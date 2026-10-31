# Mandelbulb3D SE

Source code for the native macOS fractal application Mandelbulb3D SE.
The `rel2` tag identifies the corresponding version 2.0.1 release source.
This repository distributes source, build scripts, resources, and tests; no prebuilt application is included.

## Requirements

- An Apple Silicon Mac running macOS 12 or later.
- Xcode or Apple's Command Line Tools, including Clang and the macOS SDK.
- A current stable Rust toolchain installed with Cargo available on PATH.
- GNU Make (the `make` supplied with the developer tools is sufficient).

## Build and run

```sh
git clone https://github.com/Rodrigo-Spacecraft/Mandelbulb3D-SE.git
cd Mandelbulb3D-SE
git checkout rel2
make -j4
open "Mandelbulb3D SE.app"
```

Cargo downloads the dependencies pinned in `rust-bridge/Cargo.lock` on the first build. The engine itself is included as a local path dependency in `vendor/mb3d-rs`. No developer account or private signing key is needed to build and run the locally ad-hoc-signed application.

To create a locally runnable sandbox build:

```sh
make release-sandbox
open "release/local/Mandelbulb3D SE.app"
```

The application uses user-selected file access and has no network entitlements. Build tools may download dependencies; the application itself does not require internet access.

The alternative C engine can be built with `make ENGINE=c`; this creates `Mandelbulb3Dx.app`. The App Store application uses the Rust engine with the native AppKit interface.

## Tests

```sh
./tools/cargo-local.sh test --manifest-path vendor/mb3d-rs/Cargo.toml --no-default-features --features gpu --lib
```

Some GPU tests require a compatible graphics device. The `x86::tests::f80_round_trip` test has a known failure for an extremely small 80-bit conversion value (`1e-300`). Individual native integration and UI tests are provided in the project root and `tests/`; tests that use temporary files should run with `TMPDIR=/private/tmp`.

## Source layout

- `App.m` and UI includes: native macOS interface.
- `renderer.c`, `scene.h`, and related headers: scene settings, serialization, native rendering integration, and the alternative C renderer.
- `rust-bridge/`: static-library interface between the app and Rust engine.
- `vendor/mb3d-rs/`: adapted rendering engine source.
- `rust-assets/M3Formulas/`: formula definitions with author information.
- `resources/`: application artwork, default maps, license notices, and sandbox metadata.
- `tools/`: build, packaging, and formula-generation tools.

## Using Mandelbulb3D SE

Open `Mandelbulb3D SE.app`. It renders the default Integer Power scene and displays
it alongside a compact **Calculation** tab. Close the window or press Command-Q
to quit.

The Calculation tab exposes:

| Setting | Allowed values |
|---|---|
| Width and height | Base size, at least 16 pixels each; oversampled dimensions must not exceed 16384 |
| Threads | 0 for automatic, or 1–256 |
| Iterations | 1–10000 |
| DE stop | 0.000001–100; lower values capture finer detail |
| Raystep multiplier | 0.000001–1; lower values take smaller, slower steps |

Change the values and press **Render** (or Return). Edits are validated before
rendering. The image stays visible while calculation runs in the background;
controls are disabled until it finishes. Loaded scene settings populate the
fields after a successful render. Opening or dropping another file loads that
file’s settings, with any explicit command-line size/thread overrides applied.
Changes stay in memory until **Save .m3i…** is used. The source file changes only if you explicitly select it as the save destination.


## Image size, oversampling and saving

**Keep aspect** (on by default) locks the current width/height ratio. Editing
either dimension adjusts the other. Turning the option on captures the ratio
currently shown. **DEStop+C** (also on by default) scales DE stop with image
width to preserve detail and coloring. With it off, DE stop stays unchanged.
The original option also scales the depth-of-field clipping radius; depth of
field is not implemented in this app.

**Oversampling** has choices 1× through 6×, with 1× the default. Width and height
remain the base size: 3× at 480 × 360 renders 1440 × 1080 and resolves to
480 × 360. The separate Viewing control has been removed. The full-resolution bitmap is retained for display,
including Retina screens. The title shows both display and render dimensions.
Oversampling scales the internal DE stop by its factor to preserve the same
world-space surface threshold and lighting. The displayed DE stop remains the
base value. This compensation always applies; DEStop+C controls edits of the
base width. Rendering
work and `.m3i` pixel data grow approximately with the square of oversampling.
The 16384-pixel limit applies to the actual rendered width and height.

**Save .m3i…** opens the macOS save dialog, then renders the current main settings
(including pending Calculation, Formulas, Lighting and Post-process edits) and
saves an atomic `.m3i` file. Navigator edits must first be applied to Main.
The file contains the standard 840-byte modern header, full-resolution 18-byte
surface records and 1136-byte formula addon. These records include depth,
normals, coloring, ambient occlusion and hard-shadow data from this renderer.
It also carries a versioned native settings trailer preserving exact palette
endpoints/colors, inactive formula parameters, shadow controls, oversampling,
Viewing and size-option flags when reopened here. Other MB3D readers use the
standard fields with their normal storage precision and rendering differences;
this app’s SSAO/other unsupported features remain as documented below.

Saving writes a temporary file in the destination directory and replaces the
chosen file only after rendering and writing succeed. Save failures retain the
existing destination. Loading a saved file restores the base-size fields and
oversampling/viewing choices. The regular Render button still writes no file.

Load a scene by dropping a modern `.m3i` or `.m3p` file onto the image window or the application
in Finder/Dock. You can also choose this app using Finder's Open With command.
The app does not register itself as the default handler for these files.

From Terminal:

```sh
open -a /absolute/path/Mandelbulb3D SE.app /absolute/path/scene.m3i
```

To pass optional rendering settings to a new instance:

```sh
open -n /absolute/path/Mandelbulb3D SE.app --args /absolute/path/scene.m3i --threads 4 --width 960 --height 720
```

The application displays pixels through a native image view and can save a
`.m3i` scene with calculated image data. It does not export BMP, PNG or JPEG.
It uses all online CPU
cores by default. Rendering runs off the main thread, so the window remains
responsive. Resizing fits the existing image proportionally, without stretching
or rerendering. Letterboxing uses a dark background.

The window title shows rendering status, scene name and final pixel dimensions.
If a scene fails to load, the title reports the error and the previous image
remains visible. Detailed errors and unsupported-lighting warnings are written
to standard error (visible when launching the bundle's executable in Terminal):

```sh
./Mandelbulb3D SE.app/Contents/MacOS/Mandelbulb3Dx /absolute/path/scene.m3i
```

## Formulas window

Click **Formulas…** in Calculation to open **Formulas**. The window has
**Formula 1** and **Formula 2** tabs, each offering a formula menu with **Integer Power** and **Amazing Box**. The mode is
fixed to **Alternate** and rendering is fixed to **Outside**.

Each tab’s **formula menu** switches between Integer Power and Amazing Box.
Only the chosen formula’s parameters are shown:

- **Integer Power:** Integer power (2–8; default 8), Z multiplier (−100..100;
  default −1).
- **Amazing Box:** Scale (−100..100; default 2), Min R (0.000001..100; default
  0.5), Fold (−100..100; default 1).

Each tab also has:

- **Iterations per pass:** 1–10000 for Formula 1, 0–10000 for Formula 2.
  Formula 2 defaults to 0 (disabled), preserving existing one-formula scenes.

To enable the second formula, set its iteration count above zero. With counts
2 and 3 and **Repeat from: Formula 1**, each orbit applies Formula 1 twice,
Formula 2 three times, then repeats that sequence until the overall Calculation
iteration limit or bailout. The overall limit counts individual formula
applications, not whole passes. Each formula transforms the current orbit
vector and adds the Mandelbrot/Julia constant, matching Alternate mode.

**Repeat from: Formula 2** applies Formula 1 only on the first pass, then
repeats Formula 2. It requires Formula 2 to be enabled. These iteration counts
and the repeat point are also loaded from supported `.m3i` scenes.

Press **Apply & Render** or Calculation’s **Render** to apply both tabs and
Calculation settings. Closing Formulas retains edits for the next render.
Loading another scene refreshes both tabs from that file after a successful
render; a one-formula file disables Formula 2. Files change only through an explicit Save .m3i action.
Main-window controls have visible text labels (Image width/height in pixels,
CPU threads, Max iterations, DE stop, Raystep multiplier), with native adaptive
panel backgrounds and label colors for contrast. Controls are disabled during rendering. Invalid values preserve the previous
image. Closing the main image window quits the app even if Formulas is open.

## Lighting — Object and Light sources

Click **Lighting…** in the main window. The **Object** tab includes:

- Diffuse strength (0–250) and specular strength (0–350), with sliders and
  numeric fields. 50 corresponds to a multiplier of 1.
- Color start and Color end sliders (−30..90) and numeric fields in MB3D’s palette-range units (startup: 68 and 72).
- **Adjust sliders to fit** uses the last main render’s color histogram, trimming
  0.05% of surface pixels at each end, as in MB3D. Orbit trap coloring selects
  the orbit-trap histogram. Press Apply & Render to use the fitted range.
  Loaded fine-adjustment endpoints are represented as their effective range.
- Color cycling, No interpolation, and Orbit trap coloring (minimum squared
  distance to the origin, the default MB3D second color choice).
- Color variation on Z (−120..360).
- Ten palette stops, each with a position (0–32767), diffuse color and specular
  color. Click a color well to edit it in the native RGB/HSB/wheel color picker.
  Stop positions must stay sorted; repeated positions are allowed.

Press **Apply & Render** to use the edits. The main Render and Formulas
Apply & Render buttons also include pending Object and light-source edits. Opening another scene
loads its saved Object and light-source settings. Scene files change only through an explicit Save .m3i action. Lighting load/save, background-file controls, and file-based palette pickers
are omitted. Cut/interior palettes do not apply to the supported outside render
and are not shown. The **Light sources** tab contains six tabs, one for each light. Each exposes
enabled, directional/point type, color, strength, X/Y angles in degrees or XYZ
world position, object-relative directional lighting, hard/ambient-shadow bypass,
four diffuse functions and eight specular exponents. Lights 2–6 start disabled but use white color and strength 1, so enabling a
light immediately contributes illumination. Enabling an unused loaded light
with zero strength or black color initializes those values to 1 and white;
existing nonzero strengths and nonblack colors are preserved. Loaded light
values otherwise populate the controls. All six can illuminate the same scene.
Enable, color, function and strength edits update the image automatically.
Ambient and fog tabs are not included; those settings and the background
continue to come from the loaded scene or startup defaults.

Object sliders and each light’s X/Y/Z sliders update the main image while
being dragged. Continuous previews fit 480 × 360; release the mouse for a full
render at the Calculation dimensions. Only one preview renders at a time;
intermediate requests coalesce into the latest settings. Completed frames can
appear during mouse tracking, while results from obsolete main renders are
ignored. Previews leave the controls enabled; the final render disables them
until it finishes. Rendering still recalculates geometry rather than reshading
a cached surface. The Lighting controls do not save separate lighting files; use Save .m3i in the main window to save the scene.

Directional lights use X/Y angles in degrees (−180..180); their unused Z slider
is disabled. Point lights use all three world coordinates (normally −10..10).
Loaded values outside these ranges expand the sliders; numeric fields accept
finite coordinates. Invalid values retain the previous image.

## Color adjustment

Click the **Diffuse Colors** gradient in Lighting → Object to open **Color
adjustment**. The two previews show diffuse and specular colors at the same ten
stop positions. Drag a marker to move its stop; double-click it to open the
native color picker. The Stop menu selects tightly clustered stops, and the
position field accepts integers from 0 to 32767. Crossing stops reorder their
positions and both colors together. **Glue sliders** stretches the neighboring
positions proportionally.

The selected stop’s diffuse and specular color wells also open the color picker.
**Random diffuse** and **Random specular** use their reference colors and
multipliers (0–3); specular randomization also uses the diffuse colors. These
edits immediately synchronize with the palette fields and bar in Lighting.
**Update Image** applies pending edits and renders the image. Enable **Auto
update image** to render after color changes and at the end of a stop drag.
These updates currently calculate a full render. Loading another scene refreshes
both windows. This editor does not write files directly; Save .m3i captures its applied scene settings. This editor uses
the supported outside palette; interior/transparency and image-painting controls
are omitted.

## Navigator

Click **Navigator…** in the main window. It opens a background-rendered preview
and camera controls. These changes stay in the Navigator until **Apply to Main**
is pressed. That button renders the main image at its Calculation dimensions,
using the new viewpoint, Navigator formula values, and pending Calculation or Lighting edits.

- Move with **W/S** (forward/back), **A/D** (left/right), **Q/E** (up/down), or
  the matching buttons. Movement follows the current camera axes.
- Look left/right with **J/L** and up/down with **I/K**. The **arrow keys**
  also work, or drag the preview with the mouse.
- Roll with **U/O** (Z/X also work); zoom with **+/−** or the zoom buttons.
- **Move step** sets translation distance per action; **Look step** sets the
  button/key angle in degrees. Mouse-look uses 0.25 degrees per pixel.
- **FOVy** changes vertical field of view (0.001–179.999°); Return updates the preview.
- **Fixed zoom and steps** starts off. Switching it on or off preserves the current camera zoom and movement step. Adaptive changes are relative to that captured view.
  Uncheck it to adapt zoom and translation step size to the local fractal
  distance estimate. Approaching the surface increases zoom and reduces steps;
  moving away does the reverse. Movement uses fresh distance estimates between
  substeps, including rapid key repeats. Automatic zoom keeps the ray-start plane
  within the local distance estimate. Minimum distance is zero, with no positive
  distance floor. Rotation angle stays at the Look step value.
- **Far plane** is a ray-distance multiplier (0.001–10000). In fixed mode it
  multiplies the view-plane diagonal in world units; in adaptive mode it
  multiplies local DE. Switching modes rebases the displayed factor to preserve
  the current ray distance. **F1** or Far − multiplies it by 0.8; **F2** or Far +
  multiplies it by 1.25. Shortcuts work from either Navigator tab. Smaller values
  clip distant geometry. Return applies typed values to the preview.
- **Apply to Main** transfers FOVy, the actual far distance and the resulting
  camera zoom together with the viewpoint and formula values. Save .m3i then
  preserves those resulting camera settings. The adaptive-mode checkbox itself
  is a Navigator-only preference and is not stored in the scene file.
- **Reset to Main** restores the most recently rendered main viewpoint and formula values.
- Navigation shortcuts are handled by the Navigator window, including after
  buttons, sliders and steppers. Movement/look letter keys also work while a
  number field has focus. While actively typing a number, signs and arrow keys
  retain normal text-editing behavior; Return commits the value and restores
  preview focus. Stepper, menu and button actions also restore preview focus.
  Command/Control/Option shortcuts are left to macOS and the controls.

The **Formula Values** tab edits either of the two existing formula slots.
Integer Power exposes Power (integer 2–8) and Z multiplier (−100..100).
Amazing Box exposes Scale/Fold (−100..100) and Min R (0.000001..100).
Drag a slider for continuous preview updates, or type a value and press Return. The **Iterations** field sets applications per pass for the selected formula;
type an integer and press Return, or use the up/down stepper. Formula 1 accepts
1–10000; Formula 2 accepts 0–10000, where 0 disables it. Moving Formula 2 from
0 to a positive count enables it. Disabling Formula 2 also resets repeat to
Formula 1. The stepper uses the latest typed value, even before Return, and
clamps to the selected slot’s limits. These counts control the formula sequence;
the main Calculation **Max iterations** still limits total orbit iterations.
Use the Formulas window to change formula types and repeat point.
Navigator edits stay local until **Apply to Main** transfers both slots and the
viewpoint, replacing pending edits in the Formulas window. Both Apply and Reset
remain available on either Navigator tab. Invalid values keep the previous
preview and report the allowed range.

The preview uses the main lighting and calculation settings with the Navigator’s
formula values. Pending Lighting edits are included when applying to the main
render. Any successful main render resynchronizes the Navigator.
Loading another scene also resets it to that scene’s camera and formulas. Closing Navigator
keeps the main image unchanged and stops further pending preview updates.

Preview requests are coalesced while dragging or pressing keys. Completed
frames update the image during dragging; results from an obsolete main scene
are discarded. The main and preview renders share a serial job queue, with
multicore rendering inside each job, preventing shared scene-state races.
Preview resolution normally fits 640 × 360 without upscaling; extremely narrow
aspect ratios retain the renderer’s minimum 16-pixel dimension. No image or
camera file is written. Formula and lighting edits remain in their separate windows; Julia editing
is not included in this Navigator. Panorama/rectilinear camera modes loaded
from a scene are retained.

## Credits and licenses

macOS application, interface, and additional rendering features by Glenn Olander.
Based on Mandelbulb3D, originally developed by Jesse, with community contributions.
Rendering engine adapted from mb3d-rs by Sebastian Paluch.
Formulas retain their respective authors' credits.

See `LICENSE`, `vendor/mb3d-rs/LICENSE`, `vendor/ENGINE_PROVENANCE.txt`, and `resources/Licenses/` for license texts, modification notices, and third-party notices. Bundled maps have separate terms in `resources/DefaultMaps/m3maps terms of use.txt`.

Privacy policy: https://greenoak-software.com/PrivacyPolicy.html
