//! The SE main-window layout and its desktop actions.
use super::{Mb3d, MAIN};
use crate::vcl::control::{Align, Control, Kind};
use crate::vcl::form::Form;
use crate::vcl::Ui;
use std::path::PathBuf;

pub(super) fn configure(ui: &mut Ui) {
    let form = ui.fm(MAIN);
    super::main_camera::configure(form);
    form.ctl[0].min_w = 800;
    form.ctl[0].min_h = 728;
    let panel = form.id("Panel1").unwrap();
    form.ctl[panel].kind = Kind::ScrollBox;
    form.ctl[panel].width = 296;
    for name in ["Panel2", "Panel3", "Panel4", "Panel6"] {
        form.c_mut(name).visible = false;
    }
    for name in ["TabSheet8", "TabSheet9", "TabSheet3", "TabSheet6"] {
        form.c_mut(name).tab_visible = false;
    }

    place(form, panel, "PageControl1", (8, 448, 262, 232));
    place(form, panel, "ProgressBar1", (12, 687, 24, 24));
    form.c_mut("ProgressBar1").circular_progress=true;
    place(form, panel, "Label6", (44, 691, 223, 19));
    form.c_mut("Memo1").visible = false;
    form.c_mut("Button2").default = true;
    form.c_mut("SpeedButton35").flat = false;
    form.c_mut("Button8").enabled = false;
    form.c_mut("Button3").enabled = false;

    for (name, caption, x, y, width) in [
        ("Button9", "Open…", 9, 380, 79),
        ("Button8", "Save…", 93, 380, 79),
        ("Button3", "Export .png", 177, 380, 92),
        ("SpeedButton8", "Open from clipboard", 9, 348, 126),
        ("SpeedButton7", "Save to clipboard", 143, 348, 126),
        ("Button10", "Formulas…", 9, 244, 126),
        ("Button18", "Lighting…", 143, 244, 126),
        ("SpeedButton15", "Navigator…", 9, 276, 126),
        ("Button15", "Post-process…", 143, 276, 126),
        ("SpeedButton12", "Animation…", 9, 308, 126),
        ("MutaGenBtn", "Mutagen…", 143, 308, 126),
        ("SpeedButton35", "1×", 177, 176, 92),
        ("Button2", "Render", 9, 144, 126),
        ("CheckBox10", "Keep aspect", 9, 80, 121),
        ("CheckBox11", "DEStop+C", 143, 80, 126),
        ("Label11", "Image width (px)", 9, 14, 138),
        ("Label25", "Image height (px)", 9, 48, 138),
    ] {
        place(form, panel, name, (x, y, width, 24));
        form.c_mut(name).caption = caption.into();
    }
    place(form, panel, "Edit11", (177, 14, 62, 21));
    place(form, panel, "Edit12", (177, 48, 62, 21));
    place(form, panel, "UpDown2", (242, 14, 27, 21));
    let buttons = [
        ("SeMaps", "Open Map Folder", 9, 422, 98),
        ("SeBackgrounds", "Open Bkgnd Folder", 113, 422, 108),
        ("SeHistory", "History", 143, 144, 126),
        ("SeActualSize", "Display Actual Size", 9, 112, 260),
    ];
    for (name, caption, x, y, width) in buttons {
        let mut button = Control::new(name, "TButton");
        button.caption = caption.into();
        button.set_bounds(x, y, width, 25);
        if name == "SeHistory" {
            button.events.insert("OnMouseDown".into(), "SeHistoryDown".into());
        } else { button.events.insert("OnClick".into(), name.into()); }
        button.enabled = name != "SeActualSize";
        form.add_control(panel, button);
    }
    for (name, caption, y) in [("SeSamplingLabel", "Oversampling", 180), ("SeOutputSize", "", 205)] {
        let mut label = Control::new(name, "TLabel");
        label.set_bounds(9, y, 260, 18);
        label.caption = caption.into();
        form.add_control(panel, label);
    }
    let scale_menu = form.id("PopupMenu1").unwrap();
    for (index, id) in form.ctl[scale_menu].children.clone().into_iter().enumerate() {
        let item = &mut form.ctl[id];
        item.visible = index < 6;
        item.caption = format!("{}×", index + 1);
    }
    let mut menu_button = Control::new("SeAppMenu", "TButton");
    menu_button.caption = "About".into();
    menu_button.popup_button = false;
    menu_button.set_bounds(227, 422, 42, 25);
    menu_button.events.insert("OnClick".into(), "SeAppMenu".into());
    form.add_control(panel, menu_button);
    let popup = form.add_control(0, Control::new("SeApplicationMenu", "TPopupMenu"));
    let mut about = Control::new("SeAbout", "TMenuItem");
    about.caption = "About Mandelbulb3D SE…".into();
    about.events.insert("OnClick".into(), "SeAbout".into());
    form.add_control(popup, about);
    add_history_menu(form);

    let calc = form.id("TabSheet2").unwrap();
    for (row, (label, field, caption)) in [
        ("Label18", "Edit25", "DE Stop"),
        ("Label22", "Edit6", "Raystep multiplier"),
        ("Label16", "Edit19", "Smooth normals"),
        ("Label13", "Edit20", "Stepcount"),
        ("Label26", "Edit8", "Stepwidth limiter"),
    ].into_iter().enumerate() {
        let y = 7 + row as i32 * 26;
        place(form, calc, label, (9, y + 3, 145, 19));
        form.c_mut(label).caption = caption.into();
        place(form, calc, field, (155, y, 64, 21));
    }
    form.c_mut("SpeedButton10").visible = false;
    place(form, calc, "SpinEdit2", (222, 59, 20, 21));
    place(form, calc, "SpinEdit5", (222, 85, 20, 21));
    for (name, x, y) in [
        ("CheckBox9", 9, 140), ("CheckBox1", 131, 140),
        ("CheckBox3", 9, 163), ("CheckBox8", 131, 163),
        ("CheckBox2", 9, 186),
    ] {
        place(form, calc, name, (x, y, 116, 19));
    }
    form.c_mut("CheckBox9").caption = "Vary DE with FOV".into();
    form.c_mut("CheckBox8").caption = "Short-distance DE".into();
    form.c_mut("CheckBox2").caption = "Step below DE stop".into();

    let settings = form.id("TabSheet4").unwrap();
    for id in form.ctl[settings].children.clone() { form.ctl[id].visible=false; }
    place(form, settings, "Label15", (9, 11, 144, 18));
    form.c_mut("Label15").caption = "CPU Thread (0=auto)".into();
    form.c_mut("Label15").alignment=crate::vcl::canvas::HAlign::Left;
    place(form, settings, "Edit21", (155, 7, 64, 24));
    let field=form.c_mut("Edit21");
    field.visible=true;
    field.read_only=false;
    field.numbers_only=true;
    field.hint="0 = automatic; otherwise 1–256 CPU threads. Applies to subsequent renders.".into();
    field.events.insert("OnChange".into(),"SeThreadCountChange".into());
    field.events.insert("OnExit".into(),"SeThreadCountExit".into());
    form.c_mut("Label15").visible=true;
    place(form, settings, "UpDown3", (225, 7, 20, 24));
    let stepper=form.c_mut("UpDown3");
    stepper.visible=true;
    stepper.min=0;
    stepper.max=256;

    let info = form.id("TabSheet5").unwrap();
    for id in form.ctl[info].children.clone() { form.ctl[id].visible=false; }
    let mut report=Control::new("SeRenderInfo","TMemo");
    report.align=Align::Client;
    report.read_only=true;
    report.word_wrap=true;
    report.scroll_bars=2;
    report.font=Some(crate::vcl::font::Font { name:"Consolas".into(),height:-11,..Default::default() });
    report.text="Statistics appear here after a main-window render finishes. Select and copy the text to compare renders.".into();
    report.hint="Completed render statistics. Select text and press Ctrl+C to copy.".into();
    report.show_hint=Some(true);
    form.add_control(info,report);

}

pub(super) fn place(form: &mut Form, parent: usize, name: &str, (x, y, w, h): (i32, i32, i32, i32)) {
    let id = form.id(name).unwrap();
    let old_parent = form.ctl[id].parent.unwrap();
    if old_parent != parent {
        form.ctl[old_parent].children.retain(|&child| child != id);
        form.ctl[parent].children.push(id);
    }
    let control = &mut form.ctl[id];
    control.parent = Some(parent);
    control.align = Align::None;
    control.set_bounds(x, y, w, h);
    control.anchored = false;
}

const HISTORY_LIMIT: usize = 50;

fn add_history_menu(form: &mut Form) {
    let menu = form.add_control(0, Control::new("SeHistoryMenu", "TPopupMenu"));
    let empty = form.add_control(menu, Control::new("SeHistoryEmpty", "TMenuItem"));
    form.ctl[empty].caption = "No completed renders".into();
    form.ctl[empty].enabled = false;
    let mut parent = menu;
    for index in 0..HISTORY_LIMIT {
        if index >= 10 && index % 10 == 0 {
            let mut group = Control::new(&format!("SeHistoryGroup{index}"), "TMenuItem");
            group.caption = format!("Older renders {}–{}", index + 1, index + 10);
            parent = form.add_control(menu, group);
        }
        let mut item = Control::new(&format!("SeHistoryItem{index}"), "TMenuItem");
        item.tag = index as i64;
        item.events.insert("OnClick".into(), "SeHistoryItem".into());
        form.add_control(parent, item);
    }
}

pub(super) fn save_history_thumbnail(path: &std::path::Path, pixels: &[u8], width: usize, height: usize) {
    if width == 0 || height == 0 { return; }
    let scale = (44.0 / width as f64).min(32.0 / height as f64).min(1.0);
    let thumb_width = (width as f64 * scale).round().max(1.0) as usize;
    let thumb_height = (height as f64 * scale).round().max(1.0) as usize;
    let mut thumbnail = Vec::with_capacity(thumb_width * thumb_height * 3);
    for y in 0..thumb_height {
        for x in 0..thumb_width {
            let source_x = (2 * x + 1) * width / (2 * thumb_width);
            let source_y = (2 * y + 1) * height / (2 * thumb_height);
            let offset = 3 * (source_y * width + source_x);
            thumbnail.extend_from_slice(&pixels[offset..offset + 3]);
        }
    }
    let png = crate::png::encode_rgb(thumb_width, thumb_height, &thumbnail);
    let _ = std::fs::write(path.with_extension("thumb.png"), png);
}

pub(super) fn show_history(ui: &mut Ui) -> Vec<PathBuf> {
    let mut files = Vec::new();
    let history = crate::appdirs::work_folder("History");
    if let Ok(days) = history.read_dir() {
        for day in days.flatten() {
            if let Ok(entries) = day.path().read_dir() {
                files.extend(entries.flatten().map(|entry| entry.path()).filter(|path| {
                    path.extension().is_some_and(|ext| ext == "m3p")
                }));
            }
        }
    }
    files.sort_unstable_by(|a, b| b.cmp(a));
    files.truncate(HISTORY_LIMIT);
    for index in 0..HISTORY_LIMIT {
        let name = format!("SeHistoryItem{index}");
        ui.set_visible(MAIN, &name, index < files.len());
        let thumb = files.get(index)
            .and_then(|path| std::fs::read(path.with_extension("thumb.png")).ok())
            .and_then(|bytes| crate::vcl::bitmap::decode_any(&bytes));
        ui.set_picture(MAIN, &name, thumb);
        if let Some(path) = files.get(index) {
            let date = path.parent().and_then(|day| day.file_name()).unwrap_or_default();
            let title = path.file_stem().unwrap_or_default();
            ui.set_caption(MAIN, &name, &format!("{}  {}", date.to_string_lossy(), title.to_string_lossy()));
        }
        if index >= 10 && index % 10 == 0 {
            ui.set_visible(MAIN, &format!("SeHistoryGroup{index}"), index < files.len());
        }
    }
    ui.set_visible(MAIN, "SeHistoryEmpty", files.is_empty());
    let height = ui.c(MAIN, "SeHistory").height;
    ui.popup_menu(MAIN, "SeHistoryMenu", "SeHistory", 0, height);
    files
}

pub(super) fn sampling_readout(ui: &mut Ui, factor: i32) {
    let dimension = |field| super::util::pti(&ui.text(MAIN, field));
    let (w, h) = (dimension("Edit11").saturating_mul(factor), dimension("Edit12").saturating_mul(factor));
    ui.set_caption(MAIN, "SpeedButton35", &format!("{factor}×"));
    let size = if w > 0 && h > 0 { format!("Render: {w} × {h} px") } else { String::new() };
    ui.set_caption(MAIN, "SeOutputSize", &size);
}

const SCENE_PAGES: [&str; 2] = ["TabSheet8", "TabSheet3"];

pub(super) fn show_scene_page(ui: &mut Ui, index: usize) {
    if let Some(page) = SCENE_PAGES.get(index) {
        ui.set_active_page(MAIN, "PageControl1", page);
        update_scene_pages(ui);
    }
}

pub(super) fn update_scene_pages(ui: &mut Ui) {
    let active = ui.active_page(MAIN, "PageControl1");
    for page in SCENE_PAGES {
        ui.cm(MAIN, page).tab_visible = active == page;
    }
}

pub(super) fn sync_thread_controls(ui: &mut Ui) {
    ui.set_enabled(MAIN, "Edit21", true);
    ui.set_enabled(MAIN, "UpDown3", true);
}

pub(super) fn actual_size(ui: &mut Ui) {
    let Some(picture)=ui.c(MAIN,"Image1").picture.as_ref() else{return};
    let (width,height)=(picture.w as i32,picture.h as i32);
    ui.cm(MAIN,"ScrollBox1").scroll_x=0;
    ui.cm(MAIN,"ScrollBox1").scroll_y=0;
    let panel=ui.c(MAIN,"Panel1").width;
    let form=ui.fm(MAIN);
    form.maximized=false;
    form.ctl[0].width=(width+panel+4).max(form.ctl[0].min_w);
    form.ctl[0].height=(height+4).max(form.ctl[0].min_h);
    let fi=ui.form_index(MAIN).unwrap();
    ui.request(crate::vcl::ui::Request::ActualImageSize(fi,width,height,panel));
}

pub(super) fn open_asset_folder(app: &mut Mb3d, ui: &mut Ui, backgrounds: bool) {
    let path = if backgrounds {
        crate::appdirs::work_folder("Backgrounds")
    } else {
        app.ini.dir(super::ini::DIR_MAPS)
    };
    if let Err(error) = std::fs::create_dir_all(&path).and_then(|()| open_folder(&path)) {
        app.message(ui, &format!("{}: {error}", path.display()));
    }
}

fn open_folder(path: &std::path::Path) -> std::io::Result<()> {
    #[cfg(windows)]
    {
        // Passing the path as a single argument preserves spaces in install paths.
        std::process::Command::new("explorer.exe").arg(path).spawn().map(|_| ())
    }
    #[cfg(not(windows))]
    {
        open::that_detached(path).map_err(std::io::Error::other)
    }
}

pub(super) fn render_info(sc:&crate::scene::Scene,s:&crate::diagnostics::Statistics,stats:super::engine::Stats,cached:bool)->String {
    use std::fmt::Write;
    let mut text=format!("Engine — {} × {}\n{}\nCPU thread limit: {}\nElapsed: {:.3} s\n\nDE stop: {}\nRaystep: {}\nMax iterations: {}\n\n",
        sc.width,sc.height,if cached {"Cached geometry update"}else{"Full render"},s.threads,s.elapsed,sc.de_stop,sc.z_step_div,sc.iterations);
    let _=writeln!(text,"Field evaluations: {}",s.evaluations.iter().sum::<u64>());
    for (name,count) in ["Primary","Normals","Hit refinement","Hard shadows","Ambient shadows","Fog","Refl/transmission","Other / coloring"].iter().zip(s.evaluations) {
        let _=writeln!(text,"  {name}: {count}");
    }
    let _=write!(text,"\nFormula executions: {}\n",s.formula_calls.iter().sum::<u64>());
    for (i,formula) in sc.formulas.iter().enumerate().take(8) {
        if formula.iterations!=0 || s.formula_calls[i]!=0 {
            let _=writeln!(text,"  Slot {} ({} × {}): {}",i+1,formula.formula.name(),formula.iterations,s.formula_calls[i]);
        }
    }
    text.push_str("Includes modifier calls and numerical-DE probes.\n");
    let _=write!(text,"\nPrimary rays: {}\nSurface hits: {}\nMarch loop passes: {}\nAverage per ray: {:.2}\nMaximum per ray: {}\nRays reaching limit: {}\n\nWall timings\n  Total: {:.3} s\n",
        s.rays,s.hits,s.steps,if s.rays==0 {0.}else{s.steps as f64/s.rays as f64},s.max_steps,s.capped_rays,s.elapsed);
    if !cached {
        let _=writeln!(text,"  Geometry: {:.3} s",stats.calc_s);
        if let Some(Some(seconds))=stats.stages.shadows {let _=writeln!(text,"  Hard shadow pass: {seconds:.3} s");}
        if let Some(Some(seconds))=stats.stages.ao {let _=writeln!(text,"  Ambient post-pass: {seconds:.3} s");}
        if let Some(seconds)=stats.stages.reflections {let _=writeln!(text,"  Refl/transmission: {seconds:.3} s");}
    }
    text.push_str("\nGeometry includes normals, refinement and dynamic fog. Reflection time may include its own shadow calculations. Separate surface-lighting and DOF timings are unavailable.\n\nField evaluations count distance or iteration queries at a point. Counts describe this update only. Reused geometry contributes no primary rays. Times exclude image display and history saving.\n");
    text
}

pub(super) fn stage_name(stage: &str) -> &str {
    match stage {
        "main rendering" | "main rendering (continued)" => "Geometry",
        "emissive illumination" | "painting" | "painting a preview" => "Radiance",
        "hard shadows" => "HShadows",
        "ambient" | "ambient occlusion" | "ambient shadows" => "AShadows",
        "hard shadows and ambient occlusion" => "HShadows / AShadows",
        "reflections" => "Reflections",
        "depth of field" => "DOF",
        _ => stage,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn main_window_places_actions_in_sidebar_and_keeps_camera_accessible() {
        let mut ui = Ui::default();
        ui.add_form(include_str!("forms/Mand.dfm")).unwrap();
        configure(&mut ui);
        ui.set_visible(MAIN, "ProgressBar1", true);

        let form = ui.fm(MAIN);
        form.ctl[0].set_bounds(0, 0, 1000, 740);
        form.layout();
        assert!(form.ctl[form.id("ProgressBar1").unwrap()].circular_progress);
        let sidebar = form.id("Panel1").unwrap();
        let bounds = form.abs_rect(sidebar);
        for name in [
            "Button2", "Button3", "Button8", "Button9", "Button10", "Button15",
            "Button18", "SpeedButton12", "SpeedButton15", "MutaGenBtn", "SeHistory",
            "SeActualSize", "SeMaps", "SeBackgrounds", "SeAppMenu", "ProgressBar1", "SpeedButton35", "Edit11", "Edit12",
        ] {
            let id = form.id(name).unwrap();
            assert!(form.showing(id), "{name}");
            let rect = form.abs_rect(id);
            assert!(bounds.contains(rect.x, rect.y), "{name}");
            assert!(bounds.contains(rect.right() - 1, rect.bottom() - 1), "{name}");
        }
        for (page, field) in [("TabSheet2", "Edit25"), ("TabSheet1", "CameraPaste"),
                              ("TabSheet4", "UpDown3"), ("TabSheet5", "SeRenderInfo")] {
            ui.set_active_page(MAIN, "PageControl1", page);
            let form = ui.fm(MAIN);
            form.layout();
            let control = form.id(field).unwrap();
            let rect = form.abs_rect(control);
            let page_rect = form.abs_rect(form.id(page).unwrap());
            assert!(form.showing(control), "{field}");
            assert!(page_rect.contains(rect.right() - 1, rect.bottom() - 1), "{field}");
        }
        ui.set_text(MAIN, "Edit11", "1920");
        ui.set_text(MAIN, "Edit12", "1080");
        sampling_readout(&mut ui, 2);
        assert_eq!(ui.caption(MAIN, "SpeedButton35"), "2×");
        assert_eq!(ui.caption(MAIN, "SeOutputSize"), "Render: 3840 × 2160 px");
    }
}
