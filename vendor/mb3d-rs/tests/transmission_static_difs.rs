//! Coincident repetitions are one medium; distinct static primitives remain separate.
use mb3d::{render, scene::Scene};

#[test]
fn transparent_teapot_does_not_hit_a_blue_coincident_copy() {
    mb3d::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
    let mut sc=Scene::parse(include_str!("fixtures/transmission-teapot-board.m3s")).unwrap();
    sc.threads=4;sc.mc.reflections=true;sc.translucency_enabled=false;sc.subsurface_scattering=false;
    let (p,mut g)=render::calculate(&sc,&|_,_|{}).unwrap();
    render::post_process(&sc,&p,&mut g,4);
    let rgb=render::paint(&sc,&p,&g);
    let pixel=&rgb[(24*64+32)*3..(24*64+32)*3+3];
    assert!(pixel[0] as i32 > pixel[2] as i32+30 && pixel[1] as i32 > pixel[2] as i32+30,
        "a blue opaque repetition obscured the yellow board through the teapot: {pixel:?}");
    // Primary geometry remains independent of the transparency setting.
    sc.mc.transparency=false;
    let (p2,mut g2)=render::calculate(&sc,&|_,_|{}).unwrap();
    render::post_process(&sc,&p2,&mut g2,4);
    assert_eq!(g,g2);
}

#[test]
fn clear_box_does_not_cast_an_opaque_ambient_shadow_on_the_board_inside() {
    mb3d::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
    let mut sc=Scene::parse(include_str!("fixtures/transmission-clear-box-ao.m3s")).unwrap();
    sc.threads=4;sc.mc.reflections=true;sc.translucency_enabled=false;sc.subsurface_scattering=false;
    assert!(sc.ao.is_some());
    let (p,mut g)=render::calculate(&sc,&|_,_|{}).unwrap();render::post_process(&sc,&p,&mut g,4);
    let shaded=render::paint(&sc,&p,&g);
    sc.ao=None;
    let no_secondary_ao=render::paint(&sc,&p,&g);
    let at=(29*64+40)*3;
    eprintln!("board through clear box: AO {:?}, no secondary AO {:?}",&shaded[at..at+3],&no_secondary_ao[at..at+3]);
    assert!(shaded[at] as f32 >= no_secondary_ao[at] as f32*0.65,
        "the clear enclosure acts like an opaque AO blocker: {:?} versus {:?}",&shaded[at..at+3],&no_secondary_ao[at..at+3]);
}

#[test]
fn transparent_heightmap_torus_does_not_hit_an_opaque_blue_repetition() {
    mb3d::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
    mb3d::maps::add_map_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Maps"));
    let mut sc=Scene::parse(include_str!("fixtures/transmission-heightmap-torus.m3s")).unwrap();
    sc.threads=4;sc.mc.reflections=true;sc.translucency_enabled=false;sc.subsurface_scattering=false;
    let (p,mut g)=render::calculate(&sc,&|_,_|{}).unwrap();render::post_process(&sc,&p,&mut g,4);
    let rgb=render::paint(&sc,&p,&g);let at=(21*64+45)*3;let pixel=&rgb[at..at+3];
    assert!(pixel[0] as i32>pixel[2] as i32+20 && pixel[1] as i32>pixel[2] as i32+20,
        "height-map torus hit a blue opaque copy: {pixel:?}");
}
