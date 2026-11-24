//! Volume transport traces light paths only when needed and remains off by default.
use mb3d::{diagnostics, scene::Scene};
static TEST_LOCK: std::sync::Mutex<()> = std::sync::Mutex::new(());
#[test]
fn volume_transport_traces_only_when_needed_and_round_trips() {
    let _guard=TEST_LOCK.lock().unwrap();
    mb3d::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
    let mut sc=Scene::parse(include_str!("fixtures/transmission-box-opaque.m3s")).unwrap();
    assert!(!sc.subsurface_scattering);
    sc.width=240;sc.height=180;sc.threads=4;
    sc.translucency_enabled=true;sc.transmission_blur=2.;sc.translucency_glow=0.;
    sc.transmission_cache=Some(Default::default());
    let(p,mut g)=mb3d::render::calculate(&sc,&|_,_|{}).unwrap();
    mb3d::render::post_process(&sc,&p,&mut g,4);
    let off=mb3d::render::paint(&sc,&p,&g);
    assert!(sc.transmission_cache.as_ref().unwrap().lock().unwrap().is_some());
    sc.subsurface_scattering=true;
    diagnostics::reset();
    let cached=mb3d::render::paint(&sc,&p,&g);
    let work=diagnostics::snapshot();
    assert!(work.rays>0,"enabling volume transport failed to trace light paths");
    diagnostics::reset();
    assert_eq!(cached,mb3d::render::paint(&sc,&p,&g));
    let work=diagnostics::snapshot();
    assert_eq!(work.rays,0,"unchanged cached transport traced new rays");
    assert_eq!(work.evaluations.iter().sum::<u64>(),0,"unchanged cached transport evaluated geometry");
    assert_ne!(off,cached,"subsurface checkbox had no effect");
    let cache=sc.transmission_cache.take();
    let fresh=mb3d::render::paint(&sc,&p,&g);
    assert_eq!(cached,fresh,"cached subsurface differs from a fresh trace");
    sc.transmission_cache=cache;
    sc.subsurface_amount=0.;diagnostics::reset();
    assert_eq!(off,mb3d::render::paint(&sc,&p,&g),"zero scattering amount changed ordinary translucency");
    assert_eq!(diagnostics::snapshot().rays,0,"zero Amount still traced subsurface light rays");
    sc.subsurface_amount=1.;sc.subsurface_scattering=false;
    assert_eq!(off,mb3d::render::paint(&sc,&p,&g),"turning the experiment off changed ordinary translucency");
    for enabled in [false,true] {
        sc.translucency_enabled=enabled;sc.subsurface_scattering=true;sc.subsurface_amount=0.375;
        let data=mb3d::m3p::write_m3i(&sc,&g);
        let back=mb3d::m3p::parse(&mb3d::m3p::raw_from_m3i(&data).unwrap()).unwrap().scene;
        assert!(back.subsurface_scattering);assert_eq!(back.translucency_enabled,enabled);assert_eq!(back.subsurface_amount,0.375);
    }
    sc.subsurface_scattering=false;
    let legacy=mb3d::m3p::parse(&mb3d::m3p::raw_from_m3i(&mb3d::m3p::write_m3i(&sc,&g)).unwrap()).unwrap().scene;
    assert!(!legacy.subsurface_scattering);
    sc.subsurface_scattering=true;
    assert!(Scene::parse(&sc.to_text()).unwrap().subsurface_scattering);
}

#[test]
fn teapot_transport_preserves_a_compact_specular_highlight() {
    let _guard=TEST_LOCK.lock().unwrap();
    mb3d::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
    let mut sc=Scene::parse(include_str!("fixtures/transmission-teapot.m3s")).unwrap();
    sc.width=240;sc.height=180;sc.threads=4;
    sc.translucency_enabled=true;sc.transmission_blur=1.0048;sc.translucency_glow=0.;sc.subsurface_scattering=false;
    sc.transmission_cache=Some(Default::default());
    let(p,mut g)=mb3d::render::calculate(&sc,&|_,_|{}).unwrap();mb3d::render::post_process(&sc,&p,&mut g,4);
    let off=mb3d::render::paint(&sc,&p,&g);
    sc.subsurface_scattering=true;
    let on=mb3d::render::paint(&sc,&p,&g);
    let channel=|rgb:&[u8],x:usize,y:usize| rgb[(y*240+x)*3];
    let bright=|rgb:&[u8]| (70..157).flat_map(|y|(95..182).map(move |x|(x,y))).filter(|&(x,y)|channel(rgb,x,y)>230).count();
    assert!(bright(&on)<bright(&off)/2,"scattering enlarged the white hotspot");
    assert!(channel(&on,128,127)>channel(&on,140,110)+20,"the specular highlight was blurred away");
}

#[test]
fn scattering_preserves_opaque_board_and_lit_frosted_material() {
    let _guard=TEST_LOCK.lock().unwrap();
    mb3d::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
    let mut sc=Scene::parse(include_str!("fixtures/transmission-clear-box-ao.m3s")).unwrap();
    sc.width=32;sc.height=24;sc.threads=4;sc.mc.reflections=true;
    sc.translucency_enabled=true;sc.transmission_blur=2.;sc.translucency_glow=0.;
    sc.subsurface_scattering=false;sc.subsurface_amount=1.;sc.transmission_cache=Some(Default::default());
    let(p,mut g)=mb3d::render::calculate(&sc,&|_,_|{}).unwrap();mb3d::render::post_process(&sc,&p,&mut g,4);
    let off=mb3d::render::paint(&sc,&p,&g);
    sc.subsurface_scattering=true;let on=mb3d::render::paint(&sc,&p,&g);
    let floor=(22*32+2)*3;assert_eq!(&off[floor..floor+3],&on[floor..floor+3],"scattering altered the opaque board");
    let body=(14*32+20)*3;
    assert!(off[body]>40);
    assert!(on[body] as f32>=off[body] as f32*0.75,"lit frosted material turned dark: {:?} versus {:?}",&on[body..body+3],&off[body..body+3]);
}

#[test]
fn strength_sweep_uses_cache_without_darkening_the_clear_end() {
    let _guard=TEST_LOCK.lock().unwrap();
    mb3d::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
    let mut sc=Scene::parse(include_str!("fixtures/transmission-clear-box-ao.m3s")).unwrap();
    sc.width=32;sc.height=24;sc.threads=4;sc.mc.reflections=true;
    sc.translucency_enabled=true;sc.transmission_blur=2.;sc.translucency_glow=0.;
    sc.subsurface_scattering=true;sc.subsurface_amount=1.;sc.transmission_cache=Some(Default::default());
    let(p,mut g)=mb3d::render::calculate(&sc,&|_,_|{}).unwrap();mb3d::render::post_process(&sc,&p,&mut g,4);
    let opaque=mb3d::render::paint(&sc,&p,&g);let body=(14*32+20)*3;
    for strength in [0.,0.1,0.25,0.5,1.,1.6755,2.] {
        sc.transmission_blur=strength;diagnostics::reset();
        let cached=mb3d::render::paint(&sc,&p,&g);
        let work=diagnostics::snapshot();
        assert_eq!(work.rays,0,"Strength change retraced scattering rays");
        assert_eq!(work.evaluations.iter().sum::<u64>(),0,"Strength change evaluated geometry");
        let mut fresh=sc.clone();fresh.transmission_cache=Some(Default::default());
        assert_eq!(cached,mb3d::render::paint(&fresh,&p,&g),"cached and fresh differ at Strength {strength}");
        assert!(cached[body] as f32 >= opaque[body] as f32*0.6,"dark material at Strength {strength}: {:?}",&cached[body..body+3]);
        if strength==0. {
            fresh.subsurface_scattering=false;fresh.transmission_cache=Some(Default::default());
            assert_eq!(cached,mb3d::render::paint(&fresh,&p,&g),"zero Strength changed ordinary transparency");
        }
    }
}

#[test]
fn backlit_opaque_frosting_does_not_use_unoccluded_internal_light() {
    let _guard=TEST_LOCK.lock().unwrap();
    mb3d::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
    let mut sc=Scene::parse(include_str!("fixtures/transmission-qcyl-backlit.m3s")).unwrap();
    sc.width=96;sc.height=72;sc.threads=4;
    sc.translucency_enabled=true;sc.transmission_blur=1.4597;sc.translucency_glow=0.;
    let(p,mut g)=mb3d::render::calculate(&sc,&|_,_|{}).unwrap();
    mb3d::render::post_process(&sc,&p,&mut g,4);
    for scattering in [false,true] {
        sc.subsurface_scattering=scattering;
        let rgb=mb3d::render::paint(&sc,&p,&g);
        // This opaque, camera-facing patch is lit from behind. The previous
        // directionless internal-light estimate made it nearly full cyan.
        let center=(40*96+48)*3;
        assert!(rgb[center+1]<190,"backlit frosting became luminous (SSS {scattering}): {:?}",&rgb[center..center+3]);
        assert!(rgb[center+1]>20,"backlit frosting lost its ambient illumination");
    }
}

#[test]
fn forward_scattering_brightens_the_backlit_rim_without_flattening_the_center() {
    let _guard=TEST_LOCK.lock().unwrap();
    mb3d::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
    let mut sc=Scene::parse(include_str!("fixtures/transmission-qcyl-alabaster.m3s")).unwrap();
    sc.translucency_enabled=true;sc.transmission_blur=1.867;sc.translucency_glow=0.;
    sc.transmission_cache=Some(Default::default());sc.subsurface_scattering=false;
    let(p,mut g)=mb3d::render::calculate(&sc,&|_,_|{}).unwrap();
    mb3d::render::post_process(&sc,&p,&mut g,4);
    let off=mb3d::render::paint(&sc,&p,&g);
    sc.subsurface_scattering=true;let on=mb3d::render::paint(&sc,&p,&g);
    let mean=|rgb:&[u8],xs:std::ops::Range<usize>,ys:std::ops::Range<usize>| {
        let count=xs.len()*ys.len();
        ys.flat_map(|y|xs.clone().map(move |x|rgb[(y*96+x)*3+1] as f32)).sum::<f32>()/count as f32
    };
    let rim=mean(&on,34..43,26..30);let old_rim=mean(&off,34..43,26..30);
    let center=mean(&on,43..53,42..54);let old_center=mean(&off,43..53,42..54);
    assert!(rim>old_rim+50.&&rim>center*2.,"backlight did not illuminate the thin rim: {old_rim} -> {rim}, center {center}");
    assert!(center<old_center+30.,"scattering washed out the thick center: {old_center} -> {center}");
}

#[test]
fn scene_depth_fog_survives_scattering_and_cached_strength_edits() {
    let _guard=TEST_LOCK.lock().unwrap();
    mb3d::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
    let mut sc=Scene::parse(include_str!("fixtures/transmission-depth-fog.m3s")).unwrap();
    sc.mc.reflections=true;sc.translucency_enabled=true;sc.transmission_blur=1.1888;sc.translucency_glow=0.;
    sc.subsurface_amount=0.8539;sc.subsurface_scattering=false;sc.transmission_cache=Some(Default::default());
    let(p,mut g)=mb3d::render::calculate(&sc,&|_,_|{}).unwrap();
    mb3d::render::post_process(&sc,&p,&mut g,4);
    let ordinary=mb3d::render::paint(&sc,&p,&g);
    sc.subsurface_scattering=true;let scattered=mb3d::render::paint(&sc,&p,&g);
    let check=|image:&[u8]|for x in [3,92] {
        let offset=(3*96+x)*3;
        assert!(image[offset..offset+3].iter().zip(&ordinary[offset..offset+3]).all(|(&a,&b)|a.abs_diff(b)<=1),
            "foreground depth fog disappeared: {:?} instead of {:?}",&image[offset..offset+3],&ordinary[offset..offset+3]);
    };
    check(&scattered);
    for strength in [0.5,1.8] {
        sc.transmission_blur=strength;diagnostics::reset();
        check(&mb3d::render::paint(&sc,&p,&g));
        assert_eq!(diagnostics::snapshot().rays,0,"cached Strength edit traced new rays");
    }
}
