//! Independent, single-threaded formula previews and a persistent disk cache.
use crate::{formulas::{self,Formula},scene::{Scene,FormulaEntry},vcl::{Ui,bitmap::Bitmap}};
use std::{collections::HashMap,path::{Path,PathBuf},sync::{Mutex,OnceLock,mpsc},time::{Duration,Instant}};
struct State { incoming:mpsc::Receiver<(String,Bitmap)>, images:HashMap<String,Bitmap>, last_apply:Instant }
static STATE:OnceLock<Mutex<State>>=OnceLock::new();
fn eligible(de:i32)->bool { !matches!(de,-1|-2|21|22) }
fn cache_path(root:&Path,name:&str,source:&[u8])->PathBuf {
 let hash=b"formula64-default-camera-v1".iter().copied().chain(name.bytes()).chain(source.iter().copied())
  .fold(14695981039346656037u64,|h,b|(h^b as u64).wrapping_mul(1099511628211));
 root.join(format!("{hash:016x}.argb"))
}
fn read_cache(path:&Path)->Option<Bitmap> {
 let bytes=std::fs::read(path).ok()?;
 if bytes.len()!=4100||&bytes[..4]!=b"FT01" {return None;}
 Some(Bitmap{w:32,h:32,px:bytes[4..].chunks_exact(4).map(|v|u32::from_le_bytes(v.try_into().unwrap())).collect()})
}
fn write_cache(path:&Path,image:&Bitmap) {
 let mut bytes=b"FT01".to_vec();for p in &image.px {bytes.extend_from_slice(&p.to_le_bytes());}
 if let Some(parent)=path.parent(){if std::fs::create_dir_all(parent).is_err(){return;}}
 let tmp=path.with_extension(format!("{}.tmp",std::process::id()));
 if std::fs::write(&tmp,bytes).is_ok(){
  if path.exists(){let _=std::fs::remove_file(path);}
  let _=std::fs::rename(&tmp,path);
 }
}
fn preview(name:&str)->Option<Bitmap> {
 let formula=formulas::lookup(name).ok()?;
 if !eligible(formula.de_option()){return None;}
 let mut scene=Scene::preset("Integer Power").ok()?;
 scene.width=64;scene.height=64;scene.de_stop=1./15.;scene.iterations=60;scene.threads=1;
 scene.formulas=vec![FormulaEntry{formula,iterations:1}];
 scene.shadows=None;scene.ao=None;scene.deao=None;scene.mc.reflections=false;scene.dof=None;
 let start=Instant::now();let cancel=||start.elapsed()>Duration::from_secs(10);
 let (params,gbuf)=crate::render::calculate_cancellable(&scene,&|_,_|{},&cancel).ok()?;
 let rgb=crate::render::paint_cancellable(&scene,&params,&gbuf,&cancel).ok()?;
 let (rgb,w,h)=crate::render::downsample(&rgb,64,64,2);
 Some(Bitmap::from_rgb(w,h,&rgb))
}
fn work(send:mpsc::Sender<(String,Bitmap)>,wake:Option<crate::vcl::ui::Waker>) {
 #[cfg(windows)] unsafe {
  #[link(name="kernel32")] unsafe extern "system" {fn GetCurrentThread()->*mut std::ffi::c_void;fn SetThreadPriority(thread:*mut std::ffi::c_void,priority:i32)->i32;}
  SetThreadPriority(GetCurrentThread(),0x10000); // background mode
 }
 let root=std::env::var_os("LOCALAPPDATA").or_else(||std::env::var_os("XDG_CACHE_HOME")).map(PathBuf::from)
  .unwrap_or_else(std::env::temp_dir).join("Mandelbulb3D SE/Cache/FormulaThumbnails");
 let mut names=formulas::list_custom_with_de();
 names.extend(Formula::all_names().iter().filter_map(|n|Formula::default_for(n).map(|f|(n.to_string(),f.de_option()))));
 names.retain(|(_,de)|eligible(*de));names.sort_by_key(|(n,_)|n.to_ascii_lowercase());names.dedup_by(|a,b|a.0.eq_ignore_ascii_case(&b.0));
 let mut missing=Vec::new();
 // Publish every cached image before starting any new render.
 for (name,_) in names {
  let source=formulas::custom_path(&name).and_then(|p|std::fs::read(p).ok()).or_else(||formulas::embedded_bytes(&name).map(|b|b.to_vec())).unwrap_or_default();
  let path=cache_path(&root,&name,&source);
  if let Some(image)=read_cache(&path) {if send.send((name,image)).is_err(){return;}if let Some(w)=&wake{w.wake();}}
  else {missing.push((name,path));}
 }
 for (name,path) in missing {
  let image=std::panic::catch_unwind(||preview(&name)).ok().flatten();
  if let Some(image)=image {write_cache(&path,&image);if send.send((name,image)).is_err(){return;}if let Some(w)=&wake{w.wake();}}
 }
}
pub(super) fn idle(ui:&mut Ui) {
 let state=STATE.get_or_init(||{
  let (send,incoming)=mpsc::channel();let wake=ui.waker();
  let _=std::thread::Builder::new().name("formula-thumbnails".into()).spawn(move||work(send,wake));
  Mutex::new(State{incoming,images:HashMap::new(),last_apply:Instant::now()-Duration::from_secs(1)})
 });
 let Ok(mut state)=state.lock() else{return;};let mut changed=false;
 while let Ok((name,image))=state.incoming.try_recv(){state.images.insert(name,image);changed=true;}
 if !changed&&state.last_apply.elapsed()<Duration::from_millis(500){return;}
 state.last_apply=Instant::now();
 attach(ui,&state.images);
}
fn attach(ui:&mut Ui,images:&HashMap<String,Bitmap>) {
 for form in &mut ui.forms {for c in &mut form.ctl {
  if c.name.starts_with("SeFormulaChoice")&&c.picture.is_none(){if let Some(image)=images.get(&c.caption){c.picture=Some(image.clone());form.dirty=true;}}
 }}
}
#[cfg(test)] mod tests {
 use super::*;
 #[test] fn se_windows_formula_images_attach_to_both_formula_menus() {
  let mut ui=Ui::default();let image=Bitmap::new(32,32,0xff123456);
  for name in ["FNavigator","FormulaGUIForm"] {
   ui.add_form(&format!("object {name}: TForm\n ClientWidth = 400\n ClientHeight = 300\nend")).unwrap();
   let mut item=crate::vcl::control::Control::new("SeFormulaChoice0","TMenuItem");item.caption="Integer Power".into();ui.fm(name).add_control(0,item);
  }
  attach(&mut ui,&HashMap::from([("Integer Power".into(),image.clone())]));
  for name in ["FNavigator","FormulaGUIForm"] {assert_eq!(ui.c(name,"SeFormulaChoice0").picture,Some(image.clone()));}
 }
 #[test] fn se_windows_formula_cache_roundtrip_and_source_invalidation() {
  let root=std::env::temp_dir().join(format!("formula-cache-test-{}",std::process::id()));
  let path=cache_path(&root,"test",b"first");assert_ne!(path,cache_path(&root,"test",b"changed"));
  let image=Bitmap::new(32,32,0xff123456);write_cache(&path,&image);assert_eq!(read_cache(&path),Some(image));
  std::fs::write(&path,b"incomplete").unwrap();assert!(read_cache(&path).is_none());let _=std::fs::remove_dir_all(root);
 }
 #[test] fn se_windows_formula_thumbnail_is_rendered_and_adds_are_excluded() {
  for de in [-1,-2,21,22]{assert!(!eligible(de));}assert!(eligible(20));
  let image=preview("Integer Power").unwrap();assert_eq!((image.w,image.h),(32,32));assert!(image.px.iter().any(|p|*p!=image.px[0]));
 }
}
