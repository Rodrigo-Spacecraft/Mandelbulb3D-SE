//! Additional bundled native formulas, including lifted kernels.
use super::*;

pub(super) fn f_10b6bb1104349cbf(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
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

// teapot

pub(super) fn f_147b986ebf3538f6(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<304>(vb.wrapping_add(136))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut r6: u64 = m.rd64u(0x10001030u32);
    let mut r14: u64 = m.rd64u(0x10001070u32);
    let mut r15: u64 = m.rd64u(0x10001078u32);
    let mut r32: u64 = m.rd64u(0x10001100u32);
    let mut r33: u64 = m.rd64u(0x10001108u32);
    let mut r34: u64 = m.rd64u(0x10001110u32);
    let mut s2005: u64 = m.rd64u(0x10007ea8u32);
    let mut s2006: u64 = m.rd64u(0x10007eb0u32);
    let mut s2007: u64 = m.rd64u(0x10007eb8u32);
    let mut s2008: u64 = m.rd64u(0x10007ec0u32);
    let mut s2009: u64 = m.rd64u(0x10007ec8u32);
    let mut s2010: u64 = m.rd64u(0x10007ed0u32);
    let mut s2011: u64 = m.rd64u(0x10007ed8u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut v17: u64 = cell(vm, 0);
    let mut v18: u64 = cell(vm, 8);
    let mut v19: u64 = cell(vm, 16);
    let mut v20: u64 = cell(vm, 24);
    let mut v21: u64 = cell(vm, 32);
    let mut v22: u64 = cell(vm, 40);
    let mut v23: u64 = cell(vm, 48);
    let mut v24: u64 = cell(vm, 56);
    let mut v25: u64 = cell(vm, 64);
    let mut v26: u64 = cell(vm, 72);
    let mut v27: u64 = cell(vm, 80);
    let mut v28: u64 = cell(vm, 88);
    let mut v29: u64 = cell(vm, 96);
    let mut v30: u64 = cell(vm, 104);
    let mut v32: u64 = cell(vm, 120);
    let mut v33: u64 = cell(vm, 128);
    let mut v34: u64 = cell(vm, 136);
    let mut v35: u64 = cell(vm, 144);
    let mut v36: u64 = cell(vm, 152);
    let mut v37: u64 = cell(vm, 160);
    let mut v38: u64 = cell(vm, 168);
    let mut v39: u64 = cell(vm, 176);
    let mut v40: u64 = cell(vm, 184);
    let mut v41: u64 = cell(vm, 192);
    let mut v42: u64 = cell(vm, 200);
    let mut v43: u64 = cell(vm, 208);
    let mut v44: u64 = cell(vm, 216);
    let mut v45: u64 = cell(vm, 224);
    let mut v46: u64 = cell(vm, 232);
    let mut v47: u64 = cell(vm, 240);
    let mut v48: u64 = cell(vm, 248);
    let mut v49: u64 = cell(vm, 256);
    let mut v50: u64 = cell(vm, 264);
    let mut v51: u64 = cell(vm, 272);
    let mut v52: u64 = cell(vm, 280);
    let mut v53: u64 = cell(vm, 288);
    let mut v54: u64 = cell(vm, 296);
    'body: {
        'b34: {
        'b32: {
        'b31: {
        'b29: {
        'b28: {
        'b26: {
        'b25: {
        'b23: {
        'b22: {
        'b20: {
        'b19: {
        'b17: {
        'b16: {
        'b14: {
        'b13: {
        'b11: {
        'b10: {
        'b9: {
        'b7: {
        'b6: {
        'b4: {
        'b2: {
        // block 0
        { let bv = 0xffffffaeu32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        m.xmm[0] = [r3, r4];
        { let s: u64 = r5; m.xmm[1] = [s, 0]; }
        { let s: [u64; 2] = [v28, v29]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) * f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) * f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v28; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        { let s: [u64; 2] = [v24, v25]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) + f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) + f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v26; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) + f64::from_bits(s)).to_bits(); }
        { let bv = 0x0u32; let av = (((v23 >> 32) & 0xffffffffu64) as u32); let r = fl.alu(Alu::Cmp, av, bv, 4); }
        if fl.cond(4) { break 'b2; }
        // block 1
        { let s: u64 = r32; m.xmm[5] = [s, 0]; }
        { let s: u64 = v28; let a = m.xmm[5][0]; m.xmm[5][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        r3 = m.xmm[0][0]; r4 = m.xmm[0][1];
        r5 = m.xmm[1][0];
        r32 = m.xmm[5][0];
        } // 'b2
        // block 2
        { let v: u64 = m.xmm[0][0]; s2005 = (s2005 & !(0xffffffffffffu64 << 16)) | ((v & 0xffffffffffffu64) << 16); s2006 = (s2006 & !0xffffu64) | ((v >> 48) & 0xffffu64); } { let v: u64 = m.xmm[0][1]; s2006 = (s2006 & !(0xffffffffffffu64 << 16)) | ((v & 0xffffffffffffu64) << 16); s2007 = (s2007 & !0xffffu64) | ((v >> 48) & 0xffffu64); }
        { let v: u64 = m.xmm[1][0]; s2007 = (s2007 & !(0xffffffffffffu64 << 16)) | ((v & 0xffffffffffffu64) << 16); s2008 = (s2008 & !0xffffu64) | ((v >> 48) & 0xffffu64); }
        f[0] = f64::from_bits((((s2007 >> 16) | (s2008 << 48)) & u64::MAX));
        f[1] = f64::from_bits((((s2006 >> 16) | (s2007 << 48)) & u64::MAX));
        f[2] = f64::from_bits((((s2005 >> 16) | (s2006 << 48)) & u64::MAX));
        f[3] = f[2];
        { let v = (f32::from_bits(((v18 >> 0) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[4] = f[1];
        { let v = (f32::from_bits(((v17 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[0];
        { let v = (f32::from_bits(((v17 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[2];
        { let v = (f32::from_bits(((v21 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[5] = f[1];
        { let v = (f32::from_bits(((v20 >> 32) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f[5] = f[0];
        { let v = (f32::from_bits(((v20 >> 0) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f.swap(4, 2);
        { let v = (f32::from_bits(((v19 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f.swap(4, 1);
        { let v = (f32::from_bits(((v19 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[1] = f[1] + f[4];
        f.swap(3, 0);
        { let v = (f32::from_bits(((v18 >> 32) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[1] = f[1] + f[3];
        { let v: u64 = f[2].to_bits(); s2005 = (s2005 & !(0xffffffffffffu64 << 16)) | ((v & 0xffffffffffffu64) << 16); s2006 = (s2006 & !0xffffu64) | ((v >> 48) & 0xffffu64); }
        { let v: u64 = f[1].to_bits(); s2006 = (s2006 & !(0xffffffffffffu64 << 16)) | ((v & 0xffffffffffffu64) << 16); s2007 = (s2007 & !0xffffu64) | ((v >> 48) & 0xffffu64); }
        f[0] = -f[0];
        { let v: u64 = f[0].to_bits(); s2007 = (s2007 & !(0xffffffffffffu64 << 16)) | ((v & 0xffffffffffffu64) << 16); s2008 = (s2008 & !0xffffu64) | ((v >> 48) & 0xffffu64); }
        f[0] = f64::from_bits((((s2006 >> 16) | (s2007 << 48)) & u64::MAX));
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2005 >> 16) | (s2006 << 48)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v: u64 = f[0].to_bits(); s2008 = (s2008 & !(0xffffffffffffu64 << 16)) | ((v & 0xffffffffffffu64) << 16); s2009 = (s2009 & !0xffffu64) | ((v >> 48) & 0xffffu64); }
        f[0] = f64::from_bits((((s2007 >> 16) | (s2008 << 48)) & u64::MAX));
        { let v = f64::from_bits(v41); f[0] = f[0] - v; }
        { let v: u64 = f[0].to_bits(); s2010 = (s2010 & !(0xffffffffffffu64 << 16)) | ((v & 0xffffffffffffu64) << 16); s2011 = (s2011 & !0xffffu64) | ((v >> 48) & 0xffffu64); }
        f[1] = f64::from_bits(0x0);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(3) { break 'b4; }
        // block 3
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2008 >> 16) | (s2009 << 48)) & u64::MAX));
        { let v = f64::from_bits(v32); f[1] = f[1] + v; }
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits(v35); f[0] = f[0] - v; }
        break 'b11;
        } // 'b4
        // block 4
        f[0] = f[0];
        f[0] = f64::from_bits((((s2008 >> 16) | (s2009 << 48)) & u64::MAX));
        f[0] = f[0] + f[0];
        { let v = f64::from_bits((((s2007 >> 16) | (s2008 << 48)) & u64::MAX)); f[0] = f[0] - v; }
        { let v = f64::from_bits(v36); f[0] = f[0] - v; }
        f[1] = f64::from_bits(v39);
        { let v = f64::from_bits((((s2007 >> 16) | (s2008 << 48)) & u64::MAX)); f[1] = f[1] - v; }
        { let v: u64 = f[1].to_bits(); s2009 = (s2009 & !(0xffffffffffffu64 << 16)) | ((v & 0xffffffffffffu64) << 16); s2010 = (s2010 & !0xffffu64) | ((v >> 48) & 0xffffu64); }
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(3) { break 'b6; }
        // block 5
        f[1] = f[1];
        break 'b7;
        } // 'b6
        // block 6
        f[0] = f[1];
        } // 'b7
        // block 7
        f[1] = f64::from_bits(0x0);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x0) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(3) { break 'b9; }
        // block 8
        f[0] = f64::from_bits(v37);
        { let v = f64::from_bits((((s2008 >> 16) | (s2009 << 48)) & u64::MAX)); f[0] = f[0] - v; }
        f[1] = f[0];
        f[1] = f[1].abs();
        f[1] = -f[1];
        f[0] = f[0] + f[1];
        { let v = f64::from_bits(v38); f[0] = f[0] * v; }
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2009 >> 16) | (s2010 << 48)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits(v33); f[0] = f[0] + v; }
        break 'b10;
        } // 'b9
        // block 9
        f[0] = f64::from_bits((((s2008 >> 16) | (s2009 << 48)) & u64::MAX));
        { let v = f64::from_bits(v40); f[0] = f[0] - v; }
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2010 >> 16) | (s2011 << 48)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits(v34); f[0] = f[0] + v; }
        f[0] = -f[0];
        } // 'b10
        // block 10
        { let v: u64 = f[0].to_bits(); s2010 = (s2010 & !(0xffffffffffffu64 << 16)) | ((v & 0xffffffffffffu64) << 16); s2011 = (s2011 & !0xffffu64) | ((v >> 48) & 0xffffu64); }
        f[0] = f[0].abs();
        { let v = f64::from_bits(v35); f[0] = f[0] - v; }
        f[1] = f64::from_bits(v41);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(2) { break 'b32; }
        } // 'b11
        // block 11
        f[1] = f64::from_bits((((s2005 >> 16) | (s2006 << 48)) & u64::MAX));
        { let v = f64::from_bits(v45); f[1] = f[1] - v; }
        f[2] = f[1];
        f[3] = f64::from_bits((((s2007 >> 16) | (s2008 << 48)) & u64::MAX));
        { let v = f64::from_bits(v46); f[3] = f[3] + v; }
        f[4] = f[3];
        f[2] = f[2] + f[4];
        f.swap(3, 2);
        { let v = f64::from_bits(v47); f[3] = f[3] * v; }
        { let v: u64 = f[3].to_bits(); s2011 = (s2011 & !(0xffffffffffffu64 << 16)) | ((v & 0xffffffffffffu64) << 16); s2012 = (s2012 & !0xffffu64) | ((v >> 48) & 0xffffu64); }
        f[1] = f[2] - f[1];
        { let v = f64::from_bits(v47); f[1] = f[1] * v; }
        f[1] = f[1] * f[1];
        f[2] = f64::from_bits((((s2006 >> 16) | (s2007 << 48)) & u64::MAX));
        f[2] = f[2] * f[2];
        { let v = f64::from_bits(v48); f[2] = f[2] * v; }
        f[1] = f[1] + f[2];
        f[1] = f[1].sqrt();
        { let v = f64::from_bits(v49); f[1] = f[1] - v; }
        f[2] = f64::from_bits((((s2011 >> 16) | (s2012 << 48)) & u64::MAX));
        { let v = f64::from_bits(v50); f[2] = f[2] * v; }
        f[1] = f[1] + f[2];
        f[2] = f64::from_bits((((s2011 >> 16) | (s2012 << 48)) & u64::MAX));
        f[2] = f[2] * f[2];
        { let v = f64::from_bits(v54); f[2] = f[2] * v; }
        f[1] = f[1] + f[2];
        f[2] = f64::from_bits((((s2011 >> 16) | (s2012 << 48)) & u64::MAX));
        { let v = f64::from_bits(v44); f[2] = f[2] - v; }
        f[2] = f[2].abs();
        { let v = f64::from_bits(v44); f[2] = f[2] - v; }
        fsw = fcompare_cc(f[2], f[1]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x2800) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(3) { break 'b13; }
        // block 12
        f[2] = f[2];
        break 'b14;
        } // 'b13
        // block 13
        f[1] = f[2];
        } // 'b14
        // block 14
        { let v: u64 = f[1].to_bits(); s2011 = (s2011 & !(0xffffffffffffu64 << 16)) | ((v & 0xffffffffffffu64) << 16); s2012 = (s2012 & !0xffffu64) | ((v >> 48) & 0xffffu64); }
        { let v = f64::from_bits(v35); f[1] = f[1] - v; }
        f[1] = f[1].abs();
        { let v = f64::from_bits(v35); f[1] = f[1] - v; }
        f[2] = f64::from_bits((((s2007 >> 16) | (s2008 << 48)) & u64::MAX));
        { let v = f64::from_bits(v43); f[2] = f[2] - v; }
        fsw = fcompare_cc(f[2], f[1]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x2800) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(3) { break 'b16; }
        // block 15
        f[2] = f[2];
        break 'b17;
        } // 'b16
        // block 16
        f[1] = f[2];
        } // 'b17
        // block 17
        f[2] = f64::from_bits((((s2007 >> 16) | (s2008 << 48)) & u64::MAX));
        { let v = f64::from_bits(v42); f[2] = f[2] - v; }
        f[3] = f64::from_bits(0x0);
        fsw = fcompare_cc(f[3], f[2]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x2800) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(3) { break 'b19; }
        // block 18
        f[2] = f[2] * f[2];
        f[3] = f64::from_bits((((s2005 >> 16) | (s2006 << 48)) & u64::MAX));
        { let v = f64::from_bits(v51); f[3] = f[3] + v; }
        f[3] = f[3] * f[3];
        f[2] = f[2] + f[3];
        f[2] = f[2].sqrt();
        { let v = f64::from_bits(v34); f[2] = f[2] + v; }
        break 'b20;
        } // 'b19
        // block 19
        f[2] = f[2] * f[2];
        f[3] = f64::from_bits((((s2005 >> 16) | (s2006 << 48)) & u64::MAX));
        { let v = f64::from_bits(v53); f[3] = f[3] + v; }
        f[3] = f[3] * f[3];
        f[2] = f[2] + f[3];
        f[2] = f[2].sqrt();
        { let v = f64::from_bits(v52); f[2] = f[2] - v; }
        } // 'b20
        // block 20
        f[2] = f[2] * f[2];
        f[3] = f64::from_bits((((s2006 >> 16) | (s2007 << 48)) & u64::MAX));
        f[3] = f[3] * f[3];
        f[2] = f[2] + f[3];
        f[2] = f[2].sqrt();
        { let v = f64::from_bits(v36); f[2] = f[2] - v; }
        fsw = fcompare_cc(f[2], f[1]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x2800) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(6) { break 'b22; }
        // block 21
        f[2] = f[2];
        break 'b23;
        } // 'b22
        // block 22
        f[1] = f[2];
        } // 'b23
        // block 23
        f[2] = f64::from_bits((((s2010 >> 16) | (s2011 << 48)) & u64::MAX));
        f[2] = -f[2];
        fsw = fcompare_cc(f[2], f[1]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x2800) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(3) { break 'b25; }
        // block 24
        f[2] = f[2];
        break 'b26;
        } // 'b25
        // block 25
        f[1] = f[2];
        } // 'b26
        // block 26
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(6) { break 'b28; }
        // block 27
        f[1] = f[1];
        break 'b29;
        } // 'b28
        // block 28
        f[0] = f[1];
        } // 'b29
        // block 29
        f[1] = f64::from_bits((((s2011 >> 16) | (s2012 << 48)) & u64::MAX));
        f[1] = -f[1];
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(3) { break 'b31; }
        // block 30
        f[1] = f[1];
        break 'b32;
        } // 'b31
        // block 31
        f[0] = f[1];
        } // 'b32
        // block 32
        { let bv = 0x0u32; let av = (((v23 >> 32) & 0xffffffffu64) as u32); let r = fl.alu(Alu::Cmp, av, bv, 4); }
        if fl.cond(5) { break 'b34; }
        // block 33
        { let v = f64::from_bits(v28); f[0] = f[0] / v; }
        } // 'b34
        // block 34
        r14 = f[0].to_bits();
        f[0] = f64::from_bits(v30);
        f[1] = (((r15 >> 0) & 0xffffffffu64) as u32 as i32 as f64);
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        f[0] = f[0].abs();
        r34 = f[0].to_bits();
        { let bv = 0x52u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10001070u32, r14);
    m.wr64u(0x10001100u32, r32);
    m.wr64u(0x10001110u32, r34);
    m.wr64u(0x10007ea8u32, s2005);
    m.wr64u(0x10007eb0u32, s2006);
    m.wr64u(0x10007eb8u32, s2007);
    m.wr64u(0x10007ec0u32, s2008);
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

// LoResTIFS

pub(super) fn f_1e0f9a93662cc139(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<200>(vb.wrapping_add(80))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut r6: u64 = m.rd64u(0x10001030u32);
    let mut r14: u64 = m.rd64u(0x10001070u32);
    let mut r32: u64 = m.rd64u(0x10001100u32);
    let mut r33: u64 = m.rd64u(0x10001108u32);
    let mut r34: u64 = m.rd64u(0x10001110u32);
    let mut s2009: u64 = m.rd64u(0x10007ec8u32);
    let mut s2010: u64 = m.rd64u(0x10007ed0u32);
    let mut s2011: u64 = m.rd64u(0x10007ed8u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
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
        f[0] = f64::from_bits((((s2011 >> 32) | (s2012 << 32)) & u64::MAX));
        f[1] = f64::from_bits((((s2010 >> 32) | (s2011 << 32)) & u64::MAX));
        f[2] = f64::from_bits((((s2009 >> 32) | (s2010 << 32)) & u64::MAX));
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
        { let v: u64 = f[2].to_bits(); s2009 = (s2009 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2010 = (s2010 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        { let v: u64 = f[1].to_bits(); s2010 = (s2010 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2011 = (s2011 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        { let v: u64 = f[0].to_bits(); s2011 = (s2011 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2012 = (s2012 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        f[0] = f64::from_bits((((s2009 >> 32) | (s2010 << 32)) & u64::MAX));
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2010 >> 32) | (s2011 << 32)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[1] = f64::from_bits((((s2011 >> 32) | (s2012 << 32)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits((((v20 >> 32) | (v21 << 32)) & u64::MAX)); f[0] = f[0] - v; }
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
        f[0] = f64::from_bits((((s2011 >> 32) | (s2012 << 32)) & u64::MAX));
        f[1] = f64::from_bits((((s2010 >> 32) | (s2011 << 32)) & u64::MAX));
        f[2] = f64::from_bits((((s2009 >> 32) | (s2010 << 32)) & u64::MAX));
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
        { let v: u64 = f[2].to_bits(); s2009 = (s2009 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2010 = (s2010 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        { let v: u64 = f[1].to_bits(); s2010 = (s2010 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2011 = (s2011 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        { let v: u64 = f[0].to_bits(); s2011 = (s2011 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2012 = (s2012 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        f[0] = f64::from_bits((((s2009 >> 32) | (s2010 << 32)) & u64::MAX));
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2010 >> 32) | (s2011 << 32)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        { let v = f64::from_bits((((v20 >> 32) | (v21 << 32)) & u64::MAX)); f[0] = f[0] - v; }
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2011 >> 32) | (s2012 << 32)) & u64::MAX));
        f[1] = f[1] * f[1];
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
        f[0] = f64::from_bits((((v10 >> 32) | (v11 << 32)) & u64::MAX));
        r34 = f[0].to_bits();
        { let bv = 0x30u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10001070u32, r14);
    m.wr64u(0x10001100u32, r32);
    m.wr64u(0x10001110u32, r34);
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

// ScherkIFS

pub(super) fn f_23cd7b4f83b9f0ef(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<160>(vb.wrapping_add(104))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut r6: u64 = m.rd64u(0x10001030u32);
    let mut r14: u64 = m.rd64u(0x10001070u32);
    let mut r15: u64 = m.rd64u(0x10001078u32);
    let mut r32: u64 = m.rd64u(0x10001100u32);
    let mut r33: u64 = m.rd64u(0x10001108u32);
    let mut r34: u64 = m.rd64u(0x10001110u32);
    let mut s2003: u64 = m.rd64u(0x10007e98u32);
    let mut s2004: u64 = m.rd64u(0x10007ea0u32);
    let mut s2005: u64 = m.rd64u(0x10007ea8u32);
    let mut s2006: u64 = m.rd64u(0x10007eb0u32);
    let mut s2007: u64 = m.rd64u(0x10007eb8u32);
    let mut s2008: u64 = m.rd64u(0x10007ec0u32);
    let mut s2009: u64 = m.rd64u(0x10007ec8u32);
    let mut s2010: u64 = m.rd64u(0x10007ed0u32);
    let mut v13: u64 = cell(vm, 0);
    let mut v14: u64 = cell(vm, 8);
    let mut v15: u64 = cell(vm, 16);
    let mut v16: u64 = cell(vm, 24);
    let mut v17: u64 = cell(vm, 32);
    let mut v18: u64 = cell(vm, 40);
    let mut v19: u64 = cell(vm, 48);
    let mut v20: u64 = cell(vm, 56);
    let mut v21: u64 = cell(vm, 64);
    let mut v22: u64 = cell(vm, 72);
    let mut v23: u64 = cell(vm, 80);
    let mut v24: u64 = cell(vm, 88);
    let mut v25: u64 = cell(vm, 96);
    let mut v26: u64 = cell(vm, 104);
    let mut v27: u64 = cell(vm, 112);
    let mut v28: u64 = cell(vm, 120);
    let mut v29: u64 = cell(vm, 128);
    let mut v30: u64 = cell(vm, 136);
    let mut v32: u64 = cell(vm, 152);
    'body: {
        'b13: {
        'b11: {
        'b10: {
        'b8: {
        'b7: {
        'b5: {
        'b4: {
        'b2: {
        // block 0
        { let bv = 0xffffff9cu32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        m.xmm[0] = [r3, r4];
        { let s: u64 = r5; m.xmm[1] = [s, 0]; }
        { let s: [u64; 2] = [v28, v29]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) * f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) * f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v28; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        { let s: [u64; 2] = [v24, v25]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) + f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) + f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v26; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) + f64::from_bits(s)).to_bits(); }
        { let bv = 0x0u32; let av = (((v23 >> 32) & 0xffffffffu64) as u32); let r = fl.alu(Alu::Cmp, av, bv, 4); }
        if fl.cond(4) { break 'b2; }
        // block 1
        { let s: u64 = r32; m.xmm[5] = [s, 0]; }
        { let s: u64 = v28; let a = m.xmm[5][0]; m.xmm[5][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        r3 = m.xmm[0][0]; r4 = m.xmm[0][1];
        r5 = m.xmm[1][0];
        r32 = m.xmm[5][0];
        } // 'b2
        // block 2
        s2003 = m.xmm[0][0]; s2004 = m.xmm[0][1];
        s2005 = m.xmm[1][0];
        f[0] = f64::from_bits(s2005);
        f[1] = f64::from_bits(s2004);
        f[2] = f64::from_bits(s2003);
        f[3] = f[2];
        { let v = (f32::from_bits(((v18 >> 0) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[4] = f[1];
        { let v = (f32::from_bits(((v17 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[0];
        { let v = (f32::from_bits(((v17 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[2];
        { let v = (f32::from_bits(((v21 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[5] = f[1];
        { let v = (f32::from_bits(((v20 >> 32) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f[5] = f[0];
        { let v = (f32::from_bits(((v20 >> 0) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f.swap(4, 2);
        { let v = (f32::from_bits(((v19 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f.swap(4, 1);
        { let v = (f32::from_bits(((v19 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[1] = f[1] + f[4];
        f.swap(3, 0);
        { let v = (f32::from_bits(((v18 >> 32) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[1] = f[1] + f[3];
        s2003 = f[2].to_bits();
        s2004 = f[1].to_bits();
        s2005 = f[0].to_bits();
        f[0] = f64::from_bits(s2003);
        f[1] = f64::from_bits(v14);
        s2009 = f[1].to_bits();
        f[2] = f64::from_bits(v32);
        fsw = fcompare_cc(f[2], f[1]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(2) { break 'b4; }
        // block 3
        f[1] = f64::from_bits(v32);
        { let v = f64::from_bits(v14); f[1] = f[1] - v; }
        { let v = f64::from_bits(v32); f[1] = f[1] + v; }
        s2009 = f[1].to_bits();
        f[0] = f[0] * f[1];
        break 'b5;
        } // 'b4
        // block 4
        f[0] = f[0].sin(); fsw &= !0x0400;
        { let v = f64::from_bits(v14); f[0] = f[0] * v; }
        } // 'b5
        // block 5
        f[1] = f64::from_bits(0x3ff71547652b82fe);
        f[0] = f[0] * f[1];
        f[1] = f64::from_bits(0x3ff0000000000000);
        f[2] = f[0];
        { let (x, y) = (f[2], f[1]); let q = if false { (x / y).round_ties_even() } else { (x / y).trunc() }; f[2] = if false { x - q * y } else { x % y }; let qi = q.abs() as u64; fsw = (if qi & 4 != 0 { 0x0100 } else { 0 }) | (if qi & 2 != 0 { 0x4000 } else { 0 }) | (if qi & 1 != 0 { 0x0200 } else { 0 }); }
        f[2] = f[2].exp2() - 1.0;
        f[1] = f[1] + f[2];
        f[1] *= f[0].trunc().exp2();
        f.swap(1, 0);
        f[1] = f[1];
        s2003 = f[0].to_bits();
        f[1] = f64::from_bits(s2004);
        f[2] = f64::from_bits(v13);
        s2010 = f[2].to_bits();
        f[3] = f64::from_bits(v32);
        fsw = fcompare_cc(f[3], f[2]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(2) { break 'b7; }
        // block 6
        f[2] = f64::from_bits(v32);
        { let v = f64::from_bits(v13); f[2] = f[2] - v; }
        { let v = f64::from_bits(v32); f[2] = f[2] + v; }
        s2010 = f[2].to_bits();
        f[1] = f[1] * f[2];
        break 'b8;
        } // 'b7
        // block 7
        f[1] = f[1].sin(); fsw &= !0x0400;
        { let v = f64::from_bits(v13); f[1] = f[1] * v; }
        } // 'b8
        // block 8
        f[2] = f64::from_bits(0x3ff71547652b82fe);
        f[1] = f[1] * f[2];
        f[2] = f64::from_bits(0x3ff0000000000000);
        f[3] = f[1];
        { let (x, y) = (f[3], f[2]); let q = if false { (x / y).round_ties_even() } else { (x / y).trunc() }; f[3] = if false { x - q * y } else { x % y }; let qi = q.abs() as u64; fsw = (if qi & 4 != 0 { 0x0100 } else { 0 }) | (if qi & 2 != 0 { 0x4000 } else { 0 }) | (if qi & 1 != 0 { 0x0200 } else { 0 }); }
        f[3] = f[3].exp2() - 1.0;
        f[2] = f[2] + f[3];
        f[2] *= f[1].trunc().exp2();
        f.swap(2, 1);
        f[2] = f[2];
        s2004 = f[1].to_bits();
        f[0] = f[0] * f[1];
        s2006 = f[0].to_bits();
        f[0] = f64::from_bits(s2003);
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits(s2004);
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        s2007 = f[0].to_bits();
        f[0] = f64::from_bits(s2006);
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits(0x3ff0000000000000);
        f[0] = f[0] + f[1];
        s2008 = f[0].to_bits();
        f[0] = f64::from_bits(s2005);
        f[0] = f[0].sin(); fsw &= !0x0400;
        { let v = f64::from_bits(v16); f[0] = f[0] * v; }
        { let v = f64::from_bits(s2006); f[0] = f[0] * v; }
        f[1] = f64::from_bits(0x0);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(3) { break 'b10; }
        // block 9
        { let v = f64::from_bits(s2007); f[0] = f[0] + v; }
        { let v = f64::from_bits(s2008); f[0] = f[0] / v; }
        break 'b11;
        } // 'b10
        // block 10
        f[0] = -f[0];
        { let v = f64::from_bits(s2008); f[0] = f[0] + v; }
        f[1] = f64::from_bits(s2007);
        f[0] = f[1] / f[0];
        } // 'b11
        // block 11
        f[1] = f64::from_bits(0x3ff71547652b82fe);
        f.swap(1, 0);
        f[0] *= f[1].log2();
        f[0] = f[0].abs();
        f[1] = f64::from_bits(s2009);
        f[1] = f[1] * f[1];
        f[2] = f64::from_bits(s2010);
        f[2] = f[2] * f[2];
        f[1] = f[1] + f[2];
        f[1] = f[1].sqrt();
        f[0] = f[0] / f[1];
        { let v = f64::from_bits(v15); f[0] = f[0] - v; }
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let bv = 0x0u32; let av = (((v23 >> 32) & 0xffffffffu64) as u32); let r = fl.alu(Alu::Cmp, av, bv, 4); }
        if fl.cond(5) { break 'b13; }
        // block 12
        { let v = f64::from_bits(v28); f[0] = f[0] / v; }
        } // 'b13
        // block 13
        r14 = f[0].to_bits();
        f[0] = f64::from_bits(v30);
        f[1] = (((r15 >> 0) & 0xffffffffu64) as u32 as i32 as f64);
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        f[0] = f[0].abs();
        r34 = f[0].to_bits();
        { let bv = 0x64u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10001070u32, r14);
    m.wr64u(0x10001100u32, r32);
    m.wr64u(0x10001110u32, r34);
    m.wr64u(0x10007e98u32, s2003);
    m.wr64u(0x10007ea0u32, s2004);
    m.wr64u(0x10007ea8u32, s2005);
    m.wr64u(0x10007eb0u32, s2006);
    m.wr64u(0x10007eb8u32, s2007);
    m.wr64u(0x10007ec0u32, s2008);
    m.wr64u(0x10007ec8u32, s2009);
    m.wr64u(0x10007ed0u32, s2010);
    m.regs = rg;
    m.fl = fl;
    m.fsw_cc = fsw;
    m.st = f;
    Ok(())
}

// ApolloTetraIFS

pub(super) fn f_24c113e431dbc7b7(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<40>(vb.wrapping_add(208))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut r6: u64 = m.rd64u(0x10001030u32);
    let mut r32: u64 = m.rd64u(0x10001100u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut v26: u64 = cell(vm, 0);
    let mut v27: u64 = cell(vm, 8);
    let mut v28: u64 = cell(vm, 16);
    let mut v29: u64 = cell(vm, 24);
    let mut v30: u64 = cell(vm, 32);
    'body: {
        'b27: {
        'b26: {
        'b25: {
        'b23: {
        'b22: {
        'b20: {
        'b18: {
        'b17: {
        'b15: {
        'b14: {
        'b12: {
        'b11: {
        'b9: {
        'b8: {
        'b6: {
        'b5: {
        'b3: {
        'b2: {
        // block 0
        { let bv = 0xffffffe4u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        m.xmm[0] = [r3, r4];
        { let s: u64 = r5; m.xmm[1] = [s, 0]; }
        s2012 = m.xmm[0][0]; s2013 = m.xmm[0][1];
        s2014 = m.xmm[1][0];
        f[0] = f64::from_bits(s2013);
        f[0] = -f[0];
        f[1] = f64::from_bits(s2012);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(4) { break 'b2; }
        // block 1
        f[1] = -f[1];
        s2013 = f[1].to_bits();
        s2012 = f[0].to_bits();
        break 'b3;
        } // 'b2
        // block 2
        f[1] = f[1];
        f[0] = f[0];
        } // 'b3
        // block 3
        f[0] = f64::from_bits(s2014);
        f[0] = -f[0];
        f[1] = f64::from_bits(s2012);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(4) { break 'b5; }
        // block 4
        f[1] = -f[1];
        s2014 = f[1].to_bits();
        s2012 = f[0].to_bits();
        break 'b6;
        } // 'b5
        // block 5
        f[1] = f[1];
        f[0] = f[0];
        } // 'b6
        // block 6
        f[0] = f64::from_bits(s2014);
        f[0] = -f[0];
        f[1] = f64::from_bits(s2013);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(4) { break 'b8; }
        // block 7
        f[1] = -f[1];
        s2014 = f[1].to_bits();
        s2013 = f[0].to_bits();
        break 'b9;
        } // 'b8
        // block 8
        f[1] = f[1];
        f[0] = f[0];
        } // 'b9
        // block 9
        f[0] = f64::from_bits(s2013);
        f[1] = f64::from_bits(s2012);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(4) { break 'b11; }
        // block 10
        s2013 = f[1].to_bits();
        s2012 = f[0].to_bits();
        break 'b12;
        } // 'b11
        // block 11
        f[1] = f[1];
        f[0] = f[0];
        } // 'b12
        // block 12
        f[0] = f64::from_bits(s2014);
        f[1] = f64::from_bits(s2012);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(4) { break 'b14; }
        // block 13
        s2014 = f[1].to_bits();
        s2012 = f[0].to_bits();
        break 'b15;
        } // 'b14
        // block 14
        f[1] = f[1];
        f[0] = f[0];
        } // 'b15
        // block 15
        f[0] = f64::from_bits(s2014);
        f[1] = f64::from_bits(s2013);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(4) { break 'b17; }
        // block 16
        s2014 = f[1].to_bits();
        s2013 = f[0].to_bits();
        break 'b18;
        } // 'b17
        // block 17
        f[1] = f[1];
        f[0] = f[0];
        } // 'b18
        // block 18
        f[0] = f64::from_bits(s2012);
        { let v = f64::from_bits(v30); f[0] = f[0] + v; }
        f[1] = f64::from_bits(s2013);
        { let v = f64::from_bits(v29); f[1] = f[1] + v; }
        f[2] = f64::from_bits(s2014);
        { let v = f64::from_bits(v28); f[2] = f[2] + v; }
        f[3] = f64::from_bits(v27);
        f[4] = f64::from_bits(0x0);
        fsw = fcompare_cc(f[4], f[3]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x2800) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(5) { break 'b20; }
        // block 19
        s2014 = f[2].to_bits();
        s2013 = f[1].to_bits();
        s2012 = f[0].to_bits();
        break 'b27;
        } // 'b20
        // block 20
        s2014 = f[2].to_bits();
        f[2] = f[2] * f[2];
        f.swap(2, 1);
        s2013 = f[2].to_bits();
        f[2] = f[2] * f[2];
        f.swap(2, 0);
        s2012 = f[2].to_bits();
        f[2] = f[2] * f[2];
        f[1] = f[1] + f[2];
        f[0] = f[0] + f[1];
        f[1] = f64::from_bits(v26);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(5) { break 'b22; }
        // block 21
        f[0] = f[1];
        break 'b23;
        } // 'b22
        // block 22
        f[1] = f[1];
        } // 'b23
        // block 23
        f[1] = f64::from_bits(0x3ff0000000000000);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(4) { break 'b25; }
        // block 24
        f[0] = f[1];
        break 'b26;
        } // 'b25
        // block 25
        f[1] = f[1];
        } // 'b26
        // block 26
        f[1] = f64::from_bits(v27);
        f[1] = f[1].abs();
        f[0] = f[1] / f[0];
        f[1] = f[0];
        { let v = f64::from_bits(s2012); f[1] = f[1] * v; }
        s2012 = f[1].to_bits();
        f[1] = f[0];
        { let v = f64::from_bits(s2013); f[1] = f[1] * v; }
        s2013 = f[1].to_bits();
        f[1] = f[0];
        { let v = f64::from_bits(s2014); f[1] = f[1] * v; }
        s2014 = f[1].to_bits();
        { let v = f64::from_bits(r32); f[0] = f[0] * v; }
        r32 = f[0].to_bits();
        } // 'b27
        // block 27
        f[0] = f64::from_bits(s2012);
        f[1] = f64::from_bits(s2013);
        f[2] = f64::from_bits(s2014);
        r5 = f[2].to_bits();
        r4 = f[1].to_bits();
        r3 = f[0].to_bits();
        { let bv = 0x1cu32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10001100u32, r32);
    m.wr64u(0x10007ee0u32, s2012);
    m.wr64u(0x10007ee8u32, s2013);
    m.wr64u(0x10007ef0u32, s2014);
    m.regs = rg;
    m.fl = fl;
    m.fsw_cc = fsw;
    m.st = f;
    Ok(())
}

// K-TowerIFS

pub(super) fn f_271e754564d800c8(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<160>(vb.wrapping_add(104))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut r6: u64 = m.rd64u(0x10001030u32);
    let mut r14: u64 = m.rd64u(0x10001070u32);
    let mut r15: u64 = m.rd64u(0x10001078u32);
    let mut r32: u64 = m.rd64u(0x10001100u32);
    let mut r33: u64 = m.rd64u(0x10001108u32);
    let mut r34: u64 = m.rd64u(0x10001110u32);
    let mut s2003: u64 = m.rd64u(0x10007e98u32);
    let mut s2004: u64 = m.rd64u(0x10007ea0u32);
    let mut s2005: u64 = m.rd64u(0x10007ea8u32);
    let mut s2006: u64 = m.rd64u(0x10007eb0u32);
    let mut s2007: u64 = m.rd64u(0x10007eb8u32);
    let mut s2008: u64 = m.rd64u(0x10007ec0u32);
    let mut v13: u64 = cell(vm, 0);
    let mut v14: u64 = cell(vm, 8);
    let mut v15: u64 = cell(vm, 16);
    let mut v16: u64 = cell(vm, 24);
    let mut v17: u64 = cell(vm, 32);
    let mut v18: u64 = cell(vm, 40);
    let mut v19: u64 = cell(vm, 48);
    let mut v20: u64 = cell(vm, 56);
    let mut v21: u64 = cell(vm, 64);
    let mut v22: u64 = cell(vm, 72);
    let mut v23: u64 = cell(vm, 80);
    let mut v24: u64 = cell(vm, 88);
    let mut v25: u64 = cell(vm, 96);
    let mut v26: u64 = cell(vm, 104);
    let mut v27: u64 = cell(vm, 112);
    let mut v28: u64 = cell(vm, 120);
    let mut v29: u64 = cell(vm, 128);
    let mut v30: u64 = cell(vm, 136);
    let mut v32: u64 = cell(vm, 152);
    'body: {
        'b7: {
        'b5: {
        'b4: {
        'b2: {
        // block 0
        { let bv = 0xffffff9cu32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        m.xmm[0] = [r3, r4];
        { let s: u64 = r5; m.xmm[1] = [s, 0]; }
        { let s: [u64; 2] = [v28, v29]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) * f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) * f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v28; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        { let s: [u64; 2] = [v24, v25]; let a = m.xmm[0]; m.xmm[0] = [(f64::from_bits(a[0]) + f64::from_bits(s[0])).to_bits(), (f64::from_bits(a[1]) + f64::from_bits(s[1])).to_bits()]; }
        { let s: u64 = v26; let a = m.xmm[1][0]; m.xmm[1][0] = (f64::from_bits(a) + f64::from_bits(s)).to_bits(); }
        { let bv = 0x0u32; let av = (((v23 >> 32) & 0xffffffffu64) as u32); let r = fl.alu(Alu::Cmp, av, bv, 4); }
        if fl.cond(4) { break 'b2; }
        // block 1
        { let s: u64 = r32; m.xmm[5] = [s, 0]; }
        { let s: u64 = v28; let a = m.xmm[5][0]; m.xmm[5][0] = (f64::from_bits(a) * f64::from_bits(s)).to_bits(); }
        r3 = m.xmm[0][0]; r4 = m.xmm[0][1];
        r5 = m.xmm[1][0];
        r32 = m.xmm[5][0];
        } // 'b2
        // block 2
        s2003 = m.xmm[0][0]; s2004 = m.xmm[0][1];
        s2005 = m.xmm[1][0];
        f[0] = f64::from_bits(s2005);
        f[1] = f64::from_bits(s2004);
        f[2] = f64::from_bits(s2003);
        f[3] = f[2];
        { let v = (f32::from_bits(((v18 >> 0) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[4] = f[1];
        { let v = (f32::from_bits(((v17 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[0];
        { let v = (f32::from_bits(((v17 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[2];
        { let v = (f32::from_bits(((v21 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[5] = f[1];
        { let v = (f32::from_bits(((v20 >> 32) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f[5] = f[0];
        { let v = (f32::from_bits(((v20 >> 0) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f.swap(4, 2);
        { let v = (f32::from_bits(((v19 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f.swap(4, 1);
        { let v = (f32::from_bits(((v19 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[1] = f[1] + f[4];
        f.swap(3, 0);
        { let v = (f32::from_bits(((v18 >> 32) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[1] = f[1] + f[3];
        s2003 = f[2].to_bits();
        s2004 = f[1].to_bits();
        s2005 = f[0].to_bits();
        f[0] = f64::from_bits(s2003);
        f[1] = f64::from_bits(s2004);
        f[0] = f[0].atan2(f[1]);
        { let v = f64::from_bits(v13); f[0] = f[0] * v; }
        { let (s, c) = f[0].sin_cos(); f[0] = s; f[1] = c; fsw &= !0x0400; }
        s2006 = f[1].to_bits();
        s2007 = f[0].to_bits();
        f[0] = f64::from_bits(s2003);
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits(s2004);
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        f[1] = f[0];
        { let v = f64::from_bits(s2006); f[1] = f[1] * v; }
        s2004 = f[1].to_bits();
        { let v = f64::from_bits(s2007); f[0] = f[0] * v; }
        { let v = f64::from_bits(v14); f[0] = f[0] * v; }
        f[1] = f64::from_bits(0x3ff71547652b82fe);
        f[0] = f[0] * f[1];
        f[1] = f64::from_bits(0x3ff0000000000000);
        f[2] = f[0];
        { let (x, y) = (f[2], f[1]); let q = if false { (x / y).round_ties_even() } else { (x / y).trunc() }; f[2] = if false { x - q * y } else { x % y }; let qi = q.abs() as u64; fsw = (if qi & 4 != 0 { 0x0100 } else { 0 }) | (if qi & 2 != 0 { 0x4000 } else { 0 }) | (if qi & 1 != 0 { 0x0200 } else { 0 }); }
        f[2] = f[2].exp2() - 1.0;
        f[1] = f[1] + f[2];
        f[1] *= f[0].trunc().exp2();
        f.swap(1, 0);
        f[1] = f[1];
        s2003 = f[0].to_bits();
        f[1] = f64::from_bits(s2004);
        { let v = f64::from_bits(v14); f[1] = f[1] * v; }
        f[2] = f64::from_bits(0x3ff71547652b82fe);
        f[1] = f[1] * f[2];
        f[2] = f64::from_bits(0x3ff0000000000000);
        f[3] = f[1];
        { let (x, y) = (f[3], f[2]); let q = if false { (x / y).round_ties_even() } else { (x / y).trunc() }; f[3] = if false { x - q * y } else { x % y }; let qi = q.abs() as u64; fsw = (if qi & 4 != 0 { 0x0100 } else { 0 }) | (if qi & 2 != 0 { 0x4000 } else { 0 }) | (if qi & 1 != 0 { 0x0200 } else { 0 }); }
        f[3] = f[3].exp2() - 1.0;
        f[2] = f[2] + f[3];
        f[2] *= f[1].trunc().exp2();
        f.swap(2, 1);
        f[2] = f[2];
        s2004 = f[1].to_bits();
        f[0] = f[0] * f[1];
        s2006 = f[0].to_bits();
        f[0] = f64::from_bits(s2003);
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits(s2004);
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        s2007 = f[0].to_bits();
        f[0] = f64::from_bits(s2006);
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits(0x3ff0000000000000);
        f[0] = f[0] + f[1];
        s2008 = f[0].to_bits();
        f[0] = f64::from_bits(s2005);
        f[0] = f[0].sin(); fsw &= !0x0400;
        { let v = f64::from_bits(v16); f[0] = f[0] * v; }
        { let v = f64::from_bits(s2006); f[0] = f[0] * v; }
        f[1] = f64::from_bits(0x0);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(3) { break 'b4; }
        // block 3
        { let v = f64::from_bits(s2007); f[0] = f[0] + v; }
        { let v = f64::from_bits(s2008); f[0] = f[0] / v; }
        break 'b5;
        } // 'b4
        // block 4
        f[0] = -f[0];
        { let v = f64::from_bits(s2008); f[0] = f[0] + v; }
        f[1] = f64::from_bits(s2007);
        f[0] = f[1] / f[0];
        } // 'b5
        // block 5
        f[1] = f64::from_bits(0x3ff71547652b82fe);
        f.swap(1, 0);
        f[0] *= f[1].log2();
        { let v = f64::from_bits(v14); f[0] = f[0] / v; }
        f[0] = f[0].abs();
        { let v = f64::from_bits(v15); f[0] = f[0] - v; }
        { let v = f64::from_bits(v32); f[0] = f[0] * v; }
        { let bv = 0x0u32; let av = (((v23 >> 32) & 0xffffffffu64) as u32); let r = fl.alu(Alu::Cmp, av, bv, 4); }
        if fl.cond(5) { break 'b7; }
        // block 6
        { let v = f64::from_bits(v28); f[0] = f[0] / v; }
        } // 'b7
        // block 7
        r14 = f[0].to_bits();
        f[0] = f64::from_bits(v30);
        f[1] = (((r15 >> 0) & 0xffffffffu64) as u32 as i32 as f64);
        { let v = f64::from_bits((((v22 >> 32) | (v23 << 32)) & u64::MAX)); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        f[0] = f[0].abs();
        r34 = f[0].to_bits();
        { let bv = 0x64u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10001070u32, r14);
    m.wr64u(0x10001100u32, r32);
    m.wr64u(0x10001110u32, r34);
    m.wr64u(0x10007e98u32, s2003);
    m.wr64u(0x10007ea0u32, s2004);
    m.wr64u(0x10007ea8u32, s2005);
    m.wr64u(0x10007eb0u32, s2006);
    m.wr64u(0x10007eb8u32, s2007);
    m.wr64u(0x10007ec0u32, s2008);
    m.regs = rg;
    m.fl = fl;
    m.fsw_cc = fsw;
    m.st = f;
    Ok(())
}

// _Simplex3DShift

pub(super) fn f_29261967e8153d83(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
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
                { let v = rg[7]; push_lu(m, &mut rg, v); }
                { let v = rg[6]; push_lu(m, &mut rg, v); }
                { let v = rg[3]; push_lu(m, &mut rg, v); }
                { let bv = 0xd4u32; let av = rg[4]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[4] = r; }
                rg[0] = m.rd32u(rg[4].wrapping_add(0xe8u32));
                rg[0] = m.rd32u(rg[0].wrapping_add(0x30u32));
                { let a = rg[4].wrapping_add(0x6cu32); m.wr32u(a, rg[0]); }
                
                rg[3] = m.rd32u(rg[4].wrapping_add(0xe8u32));
                f[0] = m.rdf64u(rg[0].wrapping_add(0xffffffe8u32));
                f[1] = m.rdf64u(rg[3].wrapping_add(0xffffffe0u32));
                f[1] = f[1] * f[0];
                { let v = m.rdf64u(rg[0].wrapping_add(0xffffffe0u32)); f[1] = f[1] - v; }
                f[2] = m.rdf64u(rg[3].wrapping_add(0xffffffe8u32));
                f[2] = f[2] * f[0];
                { let v = m.rdf64u(rg[0].wrapping_add(0xffffffd8u32)); f[2] = f[2] - v; }
                f.swap(2, 0);
                { let v = m.rdf64u(rg[3].wrapping_add(0xfffffff0u32)); f[2] = f[2] * v; }
                rg[3] = rg[0];
                { let v = m.rdf64u(rg[0].wrapping_add(0xffffffd0u32)); f[2] = f[2] - v; }
                f[3] = f[1];
                f[3] = f[3] + f[0];
                f[3] = f[3] + f[2];
                { let v = m.rdf64u(rg[0].wrapping_add(0x0u32)); f[3] = f[3] * v; }
                
                if let Op::Gen(ins, nx, at) = &p.ops[26] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // FnstcwMem(Mem { base: Some(4), index: None, disp: 200 })
                { let v = (m.rd16u(rg[4].wrapping_add(0xc8u32)) as u32); reg_set(&mut rg, 0, 2, v); }
                { let bv = 0x4u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::Or, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
                { let v = reg_get(&rg, 0, 2); { let a = rg[4].wrapping_add(0xc0u32); m.wr16u(a, v as u16); } }
                if let Op::Gen(ins, nx, at) = &p.ops[30] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // FldcwMem(Mem { base: Some(4), index: None, disp: 192 })
                rg[0] = m.rd32u(rg[4].wrapping_add(0xc8u32));
                f[4] = f[1];
                f[4] = f[4] + f[3];
                { let a = rg[4].wrapping_add(0xb8u32); m.wrf64u(a, f[4]); }
                f[4] = m.rdf64u(rg[4].wrapping_add(0xb8u32));
                { let a = rg[4].wrapping_add(0xc8u32); m.fstoreu(FKind::I32, a, f[4]); }
                rg[1] = m.rd32u(rg[4].wrapping_add(0xc8u32));
                { let a = rg[4].wrapping_add(0x68u32); m.wr32u(a, rg[1]); }
                f[4] = m.floadu(FKind::I32, rg[4].wrapping_add(0x68u32));
                f[5] = f[0];
                f[5] = f[5] + f[3];
                { let a = rg[4].wrapping_add(0xc0u32); m.wrf64u(a, f[5]); }
                f[5] = m.rdf64u(rg[4].wrapping_add(0xc0u32));
                { let a = rg[4].wrapping_add(0xc8u32); m.fstoreu(FKind::I32, a, f[5]); }
                rg[1] = m.rd32u(rg[4].wrapping_add(0xc8u32));
                { let a = rg[4].wrapping_add(0x54u32); m.wr32u(a, rg[1]); }
                f[5] = m.floadu(FKind::I32, rg[4].wrapping_add(0x54u32));
                f.swap(5, 3);
                f[5] = f[5] + f[2];
                { let a = rg[4].wrapping_add(0xc8u32); m.wrf64u(a, f[5]); }
                f[5] = m.rdf64u(rg[4].wrapping_add(0xc8u32));
                { let a = rg[4].wrapping_add(0xb4u32); m.fstoreu(FKind::I32, a, f[5]); }
                rg[1] = m.rd32u(rg[4].wrapping_add(0xb4u32));
                { let v = reg_get(&rg, 0, 2); { let a = rg[4].wrapping_add(0xb4u32); m.wr16u(a, v as u16); } }
                { let a = rg[4].wrapping_add(0x38u32); m.wr32u(a, rg[1]); }
                f[5] = m.floadu(FKind::I32, rg[4].wrapping_add(0x38u32));
                if let Op::Gen(ins, nx, at) = &p.ops[57] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // FldcwMem(Mem { base: Some(4), index: None, disp: 180 })
                f[6] = m.rdf64u(rg[3].wrapping_add(0x8u32));
                f[7] = f[4];
                f[7] = f[7] + f[3];
                { let bv = rg[2]; let av = rg[2]; let r = fl.alu(Alu::Xor, av, bv, 4); rg[2] = r; }
                { let v = 0x1u32; rg[3] = v; }
                rg[6] = rg[3];
                f[7] = f[7] + f[5];
                f[7] = f[7] * f[6];
                f.swap(7, 1);
                f[4] = f[7] - f[4];
                f.swap(6, 4);
                f[6] = f[6] + f[1];
                f.swap(6, 3);
                f[0] = f[0] - f[6];
                f.swap(5, 0);
                f[5] = f[5] + f[1];
                f.swap(5, 2);
                f[0] = f[5] - f[0];
                f.swap(4, 0);
                f[1] = f[1] + f[4];
                f.swap(3, 2);
                fsw = fcompare_cc(f[3], f[2]);
                rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x2000) as u32;
                f.swap(3, 1);
                { let bv = 0x5u32; let av = reg_get(&rg, 4, 1); fl.alu(Alu::And, av, bv, 1); }
                if let Op::Gen(ins, nx, at) = &p.ops[83] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Setcc { cc: 5, dst: Reg(2) }
                fsw = fcompare_cc(f[3], f[1]);
                rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x2000) as u32;
                f.swap(3, 2);
                { let bv = rg[1]; let av = rg[1]; let r = fl.alu(Alu::Xor, av, bv, 4); rg[1] = r; }
                { let bv = 0x5u32; let av = reg_get(&rg, 4, 1); fl.alu(Alu::And, av, bv, 1); }
                fsw = fcompare_cc(f[3], f[2]);
                rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x2000) as u32;
                if let Op::Gen(ins, nx, at) = &p.ops[91] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Setcc { cc: 5, dst: Reg(1) }
                { let bv = 0x5u32; let av = reg_get(&rg, 4, 1); fl.alu(Alu::And, av, bv, 1); }
                if let Op::Gen(ins, nx, at) = &p.ops[93] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // Setcc { cc: 5, dst: Reg(0) }
                { let bv = 0xffu32; let av = rg[0]; let r = fl.alu(Alu::And, av, bv, 4); rg[0] = r; }
                { let bv = rg[0]; let av = rg[6]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[6] = r; }
                rg[7] = rg[6];
                rg[6] = rg[3];
                { let bv = rg[1]; let av = rg[3]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[3] = r; }
                { let bv = rg[2]; let av = rg[6]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[6] = r; }
                if let Op::Gen(ins, nx, at) = &p.ops[100] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // IMul2 { reg: 3, src: Reg(0) }
                f[4] = f64::from_bits(0x3ff0000000000000);
                { let a = rg[4].wrapping_add(0x48u32); m.wr32u(a, rg[3]); }
                rg[3] = rg[2].wrapping_add(0xffffffffu32);
                if let Op::Gen(ins, nx, at) = &p.ops[104] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // IMul2 { reg: 3, src: Reg(0) }
                { let cf = fl.cf; let r = fl.alu(Alu::Add, rg[3], 1, 4); fl.cf = cf; rg[3] = r; }
                { let cf = fl.cf; let r = fl.alu(Alu::Sub, rg[0], 1, 4); fl.cf = cf; rg[0] = r; }
                { let a = rg[4].wrapping_add(0x3cu32); m.wr32u(a, rg[3]); }
                rg[3] = rg[1].wrapping_add(0xffffffffu32);
                if let Op::Gen(ins, nx, at) = &p.ops[109] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // IMul2 { reg: 7, src: Reg(2) }
                if let Op::Gen(ins, nx, at) = &p.ops[110] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // IMul2 { reg: 2, src: Reg(3) }
                if let Op::Gen(ins, nx, at) = &p.ops[111] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // IMul2 { reg: 6, src: Reg(1) }
                if let Op::Gen(ins, nx, at) = &p.ops[112] { { m.regs = rg; m.fl = fl; m.fsw_cc = fsw; m.steps = steps; let res = m.exec(ins, *nx, *at); rg = m.regs; fl = m.fl; fsw = m.fsw_cc; steps = m.steps; res?; } } // IMul2 { reg: 1, src: Reg(0) }
                f[5] = f[0];
                f[5] = f[5] + f[3];
                rg[3] = rg[2].wrapping_add(0x1u32);
                rg[5] = rg[6];
                { let a = rg[4].wrapping_add(0x4cu32); m.wr32u(a, rg[3]); }
                rg[0] = rg[1].wrapping_add(0x1u32);
                { let bv = rg[7]; let av = rg[7]; fl.alu(Alu::And, av, bv, 4); }
                { let a = rg[4].wrapping_add(0x20u32); m.wrf64u(a, f[5]); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 2; continue; }
                b = 1;
            }
            1 => {
                f[5] = f[5] - f[4];
                { let a = rg[4].wrapping_add(0x20u32); m.wrf64u(a, f[5]); }
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 3; continue;
            }
            2 => {
                f[5] = f[5];
                b = 3;
            }
            3 => {
                f[5] = f[0];
                f[5] = f[5] + f[1];
                { let bv = rg[5]; let av = rg[5]; fl.alu(Alu::And, av, bv, 4); }
                { let a = rg[4].wrapping_add(0x30u32); m.wrf64u(a, f[5]); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 5; continue; }
                b = 4;
            }
            4 => {
                f[5] = f[5] - f[4];
                { let a = rg[4].wrapping_add(0x30u32); m.wrf64u(a, f[5]); }
                f.swap(4, 0);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 6; continue;
            }
            5 => {
                f[5] = f[5];
                f.swap(4, 0);
                b = 6;
            }
            6 => {
                f[4] = f[4] + f[2];
                rg[3] = m.rd32u(rg[4].wrapping_add(0x48u32));
                { let bv = rg[3]; let av = rg[3]; fl.alu(Alu::And, av, bv, 4); }
                { let a = rg[4].wrapping_add(0x28u32); m.wrf64u(a, f[4]); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 8; continue; }
                b = 7;
            }
            7 => {
                f[4] = f[4] - f[0];
                { let a = rg[4].wrapping_add(0x28u32); m.wrf64u(a, f[4]); }
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 9; continue;
            }
            8 => {
                f[4] = f[4];
                b = 9;
            }
            9 => {
                rg[3] = m.rd32u(rg[4].wrapping_add(0x6cu32));
                rg[1] = m.rd32u(rg[4].wrapping_add(0x3cu32));
                { let bv = rg[1]; let av = rg[1]; fl.alu(Alu::And, av, bv, 4); }
                f[4] = m.rdf64u(rg[3].wrapping_add(0x0u32));
                f[5] = f[3];
                f[5] = f[5] + f[4];
                { let a = rg[4].wrapping_add(0x80u32); m.wrf64u(a, f[5]); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 11; continue; }
                b = 10;
            }
            10 => {
                f[5] = f[5] - f[0];
                { let a = rg[4].wrapping_add(0x80u32); m.wrf64u(a, f[5]); }
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 12; continue;
            }
            11 => {
                f[5] = f[5];
                b = 12;
            }
            12 => {
                f[5] = f[1];
                f[5] = f[5] + f[4];
                rg[2] = m.rd32u(rg[4].wrapping_add(0x4cu32));
                { let bv = rg[2]; let av = rg[2]; fl.alu(Alu::And, av, bv, 4); }
                { let a = rg[4].wrapping_add(0x90u32); m.wrf64u(a, f[5]); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 14; continue; }
                b = 13;
            }
            13 => {
                f[5] = f[5] - f[0];
                { let a = rg[4].wrapping_add(0x90u32); m.wrf64u(a, f[5]); }
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 15; continue;
            }
            14 => {
                f[5] = f[5];
                b = 15;
            }
            15 => {
                f[4] = f[4] + f[2];
                { let bv = rg[0]; let av = rg[0]; fl.alu(Alu::And, av, bv, 4); }
                { let a = rg[4].wrapping_add(0x88u32); m.wrf64u(a, f[4]); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 17; continue; }
                b = 16;
            }
            16 => {
                f[0] = f[4] - f[0];
                f.swap(3, 0);
                { let a = rg[4].wrapping_add(0x88u32); m.wrf64u(a, f[3]); }
                f.swap(2, 1);
                f.swap(2, 0);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 18; continue;
            }
            17 => {
                f[4] = f[4];
                f[0] = f[3];
                f.swap(2, 1);
                f.swap(2, 0);
                b = 18;
            }
            18 => {
                f[3] = f64::from_bits(0x0);
                rg[3] = m.rd32u(rg[4].wrapping_add(0x6cu32));
                rg[1] = m.rd32u(rg[4].wrapping_add(0x68u32));
                { let a = rg[4].wrapping_add(0x0u32); m.wrf64u(a, f[3]); }
                f[3] = m.rdf64u(rg[3].wrapping_add(0x10u32));
                f[4] = f[2];
                f[4] = f[4] + f[3];
                rg[2] = m.rd32u(rg[4].wrapping_add(0x3cu32));
                { let bv = rg[1]; let av = rg[2]; let r = fl.alu(Alu::Add, av, bv, 4); rg[2] = r; }
                rg[6] = m.rd32u(rg[4].wrapping_add(0x38u32));
                { let a = rg[4].wrapping_add(0xa0u32); m.wr32u(a, rg[2]); }
                rg[2] = m.rd32u(rg[4].wrapping_add(0x4cu32));
                { let bv = m.rd32u(rg[4].wrapping_add(0x54u32)); let av = rg[2]; let r = fl.alu(Alu::Add, av, bv, 4); rg[2] = r; }
                { let bv = rg[1]; let av = rg[7]; let r = fl.alu(Alu::Add, av, bv, 4); rg[7] = r; }
                { let a = rg[4].wrapping_add(0x70u32); m.wrf64u(a, f[4]); }
                f[4] = f[0];
                f[4] = f[4] + f[3];
                { let a = rg[4].wrapping_add(0xa4u32); m.wr32u(a, rg[2]); }
                rg[2] = rg[0];
                { let bv = rg[6]; let av = rg[2]; let r = fl.alu(Alu::Add, av, bv, 4); rg[2] = r; }
                { let a = rg[4].wrapping_add(0xa8u32); m.wr32u(a, rg[2]); }
                { let a = rg[4].wrapping_add(0x58u32); m.wrf64u(a, f[4]); }
                f[4] = f[1];
                f[4] = f[4] + f[3];
                { let a = rg[4].wrapping_add(0x60u32); m.wrf64u(a, f[4]); }
                f[4] = m.rdf64u(rg[3].wrapping_add(0xffffffb8u32));
                f[5] = f[0];
                f[5] = f[5] * f[0];
                rg[3] = m.rd32u(rg[4].wrapping_add(0x54u32));
                { let a = rg[4].wrapping_add(0xacu32); m.wr32u(a, rg[3]); }
                { let bv = rg[3]; let av = rg[3]; let r = fl.alu(Alu::Xor, av, bv, 4); rg[3] = r; }
                f[6] = f[2];
                f[6] = f[6] * f[2];
                f[5] = f[5] + f[6];
                f[6] = f[1];
                f[6] = f[6] * f[1];
                f[5] = f[5] + f[6];
                f[5] = f[4] - f[5];
                f[6] = m.rdf64u(rg[4].wrapping_add(0x30u32));
                f[7] = f[6];
                f[6] = f[6] * f[7];
                f[7] = m.rdf64u(rg[4].wrapping_add(0x20u32));
                f[7] = f[7] * f[7];
                f[6] = f[6] + f[7];
                f[7] = m.rdf64u(rg[4].wrapping_add(0x28u32));
                f[7] = f[7] * f[7];
                f[6] = f[6] + f[7];
                f[6] = f[4] - f[6];
                { let a = rg[4].wrapping_add(0x40u32); m.wrf64u(a, f[6]); }
                f[6] = m.rdf64u(rg[4].wrapping_add(0x90u32));
                f[7] = f[6];
                f[6] = f[6] * f[7];
                f[7] = m.rdf64u(rg[4].wrapping_add(0x80u32));
                f[7] = f[7] * f[7];
                f[6] = f[6] + f[7];
                f[7] = m.rdf64u(rg[4].wrapping_add(0x88u32));
                f[7] = f[7] * f[7];
                f[6] = f[6] + f[7];
                f[6] = f[4] - f[6];
                { let a = rg[4].wrapping_add(0x98u32); m.wrf64u(a, f[6]); }
                f[6] = m.rdf64u(rg[4].wrapping_add(0x70u32));
                f[7] = f[6];
                f[6] = f[6] * f[7];
                f[7] = m.rdf64u(rg[4].wrapping_add(0x58u32));
                f[7] = f[7] * f[7];
                f[6] = f[6] + f[7];
                f[7] = m.rdf64u(rg[4].wrapping_add(0x60u32));
                f[7] = f[7] * f[7];
                f[6] = f[6] + f[7];
                f[4] = f[4] - f[6];
                f.swap(5, 4);
                { let a = rg[4].wrapping_add(0x78u32); m.wrf64u(a, f[5]); }
                f[5] = m.rdf64u(rg[4].wrapping_add(0x0u32));
                { let a = rg[4].wrapping_add(0x8u32); m.wrf64u(a, f[5]); }
                { let a = rg[4].wrapping_add(0x10u32); m.wrf64u(a, f[5]); }
                { let a = rg[4].wrapping_add(0x18u32); m.wrf64u(a, f[5]); }
                { let a = rg[4].wrapping_add(0x4cu32); m.wr32u(a, rg[7]); }
                rg[0] = m.rd32u(rg[4].wrapping_add(0x54u32));
                { let bv = rg[0]; let av = rg[5]; let r = fl.alu(Alu::Add, av, bv, 4); rg[5] = r; }
                rg[2] = m.rd32u(rg[4].wrapping_add(0xacu32));
                { let a = rg[4].wrapping_add(0x50u32); m.wr32u(a, rg[5]); }
                b = 19;
            }
            19 => {
                f[5] = m.rdf64u(rg[4].wrapping_add(0x0u32));
                f.swap(5, 4);
                fsw = fcompare_cc(f[5], f[4]);
                rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x1000) as u32;
                f[4] = f[5];
                { let bv = 0x45u32; let av = reg_get(&rg, 4, 1); fl.alu(Alu::And, av, bv, 1); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 26; continue; }
                b = 20;
            }
            20 => {
                f[4] = f[4];
                f[1] = f[3];
                f[2] = f[2];
                f[0] = f[1];
                b = 21;
            }
            21 => {
                { let bv = rg[3]; let av = rg[3]; fl.alu(Alu::And, av, bv, 4); }
                if fl.cond(5) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 23; continue; }
                b = 22;
            }
            22 => {
                f[1] = m.rdf64u(rg[4].wrapping_add(0x40u32));
                f[2] = m.rdf64u(rg[4].wrapping_add(0x28u32));
                rg[6] = m.rd32u(rg[4].wrapping_add(0x38u32));
                rg[0] = m.rd32u(rg[4].wrapping_add(0x48u32));
                f[3] = m.rdf64u(rg[4].wrapping_add(0x30u32));
                rg[1] = m.rd32u(rg[4].wrapping_add(0x4cu32));
                rg[2] = m.rd32u(rg[4].wrapping_add(0x50u32));
                { let bv = rg[0]; let av = rg[6]; let r = fl.alu(Alu::Add, av, bv, 4); rg[6] = r; }
                { let v = 0x1u32; reg_set(&mut rg, 3, 1, v); }
                f[4] = m.rdf64u(rg[4].wrapping_add(0x20u32));
                f.swap(4, 2);
                f.swap(4, 1);
                f.swap(4, 3);
                f.swap(4, 0);
                f.swap(4, 3);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 19; continue;
            }
            23 => {
                { let bv = 0x1u32; let av = rg[3]; let r = fl.alu(Alu::Cmp, av, bv, 4); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 27; continue; }
                b = 24;
            }
            24 => {
                { let bv = 0x2u32; let av = rg[3]; let r = fl.alu(Alu::Cmp, av, bv, 4); }
                if fl.cond(5) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 28; continue; }
                b = 25;
            }
            25 => {
                rg[0] = m.rd32u(rg[4].wrapping_add(0x68u32));
                { let v = 0x3u32; reg_set(&mut rg, 3, 1, v); }
                f[1] = m.rdf64u(rg[4].wrapping_add(0x78u32));
                rg[1] = rg[0].wrapping_add(0x1u32);
                rg[0] = m.rd32u(rg[4].wrapping_add(0x54u32));
                f[2] = m.rdf64u(rg[4].wrapping_add(0x60u32));
                rg[2] = rg[0].wrapping_add(0x1u32);
                rg[0] = m.rd32u(rg[4].wrapping_add(0x38u32));
                f[3] = m.rdf64u(rg[4].wrapping_add(0x58u32));
                rg[6] = rg[0].wrapping_add(0x1u32);
                f[4] = m.rdf64u(rg[4].wrapping_add(0x70u32));
                f.swap(4, 2);
                f.swap(4, 1);
                f.swap(4, 3);
                f.swap(4, 0);
                f.swap(4, 3);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 19; continue;
            }
            26 => {
                f[5] = f[4];
                f[5] = f[5] * f[4];
                f.swap(5, 4);
                rg[0] = m.rd32u(rg[4].wrapping_add(0x6cu32));
                rg[7] = rg[2];
                rg[5] = (0x0u32).wrapping_add(rg[6].wrapping_mul(4));
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 7, 14, 4);
                { let v = m.rdf64u(rg[0].wrapping_add(0xffffffc0u32)); f[5] = f[5] * v; }
                { let v = m.rdf64u(rg[0].wrapping_add(0xffffffc8u32)); f[5] = f[5] + v; }
                f[4] = f[4] * f[5];
                f[5] = m.rdf64u(rg[0].wrapping_add(0x20u32));
                rg[0] = rg[2];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 0, 10, 4);
                { let bv = rg[0]; let av = rg[7]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[7] = r; }
                rg[0] = rg[6];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 0, 8, 4);
                { let bv = rg[2]; let av = rg[7]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[7] = r; }
                { let bv = rg[5]; let av = rg[0]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[0] = r; }
                { let bv = rg[6]; let av = rg[0]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[0] = r; }
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 0, 4, 4);
                { let bv = rg[6]; let av = rg[0]; let r = fl.alu(Alu::Add, av, bv, 4); rg[0] = r; }
                rg[0] = (rg[6].wrapping_add(0x0u32)).wrapping_add(rg[0].wrapping_mul(4));
                rg[5] = (rg[7].wrapping_add(0x2u32)).wrapping_add(rg[0].wrapping_mul(1));
                rg[0] = rg[2];
                rg[7] = (0x0u32).wrapping_add(rg[2].wrapping_mul(4));
                { let bv = 0x5a5au32; let av = rg[5]; let r = fl.alu(Alu::Xor, av, bv, 4); rg[5] = r; }
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 0, 8, 4);
                { let bv = rg[7]; let av = rg[0]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[0] = r; }
                { let bv = rg[2]; let av = rg[0]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[0] = r; }
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 0, 4, 4);
                { let bv = rg[2]; let av = rg[0]; let r = fl.alu(Alu::Add, av, bv, 4); rg[0] = r; }
                rg[7] = (rg[2].wrapping_add(0x7u32)).wrapping_add(rg[0].wrapping_mul(4));
                rg[2] = rg[1];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 2, 10, 4);
                rg[0] = rg[1];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 0, 14, 4);
                { let bv = rg[2]; let av = rg[0]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[0] = r; }
                rg[2] = rg[0];
                rg[0] = rg[6];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 0, 14, 4);
                { let bv = rg[1]; let av = rg[2]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[2] = r; }
                { let bv = rg[7]; let av = rg[2]; let r = fl.alu(Alu::Add, av, bv, 4); rg[2] = r; }
                rg[7] = rg[6];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 7, 10, 4);
                { let bv = 0x5a5au32; let av = rg[2]; let r = fl.alu(Alu::Xor, av, bv, 4); rg[2] = r; }
                { let bv = rg[7]; let av = rg[0]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[0] = r; }
                rg[7] = (0x0u32).wrapping_add(rg[1].wrapping_mul(4));
                { let bv = rg[6]; let av = rg[0]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[0] = r; }
                rg[6] = rg[0];
                rg[0] = rg[1];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 0, 8, 4);
                { let bv = rg[7]; let av = rg[0]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[0] = r; }
                { let bv = rg[1]; let av = rg[0]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[0] = r; }
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 0, 4, 4);
                { let bv = rg[1]; let av = rg[0]; let r = fl.alu(Alu::Add, av, bv, 4); rg[0] = r; }
                rg[0] = (rg[1].wrapping_add(0x0u32)).wrapping_add(rg[0].wrapping_mul(4));
                rg[1] = (rg[6].wrapping_add(0xbu32)).wrapping_add(rg[0].wrapping_mul(1));
                { let bv = 0x5a5au32; let av = rg[1]; let r = fl.alu(Alu::Xor, av, bv, 4); rg[1] = r; }
                rg[0] = rg[1];
                { let bv = rg[2]; let av = rg[0]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[0] = r; }
                rg[6] = (rg[0].wrapping_add(0x0u32)).wrapping_add(rg[0].wrapping_mul(8));
                rg[7] = (rg[6].wrapping_add(0x0u32)).wrapping_add(rg[6].wrapping_mul(8));
                rg[6] = rg[7];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 6, 4, 4);
                { let bv = rg[7]; let av = rg[6]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[6] = r; }
                { let bv = rg[5]; let av = rg[2]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[2] = r; }
                { let bv = rg[1]; let av = rg[5]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[5] = r; }
                rg[6] = (rg[0].wrapping_add(0x0u32)).wrapping_add(rg[6].wrapping_mul(8));
                rg[6] = (rg[0].wrapping_add(0x0u32)).wrapping_add(rg[6].wrapping_mul(2));
                rg[0] = (rg[0].wrapping_add(0x0u32)).wrapping_add(rg[6].wrapping_mul(4));
                rg[6] = (rg[2].wrapping_add(0x0u32)).wrapping_add(rg[2].wrapping_mul(8));
                rg[7] = (rg[6].wrapping_add(0x0u32)).wrapping_add(rg[6].wrapping_mul(8));
                rg[6] = rg[7];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 6, 4, 4);
                { let bv = rg[7]; let av = rg[6]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[6] = r; }
                rg[6] = (rg[2].wrapping_add(0x0u32)).wrapping_add(rg[6].wrapping_mul(8));
                rg[6] = (rg[2].wrapping_add(0x0u32)).wrapping_add(rg[6].wrapping_mul(2));
                rg[7] = (rg[2].wrapping_add(0x0u32)).wrapping_add(rg[6].wrapping_mul(4));
                rg[2] = (rg[5].wrapping_add(0x0u32)).wrapping_add(rg[5].wrapping_mul(8));
                rg[6] = rg[7];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 6, 4, 4);
                rg[1] = (rg[2].wrapping_add(0x0u32)).wrapping_add(rg[2].wrapping_mul(8));
                { let bv = 0x3fffffffu32; let av = rg[6]; let r = fl.alu(Alu::And, av, bv, 4); rg[6] = r; }
                rg[2] = rg[1];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 2, 4, 4);
                { let a = rg[4].wrapping_add(0x3cu32); m.wr32u(a, rg[6]); }
                f[6] = m.floadu(FKind::I32, rg[4].wrapping_add(0x3cu32));
                f[6] = f[6] * f[5];
                rg[6] = rg[0];
                { let bv = 0x3fffffffu32; let av = rg[6]; let r = fl.alu(Alu::And, av, bv, 4); rg[6] = r; }
                { let bv = rg[1]; let av = rg[2]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[2] = r; }
                { let a = rg[4].wrapping_add(0x3cu32); m.wr32u(a, rg[6]); }
                f[6] = f[6] + f[3];
                rg[2] = (rg[5].wrapping_add(0x0u32)).wrapping_add(rg[2].wrapping_mul(8));
                rg[2] = (rg[5].wrapping_add(0x0u32)).wrapping_add(rg[2].wrapping_mul(2));
                f[6] = f[6] * f[2];
                rg[2] = (rg[5].wrapping_add(0x0u32)).wrapping_add(rg[2].wrapping_mul(4));
                rg[6] = rg[2];
                rg[5] = rg[0];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 6, 8, 4);
                rg[1] = rg[2];
                f[7] = m.floadu(FKind::I32, rg[4].wrapping_add(0x3cu32));
                f[7] = f[7] * f[5];
                { let bv = 0x3fffffffu32; let av = rg[6]; let r = fl.alu(Alu::And, av, bv, 4); rg[6] = r; }
                { let a = rg[4].wrapping_add(0x3cu32); m.wr32u(a, rg[6]); }
                rg[6] = rg[7];
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 6, 8, 4);
                { let bv = 0x3fffffffu32; let av = rg[2]; let r = fl.alu(Alu::And, av, bv, 4); rg[2] = r; }
                f[7] = f[7] + f[3];
                { let bv = 0x3fffffffu32; let av = rg[6]; let r = fl.alu(Alu::And, av, bv, 4); rg[6] = r; }
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 5, 4, 4);
                { let bv = 0x3fffffffu32; let av = rg[7]; let r = fl.alu(Alu::And, av, bv, 4); rg[7] = r; }
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 0, 8, 4);
                { let bv = 0x3fffffffu32; let av = rg[5]; let r = fl.alu(Alu::And, av, bv, 4); rg[5] = r; }
                f[7] = f[7] * f[0];
                { let bv = 0x3fffffffu32; let av = rg[0]; let r = fl.alu(Alu::And, av, bv, 4); rg[0] = r; }
                shift_reg_l(&mut rg, &mut fl, Shift::Shl, 1, 4, 4);
                { let bv = 0x3fffffffu32; let av = rg[1]; let r = fl.alu(Alu::And, av, bv, 4); rg[1] = r; }
                f[6] = f[6] + f[7];
                f[7] = m.floadu(FKind::I32, rg[4].wrapping_add(0x3cu32));
                f[7] = f[7] * f[5];
                { let a = rg[4].wrapping_add(0x3cu32); m.wr32u(a, rg[6]); }
                f[7] = f[7] + f[3];
                f[7] = f[7] * f[1];
                f[6] = f[6] + f[7];
                f[6] = f[6] * f[4];
                { let v = m.rdf64u(rg[4].wrapping_add(0x18u32)); f[6] = f[6] + v; }
                { let a = rg[4].wrapping_add(0x18u32); m.wrf64u(a, f[6]); }
                f[6] = m.floadu(FKind::I32, rg[4].wrapping_add(0x3cu32));
                f[6] = f[6] * f[5];
                { let a = rg[4].wrapping_add(0x3cu32); m.wr32u(a, rg[5]); }
                f[6] = f[6] + f[3];
                f[6] = f[6] * f[2];
                f[7] = m.floadu(FKind::I32, rg[4].wrapping_add(0x3cu32));
                f[7] = f[7] * f[5];
                { let a = rg[4].wrapping_add(0x3cu32); m.wr32u(a, rg[2]); }
                f[7] = f[7] + f[3];
                f[7] = f[7] * f[0];
                f[6] = f[6] + f[7];
                f[7] = m.floadu(FKind::I32, rg[4].wrapping_add(0x3cu32));
                f[7] = f[7] * f[5];
                { let a = rg[4].wrapping_add(0x3cu32); m.wr32u(a, rg[7]); }
                f[7] = f[7] + f[3];
                f[7] = f[7] * f[1];
                f[6] = f[6] + f[7];
                f[6] = f[6] * f[4];
                { let v = m.rdf64u(rg[4].wrapping_add(0x10u32)); f[6] = f[6] + v; }
                { let a = rg[4].wrapping_add(0x10u32); m.wrf64u(a, f[6]); }
                f[6] = m.floadu(FKind::I32, rg[4].wrapping_add(0x3cu32));
                f[6] = f[6] * f[5];
                { let a = rg[4].wrapping_add(0x3cu32); m.wr32u(a, rg[0]); }
                f[6] = f[6] + f[3];
                f[2] = f[2] * f[6];
                f[6] = m.floadu(FKind::I32, rg[4].wrapping_add(0x3cu32));
                f[6] = f[6] * f[5];
                { let a = rg[4].wrapping_add(0x3cu32); m.wr32u(a, rg[1]); }
                f[6] = f[6] + f[3];
                f[0] = f[0] * f[6];
                f.swap(5, 0);
                f[2] = f[2] + f[5];
                f[5] = m.floadu(FKind::I32, rg[4].wrapping_add(0x3cu32));
                f[0] = f[0] * f[5];
                f.swap(4, 0);
                f[4] = f[4] + f[3];
                f[1] = f[1] * f[4];
                f.swap(3, 2);
                f[1] = f[1] + f[3];
                f.swap(2, 0);
                f[1] = f[1] * f[2];
                { let v = m.rdf64u(rg[4].wrapping_add(0x8u32)); f[1] = f[1] + v; }
                { let a = rg[4].wrapping_add(0x8u32); m.wrf64u(a, f[1]); }
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 21; continue;
            }
            27 => {
                f[1] = m.rdf64u(rg[4].wrapping_add(0x98u32));
                f[2] = m.rdf64u(rg[4].wrapping_add(0x88u32));
                f[3] = m.rdf64u(rg[4].wrapping_add(0x90u32));
                rg[1] = m.rd32u(rg[4].wrapping_add(0xa0u32));
                rg[2] = m.rd32u(rg[4].wrapping_add(0xa4u32));
                rg[6] = m.rd32u(rg[4].wrapping_add(0xa8u32));
                { let v = 0x2u32; reg_set(&mut rg, 3, 1, v); }
                f[4] = m.rdf64u(rg[4].wrapping_add(0x80u32));
                f.swap(4, 2);
                f.swap(4, 1);
                f.swap(4, 3);
                f.swap(4, 0);
                f.swap(4, 3);
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 19; continue;
            }
            28 => {
                f[0] = f[0];
                rg[0] = m.rd32u(rg[4].wrapping_add(0x6cu32));
                rg[3] = m.rd32u(rg[4].wrapping_add(0xe8u32));
                f[0] = m.rdf64u(rg[4].wrapping_add(0x18u32));
                { let v = m.rdf64u(rg[0].wrapping_add(0xfffffff0u32)); f[0] = f[0] * v; }
                { let v = m.rdf64u(rg[3].wrapping_add(0xffffffe0u32)); f[0] = f[0] + v; }
                { let a = rg[3].wrapping_add(0xffffffe0u32); m.wrf64u(a, f[0]); }
                f[0] = m.rdf64u(rg[4].wrapping_add(0x10u32));
                { let v = m.rdf64u(rg[0].wrapping_add(0xfffffff0u32)); f[0] = f[0] * v; }
                { let v = m.rdf64u(rg[3].wrapping_add(0xffffffe8u32)); f[0] = f[0] + v; }
                { let a = rg[3].wrapping_add(0xffffffe8u32); m.wrf64u(a, f[0]); }
                f[0] = m.rdf64u(rg[4].wrapping_add(0x8u32));
                { let v = m.rdf64u(rg[0].wrapping_add(0xfffffff0u32)); f[0] = f[0] * v; }
                { let v = m.rdf64u(rg[3].wrapping_add(0xfffffff0u32)); f[0] = f[0] + v; }
                { let a = rg[3].wrapping_add(0xfffffff0u32); m.wrf64u(a, f[0]); }
                { let bv = 0xd4u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
                { let v = pop_lu(m, &mut rg); rg[3] = v; }
                { let v = pop_lu(m, &mut rg); rg[6] = v; }
                { let v = pop_lu(m, &mut rg); rg[7] = v; }
                { let v = pop_lu(m, &mut rg); rg[5] = v; }
                let r = pop_lu(m, &mut rg); rg[ESP] = rg[ESP].wrapping_add(8);                              if r != RETURN_SENTINEL { match p.rets.iter().find(|e| e.0 == r).map(|e| e.1) { _ => return Err(unsup(r, "bad return".into())) } }                              m.st = f; return Ok(());
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

// _F_MandalayFold

pub(super) fn f_2dffd31d561b9853(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
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
        { let v = f64::from_bits(v30); f[0] = f[0] - v; }
        f[0] = f[0].abs();
        { let v = f64::from_bits(v30); f[0] = f[0] - v; }
        r3 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        { let v = f64::from_bits(v29); f[0] = f[0] - v; }
        f[0] = f[0].abs();
        { let v = f64::from_bits(v29); f[0] = f[0] - v; }
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        { let v = f64::from_bits(v28); f[0] = f[0] - v; }
        f[0] = f[0].abs();
        { let v = f64::from_bits(v28); f[0] = f[0] - v; }
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

// _T_Wobble

pub(super) fn f_30e2e60d6a23e99d(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
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
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 0)) | (((rg[7] as u64) & 0xffffffffu64) << 0); }
        rg[6] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[7] = ((r13 >> 0) & 0xffffffffu64) as u32;
        f[0] = f64::from_bits(r3);
        { let v = f64::from_bits(v29); f[0] = f[0] * v; }
        f[1] = f64::from_bits(r4);
        { let v = f64::from_bits(v28); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        { let v = f64::from_bits(v27); f[0] = f[0] + v; }
        f[0] = f[0].sin(); fsw &= !0x0400;
        { let v = f64::from_bits(v30); f[0] = f[0] * v; }
        { let v = f64::from_bits(r5); f[0] = f[0] + v; }
        r5 = f[0].to_bits();
        { rg[7] = ((s2013 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[6] = ((s2013 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[5] = ((s2014 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 5, r5);
    m.wr64u(0x10007ee8u32, s2013);
    m.wr64u(0x10007ef0u32, s2014);
    Ok(())
}

// _F_AbsFold

pub(super) fn f_31ca3aecc58e5db3(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    'body: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 32)) | (((rg[6] as u64) & 0xffffffffu64) << 32); }
        rg[6] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[6] = ((r13 >> 0) & 0xffffffffu64) as u32;
        f[0] = f64::from_bits(r3);
        f[0] = f[0].abs();
        r3 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        f[0] = f[0].abs();
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        f[0] = f[0].abs();
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

// EiffieQ

pub(super) fn f_33f85ce639630e31(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let mut r0: u64 = rec_get(m, it, pvar, 0);
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r6: u64 = rec_get(m, it, pvar, 6);
    let mut r10: u64 = rec_get(m, it, pvar, 10);
    let mut r11: u64 = rec_get(m, it, pvar, 11);
    let mut r12: u64 = rec_get(m, it, pvar, 12);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    'body: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        rg[2] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[0] = rg[2].wrapping_add(0xffffffc8u32);
        f[0] = f64::from_bits(r3);
        f[1] = f64::from_bits(r4);
        f[2] = f64::from_bits(r5);
        f[3] = f[0];
        f[4] = f[1];
        f[5] = f64::from_bits(r6);
        f.swap(5, 4);
        f[5] = f[5] * f[1];
        f.swap(5, 3);
        f[5] = f[5] * f[0];
        f[6] = f[2];
        f.swap(6, 5);
        f[3] = f[6] - f[3];
        f[6] = f[2];
        f.swap(6, 5);
        f[6] = f[6] * f[4];
        f.swap(6, 5);
        f[6] = f[6] * f[2];
        f[7] = f[0];
        f.swap(7, 3);
        f[6] = f[7] - f[6];
        f[7] = f[4];
        f.swap(7, 3);
        f[7] = f[7] * f[2];
        f.swap(7, 3);
        f[7] = f[7] * f[4];
        f[6] = f[6] + f[7];
        f[7] = f[0];
        f[7] = f[7] * f[4];
        f.swap(7, 0);
        f[7] = f[7] * f[1];
        f.swap(7, 6);
        { let v = f64::from_bits(r10); f[7] = f[7] + v; }
        f.swap(7, 5);
        f[6] = f[7] - f[6];
        f[7] = f[1];
        f[2] = f[2] * f[7];
        f.swap(6, 1);
        f[4] = f[4] * f[6];
        f.swap(5, 0);
        f[2] = f[2] + f[5];
        f.swap(4, 1);
        f[4] = f[4] + f[4];
        f.swap(4, 1);
        f[3] = f[4] - f[3];
        f.swap(3, 2);
        f[3] = f[3] + f[3];
        f.swap(3, 1);
        { let v = f64::from_bits(r11); f[3] = f[3] + v; }
        f.swap(3, 2);
        f[3] = f[3] + f[3];
        f.swap(3, 1);
        { let v = f64::from_bits(r0); f[3] = f[3] + v; }
        f.swap(3, 0);
        r3 = f[3].to_bits();
        f.swap(2, 1);
        { let v = f64::from_bits(r12); f[2] = f[2] + v; }
        f.swap(2, 1);
        r4 = f[2].to_bits();
        f.swap(1, 0);
        r6 = f[1].to_bits();
        r5 = f[0].to_bits();
        { rg[5] = ((s2014 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 3, r3);
    rec_set(m, it, 4, r4);
    rec_set(m, it, 5, r5);
    rec_set(m, it, 6, r6);
    m.wr64u(0x10007ef0u32, s2014);
    Ok(())
}

// _BTwistBraid_V3v2after

pub(super) fn f_341cdd3c9a694310(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let mut steps = 0u64;
    let limit = max_steps;
    let vb = pvar.wrapping_sub(256);
    let vm = m.bytes_at::<144>(vb.wrapping_add(136))?;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s1998: u64 = m.rd64u(0x10007e70u32);
    let mut s1999: u64 = m.rd64u(0x10007e78u32);
    let mut s2001: u64 = m.rd64u(0x10007e88u32);
    let mut s2003: u64 = m.rd64u(0x10007e98u32);
    let mut s2005: u64 = m.rd64u(0x10007ea8u32);
    let mut s2006: u64 = m.rd64u(0x10007eb0u32);
    let mut s2007: u64 = m.rd64u(0x10007eb8u32);
    let mut s2008: u64 = m.rd64u(0x10007ec0u32);
    let mut s2009: u64 = m.rd64u(0x10007ec8u32);
    let mut s2011: u64 = m.rd64u(0x10007ed8u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    let mut v17: u64 = cell(vm, 0);
    let mut v18: u64 = cell(vm, 8);
    let mut v19: u64 = cell(vm, 16);
    let mut v20: u64 = cell(vm, 24);
    let mut v21: u64 = cell(vm, 32);
    let mut v22: u64 = cell(vm, 40);
    let mut v23: u64 = cell(vm, 48);
    let mut v24: u64 = cell(vm, 56);
    let mut v25: u64 = cell(vm, 64);
    let mut v26: u64 = cell(vm, 72);
    let mut v28: u64 = cell(vm, 88);
    let mut v29: u64 = cell(vm, 96);
    let mut v32: u64 = cell(vm, 120);
    let mut v33: u64 = cell(vm, 128);
    let mut v34: u64 = cell(vm, 136);
    'body: {
        'b49: {
        'b47: {
        'b45: {
        'b44: {
        'b42: {
        'b39: {
        'b38: {
        'b35: {
        'b32: {
        'b30: {
        'b28: {
        'b26: {
        'b25: {
        'b23: {
        'b20: {
        'b27: {
        'b19: {
        'b16: {
        'b13: {
        'b11: {
        'b8: {
        'b7: {
        'b5: {
        'b3: {
        'b2: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        { let bv = 0x70u32; let av = rg[4]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[4] = r; }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s1999 = (s1999 & !(0xffffffffu64 << 32)) | (((rg[3] as u64) & 0xffffffffu64) << 32); }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s1999 = (s1999 & !(0xffffffffu64 << 0)) | (((rg[6] as u64) & 0xffffffffu64) << 0); }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s1998 = (s1998 & !(0xffffffffu64 << 32)) | (((rg[7] as u64) & 0xffffffffu64) << 32); }
        rg[6] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[7] = ((r13 >> 0) & 0xffffffffu64) as u32;
        rg[3] = rg[0];
        f[0] = f64::from_bits(r3);
        s2001 = f[0].to_bits();
        f[0] = f64::from_bits(r3);
        { let v = f64::from_bits(v29); f[0] = f[0] - v; }
        f[0] = f[0].abs();
        s2011 = f[0].to_bits();
        f[0] = f64::from_bits(v28);
        fsw = fcompare_cc(f[0], 0.0);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(4) { break 'b2; }
        // block 1
        f[0] = f[0];
        f[0] = f64::from_bits(v23);
        f[0] = -f[0];
        f[1] = f64::from_bits(0x3ff0000000000000);
        f[0] = f[0] + f[1];
        s2009 = f[0].to_bits();
        f[0] = f64::from_bits(r3);
        { let v = f64::from_bits(v28); f[0] = f[0] * v; }
        { let v = f64::from_bits(v32); f[0] = f[0] + v; }
        { let (s, c) = f[0].sin_cos(); f[0] = s; f[1] = c; fsw &= !0x0400; }
        s2013 = f[1].to_bits();
        s2012 = f[0].to_bits();
        f[1] = f64::from_bits(r5);
        f[0] = f[0] * f[1];
        f[1] = f64::from_bits(r4);
        { let v = f64::from_bits(s2013); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        f[1] = f64::from_bits(r4);
        { let v = f64::from_bits(s2012); f[1] = f[1] * v; }
        f[2] = f64::from_bits(r5);
        { let v = f64::from_bits(s2013); f[2] = f[2] * v; }
        f[2] = -f[2];
        f[1] = f[1] + f[2];
        f[2] = f64::from_bits(s2009);
        f[1] = f[1] * f[2];
        r4 = f[1].to_bits();
        f[1] = f64::from_bits(s2009);
        f[0] = f[0] * f[1];
        r5 = f[0].to_bits();
        break 'b3;
        } // 'b2
        // block 2
        f[0] = f[0];
        } // 'b3
        // block 3
        f[0] = f64::from_bits(v25);
        fsw = fcompare_cc(f[0], 0.0);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(5) { break 'b5; }
        // block 4
        f[0] = f[0];
        break 'b27;
        } // 'b5
        // block 5
        f[0] = f[0];
        f[0] = f64::from_bits(v24);
        { let v = f64::from_bits(v26); f[0] = f[0] - v; }
        f[0] = f[0].abs();
        f[1] = f64::from_bits(v25);
        f[1] = f[1].abs();
        s2007 = f[1].to_bits();
        fsw = fcompare_cc(f[0], f64::from_bits(s2007));
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(3) { break 'b7; }
        // block 6
        s2007 = f[0].to_bits();
        break 'b8;
        } // 'b7
        // block 7
        f[0] = f[0];
        } // 'b8
        // block 8
        f[0] = f64::from_bits(v24);
        { let v = f64::from_bits(v26); f[0] = f[0] - v; }
        fsw = fcompare_cc(f[0], 0.0);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        f[0] = f[0];
        f[0] = f64::from_bits(s2007);
        f[0] = f[0].abs();
        if fl.cond(3) { break 'b28; }
        // block 9
        f[0] = -f[0];
        s2007 = f[0].to_bits();
        f[0] = f64::from_bits(r3);
        fsw = fcompare_cc(f[0], f64::from_bits(v26));
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(6) { break 'b11; }
        // block 10
        f[0] = f[0];
        break 'b27;
        } // 'b11
        // block 11
        fsw = fcompare_cc(f[0], f64::from_bits(v24));
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(3) { break 'b13; }
        // block 12
        { let v = f64::from_bits(v24); f[0] = f[0] - v; }
        { let v = f64::from_bits(v26); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        break 'b27;
        } // 'b13
        // block 13
        f[1] = f64::from_bits(v24);
        { let v = f64::from_bits(v26); f[1] = f[1] - v; }
        'l14: loop {
            // block 14
            fsw = fcompare_cc(f[1], f64::from_bits(s2007));
            rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
            { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
            if fl.cond(3) { break 'b16; }
            // block 15
            { let v = f64::from_bits(s2007); f[1] = f[1] - v; }
            steps += 1; if steps > limit { return Err(EmuError::StepLimit); } continue 'l14;
        }
        } // 'b16
        // block 16
        s2006 = f[1].to_bits();
        f[1] = f64::from_bits(v24);
        { let v = f64::from_bits(s2006); f[1] = f[1] - v; }
        s2005 = f[1].to_bits();
        fsw = fcompare_cc(f[0], f64::from_bits(s2005));
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(3) { break 'b20; }
        // block 17
        { let v = f64::from_bits(s2005); f[0] = f[0] - v; }
        f[1] = f64::from_bits(s2006);
        { let v = f64::from_bits(v34); f[1] = f[1] * v; }
        s2007 = f[1].to_bits();
        fsw = fcompare_cc(f[0], f64::from_bits(s2007));
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(6) { break 'b19; }
        // block 18
        { let v = f64::from_bits(v26); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        break 'b27;
        } // 'b19
        // block 19
        f[0] = f[0];
        f[0] = f64::from_bits(v24);
        f[1] = f64::from_bits(r3);
        f[1] = -f[1];
        f[0] = f[0] + f[1];
        { let v = f64::from_bits(v26); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        
        } // 'b27
        // block 27
        break 'b45;
        } // 'b20
        // block 20
        f[1] = f64::from_bits(v26);
        f[2] = f64::from_bits(v25);
        f[2] = f[2].abs();
        f[2] = -f[2];
        f[1] = f[1] + f[2];
        s2006 = f[1].to_bits();
        'l21: loop {
            // block 21
            fsw = fcompare_cc(f[0], f64::from_bits(s2006));
            rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
            { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
            if fl.cond(3) { break 'b23; }
            // block 22
            f[1] = f64::from_bits(v25);
            f[1] = f[1].abs();
            f[0] = f[0] + f[1];
            steps += 1; if steps > limit { return Err(EmuError::StepLimit); } continue 'l21;
        }
        } // 'b23
        // block 23
        { let v = f64::from_bits(v26); f[0] = f[0] - v; }
        f[1] = f64::from_bits(s2007);
        { let v = f64::from_bits(v34); f[1] = f[1] * v; }
        s2006 = f[1].to_bits();
        fsw = fcompare_cc(f[0], f64::from_bits(s2006));
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(6) { break 'b25; }
        // block 24
        { let v = f64::from_bits(v26); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        break 'b26;
        } // 'b25
        // block 25
        f[0] = -f[0];
        f[1] = f64::from_bits(s2007);
        f[0] = f[0] + f[1];
        { let v = f64::from_bits(v26); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        } // 'b26
        // block 26
        break 'b45;
        } // 'b28
        // block 28
        s2007 = f[0].to_bits();
        f[0] = f64::from_bits(r3);
        fsw = fcompare_cc(f[0], f64::from_bits(v26));
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(3) { break 'b30; }
        // block 29
        f[0] = f[0];
        break 'b45;
        } // 'b30
        // block 30
        fsw = fcompare_cc(f[0], f64::from_bits(v24));
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(6) { break 'b32; }
        // block 31
        { let v = f64::from_bits(v24); f[0] = f[0] - v; }
        { let v = f64::from_bits(v26); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        break 'b45;
        } // 'b32
        // block 32
        f[1] = f64::from_bits(v24);
        { let v = f64::from_bits(v26); f[1] = f[1] - v; }
        'l33: loop {
            // block 33
            fsw = fcompare_cc(f[1], f64::from_bits(s2007));
            rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
            { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
            if fl.cond(6) { break 'b35; }
            // block 34
            { let v = f64::from_bits(s2007); f[1] = f[1] - v; }
            steps += 1; if steps > limit { return Err(EmuError::StepLimit); } continue 'l33;
        }
        } // 'b35
        // block 35
        s2006 = f[1].to_bits();
        f[1] = f64::from_bits(v24);
        { let v = f64::from_bits(s2006); f[1] = f[1] - v; }
        s2005 = f[1].to_bits();
        fsw = fcompare_cc(f[0], f64::from_bits(s2005));
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(6) { break 'b39; }
        // block 36
        { let v = f64::from_bits(s2005); f[0] = f[0] - v; }
        f[1] = f64::from_bits(s2006);
        { let v = f64::from_bits(v34); f[1] = f[1] * v; }
        s2007 = f[1].to_bits();
        fsw = fcompare_cc(f[0], f64::from_bits(s2007));
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(3) { break 'b38; }
        // block 37
        { let v = f64::from_bits(v26); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        break 'b45;
        } // 'b38
        // block 38
        f[0] = f[0];
        f[0] = f64::from_bits(v24);
        f[1] = f64::from_bits(r3);
        f[1] = -f[1];
        f[0] = f[0] + f[1];
        { let v = f64::from_bits(v26); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        break 'b45;
        } // 'b39
        // block 39
        f[1] = f64::from_bits(v26);
        f[2] = f64::from_bits(v25);
        f[2] = f[2].abs();
        f[1] = f[1] + f[2];
        s2006 = f[1].to_bits();
        'l40: loop {
            // block 40
            fsw = fcompare_cc(f[0], f64::from_bits(s2006));
            rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
            { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
            if fl.cond(6) { break 'b42; }
            // block 41
            f[1] = f64::from_bits(v25);
            f[1] = f[1].abs();
            f[1] = -f[1];
            f[0] = f[0] + f[1];
            steps += 1; if steps > limit { return Err(EmuError::StepLimit); } continue 'l40;
        }
        } // 'b42
        // block 42
        { let v = f64::from_bits(v26); f[0] = f[0] - v; }
        f[1] = f64::from_bits(s2007);
        { let v = f64::from_bits(v34); f[1] = f[1] * v; }
        s2006 = f[1].to_bits();
        fsw = fcompare_cc(f[0], f64::from_bits(s2006));
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(3) { break 'b44; }
        // block 43
        { let v = f64::from_bits(v26); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        break 'b45;
        } // 'b44
        // block 44
        f[0] = -f[0];
        f[1] = f64::from_bits(s2007);
        f[0] = f[0] + f[1];
        { let v = f64::from_bits(v26); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        } // 'b45
        // block 45
        f[0] = f64::from_bits(v32);
        { let v = f64::from_bits(v34); f[0] = f[0] * v; }
        f[1] = f64::from_bits(v18);
        { let v = f64::from_bits(v18); f[1] = f[1] / v; }
        f[0] = f[0] * f[1];
        s2009 = f[0].to_bits();
        f[0] = f64::from_bits(v32);
        { let v = f64::from_bits(v33); f[0] = f[0] * v; }
        { let v = f64::from_bits(v18); f[0] = f[0] / v; }
        s2011 = f[0].to_bits();
        { let v = f64::from_bits(v33); f[0] = f[0] * v; }
        f[1] = f64::from_bits(v18);
        f[2] = f64::from_bits(0x3ff0000000000000);
        f[2] = -f[2];
        f[1] = f[1] + f[2];
        f[0] = f[0] * f[1];
        s2008 = f[0].to_bits();
        f[0] = f64::from_bits(v32);
        { let v = f64::from_bits(v33); f[0] = f[0] * v; }
        { let v = f64::from_bits(v33); f[0] = f[0] * v; }
        s2013 = f[0].to_bits();
        { let v = f64::from_bits(v18); f[0] = f[0] / v; }
        s2012 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        f[1] = f64::from_bits(r4);
        f[0] = f[0].atan2(f[1]);
        fsw = fcompare_cc(f[0], 0.0);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
        { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
        if fl.cond(3) { break 'b47; }
        // block 46
        { let v = f64::from_bits(s2013); f[0] = f[0] + v; }
        } // 'b47
        'l47: loop {
            // block 47
            fsw = fcompare_cc(f[0], f64::from_bits(s2012));
            rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3800) as u32;
            { let ah = (rg[EAX] >> 8) as u8; fl.sf = ah & 0x80 != 0; fl.zf = ah & 0x40 != 0; fl.af = ah & 0x10 != 0; fl.pf = ah & 0x04 != 0; fl.cf = ah & 0x01 != 0; }
            if fl.cond(6) { break 'b49; }
            // block 48
            f[1] = f64::from_bits(s2011);
            { let v = f64::from_bits(s2012); f[1] = f[1] + v; }
            s2011 = f[1].to_bits();
            f[1] = f64::from_bits(s2009);
            { let v = f64::from_bits(s2008); f[1] = f[1] + v; }
            s2009 = f[1].to_bits();
            { let v = f64::from_bits(s2012); f[0] = f[0] - v; }
            steps += 1; if steps > limit { return Err(EmuError::StepLimit); } continue 'l47;
        }
        } // 'b49
        // block 49
        f[0] = f[0];
        f[0] = f64::from_bits(s2011);
        { let (s, c) = f[0].sin_cos(); f[0] = s; f[1] = c; fsw &= !0x0400; }
        f[2] = f64::from_bits(s2001);
        { let v = f64::from_bits(v21); f[2] = f[2] * v; }
        f[2] = f[2].cos(); fsw &= !0x0400;
        { let v = f64::from_bits(v17); f[2] = f[2] * v; }
        { let v = f64::from_bits(v22); f[2] = f[2] * v; }
        { let v = f64::from_bits(v17); f[2] = f[2] + v; }
        s2003 = f[2].to_bits();
        f[1] = f[1] * f[2];
        f[1] = -f[1];
        { let v = f64::from_bits(r4); f[1] = f[1] + v; }
        r4 = f[1].to_bits();
        f[1] = f64::from_bits(s2003);
        f[0] = f[0] * f[1];
        f[0] = -f[0];
        { let v = f64::from_bits(r5); f[0] = f[0] + v; }
        r5 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits(r5);
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        f[1] = f64::from_bits(s2001);
        { let v = f64::from_bits(v19); f[1] = f[1] * v; }
        f[1] = f[1].cos(); fsw &= !0x0400;
        { let v = f64::from_bits(v17); f[1] = f[1] * v; }
        { let v = f64::from_bits(v20); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        s2013 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        f[1] = f64::from_bits(r4);
        f[0] = f[0].atan2(f[1]);
        { let v = f64::from_bits(s2009); f[0] = f[0] + v; }
        { let (s, c) = f[0].sin_cos(); f[0] = s; f[1] = c; fsw &= !0x0400; }
        { let v = f64::from_bits(s2013); f[1] = f[1] * v; }
        r4 = f[1].to_bits();
        { let v = f64::from_bits(s2013); f[0] = f[0] * v; }
        r5 = f[0].to_bits();
        rg[0] = rg[3];
        { rg[7] = ((s1998 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[6] = ((s1999 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[3] = ((s1999 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[4] = rg[5];
        { rg[5] = ((s2014 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 3, r3);
    rec_set(m, it, 4, r4);
    rec_set(m, it, 5, r5);
    m.wr64u(0x10007e70u32, s1998);
    m.wr64u(0x10007e78u32, s1999);
    m.wr64u(0x10007e88u32, s2001);
    m.wr64u(0x10007e98u32, s2003);
    m.wr64u(0x10007ea8u32, s2005);
    m.wr64u(0x10007eb0u32, s2006);
    m.wr64u(0x10007eb8u32, s2007);
    m.wr64u(0x10007ec0u32, s2008);
    m.wr64u(0x10007ec8u32, s2009);
    m.wr64u(0x10007ed8u32, s2011);
    m.wr64u(0x10007ee0u32, s2012);
    m.wr64u(0x10007ee8u32, s2013);
    m.wr64u(0x10007ef0u32, s2014);
    Ok(())
}

// CosAziTwoStage

pub(super) fn f_3f3c312349d7b282(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let vb = pvar.wrapping_sub(256);
    let vm = m.bytes_at::<32>(vb.wrapping_add(256))?;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r10: u64 = rec_get(m, it, pvar, 10);
    let mut r11: u64 = rec_get(m, it, pvar, 11);
    let mut r12: u64 = rec_get(m, it, pvar, 12);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    let mut v32: u64 = cell(vm, 0);
    let mut v33: u64 = cell(vm, 8);
    let mut v34: u64 = cell(vm, 16);
    let mut v35: u64 = cell(vm, 24);
    'body: {
        // block 0
        { let bv = 0x14u32; let av = rg[4]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[4] = r; }
        rg[0] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[2] = ((r13 >> 0) & 0xffffffffu64) as u32;
        f[0] = f64::from_bits(r3);
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits(r4);
        f[1] = f[1] * f[1];
        f[2] = f64::from_bits(r5);
        f[2] = f[2] * f[2];
        f[3] = f[0];
        f[3] = f[3] + f[1];
        f[4] = f[3];
        f[4] = f[4].sqrt();
        f[5] = f[2];
        f[5] = f[5] - f[3];
        f.swap(5, 4);
        f[5] = f[5] * f[3];
        f[4] = f[4] / f[5];
        f[5] = f64::from_bits(r5);
        { let v = f64::from_bits(v33); f[5] = f[5] * v; }
        f[4] = f[4] * f[5];
        f[5] = f[4];
        { let v = f64::from_bits(v33); f[5] = f[5] * v; }
        { let v = f64::from_bits(r3); f[5] = f[5] * v; }
        f[6] = f[0];
        f[6] = f[6] - f[1];
        f[5] = f[5] * f[6];
        { let v = f64::from_bits(r4); f[5] = f[5] * v; }
        r4 = f[5].to_bits();
        f[6] = f[0];
        { let v = f64::from_bits(v32); f[6] = f[6] * v; }
        f[6] = f[6] * f[1];
        f.swap(6, 0);
        f[6] = f[6] * f[6];
        f[0] = f[0] + f[6];
        f.swap(5, 1);
        f[5] = f[5] * f[5];
        f[0] = f[0] + f[5];
        f[0] = f[0] * f[4];
        f[4] = f[0];
        r3 = f[4].to_bits();
        f[5] = f[2];
        { let v = f64::from_bits(v32); f[5] = f[5] * v; }
        f[5] = f[5] * f[3];
        f.swap(5, 2);
        f[5] = f[5] * f[5];
        f[2] = f[2] + f[5];
        f.swap(4, 3);
        f[4] = f[4] * f[4];
        f[2] = f[2] + f[4];
        f.swap(3, 2);
        r5 = f[3].to_bits();
        f[4] = f[2];
        f[2] = f[2] * f[4];
        f[4] = f[1];
        f[4] = f[4] * f[1];
        f[5] = f[3];
        f[5] = f[5] * f[3];
        f[6] = f[2];
        f[6] = f[6] + f[4];
        f[7] = f[6];
        f[7] = f[7] * f[6];
        s2012 = f[7].to_bits();
        f[6] = f[6].sqrt();
        f[6] = f[6];
        f[6] = f64::from_bits(0x3ff0000000000000);
        f[7] = f[2];
        f[7] = f[7] - f[4];
        s2013 = f[7].to_bits();
        f[7] = f[0];
        { let v = f64::from_bits(v35); f[7] = f[7] * v; }
        f[1] = f[1] * f[7];
        f[7] = f64::from_bits(s2013);
        { let v = f64::from_bits(v35); f[7] = f[7] * v; }
        f[7] = f[7] * f[5];
        { let v = f64::from_bits(s2012); f[7] = f[7] / v; }
        f[6] = f[6] - f[7];
        f[1] = f[1] * f[6];
        f.swap(5, 1);
        r4 = f[5].to_bits();
        f[6] = f64::from_bits(v35);
        f[6] = -f[6];
        f[0] = f[0] * f[6];
        f.swap(5, 3);
        f[0] = f[0] * f[5];
        f.swap(4, 0);
        r5 = f[4].to_bits();
        f[5] = f[2];
        f[5] = f[5] * f[2];
        f.swap(5, 2);
        { let v = f64::from_bits(v34); f[5] = f[5] * v; }
        f[5] = f[5] * f[0];
        f[2] = f[2] - f[5];
        f.swap(4, 0);
        f[4] = f[4] * f[4];
        f[2] = f[2] + f[4];
        f.swap(3, 1);
        f[2] = f[2] * f[3];
        { let v = f64::from_bits(s2012); f[2] = f[2] / v; }
        { let v = f64::from_bits(s2013); f[2] = v - f[2]; }
        { let v = f64::from_bits(r10); f[2] = f[2] + v; }
        r3 = f[2].to_bits();
        { let v = f64::from_bits(r11); f[1] = f[1] + v; }
        r4 = f[1].to_bits();
        { let v = f64::from_bits(r12); f[0] = f[0] + v; }
        r5 = f[0].to_bits();
        { let bv = 0x14u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 3, r3);
    rec_set(m, it, 4, r4);
    rec_set(m, it, 5, r5);
    m.wr64u(0x10007ee0u32, s2012);
    m.wr64u(0x10007ee8u32, s2013);
    Ok(())
}

// invcylIFS

pub(super) fn f_418c00f4c8bd6d96(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    'body: {
        // block 0
        f[0] = f64::from_bits(r3);
        { let (s, c) = f[0].sin_cos(); f[0] = s; f[1] = c; fsw &= !0x0400; }
        f[2] = f64::from_bits(r4);
        f[0] = f[0] * f[2];
        f[1] = f[1] * f[2];
        r4 = f[1].to_bits();
        r3 = f[0].to_bits();
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.regs = rg;
    m.fl = fl;
    m.fsw_cc = fsw;
    m.st = f;
    Ok(())
}

// _T_ScaleOffset

pub(super) fn f_4aa26c3c41bb6ac8(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let vb = pvar.wrapping_sub(256);
    let vm = m.bytes_at::<48>(vb.wrapping_add(200))?;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    let mut v25: u64 = cell(vm, 0);
    let mut v26: u64 = cell(vm, 8);
    let mut v27: u64 = cell(vm, 16);
    let mut v28: u64 = cell(vm, 24);
    let mut v29: u64 = cell(vm, 32);
    let mut v30: u64 = cell(vm, 40);
    'body: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 32)) | (((rg[6] as u64) & 0xffffffffu64) << 32); }
        rg[6] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[6] = ((r13 >> 0) & 0xffffffffu64) as u32;
        f[0] = f64::from_bits(r3);
        { let v = f64::from_bits(v30); f[0] = f[0] * v; }
        { let v = f64::from_bits(v27); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        { let v = f64::from_bits(v29); f[0] = f[0] * v; }
        { let v = f64::from_bits(v26); f[0] = f[0] + v; }
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        { let v = f64::from_bits(v28); f[0] = f[0] * v; }
        { let v = f64::from_bits(v25); f[0] = f[0] + v; }
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

// YPicartP8

pub(super) fn f_4ce27eb7beb48ce8(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
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
                { let v = rg[3]; push_l(m, &mut rg, v)?; }
                { let bv = 0xc0u32; let av = rg[4]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[4] = r; }
                rg[3] = m.rd32(rg[4].wrapping_add(0xc8u32))?;
                rg[2] = m.rd32(rg[3].wrapping_add(0x30u32))?;
                f[0] = m.rdf64(rg[3].wrapping_add(0xfffffff0u32))?;
                f[1] = m.rdf64(rg[3].wrapping_add(0xffffffe8u32))?;
                f[2] = m.rdf64(rg[3].wrapping_add(0xffffffe0u32))?;
                f[3] = f[2];
                f[3] = f[3] * f[2];
                f[4] = f[1];
                f[4] = f[4] * f[1];
                f[3] = f[3] + f[4];
                f[4] = f[0];
                f[4] = f[4] * f[0];
                f[3] = f[3] + f[4];
                f[3] = f[3].sqrt();
                f[4] = f[3];
                f[5] = f64::from_bits(0x3ff0000000000000);
                f[4] = f[5] / f[4];
                f[5] = f64::from_bits(0x3ff0000000000000);
                f.swap(5, 3);
                { let v = 0x4u32; rg[0] = v; }
                { let v = 0x8u32; rg[1] = v; }
                steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 3; continue;
            }
            1 => {
                { let bv = 0x1u32; let av = reg_get(&rg, 1, 1); fl.alu(Alu::And, av, bv, 1); }
                if fl.cond(4) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 3; continue; }
                b = 2;
            }
            2 => {
                f[3] = f[3] * f[5];
                b = 3;
            }
            3 => {
                shift_reg_l(&mut rg, &mut fl, Shift::Sar, 1, 1, 4);
                f[5] = f[5] * f[5];
                { let cf = fl.cf; let r = fl.alu(Alu::Sub, rg[0], 1, 4); fl.cf = cf; rg[0] = r; }
                if fl.cond(5) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 1; continue; }
                b = 4;
            }
            4 => {
                f[5] = f[5];
                f[2] = f[2] * f[4];
                f.swap(4, 2);
                { let a = rg[4].wrapping_add(0x80u32); m.wrf64(a, f[4])?; }
                f.swap(3, 1);
                f[3] = f[3] * f[2];
                { let a = rg[4].wrapping_add(0x40u32); m.wrf64(a, f[3])?; }
                f[0] = f[0] * f[2];
                f.swap(1, 0);
                { let a = rg[4].wrapping_add(0x0u32); m.wrf64(a, f[1])?; }
                { let v = 0x1u32; rg[0] = v; }
                b = 5;
            }
            5 => {
                f[1] = m.rdf64((rg[4].wrapping_add(0x78u32)).wrapping_add(rg[0].wrapping_mul(8)))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x80u32))?; f[1] = f[1] * v; }
                { let a = (rg[4].wrapping_add(0x80u32)).wrapping_add(rg[0].wrapping_mul(8)); m.wrf64(a, f[1])?; }
                f[1] = m.rdf64((rg[4].wrapping_add(0x38u32)).wrapping_add(rg[0].wrapping_mul(8)))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x40u32))?; f[1] = f[1] * v; }
                { let a = (rg[4].wrapping_add(0x40u32)).wrapping_add(rg[0].wrapping_mul(8)); m.wrf64(a, f[1])?; }
                f[1] = m.rdf64((rg[4].wrapping_add(0xfffffff8u32)).wrapping_add(rg[0].wrapping_mul(8)))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x0u32))?; f[1] = f[1] * v; }
                { let a = (rg[4].wrapping_add(0x0u32)).wrapping_add(rg[0].wrapping_mul(8)); m.wrf64(a, f[1])?; }
                { let cf = fl.cf; let r = fl.alu(Alu::Add, rg[0], 1, 4); fl.cf = cf; rg[0] = r; }
                { let bv = 0x8u32; let av = rg[0]; let r = fl.alu(Alu::Cmp, av, bv, 4); }
                if fl.cond(5) { steps += 1; if steps > limit { return Err(EmuError::StepLimit); } b = 5; continue; }
                b = 6;
            }
            6 => {
                f[1] = m.rdf64(rg[2].wrapping_add(0x18u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0xa8u32))?; f[1] = f[1] * v; }
                { let v = m.rdf64(rg[4].wrapping_add(0xb8u32))?; f[1] = f[1] + v; }
                f[2] = m.rdf64(rg[2].wrapping_add(0x20u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x98u32))?; f[2] = f[2] * v; }
                f[1] = f[1] + f[2];
                f[2] = m.rdf64(rg[2].wrapping_add(0x18u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x88u32))?; f[2] = f[2] * v; }
                f[1] = f[1] + f[2];
                f[1] = f[1].abs();
                f[2] = f64::from_bits(0x3ff0000000000000);
                f[3] = f[0];
                { let v = m.rdf64(rg[2].wrapping_add(0x0u32))?; f[3] = f[3] * v; }
                f[4] = m.rdf64(rg[2].wrapping_add(0x8u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x90u32))?; f[4] = f[4] * v; }
                { let v = m.rdf64(rg[4].wrapping_add(0x80u32))?; f[4] = f[4] + v; }
                f[5] = m.rdf64(rg[2].wrapping_add(0x10u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0xa0u32))?; f[5] = f[5] * v; }
                f[4] = f[4] + f[5];
                { let v = m.rdf64(rg[4].wrapping_add(0xb0u32))?; f[4] = f[4] - v; }
                f[3] = f[3] * f[4];
                f.swap(3, 2);
                f[1] = f[1] + f[3];
                f[1] = f[2] / f[1];
                { let v = m.rdf64(rg[3].wrapping_add(0x18u32))?; f[1] = f[1] + v; }
                { let a = rg[3].wrapping_add(0xffffffe0u32); m.wrf64(a, f[1])?; }
                f[1] = m.rdf64(rg[2].wrapping_add(0x18u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x68u32))?; f[1] = f[1] * v; }
                { let v = m.rdf64(rg[4].wrapping_add(0x78u32))?; f[1] = f[1] + v; }
                f[2] = m.rdf64(rg[2].wrapping_add(0x20u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x58u32))?; f[2] = f[2] * v; }
                f[1] = f[1] + f[2];
                f[2] = m.rdf64(rg[2].wrapping_add(0x18u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x48u32))?; f[2] = f[2] * v; }
                f[1] = f[1] + f[2];
                f[1] = f[1].abs();
                f[2] = f64::from_bits(0x3ff0000000000000);
                f[3] = f[0];
                { let v = m.rdf64(rg[2].wrapping_add(0x0u32))?; f[3] = f[3] * v; }
                f[4] = m.rdf64(rg[2].wrapping_add(0x8u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x50u32))?; f[4] = f[4] * v; }
                { let v = m.rdf64(rg[4].wrapping_add(0x40u32))?; f[4] = f[4] + v; }
                f[5] = m.rdf64(rg[2].wrapping_add(0x10u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x60u32))?; f[5] = f[5] * v; }
                f[4] = f[4] + f[5];
                { let v = m.rdf64(rg[4].wrapping_add(0x70u32))?; f[4] = f[4] - v; }
                f[3] = f[3] * f[4];
                f.swap(3, 2);
                f[1] = f[1] + f[3];
                f[1] = f[2] / f[1];
                { let v = m.rdf64(rg[3].wrapping_add(0x20u32))?; f[1] = f[1] + v; }
                { let a = rg[3].wrapping_add(0xffffffe8u32); m.wrf64(a, f[1])?; }
                f[1] = m.rdf64(rg[2].wrapping_add(0x18u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x28u32))?; f[1] = f[1] * v; }
                { let v = m.rdf64(rg[4].wrapping_add(0x38u32))?; f[1] = f[1] + v; }
                f[2] = m.rdf64(rg[2].wrapping_add(0x20u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x18u32))?; f[2] = f[2] * v; }
                f[1] = f[1] + f[2];
                f[2] = m.rdf64(rg[2].wrapping_add(0x18u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x8u32))?; f[2] = f[2] * v; }
                f[1] = f[1] + f[2];
                f[1] = f[1].abs();
                f[2] = f64::from_bits(0x3ff0000000000000);
                f.swap(2, 0);
                { let v = m.rdf64(rg[2].wrapping_add(0x0u32))?; f[2] = f[2] * v; }
                f[3] = m.rdf64(rg[2].wrapping_add(0x8u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x10u32))?; f[3] = f[3] * v; }
                { let v = m.rdf64(rg[4].wrapping_add(0x0u32))?; f[3] = f[3] + v; }
                f[4] = m.rdf64(rg[2].wrapping_add(0x10u32))?;
                { let v = m.rdf64(rg[4].wrapping_add(0x20u32))?; f[4] = f[4] * v; }
                f[3] = f[3] + f[4];
                { let v = m.rdf64(rg[4].wrapping_add(0x30u32))?; f[3] = f[3] - v; }
                f[2] = f[2] * f[3];
                f.swap(2, 0);
                f[1] = f[1] + f[2];
                f[0] = f[0] / f[1];
                { let v = m.rdf64(rg[3].wrapping_add(0x28u32))?; f[0] = f[0] + v; }
                { let a = rg[3].wrapping_add(0xfffffff0u32); m.wrf64(a, f[0])?; }
                { let bv = 0xc0u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
                { let v = pop_l(m, &mut rg)?; rg[3] = v; }
                let r = pop_l(m, &mut rg)?; rg[ESP] = rg[ESP].wrapping_add(8);                              if r != RETURN_SENTINEL { match p.rets.iter().find(|e| e.0 == r).map(|e| e.1) { _ => return Err(unsup(r, "bad return".into())) } }                              m.st = f; return Ok(());
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

// LoResCIFS

pub(super) fn f_4e2c2e531ba0933f(m: &mut Machine, p: &Prog, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = m.regs;
    let mut fl = m.fl;
    let mut fsw = m.fsw_cc;
    let vb = rg[EDI].wrapping_sub(256);
    let vm = m.bytes_at::<200>(vb.wrapping_add(80))?;
    let mut r3: u64 = m.rd64u(0x10001018u32);
    let mut r4: u64 = m.rd64u(0x10001020u32);
    let mut r5: u64 = m.rd64u(0x10001028u32);
    let mut r6: u64 = m.rd64u(0x10001030u32);
    let mut r14: u64 = m.rd64u(0x10001070u32);
    let mut r32: u64 = m.rd64u(0x10001100u32);
    let mut r33: u64 = m.rd64u(0x10001108u32);
    let mut r34: u64 = m.rd64u(0x10001110u32);
    let mut s2009: u64 = m.rd64u(0x10007ec8u32);
    let mut s2010: u64 = m.rd64u(0x10007ed0u32);
    let mut s2011: u64 = m.rd64u(0x10007ed8u32);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
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
    'body: {
        'b10: {
        'b8: {
        'b7: {
        'b5: {
        'b4: {
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
        f[0] = f64::from_bits((((s2011 >> 32) | (s2012 << 32)) & u64::MAX));
        f[1] = f64::from_bits((((s2010 >> 32) | (s2011 << 32)) & u64::MAX));
        f[2] = f64::from_bits((((s2009 >> 32) | (s2010 << 32)) & u64::MAX));
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
        { let v: u64 = f[2].to_bits(); s2009 = (s2009 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2010 = (s2010 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        { let v: u64 = f[1].to_bits(); s2010 = (s2010 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2011 = (s2011 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        { let v: u64 = f[0].to_bits(); s2011 = (s2011 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2012 = (s2012 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        rg[2] = ((v23 >> 32) & 0xffffffffu64) as u32;
        { let bv = 0x2u32; let av = rg[2]; let r = fl.alu(Alu::And, av, bv, 4); rg[2] = r; }
        if fl.cond(5) { break 'b4; }
        // block 3
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
        break 'b5;
        } // 'b4
        // block 4
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
        } // 'b5
        // block 5
        f[0] = f64::from_bits((((s2011 >> 32) | (s2012 << 32)) & u64::MAX));
        f[1] = f64::from_bits((((s2010 >> 32) | (s2011 << 32)) & u64::MAX));
        f[2] = f64::from_bits((((s2009 >> 32) | (s2010 << 32)) & u64::MAX));
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
        { let v: u64 = f[2].to_bits(); s2009 = (s2009 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2010 = (s2010 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        { let v: u64 = f[1].to_bits(); s2010 = (s2010 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2011 = (s2011 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        { let v: u64 = f[0].to_bits(); s2011 = (s2011 & !(0xffffffffu64 << 32)) | ((v & 0xffffffffu64) << 32); s2012 = (s2012 & !0xffffffffu64) | ((v >> 32) & 0xffffffffu64); }
        f[0] = f64::from_bits((((s2009 >> 32) | (s2010 << 32)) & u64::MAX));
        f[0] = f[0] * f[0];
        f[1] = f64::from_bits((((s2010 >> 32) | (s2011 << 32)) & u64::MAX));
        f[1] = f[1] * f[1];
        f[0] = f[0] + f[1];
        f[0] = f[0].sqrt();
        f[1] = f64::from_bits(0x3ff0000000000000);
        f[0] = f[0] - f[1];
        { let v = (f32::from_bits(((v20 >> 32) & 0xffffffffu64) as u32) as f64); f[0] = f[0] * v; }
        f[1] = f64::from_bits((((s2011 >> 32) | (s2012 << 32)) & u64::MAX));
        { let v = (f32::from_bits(((v21 >> 0) & 0xffffffffu64) as u32) as f64); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        f[1] = f64::from_bits((((s2011 >> 32) | (s2012 << 32)) & u64::MAX));
        { let v = f64::from_bits(v30); f[1] = f[1] + v; }
        f[1] = f[1].abs();
        { let v = f64::from_bits(v30); f[1] = f[1] - v; }
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        { let bv = 0x41u32; let av = reg_get(&rg, 4, 1); let r = fl.alu(Alu::And, av, bv, 1); reg_set(&mut rg, 4, 1, r); }
        if fl.cond(5) { break 'b7; }
        // block 6
        f[0] = f[1];
        break 'b8;
        } // 'b7
        // block 7
        f[1] = f[1];
        } // 'b8
        // block 8
        rg[2] = ((v23 >> 32) & 0xffffffffu64) as u32;
        { let bv = 0x1u32; let av = rg[2]; let r = fl.alu(Alu::And, av, bv, 4); rg[2] = r; }
        if fl.cond(5) { break 'b10; }
        // block 9
        { let v = f64::from_bits(v28); f[0] = f[0] / v; }
        } // 'b10
        // block 10
        r14 = f[0].to_bits();
        f[0] = f64::from_bits((((v10 >> 32) | (v11 << 32)) & u64::MAX));
        r34 = f[0].to_bits();
        { let bv = 0x30u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        rg[ESP] = rg[ESP].wrapping_add(4); break 'body;
    }
    m.wr64u(0x10001018u32, r3);
    m.wr64u(0x10001020u32, r4);
    m.wr64u(0x10001028u32, r5);
    m.wr64u(0x10001070u32, r14);
    m.wr64u(0x10001100u32, r32);
    m.wr64u(0x10001110u32, r34);
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

// _F_MandalayFold4D

pub(super) fn f_5e299e82b7f6da6b(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
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
        { let v = f64::from_bits(v30); f[0] = f[0] - v; }
        f[0] = f[0].abs();
        { let v = f64::from_bits(v30); f[0] = f[0] - v; }
        r3 = f[0].to_bits();
        f[0] = f64::from_bits(r4);
        { let v = f64::from_bits(v29); f[0] = f[0] - v; }
        f[0] = f[0].abs();
        { let v = f64::from_bits(v29); f[0] = f[0] - v; }
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        { let v = f64::from_bits(v28); f[0] = f[0] - v; }
        f[0] = f[0].abs();
        { let v = f64::from_bits(v28); f[0] = f[0] - v; }
        r5 = f[0].to_bits();
        f[0] = f64::from_bits(r6);
        { let v = f64::from_bits(v27); f[0] = f[0] - v; }
        f[0] = f[0].abs();
        { let v = f64::from_bits(v27); f[0] = f[0] - v; }
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

// CrossMenger

pub(super) fn f_621449000c668362(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let vb = pvar.wrapping_sub(256);
    let vm = m.bytes_at::<88>(vb.wrapping_add(160))?;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r6: u64 = rec_get(m, it, pvar, 6);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
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
    'body: {
        'b2: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 32)) | (((rg[3] as u64) & 0xffffffffu64) << 32); }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 0)) | (((rg[6] as u64) & 0xffffffffu64) << 0); }
        rg[3] = rg[0];
        rg[6] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        rg[6] = ((r13 >> 0) & 0xffffffffu64) as u32;
        { let v = 0x7fffffffu32; rg[0] = v; }
        { let bv = rg[0]; let av = (((r5 >> 32) & 0xffffffffu64) as u32); let r = fl.alu(Alu::And, av, bv, 4); r5 = (r5 & !(0xffffffffu64 << 32)) | ((((r) as u64) & 0xffffffffu64) << 32); }
        { let bv = rg[0]; let av = (((r4 >> 32) & 0xffffffffu64) as u32); let r = fl.alu(Alu::And, av, bv, 4); r4 = (r4 & !(0xffffffffu64 << 32)) | ((((r) as u64) & 0xffffffffu64) << 32); }
        f[0] = f64::from_bits(r3);
        { let v = (f32::from_bits(((v22 >> 0) & 0xffffffffu64) as u32) as f64); f[0] = f[0] * v; }
        f[1] = f64::from_bits(r4);
        { let v = (f32::from_bits(((v21 >> 32) & 0xffffffffu64) as u32) as f64); f[1] = f[1] * v; }
        f[0] = f[0] + f[1];
        f[1] = f[0];
        f[1] = f[1].abs();
        f[0] = f[0] + f[1];
        f[0] = -f[0];
        f[1] = f[0];
        { let v = (f32::from_bits(((v22 >> 0) & 0xffffffffu64) as u32) as f64); f[1] = f[1] * v; }
        { let v = f64::from_bits(r3); f[1] = f[1] + v; }
        r3 = f[1].to_bits();
        { let v = (f32::from_bits(((v21 >> 32) & 0xffffffffu64) as u32) as f64); f[0] = f[0] * v; }
        { let v = f64::from_bits(r4); f[0] = f[0] + v; }
        r4 = f[0].to_bits();
        { let v = 0x7fffffffu32; rg[0] = v; }
        { let bv = rg[0]; let av = (((r4 >> 32) & 0xffffffffu64) as u32); let r = fl.alu(Alu::And, av, bv, 4); r4 = (r4 & !(0xffffffffu64 << 32)) | ((((r) as u64) & 0xffffffffu64) << 32); }
        f[0] = f64::from_bits(r4);
        f[1] = f64::from_bits(r5);
        fsw = fcompare_cc(f[1], f[0]);
        rg[EAX] = (rg[EAX] & 0xFFFF_0000) | (fsw | 0x3000) as u32;
        shift_reg_l(&mut rg, &mut fl, Shift::Shr, 4, 1, 1);
        if fl.cond(3) { break 'b2; }
        // block 1
        f.swap(1, 0);
        } // 'b2
        // block 2
        r5 = f[1].to_bits();
        { let v = f64::from_bits((((v20 >> 32) | (v21 << 32)) & u64::MAX)); f[0] = f[0] - v; }
        f[0] = f[0].abs();
        { let v = f64::from_bits((((v20 >> 32) | (v21 << 32)) & u64::MAX)); f[0] = f[0] + v; }
        r4 = f[0].to_bits();
        f[0] = f64::from_bits(r5);
        f[1] = f64::from_bits(r4);
        f[2] = f64::from_bits(r3);
        f[3] = f[1];
        { let v = (f32::from_bits(((v23 >> 32) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[4] = f[2];
        { let v = (f32::from_bits(((v23 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[0];
        { let v = (f32::from_bits(((v22 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[3] = f[3] + f[4];
        f[4] = f[1];
        { let v = (f32::from_bits(((v26 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[5] = f[2];
        { let v = (f32::from_bits(((v26 >> 0) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f[5] = f[0];
        { let v = (f32::from_bits(((v25 >> 32) & 0xffffffffu64) as u32) as f64); f[5] = f[5] * v; }
        f[4] = f[4] + f[5];
        f.swap(4, 1);
        { let v = (f32::from_bits(((v25 >> 0) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f.swap(4, 2);
        { let v = (f32::from_bits(((v24 >> 32) & 0xffffffffu64) as u32) as f64); f[4] = f[4] * v; }
        f[2] = f[2] + f[4];
        f.swap(3, 0);
        { let v = (f32::from_bits(((v24 >> 0) & 0xffffffffu64) as u32) as f64); f[3] = f[3] * v; }
        f[2] = f[2] + f[3];
        r3 = f[2].to_bits();
        r4 = f[1].to_bits();
        r5 = f[0].to_bits();
        f[0] = f64::from_bits(v30);
        f[1] = f64::from_bits(r6);
        f[1] = f[1] * f[0];
        r6 = f[1].to_bits();
        f[1] = f64::from_bits(r5);
        { let v = f64::from_bits(v27); f[1] = f[1] - v; }
        f[1] = f[1] * f[0];
        { let v = f64::from_bits(v27); f[1] = f[1] + v; }
        r5 = f[1].to_bits();
        f[1] = f64::from_bits(r4);
        { let v = f64::from_bits(v28); f[1] = f[1] - v; }
        f[1] = f[1] * f[0];
        { let v = f64::from_bits(v28); f[1] = f[1] + v; }
        r4 = f[1].to_bits();
        f[1] = f64::from_bits(r3);
        { let v = f64::from_bits(v29); f[1] = f[1] - v; }
        f[0] = f[0] * f[1];
        { let v = f64::from_bits(v29); f[0] = f[0] + v; }
        r3 = f[0].to_bits();
        rg[0] = rg[3];
        { rg[6] = ((s2013 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[3] = ((s2013 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
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

// BuddhiRotX3b

pub(super) fn f_62c00571d2e5f3a1(m: &mut Machine, p: &Prog, it: &mut Iteration, pvar: u32, max_steps: u64) -> R<()> {
    let _ = p;
    let mut f = [0f64; 8];
    let mut rg = direct_regs(m);
    let mut fl = Flags::default();
    let mut fsw = 0u16;
    let vb = pvar.wrapping_sub(256);
    let vm = m.bytes_at::<16>(vb.wrapping_add(232))?;
    let mut r3: u64 = rec_get(m, it, pvar, 3);
    let mut r4: u64 = rec_get(m, it, pvar, 4);
    let mut r5: u64 = rec_get(m, it, pvar, 5);
    let mut r10: u64 = rec_get(m, it, pvar, 10);
    let mut r11: u64 = rec_get(m, it, pvar, 11);
    let mut r12: u64 = rec_get(m, it, pvar, 12);
    let mut r13: u64 = rec_get(m, it, pvar, 13);
    let mut s2012: u64 = m.rd64u(0x10007ee0u32);
    let mut s2013: u64 = m.rd64u(0x10007ee8u32);
    let mut s2014: u64 = m.rd64u(0x10007ef0u32);
    let mut s2015: u64 = m.rd64u(0x10007ef8u32);
    let mut v29: u64 = cell(vm, 0);
    let mut v30: u64 = cell(vm, 8);
    'body: {
        'b34: {
        'b35: {
        'b32: {
        'b30: {
        'b28: {
        'b26: {
        'b24: {
        'b22: {
        'b21: {
        'b20: {
        'b18: {
        'b16: {
        'b14: {
        'b12: {
        'b36: {
        'b10: {
        'b8: {
        'b6: {
        'b4: {
        'b2: {
        // block 0
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2014 = (s2014 & !(0xffffffffu64 << 0)) | (((rg[5] as u64) & 0xffffffffu64) << 0); }
        rg[5] = rg[4];
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 32)) | (((rg[7] as u64) & 0xffffffffu64) << 32); }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2013 = (s2013 & !(0xffffffffu64 << 0)) | (((rg[6] as u64) & 0xffffffffu64) << 0); }
        { rg[ESP] = rg[ESP].wrapping_sub(4); s2012 = (s2012 & !(0xffffffffu64 << 32)) | (((rg[3] as u64) & 0xffffffffu64) << 32); }
        { let bv = 0x4u32; let av = rg[4]; let r = fl.alu(Alu::Sub, av, bv, 4); rg[4] = r; }
        rg[1] = ((s2015 >> 0) & 0xffffffffu64) as u32;
        f[0] = f64::from_bits(r3);
        f[1] = f64::from_bits(r4);
        rg[2] = rg[1].wrapping_add(0xffffffc8u32);
        f[2] = f[0];
        f[3] = f[1];
        rg[3] = ((r13 >> 0) & 0xffffffffu64) as u32;
        f[3] = f[3] * f[1];
        f.swap(3, 2);
        f[3] = f[3] * f[0];
        rg[0] = rg[1].wrapping_add(0xffffffe8u32);
        f[2] = f[2] + f[3];
        s2012 = (s2012 & !(0xffffffffu64 << 0)) | (((rg[0] as u64) & 0xffffffffu64) << 0);
        rg[0] = ((v30 >> 32) & 0xffffffffu64) as u32;
        f[2] = f[2].sqrt();
        rg[7] = rg[3].wrapping_add(0xfffffff4u32);
        f[3] = f[0];
        f.swap(3, 2);
        f[4] = f64::from_bits(0x3ff0000000000000);
        f[3] = f[4] / f[3];
        { let bv = 0x8u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        f[4] = f[1];
        if fl.cond(4) { break 'b2; }
        // block 1
        f.swap(4, 2);
        f[4] = f[4].abs();
        f.swap(4, 2);
        } // 'b2
        // block 2
        { let bv = 0x10u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        if fl.cond(4) { break 'b4; }
        // block 3
        f[4] = f[4];
        f[4] = f[1];
        f[4] = f[4].abs();
        } // 'b4
        // block 4
        f[5] = f[0];
        f.swap(5, 4);
        f[5] = f[5] * f[1];
        f.swap(5, 4);
        { let bv = 0x4u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        f[2] = f[2] * f[5];
        f[2] = f[2] - f[4];
        if fl.cond(4) { break 'b6; }
        // block 5
        f.swap(3, 2);
        f[3] = f[3].abs();
        f.swap(3, 2);
        } // 'b6
        // block 6
        { let bv = 0x1u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        if fl.cond(4) { break 'b8; }
        // block 7
        f.swap(3, 0);
        f[3] = f[3].abs();
        f.swap(3, 0);
        } // 'b8
        // block 8
        { let bv = 0x2u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        if fl.cond(4) { break 'b10; }
        // block 9
        f.swap(3, 1);
        f[3] = f[3].abs();
        f.swap(3, 1);
        } // 'b10
        // block 10
        rg[6] = ((v29 >> 0) & 0xffffffffu64) as u32;
        f[2] = f[2] * f[3];
        f.swap(3, 0);
        f[1] = f[1] * f[3];
        { let bv = 0x1u32; let av = rg[6]; fl.alu(Alu::And, av, bv, 4); }
        r3 = f[2].to_bits();
        f[1] = f[1] + f[1];
        f[0] = f[0] * f[1];
        r4 = f[0].to_bits();
        if fl.cond(5) { break 'b21; }
        // block 11
        f[1] = f64::from_bits(r5);
        f[2] = f[0];
        rg[0] = ((v30 >> 0) & 0xffffffffu64) as u32;
        f[3] = f[1];
        f.swap(3, 2);
        f[3] = f[3] * f[0];
        f.swap(3, 2);
        f[3] = f[3] * f[1];
        f[2] = f[2] + f[3];
        f[3] = f[0];
        f.swap(3, 2);
        f[3] = f[3].sqrt();
        f[4] = f64::from_bits(0x3ff0000000000000);
        f[3] = f[4] / f[3];
        { let bv = 0x8u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        f[4] = f[1];
        if fl.cond(5) { break 'b36; }
        break 'b12;
        } // 'b36
        // block 36
        f.swap(4, 2);
        f[4] = f[4].abs();
        f.swap(4, 2);
        
        } // 'b12
        // block 12
        { let bv = 0x10u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        if fl.cond(4) { break 'b14; }
        // block 13
        f[4] = f[4];
        f[4] = f[1];
        f[4] = f[4].abs();
        } // 'b14
        // block 14
        f[5] = f[0];
        f.swap(5, 4);
        f[5] = f[5] * f[1];
        f.swap(5, 4);
        { let bv = 0x4u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        f[2] = f[2] * f[5];
        f[2] = f[2] - f[4];
        if fl.cond(4) { break 'b16; }
        // block 15
        f.swap(3, 2);
        f[3] = f[3].abs();
        f.swap(3, 2);
        } // 'b16
        // block 16
        { let bv = 0x1u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        if fl.cond(4) { break 'b18; }
        // block 17
        f.swap(3, 0);
        f[3] = f[3].abs();
        f.swap(3, 0);
        } // 'b18
        // block 18
        { let bv = 0x2u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        if fl.cond(4) { break 'b20; }
        // block 19
        f.swap(3, 1);
        f[3] = f[3].abs();
        f.swap(3, 1);
        } // 'b20
        // block 20
        f.swap(3, 0);
        f[1] = f[1] * f[3];
        f[2] = f[2] * f[0];
        f.swap(2, 1);
        rg[3] = ((s2012 >> 0) & 0xffffffffu64) as u32;
        f[2] = f[2] + f[2];
        r5 = f[2].to_bits();
        r4 = f[1].to_bits();
        { let v = f64::from_bits(r5); f[0] = f[0] * v; }
        r5 = f[0].to_bits();
        break 'b22;
        } // 'b21
        // block 21
        f[0] = f[0];
        } // 'b22
        // block 22
        f[0] = f64::from_bits(r3);
        f[1] = f64::from_bits(r5);
        rg[0] = ((v29 >> 32) & 0xffffffffu64) as u32;
        f[2] = f[0];
        f[3] = f[1];
        f[3] = f[3] * f[1];
        f.swap(3, 2);
        f[3] = f[3] * f[0];
        f[2] = f[2] + f[3];
        f[3] = f[0];
        f.swap(3, 2);
        f[3] = f[3].sqrt();
        f[4] = f64::from_bits(0x3ff0000000000000);
        f[3] = f[4] / f[3];
        { let bv = 0x8u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        f[4] = f[1];
        if fl.cond(4) { break 'b24; }
        // block 23
        f.swap(4, 2);
        f[4] = f[4].abs();
        f.swap(4, 2);
        } // 'b24
        // block 24
        { let bv = 0x10u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        if fl.cond(4) { break 'b26; }
        // block 25
        f[4] = f[4];
        f[4] = f[1];
        f[4] = f[4].abs();
        } // 'b26
        // block 26
        f[5] = f[0];
        f.swap(5, 4);
        f[5] = f[5] * f[1];
        f.swap(5, 4);
        { let bv = 0x4u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        f[2] = f[2] * f[5];
        f[2] = f[2] - f[4];
        if fl.cond(4) { break 'b28; }
        // block 27
        f.swap(3, 2);
        f[3] = f[3].abs();
        f.swap(3, 2);
        } // 'b28
        // block 28
        { let bv = 0x1u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        if fl.cond(4) { break 'b30; }
        // block 29
        f.swap(3, 0);
        f[3] = f[3].abs();
        f.swap(3, 0);
        } // 'b30
        // block 30
        { let bv = 0x2u32; let av = reg_get(&rg, 0, 1); fl.alu(Alu::And, av, bv, 1); }
        if fl.cond(4) { break 'b32; }
        // block 31
        f.swap(3, 1);
        f[3] = f[3].abs();
        f.swap(3, 1);
        } // 'b32
        // block 32
        f.swap(3, 0);
        f[1] = f[1] * f[3];
        { let bv = 0x2u32; let av = rg[6]; let r = fl.alu(Alu::And, av, bv, 4); rg[6] = r; }
        f[2] = f[2] * f[0];
        f.swap(2, 1);
        f[2] = f[2] + f[2];
        f[0] = f[0] * f[2];
        if fl.cond(4) { break 'b35; }
        // block 33
        f[2] = f64::from_bits(r4);
        f[3] = f[1];
        f[4] = f[2];
        f.swap(4, 3);
        f[4] = f[4] * f[1];
        f.swap(4, 3);
        f[4] = f[4] * f[2];
        f[3] = f[3] + f[4];
        f[4] = f[0];
        f[4] = f[4] * f[0];
        f[3] = f[3] + f[4];
        break 'b34;
        } // 'b35
        // block 35
        f[2] = f64::from_bits(r4);
        f[3] = f[1];
        f[4] = f[2];
        f.swap(4, 3);
        f[4] = f[4] * f[1];
        f.swap(4, 3);
        f[4] = f[4] * f[2];
        f[3] = f[3] + f[4];
        f[4] = f[0];
        f[4] = f[4] * f[0];
        f[3] = f[3] + f[4];
        f[3] = f[3].sqrt();
        
        } // 'b34
        // block 34
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
        { let bv = 0x4u32; let av = rg[4]; let r = fl.alu(Alu::Add, av, bv, 4); rg[4] = r; }
        { rg[3] = ((s2012 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[6] = ((s2013 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[7] = ((s2013 >> 32) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        { rg[5] = ((s2014 >> 0) & 0xffffffffu64) as u32; rg[ESP] = rg[ESP].wrapping_add(4); }
        rg[ESP] = rg[ESP].wrapping_add(12); break 'body;
    }
    rec_set(m, it, 3, r3);
    rec_set(m, it, 4, r4);
    rec_set(m, it, 5, r5);
    m.wr64u(0x10007ee0u32, s2012);
    m.wr64u(0x10007ee8u32, s2013);
    m.wr64u(0x10007ef0u32, s2014);
    Ok(())
}

// _T_SqrtAdd
