fn main() {
    mb3d::formulas::add_formula_dir(std::fs::canonicalize("rust-assets/M3Formulas").unwrap());
    let path=std::env::args().nth(1).expect("scene path");
    let bytes=std::fs::read(path).unwrap();
    let raw=mb3d::m3p::raw_from_m3i(&bytes).unwrap();
    let mut sc=mb3d::m3p::parse(&raw).unwrap().scene;
    let p=mb3d::calc::CalcParams::new(&sc).unwrap();
    for light in &mut sc.lighting.lights {light.hs_enabled=false;}
    assert!(mb3d::render::shadow_job(&sc,&p).is_none());
    sc.lighting.lights[0].hs_enabled=true;
    sc.lighting.lights[0].on=true;
    assert!(mb3d::render::shadow_job(&sc,&p).is_some());
    println!("Ignored lights excluded; enabled shadow light retained.");
}
