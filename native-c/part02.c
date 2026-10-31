/* Generated native C formula calculations. See tools/generate-native-c.py. */
#include "runtime.h"
int cn_f_1c9a2f979ccd5056(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+216))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_105;
__auto_type cn_init_118 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_118;
__auto_type cn_init_131 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_131;
__auto_type cn_init_144 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_144;
__auto_type cn_init_157 = cn_cell(vm,0); uint64_t v27 = cn_init_157;
__auto_type cn_init_170 = cn_cell(vm,8); uint64_t v28 = cn_init_170;
__auto_type cn_init_183 = cn_cell(vm,16); uint64_t v29 = cn_init_183;
__auto_type cn_init_196 = cn_cell(vm,24); uint64_t v30 = cn_init_196;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r4));
(f[1]=cn_double(v28));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(v30));
(f[0]=(f[0]+f[1]));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v27));
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
(f[1]=cn_double(v29));
(f[0]=(f[0]-f[1]));
(r4=cn_bits(f[0]));
{
(rg[6]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_1d53e7c915b02656(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+168))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,0); uint64_t v21 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,8); uint64_t v22 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,16); uint64_t v23 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,24); uint64_t v24 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,32); uint64_t v25 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,40); uint64_t v26 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,48); uint64_t v27 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,56); uint64_t v28 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,64); uint64_t v29 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,72); uint64_t v30 = cn_init_331;
{
{
{
{
__auto_type cn_init_346 = 0xffffffe4U; __auto_type bv = cn_init_346;
__auto_type cn_init_354 = rg[4]; __auto_type av = cn_init_354;
__auto_type cn_init_372 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_372;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_401 = r5; uint64_t s = cn_init_401;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_431 = (CN_U2){v28,v29}; CN_U2 s = cn_init_431;
__auto_type cn_init_441 = m->xmm[0]; __auto_type a = cn_init_441;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_511 = v28; uint64_t s = cn_init_511;
__auto_type cn_init_524 = m->xmm[1][0]; __auto_type a = cn_init_524;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_571 = (CN_U2){v24,v25}; CN_U2 s = cn_init_571;
__auto_type cn_init_581 = m->xmm[0]; __auto_type a = cn_init_581;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_651 = v26; uint64_t s = cn_init_651;
__auto_type cn_init_664 = m->xmm[1][0]; __auto_type a = cn_init_664;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_701 = 0x0U; __auto_type bv = cn_init_701;
__auto_type cn_init_718 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_718;
__auto_type cn_init_736 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_736;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_757 = r32; uint64_t s = cn_init_757;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_779 = v28; uint64_t s = cn_init_779;
__auto_type cn_init_792 = m->xmm[5][0]; __auto_type a = cn_init_792;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(s2012=m->xmm[0][0]);
(s2013=m->xmm[0][1]);
(s2014=m->xmm[1][0]);
(f[0]=cn_double(s2014));
(f[0]=fabs(f[0]));
(s2014=cn_bits(f[0]));
(f[0]=cn_double(s2012));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2013));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2012=cn_bits(f[0]));
(f[1]=f[0]);
{
__auto_type cn_init_1060 = cn_double(s2014); __auto_type v = cn_init_1060;
(f[1]=(f[1]*v));
}
cn_swap(f,1,0);
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_1131 = cn_double(v30); __auto_type v = cn_init_1131;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_1170 = cn_double(v23); __auto_type v = cn_init_1170;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2014));
{
__auto_type cn_init_1222 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1222;
(f[1]=(f[1]-v));
}
(f[2]=f[1]);
(f[2]=fabs(f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_1295 = 0x0U; __auto_type bv = cn_init_1295;
__auto_type cn_init_1312 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_1312;
__auto_type cn_init_1330 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1330;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
{
__auto_type cn_init_1354 = cn_double(v28); __auto_type v = cn_init_1354;
(f[0]=(f[0]/v));
}
}
cn_break_b4:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_1385 = 0x1cU; __auto_type bv = cn_init_1385;
__auto_type cn_init_1393 = rg[4]; __auto_type av = cn_init_1393;
__auto_type cn_init_1411 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1411;
(rg[4]=r);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10001070U,r14);
cn_wr64u(m,0x10001100U,r32);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_1e2a7e409a31e0cc(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+184))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v23 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,8); uint64_t v24 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,16); uint64_t v25 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,24); uint64_t v26 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,32); uint64_t v27 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,40); uint64_t v28 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,48); uint64_t v29 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,56); uint64_t v30 = cn_init_299;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r6));
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[4]=f[3]);
{
__auto_type cn_init_523 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_523;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_571 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_571;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_634 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_634;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_697 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_697;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r3=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_771 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_771;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_819 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_819;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_882 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_882;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_945 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_945;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r4=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_1019 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1019;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1067 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1067;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1130 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1130;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1193 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1193;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r5=cn_bits(f[4]));
{
__auto_type cn_init_1257 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1257;
(f[3]=(f[3]*v));
}
cn_swap(f,3,2);
{
__auto_type cn_init_1304 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1304;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
cn_swap(f,2,1);
{
__auto_type cn_init_1366 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1366;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
cn_swap(f,1,0);
{
__auto_type cn_init_1428 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1428;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r6=cn_bits(f[0]));
{
(rg[6]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_1edf5f95d0f22940(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_58 = cn_rd64(m,CN_REC+8*(0)); uint64_t r0 = cn_init_58;
__auto_type cn_init_75 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_75;
__auto_type cn_init_92 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_92;
__auto_type cn_init_109 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_109;
__auto_type cn_init_126 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_126;
__auto_type cn_init_143 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_143;
__auto_type cn_init_160 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_160;
__auto_type cn_init_177 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_177;
__auto_type cn_init_190 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_216;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(f[0]=cn_double(r6));
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(r10=cn_bits(f[3]));
(r11=cn_bits(f[2]));
(r12=cn_bits(f[1]));
(r0=cn_bits(f[0]));
{
(rg[6]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(0),r0);
cn_wr64(m,CN_REC+8*(10),r10);
cn_wr64(m,CN_REC+8*(11),r11);
cn_wr64(m,CN_REC+8*(12),r12);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_1fc56909b67e214a(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_44 = 0ULL; __auto_type steps = cn_init_44;
__auto_type cn_init_49 = max_steps; __auto_type limit = cn_init_49;
__auto_type cn_init_62 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+112))); unsigned char * vm = cn_init_82;
__auto_type cn_init_95 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_95;
__auto_type cn_init_108 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_108;
__auto_type cn_init_121 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_121;
__auto_type cn_init_134 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_134;
__auto_type cn_init_147 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_147;
__auto_type cn_init_160 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_160;
__auto_type cn_init_173 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_173;
__auto_type cn_init_186 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_186;
__auto_type cn_init_199 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_199;
__auto_type cn_init_212 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_212;
__auto_type cn_init_225 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_225;
__auto_type cn_init_238 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_238;
__auto_type cn_init_251 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_251;
__auto_type cn_init_264 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_264;
__auto_type cn_init_277 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_277;
__auto_type cn_init_290 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_290;
__auto_type cn_init_303 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_303;
__auto_type cn_init_316 = cn_cell(vm,0); uint64_t v14 = cn_init_316;
__auto_type cn_init_329 = cn_cell(vm,8); uint64_t v15 = cn_init_329;
__auto_type cn_init_342 = cn_cell(vm,16); uint64_t v16 = cn_init_342;
__auto_type cn_init_355 = cn_cell(vm,24); uint64_t v17 = cn_init_355;
__auto_type cn_init_368 = cn_cell(vm,32); uint64_t v18 = cn_init_368;
__auto_type cn_init_381 = cn_cell(vm,40); uint64_t v19 = cn_init_381;
__auto_type cn_init_394 = cn_cell(vm,48); uint64_t v20 = cn_init_394;
__auto_type cn_init_407 = cn_cell(vm,56); uint64_t v21 = cn_init_407;
__auto_type cn_init_420 = cn_cell(vm,64); uint64_t v22 = cn_init_420;
__auto_type cn_init_433 = cn_cell(vm,72); uint64_t v23 = cn_init_433;
__auto_type cn_init_446 = cn_cell(vm,80); uint64_t v24 = cn_init_446;
__auto_type cn_init_459 = cn_cell(vm,88); uint64_t v25 = cn_init_459;
__auto_type cn_init_472 = cn_cell(vm,96); uint64_t v26 = cn_init_472;
__auto_type cn_init_485 = cn_cell(vm,104); uint64_t v27 = cn_init_485;
__auto_type cn_init_498 = cn_cell(vm,112); uint64_t v28 = cn_init_498;
__auto_type cn_init_511 = cn_cell(vm,120); uint64_t v29 = cn_init_511;
__auto_type cn_init_524 = cn_cell(vm,128); uint64_t v30 = cn_init_524;
__auto_type cn_init_537 = cn_cell(vm,144); uint64_t v32 = cn_init_537;
{
{
{
{
{
{
__auto_type cn_init_558 = 0xffffffa6U; __auto_type bv = cn_init_558;
__auto_type cn_init_566 = rg[4]; __auto_type av = cn_init_566;
__auto_type cn_init_584 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_584;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_613 = r5; uint64_t s = cn_init_613;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_643 = (CN_U2){v28,v29}; CN_U2 s = cn_init_643;
__auto_type cn_init_653 = m->xmm[0]; __auto_type a = cn_init_653;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_723 = v28; uint64_t s = cn_init_723;
__auto_type cn_init_736 = m->xmm[1][0]; __auto_type a = cn_init_736;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_783 = m->xmm[0][0]; uint64_t v = cn_init_783;
(s2004=(((s2004&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2005=(((s2005&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_842 = m->xmm[0][1]; uint64_t v = cn_init_842;
(s2005=(((s2005&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2006=(((s2006&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_901 = m->xmm[1][0]; uint64_t v = cn_init_901;
(s2006=(((s2006&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2007=(((s2007&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_960 = (CN_U2){v24,v25}; CN_U2 s = cn_init_960;
__auto_type cn_init_970 = m->xmm[0]; __auto_type a = cn_init_970;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_1040 = v26; uint64_t s = cn_init_1040;
__auto_type cn_init_1053 = m->xmm[1][0]; __auto_type a = cn_init_1053;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_1090 = 0x0U; __auto_type bv = cn_init_1090;
__auto_type cn_init_1107 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_1107;
__auto_type cn_init_1125 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1125;
}
if(cn_cond(fl,12)){
goto cn_break_b2;
}
{
__auto_type cn_init_1146 = r32; uint64_t s = cn_init_1146;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_1168 = v28; uint64_t s = cn_init_1168;
__auto_type cn_init_1181 = m->xmm[5][0]; __auto_type a = cn_init_1181;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(f[0]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_1288 = cn_bits(f[0]); uint64_t v = cn_init_1288;
(s2012=(((s2012&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2013=(((s2013&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(v32));
(r14=cn_bits(f[0]));
(rg[2]=((uint32_t)(((((v19>>0))&0xffffffffULL)))));
{
__auto_type cn_init_1377 = 0x1fU; __auto_type bv = cn_init_1377;
__auto_type cn_init_1385 = rg[2]; __auto_type av = cn_init_1385;
__auto_type cn_init_1403 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1403;
(rg[2]=r);
}
{
__auto_type cn_init_1417 = 0x0U; __auto_type bv = cn_init_1417;
__auto_type cn_init_1425 = rg[2]; __auto_type av = cn_init_1425;
__auto_type cn_init_1443 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1443;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
{
__auto_type cn_init_1462 = 0x1U; __auto_type v = cn_init_1462;
(rg[2]=v);
}
}
cn_break_b4:;
cn_continue_l4:;
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
(f[0]=cn_double(((((((s2006>>16))|((s2007<<48))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2004>>16))|((s2005<<48))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1642 = (((double)(cn_float(((uint32_t)(((((v15>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1642;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1690 = (((double)(cn_float(((uint32_t)(((((v15>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1690;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1753 = (((double)(cn_float(((uint32_t)(((((v14>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1753;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1816 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1816;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1864 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1864;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1927 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1927;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1989 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1989;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_2036 = (((double)(cn_float(((uint32_t)(((((v16>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2036;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2098 = (((double)(cn_float(((uint32_t)(((((v16>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2098;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_2137 = cn_double(v30); __auto_type v = cn_init_2137;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_2165 = cn_bits(f[2]); uint64_t v = cn_init_2165;
(s2007=(((s2007&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2008=(((s2008&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[2]=fabs(f[2]));
{
__auto_type cn_init_2237 = cn_bits(f[2]); uint64_t v = cn_init_2237;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_2291 = cn_double(v24); __auto_type v = cn_init_2291;
(f[2]=(f[2]-v));
}
{
__auto_type cn_init_2319 = cn_bits(f[2]); uint64_t v = cn_init_2319;
(s2004=(((s2004&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2005=(((s2005&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_2373 = cn_double(v30); __auto_type v = cn_init_2373;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2401 = cn_bits(f[1]); uint64_t v = cn_init_2401;
(s2008=(((s2008&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2009=(((s2009&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[1]=fabs(f[1]));
(f[2]=f[1]);
(f[3]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
{
__auto_type cn_init_2539 = 0x41U; __auto_type bv = cn_init_2539;
__auto_type cn_init_2552 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2552;
__auto_type cn_init_2570 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2570;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
(f[2]=f[3]);
goto cn_break_b7;
}
cn_break_b6:;
(f[3]=f[3]);
}
cn_break_b7:;
{
__auto_type cn_init_2636 = cn_bits(f[2]); uint64_t v = cn_init_2636;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_2690 = cn_double(v25); __auto_type v = cn_init_2690;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_2718 = cn_bits(f[1]); uint64_t v = cn_init_2718;
(s2005=(((s2005&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2006=(((s2006&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_2772 = cn_double(v30); __auto_type v = cn_init_2772;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2800 = cn_bits(f[0]); uint64_t v = cn_init_2800;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=fabs(f[0]));
(f[1]=f[0]);
(f[2]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_2938 = 0x41U; __auto_type bv = cn_init_2938;
__auto_type cn_init_2951 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2951;
__auto_type cn_init_2969 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2969;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b9;
}
(f[1]=f[2]);
goto cn_break_b10;
}
cn_break_b9:;
(f[2]=f[2]);
}
cn_break_b10:;
{
__auto_type cn_init_3035 = cn_bits(f[1]); uint64_t v = cn_init_3035;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_3089 = cn_double(v26); __auto_type v = cn_init_3089;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_3117 = cn_bits(f[0]); uint64_t v = cn_init_3117;
(s2006=(((s2006&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2007=(((s2007&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2006>>16))|((s2007<<48))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2004>>16))|((s2005<<48))))&0xffffffffffffffffULL))));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_3287 = 0x41U; __auto_type bv = cn_init_3287;
__auto_type cn_init_3300 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3300;
__auto_type cn_init_3318 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3318;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b12;
}
cn_swap(f,2,1);
}
cn_break_b12:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_3397 = 0x41U; __auto_type bv = cn_init_3397;
__auto_type cn_init_3410 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3410;
__auto_type cn_init_3428 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3428;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b14;
}
cn_swap(f,2,0);
}
cn_break_b14:;
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_3516 = 0x41U; __auto_type bv = cn_init_3516;
__auto_type cn_init_3529 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3529;
__auto_type cn_init_3547 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3547;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b16;
}
cn_swap(f,2,0);
}
cn_break_b16:;
{
__auto_type cn_init_3610 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3610;
(f[2]=(f[2]-v));
}
{
__auto_type cn_init_3638 = cn_bits(f[2]); uint64_t v = cn_init_3638;
(s2005=(((s2005&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2006=(((s2006&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_3708 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3708;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_3736 = cn_bits(f[1]); uint64_t v = cn_init_3736;
(s2004=(((s2004&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2005=(((s2005&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_3806 = cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3806;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_3834 = cn_bits(f[0]); uint64_t v = cn_init_3834;
(s2006=(((s2006&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2007=(((s2007&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2006>>16))|((s2007<<48))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2004>>16))|((s2005<<48))))&0xffffffffffffffffULL))));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_4004 = 0x41U; __auto_type bv = cn_init_4004;
__auto_type cn_init_4017 = cn_reg_get(rg,4,1); __auto_type av = cn_init_4017;
__auto_type cn_init_4035 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_4035;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b18;
}
cn_swap(f,2,1);
}
cn_break_b18:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_4114 = 0x41U; __auto_type bv = cn_init_4114;
__auto_type cn_init_4127 = cn_reg_get(rg,4,1); __auto_type av = cn_init_4127;
__auto_type cn_init_4145 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_4145;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b20;
}
cn_swap(f,2,0);
}
cn_break_b20:;
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_4233 = 0x41U; __auto_type bv = cn_init_4233;
__auto_type cn_init_4246 = cn_reg_get(rg,4,1); __auto_type av = cn_init_4246;
__auto_type cn_init_4264 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_4264;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b22;
}
cn_swap(f,2,0);
}
cn_break_b22:;
{
__auto_type cn_init_4315 = cn_bits(f[2]); uint64_t v = cn_init_4315;
(s2005=(((s2005&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2006=(((s2006&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_4373 = cn_bits(f[1]); uint64_t v = cn_init_4373;
(s2004=(((s2004&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2005=(((s2005&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_4431 = cn_bits(f[0]); uint64_t v = cn_init_4431;
(s2006=(((s2006&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2007=(((s2007&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4513 = cn_double(v30); __auto_type v = cn_init_4513;
(f[0]=(f[0]*v));
}
(f[0]=fabs(f[0]));
(f[1]=f[0]);
{
__auto_type cn_init_4565 = cn_bits(f[1]); uint64_t v = cn_init_4565;
(s2012=(((s2012&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2013=(((s2013&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[1]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_4647 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4647;
(f[1]=(v-f[1]));
}
(f[2]=cn_double(((((((s2004>>16))|((s2005<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4713 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4713;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4779 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4779;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(v30));
(f[4]=cn_double(0x0));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_4874 = 0x41U; __auto_type bv = cn_init_4874;
__auto_type cn_init_4887 = cn_reg_get(rg,4,1); __auto_type av = cn_init_4887;
__auto_type cn_init_4905 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_4905;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b24;
}
(f[2]=-f[2]);
}
cn_break_b24:;
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_4986 = 0x41U; __auto_type bv = cn_init_4986;
__auto_type cn_init_4999 = cn_reg_get(rg,4,1); __auto_type av = cn_init_4999;
__auto_type cn_init_5017 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5017;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b26;
}
(f[1]=f[2]);
goto cn_break_b27;
}
cn_break_b26:;
(f[2]=f[2]);
}
cn_break_b27:;
(f[0]=(f[1]/f[0]));
(f[1]=cn_double(r14));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_5138 = 0x41U; __auto_type bv = cn_init_5138;
__auto_type cn_init_5151 = cn_reg_get(rg,4,1); __auto_type av = cn_init_5151;
__auto_type cn_init_5169 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5169;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b29;
}
(f[0]=f[1]);
goto cn_break_b30;
}
cn_break_b29:;
(f[1]=f[1]);
}
cn_break_b30:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_5237 = 0x0U; __auto_type bv = cn_init_5237;
__auto_type cn_init_5254 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_5254;
__auto_type cn_init_5272 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_5272;
}
if(cn_cond(fl,15)){
goto cn_break_b32;
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2008>>16))|((s2009<<48))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5384 = cn_bits(f[2]); uint64_t v = cn_init_5384;
(s2004=(((s2004&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2005=(((s2005&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_5442 = cn_bits(f[1]); uint64_t v = cn_init_5442;
(s2005=(((s2005&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2006=(((s2006&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_5500 = cn_bits(f[0]); uint64_t v = cn_init_5500;
(s2006=(((s2006&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2007=(((s2007&~0xffffULL))|((((v>>48))&0xffffULL))));
}
}
cn_break_b32:;
{
__auto_type cn_init_5553 = rg[2]; __auto_type v = cn_init_5553;
__auto_type cn_init_5560 = fl.cf; __auto_type cf = cn_init_5560;
__auto_type cn_init_5578 = cn_alu(&fl,Alu_Sub,v,1,4); __auto_type r = cn_init_5578;
(fl.cf=cf);
(rg[2]=r);
}
if(cn_cond(fl,15)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l4;
}
goto cn_break_b33;
}
goto cn_continue_l4;
cn_break_l4:;
}
cn_break_b33:;
(f[0]=cn_double(r14));
{
__auto_type cn_init_5645 = 0x0U; __auto_type bv = cn_init_5645;
__auto_type cn_init_5662 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_5662;
__auto_type cn_init_5680 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_5680;
}
if(cn_cond(fl,12)){
goto cn_break_b35;
}
{
__auto_type cn_init_5704 = cn_double(v28); __auto_type v = cn_init_5704;
(f[0]=(f[0]/v));
}
}
cn_break_b35:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_5735 = 0x5aU; __auto_type bv = cn_init_5735;
__auto_type cn_init_5743 = rg[4]; __auto_type av = cn_init_5743;
__auto_type cn_init_5761 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_5761;
(rg[4]=r);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10001070U,r14);
cn_wr64u(m,0x10001100U,r32);
cn_wr64u(m,0x10007ea0U,s2004);
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_2029faef222702b4(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;
__auto_type cn_init_11 = (CN_D8){0}; __auto_type f = cn_init_11;
__auto_type cn_init_19 = m->regs; __auto_type rg = cn_init_19;
__auto_type cn_init_27 = m->fl; __auto_type fl = cn_init_27;
__auto_type cn_init_35 = m->fsw_cc; __auto_type fsw = cn_init_35;
__auto_type cn_init_43 = m->steps; __auto_type steps = cn_init_43;
__auto_type cn_init_50 = (steps+max_steps); __auto_type limit = cn_init_50;
{
__auto_type cn_init_59 = 0; uint32_t b = cn_init_59;
for(;;){
switch(b){
case 0:
{
{
__auto_type cn_init_76 = rg[5]; __auto_type v = cn_init_76;
cn_push_lu(m,rg,v);
}
(rg[5]=rg[4]);
{
__auto_type cn_init_107 = rg[0]; __auto_type v = cn_init_107;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_128 = rg[6]; __auto_type v = cn_init_128;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_149 = rg[7]; __auto_type v = cn_init_149;
cn_push_lu(m,rg,v);
}
(rg[6]=cn_rd32u(m,((uint32_t)(rg[5]+0x8U))));
(rg[7]=cn_rd32u(m,((uint32_t)(rg[6]+0x30U))));
(f[0]=cn_rdf64u(m,((uint32_t)(rg[6]+0x38U))));
{
__auto_type cn_init_244 = cn_floadu(m,FKind_F64,((uint32_t)(rg[7]+0xfffffff0U))); __auto_type v = cn_init_244;
(fsw=cn_compare(f[0],v));
}
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_285 = 0x41U; __auto_type bv = cn_init_285;
__auto_type cn_init_298 = cn_reg_get(rg,4,1); __auto_type av = cn_init_298;
__auto_type cn_init_316 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_316;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=2);
continue;
}
(b=1);
}
break;
case 1:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffe0U))));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=5);
continue;
}
break;
case 2:
{
{
__auto_type cn_init_442 = cn_floadu(m,FKind_F64,((uint32_t)(rg[7]+0xffffffe8U))); __auto_type v = cn_init_442;
(fsw=cn_compare(f[0],v));
}
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_483 = 0x41U; __auto_type bv = cn_init_483;
__auto_type cn_init_496 = cn_reg_get(rg,4,1); __auto_type av = cn_init_496;
__auto_type cn_init_514 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_514;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=4);
continue;
}
(b=3);
}
break;
case 3:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffdcU))));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=5);
continue;
}
break;
case 4:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffd8U))));
(b=5);
}
break;
case 5:
{
(f[0]=f[0]);
{
__auto_type cn_init_664 = rg[0]; __auto_type bv = cn_init_664;
__auto_type cn_init_672 = rg[0]; __auto_type av = cn_init_672;
cn_alu(&fl,Alu_And,av,bv,4);
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=7);
continue;
}
(b=6);
}
break;
case 6:
{
{
__auto_type cn_init_738 = rg[0]; __auto_type bv = cn_init_738;
__auto_type cn_init_746 = rg[0]; __auto_type av = cn_init_746;
__auto_type cn_init_764 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_764;
(rg[0]=r);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=9);
continue;
}
break;
case 7:
{
{
__auto_type cn_init_806 = 0x1869fU; __auto_type bv = cn_init_806;
__auto_type cn_init_814 = rg[0]; __auto_type av = cn_init_814;
__auto_type cn_init_832 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_832;
}
if(cn_cond(fl,14)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=9);
continue;
}
(b=8);
}
break;
case 8:
{
{
__auto_type cn_init_880 = 0x1869fU; __auto_type v = cn_init_880;
(rg[0]=v);
}
(b=9);
}
break;
case 9:
{
(rg[7]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffe4U))));
{
__auto_type cn_init_922 = 0x1U; __auto_type bv = cn_init_922;
__auto_type cn_init_930 = rg[7]; __auto_type av = cn_init_930;
__auto_type cn_init_948 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_948;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=11);
continue;
}
(b=10);
}
break;
case 10:
{
{
__auto_type cn_init_996 = 0x1U; __auto_type v = cn_init_996;
(rg[7]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=13);
continue;
}
break;
case 11:
{
{
__auto_type cn_init_1038 = 0x6U; __auto_type bv = cn_init_1038;
__auto_type cn_init_1046 = rg[7]; __auto_type av = cn_init_1046;
__auto_type cn_init_1064 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1064;
}
if(cn_cond(fl,14)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=13);
continue;
}
(b=12);
}
break;
case 12:
{
{
__auto_type cn_init_1112 = 0x6U; __auto_type v = cn_init_1112;
(rg[7]=v);
}
(b=13);
}
break;
case 13:
{
(rg[7]=((uint32_t)((((uint32_t)(rg[6]+0x48U)))+((uint32_t)(rg[7]*4)))));
{
__auto_type cn_init_1164 = 0x0U; __auto_type bv = cn_init_1164;
__auto_type cn_init_1183 = cn_rd32(m,((uint32_t)(rg[7]+0x0U))); __auto_type av = cn_init_1183;
__auto_type cn_init_1201 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1201;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=15);
continue;
}
(b=14);
}
break;
case 14:
{
{
__auto_type cn_init_1249 = 0x80000000U; __auto_type bv = cn_init_1249;
__auto_type cn_init_1257 = rg[0]; __auto_type av = cn_init_1257;
__auto_type cn_init_1275 = cn_alu(&fl,Alu_Or,av,bv,4); __auto_type r = cn_init_1275;
(rg[0]=r);
}
(b=15);
}
break;
case 15:
{
{
__auto_type cn_init_1305 = ((uint32_t)(rg[7]+0x0U)); __auto_type a = cn_init_1305;
cn_wr32(m,a,rg[0]);
}
{
__auto_type cn_init_1332 = cn_pop_lu(m,rg); __auto_type v = cn_init_1332;
(rg[7]=v);
}
{
__auto_type cn_init_1353 = cn_pop_lu(m,rg); __auto_type v = cn_init_1353;
(rg[6]=v);
}
{
__auto_type cn_init_1374 = cn_pop_lu(m,rg); __auto_type v = cn_init_1374;
(rg[0]=v);
}
{
__auto_type cn_init_1395 = cn_pop_lu(m,rg); __auto_type v = cn_init_1395;
(rg[5]=v);
}
__auto_type cn_init_1415 = cn_pop_lu(m,rg); __auto_type r = cn_init_1415;
(rg[ESP]=((uint32_t)(rg[ESP]+8)));
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
break;
default:
return 1;
break;
}
}
}
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_205ab96c98f98fb9(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+240))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_105;
__auto_type cn_init_118 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_118;
__auto_type cn_init_131 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_131;
__auto_type cn_init_144 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_144;
__auto_type cn_init_157 = cn_cell(vm,0); uint64_t v30 = cn_init_157;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r4));
(f[1]=cn_double(v30));
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(f[1]=cn_double(v30));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(r4=cn_bits(f[0]));
{
(rg[6]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_20f481396f51978b(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+216))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007e98U); uint64_t s2003 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_178;
__auto_type cn_init_191 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_191;
__auto_type cn_init_204 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_204;
__auto_type cn_init_217 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_217;
__auto_type cn_init_230 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_230;
__auto_type cn_init_243 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_243;
__auto_type cn_init_256 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_256;
__auto_type cn_init_269 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_269;
__auto_type cn_init_282 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_282;
__auto_type cn_init_295 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_295;
__auto_type cn_init_308 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_308;
__auto_type cn_init_321 = cn_cell(vm,0); uint64_t v27 = cn_init_321;
__auto_type cn_init_334 = cn_cell(vm,8); uint64_t v28 = cn_init_334;
__auto_type cn_init_347 = cn_cell(vm,16); uint64_t v29 = cn_init_347;
__auto_type cn_init_360 = cn_cell(vm,24); uint64_t v30 = cn_init_360;
__auto_type cn_init_373 = cn_cell(vm,40); uint64_t v32 = cn_init_373;
__auto_type cn_init_386 = cn_cell(vm,48); uint64_t v33 = cn_init_386;
{
{
{
{
{
{
{
{
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_479 = 0x48U; __auto_type bv = cn_init_479;
__auto_type cn_init_487 = rg[4]; __auto_type av = cn_init_487;
__auto_type cn_init_505 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_505;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_704 = 0x0U; __auto_type bv = cn_init_704;
__auto_type cn_init_721 = (((uint32_t)(((((v30>>32))&0xffffffffULL))))); __auto_type av = cn_init_721;
__auto_type cn_init_739 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_739;
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
(f[0]=cn_double(0x0));
(s2013=cn_bits(f[0]));
(s2012=cn_bits(f[0]));
(s2011=cn_bits(f[0]));
goto cn_break_b7;
}
cn_break_b2:;
(f[0]=cn_double(((((((v29>>32))|((v30<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_884 = 0x41U; __auto_type bv = cn_init_884;
__auto_type cn_init_897 = cn_reg_get(rg,4,1); __auto_type av = cn_init_897;
__auto_type cn_init_915 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_915;
cn_reg_set(rg,4,1,r);
}
{
__auto_type cn_init_935 = 0x40U; __auto_type bv = cn_init_935;
__auto_type cn_init_948 = cn_reg_get(rg,4,1); __auto_type av = cn_init_948;
__auto_type cn_init_966 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_966;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b5;
}
(f[0]=cn_double(((((((v29>>32))|((v30<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_1075 = 0x41U; __auto_type bv = cn_init_1075;
__auto_type cn_init_1088 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1088;
__auto_type cn_init_1106 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1106;
cn_reg_set(rg,4,1,r);
}
{
__auto_type cn_init_1126 = 0x40U; __auto_type bv = cn_init_1126;
__auto_type cn_init_1139 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1139;
__auto_type cn_init_1157 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_1157;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b5;
}
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2010=cn_bits(f[0]));
(f[1]=cn_double(((((((v29>>32))|((v30<<32))))&0xffffffffffffffffULL))));
cn_swap(f,1,0);
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_1426_0 = f[2];
__auto_type cn_tuple_1426_1 = f[1];
__auto_type x = cn_tuple_1426_0;
__auto_type y = cn_tuple_1426_1;
__auto_type cn_init_1455 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1455;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1487 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1487;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
(s2009=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[1]=cn_double(r3));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1686 = cn_double(((((((v29>>32))|((v30<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1686;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1722 = cn_double(s2010); __auto_type v = cn_init_1722;
(f[1]=(f[1]/v));
}
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(f[2]=-f[2]);
(f[3]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]+f[3]));
(f[2]=sqrt(f[2]));
(f[3]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]+f[3]));
cn_swap(f,2,1);
(f[1]=atan2(f[1],f[2]));
(f[1]=(f[1]+f[1]));
{
__auto_type cn_init_1908 = cn_double(((((((v29>>32))|((v30<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1908;
(f[1]=(f[1]*v));
}
{
__auto_type cn_tuple_1938_0 = sin(f[1]);
__auto_type cn_tuple_1938_1 = cos(f[1]);
__auto_type s = cn_tuple_1938_0;
__auto_type c = cn_tuple_1938_1;
(f[1]=s);
(f[2]=c);
(fsw&=~0x0400);
}
(s2005=cn_bits(f[2]));
(s2006=cn_bits(f[1]));
{
__auto_type cn_tuple_1997_0 = sin(f[0]);
__auto_type cn_tuple_1997_1 = cos(f[0]);
__auto_type s = cn_tuple_1997_0;
__auto_type c = cn_tuple_1997_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2007=cn_bits(f[1]));
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_2062 = cn_double(s2007); __auto_type v = cn_init_2062;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2086 = cn_double(s2005); __auto_type v = cn_init_2086;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2121 = (((double)(((int32_t)(((uint32_t)(((((v30>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2121;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2145 = cn_double(v32); __auto_type v = cn_init_2145;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_2192 = cn_double(s2008); __auto_type v = cn_init_2192;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2216 = cn_double(s2005); __auto_type v = cn_init_2216;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2251 = (((double)(((int32_t)(((uint32_t)(((((v30>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2251;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2275 = cn_double(v32); __auto_type v = cn_init_2275;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_2322 = cn_double(s2006); __auto_type v = cn_init_2322;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2357 = (((double)(((int32_t)(((uint32_t)(((((v30>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2357;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2381 = cn_double(v32); __auto_type v = cn_init_2381;
(f[0]=(f[0]*v));
}
(s2011=cn_bits(f[0]));
goto cn_break_b6;
}
cn_break_b5:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_2443 = (((double)(((int32_t)(((uint32_t)(((((v30>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2443;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2467 = cn_double(v32); __auto_type v = cn_init_2467;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_2525 = (((double)(((int32_t)(((uint32_t)(((((v30>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2525;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2549 = cn_double(v32); __auto_type v = cn_init_2549;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_2607 = (((double)(((int32_t)(((uint32_t)(((((v30>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2607;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2631 = cn_double(v32); __auto_type v = cn_init_2631;
(f[0]=(f[0]*v));
}
(s2011=cn_bits(f[0]));
}
cn_break_b6:;
}
cn_break_b7:;
{
__auto_type cn_init_2663 = 0x0U; __auto_type bv = cn_init_2663;
__auto_type cn_init_2680 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_2680;
__auto_type cn_init_2698 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2698;
}
if(cn_cond(fl,4)){
goto cn_break_b9;
}
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[1]=atan2(f[1],f[2]));
{
__auto_type cn_init_2858 = (((double)(((int32_t)(((uint32_t)(((((v29>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_2858;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2882 = cn_double(v32); __auto_type v = cn_init_2882;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2906 = cn_double(s2012); __auto_type v = cn_init_2906;
(f[1]=(f[1]+v));
}
(s2012=cn_bits(f[1]));
{
__auto_type cn_init_2952 = (((double)(((int32_t)(((uint32_t)(((((v29>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_2952;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2976 = cn_double(v32); __auto_type v = cn_init_2976;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3000 = cn_double(s2013); __auto_type v = cn_init_3000;
(f[0]=(f[0]+v));
}
(s2013=cn_bits(f[0]));
}
cn_break_b9:;
{
__auto_type cn_init_3031 = 0x0U; __auto_type bv = cn_init_3031;
__auto_type cn_init_3048 = (((uint32_t)(((((v28>>32))&0xffffffffULL))))); __auto_type av = cn_init_3048;
__auto_type cn_init_3066 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3066;
}
if(cn_cond(fl,4)){
goto cn_break_b11;
}
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]+f[0]));
(f[1]=sqrt(f[1]));
cn_swap(f,1,0);
(f[1]=sqrt(f[1]));
(f[2]=cn_double(r5));
(f[1]=atan2(f[1],f[2]));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[2]=atan2(f[2],f[3]));
{
__auto_type cn_init_3321 = (((double)(((int32_t)(((uint32_t)(((((v28>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3321;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_3345 = cn_double(v32); __auto_type v = cn_init_3345;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_3369 = cn_double(s2011); __auto_type v = cn_init_3369;
(f[2]=(f[2]+v));
}
(s2011=cn_bits(f[2]));
{
__auto_type cn_init_3415 = (((double)(((int32_t)(((uint32_t)(((((v28>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3415;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3439 = cn_double(v32); __auto_type v = cn_init_3439;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3463 = cn_double(s2012); __auto_type v = cn_init_3463;
(f[1]=(f[1]+v));
}
(s2012=cn_bits(f[1]));
{
__auto_type cn_init_3509 = (((double)(((int32_t)(((uint32_t)(((((v28>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3509;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3533 = cn_double(v32); __auto_type v = cn_init_3533;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3557 = cn_double(s2013); __auto_type v = cn_init_3557;
(f[0]=(f[0]+v));
}
(s2013=cn_bits(f[0]));
}
cn_break_b11:;
{
__auto_type cn_init_3588 = 0x0U; __auto_type bv = cn_init_3588;
__auto_type cn_init_3605 = (((uint32_t)(((((v28>>0))&0xffffffffULL))))); __auto_type av = cn_init_3605;
__auto_type cn_init_3623 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3623;
}
if(cn_cond(fl,4)){
goto cn_break_b13;
}
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
(f[1]=cos(f[1]));
(fsw&=~0x0400);
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(r3));
(f[2]=cn_double(r4));
(f[2]=sin(f[2]));
(fsw&=~0x0400);
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_3774 = (((double)(((int32_t)(((uint32_t)(((((v28>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_3774;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3798 = cn_double(v32); __auto_type v = cn_init_3798;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3822 = cn_double(s2012); __auto_type v = cn_init_3822;
(f[1]=(f[1]+v));
}
(s2012=cn_bits(f[1]));
{
__auto_type cn_init_3868 = (((double)(((int32_t)(((uint32_t)(((((v28>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_3868;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3892 = cn_double(v32); __auto_type v = cn_init_3892;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3916 = cn_double(s2013); __auto_type v = cn_init_3916;
(f[0]=(f[0]+v));
}
(s2013=cn_bits(f[0]));
}
cn_break_b13:;
{
__auto_type cn_init_3947 = 0x0U; __auto_type bv = cn_init_3947;
__auto_type cn_init_3964 = (((uint32_t)(((((v27>>32))&0xffffffffULL))))); __auto_type av = cn_init_3964;
__auto_type cn_init_3982 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3982;
}
if(cn_cond(fl,4)){
goto cn_break_b15;
}
(f[0]=cn_double(r4));
{
__auto_type cn_tuple_4024_0 = sin(f[0]);
__auto_type cn_tuple_4024_1 = cos(f[0]);
__auto_type s = cn_tuple_4024_0;
__auto_type c = cn_tuple_4024_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(f[2]=cn_double(r5));
{
__auto_type cn_tuple_4073_0 = sin(f[2]);
__auto_type cn_tuple_4073_1 = cos(f[2]);
__auto_type s = cn_tuple_4073_0;
__auto_type c = cn_tuple_4073_1;
(f[2]=s);
(f[3]=c);
(fsw&=~0x0400);
}
cn_swap(f,3,1);
{
__auto_type cn_init_4113 = cn_double(r3); __auto_type v = cn_init_4113;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_4148 = (((double)(((int32_t)(((uint32_t)(((((v27>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_4148;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_4172 = cn_double(v32); __auto_type v = cn_init_4172;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_4196 = cn_double(s2011); __auto_type v = cn_init_4196;
(f[3]=(f[3]+v));
}
(s2011=cn_bits(f[3]));
cn_swap(f,2,0);
(f[1]=(f[1]*f[2]));
cn_swap(f,2,1);
{
__auto_type cn_init_4264 = cn_double(r3); __auto_type v = cn_init_4264;
(f[2]=(f[2]*v));
}
cn_swap(f,2,0);
cn_swap(f,2,1);
{
__auto_type cn_init_4306 = cn_double(r3); __auto_type v = cn_init_4306;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_4356 = (((double)(((int32_t)(((uint32_t)(((((v27>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_4356;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4380 = cn_double(v32); __auto_type v = cn_init_4380;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4404 = cn_double(s2012); __auto_type v = cn_init_4404;
(f[1]=(f[1]+v));
}
(s2012=cn_bits(f[1]));
{
__auto_type cn_init_4450 = (((double)(((int32_t)(((uint32_t)(((((v27>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_4450;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4474 = cn_double(v32); __auto_type v = cn_init_4474;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4498 = cn_double(s2013); __auto_type v = cn_init_4498;
(f[0]=(f[0]+v));
}
(s2013=cn_bits(f[0]));
}
cn_break_b15:;
{
__auto_type cn_init_4529 = 0x0U; __auto_type bv = cn_init_4529;
__auto_type cn_init_4546 = (((uint32_t)(((((v27>>0))&0xffffffffULL))))); __auto_type av = cn_init_4546;
__auto_type cn_init_4564 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_4564;
}
if(cn_cond(fl,4)){
goto cn_break_b17;
}
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(r5));
(f[0]=(f[1]/f[0]));
(s2010=cn_bits(f[0]));
{
__auto_type cn_init_4709 = cn_double(r4); __auto_type v = cn_init_4709;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_4744 = cn_double(r3); __auto_type v = cn_init_4744;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(0x3ff71547652b82fe));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_4826_0 = f[2];
__auto_type cn_tuple_4826_1 = f[1];
__auto_type x = cn_tuple_4826_0;
__auto_type y = cn_tuple_4826_1;
__auto_type cn_init_4855 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_4855;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_4887 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_4887;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
{
__auto_type cn_init_5017 = cn_double(v33); __auto_type v = cn_init_5017;
(f[0]=(f[0]*v));
}
(s2009=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_5064 = cn_double(r3); __auto_type v = cn_init_5064;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5088 = cn_double(r4); __auto_type v = cn_init_5088;
(f[0]=(f[0]+v));
}
{
__auto_type cn_tuple_5118_0 = sin(f[0]);
__auto_type cn_tuple_5118_1 = cos(f[0]);
__auto_type s = cn_tuple_5118_0;
__auto_type c = cn_tuple_5118_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2007=cn_bits(f[1]));
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_5183 = cn_double(r3); __auto_type v = cn_init_5183;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5207 = cn_double(r4); __auto_type v = cn_init_5207;
(f[0]=(f[0]-v));
}
{
__auto_type cn_tuple_5237_0 = sin(f[0]);
__auto_type cn_tuple_5237_1 = cos(f[0]);
__auto_type s = cn_tuple_5237_0;
__auto_type c = cn_tuple_5237_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2005=cn_bits(f[1]));
(s2006=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_5302 = cn_double(r4); __auto_type v = cn_init_5302;
(f[0]=(f[0]*v));
}
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(0x3ff71547652b82fe));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_5399_0 = f[2];
__auto_type cn_tuple_5399_1 = f[1];
__auto_type x = cn_tuple_5399_0;
__auto_type y = cn_tuple_5399_1;
__auto_type cn_init_5428 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_5428;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_5460 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_5460;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
(s2010=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_5613 = cn_double(s2005); __auto_type v = cn_init_5613;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5637 = cn_double(s2007); __auto_type v = cn_init_5637;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_5661 = cn_double(s2009); __auto_type v = cn_init_5661;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5696 = (((double)(((int32_t)(((uint32_t)(((((v27>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_5696;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5720 = cn_double(v32); __auto_type v = cn_init_5720;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5744 = cn_double(s2013); __auto_type v = cn_init_5744;
(f[0]=(f[0]+v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_5791 = cn_double(s2006); __auto_type v = cn_init_5791;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_5826 = cn_double(s2008); __auto_type v = cn_init_5826;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_5850 = cn_double(s2009); __auto_type v = cn_init_5850;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5885 = (((double)(((int32_t)(((uint32_t)(((((v27>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_5885;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5909 = cn_double(v32); __auto_type v = cn_init_5909;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5933 = cn_double(s2012); __auto_type v = cn_init_5933;
(f[0]=(f[0]+v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(0x3ff71547652b82fe));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_6109_0 = f[2];
__auto_type cn_tuple_6109_1 = f[1];
__auto_type x = cn_tuple_6109_0;
__auto_type y = cn_tuple_6109_1;
__auto_type cn_init_6138 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_6138;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_6170 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_6170;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
(f[1]=cn_double(r5));
(f[1]=sin(f[1]));
(fsw&=~0x0400);
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_6357 = (((double)(((int32_t)(((uint32_t)(((((v27>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_6357;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_6381 = cn_double(v32); __auto_type v = cn_init_6381;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_6405 = cn_double(s2011); __auto_type v = cn_init_6405;
(f[0]=(f[0]+v));
}
(s2011=cn_bits(f[0]));
}
cn_break_b17:;
(f[0]=cn_double(s2011));
(r5=cn_bits(f[0]));
(f[0]=cn_double(s2012));
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2013));
(r3=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s2003>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2004>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2004>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[4]=rg[5]);
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007e98U,s2003);
cn_wr64u(m,0x10007ea0U,s2004);
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_215b69722828d4d5(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+192))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(0)); uint64_t r0 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_190;
__auto_type cn_init_207 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_207;
__auto_type cn_init_224 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_224;
__auto_type cn_init_237 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_237;
__auto_type cn_init_250 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_250;
__auto_type cn_init_263 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_263;
__auto_type cn_init_276 = cn_cell(vm,0); uint64_t v24 = cn_init_276;
__auto_type cn_init_289 = cn_cell(vm,8); uint64_t v25 = cn_init_289;
__auto_type cn_init_302 = cn_cell(vm,16); uint64_t v26 = cn_init_302;
__auto_type cn_init_315 = cn_cell(vm,24); uint64_t v27 = cn_init_315;
__auto_type cn_init_328 = cn_cell(vm,32); uint64_t v28 = cn_init_328;
__auto_type cn_init_341 = cn_cell(vm,40); uint64_t v29 = cn_init_341;
__auto_type cn_init_354 = cn_cell(vm,48); uint64_t v30 = cn_init_354;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r4));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_580 = cn_double(v29); __auto_type v = cn_init_580;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_631 = cn_double(v28); __auto_type v = cn_init_631;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r6));
(f[2]=(f[2]*f[2]));
{
__auto_type cn_init_682 = cn_double(v27); __auto_type v = cn_init_682;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=-f[0]);
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_774 = cn_double(v30); __auto_type v = cn_init_774;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_813 = cn_double(r10); __auto_type v = cn_init_813;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r11));
{
__auto_type cn_init_849 = cn_double(v25); __auto_type v = cn_init_849;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r3));
{
__auto_type cn_init_900 = cn_double(r4); __auto_type v = cn_init_900;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_924 = cn_double(v29); __auto_type v = cn_init_924;
(f[1]=(f[1]*v));
}
(f[1]=(f[1]+f[1]));
{
__auto_type cn_init_963 = cn_double(r11); __auto_type v = cn_init_963;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r10));
{
__auto_type cn_init_999 = cn_double(v24); __auto_type v = cn_init_999;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r3));
{
__auto_type cn_init_1050 = cn_double(r5); __auto_type v = cn_init_1050;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1074 = cn_double(v28); __auto_type v = cn_init_1074;
(f[2]=(f[2]*v));
}
(f[2]=(f[2]+f[2]));
{
__auto_type cn_init_1113 = cn_double(r12); __auto_type v = cn_init_1113;
(f[2]=(f[2]+v));
}
(f[3]=cn_double(r3));
{
__auto_type cn_init_1149 = cn_double(r6); __auto_type v = cn_init_1149;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_1173 = cn_double(v27); __auto_type v = cn_init_1173;
(f[3]=(f[3]*v));
}
(f[3]=(f[3]+f[3]));
{
__auto_type cn_init_1212 = cn_double(v26); __auto_type v = cn_init_1212;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_1236 = cn_double(r0); __auto_type v = cn_init_1236;
(f[3]=(f[3]+v));
}
(r6=cn_bits(f[3]));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
{
(rg[7]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_216ee55ed6cccd96(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+256))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_229;
__auto_type cn_init_242 = cn_cell(vm,0); uint64_t v32 = cn_init_242;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[1]);
(f[3]=(f[3]*f[1]));
(f[4]=f[0]);
(f[4]=(f[4]*f[0]));
(f[4]=(f[4]+f[3]));
(f[5]=f[2]);
(f[5]=(f[5]*f[2]));
(f[3]=(f[3]+f[5]));
(f[5]=f[3]);
(f[5]=(f[5]*f[3]));
(f[5]=(f[5]*f[3]));
(f[6]=cn_double(0x3ff0000000000000));
(f[5]=(f[6]/f[5]));
(f[6]=f[2]);
(f[6]=(f[6]*f[2]));
(f[7]=f[6]);
(f[7]=(f[7]*f[4]));
{
__auto_type cn_init_699 = cn_double(v32); __auto_type v = cn_init_699;
(f[7]=(f[7]*v));
}
cn_swap(f,7,6);
(f[4]=(f[7]-f[4]));
(f[7]=f[4]);
(f[7]=(f[7]*f[4]));
(f[6]=(f[7]-f[6]));
(f[4]=(f[4]*f[6]));
(f[6]=f[3]);
(f[6]=sqrt(f[6]));
(f[7]=f[0]);
(f[7]=(f[7]*f[7]));
(f[3]=(f[3]-f[7]));
(f[6]=(f[6]+f[6]));
(f[0]=(f[0]*f[6]));
(f[6]=f[3]);
(f[6]=(f[6]*f[6]));
(f[7]=f[0]);
(f[7]=(f[7]*f[7]));
(f[6]=(f[6]-f[7]));
(f[7]=f[0]);
(f[7]=(f[7]*f[3]));
(f[7]=(f[7]+f[7]));
cn_swap(f,7,4);
{
__auto_type cn_init_1010 = cn_double(r10); __auto_type v = cn_init_1010;
(f[7]=(f[7]+v));
}
(r3=cn_bits(f[7]));
(f[7]=f[4]);
(f[7]=(f[7]*f[3]));
cn_swap(f,7,6);
(f[3]=(f[3]*f[7]));
(f[7]=(f[7]*f[0]));
(f[6]=(f[6]+f[7]));
cn_swap(f,6,0);
(f[4]=(f[4]*f[6]));
cn_swap(f,5,4);
(f[3]=(f[3]-f[5]));
cn_swap(f,4,2);
(f[5]=f[4]);
(f[5]=(f[5]*f[5]));
(f[6]=f[1]);
(f[6]=(f[6]*f[6]));
(f[5]=(f[5]-f[6]));
cn_swap(f,5,1);
(f[4]=(f[4]*f[5]));
(f[4]=(f[4]+f[4]));
(f[5]=f[4]);
(f[5]=(f[5]*f[5]));
(f[6]=f[1]);
(f[6]=(f[6]*f[6]));
(f[5]=(f[6]-f[5]));
(f[6]=f[4]);
(f[6]=(f[6]*f[1]));
(f[6]=(f[6]+f[6]));
(f[1]=(f[1]*f[6]));
(f[4]=(f[4]*f[5]));
(f[1]=(f[1]+f[4]));
(f[1]=(f[1]*f[3]));
cn_swap(f,2,1);
(f[2]=fabs(f[2]));
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(r12));
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
(r5=cn_bits(f[1]));
(f[0]=fabs(f[0]));
(f[1]=cn_double(r11));
(f[1]=fabs(f[1]));
(f[0]=(f[1]-f[0]));
(r4=cn_bits(f[0]));
{
(rg[7]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_217635cca6da9dd8(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_47 = 0ULL; __auto_type steps = cn_init_47;
__auto_type cn_init_52 = max_steps; __auto_type limit = cn_init_52;
__auto_type cn_init_62 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+232))); unsigned char * vm = cn_init_82;
__auto_type cn_init_99 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_99;
__auto_type cn_init_116 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_116;
__auto_type cn_init_133 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_133;
__auto_type cn_init_150 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_150;
__auto_type cn_init_163 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_163;
__auto_type cn_init_176 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_176;
__auto_type cn_init_189 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_189;
__auto_type cn_init_202 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_202;
__auto_type cn_init_215 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_215;
__auto_type cn_init_228 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_228;
__auto_type cn_init_241 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_241;
__auto_type cn_init_254 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_254;
__auto_type cn_init_267 = cn_cell(vm,0); uint64_t v29 = cn_init_267;
__auto_type cn_init_280 = cn_cell(vm,8); uint64_t v30 = cn_init_280;
__auto_type cn_init_293 = cn_cell(vm,24); uint64_t v32 = cn_init_293;
{
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_365 = 0x30U; __auto_type bv = cn_init_365;
__auto_type cn_init_373 = rg[4]; __auto_type av = cn_init_373;
__auto_type cn_init_391 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_391;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2007=(((s2007&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2007=(((s2007&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2006=(((s2006&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(f[0]=cn_double(v32));
{
__auto_type cn_init_607 = cn_double(v30); __auto_type v = cn_init_607;
(f[0]=(f[0]/v));
}
(s2013=cn_bits(f[0]));
(f[0]=(f[0]+f[0]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(v32));
{
__auto_type cn_init_680 = cn_double(v29); __auto_type v = cn_init_680;
(f[0]=(f[0]/v));
}
(s2011=cn_bits(f[0]));
(f[0]=(f[0]+f[0]));
(s2010=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[0]=atan2(f[0],f[1]));
(f[0]=fabs(f[0]));
cn_continue_l1:;
{
(fsw=cn_compare(f[0],cn_double(s2013)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_835 = 0x41U; __auto_type bv = cn_init_835;
__auto_type cn_init_848 = cn_reg_get(rg,4,1); __auto_type av = cn_init_848;
__auto_type cn_init_866 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_866;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,15)){
goto cn_break_b3;
}
{
__auto_type cn_init_903 = cn_double(s2012); __auto_type v = cn_init_903;
(f[0]=(f[0]-v));
}
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l1;
}
goto cn_continue_l1;
cn_break_l1:;
}
cn_break_b3:;
(f[0]=cos(f[0]));
(fsw&=~0x0400);
(s2012=cn_bits(f[0]));
{
__auto_type cn_init_980 = cn_double(r4); __auto_type v = cn_init_980;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1042 = cn_double(r5); __auto_type v = cn_init_1042;
(f[1]=(f[1]*v));
}
(s2012=cn_bits(f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(r3));
(f[0]=atan2(f[0],f[1]));
(f[0]=fabs(f[0]));
cn_continue_l4:;
{
(fsw=cn_compare(f[0],cn_double(s2011)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1203 = 0x41U; __auto_type bv = cn_init_1203;
__auto_type cn_init_1216 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1216;
__auto_type cn_init_1234 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1234;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,15)){
goto cn_break_b6;
}
{
__auto_type cn_init_1271 = cn_double(s2010); __auto_type v = cn_init_1271;
(f[0]=(f[0]-v));
}
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l4;
}
goto cn_continue_l4;
cn_break_l4:;
}
cn_break_b6:;
(f[0]=cos(f[0]));
(fsw&=~0x0400);
(f[1]=f[0]);
(f[2]=f[1]);
{
__auto_type cn_init_1357 = cn_double(s2013); __auto_type v = cn_init_1357;
(f[2]=(f[2]*v));
}
(r4=cn_bits(f[2]));
{
__auto_type cn_init_1392 = cn_double(s2012); __auto_type v = cn_init_1392;
(f[1]=(f[1]*v));
}
(r5=cn_bits(f[1]));
{
__auto_type cn_init_1427 = cn_double(r3); __auto_type v = cn_init_1427;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s2006>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2007>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2007>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[4]=rg[5]);
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_221797652ab837b5(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+168))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_136;
__auto_type cn_init_149 = cn_cell(vm,0); uint64_t v21 = cn_init_149;
__auto_type cn_init_162 = cn_cell(vm,8); uint64_t v22 = cn_init_162;
__auto_type cn_init_175 = cn_cell(vm,16); uint64_t v23 = cn_init_175;
__auto_type cn_init_188 = cn_cell(vm,24); uint64_t v24 = cn_init_188;
__auto_type cn_init_201 = cn_cell(vm,32); uint64_t v25 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,40); uint64_t v26 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,48); uint64_t v27 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,56); uint64_t v28 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,64); uint64_t v29 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,72); uint64_t v30 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,88); uint64_t v32 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,96); uint64_t v33 = cn_init_292;
{
{
{
__auto_type cn_init_304 = 0xfffffff8U; __auto_type bv = cn_init_304;
__auto_type cn_init_312 = rg[4]; __auto_type av = cn_init_312;
__auto_type cn_init_330 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_330;
(rg[4]=r);
}
(f[0]=cn_double(v22));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[0]));
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[0]));
{
__auto_type cn_init_415 = cn_double(v30); __auto_type v = cn_init_415;
(f[2]=(f[2]+v));
}
(f[3]=f[1]);
(f[4]=f[2]);
__auto_type cn_tuple_467_0 = f[3];
__auto_type cn_tuple_467_1 = f[4];
__auto_type pa9y = cn_tuple_467_0;
__auto_type pa9x = cn_tuple_467_1;
__auto_type cn_tuple_481_0 = atan2(pa9y,pa9x);
__auto_type cn_tuple_481_1 = atan2(pa9y,pa9x);
__auto_type pa9lo = cn_tuple_481_0;
__auto_type pa9hi = cn_tuple_481_1;
(f[3]=pa9lo);
(f[3]=-f[3]);
__auto_type cn_init_528 = ({__auto_type cn_init_513 = cn_double(v32); __auto_type v = cn_init_513; (f[3]=(f[3]*v)); v;}); __auto_type c9_11 = cn_init_528;
(f[4]=(((double)(((int32_t)(((uint32_t)(((((v23>>0))&0xffffffffULL))))))))));
cn_swap(f,4,3);
__auto_type cn_init_568 = f[3]; __auto_type c9_14 = cn_init_568;
(f[4]=(f[4]*f[3]));
{

__auto_type cn_init_629 = cn_round(m,({__auto_type cn_arg=pa9lo; ({(cn_arg=-cn_arg); (cn_arg=(cn_arg*c9_11)); (cn_arg=(cn_arg*c9_14)); cn_arg;});})); __auto_type r1 = cn_init_629;
__auto_type cn_init_642 = cn_round(m,({__auto_type cn_arg=pa9hi; ({(cn_arg=-cn_arg); (cn_arg=(cn_arg*c9_11)); (cn_arg=(cn_arg*c9_14)); cn_arg;});})); __auto_type r2 = cn_init_642;
(f[4]=((((r1==r2)&&(cn_bits(r1)==cn_bits(r2))))?(({r1;})):(({cn_round(m,({__auto_type cn_arg=atan2(pa9y,pa9x); ({(cn_arg=-cn_arg); (cn_arg=(cn_arg*c9_11)); (cn_arg=(cn_arg*c9_14)); cn_arg;});}));}))));
}
{
__auto_type cn_init_699 = cn_round(m,f[4]); __auto_type x = cn_init_699;
__auto_type cn_init_734 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_734;
(s2014=(((s2014&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
(f[3]=(f[4]/f[3]));
{
__auto_type cn_init_788 = cn_double(v33); __auto_type v = cn_init_788;
(f[3]=(f[3]*v));
}
{
__auto_type cn_tuple_819_0 = sin(f[3]);
__auto_type cn_tuple_819_1 = cos(f[3]);
__auto_type s = cn_tuple_819_0;
__auto_type c = cn_tuple_819_1;
(f[3]=s);
(f[4]=c);
(fsw&=~0x0400);
}
(f[5]=f[1]);
(f[5]=(f[5]*f[4]));
(f[6]=f[2]);
(f[6]=(f[6]*f[3]));
(f[5]=(f[5]+f[6]));
{
__auto_type cn_init_910 = 0x1U; __auto_type bv = cn_init_910;
__auto_type cn_init_927 = (((uint32_t)(((((s2014>>32))&0xffffffffULL))))); __auto_type av = cn_init_927;
__auto_type cn_init_945 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_945;
(s2014=(((s2014&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
(f[5]=-f[5]);
}
cn_break_b2:;
cn_swap(f,5,1);
(f[3]=(f[3]*f[5]));
(f[2]=(f[2]*f[4]));
(f[2]=(f[2]-f[3]));
cn_swap(f,2,1);
(f[3]=cn_double(r5));
cn_swap(f,3,1);
{
__auto_type cn_init_1094 = cn_double(v29); __auto_type v = cn_init_1094;
(f[3]=(f[3]+v));
}
(f[4]=f[3]);
{
__auto_type cn_init_1142 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1142;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1190 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1190;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1253 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1253;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[3]);
{
__auto_type cn_init_1316 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1316;
(f[5]=(f[5]*v));
}
(f[6]=f[2]);
{
__auto_type cn_init_1364 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1364;
(f[6]=(f[6]*v));
}
(f[5]=(f[5]+f[6]));
(f[6]=f[1]);
{
__auto_type cn_init_1427 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1427;
(f[6]=(f[6]*v));
}
(f[5]=(f[5]+f[6]));
cn_swap(f,5,3);
{
__auto_type cn_init_1489 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1489;
(f[5]=(f[5]*v));
}
cn_swap(f,5,2);
{
__auto_type cn_init_1536 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1536;
(f[5]=(f[5]*v));
}
(f[2]=(f[2]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_1598 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1598;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
(r4=cn_bits(f[3]));
(f[2]=-f[2]);
cn_swap(f,2,1);
{
__auto_type cn_init_1668 = cn_double(v28); __auto_type v = cn_init_1668;
(f[2]=(f[2]*v));
}
(r5=cn_bits(f[2]));
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(r4));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[3]=f[2]);
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[3]-f[4]));
cn_swap(f,3,2);
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r4));
(f[4]=(f[4]+f[4]));
(f[3]=(f[3]+f[4]));
(f[0]=(f[0]*f[3]));
cn_swap(f,2,0);
(f[3]=cn_double(0x3ff0000000000000));
(f[2]=(f[3]/f[2]));
cn_swap(f,2,0);
(f[2]=(f[2]*f[0]));
{
__auto_type cn_init_1960 = cn_double(v21); __auto_type v = cn_init_1960;
(f[2]=(f[2]+v));
}
(r3=cn_bits(f[2]));
(f[1]=(f[1]+f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]*f[1]));
(r4=cn_bits(f[0]));
(f[0]=cn_double(r32));
(f[1]=cn_double(v28));
(f[1]=fabs(f[1]));
(f[0]=(f[0]*f[1]));
(r32=cn_bits(f[0]));
{
__auto_type cn_init_2106 = 0x8U; __auto_type bv = cn_init_2106;
__auto_type cn_init_2114 = rg[4]; __auto_type av = cn_init_2114;
__auto_type cn_init_2132 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2132;
(rg[4]=r);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10001100U,r32);
cn_wr64u(m,0x10007ef0U,s2014);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_22c630ccb8814de6(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+256))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_268;
__auto_type cn_init_281 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_281;
__auto_type cn_init_294 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_294;
__auto_type cn_init_307 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_307;
__auto_type cn_init_320 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_320;
__auto_type cn_init_333 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_333;
__auto_type cn_init_346 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,0); uint64_t v32 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,8); uint64_t v33 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,16); uint64_t v34 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,24); uint64_t v35 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,32); uint64_t v36 = cn_init_411;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_477 = 0xffffffc0U; __auto_type bv = cn_init_477;
__auto_type cn_init_485 = rg[4]; __auto_type av = cn_init_485;
__auto_type cn_init_503 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_503;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2005=(((s2005&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2005=(((s2005&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_709 = cn_double(r3); __auto_type v = cn_init_709;
(f[0]=(f[0]*v));
}
(s2010=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_756 = cn_double(s2010); __auto_type v = cn_init_756;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_803 = cn_double(r4); __auto_type v = cn_init_803;
(f[0]=(f[0]*v));
}
(s2009=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_850 = cn_double(s2009); __auto_type v = cn_init_850;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_897 = cn_double(r5); __auto_type v = cn_init_897;
(f[0]=(f[0]*v));
}
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2008));
{
__auto_type cn_init_944 = cn_double(s2008); __auto_type v = cn_init_944;
(f[0]=(f[0]*v));
}
(s2011=cn_bits(f[0]));
(f[0]=cn_double(v32));
{
__auto_type cn_init_991 = cn_double(r3); __auto_type v = cn_init_991;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(v33));
{
__auto_type cn_init_1027 = cn_double(s2012); __auto_type v = cn_init_1027;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v34));
{
__auto_type cn_init_1063 = cn_double(s2011); __auto_type v = cn_init_1063;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v36));
{
__auto_type cn_init_1114 = cn_double(s2009); __auto_type v = cn_init_1114;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1138 = cn_double(s2008); __auto_type v = cn_init_1138;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(v34));
{
__auto_type cn_init_1174 = cn_double(s2009); __auto_type v = cn_init_1174;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(v33));
{
__auto_type cn_init_1210 = cn_double(s2008); __auto_type v = cn_init_1210;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_1249 = cn_double(s2010); __auto_type v = cn_init_1249;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]-f[3]));
{
__auto_type cn_init_1288 = cn_double(s2013); __auto_type v = cn_init_1288;
(f[2]=(f[2]+v));
}
{
__auto_type cn_init_1312 = cn_double(v35); __auto_type v = cn_init_1312;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[0]=(f[0]*f[1]));
(rg[7]=rg[6]);
{
__auto_type cn_init_1371 = 0x18U; __auto_type bv = cn_init_1371;
__auto_type cn_init_1379 = rg[7]; __auto_type av = cn_init_1379;
__auto_type cn_init_1397 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1397;
(rg[7]=r);
}
{
__auto_type cn_init_1416 = cn_double(r10); __auto_type v = cn_init_1416;
(f[0]=(v-f[0]));
}
(s2007=cn_bits(f[0]));
(f[0]=cn_double(v32));
{
__auto_type cn_init_1463 = cn_double(r4); __auto_type v = cn_init_1463;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(v33));
{
__auto_type cn_init_1499 = cn_double(s2011); __auto_type v = cn_init_1499;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v34));
{
__auto_type cn_init_1535 = cn_double(s2013); __auto_type v = cn_init_1535;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v36));
{
__auto_type cn_init_1586 = cn_double(s2008); __auto_type v = cn_init_1586;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1610 = cn_double(s2010); __auto_type v = cn_init_1610;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(v34));
{
__auto_type cn_init_1646 = cn_double(s2008); __auto_type v = cn_init_1646;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(v33));
{
__auto_type cn_init_1682 = cn_double(s2010); __auto_type v = cn_init_1682;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_1721 = cn_double(s2009); __auto_type v = cn_init_1721;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]-f[3]));
{
__auto_type cn_init_1760 = cn_double(s2012); __auto_type v = cn_init_1760;
(f[2]=(f[2]+v));
}
{
__auto_type cn_init_1784 = cn_double(v35); __auto_type v = cn_init_1784;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[0]=(f[0]*f[1]));
(rg[7]=rg[6]);
{
__auto_type cn_init_1843 = 0x20U; __auto_type bv = cn_init_1843;
__auto_type cn_init_1851 = rg[7]; __auto_type av = cn_init_1851;
__auto_type cn_init_1869 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1869;
(rg[7]=r);
}
{
__auto_type cn_init_1888 = cn_double(r11); __auto_type v = cn_init_1888;
(f[0]=(v-f[0]));
}
(s2006=cn_bits(f[0]));
(f[0]=cn_double(v32));
{
__auto_type cn_init_1935 = cn_double(r5); __auto_type v = cn_init_1935;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(v33));
{
__auto_type cn_init_1971 = cn_double(s2013); __auto_type v = cn_init_1971;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v34));
{
__auto_type cn_init_2007 = cn_double(s2012); __auto_type v = cn_init_2007;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v36));
{
__auto_type cn_init_2058 = cn_double(s2010); __auto_type v = cn_init_2058;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_2082 = cn_double(s2009); __auto_type v = cn_init_2082;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(v34));
{
__auto_type cn_init_2118 = cn_double(s2010); __auto_type v = cn_init_2118;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(v33));
{
__auto_type cn_init_2154 = cn_double(s2009); __auto_type v = cn_init_2154;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_2193 = cn_double(s2008); __auto_type v = cn_init_2193;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]-f[3]));
{
__auto_type cn_init_2232 = cn_double(s2011); __auto_type v = cn_init_2232;
(f[2]=(f[2]+v));
}
{
__auto_type cn_init_2256 = cn_double(v35); __auto_type v = cn_init_2256;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2305 = 0x28U; __auto_type bv = cn_init_2305;
__auto_type cn_init_2313 = rg[6]; __auto_type av = cn_init_2313;
__auto_type cn_init_2331 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2331;
(rg[6]=r);
}
{
__auto_type cn_init_2350 = cn_double(r12); __auto_type v = cn_init_2350;
(f[0]=(v-f[0]));
}
(r5=cn_bits(f[0]));
(rg[1]=((uint32_t)(((((s2007>>0))&0xffffffffULL)))));
(r3=(((r3&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[1])))&0xffffffffULL))<<0))));
(rg[1]=((uint32_t)(((((s2007>>32))&0xffffffffULL)))));
(r3=(((r3&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[1])))&0xffffffffULL))<<32))));
(rg[0]=((uint32_t)(((((s2006>>0))&0xffffffffULL)))));
(r4=(((r4&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
(rg[0]=((uint32_t)(((((s2006>>32))&0xffffffffULL)))));
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
{
(rg[7]=((uint32_t)(((((s2004>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2005>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2005>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[4]=rg[5]);
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ea0U,s2004);
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_22e2557ab471f64e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_44 = 0ULL; __auto_type steps = cn_init_44;
__auto_type cn_init_49 = max_steps; __auto_type limit = cn_init_49;
__auto_type cn_init_62 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+104))); unsigned char * vm = cn_init_82;
__auto_type cn_init_95 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_95;
__auto_type cn_init_108 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_108;
__auto_type cn_init_121 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_121;
__auto_type cn_init_134 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_134;
__auto_type cn_init_147 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_147;
__auto_type cn_init_160 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_160;
__auto_type cn_init_173 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_173;
__auto_type cn_init_186 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_186;
__auto_type cn_init_199 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_199;
__auto_type cn_init_212 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_212;
__auto_type cn_init_225 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_225;
__auto_type cn_init_238 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_238;
__auto_type cn_init_251 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_251;
__auto_type cn_init_264 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_264;
__auto_type cn_init_277 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_277;
__auto_type cn_init_290 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_290;
__auto_type cn_init_303 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_303;
__auto_type cn_init_316 = cn_cell(vm,0); uint64_t v13 = cn_init_316;
__auto_type cn_init_329 = cn_cell(vm,8); uint64_t v14 = cn_init_329;
__auto_type cn_init_342 = cn_cell(vm,16); uint64_t v15 = cn_init_342;
__auto_type cn_init_355 = cn_cell(vm,24); uint64_t v16 = cn_init_355;
__auto_type cn_init_368 = cn_cell(vm,32); uint64_t v17 = cn_init_368;
__auto_type cn_init_381 = cn_cell(vm,40); uint64_t v18 = cn_init_381;
__auto_type cn_init_394 = cn_cell(vm,48); uint64_t v19 = cn_init_394;
__auto_type cn_init_407 = cn_cell(vm,56); uint64_t v20 = cn_init_407;
__auto_type cn_init_420 = cn_cell(vm,64); uint64_t v21 = cn_init_420;
__auto_type cn_init_433 = cn_cell(vm,72); uint64_t v22 = cn_init_433;
__auto_type cn_init_446 = cn_cell(vm,80); uint64_t v23 = cn_init_446;
__auto_type cn_init_459 = cn_cell(vm,88); uint64_t v24 = cn_init_459;
__auto_type cn_init_472 = cn_cell(vm,96); uint64_t v25 = cn_init_472;
__auto_type cn_init_485 = cn_cell(vm,104); uint64_t v26 = cn_init_485;
__auto_type cn_init_498 = cn_cell(vm,112); uint64_t v27 = cn_init_498;
__auto_type cn_init_511 = cn_cell(vm,120); uint64_t v28 = cn_init_511;
__auto_type cn_init_524 = cn_cell(vm,128); uint64_t v29 = cn_init_524;
__auto_type cn_init_537 = cn_cell(vm,136); uint64_t v30 = cn_init_537;
__auto_type cn_init_550 = cn_cell(vm,152); uint64_t v32 = cn_init_550;
{
{
{
{
{
{
{
{
{
{
__auto_type cn_init_583 = 0xffffffa6U; __auto_type bv = cn_init_583;
__auto_type cn_init_591 = rg[4]; __auto_type av = cn_init_591;
__auto_type cn_init_609 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_609;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_638 = r5; uint64_t s = cn_init_638;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_668 = (CN_U2){v28,v29}; CN_U2 s = cn_init_668;
__auto_type cn_init_678 = m->xmm[0]; __auto_type a = cn_init_678;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_748 = v28; uint64_t s = cn_init_748;
__auto_type cn_init_761 = m->xmm[1][0]; __auto_type a = cn_init_761;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_808 = (CN_U2){v24,v25}; CN_U2 s = cn_init_808;
__auto_type cn_init_818 = m->xmm[0]; __auto_type a = cn_init_818;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_888 = v26; uint64_t s = cn_init_888;
__auto_type cn_init_901 = m->xmm[1][0]; __auto_type a = cn_init_901;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_938 = 0x0U; __auto_type bv = cn_init_938;
__auto_type cn_init_955 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_955;
__auto_type cn_init_973 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_973;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_994 = r32; uint64_t s = cn_init_994;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_1016 = v28; uint64_t s = cn_init_1016;
__auto_type cn_init_1029 = m->xmm[5][0]; __auto_type a = cn_init_1029;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1125 = m->xmm[0][0]; uint64_t v = cn_init_1125;
(s2004=(((s2004&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2005=(((s2005&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1184 = m->xmm[0][1]; uint64_t v = cn_init_1184;
(s2005=(((s2005&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2006=(((s2006&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1243 = m->xmm[1][0]; uint64_t v = cn_init_1243;
(s2006=(((s2006&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2007=(((s2007&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(rg[2]=((uint32_t)(((((v19>>0))&0xffffffffULL)))));
{
__auto_type cn_init_1309 = 0x1fU; __auto_type bv = cn_init_1309;
__auto_type cn_init_1317 = rg[2]; __auto_type av = cn_init_1317;
__auto_type cn_init_1335 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1335;
(rg[2]=r);
}
{
__auto_type cn_init_1349 = 0x0U; __auto_type bv = cn_init_1349;
__auto_type cn_init_1357 = rg[2]; __auto_type av = cn_init_1357;
__auto_type cn_init_1375 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1375;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
{
__auto_type cn_init_1394 = 0x1U; __auto_type v = cn_init_1394;
(rg[2]=v);
}
}
cn_break_b4:;
(f[0]=cn_double(((((((s2004>>16))|((s2005<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1442 = cn_double(v32); __auto_type v = cn_init_1442;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1466 = cn_double(v32); __auto_type v = cn_init_1466;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1494 = cn_bits(f[0]); uint64_t v = cn_init_1494;
(s2004=(((s2004&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2005=(((s2005&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1576 = cn_double(v32); __auto_type v = cn_init_1576;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1600 = cn_double(v32); __auto_type v = cn_init_1600;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1628 = cn_bits(f[0]); uint64_t v = cn_init_1628;
(s2005=(((s2005&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2006=(((s2006&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2006>>16))|((s2007<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1710 = cn_double(v32); __auto_type v = cn_init_1710;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1734 = cn_double(v32); __auto_type v = cn_init_1734;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1762 = cn_bits(f[0]); uint64_t v = cn_init_1762;
(s2006=(((s2006&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2007=(((s2007&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2004>>16))|((s2005<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1844 = cn_double(v32); __auto_type v = cn_init_1844;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1882 = cn_double(v32); __auto_type v = cn_init_1882;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_1910 = cn_bits(f[0]); uint64_t v = cn_init_1910;
(s2007=(((s2007&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2008=(((s2008&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[1]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1992 = cn_double(v32); __auto_type v = cn_init_1992;
(f[1]=(f[1]-v));
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2030 = cn_double(v32); __auto_type v = cn_init_2030;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_2058 = cn_bits(f[1]); uint64_t v = cn_init_2058;
(s2008=(((s2008&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2009=(((s2009&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[2]=cn_double(((((((s2006>>16))|((s2007<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2140 = cn_double(v32); __auto_type v = cn_init_2140;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
{
__auto_type cn_init_2178 = cn_double(v32); __auto_type v = cn_init_2178;
(f[2]=(f[2]-v));
}
{
__auto_type cn_init_2206 = cn_bits(f[2]); uint64_t v = cn_init_2206;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[3]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_2276 = cn_bits(f[3]); uint64_t v = cn_init_2276;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_2362 = 0x41U; __auto_type bv = cn_init_2362;
__auto_type cn_init_2375 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2375;
__auto_type cn_init_2393 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2393;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
(f[1]=f[2]);
goto cn_break_b7;
}
cn_break_b6:;
(f[2]=f[2]);
}
cn_break_b7:;
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_2487 = 0x41U; __auto_type bv = cn_init_2487;
__auto_type cn_init_2500 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2500;
__auto_type cn_init_2518 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2518;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b9;
}
(f[0]=f[1]);
goto cn_break_b10;
}
cn_break_b9:;
(f[1]=f[1]);
}
cn_break_b10:;
{
__auto_type cn_init_2584 = cn_bits(f[0]); uint64_t v = cn_init_2584;
(s2011=(((s2011&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2012=(((s2012&~0xffffULL))|((((v>>48))&0xffffULL))));
}
cn_continue_l11:;
{
{
{
{
{
{
{
{
{
{
{
__auto_type cn_init_2673 = cn_bits(f[0]); uint64_t v = cn_init_2673;
(s2012=(((s2012&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2013=(((s2013&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(v23));
(f[1]=cn_double(((((((s2006>>16))|((s2007<<48))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[0]));
{
__auto_type cn_init_2798 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2798;
(f[1]=(f[1]*v));
}
cn_continue_l12:;
{
{
__auto_type cn_tuple_2835_0 = f[1];
__auto_type cn_tuple_2835_1 = f[0];
__auto_type x = cn_tuple_2835_0;
__auto_type y = cn_tuple_2835_1;
__auto_type cn_init_2864 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_2864;
(f[1]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_2896 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_2896;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_2984 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_2984;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,10)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l12;
}
goto cn_break_b13;
}
goto cn_continue_l12;
cn_break_l12:;
}
cn_break_b13:;
(f[0]=f[1]);
{
__auto_type cn_init_3107 = cn_double(((((((v13>>32))|((v14<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3107;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(v23));
(f[2]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_3202 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3202;
(f[2]=(f[2]*v));
}
cn_continue_l14:;
{
{
__auto_type cn_tuple_3239_0 = f[2];
__auto_type cn_tuple_3239_1 = f[1];
__auto_type x = cn_tuple_3239_0;
__auto_type y = cn_tuple_3239_1;
__auto_type cn_init_3268 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_3268;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_3300 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_3300;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_3388 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_3388;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,10)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l14;
}
goto cn_break_b15;
}
goto cn_continue_l14;
cn_break_l14:;
}
cn_break_b15:;
(f[1]=f[2]);
{
__auto_type cn_init_3511 = cn_double(((((((v13>>32))|((v14<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3511;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(v23));
(f[3]=cn_double(((((((s2004>>16))|((s2005<<48))))&0xffffffffffffffffULL))));
(f[3]=(f[3]*f[2]));
{
__auto_type cn_init_3606 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3606;
(f[3]=(f[3]*v));
}
cn_continue_l16:;
{
{
__auto_type cn_tuple_3643_0 = f[3];
__auto_type cn_tuple_3643_1 = f[2];
__auto_type x = cn_tuple_3643_0;
__auto_type y = cn_tuple_3643_1;
__auto_type cn_init_3672 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_3672;
(f[3]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_3704 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_3704;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
{
__auto_type cn_init_3792 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_3792;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,10)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l16;
}
goto cn_break_b17;
}
goto cn_continue_l16;
cn_break_l16:;
}
cn_break_b17:;
(f[2]=f[3]);
{
__auto_type cn_init_3915 = cn_double(((((((v13>>32))|((v14<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3915;
(f[2]=(f[2]-v));
}
(f[3]=f[2]);
{
__auto_type cn_init_3963 = (((double)(cn_float(((uint32_t)(((((v15>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3963;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_4011 = (((double)(cn_float(((uint32_t)(((((v15>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4011;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_4074 = (((double)(cn_float(((uint32_t)(((((v14>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4074;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_4137 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4137;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_4185 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4185;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_4248 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4248;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_4310 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4310;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_4357 = (((double)(cn_float(((uint32_t)(((((v16>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4357;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_4419 = (((double)(cn_float(((uint32_t)(((((v16>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4419;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_4462 = cn_bits(f[2]); uint64_t v = cn_init_4462;
(s2007=(((s2007&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2008=(((s2008&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_4520 = cn_bits(f[1]); uint64_t v = cn_init_4520;
(s2008=(((s2008&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2009=(((s2009&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_4578 = cn_bits(f[0]); uint64_t v = cn_init_4578;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2008>>16))|((s2009<<48))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4791 = cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4791;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4831 = cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4831;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
(f[1]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_4928 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4928;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_4983 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4983;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
(f[2]=cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5166 = cn_double(((((((s2008>>16))|((s2009<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5166;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_5206 = cn_double(((((((s2008>>16))|((s2009<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5206;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[2]=cn_double(((((((s2008>>16))|((s2009<<48))))&0xffffffffffffffffULL))));
(f[2]=fabs(f[2]));
{
__auto_type cn_init_5303 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5303;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
{
__auto_type cn_init_5358 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5358;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(((((((s2008>>16))|((s2009<<48))))&0xffffffffffffffffULL))));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[2]=sqrt(f[2]));
(f[3]=cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5541 = cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5541;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_5581 = cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5581;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]-f[3]));
(f[3]=cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))));
(f[3]=fabs(f[3]));
{
__auto_type cn_init_5678 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5678;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]-f[3]));
{
__auto_type cn_init_5733 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5733;
(f[2]=(f[2]-v));
}
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_5789 = 0x41U; __auto_type bv = cn_init_5789;
__auto_type cn_init_5802 = cn_reg_get(rg,4,1); __auto_type av = cn_init_5802;
__auto_type cn_init_5820 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5820;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b19;
}
(f[1]=f[2]);
goto cn_break_b20;
}
cn_break_b19:;
(f[2]=f[2]);
}
cn_break_b20:;
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_5914 = 0x41U; __auto_type bv = cn_init_5914;
__auto_type cn_init_5927 = cn_reg_get(rg,4,1); __auto_type av = cn_init_5927;
__auto_type cn_init_5945 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5945;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b22;
}
(f[0]=f[1]);
goto cn_break_b23;
}
cn_break_b22:;
(f[1]=f[1]);
}
cn_break_b23:;
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))));
(f[2]=fabs(f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))));
(f[2]=fabs(f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]/f[1]));
{
__auto_type cn_init_6164 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_6164;
(f[0]=(f[0]/v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_6203 = cn_bits(f[0]); uint64_t v = cn_init_6203;
(s2011=(((s2011&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2012=(((s2012&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[1]=cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_6317 = 0x41U; __auto_type bv = cn_init_6317;
__auto_type cn_init_6330 = cn_reg_get(rg,4,1); __auto_type av = cn_init_6330;
__auto_type cn_init_6348 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_6348;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b25;
}
(f[0]=f[1]);
goto cn_break_b26;
}
cn_break_b25:;
(f[1]=f[1]);
}
cn_break_b26:;
(f[1]=cn_double(v30));
{
__auto_type cn_init_6438 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_6438;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_6466 = cn_bits(f[1]); uint64_t v = cn_init_6466;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_6518 = rg[2]; __auto_type v = cn_init_6518;
__auto_type cn_init_6525 = fl.cf; __auto_type cf = cn_init_6525;
__auto_type cn_init_6543 = cn_alu(&fl,Alu_Sub,v,1,4); __auto_type r = cn_init_6543;
(fl.cf=cf);
(rg[2]=r);
}
if(cn_cond(fl,15)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l11;
}
goto cn_break_b27;
}
goto cn_continue_l11;
cn_break_l11:;
}
cn_break_b27:;
{
__auto_type cn_init_6598 = 0x0U; __auto_type bv = cn_init_6598;
__auto_type cn_init_6615 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_6615;
__auto_type cn_init_6633 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_6633;
}
if(cn_cond(fl,5)){
goto cn_break_b29;
}
{
__auto_type cn_init_6657 = cn_double(v28); __auto_type v = cn_init_6657;
(f[0]=(f[0]/v));
}
}
cn_break_b29:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_6688 = 0x5aU; __auto_type bv = cn_init_6688;
__auto_type cn_init_6696 = rg[4]; __auto_type av = cn_init_6696;
__auto_type cn_init_6714 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_6714;
(rg[4]=r);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10001070U,r14);
cn_wr64u(m,0x10001100U,r32);
cn_wr64u(m,0x10007ea0U,s2004);
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_2447beab2b1a0d2d(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+128))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,0); uint64_t v16 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,8); uint64_t v17 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,16); uint64_t v18 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,24); uint64_t v19 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,32); uint64_t v20 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,40); uint64_t v21 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,48); uint64_t v22 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,56); uint64_t v23 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,64); uint64_t v24 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,72); uint64_t v25 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,80); uint64_t v26 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,88); uint64_t v27 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,96); uint64_t v28 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,104); uint64_t v29 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,112); uint64_t v30 = cn_init_409;
{
{
{
{
{
{
{
{
{
{
__auto_type cn_init_442 = 0xffffffe4U; __auto_type bv = cn_init_442;
__auto_type cn_init_450 = rg[4]; __auto_type av = cn_init_450;
__auto_type cn_init_468 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_468;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_497 = r5; uint64_t s = cn_init_497;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_527 = (CN_U2){v28,v29}; CN_U2 s = cn_init_527;
__auto_type cn_init_537 = m->xmm[0]; __auto_type a = cn_init_537;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_607 = v28; uint64_t s = cn_init_607;
__auto_type cn_init_620 = m->xmm[1][0]; __auto_type a = cn_init_620;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_667 = (CN_U2){v24,v25}; CN_U2 s = cn_init_667;
__auto_type cn_init_677 = m->xmm[0]; __auto_type a = cn_init_677;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_747 = v26; uint64_t s = cn_init_747;
__auto_type cn_init_760 = m->xmm[1][0]; __auto_type a = cn_init_760;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_797 = 0x0U; __auto_type bv = cn_init_797;
__auto_type cn_init_814 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_814;
__auto_type cn_init_832 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_832;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_853 = r32; uint64_t s = cn_init_853;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_875 = v28; uint64_t s = cn_init_875;
__auto_type cn_init_888 = m->xmm[5][0]; __auto_type a = cn_init_888;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(s2012=m->xmm[0][0]);
(s2013=m->xmm[0][1]);
(s2014=m->xmm[1][0]);
(f[0]=cn_double(s2014));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1065 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1065;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,3)){
goto cn_break_b4;
}
(f[1]=cn_double(((((((v18>>32))|((v19<<32))))&0xffffffffffffffffULL))));
goto cn_break_b5;
}
cn_break_b4:;
(f[1]=cn_double(((((((v17>>32))|((v18<<32))))&0xffffffffffffffffULL))));
}
cn_break_b5:;
(r34=cn_bits(f[1]));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1241 = cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1241;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2013));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_1307 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1307;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_1372 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1372;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,2)){
goto cn_break_b7;
}
(f[0]=f[1]);
(f[1]=cn_double(((((((v16>>32))|((v17<<32))))&0xffffffffffffffffULL))));
(r34=cn_bits(f[1]));
goto cn_break_b8;
}
cn_break_b7:;
(f[1]=f[1]);
}
cn_break_b8:;
(f[1]=cn_double(s2012));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_1552 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1552;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_1617 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1617;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,2)){
goto cn_break_b10;
}
(f[0]=f[1]);
(f[1]=cn_double(((((((v16>>32))|((v17<<32))))&0xffffffffffffffffULL))));
(r34=cn_bits(f[1]));
goto cn_break_b11;
}
cn_break_b10:;
(f[1]=f[1]);
}
cn_break_b11:;
(f[1]=cn_double(s2012));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(s2013));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(s2014));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_1880 = cn_double(v23); __auto_type v = cn_init_1880;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1933 = cn_double(v30); __auto_type v = cn_init_1933;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_1952 = 0x0U; __auto_type bv = cn_init_1952;
__auto_type cn_init_1969 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_1969;
__auto_type cn_init_1987 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1987;
}
if(cn_cond(fl,5)){
goto cn_break_b13;
}
{
__auto_type cn_init_2011 = cn_double(v28); __auto_type v = cn_init_2011;
(f[0]=(f[0]/v));
}
}
cn_break_b13:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2042 = 0x1cU; __auto_type bv = cn_init_2042;
__auto_type cn_init_2050 = rg[4]; __auto_type av = cn_init_2050;
__auto_type cn_init_2068 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2068;
(rg[4]=r);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10001070U,r14);
cn_wr64u(m,0x10001100U,r32);
cn_wr64u(m,0x10001110U,r34);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_25017cb141564ccb(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+200))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_242;
__auto_type cn_init_255 = cn_cell(vm,0); uint64_t v25 = cn_init_255;
__auto_type cn_init_268 = cn_cell(vm,8); uint64_t v26 = cn_init_268;
__auto_type cn_init_281 = cn_cell(vm,16); uint64_t v27 = cn_init_281;
__auto_type cn_init_294 = cn_cell(vm,24); uint64_t v28 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,32); uint64_t v29 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,40); uint64_t v30 = cn_init_320;
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v27));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_817 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_817;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,7)){
goto cn_break_b25;
}
if(cn_cond(fl,4)){
goto cn_break_b26;
}
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[2]));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_983 = cn_double(v30); __auto_type v = cn_init_983;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v26));
(f[3]=cn_double(r5));
(f[3]=(f[3]*f[3]));
(f[3]=(f[3]/f[0]));
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
(f[1]=(f[1]*f[2]));
(rg[0]=((uint32_t)(((((v25>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1114 = 0x3U; __auto_type bv = cn_init_1114;
__auto_type cn_init_1127 = cn_reg_get(rg,0,2); __auto_type av = cn_init_1127;
__auto_type cn_init_1145 = cn_alu(&fl,Alu_And,av,bv,2); __auto_type r = cn_init_1145;
cn_reg_set(rg,0,2,r);
}
{
__auto_type cn_init_1165 = 0x0U; __auto_type bv = cn_init_1165;
__auto_type cn_init_1178 = cn_reg_get(rg,0,2); __auto_type av = cn_init_1178;
__auto_type cn_init_1196 = cn_alu(&fl,Alu_Cmp,av,bv,2); __auto_type r = cn_init_1196;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_1234 = cn_double(r10); __auto_type v = cn_init_1234;
(f[1]=(f[1]+v));
}
goto cn_break_b9;
}
cn_break_b4:;
{
__auto_type cn_init_1257 = 0x1U; __auto_type bv = cn_init_1257;
__auto_type cn_init_1270 = cn_reg_get(rg,0,2); __auto_type av = cn_init_1270;
__auto_type cn_init_1288 = cn_alu(&fl,Alu_Cmp,av,bv,2); __auto_type r = cn_init_1288;
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
{
__auto_type cn_init_1312 = cn_double(r10); __auto_type v = cn_init_1312;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
goto cn_break_b9;
}
cn_break_b6:;
{
__auto_type cn_init_1349 = 0x2U; __auto_type bv = cn_init_1349;
__auto_type cn_init_1362 = cn_reg_get(rg,0,2); __auto_type av = cn_init_1362;
__auto_type cn_init_1380 = cn_alu(&fl,Alu_Cmp,av,bv,2); __auto_type r = cn_init_1380;
}
if(cn_cond(fl,5)){
goto cn_break_b8;
}
(f[2]=f[1]);
{
__auto_type cn_init_1414 = cn_double(r10); __auto_type v = cn_init_1414;
(f[2]=(f[2]+v));
}
(f[2]=fabs(f[2]));
(f[3]=f[1]);
{
__auto_type cn_init_1462 = cn_double(r10); __auto_type v = cn_init_1462;
(f[3]=(f[3]-v));
}
(f[3]=fabs(f[3]));
cn_swap(f,3,2);
(f[2]=(f[3]-f[2]));
cn_swap(f,2,1);
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
goto cn_break_b9;
}
cn_break_b8:;
{
__auto_type cn_init_1563 = cn_double(r10); __auto_type v = cn_init_1563;
(f[1]=(f[1]+v));
}
}
cn_break_b9:;
(f[2]=cn_double(r3));
{
__auto_type cn_init_1600 = cn_double(r4); __auto_type v = cn_init_1600;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1624 = cn_double(v29); __auto_type v = cn_init_1624;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(v26));
(f[4]=cn_double(r5));
(f[4]=(f[4]*f[4]));
(f[4]=(f[4]/f[0]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]*f[3]));
(rg[0]=((uint32_t)(((((v25>>32))&0xffffffffULL)))));
cn_shift_reg_l(rg,&fl,Shift_Shr,0,2,2);
{
__auto_type cn_init_1776 = 0x3U; __auto_type bv = cn_init_1776;
__auto_type cn_init_1789 = cn_reg_get(rg,0,2); __auto_type av = cn_init_1789;
__auto_type cn_init_1807 = cn_alu(&fl,Alu_And,av,bv,2); __auto_type r = cn_init_1807;
cn_reg_set(rg,0,2,r);
}
{
__auto_type cn_init_1827 = 0x0U; __auto_type bv = cn_init_1827;
__auto_type cn_init_1840 = cn_reg_get(rg,0,2); __auto_type av = cn_init_1840;
__auto_type cn_init_1858 = cn_alu(&fl,Alu_Cmp,av,bv,2); __auto_type r = cn_init_1858;
}
if(cn_cond(fl,5)){
goto cn_break_b11;
}
(f[2]=fabs(f[2]));
{
__auto_type cn_init_1896 = cn_double(r11); __auto_type v = cn_init_1896;
(f[2]=(f[2]+v));
}
goto cn_break_b16;
}
cn_break_b11:;
{
__auto_type cn_init_1919 = 0x1U; __auto_type bv = cn_init_1919;
__auto_type cn_init_1932 = cn_reg_get(rg,0,2); __auto_type av = cn_init_1932;
__auto_type cn_init_1950 = cn_alu(&fl,Alu_Cmp,av,bv,2); __auto_type r = cn_init_1950;
}
if(cn_cond(fl,5)){
goto cn_break_b13;
}
{
__auto_type cn_init_1974 = cn_double(r11); __auto_type v = cn_init_1974;
(f[2]=(f[2]+v));
}
(f[2]=fabs(f[2]));
goto cn_break_b16;
}
cn_break_b13:;
{
__auto_type cn_init_2011 = 0x2U; __auto_type bv = cn_init_2011;
__auto_type cn_init_2024 = cn_reg_get(rg,0,2); __auto_type av = cn_init_2024;
__auto_type cn_init_2042 = cn_alu(&fl,Alu_Cmp,av,bv,2); __auto_type r = cn_init_2042;
}
if(cn_cond(fl,5)){
goto cn_break_b15;
}
(f[3]=f[2]);
{
__auto_type cn_init_2076 = cn_double(r11); __auto_type v = cn_init_2076;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_2124 = cn_double(r11); __auto_type v = cn_init_2124;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
cn_swap(f,4,3);
(f[3]=(f[4]-f[3]));
cn_swap(f,3,2);
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
goto cn_break_b16;
}
cn_break_b15:;
{
__auto_type cn_init_2225 = cn_double(r11); __auto_type v = cn_init_2225;
(f[2]=(f[2]+v));
}
}
cn_break_b16:;
(f[3]=cn_double(r5));
(f[4]=f[0]);
(f[4]=sqrt(f[4]));
(f[3]=(f[3]*f[4]));
{
__auto_type cn_init_2301 = cn_double(v28); __auto_type v = cn_init_2301;
(f[3]=(f[3]*v));
}
(rg[0]=((uint32_t)(((((v25>>32))&0xffffffffULL)))));
cn_shift_reg_l(rg,&fl,Shift_Shr,0,4,2);
{
__auto_type cn_init_2358 = 0x3U; __auto_type bv = cn_init_2358;
__auto_type cn_init_2371 = cn_reg_get(rg,0,2); __auto_type av = cn_init_2371;
__auto_type cn_init_2389 = cn_alu(&fl,Alu_And,av,bv,2); __auto_type r = cn_init_2389;
cn_reg_set(rg,0,2,r);
}
{
__auto_type cn_init_2409 = 0x0U; __auto_type bv = cn_init_2409;
__auto_type cn_init_2422 = cn_reg_get(rg,0,2); __auto_type av = cn_init_2422;
__auto_type cn_init_2440 = cn_alu(&fl,Alu_Cmp,av,bv,2); __auto_type r = cn_init_2440;
}
if(cn_cond(fl,5)){
goto cn_break_b18;
}
(f[3]=fabs(f[3]));
{
__auto_type cn_init_2478 = cn_double(r12); __auto_type v = cn_init_2478;
(f[3]=(f[3]+v));
}
goto cn_break_b24;
}
cn_break_b18:;
{
__auto_type cn_init_2501 = 0x1U; __auto_type bv = cn_init_2501;
__auto_type cn_init_2514 = cn_reg_get(rg,0,2); __auto_type av = cn_init_2514;
__auto_type cn_init_2532 = cn_alu(&fl,Alu_Cmp,av,bv,2); __auto_type r = cn_init_2532;
}
if(cn_cond(fl,5)){
goto cn_break_b20;
}
{
__auto_type cn_init_2556 = cn_double(r12); __auto_type v = cn_init_2556;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
goto cn_break_b24;
}
cn_break_b20:;
{
__auto_type cn_init_2593 = 0x2U; __auto_type bv = cn_init_2593;
__auto_type cn_init_2606 = cn_reg_get(rg,0,2); __auto_type av = cn_init_2606;
__auto_type cn_init_2624 = cn_alu(&fl,Alu_Cmp,av,bv,2); __auto_type r = cn_init_2624;
}
if(cn_cond(fl,5)){
goto cn_break_b22;
}
(f[4]=f[3]);
{
__auto_type cn_init_2658 = cn_double(r12); __auto_type v = cn_init_2658;
(f[4]=(f[4]+v));
}
(f[4]=fabs(f[4]));
(f[5]=f[3]);
{
__auto_type cn_init_2706 = cn_double(r12); __auto_type v = cn_init_2706;
(f[5]=(f[5]-v));
}
(f[5]=fabs(f[5]));
cn_swap(f,5,4);
(f[4]=(f[5]-f[4]));
cn_swap(f,4,3);
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
goto cn_break_b24;
}
cn_break_b22:;
{
__auto_type cn_init_2807 = cn_double(r12); __auto_type v = cn_init_2807;
(f[3]=(f[3]+v));
}
goto cn_break_b23;
}
cn_break_b26:;
(f[1]=cn_double(r10));
(f[2]=cn_double(r11));
(f[3]=cn_double(r12));
goto cn_break_b23;
}
cn_break_b25:;
(f[1]=cn_double(0x0));
(f[2]=cn_double(0x0));
(f[3]=cn_double(0x0));
}
cn_break_b23:;
}
cn_break_b24:;
(r5=cn_bits(f[3]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(f[0]=f[0]);
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s2012>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2012>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[0]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_2514ff7bf0f8abc3(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+224))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_195;
__auto_type cn_init_208 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_208;
__auto_type cn_init_221 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_221;
__auto_type cn_init_234 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_234;
__auto_type cn_init_247 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_247;
__auto_type cn_init_260 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_260;
__auto_type cn_init_273 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_273;
__auto_type cn_init_286 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_286;
__auto_type cn_init_299 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,0); uint64_t v28 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,8); uint64_t v29 = cn_init_325;
__auto_type cn_init_338 = cn_cell(vm,16); uint64_t v30 = cn_init_338;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_404 = 0x40U; __auto_type bv = cn_init_404;
__auto_type cn_init_412 = rg[4]; __auto_type av = cn_init_412;
__auto_type cn_init_430 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_430;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2005=(((s2005&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2005=(((s2005&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2013=cn_bits(f[0]));
(f[1]=cn_double(v30));
cn_swap(f,1,0);
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_850_0 = f[2];
__auto_type cn_tuple_850_1 = f[1];
__auto_type x = cn_tuple_850_0;
__auto_type y = cn_tuple_850_1;
__auto_type cn_init_879 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_879;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_911 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_911;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2011=cn_bits(f[0]));
(f[1]=cn_double(r3));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1176 = cn_double(v30); __auto_type v = cn_init_1176;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1206_0 = sin(f[0]);
__auto_type cn_tuple_1206_1 = cos(f[0]);
__auto_type s = cn_tuple_1206_0;
__auto_type c = cn_tuple_1206_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2009=cn_bits(f[1]));
(s2010=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[1]=cn_double(r5));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1301 = cn_double(v29); __auto_type v = cn_init_1301;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1331_0 = sin(f[0]);
__auto_type cn_tuple_1331_1 = cos(f[0]);
__auto_type s = cn_tuple_1331_0;
__auto_type c = cn_tuple_1331_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2007=cn_bits(f[1]));
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_1396 = cn_double(s2012); __auto_type v = cn_init_1396;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1420 = cn_double(r10); __auto_type v = cn_init_1420;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_1467 = cn_double(s2008); __auto_type v = cn_init_1467;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1491 = cn_double(s2012); __auto_type v = cn_init_1491;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_1538 = cn_double(s2007); __auto_type v = cn_init_1538;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1562 = cn_double(v28); __auto_type v = cn_init_1562;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1586 = cn_double(s2012); __auto_type v = cn_init_1586;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s2004>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2005>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2005>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[4]=rg[5]);
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ea0U,s2004);
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_25b0e599b5e18c3f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+144))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_240;
__auto_type cn_init_253 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,0); uint64_t v18 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,8); uint64_t v19 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,16); uint64_t v20 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,24); uint64_t v21 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,32); uint64_t v22 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,40); uint64_t v23 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,48); uint64_t v24 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,56); uint64_t v25 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,64); uint64_t v26 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,72); uint64_t v27 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,80); uint64_t v28 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,88); uint64_t v29 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,96); uint64_t v30 = cn_init_422;
__auto_type cn_init_435 = cn_cell(vm,112); uint64_t v32 = cn_init_435;
{
{
{
{
{
{
__auto_type cn_init_456 = 0xffffffbaU; __auto_type bv = cn_init_456;
__auto_type cn_init_464 = rg[4]; __auto_type av = cn_init_464;
__auto_type cn_init_482 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_482;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_511 = r5; uint64_t s = cn_init_511;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_541 = (CN_U2){v28,v29}; CN_U2 s = cn_init_541;
__auto_type cn_init_551 = m->xmm[0]; __auto_type a = cn_init_551;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_621 = v28; uint64_t s = cn_init_621;
__auto_type cn_init_634 = m->xmm[1][0]; __auto_type a = cn_init_634;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_681 = (CN_U2){v24,v25}; CN_U2 s = cn_init_681;
__auto_type cn_init_691 = m->xmm[0]; __auto_type a = cn_init_691;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_761 = v26; uint64_t s = cn_init_761;
__auto_type cn_init_774 = m->xmm[1][0]; __auto_type a = cn_init_774;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_811 = 0x0U; __auto_type bv = cn_init_811;
__auto_type cn_init_828 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_828;
__auto_type cn_init_846 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_846;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_867 = r32; uint64_t s = cn_init_867;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_889 = v28; uint64_t s = cn_init_889;
__auto_type cn_init_902 = m->xmm[5][0]; __auto_type a = cn_init_902;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_998 = m->xmm[0][0]; uint64_t v = cn_init_998;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1057 = m->xmm[0][1]; uint64_t v = cn_init_1057;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1116 = m->xmm[1][0]; uint64_t v = cn_init_1116;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(0x0));
{
__auto_type cn_init_1186 = cn_bits(f[0]); uint64_t v = cn_init_1186;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1244 = cn_bits(f[0]); uint64_t v = cn_init_1244;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1293 = 0xffffffd4U; __auto_type bv = cn_init_1293;
__auto_type cn_init_1301 = rg[7]; __auto_type av = cn_init_1301;
__auto_type cn_init_1319 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1319;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1446 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1446;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1494 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1494;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1557 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1557;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1620 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1620;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1668 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1668;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1731 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1731;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1793 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1793;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1840 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1840;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1902 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1902;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1945 = cn_bits(f[2]); uint64_t v = cn_init_1945;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_2003 = cn_bits(f[1]); uint64_t v = cn_init_2003;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_2061 = cn_bits(f[0]); uint64_t v = cn_init_2061;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_2110 = 0x2cU; __auto_type bv = cn_init_2110;
__auto_type cn_init_2118 = rg[7]; __auto_type av = cn_init_2118;
__auto_type cn_init_2136 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2136;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2318 = cn_bits(f[0]); uint64_t v = cn_init_2318;
(s2011=(((s2011&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2012=(((s2012&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_2372 = cn_double(v23); __auto_type v = cn_init_2372;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2412 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2412;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2452 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2452;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2480 = cn_bits(f[0]); uint64_t v = cn_init_2480;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(v30));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[1]=-f[1]);
(f[2]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2700 = cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2700;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2740 = cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2740;
(f[0]=(f[0]*v));
}
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
{
__auto_type cn_init_2847 = cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2847;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_2875 = cn_bits(f[0]); uint64_t v = cn_init_2875;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
goto cn_break_b5;
}
cn_break_b4:;
{
__auto_type cn_init_2949 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2949;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2977 = cn_bits(f[0]); uint64_t v = cn_init_2977;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b5:;
(f[0]=cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))));
(f[0]=sqrt(f[0]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))));
(f[1]=sqrt(f[1]));
(f[1]=sqrt(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((s2011>>48))|((s2012<<16))))&0xffffffffffffffffULL))));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_3212 = cn_double(v30); __auto_type v = cn_init_3212;
(f[1]=(f[1]-v));
}
(f[2]=f[1]);
(f[2]=fabs(f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=(f[1]+f[1]));
(f[1]=(f[1]+f[1]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3320 = cn_double(v32); __auto_type v = cn_init_3320;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3339 = 0x0U; __auto_type bv = cn_init_3339;
__auto_type cn_init_3356 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_3356;
__auto_type cn_init_3374 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3374;
}
if(cn_cond(fl,5)){
goto cn_break_b7;
}
{
__auto_type cn_init_3398 = cn_double(v28); __auto_type v = cn_init_3398;
(f[0]=(f[0]/v));
}
}
cn_break_b7:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_3429 = 0x46U; __auto_type bv = cn_init_3429;
__auto_type cn_init_3437 = rg[4]; __auto_type av = cn_init_3437;
__auto_type cn_init_3455 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3455;
(rg[4]=r);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10001070U,r14);
cn_wr64u(m,0x10001100U,r32);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_268ab00071700e27(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_44 = 0ULL; __auto_type steps = cn_init_44;
__auto_type cn_init_49 = max_steps; __auto_type limit = cn_init_49;
__auto_type cn_init_62 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+152))); unsigned char * vm = cn_init_82;
__auto_type cn_init_95 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_95;
__auto_type cn_init_108 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_108;
__auto_type cn_init_121 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_121;
__auto_type cn_init_134 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_134;
__auto_type cn_init_147 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_147;
__auto_type cn_init_160 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_160;
__auto_type cn_init_173 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_173;
__auto_type cn_init_186 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_186;
__auto_type cn_init_199 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_199;
__auto_type cn_init_212 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_212;
__auto_type cn_init_225 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_225;
__auto_type cn_init_238 = cn_cell(vm,0); uint64_t v19 = cn_init_238;
__auto_type cn_init_251 = cn_cell(vm,8); uint64_t v20 = cn_init_251;
__auto_type cn_init_264 = cn_cell(vm,16); uint64_t v21 = cn_init_264;
__auto_type cn_init_277 = cn_cell(vm,24); uint64_t v22 = cn_init_277;
__auto_type cn_init_290 = cn_cell(vm,32); uint64_t v23 = cn_init_290;
__auto_type cn_init_303 = cn_cell(vm,40); uint64_t v24 = cn_init_303;
__auto_type cn_init_316 = cn_cell(vm,48); uint64_t v25 = cn_init_316;
__auto_type cn_init_329 = cn_cell(vm,56); uint64_t v26 = cn_init_329;
__auto_type cn_init_342 = cn_cell(vm,64); uint64_t v27 = cn_init_342;
__auto_type cn_init_355 = cn_cell(vm,72); uint64_t v28 = cn_init_355;
__auto_type cn_init_368 = cn_cell(vm,80); uint64_t v29 = cn_init_368;
__auto_type cn_init_381 = cn_cell(vm,88); uint64_t v30 = cn_init_381;
__auto_type cn_init_394 = cn_cell(vm,104); uint64_t v32 = cn_init_394;
__auto_type cn_init_407 = cn_cell(vm,112); uint64_t v33 = cn_init_407;
__auto_type cn_init_420 = cn_cell(vm,120); uint64_t v34 = cn_init_420;
{
{
{
{
{
{
{
{
{
__auto_type cn_init_450 = 0xffffffb0U; __auto_type bv = cn_init_450;
__auto_type cn_init_458 = rg[4]; __auto_type av = cn_init_458;
__auto_type cn_init_476 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_476;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_505 = r5; uint64_t s = cn_init_505;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_535 = (CN_U2){v28,v29}; CN_U2 s = cn_init_535;
__auto_type cn_init_545 = m->xmm[0]; __auto_type a = cn_init_545;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_615 = v28; uint64_t s = cn_init_615;
__auto_type cn_init_628 = m->xmm[1][0]; __auto_type a = cn_init_628;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_675 = (CN_U2){v24,v25}; CN_U2 s = cn_init_675;
__auto_type cn_init_685 = m->xmm[0]; __auto_type a = cn_init_685;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_755 = v26; uint64_t s = cn_init_755;
__auto_type cn_init_768 = m->xmm[1][0]; __auto_type a = cn_init_768;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_805 = 0x0U; __auto_type bv = cn_init_805;
__auto_type cn_init_822 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_822;
__auto_type cn_init_840 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_840;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_861 = r32; uint64_t s = cn_init_861;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_883 = v28; uint64_t s = cn_init_883;
__auto_type cn_init_896 = m->xmm[5][0]; __auto_type a = cn_init_896;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_992 = m->xmm[0][0]; uint64_t v = cn_init_992;
(s2005=(((s2005&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2006=(((s2006&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1051 = m->xmm[0][1]; uint64_t v = cn_init_1051;
(s2006=(((s2006&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2007=(((s2007&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1110 = m->xmm[1][0]; uint64_t v = cn_init_1110;
(s2007=(((s2007&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2008=(((s2008&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1159 = 0x2U; __auto_type v = cn_init_1159;
(rg[2]=v);
}
cn_continue_l3:;
{
(f[0]=cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1228 = cn_bits(f[0]); uint64_t v = cn_init_1228;
(s2005=(((s2005&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2006=(((s2006&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1282 = cn_double(v32); __auto_type v = cn_init_1282;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_1352 = cn_bits(f[1]); uint64_t v = cn_init_1352;
(s2006=(((s2006&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2007=(((s2007&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1406 = cn_double(v33); __auto_type v = cn_init_1406;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
(f[2]=fabs(f[2]));
{
__auto_type cn_init_1476 = cn_bits(f[2]); uint64_t v = cn_init_1476;
(s2007=(((s2007&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2008=(((s2008&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1530 = cn_double(v34); __auto_type v = cn_init_1530;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=-f[0]);
(f[1]=f[0]);
{
__auto_type cn_init_1644 = cn_double(v32); __auto_type v = cn_init_1644;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1684 = cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1684;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_1712 = cn_bits(f[1]); uint64_t v = cn_init_1712;
(s2005=(((s2005&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2006=(((s2006&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[1]=f[0]);
{
__auto_type cn_init_1776 = cn_double(v33); __auto_type v = cn_init_1776;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1816 = cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1816;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_1844 = cn_bits(f[1]); uint64_t v = cn_init_1844;
(s2006=(((s2006&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2007=(((s2007&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[1]=f[0]);
{
__auto_type cn_init_1908 = cn_double(v34); __auto_type v = cn_init_1908;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1948 = cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1948;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_1976 = cn_bits(f[1]); uint64_t v = cn_init_1976;
(s2007=(((s2007&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2008=(((s2008&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=f[0]);
(f[0]=cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2068 = cn_double(v33); __auto_type v = cn_init_2068;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2120 = cn_double(v34); __auto_type v = cn_init_2120;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[2]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2183 = cn_double(v32); __auto_type v = cn_init_2183;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_2297 = cn_double(v33); __auto_type v = cn_init_2297;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
{
__auto_type cn_init_2348 = cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2348;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2376 = cn_bits(f[1]); uint64_t v = cn_init_2376;
(s2005=(((s2005&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2006=(((s2006&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[1]=f[0]);
{
__auto_type cn_init_2440 = cn_double(v34); __auto_type v = cn_init_2440;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2480 = cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2480;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2508 = cn_bits(f[1]); uint64_t v = cn_init_2508;
(s2006=(((s2006&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2007=(((s2007&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[1]=f[0]);
{
__auto_type cn_init_2572 = cn_double(v32); __auto_type v = cn_init_2572;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2612 = cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2612;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2640 = cn_bits(f[1]); uint64_t v = cn_init_2640;
(s2007=(((s2007&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2008=(((s2008&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=f[0]);
{
__auto_type cn_init_2702 = rg[2]; __auto_type v = cn_init_2702;
__auto_type cn_init_2709 = fl.cf; __auto_type cf = cn_init_2709;
__auto_type cn_init_2727 = cn_alu(&fl,Alu_Sub,v,1,4); __auto_type r = cn_init_2727;
(fl.cf=cf);
(rg[2]=r);
}
if(cn_cond(fl,15)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l3;
}
goto cn_break_b4;
}
goto cn_continue_l3;
cn_break_l3:;
}
cn_break_b4:;
(f[0]=cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))));
(f[0]=fabs(f[0]));
(f[1]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
(f[1]=fabs(f[1]));
(f[2]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
(f[2]=fabs(f[2]));
(f[3]=cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[3]));
(f[3]=f[3]);
(f[3]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[3]));
(f[3]=f[3]);
(f[3]=cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[3]));
(f[3]=f[3]);
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3102 = cn_double(v30); __auto_type v = cn_init_3102;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
(f[2]=cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))));
(f[2]=fabs(f[2]));
(f[1]=(f[1]-f[2]));
(rg[2]=((uint32_t)(((((v23>>0))&0xffffffffULL)))));
{
__auto_type cn_init_3368 = 0x80000000U; __auto_type bv = cn_init_3368;
__auto_type cn_init_3376 = rg[2]; __auto_type av = cn_init_3376;
__auto_type cn_init_3394 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_3394;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b8;
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_3457 = 0x41U; __auto_type bv = cn_init_3457;
__auto_type cn_init_3470 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3470;
__auto_type cn_init_3488 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3488;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b7;
}
(f[0]=f[1]);
goto cn_break_b11;
}
cn_break_b7:;
(f[1]=f[1]);
goto cn_break_b11;
}
cn_break_b8:;
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_3585 = 0x41U; __auto_type bv = cn_init_3585;
__auto_type cn_init_3598 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3598;
__auto_type cn_init_3616 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3616;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b10;
}
(f[1]=f[1]);
goto cn_break_b11;
}
cn_break_b10:;
(f[0]=f[1]);
}
cn_break_b11:;
{
__auto_type cn_init_3673 = 0x0U; __auto_type bv = cn_init_3673;
__auto_type cn_init_3690 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_3690;
__auto_type cn_init_3708 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3708;
}
if(cn_cond(fl,5)){
goto cn_break_b13;
}
{
__auto_type cn_init_3732 = cn_double(v28); __auto_type v = cn_init_3732;
(f[0]=(f[0]/v));
}
}
cn_break_b13:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_3763 = 0x50U; __auto_type bv = cn_init_3763;
__auto_type cn_init_3771 = rg[4]; __auto_type av = cn_init_3771;
__auto_type cn_init_3789 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3789;
(rg[4]=r);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10001070U,r14);
cn_wr64u(m,0x10001100U,r32);
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_29e575922b051916(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_58 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_58;
__auto_type cn_init_75 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_75;
__auto_type cn_init_88 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_88;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(r5=cn_bits(f[1]));
(r4=cn_bits(f[0]));
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_2a196bafa4357ec1(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+232))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_178;
__auto_type cn_init_191 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_191;
__auto_type cn_init_204 = cn_cell(vm,0); uint64_t v29 = cn_init_204;
__auto_type cn_init_217 = cn_cell(vm,8); uint64_t v30 = cn_init_217;
{
{
{
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(v30));
(f[1]=cn_double(r3));
{
__auto_type cn_init_509 = cn_double(v29); __auto_type v = cn_init_509;
(f[1]=(f[1]*v));
}
(f[1]=(f[0]-f[1]));
(f[2]=cn_double(r4));
{
__auto_type cn_init_560 = cn_double(v29); __auto_type v = cn_init_560;
(f[2]=(f[2]*v));
}
(f[2]=(f[0]-f[2]));
(f[3]=cn_double(r5));
{
__auto_type cn_init_611 = cn_double(v29); __auto_type v = cn_init_611;
(f[3]=(f[3]*v));
}
(f[3]=(f[0]-f[3]));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
{
__auto_type cn_init_682 = 0x41U; __auto_type bv = cn_init_682;
__auto_type cn_init_695 = cn_reg_get(rg,4,1); __auto_type av = cn_init_695;
__auto_type cn_init_713 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_713;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,14)){
goto cn_break_b2;
}
(f[2]=f[3]);
goto cn_break_b3;
}
cn_break_b2:;
(f[3]=f[3]);
}
cn_break_b3:;
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_807 = 0x41U; __auto_type bv = cn_init_807;
__auto_type cn_init_820 = cn_reg_get(rg,4,1); __auto_type av = cn_init_820;
__auto_type cn_init_838 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_838;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,14)){
goto cn_break_b5;
}
(f[1]=f[2]);
goto cn_break_b6;
}
cn_break_b5:;
(f[2]=f[2]);
}
cn_break_b6:;
(f[0]=f[1]);
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r3));
(f[1]=(f[1]-f[0]));
(f[2]=cn_double(r4));
(f[2]=(f[2]-f[0]));
(f[3]=cn_double(r5));
(f[3]=(f[3]-f[0]));
(r5=cn_bits(f[3]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(f[0]=f[0]);
(rg[0]=rg[3]);
{
(rg[3]=((uint32_t)(((((s2012>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[7]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_2a3ad3459047dc56(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+240))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(0)); uint64_t r0 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_190;
__auto_type cn_init_207 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_207;
__auto_type cn_init_224 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_224;
__auto_type cn_init_237 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_237;
__auto_type cn_init_250 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_250;
__auto_type cn_init_263 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_263;
__auto_type cn_init_276 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_276;
__auto_type cn_init_289 = cn_cell(vm,0); uint64_t v30 = cn_init_289;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r6));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r3));
{
__auto_type cn_init_710 = cn_double(r5); __auto_type v = cn_init_710;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r4));
{
__auto_type cn_init_746 = cn_double(r6); __auto_type v = cn_init_746;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[1]=(f[1]+f[1]));
(f[2]=cn_double(r3));
{
__auto_type cn_init_812 = cn_double(r6); __auto_type v = cn_init_812;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r4));
{
__auto_type cn_init_848 = cn_double(r5); __auto_type v = cn_init_848;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[2]=(f[2]+f[2]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[3]));
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]-f[4]));
(f[3]=(f[3]+f[3]));
(f[4]=cn_double(r3));
{
__auto_type cn_init_998 = cn_double(r4); __auto_type v = cn_init_998;
(f[4]=(f[4]*v));
}
(f[4]=(f[4]+f[4]));
(f[4]=(f[4]+f[4]));
(r4=cn_bits(f[4]));
(r3=cn_bits(f[3]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[3]));
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[3]=sqrt(f[3]));
(f[3]=(f[0]/f[3]));
(f[3]=-f[3]);
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
(f[4]=(f[4]*f[3]));
(r3=cn_bits(f[4]));
(f[4]=cn_double(r4));
(f[3]=(f[3]*f[4]));
(r4=cn_bits(f[3]));
(r6=cn_bits(f[2]));
(r5=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(r10));
{
__auto_type cn_init_1330 = cn_double(r3); __auto_type v = cn_init_1330;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r11));
{
__auto_type cn_init_1377 = cn_double(r4); __auto_type v = cn_init_1377;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r12));
{
__auto_type cn_init_1424 = cn_double(r5); __auto_type v = cn_init_1424;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r0));
{
__auto_type cn_init_1471 = cn_double(v30); __auto_type v = cn_init_1471;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1495 = cn_double(r6); __auto_type v = cn_init_1495;
(f[0]=(f[0]+v));
}
(r6=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s2012>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[4]=rg[5]);
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_2aa886369f57321b(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+208))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_178;
__auto_type cn_init_191 = cn_cell(vm,0); uint64_t v26 = cn_init_191;
__auto_type cn_init_204 = cn_cell(vm,8); uint64_t v27 = cn_init_204;
__auto_type cn_init_217 = cn_cell(vm,16); uint64_t v28 = cn_init_217;
__auto_type cn_init_230 = cn_cell(vm,24); uint64_t v29 = cn_init_230;
__auto_type cn_init_243 = cn_cell(vm,32); uint64_t v30 = cn_init_243;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_455 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_455;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_503 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_503;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_566 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_566;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_629 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_629;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_677 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_677;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_740 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_740;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_802 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_802;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_849 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_849;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_911 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_911;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
{
(rg[6]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_2ae643c3730b173d(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;
__auto_type cn_init_11 = (CN_D8){0}; __auto_type f = cn_init_11;
__auto_type cn_init_19 = m->regs; __auto_type rg = cn_init_19;
__auto_type cn_init_27 = m->fl; __auto_type fl = cn_init_27;
__auto_type cn_init_35 = m->fsw_cc; __auto_type fsw = cn_init_35;
__auto_type cn_init_43 = m->steps; __auto_type steps = cn_init_43;
__auto_type cn_init_50 = (steps+max_steps); __auto_type limit = cn_init_50;
{
__auto_type cn_init_59 = 0; uint32_t b = cn_init_59;
for(;;){
switch(b){
case 0:
{
{
__auto_type cn_init_76 = rg[5]; __auto_type v = cn_init_76;
cn_push_lu(m,rg,v);
}
(rg[5]=rg[4]);
{
__auto_type cn_init_107 = rg[0]; __auto_type v = cn_init_107;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_128 = rg[2]; __auto_type v = cn_init_128;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_149 = rg[6]; __auto_type v = cn_init_149;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_170 = rg[7]; __auto_type v = cn_init_170;
cn_push_lu(m,rg,v);
}
(rg[6]=cn_rd32u(m,((uint32_t)(rg[5]+0x8U))));
(rg[7]=cn_rd32u(m,((uint32_t)(rg[6]+0x30U))));
{
__auto_type cn_init_236 = ((uint32_t)(rg[6]+0xd0U)); __auto_type a = cn_init_236;
__auto_type cn_init_246 = cn_rd32u(m,a); __auto_type v = cn_init_246;
__auto_type cn_init_253 = fl.cf; __auto_type cf = cn_init_253;
__auto_type cn_init_271 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_271;
(fl.cf=cf);
cn_wr32u(m,a,r);
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[6]+0xd0U))));
(rg[2]=rg[0]);
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xfffffff4U))));
{
__auto_type cn_init_343 = 0x1U; __auto_type bv = cn_init_343;
__auto_type cn_init_351 = rg[0]; __auto_type av = cn_init_351;
__auto_type cn_init_369 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_369;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=2);
continue;
}
(b=1);
}
break;
case 1:
{
{
__auto_type cn_init_417 = 0x1U; __auto_type v = cn_init_417;
(rg[0]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=4);
continue;
}
break;
case 2:
{
{
__auto_type cn_init_459 = 0x64U; __auto_type bv = cn_init_459;
__auto_type cn_init_467 = rg[0]; __auto_type av = cn_init_467;
__auto_type cn_init_485 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_485;
}
if(cn_cond(fl,14)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=4);
continue;
}
(b=3);
}
break;
case 3:
{
{
__auto_type cn_init_533 = 0x64U; __auto_type v = cn_init_533;
(rg[0]=v);
}
(b=4);
}
break;
case 4:
{
{
__auto_type cn_init_558 = rg[0]; __auto_type bv = cn_init_558;
__auto_type cn_init_566 = rg[2]; __auto_type av = cn_init_566;
__auto_type cn_init_584 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_584;
}
if(cn_cond(fl,12)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=7);
continue;
}
(b=5);
}
break;
case 5:
{
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=19);
continue;
}
(b=6);
}
break;
case 6:
{
(steps+=1);
if((steps>limit)){
return 1;
}
(b=20);
continue;
}
break;
case 7:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffecU))));
(b=8);
}
break;
case 8:
{
{
__auto_type cn_init_729 = 0x0U; __auto_type bv = cn_init_729;
__auto_type cn_init_737 = rg[0]; __auto_type av = cn_init_737;
__auto_type cn_init_755 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_755;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=10);
continue;
}
(b=9);
}
break;
case 9:
{
{
__auto_type cn_init_803 = 0x0U; __auto_type v = cn_init_803;
(rg[0]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=12);
continue;
}
break;
case 10:
{
{
__auto_type cn_init_845 = 0x64U; __auto_type bv = cn_init_845;
__auto_type cn_init_853 = rg[0]; __auto_type av = cn_init_853;
__auto_type cn_init_871 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_871;
}
if(cn_cond(fl,14)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=12);
continue;
}
(b=11);
}
break;
case 11:
{
{
__auto_type cn_init_919 = 0x64U; __auto_type v = cn_init_919;
(rg[0]=v);
}
(b=12);
}
break;
case 12:
{
(rg[7]=cn_rd32u(m,((uint32_t)(rg[7]+0xfffffff0U))));
{
__auto_type cn_init_961 = 0x1U; __auto_type bv = cn_init_961;
__auto_type cn_init_969 = rg[7]; __auto_type av = cn_init_969;
__auto_type cn_init_987 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_987;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=14);
continue;
}
(b=13);
}
break;
case 13:
{
{
__auto_type cn_init_1035 = 0x1U; __auto_type v = cn_init_1035;
(rg[7]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=16);
continue;
}
break;
case 14:
{
{
__auto_type cn_init_1077 = 0x6U; __auto_type bv = cn_init_1077;
__auto_type cn_init_1085 = rg[7]; __auto_type av = cn_init_1085;
__auto_type cn_init_1103 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1103;
}
if(cn_cond(fl,14)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=16);
continue;
}
(b=15);
}
break;
case 15:
{
{
__auto_type cn_init_1151 = 0x6U; __auto_type v = cn_init_1151;
(rg[7]=v);
}
(b=16);
}
break;
case 16:
{
(rg[7]=((uint32_t)((((uint32_t)(rg[6]+0x48U)))+((uint32_t)(rg[7]*4)))));
{
__auto_type cn_init_1203 = 0x0U; __auto_type bv = cn_init_1203;
__auto_type cn_init_1222 = cn_rd32(m,((uint32_t)(rg[7]+0x0U))); __auto_type av = cn_init_1222;
__auto_type cn_init_1240 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1240;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=18);
continue;
}
(b=17);
}
break;
case 17:
{
{
__auto_type cn_init_1288 = 0x80000000U; __auto_type bv = cn_init_1288;
__auto_type cn_init_1296 = rg[0]; __auto_type av = cn_init_1296;
__auto_type cn_init_1314 = cn_alu(&fl,Alu_Or,av,bv,4); __auto_type r = cn_init_1314;
(rg[0]=r);
}
(b=18);
}
break;
case 18:
{
{
__auto_type cn_init_1344 = ((uint32_t)(rg[7]+0x0U)); __auto_type a = cn_init_1344;
cn_wr32(m,a,rg[0]);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=21);
continue;
}
break;
case 19:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffe8U))));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=8);
continue;
}
break;
case 20:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffe4U))));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=8);
continue;
}
break;
case 21:
{
(rg[7]=cn_rd32u(m,((uint32_t)(rg[6]+0x30U))));
{
__auto_type cn_init_1508 = 0xffffffecU; __auto_type bv = cn_init_1508;
__auto_type cn_init_1516 = rg[7]; __auto_type av = cn_init_1516;
__auto_type cn_init_1534 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1534;
(rg[7]=r);
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xfffffff4U))));
{
__auto_type cn_init_1568 = 0x1U; __auto_type bv = cn_init_1568;
__auto_type cn_init_1576 = rg[0]; __auto_type av = cn_init_1576;
__auto_type cn_init_1594 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1594;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=23);
continue;
}
(b=22);
}
break;
case 22:
{
{
__auto_type cn_init_1642 = 0x1U; __auto_type v = cn_init_1642;
(rg[0]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=25);
continue;
}
break;
case 23:
{
{
__auto_type cn_init_1684 = 0x64U; __auto_type bv = cn_init_1684;
__auto_type cn_init_1692 = rg[0]; __auto_type av = cn_init_1692;
__auto_type cn_init_1710 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1710;
}
if(cn_cond(fl,14)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=25);
continue;
}
(b=24);
}
break;
case 24:
{
{
__auto_type cn_init_1758 = 0x64U; __auto_type v = cn_init_1758;
(rg[0]=v);
}
(b=25);
}
break;
case 25:
{
{
__auto_type cn_init_1783 = rg[0]; __auto_type bv = cn_init_1783;
__auto_type cn_init_1791 = rg[2]; __auto_type av = cn_init_1791;
__auto_type cn_init_1809 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1809;
}
if(cn_cond(fl,12)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=28);
continue;
}
(b=26);
}
break;
case 26:
{
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=40);
continue;
}
(b=27);
}
break;
case 27:
{
(steps+=1);
if((steps>limit)){
return 1;
}
(b=41);
continue;
}
break;
case 28:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffecU))));
(b=29);
}
break;
case 29:
{
{
__auto_type cn_init_1954 = 0x0U; __auto_type bv = cn_init_1954;
__auto_type cn_init_1962 = rg[0]; __auto_type av = cn_init_1962;
__auto_type cn_init_1980 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1980;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=31);
continue;
}
(b=30);
}
break;
case 30:
{
{
__auto_type cn_init_2028 = 0x0U; __auto_type v = cn_init_2028;
(rg[0]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=33);
continue;
}
break;
case 31:
{
{
__auto_type cn_init_2070 = 0x64U; __auto_type bv = cn_init_2070;
__auto_type cn_init_2078 = rg[0]; __auto_type av = cn_init_2078;
__auto_type cn_init_2096 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2096;
}
if(cn_cond(fl,14)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=33);
continue;
}
(b=32);
}
break;
case 32:
{
{
__auto_type cn_init_2144 = 0x64U; __auto_type v = cn_init_2144;
(rg[0]=v);
}
(b=33);
}
break;
case 33:
{
(rg[7]=cn_rd32u(m,((uint32_t)(rg[7]+0xfffffff0U))));
{
__auto_type cn_init_2186 = 0x1U; __auto_type bv = cn_init_2186;
__auto_type cn_init_2194 = rg[7]; __auto_type av = cn_init_2194;
__auto_type cn_init_2212 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2212;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=35);
continue;
}
(b=34);
}
break;
case 34:
{
{
__auto_type cn_init_2260 = 0x1U; __auto_type v = cn_init_2260;
(rg[7]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=37);
continue;
}
break;
case 35:
{
{
__auto_type cn_init_2302 = 0x6U; __auto_type bv = cn_init_2302;
__auto_type cn_init_2310 = rg[7]; __auto_type av = cn_init_2310;
__auto_type cn_init_2328 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2328;
}
if(cn_cond(fl,14)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=37);
continue;
}
(b=36);
}
break;
case 36:
{
{
__auto_type cn_init_2376 = 0x6U; __auto_type v = cn_init_2376;
(rg[7]=v);
}
(b=37);
}
break;
case 37:
{
(rg[7]=((uint32_t)((((uint32_t)(rg[6]+0x48U)))+((uint32_t)(rg[7]*4)))));
{
__auto_type cn_init_2428 = 0x0U; __auto_type bv = cn_init_2428;
__auto_type cn_init_2447 = cn_rd32(m,((uint32_t)(rg[7]+0x0U))); __auto_type av = cn_init_2447;
__auto_type cn_init_2465 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2465;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=39);
continue;
}
(b=38);
}
break;
case 38:
{
{
__auto_type cn_init_2513 = 0x80000000U; __auto_type bv = cn_init_2513;
__auto_type cn_init_2521 = rg[0]; __auto_type av = cn_init_2521;
__auto_type cn_init_2539 = cn_alu(&fl,Alu_Or,av,bv,4); __auto_type r = cn_init_2539;
(rg[0]=r);
}
(b=39);
}
break;
case 39:
{
{
__auto_type cn_init_2569 = ((uint32_t)(rg[7]+0x0U)); __auto_type a = cn_init_2569;
cn_wr32(m,a,rg[0]);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=42);
continue;
}
break;
case 40:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffe8U))));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=29);
continue;
}
break;
case 41:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffe4U))));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=29);
continue;
}
break;
case 42:
{
{
__auto_type cn_init_2720 = cn_pop_lu(m,rg); __auto_type v = cn_init_2720;
(rg[7]=v);
}
{
__auto_type cn_init_2741 = cn_pop_lu(m,rg); __auto_type v = cn_init_2741;
(rg[6]=v);
}
{
__auto_type cn_init_2762 = cn_pop_lu(m,rg); __auto_type v = cn_init_2762;
(rg[2]=v);
}
{
__auto_type cn_init_2783 = cn_pop_lu(m,rg); __auto_type v = cn_init_2783;
(rg[0]=v);
}
{
__auto_type cn_init_2804 = cn_pop_lu(m,rg); __auto_type v = cn_init_2804;
(rg[5]=v);
}
__auto_type cn_init_2824 = cn_pop_lu(m,rg); __auto_type r = cn_init_2824;
(rg[ESP]=((uint32_t)(rg[ESP]+8)));
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
break;
default:
return 1;
break;
}
}
}
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_2afaa6e446c39604(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+96))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001078U); uint64_t r15 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_240;
__auto_type cn_init_253 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,0); uint64_t v12 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,8); uint64_t v13 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,16); uint64_t v14 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,24); uint64_t v15 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,32); uint64_t v16 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,40); uint64_t v17 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,48); uint64_t v18 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,56); uint64_t v19 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,64); uint64_t v20 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,72); uint64_t v21 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,80); uint64_t v22 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,88); uint64_t v23 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,96); uint64_t v24 = cn_init_422;
__auto_type cn_init_435 = cn_cell(vm,104); uint64_t v25 = cn_init_435;
__auto_type cn_init_448 = cn_cell(vm,112); uint64_t v26 = cn_init_448;
__auto_type cn_init_461 = cn_cell(vm,120); uint64_t v27 = cn_init_461;
__auto_type cn_init_474 = cn_cell(vm,128); uint64_t v28 = cn_init_474;
__auto_type cn_init_487 = cn_cell(vm,136); uint64_t v29 = cn_init_487;
__auto_type cn_init_500 = cn_cell(vm,144); uint64_t v30 = cn_init_500;
__auto_type cn_init_513 = cn_cell(vm,160); uint64_t v32 = cn_init_513;
{
{
{
{
{
{
{
{
__auto_type cn_init_540 = 0xffffffccU; __auto_type bv = cn_init_540;
__auto_type cn_init_548 = rg[4]; __auto_type av = cn_init_548;
__auto_type cn_init_566 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_566;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_595 = r5; uint64_t s = cn_init_595;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_625 = (CN_U2){v28,v29}; CN_U2 s = cn_init_625;
__auto_type cn_init_635 = m->xmm[0]; __auto_type a = cn_init_635;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_705 = v28; uint64_t s = cn_init_705;
__auto_type cn_init_718 = m->xmm[1][0]; __auto_type a = cn_init_718;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_765 = (CN_U2){v24,v25}; CN_U2 s = cn_init_765;
__auto_type cn_init_775 = m->xmm[0]; __auto_type a = cn_init_775;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_845 = v26; uint64_t s = cn_init_845;
__auto_type cn_init_858 = m->xmm[1][0]; __auto_type a = cn_init_858;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_895 = 0x0U; __auto_type bv = cn_init_895;
__auto_type cn_init_912 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_912;
__auto_type cn_init_930 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_930;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_951 = r32; uint64_t s = cn_init_951;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_973 = v28; uint64_t s = cn_init_973;
__auto_type cn_init_986 = m->xmm[5][0]; __auto_type a = cn_init_986;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(s2009=m->xmm[0][0]);
(s2010=m->xmm[0][1]);
(s2011=m->xmm[1][0]);
(f[0]=cn_double(s2011));
(f[1]=cn_double(s2010));
(f[2]=cn_double(s2009));
(f[3]=f[2]);
{
__auto_type cn_init_1173 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1173;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1221 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1221;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1284 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1284;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1347 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1347;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1395 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1395;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1458 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1458;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1520 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1520;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1567 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1567;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1629 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1629;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(s2009=cn_bits(f[2]));
(s2010=cn_bits(f[1]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(s2011));
{
__auto_type cn_init_1713 = cn_double(v32); __auto_type v = cn_init_1713;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1751 = cn_double(v32); __auto_type v = cn_init_1751;
(f[0]=(f[0]-v));
}
(r14=cn_bits(f[0]));
(f[0]=cn_double(s2011));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]-f[1]));
(f[1]=cn_double(v12));
cn_swap(f,1,0);
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_1905_0 = f[2];
__auto_type cn_tuple_1905_1 = f[1];
__auto_type x = cn_tuple_1905_0;
__auto_type y = cn_tuple_1905_1;
__auto_type cn_init_1934 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1934;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1966 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1966;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
(f[0]=-f[0]);
(s2011=cn_bits(f[0]));
(f[1]=cn_double(v13));
cn_swap(f,1,0);
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_2198_0 = f[2];
__auto_type cn_tuple_2198_1 = f[1];
__auto_type x = cn_tuple_2198_0;
__auto_type y = cn_tuple_2198_1;
__auto_type cn_init_2227 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_2227;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_2259 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_2259;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
{
__auto_type cn_init_2389 = cn_double(v16); __auto_type v = cn_init_2389;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_2419_0 = sin(f[0]);
__auto_type cn_tuple_2419_1 = cos(f[0]);
__auto_type s = cn_tuple_2419_0;
__auto_type c = cn_tuple_2419_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2013=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_2484 = cn_double(s2012); __auto_type v = cn_init_2484;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2010));
{
__auto_type cn_init_2520 = cn_double(s2013); __auto_type v = cn_init_2520;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2009));
{
__auto_type cn_init_2597 = cn_double(s2013); __auto_type v = cn_init_2597;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2010));
{
__auto_type cn_init_2633 = cn_double(s2012); __auto_type v = cn_init_2633;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(s2011));
{
__auto_type cn_init_2684 = cn_double(v15); __auto_type v = cn_init_2684;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(v16));
(f[1]=fabs(f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
(f[1]=f[1]);
goto cn_break_b5;
}
cn_break_b4:;
(f[1]=sqrt(f[1]));
(f[0]=(f[0]/f[1]));
}
cn_break_b5:;
(f[1]=cn_double(s2011));
{
__auto_type cn_init_2931 = cn_double(v14); __auto_type v = cn_init_2931;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r14));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b7;
}
(f[1]=f[1]);
goto cn_break_b8;
}
cn_break_b7:;
(f[0]=f[1]);
}
cn_break_b8:;
{
__auto_type cn_init_3072 = 0x0U; __auto_type bv = cn_init_3072;
__auto_type cn_init_3089 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_3089;
__auto_type cn_init_3107 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3107;
}
if(cn_cond(fl,5)){
goto cn_break_b10;
}
{
__auto_type cn_init_3131 = cn_double(v28); __auto_type v = cn_init_3131;
(f[0]=(f[0]/v));
}
}
cn_break_b10:;
(r14=cn_bits(f[0]));
(f[0]=cn_double(v30));
(f[1]=(((double)(((int32_t)(((uint32_t)(((((r15>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_3218 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3218;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(r34=cn_bits(f[0]));
{
__auto_type cn_init_3277 = 0x34U; __auto_type bv = cn_init_3277;
__auto_type cn_init_3285 = rg[4]; __auto_type av = cn_init_3285;
__auto_type cn_init_3303 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3303;
(rg[4]=r);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10001070U,r14);
cn_wr64u(m,0x10001100U,r32);
cn_wr64u(m,0x10001110U,r34);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_2ce52f975c89786f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+144))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,0); uint64_t v18 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,8); uint64_t v19 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,16); uint64_t v20 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,24); uint64_t v21 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,32); uint64_t v22 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,40); uint64_t v23 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,48); uint64_t v24 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,56); uint64_t v25 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,64); uint64_t v26 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,72); uint64_t v27 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,80); uint64_t v28 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,88); uint64_t v29 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,96); uint64_t v30 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,112); uint64_t v32 = cn_init_422;
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
__auto_type cn_init_497 = 0xffffffbaU; __auto_type bv = cn_init_497;
__auto_type cn_init_505 = rg[4]; __auto_type av = cn_init_505;
__auto_type cn_init_523 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_523;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_552 = r5; uint64_t s = cn_init_552;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_582 = (CN_U2){v28,v29}; CN_U2 s = cn_init_582;
__auto_type cn_init_592 = m->xmm[0]; __auto_type a = cn_init_592;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_662 = v28; uint64_t s = cn_init_662;
__auto_type cn_init_675 = m->xmm[1][0]; __auto_type a = cn_init_675;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_722 = (CN_U2){v24,v25}; CN_U2 s = cn_init_722;
__auto_type cn_init_732 = m->xmm[0]; __auto_type a = cn_init_732;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_802 = v26; uint64_t s = cn_init_802;
__auto_type cn_init_815 = m->xmm[1][0]; __auto_type a = cn_init_815;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_852 = 0x0U; __auto_type bv = cn_init_852;
__auto_type cn_init_869 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_869;
__auto_type cn_init_887 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_887;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_908 = r32; uint64_t s = cn_init_908;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_930 = v28; uint64_t s = cn_init_930;
__auto_type cn_init_943 = m->xmm[5][0]; __auto_type a = cn_init_943;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1039 = m->xmm[0][0]; uint64_t v = cn_init_1039;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1098 = m->xmm[0][1]; uint64_t v = cn_init_1098;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1157 = m->xmm[1][0]; uint64_t v = cn_init_1157;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(0x0));
{
__auto_type cn_init_1227 = cn_bits(f[0]); uint64_t v = cn_init_1227;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1285 = cn_bits(f[0]); uint64_t v = cn_init_1285;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1334 = 0xffffffd4U; __auto_type bv = cn_init_1334;
__auto_type cn_init_1342 = rg[7]; __auto_type av = cn_init_1342;
__auto_type cn_init_1360 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1360;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1487 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1487;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1535 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1535;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1598 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1598;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1661 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1661;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1709 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1709;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1772 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1772;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1834 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1834;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1881 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1881;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1943 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1943;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1986 = cn_bits(f[2]); uint64_t v = cn_init_1986;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_2044 = cn_bits(f[1]); uint64_t v = cn_init_2044;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_2102 = cn_bits(f[0]); uint64_t v = cn_init_2102;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_2151 = 0x2cU; __auto_type bv = cn_init_2151;
__auto_type cn_init_2159 = rg[7]; __auto_type av = cn_init_2159;
__auto_type cn_init_2177 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2177;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2240 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2240;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2280 = cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2280;
(f[0]=(f[0]*v));
}
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
{
__auto_type cn_init_2387 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2387;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_2415 = cn_bits(f[0]); uint64_t v = cn_init_2415;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
goto cn_break_b5;
}
cn_break_b4:;
{
__auto_type cn_init_2489 = cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2489;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2517 = cn_bits(f[0]); uint64_t v = cn_init_2517;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b5:;
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2616 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2616;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2656 = cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2656;
(f[0]=(f[0]*v));
}
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b7;
}
{
__auto_type cn_init_2763 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2763;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_2791 = cn_bits(f[0]); uint64_t v = cn_init_2791;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
goto cn_break_b8;
}
cn_break_b7:;
{
__auto_type cn_init_2865 = cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2865;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2893 = cn_bits(f[0]); uint64_t v = cn_init_2893;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b8:;
(f[0]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2992 = cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2992;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3032 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3032;
(f[0]=(f[0]*v));
}
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b10;
}
{
__auto_type cn_init_3139 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3139;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_3167 = cn_bits(f[0]); uint64_t v = cn_init_3167;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
goto cn_break_b11;
}
cn_break_b10:;
{
__auto_type cn_init_3241 = cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3241;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3269 = cn_bits(f[0]); uint64_t v = cn_init_3269;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b11:;
(f[0]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3368 = cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3368;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3408 = cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3408;
(f[0]=(f[0]*v));
}
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b13;
}
{
__auto_type cn_init_3515 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3515;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_3543 = cn_bits(f[0]); uint64_t v = cn_init_3543;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
goto cn_break_b14;
}
cn_break_b13:;
{
__auto_type cn_init_3617 = cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3617;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3645 = cn_bits(f[0]); uint64_t v = cn_init_3645;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b14:;
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3744 = cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3744;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3784 = cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3784;
(f[0]=(f[0]*v));
}
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b16;
}
{
__auto_type cn_init_3891 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3891;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_3919 = cn_bits(f[0]); uint64_t v = cn_init_3919;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
goto cn_break_b17;
}
cn_break_b16:;
{
__auto_type cn_init_3993 = cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3993;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_4021 = cn_bits(f[0]); uint64_t v = cn_init_4021;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b17:;
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4120 = cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4120;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4160 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4160;
(f[0]=(f[0]*v));
}
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b19;
}
{
__auto_type cn_init_4267 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4267;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_4295 = cn_bits(f[0]); uint64_t v = cn_init_4295;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
goto cn_break_b20;
}
cn_break_b19:;
{
__auto_type cn_init_4369 = cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4369;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_4397 = cn_bits(f[0]); uint64_t v = cn_init_4397;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b20:;
(f[0]=cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4480 = cn_double(v23); __auto_type v = cn_init_4480;
(f[0]=(f[0]*v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_4522 = cn_bits(f[0]); uint64_t v = cn_init_4522;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4604 = cn_double(v23); __auto_type v = cn_init_4604;
(f[0]=(f[0]*v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_4646 = cn_bits(f[0]); uint64_t v = cn_init_4646;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4744 = cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4744;
(f[0]=(f[0]*v));
}
(f[0]=(f[0]+f[0]));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b22;
}
{
__auto_type cn_init_4866 = cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4866;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_4894 = cn_bits(f[0]); uint64_t v = cn_init_4894;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
goto cn_break_b23;
}
cn_break_b22:;
{
__auto_type cn_init_4968 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4968;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_4996 = cn_bits(f[0]); uint64_t v = cn_init_4996;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b23:;
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5095 = cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5095;
(f[0]=(f[0]*v));
}
(f[0]=(f[0]+f[0]));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b25;
}
{
__auto_type cn_init_5217 = cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5217;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_5245 = cn_bits(f[0]); uint64_t v = cn_init_5245;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
goto cn_break_b26;
}
cn_break_b25:;
{
__auto_type cn_init_5319 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5319;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_5347 = cn_bits(f[0]); uint64_t v = cn_init_5347;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b26:;
(f[0]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5446 = cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5446;
(f[0]=(f[0]*v));
}
(f[0]=(f[0]+f[0]));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b28;
}
{
__auto_type cn_init_5568 = cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5568;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_5596 = cn_bits(f[0]); uint64_t v = cn_init_5596;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
goto cn_break_b29;
}
cn_break_b28:;
{
__auto_type cn_init_5670 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5670;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_5698 = cn_bits(f[0]); uint64_t v = cn_init_5698;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b29:;
(f[0]=cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))));
(f[0]=sqrt(f[0]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))));
(f[1]=sqrt(f[1]));
(f[1]=sqrt(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_5891 = cn_double(v32); __auto_type v = cn_init_5891;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_6088 = cn_double(v30); __auto_type v = cn_init_6088;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b31;
}
(f[1]=f[1]);
goto cn_break_b32;
}
cn_break_b31:;
(f[0]=f[1]);
}
cn_break_b32:;
{
__auto_type cn_init_6202 = 0x0U; __auto_type bv = cn_init_6202;
__auto_type cn_init_6219 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_6219;
__auto_type cn_init_6237 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_6237;
}
if(cn_cond(fl,5)){
goto cn_break_b34;
}
{
__auto_type cn_init_6261 = cn_double(v28); __auto_type v = cn_init_6261;
(f[0]=(f[0]/v));
}
}
cn_break_b34:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_6292 = 0x46U; __auto_type bv = cn_init_6292;
__auto_type cn_init_6300 = rg[4]; __auto_type av = cn_init_6300;
__auto_type cn_init_6318 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_6318;
(rg[4]=r);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10001070U,r14);
cn_wr64u(m,0x10001100U,r32);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_2d0eb4e6f078b385(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+232))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_242;
__auto_type cn_init_255 = cn_cell(vm,0); uint64_t v29 = cn_init_255;
__auto_type cn_init_268 = cn_cell(vm,8); uint64_t v30 = cn_init_268;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_583 = cn_double(r5); __auto_type v = cn_init_583;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_607 = cn_double(v30); __auto_type v = cn_init_607;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_631 = cn_double(r10); __auto_type v = cn_init_631;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_724 = cn_double(v29); __auto_type v = cn_init_724;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_748 = cn_double(r11); __auto_type v = cn_init_748;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r4));
{
__auto_type cn_init_784 = cn_double(r12); __auto_type v = cn_init_784;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(f[7]=f[7]);
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s2012>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2012>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[0]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
