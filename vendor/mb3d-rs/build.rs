use std::{collections::BTreeMap,env,fs,path::PathBuf};
fn main() {
 let engine=PathBuf::from(env::var_os("CARGO_MANIFEST_DIR").unwrap());
 let mut catalog=BTreeMap::new();
 if env::var_os("CARGO_FEATURE_SE_DESKTOP").is_some() {
  for root in [engine.join("M3Formulas-rs"),engine.join("../../rust-assets/M3Formulas")] {
   println!("cargo:rerun-if-changed={}",root.display());
   for entry in fs::read_dir(&root).unwrap_or_else(|e|panic!("{}: {e}",root.display())) {
    let path=entry.unwrap().path();
    if path.extension().is_some_and(|e|e.eq_ignore_ascii_case("m3f")) {
     let name=path.file_stem().unwrap().to_string_lossy().into_owned();
     catalog.insert(name.to_ascii_lowercase(),(name,path.canonicalize().unwrap()));
    }
   }
  }
  assert!(!catalog.is_empty(),"SE builds require the embedded formula catalog");
 }
 let mut source=String::from("pub static CATALOG: &[(&str, &[u8])] = &[\n");
 for (_, (name,path)) in catalog {source.push_str(&format!("({name:?}, include_bytes!({:?})),\n",path.to_string_lossy()));}
 source.push_str("];\n");
 fs::write(PathBuf::from(env::var_os("OUT_DIR").unwrap()).join("embedded_formulas.rs"),source).unwrap();
 println!("cargo:rerun-if-env-changed=CARGO_FEATURE_SE_DESKTOP");
}
