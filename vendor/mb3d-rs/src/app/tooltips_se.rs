//! Help for controls introduced by the SE desktop layout.
use crate::vcl::Ui;

pub(super) fn install(ui: &mut Ui) {
    for (form, entries) in [
        ("Mand3DForm", &[
            ("SeAppMenu", "About Mandelbulb3D SE, support, source code, and licenses."),
            ("SeHistory", "Browse and reload recent rendered scenes."),
            ("SeActualSize", "Show one image pixel per display pixel."),
            ("SpeedButton35", "Oversampling renders a larger image and reduces it to the output size."),
            ("SeMaps", "Open the folder containing object and light maps."),
            ("SeBackgrounds", "Open the folder containing background images."),
            ("CameraCopy", "Copy camera position, rotation, zoom, and field of view."),
            ("CameraPaste", "Restore the copied camera and start a render."),
        ][..]),
        ("FNavigator", &[
            ("SeSlot", "Select a formula slot. The opened list includes formula names. An asterisk marks an active slot."),
            ("SeFormula", "Choose a formula from the categories, or search by name."),
            ("SeRange", "Set the sensitivity of the formula parameter sliders."),
            ("EditSeIterations", "Applications of this formula per pass. Zero disables the slot."),
            ("SeResetValue", "Restore the selected parameter to its formula default."),
            ("SePreviousSlot", "Select the previous formula slot."),
            ("SeNextSlot", "Select the next formula slot."),
            ("TrackBar1", "Adjust Navigator display brightness. Ctrl-click or Windows-key-click resets to neutral."),
        ][..]),
        ("LightAdjustForm", &[
            ("SeLightingReset", "Reset the lighting to a gray palette and one white directional light."),
            ("SeLightingUndo", "Undo the previous lighting edit."),
            ("SeLightingRender", "Apply the lighting and render the main image."),
            ("SeLightType", "Choose a directional light, positional light, or light map."),
            ("SeLightStrength", "Adjust the light source strength. Type into the adjacent field for smaller or larger values."),
            ("SeLightMoveStep", "World distance moved by the positional light steppers."),
            ("SeOutsidePalette", "Open the outside object color palette."),
            ("SeInsidePalette", "Open the inside object color palette."),
            ("SeDiffusePreview", "Edit the diffuse colors and emissive opacity."),
            ("SeSpecularPreview", "Edit the specular colors and transparency opacity."),
            ("SeOutsideZoom", "Zoom the exterior histogram and color start/end slider ranges."),
            ("SeInsideZoom", "Zoom the interior histogram and color start/end slider ranges."),
            ("SeObjectMode", "Choose how the surface selects a position in the color palette."),
            ("SeRadianceMode", "Select fog, volumetric light, or Emissive DIFS lighting."),
            ("SeEmitStop", "Select the diffuse palette stop whose opacity controls emissive strength."),
            ("SeEmitOpacity", "Diffuse opacity for the selected stop, as a percentage. Render again after changing emissive strength."),
            ("Edit1", "Light strength. Scientific notation such as 1e-6 is supported."),
            ("ButtonGetPos", "Click the main render to position this light on a surface."),
        ][..]),
        ("FormulaGUIForm", &[
            ("SeFormula", "Choose a formula for the selected slot, or use Search or Clear."),
            ("SeMode", "Alternate formulas, interpolate the first two slots, or combine two formula programs."),
            ("SeRepeat", "First formula repeated after the last slot."),
            ("SeSplit", "First formula in the second DE-combination program."),
            ("SeRepeat2", "First formula repeated within the second program."),
            ("SeRender", "Render outside surfaces, inside surfaces, or both."),
            ("SeCopySlot", "Copy the selected formula and its iteration count. Right-click to copy all active formula names as a comma-separated line."),
            ("SePasteSlot", "Paste the copied formula into the selected slot."),
            ("SeInfo", "Show the selected formula's information."),
            ("SeResetProgram", "Restore the default formula program."),
            ("SeApplyProgram", "Apply the formula program and render the main image."),
            ("EditItCount", "Iterations per pass, or interpolation weight. Zero disables the slot."),
        ][..]),
        ("PostProForm", &[
            ("SeAmbientStrength", "Adjust ambient shadow strength on the current image using the existing shadow data."),
            ("SeAmbientStrengthEdit", "Ambient shadow multiplier from 0 to 5."),
            ("SeAmbientMethod", "Choose the ambient shadow calculation method."),
            ("SeAmbientLength", "Maximum ambient ray length on a logarithmic scale."),
            ("SeAmbientRays", "Number of DE ambient shadow rays. More rays increase quality and rendering time."),
            ("SeReflectionAmount", "Total reflection and transparency amount, multiplied by the local specular color."),
            ("SeTranslucency", "Calculate and cache the extra transmission data needed for translucency."),
            ("SeTransStrength", "Soften transmitted light and increase opacity on longer paths. Requires cached transmission data."),
            ("SeTransGlow", "Negative values favor clear edges. Positive values favor the opaque interior. Ctrl-click resets to zero."),
            ("SeTransStrengthEdit", "Translucency strength from 0 to 2. Calculate now after entering a value when the live sliders are disabled."),
            ("SeTransGlowEdit", "Translucency glow from -1 to +1."),
            ("SeDofPasses", "Number of depth-of-field filtering passes."),
            ("SeDofZ1", "Start of the sharp depth range. Use Get Z1 to pick a surface."),
            ("SeDofZ2", "End of the sharp depth range. Use Get Z2 to pick a surface."),
            ("SeDofAperture", "Larger apertures increase depth-of-field blur."),
            ("SeDofRadius", "Maximum depth-of-field blur radius in render pixels."),
        ][..]),
        ("AnimationForm", &[
            ("SeKeys", "Select a keyframe to edit it. The empty row captures a new keyframe."),
            ("SeTimeline", "Scrub through the cached animation preview."),
            ("SeCurrentFrame", "Current animation frame, numbered from 1."),
            ("SeFps", "Playback frames per second."),
            ("SeInsertKey", "Insert the last completed main render after the selected keyframe."),
            ("SeRenderFrame", "Render the current animation frame at the output size."),
            ("SePlayback", "Pause or resume the cached animation preview."),
            ("SeFrameNumber", "Overlay a frame number at display resolution."),
            ("SeFrameColor", "Color of the frame-number overlay."),
            ("SeSampling", "Oversampling for exported frames. The output width and height stay the same."),
            ("SeInterpolation", "Choose linear or quadratic Bezier animation interpolation."),
            ("SePreviewScale", "Reduce preview dimensions for faster rendering and lower memory use."),
        ][..]),
        ("ColorForm", &[
            ("SePaletteMode", "Edit the outside or inside object colors."),
            ("SePaletteStop", "Choose the palette stop to edit."),
            ("SePalettePosition", "Position of the selected stop. Moving it updates the image."),
            ("SeDiffuseWell", "Edit diffuse color and opacity. Diffuse opacity controls emissive DIFS strength."),
            ("SeSpecularWell", "Edit specular color and opacity. Specular opacity controls transparency."),
            ("SeGlue", "Stretch neighboring stop positions proportionally when moving a stop."),
            ("SeRandom0", "Randomize diffuse colors around the reference color."),
            ("SeRandom1", "Randomize specular colors around the reference color."),
            ("SeUpdatePalette", "Repaint the image with the current palette."),
            ("SePaletteBar0", "Diffuse colors with opacity above. Drag a marker, double-click to choose a color, or right-click for Copy and Paste."),
            ("SePaletteBar1", "Specular colors with opacity above. Drag a marker, double-click to choose a color, or right-click for Copy and Paste."),
        ][..]),
        ("SeColorPicker", &[
            ("Wheel", "Choose hue and saturation. Drag to update the color interactively."),
            ("Brightness", "Adjust the brightness of the selected color."),
            ("Opacity", "Adjust the selected color's opacity."),
            ("HexValue", "Six-digit RGB hexadecimal color, such as #FF8000."),
            ("Eyedropper", "Click any desktop pixel to sample its color. Escape cancels sampling."),
            ("PickCancel", "Close the color picker. Color changes are already applied."),
        ][..]),
    ] {
        if !ui.has_form(form) { continue; }
        for &(name, help) in entries {
            if ui.f(form).has(name) { ui.cm(form,name).hint=help.into(); }
        }
    }
    for form in &mut ui.forms {
        form.ctl[0].show_hint=Some(true);
        for control in &mut form.ctl {
            if !control.hint.is_empty() { control.show_hint=Some(true); }
            if control.hint.is_empty() && control.fine_track_drag {
                control.hint="Hold Shift while dragging for fine adjustment.".into();
                control.show_hint=Some(true);
            }
        }
    }
}
