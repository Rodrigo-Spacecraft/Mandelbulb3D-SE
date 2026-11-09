//! Local emissive DIFS experiment: deterministic one-bounce transport and bloom.
use crate::{calc::{CalcParams,Marcher},gbuffer::SiLight,math::*};
#[derive(Clone,Debug)]
pub(crate) struct Emission {pub p:CalcParams,pub color:[f32;3],pub mask:EmissionMask,pub bounce:[f32;3],pub primary:Option<std::sync::Arc<Vec<(bool,f32)>>>}
/// Linear material opacity, independent of the lighting gamma setting.
#[derive(Clone,Debug)]
pub(crate) struct EmissionMask {alpha:[f32;10],positions:[i32;10],start:f32,mul:f32,zmul:f32,cycle:bool,stepped:bool,orbit:bool,pub depth_offset:f32}
impl EmissionMask {
 // Diffuse opacity is supplied separately from the specular transparency channel.
 pub fn new(l:&crate::lighting::LightVals,depth_offset:f32,alpha:[f32;10])->Self{Self{alpha,positions:l.col_pos,start:l.s_c_start,mul:l.s_c_mul,zmul:l.s_col_zmul,cycle:l.col_cycling,orbit:l.col_on_otrap,stepped:l.no_col_ipol,depth_offset}}
 pub fn strength(&self,si:&SiLight,depth:f32)->f32{
  let raw=if self.orbit{si.otrap&32767}else{si.si_gradient&32767};
  self.at(raw,depth)
 }
 fn at(&self,raw:u16,depth:f32)->f32{
  let mut x=(((raw as f32-self.start)*self.mul+self.zmul*depth)*16384.).clamp(-1e9,1e9).round() as i32;
  if self.cycle{x&=32767}else if x<0{return self.alpha[0].clamp(0.,1.)}else if x>=self.positions[9]{return self.alpha[9].clamp(0.,1.)}
  let mut b=1;while b<10&&self.positions[b]<x{b+=1}let a=b-1;
  if self.stepped{return self.alpha[a].clamp(0.,1.)}
  let end=if b<10{self.positions[b]}else{32767};let b=if b<10{b}else{0};
  let t=(x-self.positions[a]) as f32/(end-self.positions[a]).max(1) as f32;
  (self.alpha[a]+t*(self.alpha[b]-self.alpha[a])).clamp(0.,1.)
 }
}
// Brightness of light cast onto receivers; source display and bloom are independent.
pub(crate) const ILLUMINATION_GAIN:f32=1.5;

/// Shape only the low end of received emissive light. A single RGB gain
/// preserves hue, leaves the bright half unchanged, and respects internal gamma.
pub(crate) fn receiver_contrast(light:[f32;3],squared:bool)->[f32;3]{
 let peak=light.iter().copied().fold(0.,f32::max);
 let brightness=if squared{peak.sqrt()}else{peak};
 // Keep at least 75% of low illumination so shadows retain visible detail.
 let t=(brightness/0.5).clamp(0.,1.);let gain=0.75+0.25*t*t*(3.-2.*t);
 let gain=if squared{gain*gain}else{gain};light.map(|v|v*gain)
}
// Cosine-weighted hemisphere: unit source radiance, 64 visibility rays.
const EMISSION_DIRECTIONS:usize=64;
fn cross(a:Vec3,b:Vec3)->Vec3{[a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0]]}
// Stable per-pixel scrambling avoids coherent visibility bands without extra rays.
fn emission_scramble(mut seed:u32)->[f64;2]{
 seed^=seed>>16;seed=seed.wrapping_mul(0x7feb352d);seed^=seed>>15;
 seed=seed.wrapping_mul(0x846ca68b);seed^=seed>>16;
 let a=seed as f64/4294967296.;
 seed=seed.wrapping_mul(1664525).wrapping_add(1013904223);
 [a,seed as f64/4294967296.]
}
fn emission_direction(i:usize,n:Vec3,scramble:[f64;2])->Vec3{
 let axis=if n[2].abs()<0.9{[0.,0.,1.]}else{[0.,1.,0.]};
 let tangent=normalize(cross(axis,n));let bitangent=cross(n,tangent);
 let(mut bits,mut radical,mut factor)=(i,0.,0.5);
 while bits!=0{radical+=(bits&1) as f64*factor;bits>>=1;factor*=0.5;}
 let r=((i as f64+scramble[0])/EMISSION_DIRECTIONS as f64).sqrt();let a=std::f64::consts::TAU*(radical+scramble[1]);
 add(scale(n,(1.-r*r).sqrt()),add(scale(tangent,r*a.cos()),scale(bitangent,r*a.sin())))
}
impl Emission {
 pub fn strength_at(&self,m:&mut Marcher,pos:Vec3,depth:f32)->f32{
  if self.mask.alpha.iter().all(|a|*a==self.mask.alpha[0]){return self.mask.alpha[0].clamp(0.,1.)}
  let de=m.de_at_point(pos,true);let mut si=SiLight::default();
  // Match surface_found: raw smooth iterations omit material colour offsets.
  si.si_gradient=m.surface_color_gradient(m.it.smooth_it,m.it.it_result<m.max_its_result||de<m.ms_de_stop as f64);
  if self.p.color_on_it!=0{m.do_color_on_it();}m.do_color(&mut si);
  self.mask.strength(&si,depth)
 }

 pub fn point(&self,si:&SiLight,x:i32,y:i32)->Option<(Vec3,f64)>{let mut m=Marcher::new(&self.p,1);if m.surface_point(x,y,si,4,0.01){Some((m.it.c,m.ms_de_stop as f64))}else{None}}
 pub fn sample(&self,pos:Vec3,mut n:Vec3,view:Vec3,eps:f64,seed:u32,cancel:&(dyn Fn()->bool+Sync))->(bool,f32){
  if cancel(){return(false,0.)}
  let p=&self.p;if !p.difs&&!p.decomb.as_ref().is_some_and(|d|d.part2.difs){return(false,0.)}let mut m=Marcher::new(p,1);m.ms_de_stop=eps as f32;m.de_at_point(pos,false);let emitter=m.last_difs;
  if emitter{let depth=dot(&sub(pos,p.ystart),&normalize(p.vgrads[2])) as f32+self.mask.depth_offset;if self.strength_at(&mut m,pos,depth)>=1.{return(true,0.)}}
  if dot(&n,&view)>0.{n=scale(n,-1.)}
  let eps=eps.max(0.001);let origin=add(pos,scale(n,2.*eps*p.step_width));let mut total=0.;let scramble=emission_scramble(seed);
  for i in 0..EMISSION_DIRECTIONS {if cancel(){return(false,0.)}let dir=emission_direction(i,n,scramble);let mut t=0.;
   for step in 0..1024 {if step%16==0&&cancel(){return(false,0.)}if t>=p.zend.max(eps*32.){break}m.ms_de_stop=(eps*0.5) as f32;let d=m.de_at_point(add(origin,scale(dir,t*p.step_width)),false);if !d.is_finite(){break}if d<=eps*0.5||(!m.last_difs&&m.it.it_result>=m.max_its_result){if m.last_difs{let hit=add(origin,scale(dir,t*p.step_width));let depth=(dot(&sub(hit,p.ystart),&normalize(p.vgrads[2]))) as f32+self.mask.depth_offset;total+=1./EMISSION_DIRECTIONS as f32*self.strength_at(&mut m,hit,depth);}break}t+=(d*0.7).max(eps*0.25);}
  }
  if emitter&&total>0.&&std::env::var_os("MB3DX_EMISSION_DEBUG").is_some(){
   static REPORTED:std::sync::atomic::AtomicBool=std::sync::atomic::AtomicBool::new(false);
   if !REPORTED.swap(true,std::sync::atomic::Ordering::Relaxed){eprintln!("DIFS receiver irradiance: {}",total);}
  }
  (emitter,total)
 }
}
fn blur(src:&[f32],dst:&mut[f32],w:usize,h:usize,r:usize,vertical:bool,cancel:&(dyn Fn()->bool+Sync))->bool{
 let(lines,len,step)=if vertical{(w,h,w)}else{(h,w,1)};for line in 0..lines{if cancel(){return false}let base=if vertical{line}else{line*w};let mut sum=0f64;for i in 0..=r.min(len-1){sum+=src[base+i*step] as f64;}for i in 0..len{dst[base+i*step]=(sum/(i.saturating_add(r).min(len-1)-i.saturating_sub(r)+1) as f64) as f32;if i>=r{sum-=src[base+(i-r)*step] as f64;}if i+r+1<len{sum+=src[base+(i+r+1)*step] as f64;}}}true
}
pub fn glow(sc:&crate::Scene,p:&CalcParams,gbuf:&[SiLight],rgb:&mut[u8],cancel:&(dyn Fn()->bool+Sync))->Result<(),String>{
 let Some(color)=sc.emissive_difs else{return Ok(())};let(w,h)=(p.width as usize,p.height as usize);let mut mask=vec![0f32;w*h];let mut tmp=mask.clone();let mut m=Marcher::new(p,1);
 let cam=crate::render::paint_camera(sc,p);let lighting=crate::render::light_vals(sc,&sc.lighting,&cam);
 let strength=|i:usize|{let si=&gbuf[i];let z=(((8388352.-(si.zpos_fine>>8) as f64)/cam.zc_mul+1.).powi(2)-1.)*cam.step_width/cam.zcorr+cam.zz_stmit_dif;lighting.emission.as_ref().map(|e|e.mask.strength(si,z as f32)).unwrap_or(0.)*color.iter().copied().fold(0.,f32::max)};
 let cached=sc.emission_cache.lock().ok().and_then(|c|c.as_ref().map(|(_,v)|v.clone()));
 for y in 0..h{if cancel(){return Err("cancelled".into())}for x in 0..w{let i=y*w+x;
 if let Some(samples)=cached.as_ref().filter(|v|v.len()==w*h){if samples[i].0{mask[i]=strength(i);}continue}
 if m.surface_point(x as i32,y as i32,&gbuf[i],4,0.01){m.calc_de();if m.last_difs{mask[i]=strength(i);}}}}
 if std::env::var_os("MB3DX_EMISSION_DEBUG").is_some(){if let Some(samples)=&cached{eprintln!("DIFS receivers lit: {}",samples.iter().enumerate().filter(|(i,s)|s.0&&s.1>0.&&strength(*i)<color.iter().copied().fold(0.,f32::max)).count());}eprintln!("Emissive mask: {} / {} pixels; first DIFS {}, second DIFS {:?}",mask.iter().filter(|v|**v>0.).count(),w*h,p.difs,p.decomb.as_ref().map(|d|d.part2.difs));}
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
  let mut tasks=Vec::with_capacity(256*EMISSION_DIRECTIONS);let mut weights=Vec::with_capacity(tasks.capacity());
  for i in begin..end{
   if cancel(){return Err("cancelled".into())}
   let x=(i%p.width as usize) as i32;let y=(i/p.width as usize) as i32;
   let Some((pos,eps))=e.point(&gbuf[i],x,y) else{continue};
   classifier.ms_de_stop=eps as f32;classifier.de_at_point(pos,false);
   if classifier.last_difs{samples[i]=(true,0.);let depth=dot(&sub(pos,p.ystart),&normalize(p.vgrads[2])) as f32+e.mask.depth_offset;if e.strength_at(&mut classifier,pos,depth)>=1.{continue}}
   // GPU finite differences can amplify rounding as pixel spacing shrinks.
   // Reconstruct the launch normal in CPU precision; transport stays on GPU.
   let mut source=gbuf[i];let mut launch=Marcher::new(p,1);
   if !launch.surface_point(x,y,&source,4,0.01){continue}
   if p.normals_on_de{launch.calculate_normals(&mut source);}else{launch.calculate_normals_on_smooth_it(&mut source);}
   let raw=source.normal.map(|v|v as f64/32767.);
   let mut n=normalize(rotate_vector_reverse(&raw,&normalise_matrix_to(1.,&p.vgrads)));
   let view=cam.to_abs(cam.view_vec((x+1) as f32/cam.width as f32,y as f32/cam.height as f32,cam.aspect)).map(|v|v as f64);
   if dot(&n,&view)>0.{n=scale(n,-1.)}
   let origin=add(pos,scale(n,2.*eps.max(0.001)*p.step_width));
   for ray in 0..EMISSION_DIRECTIONS{
    let dir=emission_direction(ray,n,emission_scramble(i as u32));
    weights.push(1./EMISSION_DIRECTIONS as f32);
    let zf=(gbuf[i].zpos_fine>>8) as f64;
    let zz=(((8388351.5-zf)/p.zc_mul+1.).powi(2)-1.)/p.zcorr;
    tasks.push(ReflectTask{origin,dir:dir.map(|v|(v*p.step_width) as f32),zz:zz as f32,pixel:i as u32,..Default::default()});
   }
  }
  if tasks.is_empty(){continue}
  let(hits,_,unfinished)=crate::gpu::reflect_batch_cancellable(p,&tasks,&ReflectOpts::default(),None,cancel)?;
  if !unfinished.is_empty()||hits.len()!=tasks.len(){return Err("incomplete GPU emission batch".into())}
  for ((task,hit),weight) in tasks.iter().zip(hits).zip(weights){
   if cancel(){return Err("cancelled".into())}
   if hit.hit&&!hit.skip&&hit.difs{let mut material=Marcher::new(p,1);let depth=hit.zz*p.step_width as f32+e.mask.depth_offset;samples[task.pixel as usize].1+=weight*e.strength_at(&mut material,hit.pos,depth);}
  }
 }
 Ok(samples)
}

/// Separate geometric transport from the material repaint, on the CPU too.
pub(crate) fn prepare_cpu(e:&Emission,gbuf:&[SiLight],cam:&crate::lighting::PaintCamera,threads:usize,progress:&(dyn Fn(usize,usize)+Sync),cancel:&(dyn Fn()->bool+Sync))->Result<Vec<(bool,f32)>,String>{
 let p=&e.p;let mut samples=vec![(false,0.);gbuf.len()];
 // Hand out small disjoint batches so expensive receivers cannot strand
 // workers behind large background/emitter-only image regions.
 let finished=std::sync::atomic::AtomicUsize::new(0);progress(0,gbuf.len());
 let batches=std::sync::Mutex::new(samples.chunks_mut(64).enumerate());
 std::thread::scope(|scope|{for _ in 0..threads.max(1).min((gbuf.len()+63)/64){let batches=&batches;let finished=&finished;scope.spawn(move||{
  loop {
   if cancel(){return}
   let batch={batches.lock().unwrap().next()};
   let Some((batch,out))=batch else{break};
   for(j,sample)in out.iter_mut().enumerate(){if cancel(){return}let i=batch*64+j;let x=(i%p.width as usize) as i32;let y=(i/p.width as usize) as i32;
    if let Some((pos,eps))=e.point(&gbuf[i],x,y){let raw=gbuf[i].normal.map(|v|v as f64/32767.);let n=normalize(rotate_vector_reverse(&raw,&normalise_matrix_to(1.,&p.vgrads)));
     let view=cam.to_abs(cam.view_vec((x+1) as f32/cam.width as f32,y as f32/cam.height as f32,cam.aspect)).map(|v|v as f64);
     *sample=e.sample(pos,n,view,eps,i as u32,cancel);
    }
   }
   progress(finished.fetch_add(out.len(),std::sync::atomic::Ordering::Relaxed)+out.len(),gbuf.len());
  }
 });}});
 if cancel(){Err("cancelled".into())}else{Ok(samples)}
}

/// A cheap, view-dependent bounce estimate. Average reflected light from at
/// most 4096 visible receiving surfaces; no geometry queries or new rays.
pub(crate) fn indirect_fill(lv:&crate::lighting::LightVals,gbuf:&[SiLight],cam:&crate::lighting::PaintCamera,cancel:&(dyn Fn()->bool+Sync))->[f32;3]{
 let Some(e)=&lv.emission else{return [0.;3]};let Some(samples)=&e.primary else{return [0.;3]};
 let mut total=[0.;3];let mut count=0.;let stride=((gbuf.len()+4095)/4096).max(1);
 for i in (0..gbuf.len()).step_by(stride){if cancel(){return [0.;3]}let si=&gbuf[i];if si.is_background(){continue}
  let plv=lv.plv_for_pixel(si,(i%cam.width as usize) as i32,(i/cam.width as usize) as i32,cam);
  let strength=if samples[i].0{e.mask.strength(si,plv.z_pos)}else{0.};if strength>=1.{continue}
  let idif0=lv.s_col_zmul*plv.z_pos;
  let mut dif=if si.si_gradient>32767{lv.calc_colors_inside(si,idif0).0}else{lv.calc_colors(si,idif0).0};
  if let Some(map)=&lv.diff_map{let n=si.normal.map(|v|v as f32/32767.);let color=lv.diff_map_color(map,si,n,plv.obj_pos,0.,cam);dif=if lv.yc_comb{let luminance=|v:[f32;3]|v[0]*0.299+v[1]*0.587+v[2]*0.114;let a=luminance(color)/(0.01+luminance(dif));dif.map(|v|v*a)}else{color};}
  let energy=samples[i].1*(1.-strength)*lv.s_diff.min(1.)*ILLUMINATION_GAIN;
  for c in 0..3{let color=if lv.sqr{e.color[c]*e.color[c]}else{e.color[c]};total[c]+=dif[c].clamp(0.,1.)*color*energy;}count+=1.;
 }
 if count>0.{total.map(|v|(v/count*0.45).clamp(0.,0.25))}else{[0.;3]}
}

/// Filter only incoming irradiance. Material colour and self-emission stay sharp.
/// Two separable bilateral passes preserve depth, normal and emitter boundaries.
pub(crate) fn filter_primary(samples:&mut Vec<(bool,f32)>,gbuf:&[SiLight],p:&CalcParams,mask:&EmissionMask,cam:&crate::lighting::PaintCamera,cancel:&(dyn Fn()->bool+Sync))->bool{
 let(w,h)=(p.width as usize,p.height as usize);if samples.len()!=w*h||gbuf.len()!=w*h{return true}
 let mut depth=Vec::with_capacity(w*h);let mut opacity=Vec::with_capacity(w*h);
 for (i,si) in gbuf.iter().enumerate(){if cancel(){return false}let z=(((8388352.-(si.zpos_fine>>8) as f64)/cam.zc_mul+1.).powi(2)-1.)*cam.step_width/cam.zcorr;depth.push(z as f32);opacity.push(if samples[i].0{mask.strength(si,(z+cam.zz_stmit_dif) as f32)}else{0.});}
 let radius=((w.min(h) as f64/160.).round() as usize).clamp(2,32);
 let mut tmp=samples.clone();
 for scale in [1,2]{for vertical in [false,true]{
  if !filter_axis(samples,&mut tmp,gbuf,&depth,&opacity,w,h,radius*scale,vertical,(p.step_width*4.) as f32,cancel){return false}
  std::mem::swap(samples,&mut tmp);
 }}true
}
fn filter_axis(src:&[(bool,f32)],dst:&mut[(bool,f32)],gbuf:&[SiLight],depth:&[f32],opacity:&[f32],w:usize,h:usize,r:usize,vertical:bool,footprint:f32,cancel:&(dyn Fn()->bool+Sync))->bool{
 for y in 0..h{if cancel(){return false}for x in 0..w{let i=y*w+x;dst[i]=src[i];if gbuf[i].is_background()||opacity[i]>=1.{continue}
  let mut sum=0.;let mut weight=0.;let n=gbuf[i].normal;
  for offset in -(r as isize)..=r as isize{
   let(xx,yy)=if vertical{(x as isize,y as isize+offset)}else{(x as isize+offset,y as isize)};
   if xx<0||yy<0||xx>=w as isize||yy>=h as isize{continue}let j=yy as usize*w+xx as usize;
   if gbuf[j].is_background()||src[i].0!=src[j].0||(opacity[i]-opacity[j]).abs()>0.1{continue}
   let dot=n.iter().zip(gbuf[j].normal).map(|(a,b)|*a as f32*b as f32).sum::<f32>()/(32767.*32767.);
   if dot<0.85{continue}let dz=(depth[i]-depth[j]).abs()/(footprint*(offset.abs() as f32+1.)).max(1e-20);if dz>1.{continue}
   let spatial=1.-(offset as f32/(r+1) as f32).powi(2);let a=spatial*dot.clamp(0.,1.).powi(16)*(1.-dz*dz);
   sum+=src[j].1*a;weight+=a;
  }if weight>0.{dst[i].1=sum/weight;}
 }}true
}

#[cfg(test)]
mod tests {
 use super::*;
 #[test] fn cosine_sampler_stays_in_unit_hemisphere(){
  assert_eq!(EMISSION_DIRECTIONS,64);
  for n in [[0.,0.,1.],[1.,0.,0.],normalize([1.,2.,3.])]{for seed in [0,1,57,4096]{let scramble=emission_scramble(seed);for i in 0..EMISSION_DIRECTIONS{let d=emission_direction(i,n,scramble);assert!(dot(&n,&d)>0.);assert!((dot(&d,&d)-1.).abs()<1e-12);}}}
 }
 #[test] fn scrambled_visibility_preserves_area_light_energy(){
  // A circular emitter wholly above the horizon has irradiance sin²(radius)*cos(tilt).
  let n=normalize([1.,0.,1.]);let source=[0.,0.,1.];let mut total=0.;
  for seed in 0..2048{let scramble=emission_scramble(seed);for ray in 0..EMISSION_DIRECTIONS{
   if dot(&emission_direction(ray,n,scramble),&source)>0.8{total+=1.;}
  }}
  let measured=total/(2048*EMISSION_DIRECTIONS) as f64;
  assert!((measured-0.36*n[2]).abs()<0.003,"{measured}");
 }
 #[test] fn irradiance_filter_smooths_without_crossing_edges(){
  let mut g=vec![SiLight::default();7];for si in &mut g{si.normal=[0,0,32767];si.zpos_fine=0;}
  let opacity=vec![0.;7];let depth=vec![0.;7];let src=vec![(false,0.),(false,0.),(false,0.),(false,1.),(false,0.),(false,0.),(false,0.)];let mut dst=src.clone();
  assert!(filter_axis(&src,&mut dst,&g,&depth,&opacity,7,1,2,false,1.,&||false));assert!(dst[3].1<1.&&dst[2].1>0.);
  let src=vec![(false,0.),(false,0.),(false,0.),(false,1.),(false,1.),(false,1.),(false,1.)];
  let depth=vec![0.,0.,0.,100.,100.,100.,100.];
  assert!(filter_axis(&src,&mut dst,&g,&depth,&opacity,7,1,2,false,1.,&||false));assert_eq!(src,dst);
  let depth=vec![0.;7];for si in &mut g[3..]{si.normal=[32767,0,0];}
  assert!(filter_axis(&src,&mut dst,&g,&depth,&opacity,7,1,2,false,1.,&||false));assert_eq!(src,dst);
  for si in &mut g{si.normal=[0,0,32767];si.zpos_fine=0;}let opacity=vec![0.,0.,0.,1.,1.,1.,1.];
  assert!(filter_axis(&src,&mut dst,&g,&depth,&opacity,7,1,2,false,1.,&||false));assert_eq!(src,dst);
  assert!(!filter_axis(&src,&mut dst,&g,&depth,&opacity,7,1,2,false,1.,&||true));
 }
 #[test] fn contrast_preserves_highlights_hue_and_gamma(){
  let bright=[0.8,0.4,0.2];assert_eq!(receiver_contrast(bright,false),bright);
  let edge=[0.5,0.25,0.1];assert_eq!(receiver_contrast(edge,false),edge);
  assert_eq!(receiver_contrast([0.,0.,0.],false),[0.;3]);
  let low=[0.25,0.125,0.0625];assert_eq!(receiver_contrast(low,false),[0.21875,0.109375,0.0546875]);
  let shadow=[0.01,0.005,0.0025];assert!(receiver_contrast(shadow,false)[0]>=0.0075);
  let squared=receiver_contrast(low.map(|v|v*v),true);
  for (a,b) in squared.into_iter().zip(receiver_contrast(low,false)){assert!((a.sqrt()-b).abs()<1e-6);}
 }
 #[test] fn opacity_masks_emission_linearly(){
  let mut m=EmissionMask{alpha:[1.;10],positions:std::array::from_fn(|i|i as i32*3000),start:0.,mul:1./16384.,zmul:0.,cycle:false,stepped:false,orbit:false,depth_offset:0.};
  assert_eq!(m.at(1500,0.),1.);m.alpha=[0.;10];assert_eq!(m.at(1500,0.),0.);
  m.alpha[1]=1.;assert!((m.at(1500,0.)-0.5).abs()<1e-6);
  m.stepped=true;assert_eq!(m.at(1500,0.),0.);
 }
}
