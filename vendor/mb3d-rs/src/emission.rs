//! Local emissive DIFS experiment: deterministic one-bounce transport and bloom.
use crate::{calc::{CalcParams,Marcher},gbuffer::SiLight,math::*};
#[derive(Clone,Debug)]
pub(crate) struct Emission {pub p:CalcParams,pub color:[f32;3],pub primary:Option<std::sync::Arc<Vec<(bool,f32)>>>}
impl Emission {
 pub fn point(&self,si:&SiLight,x:i32,y:i32)->Option<(Vec3,f64)>{let mut m=Marcher::new(&self.p,1);if m.surface_point(x,y,si,4,0.01){Some((m.it.c,m.ms_de_stop as f64))}else{None}}
 pub fn sample(&self,pos:Vec3,mut n:Vec3,view:Vec3,eps:f64,cancel:&(dyn Fn()->bool+Sync))->(bool,f32){
  if cancel(){return(false,0.)}
  let p=&self.p;if !p.difs&&!p.decomb.as_ref().is_some_and(|d|d.part2.difs){return(false,0.)}let mut m=Marcher::new(p,1);m.ms_de_stop=eps as f32;m.de_at_point(pos,false);if m.last_difs{return(true,0.)}
  if dot(&n,&view)>0.{n=scale(n,-1.)}let axis=if n[2].abs()<0.9{[0.,0.,1.]}else{[0.,1.,0.]};let tangent=normalize(cross(axis,n));let bitangent=cross(n,tangent);
  let eps=eps.max(0.001);let origin=add(pos,scale(n,2.*eps*p.step_width));let mut total=0.;
  for i in 0..64 {if cancel(){return(false,0.)}let mut bits=i;let(mut radical,mut factor)=(0.,0.5);while bits!=0{radical+=(bits&1) as f64*factor;bits>>=1;factor*=0.5;}let r=((i as f64+0.5)/64.).sqrt();let angle=std::f64::consts::TAU*radical;let dir=add(scale(n,(1.-r*r).sqrt()),add(scale(tangent,r*angle.cos()),scale(bitangent,r*angle.sin())));let mut t=0.;
   for step in 0..1024 {if step%16==0&&cancel(){return(false,0.)}if t>=p.zend.max(eps*32.){break}m.ms_de_stop=(eps*0.5) as f32;let d=m.de_at_point(add(origin,scale(dir,t*p.step_width)),false);if !d.is_finite(){break}if d<=eps*0.5||(!m.last_difs&&m.it.it_result>=m.max_its_result){if m.last_difs{total+=4.}break}t+=(d*0.7).max(eps*0.25);}
  }(false,total/64.)
 }
}
fn cross(a:Vec3,b:Vec3)->Vec3{[a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0]]}
fn blur(src:&[f32],dst:&mut[f32],w:usize,h:usize,r:usize,vertical:bool,cancel:&(dyn Fn()->bool+Sync))->bool{
 let(lines,len,step)=if vertical{(w,h,w)}else{(h,w,1)};for line in 0..lines{if cancel(){return false}let base=if vertical{line}else{line*w};let mut sum=0f64;for i in 0..=r.min(len-1){sum+=src[base+i*step] as f64;}for i in 0..len{dst[base+i*step]=(sum/(i.saturating_add(r).min(len-1)-i.saturating_sub(r)+1) as f64) as f32;if i>=r{sum-=src[base+(i-r)*step] as f64;}if i+r+1<len{sum+=src[base+(i+r+1)*step] as f64;}}}true
}
pub fn glow(sc:&crate::Scene,p:&CalcParams,gbuf:&[SiLight],rgb:&mut[u8],cancel:&(dyn Fn()->bool+Sync))->Result<(),String>{
 let Some(color)=sc.emissive_difs else{return Ok(())};let(w,h)=(p.width as usize,p.height as usize);let mut mask=vec![0f32;w*h];let mut tmp=mask.clone();let mut m=Marcher::new(p,1);
 let cached=sc.emission_cache.lock().ok().and_then(|c|c.as_ref().map(|(_,v)|v.clone()));
 for y in 0..h{if cancel(){return Err("cancelled".into())}for x in 0..w{let i=y*w+x;
 if let Some(samples)=cached.as_ref().filter(|v|v.len()==w*h){if samples[i].0{mask[i]=rgb[i*3..i*3+3].iter().copied().max().unwrap_or(0) as f32/255.;}continue}
 if m.surface_point(x as i32,y as i32,&gbuf[i],4,0.01){m.calc_de();if m.last_difs{mask[i]=rgb[i*3..i*3+3].iter().copied().max().unwrap_or(0) as f32/255.;}}}}
 if std::env::var_os("MB3DX_EMISSION_DEBUG").is_some(){eprintln!("Emissive mask: {} / {} pixels; first DIFS {}, second DIFS {:?}",mask.iter().filter(|v|**v>0.).count(),w*h,p.difs,p.decomb.as_ref().map(|d|d.part2.difs));}
 let r=((w.min(h) as f64*0.015).round() as usize).max(1);for _ in 0..3{if !blur(&mask,&mut tmp,w,h,r,false,cancel)||!blur(&tmp,&mut mask,w,h,r,true,cancel){return Err("cancelled".into())}}
 for(i,v)in rgb.chunks_exact_mut(3).enumerate(){for c in 0..3{v[c]=(v[c] as f32+(255.-v[c] as f32)*(mask[i]*1.5).clamp(0.,1.)*color[c]).round().clamp(0.,255.) as u8;}}Ok(())
}

/// Cast the expensive visibility rays on the card in bounded batches. Surface
/// reconstruction and launch normals retain CPU precision. Hit materials
/// come from the same GPU evaluation that accepted each intersection.
#[cfg(feature="gpu")]
pub(crate) fn prepare_gpu(e:&Emission,gbuf:&[SiLight],cam:&crate::lighting::PaintCamera,cancel:&(dyn Fn()->bool+Sync))->Result<Vec<(bool,f32)>,String>{
 use crate::gpu::{ReflectTask,ReflectOpts};
 let p=&e.p;
 if let Some(reason)=crate::gpu::unsupported(p){return Err(reason)}
 if p.rect != [0,0,p.width,p.height]{return Err("tiled emission uses the CPU".into())}
 let ready=crate::gpu::emission_prepare(p)?;
 while !ready.load(std::sync::atomic::Ordering::SeqCst){
  if cancel(){return Err("cancelled".into())}
  std::thread::sleep(std::time::Duration::from_millis(5));
 }
 let mut samples=vec![(false,0.);gbuf.len()];
 let mut classifier=Marcher::new(p,1);
 for begin in (0..gbuf.len()).step_by(256){
  if cancel(){return Err("cancelled".into())}
  let end=(begin+256).min(gbuf.len());
  let mut tasks=Vec::with_capacity(256*64);
  for i in begin..end{
   if cancel(){return Err("cancelled".into())}
   let x=(i%p.width as usize) as i32;let y=(i/p.width as usize) as i32;
   let Some((pos,eps))=e.point(&gbuf[i],x,y) else{continue};
   classifier.ms_de_stop=eps as f32;classifier.de_at_point(pos,false);
   if classifier.last_difs{samples[i]=(true,0.);continue}
   // GPU finite differences can amplify rounding as pixel spacing shrinks.
   // Reconstruct the launch normal in CPU precision; transport stays on GPU.
   let mut source=gbuf[i];let mut launch=Marcher::new(p,1);
   if !launch.surface_point(x,y,&source,4,0.01){continue}
   if p.normals_on_de{launch.calculate_normals(&mut source);}else{launch.calculate_normals_on_smooth_it(&mut source);}
   let raw=source.normal.map(|v|v as f64/32767.);
   let mut n=normalize(rotate_vector_reverse(&raw,&normalise_matrix_to(1.,&p.vgrads)));
   let view=cam.to_abs(cam.view_vec((x+1) as f32/cam.width as f32,y as f32/cam.height as f32,cam.aspect)).map(|v|v as f64);
   if dot(&n,&view)>0.{n=scale(n,-1.)}
   let axis=if n[2].abs()<0.9{[0.,0.,1.]}else{[0.,1.,0.]};
   let tangent=normalize(cross(axis,n));let bitangent=cross(n,tangent);
   let origin=add(pos,scale(n,2.*eps.max(0.001)*p.step_width));
   for ray in 0..64{
    let(mut bits,mut radical,mut factor)=(ray,0.,0.5);
    while bits!=0{radical+=(bits&1) as f64*factor;bits>>=1;factor*=0.5;}
    let r=((ray as f64+0.5)/64.).sqrt();let angle=std::f64::consts::TAU*radical;
    let dir=add(scale(n,(1.-r*r).sqrt()),add(scale(tangent,r*angle.cos()),scale(bitangent,r*angle.sin())));
    let zf=(gbuf[i].zpos_fine>>8) as f64;
    let zz=(((8388351.5-zf)/p.zc_mul+1.).powi(2)-1.)/p.zcorr;
    tasks.push(ReflectTask{origin,dir:dir.map(|v|(v*p.step_width) as f32),zz:zz as f32,pixel:i as u32,..Default::default()});
   }
  }
  if tasks.is_empty(){continue}
  let(hits,_,unfinished)=crate::gpu::reflect_batch_cancellable(p,&tasks,&ReflectOpts::default(),None,cancel)?;
  if !unfinished.is_empty()||hits.len()!=tasks.len(){return Err("incomplete GPU emission batch".into())}
  for (task,hit) in tasks.iter().zip(hits){
   if cancel(){return Err("cancelled".into())}
   if hit.hit&&!hit.skip&&hit.difs{samples[task.pixel as usize].1+=4./64.;}
  }
 }
 Ok(samples)
}

/// Separate geometric transport from the material repaint, on the CPU too.
pub(crate) fn prepare_cpu(e:&Emission,gbuf:&[SiLight],cam:&crate::lighting::PaintCamera,threads:usize,cancel:&(dyn Fn()->bool+Sync))->Result<Vec<(bool,f32)>,String>{
 let p=&e.p;let mut samples=vec![(false,0.);gbuf.len()];
 let chunk=(gbuf.len()+threads.max(1)-1)/threads.max(1);
 std::thread::scope(|scope|{for(ci,out)in samples.chunks_mut(chunk.max(1)).enumerate(){scope.spawn(move||{
  for(j,sample)in out.iter_mut().enumerate(){if cancel(){return}let i=ci*chunk+j;let x=(i%p.width as usize) as i32;let y=(i/p.width as usize) as i32;
   if let Some((pos,eps))=e.point(&gbuf[i],x,y){let raw=gbuf[i].normal.map(|v|v as f64/32767.);let n=normalize(rotate_vector_reverse(&raw,&normalise_matrix_to(1.,&p.vgrads)));
    let view=cam.to_abs(cam.view_vec((x+1) as f32/cam.width as f32,y as f32/cam.height as f32,cam.aspect)).map(|v|v as f64);
    *sample=e.sample(pos,n,view,eps,cancel);
   }
  }
 });}});
 if cancel(){Err("cancelled".into())}else{Ok(samples)}
}
