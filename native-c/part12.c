/* Generated native C formula calculations. See tools/generate-native-c.py. */
#include "runtime.h"
int cn_f_be6549f648444f08(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
{
__auto_type cn_init_563 = cn_double(r5); __auto_type v = cn_init_563;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_599 = cn_double(r6); __auto_type v = cn_init_599;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(r3));
{
__auto_type cn_init_665 = cn_double(r6); __auto_type v = cn_init_665;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r4));
{
__auto_type cn_init_701 = cn_double(r5); __auto_type v = cn_init_701;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=(f[1]+f[1]));
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(r4));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r5));
(f[3]=(f[3]*f[3]));
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b3;
}
(f[2]=(f[3]/f[2]));
(f[2]=-f[2]);
(f[3]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[3]));
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]-f[4]));
(f[3]=(f[3]*f[2]));
(f[4]=cn_double(r3));
{
__auto_type cn_init_1112 = cn_double(r4); __auto_type v = cn_init_1112;
(f[4]=(f[4]*v));
}
goto cn_break_b2;
}
cn_break_b3:;
(f[2]=(f[2]/f[3]));
(f[3]=cn_double(0x3ff0000000000000));
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r5));
(f[3]=(f[3]*f[3]));
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]-f[4]));
(f[3]=(f[3]*f[2]));
(f[4]=cn_double(r5));
{
__auto_type cn_init_1289 = cn_double(r6); __auto_type v = cn_init_1289;
(f[4]=(f[4]*v));
}
}
cn_break_b2:;
(f[4]=(f[4]+f[4]));
(f[4]=(f[4]*f[2]));
(r4=cn_bits(f[4]));
(r3=cn_bits(f[3]));
(f[2]=f[2]);
(r6=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r10));
{
__auto_type cn_init_1410 = cn_double(r3); __auto_type v = cn_init_1410;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r11));
{
__auto_type cn_init_1457 = cn_double(r4); __auto_type v = cn_init_1457;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r12));
{
__auto_type cn_init_1504 = cn_double(r5); __auto_type v = cn_init_1504;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r0));
{
__auto_type cn_init_1551 = cn_double(v30); __auto_type v = cn_init_1551;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1575 = cn_double(r6); __auto_type v = cn_init_1575;
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
int cn_f_bf79183e66c994f5(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+208))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(0)); uint64_t r0 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_173;
__auto_type cn_init_186 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_186;
__auto_type cn_init_199 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_199;
__auto_type cn_init_212 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_212;
__auto_type cn_init_225 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_225;
__auto_type cn_init_238 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_238;
__auto_type cn_init_251 = cn_cell(vm,0); uint64_t v26 = cn_init_251;
__auto_type cn_init_264 = cn_cell(vm,8); uint64_t v27 = cn_init_264;
__auto_type cn_init_277 = cn_cell(vm,16); uint64_t v28 = cn_init_277;
__auto_type cn_init_290 = cn_cell(vm,24); uint64_t v29 = cn_init_290;
__auto_type cn_init_303 = cn_cell(vm,32); uint64_t v30 = cn_init_303;
{
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_375 = 0x10U; __auto_type bv = cn_init_375;
__auto_type cn_init_383 = rg[4]; __auto_type av = cn_init_383;
__auto_type cn_init_401 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_401;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
{
__auto_type cn_init_600 = 0x0U; __auto_type bv = cn_init_600;
__auto_type cn_init_617 = (((uint32_t)(((((v30>>32))&0xffffffffULL))))); __auto_type av = cn_init_617;
__auto_type cn_init_635 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_635;
}
if(cn_cond(fl,4)){
goto cn_break_b3;
}
(f[0]=cn_double(((((((v29>>32))|((v30<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(r3));
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_758_0 = f[2];
__auto_type cn_tuple_758_1 = f[1];
__auto_type x = cn_tuple_758_0;
__auto_type y = cn_tuple_758_1;
__auto_type cn_init_787 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_787;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_819 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_819;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
{
__auto_type cn_init_965 = cn_double(((((((v28>>32))|((v29<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_965;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(((((((v29>>32))|((v30<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_1099_0 = f[2];
__auto_type cn_tuple_1099_1 = f[1];
__auto_type x = cn_tuple_1099_0;
__auto_type y = cn_tuple_1099_1;
__auto_type cn_init_1128 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1128;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1160 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1160;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
{
__auto_type cn_init_1306 = cn_double(((((((v27>>32))|((v28<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1306;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1330 = cn_double(s2012); __auto_type v = cn_init_1330;
(f[0]=(f[0]+v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(((((((v29>>32))|((v30<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(r5));
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_1464_0 = f[2];
__auto_type cn_tuple_1464_1 = f[1];
__auto_type x = cn_tuple_1464_0;
__auto_type y = cn_tuple_1464_1;
__auto_type cn_init_1493 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1493;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1525 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1525;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
{
__auto_type cn_init_1671 = cn_double(((((((v26>>32))|((v27<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1671;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1695 = cn_double(s2012); __auto_type v = cn_init_1695;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(((((((v28>>32))|((v29<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1763 = cn_double(((((((v27>>32))|((v28<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1763;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_1803 = cn_double(((((((v26>>32))|((v27<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1803;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(((((((v29>>32))|((v30<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]/f[2]));
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_1951_0 = f[2];
__auto_type cn_tuple_1951_1 = f[1];
__auto_type x = cn_tuple_1951_0;
__auto_type y = cn_tuple_1951_1;
__auto_type cn_init_1980 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1980;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_2012 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_2012;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
goto cn_break_b2;
}
cn_break_b3:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_2174 = cn_double(((((((v28>>32))|((v29<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2174;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_2226 = cn_double(((((((v27>>32))|((v28<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2226;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_2278 = cn_double(((((((v26>>32))|((v27<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2278;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((v28>>32))|((v29<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2376 = cn_double(((((((v27>>32))|((v28<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2376;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2416 = cn_double(((((((v26>>32))|((v27<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2416;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]/f[1]));
}
cn_break_b2:;
(r6=cn_bits(f[0]));
(r0=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s2010>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2011>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2011>>32))&0xffffffffULL)))));
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
cn_wr64(m,CN_REC+8*(0),r0);
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_bfc76004fae4a28f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_476 = cn_double(v23); __auto_type v = cn_init_476;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_512 = cn_double(v29); __auto_type v = cn_init_512;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_563 = cn_double(v28); __auto_type v = cn_init_563;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r6));
{
__auto_type cn_init_614 = cn_double(v27); __auto_type v = cn_init_614;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_653 = cn_double(v30); __auto_type v = cn_init_653;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(v26));
{
__auto_type cn_init_689 = cn_double(r5); __auto_type v = cn_init_689;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_713 = cn_double(r6); __auto_type v = cn_init_713;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v29));
{
__auto_type cn_init_749 = cn_double(r3); __auto_type v = cn_init_749;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_837 = cn_double(v22); __auto_type v = cn_init_837;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_861 = cn_double(v29); __auto_type v = cn_init_861;
(f[2]=(f[2]+v));
}
{
__auto_type cn_init_885 = cn_double(r4); __auto_type v = cn_init_885;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v25));
{
__auto_type cn_init_936 = cn_double(r4); __auto_type v = cn_init_936;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_960 = cn_double(r6); __auto_type v = cn_init_960;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(v28));
{
__auto_type cn_init_996 = cn_double(r3); __auto_type v = cn_init_996;
(f[3]=(f[3]*v));
}
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[3]));
(f[3]=-f[3]);
{
__auto_type cn_init_1084 = cn_double(v22); __auto_type v = cn_init_1084;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_1108 = cn_double(v28); __auto_type v = cn_init_1108;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_1132 = cn_double(r5); __auto_type v = cn_init_1132;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(v24));
{
__auto_type cn_init_1183 = cn_double(r5); __auto_type v = cn_init_1183;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_1207 = cn_double(r4); __auto_type v = cn_init_1207;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(v27));
{
__auto_type cn_init_1243 = cn_double(r3); __auto_type v = cn_init_1243;
(f[4]=(f[4]*v));
}
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
(f[4]=(f[4]*f[4]));
(f[4]=-f[4]);
{
__auto_type cn_init_1331 = cn_double(v22); __auto_type v = cn_init_1331;
(f[4]=(f[4]*v));
}
{
__auto_type cn_init_1355 = cn_double(v27); __auto_type v = cn_init_1355;
(f[4]=(f[4]+v));
}
{
__auto_type cn_init_1379 = cn_double(r6); __auto_type v = cn_init_1379;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
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
int cn_f_c0d951c2712fba4d(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[1]=(f[1]/f[0]));
(f[2]=cn_double(v27));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_688 = cn_double(v30); __auto_type v = cn_init_688;
(f[1]=(f[1]-v));
}
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[0]/f[1]));
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
int cn_f_c0dcddf31e72bec8(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_175 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,0); uint64_t v21 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,8); uint64_t v22 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,16); uint64_t v23 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,24); uint64_t v24 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,32); uint64_t v25 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,40); uint64_t v26 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,48); uint64_t v27 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,56); uint64_t v28 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,64); uint64_t v29 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,72); uint64_t v30 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,88); uint64_t v32 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,96); uint64_t v33 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,104); uint64_t v34 = cn_init_409;
{
{
{
{
__auto_type cn_init_424 = 0xffffffd8U; __auto_type bv = cn_init_424;
__auto_type cn_init_432 = rg[4]; __auto_type av = cn_init_432;
__auto_type cn_init_450 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_450;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_479 = r5; uint64_t s = cn_init_479;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_509 = (CN_U2){v28,v29}; CN_U2 s = cn_init_509;
__auto_type cn_init_519 = m->xmm[0]; __auto_type a = cn_init_519;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_589 = v28; uint64_t s = cn_init_589;
__auto_type cn_init_602 = m->xmm[1][0]; __auto_type a = cn_init_602;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_649 = (CN_U2){v24,v25}; CN_U2 s = cn_init_649;
__auto_type cn_init_659 = m->xmm[0]; __auto_type a = cn_init_659;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_729 = v26; uint64_t s = cn_init_729;
__auto_type cn_init_742 = m->xmm[1][0]; __auto_type a = cn_init_742;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_779 = 0x0U; __auto_type bv = cn_init_779;
__auto_type cn_init_796 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_796;
__auto_type cn_init_814 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_814;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_835 = r32; uint64_t s = cn_init_835;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_857 = v28; uint64_t s = cn_init_857;
__auto_type cn_init_870 = m->xmm[5][0]; __auto_type a = cn_init_870;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_966 = m->xmm[0][0]; uint64_t v = cn_init_966;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1025 = m->xmm[0][1]; uint64_t v = cn_init_1025;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1084 = m->xmm[1][0]; uint64_t v = cn_init_1084;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
__auto_type cn_tuple_1202_0 = f[0];
__auto_type cn_tuple_1202_1 = f[1];
__auto_type pa18y = cn_tuple_1202_0;
__auto_type pa18x = cn_tuple_1202_1;
__auto_type cn_tuple_1216_0 = atan2(pa18y,pa18x);
__auto_type cn_tuple_1216_1 = atan2(pa18y,pa18x);
__auto_type pa18lo = cn_tuple_1216_0;
__auto_type pa18hi = cn_tuple_1216_1;
(f[0]=pa18lo);
__auto_type cn_init_1252 = ({__auto_type cn_init_1237 = cn_double(v34); __auto_type v = cn_init_1237; (f[0]=(v-f[0])); v;}); __auto_type c18_19 = cn_init_1252;
__auto_type cn_init_1281 = ({__auto_type cn_init_1266 = cn_double(v32); __auto_type v = cn_init_1266; (f[0]=(f[0]*v)); v;}); __auto_type c18_20 = cn_init_1281;
__auto_type cn_init_1321 = ({__auto_type cn_init_1306 = (((double)(((int32_t)(((uint32_t)(((((v30>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_1306; (f[0]=(f[0]*v)); v;}); __auto_type c18_21 = cn_init_1321;
{

__auto_type cn_init_1368 = cn_round(m,({__auto_type cn_arg=pa18lo; ({(cn_arg=(c18_19-cn_arg)); (cn_arg=(cn_arg*c18_20)); (cn_arg=(cn_arg*c18_21)); cn_arg;});})); __auto_type r1 = cn_init_1368;
__auto_type cn_init_1381 = cn_round(m,({__auto_type cn_arg=pa18hi; ({(cn_arg=(c18_19-cn_arg)); (cn_arg=(cn_arg*c18_20)); (cn_arg=(cn_arg*c18_21)); cn_arg;});})); __auto_type r2 = cn_init_1381;
(f[0]=((((r1==r2)&&(cn_bits(r1)==cn_bits(r2))))?(({r1;})):(({cn_round(m,({__auto_type cn_arg=atan2(pa18y,pa18x); ({(cn_arg=(c18_19-cn_arg)); (cn_arg=(cn_arg*c18_20)); (cn_arg=(cn_arg*c18_21)); cn_arg;});}));}))));
}
{
__auto_type cn_init_1446 = (((double)(((int32_t)(((uint32_t)(((((v30>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_1446;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_1470 = cn_double(v33); __auto_type v = cn_init_1470;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1501_0 = sin(f[0]);
__auto_type cn_tuple_1501_1 = cos(f[0]);
__auto_type s = cn_tuple_1501_0;
__auto_type c = cn_tuple_1501_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
{
__auto_type cn_init_1536 = cn_bits(f[1]); uint64_t v = cn_init_1536;
(s2014=(((s2014&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2015=(((s2015&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1594 = cn_bits(f[0]); uint64_t v = cn_init_1594;
(s2013=(((s2013&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2014=(((s2014&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1692 = cn_double(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1692;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1760 = cn_double(((((((s2014>>32))|((s2015<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1760;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1854 = cn_double(((((((s2014>>32))|((s2015<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1854;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1922 = cn_double(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1922;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_1965 = cn_bits(f[1]); uint64_t v = cn_init_1965;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_2023 = cn_bits(f[0]); uint64_t v = cn_init_2023;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
__auto_type cn_tuple_2141_0 = f[0];
__auto_type cn_tuple_2141_1 = f[1];
__auto_type pa43y = cn_tuple_2141_0;
__auto_type pa43x = cn_tuple_2141_1;
__auto_type cn_tuple_2155_0 = atan2(pa43y,pa43x);
__auto_type cn_tuple_2155_1 = atan2(pa43y,pa43x);
__auto_type pa43lo = cn_tuple_2155_0;
__auto_type pa43hi = cn_tuple_2155_1;
(f[0]=pa43lo);
__auto_type cn_init_2191 = ({__auto_type cn_init_2176 = cn_double(v34); __auto_type v = cn_init_2176; (f[0]=(v-f[0])); v;}); __auto_type c43_44 = cn_init_2191;
__auto_type cn_init_2220 = ({__auto_type cn_init_2205 = cn_double(v32); __auto_type v = cn_init_2205; (f[0]=(f[0]*v)); v;}); __auto_type c43_45 = cn_init_2220;
__auto_type cn_init_2260 = ({__auto_type cn_init_2245 = (((double)(((int32_t)(((uint32_t)(((((v30>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_2245; (f[0]=(f[0]*v)); v;}); __auto_type c43_46 = cn_init_2260;
{

__auto_type cn_init_2307 = cn_round(m,({__auto_type cn_arg=pa43lo; ({(cn_arg=(c43_44-cn_arg)); (cn_arg=(cn_arg*c43_45)); (cn_arg=(cn_arg*c43_46)); cn_arg;});})); __auto_type r1 = cn_init_2307;
__auto_type cn_init_2320 = cn_round(m,({__auto_type cn_arg=pa43hi; ({(cn_arg=(c43_44-cn_arg)); (cn_arg=(cn_arg*c43_45)); (cn_arg=(cn_arg*c43_46)); cn_arg;});})); __auto_type r2 = cn_init_2320;
(f[0]=((((r1==r2)&&(cn_bits(r1)==cn_bits(r2))))?(({r1;})):(({cn_round(m,({__auto_type cn_arg=atan2(pa43y,pa43x); ({(cn_arg=(c43_44-cn_arg)); (cn_arg=(cn_arg*c43_45)); (cn_arg=(cn_arg*c43_46)); cn_arg;});}));}))));
}
{
__auto_type cn_init_2385 = (((double)(((int32_t)(((uint32_t)(((((v30>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_2385;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_2409 = cn_double(v33); __auto_type v = cn_init_2409;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_2440_0 = sin(f[0]);
__auto_type cn_tuple_2440_1 = cos(f[0]);
__auto_type s = cn_tuple_2440_0;
__auto_type c = cn_tuple_2440_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
{
__auto_type cn_init_2475 = cn_bits(f[1]); uint64_t v = cn_init_2475;
(s2014=(((s2014&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2015=(((s2015&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_2533 = cn_bits(f[0]); uint64_t v = cn_init_2533;
(s2013=(((s2013&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2014=(((s2014&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2631 = cn_double(((((((s2014>>32))|((s2015<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2631;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2699 = cn_double(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2699;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2754 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2754;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_2808 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2808;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2827 = 0x0U; __auto_type bv = cn_init_2827;
__auto_type cn_init_2844 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_2844;
__auto_type cn_init_2862 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2862;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
{
__auto_type cn_init_2886 = cn_double(v28); __auto_type v = cn_init_2886;
(f[0]=(f[0]/v));
}
}
cn_break_b4:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2917 = 0x28U; __auto_type bv = cn_init_2917;
__auto_type cn_init_2925 = rg[4]; __auto_type av = cn_init_2925;
__auto_type cn_init_2943 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2943;
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
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
cn_wr64u(m,0x10007ef8U,s2015);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_c18a0ced851f0bba(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;
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
__auto_type cn_init_76 = rg[1]; __auto_type v = cn_init_76;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_94 = 0xffffffe0U; __auto_type bv = cn_init_94;
__auto_type cn_init_102 = rg[4]; __auto_type av = cn_init_102;
__auto_type cn_init_120 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_120;
(rg[4]=r);
}
(f[0]=cn_rdf64u(m,((uint32_t)(rg[6]+0xffffff98U))));
(f[1]=cn_rdf64u(m,((uint32_t)(rg[6]+0xffffff90U))));
(f[2]=cn_rdf64u(m,((uint32_t)(rg[6]+0xffffff88U))));
(f[3]=f[2]);
(f[3]=(f[3]*f[3]));
(f[4]=f[1]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[4]/f[3]));
{
__auto_type cn_init_343 = cn_floadu(m,FKind_F64,((uint32_t)(rg[7]+0x0U))); __auto_type v = cn_init_343;
(fsw=cn_compare(f[3],v));
}
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
{
__auto_type cn_init_384 = 0x41U; __auto_type bv = cn_init_384;
__auto_type cn_init_397 = cn_reg_get(rg,4,1); __auto_type av = cn_init_397;
__auto_type cn_init_415 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_415;
cn_reg_set(rg,4,1,r);
}
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
(f[3]=f[3]);
(rg[1]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffa4U))));
{
__auto_type cn_init_506 = 0x1U; __auto_type bv = cn_init_506;
__auto_type cn_init_514 = rg[1]; __auto_type av = cn_init_514;
__auto_type cn_init_532 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_532;
(rg[1]=r);
}
cn_shift_reg_l(rg,&fl,Shift_Shl,1,3,4);
(f[3]=cn_rdf64(m,((uint32_t)((((uint32_t)(rg[1]+0x0U)))+((uint32_t)(rg[7]*1))))));
(b=2);
}
break;
case 2:
{
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]*f[3]));
(f[0]=(f[0]*f[3]));
{
__auto_type cn_init_664 = ((uint32_t)(rg[6]+0xffffffe0U)); __auto_type a = cn_init_664;
cn_wrf64u(m,a,f[3]);
}
(f[3]=f[2]);
{
__auto_type cn_init_710 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffc0U))); __auto_type v = cn_init_710;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_756 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffbcU))); __auto_type v = cn_init_756;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_817 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffb8U))); __auto_type v = cn_init_817;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_878 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffd8U))); __auto_type v = cn_init_878;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_924 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffd4U))); __auto_type v = cn_init_924;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_985 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffd0U))); __auto_type v = cn_init_985;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1045 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffccU))); __auto_type v = cn_init_1045;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1090 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffc8U))); __auto_type v = cn_init_1090;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1150 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffc4U))); __auto_type v = cn_init_1150;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[3]=f[0]);
{
__auto_type cn_init_1211 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffe8U))); __auto_type v = cn_init_1211;
(f[3]=(f[3]+v));
}
(f[4]=cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffdcU))));
{
__auto_type cn_init_1267 = cn_rdf64u(m,((uint32_t)(rg[7]+0xfffffff8U))); __auto_type v = cn_init_1267;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]-f[4]));
(f[3]=fabs(f[3]));
(f[4]=cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffdcU))));
(f[4]=fabs(f[4]));
{
__auto_type cn_init_1366 = cn_rdf64u(m,((uint32_t)(rg[6]+0xffffff78U))); __auto_type v = cn_init_1366;
(f[4]=(f[4]+v));
}
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
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
(fsw=cn_compare(f[2],f[1]));
(f[1]=cn_rdf64u(m,((uint32_t)(rg[7]+0xfffffff8U))));
{
__auto_type cn_init_1536 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffdcU))); __auto_type v = cn_init_1536;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1572 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffe8U))); __auto_type v = cn_init_1572;
(f[1]=(f[1]-v));
}
(f[0]=(f[1]-f[0]));
{
__auto_type cn_init_1619 = cn_rdf64u(m,((uint32_t)(rg[6]+0xffffffe0U))); __auto_type v = cn_init_1619;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_1646 = ((uint32_t)(rg[6]+0xffffffe0U)); __auto_type a = cn_init_1646;
cn_wrf64u(m,a,f[0]);
}
{
__auto_type cn_init_1665 = 0x20U; __auto_type bv = cn_init_1665;
__auto_type cn_init_1673 = rg[4]; __auto_type av = cn_init_1673;
__auto_type cn_init_1691 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1691;
(rg[4]=r);
}
{
__auto_type cn_init_1712 = cn_pop_lu(m,rg); __auto_type v = cn_init_1712;
(rg[1]=v);
}
__auto_type cn_init_1732 = cn_pop_lu(m,rg); __auto_type r = cn_init_1732;
(rg[ESP]=((uint32_t)(rg[ESP]+0)));
(m->st=f);
(*regs)=rg; m->regs=rg; return 0;
}
break;
case 4:
{
{
__auto_type cn_init_1787 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffe4U))); __auto_type v = cn_init_1787;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1823 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xfffffff0U))); __auto_type v = cn_init_1823;
(f[2]=(f[2]-v));
}
{
__auto_type cn_init_1850 = ((uint32_t)(rg[4]+0x0U)); __auto_type a = cn_init_1850;
cn_wrf64u(m,a,f[2]);
}
{
__auto_type cn_init_1886 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffe0U))); __auto_type v = cn_init_1886;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1922 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffecU))); __auto_type v = cn_init_1922;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_1949 = ((uint32_t)(rg[4]+0x8U)); __auto_type a = cn_init_1949;
cn_wrf64u(m,a,f[1]);
}
{
__auto_type cn_init_1976 = ((uint32_t)(rg[4]+0x18U)); __auto_type a = cn_init_1976;
cn_wrf64u(m,a,f[0]);
}
(rg[0]=rg[4]);
(rg[2]=cn_rd32u(m,((uint32_t)(rg[7]+0xfffffff4U))));
(rg[1]=rg[4]);
cn_height_host(m,rg,f);
(rg[1]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffb4U))));
{
__auto_type cn_init_2064 = 0x3U; __auto_type bv = cn_init_2064;
__auto_type cn_init_2072 = rg[1]; __auto_type av = cn_init_2072;
__auto_type cn_init_2090 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2090;
(rg[1]=r);
}
(f[0]=cn_rdf64(m,((uint32_t)((((uint32_t)(rg[4]+0x0U)))+((uint32_t)(rg[1]*8))))));
{
__auto_type cn_init_2157 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffdcU))); __auto_type v = cn_init_2157;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2193 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffe8U))); __auto_type v = cn_init_2193;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2225 = cn_rdf64u(m,((uint32_t)(rg[4]+0x18U))); __auto_type v = cn_init_2225;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2257 = cn_rdf64u(m,((uint32_t)(rg[6]+0xffffffe0U))); __auto_type v = cn_init_2257;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_2284 = ((uint32_t)(rg[6]+0xffffffe0U)); __auto_type a = cn_init_2284;
cn_wrf64u(m,a,f[0]);
}
(rg[1]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffb0U))));
{
__auto_type cn_init_2323 = 0x3U; __auto_type bv = cn_init_2323;
__auto_type cn_init_2331 = rg[1]; __auto_type av = cn_init_2331;
__auto_type cn_init_2349 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2349;
(rg[1]=r);
}
(f[0]=cn_rdf64(m,((uint32_t)((((uint32_t)(rg[4]+0x0U)))+((uint32_t)(rg[1]*8))))));
{
__auto_type cn_init_2416 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffacU))); __auto_type v = cn_init_2416;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2452 = cn_floadu(m,FKind_F32,((uint32_t)(rg[7]+0xffffffa8U))); __auto_type v = cn_init_2452;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2479 = ((uint32_t)(rg[6]+0x80U)); __auto_type a = cn_init_2479;
cn_wrf64u(m,a,f[0]);
}
{
__auto_type cn_init_2498 = 0x20U; __auto_type bv = cn_init_2498;
__auto_type cn_init_2506 = rg[4]; __auto_type av = cn_init_2506;
__auto_type cn_init_2524 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2524;
(rg[4]=r);
}
{
__auto_type cn_init_2545 = cn_pop_lu(m,rg); __auto_type v = cn_init_2545;
(rg[1]=v);
}
__auto_type cn_init_2565 = cn_pop_lu(m,rg); __auto_type r = cn_init_2565;
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
int cn_f_c2594bf5906a27ea(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+200))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_88;
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
(f[0]=cn_double(r5));
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
{
__auto_type cn_init_423 = (((uint32_t)(((((r5>>56))&0xffULL))))); __auto_type v = cn_init_423;
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
(f[1]=cn_double(r5));
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
(r5=cn_bits(f[0]));
{
__auto_type cn_init_820 = cn_reg_get(rg,2,1); __auto_type bv = cn_init_820;
__auto_type cn_init_837 = (((uint32_t)(((((r5>>56))&0xffULL))))); __auto_type av = cn_init_837;
__auto_type cn_init_855 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_855;
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
int cn_f_c2617e0c54c1c2de(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_152 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_178;
__auto_type cn_init_191 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_191;
__auto_type cn_init_204 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_204;
__auto_type cn_init_217 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_217;
__auto_type cn_init_230 = cn_cell(vm,0); uint64_t v25 = cn_init_230;
__auto_type cn_init_243 = cn_cell(vm,8); uint64_t v26 = cn_init_243;
__auto_type cn_init_256 = cn_cell(vm,16); uint64_t v27 = cn_init_256;
__auto_type cn_init_269 = cn_cell(vm,24); uint64_t v28 = cn_init_269;
__auto_type cn_init_282 = cn_cell(vm,32); uint64_t v29 = cn_init_282;
__auto_type cn_init_295 = cn_cell(vm,40); uint64_t v30 = cn_init_295;
__auto_type cn_init_308 = cn_cell(vm,56); uint64_t v32 = cn_init_308;
__auto_type cn_init_321 = cn_cell(vm,64); uint64_t v33 = cn_init_321;
__auto_type cn_init_334 = cn_cell(vm,72); uint64_t v34 = cn_init_334;
__auto_type cn_init_347 = cn_cell(vm,80); uint64_t v35 = cn_init_347;
__auto_type cn_init_360 = cn_cell(vm,88); uint64_t v36 = cn_init_360;
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
__auto_type cn_init_638 = 0xffffffe0U; __auto_type bv = cn_init_638;
__auto_type cn_init_646 = rg[4]; __auto_type av = cn_init_646;
__auto_type cn_init_664 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_664;
(rg[4]=r);
}
(f[0]=cn_double(r5));
(f[1]=cn_double(v25));
(f[0]=(f[0]*f[1]));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x1000801dU))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_766 = cn_double(v32); __auto_type v = cn_init_766;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_793 = cn_round(m,f[0]); __auto_type x = cn_init_793;
__auto_type cn_init_828 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_828;
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2011>>0))&0xffffffffULL))))))))));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v36));
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_957 = cn_double(v35); __auto_type v = cn_init_957;
(f[2]=(f[2]+v));
}
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_996 = cn_double(v34); __auto_type v = cn_init_996;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_1035 = cn_double(v33); __auto_type v = cn_init_1035;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_1081 = (((uint32_t)(((((s2011>>0))&0xffULL))))); __auto_type v = cn_init_1081;
cn_reg_set(rg,0,1,v);
}
{
__auto_type cn_init_1101 = 0x1U; __auto_type bv = cn_init_1101;
__auto_type cn_init_1114 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1114;
__auto_type cn_init_1132 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1132;
cn_reg_set(rg,0,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b34;
}
(f[0]=-f[0]);
}
cn_break_b34:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f[1]=cn_double(r5));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v26));
(f[0]=(f[0]*f[1]));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x1000802bU))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_1294 = cn_double(v32); __auto_type v = cn_init_1294;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1321 = cn_round(m,f[0]); __auto_type x = cn_init_1321;
__auto_type cn_init_1356 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_1356;
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2011>>0))&0xffffffffULL))))))))));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v36));
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_1485 = cn_double(v35); __auto_type v = cn_init_1485;
(f[2]=(f[2]+v));
}
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_1524 = cn_double(v34); __auto_type v = cn_init_1524;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_1563 = cn_double(v33); __auto_type v = cn_init_1563;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_1609 = (((uint32_t)(((((s2011>>0))&0xffULL))))); __auto_type v = cn_init_1609;
cn_reg_set(rg,0,1,v);
}
{
__auto_type cn_init_1629 = 0x1U; __auto_type bv = cn_init_1629;
__auto_type cn_init_1642 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1642;
__auto_type cn_init_1660 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1660;
cn_reg_set(rg,0,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b35;
}
(f[0]=-f[0]);
}
cn_break_b35:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f[1]=cn_double(r5));
(f[0]=(f[0]+f[1]));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008034U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_1795 = cn_double(v32); __auto_type v = cn_init_1795;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1822 = cn_round(m,f[0]); __auto_type x = cn_init_1822;
__auto_type cn_init_1857 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_1857;
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2011>>0))&0xffffffffULL))))))))));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v36));
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_1986 = cn_double(v35); __auto_type v = cn_init_1986;
(f[2]=(f[2]+v));
}
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_2025 = cn_double(v34); __auto_type v = cn_init_2025;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_2064 = cn_double(v33); __auto_type v = cn_init_2064;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2110 = (((uint32_t)(((((s2011>>0))&0xffULL))))); __auto_type v = cn_init_2110;
cn_reg_set(rg,0,1,v);
}
{
__auto_type cn_init_2130 = 0x1U; __auto_type bv = cn_init_2130;
__auto_type cn_init_2143 = cn_reg_get(rg,0,1); __auto_type av = cn_init_2143;
__auto_type cn_init_2161 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2161;
cn_reg_set(rg,0,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b36;
}
(f[0]=-f[0]);
}
cn_break_b36:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f[1]=cn_double(v29));
(f[0]=(f[0]*f[1]));
(f[0]=-f[0]);
(f[1]=cn_double(r3));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v30));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(r3));
(f[2]=cn_double(v25));
(f[1]=(f[1]*f[2]));
(f=(CN_D8){f[1],f[2],f[3],f[4],f[5],f[6],f[7],f[0]});
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)((0xfffe001fU))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_2444 = cn_double(v32); __auto_type v = cn_init_2444;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2471 = cn_round(m,f[0]); __auto_type x = cn_init_2471;
__auto_type cn_init_2506 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2506;
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2011>>0))&0xffffffffULL))))))))));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v36));
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_2635 = cn_double(v35); __auto_type v = cn_init_2635;
(f[2]=(f[2]+v));
}
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_2674 = cn_double(v34); __auto_type v = cn_init_2674;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_2713 = cn_double(v33); __auto_type v = cn_init_2713;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2759 = (((uint32_t)(((((s2011>>0))&0xffULL))))); __auto_type v = cn_init_2759;
cn_reg_set(rg,0,1,v);
}
{
__auto_type cn_init_2779 = 0x1U; __auto_type bv = cn_init_2779;
__auto_type cn_init_2792 = cn_reg_get(rg,0,1); __auto_type av = cn_init_2792;
__auto_type cn_init_2810 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2810;
cn_reg_set(rg,0,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b37;
}
(f[0]=-f[0]);
}
cn_break_b37:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f=(CN_D8){f[7],f[0],f[1],f[2],f[3],f[4],f[5],f[6]});
(f[2]=cn_double(r3));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v26));
(f[1]=(f[1]*f[2]));
(f=(CN_D8){f[1],f[2],f[3],f[4],f[5],f[6],f[7],f[0]});
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)((0xfffe0025U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_3060 = cn_double(v32); __auto_type v = cn_init_3060;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3087 = cn_round(m,f[0]); __auto_type x = cn_init_3087;
__auto_type cn_init_3122 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3122;
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2011>>0))&0xffffffffULL))))))))));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v36));
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_3251 = cn_double(v35); __auto_type v = cn_init_3251;
(f[2]=(f[2]+v));
}
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_3290 = cn_double(v34); __auto_type v = cn_init_3290;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_3329 = cn_double(v33); __auto_type v = cn_init_3329;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3375 = (((uint32_t)(((((s2011>>0))&0xffULL))))); __auto_type v = cn_init_3375;
cn_reg_set(rg,0,1,v);
}
{
__auto_type cn_init_3395 = 0x1U; __auto_type bv = cn_init_3395;
__auto_type cn_init_3408 = cn_reg_get(rg,0,1); __auto_type av = cn_init_3408;
__auto_type cn_init_3426 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3426;
cn_reg_set(rg,0,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b38;
}
(f[0]=-f[0]);
}
cn_break_b38:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f=(CN_D8){f[7],f[0],f[1],f[2],f[3],f[4],f[5],f[6]});
(f[2]=cn_double(r3));
(f[1]=(f[1]+f[2]));
(f=(CN_D8){f[1],f[2],f[3],f[4],f[5],f[6],f[7],f[0]});
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)((0xfffe0029U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_3649 = cn_double(v32); __auto_type v = cn_init_3649;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3676 = cn_round(m,f[0]); __auto_type x = cn_init_3676;
__auto_type cn_init_3711 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_3711;
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2011>>0))&0xffffffffULL))))))))));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v36));
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_3840 = cn_double(v35); __auto_type v = cn_init_3840;
(f[2]=(f[2]+v));
}
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_3879 = cn_double(v34); __auto_type v = cn_init_3879;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_3918 = cn_double(v33); __auto_type v = cn_init_3918;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3964 = (((uint32_t)(((((s2011>>0))&0xffULL))))); __auto_type v = cn_init_3964;
cn_reg_set(rg,0,1,v);
}
{
__auto_type cn_init_3984 = 0x1U; __auto_type bv = cn_init_3984;
__auto_type cn_init_3997 = cn_reg_get(rg,0,1); __auto_type av = cn_init_3997;
__auto_type cn_init_4015 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_4015;
cn_reg_set(rg,0,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b39;
}
(f[0]=-f[0]);
}
cn_break_b39:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f=(CN_D8){f[7],f[0],f[1],f[2],f[3],f[4],f[5],f[6]});
(f[2]=cn_double(v28));
(f[1]=(f[1]*f[2]));
(f[1]=-f[1]);
(f[2]=cn_double(r4));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v30));
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(r4));
(f[3]=cn_double(v25));
(f[2]=(f[2]*f[3]));
(f=(CN_D8){f[2],f[3],f[4],f[5],f[6],f[7],f[0],f[1]});
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)((0xfffe0035U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_4342 = cn_double(v32); __auto_type v = cn_init_4342;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4369 = cn_round(m,f[0]); __auto_type x = cn_init_4369;
__auto_type cn_init_4404 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_4404;
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2011>>0))&0xffffffffULL))))))))));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v36));
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_4533 = cn_double(v35); __auto_type v = cn_init_4533;
(f[2]=(f[2]+v));
}
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_4572 = cn_double(v34); __auto_type v = cn_init_4572;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_4611 = cn_double(v33); __auto_type v = cn_init_4611;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_4657 = (((uint32_t)(((((s2011>>0))&0xffULL))))); __auto_type v = cn_init_4657;
cn_reg_set(rg,0,1,v);
}
{
__auto_type cn_init_4677 = 0x1U; __auto_type bv = cn_init_4677;
__auto_type cn_init_4690 = cn_reg_get(rg,0,1); __auto_type av = cn_init_4690;
__auto_type cn_init_4708 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_4708;
cn_reg_set(rg,0,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b40;
}
(f[0]=-f[0]);
}
cn_break_b40:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f=(CN_D8){f[6],f[7],f[0],f[1],f[2],f[3],f[4],f[5]});
(f[3]=cn_double(r4));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(v26));
(f[2]=(f[2]*f[3]));
(f=(CN_D8){f[2],f[3],f[4],f[5],f[6],f[7],f[0],f[1]});
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)((0xfffe003bU))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_4958 = cn_double(v32); __auto_type v = cn_init_4958;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_4985 = cn_round(m,f[0]); __auto_type x = cn_init_4985;
__auto_type cn_init_5020 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_5020;
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2011>>0))&0xffffffffULL))))))))));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v36));
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_5149 = cn_double(v35); __auto_type v = cn_init_5149;
(f[2]=(f[2]+v));
}
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_5188 = cn_double(v34); __auto_type v = cn_init_5188;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_5227 = cn_double(v33); __auto_type v = cn_init_5227;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_5273 = (((uint32_t)(((((s2011>>0))&0xffULL))))); __auto_type v = cn_init_5273;
cn_reg_set(rg,0,1,v);
}
{
__auto_type cn_init_5293 = 0x1U; __auto_type bv = cn_init_5293;
__auto_type cn_init_5306 = cn_reg_get(rg,0,1); __auto_type av = cn_init_5306;
__auto_type cn_init_5324 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5324;
cn_reg_set(rg,0,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b41;
}
(f[0]=-f[0]);
}
cn_break_b41:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f=(CN_D8){f[6],f[7],f[0],f[1],f[2],f[3],f[4],f[5]});
(f[3]=cn_double(r4));
(f[2]=(f[2]+f[3]));
(f=(CN_D8){f[2],f[3],f[4],f[5],f[6],f[7],f[0],f[1]});
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)((0xfffe003fU))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_5547 = cn_double(v32); __auto_type v = cn_init_5547;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5574 = cn_round(m,f[0]); __auto_type x = cn_init_5574;
__auto_type cn_init_5609 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_5609;
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2011>>0))&0xffffffffULL))))))))));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v36));
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_5738 = cn_double(v35); __auto_type v = cn_init_5738;
(f[2]=(f[2]+v));
}
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_5777 = cn_double(v34); __auto_type v = cn_init_5777;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_5816 = cn_double(v33); __auto_type v = cn_init_5816;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_5862 = (((uint32_t)(((((s2011>>0))&0xffULL))))); __auto_type v = cn_init_5862;
cn_reg_set(rg,0,1,v);
}
{
__auto_type cn_init_5882 = 0x1U; __auto_type bv = cn_init_5882;
__auto_type cn_init_5895 = cn_reg_get(rg,0,1); __auto_type av = cn_init_5895;
__auto_type cn_init_5913 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5913;
cn_reg_set(rg,0,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b42;
}
(f[0]=-f[0]);
}
cn_break_b42:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f=(CN_D8){f[6],f[7],f[0],f[1],f[2],f[3],f[4],f[5]});
(f[3]=cn_double(v27));
(f[2]=(f[2]*f[3]));
(f[2]=-f[2]);
(f[3]=cn_double(r5));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(v30));
(f[2]=(f[2]*f[3]));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
{
__auto_type cn_init_6141 = 0x20U; __auto_type bv = cn_init_6141;
__auto_type cn_init_6149 = rg[4]; __auto_type av = cn_init_6149;
__auto_type cn_init_6167 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_6167;
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
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_c2c95d1d71e3f677(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+136))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,0); uint64_t v17 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,8); uint64_t v18 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,16); uint64_t v19 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,24); uint64_t v20 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,32); uint64_t v21 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,40); uint64_t v22 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,48); uint64_t v23 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,56); uint64_t v24 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,64); uint64_t v25 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,72); uint64_t v26 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,80); uint64_t v27 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,88); uint64_t v28 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,96); uint64_t v29 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,104); uint64_t v30 = cn_init_409;
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
__auto_type cn_init_442 = 0xffffffe0U; __auto_type bv = cn_init_442;
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
{
__auto_type cn_init_984 = m->xmm[0][0]; uint64_t v = cn_init_984;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1043 = m->xmm[0][1]; uint64_t v = cn_init_1043;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1102 = m->xmm[1][0]; uint64_t v = cn_init_1102;
(s2013=(((s2013&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2014=(((s2014&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1151 = 0xffffffd4U; __auto_type bv = cn_init_1151;
__auto_type cn_init_1159 = rg[7]; __auto_type av = cn_init_1159;
__auto_type cn_init_1177 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1177;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1304 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1304;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1352 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1352;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1415 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1415;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1478 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1478;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1526 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1526;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1589 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1589;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1651 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1651;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1698 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1698;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1760 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1760;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1803 = cn_bits(f[2]); uint64_t v = cn_init_1803;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1861 = cn_bits(f[1]); uint64_t v = cn_init_1861;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1919 = cn_bits(f[0]); uint64_t v = cn_init_1919;
(s2013=(((s2013&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2014=(((s2014&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1968 = 0x2cU; __auto_type bv = cn_init_1968;
__auto_type cn_init_1976 = rg[7]; __auto_type av = cn_init_1976;
__auto_type cn_init_1994 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1994;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2041 = cn_double(v23); __auto_type v = cn_init_2041;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_2071_0 = sin(f[0]);
__auto_type cn_tuple_2071_1 = cos(f[0]);
__auto_type s = cn_tuple_2071_0;
__auto_type c = cn_tuple_2071_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(f[2]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2130 = cn_double(v23); __auto_type v = cn_init_2130;
(f[2]=(f[2]*v));
}
{
__auto_type cn_tuple_2160_0 = sin(f[2]);
__auto_type cn_tuple_2160_1 = cos(f[2]);
__auto_type s = cn_tuple_2160_0;
__auto_type c = cn_tuple_2160_1;
(f[2]=s);
(f[3]=c);
(fsw&=~0x0400);
}
(f[4]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2219 = cn_double(v23); __auto_type v = cn_init_2219;
(f[4]=(f[4]*v));
}
{
__auto_type cn_tuple_2249_0 = sin(f[4]);
__auto_type cn_tuple_2249_1 = cos(f[4]);
__auto_type s = cn_tuple_2249_0;
__auto_type c = cn_tuple_2249_1;
(f[4]=s);
(f[5]=c);
(fsw&=~0x0400);
}
(f[2]=(f[2]*f[5]));
(f[1]=(f[1]*f[4]));
(f[0]=(f[0]*f[3]));
(f[3]=f[2]);
(f[3]=(f[3]-f[1]));
(f[3]=(f[3]-f[0]));
{
__auto_type cn_init_2365 = cn_double(v17); __auto_type v = cn_init_2365;
(f[3]=(f[3]*v));
}
(f[3]=fabs(f[3]));
(r34=cn_bits(f[3]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))));
(f[1]=fabs(f[1]));
(f[2]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
(f[2]=fabs(f[2]));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
(f[2]=f[2]);
goto cn_break_b5;
}
cn_break_b4:;
(f[1]=f[2]);
}
cn_break_b5:;
(f[2]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[2]=fabs(f[2]));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b7;
}
(f[2]=f[2]);
goto cn_break_b8;
}
cn_break_b7:;
(f[1]=f[2]);
}
cn_break_b8:;
{
__auto_type cn_init_2760 = cn_double(v30); __auto_type v = cn_init_2760;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
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
__auto_type cn_init_2879 = cn_double(v23); __auto_type v = cn_init_2879;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_2898 = 0x0U; __auto_type bv = cn_init_2898;
__auto_type cn_init_2915 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_2915;
__auto_type cn_init_2933 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2933;
}
if(cn_cond(fl,5)){
goto cn_break_b13;
}
{
__auto_type cn_init_2957 = cn_double(v28); __auto_type v = cn_init_2957;
(f[0]=(f[0]/v));
}
}
cn_break_b13:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2988 = 0x20U; __auto_type bv = cn_init_2988;
__auto_type cn_init_2996 = rg[4]; __auto_type av = cn_init_2996;
__auto_type cn_init_3014 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3014;
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
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_c3fa8539ce08ddd1(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+168))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_cell(vm,0); uint64_t v21 = cn_init_123;
__auto_type cn_init_136 = cn_cell(vm,8); uint64_t v22 = cn_init_136;
__auto_type cn_init_149 = cn_cell(vm,16); uint64_t v23 = cn_init_149;
__auto_type cn_init_162 = cn_cell(vm,24); uint64_t v24 = cn_init_162;
__auto_type cn_init_175 = cn_cell(vm,32); uint64_t v25 = cn_init_175;
__auto_type cn_init_188 = cn_cell(vm,40); uint64_t v26 = cn_init_188;
__auto_type cn_init_201 = cn_cell(vm,48); uint64_t v27 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,56); uint64_t v28 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,64); uint64_t v29 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,72); uint64_t v30 = cn_init_240;
{
{
{
(f[0]=cn_double(r5));
{
__auto_type cn_init_272 = cn_double(v28); __auto_type v = cn_init_272;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_308 = cn_double(v29); __auto_type v = cn_init_308;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_344 = cn_double(v30); __auto_type v = cn_init_344;
(f[2]=(f[2]+v));
}
(f[3]=f[2]);
{
__auto_type cn_init_392 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_392;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_440 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_440;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_503 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_503;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_566 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_566;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_614 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_614;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_677 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_677;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_739 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_739;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_786 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_786;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_848 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_848;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(0x3ff0000000000000));
(f[1]=cn_double(r3));
(f[1]=fabs(f[1]));
(f[0]=(f[0]-f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(0x3ff0000000000000));
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
(f[0]=(f[0]-f[1]));
(r4=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
(f[0]=cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_1234 = cn_double(r3); __auto_type v = cn_init_1234;
(f[1]=(f[1]*v));
}
cn_swap(f,1,0);
{
__auto_type cn_init_1267 = cn_double(r3); __auto_type v = cn_init_1267;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1291 = cn_double(r3); __auto_type v = cn_init_1291;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r3=cn_bits(f[0]));
}
cn_break_b2:;
(f[0]=cn_double(r4));
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
(f[0]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_1528 = cn_double(r4); __auto_type v = cn_init_1528;
(f[1]=(f[1]*v));
}
cn_swap(f,1,0);
{
__auto_type cn_init_1561 = cn_double(r4); __auto_type v = cn_init_1561;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1585 = cn_double(r4); __auto_type v = cn_init_1585;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r4=cn_bits(f[0]));
}
cn_break_b4:;
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
int cn_f_c3fc393a278226c7(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+232))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_276 = cn_cell(vm,0); uint64_t v29 = cn_init_276;
__auto_type cn_init_289 = cn_cell(vm,8); uint64_t v30 = cn_init_289;
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
(f[0]=cn_double(v30));
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[4]=f[3]);
(f[4]=(f[4]+f[2]));
(f[4]=(f[4]+f[1]));
(f[4]=fabs(f[4]));
{
__auto_type cn_init_590 = cn_double(v29); __auto_type v = cn_init_590;
(f[4]=(f[4]*v));
}
(f[4]=(f[4]+f[0]));
(r3=cn_bits(f[4]));
(f[4]=f[1]);
(f[4]=(f[4]-f[3]));
(f[4]=(f[4]-f[2]));
(f[4]=fabs(f[4]));
{
__auto_type cn_init_694 = cn_double(v29); __auto_type v = cn_init_694;
(f[4]=(f[4]*v));
}
(f[4]=(f[4]+f[0]));
(r4=cn_bits(f[4]));
(f[4]=f[2]);
(f[4]=(f[4]-f[3]));
(f[4]=(f[4]-f[1]));
(f[4]=fabs(f[4]));
{
__auto_type cn_init_798 = cn_double(v29); __auto_type v = cn_init_798;
(f[4]=(f[4]*v));
}
(f[4]=(f[4]+f[0]));
(r5=cn_bits(f[4]));
(f[2]=(f[3]-f[2]));
(f[1]=(f[2]-f[1]));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_892 = cn_double(v29); __auto_type v = cn_init_892;
(f[1]=(f[1]*v));
}
(f[1]=(f[1]+f[0]));
(r6=cn_bits(f[1]));
(f[1]=cn_double(r12));
(f[2]=cn_double(r11));
(f[3]=cn_double(r10));
(f[4]=f[3]);
(f[4]=(f[4]+f[2]));
(f[4]=(f[4]+f[1]));
(f[4]=fabs(f[4]));
{
__auto_type cn_init_1032 = cn_double(v29); __auto_type v = cn_init_1032;
(f[4]=(f[4]*v));
}
(f[4]=(f[4]+f[0]));
(r10=cn_bits(f[4]));
(f[4]=f[1]);
(f[4]=(f[4]-f[3]));
(f[4]=(f[4]-f[2]));
(f[4]=fabs(f[4]));
{
__auto_type cn_init_1136 = cn_double(v29); __auto_type v = cn_init_1136;
(f[4]=(f[4]*v));
}
(f[4]=(f[4]+f[0]));
(r11=cn_bits(f[4]));
(f[4]=f[2]);
(f[4]=(f[4]-f[3]));
(f[4]=(f[4]-f[1]));
(f[4]=fabs(f[4]));
{
__auto_type cn_init_1240 = cn_double(v29); __auto_type v = cn_init_1240;
(f[4]=(f[4]*v));
}
(f[4]=(f[4]+f[0]));
(r12=cn_bits(f[4]));
(f[2]=(f[3]-f[2]));
(f[1]=(f[2]-f[1]));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_1334 = cn_double(v29); __auto_type v = cn_init_1334;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r0=cn_bits(f[0]));
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
cn_wr64(m,CN_REC+8*(0),r0);
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64(m,CN_REC+8*(10),r10);
cn_wr64(m,CN_REC+8*(11),r11);
cn_wr64(m,CN_REC+8*(12),r12);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_c4d7d73cd046fdfb(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(14)); uint64_t r14 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v29 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,8); uint64_t v30 = cn_init_221;
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
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r14));
(fsw=cn_compare(f[0],cn_double(v30)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
(f[0]=sqrt(f[0]));
(f[1]=f[0]);
{
__auto_type cn_init_531 = cn_double(v29); __auto_type v = cn_init_531;
(f[1]=(v-f[1]));
}
(f[0]=(f[1]/f[0]));
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[0]));
(r3=cn_bits(f[3]));
(f[2]=(f[2]*f[0]));
(r4=cn_bits(f[2]));
(f[0]=(f[0]*f[1]));
(r5=cn_bits(f[0]));
}
cn_break_b2:;
(f[0]=f[0]);
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
int cn_f_c509eb91a6530527(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_51;
{
{
__auto_type cn_init_60 = 0x0U; __auto_type v = cn_init_60;
(r14=(((r14&~((0xffffffffULL<<0))))|(((((((uint64_t)((v))))&0xffffffffULL))<<0))));
}
{
__auto_type cn_init_96 = 0x7fefffffU; __auto_type v = cn_init_96;
(r14=(((r14&~((0xffffffffULL<<32))))|(((((((uint64_t)((v))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_132 = 0x6433626dU; __auto_type v = cn_init_132;
(rg[0]=v);
}
{
__auto_type cn_init_146 = 0x2073722dU; __auto_type v = cn_init_146;
(rg[0]=v);
}
{
__auto_type cn_init_160 = 0x75657350U; __auto_type v = cn_init_160;
(rg[0]=v);
}
{
__auto_type cn_init_174 = 0x6c4b6f64U; __auto_type v = cn_init_174;
(rg[0]=v);
}
{
__auto_type cn_init_188 = 0x6e6965U; __auto_type v = cn_init_188;
(rg[0]=v);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001070U,r14);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_c5a3cf92aaca95a4(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_58 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_58;
__auto_type cn_init_75 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_75;
__auto_type cn_init_92 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_92;
__auto_type cn_init_109 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_109;
__auto_type cn_init_126 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_126;
__auto_type cn_init_143 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_143;
__auto_type cn_init_160 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_160;
__auto_type cn_init_173 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_173;
__auto_type cn_init_186 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_186;
__auto_type cn_init_199 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_199;
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
(f[0]=cn_double(r10));
{
__auto_type cn_init_393 = cn_double(r11); __auto_type v = cn_init_393;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_417 = cn_double(r12); __auto_type v = cn_init_417;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]-f[1]));
(f[1]=cn_double(r6));
{
__auto_type cn_init_551 = cn_double(r5); __auto_type v = cn_init_551;
(f[1]=(f[1]*v));
}
(f[1]=(f[1]+f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r10));
(f[1]=-f[1]);
{
__auto_type cn_init_628 = cn_double(r11); __auto_type v = cn_init_628;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_652 = cn_double(r12); __auto_type v = cn_init_652;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]-f[2]));
(f[2]=cn_double(r6));
{
__auto_type cn_init_786 = cn_double(r5); __auto_type v = cn_init_786;
(f[2]=(f[2]*v));
}
(f[2]=(f[2]+f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r10));
(f[2]=-f[2]);
{
__auto_type cn_init_863 = cn_double(r11); __auto_type v = cn_init_863;
(f[2]=(f[2]+v));
}
{
__auto_type cn_init_887 = cn_double(r12); __auto_type v = cn_init_887;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[3]=cn_double(r5));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r6));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]-f[3]));
(f[3]=cn_double(r3));
{
__auto_type cn_init_1021 = cn_double(r4); __auto_type v = cn_init_1021;
(f[3]=(f[3]*v));
}
(f[3]=(f[3]+f[3]));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r10));
{
__auto_type cn_init_1087 = cn_double(r11); __auto_type v = cn_init_1087;
(f[3]=(f[3]-v));
}
{
__auto_type cn_init_1111 = cn_double(r12); __auto_type v = cn_init_1111;
(f[3]=(f[3]-v));
}
(f[3]=fabs(f[3]));
(f[4]=cn_double(r5));
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]-f[4]));
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
{
__auto_type cn_init_1245 = cn_double(r4); __auto_type v = cn_init_1245;
(f[4]=(f[4]*v));
}
(f[4]=(f[4]+f[4]));
(f[3]=(f[3]+f[4]));
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
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_c5f3828c89d58fc9(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_191 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_191;
__auto_type cn_init_204 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_204;
__auto_type cn_init_217 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_217;
__auto_type cn_init_230 = cn_cell(vm,0); uint64_t v29 = cn_init_230;
__auto_type cn_init_243 = cn_cell(vm,8); uint64_t v30 = cn_init_243;
__auto_type cn_init_256 = cn_cell(vm,24); uint64_t v32 = cn_init_256;
__auto_type cn_init_269 = cn_cell(vm,32); uint64_t v33 = cn_init_269;
__auto_type cn_init_282 = cn_cell(vm,40); uint64_t v34 = cn_init_282;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_348 = 0x30U; __auto_type bv = cn_init_348;
__auto_type cn_init_356 = rg[4]; __auto_type av = cn_init_356;
__auto_type cn_init_374 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_374;
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
__auto_type cn_init_590 = cn_double(v32); __auto_type v = cn_init_590;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_626 = cn_double(v33); __auto_type v = cn_init_626;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_676 = cn_double(v34); __auto_type v = cn_init_676;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_723 = cn_double(v34); __auto_type v = cn_init_723;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_770 = cn_double(v33); __auto_type v = cn_init_770;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_806 = cn_double(v32); __auto_type v = cn_init_806;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2013));
{
__auto_type cn_init_857 = cn_double(r4); __auto_type v = cn_init_857;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(s2013));
{
__auto_type cn_init_893 = cn_double(r4); __auto_type v = cn_init_893;
(f[2]=(f[2]+v));
}
(f[2]=(f[2]*f[2]));
(f[2]=(f[2]*f[2]));
(f[2]=(f[2]*f[2]));
(s2012=cn_bits(f[2]));
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
(s2013=cn_bits(f[1]));
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
(f[0]=(f[0]*f[0]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_1097 = cn_double(r5); __auto_type v = cn_init_1097;
(f[0]=(f[0]+v));
}
(f[0]=sqrt(f[0]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1149 = cn_double(v29); __auto_type v = cn_init_1149;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1187 = cn_double(v30); __auto_type v = cn_init_1187;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1211 = cn_double(v34); __auto_type v = cn_init_1211;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1258 = cn_double(r5); __auto_type v = cn_init_1258;
(f[0]=(f[0]+v));
}
(f[0]=sqrt(f[0]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1310 = cn_double(v29); __auto_type v = cn_init_1310;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1348 = cn_double(v30); __auto_type v = cn_init_1348;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1372 = cn_double(v34); __auto_type v = cn_init_1372;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1419 = cn_double(s2012); __auto_type v = cn_init_1419;
(f[0]=(f[0]+v));
}
(f[0]=sqrt(f[0]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1471 = cn_double(v29); __auto_type v = cn_init_1471;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1509 = cn_double(v30); __auto_type v = cn_init_1509;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1556 = cn_double(r3); __auto_type v = cn_init_1556;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1592 = cn_double(r3); __auto_type v = cn_init_1592;
(f[1]=(f[1]-v));
}
(r4=cn_bits(f[1]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1650 = cn_double(v32); __auto_type v = cn_init_1650;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1686 = cn_double(v33); __auto_type v = cn_init_1686;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1737 = cn_double(v33); __auto_type v = cn_init_1737;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[2]=cn_double(r5));
{
__auto_type cn_init_1784 = cn_double(v32); __auto_type v = cn_init_1784;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r5=cn_bits(f[1]));
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
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_c692939cbb1d0771(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;
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
__auto_type cn_init_149 = rg[3]; __auto_type v = cn_init_149;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_170 = rg[6]; __auto_type v = cn_init_170;
cn_push_lu(m,rg,v);
}
{
__auto_type cn_init_191 = rg[7]; __auto_type v = cn_init_191;
cn_push_lu(m,rg,v);
}
(rg[6]=cn_rd32u(m,((uint32_t)(rg[5]+0x8U))));
(rg[7]=cn_rd32u(m,((uint32_t)(rg[6]+0x30U))));
{
__auto_type cn_init_257 = ((uint32_t)(rg[6]+0xd0U)); __auto_type a = cn_init_257;
__auto_type cn_init_267 = cn_rd32u(m,a); __auto_type v = cn_init_267;
__auto_type cn_init_274 = fl.cf; __auto_type cf = cn_init_274;
__auto_type cn_init_292 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_292;
(fl.cf=cf);
cn_wr32u(m,a,r);
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[6]+0xd0U))));
(rg[2]=rg[0]);
{
__auto_type cn_init_344 = 0xfU; __auto_type bv = cn_init_344;
__auto_type cn_init_352 = rg[2]; __auto_type av = cn_init_352;
__auto_type cn_init_370 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_370;
(rg[2]=r);
}
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xfffffff4U))));
(b=1);
}
break;
case 1:
{
{
__auto_type cn_init_414 = fl.cf; __auto_type cf = cn_init_414;
__auto_type cn_init_435 = cn_alu(&fl,Alu_Sub,rg[2],1,4); __auto_type r = cn_init_435;
(fl.cf=cf);
(rg[2]=r);
}
{
__auto_type cn_init_455 = 0x0U; __auto_type bv = cn_init_455;
__auto_type cn_init_463 = rg[2]; __auto_type av = cn_init_463;
__auto_type cn_init_481 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_481;
}
if(cn_cond(fl,14)){
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
cn_shift_reg_l(rg,&fl,Shift_Sar,0,1,4);
(steps+=1);
if((steps>limit)){
return 1;
}
(b=1);
continue;
}
break;
case 3:
{
{
__auto_type cn_init_578 = 0x1U; __auto_type bv = cn_init_578;
__auto_type cn_init_586 = rg[0]; __auto_type av = cn_init_586;
__auto_type cn_init_604 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_604;
(rg[0]=r);
}
if(cn_cond(fl,5)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=25);
continue;
}
(b=4);
}
break;
case 4:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffe8U))));
{
__auto_type cn_init_679 = 0x0U; __auto_type bv = cn_init_679;
__auto_type cn_init_687 = rg[0]; __auto_type av = cn_init_687;
__auto_type cn_init_705 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_705;
}
if(cn_cond(fl,13)){
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
{
__auto_type cn_init_753 = 0x0U; __auto_type v = cn_init_753;
(rg[0]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=8);
continue;
}
break;
case 6:
{
{
__auto_type cn_init_795 = 0x64U; __auto_type bv = cn_init_795;
__auto_type cn_init_803 = rg[0]; __auto_type av = cn_init_803;
__auto_type cn_init_821 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_821;
}
if(cn_cond(fl,14)){
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
{
__auto_type cn_init_869 = 0x64U; __auto_type v = cn_init_869;
(rg[0]=v);
}
(b=8);
}
break;
case 8:
{
(rg[7]=cn_rd32u(m,((uint32_t)(rg[7]+0xfffffff0U))));
{
__auto_type cn_init_911 = 0x1U; __auto_type bv = cn_init_911;
__auto_type cn_init_919 = rg[7]; __auto_type av = cn_init_919;
__auto_type cn_init_937 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_937;
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
__auto_type cn_init_985 = 0x1U; __auto_type v = cn_init_985;
(rg[7]=v);
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
__auto_type cn_init_1027 = 0x6U; __auto_type bv = cn_init_1027;
__auto_type cn_init_1035 = rg[7]; __auto_type av = cn_init_1035;
__auto_type cn_init_1053 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1053;
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
__auto_type cn_init_1101 = 0x6U; __auto_type v = cn_init_1101;
(rg[7]=v);
}
(b=12);
}
break;
case 12:
{
(rg[7]=((uint32_t)((((uint32_t)(rg[6]+0x48U)))+((uint32_t)(rg[7]*4)))));
{
__auto_type cn_init_1153 = 0x0U; __auto_type bv = cn_init_1153;
__auto_type cn_init_1172 = cn_rd32(m,((uint32_t)(rg[7]+0x0U))); __auto_type av = cn_init_1172;
__auto_type cn_init_1190 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1190;
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
__auto_type cn_init_1238 = 0x80000000U; __auto_type bv = cn_init_1238;
__auto_type cn_init_1246 = rg[0]; __auto_type av = cn_init_1246;
__auto_type cn_init_1264 = cn_alu(&fl,Alu_Or,av,bv,4); __auto_type r = cn_init_1264;
(rg[0]=r);
}
(b=14);
}
break;
case 14:
{
{
__auto_type cn_init_1294 = ((uint32_t)(rg[7]+0x0U)); __auto_type a = cn_init_1294;
cn_wr32(m,a,rg[0]);
}
(rg[7]=cn_rd32u(m,((uint32_t)(rg[6]+0x30U))));
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffe4U))));
{
__auto_type cn_init_1354 = 0x1U; __auto_type bv = cn_init_1354;
__auto_type cn_init_1362 = rg[0]; __auto_type av = cn_init_1362;
__auto_type cn_init_1380 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1380;
}
if(cn_cond(fl,13)){
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
__auto_type cn_init_1428 = 0x1U; __auto_type v = cn_init_1428;
(rg[0]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=18);
continue;
}
break;
case 16:
{
{
__auto_type cn_init_1470 = 0x64U; __auto_type bv = cn_init_1470;
__auto_type cn_init_1478 = rg[0]; __auto_type av = cn_init_1478;
__auto_type cn_init_1496 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1496;
}
if(cn_cond(fl,14)){
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
__auto_type cn_init_1544 = 0x64U; __auto_type v = cn_init_1544;
(rg[0]=v);
}
(b=18);
}
break;
case 18:
{
(rg[7]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffecU))));
{
__auto_type cn_init_1586 = 0x1U; __auto_type bv = cn_init_1586;
__auto_type cn_init_1594 = rg[7]; __auto_type av = cn_init_1594;
__auto_type cn_init_1612 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1612;
}
if(cn_cond(fl,13)){
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
{
__auto_type cn_init_1660 = 0x1U; __auto_type v = cn_init_1660;
(rg[7]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=22);
continue;
}
break;
case 20:
{
{
__auto_type cn_init_1702 = 0x6U; __auto_type bv = cn_init_1702;
__auto_type cn_init_1710 = rg[7]; __auto_type av = cn_init_1710;
__auto_type cn_init_1728 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1728;
}
if(cn_cond(fl,14)){
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
__auto_type cn_init_1776 = 0x6U; __auto_type v = cn_init_1776;
(rg[7]=v);
}
(b=22);
}
break;
case 22:
{
(rg[7]=((uint32_t)((((uint32_t)(rg[6]+0x48U)))+((uint32_t)(rg[7]*4)))));
{
__auto_type cn_init_1828 = 0x0U; __auto_type bv = cn_init_1828;
__auto_type cn_init_1847 = cn_rd32(m,((uint32_t)(rg[7]+0x0U))); __auto_type av = cn_init_1847;
__auto_type cn_init_1865 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1865;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=24);
continue;
}
(b=23);
}
break;
case 23:
{
{
__auto_type cn_init_1913 = 0x80000000U; __auto_type bv = cn_init_1913;
__auto_type cn_init_1921 = rg[0]; __auto_type av = cn_init_1921;
__auto_type cn_init_1939 = cn_alu(&fl,Alu_Or,av,bv,4); __auto_type r = cn_init_1939;
(rg[0]=r);
}
(b=24);
}
break;
case 24:
{
{
__auto_type cn_init_1969 = ((uint32_t)(rg[7]+0x0U)); __auto_type a = cn_init_1969;
cn_wr32(m,a,rg[0]);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=46);
continue;
}
break;
case 25:
{
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffe8U))));
{
__auto_type cn_init_2037 = 0x0U; __auto_type bv = cn_init_2037;
__auto_type cn_init_2045 = rg[0]; __auto_type av = cn_init_2045;
__auto_type cn_init_2063 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2063;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=27);
continue;
}
(b=26);
}
break;
case 26:
{
{
__auto_type cn_init_2111 = 0x0U; __auto_type v = cn_init_2111;
(rg[0]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=29);
continue;
}
break;
case 27:
{
{
__auto_type cn_init_2153 = 0x64U; __auto_type bv = cn_init_2153;
__auto_type cn_init_2161 = rg[0]; __auto_type av = cn_init_2161;
__auto_type cn_init_2179 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2179;
}
if(cn_cond(fl,14)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=29);
continue;
}
(b=28);
}
break;
case 28:
{
{
__auto_type cn_init_2227 = 0x64U; __auto_type v = cn_init_2227;
(rg[0]=v);
}
(b=29);
}
break;
case 29:
{
(rg[7]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffecU))));
{
__auto_type cn_init_2269 = 0x1U; __auto_type bv = cn_init_2269;
__auto_type cn_init_2277 = rg[7]; __auto_type av = cn_init_2277;
__auto_type cn_init_2295 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2295;
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
__auto_type cn_init_2343 = 0x1U; __auto_type v = cn_init_2343;
(rg[7]=v);
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
__auto_type cn_init_2385 = 0x6U; __auto_type bv = cn_init_2385;
__auto_type cn_init_2393 = rg[7]; __auto_type av = cn_init_2393;
__auto_type cn_init_2411 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2411;
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
__auto_type cn_init_2459 = 0x6U; __auto_type v = cn_init_2459;
(rg[7]=v);
}
(b=33);
}
break;
case 33:
{
(rg[7]=((uint32_t)((((uint32_t)(rg[6]+0x48U)))+((uint32_t)(rg[7]*4)))));
{
__auto_type cn_init_2511 = 0x0U; __auto_type bv = cn_init_2511;
__auto_type cn_init_2530 = cn_rd32(m,((uint32_t)(rg[7]+0x0U))); __auto_type av = cn_init_2530;
__auto_type cn_init_2548 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2548;
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
__auto_type cn_init_2596 = 0x80000000U; __auto_type bv = cn_init_2596;
__auto_type cn_init_2604 = rg[0]; __auto_type av = cn_init_2604;
__auto_type cn_init_2622 = cn_alu(&fl,Alu_Or,av,bv,4); __auto_type r = cn_init_2622;
(rg[0]=r);
}
(b=35);
}
break;
case 35:
{
{
__auto_type cn_init_2652 = ((uint32_t)(rg[7]+0x0U)); __auto_type a = cn_init_2652;
cn_wr32(m,a,rg[0]);
}
(rg[7]=cn_rd32u(m,((uint32_t)(rg[6]+0x30U))));
(rg[0]=cn_rd32u(m,((uint32_t)(rg[7]+0xffffffe4U))));
{
__auto_type cn_init_2712 = 0x1U; __auto_type bv = cn_init_2712;
__auto_type cn_init_2720 = rg[0]; __auto_type av = cn_init_2720;
__auto_type cn_init_2738 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2738;
}
if(cn_cond(fl,13)){
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
__auto_type cn_init_2786 = 0x1U; __auto_type v = cn_init_2786;
(rg[0]=v);
}
(steps+=1);
if((steps>limit)){
return 1;
}
(b=39);
continue;
}
break;
case 37:
{
{
__auto_type cn_init_2828 = 0x64U; __auto_type bv = cn_init_2828;
__auto_type cn_init_2836 = rg[0]; __auto_type av = cn_init_2836;
__auto_type cn_init_2854 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2854;
}
if(cn_cond(fl,14)){
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
__auto_type cn_init_2902 = 0x64U; __auto_type v = cn_init_2902;
(rg[0]=v);
}
(b=39);
}
break;
case 39:
{
(rg[7]=cn_rd32u(m,((uint32_t)(rg[7]+0xfffffff0U))));
{
__auto_type cn_init_2944 = 0x1U; __auto_type bv = cn_init_2944;
__auto_type cn_init_2952 = rg[7]; __auto_type av = cn_init_2952;
__auto_type cn_init_2970 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2970;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=41);
continue;
}
(b=40);
}
break;
case 40:
{
{
__auto_type cn_init_3018 = 0x1U; __auto_type v = cn_init_3018;
(rg[7]=v);
}
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
{
__auto_type cn_init_3060 = 0x6U; __auto_type bv = cn_init_3060;
__auto_type cn_init_3068 = rg[7]; __auto_type av = cn_init_3068;
__auto_type cn_init_3086 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3086;
}
if(cn_cond(fl,14)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=43);
continue;
}
(b=42);
}
break;
case 42:
{
{
__auto_type cn_init_3134 = 0x6U; __auto_type v = cn_init_3134;
(rg[7]=v);
}
(b=43);
}
break;
case 43:
{
(rg[7]=((uint32_t)((((uint32_t)(rg[6]+0x48U)))+((uint32_t)(rg[7]*4)))));
{
__auto_type cn_init_3186 = 0x0U; __auto_type bv = cn_init_3186;
__auto_type cn_init_3205 = cn_rd32(m,((uint32_t)(rg[7]+0x0U))); __auto_type av = cn_init_3205;
__auto_type cn_init_3223 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3223;
}
if(cn_cond(fl,13)){
(steps+=1);
if((steps>limit)){
return 1;
}
(b=45);
continue;
}
(b=44);
}
break;
case 44:
{
{
__auto_type cn_init_3271 = 0x80000000U; __auto_type bv = cn_init_3271;
__auto_type cn_init_3279 = rg[0]; __auto_type av = cn_init_3279;
__auto_type cn_init_3297 = cn_alu(&fl,Alu_Or,av,bv,4); __auto_type r = cn_init_3297;
(rg[0]=r);
}
(b=45);
}
break;
case 45:
{
{
__auto_type cn_init_3327 = ((uint32_t)(rg[7]+0x0U)); __auto_type a = cn_init_3327;
cn_wr32(m,a,rg[0]);
}
(b=46);
}
break;
case 46:
{
{
__auto_type cn_init_3362 = cn_pop_lu(m,rg); __auto_type v = cn_init_3362;
(rg[7]=v);
}
{
__auto_type cn_init_3383 = cn_pop_lu(m,rg); __auto_type v = cn_init_3383;
(rg[6]=v);
}
{
__auto_type cn_init_3404 = cn_pop_lu(m,rg); __auto_type v = cn_init_3404;
(rg[3]=v);
}
{
__auto_type cn_init_3425 = cn_pop_lu(m,rg); __auto_type v = cn_init_3425;
(rg[2]=v);
}
{
__auto_type cn_init_3446 = cn_pop_lu(m,rg); __auto_type v = cn_init_3446;
(rg[0]=v);
}
{
__auto_type cn_init_3467 = cn_pop_lu(m,rg); __auto_type v = cn_init_3467;
(rg[5]=v);
}
__auto_type cn_init_3487 = cn_pop_lu(m,rg); __auto_type r = cn_init_3487;
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
int cn_f_c6e2b756c84264a4(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+240))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v30 = cn_init_208;
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
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_405 = 0x0U; __auto_type bv = cn_init_405;
__auto_type cn_init_422 = (((uint32_t)(((((v30>>32))&0xffffffffULL))))); __auto_type av = cn_init_422;
__auto_type cn_init_440 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_440;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(f[0]=cn_double(r10));
(f[1]=cn_double(r12));
(r10=cn_bits(f[1]));
(r12=cn_bits(f[0]));
}
cn_break_b2:;
(f[0]=cn_double(r5));
(f[1]=cn_double(r3));
(r5=cn_bits(f[1]));
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
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64(m,CN_REC+8*(10),r10);
cn_wr64(m,CN_REC+8*(12),r12);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_c77cd40678b1b679(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_47 = 0ULL; __auto_type steps = cn_init_47;
__auto_type cn_init_52 = max_steps; __auto_type limit = cn_init_52;
__auto_type cn_init_62 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+240))); unsigned char * vm = cn_init_82;
__auto_type cn_init_99 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_99;
__auto_type cn_init_116 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_116;
__auto_type cn_init_133 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_133;
__auto_type cn_init_150 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_150;
__auto_type cn_init_167 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_167;
__auto_type cn_init_184 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_184;
__auto_type cn_init_201 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007e80U); uint64_t s2000 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007e88U); uint64_t s2001 = cn_init_227;
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
__auto_type cn_init_383 = cn_cell(vm,0); uint64_t v30 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,56); uint64_t v37 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,64); uint64_t v38 = cn_init_409;
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
__auto_type cn_init_487 = 0x60U; __auto_type bv = cn_init_487;
__auto_type cn_init_495 = rg[4]; __auto_type av = cn_init_495;
__auto_type cn_init_513 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_513;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2001=(((s2001&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2001=(((s2001&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2000=(((s2000&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
{
__auto_type cn_init_724 = (((uint32_t)(((((v30>>32))&0xffULL))))); __auto_type v = cn_init_724;
cn_reg_set(rg,4,1,v);
}
{
__auto_type cn_init_744 = 0x7U; __auto_type bv = cn_init_744;
__auto_type cn_init_757 = cn_reg_get(rg,4,1); __auto_type av = cn_init_757;
__auto_type cn_init_775 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_775;
cn_reg_set(rg,4,1,r);
}
cn_continue_l1:;
{
{
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=f[0]);
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
cn_shift_reg_l(rg,&fl,Shift_Shl,0,16,4);
(fsw=cn_compare(f[1],cn_double(v38)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b8;
}
cn_shift_reg_l(rg,&fl,Shift_Shr,0,16,4);
(f[1]=sqrt(f[1]));
(s2005=cn_bits(f[1]));
(f[2]=cn_double(r5));
(f[1]=(f[2]/f[1]));
(s2013=cn_bits(f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1119 = cn_double(r4); __auto_type v = cn_init_1119;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_1143 = cn_double(r3); __auto_type v = cn_init_1143;
(f[0]=(f[0]/v));
}
(s2012=cn_bits(f[0]));
(f[0]=(f[0]*f[0]));
(s2009=cn_bits(f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[1]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_1270 = cn_double(s2013); __auto_type v = cn_init_1270;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_1306 = cn_double(s2013); __auto_type v = cn_init_1306;
(f[2]=(f[2]-v));
}
(f[1]=(f[2]/f[1]));
(f[1]=sqrt(f[1]));
(f[0]=(f[0]*f[1]));
(f[1]=f[0]);
(f[1]=(f[1]+f[1]));
{
__auto_type cn_init_1399 = cn_double(s2012); __auto_type v = cn_init_1399;
(f[1]=(f[1]*v));
}
(r3=cn_bits(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_1446 = cn_double(s2009); __auto_type v = cn_init_1446;
(f[1]=(f[1]-v));
}
(f[0]=(f[0]*f[1]));
(r4=cn_bits(f[0]));
{
__auto_type cn_init_1503 = (((uint32_t)(((((v30>>0))&0xffULL))))); __auto_type v = cn_init_1503;
cn_reg_set(rg,0,1,v);
}
{
__auto_type cn_init_1523 = 0x7U; __auto_type bv = cn_init_1523;
__auto_type cn_init_1536 = cn_reg_get(rg,0,1); __auto_type av = cn_init_1536;
__auto_type cn_init_1554 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1554;
cn_reg_set(rg,0,1,r);
}
cn_continue_l3:;
{
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
cn_shift_reg_l(rg,&fl,Shift_Shl,0,16,4);
(fsw=cn_compare(f[0],cn_double(v38)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b9;
}
cn_shift_reg_l(rg,&fl,Shift_Shr,0,16,4);
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=-f[0]);
(f[1]=cn_double(s2011));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(s2011));
(f[2]=cn_double(r3));
{
__auto_type cn_init_1878 = cn_double(v37); __auto_type v = cn_init_1878;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]-f[2]));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(s2011));
(f[2]=cn_double(r3));
{
__auto_type cn_init_1983 = cn_double(v37); __auto_type v = cn_init_1983;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]-f[2]));
(f[0]=(f[0]*f[1]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[1]=cn_double(s2011));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]-f[2]));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(s2011));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(s2011));
{
__auto_type cn_init_2180 = cn_double(v37); __auto_type v = cn_init_2180;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r4));
{
__auto_type cn_init_2231 = cn_double(v37); __auto_type v = cn_init_2231;
(f[2]=(f[2]*v));
}
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(s2011));
(f[1]=cn_double(r4));
{
__auto_type cn_init_2362 = cn_double(v37); __auto_type v = cn_init_2362;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2011));
(f[2]=cn_double(r4));
{
__auto_type cn_init_2452 = cn_double(v37); __auto_type v = cn_init_2452;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(v37));
(f[0]=(f[1]/f[0]));
(f[1]=f[0]);
{
__auto_type cn_init_2585 = cn_double(s2012); __auto_type v = cn_init_2585;
(f[1]=(f[1]*v));
}
(r3=cn_bits(f[1]));
{
__auto_type cn_init_2620 = cn_double(s2013); __auto_type v = cn_init_2620;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2005));
(f[0]=(f[0]*f[0]));
(s2005=cn_bits(f[0]));
{
__auto_type cn_init_2696 = cn_reg_get(rg,0,1); __auto_type v = cn_init_2696;
__auto_type cn_init_2703 = fl.cf; __auto_type cf = cn_init_2703;
__auto_type cn_init_2721 = cn_alu(&fl,Alu_Sub,v,1,1); __auto_type r = cn_init_2721;
(fl.cf=cf);
cn_reg_set(rg,0,1,r);
}
if(cn_cond(fl,15)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l3;
}
goto cn_break_b5;
}
goto cn_continue_l3;
cn_break_l3:;
}
cn_break_b5:;
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(s2006=cn_bits(f[0]));
(f[0]=sqrt(f[0]));
(s2011=cn_bits(f[0]));
{
__auto_type cn_init_2892 = cn_double(r4); __auto_type v = cn_init_2892;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2916 = cn_double(r3); __auto_type v = cn_init_2916;
(f[0]=(f[0]/v));
}
(s2012=cn_bits(f[0]));
(f[0]=(f[0]*f[0]));
(s2009=cn_bits(f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(s2010=cn_bits(f[0]));
(f[1]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_3054 = cn_double(s2009); __auto_type v = cn_init_3054;
(f[1]=(f[1]-v));
}
(f[0]=(f[0]*f[1]));
(s2007=cn_bits(f[0]));
(f[0]=cn_double(s2012));
(f[0]=(f[0]+f[0]));
{
__auto_type cn_init_3131 = cn_double(s2010); __auto_type v = cn_init_3131;
(f[0]=(f[0]*v));
}
(s2008=cn_bits(f[0]));
(f[0]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_3178 = cn_double(s2006); __auto_type v = cn_init_3178;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(v37));
(f[0]=(f[1]/f[0]));
(s2009=cn_bits(f[0]));
{
__auto_type cn_init_3240 = cn_double(s2011); __auto_type v = cn_init_3240;
(f[0]=(f[0]*v));
}
(s2010=cn_bits(f[0]));
(f[0]=cn_double(s2005));
{
__auto_type cn_init_3287 = cn_double(s2008); __auto_type v = cn_init_3287;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3311 = cn_double(s2010); __auto_type v = cn_init_3311;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2005));
{
__auto_type cn_init_3347 = cn_double(s2007); __auto_type v = cn_init_3347;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3371 = cn_double(s2010); __auto_type v = cn_init_3371;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2009));
(f[3]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]-f[3]));
{
__auto_type cn_init_3434 = cn_double(s2005); __auto_type v = cn_init_3434;
(f[2]=(f[2]*v));
}
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
{
__auto_type cn_init_3494 = cn_reg_get(rg,4,1); __auto_type v = cn_init_3494;
__auto_type cn_init_3501 = fl.cf; __auto_type cf = cn_init_3501;
__auto_type cn_init_3519 = cn_alu(&fl,Alu_Sub,v,1,1); __auto_type r = cn_init_3519;
(fl.cf=cf);
cn_reg_set(rg,4,1,r);
}
{
__auto_type cn_init_3545 = 0x0U; __auto_type bv = cn_init_3545;
__auto_type cn_init_3558 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3558;
__auto_type cn_init_3576 = cn_alu(&fl,Alu_Cmp,av,bv,1); __auto_type r = cn_init_3576;
}
if(cn_cond(fl,15)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l1;
}
goto cn_break_b6;
}
goto cn_continue_l1;
cn_break_l1:;
}
cn_break_b6:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_3635 = cn_double(r10); __auto_type v = cn_init_3635;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_3671 = cn_double(r11); __auto_type v = cn_init_3671;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_3707 = cn_double(r12); __auto_type v = cn_init_3707;
(f[2]=(f[2]+v));
}
goto cn_break_b7;
}
cn_break_b8:;
(f[1]=f[1]);
}
cn_break_b9:;
(f[0]=f[0]);
(f[0]=cn_double(v38));
(f[1]=f[0]);
(f[2]=f[1]);
}
cn_break_b7:;
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s2000>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2001>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2001>>32))&0xffffffffULL)))));
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
cn_wr64u(m,0x10007e80U,s2000);
cn_wr64u(m,0x10007e88U,s2001);
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
int cn_f_c7afd221a296d6e4(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_47 = 0ULL; __auto_type steps = cn_init_47;
__auto_type cn_init_52 = max_steps; __auto_type limit = cn_init_52;
__auto_type cn_init_62 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+240))); unsigned char * vm = cn_init_82;
__auto_type cn_init_99 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_99;
__auto_type cn_init_116 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_116;
__auto_type cn_init_133 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_133;
__auto_type cn_init_146 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_146;
__auto_type cn_init_159 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_159;
__auto_type cn_init_172 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_172;
__auto_type cn_init_185 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_185;
__auto_type cn_init_198 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_198;
__auto_type cn_init_211 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_211;
__auto_type cn_init_224 = cn_cell(vm,0); uint64_t v30 = cn_init_224;
__auto_type cn_init_237 = cn_cell(vm,16); uint64_t v32 = cn_init_237;
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_306 = 0x30U; __auto_type bv = cn_init_306;
__auto_type cn_init_314 = rg[4]; __auto_type av = cn_init_314;
__auto_type cn_init_332 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_332;
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
__auto_type cn_init_548 = cn_double(v30); __auto_type v = cn_init_548;
(f[0]=(f[0]/v));
}
(s2013=cn_bits(f[0]));
(f[0]=(f[0]+f[0]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[0]=atan2(f[0],f[1]));
(f[0]=fabs(f[0]));
cn_continue_l1:;
{
(fsw=cn_compare(f[0],cn_double(s2013)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_703 = 0x41U; __auto_type bv = cn_init_703;
__auto_type cn_init_716 = cn_reg_get(rg,4,1); __auto_type av = cn_init_716;
__auto_type cn_init_734 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_734;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,15)){
goto cn_break_b3;
}
{
__auto_type cn_init_771 = cn_double(s2012); __auto_type v = cn_init_771;
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
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[1]=f[0]);
{
__auto_type cn_init_874 = cn_double(r4); __auto_type v = cn_init_874;
(f[1]=(f[1]*v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_909 = cn_double(r5); __auto_type v = cn_init_909;
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
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_c8b3802efdcf5a9b(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+208))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_122;
__auto_type cn_init_135 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_135;
__auto_type cn_init_148 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_148;
__auto_type cn_init_161 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_161;
__auto_type cn_init_174 = cn_cell(vm,0); uint64_t v26 = cn_init_174;
__auto_type cn_init_187 = cn_cell(vm,8); uint64_t v27 = cn_init_187;
__auto_type cn_init_200 = cn_cell(vm,16); uint64_t v28 = cn_init_200;
__auto_type cn_init_213 = cn_cell(vm,24); uint64_t v29 = cn_init_213;
__auto_type cn_init_226 = cn_cell(vm,32); uint64_t v30 = cn_init_226;
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
(f[1]=cn_double(v26));
(f[0]=(f[0]*f[1]));
(f[0]=sin(f[0]));
(fsw&=~0x0400);
(f[1]=cn_double(r4));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v27));
(f[0]=(f[0]*f[1]));
(f[0]=sin(f[0]));
(fsw&=~0x0400);
(f[1]=cn_double(r4));
(f[0]=(f[0]+f[1]));
(f[0]=sin(f[0]));
(fsw&=~0x0400);
(f[1]=cn_double(v29));
(f[0]=(f[0]*f[1]));
(f[0]=-f[0]);
(f[1]=cn_double(r3));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v30));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(r3));
(f[2]=cn_double(v26));
(f[1]=(f[1]*f[2]));
(f[1]=sin(f[1]));
(fsw&=~0x0400);
(f[2]=cn_double(r3));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v27));
(f[1]=(f[1]*f[2]));
(f[1]=sin(f[1]));
(fsw&=~0x0400);
(f[2]=cn_double(r3));
(f[1]=(f[1]+f[2]));
(f[1]=sin(f[1]));
(fsw&=~0x0400);
(f[2]=cn_double(v28));
(f[1]=(f[1]*f[2]));
(f[1]=-f[1]);
(f[2]=cn_double(r4));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v30));
(f[1]=(f[1]*f[2]));
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
int cn_f_c9799e0c0df9ea53(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_203 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_242;
__auto_type cn_init_255 = cn_cell(vm,0); uint64_t v27 = cn_init_255;
__auto_type cn_init_268 = cn_cell(vm,8); uint64_t v28 = cn_init_268;
__auto_type cn_init_281 = cn_cell(vm,16); uint64_t v29 = cn_init_281;
__auto_type cn_init_294 = cn_cell(vm,24); uint64_t v30 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,40); uint64_t v32 = cn_init_307;
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
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_804 = cn_double(v32); __auto_type v = cn_init_804;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[2]));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(r4));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_992 = cn_double(v32); __auto_type v = cn_init_992;
(f[2]=(f[2]+v));
}
(f[1]=(f[1]/f[2]));
(f[1]=(f[1]*f[0]));
(f[2]=cn_double(r3));
(f[2]=fabs(f[2]));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_1087 = cn_double(v30); __auto_type v = cn_init_1087;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1111 = cn_double(r10); __auto_type v = cn_init_1111;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_1147 = cn_double(r4); __auto_type v = cn_init_1147;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r3));
(f[3]=fabs(f[3]));
(f[2]=(f[2]*f[3]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[3]));
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_1281 = cn_double(v32); __auto_type v = cn_init_1281;
(f[3]=(f[3]+v));
}
(f[2]=(f[2]/f[3]));
(f[2]=(f[2]*f[0]));
{
__auto_type cn_init_1335 = cn_double(v29); __auto_type v = cn_init_1335;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1359 = cn_double(r11); __auto_type v = cn_init_1359;
(f[2]=(f[2]+v));
}
(f[3]=cn_double(r5));
(f[4]=cn_double(r3));
(f[4]=(f[4]*f[4]));
(f[5]=cn_double(r4));
(f[5]=(f[5]*f[5]));
(f[6]=cn_double(r5));
(f[6]=(f[6]*f[6]));
(f[5]=(f[5]+f[6]));
(f[4]=(f[4]+f[5]));
(f[4]=sqrt(f[4]));
(f[3]=(f[3]*f[4]));
{
__auto_type cn_init_1535 = cn_double(v28); __auto_type v = cn_init_1535;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r12));
(f[4]=fabs(f[4]));
{
__auto_type cn_init_1585 = cn_double(v27); __auto_type v = cn_init_1585;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
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
int cn_f_c9a4c49456635bcd(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[4]=cn_double(v16));
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(v17));
(f[2]=(f[2]+f[4]));
(f[4]=cn_double(v15));
(f[1]=(f[1]+f[4]));
(f[4]=cn_double(v14));
(f[0]=(f[0]+f[4]));
{
__auto_type cn_init_1515 = 0x28U; __auto_type bv = cn_init_1515;
__auto_type cn_init_1523 = rg[7]; __auto_type av = cn_init_1523;
__auto_type cn_init_1541 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_1541;
(rg[7]=r);
}
(f[4]=f[3]);
{
__auto_type cn_init_1584 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1584;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1632 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1632;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1695 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1695;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1758 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1758;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r3=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_1832 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1832;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1880 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1880;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_1943 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1943;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2006 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2006;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r4=cn_bits(f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_2080 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2080;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_2128 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2128;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
{
__auto_type cn_init_2191 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2191;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2254 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2254;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(r5=cn_bits(f[4]));
{
__auto_type cn_init_2318 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2318;
(f[3]=(f[3]*v));
}
cn_swap(f,3,2);
{
__auto_type cn_init_2365 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2365;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
cn_swap(f,2,1);
{
__auto_type cn_init_2427 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2427;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
cn_swap(f,1,0);
{
__auto_type cn_init_2489 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2489;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r6=cn_bits(f[0]));
{
__auto_type cn_init_2534 = 0x28U; __auto_type bv = cn_init_2534;
__auto_type cn_init_2542 = rg[7]; __auto_type av = cn_init_2542;
__auto_type cn_init_2560 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2560;
(rg[7]=r);
}
(f[0]=cn_double(r6));
{
__auto_type cn_init_2591 = cn_double(v14); __auto_type v = cn_init_2591;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_2627 = cn_double(v15); __auto_type v = cn_init_2627;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(r4));
{
__auto_type cn_init_2663 = cn_double(v17); __auto_type v = cn_init_2663;
(f[2]=(f[2]-v));
}
(f[3]=cn_double(r3));
{
__auto_type cn_init_2699 = cn_double(v16); __auto_type v = cn_init_2699;
(f[3]=(f[3]-v));
}
(f[4]=cn_double(v30));
(f[5]=f[4]);
{
__auto_type cn_init_2745 = cn_double(r36); __auto_type v = cn_init_2745;
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
int cn_f_ca112d82bc2dc67f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_58 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_58;
__auto_type cn_init_75 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_75;
__auto_type cn_init_88 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_88;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[1]=atan2(f[1],f[2]));
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
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_ca35300610e09d04(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+144))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001010U); uint64_t r2 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_175;
__auto_type cn_init_188 = cn_cell(vm,0); uint64_t v18 = cn_init_188;
__auto_type cn_init_201 = cn_cell(vm,8); uint64_t v19 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,16); uint64_t v20 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,24); uint64_t v21 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,32); uint64_t v22 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,40); uint64_t v23 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,48); uint64_t v24 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,56); uint64_t v25 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,64); uint64_t v26 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,72); uint64_t v27 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,80); uint64_t v28 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,88); uint64_t v29 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,96); uint64_t v30 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,104); uint64_t v31 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,112); uint64_t v32 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,120); uint64_t v33 = cn_init_383;
{
{
{
(m->xmm[0]=(CN_U2){r4,r5});
{
__auto_type cn_init_413 = r3; uint64_t s = cn_init_413;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_443 = (CN_U2){v26,v27}; CN_U2 s = cn_init_443;
__auto_type cn_init_453 = m->xmm[0]; __auto_type a = cn_init_453;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_523 = v26; uint64_t s = cn_init_523;
__auto_type cn_init_536 = m->xmm[1][0]; __auto_type a = cn_init_536;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_583 = (CN_U2){v24,v25}; CN_U2 s = cn_init_583;
__auto_type cn_init_593 = m->xmm[0]; __auto_type a = cn_init_593;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_663 = v23; uint64_t s = cn_init_663;
__auto_type cn_init_676 = m->xmm[1][0]; __auto_type a = cn_init_676;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_713 = 0x0U; __auto_type bv = cn_init_713;
__auto_type cn_init_730 = (((uint32_t)(((((v20>>32))&0xffffffffULL))))); __auto_type av = cn_init_730;
__auto_type cn_init_748 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_748;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_769 = r32; uint64_t s = cn_init_769;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_791 = v26; uint64_t s = cn_init_791;
__auto_type cn_init_804 = m->xmm[5][0]; __auto_type a = cn_init_804;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r4=m->xmm[0][0]);
(r5=m->xmm[0][1]);
(r3=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(m->xmm[4]=m->xmm[1]);
{
__auto_type cn_init_915 = m->xmm[0]; CN_U2 s = cn_init_915;
__auto_type cn_init_925 = m->xmm[0]; __auto_type a = cn_init_925;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_1003 = (CN_U2){v32,v33}; CN_U2 s = cn_init_1003;
__auto_type cn_init_1013 = m->xmm[1]; __auto_type a = cn_init_1013;
(m->xmm[1]=(CN_U2){(a[0]&s[0]),(a[1]&s[1])});
}
{
__auto_type cn_init_1060 = m->xmm[0]; CN_U2 s = cn_init_1060;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_1153 = v28; uint64_t s = cn_init_1153;
__auto_type cn_init_1166 = m->xmm[1][0]; __auto_type a = cn_init_1166;
(m->xmm[1][0]=cn_bits(((cn_double(a)-cn_double(s)))));
}
{
__auto_type cn_init_1213 = m->xmm[2][0]; uint64_t s = cn_init_1213;
__auto_type cn_init_1226 = m->xmm[0][0]; __auto_type a = cn_init_1226;
(m->xmm[0][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_1265 = v28; uint64_t s = cn_init_1265;
__auto_type cn_init_1278 = m->xmm[3][0]; __auto_type a = cn_init_1278;
(m->xmm[3][0]=cn_bits(({__auto_type cn_tuple_1312_0 = cn_double(a);
__auto_type cn_tuple_1312_1 = cn_double(s);
__auto_type p = cn_tuple_1312_0;
__auto_type q = cn_tuple_1312_1; (((p<q))?(({p;})):(({q;})));})));
}
{
__auto_type cn_init_1338 = v21; uint64_t s = cn_init_1338;
__auto_type cn_init_1351 = m->xmm[4][0]; __auto_type a = cn_init_1351;
(m->xmm[4][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_1398 = m->xmm[3][0]; uint64_t s = cn_init_1398;
__auto_type cn_init_1411 = m->xmm[3][0]; __auto_type a = cn_init_1411;
(m->xmm[3][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_1458 = m->xmm[0][0]; uint64_t s = cn_init_1458;
(m->xmm[0][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_1492 = v18; uint64_t s = cn_init_1492;
(m->xmm[2]=(CN_U2){s,0});
}
{
__auto_type cn_init_1514 = v22; uint64_t s = cn_init_1514;
__auto_type cn_init_1527 = m->xmm[3][0]; __auto_type a = cn_init_1527;
(m->xmm[3][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_1574 = m->xmm[0][0]; uint64_t s = cn_init_1574;
__auto_type cn_init_1587 = m->xmm[2][0]; __auto_type a = cn_init_1587;
(m->xmm[2][0]=cn_bits(((cn_double(a)-cn_double(s)))));
}
{
__auto_type cn_init_1626 = v30; uint64_t s = cn_init_1626;
__auto_type cn_init_1639 = m->xmm[0][0]; __auto_type a = cn_init_1639;
(m->xmm[0][0]=cn_bits(((cn_double(a)-cn_double(s)))));
}
{
__auto_type cn_init_1686 = m->xmm[3][0]; uint64_t s = cn_init_1686;
__auto_type cn_init_1699 = m->xmm[2][0]; __auto_type a = cn_init_1699;
(m->xmm[2][0]=cn_bits(((cn_double(a)-cn_double(s)))));
}
{
__auto_type cn_init_1746 = m->xmm[3][0]; uint64_t s = cn_init_1746;
__auto_type cn_init_1759 = m->xmm[0][0]; __auto_type a = cn_init_1759;
(m->xmm[0][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_1806 = m->xmm[4][0]; uint64_t s = cn_init_1806;
__auto_type cn_init_1819 = m->xmm[2][0]; __auto_type a = cn_init_1819;
(m->xmm[2][0]=cn_bits(((cn_double(a)-cn_double(s)))));
}
{
__auto_type cn_init_1866 = m->xmm[4][0]; uint64_t s = cn_init_1866;
__auto_type cn_init_1879 = m->xmm[0][0]; __auto_type a = cn_init_1879;
(m->xmm[0][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_1926 = m->xmm[2][0]; uint64_t s = cn_init_1926;
__auto_type cn_init_1939 = m->xmm[0][0]; __auto_type a = cn_init_1939;
(m->xmm[0][0]=cn_bits(({__auto_type cn_tuple_1973_0 = cn_double(a);
__auto_type cn_tuple_1973_1 = cn_double(s);
__auto_type p = cn_tuple_1973_0;
__auto_type q = cn_tuple_1973_1; (((p>q))?(({p;})):(({q;})));})));
}
{
__auto_type cn_init_2007 = m->xmm[1][0]; uint64_t s = cn_init_2007;
__auto_type cn_init_2020 = m->xmm[0][0]; __auto_type a = cn_init_2020;
(m->xmm[0][0]=cn_bits(({__auto_type cn_tuple_2054_0 = cn_double(a);
__auto_type cn_tuple_2054_1 = cn_double(s);
__auto_type p = cn_tuple_2054_0;
__auto_type q = cn_tuple_2054_1; (((p>q))?(({p;})):(({q;})));})));
}
{
__auto_type cn_init_2078 = 0x0U; __auto_type bv = cn_init_2078;
__auto_type cn_init_2095 = (((uint32_t)(((((v20>>32))&0xffffffffULL))))); __auto_type av = cn_init_2095;
__auto_type cn_init_2113 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2113;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
{
__auto_type cn_init_2134 = v26; uint64_t s = cn_init_2134;
__auto_type cn_init_2147 = m->xmm[0][0]; __auto_type a = cn_init_2147;
(m->xmm[0][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
}
cn_break_b4:;
(rg[0]=((uint32_t)(((((v20>>0))&0xffffffffULL)))));
(r14=m->xmm[0][0]);
{
__auto_type cn_init_2214 = 0x3U; __auto_type bv = cn_init_2214;
__auto_type cn_init_2222 = rg[0]; __auto_type av = cn_init_2222;
__auto_type cn_init_2240 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2240;
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
__auto_type cn_init_2488 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2488;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2526 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2526;
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
int cn_f_ca6a94630e0cdf3e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[1]=(f[1]+f[2]));
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
(f[1]=(f[1]+f[2]));
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
(f[1]=(f[1]+f[2]));
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
(f[2]=(f[2]+f[3]));
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
int cn_f_ca985984466a6b17(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+136))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_190;
__auto_type cn_init_207 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_207;
__auto_type cn_init_224 = cn_rd64(m,CN_REC+8*(26)); uint64_t r26 = cn_init_224;
__auto_type cn_init_241 = cn_rd64(m,CN_REC+8*(36)); uint64_t r36 = cn_init_241;
__auto_type cn_init_254 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_254;
__auto_type cn_init_267 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_267;
__auto_type cn_init_280 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_280;
__auto_type cn_init_293 = cn_cell(vm,0); uint64_t v17 = cn_init_293;
__auto_type cn_init_306 = cn_cell(vm,8); uint64_t v18 = cn_init_306;
__auto_type cn_init_319 = cn_cell(vm,16); uint64_t v19 = cn_init_319;
__auto_type cn_init_332 = cn_cell(vm,24); uint64_t v20 = cn_init_332;
__auto_type cn_init_345 = cn_cell(vm,32); uint64_t v21 = cn_init_345;
__auto_type cn_init_358 = cn_cell(vm,40); uint64_t v22 = cn_init_358;
__auto_type cn_init_371 = cn_cell(vm,48); uint64_t v23 = cn_init_371;
__auto_type cn_init_384 = cn_cell(vm,56); uint64_t v24 = cn_init_384;
__auto_type cn_init_397 = cn_cell(vm,64); uint64_t v25 = cn_init_397;
__auto_type cn_init_410 = cn_cell(vm,72); uint64_t v26 = cn_init_410;
__auto_type cn_init_423 = cn_cell(vm,80); uint64_t v27 = cn_init_423;
__auto_type cn_init_436 = cn_cell(vm,88); uint64_t v28 = cn_init_436;
__auto_type cn_init_449 = cn_cell(vm,96); uint64_t v29 = cn_init_449;
__auto_type cn_init_462 = cn_cell(vm,104); uint64_t v30 = cn_init_462;
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
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r5));
{
__auto_type cn_init_676 = cn_double(v27); __auto_type v = cn_init_676;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_712 = cn_double(v28); __auto_type v = cn_init_712;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_748 = cn_double(v29); __auto_type v = cn_init_748;
(f[2]=(f[2]+v));
}
(f[3]=f[2]);
{
__auto_type cn_init_782 = cn_double(v20); __auto_type v = cn_init_782;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_816 = cn_double(v19); __auto_type v = cn_init_816;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_865 = cn_double(v18); __auto_type v = cn_init_865;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_914 = cn_double(v26); __auto_type v = cn_init_914;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_948 = cn_double(v25); __auto_type v = cn_init_948;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_997 = cn_double(v24); __auto_type v = cn_init_997;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1045 = cn_double(v23); __auto_type v = cn_init_1045;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1078 = cn_double(v22); __auto_type v = cn_init_1078;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1126 = cn_double(v21); __auto_type v = cn_init_1126;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[3]=cn_double(r6));
(f[4]=cn_double(r36));
(f[5]=cn_double(v30));
(f[0]=(f[0]*f[5]));
(f[1]=(f[1]*f[5]));
(f[2]=(f[2]*f[5]));
(f[3]=(f[3]*f[5]));
(f[4]=(f[4]*f[5]));
(r36=cn_bits(f[4]));
(r6=cn_bits(f[3]));
{
__auto_type cn_init_1293 = 0x0U; __auto_type bv = cn_init_1293;
__auto_type cn_init_1310 = (((uint32_t)(((((r26>>0))&0xffffffffULL))))); __auto_type av = cn_init_1310;
__auto_type cn_init_1328 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1328;
}
if(cn_cond(fl,5)){
goto cn_break_b3;
}
{
__auto_type cn_init_1347 = 0x0U; __auto_type bv = cn_init_1347;
__auto_type cn_init_1364 = (((uint32_t)(((((v17>>32))&0xffffffffULL))))); __auto_type av = cn_init_1364;
__auto_type cn_init_1382 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1382;
}
if(cn_cond(fl,4)){
goto cn_break_b3;
}
(r10=cn_bits(f[2]));
(f[3]=f[1]);
(r11=cn_bits(f[3]));
(f[3]=f[0]);
(r12=cn_bits(f[3]));
}
cn_break_b3:;
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64(m,CN_REC+8*(10),r10);
cn_wr64(m,CN_REC+8*(11),r11);
cn_wr64(m,CN_REC+8*(12),r12);
cn_wr64(m,CN_REC+8*(36),r36);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_cb020d7c1a106e2b(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_175 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_227;
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
__auto_type cn_init_494 = 0xffffffd8U; __auto_type bv = cn_init_494;
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
{
__auto_type cn_init_849 = 0x0U; __auto_type bv = cn_init_849;
__auto_type cn_init_866 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_866;
__auto_type cn_init_884 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_884;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_905 = r32; uint64_t s = cn_init_905;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_927 = v28; uint64_t s = cn_init_927;
__auto_type cn_init_940 = m->xmm[5][0]; __auto_type a = cn_init_940;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1036 = m->xmm[0][0]; uint64_t v = cn_init_1036;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1095 = m->xmm[0][1]; uint64_t v = cn_init_1095;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1154 = m->xmm[1][0]; uint64_t v = cn_init_1154;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1203 = 0xffffffc4U; __auto_type bv = cn_init_1203;
__auto_type cn_init_1211 = rg[7]; __auto_type av = cn_init_1211;
__auto_type cn_init_1229 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1229;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1356 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1356;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1404 = (((double)(cn_float(((uint32_t)(((((v16>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1404;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1467 = (((double)(cn_float(((uint32_t)(((((v16>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1467;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1530 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1530;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1578 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1578;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1641 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1641;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1703 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1703;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1750 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1750;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1812 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1812;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1855 = cn_bits(f[2]); uint64_t v = cn_init_1855;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1913 = cn_bits(f[1]); uint64_t v = cn_init_1913;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1971 = cn_bits(f[0]); uint64_t v = cn_init_1971;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_2020 = 0x3cU; __auto_type bv = cn_init_2020;
__auto_type cn_init_2028 = rg[7]; __auto_type av = cn_init_2028;
__auto_type cn_init_2046 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2046;
(rg[7]=r);
}
(rg[2]=((uint32_t)(((((v23>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2077 = 0x80000000U; __auto_type bv = cn_init_2077;
__auto_type cn_init_2085 = rg[2]; __auto_type av = cn_init_2085;
__auto_type cn_init_2103 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2103;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[1]=f[0]);
(f[2]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]-f[3]));
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[2]=-f[2]);
(f[2]=(f[2]+f[2]));
(f[0]=(f[0]*f[2]));
{
__auto_type cn_init_2511 = cn_double(v24); __auto_type v = cn_init_2511;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2539 = cn_bits(f[1]); uint64_t v = cn_init_2539;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_2597 = cn_bits(f[0]); uint64_t v = cn_init_2597;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2693 = (((double)(cn_float(((uint32_t)(((((v15>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2693;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2759 = (((double)(cn_float(((uint32_t)(((((v15>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2759;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2851 = (((double)(cn_float(((uint32_t)(((((v15>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2851;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2917 = (((double)(cn_float(((uint32_t)(((((v15>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2917;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_2960 = cn_bits(f[1]); uint64_t v = cn_init_2960;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_3018 = cn_bits(f[0]); uint64_t v = cn_init_3018;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
}
cn_break_b4:;
(f[0]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(v30));
{
__auto_type cn_init_3195 = 0x1U; __auto_type bv = cn_init_3195;
__auto_type cn_init_3212 = (((uint32_t)(((((v20>>32))&0xffffffffULL))))); __auto_type av = cn_init_3212;
__auto_type cn_init_3230 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3230;
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
(f[0]=(f[1]/f[0]));
goto cn_break_b13;
}
cn_break_b6:;
{
__auto_type cn_init_3268 = 0x2U; __auto_type bv = cn_init_3268;
__auto_type cn_init_3285 = (((uint32_t)(((((v20>>32))&0xffffffffULL))))); __auto_type av = cn_init_3285;
__auto_type cn_init_3303 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3303;
}
if(cn_cond(fl,5)){
goto cn_break_b8;
}
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
(f[0]=(f[0]*f[0]));
(f[0]=-f[0]);
goto cn_break_b13;
}
cn_break_b8:;
{
__auto_type cn_init_3375 = 0x3U; __auto_type bv = cn_init_3375;
__auto_type cn_init_3392 = (((uint32_t)(((((v20>>32))&0xffffffffULL))))); __auto_type av = cn_init_3392;
__auto_type cn_init_3410 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3410;
}
if(cn_cond(fl,5)){
goto cn_break_b12;
}
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
{
__auto_type cn_init_3461 = cn_bits(f[0]); uint64_t v = cn_init_3461;
(s2013=(((s2013&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2014=(((s2014&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_3529 = cn_double(v33); __auto_type v = cn_init_3529;
(f[0]=(f[0]+v));
}
(rg[2]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
{
__auto_type cn_init_3565 = 0x80000000U; __auto_type bv = cn_init_3565;
__auto_type cn_init_3573 = rg[2]; __auto_type av = cn_init_3573;
__auto_type cn_init_3591 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_3591;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b11;
}
(f[0]=-f[0]);
}
cn_break_b11:;
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
goto cn_break_b13;
}
cn_break_b12:;
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
}
cn_break_b13:;
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[1]=atan2(f[1],f[2]));
{
__auto_type cn_init_3763 = cn_double(v32); __auto_type v = cn_init_3763;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3798 = (((double)(((int32_t)(((uint32_t)(((((v22>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_3798;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=f[0]);
(f[1]=cn_round(m,f[1]));
(f[0]=(f[1]-f[0]));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_3891 = cn_double(v21); __auto_type v = cn_init_3891;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(v23));
(f[1]=fabs(f[1]));
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_4023 = 0x0U; __auto_type bv = cn_init_4023;
__auto_type cn_init_4040 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_4040;
__auto_type cn_init_4058 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_4058;
}
if(cn_cond(fl,5)){
goto cn_break_b15;
}
{
__auto_type cn_init_4082 = cn_double(v28); __auto_type v = cn_init_4082;
(f[0]=(f[0]/v));
}
}
cn_break_b15:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_4113 = 0x28U; __auto_type bv = cn_init_4113;
__auto_type cn_init_4121 = rg[4]; __auto_type av = cn_init_4121;
__auto_type cn_init_4139 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_4139;
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
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_cc0b522db10a8ce6(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+168))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_201;
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
__auto_type cn_init_344 = cn_cell(vm,80); uint64_t v31 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,88); uint64_t v32 = cn_init_357;
{
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2015=(((s2015&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[1])))&0xffffffffULL))<<0))));
}
{
__auto_type cn_init_419 = 0xffffffe0U; __auto_type bv = cn_init_419;
__auto_type cn_init_427 = rg[4]; __auto_type av = cn_init_427;
__auto_type cn_init_445 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_445;
(rg[4]=r);
}
(f[0]=cn_double(r5));
{
__auto_type cn_init_490 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_490;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_540 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_540;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_590 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_590;
(f[2]=(f[2]-v));
}
(f[3]=f[2]);
{
__auto_type cn_init_638 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_638;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_686 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_686;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_749 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_749;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_812 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_812;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_860 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_860;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_923 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_923;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_985 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_985;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1032 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1032;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1094 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1094;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[3]=f[1]);
(f[3]=(f[3]*f[3]));
(f[4]=f[2]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[3]=sqrt(f[3]));
(s2014=(((s2014&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[3]))))))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_1266 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1266;
(f[3]=(f[3]-v));
}
(f[4]=f[0]);
(f[4]=fabs(f[4]));
{
__auto_type cn_init_1328 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1328;
(f[4]=(f[4]-v));
}
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b2;
}
cn_swap(f,4,3);
}
cn_break_b2:;
(f[4]=f[4]);
(f[4]=f[3]);
(f[4]=fabs(f[4]));
(f[5]=(((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))));
(f[5]=fabs(f[5]));
(fsw=cn_compare(f[5],f[4]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
(r14=cn_bits(f[3]));
(fsw=cn_compare(f[2],f[1]));
(f[0]=f[0]);
{
__auto_type cn_init_1607 = 0x20U; __auto_type bv = cn_init_1607;
__auto_type cn_init_1615 = rg[4]; __auto_type av = cn_init_1615;
__auto_type cn_init_1633 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1633;
(rg[4]=r);
}
{
(rg[1]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_b4:;
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[3]))))))))&0xffffffffULL))<<0))));
(f[3]=f[1]);
(f[2]=atan2(f[2],f[3]));
{
__auto_type cn_init_1773 = cn_double(v32); __auto_type v = cn_init_1773;
(f[2]=(f[2]*v));
}
(s2011=cn_bits(f[2]));
(f[1]=f[1]);
{
__auto_type cn_init_1818 = cn_double(v32); __auto_type v = cn_init_1818;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1856 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1856;
(f[0]=(f[0]/v));
}
(s2012=cn_bits(f[0]));
(rg[0]=rg[4]);
(rg[2]=((uint32_t)(((((v30>>32))&0xffffffffULL)))));
(rg[1]=rg[4]);
{
__auto_type cn_init_1956 = cn_map_px(false,((int32_t)(rg[EDX])),(CN_D3){cn_double(s2011),cn_double(s2012),cn_double(s2013)}); __auto_type r = cn_init_1956;
(s2011=cn_bits(r[0]));
(s2012=cn_bits(r[1]));
(s2013=cn_bits(r[2]));
}
(rg[1]=((uint32_t)(((((v30>>0))&0xffffffffULL)))));
{
__auto_type cn_init_2013 = 0x3U; __auto_type bv = cn_init_2013;
__auto_type cn_init_2021 = rg[1]; __auto_type av = cn_init_2021;
__auto_type cn_init_2039 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2039;
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
__auto_type cn_init_2273 = cn_double(v31); __auto_type v = cn_init_2273;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2311 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2311;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2349 = (((double)(cn_float(((uint32_t)(((((s2014>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2349;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2387 = (((double)(cn_float(((uint32_t)(((((s2014>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2387;
(f[0]=(v-f[0]));
}
(r14=cn_bits(f[0]));
(rg[1]=((uint32_t)(((((v22>>0))&0xffffffffULL)))));
{
__auto_type cn_init_2434 = 0x3U; __auto_type bv = cn_init_2434;
__auto_type cn_init_2442 = rg[1]; __auto_type av = cn_init_2442;
__auto_type cn_init_2460 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2460;
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
__auto_type cn_init_2708 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2708;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2746 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2746;
(f[0]=(f[0]*v));
}
(r34=cn_bits(f[0]));
{
__auto_type cn_init_2776 = 0x20U; __auto_type bv = cn_init_2776;
__auto_type cn_init_2784 = rg[4]; __auto_type av = cn_init_2784;
__auto_type cn_init_2802 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2802;
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
int cn_f_cc9e197248dd9869(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_58 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_58;
__auto_type cn_init_75 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_75;
__auto_type cn_init_92 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_92;
__auto_type cn_init_109 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_109;
__auto_type cn_init_126 = cn_rd64(m,CN_REC+8*(14)); uint64_t r14 = cn_init_126;
__auto_type cn_init_139 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_165;
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
(f[4]=cn_double(r14));
(f[0]=(f[0]*f[4]));
(f[1]=(f[1]*f[4]));
(f[2]=(f[2]*f[4]));
(f[3]=(f[3]*f[4]));
(r3=cn_bits(f[3]));
(r4=cn_bits(f[2]));
(r5=cn_bits(f[1]));
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
int cn_f_ccc969eed4f1b60e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+192))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_178;
__auto_type cn_init_191 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_191;
__auto_type cn_init_204 = cn_cell(vm,0); uint64_t v24 = cn_init_204;
__auto_type cn_init_217 = cn_cell(vm,8); uint64_t v25 = cn_init_217;
__auto_type cn_init_230 = cn_cell(vm,16); uint64_t v26 = cn_init_230;
__auto_type cn_init_243 = cn_cell(vm,24); uint64_t v27 = cn_init_243;
__auto_type cn_init_256 = cn_cell(vm,32); uint64_t v28 = cn_init_256;
__auto_type cn_init_269 = cn_cell(vm,40); uint64_t v29 = cn_init_269;
__auto_type cn_init_282 = cn_cell(vm,48); uint64_t v30 = cn_init_282;
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
(f[0]=cn_double(r5));
{
__auto_type cn_init_571 = cn_double(v28); __auto_type v = cn_init_571;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_607 = cn_double(v29); __auto_type v = cn_init_607;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_643 = cn_double(v30); __auto_type v = cn_init_643;
(f[2]=(f[2]+v));
}
(f[3]=f[2]);
(f[3]=(f[3]*f[3]));
(f[4]=f[1]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_772 = cn_double(v27); __auto_type v = cn_init_772;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_791 = 0x0U; __auto_type bv = cn_init_791;
__auto_type cn_init_808 = (((uint32_t)(((((v24>>32))&0xffffffffULL))))); __auto_type av = cn_init_808;
__auto_type cn_init_826 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_826;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(f[4]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
{
__auto_type cn_init_894 = 0x41U; __auto_type bv = cn_init_894;
__auto_type cn_init_907 = cn_reg_get(rg,4,1); __auto_type av = cn_init_907;
__auto_type cn_init_925 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_925;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b9;
}
goto cn_break_b2;
}
cn_break_b9:;
(f[3]=f[3]);
(f[2]=f[2]);
(f[1]=f[1]);
(f[0]=f[0]);
goto cn_break_b5;
}
cn_break_b2:;
(fsw=cn_compare(f[3],cn_double(v26)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
{
__auto_type cn_init_1044 = 0x41U; __auto_type bv = cn_init_1044;
__auto_type cn_init_1057 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1057;
__auto_type cn_init_1075 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1075;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b6;
}
goto cn_break_b3;
}
cn_break_b6:;
{
__auto_type cn_init_1111 = 0x2U; __auto_type bv = cn_init_1111;
__auto_type cn_init_1128 = (((uint32_t)(((((v24>>32))&0xffffffffULL))))); __auto_type av = cn_init_1128;
__auto_type cn_init_1146 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1146;
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[3]=f[3]);
(f[3]=cn_double(v25));
goto cn_break_b4;
}
cn_break_b8:;
(f[3]=-f[3]);
{
__auto_type cn_init_1207 = cn_double(v26); __auto_type v = cn_init_1207;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_1231 = cn_double(v26); __auto_type v = cn_init_1231;
(f[3]=(f[3]+v));
}
}
cn_break_b3:;
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[4]/f[3]));
}
cn_break_b4:;
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]*f[3]));
(f[0]=(f[0]*f[3]));
(f[3]=f[3]);
{
__auto_type cn_init_1339 = cn_double(v30); __auto_type v = cn_init_1339;
(f[2]=(f[2]-v));
}
(r3=cn_bits(f[2]));
{
__auto_type cn_init_1374 = cn_double(v29); __auto_type v = cn_init_1374;
(f[1]=(f[1]-v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_1409 = cn_double(v28); __auto_type v = cn_init_1409;
(f[0]=(f[0]-v));
}
(r5=cn_bits(f[0]));
}
cn_break_b5:;
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
int cn_f_cd09cc47b9ba875d(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+240))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
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
(f[0]=cn_double(r3));
(f[1]=cn_double(v30));
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(f[1]=cn_double(v30));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
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
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_cf16d7a4f261c2fa(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+152))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_123;
__auto_type cn_init_136 = cn_cell(vm,0); uint64_t v19 = cn_init_136;
__auto_type cn_init_149 = cn_cell(vm,8); uint64_t v20 = cn_init_149;
__auto_type cn_init_162 = cn_cell(vm,16); uint64_t v21 = cn_init_162;
__auto_type cn_init_175 = cn_cell(vm,24); uint64_t v22 = cn_init_175;
__auto_type cn_init_188 = cn_cell(vm,32); uint64_t v23 = cn_init_188;
__auto_type cn_init_201 = cn_cell(vm,40); uint64_t v24 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,48); uint64_t v25 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,56); uint64_t v26 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,64); uint64_t v27 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,72); uint64_t v28 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,80); uint64_t v29 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,88); uint64_t v30 = cn_init_279;
{
{
{
(f[0]=cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(r5));
(f[2]=f[1]);
(f[2]=(f[2]-f[0]));
(f[2]=fabs(f[2]));
(f[2]=(f[2]+f[1]));
cn_swap(f,2,1);
(f[2]=(f[2]+f[0]));
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
(r5=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(r4));
(f[2]=f[1]);
(f[2]=(f[2]-f[0]));
(f[2]=fabs(f[2]));
(f[2]=(f[2]+f[1]));
cn_swap(f,2,1);
(f[2]=(f[2]+f[0]));
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
(r4=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(r3));
(f[2]=f[1]);
(f[2]=(f[2]-f[0]));
(f[2]=fabs(f[2]));
(f[2]=(f[2]+f[1]));
cn_swap(f,2,1);
(f[2]=(f[2]+f[0]));
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
(r3=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(r5));
{
__auto_type cn_init_815 = cn_double(v28); __auto_type v = cn_init_815;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_851 = cn_double(v29); __auto_type v = cn_init_851;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_887 = cn_double(v30); __auto_type v = cn_init_887;
(f[2]=(f[2]+v));
}
(f[3]=f[2]);
{
__auto_type cn_init_935 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_935;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_983 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_983;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1046 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1046;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1109 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1109;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1157 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1157;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1220 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1220;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1282 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1282;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1329 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1329;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1391 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1391;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[3]=f[2]);
(f[3]=(f[3]*f[3]));
(f[4]=f[1]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[4]/f[3]));
(f[4]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b3;
}
(fsw=cn_compare(f[3],cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL)))));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b4;
}
(f[3]=f[3]);
(f[3]=cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))));
}
cn_break_b4:;
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]*f[3]));
(f[0]=(f[0]*f[3]));
(f[4]=cn_double(r32));
(f[4]=(f[4]*f[3]));
(f[4]=fabs(f[4]));
(r32=cn_bits(f[4]));
}
cn_break_b3:;
(f[3]=f[3]);
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10001100U,r32);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_d004a1690fd068a2(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+176))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,0); uint64_t v22 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,8); uint64_t v23 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,16); uint64_t v24 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,24); uint64_t v25 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,32); uint64_t v26 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,40); uint64_t v27 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,48); uint64_t v28 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,56); uint64_t v29 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,64); uint64_t v30 = cn_init_344;
{
{
{
{
__auto_type cn_init_359 = 0xffffffdaU; __auto_type bv = cn_init_359;
__auto_type cn_init_367 = rg[4]; __auto_type av = cn_init_367;
__auto_type cn_init_385 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_385;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_414 = r5; uint64_t s = cn_init_414;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_444 = (CN_U2){v28,v29}; CN_U2 s = cn_init_444;
__auto_type cn_init_454 = m->xmm[0]; __auto_type a = cn_init_454;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_524 = v28; uint64_t s = cn_init_524;
__auto_type cn_init_537 = m->xmm[1][0]; __auto_type a = cn_init_537;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_584 = (CN_U2){v24,v25}; CN_U2 s = cn_init_584;
__auto_type cn_init_594 = m->xmm[0]; __auto_type a = cn_init_594;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_664 = v26; uint64_t s = cn_init_664;
__auto_type cn_init_677 = m->xmm[1][0]; __auto_type a = cn_init_677;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_714 = 0x0U; __auto_type bv = cn_init_714;
__auto_type cn_init_731 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_731;
__auto_type cn_init_749 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_749;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_770 = r32; uint64_t s = cn_init_770;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_792 = v28; uint64_t s = cn_init_792;
__auto_type cn_init_805 = m->xmm[5][0]; __auto_type a = cn_init_805;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_901 = m->xmm[0][0]; uint64_t v = cn_init_901;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_960 = m->xmm[0][1]; uint64_t v = cn_init_960;
(s2011=(((s2011&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2012=(((s2012&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1019 = m->xmm[1][0]; uint64_t v = cn_init_1019;
(s2012=(((s2012&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2013=(((s2013&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1105 = cn_bits(f[0]); uint64_t v = cn_init_1105;
(s2013=(((s2013&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2014=(((s2014&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_1178 = cn_bits(f[0]); uint64_t v = cn_init_1178;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[1]=cn_double(((((((s2011>>48))|((s2012<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2012>>48))|((s2013<<16))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_1337 = cn_bits(f[1]); uint64_t v = cn_init_1337;
(s2011=(((s2011&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2012=(((s2012&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=(f[0]+f[1]));
(f[1]=f[0]);
cn_swap(f,1,0);
(f[2]=cn_double(v30));
{
__auto_type cn_init_1453 = cn_double(((((((s2013>>48))|((s2014<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1453;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1566 = cn_double(((((((s2011>>48))|((s2012<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1566;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v23));
(f[2]=fabs(f[2]));
{
__auto_type cn_init_1620 = cn_bits(f[2]); uint64_t v = cn_init_1620;
(s2013=(((s2013&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2014=(((s2014&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2011>>48))|((s2012<<16))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_1878 = cn_double(((((((s2013>>48))|((s2014<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1878;
(f[1]=(f[1]*v));
}
(f[1]=sqrt(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_1937 = 0x0U; __auto_type bv = cn_init_1937;
__auto_type cn_init_1954 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_1954;
__auto_type cn_init_1972 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1972;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
{
__auto_type cn_init_1996 = cn_double(v28); __auto_type v = cn_init_1996;
(f[0]=(f[0]/v));
}
}
cn_break_b4:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2027 = 0x26U; __auto_type bv = cn_init_2027;
__auto_type cn_init_2035 = rg[4]; __auto_type av = cn_init_2035;
__auto_type cn_init_2053 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2053;
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
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
