The .m3f files are the original definitions from Mandelbulb3D, revision
26de069672c385e4c75e20b8a6cdfb21b3e86c82. The assembly file lifts their
x87 bodies into x86-64 calling conventions for reference evaluation.

On a Mac with x86-64 execution available (Rosetta on Apple Silicon), run
from this directory:

```sh
clang -target x86_64-apple-macos11 -O2 test_extra_reference.c extra_reference.s -lm -o /tmp/test-extra-reference
/tmp/test-extra-reference
```

This checks 2,100 cases and writes extra_vectors.h. The corresponding
committed native test vectors are ../test_extra_vectors.h.

The full analytic-DE orbit vectors can be regenerated from this directory:

```sh
clang -target x86_64-apple-macos11 -O2 test_sierp_de_reference.c extra_reference.s -lm -o /tmp/test-sierp-de-reference
/tmp/test-sierp-de-reference
```

This writes sierp_de_vectors.h for comparison with ../test_sierp_de_vectors.h.
It uses the original kernel's derivative output and analytic DE scale 1,
not the formula's numerical DE scale 0.2.

`new_reference.s` adapts the original _addC, _SinY and Benesi3Pow2 x87
bodies to x86-64. Regenerate their golden steps on a Mac with Rosetta using:

```sh
clang -target x86_64-apple-macos11 -O2 test_new_reference.c new_reference.s -o /tmp/test-new-reference
/tmp/test-new-reference
```

This writes `new_vectors.h`; the committed copy is `../test_new_formula_vectors.h`.
Quaternion follows `HybridQuat` in original `formulas.pas`; its parameter names
and defaults come from `CustomFormulas.pas` and `HeaderTrafos.pas`.

The .m3a codec follows `TAnimationForm.SpeedButton9Click` (writer) and
`LoadAni` (reader) in original `Animation.pas` at the revision above. Version 5
has a 284-byte global header, then 1988 bytes per key (12 timing + 840 scene +
1136 addon), followed by width/height and BGRA thumbnail pixels for each key.
Tests independently construct this layout without a native trailer.

`_toruspinv3.m3f` is from the same original MB3D revision.
`torus_reference.s` adapts its original x87 executable body to the x86-64 calling convention.
To regenerate its 200 reference steps, build and run
`clang -target x86_64-apple-macos11 -O2 test_torus_reference.c torus_reference.s -o /tmp/torus-reference`
from this directory, then copy the generated `torus_vectors.h` to `../test_torus_vectors.h`.
The portable translation intentionally matches the code rather than the conflicting prose description.

`Amazing Surf.m3f` and `TgladDihed.m3f` come from the same original MB3D source revision. Their `surf_reference.s` and `dihed_reference.s` wrappers preserve the executable x87 bodies with x86-64 calling conventions. Build each corresponding `test_*_reference.c` with its assembly using `clang -target x86_64-apple-macos11 -O2`; run and copy the resulting `*_vectors.h` to the matching `../test_*_vectors.h`. Amazing Surf includes 960 steps covering persistent scale state, rotation, negative parameters and both inversion shapes. TgladDihed covers all 64 power combinations and the original early escape limit. Zero-radius underflow is resolved to C rather than propagating a projection singularity.

`trifoliumIFS.m3f`, `helistairsIFS.m3f`, `hextgrid2IFS.m3f` and `boardIFS.m3f` come from the same original MB3D revision. `difs_reference.s` adapts their SSE2/x87 bodies to x86-64 without changing their calculation instructions. Build with `clang -target x86_64-apple-macos11 -O2 test_difs_reference.c difs_reference.s -o /tmp/difs-reference`, run, then copy `difs_vectors.h` to `../test_difs_vectors.h`. The 1280 vectors check signed distances, scale and coordinate updates, rotation, orbit-trap values, both stair styles and all five board variations.

`BoxIFS.m3f` and `HeightMapIFS.m3f` are from the same original revision. `box_height_reference.s` adapts the original instruction bodies, with HeightMapIFS's map callback replaced by fixed RGB (.2,.4,.8) plus coordinate capture. Compile `test_box_height_reference.c` with that assembly for x86-64 and run to regenerate `test_box_height_vectors.h`. The 480 vectors validate twist, trapezoid, both scaling modes, height-plane early exits, channels, float option conversions, map coordinates and orbit traps.

`fourd_reference.s` lifts the original Makin4D p4b, CubicQuat and Lambda4Dc x87 kernels. Regenerate the 480 reference steps with:

```sh
clang -target x86_64-apple-macos11 -O2 test_fourd_reference.c fourd_reference.s -lm -o /tmp/test-fourd-reference
/tmp/test-fourd-reference
```

The generated `fourd_vectors.h` corresponds to `../test_fourd_vectors.h`. Cw uses the supported default zero; the input W component is varied.

`smooth_reference.s` lifts MengerSmt and _reciprocalY3b, including the original conditional smoothing branches. Regenerate their 440 golden steps with:

```sh
clang -target x86_64-apple-macos11 -O2 test_smooth_reference.c smooth_reference.s -lm -o /tmp/test-smooth-reference
/tmp/test-smooth-reference
```

The generated `smooth_vectors.h` corresponds to `../test_smooth_vectors.h`.

DiniIFS: dini_reference.s preserves the original SSE2/x87 instructions with a 64-bit calling wrapper. Build with `clang -arch x86_64 reference/dini_reference.s reference/test_dini_reference.c -o /tmp/dini-reference` and run from the project directory to regenerate test_dini_vectors.h (240 cases; Rosetta required on Apple Silicon).

Apollo2D-IFS: apollo_reference.s and test_apollo_reference.c generate 240 original x87 reference evaluations in test_apollo_vectors.h. Build with `clang -arch x86_64 reference/apollo_reference.s reference/test_apollo_reference.c -o /tmp/apollo-reference`, then run from the project directory. The formula is a DEoption 21 orbit transform, used with a distance primitive in dIFS chains.

SphereIFS: sphere_reference.s and test_sphere_reference.c generate test_sphere_vectors.h (240 cases covering hollow shells, signed scales, ellipsoid sizes and all trap options). Build with `clang -arch x86_64 reference/sphere_reference.s reference/test_sphere_reference.c -o /tmp/sphere-reference`, and run from the project directory.

RoundedBox / amazingIFS: rounded_reference.s, amazingifs_reference.s and test_shapes_reference.c generate 480 original SSE2/x87 vectors in test_shapes_vectors.h. Build the three sources with `clang -arch x86_64` and run the result from the project directory (Rosetta on Apple Silicon).

SphCageIFS: cage_reference.s and test_cage_reference.c generate 240 original SSE2/x87 cases in test_cage_vectors.h. Build with `clang -arch x86_64 reference/cage_reference.s reference/test_cage_reference.c -o /tmp/cage-reference` and run from the project directory.

transformIFS: transformifs_reference.s and test_transformifs_reference.c generate 240 original x87 evaluations in test_transformifs_vectors.h. Build with `clang -arch x86_64 reference/transformifs_reference.s reference/test_transformifs_reference.c -o /tmp/transformifs-reference` and run from the project directory.

MixPinski4ex / _LinCombineXYZ: mix_reference.s preserves the original x87 executable bodies with x86-64 calling wrappers. test_mix_reference.c independently expands the 4D float rotation option matrix and generates 480 reference steps, including all six plane rotations, nonuniform offsets, negative scales, W state and derivative updates. Build with `clang -arch x86_64 reference/mix_reference.s reference/test_mix_reference.c -o /tmp/mix-reference` and run from the project directory to regenerate test_mix_vectors.h (Rosetta on Apple Silicon). _LinCombXYZ is accepted as an alias for the source formula's _LinCombineXYZ name.

4D scene rotations: test_rotation4_reference.c independently translates the original Math3D.BuildSMatrix4 / Rotate4Dex initialization and drives the original x87 formulas for four steps, including rotated non-Julia constants and Julia W. Build with `clang -arch x86_64 reference/test_rotation4_reference.c reference/fourd_reference.s reference/mix_reference.s -o /tmp/rotation4-reference`, then run from the project directory to regenerate test_rotation4_vectors.h (600 cases).
