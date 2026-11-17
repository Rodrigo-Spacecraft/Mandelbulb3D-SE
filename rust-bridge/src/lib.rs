//! AppKit bridge to the locally copied mb3d engine. All public operations are
//! serial except cancellation/progress callbacks; panics never cross the ABI.
use mb3d::{calc::CalcParams, gbuffer::SiLight, Scene};
use std::{
    ffi::{c_char, c_void, CStr},
    path::PathBuf,
    sync::{Mutex, OnceLock},
};
// UI changes are atomic requests, applied only at the next serialized render.
static CPU_ONLY:std::sync::atomic::AtomicBool=std::sync::atomic::AtomicBool::new(false);
#[no_mangle]
pub extern "C" fn mb3dx_rust_set_cpu_only(on:i32){CPU_ONLY.store(on!=0,std::sync::atomic::Ordering::Relaxed);}
struct Cached {
    key: String,
    raw: Vec<SiLight>,
    post_key: String,
    transmission_key: String,
    p: CalcParams,
    scene: Scene,
    gbuf: Vec<SiLight>,
    color_fit: Option<[[i32; 2]; 2]>,
}
// Outside-palette endpoints from primary geometry only. Both coloring
// choices are retained so switching orbit-trap mode needs no new trace.
fn palette_fit(pixels: &[SiLight]) -> Option<[[i32; 2]; 2]> {
    let mut histogram=vec![0usize; 2*32768];let mut totals=[0usize;2];
    for si in pixels {
        if si.is_background(){continue;}
        if si.si_gradient & 0x8000 == 0{histogram[si.si_gradient as usize]+=1;totals[0]+=1;}
        histogram[32768+(si.otrap & 0x7fff) as usize]+=1;totals[1]+=1;
    }
    if totals[1]==0{return None;}
    let mut ranges=[[0i32,32767];2];
    for channel in 0..2 {
        if totals[channel]==0{continue;}let threshold=(totals[channel]/2000).max(1);
        let bins=&histogram[channel*32768..(channel+1)*32768];let mut count=0;
        for (i,&n) in bins.iter().enumerate(){count+=n;if count>=threshold{ranges[channel][0]=i as i32;break;}}
        count=0;for (i,&n) in bins.iter().enumerate().rev(){count+=n;if count>=threshold{ranges[channel][1]=i as i32;break;}}
    }
    Some(ranges)
}
#[no_mangle]
pub extern "C" fn mb3dx_rust_color_fit(out: *mut i32) -> i32 {
    if out.is_null(){return 0;}
    let Ok(cache)=caches().lock() else{return 0;};
    let Some(ranges)=cache[0].as_ref().and_then(|c|c.color_fit) else{return 0;};
    unsafe {for channel in 0..2{for end in 0..2{*out.add(channel*2+end)=ranges[channel][end];}}}
    1
}
#[no_mangle]
pub extern "C" fn mb3dx_rust_color_histogram(out: *mut u32) -> i32 {
    if out.is_null(){return 0;}
    let Ok(cache)=caches().lock() else{return 0;};let Some(c)=cache[0].as_ref() else{return 0;};
    let mut bins=[[0u32;256];3];
    for si in &c.raw {if si.is_background(){continue;}
        let gradient=(si.si_gradient & 32767) as f64;let channel=if si.si_gradient & 32768 != 0 {2}else{0};
        let fraction=if channel==2 {(gradient/0.000158025).powf(0.25)/127.}else{90.*((gradient+10900.)/32767.).sqrt()/120.};
        bins[channel][(fraction*255.).round().clamp(0.,255.) as usize]+=1;
        let fraction=90.*(((si.otrap & 32767) as f64+10900.)/32767.).sqrt()/120.;bins[1][(fraction*255.).round().clamp(0.,255.) as usize]+=1;
    }
    unsafe {for channel in 0..3{for bin in 0..256{*out.add(channel*256+bin)=bins[channel][bin];}}}1
}
static CACHES: OnceLock<Mutex<[Option<Cached>; 2]>> = OnceLock::new();
fn caches() -> &'static Mutex<[Option<Cached>; 2]> {
    CACHES.get_or_init(|| Mutex::new([None, None]))
}
fn has_transmission_cache(scene: &Scene) -> bool {
    scene.transmission_cache.as_ref()
        .and_then(|entry| entry.lock().ok())
        .is_some_and(|entry| entry.is_some())
}

fn text(p: *const c_char) -> Result<String, String> {
    if p.is_null() {
        return Err("Missing bridge path".into());
    }
    unsafe { CStr::from_ptr(p) }
        .to_str()
        .map(str::to_owned)
        .map_err(|_| "Invalid path encoding".into())
}
fn error(out: *mut c_char, s: &str) {
    if out.is_null() {
        return;
    }
    unsafe {
        std::ptr::write_bytes(out, 0, 512);
        let n = s.len().min(511);
        std::ptr::copy_nonoverlapping(s.as_ptr(), out as *mut u8, n)
    }
}
fn rgba(rgb: &[u8], out: *mut u8) {
    if out.is_null() {
        return;
    }
    let pixels = unsafe { std::slice::from_raw_parts_mut(out, rgb.len() / 3 * 4) };
    for (src, dst) in rgb.chunks_exact(3).zip(pixels.chunks_exact_mut(4)) {
        dst[..3].copy_from_slice(src);
        dst[3] = 255;
    }
}
fn geometry_key(sc: &Scene) -> String {
    let mut g = sc.clone();
    g.lighting = Default::default();
    g.shadows = None;
    g.ao = None;
    g.deao = None;
    g.dof = None;
    g.mc = Default::default();
    g.threads = 0;
    g.to_text()
}
#[no_mangle]
pub extern "C" fn mb3dx_rust_render(
    path: *const c_char,
    assets: *const c_char,
    threads: i32,
    preview: i32,
    reuse: i32,
    map_scale: f64,
    emission: *const f64,
    emission_opacity: *const f64,
    transmission_blur: f64,
    translucency_glow: f64,
    translucency_enabled: i32,
    token: *mut c_void,
    cancel: extern "C" fn(*mut c_void) -> i32,
    progress: extern "C" fn(*mut c_void, i32, i32),
    out: *mut u8,
    sharp: *mut u8,
    local: *mut f64,
    err: *mut c_char,
    statistics: *mut mb3d::diagnostics::Statistics,
) -> i32 {
    mb3d::diagnostics::reset();
    let profile_start=std::time::Instant::now();
    let mut geometry_reused = false;
    let result =
        std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| -> Result<bool, String> {
            static INIT: OnceLock<()> = OnceLock::new();
            INIT.get_or_init(|| {
                std::env::set_var("MB3D_PORTABLE", "0");
                if std::env::var_os("XDG_CACHE_HOME").is_none() {
                    if let Some(home) = std::env::var_os("HOME") {
                        std::env::set_var(
                            "XDG_CACHE_HOME",
                            PathBuf::from(home).join("Library/Caches/Mandelbulb3Dr"),
                        );
                    }
                }
            });
            let mode=std::env::var("MB3DX_GPU").unwrap_or_default();
            let cpu_only=CPU_ONLY.load(std::sync::atomic::Ordering::Relaxed)||mode=="cpu";
            #[cfg(feature="gpu")]{mb3d::gpu::set_enabled(mb3d::gpu::default_on()&&!cpu_only);mb3d::gpu::set_auto(mode!="card");}
            let assets = PathBuf::from(text(assets)?);
            if !mb3d::formulas::formula_dir_list().contains(&assets) {
                mb3d::formulas::add_formula_dir(assets);
            }
            if std::env::var_os("MB3DX_MAP_DIR").is_none() {
                if let Some(home) = std::env::var_os("HOME") {
                    mb3d::maps::add_map_dir(PathBuf::from(home).join("M3D/M3Maps"));
                }
            }
            let loaded = mb3d::m3p::load(std::path::Path::new(&text(path)?))?;
            for w in loaded.warnings {
                eprintln!("Rust engine: {w}");
            }
            let mut sc = loaded.scene;
            let translucency_enabled = translucency_enabled != 0 && sc.mc.transparency;
            if translucency_enabled {
                sc.transmission_blur = transmission_blur.clamp(0.0, 2.0) as f32;
                sc.translucency_glow = translucency_glow.clamp(-1.0, 1.0) as f32;
            }
            if !emission.is_null(){sc.emissive_difs=Some(unsafe{[(*emission) as f32,(*emission.add(1)) as f32,(*emission.add(2)) as f32]});}
            if !emission_opacity.is_null(){sc.emissive_opacity=std::array::from_fn(|i|unsafe{(*emission_opacity.add(i)).clamp(0.,1.) as f32});}
            if map_scale.is_finite() && map_scale > 0.0 { sc.lighting.diff_map_scale_exact = Some(map_scale); }
            sc.threads = threads.max(0) as usize;
            let token = token as usize;
            let stop = || cancel(token as *mut c_void) != 0;
            let report = |done: usize, total: usize| {
                progress(token as *mut c_void, done.min(i32::MAX as usize) as i32, total.min(i32::MAX as usize) as i32);
            };
            let stage = |name: &str| {
                let id=if name.contains("emissive") {1} else if name.contains("reflection") {3} else if name.contains("depth of field") {4} else if name.contains("hard shadows") {2} else {5};
                progress(token as *mut c_void, -id-1, 0);
            };
            progress(token as *mut c_void, -1, 0);
            if stop() { return Err("cancelled".into()); }
            let index = usize::from(preview != 0);
            let mut caches = caches().lock().map_err(|_| "Rust cache lock failed")?;
            let key = format!("{}\nCPU_ONLY={cpu_only}",geometry_key(&sc));
            geometry_reused = reuse != 0 && caches[index].as_ref().is_some_and(|c| c.key == key);
            let transmission_key = if index == 0 && sc.mc.reflections && translucency_enabled {
                let mut trace_scene = sc.clone();
                trace_scene.transmission_blur = 0.0;
                trace_scene.translucency_glow = 0.0;
                trace_scene.emission_cache = Default::default();
                trace_scene.transmission_cache = None;
                format!("{trace_scene:?}")
            } else {
                String::new()
            };
            if reuse == 2 {
                let valid = geometry_reused && !transmission_key.is_empty() &&
                    caches[index].as_ref().is_some_and(|c| {
                        let post_key = format!("{:?}|{:?}|{}", mb3d::render::post_job(&sc, &c.p), sc.ao, sc.normals_on_zbuf);
                        c.post_key == post_key && c.transmission_key == transmission_key &&
                            c.gbuf.len() == c.raw.len() && has_transmission_cache(&c.scene)
                    });
                if !valid { return Err("Render transparency to enable the Glow slider.".into()); }
            }
            mb3d::diagnostics::phase(0);
            let march_start=std::time::Instant::now();
            let mut c = if geometry_reused {
                caches[index].take().unwrap()
            } else {
                let (p, raw) = mb3d::render::calculate_raw_cancellable(&sc, &report, &stop)?;
                let color_fit=if index==0{palette_fit(&raw)}else{None};
                Cached {
                    color_fit,
                    key,
                    raw,
                    post_key: String::new(),
                    transmission_key: String::new(),
                    p,
                    scene: sc.clone(),
                    gbuf: Vec::new(),
                }
            };
            let march_time=march_start.elapsed();let post_start=std::time::Instant::now();
            if geometry_reused{sc.emission_cache=c.scene.emission_cache.clone();}
            let post_key=format!("{:?}|{:?}|{}",mb3d::render::post_job(&sc,&c.p),sc.ao,sc.normals_on_zbuf);
            let reuse_post=geometry_reused&&c.post_key==post_key&&c.gbuf.len()==c.raw.len();
            let mut gbuf = if reuse_post {c.gbuf.clone()} else {c.raw.clone()};
            mb3d::diagnostics::phase(7);
            let post_times=if reuse_post {mb3d::render::StageTimes::default()} else {mb3d::render::post_process_reporting(&sc, &c.p, &mut gbuf, mb3d_threads(&sc), &report, &stage, &stop)?};
            let post_time=post_start.elapsed();let paint_start=std::time::Instant::now();
            // Paint once without DoF to retain the exact sharp result, including R/T/fog.
            let dof = sc.dof.take();
            if !transmission_key.is_empty() {
                sc.transmission_cache = if reuse_post && transmission_key == c.transmission_key {
                    c.scene.transmission_cache.take().or_else(|| Some(Default::default()))
                } else {
                    Some(Default::default())
                };
            }
            mb3d::diagnostics::phase(6);
            stage("emissive illumination");
            let (mut rgb, reflection_time) = mb3d::render::paint_reporting(&sc, &c.p, &gbuf, &report, &stage, &stop);
            if sc.emissive_difs.is_some(){stage("emissive illumination");}
            mb3d::emission::glow(&sc,&c.p,&gbuf,&mut rgb,&stop)?;
            rgba(&rgb, sharp);
            sc.dof = dof;
            let paint_time=paint_start.elapsed().as_secs_f64();let dof_start=std::time::Instant::now();
            if let Some(d) = sc.dof.as_ref() {
                stage("depth of field");
                mb3d::dof::apply(
                    &mut rgb,
                    &gbuf,
                    c.p.width as usize,
                    c.p.height as usize,
                    c.p.zc_mul,
                    c.p.zcorr,
                    sc.fov_y,
                    d,
                    &stop,
                );
            }
            if stop() {
                return Err("cancelled".into());
            }
            if std::env::var_os("MB3DX_PROFILE").is_some(){eprintln!("Rust profile: setup {:.4}s, march {:.4}s, post {:.4}s, paint/DoF {:.4}s, total {:.4}s, threads {}",march_start.duration_since(profile_start).as_secs_f64(),march_time.as_secs_f64(),post_time.as_secs_f64(),paint_start.elapsed().as_secs_f64(),profile_start.elapsed().as_secs_f64(),mb3d_threads(&sc));}
            rgba(&rgb, out);
            mb3d::diagnostics::phase(7);
            if !local.is_null() {
                let (pos, _) = mb3d::calc::pixel_ray(&c.p, c.p.width / 2, c.p.height / 2);
                unsafe {
                    *local = mb3d::calc::de_at(&c.p, pos).0.abs();
                }
            }
            #[cfg(feature = "gpu")]
            eprintln!("Mandelbulb3Dr: {}", mb3d::gpu::last_status());
            let mut counts=mb3d::diagnostics::snapshot();counts.valid=1;counts.threads=mb3d_threads(&sc) as i32;
            counts.elapsed=profile_start.elapsed().as_secs_f64();counts.timing_mask=0xcf;
            counts.seconds[0]=march_time.as_secs_f64();counts.seconds[1]=(paint_time-reflection_time.unwrap_or(0.)).max(0.);
            counts.seconds[2]=post_times.ao.flatten().unwrap_or(0.);counts.seconds[3]=post_times.shadows.flatten().unwrap_or(0.);
            counts.seconds[5]=reflection_time.unwrap_or(0.);counts.timing_mask|=1<<5;
            counts.seconds[6]=dof_start.elapsed().as_secs_f64();counts.seconds[7]=march_start.duration_since(profile_start).as_secs_f64()+(post_time.as_secs_f64()-counts.seconds[2]-counts.seconds[3]).max(0.);
            #[cfg(feature="gpu")] {counts.gpu=i32::from(mb3d::gpu::last_status().starts_with("GPU"));}
            if !statistics.is_null(){unsafe{*statistics=counts;}}
            c.post_key=post_key;
            c.transmission_key=transmission_key;
            let transmission_cached = has_transmission_cache(&sc);
            c.scene = sc;
            c.gbuf = gbuf;
            caches[index] = Some(c);
            Ok(transmission_cached)
        }));
    match result {
        // Bit 0 means success without surface reuse, bit 1 means success
        // with reuse, and bit 2 reports this render's transmission cache.
        Ok(Ok(transmission_cached)) =>
            (if geometry_reused { 2 } else { 1 }) | (i32::from(transmission_cached) << 2),
        Ok(Err(e)) => {
            error(err, &e);
            0
        }
        Err(_) => {
            error(err, "Rust engine panicked; no partial image was displayed");
            0
        }
    }
}
fn mb3d_threads(sc: &Scene) -> usize {
    if sc.threads > 0 {
        sc.threads
    } else {
        std::thread::available_parallelism()
            .map(usize::from)
            .unwrap_or(4)
    }
}

/// Adaptive navigation for formulas which have no C implementation. The most
/// recent Navigator render supplies the geometry; movement probes world points.
#[no_mangle]
pub extern "C" fn mb3dx_rust_distance(x: f64, y: f64, z: f64) -> f64 {
    std::panic::catch_unwind(|| {
        let guard = caches().lock().ok()?;
        let c = guard[1].as_ref().or(guard[0].as_ref())?;
        Some(mb3d::calc::de_at(&c.p, [x,y,z]).0)
    }).ok().flatten().unwrap_or(f64::NAN)
}

#[no_mangle]
pub extern "C" fn mb3dx_rust_navigator_correction() -> f64 {
    let Ok(cache) = caches().lock() else { return 1.0 };
    let Some(c) = cache[1].as_ref() else { return 1.0 };
    let (w, h) = (c.p.width, c.p.height);
    let (origin, _) = mb3d::calc::pixel_ray(&c.p, w / 2, h / 2);
    let view_distance = 2.0 * f64::from(w).hypot(f64::from(h)) / (f64::from(w) * c.scene.zoom);
    let plane_radius = c.p.step_width * f64::from(w).hypot(f64::from(h)) * 0.5;
    let mut nearest = view_distance;
    for (index, pixel) in c.gbuf.iter().enumerate() {
        if pixel.is_background() { continue; }
        let z = f64::from(pixel.zpos_fine >> 8);
        let depth = ((((8388351.9 - z) / c.p.zc_mul + 1.0).powi(2) - 1.0) / c.p.zcorr).max(0.0);
        if depth * c.p.step_width > nearest + plane_radius { continue; }
        let (start, direction) = mb3d::calc::pixel_ray(&c.p, index as i32 % w, index as i32 / w);
        let squared = (0..3).map(|axis| {
            (start[axis] + direction[axis] * depth - origin[axis]).powi(2)
        }).sum::<f64>();
        nearest = nearest.min(squared.sqrt());
        if nearest <= view_distance * 0.5 { return 0.5; }
    }
    (nearest / view_distance).clamp(0.5, 1.0)
}
#[no_mangle]
pub extern "C" fn mb3dx_rust_pick(x: f64, y: f64, out: *mut f64, focus: *mut f64) -> i32 {
    if !(0.0..=1.0).contains(&x) || !(0.0..=1.0).contains(&y) {
        return 0;
    }
    let Ok(cache) = caches().lock() else { return 0 };
    let Some(c) = cache[0].as_ref() else { return 0 };
    let w = c.p.width as usize;
    let h = c.p.height as usize;
    let ix = ((x * w as f64) as usize).min(w - 1);
    let iy = ((y * h as f64) as usize).min(h - 1);
    let si = &c.gbuf[iy * w + ix];
    if si.is_background() {
        return 0;
    }
    let z = (si.zpos_fine >> 8) as f64;
    let depth = (((8388351.9 - z) / c.p.zc_mul + 1.0).powi(2) - 1.0) / c.p.zcorr;
    let (start, dir) = mb3d::calc::pixel_ray(&c.p, ix as i32, iy as i32);
    unsafe {
        if !out.is_null() {
            for k in 0..3 {
                *out.add(k) = start[k] + dir[k] * (depth - 4.0 * c.p.de_stop as f64).max(0.0);
            }
        }
        if !focus.is_null() {
            *focus = depth * c.p.step_width * c.scene.zoom / 2.1345;
        }
    }
    1
}
#[no_mangle]
pub extern "C" fn mb3dx_rust_depth(
    path: *const c_char,
    preview: i32,
    w: i32,
    h: i32,
    err: *mut c_char,
) -> i32 {
    let result = std::panic::catch_unwind(|| -> Result<(), String> {
        let path = text(path)?;
        let cache = caches().lock().map_err(|_| "Rust cache lock failed")?;
        let c = cache[usize::from(preview != 0)]
            .as_ref()
            .ok_or("No Rust depth buffer available")?;
        let (sw, sh) = (c.p.width as usize, c.p.height as usize);
        if w < 1 || h < 1 || sw % w as usize != 0 || sh % h as usize != 0 {
            return Err("Depth dimensions do not match the render".into());
        }
        let (w, h) = (w as usize, h as usize);
        let (nx, ny) = (sw / w, sh / h);
        let mut depth = vec![0u16; w * h];
        for y in 0..h {
            for x in 0..w {
                let mut sum = 0u64;
                for j in 0..ny {
                    for i in 0..nx {
                        let s = &c.gbuf[(y * ny + j) * sw + x * nx + i];
                        if !s.is_background() {
                            sum += (65535 - (s.zpos() * 2).min(65535)) as u64;
                        }
                    }
                }
                depth[y * w + x] = ((sum + (nx * ny / 2) as u64) / (nx * ny) as u64) as u16;
            }
        }
        mb3d::png::write_gray16(&path, w, h, &depth).map_err(|e| e.to_string())
    });
    match result {
        Ok(Ok(())) => 1,
        Ok(Err(e)) => {
            error(err, &e);
            0
        }
        Err(_) => {
            error(err, "Rust depth export failed");
            0
        }
    }
}
