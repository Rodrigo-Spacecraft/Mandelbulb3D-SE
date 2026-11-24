//! Regressions for an opaque DIFS ring lying inside a transparent sphere.
//! The normal union has no internal boundary; transmission needs the
//! individual repeated DIFS instances without changing primary geometry.
use mb3d::{
    calc::{de_at, CalcParams, Marcher},
    scene::Scene,
};
fn scene() -> Scene {
    let root =
        std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas");
    mb3d::formulas::add_formula_dir(root);
    Scene::parse(include_str!("fixtures/transmission-overlap.m3s")).unwrap()
}
#[test]
fn internal_opaque_boundary_survives_transmission_through_union() {
    let sc = scene();
    let p = CalcParams::new(&sc).unwrap();
    // An opaque repeated ring is inside DIFS instance 2's sphere.
    let point = [
        0.5455753236608684,
        -0.0035550108094156013,
        -0.056738455556513356,
    ];
    assert!(de_at(&p, point).0 < -0.05);
    let mut m = Marcher::new(&p, 1);
    let mut inside = vec![2];
    let mut distance = 0.;
    // More than one repeated sphere contains this point. Enter each
    // overlapping volume before asking for the ring's internal boundary.
    for _ in 0..sc.iterations {
        m.it.difs_inside_components = Some(inside.clone());
        distance = m.de_at_point(point, false) * p.step_width;
        if distance >= 0. {
            break;
        }
        assert!(!inside.contains(&m.it.it_result));
        inside.push(m.it.it_result);
    }
    assert!(
        (0.0..0.01).contains(&distance),
        "internal ring distance {distance}"
    );
    assert!(
        !inside.contains(&m.it.it_result),
        "selected a containing sphere instead of the ring"
    );
}
#[test]
fn transmission_sees_the_ring_and_is_thread_independent() {
    let mut sc = scene();
    sc.threads = 1;
    let (p, g) = mb3d::render::calculate(&sc, &|_, _| {}).unwrap();
    let rgb = mb3d::render::paint(&sc, &p, &g);
    let pixel = &rgb[(26 * 64 + 36) * 3..(26 * 64 + 36) * 3 + 3];
    assert!(
        pixel[2] > pixel[1] + 25 && pixel[2] > pixel[0] + 50,
        "sphere hides internal blue ring: {pixel:?}"
    );
    sc.threads = 3;
    assert_eq!(rgb, mb3d::render::paint(&sc, &p, &g));
    sc.mc.transparency = false;
    let opaque = mb3d::render::paint(&sc, &p, &g);
    assert_ne!(rgb, opaque);
    assert!(opaque[(26 * 64 + 36) * 3 + 1] > opaque[(26 * 64 + 36) * 3 + 2]);
}
#[test]
fn transmitted_internal_object_is_retained_for_cached_recomposition() {
    let mut sc = scene();
    sc.translucency_enabled = true;
    sc.transmission_cache = Some(Default::default());
    let (p, g) = mb3d::render::calculate(&sc, &|_, _| {}).unwrap();
    let original = mb3d::render::paint(&sc, &p, &g);
    assert!(sc
        .transmission_cache
        .as_ref()
        .unwrap()
        .lock()
        .unwrap()
        .is_some());
    assert_eq!(original, mb3d::render::paint(&sc, &p, &g));
    sc.transmission_blur = 2.;
    assert_ne!(original, mb3d::render::paint(&sc, &p, &g));
}

#[test]
fn placeholder_geometry_is_not_a_saved_render() {
    let sc = scene();
    let background = vec![mb3d::gbuffer::SiLight::default(); (sc.width * sc.height) as usize];
    let data = mb3d::m3p::write_m3i(&sc, &background);
    assert!(mb3d::m3p::gbuffer_from_m3i(&data).is_some());
    let mut empty = background;
    for p in &mut empty { p.zpos_fine = 0; }
    let data = mb3d::m3p::write_m3i(&sc, &empty);
    assert!(mb3d::m3p::gbuffer_from_m3i(&data).is_none());
}
