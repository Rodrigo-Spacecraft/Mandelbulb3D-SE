//! Color adjustment and the shared SE color picker.
use super::super::{light_form, light_se};
use super::*;
use crate::vcl::control::Control;
use crate::vcl::form::{Form, SS_CTRL, SS_LEFT, SS_SUPER};

pub(crate) const PICKER: &str = "SeColorPicker";
const MAX_POSITION: u16 = 32767;

#[derive(Clone, Copy)]
struct Swatch {
    rgb: [u8; 3],
    opacity: f32,
}

#[derive(Clone, Copy)]
struct Stop {
    position: u16,
    colors: [Swatch; 2],
    specular_alpha: u8,
}

enum Target {
    Stop {
        outside: bool,
        index: usize,
        channel: usize,
    },
    Reference(usize),
    Light(String),
}

#[derive(Default)]
pub struct SeState {
    copy: Option<[Swatch; 2]>,
    drag: bool,
    dragged: bool,
    drag_limit: u16,
    picker: Option<Target>,
    rgb: [u8; 3],
    hue: f32,
    saturation: f32,
    brightness: f32,
    opacity: f32,
    eye_armed: bool,
    eye_active: bool,
}

fn control(
    form: &mut Form,
    name: &str,
    class: &str,
    title: &str,
    bounds: (i32, i32, i32, i32),
) -> usize {
    let mut c = Control::new(name, class);
    c.caption = title.into();
    c.set_bounds(bounds.0, bounds.1, bounds.2, bounds.3);
    form.add_control(0, c)
}

fn label(form: &mut Form, name: &str, title: &str, x: i32, y: i32, width: i32) {
    control(form, name, "TLabel", title, (x, y, width, 18));
}

fn button(form: &mut Form, name: &str, title: &str, bounds: (i32, i32, i32, i32)) -> usize {
    let id = control(form, name, "TButton", title, bounds);
    form.ctl[id].events.insert("OnClick".into(), name.into());
    id
}

fn swatch_button(form: &mut Form, name: &str, bounds: (i32, i32, i32, i32)) -> usize {
    let id = control(form, name, "TSpeedButton", "", bounds);
    form.ctl[id].events.insert("OnClick".into(), name.into());
    id
}

fn menu(form: &mut Form, name: &str, items: &[&str], bounds: (i32, i32, i32, i32)) {
    let id = control(form, name, "TComboBox", "", bounds);
    let c = &mut form.ctl[id];
    c.style = "csDropDownList".into();
    c.items = items.iter().map(|s| s.to_string()).collect();
    c.set_item_index(0);
    c.events.insert("OnChange".into(), name.into());
}

fn edit(form: &mut Form, name: &str, bounds: (i32, i32, i32, i32)) {
    let id = control(form, name, "TEdit", "", bounds);
    form.ctl[id].events.insert("OnExit".into(), name.into());
    form.ctl[id].events.insert("OnKeyDown".into(), name.into());
}

fn slider(form: &mut Form, name: &str, max: i64, bounds: (i32, i32, i32, i32)) {
    let id = control(form, name, "TTrackBar", "", bounds);
    let c = &mut form.ctl[id];
    c.max = max;
    c.fine_track_drag = true;
    c.events.insert("OnChange".into(), name.into());
}

pub(super) fn configure(ui: &mut Ui) {
    ui.set_client_size(F, 780, 493);
    let form = ui.fm(F);
    form.stay_on_top = false;
    for id in form.ctl[0].children.clone() {
        form.ctl[id].visible = false;
    }
    label(form, "SeModeLabel", "Object colors", 16, 13, 100);
    menu(
        form,
        "SePaletteMode",
        &["Outside", "Inside"],
        (126, 7, 140, 26),
    );
    for (row, title) in ["Diffuse", "Specular"].into_iter().enumerate() {
        let y = 54 + row as i32 * 88;
        label(form, &format!("SePaletteLabel{row}"), title, 16, y, 120);
        let id = control(
            form,
            &format!("SePaletteBar{row}"),
            "TImage",
            "",
            (16, y + 23, 748, 60),
        );
        let c = &mut form.ctl[id];
        c.tag = row as i64;
        for (event, handler) in [
            ("OnMouseDown", "SeBarDown"),
            ("OnMouseMove", "SeBarMove"),
            ("OnMouseUp", "SeBarUp"),
            ("OnDblClick", "SeBarDouble"),
        ] {
            c.events.insert(event.into(), handler.into());
        }
    }
    for (index, (title, x)) in [
        ("Stop", 16),
        ("Position (0–32767)", 150),
        ("Diffuse color", 390),
        ("Specular color", 580),
    ]
    .into_iter()
    .enumerate()
    {
        label(
            form,
            &format!("SePaletteFieldLabel{index}"),
            title,
            x,
            235,
            180,
        );
    }
    menu(form, "SePaletteStop", &["Stop 1"], (16, 258, 115, 27));
    edit(form, "SePalettePosition", (150, 258, 190, 27));
    swatch_button(form, "SeDiffuseWell", (390, 258, 170, 27));
    swatch_button(form, "SeSpecularWell", (580, 258, 184, 27));
    control(
        form,
        "SeGlue",
        "TCheckBox",
        "Glue sliders",
        (16, 304, 180, 24),
    );
    for (row, title) in ["Random diffuse", "Random specular"]
        .into_iter()
        .enumerate()
    {
        let y = 348 + row as i32 * 38;
        let id = button(form, &format!("SeRandom{row}"), title, (16, y, 180, 28));
        form.ctl[id].tag = row as i64;
        label(
            form,
            &format!("SeReferenceLabel{row}"),
            "Reference color",
            220,
            y + 6,
            104,
        );
        swatch_button(form, &format!("SeReference{row}"), (332, y, 95, 28));
        label(
            form,
            &format!("SeAmountLabel{row}"),
            "Multiplier (0–3)",
            442,
            y + 6,
            119,
        );
        slider(
            form,
            &format!("SeRandomSlider{row}"),
            300,
            (566, y, 130, 26),
        );
        form.c_mut(&format!("SeRandomSlider{row}")).position = 100;
        edit(form, &format!("SeRandomAmount{row}"), (706, y, 58, 26));
        form.c_mut(&format!("SeRandomAmount{row}")).text = "1".into();
    }
    label(
        form,
        "SePaletteStatus",
        "Drag a marker to move it. Double-click to pick a color. Right-click for Copy and Paste.",
        16,
        448,
        550,
    );
    button(form, "SeUpdatePalette", "Update Image", (580, 440, 184, 32));

    let popup = control(form, "SeStopMenu", "TPopupMenu", "", (0, 0, 0, 0));
    for (cmd, title) in ["Copy stop", "Paste stop", "Paste diffuse", "Paste specular"]
        .into_iter()
        .enumerate()
    {
        let mut item = Control::new(&format!("SeStopCommand{cmd}"), "TMenuItem");
        item.caption = title.into();
        item.tag = cmd as i64;
        item.events.insert("OnClick".into(), "SeStopCommand".into());
        form.add_control(popup, item);
    }
}

fn configure_picker(ui: &mut Ui) {
    let form = ui.fm(PICKER);
    let wheel = control(form, "Wheel", "TImage", "", (16, 14, 224, 224));
    for (event, handler) in [("OnMouseDown", "PickWheel"), ("OnMouseMove", "PickWheel")] {
        form.ctl[wheel].events.insert(event.into(), handler.into());
    }
    label(form, "ColorLabel", "Selected color", 256, 20, 128);
    control(form, "Swatch", "TImage", "", (256, 43, 143, 34));
    label(form, "HexLabel", "Hex RGB", 256, 92, 126);
    edit(form, "HexValue", (256, 112, 143, 26));
    label(form, "BrightnessLabel", "Brightness", 256, 151, 140);
    slider(form, "Brightness", 1000, (252, 172, 150, 24));
    label(form, "OpacityLabel", "Opacity", 256, 204, 140);
    slider(form, "Opacity", 1000, (252, 225, 150, 24));
    let colors = [
        0x000000, 0x404040, 0x808080, 0xFFFFFF, 0xFF0000, 0xFF8000, 0xFFFF00, 0x804020, 0x008000,
        0x80FF00, 0x00FFFF, 0x008080, 0x0000FF, 0x8000FF, 0xFF00FF, 0xFF80B0,
    ];
    for (i, color) in colors.into_iter().enumerate() {
        let id = swatch_button(
            form,
            &format!("Common{i}"),
            (16 + i as i32 * 24, 263, 22, 22),
        );
        let c = &mut form.ctl[id];
        c.tag = color;
        c.hint = format!("#{color:06X}");
        c.glyph = Some(swatch_bitmap(
            Swatch {
                rgb: rgb_of(color as u32),
                opacity: 1.0,
            },
            14,
            14,
            false,
        ));
        c.events.insert("OnClick".into(), "PickCommon".into());
    }
    label(form, "PickerStatus", "", 16, 297, 380);
    button(form, "Eyedropper", "Eyedropper", (16, 324, 105, 28));
    let cancel = button(form, "PickCancel", "Close", (318, 324, 81, 28));
    form.ctl[cancel].cancel = true;
    let timer = control(form, "PickTimer", "TTimer", "", (0, 0, 0, 0));
    form.ctl[timer].enabled = false;
    form.ctl[timer].interval = 20;
    form.ctl[timer]
        .events
        .insert("OnTimer".into(), "PickScreen".into());
}

pub(crate) fn add_picker(ui: &mut Ui) -> Result<(), String> {
    ui.add_form(
        r#"
object SeColorPicker: TForm
  Caption = 'Colors'
  BorderStyle = bsDialog
  ClientWidth = 415
  ClientHeight = 367
  Position = poScreenCenter
  OnHide = PickHide
end
"#,
    )?;
    configure_picker(ui);
    Ok(())
}

fn stops(app: &Mb3d, out: bool) -> Vec<Stop> {
    let l = &app.scene.lighting;
    (0..if out { 10 } else { 4 })
        .map(|i| {
            if out {
                let p = l.palette[i];
                let a = l.palette_alpha(i);
                Stop {
                    position: p.position,
                    colors: [
                        Swatch {
                            rgb: p.diffuse,
                            opacity: app.scene.emissive_opacity[i],
                        },
                        Swatch {
                            rgb: p.specular,
                            opacity: 1.0 - f32::from(a >> 3) / 31.0,
                        },
                    ],
                    specular_alpha: a,
                }
            } else {
                let p = l.interior[i];
                Stop {
                    position: p.0,
                    colors: [
                        Swatch {
                            rgb: p.1,
                            opacity: 1.0,
                        },
                        Swatch {
                            rgb: [l.interior_spec[i]; 3],
                            opacity: 1.0,
                        },
                    ],
                    specular_alpha: l.interior_spec[i],
                }
            }
        })
        .collect()
}

fn selected(ui: &Ui) -> usize {
    ui.item_index(F, "SePaletteStop").max(0) as usize
}

fn blend(a: Swatch, b: Swatch, t: f32) -> Swatch {
    let mix = |a: f32, b: f32| a + (b - a) * t;
    Swatch {
        rgb: std::array::from_fn(|i| mix(f32::from(a.rgb[i]), f32::from(b.rgb[i])).round() as u8),
        opacity: mix(a.opacity, b.opacity),
    }
}

fn opacity_pixel(s: Swatch, x: usize, y: usize) -> u32 {
    let gray = if (x / 4 + y / 4) % 2 == 0 { 238 } else { 153 };
    argb(
        blend(
            Swatch {
                rgb: [gray; 3],
                opacity: 1.0,
            },
            s,
            s.opacity,
        )
        .rgb,
    )
}

fn swatch_bitmap(s: Swatch, w: usize, h: usize, strip: bool) -> Bitmap {
    let mut bitmap = Bitmap::new(w, h, argb(s.rgb));
    // VCL treats the bottom-left pixel as the glyph transparency key.
    bitmap.px[(h - 1) * w] = if s.rgb == [255, 0, 255] {
        0xFF00_FF00
    } else {
        0xFFFF_00FF
    };
    if strip {
        for y in 0..4.min(h) {
            for x in 0..w {
                bitmap.px[y * w + x] = opacity_pixel(s, x, y);
            }
        }
    }
    bitmap
}

fn palette_bar(
    stops: &[Stop],
    channel: usize,
    index: usize,
    width: usize,
    height: usize,
    limit: u16,
    interpolate: bool,
) -> Bitmap {
    let mut bitmap = Bitmap::new(width, height, 0xFFF0_F0F0);
    for x in 0..width {
        let position = x as f32 * f32::from(limit) / (width - 1) as f32;
        let upper = stops.partition_point(|stop| f32::from(stop.position) <= position);
        let left = upper.saturating_sub(1);
        let right = upper.min(stops.len() - 1);
        let t = if interpolate && right != left {
            ((position - f32::from(stops[left].position))
                / f32::from(
                    stops[right]
                        .position
                        .saturating_sub(stops[left].position)
                        .max(1),
                ))
            .clamp(0.0, 1.0)
        } else {
            0.0
        };
        let color = blend(stops[left].colors[channel], stops[right].colors[channel], t);
        for y in 0..height - 13 {
            bitmap.px[y * width + x] = if y < 7 {
                gray((color.opacity * 255.0).round() as u8)
            } else {
                argb(color.rgb)
            };
        }
    }
    // Paint the selected marker last when two stops meet at the same position.
    for i in (0..stops.len())
        .filter(|&i| i != index)
        .chain(std::iter::once(index))
    {
        let x = marker_x(stops[i].position, limit, width as i32);
        for y in 0..11 {
            let half = (y + 1).min(5);
            for dx in -half..=half {
                let px = x + dx;
                if (0..width as i32).contains(&px) {
                    bitmap.px[(height - 12 + y as usize) * width + px as usize] =
                        if i == index { 0xFF18_62C1 } else { 0xFF44_4444 };
                }
            }
        }
    }
    bitmap
}

fn marker_x(position: u16, limit: u16, width: i32) -> i32 {
    (f32::from(position) * (width - 1) as f32 / f32::from(limit)).round() as i32
}

fn limit(stops: &[Stop]) -> u16 {
    stops
        .iter()
        .map(|s| s.position)
        .max()
        .unwrap_or(0)
        .max(MAX_POSITION)
}

fn refresh(app: &Mb3d, ui: &mut Ui) {
    let out = outside(ui);
    let stops = stops(app, out);
    let i = selected(ui).min(stops.len() - 1);
    ui.set_item_index(F, "SePaletteMode", i32::from(!out));
    if ui.c(F, "SePaletteStop").items.len() != stops.len() {
        ui.set_items(
            F,
            "SePaletteStop",
            (1..=stops.len()).map(|i| format!("Stop {i}")).collect(),
        );
    }
    ui.set_item_index(F, "SePaletteStop", i as i32);
    ui.set_text(F, "SePalettePosition", &stops[i].position.to_string());
    for (channel, well) in ["SeDiffuseWell", "SeSpecularWell"].into_iter().enumerate() {
        let name = format!("SePaletteBar{channel}");
        let c = ui.c(F, &name);
        let image = palette_bar(
            &stops,
            channel,
            i,
            c.width as usize,
            c.height as usize,
            limit(&stops),
            !app.scene.lighting.no_col_ipol,
        );
        ui.set_picture(F, &name, Some(image));
        let c = ui.cm(F, well);
        c.glyph = Some(swatch_bitmap(
            stops[i].colors[channel],
            c.width as usize - 16,
            17,
            out,
        ));
        c.num_glyphs = 1;
        let c = ui.cm(F, &format!("SeReference{channel}"));
        let s = Swatch {
            rgb: rgb_of(app.palette.rand_mid[channel]),
            opacity: 1.0,
        };
        c.glyph = Some(swatch_bitmap(s, 78, 17, false));
        c.num_glyphs = 1;
    }
}

pub(crate) fn open(app: &Mb3d, ui: &mut Ui, inside: bool) {
    ui.set_item_index(F, "RadioGroup1", i32::from(inside));
    ui.set_item_index(F, "SePaletteStop", 0);
    refresh(app, ui);
    ui.show(F);
}

fn commit(app: &mut Mb3d, ui: &mut Ui, out: bool, stops: &[Stop]) {
    let l = &mut app.scene.lighting;
    for (i, stop) in stops.iter().enumerate() {
        if out {
            l.palette[i] = crate::lighting::PaletteColor {
                position: stop.position,
                diffuse: stop.colors[0].rgb,
                specular: stop.colors[1].rgb,
            };
            app.scene.emissive_opacity[i] = stop.colors[0].opacity;
        } else {
            l.interior[i] = (stop.position, stop.colors[0].rgb);
            l.interior_spec[i] = stop.specular_alpha;
        }
    }
    if out {
        l.palette_alpha = Some(std::array::from_fn(|i| stops[i].specular_alpha));
    }
    refresh(app, ui);
    light_se::refresh_palettes(ui, &app.scene);
    light_se::opacity_text(ui, &app.scene);
}

fn move_stop(app: &mut Mb3d, ui: &mut Ui, mut i: usize, position: u16) {
    let out = outside(ui);
    let mut stops = stops(app, out);
    let bound = limit(&stops).max(position);
    let old = stops[i].position;
    if old == position {
        return;
    }
    if ui.checked(F, "SeGlue") {
        for (j, entry) in stops.iter_mut().enumerate() {
            let p = f64::from(entry.position);
            let (p0, p1, cap) = (f64::from(old), f64::from(position), f64::from(bound));
            entry.position = if j < i && old != 0 {
                (p * p1 / p0).round() as u16
            } else if j > i && old < bound {
                (cap - (cap - p) * (cap - p1) / (cap - p0)).round() as u16
            } else {
                entry.position
            };
        }
    }
    stops[i].position = position;
    while i > 0 && stops[i].position < stops[i - 1].position {
        retarget_swapped_stops(app, out, i, i - 1);
        stops.swap(i, i - 1);
        i -= 1;
    }
    while i + 1 < stops.len() && stops[i].position > stops[i + 1].position {
        retarget_swapped_stops(app, out, i, i + 1);
        stops.swap(i, i + 1);
        i += 1;
    }
    ui.set_item_index(F, "SePaletteStop", i as i32);
    commit(app, ui, out, &stops);
}

fn retarget_swapped_stops(app: &mut Mb3d, out: bool, a: usize, b: usize) {
    if let Some(Target::Stop { outside, index, .. }) = &mut app.palette.se.picker {
        if *outside == out {
            if *index == a {
                *index = b;
            } else if *index == b {
                *index = a;
            }
        }
    }
}

fn set_color(stop: &mut Stop, out: bool, channel: usize, mut color: Swatch) {
    if !out && channel == 1 {
        let gray = (color.rgb.iter().map(|&v| u16::from(v)).sum::<u16>() / 3) as u8;
        color.rgb = [gray; 3];
        stop.specular_alpha = gray;
    } else if out && channel == 1 {
        let tr = ((1.0 - color.opacity) * 31.0).round() as u8;
        if color.opacity != stop.colors[1].opacity {
            stop.specular_alpha = (tr << 3) | (stop.specular_alpha & 7);
        }
    }
    stop.colors[channel] = color;
}

fn stop_command(app: &mut Mb3d, ui: &mut Ui, cmd: i64) {
    let out = outside(ui);
    let mut stops = stops(app, out);
    let i = selected(ui);
    if cmd == 0 {
        app.palette.se.copy = Some(stops[i].colors);
    } else if let Some(colors) = app.palette.se.copy {
        for (channel, color) in colors.into_iter().enumerate() {
            if cmd == 1 || cmd == channel as i64 + 2 {
                set_color(&mut stops[i], out, channel, color);
            }
        }
        commit(app, ui, out, &stops);
        light_form::trigger_repaint(app, ui);
    }
}

fn parse_edit(e: &Event) -> bool {
    matches!(e.ev, Ev::Exit | Ev::KeyDown { key: 13, .. })
}

pub(super) fn event(app: &mut Mb3d, ui: &mut Ui, e: &Event) {
    let h = e.handler.as_str();
    if h == "FormShow" {
        light_form::put_light_in_header(app, ui);
        refresh(app, ui);
        return;
    }
    if h == "FormHide" {
        app.palette.se.drag = false;
        return;
    }
    if app.main.calculating {
        return;
    }
    match h {
        "SePaletteMode" => {
            ui.set_item_index(F, "RadioGroup1", ui.item_index(F, "SePaletteMode"));
            ui.set_item_index(F, "SePaletteStop", 0);
            refresh(app, ui);
        }
        "SePaletteStop" => refresh(app, ui),
        "SePalettePosition" if parse_edit(e) => {
            if let Ok(p) = ui.text(F, "SePalettePosition").trim().parse::<u16>() {
                let p = if outside(ui) { p } else { p.min(MAX_POSITION) };
                move_stop(app, ui, selected(ui), p);
                light_form::trigger_repaint(app, ui);
            }
            refresh(app, ui);
        }
        "SeBarDown" => {
            if let Ev::MouseDown { button, x, y, .. } = e.ev {
                let stops = stops(app, outside(ui));
                let width = ui.c(F, &e.sender).width;
                let bound = limit(&stops);
                let current = selected(ui);
                let i = (0..stops.len())
                    .min_by_key(|&i| {
                        (
                            (marker_x(stops[i].position, bound, width) - x).abs(),
                            i != current,
                        )
                    })
                    .unwrap();
                ui.set_item_index(F, "SePaletteStop", i as i32);
                refresh(app, ui);
                if button == MouseButton::Left {
                    app.palette.se.drag = true;
                    app.palette.se.dragged = false;
                    app.palette.se.drag_limit = bound;
                } else if button == MouseButton::Right {
                    for i in 1..4 {
                        ui.set_enabled(
                            F,
                            &format!("SeStopCommand{i}"),
                            app.palette.se.copy.is_some(),
                        );
                    }
                    ui.popup_menu(F, "SeStopMenu", &e.sender, x, y);
                }
            }
        }
        "SeBarMove" => {
            if let Ev::MouseMove { x, shift, .. } = e.ev {
                if app.palette.se.drag && shift & SS_LEFT != 0 {
                    let width = ui.c(F, &e.sender).width;
                    let bound = app.palette.se.drag_limit;
                    let p = (f64::from(x.clamp(0, width - 1)) * f64::from(bound)
                        / f64::from(width - 1))
                    .round() as u16;
                    move_stop(app, ui, selected(ui), p);
                    app.palette.se.dragged = true;
                    light_form::trigger_repaint(app, ui);
                }
            }
        }
        "SeBarUp" => {
            app.palette.se.drag = false;
            if std::mem::take(&mut app.palette.se.dragged) {
                light_form::trigger_repaint(app, ui);
            } else if matches!(e.ev,Ev::MouseUp{button:MouseButton::Left,..}) {
                let channel=ui.tag(F,&e.sender) as usize;
                let out=outside(ui);let index=selected(ui);
                open_picker(app,ui,Target::Stop{outside:out,index,channel},stops(app,out)[index].colors[channel],out);
            }
        }
        "SeBarDouble" | "SeDiffuseWell" | "SeSpecularWell" => {
            app.palette.se.drag = false;
            let channel = if h == "SeBarDouble" {
                ui.tag(F, &e.sender) as usize
            } else {
                usize::from(h == "SeSpecularWell")
            };
            let out = outside(ui);
            let i = selected(ui);
            open_picker(
                app,
                ui,
                Target::Stop {
                    outside: out,
                    index: i,
                    channel,
                },
                stops(app, out)[i].colors[channel],
                out,
            );
        }
        "SeReference0" | "SeReference1" => {
            let i = usize::from(h == "SeReference1");
            let s = Swatch {
                rgb: rgb_of(app.palette.rand_mid[i]),
                opacity: 1.0,
            };
            open_picker(app, ui, Target::Reference(i), s, false);
        }
        "SeRandomSlider0" | "SeRandomSlider1" => {
            let i = usize::from(h.ends_with('1'));
            ui.set_text(
                F,
                &format!("SeRandomAmount{i}"),
                &(ui.position(F, h) as f64 / 100.0).to_string(),
            );
        }
        "SeRandomAmount0" | "SeRandomAmount1" if parse_edit(e) => {
            let i = usize::from(h.ends_with('1'));
            if let Some(v) =
                super::super::util::parse_float(&ui.text(F, h)).filter(|v| v.is_finite())
            {
                ui.set_position(F, &format!("SeRandomSlider{i}"), (v * 100.0).round() as i64);
            }
        }
        "SeRandom0" | "SeRandom1" => randomize(app, ui, usize::from(h.ends_with('1'))),
        "SeStopCommand" => stop_command(app, ui, ui.tag(F, &e.sender)),
        "FormKeyDown" => {
            if let Ev::KeyDown { key, shift } = e.ev {
                if shift & (SS_CTRL | SS_SUPER) != 0
                    && ui
                        .focused(F)
                        .as_deref()
                        .is_none_or(|name| ui.c(F, name).kind != crate::vcl::control::Kind::Edit)
                {
                    if let Some(cmd) = match key {
                        67 => Some(0),
                        86 => Some(1),
                        71 => Some(2),
                        66 => Some(3),
                        _ => None,
                    } {
                        stop_command(app, ui, cmd);
                    }
                }
            }
        }
        "SeUpdatePalette" => light_form::trigger_repaint(app, ui),
        _ => {}
    }
}

fn randomize(app: &mut Mb3d, ui: &mut Ui, channel: usize) {
    let name = format!("SeRandomAmount{channel}");
    let Some(amount) =
        super::super::util::parse_float(&ui.text(F, &name)).filter(|v| (0.0..=3.0).contains(v))
    else {
        ui.set_caption(
            F,
            "SePaletteStatus",
            "Enter a random multiplier from 0 to 3.",
        );
        return;
    };
    let amount = amount as f32;
    let out = outside(ui);
    let reference = rgb_of(app.palette.rand_mid[channel]).map(|v| f32::from(v) / 255.0);
    let mut rng = crate::mutagen::Rng::from_time();
    let mut colors = stops(app, out);
    for stop in &mut colors {
        let r = ((rng.f64() * std::f64::consts::TAU).cos() * 0.5 + 0.5) as f32;
        let weight = (amount.max(1.0) - rng.f64() as f32 * amount)
            .clamp(0.0, 1.0)
            .sqrt();
        let rgb = std::array::from_fn(|j| {
            let mid = reference[j];
            let x = if !out {
                mid + (rng.f64() as f32 - 0.5) * amount
            } else if channel == 1 {
                (mid + (0.5 - r) * amount) * weight
                    + f32::from(stop.colors[0].rgb[j]) / 255.0 * (1.0 - weight)
            } else {
                mid + (rng.f64().powf(f64::from(mid.clamp(0.05, 0.95).log(0.5))) as f32 - mid)
                    * amount
            };
            (x.clamp(0.0, 1.0) * 255.0).round() as u8
        });
        set_color(
            stop,
            out,
            channel,
            Swatch {
                rgb,
                ..stop.colors[channel]
            },
        );
    }
    commit(app, ui, out, &colors);
    light_form::trigger_repaint(app, ui);
}

pub(crate) fn open_light_picker(app: &mut Mb3d, ui: &mut Ui, command: String, rgb: [u8; 3]) {
    open_picker(
        app,
        ui,
        Target::Light(command),
        Swatch { rgb, opacity: 1.0 },
        false,
    );
}

fn open_picker(app: &mut Mb3d, ui: &mut Ui, target: Target, color: Swatch, opacity: bool) {
    stop_eyedropper(app, ui);
    let state = &mut app.palette.se;
    state.picker = Some(target);
    state.opacity = color.opacity;
    set_rgb(state, color.rgb);
    for name in ["Opacity", "OpacityLabel"] {
        ui.set_visible(PICKER, name, opacity);
    }
    ui.set_enabled(PICKER, "Eyedropper", cfg!(windows));
    ui.set_caption(PICKER, "PickerStatus", "");
    refresh_picker(app, ui);
    ui.show(PICKER);
}

fn set_rgb(state: &mut SeState, rgb: [u8; 3]) {
    state.rgb = rgb;
    let [r, g, b] = rgb.map(|v| f32::from(v) / 255.0);
    let max = r.max(g).max(b);
    let delta = max - r.min(g).min(b);
    state.brightness = max;
    state.saturation = if max == 0.0 { 0.0 } else { delta / max };
    if delta > 0.0 {
        state.hue = (if max == r {
            (g - b) / delta
        } else if max == g {
            2.0 + (b - r) / delta
        } else {
            4.0 + (r - g) / delta
        })
        .rem_euclid(6.0)
            / 6.0;
    }
}

fn hsv(h: f32, s: f32, v: f32) -> [u8; 3] {
    let h = h * 6.0;
    [5.0, 3.0, 1.0].map(|offset| {
        let k = (h + offset).rem_euclid(6.0);
        let value = v * (1.0 - s * k.min(4.0 - k).clamp(0.0, 1.0));
        (value * 255.0).round() as u8
    })
}

fn refresh_picker(app: &Mb3d, ui: &mut Ui) {
    let s = &app.palette.se;
    let color = argb(s.rgb);
    ui.set_text(PICKER, "HexValue", &format!("#{:06X}", color & 0xFFFFFF));
    ui.set_position(PICKER, "Brightness", (s.brightness * 1000.0).round() as i64);
    ui.set_position(PICKER, "Opacity", (s.opacity * 1000.0).round() as i64);
    ui.set_caption(
        PICKER,
        "OpacityLabel",
        &format!("Opacity  {:.0}%", s.opacity * 100.0),
    );
    ui.set_picture(
        PICKER,
        "Swatch",
        Some(swatch_bitmap(
            Swatch {
                rgb: s.rgb,
                opacity: s.opacity,
            },
            143,
            34,
            ui.visible(PICKER, "Opacity"),
        )),
    );

    let size = ui.c(PICKER, "Wheel").width as usize;
    let mut wheel = Bitmap::new(size, size, ui.theme.face());
    let center = size as f32 * 0.5;
    let radius = center - 6.0;
    let angle = s.hue * std::f32::consts::TAU;
    let mx = center + angle.cos() * radius * s.saturation;
    let my = center - angle.sin() * radius * s.saturation;
    for y in 0..size {
        for x in 0..size {
            let (dx, dy) = (x as f32 - center, center - y as f32);
            let sat = dx.hypot(dy) / radius;
            if sat <= 1.0 {
                let h = dy.atan2(dx).rem_euclid(std::f32::consts::TAU) / std::f32::consts::TAU;
                wheel.px[y * size + x] = argb(hsv(h, sat, s.brightness));
            }
            let d = (x as f32 - mx).hypot(y as f32 - my);
            if (3.5..=5.5).contains(&d) {
                wheel.px[y * size + x] = if d < 4.5 { 0xFFFF_FFFF } else { 0xFF15_1515 };
            }
        }
    }
    ui.set_picture(PICKER, "Wheel", Some(wheel));
}

fn hex(ui: &Ui) -> Option<[u8; 3]> {
    let value = ui.text(PICKER, "HexValue");
    let text = value.trim().trim_start_matches('#');
    if text.len() != 6 {
        return None;
    }
    u32::from_str_radix(text, 16).ok().map(rgb_of)
}

fn apply_picker_color(app: &mut Mb3d, ui: &mut Ui) {
    let color = Swatch {
        rgb: app.palette.se.rgb,
        opacity: app.palette.se.opacity,
    };
    match app.palette.se.picker.as_ref() {
        Some(&Target::Stop {
            outside,
            index,
            channel,
        }) => {
            let mut stops = stops(app, outside);
            let old = stops[index].colors[channel];
            if old.rgb == color.rgb && old.opacity == color.opacity {
                return;
            }
            set_color(&mut stops[index], outside, channel, color);
            commit(app, ui, outside, &stops);
            light_form::trigger_repaint(app, ui);
        }
        Some(&Target::Reference(i)) => {
            app.palette.rand_mid[i] = argb(color.rgb);
            refresh(app, ui);
        }
        Some(Target::Light(command)) => {
            let command = command.clone();
            light_form::dialog(
                app,
                ui,
                &command,
                &DialogResult::Color(Some(argb(color.rgb))),
            );
        }
        None => {}
    }
}

pub(crate) fn refresh_if_open(app: &Mb3d, ui: &mut Ui) {
    if ui.showing(F) {
        refresh(app, ui);
    }
}

pub(crate) fn picker_event(app: &mut Mb3d, ui: &mut Ui, e: &Event) {
    if app.main.calculating && !matches!(e.handler.as_str(), "PickHide" | "PickCancel") {
        stop_eyedropper(app, ui);
        return;
    }
    match e.handler.as_str() {
        "PickWheel" => {
            let (x, y) = match e.ev {
                Ev::MouseDown {
                    x,
                    y,
                    button: MouseButton::Left,
                    ..
                } => (x, y),
                Ev::MouseMove { x, y, shift } if shift & SS_LEFT != 0 => (x, y),
                _ => return,
            };
            let center = ui.c(PICKER, "Wheel").width as f32 / 2.0;
            let (dx, dy) = (x as f32 - center, center - y as f32);
            let state = &mut app.palette.se;
            state.hue = dy.atan2(dx).rem_euclid(std::f32::consts::TAU) / std::f32::consts::TAU;
            state.saturation = (dx.hypot(dy) / (center - 6.0)).min(1.0);
            state.rgb = hsv(state.hue, state.saturation, state.brightness);
        }
        "Brightness" => {
            let state = &mut app.palette.se;
            state.brightness = ui.position(PICKER, "Brightness") as f32 / 1000.0;
            state.rgb = hsv(state.hue, state.saturation, state.brightness);
        }
        "Opacity" => app.palette.se.opacity = ui.position(PICKER, "Opacity") as f32 / 1000.0,
        "PickCommon" => set_rgb(
            &mut app.palette.se,
            rgb_of(ui.tag(PICKER, &e.sender) as u32),
        ),
        "HexValue" if parse_edit(e) => {
            if let Some(value) = hex(ui) {
                set_rgb(&mut app.palette.se, value);
            } else {
                ui.set_caption(PICKER, "PickerStatus", "Enter a six-digit RGB hex value.");
                return;
            }
        }
        "PickCancel" if app.palette.se.eye_active => {
            stop_eyedropper(app, ui);
            return;
        }
        "PickCancel" => {
            ui.hide(PICKER);
            return;
        }
        "PickHide" => {
            app.palette.se.picker = None;
            stop_eyedropper(app, ui);
            return;
        }
        "Eyedropper" => {
            app.palette.se.eye_active = true;
            app.palette.se.eye_armed = false;
            ui.set_caption(
                PICKER,
                "PickerStatus",
                "Click any screen pixel to sample it. Esc cancels.",
            );
            ui.set_timer(PICKER, "PickTimer", true);
            return;
        }
        "PickScreen" => {
            let Some(rgb) = poll_screen(app, ui) else {
                return;
            };
            set_rgb(&mut app.palette.se, rgb);
        }
        _ => return,
    }
    ui.set_caption(PICKER, "PickerStatus", "");
    refresh_picker(app, ui);
    apply_picker_color(app, ui);
}

fn stop_eyedropper(app: &mut Mb3d, ui: &mut Ui) {
    app.palette.se.eye_armed = false;
    app.palette.se.eye_active = false;
    ui.set_timer(PICKER, "PickTimer", false);
    ui.set_caption(PICKER, "PickerStatus", "");
}

#[cfg(not(windows))]
fn poll_screen(_app: &mut Mb3d, _ui: &mut Ui) -> Option<[u8; 3]> {
    None
}

#[cfg(windows)]
fn poll_screen(app: &mut Mb3d, ui: &mut Ui) -> Option<[u8; 3]> {
    use std::ffi::c_void;
    type Handle = *mut c_void;
    #[repr(C)]
    struct Point {
        x: i32,
        y: i32,
    }
    #[link(name = "user32")]
    extern "system" {
        fn GetAsyncKeyState(key: i32) -> i16;
        fn GetCursorPos(point: *mut Point) -> i32;
        fn GetDC(window: Handle) -> Handle;
        fn ReleaseDC(window: Handle, dc: Handle) -> i32;
    }
    #[link(name = "gdi32")]
    extern "system" {
        fn GetPixel(dc: Handle, x: i32, y: i32) -> u32;
    }

    unsafe {
        if GetAsyncKeyState(0x1B) < 0 {
            stop_eyedropper(app, ui);
            return None;
        }
        if GetAsyncKeyState(0x01) >= 0 {
            app.palette.se.eye_armed = true;
            return None;
        }
        if !app.palette.se.eye_armed {
            return None;
        }
        stop_eyedropper(app, ui);
        let mut pos = Point { x: 0, y: 0 };
        let hwnd = std::ptr::null_mut();
        let color = if GetCursorPos(&mut pos) != 0 {
            let dc = GetDC(hwnd);
            if dc.is_null() {
                u32::MAX
            } else {
                let pixel = GetPixel(dc, pos.x, pos.y);
                ReleaseDC(hwnd, dc);
                pixel
            }
        } else {
            u32::MAX
        };
        if color == u32::MAX {
            ui.set_caption(
                PICKER,
                "PickerStatus",
                "The selected screen pixel could not be read.",
            );
            return None;
        }
        Some([color as u8, (color >> 8) as u8, (color >> 16) as u8])
    }
}

#[cfg(all(test,feature="se-desktop"))] mod se_windows_stop_click_tests {
 use super::*;
 #[test] fn se_windows_single_click_opens_and_retargets_picker() {
  let (mut ui,mut app)=crate::app::build(&[]).unwrap().unwrap();
  app.eng.stop();app.navi.eng.stop();app.main.calculating=false;
  for (channel,x) in [(0,10),(1,500),(0,300)] {
   let sender=format!("SePaletteBar{channel}");
   let down=Event{form:F.into(),sender:sender.clone(),handler:"SeBarDown".into(),ev:Ev::MouseDown{button:MouseButton::Left,x,y:30,shift:0}};
   event(&mut app,&mut ui,&down);
   let index=selected(&ui);let out=outside(&ui);let expected=stops(&app,out)[index].colors[channel].rgb;
   let up=Event{handler:"SeBarUp".into(),ev:Ev::MouseUp{button:MouseButton::Left,x,y:30,shift:0},..down};
   event(&mut app,&mut ui,&up);
   assert!(ui.showing(PICKER));assert_eq!(app.palette.se.rgb,expected);
   assert!(matches!(app.palette.se.picker,Some(Target::Stop{index:i,channel:c,..}) if i==index&&c==channel));
  }
  app.eng.stop();app.navi.eng.stop();
 }
}
