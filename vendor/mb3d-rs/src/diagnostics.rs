//! Optional CPU work counters for the AppKit Info tab. TLS increments,
//! aggregation on Marcher drop (after its work), no shared hot-path atomics.
use std::{cell::{Cell,UnsafeCell}, sync::{Mutex, atomic::{AtomicBool,AtomicUsize,Ordering}}};
#[repr(C)]
#[derive(Clone,Copy,Default)]
pub struct Statistics {
 pub evaluations:[u64;8], pub formula_calls:[u64;8],
 pub rays:u64,pub steps:u64,pub max_steps:u64,pub capped_rays:u64,pub hits:u64,
 pub seconds:[f64;8],pub elapsed:f64,pub timing_mask:u32,
 pub valid:i32,pub threads:i32,pub gpu:i32,
}
static TOTAL:Mutex<Statistics>=Mutex::new(Statistics{evaluations:[0;8],formula_calls:[0;8],rays:0,steps:0,max_steps:0,capped_rays:0,hits:0,seconds:[0.;8],elapsed:0.,timing_mask:0,valid:0,threads:0,gpu:0});
static ACTIVE:AtomicBool=AtomicBool::new(false);
static PHASE:AtomicUsize=AtomicUsize::new(7);
// LOCAL is accessed only on its owning thread. Each unsafe access is a
// non-reentrant field update/take with no callbacks or escaping references.
thread_local!{static LOCAL:UnsafeCell<Statistics>=UnsafeCell::new(Statistics::default());static OVERRIDE:Cell<Option<usize>>=const{Cell::new(None)};static RAY_STEPS:Cell<u64>=const{Cell::new(0)};}
pub fn reset(){flush();*TOTAL.lock().unwrap()=Statistics::default();PHASE.store(7,Ordering::Relaxed);ACTIVE.store(true,Ordering::Relaxed);}
pub fn phase(n:usize){PHASE.store(n,Ordering::Relaxed);}
pub struct Scope(Option<usize>);
impl Scope{pub fn new(n:usize)->Self{Self(OVERRIDE.with(|c|c.replace(Some(n))))}}
impl Drop for Scope{fn drop(&mut self){OVERRIDE.with(|c|c.set(self.0));}}
#[inline] pub fn evaluation(){if ACTIVE.load(Ordering::Relaxed){let n=OVERRIDE.with(|c|c.get()).unwrap_or_else(||PHASE.load(Ordering::Relaxed));LOCAL.with(|c|unsafe{(*c.get()).evaluations[n]+=1;});}}
#[inline] pub fn formula(n:usize){if ACTIVE.load(Ordering::Relaxed){LOCAL.with(|c|unsafe{(*c.get()).formula_calls[n.min(7)]+=1;});}}
pub fn begin_ray(){RAY_STEPS.with(|c|c.set(0));}
#[inline] pub fn step(){if ACTIVE.load(Ordering::Relaxed){RAY_STEPS.with(|c|c.set(c.get()+1));}}
pub fn end_ray(hit:bool){if ACTIVE.load(Ordering::Relaxed){let n=RAY_STEPS.with(|c|c.get());LOCAL.with(|c|unsafe{let s=&mut *c.get();s.rays+=1;s.steps+=n;s.max_steps=s.max_steps.max(n);s.capped_rays+=u64::from(n>=2_000_000&&!hit);s.hits+=u64::from(hit);});}}
pub fn flush(){let s=LOCAL.with(|c|unsafe{std::mem::take(&mut *c.get())});if s.evaluations.iter().sum::<u64>()+s.formula_calls.iter().sum::<u64>()+s.rays==0{return;}let mut t=TOTAL.lock().unwrap();for i in 0..8{t.evaluations[i]+=s.evaluations[i];t.formula_calls[i]+=s.formula_calls[i];}t.rays+=s.rays;t.steps+=s.steps;t.max_steps=t.max_steps.max(s.max_steps);t.capped_rays+=s.capped_rays;t.hits+=s.hits;}
pub fn snapshot()->Statistics{flush();*TOTAL.lock().unwrap()}
