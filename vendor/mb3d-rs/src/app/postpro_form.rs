//! The post processing window (PostProcessForm.pas, `TPostProForm`):
//! normals on the z-buffer, hard shadows, ambient shadows, reflections and
//! transparency, depth of field and the recalculation of a selection.
//! "Calculate now" applies a processing to the kept image; the
//! "automatically" boxes put it into the parameters of the next calculation.

use super::util::{d2byte, d2byte_str, fts_single, parse_float, pti, ptf};
use super::{Mb3d, MAIN};
use crate::dof::DofParams;
use crate::scene::ShadowParams;
use crate::ssao::SsaoParams;
use crate::vcl::{Ev, Event, Ui};

const F: &str = "PostProForm";

/// Processings applied with "Calculate now" to the image on screen (kept
/// until the next calculation, like MB3D's bits in the G-buffer).
#[derive(Default)]
pub struct State {
    pub hs_now: bool,
    pub ao_now: bool,
    pub normals_now: bool,
    pub dof_now: bool,
    pub refl_now: bool,
    /// the processing running from this window (its name for the status
    /// line) and its start
    pub running: Option<(&'static str, std::time::Instant)>,
}

const PANELS: [(&str, &str, &str); 7] = [
    ("RecalcSectionBtn", "RecalcSectionPnl", "CheckBox21"),
    ("NormalsOnZBufferBtn", "NormalsOnZBufferPnl", "CheckBox23"),
    ("HardShadowsBtn", "HardShadowsPnl", "CheckBox9"),
    ("AmbientShadowsBtn", "AmbientShadowsPnl", "CheckBox11"),
    ("ReflTransparencyBtn", "ReflTransparencyPnl", "CheckBox24"),
    ("DepthOfFieldBtn", "DepthOfFieldPnl", "CheckBox1"),
    ("NoiseFilterBtn", "NoiseFilterPnl", "NoiseAutoCbx"),
];

const SE_PAGES: [(&str, &str, &str); 4] = [
    ("SeHardShadows", "Hard Shadows", "CheckBox9"),
    ("SeAmbientShadows", "Ambient Shadows", "CheckBox11"),
    ("SeReflection", "Refl/Trans", "CheckBox24"),
    ("SeDepthOfField", "Depth of Field", "CheckBox1"),
];

const SE_SLIDERS: [(&str, &str, i64, i64, f64); 10] = [
    ("SeReflectionAmount", "Edit6", 0, 1000, 1000.0),
    ("SeDofZ1", "Edit1", 0, 10000, 1000.0),
    ("SeDofZ2", "Edit10", 0, 10000, 1000.0),
    ("SeDofAperture", "Edit3", 0, 2000, 1000.0),
    ("SeDofRadius", "Edit2", 1, 10000, 10.0),
    ("SeAmbientLength", "Edit8", -2408, 2000, 1000.0),
    ("SeTransStrength", "SeTransStrengthEdit", 0, 200, 100.0),
    ("SeTransGlow", "SeTransGlowEdit", -100, 100, 100.0),
    ("SeAmbientStrength", "SeAmbientStrengthEdit", 0, 500, 100.0),
    ("SeSubsurfaceAmount", "SeSubsurfaceAmountEdit", 0, 1000, 1000.0),
];

fn configure_se(ui: &mut Ui) {
    use super::main_se::place;
    use crate::vcl::control::Control;
    use crate::vcl::form::Form;

    fn add(form: &mut Form, parent: usize, name: &str, class: &str, title: &str,
           bounds: (i32, i32, i32, i32)) -> usize {
        let mut control = Control::new(name, class);
        control.caption = title.into();
        control.set_bounds(bounds.0, bounds.1, bounds.2, bounds.3);
        form.add_control(parent, control)
    }

    fn row(form: &mut Form, page: usize, name: &str, title: &str, y: i32, x: i32, width: i32) {
        place(form, page, name, (x, y, width, 26));
        add(form, page, &format!("SeLabel{name}"), "TLabel", title, (16, y + 5, x - 22, 17));
    }

    ui.set_client_size(F, 540, 440);
    let form = ui.fm(F);
    form.ctl[0].caption = "Post-process".into();
    for (button, panel, _) in PANELS {
        form.c_mut(button).visible = false;
        form.c_mut(panel).visible = false;
    }
    for name in ["PostProcessHintPnl", "GroupBox4", "GroupBox6", "GroupBox10"] {
        form.c_mut(name).visible = false;
    }
    let tabs = add(form, 0, "SePostTabs", "TPageControl", "", (12, 10, 516, 418));
    let pages = SE_PAGES.map(|(name, title, _)| add(form, tabs, name, "TTabSheet", title, (0, 0, 0, 0)));
    for (index, (page, (_, _, automatic), title, calculate, reset)) in [
        (pages[0], SE_PAGES[0], "Calculate hard shadows automatically", "Button3", "Reset shadows"),
        (pages[1], SE_PAGES[1], "Calculate ambient shadows automatically", "Button10", "Reset shadows"),
        (pages[2], SE_PAGES[2], "Calculate Reflections (and, if selected, Transparency) automatically", "Button15", "Reset"),
        (pages[3], SE_PAGES[3], "Calculate DoF automatically", "Button1", "Reset DoF"),
    ].into_iter().enumerate() {
        place(form, page, automatic, (16, 14, 463, 25));
        form.c_mut(automatic).caption = title.into();
        place(form, page, calculate, (264, 346, 218, 30));
        form.c_mut(calculate).caption = "Calculate now".into();
        let id = add(form, page, &format!("SePostReset{index}"), "TButton", reset, (16, 346, 218, 30));
        form.ctl[id].tag = index as i64;
        form.ctl[id].events.insert("OnClick".into(), "SePostReset".into());
    }

    let [hard, ambient, reflection, dof] = pages;
    for i in 0..6 {
        let name = format!("CheckBox{}", i + 2);
        place(form, hard, &name, (16 + (i % 3) * 155, 52 + (i / 3) * 32, 140, 24));
        form.c_mut(&name).caption = format!("Light {}", i + 1);
    }
    place(form, hard, "CheckBox29", (16, 122, 245, 24));
    form.c_mut("CheckBox29").caption = "Softer hard shadows".into();
    place(form, hard, "CheckBox10", (16, 154, 315, 24));
    form.c_mut("CheckBox10").caption = "Set light function to cosine".into();
    row(form, hard, "Edit5", "Max length (0.001–100)", 196, 300, 182);
    row(form, hard, "Edit7", "Radius", 230, 300, 182);

    let method = add(form, ambient, "SeAmbientMethod", "TComboBox", "", (210, 50, 272, 27));
    form.ctl[method].style = "csDropDownList".into();
    // Keep legacy method indices so imported scenes retain their method.
    form.ctl[method].items = ["Fast approximation", "SSAO 24-bit", "SSAO 24-bit random", "DE ray tracing"]
        .map(str::to_string).into();
    form.ctl[method].events.insert("OnChange".into(), "SeAmbientMethod".into());
    add(form, ambient, "SeAmbientMethodLabel", "TLabel", "Method", (16, 55, 180, 18));
    add(form, ambient, "SeAmbientStrengthEdit", "TEdit", "", (0, 0, 0, 0));
    row(form, ambient, "SeAmbientStrengthEdit", "Strength (0–5)", 92, 390, 92);
    row(form, ambient, "Edit8", "Max length", 130, 390, 92);
    row(form, ambient, "Edit34", "Threshold", 130, 390, 92);
    row(form, ambient, "Edit9", "Border mirror", 168, 390, 92);
    row(form, ambient, "Edit21", "Random samples", 206, 390, 70);
    place(form, ambient, "UpDown3", (460, 206, 22, 26));
    place(form, ambient, "CheckBox12", (16, 244, 240, 24));
    place(form, ambient, "CheckBox22", (16, 244, 240, 24));
    form.c_mut("CheckBox22").caption = "Random first step".into();
    let rays = add(form, ambient, "SeAmbientRays", "TComboBox", "", (390, 168, 92, 26));
    form.ctl[rays].style = "csDropDownList".into();
    form.ctl[rays].items = ["3", "7", "17", "33"].map(str::to_string).into();
    form.ctl[rays].events.insert("OnChange".into(), "SeAmbientRays".into());
    add(form, ambient, "SeAmbientRaysLabel", "TLabel", "Rays", (16, 173, 150, 18));

    row(form, reflection, "Edit6", "Amount (0–1)", 50, 307, 175);
    row(form, reflection, "Edit11", "Depth (1–30)", 94, 307, 147);
    place(form, reflection, "UpDown2", (460, 94, 22, 26));
    form.c_mut("Edit11").read_only = false;
    for event in ["OnExit", "OnKeyDown"] {
        form.c_mut("Edit11").events.insert(event.into(), "SePostDepth".into());
    }
    place(form, reflection, "CheckBox27", (16, 125, 228, 24));
    form.c_mut("CheckBox27").caption = "Calculate transparency".into();
    place(form, reflection, "CheckBox28", (258, 125, 125, 24));
    form.c_mut("CheckBox28").caption = "Only DIFS".into();
    row(form, reflection, "Edit13", "Absorption (0–10000000000)", 158, 307, 175);
    row(form, reflection, "Edit14", "Refractive index (0.1–10)", 196, 307, 175);
    row(form, reflection, "Edit17", "Light scattering", 234, 307, 175);
    let translucency = add(form, reflection, "SeTranslucency", "TCheckBox", "Translucency", (16, 286, 109, 26));
    form.ctl[translucency].events.insert("OnClick".into(), "SeTransparency".into());
    for (name, title, x, field) in [
        ("SeTransStrengthEdit", "Strength", 126, 263), ("SeTransGlowEdit", "Glow", 321, 430),
    ] {
        add(form, reflection, &format!("SeLabel{name}"), "TLabel", title, (x, 292, if title=="Glow" {31}else{51}, 16));
        add(form, reflection, name, "TEdit", "", (field, 286, 52, 26));
    }
    let subsurface = add(form, reflection, "SeSubsurface", "TCheckBox", "Subsurface scattering", (16, 315, 198, 24));
    form.ctl[subsurface].events.insert("OnClick".into(), "SeSubsurface".into());
    form.ctl[subsurface].hint = "Trace light through the material. Adds light rays when enabled.".into();
    add(form,reflection,"SeSubsurfaceAmountLabel","TLabel","Amount",(216,320,52,20));
    add(form,reflection,"SeSubsurfaceAmountEdit","TEdit","1",(405,314,77,26));
    for name in ["CheckBox27", "CheckBox28"] {
        form.c_mut(name).events.insert("OnClick".into(), "SeTransparency".into());
    }

    for (name, title, y) in [
        ("Edit1", "Z1 sharp", 52), ("Edit10", "Z2 sharp", 98),
        ("Edit3", "Aperture", 144), ("Edit2", "Clipping radius", 190),
    ] {
        row(form, dof, name, title, y, 305, 86);
    }
    place(form, dof, "Button2", (400, 52, 82, 26));
    place(form, dof, "Button18", (400, 98, 82, 26));
    place(form, dof, "Button19", (16, 242, 164, 28));
    form.c_mut("Button19").caption = "Copy Z1 to Z2".into();
    add(form, dof, "SeDofPassesLabel", "TLabel", "Passes", (280, 247, 65, 18));
    let passes = add(form, dof, "SeDofPasses", "TComboBox", "", (362, 242, 120, 28));
    form.ctl[passes].style = "csDropDownList".into();
    form.ctl[passes].items = ["1", "2", "3"].map(str::to_string).into();
    form.ctl[passes].events.insert("OnChange".into(), "SeDofPasses".into());

    for ((slider, field, min, max, _), (page, x, y, width)) in SE_SLIDERS.into_iter().zip([
        (reflection, 140, 50, 151), (dof, 144, 52, 147), (dof, 144, 98, 147),
        (dof, 144, 144, 147), (dof, 144, 190, 147), (ambient, 184, 130, 192),
        (reflection, 181, 286, 75), (reflection, 357, 286, 66), (ambient, 184, 92, 192),
        (reflection,272,315,120),
    ]) {
        let id = add(form, page, slider, "TTrackBar", "", (x, y, width, 26));
        form.ctl[id].min = min;
        form.ctl[id].max = max;
        form.ctl[id].fine_track_drag = true;
        form.ctl[id].tick_style = "tsNone".into();
        form.ctl[id].modifier_resets_track = slider == "SeTransGlow";
        form.ctl[id].events.insert("OnChange".into(), "SePostSlider".into());
        if slider=="SeSubsurfaceAmount" {form.ctl[id].events.insert("OnMouseUp".into(),"SeSubsurfaceCommit".into());form.ctl[id].events.insert("OnKeyUp".into(),"SeSubsurfaceCommit".into());}
        let edit = form.c_mut(field);
        edit.events.insert("OnExit".into(), "SePostValue".into());
        edit.events.insert("OnKeyDown".into(), "SePostValue".into());
    }
    // Legacy checkbox captions default to placing the box on the right.
    for control in &mut form.ctl {
        if control.kind == crate::vcl::control::Kind::CheckBox {
            control.props.retain(|(key, _)| key != "Alignment");
        }
    }
}

pub(super) fn sync_se_sliders(ui: &mut Ui) {
    if !cfg!(feature = "se-desktop") {
        return;
    }
    for (name, field, _, _, scale) in SE_SLIDERS {
        let Some(mut value) = parse_float(&ui.text(F, field)).filter(|v| v.is_finite()) else { continue };
        if name == "SeAmbientLength" { value = value.max(1.0 / 255.0).log10(); }
        if matches!(name, "SeReflectionAmount" | "SeDofZ1" | "SeDofZ2") {
            let nominal: f64 = if name == "SeReflectionAmount" { 1.0 } else { 10.0 };
            ui.cm(F, name).max = (nominal.max(value * 1.1) * scale).ceil() as i64;
        }
        ui.set_position(F, name, (value * scale).round() as i64);
    }
}

fn sync_se_transparency(ui: &mut Ui, cache_ready: bool) {
    let on = ui.checked(F, "CheckBox27");
    for name in ["CheckBox28", "Edit13", "Edit14", "Edit17", "SeTranslucency"] {
        ui.set_enabled(F, name, on);
    }
    let translucency = on && ui.checked(F, "SeTranslucency");
    ui.set_enabled(F, "SeSubsurface", translucency);
    for name in ["SeSubsurfaceAmount","SeSubsurfaceAmountEdit"] {ui.set_enabled(F,name,translucency&&ui.checked(F,"SeSubsurface"));}
    for name in ["SeTransStrength", "SeTransStrengthEdit", "SeTransGlow", "SeTransGlowEdit"] {
        ui.set_enabled(F, name, translucency && (name.ends_with("Edit") || cache_ready));
    }
}

/// The strength of the noise filter (Noise Filter section), 0 when off.
pub fn noise_sigma(ui: &Ui) -> f32 {
    ui.text(F, "NoiseSigmaEdit").trim().replace(',', ".").parse::<f32>().map_or(4.0, |v| v.clamp(0.0, 255.0))
}

/// "Filter new pictures automatically" of the Noise Filter section.
pub fn noise_auto(ui: &Ui) -> bool {
    ui.has_form(F) && ui.checked(F, "NoiseAutoCbx")
}

fn shadow_params(ui: &Ui) -> ShadowParams {
    let mut lights = 0u8;
    for i in 0..6 {
        if ui.checked(F, &format!("CheckBox{}", i + 2)) {
            lights |= 1 << i;
        }
    }
    ShadowParams {
        lights,
        soft: ui.checked(F, "CheckBox29") && ui.enabled(F, "CheckBox29"),
        soft_radius: ptf(&ui.text(F, "Edit7")).clamp(0.01, 20.0) as f32,
        max_len_mul: ptf(&ui.text(F, "Edit5")).max(0.0) as f32,
        set_cos: ui.checked(F, "CheckBox10"),
    }
}

fn dof_params(ui: &Ui) -> DofParams {
    DofParams {
        z_sharp: ptf(&ui.text(F, "Edit1")) as f32,
        z_sharp2: ptf(&ui.text(F, "Edit10")) as f32,
        aperture: ptf(&ui.text(F, "Edit3")) as f32,
        clip_r: ptf(&ui.text(F, "Edit2")) as f32,
        passes: (ui.item_index(F, "RadioGroup1").clamp(0, 2) + 1) as u8,
        forward: ui.item_index(F, "RadioGroup2") == 1,
    }
}

/// The post processing parameters into the scene (`PutDOFparsToHeader`,
/// `PutAmbientParsToHeader`, `PutReflectionParsToHeader`, HS options).
pub fn make_header(app: &mut Mb3d, ui: &mut Ui) {
    let st = &app.post;
    let sc = &mut app.scene;
    sc.shadows = (ui.checked(F, "CheckBox9") || st.hs_now).then(|| shadow_params(ui));
    let tab = ui.c(F, "TabControl1").tab_index;
    let ao_on = ui.checked(F, "CheckBox11") || st.ao_now;
    sc.ao = ao_on.then(|| SsaoParams {
        threshold: ptf(&ui.text(F, "Edit34")).max(0.01) as f32,
        border_mirror: d2byte(&ui.text(F, "Edit9")) as f32 * 0.01,
        t0: ui.checked(F, "CheckBox12"),
        random: if tab == 2 { ui.position(F, "UpDown3").clamp(1, 9) as u8 } else { 0 },
        bits15: tab == 0,
        wrap_x: false,
    });
    sc.deao = (ao_on && tab == 3).then(|| crate::deao::DeaoParams {
        quality: ui.position(F, "UpDown1").clamp(0, 3) as u8,
        dither: ui.item_index(F, "RadioGroup5").clamp(0, 2) as u8,
        max_len: ptf(&ui.text(F, "Edit8")).clamp(1.0 / 255.0, 100.0) as f32,
        first_step_random: ui.checked(F, "CheckBox22"),
    });
    sc.normals_on_zbuf = ui.checked(F, "CheckBox23") || st.normals_now;
    sc.dof = (ui.checked(F, "CheckBox1") || st.dof_now).then(|| dof_params(ui));
    let m = &mut sc.mc;
    m.reflections = ui.checked(F, "CheckBox24") || st.refl_now;
    m.transparency = ui.checked(F, "CheckBox27");
    m.only_difs = ui.checked(F, "CheckBox28");
    m.reflection_amount = ptf(&ui.text(F, "Edit6")).clamp(0.0, 100.0) as f32;
    m.reflection_depth = if cfg!(feature = "se-desktop") {
        pti(&ui.text(F, "Edit11")).clamp(1, 30) as u8
    } else { ui.position(F, "UpDown2").clamp(1, 8) as u8 };
    let min_absorption = if cfg!(feature = "se-desktop") { 0.0 } else { 1e-30 };
    m.absorption = ptf(&ui.text(F, "Edit13")).clamp(min_absorption, 1e10) as f32;
    m.refraction_index = ptf(&ui.text(F, "Edit14")).clamp(0.1, 10.0) as f32;
    m.scattering = ptf(&ui.text(F, "Edit17")).max(0.0) as f32;
    if cfg!(feature = "se-desktop") {
        let enabled = ui.checked(F, "SeTranslucency");
        sc.translucency_enabled = enabled;
        sc.subsurface_scattering = ui.checked(F, "SeSubsurface");
        sc.subsurface_amount=ptf(&ui.text(F,"SeSubsurfaceAmountEdit")).clamp(0.0,1.0) as f32;
        sc.transmission_blur = if enabled { ptf(&ui.text(F, "SeTransStrengthEdit")).clamp(0.0, 2.0) as f32 } else { 0.0 };
        sc.translucency_glow = if enabled { ptf(&ui.text(F, "SeTransGlowEdit")).clamp(-1.0, 1.0) as f32 } else { 0.0 };
        if ao_on {
            sc.lighting.amb_shadow = ptf(&ui.text(F, "SeAmbientStrengthEdit")).clamp(0.0, 5.0) as f32 * 53.0;
        }
    }
    m.soft_shadow_radius = parse_float(&ui.text(F, "Edit7")).unwrap_or(1.0).clamp(0.01, 20.0) as f32;
}

/// The scene's post processing into the window (`SetEditsFromHeader`'s part).
pub fn set_from_header(app: &mut Mb3d, ui: &mut Ui) {
    app.post = State::default();
    let sc = app.scene.clone();
    ui.set_checked(F, "CheckBox1", sc.dof.is_some());
    let d = sc.dof.unwrap_or_default();
    ui.set_item_index(F, "RadioGroup2", d.forward as i32);
    ui.set_item_index(F, "RadioGroup1", (d.passes as i32 - 1).clamp(0, 2));
    ui.set_text(F, "Edit1", &fts_single(d.z_sharp as f64));
    ui.set_text(F, "Edit2", &fts_single(d.clip_r as f64));
    ui.set_text(F, "Edit3", &fts_single(d.aperture as f64));
    ui.set_text(F, "Edit10", &fts_single(d.z_sharp2 as f64));
    let h = sc.shadows.unwrap_or_default();
    ui.set_text(F, "Edit5", &fts_single(h.max_len_mul as f64));
    ui.set_checked(F, "CheckBox9", sc.shadows.is_some());
    ui.set_checked(F, "CheckBox10", h.set_cos);
    for i in 0..6 {
        ui.set_checked(F, &format!("CheckBox{}", i + 2), h.lights >> i & 1 != 0);
    }
    ui.set_checked(F, "CheckBox29", h.soft);
    let a = sc.ao.unwrap_or_default();
    ui.set_checked(F, "CheckBox11", sc.ao.is_some());
    ui.set_checked(F, "CheckBox12", a.t0);
    let tab = if sc.deao.is_some() {
        3
    } else if a.bits15 {
        0
    } else if a.random > 0 {
        2
    } else {
        1
    };
    ui.cm(F, "TabControl1").tab_index = tab;
    if let Some(de) = &sc.deao {
        ui.set_position(F, "UpDown1", de.quality as i64);
        ui.set_item_index(F, "RadioGroup5", de.dither as i32);
        ui.set_text(F, "Edit8", &fts_single(de.max_len as f64));
        ui.set_checked(F, "CheckBox22", de.first_step_random);
    }
    ui.set_position(F, "UpDown3", (a.random as i64).clamp(1, 9));
    ui.set_text(F, "Edit21", &(a.random as i64).clamp(1, 9).to_string());
    ui.set_text(F, "Edit34", &fts_single(a.threshold.abs() as f64));
    ui.set_text(F, "Edit9", &d2byte_str((a.border_mirror * 100.0).round().clamp(0.0, 250.0) as u8));
    radio_group3_click(ui);
    ui.set_checked(F, "CheckBox23", sc.normals_on_zbuf);
    let m = sc.mc;
    ui.set_checked(F, "CheckBox24", m.reflections);
    ui.set_text(F, "Edit6", &fts_single(m.reflection_amount as f64));
    let depth = m.reflection_depth.clamp(1, if cfg!(feature = "se-desktop") { 30 } else { 8 });
    ui.set_position(F, "UpDown2", i64::from(depth));
    ui.set_text(F, "Edit11", &depth.to_string());
    ui.set_text(F, "Edit13", &fts_single(m.absorption as f64));
    ui.set_text(F, "Edit14", &fts_single(m.refraction_index as f64));
    ui.set_text(F, "Edit17", &fts_single(m.scattering as f64));
    ui.set_checked(F, "CheckBox27", m.transparency);
    ui.set_checked(F, "CheckBox28", m.only_difs);
    ui.set_text(F, "Edit7", &fts_single(m.soft_shadow_radius as f64));
    if cfg!(feature = "se-desktop") {
        if sc.deao.is_none() {
            let defaults = crate::deao::DeaoParams::default();
            ui.set_text(F, "Edit8", &fts_single(defaults.max_len as f64));
            ui.set_position(F, "UpDown1", i64::from(defaults.quality));
        }
        let translucency = sc.translucency_enabled;
        ui.set_checked(F, "SeTranslucency", translucency);
        ui.set_checked(F, "SeSubsurface", sc.subsurface_scattering);
        ui.set_text(F,"SeSubsurfaceAmountEdit",&fts_single(sc.subsurface_amount as f64));
        ui.set_text(F, "SeTransStrengthEdit", &fts_single(if translucency { sc.transmission_blur as f64 } else { 1.0 }));
        ui.set_text(F, "SeTransGlowEdit", &fts_single(sc.translucency_glow as f64));
        ui.set_text(F, "SeAmbientStrengthEdit", &fts_single(sc.lighting.amb_shadow as f64 / 53.0));
        ui.set_item_index(F, "SeDofPasses", ui.item_index(F, "RadioGroup1"));
        radio_group3_click(ui);
        sync_se_sliders(ui);
        sync_se_transparency(ui, false);
    }
    check_box2(ui);
    update_captions(ui);
}

fn radio_group3_click(ui: &mut Ui) {
    let t = ui.c(F, "TabControl1").tab_index;
    let b = t < 3;
    if cfg!(feature = "se-desktop") {
        ui.set_item_index(F, "SeAmbientMethod", t);
        ui.set_item_index(F, "SeAmbientRays", ui.position(F, "UpDown1") as i32);
        for (name, visible) in [
            ("SeLabelEdit8", !b), ("SeAmbientLength", !b), ("SeAmbientRays", !b),
            ("SeAmbientRaysLabel", !b), ("SeLabelEdit34", b),
            ("SeLabelEdit21", t == 2), ("SeLabelEdit9", t == 1 || t == 2),
        ] {
            ui.set_visible(F, name, visible);
        }
    }
    for c in ["RadioGroup5", "CheckBox22", "Label15", "Label16", "Label17", "Edit8", "UpDown1"] {
        ui.set_visible(F, c, !b);
    }
    for c in ["CheckBox12", "Edit34", "Label50"] {
        ui.set_visible(F, c, b);
    }
    for c in ["UpDown3", "Edit21", "Label14"] {
        ui.set_visible(F, c, t == 2);
    }
    for c in ["Label20", "Edit9"] {
        ui.set_visible(F, c, t == 1 || t == 2);
    }
    let rays = [3, 7, 17, 33][ui.position(F, "UpDown1").clamp(0, 3) as usize];
    ui.set_caption(F, "Label17", &rays.to_string());
}

fn check_box2(ui: &mut Ui) {
    let n = (2..8).filter(|i| ui.checked(F, &format!("CheckBox{i}"))).count();
    for c in ["CheckBox29", "Edit7", "Label6"] {
        ui.set_enabled(F, c, n == 1);
    }
}

/// `UpdateButtonCaption`: a check mark glyph on the section buttons whose
/// processing runs automatically.
fn update_captions(ui: &mut Ui) {
    if cfg!(feature = "se-desktop") {
        update_se_tabs(ui, [false; 4]);
        return;
    }
    let img = ui.c(F, "ImageList1").images.first().cloned();
    for (btn, _, cb) in PANELS {
        let on = ui.checked(F, cb);
        let c = ui.cm(F, btn);
        c.glyph = if on { img.clone() } else { None };
        c.num_glyphs = 1;
        c.alignment = crate::vcl::canvas::HAlign::Left;
    }
}

fn update_se_tabs(ui: &mut Ui, applied: [bool; 4]) {
    for ((name, title, automatic), applied) in SE_PAGES.into_iter().zip(applied) {
        let mark = if applied || ui.checked(F, automatic) { "*" } else { "" };
        ui.set_caption(F, name, &format!("{title}{mark}"));
    }
}

pub(super) fn sync_se_tabs(app: &Mb3d, ui: &mut Ui) {
    if cfg!(feature = "se-desktop") {
        let applied = app.eng.base().map_or([false; 4], |base| {
            let scene = &base.scene;
            [scene.shadows.is_some(), scene.ao.is_some(), scene.mc.reflections, scene.dof.is_some()]
        });
        update_se_tabs(ui, applied);
        sync_se_transparency(ui, app.eng.has_transmission_cache());
    }
}

/// `AlignPanels`: the window's height follows the open sections.
fn align_panels(ui: &mut Ui) {
    let mut h = ui.c(F, "PostProcessHintPnl").height;
    for (btn, pnl, _) in PANELS {
        h += ui.c(F, btn).height;
        if ui.visible(F, pnl) {
            h += ui.c(F, pnl).height;
        }
    }
    let w = ui.f(F).client_size().0;
    ui.set_client_size(F, w, h);
}

fn toggle(ui: &mut Ui, btn: &str, pnl: &str) {
    let r = ui.c(F, btn).rect();
    let v = !ui.visible(F, pnl);
    let p = ui.cm(F, pnl);
    // just below its button in the alTop order
    p.top = r.bottom() - 1;
    p.visible = v;
    align_panels(ui);
    update_captions(ui);
}

/// The image is repainted with the post processing of the parameters;
/// `stage` is shown in the main window while it runs.
pub fn repaint(app: &mut Mb3d, ui: &mut Ui, stage: &'static str) {
    if app.main.calculating {
        app.message(ui, "Wait for the running calculation, or stop it first.");
        return;
    }
    if app.eng.base().is_none() {
        app.message(ui, "Calculate the image first.");
        return;
    }
    app.make_scene(ui);
    started(app, ui, stage);
    app.eng.start(super::engine::Job::Repaint { scene: app.scene.clone() });
}

/// The selection in the image (MB3D's `iRect` with `ClipIRect`'s checks),
/// in pixels of the image; None (and the message) without one.
fn preview_translucency(app:&mut Mb3d,ui:&mut Ui) {
    if app.main.calculating || !ui.checked(F,"CheckBox27") || !ui.checked(F,"SeTranslucency") { return; }
    let Some(strength)=parse_float(&ui.text(F,"SeTransStrengthEdit")).filter(|v|v.is_finite()) else{return};
    let Some(glow)=parse_float(&ui.text(F,"SeTransGlowEdit")).filter(|v|v.is_finite()) else{return};
    app.scene.transmission_blur=strength.clamp(0.,2.) as f32;
    app.scene.translucency_glow=glow.clamp(-1.,1.) as f32;
    app.scene.translucency_enabled=true;
    app.scene.subsurface_scattering=ui.checked(F,"SeSubsurface");
    let Some(base)=app.eng.base().filter(|_|app.eng.has_transmission_cache()) else {sync_se_transparency(ui,false);return};
    // Recompose the rendered scene, without rounding unrelated form values
    // or changing the automatic-calculation flags of a Calculate Now result.
    let mut scene=base.scene.clone();
    scene.transmission_blur=app.scene.transmission_blur;
    scene.translucency_glow=app.scene.translucency_glow;
    scene.subsurface_scattering=app.scene.subsurface_scattering;
    if app.eng.can_repaint_translucency(&scene) {
        app.eng.start(super::engine::Job::Repaint{scene});
        sync_se_transparency(ui,true);
    } else {sync_se_transparency(ui,false);}
}

fn preview_ambient_strength(app: &mut Mb3d, ui: &mut Ui) {
    if app.main.calculating {
        return;
    }
    let Some(value) = parse_float(&ui.text(F, "SeAmbientStrengthEdit")).filter(|v| v.is_finite()) else { return };
    let strength = value.clamp(0.0, 5.0) as f32 * 53.0;
    let Some(base) = app.eng.base().filter(|base| base.scene.ao.is_some() || base.scene.deao.is_some()) else { return };
    let mut scene = base.scene.clone();
    scene.lighting.amb_shadow = strength;
    app.scene.lighting.amb_shadow = strength;
    app.eng.start(super::engine::Job::Repaint { scene });
}

fn se_post_ready(app: &mut Mb3d, ui: &mut Ui) -> bool {
    if app.main.calculating {
        return false;
    }
    if app.eng.base().is_none() {
        app.message(ui, "Calculate the image first.");
        return false;
    }
    true
}

fn reset_se_effect(app: &mut Mb3d, ui: &mut Ui, effect: i64) {
    if app.main.calculating || app.eng.base().is_none() {
        return;
    }
    app.make_scene(ui);
    let mut scene = app.scene.clone();
    match effect {
        0 => { app.post.hs_now = false; scene.shadows = None; }
        1 => { app.post.ao_now = false; scene.ao = None; scene.deao = None; }
        2 => { app.post.refl_now = false; scene.mc.reflections = false; }
        3 => { app.post.dof_now = false; scene.dof = None; }
        _ => return,
    }
    started(app, ui, "post processing");
    app.eng.start(super::engine::Job::Repaint { scene });
}

fn selection_rect(app: &Mb3d, ui: &mut Ui) -> Option<[i32; 4]> {
    if !ui.visible(MAIN, "Shape1") {
        ui.show_message("Please make a selection in the image first.");
        return None;
    }
    let sh = ui.c(MAIN, "Shape1").rect();
    let img = ui.c(MAIN, "Image1").rect();
    let s = app.main.image_scale;
    let rect = [(sh.x - img.x) * s, (sh.y - img.y) * s, sh.w * s, sh.h * s];
    if rect[2] <= 2 || rect[3] <= 2 {
        ui.show_message("The selection must be bigger than 2 pixels in width and height.");
        return None;
    }
    Some(rect)
}

/// A processing of this window starts (MB3D's `DisableButtons` and
/// `Label6`): "Calculate 3D" turns into "Stop", the LED blinks and the stage
/// is shown until it is done.
fn started(app: &mut Mb3d, ui: &mut Ui, stage: &'static str) {
    super::main_form::disable_buttons(app, ui);
    app.main.calc3d = false;
    app.main.led_running = true;
    super::main_form::show_led(ui, app.main.led, true);
    ui.set_caption(MAIN, "Label6", stage);
    app.post.running = Some((stage, std::time::Instant::now()));
}

/// The processing finished (not stopped): a line in the status.
pub fn calc_finished(app: &mut Mb3d, ui: &mut Ui) {
    if let Some((stage, t)) = app.post.running.take() {
        let tenths = (t.elapsed().as_secs_f64() * 10.0).round().max(1.0) as i64;
        let mut s = stage.to_string();
        s[..1].make_ascii_uppercase();
        app.message(ui, &format!("{s} done ({}).", super::util::time_str(tenths)));
    }
}

pub fn event(app: &mut Mb3d, ui: &mut Ui, e: &Event) {
    let h = e.handler.as_str();
    for (btn, pnl, _) in PANELS {
        if h == format!("{btn}Click") {
            toggle(ui, btn, pnl);
            return;
        }
    }
    match h {
        "FormCreate" if cfg!(feature = "se-desktop") => configure_se(ui),
        "SeAmbientMethod" => {
            ui.cm(F, "TabControl1").tab_index = ui.item_index(F, "SeAmbientMethod");
            radio_group3_click(ui);
        }
        "SeAmbientRays" => ui.set_position(F, "UpDown1", i64::from(ui.item_index(F, "SeAmbientRays"))),
        "SeDofPasses" => ui.set_item_index(F, "RadioGroup1", ui.item_index(F, "SeDofPasses")),
        "SeSubsurface" | "SeSubsurfaceCommit" => {
            sync_se_transparency(ui,false);
            if se_post_ready(app,ui) {app.post.refl_now=true;repaint(app,ui,"subsurface scattering");}
        },
        "SeTransparency" => sync_se_transparency(ui, app.eng.has_transmission_cache()),
        "SePostSlider" => {
            if let Some((name, field, _, _, scale)) = SE_SLIDERS.iter().find(|(name, ..)| *name == e.sender) {
                let mut value = ui.position(F, name) as f64 / scale;
                if *name == "SeAmbientLength" { value = 10.0_f64.powf(value); }
                ui.set_text(F, field, &fts_single(value));
                if *name == "SeAmbientStrength" {
                    preview_ambient_strength(app, ui);
                }
                if matches!(*name, "SeTransStrength" | "SeTransGlow") { preview_translucency(app,ui); }
            }
        }
        "SePostValue" if matches!(e.ev, Ev::Exit | Ev::KeyDown { key: 13, .. }) => {
            sync_se_sliders(ui);
            if e.sender=="SeSubsurfaceAmountEdit" {
                if se_post_ready(app,ui){app.post.refl_now=true;repaint(app,ui,"subsurface scattering");}
            }
            if matches!(e.sender.as_str(),"SeTransStrengthEdit"|"SeTransGlowEdit") {
                preview_translucency(app,ui);
                return;
            }
            if e.sender == "SeAmbientStrengthEdit" {
                preview_ambient_strength(app, ui);
                return;
            }
            app.make_scene(ui);
            sync_se_transparency(ui, app.eng.can_repaint_translucency(&app.scene));
        }
        "SePostDepth" if matches!(e.ev, Ev::Exit | Ev::KeyDown { key: 13, .. }) => {
            let depth = pti(&ui.text(F, "Edit11")).clamp(1, 30);
            ui.set_position(F, "UpDown2", i64::from(depth));
            ui.set_text(F, "Edit11", &depth.to_string());
        }
        "SePostReset" => reset_se_effect(app, ui, ui.tag(F, &e.sender)),
        "NoiseFilterNowBtnClick" => super::main_form::denoise_picture(app, ui, noise_sigma(ui)),
        "NoiseAutoCbxClick" => update_captions(ui),
        "FormShow" => {
            super::main_form::place_sticky(app, ui, Some(F), true);
            ui.cm(F, "Edit11").hint = "Depth of reflections: 1 to see only one reflection,\nwith 2 you could see reflections in the reflected object, ... and so on.".into();
            ui.cm(F, "Edit12").hint = "Divides the actual \"Raystep multiplier\" by this value,\nincrease the value to reduce overstepping.".into();
            if cfg!(feature = "se-desktop") {
                sync_se_tabs(app, ui);
            } else {
                align_panels(ui);
                update_captions(ui);
            }
        }
        "FormHide" => {
            let f = ui.f(F);
            let s = format!("{} {}", f.left, f.top);
            app.ini.set("PostpPos", &s);
        }
        "CheckBox9Click" | "CheckBox11Click" | "CheckBox24Click" | "CheckBox1Click"
            if cfg!(feature = "se-desktop") =>
        {
            let page = SE_PAGES.iter().position(|(_, _, automatic)| *automatic == e.sender).unwrap();
            if !ui.checked(F, &e.sender) && app.eng.base().is_some() && !app.main.calculating {
                reset_se_effect(app, ui, page as i64);
            }
            sync_se_tabs(app, ui);
        }
        "CheckBox23Click" | "CheckBox9Click" | "CheckBox11Click" | "CheckBox24Click" | "CheckBox1Click" => update_captions(ui),
        "CheckBox2Click" => check_box2(ui),
        "RadioGroup3Click" => radio_group3_click(ui),
        "UpDown1ChangingEx" => radio_group3_click(ui),
        "Button14Click" => {
            app.post.normals_now = true;
            repaint(app, ui, "Normals on ZBuf");
        }
        "Button3Click" => {
            if cfg!(feature = "se-desktop") && !se_post_ready(app, ui) { return; }
            if shadow_params(ui).lights == 0 {
                ui.show_message("Please select the lights first.  No HS for lightmaps.");
                return;
            }
            app.post.hs_now = true;
            repaint(app, ui, "hard shadow calculation");
        }
        "Button4Click" => {
            // reset the hard shadow of a light
            let t = ui.tag(F, &e.sender) as usize;
            ui.set_checked(F, &format!("CheckBox{}", t + 1), false);
            if shadow_params(ui).lights == 0 {
                app.post.hs_now = false;
            }
            repaint(app, ui, "hard shadow calculation");
        }
        "Button10Click" => {
            if cfg!(feature = "se-desktop") && !se_post_ready(app, ui) { return; }
            app.post.ao_now = true;
            repaint(app, ui, "ambient shadow calculation");
        }
        "Button11Click" => {
            if cfg!(feature = "se-desktop") && !se_post_ready(app, ui) { return; }
            if ui.checked(F, "CheckBox25") {
                // "Calculate only a selection in the image": the reflections
                // of the selection only (MB3D's CalcSRT with the selection)
                if app.main.calculating {
                    app.message(ui, "Wait for the running calculation, or stop it first.");
                    return;
                }
                if app.eng.base().is_none() {
                    app.message(ui, "Calculate the image first.");
                    return;
                }
                let Some(rect) = selection_rect(app, ui) else { return };
                app.make_scene(ui);
                started(app, ui, "reflections of the selection");
                app.eng.start(super::engine::Job::ReflectSel { scene: app.scene.clone(), rect });
                return;
            }
            app.post.refl_now = true;
            repaint(app, ui, "Reflections");
        }
        "Button1Click" => {
            if cfg!(feature = "se-desktop") && !se_post_ready(app, ui) { return; }
            if app.scene.tiling.is_some() {
                ui.show_message("No DoF on tiles.");
                return;
            }
            app.post.dof_now = true;
            repaint(app, ui, "DoF calculation");
        }
        "Button2Click" => {
            let tg = ui.tag(F, &e.sender) as i32;
            if cfg!(feature = "se-desktop") && !se_post_ready(app, ui) { return; }
            if ui.caption(F, &e.sender) == "Click on image" {
                ui.set_caption(F, &e.sender, if tg == 1 { "Get Z1" } else { "Get Z2" });
                app.main.get_pos = 0;
                ui.cm(MAIN, "Image1").cursor = "crDefault".into();
            } else {
                if cfg!(feature = "se-desktop") {
                    ui.set_caption(F, if tg == 1 { "Button18" } else { "Button2" },
                        if tg == 1 { "Get Z2" } else { "Get Z1" });
                }
                app.main.get_pos = tg;
                ui.set_caption(F, &e.sender, "Click on image");
                ui.cm(MAIN, "Image1").cursor = "crCross".into();
            }
        }
        "Button19Click" => {
            let t = ui.text(F, "Edit1");
            ui.set_text(F, "Edit10", &t);
            sync_se_sliders(ui);
        }
        "Button16Click" => {
            // "Reset now": the processings applied by hand are dropped
            app.post = State::default();
            repaint(app, ui, "post processing");
        }
        "CheckBox21Click" | "CheckBox25Click" => {
            update_captions(ui);
            let on = ui.checked(F, &e.sender);
            ui.set_enabled(F, "Button13", ui.checked(F, "CheckBox21"));
            if on {
                for b in ["SpeedButton1", "SpeedButton2", "SpeedButton4"] {
                    ui.cm(MAIN, b).down = false;
                }
                ui.cm(MAIN, "Image1").cursor = "crCross".into();
            } else {
                ui.set_visible(MAIN, "Shape1", false);
                ui.cm(MAIN, "Image1").cursor = "crDefault".into();
            }
        }
        "Button13Click" => {
            let Some(rect) = selection_rect(app, ui) else { return };
            app.make_scene(ui);
            let div = pti(&ui.text(F, "Edit12")).max(1) as f64;
            let nearer = ui.checked(F, "CheckBox19");
            // MB3D's CalcPartT(iRect, CheckBox9, CheckBox19, CheckBox11 and
            // the DEAO tab, CheckBox30, ...)
            let hs = ui.checked(F, "CheckBox9");
            let deao = ui.checked(F, "CheckBox11") && ui.c(F, "TabControl1").tab_index == 3;
            let keep_as = ui.checked(F, "CheckBox30");
            started(app, ui, "selection recalculation");
            ui.set_visible(MAIN, "ProgressBar1", true);
            app.eng.start(super::engine::Job::Recalc { scene: app.scene.clone(), rect, div, nearer, hs, deao, keep_as });
        }
        "Button12Click" => {
            // DoubleImageSize: the kept G-buffer interpolated to twice the size
            if app.main.calculating {
                return;
            }
            let Some(b) = app.eng.base() else { return ui.show_message("No image calculated yet.") };
            let g = crate::gbuffer::double_size(&b.post, b.w, b.h);
            let mut sc = b.scene.clone();
            sc.width *= 2;
            sc.height *= 2;
            sc.de_stop *= 2.0;
            app.make_scene(ui);
            let light = app.scene.lighting.clone();
            sc.lighting = light;
            match app.eng.set_gbuffer(&sc, g) {
                Ok(()) => {
                    app.scene.width = sc.width;
                    app.scene.height = sc.height;
                    app.scene.de_stop = sc.de_stop;
                    let s = match app.main.image_scale {
                        1 => 2,
                        2 => 4,
                        s => s,
                    };
                    super::main_form::set_edits_from_header(app, ui);
                    super::main_form::update_scale(app, ui, s);
                    super::main_form::show_image(app, ui);
                }
                Err(e) => ui.show_message(&e),
            }
        }
        "FormMouseWheel" => {}
        _ => {}
    }
}
