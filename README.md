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

## Credits and licenses

macOS application, interface, and additional rendering features by Glenn Olander.
Based on Mandelbulb3D, originally developed by Jesse, with community contributions.
Rendering engine adapted from mb3d-rs by Sebastian Paluch.
Formulas retain their respective authors' credits.

See `LICENSE`, `vendor/mb3d-rs/LICENSE`, `vendor/ENGINE_PROVENANCE.txt`, and `resources/Licenses/` for license texts, modification notices, and third-party notices. Bundled maps have separate terms in `resources/DefaultMaps/m3maps terms of use.txt`.

Privacy policy: https://greenoak-software.com/PrivacyPolicy.html
