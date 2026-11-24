//! SE Lighting window layout and Radiance controls.
use super::main_se::place;
use super::util::{argb, fts, parse_float};
use super::Mb3d;
use crate::scene::Scene;
use crate::vcl::control::{Control, Kind};
use crate::vcl::form::Form;
use crate::vcl::Ui;

const F: &str = "LightAdjustForm";
const NONE: i32 = 0;
const DYNAMIC: i32 = 1;
const VOLUME: i32 = 2;
const EMISSIVE: i32 = 3;

fn add(form: &mut Form, parent: usize, name: &str, class: &str, caption: &str, bounds: (i32, i32, i32, i32)) -> usize {
    let mut control = Control::new(name, class);
    control.caption = caption.into();
    control.set_bounds(bounds.0, bounds.1, bounds.2, bounds.3);
    form.add_control(parent, control)
}

fn label(form: &mut Form, parent: usize, name: &str, caption: &str, x: i32, y: i32) {
    add(form, parent, name, "TLabel", caption, (x, y, 175, 20));
}

fn button(form: &mut Form, parent: usize, name: &str, caption: &str, bounds: (i32, i32, i32, i32)) -> usize {
    let id = add(form, parent, name, "TButton", caption, bounds);
    form.ctl[id].events.insert("OnClick".into(), name.into());
    id
}

fn menu(form: &mut Form, parent: usize, name: &str, choices: Vec<String>, bounds: (i32, i32, i32, i32)) {
    let id = add(form, parent, name, "TComboBox", "", bounds);
    let control = &mut form.ctl[id];
    control.items = choices;
    control.style = "csDropDownList".into();
    control.set_item_index(0);
    control.events.insert("OnChange".into(), name.into());
}

fn edit(form: &mut Form, parent: usize, name: &str, bounds: (i32, i32, i32, i32)) {
    let id = add(form, parent, name, "TEdit", "", bounds);
    form.ctl[id].events.insert("OnExit".into(), name.into());
    form.ctl[id].events.insert("OnKeyDown".into(), name.into());
}

pub(super) fn configure(ui: &mut Ui) {
    ui.set_client_size(F, 600, 742);
    let form = ui.fm(F);
    place(form, 0, "PageControl2", (12, 10, 576, 668));
    form.c_mut("Panel3").visible = false;
    form.c_mut("Panel4").visible = false;

    let tabs = form.id("PageControl2").unwrap();
    let objects = form.id("TabSheet3").unwrap();
    let lights = add(form, tabs, "SeLights", "TTabSheet", "Light sources", (0, 0, 0, 0));
    form.ctl[tabs].children.retain(|&child| child != lights);
    form.ctl[tabs].children.insert(1, lights);
    form.ctl[tabs].active_page = Some(objects);
    configure_sources(form, lights);
    form.c_mut("TabSheet5").caption = "Background".into();
    form.c_mut("Fog").caption = "Radiance".into();
    let ambient = form.id("TabSheet4").unwrap();
    for (slider, y) in [
        ("TrackBar8", 2), ("TrackBar4", 30), ("TrackBar32", 110),
        ("TrackBar11", 160), ("TrackBar23", 196), ("TrackBar24", 244),
    ] {
        place(form, ambient, slider, (101, y, 310, 26));
    }
    let background = form.id("TabSheet5").unwrap();
    for (slider, y) in [("TrackBar22", 118), ("TrackBar21", 145), ("TrackBar20", 172), ("TrackBar33", 201)] {
        place(form, background, slider, (93, y, 302, 26));
    }

    for (name, title, x, width) in [
        ("SpeedButton13", "Open…", 12, 80), ("CheckBox11", "Keep lights", 98, 94),
        ("SpeedButton14", "Save…", 198, 80),
    ] {
        place(form, 0, name, (x, 698, width, 27));
        let control = form.c_mut(name);
        control.caption = title.into();
        control.glyph = None;
        control.flat = false;
        control.visible = true;
    }
    button(form, 0, "SeLightingReset", "Reset", (285, 698, 70, 27));
    form.c_mut("SeLightingReset").hint = "Reset lighting to a gray palette and one white directional light.".into();
    button(form, 0, "SeLightingUndo", "Undo", (362, 698, 55, 27));
    let render = button(form, 0, "SeLightingRender", "Apply && Render", (424, 698, 160, 27));
    form.ctl[render].default = true;

    configure_object(form, objects);

    let radiance = form.id("Fog").unwrap();
    label(form, radiance, "SeRadianceLabel", "Mode", 15, 19);
    menu(form, radiance, "SeRadianceMode",
        ["None", "Dynamic fog on iterations", "Volumetric lighting", "Emissive DIFS"].map(str::to_string).into(),
        (189, 14, 341, 26));
    label(form, radiance, "SeVolSourceLabel", "Volumetric light source", 15, 60);
    menu(form, radiance, "SeVolSource", (1..=6).map(|n| format!("Light {n}")).collect(), (189, 55, 152, 25));
    for (row, (slider, caption)) in [
        ("TrackBar6", "Intensity"), ("TrackBar3", "Level"), ("TrackBar19", "Offset"),
    ].into_iter().enumerate() {
        let y = 95 + row as i32 * 40;
        label(form, radiance, &format!("SeFogLabel{row}"), caption, 15, y + 4);
        place(form, radiance, slider, (189, y, 285, 30));
        add(form, radiance, &format!("SeFogValue{row}"), "TLabel", "", (490, y + 4, 53, 20));
    }
    for name in ["Label1", "Label18", "Label44", "Label47"] {
        form.c_mut(name).visible = false;
    }
    label(form, radiance, "SeFogColorLabel", "Fog Color", 15, 233);
    place(form, radiance, "SpeedButton4", (189, 226, 87, 28));
    form.c_mut("SpeedButton4").caption.clear();
    label(form, radiance, "SeFogColor2Label", "Intense Fog Color", 15, 270);
    place(form, radiance, "SpeedButton30", (189, 264, 87, 28));
    place(form, radiance, "FogResetButton", (314, 226, 216, 27));
    form.c_mut("FogResetButton").caption = "Reset sliders to zero effect".into();
    label(form, radiance, "SeFogIterationLabel", "Fog iteration (0 = all)", 15, 319);
    edit(form, radiance, "SeFogIteration", (189, 311, 75, 25));
    label(form, radiance, "SeVolumeSizeLabel", "Map size adjustment", 15, 356);
    edit(form, radiance, "SeVolumeSize", (189, 348, 75, 25));
    place(form, radiance, "CheckBox19", (15, 386, 160, 23));
    place(form, radiance, "CheckBox23", (189, 386, 160, 23));

    label(form, radiance, "SeEmitStopLabel", "Diffuse palette stop", 15, 433);
    menu(form, radiance, "SeEmitStop", (1..=10).map(|n| n.to_string()).collect(), (189, 426, 70, 25));
    label(form, radiance, "SeEmitOpacityLabel", "Diffuse opacity (%)", 283, 433);
    edit(form, radiance, "SeEmitOpacity", (445, 426, 85, 25));
    form.c_mut("SeEmitOpacity").hint = "Diffuse opacity controls emissive strength for this palette stop.".into();
    for control in &mut form.ctl {
        if control.kind == Kind::TrackBar {
            control.fine_track_drag = true;
        }
    }
}

pub(super) fn load(ui: &mut Ui, scene: &Scene) {
    let mode = if scene.emissive_difs.is_some() { EMISSIVE }
        else if scene.vol_light.is_some() { VOLUME }
        else if scene.lighting.dyn_fog != 53.0 { DYNAMIC }
        else { NONE };
    ui.set_item_index(F, "SeRadianceMode", mode);
    ui.set_item_index(F, "SeVolSource", scene.vol_light.map_or(0, |volume| volume.light.min(5) as i32));
    ui.set_text(F, "SeFogIteration", &scene.dfog_on_it.to_string());
    ui.set_text(F, "SeVolumeSize", &scene.vol_light.map_or(0, |volume| volume.map_size).to_string());
    opacity_text(ui, scene);
    update_controls(ui);
}

pub(super) fn update_controls(ui: &mut Ui) {
    let mode = ui.item_index(F, "SeRadianceMode");
    let fog = matches!(mode, DYNAMIC | VOLUME);
    for (row, slider) in ["TrackBar6", "TrackBar3", "TrackBar19"].into_iter().enumerate() {
        for name in [slider.to_string(), format!("SeFogLabel{row}"), format!("SeFogValue{row}")] {
            ui.set_enabled(F, &name, fog);
        }
        ui.set_caption(F, &format!("SeFogValue{row}"), &ui.position(F, slider).to_string());
    }
    for (names, enabled) in [
        (&["SeVolSource", "SeVolSourceLabel", "SeVolumeSize", "SeVolumeSizeLabel"][..], mode == VOLUME),
        (&["SeFogIteration", "SeFogIterationLabel", "SpeedButton30", "SeFogColor2Label"][..], mode == DYNAMIC),
        (&["FogResetButton", "CheckBox19", "CheckBox23"][..], fog),
        (&["SpeedButton4", "SeFogColorLabel"][..], mode != NONE),
    ] {
        for name in names { ui.set_enabled(F, name, enabled); }
    }
    ui.set_caption(F, "SeFogColorLabel", match mode {
        EMISSIVE => "Emissive Light Color", VOLUME => "Volumetric Light Color", _ => "Fog Color",
    });
}

pub(super) fn put(ui: &Ui, scene: &mut Scene) {
    let number = |name: &str| parse_float(&ui.text(F, name)).filter(|value| value.is_finite()).unwrap_or(0.0);
    let mode = ui.item_index(F, "SeRadianceMode");
    scene.emissive_difs = (mode == EMISSIVE).then(|| scene.lighting.dyn_fog_col.map(|v| f32::from(v) / 255.0));
    scene.dfog_on_it = number("SeFogIteration").round().clamp(0.0, 255.0) as u16;
    scene.vol_light = (mode == VOLUME).then(|| crate::vollight::VolLightParams {
        light: ui.item_index(F, "SeVolSource").clamp(0, 5) as usize,
        map_size: number("SeVolumeSize").round().clamp(-2.0, 9.0) as i32,
    });
    if matches!(mode, NONE | EMISSIVE) {
        scene.lighting.dyn_fog = 53.0;
        scene.dfog_on_it = 0;
    }
}

pub(super) fn emissive_swatch(scene: &Scene) -> Option<u32> {
    scene.emissive_difs.map(|color| argb(color.map(|value| (value * 255.0).round() as u8)))
}

pub(super) fn opacity_text(ui: &mut Ui, scene: &Scene) {
    let i = ui.item_index(F, "SeEmitStop").clamp(0, 9) as usize;
    ui.set_text(F, "SeEmitOpacity", &fts(f64::from(scene.emissive_opacity[i]) * 100.0));
}

pub(super) fn set_opacity(app: &mut Mb3d, ui: &mut Ui) {
    let i = ui.item_index(F, "SeEmitStop").clamp(0, 9) as usize;
    let text = ui.text(F, "SeEmitOpacity");
    if let Some(value) = parse_float(&text).filter(|value| value.is_finite()) {
        let value = (value.clamp(0.0, 100.0) / 100.0) as f32;
        if app.scene.emissive_opacity[i] != value {
            app.scene.emissive_opacity[i] = value;
            super::light_form::trigger_repaint(app, ui);
        }
    }
    opacity_text(ui, &app.scene);
}

const OBJECT_ROWS: [(&str, &str, i32, (i32, i32), (i32, i32)); 7] = [
    ("TrackBar5", "Diffuse strength", 50, (190, 100), (300, 64)),
    ("TrackBar7", "Specular strength", 88, (190, 100), (300, 64)),
    ("TrackBar9", "Color start", 214, (190, 230), (430, 44)),
    ("TrackBar10", "Color end", 252, (190, 230), (430, 44)),
    ("TrackBar14", "Color variation on Z", 290, (190, 98), (296, 66)),
    ("TrackBar12", "Color start", 418, (190, 230), (430, 44)),
    ("TrackBar13", "Color end", 454, (190, 230), (430, 44)),
];

fn configure_sources(form: &mut Form, lights: usize) {
    place(form, lights, "TabControl1", (10, 12, 550, 565));
    let sources = form.id("TabControl1").unwrap();
    form.ctl[sources].tab_width = 80;
    place(form, sources, "PageControl1", (9, 178, 529, 220));
    form.c_mut("PageControl1").transparent=true;
    form.c_mut("PageControl1").style = "tsButtons".into();
    for page in ["TabSheet1", "TabSheet2", "TabSheet6"] {
        form.c_mut(page).tab_visible = false;
        form.c_mut(page).transparent=true;
    }
    for (name, caption, bounds) in [
        ("CheckBox4", "Enabled", (12, 33, 150, 25)),
        ("SpeedButton12", "", (70, 100, 84, 27)),
        ("Label26", "Strength", (12, 146, 100, 20)),
        ("Edit1", "", (416, 143, 76, 26)),
        ("UpDown4", "", (498, 143, 23, 26)),
        ("CheckBox7", "Ignore hard / ambient shadows", (12, 403, 310, 26)),
        ("Label8", "Diffuse function", (12, 449, 180, 20)),
        ("ComboBox1", "", (320, 445, 201, 26)),
        ("Label9", "Specular exponent", (12, 492, 180, 20)),
        ("ComboBox2", "", (320, 488, 201, 26)),
    ] {
        place(form, sources, name, bounds);
        if !caption.is_empty() {
            form.c_mut(name).caption = caption.into();
        }
    }
    for name in ["CheckBox4", "CheckBox6", "CheckBox7"] {
        form.c_mut(name).props.retain(|(key, _)| key != "Alignment");
    }
    form.c_mut("Label9").alignment = crate::vcl::canvas::HAlign::Left;
    form.c_mut("SpeedButton12").flat = false;
    // Keep the light-type pages behind these shared controls.
    let pages = form.id("PageControl1").unwrap();
    form.ctl[sources].children.retain(|&child| child != pages);
    form.ctl[sources].children.insert(0, pages);
    label(form, sources, "SeLightTypeLabel", "Type", 12, 61);
    menu(form, sources, "SeLightType",
        ["Directional", "Positional", "Light map"].map(str::to_string).into(), (70, 57, 117, 26));
    label(form, sources, "SeLightColorLabel", "Color", 12, 104);
    place(form, sources, "ButtonGetPos", (199, 57, 171, 26));
    form.c_mut("ButtonGetPos").caption = "Place on render…".into();
    place(form, sources, "Label25", (392, 61, 49, 20));
    place(form, sources, "ComboBox4", (451, 57, 70, 26));
    for name in ["Label32", "ComboBox5"] {
        form.c_mut(name).visible = false;
    }
    form.c_mut("ComboBox1").items = ["Cosine", "Cosine squared", "Wrapped", "Wrapped squared"]
        .map(str::to_string).into();
    let strength = add(form, sources, "SeLightStrength", "TTrackBar", "", (169, 143, 235, 26));
    form.ctl[strength].tick_style = "tsNone".into();
    form.ctl[strength].min = -100;
    form.ctl[strength].max = 100;
    form.ctl[strength].events.insert("OnMouseUp".into(), "SeLightStrengthUp".into());
    form.ctl[strength].events.insert("OnChange".into(), "SeLightStrength".into());

    let directional = form.id("TabSheet1").unwrap();
    let positional = form.id("TabSheet2").unwrap();
    for (axis, label_name, directional_slider, positional_label, positional_slider, step) in [
        (0, "Label3", "TrackBar1", "Label13", "TrackBar16", "UpDown1"),
        (1, "Label2", "TrackBar2", "Label14", "TrackBar15", "UpDown2"),
        (2, "", "", "Label15", "TrackBar17", "UpDown3"),
    ] {
        let y = 6 + 43 * axis;
        let caption = ["X angle / position", "Y angle / position", "Z position"][axis as usize];
        if axis < 2 {
            place(form, directional, label_name, (2, y + 4, 195, 20));
            form.c_mut(label_name).caption = caption.into();
            place(form, directional, directional_slider, (210, y, 182, 26));
            edit(form, directional, &format!("SeLightAngle{axis}"), (406, y, 105, 26));
        }
        place(form, positional, positional_label, (2, y + 4, 195, 20));
        form.c_mut(positional_label).caption = caption.into();
        place(form, positional, positional_slider, (210, y, 182, 26));
        edit(form, positional, &format!("SeLightPosition{axis}"), (406, y, 76, 26));
        place(form, positional, step, (488, y, 23, 26));
    }
    place(form, directional, "CheckBox6", (2, 135, 310, 25));
    form.c_mut("CheckBox6").caption = "Relative to object (directional)".into();
    label(form, positional, "SeLightMoveStepLabel", "Move step (world)", 2, 136);
    edit(form, positional, "SeLightMoveStep", (164, 132, 110, 26));
    form.c_mut("SeLightMoveStep").text = "0.01".into();
}

pub(super) fn sync_source_fields(ui: &mut Ui, light: &crate::lighting::Light) {
    for (axis, angle) in [light.x_angle, light.y_angle].into_iter().enumerate() {
        ui.set_text(F, &format!("SeLightAngle{axis}"), &fts(angle.to_degrees()));
    }
    for (axis, position) in light.position.into_iter().enumerate() {
        ui.set_text(F, &format!("SeLightPosition{axis}"), &fts(position));
    }
}

fn configure_object(form: &mut Form, page: usize) {
    let palette = form.id("Panel1").unwrap();
    let map = form.id("Panel2").unwrap();
    for child in form.ctl[palette].children.clone().into_iter().chain(form.ctl[map].children.clone()) {
        form.ctl[child].visible = false;
    }
    for name in ["Label37", "SpeedButton1", "SpeedButton2", "CheckBox15"] {
        form.c_mut(name).visible = false;
    }
    place(form, page, "Panel1", (0, 121, 562, 366));
    place(form, page, "Panel2", (0, 121, 562, 366));

    for (name, caption, x) in [("SePaletteColoring", "Palette coloring", 96), ("SeMapColoring", "Map coloring", 286)] {
        let id = add(form, page, name, "TRadioButton", caption, (x, 12, 180, 26));
        form.ctl[id].events.insert("OnClick".into(), name.into());
    }
    for (index, (slider, title, row, (x, width), (field_x, field_width))) in OBJECT_ROWS.into_iter().enumerate() {
        let parent = if index < 2 { page } else { palette };
        let y = if index < 2 { row } else { row - 121 };
        label(form, parent, &format!("SeObjectLabel{index}"), title, 16, y + 4);
        place(form, parent, slider, (x, y, width, 26));
        let control = form.c_mut(slider);
        control.visible = true;
        control.tick_style = "tsNone".into();
        let field = format!("SeObjectValue{index}");
        edit(form, parent, &field, (field_x, y, field_width, 26));
        let control = form.c_mut(&field);
        control.tag = index as i64;
        control.events.insert("OnExit".into(), "SeObjectValue".into());
        control.events.insert("OnKeyDown".into(), "SeObjectValue".into());
    }

    label(form, palette, "SeObjectModeLabel", "Mode", 16, 7);
    menu(form, palette, "SeObjectMode", [
        "Smooth Iterations", "Orbit trap (mindist. to 0)", "Last length increase", "Rout angle of X, Y",
        "Rout angle of X, Z", "Rout angle of Y, Z", "Map on output vector",
    ].map(str::to_string).into(), (150, 3, 258, 27));

    for (name, title, x, y, width, height, inside) in [
        ("SeDiffusePreview", "", 378, 54, 160, 18, false),
        ("SeSpecularPreview", "", 378, 92, 160, 18, false),
        ("SeOutsidePalette", "Outside colors", 150, 168, 388, 34, false),
        ("SeInsidePalette", "Inside colors", 150, 372, 388, 34, true),
    ] {
        let (parent, offset) = if title.is_empty() { (page, 0) } else { (palette, 121) };
        if !title.is_empty() {
            label(form, palette, &format!("{name}Label"), title, 16, y - offset + 5);
        }
        let id = add(form, parent, name, "TImage", "", (x, y - offset, width, height));
        form.ctl[id].tag = i64::from(inside);
        form.ctl[id].cursor = "crHandPoint".into();
        form.ctl[id].hover_bezel=true;
        form.ctl[id].events.insert("OnClick".into(), "SeOpenColors".into());
    }

    for (name, x, y, width, height) in [
        ("SpeedButton34", 480, 214, 58, 26), ("Image1", 190, 245, 230, 4),
        ("Image2", 190, 447, 230, 4), ("CheckBox1", 16, 330, 165, 24),
        ("CheckBox22", 190, 330, 172, 24), ("TrackBar18", 432, 328, 60, 26),
        ("CheckBox10", 498, 330, 41, 24),
    ] {
        place(form, palette, name, (x, y - 121, width, height));
        form.c_mut(name).visible = true;
    }
    form.c_mut("SpeedButton34").caption = "Fit".into();
    form.c_mut("SpeedButton34").flat = false;
    form.c_mut("CheckBox1").caption = "Color cycling".into();
    form.c_mut("CheckBox22").caption = "No interpolation".into();
    form.c_mut("CheckBox10").caption = "i2".into();
    // Gamma is shared by palette and map coloring; keep it outside both panels.
    label(form, page, "SeGammaLabel", "Gamma", 366, 332);
    place(form, page, "TrackBar18", (432, 328, 60, 26));
    place(form, page, "CheckBox10", (498, 330, 41, 24));
    for (name, y) in [("SeOutsideZoom", 252), ("SeInsideZoom", 454)] {
        let id = add(form, palette, name, "TSpeedButton", "Zoom", (480, y - 121, 58, 26));
        form.ctl[id].group_index = if y == 252 { 90 } else { 91 };
        form.ctl[id].allow_all_up = true;
        form.ctl[id].events.insert("OnClick".into(), name.into());
    }

    label(form, map, "SeDiffuseMapLabel", "Diffuse map", 16, 16);
    menu(form, map, "SeDiffuseMap", Vec::new(), (150, 13, 258, 27));
    place(form, map, "Image4", (420, 13, 116, 64));
    form.c_mut("Image4").visible = true;
    place(form, map, "Label40", (420, 39, 115, 25));
    label(form, map, "SeMapModeLabel", "Map mode", 16, 51);
    menu(form, map, "SeMapMode", ["Iteration / trap", "Normals", "Wrap 1", "Wrap 2"].map(str::to_string).into(), (150, 48, 258, 27));
    for (index, (slider, title)) in [
        ("TrackBar29", "Map X offset"), ("TrackBar28", "Map Y offset"),
        ("TrackBar30", "Map rotation (°)"), ("TrackBar31", "Map scale"),
    ].into_iter().enumerate() {
        let y = 85 + index as i32 * 28;
        label(form, map, &format!("SeMapLabel{index}"), title, 16, y + 4);
        place(form, map, slider, (150, y, 258, 25));
        form.c_mut(slider).visible = true;
        edit(form, map, &format!("SeObjectMapValue{index}"), (420, y, 116, 25));
        let control = form.c_mut(&format!("SeObjectMapValue{index}"));
        control.tag = index as i64;
        control.events.insert("OnExit".into(), "SeObjectMapValue".into());
        control.events.insert("OnKeyDown".into(), "SeObjectMapValue".into());
    }
    place(form, map, "CheckBox18", (16, 201, 330, 24));
    form.c_mut("CheckBox18").visible = true;
    form.c_mut("CheckBox18").caption = "Combine map intensity with palette colors".into();

    for (name, y) in [("SeInsideDivider", 367 - 121), ("SeFavoritesDivider", 490)] {
        let parent = if name == "SeInsideDivider" { palette } else { page };
        let line = add(form, parent, name, "TShape", "", (16, y, 522, 1));
        form.ctl[line].brush_color = 0xFF666666;
        form.ctl[line].pen_color = 0xFF666666;
    }
    label(form, page, "SeFavoritesLabel", "Favorites", 16, 499);
    button(form, page, "SeAddFavorite", "+", (130, 494, 32, 32));
    for column in 0..5 {
        let name = builtin_favorite_control(column);
        place(form, page, &name, (174 + column as i32 * 54, 494, 50, 34));
        form.c_mut(&name).flat = false;
    }
    for index in 0..20 {
        let name = favorite_control(index);
        let bounds = (16 + (index % 10) as i32 * 52, 534 + (index / 10) as i32 * 38, 50, 34);
        if index < 10 {
            place(form, page, &name, bounds);
        } else {
            let id = add(form, page, &name, "TSpeedButton", "", bounds);
            form.ctl[id].tag = index as i64 + 6;
            form.ctl[id].events.insert("OnClick".into(), "SpeedButton15Click".into());
        }
        let control = form.c_mut(&name);
        control.visible = true;
        control.caption = (index + 1).to_string();
        control.enabled = false;
        control.flat = false;
        control.events.insert("OnMouseUp".into(), "SeFavoriteMouseUp".into());
    }
    label(form, page, "SeObjectStatus", "", 16, 612);
}

pub(super) fn builtin_favorite_control(index: usize) -> String {
    format!("SpeedButton{}", [15, 16, 17, 18, 19][index])
}

pub(super) fn favorite_control(index: usize) -> String {
    [20, 21, 22, 23, 24, 25, 26, 27, 28, 29].get(index)
        .map_or_else(|| format!("SeFavorite{index}"), |number| format!("SpeedButton{number}"))
}

pub(super) fn sync_object_values(ui: &mut Ui) {
    for (index, (slider, _, _, _, _)) in OBJECT_ROWS.iter().enumerate() {
        ui.set_text(F, &format!("SeObjectValue{index}"), &ui.position(F, slider).to_string());
    }
    for index in 0..4 {
        let slider = map_control(index);
        let value = ui.position(F, slider) as f64;
        let display = match index {
            0 | 1 => value / 255.0,
            2 => (value - 128.0) * 180.0 / 128.0,
            _ => map_scale_base(ui).powf(value - 30.0),
        };
        ui.set_text(F, &format!("SeObjectMapValue{index}"), &super::util::float_general(display, 4));
    }
}

fn map_control(index: usize) -> &'static str {
    ["TrackBar29", "TrackBar28", "TrackBar30", "TrackBar31"][index]
}

fn map_scale_base(ui: &Ui) -> f64 {
    if ui.item_index(F, "SeMapMode") >= 2 { 1.2 } else { 1.05 }
}

pub(super) fn object_value_edited(ui: &mut Ui, index: usize, is_map: bool) -> bool {
    let mut changed = false;
    let name = format!("{}{index}", if is_map { "SeObjectMapValue" } else { "SeObjectValue" });
    if let Some(value) = parse_float(&ui.text(F, &name)).filter(|value| value.is_finite()) {
        let (slider, value) = if is_map {
            let slider = map_control(index);
            let value = match index {
                0 | 1 => value * 255.0,
                2 => value * 128.0 / 180.0 + 128.0,
                _ => value.max(0.001).log(map_scale_base(ui)) + 30.0,
            };
            (slider, value)
        } else {
            (OBJECT_ROWS[index].0, value)
        };
        let previous = ui.position(F, slider);
        ui.set_position(F, slider, value.round() as i64);
        changed = previous != ui.position(F, slider);
    }
    sync_object_values(ui);
    changed
}

pub(super) fn sync_object_mode(ui: &mut Ui, scene: &Scene) {
    let use_map = ui.checked(F, "CheckBox15");
    ui.set_checked(F, if use_map { "SeMapColoring" } else { "SePaletteColoring" }, true);
    ui.set_item_index(F, "SeMapMode", ui.item_index(F, "RadioGroup1"));
    let mode = if scene.lighting.color_on_otrap { i32::from(scene.color_option.min(5)) + 1 } else { 0 };
    ui.set_item_index(F, "SeObjectMode", mode);
    sync_object_values(ui);
}

fn map_thumbnail_cache_path(path:&std::path::Path,modified:Option<std::time::SystemTime>,size:u64)->std::path::PathBuf {
    let root=std::env::var_os("LOCALAPPDATA").or_else(||std::env::var_os("XDG_CACHE_HOME"))
        .map(std::path::PathBuf::from).unwrap_or_else(std::env::temp_dir);
    let canonical=path.canonicalize().unwrap_or_else(|_|path.to_path_buf());
    let stamp=modified.and_then(|v|v.duration_since(std::time::UNIX_EPOCH).ok()).map_or(0,|v|v.as_nanos());
    let key=format!("map32-v1:{}:{size}:{stamp}",canonical.to_string_lossy());
    let hash=key.bytes().fold(14695981039346656037u64,|h,b|(h^b as u64).wrapping_mul(1099511628211));
    root.join("Mandelbulb3D SE").join("Cache/MapThumbnails").join(format!("{hash:016x}.argb"))
}

fn map_thumbnail(path:&std::path::Path)->Option<crate::vcl::bitmap::Bitmap> {
    use std::{cell::RefCell,collections::HashMap,path::PathBuf,time::SystemTime};
    use crate::vcl::bitmap::Bitmap;
    type Cached=(Option<SystemTime>,u64,Option<Bitmap>);
    thread_local!{static CACHE:RefCell<HashMap<PathBuf,Cached>>=RefCell::new(HashMap::new());}
    let metadata=std::fs::metadata(path).ok()?;
    let modified=metadata.modified().ok();let size=metadata.len();
    CACHE.with(|cache|{
        if let Some((stamp,len,image))=cache.borrow().get(path){if *stamp==modified&&*len==size{return image.clone();}}
        let disk=map_thumbnail_cache_path(path,modified,size);
        if let Ok(bytes)=std::fs::read(&disk) {
            if bytes.len()==4+32*32*4&&&bytes[..4]==b"MT01" {
                let image=Bitmap{w:32,h:32,px:bytes[4..].chunks_exact(4).map(|v|u32::from_le_bytes(v.try_into().unwrap())).collect()};
                cache.borrow_mut().insert(path.into(),(modified,size,Some(image.clone())));return Some(image);
            }
        }
        let thumbnail=crate::image::load(path).ok().filter(|image|image.width>0&&image.height>0).map(|image|{
            let mut thumb=Bitmap::new(32,32,0xffdddddd);
            let scale=(32./image.width as f64).min(32./image.height as f64);
            let w=(image.width as f64*scale).round().max(1.) as usize;
            let h=(image.height as f64*scale).round().max(1.) as usize;
            for y in 0..h {for x in 0..w {
                let pixel=image.pixel((x*image.width/w).min(image.width-1),(y*image.height/h).min(image.height-1));
                let c=pixel.map(|v|if image.deep{(v>>8) as u32}else{v as u32});
                thumb.px[(y+(32-h)/2)*32+x+(32-w)/2]=0xff000000|(c[0]<<16)|(c[1]<<8)|c[2];
            }}thumb
        });
        if let Some(image)=&thumbnail {
            let mut bytes=b"MT01".to_vec();for pixel in &image.px {bytes.extend_from_slice(&pixel.to_le_bytes());}
            if let Some(parent)=disk.parent(){let _=std::fs::create_dir_all(parent);}
            let temporary=disk.with_extension("tmp");
            if std::fs::write(&temporary,bytes).is_ok(){let _=std::fs::rename(&temporary,&disk);}
        }
        cache.borrow_mut().insert(path.into(),(modified,size,thumbnail.clone()));thumbnail
    })
}

pub(super) fn refresh_map_menu(ui: &mut Ui, folder: &std::path::Path) {
    let selected = ui.position(F, "UpDownDiffMap");
    let mut maps = std::fs::read_dir(folder).into_iter().flatten().flatten().filter_map(|file| {
        let path = file.path();
        let ext = path.extension()?.to_str()?.to_ascii_lowercase();
        if !path.is_file() || !matches!(ext.as_str(), "png" | "jpg" | "jpeg" | "bmp" | "pgm") { return None; }
        let name = file.file_name().into_string().ok()?;
        let number = map_number(&name)?;
        Some((number, name))
    }).collect::<Vec<_>>();
    if !maps.iter().any(|(number, _)| *number == selected) {
        maps.push((selected, format!("{selected} (unavailable)")));
    }
    maps.sort_unstable();
    let index = maps.iter().position(|(number, _)| *number == selected).unwrap_or(0);
    let pictures=maps.iter().map(|(_,name)|map_thumbnail(&folder.join(name))).collect();
    ui.set_items(F, "SeDiffuseMap", maps.into_iter().map(|(_, name)| name).collect());
    let menu=ui.cm(F,"SeDiffuseMap");menu.item_pictures=pictures;menu.item_height=40;menu.drop_down_count=8;
    ui.set_item_index(F, "SeDiffuseMap", index as i32);
}

pub(super) fn map_number(name: &str) -> Option<i64> {
    let end = name.find(|c: char| !c.is_ascii_digit()).unwrap_or(name.len());
    name[..end].parse::<i64>().ok().filter(|value| (1..=65535).contains(value))
}

pub(super) fn refresh_palettes(ui: &mut Ui, scene: &Scene) {
    use crate::vcl::bitmap::Bitmap;
    let lighting = &scene.lighting;
    for (name, width, height, inside, bands) in [
        ("SeDiffusePreview", 160, 18, false, 1),
        ("SeSpecularPreview", 160, 18, false, 2),
        ("SeOutsidePalette", 388, 34, false, 3),
        ("SeInsidePalette", 388, 34, true, 3),
    ] {
        let mut image = Bitmap::new(width, height, 0xFF777777);
        let count = if inside { 4 } else { 10 };
        let position = |index: usize| if inside { lighting.interior[index].0 } else { lighting.palette[index].position };
        for x in 0..width {
            let p = x as f32 * 32767.0 / (width - 1) as f32;
            let right = (0..count).find(|&index| f32::from(position(index)) >= p).unwrap_or(count - 1);
            let left = right.saturating_sub(1);
            let span = (f32::from(position(right)) - f32::from(position(left))).max(1.0);
            let t = if lighting.no_col_ipol { 0.0 } else { ((p - f32::from(position(left))) / span).clamp(0.0, 1.0) };
            let sample = |index: usize| {
                if inside {
                    (lighting.interior[index].1, [lighting.interior_spec[index]; 3], 1.0, 1.0)
                } else {
                    let stop = lighting.palette[index];
                    (stop.diffuse, stop.specular, scene.emissive_opacity[index],
                        1.0 - f32::from(lighting.palette_alpha(index) >> 3) / 31.0)
                }
            };
            let (a, sa, oa, ta) = sample(left);
            let (b, sb, ob, tb) = sample(right);
            let mix = |a, b| a * (1.0 - t) + b * t;
            let color = |a: [u8; 3], b: [u8; 3]| argb(std::array::from_fn(|i| mix(f32::from(a[i]), f32::from(b[i])).round() as u8));
            let diffuse = color(a, b);
            let specular = color(sa, sb);
            let opacity = if bands == 2 { mix(ta, tb) } else { mix(oa, ob) };
            for y in 0..height {
                image.px[y * width + x] = if y < 5 {
                    let checker = if ((x / 4) + (y / 4)) % 2 == 0 { 175.0 } else { 82.0 };
                    argb([(checker + (255.0 - checker) * opacity).round() as u8; 3])
                } else if bands == 2 || (bands == 3 && y < 18) { specular } else { diffuse };
            }
        }
        ui.set_picture(F, name, Some(image));
    }
}

pub(super) fn zoom_object_range(ui: &mut Ui, inside: bool) {
    let (start, end, button, minimum, maximum) = if inside {
        ("TrackBar12", "TrackBar13", "SeInsideZoom", 0, 127)
    } else { ("TrackBar9", "TrackBar10", "SeOutsideZoom", -30, 90) };
    let a = ui.position(F, start);
    let b = ui.position(F, end);
    let pad = ((a - b).abs() / 2).max(3);
    let (low, high) = if ui.checked(F, button) {
        ((a.min(b) - pad).max(minimum), (a.max(b) + pad).min(maximum))
    } else { (minimum, maximum) };
    for name in [start, end] {
        let slider = ui.cm(F, name);
        slider.min = low;
        slider.max = high;
    }
}

#[cfg(test)] mod se_windows_cache_tests {
    use super::*;
    #[test] fn se_windows_strength_has_no_tick_line() {
        let mut ui=Ui::default();ui.add_form(include_str!("forms/LightAdjust.dfm")).unwrap();configure(&mut ui);
        assert_eq!(ui.c(F,"SeLightStrength").tick_style,"tsNone");
    }
    #[test] fn se_windows_object_color_bars_have_hover_bezels() {
        let mut ui=Ui::default();ui.add_form(include_str!("forms/LightAdjust.dfm")).unwrap();configure(&mut ui);
        let form=ui.fm(F);
        for name in ["SeDiffusePreview","SeSpecularPreview","SeOutsidePalette","SeInsidePalette"] {
            let control=&form.ctl[form.id(name).unwrap()];
            assert!(control.hover_bezel,"{name}");assert_eq!(control.cursor,"crHandPoint");
        }
    }
    #[test] fn se_windows_thumbnail_disk_cache_survives_a_fresh_thread() {
        let source=std::env::temp_dir().join(format!("mb3d-cache-test-{}.map",std::process::id()));
        std::fs::write(&source,b"not an image: disk cache must be used").unwrap();
        let meta=std::fs::metadata(&source).unwrap();
        let cache=map_thumbnail_cache_path(&source,meta.modified().ok(),meta.len());
        assert_ne!(cache,map_thumbnail_cache_path(&source,meta.modified().ok(),meta.len()+1));
        std::fs::create_dir_all(cache.parent().unwrap()).unwrap();
        let mut bytes=b"MT01".to_vec();for _ in 0..1024 {bytes.extend_from_slice(&0xff123456u32.to_le_bytes());}
        std::fs::write(&cache,bytes).unwrap();
        let path=source.clone();
        let image=std::thread::spawn(move||map_thumbnail(&path).unwrap()).join().unwrap();
        assert_eq!(image.px,vec![0xff123456;1024]);
        std::fs::remove_file(source).unwrap();std::fs::remove_file(cache).unwrap();
    }
}
