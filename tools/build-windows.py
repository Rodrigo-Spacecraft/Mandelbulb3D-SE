"""Build and package the Windows x64 prototype."""

import argparse
import os
from pathlib import Path
import plistlib
import subprocess
from zipfile import ZIP_DEFLATED, ZipFile

ROOT = Path(__file__).resolve().parents[1]
ENGINE = ROOT / "vendor/mb3d-rs"
RELEASE = ROOT / "release/windows"


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--build-number", type=int, required=True)
    parser.add_argument("--llvm-mingw", type=Path, help="LLVM MinGW installation for cross-compiling")
    args = parser.parse_args()
    with (ROOT / "Info.plist").open("rb") as plist:
        app_info = plistlib.load(plist)
    version = app_info["CFBundleShortVersionString"]
    if args.build_number <= int(app_info["CFBundleVersion"]):
        parser.error("the Windows build number must be greater than the current macOS build number")

    target_dir = RELEASE / "target"
    env = dict(os.environ, CARGO_TARGET_DIR=str(target_dir),
               MB3D_SE_BUILD=f"{version} ({args.build_number})")
    runtime_files = {}
    if args.llvm_mingw:
        mingw = args.llvm_mingw.resolve()
        target = "x86_64-pc-windows-gnullvm"
        linker = mingw / "bin/x86_64-w64-mingw32-clang"
        # Put the executable startup object before libraries, including when the
        # LLVM-MinGW distribution has no per-target clang configuration file.
        import shlex
        target_dir.mkdir(parents=True, exist_ok=True)
        wrapper = target_dir / "mingw-link.sh"
        wrapper.write_text("#!/bin/sh\nexec " + shlex.quote(str(linker)) + " " +
                           shlex.quote(str(mingw / "x86_64-w64-mingw32/lib/crt2.o")) + ' "$@"\n')
        wrapper.chmod(0o755)
        env["CARGO_TARGET_X86_64_PC_WINDOWS_GNULLVM_LINKER"] = str(wrapper)
        env["CC_x86_64_pc_windows_gnullvm"] = str(linker)
        env["AR_x86_64_pc_windows_gnullvm"] = str(mingw / "bin/llvm-ar")
        env["CARGO_TARGET_X86_64_PC_WINDOWS_GNULLVM_RUSTFLAGS"] = "-C target-feature=+crt-static -C link-arg=-fuse-ld=lld -C link-arg=--rtlib=compiler-rt -C link-arg=-nostartfiles"
        cargo = [str(ROOT / "tools/cargo-local.sh")]
        runtime_files = {
            "Licenses/LLVM-MinGW.txt": (mingw / "LICENSE.TXT") if (mingw / "LICENSE.TXT").is_file() else ROOT / "resources/Licenses/LLVM-MinGW.txt",
        }
    elif os.name == "nt":
        target = "x86_64-pc-windows-msvc"
        cargo = ["cargo"]
        env["CARGO_TARGET_X86_64_PC_WINDOWS_MSVC_RUSTFLAGS"] = "-C target-feature=+crt-static"
    else:
        parser.error("provide --llvm-mingw when building from macOS or Linux")

    package_name = f"Mandelbulb3D-SE-{version}-{args.build_number}-windows-x64"
    package = RELEASE / f"{package_name}.zip"
    if package.exists():
        parser.error("that build number is already packaged")
    target_dir.mkdir(parents=True, exist_ok=True)
    resource_source = target_dir / "app-icon.rc"
    icon_path = (ENGINE / "assets/m3d-se.ico").as_posix()
    resource_source.write_text(f'1 ICON "{icon_path}"\n')
    if args.llvm_mingw:
        resource = target_dir / "app-icon.o"
        subprocess.run([str(mingw / "bin/x86_64-w64-mingw32-windres"),
                        str(resource_source), "-O", "coff", "-o", str(resource)], check=True)
        flag_name = "CARGO_TARGET_X86_64_PC_WINDOWS_GNULLVM_RUSTFLAGS"
    else:
        resource = target_dir / "app-icon.res"
        subprocess.run(["rc.exe", "/nologo", f"/fo{resource}", str(resource_source)], check=True)
        flag_name = "CARGO_TARGET_X86_64_PC_WINDOWS_MSVC_RUSTFLAGS"
    env[flag_name] += f" -C link-arg={resource}"

    subprocess.run(
        cargo + ["build", "--locked", "--manifest-path", str(ENGINE / "Cargo.toml"),
                 "--release", "--target", target, "--no-default-features",
                 "--features", "se-desktop", "--bin", "Mandelbulb3D"],
        cwd=ROOT, env=env, check=True,
    )

    files = {
        "Mandelbulb3D SE.exe": target_dir / target / "release/Mandelbulb3D.exe",
        "M3Parameter/example.m3i": ROOT / "example.m3i",
        "LICENSE": ROOT / "LICENSE",
        **runtime_files,
    }
    for source, destination in [
        (ROOT / "resources/DefaultMaps", "M3Maps"),
        (ROOT / "resources/Licenses", "Licenses"),
    ]:
        for path in sorted(source.rglob("*")):
            relative = path.relative_to(source)
            if path.is_file() and all(not part.startswith(".") for part in relative.parts):
                files[f"{destination}/{relative.as_posix()}"] = path

    temporary_package = package.with_suffix(".zip.tmp")
    try:
        with ZipFile(temporary_package, "w", compression=ZIP_DEFLATED) as archive:
            for name, path in files.items():
                archive.write(path, f"{package_name}/{name}")
            archive.writestr(f"{package_name}/README.txt",
                             "Mandelbulb3D SE for Windows x64\n\n"
                             "Extract the ZIP, then open Mandelbulb3D SE.exe.\n"
                             "INSTALLING MAPS\n"
                             "1. Open the app and click Open Map Folder in the main window.\n"
                             "2. Open the supplied M3Maps folder in another File Explorer window.\n"
                             "3. Copy its map files and any subfolders into the folder opened by the app.\n"
                             "   Copy the contents, rather than nesting another M3Maps folder inside it.\n"
                             "4. Quit and reopen the app if the new maps are not shown.\n\n"
                             "Keep LICENSE and Licenses with the app. This is an unsigned Windows beta build.\n"
                             "Source: https://github.com/Rodrigo-Spacecraft/Mandelbulb3D-SE\n"
                             "Support: https://greenoak-software.com/m3dse_support.html\n")
        temporary_package.replace(package)
    finally:
        temporary_package.unlink(missing_ok=True)
    print(package)


if __name__ == "__main__":
    main()
