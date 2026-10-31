/* Generated native C formula calculations. See tools/generate-native-c.py. */
#include "runtime.h"
int cn_f_7a6c90aeb7f60905(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+216))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_88;
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
(f[0]=cn_double(r5));
(f[1]=cn_double(v28));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(v30));
(f[0]=(f[0]+f[1]));
(r5=cn_bits(f[0]));
{
__auto_type cn_init_596 = (((uint32_t)(((((r5>>56))&0xffULL))))); __auto_type v = cn_init_596;
cn_reg_set(rg,4,1,v);
}
{
__auto_type cn_init_616 = 0x80U; __auto_type bv = cn_init_616;
__auto_type cn_init_629 = cn_reg_get(rg,4,1); __auto_type av = cn_init_629;
__auto_type cn_init_647 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_647;
cn_reg_set(rg,4,1,r);
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(v29));
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v27));
cn_swap(f,1,0);
(f[0]*=log2(f[1]));
(r5=cn_bits(f[0]));
{
__auto_type cn_init_776 = cn_reg_get(rg,4,1); __auto_type bv = cn_init_776;
__auto_type cn_init_793 = (((uint32_t)(((((r5>>56))&0xffULL))))); __auto_type av = cn_init_793;
__auto_type cn_init_811 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_811;
(r5=(((r5&~((0xffULL<<56))))|(((((((uint64_t)((r))))&0xffULL))<<56))));
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
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_7c6826de0d986081(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+160))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_123;
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
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(r4));
(f[2]=f[1]);
(f[2]=(f[2]/f[0]));
{
__auto_type cn_init_1003 = 0xfffffff8U; __auto_type bv = cn_init_1003;
__auto_type cn_init_1011 = rg[4]; __auto_type av = cn_init_1011;
__auto_type cn_init_1029 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1029;
(rg[4]=r);
}
{
__auto_type cn_init_1051 = cn_round(m,f[2]); __auto_type x = cn_init_1051;
__auto_type cn_init_1086 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_1086;
(s2014=(((s2014&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
(f[2]=(((double)(((int32_t)(((uint32_t)(((((s2014>>32))&0xffffffffULL))))))))));
(rg[2]=((uint32_t)(((((s2014>>32))&0xffffffffULL)))));
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]-f[2]));
(f[0]=f[1]);
(f[1]=cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(r3));
(rg[2]=((uint32_t)(((((s2014>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1257 = 0x1U; __auto_type bv = cn_init_1257;
__auto_type cn_init_1265 = rg[2]; __auto_type av = cn_init_1265;
__auto_type cn_init_1283 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1283;
(rg[2]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
{
__auto_type cn_init_1330 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1330;
(f[2]=(f[2]+v));
}
}
cn_break_b2:;
(f[3]=f[2]);
(f[3]=(f[3]/f[1]));
(f[3]=cn_round(m,f[3]));
{
__auto_type cn_init_1390 = 0x8U; __auto_type bv = cn_init_1390;
__auto_type cn_init_1398 = rg[4]; __auto_type av = cn_init_1398;
__auto_type cn_init_1416 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1416;
(rg[4]=r);
}
(f[3]=(f[3]*f[1]));
(f[2]=(f[2]-f[3]));
(f[1]=f[2]);
(r3=cn_bits(f[1]));
(r4=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_body;
}
cn_break_body:;
cn_wr64u(m,0x10001018U,r3);
cn_wr64u(m,0x10001020U,r4);
cn_wr64u(m,0x10001028U,r5);
cn_wr64u(m,0x10007ef0U,s2014);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_7db073976a2f1e2e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=cn_double(r5));
(f[1]=cn_double(v25));
(f[0]=(f[0]*f[1]));
(f[0]=sin(f[0]));
(fsw&=~0x0400);
(f[1]=cn_double(r5));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v26));
(f[0]=(f[0]*f[1]));
(f[0]=sin(f[0]));
(fsw&=~0x0400);
(f[1]=cn_double(r5));
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
(f[2]=cn_double(v25));
(f[1]=(f[1]*f[2]));
(f[1]=sin(f[1]));
(fsw&=~0x0400);
(f[2]=cn_double(r3));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v26));
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
(f[2]=cn_double(r4));
(f[3]=cn_double(v25));
(f[2]=(f[2]*f[3]));
(f[2]=sin(f[2]));
(fsw&=~0x0400);
(f[3]=cn_double(r4));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(v26));
(f[2]=(f[2]*f[3]));
(f[2]=sin(f[2]));
(fsw&=~0x0400);
(f[3]=cn_double(r4));
(f[2]=(f[2]+f[3]));
(f[2]=sin(f[2]));
(fsw&=~0x0400);
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
int cn_f_7dd7527284569513(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;
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
{
__auto_type cn_init_1495 = cn_pop_lu(m,rg); __auto_type v = cn_init_1495;
(rg[7]=v);
}
{
__auto_type cn_init_1516 = cn_pop_lu(m,rg); __auto_type v = cn_init_1516;
(rg[6]=v);
}
{
__auto_type cn_init_1537 = cn_pop_lu(m,rg); __auto_type v = cn_init_1537;
(rg[2]=v);
}
{
__auto_type cn_init_1558 = cn_pop_lu(m,rg); __auto_type v = cn_init_1558;
(rg[0]=v);
}
{
__auto_type cn_init_1579 = cn_pop_lu(m,rg); __auto_type v = cn_init_1579;
(rg[5]=v);
}
__auto_type cn_init_1599 = cn_pop_lu(m,rg); __auto_type r = cn_init_1599;
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
int cn_f_7efcd46b624cb1bb(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[2]=fabs(f[2]));
(s2012=cn_bits(f[2]));
(f[1]=fabs(f[1]));
(s2013=cn_bits(f[1]));
(f[0]=fabs(f[0]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_1004 = cn_double(r5); __auto_type v = cn_init_1004;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1028 = cn_double(v29); __auto_type v = cn_init_1028;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1066 = cn_double(v30); __auto_type v = cn_init_1066;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1090 = cn_double(v34); __auto_type v = cn_init_1090;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1137 = cn_double(r5); __auto_type v = cn_init_1137;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1161 = cn_double(v29); __auto_type v = cn_init_1161;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1199 = cn_double(v30); __auto_type v = cn_init_1199;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1223 = cn_double(v34); __auto_type v = cn_init_1223;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1270 = cn_double(s2012); __auto_type v = cn_init_1270;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1294 = cn_double(v29); __auto_type v = cn_init_1294;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1332 = cn_double(v30); __auto_type v = cn_init_1332;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1379 = cn_double(r3); __auto_type v = cn_init_1379;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1415 = cn_double(r3); __auto_type v = cn_init_1415;
(f[1]=(f[1]-v));
}
(r4=cn_bits(f[1]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1473 = cn_double(v32); __auto_type v = cn_init_1473;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1509 = cn_double(v33); __auto_type v = cn_init_1509;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1560 = cn_double(v33); __auto_type v = cn_init_1560;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[2]=cn_double(r5));
{
__auto_type cn_init_1607 = cn_double(v32); __auto_type v = cn_init_1607;
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
int cn_f_7f401f1fca97428b(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_175 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_240;
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
__auto_type cn_init_437 = 0xffffffc4U; __auto_type bv = cn_init_437;
__auto_type cn_init_445 = rg[4]; __auto_type av = cn_init_445;
__auto_type cn_init_463 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_463;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_492 = r5; uint64_t s = cn_init_492;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_522 = (CN_U2){v28,v29}; CN_U2 s = cn_init_522;
__auto_type cn_init_532 = m->xmm[0]; __auto_type a = cn_init_532;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_602 = v28; uint64_t s = cn_init_602;
__auto_type cn_init_615 = m->xmm[1][0]; __auto_type a = cn_init_615;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_662 = (CN_U2){v24,v25}; CN_U2 s = cn_init_662;
__auto_type cn_init_672 = m->xmm[0]; __auto_type a = cn_init_672;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_742 = v26; uint64_t s = cn_init_742;
__auto_type cn_init_755 = m->xmm[1][0]; __auto_type a = cn_init_755;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_792 = 0x0U; __auto_type bv = cn_init_792;
__auto_type cn_init_809 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_809;
__auto_type cn_init_827 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_827;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_848 = r32; uint64_t s = cn_init_848;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_870 = v28; uint64_t s = cn_init_870;
__auto_type cn_init_883 = m->xmm[5][0]; __auto_type a = cn_init_883;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(s2008=m->xmm[0][0]);
(s2009=m->xmm[0][1]);
(s2010=m->xmm[1][0]);
{
__auto_type cn_init_1005 = 0xffffffd4U; __auto_type bv = cn_init_1005;
__auto_type cn_init_1013 = rg[7]; __auto_type av = cn_init_1013;
__auto_type cn_init_1031 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1031;
(rg[7]=r);
}
(f[0]=cn_double(s2010));
(f[1]=cn_double(s2009));
(f[2]=cn_double(s2008));
(f[3]=f[2]);
{
__auto_type cn_init_1110 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1110;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1158 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1158;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1221 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1221;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1284 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1284;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1332 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1332;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1395 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1395;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1457 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1457;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1504 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1504;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1566 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1566;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[2]=(f[2]*f[2]));
(s2008=cn_bits(f[2]));
(f[1]=(f[1]*f[1]));
(s2009=cn_bits(f[1]));
(f[0]=(f[0]*f[0]));
(s2010=cn_bits(f[0]));
{
__auto_type cn_init_1678 = 0x2cU; __auto_type bv = cn_init_1678;
__auto_type cn_init_1686 = rg[7]; __auto_type av = cn_init_1686;
__auto_type cn_init_1704 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1704;
(rg[7]=r);
}
(f[0]=cn_double(0x3ff0000000000000));
(f[1]=cn_double(v30));
(f[1]=fabs(f[1]));
(s2011=cn_bits(f[1]));
(f[2]=cn_double(v23));
(f[2]=fabs(f[2]));
(s2012=cn_bits(f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_1889 = cn_double(s2009); __auto_type v = cn_init_1889;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2008));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2010));
{
__auto_type cn_init_1982 = cn_double(s2009); __auto_type v = cn_init_1982;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2006 = cn_double(s2008); __auto_type v = cn_init_2006;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2011));
(f[1]=(f[1]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2087 = cn_double(s2013); __auto_type v = cn_init_2087;
(f[0]=(f[0]*v));
}
(f[0]=sqrt(f[0]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(s2010));
{
__auto_type cn_init_2151 = cn_double(s2009); __auto_type v = cn_init_2151;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2175 = cn_double(s2008); __auto_type v = cn_init_2175;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2199 = cn_double(s2012); __auto_type v = cn_init_2199;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2223 = cn_double(s2013); __auto_type v = cn_init_2223;
(f[1]=(f[1]*v));
}
(f[1]=sqrt(f[1]));
(f[1]=sqrt(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2301 = cn_double(v32); __auto_type v = cn_init_2301;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2320 = 0x0U; __auto_type bv = cn_init_2320;
__auto_type cn_init_2337 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_2337;
__auto_type cn_init_2355 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2355;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
{
__auto_type cn_init_2379 = cn_double(v28); __auto_type v = cn_init_2379;
(f[0]=(f[0]/v));
}
}
cn_break_b4:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2410 = 0x3cU; __auto_type bv = cn_init_2410;
__auto_type cn_init_2418 = rg[4]; __auto_type av = cn_init_2418;
__auto_type cn_init_2436 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2436;
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
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_7f9fef6fa0413ff0(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=(f[0]/f[1]));
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
int cn_f_7fb5cdafeec5dbf0(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=cn_double(r4));
{
__auto_type cn_tuple_177_0 = sin(f[0]);
__auto_type cn_tuple_177_1 = cos(f[0]);
__auto_type s = cn_tuple_177_0;
__auto_type c = cn_tuple_177_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(f[2]=cn_double(r3));
(f[0]=(f[0]*f[2]));
(f[1]=(f[1]*f[2]));
(r3=cn_bits(f[1]));
(r4=cn_bits(f[0]));
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
int cn_f_80c7c458bee44a90(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_227 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_240;
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
__auto_type cn_init_435 = cn_cell(vm,120); uint64_t v33 = cn_init_435;
{
{
{
{
{
{
{
{
__auto_type cn_init_462 = 0xffffffb0U; __auto_type bv = cn_init_462;
__auto_type cn_init_470 = rg[4]; __auto_type av = cn_init_470;
__auto_type cn_init_488 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_488;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_517 = r5; uint64_t s = cn_init_517;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_547 = (CN_U2){v28,v29}; CN_U2 s = cn_init_547;
__auto_type cn_init_557 = m->xmm[0]; __auto_type a = cn_init_557;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_627 = v28; uint64_t s = cn_init_627;
__auto_type cn_init_640 = m->xmm[1][0]; __auto_type a = cn_init_640;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_687 = (CN_U2){v24,v25}; CN_U2 s = cn_init_687;
__auto_type cn_init_697 = m->xmm[0]; __auto_type a = cn_init_697;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_767 = v26; uint64_t s = cn_init_767;
__auto_type cn_init_780 = m->xmm[1][0]; __auto_type a = cn_init_780;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_817 = 0x0U; __auto_type bv = cn_init_817;
__auto_type cn_init_834 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_834;
__auto_type cn_init_852 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_852;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_873 = r32; uint64_t s = cn_init_873;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_895 = v28; uint64_t s = cn_init_895;
__auto_type cn_init_908 = m->xmm[5][0]; __auto_type a = cn_init_908;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1004 = m->xmm[0][0]; uint64_t v = cn_init_1004;
(s2005=(((s2005&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2006=(((s2006&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1063 = m->xmm[0][1]; uint64_t v = cn_init_1063;
(s2006=(((s2006&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2007=(((s2007&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1122 = m->xmm[1][0]; uint64_t v = cn_init_1122;
(s2007=(((s2007&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2008=(((s2008&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1171 = 0xffffffd4U; __auto_type bv = cn_init_1171;
__auto_type cn_init_1179 = rg[7]; __auto_type av = cn_init_1179;
__auto_type cn_init_1197 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1197;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1324 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1324;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1372 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1372;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1435 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1435;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1498 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1498;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1546 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1546;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1609 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1609;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1671 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1671;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1718 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1718;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1780 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1780;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1823 = cn_bits(f[2]); uint64_t v = cn_init_1823;
(s2005=(((s2005&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2006=(((s2006&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1881 = cn_bits(f[1]); uint64_t v = cn_init_1881;
(s2006=(((s2006&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2007=(((s2007&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1939 = cn_bits(f[0]); uint64_t v = cn_init_1939;
(s2007=(((s2007&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2008=(((s2008&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1988 = 0x2cU; __auto_type bv = cn_init_1988;
__auto_type cn_init_1996 = rg[7]; __auto_type av = cn_init_1996;
__auto_type cn_init_2014 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2014;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2061 = cn_double(v23); __auto_type v = cn_init_2061;
(f[0]=(v-f[0]));
}
(f[1]=f[0]);
{
__auto_type cn_init_2098 = cn_round(m,f[1]); __auto_type x = cn_init_2098;
__auto_type cn_init_2133 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2133;
(s2009=(((s2009&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2009>>32))&0xffffffffULL))))))))));
(f[0]=(f[0]-f[1]));
(f[0]=fabs(f[0]));
(f[1]=cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2252 = cn_double(v32); __auto_type v = cn_init_2252;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2304 = cn_double(v33); __auto_type v = cn_init_2304;
(f[2]=(f[2]*v));
}
(f[3]=f[1]);
(f[3]=(f[3]+f[2]));
(f[4]=f[3]);
{
__auto_type cn_init_2366 = cn_round(m,f[4]); __auto_type x = cn_init_2366;
__auto_type cn_init_2401 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2401;
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(i)))&0xffffffffULL))<<0))));
}
(f[4]=(((double)(((int32_t)(((uint32_t)(((((s2010>>0))&0xffffffffULL))))))))));
(f[3]=(f[3]-f[4]));
(f[3]=fabs(f[3]));
cn_swap(f,3,1);
(f[2]=(f[2]-f[3]));
{
__auto_type cn_init_2519 = cn_round(m,f[2]); __auto_type x = cn_init_2519;
__auto_type cn_init_2554 = (((isnan(x)||!(x>=-2147483648.0&&x<=2147483647.0)))?(({0x80000000U;})):(({((uint32_t)(((int32_t)(x))));}))); __auto_type i = cn_init_2554;
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)(i)))&0xffffffffULL))<<32))));
}
(f[3]=(((double)(((int32_t)(((uint32_t)(((((s2010>>32))&0xffffffffULL))))))))));
(f[2]=(f[2]-f[3]));
(f[2]=fabs(f[2]));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
(f[2]=f[2]);
goto cn_break_b5;
}
cn_break_b4:;
(f[1]=f[2]);
}
cn_break_b5:;
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b7;
}
(f[1]=f[1]);
goto cn_break_b8;
}
cn_break_b7:;
(f[0]=f[1]);
}
cn_break_b8:;
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2922 = cn_double(v30); __auto_type v = cn_init_2922;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2941 = 0x0U; __auto_type bv = cn_init_2941;
__auto_type cn_init_2958 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_2958;
__auto_type cn_init_2976 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2976;
}
if(cn_cond(fl,5)){
goto cn_break_b10;
}
{
__auto_type cn_init_3000 = cn_double(v28); __auto_type v = cn_init_3000;
(f[0]=(f[0]/v));
}
}
cn_break_b10:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_3031 = 0x50U; __auto_type bv = cn_init_3031;
__auto_type cn_init_3039 = rg[4]; __auto_type av = cn_init_3039;
__auto_type cn_init_3057 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3057;
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
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_81da671ec8d37132(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_136 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_240;
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
__auto_type cn_init_422 = cn_cell(vm,104); uint64_t v31 = cn_init_422;
__auto_type cn_init_435 = cn_cell(vm,112); uint64_t v32 = cn_init_435;
__auto_type cn_init_448 = cn_cell(vm,120); uint64_t v33 = cn_init_448;
{
{
{
{
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_481 = r5; uint64_t s = cn_init_481;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_511 = (CN_U2){v26,v27}; CN_U2 s = cn_init_511;
__auto_type cn_init_521 = m->xmm[0]; __auto_type a = cn_init_521;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_591 = v26; uint64_t s = cn_init_591;
__auto_type cn_init_604 = m->xmm[1][0]; __auto_type a = cn_init_604;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_651 = (CN_U2){v22,v23}; CN_U2 s = cn_init_651;
__auto_type cn_init_661 = m->xmm[0]; __auto_type a = cn_init_661;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_731 = v24; uint64_t s = cn_init_731;
__auto_type cn_init_744 = m->xmm[1][0]; __auto_type a = cn_init_744;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_781 = 0x0U; __auto_type bv = cn_init_781;
__auto_type cn_init_798 = (((uint32_t)(((((v20>>0))&0xffffffffULL))))); __auto_type av = cn_init_798;
__auto_type cn_init_816 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_816;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_837 = r32; uint64_t s = cn_init_837;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_859 = v26; uint64_t s = cn_init_859;
__auto_type cn_init_872 = m->xmm[5][0]; __auto_type a = cn_init_872;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_958 = 0x0U; __auto_type bv = cn_init_958;
__auto_type cn_init_975 = (((uint32_t)(((((v20>>32))&0xffffffffULL))))); __auto_type av = cn_init_975;
__auto_type cn_init_993 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_993;
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
{
__auto_type cn_init_1012 = 0xffffffe8U; __auto_type bv = cn_init_1012;
__auto_type cn_init_1020 = rg[4]; __auto_type av = cn_init_1020;
__auto_type cn_init_1038 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1038;
(rg[4]=r);
}
{
__auto_type cn_init_1062 = m->xmm[0][0]; uint64_t v = cn_init_1062;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1121 = m->xmm[0][1]; uint64_t v = cn_init_1121;
(s2013=(((s2013&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2014=(((s2014&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1180 = m->xmm[1][0]; uint64_t v = cn_init_1180;
(s2014=(((s2014&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2015=(((s2015&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=(((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))));
{
__auto_type cn_init_1276 = cn_double(((((((s2014>>32))|((s2015<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1276;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1306_0 = sin(f[0]);
__auto_type cn_tuple_1306_1 = cos(f[0]);
__auto_type s = cn_tuple_1306_0;
__auto_type c = cn_tuple_1306_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(f[2]=cn_double(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))));
(f[3]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
(f[4]=f[0]);
(f[4]=(f[4]*f[3]));
(f[5]=f[2]);
(f[5]=(f[5]*f[1]));
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_1462 = cn_bits(f[4]); uint64_t v = cn_init_1462;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[1]=(f[1]*f[3]));
(f[0]=(f[0]*f[2]));
(f[0]=(f[1]-f[0]));
{
__auto_type cn_init_1565 = cn_bits(f[0]); uint64_t v = cn_init_1565;
(s2013=(((s2013&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2014=(((s2014&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(m->xmm[0]=(CN_U2){((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL)),((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))});
{
__auto_type cn_init_1659 = 0x18U; __auto_type bv = cn_init_1659;
__auto_type cn_init_1667 = rg[4]; __auto_type av = cn_init_1667;
__auto_type cn_init_1685 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1685;
(rg[4]=r);
}
}
cn_break_b4:;
(m->xmm[3][0]=m->xmm[1][0]);
{
__auto_type cn_init_1730 = (CN_U2){v32,v33}; CN_U2 s = cn_init_1730;
__auto_type cn_init_1740 = m->xmm[0]; __auto_type a = cn_init_1740;
(m->xmm[0]=(CN_U2){(a[0]&s[0]),(a[1]&s[1])});
}
{
__auto_type cn_init_1786 = (CN_U2){v32,v33}; CN_U2 s = cn_init_1786;
__auto_type cn_init_1796 = m->xmm[1]; __auto_type a = cn_init_1796;
(m->xmm[1]=(CN_U2){(a[0]&s[0]),(a[1]&s[1])});
}
{
__auto_type cn_init_1834 = v21; uint64_t s = cn_init_1834;
__auto_type cn_init_1847 = m->xmm[3][0]; __auto_type a = cn_init_1847;
(m->xmm[3][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_1894 = (CN_U2){v28,v29}; CN_U2 s = cn_init_1894;
__auto_type cn_init_1904 = m->xmm[0]; __auto_type a = cn_init_1904;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])-cn_double(s[0])))),cn_bits(((cn_double(a[1])-cn_double(s[1]))))});
}
{
__auto_type cn_init_1974 = v30; uint64_t s = cn_init_1974;
__auto_type cn_init_1987 = m->xmm[1][0]; __auto_type a = cn_init_1987;
(m->xmm[1][0]=cn_bits(((cn_double(a)-cn_double(s)))));
}
{
__auto_type cn_init_2034 = m->xmm[3][0]; uint64_t s = cn_init_2034;
__auto_type cn_init_2047 = m->xmm[0][0]; __auto_type a = cn_init_2047;
(m->xmm[0][0]=cn_bits(((cn_double(a)-cn_double(s)))));
}
{
__auto_type cn_init_2094 = m->xmm[0][0]; uint64_t s = cn_init_2094;
__auto_type cn_init_2107 = m->xmm[1][0]; __auto_type a = cn_init_2107;
(m->xmm[1][0]=cn_bits(({__auto_type cn_tuple_2141_0 = cn_double(a);
__auto_type cn_tuple_2141_1 = cn_double(s);
__auto_type p = cn_tuple_2141_0;
__auto_type q = cn_tuple_2141_1; (((p>q))?(({p;})):(({q;})));})));
}
{
__auto_type cn_init_2176 = m->xmm[0]; CN_U2 s = cn_init_2176;
__auto_type cn_init_2186 = m->xmm[0]; __auto_type a = cn_init_2186;
(m->xmm[0]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_2222 = m->xmm[0][0]; uint64_t s = cn_init_2222;
__auto_type cn_init_2235 = m->xmm[1][0]; __auto_type a = cn_init_2235;
(m->xmm[1][0]=cn_bits(({__auto_type cn_tuple_2269_0 = cn_double(a);
__auto_type cn_tuple_2269_1 = cn_double(s);
__auto_type p = cn_tuple_2269_0;
__auto_type q = cn_tuple_2269_1; (((p>q))?(({p;})):(({q;})));})));
}
{
__auto_type cn_init_2293 = 0x0U; __auto_type bv = cn_init_2293;
__auto_type cn_init_2310 = (((uint32_t)(((((v20>>0))&0xffffffffULL))))); __auto_type av = cn_init_2310;
__auto_type cn_init_2328 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2328;
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
{
__auto_type cn_init_2349 = v26; uint64_t s = cn_init_2349;
__auto_type cn_init_2362 = m->xmm[1][0]; __auto_type a = cn_init_2362;
(m->xmm[1][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
}
cn_break_b6:;
(rg[0]=((uint32_t)(((((v19>>32))&0xffffffffULL)))));
(r14=m->xmm[1][0]);
{
__auto_type cn_init_2429 = 0x3U; __auto_type bv = cn_init_2429;
__auto_type cn_init_2437 = rg[0]; __auto_type av = cn_init_2437;
__auto_type cn_init_2455 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2455;
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
__auto_type cn_init_2703 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2703;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2741 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2741;
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
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
cn_wr64u(m,0x10007ef8U,s2015);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_81f3c3c0ee0b399e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_661 = cn_double(r10); __auto_type v = cn_init_661;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_697 = cn_double(r4); __auto_type v = cn_init_697;
(f[1]=(f[1]*v));
}
(f[1]=(f[1]+f[1]));
{
__auto_type cn_init_736 = cn_double(r11); __auto_type v = cn_init_736;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(r6));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]-f[3]));
{
__auto_type cn_init_829 = cn_double(r12); __auto_type v = cn_init_829;
(f[2]=(f[2]+v));
}
(f[3]=cn_double(r5));
{
__auto_type cn_init_865 = cn_double(r6); __auto_type v = cn_init_865;
(f[3]=(f[3]*v));
}
(f[3]=(f[3]+f[3]));
{
__auto_type cn_init_904 = cn_double(r0); __auto_type v = cn_init_904;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_928 = cn_double(v30); __auto_type v = cn_init_928;
(f[3]=(f[3]+v));
}
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
int cn_f_827fc814703ee437(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_175 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,0); uint64_t v17 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,8); uint64_t v18 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,16); uint64_t v19 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,24); uint64_t v20 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,32); uint64_t v21 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,40); uint64_t v22 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,48); uint64_t v23 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,56); uint64_t v24 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,64); uint64_t v25 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,72); uint64_t v26 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,80); uint64_t v27 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,88); uint64_t v28 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,96); uint64_t v29 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,104); uint64_t v30 = cn_init_383;
{
{
{
{
{
{
{
{
__auto_type cn_init_410 = 0xffffffe4U; __auto_type bv = cn_init_410;
__auto_type cn_init_418 = rg[4]; __auto_type av = cn_init_418;
__auto_type cn_init_436 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_436;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_465 = r5; uint64_t s = cn_init_465;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_495 = (CN_U2){v28,v29}; CN_U2 s = cn_init_495;
__auto_type cn_init_505 = m->xmm[0]; __auto_type a = cn_init_505;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_575 = v28; uint64_t s = cn_init_575;
__auto_type cn_init_588 = m->xmm[1][0]; __auto_type a = cn_init_588;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_635 = (CN_U2){v24,v25}; CN_U2 s = cn_init_635;
__auto_type cn_init_645 = m->xmm[0]; __auto_type a = cn_init_645;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_715 = v26; uint64_t s = cn_init_715;
__auto_type cn_init_728 = m->xmm[1][0]; __auto_type a = cn_init_728;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_765 = 0x0U; __auto_type bv = cn_init_765;
__auto_type cn_init_782 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_782;
__auto_type cn_init_800 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_800;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_821 = r32; uint64_t s = cn_init_821;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_843 = v28; uint64_t s = cn_init_843;
__auto_type cn_init_856 = m->xmm[5][0]; __auto_type a = cn_init_856;
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
__auto_type cn_init_978 = 0xffffffccU; __auto_type bv = cn_init_978;
__auto_type cn_init_986 = rg[7]; __auto_type av = cn_init_986;
__auto_type cn_init_1004 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1004;
(rg[7]=r);
}
(f[0]=cn_double(s2014));
(f[1]=cn_double(s2013));
(f[2]=cn_double(s2012));
(f[3]=f[2]);
{
__auto_type cn_init_1083 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1083;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1131 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1131;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1194 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1194;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1257 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1257;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1305 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1305;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1368 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1368;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1430 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1430;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1477 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1477;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1539 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1539;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(s2012=cn_bits(f[2]));
(s2013=cn_bits(f[1]));
(s2014=cn_bits(f[0]));
{
__auto_type cn_init_1606 = 0x34U; __auto_type bv = cn_init_1606;
__auto_type cn_init_1614 = rg[7]; __auto_type av = cn_init_1614;
__auto_type cn_init_1632 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1632;
(rg[7]=r);
}
(f[0]=cn_double(s2012));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2013));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(v30));
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1769 = cn_double(s2014); __auto_type v = cn_init_1769;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1836 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1836;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2014));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1960 = cn_double(v23); __auto_type v = cn_init_1960;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1996 = cn_double(v23); __auto_type v = cn_init_1996;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_2020 = cn_double(v23); __auto_type v = cn_init_2020;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_2044 = cn_double(v23); __auto_type v = cn_init_2044;
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
(f[1]=cn_double(s2014));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2189 = cn_double(v23); __auto_type v = cn_init_2189;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_2213 = cn_double(v23); __auto_type v = cn_init_2213;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_2237 = cn_double(v23); __auto_type v = cn_init_2237;
(f[1]=(f[1]-v));
}
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
__auto_type cn_init_2351 = 0x0U; __auto_type bv = cn_init_2351;
__auto_type cn_init_2368 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_2368;
__auto_type cn_init_2386 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2386;
}
if(cn_cond(fl,5)){
goto cn_break_b10;
}
{
__auto_type cn_init_2410 = cn_double(v28); __auto_type v = cn_init_2410;
(f[0]=(f[0]/v));
}
}
cn_break_b10:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2441 = 0x1cU; __auto_type bv = cn_init_2441;
__auto_type cn_init_2449 = rg[4]; __auto_type av = cn_init_2449;
__auto_type cn_init_2467 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2467;
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
int cn_f_82fc9de97ad99e88(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
{
__auto_type cn_init_2363 = 0x28U; __auto_type bv = cn_init_2363;
__auto_type cn_init_2371 = rg[7]; __auto_type av = cn_init_2371;
__auto_type cn_init_2389 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2389;
(rg[7]=r);
}
(f[1]=cn_double(v30));
(f[0]=(f[0]*f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]-f[2]));
{
__auto_type cn_init_2462 = cn_double(v26); __auto_type v = cn_init_2462;
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
__auto_type cn_init_2685 = cn_double(v29); __auto_type v = cn_init_2685;
(f[6]=(f[6]*v));
}
(f[1]=(f[1]-f[6]));
{
__auto_type cn_init_2724 = cn_double(v28); __auto_type v = cn_init_2724;
(f[5]=(f[5]*v));
}
(f[2]=(f[2]-f[5]));
(f[4]=(f[4]/f[3]));
{
__auto_type cn_init_2778 = cn_double(v27); __auto_type v = cn_init_2778;
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
int cn_f_838ae2b97d9fa9b7(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_237 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_237;
__auto_type cn_init_250 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_250;
__auto_type cn_init_263 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_263;
__auto_type cn_init_276 = cn_cell(vm,0); uint64_t v23 = cn_init_276;
__auto_type cn_init_289 = cn_cell(vm,8); uint64_t v24 = cn_init_289;
__auto_type cn_init_302 = cn_cell(vm,16); uint64_t v25 = cn_init_302;
__auto_type cn_init_315 = cn_cell(vm,24); uint64_t v26 = cn_init_315;
__auto_type cn_init_328 = cn_cell(vm,32); uint64_t v27 = cn_init_328;
__auto_type cn_init_341 = cn_cell(vm,40); uint64_t v28 = cn_init_341;
__auto_type cn_init_354 = cn_cell(vm,48); uint64_t v29 = cn_init_354;
__auto_type cn_init_367 = cn_cell(vm,56); uint64_t v30 = cn_init_367;
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
(f[0]=cn_double(r6));
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
{
__auto_type cn_init_614 = cn_double(v30); __auto_type v = cn_init_614;
(f[3]=(f[3]+v));
}
(r3=cn_bits(f[3]));
{
__auto_type cn_init_649 = cn_double(v29); __auto_type v = cn_init_649;
(f[2]=(f[2]+v));
}
(r4=cn_bits(f[2]));
{
__auto_type cn_init_684 = cn_double(v28); __auto_type v = cn_init_684;
(f[1]=(f[1]+v));
}
(r5=cn_bits(f[1]));
{
__auto_type cn_init_719 = cn_double(v27); __auto_type v = cn_init_719;
(f[0]=(f[0]+v));
}
(r6=cn_bits(f[0]));
(f[0]=cn_double(r0));
(f[1]=cn_double(r12));
(f[2]=cn_double(r11));
(f[3]=cn_double(r10));
{
__auto_type cn_init_802 = cn_double(v26); __auto_type v = cn_init_802;
(f[3]=(f[3]+v));
}
(r10=cn_bits(f[3]));
{
__auto_type cn_init_837 = cn_double(v25); __auto_type v = cn_init_837;
(f[2]=(f[2]+v));
}
(r11=cn_bits(f[2]));
{
__auto_type cn_init_872 = cn_double(v24); __auto_type v = cn_init_872;
(f[1]=(f[1]+v));
}
(r12=cn_bits(f[1]));
{
__auto_type cn_init_907 = cn_double(v23); __auto_type v = cn_init_907;
(f[0]=(f[0]+v));
}
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
int cn_f_83c81cbbb8888f0b(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+168))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_173;
__auto_type cn_init_190 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_190;
__auto_type cn_init_203 = cn_rd64u(m,0x10007e60U); uint64_t s1996 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007e68U); uint64_t s1997 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_268;
__auto_type cn_init_281 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_281;
__auto_type cn_init_294 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_294;
__auto_type cn_init_307 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_307;
__auto_type cn_init_320 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,0); uint64_t v21 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,8); uint64_t v22 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,16); uint64_t v23 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,24); uint64_t v24 = cn_init_372;
__auto_type cn_init_385 = cn_cell(vm,32); uint64_t v25 = cn_init_385;
__auto_type cn_init_398 = cn_cell(vm,40); uint64_t v26 = cn_init_398;
__auto_type cn_init_411 = cn_cell(vm,48); uint64_t v27 = cn_init_411;
__auto_type cn_init_424 = cn_cell(vm,56); uint64_t v28 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,64); uint64_t v29 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,72); uint64_t v30 = cn_init_450;
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
__auto_type cn_init_528 = 0x80U; __auto_type bv = cn_init_528;
__auto_type cn_init_536 = rg[4]; __auto_type av = cn_init_536;
__auto_type cn_init_554 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_554;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s1997=(((s1997&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s1997=(((s1997&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s1996=(((s1996&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(f[0]=cn_double(r3));
{
__auto_type cn_init_770 = cn_double(v29); __auto_type v = cn_init_770;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(r3));
{
__auto_type cn_init_820 = cn_double(v29); __auto_type v = cn_init_820;
(f[1]=(f[1]-v));
}
(f[1]=fabs(f[1]));
(f[1]=-f[1]);
{
__auto_type cn_init_869 = cn_double(r3); __auto_type v = cn_init_869;
(f[1]=(f[1]-v));
}
(f[0]=(f[0]+f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_931 = cn_double(v29); __auto_type v = cn_init_931;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_981 = cn_double(v29); __auto_type v = cn_init_981;
(f[1]=(f[1]-v));
}
(f[1]=fabs(f[1]));
(f[1]=-f[1]);
{
__auto_type cn_init_1030 = cn_double(r4); __auto_type v = cn_init_1030;
(f[1]=(f[1]-v));
}
(f[0]=(f[0]+f[1]));
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_1092 = cn_double(v29); __auto_type v = cn_init_1092;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_1142 = cn_double(v29); __auto_type v = cn_init_1142;
(f[1]=(f[1]-v));
}
(f[1]=fabs(f[1]));
(f[1]=-f[1]);
{
__auto_type cn_init_1191 = cn_double(r5); __auto_type v = cn_init_1191;
(f[1]=(f[1]-v));
}
(f[0]=(f[0]+f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(s2011=cn_bits(f[0]));
(f[0]=sqrt(f[0]));
(s2010=cn_bits(f[0]));
(f[0]=cn_double(v30));
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[0]));
{
__auto_type cn_init_1427 = cn_double(v25); __auto_type v = cn_init_1427;
(f[1]=(f[1]-v));
}
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[0]));
{
__auto_type cn_init_1489 = cn_double(v24); __auto_type v = cn_init_1489;
(f[1]=(f[1]-v));
}
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[0]));
{
__auto_type cn_init_1551 = cn_double(v23); __auto_type v = cn_init_1551;
(f[1]=(f[1]-v));
}
(r5=cn_bits(f[1]));
(f[0]=f[0]);
{
__auto_type cn_init_1591 = 0x0U; __auto_type bv = cn_init_1591;
__auto_type cn_init_1608 = (((uint32_t)(((((v21>>32))&0xffffffffULL))))); __auto_type av = cn_init_1608;
__auto_type cn_init_1626 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1626;
}
if(cn_cond(fl,5)){
goto cn_break_b3;
}
(f[0]=cn_double(s2010));
(f[1]=cn_double(0x3ff0000000000000));
cn_swap(f,1,0);
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b5;
}
goto cn_break_b3;
}
cn_break_b5:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_1769 = cn_double(r10); __auto_type v = cn_init_1769;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1816 = cn_double(r11); __auto_type v = cn_init_1816;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_1863 = cn_double(r12); __auto_type v = cn_init_1863;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
goto cn_break_b7;
}
cn_break_b3:;
(f[0]=cn_double(s2010));
(f[1]=cn_double(v28));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b6;
}
(f[0]=cn_double(s2010));
{
__auto_type cn_init_2008 = cn_double(v28); __auto_type v = cn_init_2008;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_2044 = cn_double(v28); __auto_type v = cn_init_2044;
(f[1]=(f[1]-v));
}
(f[0]=(f[0]/f[1]));
(s2009=cn_bits(f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]-f[0]));
(s2008=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(r4));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v26));
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2011));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(v27));
(f[0]=(f[1]/f[0]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_2354 = cn_double(s2013); __auto_type v = cn_init_2354;
(f[0]=(f[0]/v));
}
(f[0]=(f[0]*f[0]));
(f[0]=-f[0]);
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2522 = cn_double(s2012); __auto_type v = cn_init_2522;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2546 = cn_double(s2011); __auto_type v = cn_init_2546;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_2582 = cn_double(r4); __auto_type v = cn_init_2582;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
{
__auto_type cn_init_2617 = cn_double(s2012); __auto_type v = cn_init_2617;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2641 = cn_double(s2011); __auto_type v = cn_init_2641;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
(f[2]=(f[2]+f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_2703 = cn_double(v22); __auto_type v = cn_init_2703;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_2727 = cn_double(s2013); __auto_type v = cn_init_2727;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_2751 = cn_double(s2011); __auto_type v = cn_init_2751;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_2775 = cn_double(s2008); __auto_type v = cn_init_2775;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r5));
{
__auto_type cn_init_2811 = cn_double(s2009); __auto_type v = cn_init_2811;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_2850 = cn_double(r12); __auto_type v = cn_init_2850;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_2885 = cn_double(s2008); __auto_type v = cn_init_2885;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r4));
{
__auto_type cn_init_2921 = cn_double(s2009); __auto_type v = cn_init_2921;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_2960 = cn_double(r11); __auto_type v = cn_init_2960;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_2995 = cn_double(s2008); __auto_type v = cn_init_2995;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_3031 = cn_double(s2009); __auto_type v = cn_init_3031;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3070 = cn_double(r10); __auto_type v = cn_init_3070;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
goto cn_break_b7;
}
cn_break_b6:;
(f[0]=cn_double(r4));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v26));
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2011));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(v27));
(f[0]=(f[1]/f[0]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_3321 = cn_double(s2013); __auto_type v = cn_init_3321;
(f[0]=(f[0]/v));
}
(f[0]=(f[0]*f[0]));
(f[0]=-f[0]);
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3489 = cn_double(s2012); __auto_type v = cn_init_3489;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3513 = cn_double(s2011); __auto_type v = cn_init_3513;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3537 = cn_double(r10); __auto_type v = cn_init_3537;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_3573 = cn_double(r4); __auto_type v = cn_init_3573;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
{
__auto_type cn_init_3608 = cn_double(s2012); __auto_type v = cn_init_3608;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3632 = cn_double(s2011); __auto_type v = cn_init_3632;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3656 = cn_double(r11); __auto_type v = cn_init_3656;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r5));
(f[2]=(f[2]+f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_3718 = cn_double(s2013); __auto_type v = cn_init_3718;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_3742 = cn_double(s2011); __auto_type v = cn_init_3742;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_3766 = cn_double(v22); __auto_type v = cn_init_3766;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_3790 = cn_double(r12); __auto_type v = cn_init_3790;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
}
cn_break_b7:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_3860 = cn_double(v25); __auto_type v = cn_init_3860;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_3907 = cn_double(v24); __auto_type v = cn_init_3907;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_3954 = cn_double(v23); __auto_type v = cn_init_3954;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s1996>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s1997>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s1997>>32))&0xffffffffULL)))));
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
cn_wr64u(m,0x10007e60U,s1996);
cn_wr64u(m,0x10007e68U,s1997);
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_84835daba033d91f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+160))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_214 = cn_cell(vm,0); uint64_t v20 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,8); uint64_t v21 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,16); uint64_t v22 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,24); uint64_t v23 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,32); uint64_t v24 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,40); uint64_t v25 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,48); uint64_t v26 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,56); uint64_t v27 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,64); uint64_t v28 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,72); uint64_t v29 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,80); uint64_t v30 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,96); uint64_t v32 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,104); uint64_t v33 = cn_init_370;
{
{
{
{
{
{
__auto_type cn_init_391 = 0xffffffe4U; __auto_type bv = cn_init_391;
__auto_type cn_init_399 = rg[4]; __auto_type av = cn_init_399;
__auto_type cn_init_417 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_417;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_446 = r5; uint64_t s = cn_init_446;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_476 = (CN_U2){v28,v29}; CN_U2 s = cn_init_476;
__auto_type cn_init_486 = m->xmm[0]; __auto_type a = cn_init_486;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_556 = v28; uint64_t s = cn_init_556;
__auto_type cn_init_569 = m->xmm[1][0]; __auto_type a = cn_init_569;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_616 = (CN_U2){v24,v25}; CN_U2 s = cn_init_616;
__auto_type cn_init_626 = m->xmm[0]; __auto_type a = cn_init_626;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_696 = v26; uint64_t s = cn_init_696;
__auto_type cn_init_709 = m->xmm[1][0]; __auto_type a = cn_init_709;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_746 = 0x0U; __auto_type bv = cn_init_746;
__auto_type cn_init_763 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_763;
__auto_type cn_init_781 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_781;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_802 = r32; uint64_t s = cn_init_802;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_824 = v28; uint64_t s = cn_init_824;
__auto_type cn_init_837 = m->xmm[5][0]; __auto_type a = cn_init_837;
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
(f[0]=cn_double(s2013));
(f[1]=cn_double(s2012));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1006 = cn_double(v32); __auto_type v = cn_init_1006;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1046 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1046;
(f[0]=(f[0]/v));
}
(f[1]=f[0]);
(f[1]=cn_round(m,f[1]));
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_1126 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1126;
(f[0]=(f[0]*v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1164 = cn_double(v30); __auto_type v = cn_init_1164;
(f[0]=(f[0]/v));
}
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_1215 = cn_double(v30); __auto_type v = cn_init_1215;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1239 = cn_double(v33); __auto_type v = cn_init_1239;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
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
__auto_type cn_init_1399 = cn_double(v23); __auto_type v = cn_init_1399;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_1439 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1439;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_1493 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1493;
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
__auto_type cn_init_1607 = 0x0U; __auto_type bv = cn_init_1607;
__auto_type cn_init_1624 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_1624;
__auto_type cn_init_1642 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1642;
}
if(cn_cond(fl,5)){
goto cn_break_b7;
}
{
__auto_type cn_init_1666 = cn_double(v28); __auto_type v = cn_init_1666;
(f[0]=(f[0]/v));
}
}
cn_break_b7:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_1697 = 0x1cU; __auto_type bv = cn_init_1697;
__auto_type cn_init_1705 = rg[4]; __auto_type av = cn_init_1705;
__auto_type cn_init_1723 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1723;
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
int cn_f_853f9148766ff293(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r6));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_715 = cn_double(v30); __auto_type v = cn_init_715;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_739 = cn_double(r10); __auto_type v = cn_init_739;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_775 = cn_double(r4); __auto_type v = cn_init_775;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_811 = cn_double(r6); __auto_type v = cn_init_811;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
{
__auto_type cn_init_850 = cn_double(v29); __auto_type v = cn_init_850;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_874 = cn_double(r11); __auto_type v = cn_init_874;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_910 = cn_double(r5); __auto_type v = cn_init_910;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_934 = cn_double(v28); __auto_type v = cn_init_934;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r4));
{
__auto_type cn_init_970 = cn_double(r6); __auto_type v = cn_init_970;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_994 = cn_double(v27); __auto_type v = cn_init_994;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_1033 = cn_double(r12); __auto_type v = cn_init_1033;
(f[2]=(f[2]+v));
}
(f[3]=cn_double(r3));
{
__auto_type cn_init_1069 = cn_double(r6); __auto_type v = cn_init_1069;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r4));
{
__auto_type cn_init_1105 = cn_double(r5); __auto_type v = cn_init_1105;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_1144 = cn_double(v26); __auto_type v = cn_init_1144;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_1168 = cn_double(r0); __auto_type v = cn_init_1168;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_1192 = cn_double(v25); __auto_type v = cn_init_1192;
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
int cn_f_85561b59b53d06b0(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+224))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_122;
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
(f[0]=cn_double(r10));
{
__auto_type cn_init_428 = cn_double(v30); __auto_type v = cn_init_428;
(f[0]=(f[0]*v));
}
(r10=cn_bits(f[0]));
(f[0]=cn_double(r11));
{
__auto_type cn_init_475 = cn_double(v29); __auto_type v = cn_init_475;
(f[0]=(f[0]*v));
}
(r11=cn_bits(f[0]));
(f[0]=cn_double(r12));
{
__auto_type cn_init_522 = cn_double(v28); __auto_type v = cn_init_522;
(f[0]=(f[0]*v));
}
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
int cn_f_856a2efce798530c(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=f[0]);
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(f[0]=cn_double(v27));
(f[0]=(f[0]+f[0]));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(r6));
(f[2]=f[1]);
(f[2]=(f[2]/f[0]));
(f[2]=cn_round(m,f[2]));
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]-f[2]));
(f[0]=f[1]);
(f[0]=-f[0]);
(f[1]=f[0]);
(f[1]=-f[1]);
{
__auto_type cn_init_828 = cn_double(v27); __auto_type v = cn_init_828;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
(f[2]=f[0]);
(f[2]=-f[2]);
{
__auto_type cn_init_887 = cn_double(v27); __auto_type v = cn_init_887;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(r6=cn_bits(f[0]));
}
cn_break_b2:;
(f[0]=cn_double(v28));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1028 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1028;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
(f[0]=f[0]);
if(cn_cond(fl,4)){
goto cn_break_b4;
}
(f[0]=cn_double(v28));
(f[0]=(f[0]+f[0]));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(r5));
(f[2]=f[1]);
(f[2]=(f[2]/f[0]));
(f[2]=cn_round(m,f[2]));
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]-f[2]));
(f[0]=f[1]);
(f[0]=-f[0]);
(f[1]=f[0]);
(f[1]=-f[1]);
{
__auto_type cn_init_1278 = cn_double(v28); __auto_type v = cn_init_1278;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
(f[2]=f[0]);
(f[2]=-f[2]);
{
__auto_type cn_init_1337 = cn_double(v28); __auto_type v = cn_init_1337;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(r5=cn_bits(f[0]));
}
cn_break_b4:;
(f[0]=cn_double(v29));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1478 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1478;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
(f[0]=f[0]);
if(cn_cond(fl,4)){
goto cn_break_b6;
}
(f[0]=cn_double(v29));
(f[0]=(f[0]+f[0]));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(r4));
(f[2]=f[1]);
(f[2]=(f[2]/f[0]));
(f[2]=cn_round(m,f[2]));
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]-f[2]));
(f[0]=f[1]);
(f[0]=-f[0]);
(f[1]=f[0]);
(f[1]=-f[1]);
{
__auto_type cn_init_1728 = cn_double(v29); __auto_type v = cn_init_1728;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
(f[2]=f[0]);
(f[2]=-f[2]);
{
__auto_type cn_init_1787 = cn_double(v29); __auto_type v = cn_init_1787;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(r4=cn_bits(f[0]));
}
cn_break_b6:;
(f[0]=cn_double(v30));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1928 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1928;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
(f[0]=f[0]);
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[0]=cn_double(v30));
(f[0]=(f[0]+f[0]));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(r3));
(f[2]=f[1]);
(f[2]=(f[2]/f[0]));
(f[2]=cn_round(m,f[2]));
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]-f[2]));
(f[0]=f[1]);
(f[0]=-f[0]);
(f[1]=f[0]);
(f[1]=-f[1]);
{
__auto_type cn_init_2178 = cn_double(v30); __auto_type v = cn_init_2178;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
(f[2]=f[0]);
(f[2]=-f[2]);
{
__auto_type cn_init_2237 = cn_double(v30); __auto_type v = cn_init_2237;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
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
int cn_f_857d56de27b2f9d7(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_175 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,0); uint64_t v18 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,8); uint64_t v19 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,16); uint64_t v20 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,24); uint64_t v21 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,32); uint64_t v22 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,40); uint64_t v23 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,48); uint64_t v24 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,56); uint64_t v25 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,64); uint64_t v26 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,72); uint64_t v27 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,80); uint64_t v28 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,88); uint64_t v29 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,96); uint64_t v30 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,112); uint64_t v32 = cn_init_383;
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
__auto_type cn_init_416 = 0xffffffe4U; __auto_type bv = cn_init_416;
__auto_type cn_init_424 = rg[4]; __auto_type av = cn_init_424;
__auto_type cn_init_442 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_442;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_471 = r5; uint64_t s = cn_init_471;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_501 = (CN_U2){v28,v29}; CN_U2 s = cn_init_501;
__auto_type cn_init_511 = m->xmm[0]; __auto_type a = cn_init_511;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_581 = v28; uint64_t s = cn_init_581;
__auto_type cn_init_594 = m->xmm[1][0]; __auto_type a = cn_init_594;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_641 = (CN_U2){v24,v25}; CN_U2 s = cn_init_641;
__auto_type cn_init_651 = m->xmm[0]; __auto_type a = cn_init_651;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_721 = v26; uint64_t s = cn_init_721;
__auto_type cn_init_734 = m->xmm[1][0]; __auto_type a = cn_init_734;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_771 = 0x0U; __auto_type bv = cn_init_771;
__auto_type cn_init_788 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_788;
__auto_type cn_init_806 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_806;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_827 = r32; uint64_t s = cn_init_827;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_849 = v28; uint64_t s = cn_init_849;
__auto_type cn_init_862 = m->xmm[5][0]; __auto_type a = cn_init_862;
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
__auto_type cn_init_984 = 0xffffffd4U; __auto_type bv = cn_init_984;
__auto_type cn_init_992 = rg[7]; __auto_type av = cn_init_992;
__auto_type cn_init_1010 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1010;
(rg[7]=r);
}
(f[0]=cn_double(s2014));
(f[1]=cn_double(s2013));
(f[2]=cn_double(s2012));
(f[3]=f[2]);
{
__auto_type cn_init_1089 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1089;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1137 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1137;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1200 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1200;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1263 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1263;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1311 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1311;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1374 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1374;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1436 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1436;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1483 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1483;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1545 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1545;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(s2012=cn_bits(f[2]));
(s2013=cn_bits(f[1]));
(s2014=cn_bits(f[0]));
{
__auto_type cn_init_1612 = 0x2cU; __auto_type bv = cn_init_1612;
__auto_type cn_init_1620 = rg[7]; __auto_type av = cn_init_1620;
__auto_type cn_init_1638 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1638;
(rg[7]=r);
}
(f[0]=cn_double(s2012));
(f[0]=cos(f[0]));
(fsw&=~0x0400);
(f[1]=cn_double(s2013));
(f[1]=cos(f[1]));
(fsw&=~0x0400);
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(v30));
cn_swap(f,1,0);
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
{
__auto_type cn_init_1783 = cn_double(v23); __auto_type v = cn_init_1783;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1807 = cn_double(s2014); __auto_type v = cn_init_1807;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2014));
(f[1]=fabs(f[1]));
(f[2]=cn_double(s2013));
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
(f[2]=cn_double(s2012));
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
(f[2]=cn_double(v32));
(f[1]=(f[1]-f[2]));
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
__auto_type cn_init_2216 = 0x0U; __auto_type bv = cn_init_2216;
__auto_type cn_init_2233 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_2233;
__auto_type cn_init_2251 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2251;
}
if(cn_cond(fl,5)){
goto cn_break_b13;
}
{
__auto_type cn_init_2275 = cn_double(v28); __auto_type v = cn_init_2275;
(f[0]=(f[0]/v));
}
}
cn_break_b13:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2306 = 0x1cU; __auto_type bv = cn_init_2306;
__auto_type cn_init_2314 = rg[4]; __auto_type av = cn_init_2314;
__auto_type cn_init_2332 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2332;
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
int cn_f_85cf25270cf6b0b0(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_220 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_220;
__auto_type cn_init_233 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_233;
__auto_type cn_init_246 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_246;
__auto_type cn_init_259 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_259;
__auto_type cn_init_272 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_272;
__auto_type cn_init_285 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_285;
__auto_type cn_init_298 = cn_cell(vm,0); uint64_t v19 = cn_init_298;
__auto_type cn_init_311 = cn_cell(vm,8); uint64_t v20 = cn_init_311;
__auto_type cn_init_324 = cn_cell(vm,16); uint64_t v21 = cn_init_324;
__auto_type cn_init_337 = cn_cell(vm,24); uint64_t v22 = cn_init_337;
__auto_type cn_init_350 = cn_cell(vm,32); uint64_t v23 = cn_init_350;
__auto_type cn_init_363 = cn_cell(vm,40); uint64_t v24 = cn_init_363;
__auto_type cn_init_376 = cn_cell(vm,48); uint64_t v25 = cn_init_376;
__auto_type cn_init_389 = cn_cell(vm,56); uint64_t v26 = cn_init_389;
__auto_type cn_init_402 = cn_cell(vm,64); uint64_t v27 = cn_init_402;
__auto_type cn_init_415 = cn_cell(vm,72); uint64_t v28 = cn_init_415;
__auto_type cn_init_428 = cn_cell(vm,80); uint64_t v29 = cn_init_428;
__auto_type cn_init_441 = cn_cell(vm,88); uint64_t v30 = cn_init_441;
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
__auto_type cn_init_594 = 0x3cU; __auto_type bv = cn_init_594;
__auto_type cn_init_602 = rg[4]; __auto_type av = cn_init_602;
__auto_type cn_init_620 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_620;
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
(rg[7]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_819 = 0x80U; __auto_type bv = cn_init_819;
__auto_type cn_init_827 = rg[7]; __auto_type av = cn_init_827;
__auto_type cn_init_845 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_845;
(rg[7]=r);
}
(f[0]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008022U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_931 = 0x0U; __auto_type v = cn_init_931;
(rg[0]=v);
}
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
(f[1]=cn_double(r3));
(f[1]=fabs(f[1]));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b6;
}
{
__auto_type cn_init_1083 = (((uint32_t)(((((s2013>>0))&0xffffffffULL))))); __auto_type v = cn_init_1083;
__auto_type cn_init_1090 = fl.cf; __auto_type cf = cn_init_1090;
__auto_type cn_init_1108 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_1108;
(fl.cf=cf);
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
}
cn_break_b6:;
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b10;
}
{
__auto_type cn_init_1259 = (((uint32_t)(((((s2013>>0))&0xffffffffULL))))); __auto_type v = cn_init_1259;
__auto_type cn_init_1266 = fl.cf; __auto_type cf = cn_init_1266;
__auto_type cn_init_1284 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_1284;
(fl.cf=cf);
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
}
cn_break_b10:;
(f[1]=cn_double(r5));
(f[1]=fabs(f[1]));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b14;
}
{
__auto_type cn_init_1435 = (((uint32_t)(((((s2013>>0))&0xffffffffULL))))); __auto_type v = cn_init_1435;
__auto_type cn_init_1442 = fl.cf; __auto_type cf = cn_init_1442;
__auto_type cn_init_1460 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_1460;
(fl.cf=cf);
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
}
cn_break_b14:;
(rg[0]=((uint32_t)(((((v19>>0))&0xffffffffULL)))));
{
__auto_type cn_init_1520 = 0x3U; __auto_type bv = cn_init_1520;
__auto_type cn_init_1528 = rg[0]; __auto_type av = cn_init_1528;
__auto_type cn_init_1546 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1546;
(rg[0]=r);
}
{
__auto_type cn_init_1572 = (((uint32_t)(((((s2013>>0))&0xffffffffULL))))); __auto_type bv = cn_init_1572;
__auto_type cn_init_1580 = rg[0]; __auto_type av = cn_init_1580;
__auto_type cn_init_1598 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_1598;
(rg[0]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b36;
}
{
__auto_type cn_init_1645 = cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1645;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b20;
}
(f[2]=cn_double(0x3ff0000000000000));
goto cn_break_b22;
}
cn_break_b20:;
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=-f[2]);
}
cn_break_b22:;
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]-f[2]));
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b26;
}
(f[2]=cn_double(0x3ff0000000000000));
goto cn_break_b28;
}
cn_break_b26:;
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=-f[2]);
}
cn_break_b28:;
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]-f[2]));
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b32;
}
(f[2]=cn_double(0x3ff0000000000000));
goto cn_break_b34;
}
cn_break_b32:;
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=-f[2]);
}
cn_break_b34:;
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]-f[2]));
(r5=cn_bits(f[1]));
}
cn_break_b36:;
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
(f[2]=cn_double(r5));
(f[3]=f[2]);
{
__auto_type cn_init_2280 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2280;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_2328 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2328;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2391 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2391;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_2454 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2454;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_2502 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2502;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2565 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2565;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_2627 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2627;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_2674 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2674;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2736 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2736;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
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
goto cn_break_b40;
}
(f[3]=-f[3]);
(f[3]=(f[3]+f[0]));
goto cn_break_b42;
}
cn_break_b40:;
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b42;
}
(f[3]=-f[3]);
(f[3]=(f[3]-f[0]));
}
cn_break_b42:;
(f[4]=cn_double(r4));
(fsw=cn_compare(f[4],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b44;
}
(f[4]=-f[4]);
(f[4]=(f[4]+f[0]));
goto cn_break_b46;
}
cn_break_b44:;
(fsw=cn_compare(f[4],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b46;
}
(f[4]=-f[4]);
(f[4]=(f[4]-f[0]));
}
cn_break_b46:;
(f[5]=cn_double(r5));
(fsw=cn_compare(f[5],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b48;
}
(f[5]=-f[5]);
(f[5]=(f[5]+f[0]));
goto cn_break_b50;
}
cn_break_b48:;
(fsw=cn_compare(f[5],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b50;
}
(f[5]=-f[5]);
(f[5]=(f[5]-f[0]));
}
cn_break_b50:;
cn_swap(f,5,2);
(f[5]=f[5]);
cn_swap(f,4,1);
(f[4]=f[4]);
cn_swap(f,3,0);
(f[3]=f[3]);
(f[3]=f[2]);
{
__auto_type cn_init_3574 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3574;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_3622 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3622;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_3685 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3685;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_3748 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3748;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_3796 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3796;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_3859 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3859;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_3921 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3921;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_3968 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3968;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_4030 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4030;
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
(fsw=cn_compare(f[3],cn_double(v28)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b52;
}
(f[3]=f[3]);
(f[3]=cn_double(v29));
goto cn_break_b55;
}
cn_break_b52:;
(f[4]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b54;
}
(f[4]=f[4]);
{
__auto_type cn_init_4364 = cn_double(v30); __auto_type v = cn_init_4364;
(f[3]=(v/f[3]));
}
goto cn_break_b55;
}
cn_break_b54:;
(fsw=cn_compare(f[4],f[3]));
(f[3]=cn_double(v30));
}
cn_break_b55:;
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[3]));
(r6=cn_bits(f[4]));
(f[0]=(f[0]*f[3]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
{
__auto_type cn_init_4503 = cn_double(r12); __auto_type v = cn_init_4503;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_4538 = cn_double(r11); __auto_type v = cn_init_4538;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_4573 = cn_double(r10); __auto_type v = cn_init_4573;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000820dU))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_4675 = 0x0U; __auto_type v = cn_init_4675;
(rg[0]=v);
}
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
(f[1]=cn_double(r3));
(f[1]=fabs(f[1]));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b7;
}
{
__auto_type cn_init_4827 = (((uint32_t)(((((s2013>>0))&0xffffffffULL))))); __auto_type v = cn_init_4827;
__auto_type cn_init_4834 = fl.cf; __auto_type cf = cn_init_4834;
__auto_type cn_init_4852 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_4852;
(fl.cf=cf);
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
}
cn_break_b7:;
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b11;
}
{
__auto_type cn_init_5003 = (((uint32_t)(((((s2013>>0))&0xffffffffULL))))); __auto_type v = cn_init_5003;
__auto_type cn_init_5010 = fl.cf; __auto_type cf = cn_init_5010;
__auto_type cn_init_5028 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_5028;
(fl.cf=cf);
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
}
cn_break_b11:;
(f[1]=cn_double(r5));
(f[1]=fabs(f[1]));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b15;
}
{
__auto_type cn_init_5179 = (((uint32_t)(((((s2013>>0))&0xffffffffULL))))); __auto_type v = cn_init_5179;
__auto_type cn_init_5186 = fl.cf; __auto_type cf = cn_init_5186;
__auto_type cn_init_5204 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_5204;
(fl.cf=cf);
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
}
cn_break_b15:;
(rg[0]=((uint32_t)(((((v19>>0))&0xffffffffULL)))));
{
__auto_type cn_init_5264 = 0x3U; __auto_type bv = cn_init_5264;
__auto_type cn_init_5272 = rg[0]; __auto_type av = cn_init_5272;
__auto_type cn_init_5290 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_5290;
(rg[0]=r);
}
{
__auto_type cn_init_5316 = (((uint32_t)(((((s2013>>0))&0xffffffffULL))))); __auto_type bv = cn_init_5316;
__auto_type cn_init_5324 = rg[0]; __auto_type av = cn_init_5324;
__auto_type cn_init_5342 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_5342;
(rg[0]=r);
}
if(cn_cond(fl,5)){
goto cn_break_b37;
}
{
__auto_type cn_init_5389 = cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5389;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b21;
}
(f[2]=cn_double(0x3ff0000000000000));
goto cn_break_b23;
}
cn_break_b21:;
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=-f[2]);
}
cn_break_b23:;
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]-f[2]));
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b27;
}
(f[2]=cn_double(0x3ff0000000000000));
goto cn_break_b29;
}
cn_break_b27:;
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=-f[2]);
}
cn_break_b29:;
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]-f[2]));
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b33;
}
(f[2]=cn_double(0x3ff0000000000000));
goto cn_break_b35;
}
cn_break_b33:;
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=-f[2]);
}
cn_break_b35:;
(f[2]=(f[2]*f[0]));
(f[1]=(f[1]-f[2]));
(r5=cn_bits(f[1]));
}
cn_break_b37:;
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007ea0U,s2004);
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_85d0642781938c8d(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_175 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,0); uint64_t v19 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,8); uint64_t v20 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,16); uint64_t v21 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,24); uint64_t v22 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,32); uint64_t v23 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,40); uint64_t v24 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,48); uint64_t v25 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,56); uint64_t v26 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,64); uint64_t v27 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,72); uint64_t v28 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,80); uint64_t v29 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,88); uint64_t v30 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,104); uint64_t v32 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,112); uint64_t v33 = cn_init_396;
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
__auto_type cn_init_432 = 0xffffffbaU; __auto_type bv = cn_init_432;
__auto_type cn_init_440 = rg[4]; __auto_type av = cn_init_440;
__auto_type cn_init_458 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_458;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_487 = r5; uint64_t s = cn_init_487;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_517 = (CN_U2){v28,v29}; CN_U2 s = cn_init_517;
__auto_type cn_init_527 = m->xmm[0]; __auto_type a = cn_init_527;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_597 = v28; uint64_t s = cn_init_597;
__auto_type cn_init_610 = m->xmm[1][0]; __auto_type a = cn_init_610;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_657 = (CN_U2){v24,v25}; CN_U2 s = cn_init_657;
__auto_type cn_init_667 = m->xmm[0]; __auto_type a = cn_init_667;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_737 = v26; uint64_t s = cn_init_737;
__auto_type cn_init_750 = m->xmm[1][0]; __auto_type a = cn_init_750;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_787 = 0x0U; __auto_type bv = cn_init_787;
__auto_type cn_init_804 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_804;
__auto_type cn_init_822 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_822;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_843 = r32; uint64_t s = cn_init_843;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_865 = v28; uint64_t s = cn_init_865;
__auto_type cn_init_878 = m->xmm[5][0]; __auto_type a = cn_init_878;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_974 = m->xmm[0][0]; uint64_t v = cn_init_974;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1033 = m->xmm[0][1]; uint64_t v = cn_init_1033;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1092 = m->xmm[1][0]; uint64_t v = cn_init_1092;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1141 = 0x1U; __auto_type bv = cn_init_1141;
__auto_type cn_init_1158 = (((uint32_t)(((((v20>>0))&0xffffffffULL))))); __auto_type av = cn_init_1158;
__auto_type cn_init_1176 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1176;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1260 = cn_bits(f[1]); uint64_t v = cn_init_1260;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1318 = cn_bits(f[0]); uint64_t v = cn_init_1318;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b4:;
{
__auto_type cn_init_1368 = 0xffffffffU; __auto_type bv = cn_init_1368;
__auto_type cn_init_1385 = (((uint32_t)(((((v20>>0))&0xffffffffULL))))); __auto_type av = cn_init_1385;
__auto_type cn_init_1403 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1403;
}
if(cn_cond(fl,5)){
goto cn_break_b6;
}
(f[0]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1487 = cn_bits(f[1]); uint64_t v = cn_init_1487;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1545 = cn_bits(f[0]); uint64_t v = cn_init_1545;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b6:;
{
__auto_type cn_init_1595 = 0x0U; __auto_type bv = cn_init_1595;
__auto_type cn_init_1612 = (((uint32_t)(((((v19>>32))&0xffffffffULL))))); __auto_type av = cn_init_1612;
__auto_type cn_init_1630 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1630;
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[0]=-f[0]);
{
__auto_type cn_init_1697 = cn_bits(f[0]); uint64_t v = cn_init_1697;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
}
cn_break_b8:;
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_1857 = cn_bits(f[0]); uint64_t v = cn_init_1857;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1929 = cn_bits(f[0]); uint64_t v = cn_init_1929;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(v30));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_2026 = cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2026;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=f[0]);
{
__auto_type cn_init_2113 = cn_double(v30); __auto_type v = cn_init_2113;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2153 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2153;
(f[1]=(f[1]/v));
}
(f[2]=cn_double(0x3fe62e42fefa39ef));
cn_swap(f,2,1);
(f[1]*=log2(f[2]));
{
__auto_type cn_init_2212 = cn_double(v30); __auto_type v = cn_init_2212;
(f[1]=(f[1]*v));
}
cn_swap(f,1,0);
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2287 = cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2287;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_2341 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2341;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2393 = cn_double(v32); __auto_type v = cn_init_2393;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2417 = cn_double(v33); __auto_type v = cn_init_2417;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2498 = cn_double(v23); __auto_type v = cn_init_2498;
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
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2661 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2661;
(f[1]=(v-f[1]));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b13;
}
(f[1]=f[1]);
goto cn_break_b14;
}
cn_break_b13:;
(f[0]=f[1]);
}
cn_break_b14:;
{
__auto_type cn_init_2775 = 0x0U; __auto_type bv = cn_init_2775;
__auto_type cn_init_2792 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_2792;
__auto_type cn_init_2810 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2810;
}
if(cn_cond(fl,5)){
goto cn_break_b16;
}
{
__auto_type cn_init_2834 = cn_double(v28); __auto_type v = cn_init_2834;
(f[0]=(f[0]/v));
}
}
cn_break_b16:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2865 = 0x46U; __auto_type bv = cn_init_2865;
__auto_type cn_init_2873 = rg[4]; __auto_type av = cn_init_2873;
__auto_type cn_init_2891 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2891;
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
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_85d2e5da4f43de0e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_169 = cn_rd64u(m,0x10007e98U); uint64_t s2003 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ea0U); uint64_t s2004 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ea8U); uint64_t s2005 = cn_init_195;
__auto_type cn_init_208 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_208;
__auto_type cn_init_221 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_221;
__auto_type cn_init_234 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_234;
__auto_type cn_init_247 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_247;
__auto_type cn_init_260 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,0); uint64_t v16 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,8); uint64_t v17 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,16); uint64_t v18 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,24); uint64_t v19 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,32); uint64_t v20 = cn_init_325;
__auto_type cn_init_338 = cn_cell(vm,40); uint64_t v21 = cn_init_338;
__auto_type cn_init_351 = cn_cell(vm,48); uint64_t v22 = cn_init_351;
__auto_type cn_init_364 = cn_cell(vm,56); uint64_t v23 = cn_init_364;
__auto_type cn_init_377 = cn_cell(vm,64); uint64_t v24 = cn_init_377;
__auto_type cn_init_390 = cn_cell(vm,72); uint64_t v25 = cn_init_390;
__auto_type cn_init_403 = cn_cell(vm,80); uint64_t v26 = cn_init_403;
__auto_type cn_init_416 = cn_cell(vm,88); uint64_t v27 = cn_init_416;
__auto_type cn_init_429 = cn_cell(vm,96); uint64_t v28 = cn_init_429;
__auto_type cn_init_442 = cn_cell(vm,104); uint64_t v29 = cn_init_442;
__auto_type cn_init_455 = cn_cell(vm,112); uint64_t v30 = cn_init_455;
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
__auto_type cn_init_587 = 0x40U; __auto_type bv = cn_init_587;
__auto_type cn_init_595 = rg[4]; __auto_type av = cn_init_595;
__auto_type cn_init_613 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_613;
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
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_877 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_877;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_925 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_925;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_988 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_988;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1051 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1051;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1099 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1099;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1162 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1162;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1224 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1224;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1271 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1271;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1333 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1333;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100080f5U))))&0xffffffffULL))<<0))));
(f[0]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_1461 = cn_double(v17); __auto_type v = cn_init_1461;
(f[0]=(f[0]-v));
}
(f[0]=-f[0]);
(s2013=cn_bits(f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(0x3ff0000000000000));
(f[0]=-f[0]);
(s2011=cn_bits(f[0]));
(f[0]=cn_double(s2013));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2012));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(s2011));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[1]=cn_double(s2013));
(f[1]=(f[1]*f[0]));
(s2013=cn_bits(f[1]));
(f[1]=cn_double(s2012));
(f[1]=(f[1]*f[0]));
(s2012=cn_bits(f[1]));
(f[1]=cn_double(s2011));
(f[1]=(f[1]*f[0]));
(s2011=cn_bits(f[1]));
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100080faU))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1926 = cn_double(s2013); __auto_type v = cn_init_1926;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1962 = cn_double(s2012); __auto_type v = cn_init_1962;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_1998 = cn_double(s2011); __auto_type v = cn_init_1998;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b15;
}
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b25;
}
cn_break_b15:;
(f[0]=(f[0]+f[0]));
(f[0]=-f[0]);
(f[1]=f[0]);
{
__auto_type cn_init_2184 = cn_double(s2013); __auto_type v = cn_init_2184;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2208 = cn_double(r3); __auto_type v = cn_init_2208;
(f[1]=(f[1]+v));
}
(r3=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_2253 = cn_double(s2012); __auto_type v = cn_init_2253;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2277 = cn_double(r4); __auto_type v = cn_init_2277;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_2312 = cn_double(s2011); __auto_type v = cn_init_2312;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2336 = cn_double(r5); __auto_type v = cn_init_2336;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b25:;
{
__auto_type cn_init_2382 = 0x0U; __auto_type bv = cn_init_2382;
__auto_type cn_init_2399 = (((uint32_t)(((((v16>>32))&0xffffffffULL))))); __auto_type av = cn_init_2399;
__auto_type cn_init_2417 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2417;
}
if(cn_cond(fl,5)){
goto cn_break_b27;
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008105U))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[1]);
{
__auto_type cn_init_2545 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2545;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_2593 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2593;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2656 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2656;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_2719 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2719;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_2767 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2767;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2830 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2830;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_2892 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2892;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_2939 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2939;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_3001 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3001;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b27:;
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x1000816bU))))&0xffffffffULL))<<0))));
(f[0]=cn_double(s2013));
(f[1]=cn_double(s2012));
(f[2]=cn_double(s2011));
(s2013=cn_bits(f[2]));
(s2011=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000811eU))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_3258 = cn_double(s2013); __auto_type v = cn_init_3258;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_3294 = cn_double(s2012); __auto_type v = cn_init_3294;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_3330 = cn_double(s2011); __auto_type v = cn_init_3330;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b16;
}
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b34;
}
cn_break_b16:;
(f[0]=(f[0]+f[0]));
(f[0]=-f[0]);
(f[1]=f[0]);
{
__auto_type cn_init_3516 = cn_double(s2013); __auto_type v = cn_init_3516;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3540 = cn_double(r3); __auto_type v = cn_init_3540;
(f[1]=(f[1]+v));
}
(r3=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_3585 = cn_double(s2012); __auto_type v = cn_init_3585;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3609 = cn_double(r4); __auto_type v = cn_init_3609;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_3644 = cn_double(s2011); __auto_type v = cn_init_3644;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_3668 = cn_double(r5); __auto_type v = cn_init_3668;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b34:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_3729 = 0x1U; __auto_type bv = cn_init_3729;
__auto_type cn_init_3746 = (((uint32_t)(((((v16>>32))&0xffffffffULL))))); __auto_type av = cn_init_3746;
__auto_type cn_init_3764 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3764;
}
if(cn_cond(fl,5)){
goto cn_break_b51;
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008176U))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[1]);
{
__auto_type cn_init_3892 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3892;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_3940 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3940;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_4003 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4003;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_4066 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4066;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_4114 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4114;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_4177 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4177;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_4239 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4239;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_4286 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4286;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_4348 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4348;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b51:;
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x1000817bU))))&0xffffffffULL))<<0))));
(f[0]=cn_double(s2013));
(f[1]=cn_double(s2012));
(f[2]=cn_double(s2011));
(s2013=cn_bits(f[2]));
(s2011=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000811eU))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_4605 = cn_double(s2013); __auto_type v = cn_init_4605;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_4641 = cn_double(s2012); __auto_type v = cn_init_4641;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_4677 = cn_double(s2011); __auto_type v = cn_init_4677;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b17;
}
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b35;
}
cn_break_b17:;
(f[0]=(f[0]+f[0]));
(f[0]=-f[0]);
(f[1]=f[0]);
{
__auto_type cn_init_4863 = cn_double(s2013); __auto_type v = cn_init_4863;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4887 = cn_double(r3); __auto_type v = cn_init_4887;
(f[1]=(f[1]+v));
}
(r3=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_4932 = cn_double(s2012); __auto_type v = cn_init_4932;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_4956 = cn_double(r4); __auto_type v = cn_init_4956;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_4991 = cn_double(s2011); __auto_type v = cn_init_4991;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5015 = cn_double(r5); __auto_type v = cn_init_5015;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b35:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_5076 = 0x2U; __auto_type bv = cn_init_5076;
__auto_type cn_init_5093 = (((uint32_t)(((((v16>>32))&0xffffffffULL))))); __auto_type av = cn_init_5093;
__auto_type cn_init_5111 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_5111;
}
if(cn_cond(fl,5)){
goto cn_break_b54;
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008186U))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[1]);
{
__auto_type cn_init_5239 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5239;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_5287 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5287;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_5350 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5350;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_5413 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5413;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_5461 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5461;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_5524 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5524;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_5586 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5586;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_5633 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_5633;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_5695 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_5695;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b54:;
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x1000818bU))))&0xffffffffULL))<<0))));
(f[0]=cn_double(s2013));
(f[1]=cn_double(s2012));
(f[2]=cn_double(s2011));
(s2013=cn_bits(f[2]));
(s2011=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000811eU))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_5952 = cn_double(s2013); __auto_type v = cn_init_5952;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_5988 = cn_double(s2012); __auto_type v = cn_init_5988;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_6024 = cn_double(s2011); __auto_type v = cn_init_6024;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b18;
}
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b36;
}
cn_break_b18:;
(f[0]=(f[0]+f[0]));
(f[0]=-f[0]);
(f[1]=f[0]);
{
__auto_type cn_init_6210 = cn_double(s2013); __auto_type v = cn_init_6210;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_6234 = cn_double(r3); __auto_type v = cn_init_6234;
(f[1]=(f[1]+v));
}
(r3=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_6279 = cn_double(s2012); __auto_type v = cn_init_6279;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_6303 = cn_double(r4); __auto_type v = cn_init_6303;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_6338 = cn_double(s2011); __auto_type v = cn_init_6338;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_6362 = cn_double(r5); __auto_type v = cn_init_6362;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b36:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_6423 = 0x3U; __auto_type bv = cn_init_6423;
__auto_type cn_init_6440 = (((uint32_t)(((((v16>>32))&0xffffffffULL))))); __auto_type av = cn_init_6440;
__auto_type cn_init_6458 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_6458;
}
if(cn_cond(fl,5)){
goto cn_break_b57;
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008196U))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[1]);
{
__auto_type cn_init_6586 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_6586;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_6634 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_6634;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_6697 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_6697;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_6760 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_6760;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_6808 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_6808;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_6871 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_6871;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_6933 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_6933;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_6980 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_6980;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_7042 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_7042;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b57:;
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x1000819bU))))&0xffffffffULL))<<0))));
(f[0]=cn_double(s2013));
(f[1]=cn_double(s2012));
(f[2]=cn_double(s2011));
(s2013=cn_bits(f[2]));
(s2011=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000811eU))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_7299 = cn_double(s2013); __auto_type v = cn_init_7299;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_7335 = cn_double(s2012); __auto_type v = cn_init_7335;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_7371 = cn_double(s2011); __auto_type v = cn_init_7371;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b19;
}
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b37;
}
cn_break_b19:;
(f[0]=(f[0]+f[0]));
(f[0]=-f[0]);
(f[1]=f[0]);
{
__auto_type cn_init_7557 = cn_double(s2013); __auto_type v = cn_init_7557;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_7581 = cn_double(r3); __auto_type v = cn_init_7581;
(f[1]=(f[1]+v));
}
(r3=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_7626 = cn_double(s2012); __auto_type v = cn_init_7626;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_7650 = cn_double(r4); __auto_type v = cn_init_7650;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_7685 = cn_double(s2011); __auto_type v = cn_init_7685;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_7709 = cn_double(r5); __auto_type v = cn_init_7709;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b37:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_7770 = 0x4U; __auto_type bv = cn_init_7770;
__auto_type cn_init_7787 = (((uint32_t)(((((v16>>32))&0xffffffffULL))))); __auto_type av = cn_init_7787;
__auto_type cn_init_7805 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_7805;
}
if(cn_cond(fl,5)){
goto cn_break_b60;
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100081a6U))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[1]);
{
__auto_type cn_init_7933 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_7933;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_7981 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_7981;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_8044 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_8044;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_8107 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_8107;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_8155 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_8155;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_8218 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_8218;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_8280 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_8280;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_8327 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_8327;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_8389 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_8389;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b60:;
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100081abU))))&0xffffffffULL))<<0))));
(f[0]=cn_double(s2013));
(f[1]=cn_double(s2012));
(f[2]=cn_double(s2011));
(s2013=cn_bits(f[2]));
(s2011=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000811eU))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_8646 = cn_double(s2013); __auto_type v = cn_init_8646;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_8682 = cn_double(s2012); __auto_type v = cn_init_8682;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_8718 = cn_double(s2011); __auto_type v = cn_init_8718;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b20;
}
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b38;
}
cn_break_b20:;
(f[0]=(f[0]+f[0]));
(f[0]=-f[0]);
(f[1]=f[0]);
{
__auto_type cn_init_8904 = cn_double(s2013); __auto_type v = cn_init_8904;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_8928 = cn_double(r3); __auto_type v = cn_init_8928;
(f[1]=(f[1]+v));
}
(r3=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_8973 = cn_double(s2012); __auto_type v = cn_init_8973;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_8997 = cn_double(r4); __auto_type v = cn_init_8997;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_9032 = cn_double(s2011); __auto_type v = cn_init_9032;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_9056 = cn_double(r5); __auto_type v = cn_init_9056;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b38:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_9117 = 0x5U; __auto_type bv = cn_init_9117;
__auto_type cn_init_9134 = (((uint32_t)(((((v16>>32))&0xffffffffULL))))); __auto_type av = cn_init_9134;
__auto_type cn_init_9152 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_9152;
}
if(cn_cond(fl,5)){
goto cn_break_b63;
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100081b6U))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[1]);
{
__auto_type cn_init_9280 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_9280;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_9328 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_9328;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_9391 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_9391;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_9454 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_9454;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_9502 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_9502;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_9565 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_9565;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_9627 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_9627;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_9674 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_9674;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_9736 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_9736;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b63:;
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100081bbU))))&0xffffffffULL))<<0))));
(f[0]=cn_double(s2013));
(f[1]=cn_double(s2012));
(f[2]=cn_double(s2011));
(s2013=cn_bits(f[2]));
(s2011=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000811eU))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_9993 = cn_double(s2013); __auto_type v = cn_init_9993;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_10029 = cn_double(s2012); __auto_type v = cn_init_10029;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_10065 = cn_double(s2011); __auto_type v = cn_init_10065;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b21;
}
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b39;
}
cn_break_b21:;
(f[0]=(f[0]+f[0]));
(f[0]=-f[0]);
(f[1]=f[0]);
{
__auto_type cn_init_10251 = cn_double(s2013); __auto_type v = cn_init_10251;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_10275 = cn_double(r3); __auto_type v = cn_init_10275;
(f[1]=(f[1]+v));
}
(r3=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_10320 = cn_double(s2012); __auto_type v = cn_init_10320;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_10344 = cn_double(r4); __auto_type v = cn_init_10344;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_10379 = cn_double(s2011); __auto_type v = cn_init_10379;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_10403 = cn_double(r5); __auto_type v = cn_init_10403;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b39:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_10464 = 0x6U; __auto_type bv = cn_init_10464;
__auto_type cn_init_10481 = (((uint32_t)(((((v16>>32))&0xffffffffULL))))); __auto_type av = cn_init_10481;
__auto_type cn_init_10499 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_10499;
}
if(cn_cond(fl,5)){
goto cn_break_b66;
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100081c6U))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[1]);
{
__auto_type cn_init_10627 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_10627;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_10675 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_10675;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_10738 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_10738;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_10801 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_10801;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_10849 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_10849;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_10912 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_10912;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_10974 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_10974;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_11021 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_11021;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_11083 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_11083;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b66:;
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
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
__auto_type cn_init_11349 = cn_double(v29); __auto_type v = cn_init_11349;
(f[5]=(f[5]*v));
}
(f[1]=(f[1]-f[5]));
{
__auto_type cn_init_11388 = cn_double(v28); __auto_type v = cn_init_11388;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]-f[4]));
{
__auto_type cn_init_11427 = cn_double(v27); __auto_type v = cn_init_11427;
(f[3]=(f[3]*v));
}
(f[0]=(f[0]-f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
{
__auto_type cn_init_11494 = 0x7U; __auto_type bv = cn_init_11494;
__auto_type cn_init_11511 = (((uint32_t)(((((v16>>32))&0xffffffffULL))))); __auto_type av = cn_init_11511;
__auto_type cn_init_11529 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_11529;
}
if(cn_cond(fl,5)){
goto cn_break_b68;
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2004=(((s2004&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008205U))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[1]);
{
__auto_type cn_init_11657 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_11657;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_11705 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_11705;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_11768 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_11768;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_11831 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_11831;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_11879 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_11879;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_11942 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_11942;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_12004 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_12004;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_12051 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_12051;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_12113 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_12113;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b68:;
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64u(m,0x10007e98U,s2003);
cn_wr64u(m,0x10007ea0U,s2004);
cn_wr64u(m,0x10007ea8U,s2005);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_862fd5f9a2ee5d0e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+168))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_255 = cn_cell(vm,0); uint64_t v21 = cn_init_255;
__auto_type cn_init_268 = cn_cell(vm,8); uint64_t v22 = cn_init_268;
__auto_type cn_init_281 = cn_cell(vm,16); uint64_t v23 = cn_init_281;
__auto_type cn_init_294 = cn_cell(vm,24); uint64_t v24 = cn_init_294;
__auto_type cn_init_307 = cn_cell(vm,32); uint64_t v25 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,40); uint64_t v26 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,48); uint64_t v27 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,56); uint64_t v28 = cn_init_346;
__auto_type cn_init_359 = cn_cell(vm,64); uint64_t v29 = cn_init_359;
__auto_type cn_init_372 = cn_cell(vm,72); uint64_t v30 = cn_init_372;
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
__auto_type cn_init_701 = 0x1U; __auto_type bv = cn_init_701;
__auto_type cn_init_718 = (((uint32_t)(((((v21>>0))&0xffffffffULL))))); __auto_type av = cn_init_718;
__auto_type cn_init_736 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_736;
}
if(cn_cond(fl,5)){
goto cn_break_b8;
}
(f[0]=cn_double(r3));
{
__auto_type cn_init_772 = cn_double(v30); __auto_type v = cn_init_772;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_822 = cn_double(v29); __auto_type v = cn_init_822;
(f[1]=(f[1]-v));
}
(f[1]=fabs(f[1]));
(f[2]=cn_double(r5));
{
__auto_type cn_init_872 = cn_double(v28); __auto_type v = cn_init_872;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_942 = 0x41U; __auto_type bv = cn_init_942;
__auto_type cn_init_955 = cn_reg_get(rg,4,1); __auto_type av = cn_init_955;
__auto_type cn_init_973 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_973;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b3;
}
(f[1]=f[2]);
goto cn_break_b4;
}
cn_break_b3:;
(f[2]=f[2]);
}
cn_break_b4:;
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_1067 = 0x41U; __auto_type bv = cn_init_1067;
__auto_type cn_init_1080 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1080;
__auto_type cn_init_1098 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1098;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b6;
}
(f[0]=f[1]);
goto cn_break_b7;
}
cn_break_b6:;
(f[1]=f[1]);
}
cn_break_b7:;
goto cn_break_b29;
}
cn_break_b8:;
{
__auto_type cn_init_1159 = 0x2U; __auto_type bv = cn_init_1159;
__auto_type cn_init_1176 = (((uint32_t)(((((v21>>0))&0xffffffffULL))))); __auto_type av = cn_init_1176;
__auto_type cn_init_1194 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1194;
}
if(cn_cond(fl,5)){
goto cn_break_b10;
}
(f[0]=cn_double(r3));
{
__auto_type cn_init_1230 = cn_double(v30); __auto_type v = cn_init_1230;
(f[0]=(f[0]-v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_1281 = cn_double(v29); __auto_type v = cn_init_1281;
(f[1]=(f[1]-v));
}
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_1347 = cn_double(v28); __auto_type v = cn_init_1347;
(f[1]=(f[1]-v));
}
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]/f[1]));
(f[0]=sqrt(f[0]));
goto cn_break_b29;
}
cn_break_b10:;
{
__auto_type cn_init_1414 = 0x3U; __auto_type bv = cn_init_1414;
__auto_type cn_init_1431 = (((uint32_t)(((((v21>>0))&0xffffffffULL))))); __auto_type av = cn_init_1431;
__auto_type cn_init_1449 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1449;
}
if(cn_cond(fl,5)){
goto cn_break_b12;
}
(f[0]=cn_double(r3));
{
__auto_type cn_init_1485 = cn_double(v30); __auto_type v = cn_init_1485;
(f[0]=(f[0]-v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_1536 = cn_double(v29); __auto_type v = cn_init_1536;
(f[1]=(f[1]-v));
}
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
goto cn_break_b29;
}
cn_break_b12:;
{
__auto_type cn_init_1603 = 0xfffffffeU; __auto_type bv = cn_init_1603;
__auto_type cn_init_1620 = (((uint32_t)(((((v21>>0))&0xffffffffULL))))); __auto_type av = cn_init_1620;
__auto_type cn_init_1638 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1638;
}
if(cn_cond(fl,5)){
goto cn_break_b16;
}
(f[0]=cn_double(r5));
{
__auto_type cn_init_1674 = cn_double(v28); __auto_type v = cn_init_1674;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_1742 = 0x41U; __auto_type bv = cn_init_1742;
__auto_type cn_init_1755 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1755;
__auto_type cn_init_1773 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1773;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,6)){
goto cn_break_b15;
}
(f[0]=cn_double(r3));
{
__auto_type cn_init_1822 = cn_double(v30); __auto_type v = cn_init_1822;
(f[0]=(f[0]-v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_1873 = cn_double(v29); __auto_type v = cn_init_1873;
(f[1]=(f[1]-v));
}
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_1953 = cn_double(v28); __auto_type v = cn_init_1953;
(f[1]=(f[1]-v));
}
(f[0]=(f[0]/f[1]));
goto cn_break_b29;
}
cn_break_b15:;
(f[0]=cn_double(0x3ff0000000000000));
goto cn_break_b30;
}
cn_break_b16:;
{
__auto_type cn_init_2007 = 0x4U; __auto_type bv = cn_init_2007;
__auto_type cn_init_2024 = (((uint32_t)(((((v21>>0))&0xffffffffULL))))); __auto_type av = cn_init_2024;
__auto_type cn_init_2042 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2042;
}
if(cn_cond(fl,5)){
goto cn_break_b21;
}
(f[0]=cn_double(r3));
{
__auto_type cn_init_2078 = cn_double(v30); __auto_type v = cn_init_2078;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_2128 = cn_double(v29); __auto_type v = cn_init_2128;
(f[1]=(f[1]-v));
}
(f[1]=fabs(f[1]));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_2198 = 0x41U; __auto_type bv = cn_init_2198;
__auto_type cn_init_2211 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2211;
__auto_type cn_init_2229 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2229;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b19;
}
(f[0]=f[1]);
goto cn_break_b20;
}
cn_break_b19:;
(f[1]=f[1]);
}
cn_break_b20:;
(f[1]=cn_double(r5));
{
__auto_type cn_init_2303 = cn_double(v28); __auto_type v = cn_init_2303;
(f[1]=(f[1]-v));
}
(f[1]=fabs(f[1]));
(f[0]=(f[0]/f[1]));
goto cn_break_b29;
}
cn_break_b21:;
{
__auto_type cn_init_2355 = 0xfffffffcU; __auto_type bv = cn_init_2355;
__auto_type cn_init_2372 = (((uint32_t)(((((v21>>0))&0xffffffffULL))))); __auto_type av = cn_init_2372;
__auto_type cn_init_2390 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2390;
}
if(cn_cond(fl,5)){
goto cn_break_b28;
}
(f[0]=cn_double(r5));
{
__auto_type cn_init_2426 = cn_double(v28); __auto_type v = cn_init_2426;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_2494 = 0x41U; __auto_type bv = cn_init_2494;
__auto_type cn_init_2507 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2507;
__auto_type cn_init_2525 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2525;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,6)){
goto cn_break_b27;
}
(f[0]=cn_double(r3));
{
__auto_type cn_init_2574 = cn_double(v30); __auto_type v = cn_init_2574;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_2624 = cn_double(v29); __auto_type v = cn_init_2624;
(f[1]=(f[1]-v));
}
(f[1]=fabs(f[1]));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_2694 = 0x41U; __auto_type bv = cn_init_2694;
__auto_type cn_init_2707 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2707;
__auto_type cn_init_2725 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2725;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b25;
}
(f[0]=f[1]);
goto cn_break_b26;
}
cn_break_b25:;
(f[1]=f[1]);
}
cn_break_b26:;
(f[1]=cn_double(r5));
{
__auto_type cn_init_2799 = cn_double(v28); __auto_type v = cn_init_2799;
(f[1]=(f[1]-v));
}
(f[1]=fabs(f[1]));
(f[0]=(f[0]/f[1]));
goto cn_break_b29;
}
cn_break_b27:;
(f[0]=cn_double(0x3ff0000000000000));
goto cn_break_b30;
}
cn_break_b28:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_2884 = cn_double(v30); __auto_type v = cn_init_2884;
(f[0]=(f[0]-v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_2935 = cn_double(v29); __auto_type v = cn_init_2935;
(f[1]=(f[1]-v));
}
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
{
__auto_type cn_init_2986 = cn_double(v28); __auto_type v = cn_init_2986;
(f[2]=(f[2]-v));
}
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
}
cn_break_b29:;
{
__auto_type cn_init_3070 = cn_double(v27); __auto_type v = cn_init_3070;
(f[0]=(f[0]/v));
}
}
cn_break_b30:;
{
__auto_type cn_init_3090 = 0x1U; __auto_type bv = cn_init_3090;
__auto_type cn_init_3107 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_3107;
__auto_type cn_init_3125 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3125;
}
if(cn_cond(fl,4)){
goto cn_break_b32;
}
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_3193 = 0x41U; __auto_type bv = cn_init_3193;
__auto_type cn_init_3206 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3206;
__auto_type cn_init_3224 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3224;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,6)){
goto cn_break_b42;
}
(f[1]=cn_double(v25));
(r10=cn_bits(f[1]));
(f[1]=cn_double(v24));
(r11=cn_bits(f[1]));
(f[1]=cn_double(v23));
(r12=cn_bits(f[1]));
goto cn_break_b37;
}
cn_break_b42:;
{
__auto_type cn_init_3334 = cn_double(v26); __auto_type v = cn_init_3334;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_3402 = 0x41U; __auto_type bv = cn_init_3402;
__auto_type cn_init_3415 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3415;
__auto_type cn_init_3433 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3433;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,6)){
goto cn_break_b44;
}
(f[1]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_3482 = cn_double(v26); __auto_type v = cn_init_3482;
(f[1]=(f[1]-v));
}
(f[0]=(f[0]/f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_3531 = cn_double(v25); __auto_type v = cn_init_3531;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]-f[0]));
(f[3]=cn_double(r10));
(f[4]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3622 = cn_double(v30); __auto_type v = cn_init_3622;
(f[4]=(f[4]*v));
}
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(r10=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_3723 = cn_double(v24); __auto_type v = cn_init_3723;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]-f[0]));
(f[3]=cn_double(r11));
(f[4]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3814 = cn_double(v29); __auto_type v = cn_init_3814;
(f[4]=(f[4]*v));
}
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(r11=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_3915 = cn_double(v23); __auto_type v = cn_init_3915;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]-f[0]));
(f[3]=cn_double(r12));
(f[4]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4006 = cn_double(v28); __auto_type v = cn_init_4006;
(f[4]=(f[4]*v));
}
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(r12=cn_bits(f[1]));
goto cn_break_b35;
}
cn_break_b44:;
(f[1]=cn_double(r10));
(f[2]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4141 = cn_double(v30); __auto_type v = cn_init_4141;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(r10=cn_bits(f[1]));
(f[1]=cn_double(r11));
(f[2]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4242 = cn_double(v29); __auto_type v = cn_init_4242;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(r11=cn_bits(f[1]));
(f[1]=cn_double(r12));
(f[2]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4343 = cn_double(v28); __auto_type v = cn_init_4343;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(r12=cn_bits(f[1]));
goto cn_break_b39;
}
cn_break_b32:;
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_4452 = 0x41U; __auto_type bv = cn_init_4452;
__auto_type cn_init_4465 = cn_reg_get(rg,4,1); __auto_type av = cn_init_4465;
__auto_type cn_init_4483 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_4483;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b37;
}
{
__auto_type cn_init_4520 = cn_double(v26); __auto_type v = cn_init_4520;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_4588 = 0x41U; __auto_type bv = cn_init_4588;
__auto_type cn_init_4601 = cn_reg_get(rg,4,1); __auto_type av = cn_init_4601;
__auto_type cn_init_4619 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_4619;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,6)){
goto cn_break_b38;
}
(f[1]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_4668 = cn_double(v26); __auto_type v = cn_init_4668;
(f[1]=(f[1]-v));
}
(f[0]=(f[0]/f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_4717 = cn_double(r10); __auto_type v = cn_init_4717;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]-f[0]));
{
__auto_type cn_init_4768 = cn_double(v25); __auto_type v = cn_init_4768;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r10=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_4828 = cn_double(r11); __auto_type v = cn_init_4828;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]-f[0]));
{
__auto_type cn_init_4879 = cn_double(v24); __auto_type v = cn_init_4879;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r11=cn_bits(f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_4939 = cn_double(r12); __auto_type v = cn_init_4939;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]-f[0]));
{
__auto_type cn_init_4990 = cn_double(v23); __auto_type v = cn_init_4990;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r12=cn_bits(f[1]));
}
cn_break_b35:;
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]-f[0]));
{
__auto_type cn_init_5084 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5084;
(f[0]=(f[0]*v));
}
goto cn_break_b36;
}
cn_break_b38:;
(f[1]=cn_double(v25));
(r10=cn_bits(f[1]));
(f[1]=cn_double(v24));
(r11=cn_bits(f[1]));
(f[1]=cn_double(v23));
(r12=cn_bits(f[1]));
}
cn_break_b39:;
(f[0]=f[0]);
(f[0]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
}
cn_break_b36:;
(f[1]=cn_double(v30));
(f[1]=(f[1]*f[0]));
{
__auto_type cn_init_5248 = cn_double(r3); __auto_type v = cn_init_5248;
(f[1]=(v-f[1]));
}
(r3=cn_bits(f[1]));
(f[1]=cn_double(v29));
(f[1]=(f[1]*f[0]));
{
__auto_type cn_init_5310 = cn_double(r4); __auto_type v = cn_init_5310;
(f[1]=(v-f[1]));
}
(r4=cn_bits(f[1]));
(f[1]=cn_double(v28));
(f[1]=(f[1]*f[0]));
{
__auto_type cn_init_5372 = cn_double(r5); __auto_type v = cn_init_5372;
(f[1]=(v-f[1]));
}
(r5=cn_bits(f[1]));
}
cn_break_b37:;
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
cn_wr64(m,CN_REC+8*(10),r10);
cn_wr64(m,CN_REC+8*(11),r11);
cn_wr64(m,CN_REC+8*(12),r12);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_8713cb10fb46f160(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+160))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001030U); uint64_t r6 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10007ec0U); uint64_t s2008 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_240;
__auto_type cn_init_253 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,0); uint64_t v20 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,8); uint64_t v21 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,16); uint64_t v22 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,24); uint64_t v23 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,32); uint64_t v24 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,40); uint64_t v25 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,48); uint64_t v26 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,56); uint64_t v27 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,64); uint64_t v28 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,72); uint64_t v29 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,80); uint64_t v30 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,96); uint64_t v32 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,104); uint64_t v33 = cn_init_422;
__auto_type cn_init_435 = cn_cell(vm,112); uint64_t v34 = cn_init_435;
__auto_type cn_init_448 = cn_cell(vm,120); uint64_t v35 = cn_init_448;
{
{
{
{
{
{
__auto_type cn_init_469 = 0xffffffc4U; __auto_type bv = cn_init_469;
__auto_type cn_init_477 = rg[4]; __auto_type av = cn_init_477;
__auto_type cn_init_495 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_495;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_524 = r5; uint64_t s = cn_init_524;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_554 = (CN_U2){v28,v29}; CN_U2 s = cn_init_554;
__auto_type cn_init_564 = m->xmm[0]; __auto_type a = cn_init_564;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_634 = v28; uint64_t s = cn_init_634;
__auto_type cn_init_647 = m->xmm[1][0]; __auto_type a = cn_init_647;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_694 = (CN_U2){v24,v25}; CN_U2 s = cn_init_694;
__auto_type cn_init_704 = m->xmm[0]; __auto_type a = cn_init_704;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_774 = v26; uint64_t s = cn_init_774;
__auto_type cn_init_787 = m->xmm[1][0]; __auto_type a = cn_init_787;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_824 = 0x0U; __auto_type bv = cn_init_824;
__auto_type cn_init_841 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_841;
__auto_type cn_init_859 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_859;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_880 = r32; uint64_t s = cn_init_880;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_902 = v28; uint64_t s = cn_init_902;
__auto_type cn_init_915 = m->xmm[5][0]; __auto_type a = cn_init_915;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(s2008=m->xmm[0][0]);
(s2009=m->xmm[0][1]);
(s2010=m->xmm[1][0]);
(f[0]=cn_double(s2008));
(f[1]=cn_double(s2009));
(f[0]=atan2(f[0],f[1]));
(s2013=cn_bits(f[0]));
{
__auto_type cn_init_1095 = cn_double(v35); __auto_type v = cn_init_1095;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1130 = (((double)(((int32_t)(((uint32_t)(((((v21>>32))&0xffffffffULL))))))))); __auto_type v = cn_init_1130;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1170 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1170;
(f[0]=(f[0]+v));
}
{
__auto_type cn_tuple_1200_0 = sin(f[0]);
__auto_type cn_tuple_1200_1 = cos(f[0]);
__auto_type s = cn_tuple_1200_0;
__auto_type c = cn_tuple_1200_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2012=cn_bits(f[1]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1265 = cn_double(v34); __auto_type v = cn_init_1265;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_1289 = cn_double(v32); __auto_type v = cn_init_1289;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1324 = (((double)(((int32_t)(((uint32_t)(((((v22>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_1324;
(f[0]=(f[0]*v));
}
(f[0]=cn_round(m,f[0]));
{
__auto_type cn_init_1374 = (((double)(((int32_t)(((uint32_t)(((((v22>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_1374;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_1398 = cn_double(v33); __auto_type v = cn_init_1398;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_1429_0 = sin(f[0]);
__auto_type cn_tuple_1429_1 = cos(f[0]);
__auto_type s = cn_tuple_1429_0;
__auto_type c = cn_tuple_1429_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2013=cn_bits(f[1]));
(s2014=cn_bits(f[0]));
(f[0]=cn_double(s2008));
{
__auto_type cn_init_1494 = cn_double(s2013); __auto_type v = cn_init_1494;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2009));
{
__auto_type cn_init_1530 = cn_double(s2014); __auto_type v = cn_init_1530;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1583 = cn_double(v30); __auto_type v = cn_init_1583;
(f[0]=(f[0]-v));
}
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2008));
{
__auto_type cn_init_1630 = cn_double(s2011); __auto_type v = cn_init_1630;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2010));
{
__auto_type cn_init_1666 = cn_double(s2012); __auto_type v = cn_init_1666;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(f[1]=cn_double(s2008));
{
__auto_type cn_init_1742 = cn_double(s2012); __auto_type v = cn_init_1742;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2010));
{
__auto_type cn_init_1778 = cn_double(s2011); __auto_type v = cn_init_1778;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=fabs(f[1]));
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
__auto_type cn_init_1926 = cn_double(v23); __auto_type v = cn_init_1926;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_1945 = 0x0U; __auto_type bv = cn_init_1945;
__auto_type cn_init_1962 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_1962;
__auto_type cn_init_1980 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1980;
}
if(cn_cond(fl,5)){
goto cn_break_b7;
}
{
__auto_type cn_init_2004 = cn_double(v28); __auto_type v = cn_init_2004;
(f[0]=(f[0]/v));
}
}
cn_break_b7:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2035 = 0x3cU; __auto_type bv = cn_init_2035;
__auto_type cn_init_2043 = rg[4]; __auto_type av = cn_init_2043;
__auto_type cn_init_2061 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2061;
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
cn_wr64u(m,0x10007ec0U,s2008);
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_887131ff4a1b0a62(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+208))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_122;
__auto_type cn_init_135 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_135;
__auto_type cn_init_148 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_148;
__auto_type cn_init_161 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_161;
__auto_type cn_init_174 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_174;
__auto_type cn_init_187 = cn_cell(vm,0); uint64_t v26 = cn_init_187;
__auto_type cn_init_200 = cn_cell(vm,8); uint64_t v27 = cn_init_200;
__auto_type cn_init_213 = cn_cell(vm,16); uint64_t v28 = cn_init_213;
__auto_type cn_init_226 = cn_cell(vm,24); uint64_t v29 = cn_init_226;
__auto_type cn_init_239 = cn_cell(vm,32); uint64_t v30 = cn_init_239;
__auto_type cn_init_252 = cn_cell(vm,48); uint64_t v32 = cn_init_252;
__auto_type cn_init_265 = cn_cell(vm,56); uint64_t v33 = cn_init_265;
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
(f[0]=cn_double(r4));
{
__auto_type cn_init_533 = cn_double(v27); __auto_type v = cn_init_533;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_569 = cn_double(v28); __auto_type v = cn_init_569;
(f[1]=(f[1]+v));
}
__auto_type cn_tuple_601_0 = f[0];
__auto_type cn_tuple_601_1 = f[1];
__auto_type pa12y = cn_tuple_601_0;
__auto_type pa12x = cn_tuple_601_1;
__auto_type cn_tuple_615_0 = atan2(pa12y,pa12x);
__auto_type cn_tuple_615_1 = atan2(pa12y,pa12x);
__auto_type pa12lo = cn_tuple_615_0;
__auto_type pa12hi = cn_tuple_615_1;
(f[0]=pa12lo);
(f[1]=cn_double(v26));
{
__auto_type cn_init_645 = cn_double(v29); __auto_type v = cn_init_645;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_669 = cn_double(v33); __auto_type v = cn_init_669;
(f[1]=(f[1]*v));
}
__auto_type cn_init_690 = f[1]; __auto_type c12_16 = cn_init_690;
(f[0]=(f[0]+f[1]));
__auto_type cn_init_734 = ({__auto_type cn_init_719 = cn_double(v32); __auto_type v = cn_init_719; (f[0]=(f[0]/v)); v;}); __auto_type c12_17 = cn_init_734;
__auto_type cn_init_763 = ({__auto_type cn_init_748 = cn_double(v30); __auto_type v = cn_init_748; (f[0]=(f[0]*v)); v;}); __auto_type c12_18 = cn_init_763;
{

__auto_type cn_init_810 = cn_round(m,({__auto_type cn_arg=pa12lo; ({(cn_arg=(cn_arg+c12_16)); (cn_arg=(cn_arg/c12_17)); (cn_arg=(cn_arg*c12_18)); cn_arg;});})); __auto_type r1 = cn_init_810;
__auto_type cn_init_823 = cn_round(m,({__auto_type cn_arg=pa12hi; ({(cn_arg=(cn_arg+c12_16)); (cn_arg=(cn_arg/c12_17)); (cn_arg=(cn_arg*c12_18)); cn_arg;});})); __auto_type r2 = cn_init_823;
(f[0]=((((r1==r2)&&(cn_bits(r1)==cn_bits(r2))))?(({r1;})):(({cn_round(m,({__auto_type cn_arg=atan2(pa12y,pa12x); ({(cn_arg=(cn_arg+c12_16)); (cn_arg=(cn_arg/c12_17)); (cn_arg=(cn_arg*c12_18)); cn_arg;});}));}))));
}
(f[0]=-f[0]);
{
__auto_type cn_init_888 = cn_double(v30); __auto_type v = cn_init_888;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_912 = cn_double(v32); __auto_type v = cn_init_912;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(v29));
{
__auto_type cn_init_948 = cn_double(v33); __auto_type v = cn_init_948;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_tuple_993_0 = sin(f[0]);
__auto_type cn_tuple_993_1 = cos(f[0]);
__auto_type s = cn_tuple_993_0;
__auto_type c = cn_tuple_993_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[1]));
(f[3]=cn_double(r4));
(f[3]=(f[3]*f[0]));
(f[2]=(f[3]-f[2]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[0]));
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[1]));
(f[3]=(f[3]+f[4]));
(r4=cn_bits(f[3]));
(r3=cn_bits(f[2]));
(f[1]=f[1]);
(f[0]=f[0]);
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
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
