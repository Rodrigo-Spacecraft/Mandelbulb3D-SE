//! Additional bundled native formulas, including lifted kernels.
use super::*;

pub(super) fn f_747c6c9d1edf0d4e(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let vb = pvar.wrapping_sub(256);
    let vm = m.bytes_at::<24>(vb.wrapping_add(224))?;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    let mut v28: u64 = cell(vm, 0);
    let mut v29: u64 = cell(vm, 8);
    let mut v30: u64 = cell(vm, 16);
    'body: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 32)) | (((rg[6] as u64) & 0xffffffffu64) << 32); }
        rg[6] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[6] = ((r13 >> 0) & 0xffffffffu64) as u32;
        f[0] = f64::from_bits(r3);
        f[0] = f[0].abs();
        f[0] = f[0].sqrt();
        { let v = f64::from_bits(v30); f[0] = f[0] * v; }
        { let v = f64::from_bits(r3); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        f[0] = f[0].abs();
        f[0] = f[0].sqrt();
        { let v = f64::from_bits(v29); f[0] = f[0] * v; }
        { let v = f64::from_bits(r4); f[0] = f[0] + v; }
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        f[0] = f[0].abs();
        f[0] = f[0].sqrt();
        { let v = f64::from_bits(v28); f[0] = f[0] * v; }
        { let v = f64::from_bits(r5); f[0] = f[0] + v; }
        r5 = f[0].to_bits();
        { rg[6] = ((s2013 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[5] = ((s2014 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 3, r3);
    rec_set(m, it, 4, r4);
    rec_set(m, it, 5, r5);
    m.wr64u(0x10007ee8u32, s2013);
    m.wr64u(0x10007ef0u32, s2014);
    Ok(())
}

// LoHexIFS

pub(super) fn f_8727bafba736d17a(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<144>(vb.wrapping_add(168))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut r6: u64 = m.rd64u(0x10001030u32);
    let mut r14: u64 = m.rd64u(0x10001070u32);
    let mut r32: u64 = m.rd64u(0x10001100u32);
    let mut r33: u64 = m.rd64u(0x10001108u32);
    let mut s2006: u64 = m.rd64u(0x10007eb0u32);
    let mut s2007: u64 = m.rd64u(0x10007eb8u32);
    let mut s2008: u64 = m.rd64u(0x10007ec0u32);
    let mut s2009: u64 = m.rd64u(0x10007ec8u32);
    let mut s2010: u64 = m.rd64u(0x10007ed0u32);
    let mut s2011: u64 = m.rd64u(0x10007ed8u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut v21: u64 = cell(vm, 0);
    let mut v22: u64 = cell(vm, 8);
    let mut v23: u64 = cell(vm, 16);
    let mut v24: u64 = cell(vm, 24);
    let mut v25: u64 = cell(vm, 32);
    let mut v26: u64 = cell(vm, 40);
    let mut v27: u64 = cell(vm, 48);
    let mut v28: u64 = cell(vm, 56);
    let mut v29: u64 = cell(vm, 64);
    let mut v30: u64 = cell(vm, 72);
    let mut v32: u64 = cell(vm, 88);
    let mut v34: u64 = cell(vm, 104);
    let mut v35: u64 = cell(vm, 112);
    let mut v36: u64 = cell(vm, 120);
    let mut v37: u64 = cell(vm, 128);
    let mut v38: u64 = cell(vm, 136);
    'body: {
        'b6: {
        'b4: {
        'b2: {
        // block 0
        { let bv = 0xffffffbau32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        m.xmm[0] = [r3, r4];
        { let s: u64 = r5; m.xmm[1] = [s, 0]; }
        { let s: [u64; 2] = [v28, v29]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) * f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) * f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v28; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        { let s: [u64; 2] = [v24, v25]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) + f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) + f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v26; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) + f64::from_bits(s)).to_bits(); }
        rg[2] = ((v23 >> 32) & 0xffffffffu64) as u32;
        { let bv = 0x1u32; let av = rg[2]; let r = fl.alu(Alu::And, av, bv, 4); rg[2] = r; }
        if fl.cond(4) { break 'b2; }
        // block 1
        { let s: u64 = r32; m.xmm[5] = [s, 0]; }
        { let s: u64 = v28; let a = m.xmm[5][0]; m.xmm[5][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        r3 = m.xmm[0][0]; r4 = m.xmm[0][1];
        r5 = m.xmm[1][0];
        r32 = m.xmm[5][0];
        } // 'b2
        // block 2
        { let v: u64 = m.xmm[0][0]; s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); } { let v: u64 = m.xmm[0][1]; s2007 = (s2007 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2008 = (s2008 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        { let v: u64 = m.xmm[1][0]; s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2007 >> 48) | (s2008 << 16)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[2] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        f[2] = f[2] * f[2];
        f[1] = f[1] + f[2];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits(v30); f[0] = f[0] - v; }
        f[1] = f64::from_bits(0x3ff0000000000000);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(5) { break 'b4; }
        // block 3
        f[0] = f[0];
        f[0] = f64::from_bits((((s2007 >> 48) | (s2008 << 16)) & u64::MAX));
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2007 = (s2007 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2008 = (s2008 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        { let v = f64::from_bits(v38); f[0] = f[0] * v; }
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        { let v = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX)); f[0] = f[0] + v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v: u64 = f[0].to_bits(); s2010 = (s2010 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2011 = (s2011 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        { let v = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX)); f[0] = f[0] - v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits((((s2010 >> 48) | (s2011 << 16)) & u64::MAX)); f[0] = f[0] + v; }
        { let v = f64::from_bits(v35); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v: u64 = f[0].to_bits(); s2011 = (s2011 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2012 = (s2012 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = -f[0];
        f[1] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        f[1] = f[1] + f[1];
        f[2] = f64::from_bits(0x3ff0000000000000);
        f[1] = f[1] + f[2];
        { let x = m.round_int(f[1]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[1] = f[1] - v; }
        f[2] = f[1];
        f[2] = f[2] * f[2];
        f[2] = f[2] * f[2];
        f[1] = f[1] * f[2];
        { let v = f64::from_bits(v32); f[1] = f[1] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[1] = f[1] + v; }
        { let v = f64::from_bits((((s2010 >> 48) | (s2011 << 16)) & u64::MAX)); f[1] = f[1] + v; }
        { let v = f64::from_bits(v35); f[1] = f[1] * v; }
        { let x = m.round_int(f[1]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[1] = f[1] - v; }
        f[2] = f[1];
        f[2] = f[2] * f[2];
        f[2] = f[2] * f[2];
        f[1] = f[1] * f[2];
        { let v = f64::from_bits(v32); f[1] = f[1] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[1] = f[1] + v; }
        f[0] = f[0] + f[1];
        { let v: u64 = f[0].to_bits(); s2012 = (s2012 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2013 = (s2013 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[1] = f64::from_bits((((s2011 >> 48) | (s2012 << 16)) & u64::MAX));
        { let v = f64::from_bits(v36); f[1] = f[1] * v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[1] = f[1] * v; }
        { let v: u64 = f[1].to_bits(); s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[1] = f64::from_bits((((s2011 >> 48) | (s2012 << 16)) & u64::MAX));
        { let v = f64::from_bits(v34); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        { let v = f64::from_bits(v37); f[0] = f[0] * v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2007 >> 48) | (s2008 << 16)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[2] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        f[2] = f[2] * f[2];
        f[1] = f[1] + f[2];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits(v30); f[0] = f[0] - v; }
        } // 'b4
        // block 4
        rg[2] = ((v23 >> 32) & 0xffffffffu64) as u32;
        { let bv = 0x1u32; let av = rg[2]; let r = fl.alu(Alu::And, av, bv, 4); rg[2] = r; }
        if fl.cond(5) { break 'b6; }
        // block 5
        { let v = f64::from_bits(v28); f[0] = f[0] / v; }
        } // 'b6
        // block 6
        r14 = f[0].to_bits();
        { let bv = 0x46u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10001070u32, r14);
    m.wr64u(0x10001100u32, r32);
    m.wr64u(0x10007eb0u32, s2006);
    m.wr64u(0x10007eb8u32, s2007);
    m.wr64u(0x10007ec0u32, s2008);
    m.wr64u(0x10007ec8u32, s2009);
    m.wr64u(0x10007ed0u32, s2010);
    m.wr64u(0x10007ed8u32, s2011);
    m.wr64u(0x10007ee0u32, s2012);
    m.wr64u(0x10007ee8u32, s2013);
    m.regs = rg;
    m.fl = fl;
    m.fsw_cc = fsw;
    m.st = f;
    Ok(())
}


pub(super) fn f_89f03bb8be527f08(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let mut steps = m.steps;
    let limit = steps + max_steps;
    let res = (|| -> R<()> {
    let mut b: u32 = 0;
    loop {
        match b {
            0 => {
                { let v = rg[5]; push_lu(m, &mut rg, v); }
                rg[5] = rg[4];
                { let bv = 0x8u32; let av = rg[4]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[4] = r; }
                rg[2] = m.rd32u(rg[5].wrapping_add(0x8u32));
                { let bv = 0x38u32; let av = rg[2]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[2] = r; }
                rg[0] = m.rd32u(rg[2].wrapping_add(0x68u32));
                f[0] = m.rdf64u(rg[2].wrapping_add(0x18u32));
                f[1] = m.rdf64u(rg[2].wrapping_add(0x20u32));
                f[2] = m.rdf64u(rg[0].wrapping_add(0xffffffe4u32));
                f[3] = f[0];
                f[4] = m.rdf64u(rg[2].wrapping_add(0x28u32));
                f.swap(4, 2);
                { let a = rg[5].wrapping_add(0xfffffff8u32); m.wrf64u(a, f[4]); }
                f[4] = f[1];
                f.swap(4, 3);
                f[4] = f[4] * f[0];
                f.swap(4, 3);
                f[4] = f[4] * f[1];
                rg[1] = rg[0].wrapping_add(0xfffffff4u32);
                f[5] = m.rdf64u(rg[0].wrapping_add(0xffffffdcu32));
                f.swap(5, 3);
                f[4] = f[4] + f[5];
                f[5] = f[2];
                rg[0] = m.rd32u(rg[0].wrapping_add(0xfffffff4u32));
                f[5] = f[5] * f[2];
                { let bv = rg[0]; let av = rg[0]; fl.alu(Alu::And, av, bv, 4); }
                f[4] = f[4] + f[5];
                f[4] = f[4].sqrt();
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 8; continue; }
                b = 1;
            }
            1 => {
                f[5] = f64::from_bits(0x3ff0000000000000);
                f[6] = f[5];
                f[6] = f[6] / f[4];
                f[0] = f[0] * f[6];
                f[1] = f[1] * f[6];
                b = 2;
            }
            2 => {
                f[6] = f[5];
                rg[0] = m.rd32u(rg[1].wrapping_add(0xfffffffcu32));
                f[6] = f[6] / f[4];
                { let bv = rg[0]; let av = rg[0]; fl.alu(Alu::And, av, bv, 4); }
                f[2] = f[2] * f[6];
                f.swap(5, 2);
                f[5] = f[5] + f[3];
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 4; continue; }
                b = 3;
            }
            3 => {
                f[5] = f[5] * f[5];
                f.swap(5, 3);
                f[5] = f[5] * f[5];
                f.swap(5, 3);
                b = 4;
            }
            4 => {
                rg[0] = m.rd32u(rg[1].wrapping_add(0xfffffff8u32));
                f[6] = f[5];
                { let bv = rg[0]; let av = rg[0]; fl.alu(Alu::And, av, bv, 4); }
                if fl.cond(5) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 6; continue; }
                b = 5;
            }
            5 => {
                f[6] = f[6];
                f[6] = f64::from_bits(0x3ff0000000000000);
                f[5] = f[6] / f[5];
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 7; continue;
            }
            6 => {
                f[5] = f[6];
                b = 7;
            }
            7 => {
                f[0] = f[0] * f[5];
                f[1] = f[1] * f[5];
                f[5] = f[0];
                f[6] = f[1];
                f[6] = f[6] * f[1];
                f.swap(6, 5);
                f[6] = f[6] * f[0];
                f.swap(6, 1);
                f[0] = f[0] * f[6];
                f[1] = f[1] - f[5];
                f.swap(4, 0);
                f[4] = f[4] + f[4];
                f[5] = f[3];
                f[6] = f[4];
                f[7] = f[1];
                f.swap(7, 5);
                f[3] = f[3] * f[7];
                f[6] = f[6] * f[4];
                f.swap(6, 5);
                f[6] = f[6] * f[1];
                f.swap(6, 3);
                f[6] = f[6] + f[2];
                f.swap(6, 3);
                f[5] = f[5] + f[6];
                f.swap(5, 3);
                { let v = m.rdf64u(rg[5].wrapping_add(0xfffffff8u32)); f[5] = f[5] * v; }
                f[6] = f[3];
                f[6] = f[6] - f[2];
                f.swap(6, 3);
                f[2] = f[2] + f[6];
                f.swap(5, 2);
                f[6] = f64::from_bits(0x3ff0000000000000);
                f[5] = f[6] / f[5];
                f[2] = f[2] * f[5];
                f[3] = f[3] * f[5];
                f[5] = f[0];
                f.swap(5, 4);
                f[5] = f[5] * f[2];
                f.swap(5, 4);
                f[0] = f[0] * f[5];
                f.swap(4, 2);
                f[1] = f[1] * f[4];
                f.swap(3, 1);
                f[3] = f[3] * f[0];
                f.swap(3, 2);
                f[3] = f[3] * f[0];
                f.swap(3, 1);
                f[0] = f[0] * f[3];
                { let v = m.rdf64u(rg[2].wrapping_add(0x50u32)); f[2] = f[2] + v; }
                f.swap(2, 1);
                { let v = m.rdf64u(rg[2].wrapping_add(0x58u32)); f[2] = f[2] + v; }
                f.swap(2, 0);
                { let v = m.rdf64u(rg[2].wrapping_add(0x60u32)); f[2] = f[2] + v; }
                f.swap(2, 1);
                { let a = rg[2].wrapping_add(0x18u32); m.wrf64u(a, f[2]); }
                f.swap(1, 0);
                { let a = rg[2].wrapping_add(0x20u32); m.wrf64u(a, f[1]); }
                { let a = rg[2].wrapping_add(0x28u32); m.wrf64u(a, f[0]); }
                if let Op::Gen(ins, nx, at) = &p.ops[113] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Leave
                let r = pop_lu(m, &mut rg); rg[ESP] = rg[ESP].wrapping_add(8);                              if r != RETURN_SENTINEL { match p.rets.iter().find(|e| e.0 == r).map(|e| e.1) { _ => return Err(unsup(r, "bad return".into())) } }                              m.st = f; return Ok(());
            }
            8 => {
                f[5] = f64::from_bits(0x3ff0000000000000);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 2; continue;
            }
            _ => return Err(unsup(0, "bad block".into())),
        }
    }
    })();
    // after an error the machine state does not matter (the caller drops
    // the result, the next call starts with fresh registers); writing it
    // back only on success keeps the locals dead on the error paths
    if res.is_ok() {
        m.regs = rg;
        m.fl = fl;
        m.fsw_cc = fsw;
        m.steps = steps;
    }
    res
}

// _T_AbsOffset4D

pub(super) fn f_8a7908c7e72f01c6(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let vb = pvar.wrapping_sub(256);
    let vm = m.bytes_at::<32>(vb.wrapping_add(216))?;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r6: u64 = rec_get(m, it, pvar, 6);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    let mut v27: u64 = cell(vm, 0);
    let mut v28: u64 = cell(vm, 8);
    let mut v29: u64 = cell(vm, 16);
    let mut v30: u64 = cell(vm, 24);
    'body: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 32)) | (((rg[6] as u64) & 0xffffffffu64) << 32); }
        rg[6] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[6] = ((r13 >> 0) & 0xffffffffu64) as u32;
        f[0] = f64::from_bits(r3);
        f[0] = f[0].abs();
        { let v = f64::from_bits(v30); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        f[0] = f[0].abs();
        { let v = f64::from_bits(v29); f[0] = f[0] + v; }
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        f[0] = f[0].abs();
        { let v = f64::from_bits(v28); f[0] = f[0] + v; }
        r5 = f[0].to_bits();
        f[0] = f64::from_bits(r6);
        f[0] = f[0].abs();
        { let v = f64::from_bits(v27); f[0] = f[0] + v; }
        r6 = f[0].to_bits();
        { rg[6] = ((s2013 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[5] = ((s2014 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 3, r3);
    rec_set(m, it, 4, r4);
    rec_set(m, it, 5, r5);
    rec_set(m, it, 6, r6);
    m.wr64u(0x10007ee8u32, s2013);
    m.wr64u(0x10007ef0u32, s2014);
    Ok(())
}

// LoHexCIFS

pub(super) fn f_8fc38030eb046ba1(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<232>(vb.wrapping_add(80))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut r6: u64 = m.rd64u(0x10001030u32);
    let mut r14: u64 = m.rd64u(0x10001070u32);
    let mut r32: u64 = m.rd64u(0x10001100u32);
    let mut r33: u64 = m.rd64u(0x10001108u32);
    let mut r34: u64 = m.rd64u(0x10001110u32);
    let mut s2006: u64 = m.rd64u(0x10007eb0u32);
    let mut s2007: u64 = m.rd64u(0x10007eb8u32);
    let mut s2008: u64 = m.rd64u(0x10007ec0u32);
    let mut s2009: u64 = m.rd64u(0x10007ec8u32);
    let mut s2010: u64 = m.rd64u(0x10007ed0u32);
    let mut s2011: u64 = m.rd64u(0x10007ed8u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut v10: u64 = cell(vm, 0);
    let mut v11: u64 = cell(vm, 8);
    let mut v12: u64 = cell(vm, 16);
    let mut v13: u64 = cell(vm, 24);
    let mut v14: u64 = cell(vm, 32);
    let mut v15: u64 = cell(vm, 40);
    let mut v16: u64 = cell(vm, 48);
    let mut v17: u64 = cell(vm, 56);
    let mut v18: u64 = cell(vm, 64);
    let mut v19: u64 = cell(vm, 72);
    let mut v20: u64 = cell(vm, 80);
    let mut v21: u64 = cell(vm, 88);
    let mut v22: u64 = cell(vm, 96);
    let mut v23: u64 = cell(vm, 104);
    let mut v24: u64 = cell(vm, 112);
    let mut v25: u64 = cell(vm, 120);
    let mut v26: u64 = cell(vm, 128);
    let mut v27: u64 = cell(vm, 136);
    let mut v28: u64 = cell(vm, 144);
    let mut v29: u64 = cell(vm, 152);
    let mut v30: u64 = cell(vm, 160);
    let mut v32: u64 = cell(vm, 176);
    let mut v34: u64 = cell(vm, 192);
    let mut v35: u64 = cell(vm, 200);
    let mut v36: u64 = cell(vm, 208);
    let mut v37: u64 = cell(vm, 216);
    let mut v38: u64 = cell(vm, 224);
    'body: {
        'b7: {
        'b5: {
        'b4: {
        'b2: {
        // block 0
        { let bv = 0xffffffbau32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        m.xmm[0] = [r3, r4];
        { let s: u64 = r5; m.xmm[1] = [s, 0]; }
        { let s: [u64; 2] = [v28, v29]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) * f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) * f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v28; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        { let s: [u64; 2] = [v24, v25]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) + f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) + f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v26; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) + f64::from_bits(s)).to_bits(); }
        rg[2] = ((v23 >> 32) & 0xffffffffu64) as u32;
        { let bv = 0x1u32; let av = rg[2]; let r = fl.alu(Alu::And, av, bv, 4); rg[2] = r; }
        if fl.cond(4) { break 'b2; }
        // block 1
        { let s: u64 = r32; m.xmm[5] = [s, 0]; }
        { let s: u64 = v28; let a = m.xmm[5][0]; m.xmm[5][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        r3 = m.xmm[0][0]; r4 = m.xmm[0][1];
        r5 = m.xmm[1][0];
        r32 = m.xmm[5][0];
        } // 'b2
        // block 2
        { let v: u64 = m.xmm[0][0]; s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); } { let v: u64 = m.xmm[0][1]; s2007 = (s2007 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2008 = (s2008 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        { let v: u64 = m.xmm[1][0]; s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        f[1] = f64::from_bits((((s2007 >> 48) | (s2008 << 16)) & u64::MAX));
        f[2] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        f[3] = f[2];
        { let v = (f32::from_bits(((v12 >> 32) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[4] = f[1];
        { let v = (f32::from_bits(((v12 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[0];
        { let v = (f32::from_bits(((v11 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[2];
        { let v = (f32::from_bits(((v15 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[5] = f[1];
        { let v = (f32::from_bits(((v15 >> 0) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f[5] = f[0];
        { let v = (f32::from_bits(((v14 >> 32) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f.swap(4, 2);
        { let v = (f32::from_bits(((v14 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f.swap(4, 1);
        { let v = (f32::from_bits(((v13 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[1] = f[1] + f[4];
        f.swap(3, 0);
        { let v = (f32::from_bits(((v13 >> 0) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[1] = f[1] + f[3];
        { let v: u64 = f[2].to_bits(); s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        { let v: u64 = f[1].to_bits(); s2007 = (s2007 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2008 = (s2008 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        { let v: u64 = f[0].to_bits(); s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2007 >> 48) | (s2008 << 16)) & u64::MAX));
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2007 = (s2007 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2008 = (s2008 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        { let v = f64::from_bits(v38); f[0] = f[0] * v; }
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        { let v = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX)); f[0] = f[0] + v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v: u64 = f[0].to_bits(); s2010 = (s2010 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2011 = (s2011 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        { let v = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX)); f[0] = f[0] - v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits((((s2010 >> 48) | (s2011 << 16)) & u64::MAX)); f[0] = f[0] + v; }
        { let v = f64::from_bits(v35); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v: u64 = f[0].to_bits(); s2011 = (s2011 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2012 = (s2012 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = -f[0];
        f[1] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        f[1] = f[1] + f[1];
        f[2] = f64::from_bits(0x3ff0000000000000);
        f[1] = f[1] + f[2];
        { let x = m.round_int(f[1]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[1] = f[1] - v; }
        f[2] = f[1];
        f[2] = f[2] * f[2];
        f[2] = f[2] * f[2];
        f[1] = f[1] * f[2];
        { let v = f64::from_bits(v32); f[1] = f[1] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[1] = f[1] + v; }
        { let v = f64::from_bits((((s2010 >> 48) | (s2011 << 16)) & u64::MAX)); f[1] = f[1] + v; }
        { let v = f64::from_bits(v35); f[1] = f[1] * v; }
        { let x = m.round_int(f[1]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[1] = f[1] - v; }
        f[2] = f[1];
        f[2] = f[2] * f[2];
        f[2] = f[2] * f[2];
        f[1] = f[1] * f[2];
        { let v = f64::from_bits(v32); f[1] = f[1] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[1] = f[1] + v; }
        f[0] = f[0] + f[1];
        { let v: u64 = f[0].to_bits(); s2012 = (s2012 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2013 = (s2013 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[1] = f64::from_bits((((s2011 >> 48) | (s2012 << 16)) & u64::MAX));
        { let v = f64::from_bits(v36); f[1] = f[1] * v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[1] = f[1] * v; }
        { let v: u64 = f[1].to_bits(); s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[1] = f64::from_bits((((s2011 >> 48) | (s2012 << 16)) & u64::MAX));
        { let v = f64::from_bits(v34); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        { let v = f64::from_bits(v37); f[0] = f[0] * v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        f[1] = f64::from_bits((((s2007 >> 48) | (s2008 << 16)) & u64::MAX));
        f[2] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        f[3] = f[2];
        { let v = (f32::from_bits(((v19 >> 0) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[4] = f[1];
        { let v = (f32::from_bits(((v17 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[0];
        { let v = (f32::from_bits(((v16 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[2];
        { let v = (f32::from_bits(((v20 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[5] = f[1];
        { let v = (f32::from_bits(((v18 >> 32) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f[5] = f[0];
        { let v = (f32::from_bits(((v17 >> 0) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f.swap(4, 2);
        { let v = (f32::from_bits(((v19 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f.swap(4, 1);
        { let v = (f32::from_bits(((v18 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[1] = f[1] + f[4];
        f.swap(3, 0);
        { let v = (f32::from_bits(((v16 >> 32) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[1] = f[1] + f[3];
        { let v: u64 = f[2].to_bits(); s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        { let v: u64 = f[1].to_bits(); s2007 = (s2007 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2008 = (s2008 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        { let v: u64 = f[0].to_bits(); s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2007 >> 48) | (s2008 << 16)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        f[1] = f64::from_bits(0x3ff0000000000000);
        f[0] = f[0] - f[1];
        { let v = (f32::from_bits(((v20 >> 32) & 0xffffffffu64) as u32) as f64); f[0] = f[0] * v; }
        f[1] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        { let v = (f32::from_bits(((v21 >> 0) & 0xffffffffu64) as u32) as f64); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        f[1] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        { let v = f64::from_bits(v30); f[1] = f[1] + v; }
        f[1] = f[1].abs();
        { let v = f64::from_bits(v30); f[1] = f[1] - v; }
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(5) { break 'b4; }
        // block 3
        f[0] = f[1];
        break 'b5;
        } // 'b4
        // block 4
        f[1] = f[1];
        } // 'b5
        // block 5
        rg[2] = ((v23 >> 32) & 0xffffffffu64) as u32;
        { let bv = 0x1u32; let av = rg[2]; let r = fl.alu(Alu::And, av, bv, 4); rg[2] = r; }
        if fl.cond(5) { break 'b7; }
        // block 6
        { let v = f64::from_bits(v28); f[0] = f[0] / v; }
        } // 'b7
        // block 7
        r14 = f[0].to_bits();
        f[0] = f64::from_bits((((v10 >> 32) | (v11 << 32)) & u64::MAX));
        r34 = f[0].to_bits();
        { let bv = 0x46u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10001070u32, r14);
    m.wr64u(0x10001100u32, r32);
    m.wr64u(0x10001110u32, r34);
    m.wr64u(0x10007eb0u32, s2006);
    m.wr64u(0x10007eb8u32, s2007);
    m.wr64u(0x10007ec0u32, s2008);
    m.wr64u(0x10007ec8u32, s2009);
    m.wr64u(0x10007ed0u32, s2010);
    m.wr64u(0x10007ed8u32, s2011);
    m.wr64u(0x10007ee0u32, s2012);
    m.wr64u(0x10007ee8u32, s2013);
    m.regs = rg;
    m.fl = fl;
    m.fsw_cc = fsw;
    m.st = f;
    Ok(())
}

// LoResIFS

pub(super) fn f_9097eae42ce14448(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<112>(vb.wrapping_add(168))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut r6: u64 = m.rd64u(0x10001030u32);
    let mut r14: u64 = m.rd64u(0x10001070u32);
    let mut r32: u64 = m.rd64u(0x10001100u32);
    let mut r33: u64 = m.rd64u(0x10001108u32);
    let mut s2009: u64 = m.rd64u(0x10007ec8u32);
    let mut s2010: u64 = m.rd64u(0x10007ed0u32);
    let mut s2011: u64 = m.rd64u(0x10007ed8u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut v21: u64 = cell(vm, 0);
    let mut v22: u64 = cell(vm, 8);
    let mut v23: u64 = cell(vm, 16);
    let mut v24: u64 = cell(vm, 24);
    let mut v25: u64 = cell(vm, 32);
    let mut v26: u64 = cell(vm, 40);
    let mut v27: u64 = cell(vm, 48);
    let mut v28: u64 = cell(vm, 56);
    let mut v29: u64 = cell(vm, 64);
    let mut v30: u64 = cell(vm, 72);
    let mut v32: u64 = cell(vm, 88);
    let mut v34: u64 = cell(vm, 104);
    'body: {
        'b9: {
        'b7: {
        'b6: {
        'b5: {
        'b2: {
        // block 0
        { let bv = 0xffffffd0u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        m.xmm[0] = [r3, r4];
        { let s: u64 = r5; m.xmm[1] = [s, 0]; }
        { let s: [u64; 2] = [v28, v29]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) * f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) * f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v28; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        { let s: [u64; 2] = [v24, v25]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) + f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) + f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v26; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) + f64::from_bits(s)).to_bits(); }
        rg[2] = ((v23 >> 32) & 0xffffffffu64) as u32;
        { let bv = 0x1u32; let av = rg[2]; let r = fl.alu(Alu::And, av, bv, 4); rg[2] = r; }
        if fl.cond(4) { break 'b2; }
        // block 1
        { let s: u64 = r32; m.xmm[5] = [s, 0]; }
        { let s: u64 = v28; let a = m.xmm[5][0]; m.xmm[5][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        r3 = m.xmm[0][0]; r4 = m.xmm[0][1];
        r5 = m.xmm[1][0];
        r32 = m.xmm[5][0];
        } // 'b2
        // block 2
        { let v: u64 = m.xmm[0][0]; s2009 = (s2009 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2010 = (s2010 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); } { let v: u64 = m.xmm[0][1]; s2010 = (s2010 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2011 = (s2011 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        { let v: u64 = m.xmm[1][0]; s2011 = (s2011 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2012 = (s2012 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        f[0] = f64::from_bits((((s2009 >> 32) | (s2010 << 32)) & u64::MAX));
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2010 >> 32) | (s2011 << 32)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[2] = f64::from_bits((((s2011 >> 32) | (s2012 << 32)) & u64::MAX));
        f[2] = f[2] * f[2];
        f[1] = f[1] + f[2];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits(v30); f[0] = f[0] - v; }
        f[1] = f64::from_bits(0x3ff0000000000000);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(5) { break 'b7; }
        // block 3
        f[0] = f[0];
        rg[2] = ((v23 >> 32) & 0xffffffffu64) as u32;
        { let bv = 0x2u32; let av = rg[2]; let r = fl.alu(Alu::And, av, bv, 4); rg[2] = r; }
        if fl.cond(5) { break 'b5; }
        // block 4
        f[0] = f64::from_bits((((s2009 >> 32) | (s2010 << 32)) & u64::MAX));
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; s2012 = (s2012 & !(0xffffffffu64 << 32)) | (((i as u64) & 0xffffffffu64) << 32); }
        { let v = (((s2012 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = (((s2012 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2009 = (s2009 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2010 = (s2010 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        f[0] = f64::from_bits((((s2010 >> 32) | (s2011 << 32)) & u64::MAX));
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; s2012 = (s2012 & !(0xffffffffu64 << 32)) | (((i as u64) & 0xffffffffu64) << 32); }
        { let v = (((s2012 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = (((s2012 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2010 = (s2010 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2011 = (s2011 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        f[0] = f64::from_bits((((s2011 >> 32) | (s2012 << 32)) & u64::MAX));
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; s2012 = (s2012 & !(0xffffffffu64 << 32)) | (((i as u64) & 0xffffffffu64) << 32); }
        { let v = (((s2012 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = (((s2012 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2011 = (s2011 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2012 = (s2012 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        break 'b6;
        } // 'b5
        // block 5
        f[0] = f64::from_bits((((s2009 >> 32) | (s2010 << 32)) & u64::MAX));
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; s2012 = (s2012 & !(0xffffffffu64 << 32)) | (((i as u64) & 0xffffffffu64) << 32); }
        { let v = (((s2012 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        { let v = f64::from_bits(v34); f[0] = f[0] + v; }
        f[0] = f[0] * f[0];
        f[0] = f[0] * f[0];
        f[0] = f[0] * f[0];
        { let v = (((s2012 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2009 = (s2009 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2010 = (s2010 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        f[0] = f64::from_bits((((s2010 >> 32) | (s2011 << 32)) & u64::MAX));
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; s2012 = (s2012 & !(0xffffffffu64 << 32)) | (((i as u64) & 0xffffffffu64) << 32); }
        { let v = (((s2012 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        { let v = f64::from_bits(v34); f[0] = f[0] + v; }
        f[0] = f[0] * f[0];
        f[0] = f[0] * f[0];
        f[0] = f[0] * f[0];
        { let v = (((s2012 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2010 = (s2010 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2011 = (s2011 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        f[0] = f64::from_bits((((s2011 >> 32) | (s2012 << 32)) & u64::MAX));
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; s2012 = (s2012 & !(0xffffffffu64 << 32)) | (((i as u64) & 0xffffffffu64) << 32); }
        { let v = (((s2012 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        { let v = f64::from_bits(v34); f[0] = f[0] + v; }
        f[0] = f[0] * f[0];
        f[0] = f[0] * f[0];
        f[0] = f[0] * f[0];
        { let v = (((s2012 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2011 = (s2011 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2012 = (s2012 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        } // 'b6
        // block 6
        f[0] = f64::from_bits((((s2009 >> 32) | (s2010 << 32)) & u64::MAX));
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2010 >> 32) | (s2011 << 32)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[2] = f64::from_bits((((s2011 >> 32) | (s2012 << 32)) & u64::MAX));
        f[2] = f[2] * f[2];
        f[1] = f[1] + f[2];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits(v30); f[0] = f[0] - v; }
        } // 'b7
        // block 7
        rg[2] = ((v23 >> 32) & 0xffffffffu64) as u32;
        { let bv = 0x1u32; let av = rg[2]; let r = fl.alu(Alu::And, av, bv, 4); rg[2] = r; }
        if fl.cond(5) { break 'b9; }
        // block 8
        { let v = f64::from_bits(v28); f[0] = f[0] / v; }
        } // 'b9
        // block 9
        r14 = f[0].to_bits();
        { let bv = 0x30u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10001070u32, r14);
    m.wr64u(0x10001100u32, r32);
    m.wr64u(0x10007ec8u32, s2009);
    m.wr64u(0x10007ed0u32, s2010);
    m.wr64u(0x10007ed8u32, s2011);
    m.wr64u(0x10007ee0u32, s2012);
    m.regs = rg;
    m.fl = fl;
    m.fsw_cc = fsw;
    m.st = f;
    Ok(())
}

// _loresmode

pub(super) fn f_a774b10b3f158cbb(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let vb = pvar.wrapping_sub(256);
    let vm = m.bytes_at::<32>(vb.wrapping_add(232))?;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s2006: u64 = m.rd64u(0x10007eb0u32);
    let mut s2007: u64 = m.rd64u(0x10007eb8u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    let mut v29: u64 = cell(vm, 0);
    let mut v30: u64 = cell(vm, 8);
    let mut v32: u64 = cell(vm, 24);
    'body: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        { let bv = 0x30u32; let av = rg[4]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[4] = r; }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2007 = (s2007 & !(0xffffffffu64 << 32)) | (((rg[3] as u64) & 0xffffffffu64) << 32); }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2007 = (s2007 & !(0xffffffffu64 << 0)) | (((rg[6] as u64) & 0xffffffffu64) << 0); }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2006 = (s2006 & !(0xffffffffu64 << 32)) | (((rg[7] as u64) & 0xffffffffu64) << 32); }
        rg[6] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[7] = ((r13 >> 0) & 0xffffffffu64) as u32;
        rg[3] = rg[0];
        f[0] = f64::from_bits(r3);
        { let v = f64::from_bits(v30); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; s2012 = (s2012 & !(0xffffffffu64 << 0)) | (((i as u64) & 0xffffffffu64) << 0); }
        { let v = (((s2012 >> 0) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = (((s2012 >> 0) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits(v29); f[0] = f[0] * v; }
        r3 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        { let v = f64::from_bits(v30); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; s2012 = (s2012 & !(0xffffffffu64 << 0)) | (((i as u64) & 0xffffffffu64) << 0); }
        { let v = (((s2012 >> 0) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = (((s2012 >> 0) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits(v29); f[0] = f[0] * v; }
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        { let v = f64::from_bits(v30); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; s2012 = (s2012 & !(0xffffffffu64 << 0)) | (((i as u64) & 0xffffffffu64) << 0); }
        { let v = (((s2012 >> 0) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = (((s2012 >> 0) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits(v29); f[0] = f[0] * v; }
        r5 = f[0].to_bits();
        rg[0] = rg[3];
        { rg[7] = ((s2006 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[6] = ((s2007 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[3] = ((s2007 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[4] = rg[5];
        { rg[5] = ((s2014 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 3, r3);
    rec_set(m, it, 4, r4);
    rec_set(m, it, 5, r5);
    m.wr64u(0x10007eb0u32, s2006);
    m.wr64u(0x10007eb8u32, s2007);
    m.wr64u(0x10007ee0u32, s2012);
    m.wr64u(0x10007ef0u32, s2014);
    Ok(())
}

// LoHexTIFS

pub(super) fn f_add1e1a9add7e00d(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<232>(vb.wrapping_add(80))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut r6: u64 = m.rd64u(0x10001030u32);
    let mut r14: u64 = m.rd64u(0x10001070u32);
    let mut r32: u64 = m.rd64u(0x10001100u32);
    let mut r33: u64 = m.rd64u(0x10001108u32);
    let mut r34: u64 = m.rd64u(0x10001110u32);
    let mut s2006: u64 = m.rd64u(0x10007eb0u32);
    let mut s2007: u64 = m.rd64u(0x10007eb8u32);
    let mut s2008: u64 = m.rd64u(0x10007ec0u32);
    let mut s2009: u64 = m.rd64u(0x10007ec8u32);
    let mut s2010: u64 = m.rd64u(0x10007ed0u32);
    let mut s2011: u64 = m.rd64u(0x10007ed8u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut v10: u64 = cell(vm, 0);
    let mut v11: u64 = cell(vm, 8);
    let mut v12: u64 = cell(vm, 16);
    let mut v13: u64 = cell(vm, 24);
    let mut v14: u64 = cell(vm, 32);
    let mut v15: u64 = cell(vm, 40);
    let mut v16: u64 = cell(vm, 48);
    let mut v17: u64 = cell(vm, 56);
    let mut v18: u64 = cell(vm, 64);
    let mut v19: u64 = cell(vm, 72);
    let mut v20: u64 = cell(vm, 80);
    let mut v21: u64 = cell(vm, 88);
    let mut v22: u64 = cell(vm, 96);
    let mut v23: u64 = cell(vm, 104);
    let mut v24: u64 = cell(vm, 112);
    let mut v25: u64 = cell(vm, 120);
    let mut v26: u64 = cell(vm, 128);
    let mut v27: u64 = cell(vm, 136);
    let mut v28: u64 = cell(vm, 144);
    let mut v29: u64 = cell(vm, 152);
    let mut v30: u64 = cell(vm, 160);
    let mut v32: u64 = cell(vm, 176);
    let mut v34: u64 = cell(vm, 192);
    let mut v35: u64 = cell(vm, 200);
    let mut v36: u64 = cell(vm, 208);
    let mut v37: u64 = cell(vm, 216);
    let mut v38: u64 = cell(vm, 224);
    'body: {
        'b6: {
        'b4: {
        'b2: {
        // block 0
        { let bv = 0xffffffbau32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        m.xmm[0] = [r3, r4];
        { let s: u64 = r5; m.xmm[1] = [s, 0]; }
        { let s: [u64; 2] = [v28, v29]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) * f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) * f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v28; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        { let s: [u64; 2] = [v24, v25]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) + f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) + f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v26; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) + f64::from_bits(s)).to_bits(); }
        rg[2] = ((v23 >> 32) & 0xffffffffu64) as u32;
        { let bv = 0x1u32; let av = rg[2]; let r = fl.alu(Alu::And, av, bv, 4); rg[2] = r; }
        if fl.cond(4) { break 'b2; }
        // block 1
        { let s: u64 = r32; m.xmm[5] = [s, 0]; }
        { let s: u64 = v28; let a = m.xmm[5][0]; m.xmm[5][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        r3 = m.xmm[0][0]; r4 = m.xmm[0][1];
        r5 = m.xmm[1][0];
        r32 = m.xmm[5][0];
        } // 'b2
        // block 2
        { let v: u64 = m.xmm[0][0]; s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); } { let v: u64 = m.xmm[0][1]; s2007 = (s2007 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2008 = (s2008 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        { let v: u64 = m.xmm[1][0]; s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        f[1] = f64::from_bits((((s2007 >> 48) | (s2008 << 16)) & u64::MAX));
        f[2] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        f[3] = f[2];
        { let v = (f32::from_bits(((v12 >> 32) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[4] = f[1];
        { let v = (f32::from_bits(((v12 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[0];
        { let v = (f32::from_bits(((v11 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[2];
        { let v = (f32::from_bits(((v15 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[5] = f[1];
        { let v = (f32::from_bits(((v15 >> 0) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f[5] = f[0];
        { let v = (f32::from_bits(((v14 >> 32) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f.swap(4, 2);
        { let v = (f32::from_bits(((v14 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f.swap(4, 1);
        { let v = (f32::from_bits(((v13 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[1] = f[1] + f[4];
        f.swap(3, 0);
        { let v = (f32::from_bits(((v13 >> 0) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[1] = f[1] + f[3];
        { let v: u64 = f[2].to_bits(); s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        { let v: u64 = f[1].to_bits(); s2007 = (s2007 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2008 = (s2008 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        { let v: u64 = f[0].to_bits(); s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2007 >> 48) | (s2008 << 16)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits((((v20 >> 32) | (v21 << 32)) & u64::MAX)); f[0] = f[0] - v; }
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits(v30); f[0] = f[0] - v; }
        f[1] = f64::from_bits(0x3ff0000000000000);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(5) { break 'b4; }
        // block 3
        f[0] = f[0];
        f[0] = f64::from_bits((((s2007 >> 48) | (s2008 << 16)) & u64::MAX));
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2007 = (s2007 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2008 = (s2008 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        { let v = f64::from_bits(v38); f[0] = f[0] * v; }
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        { let v = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX)); f[0] = f[0] + v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v: u64 = f[0].to_bits(); s2010 = (s2010 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2011 = (s2011 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        { let v = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX)); f[0] = f[0] - v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits((((s2010 >> 48) | (s2011 << 16)) & u64::MAX)); f[0] = f[0] + v; }
        { let v = f64::from_bits(v35); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v: u64 = f[0].to_bits(); s2011 = (s2011 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2012 = (s2012 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = -f[0];
        f[1] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        f[1] = f[1] + f[1];
        f[2] = f64::from_bits(0x3ff0000000000000);
        f[1] = f[1] + f[2];
        { let x = m.round_int(f[1]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[1] = f[1] - v; }
        f[2] = f[1];
        f[2] = f[2] * f[2];
        f[2] = f[2] * f[2];
        f[1] = f[1] * f[2];
        { let v = f64::from_bits(v32); f[1] = f[1] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[1] = f[1] + v; }
        { let v = f64::from_bits((((s2010 >> 48) | (s2011 << 16)) & u64::MAX)); f[1] = f[1] + v; }
        { let v = f64::from_bits(v35); f[1] = f[1] * v; }
        { let x = m.round_int(f[1]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; { let v: u64 = i as u64; s2009 = (s2009 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2010 = (s2010 & !0xffffu64) | ((v >> 16) & 0xffffu64); } }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[1] = f[1] - v; }
        f[2] = f[1];
        f[2] = f[2] * f[2];
        f[2] = f[2] * f[2];
        f[1] = f[1] * f[2];
        { let v = f64::from_bits(v32); f[1] = f[1] * v; }
        { let v = ((((s2009 >> 48) | (s2010 << 16)) & 0xffffffffu64) as u32 as i32 as f64); f[1] = f[1] + v; }
        f[0] = f[0] + f[1];
        { let v: u64 = f[0].to_bits(); s2012 = (s2012 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2013 = (s2013 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[1] = f64::from_bits((((s2011 >> 48) | (s2012 << 16)) & u64::MAX));
        { let v = f64::from_bits(v36); f[1] = f[1] * v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[1] = f[1] * v; }
        { let v: u64 = f[1].to_bits(); s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[1] = f64::from_bits((((s2011 >> 48) | (s2012 << 16)) & u64::MAX));
        { let v = f64::from_bits(v34); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        { let v = f64::from_bits(v37); f[0] = f[0] * v; }
        { let v = f64::from_bits((((v21 >> 32) | (v22 << 32)) & u64::MAX)); f[0] = f[0] * v; }
        { let v: u64 = f[0].to_bits(); s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        f[1] = f64::from_bits((((s2007 >> 48) | (s2008 << 16)) & u64::MAX));
        f[2] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        f[3] = f[2];
        { let v = (f32::from_bits(((v19 >> 0) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[4] = f[1];
        { let v = (f32::from_bits(((v17 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[0];
        { let v = (f32::from_bits(((v16 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[2];
        { let v = (f32::from_bits(((v20 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[5] = f[1];
        { let v = (f32::from_bits(((v18 >> 32) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f[5] = f[0];
        { let v = (f32::from_bits(((v17 >> 0) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f.swap(4, 2);
        { let v = (f32::from_bits(((v19 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f.swap(4, 1);
        { let v = (f32::from_bits(((v18 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[1] = f[1] + f[4];
        f.swap(3, 0);
        { let v = (f32::from_bits(((v16 >> 32) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[1] = f[1] + f[3];
        { let v: u64 = f[2].to_bits(); s2006 = (s2006 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2007 = (s2007 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        { let v: u64 = f[1].to_bits(); s2007 = (s2007 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2008 = (s2008 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        { let v: u64 = f[0].to_bits(); s2008 = (s2008 & !(0xffffu64 << 48)) | ((v & 0xffffu64) << 48); s2009 = (s2009 & !0xffffffffffffu64) | ((v >> 16) & 0xffffffffffffu64); }
        f[0] = f64::from_bits((((s2006 >> 48) | (s2007 << 16)) & u64::MAX));
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2007 >> 48) | (s2008 << 16)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits((((v20 >> 32) | (v21 << 32)) & u64::MAX)); f[0] = f[0] - v; }
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2008 >> 48) | (s2009 << 16)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits(v30); f[0] = f[0] - v; }
        } // 'b4
        // block 4
        rg[2] = ((v23 >> 32) & 0xffffffffu64) as u32;
        { let bv = 0x1u32; let av = rg[2]; let r = fl.alu(Alu::And, av, bv, 4); rg[2] = r; }
        if fl.cond(5) { break 'b6; }
        // block 5
        { let v = f64::from_bits(v28); f[0] = f[0] / v; }
        } // 'b6
        // block 6
        r14 = f[0].to_bits();
        f[0] = f64::from_bits((((v10 >> 32) | (v11 << 32)) & u64::MAX));
        r34 = f[0].to_bits();
        { let bv = 0x46u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10001070u32, r14);
    m.wr64u(0x10001100u32, r32);
    m.wr64u(0x10001110u32, r34);
    m.wr64u(0x10007eb0u32, s2006);
    m.wr64u(0x10007eb8u32, s2007);
    m.wr64u(0x10007ec0u32, s2008);
    m.wr64u(0x10007ec8u32, s2009);
    m.wr64u(0x10007ed0u32, s2010);
    m.wr64u(0x10007ed8u32, s2011);
    m.wr64u(0x10007ee0u32, s2012);
    m.wr64u(0x10007ee8u32, s2013);
    m.regs = rg;
    m.fl = fl;
    m.fsw_cc = fsw;
    m.st = f;
    Ok(())
}

// JosKn-ModIFS

pub(super) fn f_bbefa3d716fd8355(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let mut steps = m.steps;
    let limit = steps + max_steps;
    let res = (|| -> R<()> {
    let mut b: u32 = 0;
    loop {
        match b {
            0 => {
                { let v = rg[5]; push_lu(m, &mut rg, v); }
                { let v = rg[3]; push_lu(m, &mut rg, v); }
                { let bv = 0x104u32; let av = rg[4]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[4] = r; }
                f[0] = f64::from_bits(0x3ff0000000000000);
                f[1] = f[0];
                { let a = rg[4].wrapping_add(0x18u32); m.wrf64u(a, f[1]); }
                f[1] = m.rdf64u(rg[6].wrapping_add(0xffffff88u32));
                f[2] = f[1];
                { let a = rg[4].wrapping_add(0x0u32); m.wrf64u(a, f[2]); }
                f[2] = m.rdf64u(rg[6].wrapping_add(0xffffff90u32));
                f[3] = f[2];
                f[4] = m.rdf64u(rg[6].wrapping_add(0xffffff98u32));
                f[5] = f[4];
                f[6] = f[4];
                f[7] = f[1];
                f[7] = f[7] + f[0];
                { let a = rg[4].wrapping_add(0x50u32); m.wrf64u(a, f[7]); }
                f[7] = f[3];
                f[7] = f[7] + f[0];
                { let a = rg[4].wrapping_add(0x30u32); m.wrf64u(a, f[7]); }
                f[7] = f[4];
                f[7] = f[7] + f[0];
                { let a = rg[4].wrapping_add(0x58u32); m.wrf64u(a, f[7]); }
                f[7] = f[1];
                f[7] = f[7] - f[0];
                { let a = rg[4].wrapping_add(0x38u32); m.wrf64u(a, f[7]); }
                f[7] = f[3];
                f[7] = f[7] - f[0];
                { let a = rg[4].wrapping_add(0x40u32); m.wrf64u(a, f[7]); }
                f.swap(6, 0);
                f[4] = f[4] - f[6];
                f.swap(5, 4);
                { let a = rg[4].wrapping_add(0x48u32); m.wrf64u(a, f[5]); }
                f[5] = m.rdf64u(rg[7].wrapping_add(0x0u32));
                { let a = rg[4].wrapping_add(0xb0u32); m.wrf64u(a, f[5]); }
                rg[0] = m.rd32u(rg[7].wrapping_add(0xffffffc4u32));
                { let a = rg[4].wrapping_add(0xf8u32); m.wr32u(a, rg[0]); }
                rg[5] = m.rd32u(rg[4].wrapping_add(0xf8u32));
                rg[0] = m.rd32u(rg[7].wrapping_add(0xffffffc0u32));
                { let a = rg[4].wrapping_add(0xf8u32); m.wr32u(a, rg[0]); }
                rg[3] = m.rd32u(rg[4].wrapping_add(0xf8u32));
                rg[0] = m.rd32u(rg[7].wrapping_add(0xffffffbcu32));
                { let a = rg[4].wrapping_add(0xf8u32); m.wr32u(a, rg[0]); }
                if let Op::Gen(ins, nx, at) = &p.ops[43] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Movzx { reg: 0, src: Mem(Mem { base: Some(4), index: None, disp: 248 }), size: 1 }
                { let bv = 0x4u32; let av = reg_get(&rg, 0, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 0, 1, r); }
                { let v = reg_get(&rg, 0, 1); { let a = rg[4].wrapping_add(0xbeu32); m.wr8u(a, v as u8); } }
                rg[0] = m.rd32u(rg[7].wrapping_add(0xffffffbcu32));
                { let a = rg[4].wrapping_add(0xf8u32); m.wr32u(a, rg[0]); }
                if let Op::Gen(ins, nx, at) = &p.ops[48] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Movzx { reg: 0, src: Mem(Mem { base: Some(4), index: None, disp: 248 }), size: 1 }
                { let bv = 0x1u32; let av = reg_get(&rg, 0, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 0, 1, r); }
                { let v = reg_get(&rg, 0, 1); { let a = rg[4].wrapping_add(0x97u32); m.wr8u(a, v as u8); } }
                rg[0] = m.rd32u(rg[7].wrapping_add(0xffffffbcu32));
                { let a = rg[4].wrapping_add(0xf8u32); m.wr32u(a, rg[0]); }
                if let Op::Gen(ins, nx, at) = &p.ops[53] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Movzx { reg: 0, src: Mem(Mem { base: Some(4), index: None, disp: 248 }), size: 1 }
                { let bv = 0x2u32; let av = reg_get(&rg, 0, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 0, 1, r); }
                { let v = reg_get(&rg, 0, 1); { let a = rg[4].wrapping_add(0xbfu32); m.wr8u(a, v as u8); } }
                rg[0] = m.rd32u(rg[7].wrapping_add(0xffffffbcu32));
                { let a = rg[4].wrapping_add(0xf8u32); m.wr32u(a, rg[0]); }
                if let Op::Gen(ins, nx, at) = &p.ops[58] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Movzx { reg: 0, src: Mem(Mem { base: Some(4), index: None, disp: 248 }), size: 1 }
                { let bv = 0x8u32; let av = reg_get(&rg, 0, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 0, 1, r); }
                { let v = reg_get(&rg, 0, 1); { let a = rg[4].wrapping_add(0xb8u32); m.wr8u(a, v as u8); } }
                rg[0] = m.rd32u(rg[7].wrapping_add(0xffffffbcu32));
                { let a = rg[4].wrapping_add(0xf8u32); m.wr32u(a, rg[0]); }
                if let Op::Gen(ins, nx, at) = &p.ops[63] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Movzx { reg: 0, src: Mem(Mem { base: Some(4), index: None, disp: 248 }), size: 1 }
                { let bv = 0x10u32; let av = reg_get(&rg, 0, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 0, 1, r); }
                { let v = reg_get(&rg, 0, 1); { let a = rg[4].wrapping_add(0xb9u32); m.wr8u(a, v as u8); } }
                rg[0] = m.rd32u(rg[7].wrapping_add(0xffffffbcu32));
                { let a = rg[4].wrapping_add(0xf8u32); m.wr32u(a, rg[0]); }
                if let Op::Gen(ins, nx, at) = &p.ops[68] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Movzx { reg: 0, src: Mem(Mem { base: Some(4), index: None, disp: 248 }), size: 1 }
                { let bv = 0x20u32; let av = reg_get(&rg, 0, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 0, 1, r); }
                { let v = reg_get(&rg, 0, 1); { let a = rg[4].wrapping_add(0xbau32); m.wr8u(a, v as u8); } }
                rg[0] = m.rd32u(rg[7].wrapping_add(0xffffffbcu32));
                { let a = rg[4].wrapping_add(0xf8u32); m.wr32u(a, rg[0]); }
                if let Op::Gen(ins, nx, at) = &p.ops[73] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Movzx { reg: 0, src: Mem(Mem { base: Some(4), index: None, disp: 248 }), size: 1 }
                { let bv = 0x40u32; let av = reg_get(&rg, 0, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 0, 1, r); }
                { let v = reg_get(&rg, 0, 1); { let a = rg[4].wrapping_add(0xbbu32); m.wr8u(a, v as u8); } }
                rg[0] = m.rd32u(rg[7].wrapping_add(0xffffffbcu32));
                { let a = rg[4].wrapping_add(0xf8u32); m.wr32u(a, rg[0]); }
                if let Op::Gen(ins, nx, at) = &p.ops[78] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Movzx { reg: 1, src: Mem(Mem { base: Some(4), index: None, disp: 248 }), size: 1 }
                rg[0] = m.rd32u(rg[7].wrapping_add(0xffffffbcu32));
                { let a = rg[4].wrapping_add(0xf8u32); m.wr32u(a, rg[0]); }
                rg[0] = m.rd32u(rg[4].wrapping_add(0xf8u32));
                shift_reg_l(&mut rg, &mut fl, Shift::Sar, 0, 8, 4);
                { let bv = 0x1u32; let av = reg_get(&rg, 0, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 0, 1, r); }
                { let v = reg_get(&rg, 0, 1); { let a = rg[4].wrapping_add(0xbcu32); m.wr8u(a, v as u8); } }
                f[5] = m.rdf64u(rg[7].wrapping_add(0xffffff9cu32));
                f[5] = f[5].abs();
                f[6] = m.rdf64u(rg[7].wrapping_add(0x18u32));
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[88], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FComi { a: 6, b: 5 }
                f[5] = f[5];
                if let Op::Gen(ins, nx, at) = &p.ops[90] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Setcc { cc: 7, dst: Reg(2) }
                f[5] = m.rdf64u(rg[7].wrapping_add(0xffffffe0u32));
                f[6] = f[5];
                { let a = rg[4].wrapping_add(0x20u32); m.wrf64u(a, f[6]); }
                f[6] = m.rdf64u(rg[7].wrapping_add(0xffffffd8u32));
                f[7] = f[6];
                { let a = rg[4].wrapping_add(0x28u32); m.wrf64u(a, f[7]); }
                f[7] = m.rdf64u(rg[7].wrapping_add(0x28u32));
                f[5] = f[5] * f[7];
                f.swap(6, 5);
                { let a = rg[4].wrapping_add(0x98u32); m.wrf64u(a, f[6]); }
                f[6] = m.rdf64u(rg[7].wrapping_add(0x28u32));
                f[5] = f[5] * f[6];
                { let a = rg[4].wrapping_add(0xa0u32); m.wrf64u(a, f[5]); }
                { let bv = 0x64u32; let av = rg[5]; let r = fl.alu(Alu::Cmp, av, bv, 4); }
                { let v = 0x64u32; rg[0] = v; }
                if let Op::Gen(ins, nx, at) = &p.ops[106] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Cmovcc { cc: 15, reg: 5, src: Reg(0) }
                { let bv = 0x14u32; let av = rg[3]; let r = fl.alu(Alu::Cmp, av, bv, 4); }
                { let v = 0x14u32; rg[0] = v; }
                if let Op::Gen(ins, nx, at) = &p.ops[109] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Cmovcc { cc: 14, reg: 0, src: Reg(3) }
                { let a = rg[4].wrapping_add(0xc4u32); m.wr32u(a, rg[0]); }
                f[5] = m.rdf64u(rg[7].wrapping_add(0xfffffff0u32));
                { let a = rg[4].wrapping_add(0x8u32); m.wrf64u(a, f[5]); }
                f[5] = m.rdf64u(rg[7].wrapping_add(0xffffffe8u32));
                f[6] = f[5];
                { let a = rg[4].wrapping_add(0x60u32); m.wrf64u(a, f[6]); }
                f[6] = m.rdf64u(rg[7].wrapping_add(0xffffff94u32));
                { let a = rg[4].wrapping_add(0x10u32); m.wrf64u(a, f[6]); }
                f.swap(6, 5);
                
                if let Op::Gen(ins, nx, at) = &p.ops[120] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // FnstcwMem(Mem { base: Some(4), index: None, disp: 248 })
                { let v = (m.rd16u(rg[4].wrapping_add(0xf8u32)) as u32); reg_set(&mut rg, 0, 2, v); }
                { let bv = 0xf3u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
                { let bv = 0x4u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::Or, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
                { let v = reg_get(&rg, 0, 2); { let a = rg[4].wrapping_add(0xf0u32); m.wr16u(a, v as u16); } }
                if let Op::Gen(ins, nx, at) = &p.ops[125] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // FldcwMem(Mem { base: Some(4), index: None, disp: 240 })
                if let Op::Gen(ins, nx, at) = &p.ops[126] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Movzx { reg: 0, src: Mem(Mem { base: Some(4), index: None, disp: 248 }), size: 2 }
                { let a = rg[4].wrapping_add(0xc0u32); m.wr32u(a, rg[0]); }
                f[6] = f[6] * f[6];
                f.swap(6, 5);
                f[6] = f[6] * f[6];
                f[5] = f[5] + f[6];
                f[5] = f[5].sqrt();
                f[6] = f[5];
                { let a = rg[4].wrapping_add(0x88u32); m.wrf64u(a, f[6]); }
                f[6] = m.rdf64u(rg[7].wrapping_add(0x48u32));
                f.swap(6, 5);
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[137], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FComi { a: 6, b: 5 }
                f[5] = f[6];
                if fl.cond(6) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 2; continue; }
                b = 1;
            }
            1 => {
                f[6] = f64::from_bits(0x3ff0000000000000);
                f[5] = f[6] / f[5];
                { let a = rg[4].wrapping_add(0x88u32); m.wrf64u(a, f[5]); }
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 3; continue;
            }
            2 => {
                f[5] = f[5];
                b = 3;
            }
            3 => {
                { let bv = 0x0u32; let av = (m.rd8u(rg[4].wrapping_add(0xbeu32)) as u32); let r = fl.alu(Alu::Cmp, av, bv, 1); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 8; continue; }
                b = 4;
            }
            4 => {
                f[0] = f[4];
                f[2] = f[3];
                f.swap(2, 1);
                f.swap(2, 0);
                f[3] = m.rdf64u(rg[7].wrapping_add(0xffffffb4u32));
                f[0] = f[0] - f[3];
                f[3] = m.rdf64u(rg[7].wrapping_add(0xffffffacu32));
                f[1] = f[1] - f[3];
                f[3] = m.rdf64u(rg[7].wrapping_add(0xffffffa4u32));
                f[2] = f[2] - f[3];
                { let bv = reg_get(&rg, 2, 1); let av = reg_get(&rg, 2, 1); fl.alu(Alu::And, av, bv, 1); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 6; continue; }
                b = 5;
            }
            5 => {
                f[3] = f64::from_bits(0x3ff0000000000000);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 7; continue;
            }
            6 => {
                f[3] = m.rdf64u(rg[7].wrapping_add(0xffffff9cu32));
                b = 7;
            }
            7 => {
                f[3] = f[3] * f[3];
                f[4] = f[0];
                f[4] = f[4] * f[0];
                f[5] = f[1];
                f[5] = f[5] * f[1];
                f[4] = f[4] + f[5];
                f[5] = f[2];
                f[5] = f[5] * f[2];
                f[4] = f[4] + f[5];
                f[5] = f[4];
                { let a = rg[4].wrapping_add(0xc8u32); m.wrf64u(a, f[5]); }
                f[3] = f[3] / f[4];
                f[0] = f[0] * f[3];
                f[4] = m.rdf64u(rg[7].wrapping_add(0xffffffb4u32));
                f[0] = f[0] + f[4];
                f.swap(3, 0);
                { let a = rg[4].wrapping_add(0x0u32); m.wrf64u(a, f[3]); }
                f[3] = m.rdf64u(rg[7].wrapping_add(0xffffffacu32));
                f.swap(3, 1);
                f[3] = f[3] * f[0];
                f[1] = f[1] + f[3];
                f[0] = f[0] * f[2];
                f[2] = m.rdf64u(rg[7].wrapping_add(0xffffffa4u32));
                f[0] = f[0] + f[2];
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 9; continue;
            }
            8 => {
                f[4] = f[4];
                f[3] = f[3];
                f[1] = f[2];
                b = 9;
            }
            9 => {
                { let bv = rg[5]; let av = rg[5]; fl.alu(Alu::And, av, bv, 4); }
                if fl.cond(14) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 41; continue; }
                b = 10;
            }
            10 => {
                { let v = 0x0u32; rg[3] = v; }
                f[2] = m.rdf64u(rg[4].wrapping_add(0x8u32));
                f[2] = -f[2];
                { let a = rg[4].wrapping_add(0xa8u32); m.wrf64u(a, f[2]); }
                f[2] = m.rdf64u(rg[4].wrapping_add(0x60u32));
                f[2] = -f[2];
                { let a = rg[4].wrapping_add(0x80u32); m.wrf64u(a, f[2]); }
                { let v = reg_get(&rg, 1, 1); { let a = rg[4].wrapping_add(0xbdu32); m.wr8u(a, v as u8); } }
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 12; continue;
            }
            11 => {
                { let a = rg[4].wrapping_add(0x58u32); m.wrf64u(a, f[1]); }
                f.swap(1, 0);
                { let a = rg[4].wrapping_add(0x30u32); m.wrf64u(a, f[1]); }
                f[2] = m.rdf64u(rg[4].wrapping_add(0x0u32));
                { let a = rg[4].wrapping_add(0x50u32); m.wrf64u(a, f[2]); }
                b = 12;
            }
            12 => {
                { let bv = 0x0u32; let av = (m.rd8u(rg[4].wrapping_add(0xbau32)) as u32); let r = fl.alu(Alu::Cmp, av, bv, 1); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 14; continue; }
                b = 13;
            }
            13 => {
                f[2] = m.rdf64u(rg[7].wrapping_add(0x10u32));
                f[3] = m.rdf64u(rg[4].wrapping_add(0x20u32));
                f[2] = f[2] * f[3];
                f.swap(3, 2);
                { let v = m.rdf64u(rg[4].wrapping_add(0x0u32)); f[3] = f[3] + v; }
                f[3] = f[3].abs();
                f[4] = m.rdf64u(rg[7].wrapping_add(0x10u32));
                f[2] = f[2] * f[4];
                f[2] = f[2] + f[3];
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 15; continue;
            }
            14 => {
                f[2] = m.rdf64u(rg[4].wrapping_add(0x0u32));
                { let v = m.rdf64u(rg[4].wrapping_add(0x20u32)); f[2] = f[2] + v; }
                b = 15;
            }
            15 => {
                { let bv = 0x0u32; let av = (m.rd8u(rg[4].wrapping_add(0xbbu32)) as u32); let r = fl.alu(Alu::Cmp, av, bv, 1); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 17; continue; }
                b = 16;
            }
            16 => {
                f[3] = m.rdf64u(rg[7].wrapping_add(0x10u32));
                f[4] = m.rdf64u(rg[4].wrapping_add(0x28u32));
                f[3] = f[3] * f[4];
                f.swap(4, 3);
                f[0] = f[0] + f[4];
                f.swap(3, 0);
                f[3] = f[3].abs();
                f[4] = m.rdf64u(rg[7].wrapping_add(0x10u32));
                f[0] = f[0] * f[4];
                f[0] = f[0] + f[3];
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 18; continue;
            }
            17 => {
                f.swap(2, 0);
                { let v = m.rdf64u(rg[4].wrapping_add(0x28u32)); f[2] = f[2] + v; }
                f.swap(2, 0);
                b = 18;
            }
            18 => {
                f[3] = m.rdf64u(rg[4].wrapping_add(0x98u32));
                f[4] = f[3];
                f[4] = f[2] / f[4];
                { let a = rg[4].wrapping_add(0xd8u32); m.wrf64u(a, f[4]); }
                f[4] = m.rdf64u(rg[4].wrapping_add(0xd8u32));
                { let a = rg[4].wrapping_add(0xf8u32); m.fstoreu(FKind::I32, a, f[4]); }
                rg[0] = m.rd32u(rg[4].wrapping_add(0xf8u32));
                { let a = rg[4].wrapping_add(0x0u32); m.wr32u(a, rg[0]); }
                f[4] = m.floadu(FKind::I32, rg[4].wrapping_add(0x0u32));
                f[3] = f[3] * f[4];
                { let v = m.rdf64u(rg[4].wrapping_add(0x20u32)); f[3] = f[3] + v; }
                f[2] = f[2] - f[3];
                f[3] = m.rdf64u(rg[4].wrapping_add(0xa0u32));
                f[4] = f[3];
                f[4] = f[0] / f[4];
                { let a = rg[4].wrapping_add(0xe0u32); m.wrf64u(a, f[4]); }
                f[4] = m.rdf64u(rg[4].wrapping_add(0xe0u32));
                { let a = rg[4].wrapping_add(0xf8u32); m.fstoreu(FKind::I32, a, f[4]); }
                rg[1] = m.rd32u(rg[4].wrapping_add(0xf8u32));
                { let a = rg[4].wrapping_add(0x0u32); m.wr32u(a, rg[1]); }
                f[4] = m.floadu(FKind::I32, rg[4].wrapping_add(0x0u32));
                f[3] = f[3] * f[4];
                { let v = m.rdf64u(rg[4].wrapping_add(0x28u32)); f[3] = f[3] + v; }
                f[0] = f[0] - f[3];
                { let bv = 0x0u32; let av = (m.rd8u(rg[4].wrapping_add(0x97u32)) as u32); let r = fl.alu(Alu::Cmp, av, bv, 1); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 20; continue; }
                b = 19;
            }
            19 => {
                f[3] = m.rdf64u(rg[4].wrapping_add(0x8u32));
                f[3] = f[1] / f[3];
                { let a = rg[4].wrapping_add(0xe8u32); m.wrf64u(a, f[3]); }
                f[3] = m.rdf64u(rg[4].wrapping_add(0xe8u32));
                { let a = rg[4].wrapping_add(0xf8u32); m.fstoreu(FKind::I32, a, f[3]); }
                f[3] = m.floadu(FKind::I32, rg[4].wrapping_add(0xf8u32));
                { let v = m.rdf64u(rg[4].wrapping_add(0xa8u32)); f[3] = f[3] * v; }
                f[1] = f[1] + f[3];
                b = 20;
            }
            20 => {
                { let bv = 0x0u32; let av = (m.rd8u(rg[4].wrapping_add(0xb8u32)) as u32); let r = fl.alu(Alu::Cmp, av, bv, 1); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 22; continue; }
                b = 21;
            }
            21 => {
                { let bv = 0x1u32; let av = rg[0]; let r = fl.alu(Alu::And, av, bv, 4); rg[0] = r; }
                f[3] = f[2];
                f[3] = -f[3];
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[275], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FCmov { cc: 4, dst: 3, src: 2 }
                f[2] = f[3];
                rg[0] = rg[1];
                { let bv = 0x1u32; let av = rg[0]; let r = fl.alu(Alu::And, av, bv, 4); rg[0] = r; }
                f[3] = f[0];
                f[3] = -f[3];
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[281], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FCmov { cc: 4, dst: 3, src: 0 }
                f[0] = f[3];
                b = 22;
            }
            22 => {
                f[3] = m.rdf64u(rg[7].wrapping_add(0x10u32));
                f[4] = m.rdf64u(rg[7].wrapping_add(0x10u32));
                f[5] = m.rdf64u(rg[4].wrapping_add(0x60u32));
                f[3] = f[3] * f[5];
                f.swap(5, 3);
                f[5] = f[5] + f[2];
                f[3] = f[3] * f[5];
                f[5] = m.rdf64u(rg[4].wrapping_add(0x10u32));
                f[4] = f[4] * f[5];
                f.swap(5, 4);
                f[5] = f[5] + f[0];
                f[4] = f[4] * f[5];
                f[3] = f[3] - f[4];
                { let v = m.rdf64u(rg[4].wrapping_add(0x88u32)); f[3] = f[3] * v; }
                f[4] = f[3];
                fsw = fcompare_cc(f[4], 0.0);
                
                rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x1800) as u32;
                { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
                if fl.cond(2) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 26; continue; }
                b = 23;
            }
            23 => {
                if fl.cond(7) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 25; continue; }
                b = 24;
            }
            24 => {
                f[5] = f64::from_bits(0x0);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 27; continue;
            }
            25 => {
                f[5] = f64::from_bits(0x3ff0000000000000);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 27; continue;
            }
            26 => {
                f[5] = f64::from_bits(0x3ff0000000000000);
                f[5] = -f[5];
                b = 27;
            }
            27 => {
                f[4] = f[5];
                f[5] = f64::from_bits(0x3ff0000000000000);
                f[6] = m.rdf64u(rg[7].wrapping_add(0x20u32));
                f.swap(6, 3);
                f[6] = f[6].abs();
                f[3] = f[3] * f[6];
                f.swap(5, 3);
                f[6] = f64::from_bits(0x3ff71547652b82fe);
                f[5] = f[5] * f[6];
                f[6] = f64::from_bits(0x3ff0000000000000);
                f[7] = f[5];
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[321], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FPrem { a: 7, b: 6, ieee: false }
                f[7] = f[7].exp2() - 1.0;
                f[6] = f[6] + f[7];
                f[6] *= f[5].trunc().exp2();
                f.swap(6, 5);
                f[6] = f[6];
                f[6] = m.rdf64u(rg[7].wrapping_add(0x10u32));
                f[7] = m.rdf64u(rg[7].wrapping_add(0x18u32));
                f.swap(7, 5);
                f[3] = f[3] - f[7];
                f.swap(6, 3);
                f[4] = f[4] * f[6];
                f[4] = f[4] * f[5];
                f[3] = f[3] + f[4];
                { let v = m.rdf64u(rg[4].wrapping_add(0x8u32)); f[3] = f[3] * v; }
                { let bv = 0x0u32; let av = (m.rd8u(rg[4].wrapping_add(0xb9u32)) as u32); let r = fl.alu(Alu::Cmp, av, bv, 1); }
                if fl.cond(5) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 30; continue; }
                b = 28;
            }
            28 => {
                f.swap(3, 1);
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[339], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FComi { a: 3, b: 1 }
                f[1] = f[3];
                if fl.cond(6) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 31; continue; }
                b = 29;
            }
            29 => {
                { let v = m.rdf64u(rg[4].wrapping_add(0x80u32)); f[2] = v - f[2]; }
                f.swap(2, 1);
                { let v = m.rdf64u(rg[4].wrapping_add(0x8u32)); f[2] = v - f[2]; }
                f.swap(2, 0);
                { let v = m.rdf64u(rg[4].wrapping_add(0x10u32)); f[2] = v - f[2]; }
                f.swap(2, 0);
                f.swap(2, 1);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 31; continue;
            }
            30 => {
                f[3] = f[3] - f[1];
                f[4] = m.rdf64u(rg[7].wrapping_add(0x8u32));
                { let v = m.rdf64u(rg[4].wrapping_add(0x8u32)); f[4] = f[4] * v; }
                f[3] = f[3] - f[4];
                f[4] = f64::from_bits(0x0);
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[355], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FComi { a: 4, b: 3 }
                f[3] = f[3];
                if fl.cond(7) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 42; continue; }
                b = 31;
            }
            31 => {
                { let bv = 0x0u32; let av = (m.rd8u(rg[4].wrapping_add(0xbdu32)) as u32); let r = fl.alu(Alu::Cmp, av, bv, 1); }
                if fl.cond(9) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 33; continue; }
                b = 32;
            }
            32 => {
                f[2] = f[2].abs();
                b = 33;
            }
            33 => {
                { let bv = 0x0u32; let av = (m.rd8u(rg[4].wrapping_add(0xbcu32)) as u32); let r = fl.alu(Alu::Cmp, av, bv, 1); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 35; continue; }
                b = 34;
            }
            34 => {
                f.swap(2, 0);
                f[2] = f[2].abs();
                f.swap(2, 0);
                b = 35;
            }
            35 => {
                f[3] = f[2];
                f[3] = f[3] * f[2];
                f[4] = f[1];
                f[4] = f[4] * f[1];
                { let a = rg[4].wrapping_add(0x68u32); m.wrf64u(a, f[4]); }
                f[5] = m.rdf64u(rg[7].wrapping_add(0xffffffd0u32));
                { let a = rg[4].wrapping_add(0x70u32); m.wrf64u(a, f[5]); }
                f[5] = m.rdf64u(rg[7].wrapping_add(0xffffffc8u32));
                { let a = rg[4].wrapping_add(0x78u32); m.wrf64u(a, f[5]); }
                f[4] = f[4] + f[3];
                f[5] = f[0];
                f[5] = f[5] * f[0];
                f[4] = f[4] + f[5];
                f[5] = f64::from_bits(0x3ff0000000000000);
                f[4] = f[5] / f[4];
                f[5] = f[4];
                f[5] = -f[5];
                f[6] = f[2];
                f[6] = f[6] * f[5];
                f[7] = f[1];
                f[7] = f[7] * f[5];
                f.swap(7, 5);
                f[0] = f[0] * f[7];
                { let v = m.rdf64u(rg[4].wrapping_add(0x80u32)); f[6] = v - f[6]; }
                { let a = rg[4].wrapping_add(0x0u32); m.wrf64u(a, f[6]); }
                { let v = m.rdf64u(rg[4].wrapping_add(0x8u32)); f[5] = f[5] + v; }
                f.swap(5, 0);
                { let v = m.rdf64u(rg[4].wrapping_add(0x10u32)); f[5] = v - f[5]; }
                f.swap(5, 4);
                { let v = m.rdf64u(rg[4].wrapping_add(0x18u32)); f[5] = f[5] * v; }
                { let a = rg[4].wrapping_add(0x18u32); m.wrf64u(a, f[5]); }
                { let bv = reg_get(&rg, 2, 1); let av = reg_get(&rg, 2, 1); fl.alu(Alu::And, av, bv, 1); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 37; continue; }
                b = 36;
            }
            36 => {
                f.swap(4, 1);
                f[2] = f[2] * f[4];
                f[4] = m.rdf64u(rg[7].wrapping_add(0xffffff9cu32));
                f.swap(4, 3);
                { let v = m.rdf64u(rg[4].wrapping_add(0x68u32)); f[4] = f[4] - v; }
                { let v = m.rdf64u(rg[4].wrapping_add(0x70u32)); f[4] = f[4] + v; }
                f[3] = f[3] * f[4];
                { let v = m.rdf64u(rg[4].wrapping_add(0x0u32)); f[3] = f[3] + v; }
                { let a = rg[4].wrapping_add(0x0u32); m.wrf64u(a, f[3]); }
                f[3] = m.rdf64u(rg[7].wrapping_add(0xffffff9cu32));
                f[4] = m.rdf64u(rg[4].wrapping_add(0x78u32));
                f[4] = f[4] + f[2];
                f[2] = f[2] + f[4];
                f[2] = f[2] * f[3];
                f[0] = f[0] + f[2];
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 38; continue;
            }
            37 => {
                f[1] = f[4];
                f[3] = f[3];
                f[2] = f[2];
                b = 38;
            }
            38 => {
                f[2] = m.rdf64u(rg[4].wrapping_add(0x48u32));
                f[2] = f[1] - f[2];
                f[3] = m.rdf64u(rg[4].wrapping_add(0x40u32));
                f[3] = f[0] - f[3];
                f[4] = m.rdf64u(rg[4].wrapping_add(0x38u32));
                { let v = m.rdf64u(rg[4].wrapping_add(0x0u32)); f[4] = v - f[4]; }
                f[5] = m.rdf64u(rg[7].wrapping_add(0x48u32));
                f.swap(5, 4);
                f[5] = f[5] * f[5];
                f.swap(5, 3);
                f[5] = f[5] * f[5];
                f[3] = f[3] + f[5];
                f.swap(4, 2);
                f[4] = f[4] * f[4];
                f[3] = f[3] + f[4];
                f.swap(3, 2);
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[434], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FComi { a: 3, b: 2 }
                f[2] = f[2];
                if fl.cond(7) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 43; continue; }
                b = 39;
            }
            39 => {
                { let cf = fl.cf; let r = fl.alu(Alu::Add, rg[3], 1, 4); fl.cf = cf; rg[3] = r; }
                f[2] = m.rdf64u(rg[4].wrapping_add(0x50u32));
                { let a = rg[4].wrapping_add(0x38u32); m.wrf64u(a, f[2]); }
                f[2] = m.rdf64u(rg[4].wrapping_add(0x30u32));
                { let a = rg[4].wrapping_add(0x40u32); m.wrf64u(a, f[2]); }
                f[2] = m.rdf64u(rg[4].wrapping_add(0x58u32));
                { let a = rg[4].wrapping_add(0x48u32); m.wrf64u(a, f[2]); }
                { let bv = rg[5]; let av = rg[3]; let r = fl.alu(Alu::Cmp, av, bv, 4); }
                if fl.cond(5) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 11; continue; }
                b = 40;
            }
            40 => {
                f.swap(1, 0);
                rg[3] = rg[5];
                { let a = rg[4].wrapping_add(0x30u32); m.wrf64u(a, f[1]); }
                f.swap(1, 0);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 43; continue;
            }
            41 => {
                f.swap(1, 0);
                { let v = 0x0u32; rg[3] = v; }
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 43; continue;
            }
            42 => {
                { let a = rg[4].wrapping_add(0x0u32); m.wrf64u(a, f[2]); }
                f.swap(1, 0);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 43; continue;
            }
            43 => {
                f[2] = m.rdf64u(rg[7].wrapping_add(0xffffff8cu32));
                f[3] = m.rdf64u(rg[7].wrapping_add(0x30u32));
                { let a = rg[4].wrapping_add(0x20u32); m.wr32u(a, rg[3]); }
                f[4] = m.floadu(FKind::I32, rg[4].wrapping_add(0x20u32));
                f[4] = f[4].sqrt();
                f[5] = m.rdf64u(rg[7].wrapping_add(0x30u32));
                f.swap(5, 3);
                f[5] = f[5] - f[2];
                { let v = m.rdf64u(rg[4].wrapping_add(0x30u32)); f[5] = f[5] * v; }
                f.swap(5, 4);
                f[2] = f[2] * f[5];
                f.swap(4, 2);
                f[3] = f[3] + f[4];
                f[2] = f[2] / f[3];
                { let a = rg[4].wrapping_add(0xf0u32); m.wrf64u(a, f[2]); }
                f[2] = m.rdf64u(rg[4].wrapping_add(0xf0u32));
                { let a = rg[6].wrapping_add(0x80u32); m.wrf64u(a, f[2]); }
                f[2] = f64::from_bits(0x3ff0000000000000);
                f[3] = f64::from_bits(0x3ff0000000000000);
                { let v = 0x0u32; rg[0] = v; }
                f[4] = m.rdf64u(rg[4].wrapping_add(0x0u32));
                f.swap(4, 2);
                if let Op::Gen(ins, nx, at) = &p.ops[479] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Movzx { reg: 1, src: Mem(Mem { base: Some(4), index: None, disp: 191 }), size: 1 }
                { let a = rg[4].wrapping_add(0x0u32); m.wrf64u(a, f[4]); }
                f[4] = m.rdf64u(rg[4].wrapping_add(0xb0u32));
                f[5] = m.rdf64u(rg[4].wrapping_add(0x18u32));
                rg[3] = m.rd32u(rg[4].wrapping_add(0xc4u32));
                b = 44;
            }
            44 => {
                f[6] = f[0];
                { let bv = reg_get(&rg, 1, 1); let av = reg_get(&rg, 1, 1); fl.alu(Alu::And, av, bv, 1); }
                if fl.cond(5) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 46; continue; }
                b = 45;
            }
            45 => {
                f[6] = f[6];
                f[6] = m.rdf64u(rg[4].wrapping_add(0x8u32));
                f[6] = f[6] - f[0];
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[490], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FComi { a: 6, b: 0 }
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[491], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FCmov { cc: 7, dst: 6, src: 0 }
                b = 46;
            }
            46 => {
                f[7] = m.rdf64u(rg[4].wrapping_add(0x0u32));
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[493], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FComi { a: 7, b: 6 }
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[494], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FCmov { cc: 7, dst: 7, src: 6 }
                f[6] = f[7];
                f.swap(6, 5);
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[497], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FComi { a: 6, b: 3 }
                f[7] = f[3];
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[499], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FCmov { cc: 7, dst: 7, src: 6 }
                f[5] = f[5] / f[7];
                f.swap(6, 5);
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[502], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FComi { a: 6, b: 4 }
                { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec_op(&p.ops[503], &mut f); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } // FCmov { cc: 7, dst: 6, src: 4 }
                f[4] = f[6];
                { let bv = rg[3]; let av = rg[0]; let r = fl.alu(Alu::Cmp, av, bv, 4); }
                if fl.cond(13) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 48; continue; }
                b = 47;
            }
            47 => {
                f.swap(5, 2);
                { let v = m.rdf64u(rg[4].wrapping_add(0x60u32)); f[5] = f[5] + v; }
                f.swap(5, 0);
                { let v = m.rdf64u(rg[4].wrapping_add(0x8u32)); f[5] = v - f[5]; }
                f.swap(5, 1);
                { let v = m.rdf64u(rg[4].wrapping_add(0x10u32)); f[5] = f[5] - v; }
                f[6] = f[0];
                f[6] = f[6] * f[0];
                f[7] = f[1];
                f[7] = f[7] * f[1];
                f[6] = f[6] + f[7];
                f[7] = f[5];
                f[7] = f[7] * f[5];
                f[6] = f[6] + f[7];
                f[7] = f64::from_bits(0x3ff0000000000000);
                f[6] = f[7] / f[6];
                f[0] = f[0] * f[6];
                f[1] = f[1] * f[6];
                f[5] = f[5] * f[6];
                f[2] = f[2] * f[6];
                f.swap(5, 1);
                f.swap(5, 0);
                f.swap(5, 2);
                { let cf = fl.cf; let r = fl.alu(Alu::Add, rg[0], 1, 4); fl.cf = cf; rg[0] = r; }
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 44; continue;
            }
            48 => {
                f[5] = f[5];
                f[1] = f[4];
                f[3] = f[3];
                f[2] = f[2];
                f[0] = f[1];
                { let a = rg[4].wrapping_add(0xb0u32); m.wrf64u(a, f[0]); }
                { let bv = 0x0u32; let av = (m.rd8u(rg[4].wrapping_add(0xbeu32)) as u32); let r = fl.alu(Alu::Cmp, av, bv, 1); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 53; continue; }
                b = 49;
            }
            49 => {
                { let bv = reg_get(&rg, 2, 1); let av = reg_get(&rg, 2, 1); fl.alu(Alu::And, av, bv, 1); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 51; continue; }
                b = 50;
            }
            50 => {
                f[1] = f64::from_bits(0x3ff0000000000000);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 52; continue;
            }
            51 => {
                f[1] = m.rdf64u(rg[7].wrapping_add(0xffffff9cu32));
                b = 52;
            }
            52 => {
                f[2] = m.rdf64u(rg[4].wrapping_add(0xc8u32));
                f[3] = f[2];
                f[3] = f[3] * f[0];
                f.swap(3, 2);
                f[3] = f[3].sqrt();
                f[0] = f[0] * f[3];
                f.swap(2, 0);
                f[1] = f[1] + f[2];
                f[0] = f[0] / f[1];
                { let a = rg[4].wrapping_add(0xb0u32); m.wrf64u(a, f[0]); }
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 54; continue;
            }
            53 => {
                f[0] = f[0];
                b = 54;
            }
            54 => {
                rg[0] = m.rd32u(rg[4].wrapping_add(0xc0u32));
                { let v = reg_get(&rg, 0, 2); { let a = rg[4].wrapping_add(0xd6u32); m.wr16u(a, v as u16); } }
                if let Op::Gen(ins, nx, at) = &p.ops[559] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // FldcwMem(Mem { base: Some(4), index: None, disp: 214 })
                f[0] = m.rdf64u(rg[4].wrapping_add(0xb0u32));
                { let a = rg[4].wrapping_add(0xf8u32); m.wrf64u(a, f[0]); }
                f[0] = m.rdf64u(rg[4].wrapping_add(0xf8u32));
                { let a = rg[6].wrapping_add(0xffffffe0u32); m.wrf64u(a, f[0]); }
                { let bv = 0x104u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
                { let v = pop_lu(m, &mut rg); rg[3] = v; }
                { let v = pop_lu(m, &mut rg); rg[5] = v; }
                let r = pop_lu(m, &mut rg); rg[ESP] = rg[ESP].wrapping_add(0);                              if r != RETURN_SENTINEL { match p.rets.iter().find(|e| e.0 == r).map(|e| e.1) { _ => return Err(unsup(r, "bad return".into())) } }                              m.st = f; return Ok(());
            }
            _ => return Err(unsup(0, "bad block".into())),
        }
    }
    })();
    // after an error the machine state does not matter (the caller drops
    // the result, the next call starts with fresh registers); writing it
    // back only on success keeps the locals dead on the error paths
    if res.is_ok() {
        m.regs = rg;
        m.fl = fl;
        m.fsw_cc = fsw;
        m.steps = steps;
    }
    res
}

// _T_Scale3D

pub(super) fn f_bdee0a1f4f1c566e(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let vb = pvar.wrapping_sub(256);
    let vm = m.bytes_at::<24>(vb.wrapping_add(224))?;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    let mut v28: u64 = cell(vm, 0);
    let mut v29: u64 = cell(vm, 8);
    let mut v30: u64 = cell(vm, 16);
    'body: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 32)) | (((rg[6] as u64) & 0xffffffffu64) << 32); }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 0)) | (((rg[7] as u64) & 0xffffffffu64) << 0); }
        rg[6] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[7] = ((r13 >> 0) & 0xffffffffu64) as u32;
        f[0] = f64::from_bits(r3);
        { let v = f64::from_bits(v30); f[0] = f[0] * v; }
        r3 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        { let v = f64::from_bits(v29); f[0] = f[0] * v; }
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        { let v = f64::from_bits(v28); f[0] = f[0] * v; }
        r5 = f[0].to_bits();
        { rg[7] = ((s2013 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[6] = ((s2013 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[5] = ((s2014 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 3, r3);
    rec_set(m, it, 4, r4);
    rec_set(m, it, 5, r5);
    m.wr64u(0x10007ee8u32, s2013);
    m.wr64u(0x10007ef0u32, s2014);
    Ok(())
}

// murl

pub(super) fn f_cc0171a0c630040b(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<88>(vb.wrapping_add(184))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut r32: u64 = m.rd64u(0x10001100u32);
    let mut s2000: u64 = m.rd64u(0x10007e80u32);
    let mut s2001: u64 = m.rd64u(0x10007e88u32);
    let mut s2002: u64 = m.rd64u(0x10007e90u32);
    let mut s2003: u64 = m.rd64u(0x10007e98u32);
    let mut s2004: u64 = m.rd64u(0x10007ea0u32);
    let mut s2005: u64 = m.rd64u(0x10007ea8u32);
    let mut s2006: u64 = m.rd64u(0x10007eb0u32);
    let mut s2007: u64 = m.rd64u(0x10007eb8u32);
    let mut s2008: u64 = m.rd64u(0x10007ec0u32);
    let mut s2009: u64 = m.rd64u(0x10007ec8u32);
    let mut s2010: u64 = m.rd64u(0x10007ed0u32);
    let mut s2011: u64 = m.rd64u(0x10007ed8u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    let mut v23: u64 = cell(vm, 0);
    let mut v24: u64 = cell(vm, 8);
    let mut v25: u64 = cell(vm, 16);
    let mut v26: u64 = cell(vm, 24);
    let mut v27: u64 = cell(vm, 32);
    let mut v28: u64 = cell(vm, 40);
    let mut v29: u64 = cell(vm, 48);
    let mut v30: u64 = cell(vm, 56);
    let mut v32: u64 = cell(vm, 72);
    let mut v33: u64 = cell(vm, 80);
    'body: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2015 = (s2015 & !(0xffffffffu64 << 0)) | (((rg[7] as u64) & 0xffffffffu64) << 0); }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 32)) | (((rg[6] as u64) & 0xffffffffu64) << 32); }
        { let bv = 0x74u32; let av = rg[4]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[4] = r; }
        f[0] = f64::from_bits(r3);
        s2001 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        s2002 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        s2003 = f[0].to_bits();
        f[0] = f64::from_bits(v26);
        f[1] = f64::from_bits(v25);
        f[2] = f64::from_bits(v28);
        f.swap(2, 0);
        { let v = f64::from_bits(s2001); f[2] = v - f[2]; }
        f[0] = f[0] * f[2];
        f[2] = f[0];
        f[3] = f64::from_bits(v28);
        f.swap(3, 1);
        { let v = f64::from_bits(s2002); f[3] = v - f[3]; }
        f[1] = f[1] * f[3];
        f[3] = f64::from_bits(v29);
        { let v = f64::from_bits(s2003); f[3] = f[3] * v; }
        s2004 = f[3].to_bits();
        f[3] = f64::from_bits(v30);
        f[4] = f64::from_bits(v32);
        f[5] = f[0];
        f[5] = f[5] * f[0];
        f[6] = f[1];
        f[6] = f[6] * f[1];
        f[5] = f[5] + f[6];
        f[6] = f64::from_bits(0x3fe62e42fefa39ef);
        f.swap(6, 5);
        f[5] *= f[6].log2();
        f.swap(5, 3);
        f[4] = f[4] * f[5];
        f[3] = f[3] * f[4];
        f[4] = f64::from_bits(0x3ff71547652b82fe);
        f[3] = f[3] * f[4];
        f[4] = f64::from_bits(0x3ff0000000000000);
        f[5] = f[3];
        { let (x, y) = (f[5], f[4]); let q = if false { (x / y).round_ties_even() } else { (x / y).trunc() }; f[5] = if false { x - q * y } else { x % y }; let qi = q.abs() as u64; fsw = (if qi & 4 != 0 { 0x0100 } else { 0 }) | (if qi & 2 != 0 { 0x4000 } else { 0 }) | (if qi & 1 != 0 { 0x0200 } else { 0 }); }
        f[5] = f[5].exp2() - 1.0;
        f[4] = f[4] + f[5];
        f[4] *= f[3].trunc().exp2();
        f.swap(4, 3);
        f[4] = f[4];
        f.swap(3, 1);
        s2000 = f[3].to_bits();
        f.swap(3, 2);
        f.swap(3, 0);
        f[2] = f[2].atan2(f[3]);
        f[3] = f64::from_bits(v30);
        f[2] = f[2] * f[3];
        s2006 = f[2].to_bits();
        f[2] = f64::from_bits(s2006);
        { let (s, c) = f[2].sin_cos(); f[2] = s; f[3] = c; fsw &= !0x0400; }
        s2012 = f[3].to_bits();
        s2013 = f[2].to_bits();
        f[2] = f[1];
        { let v = f64::from_bits(s2013); f[2] = f[2] * v; }
        f.swap(2, 1);
        { let v = f64::from_bits(s2012); f[2] = f[2] * v; }
        f[3] = f64::from_bits(0x3ff0000000000000);
        f[2] = f[2] + f[3];
        f[3] = f64::from_bits(v29);
        f[4] = f64::from_bits(v32);
        f[5] = f[2];
        f[5] = f[5] * f[2];
        f[6] = f[1];
        f[6] = f[6] * f[1];
        f[5] = f[5] + f[6];
        f[6] = f64::from_bits(0x3fe62e42fefa39ef);
        f.swap(6, 5);
        f[5] *= f[6].log2();
        f.swap(5, 4);
        f[3] = f[3] * f[5];
        f[3] = f[3] * f[4];
        f[4] = f64::from_bits(0x3ff71547652b82fe);
        f[3] = f[3] * f[4];
        f[4] = f64::from_bits(0x3ff0000000000000);
        f[5] = f[3];
        { let (x, y) = (f[5], f[4]); let q = if false { (x / y).round_ties_even() } else { (x / y).trunc() }; f[5] = if false { x - q * y } else { x % y }; let qi = q.abs() as u64; fsw = (if qi & 4 != 0 { 0x0100 } else { 0 }) | (if qi & 2 != 0 { 0x4000 } else { 0 }) | (if qi & 1 != 0 { 0x0200 } else { 0 }); }
        f[5] = f[5].exp2() - 1.0;
        f[4] = f[4] + f[5];
        f[4] *= f[3].trunc().exp2();
        f.swap(4, 3);
        f[4] = f[4];
        f.swap(3, 1);
        f.swap(3, 2);
        f[2] = f[2].atan2(f[3]);
        f[3] = f64::from_bits(v29);
        f[2] = f[2] * f[3];
        s2007 = f[2].to_bits();
        f[2] = f64::from_bits(s2007);
        { let (s, c) = f[2].sin_cos(); f[2] = s; f[3] = c; fsw &= !0x0400; }
        s2012 = f[3].to_bits();
        s2013 = f[2].to_bits();
        f[2] = f[1];
        { let v = f64::from_bits(s2013); f[2] = f[2] * v; }
        f.swap(2, 1);
        { let v = f64::from_bits(s2012); f[2] = f[2] * v; }
        f[3] = f64::from_bits(0x3ff0000000000000);
        f[2] = f[2] + f[3];
        f[3] = f[2];
        f[4] = f64::from_bits(v33);
        f.swap(4, 2);
        f[4] = f[4] * f[4];
        f[5] = f[1];
        f[5] = f[5] * f[1];
        f[4] = f[4] + f[5];
        f[2] = f[2] / f[4];
        f[4] = f64::from_bits(v24);
        s2005 = f[4].to_bits();
        f[4] = f64::from_bits(v23);
        f[5] = f64::from_bits(v27);
        f[6] = f[0];
        f[6] = f[6] * f[3];
        f[7] = f64::from_bits(s2000);
        f[7] = f[7] * f[1];
        f[6] = f[6] + f[7];
        f[6] = f[6] * f[2];
        { let v = f64::from_bits(s2005); f[6] = f[6] - v; }
        f[5] = f[5] * f[6];
        f[6] = f64::from_bits(v27);
        f.swap(6, 3);
        { let v = f64::from_bits(s2000); f[6] = f[6] * v; }
        f.swap(6, 1);
        f[0] = f[0] * f[6];
        f.swap(5, 1);
        f[0] = f[5] - f[0];
        f.swap(4, 0);
        f[2] = f[2] * f[4];
        f.swap(3, 0);
        f[2] = f[2] - f[3];
        f[0] = f[0] * f[2];
        f[2] = f64::from_bits(v28);
        f[3] = f64::from_bits(s2004);
        f[2] = f[2] * f[3];
        f[3] = f64::from_bits(s2001);
        f[4] = f[3];
        f[3] = f[3] * f[4];
        f[4] = f64::from_bits(s2002);
        f[5] = f[4];
        f[4] = f[4] * f[5];
        f[3] = f[3] + f[4];
        f[4] = f64::from_bits(s2003);
        f[5] = f[4];
        f[4] = f[4] * f[5];
        f[3] = f[3] + f[4];
        f[4] = f[1];
        f[4] = f[4] * f[1];
        f[5] = f[0];
        f[5] = f[5] * f[0];
        f[4] = f[4] + f[5];
        f[5] = f[2];
        f[5] = f[5] * f[2];
        f[4] = f[4] + f[5];
        f[3] = f[3] / f[4];
        f[3] = f[3].sqrt();
        f.swap(3, 1);
        s2008 = f[3].to_bits();
        f.swap(2, 0);
        f[3] = f64::from_bits(s2008);
        r3 = f[3].to_bits();
        s2009 = f[2].to_bits();
        f.swap(1, 0);
        f[2] = f64::from_bits(s2009);
        r4 = f[2].to_bits();
        s2010 = f[1].to_bits();
        f[1] = f64::from_bits(s2010);
        r5 = f[1].to_bits();
        s2011 = f[0].to_bits();
        f[0] = f64::from_bits(s2011);
        { let v = f64::from_bits(r32); f[0] = f[0] * v; }
        r32 = f[0].to_bits();
        { let bv = 0x74u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        { rg[6] = ((s2014 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[7] = ((s2015 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10001100u32, r32);
    m.wr64u(0x10007e80u32, s2000);
    m.wr64u(0x10007e88u32, s2001);
    m.wr64u(0x10007e90u32, s2002);
    m.wr64u(0x10007e98u32, s2003);
    m.wr64u(0x10007ea0u32, s2004);
    m.wr64u(0x10007ea8u32, s2005);
    m.wr64u(0x10007eb0u32, s2006);
    m.wr64u(0x10007eb8u32, s2007);
    m.wr64u(0x10007ec0u32, s2008);
    m.wr64u(0x10007ec8u32, s2009);
    m.wr64u(0x10007ed0u32, s2010);
    m.wr64u(0x10007ed8u32, s2011);
    m.wr64u(0x10007ee0u32, s2012);
    m.wr64u(0x10007ee8u32, s2013);
    m.wr64u(0x10007ef0u32, s2014);
    m.wr64u(0x10007ef8u32, s2015);
    m.regs = rg;
    m.fl = fl;
    m.fsw_cc = fsw;
    m.st = f;
    Ok(())
}

// Wobblybulb

pub(super) fn f_d1afd04a670fe713(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let vb = pvar.wrapping_sub(256);
    let vm = m.bytes_at::<56>(vb.wrapping_add(192))?;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r10: u64 = rec_get(m, it, pvar, 10);
    let mut r11: u64 = rec_get(m, it, pvar, 11);
    let mut r12: u64 = rec_get(m, it, pvar, 12);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s2004: u64 = m.rd64u(0x10007ea0u32);
    let mut s2005: u64 = m.rd64u(0x10007ea8u32);
    let mut s2007: u64 = m.rd64u(0x10007eb8u32);
    let mut s2008: u64 = m.rd64u(0x10007ec0u32);
    let mut s2009: u64 = m.rd64u(0x10007ec8u32);
    let mut s2010: u64 = m.rd64u(0x10007ed0u32);
    let mut s2011: u64 = m.rd64u(0x10007ed8u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    let mut v24: u64 = cell(vm, 0);
    let mut v25: u64 = cell(vm, 8);
    let mut v26: u64 = cell(vm, 16);
    let mut v27: u64 = cell(vm, 24);
    let mut v28: u64 = cell(vm, 32);
    let mut v29: u64 = cell(vm, 40);
    let mut v30: u64 = cell(vm, 48);
    'body: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        { let bv = 0x40u32; let av = rg[4]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[4] = r; }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2005 = (s2005 & !(0xffffffffu64 << 32)) | (((rg[3] as u64) & 0xffffffffu64) << 32); }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2005 = (s2005 & !(0xffffffffu64 << 0)) | (((rg[6] as u64) & 0xffffffffu64) << 0); }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2004 = (s2004 & !(0xffffffffu64 << 32)) | (((rg[7] as u64) & 0xffffffffu64) << 32); }
        rg[6] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[7] = ((r13 >> 0) & 0xffffffffu64) as u32;
        rg[3] = rg[0];
        f[0] = f64::from_bits(r3);
        { let v = f64::from_bits(v26); f[0] = f[0] * v; }
        f[1] = f64::from_bits(r4);
        { let v = f64::from_bits(v25); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        { let v = f64::from_bits(v24); f[0] = f[0] + v; }
        f[0] = f[0].sin(); fsw &= !0x0400;
        { let v = f64::from_bits(v27); f[0] = f[0] * v; }
        { let v = f64::from_bits(r5); f[0] = f[0] + v; }
        r5 = f[0].to_bits();
        f[0] = f64::from_bits(r3);
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits(r4);
        f[1] = f[1] * f[1];
        f[2] = f64::from_bits(r5);
        f[2] = f[2] * f[2];
        f[1] = f[1] + f[2];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        s2013 = f[0].to_bits();
        f[1] = f64::from_bits(v30);
        f.swap(1, 0);
        f[1] = f[1].abs();
        f[0] *= f[1].log2();
        f[1] = f64::from_bits(0x3ff0000000000000);
        f[2] = f[0];
        { let (x, y) = (f[2], f[1]); let q = if false { (x / y).round_ties_even() } else { (x / y).trunc() }; f[2] = if false { x - q * y } else { x % y }; let qi = q.abs() as u64; fsw = (if qi & 4 != 0 { 0x0100 } else { 0 }) | (if qi & 2 != 0 { 0x4000 } else { 0 }) | (if qi & 1 != 0 { 0x0200 } else { 0 }); }
        f[2] = f[2].exp2() - 1.0;
        f[1] = f[1] + f[2];
        f[1] *= f[0].trunc().exp2();
        f.swap(1, 0);
        f[1] = f[1];
        s2012 = f[0].to_bits();
        f[0] = f64::from_bits(r3);
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits(r5);
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        s2011 = f[0].to_bits();
        f[1] = f64::from_bits(r4);
        f[0] = f[0].atan2(f[1]);
        { let v = f64::from_bits(v30); f[0] = f[0] * v; }
        { let (s, c) = f[0].sin_cos(); f[0] = s; f[1] = c; fsw &= !0x0400; }
        s2009 = f[1].to_bits();
        s2010 = f[0].to_bits();
        f[0] = f64::from_bits(r3);
        f[1] = f64::from_bits(r5);
        f[0] = f[0].atan2(f[1]);
        { let v = f64::from_bits(v29); f[0] = f[0] * v; }
        { let (s, c) = f[0].sin_cos(); f[0] = s; f[1] = c; fsw &= !0x0400; }
        s2007 = f[1].to_bits();
        s2008 = f[0].to_bits();
        f[0] = f64::from_bits(s2010);
        { let v = f64::from_bits(s2008); f[0] = f[0] * v; }
        { let v = f64::from_bits(s2012); f[0] = f[0] * v; }
        { let v = f64::from_bits(r10); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        f[0] = f64::from_bits(s2009);
        { let v = f64::from_bits(s2012); f[0] = f[0] * v; }
        { let v = f64::from_bits(r11); f[0] = f[0] + v; }
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(s2010);
        { let v = f64::from_bits(s2007); f[0] = f[0] * v; }
        { let v = f64::from_bits(v28); f[0] = f[0] * v; }
        { let v = f64::from_bits(s2012); f[0] = f[0] * v; }
        { let v = f64::from_bits(r12); f[0] = f[0] + v; }
        r5 = f[0].to_bits();
        rg[0] = rg[3];
        { rg[7] = ((s2004 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[6] = ((s2005 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[3] = ((s2005 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[4] = rg[5];
        { rg[5] = ((s2014 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 3, r3);
    rec_set(m, it, 4, r4);
    rec_set(m, it, 5, r5);
    m.wr64u(0x10007ea0u32, s2004);
    m.wr64u(0x10007ea8u32, s2005);
    m.wr64u(0x10007eb8u32, s2007);
    m.wr64u(0x10007ec0u32, s2008);
    m.wr64u(0x10007ec8u32, s2009);
    m.wr64u(0x10007ed0u32, s2010);
    m.wr64u(0x10007ed8u32, s2011);
    m.wr64u(0x10007ee0u32, s2012);
    m.wr64u(0x10007ee8u32, s2013);
    m.wr64u(0x10007ef0u32, s2014);
    Ok(())
}

// loresmodeIFS

pub(super) fn f_db5a99b4889edb6e(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<32>(vb.wrapping_add(232))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut s2011: u64 = m.rd64u(0x10007ed8u32);
    let mut v29: u64 = cell(vm, 0);
    let mut v30: u64 = cell(vm, 8);
    let mut v32: u64 = cell(vm, 24);
    'body: {
        // block 0
        { let bv = 0xffffffe0u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        f[0] = f64::from_bits(r5);
        { let v = f64::from_bits(v30); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; s2011 = (s2011 & !(0xffffffffu64 << 32)) | (((i as u64) & 0xffffffffu64) << 32); }
        { let v = (((s2011 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = (((s2011 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits(v29); f[0] = f[0] * v; }
        r5 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        { let v = f64::from_bits(v30); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; s2011 = (s2011 & !(0xffffffffu64 << 32)) | (((i as u64) & 0xffffffffu64) << 32); }
        { let v = (((s2011 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = (((s2011 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits(v29); f[0] = f[0] * v; }
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(r3);
        { let v = f64::from_bits(v30); f[0] = f[0] * v; }
        { let x = m.round_int(f[0]); let i = if x.is_nan() || !(-2147483648.0..=2147483647.0).contains(&x) { 0x8000_0000u32 } else { x as i32 as u32 }; s2011 = (s2011 & !(0xffffffffu64 << 32)) | (((i as u64) & 0xffffffffu64) << 32); }
        { let v = (((s2011 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1] * f[1];
        f[1] = f[1] * f[1];
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let v = (((s2011 >> 32) & 0xffffffffu64) as u32 as i32 as f64); f[0] = f[0] + v; }
        { let v = f64::from_bits(v29); f[0] = f[0] * v; }
        r3 = f[0].to_bits();
        { let bv = 0x20u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10007ed8u32, s2011);
    m.regs = rg;
    m.fl = fl;
    m.fsw_cc = fsw;
    m.st = f;
    Ok(())
}

// _T_Scale4D

pub(super) fn f_e000d141ddd3a421(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let vb = pvar.wrapping_sub(256);
    let vm = m.bytes_at::<32>(vb.wrapping_add(216))?;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r6: u64 = rec_get(m, it, pvar, 6);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    let mut v27: u64 = cell(vm, 0);
    let mut v28: u64 = cell(vm, 8);
    let mut v29: u64 = cell(vm, 16);
    let mut v30: u64 = cell(vm, 24);
    'body: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 32)) | (((rg[6] as u64) & 0xffffffffu64) << 32); }
        rg[6] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[6] = ((r13 >> 0) & 0xffffffffu64) as u32;
        f[0] = f64::from_bits(r3);
        { let v = f64::from_bits(v30); f[0] = f[0] * v; }
        r3 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        { let v = f64::from_bits(v29); f[0] = f[0] * v; }
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        { let v = f64::from_bits(v28); f[0] = f[0] * v; }
        r5 = f[0].to_bits();
        f[0] = f64::from_bits(r6);
        { let v = f64::from_bits(v27); f[0] = f[0] * v; }
        r6 = f[0].to_bits();
        { rg[6] = ((s2013 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[5] = ((s2014 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 3, r3);
    rec_set(m, it, 4, r4);
    rec_set(m, it, 5, r5);
    rec_set(m, it, 6, r6);
    m.wr64u(0x10007ee8u32, s2013);
    m.wr64u(0x10007ef0u32, s2014);
    Ok(())
}

// _T_Offset

pub(super) fn f_e04801556de19bc6(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let vb = pvar.wrapping_sub(256);
    let vm = m.bytes_at::<24>(vb.wrapping_add(224))?;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    let mut v28: u64 = cell(vm, 0);
    let mut v29: u64 = cell(vm, 8);
    let mut v30: u64 = cell(vm, 16);
    'body: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 32)) | (((rg[6] as u64) & 0xffffffffu64) << 32); }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 0)) | (((rg[7] as u64) & 0xffffffffu64) << 0); }
        rg[6] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[7] = ((r13 >> 0) & 0xffffffffu64) as u32;
        f[0] = f64::from_bits(r3);
        { let v = f64::from_bits(v30); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        { let v = f64::from_bits(v29); f[0] = f[0] + v; }
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        { let v = f64::from_bits(v28); f[0] = f[0] + v; }
        r5 = f[0].to_bits();
        { rg[7] = ((s2013 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[6] = ((s2013 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[5] = ((s2014 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 3, r3);
    rec_set(m, it, 4, r4);
    rec_set(m, it, 5, r5);
    m.wr64u(0x10007ee8u32, s2013);
    m.wr64u(0x10007ef0u32, s2014);
    Ok(())
}

// eiffieCarIFS

pub(super) fn f_e37b852748043cdc(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<224>(vb.wrapping_add(160))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut r14: u64 = m.rd64u(0x10001070u32);
    let mut r32: u64 = m.rd64u(0x10001100u32);
    let mut r34: u64 = m.rd64u(0x10001110u32);
    let mut s2008: u64 = m.rd64u(0x10007ec0u32);
    let mut s2009: u64 = m.rd64u(0x10007ec8u32);
    let mut s2010: u64 = m.rd64u(0x10007ed0u32);
    let mut s2011: u64 = m.rd64u(0x10007ed8u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut v20: u64 = cell(vm, 0);
    let mut v21: u64 = cell(vm, 8);
    let mut v22: u64 = cell(vm, 16);
    let mut v23: u64 = cell(vm, 24);
    let mut v24: u64 = cell(vm, 32);
    let mut v25: u64 = cell(vm, 40);
    let mut v26: u64 = cell(vm, 48);
    let mut v27: u64 = cell(vm, 56);
    let mut v28: u64 = cell(vm, 64);
    let mut v29: u64 = cell(vm, 72);
    let mut v30: u64 = cell(vm, 80);
    let mut v32: u64 = cell(vm, 96);
    let mut v33: u64 = cell(vm, 104);
    let mut v34: u64 = cell(vm, 112);
    let mut v35: u64 = cell(vm, 120);
    let mut v36: u64 = cell(vm, 128);
    let mut v37: u64 = cell(vm, 136);
    let mut v38: u64 = cell(vm, 144);
    let mut v39: u64 = cell(vm, 152);
    let mut v40: u64 = cell(vm, 160);
    let mut v41: u64 = cell(vm, 168);
    let mut v42: u64 = cell(vm, 176);
    let mut v43: u64 = cell(vm, 184);
    let mut v44: u64 = cell(vm, 192);
    let mut v45: u64 = cell(vm, 200);
    let mut v46: u64 = cell(vm, 208);
    let mut v47: u64 = cell(vm, 216);
    'body: {
        'b8: {
        'b7: {
        'b5: {
        'b6: {
        'b2: {
        // block 0
        { let bv = 0x44u32; let av = rg[4]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[4] = r; }
        f[0] = f64::from_bits(r4);
        f[1] = f64::from_bits(v27);
        f[2] = f64::from_bits(v29);
        f.swap(2, 1);
        f[0] = f[0] * f[2];
        f[0] = f[1] - f[0];
        f[1] = f64::from_bits(r5);
        f[2] = f64::from_bits(v27);
        f[3] = f64::from_bits(v28);
        f.swap(3, 2);
        f[1] = f[1] * f[3];
        f[1] = f[2] - f[1];
        f[2] = f64::from_bits(r3);
        f[3] = f64::from_bits(v27);
        f[4] = f64::from_bits(v30);
        f.swap(4, 3);
        f[2] = f[2] * f[4];
        f[2] = f[2] + f[3];
        f[3] = (f32::from_bits(((v20 >> 32) & 0xffffffffu64) as u32) as f64);
        f[4] = (f32::from_bits(((v21 >> 0) & 0xffffffffu64) as u32) as f64);
        f[5] = (f32::from_bits(((v21 >> 32) & 0xffffffffu64) as u32) as f64);
        f.swap(5, 3);
        f[5] = f[5] * f[0];
        f.swap(5, 4);
        f[5] = f[5] * f[1];
        f[4] = f[4] + f[5];
        f.swap(4, 3);
        f[4] = f[4] * f[2];
        f[3] = f[3] + f[4];
        f[4] = (f32::from_bits(((v22 >> 0) & 0xffffffffu64) as u32) as f64);
        f[5] = (f32::from_bits(((v22 >> 32) & 0xffffffffu64) as u32) as f64);
        f.swap(5, 4);
        f[5] = f[5] * f[0];
        f.swap(5, 4);
        f[5] = f[5] * f[1];
        f[4] = f[4] + f[5];
        f[5] = (f32::from_bits(((v23 >> 0) & 0xffffffffu64) as u32) as f64);
        f[5] = f[5] * f[2];
        f[4] = f[4] + f[5];
        f[5] = (f32::from_bits(((v23 >> 32) & 0xffffffffu64) as u32) as f64);
        f[6] = (f32::from_bits(((v24 >> 0) & 0xffffffffu64) as u32) as f64);
        f[7] = (f32::from_bits(((v24 >> 32) & 0xffffffffu64) as u32) as f64);
        f.swap(7, 5);
        f[0] = f[0] * f[7];
        f[1] = f[1] * f[6];
        f.swap(5, 1);
        f[0] = f[0] + f[5];
        f.swap(4, 2);
        f[1] = f[1] * f[4];
        f.swap(3, 1);
        f[0] = f[0] + f[3];
        rg[0] = ((v20 >> 0) & 0xffffffffu64) as u32;
        s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[0] as u64) & 0xffffffffu64) << 0);
        { let bv = 0x0u32; let av = (((s2014 >> 0) & 0xffffffffu64) as u32); let r = fl.alu(Alu::Cmp, av, bv, 4); }
        if fl.cond(4) { break 'b2; }
        // block 1
        f[3] = f64::from_bits(r3);
        f[4] = f64::from_bits(v27);
        f[5] = f64::from_bits(v30);
        f.swap(5, 3);
        f[4] = f[4] * f[5];
        f[3] = f[3] + f[4];
        s2008 = f[3].to_bits();
        f[3] = f64::from_bits(s2008);
        r3 = f[3].to_bits();
        f[3] = f64::from_bits(r4);
        f[4] = f64::from_bits(v27);
        f[5] = f64::from_bits(v29);
        f.swap(5, 3);
        f[4] = f[4] * f[5];
        f[3] = f[3] + f[4];
        s2009 = f[3].to_bits();
        f[3] = f64::from_bits(s2009);
        r4 = f[3].to_bits();
        f[3] = f64::from_bits(r5);
        f[4] = f64::from_bits(v27);
        f[5] = f64::from_bits(v28);
        f.swap(5, 3);
        f[4] = f[4] * f[5];
        f[3] = f[3] + f[4];
        s2010 = f[3].to_bits();
        f[3] = f64::from_bits(s2010);
        r5 = f[3].to_bits();
        f[3] = f64::from_bits(v27);
        s2011 = f[3].to_bits();
        f[3] = f64::from_bits(s2011);
        { let v = f64::from_bits(r32); f[3] = f[3] * v; }
        r32 = f[3].to_bits();
        } // 'b2
        // block 2
        f[3] = f[0];
        f[3] = f[3] * f[0];
        f[4] = f[1];
        f[4] = f[4] * f[1];
        f[5] = f[2];
        f[5] = f[5] * f[2];
        f[4] = f[4] + f[5];
        f[4] = f[4] + f[3];
        f[4] = f[4].sqrt();
        f[5] = f[4];
        f[6] = f64::from_bits(v44);
        { let (x,y) = (f[6], f[5]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        f[5] = f[5];
        if fl.cond(6) { break 'b7; }
        // block 3
        f[4] = f[4];
        f[4] = f64::from_bits(v41);
        f[4] = f[4] + f[2];
        f[5] = f[4];
        f[5] = f[5] * f[4];
        f[3] = f[3] + f[5];
        f.swap(4, 3);
        f[4] = f[4].sqrt();
        f[5] = f64::from_bits(v42);
        f[3] = f[5] - f[3];
        f[5] = f64::from_bits(v43);
        f[4] = f[4] - f[5];
        f[5] = f[1];
        f[5] = f[5].abs();
        f[6] = f64::from_bits(v38);
        f[5] = f[5] - f[6];
        f[6] = f64::from_bits(0x0);
        f.swap(6, 3);
        { let (x,y) = (f[6], f[3]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        if fl.cond(6) { f[6] = f[3]; }
        f.swap(6, 4);
        { let (x,y) = (f[6], f[3]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        if fl.cond(6) { f[6] = f[3]; }
        f.swap(6, 5);
        { let (x,y) = (f[6], f[3]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        if fl.cond(6) { f[6] = f[3]; }
        f[3] = f[6];
        f.swap(5, 3);
        f[5] = f[5] * f[5];
        f.swap(5, 3);
        f[5] = f[5] * f[5];
        f[3] = f[3] + f[5];
        f[5] = f[4];
        f[4] = f[4] * f[5];
        f[3] = f[3] + f[4];
        f[3] = f[3].sqrt();
        f[4] = f64::from_bits(v33);
        f[3] = f[3] - f[4];
        f[4] = f64::from_bits(0x3ff0000000000000);
        f[4] = f[0] - f[4];
        f.swap(4, 3);
        { let (x,y) = (f[4], f[3]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        if fl.cond(6) { f[4] = f[3]; }
        f[3] = f[4];
        f[4] = f64::from_bits(v45);
        f[2] = f[2] - f[4];
        f[4] = f64::from_bits(v46);
        f.swap(4, 1);
        f[4] = f[4].abs();
        f[5] = f64::from_bits(v39);
        f[4] = f[4] - f[5];
        f[4] = f[4].abs();
        f.swap(4, 0);
        f[1] = f[1] + f[4];
        f.swap(3, 1);
        f[3] = f[3].abs();
        f[4] = f64::from_bits(v40);
        f[3] = f[3] - f[4];
        f[4] = f[2];
        f[4] = f[4] * f[2];
        f.swap(4, 3);
        f[4] = f[4] * f[4];
        f[3] = f[3] + f[4];
        f[3] = f[3].sqrt();
        f[4] = f64::from_bits(v34);
        f.swap(4, 2);
        f[4] = -f[4];
        f[2] = f[4] - f[2];
        f[4] = f64::from_bits(v37);
        f[4] = f[3] - f[4];
        f[5] = f64::from_bits(v34);
        f[5] = f[0] - f[5];
        f[6] = f64::from_bits(0x0);
        f.swap(6, 2);
        { let (x,y) = (f[6], f[2]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        if fl.cond(6) { f[6] = f[2]; }
        f.swap(6, 4);
        { let (x,y) = (f[6], f[2]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        if fl.cond(6) { f[6] = f[2]; }
        f.swap(6, 5);
        { let (x,y) = (f[6], f[2]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        if fl.cond(6) { f[6] = f[2]; }
        f[2] = f[6];
        f.swap(5, 2);
        f[5] = f[5] * f[5];
        f.swap(5, 2);
        f[5] = f[5] * f[5];
        f[2] = f[2] + f[5];
        f[4] = f[4] * f[4];
        f[2] = f[2] + f[4];
        f.swap(3, 2);
        f[3] = f[3].sqrt();
        f[4] = f64::from_bits(v32);
        f[5] = f64::from_bits(v44);
        f[5] = -f[5];
        f[1] = f[1] * f[5];
        f.swap(5, 1);
        f[6] = f64::from_bits(0x3ff71547652b82fe);
        f[5] = f[5] * f[6];
        f[6] = f64::from_bits(0x3ff0000000000000);
        f[7] = f[5];
        { let (x, y) = (f[7], f[6]); let q = if false { (x / y).round_ties_even() } else { (x / y).trunc() }; f[7] = if false { x - q * y } else { x % y }; let qi = q.abs() as u64; fsw = (if qi & 4 != 0 { 0x0100 } else { 0 }) | (if qi & 2 != 0 { 0x4000 } else { 0 }) | (if qi & 1 != 0 { 0x0200 } else { 0 }); }
        f[7] = f[7].exp2() - 1.0;
        f[6] = f[6] + f[7];
        f[6] *= f[5].trunc().exp2();
        f.swap(6, 5);
        f[6] = f[6];
        f.swap(5, 3);
        f[4] = f[5] - f[4];
        f[4] = f[4] * f[1];
        f[5] = f64::from_bits(0x3ff71547652b82fe);
        f[4] = f[4] * f[5];
        f[5] = f64::from_bits(0x3ff0000000000000);
        f[6] = f[4];
        { let (x, y) = (f[6], f[5]); let q = if false { (x / y).round_ties_even() } else { (x / y).trunc() }; f[6] = if false { x - q * y } else { x % y }; let qi = q.abs() as u64; fsw = (if qi & 4 != 0 { 0x0100 } else { 0 }) | (if qi & 2 != 0 { 0x4000 } else { 0 }) | (if qi & 1 != 0 { 0x0200 } else { 0 }); }
        f[6] = f[6].exp2() - 1.0;
        f[5] = f[5] + f[6];
        f[5] *= f[4].trunc().exp2();
        f.swap(5, 4);
        f[5] = f[5];
        f[3] = f[3] + f[4];
        f[4] = f64::from_bits(0x3fe62e42fefa39ef);
        f.swap(4, 3);
        f[3] *= f[4].log2();
        f[1] = f[3] / f[1];
        f[3] = f64::from_bits(v37);
        f[3] = f[2] - f[3];
        f[4] = f64::from_bits(v36);
        f[4] = f[0] - f[4];
        { let (x,y) = (f[4], f[3]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        if fl.cond(6) { f[4] = f[3]; }
        f[3] = f[4];
        f[3] = -f[3];
        f.swap(3, 1);
        { let (x,y) = (f[3], f[1]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        if fl.cond(6) { f[3] = f[1]; }
        f[1] = f[3];
        f[3] = f64::from_bits(v45);
        f[2] = f[2] - f[3];
        f[3] = f64::from_bits(0x0);
        f[4] = f64::from_bits(v35);
        f[0] = f[0] - f[4];
        f[4] = f[0];
        { let (x,y) = (f[4], f[3]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        if fl.cond(7) { f[3] = f[0]; }
        f[0] = f[3];
        f[3] = f[0];
        f[0] = f[0] * f[3];
        f[3] = f[2];
        f[2] = f[2] * f[3];
        f[0] = f[0] + f[2];
        f.swap(1, 0);
        f[1] = f[1].sqrt();
        f[2] = f64::from_bits(v47);
        f[1] = f[1] - f[2];
        { let (x,y) = (f[1], f[0]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        if fl.cond(7) { f[1] = f[0]; }
        { let (x,y) = (f[1], f[0]); fl.of=false; fl.sf=false; fl.af=false; let unordered=x.is_nan() || y.is_nan(); fl.zf=unordered || x==y; fl.pf=unordered; fl.cf=unordered || x<y; }
        f[0] = f[1];
        if fl.cond(10) { break 'b5; }
        // block 4
        if fl.cond(4) { break 'b6; }
        break 'b5;
        } // 'b6
        // block 6
        f[1] = f64::from_bits(v25);
        s2013 = f[1].to_bits();
        f[1] = f64::from_bits(s2013);
        r34 = f[1].to_bits();
        break 'b8;
        } // 'b5
        // block 5
        f[1] = f64::from_bits(v26);
        s2012 = f[1].to_bits();
        f[1] = f64::from_bits(s2012);
        r34 = f[1].to_bits();
        break 'b8;
        } // 'b7
        // block 7
        f[1] = f[4];
        f[3] = f[3];
        f[2] = f[2];
        f[0] = f[1];
        } // 'b8
        // block 8
        f[1] = f64::from_bits(v27);
        f[0] = f[0] / f[1];
        s2014 = f[0].to_bits();
        f[0] = f64::from_bits(s2014);
        r14 = f[0].to_bits();
        { let bv = 0x44u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10001070u32, r14);
    m.wr64u(0x10001100u32, r32);
    m.wr64u(0x10001110u32, r34);
    m.wr64u(0x10007ec0u32, s2008);
    m.wr64u(0x10007ec8u32, s2009);
    m.wr64u(0x10007ed0u32, s2010);
    m.wr64u(0x10007ed8u32, s2011);
    m.wr64u(0x10007ee0u32, s2012);
    m.wr64u(0x10007ee8u32, s2013);
    m.wr64u(0x10007ef0u32, s2014);
    m.regs = rg;
    m.fl = fl;
    m.fsw_cc = fsw;
    m.st = f;
    Ok(())
}

// _T_Sin_XYZ

pub(super) fn f_fb2f524a42903f19(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r10: u64 = rec_get(m, it, pvar, 10);
    let mut r11: u64 = rec_get(m, it, pvar, 11);
    let mut r12: u64 = rec_get(m, it, pvar, 12);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    'body: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        rg[0] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        { let bv = 0x38u32; let av = rg[0]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[0] = r; }
        f[0] = f64::from_bits(r3);
        f[1] = f64::from_bits(r4);
        f[2] = f[0];
        f[3] = f[1];
        f.swap(3, 2);
        f[3] = f[3] * f[0];
        f.swap(3, 2);
        f[3] = f[3] * f[1];
        f.swap(3, 0);
        f[1] = f[1] * f[3];
        f[3] = f[2];
        f[4] = f64::from_bits(r5);
        f.swap(4, 1);
        f[4] = f[4] + f[4];
        f.swap(4, 3);
        f[4] = f[4] + f[0];
        f.swap(4, 2);
        f[0] = f[4] - f[0];
        f[4] = f[1];
        f.swap(4, 2);
        f[4] = f[4].sqrt();
        f.swap(4, 2);
        f[4] = f[4] * f[1];
        f.swap(4, 2);
        f[5] = f64::from_bits(0x3ff0000000000000);
        f[4] = f[5] / f[4];
        f[3] = f[3] * f[4];
        f[5] = f[3];
        f.swap(5, 0);
        f[4] = f[4] * f[5];
        f[5] = f[2];
        f.swap(5, 0);
        f[5] = f[5] * f[3];
        f.swap(5, 1);
        f[5] = f[5] * f[3];
        f.swap(5, 3);
        r4 = f[5].to_bits();
        f.swap(4, 0);
        f[4] = f[4] + f[1];
        f.swap(4, 3);
        f[4] = f[4] + f[4];
        f.swap(4, 1);
        f[2] = f[4] - f[2];
        f[3] = f[3].sqrt();
        f[4] = f[0];
        r3 = f[4].to_bits();
        f.swap(4, 3);
        f[5] = f64::from_bits(0x3ff0000000000000);
        f[4] = f[5] / f[4];
        f[1] = f[1] * f[4];
        f[5] = f[1];
        f.swap(5, 2);
        f[4] = f[4] * f[5];
        f.swap(4, 0);
        f[4] = f[4] * f[3];
        f.swap(4, 2);
        f[4] = f[4] * f[1];
        f.swap(4, 1);
        r5 = f[4].to_bits();
        f[3] = f[3] * f[4];
        f[4] = f[1];
        f.swap(4, 3);
        f[4] = f[4] + f[4];
        f.swap(4, 0);
        r4 = f[4].to_bits();
        f.swap(4, 3);
        f[4] = f[4] + f[2];
        f.swap(4, 2);
        f[1] = f[4] - f[1];
        f[4] = f[3];
        f.swap(4, 2);
        f[4] = f[4].sqrt();
        f.swap(4, 2);
        f[4] = f[4] * f[3];
        f.swap(4, 2);
        f[5] = f64::from_bits(0x3ff0000000000000);
        f[4] = f[5] / f[4];
        f[1] = f[1] * f[4];
        f[0] = f[0] * f[4];
        f[4] = f[1];
        f[4] = f[4] * f[1];
        f[2] = f[2] + f[4];
        f[4] = f[0];
        f[4] = f[4] * f[0];
        f[2] = f[2] + f[4];
        f.swap(3, 2);
        f[3] = f[3].sqrt();
        f[1] = f[1] * f[3];
        f[2] = f[2] * f[3];
        f[0] = f[0] * f[3];
        f.swap(2, 1);
        { let v = f64::from_bits(r10); f[2] = f[2] + v; }
        f.swap(2, 1);
        { let v = f64::from_bits(r11); f[2] = f[2] + v; }
        f.swap(2, 0);
        { let v = f64::from_bits(r12); f[2] = f[2] + v; }
        f.swap(2, 1);
        r3 = f[2].to_bits();
        f.swap(1, 0);
        r4 = f[1].to_bits();
        r5 = f[0].to_bits();
        { rg[5] = ((s2014 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 3, r3);
    rec_set(m, it, 4, r4);
    rec_set(m, it, 5, r5);
    m.wr64u(0x10007ef0u32, s2014);
    Ok(())
}

// _F_BoxFold
