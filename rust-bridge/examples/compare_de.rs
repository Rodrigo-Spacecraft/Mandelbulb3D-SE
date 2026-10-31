//! Diagnostic world-space samples: parameter file on argv, XYZ lines on stdin.
//! MB3D_FORMULAS selects the bundled formula directory.
use std::io::{self, BufRead};
fn main() {
    let path = std::env::args().nth(1).expect("parameter file");
    let sc = mb3d::m3p::load(std::path::Path::new(&path)).unwrap().scene;
    let p = mb3d::calc::CalcParams::new(&sc).unwrap();
    let correction = p.d_col_plus as f64 + p.col_var_de_stop_mul as f64 * (p.de_stop as f64 * p.step_width).ln();
    eprintln!("Rust: {}x{}, iterations {}, DE {}, repeat {}, color correction {}", p.width,p.height,p.max_it,p.de_option,p.repeat_from,correction);
    for line in io::stdin().lock().lines() {
        let line=line.unwrap();let v:Vec<f64>=line.split_whitespace().map(|s|s.parse().unwrap()).collect();
        if v.len()<3 {continue;}
        let mut m=mb3d::calc::Marcher::new(&p,1);m.it.c=[v[0],v[1],v[2]];m.it.calc_sit=true;
        let d=m.calc_de()*p.step_width;
        println!("{:.17e} {:.17e} {:.17e} {:.17e}",d,m.it.smooth_it,m.it.otrap,correction);
    }
}
