//! SE Navigator layout. The navigation and preview engine live in navi_form.
use super::main_se::place;
use super::util::fts;
use crate::scene::Scene;
use crate::vcl::control::{Control, Kind};
use crate::vcl::form::Form;
use crate::vcl::Ui;

pub(super) const F: &str = "FNavigator";
pub(super) const NAVIGATION: &str = "SeNavigation";
pub(super) const FORMULAS: &str = "SeFormulaValues";
pub(super) const JULIA: &str = "SeJuliaValues";
pub(super) const ROTATION: &str = "SeRotation";
pub(super) const CUTTING: &str = "SeCutting";
pub(super) const SEARCH: &str = "SeFormulaSearch";
pub(super) const PARAMETER_ROWS: usize = 16;

fn add(form: &mut Form, parent: usize, name: &str, class: &str, caption: &str, bounds: (i32, i32, i32, i32)) -> usize {
    let mut control = Control::new(name, class);
    control.caption = caption.into();
    control.set_bounds(bounds.0, bounds.1, bounds.2, bounds.3);
    form.add_control(parent, control)
}

fn button(form: &mut Form, parent: usize, name: &str, caption: &str, bounds: (i32, i32, i32, i32)) {
    let id = add(form, parent, name, "TButton", caption, bounds);
    form.ctl[id].events.insert("OnClick".into(), name.into());
}

fn label(form: &mut Form, parent: usize, name: &str, caption: &str, bounds: (i32, i32, i32, i32)) {
    add(form, parent, name, "TLabel", caption, bounds);
}

fn edit(form: &mut Form, parent: usize, name: &str, handler: &str, tag: i64, bounds: (i32, i32, i32, i32)) {
    let id = add(form, parent, name, "TEdit", "", bounds);
    let control = &mut form.ctl[id];
    control.tag = tag;
    control.events.insert("OnExit".into(), handler.into());
    control.events.insert("OnKeyDown".into(), handler.into());
}

pub(super) fn configure(ui: &mut Ui) {
    ui.add_form(FORMULA_SEARCH_FORM).expect("valid formula search form");
    let form = ui.fm(F);
    for name in ["Panel1", "Panel2", "Panel3"] {
        form.c_mut(name).visible = false;
    }
    let tabs = add(form, 0, "SeNavigatorTabs", "TPageControl", "", (12, 424, 696, 230));
    let [navigation, formulas, julia, rotation, cutting] = [
        (NAVIGATION, "Navigation"),
        (FORMULAS, "Formula Values"),
        (JULIA, "Julia Values"),
        (ROTATION, "4D Rotation"),
        (CUTTING, "Cutting"),
    ].map(|(name, title)| add(form, tabs, name, "TTabSheet", title, (0, 0, 0, 0)));
    form.ctl[tabs].active_page = Some(navigation);

    for (index, (name, caption)) in [
        ("SpeedButton9", "Forward (W)"), ("SpeedButton10", "Back (S)"),
        ("SpeedButton3", "Left (A)"), ("SpeedButton4", "Right (D)"),
        ("SpeedButton2", "Down (C)"), ("SpeedButton1", "Up (E)"),
        ("SpeedButton7", "Look left (J)"), ("SpeedButton8", "Look right (L)"),
        ("SpeedButton5", "Look up (I)"), ("SpeedButton6", "Look down (K)"),
        ("SpeedButton12", "Roll left (U)"), ("SpeedButton13", "Roll right (O)"),
    ].into_iter().enumerate() {
        place(form, navigation, name, (8 + (index % 6) as i32 * 112, 3 + (index / 6) as i32 * 34, 105, 28));
        let control = form.c_mut(name);
        control.caption = caption.into();
        control.picture = None;
        control.glyph = None;
        control.flat = false;
        control.events.remove("OnClick");
        control.events.insert("OnMouseUp".into(), "SeMoveMouseUp".into());
    }

    for (i, (name, caption)) in [("Edit1", "Move step (%)"), ("Edit2", "Look step (°)"), ("Edit3", "FOVy (°)")].into_iter().enumerate() {
        let x = 8 + i as i32 * 224;
        label(form, navigation, &format!("SeMoveLabel{i}"), caption, (x, 79, 105, 18));
        place(form, navigation, name, (x + 111, 75, 100, 24));
    }
    for (index, (name, caption)) in [
        ("SeZoomIn", "Zoom in (+)"), ("SeZoomOut", "Zoom out (−)"),
        ("SeFarLess", "Far − (F1)"), ("SeFarMore", "Far + (F2)"),
    ].into_iter().enumerate() {
        button(form, navigation, name, caption, (8 + index as i32 * 168, 112, 160, 28));
    }
    label(form, navigation, "SeNavigationHint", "Hold Shift for finer movement. Arrow keys also look.", (8, 153, 660, 20));

    for (name, caption, x, width) in [
        ("SpeedButton11", "Reset from Main", 16, 132),
        ("ResetViewBtn", "Reset Pos", 296, 126),
        ("SpeedButton18", "Add to Anim", 430, 132),
        ("SpeedButton14", "Apply to Main", 570, 134),
    ] {
        place(form, 0, name, (x, 705, width, 27));
        form.c_mut(name).caption = caption.into();
    }
    button(form, 0, "SeResetValue", "Reset Value", (156, 705, 132, 27));
    form.c_mut("SeResetValue").enabled = false;
    place(form, 0, "CheckBox1", (16, 668, 124, 25));
    form.c_mut("CheckBox1").caption = "Fixed zoom/steps".into();
    label(form, 0, "SeBright", "Bright", (155, 674, 41, 18));
    place(form, 0, "TrackBar1", (202, 666, 82, 26));
    let brightness = form.c_mut("TrackBar1");
    brightness.vertical = false;
    brightness.modifier_resets_track = true;
    brightness.hint = "Windows-key-click or Ctrl-click to reset brightness.".into();
    for (index, caption) in ["Zoom", "Z Start", "Z End", "Far plane"].into_iter().enumerate() {
        let x = 310 + index as i32 * 98;
        label(form, 0, &format!("SeCameraLabel{index}"), caption, (x, 658, 96, 17));
        label(form, 0, &format!("SeCameraValue{index}"), "", (x, 677, 96, 17));
    }

    button(form, formulas, "SePreviousSlot", "<", (9, 5, 30, 24));
    button(form, formulas, "SeNextSlot", ">", (111, 5, 30, 24));
    form.c_mut("SePreviousSlot").hint = "Previous formula slot".into();
    form.c_mut("SeNextSlot").hint = "Next formula slot".into();
    let slot = add(form, formulas, "SeSlot", "TComboBox", "", (44, 5, 62, 24));
    let control = &mut form.ctl[slot];
    control.style = "csDropDownList".into();
    control.items = (1..=6).map(|n| n.to_string()).collect();
    control.set_item_index(0);
    control.events.insert("OnChange".into(), "SeSlot".into());
    button(form, formulas, "SeFormula", "Choose Formula…", (146, 5, 240, 24));
    form.c_mut("SeFormula").popup_button = true;
    add_formula_menu(form);
    place(form, formulas, "Label42", (402, 10, 72, 18));
    edit(form, formulas, "EditSeIterations", "SeIterations", 0, (476, 5, 54, 24));
    place(form, formulas, "UpDown2", (534, 5, 19, 24));
    label(form, formulas, "SeRangeLabel", "Range", (565, 10, 43, 18));
    let range = add(form, formulas, "SeRange", "TComboBox", "", (609, 5, 69, 24));
    let control = &mut form.ctl[range];
    control.style = "csDropDownList".into();
    control.items = ["min", "fine", "mid", "big"].map(str::to_string).into();
    control.set_item_index(2);
    control.events.insert("OnChange".into(), "SeRange".into());
    let values = add(form, formulas, "SeFormulaValuesPane", "TScrollBox", "", (8, 37, 672, 169));
    form.ctl[values].wheel_scroll_children=true;
    for row in 0..PARAMETER_ROWS {
        let y = row as i32 * 36;
        label(form, values, &format!("SeParameterLabel{row}"), "", (7, y + 4, 160, 20));
        let id = add(form, values, &format!("SeParameterSlider{row}"), "TTrackBar", "", (173, y, 320, 26));
        let control = &mut form.ctl[id];
        control.tag = row as i64;
        control.min = -100;
        control.max = 100;
        control.tick_style = "tsNone".into();
        control.events.insert("OnChange".into(), "SeParameterSlider".into());
        control.events.insert("OnMouseUp".into(), "SeParameterSliderUp".into());
        edit(form, values, &format!("EditSeParameter{row}"), "SeParameterEdit", row as i64, (505, y, 136, 24));
    }

    place(form, julia, "CheckBox7", (9, 3, 172, 22));
    place(form, julia, "CheckBox8", (227, 3, 200, 22));
    form.c_mut("CheckBox8").caption = "Spherical coordinates".into();
    form.c_mut("CheckBox8").events.insert("OnClick".into(),"SeJuliaCoordinates".into());
    for row in 0..4 {
        let y = 35 + row * 38;
        label(form, julia, &format!("SeJuliaLabel{row}"), ["X", "Y", "Z", "W"][row as usize], (12, y + 4, 100, 20));
        if row < 3 {
            place(form, julia, &format!("TrackBarEx{}", row + 1), (158, y, 318, 26));
        } else {
            let slider = add(form, julia, "SeJuliaW", "TTrackBar", "", (158, y, 318, 26));
            let control = &mut form.ctl[slider];
            control.min = -60;
            control.max = 60;
            control.events.insert("OnChange".into(), "SeJuliaW".into());
            control.events.insert("OnMouseUp".into(), "SeJuliaWUp".into());
        }
        let tag = if row == 3 { 14 } else { row };
        edit(form, julia, &format!("EditSeValue{tag}"), "SeValue", tag.into(), (494, y, 145, 24));
    }

    for row in 0..3 {
        let y = 14 + row * 43;
        label(form, rotation, &format!("SeRotationLabel{row}"), ["XW (°)", "YW (°)", "ZW (°)"][row as usize], (12, y + 4, 100, 20));
        place(form, rotation, &format!("TrackBarEx{}", row + 7), (158, y, 318, 26));
        edit(form, rotation, &format!("EditSeValue{}", row + 6), "SeValue", (row + 6).into(), (494, y, 145, 24));
    }

    for row in 0..3 {
        let y = 13 + row * 38;
        label(form, cutting, &format!("SeCutLabel{row}"), ["X", "Y", "Z"][row as usize], (12, y + 4, 35, 20));
        let slider = add(form, cutting, &format!("SeCutSlider{row}"), "TTrackBar", "", (53, y, 347, 26));
        let control = &mut form.ctl[slider];
        control.tag = row.into();
        control.min = -100;
        control.max = 100;
        control.events.insert("OnChange".into(), "SeCutSlider".into());
        control.events.insert("OnMouseUp".into(), "SeCutSliderUp".into());
        edit(form, cutting, &format!("EditSeCut{row}"), "SeCutValue", row.into(), (425, y, 150, 24));
        let check = add(form, cutting, &format!("SeCutCheck{row}"), "TCheckBox", "Enable", (595, y, 70, 24));
        form.ctl[check].tag = row.into();
        form.ctl[check].events.insert("OnClick".into(), "SeCutCheck".into());
    }
    button(form, cutting, "SeCutMid", "Insert mid values", (53, 139, 203, 27));
    button(form, cutting, "SeCutPick", "Get values from image", (270, 139, 230, 27));
    for control in &mut form.ctl {
        if control.kind == Kind::TrackBar {
            control.fine_track_drag = true;
        }
    }
}

pub(super) fn set_preview_bounds(app: &mut super::Mb3d, ui: &mut Ui) {
    let (ow, oh) = app.navi.orig;
    let aspect = f64::from(ow.max(1)) / f64::from(oh.max(1));
    let w = (400.0 * aspect).round().clamp(1.0, 688.0) as i32;
    let h = (f64::from(w) / aspect).round().clamp(1.0, 400.0) as i32;
    app.navi.scene.width = w;
    app.navi.scene.height = h;
    ui.set_client_size(F, 720, 740);
    let image = ui.cm(F, "Image1");
    image.set_bounds(16 + (688 - w) / 2, 16 + (400 - h) / 2, w, h);
    image.stretch = true;
    image.anchored = false;
}

pub(super) fn sync_camera(ui: &mut Ui, scene: &Scene) {
    for (index, value) in [scene.zoom, scene.z_start, scene.z_end, scene.z_end - scene.z_start].into_iter().enumerate() {
        ui.set_caption(F, &format!("SeCameraValue{index}"), &super::util::float_general(value, 6));
    }
}

pub(super) fn sync_cutting(ui: &mut Ui, scene: &Scene) {
    for (axis, value) in scene.cut_pos.into_iter().enumerate() {
        let enabled = scene.cut_options & (1 << axis) != 0;
        ui.set_text(F, &format!("EditSeCut{axis}"), &fts(value));
        ui.set_checked(F, &format!("SeCutCheck{axis}"), enabled);
        ui.set_enabled(F, &format!("SeCutSlider{axis}"), enabled);
        ui.set_position(F, &format!("SeCutSlider{axis}"), 0);
    }
}

pub(super) fn add_formula_menu(form: &mut Form) {
    use crate::formulas::Formula;
    let root = form.add_control(0, Control::new("SeFormulaMenu", "TPopupMenu"));
    for (label, handler) in [("Search…", "SeSearch"), ("Clear", "SeClearFormula")] {
        let id = add(form, root, handler, "TMenuItem", label, (0, 0, 0, 0));
        form.ctl[id].events.insert("OnClick".into(), handler.into());
    }
    let catalog = crate::formulas::list_custom_with_de().into_iter().chain(
        Formula::all_names().iter().filter_map(|name| {
            let formula = Formula::default_for(name)?;
            Some((name.to_string(), formula.de_option()))
        }),
    );
    let mut groups: [Vec<String>; 7] = Default::default();
    for (name, de) in catalog {
        let category = match de {
            2 | 11 => 1,
            4 => 2,
            5 | 6 => 3,
            -1 | -2 => 4,
            20 => 5,
            21 | 22 => 6,
            _ => 0,
        };
        groups[category].push(name);
    }
    let mut names = Vec::new();
    for (index, ((category, parts), entries)) in
        [("3D", 3), ("3Da", 1), ("4D", 1), ("4Da", 1), ("Ads", 3), ("dIFS", 2), ("dIFSa", 1)]
            .into_iter().zip(&mut groups).enumerate()
    {
        entries.sort_unstable_by_key(|name| name.to_ascii_lowercase());
        entries.dedup_by(|a, b| a.eq_ignore_ascii_case(b));
        for part in 0..parts {
            let entries = &entries[entries.len() * part / parts..entries.len() * (part + 1) / parts];
            if entries.is_empty() { continue; }
            let title = if parts == 1 { category.to_string() }
                else { format!("{category} ({} – {})", entries[0], entries[entries.len() - 1]) };
            let group = add(form, root, &format!("SeFormulaGroup{index}_{part}"), "TMenuItem", &title, (0, 0, 0, 0));
            for name in entries {
                let item = add(form, group, &format!("SeFormulaChoice{}", names.len()), "TMenuItem", name, (0, 0, 0, 0));
                if index != 4 && index != 6 { form.ctl[item].item_height=38; }
                form.ctl[item].events.insert("OnClick".into(), "SeFormulaChoice".into());
                names.push(name.clone());
            }
        }
    }
    names.sort_unstable_by_key(|name| name.to_ascii_lowercase());
    names.dedup_by(|a, b| a.eq_ignore_ascii_case(b));
    form.c_mut("SeFormula").items = names;
}

const FORMULA_SEARCH_FORM: &str = r#"
object SeFormulaSearch: TForm
  Caption = 'Search Formulas'
  BorderStyle = bsDialog
  Position = poScreenCenter
  ClientWidth = 390
  ClientHeight = 320
  object Query: TEdit
    Left = 12
    Top = 10
    Width = 366
    Height = 25
    TabOrder = 0
    OnChange = Filter
  end
  object Results: TListBox
    Left = 12
    Top = 43
    Width = 366
    Height = 231
    TabOrder = 1
    OnDblClick = Choose
  end
  object ChooseButton: TButton
    Left = 210
    Top = 283
    Width = 80
    Height = 25
    Caption = 'Choose'
    Default = True
    TabOrder = 2
    OnClick = Choose
  end
  object CancelButton: TButton
    Left = 298
    Top = 283
    Width = 80
    Height = 25
    Caption = 'Cancel'
    Cancel = True
    TabOrder = 3
    OnClick = Cancel
  end
end
"#;

/// The search dialog remembers its caller so choosing a result cannot edit
/// the other window's independent formula program.
pub(super) fn open_search(ui:&mut Ui,formula_window:bool) {
    ui.fm(SEARCH).ctl[0].tag=i64::from(formula_window);
    ui.set_text(SEARCH,"Query","");
    filter_search(ui);
    ui.show_modal(SEARCH);
    ui.set_focus(SEARCH,"Query");
}

pub(super) fn filter_search(ui: &mut Ui) {
    let query = ui.text(SEARCH, "Query").to_ascii_lowercase();
    let items = ui.c(F, "SeFormula").items.iter().filter(|name| {
        let name = name.to_ascii_lowercase();
        query.split_whitespace().all(|term| name.contains(term))
    }).cloned().collect::<Vec<_>>();
    let found = !items.is_empty();
    ui.set_items(SEARCH, "Results", items);
    ui.set_item_index(SEARCH, "Results", if found { 0 } else { -1 });
    ui.set_enabled(SEARCH, "ChooseButton", found);
}

#[cfg(test)] mod se_windows_wheel_tests {
 use super::*;
 #[test] fn se_windows_formula_wheel_scrolls_instead_of_changing_slider() {
  let mut ui=Ui::default();ui.add_form(include_str!("forms/Navigator.dfm")).unwrap();configure(&mut ui);
  ui.set_active_page(F,"SeNavigatorTabs",FORMULAS);
  let form=ui.fm(F);form.layout();
  let pane=form.id("SeFormulaValuesPane").unwrap();
  let slider=form.id("SeParameterSlider0").unwrap();
  for id in form.ctl[pane].children.clone(){form.ctl[id].visible=true;}
  form.ctl[slider].visible=true;form.focus=Some(slider);form.layout();
  let rect=form.abs_rect(slider);let old=form.ctl[slider].position;
  let events=form.wheel(-120,rect.x+5,rect.y+5,0);
  assert!(events.is_empty());assert!(form.ctl[pane].scroll_y>0);assert_eq!(form.ctl[slider].position,old);
 }
}

pub(super) fn sync_julia_labels(ui:&mut Ui) {
 let names=if ui.checked(F,"CheckBox8") {["Radius","Longitude (°)","Latitude (°)","W"]} else {["X","Y","Z","W"]};
 for (axis,name) in names.into_iter().enumerate(){ui.set_caption(F,&format!("SeJuliaLabel{axis}"),name);}
}
#[cfg(test)] mod se_windows_julia_label_tests {
 use super::*;
 #[test] fn se_windows_julia_coordinate_mode_updates_slider_labels() {
  let mut ui=Ui::default();ui.add_form(include_str!("forms/Navigator.dfm")).unwrap();configure(&mut ui);
  for (spherical,names) in [(true,["Radius","Longitude (°)","Latitude (°)","W"]),(false,["X","Y","Z","W"])] {
   ui.set_checked(F,"CheckBox8",spherical);sync_julia_labels(&mut ui);
   for (axis,name) in names.into_iter().enumerate(){assert_eq!(ui.caption(F,&format!("SeJuliaLabel{axis}")),name);}
  }
 }
}
