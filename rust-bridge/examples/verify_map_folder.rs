//! Smoke test: cargo run --release --example verify_map_folder -- <fixture-dir>
use std::path::PathBuf;
fn main() {
    let folder = PathBuf::from(std::env::args_os().nth(1).expect("fixture folder"));
    let background_folder=std::env::args_os().nth(2);
    if let Some(ref path)=background_folder {std::env::set_var("MB3DX_BACKGROUND_DIR",path);}
    std::env::set_var("MB3DX_MAP_DIR", &folder);
    assert_eq!(mb3d::maps::find_map_file(9876), Some(folder.join("9876.png")));
    assert_eq!(mb3d::maps::with_map(9876, |m| (m.width,m.height)), Some((8,8)));
    let background=mb3d::maps::background("9876.png",0).expect("background map");
    assert_eq!((background.width,background.height),if background_folder.is_some(){(16,16)}else{(8,8)});
    println!("Rust numbered and background maps load from the configured Maps folder.");
}
