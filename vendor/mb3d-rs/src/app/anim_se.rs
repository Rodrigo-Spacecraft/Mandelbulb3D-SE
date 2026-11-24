//! The SE animation window. The renderer and project operations are shared with
//! the legacy animation form.
use super::super::main_se::place;
use super::*;
use crate::vcl::control::{Column, Control};
use crate::vcl::form::Form;

fn add(
    form: &mut Form,
    name: &str,
    class: &str,
    text: &str,
    bounds: (i32, i32, i32, i32),
) -> usize {
    let mut c = Control::new(name, class);
    c.caption = text.into();
    c.set_bounds(bounds.0, bounds.1, bounds.2, bounds.3);
    form.add_control(0, c)
}

fn menu(form: &mut Form, name: &str, choices: &[&str], bounds: (i32, i32, i32, i32)) {
    let id = add(form, name, "TComboBox", "", bounds);
    let c = &mut form.ctl[id];
    c.style = "csDropDownList".into();
    c.items = choices.iter().map(|s| s.to_string()).collect();
    c.set_item_index(0);
    c.events.insert("OnChange".into(), name.into());
}

fn button(form: &mut Form, name: &str, title: &str, bounds: (i32, i32, i32, i32)) {
    let id = add(form, name, "TButton", title, bounds);
    form.ctl[id].events.insert("OnClick".into(), name.into());
}

pub(super) fn configure(ui: &mut Ui) {
    ui.set_client_size(F, 900, 620);
    let form = ui.fm(F);
    for id in form.ctl[0].children.clone() {
        form.ctl[id].visible = false;
    }
    let table = add(form, "SeKeys", "TListView", "", (16, 16, 354, 282));
    let c = &mut form.ctl[table];
    c.default_row_height = 52;
    c.cols = [("Preview", 78), ("Key", 63), ("To next", 90), ("Frame", 85)]
        .map(|(caption, width)| Column {
            caption: caption.into(),
            width,
            auto: false,
        })
        .into();
    c.events.insert("OnChange".into(), "SeKeys".into());
    let image = add(form, "SeAnimationImage", "TImage", "", (390, 16, 494, 282));
    form.ctl[image].stretch = true;
    form.ctl[image].proportional = true;
    form.ctl[image].center = true;

    for (index, (name, title)) in [
        ("SpeedButton1", "Capture"),
        ("SeInsertKey", "Insert"),
        ("SpeedButton12", "Interp"),
        ("SpeedButton8", "To Main"),
        ("SpeedButton5", "Remove"),
        ("SpeedButton2", "Move up"),
        ("SpeedButton3", "Move Dn"),
        ("SpeedButton13", "Clear"),
    ]
    .into_iter()
    .enumerate()
    {
        let bounds = (
            16 + (index % 4) as i32 * 90,
            310 + (index / 4) as i32 * 34,
            86,
            28,
        );
        if name == "SeInsertKey" {
            button(form, name, title, bounds);
        } else {
            show(form, name, title, bounds);
        }
    }
    for (index, (name, title)) in [
        ("Edit1", "Frames to next"),
        ("SeCurrentFrame", "Current frame"),
        ("Edit6", "Width"),
        ("Edit7", "Height"),
        ("SeFps", "Frames / second"),
        ("Edit12", "Preview every nth"),
        ("Edit8", "Start frame"),
        ("Edit11", "End frame"),
    ]
    .into_iter()
    .enumerate()
    {
        let x = 16 + (index % 2) as i32 * 244;
        let y = 380 + (index / 2) as i32 * 32;
        add(
            form,
            &format!("SeLabel{name}"),
            "TLabel",
            title,
            (x, y + 5, 142, 19),
        );
        if name.starts_with("Se") {
            add(form, name, "TEdit", "", (x + 150, y, 80, 25));
        } else {
            show(form, name, "", (x + 150, y, 80, 25));
        }
        let edit = form.c_mut(name);
        edit.read_only = false;
        edit.events.remove("OnChange");
        for event in ["OnExit", "OnKeyDown"] {
            edit.events.insert(event.into(), "SeAnimationValue".into());
        }
    }
    let timeline = add(form, "SeTimeline", "TTrackBar", "", (390, 310, 494, 28));
    let c = &mut form.ctl[timeline];
    c.min = 1;
    c.max = 2;
    c.position = 1;
    c.fine_track_drag = true;
    c.events.insert("OnChange".into(), "SeTimeline".into());
    let overlay = add(
        form,
        "SeFrameNumber",
        "TCheckBox",
        "Frame number",
        (390, 345, 136, 26),
    );
    form.ctl[overlay]
        .events
        .insert("OnClick".into(), "SeFrameNumber".into());
    menu(
        form,
        "SeFrameColor",
        &["White", "Black"],
        (534, 345, 112, 27),
    );
    button(form, "SePlayback", "Resume", (750, 345, 134, 28));
    show(form, "SpeedButton10", "Processings…", (742, 378, 132, 28));
    show(form, "CheckBox2", "Loop animation", (510, 380, 212, 26));
    form.c_mut("CheckBox2")
        .events
        .insert("OnClick".into(), "SeAnimationOptions".into());
    add(
        form,
        "SeSamplingLabel",
        "TLabel",
        "Oversampling",
        (510, 419, 100, 20),
    );
    menu(
        form,
        "SeSampling",
        &["1×", "2×", "3×", "4×", "5×", "6×"],
        (610, 412, 54, 28),
    );
    add(
        form,
        "SeInterpolationLabel",
        "TLabel",
        "Interp",
        (670, 419, 46, 20),
    );
    menu(
        form,
        "SeInterpolation",
        &["Linear", "Quadratic Bezier"],
        (716, 412, 158, 28),
    );
    show(form, "Label25", "", (510, 451, 365, 20));
    add(
        form,
        "SePreviewScaleLabel",
        "TLabel",
        "Preview scale down",
        (510, 483, 150, 20),
    );
    menu(
        form,
        "SePreviewScale",
        &["1×", "1/2×", "1/4×", "1/8×"],
        (666, 476, 208, 28),
    );
    form.c_mut("SePreviewScale").set_item_index(1);
    for (name, title, x, width) in [
        ("SpeedButton11", "Open animation…", 16, 142),
        ("SeRenderFrame", "Render Current Frame", 166, 158),
        ("Button4", "Render preview", 332, 118),
        ("Button3", "Choose Output Folder…", 458, 168),
        ("Button2", "Start Render", 634, 110),
        ("SpeedButton9", "Save animation…", 752, 132),
    ] {
        let bounds = (x, 516, width, 30);
        if name == "SeRenderFrame" {
            button(form, name, title, bounds);
        } else {
            show(form, name, title, bounds);
        }
    }
    add(
        form,
        "SeOutputFolderLabel",
        "TLabel",
        "Output folder",
        (16, 565, 90, 18),
    );
    show(form, "Edit2", "", (108, 556, 588, 27));
    form.c_mut("Edit2").read_only = true;
    show(form, "CheckBox7", "Export Z-buffer", (714, 556, 170, 28));
    show(form, "Label19", "", (16, 590, 690, 20));
    show(form, "Label22", "", (750, 590, 130, 20));

    for name in ["CheckBox2", "CheckBox7"] {
        form.c_mut(name).props.retain(|(key, _)| key != "Alignment");
    }
    form.c_mut("Timer2").interval = 10;
    form.c_mut("Timer2")
        .events
        .insert("OnTimer".into(), "SePlaybackTick".into());
    form.c_mut("Timer2").enabled = false;
    form.ctl[0]
        .events
        .insert("OnHide".into(), "FormHide".into());
}

fn show(form: &mut Form, name: &str, title: &str, bounds: (i32, i32, i32, i32)) {
    place(form, 0, name, bounds);
    let c = form.c_mut(name);
    c.visible = true;
    if !title.is_empty() {
        c.caption = title.into();
    }
    c.glyph = None;
    c.flat = false;
}

pub(super) fn initialize(app: &mut Mb3d, ui: &mut Ui) {
    if count(app) == 0 {
        ui.set_text(F, "Edit6", &app.scene.width.max(16).to_string());
        ui.set_text(F, "Edit7", &app.scene.height.max(16).to_string());
        ui.set_text(F, "Edit8", "1");
        ui.set_text(F, "Edit11", "last");
        ui.set_item_index(F, "SeInterpolation", 1);
        ui.set_item_index(F, "SeSampling", 0);
    }
    for (name, value) in [("SeFps", "24"), ("Edit12", "1"), ("SeCurrentFrame", "1")] {
        ui.set_text(F, name, value);
    }
}

pub(super) fn refresh(app: &Mb3d, ui: &mut Ui) {
    let a = &app.anim.anim;
    let n = a.keyframes.len();
    let i = app.anim.current.saturating_sub(1).min(n);
    let mut start = 1usize;
    let mut rows = Vec::with_capacity(n + 1);
    for (index, key) in a.keyframes.iter().enumerate() {
        rows.push(vec![
            String::new(),
            (index + 1).to_string(),
            key.frames.to_string(),
            start.to_string(),
        ]);
        start += key.frames as usize;
    }
    rows.push(vec![
        String::new(),
        "Empty".into(),
        String::new(),
        start.to_string(),
    ]);
    let form = ui.fm(F);
    let id = form.id("SeKeys").unwrap();
    let table = &mut form.ctl[id];
    table.cells = rows;
    table.images = app
        .anim
        .thumbs
        .iter()
        .map(|image| image.clone().unwrap_or_else(|| Bitmap::new(0, 0, 0)))
        .collect();
    table.images.push(Bitmap::new(0, 0, 0));
    table.item_index = i as i32;
    let (_, _, visible, _, _) = form.listview_rows(id);
    let table = &mut form.ctl[id];
    table.scroll_y = table.scroll_y.max(i as i32 + 1 - visible).min(i as i32);
    ui.set_visible(F, "Edit1", true);
    ui.set_text(
        F,
        "Edit1",
        &a.keyframes
            .get(i)
            .map_or_else(|| ui.text(F, "Edit5"), |k| k.frames.to_string()),
    );
    ui.cm(F, "SeTimeline").max = a.frame_count().max(2) as i64;
    if !app.anim.job.lock().unwrap().running {
        ui.set_enabled(F, "SeTimeline", a.frame_count() > 0);
    }
    if !app.anim.inline_preview {
        set_frame(ui, a.first_frame_of(i) + 1);
        show_image(
            ui,
            app.anim.thumbs.get(i).cloned().flatten(),
            a.first_frame_of(i) + 1,
        );
    }
    if !app.anim.job.lock().unwrap().running {
        for (name, enabled) in [
            ("SpeedButton1", true),
            ("SeInsertKey", true),
            ("SpeedButton12", i + 1 < n),
            ("SpeedButton8", i < n),
            ("SpeedButton5", i < n),
            ("SpeedButton2", i > 0 && i < n),
            ("SpeedButton3", i + 1 < n),
            ("SpeedButton13", n > 0),
            ("SeRenderFrame", a.frame_count() > 0),
            ("Button4", n >= 2),
            ("Button2", n >= 2),
        ] {
            ui.set_enabled(F, name, enabled);
        }
    }
}

pub(super) fn estimate(app: &Mb3d, ui: &mut Ui) {
    let a = &app.anim.anim;
    let scale = preview_divisor(ui);
    let count =
        frame_range(ui, a).map_or(0, |(start, end)| (end - start).div_ceil(preview_step(ui)));
    let factor = (1.0 / scale).max(16.0 / f64::from(a.width.min(a.height).max(16)));
    let size = f64::from(a.width) * f64::from(a.height) * factor.powi(2) * 4.0 * count as f64;
    let text = if count > 0 {
        format!(
            "Preview: {count} frames, about {:.1} MB",
            size / 1_048_576.0
        )
    } else {
        "Preview: capture keyframes to estimate memory".into()
    };
    ui.set_caption(F, "Label25", &text);
}

pub(super) fn preview_divisor(ui: &Ui) -> f64 {
    (1 << ui.item_index(F, "SePreviewScale").clamp(0, 3)) as f64
}
pub(super) fn preview_step(ui: &Ui) -> usize {
    pti(&ui.text(F, "Edit12")).clamp(1, 1000) as usize
}

pub(super) fn frame_range(ui: &Ui, a: &Animation) -> Result<(usize, usize), String> {
    let total = a.frame_count();
    let start = ui
        .text(F, "Edit8")
        .trim()
        .parse::<usize>()
        .ok()
        .filter(|n| *n > 0);
    let end = ui.text(F, "Edit11");
    let end = if end.trim().eq_ignore_ascii_case("last") {
        Some(total)
    } else {
        end.trim().parse().ok()
    };
    match start.zip(end) {
        Some((start, end)) if start <= end && end <= total => Ok((start - 1, end)),
        _ => Err(format!("Enter a frame range between 1 and {total}.")),
    }
}

fn set_frame(ui: &mut Ui, number: usize) {
    ui.set_position(F, "SeTimeline", number as i64);
    ui.set_text(F, "SeCurrentFrame", &number.to_string());
}

pub(super) fn show_image(ui: &mut Ui, image: Option<Bitmap>, number: usize) {
    let show_number = ui.checked(F, "SeFrameNumber");
    let color = if ui.item_index(F, "SeFrameColor") == 1 { 0xFF00_0000 } else { 0xFFFF_FFFF };
    let preview = ui.cm(F, "SeAnimationImage");
    preview.image_text_color = show_number.then_some(color);
    preview.caption = number.to_string();
    ui.set_picture(F, "SeAnimationImage", image);
}

fn cached_frame(app: &Mb3d, index: usize) -> Option<Bitmap> {
    app.anim
        .job
        .lock()
        .unwrap()
        .frames
        .get(index)
        .cloned()
        .flatten()
}

pub(super) fn show_cached(app: &mut Mb3d, ui: &mut Ui, index: usize) {
    if let Some(image) = cached_frame(app, index) {
        app.anim.play_frame = index;
        let number = app.anim.preview_start + index * app.anim.preview_step;
        set_frame(ui, number);
        show_image(ui, Some(image), number);
    }
}

fn pause(app: &mut Mb3d, ui: &mut Ui) {
    app.anim.playing = false;
    ui.set_timer(F, "Timer2", false);
    ui.set_caption(F, "SePlayback", "Resume");
}

pub(super) fn reset_preview(app: &mut Mb3d, ui: &mut Ui) {
    pause(app, ui);
    app.anim.inline_preview = false;
    let mut job = app.anim.job.lock().unwrap();
    if !job.running {
        job.frames.clear();
    }
    ui.set_enabled(F, "SePlayback", false);
}

pub(super) fn play(app: &mut Mb3d, ui: &mut Ui) {
    app.anim.playing = true;
    app.anim.started = Instant::now();
    ui.set_caption(F, "SePlayback", "Pause");
    ui.set_timer(F, "Timer2", true);
}

fn seek(app: &mut Mb3d, ui: &mut Ui, number: usize) {
    set_frame(ui, number);
    if app.anim.inline_preview {
        let index = (number.saturating_sub(app.anim.preview_start) + app.anim.preview_step / 2)
            / app.anim.preview_step;
        let last = app.anim.job.lock().unwrap().done.saturating_sub(1);
        show_cached(app, ui, index.min(last));
    }
}

pub(super) fn job_controls(ui: &mut Ui, running: bool, action: &str) {
    for name in [
        "SeKeys",
        "SpeedButton1",
        "SeInsertKey",
        "SpeedButton12",
        "SpeedButton8",
        "SpeedButton5",
        "SpeedButton2",
        "SpeedButton3",
        "SpeedButton13",
        "SpeedButton10",
        "SpeedButton11",
        "SpeedButton9",
        "Button3",
        "Edit1",
        "SeTimeline",
        "SeSampling",
        "SeInterpolation",
        "SePreviewScale",
        "CheckBox2",
        "CheckBox7",
        "Edit6",
        "Edit7",
        "Edit8",
        "Edit11",
        "Edit12",
        "SeCurrentFrame",
    ] {
        ui.set_enabled(F, name, !running);
    }
    for (name, label) in [
        ("Button2", "Start Render"),
        ("Button4", "Render preview"),
        ("SeRenderFrame", "Render Current Frame"),
    ] {
        let active = running && name == action;
        ui.set_enabled(F, name, !running || active);
        ui.set_caption(F, name, if active { "Stop" } else { label });
    }
}

pub(super) fn capture(app: &mut Mb3d, ui: &mut Ui, insert: bool) {
    if app.main.calculating || app.eng.running() {
        ui.set_caption(F, "Label19", "Wait for the main render to finish.");
        return;
    }
    let Some(base) = app.eng.base().filter(|base| base.scene.slice_2d == 0) else {
        ui.set_caption(
            F,
            "Label19",
            "Render the main scene before capturing a keyframe.",
        );
        return;
    };
    let scene = base.scene.clone();
    reset_preview(app, ui);
    read_settings(app, ui);
    let n = count(app);
    let i = app.anim.current.saturating_sub(1).min(n);
    if (insert || i == n) && n >= 1000 {
        ui.set_caption(F, "Label19", "At most 1000 keyframes are supported.");
        return;
    }
    let frames = pti(&ui.text(F, "Edit1")).clamp(1, 10000) as u32;
    let index = if insert { (i + 1).min(n) } else { i };
    if insert || index == n {
        app.anim
            .anim
            .keyframes
            .insert(index, Keyframe::new(scene, frames));
        app.anim.thumbs.insert(index, None);
        app.anim.ids.insert(index, app.anim.next_id);
        app.anim.next_id += 1;
    } else {
        app.anim.anim.keyframes[index].scene = scene;
    }
    app.anim.current = index + 1;
    render_thumb(app, ui, index);
    refresh(app, ui);
    estimate(app, ui);
    ui.set_caption(F, "Label19", &format!("Captured keyframe {}.", index + 1));
}

pub(super) fn event(app: &mut Mb3d, ui: &mut Ui, e: &Event) -> bool {
    match e.handler.as_str() {
        "SeKeys" => {
            reset_preview(app, ui);
            app.anim.current = ui.item_index(F, "SeKeys").max(0) as usize + 1;
            refresh(app, ui);
        }
        "SeInsertKey" => capture(app, ui, true),
        "SeRenderFrame" => start_preview(app, ui, true),
        "SeTimeline" => {
            pause(app, ui);
            seek(app, ui, ui.position(F, "SeTimeline").max(1) as usize);
        }
        "SePlayback" => {
            if app.anim.playing {
                pause(app, ui);
            } else {
                let n = app.anim.job.lock().unwrap().done;
                if n > 1 && app.anim.play_frame + 1 >= n {
                    show_cached(app, ui, 0);
                }
                play(app, ui);
            }
        }
        "SePlaybackTick" => {
            if !app.anim.playing || !ui.showing(F) {
                return true;
            }
            let fps = pti(&ui.text(F, "SeFps")).clamp(1, 240) as f64;
            let interval = std::time::Duration::from_secs_f64(app.anim.preview_step as f64 / fps);
            if app.anim.started.elapsed() >= interval {
                app.anim.started = Instant::now();
                let n = app.anim.job.lock().unwrap().done;
                let next = app.anim.play_frame + 1;
                if next < n {
                    show_cached(app, ui, next);
                } else if n > 1 && ui.checked(F, "CheckBox2") {
                    show_cached(app, ui, 0);
                } else {
                    pause(app, ui);
                }
            }
        }
        "SeFrameNumber" | "SeFrameColor" => {
            if app.anim.inline_preview {
                show_cached(app, ui, app.anim.play_frame);
            } else {
                refresh(app, ui);
            }
        }
        "SeAnimationValue" if matches!(e.ev, Ev::Exit | Ev::KeyDown { key: 13, .. }) => {
            if e.sender == "Edit1" {
                let value = pti(&ui.text(F, "Edit1")).clamp(1, 10000);
                ui.set_text(F, "Edit5", &value.to_string());
                if let Some(key) = app.anim.anim.keyframes.get_mut(app.anim.current - 1) {
                    key.frames = value as u32;
                }
                reset_preview(app, ui);
                refresh(app, ui);
            } else if e.sender == "SeCurrentFrame" {
                pause(app, ui);
                let frame = pti(&ui.text(F, "SeCurrentFrame")).max(1) as usize;
                seek(app, ui, frame.min(app.anim.anim.frame_count().max(1)));
            }
            read_settings(app, ui);
            estimate(app, ui);
        }
        "SeAnimationOptions" | "SeSampling" | "SeInterpolation" | "SePreviewScale" => {
            reset_preview(app, ui);
            read_settings(app, ui);
            refresh(app, ui);
            estimate(app, ui);
        }
        "FormHide" => {
            pause(app, ui);
            app.anim.stop.store(true, Ordering::SeqCst);
        }
        _ => return false,
    }
    true
}
