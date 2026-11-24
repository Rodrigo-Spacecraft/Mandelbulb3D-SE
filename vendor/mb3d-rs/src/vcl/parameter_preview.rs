//! Small previews read directly from saved M3I pixels, without rendering.
use super::bitmap::Bitmap;
use std::{fs::File,io::{Read,Seek,SeekFrom},path::Path};
pub(crate) fn load(path:&Path,width:usize,height:usize)->Option<Bitmap>{
    if width==0||height==0{return None;}
    embedded(path,width,height).or_else(||saved_geometry(path,width,height)).or_else(||{
        let image=crate::image::load(&path.with_extension("png")).ok()?;
        if image.width==0||image.height==0{return None;}
        let mut result=Bitmap::new(width,height,0xff202020);
        let scale=(width as f64/image.width as f64).min(height as f64/image.height as f64);
        let w=(image.width as f64*scale).round().max(1.) as usize;let h=(image.height as f64*scale).round().max(1.) as usize;
        for y in 0..h {for x in 0..w {let c=image.pixel(x*image.width/w,y*image.height/h).map(|v|if image.deep{(v>>8)as u32}else{v as u32});result.px[(y+(height-h)/2)*width+x+(width-w)/2]=0xff000000|(c[0]<<16)|(c[1]<<8)|c[2];}}
        Some(result)
    })
}
fn embedded(path:&Path,width:usize,height:usize)->Option<Bitmap>{
    let mut file=File::open(path).ok()?;let mut header=[0u8;840];file.read_exact(&mut header).ok()?;
    let word=|offset|i32::from_le_bytes(header[offset..offset+4].try_into().unwrap());
    let id=word(0);let sw=usize::try_from(word(4)).ok()?;let sh=usize::try_from(word(8)).ok()?;
    if !(20..=100).contains(&id)||sw==0||sh==0||sw>30000||sh>30000||(id>=35&&word(428)!=0){return None;}
    let pixels=sw.checked_mul(sh)?;let offset=840u64+(pixels as u64)*18+1136;
    if file.metadata().ok()?.len()<offset+(pixels as u64)*4{return None;}
    let scale=(width as f64/sw as f64).min(height as f64/sh as f64);
    let w=(sw as f64*scale).round().max(1.) as usize;let h=(sh as f64*scale).round().max(1.) as usize;
    let mut result=Bitmap::new(width,height,0xff202020);let mut row=vec![0u8;sw*4];
    for y in 0..h{
        file.seek(SeekFrom::Start(offset+(y*sh/h*sw*4)as u64)).ok()?;file.read_exact(&mut row).ok()?;
        for x in 0..w{let c=&row[x*sw/w*4..];result.px[(y+(height-h)/2)*width+x+(width-w)/2]=0xff000000|(c[2]as u32)<<16|(c[1]as u32)<<8|c[0]as u32;}
    }
    Some(result)
}
// Older Windows M3I files store geometry rather than a finished RGB image.
// Shade a small sample of those saved records; never march new scene rays.
fn saved_geometry(path:&Path,width:usize,height:usize)->Option<Bitmap>{
    let mut file=File::open(path).ok()?;let mut header=[0u8;840];file.read_exact(&mut header).ok()?;
    let word=|o|i32::from_le_bytes(header[o..o+4].try_into().unwrap());
    let id=word(0);let sw=usize::try_from(word(4)).ok()?;let sh=usize::try_from(word(8)).ok()?;
    if !(20..=100).contains(&id)||sw==0||sh==0||sw>30000||sh>30000||(id>=35&&word(428)!=0){return None;}
    let end=840u64+sw.checked_mul(sh)? as u64*18;
    if file.metadata().ok()?.len()<end+1136{return None;}
    file.seek(SeekFrom::Start(end)).ok()?;let mut addon=[0u8;1136];file.read_exact(&mut addon).ok()?;
    let mut raw=header.to_vec();raw.extend_from_slice(&addon);let mut scene=crate::m3p::parse(&raw).ok()?.scene;
    let scale=(width as f64/sw as f64).min(height as f64/sh as f64).min(1.);
    scene.scale_image(scale);let w=scene.width as usize;let h=scene.height as usize;
    if w>width||h>height{return None;}
    scene.mc.reflections=false;scene.emissive_difs=None;scene.vol_light=None;scene.dof=None;
    let mut records=Vec::with_capacity(w*h);let mut row=vec![0u8;sw*18];
    for y in 0..h {
        file.seek(SeekFrom::Start(840+(y*sh/h*sw*18)as u64)).ok()?;file.read_exact(&mut row).ok()?;
        for x in 0..w {
            let c=&row[x*sw/w*18..];let u=|o|u16::from_le_bytes([c[o],c[o+1]]);
            records.push(crate::gbuffer::SiLight{normal:[u(0)as i16,u(2)as i16,u(4)as i16],zpos_fine:u32::from_le_bytes(c[6..10].try_into().unwrap()),shadow:u(10),amb_shadow:u(12),si_gradient:u(14),otrap:u(16)});
        }
    }
    if records.iter().all(|p|p.normal==[0;3]&&p.zpos_fine==0){return None;}
    let params=crate::calc::CalcParams::new(&scene).ok()?;
    let rgb=crate::render::paint(&scene,&params,&records);let small=Bitmap::from_rgb(w,h,&rgb);
    let mut image=Bitmap::new(width,height,0xff202020);
    for y in 0..h {image.px[(y+(height-h)/2)*width+(width-w)/2..(y+(height-h)/2)*width+(width-w)/2+w].copy_from_slice(&small.px[y*w..(y+1)*w]);}
    Some(image)
}
#[cfg(test)]mod tests{
 use super::*;
 #[test]fn reads_saved_bgra_and_rejects_missing_pixels(){
  let path=std::env::temp_dir().join(format!("mb3d-preview-{}.m3i",std::process::id()));
  let mut bytes=vec![0u8;840+2*18+1136];bytes[..4].copy_from_slice(&44i32.to_le_bytes());bytes[4..8].copy_from_slice(&2i32.to_le_bytes());bytes[8..12].copy_from_slice(&1i32.to_le_bytes());
  std::fs::write(&path,&bytes).unwrap();assert!(embedded(&path,2,1).is_none());
  bytes.extend_from_slice(&[0,0,255,255,255,0,0,255]);std::fs::write(&path,bytes).unwrap();
  assert_eq!(embedded(&path,2,1).unwrap().px,vec![0xffff0000,0xff0000ff]);let _=std::fs::remove_file(path);
 }
}
