//! Reflections and transparency of the normal renderer (`CalcSR.pas`) and
//! the normals calculated from the z-buffer (`NormalsOnZbuf`,
//! ImageProcess.pas), two of MB3D's automatic post processing steps.
//!
//! The reflection pass runs after painting: for every object pixel the
//! view ray is reflected (or refracted into transparent material, with
//! Fresnel reflection and absorption), marched to the next surface, which
//! gets its own normal, colour, hard shadow and DE ambient occlusion, and
//! is lit like a painted pixel (`CalcPixelColorSvec(Trans)`), up to
//! `SRreflectioncount` times.  The specular colour of the palette is the
//! amount of reflected light, its alpha the transparency.

use crate::calc::{CalcParams, Marcher};
use crate::gbuffer::SiLight;
use crate::lighting::{LightVals, PaintCamera, Plv, Sample, ShadeOpts};
use crate::math::*;
use crate::scene::{CameraOptic, Scene};

type S3 = [f32; 3];

#[inline]
fn s3(v: &Vec3) -> S3 {
    [v[0] as f32, v[1] as f32, v[2] as f32]
}
#[inline]
fn add3(a: S3, b: S3) -> S3 {
    [a[0] + b[0], a[1] + b[1], a[2] + b[2]]
}
#[inline]
fn sub3(a: S3, b: S3) -> S3 {
    [a[0] - b[0], a[1] - b[1], a[2] - b[2]]
}
#[inline]
fn mul3(a: S3, b: S3) -> S3 {
    [a[0] * b[0], a[1] * b[1], a[2] * b[2]]
}
#[inline]
fn sc3(a: S3, s: f32) -> S3 {
    [a[0] * s, a[1] * s, a[2] * s]
}
#[inline]
fn dot3(a: S3, b: S3) -> f32 {
    a[0] * b[0] + a[1] * b[1] + a[2] * b[2]
}
#[inline]
fn spow(v: S3, e: f32) -> S3 {
    [v[0].powf(e), v[1].powf(e), v[2].powf(e)]
}
#[inline]
fn lin2(sv1: S3, sv2: S3, w1: f32) -> S3 {
    [sv2[0] + w1 * (sv1[0] - sv2[0]), sv2[1] + w1 * (sv1[1] - sv2[1]), sv2[2] + w1 * (sv1[2] - sv2[2])]
}
#[inline]
fn norm_to(n: f64, v: Vec3) -> Vec3 {
    let d = n / (v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + 1e-100).sqrt();
    [v[0] * d, v[1] * d, v[2] * d]
}
fn normal_of(si: &SiLight) -> Vec3 {
    [si.normal[0] as f64 / 32767.0, si.normal[1] as f64 / 32767.0, si.normal[2] as f64 / 32767.0]
}

// ---------------------------------------------------------------------------
// normals on the z-buffer

/// `GetDEstopFactor`: growth of the DE stop with the distance
pub fn de_stop_factor(sc: &Scene) -> f64 {
    let sw = sc.step_width();
    let ze = ((sc.z_end - sc.z_start) / sw).max(1e-16);
    let x1 = if sc.optic == CameraOptic::Panorama {
        0.01 * sc.height as f64 / (0.01f64.sin() * std::f64::consts::PI)
    } else {
        0.01 * sc.height as f64 / (0.01f64.sin() * (sc.fov_y.to_radians()).max(1.0 / 65535.0))
    };
    let x2 = sw * (x1 + ze) / x1;
    (x2 - sw) / (sw * ze.max(1.0 / 6.0))
}

/// `NormalsOnZbuf`: smoother normals from the positions of the neighbour
/// pixels (MB3D's "Normals on Z-buffer" post processing).
pub fn normals_on_zbuf(sc: &Scene, p: &CalcParams, gbuf: &mut [SiLight]) {
    let [left, top, w, h] = p.rect;
    let (w, h) = (w as usize, h as usize);
    if w == 0 || h == 0 {
        return;
    }
    let sw = p.step_width as f32;
    let planar = sc.optic as i32;
    let (aspect, sfov) = if sc.optic == CameraOptic::Panorama {
        (2.0f32, std::f32::consts::PI)
    } else {
        (sc.width as f32 / sc.height as f32, sc.fov_y.to_radians() as f32)
    };
    let zt = (sfov as f64 * 0.5).clamp(0.01, 1.5);
    let pl_optic_z = (zt.cos() * zt / zt.sin()) as f32;
    let dcorr = p.step_width / p.zcorr;
    let zc_inv = 1.0 / p.zc_mul;
    let dsf = de_stop_factor(sc) as f32;
    let (fw, fh) = (sc.width as f32, sc.height as f32);
    // CalcViewVec (without the stereo offset)
    let view_vec = |xp: f32, yp: f32| -> S3 {
        let cx = (0.5 - xp) * sfov * aspect;
        let cy = (yp - 0.5) * sfov;
        match planar {
            1 => {
                let v = [-cx, cy, pl_optic_z];
                sc3(v, 1.0 / dot3(v, v).sqrt())
            }
            2 => [-(cx.sin()) * cy.cos(), cy.sin(), cy.cos() * cx.cos()],
            _ => {
                let v = [-(cx.sin()), cy.sin(), cy.cos() * cx.cos()];
                sc3(v, 1.0 / dot3(v, v).sqrt())
            }
        }
    };
    let valid = |si: &SiLight| si.zpos() < 32768 && si.si_gradient < 32768;
    let dist = |si: &SiLight| -> f32 {
        let zf = (si.zpos_fine >> 8) as f64;
        ((((8388352.0 - zf) * zc_inv + 1.0).powi(2) - 1.0) * dcorr) as f32
    };
    const INV: f32 = -1e20;
    let w1 = w + 1;
    let mut buf = vec![[0f32; 3]; w1 * 3];
    let pos = |si: &SiLight, c: usize, yrow: f32, ypos: f32| -> S3 {
        let xp = [if planar != 2 { (c as i32 + left) as f32 * sw } else { 0.0 }, if planar != 2 { yrow } else { 0.0 }, 0.0];
        let v = view_vec((c as i32 + 1 + left) as f32 / fw, ypos);
        add3(sc3(v, dist(si)), xp)
    };
    // the first two rows
    for y in 1..=2usize {
        let r = y - 1;
        for x in 0..w {
            buf[x + y * w1] = if r < h && valid(&gbuf[r * w + x]) {
                pos(&gbuf[r * w + x], x, y as f32 * sw, (r as i32 + top) as f32 / fh)
            } else {
                [INV, 0.0, 0.0]
            };
        }
        buf[w + y * w1][0] = INV;
    }
    for x in 0..=w {
        buf[x][0] = INV;
    }
    let rec = |a: S3, b: S3, n: f32| -> S3 {
        let n = n * n;
        let w1 = 1.0 / (dot3(a, a) + n);
        let w2 = 1.0 / (dot3(b, b) + n);
        let wm = 1.0 / (w1 + w2);
        add3(sc3(a, w1 * wm), sc3(b, w2 * wm))
    };
    for y in 1..=h {
        let r = y - 1;
        for x in 0..w {
            if buf[x + w1][0] > -1e19 {
                let si = gbuf[r * w + x];
                let s0 = sw + dist(&si) * dsf;
                let (up, mid, down) = (buf[x], buf[x + w1], buf[x + 2 * w1]);
                let svy = if up[0] < -1e19 {
                    if down[0] > -1e19 {
                        sub3(mid, down)
                    } else {
                        [0.0, 1.0, 0.0]
                    }
                } else if down[0] > -1e19 {
                    rec(sub3(up, mid), sub3(mid, down), s0)
                } else {
                    sub3(up, mid)
                };
                let (lft, rgt) = (buf[x + w], buf[x + 1 + w1]);
                let svx = if lft[0] < -1e19 {
                    if rgt[0] > -1e19 {
                        sub3(mid, rgt)
                    } else {
                        [1.0, 0.0, 0.0]
                    }
                } else if rgt[0] > -1e19 {
                    rec(sub3(lft, mid), sub3(mid, rgt), s0)
                } else {
                    sub3(lft, mid)
                };
                // SVecToNormals(SVectorCross(svY, svX))
                let c = [svy[1] * svx[2] - svy[2] * svx[1], svy[2] * svx[0] - svy[0] * svx[2], svy[0] * svx[1] - svy[1] * svx[0]];
                let d = 32767.0 / ((c[0] as f64).powi(2) + (c[1] as f64).powi(2) + (c[2] as f64).powi(2) + 1e-100).sqrt();
                let n = &mut gbuf[r * w + x].normal;
                for k in 0..3 {
                    n[k] = (c[k] as f64 * d).round_ties_even().clamp(-32768.0, 32767.0) as i16;
                }
            }
        }
        for x in 0..w {
            buf[x] = buf[x + w1];
            buf[x + w1] = buf[x + 2 * w1];
        }
        let nr = r + 2;
        for x in 0..w {
            buf[x + 2 * w1] = if y < h.saturating_sub(1) && nr < h && valid(&gbuf[nr * w + x]) {
                pos(&gbuf[nr * w + x], x, (y + 2) as f32 * sw + top as f32 * sw, (y as i32 + 1 + top) as f32 / fh)
            } else {
                [INV, 0.0, 0.0]
            };
        }
    }
}

// ---------------------------------------------------------------------------
// reflections

struct SrCtx<'a> {
    cancel:&'a (dyn Fn()->bool+Sync),
    p: &'a CalcParams,
    lv: &'a LightVals,
    cam: &'a PaintCamera,
    mid: Vec3,
    /// `HSvecs` per entry of `lv.lights`
    hs_vecs: Vec<Vec3>,
    max_reflections: i32,
    sr_light_amount: f32,
    trans_di_const: f32,
    calc_trans: bool,
    only_difs: bool,
    absorption: f32,
    absorp_coeff: f32,
    light_scattering: f32,
    back_dist: f32,
    /// hard shadows: (lights as indices into `lv.lights` with their header
    /// index, soft, soft radius, max length multiplier)
    hs: Option<(Vec<(usize, usize)>, bool, f32, f32)>,
    /// DE ambient occlusion: (max length, first step random)
    ao: Option<(f32, bool)>,
    vol: bool,
    /// the rays are marched on the graphics card
    gpu: bool,
    capture_transmission: bool,
    translucency_thickness: bool,
    subsurface_amount: f32,
    static_difs: bool,
}

struct SrTracer<'a, 'c> {
    c: &'c SrCtx<'a>,
    m: Marcher<'a>,
    /// the G-buffer value of the pixel (`srPsiLight`)
    sr_si: SiLight,
    normal: Vec3,
    transmission: Transmission,
    difs_materials: Vec<(i32,Sd)>,
    t_amb: S3,
    plv: Plv,
    light_z: Vec<(f32, f32)>,
    calc_trans_r: bool,
    trans_flip_inside: bool,
    scale_amb_diff_down: bool,
    rnd: i32,
    guard: u32,
    /// MB3D_REFLECT_DEBUG=x,y: print the bounces of that pixel
    dbg: bool,
    /// set: give up the ray being marched (`march_until`)
    stop: Option<std::sync::Arc<std::sync::atomic::AtomicBool>>,
}

#[derive(Clone, Copy)]
struct Transmission {
    base: S3,
    light: S3,
    interior_light: S3,
    material_light: S3,
    entry_light: S3,
    entry_fog: S3,
    entry_visibility: S3,
    entry_specular: S3,
    entry_volume: S3,
    subsurface_light: S3,
    subsurface_through: S3,
    subsurface_background: S3,
    subsurface_valid: bool,
    entry_facing: f32,
    component: i32,
    distance: f32,
    opacity: f32,
}

impl Default for Transmission {
    fn default() -> Self { Self {
        base:[0.;3],light:[0.;3],interior_light:[0.;3],material_light:[0.;3],entry_light:[0.;3],
        entry_specular:[0.;3],entry_volume:[0.;3],entry_fog:[0.;3],entry_visibility:[1.;3],subsurface_light:[0.;3],
        subsurface_through:[1.;3],subsurface_background:[0.;3],subsurface_valid:false,
        entry_facing:0.,component:0,distance:0.,opacity:0.,
    }}
}

pub struct TransmissionCache {
    rgb: Vec<u8>,
    samples: Vec<Transmission>,
    subsurface_amount: f32,
    full_thickness: bool,
}

impl std::fmt::Debug for TransmissionCache {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.debug_struct("TransmissionCache").field("pixels", &self.samples.len()).finish()
    }
}

/// (specular colour, alpha, diffuse colour) of a surface for the next ray
type Sd = (S3, f32, S3);

/// Where a frame of [`SrTracer::step`] continues.
#[derive(Clone, Copy, PartialEq, Debug)]
enum At {
    /// the start of `CalcRay`
    Enter,
    /// `lab1`: the next ray (refracted or reflected) from the surface
    Next,
    /// the ray was marched
    Marched,
    /// the recursion for the hit returned
    Returned,
}

/// The locals of one `CalcRay` call.
#[derive(Clone, Debug)]
struct Frame {
    at: At,
    rit: i32,
    sr_vec: Vec3,
    zz: f64,
    t_absorb: S3,
    sd: Sd,
    calc_t: bool,
    tmp_loc: Vec3,
    tmp_norm: Vec3,
    tmp_absorb: S3,
    tmp_sd: Sd,
    zz_tmp: f64,
    spec_mul_t: f64,
    new_vec: Vec3,
    max_l: f64,
    /// where the ray starts
    origin: Vec3,
    transmission_start: Option<S3>,
    component: i32,
    tmp_materials: Vec<(i32,Sd)>,
    primary_transmission: bool,
}

impl Frame {
    fn new(zz: f64, sr_vec: Vec3, t_absorb: S3, sd: Sd, rit: i32) -> Self {
        Frame {
            at: At::Enter,
            rit,
            sr_vec,
            zz,
            t_absorb,
            sd,
            calc_t: false,
            tmp_loc: [0.0; 3],
            tmp_norm: [0.0; 3],
            tmp_absorb: [0.0; 3],
            tmp_sd: ([0.0; 3], 0.0, [0.0; 3]),
            zz_tmp: 0.0,
            spec_mul_t: 0.0,
            new_vec: [0.0; 3],
            max_l: 0.0,
            origin: [0.0; 3],
            transmission_start: None,
            component: 0,
            tmp_materials: Vec::new(),
            primary_transmission: false,
        }
    }
}

/// A ray to march: from the surface at `origin` (depth `zz`) in direction
/// `dir`, inside the set or not, bounce `rit`, at most `max_l` long.
#[derive(Clone, Copy, Debug)]
struct RayReq {
    origin: Vec3,
    dir: Vec3,
    zz: f64,
    inside: bool,
    rit: i32,
    max_l: f64,
}

/// The result of a march: the G-buffer value of the hit (normal, colour,
/// depth, shadows, occlusion) or of the open air (step count), the hit
/// position and depth, the length of the ray before (`zz2_paint`) and after
/// the search of the surface.
#[derive(Clone, Copy, Debug)]
struct RayHit {
    hit: bool,
    si: SiLight,
    pos: Vec3,
    zz: f64,
    zz2_paint: f64,
    zz2: f64,
    component: i32,
}

/// The pixel named by `MB3D_REFLECT_DEBUG` ("x,y").
fn debug_pixel() -> Option<(i32, i32)> {
    let v = std::env::var("MB3D_REFLECT_DEBUG").ok()?;
    let (a, b) = v.split_once(',')?;
    Some((a.trim().parse().ok()?, b.trim().parse().ok()?))
}

impl<'a, 'c> SrTracer<'a, 'c> {
    #[inline]
    fn update_de_stop(&mut self, zz: f64) {
        let p = self.c.p;
        self.m.ms_de_stop = (p.de_stop as f64 * (1.0 + zz.abs() * p.de_stop_factor as f64)) as f32;
    }

    #[inline]
    fn stopped(&self) -> bool {
        self.stop.as_ref().is_some_and(|f| f.load(std::sync::atomic::Ordering::Relaxed))
    }

    #[inline]
    fn component_trace(&self)->bool {
        self.c.calc_trans && self.c.p.difs && self.c.p.decomb.is_none()
            && !self.c.p.inside_rendering && !self.c.p.in_and_outside
    }
    fn sync_components(&mut self) {
        if self.c.static_difs {self.m.it.max_it=1;}
        self.m.it.difs_inside_components=Some(self.difs_materials.iter().map(|(id,_)|*id).collect());
        self.m.inside=!self.difs_materials.is_empty();
        self.m.calc_inside=self.m.inside;
    }

    fn toggle_inside(&mut self) {
        self.m.inside = !self.m.inside;
        self.m.calc_inside = !self.m.calc_inside;
    }

    #[inline]
    fn advance(&mut self, dir: &Vec3, d: f64) {
        add_weight(&mut self.m.it.c, dir, d);
    }

    fn rand(&mut self) -> f64 {
        self.rnd = self.rnd.wrapping_mul(0x343FD).wrapping_add(0x269EC3);
        ((self.rnd as u32 >> 8) & 0x7FFFFF) as f64 / 0x7FFFFF as f64
    }

    /// `minLengthToCutPlane`
    fn min_length_to_cut_plane(&self, len: &mut f64, plane: &mut usize, limit: f64, pos: &Vec3, v: &Vec3) {
        let p = self.c.p;
        *plane = 0;
        for k in 0..3 {
            if (p.cut_options >> k) & 1 != 0 && v[k].abs() > 1e-20 {
                let t = (p.cut_pos[k] - pos[k]) / v[k];
                if t > limit && t < *len {
                    *len = t;
                    *plane = k + 1;
                }
            }
        }
    }

    /// `CalcLightZPos`: depth of positional lights seen along the ray
    fn calc_light_z_pos(&mut self) {
        let p = self.c.p;
        let sw = p.step_width as f32;
        let av = self.plv.abs_view;
        let cp = self.plv.cam_pos;
        for (i, l) in self.c.lv.lights.iter().enumerate() {
            if !l.positional {
                continue;
            }
            let d = if av[0].abs() > 0.5 {
                (l.ln[0] - cp[0]) / av[0]
            } else if av[1].abs() > 0.5 {
                (l.ln[1] - cp[1]) / av[1]
            } else {
                (l.ln[2] - cp[2]) / av[2]
            };
            let z = d.max(0.0);
            let lp = 8388352.0 - p.zc_mul * (((z / sw) as f64 * p.zcorr + 1.0).sqrt() - 1.0);
            self.light_z[i] = (z, ((lp / 256.0) as f32).clamp(0.0, 32767.0));
        }
    }

    /// `AddLight`: light scattered inside transparent material between the
    /// start of the ray and the object position
    fn add_light(&self, dif: S3) -> S3 {
        let mut res = [0f32; 3];
        let s3w = (self.c.p.step_width as f32).powi(2);
        let (cam, obj) = (self.plv.cam_pos, self.plv.obj_pos);
        for l in &self.c.lv.lights {
            let stmp = if l.positional {
                let sv = sub3(obj, cam);
                let sv2 = sub3(l.ln, cam);
                let sv3 = sub3(l.ln, obj);
                let d2 = dot3(sv2, sv2) + s3w;
                let d3 = dot3(sv3, sv3) + s3w;
                let st = dot3(sv2, sv);
                if st <= 0.0 {
                    0.25 / d3 + 1.0 / d2
                } else {
                    let st2 = dot3(sv, sv);
                    if st2 <= st {
                        0.25 / d2 + 1.0 / d3
                    } else {
                        let q = sub3(l.ln, add3(cam, sc3(sv, st / st2)));
                        1.0 / (dot3(q, q) + s3w) + 0.25 / d3.max(d2)
                    }
                }
            } else {
                1.0
            };
            for k in 0..3 {
                res[k] += l.col[k] * stmp;
            }
        }
        mul3(dif, res)
    }

    /// Two deterministic quadrature samples in the material, with actual
    /// rays toward the lights. Beer-Lambert attenuation applies on both the
    /// incoming light path and the outgoing camera path. No image filtering.
    fn integrate_subsurface(&mut self, origin: Vec3, direction: Vec3, distance: f32, albedo: S3, component: i32) {
        if distance <= 0.0 { return; }
        let c=self.c;
        let density=subsurface_density(c.p, c.subsurface_amount);
        let extinction=albedo.map(|a| density+c.absorp_coeff*(1.0-a.clamp(0.0,1.0)));
        // A scattering event changes direction rather than destroying light.
        // Use a reduced transport coefficient for the diffuse light field;
        // clear (ballistic) transmission still uses the full extinction below.
        let transport_density=density*(1.0-SUBSURFACE_ANISOTROPY);
        let transport=albedo.map(|a|transport_density+c.absorp_coeff*(1.0-a.clamp(0.0,1.0)));
        let cut=distance.min(1.0/transport_density.max(1e-20));
        let intervals=[(0.0,cut),(cut,distance)];
        let dir=normalize(direction);
        let mut radiance=[0.;3];
        for (start,end) in intervals {
            if end<=start {continue;}
            let t=(start+end)*0.5;
            let point=add(origin,scale(dir,t as f64));
            let mut incoming=[0.;3];
            for (index,light) in c.lv.lights.iter().enumerate() {
                if light.col.iter().all(|channel|*channel<=0.0){continue;}
                let v=if light.positional {sub(c.hs_vecs[index],point)}else{c.hs_vecs[index]};
                let length=if light.positional {len(&v)}else{(c.p.zend*c.p.step_width).abs().max(10.0)};
                let attenuation=if light.positional {1.0/(length*length+c.p.step_width*c.p.step_width)}else{1.0};
                let Some(material_path)=subsurface_light_path(c.p,point,normalize(v),length,component,self.m.ms_de_stop,c.static_difs,c.cancel) else {continue;};
                for k in 0..3 {
                    // Forward scattering carries backlight toward the viewer;
                    // oblique illumination remains weaker. The normalized phase
                    // redistributes source light instead of adding a free rim.
                    let phase=subsurface_phase(dot(&dir,&normalize(v)) as f32);
                    incoming[k]+=light.col[k]/255.0*c.lv.s_diff*phase*attenuation as f32
                        *(-transport[k]*material_path).exp();
                }
            }
            // The existing ambient environment is an incident light field,
            // attenuated over the nearer material boundary, not a free glow.
            let ambient=sc3(add3(c.lv.amb_col,c.lv.amb_col2),0.5/255.0);
            for k in 0..3 {
                incoming[k]+=ambient[k]*(-transport[k]*t.min(distance-t)).exp();
                let camera_weight=(-transport[k]*start).exp()-(-transport[k]*end).exp();
                radiance[k]+=incoming[k]*transport_density*albedo[k].clamp(0.0,0.999)/transport[k].max(1e-20)*camera_weight;
            }
        }
        self.transmission.subsurface_light=add3(self.transmission.subsurface_light,mul3(self.transmission.subsurface_through,radiance));
        self.transmission.subsurface_through=mul3(self.transmission.subsurface_through,extinction.map(|s|(-s*distance).exp()));
        self.transmission.subsurface_valid=true;
    }

    /// Scattering builds with distance traveled through the material.
    /// Scale by the view width to keep the control useful at different zooms.
    fn scattering_weight(&self, path_steps: f32, light: S3) -> f32 {
        let optical_depth = 0.35 * self.c.light_scattering * (path_steps.max(0.0) / self.c.p.width.max(1) as f32);
        let peak = light.iter().copied().fold(1.0_f32, f32::max);
        -(-optical_depth).exp_m1() / peak
    }

    fn shade(&self, si: &SiLight, inside: Option<(S3, f32)>, exit_transmission: Option<f32>) -> crate::lighting::Shaded {
        let o = ShadeOpts {
            cancel:Some(self.c.cancel),
            emission_sample:None,
            emission_seed:self.m.it.c.iter().fold(0u32,|seed,v|seed.rotate_left(7)^(v.to_bits() as u32)),
            emission_point:Some((self.m.it.c,self.m.ms_de_stop as f64)),
            scale_amb_diff_down: if self.scale_amb_diff_down { Some(self.c.sr_light_amount) } else { None },
            inside_trans: inside,
            exit_transmission,
            light_z: Some(&self.light_z),
            svec: true,
        };
        self.c.lv.shade(si, &self.plv, self.c.cam, &o)
    }

    /// `CalcHS` / `CalcHSsoft` at the current position for the G-buffer
    /// value `si` (its normal)
    fn calc_hs(&mut self, si: &mut SiLight) {
        let _info_phase=crate::diagnostics::Scope::new(3);
        let Some((lights, soft, soft_radius, hs_mul)) = &self.c.hs else { return };
        let p = self.c.p;
        let sw = p.step_width;
        let zz = self.m.mzz.abs() as f32;
        let ic = self.m.it.c;
        let max_lhs = ((p.width + p.height) as f32 * 0.6 * (1.0 + 0.5 * zz.min(p.zend as f32 * 0.4) * (p.fov_y as f32).max(0.0) / p.height as f32) * hs_mul) as f64;
        let nvec = rotate_vector_reverse(&normal_of(si), &p.vgrads);
        let march = |me: &mut Self, hsvec: &Vec3, dt1: &mut f64, zz2: &mut f64, zz2mul: f64, zr: Option<(f32, f64)>| -> f32 {
            let mut rsfd = 1f32;
            let mut zrsoft = 1f32;
            let dmaxl = *dt1;
            let mut d = me.m.calc_de();
            let mut guard = 0;
            loop {
                guard += 1;
                let last_de = d;
                let st = ((d * p.z_step_div as f64 * rsfd as f64) as f32).min(me.m.ms_de_stop.max(0.4) * p.mh04zsd) as f64;
                *dt1 -= st;
                me.advance(hsvec, -st);
                *zz2 += st * zz2mul;
                me.update_de_stop(*zz2);
                d = me.m.calc_de();
                if let Some((zrs_mul, max_lhs)) = zr {
                    let r = ((dmaxl - *dt1) / max_lhs) as f32;
                    let r8 = (r * r) * (r * r);
                    zrsoft = zrsoft.min(((d - me.m.ms_de_stop as f64) * zrs_mul as f64 / (dmaxl - *dt1 + 0.11)) as f32 + r8 * r8);
                }
                if me.m.it.it_result >= me.m.max_its_result || d < me.m.ms_de_stop as f64 {
                    break;
                }
                if d > last_de + st {
                    d = last_de + st;
                }
                rsfd = if last_de > d + 1e-30 {
                    let t = (st / (last_de - d)) as f32;
                    if t < 1.0 {
                        t.max(0.5)
                    } else {
                        1.0
                    }
                } else {
                    1.0
                };
                if *dt1 < 0.0 || guard > 1_000_000 || (guard % 64 == 0 && me.stopped()) {
                    break;
                }
            }
            zrsoft
        };
        let cut_len = |me: &Self, v: &Vec3, len: &mut f64| {
            for k in 0..3 {
                if (p.cut_options >> k) & 1 != 0 && v[k].abs() > 1e-20 {
                    let t = (me.m.it.c[k] - p.cut_pos[k]) / v[k];
                    if t > 0.0 && t < *len {
                        *len = t;
                    }
                }
            }
        };
        if *soft {
            // CalcHSsoft: the last selected light
            let Some(&(li, _)) = lights.last() else { return };
            let l = &self.c.lv.lights[li];
            let zrs_mul = if l.positional {
                if l.visible & 6 == 2 {
                    70.0 / soft_radius
                } else {
                    40.0 / soft_radius
                }
            } else {
                80.0 / soft_radius
            };
            si.shadow |= 0xFC00;
            let mut zz2 = self.m.mzz;
            self.update_de_stop(zz as f64);
            let mut dmaxl = max_lhs;
            let mut hsvec = self.c.hs_vecs[li];
            if l.positional {
                let v = sub(add(s3d(l.ln), self.c.mid), self.m.it.c);
                let d = sqr_len(&v);
                if d > (l.lmax_l * hs_mul) as f64 {
                    return;
                }
                if d < (dmaxl * sw).powi(2) {
                    dmaxl = d.sqrt() / sw;
                }
                hsvec = norm_to(-sw, v);
            }
            let zz2mul = -dot(&hsvec, &self.m.vfov) / (sqr_len(&hsvec) * sqr_len(&self.m.vfov)).sqrt();
            if p.cut_options != 0 {
                cut_len(self, &hsvec, &mut dmaxl);
            }
            if dmaxl > 0.0 {
                if dot(&nvec, &hsvec) > 0.0 {
                    si.shadow &= 0x3FF;
                    return;
                }
                let mut dt1 = dmaxl;
                let zr = march(self, &hsvec, &mut dt1, &mut zz2, zz2mul, Some((zrs_mul, max_lhs)));
                si.shadow = (si.shadow & 0x3FF) | (((zr.clamp(0.0, 1.0) * 63.4).round_ties_even() as u16) << 10);
                self.m.it.c = ic;
            }
            return;
        }
        let mut mask = 0u16;
        for &(_, idx) in lights {
            mask |= 0x400 << idx;
        }
        si.shadow &= !mask;
        for &(li, idx) in lights {
            let l = &self.c.lv.lights[li];
            self.m.it.c = ic;
            let mut zz2 = self.m.mzz;
            self.update_de_stop(zz as f64);
            let mut dt1 = max_lhs;
            let mut hsvec = self.c.hs_vecs[li];
            if l.positional {
                let v = sub(add(s3d(l.ln), self.c.mid), self.m.it.c);
                let d = sqr_len(&v);
                if d > (l.lmax_l * hs_mul) as f64 {
                    si.shadow |= 0x400 << idx;
                    continue;
                }
                if d < (dt1 * sw).powi(2) {
                    dt1 = d.sqrt() / sw;
                }
                hsvec = norm_to(-sw, v);
            }
            let zz2mul = -dot(&hsvec, &self.m.vfov) / (sqr_len(&hsvec) * sqr_len(&self.m.vfov)).sqrt();
            if p.cut_options != 0 {
                cut_len(self, &hsvec, &mut dt1);
            }
            if dt1 > 0.0 {
                if dot(&nvec, &hsvec) > 0.0 {
                    si.shadow |= 0x400 << idx;
                    continue;
                }
                march(self, &hsvec, &mut dt1, &mut zz2, zz2mul, None);
                if dt1 > 0.0 {
                    si.shadow |= 0x400 << idx;
                }
            }
        }
        self.m.it.c = ic;
    }

    /// `CalcAmbShadowDEfor1pos`: DE ambient occlusion at the current
    /// position (no dithering)
    fn deao_1pos(&mut self, si: &mut SiLight, quality: i32, max_len: f32, first_random: bool) {
        let _info_phase=crate::diagnostics::Scope::new(4);
        si.amb_shadow = 0;
        if si.zpos() >= 32768 || si.si_gradient >= 32768 {
            return;
        }
        let p = self.c.p;
        let sw = p.step_width;
        self.m.it.calc_sit = false;
        let rot_v = normalise_matrix_to(sw, &p.vgrads);
        let s_max_d = max_len as f64 * 0.5 * ((p.height as f64).powi(2) + (p.width as f64).powi(2)).sqrt();
        let mut ms_de_stop = ((p.de_stop as f64 * (1.0 + self.m.mzz.abs() * p.de_stop_factor as f64)) as f32).min(1e6) as f64;
        let ic = self.m.it.c;
        let step_ao = ms_de_stop / p.de_stop as f64;
        let max_dist = s_max_d * step_ao.sqrt();
        let ray_dir = |ya: f64, za: f64| -> S3 {
            let (sy, cy) = ya.sin_cos();
            let (sz, cz) = za.sin_cos();
            [(sy * cz) as f32, (-sy * sz) as f32, (-cy) as f32]
        };
        let tau = std::f64::consts::TAU;
        let mut dirs: Vec<S3> = Vec::new();
        let (mut d_step_mul, d_min_a_dif, corr_w);
        if quality == 0 {
            let abr = 60f64.to_radians();
            for i in 0..3 {
                dirs.push(ray_dir(0.5 * abr, i as f64 * tau / 3.0));
            }
            d_step_mul = 1.8f64;
            d_min_a_dif = -1.0f32;
            corr_w = 0.3f32;
        } else {
            let abr = std::f64::consts::FRAC_PI_2 / (quality as f64 + 0.9);
            dirs.push(ray_dir(0.0, 0.0));
            for iy in 1..=quality {
                let n = (0.25f64.sin() * tau / abr).round_ties_even() as i32;
                for ix in 0..n {
                    dirs.push(ray_dir(abr * iy as f64, ix as f64 * tau / n as f64));
                }
            }
            d_step_mul = 1.0 + abr.sin();
            d_min_a_dif = (abr * 1.2).cos() as f32;
            corr_w = if quality == 1 { 0.2 } else { 0.1666 };
        }
        let inside = self.m.inside && !p.difs;
        if inside {
            d_step_mul *= 0.5;
        }
        let n = {
            let v = [si.normal[0] as f32, si.normal[1] as f32, si.normal[2] as f32];
            let l = dot3(v, v).sqrt().max(1e-30);
            [v[0] / l, v[1] / l, v[2] / l]
        };
        let rot_w = crate::deao::normal_matrix(n);
        if p.de_stop_factor != 0.0 {
            if !inside {
                ms_de_stop /= d_step_mul * d_step_mul;
            }
        } else {
            ms_de_stop = p.de_stop as f64 / (d_step_mul * d_step_mul);
        }
        let ray_count = dirs.len();
        let de_mul = if inside { 1.0 } else { (ray_count as f64 * 0.5).sqrt() };
        let abr = 1.2 / (1.0 / de_mul).clamp(-1.0, 1.0).asin();
        let md_d10 = 0.1 / (max_dist * de_mul);
        let mut min_ra = vec![0f32; ray_count];
        for (k, d) in dirs.iter().enumerate() {
            let v = [dot3(rot_w[0], *d), dot3(rot_w[1], *d), dot3(rot_w[2], *d)];
            let sv = rotate_vector_reverse(&[v[0] as f64, v[1] as f64, v[2] as f64], &rot_v);
            let mut dt1 = step_ao * d_step_mul;
            let mut s = 1f64;
            let mut end = false;
            let mut first = first_random;
            let mut guard = 0;
            loop {
                guard += 1;
                if first {
                    first = false;
                    dt1 *= self.rand() * 1.5 + 0.5;
                } else if dt1 > max_dist {
                    dt1 = max_dist;
                    end = true;
                }
                self.m.it.c = ic;
                add_weight(&mut self.m.it.c, &sv, dt1);
                if p.cut_options > 0 && self.m.at_cut_plane(dt1 * sw * 0.5) {
                    break;
                }
                let d2 = self.m.calc_de();
                if inside {
                    if d2 < ms_de_stop {
                        s = (dt1 / max_dist).powi(4);
                        break;
                    }
                    dt1 += dt1 * d_step_mul * 0.1 + ms_de_stop;
                } else {
                    s = s.min((d2 - ms_de_stop + dt1 * md_d10) / dt1);
                    if s < 0.02 {
                        break;
                    }
                    dt1 += d2.max(dt1 * d_step_mul);
                }
                if end || guard > 100_000 {
                    break;
                }
            }
            min_ra[k] = (s.max(0.0) * de_mul) as f32;
        }
        let mut amount = 0f64;
        if inside {
            amount = min_ra.iter().map(|&v| v as f64).sum();
        } else {
            for k in 0..ray_count {
                let mut s_add = 0f32;
                if min_ra[k] < 1.0 {
                    let max_add = 1.0 - min_ra[k];
                    for k2 in 0..ray_count {
                        if k2 == k {
                            continue;
                        }
                        let dt = dot3(dirs[k], dirs[k2]);
                        if dt > d_min_a_dif {
                            let overlap = min_ra[k2] - (dt.clamp(-1.0, 1.0).acos() as f64 * abr) as f32 + 1.0;
                            if overlap > 0.0 {
                                s_add += max_add.min(overlap) * corr_w;
                            }
                        }
                    }
                }
                amount += (s_add + min_ra[k]).min(1.0) as f64;
            }
        }
        si.amb_shadow = (16383.0 * (1.0 - amount / ray_count as f64)).round_ties_even().max(0.0) as u16;
        self.m.it.c = ic;
    }

    /// `CalcOpenAir`: the background seen by a reflected ray
    fn calc_open_air(&mut self, si: &mut SiLight, sd: &mut ([f32; 3], f32, [f32; 3]), t_absorb: &mut S3, calc_t: bool, zz: f32, primary: bool) {
        let lv = self.c.lv;
        let p = self.c.p;
        if (lv.far_fog || lv.sqr) && lv.s_depth.abs() > 1e-10 {
            let both = lv.far_fog && lv.sqr;
            let mut d = 1.0 - (1.0 + (self.sr_si.zpos() as i32 - 28000) as f32 * lv.s_depth).max(0.0);
            if d > 0.0 {
                d *= d;
                if both {
                    d *= d;
                }
            }
            let mut d2 = 1.0 - (1.0 - 28000.0 * lv.s_depth).max(0.0);
            if d2 > 0.0 {
                d2 *= d2;
                if both {
                    d2 *= d2;
                }
            }
            let mut e = d2 - d;
            if e > 0.0 {
                e = e.sqrt();
                if both {
                    e = e.sqrt();
                }
            }
            si.zpos_fine = ((60768.0 - e / lv.s_depth).clamp(32768.0, 65535.0).round_ties_even() as u32) << 16;
        } else {
            si.zpos_fine = 32768 << 16;
        }
        self.plv.z_pos = self.c.back_dist + p.zz_stmit_dif as f32;
        self.plv.zpos_dyn_fog = self.plv.z_pos;
        let mut inside = None;
        if calc_t && (self.trans_flip_inside ^ self.m.inside) {
            let tmp_amb = spow(sd.2, zz * self.c.absorption);
            let entering = *t_absorb;
            *t_absorb = mul3(entering, tmp_amb);
            let al = self.add_light(sd.2);
            let scatter = self.scattering_weight(zz, al);
            // Match the hit path: scattering accumulates along the segment,
            // even when absorption leaves almost no light at its far end.
            let along_path = lin2(*t_absorb, entering, 0.5);
            self.t_amb = add3(self.t_amb, sc3(mul3(al, along_path), scatter));
            inside = Some((sd.2, self.c.absorp_coeff));
        }
        let sh = self.shade(si, inside, None);
        let tmp_amb = sh.light.map(|v| (v / 255.0).clamp(0.0, 8.0));
        if primary && self.c.subsurface_amount > 0.0 && !self.m.inside {self.transmission.subsurface_background=tmp_amb;}
        self.t_amb = add3(self.t_amb, mul3(*t_absorb, tmp_amb));
    }

    /// The paint values along a reflected ray (the view, the positions of
    /// the lights and of the background, the depth colour).
    fn set_ray_paint(&mut self, new_vec: Vec3, zz2: f64) {
        let c = self.c;
        let p = c.p;
        let sw = p.step_width;
        // the paint values along the new ray
        let av = s3(&normalize(new_vec));
        self.plv.abs_view = av;
        self.plv.view = c.cam.to_view(av);
        self.calc_light_z_pos();
        let lv = c.lv;
        self.plv.zpos_dyn_fog = (zz2 * sw + p.zz_stmit_dif) as f32;
        let t = if lv.amb_rel_obj { self.plv.abs_view } else { self.plv.view };
        let fov_y = p.fov_y as f32;
        let mut ypos = t[1].clamp(-1.0, 1.0).asin() / fov_y + 0.5;
        if lv.bg.is_some() {
            let d = (p.fov_y / (2.0 * std::f64::consts::PI - p.fov_y).max(0.1)) as f32;
            if ypos > 1.0 {
                ypos = 1.0 + d * (1.0 - ypos);
                if ypos < 0.75 {
                    ypos = 1.5 - ypos;
                }
            } else if ypos < 0.0 {
                ypos = ypos.abs() * d;
                if ypos > 0.25 {
                    ypos = 0.5 - ypos;
                }
            }
        }
        self.plv.y_pos = ypos.clamp(0.0, 1.0);
        let dstep = (p.height as f64 / (p.fov_y * p.width as f64)) as f32;
        let mut xpos = t[0].atan2(t[2]) * dstep + 0.5;
        if lv.bg.is_some() {
            let d = 1.0 / (dstep * (2.0 * std::f32::consts::PI - 1.0 / dstep).max(0.1));
            if xpos > 1.0 {
                xpos = 1.0 + d * (1.0 - xpos);
            } else if xpos < 0.0 {
                xpos = xpos.abs() * d;
            }
        }
        self.plv.x_pos = xpos.clamp(0.0, 1.0);
        if !lv.amb_rel_obj {
            let mut s = self.plv.y_pos;
            if lv.depth_func == 1 {
                s *= s;
            } else if lv.depth_func != 0 {
                s = s.max(0.0).sqrt();
            }
            self.plv.dep_c = lin2(lv.depth_col2, lv.depth_col, s);
        }
    }

    /// `CalcRay`: follows the reflected (or refracted) ray from the current
    /// surface; `sd` = (specular colour, alpha, diffuse colour) of it.
    fn calc_ray(&mut self, zz: f64, sr_vec: Vec3, t_absorb: S3, sd: Sd, rit: i32) {
        let mut first=Frame::new(zz,sr_vec,t_absorb,sd,rit);
        first.component=if self.component_trace(){self.m.it.difs_component_id}else{0};
        // Opaque palette stops are not participating transmission media.
        first.primary_transmission=sd.1>0.0;
        let mut st = vec![first];
        let mut hit = None;
        while let Some(r) = self.step(&mut st, hit.take()) {
            hit = Some(self.march(&r));
        }
    }

    /// `CalcRay` as a resumable machine: runs the frames on `st` (the
    /// recursion of `CalcRay`, the last is the current one) until a ray has
    /// to be marched (returned; its result is passed in `hit` on the next
    /// call) or all are done.  The march is [`SrTracer::march`] on the CPU
    /// or a batch of rays on the graphics card.
    fn step(&mut self, st: &mut Vec<Frame>, mut hit: Option<RayHit>) -> Option<RayReq> {
        let c = self.c;
        let p = c.p;
        let sw = p.step_width;
        loop {
            let f = st.last_mut()?;
            match f.at {
                At::Enter => {
                    self.guard += 1;
                    if self.guard > 10_000 {
                        st.pop();
                        continue;
                    }
                    self.normal = rotate_vector_reverse(&self.normal, &p.vgrads);
                    self.calc_trans_r = if !c.calc_trans {
                        false
                    } else if !c.only_difs {
                        true
                    } else if c.gpu {
                        // which part the DE comes from (the last one evaluated)
                        p.decomb.as_ref().map_or(p.difs, |d| d.part2.difs)
                    } else {
                        self.m.calc_de();
                        self.m.last_difs
                    };
                    f.calc_t = self.calc_trans_r;
                    (f.tmp_loc, f.tmp_norm, f.tmp_absorb, f.tmp_sd, f.zz_tmp, f.spec_mul_t) = (self.m.it.c, self.normal, f.t_absorb, f.sd, f.zz, 0.0);
                    f.at = At::Next;
                }
                At::Next => {
                    let t_absorb = f.t_absorb;
                    if t_absorb[0].abs() * 0.3 + t_absorb[1].abs() * 0.59 + t_absorb[2].abs() * 0.11 < 1e-4
                        && !(c.subsurface_amount > 0.0 && f.primary_transmission) {
                        st.pop();
                        continue;
                    }
                    let sr_vec = f.sr_vec;
                    let new_vec;
                    loop {
                        if f.calc_t {
                            let sd = f.sd;
                            let dstep = if self.component_trace() {
                                let exiting=self.difs_materials.iter().any(|(id,_)|*id==f.component);
                                if exiting&&self.difs_materials.len()==1 {c.trans_di_const as f64}
                                else if !exiting&&self.difs_materials.is_empty(){1.0/c.trans_di_const as f64}
                                else {1.0}
                            } else if self.trans_flip_inside ^ self.m.inside { c.trans_di_const as f64 } else { 1.0 / c.trans_di_const as f64 };
                            let dl = len(&sr_vec);
                            let nl = len(&self.normal);
                            f.spec_mul_t = -dot(&sr_vec, &self.normal) / (dl * nl);
                            let zz2 = 1.0 - dstep * dstep * (1.0 - f.spec_mul_t * f.spec_mul_t);
                            if zz2 <= 0.0 {
                                // Redirect the transmitted fraction into the reflected ray.
                                // A black specular palette must not absorb that fraction.
                                let transmission = sd.1.clamp(0.0, 1.0);
                                f.sd.0 = sd.0.map(|specular| specular * (1.0 - transmission) + transmission);
                                f.calc_t = false;
                                continue;
                            }
                            f.tmp_loc = self.m.it.c;
                            f.tmp_norm = self.normal;
                            f.tmp_absorb = f.t_absorb;
                            f.tmp_sd = f.sd;
                            f.zz_tmp = f.zz;
                            let mut nv = sub(sr_vec, scale(self.normal, dl / (nl * dstep) * (zz2.sqrt() - dstep * f.spec_mul_t)));
                            nv = scale(nv, dl / len(&nv));
                            let dt = dot(&nv, &self.normal).abs() / (dl * nl);
                            f.spec_mul_t = f.spec_mul_t.abs();
                            if dt.abs() > 1e-16 {
                                let a = f.spec_mul_t;
                                f.spec_mul_t = (((a - dstep * dt) / (a + dstep * dt)).powi(2) + ((dt - dstep * a) / (dt + dstep * a)).powi(2)) * 0.5;
                            }
                            let stmp = sd.0[0].max(sd.0[1]).max(sd.0[2]);
                            f.t_absorb = sc3(f.t_absorb, (1.0 - f.spec_mul_t * stmp as f64) as f32);
                            if f.primary_transmission && c.subsurface_amount > 0.0 {
                                self.transmission.subsurface_through=sc3(self.transmission.subsurface_through,(1.0-f.spec_mul_t).clamp(0.0,1.0) as f32);
                            }
                            if self.component_trace() {
                                f.tmp_materials=self.difs_materials.clone();
                                if let Some(i)=self.difs_materials.iter().position(|(id,_)|*id==f.component) {
                                    self.difs_materials.remove(i);
                                } else {self.difs_materials.push((f.component,f.sd));}
                                self.sync_components();
                            } else {self.toggle_inside();}
                            new_vec = nv;
                        } else {
                            let n = self.normal;
                            new_vec = sub(sr_vec, scale(n, 2.0 * dot(&n, &sr_vec) / sqr_len(&n)));
                        }
                        break;
                    }
                    let mut max_l = p.zend;
                    if p.cut_options != 0 {
                        let mut cp = 0usize;
                        let pos = self.m.it.c;
                        self.min_length_to_cut_plane(&mut max_l, &mut cp, 1.0, &pos, &new_vec);
                    }
                    f.new_vec = new_vec;
                    f.max_l = max_l;
                    f.origin = self.m.it.c;
                    f.at = At::Marched;
                    return Some(RayReq { origin: self.m.it.c, dir: new_vec, zz: f.zz, inside: self.m.calc_inside, rit: f.rit, max_l });
                }
                At::Marched => {
                    let h = hit.take().expect("the march of the ray");
                    let (new_vec, max_l, rit, calc_t) = (f.new_vec, f.max_l, f.rit, f.calc_t);
                    // the paint values along the ray from its first step
                    let step0 = (p.de_stop as f64 * 0.25).min(1.0);
                    self.plv.cam_pos = s3(&sub(add(f.origin, scale(new_vec, step0)), c.mid));
                    self.set_ray_paint(new_vec, h.zz2_paint);
                    if self.dbg {
                        eprintln!("bounce {rit}: new_vec {new_vec:?} open_air {} zz {:.4} zz2 {:.4} steps {}", !h.hit, h.zz, h.zz2, h.si.shadow & 0x3FF);
                    }
                    f.at = At::Returned;
                    let mut si = h.si;
                    if h.hit {
                        self.m.it.c = h.pos;
                        f.zz = h.zz;
                        self.normal = normal_of(&si);
                        self.plv.z_pos = (h.zz.abs() * sw + p.zz_stmit_dif) as f32;
                        self.plv.obj_pos = s3(&sub(h.pos, c.mid));
                        self.scale_amb_diff_down = self.calc_trans_r && rit < c.max_reflections;
                        let sd = f.sd;
                        let mut t_absorb = if calc_t { sc3(f.t_absorb, sd.1) } else { mul3(f.t_absorb, sd.0) };
                        let mut inside = None;
                        if self.trans_flip_inside ^ self.m.inside {
                            if calc_t && rit == 1 && c.capture_transmission {
                                self.transmission.distance = (h.zz2.min(max_l).max(0.0) * sw) as f32;
                                if c.translucency_thickness && self.component_trace() {
                                    // Frosting follows the visible material crossing.
                                    // A grazing ray refracted deep into the object must
                                    // not make a visually thin edge opaque. Background
                                    // transport and physical scattering still refract.
                                    let start=(p.de_stop as f64*0.25).min(1.0);
                                    let stop=(p.de_stop as f64*(1.0+f.zz_tmp.abs()*p.de_stop_factor as f64)) as f32;
                                    if let Some(path) = material_exit_path(p, f.origin, f.sr_vec, start, max_l,
                                        f.component, stop, c.cancel) {
                                        self.transmission.distance = (path * sw) as f32;
                                    }
                                }
                                self.transmission.opacity = sd.1;
                                self.transmission.component = f.component;
                                self.transmission.entry_facing = (dot(&normalize(f.tmp_norm), &normalize(f.sr_vec))
                                    .abs().clamp(0.0, 1.0)) as f32;
                            }
                            // absorption inside the material
                            let medium=if self.component_trace(){self.difs_materials.last().map_or(sd,|(_,material)|*material)}else{sd};
                            let tmp_amb = spow(medium.2, (h.zz2.min(max_l) as f32) * c.absorption);
                            let tmp_spec = t_absorb;
                            t_absorb = mul3(t_absorb, tmp_amb);
                            let al = self.add_light(medium.2);
                            if calc_t && rit == 1 && c.capture_transmission {
                                // Use the same scene lighting and material tint as
                                // the existing internal scattering term.
                                let peak=al.iter().copied().fold(1.0_f32,f32::max);
                                self.transmission.interior_light=mul3(tmp_spec,sc3(al,1.0/peak));
                                self.transmission.material_light = mul3(tmp_spec,self.transmission.material_light);
                            }
                            let scatter = self.scattering_weight(h.zz2.min(max_l) as f32, al);
                            let volume = sc3(mul3(al, lin2(t_absorb, tmp_spec, 0.5)), scatter);
                            self.t_amb = add3(self.t_amb, volume);
                            if calc_t && rit == 1 && c.capture_transmission { self.transmission.entry_volume = volume; }
                            if calc_t && f.primary_transmission && c.subsurface_amount > 0.0 {
                                self.integrate_subsurface(f.origin, new_vec, (h.zz2.min(max_l).max(0.0) * sw) as f32, medium.2, f.component);
                            }
                            inside = Some((medium.2, c.absorp_coeff));
                        }
                        if calc_t && rit == 1 && c.capture_transmission
                            && self.transmission.distance > 0.0 {
                            // Everything seen through the first material segment,
                            // including the exit surface's shading and reflections,
                            // must be extinguished by its translucency opacity.
                            // Keep only entry shading and volume light in the base.
                            f.transmission_start = Some(self.t_amb);
                        }
                        // Use the entered material's transparency at its exit.
                        let exit_transmission = if self.component_trace() {
                            self.difs_materials.iter().find(|(id,_)|*id==h.component).map(|(_,material)|material.1)
                        } else {(calc_t && inside.is_some()).then_some(sd.1)};
                        let sh = self.shade(&si, inside, exit_transmission);
                        if self.dbg {
                            eprintln!("  hit: pos {:?} si {si:?}\n  plv {:?}\n  light {:?} result {:?} spe {:?} {} dif {:?} t_absorb {t_absorb:?}", h.pos, self.plv, sh.light, sh.result, sh.spe, sh.spe_a, sh.dif);
                        }
                        let tmp_amb = sh.light.map(|v| (v / 255.0).clamp(0.0, 8.0));
                        if f.primary_transmission && calc_t && c.subsurface_amount>0.0 && inside.is_none()
                            && h.component!=self.transmission.component && sh.spe_a<0.01 {
                            self.transmission.subsurface_background=tmp_amb;
                            f.primary_transmission=false;
                        }
                        f.sd = (sh.spe, sh.spe_a, sh.dif);
                        self.t_amb = add3(self.t_amb, mul3(t_absorb, tmp_amb));
                        if !calc_t || !(self.trans_flip_inside ^ self.m.inside) {
                            t_absorb = mul3(t_absorb, sh.result);
                        }
                        f.t_absorb = t_absorb;
                        if rit < c.max_reflections {
                            let t_absorb = sc3(t_absorb, c.sr_light_amount);
                            let (zz, sd) = (f.zz, f.sd);
                            let mut next=Frame::new(zz,new_vec,t_absorb,sd,rit+1);
                            next.component=h.component;
                            next.primary_transmission=f.primary_transmission && calc_t;
                            st.push(next);
                        }
                    } else {
                        let mut sd = f.sd;
                        let mut t_absorb = if calc_t { sc3(f.t_absorb, sd.1) } else { mul3(f.t_absorb, sd.0) };
                        self.calc_open_air(&mut si, &mut sd, &mut t_absorb, calc_t, h.zz2.min(max_l) as f32, f.primary_transmission && calc_t);
                        (f.sd, f.t_absorb) = (sd, t_absorb);
                        if self.dbg {
                            eprintln!("  open air: t_absorb {t_absorb:?} t_amb {:?} plv {:?}", self.t_amb, self.plv);
                        }
                    }
                }
                At::Returned => {
                    if let Some(start) = f.transmission_start.take() {
                        self.transmission.light = sub3(self.t_amb, start);
                    }
                    if f.calc_t {
                        // now the reflected part of the refracting surface
                        self.m.it.c = f.tmp_loc;
                        self.normal = f.tmp_norm;
                        f.zz = f.zz_tmp;
                        f.sd = f.tmp_sd;
                        f.t_absorb = sc3(f.tmp_absorb, (f.spec_mul_t + (1.0 - f.spec_mul_t) * (1.0 - f.sd.1 as f64)) as f32);
                        if self.component_trace() {self.difs_materials=f.tmp_materials.clone();self.sync_components();}
                        else {self.toggle_inside();}
                        f.calc_t = false;
                        f.primary_transmission = false;
                        f.at = At::Next;
                    } else {
                        st.pop();
                    }
                }
            }
        }
    }

    /// The march of a reflected or refracted ray on the CPU (the part of
    /// `CalcRay` from the first step to the shadows and the ambient
    /// occlusion of the hit).
    fn march(&mut self, r: &RayReq) -> RayHit {
        self.march_until(r).expect("not stopped")
    }

    /// [`SrTracer::march`] that gives up (None) when the tracer's `stop`
    /// flag is set (checked every 64 steps of the ray and of its shadow ray).
    fn march_until(&mut self, r: &RayReq) -> Option<RayHit> {
        let c = self.c;
        let p = c.p;
        let sw = p.step_width;
        let new_vec = r.dir;
        let max_l = r.max_l;
        let mut zz = r.zz;
        self.m.it.c = r.origin;
        let zzplus = dot(&self.m.vfov, &new_vec) / (sqr_len(&self.m.vfov) * sqr_len(&new_vec) + 1e-100).sqrt();
        let last_zz = zz.abs() as f32;
        let mut zz2 = (p.de_stop as f64 * 0.25).min(1.0);
        zz += zz2 * zzplus;
        self.advance(&new_vec, zz2);
        self.update_de_stop(zz);
        let mut open_air = true;
        let mut step_count = 0f32;
        let mut de_limited = true;
        let mut rlast_sw = 0f64;
        if self.sr_si.si_gradient > 32767 {
            zz2 = p.zend;
        } else {
            open_air = false;
            let mut rsfmul = 1f32;
            let mut dtmp = self.m.calc_de();
            rlast_sw = dtmp * p.z_step_div as f64;
            let mut guard = 0u32;
            if dtmp > 1e-10 {
                loop {
                    let mut rlast_de = dtmp;
                    let mut dstep;
                    if c.vol {
                        dstep = dtmp;
                        self.m.mzz = zz.abs();
                        dstep = ((dstep - p.ms_de_sub as f64 * self.m.ms_de_stop as f64) * p.z_step_div as f64 * rsfmul as f64).max(0.11);
                        let s1 = (self.m.ms_de_stop.max(0.4) * p.mh04zsd) as f64;
                        if s1 < dstep {
                            dstep = s1;
                        }
                        if let Some(vl) = &p.vol {
                            let cc = self.m.it.c;
                            let vf = self.m.vfov;
                            vl.integrate(p, &cc, &vf, rlast_sw, self.m.mzz, &mut step_count);
                        }
                    } else {
                        dstep = ((dtmp - p.ms_de_sub as f64 * self.m.ms_de_stop as f64) * p.z_step_div as f64 * rsfmul as f64).max(0.11);
                        let s = (self.m.ms_de_stop.max(0.4) * p.mh04zsd) as f64;
                        let count = p.dfog_on_it == 0 || self.m.it.it_result == p.dfog_on_it as i32;
                        if s < dstep {
                            if count {
                                step_count += (s / dstep) as f32;
                            }
                            dstep = s;
                        } else if count {
                            step_count += 1.0;
                        }
                    }
                    rlast_sw = dstep;
                    zz2 += dstep;
                    if zz2 > max_l {
                        if c.vol {
                            rlast_sw = max_l - zz2 + rlast_sw;
                            self.advance(&new_vec, rlast_sw);
                            if let Some(vl) = &p.vol {
                                let cc = self.m.it.c;
                                let vf = self.m.vfov;
                                vl.integrate(p, &cc, &vf, rlast_sw, self.m.mzz, &mut step_count);
                            }
                            let _ = &mut rlast_de;
                        }
                        open_air = true;
                        break;
                    }
                    self.advance(&new_vec, dstep);
                    zz += dstep * zzplus;
                    self.update_de_stop(zz);
                    dtmp = self.m.calc_de();
                    if self.m.it.it_result >= self.m.max_its_result {
                        de_limited = false;
                        break;
                    }
                    if dtmp < self.m.ms_de_stop as f64 && self.m.it.it_result >= p.min_it {
                        break;
                    }
                    if dtmp > rlast_de + rlast_sw {
                        dtmp = rlast_de + rlast_sw;
                    }
                    rsfmul = if rlast_de > dtmp + 1e-10 {
                        let d = rlast_sw / (rlast_de - dtmp);
                        if d < 1.0 {
                            d.max(0.5) as f32
                        } else {
                            1.0
                        }
                    } else {
                        1.0
                    };
                    rlast_de = dtmp;
                    let _ = rlast_de;
                    guard += 1;
                    if guard > 1_000_000 {
                        open_air = true;
                        break;
                    }
                    if guard % 64 == 0 && self.stopped() {
                        return None;
                    }
                }
            }
        }
        let zz2_paint = zz2;
        let lv = c.lv;
        let mut si = SiLight::default();
        si.shadow = if c.vol {
            crate::lighting::encode_vlight(step_count)
        } else {
            if self.m.inside {
                step_count *= 200.0 * p.de_stop / p.width as f32;
            }
            step_count.clamp(0.0, 1023.0).round_ties_even() as u16
        };
        if !open_air {
            if p.de_add_steps != 0 {
                if de_limited {
                    let mut itmp = p.de_add_steps;
                    let mut ds = rlast_sw * -0.5;
                    let mut d = self.m.calc_de();
                    while (d - self.m.ms_de_stop as f64).abs() > 0.001 {
                        zz2 += ds;
                        zz += ds * zzplus;
                        self.advance(&new_vec, ds);
                        self.update_de_stop(zz);
                        itmp -= 1;
                        if itmp <= 0 {
                            break;
                        }
                        d = self.m.calc_de();
                        ds = if d < self.m.ms_de_stop as f64 { ds.abs() * -0.55 } else { ds.abs() * 0.55 };
                    }
                } else {
                    let before = zz2;
                    let vf = self.m.vfov;
                    self.m.vfov = new_vec;
                    self.m.mzz = zz2;
                    self.m.bin_search_it();
                    zz2 = self.m.mzz;
                    self.m.vfov = vf;
                    zz += (zz2 - before) * zzplus;
                }
            }
            self.m.mzz = zz.abs();
            let nn = if p.normals_on_de { self.m.calculate_normals(&mut si) } else { self.m.calculate_normals_on_smooth_it(&mut si) };
            let v = if de_limited {
                32767.0 - (nn + p.d_col_plus + p.col_var_de_stop_mul * ((self.m.ms_de_stop as f64 * sw).ln() as f32)) * p.mcts_m
            } else {
                32767.0 - nn * p.mcts_m
            };
            si.si_gradient = min_max_clip_15bit(v);
            if p.color_on_it != 0 {
                self.m.do_color_on_it();
            }
            self.m.do_color(&mut si);
            let ds = if lv.far_fog || lv.sqr {
                (((zz2 + last_zz as f64).powi(2) - last_zz as f64 + 1e-30).max(0.0)).sqrt()
            } else {
                zz2
            };
            {
                let v = (p.zc_mul * ((ds.max(0.0) * p.zcorr + 1.0).sqrt() - 1.0)).round_ties_even() as i64;
                let z = (8388352 - v).clamp(0, 8388352) as u32;
                let mut r = z << 8;
                if p.sm_normals > 0 {
                    r |= ((self.m.s_roughness * 255.0).round_ties_even() as u32) & 0xFF;
                }
                si.zpos_fine = r;
            }
            let saved_de_stop = self.m.ms_de_stop;
            if c.hs.is_some() {
                self.m.mzz = zz.abs();
                self.calc_hs(&mut si);
                if self.stopped() {
                    return None;
                }
            }
            if let Some((max_len, first)) = c.ao {
                let q = match r.rit {
                    1 => 2,
                    2 => 1,
                    _ => 0,
                };
                self.m.mzz = zz.abs();
                // Trace ambient occlusion against other geometry, then weight
                // the containing media by their actual transparency. Palette
                // interpolation must not turn nearly clear glass into a solid
                // enclosure. Fully opaque objects remain in the AO field.
                let ignored = std::mem::take(&mut self.m.it.difs_ignored_components);
                let mut enclosure_transmission = 1.0_f32;
                if self.component_trace() {
                    self.m.it.difs_ignored_components = self.difs_materials.iter()
                        .filter(|(_,material)|material.1 > 0.0).map(|(id,material)| {
                            enclosure_transmission *= material.1.clamp(0.0,1.0);
                            *id
                        }).collect();
                }
                self.deao_1pos(&mut si, q, max_len, first);
                self.m.it.difs_ignored_components = ignored;
                si.amb_shadow = (16383.0 - (16383.0-si.amb_shadow as f32)*enclosure_transmission)
                    .round_ties_even().clamp(0.0,16383.0) as u16;
                si.amb_shadow = ((si.amb_shadow as i32 * 8) / (8 + r.rit)) as u16;
            } else {
                si.amb_shadow = 5000;
            }
            self.m.ms_de_stop = saved_de_stop;
        } else {
            si.zpos_fine = 32768 << 16;
        }
        let component=if !open_air&&self.component_trace(){self.m.calc_de();self.m.it.difs_component_id}else{0};
        Some(RayHit { hit: !open_air, si, pos: self.m.it.c, zz, zz2_paint, zz2,component })
    }

    /// One pixel of `TSRCalcThread.Execute`: returns the new colour, or
    /// None to keep the painted one.
    fn pixel<S: Sample>(&mut self, x: i32, y: i32, si: &SiLight) -> Option<[S; 3]> {
        self.transmission = Transmission::default();
        let (mzz, vf, sv, sd) = self.start_pixel(x, y, si)?;
        self.calc_ray(mzz, vf, sv, sd, 1);
        self.transmission.base = sub3(self.t_amb, self.transmission.light);
        Some(reflection_colour(self.c.lv, self.t_amb))
    }

    /// The pixel's surface (refined, or on the cutting plane), its shading
    /// and the start of `calc_ray`: (depth, view vector, absorption, `sd`);
    /// None to keep the painted colour.
    fn start_pixel(&mut self, x: i32, y: i32, si: &SiLight) -> Option<(f64, Vec3, S3, Sd)> {
        let c = self.c;
        let p = c.p;
        let sw = p.step_width;
        let lv = c.lv;
        if si.zpos() >= 32768 {
            return None;
        }
        self.sr_si = *si;
        self.difs_materials.clear();
        self.m.it.difs_inside_components=if self.component_trace(){Some(Vec::new())}else{None};
        self.guard = 0;
        let inside = if p.in_and_outside && si.otrap & 0x8000 != 0 { false } else { p.inside_rendering };
        self.m.inside = inside;
        self.m.calc_inside = inside;
        self.pixel_marcher(x, y);
        self.plv.cam_pos = s3(&sub(self.m.it.c, c.mid));
        let av = s3(&normalize(self.m.vfov));
        self.plv.abs_view = av;
        self.plv.view = c.cam.to_view(av);
        self.plv.y_pos = y as f32 / p.height as f32;
        self.plv.x_pos = (x + 1) as f32 / p.width as f32;
        {
            let ys = self.plv.y_pos;
            let s = match lv.depth_func {
                1 => ys * ys,
                0 => ys,
                _ => ys.max(0.0).sqrt(),
            };
            self.plv.dep_c = lin2(lv.depth_col2, lv.depth_col, s);
        }
        self.calc_light_z_pos();
        self.m.it.calc_sit = false;
        let zf = (si.zpos_fine >> 8) as f64;
        let zpos_of = |iz: f64| (((8388351.5 - iz) / p.zc_mul + 1.0).powi(2) - 1.0) / p.zcorr;
        self.m.mzz = zpos_of(zf);
        let vf = self.m.vfov;
        add_weight(&mut self.m.it.c, &vf, self.m.mzz);
        self.update_de_stop(self.m.mzz);
        if si.si_gradient < 32768 {
            let mut d = self.m.calc_de();
            if d < self.m.ms_de_stop as f64 * 0.5 {
                return None;
            }
            let de_limited = self.m.it.it_result < self.m.max_its_result || d <= self.m.ms_de_stop as f64;
            if de_limited {
                let dt1 = self.m.mzz - zpos_of(zf - 1.0);
                self.m.bin_search(&mut d, dt1);
            } else {
                self.m.bin_search_it();
            }
        } else {
            // on a cutting plane
            let mut dt1 = p.zend;
            let mut cp = 0;
            if p.cut_options != 0 {
                let pos = self.m.it.c;
                self.min_length_to_cut_plane(&mut dt1, &mut cp, -2.0, &pos, &vf);
            }
            if dt1.abs() > 1.0 {
                return None;
            }
            self.m.mzz += dt1;
            add_weight(&mut self.m.it.c, &vf, dt1);
            self.update_de_stop(self.m.mzz);
        }
        self.normal = normal_of(si);
        self.plv.z_pos = (self.m.mzz * sw + p.zz_stmit_dif) as f32;
        self.plv.obj_pos = s3(&sub(self.m.it.c, c.mid));
        self.plv.zpos_dyn_fog = self.plv.z_pos;
        self.calc_trans_r = c.calc_trans && (!c.only_difs || self.m.last_difs);
        self.scale_amb_diff_down = self.calc_trans_r;
        let sh = self.shade(si, None, None);
        self.t_amb = sh.light.map(|v| (v / 255.0).clamp(0.0, 8.0));
        if c.capture_transmission {
            self.transmission.entry_light = self.t_amb;
            self.transmission.entry_fog=sh.depth_fog_light.map(|v|v/255.0);
            self.transmission.entry_visibility=sh.result;
            self.transmission.entry_specular = mul3(sh.specular_light.map(|v| v / 255.0), sh.result);
            // Frosted opacity must use the visible boundary's diffuse lighting,
            // including facing and shadows. Internal light intensity alone would
            // illuminate a backlit opaque face as if it faced every light.
            self.scale_amb_diff_down=false;
            let opaque=self.shade(si,None,None);
            self.scale_amb_diff_down=self.calc_trans_r;
            let specular=mul3(opaque.specular_light.map(|v|v/255.0),opaque.result);
            let diffuse=sub3(opaque.light.map(|v|v/255.0),specular).map(|v|v.max(0.0));
            self.transmission.material_light=translucency_material_light([1.;3],[1.;3],diffuse);
        }
        let sv = sc3(sh.result, c.sr_light_amount);
        let mzz = self.m.mzz;
        if self.dbg {
            eprintln!("CPU surface: pos {:?} zz {mzz:.4} si {si:?}\n  plv {:?}\n  light {:?} result {:?} spe {:?} {} dif {:?}", self.m.it.c, self.plv, sh.light, sh.result, sh.spe, sh.spe_a, sh.dif);
        }
        if self.component_trace(){self.m.calc_de();}
        Some((mzz, vf, sv, (sh.spe, sh.spe_a, sh.dif)))
    }

    /// The marcher's view of pixel x, y (its view vector, gradients and
    /// start position).
    fn pixel_marcher(&mut self, x: i32, y: i32) {
        let p = self.c.p;
        self.m.cafy = (y as f64 / p.height as f64 - 0.5) * p.fov_y;
        self.m.calc_vgrads_fov(x + 1);
        self.m.calc_start_pos(x, y);
    }

}

fn reflection_colour<S: Sample>(lv: &LightVals, colour: S3) -> [S; 3] {
    let mut t = colour.map(|v| v.clamp(0.0, 1.0));
    if lv.sqr {
        t = t.map(|v| v.sqrt());
    }
    if lv.gamma_h != 0 {
        let g = if lv.gamma_h > 0 { t.map(|v| v.sqrt()) } else { t.map(|v| v * v) };
        t = add3(t, sc3(sub3(g, t), lv.s_gamma));
    }
    t.map(S::from_unit)
}

#[inline]
/// The resident memory of the process in MB (Linux; 0 elsewhere): the
/// memory prints of `MB3D_GPU_TIMING`.
pub fn rss_mb() -> u64 {
    std::fs::read_to_string("/proc/self/status")
        .ok()
        .and_then(|s| s.lines().find(|l| l.starts_with("VmRSS:")).and_then(|l| l.split_whitespace().nth(1)?.parse::<u64>().ok()))
        .unwrap_or(0)
        / 1024
}

fn s3d(v: S3) -> Vec3 {
    [v[0] as f64, v[1] as f64, v[2] as f64]
}

/// Bound reflection working memory to half of available memory, capped at 2M pixels.
const REFLECT_BAND_PIXELS: usize = 1 << 21;
const REFLECT_BAND_PIXELS_MIN: usize = 1 << 18;
const REFLECT_BAND_BYTES: u64 = 1792;
fn band_pixels(free: Option<u64>) -> usize {
    match free {
        Some(f) => ((f / 2) / REFLECT_BAND_BYTES).clamp(REFLECT_BAND_PIXELS_MIN as u64, REFLECT_BAND_PIXELS as u64) as usize,
        None => REFLECT_BAND_PIXELS,
    }
}

fn can_cache_transmission(sc: &Scene, p: &CalcParams) -> bool {
    if sc.transmission_cache.is_none() || p.rect != [0, 0, p.width, p.height] {
        return false;
    }
    // Budget in bytes so oversampling can use the same cache when memory permits.
    // The cache retains one sample and an RGB baseline for each render pixel.
    let pixels = u64::from(p.width as u32) * u64::from(p.height as u32);
    let bytes = pixels * (std::mem::size_of::<Transmission>() as u64 + 3);
    let budget = crate::render::memory_available()
        .map_or(256 << 20, |available| (available / 2).min(512 << 20));
    bytes <= budget
}

/// `CalcSRT`: the reflection pass over the painted image `rgb` of the
/// G-buffer `gbuf` (both covering `p.rect`).
///
/// `cancel` ("Stop") ends it early; the picture is then half done (the
/// callers drop it).
#[allow(clippy::too_many_arguments)]
pub fn reflections<S: Sample>(
    sc: &Scene,
    p: &CalcParams,
    gbuf: &[SiLight],
    rgb: &mut [S],
    cam: &PaintCamera,
    lv: &LightVals,
    threads: usize,
    progress: &(dyn Fn(usize, usize) + Sync),
    cancel: &(dyn Fn() -> bool + Sync),
) {
    if let Some(cache) = &sc.transmission_cache {
        let cached = cache.lock().ok();
        if let Some(data) = cached.as_deref().and_then(Option::as_ref)
            .filter(|data| p.rect == [0, 0, p.width, p.height] && data.rgb.len() == rgb.len()
                && data.full_thickness == sc.translucency_enabled
                && data.subsurface_amount == if sc.subsurface_scattering && sc.translucency_enabled {sc.subsurface_amount}else{0.0})
        {
            for (dst, &src) in rgb.iter_mut().zip(&data.rgb) {
                *dst = S::from_paint(f32::from(src));
            }
            if sc.transmission_blur > 0.0 || sc.translucency_glow != 0.0 || (sc.subsurface_scattering && sc.translucency_enabled && sc.subsurface_amount > 0.0) {
                blur_transmission(rgb, gbuf, &data.samples, p, lv, sc.transmission_blur,
                    sc.translucency_glow, if sc.subsurface_scattering && sc.translucency_enabled {sc.subsurface_amount}else{0.0}, threads.min(p.height as usize).max(1), cancel);
            }
            progress(p.height as usize, p.height as usize);
            return;
        }
    }
    #[cfg(feature = "gpu")]
    if !(sc.mc.transparency && ((p.difs&&p.decomb.is_none()) || (sc.subsurface_scattering && sc.translucency_enabled && sc.subsurface_amount > 0.0) || sc.transmission_blur > 0.0 || sc.translucency_glow != 0.0
        || (sc.mc.reflection_depth >= 2 && can_cache_transmission(sc, p))))
        && crate::gpu::enabled() && crate::gpu::unsupported(p).is_none() {
        let [x0, y0, w, h] = p.rect;
        let (wu, hu) = (w.max(1) as usize, h.max(0) as usize);
        let band_px = std::env::var("MB3D_REFLECT_BAND_PIXELS")
            .ok()
            .and_then(|v| v.parse().ok())
            .unwrap_or_else(|| band_pixels(crate::render::memory_available()));
        let rows = (band_px / wu).max(1);
        let mut q = p.clone();
        let mut y = 0;
        while y < hu {
            if cancel() {
                return;
            }
            let bh = rows.min(hu - y);
            q.rect = [x0, y0 + y as i32, w, bh as i32];
            let (g, c) = (&gbuf[y * wu..(y + bh) * wu], &mut rgb[y * wu * 3..(y + bh) * wu * 3]);
            match reflections_gpu(sc, &q, g, c, cam, lv, threads, cancel) {
                Ok(()) => {
                    y += bh;
                    progress(y, hu);
                }
                // the program ends (gpu::abort_all): no CPU pass either
                Err(e) if e == "cancelled" => return,
                // (a failed band is unchanged: it and the rest on the CPU)
                Err(e) => {
                    eprintln!("reflections on the GPU failed, calculated on the CPU: {e}");
                    q.rect = [x0, y0 + y as i32, w, (hu - y) as i32];
                    // (the rows go on counting from where the card stopped)
                    return reflections_cpu(sc, &q, &gbuf[y * wu..], &mut rgb[y * wu * 3..], cam, lv, threads, &|d, _| progress(y + d, hu), cancel);
                }
            }
        }
        let s = crate::gpu::last_status();
        if s.starts_with("GPU") && !s.contains("+reflections") {
            crate::gpu::set_status(format!("{s} +reflections"));
        }
        return;
    }
    reflections_cpu(sc, p, gbuf, rgb, cam, lv, threads, progress, cancel)
}

/// [`reflections`] on the CPU.
#[allow(clippy::too_many_arguments)]
fn reflections_cpu<S: Sample>(
    sc: &Scene,
    p: &CalcParams,
    gbuf: &[SiLight],
    rgb: &mut [S],
    cam: &PaintCamera,
    lv: &LightVals,
    threads: usize,
    progress: &(dyn Fn(usize, usize) + Sync),
    cancel: &(dyn Fn() -> bool + Sync),
) {
    let mc = &sc.mc;
    let mid = sc.stereo_mid();
    let m1 = normalise_matrix_to(1.0, &p.vgrads);
    let hs_vecs: Vec<Vec3> = lv
        .lights
        .iter()
        .map(|l| {
            if l.positional {
                add(s3d(l.ln), mid)
            } else {
                rotate_vector_reverse(&norm_to(-p.step_width, s3d(l.ln)), &m1)
            }
        })
        .collect();
    let hs = sc.shadows.map(|h| {
        let lights: Vec<(usize, usize)> =
            lv.lights.iter().enumerate().filter(|(_, l)| (h.lights >> l.idx) & 1 != 0).map(|(i, l)| (i, l.idx)).collect();
        (lights, h.soft, h.soft_radius.max(0.001), h.max_len_mul)
    });
    let ao = sc.ao.as_ref().map(|_| {
        let d = sc.deao.unwrap_or_default();
        (d.max_len, d.first_step_random)
    });
    let ctx = SrCtx {
        cancel,
        p,
        lv,
        cam,
        mid,
        hs_vecs,
        max_reflections: mc.reflection_depth as i32,
        sr_light_amount: mc.reflection_amount.clamp(0.0, 100.0),
        // bOptions2 and 6 = 4 (an interpolation hybrid of dIFS): index 1
        trans_di_const: mc.refraction_index,
        calc_trans: mc.transparency,
        only_difs: mc.only_difs,
        absorption: (mc.absorption as f64 * p.step_width) as f32,
        absorp_coeff: mc.absorption,
        light_scattering: mc.scattering.max(0.0),
        back_dist: (((8388352.0 / p.zc_mul + 1.0).powi(2) - 1.0) * p.step_width / p.zcorr) as f32,
        hs,
        ao,
        vol: p.vol.is_some(),
        gpu: false,
        static_difs: static_difs_instances(p),
        subsurface_amount: if sc.subsurface_scattering && sc.translucency_enabled {sc.subsurface_amount.clamp(0.0,1.0)}else{0.0},
        translucency_thickness: sc.translucency_enabled,
        capture_transmission: mc.transparency && mc.reflection_depth >= 2
            && ((sc.subsurface_scattering && sc.translucency_enabled && sc.subsurface_amount > 0.0) || sc.transmission_blur > 0.0 || sc.translucency_glow != 0.0 || can_cache_transmission(sc, p)),
    };
    let [x0, y0, w, h] = p.rect;
    let (wu, hu) = (w as usize, h as usize);
    let threads = threads.min(hu).max(1);
    let ctx = &ctx;
    let finished = std::sync::atomic::AtomicUsize::new(0);
    let finished = &finished;
    let mut transmission = if ctx.capture_transmission {
        vec![Transmission::default(); wu * hu]
    } else {
        Vec::new()
    };
    std::thread::scope(|s| {
        let mut per: Vec<Vec<_>> = (0..threads).map(|_| Vec::new()).collect();
        let samples = transmission.chunks_mut(wu).map(Some).chain(std::iter::repeat_with(|| None));
        for (y, (row, samples)) in rgb.chunks_mut(wu * 3).zip(samples).enumerate() {
            per[y % threads].push((y, row, samples));
        }
        for list in per {
            s.spawn(move || {
                for (ry, row, mut samples) in list {
                    if cancel() {
                        break;
                    }
                    let y = ry as i32 + y0;
                    let seed = (0x24563487i64 + (y as i64 + 1) * 0x324594A1i64) as i32;
                    let mut t = SrTracer {
                        c: ctx,
                        m: Marcher::new(p, seed),
                        sr_si: SiLight::default(),
                        normal: [0.0; 3],
                        transmission: Transmission::default(),
                        difs_materials: Vec::new(),
                        t_amb: [0.0; 3],
                        plv: Plv {
                            view: [0.0, 0.0, 1.0],
                            abs_view: [0.0, 0.0, 1.0],
                            cam_pos: [0.0; 3],
                            obj_pos: [0.0; 3],
                            z_pos: 0.0,
                            zpos_dyn_fog: 0.0,
                            x_pos: 0.0,
                            y_pos: 0.0,
                            dep_c: [0.0; 3],
                        },
                        light_z: lv.lights.iter().map(|l| (l.pos_z, l.pos_lp)).collect(),
                        calc_trans_r: false,
                        trans_flip_inside: p.inside_rendering,
                        scale_amb_diff_down: false,
                        rnd: seed,
                        guard: 0,
                        dbg: false,
                        stop: None,
                    };
                    let dp = debug_pixel();
                    for x in 0..wu {
                        t.dbg = dp == Some((x as i32 + x0, y));
                        if let Some(c) = t.pixel(x as i32 + x0, y, &gbuf[ry * wu + x]) {
                            row[x * 3..x * 3 + 3].copy_from_slice(&c);
                            if let Some(samples) = &mut samples {
                                samples[x] = t.transmission;
                            }
                        }
                    }
                    progress(finished.fetch_add(1, std::sync::atomic::Ordering::Relaxed) + 1, hu);
                }
            });
        }
    });
    if !transmission.is_empty() && !cancel() {
        // Keep one full frame of CPU trace data for the next interactive edit.
        // Tiled renders and frames outside the memory budget skip retention.
        let cache = sc.transmission_cache.as_ref().filter(|_| {
            can_cache_transmission(sc, p) && transmission.iter().any(|sample| sample.distance > 0.0 && (sample.opacity > 0.0 || sample.subsurface_valid))
        });
        let baseline = cache.map(|_| rgb.iter().map(|c| c.to_255().round() as u8).collect());
        if sc.transmission_blur > 0.0 || sc.translucency_glow != 0.0 || (sc.subsurface_scattering && sc.translucency_enabled && sc.subsurface_amount > 0.0) {
            blur_transmission(rgb, gbuf, &transmission, p, lv, sc.transmission_blur, sc.translucency_glow, if sc.subsurface_scattering && sc.translucency_enabled {sc.subsurface_amount}else{0.0}, threads, cancel);
        }
        if let (Some(cache), Some(rgb)) = (cache, baseline) {
            if !cancel() {
                if let Ok(mut entry) = cache.lock() {
                    *entry = Some(TransmissionCache { rgb, samples: transmission, subsurface_amount:ctx.subsurface_amount, full_thickness:ctx.translucency_thickness });
                }
            }
        }
    }
}

// A single distance primitive with vector updates disabled describes the
// same surface on every iteration. Its coincident repetitions are one medium,
// not a stack of different surfaces consuming reflection depth.
fn static_difs_instances(p:&CalcParams)->bool {
    if !p.difs || p.decomb.is_some() {return false;}
    let mut active=p.slots.iter().filter(|slot|slot.iterations>0);
    let Some(slot)=active.next() else {return false;};
    active.next().is_none() && !slot.uncounted
        && slot.formula.options().iter().any(|(name,value)|
            name.eq_ignore_ascii_case("Apply scale+add") && *value==0.0)
}

/// Continue a thickness query past an internal object to the entered medium's
/// actual exit. This affects frosting only; normal visibility still stops at
/// an opaque object. Ray parameters use the same units as the reflection march.
fn material_exit_path(p: &CalcParams, origin: Vec3, direction: Vec3, start: f64, limit: f64,
    component: i32, de_stop: f32, cancel: &(dyn Fn()->bool+Sync)) -> Option<f64> {
    let mut m=Marcher::new(p,1);
    m.ms_de_stop=de_stop;m.inside=true;m.calc_inside=true;
    m.it.difs_inside_components=Some(vec![component]);m.it.difs_only_component=Some(component);
    let mut path=start;
    for step in 0..512 {
        if step%16==0 && cancel() {return None;}
        let distance=m.de_at_point(add(origin,scale(direction,path)),false);
        if !distance.is_finite() {return None;}
        if distance<=de_stop as f64 {return Some(path);}
        path += ((distance-p.ms_de_sub as f64*de_stop as f64)*p.z_step_div as f64).max(0.11);
        if path>limit {return None;}
    }
    None
}

// Approximate the forward-biased scattering of a translucent solid.
const SUBSURFACE_ANISOTROPY:f32=0.7;
fn subsurface_phase(cosine:f32)->f32 {
    let g=SUBSURFACE_ANISOTROPY;
    0.25*(1.0-g*g)/(1.0+g*g-2.0*g*cosine.clamp(-1.0,1.0)).powf(1.5)
}

// Define optical thickness relative to the view's world-space width, like
// the existing transmission controls. A fixed world-unit coefficient makes
// the effect disappear on highly magnified fractal details. Width * step_width
// is independent of render resolution and oversampling.
fn subsurface_density(p: &CalcParams, amount: f32) -> f32 {
    let view_width = (p.step_width * p.width as f64).abs().max(1e-30);
    // Preserve the existing density at ordinary scene scales; increase it
    // for magnified details rather than weakening larger objects.
    (100.0 * (amount as f64).powi(2) * (0.1 / view_width).max(1.0)) as f32
}

/// Material distance from an interior sample toward a light. Other DIFS
/// instances occlude the light; repeated crossings of a hollow object's walls
/// accumulate only solid material, excluding the air in its cavity.
fn subsurface_light_path(p:&CalcParams,origin:Vec3,direction:Vec3,max_distance:f64,component:i32,de_stop:f32,static_difs:bool,cancel:&(dyn Fn()->bool+Sync))->Option<f32>{
    crate::diagnostics::begin_ray();
    let result=(|| {
        let mut m=Marcher::new(p,1);m.ms_de_stop=de_stop;
        // Light transport needs geometric distances more precise than the
        // primary image's pixel-sized surface threshold.
        let eps=(de_stop as f64*p.step_width).abs().min(1e-5).max(1e-9);
        m.ms_de_stop=(eps/p.step_width.abs()) as f32;
        let individual=p.difs&&p.decomb.is_none();
        if static_difs {m.it.max_it=1;}
        let components=vec![component];
        let mut inside=true;let mut travelled=0.0;let mut material=0.0;
        if individual {m.it.difs_inside_components=Some(components.clone());}
        for step in 0..256 {
            if step%16==0&&cancel(){return None;}
            crate::diagnostics::step();
            m.inside=inside;m.calc_inside=inside;
            let point=add(origin,scale(direction,travelled));
            let d=m.de_at_point(point,false)*p.step_width;
            if !d.is_finite(){return None;}
            let remaining=max_distance-travelled;
            if remaining<=eps{return Some(material as f32);}
            let advance=if d<=eps*1.2 {
                if individual&&m.it.difs_component_id!=component{return None;}
                inside=!inside;
                if individual {m.it.difs_inside_components=Some(if inside{components.clone()}else{Vec::new()});}
                (eps*4.0).min(remaining)
            }else{(d*0.7).max(eps).min(remaining)};
            if inside {material+=advance;}
            travelled+=advance;
            if travelled>=max_distance{return Some(material as f32);}
        }
        None // A bounded, unresolved light path is conservatively occluded.
    })();
    crate::diagnostics::end_ray(result.is_some());result
}

/// Normalize illumination before applying albedo, so bright light does not
/// erase the material's diffuse color. Opaque frosting uses this full lit
/// material response rather than an arbitrary quarter-brightness substitute.
fn translucency_material_light(through: S3, albedo: S3, incident: S3) -> S3 {
    let peak=incident.iter().copied().fold(1.0_f32,f32::max);
    mul3(through,mul3(albedo,sc3(incident,1.0/peak)))
}

fn frost_edge_coverage(path: f32) -> f32 {
    let edge=(path/0.05).clamp(0.0,1.0);
    edge*edge*(3.0-2.0*edge)
}

fn transmission_opacity(path: f32, strength: f32) -> f32 {
    // A single broad ramp preserves intermediate thicknesses. Strength 2
    // remains fully frosted away from the clear silhouette.
    let t = (path / 2.0).clamp(0.0, 1.0);
    let opacity = (strength * t * t * (3.0 - 2.0 * t)).min(1.0);
    let coverage = (strength - 1.0).clamp(0.0, 1.0);
    let coverage = coverage * coverage * (3.0 - 2.0 * coverage);
    opacity + coverage * frost_edge_coverage(path) * (1.0 - opacity)
}

/// Filter only the light gathered beyond the exit interface. Surface
/// highlights, absorption and internal illumination stay in the base color.
fn blur_transmission<S: Sample>(
    rgb: &mut [S], gbuf: &[SiLight], transmission: &[Transmission], p: &CalcParams,
    lv: &LightVals, amount: f32, glow_amount: f32, subsurface_amount: f32, threads: usize, cancel: &(dyn Fn() -> bool + Sync),
) {
    if amount<=0.0 && glow_amount==0.0 { return; }
    let [_, _, width, height] = p.rect;
    let (width, height) = (width as usize, height as usize);
    let rows = height.div_ceil(threads);
    let radius_limit = (p.width.min(p.height) as f32 * 0.075).clamp(1.0, 64.0);
    // The near-plane pixel scale can be orders of magnitude smaller than
    // a distant object's thickness. Measure paths on each DIFS instance so
    // a floor or another object cannot make all of its edges appear thick.
    let mut paths = std::collections::HashMap::<i32, Vec<f32>>::new();
    for sample in transmission.iter().step_by((transmission.len() / 65_536).max(1)) {
        if sample.distance.is_finite() && sample.distance > 0.0 && sample.opacity > 0.0 {
            paths.entry(sample.component).or_default().push(sample.distance);
        }
    }
    let scales: std::collections::HashMap<_, _> = paths.into_iter().map(|(id, mut paths)| {
        let index = paths.len() * 3 / 4;
        let (_, distance, _) = paths.select_nth_unstable_by(index, f32::total_cmp);
        (id, (*distance * 0.65).max(1e-20))
    }).collect();
    let scales = &scales;
    // Above the default strength, progressively frost even short paths.
    let coverage = (amount - 1.0).clamp(0.0, 1.0);
    let coverage = coverage * coverage * (3.0 - 2.0 * coverage);
    std::thread::scope(|scope| {
        for (band, output) in rgb.chunks_mut(rows * width * 3).enumerate() {
            scope.spawn(move || {
                for (row, pixels) in output.chunks_mut(width * 3).enumerate() {
                    if cancel() { return; }
                    let y = band * rows + row;
                    for (x, pixel) in pixels.chunks_exact_mut(3).enumerate() {
                        let i = y * width + x;
                        let center = transmission[i];
                        if center.distance <= 0.0 || (center.opacity <= 0.0 && !center.subsurface_valid) { continue; }
                        let path_scale = scales.get(&center.component).copied().unwrap_or(1.0);
                        let path = center.distance / path_scale;
                        // Keep short paths clear and let the blur rise quickly
                        // as the ray travels farther inside the material.
                        let thickness = path / (1.0 + path);
                        let response = thickness * thickness * (3.0 - 2.0 * thickness);
                        // Use the whole thickness range, rather than stacking
                        // narrow thresholds into a steep transparency boundary.
                        let edge_weight = response;
                        let edge_coverage = coverage * frost_edge_coverage(path);
                        let edge_weight = edge_weight + edge_coverage * (1.0 - edge_weight);
                        if edge_weight == 0.0 && glow_amount == 0.0 && subsurface_amount <= 0.0 { continue; }
                        let radius = amount * radius_limit * (response + edge_coverage * (1.0 - response));
                        if radius <= 0.5 && glow_amount == 0.0 && subsurface_amount <= 0.0 { continue; }
                        let sample_radius = if radius > 0.5 { radius } else { 3.0 };

                        let mut light = center.light;
                        let mut interior_light = center.interior_light;
                        let mut material_light = center.material_light;
                        let mut weights = 1.0;
                        for tap in 0..32 {
                            let index = tap as f32 + 0.5;
                            let r = sample_radius * (index / 32.0).sqrt();
                            let (sin, cos) = (index * 2.399_963_1).sin_cos();
                            let nx = x as isize + (r * cos).round() as isize;
                            let ny = y as isize + (r * sin).round() as isize;
                            if nx < 0 || ny < 0 || nx >= width as isize || ny >= height as isize { continue; }
                            let j = ny as usize * width + nx as usize;
                            let other = transmission[j];
                            if other.distance <= 0.0 || (other.opacity - center.opacity).abs() > 0.1 { continue; }
                            let depth = gbuf[i].zpos().abs_diff(gbuf[j].zpos()) as f32;
                            let delta = (other.distance - center.distance).abs() / center.distance.max(other.distance);
                            let weight = (1.0 - 0.8 * index / 32.0)
                                / (1.0 + (depth / 100.0).powi(2) + 16.0 * delta.powi(2));
                            light = add3(light, sc3(other.light, weight));
                            interior_light = add3(interior_light, sc3(other.interior_light, weight));
                            material_light = add3(material_light, sc3(other.material_light, weight));
                            weights += weight;

                        }
                        let mix = ((response - 0.12) / 0.43).clamp(0.0, 1.0)
                            * (radius - 0.5).clamp(0.0, 1.0) * edge_weight;
                        let blurred = lin2(sc3(light, 1.0 / weights), center.light, mix);
                        // At maximum blur, long paths contribute diffuse
                        // interior light without transmitting the background.
                        // Use the same scene-relative thickness as the blur so
                        // smaller objects can also develop an opaque interior.
                        let opacity = transmission_opacity(path, amount);
                        let lit_material = sc3(interior_light, 1.0 / weights);
                        let frosted_material = sc3(material_light,1.0/weights);
                        // Replace extinguished background light with diffuse
                        // light scattered inside the material.
                        let transmitted = if opacity > 0.0 {
                            add3(sc3(blurred, 1.0 - opacity), sc3(frosted_material, opacity))
                        } else { blurred };
                        let glow = if glow_amount < 0.0 {
                            // Grazing entry rays form a rim. Extinction along
                            // the path softens the glow toward the interior.
                            let facing = center.entry_facing;
                            let grazing = (1.0 - facing).powi(2);
                            let falloff = (-1.5 * path).exp();
                            let rim = ((0.5 + 2.5 * grazing) * falloff).min(1.0);
                            let rim_color = lit_material.map(|channel| channel.max(0.0).sqrt());
                            sc3(rim_color, 1.2 * -glow_amount * rim)
                        } else {
                            // Let interior glow build over a broader range of path
                            // lengths than the filter that protects clear edges.
                            let interior = ((response - 0.18) / 0.62).clamp(0.0, 1.0);
                            let glow_weight = interior * interior * (3.0 - 2.0 * interior);
                            sc3(lit_material, 0.65 * glow_amount * glow_weight)
                        };
                        let ordinary = add3(center.base, transmitted);
                        let color = if subsurface_amount > 0.0 && center.subsurface_valid {
                            // The ordinary transmission already includes material opacity,
                            // refraction, surface frosting and diffuse boundary lighting.
                            // Extinguish that transmitted light and add the integrated
                            // volume radiance; do not replace it with an unfiltered
                            // background ray or discard the surface contribution.
                            // Fog lies between the camera and the material. It must
                            // not be extinguished as internal diffuse illumination.
                            let surface_diffuse = sub3(sub3(center.entry_light, center.entry_specular),center.entry_fog).map(|v| v.max(0.0));
                            let surface = add3(sub3(center.base, surface_diffuse),
                                mul3(surface_diffuse, center.subsurface_through));
                            // Frosted material is already a lit opaque response,
                            // not background radiance crossing the whole volume.
                            // Only the remaining clear transmission is ballistic.
                            let physical_transmission = add3(
                                mul3(sc3(blurred,1.0-opacity),center.subsurface_through),
                                sc3(frosted_material,opacity));
                            let physical = add3(surface,
                                add3(mul3(center.subsurface_light,center.entry_visibility), physical_transmission));
                            // Strength is the material mixture, including scattering.
                            // Do not retain full volume extinction as the frosted
                            // fraction approaches clear, ordinary transmission.
                            lin2(physical, ordinary, subsurface_amount * center.opacity.clamp(0.0,1.0) * opacity)
                        } else { ordinary };
                        pixel.copy_from_slice(&reflection_colour(lv, add3(color, glow)));
                    }
                }
            });
        }
    });
}

/// Fewer rays than this in a round of the reflection pass are marched on
/// the CPU.
#[cfg(feature = "gpu")]
const CPU_RAYS: usize = 2000;

/// The CPU's part of the rays at which the rest of the reflection rounds
/// run on the CPU alone (see `reflections_gpu`).
#[cfg(feature = "gpu")]
const CPU_FINISH: f64 = 0.6;

/// The per pixel state of the reflection pass on the graphics card: the
/// tracer fields `calc_ray` keeps between its rays and its frames.
#[cfg(feature = "gpu")]
#[derive(Clone)]
struct RPix {
    /// the G-buffer value of the pixel
    si0: SiLight,
    t_amb: S3,
    pos: Vec3,
    normal: Vec3,
    inside: bool,
    plv: Plv,
    calc_trans_r: bool,
    scale_amb_diff_down: bool,
    guard: u32,
    stack: Vec<Frame>,
    /// the march of the ray the last step asked for
    hit: Option<RayHit>,
}

/// `reflections` with the rays on the graphics card: every bounce of all
/// pixels is one batch (`gpu::reflect_batch`), which marches the rays and
/// calculates the normals, colours, shadows and ambient occlusion of the
/// hits; the shading and the blending of the rays stay here
/// (`SrTracer::step`, the same code as on the CPU).  With transparency a
/// surface sends a refracted and a reflected ray: every round marches the
/// next ray of each pixel.
#[cfg(feature = "gpu")]
#[allow(clippy::too_many_arguments)]
fn reflections_gpu<S: Sample>(sc: &Scene, p: &CalcParams, gbuf: &[SiLight], rgb: &mut [S], cam: &PaintCamera, lv: &LightVals, threads: usize, cancel: &(dyn Fn() -> bool + Sync)) -> Result<(), String> {
    use crate::gpu::{ReflectLight, ReflectOpts, ReflectTask};
    let mc = &sc.mc;
    let mid = sc.stereo_mid();
    let m1 = normalise_matrix_to(1.0, &p.vgrads);
    let sw = p.step_width;
    let hs_vecs: Vec<Vec3> = lv
        .lights
        .iter()
        .map(|l| if l.positional { add(s3d(l.ln), mid) } else { rotate_vector_reverse(&norm_to(-p.step_width, s3d(l.ln)), &m1) })
        .collect();
    let hs = sc.shadows.map(|h| {
        let lights: Vec<(usize, usize)> = lv.lights.iter().enumerate().filter(|(_, l)| (h.lights >> l.idx) & 1 != 0).map(|(i, l)| (i, l.idx)).collect();
        (lights, h.soft, h.soft_radius.max(0.001), h.max_len_mul)
    });
    let ao = sc.ao.as_ref().map(|_| {
        let d = sc.deao.unwrap_or_default();
        (d.max_len, d.first_step_random)
    });
    let ctx = SrCtx {
        cancel,
        p,
        lv,
        cam,
        mid,
        hs_vecs: hs_vecs.clone(),
        max_reflections: mc.reflection_depth as i32,
        sr_light_amount: mc.reflection_amount.clamp(0.0, 100.0),
        trans_di_const: mc.refraction_index,
        calc_trans: mc.transparency,
        only_difs: mc.only_difs,
        absorption: (mc.absorption as f64 * p.step_width) as f32,
        absorp_coeff: mc.absorption,
        light_scattering: mc.scattering.max(0.0),
        back_dist: (((8388352.0 / p.zc_mul + 1.0).powi(2) - 1.0) * p.step_width / p.zcorr) as f32,
        hs: hs.clone(),
        ao,
        vol: p.vol.is_some(),
        gpu: true,
        capture_transmission: false,
        translucency_thickness: false,
        subsurface_amount: 0.0,
        static_difs: static_difs_instances(p),
    };
    // the lights of the shadow rays (calc_hs): soft shadows use the last one
    let mut lights: Vec<ReflectLight> = Vec::new();
    let (mut soft_radius, mut hs_mul) = (0.0f32, 1.0f32);
    if let Some((ls, soft, radius, mul)) = &hs {
        hs_mul = *mul;
        let sel: Vec<&(usize, usize)> = if *soft { ls.last().into_iter().collect() } else { ls.iter().collect() };
        if *soft && !sel.is_empty() {
            soft_radius = *radius;
        }
        for &(li, idx) in sel {
            let l = &lv.lights[li];
            lights.push(ReflectLight { idx: idx as u32, vec: s3(&hs_vecs[li]), positional: l.positional, lmax_l: l.lmax_l, visible: l.visible as u32 });
        }
    }
    let far_fog = lv.far_fog || lv.sqr;
    let [x0, y0, w, h] = p.rect;
    let (wu, hu) = (w as usize, h as usize);
    let n = wu * hu;
    let threads = threads.clamp(1, hu);
    // a tracer per thread for the shading (its marcher is not used)
    let new_tracer = |seed: i32| SrTracer {
        c: &ctx,
        m: Marcher::new(p, seed),
        sr_si: SiLight::default(),
        normal: [0.0; 3],
        transmission: Transmission::default(),
        difs_materials: Vec::new(),
        t_amb: [0.0; 3],
        plv: Plv { view: [0.0, 0.0, 1.0], abs_view: [0.0, 0.0, 1.0], cam_pos: [0.0; 3], obj_pos: [0.0; 3], z_pos: 0.0, zpos_dyn_fog: 0.0, x_pos: 0.0, y_pos: 0.0, dep_c: [0.0; 3] },
        light_z: lv.lights.iter().map(|l| (l.pos_z, l.pos_lp)).collect(),
        calc_trans_r: false,
        trans_flip_inside: p.inside_rendering,
        scale_amb_diff_down: false,
        rnd: seed,
        guard: 0,
        dbg: false,
        stop: None,
    };
    let dbg_i = debug_pixel().map(|(x, y)| ((y - y0) * w + (x - x0)) as usize);
    // the surfaces of the object pixels
    let mut px: Vec<Option<RPix>> = vec![None; n];
    let mut tasks: Vec<ReflectTask> = Vec::new();
    // inside rendering: the rays of a pixel run inside the set (in and
    // outside: unless the pixel was found from outside, as `pixel` does)
    let inside_of = |si: &SiLight| if p.in_and_outside && si.otrap & 0x8000 != 0 { false } else { p.inside_rendering };
    for (i, si) in gbuf.iter().enumerate() {
        if si.zpos() < 32768 && si.si_gradient < 32768 {
            tasks.push(ReflectTask { zz: (si.zpos_fine >> 8) as f32, pixel: i as u32, inside: inside_of(si), ..Default::default() });
        }
    }
    let timing = std::env::var_os("MB3D_GPU_TIMING").is_some();
    let t0 = std::time::Instant::now();
    let (hits, _, _) = crate::gpu::reflect_batch_cancellable(p, &tasks, &ReflectOpts { surface: true, hs_mul, ..Default::default() }, None, cancel)?;
    if timing {
        eprintln!("  reflections: {} surfaces in {:.2} s", tasks.len(), t0.elapsed().as_secs_f64());
    }
    let chunk = |n: usize| n.div_ceil(threads).max(1);
    let pairs: Vec<(usize, crate::gpu::ReflectHit)> = tasks.iter().zip(&hits).map(|(t, h)| (t.pixel as usize, *h)).collect();
    // Release the large input/output lists before building per-pixel state.
    drop((tasks, hits));
    std::thread::scope(|s| {
        let mut rest: &mut [Option<RPix>] = &mut px;
        let mut start = 0usize;
        // the pixels in index order: split the state by pixel ranges
        let per = chunk(n);
        while start < n {
            let (part, r) = rest.split_at_mut(per.min(rest.len()));
            rest = r;
            let lo = start;
            let hi = start + part.len();
            let mine: Vec<(usize, crate::gpu::ReflectHit)> = pairs.iter().filter(|(i, _)| *i >= lo && *i < hi).copied().collect();
            s.spawn(move || {
                let mut t = new_tracer(1);
                for (i, hit) in mine {
                    if hit.skip {
                        continue;
                    }
                    let si = gbuf[i];
                    let (x, y) = (x0 + (i % wu) as i32, y0 + (i / wu) as i32);
                    let (start, vfov) = crate::calc::pixel_ray(p, x, y);
                    t.plv.cam_pos = s3(&sub(start, mid));
                    let av = s3(&normalize(vfov));
                    t.plv.abs_view = av;
                    t.plv.view = cam.to_view(av);
                    t.plv.y_pos = y as f32 / p.height as f32;
                    t.plv.x_pos = (x + 1) as f32 / p.width as f32;
                    let ys = t.plv.y_pos;
                    let sd = match lv.depth_func {
                        1 => ys * ys,
                        0 => ys,
                        _ => ys.max(0.0).sqrt(),
                    };
                    t.plv.dep_c = lin2(lv.depth_col2, lv.depth_col, sd);
                    t.calc_light_z_pos();
                    let pos = hit.pos;
                    let zz = hit.zz as f64;
                    t.plv.z_pos = (zz * sw + p.zz_stmit_dif) as f32;
                    t.plv.obj_pos = s3(&sub(pos, mid));
                    t.plv.zpos_dyn_fog = t.plv.z_pos;
                    let calc_trans_r = ctx.calc_trans && (!ctx.only_difs || p.decomb.as_ref().map_or(p.difs, |d| d.part2.difs));
                    t.scale_amb_diff_down = calc_trans_r;
                    t.sr_si = si;
                    let sh = t.shade(&si, None, None);
                    if dbg_i == Some(i) {
                        eprintln!("GPU surface: pos {pos:?} zz {zz:.4} si {si:?}\n  plv {:?}\n  light {:?} result {:?} spe {:?} {} dif {:?}", t.plv, sh.light, sh.result, sh.spe, sh.spe_a, sh.dif);
                    }
                    let sd = (sh.spe, sh.spe_a, sh.dif);
                    part[i - lo] = Some(RPix {
                        si0: si,
                        t_amb: sh.light.map(|v| (v / 255.0).clamp(0.0, 8.0)),
                        pos,
                        normal: normal_of(&si),
                        inside: inside_of(&si),
                        plv: t.plv,
                        calc_trans_r,
                        scale_amb_diff_down: calc_trans_r,
                        guard: 0,
                        stack: vec![Frame::new(zz, vfov, sc3(sh.result, ctx.sr_light_amount), sd, 1)],
                        hit: None,
                    });
                }
                // pixels on a cutting plane: no surface to refine, set up here
                // (their rays only see the open air)
                if p.cut_options != 0 {
                    for i in lo..hi {
                        let si = gbuf[i];
                        if si.zpos() >= 32768 || si.si_gradient < 32768 {
                            continue;
                        }
                        let (x, y) = (x0 + (i % wu) as i32, y0 + (i / wu) as i32);
                        t.dbg = dbg_i == Some(i);
                        let Some((mzz, vf, sv, sd)) = t.start_pixel(x, y, &si) else { continue };
                        part[i - lo] = Some(RPix {
                            si0: si,
                            t_amb: t.t_amb,
                            pos: t.m.it.c,
                            normal: t.normal,
                            inside: t.m.inside,
                            plv: t.plv,
                            calc_trans_r: t.calc_trans_r,
                            scale_amb_diff_down: t.scale_amb_diff_down,
                            guard: 0,
                            stack: vec![Frame::new(mzz, vf, sv, sd, 1)],
                            hit: None,
                        });
                    }
                }
            });
            start = hi;
        }
    });
    drop(pairs);
    // the rays: every round runs each pixel to its next ray, the rays are
    // marched in a batch per bounce (the AO quality depends on it)
    let rit_q = |rit: i32| match rit {
        1 => 2u8,
        2 => 1,
        _ => 0,
    };
    // marches rays on the card
    let march_gpu = |list: &[&(usize, RayReq)], share: Option<&crate::gpu::RaySharing>| -> Result<(Vec<RayHit>, usize, Vec<usize>), String> {
        let tasks: Vec<ReflectTask> = list
            .iter()
            .map(|(i, r)| ReflectTask { origin: r.origin, dir: s3(&r.dir), zz: r.zz as f32, pixel: *i as u32, inside: r.inside, ao_q: rit_q(r.rit) })
            .collect();
        let opts = ReflectOpts { surface: false, lights: lights.clone(), soft_radius, hs_mul, ao: ao.map(|(m, f)| (0, m, f)), far_fog };
        let (hits, n_card, unfinished) = crate::gpu::reflect_batch_cancellable(p, &tasks, &opts, share, cancel)?;
        let hits = list
            .iter()
            .zip(hits)
            .map(|((_, req), h)| {
                if h.hit {
                    let mut si = h.si;
                    if ao.is_some() {
                        si.amb_shadow = ((si.amb_shadow as i32 * 8) / (8 + req.rit)) as u16;
                    } else {
                        si.amb_shadow = 5000;
                    }
                    RayHit { hit: true, si, pos: h.pos, zz: h.zz as f64, zz2_paint: h.zz2 as f64, zz2: h.zz2 as f64, component:0 }
                } else {
                    // the step count of the ray (dynamic fog) as calc_ray keeps it
                    let shadow = if p.vol.is_some() { crate::lighting::encode_vlight(h.step_count) } else { h.step_count.clamp(0.0, 1023.0).round_ties_even() as u16 };
                    let si = SiLight { zpos_fine: 32768 << 16, shadow, ..SiLight::default() };
                    RayHit { hit: false, si, pos: [0.0; 3], zz: h.zz as f64, zz2_paint: h.zz2 as f64, zz2: h.zz2 as f64, component:0 }
                }
            })
            .collect();
        Ok((hits, n_card, unfinished))
    };
    // marches rays here: all of `list`, or with `share` the ones the card
    // leaves (taken from the end in pieces): (index in `list`, result)
    // the threads' time on rays (not waiting for the card)
    let busy = std::sync::atomic::AtomicU64::new(0);
    let busy_ns = &busy;
    let march_cpu = |list: &[&(usize, RayReq)], share: Option<&crate::gpu::RaySharing>| -> Vec<(usize, RayHit)> {
        use std::sync::atomic::Ordering::SeqCst;
        const PIECE: usize = 16;
        let own = crate::gpu::RaySharing { state: std::sync::Mutex::new((0, list.len())), done: std::sync::Arc::new(true.into()), tail: 0, cap: usize::MAX };
        let sh = share.unwrap_or(&own);
        // one thread feeds the card
        let workers = if share.is_some() { threads.saturating_sub(1).max(1) } else { threads };
        std::thread::scope(|s| {
            let hs: Vec<_> = (0..workers)
                .map(|_| {
                    s.spawn(move || {
                        let mut t = new_tracer(1);
                        // with the card: rays still running when it is done
                        // are given up (single rays can take long here)
                        t.stop = share.map(|sh| sh.done.clone());
                        let mut out = Vec::new();
                        loop {
                            let (lo, cur) = {
                                let mut st = sh.state.lock().unwrap();
                                let (lim, cur) = *st;
                                if cur > lim {
                                    st.1 = cur.saturating_sub(PIECE).max(lim);
                                    (st.1, cur)
                                } else {
                                    (cur, cur)
                                }
                            };
                            if lo == cur {
                                if sh.done.load(SeqCst) {
                                    break;
                                }
                                // the card has the rest for now
                                std::thread::sleep(std::time::Duration::from_micros(500));
                                continue;
                            }
                            let tb = std::time::Instant::now();
                            for (k, (i, r)) in list.iter().enumerate().take(cur).skip(lo) {
                                t.pixel_marcher(x0 + (i % wu) as i32, y0 + (i / wu) as i32);
                                t.sr_si = gbuf[*i];
                                t.m.inside = r.inside;
                                t.m.calc_inside = r.inside;
                                if let Some(h) = t.march_until(r) {
                                    out.push((k, h));
                                }
                            }
                            busy_ns.fetch_add(tb.elapsed().as_nanos() as u64, std::sync::atomic::Ordering::Relaxed);
                        }
                        out
                    })
                })
                .collect();
            hs.into_iter().flat_map(|h| h.join().unwrap()).collect()
        })
    };
    let mut round = 0;
    // MB3D_REFLECT_CPU_SHARE=0: all rays on the card (comparisons)
    let card_only = std::env::var("MB3D_REFLECT_CPU_SHARE").is_ok_and(|v| v == "0");
    let mut t_steps = 0.0;
    // the CPU's part of a round, from the rates of the last one (the card
    // claims its rays as fast as it marches them, but then casts their
    // shadow and occlusion rays alone: without a cap the threads wait)
    // Kept per odd and even round: the rounds alternate in what they cost
    // the two (Luna's vase: the CPU's part came out 68 % and 45 % in turn).
    let mut cpu_part: [Option<f64>; 2] = [None; 2];
    // once the CPU's part of both kinds of round is this big, the card only
    // adds the cost of its rounds (many small ones with transparency): the
    // rest of the rounds run here, as small rounds always do
    let cpu_finish: f64 = std::env::var("MB3D_REFLECT_CPU_FINISH").ok().and_then(|v| v.parse().ok()).unwrap_or(CPU_FINISH);
    let mut cpu_rest = false;
    loop {
        // ("Stop": rgb is written only at the end, so it stays unchanged)
        if cancel() {
            return Err("cancelled".into());
        }
        let ts = std::time::Instant::now();
        let reqs: Vec<(usize, RayReq)> = std::thread::scope(|s| {
            let mut handles = Vec::new();
            let mut rest: &mut [Option<RPix>] = &mut px;
            let mut start = 0usize;
            let per = chunk(n);
            while start < n {
                let (part, r) = rest.split_at_mut(per.min(rest.len()));
                rest = r;
                let lo = start;
                start += part.len();
                handles.push(s.spawn(move || {
                    let mut t = new_tracer(1);
                    let mut out = Vec::new();
                    for (k, q) in part.iter_mut().enumerate() {
                        let Some(q) = q.as_mut().filter(|q| !q.stack.is_empty()) else { continue };
                        let i = lo + k;
                        t.plv = q.plv;
                        t.t_amb = q.t_amb;
                        t.m.it.c = q.pos;
                        t.normal = q.normal;
                        t.m.inside = q.inside;
                        t.m.calc_inside = q.inside;
                        t.sr_si = q.si0;
                        t.calc_trans_r = q.calc_trans_r;
                        t.scale_amb_diff_down = q.scale_amb_diff_down;
                        t.guard = q.guard;
                        t.dbg = dbg_i == Some(i);
                        // the rays of a pixel on a cutting plane end in the open
                        // air (`march` does not step): no need for the card
                        let on_cut = q.si0.si_gradient > 32767;
                        if on_cut {
                            t.pixel_marcher(x0 + (i % wu) as i32, y0 + (i / wu) as i32);
                        }
                        let mut hit = q.hit.take();
                        while let Some(r) = t.step(&mut q.stack, hit) {
                            if on_cut {
                                hit = Some(t.march(&r));
                                continue;
                            }
                            out.push((i, r));
                            break;
                        }
                        q.plv = t.plv;
                        q.t_amb = t.t_amb;
                        q.pos = t.m.it.c;
                        q.normal = t.normal;
                        q.inside = t.m.inside;
                        q.calc_trans_r = t.calc_trans_r;
                        q.scale_amb_diff_down = t.scale_amb_diff_down;
                        q.guard = t.guard;
                    }
                    out
                }));
            }
            handles.into_iter().flat_map(|h| h.join().unwrap()).collect()
        });
        t_steps += ts.elapsed().as_secs_f64();
        if reqs.is_empty() {
            break;
        }
        round += 1;
        // the rays of the round: on the card in one batch (the tasks carry
        // the AO quality of their bounce) while the threads here take a
        // share of them in small pieces, until the card is done; what they
        // did not get to goes after (all on the CPU for a few rays: the card
        // would wait for the slowest of them)
        let all: Vec<&(usize, RayReq)> = reqs.iter().collect();
        let t0 = std::time::Instant::now();
        let mut res: Vec<Option<RayHit>> = vec![None; all.len()];
        let mut n_gpu = 0usize;
        if (all.len() < CPU_RAYS || cpu_rest) && !card_only {
            for (k, h) in march_cpu(&all, None) {
                res[k] = Some(h);
            }
        } else if card_only {
            let (hits, _, _) = march_gpu(&all, None)?;
            n_gpu = all.len();
            for (k, h) in hits.into_iter().enumerate() {
                res[k] = Some(h);
            }
        } else {
            // the CPU starts with a few pieces per thread from the end
            let n = all.len();
            let cap = cpu_part[round % 2].or(cpu_part[(round + 1) % 2]).map_or(usize::MAX, |c| n - (n as f64 * c) as usize);
            let sh = crate::gpu::RaySharing { state: std::sync::Mutex::new((0, n)), done: std::sync::Arc::new(false.into()), tail: threads * 2, cap };
            busy_ns.store(0, std::sync::atomic::Ordering::Relaxed);
            let ((gpu, t_card), cpu) = std::thread::scope(|s| {
                let g = s.spawn(|| {
                    let t = std::time::Instant::now();
                    (march_gpu(&all, Some(&sh)), t.elapsed().as_secs_f64())
                });
                let c = march_cpu(&all, Some(&sh));
                (g.join().unwrap(), c)
            });
            // (the threads' busy time over their number: the time all of
            // them took)
            let t_cpu = busy_ns.load(std::sync::atomic::Ordering::Relaxed) as f64 * 1e-9 / threads.saturating_sub(1).max(1) as f64;
            let (hits, n_card, unfinished) = gpu?;
            n_gpu = n_card - unfinished.len();
            // rays per second of both sides (each in its own time)
            if n_gpu > 0 && !cpu.is_empty() {
                let card = n_gpu as f64 / t_card.max(1e-4);
                let c = cpu.len() as f64 / t_cpu.max(1e-4);
                cpu_part[round % 2] = Some((c / (c + card)).clamp(0.02, 0.85));
            }
            for (k, h) in hits.into_iter().enumerate().take(n_card) {
                res[k] = Some(h);
            }
            for (k, h) in cpu {
                res[k] = Some(h);
            }
            // the rays the card left: here
            let list: Vec<&(usize, RayReq)> = unfinished.iter().map(|&k| all[k]).collect();
            for (j, h) in march_cpu(&list, None) {
                res[unfinished[j]] = Some(h);
            }
            // the rays given up here: on the card
            let rest: Vec<usize> = (0..all.len()).filter(|&k| res[k].is_none()).collect();
            if !rest.is_empty() {
                let list: Vec<&(usize, RayReq)> = rest.iter().map(|&k| all[k]).collect();
                let (hits, _, _) = march_gpu(&list, None)?;
                for (j, h) in hits.into_iter().enumerate() {
                    res[rest[j]] = Some(h);
                }
            }
        }
        if cpu_part.iter().all(|c| c.is_some_and(|c| c >= cpu_finish)) {
            cpu_rest = true;
        }
        let n_cpu_done = all.len() - n_gpu;
        if timing {
            eprintln!(
                "  reflections: round {round}: {} rays, {n_gpu} on the card, {n_cpu_done} on the CPU, in {:.2} s (CPU's part {:.0} %)",
                all.len(),
                t0.elapsed().as_secs_f64(),
                cpu_part[round % 2].unwrap_or(0.0) * 100.0
            );
        }
        for ((i, _), h) in all.iter().zip(res) {
            if let (Some(q), Some(h)) = (px[*i].as_mut(), h) {
                q.hit = Some(h);
            }
        }
    }
    if timing {
        eprintln!("  reflections: {round} rounds, shading {t_steps:.2} s");
    }
    // the colours
    for (i, q) in px.iter().enumerate() {
        let Some(q) = q else { continue };
        let mut t = q.t_amb.map(|v| v.clamp(0.0, 1.0));
        if lv.sqr {
            t = t.map(|v| v.sqrt());
        }
        if lv.gamma_h != 0 {
            let g = if lv.gamma_h > 0 { t.map(|v| v.sqrt()) } else { t.map(|v| v * v) };
            t = add3(t, sc3(sub3(g, t), lv.s_gamma));
        }
        let c = t.map(S::from_unit);
        rgb[i * 3..i * 3 + 3].copy_from_slice(&c);
    }
    Ok(())
}



#[cfg(test)]
mod band_memory_tests {
    use super::*;
    #[test]
    fn band_from_free_memory() {
        assert_eq!(band_pixels(None), 1 << 21);
        assert_eq!(band_pixels(Some(0)), 1 << 18);
        assert_eq!(band_pixels(Some(u64::MAX)), 1 << 21);
        let free = 2 * REFLECT_BAND_BYTES * (1 << 20);
        assert_eq!(band_pixels(Some(free)), 1 << 20);
    }
}

#[cfg(test)]
mod transmission_opacity_tests {
    use super::transmission_opacity;
    #[test]
    fn lit_frosting_retains_white_gray_and_colored_materials() {
        use super::translucency_material_light;
        for albedo in [[1.;3],[0.5;3],[1.,0.2,0.1]] {
            assert_eq!(translucency_material_light([1.;3],albedo,[4.;3]),albedo);
        }
        assert_eq!(translucency_material_light([1.;3],[1.;3],[0.;3]),[0.;3]);
        assert_eq!(translucency_material_light([1.;3],[1.;3],[0.2;3]),[0.2;3]);
    }

    #[test]
    fn zero_thickness_is_clear_at_every_strength() {
        for strength in [0.,0.5,1.,1.0861,1.5,2.] {
            assert_eq!(transmission_opacity(0.,strength),0.);
            assert!(transmission_opacity(0.00001,strength)<0.001);
            let edge:Vec<_>=(0..=100).map(|i|transmission_opacity(i as f32*0.0005,strength)).collect();
            assert!(edge.windows(2).all(|v|v[1]>=v[0] && v[1]-v[0]<0.05));
        }
    }

    #[test]
    fn opacity_has_a_broad_ramp_and_an_opaque_maximum() {
        let values: Vec<_> = (1..=20).map(|i| transmission_opacity(i as f32 / 10.0, 1.2473)).collect();
        assert!(values.windows(2).all(|p| p[1] >= p[0] && p[1] - p[0] < 0.09));
        assert!(values[5] > 0.1 && values[5] < values[10] && values[10] < values[15]);
        for path in [0.1, 0.5, 1.0, 3.0] {
            assert_eq!(transmission_opacity(path, 2.0), 1.0);
            assert_eq!(transmission_opacity(path, 0.0), 0.0);
        }
    }
}

#[cfg(test)]
mod subsurface_transport_tests {
    use super::*;
    #[test]
    fn light_ray_measures_the_material_in_an_analytic_sphere() {
        crate::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
        let mut sc=Scene::preset("SphereIFS").unwrap();sc.iterations=1;sc.width=128;sc.height=128;
        let text=sc.to_text().lines().map(|line|if line.to_ascii_lowercase().starts_with("apply scale+add") {"apply scale+add = 0".to_string()}else{line.to_string()}).collect::<Vec<_>>().join("\n");
        let sc=Scene::parse(&text).unwrap();
        let p=CalcParams::new(&sc).unwrap();
        let origin=[-1.5,0.,0.]; // default SphereIFS: scale 2 and X add 3
        let radius=-crate::calc::de_at(&p,origin).0;
        let path=subsurface_light_path(&p,origin,[0.,0.,1.],radius*3.,1,p.de_stop,static_difs_instances(&p),&||false).unwrap();
        assert!((path as f64-radius).abs()<radius*0.02,"material path {path}, analytic radius {radius}");
        let mut shell=sc.clone();shell.iterations=60;
        shell.formulas[0].formula.set_option("Inside radius",0.8).unwrap();
        let p=CalcParams::new(&shell).unwrap();
        let path=subsurface_light_path(&p,[-1.5,0.,0.45],[0.,0.,-1.],2.,1,p.de_stop,static_difs_instances(&p),&||false).unwrap();
        assert!((path-0.15).abs()<0.002,"hollow sphere counted air as material: {path}");
    }
    #[test]
    fn repeated_static_difs_instances_share_the_entered_medium() {
        crate::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
        for count in [1,2] {
            let sc=Scene::parse(&format!("width=128\nheight=128\niterations=60\n[formula]\nname=SphereIFS\niterations={count}\nRadius=1\nScale=1\nX add=0\nApply scale+add=0\n[formula]\nname=SphereIFS\niterations=1\nRadius=0.25\nScale=1\nX add=0\nZ add=-3\nApply scale+add=0")).unwrap();
            let p=CalcParams::new(&sc).unwrap();
            let mut m=Marcher::new(&p,1);m.it.c=[0.;3];m.inside=true;m.calc_inside=true;
            m.it.difs_inside_components=Some(vec![1]);
            let distance=m.calc_de()*p.step_width;
            assert!(distance>0.9 && distance<1.1,"coincident repeat was treated as another boundary: {distance}, count={count}");
            m.it.c=[0.,0.,3.];
            assert!(m.calc_de()*p.step_width < -0.2,"a distinct opaque primitive was merged into the entered medium");
            m.it.difs_inside_components=Some(vec![count+1]);
            let exit=m.calc_de()*p.step_width;
            assert!(exit>0.2 && exit<0.3,"the second primitive's repetitions did not share its medium: {exit}");
            m.it.c=[0.;3];m.it.difs_inside_components=Some(vec![1]);m.it.difs_ignored_components=vec![1];
            let unoccluded=m.calc_de()*p.step_width;
            assert!((unoccluded-2.75).abs()<0.02,"clear enclosing copies still occlude AO: {unoccluded}");
            m.it.c=[0.,0.,3.];
            assert!(m.calc_de()*p.step_width < -0.2,"ignoring a clear enclosure also hid an opaque object");
        }
    }

    #[test]
    fn coincident_heightmap_primitives_share_a_medium_without_an_apply_option() {
        crate::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
        let sc=Scene::parse("width=128\nheight=128\niterations=60\n[formula]\nname=TorusHMVoid\niterations=1\nMap height=0\nRadius=0.8\nRadius2=0.3\nScale=1\n[formula]\nname=SphereIFS\niterations=1\nRadius=0.25\nScale=1\nX add=0\nZ add=-3\nApply scale+add=0").unwrap();
        let p=CalcParams::new(&sc).unwrap();let mut m=Marcher::new(&p,1);
        m.it.c=[0.5,0.,0.];m.inside=true;m.calc_inside=true;m.it.difs_inside_components=Some(vec![1]);
        let distance=m.calc_de()*p.step_width;
        assert!(distance>0.04 && distance<0.15,"coincident torus repetitions form a false boundary: {distance}");
    }

    #[test]
    fn another_object_occludes_the_subsurface_light_ray() {
        crate::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
        let sc=Scene::parse("width=128\nheight=128\niterations=2\n[formula]\nname=SphereIFS\niterations=1\nRadius=1\nScale=1\nX add=0\nApply scale+add=0\n[formula]\nname=SphereIFS\niterations=1\nRadius=0.2\nScale=1\nX add=0\nZ add=-2\nApply scale+add=0").unwrap();
        let p=CalcParams::new(&sc).unwrap();
        assert!(subsurface_light_path(&p,[0.,0.,0.],[0.,0.,1.],3.,1,p.de_stop,false,&||false).is_none());
    }
    #[test]
    fn teapot_thin_spout_paths_transmit_more_than_the_body() {
        crate::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
        let mut sc=Scene::parse(include_str!("../tests/fixtures/transmission-teapot.m3s")).unwrap();
        sc.width=240;sc.height=180;sc.threads=4;sc.mc.reflections=true;
        sc.translucency_enabled=true;sc.transmission_blur=1.0048;sc.subsurface_scattering=true;sc.subsurface_amount=0.7;
        sc.transmission_cache=Some(Default::default());
        let(p,mut g)=crate::render::calculate(&sc,&|_,_|{}).unwrap();crate::render::post_process(&sc,&p,&mut g,4);
        let _=crate::render::paint(&sc,&p,&g);
        let cache=sc.transmission_cache.as_ref().unwrap().lock().unwrap();let cache=cache.as_ref().unwrap();
        let values=|xr:std::ops::Range<usize>,yr:std::ops::Range<usize>| {
            let mut values=Vec::new();for y in yr {for x in xr.clone(){let v=cache.samples[y*240+x];if v.subsurface_valid {values.push(v.subsurface_through[1]);}}}values.sort_by(f32::total_cmp);values
        };
        let spout=values(37..76,76..111);let body=values(106..160,103..143);
        assert!(!spout.is_empty()&&!body.is_empty());
        let thin=spout[spout.len()*9/10];let thick=body[body.len()/2];
        eprintln!("spout clear-path T={thin}, body median T={thick}");
        assert!(thin>0.2 && thin>thick*3.,"thin spout is not transmitting: {thin} versus body {thick}");
    }

    #[test]
    fn subsurface_density_tracks_scene_scale_not_render_resolution() {
        let mut sc=Scene::preset("Integer Power").unwrap();sc.width=100;sc.height=100;sc.zoom=40.;
        let p=CalcParams::new(&sc).unwrap();let original=subsurface_density(&p,1.);
        sc.width=400;sc.height=400;
        assert!((subsurface_density(&CalcParams::new(&sc).unwrap(),1.)/original-1.).abs()<1e-6);
        sc.zoom*=100.;let magnified=subsurface_density(&CalcParams::new(&sc).unwrap(),1.);
        assert!((magnified/original-100.).abs()<1e-4);
        assert_eq!(subsurface_density(&p,0.),0.);
        assert!((subsurface_density(&p,0.5)/original-0.25).abs()<1e-6);
    }

    #[test]
    fn subsurface_is_visible_in_magnified_translucent_scene() {
        crate::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
        let mut sc=Scene::parse(include_str!("../tests/fixtures/transmission-magnified.m3s")).unwrap();
        sc.width=32;sc.height=32;sc.threads=4;sc.mc.reflections=true;
        sc.transmission_blur=0.5694;sc.translucency_glow=-0.4423;
        sc.subsurface_amount=1.;sc.translucency_enabled=true;
        sc.transmission_cache=Some(Default::default());
        let(p,mut g)=crate::render::calculate(&sc,&|_,_|{}).unwrap();crate::render::post_process(&sc,&p,&mut g,4);
        sc.subsurface_scattering=false;let off=crate::render::paint(&sc,&p,&g);
        sc.subsurface_scattering=true;let on=crate::render::paint(&sc,&p,&g);
        let difference=off.iter().zip(&on).map(|(&a,&b)|a.abs_diff(b) as f64).sum::<f64>()/off.len() as f64;
        eprintln!("magnified scene mean on/off difference={difference}");
        assert!(difference>5.,"scattering is visually negligible: {difference}/255");
        let cache=sc.transmission_cache.as_ref().unwrap().lock().unwrap();let cache=cache.as_ref().unwrap();
        let peak=cache.samples.iter().flat_map(|s|s.subsurface_light).fold(0.0_f32,f32::max);
        eprintln!("magnified scene peak scattered radiance={peak}");
        assert!(peak>0.01,"scattering only extinguished light without gathering a visible source: {peak}");
    }

    #[test]
    fn frosting_edge_thickness_is_independent_of_refraction() {
        crate::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
        let mut sc=Scene::parse(include_str!("../tests/fixtures/translucency-board-occlusion.m3s")).unwrap();
        sc.threads=4;sc.mc.reflections=true;sc.translucency_enabled=true;sc.transmission_blur=1.0861;sc.translucency_glow=0.;
        let measure=|sc:&mut Scene,ri:f32| {
            sc.mc.refraction_index=ri;sc.transmission_cache=Some(Default::default());
            let (p,mut g)=crate::render::calculate(sc,&|_,_|{}).unwrap();crate::render::post_process(sc,&p,&mut g,4);
            let _=crate::render::paint(sc,&p,&g);
            let cache=sc.transmission_cache.as_ref().unwrap().lock().unwrap();let cache=cache.as_ref().unwrap();
            [cache.samples[24*64+26].distance,cache.samples[24*64+53].distance]
        };
        let glass=measure(&mut sc,1.5);let nearly_unrefracted=measure(&mut sc,1.01);
        eprintln!("edge thickness: RI1.5={glass:?}, RI1.01={nearly_unrefracted:?}");
        for (a,b) in glass.into_iter().zip(nearly_unrefracted) {
            assert!(a>0. && b>0.);assert!((a-b).abs()<b*0.05,"refraction made a thin visible edge opaque: {a} versus {b}");
        }
    }

    #[test]
    fn translucency_thickness_is_not_truncated_by_an_internal_board() {
        crate::formulas::add_formula_dir(std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../../rust-assets/M3Formulas"));
        let mut sc=Scene::parse(include_str!("../tests/fixtures/translucency-board-occlusion.m3s")).unwrap();
        sc.threads=4;sc.mc.reflections=true;sc.translucency_enabled=true;sc.transmission_blur=1.2997;sc.translucency_glow=0.;
        sc.transmission_cache=Some(Default::default());
        let measure=|sc:&Scene| {
            let (p,mut g)=crate::render::calculate(sc,&|_,_|{}).unwrap();crate::render::post_process(sc,&p,&mut g,4);
            let _=crate::render::paint(sc,&p,&g);
            let cache=sc.transmission_cache.as_ref().unwrap().lock().unwrap();let cache=cache.as_ref().unwrap();
            let v=cache.samples[27*64+40];eprintln!("captured box path {} component {}",v.distance,v.component);v.distance
        };
        let with_board=measure(&sc);sc.formulas[1].iterations=0;
        sc.transmission_cache=Some(Default::default());
        let without_board=measure(&sc);
        assert!(with_board>0. && without_board>0.);
        assert!((with_board-without_board).abs()<without_board*0.05,
            "internal board changed the box thickness: {with_board} versus {without_board}");
    }

    #[test]
    fn scattering_fades_with_strength_instead_of_exposing_full_extinction() {
        let mut sc=Scene::preset("Integer Power").unwrap();sc.width=16;sc.height=16;
        sc.lighting.gamma=32.;sc.lighting.internal_gamma2=false;
        let p=CalcParams::new(&sc).unwrap();let cam=crate::render::paint_camera(&sc,&p);
        let lv=crate::render::light_vals(&sc,&sc.lighting,&cam);
        let g=vec![SiLight{normal:[0,0,32767],zpos_fine:100<<16,..Default::default()};256];
        let samples=vec![Transmission{light:[1.;3],material_light:[1.;3],distance:1.,opacity:1.,component:1,
            subsurface_valid:true,subsurface_through:[0.;3],..Default::default()};256];
        for strength in [0.,0.1,0.25,0.5,0.75,1.,1.5,2.] {
            let mut ordinary=vec![255u8;256*3];let mut scattering=ordinary.clone();
            blur_transmission(&mut ordinary,&g,&samples,&p,&lv,strength,0.,0.,2,&||false);
            blur_transmission(&mut scattering,&g,&samples,&p,&lv,strength,0.,1.,2,&||false);
            if strength==0. {assert!(ordinary==scattering,"zero Strength retained scattering extinction");}
            // A conservative white medium cannot become black simply because
            // the user reduces its frosted fraction.
            assert!(scattering.iter().all(|&v|v>=190),"dark band at Strength {strength}: {}",scattering.iter().min().unwrap());
        }
    }

    #[test]
    fn scattering_preserves_foreground_depth_fog() {
        let mut sc=Scene::preset("Integer Power").unwrap();sc.width=16;sc.height=16;
        sc.lighting.gamma=32.;sc.lighting.internal_gamma2=false;
        let p=CalcParams::new(&sc).unwrap();let cam=crate::render::paint_camera(&sc,&p);
        let lv=crate::render::light_vals(&sc,&sc.lighting,&cam);
        let g=vec![SiLight{normal:[0,0,32767],zpos_fine:100<<16,..Default::default()};256];
        let fog=[0.2,0.35,0.5];
        for visibility in [0.,0.2,1.] {
            let samples=vec![Transmission{base:fog,entry_light:fog,entry_fog:fog,entry_visibility:[visibility;3],
                distance:1.,opacity:1.,component:1,subsurface_valid:true,subsurface_through:[0.;3],
                subsurface_light:[0.1;3],..Default::default()};256];
            let mut output=vec![0u8;256*3];
            blur_transmission(&mut output,&g,&samples,&p,&lv,2.,0.,1.,2,&||false);
            let expected=reflection_colour::<u8>(&lv,add3(fog,[0.1*visibility;3]));
            assert!(output.chunks_exact(3).all(|v|v.iter().zip(expected).all(|(&a,b)|a.abs_diff(b)<=1)),
                "scattering absorbed foreground fog or bypassed its visibility: {visibility}");
        }
    }

    #[test]
    fn scattering_does_not_extinguish_lit_opaque_frosting() {
        let mut sc=Scene::preset("Integer Power").unwrap();sc.width=16;sc.height=16;
        sc.lighting.gamma=32.;sc.lighting.internal_gamma2=false;
        let p=CalcParams::new(&sc).unwrap();let cam=crate::render::paint_camera(&sc,&p);
        let lv=crate::render::light_vals(&sc,&sc.lighting,&cam);
        let g=vec![SiLight{normal:[0,0,32767],zpos_fine:100<<16,..Default::default()};256];
        for color in [[1.;3],[0.5;3],[0.8,0.3,0.1]] {
            let samples=vec![Transmission{material_light:color,light:[0.9;3],distance:1.,opacity:1.,component:1,
                subsurface_valid:true,subsurface_through:[0.;3],..Default::default()};256];
            let mut output=vec![0u8;256*3];
            blur_transmission(&mut output,&g,&samples,&p,&lv,2.,0.,1.,2,&||false);
            let expected=reflection_colour::<u8>(&lv,color);
            assert!(output.chunks_exact(3).all(|v|v.iter().zip(expected).all(|(&a,b)|a.abs_diff(b)<=1)),"volume extinction darkened lit opaque material {color:?}");
        }
        // The opaque portion of a mixed palette stop keeps its lighting.
        let samples=vec![Transmission{base:[0.4;3],entry_light:[0.4;3],light:[0.1;3],distance:1.,opacity:0.01,
            component:1,subsurface_valid:true,subsurface_through:[0.;3],..Default::default()};256];
        let mut output=vec![0u8;256*3];
        blur_transmission(&mut output,&g,&samples,&p,&lv,2.,0.,1.,2,&||false);
        let expected=reflection_colour::<u8>(&lv,[0.396;3]);
        assert!(output.chunks_exact(3).all(|v|v.iter().zip(expected).all(|(&a,b)|a.abs_diff(b)<=1)),"a tiny transmitting fraction darkened the opaque material");
    }

    #[test]
    fn subsurface_cannot_restore_detail_removed_by_translucency() {
        let mut sc=Scene::preset("Integer Power").unwrap();sc.width=64;sc.height=64;
        sc.lighting.gamma=32.;sc.lighting.internal_gamma2=false;
        let p=CalcParams::new(&sc).unwrap();
        let cam=crate::render::paint_camera(&sc,&p);
        let lv=crate::render::light_vals(&sc,&sc.lighting,&cam);
        let g=vec![SiLight{normal:[0,0,32767],zpos_fine:100<<16,..Default::default()};4096];
        let samples:Vec<_>=(0..4096).map(|i| {
            let light=if (i%64/4+i/64/4)%2==0 {[0.1;3]}else{[0.9;3]};
            Transmission{light,subsurface_background:light,interior_light:[0.4;3],material_light:[0.4;3],distance:1e-8,
                opacity:1.,component:1,subsurface_valid:true,..Default::default()}
        }).collect();
        let initial:Vec<u8>=samples.iter().flat_map(|s|reflection_colour::<u8>(&lv,s.light)).collect();
        // An optically tiny material has near-unit physical transmission. It
        // must still obey the independently selected surface frosting.
        for strength in [0.,0.25,0.6,2.] {
            let mut ordinary=initial.clone();let mut scattering=initial.clone();
            blur_transmission(&mut ordinary,&g,&samples,&p,&lv,strength,0.,0.,2,&||false);
            blur_transmission(&mut scattering,&g,&samples,&p,&lv,strength,0.,1.,2,&||false);
            assert!(ordinary == scattering,"SSS bypassed frosting at strength {strength}");
        }
        let opaque:Vec<_>=samples.iter().map(|s|Transmission{opacity:0.,light:[0.;3],entry_light:[0.2;3],base:[0.2;3],..*s}).collect();
        let mut output=initial.clone();
        blur_transmission(&mut output,&g,&opaque,&p,&lv,0.,0.,1.,2,&||false);
        let expected=reflection_colour::<u8>(&lv,[0.2;3]);
        assert!(output.chunks_exact(3).all(|pixel|pixel == expected), "SSS made an opaque entry transmit the background");
    }

}
