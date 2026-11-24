#!/bin/sh
# Only Mandelbulb3D SE. No uploads, network calls or installer scripts.
set -eu
cd "$(dirname "$0")/.."
mode=${1:---local}
case "$mode" in --local|--app-store) ;; *) echo 'Usage: release-app-store.sh --local|--app-store' >&2; exit 2;; esac
export TMPDIR=${TMPDIR:-/private/tmp}
if [ "$mode" = --app-store ]; then
    : "${APP_SIGN_ID:?Set APP_SIGN_ID to your Apple Distribution signing identity}"
    : "${INSTALLER_SIGN_ID:?Set INSTALLER_SIGN_ID to your Mac Installer Distribution identity}"
    : "${PROVISIONING_PROFILE:?Set PROVISIONING_PROFILE to your App Store provisioning profile}"
    test -f "$PROVISIONING_PROFILE"
fi
make -j4 ENGINE=rust all
stage=release/local
if [ "$mode" = --app-store ]; then stage=release/app-store; fi
mkdir -p "$stage"
app="$stage/Mandelbulb3D SE.app"
# Replace only this script's generated app copy; development apps stay untouched.
if [ -d "$app" ]; then rm -rf "$app"; fi
ditto 'Mandelbulb3D SE.app' "$app"
plist="$app/Contents/Info.plist"
/usr/libexec/PlistBuddy -c 'Add :M3DAppSandboxed bool true' "$plist"
/usr/libexec/PlistBuddy -c 'Add :LSApplicationCategoryType string public.app-category.graphics-design' "$plist"
/usr/libexec/PlistBuddy -c 'Add :NSHumanReadableCopyright string Copyright © 2026 Glenn Olander. Includes third-party components.' "$plist"
cp resources/app-store/PrivacyInfo.xcprivacy "$app/Contents/Resources/PrivacyInfo.xcprivacy"
cp resources/app-store/Mandelbulb3DSE.entitlements "$stage/Entitlements.plist"
if [ "$mode" = --app-store ]; then
    if ! security cms -D -i "$PROVISIONING_PROFILE" > "$stage/Profile.plist"; then
        # Offline decoding fallback when security's Keychain services are unavailable.
        # This extracts the signed payload; it does not verify Apple's certificate trust.
        openssl cms -verify -inform DER -noverify -in "$PROVISIONING_PROFILE" -out "$stage/Profile.plist"
    fi
    python3 - "$stage/Profile.plist" "$stage/Entitlements.plist" <<'PY'
import plistlib,sys,datetime
with open(sys.argv[1],'rb') as f:p=plistlib.load(f)
with open(sys.argv[2],'rb') as f:e=plistlib.load(f)
a=p['Entitlements'];key='com.apple.application-identifier' if 'com.apple.application-identifier' in a else 'application-identifier'
assert a[key].endswith('.com.greenoak.m3dse'),'Profile must use the explicit com.greenoak.m3dse App ID'
assert not p.get('ProvisionedDevices') and not p.get('ProvisionsAllDevices'),'Use an App Store distribution profile'
assert p['ExpirationDate']>datetime.datetime.utcnow(),'Provisioning profile expired'
assert not a.get('get-task-allow') and not a.get('com.apple.security.get-task-allow'),'Development profile is not allowed'
e[key]=a[key]
if 'com.apple.developer.team-identifier' in a:e['com.apple.developer.team-identifier']=a['com.apple.developer.team-identifier']
with open(sys.argv[2],'wb') as f:plistlib.dump(e,f)
PY
    cp "$PROVISIONING_PROFILE" "$app/Contents/embedded.provisionprofile"
fi
# Downloaded resources and provisioning profiles may carry quarantine/provenance.
# Strip metadata only from the generated staging copy, before its final signature.
xattr -cr "$app"
python3 - "$app" <<'PYATTR'
import subprocess,sys
attributes=subprocess.check_output(['xattr','-r',sys.argv[1]],text=True)
assert 'com.apple.quarantine' not in attributes, 'Quarantine attribute remains in staged app'
print('Verified: no quarantine attributes in staged app.')
PYATTR
if [ "$mode" = --app-store ]; then
    codesign --force --timestamp --options runtime --entitlements resources/app-store/ThumbnailHelper.entitlements --sign "$APP_SIGN_ID" "$app/Contents/Helpers/FormulaThumbnailRenderer"
    codesign --force --timestamp --options runtime --entitlements "$stage/Entitlements.plist" --sign "$APP_SIGN_ID" "$app"
else
    codesign --force --options runtime --entitlements resources/app-store/ThumbnailHelper.entitlements --sign - "$app/Contents/Helpers/FormulaThumbnailRenderer"
    codesign --force --options runtime --entitlements "$stage/Entitlements.plist" --sign - "$app"
fi
codesign -d --entitlements :- "$app/Contents/Helpers/FormulaThumbnailRenderer" > "$stage/ThumbnailHelperEntitlements.plist" 2> "$stage/thumbnail-helper-signature.txt"
python3 - "$stage/ThumbnailHelperEntitlements.plist" <<'PYHELPER'
import plistlib,sys
with open(sys.argv[1],'rb') as f:e=plistlib.load(f)
assert e=={'com.apple.security.app-sandbox':True,'com.apple.security.inherit':True}, 'Thumbnail helper must inherit the parent sandbox with exactly two entitlements'
print('Verified: thumbnail helper inherits the parent sandbox.')
PYHELPER
codesign --verify --deep --strict "$app"
codesign -d --entitlements :- "$app" > "$stage/SignedEntitlements.plist" 2> "$stage/signature.txt"
python3 - "$plist" "$stage/SignedEntitlements.plist" Info.plist <<'PY'
import plistlib,sys
with open(sys.argv[1],'rb') as f:p=plistlib.load(f)
with open(sys.argv[2],'rb') as f:e=plistlib.load(f)
assert p['CFBundleIdentifier']=='com.greenoak.m3dse'
with open(sys.argv[3],'rb') as f: expected=plistlib.load(f)
assert p['CFBundleShortVersionString']==expected['CFBundleShortVersionString']
assert e['com.apple.security.app-sandbox']
assert e['com.apple.security.files.user-selected.read-write']
assert e['com.apple.security.files.bookmarks.app-scope']
allowed={'com.apple.security.app-sandbox','com.apple.security.files.user-selected.read-write','com.apple.security.files.bookmarks.app-scope','com.apple.application-identifier','application-identifier','com.apple.developer.team-identifier'}
assert set(e)<=allowed,'Unexpected entitlement; no network, broad filesystem or debugging exceptions permitted'
print('Verified: App Sandbox, user-selected read/write files, scoped bookmarks, no network entitlements.')
PY
# Apple requires macOS 12+ for an arm64-only Mac App Store submission.
python3 - "$app" <<'PYARCH'
import pathlib,plistlib,re,subprocess,sys
app=pathlib.Path(sys.argv[1])
with (app/'Contents/Info.plist').open('rb') as f:p=plistlib.load(f)
binary=app/'Contents/MacOS'/p['CFBundleExecutable']
arches=subprocess.check_output(['lipo','-archs',str(binary)],text=True).split()
if arches==['arm64']:
    assert tuple(map(int,p['LSMinimumSystemVersion'].split('.'))) >= (12,0), 'arm64-only app requires macOS 12+'
    load=subprocess.check_output(['xcrun','vtool','-show-build',str(binary)],text=True)
    minimum=re.search(r'\bminos\s+(\d+)\.(\d+)',load)
    assert minimum and tuple(map(int,minimum.groups())) >= (12,0), 'Executable deployment target must be macOS 12+'
print('Verified architectures and minimum macOS version:', ', '.join(arches), p['LSMinimumSystemVersion'])
PYARCH
build=$(/usr/libexec/PlistBuddy -c 'Print :CFBundleVersion' "$plist")
version=$(/usr/libexec/PlistBuddy -c 'Print :CFBundleShortVersionString' "$plist")
if [ "$mode" = --app-store ]; then
    pkg="$stage/Mandelbulb3D-SE-$version-$build.pkg"
    productbuild --component "$app" /Applications --sign "$INSTALLER_SIGN_ID" "$pkg"
    pkgutil --check-signature "$pkg"
    echo "Signed package ready for Transporter validation: $pkg"
else
    archive="$stage/Mandelbulb3D-SE-$version-$build-sandbox-test.zip"
    ditto -c -k --sequesterRsrc --keepParent "$app" "$archive"
    echo 'LOCAL SANDBOX TEST BUILD — ad-hoc signed; not an App Store submission package.' > "$stage/BUILD-STATUS.txt"
    echo "Local sandbox build: $app"
    echo 'App Store signing still requires distribution identities and an explicit App Store profile.'
fi
