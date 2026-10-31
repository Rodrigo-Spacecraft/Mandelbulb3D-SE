/* Generated native C formula calculations. See tools/generate-native-c.py. */
#include "runtime.h"
int cn_f_9bb35860d75f1ec8(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_47 = 0ULL; __auto_type steps = cn_init_47;
__auto_type cn_init_52 = max_steps; __auto_type limit = cn_init_52;
__auto_type cn_init_62 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+208))); unsigned char * vm = cn_init_82;
__auto_type cn_init_99 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_99;
__auto_type cn_init_116 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_116;
__auto_type cn_init_133 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_133;
__auto_type cn_init_146 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_146;
__auto_type cn_init_159 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_159;
__auto_type cn_init_172 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_172;
__auto_type cn_init_185 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_185;
__auto_type cn_init_198 = cn_cell(vm,0); uint64_t v26 = cn_init_198;
__auto_type cn_init_211 = cn_cell(vm,8); uint64_t v27 = cn_init_211;
__auto_type cn_init_224 = cn_cell(vm,16); uint64_t v28 = cn_init_224;
__auto_type cn_init_237 = cn_cell(vm,24); uint64_t v29 = cn_init_237;
__auto_type cn_init_250 = cn_cell(vm,32); uint64_t v30 = cn_init_250;
__auto_type cn_init_263 = cn_cell(vm,48); uint64_t v32 = cn_init_263;
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
(f[0]=cn_double(r3));
(f[0]=fabs(f[0]));
(f[1]=cn_double(r5));
(f[1]=fabs(f[1]));
(f[2]=f[1]);
(f[2]=(f[2]+f[0]));
(f[3]=f[1]);
(f[3]=(f[3]-f[0]));
{
__auto_type cn_init_624 = cn_double(v29); __auto_type v = cn_init_624;
(f[3]=(f[3]-v));
}
(r3=cn_bits(f[3]));
{
__auto_type cn_init_659 = cn_double(v28); __auto_type v = cn_init_659;
(f[2]=(f[2]-v));
}
(r5=cn_bits(f[2]));
(f[1]=f[1]);
(f[0]=f[0]);
(f[0]=cn_double(r3));
(f[0]=fabs(f[0]));
(f[0]=-f[0]);
(f[1]=cn_double(r5));
(f[2]=f[1]);
(f[2]=(f[0]-f[2]));
(f[3]=f[1]);
(f[3]=(f[3]+f[0]));
(f[3]=-f[3]);
{
__auto_type cn_init_824 = cn_double(v27); __auto_type v = cn_init_824;
(f[3]=(f[3]-v));
}
{
__auto_type cn_init_848 = cn_double(v32); __auto_type v = cn_init_848;
(f[3]=(f[3]*v));
}
(r3=cn_bits(f[3]));
{
__auto_type cn_init_883 = cn_double(v27); __auto_type v = cn_init_883;
(f[2]=(f[2]-v));
}
{
__auto_type cn_init_907 = cn_double(v32); __auto_type v = cn_init_907;
(f[2]=(f[2]*v));
}
(r5=cn_bits(f[2]));
(f[1]=f[1]);
(f[0]=f[0]);
(f[0]=cn_double(v30));
(f[1]=cn_double(r3));
(fsw=cn_compare(f[1],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b4;
}
(rg[0]=((uint32_t)(((((v26>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1068 = rg[0]; __auto_type v = cn_init_1068;
__auto_type cn_init_1075 = fl.cf; __auto_type cf = cn_init_1075;
__auto_type cn_init_1093 = cn_alu(&fl,Alu_Sub,v,1,4); __auto_type r = cn_init_1093;
(fl.cf=cf);
(rg[0]=r);
}
if(cn_cond(fl,14)){
goto cn_break_b4;
}
{
__auto_type cn_init_1125 = 0x3e7U; __auto_type bv = cn_init_1125;
__auto_type cn_init_1133 = rg[0]; __auto_type av = cn_init_1133;
__auto_type cn_init_1151 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1151;
}
if(cn_cond(fl,15)){
goto cn_break_b4;
}
cn_continue_l3:;
{
(f[1]=(f[0]-f[1]));
(f[1]=fabs(f[1]));
(f[1]=(f[0]-f[1]));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_1235 = rg[0]; __auto_type v = cn_init_1235;
__auto_type cn_init_1242 = fl.cf; __auto_type cf = cn_init_1242;
__auto_type cn_init_1260 = cn_alu(&fl,Alu_Sub,v,1,4); __auto_type r = cn_init_1260;
(fl.cf=cf);
(rg[0]=r);
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
(f[0]=f[1]);
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
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_9caf95e667741341(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+216))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_359 = cn_cell(vm,0); uint64_t v27 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,8); uint64_t v28 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,16); uint64_t v29 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,24); uint64_t v30 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,40); uint64_t v32 = cn_init_411;
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
__auto_type cn_init_489 = 0x40U; __auto_type bv = cn_init_489;
__auto_type cn_init_497 = rg[4]; __auto_type av = cn_init_497;
__auto_type cn_init_515 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_515;
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
(s2006=cn_bits(f[0]));
(f[1]=cn_double(v30));
cn_swap(f,1,0);
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_935_0 = f[2];
__auto_type cn_tuple_935_1 = f[1];
__auto_type x = cn_tuple_935_0;
__auto_type y = cn_tuple_935_1;
__auto_type cn_init_964 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_964;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_996 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_996;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
(s2013=cn_bits(f[0]));
{
__auto_type cn_init_1132 = 0x0U; __auto_type bv = cn_init_1132;
__auto_type cn_init_1149 = (((uint32_t)(((((v27>>32))&0xffffffffULL))))); __auto_type av = cn_init_1149;
__auto_type cn_init_1167 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1167;
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
(f[0]=cn_double(s2013));
(s2006=cn_bits(f[0]));
goto cn_break_b3;
}
cn_break_b2:;
(f[0]=cn_double(s2006));
(f[1]=cn_double(v29));
cn_swap(f,1,0);
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_1310_0 = f[2];
__auto_type cn_tuple_1310_1 = f[1];
__auto_type x = cn_tuple_1310_0;
__auto_type y = cn_tuple_1310_1;
__auto_type cn_init_1339 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1339;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1371 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1371;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
(s2006=cn_bits(f[0]));
}
cn_break_b3:;
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(r5));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_1721 = cn_double(r4); __auto_type v = cn_init_1721;
(f[1]=(f[1]+v));
}
(f[0]=atan2(f[0],f[1]));
(f[0]=(f[0]+f[0]));
{
__auto_type cn_init_1778 = cn_double(v29); __auto_type v = cn_init_1778;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1808_0 = sin(f[0]);
__auto_type cn_tuple_1808_1 = cos(f[0]);
__auto_type s = cn_tuple_1808_0;
__auto_type c = cn_tuple_1808_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2012=cn_bits(f[1]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(r3));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1898 = 0x0U; __auto_type bv = cn_init_1898;
__auto_type cn_init_1915 = (((uint32_t)(((((v27>>0))&0xffffffffULL))))); __auto_type av = cn_init_1915;
__auto_type cn_init_1933 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1933;
}
if(cn_cond(fl,5)){
goto cn_break_b8;
}
(f[1]=cn_double(r3));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2013 = 0x41U; __auto_type bv = cn_init_2013;
__auto_type cn_init_2026 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2026;
__auto_type cn_init_2044 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2044;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b8;
}
(f[1]=cn_double(r5));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2137 = 0x41U; __auto_type bv = cn_init_2137;
__auto_type cn_init_2150 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2150;
__auto_type cn_init_2168 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2168;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b7;
}
(f[1]=cn_double(0x400921fb54442d18));
{
__auto_type cn_init_2217 = cn_double(v32); __auto_type v = cn_init_2217;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
goto cn_break_b8;
}
cn_break_b7:;
(f[1]=cn_double(0x400921fb54442d18));
{
__auto_type cn_init_2272 = cn_double(v32); __auto_type v = cn_init_2272;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
}
cn_break_b8:;
{
__auto_type cn_init_2312 = cn_double(v29); __auto_type v = cn_init_2312;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_2342_0 = sin(f[0]);
__auto_type cn_tuple_2342_1 = cos(f[0]);
__auto_type s = cn_tuple_2342_0;
__auto_type c = cn_tuple_2342_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2010=cn_bits(f[1]));
(s2009=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_2407 = cn_double(s2011); __auto_type v = cn_init_2407;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2431 = cn_double(s2009); __auto_type v = cn_init_2431;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2455 = cn_double(r10); __auto_type v = cn_init_2455;
(f[0]=(f[0]+v));
}
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_2502 = cn_double(s2012); __auto_type v = cn_init_2502;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2526 = cn_double(r11); __auto_type v = cn_init_2526;
(f[0]=(f[0]+v));
}
(s2007=cn_bits(f[0]));
(f[0]=cn_double(s2006));
{
__auto_type cn_init_2573 = cn_double(s2010); __auto_type v = cn_init_2573;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2597 = cn_double(s2011); __auto_type v = cn_init_2597;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2621 = cn_double(v28); __auto_type v = cn_init_2621;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2645 = cn_double(r12); __auto_type v = cn_init_2645;
(f[0]=(f[0]+v));
}
(s2006=cn_bits(f[0]));
(f[0]=cn_double(s2008));
(f[1]=cn_double(s2007));
(f[2]=cn_double(s2006));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
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
int cn_f_9cd737f7d9103ebe(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+176))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_190;
__auto_type cn_init_207 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_207;
__auto_type cn_init_220 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_220;
__auto_type cn_init_233 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_233;
__auto_type cn_init_246 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_246;
__auto_type cn_init_259 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_259;
__auto_type cn_init_272 = cn_cell(vm,0); uint64_t v22 = cn_init_272;
__auto_type cn_init_285 = cn_cell(vm,8); uint64_t v23 = cn_init_285;
__auto_type cn_init_298 = cn_cell(vm,16); uint64_t v24 = cn_init_298;
__auto_type cn_init_311 = cn_cell(vm,24); uint64_t v25 = cn_init_311;
__auto_type cn_init_324 = cn_cell(vm,32); uint64_t v26 = cn_init_324;
__auto_type cn_init_337 = cn_cell(vm,40); uint64_t v27 = cn_init_337;
__auto_type cn_init_350 = cn_cell(vm,48); uint64_t v28 = cn_init_350;
__auto_type cn_init_363 = cn_cell(vm,56); uint64_t v29 = cn_init_363;
__auto_type cn_init_376 = cn_cell(vm,64); uint64_t v30 = cn_init_376;
__auto_type cn_init_389 = cn_cell(vm,80); uint64_t v32 = cn_init_389;
__auto_type cn_init_402 = cn_cell(vm,88); uint64_t v33 = cn_init_402;
__auto_type cn_init_415 = cn_cell(vm,96); uint64_t v34 = cn_init_415;
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
(f[0]=cn_double(r6));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=f[0]);
(fsw=cn_compare(f[1],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_909 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_909;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,4)){
goto cn_break_b5;
}
(f[1]=f[0]);
(f[2]=cn_double(r3));
(f[1]=atan2(f[1],f[2]));
(f[2]=f[0]);
(f[1]=(f[1]/f[2]));
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[2]));
(f[3]=f[0]);
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[3]=f[2]);
(f[4]=cn_double(v32));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_1169 = 0x41U; __auto_type bv = cn_init_1169;
__auto_type cn_init_1182 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1182;
__auto_type cn_init_1200 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1200;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b3;
}
(f[3]=f[2]);
(f[4]=cn_double(0x3fe62e42fefa39ef));
cn_swap(f,4,3);
(f[3]*=log2(f[4]));
{
__auto_type cn_init_1282 = cn_double(v33); __auto_type v = cn_init_1282;
(f[3]=(f[3]*v));
}
goto cn_break_b4;
}
cn_break_b3:;
(f[3]=cn_double(v34));
}
cn_break_b4:;
(r3=cn_bits(f[3]));
(f[3]=cn_double(r4));
(f[3]=(f[3]*f[1]));
(r4=cn_bits(f[3]));
(f[3]=cn_double(r5));
(f[3]=(f[3]*f[1]));
(r5=cn_bits(f[3]));
(f[3]=cn_double(r6));
(f[3]=(f[3]*f[1]));
(r6=cn_bits(f[3]));
(f[2]=f[2]);
(f[1]=f[1]);
(f[0]=f[0]);
goto cn_break_b8;
}
cn_break_b5:;
(f[0]=f[0]);
(f[0]=cn_double(r3));
(f[1]=cn_double(v32));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_1548 = 0x41U; __auto_type bv = cn_init_1548;
__auto_type cn_init_1561 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1561;
__auto_type cn_init_1579 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1579;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b7;
}
(f[0]=cn_double(r3));
(f[1]=cn_double(0x3fe62e42fefa39ef));
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
(r3=cn_bits(f[0]));
goto cn_break_b8;
}
cn_break_b7:;
(f[0]=cn_double(v34));
(r3=cn_bits(f[0]));
}
cn_break_b8:;
(f[0]=cn_double(r6));
(f[1]=cn_double(v23));
(f[0]=(f[0]*f[1]));
(r6=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(v24));
(f[0]=(f[0]*f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[1]=cn_double(v25));
(f[0]=(f[0]*f[1]));
(r4=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[1]=cn_double(v26));
(f[0]=(f[0]*f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1914 = cn_double(v30); __auto_type v = cn_init_1914;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1950 = cn_double(v29); __auto_type v = cn_init_1950;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_2012 = cn_double(v28); __auto_type v = cn_init_2012;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r6));
{
__auto_type cn_init_2074 = cn_double(v27); __auto_type v = cn_init_2074;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r3));
{
__auto_type cn_init_2136 = cn_double(v29); __auto_type v = cn_init_2136;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r4));
{
__auto_type cn_init_2172 = cn_double(v30); __auto_type v = cn_init_2172;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r5));
{
__auto_type cn_init_2223 = cn_double(v27); __auto_type v = cn_init_2223;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r6));
{
__auto_type cn_init_2274 = cn_double(v28); __auto_type v = cn_init_2274;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r3));
{
__auto_type cn_init_2336 = cn_double(v28); __auto_type v = cn_init_2336;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r4));
{
__auto_type cn_init_2372 = cn_double(v27); __auto_type v = cn_init_2372;
(f[3]=(f[3]*v));
}
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r5));
{
__auto_type cn_init_2434 = cn_double(v30); __auto_type v = cn_init_2434;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r6));
{
__auto_type cn_init_2485 = cn_double(v29); __auto_type v = cn_init_2485;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
{
__auto_type cn_init_2536 = cn_double(v27); __auto_type v = cn_init_2536;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r4));
{
__auto_type cn_init_2572 = cn_double(v28); __auto_type v = cn_init_2572;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r5));
{
__auto_type cn_init_2623 = cn_double(v29); __auto_type v = cn_init_2623;
(f[4]=(f[4]*v));
}
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r6));
{
__auto_type cn_init_2685 = cn_double(v30); __auto_type v = cn_init_2685;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(r6=cn_bits(f[3]));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r6));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=f[0]);
{
__auto_type cn_tuple_2909_0 = sin(f[1]);
__auto_type cn_tuple_2909_1 = cos(f[1]);
__auto_type s = cn_tuple_2909_0;
__auto_type c = cn_tuple_2909_1;
(f[1]=s);
(f[2]=c);
(fsw&=~0x0400);
}
(f[3]=cn_double(r3));
(f[4]=cn_double(0x3ff71547652b82fe));
(f[3]=(f[3]*f[4]));
(f[4]=cn_double(0x3ff0000000000000));
(f[5]=f[3]);
{
__auto_type cn_tuple_3010_0 = f[5];
__auto_type cn_tuple_3010_1 = f[4];
__auto_type x = cn_tuple_3010_0;
__auto_type y = cn_tuple_3010_1;
__auto_type cn_init_3039 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_3039;
(f[5]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_3071 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_3071;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[5]=(exp2(f[5])-1.0));
(f[4]=(f[4]+f[5]));
(f[4]*=exp2(trunc(f[3])));
cn_swap(f,4,3);
(f[4]=f[4]);
(f[4]=f[3]);
(f[4]=(f[4]*f[2]));
(r3=cn_bits(f[4]));
(f[3]=(f[3]*f[1]));
(f[4]=f[0]);
(f[5]=cn_double(v32));
(fsw=cn_compare(f[5],f[4]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
{
__auto_type cn_init_3306 = 0x41U; __auto_type bv = cn_init_3306;
__auto_type cn_init_3319 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3319;
__auto_type cn_init_3337 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3337;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b10;
}
(f[3]=(f[3]/f[0]));
}
cn_break_b10:;
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[3]));
(r4=cn_bits(f[4]));
(f[4]=cn_double(r5));
(f[4]=(f[4]*f[3]));
(r5=cn_bits(f[4]));
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[3]));
(r6=cn_bits(f[4]));
(f[3]=f[3]);
(f[2]=f[2]);
(f[1]=f[1]);
(f[0]=f[0]);
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=cn_double(r10));
{
__auto_type cn_init_3592 = cn_double(v22); __auto_type v = cn_init_3592;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r3=cn_bits(f[2]));
(f[2]=cn_double(r11));
{
__auto_type cn_init_3654 = cn_double(v22); __auto_type v = cn_init_3654;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r4=cn_bits(f[1]));
(f[1]=cn_double(r12));
{
__auto_type cn_init_3716 = cn_double(v22); __auto_type v = cn_init_3716;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r5=cn_bits(f[0]));
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
int cn_f_9d19f3e50467fca6(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_203 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_268;
__auto_type cn_init_281 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_281;
__auto_type cn_init_294 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,0); uint64_t v29 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,8); uint64_t v30 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,24); uint64_t v32 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,32); uint64_t v33 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,40); uint64_t v34 = cn_init_359;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_425 = 0x30U; __auto_type bv = cn_init_425;
__auto_type cn_init_433 = rg[4]; __auto_type av = cn_init_433;
__auto_type cn_init_451 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_451;
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
__auto_type cn_init_667 = cn_double(v32); __auto_type v = cn_init_667;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_703 = cn_double(v33); __auto_type v = cn_init_703;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_753 = cn_double(v34); __auto_type v = cn_init_753;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_800 = cn_double(v34); __auto_type v = cn_init_800;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_847 = cn_double(v33); __auto_type v = cn_init_847;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_883 = cn_double(v32); __auto_type v = cn_init_883;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2013));
{
__auto_type cn_init_934 = cn_double(r4); __auto_type v = cn_init_934;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(s2013));
{
__auto_type cn_init_970 = cn_double(r4); __auto_type v = cn_init_970;
(f[2]=(f[2]+v));
}
(f[2]=(f[2]*f[2]));
(s2012=cn_bits(f[2]));
(f[1]=(f[1]*f[1]));
(s2013=cn_bits(f[1]));
(f[0]=(f[0]*f[0]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_1084 = cn_double(r5); __auto_type v = cn_init_1084;
(f[0]=(f[0]+v));
}
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1122 = cn_double(v29); __auto_type v = cn_init_1122;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1160 = cn_double(v30); __auto_type v = cn_init_1160;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1184 = cn_double(v34); __auto_type v = cn_init_1184;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1231 = cn_double(r5); __auto_type v = cn_init_1231;
(f[0]=(f[0]+v));
}
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1269 = cn_double(v29); __auto_type v = cn_init_1269;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1307 = cn_double(v30); __auto_type v = cn_init_1307;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1331 = cn_double(v34); __auto_type v = cn_init_1331;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1378 = cn_double(s2012); __auto_type v = cn_init_1378;
(f[0]=(f[0]+v));
}
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1416 = cn_double(v29); __auto_type v = cn_init_1416;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1454 = cn_double(v30); __auto_type v = cn_init_1454;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1501 = cn_double(r3); __auto_type v = cn_init_1501;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1537 = cn_double(r3); __auto_type v = cn_init_1537;
(f[1]=(f[1]-v));
}
(r4=cn_bits(f[1]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1595 = cn_double(v32); __auto_type v = cn_init_1595;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1631 = cn_double(v33); __auto_type v = cn_init_1631;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1682 = cn_double(v33); __auto_type v = cn_init_1682;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[2]=cn_double(r5));
{
__auto_type cn_init_1729 = cn_double(v32); __auto_type v = cn_init_1729;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r5=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=(f[0]*f[0]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=(f[0]*f[0]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1943 = cn_double(s2011); __auto_type v = cn_init_1943;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(f[0]=(f[0]/f[1]));
(s2010=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_2019 = cn_double(s2012); __auto_type v = cn_init_2019;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2043 = cn_double(s2011); __auto_type v = cn_init_2043;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2010));
(f[2]=cn_double(s2012));
{
__auto_type cn_init_2091 = cn_double(s2011); __auto_type v = cn_init_2091;
(f[2]=(f[2]-v));
}
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(s2010));
(f[2]=(f[2]+f[2]));
{
__auto_type cn_init_2157 = cn_double(r5); __auto_type v = cn_init_2157;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_2181 = cn_double(r4); __auto_type v = cn_init_2181;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_2205 = cn_double(r11); __auto_type v = cn_init_2205;
(f[2]=(f[2]+v));
}
(r4=cn_bits(f[2]));
{
__auto_type cn_init_2240 = cn_double(r12); __auto_type v = cn_init_2240;
(f[1]=(f[1]+v));
}
(r5=cn_bits(f[1]));
{
__auto_type cn_init_2275 = cn_double(r10); __auto_type v = cn_init_2275;
(f[0]=(f[0]+v));
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
int cn_f_9d2a79825b93b352(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_156 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_182;
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
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=rg[0]);
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[0]);
(f[3]=(f[3]*f[0]));
(f[4]=f[1]);
(f[4]=(f[4]*f[1]));
(f[5]=f[2]);
(f[5]=(f[5]*f[2]));
(fsw=cn_compare(f[5],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
{
__auto_type cn_init_526 = 0x41U; __auto_type bv = cn_init_526;
__auto_type cn_init_539 = cn_reg_get(rg,4,1); __auto_type av = cn_init_539;
__auto_type cn_init_557 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_557;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
cn_swap(f,5,3);
cn_swap(f,5,2);
cn_swap(f,5,0);
cn_swap(f,5,2);
}
cn_break_b2:;
(fsw=cn_compare(f[5],f[4]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
{
__auto_type cn_init_663 = 0x41U; __auto_type bv = cn_init_663;
__auto_type cn_init_676 = cn_reg_get(rg,4,1); __auto_type av = cn_init_676;
__auto_type cn_init_694 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_694;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
cn_swap(f,5,4);
cn_swap(f,5,2);
cn_swap(f,5,1);
cn_swap(f,5,2);
}
cn_break_b4:;
cn_swap(f,5,4);
(fsw=cn_compare(f[5],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
{
__auto_type cn_init_809 = 0x41U; __auto_type bv = cn_init_809;
__auto_type cn_init_822 = cn_reg_get(rg,4,1); __auto_type av = cn_init_822;
__auto_type cn_init_840 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_840;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
cn_swap(f,5,3);
cn_swap(f,5,1);
cn_swap(f,5,0);
cn_swap(f,5,1);
}
cn_break_b6:;
cn_swap(f,5,4);
(f[4]=(f[5]-f[4]));
(f[3]=(f[4]-f[3]));
{
__auto_type cn_init_953 = cn_double(r10); __auto_type v = cn_init_953;
(f[3]=(f[3]+v));
}
(r3=cn_bits(f[3]));
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]*f[2]));
(f[1]=(f[1]+f[1]));
{
__auto_type cn_init_1033 = cn_double(r11); __auto_type v = cn_init_1033;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
(f[0]=(f[0]+f[0]));
{
__auto_type cn_init_1083 = cn_double(r12); __auto_type v = cn_init_1083;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(rg[0]=rg[7]);
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
int cn_f_9d4f87250c50ef8f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+176))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_255 = cn_cell(vm,0); uint64_t v22 = cn_init_255;
__auto_type cn_init_268 = cn_cell(vm,8); uint64_t v23 = cn_init_268;
__auto_type cn_init_281 = cn_cell(vm,16); uint64_t v24 = cn_init_281;
__auto_type cn_init_294 = cn_cell(vm,24); uint64_t v25 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,32); uint64_t v26 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,40); uint64_t v27 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,48); uint64_t v28 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,56); uint64_t v29 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,64); uint64_t v30 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,80); uint64_t v32 = cn_init_372;
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
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_700 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_700;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_748 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_748;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_811 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_811;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_874 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_874;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_922 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_922;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_985 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_985;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1047 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1047;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1094 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1094;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1156 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1156;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[1]=cn_double(r3));
{
__auto_type cn_init_1247 = 0x1U; __auto_type bv = cn_init_1247;
__auto_type cn_init_1264 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_1264;
__auto_type cn_init_1282 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1282;
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
(f[2]=cn_double(r10));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(r11));
goto cn_break_b3;
}
cn_break_b2:;
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(r4));
}
cn_break_b3:;
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[2]=sqrt(f[2]));
(f[3]=cn_double(((((((v24>>32))|((v25<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[3]));
{
__auto_type cn_init_1469 = 0x1U; __auto_type bv = cn_init_1469;
__auto_type cn_init_1486 = (((uint32_t)(((((v24>>0))&0xffffffffULL))))); __auto_type av = cn_init_1486;
__auto_type cn_init_1504 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1504;
}
if(cn_cond(fl,5)){
goto cn_break_b5;
}
(f[3]=cn_double(r12));
goto cn_break_b6;
}
cn_break_b5:;
(f[3]=cn_double(r5));
}
cn_break_b6:;
(f[4]=cn_double(((((((v25>>32))|((v26<<32))))&0xffffffffffffffffULL))));
(f[3]=(f[3]*f[4]));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1643 = cn_double(v32); __auto_type v = cn_init_1643;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_tuple_1688_0 = sin(f[2]);
__auto_type cn_tuple_1688_1 = cos(f[2]);
__auto_type s = cn_tuple_1688_0;
__auto_type c = cn_tuple_1688_1;
(f[2]=s);
(f[3]=c);
(fsw&=~0x0400);
}
(f[4]=f[3]);
(f[4]=(f[4]*f[1]));
(f[5]=f[2]);
(f[5]=(f[5]*f[0]));
(f[4]=(f[4]+f[5]));
(r3=cn_bits(f[4]));
(f[0]=(f[0]*f[3]));
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]-f[1]));
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_1911 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1911;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1959 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1959;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2022 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2022;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_2085 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2085;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_2133 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2133;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2196 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2196;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_2258 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2258;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_2305 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2305;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2367 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2367;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
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
int cn_f_9d565c30e0de30ed(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+208))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_122;
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
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r12));
(f[1]=cn_double(r11));
(f[2]=cn_double(r10));
(f[3]=f[2]);
{
__auto_type cn_init_502 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_502;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_550 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_550;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_613 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_613;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_676 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_676;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_724 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_724;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_787 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_787;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_849 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_849;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_896 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_896;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_958 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_958;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r10=cn_bits(f[2]));
(r11=cn_bits(f[1]));
(r12=cn_bits(f[0]));
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
cn_wr64(m,CN_REC+8*(10),r10);
cn_wr64(m,CN_REC+8*(11),r11);
cn_wr64(m,CN_REC+8*(12),r12);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_9e2252b50e598467(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+176))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007e98U); uint64_t s2003 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_195;
__auto_type cn_init_208 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_208;
__auto_type cn_init_221 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_221;
__auto_type cn_init_234 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_234;
__auto_type cn_init_247 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,0); uint64_t v22 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,8); uint64_t v23 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,16); uint64_t v24 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,24); uint64_t v25 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,32); uint64_t v26 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,40); uint64_t v27 = cn_init_325;
__auto_type cn_init_338 = cn_cell(vm,48); uint64_t v28 = cn_init_338;
__auto_type cn_init_351 = cn_cell(vm,56); uint64_t v29 = cn_init_351;
__auto_type cn_init_364 = cn_cell(vm,64); uint64_t v30 = cn_init_364;
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
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_583 = 0x7fffffffU; __auto_type v = cn_init_583;
(rg[0]=v);
}
{
__auto_type cn_init_600 = rg[0]; __auto_type bv = cn_init_600;
__auto_type cn_init_617 = (((uint32_t)(((((r5>>32))&0xffffffffULL))))); __auto_type av = cn_init_617;
__auto_type cn_init_635 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_635;
(r5=(((r5&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_674 = rg[0]; __auto_type bv = cn_init_674;
__auto_type cn_init_691 = (((uint32_t)(((((r4>>32))&0xffffffffULL))))); __auto_type av = cn_init_691;
__auto_type cn_init_709 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_709;
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_748 = rg[0]; __auto_type bv = cn_init_748;
__auto_type cn_init_765 = (((uint32_t)(((((r3>>32))&0xffffffffULL))))); __auto_type av = cn_init_765;
__auto_type cn_init_783 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_783;
(r3=(((r3&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_819 = 0xffffffb0U; __auto_type bv = cn_init_819;
__auto_type cn_init_827 = rg[4]; __auto_type av = cn_init_827;
__auto_type cn_init_845 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_845;
(rg[4]=r);
}
(f[0]=cn_double(v22));
(f[1]=cn_double(0x3ff0000000000000));
(f[1]=(f[0]-f[1]));
cn_swap(f,1,0);
(f[1]=-f[1]);
(s2006=cn_bits(f[1]));
{
__auto_type cn_init_934 = cn_double(v30); __auto_type v = cn_init_934;
(f[0]=(f[0]+v));
}
(s2003=cn_bits(f[0]));
{
__auto_type cn_init_969 = cn_double(v29); __auto_type v = cn_init_969;
(f[0]=(f[0]*v));
}
(s2004=cn_bits(f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(s2005=cn_bits(f[0]));
{
__auto_type cn_init_1042 = cn_double(s2006); __auto_type v = cn_init_1042;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(s2006=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b2;
}
cn_swap(f,2,1);
}
cn_break_b2:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
cn_swap(f,2,0);
}
cn_break_b4:;
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b6;
}
cn_swap(f,2,0);
}
cn_break_b6:;
(f[3]=f[2]);
(f[4]=cn_double(s2005));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b9;
}
(f[3]=f[2]);
{
__auto_type cn_init_1491 = cn_double(s2006); __auto_type v = cn_init_1491;
(f[3]=(f[3]+v));
}
(f[4]=f[1]);
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b9;
}
(f[3]=cn_double(v28));
(f[2]=(f[2]-f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v27));
(f[1]=(f[1]-f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v26));
(f[0]=(f[0]-f[3]));
(f[3]=f[3]);
(f[3]=cn_double(s2004));
(f[0]=(f[0]*f[3]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
(f[4]=cn_double(r6));
(f[3]=(f[3]*f[4]));
(r6=cn_bits(f[3]));
(f[3]=cn_double(v28));
(f[2]=(f[2]+f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v27));
(f[1]=(f[1]+f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v26));
(f[0]=(f[0]+f[3]));
(f[3]=f[3]);
goto cn_break_b10;
}
cn_break_b9:;
(f[3]=cn_double(v25));
(f[2]=(f[2]-f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v24));
(f[1]=(f[1]-f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v23));
(f[0]=(f[0]-f[3]));
(f[3]=f[3]);
(f[3]=cn_double(s2003));
(f[0]=(f[0]*f[3]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
(f[4]=cn_double(r6));
(f[3]=(f[3]*f[4]));
(r6=cn_bits(f[3]));
(f[3]=cn_double(v25));
(f[2]=(f[2]+f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v24));
(f[1]=(f[1]+f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v23));
(f[0]=(f[0]+f[3]));
(f[3]=f[3]);
}
cn_break_b10:;
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[0]=rg[3]);
{
__auto_type cn_init_2272 = 0x50U; __auto_type bv = cn_init_2272;
__auto_type cn_init_2280 = rg[4]; __auto_type av = cn_init_2280;
__auto_type cn_init_2298 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2298;
(rg[4]=r);
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
cn_wr64u(m,0x10007e98U,s2003);
cn_wr64u(m,0x10007ea0U,s2004);
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_9e76d73b49146892(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+160))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007e98U); uint64_t s2003 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_268;
__auto_type cn_init_281 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_281;
__auto_type cn_init_294 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_294;
__auto_type cn_init_307 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_307;
__auto_type cn_init_320 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_320;
__auto_type cn_init_333 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_333;
__auto_type cn_init_346 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,0); uint64_t v20 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,8); uint64_t v21 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,16); uint64_t v22 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,24); uint64_t v23 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,32); uint64_t v24 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,40); uint64_t v25 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,48); uint64_t v26 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,56); uint64_t v27 = cn_init_450;
__auto_type cn_init_463 = cn_cell(vm,64); uint64_t v28 = cn_init_463;
__auto_type cn_init_476 = cn_cell(vm,72); uint64_t v29 = cn_init_476;
__auto_type cn_init_489 = cn_cell(vm,80); uint64_t v30 = cn_init_489;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_555 = 0x48U; __auto_type bv = cn_init_555;
__auto_type cn_init_563 = rg[4]; __auto_type av = cn_init_563;
__auto_type cn_init_581 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_581;
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
(f[0]=cn_double(r3));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r4));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r5));
(s2010=cn_bits(f[0]));
(f[0]=cn_double(r12));
{
__auto_type cn_init_866 = cn_double(v30); __auto_type v = cn_init_866;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2010));
{
__auto_type cn_init_902 = cn_double(v29); __auto_type v = cn_init_902;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r11));
{
__auto_type cn_init_953 = cn_double(v30); __auto_type v = cn_init_953;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2011));
{
__auto_type cn_init_989 = cn_double(v29); __auto_type v = cn_init_989;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r10));
{
__auto_type cn_init_1040 = cn_double(v30); __auto_type v = cn_init_1040;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2012));
{
__auto_type cn_init_1076 = cn_double(v29); __auto_type v = cn_init_1076;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=f[2]);
{
__auto_type cn_init_1139 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1139;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1187 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1187;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1250 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1250;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1313 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1313;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1361 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1361;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1424 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1424;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1486 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1486;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1533 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1533;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1595 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1595;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1634 = cn_double(v28); __auto_type v = cn_init_1634;
(f[2]=(f[2]+v));
}
(s2007=cn_bits(f[2]));
{
__auto_type cn_init_1669 = cn_double(v27); __auto_type v = cn_init_1669;
(f[1]=(f[1]+v));
}
(s2006=cn_bits(f[1]));
{
__auto_type cn_init_1704 = cn_double(v26); __auto_type v = cn_init_1704;
(f[0]=(f[0]+v));
}
(s2005=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2009=cn_bits(f[0]));
(f[0]=cn_double(s2007));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2006));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_1939 = cn_double(s2005); __auto_type v = cn_init_1939;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2008));
{
__auto_type cn_init_1975 = cn_double(s2010); __auto_type v = cn_init_1975;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2030 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2030;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_2077 = cn_double(s2005); __auto_type v = cn_init_2077;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2101 = cn_double(s2009); __auto_type v = cn_init_2101;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_2125 = cn_double(s2008); __auto_type v = cn_init_2125;
(f[0]=(f[0]/v));
}
(f[0]=-f[0]);
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(s2009=cn_bits(f[0]));
(f[1]=cn_double(s2012));
{
__auto_type cn_init_2210 = cn_double(s2007); __auto_type v = cn_init_2210;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2011));
{
__auto_type cn_init_2246 = cn_double(s2006); __auto_type v = cn_init_2246;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[0]=(f[0]*f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2007));
{
__auto_type cn_init_2323 = cn_double(s2011); __auto_type v = cn_init_2323;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2012));
{
__auto_type cn_init_2359 = cn_double(s2006); __auto_type v = cn_init_2359;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2398 = cn_double(s2009); __auto_type v = cn_init_2398;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
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
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_9ed2f86ae3d14801(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_47 = 0ULL; __auto_type steps = cn_init_47;
__auto_type cn_init_52 = max_steps; __auto_type limit = cn_init_52;
__auto_type cn_init_62 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+200))); unsigned char * vm = cn_init_82;
__auto_type cn_init_99 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_99;
__auto_type cn_init_116 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_116;
__auto_type cn_init_133 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_133;
__auto_type cn_init_150 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_150;
__auto_type cn_init_167 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_167;
__auto_type cn_init_184 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_184;
__auto_type cn_init_201 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_240;
__auto_type cn_init_253 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_253;
__auto_type cn_init_266 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_266;
__auto_type cn_init_279 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_279;
__auto_type cn_init_292 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_292;
__auto_type cn_init_305 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,0); uint64_t v25 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,8); uint64_t v26 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,16); uint64_t v27 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,24); uint64_t v28 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,32); uint64_t v29 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,40); uint64_t v30 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,56); uint64_t v32 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,64); uint64_t v33 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,72); uint64_t v34 = cn_init_422;
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_491 = 0x40U; __auto_type bv = cn_init_491;
__auto_type cn_init_499 = rg[4]; __auto_type av = cn_init_499;
__auto_type cn_init_517 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_517;
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
{
__auto_type cn_init_728 = (((uint32_t)(((((v25>>32))&0xffULL))))); __auto_type v = cn_init_728;
cn_reg_set(rg,0,1,v);
}
cn_continue_l1:;
{
(f[0]=cn_double(r3));
{
__auto_type cn_init_769 = cn_double(v32); __auto_type v = cn_init_769;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_805 = cn_double(v33); __auto_type v = cn_init_805;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_855 = cn_double(v34); __auto_type v = cn_init_855;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_902 = cn_double(v33); __auto_type v = cn_init_902;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_938 = cn_double(v32); __auto_type v = cn_init_938;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(f[1]=cn_double(s2013));
(f[2]=cn_double(r4));
{
__auto_type cn_init_1015 = cn_double(v34); __auto_type v = cn_init_1015;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[1]=fabs(f[1]));
(f[2]=cn_double(s2013));
(f[3]=cn_double(r4));
{
__auto_type cn_init_1103 = cn_double(v34); __auto_type v = cn_init_1103;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[2]=fabs(f[2]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1201 = cn_double(r4); __auto_type v = cn_init_1201;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1225 = cn_double(v34); __auto_type v = cn_init_1225;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=-f[0]);
{
__auto_type cn_init_1283 = cn_double(r4); __auto_type v = cn_init_1283;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1307 = cn_double(v34); __auto_type v = cn_init_1307;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1343 = cn_double(v32); __auto_type v = cn_init_1343;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_1379 = cn_double(v33); __auto_type v = cn_init_1379;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(s2013));
{
__auto_type cn_init_1430 = cn_double(v33); __auto_type v = cn_init_1430;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[3]=cn_double(r5));
{
__auto_type cn_init_1477 = cn_double(v32); __auto_type v = cn_init_1477;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r5=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(r4=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1561 = cn_double(v30); __auto_type v = cn_init_1561;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1585 = cn_double(v29); __auto_type v = cn_init_1585;
(f[0]=(f[0]-v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1632 = cn_double(v30); __auto_type v = cn_init_1632;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_1679 = cn_double(v30); __auto_type v = cn_init_1679;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
{
__auto_type cn_init_1717 = cn_reg_get(rg,0,1); __auto_type v = cn_init_1717;
__auto_type cn_init_1724 = fl.cf; __auto_type cf = cn_init_1724;
__auto_type cn_init_1742 = cn_alu(&fl,Alu_Sub,v,1,1); __auto_type r = cn_init_1742;
(fl.cf=cf);
cn_reg_set(rg,0,1,r);
}
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l1;
}
goto cn_break_b2;
}
goto cn_continue_l1;
cn_break_l1:;
}
cn_break_b2:;
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=(f[0]*f[0]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=(f[0]*f[0]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1961 = cn_double(s2011); __auto_type v = cn_init_1961;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(f[0]=(f[0]/f[1]));
(s2010=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_2037 = cn_double(s2012); __auto_type v = cn_init_2037;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2061 = cn_double(s2011); __auto_type v = cn_init_2061;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2010));
(f[2]=cn_double(s2012));
{
__auto_type cn_init_2109 = cn_double(s2011); __auto_type v = cn_init_2109;
(f[2]=(f[2]-v));
}
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(s2010));
(f[2]=(f[2]+f[2]));
{
__auto_type cn_init_2175 = cn_double(r5); __auto_type v = cn_init_2175;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_2199 = cn_double(r4); __auto_type v = cn_init_2199;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r11));
{
__auto_type cn_init_2235 = cn_double(v26); __auto_type v = cn_init_2235;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r4=cn_bits(f[2]));
(f[2]=cn_double(r12));
{
__auto_type cn_init_2297 = cn_double(v27); __auto_type v = cn_init_2297;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r5=cn_bits(f[1]));
(f[1]=cn_double(r10));
{
__auto_type cn_init_2359 = cn_double(v28); __auto_type v = cn_init_2359;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r3=cn_bits(f[0]));
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
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_9ed668c4d828ee88(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_156 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_182;
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[0]);
(f[3]=(f[3]*f[3]));
(f[4]=f[1]);
(f[4]=(f[4]*f[4]));
(f[5]=f[2]);
(f[5]=(f[5]*f[5]));
(f[6]=f[3]);
(f[6]=(f[6]+f[4]));
(f[7]=f[6]);
(f[7]=sqrt(f[7]));
(fsw=cn_compare(f[7],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_swap(f,7,5);
(f[6]=(f[7]-f[6]));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b3;
}
{
__auto_type cn_init_628 = (((uint32_t)(((((r10>>56))&0xffULL))))); __auto_type v = cn_init_628;
cn_reg_set(rg,0,1,v);
}
cn_shift_reg_l(rg,&fl,Shift_Shl,0,1,1);
if(cn_cond(fl,2)){
goto cn_break_b3;
}
(f[6]=-f[6]);
}
cn_break_b3:;
{
__auto_type cn_init_698 = cn_double(r10); __auto_type v = cn_init_698;
(f[6]=(f[6]+v));
}
(r3=cn_bits(f[6]));
(f[6]=cn_double(0x3ff0000000000000));
(f[6]=(f[6]+f[6]));
(f[6]=-f[6]);
(f[5]=(f[6]/f[5]));
cn_swap(f,5,2);
(f[5]=fabs(f[5]));
(f[2]=(f[2]*f[5]));
(f[3]=(f[4]-f[3]));
(f[3]=(f[3]*f[2]));
{
__auto_type cn_init_854 = cn_double(r11); __auto_type v = cn_init_854;
(f[3]=(f[3]+v));
}
(r4=cn_bits(f[3]));
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]*f[1]));
(f[0]=(f[0]+f[0]));
{
__auto_type cn_init_934 = cn_double(r12); __auto_type v = cn_init_934;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
{
(rg[6]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[0]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
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
int cn_f_9f3abcd9e3fc675a(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+136))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001010U); uint64_t r2 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_188;
__auto_type cn_init_201 = cn_cell(vm,0); uint64_t v17 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,8); uint64_t v18 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,16); uint64_t v19 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,24); uint64_t v20 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,32); uint64_t v21 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,40); uint64_t v22 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,48); uint64_t v23 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,56); uint64_t v24 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,64); uint64_t v25 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,72); uint64_t v26 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,80); uint64_t v27 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,88); uint64_t v28 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,96); uint64_t v29 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,104); uint64_t v30 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,112); uint64_t v31 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,120); uint64_t v32 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,128); uint64_t v33 = cn_init_409;
{
{
{
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_439 = r5; uint64_t s = cn_init_439;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_469 = (CN_U2){v28,v29}; CN_U2 s = cn_init_469;
__auto_type cn_init_479 = m->xmm[0]; __auto_type a = cn_init_479;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_549 = v28; uint64_t s = cn_init_549;
__auto_type cn_init_562 = m->xmm[1][0]; __auto_type a = cn_init_562;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_609 = (CN_U2){v24,v25}; CN_U2 s = cn_init_609;
__auto_type cn_init_619 = m->xmm[0]; __auto_type a = cn_init_619;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_689 = v26; uint64_t s = cn_init_689;
__auto_type cn_init_702 = m->xmm[1][0]; __auto_type a = cn_init_702;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_739 = 0x0U; __auto_type bv = cn_init_739;
__auto_type cn_init_756 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_756;
__auto_type cn_init_774 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_774;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_795 = r32; uint64_t s = cn_init_795;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_817 = v28; uint64_t s = cn_init_817;
__auto_type cn_init_830 = m->xmm[5][0]; __auto_type a = cn_init_830;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(m->xmm[3]=(CN_U2){v20,v21});
{
__auto_type cn_init_931 = v22; uint64_t s = cn_init_931;
(m->xmm[4]=(CN_U2){s,0});
}
{
__auto_type cn_init_962 = m->xmm[3]; CN_U2 s = cn_init_962;
__auto_type cn_init_972 = m->xmm[0]; __auto_type a = cn_init_972;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_1050 = m->xmm[4][0]; uint64_t s = cn_init_1050;
__auto_type cn_init_1063 = m->xmm[1][0]; __auto_type a = cn_init_1063;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_1111 = m->xmm[0]; CN_U2 s = cn_init_1111;
__auto_type cn_init_1121 = m->xmm[0]; __auto_type a = cn_init_1121;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_1199 = m->xmm[1][0]; uint64_t s = cn_init_1199;
__auto_type cn_init_1212 = m->xmm[1][0]; __auto_type a = cn_init_1212;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_1259 = m->xmm[0][0]; uint64_t s = cn_init_1259;
__auto_type cn_init_1272 = m->xmm[1][0]; __auto_type a = cn_init_1272;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_1320 = m->xmm[0]; CN_U2 s = cn_init_1320;
__auto_type cn_init_1330 = m->xmm[0]; __auto_type a = cn_init_1330;
(m->xmm[0]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_1366 = m->xmm[0][0]; uint64_t s = cn_init_1366;
__auto_type cn_init_1379 = m->xmm[1][0]; __auto_type a = cn_init_1379;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_1426 = m->xmm[1][0]; uint64_t s = cn_init_1426;
(m->xmm[1][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_1460 = v17; uint64_t s = cn_init_1460;
(m->xmm[2]=(CN_U2){s,0});
}
{
__auto_type cn_init_1490 = m->xmm[1][0]; uint64_t s = cn_init_1490;
__auto_type cn_init_1503 = m->xmm[2][0]; __auto_type a = cn_init_1503;
(m->xmm[2][0]=cn_bits(((cn_double(a)-cn_double(s)))));
}
{
__auto_type cn_init_1542 = v30; uint64_t s = cn_init_1542;
__auto_type cn_init_1555 = m->xmm[1][0]; __auto_type a = cn_init_1555;
(m->xmm[1][0]=cn_bits(((cn_double(a)-cn_double(s)))));
}
{
__auto_type cn_init_1602 = m->xmm[2][0]; uint64_t s = cn_init_1602;
__auto_type cn_init_1615 = m->xmm[1][0]; __auto_type a = cn_init_1615;
(m->xmm[1][0]=cn_bits(({__auto_type cn_tuple_1649_0 = cn_double(a);
__auto_type cn_tuple_1649_1 = cn_double(s);
__auto_type p = cn_tuple_1649_0;
__auto_type q = cn_tuple_1649_1; (((p>q))?(({p;})):(({q;})));})));
}
{
__auto_type cn_init_1683 = (CN_U2){v32,v33}; CN_U2 s = cn_init_1683;
__auto_type cn_init_1693 = m->xmm[3]; __auto_type a = cn_init_1693;
(m->xmm[3]=(CN_U2){(a[0]&s[0]),(a[1]&s[1])});
}
{
__auto_type cn_init_1739 = (CN_U2){v32,v33}; CN_U2 s = cn_init_1739;
__auto_type cn_init_1749 = m->xmm[4]; __auto_type a = cn_init_1749;
(m->xmm[4]=(CN_U2){(a[0]&s[0]),(a[1]&s[1])});
}
{
__auto_type cn_init_1795 = m->xmm[3][0]; uint64_t s = cn_init_1795;
__auto_type cn_init_1808 = m->xmm[4][0]; __auto_type a = cn_init_1808;
(m->xmm[4][0]=cn_bits(({__auto_type cn_tuple_1842_0 = cn_double(a);
__auto_type cn_tuple_1842_1 = cn_double(s);
__auto_type p = cn_tuple_1842_0;
__auto_type q = cn_tuple_1842_1; (((p>q))?(({p;})):(({q;})));})));
}
{
__auto_type cn_init_1877 = m->xmm[3]; CN_U2 s = cn_init_1877;
__auto_type cn_init_1887 = m->xmm[3]; __auto_type a = cn_init_1887;
(m->xmm[3]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_1923 = m->xmm[3][0]; uint64_t s = cn_init_1923;
__auto_type cn_init_1936 = m->xmm[4][0]; __auto_type a = cn_init_1936;
(m->xmm[4][0]=cn_bits(({__auto_type cn_tuple_1970_0 = cn_double(a);
__auto_type cn_tuple_1970_1 = cn_double(s);
__auto_type p = cn_tuple_1970_0;
__auto_type q = cn_tuple_1970_1; (((p>q))?(({p;})):(({q;})));})));
}
{
__auto_type cn_init_2004 = m->xmm[4][0]; uint64_t s = cn_init_2004;
__auto_type cn_init_2017 = m->xmm[1][0]; __auto_type a = cn_init_2017;
(m->xmm[1][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_2054 = 0x0U; __auto_type bv = cn_init_2054;
__auto_type cn_init_2071 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_2071;
__auto_type cn_init_2089 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2089;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
{
__auto_type cn_init_2110 = v28; uint64_t s = cn_init_2110;
__auto_type cn_init_2123 = m->xmm[1][0]; __auto_type a = cn_init_2123;
(m->xmm[1][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
}
cn_break_b4:;
(rg[0]=((uint32_t)(((((v19>>0))&0xffffffffULL)))));
(r14=m->xmm[1][0]);
{
__auto_type cn_init_2190 = 0x3U; __auto_type bv = cn_init_2190;
__auto_type cn_init_2198 = rg[0]; __auto_type av = cn_init_2198;
__auto_type cn_init_2216 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2216;
(rg[0]=r);
}
switch(((((rg[0]>>0))&3))){
case 0:
{
(f[0]=cn_double(((((((rg[0]>>0))&3))==0)?(r2):(((((((rg[0]>>0))&3))==1)?(r3):(((((((rg[0]>>0))&3))==2)?(r4):(((((((rg[0]>>0))&3))==3)?(r5):(0))))))))));
}
break;
case 1:
{
(f[0]=cn_double(((((((rg[0]>>0))&3))==0)?(r2):(((((((rg[0]>>0))&3))==1)?(r3):(((((((rg[0]>>0))&3))==2)?(r4):(((((((rg[0]>>0))&3))==3)?(r5):(0))))))))));
}
break;
case 2:
{
(f[0]=cn_double(((((((rg[0]>>0))&3))==0)?(r2):(((((((rg[0]>>0))&3))==1)?(r3):(((((((rg[0]>>0))&3))==2)?(r4):(((((((rg[0]>>0))&3))==3)?(r5):(0))))))))));
}
break;
case 3:
{
(f[0]=cn_double(((((((rg[0]>>0))&3))==0)?(r2):(((((((rg[0]>>0))&3))==1)?(r3):(((((((rg[0]>>0))&3))==2)?(r4):(((((((rg[0]>>0))&3))==3)?(r5):(0))))))))));
}
break;
default:
{
}
break;
}
{
__auto_type cn_init_2464 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2464;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2502 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2502;
(f[0]=(f[0]+v));
}
(r34=cn_bits(f[0]));
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
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_9fbb38a21e3674ad(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_318 = cn_cell(vm,48); uint64_t v24 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,56); uint64_t v25 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,64); uint64_t v26 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,72); uint64_t v27 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,80); uint64_t v28 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,88); uint64_t v29 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,96); uint64_t v30 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,112); uint64_t v32 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,120); uint64_t v33 = cn_init_422;
__auto_type cn_init_435 = cn_cell(vm,128); uint64_t v34 = cn_init_435;
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
{
__auto_type cn_init_2202 = cn_bits(f[0]); uint64_t v = cn_init_2202;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_2303 = cn_bits(f[0]); uint64_t v = cn_init_2303;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_2404 = cn_bits(f[0]); uint64_t v = cn_init_2404;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2545 = cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2545;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2627 = cn_double(v33); __auto_type v = cn_init_2627;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2728 = cn_bits(f[0]); uint64_t v = cn_init_2728;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2810 = cn_double(v32); __auto_type v = cn_init_2810;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2896 = cn_bits(f[0]); uint64_t v = cn_init_2896;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))));
(f[0]=sqrt(f[0]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))));
(f[1]=sqrt(f[1]));
(f[1]=sqrt(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3088 = cn_double(v34); __auto_type v = cn_init_3088;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[3]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[2]=(f[2]+f[3]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_3240 = cn_double(v30); __auto_type v = cn_init_3240;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
(f[1]=f[1]);
goto cn_break_b5;
}
cn_break_b4:;
(f[0]=f[1]);
}
cn_break_b5:;
{
__auto_type cn_init_3354 = 0x0U; __auto_type bv = cn_init_3354;
__auto_type cn_init_3371 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_3371;
__auto_type cn_init_3389 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3389;
}
if(cn_cond(fl,5)){
goto cn_break_b7;
}
{
__auto_type cn_init_3413 = cn_double(v28); __auto_type v = cn_init_3413;
(f[0]=(f[0]/v));
}
}
cn_break_b7:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_3444 = 0x46U; __auto_type bv = cn_init_3444;
__auto_type cn_init_3452 = rg[4]; __auto_type av = cn_init_3452;
__auto_type cn_init_3470 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3470;
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
int cn_f_9fd74ba8f587fc1f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[3]=-f[3]);
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
cn_swap(f,3,2);
}
cn_break_b4:;
(f[3]=-f[3]);
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b6;
}
cn_swap(f,3,1);
}
cn_break_b6:;
(f[3]=-f[3]);
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b8;
}
cn_swap(f,3,1);
}
cn_break_b8:;
(f[3]=-f[3]);
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
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b12;
}
cn_swap(f,3,0);
}
cn_break_b12:;
cn_swap(f,3,2);
cn_swap(f,3,1);
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b14;
}
cn_swap(f,3,0);
}
cn_break_b14:;
{
__auto_type cn_init_1410 = 0x28U; __auto_type bv = cn_init_1410;
__auto_type cn_init_1418 = rg[7]; __auto_type av = cn_init_1418;
__auto_type cn_init_1436 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_1436;
(rg[7]=r);
}
(f[4]=f[3]);
{
__auto_type cn_init_1479 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1479;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1527 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1527;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1590 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1590;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1653 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1653;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r3=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_1727 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1727;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1775 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1775;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1838 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1838;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1901 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1901;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r4=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_1975 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1975;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_2023 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2023;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_2086 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2086;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2149 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2149;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r5=cn_bits(f[4]));
{
__auto_type cn_init_2213 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2213;
(f[3]=(f[3]*v));
}
cn_swap(f,3,2);
{
__auto_type cn_init_2260 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2260;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
cn_swap(f,2,1);
{
__auto_type cn_init_2322 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2322;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
cn_swap(f,1,0);
{
__auto_type cn_init_2384 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2384;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r6=cn_bits(f[0]));
{
__auto_type cn_init_2429 = 0x28U; __auto_type bv = cn_init_2429;
__auto_type cn_init_2437 = rg[7]; __auto_type av = cn_init_2437;
__auto_type cn_init_2455 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2455;
(rg[7]=r);
}
(f[0]=cn_double(r6));
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[4]=cn_double(v30));
(f[5]=f[4]);
{
__auto_type cn_init_2544 = cn_double(r36); __auto_type v = cn_init_2544;
(f[5]=(f[5]*v));
}
(r36=cn_bits(f[5]));
(f[0]=(f[0]*f[4]));
(f[1]=(f[1]*f[4]));
(f[2]=(f[2]*f[4]));
(f[3]=(f[3]*f[4]));
(f[5]=cn_double(0x3ff0000000000000));
(f[4]=(f[4]-f[5]));
(f[4]=-f[4]);
(f[5]=cn_double(v29));
(f[5]=(f[5]*f[4]));
(f[5]=(f[5]+f[3]));
(r3=cn_bits(f[5]));
(f[5]=cn_double(v28));
(f[5]=(f[5]*f[4]));
(f[5]=(f[5]+f[2]));
(r4=cn_bits(f[5]));
(f[5]=cn_double(v27));
(f[5]=(f[5]*f[4]));
(f[5]=(f[5]+f[1]));
(r5=cn_bits(f[5]));
(f[5]=cn_double(v26));
(f[5]=(f[5]*f[4]));
(f[5]=(f[5]+f[0]));
(r6=cn_bits(f[5]));
(f[4]=f[4]);
(f[3]=f[3]);
(f[2]=f[2]);
(f[1]=f[1]);
(f[0]=f[0]);
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
int cn_f_a04ff08d782be6ba(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+240))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_242 = cn_cell(vm,0); uint64_t v30 = cn_init_242;
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
(f[0]=cn_double(r4));
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_453 = cn_double(r4); __auto_type v = cn_init_453;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_489 = cn_double(r3); __auto_type v = cn_init_489;
(f[1]=(f[1]*v));
}
(f[2]=f[1]);
(f[2]=(f[2]+f[0]));
(f[3]=cn_double(r5));
(f[3]=fabs(f[3]));
(f[4]=f[3]);
(f[4]=(f[4]*f[4]));
(f[4]=(f[4]-f[2]));
{
__auto_type cn_init_604 = cn_double(v30); __auto_type v = cn_init_604;
(f[4]=(f[4]*v));
}
{
__auto_type cn_init_628 = cn_double(r12); __auto_type v = cn_init_628;
(f[4]=(f[4]+v));
}
(r5=cn_bits(f[4]));
(f[3]=(f[3]+f[3]));
cn_swap(f,3,2);
(f[3]=sqrt(f[3]));
(f[2]=(f[2]/f[3]));
(f[3]=f[2]);
{
__auto_type cn_init_726 = cn_double(r3); __auto_type v = cn_init_726;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_750 = cn_double(r4); __auto_type v = cn_init_750;
(f[3]=(f[3]*v));
}
(f[3]=(f[3]+f[3]));
{
__auto_type cn_init_789 = cn_double(r11); __auto_type v = cn_init_789;
(f[3]=(f[3]+v));
}
(r4=cn_bits(f[3]));
cn_swap(f,2,1);
(f[0]=(f[2]-f[0]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_863 = cn_double(r10); __auto_type v = cn_init_863;
(f[0]=(f[0]+v));
}
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
int cn_f_a050848733dce3db(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_346 = cn_cell(vm,0); uint64_t v28 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,8); uint64_t v29 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,16); uint64_t v30 = cn_init_372;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_438 = 0x40U; __auto_type bv = cn_init_438;
__auto_type cn_init_446 = rg[4]; __auto_type av = cn_init_446;
__auto_type cn_init_464 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_464;
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
__auto_type cn_tuple_884_0 = f[2];
__auto_type cn_tuple_884_1 = f[1];
__auto_type x = cn_tuple_884_0;
__auto_type y = cn_tuple_884_1;
__auto_type cn_init_913 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_913;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_945 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_945;
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
__auto_type cn_init_1210 = cn_double(v30); __auto_type v = cn_init_1210;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1240_0 = sin(f[0]);
__auto_type cn_tuple_1240_1 = cos(f[0]);
__auto_type s = cn_tuple_1240_0;
__auto_type c = cn_tuple_1240_1;
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
__auto_type cn_init_1335 = cn_double(v29); __auto_type v = cn_init_1335;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1365_0 = sin(f[0]);
__auto_type cn_tuple_1365_1 = cos(f[0]);
__auto_type s = cn_tuple_1365_0;
__auto_type c = cn_tuple_1365_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2007=cn_bits(f[1]));
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_1430 = cn_double(s2012); __auto_type v = cn_init_1430;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1454 = cn_double(r10); __auto_type v = cn_init_1454;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_1501 = cn_double(s2008); __auto_type v = cn_init_1501;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1525 = cn_double(s2012); __auto_type v = cn_init_1525;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1549 = cn_double(r11); __auto_type v = cn_init_1549;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_1596 = cn_double(s2007); __auto_type v = cn_init_1596;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1620 = cn_double(v28); __auto_type v = cn_init_1620;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1644 = cn_double(s2012); __auto_type v = cn_init_1644;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1668 = cn_double(r12); __auto_type v = cn_init_1668;
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
int cn_f_a11ae827485a8b8b(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+136))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_178;
__auto_type cn_init_191 = cn_cell(vm,0); uint64_t v17 = cn_init_191;
__auto_type cn_init_204 = cn_cell(vm,8); uint64_t v18 = cn_init_204;
__auto_type cn_init_217 = cn_cell(vm,16); uint64_t v19 = cn_init_217;
__auto_type cn_init_230 = cn_cell(vm,24); uint64_t v20 = cn_init_230;
__auto_type cn_init_243 = cn_cell(vm,32); uint64_t v21 = cn_init_243;
__auto_type cn_init_256 = cn_cell(vm,40); uint64_t v22 = cn_init_256;
__auto_type cn_init_269 = cn_cell(vm,48); uint64_t v23 = cn_init_269;
__auto_type cn_init_282 = cn_cell(vm,56); uint64_t v24 = cn_init_282;
__auto_type cn_init_295 = cn_cell(vm,64); uint64_t v25 = cn_init_295;
__auto_type cn_init_308 = cn_cell(vm,72); uint64_t v26 = cn_init_308;
__auto_type cn_init_321 = cn_cell(vm,80); uint64_t v27 = cn_init_321;
__auto_type cn_init_334 = cn_cell(vm,88); uint64_t v28 = cn_init_334;
__auto_type cn_init_347 = cn_cell(vm,96); uint64_t v29 = cn_init_347;
__auto_type cn_init_360 = cn_cell(vm,104); uint64_t v30 = cn_init_360;
__auto_type cn_init_373 = cn_cell(vm,120); uint64_t v32 = cn_init_373;
__auto_type cn_init_386 = cn_cell(vm,128); uint64_t v33 = cn_init_386;
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
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_681 = cn_double(v29); __auto_type v = cn_init_681;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_717 = cn_double(v30); __auto_type v = cn_init_717;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=fabs(f[0]));
(f[1]=cn_double(v33));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_837 = 0x41U; __auto_type bv = cn_init_837;
__auto_type cn_init_850 = cn_reg_get(rg,4,1); __auto_type av = cn_init_850;
__auto_type cn_init_868 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_868;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,15)){
goto cn_break_b2;
}
(f[0]=cn_double(r5));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=-f[1]);
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
(f[2]=cn_double(r3));
{
__auto_type cn_init_1006 = cn_double(v28); __auto_type v = cn_init_1006;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r4));
{
__auto_type cn_init_1042 = cn_double(v27); __auto_type v = cn_init_1042;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[3]));
{
__auto_type cn_init_1108 = cn_double(v26); __auto_type v = cn_init_1108;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r4));
(f[3]=(f[3]*f[3]));
{
__auto_type cn_init_1174 = cn_double(v25); __auto_type v = cn_init_1174;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
{
__auto_type cn_init_1225 = cn_double(r4); __auto_type v = cn_init_1225;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_1249 = cn_double(v24); __auto_type v = cn_init_1249;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[3]));
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[3]=sqrt(f[3]));
{
__auto_type cn_init_1371 = cn_double(v23); __auto_type v = cn_init_1371;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[2]=(f[2]*f[0]));
(f[3]=cn_double(r3));
{
__auto_type cn_init_1437 = cn_double(v22); __auto_type v = cn_init_1437;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r4));
{
__auto_type cn_init_1473 = cn_double(v21); __auto_type v = cn_init_1473;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
(f[4]=(f[4]*f[4]));
{
__auto_type cn_init_1539 = cn_double(v20); __auto_type v = cn_init_1539;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[4]));
{
__auto_type cn_init_1605 = cn_double(v19); __auto_type v = cn_init_1605;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
{
__auto_type cn_init_1656 = cn_double(r4); __auto_type v = cn_init_1656;
(f[4]=(f[4]*v));
}
{
__auto_type cn_init_1680 = cn_double(v18); __auto_type v = cn_init_1680;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
(f[4]=(f[4]*f[4]));
(f[5]=cn_double(r4));
(f[5]=(f[5]*f[5]));
(f[4]=(f[4]+f[5]));
(f[4]=sqrt(f[4]));
{
__auto_type cn_init_1802 = cn_double(v17); __auto_type v = cn_init_1802;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[3]=(f[3]*f[1]));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
{
__auto_type cn_init_1883 = cn_double(v28); __auto_type v = cn_init_1883;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r4));
{
__auto_type cn_init_1919 = cn_double(v27); __auto_type v = cn_init_1919;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
(f[4]=(f[4]*f[4]));
{
__auto_type cn_init_1985 = cn_double(v26); __auto_type v = cn_init_1985;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[4]));
{
__auto_type cn_init_2051 = cn_double(v25); __auto_type v = cn_init_2051;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
{
__auto_type cn_init_2102 = cn_double(r4); __auto_type v = cn_init_2102;
(f[4]=(f[4]*v));
}
{
__auto_type cn_init_2126 = cn_double(v24); __auto_type v = cn_init_2126;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
(f[4]=(f[4]*f[4]));
(f[5]=cn_double(r4));
(f[5]=(f[5]*f[5]));
(f[4]=(f[4]+f[5]));
(f[4]=sqrt(f[4]));
{
__auto_type cn_init_2248 = cn_double(v23); __auto_type v = cn_init_2248;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[3]=(f[3]*f[1]));
(f[4]=cn_double(r3));
{
__auto_type cn_init_2314 = cn_double(v22); __auto_type v = cn_init_2314;
(f[4]=(f[4]*v));
}
(f[5]=cn_double(r4));
{
__auto_type cn_init_2350 = cn_double(v21); __auto_type v = cn_init_2350;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=cn_double(r3));
(f[5]=(f[5]*f[5]));
{
__auto_type cn_init_2416 = cn_double(v20); __auto_type v = cn_init_2416;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=cn_double(r4));
(f[5]=(f[5]*f[5]));
{
__auto_type cn_init_2482 = cn_double(v19); __auto_type v = cn_init_2482;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=cn_double(r3));
{
__auto_type cn_init_2533 = cn_double(r4); __auto_type v = cn_init_2533;
(f[5]=(f[5]*v));
}
{
__auto_type cn_init_2557 = cn_double(v18); __auto_type v = cn_init_2557;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=cn_double(r3));
(f[5]=(f[5]*f[5]));
(f[6]=cn_double(r4));
(f[6]=(f[6]*f[6]));
(f[5]=(f[5]+f[6]));
(f[5]=sqrt(f[5]));
{
__auto_type cn_init_2679 = cn_double(v17); __auto_type v = cn_init_2679;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[4]=(f[4]*f[0]));
(f[3]=(f[3]+f[4]));
(r4=cn_bits(f[3]));
(r3=cn_bits(f[2]));
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
cn_break_b2:;
(f[0]=cn_double(v32));
(f[1]=cn_double(v32));
(r4=cn_bits(f[1]));
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
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_a17f8ba9b9d3f95f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_149 = cn_rd64u(m,0x10001078U); uint64_t r15 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_240;
__auto_type cn_init_253 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_253;
__auto_type cn_init_266 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,0); uint64_t v16 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,8); uint64_t v17 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,16); uint64_t v18 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,24); uint64_t v19 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,32); uint64_t v20 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,40); uint64_t v21 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,48); uint64_t v22 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,56); uint64_t v23 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,64); uint64_t v24 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,72); uint64_t v25 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,80); uint64_t v26 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,88); uint64_t v27 = cn_init_422;
__auto_type cn_init_435 = cn_cell(vm,96); uint64_t v28 = cn_init_435;
__auto_type cn_init_448 = cn_cell(vm,104); uint64_t v29 = cn_init_448;
__auto_type cn_init_461 = cn_cell(vm,112); uint64_t v30 = cn_init_461;
__auto_type cn_init_474 = cn_cell(vm,128); uint64_t v32 = cn_init_474;
__auto_type cn_init_487 = cn_cell(vm,136); uint64_t v33 = cn_init_487;
__auto_type cn_init_500 = cn_cell(vm,152); uint64_t v35 = cn_init_500;
__auto_type cn_init_513 = cn_cell(vm,160); uint64_t v36 = cn_init_513;
__auto_type cn_init_526 = cn_cell(vm,168); uint64_t v37 = cn_init_526;
{
{
{
{
{
{
{
{
{
__auto_type cn_init_556 = 0xffffffd8U; __auto_type bv = cn_init_556;
__auto_type cn_init_564 = rg[4]; __auto_type av = cn_init_564;
__auto_type cn_init_582 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_582;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_611 = r5; uint64_t s = cn_init_611;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_641 = (CN_U2){v28,v29}; CN_U2 s = cn_init_641;
__auto_type cn_init_651 = m->xmm[0]; __auto_type a = cn_init_651;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_721 = v28; uint64_t s = cn_init_721;
__auto_type cn_init_734 = m->xmm[1][0]; __auto_type a = cn_init_734;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_781 = (CN_U2){v24,v25}; CN_U2 s = cn_init_781;
__auto_type cn_init_791 = m->xmm[0]; __auto_type a = cn_init_791;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_861 = v26; uint64_t s = cn_init_861;
__auto_type cn_init_874 = m->xmm[1][0]; __auto_type a = cn_init_874;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_911 = 0x0U; __auto_type bv = cn_init_911;
__auto_type cn_init_928 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_928;
__auto_type cn_init_946 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_946;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_967 = r32; uint64_t s = cn_init_967;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_989 = v28; uint64_t s = cn_init_989;
__auto_type cn_init_1002 = m->xmm[5][0]; __auto_type a = cn_init_1002;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1098 = m->xmm[0][0]; uint64_t v = cn_init_1098;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1157 = m->xmm[0][1]; uint64_t v = cn_init_1157;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1216 = m->xmm[1][0]; uint64_t v = cn_init_1216;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1265 = 0x0U; __auto_type v = cn_init_1265;
(rg[2]=v);
}
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[2])))&0xffffffffULL))<<0))));
(f[0]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
(f[0]=fabs(f[0]));
(f[1]=cn_double(v36));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
(f[0]=f[0]);
(f[0]=cn_double(v35));
goto cn_break_b7;
}
cn_break_b4:;
(f[0]=-f[0]);
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v23));
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
(rg[2]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
{
__auto_type cn_init_1549 = 0x80000000U; __auto_type bv = cn_init_1549;
__auto_type cn_init_1557 = rg[2]; __auto_type av = cn_init_1557;
__auto_type cn_init_1575 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1575;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
(f[0]=-f[0]);
}
cn_break_b6:;
{
__auto_type cn_init_1634 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1634;
(f[0]=(f[0]+v));
}
{
__auto_type cn_tuple_1664_0 = sin(f[0]);
__auto_type cn_tuple_1664_1 = cos(f[0]);
__auto_type s = cn_tuple_1664_0;
__auto_type c = cn_tuple_1664_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
{
__auto_type cn_init_1699 = cn_bits(f[1]); uint64_t v = cn_init_1699;
(s2014=(((s2014&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2015=(((s2015&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1757 = cn_bits(f[0]); uint64_t v = cn_init_1757;
(s2013=(((s2013&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2014=(((s2014&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1855 = cn_double(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1855;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1923 = cn_double(((((((s2014>>32))|((s2015<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1923;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2017 = cn_double(((((((s2014>>32))|((s2015<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2017;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2085 = cn_double(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2085;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_2142 = cn_double(v32); __auto_type v = cn_init_2142;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2182 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2182;
(f[0]=(f[0]/v));
}
(f[1]=f[0]);
{
__auto_type cn_init_2219 = cn_round(m,f[1]); __auto_type x = cn_init_2219;
__auto_type cn_init_2254 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2254;
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2014>>0))&0xffffffffULL))))))))));
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_2347 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2347;
(f[0]=(f[0]*v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_2385 = cn_double(v30); __auto_type v = cn_init_2385;
(f[0]=(f[0]/v));
}
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_2436 = cn_double(v30); __auto_type v = cn_init_2436;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2460 = cn_double(v33); __auto_type v = cn_init_2460;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
}
cn_break_b7:;
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_2669 = cn_double(v37); __auto_type v = cn_init_2669;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_2709 = cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2709;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2763 = cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2763;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b9;
}
(f[1]=f[1]);
goto cn_break_b10;
}
cn_break_b9:;
(f[0]=f[1]);
}
cn_break_b10:;
{
__auto_type cn_init_2877 = 0x0U; __auto_type bv = cn_init_2877;
__auto_type cn_init_2894 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_2894;
__auto_type cn_init_2912 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2912;
}
if(cn_cond(fl,5)){
goto cn_break_b12;
}
{
__auto_type cn_init_2936 = cn_double(v28); __auto_type v = cn_init_2936;
(f[0]=(f[0]/v));
}
}
cn_break_b12:;
(r14=cn_bits(f[0]));
(f[0]=(((double)(((int32_t)(((uint32_t)(((((r15>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_3011 = cn_double(((((((v18>>32))|((v19<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3011;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3051 = cn_double(((((((v17>>32))|((v18<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3051;
(f[0]=(f[0]+v));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2014>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_3114 = cn_double(((((((v16>>32))|((v17<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3114;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(r34=cn_bits(f[0]));
{
__auto_type cn_init_3173 = 0x28U; __auto_type bv = cn_init_3173;
__auto_type cn_init_3181 = rg[4]; __auto_type av = cn_init_3181;
__auto_type cn_init_3199 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3199;
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
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
cn_wr64u(m,0x10007ef8U,s2015);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_a1f064eaf002bf06(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+128))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v16 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,8); uint64_t v17 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,16); uint64_t v18 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,24); uint64_t v19 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,32); uint64_t v20 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,40); uint64_t v21 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,48); uint64_t v22 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,56); uint64_t v23 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,64); uint64_t v24 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,72); uint64_t v25 = cn_init_325;
__auto_type cn_init_338 = cn_cell(vm,80); uint64_t v26 = cn_init_338;
__auto_type cn_init_351 = cn_cell(vm,88); uint64_t v27 = cn_init_351;
__auto_type cn_init_364 = cn_cell(vm,96); uint64_t v28 = cn_init_364;
__auto_type cn_init_377 = cn_cell(vm,104); uint64_t v29 = cn_init_377;
__auto_type cn_init_390 = cn_cell(vm,112); uint64_t v30 = cn_init_390;
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
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_674 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_674;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_722 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_722;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_785 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_785;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_848 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_848;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_896 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_896;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_959 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_959;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1021 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1021;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1068 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1068;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1130 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1130;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[2]=-f[2]);
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b2;
}
cn_swap(f,2,1);
}
cn_break_b2:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
cn_swap(f,2,0);
}
cn_break_b4:;
(f[2]=-f[2]);
cn_swap(f,2,1);
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
(f[3]=cn_double(v17));
(f[4]=cn_double(0x0));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b8;
}
(f[3]=(f[3]-f[1]));
(f[3]=fabs(f[3]));
(f[3]=-f[3]);
{
__auto_type cn_init_1605 = cn_double(v17); __auto_type v = cn_init_1605;
(f[3]=(f[3]+v));
}
cn_swap(f,3,1);
}
cn_break_b8:;
(f[3]=f[3]);
(f[3]=cn_double(v16));
(f[4]=cn_double(0x0));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b10;
}
(f[3]=(f[3]-f[2]));
(f[3]=fabs(f[3]));
(f[3]=-f[3]);
{
__auto_type cn_init_1783 = cn_double(v16); __auto_type v = cn_init_1783;
(f[3]=(f[3]+v));
}
cn_swap(f,3,2);
}
cn_break_b10:;
(f[3]=f[3]);
(f[3]=f[2]);
{
__auto_type cn_init_1851 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1851;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1899 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1899;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1962 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1962;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_2025 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2025;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_2073 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2073;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2136 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2136;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_2198 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2198;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_2245 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2245;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2307 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2307;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
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
{
__auto_type cn_init_2478 = cn_double(v27); __auto_type v = cn_init_2478;
(f[4]=(f[4]*v));
}
(f[0]=(f[0]-f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_2527 = cn_double(v28); __auto_type v = cn_init_2527;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]-f[4]));
{
__auto_type cn_init_2566 = cn_double(v29); __auto_type v = cn_init_2566;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]-f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
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
int cn_f_a20b4efe403de33c(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(((((((v25>>32))|((v26<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[1]/f[0]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[0]));
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[0]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[0]));
(f[4]=f[3]);
{
__auto_type cn_init_681 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_681;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_729 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_729;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_792 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_792;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[3]);
{
__auto_type cn_init_855 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_855;
(f[5]=(f[5]*v));
}
(f[6]=f[2]);
{
__auto_type cn_init_903 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_903;
(f[6]=(f[6]*v));
}
(f[5]=(f[5]+f[6]));
(f[6]=f[1]);
{
__auto_type cn_init_966 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_966;
(f[6]=(f[6]*v));
}
(f[5]=(f[5]+f[6]));
cn_swap(f,5,3);
{
__auto_type cn_init_1028 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1028;
(f[5]=(f[5]*v));
}
cn_swap(f,5,2);
{
__auto_type cn_init_1075 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1075;
(f[5]=(f[5]*v));
}
(f[2]=(f[2]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_1137 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1137;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
{
__auto_type cn_init_1176 = cn_double(r3); __auto_type v = cn_init_1176;
(f[3]=(f[3]+v));
}
(r3=cn_bits(f[3]));
{
__auto_type cn_init_1211 = cn_double(r4); __auto_type v = cn_init_1211;
(f[2]=(f[2]+v));
}
(r4=cn_bits(f[2]));
{
__auto_type cn_init_1246 = cn_double(r5); __auto_type v = cn_init_1246;
(f[1]=(f[1]+v));
}
(r5=cn_bits(f[1]));
(f[0]=f[0]);
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
int cn_f_a22ef99f3a072d7d(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+224))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_195;
__auto_type cn_init_208 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,0); uint64_t v28 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,8); uint64_t v29 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,16); uint64_t v30 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,24); uint64_t v31 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,32); uint64_t v32 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,40); uint64_t v33 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,48); uint64_t v34 = cn_init_299;
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
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[2])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((v30>>32))&0xffffffffULL)))));
{
__auto_type cn_init_613 = 0x3U; __auto_type bv = cn_init_613;
__auto_type cn_init_621 = rg[6]; __auto_type av = cn_init_621;
__auto_type cn_init_639 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_639;
(rg[6]=r);
}
switch(((((rg[6]>>0))&3))){
case 0:
{
(f[0]=cn_double(((((((rg[6]>>0))&3))==0)?(r3):(((((((rg[6]>>0))&3))==1)?(r4):(((((((rg[6]>>0))&3))==2)?(r5):(((((((rg[6]>>0))&3))==3)?(r6):(0))))))))));
}
break;
case 1:
{
(f[0]=cn_double(((((((rg[6]>>0))&3))==0)?(r3):(((((((rg[6]>>0))&3))==1)?(r4):(((((((rg[6]>>0))&3))==2)?(r5):(((((((rg[6]>>0))&3))==3)?(r6):(0))))))))));
}
break;
case 2:
{
(f[0]=cn_double(((((((rg[6]>>0))&3))==0)?(r3):(((((((rg[6]>>0))&3))==1)?(r4):(((((((rg[6]>>0))&3))==2)?(r5):(((((((rg[6]>>0))&3))==3)?(r6):(0))))))))));
}
break;
case 3:
{
(f[0]=cn_double(((((((rg[6]>>0))&3))==0)?(r3):(((((((rg[6]>>0))&3))==1)?(r4):(((((((rg[6]>>0))&3))==2)?(r5):(((((((rg[6]>>0))&3))==3)?(r6):(0))))))))));
}
break;
default:
{
}
break;
}
{
__auto_type cn_init_871 = rg[2]; __auto_type bv = cn_init_871;
__auto_type cn_init_879 = rg[2]; __auto_type av = cn_init_879;
__auto_type cn_init_897 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_897;
(rg[2]=r);
}
{
__auto_type cn_init_930 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_930;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_968 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_968;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_992 = cn_double(v32); __auto_type v = cn_init_992;
(f[0]=(f[0]*v));
}
(f[1]=f[0]);
{
__auto_type cn_init_1026 = cn_double(v31); __auto_type v = cn_init_1026;
(f[1]=(f[1]-v));
}
(f[1]=cn_round(m,f[1]));
(f[0]=(f[0]-f[1]));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
(f[1]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[1]));
(f[0]=(f[1]-f[0]));
{
__auto_type cn_init_1214 = 0x80000000U; __auto_type bv = cn_init_1214;
__auto_type cn_init_1222 = rg[2]; __auto_type av = cn_init_1222;
__auto_type cn_init_1240 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_1240;
(rg[2]=r);
}
}
cn_break_b2:;
(f[1]=cn_double(0x400921fb54442d18));
(f[0]=(f[0]*f[1]));
(fsw=cn_compare(f[0],cn_double(v33)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
(f[1]=cn_double(0x400921fb54442d18));
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_1381 = 0x80000000U; __auto_type bv = cn_init_1381;
__auto_type cn_init_1389 = rg[2]; __auto_type av = cn_init_1389;
__auto_type cn_init_1407 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_1407;
(rg[2]=r);
}
}
cn_break_b4:;
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[0]));
{
__auto_type cn_init_1467 = cn_double(v34); __auto_type v = cn_init_1467;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_1501 = 0x80000000U; __auto_type bv = cn_init_1501;
__auto_type cn_init_1509 = rg[2]; __auto_type av = cn_init_1509;
cn_alu(&fl,Alu_And,av,bv,4);
}
if(cn_cond(fl,9)){
goto cn_break_b6;
}
(f[0]=-f[0]);
}
cn_break_b6:;
{
(rg[2]=((uint32_t)(((((s2012>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[0]=((uint32_t)(((((s2012>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
__auto_type cn_init_1642 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1642;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1680 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1680;
(f[0]=(f[0]+v));
}
switch(((((rg[6]>>0))&3))){
case 0:
{
switch(((((rg[6]>>0))&3))){
case 0:
{
(r3=cn_bits(f[0]));
}
break;
case 1:
{
(r4=cn_bits(f[0]));
}
break;
case 2:
{
(r5=cn_bits(f[0]));
}
break;
case 3:
{
(r6=cn_bits(f[0]));
}
break;
default:
{
}
break;
}
}
break;
case 1:
{
switch(((((rg[6]>>0))&3))){
case 0:
{
(r3=cn_bits(f[0]));
}
break;
case 1:
{
(r4=cn_bits(f[0]));
}
break;
case 2:
{
(r5=cn_bits(f[0]));
}
break;
case 3:
{
(r6=cn_bits(f[0]));
}
break;
default:
{
}
break;
}
}
break;
case 2:
{
switch(((((rg[6]>>0))&3))){
case 0:
{
(r3=cn_bits(f[0]));
}
break;
case 1:
{
(r4=cn_bits(f[0]));
}
break;
case 2:
{
(r5=cn_bits(f[0]));
}
break;
case 3:
{
(r6=cn_bits(f[0]));
}
break;
default:
{
}
break;
}
}
break;
case 3:
{
switch(((((rg[6]>>0))&3))){
case 0:
{
(r3=cn_bits(f[0]));
}
break;
case 1:
{
(r4=cn_bits(f[0]));
}
break;
case 2:
{
(r5=cn_bits(f[0]));
}
break;
case 3:
{
(r6=cn_bits(f[0]));
}
break;
default:
{
}
break;
}
}
break;
default:
{
}
break;
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
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_a27039696d5a3201(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+152))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_190;
__auto_type cn_init_207 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_207;
__auto_type cn_init_220 = cn_rd64u(m,0x10007e90U); uint64_t s2002 = cn_init_220;
__auto_type cn_init_233 = cn_rd64u(m,0x10007e98U); uint64_t s2003 = cn_init_233;
__auto_type cn_init_246 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_246;
__auto_type cn_init_259 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_259;
__auto_type cn_init_272 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_272;
__auto_type cn_init_285 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_285;
__auto_type cn_init_298 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_298;
__auto_type cn_init_311 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_311;
__auto_type cn_init_324 = cn_cell(vm,0); uint64_t v19 = cn_init_324;
__auto_type cn_init_337 = cn_cell(vm,8); uint64_t v20 = cn_init_337;
__auto_type cn_init_350 = cn_cell(vm,16); uint64_t v21 = cn_init_350;
__auto_type cn_init_363 = cn_cell(vm,24); uint64_t v22 = cn_init_363;
__auto_type cn_init_376 = cn_cell(vm,32); uint64_t v23 = cn_init_376;
__auto_type cn_init_389 = cn_cell(vm,40); uint64_t v24 = cn_init_389;
__auto_type cn_init_402 = cn_cell(vm,48); uint64_t v25 = cn_init_402;
__auto_type cn_init_415 = cn_cell(vm,56); uint64_t v26 = cn_init_415;
__auto_type cn_init_428 = cn_cell(vm,64); uint64_t v27 = cn_init_428;
__auto_type cn_init_441 = cn_cell(vm,72); uint64_t v28 = cn_init_441;
__auto_type cn_init_454 = cn_cell(vm,80); uint64_t v29 = cn_init_454;
__auto_type cn_init_467 = cn_cell(vm,88); uint64_t v30 = cn_init_467;
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
__auto_type cn_init_563 = 0x50U; __auto_type bv = cn_init_563;
__auto_type cn_init_571 = rg[4]; __auto_type av = cn_init_571;
__auto_type cn_init_589 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_589;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2002=(((s2002&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[7]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_788 = 0x80U; __auto_type bv = cn_init_788;
__auto_type cn_init_796 = rg[7]; __auto_type av = cn_init_796;
__auto_type cn_init_814 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_814;
(rg[7]=r);
}
(f[0]=cn_double(r5));
(f[0]=fabs(f[0]));
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
(f[2]=cn_double(r3));
(f[2]=fabs(f[2]));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
cn_swap(f,2,1);
}
cn_break_b2:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
cn_swap(f,2,0);
}
cn_break_b4:;
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b6;
}
cn_swap(f,2,0);
}
cn_break_b6:;
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(v27));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(r3));
(f[1]=(f[1]-f[0]));
(s2012=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(v27));
(f[1]=cn_double(r3));
(f[1]=(f[1]-f[0]));
(f[1]=fabs(f[1]));
(f[1]=(f[0]-f[1]));
(s2009=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]-f[0]));
(f[1]=fabs(f[1]));
(f[1]=(f[0]-f[1]));
(s2008=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b8;
}
(f[1]=cn_double(r5));
(f[1]=(f[1]-f[0]));
(f[1]=fabs(f[1]));
(f[1]=(f[0]-f[1]));
goto cn_break_b9;
}
cn_break_b8:;
{
__auto_type cn_init_1594 = cn_double(r5); __auto_type v = cn_init_1594;
(f[0]=(f[0]+v));
}
(f=(CN_D8){f[7],f[0],f[1],f[2],f[3],f[4],f[5],f[6]});
}
cn_break_b9:;
(s2007=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(s2012));
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b14;
}
(f[1]=cn_double(r4));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b14;
}
(f[1]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1888 = cn_double(r4); __auto_type v = cn_init_1888;
(f[1]=(f[1]+v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b13;
}
(f[1]=cn_double(s2009));
{
__auto_type cn_init_2010 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2010;
(f[1]=(f[1]+v));
}
(s2009=cn_bits(f[1]));
(f[1]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2073 = cn_double(v27); __auto_type v = cn_init_2073;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_2097 = cn_double(r4); __auto_type v = cn_init_2097;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2135 = cn_double(v27); __auto_type v = cn_init_2135;
(f[1]=(v-f[1]));
}
(s2008=cn_bits(f[1]));
goto cn_break_b14;
}
cn_break_b13:;
(f[1]=cn_double(r4));
(f[1]=-f[1]);
(s2009=cn_bits(f[1]));
(f[1]=cn_double(r3));
{
__auto_type cn_init_2220 = cn_double(v27); __auto_type v = cn_init_2220;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_2244 = cn_double(v27); __auto_type v = cn_init_2244;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_2268 = cn_double(v27); __auto_type v = cn_init_2268;
(f[1]=(f[1]-v));
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2306 = cn_double(v27); __auto_type v = cn_init_2306;
(f[1]=(v-f[1]));
}
(s2008=cn_bits(f[1]));
}
cn_break_b14:;
(f[0]=f[0]);
(f[0]=cn_double(s2009));
(f[1]=cn_double(s2008));
(f[2]=cn_double(s2007));
(f[3]=f[2]);
{
__auto_type cn_init_2412 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2412;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_2460 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2460;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2523 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2523;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_2586 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2586;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_2634 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2634;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2697 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2697;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_2759 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2759;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_2806 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2806;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2868 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2868;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[3]=f[2]);
(f[3]=(f[3]*f[2]));
(f[4]=f[1]);
(f[4]=(f[4]*f[1]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[0]));
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_3028 = cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3028;
(f[3]=(f[3]*v));
}
(fsw=cn_compare(f[3],cn_double(v28)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b16;
}
(f[3]=f[3]);
(f[3]=cn_double(v29));
goto cn_break_b19;
}
cn_break_b16:;
(f[4]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b18;
}
(f[4]=f[4]);
{
__auto_type cn_init_3242 = cn_double(v30); __auto_type v = cn_init_3242;
(f[3]=(v/f[3]));
}
goto cn_break_b19;
}
cn_break_b18:;
(fsw=cn_compare(f[4],f[3]));
(f[3]=cn_double(v30));
}
cn_break_b19:;
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[3]));
(r6=cn_bits(f[4]));
(f[0]=(f[0]*f[3]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
{
__auto_type cn_init_3381 = cn_double(r12); __auto_type v = cn_init_3381;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_3416 = cn_double(r11); __auto_type v = cn_init_3416;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_3451 = cn_double(r10); __auto_type v = cn_init_3451;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s2002>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2003>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2003>>32))&0xffffffffULL)))));
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
cn_wr64u(m,0x10007e90U,s2002);
cn_wr64u(m,0x10007e98U,s2003);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_a3b564facf4224ee(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+216))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_359 = cn_cell(vm,0); uint64_t v27 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,8); uint64_t v28 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,16); uint64_t v29 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,24); uint64_t v30 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,40); uint64_t v32 = cn_init_411;
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
__auto_type cn_init_489 = 0x40U; __auto_type bv = cn_init_489;
__auto_type cn_init_497 = rg[4]; __auto_type av = cn_init_497;
__auto_type cn_init_515 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_515;
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
(s2006=cn_bits(f[0]));
(f[1]=cn_double(v30));
cn_swap(f,1,0);
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_935_0 = f[2];
__auto_type cn_tuple_935_1 = f[1];
__auto_type x = cn_tuple_935_0;
__auto_type y = cn_tuple_935_1;
__auto_type cn_init_964 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_964;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_996 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_996;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
(s2013=cn_bits(f[0]));
{
__auto_type cn_init_1132 = 0x0U; __auto_type bv = cn_init_1132;
__auto_type cn_init_1149 = (((uint32_t)(((((v27>>32))&0xffffffffULL))))); __auto_type av = cn_init_1149;
__auto_type cn_init_1167 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1167;
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
(f[0]=cn_double(s2013));
(s2006=cn_bits(f[0]));
goto cn_break_b3;
}
cn_break_b2:;
(f[0]=cn_double(s2006));
(f[1]=cn_double(v29));
cn_swap(f,1,0);
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_1310_0 = f[2];
__auto_type cn_tuple_1310_1 = f[1];
__auto_type x = cn_tuple_1310_0;
__auto_type y = cn_tuple_1310_1;
__auto_type cn_init_1339 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1339;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1371 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1371;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
(s2006=cn_bits(f[0]));
}
cn_break_b3:;
(f[0]=cn_double(r3));
(f[0]=-f[0]);
(f[1]=cn_double(r5));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1561 = 0x0U; __auto_type bv = cn_init_1561;
__auto_type cn_init_1578 = (((uint32_t)(((((v27>>0))&0xffffffffULL))))); __auto_type av = cn_init_1578;
__auto_type cn_init_1596 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1596;
}
if(cn_cond(fl,5)){
goto cn_break_b8;
}
(f[1]=cn_double(r3));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1676 = 0x41U; __auto_type bv = cn_init_1676;
__auto_type cn_init_1689 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1689;
__auto_type cn_init_1707 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1707;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,15)){
goto cn_break_b8;
}
(f[1]=cn_double(r5));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1800 = 0x41U; __auto_type bv = cn_init_1800;
__auto_type cn_init_1813 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1813;
__auto_type cn_init_1831 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1831;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,12)){
goto cn_break_b7;
}
(f[1]=cn_double(0x400921fb54442d18));
{
__auto_type cn_init_1880 = cn_double(v32); __auto_type v = cn_init_1880;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
goto cn_break_b8;
}
cn_break_b7:;
(f[1]=cn_double(0x400921fb54442d18));
{
__auto_type cn_init_1935 = cn_double(v32); __auto_type v = cn_init_1935;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
}
cn_break_b8:;
{
__auto_type cn_init_1975 = cn_double(v29); __auto_type v = cn_init_1975;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_2005_0 = sin(f[0]);
__auto_type cn_tuple_2005_1 = cos(f[0]);
__auto_type s = cn_tuple_2005_0;
__auto_type c = cn_tuple_2005_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2012=cn_bits(f[1]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[1]=cn_double(r3));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_2100 = cn_double(v30); __auto_type v = cn_init_2100;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_2130_0 = sin(f[0]);
__auto_type cn_tuple_2130_1 = cos(f[0]);
__auto_type s = cn_tuple_2130_0;
__auto_type c = cn_tuple_2130_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2010=cn_bits(f[1]));
(s2009=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_2195 = cn_double(s2012); __auto_type v = cn_init_2195;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2219 = cn_double(s2010); __auto_type v = cn_init_2219;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_2254 = cn_double(r10); __auto_type v = cn_init_2254;
(f[0]=(f[0]+v));
}
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_2301 = cn_double(s2012); __auto_type v = cn_init_2301;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2325 = cn_double(s2009); __auto_type v = cn_init_2325;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_2360 = cn_double(r11); __auto_type v = cn_init_2360;
(f[0]=(f[0]+v));
}
(s2007=cn_bits(f[0]));
(f[0]=cn_double(s2006));
{
__auto_type cn_init_2407 = cn_double(s2011); __auto_type v = cn_init_2407;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2431 = cn_double(v28); __auto_type v = cn_init_2431;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2455 = cn_double(r12); __auto_type v = cn_init_2455;
(f[0]=(f[0]+v));
}
(s2006=cn_bits(f[0]));
(f[0]=cn_double(s2008));
(f[1]=cn_double(s2007));
(f[2]=cn_double(s2006));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
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
int cn_f_a4250598b4a80ded(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r4));
(f[1]=cn_double(r3));
{
__auto_type cn_init_436 = cn_double(v28); __auto_type v = cn_init_436;
(f[1]=(f[1]*v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
(f[1]=-f[1]);
{
__auto_type cn_init_490 = cn_double(v29); __auto_type v = cn_init_490;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_529 = cn_double(v30); __auto_type v = cn_init_529;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(v27));
{
__auto_type cn_init_565 = cn_double(r3); __auto_type v = cn_init_565;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_589 = cn_double(v30); __auto_type v = cn_init_589;
(f[1]=(f[1]*v));
}
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r6));
(f[1]=cn_double(r5));
{
__auto_type cn_init_659 = cn_double(v28); __auto_type v = cn_init_659;
(f[1]=(f[1]*v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
(f[1]=-f[1]);
{
__auto_type cn_init_713 = cn_double(v29); __auto_type v = cn_init_713;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_752 = cn_double(v30); __auto_type v = cn_init_752;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(v26));
{
__auto_type cn_init_788 = cn_double(r5); __auto_type v = cn_init_788;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_812 = cn_double(v30); __auto_type v = cn_init_812;
(f[1]=(f[1]*v));
}
(r6=cn_bits(f[1]));
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_a474a32cf1d741bd(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=cn_double(r10));
{
__auto_type cn_init_515 = cn_double(v30); __auto_type v = cn_init_515;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r3=cn_bits(f[2]));
(f[2]=cn_double(r11));
{
__auto_type cn_init_577 = cn_double(v29); __auto_type v = cn_init_577;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r4=cn_bits(f[1]));
(f[1]=cn_double(r12));
{
__auto_type cn_init_639 = cn_double(v28); __auto_type v = cn_init_639;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
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
int cn_f_a4bf55564b130369(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_237 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_237;
__auto_type cn_init_250 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_250;
__auto_type cn_init_263 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_263;
__auto_type cn_init_276 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_276;
__auto_type cn_init_289 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_289;
__auto_type cn_init_302 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_302;
__auto_type cn_init_315 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_315;
__auto_type cn_init_328 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_328;
__auto_type cn_init_341 = cn_cell(vm,0); uint64_t v23 = cn_init_341;
__auto_type cn_init_354 = cn_cell(vm,8); uint64_t v24 = cn_init_354;
__auto_type cn_init_367 = cn_cell(vm,16); uint64_t v25 = cn_init_367;
__auto_type cn_init_380 = cn_cell(vm,24); uint64_t v26 = cn_init_380;
__auto_type cn_init_393 = cn_cell(vm,32); uint64_t v27 = cn_init_393;
__auto_type cn_init_406 = cn_cell(vm,40); uint64_t v28 = cn_init_406;
__auto_type cn_init_419 = cn_cell(vm,48); uint64_t v29 = cn_init_419;
__auto_type cn_init_432 = cn_cell(vm,56); uint64_t v30 = cn_init_432;
__auto_type cn_init_445 = cn_cell(vm,72); uint64_t v32 = cn_init_445;
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
__auto_type cn_init_535 = 0x30U; __auto_type bv = cn_init_535;
__auto_type cn_init_543 = rg[4]; __auto_type av = cn_init_543;
__auto_type cn_init_561 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_561;
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
__auto_type cn_init_777 = cn_double(r6); __auto_type v = cn_init_777;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_813 = cn_double(r5); __auto_type v = cn_init_813;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_849 = cn_double(r6); __auto_type v = cn_init_849;
(f[2]=(f[2]+v));
}
(f[3]=cn_double(r4));
{
__auto_type cn_init_885 = cn_double(r5); __auto_type v = cn_init_885;
(f[3]=(f[3]-v));
}
(r6=cn_bits(f[3]));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[1]=cn_double(v25));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_1009 = 0x41U; __auto_type bv = cn_init_1009;
__auto_type cn_init_1022 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1022;
__auto_type cn_init_1040 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1040;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b2;
}
(f[0]=cn_double(r3));
{
__auto_type cn_init_1089 = cn_double(v30); __auto_type v = cn_init_1089;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1136 = cn_double(v29); __auto_type v = cn_init_1136;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
goto cn_break_b3;
}
cn_break_b2:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_1187 = cn_double(v30); __auto_type v = cn_init_1187;
(f[0]=(f[0]-v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1234 = cn_double(v29); __auto_type v = cn_init_1234;
(f[0]=(f[0]-v));
}
(r4=cn_bits(f[0]));
}
cn_break_b3:;
(f[0]=cn_double(r5));
(f[1]=cn_double(v24));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_1326 = 0x41U; __auto_type bv = cn_init_1326;
__auto_type cn_init_1339 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1339;
__auto_type cn_init_1357 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1357;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b5;
}
(f[0]=cn_double(r5));
{
__auto_type cn_init_1406 = cn_double(v28); __auto_type v = cn_init_1406;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
{
__auto_type cn_init_1453 = cn_double(v27); __auto_type v = cn_init_1453;
(f[0]=(f[0]+v));
}
(r6=cn_bits(f[0]));
goto cn_break_b6;
}
cn_break_b5:;
(f[0]=cn_double(r5));
{
__auto_type cn_init_1504 = cn_double(v28); __auto_type v = cn_init_1504;
(f[0]=(f[0]-v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
{
__auto_type cn_init_1551 = cn_double(v27); __auto_type v = cn_init_1551;
(f[0]=(f[0]-v));
}
(r6=cn_bits(f[0]));
}
cn_break_b6:;
(f[0]=cn_double(r10));
(s2010=cn_bits(f[0]));
(f[0]=cn_double(r11));
(s2009=cn_bits(f[0]));
{
__auto_type cn_init_1628 = 0x0U; __auto_type bv = cn_init_1628;
__auto_type cn_init_1645 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_1645;
__auto_type cn_init_1663 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1663;
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[0]=cn_double(s2009));
(f[0]=-f[0]);
(s2009=cn_bits(f[0]));
}
cn_break_b8:;
{
__auto_type cn_init_1717 = 0x0U; __auto_type bv = cn_init_1717;
__auto_type cn_init_1734 = (((uint32_t)(((((v23>>0))&0xffffffffULL))))); __auto_type av = cn_init_1734;
__auto_type cn_init_1752 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1752;
}
if(cn_cond(fl,4)){
goto cn_break_b10;
}
(f[0]=cn_double(s2010));
(f[1]=cn_double(s2009));
(s2010=cn_bits(f[1]));
(s2009=cn_bits(f[0]));
}
cn_break_b10:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_1835 = cn_double(s2010); __auto_type v = cn_init_1835;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1871 = cn_double(s2009); __auto_type v = cn_init_1871;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r3));
{
__auto_type cn_init_1933 = cn_double(s2009); __auto_type v = cn_init_1933;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r4));
{
__auto_type cn_init_1969 = cn_double(s2010); __auto_type v = cn_init_1969;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r12));
(s2010=cn_bits(f[0]));
(f[0]=cn_double(r0));
(s2009=cn_bits(f[0]));
{
__auto_type cn_init_2071 = 0x0U; __auto_type bv = cn_init_2071;
__auto_type cn_init_2088 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_2088;
__auto_type cn_init_2106 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2106;
}
if(cn_cond(fl,4)){
goto cn_break_b12;
}
(f[0]=cn_double(s2009));
(f[0]=-f[0]);
(s2009=cn_bits(f[0]));
}
cn_break_b12:;
{
__auto_type cn_init_2160 = 0x0U; __auto_type bv = cn_init_2160;
__auto_type cn_init_2177 = (((uint32_t)(((((v23>>0))&0xffffffffULL))))); __auto_type av = cn_init_2177;
__auto_type cn_init_2195 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2195;
}
if(cn_cond(fl,4)){
goto cn_break_b14;
}
(f[0]=cn_double(s2010));
(f[1]=cn_double(s2009));
(s2010=cn_bits(f[1]));
(s2009=cn_bits(f[0]));
}
cn_break_b14:;
(f[0]=cn_double(r5));
{
__auto_type cn_init_2278 = cn_double(s2010); __auto_type v = cn_init_2278;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r6));
{
__auto_type cn_init_2314 = cn_double(s2009); __auto_type v = cn_init_2314;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r3));
{
__auto_type cn_init_2376 = cn_double(s2009); __auto_type v = cn_init_2376;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r6));
{
__auto_type cn_init_2412 = cn_double(s2010); __auto_type v = cn_init_2412;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_2451 = cn_double(v26); __auto_type v = cn_init_2451;
(f[1]=(f[1]+v));
}
(r6=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_2509 = cn_double(r5); __auto_type v = cn_init_2509;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2533 = cn_double(v32); __auto_type v = cn_init_2533;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_2580 = cn_double(r6); __auto_type v = cn_init_2580;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2604 = cn_double(v32); __auto_type v = cn_init_2604;
(f[0]=(f[0]*v));
}
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_2651 = cn_double(r6); __auto_type v = cn_init_2651;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2675 = cn_double(v32); __auto_type v = cn_init_2675;
(f[0]=(f[0]*v));
}
(s2010=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=-f[0]);
{
__auto_type cn_init_2733 = cn_double(r5); __auto_type v = cn_init_2733;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2757 = cn_double(v32); __auto_type v = cn_init_2757;
(f[0]=(f[0]*v));
}
(s2009=cn_bits(f[0]));
(f[0]=cn_double(s2009));
(r6=cn_bits(f[0]));
(f[0]=cn_double(s2010));
(r5=cn_bits(f[0]));
(f[0]=cn_double(s2011));
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2012));
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_a54e8329bc37d850(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r4));
{
__auto_type cn_init_424 = cn_double(r5); __auto_type v = cn_init_424;
(f[0]=(f[0]+v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_459 = cn_double(v30); __auto_type v = cn_init_459;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
(f[2]=cn_double(r4));
{
__auto_type cn_init_507 = cn_double(v29); __auto_type v = cn_init_507;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_546 = cn_double(r6); __auto_type v = cn_init_546;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_570 = cn_double(v30); __auto_type v = cn_init_570;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v28));
(f[3]=cn_double(r3));
{
__auto_type cn_init_618 = cn_double(r5); __auto_type v = cn_init_618;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_657 = cn_double(v30); __auto_type v = cn_init_657;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(v27));
{
__auto_type cn_init_693 = cn_double(r5); __auto_type v = cn_init_693;
(f[3]=(f[3]*v));
}
(f[3]=-f[3]);
(f[4]=cn_double(v26));
{
__auto_type cn_init_740 = cn_double(r6); __auto_type v = cn_init_740;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_779 = cn_double(v30); __auto_type v = cn_init_779;
(f[3]=(f[3]*v));
}
(r6=cn_bits(f[3]));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
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
int cn_f_a6dbf2766292a63e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_58 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_58;
__auto_type cn_init_75 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_75;
__auto_type cn_init_92 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_92;
__auto_type cn_init_105 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_105;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(f[0]=cn_double(r3));
{
__auto_type cn_init_188 = cn_double(r3); __auto_type v = cn_init_188;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_224 = cn_double(r4); __auto_type v = cn_init_224;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_275 = cn_double(r5); __auto_type v = cn_init_275;
(f[1]=(f[1]*v));
}
(f[1]=(f[1]+f[0]));
(f[1]=sqrt(f[1]));
cn_swap(f,1,0);
(f[1]=sqrt(f[1]));
(f[2]=cn_double(r5));
(f[1]=atan2(f[1],f[2]));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[2]=atan2(f[2],f[3]));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
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
int cn_f_a7936171b561b3d0(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+176))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v22 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,8); uint64_t v23 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,16); uint64_t v24 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,24); uint64_t v25 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,32); uint64_t v26 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,40); uint64_t v27 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,48); uint64_t v28 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,56); uint64_t v29 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,64); uint64_t v30 = cn_init_312;
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
(f[0]=fabs(f[0]));
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
(f[2]=cn_double(r3));
(f[2]=fabs(f[2]));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
cn_swap(f,2,1);
}
cn_break_b2:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
cn_swap(f,2,0);
}
cn_break_b4:;
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b6;
}
cn_swap(f,2,0);
}
cn_break_b6:;
(f[3]=f[1]);
{
__auto_type cn_init_881 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_881;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_929 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_929;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_992 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_992;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_1055 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1055;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1103 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1103;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1166 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1166;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_1228 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1228;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_1275 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1275;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1337 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1337;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(v30));
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[3]));
(r6=cn_bits(f[4]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
(f[4]=f[3]);
(f[5]=cn_double(0x3ff0000000000000));
(f[4]=(f[4]-f[5]));
(f[5]=f[4]);
(f[6]=f[5]);
{
__auto_type cn_init_1513 = cn_double(v29); __auto_type v = cn_init_1513;
(f[6]=(f[6]*v));
}
(f[1]=(f[1]-f[6]));
{
__auto_type cn_init_1552 = cn_double(v28); __auto_type v = cn_init_1552;
(f[5]=(f[5]*v));
}
(f[2]=(f[2]-f[5]));
(f[4]=(f[4]/f[3]));
{
__auto_type cn_init_1606 = cn_double(v27); __auto_type v = cn_init_1606;
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
int cn_f_a85da18b6fe095bc(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+240))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_122;
__auto_type cn_init_135 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_135;
__auto_type cn_init_148 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_148;
__auto_type cn_init_161 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_161;
__auto_type cn_init_174 = cn_cell(vm,0); uint64_t v30 = cn_init_174;
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
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[0]=-f[0]);
{
__auto_type cn_init_420 = cn_double(v30); __auto_type v = cn_init_420;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[1]=atan2(f[1],f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
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
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_a9861b5923bb62f5(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+152))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v19 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,8); uint64_t v20 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,16); uint64_t v21 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,24); uint64_t v22 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,32); uint64_t v23 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,40); uint64_t v24 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,48); uint64_t v25 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,56); uint64_t v26 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,64); uint64_t v27 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,72); uint64_t v28 = cn_init_325;
__auto_type cn_init_338 = cn_cell(vm,80); uint64_t v29 = cn_init_338;
__auto_type cn_init_351 = cn_cell(vm,88); uint64_t v30 = cn_init_351;
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
(f[2]=-f[2]);
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b2;
}
cn_swap(f,2,1);
}
cn_break_b2:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
cn_swap(f,2,0);
}
cn_break_b4:;
(f[2]=-f[2]);
cn_swap(f,2,1);
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
(f[3]=cn_double(v26));
(f[2]=(f[2]+f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v25));
(f[1]=(f[1]+f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v24));
(f[0]=(f[0]+f[3]));
(f[3]=f[3]);
(f[3]=f[2]);
{
__auto_type cn_init_1042 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1042;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1090 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1090;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1153 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1153;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1216 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1216;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1264 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1264;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1327 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1327;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1389 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1389;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1436 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1436;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1498 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1498;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[3]=cn_double(v26));
(f[2]=(f[2]-f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v25));
(f[1]=(f[1]-f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v24));
(f[0]=(f[0]-f[3]));
(f[3]=f[3]);
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
{
__auto_type cn_init_1780 = cn_double(v27); __auto_type v = cn_init_1780;
(f[4]=(f[4]*v));
}
(f[0]=(f[0]-f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_1829 = cn_double(v28); __auto_type v = cn_init_1829;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]-f[4]));
{
__auto_type cn_init_1868 = cn_double(v29); __auto_type v = cn_init_1868;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]-f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
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
int cn_f_aa054baa11be9c8e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+160))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_175;
__auto_type cn_init_188 = cn_cell(vm,0); uint64_t v20 = cn_init_188;
__auto_type cn_init_201 = cn_cell(vm,8); uint64_t v21 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,16); uint64_t v22 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,24); uint64_t v23 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,32); uint64_t v24 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,40); uint64_t v25 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,48); uint64_t v26 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,56); uint64_t v27 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,64); uint64_t v28 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,72); uint64_t v29 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,80); uint64_t v30 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,96); uint64_t v32 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,104); uint64_t v33 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,112); uint64_t v34 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,120); uint64_t v35 = cn_init_370;
{
(f[0]=cn_double(r5));
{
__auto_type cn_init_396 = cn_double(v28); __auto_type v = cn_init_396;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_432 = cn_double(v29); __auto_type v = cn_init_432;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_468 = cn_double(v30); __auto_type v = cn_init_468;
(f[2]=(f[2]+v));
}
(f[3]=f[2]);
{
__auto_type cn_init_516 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_516;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_564 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_564;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_627 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_627;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_690 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_690;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_738 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_738;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_801 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_801;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_863 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_863;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_910 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_910;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_972 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_972;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
{
__auto_type cn_init_1039 = 0xffffffd8U; __auto_type bv = cn_init_1039;
__auto_type cn_init_1047 = rg[4]; __auto_type av = cn_init_1047;
__auto_type cn_init_1065 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1065;
(rg[4]=r);
}
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1183 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1183;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1211 = cn_bits(f[0]); uint64_t v = cn_init_1211;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[1]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
{
__auto_type cn_init_1316 = cn_double(v32); __auto_type v = cn_init_1316;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1344 = cn_bits(f[0]); uint64_t v = cn_init_1344;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(r4));
(f[1]=cn_double(r3));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1440 = cn_double(v32); __auto_type v = cn_init_1440;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1468 = cn_bits(f[0]); uint64_t v = cn_init_1468;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=(((double)(((int32_t)(((uint32_t)(((((v23>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_1561 = cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1561;
(f[0]=(f[0]*v));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((v22>>32))&0xffffffffULL))))))))));
{
__auto_type cn_init_1624 = cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1624;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=f[0]);
(f[1]=cn_round(m,f[1]));
(f[0]=(f[1]-f[0]));
{
__auto_type cn_init_1703 = cn_double(v33); __auto_type v = cn_init_1703;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(f[0]=(((double)(((int32_t)(((uint32_t)(((((v22>>32))&0xffffffffULL))))))))));
{
__auto_type cn_init_1777 = cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1777;
(f[0]=(f[0]*v));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((v23>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_1840 = cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1840;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=f[0]);
(f[1]=cn_round(m,f[1]));
(f[0]=(f[1]-f[0]));
{
__auto_type cn_init_1930 = cn_double(v33); __auto_type v = cn_init_1930;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r32));
(f[1]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_2019 = cn_double(v34); __auto_type v = cn_init_2019;
(f[1]=(f[1]+v));
}
(f[0]=(f[1]/f[0]));
(f[1]=(((double)(((int32_t)(((uint32_t)(((((v22>>32))&0xffffffffULL))))))))));
(f[1]=(f[1]*f[1]));
(f[2]=(((double)(((int32_t)(((uint32_t)(((((v23>>0))&0xffffffffULL))))))))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2236 = cn_double(v35); __auto_type v = cn_init_2236;
(f[0]=(f[0]*v));
}
(r32=cn_bits(f[0]));
{
__auto_type cn_init_2266 = 0x28U; __auto_type bv = cn_init_2266;
__auto_type cn_init_2274 = rg[4]; __auto_type av = cn_init_2274;
__auto_type cn_init_2292 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2292;
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
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_aae0cddc3ff577d8(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+176))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(0)); uint64_t r0 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_190;
__auto_type cn_init_207 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_207;
__auto_type cn_init_224 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_224;
__auto_type cn_init_241 = cn_rd64(m,CN_REC+8*(36)); uint64_t r36 = cn_init_241;
__auto_type cn_init_254 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_254;
__auto_type cn_init_267 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_267;
__auto_type cn_init_280 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_280;
__auto_type cn_init_293 = cn_cell(vm,0); uint64_t v22 = cn_init_293;
__auto_type cn_init_306 = cn_cell(vm,8); uint64_t v23 = cn_init_306;
__auto_type cn_init_319 = cn_cell(vm,16); uint64_t v24 = cn_init_319;
__auto_type cn_init_332 = cn_cell(vm,24); uint64_t v25 = cn_init_332;
__auto_type cn_init_345 = cn_cell(vm,32); uint64_t v26 = cn_init_345;
__auto_type cn_init_358 = cn_cell(vm,40); uint64_t v27 = cn_init_358;
__auto_type cn_init_371 = cn_cell(vm,48); uint64_t v28 = cn_init_371;
__auto_type cn_init_384 = cn_cell(vm,56); uint64_t v29 = cn_init_384;
__auto_type cn_init_397 = cn_cell(vm,64); uint64_t v30 = cn_init_397;
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
(rg[7]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_600 = 0x80U; __auto_type bv = cn_init_600;
__auto_type cn_init_608 = rg[7]; __auto_type av = cn_init_608;
__auto_type cn_init_626 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_626;
(rg[7]=r);
}
(f[0]=cn_double(v27));
(f[1]=cn_double(r3));
(f[2]=f[1]);
(f[2]=(f[2]-f[0]));
(f[2]=fabs(f[2]));
(f[2]=(f[2]+f[1]));
cn_swap(f,2,1);
(f[2]=(f[2]+f[0]));
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_776 = cn_double(v26); __auto_type v = cn_init_776;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(r4));
(f[3]=f[2]);
(f[3]=(f[3]-f[0]));
(f[3]=fabs(f[3]));
(f[3]=(f[3]+f[2]));
cn_swap(f,3,2);
(f[3]=(f[3]+f[0]));
(f[3]=fabs(f[3]));
(f[2]=(f[3]-f[2]));
{
__auto_type cn_init_919 = cn_double(v25); __auto_type v = cn_init_919;
(f[2]=(f[2]-v));
}
(f[3]=cn_double(r5));
(f[4]=f[3]);
(f[4]=(f[4]-f[0]));
(f[4]=fabs(f[4]));
(f[4]=(f[4]+f[3]));
cn_swap(f,4,3);
(f[4]=(f[4]+f[0]));
(f[4]=fabs(f[4]));
(f[3]=(f[4]-f[3]));
{
__auto_type cn_init_1062 = cn_double(v24); __auto_type v = cn_init_1062;
(f[3]=(f[3]-v));
}
(f[4]=cn_double(r6));
(f[5]=f[4]);
(f[5]=(f[5]-f[0]));
(f[5]=fabs(f[5]));
(f[5]=(f[5]+f[4]));
cn_swap(f,5,4);
(f[5]=(f[5]+f[0]));
(f[5]=fabs(f[5]));
(f[4]=(f[5]-f[4]));
{
__auto_type cn_init_1205 = cn_double(v23); __auto_type v = cn_init_1205;
(f[4]=(f[4]-v));
}
cn_swap(f,4,0);
(f[4]=f[4]);
(f[4]=f[3]);
(f[4]=(f[4]*f[3]));
(f[5]=f[2]);
(f[5]=(f[5]*f[2]));
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
(f[5]=(f[5]*f[1]));
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
(f[5]=(f[5]*f[0]));
(f[4]=(f[4]+f[5]));
(fsw=cn_compare(f[4],cn_double(v28)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
(f[4]=f[4]);
(f[4]=cn_double(v29));
goto cn_break_b5;
}
cn_break_b2:;
(f[5]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[5],f[4]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
(f[5]=cn_double(v30));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
(f[5]=(f[5]/f[4]));
}
cn_break_b4:;
cn_swap(f,5,4);
(f[5]=f[5]);
}
cn_break_b5:;
(f[5]=cn_double(r36));
(f[5]=(f[5]*f[4]));
(r36=cn_bits(f[5]));
(f[0]=(f[0]*f[4]));
(f[1]=(f[1]*f[4]));
(f[2]=(f[2]*f[4]));
(f[3]=(f[3]*f[4]));
{
__auto_type cn_init_1719 = cn_double(r12); __auto_type v = cn_init_1719;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_1743 = cn_double(v24); __auto_type v = cn_init_1743;
(f[3]=(f[3]+v));
}
(r5=cn_bits(f[3]));
{
__auto_type cn_init_1778 = cn_double(r11); __auto_type v = cn_init_1778;
(f[2]=(f[2]+v));
}
{
__auto_type cn_init_1802 = cn_double(v25); __auto_type v = cn_init_1802;
(f[2]=(f[2]+v));
}
(r4=cn_bits(f[2]));
{
__auto_type cn_init_1837 = cn_double(r10); __auto_type v = cn_init_1837;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_1861 = cn_double(v26); __auto_type v = cn_init_1861;
(f[1]=(f[1]+v));
}
(r3=cn_bits(f[1]));
{
__auto_type cn_init_1896 = cn_double(v22); __auto_type v = cn_init_1896;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1920 = cn_double(v23); __auto_type v = cn_init_1920;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1944 = cn_double(r0); __auto_type v = cn_init_1944;
(f[0]=(f[0]+v));
}
(r6=cn_bits(f[0]));
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
cn_wr64(m,CN_REC+8*(36),r36);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
