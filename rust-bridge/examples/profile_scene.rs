use std::{path::Path,time::Instant};
fn main(){
 let args:Vec<_>=std::env::args().collect();let path=Path::new(&args[1]);
 mb3d::formulas::add_formula_dir(std::fs::canonicalize("rust-assets/M3Formulas").unwrap());
 if let Some(home)=std::env::var_os("HOME"){mb3d::maps::add_map_dir(Path::new(&home).join("M3D/M3Maps"));}
 #[cfg(feature="gpu")]mb3d::gpu::set_enabled(mb3d::gpu::default_on());
 let bytes=std::fs::read(path).unwrap();let raw=if path.extension().is_some_and(|x|x=="m3p"){bytes}else{mb3d::m3p::raw_from_m3i(&bytes).unwrap()};let mut sc=mb3d::m3p::parse(&raw).unwrap().scene;
 sc.slice_2d=0;if args.len()>2{sc.width=args[2].parse().unwrap();sc.height=args[3].parse().unwrap();}
 if let Ok(n)=std::env::var("MB3DX_THREADS"){sc.threads=n.parse().unwrap();}
 if let Ok(out)=std::env::var("MB3DX_SCENE_TEXT"){std::fs::write(out,sc.to_text()).unwrap();}
 if std::env::var_os("MB3DX_INSPECT").is_some(){println!("{}",sc.to_text());return;}
 let start=Instant::now();let result=mb3d::render::render(&sc,&|_,_|{}).unwrap();eprintln!("Direct Rust: calculate/post {:.4}s, paint {:.4}s, total {:.4}s, {}x{}",result.calc_seconds,result.paint_seconds,start.elapsed().as_secs_f64(),result.width,result.height);
 if let Ok(out)=std::env::var("MB3DX_RGB_DUMP"){std::fs::write(out,result.rgb).unwrap();}
}
