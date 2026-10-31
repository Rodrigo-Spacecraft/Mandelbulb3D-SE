#!/bin/sh
set -eu
icon_work=$(mktemp -d "${TMPDIR:-/tmp}/mandelbulb-icon.XXXXXX")
trap 'rm -rf "$icon_work"' EXIT HUP INT TERM
mkdir "$icon_work/AppIcon.iconset"
for size in 16 32 128 256 512; do
    sips -z "$size" "$size" "$1" --out "$icon_work/AppIcon.iconset/icon_${size}x${size}.png" >/dev/null
    retina=$((size * 2))
    sips -z "$retina" "$retina" "$1" --out "$icon_work/AppIcon.iconset/icon_${size}x${size}@2x.png" >/dev/null
done
# icp4/icp5 PNG payloads corrupt Finder's small application icons.
# Encode the small 1x images as ic04/ic05 straight ARGB planes instead.
clang -O2 -fobjc-arc "$(dirname "$0")/icon-pixels.m" -framework Cocoa -o "$icon_work/icon-pixels"
for size in 16 32; do
    "$icon_work/icon-pixels" "$icon_work/AppIcon.iconset/icon_${size}x${size}.png" > "$icon_work/AppIcon.iconset/${size}.argb"
done
/usr/bin/perl - "$icon_work/AppIcon.iconset" "$2" <<'PERL'
use strict; use warnings;
my ($dir,$output)=@ARGV;
my @entries=(['ic04','16'],['ic05','32'],
 ['ic07','128x128'],['ic08','256x256'],['ic09','512x512'],['ic10','512x512@2x'],
 ['ic11','16x16@2x'],['ic12','32x32@2x'],['ic13','128x128@2x'],['ic14','256x256@2x']);
my $body='';
for my $entry (@entries) {
 my $small=$entry->[0] eq "ic04" || $entry->[0] eq "ic05";
 my $file=$small?"$dir/$entry->[1].argb":"$dir/icon_$entry->[1].png";
 open my $in,'<',$file or die $!;binmode $in;
 local $/;my $png=<$in>;close $in;
 if ($small) {
  # Valid literal RLE packets, at most 128 bytes each, separately per plane.
  my $encoded='ARGB';my $plane=$entry->[1]*$entry->[1];
  for my $c (0..3) {for(my $offset=0;$offset<$plane;$offset+=128){my $count=$plane-$offset;$count=128 if $count>128;$encoded.=chr($count-1).substr($png,$c*$plane+$offset,$count);}}
  $png=$encoded;
 }
 $body.=$entry->[0].pack('N',length($png)+8).$png;
}
open my $out,'>',$output or die $!;binmode $out;
print $out 'icns',pack('N',length($body)+8),$body;close $out or die $!;
PERL
