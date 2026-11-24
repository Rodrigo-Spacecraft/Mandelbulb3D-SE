//! SE main-window Camera tab, using the existing scene controls.

use super::util::{fts, parse_float};
use super::MAIN;
use crate::math::{build_rot_matrix, matrix_to_angles, normalise_matrix_to, Mat3};
use crate::vcl::control::Control;
use crate::vcl::form::Form;
use crate::vcl::Ui;

const POSITION: [&str; 7] = ["Edit9", "Edit10", "Edit17", "Edit1", "Edit3", "Edit5", "Edit14"];
const ROTATION: [&str; 3] = ["Edit27", "Edit31", "Edit32"];

#[derive(Clone)]
pub(super) struct CameraCopy {
    position: [String; 7],
    rotation: Mat3,
}

impl CameraCopy {
    pub(super) fn read(ui: &Ui, current: Mat3) -> Option<Self> {
        let position = POSITION.map(|field| ui.text(MAIN, field));
        for value in &position {
            finite_number(value)?;
        }
        Some(Self { position, rotation: edited_rotation(ui, current)? })
    }

    pub(super) fn restore(&self, ui: &mut Ui) -> Mat3 {
        for (field, value) in POSITION.into_iter().zip(&self.position) {
            ui.set_text(MAIN, field, value);
        }
        self.rotation
    }
}

fn finite_number(text: &str) -> Option<f64> {
    parse_float(text).filter(|value| value.is_finite())
}

pub(super) fn angle_text(rotation: Mat3) -> [String; 3] {
    let angles = matrix_to_angles(&rotation).unwrap_or_else(|| {
        // At gimbal lock the rotation can be represented with Z set to zero.
        let m = normalise_matrix_to(1.0, &rotation);
        let y = m[0][2].clamp(-1.0, 1.0).asin();
        [(m[1][0] * y.signum()).atan2(m[1][1]), y, 0.0]
    });
    angles.map(|angle| fts(angle.to_degrees()))
}

pub(super) fn edited_rotation(ui: &Ui, current: Mat3) -> Option<Mat3> {
    let fields = ROTATION.map(|field| ui.text(MAIN, field));
    if fields == angle_text(current) {
        return Some(current);
    }
    let [x, y, z] = fields.each_ref().map(|field| finite_number(field).map(f64::to_radians));
    Some(build_rot_matrix(x?, y?, z?))
}

pub(super) fn show_rotation(ui: &mut Ui, rotation: Mat3) {
    for (field, value) in ROTATION.into_iter().zip(angle_text(rotation)) {
        ui.set_text(MAIN, field, &value);
    }
}

pub(super) fn configure(form: &mut Form) {
    let camera = form.id("TabSheet1").expect("main window has a Camera tab");
    for name in ["PositionBtn", "RotationBtn", "PositionPnl", "RotationPnl"] {
        form.c_mut(name).visible = false;
    }
    form.c_mut("Panel1").width = 258;
    form.c_mut("TabSheet2").caption = "Calc".into();
    form.c_mut("TabSheet5").caption = "Info".into();
    form.c_mut("TabSheet4").caption = "Settings".into();

    let pages = form.id("PageControl1").expect("main window has tabs");
    let first = ["TabSheet2", "TabSheet1", "TabSheet5", "TabSheet4"]
        .map(|name| form.id(name).expect("main window tab exists"));
    // Keep the remaining legacy tabs available during the port.
    let tabs = &mut form.ctl[pages].children;
    tabs.retain(|id| !first.contains(id));
    tabs.splice(..0, first);

    for (row, (label, field, caption)) in [
        ("Label9", "Edit9", "X mid"),
        ("Label10", "Edit10", "Y mid"),
        ("SpeedButton32", "Edit17", "Z mid"),
        ("SpeedButton33", "Edit1", "Z start"),
        ("SpeedButton34", "Edit3", "Z end"),
        ("Label5", "Edit5", "Zoom"),
        ("Label54", "Edit27", "X rot (°)"),
        ("Label55", "Edit31", "Y rot (°)"),
        ("Label56", "Edit32", "Z rot (°)"),
        ("Label21", "Edit14", "FOV Y (°)"),
    ].into_iter().enumerate() {
        let (x, y) = if row < 6 { (5, 8 + 24 * row as i32) } else { (130, 8 + 24 * (row as i32 - 6)) };
        move_to_camera(form, camera, label, (x, y + 2, 48, 18));
        form.c_mut(label).caption = caption.into();
        move_to_camera(form, camera, field, (x + 50, y, 68, 21));
        let edit = form.c_mut(field);
        edit.tab_order = row as i32;
        if ROTATION.contains(&field) {
            edit.events.insert("OnChange".into(), "CameraAngleChange".into());
            edit.hint = "Camera rotation in degrees".into();
        }
    }
    for (name, caption, x) in [("SpeedButton30", "Get mid", 5), ("SpeedButton31", "Reset", 65)] {
        move_to_camera(form, camera, name, (x, 154, 56, 21));
        form.c_mut(name).caption = caption.into();
    }
    move_to_camera(form, camera, "RadioGroup2", (130, 105, 118, 94));
    form.c_mut("RadioGroup2").caption = "Camera lens".into();
    form.c_mut("RadioGroup2").tab_order = 12;

    for (name, caption, x, tab_order) in [
        ("CameraCopy", "Copy", 5, 10),
        ("CameraPaste", "Paste", 65, 11),
    ] {
        let mut button = Control::new(name, "TButton");
        button.set_bounds(x, 178, 56, 21);
        button.caption = caption.into();
        button.tab_order = tab_order;
        button.enabled = name == "CameraCopy";
        button.events.insert("OnClick".into(), name.into());
        form.add_control(camera, button);
    }
}

fn move_to_camera(form: &mut Form, camera: usize, name: &str, bounds: (i32, i32, i32, i32)) {
    let id = form.id(name).expect("camera control exists");
    let parent = form.ctl[id].parent.expect("camera control has a parent");
    if parent != camera {
        form.ctl[parent].children.retain(|&child| child != id);
        form.ctl[camera].children.push(id);
        form.ctl[id].parent = Some(camera);
    }
    let control = &mut form.ctl[id];
    control.set_bounds(bounds.0, bounds.1, bounds.2, bounds.3);
    control.anchored = false;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn camera_controls_fit_and_copy_restores_the_exact_view() {
        let mut ui = Ui::default();
        ui.add_form(include_str!("forms/Mand.dfm")).unwrap();
        configure(ui.fm(MAIN));
        ui.set_active_page(MAIN, "PageControl1", "TabSheet1");
        let form = ui.fm(MAIN);
        form.layout();
        let tab = form.id("TabSheet1").unwrap();
        let bounds = form.abs_rect(tab);
        for name in POSITION.into_iter().chain(ROTATION).chain(["CameraCopy", "CameraPaste", "RadioGroup2"]) {
            let id = form.id(name).unwrap();
            assert!(form.showing(id), "{name}");
            let rect = form.abs_rect(id);
            assert!(bounds.contains(rect.x, rect.y), "{name}");
            assert!(bounds.contains(rect.right() - 1, rect.bottom() - 1), "{name}");
        }
        assert!(!ui.enabled(MAIN, "CameraPaste"));

        let rotation = build_rot_matrix(0.2, std::f64::consts::FRAC_PI_2, -0.3);
        show_rotation(&mut ui, rotation);
        ui.set_text(MAIN, "Edit14", "42.5");
        let copy = CameraCopy::read(&ui, rotation).unwrap();
        ui.set_text(MAIN, "Edit14", "25");
        ui.set_text(MAIN, "Edit31", "0");
        assert_ne!(edited_rotation(&ui, rotation), Some(rotation));
        assert_eq!(copy.restore(&mut ui), rotation);
        assert_eq!(ui.text(MAIN, "Edit14"), "42.5");

        ui.set_text(MAIN, "Edit31", "NaN");
        assert!(CameraCopy::read(&ui, rotation).is_none());
    }
}
