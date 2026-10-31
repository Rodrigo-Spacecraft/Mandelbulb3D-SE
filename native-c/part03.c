/* Generated native C formula calculations. See tools/generate-native-c.py. */
#include "runtime.h"
int cn_f_2e69ea4edc1c5736(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+208))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v26 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,8); uint64_t v27 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,16); uint64_t v28 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,24); uint64_t v29 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,32); uint64_t v30 = cn_init_260;
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
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_496 = cn_double(v30); __auto_type v = cn_init_496;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_520 = cn_double(v29); __auto_type v = cn_init_520;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_582 = cn_double(v30); __auto_type v = cn_init_582;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_606 = cn_double(v28); __auto_type v = cn_init_606;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_668 = cn_double(v30); __auto_type v = cn_init_668;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_692 = cn_double(v27); __auto_type v = cn_init_692;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_754 = cn_double(v30); __auto_type v = cn_init_754;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_778 = cn_double(v26); __auto_type v = cn_init_778;
(f[0]=(f[0]+v));
}
(r6=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[3]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
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
int cn_f_2e7bab9b5e660afa(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+144))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_294 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_294;
__auto_type cn_init_307 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,0); uint64_t v18 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,8); uint64_t v19 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,16); uint64_t v20 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,24); uint64_t v21 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,32); uint64_t v22 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,40); uint64_t v23 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,48); uint64_t v24 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,56); uint64_t v25 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,64); uint64_t v26 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,72); uint64_t v27 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,80); uint64_t v28 = cn_init_450;
__auto_type cn_init_463 = cn_cell(vm,88); uint64_t v29 = cn_init_463;
__auto_type cn_init_476 = cn_cell(vm,96); uint64_t v30 = cn_init_476;
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
__auto_type cn_init_641 = 0x3cU; __auto_type bv = cn_init_641;
__auto_type cn_init_649 = rg[4]; __auto_type av = cn_init_649;
__auto_type cn_init_667 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_667;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2006=(((s2006&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2005=(((s2005&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2005=(((s2005&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(f[0]=(((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))));
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))));
(s2009=(((s2009&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))));
(s2009=(((s2009&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))));
(s2008=(((s2008&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))));
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))));
(s2007=(((s2007&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))));
(s2007=(((s2007&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))));
(s2006=(((s2006&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008106U))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_1569 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1569;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1617 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1617;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1680 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1680;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1743 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1743;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1791 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1791;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1854 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1854;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1916 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1916;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1963 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1963;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2025 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2025;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_2059 = 0x1U; __auto_type bv = cn_init_2059;
__auto_type cn_init_2076 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_2076;
__auto_type cn_init_2094 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2094;
}
if(cn_cond(fl,4)){
goto cn_break_b77;
}
{
__auto_type cn_init_2118 = cn_double(v25); __auto_type v = cn_init_2118;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_2167 = cn_double(v25); __auto_type v = cn_init_2167;
(f[2]=(f[2]+v));
}
goto cn_break_b78;
}
cn_break_b77:;
(f[3]=f[2]);
{
__auto_type cn_init_2205 = cn_double(v25); __auto_type v = cn_init_2205;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_2253 = cn_double(v25); __auto_type v = cn_init_2253;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b78:;
{
__auto_type cn_init_2360 = cn_double(((((((v18>>32))|((v19<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2360;
(f[2]=(f[2]*v));
}
(f[3]=f[2]);
{
__auto_type cn_init_2408 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2408;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_2456 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2456;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2519 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2519;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_2582 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2582;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_2630 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2630;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2693 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2693;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_2755 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2755;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_2802 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2802;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2864 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2864;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_2946 = 0x0U; __auto_type bv = cn_init_2946;
__auto_type cn_init_2963 = (((uint32_t)(((((v20>>0))&0xffffffffULL))))); __auto_type av = cn_init_2963;
__auto_type cn_init_2981 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2981;
}
if(cn_cond(fl,5)){
goto cn_break_b55;
}
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008131U))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_3417 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3417;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_3465 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3465;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_3528 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3528;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_3591 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3591;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_3639 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3639;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_3702 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3702;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_3764 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3764;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_3811 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3811;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_3873 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3873;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_3907 = 0x1U; __auto_type bv = cn_init_3907;
__auto_type cn_init_3924 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_3924;
__auto_type cn_init_3942 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3942;
}
if(cn_cond(fl,4)){
goto cn_break_b25;
}
{
__auto_type cn_init_3966 = cn_double(v25); __auto_type v = cn_init_3966;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_4015 = cn_double(v25); __auto_type v = cn_init_4015;
(f[2]=(f[2]+v));
}
goto cn_break_b37;
}
cn_break_b25:;
(f[3]=f[2]);
{
__auto_type cn_init_4053 = cn_double(v25); __auto_type v = cn_init_4053;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_4101 = cn_double(v25); __auto_type v = cn_init_4101;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b37:;
(f[3]=f[2]);
{
__auto_type cn_init_4216 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4216;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_4264 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4264;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_4327 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4327;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_4390 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4390;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_4438 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4438;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_4501 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4501;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_4563 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4563;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_4610 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4610;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_4672 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4672;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008156U))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_5171 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5171;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_5219 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5219;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_5282 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5282;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_5345 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5345;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_5393 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5393;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_5456 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5456;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_5518 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5518;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_5565 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5565;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_5627 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5627;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_5661 = 0x1U; __auto_type bv = cn_init_5661;
__auto_type cn_init_5678 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_5678;
__auto_type cn_init_5696 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_5696;
}
if(cn_cond(fl,4)){
goto cn_break_b26;
}
{
__auto_type cn_init_5720 = cn_double(v25); __auto_type v = cn_init_5720;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_5769 = cn_double(v25); __auto_type v = cn_init_5769;
(f[2]=(f[2]+v));
}
goto cn_break_b38;
}
cn_break_b26:;
(f[3]=f[2]);
{
__auto_type cn_init_5807 = cn_double(v25); __auto_type v = cn_init_5807;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_5855 = cn_double(v25); __auto_type v = cn_init_5855;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b38:;
(f[3]=f[2]);
{
__auto_type cn_init_5970 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5970;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_6018 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_6018;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_6081 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_6081;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_6144 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_6144;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_6192 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_6192;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_6255 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_6255;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_6317 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_6317;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_6364 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_6364;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_6426 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_6426;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000817bU))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_6925 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_6925;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_6973 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_6973;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_7036 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_7036;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_7099 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_7099;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_7147 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_7147;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_7210 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_7210;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_7272 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_7272;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_7319 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_7319;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_7381 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_7381;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_7415 = 0x1U; __auto_type bv = cn_init_7415;
__auto_type cn_init_7432 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_7432;
__auto_type cn_init_7450 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_7450;
}
if(cn_cond(fl,4)){
goto cn_break_b27;
}
{
__auto_type cn_init_7474 = cn_double(v25); __auto_type v = cn_init_7474;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_7523 = cn_double(v25); __auto_type v = cn_init_7523;
(f[2]=(f[2]+v));
}
goto cn_break_b39;
}
cn_break_b27:;
(f[3]=f[2]);
{
__auto_type cn_init_7561 = cn_double(v25); __auto_type v = cn_init_7561;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_7609 = cn_double(v25); __auto_type v = cn_init_7609;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b39:;
(f[3]=f[2]);
{
__auto_type cn_init_7724 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_7724;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_7772 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_7772;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_7835 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_7835;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_7898 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_7898;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_7946 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_7946;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_8009 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_8009;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_8071 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_8071;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_8118 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_8118;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_8180 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_8180;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b69;
}
cn_break_b55:;
{
__auto_type cn_init_8266 = 0x1U; __auto_type bv = cn_init_8266;
__auto_type cn_init_8283 = (((uint32_t)(((((v20>>0))&0xffffffffULL))))); __auto_type av = cn_init_8283;
__auto_type cn_init_8301 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_8301;
}
if(cn_cond(fl,5)){
goto cn_break_b60;
}
(f[0]=(((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100081abU))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_8737 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_8737;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_8785 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_8785;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_8848 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_8848;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_8911 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_8911;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_8959 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_8959;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_9022 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_9022;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_9084 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_9084;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_9131 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_9131;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_9193 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_9193;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_9227 = 0x1U; __auto_type bv = cn_init_9227;
__auto_type cn_init_9244 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_9244;
__auto_type cn_init_9262 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_9262;
}
if(cn_cond(fl,4)){
goto cn_break_b28;
}
{
__auto_type cn_init_9286 = cn_double(v25); __auto_type v = cn_init_9286;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_9335 = cn_double(v25); __auto_type v = cn_init_9335;
(f[2]=(f[2]+v));
}
goto cn_break_b40;
}
cn_break_b28:;
(f[3]=f[2]);
{
__auto_type cn_init_9373 = cn_double(v25); __auto_type v = cn_init_9373;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_9421 = cn_double(v25); __auto_type v = cn_init_9421;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b40:;
(f[3]=f[2]);
{
__auto_type cn_init_9536 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_9536;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_9584 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_9584;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_9647 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_9647;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_9710 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_9710;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_9758 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_9758;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_9821 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_9821;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_9883 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_9883;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_9930 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_9930;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_9992 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_9992;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100081d0U))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_10491 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_10491;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_10539 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_10539;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_10602 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_10602;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_10665 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_10665;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_10713 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_10713;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_10776 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_10776;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_10838 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_10838;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_10885 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_10885;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_10947 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_10947;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_10981 = 0x1U; __auto_type bv = cn_init_10981;
__auto_type cn_init_10998 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_10998;
__auto_type cn_init_11016 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_11016;
}
if(cn_cond(fl,4)){
goto cn_break_b29;
}
{
__auto_type cn_init_11040 = cn_double(v25); __auto_type v = cn_init_11040;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_11089 = cn_double(v25); __auto_type v = cn_init_11089;
(f[2]=(f[2]+v));
}
goto cn_break_b41;
}
cn_break_b29:;
(f[3]=f[2]);
{
__auto_type cn_init_11127 = cn_double(v25); __auto_type v = cn_init_11127;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_11175 = cn_double(v25); __auto_type v = cn_init_11175;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b41:;
(f[3]=f[2]);
{
__auto_type cn_init_11290 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_11290;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_11338 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_11338;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_11401 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_11401;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_11464 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_11464;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_11512 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_11512;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_11575 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_11575;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_11637 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_11637;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_11684 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_11684;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_11746 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_11746;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100081f5U))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_12245 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_12245;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_12293 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_12293;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_12356 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_12356;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_12419 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_12419;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_12467 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_12467;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_12530 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_12530;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_12592 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_12592;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_12639 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_12639;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_12701 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_12701;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_12735 = 0x1U; __auto_type bv = cn_init_12735;
__auto_type cn_init_12752 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_12752;
__auto_type cn_init_12770 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_12770;
}
if(cn_cond(fl,4)){
goto cn_break_b30;
}
{
__auto_type cn_init_12794 = cn_double(v25); __auto_type v = cn_init_12794;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_12843 = cn_double(v25); __auto_type v = cn_init_12843;
(f[2]=(f[2]+v));
}
goto cn_break_b42;
}
cn_break_b30:;
(f[3]=f[2]);
{
__auto_type cn_init_12881 = cn_double(v25); __auto_type v = cn_init_12881;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_12929 = cn_double(v25); __auto_type v = cn_init_12929;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b42:;
(f[3]=f[2]);
{
__auto_type cn_init_13044 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_13044;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_13092 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_13092;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_13155 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_13155;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_13218 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_13218;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_13266 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_13266;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_13329 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_13329;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_13391 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_13391;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_13438 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_13438;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_13500 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_13500;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b69;
}
cn_break_b60:;
{
__auto_type cn_init_13586 = 0x2U; __auto_type bv = cn_init_13586;
__auto_type cn_init_13603 = (((uint32_t)(((((v20>>0))&0xffffffffULL))))); __auto_type av = cn_init_13603;
__auto_type cn_init_13621 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_13621;
}
if(cn_cond(fl,5)){
goto cn_break_b65;
}
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008225U))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_14057 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_14057;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_14105 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_14105;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_14168 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_14168;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_14231 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_14231;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_14279 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_14279;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_14342 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_14342;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_14404 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_14404;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_14451 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_14451;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_14513 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_14513;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_14547 = 0x1U; __auto_type bv = cn_init_14547;
__auto_type cn_init_14564 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_14564;
__auto_type cn_init_14582 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_14582;
}
if(cn_cond(fl,4)){
goto cn_break_b31;
}
{
__auto_type cn_init_14606 = cn_double(v25); __auto_type v = cn_init_14606;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_14655 = cn_double(v25); __auto_type v = cn_init_14655;
(f[2]=(f[2]+v));
}
goto cn_break_b43;
}
cn_break_b31:;
(f[3]=f[2]);
{
__auto_type cn_init_14693 = cn_double(v25); __auto_type v = cn_init_14693;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_14741 = cn_double(v25); __auto_type v = cn_init_14741;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b43:;
(f[3]=f[2]);
{
__auto_type cn_init_14856 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_14856;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_14904 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_14904;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_14967 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_14967;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_15030 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_15030;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_15078 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_15078;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_15141 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_15141;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_15203 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_15203;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_15250 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_15250;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_15312 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_15312;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000824aU))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_15811 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_15811;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_15859 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_15859;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_15922 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_15922;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_15985 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_15985;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_16033 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_16033;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_16096 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_16096;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_16158 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_16158;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_16205 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_16205;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_16267 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_16267;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_16301 = 0x1U; __auto_type bv = cn_init_16301;
__auto_type cn_init_16318 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_16318;
__auto_type cn_init_16336 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_16336;
}
if(cn_cond(fl,4)){
goto cn_break_b32;
}
{
__auto_type cn_init_16360 = cn_double(v25); __auto_type v = cn_init_16360;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_16409 = cn_double(v25); __auto_type v = cn_init_16409;
(f[2]=(f[2]+v));
}
goto cn_break_b44;
}
cn_break_b32:;
(f[3]=f[2]);
{
__auto_type cn_init_16447 = cn_double(v25); __auto_type v = cn_init_16447;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_16495 = cn_double(v25); __auto_type v = cn_init_16495;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b44:;
(f[3]=f[2]);
{
__auto_type cn_init_16610 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_16610;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_16658 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_16658;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_16721 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_16721;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_16784 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_16784;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_16832 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_16832;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_16895 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_16895;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_16957 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_16957;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_17004 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_17004;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_17066 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_17066;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000826fU))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_17565 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_17565;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_17613 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_17613;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_17676 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_17676;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_17739 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_17739;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_17787 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_17787;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_17850 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_17850;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_17912 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_17912;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_17959 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_17959;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_18021 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_18021;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_18055 = 0x1U; __auto_type bv = cn_init_18055;
__auto_type cn_init_18072 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_18072;
__auto_type cn_init_18090 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_18090;
}
if(cn_cond(fl,4)){
goto cn_break_b33;
}
{
__auto_type cn_init_18114 = cn_double(v25); __auto_type v = cn_init_18114;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_18163 = cn_double(v25); __auto_type v = cn_init_18163;
(f[2]=(f[2]+v));
}
goto cn_break_b45;
}
cn_break_b33:;
(f[3]=f[2]);
{
__auto_type cn_init_18201 = cn_double(v25); __auto_type v = cn_init_18201;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_18249 = cn_double(v25); __auto_type v = cn_init_18249;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b45:;
(f[3]=f[2]);
{
__auto_type cn_init_18364 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_18364;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_18412 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_18412;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_18475 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_18475;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_18538 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_18538;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_18586 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_18586;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_18649 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_18649;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_18711 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_18711;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_18758 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_18758;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_18820 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_18820;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b69;
}
cn_break_b65:;
(f[0]=(((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000829cU))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_19323 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_19323;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_19371 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_19371;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_19434 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_19434;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_19497 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_19497;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_19545 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_19545;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_19608 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_19608;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_19670 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_19670;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_19717 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_19717;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_19779 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_19779;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_19813 = 0x1U; __auto_type bv = cn_init_19813;
__auto_type cn_init_19830 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_19830;
__auto_type cn_init_19848 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_19848;
}
if(cn_cond(fl,4)){
goto cn_break_b34;
}
{
__auto_type cn_init_19872 = cn_double(v25); __auto_type v = cn_init_19872;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_19921 = cn_double(v25); __auto_type v = cn_init_19921;
(f[2]=(f[2]+v));
}
goto cn_break_b46;
}
cn_break_b34:;
(f[3]=f[2]);
{
__auto_type cn_init_19959 = cn_double(v25); __auto_type v = cn_init_19959;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_20007 = cn_double(v25); __auto_type v = cn_init_20007;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b46:;
(f[3]=f[2]);
{
__auto_type cn_init_20122 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_20122;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_20170 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_20170;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_20233 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_20233;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_20296 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_20296;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_20344 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_20344;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_20407 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_20407;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_20469 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_20469;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_20516 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_20516;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_20578 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_20578;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082c1U))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_21077 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_21077;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_21125 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_21125;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_21188 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_21188;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_21251 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_21251;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_21299 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_21299;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_21362 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_21362;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_21424 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_21424;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_21471 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_21471;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_21533 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_21533;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_21567 = 0x1U; __auto_type bv = cn_init_21567;
__auto_type cn_init_21584 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_21584;
__auto_type cn_init_21602 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_21602;
}
if(cn_cond(fl,4)){
goto cn_break_b35;
}
{
__auto_type cn_init_21626 = cn_double(v25); __auto_type v = cn_init_21626;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_21675 = cn_double(v25); __auto_type v = cn_init_21675;
(f[2]=(f[2]+v));
}
goto cn_break_b47;
}
cn_break_b35:;
(f[3]=f[2]);
{
__auto_type cn_init_21713 = cn_double(v25); __auto_type v = cn_init_21713;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_21761 = cn_double(v25); __auto_type v = cn_init_21761;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b47:;
(f[3]=f[2]);
{
__auto_type cn_init_21876 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_21876;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_21924 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_21924;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_21987 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_21987;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_22050 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_22050;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_22098 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_22098;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_22161 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_22161;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_22223 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_22223;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_22270 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_22270;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_22332 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_22332;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2009=(((s2009&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))));
(f[0]=-f[0]);
(s2007=(((s2007&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082e6U))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_22831 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_22831;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_22879 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_22879;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_22942 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_22942;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_23005 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_23005;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_23053 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_23053;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_23116 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_23116;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_23178 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_23178;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_23225 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_23225;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_23287 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_23287;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_23321 = 0x1U; __auto_type bv = cn_init_23321;
__auto_type cn_init_23338 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_23338;
__auto_type cn_init_23356 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_23356;
}
if(cn_cond(fl,4)){
goto cn_break_b36;
}
{
__auto_type cn_init_23380 = cn_double(v25); __auto_type v = cn_init_23380;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_23429 = cn_double(v25); __auto_type v = cn_init_23429;
(f[2]=(f[2]+v));
}
goto cn_break_b48;
}
cn_break_b36:;
(f[3]=f[2]);
{
__auto_type cn_init_23467 = cn_double(v25); __auto_type v = cn_init_23467;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_23515 = cn_double(v25); __auto_type v = cn_init_23515;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
}
cn_break_b48:;
(f[3]=f[2]);
{
__auto_type cn_init_23630 = (((double)(cn_float(((uint32_t)(((((s2009>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_23630;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_23678 = (((double)(cn_float(((uint32_t)(((((s2008>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_23678;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_23741 = (((double)(cn_float(((uint32_t)(((((s2006>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_23741;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_23804 = (((double)(cn_float(((uint32_t)(((((s2010>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_23804;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_23852 = (((double)(cn_float(((uint32_t)(((((s2009>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_23852;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_23915 = (((double)(cn_float(((uint32_t)(((((s2007>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_23915;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_23977 = (((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_23977;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_24024 = (((double)(cn_float(((uint32_t)(((((s2008>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_24024;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_24086 = (((double)(cn_float(((uint32_t)(((((s2007>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_24086;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b69:;
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
__auto_type cn_init_24323 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_24323;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,7)){
goto cn_break_b73;
}
if(cn_cond(fl,4)){
goto cn_break_b74;
}
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[2]));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_24489 = cn_double(v30); __auto_type v = cn_init_24489;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v26));
(f[3]=cn_double(r5));
(f[3]=(f[3]*f[3]));
(f[3]=(f[3]/f[0]));
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_24608 = cn_double(r10); __auto_type v = cn_init_24608;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_24644 = cn_double(r4); __auto_type v = cn_init_24644;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_24668 = cn_double(v29); __auto_type v = cn_init_24668;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(v26));
(f[4]=cn_double(r5));
(f[4]=(f[4]*f[4]));
(f[4]=(f[4]/f[0]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]*f[3]));
{
__auto_type cn_init_24787 = cn_double(r11); __auto_type v = cn_init_24787;
(f[2]=(f[2]+v));
}
(f[3]=cn_double(r5));
(f[4]=f[0]);
(f[4]=sqrt(f[4]));
(f[3]=(f[3]*f[4]));
{
__auto_type cn_init_24862 = cn_double(v28); __auto_type v = cn_init_24862;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_24886 = cn_double(r12); __auto_type v = cn_init_24886;
(f[3]=(f[3]+v));
}
goto cn_break_b72;
}
cn_break_b74:;
(f[1]=cn_double(r10));
(f[2]=cn_double(r11));
(f[3]=cn_double(r12));
goto cn_break_b72;
}
cn_break_b73:;
(f[1]=cn_double(0x0));
(f[2]=cn_double(0x0));
(f[3]=cn_double(0x0));
}
cn_break_b72:;
(r5=cn_bits(f[3]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(f[0]=f[0]);
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s2005>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2005>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2006>>0))&0xffffffffULL)))));
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
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_2ff39075db065d85(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+144))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(36)); uint64_t r36 = cn_init_173;
__auto_type cn_init_186 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_186;
__auto_type cn_init_199 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_199;
__auto_type cn_init_212 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_212;
__auto_type cn_init_225 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_225;
__auto_type cn_init_238 = cn_cell(vm,0); uint64_t v18 = cn_init_238;
__auto_type cn_init_251 = cn_cell(vm,8); uint64_t v19 = cn_init_251;
__auto_type cn_init_264 = cn_cell(vm,16); uint64_t v20 = cn_init_264;
__auto_type cn_init_277 = cn_cell(vm,24); uint64_t v21 = cn_init_277;
__auto_type cn_init_290 = cn_cell(vm,32); uint64_t v22 = cn_init_290;
__auto_type cn_init_303 = cn_cell(vm,40); uint64_t v23 = cn_init_303;
__auto_type cn_init_316 = cn_cell(vm,48); uint64_t v24 = cn_init_316;
__auto_type cn_init_329 = cn_cell(vm,56); uint64_t v25 = cn_init_329;
__auto_type cn_init_342 = cn_cell(vm,64); uint64_t v26 = cn_init_342;
__auto_type cn_init_355 = cn_cell(vm,72); uint64_t v27 = cn_init_355;
__auto_type cn_init_368 = cn_cell(vm,80); uint64_t v28 = cn_init_368;
__auto_type cn_init_381 = cn_cell(vm,88); uint64_t v29 = cn_init_381;
__auto_type cn_init_394 = cn_cell(vm,96); uint64_t v30 = cn_init_394;
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
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r6));
(f[0]=fabs(f[0]));
(f[1]=cn_double(r5));
(f[1]=fabs(f[1]));
(f[2]=cn_double(r4));
(f[2]=fabs(f[2]));
(f[3]=cn_double(r3));
(f[3]=fabs(f[3]));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
cn_swap(f,3,2);
}
cn_break_b2:;
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
cn_swap(f,3,1);
}
cn_break_b4:;
cn_swap(f,3,2);
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b6;
}
cn_swap(f,3,1);
}
cn_break_b6:;
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b8;
}
cn_swap(f,3,0);
}
cn_break_b8:;
cn_swap(f,3,2);
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b10;
}
cn_swap(f,3,0);
}
cn_break_b10:;
cn_swap(f,3,2);
cn_swap(f,3,1);
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b12;
}
cn_swap(f,3,0);
}
cn_break_b12:;
cn_swap(f,3,1);
{
__auto_type cn_init_1292 = 0x28U; __auto_type bv = cn_init_1292;
__auto_type cn_init_1300 = rg[7]; __auto_type av = cn_init_1300;
__auto_type cn_init_1318 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_1318;
(rg[7]=r);
}
(f[4]=f[3]);
{
__auto_type cn_init_1361 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1361;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1409 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1409;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1472 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1472;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1535 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1535;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r3=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_1609 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1609;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1657 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1657;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1720 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1720;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1783 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1783;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r4=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_1857 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1857;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1905 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1905;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1968 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1968;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2031 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2031;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r5=cn_bits(f[4]));
{
__auto_type cn_init_2095 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2095;
(f[3]=(f[3]*v));
}
cn_swap(f,3,2);
{
__auto_type cn_init_2142 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2142;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
cn_swap(f,2,1);
{
__auto_type cn_init_2204 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2204;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
cn_swap(f,1,0);
{
__auto_type cn_init_2266 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2266;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2300 = 0x28U; __auto_type bv = cn_init_2300;
__auto_type cn_init_2308 = rg[7]; __auto_type av = cn_init_2308;
__auto_type cn_init_2326 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2326;
(rg[7]=r);
}
(f[1]=cn_double(v30));
(f[0]=(f[0]*f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]-f[2]));
{
__auto_type cn_init_2399 = cn_double(v26); __auto_type v = cn_init_2399;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
(r6=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=cn_double(v30));
(f[4]=cn_double(r36));
(f[4]=(f[4]*f[3]));
(r36=cn_bits(f[4]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
(f[4]=f[3]);
(f[5]=cn_double(0x3ff0000000000000));
(f[4]=(f[4]-f[5]));
(f[5]=f[4]);
(f[6]=f[5]);
{
__auto_type cn_init_2622 = cn_double(v29); __auto_type v = cn_init_2622;
(f[6]=(f[6]*v));
}
(f[1]=(f[1]-f[6]));
{
__auto_type cn_init_2661 = cn_double(v28); __auto_type v = cn_init_2661;
(f[5]=(f[5]*v));
}
(f[2]=(f[2]-f[5]));
(f[4]=(f[4]/f[3]));
{
__auto_type cn_init_2715 = cn_double(v27); __auto_type v = cn_init_2715;
(f[4]=(f[4]*v));
}
(f[0]=(f[0]-f[4]));
cn_swap(f,4,0);
(f[4]=fabs(f[4]));
(f[0]=(f[0]-f[4]));
(f[0]=(f[0]*f[3]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
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
cn_wr64(m,CN_REC+8*(36),r36);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_3026de1ec4eb0e62(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+200))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_276 = cn_cell(vm,0); uint64_t v25 = cn_init_276;
__auto_type cn_init_289 = cn_cell(vm,8); uint64_t v26 = cn_init_289;
__auto_type cn_init_302 = cn_cell(vm,16); uint64_t v27 = cn_init_302;
__auto_type cn_init_315 = cn_cell(vm,24); uint64_t v28 = cn_init_315;
__auto_type cn_init_328 = cn_cell(vm,32); uint64_t v29 = cn_init_328;
__auto_type cn_init_341 = cn_cell(vm,40); uint64_t v30 = cn_init_341;
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
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r6));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_704 = cn_double(v30); __auto_type v = cn_init_704;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_728 = cn_double(r10); __auto_type v = cn_init_728;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_764 = cn_double(r4); __auto_type v = cn_init_764;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_800 = cn_double(r6); __auto_type v = cn_init_800;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_839 = cn_double(v29); __auto_type v = cn_init_839;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_863 = cn_double(r11); __auto_type v = cn_init_863;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_899 = cn_double(r5); __auto_type v = cn_init_899;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_923 = cn_double(v28); __auto_type v = cn_init_923;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r4));
{
__auto_type cn_init_959 = cn_double(r6); __auto_type v = cn_init_959;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_983 = cn_double(v27); __auto_type v = cn_init_983;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_1022 = cn_double(r12); __auto_type v = cn_init_1022;
(f[2]=(f[2]+v));
}
(f[3]=cn_double(r3));
{
__auto_type cn_init_1058 = cn_double(r6); __auto_type v = cn_init_1058;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r4));
{
__auto_type cn_init_1094 = cn_double(r5); __auto_type v = cn_init_1094;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]-f[4]));
{
__auto_type cn_init_1133 = cn_double(v26); __auto_type v = cn_init_1133;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_1157 = cn_double(r0); __auto_type v = cn_init_1157;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_1181 = cn_double(v25); __auto_type v = cn_init_1181;
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
int cn_f_319b6afb1ce0cefe(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_47 = 0ULL; __auto_type steps = cn_init_47;
__auto_type cn_init_52 = max_steps; __auto_type limit = cn_init_52;
__auto_type cn_init_62 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+184))); unsigned char * vm = cn_init_82;
__auto_type cn_init_99 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_99;
__auto_type cn_init_116 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_116;
__auto_type cn_init_133 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_133;
__auto_type cn_init_150 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_150;
__auto_type cn_init_167 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_167;
__auto_type cn_init_184 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_184;
__auto_type cn_init_201 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_201;
__auto_type cn_init_218 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_218;
__auto_type cn_init_235 = cn_rd64(m,CN_REC+8*(32)); uint64_t r32 = cn_init_235;
__auto_type cn_init_252 = cn_rd64(m,CN_REC+8*(33)); uint64_t r33 = cn_init_252;
__auto_type cn_init_265 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_265;
__auto_type cn_init_278 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_278;
__auto_type cn_init_291 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_291;
__auto_type cn_init_304 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_304;
__auto_type cn_init_317 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_317;
__auto_type cn_init_330 = cn_cell(vm,0); uint64_t v23 = cn_init_330;
__auto_type cn_init_343 = cn_cell(vm,8); uint64_t v24 = cn_init_343;
__auto_type cn_init_356 = cn_cell(vm,16); uint64_t v25 = cn_init_356;
__auto_type cn_init_369 = cn_cell(vm,24); uint64_t v26 = cn_init_369;
__auto_type cn_init_382 = cn_cell(vm,32); uint64_t v27 = cn_init_382;
__auto_type cn_init_395 = cn_cell(vm,40); uint64_t v28 = cn_init_395;
__auto_type cn_init_408 = cn_cell(vm,56); uint64_t v30 = cn_init_408;
__auto_type cn_init_421 = cn_cell(vm,64); uint64_t v31 = cn_init_421;
__auto_type cn_init_434 = cn_cell(vm,72); uint64_t v32 = cn_init_434;
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
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
{
__auto_type cn_init_757 = 0x70U; __auto_type bv = cn_init_757;
__auto_type cn_init_765 = rg[6]; __auto_type av = cn_init_765;
__auto_type cn_init_783 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_783;
(rg[6]=r);
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008066U))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r3));
(f[0]=fabs(f[0]));
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
}
(rg[0]=((uint32_t)(((((v25>>32))&0xffffffffULL)))));
(f[1]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008040U))))&0xffffffffULL))<<0))));
cn_shift_reg_l(rg,&fl,Shift_Shr,0,1,4);
if(cn_cond(fl,4)){
goto cn_break_b29;
}
if(cn_cond(fl,3)){
goto cn_break_b13;
}
(f[2]=f[1]);
goto cn_break_b17;
}
cn_break_b13:;
(f[2]=cn_double(0x3ff0000000000000));
cn_swap(f,2,1);
}
cn_break_b17:;
cn_continue_l17:;
{
(f[2]=(f[2]*f[2]));
cn_shift_reg_l(rg,&fl,Shift_Shr,0,1,4);
if(cn_cond(fl,3)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l17;
}
(f[1]=(f[1]*f[2]));
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l17;
}
goto cn_break_b25;
}
goto cn_continue_l17;
cn_break_l17:;
}
cn_break_b25:;
(f[2]=f[2]);
}
cn_break_b29:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
(rg[0]=((uint32_t)(((((s2011>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
__auto_type cn_init_1267 = cn_double(((((((v24>>32))|((v25<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1267;
(f[1]=(f[1]*v));
}
cn_swap(f,1,0);
(f[2]=cn_double(v27));
(f[2]=(f[2]+f[2]));
(f[2]=(f[2]-f[1]));
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[2]));
(f[0]=(f[1]/f[0]));
{
__auto_type cn_init_1409 = 0x80U; __auto_type bv = cn_init_1409;
__auto_type cn_init_1426 = (((uint32_t)(((((r3>>56))&0xffULL))))); __auto_type av = cn_init_1426;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,9)){
goto cn_break_b42;
}
(f[0]=-f[0]);
}
cn_break_b42:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(rg[0]=rg[2]);
(f=(CN_D8){f[1],f[2],f[3],f[4],f[5],f[6],f[7],f[0]});
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)((0xfffe002fU))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r4));
(f[0]=fabs(f[0]));
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
}
(rg[0]=((uint32_t)(((((v25>>32))&0xffffffffULL)))));
(f[1]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008040U))))&0xffffffffULL))<<0))));
cn_shift_reg_l(rg,&fl,Shift_Shr,0,1,4);
if(cn_cond(fl,4)){
goto cn_break_b30;
}
if(cn_cond(fl,3)){
goto cn_break_b14;
}
(f[2]=f[1]);
goto cn_break_b18;
}
cn_break_b14:;
(f[2]=cn_double(0x3ff0000000000000));
cn_swap(f,2,1);
}
cn_break_b18:;
cn_continue_l18:;
{
(f[2]=(f[2]*f[2]));
cn_shift_reg_l(rg,&fl,Shift_Shr,0,1,4);
if(cn_cond(fl,3)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l18;
}
(f[1]=(f[1]*f[2]));
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l18;
}
goto cn_break_b26;
}
goto cn_continue_l18;
cn_break_l18:;
}
cn_break_b26:;
(f[2]=f[2]);
}
cn_break_b30:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
(rg[0]=((uint32_t)(((((s2011>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
__auto_type cn_init_2011 = cn_double(((((((v24>>32))|((v25<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2011;
(f[1]=(f[1]*v));
}
cn_swap(f,1,0);
(f[2]=cn_double(v27));
(f[2]=(f[2]+f[2]));
(f[2]=(f[2]-f[1]));
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[2]));
(f[0]=(f[1]/f[0]));
{
__auto_type cn_init_2153 = 0x80U; __auto_type bv = cn_init_2153;
__auto_type cn_init_2170 = (((uint32_t)(((((r4>>56))&0xffULL))))); __auto_type av = cn_init_2170;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,9)){
goto cn_break_b43;
}
(f[0]=-f[0]);
}
cn_break_b43:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f=(CN_D8){f[7],f[0],f[1],f[2],f[3],f[4],f[5],f[6]});
(rg[0]=rg[1]);
(f=(CN_D8){f[2],f[3],f[4],f[5],f[6],f[7],f[0],f[1]});
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)((0xfffe0032U))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r5));
(f[0]=fabs(f[0]));
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
}
(rg[0]=((uint32_t)(((((v25>>32))&0xffffffffULL)))));
(f[1]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008040U))))&0xffffffffULL))<<0))));
cn_shift_reg_l(rg,&fl,Shift_Shr,0,1,4);
if(cn_cond(fl,4)){
goto cn_break_b31;
}
if(cn_cond(fl,3)){
goto cn_break_b15;
}
(f[2]=f[1]);
goto cn_break_b19;
}
cn_break_b15:;
(f[2]=cn_double(0x3ff0000000000000));
cn_swap(f,2,1);
}
cn_break_b19:;
cn_continue_l19:;
{
(f[2]=(f[2]*f[2]));
cn_shift_reg_l(rg,&fl,Shift_Shr,0,1,4);
if(cn_cond(fl,3)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l19;
}
(f[1]=(f[1]*f[2]));
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l19;
}
goto cn_break_b27;
}
goto cn_continue_l19;
cn_break_l19:;
}
cn_break_b27:;
(f[2]=f[2]);
}
cn_break_b31:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
(rg[0]=((uint32_t)(((((s2011>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
__auto_type cn_init_2799 = cn_double(((((((v24>>32))|((v25<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2799;
(f[1]=(f[1]*v));
}
cn_swap(f,1,0);
(f[2]=cn_double(v27));
(f[2]=(f[2]+f[2]));
(f[2]=(f[2]-f[1]));
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[2]));
(f[0]=(f[1]/f[0]));
{
__auto_type cn_init_2941 = 0x80U; __auto_type bv = cn_init_2941;
__auto_type cn_init_2958 = (((uint32_t)(((((r5>>56))&0xffULL))))); __auto_type av = cn_init_2958;
cn_alu(&fl,Alu_And,av,bv,1);
}
if(cn_cond(fl,9)){
goto cn_break_b44;
}
(f[0]=-f[0]);
}
cn_break_b44:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f=(CN_D8){f[6],f[7],f[0],f[1],f[2],f[3],f[4],f[5]});
{
__auto_type cn_init_3063 = 0x0U; __auto_type bv = cn_init_3063;
__auto_type cn_init_3080 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type av = cn_init_3080;
__auto_type cn_init_3098 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3098;
}
if(cn_cond(fl,15)){
goto cn_break_b52;
}
{
__auto_type cn_init_3129 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type v = cn_init_3129;
__auto_type cn_init_3136 = fl.cf; __auto_type cf = cn_init_3136;
__auto_type cn_init_3154 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_3154;
(fl.cf=cf);
(r33=(((r33&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
(f[3]=cn_double(v30));
(r32=cn_bits(f[3]));
}
cn_break_b52:;
(f[3]=cn_double(r32));
(f[4]=cn_double(0x3ff0000000000000));
(f[5]=f[3]);
(f[5]=fabs(f[5]));
(f[4]=(f[5]-f[4]));
{
__auto_type cn_init_3288 = cn_double(v26); __auto_type v = cn_init_3288;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(r32=cn_bits(f[3]));
(f[3]=cn_double(v28));
(fsw=cn_compare(f[3],cn_double(v32)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b54;
}
(f[3]=cn_double(0x3ff0000000000000));
goto cn_break_b61;
}
cn_break_b54:;
(f[3]=f[0]);
(f[3]=(f[3]*f[3]));
(f[4]=f[1]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_3555 = cn_double(v28); __auto_type v = cn_init_3555;
(f[4]=(f[4]+v));
}
{
__auto_type cn_init_3579 = cn_double(v31); __auto_type v = cn_init_3579;
(f[4]=(f[4]*v));
}
(f[5]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_3615 = cn_double(v28); __auto_type v = cn_init_3615;
(f[5]=(f[5]-v));
}
{
__auto_type cn_init_3639 = cn_double(v31); __auto_type v = cn_init_3639;
(f[5]=(f[5]*v));
}
cn_swap(f,5,3);
(f[5]=(f[5]-f[4]));
(fsw=cn_compare(f[5],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
}
(f[5]=fabs(f[5]));
(f[5]=(f[5]/f[3]));
(f[6]=f[5]);
(rg[0]=((uint32_t)(((((v24>>0))&0xffffffffULL)))));
cn_shift_reg_l(rg,&fl,Shift_Shr,0,1,4);
if(cn_cond(fl,3)){
goto cn_break_b56;
}
(f[6]=sqrt(f[6]));
{
__auto_type cn_init_3869 = rg[0]; __auto_type x = cn_init_3869;
__auto_type cn_init_3882 = ((((x>>31))&1)==1); __auto_type out = cn_init_3882;
(rg[0]=(((x<<1))|((uint32_t)(fl.cf))));
(fl.cf=out);
}
}
cn_break_b56:;
(f=(CN_D8){f[5],f[6],f[7],f[0],f[1],f[2],f[3],f[4]});
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<32))))|(((((((uint64_t)((0xfffe0065U))))&0xffffffffULL))<<32))));
cn_shift_reg_l(rg,&fl,Shift_Shr,0,1,4);
if(cn_cond(fl,4)){
goto cn_break_b32;
}
if(cn_cond(fl,3)){
goto cn_break_b16;
}
(f[2]=f[1]);
goto cn_break_b20;
}
cn_break_b16:;
(f[2]=cn_double(0x3ff0000000000000));
cn_swap(f,2,1);
}
cn_break_b20:;
cn_continue_l20:;
{
(f[2]=(f[2]*f[2]));
cn_shift_reg_l(rg,&fl,Shift_Shr,0,1,4);
if(cn_cond(fl,3)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l20;
}
(f[1]=(f[1]*f[2]));
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l20;
}
goto cn_break_b28;
}
goto cn_continue_l20;
cn_break_l20:;
}
cn_break_b28:;
(f[2]=f[2]);
}
cn_break_b32:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f=(CN_D8){f[3],f[4],f[5],f[6],f[7],f[0],f[1],f[2]});
{
__auto_type cn_init_4277 = cn_double(v23); __auto_type v = cn_init_4277;
(f[6]=(f[6]*v));
}
(f[7]=cn_double(0x3ff0000000000000));
(f[7]=(f[7]+f[6]));
cn_swap(f,7,5);
(f[6]=(f[6]+f[7]));
(f[5]=(f[6]/f[5]));
{
(rg[0]=((uint32_t)(((((s2012>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(f[3]=(f[3]*f[5]));
cn_swap(f,4,3);
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b60;
}
(f[4]=-f[4]);
}
cn_break_b60:;
(f[3]=(f[3]+f[4]));
}
cn_break_b61:;
(f[4]=cn_double(r32));
(f[3]=(f[4]/f[3]));
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[3]));
(r6=cn_bits(f[4]));
(f[0]=(f[0]*f[3]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
{
__auto_type cn_init_4596 = cn_double(r12); __auto_type v = cn_init_4596;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_4631 = cn_double(r11); __auto_type v = cn_init_4631;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_4666 = cn_double(r10); __auto_type v = cn_init_4666;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64(m,CN_REC+8*(32),r32);
cn_wr64(m,CN_REC+8*(33),r33);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_31d3d4fa897a6b4a(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_44 = 0ULL; __auto_type steps = cn_init_44;
__auto_type cn_init_49 = max_steps; __auto_type limit = cn_init_49;
__auto_type cn_init_62 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+144))); unsigned char * vm = cn_init_82;
__auto_type cn_init_95 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_95;
__auto_type cn_init_108 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_108;
__auto_type cn_init_121 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_121;
__auto_type cn_init_134 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_134;
__auto_type cn_init_147 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_147;
__auto_type cn_init_160 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_160;
__auto_type cn_init_173 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_173;
__auto_type cn_init_186 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_186;
__auto_type cn_init_199 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_199;
__auto_type cn_init_212 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_212;
__auto_type cn_init_225 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_225;
__auto_type cn_init_238 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_238;
__auto_type cn_init_251 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_251;
__auto_type cn_init_264 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_264;
__auto_type cn_init_277 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_277;
__auto_type cn_init_290 = cn_cell(vm,0); uint64_t v18 = cn_init_290;
__auto_type cn_init_303 = cn_cell(vm,8); uint64_t v19 = cn_init_303;
__auto_type cn_init_316 = cn_cell(vm,16); uint64_t v20 = cn_init_316;
__auto_type cn_init_329 = cn_cell(vm,24); uint64_t v21 = cn_init_329;
__auto_type cn_init_342 = cn_cell(vm,32); uint64_t v22 = cn_init_342;
__auto_type cn_init_355 = cn_cell(vm,40); uint64_t v23 = cn_init_355;
__auto_type cn_init_368 = cn_cell(vm,48); uint64_t v24 = cn_init_368;
__auto_type cn_init_381 = cn_cell(vm,56); uint64_t v25 = cn_init_381;
__auto_type cn_init_394 = cn_cell(vm,64); uint64_t v26 = cn_init_394;
__auto_type cn_init_407 = cn_cell(vm,72); uint64_t v27 = cn_init_407;
__auto_type cn_init_420 = cn_cell(vm,80); uint64_t v28 = cn_init_420;
__auto_type cn_init_433 = cn_cell(vm,88); uint64_t v29 = cn_init_433;
__auto_type cn_init_446 = cn_cell(vm,96); uint64_t v30 = cn_init_446;
__auto_type cn_init_459 = cn_cell(vm,112); uint64_t v32 = cn_init_459;
__auto_type cn_init_472 = cn_cell(vm,120); uint64_t v33 = cn_init_472;
__auto_type cn_init_485 = cn_cell(vm,128); uint64_t v34 = cn_init_485;
{
{
{
{
{
{
{
{
__auto_type cn_init_512 = 0xffffffbaU; __auto_type bv = cn_init_512;
__auto_type cn_init_520 = rg[4]; __auto_type av = cn_init_520;
__auto_type cn_init_538 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_538;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_567 = r5; uint64_t s = cn_init_567;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_597 = (CN_U2){v28,v29}; CN_U2 s = cn_init_597;
__auto_type cn_init_607 = m->xmm[0]; __auto_type a = cn_init_607;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_677 = v28; uint64_t s = cn_init_677;
__auto_type cn_init_690 = m->xmm[1][0]; __auto_type a = cn_init_690;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_737 = (CN_U2){v24,v25}; CN_U2 s = cn_init_737;
__auto_type cn_init_747 = m->xmm[0]; __auto_type a = cn_init_747;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_817 = v26; uint64_t s = cn_init_817;
__auto_type cn_init_830 = m->xmm[1][0]; __auto_type a = cn_init_830;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_867 = 0x0U; __auto_type bv = cn_init_867;
__auto_type cn_init_884 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_884;
__auto_type cn_init_902 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_902;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_923 = r32; uint64_t s = cn_init_923;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_945 = v28; uint64_t s = cn_init_945;
__auto_type cn_init_958 = m->xmm[5][0]; __auto_type a = cn_init_958;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1054 = m->xmm[0][0]; uint64_t v = cn_init_1054;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1113 = m->xmm[0][1]; uint64_t v = cn_init_1113;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1172 = m->xmm[1][0]; uint64_t v = cn_init_1172;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(v34));
{
__auto_type cn_init_1242 = cn_bits(f[0]); uint64_t v = cn_init_1242;
(s2011=(((s2011&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2012=(((s2012&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1291 = 0x1U; __auto_type bv = cn_init_1291;
__auto_type cn_init_1308 = (((uint32_t)(((((v20>>0))&0xffffffffULL))))); __auto_type av = cn_init_1308;
__auto_type cn_init_1326 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1326;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1410 = cn_bits(f[1]); uint64_t v = cn_init_1410;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1468 = cn_bits(f[0]); uint64_t v = cn_init_1468;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b4:;
{
__auto_type cn_init_1518 = 0xffffffffU; __auto_type bv = cn_init_1518;
__auto_type cn_init_1535 = (((uint32_t)(((((v20>>0))&0xffffffffULL))))); __auto_type av = cn_init_1535;
__auto_type cn_init_1553 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1553;
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
(f[0]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1637 = cn_bits(f[1]); uint64_t v = cn_init_1637;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1695 = cn_bits(f[0]); uint64_t v = cn_init_1695;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b6:;
{
__auto_type cn_init_1745 = 0x0U; __auto_type bv = cn_init_1745;
__auto_type cn_init_1762 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_1762;
__auto_type cn_init_1780 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1780;
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[0]=-f[0]);
{
__auto_type cn_init_1847 = cn_bits(f[0]); uint64_t v = cn_init_1847;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b8:;
{
__auto_type cn_init_1897 = 0x3U; __auto_type v = cn_init_1897;
(rg[2]=v);
}
cn_continue_l9:;
{
{
{
{
{
{
{
{
{
(f[0]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[0]=-f[0]);
{
__auto_type cn_init_1987 = cn_bits(f[0]); uint64_t v = cn_init_1987;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[0]=-f[0]);
{
__auto_type cn_init_2084 = cn_bits(f[0]); uint64_t v = cn_init_2084;
(s2012=(((s2012&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2013=(((s2013&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2182 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2182;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2250 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2250;
(f[1]=(f[1]+v));
}
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_2308 = cn_double(((((((v18>>32))|((v19<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2308;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2336 = cn_bits(f[0]); uint64_t v = cn_init_2336;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2495 = cn_bits(f[0]); uint64_t v = cn_init_2495;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2567 = cn_bits(f[0]); uint64_t v = cn_init_2567;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(v30));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_2664 = cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2664;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=f[0]);
{
__auto_type cn_init_2751 = cn_double(v30); __auto_type v = cn_init_2751;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2791 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2791;
(f[1]=(f[1]/v));
}
(f[2]=cn_double(0x3fe62e42fefa39ef));
cn_swap(f,2,1);
(f[1]*=log2(f[2]));
{
__auto_type cn_init_2850 = cn_double(v30); __auto_type v = cn_init_2850;
(f[1]=(f[1]*v));
}
cn_swap(f,1,0);
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2925 = cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2925;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2965 = cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2965;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_3019 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3019;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3071 = cn_double(v32); __auto_type v = cn_init_3071;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3095 = cn_double(v33); __auto_type v = cn_init_3095;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3176 = cn_double(v23); __auto_type v = cn_init_3176;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b11;
}
(f[1]=f[1]);
goto cn_break_b12;
}
cn_break_b11:;
(f[0]=f[1]);
}
cn_break_b12:;
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3339 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3339;
(f[1]=(v-f[1]));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b14;
}
(f[1]=f[1]);
goto cn_break_b15;
}
cn_break_b14:;
(f[0]=f[1]);
}
cn_break_b15:;
(f[1]=cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b17;
}
(f[1]=f[1]);
goto cn_break_b18;
}
cn_break_b17:;
(f[0]=f[1]);
}
cn_break_b18:;
(fsw=cn_compare(f[0],cn_double(((((((s2011>>48))|((s2012<<16))))&0xffffffffffffffffULL)))));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b20;
}
{
__auto_type cn_init_3673 = cn_bits(f[0]); uint64_t v = cn_init_3673;
(s2011=(((s2011&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2012=(((s2012&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
goto cn_break_b21;
}
cn_break_b20:;
(f[0]=f[0]);
}
cn_break_b21:;
(f[0]=cn_double(((((((s2012>>48))|((s2013<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3774 = cn_bits(f[0]); uint64_t v = cn_init_3774;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3860 = cn_bits(f[0]); uint64_t v = cn_init_3860;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((v18>>32))|((v19<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(0x400921fb54442d18));
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_4016 = cn_bits(f[0]); uint64_t v = cn_init_4016;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_4068 = rg[2]; __auto_type v = cn_init_4068;
__auto_type cn_init_4075 = fl.cf; __auto_type cf = cn_init_4075;
__auto_type cn_init_4093 = cn_alu(&fl,Alu_Sub,v,1,4); __auto_type r = cn_init_4093;
(fl.cf=cf);
(rg[2]=r);
}
if(cn_cond(fl,15)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l9;
}
goto cn_break_b22;
}
goto cn_continue_l9;
cn_break_l9:;
}
cn_break_b22:;
(f[0]=cn_double(((((((s2011>>48))|((s2012<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4176 = 0x0U; __auto_type bv = cn_init_4176;
__auto_type cn_init_4193 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_4193;
__auto_type cn_init_4211 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_4211;
}
if(cn_cond(fl,5)){
goto cn_break_b24;
}
{
__auto_type cn_init_4235 = cn_double(v28); __auto_type v = cn_init_4235;
(f[0]=(f[0]/v));
}
}
cn_break_b24:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_4266 = 0x46U; __auto_type bv = cn_init_4266;
__auto_type cn_init_4274 = rg[4]; __auto_type av = cn_init_4274;
__auto_type cn_init_4292 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_4292;
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
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_31f1cc5bee2024dc(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+216))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_105;
__auto_type cn_init_118 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_118;
__auto_type cn_init_131 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_131;
__auto_type cn_init_144 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_144;
__auto_type cn_init_157 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_157;
__auto_type cn_init_170 = cn_cell(vm,0); uint64_t v27 = cn_init_170;
__auto_type cn_init_183 = cn_cell(vm,8); uint64_t v28 = cn_init_183;
__auto_type cn_init_196 = cn_cell(vm,16); uint64_t v29 = cn_init_196;
__auto_type cn_init_209 = cn_cell(vm,24); uint64_t v30 = cn_init_209;
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
(f[1]=cn_double(v28));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(v30));
(f[0]=(f[0]+f[1]));
(r3=cn_bits(f[0]));
{
__auto_type cn_init_596 = (((uint32_t)(((((r3>>56))&0xffULL))))); __auto_type v = cn_init_596;
cn_reg_set(rg,0,1,v);
}
{
__auto_type cn_init_616 = 0x80U; __auto_type bv = cn_init_616;
__auto_type cn_init_629 = cn_reg_get(rg,0,1); __auto_type av = cn_init_629;
__auto_type cn_init_647 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_647;
cn_reg_set(rg,0,1,r);
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(v29));
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v27));
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
(r3=cn_bits(f[0]));
{
__auto_type cn_init_776 = cn_reg_get(rg,0,1); __auto_type bv = cn_init_776;
__auto_type cn_init_793 = (((uint32_t)(((((r3>>56))&0xffULL))))); __auto_type av = cn_init_793;
__auto_type cn_init_811 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_811;
(r3=(((r3&~((0xffULL<<56))))|(((((((uint64_t)((r))))&0xffULL))<<56))));
}
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
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_324ecf945352b2bd(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+184))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_289 = cn_cell(vm,0); uint64_t v23 = cn_init_289;
__auto_type cn_init_302 = cn_cell(vm,8); uint64_t v24 = cn_init_302;
__auto_type cn_init_315 = cn_cell(vm,16); uint64_t v25 = cn_init_315;
__auto_type cn_init_328 = cn_cell(vm,24); uint64_t v26 = cn_init_328;
__auto_type cn_init_341 = cn_cell(vm,32); uint64_t v27 = cn_init_341;
__auto_type cn_init_354 = cn_cell(vm,40); uint64_t v28 = cn_init_354;
__auto_type cn_init_367 = cn_cell(vm,48); uint64_t v29 = cn_init_367;
__auto_type cn_init_380 = cn_cell(vm,56); uint64_t v30 = cn_init_380;
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
(f[1]=cn_double(r11));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_728 = cn_double(v25); __auto_type v = cn_init_728;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
(f[2]=cn_double(r10));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_791 = cn_double(v24); __auto_type v = cn_init_791;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v23));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_874 = 0x41U; __auto_type bv = cn_init_874;
__auto_type cn_init_887 = cn_reg_get(rg,4,1); __auto_type av = cn_init_887;
__auto_type cn_init_905 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_905;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b2;
}
(f[0]=cn_double(r3));
{
__auto_type cn_init_954 = cn_double(v30); __auto_type v = cn_init_954;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1001 = cn_double(v29); __auto_type v = cn_init_1001;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_1048 = cn_double(v28); __auto_type v = cn_init_1048;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
{
__auto_type cn_init_1095 = cn_double(v27); __auto_type v = cn_init_1095;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1119 = cn_double(v26); __auto_type v = cn_init_1119;
(f[0]=(f[0]+v));
}
(r6=cn_bits(f[0]));
goto cn_break_b3;
}
cn_break_b2:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_1170 = cn_double(v30); __auto_type v = cn_init_1170;
(f[0]=(f[0]-v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1217 = cn_double(v29); __auto_type v = cn_init_1217;
(f[0]=(f[0]-v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_1264 = cn_double(v28); __auto_type v = cn_init_1264;
(f[0]=(f[0]-v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
{
__auto_type cn_init_1311 = cn_double(v27); __auto_type v = cn_init_1311;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_1335 = cn_double(v26); __auto_type v = cn_init_1335;
(f[0]=(f[0]+v));
}
(r6=cn_bits(f[0]));
}
cn_break_b3:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_1383 = cn_double(r10); __auto_type v = cn_init_1383;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1419 = cn_double(r11); __auto_type v = cn_init_1419;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_1481 = cn_double(r12); __auto_type v = cn_init_1481;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r6));
{
__auto_type cn_init_1543 = cn_double(r0); __auto_type v = cn_init_1543;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r3));
{
__auto_type cn_init_1605 = cn_double(r11); __auto_type v = cn_init_1605;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r4));
{
__auto_type cn_init_1641 = cn_double(r10); __auto_type v = cn_init_1641;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r5));
{
__auto_type cn_init_1692 = cn_double(r0); __auto_type v = cn_init_1692;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r6));
{
__auto_type cn_init_1743 = cn_double(r12); __auto_type v = cn_init_1743;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r3));
{
__auto_type cn_init_1805 = cn_double(r12); __auto_type v = cn_init_1805;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r4));
{
__auto_type cn_init_1841 = cn_double(r0); __auto_type v = cn_init_1841;
(f[3]=(f[3]*v));
}
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r5));
{
__auto_type cn_init_1903 = cn_double(r10); __auto_type v = cn_init_1903;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r6));
{
__auto_type cn_init_1954 = cn_double(r11); __auto_type v = cn_init_1954;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
{
__auto_type cn_init_2005 = cn_double(r0); __auto_type v = cn_init_2005;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r4));
{
__auto_type cn_init_2041 = cn_double(r12); __auto_type v = cn_init_2041;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r5));
{
__auto_type cn_init_2092 = cn_double(r11); __auto_type v = cn_init_2092;
(f[4]=(f[4]*v));
}
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r6));
{
__auto_type cn_init_2154 = cn_double(r10); __auto_type v = cn_init_2154;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(r6=cn_bits(f[3]));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_327c8d0feb18147a(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+120))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,0); uint64_t v15 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,8); uint64_t v16 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,16); uint64_t v17 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,24); uint64_t v18 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,32); uint64_t v19 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,40); uint64_t v20 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,48); uint64_t v21 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,56); uint64_t v22 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,64); uint64_t v23 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,72); uint64_t v24 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,80); uint64_t v25 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,88); uint64_t v26 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,96); uint64_t v27 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,104); uint64_t v28 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,112); uint64_t v29 = cn_init_422;
__auto_type cn_init_435 = cn_cell(vm,120); uint64_t v30 = cn_init_435;
__auto_type cn_init_448 = cn_cell(vm,136); uint64_t v32 = cn_init_448;
__auto_type cn_init_461 = cn_cell(vm,144); uint64_t v33 = cn_init_461;
__auto_type cn_init_474 = cn_cell(vm,152); uint64_t v34 = cn_init_474;
__auto_type cn_init_487 = cn_cell(vm,160); uint64_t v35 = cn_init_487;
__auto_type cn_init_500 = cn_cell(vm,168); uint64_t v36 = cn_init_500;
{
{
{
{
{
{
__auto_type cn_init_521 = 0xffffffceU; __auto_type bv = cn_init_521;
__auto_type cn_init_529 = rg[4]; __auto_type av = cn_init_529;
__auto_type cn_init_547 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_547;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_576 = r5; uint64_t s = cn_init_576;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_606 = (CN_U2){v28,v29}; CN_U2 s = cn_init_606;
__auto_type cn_init_616 = m->xmm[0]; __auto_type a = cn_init_616;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_686 = v28; uint64_t s = cn_init_686;
__auto_type cn_init_699 = m->xmm[1][0]; __auto_type a = cn_init_699;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_746 = (CN_U2){v24,v25}; CN_U2 s = cn_init_746;
__auto_type cn_init_756 = m->xmm[0]; __auto_type a = cn_init_756;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_826 = v26; uint64_t s = cn_init_826;
__auto_type cn_init_839 = m->xmm[1][0]; __auto_type a = cn_init_839;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_876 = 0x0U; __auto_type bv = cn_init_876;
__auto_type cn_init_893 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_893;
__auto_type cn_init_911 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_911;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_932 = r32; uint64_t s = cn_init_932;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_954 = v28; uint64_t s = cn_init_954;
__auto_type cn_init_967 = m->xmm[5][0]; __auto_type a = cn_init_967;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1063 = m->xmm[0][0]; uint64_t v = cn_init_1063;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1122 = m->xmm[0][1]; uint64_t v = cn_init_1122;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1181 = m->xmm[1][0]; uint64_t v = cn_init_1181;
(s2011=(((s2011&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2012=(((s2012&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1230 = 0xffffffd4U; __auto_type bv = cn_init_1230;
__auto_type cn_init_1238 = rg[7]; __auto_type av = cn_init_1238;
__auto_type cn_init_1256 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1256;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1383 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1383;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1431 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1431;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1494 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1494;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1557 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1557;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1605 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1605;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1668 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1668;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1730 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1730;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1777 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1777;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1839 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1839;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1882 = cn_bits(f[2]); uint64_t v = cn_init_1882;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1940 = cn_bits(f[1]); uint64_t v = cn_init_1940;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1998 = cn_bits(f[0]); uint64_t v = cn_init_1998;
(s2011=(((s2011&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2012=(((s2012&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_2047 = 0x2cU; __auto_type bv = cn_init_2047;
__auto_type cn_init_2055 = rg[7]; __auto_type av = cn_init_2055;
__auto_type cn_init_2073 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2073;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2120 = cn_double(v23); __auto_type v = cn_init_2120;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_2162 = cn_bits(f[0]); uint64_t v = cn_init_2162;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2244 = cn_double(v23); __auto_type v = cn_init_2244;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_2268 = cn_double(v32); __auto_type v = cn_init_2268;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2292 = cn_double(v32); __auto_type v = cn_init_2292;
(f[0]=(f[0]-v));
}
(f[0]=cn_round(m,f[0]));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2373 = cn_double(v23); __auto_type v = cn_init_2373;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_2424 = cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2424;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_2466 = cn_bits(f[0]); uint64_t v = cn_init_2466;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(v23));
{
__auto_type cn_init_2532 = cn_double(v33); __auto_type v = cn_init_2532;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2560 = cn_bits(f[0]); uint64_t v = cn_init_2560;
(s2012=(((s2012&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2013=(((s2013&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2658 = cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2658;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_2700 = cn_bits(f[0]); uint64_t v = cn_init_2700;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2798 = cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2798;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_2822 = cn_double(v32); __auto_type v = cn_init_2822;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2846 = cn_double(v32); __auto_type v = cn_init_2846;
(f[0]=(f[0]-v));
}
(f[0]=cn_round(m,f[0]));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2943 = cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2943;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_2994 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2994;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_3036 = cn_bits(f[0]); uint64_t v = cn_init_3036;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3118 = cn_double(v34); __auto_type v = cn_init_3118;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3170 = cn_double(v35); __auto_type v = cn_init_3170;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3209 = cn_double(v36); __auto_type v = cn_init_3209;
(f[0]=(f[0]+v));
}
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3287 = cn_bits(f[0]); uint64_t v = cn_init_3287;
(s2012=(((s2012&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2013=(((s2013&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[1]=f[0]);
{
__auto_type cn_init_3351 = cn_double(v34); __auto_type v = cn_init_3351;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
{
__auto_type cn_init_3402 = cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3402;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_3444 = cn_bits(f[1]); uint64_t v = cn_init_3444;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_3498 = cn_double(v35); __auto_type v = cn_init_3498;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_3549 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3549;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_3591 = cn_bits(f[0]); uint64_t v = cn_init_3591;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3673 = cn_double(v34); __auto_type v = cn_init_3673;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3725 = cn_double(v35); __auto_type v = cn_init_3725;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3764 = cn_double(v36); __auto_type v = cn_init_3764;
(f[0]=(f[0]+v));
}
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3842 = cn_bits(f[0]); uint64_t v = cn_init_3842;
(s2012=(((s2012&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2013=(((s2013&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[1]=f[0]);
{
__auto_type cn_init_3906 = cn_double(v34); __auto_type v = cn_init_3906;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
{
__auto_type cn_init_3957 = cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3957;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_3985 = cn_bits(f[1]); uint64_t v = cn_init_3985;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_4039 = cn_double(v35); __auto_type v = cn_init_4039;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_4090 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4090;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_4132 = cn_bits(f[0]); uint64_t v = cn_init_4132;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4228 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4228;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4294 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4294;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_4333 = cn_double(v16); __auto_type v = cn_init_4333;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_4413 = cn_double(v15); __auto_type v = cn_init_4413;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b4;
}
(f[0]=f[1]);
goto cn_break_b5;
}
cn_break_b4:;
(f[1]=f[1]);
}
cn_break_b5:;
{
__auto_type cn_init_4532 = cn_double(v30); __auto_type v = cn_init_4532;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_4551 = 0x0U; __auto_type bv = cn_init_4551;
__auto_type cn_init_4568 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_4568;
__auto_type cn_init_4586 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_4586;
}
if(cn_cond(fl,5)){
goto cn_break_b7;
}
{
__auto_type cn_init_4610 = cn_double(v28); __auto_type v = cn_init_4610;
(f[0]=(f[0]/v));
}
}
cn_break_b7:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_4641 = 0x32U; __auto_type bv = cn_init_4641;
__auto_type cn_init_4649 = rg[4]; __auto_type av = cn_init_4649;
__auto_type cn_init_4667 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_4667;
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
cn_wr64u(m,0x10007ee8U,s2013);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_333566b600828b95(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+216))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
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
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_423 = cn_double(v28); __auto_type v = cn_init_423;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_447 = cn_double(v30); __auto_type v = cn_init_447;
(f[0]=(f[0]+v));
}
(f[1]=f[0]);
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_525 = 0x41U; __auto_type bv = cn_init_525;
__auto_type cn_init_538 = cn_reg_get(rg,4,1); __auto_type av = cn_init_538;
__auto_type cn_init_556 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_556;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,15)){
goto cn_break_b2;
}
(f[1]=f[0]);
(f[1]=-f[1]);
(f[2]=cn_double(v29));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
goto cn_break_b3;
}
cn_break_b2:;
(f[1]=f[0]);
(f[2]=cn_double(v29));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
}
cn_break_b3:;
{
__auto_type cn_init_724 = cn_double(v27); __auto_type v = cn_init_724;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_748 = cn_double(v30); __auto_type v = cn_init_748;
(f[0]=(f[0]-v));
}
(r3=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[3]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
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
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_334f193283f9597c(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+144))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v18 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,8); uint64_t v19 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,16); uint64_t v20 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,24); uint64_t v21 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,32); uint64_t v22 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,40); uint64_t v23 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,48); uint64_t v24 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,56); uint64_t v25 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,64); uint64_t v26 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,72); uint64_t v27 = cn_init_325;
__auto_type cn_init_338 = cn_cell(vm,80); uint64_t v28 = cn_init_338;
__auto_type cn_init_351 = cn_cell(vm,88); uint64_t v29 = cn_init_351;
__auto_type cn_init_364 = cn_cell(vm,96); uint64_t v30 = cn_init_364;
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
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_642 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_642;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_690 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_690;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_753 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_753;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_816 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_816;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_864 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_864;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_927 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_927;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_989 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_989;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1036 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1036;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1098 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1098;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
cn_swap(f,2,1);
}
cn_break_b2:;
(f[2]=-f[2]);
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
cn_swap(f,2,1);
}
cn_break_b4:;
(f[2]=-f[2]);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b6;
}
cn_swap(f,2,0);
}
cn_break_b6:;
(f[2]=-f[2]);
cn_swap(f,2,1);
(f[3]=f[1]);
{
__auto_type cn_init_1443 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1443;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_1491 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1491;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1554 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1554;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_1617 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1617;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1665 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1665;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1728 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1728;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_1790 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1790;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_1837 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1837;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1899 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1899;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(v30));
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[3]));
(r6=cn_bits(f[4]));
(f[0]=(f[0]*f[3]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[3]-f[4]));
(f[4]=f[3]);
(f[5]=f[4]);
{
__auto_type cn_init_2080 = cn_double(v29); __auto_type v = cn_init_2080;
(f[5]=(f[5]*v));
}
(f[1]=(f[1]-f[5]));
{
__auto_type cn_init_2119 = cn_double(v28); __auto_type v = cn_init_2119;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]-f[4]));
{
__auto_type cn_init_2158 = cn_double(v27); __auto_type v = cn_init_2158;
(f[3]=(f[3]*v));
}
(f[0]=(f[0]-f[3]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
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
int cn_f_3546633fd6664de2(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+176))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_cell(vm,0); uint64_t v22 = cn_init_123;
__auto_type cn_init_136 = cn_cell(vm,8); uint64_t v23 = cn_init_136;
__auto_type cn_init_149 = cn_cell(vm,16); uint64_t v24 = cn_init_149;
__auto_type cn_init_162 = cn_cell(vm,24); uint64_t v25 = cn_init_162;
__auto_type cn_init_175 = cn_cell(vm,32); uint64_t v26 = cn_init_175;
__auto_type cn_init_188 = cn_cell(vm,40); uint64_t v27 = cn_init_188;
__auto_type cn_init_201 = cn_cell(vm,48); uint64_t v28 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,56); uint64_t v29 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,64); uint64_t v30 = cn_init_227;
{
{
{
{
(f[0]=cn_double(r5));
{
__auto_type cn_init_257 = 0x0U; __auto_type bv = cn_init_257;
__auto_type cn_init_274 = (((uint32_t)(((((v22>>0))&0xffffffffULL))))); __auto_type av = cn_init_274;
__auto_type cn_init_292 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_292;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(f[0]=fabs(f[0]));
}
cn_break_b2:;
(f[1]=cn_double(r4));
{
__auto_type cn_init_338 = 0x0U; __auto_type bv = cn_init_338;
__auto_type cn_init_355 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_355;
__auto_type cn_init_373 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_373;
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
(f[1]=fabs(f[1]));
}
cn_break_b4:;
(f[2]=cn_double(r3));
{
__auto_type cn_init_419 = 0x0U; __auto_type bv = cn_init_419;
__auto_type cn_init_436 = (((uint32_t)(((((v23>>0))&0xffffffffULL))))); __auto_type av = cn_init_436;
__auto_type cn_init_454 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_454;
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
(f[2]=fabs(f[2]));
}
cn_break_b6:;
(f[3]=f[2]);
{
__auto_type cn_init_517 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_517;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_565 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_565;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_628 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_628;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_691 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_691;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_739 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_739;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_802 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_802;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_864 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_864;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_911 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_911;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_973 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_973;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1012 = cn_double(v30); __auto_type v = cn_init_1012;
(f[2]=(f[2]+v));
}
(r3=cn_bits(f[2]));
{
__auto_type cn_init_1047 = cn_double(v29); __auto_type v = cn_init_1047;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_1082 = cn_double(v28); __auto_type v = cn_init_1082;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_354e2b1115793e88(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_152 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_178;
__auto_type cn_init_191 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_191;
__auto_type cn_init_204 = cn_cell(vm,0); uint64_t v27 = cn_init_204;
__auto_type cn_init_217 = cn_cell(vm,8); uint64_t v28 = cn_init_217;
__auto_type cn_init_230 = cn_cell(vm,16); uint64_t v29 = cn_init_230;
__auto_type cn_init_243 = cn_cell(vm,24); uint64_t v30 = cn_init_243;
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
(rg[7]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
(f[2]=cn_double(r5));
(rg[1]=rg[0]);
(rg[2]=((uint32_t)(((((v30>>32))&0xffffffffULL)))));
{
__auto_type cn_init_590 = cn_map_px(true,((int32_t)(rg[EDX])),(CN_D3){cn_double(r3),cn_double(r4),cn_double(r5)}); __auto_type r = cn_init_590;
(r3=cn_bits(r[0]));
(r4=cn_bits(r[1]));
(r5=cn_bits(r[2]));
}
(f[3]=cn_double(r3));
{
__auto_type cn_init_661 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_661;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_699 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_699;
(f[3]=(f[3]*v));
}
(f[0]=(f[0]+f[3]));
(f[3]=cn_double(r4));
{
__auto_type cn_init_764 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_764;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_802 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_802;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[3]=cn_double(r5));
{
__auto_type cn_init_867 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_867;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_905 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_905;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
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
int cn_f_354eaa270ceeee89(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_229;
__auto_type cn_init_242 = cn_cell(vm,0); uint64_t v28 = cn_init_242;
__auto_type cn_init_255 = cn_cell(vm,8); uint64_t v29 = cn_init_255;
__auto_type cn_init_268 = cn_cell(vm,16); uint64_t v30 = cn_init_268;
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
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_600 = cn_double(r10); __auto_type v = cn_init_600;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_636 = cn_double(v30); __auto_type v = cn_init_636;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_672 = cn_double(v28); __auto_type v = cn_init_672;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_711 = cn_double(r4); __auto_type v = cn_init_711;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_735 = cn_double(r11); __auto_type v = cn_init_735;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_771 = cn_double(v30); __auto_type v = cn_init_771;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r4));
{
__auto_type cn_init_807 = cn_double(v29); __auto_type v = cn_init_807;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_846 = cn_double(r5); __auto_type v = cn_init_846;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_870 = cn_double(r12); __auto_type v = cn_init_870;
(f[2]=(f[2]+v));
}
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
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_359551ba93faa981(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+200))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_105;
__auto_type cn_init_118 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_118;
__auto_type cn_init_131 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_131;
__auto_type cn_init_144 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_144;
__auto_type cn_init_157 = cn_cell(vm,0); uint64_t v25 = cn_init_157;
__auto_type cn_init_170 = cn_cell(vm,8); uint64_t v26 = cn_init_170;
__auto_type cn_init_183 = cn_cell(vm,16); uint64_t v27 = cn_init_183;
__auto_type cn_init_196 = cn_cell(vm,24); uint64_t v28 = cn_init_196;
__auto_type cn_init_209 = cn_cell(vm,32); uint64_t v29 = cn_init_209;
__auto_type cn_init_222 = cn_cell(vm,40); uint64_t v30 = cn_init_222;
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
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[2])))&0xffffffffULL))<<0))));
}
(f[0]=cn_double(r3));
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
{
__auto_type cn_init_423 = (((uint32_t)(((((r3>>56))&0xffULL))))); __auto_type v = cn_init_423;
cn_reg_set(rg,2,1,v);
}
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_465 = cn_double(v26); __auto_type v = cn_init_465;
(f[0]=(f[0]*v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_503 = cn_double(v30); __auto_type v = cn_init_503;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[0]=-f[0]);
{
__auto_type cn_init_565 = cn_double(v29); __auto_type v = cn_init_565;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_616 = cn_double(v25); __auto_type v = cn_init_616;
(f[1]=(f[1]*v));
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_654 = cn_double(v28); __auto_type v = cn_init_654;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_673 = 0x80U; __auto_type bv = cn_init_673;
__auto_type cn_init_686 = cn_reg_get(rg,2,1); __auto_type av = cn_init_686;
__auto_type cn_init_704 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_704;
cn_reg_set(rg,2,1,r);
}
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[2]/f[1]));
(f[1]=-f[1]);
{
__auto_type cn_init_767 = cn_double(v27); __auto_type v = cn_init_767;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]+f[1]));
(r3=cn_bits(f[0]));
{
__auto_type cn_init_820 = cn_reg_get(rg,2,1); __auto_type bv = cn_init_820;
__auto_type cn_init_837 = (((uint32_t)(((((r3>>56))&0xffULL))))); __auto_type av = cn_init_837;
__auto_type cn_init_855 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_855;
(r3=(((r3&~((0xffULL<<56))))|(((((((uint64_t)((r))))&0xffULL))<<56))));
}
{
(rg[2]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
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
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_36ef04a3636073d1(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+112))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(36)); uint64_t r36 = cn_init_173;
__auto_type cn_init_186 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_186;
__auto_type cn_init_199 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_199;
__auto_type cn_init_212 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_212;
__auto_type cn_init_225 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_225;
__auto_type cn_init_238 = cn_cell(vm,0); uint64_t v14 = cn_init_238;
__auto_type cn_init_251 = cn_cell(vm,8); uint64_t v15 = cn_init_251;
__auto_type cn_init_264 = cn_cell(vm,16); uint64_t v16 = cn_init_264;
__auto_type cn_init_277 = cn_cell(vm,24); uint64_t v17 = cn_init_277;
__auto_type cn_init_290 = cn_cell(vm,32); uint64_t v18 = cn_init_290;
__auto_type cn_init_303 = cn_cell(vm,40); uint64_t v19 = cn_init_303;
__auto_type cn_init_316 = cn_cell(vm,48); uint64_t v20 = cn_init_316;
__auto_type cn_init_329 = cn_cell(vm,56); uint64_t v21 = cn_init_329;
__auto_type cn_init_342 = cn_cell(vm,64); uint64_t v22 = cn_init_342;
__auto_type cn_init_355 = cn_cell(vm,72); uint64_t v23 = cn_init_355;
__auto_type cn_init_368 = cn_cell(vm,80); uint64_t v24 = cn_init_368;
__auto_type cn_init_381 = cn_cell(vm,88); uint64_t v25 = cn_init_381;
__auto_type cn_init_394 = cn_cell(vm,96); uint64_t v26 = cn_init_394;
__auto_type cn_init_407 = cn_cell(vm,104); uint64_t v27 = cn_init_407;
__auto_type cn_init_420 = cn_cell(vm,112); uint64_t v28 = cn_init_420;
__auto_type cn_init_433 = cn_cell(vm,120); uint64_t v29 = cn_init_433;
__auto_type cn_init_446 = cn_cell(vm,128); uint64_t v30 = cn_init_446;
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
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r6));
(f[0]=fabs(f[0]));
(f[1]=cn_double(r5));
(f[1]=fabs(f[1]));
(f[2]=cn_double(r4));
(f[2]=fabs(f[2]));
(f[3]=cn_double(r3));
(f[3]=fabs(f[3]));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
cn_swap(f,3,2);
}
cn_break_b2:;
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
cn_swap(f,3,1);
}
cn_break_b4:;
cn_swap(f,3,2);
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b6;
}
cn_swap(f,3,1);
}
cn_break_b6:;
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b8;
}
cn_swap(f,3,0);
}
cn_break_b8:;
cn_swap(f,3,2);
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b10;
}
cn_swap(f,3,0);
}
cn_break_b10:;
cn_swap(f,3,2);
cn_swap(f,3,1);
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b12;
}
cn_swap(f,3,0);
}
cn_break_b12:;
cn_swap(f,3,1);
(f[4]=cn_double(v16));
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(v17));
(f[2]=(f[2]+f[4]));
(f[4]=cn_double(v15));
(f[1]=(f[1]+f[4]));
(f[4]=cn_double(v14));
(f[0]=(f[0]+f[4]));
{
__auto_type cn_init_1452 = 0x28U; __auto_type bv = cn_init_1452;
__auto_type cn_init_1460 = rg[7]; __auto_type av = cn_init_1460;
__auto_type cn_init_1478 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_1478;
(rg[7]=r);
}
(f[4]=f[3]);
{
__auto_type cn_init_1521 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1521;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1569 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1569;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1632 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1632;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1695 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1695;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r3=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_1769 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1769;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1817 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1817;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1880 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1880;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1943 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1943;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r4=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_2017 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2017;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_2065 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2065;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_2128 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2128;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2191 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2191;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r5=cn_bits(f[4]));
{
__auto_type cn_init_2255 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2255;
(f[3]=(f[3]*v));
}
cn_swap(f,3,2);
{
__auto_type cn_init_2302 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2302;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
cn_swap(f,2,1);
{
__auto_type cn_init_2364 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2364;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
cn_swap(f,1,0);
{
__auto_type cn_init_2426 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2426;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2460 = 0x28U; __auto_type bv = cn_init_2460;
__auto_type cn_init_2468 = rg[7]; __auto_type av = cn_init_2468;
__auto_type cn_init_2486 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2486;
(rg[7]=r);
}
(f[1]=cn_double(v14));
(f[0]=(f[0]-f[1]));
(f[1]=cn_double(v30));
(f[0]=(f[0]*f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]-f[2]));
{
__auto_type cn_init_2586 = cn_double(v26); __auto_type v = cn_init_2586;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
(r6=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_2648 = cn_double(v15); __auto_type v = cn_init_2648;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_2684 = cn_double(v17); __auto_type v = cn_init_2684;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_2720 = cn_double(v16); __auto_type v = cn_init_2720;
(f[2]=(f[2]-v));
}
(f[3]=cn_double(v30));
(f[4]=cn_double(r36));
(f[4]=(f[4]*f[3]));
(r36=cn_bits(f[4]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
(f[4]=f[3]);
(f[5]=cn_double(0x3ff0000000000000));
(f[4]=(f[4]-f[5]));
(f[5]=f[4]);
(f[6]=f[5]);
{
__auto_type cn_init_2881 = cn_double(v29); __auto_type v = cn_init_2881;
(f[6]=(f[6]*v));
}
(f[1]=(f[1]-f[6]));
{
__auto_type cn_init_2920 = cn_double(v28); __auto_type v = cn_init_2920;
(f[5]=(f[5]*v));
}
(f[2]=(f[2]-f[5]));
(f[4]=(f[4]/f[3]));
{
__auto_type cn_init_2974 = cn_double(v27); __auto_type v = cn_init_2974;
(f[4]=(f[4]*v));
}
(f[0]=(f[0]-f[4]));
cn_swap(f,4,0);
(f[4]=fabs(f[4]));
(f[0]=(f[0]-f[4]));
(f[0]=(f[0]*f[3]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
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
cn_wr64(m,CN_REC+8*(36),r36);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_37744c623877da48(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
{
__auto_type cn_init_349 = 0xffffffe4U; __auto_type bv = cn_init_349;
__auto_type cn_init_357 = rg[4]; __auto_type av = cn_init_357;
__auto_type cn_init_375 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_375;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_404 = r5; uint64_t s = cn_init_404;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_434 = (CN_U2){v28,v29}; CN_U2 s = cn_init_434;
__auto_type cn_init_444 = m->xmm[0]; __auto_type a = cn_init_444;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_514 = v28; uint64_t s = cn_init_514;
__auto_type cn_init_527 = m->xmm[1][0]; __auto_type a = cn_init_527;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_574 = (CN_U2){v24,v25}; CN_U2 s = cn_init_574;
__auto_type cn_init_584 = m->xmm[0]; __auto_type a = cn_init_584;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_654 = v26; uint64_t s = cn_init_654;
__auto_type cn_init_667 = m->xmm[1][0]; __auto_type a = cn_init_667;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_704 = 0x0U; __auto_type bv = cn_init_704;
__auto_type cn_init_721 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_721;
__auto_type cn_init_739 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_739;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_760 = r32; uint64_t s = cn_init_760;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_782 = v28; uint64_t s = cn_init_782;
__auto_type cn_init_795 = m->xmm[5][0]; __auto_type a = cn_init_795;
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
(f[0]=cn_double(s2012));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2013));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
cn_swap(f,1,0);
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
{
__auto_type cn_init_1051 = 0x0U; __auto_type bv = cn_init_1051;
__auto_type cn_init_1068 = (((uint32_t)(((((v21>>0))&0xffffffffULL))))); __auto_type av = cn_init_1068;
__auto_type cn_init_1086 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1086;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_1141_0 = f[2];
__auto_type cn_tuple_1141_1 = f[1];
__auto_type x = cn_tuple_1141_0;
__auto_type y = cn_tuple_1141_1;
__auto_type cn_init_1170 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1170;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1202 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1202;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
}
cn_break_b4:;
(f[1]=cn_double(s2013));
(f[2]=cn_double(s2012));
(f[1]=atan2(f[1],f[2]));
{
__auto_type cn_init_1375 = cn_double(v30); __auto_type v = cn_init_1375;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=sin(f[0]));
(fsw&=~0x0400);
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1447 = cn_double(v23); __auto_type v = cn_init_1447;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1471 = cn_double(s2014); __auto_type v = cn_init_1471;
(f[0]=(f[0]+v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_1501 = 0x0U; __auto_type bv = cn_init_1501;
__auto_type cn_init_1518 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_1518;
__auto_type cn_init_1536 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1536;
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
{
__auto_type cn_init_1560 = cn_double(v28); __auto_type v = cn_init_1560;
(f[0]=(f[0]/v));
}
}
cn_break_b6:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_1591 = 0x1cU; __auto_type bv = cn_init_1591;
__auto_type cn_init_1599 = rg[4]; __auto_type av = cn_init_1599;
__auto_type cn_init_1617 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1617;
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
int cn_f_379b0161b71a06f6(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+152))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_214 = cn_cell(vm,0); uint64_t v19 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,8); uint64_t v20 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,16); uint64_t v21 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,24); uint64_t v22 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,32); uint64_t v23 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,40); uint64_t v24 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,48); uint64_t v25 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,56); uint64_t v26 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,64); uint64_t v27 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,72); uint64_t v28 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,80); uint64_t v29 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,88); uint64_t v30 = cn_init_357;
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
__auto_type cn_init_396 = 0xffffffe4U; __auto_type bv = cn_init_396;
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
{
__auto_type cn_init_751 = 0x0U; __auto_type bv = cn_init_751;
__auto_type cn_init_768 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_768;
__auto_type cn_init_786 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_786;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_807 = r32; uint64_t s = cn_init_807;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_829 = v28; uint64_t s = cn_init_829;
__auto_type cn_init_842 = m->xmm[5][0]; __auto_type a = cn_init_842;
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
{
__auto_type cn_init_964 = 0x0U; __auto_type bv = cn_init_964;
__auto_type cn_init_981 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_981;
__auto_type cn_init_999 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_999;
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
(f[0]=cn_double(s2012));
(f[1]=cn_double(s2014));
(s2012=cn_bits(f[1]));
(s2014=cn_bits(f[0]));
}
cn_break_b4:;
(f[0]=cn_double(s2014));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2013));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(s2012));
(f[2]=(f[2]*f[2]));
{
__auto_type cn_init_1167 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1167;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_1237 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1237;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1289 = cn_double(v23); __auto_type v = cn_init_1289;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1320 = 0x0U; __auto_type bv = cn_init_1320;
__auto_type cn_init_1337 = (((uint32_t)(((((v20>>0))&0xffffffffULL))))); __auto_type av = cn_init_1337;
__auto_type cn_init_1355 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1355;
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_1393 = cn_double(v30); __auto_type v = cn_init_1393;
(f[1]=(f[1]-v));
}
}
cn_break_b6:;
(f[2]=cn_double(s2013));
(f[2]=fabs(f[2]));
{
__auto_type cn_init_1444 = cn_double(v30); __auto_type v = cn_init_1444;
(f[2]=(f[2]-v));
}
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b8;
}
(f[2]=f[2]);
goto cn_break_b9;
}
cn_break_b8:;
(f[1]=f[2]);
}
cn_break_b9:;
(f[2]=cn_double(s2014));
(f[2]=fabs(f[2]));
{
__auto_type cn_init_1589 = cn_double(v30); __auto_type v = cn_init_1589;
(f[2]=(f[2]-v));
}
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b11;
}
(f[2]=f[2]);
goto cn_break_b12;
}
cn_break_b11:;
(f[1]=f[2]);
}
cn_break_b12:;
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b14;
}
(f[1]=f[1]);
goto cn_break_b15;
}
cn_break_b14:;
(f[0]=f[1]);
}
cn_break_b15:;
{
__auto_type cn_init_1798 = 0x0U; __auto_type bv = cn_init_1798;
__auto_type cn_init_1815 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_1815;
__auto_type cn_init_1833 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1833;
}
if(cn_cond(fl,5)){
goto cn_break_b17;
}
{
__auto_type cn_init_1857 = cn_double(v28); __auto_type v = cn_init_1857;
(f[0]=(f[0]/v));
}
}
cn_break_b17:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_1888 = 0x1cU; __auto_type bv = cn_init_1888;
__auto_type cn_init_1896 = rg[4]; __auto_type av = cn_init_1896;
__auto_type cn_init_1914 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1914;
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
int cn_f_37edf90f328708a6(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_195;
__auto_type cn_init_208 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,0); uint64_t v27 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,8); uint64_t v28 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,16); uint64_t v29 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,24); uint64_t v30 = cn_init_260;
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
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(v27));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_578 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_578;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(f[0]=cn_double(r6));
(f[1]=f[0]);
{
__auto_type cn_init_674 = cn_double(v27); __auto_type v = cn_init_674;
(f[1]=(f[1]/v));
}
(f[1]=cn_round(m,f[1]));
{
__auto_type cn_init_713 = cn_double(v27); __auto_type v = cn_init_713;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
(r6=cn_bits(f[0]));
}
cn_break_b2:;
(f[0]=cn_double(v28));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_814 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_814;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
(f[0]=cn_double(r5));
(f[1]=f[0]);
{
__auto_type cn_init_910 = cn_double(v28); __auto_type v = cn_init_910;
(f[1]=(f[1]/v));
}
(f[1]=cn_round(m,f[1]));
{
__auto_type cn_init_949 = cn_double(v28); __auto_type v = cn_init_949;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
(r5=cn_bits(f[0]));
}
cn_break_b4:;
(f[0]=cn_double(v29));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1050 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1050;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
(f[0]=cn_double(r4));
(f[1]=f[0]);
{
__auto_type cn_init_1146 = cn_double(v29); __auto_type v = cn_init_1146;
(f[1]=(f[1]/v));
}
(f[1]=cn_round(m,f[1]));
{
__auto_type cn_init_1185 = cn_double(v29); __auto_type v = cn_init_1185;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
(r4=cn_bits(f[0]));
}
cn_break_b6:;
(f[0]=cn_double(v30));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1286 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1286;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[0]=cn_double(r3));
(f[1]=f[0]);
{
__auto_type cn_init_1382 = cn_double(v30); __auto_type v = cn_init_1382;
(f[1]=(f[1]/v));
}
(f[1]=cn_round(m,f[1]));
{
__auto_type cn_init_1421 = cn_double(v30); __auto_type v = cn_init_1421;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
(r3=cn_bits(f[0]));
}
cn_break_b8:;
(rg[0]=rg[3]);
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_38a9042ac272996b(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_47 = 0ULL; __auto_type steps = cn_init_47;
__auto_type cn_init_52 = max_steps; __auto_type limit = cn_init_52;
__auto_type cn_init_62 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+216))); unsigned char * vm = cn_init_82;
__auto_type cn_init_99 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_99;
__auto_type cn_init_116 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_116;
__auto_type cn_init_133 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_133;
__auto_type cn_init_150 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_150;
__auto_type cn_init_167 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_167;
__auto_type cn_init_184 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_184;
__auto_type cn_init_201 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_201;
__auto_type cn_init_218 = cn_rd64(m,CN_REC+8*(14)); uint64_t r14 = cn_init_218;
__auto_type cn_init_231 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_231;
__auto_type cn_init_244 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_244;
__auto_type cn_init_257 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_257;
__auto_type cn_init_270 = cn_cell(vm,0); uint64_t v27 = cn_init_270;
__auto_type cn_init_283 = cn_cell(vm,8); uint64_t v28 = cn_init_283;
__auto_type cn_init_296 = cn_cell(vm,16); uint64_t v29 = cn_init_296;
__auto_type cn_init_309 = cn_cell(vm,24); uint64_t v30 = cn_init_309;
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
(f[0]=cn_double(0x3ff0000000000000));
(rg[0]=((uint32_t)(((((v30>>32))&0xffffffffULL)))));
(f[1]=cn_double(r14));
(f[1]=sqrt(f[1]));
cn_continue_l2:;
{
{
{
{
cn_shift_reg_l(rg,&fl,Shift_Shr,0,1,4);
if(cn_cond(fl,3)){
goto cn_break_b1;
}
(f[0]=(f[0]*f[1]));
if(cn_cond(fl,5)){
goto cn_break_b1;
}
(f[1]=f[1]);
(f[1]=cn_double(0x0));
(f[2]=cn_double(0x3ff0000000000000));
(f[3]=cn_double(r3));
(f[4]=cn_double(r4));
(f[5]=cn_double(r5));
(f[6]=f[3]);
(f[6]=(f[6]*f[6]));
(f[7]=f[4]);
(f[7]=(f[7]*f[7]));
(f[6]=(f[6]+f[7]));
(f[6]=sqrt(f[6]));
(f[5]=atan2(f[5],f[6]));
cn_swap(f,5,3);
(f[4]=atan2(f[4],f[5]));
(f[5]=(((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))));
(f[3]=(f[3]*f[5]));
(f[4]=(f[4]*f[5]));
{
__auto_type cn_init_881 = 0x0U; __auto_type bv = cn_init_881;
__auto_type cn_init_898 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_898;
__auto_type cn_init_916 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_916;
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
cn_swap(f,4,3);
}
cn_break_b6:;
{
__auto_type cn_init_945 = 0x0U; __auto_type bv = cn_init_945;
__auto_type cn_init_962 = (((uint32_t)(((((v28>>0))&0xffffffffULL))))); __auto_type av = cn_init_962;
__auto_type cn_init_980 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_980;
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[5]=f[3]);
(f[5]=(f[5]*f[5]));
(f[6]=f[4]);
(f[6]=(f[6]*f[6]));
(f[5]=(f[5]+f[6]));
{
__auto_type cn_init_1083 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1083;
(f[5]=(f[5]+v));
}
(f[6]=cn_double(0x3ff0000000000000));
(f[5]=(f[6]/f[5]));
(f[3]=(f[3]*f[5]));
(f[4]=(f[4]*f[5]));
}
cn_break_b8:;
(rg[0]=((uint32_t)(((((v28>>32))&0xffffffffULL)))));
cn_continue_l10:;
{
{
cn_shift_reg_l(rg,&fl,Shift_Shr,0,1,4);
if(cn_cond(fl,3)){
goto cn_break_b9;
}
(f[5]=f[2]);
(f[5]=(f[5]*f[4]));
(f[6]=f[1]);
(f[6]=(f[6]*f[3]));
(f[5]=(f[5]-f[6]));
cn_swap(f,5,2);
(f[5]=(f[5]*f[3]));
(f[6]=f[4]);
(f[1]=(f[1]*f[6]));
(f[1]=(f[1]+f[5]));
if(cn_cond(fl,5)){
goto cn_break_b9;
}
(fsw=cn_compare(f[4],f[3]));
(f[3]=(((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
{
__auto_type cn_tuple_1440_0 = sin(f[2]);
__auto_type cn_tuple_1440_1 = cos(f[2]);
__auto_type s = cn_tuple_1440_0;
__auto_type c = cn_tuple_1440_1;
(f[2]=s);
(f[3]=c);
(fsw&=~0x0400);
}
cn_swap(f,3,1);
{
__auto_type cn_tuple_1486_0 = sin(f[3]);
__auto_type cn_tuple_1486_1 = cos(f[3]);
__auto_type s = cn_tuple_1486_0;
__auto_type c = cn_tuple_1486_1;
(f[3]=s);
(f[4]=c);
(fsw&=~0x0400);
}
(f[4]=(f[4]*f[1]));
(f[4]=(f[4]*f[0]));
{
__auto_type cn_init_1547 = cn_double(r10); __auto_type v = cn_init_1547;
(f[4]=(f[4]+v));
}
(r3=cn_bits(f[4]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[0]));
{
__auto_type cn_init_1626 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1626;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1650 = cn_double(r12); __auto_type v = cn_init_1650;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_1700 = cn_double(r11); __auto_type v = cn_init_1700;
(f[0]=(f[0]+v));
}
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
cn_break_b9:;
(f[5]=f[3]);
(f[5]=(f[5]*f[4]));
(f[5]=(f[5]+f[5]));
cn_swap(f,5,3);
(f[5]=(f[5]*f[5]));
cn_swap(f,5,4);
(f[5]=(f[5]*f[5]));
(f[4]=(f[5]-f[4]));
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l10;
}
goto cn_continue_l10;
cn_break_l10:;
}
cn_break_b1:;
(f[1]=(f[1]*f[1]));
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l2;
}
goto cn_continue_l2;
cn_break_l2:;
}
cn_break_body:;
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_38cbe2a25848f82c(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+112))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001078U); uint64_t r15 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,0); uint64_t v14 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,8); uint64_t v15 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,16); uint64_t v16 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,24); uint64_t v17 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,32); uint64_t v18 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,40); uint64_t v19 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,48); uint64_t v20 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,56); uint64_t v21 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,64); uint64_t v22 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,72); uint64_t v23 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,80); uint64_t v24 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,88); uint64_t v25 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,96); uint64_t v26 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,104); uint64_t v27 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,112); uint64_t v28 = cn_init_422;
__auto_type cn_init_435 = cn_cell(vm,120); uint64_t v29 = cn_init_435;
__auto_type cn_init_448 = cn_cell(vm,128); uint64_t v30 = cn_init_448;
__auto_type cn_init_461 = cn_cell(vm,144); uint64_t v32 = cn_init_461;
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
__auto_type cn_init_506 = 0xffffffd4U; __auto_type bv = cn_init_506;
__auto_type cn_init_514 = rg[4]; __auto_type av = cn_init_514;
__auto_type cn_init_532 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_532;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_561 = r5; uint64_t s = cn_init_561;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_591 = (CN_U2){v28,v29}; CN_U2 s = cn_init_591;
__auto_type cn_init_601 = m->xmm[0]; __auto_type a = cn_init_601;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_671 = v28; uint64_t s = cn_init_671;
__auto_type cn_init_684 = m->xmm[1][0]; __auto_type a = cn_init_684;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_731 = (CN_U2){v24,v25}; CN_U2 s = cn_init_731;
__auto_type cn_init_741 = m->xmm[0]; __auto_type a = cn_init_741;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_811 = v26; uint64_t s = cn_init_811;
__auto_type cn_init_824 = m->xmm[1][0]; __auto_type a = cn_init_824;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_861 = 0x0U; __auto_type bv = cn_init_861;
__auto_type cn_init_878 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_878;
__auto_type cn_init_896 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_896;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_917 = r32; uint64_t s = cn_init_917;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_939 = v28; uint64_t s = cn_init_939;
__auto_type cn_init_952 = m->xmm[5][0]; __auto_type a = cn_init_952;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(s2010=m->xmm[0][0]);
(s2011=m->xmm[0][1]);
(s2012=m->xmm[1][0]);
{
__auto_type cn_init_1074 = 0xffffffd4U; __auto_type bv = cn_init_1074;
__auto_type cn_init_1082 = rg[7]; __auto_type av = cn_init_1082;
__auto_type cn_init_1100 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1100;
(rg[7]=r);
}
(f[0]=cn_double(s2012));
(f[1]=cn_double(s2011));
(f[2]=cn_double(s2010));
(f[3]=f[2]);
{
__auto_type cn_init_1179 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1179;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1227 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1227;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1290 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1290;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1353 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1353;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1401 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1401;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1464 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1464;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1526 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1526;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1573 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1573;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1635 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1635;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(s2010=cn_bits(f[2]));
(s2011=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
{
__auto_type cn_init_1702 = 0x2cU; __auto_type bv = cn_init_1702;
__auto_type cn_init_1710 = rg[7]; __auto_type av = cn_init_1710;
__auto_type cn_init_1728 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1728;
(rg[7]=r);
}
{
__auto_type cn_init_1742 = 0x1U; __auto_type bv = cn_init_1742;
__auto_type cn_init_1759 = (((uint32_t)(((((v17>>32))&0xffffffffULL))))); __auto_type av = cn_init_1759;
__auto_type cn_init_1777 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1777;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
(f[0]=cn_double(s2010));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2011));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[1]=f[0]);
{
__auto_type cn_init_1907 = cn_double(s2010); __auto_type v = cn_init_1907;
(f[1]=(f[1]*v));
}
(s2010=cn_bits(f[1]));
{
__auto_type cn_init_1942 = cn_double(s2011); __auto_type v = cn_init_1942;
(f[0]=(f[0]*v));
}
(s2011=cn_bits(f[0]));
}
cn_break_b4:;
{
__auto_type cn_init_1973 = 0x2U; __auto_type bv = cn_init_1973;
__auto_type cn_init_1990 = (((uint32_t)(((((v17>>32))&0xffffffffULL))))); __auto_type av = cn_init_1990;
__auto_type cn_init_2008 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2008;
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
(f[0]=cn_double(s2010));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2011));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[1]=cn_double(s2010));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(s2011));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]-f[2]));
(f[1]=(f[1]*f[0]));
(f[2]=cn_double(s2010));
(f[2]=(f[2]+f[2]));
(f[2]=-f[2]);
(f[2]=(f[2]*f[0]));
(s2011=cn_bits(f[2]));
(s2010=cn_bits(f[1]));
(f[0]=f[0]);
}
cn_break_b6:;
{
__auto_type cn_init_2347 = 0x3U; __auto_type bv = cn_init_2347;
__auto_type cn_init_2364 = (((uint32_t)(((((v17>>32))&0xffffffffULL))))); __auto_type av = cn_init_2364;
__auto_type cn_init_2382 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2382;
}
if(cn_cond(fl,5)){
goto cn_break_b8;
}
(f[0]=cn_double(s2010));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2011));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(0x3ff0000000000000));
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[1]=f[0]);
{
__auto_type cn_init_2547 = cn_double(s2010); __auto_type v = cn_init_2547;
(f[1]=(f[1]*v));
}
(s2010=cn_bits(f[1]));
{
__auto_type cn_init_2582 = cn_double(s2011); __auto_type v = cn_init_2582;
(f[0]=(f[0]*v));
}
(s2011=cn_bits(f[0]));
}
cn_break_b8:;
{
__auto_type cn_init_2613 = 0x4U; __auto_type bv = cn_init_2613;
__auto_type cn_init_2630 = (((uint32_t)(((((v17>>32))&0xffffffffULL))))); __auto_type av = cn_init_2630;
__auto_type cn_init_2648 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2648;
}
if(cn_cond(fl,5)){
goto cn_break_b10;
}
(f[0]=cn_double(s2010));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2011));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(s2011));
(f[2]=cn_double(s2010));
(f[1]=atan2(f[1],f[2]));
(s2011=cn_bits(f[1]));
(s2010=cn_bits(f[0]));
}
cn_break_b10:;
(f[0]=cn_double(s2010));
{
__auto_type cn_init_2832 = cn_double(v23); __auto_type v = cn_init_2832;
(f[0]=(f[0]*v));
}
(f[0]=sin(f[0]));
(fsw&=~0x0400);
(f[1]=cn_double(s2011));
{
__auto_type cn_init_2887 = cn_double(v23); __auto_type v = cn_init_2887;
(f[1]=(f[1]*v));
}
(f[1]=sin(f[1]));
(fsw&=~0x0400);
(f[0]=(f[0]*f[1]));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b12;
}
(f[1]=cn_double(((((((v16>>32))|((v17<<32))))&0xffffffffffffffffULL))));
goto cn_break_b13;
}
cn_break_b12:;
(f[1]=cn_double(((((((v15>>32))|((v16<<32))))&0xffffffffffffffffULL))));
}
cn_break_b13:;
(f[2]=(((double)(((int32_t)(((uint32_t)(((((r15>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_3112 = cn_double(((((((v14>>32))|((v15<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3112;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r34=cn_bits(f[1]));
{
__auto_type cn_init_3162 = cn_double(v32); __auto_type v = cn_init_3162;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3186 = cn_double(v23); __auto_type v = cn_init_3186;
(f[0]=(f[0]/v));
}
(f[1]=cn_double(s2012));
(f[1]=-f[1]);
(s2012=cn_bits(f[1]));
{
__auto_type cn_init_3244 = cn_double(v30); __auto_type v = cn_init_3244;
(f[1]=(f[1]+v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b15;
}
(f[0]=f[1]);
goto cn_break_b16;
}
cn_break_b15:;
(f[1]=f[1]);
}
cn_break_b16:;
(f[1]=cn_double(s2012));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b18;
}
(f[1]=f[1]);
goto cn_break_b19;
}
cn_break_b18:;
(f[0]=f[1]);
}
cn_break_b19:;
{
__auto_type cn_init_3465 = 0x0U; __auto_type bv = cn_init_3465;
__auto_type cn_init_3482 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_3482;
__auto_type cn_init_3500 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3500;
}
if(cn_cond(fl,5)){
goto cn_break_b21;
}
{
__auto_type cn_init_3524 = cn_double(v28); __auto_type v = cn_init_3524;
(f[0]=(f[0]/v));
}
}
cn_break_b21:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_3555 = 0x2cU; __auto_type bv = cn_init_3555;
__auto_type cn_init_3563 = rg[4]; __auto_type av = cn_init_3563;
__auto_type cn_init_3581 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3581;
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
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
