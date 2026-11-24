//! Credits and license windows, matching the SE Mac About content.
use super::{Mb3d, Ui};
use crate::vcl::control::Control;
use crate::vcl::font::Font;

pub(super) const ABOUT: &str = "SeAboutForm";
pub(super) const LICENSES: &str = "SeLicensesForm";

fn text(ui: &mut Ui, name: &str, content: &str, x: i32, y: i32, width: i32, height: i32) {
    let mut control = Control::new(name, "TLabel");
    control.caption = content.into();
    control.set_bounds(x, y, width, height);
    control.auto_size = false;
    control.word_wrap = true;
    control.font = Some(Font { height: -13, ..Default::default() });
    ui.fm(ABOUT).add_control(0, control);
}

fn link(ui: &mut Ui, name: &str, content: &str, x: i32, y: i32, width: i32) {
    text(ui, name, content, x, y, width, 22);
    let control = ui.cm(ABOUT, name);
    control.cursor = "crHandPoint".into();
    control.font = Some(Font { height: -13, color: 0xFF0066CC, custom_color: true, underline: true, ..Default::default() });
    control.events.insert("OnClick".into(), name.into());
}

fn button(ui: &mut Ui, form: &str, name: &str, title: &str, x: i32, y: i32) {
    let mut control = Control::new(name, "TButton");
    control.caption = title.into();
    control.set_bounds(x, y, 100, 30);
    control.events.insert("OnClick".into(), name.into());
    ui.fm(form).add_control(0, control);
}

pub(super) fn show(ui: &mut Ui) {
    if !ui.has_form(ABOUT) {
        ui.add_form("object SeAboutForm: TForm
 Caption = 'About Mandelbulb3D SE'
 ClientWidth = 700
 ClientHeight = 510
 BorderStyle = bsDialog
 Position = poScreenCenter
end").unwrap();
        let mut icon = Control::new("AppIcon", "TImage");
        icon.set_bounds(24, 24, 64, 64);
        icon.picture = crate::vcl::paint::decode_ico(include_bytes!("../../assets/m3d-se.ico"), 64);
        ui.fm(ABOUT).add_control(0, icon);
        text(ui, "Title", "Mandelbulb3D SE", 104, 24, 560, 28);
        ui.cm(ABOUT,"Title").font = Some(Font { height: -19, bold: true, ..Default::default() });
        text(ui, "Version", &format!("Version {}", option_env!("MB3D_SE_BUILD").unwrap_or("2.0.3")), 104, 62, 560, 22);
        text(ui, "SupportLabel", "Support:", 104, 99, 58, 22);
        link(ui, "SeAboutSupport", "https://greenoak-software.com/m3dse_support.html", 165, 99, 500);
        text(ui, "Author", "Application, interface, and additional rendering features by Glenn Olander.", 104, 139, 560, 36);
        link(ui, "SeAboutCommunity", "www.facebook.com/RodrigoSpacecraft", 104, 176, 560);
        text(ui, "Original", "Based on Mandelbulb3D, originally developed by Jesse, with contributions from the Mandelbulb3D community.", 104, 216, 560, 40);
        text(ui, "Engine", "Rendering engine adapted from mb3d-rs by Sebastian Paluch.", 104, 276, 560, 22);
        text(ui, "Formulas", "Includes formulas by their respective authors.", 104, 316, 560, 22);
        text(ui, "PrivacyLabel", "Privacy policy:", 104, 356, 90, 22);
        link(ui, "SeAboutPrivacy", "https://greenoak-software.com/PrivacyPolicy.html", 198, 356, 465);
        text(ui, "SourceLabel", "Source code:", 104, 396, 90, 22);
        link(ui, "SeAboutSource", "https://github.com/Rodrigo-Spacecraft/Mandelbulb3D-SE/tree/rel5", 104, 420, 560);
        button(ui, ABOUT, "SeAboutLicenses", "Licenses…", 456, 464);
        button(ui, ABOUT, "SeAboutClose", "OK", 568, 464);
        ui.cm(ABOUT,"SeAboutClose").default = true;
        ui.cm(ABOUT,"SeAboutClose").cancel = true;
    }
    ui.show(ABOUT);
}

fn licenses(ui: &mut Ui) {
    if !ui.has_form(LICENSES) {
        ui.add_form("object SeLicensesForm: TForm
 Caption = 'Licenses and third-party notices'
 ClientWidth = 690
 ClientHeight = 500
 BorderStyle = bsDialog
 Position = poScreenCenter
end").unwrap();
        let mut content = Control::new("LicenseText","TMemo");
        content.set_bounds(16,16,658,430);
        content.read_only = true;
        content.word_wrap = true;
        content.text = [
            ("ThirdPartyNotices.txt", include_str!("../../../../resources/Licenses/ThirdPartyNotices.txt")),
            ("LGPL-2.1.txt", include_str!("../../../../resources/Licenses/LGPL-2.1.txt")),
            ("GPL-2.0.txt", include_str!("../../../../resources/Licenses/GPL-2.0.txt")),
            ("Map-terms.txt", include_str!("../../../../resources/Licenses/Map-terms.txt")),
        ].into_iter().map(|(name, body)| format!("{name}

{body}")).collect::<Vec<_>>().join("

");
        ui.fm(LICENSES).add_control(0,content);
        button(ui,LICENSES,"SeLicensesClose","OK",574,458);
        ui.cm(LICENSES,"SeLicensesClose").cancel = true;
        ui.cm(LICENSES,"SeLicensesClose").default = true;
    }
    ui.show(LICENSES);
}

pub(super) fn event(_app: &mut Mb3d, ui: &mut Ui, handler: &str) {
    let url = match handler {
        "SeAboutClose" => { ui.hide(ABOUT); return; }
        "SeLicensesClose" => { ui.hide(LICENSES); return; }
        "SeAboutLicenses" => { licenses(ui); return; }
        "SeAboutSupport" => "https://greenoak-software.com/m3dse_support.html",
        "SeAboutCommunity" => "https://www.facebook.com/RodrigoSpacecraft",
        "SeAboutPrivacy" => "https://greenoak-software.com/PrivacyPolicy.html",
        "SeAboutSource" => "https://github.com/Rodrigo-Spacecraft/Mandelbulb3D-SE/tree/rel5",
        _ => return,
    };
    if let Err(error) = open::that_detached(url) {
        ui.show_message(&format!("Could not open the link: {error}"));
    }
}
