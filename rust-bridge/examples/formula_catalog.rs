//! Metadata from the same formula loader used to render. No GUI or network.
use mb3d::formulas::{self, Formula};
fn main() {
    let dir = std::fs::canonicalize("rust-assets/M3Formulas").unwrap();
    formulas::add_formula_dir(dir.clone());
    let mut names: Vec<(String, i32)> = Formula::all_names().iter().enumerate()
        .map(|(i,n)|(n.to_string(), [0,1,2,3,4,5,6,9][i])).collect();
    for entry in std::fs::read_dir(dir).unwrap() {
        let p=entry.unwrap().path();
        if p.extension().is_some_and(|e|e.eq_ignore_ascii_case("m3f")) {
            let n=p.file_stem().unwrap().to_string_lossy().into_owned();
            if !names.iter().any(|(a,_)|a.eq_ignore_ascii_case(&n)){names.push((n,20));}
        }
    }
    names.sort_by_key(|(n,_)|n.to_ascii_lowercase());
    for (name,id) in names {
        let f=formulas::lookup(&name).unwrap_or_else(|e|panic!("{name}: {e}"));
        let opts=f.options();assert!(opts.len()<=16,"{name} has too many options");
        println!("F\t{id}\t{name}\t{}\t{}",f.de_option(),f.default_rstop());
        for ((n,v),ty) in opts.into_iter().zip(f.option_types()) {
            assert!(v.is_finite());
            println!("P\t{ty}\t{v}\t{}",n.replace(['\t','\n','\r']," "));
        }
    }
}
