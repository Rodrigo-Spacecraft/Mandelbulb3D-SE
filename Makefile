CC = clang
MACOS_MIN = 11.0
CFLAGS = -O3 -std=c11 -Wall -Wextra -Wpedantic -mmacosx-version-min=$(MACOS_MIN)
ENGINE ?= rust
ifeq ($(ENGINE),rust)
MACOS_MIN = 12.0
APP = Mandelbulb3D SE.app
EXECUTABLE = Mandelbulb3DSE
OBJECTS = renderer-rust.o App-rust.o
RUST_LIB = rust-bridge/target/release/libmandelbulb3dx_engine.a
ENGINE_DEFINES = -DUSE_RUST_ENGINE
ENGINE_LIBS = $(RUST_LIB) -framework Metal -framework QuartzCore -framework IOKit -framework Security -liconv
else
CFLAGS += -DUSE_C_FORMULA_VM
C_NATIVE_OBJECTS = $(patsubst %.c,%.o,$(wildcard native-c/part*.c native-c/compact-part*.c)) native-c/lookup.o native-c/compact-lookup.o
C_FORMULA_DEPS = native-c/libformulas.a
C_FORMULA_LIBS = native-c/libformulas.a
APP = Mandelbulb3Dx.app
EXECUTABLE = Mandelbulb3Dx
OBJECTS = renderer.o App.o
endif

empty :=
space := $(empty) $(empty)
APP_TARGET = $(subst $(space),\$(space),$(APP))

all: $(APP_TARGET)/Contents/MacOS/$(EXECUTABLE)
native-c/%.o: native-c/%.c native-c/runtime.h native-c/compact.h
	$(CC) -O3 -std=c11 -ffp-contract=off -Wno-everything -mmacosx-version-min=11.0 -c $< -o $@
native-c/libformulas.a: $(C_NATIVE_OBJECTS)
	ar rcs $@ $^

renderer.o: rust_engine.inc emission_lighting.h emission_glow.h render_statistics.h native-c/libformulas.a c_formula_vm.h c_formula_compact.h c_formula_native.h c_formula_code.h rust_formula_catalog.h ssao.h fog.h background.h reflections.h renderer.c renderer.h scene.h formula_support.h rand_cubes.h extra_formulas.h difs_formulas.h height_maps.h
	$(CC) $(CFLAGS) -c renderer.c -o $@
App.o: file_access.h window_identity.h mutagen_engine.h mutagen_views.h mutagen_ui.inc color_favorites.h default_maps.h file_dialog_history.h rust_formula_catalog.h render_history.h history_ui.inc fog_ui.inc App.m lighting_files.h lighting_history.inc background_ui.inc formula_ui.h formula_binary_parameters.h numeric_input.h renderer.h animation.h animation_ui.inc animation_processing.inc m3a_ui.inc
	$(CC) $(CFLAGS) -fobjc-arc -c App.m -o $@
resources/AppIcon.icns: resources/AppIcon.png resources/make-icon.sh resources/icon-pixels.m
	sh resources/make-icon.sh resources/AppIcon.png "$@"
$(APP_TARGET)/Contents/MacOS/$(EXECUTABLE): $(OBJECTS) $(RUST_LIB) $(C_FORMULA_DEPS) Info.plist resources/AppIcon.icns resources/FormulaInfo.plist resources/DefaultMaps $(wildcard resources/Licenses/*) $(wildcard resources/DefaultMaps/*.png resources/DefaultMaps/*.jpg resources/DefaultMaps/*.jpeg resources/DefaultMaps/*.bmp resources/DefaultMaps/*.gif resources/DefaultMaps/*.tif resources/DefaultMaps/*.tiff resources/DefaultMaps/*.pgm)
	mkdir -p "$(APP)/Contents/MacOS"
	cp Info.plist "$(APP)/Contents/Info.plist"
ifeq ($(ENGINE),rust)
	/usr/libexec/PlistBuddy -c 'Set :LSMinimumSystemVersion $(MACOS_MIN)' "$(APP)/Contents/Info.plist"
	/usr/libexec/PlistBuddy -c 'Set :CFBundleExecutable Mandelbulb3DSE' "$(APP)/Contents/Info.plist"
	/usr/libexec/PlistBuddy -c 'Set :CFBundleName Mandelbulb3D SE' "$(APP)/Contents/Info.plist"
	/usr/libexec/PlistBuddy -c 'Add :CFBundleDisplayName string Mandelbulb3D SE' "$(APP)/Contents/Info.plist"
	/usr/libexec/PlistBuddy -c 'Set :CFBundleIdentifier com.greenoak.m3dse' "$(APP)/Contents/Info.plist"
endif
	mkdir -p "$(APP)/Contents/Resources"
	cp resources/AppIcon.icns "$(APP)/Contents/Resources/AppIcon.icns"
	cp resources/FormulaInfo.plist "$(APP)/Contents/Resources/FormulaInfo.plist"
	rm -rf "$(APP)/Contents/Resources/Licenses"
	cp -R resources/Licenses "$(APP)/Contents/Resources/Licenses"
	rm -rf "$(APP)/Contents/Resources/DefaultMaps"
	cp -R resources/DefaultMaps "$(APP)/Contents/Resources/DefaultMaps"
	$(CC) $(CFLAGS) $(OBJECTS) $(ENGINE_LIBS) -framework Cocoa $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o "$@"
ifeq ($(ENGINE),rust)
	mkdir -p "$(APP)/Contents/Resources/M3Formulas"
	cp rust-assets/M3Formulas/*.m3f "$(APP)/Contents/Resources/M3Formulas/"
	cp vendor/mb3d-rs/LICENSE "$(APP)/Contents/Resources/Rust-Engine-LICENSE"
	cp vendor/ENGINE_PROVENANCE.txt "$(APP)/Contents/Resources/Rust-Engine-Provenance.txt"
endif
ifeq ($(ENGINE),c)
	mkdir -p "$(APP)/Contents/Frameworks" "$(APP)/Contents/Resources/M3Formulas"
	rm -f "$(APP)/Contents/Frameworks/libunicorn.2.dylib" "$(APP)/Contents/Resources/COPYING" "$(APP)/Contents/Resources/COPYING.LIB" "$(APP)/Contents/Resources/PROVENANCE.txt"
	cp vendor/mb3d-rs/LICENSE "$(APP)/Contents/Resources/Native-Formulas-LICENSE"
	cp rust-assets/M3Formulas/*.m3f "$(APP)/Contents/Resources/M3Formulas/"

endif
	codesign --force --sign - "$(APP)"
	touch "$(APP)"
clean:
	rm -f native-c/*.o native-c/libformulas.a renderer.o App.o renderer-rust.o App-rust.o test-rust-engine test-rust-panel test-formula-catalog test-renderer test-sequence test-pair-loader test-program test-clipboard test-extra-formulas test-hybrid-normals test-lighting-cache test-panel test-animation test-reflections test-fog test-rotation4 test-ssao
	rm -rf "$(APP)"
.PHONY: all clean

test: test-ssao test-rotation4 test-fog fog_ui.inc reflections.h test_reflections.c renderer.o animation.h animation_ui.inc animation_processing.inc m3a_ui.inc test_animation.m test_lighting_cache.c test_hybrid_normals.c test_renderer.c test_sequence.c test_program.c test_clipboard.c test_extra_formulas.c test_mix_vectors.h test_add72_vectors.h test_transformifs_vectors.h test_cage_vectors.h test_shapes_vectors.h test_sphere_vectors.h test_apollo_vectors.h test_dini_vectors.h test_fourd_vectors.h test_smooth_vectors.h test_rand_vectors.h test_extra_vectors.h test_sierp_de_vectors.h test_new_formula_vectors.h test_torus_vectors.h test_surf_vectors.h test_dihed_vectors.h test_difs_vectors.h test_box_height_vectors.h test_pair_loader.c test_pair_loader.py test_panel.m
	$(CC) $(CFLAGS) test_renderer.c renderer.o $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-renderer
	./test-renderer example.m3i
	$(CC) $(CFLAGS) test_sequence.c $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-sequence
	./test-sequence
	$(CC) $(CFLAGS) test_program.c $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-program
	./test-program
	$(CC) $(CFLAGS) test_extra_formulas.c $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-extra-formulas
	./test-extra-formulas
	$(CC) $(CFLAGS) test_hybrid_normals.c $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-hybrid-normals
	./test-hybrid-normals
	$(CC) $(CFLAGS) test_lighting_cache.c $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-lighting-cache
	./test-lighting-cache
	$(CC) $(CFLAGS) test_clipboard.c renderer.o $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-clipboard
	./test-clipboard example.m3i
	$(CC) $(CFLAGS) test_pair_loader.c renderer.o $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-pair-loader
	python3 test_pair_loader.py
	$(CC) $(CFLAGS) -fobjc-arc test_panel.m renderer.o -framework Cocoa $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-panel
	./test-panel
	$(CC) $(CFLAGS) -fobjc-arc test_animation.m renderer.o -framework Cocoa $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-animation
	./test-animation
	$(CC) $(CFLAGS) test_reflections.c $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-reflections
	./test-reflections
.PHONY: test

test-fog: test_fog.c renderer.c renderer.h scene.h fog.h background.h
	$(CC) $(CFLAGS) test_fog.c $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-fog
	./test-fog

test-rotation4: test_rotation4.c test_rotation4_vectors.h renderer.c renderer.h scene.h extra_formulas.h
	$(CC) $(CFLAGS) test_rotation4.c $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-rotation4
	./test-rotation4

test-ssao: test_ssao.c ssao.h renderer.c renderer.h scene.h fog.h background.h
	$(CC) $(CFLAGS) test_ssao.c $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-ssao
	./test-ssao

RUST_SOURCES = $(shell rg --files rust-bridge/src vendor/mb3d-rs/src)
rust-bridge/target/release/libmandelbulb3dx_engine.a: $(RUST_SOURCES) rust-bridge/Cargo.toml rust-bridge/Cargo.lock .cargo/config.toml vendor/mb3d-rs/Cargo.toml
	./tools/cargo-local.sh build --manifest-path rust-bridge/Cargo.toml --release --locked
renderer-rust.o: Makefile render_statistics.h rust_formula_catalog.h renderer.c renderer.h scene.h formula_support.h extra_formulas.h fog.h background.h reflections.h ssao.h rust_engine.h rust_engine.inc
	$(CC) $(CFLAGS) -DUSE_RUST_ENGINE -c renderer.c -o $@
App-rust.o: Makefile file_access.h window_identity.h mutagen_engine.h mutagen_views.h mutagen_ui.inc color_favorites.h default_maps.h file_dialog_history.h render_history.h history_ui.inc App.m lighting_files.h lighting_history.inc background_ui.inc formula_ui.h formula_binary_parameters.h renderer.h animation.h animation_ui.inc animation_processing.inc m3a_ui.inc fog_ui.inc numeric_input.h rust_engine.h
	$(CC) $(CFLAGS) -DUSE_RUST_ENGINE -fobjc-arc -c App.m -o $@

.PHONY: test-rust
.PHONY: update-formula-catalog
update-formula-catalog:
	mkdir -p rust-bridge/target
	./tools/cargo-local.sh run --manifest-path rust-bridge/Cargo.toml --release --locked --example formula_catalog > rust-bridge/target/formula-catalog.tsv
	python3 tools/generate-rust-formula-catalog.py rust-bridge/target/formula-catalog.tsv
test-rust: renderer-rust.o $(RUST_LIB)
	$(CC) $(CFLAGS) -I . tests/test_no_slice.c renderer-rust.o $(ENGINE_LIBS) -framework Cocoa $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /tmp/Mandelbulb3Dr-test-no-slice
	MB3DX_GPU=cpu /tmp/Mandelbulb3Dr-test-no-slice
	$(CC) $(CFLAGS) test_formula_catalog.c renderer-rust.o $(ENGINE_LIBS) -framework Cocoa $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-formula-catalog
	MB3D_GPU=0 ./test-formula-catalog
	$(CC) $(CFLAGS) test_rust_engine.c renderer-rust.o $(ENGINE_LIBS) -framework Cocoa $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-rust-engine
	MB3D_GPU=0 ./test-rust-engine
	$(CC) $(CFLAGS) -DUSE_RUST_ENGINE -fobjc-arc test_rust_panel.m renderer-rust.o $(ENGINE_LIBS) -framework Cocoa $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-rust-panel
	./test-rust-panel

# Preserve settings that have no native editor, for either renderer.
test-import-preservation: $(filter renderer%.o,$(OBJECTS)) $(RUST_LIB)
	$(CC) $(CFLAGS) -I . $(ENGINE_DEFINES) tests/test_preserved_imports.c $(filter renderer%.o,$(OBJECTS)) $(ENGINE_LIBS) -framework Cocoa $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /tmp/$(EXECUTABLE)-test-import-preservation
	MB3DX_GPU=cpu /tmp/$(EXECUTABLE)-test-import-preservation
.PHONY: test-import-preservation

# Formula execution and editor/import tests for the independent C engine.
test-c-catalog: renderer.o test-prepared-catalog test-compact-formulas
	$(CC) $(CFLAGS) -I . tests/test_c_formula_vectors.c $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /tmp/Mandelbulb3Dx-test-formulas
	/tmp/Mandelbulb3Dx-test-formulas
	$(CC) $(CFLAGS) test_formula_catalog.c renderer.o $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o test-formula-catalog
	./test-formula-catalog
.PHONY: test-c-catalog

# In/outside traversal and stationary dIFS orbit regression.
test-render-sides: tests/test_render_sides.c renderer.c extra_formulas.h $(C_FORMULA_DEPS)
	$(CC) $(CFLAGS) -I . tests/test_render_sides.c $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /tmp/Mandelbulb3Dx-test-render-sides
	/tmp/Mandelbulb3Dx-test-render-sides
test: test-render-sides
.PHONY: test-render-sides

# Actual work counts must be deterministic across thread counts and reset on reuse.
test-info: $(firstword $(OBJECTS)) $(RUST_LIB) tests/test_render_statistics.c tests/test_info_panel.m
	$(CC) $(CFLAGS) $(ENGINE_DEFINES) -I. tests/test_render_statistics.c $(firstword $(OBJECTS)) $(ENGINE_LIBS) $(C_FORMULA_LIBS) -lm -pthread -framework Cocoa -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /tmp/mb3dx-test-info-$(ENGINE)
	MB3DX_GPU=cpu /tmp/mb3dx-test-info-$(ENGINE)
	$(CC) $(CFLAGS) $(ENGINE_DEFINES) -Wno-deprecated-declarations -I. -fobjc-arc tests/test_info_panel.m $(firstword $(OBJECTS)) $(ENGINE_LIBS) $(C_FORMULA_LIBS) -framework Cocoa -framework ImageIO -framework CoreGraphics -framework CoreFoundation -lm -pthread -o /tmp/mb3dx-test-info-panel-$(ENGINE)
	MB3DX_GPU=cpu /tmp/mb3dx-test-info-panel-$(ENGINE)
.PHONY: test-info

test-flexible-tracks: renderer.c c_formula_vm.h tests/test_flexible_tracks.c tests/flexible-tracks-parameters.m3p tests/flexible-tracks-de.tsv $(C_FORMULA_DEPS)
	$(CC) $(CFLAGS) -I. tests/test_flexible_tracks.c $(C_FORMULA_LIBS) -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /tmp/test-flexible-tracks
	/tmp/test-flexible-tracks
test: test-flexible-tracks
.PHONY: test-flexible-tracks

test-large-maps: tests/test_large_maps.c renderer.c renderer.h height_maps.h native-c/libformulas.a
	$(CC) $(CFLAGS) -DUSE_C_FORMULA_VM -I. tests/test_large_maps.c native-c/libformulas.a -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /tmp/mb3dx-test-large-maps
	/tmp/mb3dx-test-large-maps
.PHONY: test-large-maps

test-palette-cycle: tests/test_palette_cycle.c renderer.c renderer.h reflections.h native-c/libformulas.a
	$(CC) $(CFLAGS) -DUSE_C_FORMULA_VM -I. tests/test_palette_cycle.c native-c/libformulas.a -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /tmp/mb3dx-test-palette-cycle
	/tmp/mb3dx-test-palette-cycle
.PHONY: test-palette-cycle

test-compact-formulas: tests/test_compact_formulas.c renderer.c c_formula_vm.h c_formula_compact.h native-c/libformulas.a
	$(CC) $(CFLAGS) -DUSE_C_FORMULA_VM -I. tests/test_compact_formulas.c native-c/libformulas.a -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /private/tmp/mb3dx-test-compact-formulas
	/private/tmp/mb3dx-test-compact-formulas
.PHONY: test-compact-formulas

# Formula optimizations are checked against the independent, full native path.
test-prepared-catalog: tests/test_prepared_catalog.c renderer.c c_formula_vm.h c_formula_compact.h native-c/libformulas.a
	$(CC) $(CFLAGS) -DUSE_C_FORMULA_VM -I. tests/test_prepared_catalog.c native-c/libformulas.a -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /private/tmp/mb3dx-test-prepared-catalog
	/private/tmp/mb3dx-test-prepared-catalog
benchmark-c-formulas: tools/benchmark-c-formulas.c renderer.c c_formula_vm.h c_formula_compact.h native-c/libformulas.a
	$(CC) $(CFLAGS) -DUSE_C_FORMULA_VM -I. tools/benchmark-c-formulas.c native-c/libformulas.a -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /private/tmp/mb3dx-benchmark-formulas
	/private/tmp/mb3dx-benchmark-formulas
.PHONY: test-prepared-catalog benchmark-c-formulas

test-map-combine: tests/test_map_combine.c renderer.o native-c/libformulas.a
	$(CC) $(CFLAGS) -I. tests/test_map_combine.c renderer.o native-c/libformulas.a -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /private/tmp/mb3dx-test-map-combine
	/private/tmp/mb3dx-test-map-combine
.PHONY: test-map-combine
test: test-map-combine

# New formula translations are checked against independent Rust vectors.
test-added-formulas: renderer.o native-c/libformulas.a
	$(CC) $(CFLAGS) -DUSE_C_FORMULA_VM -I. tests/test_added_formula_vectors.c native-c/libformulas.a -lm -pthread -framework ImageIO -framework CoreGraphics -framework CoreFoundation -o /private/tmp/mb3dx-test-added-formulas
	/private/tmp/mb3dx-test-added-formulas
.PHONY: test-added-formulas

release-sandbox:
	sh tools/release-app-store.sh --local

release-app-store:
	sh tools/release-app-store.sh --app-store
.PHONY: release-sandbox release-app-store
