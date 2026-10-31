//! Diagnostic native/interpreter timing for the 40 additional bundled formulas.
use mb3d::{custom::{self,build_machine,code_addr,CustomFormula},m3f::M3f,x86::NATIVE_ENABLED};
use std::{sync::{Arc,atomic::Ordering},time::Instant,hint::black_box};
fn main(){
    println!("formula\tnative_ns\tinterpreted_ns\tspeedup");
    let mut totals=[0.0;2];
    for name in include_str!("../../tests/added-formulas.txt").lines(){
        let def=Arc::new(M3f::load(&std::path::Path::new("rust-assets/M3Formulas").join(format!("{name}.m3f"))).unwrap());
        let c=CustomFormula::new(def.clone());let mut m=build_machine(&[Some(&c)]);let b=custom::IT_BASE;
        let p=m.prog(code_addr(0)).unwrap();assert!(p.is_native()||p.is_direct()||(def.de_option>=20&&include_str!("../../vendor/mb3d-rs/src/x86/native/mod.rs").contains(&format!("0x{:016x} =>",p.hash))),"{name} lacks native code");
        for i in 0..3 {m.put_f64(b+56+8*i,[0.371,0.213,0.419][i as usize]);m.put_f64(b+80+8*i,[0.137,-0.283,0.317][i as usize]);}
        m.put_f64(b,0.173);m.put_f64(b+8,0.01);m.put_f64(b+16,0.01);m.put_u32(b+124,20);m.put_u32(b+128,256f32.to_bits());m.put_u32(b+132,1);m.put_u32(b+104,custom::pconst_addr(0));for i in 0..8{m.put_u32(b+156+4*i,custom::pconst_addr(i as usize));}for i in 0..4{m.put_u32(b+312+4*(i*4+i),1f32.to_bits());}
        let mut times=[0.0;2];
        for round in 0..4 {for offset in 0..2 {let mode=(round+offset)%2;NATIVE_ENABLED.store(mode==0,Ordering::Relaxed);let start=Instant::now();for _ in 0..2000 {
            for i in 0..3{m.put_f64(b+24+8*i,[0.371,0.213,0.419][i as usize]);}m.put_f64(b+48,1.0);m.put_f64(b+112,0.0);m.put_f64(b+256,1.0);m.put_f64(b+288,1.0);
            if def.de_option>=20{m.call_difs(code_addr(0),b+144,custom::pconst_addr(0),0,1,custom::STACK_TOP,custom::MAX_STEPS).unwrap();}else{m.call_formula(code_addr(0),b+56,custom::STACK_TOP,custom::MAX_STEPS).unwrap();}black_box(m.get_f64(b+24));
        }times[mode]+=start.elapsed().as_secs_f64();}}
        totals[0]+=times[0];totals[1]+=times[1];println!("{name}\t{:.1}\t{:.1}\t{:.2}",times[0]*1e9/8000.,times[1]*1e9/8000.,times[1]/times[0]);
    }
    NATIVE_ENABLED.store(true,Ordering::Relaxed);eprintln!("Aggregate native {:.4}s interpreted {:.4}s speedup {:.2}",totals[0],totals[1],totals[1]/totals[0]);
}
