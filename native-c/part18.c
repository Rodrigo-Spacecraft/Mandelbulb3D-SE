/* Generated native C formula calculations. See tools/generate-native-c.py. */
#include "runtime.h"
int cn_f_10b6bb1104349cbf(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
{
__auto_type cn_init_395 = cn_double(v30); __auto_type v = cn_init_395;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_456 = cn_double(v29); __auto_type v = cn_init_456;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_517 = cn_double(v28); __auto_type v = cn_init_517;
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
int cn_f_147b986ebf3538f6(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_24 = m->regs; __auto_type rg = cn_init_24;
__auto_type cn_init_32 = m->fl; __auto_type fl = cn_init_32;
__auto_type cn_init_40 = m->fsw_cc; __auto_type fsw = cn_init_40;
__auto_type cn_init_53 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_53;
__auto_type cn_init_73 = cn_ptr(m,((uint32_t)(vb+136))); unsigned char * vm = cn_init_73;
__auto_type cn_init_86 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_86;
__auto_type cn_init_99 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_99;
__auto_type cn_init_112 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_112;
__auto_type cn_init_125 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_125;
__auto_type cn_init_138 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_138;
__auto_type cn_init_151 = cn_rd64u(m,0x10001078U); uint64_t r15 = cn_init_151;
__auto_type cn_init_164 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_164;
__auto_type cn_init_177 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_177;
__auto_type cn_init_190 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_268;
__auto_type cn_init_281 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_281;
__auto_type cn_init_294 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,0); uint64_t v17 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,8); uint64_t v18 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,16); uint64_t v19 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,24); uint64_t v20 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,32); uint64_t v21 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,40); uint64_t v22 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,48); uint64_t v23 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,56); uint64_t v24 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,64); uint64_t v25 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,72); uint64_t v26 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,80); uint64_t v27 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,88); uint64_t v28 = cn_init_450;
__auto_type cn_init_463 = cn_cell(vm,96); uint64_t v29 = cn_init_463;
__auto_type cn_init_476 = cn_cell(vm,104); uint64_t v30 = cn_init_476;
__auto_type cn_init_489 = cn_cell(vm,120); uint64_t v32 = cn_init_489;
__auto_type cn_init_502 = cn_cell(vm,128); uint64_t v33 = cn_init_502;
__auto_type cn_init_515 = cn_cell(vm,136); uint64_t v34 = cn_init_515;
__auto_type cn_init_528 = cn_cell(vm,144); uint64_t v35 = cn_init_528;
__auto_type cn_init_541 = cn_cell(vm,152); uint64_t v36 = cn_init_541;
__auto_type cn_init_554 = cn_cell(vm,160); uint64_t v37 = cn_init_554;
__auto_type cn_init_567 = cn_cell(vm,168); uint64_t v38 = cn_init_567;
__auto_type cn_init_580 = cn_cell(vm,176); uint64_t v39 = cn_init_580;
__auto_type cn_init_593 = cn_cell(vm,184); uint64_t v40 = cn_init_593;
__auto_type cn_init_606 = cn_cell(vm,192); uint64_t v41 = cn_init_606;
__auto_type cn_init_619 = cn_cell(vm,200); uint64_t v42 = cn_init_619;
__auto_type cn_init_632 = cn_cell(vm,208); uint64_t v43 = cn_init_632;
__auto_type cn_init_645 = cn_cell(vm,216); uint64_t v44 = cn_init_645;
__auto_type cn_init_658 = cn_cell(vm,224); uint64_t v45 = cn_init_658;
__auto_type cn_init_671 = cn_cell(vm,232); uint64_t v46 = cn_init_671;
__auto_type cn_init_684 = cn_cell(vm,240); uint64_t v47 = cn_init_684;
__auto_type cn_init_697 = cn_cell(vm,248); uint64_t v48 = cn_init_697;
__auto_type cn_init_710 = cn_cell(vm,256); uint64_t v49 = cn_init_710;
__auto_type cn_init_723 = cn_cell(vm,264); uint64_t v50 = cn_init_723;
__auto_type cn_init_736 = cn_cell(vm,272); uint64_t v51 = cn_init_736;
__auto_type cn_init_749 = cn_cell(vm,280); uint64_t v52 = cn_init_749;
__auto_type cn_init_762 = cn_cell(vm,288); uint64_t v53 = cn_init_762;
__auto_type cn_init_775 = cn_cell(vm,296); uint64_t v54 = cn_init_775;
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
__auto_type cn_init_850 = 0xffffffaeU; __auto_type bv = cn_init_850;
__auto_type cn_init_858 = rg[4]; __auto_type av = cn_init_858;
__auto_type cn_init_876 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_876;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_905 = r5; uint64_t s = cn_init_905;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_935 = (CN_U2){v28,v29}; CN_U2 s = cn_init_935;
__auto_type cn_init_945 = m->xmm[0]; __auto_type a = cn_init_945;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_1015 = v28; uint64_t s = cn_init_1015;
__auto_type cn_init_1028 = m->xmm[1][0]; __auto_type a = cn_init_1028;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_1075 = (CN_U2){v24,v25}; CN_U2 s = cn_init_1075;
__auto_type cn_init_1085 = m->xmm[0]; __auto_type a = cn_init_1085;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_1155 = v26; uint64_t s = cn_init_1155;
__auto_type cn_init_1168 = m->xmm[1][0]; __auto_type a = cn_init_1168;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_1205 = 0x0U; __auto_type bv = cn_init_1205;
__auto_type cn_init_1222 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_1222;
__auto_type cn_init_1240 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1240;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_1261 = r32; uint64_t s = cn_init_1261;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_1283 = v28; uint64_t s = cn_init_1283;
__auto_type cn_init_1296 = m->xmm[5][0]; __auto_type a = cn_init_1296;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1392 = m->xmm[0][0]; uint64_t v = cn_init_1392;
(s2005=(((s2005&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2006=(((s2006&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1451 = m->xmm[0][1]; uint64_t v = cn_init_1451;
(s2006=(((s2006&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2007=(((s2007&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1510 = m->xmm[1][0]; uint64_t v = cn_init_1510;
(s2007=(((s2007&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2008=(((s2008&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2006>>16))|((s2007<<48))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1672 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1672;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1720 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1720;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1783 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1783;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1846 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1846;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1894 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1894;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1957 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1957;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_2019 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2019;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_2066 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2066;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2128 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2128;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_2171 = cn_bits(f[2]); uint64_t v = cn_init_2171;
(s2005=(((s2005&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2006=(((s2006&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_2229 = cn_bits(f[1]); uint64_t v = cn_init_2229;
(s2006=(((s2006&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2007=(((s2007&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=-f[0]);
{
__auto_type cn_init_2298 = cn_bits(f[0]); uint64_t v = cn_init_2298;
(s2007=(((s2007&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2008=(((s2008&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2006>>16))|((s2007<<48))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2471 = cn_bits(f[0]); uint64_t v = cn_init_2471;
(s2008=(((s2008&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2009=(((s2009&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2553 = cn_double(v41); __auto_type v = cn_init_2553;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2581 = cn_bits(f[0]); uint64_t v = cn_init_2581;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2008>>16))|((s2009<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2760 = cn_double(v32); __auto_type v = cn_init_2760;
(f[1]=(f[1]+v));
}
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2828 = cn_double(v35); __auto_type v = cn_init_2828;
(f[0]=(f[0]-v));
}
goto cn_break_b11;
}
cn_break_b4:;
(f[0]=f[0]);
(f[0]=cn_double(((((((s2008>>16))|((s2009<<48))))&0xffffffffffffffffULL))));
(f[0]=(f[0]+f[0]));
{
__auto_type cn_init_2925 = cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2925;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2949 = cn_double(v36); __auto_type v = cn_init_2949;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(v39));
{
__auto_type cn_init_3001 = cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3001;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_3029 = cn_bits(f[1]); uint64_t v = cn_init_3029;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b6;
}
(f[1]=f[1]);
goto cn_break_b7;
}
cn_break_b6:;
(f[0]=f[1]);
}
cn_break_b7:;
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b9;
}
(f[0]=cn_double(v37));
{
__auto_type cn_init_3288 = cn_double(((((((s2008>>16))|((s2009<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3288;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3362 = cn_double(v38); __auto_type v = cn_init_3362;
(f[0]=(f[0]*v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_3473 = cn_double(v33); __auto_type v = cn_init_3473;
(f[0]=(f[0]+v));
}
goto cn_break_b10;
}
cn_break_b9:;
(f[0]=cn_double(((((((s2008>>16))|((s2009<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3529 = cn_double(v40); __auto_type v = cn_init_3529;
(f[0]=(f[0]-v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_3640 = cn_double(v34); __auto_type v = cn_init_3640;
(f[0]=(f[0]+v));
}
(f[0]=-f[0]);
}
cn_break_b10:;
{
__auto_type cn_init_3680 = cn_bits(f[0]); uint64_t v = cn_init_3680;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_3748 = cn_double(v35); __auto_type v = cn_init_3748;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(v41));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b32;
}
}
cn_break_b11:;
(f[1]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3883 = cn_double(v45); __auto_type v = cn_init_3883;
(f[1]=(f[1]-v));
}
(f[2]=f[1]);
(f[3]=cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3945 = cn_double(v46); __auto_type v = cn_init_3945;
(f[3]=(f[3]+v));
}
(f[4]=f[3]);
(f[2]=(f[2]+f[4]));
cn_swap(f,3,2);
{
__auto_type cn_init_4003 = cn_double(v47); __auto_type v = cn_init_4003;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_4031 = cn_bits(f[3]); uint64_t v = cn_init_4031;
(s2011=(((s2011&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2012=(((s2012&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_4100 = cn_double(v47); __auto_type v = cn_init_4100;
(f[1]=(f[1]*v));
}
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2006>>16))|((s2007<<48))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
{
__auto_type cn_init_4182 = cn_double(v48); __auto_type v = cn_init_4182;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_4235 = cn_double(v49); __auto_type v = cn_init_4235;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4287 = cn_double(v50); __auto_type v = cn_init_4287;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
{
__auto_type cn_init_4369 = cn_double(v54); __auto_type v = cn_init_4369;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4436 = cn_double(v44); __auto_type v = cn_init_4436;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
{
__auto_type cn_init_4474 = cn_double(v44); __auto_type v = cn_init_4474;
(f[2]=(f[2]-v));
}
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b13;
}
(f[2]=f[2]);
goto cn_break_b14;
}
cn_break_b13:;
(f[1]=f[2]);
}
cn_break_b14:;
{
__auto_type cn_init_4597 = cn_bits(f[1]); uint64_t v = cn_init_4597;
(s2011=(((s2011&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2012=(((s2012&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_4651 = cn_double(v35); __auto_type v = cn_init_4651;
(f[1]=(f[1]-v));
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_4689 = cn_double(v35); __auto_type v = cn_init_4689;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4741 = cn_double(v43); __auto_type v = cn_init_4741;
(f[2]=(f[2]-v));
}
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b16;
}
(f[2]=f[2]);
goto cn_break_b17;
}
cn_break_b16:;
(f[1]=f[2]);
}
cn_break_b17:;
(f[2]=cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4888 = cn_double(v42); __auto_type v = cn_init_4888;
(f[2]=(f[2]-v));
}
(f[3]=cn_double(0x0));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b19;
}
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5037 = cn_double(v51); __auto_type v = cn_init_5037;
(f[3]=(f[3]+v));
}
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[2]=sqrt(f[2]));
{
__auto_type cn_init_5105 = cn_double(v34); __auto_type v = cn_init_5105;
(f[2]=(f[2]+v));
}
goto cn_break_b20;
}
cn_break_b19:;
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5176 = cn_double(v53); __auto_type v = cn_init_5176;
(f[3]=(f[3]+v));
}
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[2]=sqrt(f[2]));
{
__auto_type cn_init_5244 = cn_double(v52); __auto_type v = cn_init_5244;
(f[2]=(f[2]-v));
}
}
cn_break_b20:;
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(((((((s2006>>16))|((s2007<<48))))&0xffffffffffffffffULL))));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[2]=sqrt(f[2]));
{
__auto_type cn_init_5356 = cn_double(v36); __auto_type v = cn_init_5356;
(f[2]=(f[2]-v));
}
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b22;
}
(f[2]=f[2]);
goto cn_break_b23;
}
cn_break_b22:;
(f[1]=f[2]);
}
cn_break_b23:;
(f[2]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
(f[2]=-f[2]);
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b25;
}
(f[2]=f[2]);
goto cn_break_b26;
}
cn_break_b25:;
(f[1]=f[2]);
}
cn_break_b26:;
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b28;
}
(f[1]=f[1]);
goto cn_break_b29;
}
cn_break_b28:;
(f[0]=f[1]);
}
cn_break_b29:;
(f[1]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
(f[1]=-f[1]);
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
__auto_type cn_init_5833 = 0x0U; __auto_type bv = cn_init_5833;
__auto_type cn_init_5850 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_5850;
__auto_type cn_init_5868 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_5868;
}
if(cn_cond(fl,5)){
goto cn_break_b34;
}
{
__auto_type cn_init_5892 = cn_double(v28); __auto_type v = cn_init_5892;
(f[0]=(f[0]/v));
}
}
cn_break_b34:;
(r14=cn_bits(f[0]));
(f[0]=cn_double(v30));
(f[1]=(((double)(((int32_t)(((uint32_t)(((((r15>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_5979 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5979;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(r34=cn_bits(f[0]));
{
__auto_type cn_init_6038 = 0x52U; __auto_type bv = cn_init_6038;
__auto_type cn_init_6046 = rg[4]; __auto_type av = cn_init_6046;
__auto_type cn_init_6064 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_6064;
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
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
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
int cn_f_1e0f9a93662cc139(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_190 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_229;
__auto_type cn_init_242 = cn_cell(vm,0); uint64_t v10 = cn_init_242;
__auto_type cn_init_255 = cn_cell(vm,8); uint64_t v11 = cn_init_255;
__auto_type cn_init_268 = cn_cell(vm,16); uint64_t v12 = cn_init_268;
__auto_type cn_init_281 = cn_cell(vm,24); uint64_t v13 = cn_init_281;
__auto_type cn_init_294 = cn_cell(vm,32); uint64_t v14 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,40); uint64_t v15 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,48); uint64_t v16 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,56); uint64_t v17 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,64); uint64_t v18 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,72); uint64_t v19 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,80); uint64_t v20 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,88); uint64_t v21 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,96); uint64_t v22 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,104); uint64_t v23 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,112); uint64_t v24 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,120); uint64_t v25 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,128); uint64_t v26 = cn_init_450;
__auto_type cn_init_463 = cn_cell(vm,136); uint64_t v27 = cn_init_463;
__auto_type cn_init_476 = cn_cell(vm,144); uint64_t v28 = cn_init_476;
__auto_type cn_init_489 = cn_cell(vm,152); uint64_t v29 = cn_init_489;
__auto_type cn_init_502 = cn_cell(vm,160); uint64_t v30 = cn_init_502;
__auto_type cn_init_515 = cn_cell(vm,176); uint64_t v32 = cn_init_515;
__auto_type cn_init_528 = cn_cell(vm,192); uint64_t v34 = cn_init_528;
{
{
{
{
{
{
{
__auto_type cn_init_552 = 0xffffffd0U; __auto_type bv = cn_init_552;
__auto_type cn_init_560 = rg[4]; __auto_type av = cn_init_560;
__auto_type cn_init_578 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_578;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_607 = r5; uint64_t s = cn_init_607;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_637 = (CN_U2){v28,v29}; CN_U2 s = cn_init_637;
__auto_type cn_init_647 = m->xmm[0]; __auto_type a = cn_init_647;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_717 = v28; uint64_t s = cn_init_717;
__auto_type cn_init_730 = m->xmm[1][0]; __auto_type a = cn_init_730;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_777 = (CN_U2){v24,v25}; CN_U2 s = cn_init_777;
__auto_type cn_init_787 = m->xmm[0]; __auto_type a = cn_init_787;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_857 = v26; uint64_t s = cn_init_857;
__auto_type cn_init_870 = m->xmm[1][0]; __auto_type a = cn_init_870;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_924 = 0x1U; __auto_type bv = cn_init_924;
__auto_type cn_init_932 = rg[2]; __auto_type av = cn_init_932;
__auto_type cn_init_950 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_950;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_978 = r32; uint64_t s = cn_init_978;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_1000 = v28; uint64_t s = cn_init_1000;
__auto_type cn_init_1013 = m->xmm[5][0]; __auto_type a = cn_init_1013;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1109 = m->xmm[0][0]; uint64_t v = cn_init_1109;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1168 = m->xmm[0][1]; uint64_t v = cn_init_1168;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1227 = m->xmm[1][0]; uint64_t v = cn_init_1227;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1389 = (((double)(cn_float(((uint32_t)(((((v12>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1389;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1437 = (((double)(cn_float(((uint32_t)(((((v12>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1437;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1500 = (((double)(cn_float(((uint32_t)(((((v11>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1500;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1563 = (((double)(cn_float(((uint32_t)(((((v15>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1563;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1611 = (((double)(cn_float(((uint32_t)(((((v15>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1611;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1674 = (((double)(cn_float(((uint32_t)(((((v14>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1674;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1736 = (((double)(cn_float(((uint32_t)(((((v14>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1736;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1783 = (((double)(cn_float(((uint32_t)(((((v13>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1783;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1845 = (((double)(cn_float(((uint32_t)(((((v13>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1845;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1888 = cn_bits(f[2]); uint64_t v = cn_init_1888;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1946 = cn_bits(f[1]); uint64_t v = cn_init_1946;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_2004 = cn_bits(f[0]); uint64_t v = cn_init_2004;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2247 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2247;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2271 = cn_double(v30); __auto_type v = cn_init_2271;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2339 = 0x41U; __auto_type bv = cn_init_2339;
__auto_type cn_init_2352 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2352;
__auto_type cn_init_2370 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2370;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b7;
}
(f[0]=f[0]);
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2429 = 0x2U; __auto_type bv = cn_init_2429;
__auto_type cn_init_2437 = rg[2]; __auto_type av = cn_init_2437;
__auto_type cn_init_2455 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2455;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b5;
}
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2530 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2530;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2557 = cn_round(m,f[0]); __auto_type x = cn_init_2557;
__auto_type cn_init_2592 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2592;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_2642 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2642;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2721 = cn_double(v32); __auto_type v = cn_init_2721;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2756 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2756;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2796 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2796;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2824 = cn_bits(f[0]); uint64_t v = cn_init_2824;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2922 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2922;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2949 = cn_round(m,f[0]); __auto_type x = cn_init_2949;
__auto_type cn_init_2984 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2984;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_3034 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3034;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3113 = cn_double(v32); __auto_type v = cn_init_3113;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3148 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3148;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3188 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3188;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3216 = cn_bits(f[0]); uint64_t v = cn_init_3216;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3314 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3314;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3341 = cn_round(m,f[0]); __auto_type x = cn_init_3341;
__auto_type cn_init_3376 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3376;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_3426 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3426;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3505 = cn_double(v32); __auto_type v = cn_init_3505;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3540 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3540;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3580 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3580;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3608 = cn_bits(f[0]); uint64_t v = cn_init_3608;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
goto cn_break_b6;
}
cn_break_b5:;
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3710 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3710;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3737 = cn_round(m,f[0]); __auto_type x = cn_init_3737;
__auto_type cn_init_3772 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3772;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_3822 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3822;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_3846 = cn_double(v34); __auto_type v = cn_init_3846;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_3926 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3926;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3966 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3966;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3994 = cn_bits(f[0]); uint64_t v = cn_init_3994;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4092 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4092;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4119 = cn_round(m,f[0]); __auto_type x = cn_init_4119;
__auto_type cn_init_4154 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_4154;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_4204 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_4204;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_4228 = cn_double(v34); __auto_type v = cn_init_4228;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_4308 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_4308;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_4348 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4348;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4376 = cn_bits(f[0]); uint64_t v = cn_init_4376;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4474 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4474;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4501 = cn_round(m,f[0]); __auto_type x = cn_init_4501;
__auto_type cn_init_4536 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_4536;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_4586 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_4586;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_4610 = cn_double(v34); __auto_type v = cn_init_4610;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_4690 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_4690;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_4730 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4730;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4758 = cn_bits(f[0]); uint64_t v = cn_init_4758;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
}
cn_break_b6:;
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_4921 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4921;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_4969 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4969;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_5032 = (((double)(cn_float(((uint32_t)(((((v16>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5032;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_5095 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5095;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_5143 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5143;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_5206 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5206;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_5268 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5268;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_5315 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5315;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_5377 = (((double)(cn_float(((uint32_t)(((((v16>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5377;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_5420 = cn_bits(f[2]); uint64_t v = cn_init_5420;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_5478 = cn_bits(f[1]); uint64_t v = cn_init_5478;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_5536 = cn_bits(f[0]); uint64_t v = cn_init_5536;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_5721 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5721;
(f[0]=(f[0]-v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_5832 = cn_double(v30); __auto_type v = cn_init_5832;
(f[0]=(f[0]-v));
}
}
cn_break_b7:;
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_5869 = 0x1U; __auto_type bv = cn_init_5869;
__auto_type cn_init_5877 = rg[2]; __auto_type av = cn_init_5877;
__auto_type cn_init_5895 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_5895;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b9;
}
{
__auto_type cn_init_5926 = cn_double(v28); __auto_type v = cn_init_5926;
(f[0]=(f[0]/v));
}
}
cn_break_b9:;
(r14=cn_bits(f[0]));
(f[0]=cn_double(((((((v10>>32))|((v11<<32))))&0xffffffffffffffffULL))));
(r34=cn_bits(f[0]));
{
__auto_type cn_init_5996 = 0x30U; __auto_type bv = cn_init_5996;
__auto_type cn_init_6004 = rg[4]; __auto_type av = cn_init_6004;
__auto_type cn_init_6022 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_6022;
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
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_23cd7b4f83b9f0ef(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_24 = m->regs; __auto_type rg = cn_init_24;
__auto_type cn_init_32 = m->fl; __auto_type fl = cn_init_32;
__auto_type cn_init_40 = m->fsw_cc; __auto_type fsw = cn_init_40;
__auto_type cn_init_53 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_53;
__auto_type cn_init_73 = cn_ptr(m,((uint32_t)(vb+104))); unsigned char * vm = cn_init_73;
__auto_type cn_init_86 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_86;
__auto_type cn_init_99 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_99;
__auto_type cn_init_112 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_112;
__auto_type cn_init_125 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_125;
__auto_type cn_init_138 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_138;
__auto_type cn_init_151 = cn_rd64u(m,0x10001078U); uint64_t r15 = cn_init_151;
__auto_type cn_init_164 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_164;
__auto_type cn_init_177 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_177;
__auto_type cn_init_190 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007e98U); uint64_t s2003 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_268;
__auto_type cn_init_281 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_281;
__auto_type cn_init_294 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,0); uint64_t v13 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,8); uint64_t v14 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,16); uint64_t v15 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,24); uint64_t v16 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,32); uint64_t v17 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,40); uint64_t v18 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,48); uint64_t v19 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,56); uint64_t v20 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,64); uint64_t v21 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,72); uint64_t v22 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,80); uint64_t v23 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,88); uint64_t v24 = cn_init_450;
__auto_type cn_init_463 = cn_cell(vm,96); uint64_t v25 = cn_init_463;
__auto_type cn_init_476 = cn_cell(vm,104); uint64_t v26 = cn_init_476;
__auto_type cn_init_489 = cn_cell(vm,112); uint64_t v27 = cn_init_489;
__auto_type cn_init_502 = cn_cell(vm,120); uint64_t v28 = cn_init_502;
__auto_type cn_init_515 = cn_cell(vm,128); uint64_t v29 = cn_init_515;
__auto_type cn_init_528 = cn_cell(vm,136); uint64_t v30 = cn_init_528;
__auto_type cn_init_541 = cn_cell(vm,152); uint64_t v32 = cn_init_541;
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
__auto_type cn_init_574 = 0xffffff9cU; __auto_type bv = cn_init_574;
__auto_type cn_init_582 = rg[4]; __auto_type av = cn_init_582;
__auto_type cn_init_600 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_600;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_629 = r5; uint64_t s = cn_init_629;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_659 = (CN_U2){v28,v29}; CN_U2 s = cn_init_659;
__auto_type cn_init_669 = m->xmm[0]; __auto_type a = cn_init_669;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_739 = v28; uint64_t s = cn_init_739;
__auto_type cn_init_752 = m->xmm[1][0]; __auto_type a = cn_init_752;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_799 = (CN_U2){v24,v25}; CN_U2 s = cn_init_799;
__auto_type cn_init_809 = m->xmm[0]; __auto_type a = cn_init_809;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_879 = v26; uint64_t s = cn_init_879;
__auto_type cn_init_892 = m->xmm[1][0]; __auto_type a = cn_init_892;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_929 = 0x0U; __auto_type bv = cn_init_929;
__auto_type cn_init_946 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_946;
__auto_type cn_init_964 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_964;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_985 = r32; uint64_t s = cn_init_985;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_1007 = v28; uint64_t s = cn_init_1007;
__auto_type cn_init_1020 = m->xmm[5][0]; __auto_type a = cn_init_1020;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(s2003=m->xmm[0][0]);
(s2004=m->xmm[0][1]);
(s2005=m->xmm[1][0]);
(f[0]=cn_double(s2005));
(f[1]=cn_double(s2004));
(f[2]=cn_double(s2003));
(f[3]=f[2]);
{
__auto_type cn_init_1207 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1207;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1255 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1255;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1318 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1318;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1381 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1381;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1429 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1429;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1492 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1492;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1554 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1554;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1601 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1601;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1663 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1663;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(s2003=cn_bits(f[2]));
(s2004=cn_bits(f[1]));
(s2005=cn_bits(f[0]));
(f[0]=cn_double(s2003));
(f[1]=cn_double(v14));
(s2009=cn_bits(f[1]));
(f[2]=cn_double(v32));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
(f[1]=cn_double(v32));
{
__auto_type cn_init_1864 = cn_double(v14); __auto_type v = cn_init_1864;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_1888 = cn_double(v32); __auto_type v = cn_init_1888;
(f[1]=(f[1]+v));
}
(s2009=cn_bits(f[1]));
(f[0]=(f[0]*f[1]));
goto cn_break_b5;
}
cn_break_b4:;
(f[0]=sin(f[0]));
(fsw&=~0x0400);
{
__auto_type cn_init_1961 = cn_double(v14); __auto_type v = cn_init_1961;
(f[0]=(f[0]*v));
}
}
cn_break_b5:;
(f[1]=cn_double(0x3ff71547652b82fe));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_2044_0 = f[2];
__auto_type cn_tuple_2044_1 = f[1];
__auto_type x = cn_tuple_2044_0;
__auto_type y = cn_tuple_2044_1;
__auto_type cn_init_2073 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_2073;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_2105 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_2105;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
(s2003=cn_bits(f[0]));
(f[1]=cn_double(s2004));
(f[2]=cn_double(v13));
(s2010=cn_bits(f[2]));
(f[3]=cn_double(v32));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b7;
}
(f[2]=cn_double(v32));
{
__auto_type cn_init_2375 = cn_double(v13); __auto_type v = cn_init_2375;
(f[2]=(f[2]-v));
}
{
__auto_type cn_init_2399 = cn_double(v32); __auto_type v = cn_init_2399;
(f[2]=(f[2]+v));
}
(s2010=cn_bits(f[2]));
(f[1]=(f[1]*f[2]));
goto cn_break_b8;
}
cn_break_b7:;
(f[1]=sin(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_2472 = cn_double(v13); __auto_type v = cn_init_2472;
(f[1]=(f[1]*v));
}
}
cn_break_b8:;
(f[2]=cn_double(0x3ff71547652b82fe));
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[3]=f[1]);
{
__auto_type cn_tuple_2555_0 = f[3];
__auto_type cn_tuple_2555_1 = f[2];
__auto_type x = cn_tuple_2555_0;
__auto_type y = cn_tuple_2555_1;
__auto_type cn_init_2584 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_2584;
(f[3]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_2616 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_2616;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[3]=(exp2(f[3])-1.0));
(f[2]=(f[2]+f[3]));
(f[2]*=exp2(trunc(f[1])));
cn_swap(f,2,1);
(f[2]=f[2]);
(s2004=cn_bits(f[1]));
(f[0]=(f[0]*f[1]));
(s2006=cn_bits(f[0]));
(f[0]=cn_double(s2003));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2004));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(s2007=cn_bits(f[0]));
(f[0]=cn_double(s2006));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2005));
(f[0]=sin(f[0]));
(fsw&=~0x0400);
{
__auto_type cn_init_2959 = cn_double(v16); __auto_type v = cn_init_2959;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2983 = cn_double(s2006); __auto_type v = cn_init_2983;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b10;
}
{
__auto_type cn_init_3089 = cn_double(s2007); __auto_type v = cn_init_3089;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3113 = cn_double(s2008); __auto_type v = cn_init_3113;
(f[0]=(f[0]/v));
}
goto cn_break_b11;
}
cn_break_b10:;
(f[0]=-f[0]);
{
__auto_type cn_init_3152 = cn_double(s2008); __auto_type v = cn_init_3152;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(s2007));
(f[0]=(f[1]/f[0]));
}
cn_break_b11:;
(f[1]=cn_double(0x3ff71547652b82fe));
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
(f[0]=fabs(f[0]));
(f[1]=cn_double(s2009));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(s2010));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
(f[0]=(f[0]/f[1]));
{
__auto_type cn_init_3351 = cn_double(v15); __auto_type v = cn_init_3351;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_3375 = cn_double(v32); __auto_type v = cn_init_3375;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3394 = 0x0U; __auto_type bv = cn_init_3394;
__auto_type cn_init_3411 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_3411;
__auto_type cn_init_3429 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3429;
}
if(cn_cond(fl,5)){
goto cn_break_b13;
}
{
__auto_type cn_init_3453 = cn_double(v28); __auto_type v = cn_init_3453;
(f[0]=(f[0]/v));
}
}
cn_break_b13:;
(r14=cn_bits(f[0]));
(f[0]=cn_double(v30));
(f[1]=(((double)(((int32_t)(((uint32_t)(((((r15>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_3540 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3540;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(r34=cn_bits(f[0]));
{
__auto_type cn_init_3599 = 0x64U; __auto_type bv = cn_init_3599;
__auto_type cn_init_3607 = rg[4]; __auto_type av = cn_init_3607;
__auto_type cn_init_3625 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3625;
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
cn_wr64u(m,0x10007e98U,s2003);
cn_wr64u(m,0x10007ea0U,s2004);
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_24c113e431dbc7b7(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_24 = m->regs; __auto_type rg = cn_init_24;
__auto_type cn_init_32 = m->fl; __auto_type fl = cn_init_32;
__auto_type cn_init_40 = m->fsw_cc; __auto_type fsw = cn_init_40;
__auto_type cn_init_53 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_53;
__auto_type cn_init_73 = cn_ptr(m,((uint32_t)(vb+208))); unsigned char * vm = cn_init_73;
__auto_type cn_init_86 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_86;
__auto_type cn_init_99 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_99;
__auto_type cn_init_112 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_112;
__auto_type cn_init_125 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_125;
__auto_type cn_init_138 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_138;
__auto_type cn_init_151 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_151;
__auto_type cn_init_164 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_164;
__auto_type cn_init_177 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_177;
__auto_type cn_init_190 = cn_cell(vm,0); uint64_t v26 = cn_init_190;
__auto_type cn_init_203 = cn_cell(vm,8); uint64_t v27 = cn_init_203;
__auto_type cn_init_216 = cn_cell(vm,16); uint64_t v28 = cn_init_216;
__auto_type cn_init_229 = cn_cell(vm,24); uint64_t v29 = cn_init_229;
__auto_type cn_init_242 = cn_cell(vm,32); uint64_t v30 = cn_init_242;
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
__auto_type cn_init_305 = 0xffffffe4U; __auto_type bv = cn_init_305;
__auto_type cn_init_313 = rg[4]; __auto_type av = cn_init_313;
__auto_type cn_init_331 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_331;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_360 = r5; uint64_t s = cn_init_360;
(m->xmm[1]=(CN_U2){s,0});
}
(s2012=m->xmm[0][0]);
(s2013=m->xmm[0][1]);
(s2014=m->xmm[1][0]);
(f[0]=cn_double(s2013));
(f[0]=-f[0]);
(f[1]=cn_double(s2012));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_488 = 0x41U; __auto_type bv = cn_init_488;
__auto_type cn_init_501 = cn_reg_get(rg,4,1); __auto_type av = cn_init_501;
__auto_type cn_init_519 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_519;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(f[1]=-f[1]);
(s2013=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
goto cn_break_b3;
}
cn_break_b2:;
(f[1]=f[1]);
(f[0]=f[0]);
}
cn_break_b3:;
(f[0]=cn_double(s2014));
(f[0]=-f[0]);
(f[1]=cn_double(s2012));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_681 = 0x41U; __auto_type bv = cn_init_681;
__auto_type cn_init_694 = cn_reg_get(rg,4,1); __auto_type av = cn_init_694;
__auto_type cn_init_712 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_712;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b5;
}
(f[1]=-f[1]);
(s2014=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
goto cn_break_b6;
}
cn_break_b5:;
(f[1]=f[1]);
(f[0]=f[0]);
}
cn_break_b6:;
(f[0]=cn_double(s2014));
(f[0]=-f[0]);
(f[1]=cn_double(s2013));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_874 = 0x41U; __auto_type bv = cn_init_874;
__auto_type cn_init_887 = cn_reg_get(rg,4,1); __auto_type av = cn_init_887;
__auto_type cn_init_905 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_905;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[1]=-f[1]);
(s2014=cn_bits(f[1]));
(s2013=cn_bits(f[0]));
goto cn_break_b9;
}
cn_break_b8:;
(f[1]=f[1]);
(f[0]=f[0]);
}
cn_break_b9:;
(f[0]=cn_double(s2013));
(f[1]=cn_double(s2012));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_1056 = 0x41U; __auto_type bv = cn_init_1056;
__auto_type cn_init_1069 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1069;
__auto_type cn_init_1087 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1087;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b11;
}
(s2013=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
goto cn_break_b12;
}
cn_break_b11:;
(f[1]=f[1]);
(f[0]=f[0]);
}
cn_break_b12:;
(f[0]=cn_double(s2014));
(f[1]=cn_double(s2012));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_1227 = 0x41U; __auto_type bv = cn_init_1227;
__auto_type cn_init_1240 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1240;
__auto_type cn_init_1258 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1258;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b14;
}
(s2014=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
goto cn_break_b15;
}
cn_break_b14:;
(f[1]=f[1]);
(f[0]=f[0]);
}
cn_break_b15:;
(f[0]=cn_double(s2014));
(f[1]=cn_double(s2013));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_1398 = 0x41U; __auto_type bv = cn_init_1398;
__auto_type cn_init_1411 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1411;
__auto_type cn_init_1429 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1429;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b17;
}
(s2014=cn_bits(f[1]));
(s2013=cn_bits(f[0]));
goto cn_break_b18;
}
cn_break_b17:;
(f[1]=f[1]);
(f[0]=f[0]);
}
cn_break_b18:;
(f[0]=cn_double(s2012));
{
__auto_type cn_init_1525 = cn_double(v30); __auto_type v = cn_init_1525;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1561 = cn_double(v29); __auto_type v = cn_init_1561;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(s2014));
{
__auto_type cn_init_1597 = cn_double(v28); __auto_type v = cn_init_1597;
(f[2]=(f[2]+v));
}
(f[3]=cn_double(v27));
(f[4]=cn_double(0x0));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_1677 = 0x41U; __auto_type bv = cn_init_1677;
__auto_type cn_init_1690 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1690;
__auto_type cn_init_1708 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1708;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b20;
}
(s2014=cn_bits(f[2]));
(s2013=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
goto cn_break_b27;
}
cn_break_b20:;
(s2014=cn_bits(f[2]));
(f[2]=(f[2]*f[2]));
cn_swap(f,2,1);
(s2013=cn_bits(f[2]));
(f[2]=(f[2]*f[2]));
cn_swap(f,2,0);
(s2012=cn_bits(f[2]));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v26));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_1952 = 0x41U; __auto_type bv = cn_init_1952;
__auto_type cn_init_1965 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1965;
__auto_type cn_init_1983 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1983;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
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
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_2089 = 0x41U; __auto_type bv = cn_init_2089;
__auto_type cn_init_2102 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2102;
__auto_type cn_init_2120 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2120;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b25;
}
(f[0]=f[1]);
goto cn_break_b26;
}
cn_break_b25:;
(f[1]=f[1]);
}
cn_break_b26:;
(f[1]=cn_double(v27));
(f[1]=fabs(f[1]));
(f[0]=(f[1]/f[0]));
(f[1]=f[0]);
{
__auto_type cn_init_2233 = cn_double(s2012); __auto_type v = cn_init_2233;
(f[1]=(f[1]*v));
}
(s2012=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_2278 = cn_double(s2013); __auto_type v = cn_init_2278;
(f[1]=(f[1]*v));
}
(s2013=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_2323 = cn_double(s2014); __auto_type v = cn_init_2323;
(f[1]=(f[1]*v));
}
(s2014=cn_bits(f[1]));
{
__auto_type cn_init_2358 = cn_double(r32); __auto_type v = cn_init_2358;
(f[0]=(f[0]*v));
}
(r32=cn_bits(f[0]));
}
cn_break_b27:;
(f[0]=cn_double(s2012));
(f[1]=cn_double(s2013));
(f[2]=cn_double(s2014));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
{
__auto_type cn_init_2458 = 0x1cU; __auto_type bv = cn_init_2458;
__auto_type cn_init_2466 = rg[4]; __auto_type av = cn_init_2466;
__auto_type cn_init_2484 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2484;
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
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_271e754564d800c8(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_24 = m->regs; __auto_type rg = cn_init_24;
__auto_type cn_init_32 = m->fl; __auto_type fl = cn_init_32;
__auto_type cn_init_40 = m->fsw_cc; __auto_type fsw = cn_init_40;
__auto_type cn_init_53 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_53;
__auto_type cn_init_73 = cn_ptr(m,((uint32_t)(vb+104))); unsigned char * vm = cn_init_73;
__auto_type cn_init_86 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_86;
__auto_type cn_init_99 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_99;
__auto_type cn_init_112 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_112;
__auto_type cn_init_125 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_125;
__auto_type cn_init_138 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_138;
__auto_type cn_init_151 = cn_rd64u(m,0x10001078U); uint64_t r15 = cn_init_151;
__auto_type cn_init_164 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_164;
__auto_type cn_init_177 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_177;
__auto_type cn_init_190 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007e98U); uint64_t s2003 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_268;
__auto_type cn_init_281 = cn_cell(vm,0); uint64_t v13 = cn_init_281;
__auto_type cn_init_294 = cn_cell(vm,8); uint64_t v14 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,16); uint64_t v15 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,24); uint64_t v16 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,32); uint64_t v17 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,40); uint64_t v18 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,48); uint64_t v19 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,56); uint64_t v20 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,64); uint64_t v21 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,72); uint64_t v22 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,80); uint64_t v23 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,88); uint64_t v24 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,96); uint64_t v25 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,104); uint64_t v26 = cn_init_450;
__auto_type cn_init_463 = cn_cell(vm,112); uint64_t v27 = cn_init_463;
__auto_type cn_init_476 = cn_cell(vm,120); uint64_t v28 = cn_init_476;
__auto_type cn_init_489 = cn_cell(vm,128); uint64_t v29 = cn_init_489;
__auto_type cn_init_502 = cn_cell(vm,136); uint64_t v30 = cn_init_502;
__auto_type cn_init_515 = cn_cell(vm,152); uint64_t v32 = cn_init_515;
{
{
{
{
{
{
__auto_type cn_init_536 = 0xffffff9cU; __auto_type bv = cn_init_536;
__auto_type cn_init_544 = rg[4]; __auto_type av = cn_init_544;
__auto_type cn_init_562 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_562;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_591 = r5; uint64_t s = cn_init_591;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_621 = (CN_U2){v28,v29}; CN_U2 s = cn_init_621;
__auto_type cn_init_631 = m->xmm[0]; __auto_type a = cn_init_631;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_701 = v28; uint64_t s = cn_init_701;
__auto_type cn_init_714 = m->xmm[1][0]; __auto_type a = cn_init_714;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_761 = (CN_U2){v24,v25}; CN_U2 s = cn_init_761;
__auto_type cn_init_771 = m->xmm[0]; __auto_type a = cn_init_771;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_841 = v26; uint64_t s = cn_init_841;
__auto_type cn_init_854 = m->xmm[1][0]; __auto_type a = cn_init_854;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_891 = 0x0U; __auto_type bv = cn_init_891;
__auto_type cn_init_908 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_908;
__auto_type cn_init_926 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_926;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_947 = r32; uint64_t s = cn_init_947;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_969 = v28; uint64_t s = cn_init_969;
__auto_type cn_init_982 = m->xmm[5][0]; __auto_type a = cn_init_982;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(s2003=m->xmm[0][0]);
(s2004=m->xmm[0][1]);
(s2005=m->xmm[1][0]);
(f[0]=cn_double(s2005));
(f[1]=cn_double(s2004));
(f[2]=cn_double(s2003));
(f[3]=f[2]);
{
__auto_type cn_init_1169 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1169;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1217 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1217;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1280 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1280;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1343 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1343;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1391 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1391;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1454 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1454;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1516 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1516;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1563 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1563;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1625 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1625;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(s2003=cn_bits(f[2]));
(s2004=cn_bits(f[1]));
(s2005=cn_bits(f[0]));
(f[0]=cn_double(s2003));
(f[1]=cn_double(s2004));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1739 = cn_double(v13); __auto_type v = cn_init_1739;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1769_0 = sin(f[0]);
__auto_type cn_tuple_1769_1 = cos(f[0]);
__auto_type s = cn_tuple_1769_0;
__auto_type c = cn_tuple_1769_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2006=cn_bits(f[1]));
(s2007=cn_bits(f[0]));
(f[0]=cn_double(s2003));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2004));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=f[0]);
{
__auto_type cn_init_1915 = cn_double(s2006); __auto_type v = cn_init_1915;
(f[1]=(f[1]*v));
}
(s2004=cn_bits(f[1]));
{
__auto_type cn_init_1950 = cn_double(s2007); __auto_type v = cn_init_1950;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1974 = cn_double(v14); __auto_type v = cn_init_1974;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(0x3ff71547652b82fe));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_2056_0 = f[2];
__auto_type cn_tuple_2056_1 = f[1];
__auto_type x = cn_tuple_2056_0;
__auto_type y = cn_tuple_2056_1;
__auto_type cn_init_2085 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_2085;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_2117 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_2117;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
(s2003=cn_bits(f[0]));
(f[1]=cn_double(s2004));
{
__auto_type cn_init_2270 = cn_double(v14); __auto_type v = cn_init_2270;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(0x3ff71547652b82fe));
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[3]=f[1]);
{
__auto_type cn_tuple_2352_0 = f[3];
__auto_type cn_tuple_2352_1 = f[2];
__auto_type x = cn_tuple_2352_0;
__auto_type y = cn_tuple_2352_1;
__auto_type cn_init_2381 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_2381;
(f[3]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_2413 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_2413;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[3]=(exp2(f[3])-1.0));
(f[2]=(f[2]+f[3]));
(f[2]*=exp2(trunc(f[1])));
cn_swap(f,2,1);
(f[2]=f[2]);
(s2004=cn_bits(f[1]));
(f[0]=(f[0]*f[1]));
(s2006=cn_bits(f[0]));
(f[0]=cn_double(s2003));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2004));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(s2007=cn_bits(f[0]));
(f[0]=cn_double(s2006));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2005));
(f[0]=sin(f[0]));
(fsw&=~0x0400);
{
__auto_type cn_init_2756 = cn_double(v16); __auto_type v = cn_init_2756;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2780 = cn_double(s2006); __auto_type v = cn_init_2780;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
{
__auto_type cn_init_2886 = cn_double(s2007); __auto_type v = cn_init_2886;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2910 = cn_double(s2008); __auto_type v = cn_init_2910;
(f[0]=(f[0]/v));
}
goto cn_break_b5;
}
cn_break_b4:;
(f[0]=-f[0]);
{
__auto_type cn_init_2949 = cn_double(s2008); __auto_type v = cn_init_2949;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(s2007));
(f[0]=(f[1]/f[0]));
}
cn_break_b5:;
(f[1]=cn_double(0x3ff71547652b82fe));
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
{
__auto_type cn_init_3036 = cn_double(v14); __auto_type v = cn_init_3036;
(f[0]=(f[0]/v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_3074 = cn_double(v15); __auto_type v = cn_init_3074;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_3098 = cn_double(v32); __auto_type v = cn_init_3098;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3117 = 0x0U; __auto_type bv = cn_init_3117;
__auto_type cn_init_3134 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_3134;
__auto_type cn_init_3152 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3152;
}
if(cn_cond(fl,5)){
goto cn_break_b7;
}
{
__auto_type cn_init_3176 = cn_double(v28); __auto_type v = cn_init_3176;
(f[0]=(f[0]/v));
}
}
cn_break_b7:;
(r14=cn_bits(f[0]));
(f[0]=cn_double(v30));
(f[1]=(((double)(((int32_t)(((uint32_t)(((((r15>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_3263 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3263;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(r34=cn_bits(f[0]));
{
__auto_type cn_init_3322 = 0x64U; __auto_type bv = cn_init_3322;
__auto_type cn_init_3330 = rg[4]; __auto_type av = cn_init_3330;
__auto_type cn_init_3348 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3348;
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
cn_wr64u(m,0x10007e98U,s2003);
cn_wr64u(m,0x10007ea0U,s2004);
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_29261967e8153d83(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;
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
__auto_type cn_init_97 = rg[7]; __auto_type v = cn_init_97;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_118 = rg[6]; __auto_type v = cn_init_118;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_139 = rg[3]; __auto_type v = cn_init_139;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_157 = 0xd4U; __auto_type bv = cn_init_157;
__auto_type cn_init_165 = rg[4]; __auto_type av = cn_init_165;
__auto_type cn_init_183 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_183;
(rg[4]=r);
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[4]+0xe8U))));
(rg[0]=cn_rd32u(m,((uint32_t)(rg[0]+0x30U))));
{
__auto_type cn_init_245 = ((uint32_t)(rg[4]+0x6cU)); __auto_type a = cn_init_245;
cn_wr32u(m,a,rg[0]);
}
(rg[3]=cn_rd32u(m,((uint32_t)(rg[4]+0xe8U))));
(f[0]=cn_rdf64u(m,((uint32_t)(rg[0]+0xffffffe8U))));
(f[1]=cn_rdf64u(m,((uint32_t)(rg[3]+0xffffffe0U))));
(f[1]=(f[1]*f[0]));
{
__auto_type cn_init_352 = cn_rdf64u(m,((uint32_t)(rg[0]+0xffffffe0U))); __auto_type v = cn_init_352;
(f[1]=(f[1]-v));
}
(f[2]=cn_rdf64u(m,((uint32_t)(rg[3]+0xffffffe8U))));
(f[2]=(f[2]*f[0]));
{
__auto_type cn_init_419 = cn_rdf64u(m,((uint32_t)(rg[0]+0xffffffd8U))); __auto_type v = cn_init_419;
(f[2]=(f[2]-v));
}
cn_swap(f,2,0);
{
__auto_type cn_init_460 = cn_rdf64u(m,((uint32_t)(rg[3]+0xfffffff0U))); __auto_type v = cn_init_460;
(f[2]=(f[2]*v));
}
(rg[3]=rg[0]);
{
__auto_type cn_init_502 = cn_rdf64u(m,((uint32_t)(rg[0]+0xffffffd0U))); __auto_type v = cn_init_502;
(f[2]=(f[2]-v));
}
(f[3]=f[1]);
(f[3]=(f[3]+f[0]));
(f[3]=(f[3]+f[2]));
{
__auto_type cn_init_574 = cn_rdf64u(m,((uint32_t)(rg[0]+0x0U))); __auto_type v = cn_init_574;
(f[3]=(f[3]*v));
}
cn_wr16u(m,((uint32_t)(rg[4]+200)),m->cw);
{
__auto_type cn_init_629 = (((uint32_t)(cn_rd16u(m,((uint32_t)(rg[4]+0xc8U)))))); __auto_type v = cn_init_629;
cn_reg_set(rg,0,2,v);
}
{
__auto_type cn_init_649 = 0x4U; __auto_type bv = cn_init_649;
__auto_type cn_init_662 = cn_reg_get(rg,4,1); __auto_type av = cn_init_662;
__auto_type cn_init_680 = cn_alu(&fl,Alu_Or,av,bv,1); __auto_type r = cn_init_680;
cn_reg_set(rg,4,1,r);
}
{
__auto_type cn_init_708 = cn_reg_get(rg,0,2); __auto_type v = cn_init_708;
{
__auto_type cn_init_722 = ((uint32_t)(rg[4]+0xc0U)); __auto_type a = cn_init_722;
cn_wr16u(m,a,((uint16_t)(v)));
}
}
(m->cw=cn_rd16u(m,((uint32_t)(rg[4]+192))));
(rg[0]=cn_rd32u(m,((uint32_t)(rg[4]+0xc8U))));
(f[4]=f[1]);
(f[4]=(f[4]+f[3]));
{
__auto_type cn_init_813 = ((uint32_t)(rg[4]+0xb8U)); __auto_type a = cn_init_813;
cn_wrf64u(m,a,f[4]);
}
(f[4]=cn_rdf64u(m,((uint32_t)(rg[4]+0xb8U))));
{
__auto_type cn_init_860 = ((uint32_t)(rg[4]+0xc8U)); __auto_type a = cn_init_860;
cn_fstoreu(m,FKind_I32,a,f[4]);
}
(rg[1]=cn_rd32u(m,((uint32_t)(rg[4]+0xc8U))));
{
__auto_type cn_init_911 = ((uint32_t)(rg[4]+0x68U)); __auto_type a = cn_init_911;
cn_wr32u(m,a,rg[1]);
}
(f[4]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x68U))));
(f[5]=f[0]);
(f[5]=(f[5]+f[3]));
{
__auto_type cn_init_987 = ((uint32_t)(rg[4]+0xc0U)); __auto_type a = cn_init_987;
cn_wrf64u(m,a,f[5]);
}
(f[5]=cn_rdf64u(m,((uint32_t)(rg[4]+0xc0U))));
{
__auto_type cn_init_1034 = ((uint32_t)(rg[4]+0xc8U)); __auto_type a = cn_init_1034;
cn_fstoreu(m,FKind_I32,a,f[5]);
}
(rg[1]=cn_rd32u(m,((uint32_t)(rg[4]+0xc8U))));
{
__auto_type cn_init_1085 = ((uint32_t)(rg[4]+0x54U)); __auto_type a = cn_init_1085;
cn_wr32u(m,a,rg[1]);
}
(f[5]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x54U))));
cn_swap(f,5,3);
(f[5]=(f[5]+f[2]));
{
__auto_type cn_init_1160 = ((uint32_t)(rg[4]+0xc8U)); __auto_type a = cn_init_1160;
cn_wrf64u(m,a,f[5]);
}
(f[5]=cn_rdf64u(m,((uint32_t)(rg[4]+0xc8U))));
{
__auto_type cn_init_1207 = ((uint32_t)(rg[4]+0xb4U)); __auto_type a = cn_init_1207;
cn_fstoreu(m,FKind_I32,a,f[5]);
}
(rg[1]=cn_rd32u(m,((uint32_t)(rg[4]+0xb4U))));
{
__auto_type cn_init_1258 = cn_reg_get(rg,0,2); __auto_type v = cn_init_1258;
{
__auto_type cn_init_1272 = ((uint32_t)(rg[4]+0xb4U)); __auto_type a = cn_init_1272;
cn_wr16u(m,a,((uint16_t)(v)));
}
}
{
__auto_type cn_init_1299 = ((uint32_t)(rg[4]+0x38U)); __auto_type a = cn_init_1299;
cn_wr32u(m,a,rg[1]);
}
(f[5]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x38U))));
(m->cw=cn_rd16u(m,((uint32_t)(rg[4]+180))));
(f[6]=cn_rdf64u(m,((uint32_t)(rg[3]+0x8U))));
(f[7]=f[4]);
(f[7]=(f[7]+f[3]));
{
__auto_type cn_init_1409 = rg[2]; __auto_type bv = cn_init_1409;
__auto_type cn_init_1417 = rg[2]; __auto_type av = cn_init_1417;
__auto_type cn_init_1435 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_1435;
(rg[2]=r);
}
{
__auto_type cn_init_1449 = 0x1U; __auto_type v = cn_init_1449;
(rg[3]=v);
}
(rg[6]=rg[3]);
(f[7]=(f[7]+f[5]));
(f[7]=(f[7]*f[6]));
cn_swap(f,7,1);
(f[4]=(f[7]-f[4]));
cn_swap(f,6,4);
(f[6]=(f[6]+f[1]));
cn_swap(f,6,3);
(f[0]=(f[0]-f[6]));
cn_swap(f,5,0);
(f[5]=(f[5]+f[1]));
cn_swap(f,5,2);
(f[0]=(f[5]-f[0]));
cn_swap(f,4,0);
(f[1]=(f[1]+f[4]));
cn_swap(f,3,2);
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_swap(f,3,1);
{
__auto_type cn_init_1702 = 0x5U; __auto_type bv = cn_init_1702;
__auto_type cn_init_1715 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1715;
cn_alu(&fl,Alu_And,av,bv,1);
}
cn_reg_set(rg,2,1,((uint32_t)(cn_cond(fl,5))));
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_swap(f,3,2);
{
__auto_type cn_init_1806 = rg[1]; __auto_type bv = cn_init_1806;
__auto_type cn_init_1814 = rg[1]; __auto_type av = cn_init_1814;
__auto_type cn_init_1832 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_1832;
(rg[1]=r);
}
{
__auto_type cn_init_1846 = 0x5U; __auto_type bv = cn_init_1846;
__auto_type cn_init_1859 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1859;
cn_alu(&fl,Alu_And,av,bv,1);
}
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_reg_set(rg,1,1,((uint32_t)(cn_cond(fl,5))));
{
__auto_type cn_init_1938 = 0x5U; __auto_type bv = cn_init_1938;
__auto_type cn_init_1951 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1951;
cn_alu(&fl,Alu_And,av,bv,1);
}
cn_reg_set(rg,0,1,((uint32_t)(cn_cond(fl,5))));
{
__auto_type cn_init_1993 = 0xffU; __auto_type bv = cn_init_1993;
__auto_type cn_init_2001 = rg[0]; __auto_type av = cn_init_2001;
__auto_type cn_init_2019 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2019;
(rg[0]=r);
}
{
__auto_type cn_init_2036 = rg[0]; __auto_type bv = cn_init_2036;
__auto_type cn_init_2044 = rg[6]; __auto_type av = cn_init_2044;
__auto_type cn_init_2062 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_2062;
(rg[6]=r);
}
(rg[7]=rg[6]);
(rg[6]=rg[3]);
{
__auto_type cn_init_2099 = rg[1]; __auto_type bv = cn_init_2099;
__auto_type cn_init_2107 = rg[3]; __auto_type av = cn_init_2107;
__auto_type cn_init_2125 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_2125;
(rg[3]=r);
}
{
__auto_type cn_init_2142 = rg[2]; __auto_type bv = cn_init_2142;
__auto_type cn_init_2150 = rg[6]; __auto_type av = cn_init_2150;
__auto_type cn_init_2168 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_2168;
(rg[6]=r);
}
{
__auto_type cn_init_2202 = ((((int64_t)(((int32_t)(rg[3])))))*(((int64_t)(((int32_t)(rg[0])))))); __auto_type product = cn_init_2202;
(rg[3]=((uint32_t)(product)));
(fl.cf=(product!=(((int64_t)(((int32_t)(product)))))));
(fl.of=fl.cf);
}
(f[4]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_2260 = ((uint32_t)(rg[4]+0x48U)); __auto_type a = cn_init_2260;
cn_wr32u(m,a,rg[3]);
}
(rg[3]=((uint32_t)(rg[2]+0xffffffffU)));
{
__auto_type cn_init_2314 = ((((int64_t)(((int32_t)(rg[3])))))*(((int64_t)(((int32_t)(rg[0])))))); __auto_type product = cn_init_2314;
(rg[3]=((uint32_t)(product)));
(fl.cf=(product!=(((int64_t)(((int32_t)(product)))))));
(fl.of=fl.cf);
}
{
__auto_type cn_init_2354 = fl.cf; __auto_type cf = cn_init_2354;
__auto_type cn_init_2375 = cn_alu(&fl,Alu_Add,rg[3],1,4); __auto_type r = cn_init_2375;
(fl.cf=cf);
(rg[3]=r);
}
{
__auto_type cn_init_2397 = fl.cf; __auto_type cf = cn_init_2397;
__auto_type cn_init_2418 = cn_alu(&fl,Alu_Sub,rg[0],1,4); __auto_type r = cn_init_2418;
(fl.cf=cf);
(rg[0]=r);
}
{
__auto_type cn_init_2446 = ((uint32_t)(rg[4]+0x3cU)); __auto_type a = cn_init_2446;
cn_wr32u(m,a,rg[3]);
}
(rg[3]=((uint32_t)(rg[1]+0xffffffffU)));
{
__auto_type cn_init_2500 = ((((int64_t)(((int32_t)(rg[7])))))*(((int64_t)(((int32_t)(rg[2])))))); __auto_type product = cn_init_2500;
(rg[7]=((uint32_t)(product)));
(fl.cf=(product!=(((int64_t)(((int32_t)(product)))))));
(fl.of=fl.cf);
}
{
__auto_type cn_init_2558 = ((((int64_t)(((int32_t)(rg[2])))))*(((int64_t)(((int32_t)(rg[3])))))); __auto_type product = cn_init_2558;
(rg[2]=((uint32_t)(product)));
(fl.cf=(product!=(((int64_t)(((int32_t)(product)))))));
(fl.of=fl.cf);
}
{
__auto_type cn_init_2616 = ((((int64_t)(((int32_t)(rg[6])))))*(((int64_t)(((int32_t)(rg[1])))))); __auto_type product = cn_init_2616;
(rg[6]=((uint32_t)(product)));
(fl.cf=(product!=(((int64_t)(((int32_t)(product)))))));
(fl.of=fl.cf);
}
{
__auto_type cn_init_2674 = ((((int64_t)(((int32_t)(rg[1])))))*(((int64_t)(((int32_t)(rg[0])))))); __auto_type product = cn_init_2674;
(rg[1]=((uint32_t)(product)));
(fl.cf=(product!=(((int64_t)(((int32_t)(product)))))));
(fl.of=fl.cf);
}
(f[5]=f[0]);
(f[5]=(f[5]+f[3]));
(rg[3]=((uint32_t)(rg[2]+0x1U)));
(rg[5]=rg[6]);
{
__auto_type cn_init_2770 = ((uint32_t)(rg[4]+0x4cU)); __auto_type a = cn_init_2770;
cn_wr32u(m,a,rg[3]);
}
(rg[0]=((uint32_t)(rg[1]+0x1U)));
{
__auto_type cn_init_2807 = rg[7]; __auto_type bv = cn_init_2807;
__auto_type cn_init_2815 = rg[7]; __auto_type av = cn_init_2815;
cn_alu(&fl,Alu_And,av,bv,4);
}
{
__auto_type cn_init_2845 = ((uint32_t)(rg[4]+0x20U)); __auto_type a = cn_init_2845;
cn_wrf64u(m,a,f[5]);
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
(f[5]=(f[5]-f[4]));
{
__auto_type cn_init_2928 = ((uint32_t)(rg[4]+0x20U)); __auto_type a = cn_init_2928;
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
(f[5]=f[0]);
(f[5]=(f[5]+f[1]));
{
__auto_type cn_init_3021 = rg[5]; __auto_type bv = cn_init_3021;
__auto_type cn_init_3029 = rg[5]; __auto_type av = cn_init_3029;
cn_alu(&fl,Alu_And,av,bv,4);
}
{
__auto_type cn_init_3059 = ((uint32_t)(rg[4]+0x30U)); __auto_type a = cn_init_3059;
cn_wrf64u(m,a,f[5]);
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=5);
continue;
}
(b=4);
}
break;
case 4:
{
(f[5]=(f[5]-f[4]));
{
__auto_type cn_init_3142 = ((uint32_t)(rg[4]+0x30U)); __auto_type a = cn_init_3142;
cn_wrf64u(m,a,f[5]);
}
cn_swap(f,4,0);
(steps+=1);
if((steps>limit)){
return 1;
}
(b=6);
continue;
}
break;
case 5:
{
(f[5]=f[5]);
cn_swap(f,4,0);
(b=6);
}
break;
case 6:
{
(f[4]=(f[4]+f[2]));
(rg[3]=cn_rd32u(m,((uint32_t)(rg[4]+0x48U))));
{
__auto_type cn_init_3263 = rg[3]; __auto_type bv = cn_init_3263;
__auto_type cn_init_3271 = rg[3]; __auto_type av = cn_init_3271;
cn_alu(&fl,Alu_And,av,bv,4);
}
{
__auto_type cn_init_3301 = ((uint32_t)(rg[4]+0x28U)); __auto_type a = cn_init_3301;
cn_wrf64u(m,a,f[4]);
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=8);
continue;
}
(b=7);
}
break;
case 7:
{
(f[4]=(f[4]-f[0]));
{
__auto_type cn_init_3384 = ((uint32_t)(rg[4]+0x28U)); __auto_type a = cn_init_3384;
cn_wrf64u(m,a,f[4]);
}
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
(b=9);
}
break;
case 9:
{
(rg[3]=cn_rd32u(m,((uint32_t)(rg[4]+0x6cU))));
(rg[1]=cn_rd32u(m,((uint32_t)(rg[4]+0x3cU))));
{
__auto_type cn_init_3492 = rg[1]; __auto_type bv = cn_init_3492;
__auto_type cn_init_3500 = rg[1]; __auto_type av = cn_init_3500;
cn_alu(&fl,Alu_And,av,bv,4);
}
(f[4]=cn_rdf64u(m,((uint32_t)(rg[3]+0x0U))));
(f[5]=f[3]);
(f[5]=(f[5]+f[4]));
{
__auto_type cn_init_3575 = ((uint32_t)(rg[4]+0x80U)); __auto_type a = cn_init_3575;
cn_wrf64u(m,a,f[5]);
}
if(cn_cond(fl,4)){
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
(f[5]=(f[5]-f[0]));
{
__auto_type cn_init_3658 = ((uint32_t)(rg[4]+0x80U)); __auto_type a = cn_init_3658;
cn_wrf64u(m,a,f[5]);
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
(f[5]=f[5]);
(b=12);
}
break;
case 12:
{
(f[5]=f[1]);
(f[5]=(f[5]+f[4]));
(rg[2]=cn_rd32u(m,((uint32_t)(rg[4]+0x4cU))));
{
__auto_type cn_init_3771 = rg[2]; __auto_type bv = cn_init_3771;
__auto_type cn_init_3779 = rg[2]; __auto_type av = cn_init_3779;
cn_alu(&fl,Alu_And,av,bv,4);
}
{
__auto_type cn_init_3809 = ((uint32_t)(rg[4]+0x90U)); __auto_type a = cn_init_3809;
cn_wrf64u(m,a,f[5]);
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
(f[5]=(f[5]-f[0]));
{
__auto_type cn_init_3892 = ((uint32_t)(rg[4]+0x90U)); __auto_type a = cn_init_3892;
cn_wrf64u(m,a,f[5]);
}
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
(f[5]=f[5]);
(b=15);
}
break;
case 15:
{
(f[4]=(f[4]+f[2]));
{
__auto_type cn_init_3975 = rg[0]; __auto_type bv = cn_init_3975;
__auto_type cn_init_3983 = rg[0]; __auto_type av = cn_init_3983;
cn_alu(&fl,Alu_And,av,bv,4);
}
{
__auto_type cn_init_4013 = ((uint32_t)(rg[4]+0x88U)); __auto_type a = cn_init_4013;
cn_wrf64u(m,a,f[4]);
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
(f[0]=(f[4]-f[0]));
cn_swap(f,3,0);
{
__auto_type cn_init_4105 = ((uint32_t)(rg[4]+0x88U)); __auto_type a = cn_init_4105;
cn_wrf64u(m,a,f[3]);
}
cn_swap(f,2,1);
cn_swap(f,2,0);
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
(f[4]=f[4]);
(f[0]=f[3]);
cn_swap(f,2,1);
cn_swap(f,2,0);
(b=18);
}
break;
case 18:
{
(f[3]=cn_double(0x0));
(rg[3]=cn_rd32u(m,((uint32_t)(rg[4]+0x6cU))));
(rg[1]=cn_rd32u(m,((uint32_t)(rg[4]+0x68U))));
{
__auto_type cn_init_4276 = ((uint32_t)(rg[4]+0x0U)); __auto_type a = cn_init_4276;
cn_wrf64u(m,a,f[3]);
}
(f[3]=cn_rdf64u(m,((uint32_t)(rg[3]+0x10U))));
(f[4]=f[2]);
(f[4]=(f[4]+f[3]));
(rg[2]=cn_rd32u(m,((uint32_t)(rg[4]+0x3cU))));
{
__auto_type cn_init_4363 = rg[1]; __auto_type bv = cn_init_4363;
__auto_type cn_init_4371 = rg[2]; __auto_type av = cn_init_4371;
__auto_type cn_init_4389 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_4389;
(rg[2]=r);
}
(rg[6]=cn_rd32u(m,((uint32_t)(rg[4]+0x38U))));
{
__auto_type cn_init_4431 = ((uint32_t)(rg[4]+0xa0U)); __auto_type a = cn_init_4431;
cn_wr32u(m,a,rg[2]);
}
(rg[2]=cn_rd32u(m,((uint32_t)(rg[4]+0x4cU))));
{
__auto_type cn_init_4483 = cn_rd32u(m,((uint32_t)(rg[4]+0x54U))); __auto_type bv = cn_init_4483;
__auto_type cn_init_4491 = rg[2]; __auto_type av = cn_init_4491;
__auto_type cn_init_4509 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_4509;
(rg[2]=r);
}
{
__auto_type cn_init_4526 = rg[1]; __auto_type bv = cn_init_4526;
__auto_type cn_init_4534 = rg[7]; __auto_type av = cn_init_4534;
__auto_type cn_init_4552 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_4552;
(rg[7]=r);
}
{
__auto_type cn_init_4574 = ((uint32_t)(rg[4]+0x70U)); __auto_type a = cn_init_4574;
cn_wrf64u(m,a,f[4]);
}
(f[4]=f[0]);
(f[4]=(f[4]+f[3]));
{
__auto_type cn_init_4626 = ((uint32_t)(rg[4]+0xa4U)); __auto_type a = cn_init_4626;
cn_wr32u(m,a,rg[2]);
}
(rg[2]=rg[0]);
{
__auto_type cn_init_4658 = rg[6]; __auto_type bv = cn_init_4658;
__auto_type cn_init_4666 = rg[2]; __auto_type av = cn_init_4666;
__auto_type cn_init_4684 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_4684;
(rg[2]=r);
}
{
__auto_type cn_init_4706 = ((uint32_t)(rg[4]+0xa8U)); __auto_type a = cn_init_4706;
cn_wr32u(m,a,rg[2]);
}
{
__auto_type cn_init_4733 = ((uint32_t)(rg[4]+0x58U)); __auto_type a = cn_init_4733;
cn_wrf64u(m,a,f[4]);
}
(f[4]=f[1]);
(f[4]=(f[4]+f[3]));
{
__auto_type cn_init_4785 = ((uint32_t)(rg[4]+0x60U)); __auto_type a = cn_init_4785;
cn_wrf64u(m,a,f[4]);
}
(f[4]=cn_rdf64u(m,((uint32_t)(rg[3]+0xffffffb8U))));
(f[5]=f[0]);
(f[5]=(f[5]*f[0]));
(rg[3]=cn_rd32u(m,((uint32_t)(rg[4]+0x54U))));
{
__auto_type cn_init_4877 = ((uint32_t)(rg[4]+0xacU)); __auto_type a = cn_init_4877;
cn_wr32u(m,a,rg[3]);
}
{
__auto_type cn_init_4899 = rg[3]; __auto_type bv = cn_init_4899;
__auto_type cn_init_4907 = rg[3]; __auto_type av = cn_init_4907;
__auto_type cn_init_4925 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_4925;
(rg[3]=r);
}
(f[6]=f[2]);
(f[6]=(f[6]*f[2]));
(f[5]=(f[5]+f[6]));
(f[6]=f[1]);
(f[6]=(f[6]*f[1]));
(f[5]=(f[5]+f[6]));
(f[5]=(f[4]-f[5]));
(f[6]=cn_rdf64u(m,((uint32_t)(rg[4]+0x30U))));
(f[7]=f[6]);
(f[6]=(f[6]*f[7]));
(f[7]=cn_rdf64u(m,((uint32_t)(rg[4]+0x20U))));
(f[7]=(f[7]*f[7]));
(f[6]=(f[6]+f[7]));
(f[7]=cn_rdf64u(m,((uint32_t)(rg[4]+0x28U))));
(f[7]=(f[7]*f[7]));
(f[6]=(f[6]+f[7]));
(f[6]=(f[4]-f[6]));
{
__auto_type cn_init_5202 = ((uint32_t)(rg[4]+0x40U)); __auto_type a = cn_init_5202;
cn_wrf64u(m,a,f[6]);
}
(f[6]=cn_rdf64u(m,((uint32_t)(rg[4]+0x90U))));
(f[7]=f[6]);
(f[6]=(f[6]*f[7]));
(f[7]=cn_rdf64u(m,((uint32_t)(rg[4]+0x80U))));
(f[7]=(f[7]*f[7]));
(f[6]=(f[6]+f[7]));
(f[7]=cn_rdf64u(m,((uint32_t)(rg[4]+0x88U))));
(f[7]=(f[7]*f[7]));
(f[6]=(f[6]+f[7]));
(f[6]=(f[4]-f[6]));
{
__auto_type cn_init_5389 = ((uint32_t)(rg[4]+0x98U)); __auto_type a = cn_init_5389;
cn_wrf64u(m,a,f[6]);
}
(f[6]=cn_rdf64u(m,((uint32_t)(rg[4]+0x70U))));
(f[7]=f[6]);
(f[6]=(f[6]*f[7]));
(f[7]=cn_rdf64u(m,((uint32_t)(rg[4]+0x58U))));
(f[7]=(f[7]*f[7]));
(f[6]=(f[6]+f[7]));
(f[7]=cn_rdf64u(m,((uint32_t)(rg[4]+0x60U))));
(f[7]=(f[7]*f[7]));
(f[6]=(f[6]+f[7]));
(f[4]=(f[4]-f[6]));
cn_swap(f,5,4);
{
__auto_type cn_init_5585 = ((uint32_t)(rg[4]+0x78U)); __auto_type a = cn_init_5585;
cn_wrf64u(m,a,f[5]);
}
(f[5]=cn_rdf64u(m,((uint32_t)(rg[4]+0x0U))));
{
__auto_type cn_init_5632 = ((uint32_t)(rg[4]+0x8U)); __auto_type a = cn_init_5632;
cn_wrf64u(m,a,f[5]);
}
{
__auto_type cn_init_5659 = ((uint32_t)(rg[4]+0x10U)); __auto_type a = cn_init_5659;
cn_wrf64u(m,a,f[5]);
}
{
__auto_type cn_init_5686 = ((uint32_t)(rg[4]+0x18U)); __auto_type a = cn_init_5686;
cn_wrf64u(m,a,f[5]);
}
{
__auto_type cn_init_5713 = ((uint32_t)(rg[4]+0x4cU)); __auto_type a = cn_init_5713;
cn_wr32u(m,a,rg[7]);
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[4]+0x54U))));
{
__auto_type cn_init_5755 = rg[0]; __auto_type bv = cn_init_5755;
__auto_type cn_init_5763 = rg[5]; __auto_type av = cn_init_5763;
__auto_type cn_init_5781 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_5781;
(rg[5]=r);
}
(rg[2]=cn_rd32u(m,((uint32_t)(rg[4]+0xacU))));
{
__auto_type cn_init_5823 = ((uint32_t)(rg[4]+0x50U)); __auto_type a = cn_init_5823;
cn_wr32u(m,a,rg[5]);
}
(b=19);
}
break;
case 19:
{
(f[5]=cn_rdf64u(m,((uint32_t)(rg[4]+0x0U))));
cn_swap(f,5,4);
(fsw=cn_compare(f[5],f[4]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
(f[4]=f[5]);
{
__auto_type cn_init_5926 = 0x45U; __auto_type bv = cn_init_5926;
__auto_type cn_init_5939 = cn_reg_get(rg,4,1); __auto_type av = cn_init_5939;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=26);
continue;
}
(b=20);
}
break;
case 20:
{
(f[4]=f[4]);
(f[1]=f[3]);
(f[2]=f[2]);
(f[0]=f[1]);
(b=21);
}
break;
case 21:
{
{
__auto_type cn_init_6053 = rg[3]; __auto_type bv = cn_init_6053;
__auto_type cn_init_6061 = rg[3]; __auto_type av = cn_init_6061;
cn_alu(&fl,Alu_And,av,bv,4);
}
if(cn_cond(fl,5)){
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
(f[1]=cn_rdf64u(m,((uint32_t)(rg[4]+0x40U))));
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0x28U))));
(rg[6]=cn_rd32u(m,((uint32_t)(rg[4]+0x38U))));
(rg[0]=cn_rd32u(m,((uint32_t)(rg[4]+0x48U))));
(f[3]=cn_rdf64u(m,((uint32_t)(rg[4]+0x30U))));
(rg[1]=cn_rd32u(m,((uint32_t)(rg[4]+0x4cU))));
(rg[2]=cn_rd32u(m,((uint32_t)(rg[4]+0x50U))));
{
__auto_type cn_init_6267 = rg[0]; __auto_type bv = cn_init_6267;
__auto_type cn_init_6275 = rg[6]; __auto_type av = cn_init_6275;
__auto_type cn_init_6293 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_6293;
(rg[6]=r);
}
{
__auto_type cn_init_6307 = 0x1U; __auto_type v = cn_init_6307;
cn_reg_set(rg,3,1,v);
}
(f[4]=cn_rdf64u(m,((uint32_t)(rg[4]+0x20U))));
cn_swap(f,4,2);
cn_swap(f,4,1);
cn_swap(f,4,3);
cn_swap(f,4,0);
cn_swap(f,4,3);
(steps+=1);
if((steps>limit)){
return 1;
}
(b=19);
continue;
}
break;
case 23:
{
{
__auto_type cn_init_6420 = 0x1U; __auto_type bv = cn_init_6420;
__auto_type cn_init_6428 = rg[3]; __auto_type av = cn_init_6428;
__auto_type cn_init_6446 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_6446;
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=27);
continue;
}
(b=24);
}
break;
case 24:
{
{
__auto_type cn_init_6494 = 0x2U; __auto_type bv = cn_init_6494;
__auto_type cn_init_6502 = rg[3]; __auto_type av = cn_init_6502;
__auto_type cn_init_6520 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_6520;
}
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=28);
continue;
}
(b=25);
}
break;
case 25:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[4]+0x68U))));
{
__auto_type cn_init_6588 = 0x3U; __auto_type v = cn_init_6588;
cn_reg_set(rg,3,1,v);
}
(f[1]=cn_rdf64u(m,((uint32_t)(rg[4]+0x78U))));
(rg[1]=((uint32_t)(rg[0]+0x1U)));
(rg[0]=cn_rd32u(m,((uint32_t)(rg[4]+0x54U))));
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0x60U))));
(rg[2]=((uint32_t)(rg[0]+0x1U)));
(rg[0]=cn_rd32u(m,((uint32_t)(rg[4]+0x38U))));
(f[3]=cn_rdf64u(m,((uint32_t)(rg[4]+0x58U))));
(rg[6]=((uint32_t)(rg[0]+0x1U)));
(f[4]=cn_rdf64u(m,((uint32_t)(rg[4]+0x70U))));
cn_swap(f,4,2);
cn_swap(f,4,1);
cn_swap(f,4,3);
cn_swap(f,4,0);
cn_swap(f,4,3);
(steps+=1);
if((steps>limit)){
return 1;
}
(b=19);
continue;
}
break;
case 26:
{
(f[5]=f[4]);
(f[5]=(f[5]*f[4]));
cn_swap(f,5,4);
(rg[0]=cn_rd32u(m,((uint32_t)(rg[4]+0x6cU))));
(rg[7]=rg[2]);
(rg[5]=((uint32_t)((0x0U)+((uint32_t)(rg[6]*4)))));
cn_shift_reg_l(rg,&fl,Shift_Shl,7,14,4);
{
__auto_type cn_init_6966 = cn_rdf64u(m,((uint32_t)(rg[0]+0xffffffc0U))); __auto_type v = cn_init_6966;
(f[5]=(f[5]*v));
}
{
__auto_type cn_init_6998 = cn_rdf64u(m,((uint32_t)(rg[0]+0xffffffc8U))); __auto_type v = cn_init_6998;
(f[5]=(f[5]+v));
}
(f[4]=(f[4]*f[5]));
(f[5]=cn_rdf64u(m,((uint32_t)(rg[0]+0x20U))));
(rg[0]=rg[2]);
cn_shift_reg_l(rg,&fl,Shift_Shl,0,10,4);
{
__auto_type cn_init_7086 = rg[0]; __auto_type bv = cn_init_7086;
__auto_type cn_init_7094 = rg[7]; __auto_type av = cn_init_7094;
__auto_type cn_init_7112 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_7112;
(rg[7]=r);
}
(rg[0]=rg[6]);
cn_shift_reg_l(rg,&fl,Shift_Shl,0,8,4);
{
__auto_type cn_init_7160 = rg[2]; __auto_type bv = cn_init_7160;
__auto_type cn_init_7168 = rg[7]; __auto_type av = cn_init_7168;
__auto_type cn_init_7186 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_7186;
(rg[7]=r);
}
{
__auto_type cn_init_7203 = rg[5]; __auto_type bv = cn_init_7203;
__auto_type cn_init_7211 = rg[0]; __auto_type av = cn_init_7211;
__auto_type cn_init_7229 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_7229;
(rg[0]=r);
}
{
__auto_type cn_init_7246 = rg[6]; __auto_type bv = cn_init_7246;
__auto_type cn_init_7254 = rg[0]; __auto_type av = cn_init_7254;
__auto_type cn_init_7272 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_7272;
(rg[0]=r);
}
cn_shift_reg_l(rg,&fl,Shift_Shl,0,4,4);
{
__auto_type cn_init_7310 = rg[6]; __auto_type bv = cn_init_7310;
__auto_type cn_init_7318 = rg[0]; __auto_type av = cn_init_7318;
__auto_type cn_init_7336 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_7336;
(rg[0]=r);
}
(rg[0]=((uint32_t)((((uint32_t)(rg[6]+0x0U)))+((uint32_t)(rg[0]*4)))));
(rg[5]=((uint32_t)((((uint32_t)(rg[7]+0x2U)))+((uint32_t)(rg[0]*1)))));
(rg[0]=rg[2]);
(rg[7]=((uint32_t)((0x0U)+((uint32_t)(rg[2]*4)))));
{
__auto_type cn_init_7442 = 0x5a5aU; __auto_type bv = cn_init_7442;
__auto_type cn_init_7450 = rg[5]; __auto_type av = cn_init_7450;
__auto_type cn_init_7468 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_7468;
(rg[5]=r);
}
cn_shift_reg_l(rg,&fl,Shift_Shl,0,8,4);
{
__auto_type cn_init_7506 = rg[7]; __auto_type bv = cn_init_7506;
__auto_type cn_init_7514 = rg[0]; __auto_type av = cn_init_7514;
__auto_type cn_init_7532 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_7532;
(rg[0]=r);
}
{
__auto_type cn_init_7549 = rg[2]; __auto_type bv = cn_init_7549;
__auto_type cn_init_7557 = rg[0]; __auto_type av = cn_init_7557;
__auto_type cn_init_7575 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_7575;
(rg[0]=r);
}
cn_shift_reg_l(rg,&fl,Shift_Shl,0,4,4);
{
__auto_type cn_init_7613 = rg[2]; __auto_type bv = cn_init_7613;
__auto_type cn_init_7621 = rg[0]; __auto_type av = cn_init_7621;
__auto_type cn_init_7639 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_7639;
(rg[0]=r);
}
(rg[7]=((uint32_t)((((uint32_t)(rg[2]+0x7U)))+((uint32_t)(rg[0]*4)))));
(rg[2]=rg[1]);
cn_shift_reg_l(rg,&fl,Shift_Shl,2,10,4);
(rg[0]=rg[1]);
cn_shift_reg_l(rg,&fl,Shift_Shl,0,14,4);
{
__auto_type cn_init_7748 = rg[2]; __auto_type bv = cn_init_7748;
__auto_type cn_init_7756 = rg[0]; __auto_type av = cn_init_7756;
__auto_type cn_init_7774 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_7774;
(rg[0]=r);
}
(rg[2]=rg[0]);
(rg[0]=rg[6]);
cn_shift_reg_l(rg,&fl,Shift_Shl,0,14,4);
{
__auto_type cn_init_7832 = rg[1]; __auto_type bv = cn_init_7832;
__auto_type cn_init_7840 = rg[2]; __auto_type av = cn_init_7840;
__auto_type cn_init_7858 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_7858;
(rg[2]=r);
}
{
__auto_type cn_init_7875 = rg[7]; __auto_type bv = cn_init_7875;
__auto_type cn_init_7883 = rg[2]; __auto_type av = cn_init_7883;
__auto_type cn_init_7901 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_7901;
(rg[2]=r);
}
(rg[7]=rg[6]);
cn_shift_reg_l(rg,&fl,Shift_Shl,7,10,4);
{
__auto_type cn_init_7946 = 0x5a5aU; __auto_type bv = cn_init_7946;
__auto_type cn_init_7954 = rg[2]; __auto_type av = cn_init_7954;
__auto_type cn_init_7972 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_7972;
(rg[2]=r);
}
{
__auto_type cn_init_7989 = rg[7]; __auto_type bv = cn_init_7989;
__auto_type cn_init_7997 = rg[0]; __auto_type av = cn_init_7997;
__auto_type cn_init_8015 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_8015;
(rg[0]=r);
}
(rg[7]=((uint32_t)((0x0U)+((uint32_t)(rg[1]*4)))));
{
__auto_type cn_init_8054 = rg[6]; __auto_type bv = cn_init_8054;
__auto_type cn_init_8062 = rg[0]; __auto_type av = cn_init_8062;
__auto_type cn_init_8080 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_8080;
(rg[0]=r);
}
(rg[6]=rg[0]);
(rg[0]=rg[1]);
cn_shift_reg_l(rg,&fl,Shift_Shl,0,8,4);
{
__auto_type cn_init_8138 = rg[7]; __auto_type bv = cn_init_8138;
__auto_type cn_init_8146 = rg[0]; __auto_type av = cn_init_8146;
__auto_type cn_init_8164 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_8164;
(rg[0]=r);
}
{
__auto_type cn_init_8181 = rg[1]; __auto_type bv = cn_init_8181;
__auto_type cn_init_8189 = rg[0]; __auto_type av = cn_init_8189;
__auto_type cn_init_8207 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_8207;
(rg[0]=r);
}
cn_shift_reg_l(rg,&fl,Shift_Shl,0,4,4);
{
__auto_type cn_init_8245 = rg[1]; __auto_type bv = cn_init_8245;
__auto_type cn_init_8253 = rg[0]; __auto_type av = cn_init_8253;
__auto_type cn_init_8271 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_8271;
(rg[0]=r);
}
(rg[0]=((uint32_t)((((uint32_t)(rg[1]+0x0U)))+((uint32_t)(rg[0]*4)))));
(rg[1]=((uint32_t)((((uint32_t)(rg[6]+0xbU)))+((uint32_t)(rg[0]*1)))));
{
__auto_type cn_init_8345 = 0x5a5aU; __auto_type bv = cn_init_8345;
__auto_type cn_init_8353 = rg[1]; __auto_type av = cn_init_8353;
__auto_type cn_init_8371 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_8371;
(rg[1]=r);
}
(rg[0]=rg[1]);
{
__auto_type cn_init_8398 = rg[2]; __auto_type bv = cn_init_8398;
__auto_type cn_init_8406 = rg[0]; __auto_type av = cn_init_8406;
__auto_type cn_init_8424 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_8424;
(rg[0]=r);
}
(rg[6]=((uint32_t)((((uint32_t)(rg[0]+0x0U)))+((uint32_t)(rg[0]*8)))));
(rg[7]=((uint32_t)((((uint32_t)(rg[6]+0x0U)))+((uint32_t)(rg[6]*8)))));
(rg[6]=rg[7]);
cn_shift_reg_l(rg,&fl,Shift_Shl,6,4,4);
{
__auto_type cn_init_8532 = rg[7]; __auto_type bv = cn_init_8532;
__auto_type cn_init_8540 = rg[6]; __auto_type av = cn_init_8540;
__auto_type cn_init_8558 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_8558;
(rg[6]=r);
}
{
__auto_type cn_init_8575 = rg[5]; __auto_type bv = cn_init_8575;
__auto_type cn_init_8583 = rg[2]; __auto_type av = cn_init_8583;
__auto_type cn_init_8601 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_8601;
(rg[2]=r);
}
{
__auto_type cn_init_8618 = rg[1]; __auto_type bv = cn_init_8618;
__auto_type cn_init_8626 = rg[5]; __auto_type av = cn_init_8626;
__auto_type cn_init_8644 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_8644;
(rg[5]=r);
}
(rg[6]=((uint32_t)((((uint32_t)(rg[0]+0x0U)))+((uint32_t)(rg[6]*8)))));
(rg[6]=((uint32_t)((((uint32_t)(rg[0]+0x0U)))+((uint32_t)(rg[6]*2)))));
(rg[0]=((uint32_t)((((uint32_t)(rg[0]+0x0U)))+((uint32_t)(rg[6]*4)))));
(rg[6]=((uint32_t)((((uint32_t)(rg[2]+0x0U)))+((uint32_t)(rg[2]*8)))));
(rg[7]=((uint32_t)((((uint32_t)(rg[6]+0x0U)))+((uint32_t)(rg[6]*8)))));
(rg[6]=rg[7]);
cn_shift_reg_l(rg,&fl,Shift_Shl,6,4,4);
{
__auto_type cn_init_8842 = rg[7]; __auto_type bv = cn_init_8842;
__auto_type cn_init_8850 = rg[6]; __auto_type av = cn_init_8850;
__auto_type cn_init_8868 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_8868;
(rg[6]=r);
}
(rg[6]=((uint32_t)((((uint32_t)(rg[2]+0x0U)))+((uint32_t)(rg[6]*8)))));
(rg[6]=((uint32_t)((((uint32_t)(rg[2]+0x0U)))+((uint32_t)(rg[6]*2)))));
(rg[7]=((uint32_t)((((uint32_t)(rg[2]+0x0U)))+((uint32_t)(rg[6]*4)))));
(rg[2]=((uint32_t)((((uint32_t)(rg[5]+0x0U)))+((uint32_t)(rg[5]*8)))));
(rg[6]=rg[7]);
cn_shift_reg_l(rg,&fl,Shift_Shl,6,4,4);
(rg[1]=((uint32_t)((((uint32_t)(rg[2]+0x0U)))+((uint32_t)(rg[2]*8)))));
{
__auto_type cn_init_9063 = 0x3fffffffU; __auto_type bv = cn_init_9063;
__auto_type cn_init_9071 = rg[6]; __auto_type av = cn_init_9071;
__auto_type cn_init_9089 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_9089;
(rg[6]=r);
}
(rg[2]=rg[1]);
cn_shift_reg_l(rg,&fl,Shift_Shl,2,4,4);
{
__auto_type cn_init_9142 = ((uint32_t)(rg[4]+0x3cU)); __auto_type a = cn_init_9142;
cn_wr32u(m,a,rg[6]);
}
(f[6]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x3cU))));
(f[6]=(f[6]*f[5]));
(rg[6]=rg[0]);
{
__auto_type cn_init_9210 = 0x3fffffffU; __auto_type bv = cn_init_9210;
__auto_type cn_init_9218 = rg[6]; __auto_type av = cn_init_9218;
__auto_type cn_init_9236 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_9236;
(rg[6]=r);
}
{
__auto_type cn_init_9253 = rg[1]; __auto_type bv = cn_init_9253;
__auto_type cn_init_9261 = rg[2]; __auto_type av = cn_init_9261;
__auto_type cn_init_9279 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_9279;
(rg[2]=r);
}
{
__auto_type cn_init_9301 = ((uint32_t)(rg[4]+0x3cU)); __auto_type a = cn_init_9301;
cn_wr32u(m,a,rg[6]);
}
(f[6]=(f[6]+f[3]));
(rg[2]=((uint32_t)((((uint32_t)(rg[5]+0x0U)))+((uint32_t)(rg[2]*8)))));
(rg[2]=((uint32_t)((((uint32_t)(rg[5]+0x0U)))+((uint32_t)(rg[2]*2)))));
(f[6]=(f[6]*f[2]));
(rg[2]=((uint32_t)((((uint32_t)(rg[5]+0x0U)))+((uint32_t)(rg[2]*4)))));
(rg[6]=rg[2]);
(rg[5]=rg[0]);
cn_shift_reg_l(rg,&fl,Shift_Shl,6,8,4);
(rg[1]=rg[2]);
(f[7]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x3cU))));
(f[7]=(f[7]*f[5]));
{
__auto_type cn_init_9530 = 0x3fffffffU; __auto_type bv = cn_init_9530;
__auto_type cn_init_9538 = rg[6]; __auto_type av = cn_init_9538;
__auto_type cn_init_9556 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_9556;
(rg[6]=r);
}
{
__auto_type cn_init_9578 = ((uint32_t)(rg[4]+0x3cU)); __auto_type a = cn_init_9578;
cn_wr32u(m,a,rg[6]);
}
(rg[6]=rg[7]);
cn_shift_reg_l(rg,&fl,Shift_Shl,6,8,4);
{
__auto_type cn_init_9628 = 0x3fffffffU; __auto_type bv = cn_init_9628;
__auto_type cn_init_9636 = rg[2]; __auto_type av = cn_init_9636;
__auto_type cn_init_9654 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_9654;
(rg[2]=r);
}
(f[7]=(f[7]+f[3]));
{
__auto_type cn_init_9683 = 0x3fffffffU; __auto_type bv = cn_init_9683;
__auto_type cn_init_9691 = rg[6]; __auto_type av = cn_init_9691;
__auto_type cn_init_9709 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_9709;
(rg[6]=r);
}
cn_shift_reg_l(rg,&fl,Shift_Shl,5,4,4);
{
__auto_type cn_init_9744 = 0x3fffffffU; __auto_type bv = cn_init_9744;
__auto_type cn_init_9752 = rg[7]; __auto_type av = cn_init_9752;
__auto_type cn_init_9770 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_9770;
(rg[7]=r);
}
cn_shift_reg_l(rg,&fl,Shift_Shl,0,8,4);
{
__auto_type cn_init_9805 = 0x3fffffffU; __auto_type bv = cn_init_9805;
__auto_type cn_init_9813 = rg[5]; __auto_type av = cn_init_9813;
__auto_type cn_init_9831 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_9831;
(rg[5]=r);
}
(f[7]=(f[7]*f[0]));
{
__auto_type cn_init_9860 = 0x3fffffffU; __auto_type bv = cn_init_9860;
__auto_type cn_init_9868 = rg[0]; __auto_type av = cn_init_9868;
__auto_type cn_init_9886 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_9886;
(rg[0]=r);
}
cn_shift_reg_l(rg,&fl,Shift_Shl,1,4,4);
{
__auto_type cn_init_9921 = 0x3fffffffU; __auto_type bv = cn_init_9921;
__auto_type cn_init_9929 = rg[1]; __auto_type av = cn_init_9929;
__auto_type cn_init_9947 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_9947;
(rg[1]=r);
}
(f[6]=(f[6]+f[7]));
(f[7]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x3cU))));
(f[7]=(f[7]*f[5]));
{
__auto_type cn_init_10023 = ((uint32_t)(rg[4]+0x3cU)); __auto_type a = cn_init_10023;
cn_wr32u(m,a,rg[6]);
}
(f[7]=(f[7]+f[3]));
(f[7]=(f[7]*f[1]));
(f[6]=(f[6]+f[7]));
(f[6]=(f[6]*f[4]));
{
__auto_type cn_init_10115 = cn_rdf64u(m,((uint32_t)(rg[4]+0x18U))); __auto_type v = cn_init_10115;
(f[6]=(f[6]+v));
}
{
__auto_type cn_init_10142 = ((uint32_t)(rg[4]+0x18U)); __auto_type a = cn_init_10142;
cn_wrf64u(m,a,f[6]);
}
(f[6]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x3cU))));
(f[6]=(f[6]*f[5]));
{
__auto_type cn_init_10208 = ((uint32_t)(rg[4]+0x3cU)); __auto_type a = cn_init_10208;
cn_wr32u(m,a,rg[5]);
}
(f[6]=(f[6]+f[3]));
(f[6]=(f[6]*f[2]));
(f[7]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x3cU))));
(f[7]=(f[7]*f[5]));
{
__auto_type cn_init_10304 = ((uint32_t)(rg[4]+0x3cU)); __auto_type a = cn_init_10304;
cn_wr32u(m,a,rg[2]);
}
(f[7]=(f[7]+f[3]));
(f[7]=(f[7]*f[0]));
(f[6]=(f[6]+f[7]));
(f[7]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x3cU))));
(f[7]=(f[7]*f[5]));
{
__auto_type cn_init_10415 = ((uint32_t)(rg[4]+0x3cU)); __auto_type a = cn_init_10415;
cn_wr32u(m,a,rg[7]);
}
(f[7]=(f[7]+f[3]));
(f[7]=(f[7]*f[1]));
(f[6]=(f[6]+f[7]));
(f[6]=(f[6]*f[4]));
{
__auto_type cn_init_10507 = cn_rdf64u(m,((uint32_t)(rg[4]+0x10U))); __auto_type v = cn_init_10507;
(f[6]=(f[6]+v));
}
{
__auto_type cn_init_10534 = ((uint32_t)(rg[4]+0x10U)); __auto_type a = cn_init_10534;
cn_wrf64u(m,a,f[6]);
}
(f[6]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x3cU))));
(f[6]=(f[6]*f[5]));
{
__auto_type cn_init_10600 = ((uint32_t)(rg[4]+0x3cU)); __auto_type a = cn_init_10600;
cn_wr32u(m,a,rg[0]);
}
(f[6]=(f[6]+f[3]));
(f[2]=(f[2]*f[6]));
(f[6]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x3cU))));
(f[6]=(f[6]*f[5]));
{
__auto_type cn_init_10696 = ((uint32_t)(rg[4]+0x3cU)); __auto_type a = cn_init_10696;
cn_wr32u(m,a,rg[1]);
}
(f[6]=(f[6]+f[3]));
(f[0]=(f[0]*f[6]));
cn_swap(f,5,0);
(f[2]=(f[2]+f[5]));
(f[5]=cn_floadu(m,FKind_I32,((uint32_t)(rg[4]+0x3cU))));
(f[0]=(f[0]*f[5]));
cn_swap(f,4,0);
(f[4]=(f[4]+f[3]));
(f[1]=(f[1]*f[4]));
cn_swap(f,3,2);
(f[1]=(f[1]+f[3]));
cn_swap(f,2,0);
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_10908 = cn_rdf64u(m,((uint32_t)(rg[4]+0x8U))); __auto_type v = cn_init_10908;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_10935 = ((uint32_t)(rg[4]+0x8U)); __auto_type a = cn_init_10935;
cn_wrf64u(m,a,f[1]);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=21);
continue;
}
break;
case 27:
{
(f[1]=cn_rdf64u(m,((uint32_t)(rg[4]+0x98U))));
(f[2]=cn_rdf64u(m,((uint32_t)(rg[4]+0x88U))));
(f[3]=cn_rdf64u(m,((uint32_t)(rg[4]+0x90U))));
(rg[1]=cn_rd32u(m,((uint32_t)(rg[4]+0xa0U))));
(rg[2]=cn_rd32u(m,((uint32_t)(rg[4]+0xa4U))));
(rg[6]=cn_rd32u(m,((uint32_t)(rg[4]+0xa8U))));
{
__auto_type cn_init_11102 = 0x2U; __auto_type v = cn_init_11102;
cn_reg_set(rg,3,1,v);
}
(f[4]=cn_rdf64u(m,((uint32_t)(rg[4]+0x80U))));
cn_swap(f,4,2);
cn_swap(f,4,1);
cn_swap(f,4,3);
cn_swap(f,4,0);
cn_swap(f,4,3);
(steps+=1);
if((steps>limit)){
return 1;
}
(b=19);
continue;
}
break;
case 28:
{
(f[0]=f[0]);
(rg[0]=cn_rd32u(m,((uint32_t)(rg[4]+0x6cU))));
(rg[3]=cn_rd32u(m,((uint32_t)(rg[4]+0xe8U))));
(f[0]=cn_rdf64u(m,((uint32_t)(rg[4]+0x18U))));
{
__auto_type cn_init_11298 = cn_rdf64u(m,((uint32_t)(rg[0]+0xfffffff0U))); __auto_type v = cn_init_11298;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_11330 = cn_rdf64u(m,((uint32_t)(rg[3]+0xffffffe0U))); __auto_type v = cn_init_11330;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_11357 = ((uint32_t)(rg[3]+0xffffffe0U)); __auto_type a = cn_init_11357;
cn_wrf64u(m,a,f[0]);
}
(f[0]=cn_rdf64u(m,((uint32_t)(rg[4]+0x10U))));
{
__auto_type cn_init_11409 = cn_rdf64u(m,((uint32_t)(rg[0]+0xfffffff0U))); __auto_type v = cn_init_11409;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_11441 = cn_rdf64u(m,((uint32_t)(rg[3]+0xffffffe8U))); __auto_type v = cn_init_11441;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_11468 = ((uint32_t)(rg[3]+0xffffffe8U)); __auto_type a = cn_init_11468;
cn_wrf64u(m,a,f[0]);
}
(f[0]=cn_rdf64u(m,((uint32_t)(rg[4]+0x8U))));
{
__auto_type cn_init_11520 = cn_rdf64u(m,((uint32_t)(rg[0]+0xfffffff0U))); __auto_type v = cn_init_11520;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_11552 = cn_rdf64u(m,((uint32_t)(rg[3]+0xfffffff0U))); __auto_type v = cn_init_11552;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_11579 = ((uint32_t)(rg[3]+0xfffffff0U)); __auto_type a = cn_init_11579;
cn_wrf64u(m,a,f[0]);
}
{
__auto_type cn_init_11598 = 0xd4U; __auto_type bv = cn_init_11598;
__auto_type cn_init_11606 = rg[4]; __auto_type av = cn_init_11606;
__auto_type cn_init_11624 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_11624;
(rg[4]=r);
}
{
__auto_type cn_init_11645 = cn_pop_lu(m,rg); __auto_type v = cn_init_11645;
(rg[3]=v);
}
{
__auto_type cn_init_11666 = cn_pop_lu(m,rg); __auto_type v = cn_init_11666;
(rg[6]=v);
}
{
__auto_type cn_init_11687 = cn_pop_lu(m,rg); __auto_type v = cn_init_11687;
(rg[7]=v);
}
{
__auto_type cn_init_11708 = cn_pop_lu(m,rg); __auto_type v = cn_init_11708;
(rg[5]=v);
}
__auto_type cn_init_11728 = cn_pop_lu(m,rg); __auto_type r = cn_init_11728;
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
int cn_f_2dffd31d561b9853(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
{
__auto_type cn_init_381 = cn_double(v30); __auto_type v = cn_init_381;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_419 = cn_double(v30); __auto_type v = cn_init_419;
(f[0]=(f[0]-v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_466 = cn_double(v29); __auto_type v = cn_init_466;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_504 = cn_double(v29); __auto_type v = cn_init_504;
(f[0]=(f[0]-v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_551 = cn_double(v28); __auto_type v = cn_init_551;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_589 = cn_double(v28); __auto_type v = cn_init_589;
(f[0]=(f[0]-v));
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
int cn_f_30e2e60d6a23e99d(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_152 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_178;
__auto_type cn_init_191 = cn_cell(vm,0); uint64_t v27 = cn_init_191;
__auto_type cn_init_204 = cn_cell(vm,8); uint64_t v28 = cn_init_204;
__auto_type cn_init_217 = cn_cell(vm,16); uint64_t v29 = cn_init_217;
__auto_type cn_init_230 = cn_cell(vm,24); uint64_t v30 = cn_init_230;
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
__auto_type cn_init_441 = cn_double(v29); __auto_type v = cn_init_441;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_477 = cn_double(v28); __auto_type v = cn_init_477;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_516 = cn_double(v27); __auto_type v = cn_init_516;
(f[0]=(f[0]+v));
}
(f[0]=sin(f[0]));
(fsw&=~0x0400);
{
__auto_type cn_init_559 = cn_double(v30); __auto_type v = cn_init_559;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_583 = cn_double(r5); __auto_type v = cn_init_583;
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
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_31ca3aecc58e5db3(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_58 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_58;
__auto_type cn_init_75 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_75;
__auto_type cn_init_92 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_92;
__auto_type cn_init_109 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_109;
__auto_type cn_init_122 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_122;
__auto_type cn_init_135 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_135;
__auto_type cn_init_148 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_148;
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
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=fabs(f[0]));
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=fabs(f[0]));
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
int cn_f_33f85ce639630e31(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_190 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_203;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(rg[2]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[0]=((uint32_t)(rg[2]+0xffffffc8U)));
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
(f[2]=cn_double(r5));
(f[3]=f[0]);
(f[4]=f[1]);
(f[5]=cn_double(r6));
cn_swap(f,5,4);
(f[5]=(f[5]*f[1]));
cn_swap(f,5,3);
(f[5]=(f[5]*f[0]));
(f[6]=f[2]);
cn_swap(f,6,5);
(f[3]=(f[6]-f[3]));
(f[6]=f[2]);
cn_swap(f,6,5);
(f[6]=(f[6]*f[4]));
cn_swap(f,6,5);
(f[6]=(f[6]*f[2]));
(f[7]=f[0]);
cn_swap(f,7,3);
(f[6]=(f[7]-f[6]));
(f[7]=f[4]);
cn_swap(f,7,3);
(f[7]=(f[7]*f[2]));
cn_swap(f,7,3);
(f[7]=(f[7]*f[4]));
(f[6]=(f[6]+f[7]));
(f[7]=f[0]);
(f[7]=(f[7]*f[4]));
cn_swap(f,7,0);
(f[7]=(f[7]*f[1]));
cn_swap(f,7,6);
{
__auto_type cn_init_679 = cn_double(r10); __auto_type v = cn_init_679;
(f[7]=(f[7]+v));
}
cn_swap(f,7,5);
(f[6]=(f[7]-f[6]));
(f[7]=f[1]);
(f[2]=(f[2]*f[7]));
cn_swap(f,6,1);
(f[4]=(f[4]*f[6]));
cn_swap(f,5,0);
(f[2]=(f[2]+f[5]));
cn_swap(f,4,1);
(f[4]=(f[4]+f[4]));
cn_swap(f,4,1);
(f[3]=(f[4]-f[3]));
cn_swap(f,3,2);
(f[3]=(f[3]+f[3]));
cn_swap(f,3,1);
{
__auto_type cn_init_881 = cn_double(r11); __auto_type v = cn_init_881;
(f[3]=(f[3]+v));
}
cn_swap(f,3,2);
(f[3]=(f[3]+f[3]));
cn_swap(f,3,1);
{
__auto_type cn_init_938 = cn_double(r0); __auto_type v = cn_init_938;
(f[3]=(f[3]+v));
}
cn_swap(f,3,0);
(r3=cn_bits(f[3]));
cn_swap(f,2,1);
{
__auto_type cn_init_991 = cn_double(r12); __auto_type v = cn_init_991;
(f[2]=(f[2]+v));
}
cn_swap(f,2,1);
(r4=cn_bits(f[2]));
cn_swap(f,1,0);
(r6=cn_bits(f[1]));
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_341cdd3c9a694310(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_47 = 0ULL; __auto_type steps = cn_init_47;
__auto_type cn_init_52 = max_steps; __auto_type limit = cn_init_52;
__auto_type cn_init_62 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+136))); unsigned char * vm = cn_init_82;
__auto_type cn_init_99 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_99;
__auto_type cn_init_116 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_116;
__auto_type cn_init_133 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_133;
__auto_type cn_init_150 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_150;
__auto_type cn_init_163 = cn_rd64u(m,0x10007e70U); uint64_t s1998 = cn_init_163;
__auto_type cn_init_176 = cn_rd64u(m,0x10007e78U); uint64_t s1999 = cn_init_176;
__auto_type cn_init_189 = cn_rd64u(m,0x10007e88U); uint64_t s2001 = cn_init_189;
__auto_type cn_init_202 = cn_rd64u(m,0x10007e98U); uint64_t s2003 = cn_init_202;
__auto_type cn_init_215 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_215;
__auto_type cn_init_228 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_228;
__auto_type cn_init_241 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_241;
__auto_type cn_init_254 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_254;
__auto_type cn_init_267 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_267;
__auto_type cn_init_280 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_280;
__auto_type cn_init_293 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_293;
__auto_type cn_init_306 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_306;
__auto_type cn_init_319 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_319;
__auto_type cn_init_332 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_332;
__auto_type cn_init_345 = cn_cell(vm,0); uint64_t v17 = cn_init_345;
__auto_type cn_init_358 = cn_cell(vm,8); uint64_t v18 = cn_init_358;
__auto_type cn_init_371 = cn_cell(vm,16); uint64_t v19 = cn_init_371;
__auto_type cn_init_384 = cn_cell(vm,24); uint64_t v20 = cn_init_384;
__auto_type cn_init_397 = cn_cell(vm,32); uint64_t v21 = cn_init_397;
__auto_type cn_init_410 = cn_cell(vm,40); uint64_t v22 = cn_init_410;
__auto_type cn_init_423 = cn_cell(vm,48); uint64_t v23 = cn_init_423;
__auto_type cn_init_436 = cn_cell(vm,56); uint64_t v24 = cn_init_436;
__auto_type cn_init_449 = cn_cell(vm,64); uint64_t v25 = cn_init_449;
__auto_type cn_init_462 = cn_cell(vm,72); uint64_t v26 = cn_init_462;
__auto_type cn_init_475 = cn_cell(vm,88); uint64_t v28 = cn_init_475;
__auto_type cn_init_488 = cn_cell(vm,96); uint64_t v29 = cn_init_488;
__auto_type cn_init_501 = cn_cell(vm,120); uint64_t v32 = cn_init_501;
__auto_type cn_init_514 = cn_cell(vm,128); uint64_t v33 = cn_init_514;
__auto_type cn_init_527 = cn_cell(vm,136); uint64_t v34 = cn_init_527;
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
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_668 = 0x70U; __auto_type bv = cn_init_668;
__auto_type cn_init_676 = rg[4]; __auto_type av = cn_init_676;
__auto_type cn_init_694 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_694;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s1999=(((s1999&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s1999=(((s1999&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s1998=(((s1998&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(f[0]=cn_double(r3));
(s2001=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_933 = cn_double(v29); __auto_type v = cn_init_933;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(v28));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1032 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1032;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(f[0]=f[0]);
(f[0]=cn_double(v23));
(f[0]=-f[0]);
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(s2009=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1189 = cn_double(v28); __auto_type v = cn_init_1189;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1213 = cn_double(v32); __auto_type v = cn_init_1213;
(f[0]=(f[0]+v));
}
{
__auto_type cn_tuple_1243_0 = sin(f[0]);
__auto_type cn_tuple_1243_1 = cos(f[0]);
__auto_type s = cn_tuple_1243_0;
__auto_type c = cn_tuple_1243_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2013=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(f[1]=cn_double(r5));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_1335 = cn_double(s2013); __auto_type v = cn_init_1335;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_1386 = cn_double(s2012); __auto_type v = cn_init_1386;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_1422 = cn_double(s2013); __auto_type v = cn_init_1422;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(s2009));
(f[1]=(f[1]*f[2]));
(r4=cn_bits(f[1]));
(f[1]=cn_double(s2009));
(f[0]=(f[0]*f[1]));
(r5=cn_bits(f[0]));
goto cn_break_b3;
}
cn_break_b2:;
(f[0]=f[0]);
}
cn_break_b3:;
(f[0]=cn_double(v25));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1613 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1613;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,5)){
goto cn_break_b5;
}
(f[0]=f[0]);
goto cn_break_b27;
}
cn_break_b5:;
(f[0]=f[0]);
(f[0]=cn_double(v24));
{
__auto_type cn_init_1723 = cn_double(v26); __auto_type v = cn_init_1723;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(v25));
(f[1]=fabs(f[1]));
(s2007=cn_bits(f[1]));
(fsw=cn_compare(f[0],cn_double(s2007)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1841 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1841;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,3)){
goto cn_break_b7;
}
(s2007=cn_bits(f[0]));
goto cn_break_b8;
}
cn_break_b7:;
(f[0]=f[0]);
}
cn_break_b8:;
(f[0]=cn_double(v24));
{
__auto_type cn_init_1953 = cn_double(v26); __auto_type v = cn_init_1953;
(f[0]=(f[0]-v));
}
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2015 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_2015;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
(f[0]=f[0]);
(f[0]=cn_double(s2007));
(f[0]=fabs(f[0]));
if(cn_cond(fl,3)){
goto cn_break_b28;
}
(f[0]=-f[0]);
(s2007=cn_bits(f[0]));
(f[0]=cn_double(r3));
(fsw=cn_compare(f[0],cn_double(v26)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2202 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_2202;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,6)){
goto cn_break_b11;
}
(f[0]=f[0]);
goto cn_break_b27;
}
cn_break_b11:;
(fsw=cn_compare(f[0],cn_double(v24)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2333 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_2333;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,3)){
goto cn_break_b13;
}
{
__auto_type cn_init_2407 = cn_double(v24); __auto_type v = cn_init_2407;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2431 = cn_double(v26); __auto_type v = cn_init_2431;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
goto cn_break_b27;
}
cn_break_b13:;
(f[1]=cn_double(v24));
{
__auto_type cn_init_2482 = cn_double(v26); __auto_type v = cn_init_2482;
(f[1]=(f[1]-v));
}
cn_continue_l14:;
{
(fsw=cn_compare(f[1],cn_double(s2007)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_2553 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_2553;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,3)){
goto cn_break_b16;
}
{
__auto_type cn_init_2627 = cn_double(s2007); __auto_type v = cn_init_2627;
(f[1]=(f[1]-v));
}
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l14;
}
goto cn_continue_l14;
cn_break_l14:;
}
cn_break_b16:;
(s2006=cn_bits(f[1]));
(f[1]=cn_double(v24));
{
__auto_type cn_init_2697 = cn_double(s2006); __auto_type v = cn_init_2697;
(f[1]=(f[1]-v));
}
(s2005=cn_bits(f[1]));
(fsw=cn_compare(f[0],cn_double(s2005)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2775 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_2775;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,3)){
goto cn_break_b20;
}
{
__auto_type cn_init_2849 = cn_double(s2005); __auto_type v = cn_init_2849;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2006));
{
__auto_type cn_init_2885 = cn_double(v34); __auto_type v = cn_init_2885;
(f[1]=(f[1]*v));
}
(s2007=cn_bits(f[1]));
(fsw=cn_compare(f[0],cn_double(s2007)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2963 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_2963;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,6)){
goto cn_break_b19;
}
{
__auto_type cn_init_3037 = cn_double(v26); __auto_type v = cn_init_3037;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
goto cn_break_b27;
}
cn_break_b19:;
(f[0]=f[0]);
(f[0]=cn_double(v24));
(f[1]=cn_double(r3));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3136 = cn_double(v26); __auto_type v = cn_init_3136;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
}
cn_break_b27:;
goto cn_break_b45;
}
cn_break_b20:;
(f[1]=cn_double(v26));
(f[2]=cn_double(v25));
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(s2006=cn_bits(f[1]));
cn_continue_l21:;
{
(fsw=cn_compare(f[0],cn_double(s2006)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_3298 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_3298;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,3)){
goto cn_break_b23;
}
(f[1]=cn_double(v25));
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l21;
}
goto cn_continue_l21;
cn_break_l21:;
}
cn_break_b23:;
{
__auto_type cn_init_3436 = cn_double(v26); __auto_type v = cn_init_3436;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2007));
{
__auto_type cn_init_3472 = cn_double(v34); __auto_type v = cn_init_3472;
(f[1]=(f[1]*v));
}
(s2006=cn_bits(f[1]));
(fsw=cn_compare(f[0],cn_double(s2006)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_3550 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_3550;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,6)){
goto cn_break_b25;
}
{
__auto_type cn_init_3624 = cn_double(v26); __auto_type v = cn_init_3624;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
goto cn_break_b26;
}
cn_break_b25:;
(f[0]=-f[0]);
(f[1]=cn_double(s2007));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3701 = cn_double(v26); __auto_type v = cn_init_3701;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
}
cn_break_b26:;
goto cn_break_b45;
}
cn_break_b28:;
(s2007=cn_bits(f[0]));
(f[0]=cn_double(r3));
(fsw=cn_compare(f[0],cn_double(v26)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_3807 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_3807;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,3)){
goto cn_break_b30;
}
(f[0]=f[0]);
goto cn_break_b45;
}
cn_break_b30:;
(fsw=cn_compare(f[0],cn_double(v24)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_3938 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_3938;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,6)){
goto cn_break_b32;
}
{
__auto_type cn_init_4012 = cn_double(v24); __auto_type v = cn_init_4012;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_4036 = cn_double(v26); __auto_type v = cn_init_4036;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
goto cn_break_b45;
}
cn_break_b32:;
(f[1]=cn_double(v24));
{
__auto_type cn_init_4087 = cn_double(v26); __auto_type v = cn_init_4087;
(f[1]=(f[1]-v));
}
cn_continue_l33:;
{
(fsw=cn_compare(f[1],cn_double(s2007)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_4158 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_4158;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,6)){
goto cn_break_b35;
}
{
__auto_type cn_init_4232 = cn_double(s2007); __auto_type v = cn_init_4232;
(f[1]=(f[1]-v));
}
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l33;
}
goto cn_continue_l33;
cn_break_l33:;
}
cn_break_b35:;
(s2006=cn_bits(f[1]));
(f[1]=cn_double(v24));
{
__auto_type cn_init_4302 = cn_double(s2006); __auto_type v = cn_init_4302;
(f[1]=(f[1]-v));
}
(s2005=cn_bits(f[1]));
(fsw=cn_compare(f[0],cn_double(s2005)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_4380 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_4380;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,6)){
goto cn_break_b39;
}
{
__auto_type cn_init_4454 = cn_double(s2005); __auto_type v = cn_init_4454;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2006));
{
__auto_type cn_init_4490 = cn_double(v34); __auto_type v = cn_init_4490;
(f[1]=(f[1]*v));
}
(s2007=cn_bits(f[1]));
(fsw=cn_compare(f[0],cn_double(s2007)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_4568 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_4568;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,3)){
goto cn_break_b38;
}
{
__auto_type cn_init_4642 = cn_double(v26); __auto_type v = cn_init_4642;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
goto cn_break_b45;
}
cn_break_b38:;
(f[0]=f[0]);
(f[0]=cn_double(v24));
(f[1]=cn_double(r3));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_4741 = cn_double(v26); __auto_type v = cn_init_4741;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
goto cn_break_b45;
}
cn_break_b39:;
(f[1]=cn_double(v26));
(f[2]=cn_double(v25));
(f[2]=fabs(f[2]));
(f[1]=(f[1]+f[2]));
(s2006=cn_bits(f[1]));
cn_continue_l40:;
{
(fsw=cn_compare(f[0],cn_double(s2006)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_4891 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_4891;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,6)){
goto cn_break_b42;
}
(f[1]=cn_double(v25));
(f[1]=fabs(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l40;
}
goto cn_continue_l40;
cn_break_l40:;
}
cn_break_b42:;
{
__auto_type cn_init_5040 = cn_double(v26); __auto_type v = cn_init_5040;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2007));
{
__auto_type cn_init_5076 = cn_double(v34); __auto_type v = cn_init_5076;
(f[1]=(f[1]*v));
}
(s2006=cn_bits(f[1]));
(fsw=cn_compare(f[0],cn_double(s2006)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_5154 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_5154;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,3)){
goto cn_break_b44;
}
{
__auto_type cn_init_5228 = cn_double(v26); __auto_type v = cn_init_5228;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
goto cn_break_b45;
}
cn_break_b44:;
(f[0]=-f[0]);
(f[1]=cn_double(s2007));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_5305 = cn_double(v26); __auto_type v = cn_init_5305;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
}
cn_break_b45:;
(f[0]=cn_double(v32));
{
__auto_type cn_init_5353 = cn_double(v34); __auto_type v = cn_init_5353;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(v18));
{
__auto_type cn_init_5389 = cn_double(v18); __auto_type v = cn_init_5389;
(f[1]=(f[1]/v));
}
(f[0]=(f[0]*f[1]));
(s2009=cn_bits(f[0]));
(f[0]=cn_double(v32));
{
__auto_type cn_init_5451 = cn_double(v33); __auto_type v = cn_init_5451;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5475 = cn_double(v18); __auto_type v = cn_init_5475;
(f[0]=(f[0]/v));
}
(s2011=cn_bits(f[0]));
{
__auto_type cn_init_5510 = cn_double(v33); __auto_type v = cn_init_5510;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(v18));
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
(s2008=cn_bits(f[0]));
(f[0]=cn_double(v32));
{
__auto_type cn_init_5622 = cn_double(v33); __auto_type v = cn_init_5622;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5646 = cn_double(v33); __auto_type v = cn_init_5646;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
{
__auto_type cn_init_5681 = cn_double(v18); __auto_type v = cn_init_5681;
(f[0]=(f[0]/v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[0]=atan2(f[0],f[1]));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_5796 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_5796;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,3)){
goto cn_break_b47;
}
{
__auto_type cn_init_5870 = cn_double(s2013); __auto_type v = cn_init_5870;
(f[0]=(f[0]+v));
}
}
cn_break_b47:;
cn_continue_l47:;
{
(fsw=cn_compare(f[0],cn_double(s2012)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_5942 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_5942;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,6)){
goto cn_break_b49;
}
(f[1]=cn_double(s2011));
{
__auto_type cn_init_6028 = cn_double(s2012); __auto_type v = cn_init_6028;
(f[1]=(f[1]+v));
}
(s2011=cn_bits(f[1]));
(f[1]=cn_double(s2009));
{
__auto_type cn_init_6075 = cn_double(s2008); __auto_type v = cn_init_6075;
(f[1]=(f[1]+v));
}
(s2009=cn_bits(f[1]));
{
__auto_type cn_init_6110 = cn_double(s2012); __auto_type v = cn_init_6110;
(f[0]=(f[0]-v));
}
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l47;
}
goto cn_continue_l47;
cn_break_l47:;
}
cn_break_b49:;
(f[0]=f[0]);
(f[0]=cn_double(s2011));
{
__auto_type cn_tuple_6185_0 = sin(f[0]);
__auto_type cn_tuple_6185_1 = cos(f[0]);
__auto_type s = cn_tuple_6185_0;
__auto_type c = cn_tuple_6185_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(f[2]=cn_double(s2001));
{
__auto_type cn_init_6228 = cn_double(v21); __auto_type v = cn_init_6228;
(f[2]=(f[2]*v));
}
(f[2]=cos(f[2]));
(fsw&=~0x0400);
{
__auto_type cn_init_6271 = cn_double(v17); __auto_type v = cn_init_6271;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_6295 = cn_double(v22); __auto_type v = cn_init_6295;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_6319 = cn_double(v17); __auto_type v = cn_init_6319;
(f[2]=(f[2]+v));
}
(s2003=cn_bits(f[2]));
(f[1]=(f[1]*f[2]));
(f[1]=-f[1]);
{
__auto_type cn_init_6380 = cn_double(r4); __auto_type v = cn_init_6380;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
(f[1]=cn_double(s2003));
(f[0]=(f[0]*f[1]));
(f[0]=-f[0]);
{
__auto_type cn_init_6453 = cn_double(r5); __auto_type v = cn_init_6453;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(s2001));
{
__auto_type cn_init_6583 = cn_double(v19); __auto_type v = cn_init_6583;
(f[1]=(f[1]*v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_6626 = cn_double(v17); __auto_type v = cn_init_6626;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_6650 = cn_double(v20); __auto_type v = cn_init_6650;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_6742 = cn_double(s2009); __auto_type v = cn_init_6742;
(f[0]=(f[0]+v));
}
{
__auto_type cn_tuple_6772_0 = sin(f[0]);
__auto_type cn_tuple_6772_1 = cos(f[0]);
__auto_type s = cn_tuple_6772_0;
__auto_type c = cn_tuple_6772_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
{
__auto_type cn_init_6803 = cn_double(s2013); __auto_type v = cn_init_6803;
(f[1]=(f[1]*v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_6838 = cn_double(s2013); __auto_type v = cn_init_6838;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s1998>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s1999>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s1999>>32))&0xffffffffULL)))));
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
cn_wr64u(m,0x10007e70U,s1998);
cn_wr64u(m,0x10007e78U,s1999);
cn_wr64u(m,0x10007e88U,s2001);
cn_wr64u(m,0x10007e98U,s2003);
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_3f3c312349d7b282(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_203 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_229;
__auto_type cn_init_242 = cn_cell(vm,0); uint64_t v32 = cn_init_242;
__auto_type cn_init_255 = cn_cell(vm,8); uint64_t v33 = cn_init_255;
__auto_type cn_init_268 = cn_cell(vm,16); uint64_t v34 = cn_init_268;
__auto_type cn_init_281 = cn_cell(vm,24); uint64_t v35 = cn_init_281;
{
{
__auto_type cn_init_290 = 0x14U; __auto_type bv = cn_init_290;
__auto_type cn_init_298 = rg[4]; __auto_type av = cn_init_298;
__auto_type cn_init_316 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_316;
(rg[4]=r);
}
(rg[0]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[2]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[3]=f[0]);
(f[3]=(f[3]+f[1]));
(f[4]=f[3]);
(f[4]=sqrt(f[4]));
(f[5]=f[2]);
(f[5]=(f[5]-f[3]));
cn_swap(f,5,4);
(f[5]=(f[5]*f[3]));
(f[4]=(f[4]/f[5]));
(f[5]=cn_double(r5));
{
__auto_type cn_init_575 = cn_double(v33); __auto_type v = cn_init_575;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]*f[5]));
(f[5]=f[4]);
{
__auto_type cn_init_624 = cn_double(v33); __auto_type v = cn_init_624;
(f[5]=(f[5]*v));
}
{
__auto_type cn_init_648 = cn_double(r3); __auto_type v = cn_init_648;
(f[5]=(f[5]*v));
}
(f[6]=f[0]);
(f[6]=(f[6]-f[1]));
(f[5]=(f[5]*f[6]));
{
__auto_type cn_init_712 = cn_double(r4); __auto_type v = cn_init_712;
(f[5]=(f[5]*v));
}
(r4=cn_bits(f[5]));
(f[6]=f[0]);
{
__auto_type cn_init_757 = cn_double(v32); __auto_type v = cn_init_757;
(f[6]=(f[6]*v));
}
(f[6]=(f[6]*f[1]));
cn_swap(f,6,0);
(f[6]=(f[6]*f[6]));
(f[0]=(f[0]+f[6]));
cn_swap(f,5,1);
(f[5]=(f[5]*f[5]));
(f[0]=(f[0]+f[5]));
(f[0]=(f[0]*f[4]));
(f[4]=f[0]);
(r3=cn_bits(f[4]));
(f[5]=f[2]);
{
__auto_type cn_init_920 = cn_double(v32); __auto_type v = cn_init_920;
(f[5]=(f[5]*v));
}
(f[5]=(f[5]*f[3]));
cn_swap(f,5,2);
(f[5]=(f[5]*f[5]));
(f[2]=(f[2]+f[5]));
cn_swap(f,4,3);
(f[4]=(f[4]*f[4]));
(f[2]=(f[2]+f[4]));
cn_swap(f,3,2);
(r5=cn_bits(f[3]));
(f[4]=f[2]);
(f[2]=(f[2]*f[4]));
(f[4]=f[1]);
(f[4]=(f[4]*f[1]));
(f[5]=f[3]);
(f[5]=(f[5]*f[3]));
(f[6]=f[2]);
(f[6]=(f[6]+f[4]));
(f[7]=f[6]);
(f[7]=(f[7]*f[6]));
(s2012=cn_bits(f[7]));
(f[6]=sqrt(f[6]));
(f[6]=f[6]);
(f[6]=cn_double(0x3ff0000000000000));
(f[7]=f[2]);
(f[7]=(f[7]-f[4]));
(s2013=cn_bits(f[7]));
(f[7]=f[0]);
{
__auto_type cn_init_1275 = cn_double(v35); __auto_type v = cn_init_1275;
(f[7]=(f[7]*v));
}
(f[1]=(f[1]*f[7]));
(f[7]=cn_double(s2013));
{
__auto_type cn_init_1326 = cn_double(v35); __auto_type v = cn_init_1326;
(f[7]=(f[7]*v));
}
(f[7]=(f[7]*f[5]));
{
__auto_type cn_init_1365 = cn_double(s2012); __auto_type v = cn_init_1365;
(f[7]=(f[7]/v));
}
(f[6]=(f[6]-f[7]));
(f[1]=(f[1]*f[6]));
cn_swap(f,5,1);
(r4=cn_bits(f[5]));
(f[6]=cn_double(v35));
(f[6]=-f[6]);
(f[0]=(f[0]*f[6]));
cn_swap(f,5,3);
(f[0]=(f[0]*f[5]));
cn_swap(f,4,0);
(r5=cn_bits(f[4]));
(f[5]=f[2]);
(f[5]=(f[5]*f[2]));
cn_swap(f,5,2);
{
__auto_type cn_init_1555 = cn_double(v34); __auto_type v = cn_init_1555;
(f[5]=(f[5]*v));
}
(f[5]=(f[5]*f[0]));
(f[2]=(f[2]-f[5]));
cn_swap(f,4,0);
(f[4]=(f[4]*f[4]));
(f[2]=(f[2]+f[4]));
cn_swap(f,3,1);
(f[2]=(f[2]*f[3]));
{
__auto_type cn_init_1672 = cn_double(s2012); __auto_type v = cn_init_1672;
(f[2]=(f[2]/v));
}
{
__auto_type cn_init_1696 = cn_double(s2013); __auto_type v = cn_init_1696;
(f[2]=(v-f[2]));
}
{
__auto_type cn_init_1720 = cn_double(r10); __auto_type v = cn_init_1720;
(f[2]=(f[2]+v));
}
(r3=cn_bits(f[2]));
{
__auto_type cn_init_1755 = cn_double(r11); __auto_type v = cn_init_1755;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_1790 = cn_double(r12); __auto_type v = cn_init_1790;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
{
__auto_type cn_init_1820 = 0x14U; __auto_type bv = cn_init_1820;
__auto_type cn_init_1828 = rg[4]; __auto_type av = cn_init_1828;
__auto_type cn_init_1846 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1846;
(rg[4]=r);
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
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_418c00f4c8bd6d96(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_24 = m->regs; __auto_type rg = cn_init_24;
__auto_type cn_init_32 = m->fl; __auto_type fl = cn_init_32;
__auto_type cn_init_40 = m->fsw_cc; __auto_type fsw = cn_init_40;
__auto_type cn_init_53 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_53;
__auto_type cn_init_66 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_66;
{
(f[0]=cn_double(r3));
{
__auto_type cn_tuple_98_0 = sin(f[0]);
__auto_type cn_tuple_98_1 = cos(f[0]);
__auto_type s = cn_tuple_98_0;
__auto_type c = cn_tuple_98_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(f[2]=cn_double(r4));
(f[0]=(f[0]*f[2]));
(f[1]=(f[1]*f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_4aa26c3c41bb6ac8(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+200))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_178;
__auto_type cn_init_191 = cn_cell(vm,0); uint64_t v25 = cn_init_191;
__auto_type cn_init_204 = cn_cell(vm,8); uint64_t v26 = cn_init_204;
__auto_type cn_init_217 = cn_cell(vm,16); uint64_t v27 = cn_init_217;
__auto_type cn_init_230 = cn_cell(vm,24); uint64_t v28 = cn_init_230;
__auto_type cn_init_243 = cn_cell(vm,32); uint64_t v29 = cn_init_243;
__auto_type cn_init_256 = cn_cell(vm,40); uint64_t v30 = cn_init_256;
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
__auto_type cn_init_420 = cn_double(v30); __auto_type v = cn_init_420;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_444 = cn_double(v27); __auto_type v = cn_init_444;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_491 = cn_double(v29); __auto_type v = cn_init_491;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_515 = cn_double(v26); __auto_type v = cn_init_515;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_562 = cn_double(v28); __auto_type v = cn_init_562;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_586 = cn_double(v25); __auto_type v = cn_init_586;
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
int cn_f_4ce27eb7beb48ce8(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;
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
__auto_type cn_init_76 = rg[3]; __auto_type v = cn_init_76;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_95 = 0xc0U; __auto_type bv = cn_init_95;
__auto_type cn_init_103 = rg[4]; __auto_type av = cn_init_103;
__auto_type cn_init_121 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_121;
(rg[4]=r);
}
(rg[3]=cn_rd32(m,((uint32_t)(rg[4]+0xc8U))));
(rg[2]=cn_rd32(m,((uint32_t)(rg[3]+0x30U))));
(f[0]=cn_rdf64(m,((uint32_t)(rg[3]+0xfffffff0U))));
(f[1]=cn_rdf64(m,((uint32_t)(rg[3]+0xffffffe8U))));
(f[2]=cn_rdf64(m,((uint32_t)(rg[3]+0xffffffe0U))));
(f[3]=f[2]);
(f[3]=(f[3]*f[2]));
(f[4]=f[1]);
(f[4]=(f[4]*f[1]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[0]));
(f[3]=(f[3]+f[4]));
(f[3]=sqrt(f[3]));
(f[4]=f[3]);
(f[5]=cn_double(0x3ff0000000000000));
(f[4]=(f[5]/f[4]));
(f[5]=cn_double(0x3ff0000000000000));
cn_swap(f,5,3);
{
__auto_type cn_init_417 = 0x4U; __auto_type v = cn_init_417;
(rg[0]=v);
}
{
__auto_type cn_init_431 = 0x8U; __auto_type v = cn_init_431;
(rg[1]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=3);
continue;
}
break;
case 1:
{
{
__auto_type cn_init_473 = 0x1U; __auto_type bv = cn_init_473;
__auto_type cn_init_486 = cn_reg_get(rg,1,1); __auto_type av = cn_init_486;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=3);
continue;
}
(b=2);
}
break;
case 2:
{
(f[3]=(f[3]*f[5]));
(b=3);
}
break;
case 3:
{
cn_shift_reg_l(rg,&fl,Shift_Sar,1,1,4);
(f[5]=(f[5]*f[5]));
{
__auto_type cn_init_610 = fl.cf; __auto_type cf = cn_init_610;
__auto_type cn_init_631 = cn_alu(&fl,Alu_Sub,rg[0],1,4); __auto_type r = cn_init_631;
(fl.cf=cf);
(rg[0]=r);
}
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=1);
continue;
}
(b=4);
}
break;
case 4:
{
(f[5]=f[5]);
(f[2]=(f[2]*f[4]));
cn_swap(f,4,2);
{
__auto_type cn_init_734 = ((uint32_t)(rg[4]+0x80U)); __auto_type a = cn_init_734;
cn_wrf64u(m,a,f[4]);
}
cn_swap(f,3,1);
(f[3]=(f[3]*f[2]));
{
__auto_type cn_init_786 = ((uint32_t)(rg[4]+0x40U)); __auto_type a = cn_init_786;
cn_wrf64u(m,a,f[3]);
}
(f[0]=(f[0]*f[2]));
cn_swap(f,1,0);
{
__auto_type cn_init_838 = ((uint32_t)(rg[4]+0x0U)); __auto_type a = cn_init_838;
cn_wrf64u(m,a,f[1]);
}
{
__auto_type cn_init_858 = 0x1U; __auto_type v = cn_init_858;
(rg[0]=v);
}
(b=5);
}
break;
case 5:
{
(f[1]=cn_rdf64(m,((uint32_t)((((uint32_t)(rg[4]+0x78U)))+((uint32_t)(rg[0]*8))))));
{
__auto_type cn_init_930 = cn_rdf64(m,((uint32_t)(rg[4]+0x80U))); __auto_type v = cn_init_930;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_972 = ((uint32_t)((((uint32_t)(rg[4]+0x80U)))+((uint32_t)(rg[0]*8)))); __auto_type a = cn_init_972;
cn_wrf64u(m,a,f[1]);
}
(f[1]=cn_rdf64(m,((uint32_t)((((uint32_t)(rg[4]+0x38U)))+((uint32_t)(rg[0]*8))))));
{
__auto_type cn_init_1042 = cn_rdf64(m,((uint32_t)(rg[4]+0x40U))); __auto_type v = cn_init_1042;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1084 = ((uint32_t)((((uint32_t)(rg[4]+0x40U)))+((uint32_t)(rg[0]*8)))); __auto_type a = cn_init_1084;
cn_wrf64u(m,a,f[1]);
}
(f[1]=cn_rdf64(m,((uint32_t)((((uint32_t)(rg[4]+0xfffffff8U)))+((uint32_t)(rg[0]*8))))));
{
__auto_type cn_init_1154 = cn_rdf64(m,((uint32_t)(rg[4]+0x0U))); __auto_type v = cn_init_1154;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1196 = ((uint32_t)((((uint32_t)(rg[4]+0x0U)))+((uint32_t)(rg[0]*8)))); __auto_type a = cn_init_1196;
cn_wrf64u(m,a,f[1]);
}
{
__auto_type cn_init_1218 = fl.cf; __auto_type cf = cn_init_1218;
__auto_type cn_init_1239 = cn_alu(&fl,Alu_Add,rg[0],1,4); __auto_type r = cn_init_1239;
(fl.cf=cf);
(rg[0]=r);
}
{
__auto_type cn_init_1259 = 0x8U; __auto_type bv = cn_init_1259;
__auto_type cn_init_1267 = rg[0]; __auto_type av = cn_init_1267;
__auto_type cn_init_1285 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1285;
}
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=5);
continue;
}
(b=6);
}
break;
case 6:
{
(f[1]=cn_rdf64(m,((uint32_t)(rg[2]+0x18U))));
{
__auto_type cn_init_1368 = cn_rdf64(m,((uint32_t)(rg[4]+0xa8U))); __auto_type v = cn_init_1368;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1401 = cn_rdf64(m,((uint32_t)(rg[4]+0xb8U))); __auto_type v = cn_init_1401;
(f[1]=(f[1]+v));
}
(f[2]=cn_rdf64(m,((uint32_t)(rg[2]+0x20U))));
{
__auto_type cn_init_1455 = cn_rdf64(m,((uint32_t)(rg[4]+0x98U))); __auto_type v = cn_init_1455;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_rdf64(m,((uint32_t)(rg[2]+0x18U))));
{
__auto_type cn_init_1524 = cn_rdf64(m,((uint32_t)(rg[4]+0x88U))); __auto_type v = cn_init_1524;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=fabs(f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[3]=f[0]);
{
__auto_type cn_init_1608 = cn_rdf64(m,((uint32_t)(rg[2]+0x0U))); __auto_type v = cn_init_1608;
(f[3]=(f[3]*v));
}
(f[4]=cn_rdf64(m,((uint32_t)(rg[2]+0x8U))));
{
__auto_type cn_init_1662 = cn_rdf64(m,((uint32_t)(rg[4]+0x90U))); __auto_type v = cn_init_1662;
(f[4]=(f[4]*v));
}
{
__auto_type cn_init_1695 = cn_rdf64(m,((uint32_t)(rg[4]+0x80U))); __auto_type v = cn_init_1695;
(f[4]=(f[4]+v));
}
(f[5]=cn_rdf64(m,((uint32_t)(rg[2]+0x10U))));
{
__auto_type cn_init_1749 = cn_rdf64(m,((uint32_t)(rg[4]+0xa0U))); __auto_type v = cn_init_1749;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_1797 = cn_rdf64(m,((uint32_t)(rg[4]+0xb0U))); __auto_type v = cn_init_1797;
(f[4]=(f[4]-v));
}
(f[3]=(f[3]*f[4]));
cn_swap(f,3,2);
(f[1]=(f[1]+f[3]));
(f[1]=(f[2]/f[1]));
{
__auto_type cn_init_1884 = cn_rdf64(m,((uint32_t)(rg[3]+0x18U))); __auto_type v = cn_init_1884;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_1911 = ((uint32_t)(rg[3]+0xffffffe0U)); __auto_type a = cn_init_1911;
cn_wrf64u(m,a,f[1]);
}
(f[1]=cn_rdf64(m,((uint32_t)(rg[2]+0x18U))));
{
__auto_type cn_init_1966 = cn_rdf64(m,((uint32_t)(rg[4]+0x68U))); __auto_type v = cn_init_1966;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1999 = cn_rdf64(m,((uint32_t)(rg[4]+0x78U))); __auto_type v = cn_init_1999;
(f[1]=(f[1]+v));
}
(f[2]=cn_rdf64(m,((uint32_t)(rg[2]+0x20U))));
{
__auto_type cn_init_2053 = cn_rdf64(m,((uint32_t)(rg[4]+0x58U))); __auto_type v = cn_init_2053;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_rdf64(m,((uint32_t)(rg[2]+0x18U))));
{
__auto_type cn_init_2122 = cn_rdf64(m,((uint32_t)(rg[4]+0x48U))); __auto_type v = cn_init_2122;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=fabs(f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[3]=f[0]);
{
__auto_type cn_init_2206 = cn_rdf64(m,((uint32_t)(rg[2]+0x0U))); __auto_type v = cn_init_2206;
(f[3]=(f[3]*v));
}
(f[4]=cn_rdf64(m,((uint32_t)(rg[2]+0x8U))));
{
__auto_type cn_init_2260 = cn_rdf64(m,((uint32_t)(rg[4]+0x50U))); __auto_type v = cn_init_2260;
(f[4]=(f[4]*v));
}
{
__auto_type cn_init_2293 = cn_rdf64(m,((uint32_t)(rg[4]+0x40U))); __auto_type v = cn_init_2293;
(f[4]=(f[4]+v));
}
(f[5]=cn_rdf64(m,((uint32_t)(rg[2]+0x10U))));
{
__auto_type cn_init_2347 = cn_rdf64(m,((uint32_t)(rg[4]+0x60U))); __auto_type v = cn_init_2347;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_2395 = cn_rdf64(m,((uint32_t)(rg[4]+0x70U))); __auto_type v = cn_init_2395;
(f[4]=(f[4]-v));
}
(f[3]=(f[3]*f[4]));
cn_swap(f,3,2);
(f[1]=(f[1]+f[3]));
(f[1]=(f[2]/f[1]));
{
__auto_type cn_init_2482 = cn_rdf64(m,((uint32_t)(rg[3]+0x20U))); __auto_type v = cn_init_2482;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2509 = ((uint32_t)(rg[3]+0xffffffe8U)); __auto_type a = cn_init_2509;
cn_wrf64u(m,a,f[1]);
}
(f[1]=cn_rdf64(m,((uint32_t)(rg[2]+0x18U))));
{
__auto_type cn_init_2564 = cn_rdf64(m,((uint32_t)(rg[4]+0x28U))); __auto_type v = cn_init_2564;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2597 = cn_rdf64(m,((uint32_t)(rg[4]+0x38U))); __auto_type v = cn_init_2597;
(f[1]=(f[1]+v));
}
(f[2]=cn_rdf64(m,((uint32_t)(rg[2]+0x20U))));
{
__auto_type cn_init_2651 = cn_rdf64(m,((uint32_t)(rg[4]+0x18U))); __auto_type v = cn_init_2651;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_rdf64(m,((uint32_t)(rg[2]+0x18U))));
{
__auto_type cn_init_2720 = cn_rdf64(m,((uint32_t)(rg[4]+0x8U))); __auto_type v = cn_init_2720;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=fabs(f[1]));
(f[2]=cn_double(0x3ff0000000000000));
cn_swap(f,2,0);
{
__auto_type cn_init_2803 = cn_rdf64(m,((uint32_t)(rg[2]+0x0U))); __auto_type v = cn_init_2803;
(f[2]=(f[2]*v));
}
(f[3]=cn_rdf64(m,((uint32_t)(rg[2]+0x8U))));
{
__auto_type cn_init_2857 = cn_rdf64(m,((uint32_t)(rg[4]+0x10U))); __auto_type v = cn_init_2857;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_2890 = cn_rdf64(m,((uint32_t)(rg[4]+0x0U))); __auto_type v = cn_init_2890;
(f[3]=(f[3]+v));
}
(f[4]=cn_rdf64(m,((uint32_t)(rg[2]+0x10U))));
{
__auto_type cn_init_2944 = cn_rdf64(m,((uint32_t)(rg[4]+0x20U))); __auto_type v = cn_init_2944;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_2992 = cn_rdf64(m,((uint32_t)(rg[4]+0x30U))); __auto_type v = cn_init_2992;
(f[3]=(f[3]-v));
}
(f[2]=(f[2]*f[3]));
cn_swap(f,2,0);
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]/f[1]));
{
__auto_type cn_init_3079 = cn_rdf64(m,((uint32_t)(rg[3]+0x28U))); __auto_type v = cn_init_3079;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3106 = ((uint32_t)(rg[3]+0xfffffff0U)); __auto_type a = cn_init_3106;
cn_wrf64u(m,a,f[0]);
}
{
__auto_type cn_init_3126 = 0xc0U; __auto_type bv = cn_init_3126;
__auto_type cn_init_3134 = rg[4]; __auto_type av = cn_init_3134;
__auto_type cn_init_3152 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3152;
(rg[4]=r);
}
{
__auto_type cn_init_3174 = cn_pop_lu(m,rg); __auto_type v = cn_init_3174;
(rg[3]=v);
}
__auto_type cn_init_3195 = cn_pop_lu(m,rg); __auto_type r = cn_init_3195;
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
int cn_f_4e2c2e531ba0933f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_190 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_229;
__auto_type cn_init_242 = cn_cell(vm,0); uint64_t v10 = cn_init_242;
__auto_type cn_init_255 = cn_cell(vm,8); uint64_t v11 = cn_init_255;
__auto_type cn_init_268 = cn_cell(vm,16); uint64_t v12 = cn_init_268;
__auto_type cn_init_281 = cn_cell(vm,24); uint64_t v13 = cn_init_281;
__auto_type cn_init_294 = cn_cell(vm,32); uint64_t v14 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,40); uint64_t v15 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,48); uint64_t v16 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,56); uint64_t v17 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,64); uint64_t v18 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,72); uint64_t v19 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,80); uint64_t v20 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,88); uint64_t v21 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,96); uint64_t v22 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,104); uint64_t v23 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,112); uint64_t v24 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,120); uint64_t v25 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,128); uint64_t v26 = cn_init_450;
__auto_type cn_init_463 = cn_cell(vm,136); uint64_t v27 = cn_init_463;
__auto_type cn_init_476 = cn_cell(vm,144); uint64_t v28 = cn_init_476;
__auto_type cn_init_489 = cn_cell(vm,152); uint64_t v29 = cn_init_489;
__auto_type cn_init_502 = cn_cell(vm,160); uint64_t v30 = cn_init_502;
__auto_type cn_init_515 = cn_cell(vm,176); uint64_t v32 = cn_init_515;
__auto_type cn_init_528 = cn_cell(vm,192); uint64_t v34 = cn_init_528;
{
{
{
{
{
{
{
{
__auto_type cn_init_555 = 0xffffffd0U; __auto_type bv = cn_init_555;
__auto_type cn_init_563 = rg[4]; __auto_type av = cn_init_563;
__auto_type cn_init_581 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_581;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_610 = r5; uint64_t s = cn_init_610;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_640 = (CN_U2){v28,v29}; CN_U2 s = cn_init_640;
__auto_type cn_init_650 = m->xmm[0]; __auto_type a = cn_init_650;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_720 = v28; uint64_t s = cn_init_720;
__auto_type cn_init_733 = m->xmm[1][0]; __auto_type a = cn_init_733;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_780 = (CN_U2){v24,v25}; CN_U2 s = cn_init_780;
__auto_type cn_init_790 = m->xmm[0]; __auto_type a = cn_init_790;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_860 = v26; uint64_t s = cn_init_860;
__auto_type cn_init_873 = m->xmm[1][0]; __auto_type a = cn_init_873;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_927 = 0x1U; __auto_type bv = cn_init_927;
__auto_type cn_init_935 = rg[2]; __auto_type av = cn_init_935;
__auto_type cn_init_953 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_953;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_981 = r32; uint64_t s = cn_init_981;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_1003 = v28; uint64_t s = cn_init_1003;
__auto_type cn_init_1016 = m->xmm[5][0]; __auto_type a = cn_init_1016;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1112 = m->xmm[0][0]; uint64_t v = cn_init_1112;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1171 = m->xmm[0][1]; uint64_t v = cn_init_1171;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1230 = m->xmm[1][0]; uint64_t v = cn_init_1230;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1392 = (((double)(cn_float(((uint32_t)(((((v12>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1392;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1440 = (((double)(cn_float(((uint32_t)(((((v12>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1440;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1503 = (((double)(cn_float(((uint32_t)(((((v11>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1503;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1566 = (((double)(cn_float(((uint32_t)(((((v15>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1566;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1614 = (((double)(cn_float(((uint32_t)(((((v15>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1614;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1677 = (((double)(cn_float(((uint32_t)(((((v14>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1677;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1739 = (((double)(cn_float(((uint32_t)(((((v14>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1739;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1786 = (((double)(cn_float(((uint32_t)(((((v13>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1786;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1848 = (((double)(cn_float(((uint32_t)(((((v13>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1848;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1891 = cn_bits(f[2]); uint64_t v = cn_init_1891;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1949 = cn_bits(f[1]); uint64_t v = cn_init_1949;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_2007 = cn_bits(f[0]); uint64_t v = cn_init_2007;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2073 = 0x2U; __auto_type bv = cn_init_2073;
__auto_type cn_init_2081 = rg[2]; __auto_type av = cn_init_2081;
__auto_type cn_init_2099 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2099;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2174 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2174;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2201 = cn_round(m,f[0]); __auto_type x = cn_init_2201;
__auto_type cn_init_2236 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2236;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_2286 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2286;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2365 = cn_double(v32); __auto_type v = cn_init_2365;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2400 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2400;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2440 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2440;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2468 = cn_bits(f[0]); uint64_t v = cn_init_2468;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2566 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2566;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2593 = cn_round(m,f[0]); __auto_type x = cn_init_2593;
__auto_type cn_init_2628 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2628;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_2678 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2678;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2757 = cn_double(v32); __auto_type v = cn_init_2757;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2792 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2792;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2832 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2832;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2860 = cn_bits(f[0]); uint64_t v = cn_init_2860;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2958 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2958;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2985 = cn_round(m,f[0]); __auto_type x = cn_init_2985;
__auto_type cn_init_3020 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3020;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_3070 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3070;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3149 = cn_double(v32); __auto_type v = cn_init_3149;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3184 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3184;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3224 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3224;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3252 = cn_bits(f[0]); uint64_t v = cn_init_3252;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
goto cn_break_b5;
}
cn_break_b4:;
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3354 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3354;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3381 = cn_round(m,f[0]); __auto_type x = cn_init_3381;
__auto_type cn_init_3416 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3416;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_3466 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3466;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_3490 = cn_double(v34); __auto_type v = cn_init_3490;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_3570 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3570;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3610 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3610;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3638 = cn_bits(f[0]); uint64_t v = cn_init_3638;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3736 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3736;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3763 = cn_round(m,f[0]); __auto_type x = cn_init_3763;
__auto_type cn_init_3798 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3798;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_3848 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3848;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_3872 = cn_double(v34); __auto_type v = cn_init_3872;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_3952 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_3952;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3992 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3992;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4020 = cn_bits(f[0]); uint64_t v = cn_init_4020;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4118 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4118;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4145 = cn_round(m,f[0]); __auto_type x = cn_init_4145;
__auto_type cn_init_4180 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_4180;
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_4230 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_4230;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_4254 = cn_double(v34); __auto_type v = cn_init_4254;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_4334 = (((double)(((int32_t)(((uint32_t)(((((s2012>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_4334;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_4374 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4374;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4402 = cn_bits(f[0]); uint64_t v = cn_init_4402;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
}
cn_break_b5:;
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_4565 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4565;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_4613 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4613;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_4676 = (((double)(cn_float(((uint32_t)(((((v16>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4676;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_4739 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4739;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_4787 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4787;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_4850 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4850;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_4912 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4912;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_4959 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4959;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_5021 = (((double)(cn_float(((uint32_t)(((((v16>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5021;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_5064 = cn_bits(f[2]); uint64_t v = cn_init_5064;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_5122 = cn_bits(f[1]); uint64_t v = cn_init_5122;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_5180 = cn_bits(f[0]); uint64_t v = cn_init_5180;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_5390 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5390;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5456 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5456;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5523 = cn_double(v30); __auto_type v = cn_init_5523;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_5561 = cn_double(v30); __auto_type v = cn_init_5561;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_5617 = 0x41U; __auto_type bv = cn_init_5617;
__auto_type cn_init_5630 = cn_reg_get(rg,4,1); __auto_type av = cn_init_5630;
__auto_type cn_init_5648 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5648;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b7;
}
(f[0]=f[1]);
goto cn_break_b8;
}
cn_break_b7:;
(f[1]=f[1]);
}
cn_break_b8:;
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_5722 = 0x1U; __auto_type bv = cn_init_5722;
__auto_type cn_init_5730 = rg[2]; __auto_type av = cn_init_5730;
__auto_type cn_init_5748 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_5748;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b10;
}
{
__auto_type cn_init_5779 = cn_double(v28); __auto_type v = cn_init_5779;
(f[0]=(f[0]/v));
}
}
cn_break_b10:;
(r14=cn_bits(f[0]));
(f[0]=cn_double(((((((v10>>32))|((v11<<32))))&0xffffffffffffffffULL))));
(r34=cn_bits(f[0]));
{
__auto_type cn_init_5849 = 0x30U; __auto_type bv = cn_init_5849;
__auto_type cn_init_5857 = rg[4]; __auto_type av = cn_init_5857;
__auto_type cn_init_5875 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_5875;
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
(m->regs=rg);
(m->fl=fl);
(m->fsw_cc=fsw);
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_5e299e82b7f6da6b(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_449 = cn_double(v30); __auto_type v = cn_init_449;
(f[0]=(f[0]-v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_496 = cn_double(v29); __auto_type v = cn_init_496;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_534 = cn_double(v29); __auto_type v = cn_init_534;
(f[0]=(f[0]-v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_581 = cn_double(v28); __auto_type v = cn_init_581;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_619 = cn_double(v28); __auto_type v = cn_init_619;
(f[0]=(f[0]-v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
{
__auto_type cn_init_666 = cn_double(v27); __auto_type v = cn_init_666;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_704 = cn_double(v27); __auto_type v = cn_init_704;
(f[0]=(f[0]-v));
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
int cn_f_621449000c668362(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+160))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v20 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,8); uint64_t v21 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,16); uint64_t v22 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,24); uint64_t v23 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,32); uint64_t v24 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,40); uint64_t v25 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,48); uint64_t v26 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,56); uint64_t v27 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,64); uint64_t v28 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,72); uint64_t v29 = cn_init_325;
__auto_type cn_init_338 = cn_cell(vm,80); uint64_t v30 = cn_init_338;
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
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_545 = 0x7fffffffU; __auto_type v = cn_init_545;
(rg[0]=v);
}
{
__auto_type cn_init_562 = rg[0]; __auto_type bv = cn_init_562;
__auto_type cn_init_579 = (((uint32_t)(((((r5>>32))&0xffffffffULL))))); __auto_type av = cn_init_579;
__auto_type cn_init_597 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_597;
(r5=(((r5&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_636 = rg[0]; __auto_type bv = cn_init_636;
__auto_type cn_init_653 = (((uint32_t)(((((r4>>32))&0xffffffffULL))))); __auto_type av = cn_init_653;
__auto_type cn_init_671 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_671;
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
(f[0]=cn_double(r3));
{
__auto_type cn_init_738 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_738;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_788 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_788;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=-f[0]);
(f[1]=f[0]);
{
__auto_type cn_init_901 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_901;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_925 = cn_double(r3); __auto_type v = cn_init_925;
(f[1]=(f[1]+v));
}
(r3=cn_bits(f[1]));
{
__auto_type cn_init_974 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_974;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_998 = cn_double(r4); __auto_type v = cn_init_998;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
{
__auto_type cn_init_1028 = 0x7fffffffU; __auto_type v = cn_init_1028;
(rg[0]=v);
}
{
__auto_type cn_init_1045 = rg[0]; __auto_type bv = cn_init_1045;
__auto_type cn_init_1062 = (((uint32_t)(((((r4>>32))&0xffffffffULL))))); __auto_type av = cn_init_1062;
__auto_type cn_init_1080 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1080;
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
(f[0]=cn_double(r4));
(f[1]=cn_double(r5));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
cn_swap(f,1,0);
}
cn_break_b2:;
(r5=cn_bits(f[1]));
{
__auto_type cn_init_1252 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1252;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1306 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1306;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[1]);
{
__auto_type cn_init_1401 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1401;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_1449 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1449;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1512 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1512;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_1575 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1575;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1623 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1623;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1686 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1686;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_1748 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1748;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_1795 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1795;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1857 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1857;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(v30));
(f[1]=cn_double(r6));
(f[1]=(f[1]*f[0]));
(r6=cn_bits(f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_1991 = cn_double(v27); __auto_type v = cn_init_1991;
(f[1]=(f[1]-v));
}
(f[1]=(f[1]*f[0]));
{
__auto_type cn_init_2030 = cn_double(v27); __auto_type v = cn_init_2030;
(f[1]=(f[1]+v));
}
(r5=cn_bits(f[1]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_2077 = cn_double(v28); __auto_type v = cn_init_2077;
(f[1]=(f[1]-v));
}
(f[1]=(f[1]*f[0]));
{
__auto_type cn_init_2116 = cn_double(v28); __auto_type v = cn_init_2116;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
(f[1]=cn_double(r3));
{
__auto_type cn_init_2163 = cn_double(v29); __auto_type v = cn_init_2163;
(f[1]=(f[1]-v));
}
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2202 = cn_double(v29); __auto_type v = cn_init_2202;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[6]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_62c00571d2e5f3a1(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_535 = 0x4U; __auto_type bv = cn_init_535;
__auto_type cn_init_543 = rg[4]; __auto_type av = cn_init_543;
__auto_type cn_init_561 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_561;
(rg[4]=r);
}
(rg[1]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
(rg[2]=((uint32_t)(rg[1]+0xffffffc8U)));
(f[2]=f[0]);
(f[3]=f[1]);
(rg[3]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[3]=(f[3]*f[1]));
cn_swap(f,3,2);
(f[3]=(f[3]*f[0]));
(rg[0]=((uint32_t)(rg[1]+0xffffffe8U)));
(f[2]=(f[2]+f[3]));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
(rg[0]=((uint32_t)(((((v30>>32))&0xffffffffULL)))));
(f[2]=sqrt(f[2]));
(rg[7]=((uint32_t)(rg[3]+0xfffffff4U)));
(f[3]=f[0]);
cn_swap(f,3,2);
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[4]/f[3]));
{
__auto_type cn_init_859 = 0x8U; __auto_type bv = cn_init_859;
__auto_type cn_init_872 = cn_reg_get(rg,0,1); __auto_type av = cn_init_872;
cn_alu(&fl,Alu_And,av,bv,1);
}
(f[4]=f[1]);
if(cn_cond(fl,4)){
goto cn_break_b2;
}
cn_swap(f,4,2);
(f[4]=fabs(f[4]));
cn_swap(f,4,2);
}
cn_break_b2:;
{
__auto_type cn_init_949 = 0x10U; __auto_type bv = cn_init_949;
__auto_type cn_init_962 = cn_reg_get(rg,0,1); __auto_type av = cn_init_962;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
(f[4]=f[4]);
(f[4]=f[1]);
(f[4]=fabs(f[4]));
}
cn_break_b4:;
(f[5]=f[0]);
cn_swap(f,5,4);
(f[5]=(f[5]*f[1]));
cn_swap(f,5,4);
{
__auto_type cn_init_1074 = 0x4U; __auto_type bv = cn_init_1074;
__auto_type cn_init_1087 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1087;
cn_alu(&fl,Alu_And,av,bv,1);
}
(f[2]=(f[2]*f[5]));
(f[2]=(f[2]-f[4]));
if(cn_cond(fl,4)){
goto cn_break_b6;
}
cn_swap(f,3,2);
(f[3]=fabs(f[3]));
cn_swap(f,3,2);
}
cn_break_b6:;
{
__auto_type cn_init_1184 = 0x1U; __auto_type bv = cn_init_1184;
__auto_type cn_init_1197 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1197;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
cn_swap(f,3,0);
(f[3]=fabs(f[3]));
cn_swap(f,3,0);
}
cn_break_b8:;
{
__auto_type cn_init_1264 = 0x2U; __auto_type bv = cn_init_1264;
__auto_type cn_init_1277 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1277;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
goto cn_break_b10;
}
cn_swap(f,3,1);
(f[3]=fabs(f[3]));
cn_swap(f,3,1);
}
cn_break_b10:;
(rg[6]=((uint32_t)(((((v29>>0))&0xffffffffULL)))));
(f[2]=(f[2]*f[3]));
cn_swap(f,3,0);
(f[1]=(f[1]*f[3]));
{
__auto_type cn_init_1400 = 0x1U; __auto_type bv = cn_init_1400;
__auto_type cn_init_1408 = rg[6]; __auto_type av = cn_init_1408;
cn_alu(&fl,Alu_And,av,bv,4);
}
(r3=cn_bits(f[2]));
(f[1]=(f[1]+f[1]));
(f[0]=(f[0]*f[1]));
(r4=cn_bits(f[0]));
if(cn_cond(fl,5)){
goto cn_break_b21;
}
(f[1]=cn_double(r5));
(f[2]=f[0]);
(rg[0]=((uint32_t)(((((v30>>0))&0xffffffffULL)))));
(f[3]=f[1]);
cn_swap(f,3,2);
(f[3]=(f[3]*f[0]));
cn_swap(f,3,2);
(f[3]=(f[3]*f[1]));
(f[2]=(f[2]+f[3]));
(f[3]=f[0]);
cn_swap(f,3,2);
(f[3]=sqrt(f[3]));
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[4]/f[3]));
{
__auto_type cn_init_1666 = 0x8U; __auto_type bv = cn_init_1666;
__auto_type cn_init_1679 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1679;
cn_alu(&fl,Alu_And,av,bv,1);
}
(f[4]=f[1]);
if(cn_cond(fl,5)){
goto cn_break_b36;
}
goto cn_break_b12;
}
cn_break_b36:;
cn_swap(f,4,2);
(f[4]=fabs(f[4]));
cn_swap(f,4,2);
}
cn_break_b12:;
{
__auto_type cn_init_1760 = 0x10U; __auto_type bv = cn_init_1760;
__auto_type cn_init_1773 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1773;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
goto cn_break_b14;
}
(f[4]=f[4]);
(f[4]=f[1]);
(f[4]=fabs(f[4]));
}
cn_break_b14:;
(f[5]=f[0]);
cn_swap(f,5,4);
(f[5]=(f[5]*f[1]));
cn_swap(f,5,4);
{
__auto_type cn_init_1885 = 0x4U; __auto_type bv = cn_init_1885;
__auto_type cn_init_1898 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1898;
cn_alu(&fl,Alu_And,av,bv,1);
}
(f[2]=(f[2]*f[5]));
(f[2]=(f[2]-f[4]));
if(cn_cond(fl,4)){
goto cn_break_b16;
}
cn_swap(f,3,2);
(f[3]=fabs(f[3]));
cn_swap(f,3,2);
}
cn_break_b16:;
{
__auto_type cn_init_1995 = 0x1U; __auto_type bv = cn_init_1995;
__auto_type cn_init_2008 = cn_reg_get(rg,0,1); __auto_type av = cn_init_2008;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
goto cn_break_b18;
}
cn_swap(f,3,0);
(f[3]=fabs(f[3]));
cn_swap(f,3,0);
}
cn_break_b18:;
{
__auto_type cn_init_2075 = 0x2U; __auto_type bv = cn_init_2075;
__auto_type cn_init_2088 = cn_reg_get(rg,0,1); __auto_type av = cn_init_2088;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
goto cn_break_b20;
}
cn_swap(f,3,1);
(f[3]=fabs(f[3]));
cn_swap(f,3,1);
}
cn_break_b20:;
cn_swap(f,3,0);
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[0]));
cn_swap(f,2,1);
(rg[3]=((uint32_t)(((((s2012>>0))&0xffffffffULL)))));
(f[2]=(f[2]+f[2]));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
{
__auto_type cn_init_2262 = cn_double(r5); __auto_type v = cn_init_2262;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
goto cn_break_b22;
}
cn_break_b21:;
(f[0]=f[0]);
}
cn_break_b22:;
(f[0]=cn_double(r3));
(f[1]=cn_double(r5));
(rg[0]=((uint32_t)(((((v29>>32))&0xffffffffULL)))));
(f[2]=f[0]);
(f[3]=f[1]);
(f[3]=(f[3]*f[1]));
cn_swap(f,3,2);
(f[3]=(f[3]*f[0]));
(f[2]=(f[2]+f[3]));
(f[3]=f[0]);
cn_swap(f,3,2);
(f[3]=sqrt(f[3]));
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[4]/f[3]));
{
__auto_type cn_init_2482 = 0x8U; __auto_type bv = cn_init_2482;
__auto_type cn_init_2495 = cn_reg_get(rg,0,1); __auto_type av = cn_init_2495;
cn_alu(&fl,Alu_And,av,bv,1);
}
(f[4]=f[1]);
if(cn_cond(fl,4)){
goto cn_break_b24;
}
cn_swap(f,4,2);
(f[4]=fabs(f[4]));
cn_swap(f,4,2);
}
cn_break_b24:;
{
__auto_type cn_init_2572 = 0x10U; __auto_type bv = cn_init_2572;
__auto_type cn_init_2585 = cn_reg_get(rg,0,1); __auto_type av = cn_init_2585;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
goto cn_break_b26;
}
(f[4]=f[4]);
(f[4]=f[1]);
(f[4]=fabs(f[4]));
}
cn_break_b26:;
(f[5]=f[0]);
cn_swap(f,5,4);
(f[5]=(f[5]*f[1]));
cn_swap(f,5,4);
{
__auto_type cn_init_2697 = 0x4U; __auto_type bv = cn_init_2697;
__auto_type cn_init_2710 = cn_reg_get(rg,0,1); __auto_type av = cn_init_2710;
cn_alu(&fl,Alu_And,av,bv,1);
}
(f[2]=(f[2]*f[5]));
(f[2]=(f[2]-f[4]));
if(cn_cond(fl,4)){
goto cn_break_b28;
}
cn_swap(f,3,2);
(f[3]=fabs(f[3]));
cn_swap(f,3,2);
}
cn_break_b28:;
{
__auto_type cn_init_2807 = 0x1U; __auto_type bv = cn_init_2807;
__auto_type cn_init_2820 = cn_reg_get(rg,0,1); __auto_type av = cn_init_2820;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
goto cn_break_b30;
}
cn_swap(f,3,0);
(f[3]=fabs(f[3]));
cn_swap(f,3,0);
}
cn_break_b30:;
{
__auto_type cn_init_2887 = 0x2U; __auto_type bv = cn_init_2887;
__auto_type cn_init_2900 = cn_reg_get(rg,0,1); __auto_type av = cn_init_2900;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,4)){
goto cn_break_b32;
}
cn_swap(f,3,1);
(f[3]=fabs(f[3]));
cn_swap(f,3,1);
}
cn_break_b32:;
cn_swap(f,3,0);
(f[1]=(f[1]*f[3]));
{
__auto_type cn_init_2991 = 0x2U; __auto_type bv = cn_init_2991;
__auto_type cn_init_2999 = rg[6]; __auto_type av = cn_init_2999;
__auto_type cn_init_3017 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_3017;
(rg[6]=r);
}
(f[2]=(f[2]*f[0]));
cn_swap(f,2,1);
(f[2]=(f[2]+f[2]));
(f[0]=(f[0]*f[2]));
if(cn_cond(fl,4)){
goto cn_break_b35;
}
(f[2]=cn_double(r4));
(f[3]=f[1]);
(f[4]=f[2]);
cn_swap(f,4,3);
(f[4]=(f[4]*f[1]));
cn_swap(f,4,3);
(f[4]=(f[4]*f[2]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[0]));
(f[3]=(f[3]+f[4]));
goto cn_break_b34;
}
cn_break_b35:;
(f[2]=cn_double(r4));
(f[3]=f[1]);
(f[4]=f[2]);
cn_swap(f,4,3);
(f[4]=(f[4]*f[1]));
cn_swap(f,4,3);
(f[4]=(f[4]*f[2]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[0]));
(f[3]=(f[3]+f[4]));
(f[3]=sqrt(f[3]));
}
cn_break_b34:;
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
(f[0]=(f[0]*f[3]));
cn_swap(f,2,1);
{
__auto_type cn_init_3445 = cn_double(r10); __auto_type v = cn_init_3445;
(f[2]=(f[2]+v));
}
cn_swap(f,2,1);
{
__auto_type cn_init_3478 = cn_double(r11); __auto_type v = cn_init_3478;
(f[2]=(f[2]+v));
}
cn_swap(f,2,0);
{
__auto_type cn_init_3511 = cn_double(r12); __auto_type v = cn_init_3511;
(f[2]=(f[2]+v));
}
cn_swap(f,2,1);
(r3=cn_bits(f[2]));
cn_swap(f,1,0);
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
{
__auto_type cn_init_3581 = 0x4U; __auto_type bv = cn_init_3581;
__auto_type cn_init_3589 = rg[4]; __auto_type av = cn_init_3589;
__auto_type cn_init_3607 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3607;
(rg[4]=r);
}
{
(rg[3]=((uint32_t)(((((s2012>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[7]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
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
