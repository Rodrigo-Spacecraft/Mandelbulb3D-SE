//! Selection-preview window owned by the native Common Item Dialog.
//! Uses documented COM events; no shell extension or registry changes needed.
use super::native_dialog::{Ptr,Guid,Com,slot,path,text,result,check};
use std::{ptr::null_mut,sync::atomic::{AtomicU32,Ordering}};
#[repr(C)]#[derive(Default,Clone,Copy)]struct Rect{left:i32,top:i32,right:i32,bottom:i32}
#[repr(C)]struct MonitorInfo{size:u32,monitor:Rect,work:Rect,flags:u32}
#[repr(C)]struct BitmapInfo{size:u32,width:i32,height:i32,planes:u16,bits:u16,compression:u32,image_size:u32,x:i32,y:i32,used:u32,important:u32,colors:[u32;1]}
#[link(name="user32")]unsafe extern "system"{
 fn CreateWindowExW(ex:u32,class:*const u16,title:*const u16,style:u32,x:i32,y:i32,w:i32,h:i32,parent:Ptr,menu:Ptr,instance:Ptr,param:Ptr)->Ptr;
 fn DestroyWindow(window:Ptr)->i32;
 fn GetWindowRect(window:Ptr,rect:*mut Rect)->i32;
 fn SetWindowPos(window:Ptr,after:Ptr,x:i32,y:i32,w:i32,h:i32,flags:u32)->i32;
 fn SetWindowTextW(window:Ptr,text:*const u16)->i32;
 fn SendMessageW(window:Ptr,message:u32,w:usize,l:isize)->isize;
 fn MonitorFromWindow(window:Ptr,flags:u32)->Ptr;
 fn GetMonitorInfoW(monitor:Ptr,info:*mut MonitorInfo)->i32;
}
#[link(name="gdi32")]unsafe extern "system"{
 fn CreateDIBSection(dc:Ptr,info:*const BitmapInfo,usage:u32,bits:*mut Ptr,section:Ptr,offset:u32)->Ptr;
 fn DeleteObject(object:Ptr)->i32;
}
const EVENTS:Guid=Guid(0x973510db,0x7d7f,0x452b,[0x89,0x75,0x74,0xa8,0x58,0x28,0xd3,0x54]);
const UNKNOWN:Guid=Guid(0,0,0,[0xc0,0,0,0,0,0,0,0x46]);
const OLE_WINDOW:Guid=Guid(0x114,0,0,[0xc0,0,0,0,0,0,0,0x46]);
#[repr(C)]struct Vtable{
 query:unsafe extern "system" fn(*mut Sink,*const Guid,*mut Ptr)->i32,
 add:unsafe extern "system" fn(*mut Sink)->u32,
 release:unsafe extern "system" fn(*mut Sink)->u32,
 file_ok:unsafe extern "system" fn(*mut Sink,Ptr)->i32,
 folder_changing:unsafe extern "system" fn(*mut Sink,Ptr,Ptr)->i32,
 folder_change:unsafe extern "system" fn(*mut Sink,Ptr)->i32,
 selection:unsafe extern "system" fn(*mut Sink,Ptr)->i32,
 share:unsafe extern "system" fn(*mut Sink,Ptr,Ptr,*mut u32)->i32,
 type_change:unsafe extern "system" fn(*mut Sink,Ptr)->i32,
 overwrite:unsafe extern "system" fn(*mut Sink,Ptr,Ptr,*mut u32)->i32,
}
#[repr(C)]struct Sink{vtable:*const Vtable,refs:AtomicU32,window:Ptr,image:Ptr,bitmap:Ptr}
unsafe extern "system" fn query(s:*mut Sink,iid:*const Guid,out:*mut Ptr)->i32{unsafe{
 if out.is_null(){return 0x80004003u32 as i32;}*out=null_mut();
 if *iid==EVENTS||*iid==UNKNOWN{*out=s.cast();add(s);0}else{0x80004002u32 as i32}
}}
unsafe extern "system" fn add(s:*mut Sink)->u32{unsafe{(*s).refs.fetch_add(1,Ordering::Relaxed)+1}}
unsafe extern "system" fn release(s:*mut Sink)->u32{unsafe{let n=(*s).refs.fetch_sub(1,Ordering::AcqRel)-1;if n==0{drop(Box::from_raw(s));}n}}
unsafe extern "system" fn ok(_: *mut Sink,_:Ptr)->i32{0}
unsafe extern "system" fn changing(_: *mut Sink,_:Ptr,_:Ptr)->i32{0}
unsafe extern "system" fn response(_: *mut Sink,_:Ptr,_:Ptr,out:*mut u32)->i32{unsafe{if !out.is_null(){*out=0;}}0}
unsafe extern "system" fn selection(s:*mut Sink,dialog:Ptr)->i32{unsafe{
 let sink=&mut *s;
 let selected=result(dialog,14).ok().and_then(|item|path(item.0).ok());
 let Some(selected)=selected else{
  if !sink.window.is_null(){SendMessageW(sink.image,0x172,0,0);if !sink.bitmap.is_null(){DeleteObject(sink.bitmap);sink.bitmap=null_mut();}SetWindowTextW(sink.window,text("Preview — select a file").as_ptr());}return 0;
 };
 let image=super::parameter_preview::load(&selected,256,192);
 if sink.window.is_null(){
  let mut ole=null_mut();let q:unsafe extern "system" fn(Ptr,*const Guid,*mut Ptr)->i32=std::mem::transmute(slot(dialog,0));
  if q(dialog,&OLE_WINDOW,&mut ole)<0{return 0;}let ole=Com(ole);
  let get:unsafe extern "system" fn(Ptr,*mut Ptr)->i32=std::mem::transmute(slot(ole.0,3));let mut owner=null_mut();if get(ole.0,&mut owner)<0{return 0;}
  let mut rect=Rect::default();GetWindowRect(owner,&mut rect);
  let mut monitor=MonitorInfo{size:std::mem::size_of::<MonitorInfo>()as u32,monitor:Rect::default(),work:Rect::default(),flags:0};
  GetMonitorInfoW(MonitorFromWindow(owner,2),&mut monitor);
  let x=if rect.right+272<=monitor.work.right{rect.right+8}else{(rect.left-272).max(monitor.work.left)};
  sink.window=CreateWindowExW(0x08000080,text("STATIC").as_ptr(),text("Preview").as_ptr(),0x90c00000,x,rect.top,264,224,owner,null_mut(),null_mut(),null_mut());
  if sink.window.is_null(){return 0;}
  sink.image=CreateWindowExW(0,text("STATIC").as_ptr(),text("").as_ptr(),0x5000020e,0,0,256,192,sink.window,null_mut(),null_mut(),null_mut());
  SetWindowPos(sink.window,null_mut(),x,rect.top,264,224,0x10|0x4);
 }
 SetWindowTextW(sink.window,text(&format!("Preview — {}",selected.file_name().unwrap_or_default().to_string_lossy())).as_ptr());
 let mut bitmap=null_mut();
 if let Some(image)=image{
  let info=BitmapInfo{size:40,width:256,height:-192,planes:1,bits:32,compression:0,image_size:0,x:0,y:0,used:0,important:0,colors:[0]};
  let mut pixels=null_mut();bitmap=CreateDIBSection(null_mut(),&info,0,&mut pixels,null_mut(),0);
  if !bitmap.is_null(){std::ptr::copy_nonoverlapping(image.px.as_ptr(),pixels.cast::<u32>(),image.px.len());}
 }
 SendMessageW(sink.image,0x172,0,bitmap as isize);
 if !sink.bitmap.is_null(){DeleteObject(sink.bitmap);}sink.bitmap=bitmap;
 if bitmap.is_null(){SetWindowTextW(sink.window,text("Preview — no saved image available").as_ptr());}
 0
}}
static VTABLE:Vtable=Vtable{query,add,release,file_ok:ok,folder_changing:changing,folder_change:selection,selection,share:response,type_change:selection,overwrite:response};
impl Drop for Sink{fn drop(&mut self){unsafe{if !self.window.is_null(){DestroyWindow(self.window);}if !self.bitmap.is_null(){DeleteObject(self.bitmap);}}}}
pub(super) struct Preview{dialog:Ptr,sink:*mut Sink,cookie:u32}
impl Preview{pub(super) unsafe fn attach(dialog:Ptr)->Result<Self,i32>{unsafe{
 let sink=Box::into_raw(Box::new(Sink{vtable:&VTABLE,refs:AtomicU32::new(1),window:null_mut(),image:null_mut(),bitmap:null_mut()}));
 let mut cookie=0;let advise:unsafe extern "system" fn(Ptr,Ptr,*mut u32)->i32=std::mem::transmute(slot(dialog,7));
 if let Err(e)=check(advise(dialog,sink.cast(),&mut cookie)){release(sink);return Err(e);}
 Ok(Self{dialog,sink,cookie})
}}}
impl Drop for Preview{fn drop(&mut self){unsafe{let unadvise:unsafe extern "system" fn(Ptr,u32)->i32=std::mem::transmute(slot(self.dialog,8));unadvise(self.dialog,self.cookie);release(self.sink);}}}
