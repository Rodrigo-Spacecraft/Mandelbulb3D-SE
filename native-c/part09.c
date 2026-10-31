/* Generated native C formula calculations. See tools/generate-native-c.py. */
#include "runtime.h"
int cn_f_8895d8ee74f58c13(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_47 = 0ULL; __auto_type steps = cn_init_47;
__auto_type cn_init_52 = max_steps; __auto_type limit = cn_init_52;
__auto_type cn_init_62 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+256))); unsigned char * vm = cn_init_82;
__auto_type cn_init_99 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_99;
__auto_type cn_init_116 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_116;
__auto_type cn_init_133 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_133;
__auto_type cn_init_150 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_150;
__auto_type cn_init_167 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_167;
__auto_type cn_init_184 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_184;
__auto_type cn_init_201 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007e98U); uint64_t s2003 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_240;
__auto_type cn_init_253 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_253;
__auto_type cn_init_266 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_266;
__auto_type cn_init_279 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_279;
__auto_type cn_init_292 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_292;
__auto_type cn_init_305 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_305;
__auto_type cn_init_318 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_318;
__auto_type cn_init_331 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_331;
__auto_type cn_init_344 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_344;
__auto_type cn_init_357 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_357;
__auto_type cn_init_370 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,0); uint64_t v32 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,8); uint64_t v33 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,16); uint64_t v34 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,24); uint64_t v35 = cn_init_422;
__auto_type cn_init_435 = cn_cell(vm,32); uint64_t v36 = cn_init_435;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_501 = 0xffffffb4U; __auto_type bv = cn_init_501;
__auto_type cn_init_509 = rg[4]; __auto_type av = cn_init_509;
__auto_type cn_init_527 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_527;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<0))));
}
(rg[7]=rg[1]);
(rg[6]=rg[2]);
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
(rg[0]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
(rg[0]=((uint32_t)(((((s2004>>32))&0xffffffffULL)))));
(rg[3]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[0]=atan2(f[0],f[1]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(s2012));
(rg[0]=((uint32_t)(rg[3]+0x20U)));
{
__auto_type cn_init_898 = cn_double(v36); __auto_type v = cn_init_898;
(f[0]=(f[0]+v));
}
(s2012=cn_bits(f[0]));
{
__auto_type cn_init_931 = rg[0]; __auto_type bv = cn_init_931;
__auto_type cn_init_939 = rg[0]; __auto_type av = cn_init_939;
__auto_type cn_init_957 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_957;
(rg[0]=r);
}
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
(s2011=(((s2011&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
cn_continue_l2:;
{
{
(f[0]=cn_double(s2012));
(fsw=cn_compare(f[0],cn_double(v32)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_1098 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1098;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,7)){
goto cn_break_b1;
}
(f[0]=cn_double(s2011));
{
__auto_type cn_tuple_1190_0 = sin(f[0]);
__auto_type cn_tuple_1190_1 = cos(f[0]);
__auto_type s = cn_tuple_1190_0;
__auto_type c = cn_tuple_1190_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2010=cn_bits(f[1]));
(s2009=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1255 = cn_double(s2010); __auto_type v = cn_init_1255;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1291 = cn_double(s2009); __auto_type v = cn_init_1291;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
(s2006=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1353 = cn_double(s2009); __auto_type v = cn_init_1353;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1389 = cn_double(s2010); __auto_type v = cn_init_1389;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(s2005=cn_bits(f[0]));
(rg[0]=((uint32_t)(((((s2006>>0))&0xffffffffULL)))));
(r4=(((r4&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
(rg[0]=((uint32_t)(((((s2006>>32))&0xffffffffULL)))));
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
(rg[0]=((uint32_t)(((((s2005>>0))&0xffffffffULL)))));
(r5=(((r5&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
(rg[0]=((uint32_t)(((((s2005>>32))&0xffffffffULL)))));
(r5=(((r5&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
(f[0]=cn_double(r5));
{
__auto_type cn_init_1639 = cn_double(r5); __auto_type v = cn_init_1639;
(f[0]=(f[0]*v));
}
(rg[0]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(f[1]=cn_double(r3));
(rg[0]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1709 = cn_double(r3); __auto_type v = cn_init_1709;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r4));
{
__auto_type cn_init_1745 = cn_double(r4); __auto_type v = cn_init_1745;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r5));
{
__auto_type cn_init_1796 = cn_double(r5); __auto_type v = cn_init_1796;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]/f[1]));
(rg[0]=((uint32_t)(rg[3]+0x10U)));
{
__auto_type cn_init_1865 = cn_double(v34); __auto_type v = cn_init_1865;
(f[0]=(v-f[0]));
}
(s2008=cn_bits(f[0]));
(rg[0]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(f[0]=cn_double(r3));
(rg[0]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1946 = cn_double(r3); __auto_type v = cn_init_1946;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1982 = cn_double(r4); __auto_type v = cn_init_1982;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_2021 = cn_double(s2008); __auto_type v = cn_init_2021;
(f[0]=(f[0]*v));
}
(s2007=cn_bits(f[0]));
(rg[0]=((uint32_t)(rg[3]+0x18U)));
(f[0]=cn_double(v35));
(rg[0]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2100 = cn_double(r3); __auto_type v = cn_init_2100;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2124 = cn_double(r4); __auto_type v = cn_init_2124;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2148 = cn_double(s2008); __auto_type v = cn_init_2148;
(f[0]=(f[0]*v));
}
(s2006=cn_bits(f[0]));
(rg[0]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(f[0]=cn_double(r3));
(rg[0]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2229 = cn_double(r3); __auto_type v = cn_init_2229;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_2265 = cn_double(r4); __auto_type v = cn_init_2265;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2313 = 0x18U; __auto_type bv = cn_init_2313;
__auto_type cn_init_2321 = rg[3]; __auto_type av = cn_init_2321;
__auto_type cn_init_2339 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2339;
(rg[3]=r);
}
(f[1]=cn_double(v35));
{
__auto_type cn_init_2370 = cn_double(r5); __auto_type v = cn_init_2370;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]*f[1]));
(s2005=cn_bits(f[0]));
(f[0]=cn_double(s2007));
(rg[0]=((uint32_t)(((((s2004>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2449 = cn_double(r10); __auto_type v = cn_init_2449;
(f[0]=(f[0]+v));
}
(rg[0]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2006));
{
__auto_type cn_init_2513 = cn_double(s2010); __auto_type v = cn_init_2513;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2005));
{
__auto_type cn_init_2549 = cn_double(s2009); __auto_type v = cn_init_2549;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(rg[0]=((uint32_t)(((((s2004>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2605 = cn_double(r11); __auto_type v = cn_init_2605;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2005));
{
__auto_type cn_init_2652 = cn_double(s2010); __auto_type v = cn_init_2652;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2006));
{
__auto_type cn_init_2688 = cn_double(s2009); __auto_type v = cn_init_2688;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
(rg[0]=((uint32_t)(((((s2004>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2744 = cn_double(r12); __auto_type v = cn_init_2744;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
{
(rg[7]=((uint32_t)(((((s2003>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2003>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2004>>0))&0xffffffffULL)))));
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
cn_break_b1:;
(f[0]=cn_double(s2012));
(rg[0]=((uint32_t)(rg[3]+0x8U)));
{
__auto_type cn_init_2971 = cn_double(v33); __auto_type v = cn_init_2971;
(f[0]=(f[0]-v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(s2011));
(rg[0]=((uint32_t)(rg[3]+0x8U)));
{
__auto_type cn_init_3033 = cn_double(v33); __auto_type v = cn_init_3033;
(f[0]=(f[0]-v));
}
(s2011=cn_bits(f[0]));
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
int cn_f_889ae4f4102ead81(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+240))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_88;
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
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[2])))&0xffffffffULL))<<0))));
}
(f[0]=cn_double(r5));
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
{
__auto_type cn_init_358 = (((uint32_t)(((((r5>>56))&0xffULL))))); __auto_type v = cn_init_358;
cn_reg_set(rg,2,1,v);
}
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_414 = cn_double(v30); __auto_type v = cn_init_414;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_433 = 0x80U; __auto_type bv = cn_init_433;
__auto_type cn_init_446 = cn_reg_get(rg,2,1); __auto_type av = cn_init_446;
__auto_type cn_init_464 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_464;
cn_reg_set(rg,2,1,r);
}
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(r5=cn_bits(f[0]));
{
__auto_type cn_init_530 = cn_reg_get(rg,2,1); __auto_type bv = cn_init_530;
__auto_type cn_init_547 = (((uint32_t)(((((r5>>56))&0xffULL))))); __auto_type av = cn_init_547;
__auto_type cn_init_565 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_565;
(r5=(((r5&~((0xffULL<<56))))|(((((((uint64_t)((r))))&0xffULL))<<56))));
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
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_8a76a45777ac6fb6(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_333 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_333;
__auto_type cn_init_346 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_346;
__auto_type cn_init_359 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,0); uint64_t v25 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,8); uint64_t v26 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,16); uint64_t v27 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,24); uint64_t v28 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,32); uint64_t v29 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,40); uint64_t v30 = cn_init_437;
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
__auto_type cn_init_512 = 0x48U; __auto_type bv = cn_init_512;
__auto_type cn_init_520 = rg[4]; __auto_type av = cn_init_520;
__auto_type cn_init_538 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_538;
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
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(f[0]=cn_double(v28));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(v30));
{
__auto_type cn_init_777 = cn_double(v29); __auto_type v = cn_init_777;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(s2005=cn_bits(f[0]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_975 = cn_double(s2013); __auto_type v = cn_init_975;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_999 = cn_double(s2005); __auto_type v = cn_init_999;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(s2008=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_1075 = cn_double(s2013); __auto_type v = cn_init_1075;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1099 = cn_double(s2005); __auto_type v = cn_init_1099;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(s2007=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_1175 = cn_double(s2013); __auto_type v = cn_init_1175;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1199 = cn_double(s2005); __auto_type v = cn_init_1199;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(s2006=cn_bits(f[1]));
(f[1]=cn_double(v30));
(f[2]=cn_double(s2008));
(f[2]=fabs(f[2]));
(f[1]*=log2(f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[3]=f[1]);
{
__auto_type cn_tuple_1331_0 = f[3];
__auto_type cn_tuple_1331_1 = f[2];
__auto_type x = cn_tuple_1331_0;
__auto_type y = cn_tuple_1331_1;
__auto_type cn_init_1360 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1360;
(f[3]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1392 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1392;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[3]=(exp2(f[3])-1.0));
(f[2]=(f[2]+f[3]));
(f[2]*=exp2(trunc(f[1])));
cn_swap(f,2,1);
(f[2]=f[2]);
(s2008=cn_bits(f[1]));
(f[1]=cn_double(v30));
(f[2]=cn_double(s2007));
(f[2]=fabs(f[2]));
(f[1]*=log2(f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[3]=f[1]);
{
__auto_type cn_tuple_1616_0 = f[3];
__auto_type cn_tuple_1616_1 = f[2];
__auto_type x = cn_tuple_1616_0;
__auto_type y = cn_tuple_1616_1;
__auto_type cn_init_1645 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1645;
(f[3]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1677 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1677;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[3]=(exp2(f[3])-1.0));
(f[2]=(f[2]+f[3]));
(f[2]*=exp2(trunc(f[1])));
cn_swap(f,2,1);
(f[2]=f[2]);
(s2007=cn_bits(f[1]));
(f[1]=cn_double(v30));
(f[2]=cn_double(s2006));
(f[2]=fabs(f[2]));
(f[1]*=log2(f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[3]=f[1]);
{
__auto_type cn_tuple_1901_0 = f[3];
__auto_type cn_tuple_1901_1 = f[2];
__auto_type x = cn_tuple_1901_0;
__auto_type y = cn_tuple_1901_1;
__auto_type cn_init_1930 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1930;
(f[3]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1962 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1962;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[3]=(exp2(f[3])-1.0));
(f[2]=(f[2]+f[3]));
(f[2]*=exp2(trunc(f[1])));
cn_swap(f,2,1);
(f[2]=f[2]);
(s2006=cn_bits(f[1]));
(f[1]=cn_double(r3));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2129 = cn_double(s2012); __auto_type v = cn_init_2129;
(f[1]=(f[1]*v));
}
(f[2]=f[0]);
cn_swap(f,2,1);
(f[1]=atan2(f[1],f[2]));
(s2011=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2227 = cn_double(s2012); __auto_type v = cn_init_2227;
(f[1]=(f[1]*v));
}
(f[2]=f[0]);
cn_swap(f,2,1);
(f[1]=atan2(f[1],f[2]));
(s2010=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2325 = cn_double(s2012); __auto_type v = cn_init_2325;
(f[1]=(f[1]*v));
}
(f[2]=f[0]);
cn_swap(f,2,1);
(f[1]=atan2(f[1],f[2]));
(s2009=cn_bits(f[1]));
(f[1]=cn_double(s2011));
{
__auto_type cn_init_2409 = cn_double(v30); __auto_type v = cn_init_2409;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2433 = cn_double(v27); __auto_type v = cn_init_2433;
(f[1]=(f[1]+v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_2476 = cn_double(s2008); __auto_type v = cn_init_2476;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r3));
(f[3]=cn_double(0x0));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_2556 = 0x41U; __auto_type bv = cn_init_2556;
__auto_type cn_init_2569 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2569;
__auto_type cn_init_2587 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2587;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(f[1]=-f[1]);
}
cn_break_b2:;
(f[2]=cn_double(r10));
{
__auto_type cn_init_2648 = cn_double(v27); __auto_type v = cn_init_2648;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r3=cn_bits(f[1]));
(f[1]=cn_double(s2010));
{
__auto_type cn_init_2710 = cn_double(v30); __auto_type v = cn_init_2710;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2734 = cn_double(v27); __auto_type v = cn_init_2734;
(f[1]=(f[1]+v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_2777 = cn_double(s2007); __auto_type v = cn_init_2777;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r4));
(f[3]=cn_double(0x0));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_2857 = 0x41U; __auto_type bv = cn_init_2857;
__auto_type cn_init_2870 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2870;
__auto_type cn_init_2888 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2888;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
(f[1]=-f[1]);
}
cn_break_b4:;
(f[2]=cn_double(r11));
{
__auto_type cn_init_2949 = cn_double(v26); __auto_type v = cn_init_2949;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r4=cn_bits(f[1]));
(f[1]=cn_double(s2009));
{
__auto_type cn_init_3011 = cn_double(v30); __auto_type v = cn_init_3011;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3035 = cn_double(v27); __auto_type v = cn_init_3035;
(f[1]=(f[1]+v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_3078 = cn_double(s2006); __auto_type v = cn_init_3078;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
(f[3]=cn_double(0x0));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_3158 = 0x41U; __auto_type bv = cn_init_3158;
__auto_type cn_init_3171 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3171;
__auto_type cn_init_3189 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3189;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
(f[1]=-f[1]);
}
cn_break_b6:;
(f[2]=cn_double(r12));
{
__auto_type cn_init_3250 = cn_double(v25); __auto_type v = cn_init_3250;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r5=cn_bits(f[1]));
(f[0]=f[0]);
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
int cn_f_8ad16c5350b999d7(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+232))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_195;
__auto_type cn_init_208 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_208;
__auto_type cn_init_221 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_221;
__auto_type cn_init_234 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_234;
__auto_type cn_init_247 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_247;
__auto_type cn_init_260 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,0); uint64_t v29 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,8); uint64_t v30 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,24); uint64_t v32 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,32); uint64_t v33 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,40); uint64_t v34 = cn_init_325;
__auto_type cn_init_338 = cn_cell(vm,48); uint64_t v35 = cn_init_338;
__auto_type cn_init_351 = cn_cell(vm,56); uint64_t v36 = cn_init_351;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_417 = 0x30U; __auto_type bv = cn_init_417;
__auto_type cn_init_425 = rg[4]; __auto_type av = cn_init_425;
__auto_type cn_init_443 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_443;
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
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2010=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_795 = cn_double(v36); __auto_type v = cn_init_795;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r6));
{
__auto_type cn_init_831 = cn_double(v35); __auto_type v = cn_init_831;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_907 = cn_double(v35); __auto_type v = cn_init_907;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r6));
{
__auto_type cn_init_943 = cn_double(v36); __auto_type v = cn_init_943;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(s2012=cn_bits(f[0]));
{
__auto_type cn_init_1004 = cn_double(v32); __auto_type v = cn_init_1004;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1040 = cn_double(v33); __auto_type v = cn_init_1040;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_1090 = cn_double(v34); __auto_type v = cn_init_1090;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_1137 = cn_double(v33); __auto_type v = cn_init_1137;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1173 = cn_double(v32); __auto_type v = cn_init_1173;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(f[1]=cn_double(s2013));
(f[2]=cn_double(r4));
{
__auto_type cn_init_1250 = cn_double(v34); __auto_type v = cn_init_1250;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[1]=fabs(f[1]));
(f[2]=cn_double(s2013));
(f[3]=cn_double(r4));
{
__auto_type cn_init_1338 = cn_double(v34); __auto_type v = cn_init_1338;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[2]=fabs(f[2]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1436 = cn_double(r4); __auto_type v = cn_init_1436;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1460 = cn_double(v34); __auto_type v = cn_init_1460;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=-f[0]);
{
__auto_type cn_init_1518 = cn_double(r4); __auto_type v = cn_init_1518;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1542 = cn_double(v34); __auto_type v = cn_init_1542;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1589 = cn_double(v32); __auto_type v = cn_init_1589;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1625 = cn_double(v33); __auto_type v = cn_init_1625;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(s2012=cn_bits(f[0]));
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1687 = cn_double(v33); __auto_type v = cn_init_1687;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[2]=cn_double(r5));
{
__auto_type cn_init_1734 = cn_double(v32); __auto_type v = cn_init_1734;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r5=cn_bits(f[1]));
{
__auto_type cn_init_1784 = cn_double(v36); __auto_type v = cn_init_1784;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
(f[1]=cn_double(s2011));
{
__auto_type cn_init_1831 = cn_double(v35); __auto_type v = cn_init_1831;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r6=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_1893 = cn_double(v35); __auto_type v = cn_init_1893;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2011));
{
__auto_type cn_init_1929 = cn_double(v36); __auto_type v = cn_init_1929;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(s2013=cn_bits(f[0]));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2092 = cn_double(s2010); __auto_type v = cn_init_2092;
(f[0]=(v/f[0]));
}
(s2012=cn_bits(f[0]));
{
__auto_type cn_init_2127 = cn_double(s2013); __auto_type v = cn_init_2127;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2151 = cn_double(v30); __auto_type v = cn_init_2151;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2175 = cn_double(v29); __auto_type v = cn_init_2175;
(f[0]=(f[0]-v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_2222 = cn_double(v30); __auto_type v = cn_init_2222;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2246 = cn_double(s2012); __auto_type v = cn_init_2246;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_2293 = cn_double(v30); __auto_type v = cn_init_2293;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2317 = cn_double(s2012); __auto_type v = cn_init_2317;
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_8b71fb6924199361(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(33)); uint64_t r33 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_195;
__auto_type cn_init_208 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_208;
__auto_type cn_init_221 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_221;
__auto_type cn_init_234 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_234;
__auto_type cn_init_247 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,0); uint64_t v26 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,8); uint64_t v27 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,16); uint64_t v28 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,24); uint64_t v29 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,32); uint64_t v30 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,48); uint64_t v32 = cn_init_325;
__auto_type cn_init_338 = cn_cell(vm,56); uint64_t v33 = cn_init_338;
__auto_type cn_init_351 = cn_cell(vm,64); uint64_t v34 = cn_init_351;
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
(rg[3]=rg[0]);
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_638 = 0xffffffd0U; __auto_type bv = cn_init_638;
__auto_type cn_init_646 = rg[4]; __auto_type av = cn_init_646;
__auto_type cn_init_664 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_664;
(rg[4]=r);
}
{
__auto_type cn_init_690 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type v = cn_init_690;
__auto_type cn_init_697 = fl.cf; __auto_type cf = cn_init_697;
__auto_type cn_init_715 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_715;
(fl.cf=cf);
(r33=(((r33&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
(s2008=(((s2008&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[2])))&0xffffffffULL))<<32))));
(rg[0]=((uint32_t)(((((r33>>0))&0xffffffffULL)))));
{
__auto_type cn_init_804 = 0x3d07U; __auto_type bv = cn_init_804;
__auto_type cn_init_817 = cn_reg_get(rg,0,2); __auto_type av = cn_init_817;
__auto_type cn_init_835 = cn_alu(&fl,Alu_Sub,av,bv,2); __auto_type r = cn_init_835;
cn_reg_set(rg,0,2,r);
}
{
__auto_type cn_init_858 = rg[0]; __auto_type b = cn_init_858;
__auto_type cn_init_866 = rg[EAX]; __auto_type a = cn_init_866;
__auto_type cn_init_901 = ((false)?(({((uint64_t)(((((int64_t)(((int32_t)(a))))*((int64_t)(((int32_t)(b))))))));})):(({(((uint64_t)(a))*((uint64_t)(b)));}))); uint64_t r = cn_init_901;
(rg[EAX]=((uint32_t)(r)));
(rg[EDX]=((uint32_t)(((r>>32)))));
(fl.cf=((false)?(({((((int64_t)(r)))!=(((int64_t)(((int32_t)(((uint32_t)(r))))))));})):(({(((r>>32))!=0);}))));
(fl.of=fl.cf);
}
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
(rg[0]=((uint32_t)(((((v27>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1031 = (((uint32_t)(((((s2008>>0))&0xffffULL))))); __auto_type b = cn_init_1031;
__auto_type cn_init_1041 = (rg[EAX]&0xFFFF); __auto_type a = cn_init_1041;
__auto_type cn_init_1074 = ((false)?(({((uint32_t)(((((int32_t)(((int16_t)(((uint16_t)(a))))))*((int32_t)(((int16_t)(((uint16_t)(b))))))))));})):(({(a*b);}))); __auto_type r = cn_init_1074;
cn_reg_set(rg,0,2,r);
cn_reg_set(rg,2,2,(r>>16));
(fl.cf=((false)?(({((((int32_t)(r)))!=(((int32_t)(((int16_t)(((uint16_t)(r))))))));})):(({(((r>>16))!=0);}))));
(fl.of=fl.cf);
}
{
__auto_type cn_init_1151 = 0x3fffU; __auto_type bv = cn_init_1151;
__auto_type cn_init_1159 = rg[0]; __auto_type av = cn_init_1159;
__auto_type cn_init_1177 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1177;
(rg[0]=r);
}
(s2006=(((s2006&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
(rg[0]=((uint32_t)(((((v27>>0))&0xffffffffULL)))));
{
__auto_type cn_init_1250 = (((uint32_t)(((((s2008>>0))&0xffffULL))))); __auto_type b = cn_init_1250;
__auto_type cn_init_1260 = (rg[EAX]&0xFFFF); __auto_type a = cn_init_1260;
__auto_type cn_init_1293 = ((false)?(({((uint32_t)(((((int32_t)(((int16_t)(((uint16_t)(a))))))*((int32_t)(((int16_t)(((uint16_t)(b))))))))));})):(({(a*b);}))); __auto_type r = cn_init_1293;
cn_reg_set(rg,0,2,r);
cn_reg_set(rg,2,2,(r>>16));
(fl.cf=((false)?(({((((int32_t)(r)))!=(((int32_t)(((int16_t)(((uint16_t)(r))))))));})):(({(((r>>16))!=0);}))));
(fl.of=fl.cf);
}
{
__auto_type cn_init_1370 = 0x3fffU; __auto_type bv = cn_init_1370;
__auto_type cn_init_1378 = rg[0]; __auto_type av = cn_init_1378;
__auto_type cn_init_1396 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1396;
(rg[0]=r);
}
(s2007=(((s2007&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
(rg[0]=((uint32_t)(((((v26>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1469 = (((uint32_t)(((((s2008>>0))&0xffffULL))))); __auto_type b = cn_init_1469;
__auto_type cn_init_1479 = (rg[EAX]&0xFFFF); __auto_type a = cn_init_1479;
__auto_type cn_init_1512 = ((false)?(({((uint32_t)(((((int32_t)(((int16_t)(((uint16_t)(a))))))*((int32_t)(((int16_t)(((uint16_t)(b))))))))));})):(({(a*b);}))); __auto_type r = cn_init_1512;
cn_reg_set(rg,0,2,r);
cn_reg_set(rg,2,2,(r>>16));
(fl.cf=((false)?(({((((int32_t)(r)))!=(((int32_t)(((int16_t)(((uint16_t)(r))))))));})):(({(((r>>16))!=0);}))));
(fl.of=fl.cf);
}
{
__auto_type cn_init_1589 = 0x3fffU; __auto_type bv = cn_init_1589;
__auto_type cn_init_1597 = rg[0]; __auto_type av = cn_init_1597;
__auto_type cn_init_1615 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1615;
(rg[0]=r);
}
(s2007=(((s2007&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
(f[0]=cn_double(v30));
(f[0]=fabs(f[0]));
(f[1]=cn_double(v32));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b8;
}
{
__auto_type cn_init_1767 = 0x0U; __auto_type v = cn_init_1767;
cn_reg_set(rg,2,2,v);
}
(f[0]=(((double)(((int32_t)(((uint32_t)(((((s2006>>32))&0xffffffffULL))))))))));
{
__auto_type cn_init_1815 = cn_double(v33); __auto_type v = cn_init_1815;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1839 = cn_double(v34); __auto_type v = cn_init_1839;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_1863 = cn_double(v30); __auto_type v = cn_init_1863;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b3;
}
(f[1]=cn_double(v32));
(f[0]=(f[1]-f[0]));
{
__auto_type cn_init_1991 = 0x1U; __auto_type v = cn_init_1991;
cn_reg_set(rg,2,2,v);
}
goto cn_break_b5;
}
cn_break_b3:;
(f[1]=cn_double(0x3ff0000000000000));
(f[1]=-f[1]);
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b5;
}
(f[1]=cn_double(v32));
(f[0]=(f[0]+f[1]));
(f[0]=-f[0]);
{
__auto_type cn_init_2146 = 0x1U; __auto_type v = cn_init_2146;
cn_reg_set(rg,2,2,v);
}
}
cn_break_b5:;
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[2]-f[1]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_2233 = 0x0U; __auto_type bv = cn_init_2233;
__auto_type cn_init_2246 = cn_reg_get(rg,2,2); __auto_type av = cn_init_2246;
__auto_type cn_init_2264 = cn_alu(&fl,Alu_Cmp,av,bv,2); __auto_type r = cn_init_2264;
}
if(cn_cond(fl,4)){
goto cn_break_b7;
}
(f[1]=-f[1]);
}
cn_break_b7:;
(rg[2]=((uint32_t)(((((s2008>>32))&0xffffffffULL)))));
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[0]));
(f[3]=cn_double(r4));
(f[3]=(f[3]*f[1]));
(f[2]=(f[3]-f[2]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[1]));
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[0]));
(f[3]=(f[3]+f[4]));
(r3=cn_bits(f[3]));
(r4=cn_bits(f[2]));
(f[1]=f[1]);
(f[0]=f[0]);
(f[7]=f[7]);
(f=(CN_D8){f[7],f[0],f[1],f[2],f[3],f[4],f[5],f[6]});
}
cn_break_b8:;
(f[0]=cn_double(v29));
(f[0]=fabs(f[0]));
(f[1]=cn_double(v32));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
(f=(CN_D8){f[1],f[2],f[3],f[4],f[5],f[6],f[7],f[0]});
goto cn_break_b16;
}
{
__auto_type cn_init_2699 = 0x0U; __auto_type v = cn_init_2699;
cn_reg_set(rg,2,2,v);
}
(f[0]=(((double)(((int32_t)(((uint32_t)(((((s2007>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_2747 = cn_double(v33); __auto_type v = cn_init_2747;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2771 = cn_double(v34); __auto_type v = cn_init_2771;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2795 = cn_double(v29); __auto_type v = cn_init_2795;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b11;
}
(f[1]=cn_double(v32));
(f[0]=(f[1]-f[0]));
{
__auto_type cn_init_2923 = 0x1U; __auto_type v = cn_init_2923;
cn_reg_set(rg,2,2,v);
}
goto cn_break_b13;
}
cn_break_b11:;
(f[1]=cn_double(0x3ff0000000000000));
(f[1]=-f[1]);
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b13;
}
(f[1]=cn_double(v32));
(f[0]=(f[0]+f[1]));
(f[0]=-f[0]);
{
__auto_type cn_init_3078 = 0x1U; __auto_type v = cn_init_3078;
cn_reg_set(rg,2,2,v);
}
}
cn_break_b13:;
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[2]-f[1]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_3165 = 0x0U; __auto_type bv = cn_init_3165;
__auto_type cn_init_3178 = cn_reg_get(rg,2,2); __auto_type av = cn_init_3178;
__auto_type cn_init_3196 = cn_alu(&fl,Alu_Cmp,av,bv,2); __auto_type r = cn_init_3196;
}
if(cn_cond(fl,4)){
goto cn_break_b15;
}
(f[1]=-f[1]);
}
cn_break_b15:;
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[0]));
(f[3]=cn_double(r5));
(f[3]=(f[3]*f[1]));
(f[2]=(f[3]-f[2]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[1]));
(f[4]=cn_double(r5));
(f[4]=(f[4]*f[0]));
(f[3]=(f[3]+f[4]));
(r3=cn_bits(f[3]));
(r5=cn_bits(f[2]));
(f[1]=f[1]);
(f[0]=f[0]);
(f[7]=f[7]);
}
cn_break_b16:;
(f[7]=cn_double(v28));
(f[7]=fabs(f[7]));
(f[0]=cn_double(v32));
(fsw=cn_compare(f[0],f[7]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
(f=(CN_D8){f[1],f[2],f[3],f[4],f[5],f[6],f[7],f[0]});
goto cn_break_b24;
}
{
__auto_type cn_init_3570 = 0x0U; __auto_type v = cn_init_3570;
cn_reg_set(rg,2,2,v);
}
(f[7]=(((double)(((int32_t)(((uint32_t)(((((s2007>>32))&0xffffffffULL))))))))));
{
__auto_type cn_init_3618 = cn_double(v33); __auto_type v = cn_init_3618;
(f[7]=(f[7]*v));
}
{
__auto_type cn_init_3642 = cn_double(v34); __auto_type v = cn_init_3642;
(f[7]=(f[7]-v));
}
{
__auto_type cn_init_3666 = cn_double(v28); __auto_type v = cn_init_3666;
(f[7]=(f[7]*v));
}
(f[0]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[0],f[7]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b19;
}
(f[0]=cn_double(v32));
(f[7]=(f[0]-f[7]));
{
__auto_type cn_init_3794 = 0x1U; __auto_type v = cn_init_3794;
cn_reg_set(rg,2,2,v);
}
goto cn_break_b21;
}
cn_break_b19:;
(f[0]=cn_double(0x3ff0000000000000));
(f[0]=-f[0]);
(fsw=cn_compare(f[0],f[7]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b21;
}
(f[0]=cn_double(v32));
(f[7]=(f[7]+f[0]));
(f[7]=-f[7]);
{
__auto_type cn_init_3949 = 0x1U; __auto_type v = cn_init_3949;
cn_reg_set(rg,2,2,v);
}
}
cn_break_b21:;
(f[0]=f[7]);
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]-f[0]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_4036 = 0x0U; __auto_type bv = cn_init_4036;
__auto_type cn_init_4049 = cn_reg_get(rg,2,2); __auto_type av = cn_init_4049;
__auto_type cn_init_4067 = cn_alu(&fl,Alu_Cmp,av,bv,2); __auto_type r = cn_init_4067;
}
if(cn_cond(fl,4)){
goto cn_break_b23;
}
(f[0]=-f[0]);
}
cn_break_b23:;
(rg[2]=((uint32_t)(((((s2008>>32))&0xffffffffULL)))));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[7]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[0]));
(f[1]=(f[2]-f[1]));
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[0]));
(f[3]=cn_double(r5));
(f[3]=(f[3]*f[7]));
(f[2]=(f[2]+f[3]));
(r4=cn_bits(f[2]));
(r5=cn_bits(f[1]));
(f[0]=f[0]);
(f[7]=f[7]);
(f[6]=f[6]);
}
cn_break_b24:;
{
__auto_type cn_init_4306 = 0x30U; __auto_type bv = cn_init_4306;
__auto_type cn_init_4314 = rg[4]; __auto_type av = cn_init_4314;
__auto_type cn_init_4332 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_4332;
(rg[4]=r);
}
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
cn_wr64(m,CN_REC+8*(33),r33);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_8b87c96a4ce0746e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_237 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_237;
__auto_type cn_init_250 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_250;
__auto_type cn_init_263 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_263;
__auto_type cn_init_276 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_276;
__auto_type cn_init_289 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_289;
__auto_type cn_init_302 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_302;
__auto_type cn_init_315 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_315;
__auto_type cn_init_328 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_328;
__auto_type cn_init_341 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_341;
__auto_type cn_init_354 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_354;
__auto_type cn_init_367 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_367;
__auto_type cn_init_380 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_380;
__auto_type cn_init_393 = cn_cell(vm,0); uint64_t v30 = cn_init_393;
__auto_type cn_init_406 = cn_cell(vm,16); uint64_t v32 = cn_init_406;
__auto_type cn_init_419 = cn_cell(vm,24); uint64_t v33 = cn_init_419;
__auto_type cn_init_432 = cn_cell(vm,32); uint64_t v34 = cn_init_432;
__auto_type cn_init_445 = cn_cell(vm,40); uint64_t v35 = cn_init_445;
__auto_type cn_init_458 = cn_cell(vm,48); uint64_t v36 = cn_init_458;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_524 = 0xffffffc0U; __auto_type bv = cn_init_524;
__auto_type cn_init_532 = rg[4]; __auto_type av = cn_init_532;
__auto_type cn_init_550 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_550;
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
__auto_type cn_init_756 = cn_double(r3); __auto_type v = cn_init_756;
(f[0]=(f[0]*v));
}
(s2009=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_803 = cn_double(s2009); __auto_type v = cn_init_803;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_850 = cn_double(r4); __auto_type v = cn_init_850;
(f[0]=(f[0]*v));
}
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2008));
{
__auto_type cn_init_897 = cn_double(s2008); __auto_type v = cn_init_897;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_944 = cn_double(r5); __auto_type v = cn_init_944;
(f[0]=(f[0]*v));
}
(s2007=cn_bits(f[0]));
(f[0]=cn_double(s2007));
{
__auto_type cn_init_991 = cn_double(s2007); __auto_type v = cn_init_991;
(f[0]=(f[0]*v));
}
(s2011=cn_bits(f[0]));
(rg[7]=((uint32_t)(((((s2015>>32))&0xffffffffULL)))));
(f[0]=cn_double(r6));
(rg[7]=((uint32_t)(((((s2015>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1072 = cn_double(r6); __auto_type v = cn_init_1072;
(f[0]=(f[0]*v));
}
(s2006=cn_bits(f[0]));
(f[0]=cn_double(s2006));
{
__auto_type cn_init_1119 = cn_double(s2006); __auto_type v = cn_init_1119;
(f[0]=(f[0]*v));
}
(s2010=cn_bits(f[0]));
(f[0]=cn_double(v32));
{
__auto_type cn_init_1166 = cn_double(r3); __auto_type v = cn_init_1166;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1202 = cn_double(s2011); __auto_type v = cn_init_1202;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_1226 = cn_double(s2010); __auto_type v = cn_init_1226;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_1250 = cn_double(v35); __auto_type v = cn_init_1250;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2008));
{
__auto_type cn_init_1286 = cn_double(s2007); __auto_type v = cn_init_1286;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2007));
{
__auto_type cn_init_1322 = cn_double(s2006); __auto_type v = cn_init_1322;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2006));
{
__auto_type cn_init_1373 = cn_double(s2008); __auto_type v = cn_init_1373;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_1412 = cn_double(v36); __auto_type v = cn_init_1412;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[2]=cn_double(v34));
{
__auto_type cn_init_1463 = cn_double(s2009); __auto_type v = cn_init_1463;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2008));
{
__auto_type cn_init_1499 = cn_double(s2007); __auto_type v = cn_init_1499;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_1523 = cn_double(s2006); __auto_type v = cn_init_1523;
(f[3]=(f[3]+v));
}
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v33));
{
__auto_type cn_init_1589 = cn_double(s2013); __auto_type v = cn_init_1589;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
(rg[7]=rg[6]);
{
__auto_type cn_init_1648 = 0x18U; __auto_type bv = cn_init_1648;
__auto_type cn_init_1656 = rg[7]; __auto_type av = cn_init_1656;
__auto_type cn_init_1674 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1674;
(rg[7]=r);
}
{
__auto_type cn_init_1693 = cn_double(r10); __auto_type v = cn_init_1693;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(v32));
{
__auto_type cn_init_1740 = cn_double(r4); __auto_type v = cn_init_1740;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2011));
{
__auto_type cn_init_1776 = cn_double(s2010); __auto_type v = cn_init_1776;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_1800 = cn_double(s2013); __auto_type v = cn_init_1800;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_1824 = cn_double(v35); __auto_type v = cn_init_1824;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2007));
{
__auto_type cn_init_1860 = cn_double(s2006); __auto_type v = cn_init_1860;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2006));
{
__auto_type cn_init_1896 = cn_double(s2009); __auto_type v = cn_init_1896;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2009));
{
__auto_type cn_init_1947 = cn_double(s2007); __auto_type v = cn_init_1947;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_1986 = cn_double(v36); __auto_type v = cn_init_1986;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[2]=cn_double(v34));
{
__auto_type cn_init_2037 = cn_double(s2008); __auto_type v = cn_init_2037;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2007));
{
__auto_type cn_init_2073 = cn_double(s2006); __auto_type v = cn_init_2073;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_2097 = cn_double(s2009); __auto_type v = cn_init_2097;
(f[3]=(f[3]+v));
}
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v33));
{
__auto_type cn_init_2163 = cn_double(s2012); __auto_type v = cn_init_2163;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
(rg[0]=rg[6]);
(rg[7]=rg[0]);
{
__auto_type cn_init_2232 = 0x20U; __auto_type bv = cn_init_2232;
__auto_type cn_init_2240 = rg[7]; __auto_type av = cn_init_2240;
__auto_type cn_init_2258 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2258;
(rg[7]=r);
}
{
__auto_type cn_init_2277 = cn_double(r11); __auto_type v = cn_init_2277;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(v32));
{
__auto_type cn_init_2324 = cn_double(r5); __auto_type v = cn_init_2324;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2010));
{
__auto_type cn_init_2360 = cn_double(s2013); __auto_type v = cn_init_2360;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2384 = cn_double(s2012); __auto_type v = cn_init_2384;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2408 = cn_double(v35); __auto_type v = cn_init_2408;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2006));
{
__auto_type cn_init_2444 = cn_double(s2009); __auto_type v = cn_init_2444;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2009));
{
__auto_type cn_init_2480 = cn_double(s2008); __auto_type v = cn_init_2480;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2008));
{
__auto_type cn_init_2531 = cn_double(s2006); __auto_type v = cn_init_2531;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_2570 = cn_double(v36); __auto_type v = cn_init_2570;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[2]=cn_double(v34));
{
__auto_type cn_init_2621 = cn_double(s2007); __auto_type v = cn_init_2621;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2006));
{
__auto_type cn_init_2657 = cn_double(s2009); __auto_type v = cn_init_2657;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_2681 = cn_double(s2008); __auto_type v = cn_init_2681;
(f[3]=(f[3]+v));
}
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v33));
{
__auto_type cn_init_2747 = cn_double(s2011); __auto_type v = cn_init_2747;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
(rg[2]=rg[0]);
{
__auto_type cn_init_2806 = 0x28U; __auto_type bv = cn_init_2806;
__auto_type cn_init_2814 = rg[2]; __auto_type av = cn_init_2814;
__auto_type cn_init_2832 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2832;
(rg[2]=r);
}
{
__auto_type cn_init_2851 = cn_double(r12); __auto_type v = cn_init_2851;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
{
__auto_type cn_init_2881 = 0x38U; __auto_type bv = cn_init_2881;
__auto_type cn_init_2889 = rg[0]; __auto_type av = cn_init_2889;
__auto_type cn_init_2907 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_2907;
(rg[0]=r);
}
(f[0]=cn_double(r0));
(rg[0]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_2950 = 0x10U; __auto_type bv = cn_init_2950;
__auto_type cn_init_2958 = rg[0]; __auto_type av = cn_init_2958;
__auto_type cn_init_2976 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_2976;
(rg[0]=r);
}
{
__auto_type cn_init_2995 = cn_double(v30); __auto_type v = cn_init_2995;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(v32));
(rg[0]=((uint32_t)(((((s2015>>32))&0xffffffffULL)))));
{
__auto_type cn_init_3048 = cn_double(r6); __auto_type v = cn_init_3048;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2013));
{
__auto_type cn_init_3084 = cn_double(s2012); __auto_type v = cn_init_3084;
(f[2]=(f[2]+v));
}
{
__auto_type cn_init_3108 = cn_double(s2011); __auto_type v = cn_init_3108;
(f[2]=(f[2]+v));
}
{
__auto_type cn_init_3132 = cn_double(v35); __auto_type v = cn_init_3132;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2009));
{
__auto_type cn_init_3168 = cn_double(s2008); __auto_type v = cn_init_3168;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(s2008));
{
__auto_type cn_init_3204 = cn_double(s2007); __auto_type v = cn_init_3204;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(s2007));
{
__auto_type cn_init_3255 = cn_double(s2009); __auto_type v = cn_init_3255;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_3294 = cn_double(v36); __auto_type v = cn_init_3294;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]-f[3]));
(f[3]=cn_double(v34));
{
__auto_type cn_init_3345 = cn_double(s2006); __auto_type v = cn_init_3345;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(s2009));
{
__auto_type cn_init_3381 = cn_double(s2008); __auto_type v = cn_init_3381;
(f[4]=(f[4]+v));
}
{
__auto_type cn_init_3405 = cn_double(s2007); __auto_type v = cn_init_3405;
(f[4]=(f[4]+v));
}
(f[3]=(f[3]*f[4]));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(v33));
{
__auto_type cn_init_3471 = cn_double(s2010); __auto_type v = cn_init_3471;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]+f[1]));
(rg[0]=((uint32_t)(((((s2015>>32))&0xffffffffULL)))));
(r6=cn_bits(f[0]));
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
cn_wr64(m,CN_REC+8*(6),r6);
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
int cn_f_8b8b7877060a52b7(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_169 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_195;
__auto_type cn_init_208 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_208;
__auto_type cn_init_221 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_221;
__auto_type cn_init_234 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_234;
__auto_type cn_init_247 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,0); uint64_t v20 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,8); uint64_t v21 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,16); uint64_t v22 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,24); uint64_t v23 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,32); uint64_t v24 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,40); uint64_t v25 = cn_init_325;
__auto_type cn_init_338 = cn_cell(vm,48); uint64_t v26 = cn_init_338;
__auto_type cn_init_351 = cn_cell(vm,56); uint64_t v27 = cn_init_351;
__auto_type cn_init_364 = cn_cell(vm,64); uint64_t v28 = cn_init_364;
__auto_type cn_init_377 = cn_cell(vm,72); uint64_t v29 = cn_init_377;
__auto_type cn_init_390 = cn_cell(vm,80); uint64_t v30 = cn_init_390;
__auto_type cn_init_403 = cn_cell(vm,96); uint64_t v32 = cn_init_403;
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
__auto_type cn_init_487 = 0x30U; __auto_type bv = cn_init_487;
__auto_type cn_init_495 = rg[4]; __auto_type av = cn_init_495;
__auto_type cn_init_513 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_513;
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
(f[0]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
(f[0]=fabs(f[0]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))));
(f[0]=fabs(f[0]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_895 = 0x41U; __auto_type bv = cn_init_895;
__auto_type cn_init_908 = cn_reg_get(rg,4,1); __auto_type av = cn_init_908;
__auto_type cn_init_926 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_926;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
(f[0]=cn_double(r3));
(f[0]=fabs(f[0]));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(s2012=cn_bits(f[1]));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1052 = cn_double(s2013); __auto_type v = cn_init_1052;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(s2012=cn_bits(f[2]));
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(s2012));
{
__auto_type cn_init_1180 = cn_double(s2013); __auto_type v = cn_init_1180;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]/f[2]));
(f[2]=cn_double(r5));
(f[2]=fabs(f[2]));
(f[3]=f[2]);
(f[3]=(f[3]*f[3]));
(s2012=cn_bits(f[3]));
(f[2]=(f[2]*f[3]));
(f[3]=cn_double(s2012));
{
__auto_type cn_init_1308 = cn_double(s2013); __auto_type v = cn_init_1308;
(f[3]=(f[3]+v));
}
(f[2]=(f[2]/f[3]));
goto cn_break_b3;
}
cn_break_b2:;
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_1378 = cn_double(s2013); __auto_type v = cn_init_1378;
(f[0]=(f[0]+v));
}
(f[0]=sqrt(f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_1443 = cn_double(s2013); __auto_type v = cn_init_1443;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
{
__auto_type cn_init_1508 = cn_double(s2013); __auto_type v = cn_init_1508;
(f[2]=(f[2]+v));
}
(f[2]=sqrt(f[2]));
}
cn_break_b3:;
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_1652 = 0x41U; __auto_type bv = cn_init_1652;
__auto_type cn_init_1665 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1665;
__auto_type cn_init_1683 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1683;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b5;
}
(f[0]=cn_double(r3));
{
__auto_type cn_init_1732 = cn_double(r4); __auto_type v = cn_init_1732;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(s2012=cn_bits(f[2]));
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(s2012));
{
__auto_type cn_init_1843 = cn_double(s2011); __auto_type v = cn_init_1843;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]/f[2]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_1908 = cn_double(v32); __auto_type v = cn_init_1908;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1955 = cn_double(s2012); __auto_type v = cn_init_1955;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1991 = cn_double(s2012); __auto_type v = cn_init_1991;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_2049 = cn_double(r5); __auto_type v = cn_init_2049;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(s2012=cn_bits(f[2]));
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(s2012));
{
__auto_type cn_init_2160 = cn_double(s2011); __auto_type v = cn_init_2160;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]/f[2]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2225 = cn_double(v32); __auto_type v = cn_init_2225;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_2272 = cn_double(s2012); __auto_type v = cn_init_2272;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_2308 = cn_double(s2012); __auto_type v = cn_init_2308;
(f[1]=(f[1]+v));
}
(r5=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_2366 = cn_double(r5); __auto_type v = cn_init_2366;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[2]=f[1]);
(f[2]=(f[2]*f[2]));
(s2012=cn_bits(f[2]));
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(s2012));
{
__auto_type cn_init_2477 = cn_double(s2011); __auto_type v = cn_init_2477;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]/f[2]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2542 = cn_double(v32); __auto_type v = cn_init_2542;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_2589 = cn_double(s2012); __auto_type v = cn_init_2589;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_2625 = cn_double(s2012); __auto_type v = cn_init_2625;
(f[1]=(f[1]+v));
}
(r5=cn_bits(f[1]));
(r4=cn_bits(f[0]));
goto cn_break_b6;
}
cn_break_b5:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_2687 = cn_double(r4); __auto_type v = cn_init_2687;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_2736 = cn_double(s2011); __auto_type v = cn_init_2736;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2800 = cn_double(v32); __auto_type v = cn_init_2800;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_2847 = cn_double(s2012); __auto_type v = cn_init_2847;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_2883 = cn_double(s2012); __auto_type v = cn_init_2883;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_2941 = cn_double(r5); __auto_type v = cn_init_2941;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_2990 = cn_double(s2011); __auto_type v = cn_init_2990;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3054 = cn_double(v32); __auto_type v = cn_init_3054;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_3101 = cn_double(s2012); __auto_type v = cn_init_3101;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_3137 = cn_double(s2012); __auto_type v = cn_init_3137;
(f[1]=(f[1]+v));
}
(r5=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_3195 = cn_double(r5); __auto_type v = cn_init_3195;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_3244 = cn_double(s2011); __auto_type v = cn_init_3244;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3308 = cn_double(v32); __auto_type v = cn_init_3308;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_3355 = cn_double(s2012); __auto_type v = cn_init_3355;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_3391 = cn_double(s2012); __auto_type v = cn_init_3391;
(f[1]=(f[1]+v));
}
(r5=cn_bits(f[1]));
(r4=cn_bits(f[0]));
}
cn_break_b6:;
(f[0]=cn_double(r5));
(f[1]=cn_double(r3));
(f[2]=cn_double(r4));
(f[3]=f[1]);
{
__auto_type cn_init_3498 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3498;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_3546 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3546;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_3609 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3609;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_3672 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3672;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_3720 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3720;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_3783 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3783;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_3845 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3845;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_3892 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3892;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_3954 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3954;
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
__auto_type cn_init_4130 = cn_double(v29); __auto_type v = cn_init_4130;
(f[6]=(f[6]*v));
}
(f[1]=(f[1]-f[6]));
{
__auto_type cn_init_4169 = cn_double(v28); __auto_type v = cn_init_4169;
(f[5]=(f[5]*v));
}
(f[2]=(f[2]-f[5]));
(f[4]=(f[4]/f[3]));
{
__auto_type cn_init_4223 = cn_double(v27); __auto_type v = cn_init_4223;
(f[4]=(f[4]*v));
}
(f[0]=(f[0]-f[4]));
cn_swap(f,4,0);
(f[5]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
(f[6]=cn_double(0x0));
(fsw=cn_compare(f[6],f[5]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
{
__auto_type cn_init_4343 = 0x41U; __auto_type bv = cn_init_4343;
__auto_type cn_init_4356 = cn_reg_get(rg,4,1); __auto_type av = cn_init_4356;
__auto_type cn_init_4374 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_4374;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b8;
}
(f[4]=fabs(f[4]));
(f[5]=f[4]);
(f[5]=(f[5]*f[5]));
(s2012=cn_bits(f[5]));
(f[4]=(f[4]*f[5]));
(f[5]=cn_double(s2012));
{
__auto_type cn_init_4488 = cn_double(s2013); __auto_type v = cn_init_4488;
(f[5]=(f[5]+v));
}
(f[4]=(f[4]/f[5]));
goto cn_break_b9;
}
cn_break_b8:;
(f[4]=(f[4]*f[4]));
{
__auto_type cn_init_4546 = cn_double(s2013); __auto_type v = cn_init_4546;
(f[4]=(f[4]+v));
}
(f[4]=sqrt(f[4]));
}
cn_break_b9:;
(f[0]=(f[0]-f[4]));
(f[0]=(f[0]*f[3]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_8bd00246408e9517(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_333 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_333;
__auto_type cn_init_346 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_346;
__auto_type cn_init_359 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,0); uint64_t v25 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,8); uint64_t v26 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,16); uint64_t v27 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,24); uint64_t v28 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,32); uint64_t v29 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,40); uint64_t v30 = cn_init_437;
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
__auto_type cn_init_521 = 0x48U; __auto_type bv = cn_init_521;
__auto_type cn_init_529 = rg[4]; __auto_type av = cn_init_529;
__auto_type cn_init_547 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_547;
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
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(f[0]=cn_double(v28));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(v30));
{
__auto_type cn_init_786 = cn_double(v29); __auto_type v = cn_init_786;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(s2005=cn_bits(f[0]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_984 = cn_double(s2013); __auto_type v = cn_init_984;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1008 = cn_double(s2005); __auto_type v = cn_init_1008;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(s2008=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_1084 = cn_double(s2013); __auto_type v = cn_init_1084;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1108 = cn_double(s2005); __auto_type v = cn_init_1108;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(s2007=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_1184 = cn_double(s2013); __auto_type v = cn_init_1184;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1208 = cn_double(s2005); __auto_type v = cn_init_1208;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(s2006=cn_bits(f[1]));
(f[1]=cn_double(v30));
(f[2]=cn_double(s2008));
(f[2]=fabs(f[2]));
(f[1]*=log2(f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[3]=f[1]);
{
__auto_type cn_tuple_1340_0 = f[3];
__auto_type cn_tuple_1340_1 = f[2];
__auto_type x = cn_tuple_1340_0;
__auto_type y = cn_tuple_1340_1;
__auto_type cn_init_1369 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1369;
(f[3]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1401 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1401;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[3]=(exp2(f[3])-1.0));
(f[2]=(f[2]+f[3]));
(f[2]*=exp2(trunc(f[1])));
cn_swap(f,2,1);
(f[2]=f[2]);
(s2008=cn_bits(f[1]));
(f[1]=cn_double(v30));
(f[2]=cn_double(s2007));
(f[2]=fabs(f[2]));
(f[1]*=log2(f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[3]=f[1]);
{
__auto_type cn_tuple_1625_0 = f[3];
__auto_type cn_tuple_1625_1 = f[2];
__auto_type x = cn_tuple_1625_0;
__auto_type y = cn_tuple_1625_1;
__auto_type cn_init_1654 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1654;
(f[3]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1686 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1686;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[3]=(exp2(f[3])-1.0));
(f[2]=(f[2]+f[3]));
(f[2]*=exp2(trunc(f[1])));
cn_swap(f,2,1);
(f[2]=f[2]);
(s2007=cn_bits(f[1]));
(f[1]=cn_double(v30));
(f[2]=cn_double(s2006));
(f[2]=fabs(f[2]));
(f[1]*=log2(f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[3]=f[1]);
{
__auto_type cn_tuple_1910_0 = f[3];
__auto_type cn_tuple_1910_1 = f[2];
__auto_type x = cn_tuple_1910_0;
__auto_type y = cn_tuple_1910_1;
__auto_type cn_init_1939 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1939;
(f[3]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1971 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1971;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[3]=(exp2(f[3])-1.0));
(f[2]=(f[2]+f[3]));
(f[2]*=exp2(trunc(f[1])));
cn_swap(f,2,1);
(f[2]=f[2]);
(s2006=cn_bits(f[1]));
(f[1]=cn_double(r3));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2138 = cn_double(s2012); __auto_type v = cn_init_2138;
(f[1]=(f[1]*v));
}
(f[2]=f[0]);
cn_swap(f,2,1);
(f[1]=atan2(f[1],f[2]));
(s2011=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2236 = cn_double(s2012); __auto_type v = cn_init_2236;
(f[1]=(f[1]*v));
}
(f[2]=f[0]);
cn_swap(f,2,1);
(f[1]=atan2(f[1],f[2]));
(s2010=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2334 = cn_double(s2012); __auto_type v = cn_init_2334;
(f[1]=(f[1]*v));
}
(f[2]=f[0]);
cn_swap(f,2,1);
(f[1]=atan2(f[1],f[2]));
(s2009=cn_bits(f[1]));
(f[1]=cn_double(s2011));
{
__auto_type cn_init_2418 = cn_double(v29); __auto_type v = cn_init_2418;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2442 = cn_double(v27); __auto_type v = cn_init_2442;
(f[1]=(f[1]+v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_2485 = cn_double(s2008); __auto_type v = cn_init_2485;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r10));
{
__auto_type cn_init_2521 = cn_double(v27); __auto_type v = cn_init_2521;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(0x0));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_2589 = 0x41U; __auto_type bv = cn_init_2589;
__auto_type cn_init_2602 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2602;
__auto_type cn_init_2620 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2620;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
(f[1]=(f[1]+f[2]));
goto cn_break_b3;
}
cn_break_b2:;
(f[1]=(f[1]-f[2]));
}
cn_break_b3:;
(r3=cn_bits(f[1]));
(f[1]=cn_double(s2010));
{
__auto_type cn_init_2715 = cn_double(v29); __auto_type v = cn_init_2715;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2739 = cn_double(v27); __auto_type v = cn_init_2739;
(f[1]=(f[1]+v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_2782 = cn_double(s2007); __auto_type v = cn_init_2782;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r11));
{
__auto_type cn_init_2818 = cn_double(v26); __auto_type v = cn_init_2818;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(0x0));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_2886 = 0x41U; __auto_type bv = cn_init_2886;
__auto_type cn_init_2899 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2899;
__auto_type cn_init_2917 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2917;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b5;
}
(f[1]=(f[1]+f[2]));
goto cn_break_b6;
}
cn_break_b5:;
(f[1]=(f[1]-f[2]));
}
cn_break_b6:;
(r4=cn_bits(f[1]));
(f[1]=cn_double(s2009));
{
__auto_type cn_init_3012 = cn_double(v29); __auto_type v = cn_init_3012;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3036 = cn_double(v27); __auto_type v = cn_init_3036;
(f[1]=(f[1]+v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_3079 = cn_double(s2006); __auto_type v = cn_init_3079;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r12));
{
__auto_type cn_init_3115 = cn_double(v25); __auto_type v = cn_init_3115;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(0x0));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_3183 = 0x41U; __auto_type bv = cn_init_3183;
__auto_type cn_init_3196 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3196;
__auto_type cn_init_3214 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3214;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b8;
}
(f[1]=(f[1]+f[2]));
goto cn_break_b9;
}
cn_break_b8:;
(f[1]=(f[1]-f[2]));
}
cn_break_b9:;
(r5=cn_bits(f[1]));
(f[0]=f[0]);
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
int cn_f_8cca213c07130873(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+160))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_123;
__auto_type cn_init_136 = cn_cell(vm,0); uint64_t v20 = cn_init_136;
__auto_type cn_init_149 = cn_cell(vm,8); uint64_t v21 = cn_init_149;
__auto_type cn_init_162 = cn_cell(vm,16); uint64_t v22 = cn_init_162;
__auto_type cn_init_175 = cn_cell(vm,24); uint64_t v23 = cn_init_175;
__auto_type cn_init_188 = cn_cell(vm,32); uint64_t v24 = cn_init_188;
__auto_type cn_init_201 = cn_cell(vm,40); uint64_t v25 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,48); uint64_t v26 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,56); uint64_t v27 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,64); uint64_t v28 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,72); uint64_t v29 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,80); uint64_t v30 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,96); uint64_t v32 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,104); uint64_t v33 = cn_init_292;
{
{
{
(f[0]=cn_double(r5));
{
__auto_type cn_init_324 = cn_double(v28); __auto_type v = cn_init_324;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_360 = cn_double(v29); __auto_type v = cn_init_360;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_396 = cn_double(v30); __auto_type v = cn_init_396;
(f[2]=(f[2]+v));
}
(f[3]=f[2]);
{
__auto_type cn_init_444 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_444;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_492 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_492;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_555 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_555;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_618 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_618;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_666 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_666;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_729 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_729;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_791 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_791;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_838 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_838;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_900 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_900;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[3]=f[1]);
(f[4]=f[2]);
__auto_type cn_tuple_967_0 = f[3];
__auto_type cn_tuple_967_1 = f[4];
__auto_type pa32y = cn_tuple_967_0;
__auto_type pa32x = cn_tuple_967_1;
__auto_type cn_tuple_981_0 = atan2(pa32y,pa32x);
__auto_type cn_tuple_981_1 = atan2(pa32y,pa32x);
__auto_type pa32lo = cn_tuple_981_0;
__auto_type pa32hi = cn_tuple_981_1;
(f[3]=pa32lo);
__auto_type cn_init_1017 = ({__auto_type cn_init_1002 = cn_double(v22); __auto_type v = cn_init_1002; (f[3]=(v-f[3])); v;}); __auto_type c32_33 = cn_init_1017;
__auto_type cn_init_1046 = ({__auto_type cn_init_1031 = cn_double(v32); __auto_type v = cn_init_1031; (f[3]=(f[3]*v)); v;}); __auto_type c32_34 = cn_init_1046;
__auto_type cn_init_1086 = ({__auto_type cn_init_1071 = (((double)(((int32_t)(((uint32_t)(((((v23>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_1071; (f[3]=(f[3]*v)); v;}); __auto_type c32_35 = cn_init_1086;
{

__auto_type cn_init_1133 = cn_round(m,({__auto_type cn_arg=pa32lo; ({(cn_arg=(c32_33-cn_arg)); (cn_arg=(cn_arg*c32_34)); (cn_arg=(cn_arg*c32_35)); cn_arg;});})); __auto_type r1 = cn_init_1133;
__auto_type cn_init_1146 = cn_round(m,({__auto_type cn_arg=pa32hi; ({(cn_arg=(c32_33-cn_arg)); (cn_arg=(cn_arg*c32_34)); (cn_arg=(cn_arg*c32_35)); cn_arg;});})); __auto_type r2 = cn_init_1146;
(f[3]=((((r1==r2)&&(cn_bits(r1)==cn_bits(r2))))?(({r1;})):(({cn_round(m,({__auto_type cn_arg=atan2(pa32y,pa32x); ({(cn_arg=(c32_33-cn_arg)); (cn_arg=(cn_arg*c32_34)); (cn_arg=(cn_arg*c32_35)); cn_arg;});}));}))));
}
{
__auto_type cn_init_1195 = 0xfffffff0U; __auto_type bv = cn_init_1195;
__auto_type cn_init_1203 = rg[4]; __auto_type av = cn_init_1203;
__auto_type cn_init_1221 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1221;
(rg[4]=r);
}
{
__auto_type cn_init_1243 = cn_round(m,f[3]); __auto_type x = cn_init_1243;
__auto_type cn_init_1278 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_1278;
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
(rg[2]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1345 = (((double)(((int32_t)(((uint32_t)(((((v23>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_1345;
(f[3]=(f[3]/v));
}
{
__auto_type cn_init_1369 = cn_double(v33); __auto_type v = cn_init_1369;
(f[3]=(f[3]*v));
}
{
__auto_type cn_tuple_1400_0 = sin(f[3]);
__auto_type cn_tuple_1400_1 = cos(f[3]);
__auto_type s = cn_tuple_1400_0;
__auto_type c = cn_tuple_1400_1;
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
__auto_type cn_init_1491 = 0x1U; __auto_type bv = cn_init_1491;
__auto_type cn_init_1499 = rg[2]; __auto_type av = cn_init_1499;
__auto_type cn_init_1517 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1517;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
(f[5]=-f[5]);
}
cn_break_b2:;
{
__auto_type cn_init_1555 = 0x10U; __auto_type bv = cn_init_1555;
__auto_type cn_init_1563 = rg[4]; __auto_type av = cn_init_1563;
__auto_type cn_init_1581 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1581;
(rg[4]=r);
}
(r4=cn_bits(f[5]));
(f[5]=f[2]);
(f[5]=(f[5]*f[4]));
(f[6]=f[1]);
(f[6]=(f[6]*f[3]));
(f[5]=(f[5]-f[6]));
(r3=cn_bits(f[5]));
(f[4]=f[4]);
(f[3]=f[3]);
(f[2]=f[2]);
(f[1]=f[1]);
(r5=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(r3));
(f[2]=f[0]);
(f[3]=f[1]);
__auto_type cn_tuple_1790_0 = f[2];
__auto_type cn_tuple_1790_1 = f[3];
__auto_type pa74y = cn_tuple_1790_0;
__auto_type pa74x = cn_tuple_1790_1;
__auto_type cn_tuple_1804_0 = atan2(pa74y,pa74x);
__auto_type cn_tuple_1804_1 = atan2(pa74y,pa74x);
__auto_type pa74lo = cn_tuple_1804_0;
__auto_type pa74hi = cn_tuple_1804_1;
(f[2]=pa74lo);
__auto_type cn_init_1856 = ({__auto_type cn_init_1841 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1841; (f[2]=(v-f[2])); v;}); __auto_type c74_75 = cn_init_1856;
__auto_type cn_init_1885 = ({__auto_type cn_init_1870 = cn_double(v32); __auto_type v = cn_init_1870; (f[2]=(f[2]*v)); v;}); __auto_type c74_76 = cn_init_1885;
__auto_type cn_init_1925 = ({__auto_type cn_init_1910 = (((double)(((int32_t)(((uint32_t)(((((v21>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_1910; (f[2]=(f[2]*v)); v;}); __auto_type c74_77 = cn_init_1925;
{

__auto_type cn_init_1972 = cn_round(m,({__auto_type cn_arg=pa74lo; ({(cn_arg=(c74_75-cn_arg)); (cn_arg=(cn_arg*c74_76)); (cn_arg=(cn_arg*c74_77)); cn_arg;});})); __auto_type r1 = cn_init_1972;
__auto_type cn_init_1985 = cn_round(m,({__auto_type cn_arg=pa74hi; ({(cn_arg=(c74_75-cn_arg)); (cn_arg=(cn_arg*c74_76)); (cn_arg=(cn_arg*c74_77)); cn_arg;});})); __auto_type r2 = cn_init_1985;
(f[2]=((((r1==r2)&&(cn_bits(r1)==cn_bits(r2))))?(({r1;})):(({cn_round(m,({__auto_type cn_arg=atan2(pa74y,pa74x); ({(cn_arg=(c74_75-cn_arg)); (cn_arg=(cn_arg*c74_76)); (cn_arg=(cn_arg*c74_77)); cn_arg;});}));}))));
}
{
__auto_type cn_init_2034 = 0xfffffff0U; __auto_type bv = cn_init_2034;
__auto_type cn_init_2042 = rg[4]; __auto_type av = cn_init_2042;
__auto_type cn_init_2060 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2060;
(rg[4]=r);
}
{
__auto_type cn_init_2082 = cn_round(m,f[2]); __auto_type x = cn_init_2082;
__auto_type cn_init_2117 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2117;
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
(rg[2]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2184 = (((double)(((int32_t)(((uint32_t)(((((v21>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_2184;
(f[2]=(f[2]/v));
}
{
__auto_type cn_init_2208 = cn_double(v33); __auto_type v = cn_init_2208;
(f[2]=(f[2]*v));
}
{
__auto_type cn_tuple_2239_0 = sin(f[2]);
__auto_type cn_tuple_2239_1 = cos(f[2]);
__auto_type s = cn_tuple_2239_0;
__auto_type c = cn_tuple_2239_1;
(f[2]=s);
(f[3]=c);
(fsw&=~0x0400);
}
(f[4]=f[0]);
(f[4]=(f[4]*f[3]));
(f[5]=f[1]);
(f[5]=(f[5]*f[2]));
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_2330 = 0x1U; __auto_type bv = cn_init_2330;
__auto_type cn_init_2338 = rg[2]; __auto_type av = cn_init_2338;
__auto_type cn_init_2356 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2356;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
(f[4]=-f[4]);
}
cn_break_b4:;
{
__auto_type cn_init_2394 = 0x10U; __auto_type bv = cn_init_2394;
__auto_type cn_init_2402 = rg[4]; __auto_type av = cn_init_2402;
__auto_type cn_init_2420 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2420;
(rg[4]=r);
}
(r5=cn_bits(f[4]));
(f[4]=f[1]);
(f[4]=(f[4]*f[3]));
(f[5]=f[0]);
(f[5]=(f[5]*f[2]));
(f[4]=(f[4]-f[5]));
(r3=cn_bits(f[4]));
(f[3]=f[3]);
(f[2]=f[2]);
(f[1]=f[1]);
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10007ee8U,s2013);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_8de1df051871edbb(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_160 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_160;
__auto_type cn_init_173 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_173;
__auto_type cn_init_186 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_186;
__auto_type cn_init_199 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_199;
__auto_type cn_init_212 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_212;
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
(f[1]=cn_double(r5));
{
__auto_type cn_init_507 = cn_double(r4); __auto_type v = cn_init_507;
(f[1]=(f[1]*v));
}
(f[1]=(f[1]+f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
{
__auto_type cn_init_600 = cn_double(r3); __auto_type v = cn_init_600;
(f[2]=(f[2]*v));
}
(f[2]=(f[2]+f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=-f[1]);
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[2]=-f[2]);
(f[3]=cn_double(r4));
{
__auto_type cn_init_715 = cn_double(r3); __auto_type v = cn_init_715;
(f[3]=(f[3]*v));
}
(f[3]=(f[3]+f[3]));
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_769 = cn_double(r12); __auto_type v = cn_init_769;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_804 = cn_double(r11); __auto_type v = cn_init_804;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_839 = cn_double(r10); __auto_type v = cn_init_839;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
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
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_8e1d3abf1bb89335(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+176))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_123;
__auto_type cn_init_136 = cn_cell(vm,0); uint64_t v22 = cn_init_136;
__auto_type cn_init_149 = cn_cell(vm,8); uint64_t v23 = cn_init_149;
__auto_type cn_init_162 = cn_cell(vm,16); uint64_t v24 = cn_init_162;
__auto_type cn_init_175 = cn_cell(vm,24); uint64_t v25 = cn_init_175;
__auto_type cn_init_188 = cn_cell(vm,32); uint64_t v26 = cn_init_188;
__auto_type cn_init_201 = cn_cell(vm,40); uint64_t v27 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,48); uint64_t v28 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,56); uint64_t v29 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,64); uint64_t v30 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,80); uint64_t v32 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,88); uint64_t v33 = cn_init_266;
{
{
(f[0]=cn_double(r5));
{
__auto_type cn_init_295 = cn_double(v28); __auto_type v = cn_init_295;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_331 = cn_double(v29); __auto_type v = cn_init_331;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_367 = cn_double(v30); __auto_type v = cn_init_367;
(f[2]=(f[2]+v));
}
(f[3]=f[2]);
{
__auto_type cn_init_415 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_415;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_463 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_463;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_526 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_526;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_589 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_589;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_637 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_637;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_700 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_700;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_762 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_762;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_809 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_809;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_871 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_871;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[3]=f[1]);
(f[4]=f[2]);
__auto_type cn_tuple_938_0 = f[3];
__auto_type cn_tuple_938_1 = f[4];
__auto_type pa32y = cn_tuple_938_0;
__auto_type pa32x = cn_tuple_938_1;
__auto_type cn_tuple_952_0 = atan2(pa32y,pa32x);
__auto_type cn_tuple_952_1 = atan2(pa32y,pa32x);
__auto_type pa32lo = cn_tuple_952_0;
__auto_type pa32hi = cn_tuple_952_1;
(f[3]=pa32lo);
__auto_type cn_init_988 = ({__auto_type cn_init_973 = cn_double(v22); __auto_type v = cn_init_973; (f[3]=(v-f[3])); v;}); __auto_type c32_33 = cn_init_988;
__auto_type cn_init_1017 = ({__auto_type cn_init_1002 = cn_double(v32); __auto_type v = cn_init_1002; (f[3]=(f[3]*v)); v;}); __auto_type c32_34 = cn_init_1017;
__auto_type cn_init_1057 = ({__auto_type cn_init_1042 = (((double)(((int32_t)(((uint32_t)(((((v23>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_1042; (f[3]=(f[3]*v)); v;}); __auto_type c32_35 = cn_init_1057;
{

__auto_type cn_init_1104 = cn_round(m,({__auto_type cn_arg=pa32lo; ({(cn_arg=(c32_33-cn_arg)); (cn_arg=(cn_arg*c32_34)); (cn_arg=(cn_arg*c32_35)); cn_arg;});})); __auto_type r1 = cn_init_1104;
__auto_type cn_init_1117 = cn_round(m,({__auto_type cn_arg=pa32hi; ({(cn_arg=(c32_33-cn_arg)); (cn_arg=(cn_arg*c32_34)); (cn_arg=(cn_arg*c32_35)); cn_arg;});})); __auto_type r2 = cn_init_1117;
(f[3]=((((r1==r2)&&(cn_bits(r1)==cn_bits(r2))))?(({r1;})):(({cn_round(m,({__auto_type cn_arg=atan2(pa32y,pa32x); ({(cn_arg=(c32_33-cn_arg)); (cn_arg=(cn_arg*c32_34)); (cn_arg=(cn_arg*c32_35)); cn_arg;});}));}))));
}
{
__auto_type cn_init_1166 = 0xfffffff0U; __auto_type bv = cn_init_1166;
__auto_type cn_init_1174 = rg[4]; __auto_type av = cn_init_1174;
__auto_type cn_init_1192 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1192;
(rg[4]=r);
}
{
__auto_type cn_init_1214 = cn_round(m,f[3]); __auto_type x = cn_init_1214;
__auto_type cn_init_1249 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_1249;
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
(rg[2]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1316 = (((double)(((int32_t)(((uint32_t)(((((v23>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_1316;
(f[3]=(f[3]/v));
}
{
__auto_type cn_init_1340 = cn_double(v33); __auto_type v = cn_init_1340;
(f[3]=(f[3]*v));
}
{
__auto_type cn_tuple_1371_0 = sin(f[3]);
__auto_type cn_tuple_1371_1 = cos(f[3]);
__auto_type s = cn_tuple_1371_0;
__auto_type c = cn_tuple_1371_1;
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
__auto_type cn_init_1462 = 0x1U; __auto_type bv = cn_init_1462;
__auto_type cn_init_1470 = rg[2]; __auto_type av = cn_init_1470;
__auto_type cn_init_1488 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1488;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
(f[5]=-f[5]);
}
cn_break_b2:;
{
__auto_type cn_init_1526 = 0x10U; __auto_type bv = cn_init_1526;
__auto_type cn_init_1534 = rg[4]; __auto_type av = cn_init_1534;
__auto_type cn_init_1552 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1552;
(rg[4]=r);
}
(r4=cn_bits(f[5]));
(f[5]=f[2]);
(f[5]=(f[5]*f[4]));
(f[6]=f[1]);
(f[6]=(f[6]*f[3]));
(f[5]=(f[5]-f[6]));
(r3=cn_bits(f[5]));
(f[4]=f[4]);
(f[3]=f[3]);
(f[2]=f[2]);
(f[1]=f[1]);
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10007ee8U,s2013);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_8e4e8be2b0066d00(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_175 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,0); uint64_t v18 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,8); uint64_t v19 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,16); uint64_t v20 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,24); uint64_t v21 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,32); uint64_t v22 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,40); uint64_t v23 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,48); uint64_t v24 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,56); uint64_t v25 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,64); uint64_t v26 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,72); uint64_t v27 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,80); uint64_t v28 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,88); uint64_t v29 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,96); uint64_t v30 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,112); uint64_t v32 = cn_init_396;
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
__auto_type cn_init_438 = 0xffffffb0U; __auto_type bv = cn_init_438;
__auto_type cn_init_446 = rg[4]; __auto_type av = cn_init_446;
__auto_type cn_init_464 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_464;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_493 = r5; uint64_t s = cn_init_493;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_523 = (CN_U2){v28,v29}; CN_U2 s = cn_init_523;
__auto_type cn_init_533 = m->xmm[0]; __auto_type a = cn_init_533;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_603 = v28; uint64_t s = cn_init_603;
__auto_type cn_init_616 = m->xmm[1][0]; __auto_type a = cn_init_616;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_663 = (CN_U2){v24,v25}; CN_U2 s = cn_init_663;
__auto_type cn_init_673 = m->xmm[0]; __auto_type a = cn_init_673;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_743 = v26; uint64_t s = cn_init_743;
__auto_type cn_init_756 = m->xmm[1][0]; __auto_type a = cn_init_756;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_793 = 0x0U; __auto_type bv = cn_init_793;
__auto_type cn_init_810 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_810;
__auto_type cn_init_828 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_828;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_849 = r32; uint64_t s = cn_init_849;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_871 = v28; uint64_t s = cn_init_871;
__auto_type cn_init_884 = m->xmm[5][0]; __auto_type a = cn_init_884;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_980 = m->xmm[0][0]; uint64_t v = cn_init_980;
(s2005=(((s2005&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2006=(((s2006&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1039 = m->xmm[0][1]; uint64_t v = cn_init_1039;
(s2006=(((s2006&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2007=(((s2007&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1098 = m->xmm[1][0]; uint64_t v = cn_init_1098;
(s2007=(((s2007&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2008=(((s2008&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1147 = 0xffffffd4U; __auto_type bv = cn_init_1147;
__auto_type cn_init_1155 = rg[7]; __auto_type av = cn_init_1155;
__auto_type cn_init_1173 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1173;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1300 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1300;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1348 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1348;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1411 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1411;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1474 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1474;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1522 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1522;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1585 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1585;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1647 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1647;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1694 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1694;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1756 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1756;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1799 = cn_bits(f[2]); uint64_t v = cn_init_1799;
(s2005=(((s2005&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2006=(((s2006&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1857 = cn_bits(f[1]); uint64_t v = cn_init_1857;
(s2006=(((s2006&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2007=(((s2007&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1915 = cn_bits(f[0]); uint64_t v = cn_init_1915;
(s2007=(((s2007&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2008=(((s2008&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1964 = 0x2cU; __auto_type bv = cn_init_1964;
__auto_type cn_init_1972 = rg[7]; __auto_type av = cn_init_1972;
__auto_type cn_init_1990 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1990;
(rg[7]=r);
}
{
__auto_type cn_init_2016 = (((uint32_t)(((((s2006>>24))&0xffULL))))); __auto_type v = cn_init_2016;
cn_reg_set(rg,2,1,v);
}
(f[0]=cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))));
(f[0]=fabs(f[0]));
(f[1]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2106 = 0x0U; __auto_type bv = cn_init_2106;
__auto_type cn_init_2123 = (((uint32_t)(((((v23>>0))&0xffffffffULL))))); __auto_type av = cn_init_2123;
__auto_type cn_init_2141 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2141;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
{
__auto_type cn_init_2160 = 0x80U; __auto_type bv = cn_init_2160;
__auto_type cn_init_2173 = cn_reg_get(rg,2,1); __auto_type av = cn_init_2173;
__auto_type cn_init_2191 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_2191;
cn_reg_set(rg,2,1,r);
}
}
cn_break_b4:;
{
__auto_type cn_init_2212 = 0x80U; __auto_type bv = cn_init_2212;
__auto_type cn_init_2225 = cn_reg_get(rg,2,1); __auto_type av = cn_init_2225;
__auto_type cn_init_2243 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2243;
cn_reg_set(rg,2,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
{
__auto_type cn_init_2280 = cn_double(v32); __auto_type v = cn_init_2280;
(f[1]=(f[1]+v));
}
goto cn_break_b7;
}
cn_break_b6:;
{
__auto_type cn_init_2308 = cn_double(v32); __auto_type v = cn_init_2308;
(f[1]=(f[1]-v));
}
}
cn_break_b7:;
(f[1]=fabs(f[1]));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
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
__auto_type cn_init_2442 = cn_double(v32); __auto_type v = cn_init_2442;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=cn_round(m,f[1]));
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_2501 = 0x0U; __auto_type bv = cn_init_2501;
__auto_type cn_init_2518 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_2518;
__auto_type cn_init_2536 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2536;
}
if(cn_cond(fl,4)){
goto cn_break_b15;
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
(f[1]=fabs(f[1]));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b13;
}
(f[0]=f[1]);
goto cn_break_b14;
}
cn_break_b13:;
(f[1]=f[1]);
}
cn_break_b14:;
goto cn_break_b16;
}
cn_break_b15:;
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
}
cn_break_b16:;
{
__auto_type cn_init_2803 = cn_double(v30); __auto_type v = cn_init_2803;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2822 = 0x0U; __auto_type bv = cn_init_2822;
__auto_type cn_init_2839 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_2839;
__auto_type cn_init_2857 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2857;
}
if(cn_cond(fl,5)){
goto cn_break_b18;
}
{
__auto_type cn_init_2881 = cn_double(v28); __auto_type v = cn_init_2881;
(f[0]=(f[0]/v));
}
}
cn_break_b18:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2912 = 0x50U; __auto_type bv = cn_init_2912;
__auto_type cn_init_2920 = rg[4]; __auto_type av = cn_init_2920;
__auto_type cn_init_2938 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2938;
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
int cn_f_8e56fc6ffe930349(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_195;
__auto_type cn_init_208 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,0); uint64_t v26 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,8); uint64_t v27 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,16); uint64_t v28 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,24); uint64_t v29 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,32); uint64_t v30 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,48); uint64_t v32 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,56); uint64_t v33 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,64); uint64_t v34 = cn_init_312;
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
{
__auto_type cn_init_636 = cn_double(v30); __auto_type v = cn_init_636;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_683 = cn_double(v29); __auto_type v = cn_init_683;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_730 = cn_double(v28); __auto_type v = cn_init_730;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
{
__auto_type cn_init_777 = cn_double(v27); __auto_type v = cn_init_777;
(f[0]=(f[0]+v));
}
(r6=cn_bits(f[0]));
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
(f[2]=cn_double(v33));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b5;
}
(f[1]=cn_double(r3));
(fsw=cn_compare(f[1],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_1070 = 0x50U; __auto_type bv = cn_init_1070;
__auto_type cn_init_1083 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1083;
__auto_type cn_init_1101 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1101;
cn_reg_set(rg,4,1,r);
}
{
__auto_type cn_init_1130 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1130;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
(f[1]=f[1]);
if(cn_cond(fl,5)){
goto cn_break_b3;
}
(f[1]=f[0]);
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[1]=fabs(f[1]));
(f[2]=cn_double(v33));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b5;
}
}
cn_break_b3:;
(f[1]=f[0]);
(f[1]=-f[1]);
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r3));
cn_swap(f,2,1);
(f[1]=atan2(f[1],f[2]));
(f[2]=f[0]);
(f[3]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
(f[3]=-f[3]);
cn_swap(f,3,2);
(f[2]=atan2(f[2],f[3]));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_1559 = cn_double(v32); __auto_type v = cn_init_1559;
(f[1]=(f[1]*v));
}
(f[2]=f[0]);
(f[3]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]+f[3]));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[3]=f[0]);
(f[3]=-f[3]);
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[3]+f[4]));
(f[3]=(f[3]*f[3]));
(f[4]=cn_double(r3));
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]/f[3]));
(f[3]=cn_double(0x3fe62e42fefa39ef));
cn_swap(f,3,2);
(f[2]*=log2(f[3]));
{
__auto_type cn_init_1832 = cn_double(v34); __auto_type v = cn_init_1832;
(f[2]=(f[2]*v));
}
(f[2]=(f[2]/f[0]));
(f[3]=f[1]);
{
__auto_type cn_init_1881 = cn_double(v26); __auto_type v = cn_init_1881;
(f[3]=(f[3]*v));
}
(r3=cn_bits(f[3]));
(f[3]=cn_double(r4));
{
__auto_type cn_init_1928 = cn_double(v26); __auto_type v = cn_init_1928;
(f[3]=(f[3]*v));
}
(f[3]=(f[3]*f[2]));
(r4=cn_bits(f[3]));
(f[3]=cn_double(r5));
{
__auto_type cn_init_1990 = cn_double(v26); __auto_type v = cn_init_1990;
(f[3]=(f[3]*v));
}
(f[3]=(f[3]*f[2]));
(r5=cn_bits(f[3]));
(f[3]=cn_double(r6));
{
__auto_type cn_init_2052 = cn_double(v26); __auto_type v = cn_init_2052;
(f[3]=(f[3]*v));
}
(f[3]=(f[3]*f[2]));
(r6=cn_bits(f[3]));
(f[2]=f[2]);
(f[1]=f[1]);
(f[0]=f[0]);
(f[7]=f[7]);
(f=(CN_D8){f[7],f[0],f[1],f[2],f[3],f[4],f[5],f[6]});
goto cn_break_b4;
}
cn_break_b5:;
(f[0]=f[0]);
(f[0]=cn_double(r3));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=atan2(f[0],f[1]));
(r3=cn_bits(f[0]));
}
cn_break_b4:;
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
int cn_f_8ec11a48c046b175(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+200))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_190;
__auto_type cn_init_207 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_207;
__auto_type cn_init_224 = cn_rd64(m,CN_REC+8*(32)); uint64_t r32 = cn_init_224;
__auto_type cn_init_241 = cn_rd64(m,CN_REC+8*(33)); uint64_t r33 = cn_init_241;
__auto_type cn_init_254 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_254;
__auto_type cn_init_267 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_267;
__auto_type cn_init_280 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_280;
__auto_type cn_init_293 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_293;
__auto_type cn_init_306 = cn_cell(vm,0); uint64_t v25 = cn_init_306;
__auto_type cn_init_319 = cn_cell(vm,8); uint64_t v26 = cn_init_319;
__auto_type cn_init_332 = cn_cell(vm,16); uint64_t v27 = cn_init_332;
__auto_type cn_init_345 = cn_cell(vm,24); uint64_t v28 = cn_init_345;
__auto_type cn_init_358 = cn_cell(vm,32); uint64_t v29 = cn_init_358;
__auto_type cn_init_371 = cn_cell(vm,40); uint64_t v30 = cn_init_371;
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
(rg[7]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_652 = 0x80U; __auto_type bv = cn_init_652;
__auto_type cn_init_660 = rg[7]; __auto_type av = cn_init_660;
__auto_type cn_init_678 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_678;
(rg[7]=r);
}
{
__auto_type cn_init_692 = 0x0U; __auto_type bv = cn_init_692;
__auto_type cn_init_709 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type av = cn_init_709;
__auto_type cn_init_727 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_727;
}
if(cn_cond(fl,15)){
goto cn_break_b2;
}
{
__auto_type cn_init_758 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type v = cn_init_758;
__auto_type cn_init_765 = fl.cf; __auto_type cf = cn_init_765;
__auto_type cn_init_783 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_783;
(fl.cf=cf);
(r33=(((r33&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
(f[0]=cn_double(v30));
(r32=cn_bits(f[0]));
}
cn_break_b2:;
(f[0]=cn_double(r32));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_917 = cn_double(v26); __auto_type v = cn_init_917;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r32=cn_bits(f[0]));
(f[0]=cn_double(v27));
(f[1]=f[0]);
(f[2]=f[1]);
(f[0]=(f[0]+f[2]));
(f[2]=-f[2]);
(f[3]=cn_double(r3));
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
(f[3]=-f[3]);
(f[3]=(f[3]+f[0]));
goto cn_break_b6;
}
cn_break_b4:;
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b6;
}
(f[3]=-f[3]);
(f[3]=(f[3]-f[0]));
}
cn_break_b6:;
(f[4]=cn_double(r4));
(fsw=cn_compare(f[4],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b8;
}
(f[4]=-f[4]);
(f[4]=(f[4]+f[0]));
goto cn_break_b10;
}
cn_break_b8:;
(fsw=cn_compare(f[4],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b10;
}
(f[4]=-f[4]);
(f[4]=(f[4]-f[0]));
}
cn_break_b10:;
(f[5]=cn_double(r5));
(fsw=cn_compare(f[5],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b12;
}
(f[5]=-f[5]);
(f[5]=(f[5]+f[0]));
goto cn_break_b14;
}
cn_break_b12:;
(fsw=cn_compare(f[5],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b14;
}
(f[5]=-f[5]);
(f[5]=(f[5]-f[0]));
}
cn_break_b14:;
cn_swap(f,5,2);
(f[5]=f[5]);
cn_swap(f,4,1);
(f[4]=f[4]);
cn_swap(f,3,0);
(f[3]=f[3]);
(f[3]=f[2]);
(f[3]=(f[3]*f[2]));
(f[4]=f[1]);
(f[4]=(f[4]*f[1]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[0]));
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(v25));
cn_swap(f,4,3);
(f[5]=cn_double(0x3fe62e42fefa39ef));
cn_swap(f,5,4);
(f[4]*=log2(f[5]));
cn_swap(f,4,3);
(f[3]=(f[3]*f[4]));
(f[4]=cn_double(0x3ff71547652b82fe));
(f[3]=(f[3]*f[4]));
(f[4]=f[3]);
(f[4]=cn_round(m,f[4]));
(f[3]=(f[3]-f[4]));
cn_swap(f,4,3);
(f[4]=(exp2(f[4])-1.0));
(f[5]=cn_double(0x3ff0000000000000));
(f[4]=(f[4]+f[5]));
(f[4]*=exp2(trunc(f[3])));
(f[3]=f[4]);
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
__auto_type cn_init_2231 = cn_double(r32); __auto_type v = cn_init_2231;
(f[3]=(v/f[3]));
}
goto cn_break_b19;
}
cn_break_b18:;
(fsw=cn_compare(f[4],f[3]));
(f[3]=cn_double(r32));
}
cn_break_b19:;
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[3]));
(r6=cn_bits(f[4]));
(f[0]=(f[0]*f[3]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
{
__auto_type cn_init_2370 = cn_double(r12); __auto_type v = cn_init_2370;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_2405 = cn_double(r11); __auto_type v = cn_init_2405;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_2440 = cn_double(r10); __auto_type v = cn_init_2440;
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
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_8f3653401b1e95a6(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
{
__auto_type cn_init_418 = cn_double(v30); __auto_type v = cn_init_418;
(f[2]=(f[2]+v));
}
(r3=cn_bits(f[2]));
{
__auto_type cn_init_453 = cn_double(v29); __auto_type v = cn_init_453;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_488 = cn_double(v28); __auto_type v = cn_init_488;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r3));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r4));
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r3));
{
__auto_type cn_init_727 = cn_double(r5); __auto_type v = cn_init_727;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_751 = cn_double(r4); __auto_type v = cn_init_751;
(f[1]=(f[1]*v));
}
cn_swap(f,1,0);
(f[1]=(f[1]-f[0]));
(f[1]=(f[1]-f[0]));
cn_swap(f,1,0);
(f[0]=(f[1]-f[0]));
(f[0]=-f[0]);
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r4));
(f[3]=cn_double(r5));
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]-f[2]));
(f[1]=(f[1]/f[0]));
{
__auto_type cn_init_945 = cn_double(v27); __auto_type v = cn_init_945;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_969 = cn_double(v30); __auto_type v = cn_init_969;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(r3));
(f[4]=cn_double(r5));
(f[3]=(f[3]*f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=(f[2]/f[0]));
{
__auto_type cn_init_1089 = cn_double(v27); __auto_type v = cn_init_1089;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1113 = cn_double(v29); __auto_type v = cn_init_1113;
(f[2]=(f[2]-v));
}
(f[3]=cn_double(r5));
(f[3]=(f[3]*f[3]));
(f[4]=cn_double(r3));
(f[5]=cn_double(r4));
(f[4]=(f[4]*f[5]));
(f[3]=(f[3]-f[4]));
(f[0]=(f[3]/f[0]));
{
__auto_type cn_init_1233 = cn_double(v27); __auto_type v = cn_init_1233;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1257 = cn_double(v28); __auto_type v = cn_init_1257;
(f[2]=(f[2]-v));
}
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
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_8f5d0319bab0a995(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+240))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_178;
__auto_type cn_init_191 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_191;
__auto_type cn_init_204 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_204;
__auto_type cn_init_217 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_217;
__auto_type cn_init_230 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_230;
__auto_type cn_init_243 = cn_cell(vm,0); uint64_t v30 = cn_init_243;
__auto_type cn_init_256 = cn_cell(vm,16); uint64_t v32 = cn_init_256;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_322 = 0x30U; __auto_type bv = cn_init_322;
__auto_type cn_init_330 = rg[4]; __auto_type av = cn_init_330;
__auto_type cn_init_348 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_348;
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
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(s2012=cn_bits(f[0]));
(f[1]=cn_double(v30));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(v30));
{
__auto_type cn_init_743 = cn_double(r5); __auto_type v = cn_init_743;
(f[1]=(f[1]*v));
}
(f[1]=(f[1]+f[1]));
(f[1]=(f[1]*f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(f[0]=sqrt(f[0]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(s2012));
(f[1]=cn_double(v30));
(f[1]=(f[1]*f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v30));
{
__auto_type cn_init_939 = cn_double(r5); __auto_type v = cn_init_939;
(f[1]=(f[1]*v));
}
(f[1]=(f[1]+f[1]));
(s2010=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[1]=cn_double(r3));
(f[0]=atan2(f[0],f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(s2011));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2012));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]-f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(s2012));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1166 = cn_double(v32); __auto_type v = cn_init_1166;
(f[0]=(v-f[0]));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_1213 = cn_double(s2011); __auto_type v = cn_init_1213;
(f[0]=(f[0]/v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(0x3ff71547652b82fe));
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
(r4=cn_bits(f[0]));
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
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_8ff344f00b5b64dd(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
{
__auto_type cn_init_418 = cn_double(v30); __auto_type v = cn_init_418;
(f[2]=(f[2]+v));
}
(r3=cn_bits(f[2]));
{
__auto_type cn_init_453 = cn_double(v29); __auto_type v = cn_init_453;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_488 = cn_double(v28); __auto_type v = cn_init_488;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r3));
(f[1]=(f[0]/f[1]));
(f[2]=cn_double(v27));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_688 = cn_double(v30); __auto_type v = cn_init_688;
(f[1]=(f[1]-v));
}
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]/f[0]));
(f[2]=cn_double(v27));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_777 = cn_double(v29); __auto_type v = cn_init_777;
(f[1]=(f[1]-v));
}
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
cn_swap(f,1,0);
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(v27));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_875 = cn_double(v28); __auto_type v = cn_init_875;
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
int cn_f_8ff930dbacf31149(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_224 = cn_rd64(m,CN_REC+8*(33)); uint64_t r33 = cn_init_224;
__auto_type cn_init_237 = cn_rd64u(m,0x10007e90U); uint64_t s2002 = cn_init_237;
__auto_type cn_init_250 = cn_rd64u(m,0x10007e98U); uint64_t s2003 = cn_init_250;
__auto_type cn_init_263 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_263;
__auto_type cn_init_276 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_276;
__auto_type cn_init_289 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_289;
__auto_type cn_init_302 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_302;
__auto_type cn_init_315 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_315;
__auto_type cn_init_328 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_328;
__auto_type cn_init_341 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_341;
__auto_type cn_init_354 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_354;
__auto_type cn_init_367 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_367;
__auto_type cn_init_380 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_380;
__auto_type cn_init_393 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_393;
__auto_type cn_init_406 = cn_cell(vm,0); uint64_t v22 = cn_init_406;
__auto_type cn_init_419 = cn_cell(vm,8); uint64_t v23 = cn_init_419;
__auto_type cn_init_432 = cn_cell(vm,16); uint64_t v24 = cn_init_432;
__auto_type cn_init_445 = cn_cell(vm,24); uint64_t v25 = cn_init_445;
__auto_type cn_init_458 = cn_cell(vm,32); uint64_t v26 = cn_init_458;
__auto_type cn_init_471 = cn_cell(vm,40); uint64_t v27 = cn_init_471;
__auto_type cn_init_484 = cn_cell(vm,48); uint64_t v28 = cn_init_484;
__auto_type cn_init_497 = cn_cell(vm,56); uint64_t v29 = cn_init_497;
__auto_type cn_init_510 = cn_cell(vm,64); uint64_t v30 = cn_init_510;
{
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_582 = 0x50U; __auto_type bv = cn_init_582;
__auto_type cn_init_590 = rg[4]; __auto_type av = cn_init_590;
__auto_type cn_init_608 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_608;
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
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
{
__auto_type cn_init_807 = 0x80U; __auto_type bv = cn_init_807;
__auto_type cn_init_815 = rg[6]; __auto_type av = cn_init_815;
__auto_type cn_init_833 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_833;
(rg[6]=r);
}
{
__auto_type cn_init_847 = 0x0U; __auto_type bv = cn_init_847;
__auto_type cn_init_864 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type av = cn_init_864;
__auto_type cn_init_882 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_882;
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
{
__auto_type cn_init_913 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type v = cn_init_913;
__auto_type cn_init_920 = fl.cf; __auto_type cf = cn_init_920;
__auto_type cn_init_938 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_938;
(fl.cf=cf);
(r33=(((r33&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
{
__auto_type cn_init_991 = m->xmm[0]; CN_U2 s = cn_init_991;
__auto_type cn_init_1001 = m->xmm[0]; __auto_type a = cn_init_1001;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_1048 = m->xmm[1]; CN_U2 s = cn_init_1048;
__auto_type cn_init_1058 = m->xmm[1]; __auto_type a = cn_init_1058;
(m->xmm[1]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
goto cn_break_b3;
}
cn_break_b2:;
{
__auto_type cn_init_1098 = 0x80U; __auto_type bv = cn_init_1098;
__auto_type cn_init_1106 = rg[6]; __auto_type av = cn_init_1106;
__auto_type cn_init_1124 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_1124;
(rg[6]=r);
}
(s2007=m->xmm[0][0]);
(s2008=m->xmm[0][1]);
(s2005=m->xmm[1][0]);
(s2006=m->xmm[1][1]);
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(v30));
cn_swap(f,1,0);
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_1396_0 = f[2];
__auto_type cn_tuple_1396_1 = f[1];
__auto_type x = cn_tuple_1396_0;
__auto_type y = cn_tuple_1396_1;
__auto_type cn_init_1425 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1425;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1457 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1457;
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
__auto_type cn_init_1640 = cn_double(v30); __auto_type v = cn_init_1640;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1670_0 = sin(f[0]);
__auto_type cn_tuple_1670_1 = cos(f[0]);
__auto_type s = cn_tuple_1670_0;
__auto_type c = cn_tuple_1670_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2012=cn_bits(f[1]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1836 = cn_double(v30); __auto_type v = cn_init_1836;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1866_0 = sin(f[0]);
__auto_type cn_tuple_1866_1 = cos(f[0]);
__auto_type s = cn_tuple_1866_0;
__auto_type c = cn_tuple_1866_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2010=cn_bits(f[1]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(v28));
(f[1]=cn_double(s2006));
(f[1]=(f[1]*f[0]));
(f[2]=cn_double(s2008));
(f[2]=(f[2]*f[0]));
(f[3]=cn_double(s2007));
(f[3]=(f[3]*f[0]));
(f[4]=f[3]);
{
__auto_type cn_init_2036 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2036;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_2084 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2084;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_2147 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2147;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[3]);
{
__auto_type cn_init_2210 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2210;
(f[5]=(f[5]*v));
}
(f[6]=f[2]);
{
__auto_type cn_init_2258 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2258;
(f[6]=(f[6]*v));
}
(f[5]=(f[5]+f[6]));
(f[6]=f[1]);
{
__auto_type cn_init_2321 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2321;
(f[6]=(f[6]*v));
}
(f[5]=(f[5]+f[6]));
cn_swap(f,5,3);
{
__auto_type cn_init_2383 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2383;
(f[5]=(f[5]*v));
}
cn_swap(f,5,2);
{
__auto_type cn_init_2430 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2430;
(f[5]=(f[5]*v));
}
(f[2]=(f[2]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_2492 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2492;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
{
__auto_type cn_init_2531 = cn_double(r10); __auto_type v = cn_init_2531;
(f[3]=(f[3]+v));
}
(s2008=cn_bits(f[3]));
{
__auto_type cn_init_2566 = cn_double(r11); __auto_type v = cn_init_2566;
(f[2]=(f[2]+v));
}
(s2007=cn_bits(f[2]));
{
__auto_type cn_init_2601 = cn_double(r12); __auto_type v = cn_init_2601;
(f[1]=(f[1]+v));
}
(s2006=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(v27));
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[0]));
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[0]));
(f[3]=cn_double(r5));
(f[3]=(f[3]*f[0]));
{
__auto_type cn_init_2739 = cn_double(s2006); __auto_type v = cn_init_2739;
(f[3]=(f[3]+v));
}
(s2006=cn_bits(f[3]));
{
__auto_type cn_init_2774 = cn_double(s2007); __auto_type v = cn_init_2774;
(f[2]=(f[2]+v));
}
(s2007=cn_bits(f[2]));
{
__auto_type cn_init_2809 = cn_double(s2008); __auto_type v = cn_init_2809;
(f[1]=(f[1]+v));
}
(s2008=cn_bits(f[1]));
(f[0]=f[0]);
(m->xmm[0]=(CN_U2){r3,r4});
(m->xmm[1]=(CN_U2){r5,r6});
(f[0]=cn_double(s2012));
{
__auto_type cn_init_2892 = cn_double(s2010); __auto_type v = cn_init_2892;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2916 = cn_double(s2009); __auto_type v = cn_init_2916;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2940 = cn_double(s2008); __auto_type v = cn_init_2940;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_2987 = cn_double(s2010); __auto_type v = cn_init_2987;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3011 = cn_double(s2009); __auto_type v = cn_init_3011;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3035 = cn_double(s2007); __auto_type v = cn_init_3035;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2011));
{
__auto_type cn_init_3082 = cn_double(s2009); __auto_type v = cn_init_3082;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3106 = cn_double(v29); __auto_type v = cn_init_3106;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3130 = cn_double(s2006); __auto_type v = cn_init_3130;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
}
cn_break_b3:;
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
cn_wr64(m,CN_REC+8*(33),r33);
cn_wr64u(m,0x10007e90U,s2002);
cn_wr64u(m,0x10007e98U,s2003);
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
int cn_f_90df87328b904240(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
{
__auto_type cn_init_431 = cn_double(v30); __auto_type v = cn_init_431;
(f[2]=(f[2]+v));
}
(r3=cn_bits(f[2]));
{
__auto_type cn_init_466 = cn_double(v29); __auto_type v = cn_init_466;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_501 = cn_double(v28); __auto_type v = cn_init_501;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=-f[0]);
{
__auto_type cn_init_616 = cn_double(v26); __auto_type v = cn_init_616;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(r3));
(f[1]=fabs(f[1]));
(f[1]=(f[1]/f[0]));
(f[2]=cn_double(v27));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_779 = cn_double(v30); __auto_type v = cn_init_779;
(f[1]=(f[1]-v));
}
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
(f[1]=(f[1]/f[0]));
(f[2]=cn_double(v27));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_882 = cn_double(v29); __auto_type v = cn_init_882;
(f[1]=(f[1]-v));
}
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[1]=fabs(f[1]));
cn_swap(f,1,0);
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(v27));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_994 = cn_double(v28); __auto_type v = cn_init_994;
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
int cn_f_918ee1cb611eb1eb(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(14)); uint64_t r14 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_229;
__auto_type cn_init_242 = cn_cell(vm,0); uint64_t v30 = cn_init_242;
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
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<0))));
}
(rg[7]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(f[0]=cn_double(r3));
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=f[1]);
(f[3]=fabs(f[3]));
(f[4]=f[2]);
(f[4]=fabs(f[4]));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_556 = 0x41U; __auto_type bv = cn_init_556;
__auto_type cn_init_569 = cn_reg_get(rg,4,1); __auto_type av = cn_init_569;
__auto_type cn_init_587 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_587;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
cn_swap(f,2,1);
}
cn_break_b2:;
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_swap(f,2,0);
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
(f[2]=-f[2]);
}
cn_break_b4:;
(f[3]=f[1]);
(f[3]=(f[3]*f[3]));
{
__auto_type cn_init_750 = cn_double(r14); __auto_type v = cn_init_750;
(f[3]=(f[3]/v));
}
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[4]-f[3]));
(f[4]=f[2]);
(f[4]=(f[4]*f[4]));
(f[5]=f[0]);
(f[5]=(f[5]*f[5]));
(f[6]=f[4]);
(f[6]=(f[6]-f[5]));
(f[6]=(f[6]*f[3]));
{
__auto_type cn_init_891 = cn_double(r10); __auto_type v = cn_init_891;
(f[6]=(f[6]+v));
}
(r3=cn_bits(f[6]));
(f[4]=(f[4]+f[5]));
(f[4]=sqrt(f[4]));
(f[1]=(f[1]*f[4]));
(f[2]=(f[2]*f[3]));
(f[0]=(f[0]*f[2]));
(f[1]=(f[1]+f[1]));
(r5=cn_bits(f[1]));
(rg[3]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=(f[0]+f[0]));
{
__auto_type cn_init_1058 = cn_double(v30); __auto_type v = cn_init_1058;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1082 = cn_double(r11); __auto_type v = cn_init_1082;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
{
(rg[3]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
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
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_926e64601c08618d(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_160 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_160;
__auto_type cn_init_173 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_173;
__auto_type cn_init_186 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_186;
__auto_type cn_init_199 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_199;
__auto_type cn_init_212 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_212;
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
(f[1]=cn_double(r5));
{
__auto_type cn_init_507 = cn_double(r4); __auto_type v = cn_init_507;
(f[1]=(f[1]*v));
}
(f[1]=(f[1]+f[1]));
(f[0]=(f[0]-f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r4));
{
__auto_type cn_init_600 = cn_double(r3); __auto_type v = cn_init_600;
(f[2]=(f[2]*v));
}
(f[2]=(f[2]+f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(r5));
{
__auto_type cn_init_693 = cn_double(r3); __auto_type v = cn_init_693;
(f[3]=(f[3]*v));
}
(f[3]=(f[3]+f[3]));
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_747 = cn_double(r12); __auto_type v = cn_init_747;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_782 = cn_double(r11); __auto_type v = cn_init_782;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_817 = cn_double(r10); __auto_type v = cn_init_817;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
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
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_939f180fc0184ac7(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+240))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_178;
__auto_type cn_init_191 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_191;
__auto_type cn_init_204 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_204;
__auto_type cn_init_217 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_217;
__auto_type cn_init_230 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_230;
__auto_type cn_init_243 = cn_cell(vm,0); uint64_t v30 = cn_init_243;
{
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_315 = 0x30U; __auto_type bv = cn_init_315;
__auto_type cn_init_323 = rg[4]; __auto_type av = cn_init_323;
__auto_type cn_init_341 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_341;
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
(f[0]=cn_double(r4));
(f[0]=(f[0]*f[0]));
(s2013=cn_bits(f[0]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(s2012=cn_bits(f[1]));
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_680 = 0x41U; __auto_type bv = cn_init_680;
__auto_type cn_init_693 = cn_reg_get(rg,4,1); __auto_type av = cn_init_693;
__auto_type cn_init_711 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_711;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,14)){
goto cn_break_b2;
}
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
}
cn_break_b2:;
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_840 = cn_double(s2012); __auto_type v = cn_init_840;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_950 = 0x41U; __auto_type bv = cn_init_950;
__auto_type cn_init_963 = cn_reg_get(rg,4,1); __auto_type av = cn_init_963;
__auto_type cn_init_981 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_981;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,14)){
goto cn_break_b4;
}
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
}
cn_break_b4:;
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1087 = cn_double(v30); __auto_type v = cn_init_1087;
(f[0]=(f[0]*v));
}
(f[1]=f[0]);
{
__auto_type cn_init_1121 = cn_double(s2011); __auto_type v = cn_init_1121;
(f[1]=(f[1]*v));
}
(s2011=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1179 = cn_double(s2012); __auto_type v = cn_init_1179;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1215 = cn_double(s2011); __auto_type v = cn_init_1215;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_1251 = cn_double(s2011); __auto_type v = cn_init_1251;
(f[2]=(f[2]*v));
}
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
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
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_940073ec6f9c15c4(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+184))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_195;
__auto_type cn_init_208 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_208;
__auto_type cn_init_221 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_221;
__auto_type cn_init_234 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,0); uint64_t v23 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,8); uint64_t v24 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,24); uint64_t v26 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,40); uint64_t v28 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,48); uint64_t v29 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,56); uint64_t v30 = cn_init_312;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_378 = 0x30U; __auto_type bv = cn_init_378;
__auto_type cn_init_386 = rg[4]; __auto_type av = cn_init_386;
__auto_type cn_init_404 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_404;
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
(f[0]=fabs(f[0]));
{
__auto_type cn_init_634 = cn_double(v30); __auto_type v = cn_init_634;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r3));
(f[1]=fabs(f[1]));
(f[1]=-f[1]);
{
__auto_type cn_init_695 = cn_double(v28); __auto_type v = cn_init_695;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_734 = cn_double(v29); __auto_type v = cn_init_734;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r10));
(f[0]=fabs(f[0]));
(f[1]=cn_double(r10));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_821 = cn_double(v24); __auto_type v = cn_init_821;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_860 = cn_double(v23); __auto_type v = cn_init_860;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_978 = cn_double(v26); __auto_type v = cn_init_978;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1002 = cn_double(s2013); __auto_type v = cn_init_1002;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1026 = cn_double(s2012); __auto_type v = cn_init_1026;
(f[0]=(f[0]+v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_1061 = cn_double(r3); __auto_type v = cn_init_1061;
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
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_949be805d5860fdb(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[3]=-f[3]);
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b2;
}
cn_swap(f,3,2);
}
cn_break_b2:;
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
cn_swap(f,3,1);
}
cn_break_b4:;
(f[3]=-f[3]);
cn_swap(f,3,2);
(f[3]=-f[3]);
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b6;
}
cn_swap(f,3,1);
}
cn_break_b6:;
(f[3]=-f[3]);
cn_swap(f,3,2);
(f[3]=-f[3]);
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b8;
}
cn_swap(f,3,0);
}
cn_break_b8:;
(f[3]=-f[3]);
cn_swap(f,3,2);
(f[3]=-f[3]);
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b10;
}
cn_swap(f,3,0);
}
cn_break_b10:;
(f[3]=-f[3]);
cn_swap(f,3,2);
cn_swap(f,3,1);
(f[3]=-f[3]);
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b12;
}
cn_swap(f,3,0);
}
cn_break_b12:;
(f[3]=-f[3]);
cn_swap(f,3,1);
{
__auto_type cn_init_1355 = 0x28U; __auto_type bv = cn_init_1355;
__auto_type cn_init_1363 = rg[7]; __auto_type av = cn_init_1363;
__auto_type cn_init_1381 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_1381;
(rg[7]=r);
}
(f[4]=f[3]);
{
__auto_type cn_init_1424 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1424;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1472 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1472;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1535 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1535;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1598 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1598;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r3=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_1672 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1672;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1720 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1720;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1783 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1783;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1846 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1846;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r4=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_1920 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1920;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1968 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1968;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_2031 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2031;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2094 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2094;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r5=cn_bits(f[4]));
{
__auto_type cn_init_2158 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2158;
(f[3]=(f[3]*v));
}
cn_swap(f,3,2);
{
__auto_type cn_init_2205 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2205;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
cn_swap(f,2,1);
{
__auto_type cn_init_2267 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2267;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
cn_swap(f,1,0);
{
__auto_type cn_init_2329 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2329;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r6=cn_bits(f[0]));
{
__auto_type cn_init_2374 = 0x28U; __auto_type bv = cn_init_2374;
__auto_type cn_init_2382 = rg[7]; __auto_type av = cn_init_2382;
__auto_type cn_init_2400 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2400;
(rg[7]=r);
}
(f[0]=cn_double(r6));
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[4]=cn_double(v30));
(f[5]=f[4]);
{
__auto_type cn_init_2489 = cn_double(r36); __auto_type v = cn_init_2489;
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
int cn_f_9587f8a4b59b2a57(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+200))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_272 = cn_cell(vm,0); uint64_t v25 = cn_init_272;
__auto_type cn_init_285 = cn_cell(vm,8); uint64_t v26 = cn_init_285;
__auto_type cn_init_298 = cn_cell(vm,16); uint64_t v27 = cn_init_298;
__auto_type cn_init_311 = cn_cell(vm,24); uint64_t v28 = cn_init_311;
__auto_type cn_init_324 = cn_cell(vm,32); uint64_t v29 = cn_init_324;
__auto_type cn_init_337 = cn_cell(vm,40); uint64_t v30 = cn_init_337;
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
(rg[3]=rg[0]);
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
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
(f[2]=cn_double(r4));
(f[3]=f[2]);
(f[3]=(f[3]-f[0]));
(f[3]=fabs(f[3]));
(f[3]=(f[3]+f[2]));
cn_swap(f,3,2);
(f[3]=(f[3]+f[0]));
(f[3]=fabs(f[3]));
(f[2]=(f[3]-f[2]));
(f[3]=cn_double(v26));
cn_swap(f,3,0);
(f[3]=f[3]);
(f[3]=cn_double(r5));
(f[4]=f[3]);
(f[4]=(f[4]-f[0]));
(f[4]=fabs(f[4]));
(f[4]=(f[4]+f[3]));
cn_swap(f,4,3);
(f[4]=(f[4]+f[0]));
(f[4]=fabs(f[4]));
(f[3]=(f[4]-f[3]));
(f[4]=f[3]);
(f[4]=fabs(f[4]));
(fsw=cn_compare(f[4],cn_double(v25)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b2;
}
{
__auto_type cn_init_1104 = cn_double(v25); __auto_type v = cn_init_1104;
(f[4]=(f[4]-v));
}
(f[4]=(f[4]*f[4]));
(f[5]=f[2]);
(f[5]=(f[5]*f[2]));
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
(f[5]=(f[5]*f[1]));
(f[4]=(f[4]+f[5]));
goto cn_break_b3;
}
cn_break_b2:;
(f[4]=f[4]);
(f[4]=f[2]);
(f[4]=(f[4]*f[2]));
(f[5]=f[1]);
(f[5]=(f[5]*f[1]));
(f[4]=(f[4]+f[5]));
}
cn_break_b3:;
(fsw=cn_compare(f[4],cn_double(v28)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b5;
}
(f[4]=f[4]);
(f[4]=cn_double(v29));
goto cn_break_b8;
}
cn_break_b5:;
(f[5]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[5],f[4]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b7;
}
(f[5]=f[5]);
{
__auto_type cn_init_1493 = cn_double(v30); __auto_type v = cn_init_1493;
(f[4]=(v/f[4]));
}
goto cn_break_b8;
}
cn_break_b7:;
(fsw=cn_compare(f[5],f[4]));
(f[4]=cn_double(v30));
}
cn_break_b8:;
(f[5]=cn_double(r6));
(f[5]=(f[5]*f[4]));
(r6=cn_bits(f[5]));
(f[1]=(f[1]*f[4]));
(f[2]=(f[2]*f[4]));
(f[3]=(f[3]*f[4]));
{
__auto_type cn_init_1632 = cn_double(r12); __auto_type v = cn_init_1632;
(f[3]=(f[3]+v));
}
(r5=cn_bits(f[3]));
{
__auto_type cn_init_1667 = cn_double(r11); __auto_type v = cn_init_1667;
(f[2]=(f[2]+v));
}
(r4=cn_bits(f[2]));
{
__auto_type cn_init_1702 = cn_double(r10); __auto_type v = cn_init_1702;
(f[1]=(f[1]+v));
}
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_9691cdfd20659ad0(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+200))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_190;
__auto_type cn_init_207 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_207;
__auto_type cn_init_220 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_220;
__auto_type cn_init_233 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_233;
__auto_type cn_init_246 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_246;
__auto_type cn_init_259 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_259;
__auto_type cn_init_272 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_272;
__auto_type cn_init_285 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_285;
__auto_type cn_init_298 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_298;
__auto_type cn_init_311 = cn_cell(vm,0); uint64_t v25 = cn_init_311;
__auto_type cn_init_324 = cn_cell(vm,8); uint64_t v26 = cn_init_324;
__auto_type cn_init_337 = cn_cell(vm,16); uint64_t v27 = cn_init_337;
__auto_type cn_init_350 = cn_cell(vm,24); uint64_t v28 = cn_init_350;
__auto_type cn_init_363 = cn_cell(vm,32); uint64_t v29 = cn_init_363;
__auto_type cn_init_376 = cn_cell(vm,40); uint64_t v30 = cn_init_376;
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
{
__auto_type cn_init_592 = 0xffffffe8U; __auto_type bv = cn_init_592;
__auto_type cn_init_600 = rg[4]; __auto_type av = cn_init_600;
__auto_type cn_init_618 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_618;
(rg[4]=r);
}
(rg[7]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
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
__auto_type cn_init_816 = cn_bits(f[1]); uint64_t v = cn_init_816;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
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
__auto_type cn_init_993 = cn_bits(f[2]); uint64_t v = cn_init_993;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
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
__auto_type cn_init_1170 = cn_bits(f[3]); uint64_t v = cn_init_1170;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(rg[0]=rg[4]);
(rg[1]=rg[4]);
(rg[2]=((uint32_t)(((((v26>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1337 = cn_map_px(true,((int32_t)(rg[EDX])),(CN_D3){cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))),cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))),cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL)))}); __auto_type r = cn_init_1337;
{
__auto_type cn_init_1352 = cn_bits(r[0]); uint64_t v = cn_init_1352;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1410 = cn_bits(r[1]); uint64_t v = cn_init_1410;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1468 = cn_bits(r[2]); uint64_t v = cn_init_1468;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
}
(f[4]=(((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))));
(f[5]=(((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))));
(f[6]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[6]=(f[6]+f[4]));
(f[6]=(f[6]*f[5]));
(f[6]=(f[6]+f[1]));
(f[6]=(f[6]*f[6]));
(f[7]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[7]=(f[7]+f[4]));
(f[7]=(f[7]*f[5]));
(f[7]=(f[7]+f[2]));
(f[7]=(f[7]*f[7]));
(f[6]=(f[6]+f[7]));
(f[7]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[7]=(f[7]+f[4]));
(f[7]=(f[7]*f[5]));
(f[7]=(f[7]+f[3]));
(f[7]=(f[7]*f[7]));
(f[6]=(f[6]+f[7]));
(fsw=cn_compare(f[6],cn_double(v28)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
(f[6]=f[6]);
(f[6]=cn_double(v29));
goto cn_break_b5;
}
cn_break_b2:;
(f[7]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[7],f[6]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
(f[7]=f[7]);
{
__auto_type cn_init_2059 = cn_double(v30); __auto_type v = cn_init_2059;
(f[6]=(v/f[6]));
}
goto cn_break_b5;
}
cn_break_b4:;
(fsw=cn_compare(f[7],f[6]));
(f[6]=cn_double(v30));
}
cn_break_b5:;
(f[7]=cn_double(r6));
(f[7]=(f[7]*f[6]));
(r6=cn_bits(f[7]));
(f[1]=(f[1]*f[6]));
(f[2]=(f[2]*f[6]));
(f[3]=(f[3]*f[6]));
(fsw=cn_compare(f[5],f[4]));
{
__auto_type cn_init_2213 = cn_double(r12); __auto_type v = cn_init_2213;
(f[3]=(f[3]+v));
}
(r5=cn_bits(f[3]));
{
__auto_type cn_init_2248 = cn_double(r11); __auto_type v = cn_init_2248;
(f[2]=(f[2]+v));
}
(r4=cn_bits(f[2]));
{
__auto_type cn_init_2283 = cn_double(r10); __auto_type v = cn_init_2283;
(f[1]=(f[1]+v));
}
(r3=cn_bits(f[1]));
(f[0]=f[0]);
(rg[0]=rg[3]);
{
__auto_type cn_init_2333 = 0x18U; __auto_type bv = cn_init_2333;
__auto_type cn_init_2341 = rg[4]; __auto_type av = cn_init_2341;
__auto_type cn_init_2359 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2359;
(rg[4]=r);
}
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
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_98525f800bf1d30d(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+168))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001008U); uint64_t r1 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,0); uint64_t v21 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,8); uint64_t v22 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,16); uint64_t v23 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,24); uint64_t v24 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,32); uint64_t v25 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,40); uint64_t v26 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,48); uint64_t v27 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,56); uint64_t v28 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,64); uint64_t v29 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,72); uint64_t v30 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,80); uint64_t v31 = cn_init_357;
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2015=(((s2015&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[1])))&0xffffffffULL))<<0))));
}
{
__auto_type cn_init_416 = 0xffffffe0U; __auto_type bv = cn_init_416;
__auto_type cn_init_424 = rg[4]; __auto_type av = cn_init_424;
__auto_type cn_init_442 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_442;
(rg[4]=r);
}
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_521 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_521;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_569 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_569;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_632 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_632;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_695 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_695;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_743 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_743;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_806 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_806;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_868 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_868;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_915 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_915;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_977 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_977;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[3]=f[0]);
{
__auto_type cn_init_1040 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1040;
(f[3]=(f[3]+v));
}
(f[4]=(((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))));
{
__auto_type cn_init_1090 = cn_double(v31); __auto_type v = cn_init_1090;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]-f[4]));
(f[3]=fabs(f[3]));
(f[4]=(((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))));
(f[4]=fabs(f[4]));
{
__auto_type cn_init_1183 = cn_double(r1); __auto_type v = cn_init_1183;
(f[4]=(f[4]+v));
}
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
(fsw=cn_compare(f[2],f[1]));
(f[1]=cn_double(v31));
{
__auto_type cn_init_1318 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1318;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1356 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1356;
(f[1]=(f[1]-v));
}
(f[0]=(f[1]-f[0]));
(r14=cn_bits(f[0]));
{
__auto_type cn_init_1401 = 0x20U; __auto_type bv = cn_init_1401;
__auto_type cn_init_1409 = rg[4]; __auto_type av = cn_init_1409;
__auto_type cn_init_1427 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1427;
(rg[4]=r);
}
{
(rg[1]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_b2:;
{
__auto_type cn_init_1513 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1513;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1551 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1551;
(f[2]=(f[2]-v));
}
(s2011=cn_bits(f[2]));
{
__auto_type cn_init_1600 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1600;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1638 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1638;
(f[1]=(f[1]-v));
}
(s2012=cn_bits(f[1]));
(s2014=cn_bits(f[0]));
(rg[0]=rg[4]);
(rg[2]=((uint32_t)(((((v30>>32))&0xffffffffULL)))));
(rg[1]=rg[4]);
{
__auto_type cn_init_1749 = cn_map_px(false,((int32_t)(rg[EDX])),(CN_D3){cn_double(s2011),cn_double(s2012),cn_double(s2013)}); __auto_type r = cn_init_1749;
(s2011=cn_bits(r[0]));
(s2012=cn_bits(r[1]));
(s2013=cn_bits(r[2]));
}
(rg[1]=((uint32_t)(((((v22>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1806 = 0x3U; __auto_type bv = cn_init_1806;
__auto_type cn_init_1814 = rg[1]; __auto_type av = cn_init_1814;
__auto_type cn_init_1832 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1832;
(rg[1]=r);
}
switch(((((rg[1]>>0))&3))){
case 0:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2011):(((((((rg[1]>>0))&3))==1)?(s2012):(((((((rg[1]>>0))&3))==2)?(s2013):(((((((rg[1]>>0))&3))==3)?(s2014):(0))))))))));
}
break;
case 1:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2011):(((((((rg[1]>>0))&3))==1)?(s2012):(((((((rg[1]>>0))&3))==2)?(s2013):(((((((rg[1]>>0))&3))==3)?(s2014):(0))))))))));
}
break;
case 2:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2011):(((((((rg[1]>>0))&3))==1)?(s2012):(((((((rg[1]>>0))&3))==2)?(s2013):(((((((rg[1]>>0))&3))==3)?(s2014):(0))))))))));
}
break;
case 3:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2011):(((((((rg[1]>>0))&3))==1)?(s2012):(((((((rg[1]>>0))&3))==2)?(s2013):(((((((rg[1]>>0))&3))==3)?(s2014):(0))))))))));
}
break;
default:
{
}
break;
}
{
__auto_type cn_init_2080 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2080;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2118 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2118;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2142 = cn_double(s2014); __auto_type v = cn_init_2142;
(f[0]=(f[0]-v));
}
(r14=cn_bits(f[0]));
(rg[1]=((uint32_t)(((((v22>>0))&0xffffffffULL)))));
{
__auto_type cn_init_2189 = 0x3U; __auto_type bv = cn_init_2189;
__auto_type cn_init_2197 = rg[1]; __auto_type av = cn_init_2197;
__auto_type cn_init_2215 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2215;
(rg[1]=r);
}
switch(((((rg[1]>>0))&3))){
case 0:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2011):(((((((rg[1]>>0))&3))==1)?(s2012):(((((((rg[1]>>0))&3))==2)?(s2013):(((((((rg[1]>>0))&3))==3)?(s2014):(0))))))))));
}
break;
case 1:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2011):(((((((rg[1]>>0))&3))==1)?(s2012):(((((((rg[1]>>0))&3))==2)?(s2013):(((((((rg[1]>>0))&3))==3)?(s2014):(0))))))))));
}
break;
case 2:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2011):(((((((rg[1]>>0))&3))==1)?(s2012):(((((((rg[1]>>0))&3))==2)?(s2013):(((((((rg[1]>>0))&3))==3)?(s2014):(0))))))))));
}
break;
case 3:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2011):(((((((rg[1]>>0))&3))==1)?(s2012):(((((((rg[1]>>0))&3))==2)?(s2013):(((((((rg[1]>>0))&3))==3)?(s2014):(0))))))))));
}
break;
default:
{
}
break;
}
{
__auto_type cn_init_2463 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2463;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2501 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2501;
(f[0]=(f[0]*v));
}
(r34=cn_bits(f[0]));
{
__auto_type cn_init_2531 = 0x20U; __auto_type bv = cn_init_2531;
__auto_type cn_init_2539 = rg[4]; __auto_type av = cn_init_2539;
__auto_type cn_init_2557 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2557;
(rg[4]=r);
}
{
(rg[1]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001070U,r14);
cn_wr64u(m,0x10001110U,r34);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
cn_wr64u(m,0x10007ef8U,s2015);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_98b9d24b2038668c(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+168))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_190;
__auto_type cn_init_207 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_207;
__auto_type cn_init_224 = cn_rd64(m,CN_REC+8*(32)); uint64_t r32 = cn_init_224;
__auto_type cn_init_241 = cn_rd64(m,CN_REC+8*(33)); uint64_t r33 = cn_init_241;
__auto_type cn_init_254 = cn_rd64u(m,0x10007e90U); uint64_t s2002 = cn_init_254;
__auto_type cn_init_267 = cn_rd64u(m,0x10007e98U); uint64_t s2003 = cn_init_267;
__auto_type cn_init_280 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_280;
__auto_type cn_init_293 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_293;
__auto_type cn_init_306 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_306;
__auto_type cn_init_319 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_319;
__auto_type cn_init_332 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_332;
__auto_type cn_init_345 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_345;
__auto_type cn_init_358 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_358;
__auto_type cn_init_371 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_371;
__auto_type cn_init_384 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_384;
__auto_type cn_init_397 = cn_cell(vm,0); uint64_t v21 = cn_init_397;
__auto_type cn_init_410 = cn_cell(vm,8); uint64_t v22 = cn_init_410;
__auto_type cn_init_423 = cn_cell(vm,16); uint64_t v23 = cn_init_423;
__auto_type cn_init_436 = cn_cell(vm,24); uint64_t v24 = cn_init_436;
__auto_type cn_init_449 = cn_cell(vm,32); uint64_t v25 = cn_init_449;
__auto_type cn_init_462 = cn_cell(vm,40); uint64_t v26 = cn_init_462;
__auto_type cn_init_475 = cn_cell(vm,48); uint64_t v27 = cn_init_475;
__auto_type cn_init_488 = cn_cell(vm,56); uint64_t v28 = cn_init_488;
__auto_type cn_init_501 = cn_cell(vm,64); uint64_t v29 = cn_init_501;
__auto_type cn_init_514 = cn_cell(vm,72); uint64_t v30 = cn_init_514;
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
__auto_type cn_init_616 = 0x50U; __auto_type bv = cn_init_616;
__auto_type cn_init_624 = rg[4]; __auto_type av = cn_init_624;
__auto_type cn_init_642 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_642;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2002=(((s2002&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
(rg[7]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_841 = 0x80U; __auto_type bv = cn_init_841;
__auto_type cn_init_849 = rg[7]; __auto_type av = cn_init_849;
__auto_type cn_init_867 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_867;
(rg[7]=r);
}
{
__auto_type cn_init_881 = 0x0U; __auto_type bv = cn_init_881;
__auto_type cn_init_898 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type av = cn_init_898;
__auto_type cn_init_916 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_916;
}
if(cn_cond(fl,15)){
goto cn_break_b2;
}
{
__auto_type cn_init_947 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type v = cn_init_947;
__auto_type cn_init_954 = fl.cf; __auto_type cf = cn_init_954;
__auto_type cn_init_972 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_972;
(fl.cf=cf);
(r33=(((r33&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
(f[0]=cn_double(v30));
(r32=cn_bits(f[0]));
}
cn_break_b2:;
(f[0]=cn_double(r32));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_1106 = cn_double(v26); __auto_type v = cn_init_1106;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r32=cn_bits(f[0]));
(f[0]=cn_double(v27));
(f[1]=f[0]);
(f[2]=f[1]);
(f[0]=(f[0]+f[2]));
(f[2]=-f[2]);
(f[3]=cn_double(r3));
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
(f[3]=-f[3]);
(f[3]=(f[3]+f[0]));
goto cn_break_b6;
}
cn_break_b4:;
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b6;
}
(f[3]=-f[3]);
(f[3]=(f[3]-f[0]));
}
cn_break_b6:;
(f[4]=cn_double(r4));
(fsw=cn_compare(f[4],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b8;
}
(f[4]=-f[4]);
(f[4]=(f[4]+f[0]));
goto cn_break_b10;
}
cn_break_b8:;
(fsw=cn_compare(f[4],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b10;
}
(f[4]=-f[4]);
(f[4]=(f[4]-f[0]));
}
cn_break_b10:;
(f[5]=cn_double(r5));
(fsw=cn_compare(f[5],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b12;
}
(f[5]=-f[5]);
(f[5]=(f[5]+f[0]));
goto cn_break_b14;
}
cn_break_b12:;
(fsw=cn_compare(f[5],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b14;
}
(f[5]=-f[5]);
(f[5]=(f[5]-f[0]));
}
cn_break_b14:;
cn_swap(f,5,2);
(f[5]=f[5]);
cn_swap(f,4,1);
(f[4]=f[4]);
cn_swap(f,3,0);
(f[3]=f[3]);
(f[3]=f[0]);
{
__auto_type cn_init_1908 = cn_double(v24); __auto_type v = cn_init_1908;
(f[3]=(f[3]*v));
}
{
__auto_type cn_tuple_1938_0 = sin(f[3]);
__auto_type cn_tuple_1938_1 = cos(f[3]);
__auto_type s = cn_tuple_1938_0;
__auto_type c = cn_tuple_1938_1;
(f[3]=s);
(f[4]=c);
(fsw&=~0x0400);
}
(s2012=cn_bits(f[4]));
(s2011=cn_bits(f[3]));
(f[3]=f[1]);
{
__auto_type cn_init_2001 = cn_double(v24); __auto_type v = cn_init_2001;
(f[3]=(f[3]*v));
}
{
__auto_type cn_tuple_2031_0 = sin(f[3]);
__auto_type cn_tuple_2031_1 = cos(f[3]);
__auto_type s = cn_tuple_2031_0;
__auto_type c = cn_tuple_2031_1;
(f[3]=s);
(f[4]=c);
(fsw&=~0x0400);
}
(s2010=cn_bits(f[4]));
(s2009=cn_bits(f[3]));
(f[3]=f[2]);
{
__auto_type cn_init_2094 = cn_double(v24); __auto_type v = cn_init_2094;
(f[3]=(f[3]*v));
}
{
__auto_type cn_tuple_2124_0 = sin(f[3]);
__auto_type cn_tuple_2124_1 = cos(f[3]);
__auto_type s = cn_tuple_2124_0;
__auto_type c = cn_tuple_2124_1;
(f[3]=s);
(f[4]=c);
(fsw&=~0x0400);
}
(s2008=cn_bits(f[4]));
(s2007=cn_bits(f[3]));
(f[3]=f[2]);
(f[3]=(f[3]*f[3]));
(f[4]=f[1]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[3]=sqrt(f[3]));
(s2006=cn_bits(f[3]));
(f[3]=cn_double(s2012));
{
__auto_type cn_init_2319 = cn_double(s2009); __auto_type v = cn_init_2319;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(s2010));
{
__auto_type cn_init_2355 = cn_double(s2007); __auto_type v = cn_init_2355;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(s2008));
{
__auto_type cn_init_2406 = cn_double(s2011); __auto_type v = cn_init_2406;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_2445 = cn_double(v25); __auto_type v = cn_init_2445;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(s2012));
{
__auto_type cn_init_2481 = cn_double(s2010); __auto_type v = cn_init_2481;
(f[4]=(f[4]+v));
}
{
__auto_type cn_init_2505 = cn_double(s2008); __auto_type v = cn_init_2505;
(f[4]=(f[4]+v));
}
{
__auto_type cn_init_2529 = cn_double(v23); __auto_type v = cn_init_2529;
(f[4]=(f[4]*v));
}
{
__auto_type cn_init_2548 = 0x1U; __auto_type bv = cn_init_2548;
__auto_type cn_init_2565 = (((uint32_t)(((((v21>>32))&0xffffffffULL))))); __auto_type av = cn_init_2565;
__auto_type cn_init_2583 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2583;
}
if(cn_cond(fl,4)){
goto cn_break_b16;
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(s2006));
{
__auto_type cn_init_2634 = cn_double(v22); __auto_type v = cn_init_2634;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
goto cn_break_b17;
}
cn_break_b16:;
{
__auto_type cn_init_2677 = cn_double(v22); __auto_type v = cn_init_2677;
(f[4]=(f[4]+v));
}
{
__auto_type cn_init_2701 = cn_double(s2006); __auto_type v = cn_init_2701;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
}
cn_break_b17:;
(f[3]=(f[3]*f[3]));
(fsw=cn_compare(f[3],cn_double(v28)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b19;
}
(f[3]=f[3]);
(f[3]=cn_double(v29));
goto cn_break_b22;
}
cn_break_b19:;
(f[4]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b21;
}
(f[4]=f[4]);
{
__auto_type cn_init_2946 = cn_double(r32); __auto_type v = cn_init_2946;
(f[3]=(v/f[3]));
}
goto cn_break_b22;
}
cn_break_b21:;
(fsw=cn_compare(f[4],f[3]));
(f[3]=cn_double(r32));
}
cn_break_b22:;
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[3]));
(r6=cn_bits(f[4]));
(f[0]=(f[0]*f[3]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
{
__auto_type cn_init_3085 = cn_double(r12); __auto_type v = cn_init_3085;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_3120 = cn_double(r11); __auto_type v = cn_init_3120;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_3155 = cn_double(r10); __auto_type v = cn_init_3155;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[3]=((uint32_t)(((((s2002>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[7]=((uint32_t)(((((s2003>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2003>>32))&0xffffffffULL)))));
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
cn_wr64(m,CN_REC+8*(32),r32);
cn_wr64(m,CN_REC+8*(33),r33);
cn_wr64u(m,0x10007e90U,s2002);
cn_wr64u(m,0x10007e98U,s2003);
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
int cn_f_99355b3a19457e8c(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_645 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_645;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_693 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_693;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_756 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_756;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_819 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_819;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_867 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_867;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_930 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_930;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_992 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_992;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1039 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1039;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1101 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1101;
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
if(cn_cond(fl,3)){
goto cn_break_b6;
}
cn_swap(f,2,0);
}
cn_break_b6:;
(f[2]=-f[2]);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b8;
}
cn_swap(f,2,0);
}
cn_break_b8:;
(f[2]=-f[2]);
cn_swap(f,2,1);
(f[3]=f[1]);
{
__auto_type cn_init_1537 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1537;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_1585 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1585;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1648 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1648;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_1711 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1711;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1759 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1759;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1822 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1822;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_1884 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1884;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_1931 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1931;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1993 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1993;
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
__auto_type cn_init_2174 = cn_double(v29); __auto_type v = cn_init_2174;
(f[5]=(f[5]*v));
}
(f[1]=(f[1]-f[5]));
{
__auto_type cn_init_2213 = cn_double(v28); __auto_type v = cn_init_2213;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]-f[4]));
{
__auto_type cn_init_2252 = cn_double(v27); __auto_type v = cn_init_2252;
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
int cn_f_9b7cb3a25acb3d6f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[3]=-f[3]);
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b2;
}
cn_swap(f,3,2);
}
cn_break_b2:;
(f[3]=-f[3]);
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
cn_swap(f,3,2);
}
cn_break_b4:;
(f[3]=-f[3]);
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
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
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b10;
}
cn_swap(f,3,0);
}
cn_break_b10:;
(f[3]=-f[3]);
(fsw=cn_compare(f[3],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b12;
}
cn_swap(f,3,0);
}
cn_break_b12:;
{
__auto_type cn_init_1257 = 0x28U; __auto_type bv = cn_init_1257;
__auto_type cn_init_1265 = rg[7]; __auto_type av = cn_init_1265;
__auto_type cn_init_1283 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_1283;
(rg[7]=r);
}
(f[4]=f[3]);
{
__auto_type cn_init_1326 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1326;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1374 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1374;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1437 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1437;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1500 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1500;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r3=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_1574 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1574;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1622 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1622;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1685 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1685;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1748 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1748;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r4=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_1822 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1822;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1870 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1870;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1933 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1933;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1996 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1996;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r5=cn_bits(f[4]));
{
__auto_type cn_init_2060 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2060;
(f[3]=(f[3]*v));
}
cn_swap(f,3,2);
{
__auto_type cn_init_2107 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2107;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
cn_swap(f,2,1);
{
__auto_type cn_init_2169 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2169;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
cn_swap(f,1,0);
{
__auto_type cn_init_2231 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2231;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r6=cn_bits(f[0]));
{
__auto_type cn_init_2276 = 0x28U; __auto_type bv = cn_init_2276;
__auto_type cn_init_2284 = rg[7]; __auto_type av = cn_init_2284;
__auto_type cn_init_2302 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2302;
(rg[7]=r);
}
(f[0]=cn_double(r6));
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[4]=cn_double(v30));
(f[5]=f[4]);
{
__auto_type cn_init_2391 = cn_double(r36); __auto_type v = cn_init_2391;
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
