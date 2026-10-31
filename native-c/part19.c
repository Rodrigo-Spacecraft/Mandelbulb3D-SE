/* Generated native C formula calculations. See tools/generate-native-c.py. */
#include "runtime.h"
int cn_f_747c6c9d1edf0d4e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+224))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_178;
__auto_type cn_init_191 = cn_cell(vm,0); uint64_t v28 = cn_init_191;
__auto_type cn_init_204 = cn_cell(vm,8); uint64_t v29 = cn_init_204;
__auto_type cn_init_217 = cn_cell(vm,16); uint64_t v30 = cn_init_217;
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
(f[0]=cn_double(r3));
(f[0]=fabs(f[0]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_409 = cn_double(v30); __auto_type v = cn_init_409;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_433 = cn_double(r3); __auto_type v = cn_init_433;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=fabs(f[0]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_508 = cn_double(v29); __auto_type v = cn_init_508;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_532 = cn_double(r4); __auto_type v = cn_init_532;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=fabs(f[0]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_607 = cn_double(v28); __auto_type v = cn_init_607;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_631 = cn_double(r5); __auto_type v = cn_init_631;
(f[0]=(f[0]+v));
}
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
int cn_f_8727bafba736d17a(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_24 = m->regs; __auto_type rg = cn_init_24;
__auto_type cn_init_32 = m->fl; __auto_type fl = cn_init_32;
__auto_type cn_init_40 = m->fsw_cc; __auto_type fsw = cn_init_40;
__auto_type cn_init_53 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_53;
__auto_type cn_init_73 = cn_ptr(m,((uint32_t)(vb+168))); unsigned char * vm = cn_init_73;
__auto_type cn_init_86 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_86;
__auto_type cn_init_99 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_99;
__auto_type cn_init_112 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_112;
__auto_type cn_init_125 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_125;
__auto_type cn_init_138 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_138;
__auto_type cn_init_151 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_151;
__auto_type cn_init_164 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_164;
__auto_type cn_init_177 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_177;
__auto_type cn_init_190 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_268;
__auto_type cn_init_281 = cn_cell(vm,0); uint64_t v21 = cn_init_281;
__auto_type cn_init_294 = cn_cell(vm,8); uint64_t v22 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,16); uint64_t v23 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,24); uint64_t v24 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,32); uint64_t v25 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,40); uint64_t v26 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,48); uint64_t v27 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,56); uint64_t v28 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,64); uint64_t v29 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,72); uint64_t v30 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,88); uint64_t v32 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,104); uint64_t v34 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,112); uint64_t v35 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,120); uint64_t v36 = cn_init_450;
__auto_type cn_init_463 = cn_cell(vm,128); uint64_t v37 = cn_init_463;
__auto_type cn_init_476 = cn_cell(vm,136); uint64_t v38 = cn_init_476;
{
{
{
{
{
__auto_type cn_init_494 = 0xffffffbaU; __auto_type bv = cn_init_494;
__auto_type cn_init_502 = rg[4]; __auto_type av = cn_init_502;
__auto_type cn_init_520 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_520;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_549 = r5; uint64_t s = cn_init_549;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_579 = (CN_U2){v28,v29}; CN_U2 s = cn_init_579;
__auto_type cn_init_589 = m->xmm[0]; __auto_type a = cn_init_589;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_659 = v28; uint64_t s = cn_init_659;
__auto_type cn_init_672 = m->xmm[1][0]; __auto_type a = cn_init_672;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_719 = (CN_U2){v24,v25}; CN_U2 s = cn_init_719;
__auto_type cn_init_729 = m->xmm[0]; __auto_type a = cn_init_729;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_799 = v26; uint64_t s = cn_init_799;
__auto_type cn_init_812 = m->xmm[1][0]; __auto_type a = cn_init_812;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_866 = 0x1U; __auto_type bv = cn_init_866;
__auto_type cn_init_874 = rg[2]; __auto_type av = cn_init_874;
__auto_type cn_init_892 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_892;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_920 = r32; uint64_t s = cn_init_920;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_942 = v28; uint64_t s = cn_init_942;
__auto_type cn_init_955 = m->xmm[5][0]; __auto_type a = cn_init_955;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1051 = m->xmm[0][0]; uint64_t v = cn_init_1051;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1110 = m->xmm[0][1]; uint64_t v = cn_init_1110;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1169 = m->xmm[1][0]; uint64_t v = cn_init_1169;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1396 = cn_double(v30); __auto_type v = cn_init_1396;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1464 = 0x41U; __auto_type bv = cn_init_1464;
__auto_type cn_init_1477 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1477;
__auto_type cn_init_1495 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1495;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
(f[0]=f[0]);
(f[0]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1586 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1586;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1613 = cn_round(m,f[0]); __auto_type x = cn_init_1613;
__auto_type cn_init_1648 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_1648;
{
__auto_type cn_init_1658 = ((uint64_t)(i)); uint64_t v = cn_init_1658;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_1732 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_1732;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_1811 = cn_double(v32); __auto_type v = cn_init_1811;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1854 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_1854;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1894 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1894;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1922 = cn_bits(f[0]); uint64_t v = cn_init_1922;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2004 = cn_double(v38); __auto_type v = cn_init_2004;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2044 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2044;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2072 = cn_bits(f[0]); uint64_t v = cn_init_2072;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2170 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2170;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2198 = cn_bits(f[0]); uint64_t v = cn_init_2198;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2296 = cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2296;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2323 = cn_round(m,f[0]); __auto_type x = cn_init_2323;
__auto_type cn_init_2358 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2358;
{
__auto_type cn_init_2368 = ((uint64_t)(i)); uint64_t v = cn_init_2368;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_2442 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_2442;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2521 = cn_double(v32); __auto_type v = cn_init_2521;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2564 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_2564;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2592 = cn_bits(f[0]); uint64_t v = cn_init_2592;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2690 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2690;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2717 = cn_round(m,f[0]); __auto_type x = cn_init_2717;
__auto_type cn_init_2752 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2752;
{
__auto_type cn_init_2762 = ((uint64_t)(i)); uint64_t v = cn_init_2762;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_2836 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_2836;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2915 = cn_double(v32); __auto_type v = cn_init_2915;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2958 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_2958;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2998 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2998;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3022 = cn_double(v35); __auto_type v = cn_init_3022;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3049 = cn_round(m,f[0]); __auto_type x = cn_init_3049;
__auto_type cn_init_3084 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3084;
{
__auto_type cn_init_3094 = ((uint64_t)(i)); uint64_t v = cn_init_3094;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_3168 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3168;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3247 = cn_double(v32); __auto_type v = cn_init_3247;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3290 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3290;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3318 = cn_bits(f[0]); uint64_t v = cn_init_3318;
(s2011=(((s2011&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2012=(((s2012&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=-f[0]);
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]+f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_3456 = cn_round(m,f[1]); __auto_type x = cn_init_3456;
__auto_type cn_init_3491 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3491;
{
__auto_type cn_init_3501 = ((uint64_t)(i)); uint64_t v = cn_init_3501;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_3575 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3575;
(f[1]=(f[1]-v));
}
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_3654 = cn_double(v32); __auto_type v = cn_init_3654;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3697 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3697;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_3737 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3737;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_3761 = cn_double(v35); __auto_type v = cn_init_3761;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3788 = cn_round(m,f[1]); __auto_type x = cn_init_3788;
__auto_type cn_init_3823 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3823;
{
__auto_type cn_init_3833 = ((uint64_t)(i)); uint64_t v = cn_init_3833;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_3907 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3907;
(f[1]=(f[1]-v));
}
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_3986 = cn_double(v32); __auto_type v = cn_init_3986;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4029 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_4029;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_4072 = cn_bits(f[0]); uint64_t v = cn_init_4072;
(s2012=(((s2012&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2013=(((s2013&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[1]=cn_double(((((((s2011>>48))|((s2012<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4154 = cn_double(v36); __auto_type v = cn_init_4154;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4194 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4194;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4222 = cn_bits(f[1]); uint64_t v = cn_init_4222;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[1]=cn_double(((((((s2011>>48))|((s2012<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4304 = cn_double(v34); __auto_type v = cn_init_4304;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_4343 = cn_double(v37); __auto_type v = cn_init_4343;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4383 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4383;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4411 = cn_bits(f[0]); uint64_t v = cn_init_4411;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_4638 = cn_double(v30); __auto_type v = cn_init_4638;
(f[0]=(f[0]-v));
}
}
cn_break_b4:;
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_4675 = 0x1U; __auto_type bv = cn_init_4675;
__auto_type cn_init_4683 = rg[2]; __auto_type av = cn_init_4683;
__auto_type cn_init_4701 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_4701;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
{
__auto_type cn_init_4732 = cn_double(v28); __auto_type v = cn_init_4732;
(f[0]=(f[0]/v));
}
}
cn_break_b6:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_4763 = 0x46U; __auto_type bv = cn_init_4763;
__auto_type cn_init_4771 = rg[4]; __auto_type av = cn_init_4771;
__auto_type cn_init_4789 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_4789;
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
cn_wr64u(m,0x10007ee8U,s2013);
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_89f03bb8be527f08(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;
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
__auto_type cn_init_104 = 0x8U; __auto_type bv = cn_init_104;
__auto_type cn_init_112 = rg[4]; __auto_type av = cn_init_112;
__auto_type cn_init_130 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_130;
(rg[4]=r);
}
(rg[2]=cn_rd32u(m,((uint32_t)(rg[5]+0x8U))));
{
__auto_type cn_init_164 = 0x38U; __auto_type bv = cn_init_164;
__auto_type cn_init_172 = rg[2]; __auto_type av = cn_init_172;
__auto_type cn_init_190 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_190;
(rg[2]=r);
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[2]+0x68U))));
(f[0]=cn_rdf64u(m,((uint32_t)(rg[2]+0x18U))));
(f[1]=cn_rdf64u(m,((uint32_t)(rg[2]+0x20U))));
(f[2]=cn_rdf64u(m,((uint32_t)(rg[0]+0xffffffe4U))));
(f[3]=f[0]);
(f[4]=cn_rdf64u(m,((uint32_t)(rg[2]+0x28U))));
cn_swap(f,4,2);
{
__auto_type cn_init_331 = ((uint32_t)(rg[5]+0xfffffff8U)); __auto_type a = cn_init_331;
cn_wrf64u(m,a,f[4]);
}
(f[4]=f[1]);
cn_swap(f,4,3);
(f[4]=(f[4]*f[0]));
cn_swap(f,4,3);
(f[4]=(f[4]*f[1]));
(rg[1]=((uint32_t)(rg[0]+0xfffffff4U)));
(f[5]=cn_rdf64u(m,((uint32_t)(rg[0]+0xffffffdcU))));
cn_swap(f,5,3);
(f[4]=(f[4]+f[5]));
(f[5]=f[2]);
(rg[0]=cn_rd32u(m,((uint32_t)(rg[0]+0xfffffff4U))));
(f[5]=(f[5]*f[2]));
{
__auto_type cn_init_515 = rg[0]; __auto_type bv = cn_init_515;
__auto_type cn_init_523 = rg[0]; __auto_type av = cn_init_523;
cn_alu(&fl,Alu_And,av,bv,4);
}
(f[4]=(f[4]+f[5]));
(f[4]=sqrt(f[4]));
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=8);
continue;
}
(b=1);
}
break;
case 1:
{
(f[5]=cn_double(0x3ff0000000000000));
(f[6]=f[5]);
(f[6]=(f[6]/f[4]));
(f[0]=(f[0]*f[6]));
(f[1]=(f[1]*f[6]));
(b=2);
}
break;
case 2:
{
(f[6]=f[5]);
(rg[0]=cn_rd32u(m,((uint32_t)(rg[1]+0xfffffffcU))));
(f[6]=(f[6]/f[4]));
{
__auto_type cn_init_738 = rg[0]; __auto_type bv = cn_init_738;
__auto_type cn_init_746 = rg[0]; __auto_type av = cn_init_746;
cn_alu(&fl,Alu_And,av,bv,4);
}
(f[2]=(f[2]*f[6]));
cn_swap(f,5,2);
(f[5]=(f[5]+f[3]));
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
(f[5]=(f[5]*f[5]));
cn_swap(f,5,3);
(f[5]=(f[5]*f[5]));
cn_swap(f,5,3);
(b=4);
}
break;
case 4:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[1]+0xfffffff8U))));
(f[6]=f[5]);
{
__auto_type cn_init_937 = rg[0]; __auto_type bv = cn_init_937;
__auto_type cn_init_945 = rg[0]; __auto_type av = cn_init_945;
cn_alu(&fl,Alu_And,av,bv,4);
}
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=6);
continue;
}
(b=5);
}
break;
case 5:
{
(f[6]=f[6]);
(f[6]=cn_double(0x3ff0000000000000));
(f[5]=(f[6]/f[5]));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=7);
continue;
}
break;
case 6:
{
(f[5]=f[6]);
(b=7);
}
break;
case 7:
{
(f[0]=(f[0]*f[5]));
(f[1]=(f[1]*f[5]));
(f[5]=f[0]);
(f[6]=f[1]);
(f[6]=(f[6]*f[1]));
cn_swap(f,6,5);
(f[6]=(f[6]*f[0]));
cn_swap(f,6,1);
(f[0]=(f[0]*f[6]));
(f[1]=(f[1]-f[5]));
cn_swap(f,4,0);
(f[4]=(f[4]+f[4]));
(f[5]=f[3]);
(f[6]=f[4]);
(f[7]=f[1]);
cn_swap(f,7,5);
(f[3]=(f[3]*f[7]));
(f[6]=(f[6]*f[4]));
cn_swap(f,6,5);
(f[6]=(f[6]*f[1]));
cn_swap(f,6,3);
(f[6]=(f[6]+f[2]));
cn_swap(f,6,3);
(f[5]=(f[5]+f[6]));
cn_swap(f,5,3);
{
__auto_type cn_init_1406 = cn_rdf64u(m,((uint32_t)(rg[5]+0xfffffff8U))); __auto_type v = cn_init_1406;
(f[5]=(f[5]*v));
}
(f[6]=f[3]);
(f[6]=(f[6]-f[2]));
cn_swap(f,6,3);
(f[2]=(f[2]+f[6]));
cn_swap(f,5,2);
(f[6]=cn_double(0x3ff0000000000000));
(f[5]=(f[6]/f[5]));
(f[2]=(f[2]*f[5]));
(f[3]=(f[3]*f[5]));
(f[5]=f[0]);
cn_swap(f,5,4);
(f[5]=(f[5]*f[2]));
cn_swap(f,5,4);
(f[0]=(f[0]*f[5]));
cn_swap(f,4,2);
(f[1]=(f[1]*f[4]));
cn_swap(f,3,1);
(f[3]=(f[3]*f[0]));
cn_swap(f,3,2);
(f[3]=(f[3]*f[0]));
cn_swap(f,3,1);
(f[0]=(f[0]*f[3]));
{
__auto_type cn_init_1707 = cn_rdf64u(m,((uint32_t)(rg[2]+0x50U))); __auto_type v = cn_init_1707;
(f[2]=(f[2]+v));
}
cn_swap(f,2,1);
{
__auto_type cn_init_1748 = cn_rdf64u(m,((uint32_t)(rg[2]+0x58U))); __auto_type v = cn_init_1748;
(f[2]=(f[2]+v));
}
cn_swap(f,2,0);
{
__auto_type cn_init_1789 = cn_rdf64u(m,((uint32_t)(rg[2]+0x60U))); __auto_type v = cn_init_1789;
(f[2]=(f[2]+v));
}
cn_swap(f,2,1);
{
__auto_type cn_init_1825 = ((uint32_t)(rg[2]+0x18U)); __auto_type a = cn_init_1825;
cn_wrf64u(m,a,f[2]);
}
cn_swap(f,1,0);
{
__auto_type cn_init_1861 = ((uint32_t)(rg[2]+0x20U)); __auto_type a = cn_init_1861;
cn_wrf64u(m,a,f[1]);
}
{
__auto_type cn_init_1888 = ((uint32_t)(rg[2]+0x28U)); __auto_type a = cn_init_1888;
cn_wrf64u(m,a,f[0]);
}
(rg[4]=rg[5]);
(rg[5]=cn_pop_lu(m,rg));
__auto_type cn_init_1937 = cn_pop_lu(m,rg); __auto_type r = cn_init_1937;
(rg[ESP]=((uint32_t)(rg[ESP]+8)));
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
break;
case 8:
{
(f[5]=cn_double(0x3ff0000000000000));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=2);
continue;
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
int cn_f_8a7908c7e72f01c6(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+216))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v27 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,8); uint64_t v28 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,16); uint64_t v29 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,24); uint64_t v30 = cn_init_247;
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
(f[0]=cn_double(r3));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_425 = cn_double(v30); __auto_type v = cn_init_425;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_486 = cn_double(v29); __auto_type v = cn_init_486;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_547 = cn_double(v28); __auto_type v = cn_init_547;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_608 = cn_double(v27); __auto_type v = cn_init_608;
(f[0]=(f[0]+v));
}
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
int cn_f_8fc38030eb046ba1(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_24 = m->regs; __auto_type rg = cn_init_24;
__auto_type cn_init_32 = m->fl; __auto_type fl = cn_init_32;
__auto_type cn_init_40 = m->fsw_cc; __auto_type fsw = cn_init_40;
__auto_type cn_init_53 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_53;
__auto_type cn_init_73 = cn_ptr(m,((uint32_t)(vb+80))); unsigned char * vm = cn_init_73;
__auto_type cn_init_86 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_86;
__auto_type cn_init_99 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_99;
__auto_type cn_init_112 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_112;
__auto_type cn_init_125 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_125;
__auto_type cn_init_138 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_138;
__auto_type cn_init_151 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_151;
__auto_type cn_init_164 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_164;
__auto_type cn_init_177 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_177;
__auto_type cn_init_190 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_268;
__auto_type cn_init_281 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_281;
__auto_type cn_init_294 = cn_cell(vm,0); uint64_t v10 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,8); uint64_t v11 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,16); uint64_t v12 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,24); uint64_t v13 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,32); uint64_t v14 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,40); uint64_t v15 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,48); uint64_t v16 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,56); uint64_t v17 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,64); uint64_t v18 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,72); uint64_t v19 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,80); uint64_t v20 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,88); uint64_t v21 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,96); uint64_t v22 = cn_init_450;
__auto_type cn_init_463 = cn_cell(vm,104); uint64_t v23 = cn_init_463;
__auto_type cn_init_476 = cn_cell(vm,112); uint64_t v24 = cn_init_476;
__auto_type cn_init_489 = cn_cell(vm,120); uint64_t v25 = cn_init_489;
__auto_type cn_init_502 = cn_cell(vm,128); uint64_t v26 = cn_init_502;
__auto_type cn_init_515 = cn_cell(vm,136); uint64_t v27 = cn_init_515;
__auto_type cn_init_528 = cn_cell(vm,144); uint64_t v28 = cn_init_528;
__auto_type cn_init_541 = cn_cell(vm,152); uint64_t v29 = cn_init_541;
__auto_type cn_init_554 = cn_cell(vm,160); uint64_t v30 = cn_init_554;
__auto_type cn_init_567 = cn_cell(vm,176); uint64_t v32 = cn_init_567;
__auto_type cn_init_580 = cn_cell(vm,192); uint64_t v34 = cn_init_580;
__auto_type cn_init_593 = cn_cell(vm,200); uint64_t v35 = cn_init_593;
__auto_type cn_init_606 = cn_cell(vm,208); uint64_t v36 = cn_init_606;
__auto_type cn_init_619 = cn_cell(vm,216); uint64_t v37 = cn_init_619;
__auto_type cn_init_632 = cn_cell(vm,224); uint64_t v38 = cn_init_632;
{
{
{
{
{
{
__auto_type cn_init_653 = 0xffffffbaU; __auto_type bv = cn_init_653;
__auto_type cn_init_661 = rg[4]; __auto_type av = cn_init_661;
__auto_type cn_init_679 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_679;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_708 = r5; uint64_t s = cn_init_708;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_738 = (CN_U2){v28,v29}; CN_U2 s = cn_init_738;
__auto_type cn_init_748 = m->xmm[0]; __auto_type a = cn_init_748;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_818 = v28; uint64_t s = cn_init_818;
__auto_type cn_init_831 = m->xmm[1][0]; __auto_type a = cn_init_831;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_878 = (CN_U2){v24,v25}; CN_U2 s = cn_init_878;
__auto_type cn_init_888 = m->xmm[0]; __auto_type a = cn_init_888;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_958 = v26; uint64_t s = cn_init_958;
__auto_type cn_init_971 = m->xmm[1][0]; __auto_type a = cn_init_971;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1025 = 0x1U; __auto_type bv = cn_init_1025;
__auto_type cn_init_1033 = rg[2]; __auto_type av = cn_init_1033;
__auto_type cn_init_1051 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1051;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_1079 = r32; uint64_t s = cn_init_1079;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_1101 = v28; uint64_t s = cn_init_1101;
__auto_type cn_init_1114 = m->xmm[5][0]; __auto_type a = cn_init_1114;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1210 = m->xmm[0][0]; uint64_t v = cn_init_1210;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1269 = m->xmm[0][1]; uint64_t v = cn_init_1269;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1328 = m->xmm[1][0]; uint64_t v = cn_init_1328;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1490 = (((double)(cn_float(((uint32_t)(((((v12>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1490;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1538 = (((double)(cn_float(((uint32_t)(((((v12>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1538;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1601 = (((double)(cn_float(((uint32_t)(((((v11>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1601;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1664 = (((double)(cn_float(((uint32_t)(((((v15>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1664;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1712 = (((double)(cn_float(((uint32_t)(((((v15>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1712;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1775 = (((double)(cn_float(((uint32_t)(((((v14>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1775;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1837 = (((double)(cn_float(((uint32_t)(((((v14>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1837;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1884 = (((double)(cn_float(((uint32_t)(((((v13>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1884;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1946 = (((double)(cn_float(((uint32_t)(((((v13>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1946;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1989 = cn_bits(f[2]); uint64_t v = cn_init_1989;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_2047 = cn_bits(f[1]); uint64_t v = cn_init_2047;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_2105 = cn_bits(f[0]); uint64_t v = cn_init_2105;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2203 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2203;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2230 = cn_round(m,f[0]); __auto_type x = cn_init_2230;
__auto_type cn_init_2265 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2265;
{
__auto_type cn_init_2275 = ((uint64_t)(i)); uint64_t v = cn_init_2275;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_2349 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_2349;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2428 = cn_double(v32); __auto_type v = cn_init_2428;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2471 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_2471;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2511 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2511;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2539 = cn_bits(f[0]); uint64_t v = cn_init_2539;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2621 = cn_double(v38); __auto_type v = cn_init_2621;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2661 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2661;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2689 = cn_bits(f[0]); uint64_t v = cn_init_2689;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2787 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2787;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2815 = cn_bits(f[0]); uint64_t v = cn_init_2815;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2913 = cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2913;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2940 = cn_round(m,f[0]); __auto_type x = cn_init_2940;
__auto_type cn_init_2975 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2975;
{
__auto_type cn_init_2985 = ((uint64_t)(i)); uint64_t v = cn_init_2985;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_3059 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3059;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3138 = cn_double(v32); __auto_type v = cn_init_3138;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3181 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3181;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3209 = cn_bits(f[0]); uint64_t v = cn_init_3209;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3307 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3307;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_3334 = cn_round(m,f[0]); __auto_type x = cn_init_3334;
__auto_type cn_init_3369 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3369;
{
__auto_type cn_init_3379 = ((uint64_t)(i)); uint64_t v = cn_init_3379;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_3453 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3453;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3532 = cn_double(v32); __auto_type v = cn_init_3532;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3575 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3575;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3615 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3615;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3639 = cn_double(v35); __auto_type v = cn_init_3639;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3666 = cn_round(m,f[0]); __auto_type x = cn_init_3666;
__auto_type cn_init_3701 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3701;
{
__auto_type cn_init_3711 = ((uint64_t)(i)); uint64_t v = cn_init_3711;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_3785 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3785;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3864 = cn_double(v32); __auto_type v = cn_init_3864;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3907 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3907;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3935 = cn_bits(f[0]); uint64_t v = cn_init_3935;
(s2011=(((s2011&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2012=(((s2012&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=-f[0]);
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]+f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_4073 = cn_round(m,f[1]); __auto_type x = cn_init_4073;
__auto_type cn_init_4108 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_4108;
{
__auto_type cn_init_4118 = ((uint64_t)(i)); uint64_t v = cn_init_4118;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_4192 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_4192;
(f[1]=(f[1]-v));
}
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_4271 = cn_double(v32); __auto_type v = cn_init_4271;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4314 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_4314;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_4354 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4354;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_4378 = cn_double(v35); __auto_type v = cn_init_4378;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4405 = cn_round(m,f[1]); __auto_type x = cn_init_4405;
__auto_type cn_init_4440 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_4440;
{
__auto_type cn_init_4450 = ((uint64_t)(i)); uint64_t v = cn_init_4450;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_4524 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_4524;
(f[1]=(f[1]-v));
}
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_4603 = cn_double(v32); __auto_type v = cn_init_4603;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4646 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_4646;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_4689 = cn_bits(f[0]); uint64_t v = cn_init_4689;
(s2012=(((s2012&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2013=(((s2013&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[1]=cn_double(((((((s2011>>48))|((s2012<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4771 = cn_double(v36); __auto_type v = cn_init_4771;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4811 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4811;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4839 = cn_bits(f[1]); uint64_t v = cn_init_4839;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[1]=cn_double(((((((s2011>>48))|((s2012<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4921 = cn_double(v34); __auto_type v = cn_init_4921;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_4960 = cn_double(v37); __auto_type v = cn_init_4960;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5000 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5000;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5028 = cn_bits(f[0]); uint64_t v = cn_init_5028;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_5190 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5190;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_5238 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5238;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_5301 = (((double)(cn_float(((uint32_t)(((((v16>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5301;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_5364 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5364;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_5412 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5412;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_5475 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5475;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_5537 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5537;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_5584 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5584;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_5646 = (((double)(cn_float(((uint32_t)(((((v16>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5646;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_5689 = cn_bits(f[2]); uint64_t v = cn_init_5689;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_5747 = cn_bits(f[1]); uint64_t v = cn_init_5747;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_5805 = cn_bits(f[0]); uint64_t v = cn_init_5805;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_6015 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_6015;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_6081 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_6081;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_6148 = cn_double(v30); __auto_type v = cn_init_6148;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_6186 = cn_double(v30); __auto_type v = cn_init_6186;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_6242 = 0x41U; __auto_type bv = cn_init_6242;
__auto_type cn_init_6255 = cn_reg_get(rg,4,1); __auto_type av = cn_init_6255;
__auto_type cn_init_6273 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_6273;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
(f[0]=f[1]);
goto cn_break_b5;
}
cn_break_b4:;
(f[1]=f[1]);
}
cn_break_b5:;
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_6347 = 0x1U; __auto_type bv = cn_init_6347;
__auto_type cn_init_6355 = rg[2]; __auto_type av = cn_init_6355;
__auto_type cn_init_6373 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_6373;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b7;
}
{
__auto_type cn_init_6404 = cn_double(v28); __auto_type v = cn_init_6404;
(f[0]=(f[0]/v));
}
}
cn_break_b7:;
(r14=cn_bits(f[0]));
(f[0]=cn_double(((((((v10>>32))|((v11<<32))))&0xffffffffffffffffULL))));
(r34=cn_bits(f[0]));
{
__auto_type cn_init_6474 = 0x46U; __auto_type bv = cn_init_6474;
__auto_type cn_init_6482 = rg[4]; __auto_type av = cn_init_6482;
__auto_type cn_init_6500 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_6500;
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
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_9097eae42ce14448(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_24 = m->regs; __auto_type rg = cn_init_24;
__auto_type cn_init_32 = m->fl; __auto_type fl = cn_init_32;
__auto_type cn_init_40 = m->fsw_cc; __auto_type fsw = cn_init_40;
__auto_type cn_init_53 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_53;
__auto_type cn_init_73 = cn_ptr(m,((uint32_t)(vb+168))); unsigned char * vm = cn_init_73;
__auto_type cn_init_86 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_86;
__auto_type cn_init_99 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_99;
__auto_type cn_init_112 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_112;
__auto_type cn_init_125 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_125;
__auto_type cn_init_138 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_138;
__auto_type cn_init_151 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_151;
__auto_type cn_init_164 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_164;
__auto_type cn_init_177 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_177;
__auto_type cn_init_190 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_216;
__auto_type cn_init_229 = cn_cell(vm,0); uint64_t v21 = cn_init_229;
__auto_type cn_init_242 = cn_cell(vm,8); uint64_t v22 = cn_init_242;
__auto_type cn_init_255 = cn_cell(vm,16); uint64_t v23 = cn_init_255;
__auto_type cn_init_268 = cn_cell(vm,24); uint64_t v24 = cn_init_268;
__auto_type cn_init_281 = cn_cell(vm,32); uint64_t v25 = cn_init_281;
__auto_type cn_init_294 = cn_cell(vm,40); uint64_t v26 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,48); uint64_t v27 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,56); uint64_t v28 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,64); uint64_t v29 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,72); uint64_t v30 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,88); uint64_t v32 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,104); uint64_t v34 = cn_init_372;
{
{
{
{
{
{
{
__auto_type cn_init_396 = 0xffffffd0U; __auto_type bv = cn_init_396;
__auto_type cn_init_404 = rg[4]; __auto_type av = cn_init_404;
__auto_type cn_init_422 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_422;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_451 = r5; uint64_t s = cn_init_451;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_481 = (CN_U2){v28,v29}; CN_U2 s = cn_init_481;
__auto_type cn_init_491 = m->xmm[0]; __auto_type a = cn_init_491;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_561 = v28; uint64_t s = cn_init_561;
__auto_type cn_init_574 = m->xmm[1][0]; __auto_type a = cn_init_574;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_621 = (CN_U2){v24,v25}; CN_U2 s = cn_init_621;
__auto_type cn_init_631 = m->xmm[0]; __auto_type a = cn_init_631;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_701 = v26; uint64_t s = cn_init_701;
__auto_type cn_init_714 = m->xmm[1][0]; __auto_type a = cn_init_714;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_768 = 0x1U; __auto_type bv = cn_init_768;
__auto_type cn_init_776 = rg[2]; __auto_type av = cn_init_776;
__auto_type cn_init_794 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_794;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_822 = r32; uint64_t s = cn_init_822;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_844 = v28; uint64_t s = cn_init_844;
__auto_type cn_init_857 = m->xmm[5][0]; __auto_type a = cn_init_857;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_953 = m->xmm[0][0]; uint64_t v = cn_init_953;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1012 = m->xmm[0][1]; uint64_t v = cn_init_1012;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1071 = m->xmm[1][0]; uint64_t v = cn_init_1071;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1298 = cn_double(v30); __auto_type v = cn_init_1298;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1366 = 0x41U; __auto_type bv = cn_init_1366;
__auto_type cn_init_1379 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1379;
__auto_type cn_init_1397 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1397;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b7;
}
(f[0]=f[0]);
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1456 = 0x2U; __auto_type bv = cn_init_1456;
__auto_type cn_init_1464 = rg[2]; __auto_type av = cn_init_1464;
__auto_type cn_init_1482 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1482;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b5;
}
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1557 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1557;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1584 = cn_round(m,f[0]); __auto_type x = cn_init_1584;
__auto_type cn_init_1619 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_1619;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_1669 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_1669;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_1748 = cn_double(v32); __auto_type v = cn_init_1748;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1783 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_1783;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1823 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1823;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1851 = cn_bits(f[0]); uint64_t v = cn_init_1851;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1949 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1949;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1976 = cn_round(m,f[0]); __auto_type x = cn_init_1976;
__auto_type cn_init_2011 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2011;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_2061 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2061;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2140 = cn_double(v32); __auto_type v = cn_init_2140;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2175 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2175;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2215 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2215;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2243 = cn_bits(f[0]); uint64_t v = cn_init_2243;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2341 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2341;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2368 = cn_round(m,f[0]); __auto_type x = cn_init_2368;
__auto_type cn_init_2403 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2403;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_2453 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2453;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2532 = cn_double(v32); __auto_type v = cn_init_2532;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2567 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2567;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2607 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2607;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2635 = cn_bits(f[0]); uint64_t v = cn_init_2635;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
goto cn_break_b6;
}
cn_break_b5:;
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2737 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2737;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2764 = cn_round(m,f[0]); __auto_type x = cn_init_2764;
__auto_type cn_init_2799 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2799;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_2849 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2849;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2873 = cn_double(v34); __auto_type v = cn_init_2873;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_2953 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2953;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2993 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2993;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3021 = cn_bits(f[0]); uint64_t v = cn_init_3021;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3119 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3119;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3146 = cn_round(m,f[0]); __auto_type x = cn_init_3146;
__auto_type cn_init_3181 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3181;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_3231 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3231;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_3255 = cn_double(v34); __auto_type v = cn_init_3255;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_3335 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3335;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3375 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3375;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3403 = cn_bits(f[0]); uint64_t v = cn_init_3403;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3501 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3501;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3528 = cn_round(m,f[0]); __auto_type x = cn_init_3528;
__auto_type cn_init_3563 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3563;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_3613 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3613;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_3637 = cn_double(v34); __auto_type v = cn_init_3637;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_3717 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3717;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3757 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3757;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3785 = cn_bits(f[0]); uint64_t v = cn_init_3785;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
}
cn_break_b6:;
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_4013 = cn_double(v30); __auto_type v = cn_init_4013;
(f[0]=(f[0]-v));
}
}
cn_break_b7:;
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_4050 = 0x1U; __auto_type bv = cn_init_4050;
__auto_type cn_init_4058 = rg[2]; __auto_type av = cn_init_4058;
__auto_type cn_init_4076 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_4076;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b9;
}
{
__auto_type cn_init_4107 = cn_double(v28); __auto_type v = cn_init_4107;
(f[0]=(f[0]/v));
}
}
cn_break_b9:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_4138 = 0x30U; __auto_type bv = cn_init_4138;
__auto_type cn_init_4146 = rg[4]; __auto_type av = cn_init_4146;
__auto_type cn_init_4164 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_4164;
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
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_a774b10b3f158cbb(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_152 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_178;
__auto_type cn_init_191 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_191;
__auto_type cn_init_204 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_204;
__auto_type cn_init_217 = cn_cell(vm,0); uint64_t v29 = cn_init_217;
__auto_type cn_init_230 = cn_cell(vm,8); uint64_t v30 = cn_init_230;
__auto_type cn_init_243 = cn_cell(vm,24); uint64_t v32 = cn_init_243;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_309 = 0x30U; __auto_type bv = cn_init_309;
__auto_type cn_init_317 = rg[4]; __auto_type av = cn_init_317;
__auto_type cn_init_335 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_335;
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
(f[0]=cn_double(r3));
{
__auto_type cn_init_551 = cn_double(v30); __auto_type v = cn_init_551;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_578 = cn_round(m,f[0]); __auto_type x = cn_init_578;
__auto_type cn_init_613 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_613;
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
{
__auto_type cn_init_663 = (((double)(((int32_t)(((uint32_t)(((((s2012>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_663;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_742 = cn_double(v32); __auto_type v = cn_init_742;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_777 = (((double)(((int32_t)(((uint32_t)(((((s2012>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_777;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_801 = cn_double(v29); __auto_type v = cn_init_801;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_848 = cn_double(v30); __auto_type v = cn_init_848;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_875 = cn_round(m,f[0]); __auto_type x = cn_init_875;
__auto_type cn_init_910 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_910;
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
{
__auto_type cn_init_960 = (((double)(((int32_t)(((uint32_t)(((((s2012>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_960;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_1039 = cn_double(v32); __auto_type v = cn_init_1039;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1074 = (((double)(((int32_t)(((uint32_t)(((((s2012>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_1074;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1098 = cn_double(v29); __auto_type v = cn_init_1098;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_1145 = cn_double(v30); __auto_type v = cn_init_1145;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1172 = cn_round(m,f[0]); __auto_type x = cn_init_1172;
__auto_type cn_init_1207 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_1207;
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
{
__auto_type cn_init_1257 = (((double)(((int32_t)(((uint32_t)(((((s2012>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_1257;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_1336 = cn_double(v32); __auto_type v = cn_init_1336;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1371 = (((double)(((int32_t)(((uint32_t)(((((s2012>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_1371;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1395 = cn_double(v29); __auto_type v = cn_init_1395;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
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
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_add1e1a9add7e00d(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_24 = m->regs; __auto_type rg = cn_init_24;
__auto_type cn_init_32 = m->fl; __auto_type fl = cn_init_32;
__auto_type cn_init_40 = m->fsw_cc; __auto_type fsw = cn_init_40;
__auto_type cn_init_53 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_53;
__auto_type cn_init_73 = cn_ptr(m,((uint32_t)(vb+80))); unsigned char * vm = cn_init_73;
__auto_type cn_init_86 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_86;
__auto_type cn_init_99 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_99;
__auto_type cn_init_112 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_112;
__auto_type cn_init_125 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_125;
__auto_type cn_init_138 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_138;
__auto_type cn_init_151 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_151;
__auto_type cn_init_164 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_164;
__auto_type cn_init_177 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_177;
__auto_type cn_init_190 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_268;
__auto_type cn_init_281 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_281;
__auto_type cn_init_294 = cn_cell(vm,0); uint64_t v10 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,8); uint64_t v11 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,16); uint64_t v12 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,24); uint64_t v13 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,32); uint64_t v14 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,40); uint64_t v15 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,48); uint64_t v16 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,56); uint64_t v17 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,64); uint64_t v18 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,72); uint64_t v19 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,80); uint64_t v20 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,88); uint64_t v21 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,96); uint64_t v22 = cn_init_450;
__auto_type cn_init_463 = cn_cell(vm,104); uint64_t v23 = cn_init_463;
__auto_type cn_init_476 = cn_cell(vm,112); uint64_t v24 = cn_init_476;
__auto_type cn_init_489 = cn_cell(vm,120); uint64_t v25 = cn_init_489;
__auto_type cn_init_502 = cn_cell(vm,128); uint64_t v26 = cn_init_502;
__auto_type cn_init_515 = cn_cell(vm,136); uint64_t v27 = cn_init_515;
__auto_type cn_init_528 = cn_cell(vm,144); uint64_t v28 = cn_init_528;
__auto_type cn_init_541 = cn_cell(vm,152); uint64_t v29 = cn_init_541;
__auto_type cn_init_554 = cn_cell(vm,160); uint64_t v30 = cn_init_554;
__auto_type cn_init_567 = cn_cell(vm,176); uint64_t v32 = cn_init_567;
__auto_type cn_init_580 = cn_cell(vm,192); uint64_t v34 = cn_init_580;
__auto_type cn_init_593 = cn_cell(vm,200); uint64_t v35 = cn_init_593;
__auto_type cn_init_606 = cn_cell(vm,208); uint64_t v36 = cn_init_606;
__auto_type cn_init_619 = cn_cell(vm,216); uint64_t v37 = cn_init_619;
__auto_type cn_init_632 = cn_cell(vm,224); uint64_t v38 = cn_init_632;
{
{
{
{
{
__auto_type cn_init_650 = 0xffffffbaU; __auto_type bv = cn_init_650;
__auto_type cn_init_658 = rg[4]; __auto_type av = cn_init_658;
__auto_type cn_init_676 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_676;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_705 = r5; uint64_t s = cn_init_705;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_735 = (CN_U2){v28,v29}; CN_U2 s = cn_init_735;
__auto_type cn_init_745 = m->xmm[0]; __auto_type a = cn_init_745;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_815 = v28; uint64_t s = cn_init_815;
__auto_type cn_init_828 = m->xmm[1][0]; __auto_type a = cn_init_828;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_875 = (CN_U2){v24,v25}; CN_U2 s = cn_init_875;
__auto_type cn_init_885 = m->xmm[0]; __auto_type a = cn_init_885;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_955 = v26; uint64_t s = cn_init_955;
__auto_type cn_init_968 = m->xmm[1][0]; __auto_type a = cn_init_968;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1022 = 0x1U; __auto_type bv = cn_init_1022;
__auto_type cn_init_1030 = rg[2]; __auto_type av = cn_init_1030;
__auto_type cn_init_1048 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1048;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_1076 = r32; uint64_t s = cn_init_1076;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_1098 = v28; uint64_t s = cn_init_1098;
__auto_type cn_init_1111 = m->xmm[5][0]; __auto_type a = cn_init_1111;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1207 = m->xmm[0][0]; uint64_t v = cn_init_1207;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1266 = m->xmm[0][1]; uint64_t v = cn_init_1266;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1325 = m->xmm[1][0]; uint64_t v = cn_init_1325;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1487 = (((double)(cn_float(((uint32_t)(((((v12>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1487;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1535 = (((double)(cn_float(((uint32_t)(((((v12>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1535;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1598 = (((double)(cn_float(((uint32_t)(((((v11>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1598;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1661 = (((double)(cn_float(((uint32_t)(((((v15>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1661;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1709 = (((double)(cn_float(((uint32_t)(((((v15>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1709;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1772 = (((double)(cn_float(((uint32_t)(((((v14>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1772;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1834 = (((double)(cn_float(((uint32_t)(((((v14>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1834;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1881 = (((double)(cn_float(((uint32_t)(((((v13>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1881;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1943 = (((double)(cn_float(((uint32_t)(((((v13>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1943;
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
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2287 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2287;
(f[0]=(f[0]-v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2398 = cn_double(v30); __auto_type v = cn_init_2398;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2466 = 0x41U; __auto_type bv = cn_init_2466;
__auto_type cn_init_2479 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2479;
__auto_type cn_init_2497 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2497;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
(f[0]=f[0]);
(f[0]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2588 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2588;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2615 = cn_round(m,f[0]); __auto_type x = cn_init_2615;
__auto_type cn_init_2650 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2650;
{
__auto_type cn_init_2660 = ((uint64_t)(i)); uint64_t v = cn_init_2660;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_2734 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_2734;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2813 = cn_double(v32); __auto_type v = cn_init_2813;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2856 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_2856;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2896 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2896;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2924 = cn_bits(f[0]); uint64_t v = cn_init_2924;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3006 = cn_double(v38); __auto_type v = cn_init_3006;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3046 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3046;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3074 = cn_bits(f[0]); uint64_t v = cn_init_3074;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3172 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3172;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3200 = cn_bits(f[0]); uint64_t v = cn_init_3200;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3298 = cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3298;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3325 = cn_round(m,f[0]); __auto_type x = cn_init_3325;
__auto_type cn_init_3360 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3360;
{
__auto_type cn_init_3370 = ((uint64_t)(i)); uint64_t v = cn_init_3370;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_3444 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3444;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3523 = cn_double(v32); __auto_type v = cn_init_3523;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3566 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3566;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3594 = cn_bits(f[0]); uint64_t v = cn_init_3594;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3692 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3692;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_3719 = cn_round(m,f[0]); __auto_type x = cn_init_3719;
__auto_type cn_init_3754 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3754;
{
__auto_type cn_init_3764 = ((uint64_t)(i)); uint64_t v = cn_init_3764;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_3838 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3838;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3917 = cn_double(v32); __auto_type v = cn_init_3917;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3960 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_3960;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_4000 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4000;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_4024 = cn_double(v35); __auto_type v = cn_init_4024;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4051 = cn_round(m,f[0]); __auto_type x = cn_init_4051;
__auto_type cn_init_4086 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_4086;
{
__auto_type cn_init_4096 = ((uint64_t)(i)); uint64_t v = cn_init_4096;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_4170 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_4170;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_4249 = cn_double(v32); __auto_type v = cn_init_4249;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4292 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_4292;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_4320 = cn_bits(f[0]); uint64_t v = cn_init_4320;
(s2011=(((s2011&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2012=(((s2012&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=-f[0]);
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]+f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_4458 = cn_round(m,f[1]); __auto_type x = cn_init_4458;
__auto_type cn_init_4493 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_4493;
{
__auto_type cn_init_4503 = ((uint64_t)(i)); uint64_t v = cn_init_4503;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_4577 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_4577;
(f[1]=(f[1]-v));
}
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_4656 = cn_double(v32); __auto_type v = cn_init_4656;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4699 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_4699;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_4739 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4739;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_4763 = cn_double(v35); __auto_type v = cn_init_4763;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4790 = cn_round(m,f[1]); __auto_type x = cn_init_4790;
__auto_type cn_init_4825 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_4825;
{
__auto_type cn_init_4835 = ((uint64_t)(i)); uint64_t v = cn_init_4835;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffULL))|((((v>>16))&0xffffULL))));
}
}
{
__auto_type cn_init_4909 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_4909;
(f[1]=(f[1]-v));
}
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_4988 = cn_double(v32); __auto_type v = cn_init_4988;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_5031 = (((double)(((int32_t)(((uint32_t)(((((((s2009>>48))|((s2010<<16))))&0xffffffffULL))))))))); __auto_type v = cn_init_5031;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_5074 = cn_bits(f[0]); uint64_t v = cn_init_5074;
(s2012=(((s2012&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2013=(((s2013&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[1]=cn_double(((((((s2011>>48))|((s2012<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5156 = cn_double(v36); __auto_type v = cn_init_5156;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_5196 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5196;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_5224 = cn_bits(f[1]); uint64_t v = cn_init_5224;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[1]=cn_double(((((((s2011>>48))|((s2012<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5306 = cn_double(v34); __auto_type v = cn_init_5306;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_5345 = cn_double(v37); __auto_type v = cn_init_5345;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5385 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5385;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5413 = cn_bits(f[0]); uint64_t v = cn_init_5413;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_5575 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5575;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_5623 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5623;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_5686 = (((double)(cn_float(((uint32_t)(((((v16>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5686;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_5749 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5749;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_5797 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5797;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_5860 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5860;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_5922 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5922;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_5969 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5969;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_6031 = (((double)(cn_float(((uint32_t)(((((v16>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_6031;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_6074 = cn_bits(f[2]); uint64_t v = cn_init_6074;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_6132 = cn_bits(f[1]); uint64_t v = cn_init_6132;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_6190 = cn_bits(f[0]); uint64_t v = cn_init_6190;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_6375 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_6375;
(f[0]=(f[0]-v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_6486 = cn_double(v30); __auto_type v = cn_init_6486;
(f[0]=(f[0]-v));
}
}
cn_break_b4:;
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_6523 = 0x1U; __auto_type bv = cn_init_6523;
__auto_type cn_init_6531 = rg[2]; __auto_type av = cn_init_6531;
__auto_type cn_init_6549 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_6549;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
{
__auto_type cn_init_6580 = cn_double(v28); __auto_type v = cn_init_6580;
(f[0]=(f[0]/v));
}
}
cn_break_b6:;
(r14=cn_bits(f[0]));
(f[0]=cn_double(((((((v10>>32))|((v11<<32))))&0xffffffffffffffffULL))));
(r34=cn_bits(f[0]));
{
__auto_type cn_init_6650 = 0x46U; __auto_type bv = cn_init_6650;
__auto_type cn_init_6658 = rg[4]; __auto_type av = cn_init_6658;
__auto_type cn_init_6676 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_6676;
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
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_bbefa3d716fd8355(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;
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
{
__auto_type cn_init_97 = rg[3]; __auto_type v = cn_init_97;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_115 = 0x104U; __auto_type bv = cn_init_115;
__auto_type cn_init_123 = rg[4]; __auto_type av = cn_init_123;
__auto_type cn_init_141 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_141;
(rg[4]=r);
}
(f[0]=cn_double(0x3ff0000000000000));
(f[1]=f[0]);
{
__auto_type cn_init_185 = ((uint32_t)(rg[4]+0x18U)); __auto_type a = cn_init_185;
cn_wrf64u(m,a,f[1]);
}
(f[1]=cn_rdf64u(m,((uint32_t)(rg[6]+0xffffff88U))));
(f[2]=f[1]);
{
__auto_type cn_init_242 = ((uint32_t)(rg[4]+0x0U)); __auto_type a = cn_init_242;
cn_wrf64u(m,a,f[2]);
}
(f[2]=cn_rdf64u(m,((uint32_t)(rg[6]+0xffffff90U))));
(f[3]=f[2]);
(f[4]=cn_rdf64u(m,((uint32_t)(rg[6]+0xffffff98U))));
(f[5]=f[4]);
(f[6]=f[4]);
(f[7]=f[1]);
(f[7]=(f[7]+f[0]));
{
__auto_type cn_init_364 = ((uint32_t)(rg[4]+0x50U)); __auto_type a = cn_init_364;
cn_wrf64u(m,a,f[7]);
}
(f[7]=f[3]);
(f[7]=(f[7]+f[0]));
{
__auto_type cn_init_416 = ((uint32_t)(rg[4]+0x30U)); __auto_type a = cn_init_416;
cn_wrf64u(m,a,f[7]);
}
(f[7]=f[4]);
(f[7]=(f[7]+f[0]));
{
__auto_type cn_init_468 = ((uint32_t)(rg[4]+0x58U)); __auto_type a = cn_init_468;
cn_wrf64u(m,a,f[7]);
}
(f[7]=f[1]);
(f[7]=(f[7]-f[0]));
{
__auto_type cn_init_520 = ((uint32_t)(rg[4]+0x38U)); __auto_type a = cn_init_520;
cn_wrf64u(m,a,f[7]);
}
(f[7]=f[3]);
(f[7]=(f[7]-f[0]));
{
__auto_type cn_init_572 = ((uint32_t)(rg[4]+0x40U)); __auto_type a = cn_init_572;
cn_wrf64u(m,a,f[7]);
}
cn_swap(f,6,0);
(f[4]=(f[4]-f[6]));
cn_swap(f,5,4);
{
__auto_type cn_init_632 = ((uint32_t)(rg[4]+0x48U)); __auto_type a = cn_init_632;
cn_wrf64u(m,a,f[5]);
}
(f[5]=cn_rdf64u(m,((uint32_t)(rg[7]+0x0U))));
{
__auto_type cn_init_679 = ((uint32_t)(rg[4]+0xb0U)); __auto_type a = cn_init_679;
cn_wrf64u(m,a,f[5]);
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffc4U))));
{
__auto_type cn_init_726 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_726;
cn_wr32u(m,a,rg[0]);
}
(rg[5]=cn_rd32u(m,((uint32_t)(rg[4]+0xf8U))));
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffc0U))));
{
__auto_type cn_init_793 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_793;
cn_wr32u(m,a,rg[0]);
}
(rg[3]=cn_rd32u(m,((uint32_t)(rg[4]+0xf8U))));
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffbcU))));
{
__auto_type cn_init_860 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_860;
cn_wr32u(m,a,rg[0]);
}
(rg[0]=((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+248))))));
{
__auto_type cn_init_901 = 0x4U; __auto_type bv = cn_init_901;
__auto_type cn_init_914 = cn_reg_get(rg,0,1); __auto_type av = cn_init_914;
__auto_type cn_init_932 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_932;
cn_reg_set(rg,0,1,r);
}
{
__auto_type cn_init_960 = cn_reg_get(rg,0,1); __auto_type v = cn_init_960;
{
__auto_type cn_init_974 = ((uint32_t)(rg[4]+0xbeU)); __auto_type a = cn_init_974;
cn_wr8u(m,a,((uint8_t)(v)));
}
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffbcU))));
{
__auto_type cn_init_1021 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_1021;
cn_wr32u(m,a,rg[0]);
}
(rg[0]=((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+248))))));
{
__auto_type cn_init_1062 = 0x1U; __auto_type bv = cn_init_1062;
__auto_type cn_init_1075 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1075;
__auto_type cn_init_1093 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1093;
cn_reg_set(rg,0,1,r);
}
{
__auto_type cn_init_1121 = cn_reg_get(rg,0,1); __auto_type v = cn_init_1121;
{
__auto_type cn_init_1135 = ((uint32_t)(rg[4]+0x97U)); __auto_type a = cn_init_1135;
cn_wr8u(m,a,((uint8_t)(v)));
}
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffbcU))));
{
__auto_type cn_init_1182 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_1182;
cn_wr32u(m,a,rg[0]);
}
(rg[0]=((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+248))))));
{
__auto_type cn_init_1223 = 0x2U; __auto_type bv = cn_init_1223;
__auto_type cn_init_1236 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1236;
__auto_type cn_init_1254 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1254;
cn_reg_set(rg,0,1,r);
}
{
__auto_type cn_init_1282 = cn_reg_get(rg,0,1); __auto_type v = cn_init_1282;
{
__auto_type cn_init_1296 = ((uint32_t)(rg[4]+0xbfU)); __auto_type a = cn_init_1296;
cn_wr8u(m,a,((uint8_t)(v)));
}
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffbcU))));
{
__auto_type cn_init_1343 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_1343;
cn_wr32u(m,a,rg[0]);
}
(rg[0]=((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+248))))));
{
__auto_type cn_init_1384 = 0x8U; __auto_type bv = cn_init_1384;
__auto_type cn_init_1397 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1397;
__auto_type cn_init_1415 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1415;
cn_reg_set(rg,0,1,r);
}
{
__auto_type cn_init_1443 = cn_reg_get(rg,0,1); __auto_type v = cn_init_1443;
{
__auto_type cn_init_1457 = ((uint32_t)(rg[4]+0xb8U)); __auto_type a = cn_init_1457;
cn_wr8u(m,a,((uint8_t)(v)));
}
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffbcU))));
{
__auto_type cn_init_1504 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_1504;
cn_wr32u(m,a,rg[0]);
}
(rg[0]=((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+248))))));
{
__auto_type cn_init_1545 = 0x10U; __auto_type bv = cn_init_1545;
__auto_type cn_init_1558 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1558;
__auto_type cn_init_1576 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1576;
cn_reg_set(rg,0,1,r);
}
{
__auto_type cn_init_1604 = cn_reg_get(rg,0,1); __auto_type v = cn_init_1604;
{
__auto_type cn_init_1618 = ((uint32_t)(rg[4]+0xb9U)); __auto_type a = cn_init_1618;
cn_wr8u(m,a,((uint8_t)(v)));
}
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffbcU))));
{
__auto_type cn_init_1665 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_1665;
cn_wr32u(m,a,rg[0]);
}
(rg[0]=((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+248))))));
{
__auto_type cn_init_1706 = 0x20U; __auto_type bv = cn_init_1706;
__auto_type cn_init_1719 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1719;
__auto_type cn_init_1737 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1737;
cn_reg_set(rg,0,1,r);
}
{
__auto_type cn_init_1765 = cn_reg_get(rg,0,1); __auto_type v = cn_init_1765;
{
__auto_type cn_init_1779 = ((uint32_t)(rg[4]+0xbaU)); __auto_type a = cn_init_1779;
cn_wr8u(m,a,((uint8_t)(v)));
}
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffbcU))));
{
__auto_type cn_init_1826 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_1826;
cn_wr32u(m,a,rg[0]);
}
(rg[0]=((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+248))))));
{
__auto_type cn_init_1867 = 0x40U; __auto_type bv = cn_init_1867;
__auto_type cn_init_1880 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1880;
__auto_type cn_init_1898 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1898;
cn_reg_set(rg,0,1,r);
}
{
__auto_type cn_init_1926 = cn_reg_get(rg,0,1); __auto_type v = cn_init_1926;
{
__auto_type cn_init_1940 = ((uint32_t)(rg[4]+0xbbU)); __auto_type a = cn_init_1940;
cn_wr8u(m,a,((uint8_t)(v)));
}
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffbcU))));
{
__auto_type cn_init_1987 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_1987;
cn_wr32u(m,a,rg[0]);
}
(rg[1]=((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+248))))));
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffbcU))));
{
__auto_type cn_init_2056 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_2056;
cn_wr32u(m,a,rg[0]);
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[4]+0xf8U))));
cn_shift_reg_l(rg,&fl,Shift_Sar,0,8,4);
{
__auto_type cn_init_2116 = 0x1U; __auto_type bv = cn_init_2116;
__auto_type cn_init_2129 = cn_reg_get(rg,0,1); __auto_type av = cn_init_2129;
__auto_type cn_init_2147 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2147;
cn_reg_set(rg,0,1,r);
}
{
__auto_type cn_init_2175 = cn_reg_get(rg,0,1); __auto_type v = cn_init_2175;
{
__auto_type cn_init_2189 = ((uint32_t)(rg[4]+0xbcU)); __auto_type a = cn_init_2189;
cn_wr8u(m,a,((uint8_t)(v)));
}
}
(f[5]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffff9cU))));
(f[5]=fabs(f[5]));
(f[6]=cn_rdf64u(m,((uint32_t)(rg[7]+0x18U))));
(fl.cf=(((f[6]<f[5])||isnan(f[6]))||isnan(f[5])));
(fl.zf=(((f[6]==f[5])||isnan(f[6]))||isnan(f[5])));
(fl.pf=(isnan(f[6])||isnan(f[5])));
(fl.of=false);
(fl.sf=false);
(fl.af=false);
(f[5]=f[5]);
cn_reg_set(rg,2,1,((uint32_t)(cn_cond(fl,7))));
(f[5]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffffe0U))));
(f[6]=f[5]);
{
__auto_type cn_init_2434 = ((uint32_t)(rg[4]+0x20U)); __auto_type a = cn_init_2434;
cn_wrf64u(m,a,f[6]);
}
(f[6]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffffd8U))));
(f[7]=f[6]);
{
__auto_type cn_init_2491 = ((uint32_t)(rg[4]+0x28U)); __auto_type a = cn_init_2491;
cn_wrf64u(m,a,f[7]);
}
(f[7]=cn_rdf64u(m,((uint32_t)(rg[7]+0x28U))));
(f[5]=(f[5]*f[7]));
cn_swap(f,6,5);
{
__auto_type cn_init_2562 = ((uint32_t)(rg[4]+0x98U)); __auto_type a = cn_init_2562;
cn_wrf64u(m,a,f[6]);
}
(f[6]=cn_rdf64u(m,((uint32_t)(rg[7]+0x28U))));
(f[5]=(f[5]*f[6]));
{
__auto_type cn_init_2624 = ((uint32_t)(rg[4]+0xa0U)); __auto_type a = cn_init_2624;
cn_wrf64u(m,a,f[5]);
}
{
__auto_type cn_init_2643 = 0x64U; __auto_type bv = cn_init_2643;
__auto_type cn_init_2651 = rg[5]; __auto_type av = cn_init_2651;
__auto_type cn_init_2669 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2669;
}
{
__auto_type cn_init_2676 = 0x64U; __auto_type v = cn_init_2676;
(rg[0]=v);
}
if(cn_cond(fl,15)){
(rg[5]=rg[0]);
}
{
__auto_type cn_init_2709 = 0x14U; __auto_type bv = cn_init_2709;
__auto_type cn_init_2717 = rg[3]; __auto_type av = cn_init_2717;
__auto_type cn_init_2735 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2735;
}
{
__auto_type cn_init_2742 = 0x14U; __auto_type v = cn_init_2742;
(rg[0]=v);
}
if(cn_cond(fl,14)){
(rg[0]=rg[3]);
}
{
__auto_type cn_init_2783 = ((uint32_t)(rg[4]+0xc4U)); __auto_type a = cn_init_2783;
cn_wr32u(m,a,rg[0]);
}
(f[5]=cn_rdf64u(m,((uint32_t)(rg[7]+0xfffffff0U))));
{
__auto_type cn_init_2830 = ((uint32_t)(rg[4]+0x8U)); __auto_type a = cn_init_2830;
cn_wrf64u(m,a,f[5]);
}
(f[5]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffffe8U))));
(f[6]=f[5]);
{
__auto_type cn_init_2887 = ((uint32_t)(rg[4]+0x60U)); __auto_type a = cn_init_2887;
cn_wrf64u(m,a,f[6]);
}
(f[6]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffff94U))));
{
__auto_type cn_init_2934 = ((uint32_t)(rg[4]+0x10U)); __auto_type a = cn_init_2934;
cn_wrf64u(m,a,f[6]);
}
cn_swap(f,6,5);
cn_wr16u(m,((uint32_t)(rg[4]+248)),m->cw);
{
__auto_type cn_init_2998 = (((uint32_t)(cn_rd16u(m,((uint32_t)(rg[4]+0xf8U)))))); __auto_type v = cn_init_2998;
cn_reg_set(rg,0,2,v);
}
{
__auto_type cn_init_3018 = 0xf3U; __auto_type bv = cn_init_3018;
__auto_type cn_init_3031 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3031;
__auto_type cn_init_3049 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3049;
cn_reg_set(rg,4,1,r);
}
{
__auto_type cn_init_3069 = 0x4U; __auto_type bv = cn_init_3069;
__auto_type cn_init_3082 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3082;
__auto_type cn_init_3100 = cn_alu(&fl,Alu_Or,av,bv,1); __auto_type r = cn_init_3100;
cn_reg_set(rg,4,1,r);
}
{
__auto_type cn_init_3128 = cn_reg_get(rg,0,2); __auto_type v = cn_init_3128;
{
__auto_type cn_init_3142 = ((uint32_t)(rg[4]+0xf0U)); __auto_type a = cn_init_3142;
cn_wr16u(m,a,((uint16_t)(v)));
}
}
(m->cw=cn_rd16u(m,((uint32_t)(rg[4]+240))));
(rg[0]=((uint32_t)(cn_rd16u(m,((uint32_t)(rg[4]+248))))));
{
__auto_type cn_init_3210 = ((uint32_t)(rg[4]+0xc0U)); __auto_type a = cn_init_3210;
cn_wr32u(m,a,rg[0]);
}
(f[6]=(f[6]*f[6]));
cn_swap(f,6,5);
(f[6]=(f[6]*f[6]));
(f[5]=(f[5]+f[6]));
(f[5]=sqrt(f[5]));
(f[6]=f[5]);
{
__auto_type cn_init_3315 = ((uint32_t)(rg[4]+0x88U)); __auto_type a = cn_init_3315;
cn_wrf64u(m,a,f[6]);
}
(f[6]=cn_rdf64u(m,((uint32_t)(rg[7]+0x48U))));
cn_swap(f,6,5);
(fl.cf=(((f[6]<f[5])||isnan(f[6]))||isnan(f[5])));
(fl.zf=(((f[6]==f[5])||isnan(f[6]))||isnan(f[5])));
(fl.pf=(isnan(f[6])||isnan(f[5])));
(fl.of=false);
(fl.sf=false);
(fl.af=false);
(f[5]=f[6]);
if(cn_cond(fl,6)){
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
(f[6]=cn_double(0x3ff0000000000000));
(f[5]=(f[6]/f[5]));
{
__auto_type cn_init_3553 = ((uint32_t)(rg[4]+0x88U)); __auto_type a = cn_init_3553;
cn_wrf64u(m,a,f[5]);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=3);
continue;
}
break;
case 2:
{
(f[5]=f[5]);
(b=3);
}
break;
case 3:
{
{
__auto_type cn_init_3618 = 0x0U; __auto_type bv = cn_init_3618;
__auto_type cn_init_3640 = (((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+0xbeU)))))); __auto_type av = cn_init_3640;
__auto_type cn_init_3658 = cn_alu(&fl,Alu_Cmp,av,bv,1); __auto_type r = cn_init_3658;
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=8);
continue;
}
(b=4);
}
break;
case 4:
{
(f[0]=f[4]);
(f[2]=f[3]);
cn_swap(f,2,1);
cn_swap(f,2,0);
(f[3]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffffb4U))));
(f[0]=(f[0]-f[3]));
(f[3]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffffacU))));
(f[1]=(f[1]-f[3]));
(f[3]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffffa4U))));
(f[2]=(f[2]-f[3]));
{
__auto_type cn_init_3857 = cn_reg_get(rg,2,1); __auto_type bv = cn_init_3857;
__auto_type cn_init_3870 = cn_reg_get(rg,2,1); __auto_type av = cn_init_3870;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=6);
continue;
}
(b=5);
}
break;
case 5:
{
(f[3]=cn_double(0x3ff0000000000000));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=7);
continue;
}
break;
case 6:
{
(f[3]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffff9cU))));
(b=7);
}
break;
case 7:
{
(f[3]=(f[3]*f[3]));
(f[4]=f[0]);
(f[4]=(f[4]*f[0]));
(f[5]=f[1]);
(f[5]=(f[5]*f[1]));
(f[4]=(f[4]+f[5]));
(f[5]=f[2]);
(f[5]=(f[5]*f[2]));
(f[4]=(f[4]+f[5]));
(f[5]=f[4]);
{
__auto_type cn_init_4139 = ((uint32_t)(rg[4]+0xc8U)); __auto_type a = cn_init_4139;
cn_wrf64u(m,a,f[5]);
}
(f[3]=(f[3]/f[4]));
(f[0]=(f[0]*f[3]));
(f[4]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffffb4U))));
(f[0]=(f[0]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_4240 = ((uint32_t)(rg[4]+0x0U)); __auto_type a = cn_init_4240;
cn_wrf64u(m,a,f[3]);
}
(f[3]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffffacU))));
cn_swap(f,3,1);
(f[3]=(f[3]*f[0]));
(f[1]=(f[1]+f[3]));
(f[0]=(f[0]*f[2]));
(f[2]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffffa4U))));
(f[0]=(f[0]+f[2]));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=9);
continue;
}
break;
case 8:
{
(f[4]=f[4]);
(f[3]=f[3]);
(f[1]=f[2]);
(b=9);
}
break;
case 9:
{
{
__auto_type cn_init_4437 = rg[5]; __auto_type bv = cn_init_4437;
__auto_type cn_init_4445 = rg[5]; __auto_type av = cn_init_4445;
cn_alu(&fl,Alu_And,av,bv,4);
}
if(cn_cond(fl,14)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=41);
continue;
}
(b=10);
}
break;
case 10:
{
{
__auto_type cn_init_4508 = 0x0U; __auto_type v = cn_init_4508;
(rg[3]=v);
}
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0x8U))));
(f[2]=-f[2]);
{
__auto_type cn_init_4561 = ((uint32_t)(rg[4]+0xa8U)); __auto_type a = cn_init_4561;
cn_wrf64u(m,a,f[2]);
}
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0x60U))));
(f[2]=-f[2]);
{
__auto_type cn_init_4619 = ((uint32_t)(rg[4]+0x80U)); __auto_type a = cn_init_4619;
cn_wrf64u(m,a,f[2]);
}
{
__auto_type cn_init_4646 = cn_reg_get(rg,1,1); __auto_type v = cn_init_4646;
{
__auto_type cn_init_4660 = ((uint32_t)(rg[4]+0xbdU)); __auto_type a = cn_init_4660;
cn_wr8u(m,a,((uint8_t)(v)));
}
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=12);
continue;
}
break;
case 11:
{
{
__auto_type cn_init_4715 = ((uint32_t)(rg[4]+0x58U)); __auto_type a = cn_init_4715;
cn_wrf64u(m,a,f[1]);
}
cn_swap(f,1,0);
{
__auto_type cn_init_4751 = ((uint32_t)(rg[4]+0x30U)); __auto_type a = cn_init_4751;
cn_wrf64u(m,a,f[1]);
}
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0x0U))));
{
__auto_type cn_init_4798 = ((uint32_t)(rg[4]+0x50U)); __auto_type a = cn_init_4798;
cn_wrf64u(m,a,f[2]);
}
(b=12);
}
break;
case 12:
{
{
__auto_type cn_init_4825 = 0x0U; __auto_type bv = cn_init_4825;
__auto_type cn_init_4847 = (((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+0xbaU)))))); __auto_type av = cn_init_4847;
__auto_type cn_init_4865 = cn_alu(&fl,Alu_Cmp,av,bv,1); __auto_type r = cn_init_4865;
}
if(cn_cond(fl,4)){
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
(f[2]=cn_rdf64u(m,((uint32_t)(rg[7]+0x10U))));
(f[3]=cn_rdf64u(m,((uint32_t)(rg[4]+0x20U))));
(f[2]=(f[2]*f[3]));
cn_swap(f,3,2);
{
__auto_type cn_init_4990 = cn_rdf64u(m,((uint32_t)(rg[4]+0x0U))); __auto_type v = cn_init_4990;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=cn_rdf64u(m,((uint32_t)(rg[7]+0x10U))));
(f[2]=(f[2]*f[4]));
(f[2]=(f[2]+f[3]));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=15);
continue;
}
break;
case 14:
{
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0x0U))));
{
__auto_type cn_init_5134 = cn_rdf64u(m,((uint32_t)(rg[4]+0x20U))); __auto_type v = cn_init_5134;
(f[2]=(f[2]+v));
}
(b=15);
}
break;
case 15:
{
{
__auto_type cn_init_5161 = 0x0U; __auto_type bv = cn_init_5161;
__auto_type cn_init_5183 = (((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+0xbbU)))))); __auto_type av = cn_init_5183;
__auto_type cn_init_5201 = cn_alu(&fl,Alu_Cmp,av,bv,1); __auto_type r = cn_init_5201;
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=17);
continue;
}
(b=16);
}
break;
case 16:
{
(f[3]=cn_rdf64u(m,((uint32_t)(rg[7]+0x10U))));
(f[4]=cn_rdf64u(m,((uint32_t)(rg[4]+0x28U))));
(f[3]=(f[3]*f[4]));
cn_swap(f,4,3);
(f[0]=(f[0]+f[4]));
cn_swap(f,3,0);
(f[3]=fabs(f[3]));
(f[4]=cn_rdf64u(m,((uint32_t)(rg[7]+0x10U))));
(f[0]=(f[0]*f[4]));
(f[0]=(f[0]+f[3]));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=18);
continue;
}
break;
case 17:
{
cn_swap(f,2,0);
{
__auto_type cn_init_5451 = cn_rdf64u(m,((uint32_t)(rg[4]+0x28U))); __auto_type v = cn_init_5451;
(f[2]=(f[2]+v));
}
cn_swap(f,2,0);
(b=18);
}
break;
case 18:
{
(f[3]=cn_rdf64u(m,((uint32_t)(rg[4]+0x98U))));
(f[4]=f[3]);
(f[4]=(f[2]/f[4]));
{
__auto_type cn_init_5540 = ((uint32_t)(rg[4]+0xd8U)); __auto_type a = cn_init_5540;
cn_wrf64u(m,a,f[4]);
}
(f[4]=cn_rdf64u(m,((uint32_t)(rg[4]+0xd8U))));
{
__auto_type cn_init_5587 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_5587;
cn_fstoreu(m,FKind_I32,a,f[4]);
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[4]+0xf8U))));
{
__auto_type cn_init_5638 = ((uint32_t)(rg[4]+0x0U)); __auto_type a = cn_init_5638;
cn_wr32u(m,a,rg[0]);
}
(f[4]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x0U))));
(f[3]=(f[3]*f[4]));
{
__auto_type cn_init_5709 = cn_rdf64u(m,((uint32_t)(rg[4]+0x20U))); __auto_type v = cn_init_5709;
(f[3]=(f[3]+v));
}
(f[2]=(f[2]-f[3]));
(f[3]=cn_rdf64u(m,((uint32_t)(rg[4]+0xa0U))));
(f[4]=f[3]);
(f[4]=(f[0]/f[4]));
{
__auto_type cn_init_5796 = ((uint32_t)(rg[4]+0xe0U)); __auto_type a = cn_init_5796;
cn_wrf64u(m,a,f[4]);
}
(f[4]=cn_rdf64u(m,((uint32_t)(rg[4]+0xe0U))));
{
__auto_type cn_init_5843 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_5843;
cn_fstoreu(m,FKind_I32,a,f[4]);
}
(rg[1]=cn_rd32u(m,((uint32_t)(rg[4]+0xf8U))));
{
__auto_type cn_init_5894 = ((uint32_t)(rg[4]+0x0U)); __auto_type a = cn_init_5894;
cn_wr32u(m,a,rg[1]);
}
(f[4]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x0U))));
(f[3]=(f[3]*f[4]));
{
__auto_type cn_init_5965 = cn_rdf64u(m,((uint32_t)(rg[4]+0x28U))); __auto_type v = cn_init_5965;
(f[3]=(f[3]+v));
}
(f[0]=(f[0]-f[3]));
{
__auto_type cn_init_5999 = 0x0U; __auto_type bv = cn_init_5999;
__auto_type cn_init_6021 = (((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+0x97U)))))); __auto_type av = cn_init_6021;
__auto_type cn_init_6039 = cn_alu(&fl,Alu_Cmp,av,bv,1); __auto_type r = cn_init_6039;
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=20);
continue;
}
(b=19);
}
break;
case 19:
{
(f[3]=cn_rdf64u(m,((uint32_t)(rg[4]+0x8U))));
(f[3]=(f[1]/f[3]));
{
__auto_type cn_init_6130 = ((uint32_t)(rg[4]+0xe8U)); __auto_type a = cn_init_6130;
cn_wrf64u(m,a,f[3]);
}
(f[3]=cn_rdf64u(m,((uint32_t)(rg[4]+0xe8U))));
{
__auto_type cn_init_6177 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_6177;
cn_fstoreu(m,FKind_I32,a,f[3]);
}
(f[3]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0xf8U))));
{
__auto_type cn_init_6237 = cn_rdf64u(m,((uint32_t)(rg[4]+0xa8U))); __auto_type v = cn_init_6237;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(b=20);
}
break;
case 20:
{
{
__auto_type cn_init_6279 = 0x0U; __auto_type bv = cn_init_6279;
__auto_type cn_init_6301 = (((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+0xb8U)))))); __auto_type av = cn_init_6301;
__auto_type cn_init_6319 = cn_alu(&fl,Alu_Cmp,av,bv,1); __auto_type r = cn_init_6319;
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=22);
continue;
}
(b=21);
}
break;
case 21:
{
{
__auto_type cn_init_6367 = 0x1U; __auto_type bv = cn_init_6367;
__auto_type cn_init_6375 = rg[0]; __auto_type av = cn_init_6375;
__auto_type cn_init_6393 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_6393;
(rg[0]=r);
}
(f[3]=f[2]);
(f[3]=-f[3]);
if(cn_cond(fl,4)){
(f[3]=f[2]);
}
(f[2]=f[3]);
(rg[0]=rg[1]);
{
__auto_type cn_init_6467 = 0x1U; __auto_type bv = cn_init_6467;
__auto_type cn_init_6475 = rg[0]; __auto_type av = cn_init_6475;
__auto_type cn_init_6493 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_6493;
(rg[0]=r);
}
(f[3]=f[0]);
(f[3]=-f[3]);
if(cn_cond(fl,4)){
(f[3]=f[0]);
}
(f[0]=f[3]);
(b=22);
}
break;
case 22:
{
(f[3]=cn_rdf64u(m,((uint32_t)(rg[7]+0x10U))));
(f[4]=cn_rdf64u(m,((uint32_t)(rg[7]+0x10U))));
(f[5]=cn_rdf64u(m,((uint32_t)(rg[4]+0x60U))));
(f[3]=(f[3]*f[5]));
cn_swap(f,5,3);
(f[5]=(f[5]+f[2]));
(f[3]=(f[3]*f[5]));
(f[5]=cn_rdf64u(m,((uint32_t)(rg[4]+0x10U))));
(f[4]=(f[4]*f[5]));
cn_swap(f,5,4);
(f[5]=(f[5]+f[0]));
(f[4]=(f[4]*f[5]));
(f[3]=(f[3]-f[4]));
{
__auto_type cn_init_6781 = cn_rdf64u(m,((uint32_t)(rg[4]+0x88U))); __auto_type v = cn_init_6781;
(f[3]=(f[3]*v));
}
(f[4]=f[3]);
(fsw=cn_compare(f[4],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
{
__auto_type cn_init_6853 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_6853;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,2)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=26);
continue;
}
(b=23);
}
break;
case 23:
{
if(cn_cond(fl,7)){
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
(f[5]=cn_double(0x0));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=27);
continue;
}
break;
case 25:
{
(f[5]=cn_double(0x3ff0000000000000));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=27);
continue;
}
break;
case 26:
{
(f[5]=cn_double(0x3ff0000000000000));
(f[5]=-f[5]);
(b=27);
}
break;
case 27:
{
(f[4]=f[5]);
(f[5]=cn_double(0x3ff0000000000000));
(f[6]=cn_rdf64u(m,((uint32_t)(rg[7]+0x20U))));
cn_swap(f,6,3);
(f[6]=fabs(f[6]));
(f[3]=(f[3]*f[6]));
cn_swap(f,5,3);
(f[6]=cn_double(0x3ff71547652b82fe));
(f[5]=(f[5]*f[6]));
(f[6]=cn_double(0x3ff0000000000000));
(f[7]=f[5]);
(f[7]=cn_remainder(f[7],f[6]));
(fsw=(fsw&~0x0400));
(f[7]=(exp2(f[7])-1.0));
(f[6]=(f[6]+f[7]));
(f[6]*=exp2(trunc(f[5])));
cn_swap(f,6,5);
(f[6]=f[6]);
(f[6]=cn_rdf64u(m,((uint32_t)(rg[7]+0x10U))));
(f[7]=cn_rdf64u(m,((uint32_t)(rg[7]+0x18U))));
cn_swap(f,7,5);
(f[3]=(f[3]-f[7]));
cn_swap(f,6,3);
(f[4]=(f[4]*f[6]));
(f[4]=(f[4]*f[5]));
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_7465 = cn_rdf64u(m,((uint32_t)(rg[4]+0x8U))); __auto_type v = cn_init_7465;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_7484 = 0x0U; __auto_type bv = cn_init_7484;
__auto_type cn_init_7506 = (((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+0xb9U)))))); __auto_type av = cn_init_7506;
__auto_type cn_init_7524 = cn_alu(&fl,Alu_Cmp,av,bv,1); __auto_type r = cn_init_7524;
}
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=30);
continue;
}
(b=28);
}
break;
case 28:
{
cn_swap(f,3,1);
(fl.cf=(((f[3]<f[1])||isnan(f[3]))||isnan(f[1])));
(fl.zf=(((f[3]==f[1])||isnan(f[3]))||isnan(f[1])));
(fl.pf=(isnan(f[3])||isnan(f[1])));
(fl.of=false);
(fl.sf=false);
(fl.af=false);
(f[1]=f[3]);
if(cn_cond(fl,6)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=31);
continue;
}
(b=29);
}
break;
case 29:
{
{
__auto_type cn_init_7749 = cn_rdf64u(m,((uint32_t)(rg[4]+0x80U))); __auto_type v = cn_init_7749;
(f[2]=(v-f[2]));
}
cn_swap(f,2,1);
{
__auto_type cn_init_7790 = cn_rdf64u(m,((uint32_t)(rg[4]+0x8U))); __auto_type v = cn_init_7790;
(f[2]=(v-f[2]));
}
cn_swap(f,2,0);
{
__auto_type cn_init_7831 = cn_rdf64u(m,((uint32_t)(rg[4]+0x10U))); __auto_type v = cn_init_7831;
(f[2]=(v-f[2]));
}
cn_swap(f,2,0);
cn_swap(f,2,1);
(steps+=1);
if((steps>limit)){
return 1;
}
(b=31);
continue;
}
break;
case 30:
{
(f[3]=(f[3]-f[1]));
(f[4]=cn_rdf64u(m,((uint32_t)(rg[7]+0x8U))));
{
__auto_type cn_init_7944 = cn_rdf64u(m,((uint32_t)(rg[4]+0x8U))); __auto_type v = cn_init_7944;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]-f[4]));
(f[4]=cn_double(0x0));
(fl.cf=(((f[4]<f[3])||isnan(f[4]))||isnan(f[3])));
(fl.zf=(((f[4]==f[3])||isnan(f[4]))||isnan(f[3])));
(fl.pf=(isnan(f[4])||isnan(f[3])));
(fl.of=false);
(fl.sf=false);
(fl.af=false);
(f[3]=f[3]);
if(cn_cond(fl,7)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=42);
continue;
}
(b=31);
}
break;
case 31:
{
{
__auto_type cn_init_8145 = 0x0U; __auto_type bv = cn_init_8145;
__auto_type cn_init_8167 = (((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+0xbdU)))))); __auto_type av = cn_init_8167;
__auto_type cn_init_8185 = cn_alu(&fl,Alu_Cmp,av,bv,1); __auto_type r = cn_init_8185;
}
if(cn_cond(fl,9)){
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
(f[2]=fabs(f[2]));
(b=33);
}
break;
case 33:
{
{
__auto_type cn_init_8255 = 0x0U; __auto_type bv = cn_init_8255;
__auto_type cn_init_8277 = (((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+0xbcU)))))); __auto_type av = cn_init_8277;
__auto_type cn_init_8295 = cn_alu(&fl,Alu_Cmp,av,bv,1); __auto_type r = cn_init_8295;
}
if(cn_cond(fl,4)){
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
cn_swap(f,2,0);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
(b=35);
}
break;
case 35:
{
(f[3]=f[2]);
(f[3]=(f[3]*f[2]));
(f[4]=f[1]);
(f[4]=(f[4]*f[1]));
{
__auto_type cn_init_8441 = ((uint32_t)(rg[4]+0x68U)); __auto_type a = cn_init_8441;
cn_wrf64u(m,a,f[4]);
}
(f[5]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffffd0U))));
{
__auto_type cn_init_8488 = ((uint32_t)(rg[4]+0x70U)); __auto_type a = cn_init_8488;
cn_wrf64u(m,a,f[5]);
}
(f[5]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffffc8U))));
{
__auto_type cn_init_8535 = ((uint32_t)(rg[4]+0x78U)); __auto_type a = cn_init_8535;
cn_wrf64u(m,a,f[5]);
}
(f[4]=(f[4]+f[3]));
(f[5]=f[0]);
(f[5]=(f[5]*f[0]));
(f[4]=(f[4]+f[5]));
(f[5]=cn_double(0x3ff0000000000000));
(f[4]=(f[5]/f[4]));
(f[5]=f[4]);
(f[5]=-f[5]);
(f[6]=f[2]);
(f[6]=(f[6]*f[5]));
(f[7]=f[1]);
(f[7]=(f[7]*f[5]));
cn_swap(f,7,5);
(f[0]=(f[0]*f[7]));
{
__auto_type cn_init_8744 = cn_rdf64u(m,((uint32_t)(rg[4]+0x80U))); __auto_type v = cn_init_8744;
(f[6]=(v-f[6]));
}
{
__auto_type cn_init_8771 = ((uint32_t)(rg[4]+0x0U)); __auto_type a = cn_init_8771;
cn_wrf64u(m,a,f[6]);
}
{
__auto_type cn_init_8803 = cn_rdf64u(m,((uint32_t)(rg[4]+0x8U))); __auto_type v = cn_init_8803;
(f[5]=(f[5]+v));
}
cn_swap(f,5,0);
{
__auto_type cn_init_8844 = cn_rdf64u(m,((uint32_t)(rg[4]+0x10U))); __auto_type v = cn_init_8844;
(f[5]=(v-f[5]));
}
cn_swap(f,5,4);
{
__auto_type cn_init_8885 = cn_rdf64u(m,((uint32_t)(rg[4]+0x18U))); __auto_type v = cn_init_8885;
(f[5]=(f[5]*v));
}
{
__auto_type cn_init_8912 = ((uint32_t)(rg[4]+0x18U)); __auto_type a = cn_init_8912;
cn_wrf64u(m,a,f[5]);
}
{
__auto_type cn_init_8939 = cn_reg_get(rg,2,1); __auto_type bv = cn_init_8939;
__auto_type cn_init_8952 = cn_reg_get(rg,2,1); __auto_type av = cn_init_8952;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
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
cn_swap(f,4,1);
(f[2]=(f[2]*f[4]));
(f[4]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffff9cU))));
cn_swap(f,4,3);
{
__auto_type cn_init_9081 = cn_rdf64u(m,((uint32_t)(rg[4]+0x68U))); __auto_type v = cn_init_9081;
(f[4]=(f[4]-v));
}
{
__auto_type cn_init_9113 = cn_rdf64u(m,((uint32_t)(rg[4]+0x70U))); __auto_type v = cn_init_9113;
(f[4]=(f[4]+v));
}
(f[3]=(f[3]*f[4]));
{
__auto_type cn_init_9160 = cn_rdf64u(m,((uint32_t)(rg[4]+0x0U))); __auto_type v = cn_init_9160;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_9187 = ((uint32_t)(rg[4]+0x0U)); __auto_type a = cn_init_9187;
cn_wrf64u(m,a,f[3]);
}
(f[3]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffff9cU))));
(f[4]=cn_rdf64u(m,((uint32_t)(rg[4]+0x78U))));
(f[4]=(f[4]+f[2]));
(f[2]=(f[2]+f[4]));
(f[2]=(f[2]*f[3]));
(f[0]=(f[0]+f[2]));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=38);
continue;
}
break;
case 37:
{
(f[1]=f[4]);
(f[3]=f[3]);
(f[2]=f[2]);
(b=38);
}
break;
case 38:
{
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0x48U))));
(f[2]=(f[1]-f[2]));
(f[3]=cn_rdf64u(m,((uint32_t)(rg[4]+0x40U))));
(f[3]=(f[0]-f[3]));
(f[4]=cn_rdf64u(m,((uint32_t)(rg[4]+0x38U))));
{
__auto_type cn_init_9475 = cn_rdf64u(m,((uint32_t)(rg[4]+0x0U))); __auto_type v = cn_init_9475;
(f[4]=(v-f[4]));
}
(f[5]=cn_rdf64u(m,((uint32_t)(rg[7]+0x48U))));
cn_swap(f,5,4);
(f[5]=(f[5]*f[5]));
cn_swap(f,5,3);
(f[5]=(f[5]*f[5]));
(f[3]=(f[3]+f[5]));
cn_swap(f,4,2);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
cn_swap(f,3,2);
(fl.cf=(((f[3]<f[2])||isnan(f[3]))||isnan(f[2])));
(fl.zf=(((f[3]==f[2])||isnan(f[3]))||isnan(f[2])));
(fl.pf=(isnan(f[3])||isnan(f[2])));
(fl.of=false);
(fl.sf=false);
(fl.af=false);
(f[2]=f[2]);
if(cn_cond(fl,7)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=43);
continue;
}
(b=39);
}
break;
case 39:
{
{
__auto_type cn_init_9782 = fl.cf; __auto_type cf = cn_init_9782;
__auto_type cn_init_9803 = cn_alu(&fl,Alu_Add,rg[3],1,4); __auto_type r = cn_init_9803;
(fl.cf=cf);
(rg[3]=r);
}
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0x50U))));
{
__auto_type cn_init_9851 = ((uint32_t)(rg[4]+0x38U)); __auto_type a = cn_init_9851;
cn_wrf64u(m,a,f[2]);
}
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0x30U))));
{
__auto_type cn_init_9898 = ((uint32_t)(rg[4]+0x40U)); __auto_type a = cn_init_9898;
cn_wrf64u(m,a,f[2]);
}
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0x58U))));
{
__auto_type cn_init_9945 = ((uint32_t)(rg[4]+0x48U)); __auto_type a = cn_init_9945;
cn_wrf64u(m,a,f[2]);
}
{
__auto_type cn_init_9967 = rg[5]; __auto_type bv = cn_init_9967;
__auto_type cn_init_9975 = rg[3]; __auto_type av = cn_init_9975;
__auto_type cn_init_9993 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_9993;
}
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=11);
continue;
}
(b=40);
}
break;
case 40:
{
cn_swap(f,1,0);
(rg[3]=rg[5]);
{
__auto_type cn_init_10068 = ((uint32_t)(rg[4]+0x30U)); __auto_type a = cn_init_10068;
cn_wrf64u(m,a,f[1]);
}
cn_swap(f,1,0);
(steps+=1);
if((steps>limit)){
return 1;
}
(b=43);
continue;
}
break;
case 41:
{
cn_swap(f,1,0);
{
__auto_type cn_init_10133 = 0x0U; __auto_type v = cn_init_10133;
(rg[3]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=43);
continue;
}
break;
case 42:
{
{
__auto_type cn_init_10183 = ((uint32_t)(rg[4]+0x0U)); __auto_type a = cn_init_10183;
cn_wrf64u(m,a,f[2]);
}
cn_swap(f,1,0);
(steps+=1);
if((steps>limit)){
return 1;
}
(b=43);
continue;
}
break;
case 43:
{
(f[2]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffff8cU))));
(f[3]=cn_rdf64u(m,((uint32_t)(rg[7]+0x30U))));
{
__auto_type cn_init_10287 = ((uint32_t)(rg[4]+0x20U)); __auto_type a = cn_init_10287;
cn_wr32u(m,a,rg[3]);
}
(f[4]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x20U))));
(f[4]=sqrt(f[4]));
(f[5]=cn_rdf64u(m,((uint32_t)(rg[7]+0x30U))));
cn_swap(f,5,3);
(f[5]=(f[5]-f[2]));
{
__auto_type cn_init_10401 = cn_rdf64u(m,((uint32_t)(rg[4]+0x30U))); __auto_type v = cn_init_10401;
(f[5]=(f[5]*v));
}
cn_swap(f,5,4);
(f[2]=(f[2]*f[5]));
cn_swap(f,4,2);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]/f[3]));
{
__auto_type cn_init_10491 = ((uint32_t)(rg[4]+0xf0U)); __auto_type a = cn_init_10491;
cn_wrf64u(m,a,f[2]);
}
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0xf0U))));
{
__auto_type cn_init_10538 = ((uint32_t)(rg[6]+0x80U)); __auto_type a = cn_init_10538;
cn_wrf64u(m,a,f[2]);
}
(f[2]=cn_double(0x3ff0000000000000));
(f[3]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_10581 = 0x0U; __auto_type v = cn_init_10581;
(rg[0]=v);
}
(f[4]=cn_rdf64u(m,((uint32_t)(rg[4]+0x0U))));
cn_swap(f,4,2);
(rg[1]=((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+191))))));
{
__auto_type cn_init_10654 = ((uint32_t)(rg[4]+0x0U)); __auto_type a = cn_init_10654;
cn_wrf64u(m,a,f[4]);
}
(f[4]=cn_rdf64u(m,((uint32_t)(rg[4]+0xb0U))));
(f[5]=cn_rdf64u(m,((uint32_t)(rg[4]+0x18U))));
(rg[3]=cn_rd32u(m,((uint32_t)(rg[4]+0xc4U))));
(b=44);
}
break;
case 44:
{
(f[6]=f[0]);
{
__auto_type cn_init_10759 = cn_reg_get(rg,1,1); __auto_type bv = cn_init_10759;
__auto_type cn_init_10772 = cn_reg_get(rg,1,1); __auto_type av = cn_init_10772;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=46);
continue;
}
(b=45);
}
break;
case 45:
{
(f[6]=f[6]);
(f[6]=cn_rdf64u(m,((uint32_t)(rg[4]+0x8U))));
(f[6]=(f[6]-f[0]));
(fl.cf=(((f[6]<f[0])||isnan(f[6]))||isnan(f[0])));
(fl.zf=(((f[6]==f[0])||isnan(f[6]))||isnan(f[0])));
(fl.pf=(isnan(f[6])||isnan(f[0])));
(fl.of=false);
(fl.sf=false);
(fl.af=false);
if(cn_cond(fl,7)){
(f[6]=f[0]);
}
(b=46);
}
break;
case 46:
{
(f[7]=cn_rdf64u(m,((uint32_t)(rg[4]+0x0U))));
(fl.cf=(((f[7]<f[6])||isnan(f[7]))||isnan(f[6])));
(fl.zf=(((f[7]==f[6])||isnan(f[7]))||isnan(f[6])));
(fl.pf=(isnan(f[7])||isnan(f[6])));
(fl.of=false);
(fl.sf=false);
(fl.af=false);
if(cn_cond(fl,7)){
(f[7]=f[6]);
}
(f[6]=f[7]);
cn_swap(f,6,5);
(fl.cf=(((f[6]<f[3])||isnan(f[6]))||isnan(f[3])));
(fl.zf=(((f[6]==f[3])||isnan(f[6]))||isnan(f[3])));
(fl.pf=(isnan(f[6])||isnan(f[3])));
(fl.of=false);
(fl.sf=false);
(fl.af=false);
(f[7]=f[3]);
if(cn_cond(fl,7)){
(f[7]=f[6]);
}
(f[5]=(f[5]/f[7]));
cn_swap(f,6,5);
(fl.cf=(((f[6]<f[4])||isnan(f[6]))||isnan(f[4])));
(fl.zf=(((f[6]==f[4])||isnan(f[6]))||isnan(f[4])));
(fl.pf=(isnan(f[6])||isnan(f[4])));
(fl.of=false);
(fl.sf=false);
(fl.af=false);
if(cn_cond(fl,7)){
(f[6]=f[4]);
}
(f[4]=f[6]);
{
__auto_type cn_init_11466 = rg[3]; __auto_type bv = cn_init_11466;
__auto_type cn_init_11474 = rg[0]; __auto_type av = cn_init_11474;
__auto_type cn_init_11492 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_11492;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=48);
continue;
}
(b=47);
}
break;
case 47:
{
cn_swap(f,5,2);
{
__auto_type cn_init_11562 = cn_rdf64u(m,((uint32_t)(rg[4]+0x60U))); __auto_type v = cn_init_11562;
(f[5]=(f[5]+v));
}
cn_swap(f,5,0);
{
__auto_type cn_init_11603 = cn_rdf64u(m,((uint32_t)(rg[4]+0x8U))); __auto_type v = cn_init_11603;
(f[5]=(v-f[5]));
}
cn_swap(f,5,1);
{
__auto_type cn_init_11644 = cn_rdf64u(m,((uint32_t)(rg[4]+0x10U))); __auto_type v = cn_init_11644;
(f[5]=(f[5]-v));
}
(f[6]=f[0]);
(f[6]=(f[6]*f[0]));
(f[7]=f[1]);
(f[7]=(f[7]*f[1]));
(f[6]=(f[6]+f[7]));
(f[7]=f[5]);
(f[7]=(f[7]*f[5]));
(f[6]=(f[6]+f[7]));
(f[7]=cn_double(0x3ff0000000000000));
(f[6]=(f[7]/f[6]));
(f[0]=(f[0]*f[6]));
(f[1]=(f[1]*f[6]));
(f[5]=(f[5]*f[6]));
(f[2]=(f[2]*f[6]));
cn_swap(f,5,1);
cn_swap(f,5,0);
cn_swap(f,5,2);
{
__auto_type cn_init_11884 = fl.cf; __auto_type cf = cn_init_11884;
__auto_type cn_init_11905 = cn_alu(&fl,Alu_Add,rg[0],1,4); __auto_type r = cn_init_11905;
(fl.cf=cf);
(rg[0]=r);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=44);
continue;
}
break;
case 48:
{
(f[5]=f[5]);
(f[1]=f[4]);
(f[3]=f[3]);
(f[2]=f[2]);
(f[0]=f[1]);
{
__auto_type cn_init_12011 = ((uint32_t)(rg[4]+0xb0U)); __auto_type a = cn_init_12011;
cn_wrf64u(m,a,f[0]);
}
{
__auto_type cn_init_12030 = 0x0U; __auto_type bv = cn_init_12030;
__auto_type cn_init_12052 = (((uint32_t)(cn_rd8u(m,((uint32_t)(rg[4]+0xbeU)))))); __auto_type av = cn_init_12052;
__auto_type cn_init_12070 = cn_alu(&fl,Alu_Cmp,av,bv,1); __auto_type r = cn_init_12070;
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=53);
continue;
}
(b=49);
}
break;
case 49:
{
{
__auto_type cn_init_12126 = cn_reg_get(rg,2,1); __auto_type bv = cn_init_12126;
__auto_type cn_init_12139 = cn_reg_get(rg,2,1); __auto_type av = cn_init_12139;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=51);
continue;
}
(b=50);
}
break;
case 50:
{
(f[1]=cn_double(0x3ff0000000000000));
(steps+=1);
if((steps>limit)){
return 1;
}
(b=52);
continue;
}
break;
case 51:
{
(f[1]=cn_rdf64u(m,((uint32_t)(rg[7]+0xffffff9cU))));
(b=52);
}
break;
case 52:
{
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0xc8U))));
(f[3]=f[2]);
(f[3]=(f[3]*f[0]));
cn_swap(f,3,2);
(f[3]=sqrt(f[3]));
(f[0]=(f[0]*f[3]));
cn_swap(f,2,0);
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]/f[1]));
{
__auto_type cn_init_12400 = ((uint32_t)(rg[4]+0xb0U)); __auto_type a = cn_init_12400;
cn_wrf64u(m,a,f[0]);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=54);
continue;
}
break;
case 53:
{
(f[0]=f[0]);
(b=54);
}
break;
case 54:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[4]+0xc0U))));
{
__auto_type cn_init_12493 = cn_reg_get(rg,0,2); __auto_type v = cn_init_12493;
{
__auto_type cn_init_12507 = ((uint32_t)(rg[4]+0xd6U)); __auto_type a = cn_init_12507;
cn_wr16u(m,a,((uint16_t)(v)));
}
}
(m->cw=cn_rd16u(m,((uint32_t)(rg[4]+214))));
(f[0]=cn_rdf64u(m,((uint32_t)(rg[4]+0xb0U))));
{
__auto_type cn_init_12573 = ((uint32_t)(rg[4]+0xf8U)); __auto_type a = cn_init_12573;
cn_wrf64u(m,a,f[0]);
}
(f[0]=cn_rdf64u(m,((uint32_t)(rg[4]+0xf8U))));
{
__auto_type cn_init_12620 = ((uint32_t)(rg[6]+0xffffffe0U)); __auto_type a = cn_init_12620;
cn_wrf64u(m,a,f[0]);
}
{
__auto_type cn_init_12639 = 0x104U; __auto_type bv = cn_init_12639;
__auto_type cn_init_12647 = rg[4]; __auto_type av = cn_init_12647;
__auto_type cn_init_12665 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_12665;
(rg[4]=r);
}
{
__auto_type cn_init_12686 = cn_pop_lu(m,rg); __auto_type v = cn_init_12686;
(rg[3]=v);
}
{
__auto_type cn_init_12707 = cn_pop_lu(m,rg); __auto_type v = cn_init_12707;
(rg[5]=v);
}
__auto_type cn_init_12727 = cn_pop_lu(m,rg); __auto_type r = cn_init_12727;
(rg[ESP]=((uint32_t)(rg[ESP]+0)));
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
int cn_f_bdee0a1f4f1c566e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+224))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_178;
__auto_type cn_init_191 = cn_cell(vm,0); uint64_t v28 = cn_init_191;
__auto_type cn_init_204 = cn_cell(vm,8); uint64_t v29 = cn_init_204;
__auto_type cn_init_217 = cn_cell(vm,16); uint64_t v30 = cn_init_217;
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
(f[0]=cn_double(r3));
{
__auto_type cn_init_428 = cn_double(v30); __auto_type v = cn_init_428;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_475 = cn_double(v29); __auto_type v = cn_init_475;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_522 = cn_double(v28); __auto_type v = cn_init_522;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
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
int cn_f_cc0171a0c630040b(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_24 = m->regs; __auto_type rg = cn_init_24;
__auto_type cn_init_32 = m->fl; __auto_type fl = cn_init_32;
__auto_type cn_init_40 = m->fsw_cc; __auto_type fsw = cn_init_40;
__auto_type cn_init_53 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_53;
__auto_type cn_init_73 = cn_ptr(m,((uint32_t)(vb+184))); unsigned char * vm = cn_init_73;
__auto_type cn_init_86 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_86;
__auto_type cn_init_99 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_99;
__auto_type cn_init_112 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_112;
__auto_type cn_init_125 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_125;
__auto_type cn_init_138 = cn_rd64u(m,0x10007e80U); uint64_t s2000 = cn_init_138;
__auto_type cn_init_151 = cn_rd64u(m,0x10007e88U); uint64_t s2001 = cn_init_151;
__auto_type cn_init_164 = cn_rd64u(m,0x10007e90U); uint64_t s2002 = cn_init_164;
__auto_type cn_init_177 = cn_rd64u(m,0x10007e98U); uint64_t s2003 = cn_init_177;
__auto_type cn_init_190 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_268;
__auto_type cn_init_281 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_281;
__auto_type cn_init_294 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_294;
__auto_type cn_init_307 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_307;
__auto_type cn_init_320 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_320;
__auto_type cn_init_333 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,0); uint64_t v23 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,8); uint64_t v24 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,16); uint64_t v25 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,24); uint64_t v26 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,32); uint64_t v27 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,40); uint64_t v28 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,48); uint64_t v29 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,56); uint64_t v30 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,72); uint64_t v32 = cn_init_450;
__auto_type cn_init_463 = cn_cell(vm,80); uint64_t v33 = cn_init_463;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2015=(((s2015&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_566 = 0x74U; __auto_type bv = cn_init_566;
__auto_type cn_init_574 = rg[4]; __auto_type av = cn_init_574;
__auto_type cn_init_592 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_592;
(rg[4]=r);
}
(f[0]=cn_double(r3));
(s2001=cn_bits(f[0]));
(f[0]=cn_double(r4));
(s2002=cn_bits(f[0]));
(f[0]=cn_double(r5));
(s2003=cn_bits(f[0]));
(f[0]=cn_double(v26));
(f[1]=cn_double(v25));
(f[2]=cn_double(v28));
cn_swap(f,2,0);
{
__auto_type cn_init_725 = cn_double(s2001); __auto_type v = cn_init_725;
(f[2]=(v-f[2]));
}
(f[0]=(f[0]*f[2]));
(f[2]=f[0]);
(f[3]=cn_double(v28));
cn_swap(f,3,1);
{
__auto_type cn_init_795 = cn_double(s2002); __auto_type v = cn_init_795;
(f[3]=(v-f[3]));
}
(f[1]=(f[1]*f[3]));
(f[3]=cn_double(v29));
{
__auto_type cn_init_846 = cn_double(s2003); __auto_type v = cn_init_846;
(f[3]=(f[3]*v));
}
(s2004=cn_bits(f[3]));
(f[3]=cn_double(v30));
(f[4]=cn_double(v32));
(f[5]=f[0]);
(f[5]=(f[5]*f[0]));
(f[6]=f[1]);
(f[6]=(f[6]*f[1]));
(f[5]=(f[5]+f[6]));
(f[6]=cn_double(0x3fe62e42fefa39ef));
cn_swap(f,6,5);
(f[5]*=log2(f[6]));
cn_swap(f,5,3);
(f[4]=(f[4]*f[5]));
(f[3]=(f[3]*f[4]));
(f[4]=cn_double(0x3ff71547652b82fe));
(f[3]=(f[3]*f[4]));
(f[4]=cn_double(0x3ff0000000000000));
(f[5]=f[3]);
{
__auto_type cn_tuple_1102_0 = f[5];
__auto_type cn_tuple_1102_1 = f[4];
__auto_type x = cn_tuple_1102_0;
__auto_type y = cn_tuple_1102_1;
__auto_type cn_init_1131 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1131;
(f[5]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1163 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1163;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[5]=(exp2(f[5])-1.0));
(f[4]=(f[4]+f[5]));
(f[4]*=exp2(trunc(f[3])));
cn_swap(f,4,3);
(f[4]=f[4]);
cn_swap(f,3,1);
(s2000=cn_bits(f[3]));
cn_swap(f,3,2);
cn_swap(f,3,0);
(f[2]=atan2(f[2],f[3]));
(f[3]=cn_double(v30));
(f[2]=(f[2]*f[3]));
(s2006=cn_bits(f[2]));
(f[2]=cn_double(s2006));
{
__auto_type cn_tuple_1405_0 = sin(f[2]);
__auto_type cn_tuple_1405_1 = cos(f[2]);
__auto_type s = cn_tuple_1405_0;
__auto_type c = cn_tuple_1405_1;
(f[2]=s);
(f[3]=c);
(fsw&=~0x0400);
}
(s2012=cn_bits(f[3]));
(s2013=cn_bits(f[2]));
(f[2]=f[1]);
{
__auto_type cn_init_1468 = cn_double(s2013); __auto_type v = cn_init_1468;
(f[2]=(f[2]*v));
}
cn_swap(f,2,1);
{
__auto_type cn_init_1501 = cn_double(s2012); __auto_type v = cn_init_1501;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(v29));
(f[4]=cn_double(v32));
(f[5]=f[2]);
(f[5]=(f[5]*f[2]));
(f[6]=f[1]);
(f[6]=(f[6]*f[1]));
(f[5]=(f[5]+f[6]));
(f[6]=cn_double(0x3fe62e42fefa39ef));
cn_swap(f,6,5);
(f[5]*=log2(f[6]));
cn_swap(f,5,4);
(f[3]=(f[3]*f[5]));
(f[3]=(f[3]*f[4]));
(f[4]=cn_double(0x3ff71547652b82fe));
(f[3]=(f[3]*f[4]));
(f[4]=cn_double(0x3ff0000000000000));
(f[5]=f[3]);
{
__auto_type cn_tuple_1773_0 = f[5];
__auto_type cn_tuple_1773_1 = f[4];
__auto_type x = cn_tuple_1773_0;
__auto_type y = cn_tuple_1773_1;
__auto_type cn_init_1802 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1802;
(f[5]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1834 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1834;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[5]=(exp2(f[5])-1.0));
(f[4]=(f[4]+f[5]));
(f[4]*=exp2(trunc(f[3])));
cn_swap(f,4,3);
(f[4]=f[4]);
cn_swap(f,3,1);
cn_swap(f,3,2);
(f[2]=atan2(f[2],f[3]));
(f[3]=cn_double(v29));
(f[2]=(f[2]*f[3]));
(s2007=cn_bits(f[2]));
(f[2]=cn_double(s2007));
{
__auto_type cn_tuple_2056_0 = sin(f[2]);
__auto_type cn_tuple_2056_1 = cos(f[2]);
__auto_type s = cn_tuple_2056_0;
__auto_type c = cn_tuple_2056_1;
(f[2]=s);
(f[3]=c);
(fsw&=~0x0400);
}
(s2012=cn_bits(f[3]));
(s2013=cn_bits(f[2]));
(f[2]=f[1]);
{
__auto_type cn_init_2119 = cn_double(s2013); __auto_type v = cn_init_2119;
(f[2]=(f[2]*v));
}
cn_swap(f,2,1);
{
__auto_type cn_init_2152 = cn_double(s2012); __auto_type v = cn_init_2152;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]+f[3]));
(f[3]=f[2]);
(f[4]=cn_double(v33));
cn_swap(f,4,2);
(f[4]=(f[4]*f[4]));
(f[5]=f[1]);
(f[5]=(f[5]*f[1]));
(f[4]=(f[4]+f[5]));
(f[2]=(f[2]/f[4]));
(f[4]=cn_double(v24));
(s2005=cn_bits(f[4]));
(f[4]=cn_double(v23));
(f[5]=cn_double(v27));
(f[6]=f[0]);
(f[6]=(f[6]*f[3]));
(f[7]=cn_double(s2000));
(f[7]=(f[7]*f[1]));
(f[6]=(f[6]+f[7]));
(f[6]=(f[6]*f[2]));
{
__auto_type cn_init_2433 = cn_double(s2005); __auto_type v = cn_init_2433;
(f[6]=(f[6]-v));
}
(f[5]=(f[5]*f[6]));
(f[6]=cn_double(v27));
cn_swap(f,6,3);
{
__auto_type cn_init_2493 = cn_double(s2000); __auto_type v = cn_init_2493;
(f[6]=(f[6]*v));
}
cn_swap(f,6,1);
(f[0]=(f[0]*f[6]));
cn_swap(f,5,1);
(f[0]=(f[5]-f[0]));
cn_swap(f,4,0);
(f[2]=(f[2]*f[4]));
cn_swap(f,3,0);
(f[2]=(f[2]-f[3]));
(f[0]=(f[0]*f[2]));
(f[2]=cn_double(v28));
(f[3]=cn_double(s2004));
(f[2]=(f[2]*f[3]));
(f[3]=cn_double(s2001));
(f[4]=f[3]);
(f[3]=(f[3]*f[4]));
(f[4]=cn_double(s2002));
(f[5]=f[4]);
(f[4]=(f[4]*f[5]));
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(s2003));
(f[5]=f[4]);
(f[4]=(f[4]*f[5]));
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
(f[4]=(f[4]*f[1]));
(f[5]=f[0]);
(f[5]=(f[5]*f[0]));
(f[4]=(f[4]+f[5]));
(f[5]=f[2]);
(f[5]=(f[5]*f[2]));
(f[4]=(f[4]+f[5]));
(f[3]=(f[3]/f[4]));
(f[3]=sqrt(f[3]));
cn_swap(f,3,1);
(s2008=cn_bits(f[3]));
cn_swap(f,2,0);
(f[3]=cn_double(s2008));
(r3=cn_bits(f[3]));
(s2009=cn_bits(f[2]));
cn_swap(f,1,0);
(f[2]=cn_double(s2009));
(r4=cn_bits(f[2]));
(s2010=cn_bits(f[1]));
(f[1]=cn_double(s2010));
(r5=cn_bits(f[1]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(s2011));
{
__auto_type cn_init_3094 = cn_double(r32); __auto_type v = cn_init_3094;
(f[0]=(f[0]*v));
}
(r32=cn_bits(f[0]));
{
__auto_type cn_init_3124 = 0x74U; __auto_type bv = cn_init_3124;
__auto_type cn_init_3132 = rg[4]; __auto_type av = cn_init_3132;
__auto_type cn_init_3150 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3150;
(rg[4]=r);
}
{
(rg[6]=((uint32_t)(((((s2014>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[7]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10001100U,r32);
cn_wr64u(m,0x10007e80U,s2000);
cn_wr64u(m,0x10007e88U,s2001);
cn_wr64u(m,0x10007e90U,s2002);
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
cn_wr64u(m,0x10007ef8U,s2015);
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_d1afd04a670fe713(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+192))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_268;
__auto_type cn_init_281 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_281;
__auto_type cn_init_294 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_294;
__auto_type cn_init_307 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_307;
__auto_type cn_init_320 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_320;
__auto_type cn_init_333 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,0); uint64_t v24 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,8); uint64_t v25 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,16); uint64_t v26 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,24); uint64_t v27 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,32); uint64_t v28 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,40); uint64_t v29 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,48); uint64_t v30 = cn_init_424;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_490 = 0x40U; __auto_type bv = cn_init_490;
__auto_type cn_init_498 = rg[4]; __auto_type av = cn_init_498;
__auto_type cn_init_516 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_516;
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
{
__auto_type cn_init_732 = cn_double(v26); __auto_type v = cn_init_732;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_768 = cn_double(v25); __auto_type v = cn_init_768;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_807 = cn_double(v24); __auto_type v = cn_init_807;
(f[0]=(f[0]+v));
}
(f[0]=sin(f[0]));
(fsw&=~0x0400);
{
__auto_type cn_init_850 = cn_double(v27); __auto_type v = cn_init_850;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_874 = cn_double(r5); __auto_type v = cn_init_874;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
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
__auto_type cn_tuple_1125_0 = f[2];
__auto_type cn_tuple_1125_1 = f[1];
__auto_type x = cn_tuple_1125_0;
__auto_type y = cn_tuple_1125_1;
__auto_type cn_init_1154 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1154;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1186 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1186;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2011=cn_bits(f[0]));
(f[1]=cn_double(r4));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1451 = cn_double(v30); __auto_type v = cn_init_1451;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1481_0 = sin(f[0]);
__auto_type cn_tuple_1481_1 = cos(f[0]);
__auto_type s = cn_tuple_1481_0;
__auto_type c = cn_tuple_1481_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2009=cn_bits(f[1]));
(s2010=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[1]=cn_double(r5));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1576 = cn_double(v29); __auto_type v = cn_init_1576;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1606_0 = sin(f[0]);
__auto_type cn_tuple_1606_1 = cos(f[0]);
__auto_type s = cn_tuple_1606_0;
__auto_type c = cn_tuple_1606_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2007=cn_bits(f[1]));
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_1671 = cn_double(s2008); __auto_type v = cn_init_1671;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1695 = cn_double(s2012); __auto_type v = cn_init_1695;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1719 = cn_double(r10); __auto_type v = cn_init_1719;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_1766 = cn_double(s2012); __auto_type v = cn_init_1766;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1790 = cn_double(r11); __auto_type v = cn_init_1790;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_1837 = cn_double(s2007); __auto_type v = cn_init_1837;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1861 = cn_double(v28); __auto_type v = cn_init_1861;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1885 = cn_double(s2012); __auto_type v = cn_init_1885;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1909 = cn_double(r12); __auto_type v = cn_init_1909;
(f[0]=(f[0]+v));
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
int cn_f_db5a99b4889edb6e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_24 = m->regs; __auto_type rg = cn_init_24;
__auto_type cn_init_32 = m->fl; __auto_type fl = cn_init_32;
__auto_type cn_init_40 = m->fsw_cc; __auto_type fsw = cn_init_40;
__auto_type cn_init_53 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_53;
__auto_type cn_init_73 = cn_ptr(m,((uint32_t)(vb+232))); unsigned char * vm = cn_init_73;
__auto_type cn_init_86 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_86;
__auto_type cn_init_99 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_99;
__auto_type cn_init_112 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_112;
__auto_type cn_init_125 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_125;
__auto_type cn_init_138 = cn_cell(vm,0); uint64_t v29 = cn_init_138;
__auto_type cn_init_151 = cn_cell(vm,8); uint64_t v30 = cn_init_151;
__auto_type cn_init_164 = cn_cell(vm,24); uint64_t v32 = cn_init_164;
{
{
__auto_type cn_init_173 = 0xffffffe0U; __auto_type bv = cn_init_173;
__auto_type cn_init_181 = rg[4]; __auto_type av = cn_init_181;
__auto_type cn_init_199 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_199;
(rg[4]=r);
}
(f[0]=cn_double(r5));
{
__auto_type cn_init_230 = cn_double(v30); __auto_type v = cn_init_230;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_257 = cn_round(m,f[0]); __auto_type x = cn_init_257;
__auto_type cn_init_292 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_292;
(s2011=(((s2011&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_342 = (((double)(((int32_t)(((uint32_t)(((((s2011>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_342;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_421 = cn_double(v32); __auto_type v = cn_init_421;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_456 = (((double)(((int32_t)(((uint32_t)(((((s2011>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_456;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_480 = cn_double(v29); __auto_type v = cn_init_480;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_527 = cn_double(v30); __auto_type v = cn_init_527;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_554 = cn_round(m,f[0]); __auto_type x = cn_init_554;
__auto_type cn_init_589 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_589;
(s2011=(((s2011&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_639 = (((double)(((int32_t)(((uint32_t)(((((s2011>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_639;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_718 = cn_double(v32); __auto_type v = cn_init_718;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_753 = (((double)(((int32_t)(((uint32_t)(((((s2011>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_753;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_777 = cn_double(v29); __auto_type v = cn_init_777;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_824 = cn_double(v30); __auto_type v = cn_init_824;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_851 = cn_round(m,f[0]); __auto_type x = cn_init_851;
__auto_type cn_init_886 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_886;
(s2011=(((s2011&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_936 = (((double)(((int32_t)(((uint32_t)(((((s2011>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_936;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_1015 = cn_double(v32); __auto_type v = cn_init_1015;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1050 = (((double)(((int32_t)(((uint32_t)(((((s2011>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_1050;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1074 = cn_double(v29); __auto_type v = cn_init_1074;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
{
__auto_type cn_init_1104 = 0x20U; __auto_type bv = cn_init_1104;
__auto_type cn_init_1112 = rg[4]; __auto_type av = cn_init_1112;
__auto_type cn_init_1130 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1130;
(rg[4]=r);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10007ed8U,s2011);
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_e000d141ddd3a421(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+216))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v27 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,8); uint64_t v28 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,16); uint64_t v29 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,24); uint64_t v30 = cn_init_247;
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
(f[0]=cn_double(r3));
{
__auto_type cn_init_411 = cn_double(v30); __auto_type v = cn_init_411;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_458 = cn_double(v29); __auto_type v = cn_init_458;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_505 = cn_double(v28); __auto_type v = cn_init_505;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
{
__auto_type cn_init_552 = cn_double(v27); __auto_type v = cn_init_552;
(f[0]=(f[0]*v));
}
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
int cn_f_e04801556de19bc6(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+224))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_178;
__auto_type cn_init_191 = cn_cell(vm,0); uint64_t v28 = cn_init_191;
__auto_type cn_init_204 = cn_cell(vm,8); uint64_t v29 = cn_init_204;
__auto_type cn_init_217 = cn_cell(vm,16); uint64_t v30 = cn_init_217;
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
(f[0]=cn_double(r3));
{
__auto_type cn_init_428 = cn_double(v30); __auto_type v = cn_init_428;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_475 = cn_double(v29); __auto_type v = cn_init_475;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_522 = cn_double(v28); __auto_type v = cn_init_522;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
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
int cn_f_e37b852748043cdc(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_24 = m->regs; __auto_type rg = cn_init_24;
__auto_type cn_init_32 = m->fl; __auto_type fl = cn_init_32;
__auto_type cn_init_40 = m->fsw_cc; __auto_type fsw = cn_init_40;
__auto_type cn_init_53 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_53;
__auto_type cn_init_73 = cn_ptr(m,((uint32_t)(vb+160))); unsigned char * vm = cn_init_73;
__auto_type cn_init_86 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_86;
__auto_type cn_init_99 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_99;
__auto_type cn_init_112 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_112;
__auto_type cn_init_125 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_125;
__auto_type cn_init_138 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_138;
__auto_type cn_init_151 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_151;
__auto_type cn_init_164 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_164;
__auto_type cn_init_177 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_177;
__auto_type cn_init_190 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_242;
__auto_type cn_init_255 = cn_cell(vm,0); uint64_t v20 = cn_init_255;
__auto_type cn_init_268 = cn_cell(vm,8); uint64_t v21 = cn_init_268;
__auto_type cn_init_281 = cn_cell(vm,16); uint64_t v22 = cn_init_281;
__auto_type cn_init_294 = cn_cell(vm,24); uint64_t v23 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,32); uint64_t v24 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,40); uint64_t v25 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,48); uint64_t v26 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,56); uint64_t v27 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,64); uint64_t v28 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,72); uint64_t v29 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,80); uint64_t v30 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,96); uint64_t v32 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,104); uint64_t v33 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,112); uint64_t v34 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,120); uint64_t v35 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,128); uint64_t v36 = cn_init_450;
__auto_type cn_init_463 = cn_cell(vm,136); uint64_t v37 = cn_init_463;
__auto_type cn_init_476 = cn_cell(vm,144); uint64_t v38 = cn_init_476;
__auto_type cn_init_489 = cn_cell(vm,152); uint64_t v39 = cn_init_489;
__auto_type cn_init_502 = cn_cell(vm,160); uint64_t v40 = cn_init_502;
__auto_type cn_init_515 = cn_cell(vm,168); uint64_t v41 = cn_init_515;
__auto_type cn_init_528 = cn_cell(vm,176); uint64_t v42 = cn_init_528;
__auto_type cn_init_541 = cn_cell(vm,184); uint64_t v43 = cn_init_541;
__auto_type cn_init_554 = cn_cell(vm,192); uint64_t v44 = cn_init_554;
__auto_type cn_init_567 = cn_cell(vm,200); uint64_t v45 = cn_init_567;
__auto_type cn_init_580 = cn_cell(vm,208); uint64_t v46 = cn_init_580;
__auto_type cn_init_593 = cn_cell(vm,216); uint64_t v47 = cn_init_593;
{
{
{
{
{
{
{
__auto_type cn_init_617 = 0x44U; __auto_type bv = cn_init_617;
__auto_type cn_init_625 = rg[4]; __auto_type av = cn_init_625;
__auto_type cn_init_643 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_643;
(rg[4]=r);
}
(f[0]=cn_double(r4));
(f[1]=cn_double(v27));
(f[2]=cn_double(v29));
cn_swap(f,2,1);
(f[0]=(f[0]*f[2]));
(f[0]=(f[1]-f[0]));
(f[1]=cn_double(r5));
(f[2]=cn_double(v27));
(f[3]=cn_double(v28));
cn_swap(f,3,2);
(f[1]=(f[1]*f[3]));
(f[1]=(f[2]-f[1]));
(f[2]=cn_double(r3));
(f[3]=cn_double(v27));
(f[4]=cn_double(v30));
cn_swap(f,4,3);
(f[2]=(f[2]*f[4]));
(f[2]=(f[2]+f[3]));
(f[3]=(((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))));
(f[4]=(((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))));
(f[5]=(((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))));
cn_swap(f,5,3);
(f[5]=(f[5]*f[0]));
cn_swap(f,5,4);
(f[5]=(f[5]*f[1]));
(f[4]=(f[4]+f[5]));
cn_swap(f,4,3);
(f[4]=(f[4]*f[2]));
(f[3]=(f[3]+f[4]));
(f[4]=(((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))));
(f[5]=(((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))));
cn_swap(f,5,4);
(f[5]=(f[5]*f[0]));
cn_swap(f,5,4);
(f[5]=(f[5]*f[1]));
(f[4]=(f[4]+f[5]));
(f[5]=(((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))));
(f[5]=(f[5]*f[2]));
(f[4]=(f[4]+f[5]));
(f[5]=(((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))));
(f[6]=(((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))));
(f[7]=(((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))));
cn_swap(f,7,5);
(f[0]=(f[0]*f[7]));
(f[1]=(f[1]*f[6]));
cn_swap(f,5,1);
(f[0]=(f[0]+f[5]));
cn_swap(f,4,2);
(f[1]=(f[1]*f[4]));
cn_swap(f,3,1);
(f[0]=(f[0]+f[3]));
(rg[0]=((uint32_t)(((((v20>>0))&0xffffffffULL)))));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
{
__auto_type cn_init_1469 = 0x0U; __auto_type bv = cn_init_1469;
__auto_type cn_init_1486 = (((uint32_t)(((((s2014>>0))&0xffffffffULL))))); __auto_type av = cn_init_1486;
__auto_type cn_init_1504 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1504;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(f[3]=cn_double(r3));
(f[4]=cn_double(v27));
(f[5]=cn_double(v30));
cn_swap(f,5,3);
(f[4]=(f[4]*f[5]));
(f[3]=(f[3]+f[4]));
(s2008=cn_bits(f[3]));
(f[3]=cn_double(s2008));
(r3=cn_bits(f[3]));
(f[3]=cn_double(r4));
(f[4]=cn_double(v27));
(f[5]=cn_double(v29));
cn_swap(f,5,3);
(f[4]=(f[4]*f[5]));
(f[3]=(f[3]+f[4]));
(s2009=cn_bits(f[3]));
(f[3]=cn_double(s2009));
(r4=cn_bits(f[3]));
(f[3]=cn_double(r5));
(f[4]=cn_double(v27));
(f[5]=cn_double(v28));
cn_swap(f,5,3);
(f[4]=(f[4]*f[5]));
(f[3]=(f[3]+f[4]));
(s2010=cn_bits(f[3]));
(f[3]=cn_double(s2010));
(r5=cn_bits(f[3]));
(f[3]=cn_double(v27));
(s2011=cn_bits(f[3]));
(f[3]=cn_double(s2011));
{
__auto_type cn_init_1890 = cn_double(r32); __auto_type v = cn_init_1890;
(f[3]=(f[3]*v));
}
(r32=cn_bits(f[3]));
}
cn_break_b2:;
(f[3]=f[0]);
(f[3]=(f[3]*f[0]));
(f[4]=f[1]);
(f[4]=(f[4]*f[1]));
(f[5]=f[2]);
(f[5]=(f[5]*f[2]));
(f[4]=(f[4]+f[5]));
(f[4]=(f[4]+f[3]));
(f[4]=sqrt(f[4]));
(f[5]=f[4]);
(f[6]=cn_double(v44));
{
__auto_type cn_tuple_2076_0 = f[6];
__auto_type cn_tuple_2076_1 = f[5];
__auto_type x = cn_tuple_2076_0;
__auto_type y = cn_tuple_2076_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_2109 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_2109;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
(f[5]=f[5]);
if(cn_cond(fl,6)){
goto cn_break_b7;
}
(f[4]=f[4]);
(f[4]=cn_double(v41));
(f[4]=(f[4]+f[2]));
(f[5]=f[4]);
(f[5]=(f[5]*f[4]));
(f[3]=(f[3]+f[5]));
cn_swap(f,4,3);
(f[4]=sqrt(f[4]));
(f[5]=cn_double(v42));
(f[3]=(f[5]-f[3]));
(f[5]=cn_double(v43));
(f[4]=(f[4]-f[5]));
(f[5]=f[1]);
(f[5]=fabs(f[5]));
(f[6]=cn_double(v38));
(f[5]=(f[5]-f[6]));
(f[6]=cn_double(0x0));
cn_swap(f,6,3);
{
__auto_type cn_tuple_2404_0 = f[6];
__auto_type cn_tuple_2404_1 = f[3];
__auto_type x = cn_tuple_2404_0;
__auto_type y = cn_tuple_2404_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_2437 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_2437;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
if(cn_cond(fl,6)){
(f[6]=f[3]);
}
cn_swap(f,6,4);
{
__auto_type cn_tuple_2512_0 = f[6];
__auto_type cn_tuple_2512_1 = f[3];
__auto_type x = cn_tuple_2512_0;
__auto_type y = cn_tuple_2512_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_2545 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_2545;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
if(cn_cond(fl,6)){
(f[6]=f[3]);
}
cn_swap(f,6,5);
{
__auto_type cn_tuple_2620_0 = f[6];
__auto_type cn_tuple_2620_1 = f[3];
__auto_type x = cn_tuple_2620_0;
__auto_type y = cn_tuple_2620_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_2653 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_2653;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
if(cn_cond(fl,6)){
(f[6]=f[3]);
}
(f[3]=f[6]);
cn_swap(f,5,3);
(f[5]=(f[5]*f[5]));
cn_swap(f,5,3);
(f[5]=(f[5]*f[5]));
(f[3]=(f[3]+f[5]));
(f[5]=f[4]);
(f[4]=(f[4]*f[5]));
(f[3]=(f[3]+f[4]));
(f[3]=sqrt(f[3]));
(f[4]=cn_double(v33));
(f[3]=(f[3]-f[4]));
(f[4]=cn_double(0x3ff0000000000000));
(f[4]=(f[0]-f[4]));
cn_swap(f,4,3);
{
__auto_type cn_tuple_2909_0 = f[4];
__auto_type cn_tuple_2909_1 = f[3];
__auto_type x = cn_tuple_2909_0;
__auto_type y = cn_tuple_2909_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_2942 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_2942;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
if(cn_cond(fl,6)){
(f[4]=f[3]);
}
(f[3]=f[4]);
(f[4]=cn_double(v45));
(f[2]=(f[2]-f[4]));
(f[4]=cn_double(v46));
cn_swap(f,4,1);
(f[4]=fabs(f[4]));
(f[5]=cn_double(v39));
(f[4]=(f[4]-f[5]));
(f[4]=fabs(f[4]));
cn_swap(f,4,0);
(f[1]=(f[1]+f[4]));
cn_swap(f,3,1);
(f[3]=fabs(f[3]));
(f[4]=cn_double(v40));
(f[3]=(f[3]-f[4]));
(f[4]=f[2]);
(f[4]=(f[4]*f[2]));
cn_swap(f,4,3);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[3]=sqrt(f[3]));
(f[4]=cn_double(v34));
cn_swap(f,4,2);
(f[4]=-f[4]);
(f[2]=(f[4]-f[2]));
(f[4]=cn_double(v37));
(f[4]=(f[3]-f[4]));
(f[5]=cn_double(v34));
(f[5]=(f[0]-f[5]));
(f[6]=cn_double(0x0));
cn_swap(f,6,2);
{
__auto_type cn_tuple_3395_0 = f[6];
__auto_type cn_tuple_3395_1 = f[2];
__auto_type x = cn_tuple_3395_0;
__auto_type y = cn_tuple_3395_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_3428 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_3428;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
if(cn_cond(fl,6)){
(f[6]=f[2]);
}
cn_swap(f,6,4);
{
__auto_type cn_tuple_3503_0 = f[6];
__auto_type cn_tuple_3503_1 = f[2];
__auto_type x = cn_tuple_3503_0;
__auto_type y = cn_tuple_3503_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_3536 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_3536;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
if(cn_cond(fl,6)){
(f[6]=f[2]);
}
cn_swap(f,6,5);
{
__auto_type cn_tuple_3611_0 = f[6];
__auto_type cn_tuple_3611_1 = f[2];
__auto_type x = cn_tuple_3611_0;
__auto_type y = cn_tuple_3611_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_3644 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_3644;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
if(cn_cond(fl,6)){
(f[6]=f[2]);
}
(f[2]=f[6]);
cn_swap(f,5,2);
(f[5]=(f[5]*f[5]));
cn_swap(f,5,2);
(f[5]=(f[5]*f[5]));
(f[2]=(f[2]+f[5]));
(f[4]=(f[4]*f[4]));
(f[2]=(f[2]+f[4]));
cn_swap(f,3,2);
(f[3]=sqrt(f[3]));
(f[4]=cn_double(v32));
(f[5]=cn_double(v44));
(f[5]=-f[5]);
(f[1]=(f[1]*f[5]));
cn_swap(f,5,1);
(f[6]=cn_double(0x3ff71547652b82fe));
(f[5]=(f[5]*f[6]));
(f[6]=cn_double(0x3ff0000000000000));
(f[7]=f[5]);
{
__auto_type cn_tuple_3944_0 = f[7];
__auto_type cn_tuple_3944_1 = f[6];
__auto_type x = cn_tuple_3944_0;
__auto_type y = cn_tuple_3944_1;
__auto_type cn_init_3973 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_3973;
(f[7]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_4005 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_4005;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[7]=(exp2(f[7])-1.0));
(f[6]=(f[6]+f[7]));
(f[6]*=exp2(trunc(f[5])));
cn_swap(f,6,5);
(f[6]=f[6]);
cn_swap(f,5,3);
(f[4]=(f[5]-f[4]));
(f[4]=(f[4]*f[1]));
(f[5]=cn_double(0x3ff71547652b82fe));
(f[4]=(f[4]*f[5]));
(f[5]=cn_double(0x3ff0000000000000));
(f[6]=f[4]);
{
__auto_type cn_tuple_4232_0 = f[6];
__auto_type cn_tuple_4232_1 = f[5];
__auto_type x = cn_tuple_4232_0;
__auto_type y = cn_tuple_4232_1;
__auto_type cn_init_4261 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_4261;
(f[6]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_4293 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_4293;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[6]=(exp2(f[6])-1.0));
(f[5]=(f[5]+f[6]));
(f[5]*=exp2(trunc(f[4])));
cn_swap(f,5,4);
(f[5]=f[5]);
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(0x3fe62e42fefa39ef));
cn_swap(f,4,3);
(f[3]*=log2(f[4]));
(f[1]=(f[3]/f[1]));
(f[3]=cn_double(v37));
(f[3]=(f[2]-f[3]));
(f[4]=cn_double(v36));
(f[4]=(f[0]-f[4]));
{
__auto_type cn_tuple_4551_0 = f[4];
__auto_type cn_tuple_4551_1 = f[3];
__auto_type x = cn_tuple_4551_0;
__auto_type y = cn_tuple_4551_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_4584 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_4584;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
if(cn_cond(fl,6)){
(f[4]=f[3]);
}
(f[3]=f[4]);
(f[3]=-f[3]);
cn_swap(f,3,1);
{
__auto_type cn_tuple_4680_0 = f[3];
__auto_type cn_tuple_4680_1 = f[1];
__auto_type x = cn_tuple_4680_0;
__auto_type y = cn_tuple_4680_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_4713 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_4713;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
if(cn_cond(fl,6)){
(f[3]=f[1]);
}
(f[1]=f[3]);
(f[3]=cn_double(v45));
(f[2]=(f[2]-f[3]));
(f[3]=cn_double(0x0));
(f[4]=cn_double(v35));
(f[0]=(f[0]-f[4]));
(f[4]=f[0]);
{
__auto_type cn_tuple_4865_0 = f[4];
__auto_type cn_tuple_4865_1 = f[3];
__auto_type x = cn_tuple_4865_0;
__auto_type y = cn_tuple_4865_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_4898 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_4898;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
if(cn_cond(fl,7)){
(f[3]=f[0]);
}
(f[0]=f[3]);
(f[3]=f[0]);
(f[0]=(f[0]*f[3]));
(f[3]=f[2]);
(f[2]=(f[2]*f[3]));
(f[0]=(f[0]+f[2]));
cn_swap(f,1,0);
(f[1]=sqrt(f[1]));
(f[2]=cn_double(v47));
(f[1]=(f[1]-f[2]));
{
__auto_type cn_tuple_5089_0 = f[1];
__auto_type cn_tuple_5089_1 = f[0];
__auto_type x = cn_tuple_5089_0;
__auto_type y = cn_tuple_5089_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_5122 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_5122;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
if(cn_cond(fl,7)){
(f[1]=f[0]);
}
{
__auto_type cn_tuple_5188_0 = f[1];
__auto_type cn_tuple_5188_1 = f[0];
__auto_type x = cn_tuple_5188_0;
__auto_type y = cn_tuple_5188_1;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_5221 = (isnan(x)||isnan(y)); __auto_type unordered = cn_init_5221;
(fl.zf=(unordered||(x==y)));
(fl.pf=unordered);
(fl.cf=(unordered||(x<y)));
}
(f[0]=f[1]);
if(cn_cond(fl,10)){
goto cn_break_b5;
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
goto cn_break_b5;
}
cn_break_b6:;
(f[1]=cn_double(v25));
(s2013=cn_bits(f[1]));
(f[1]=cn_double(s2013));
(r34=cn_bits(f[1]));
goto cn_break_b8;
}
cn_break_b5:;
(f[1]=cn_double(v26));
(s2012=cn_bits(f[1]));
(f[1]=cn_double(s2012));
(r34=cn_bits(f[1]));
goto cn_break_b8;
}
cn_break_b7:;
(f[1]=f[4]);
(f[3]=f[3]);
(f[2]=f[2]);
(f[0]=f[1]);
}
cn_break_b8:;
(f[1]=cn_double(v27));
(f[0]=(f[0]/f[1]));
(s2014=cn_bits(f[0]));
(f[0]=cn_double(s2014));
(r14=cn_bits(f[0]));
{
__auto_type cn_init_5494 = 0x44U; __auto_type bv = cn_init_5494;
__auto_type cn_init_5502 = rg[4]; __auto_type av = cn_init_5502;
__auto_type cn_init_5520 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_5520;
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
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_fb2f524a42903f19(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_58 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_58;
__auto_type cn_init_75 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_75;
__auto_type cn_init_92 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_92;
__auto_type cn_init_109 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_109;
__auto_type cn_init_126 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_126;
__auto_type cn_init_143 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_143;
__auto_type cn_init_156 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_169;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(rg[0]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
{
__auto_type cn_init_252 = 0x38U; __auto_type bv = cn_init_252;
__auto_type cn_init_260 = rg[0]; __auto_type av = cn_init_260;
__auto_type cn_init_278 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_278;
(rg[0]=r);
}
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
(f[2]=f[0]);
(f[3]=f[1]);
cn_swap(f,3,2);
(f[3]=(f[3]*f[0]));
cn_swap(f,3,2);
(f[3]=(f[3]*f[1]));
cn_swap(f,3,0);
(f[1]=(f[1]*f[3]));
(f[3]=f[2]);
(f[4]=cn_double(r5));
cn_swap(f,4,1);
(f[4]=(f[4]+f[4]));
cn_swap(f,4,3);
(f[4]=(f[4]+f[0]));
cn_swap(f,4,2);
(f[0]=(f[4]-f[0]));
(f[4]=f[1]);
cn_swap(f,4,2);
(f[4]=sqrt(f[4]));
cn_swap(f,4,2);
(f[4]=(f[4]*f[1]));
cn_swap(f,4,2);
(f[5]=cn_double(0x3ff0000000000000));
(f[4]=(f[5]/f[4]));
(f[3]=(f[3]*f[4]));
(f[5]=f[3]);
cn_swap(f,5,0);
(f[4]=(f[4]*f[5]));
(f[5]=f[2]);
cn_swap(f,5,0);
(f[5]=(f[5]*f[3]));
cn_swap(f,5,1);
(f[5]=(f[5]*f[3]));
cn_swap(f,5,3);
(r4=cn_bits(f[5]));
cn_swap(f,4,0);
(f[4]=(f[4]+f[1]));
cn_swap(f,4,3);
(f[4]=(f[4]+f[4]));
cn_swap(f,4,1);
(f[2]=(f[4]-f[2]));
(f[3]=sqrt(f[3]));
(f[4]=f[0]);
(r3=cn_bits(f[4]));
cn_swap(f,4,3);
(f[5]=cn_double(0x3ff0000000000000));
(f[4]=(f[5]/f[4]));
(f[1]=(f[1]*f[4]));
(f[5]=f[1]);
cn_swap(f,5,2);
(f[4]=(f[4]*f[5]));
cn_swap(f,4,0);
(f[4]=(f[4]*f[3]));
cn_swap(f,4,2);
(f[4]=(f[4]*f[1]));
cn_swap(f,4,1);
(r5=cn_bits(f[4]));
(f[3]=(f[3]*f[4]));
(f[4]=f[1]);
cn_swap(f,4,3);
(f[4]=(f[4]+f[4]));
cn_swap(f,4,0);
(r4=cn_bits(f[4]));
cn_swap(f,4,3);
(f[4]=(f[4]+f[2]));
cn_swap(f,4,2);
(f[1]=(f[4]-f[1]));
(f[4]=f[3]);
cn_swap(f,4,2);
(f[4]=sqrt(f[4]));
cn_swap(f,4,2);
(f[4]=(f[4]*f[3]));
cn_swap(f,4,2);
(f[5]=cn_double(0x3ff0000000000000));
(f[4]=(f[5]/f[4]));
(f[1]=(f[1]*f[4]));
(f[0]=(f[0]*f[4]));
(f[4]=f[1]);
(f[4]=(f[4]*f[1]));
(f[2]=(f[2]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[0]));
(f[2]=(f[2]+f[4]));
cn_swap(f,3,2);
(f[3]=sqrt(f[3]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
(f[0]=(f[0]*f[3]));
cn_swap(f,2,1);
{
__auto_type cn_init_1384 = cn_double(r10); __auto_type v = cn_init_1384;
(f[2]=(f[2]+v));
}
cn_swap(f,2,1);
{
__auto_type cn_init_1417 = cn_double(r11); __auto_type v = cn_init_1417;
(f[2]=(f[2]+v));
}
cn_swap(f,2,0);
{
__auto_type cn_init_1450 = cn_double(r12); __auto_type v = cn_init_1450;
(f[2]=(f[2]+v));
}
cn_swap(f,2,1);
(r3=cn_bits(f[2]));
cn_swap(f,1,0);
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
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
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
