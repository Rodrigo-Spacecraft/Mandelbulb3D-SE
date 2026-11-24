//! A distant transparent box must retain a range of optical thicknesses.
use mb3d::scene::Scene;
fn scene() -> Scene {
    mb3d::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
    let mut sc = Scene::parse(include_str!("fixtures/transmission-box.m3s")).unwrap();
    // These SE extension values are stored in m3i metadata, not legacy m3s text.
    sc.translucency_enabled = true;
    sc.transmission_blur = 0.51;
    sc.translucency_glow = -0.3696;
    sc.threads = 4;
    // The corrected, full-brightness material fill needs highlight headroom:
    // the legacy high ambient setting clips both comparison samples to 255.
    sc.lighting.diffuse *= 0.25;
    sc.lighting.ambient *= 0.25;
    sc
}
fn pixel(rgb: &[u8], x: usize) -> &[u8] { &rgb[(90 * 240 + x) * 3..(90 * 240 + x) * 3 + 3] }
#[test]
fn distant_box_has_clear_lit_edges_and_a_frosted_center() {
    let mut sc = scene();
    sc.transmission_cache = Some(Default::default());
    let (p, mut g) = mb3d::render::calculate(&sc, &|_, _| {}).unwrap();
    mb3d::render::post_process(&sc, &p, &mut g, 4);
    let lit = mb3d::render::paint(&sc, &p, &g);
    // Correctly lit opaque material may be lighter than the transmitted
    // edge. Require visible gradation without requiring the old dark fill.
    let contrast=pixel(&lit,100).iter().zip(pixel(&lit,140)).map(|(&a,&b)|a.abs_diff(b)).max().unwrap();
    eprintln!("edge {:?}, center {:?}, contrast {contrast}",pixel(&lit,100),pixel(&lit,140));
    assert!(contrast>20,"the distant box lost its edge-to-center gradation");
    sc.translucency_glow = 0.;
    let unlit = mb3d::render::paint(&sc, &p, &g);
    let edge_glow = i16::from(pixel(&lit, 110)[1]) - i16::from(pixel(&unlit, 110)[1]);
    let center_glow = i16::from(pixel(&lit, 140)[1]) - i16::from(pixel(&unlit, 140)[1]);
    assert!(edge_glow > center_glow, "short-path glow did not favor the edges");
    sc.transmission_blur = 0.;
    let clear = mb3d::render::paint(&sc, &p, &g);
    sc.translucency_enabled = false;
    assert_eq!(clear, mb3d::render::paint(&sc, &p, &g), "zero controls changed ordinary transparency");
    let mut off = scene();
    off.lighting.lights[1].on = false;
    let dark = mb3d::render::paint(&off, &p, &g);
    assert!(pixel(&lit, 120)[2] > pixel(&dark, 120)[2] + 2, "light 2 did not pass through the thin side of the box");
}

#[test]
fn opaque_translucency_obscures_the_exit_faces() {
    mb3d::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
    let mut sc = Scene::parse(include_str!("fixtures/transmission-box-opaque.m3s")).unwrap();
    sc.translucency_enabled = true;
    sc.transmission_blur = 2.0;
    sc.translucency_glow = 0.0;
    sc.threads = 4;
    sc.transmission_cache = Some(Default::default());
    let (p, mut g) = mb3d::render::calculate(&sc, &|_, _| {}).unwrap();
    mb3d::render::post_process(&sc, &p, &mut g, 4);
    let opaque = mb3d::render::paint(&sc, &p, &g);
    // Each pair lies on one front face, on opposite sides of a visible
    // back-edge in the broken render. Exit-face shading made a >45-level
    // blue discontinuity despite maximum translucency opacity.
    for (x, y0, y1) in [(260, 230, 250), (380, 210, 270)] {
        let a = opaque[(y0 * 480 + x) * 3 + 2];
        let b = opaque[(y1 * 480 + x) * 3 + 2];
        assert!(a.abs_diff(b) < 8, "back-edge remains on front face at {x}: {a} versus {b}");
    }
    sc.transmission_blur = 0.;
    let clear = mb3d::render::paint(&sc, &p, &g);
    assert_ne!(opaque, clear);
    sc.transmission_blur = 2.;
    assert_eq!(opaque, mb3d::render::paint(&sc, &p, &g));
}
