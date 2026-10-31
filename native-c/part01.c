/* Generated native C formula calculations. See tools/generate-native-c.py. */
#include "runtime.h"
int cn_f_0c932fcfcb9267a3(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
{
__auto_type cn_init_405 = cn_double(v30); __auto_type v = cn_init_405;
(f[2]=(f[2]+v));
}
(r3=cn_bits(f[2]));
{
__auto_type cn_init_440 = cn_double(v29); __auto_type v = cn_init_440;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_475 = cn_double(v28); __auto_type v = cn_init_475;
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
int cn_f_0cb3daf3eba3172e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
{
__auto_type cn_init_407 = cn_double(v29); __auto_type v = cn_init_407;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_473 = cn_double(r4); __auto_type v = cn_init_473;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_509 = cn_double(v27); __auto_type v = cn_init_509;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_548 = cn_double(v30); __auto_type v = cn_init_548;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_584 = cn_double(v28); __auto_type v = cn_init_584;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_608 = cn_double(v29); __auto_type v = cn_init_608;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[2]));
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_685 = cn_double(r3); __auto_type v = cn_init_685;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r4));
{
__auto_type cn_init_721 = cn_double(v27); __auto_type v = cn_init_721;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_760 = cn_double(v30); __auto_type v = cn_init_760;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v29));
{
__auto_type cn_init_796 = cn_double(v28); __auto_type v = cn_init_796;
(f[2]=(f[2]-v));
}
{
__auto_type cn_init_820 = cn_double(r5); __auto_type v = cn_init_820;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(v26));
(f[4]=cn_double(r3));
{
__auto_type cn_init_868 = cn_double(r4); __auto_type v = cn_init_868;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]*f[3]));
{
__auto_type cn_init_922 = cn_double(v30); __auto_type v = cn_init_922;
(f[2]=(f[2]*v));
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
int cn_f_0d2d38758758b123(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_175 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,0); uint64_t v20 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,8); uint64_t v21 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,16); uint64_t v22 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,24); uint64_t v23 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,32); uint64_t v24 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,40); uint64_t v25 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,48); uint64_t v26 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,56); uint64_t v27 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,64); uint64_t v28 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,72); uint64_t v29 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,80); uint64_t v30 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,96); uint64_t v32 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,104); uint64_t v33 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,112); uint64_t v34 = cn_init_422;
{
{
{
{
__auto_type cn_init_437 = 0xffffffceU; __auto_type bv = cn_init_437;
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
{
__auto_type cn_init_979 = m->xmm[0][0]; uint64_t v = cn_init_979;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1038 = m->xmm[0][1]; uint64_t v = cn_init_1038;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1097 = m->xmm[1][0]; uint64_t v = cn_init_1097;
(s2011=(((s2011&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2012=(((s2012&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
(f[0]=atan2(f[0],f[1]));
(f[1]=(((double)(((int32_t)(((uint32_t)(((((v21>>32))&0xffffffffULL))))))))));
(f[2]=(((double)(((int32_t)(((uint32_t)(((((v21>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_1282 = (((double)(((int32_t)(((uint32_t)(((((v22>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_1282;
(f[2]=(f[2]/v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_tuple_1342_0 = sin(f[0]);
__auto_type cn_tuple_1342_1 = cos(f[0]);
__auto_type s = cn_tuple_1342_0;
__auto_type c = cn_tuple_1342_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
{
__auto_type cn_init_1377 = cn_bits(f[1]); uint64_t v = cn_init_1377;
(s2013=(((s2013&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2014=(((s2014&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1435 = cn_bits(f[0]); uint64_t v = cn_init_1435;
(s2012=(((s2012&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2013=(((s2013&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1604 = cn_double(v30); __auto_type v = cn_init_1604;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_1632 = cn_bits(f[0]); uint64_t v = cn_init_1632;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1730 = cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1730;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1798 = cn_double(((((((s2013>>16))|((s2014<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1798;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1892 = cn_double(((((((s2013>>16))|((s2014<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1892;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1960 = cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1960;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_2003 = cn_bits(f[1]); uint64_t v = cn_init_2003;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_2061 = cn_bits(f[0]); uint64_t v = cn_init_2061;
(s2011=(((s2011&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2012=(((s2012&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
__auto_type cn_tuple_2179_0 = f[0];
__auto_type cn_tuple_2179_1 = f[1];
__auto_type pa50y = cn_tuple_2179_0;
__auto_type pa50x = cn_tuple_2179_1;
__auto_type cn_tuple_2193_0 = atan2(pa50y,pa50x);
__auto_type cn_tuple_2193_1 = atan2(pa50y,pa50x);
__auto_type pa50lo = cn_tuple_2193_0;
__auto_type pa50hi = cn_tuple_2193_1;
(f[0]=pa50lo);
__auto_type cn_init_2229 = ({__auto_type cn_init_2214 = cn_double(v34); __auto_type v = cn_init_2214; (f[0]=(v-f[0])); v;}); __auto_type c50_51 = cn_init_2229;
__auto_type cn_init_2258 = ({__auto_type cn_init_2243 = cn_double(v32); __auto_type v = cn_init_2243; (f[0]=(f[0]*v)); v;}); __auto_type c50_52 = cn_init_2258;
__auto_type cn_init_2298 = ({__auto_type cn_init_2283 = (((double)(((int32_t)(((uint32_t)(((((v22>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_2283; (f[0]=(f[0]*v)); v;}); __auto_type c50_53 = cn_init_2298;
{

__auto_type cn_init_2345 = cn_round(m,({__auto_type cn_arg=pa50lo; ({(cn_arg=(c50_51-cn_arg)); (cn_arg=(cn_arg*c50_52)); (cn_arg=(cn_arg*c50_53)); cn_arg;});})); __auto_type r1 = cn_init_2345;
__auto_type cn_init_2358 = cn_round(m,({__auto_type cn_arg=pa50hi; ({(cn_arg=(c50_51-cn_arg)); (cn_arg=(cn_arg*c50_52)); (cn_arg=(cn_arg*c50_53)); cn_arg;});})); __auto_type r2 = cn_init_2358;
(f[0]=((((r1==r2)&&(cn_bits(r1)==cn_bits(r2))))?(({r1;})):(({cn_round(m,({__auto_type cn_arg=atan2(pa50y,pa50x); ({(cn_arg=(c50_51-cn_arg)); (cn_arg=(cn_arg*c50_52)); (cn_arg=(cn_arg*c50_53)); cn_arg;});}));}))));
}
{
__auto_type cn_init_2423 = (((double)(((int32_t)(((uint32_t)(((((v22>>0))&0xffffffffULL))))))))); __auto_type v = cn_init_2423;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_2447 = cn_double(v33); __auto_type v = cn_init_2447;
(f[0]=(f[0]*v));
}
{
__auto_type cn_tuple_2478_0 = sin(f[0]);
__auto_type cn_tuple_2478_1 = cos(f[0]);
__auto_type s = cn_tuple_2478_0;
__auto_type c = cn_tuple_2478_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
{
__auto_type cn_init_2513 = cn_bits(f[1]); uint64_t v = cn_init_2513;
(s2012=(((s2012&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2013=(((s2013&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_2571 = cn_bits(f[0]); uint64_t v = cn_init_2571;
(s2013=(((s2013&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2014=(((s2014&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2669 = cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2669;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2737 = cn_double(((((((s2013>>16))|((s2014<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2737;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2787 = cn_double(v20); __auto_type v = cn_init_2787;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2870 = cn_double(((((((s2013>>16))|((s2014<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2870;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2938 = cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2938;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_3021 = cn_double(v23); __auto_type v = cn_init_3021;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_3040 = 0x0U; __auto_type bv = cn_init_3040;
__auto_type cn_init_3057 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_3057;
__auto_type cn_init_3075 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3075;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
{
__auto_type cn_init_3099 = cn_double(v28); __auto_type v = cn_init_3099;
(f[0]=(f[0]/v));
}
}
cn_break_b4:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_3130 = 0x32U; __auto_type bv = cn_init_3130;
__auto_type cn_init_3138 = rg[4]; __auto_type av = cn_init_3138;
__auto_type cn_init_3156 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3156;
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
cn_wr64u(m,0x10007ef0U,s2014);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_0d431bec7f8890e2(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_254 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_254;
__auto_type cn_init_267 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_267;
__auto_type cn_init_280 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_280;
__auto_type cn_init_293 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_293;
__auto_type cn_init_306 = cn_cell(vm,0); uint64_t v21 = cn_init_306;
__auto_type cn_init_319 = cn_cell(vm,8); uint64_t v22 = cn_init_319;
__auto_type cn_init_332 = cn_cell(vm,16); uint64_t v23 = cn_init_332;
__auto_type cn_init_345 = cn_cell(vm,24); uint64_t v24 = cn_init_345;
__auto_type cn_init_358 = cn_cell(vm,32); uint64_t v25 = cn_init_358;
__auto_type cn_init_371 = cn_cell(vm,40); uint64_t v26 = cn_init_371;
__auto_type cn_init_384 = cn_cell(vm,48); uint64_t v27 = cn_init_384;
__auto_type cn_init_397 = cn_cell(vm,56); uint64_t v28 = cn_init_397;
__auto_type cn_init_410 = cn_cell(vm,64); uint64_t v29 = cn_init_410;
__auto_type cn_init_423 = cn_cell(vm,72); uint64_t v30 = cn_init_423;
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
(rg[7]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_716 = 0x80U; __auto_type bv = cn_init_716;
__auto_type cn_init_724 = rg[7]; __auto_type av = cn_init_724;
__auto_type cn_init_742 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_742;
(rg[7]=r);
}
{
__auto_type cn_init_756 = 0x0U; __auto_type bv = cn_init_756;
__auto_type cn_init_773 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type av = cn_init_773;
__auto_type cn_init_791 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_791;
}
if(cn_cond(fl,15)){
goto cn_break_b2;
}
{
__auto_type cn_init_822 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type v = cn_init_822;
__auto_type cn_init_829 = fl.cf; __auto_type cf = cn_init_829;
__auto_type cn_init_847 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_847;
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
__auto_type cn_init_981 = cn_double(v26); __auto_type v = cn_init_981;
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
{
__auto_type cn_init_1768 = 0x0U; __auto_type bv = cn_init_1768;
__auto_type cn_init_1785 = (((uint32_t)(((((v21>>32))&0xffffffffULL))))); __auto_type av = cn_init_1785;
__auto_type cn_init_1803 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1803;
}
if(cn_cond(fl,5)){
goto cn_break_b16;
}
(f[3]=f[2]);
{
__auto_type cn_init_1837 = cn_double(v24); __auto_type v = cn_init_1837;
(f[3]=(f[3]+v));
}
(f[3]=(f[3]*f[2]));
(f[4]=f[1]);
{
__auto_type cn_init_1886 = cn_double(v23); __auto_type v = cn_init_1886;
(f[4]=(f[4]+v));
}
(f[4]=(f[4]*f[1]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1950 = cn_double(v22); __auto_type v = cn_init_1950;
(f[4]=(f[4]+v));
}
goto cn_break_b17;
}
cn_break_b16:;
(f[3]=f[2]);
{
__auto_type cn_init_1988 = cn_double(r10); __auto_type v = cn_init_1988;
(f[3]=(f[3]+v));
}
(f[3]=(f[3]*f[2]));
(f[4]=f[1]);
{
__auto_type cn_init_2037 = cn_double(r11); __auto_type v = cn_init_2037;
(f[4]=(f[4]+v));
}
(f[4]=(f[4]*f[1]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2101 = cn_double(v21); __auto_type v = cn_init_2101;
(f[4]=(f[4]+v));
}
}
cn_break_b17:;
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
__auto_type cn_init_2573 = cn_double(r32); __auto_type v = cn_init_2573;
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
__auto_type cn_init_2707 = 0x0U; __auto_type bv = cn_init_2707;
__auto_type cn_init_2724 = (((uint32_t)(((((v21>>32))&0xffffffffULL))))); __auto_type av = cn_init_2724;
__auto_type cn_init_2742 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2742;
}
if(cn_cond(fl,5)){
goto cn_break_b24;
}
{
__auto_type cn_init_2766 = cn_double(r12); __auto_type v = cn_init_2766;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_2801 = cn_double(r11); __auto_type v = cn_init_2801;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_2836 = cn_double(r10); __auto_type v = cn_init_2836;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
goto cn_break_b25;
}
cn_break_b24:;
{
__auto_type cn_init_2875 = cn_double(v22); __auto_type v = cn_init_2875;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_2910 = cn_double(v23); __auto_type v = cn_init_2910;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_2945 = cn_double(v24); __auto_type v = cn_init_2945;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
}
cn_break_b25:;
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
int cn_f_0e902bd9e09205a8(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_224 = cn_rd64(m,CN_REC+8*(32)); uint64_t r32 = cn_init_224;
__auto_type cn_init_241 = cn_rd64(m,CN_REC+8*(33)); uint64_t r33 = cn_init_241;
__auto_type cn_init_254 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_254;
__auto_type cn_init_267 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_267;
__auto_type cn_init_280 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_280;
__auto_type cn_init_293 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_293;
__auto_type cn_init_306 = cn_cell(vm,0); uint64_t v22 = cn_init_306;
__auto_type cn_init_319 = cn_cell(vm,8); uint64_t v23 = cn_init_319;
__auto_type cn_init_332 = cn_cell(vm,16); uint64_t v24 = cn_init_332;
__auto_type cn_init_345 = cn_cell(vm,24); uint64_t v25 = cn_init_345;
__auto_type cn_init_358 = cn_cell(vm,32); uint64_t v26 = cn_init_358;
__auto_type cn_init_371 = cn_cell(vm,40); uint64_t v27 = cn_init_371;
__auto_type cn_init_384 = cn_cell(vm,48); uint64_t v28 = cn_init_384;
__auto_type cn_init_397 = cn_cell(vm,56); uint64_t v29 = cn_init_397;
__auto_type cn_init_410 = cn_cell(vm,64); uint64_t v30 = cn_init_410;
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
(rg[7]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_703 = 0x80U; __auto_type bv = cn_init_703;
__auto_type cn_init_711 = rg[7]; __auto_type av = cn_init_711;
__auto_type cn_init_729 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_729;
(rg[7]=r);
}
{
__auto_type cn_init_743 = 0x0U; __auto_type bv = cn_init_743;
__auto_type cn_init_760 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type av = cn_init_760;
__auto_type cn_init_778 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_778;
}
if(cn_cond(fl,15)){
goto cn_break_b2;
}
{
__auto_type cn_init_809 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type v = cn_init_809;
__auto_type cn_init_816 = fl.cf; __auto_type cf = cn_init_816;
__auto_type cn_init_834 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_834;
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
__auto_type cn_init_968 = cn_double(v27); __auto_type v = cn_init_968;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r32=cn_bits(f[0]));
(f[0]=cn_double(v28));
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
{
__auto_type cn_init_1755 = 0x0U; __auto_type bv = cn_init_1755;
__auto_type cn_init_1772 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_1772;
__auto_type cn_init_1790 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1790;
}
if(cn_cond(fl,5)){
goto cn_break_b16;
}
(f[3]=cn_double(v25));
(f[3]=(f[3]+f[2]));
(f[3]=f[3]);
(f[3]=cn_double(v24));
(f[3]=(f[3]+f[1]));
(f[3]=f[3]);
(f[3]=cn_double(v23));
(f[3]=(f[3]+f[0]));
(f[3]=f[3]);
goto cn_break_b17;
}
cn_break_b16:;
(f[3]=cn_double(r10));
(f[3]=(f[3]+f[2]));
(f[3]=f[3]);
(f[3]=cn_double(r11));
(f[3]=(f[3]+f[1]));
(f[3]=f[3]);
(f[3]=cn_double(r12));
(f[3]=(f[3]+f[0]));
(f[3]=f[3]);
}
cn_break_b17:;
(f[3]=f[2]);
(f[3]=(f[3]*f[2]));
(f[4]=f[1]);
(f[4]=(f[4]*f[1]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[0]));
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(v29));
(f[4]=(f[4]*f[4]));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b19;
}
(f[3]=f[3]);
(f[3]=cn_double(r32));
{
__auto_type cn_init_2265 = cn_double(v26); __auto_type v = cn_init_2265;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(v29));
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]/f[4]));
goto cn_break_b22;
}
cn_break_b19:;
(f[4]=cn_double(v26));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b21;
}
(f[4]=f[4]);
{
__auto_type cn_init_2427 = cn_double(v26); __auto_type v = cn_init_2427;
(f[3]=(f[3]/v));
}
{
__auto_type cn_init_2451 = cn_double(r32); __auto_type v = cn_init_2451;
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
__auto_type cn_init_2585 = 0x0U; __auto_type bv = cn_init_2585;
__auto_type cn_init_2602 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_2602;
__auto_type cn_init_2620 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2620;
}
if(cn_cond(fl,5)){
goto cn_break_b24;
}
{
__auto_type cn_init_2644 = cn_double(r12); __auto_type v = cn_init_2644;
(f[2]=(f[2]+v));
}
{
__auto_type cn_init_2668 = cn_double(v23); __auto_type v = cn_init_2668;
(f[2]=(f[2]-v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_2703 = cn_double(r11); __auto_type v = cn_init_2703;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_2727 = cn_double(v24); __auto_type v = cn_init_2727;
(f[1]=(f[1]-v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_2762 = cn_double(r10); __auto_type v = cn_init_2762;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2786 = cn_double(v25); __auto_type v = cn_init_2786;
(f[0]=(f[0]-v));
}
(r3=cn_bits(f[0]));
goto cn_break_b25;
}
cn_break_b24:;
{
__auto_type cn_init_2825 = cn_double(r12); __auto_type v = cn_init_2825;
(f[2]=(f[2]-v));
}
{
__auto_type cn_init_2849 = cn_double(v23); __auto_type v = cn_init_2849;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_2884 = cn_double(r11); __auto_type v = cn_init_2884;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_2908 = cn_double(v24); __auto_type v = cn_init_2908;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_2943 = cn_double(r10); __auto_type v = cn_init_2943;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2967 = cn_double(v25); __auto_type v = cn_init_2967;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
}
cn_break_b25:;
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
int cn_f_0f34b1ecddc21cb4(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[1]=cn_double(r10));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2453 = 0x41U; __auto_type bv = cn_init_2453;
__auto_type cn_init_2466 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2466;
__auto_type cn_init_2484 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2484;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,14)){
goto cn_break_b3;
}
(f[1]=cn_double(r3));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2577 = 0x41U; __auto_type bv = cn_init_2577;
__auto_type cn_init_2590 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2590;
__auto_type cn_init_2608 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2608;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,14)){
goto cn_break_b3;
}
(f[1]=cn_double(s2008));
(f[1]=-f[1]);
(s2008=cn_bits(f[1]));
}
cn_break_b3:;
(f[1]=cn_double(r11));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2736 = 0x41U; __auto_type bv = cn_init_2736;
__auto_type cn_init_2749 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2749;
__auto_type cn_init_2767 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2767;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,14)){
goto cn_break_b6;
}
(f[1]=cn_double(r4));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_2860 = 0x41U; __auto_type bv = cn_init_2860;
__auto_type cn_init_2873 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2873;
__auto_type cn_init_2891 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2891;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,14)){
goto cn_break_b6;
}
(f[1]=cn_double(s2007));
(f[1]=-f[1]);
(s2007=cn_bits(f[1]));
}
cn_break_b6:;
(f[1]=cn_double(r12));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_3019 = 0x41U; __auto_type bv = cn_init_3019;
__auto_type cn_init_3032 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3032;
__auto_type cn_init_3050 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3050;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,14)){
goto cn_break_b9;
}
(f[1]=cn_double(r5));
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_3143 = 0x41U; __auto_type bv = cn_init_3143;
__auto_type cn_init_3156 = cn_reg_get(rg,4,1); __auto_type av = cn_init_3156;
__auto_type cn_init_3174 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_3174;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,14)){
goto cn_break_b9;
}
(f[1]=cn_double(s2006));
(f[1]=-f[1]);
(s2006=cn_bits(f[1]));
}
cn_break_b9:;
(f[1]=cn_double(s2011));
{
__auto_type cn_init_3258 = cn_double(v30); __auto_type v = cn_init_3258;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3282 = cn_double(v27); __auto_type v = cn_init_3282;
(f[1]=(f[1]+v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_3325 = cn_double(s2008); __auto_type v = cn_init_3325;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r10));
{
__auto_type cn_init_3361 = cn_double(v27); __auto_type v = cn_init_3361;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r3=cn_bits(f[1]));
(f[1]=cn_double(s2010));
{
__auto_type cn_init_3423 = cn_double(v30); __auto_type v = cn_init_3423;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3447 = cn_double(v27); __auto_type v = cn_init_3447;
(f[1]=(f[1]+v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_3490 = cn_double(s2007); __auto_type v = cn_init_3490;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r11));
{
__auto_type cn_init_3526 = cn_double(v26); __auto_type v = cn_init_3526;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r4=cn_bits(f[1]));
(f[1]=cn_double(s2009));
{
__auto_type cn_init_3588 = cn_double(v30); __auto_type v = cn_init_3588;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_3612 = cn_double(v27); __auto_type v = cn_init_3612;
(f[1]=(f[1]+v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_3655 = cn_double(s2006); __auto_type v = cn_init_3655;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r12));
{
__auto_type cn_init_3691 = cn_double(v25); __auto_type v = cn_init_3691;
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
int cn_f_0f43d2bea291cfc8(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+224))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_263 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_263;
__auto_type cn_init_276 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_276;
__auto_type cn_init_289 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_289;
__auto_type cn_init_302 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_302;
__auto_type cn_init_315 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_315;
__auto_type cn_init_328 = cn_cell(vm,0); uint64_t v28 = cn_init_328;
__auto_type cn_init_341 = cn_cell(vm,8); uint64_t v29 = cn_init_341;
__auto_type cn_init_354 = cn_cell(vm,16); uint64_t v30 = cn_init_354;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_420 = 0x30U; __auto_type bv = cn_init_420;
__auto_type cn_init_428 = rg[4]; __auto_type av = cn_init_428;
__auto_type cn_init_446 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_446;
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
(f[1]=cn_double(r4));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_692 = cn_double(v28); __auto_type v = cn_init_692;
(f[0]=(f[0]*v));
}
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r3));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_879 = cn_double(v30); __auto_type v = cn_init_879;
(f[0]=(f[0]-v));
}
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2012>>0))&0xffffffffULL)))))))));
{
__auto_type cn_tuple_975_0 = sin(f[0]);
__auto_type cn_tuple_975_1 = cos(f[0]);
__auto_type s = cn_tuple_975_0;
__auto_type c = cn_tuple_975_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(f[2]=(((double)(cn_float(((uint32_t)(((((s2011>>0))&0xffffffffULL)))))))));
(f[0]=(f[0]*f[2]));
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(v29));
(f[0]=(f[0]-f[2]));
(f[1]=(f[1]-f[2]));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_1153 = cn_double(v29); __auto_type v = cn_init_1153;
(f[0]=(f[0]-v));
}
(f[1]=(((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(r6=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_1256 = cn_double(v29); __auto_type v = cn_init_1256;
(f[0]=(f[0]-v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r10));
(f[1]=cn_double(r11));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_1333 = cn_double(v28); __auto_type v = cn_init_1333;
(f[0]=(f[0]*v));
}
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r10));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r11));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_1520 = cn_double(v30); __auto_type v = cn_init_1520;
(f[0]=(f[0]-v));
}
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(f[0]=(((double)(cn_float(((uint32_t)(((((s2012>>0))&0xffffffffULL)))))))));
{
__auto_type cn_tuple_1616_0 = sin(f[0]);
__auto_type cn_tuple_1616_1 = cos(f[0]);
__auto_type s = cn_tuple_1616_0;
__auto_type c = cn_tuple_1616_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(f[2]=(((double)(cn_float(((uint32_t)(((((s2011>>0))&0xffffffffULL)))))))));
(f[0]=(f[0]*f[2]));
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(v29));
(f[0]=(f[0]-f[2]));
(f[1]=(f[1]-f[2]));
(r11=cn_bits(f[1]));
(r10=cn_bits(f[0]));
(f[0]=cn_double(r12));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_1794 = cn_double(v29); __auto_type v = cn_init_1794;
(f[0]=(f[0]-v));
}
(f[1]=(((double)(cn_float(((uint32_t)(((((s2010>>0))&0xffffffffULL)))))))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(r0=cn_bits(f[0]));
(f[0]=cn_double(r12));
{
__auto_type cn_init_1897 = cn_double(v29); __auto_type v = cn_init_1897;
(f[0]=(f[0]-v));
}
(r12=cn_bits(f[0]));
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
cn_wr64(m,CN_REC+8*(0),r0);
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64(m,CN_REC+8*(10),r10);
cn_wr64(m,CN_REC+8*(11),r11);
cn_wr64(m,CN_REC+8*(12),r12);
cn_wr64u(m,0x10007eb0U,s2006);
cn_wr64u(m,0x10007eb8U,s2007);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_117351c6664c8709(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v17 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,8); uint64_t v18 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,16); uint64_t v19 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,24); uint64_t v20 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,32); uint64_t v21 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,40); uint64_t v22 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,48); uint64_t v23 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,56); uint64_t v24 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,64); uint64_t v25 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,72); uint64_t v26 = cn_init_325;
__auto_type cn_init_338 = cn_cell(vm,80); uint64_t v27 = cn_init_338;
__auto_type cn_init_351 = cn_cell(vm,88); uint64_t v28 = cn_init_351;
__auto_type cn_init_364 = cn_cell(vm,96); uint64_t v29 = cn_init_364;
__auto_type cn_init_377 = cn_cell(vm,104); uint64_t v30 = cn_init_377;
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
(f[3]=f[2]);
{
__auto_type cn_init_697 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_697;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_745 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_745;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_808 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_808;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_871 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_871;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_919 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_919;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_982 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_982;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1044 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1044;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1091 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1091;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1153 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1153;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
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
cn_swap(f,2,1);
(f[3]=f[1]);
{
__auto_type cn_init_1474 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1474;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_1522 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1522;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1585 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1585;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_1648 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1648;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1696 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1696;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1759 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1759;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_1821 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1821;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_1868 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1868;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1930 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1930;
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
cn_swap(f,3,2);
(f[4]=cn_double(v17));
(f[4]=(f[4]+f[3]));
(f[4]=fabs(f[4]));
(f[5]=cn_double(v17));
(f[5]=(f[5]-f[3]));
(f[5]=fabs(f[5]));
(f[5]=-f[5]);
(f[4]=(f[4]+f[5]));
(f[3]=(f[4]-f[3]));
cn_swap(f,3,2);
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[3]-f[4]));
(f[4]=f[3]);
(f[5]=f[4]);
{
__auto_type cn_init_2252 = cn_double(v28); __auto_type v = cn_init_2252;
(f[5]=(f[5]*v));
}
(f[1]=(f[1]-f[5]));
{
__auto_type cn_init_2291 = cn_double(v29); __auto_type v = cn_init_2291;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]-f[4]));
{
__auto_type cn_init_2330 = cn_double(v27); __auto_type v = cn_init_2330;
(f[3]=(f[3]*v));
}
(f[0]=(f[0]-f[3]));
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
int cn_f_1241d2b84fae112c(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_149 = cn_rd64u(m,0x10001078U); uint64_t r15 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_227;
__auto_type cn_init_240 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_240;
__auto_type cn_init_253 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_253;
__auto_type cn_init_266 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,0); uint64_t v15 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,8); uint64_t v16 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,16); uint64_t v17 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,24); uint64_t v18 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,32); uint64_t v19 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,40); uint64_t v20 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,48); uint64_t v21 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,56); uint64_t v22 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,64); uint64_t v23 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,72); uint64_t v24 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,80); uint64_t v25 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,88); uint64_t v26 = cn_init_422;
__auto_type cn_init_435 = cn_cell(vm,96); uint64_t v27 = cn_init_435;
__auto_type cn_init_448 = cn_cell(vm,104); uint64_t v28 = cn_init_448;
__auto_type cn_init_461 = cn_cell(vm,112); uint64_t v29 = cn_init_461;
__auto_type cn_init_474 = cn_cell(vm,120); uint64_t v30 = cn_init_474;
__auto_type cn_init_487 = cn_cell(vm,136); uint64_t v32 = cn_init_487;
__auto_type cn_init_500 = cn_cell(vm,144); uint64_t v33 = cn_init_500;
__auto_type cn_init_513 = cn_cell(vm,152); uint64_t v34 = cn_init_513;
{
{
{
{
{
{
{
{
__auto_type cn_init_540 = 0xffffffd0U; __auto_type bv = cn_init_540;
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
__auto_type cn_init_912 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_912;
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
{
__auto_type cn_init_1082 = m->xmm[0][0]; uint64_t v = cn_init_1082;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1141 = m->xmm[0][1]; uint64_t v = cn_init_1141;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1200 = m->xmm[1][0]; uint64_t v = cn_init_1200;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(0x0));
{
__auto_type cn_init_1270 = cn_bits(f[0]); uint64_t v = cn_init_1270;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1328 = cn_bits(f[0]); uint64_t v = cn_init_1328;
(s2013=(((s2013&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2014=(((s2014&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1377 = 0xffffffd4U; __auto_type bv = cn_init_1377;
__auto_type cn_init_1385 = rg[7]; __auto_type av = cn_init_1385;
__auto_type cn_init_1403 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1403;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1530 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1530;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1578 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1578;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1641 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1641;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1704 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1704;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1752 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1752;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1815 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1815;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1877 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1877;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1924 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1924;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1986 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1986;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_2029 = cn_bits(f[2]); uint64_t v = cn_init_2029;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_2087 = cn_bits(f[1]); uint64_t v = cn_init_2087;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_2145 = cn_bits(f[0]); uint64_t v = cn_init_2145;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_2194 = 0x2cU; __auto_type bv = cn_init_2194;
__auto_type cn_init_2202 = rg[7]; __auto_type av = cn_init_2202;
__auto_type cn_init_2220 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2220;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_2414 = cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2414;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2438 = cn_double(v30); __auto_type v = cn_init_2438;
(f[1]=(f[1]*v));
}
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2495 = cn_bits(f[0]); uint64_t v = cn_init_2495;
(s2013=(((s2013&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2014=(((s2014&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
{
__auto_type cn_init_2645 = cn_double(v32); __auto_type v = cn_init_2645;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2699 = cn_double(v23); __auto_type v = cn_init_2699;
(f[0]=(f[0]*v));
}
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b4;
}
{
__auto_type cn_init_2806 = cn_double(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2806;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2834 = cn_bits(f[0]); uint64_t v = cn_init_2834;
(s2013=(((s2013&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2014=(((s2014&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
goto cn_break_b5;
}
cn_break_b4:;
{
__auto_type cn_init_2908 = cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2908;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_2936 = cn_bits(f[0]); uint64_t v = cn_init_2936;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
}
cn_break_b5:;
(f[0]=cn_double(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))));
(f[0]=sqrt(f[0]));
(f[0]=sqrt(f[0]));
(f[1]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
(f[1]=sqrt(f[1]));
(f[1]=sqrt(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3129 = cn_double(v33); __auto_type v = cn_init_3129;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_3195 = cn_double(v34); __auto_type v = cn_init_3195;
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
__auto_type cn_init_3309 = 0x0U; __auto_type bv = cn_init_3309;
__auto_type cn_init_3326 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_3326;
__auto_type cn_init_3344 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3344;
}
if(cn_cond(fl,5)){
goto cn_break_b10;
}
{
__auto_type cn_init_3368 = cn_double(v28); __auto_type v = cn_init_3368;
(f[0]=(f[0]/v));
}
}
cn_break_b10:;
(r14=cn_bits(f[0]));
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
__auto_type cn_init_3577 = cn_double(v17); __auto_type v = cn_init_3577;
(f[0]=(f[0]*v));
}
(f[1]=(((double)(((int32_t)(((uint32_t)(((((r15>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_3624 = cn_double(v16); __auto_type v = cn_init_3624;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3663 = cn_double(v15); __auto_type v = cn_init_3663;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
(r34=cn_bits(f[0]));
{
__auto_type cn_init_3707 = 0x30U; __auto_type bv = cn_init_3707;
__auto_type cn_init_3715 = rg[4]; __auto_type av = cn_init_3715;
__auto_type cn_init_3733 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3733;
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
cn_wr64u(m,0x10007ef0U,s2014);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_12950cb060c90325(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_152 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_178;
__auto_type cn_init_191 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_191;
__auto_type cn_init_204 = cn_cell(vm,0); uint64_t v30 = cn_init_204;
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
__auto_type cn_init_476 = 0x0U; __auto_type bv = cn_init_476;
__auto_type cn_init_493 = (((uint32_t)(((((v30>>32))&0xffffffffULL))))); __auto_type av = cn_init_493;
__auto_type cn_init_511 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_511;
}
if(cn_cond(fl,4)){
goto cn_break_b9;
}
(f[0]=cn_double(r3));
{
__auto_type cn_init_547 = cn_double(r4); __auto_type v = cn_init_547;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b3;
}
(f[0]=cn_double(r3));
(f[0]=-f[0]);
(f[1]=cn_double(r4));
(f[1]=-f[1]);
(r3=cn_bits(f[1]));
(r4=cn_bits(f[0]));
}
cn_break_b3:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_734 = cn_double(r5); __auto_type v = cn_init_734;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b5;
}
(f[0]=cn_double(r3));
(f[0]=-f[0]);
(f[1]=cn_double(r5));
(f[1]=-f[1]);
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
}
cn_break_b5:;
(f[0]=cn_double(r5));
{
__auto_type cn_init_921 = cn_double(r4); __auto_type v = cn_init_921;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b7;
}
(f[0]=cn_double(r5));
(f[0]=-f[0]);
(f[1]=cn_double(r4));
(f[1]=-f[1]);
(r5=cn_bits(f[1]));
(r4=cn_bits(f[0]));
}
cn_break_b7:;
{
__auto_type cn_init_1091 = 0x0U; __auto_type bv = cn_init_1091;
__auto_type cn_init_1108 = (((uint32_t)(((((v30>>0))&0xffffffffULL))))); __auto_type av = cn_init_1108;
__auto_type cn_init_1126 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1126;
}
if(cn_cond(fl,4)){
goto cn_break_b15;
}
}
cn_break_b9:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_1163 = cn_double(r4); __auto_type v = cn_init_1163;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b11;
}
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
(r3=cn_bits(f[1]));
(r4=cn_bits(f[0]));
}
cn_break_b11:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_1328 = cn_double(r5); __auto_type v = cn_init_1328;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b13;
}
(f[0]=cn_double(r3));
(f[1]=cn_double(r5));
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
}
cn_break_b13:;
(f[0]=cn_double(r4));
{
__auto_type cn_init_1493 = cn_double(r5); __auto_type v = cn_init_1493;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b15;
}
(f[0]=cn_double(r4));
(f[1]=cn_double(r5));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
}
cn_break_b15:;
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
int cn_f_12bc488dcd6d5f0e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_160 = 0x6d616c55U; __auto_type v = cn_init_160;
(rg[0]=v);
}
{
__auto_type cn_init_174 = 0x72697053U; __auto_type v = cn_init_174;
(rg[0]=v);
}
{
__auto_type cn_init_188 = 0x6c61U; __auto_type v = cn_init_188;
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
int cn_f_1303ccb7dbfec158(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+256))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_195;
__auto_type cn_init_208 = cn_cell(vm,0); uint64_t v32 = cn_init_208;
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
__auto_type cn_tuple_561_0 = sin(f[1]);
__auto_type cn_tuple_561_1 = cos(f[1]);
__auto_type s = cn_tuple_561_0;
__auto_type c = cn_tuple_561_1;
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
__auto_type cn_tuple_662_0 = f[5];
__auto_type cn_tuple_662_1 = f[4];
__auto_type x = cn_tuple_662_0;
__auto_type y = cn_tuple_662_1;
__auto_type cn_init_691 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_691;
(f[5]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_723 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_723;
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
__auto_type cn_init_958 = 0x41U; __auto_type bv = cn_init_958;
__auto_type cn_init_971 = cn_reg_get(rg,4,1); __auto_type av = cn_init_971;
__auto_type cn_init_989 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_989;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(f[3]=(f[3]/f[0]));
}
cn_break_b2:;
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
int cn_f_136ff3ca654e89ac(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_203 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_203;
__auto_type cn_init_216 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_216;
__auto_type cn_init_229 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_229;
__auto_type cn_init_242 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_242;
__auto_type cn_init_255 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_255;
__auto_type cn_init_268 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_268;
__auto_type cn_init_281 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_281;
__auto_type cn_init_294 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_294;
__auto_type cn_init_307 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_307;
__auto_type cn_init_320 = cn_cell(vm,0); uint64_t v32 = cn_init_320;
__auto_type cn_init_333 = cn_cell(vm,8); uint64_t v33 = cn_init_333;
__auto_type cn_init_346 = cn_cell(vm,16); uint64_t v34 = cn_init_346;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_412 = 0x30U; __auto_type bv = cn_init_412;
__auto_type cn_init_420 = rg[4]; __auto_type av = cn_init_420;
__auto_type cn_init_438 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_438;
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
(s2013=cn_bits(f[0]));
(f[0]=(f[0]*f[0]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
(s2012=cn_bits(f[0]));
(f[0]=(f[0]*f[0]));
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
(s2011=cn_bits(f[0]));
(f[0]=(f[0]*f[0]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_801 = cn_double(r5); __auto_type v = cn_init_801;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_825 = cn_double(r3); __auto_type v = cn_init_825;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_849 = cn_double(r3); __auto_type v = cn_init_849;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_873 = cn_double(v32); __auto_type v = cn_init_873;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(s2010=cn_bits(f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(s2009=cn_bits(f[2]));
(f[1]=(f[1]-f[2]));
{
__auto_type cn_init_988 = cn_double(r3); __auto_type v = cn_init_988;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1012 = cn_double(v33); __auto_type v = cn_init_1012;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2010));
{
__auto_type cn_init_1063 = cn_double(r4); __auto_type v = cn_init_1063;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2009));
{
__auto_type cn_init_1099 = cn_double(r5); __auto_type v = cn_init_1099;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
{
__auto_type cn_init_1138 = cn_double(v34); __auto_type v = cn_init_1138;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_1177 = cn_double(s2013); __auto_type v = cn_init_1177;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1201 = cn_double(r10); __auto_type v = cn_init_1201;
(f[0]=(f[0]+v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_1248 = cn_double(r3); __auto_type v = cn_init_1248;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_1272 = cn_double(r4); __auto_type v = cn_init_1272;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1296 = cn_double(r4); __auto_type v = cn_init_1296;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1320 = cn_double(v32); __auto_type v = cn_init_1320;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(s2010=cn_bits(f[1]));
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[2]));
(s2009=cn_bits(f[2]));
(f[1]=(f[1]-f[2]));
{
__auto_type cn_init_1435 = cn_double(r4); __auto_type v = cn_init_1435;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1459 = cn_double(v33); __auto_type v = cn_init_1459;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2010));
{
__auto_type cn_init_1510 = cn_double(r5); __auto_type v = cn_init_1510;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2009));
{
__auto_type cn_init_1546 = cn_double(r3); __auto_type v = cn_init_1546;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
{
__auto_type cn_init_1585 = cn_double(v34); __auto_type v = cn_init_1585;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_1624 = cn_double(s2012); __auto_type v = cn_init_1624;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1648 = cn_double(r11); __auto_type v = cn_init_1648;
(f[0]=(f[0]+v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1695 = cn_double(r4); __auto_type v = cn_init_1695;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_1719 = cn_double(r5); __auto_type v = cn_init_1719;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1743 = cn_double(r5); __auto_type v = cn_init_1743;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1767 = cn_double(v32); __auto_type v = cn_init_1767;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(s2010=cn_bits(f[1]));
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[2]));
(s2009=cn_bits(f[2]));
(f[1]=(f[1]-f[2]));
{
__auto_type cn_init_1882 = cn_double(r5); __auto_type v = cn_init_1882;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1906 = cn_double(v33); __auto_type v = cn_init_1906;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2010));
{
__auto_type cn_init_1957 = cn_double(r3); __auto_type v = cn_init_1957;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2009));
{
__auto_type cn_init_1993 = cn_double(r4); __auto_type v = cn_init_1993;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
{
__auto_type cn_init_2032 = cn_double(v34); __auto_type v = cn_init_2032;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2071 = cn_double(s2011); __auto_type v = cn_init_2071;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2095 = cn_double(r12); __auto_type v = cn_init_2095;
(f[0]=(f[0]+v));
}
(s2011=cn_bits(f[0]));
(f[0]=cn_double(s2011));
(f[1]=cn_double(s2012));
(f[2]=cn_double(s2013));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
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
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_13798995920dbc66(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_420 = cn_double(v28); __auto_type v = cn_init_420;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_444 = cn_double(v30); __auto_type v = cn_init_444;
(f[0]=(f[0]+v));
}
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[1]=sqrt(f[1]));
cn_swap(f,1,0);
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_559 = 0x41U; __auto_type bv = cn_init_559;
__auto_type cn_init_572 = cn_reg_get(rg,4,1); __auto_type av = cn_init_572;
__auto_type cn_init_590 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_590;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,15)){
goto cn_break_b2;
}
(f[0]=-f[0]);
}
cn_break_b2:;
{
__auto_type cn_init_639 = cn_double(v27); __auto_type v = cn_init_639;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_663 = cn_double(v29); __auto_type v = cn_init_663;
(f[0]=(f[0]+v));
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
int cn_f_14487fecacf35018(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
(f[2]=cn_double(r5));
(f[3]=cn_double(r10));
(f[4]=cn_double(r11));
(f[5]=cn_double(r12));
(r5=cn_bits(f[5]));
(r4=cn_bits(f[4]));
(r3=cn_bits(f[3]));
(r12=cn_bits(f[2]));
(r11=cn_bits(f[1]));
(r10=cn_bits(f[0]));
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
cn_wr64(m,CN_REC+8*(10),r10);
cn_wr64(m,CN_REC+8*(11),r11);
cn_wr64(m,CN_REC+8*(12),r12);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_14ea390f09101007(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+256))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007eb0U); uint64_t s2006 = cn_init_152;
__auto_type cn_init_165 = cn_rd64u(m,0x10007eb8U); uint64_t s2007 = cn_init_165;
__auto_type cn_init_178 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_178;
__auto_type cn_init_191 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_191;
__auto_type cn_init_204 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_204;
__auto_type cn_init_217 = cn_cell(vm,0); uint64_t v32 = cn_init_217;
__auto_type cn_init_230 = cn_cell(vm,8); uint64_t v33 = cn_init_230;
__auto_type cn_init_243 = cn_cell(vm,16); uint64_t v34 = cn_init_243;
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
__auto_type cn_init_551 = cn_double(v32); __auto_type v = cn_init_551;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_587 = cn_double(v33); __auto_type v = cn_init_587;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_637 = cn_double(v34); __auto_type v = cn_init_637;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_684 = cn_double(v34); __auto_type v = cn_init_684;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_731 = cn_double(v33); __auto_type v = cn_init_731;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_767 = cn_double(v32); __auto_type v = cn_init_767;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_829 = cn_double(r4); __auto_type v = cn_init_829;
(f[0]=(f[0]-v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_876 = cn_double(r4); __auto_type v = cn_init_876;
(f[0]=(f[0]+v));
}
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
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_15ceb8dc7a068aa6(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_442 = 0xffffffbaU; __auto_type bv = cn_init_442;
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
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1043 = m->xmm[0][1]; uint64_t v = cn_init_1043;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1102 = m->xmm[1][0]; uint64_t v = cn_init_1102;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(0x0));
{
__auto_type cn_init_1172 = cn_bits(f[0]); uint64_t v = cn_init_1172;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1230 = cn_bits(f[0]); uint64_t v = cn_init_1230;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1279 = 0xffffffd4U; __auto_type bv = cn_init_1279;
__auto_type cn_init_1287 = rg[7]; __auto_type av = cn_init_1287;
__auto_type cn_init_1305 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1305;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1432 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1432;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1480 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1480;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1543 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1543;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1606 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1606;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1654 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1654;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1717 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1717;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1779 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1779;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1826 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1826;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1888 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1888;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1931 = cn_bits(f[2]); uint64_t v = cn_init_1931;
(s2006=(((s2006&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2007=(((s2007&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_1989 = cn_bits(f[1]); uint64_t v = cn_init_1989;
(s2007=(((s2007&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2008=(((s2008&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_2047 = cn_bits(f[0]); uint64_t v = cn_init_2047;
(s2008=(((s2008&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2009=(((s2009&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
{
__auto_type cn_init_2096 = 0x2cU; __auto_type bv = cn_init_2096;
__auto_type cn_init_2104 = rg[7]; __auto_type av = cn_init_2104;
__auto_type cn_init_2122 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2122;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2242 = cn_double(v23); __auto_type v = cn_init_2242;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2270 = cn_bits(f[0]); uint64_t v = cn_init_2270;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2352 = cn_double(v30); __auto_type v = cn_init_2352;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2432 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2432;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2472 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2472;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2512 = cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2512;
(f[0]=(f[0]*v));
}
(fsw=cn_compare(f[0],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
{
__auto_type cn_init_2619 = cn_double(((((((s2010>>48))|((s2011<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2619;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_2647 = cn_bits(f[0]); uint64_t v = cn_init_2647;
(s2010=(((s2010&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2011=(((s2011&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
}
goto cn_break_b5;
}
cn_break_b4:;
{
__auto_type cn_init_2721 = cn_double(((((((s2009>>48))|((s2010<<16))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2721;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2749 = cn_bits(f[0]); uint64_t v = cn_init_2749;
(s2009=(((s2009&~((0xffffULL<<48))))|((((v&0xffffULL))<<48))));
(s2010=(((s2010&~0xffffffffffffULL))|((((v>>16))&0xffffffffffffULL))));
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
(f[1]=cn_double(((((((s2006>>48))|((s2007<<16))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(((((((s2007>>48))|((s2008<<16))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_3057 = cn_double(v23); __auto_type v = cn_init_3057;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_3081 = cn_double(v23); __auto_type v = cn_init_3081;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_3105 = cn_double(v23); __auto_type v = cn_init_3105;
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
(f[1]=cn_double(((((((s2008>>48))|((s2009<<16))))&0xffffffffffffffffULL))));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_3266 = cn_double(v23); __auto_type v = cn_init_3266;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_3290 = cn_double(v23); __auto_type v = cn_init_3290;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_3314 = cn_double(v23); __auto_type v = cn_init_3314;
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
__auto_type cn_init_3428 = 0x0U; __auto_type bv = cn_init_3428;
__auto_type cn_init_3445 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_3445;
__auto_type cn_init_3463 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3463;
}
if(cn_cond(fl,5)){
goto cn_break_b13;
}
{
__auto_type cn_init_3487 = cn_double(v28); __auto_type v = cn_init_3487;
(f[0]=(f[0]/v));
}
}
cn_break_b13:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_3518 = 0x46U; __auto_type bv = cn_init_3518;
__auto_type cn_init_3526 = rg[4]; __auto_type av = cn_init_3526;
__auto_type cn_init_3544 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3544;
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
int cn_f_170526ee426bbc9d(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
{
{
{
(f[0]=cn_double(r5));
{
__auto_type cn_init_271 = cn_double(v28); __auto_type v = cn_init_271;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_307 = cn_double(v29); __auto_type v = cn_init_307;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_343 = cn_double(v30); __auto_type v = cn_init_343;
(f[2]=(f[2]+v));
}
(f[3]=f[2]);
{
__auto_type cn_init_391 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_391;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_439 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_439;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_502 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_502;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_565 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_565;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_613 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_613;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_676 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_676;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_738 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_738;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_785 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_785;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_847 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_847;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(rg[2]=((uint32_t)(((((v23>>0))&0xffffffffULL)))));
{
__auto_type cn_init_898 = 0x1U; __auto_type bv = cn_init_898;
__auto_type cn_init_906 = rg[2]; __auto_type av = cn_init_906;
__auto_type cn_init_924 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_924;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(f[2]=fabs(f[2]));
}
cn_break_b2:;
(r3=cn_bits(f[2]));
(rg[2]=((uint32_t)(((((v22>>32))&0xffffffffULL)))));
{
__auto_type cn_init_993 = 0x1U; __auto_type bv = cn_init_993;
__auto_type cn_init_1001 = rg[2]; __auto_type av = cn_init_1001;
__auto_type cn_init_1019 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1019;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
(f[1]=fabs(f[1]));
}
cn_break_b4:;
(r4=cn_bits(f[1]));
(rg[2]=((uint32_t)(((((v22>>0))&0xffffffffULL)))));
{
__auto_type cn_init_1088 = 0x1U; __auto_type bv = cn_init_1088;
__auto_type cn_init_1096 = rg[2]; __auto_type av = cn_init_1096;
__auto_type cn_init_1114 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1114;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
(f[0]=fabs(f[0]));
}
cn_break_b6:;
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(rg[2]=((uint32_t)(((((v23>>0))&0xffffffffULL)))));
{
__auto_type cn_init_1196 = 0x2U; __auto_type bv = cn_init_1196;
__auto_type cn_init_1204 = rg[2]; __auto_type av = cn_init_1204;
__auto_type cn_init_1222 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1222;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b9;
}
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_1285 = 0x41U; __auto_type bv = cn_init_1285;
__auto_type cn_init_1298 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1298;
__auto_type cn_init_1316 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1316;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b9;
}
cn_swap(f,2,1);
}
cn_break_b9:;
(rg[2]=((uint32_t)(((((v22>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1375 = 0x2U; __auto_type bv = cn_init_1375;
__auto_type cn_init_1383 = rg[2]; __auto_type av = cn_init_1383;
__auto_type cn_init_1401 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1401;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b12;
}
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_1464 = 0x41U; __auto_type bv = cn_init_1464;
__auto_type cn_init_1477 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1477;
__auto_type cn_init_1495 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1495;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b12;
}
cn_swap(f,2,0);
}
cn_break_b12:;
cn_swap(f,2,1);
(rg[2]=((uint32_t)(((((v22>>0))&0xffffffffULL)))));
{
__auto_type cn_init_1563 = 0x2U; __auto_type bv = cn_init_1563;
__auto_type cn_init_1571 = rg[2]; __auto_type av = cn_init_1571;
__auto_type cn_init_1589 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1589;
(rg[2]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b15;
}
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_1652 = 0x41U; __auto_type bv = cn_init_1652;
__auto_type cn_init_1665 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1665;
__auto_type cn_init_1683 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1683;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b15;
}
cn_swap(f,2,0);
}
cn_break_b15:;
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
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_170d88a7063dc19f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
{
__auto_type cn_init_419 = cn_double(v27); __auto_type v = cn_init_419;
(f[1]=(f[1]*v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
(f[1]=-f[1]);
{
__auto_type cn_init_473 = cn_double(v29); __auto_type v = cn_init_473;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_524 = cn_double(v26); __auto_type v = cn_init_524;
(f[1]=(f[1]*v));
}
(f[1]=sin(f[1]));
(fsw&=~0x0400);
(f[1]=-f[1]);
{
__auto_type cn_init_578 = cn_double(v28); __auto_type v = cn_init_578;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_617 = cn_double(v30); __auto_type v = cn_init_617;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
(f[2]=cn_double(r5));
{
__auto_type cn_init_665 = cn_double(v27); __auto_type v = cn_init_665;
(f[2]=(f[2]*v));
}
(f[2]=cos(f[2]));
(fsw&=~0x0400);
(f[2]=-f[2]);
{
__auto_type cn_init_719 = cn_double(v29); __auto_type v = cn_init_719;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r3));
{
__auto_type cn_init_770 = cn_double(v26); __auto_type v = cn_init_770;
(f[2]=(f[2]*v));
}
(f[2]=sin(f[2]));
(fsw&=~0x0400);
(f[2]=-f[2]);
{
__auto_type cn_init_824 = cn_double(v28); __auto_type v = cn_init_824;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_863 = cn_double(v30); __auto_type v = cn_init_863;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
(f[3]=cn_double(r3));
{
__auto_type cn_init_911 = cn_double(v27); __auto_type v = cn_init_911;
(f[3]=(f[3]*v));
}
(f[3]=cos(f[3]));
(fsw&=~0x0400);
(f[3]=-f[3]);
{
__auto_type cn_init_965 = cn_double(v29); __auto_type v = cn_init_965;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r4));
{
__auto_type cn_init_1016 = cn_double(v26); __auto_type v = cn_init_1016;
(f[3]=(f[3]*v));
}
(f[3]=sin(f[3]));
(fsw&=~0x0400);
(f[3]=-f[3]);
{
__auto_type cn_init_1070 = cn_double(v28); __auto_type v = cn_init_1070;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_1109 = cn_double(v30); __auto_type v = cn_init_1109;
(f[2]=(f[2]*v));
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
int cn_f_170d88a7063dc19f_fast(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
{
__auto_type cn_init_419 = cn_double(v27); __auto_type v = cn_init_419;
(f[1]=(f[1]*v));
}
(f[1]=cn_fast_cos(f[1]));
(fsw&=~0x0400);
(f[1]=-f[1]);
{
__auto_type cn_init_473 = cn_double(v29); __auto_type v = cn_init_473;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_524 = cn_double(v26); __auto_type v = cn_init_524;
(f[1]=(f[1]*v));
}
(f[1]=cn_fast_sin(f[1]));
(fsw&=~0x0400);
(f[1]=-f[1]);
{
__auto_type cn_init_578 = cn_double(v28); __auto_type v = cn_init_578;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_617 = cn_double(v30); __auto_type v = cn_init_617;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
(f[2]=cn_double(r5));
{
__auto_type cn_init_665 = cn_double(v27); __auto_type v = cn_init_665;
(f[2]=(f[2]*v));
}
(f[2]=cn_fast_cos(f[2]));
(fsw&=~0x0400);
(f[2]=-f[2]);
{
__auto_type cn_init_719 = cn_double(v29); __auto_type v = cn_init_719;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r3));
{
__auto_type cn_init_770 = cn_double(v26); __auto_type v = cn_init_770;
(f[2]=(f[2]*v));
}
(f[2]=cn_fast_sin(f[2]));
(fsw&=~0x0400);
(f[2]=-f[2]);
{
__auto_type cn_init_824 = cn_double(v28); __auto_type v = cn_init_824;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_863 = cn_double(v30); __auto_type v = cn_init_863;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
(f[3]=cn_double(r3));
{
__auto_type cn_init_911 = cn_double(v27); __auto_type v = cn_init_911;
(f[3]=(f[3]*v));
}
(f[3]=cn_fast_cos(f[3]));
(fsw&=~0x0400);
(f[3]=-f[3]);
{
__auto_type cn_init_965 = cn_double(v29); __auto_type v = cn_init_965;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r4));
{
__auto_type cn_init_1016 = cn_double(v26); __auto_type v = cn_init_1016;
(f[3]=(f[3]*v));
}
(f[3]=cn_fast_sin(f[3]));
(fsw&=~0x0400);
(f[3]=-f[3]);
{
__auto_type cn_init_1070 = cn_double(v28); __auto_type v = cn_init_1070;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_1109 = cn_double(v30); __auto_type v = cn_init_1109;
(f[2]=(f[2]*v));
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
int cn_f_179460da9f3c72b4(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+240))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_122;
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
(f[0]=cn_double(r11));
(f[1]=cn_double(r12));
(r11=cn_bits(f[1]));
(r12=cn_bits(f[0]));
}
cn_break_b2:;
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(r5=cn_bits(f[1]));
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
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64(m,CN_REC+8*(11),r11);
cn_wr64(m,CN_REC+8*(12),r12);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_17ea5a086699b098(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_241 = cn_rd64(m,CN_REC+8*(33)); uint64_t r33 = cn_init_241;
__auto_type cn_init_254 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_254;
__auto_type cn_init_267 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_267;
__auto_type cn_init_280 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_280;
__auto_type cn_init_293 = cn_cell(vm,0); uint64_t v30 = cn_init_293;
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
__auto_type cn_init_490 = 0x0U; __auto_type bv = cn_init_490;
__auto_type cn_init_507 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type av = cn_init_507;
__auto_type cn_init_525 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_525;
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
{
__auto_type cn_init_556 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type v = cn_init_556;
__auto_type cn_init_563 = fl.cf; __auto_type cf = cn_init_563;
__auto_type cn_init_581 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_581;
(fl.cf=cf);
(r33=(((r33&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
(f[0]=cn_double(v30));
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[4]=f[3]);
(f[4]=(f[4]+f[2]));
(f[4]=(f[4]+f[1]));
(f[4]=fabs(f[4]));
(f[4]=(f[4]+f[0]));
(r3=cn_bits(f[4]));
(f[4]=f[1]);
(f[4]=(f[4]-f[3]));
(f[4]=(f[4]-f[2]));
(f[4]=fabs(f[4]));
(f[4]=(f[4]+f[0]));
(r4=cn_bits(f[4]));
(f[4]=f[2]);
(f[4]=(f[4]-f[3]));
(f[4]=(f[4]-f[1]));
(f[4]=fabs(f[4]));
(f[4]=(f[4]+f[0]));
(r5=cn_bits(f[4]));
(f[2]=(f[3]-f[2]));
(f[1]=(f[2]-f[1]));
(f[1]=fabs(f[1]));
(f[1]=(f[1]+f[0]));
(r6=cn_bits(f[1]));
(f[1]=cn_double(r12));
(f[2]=cn_double(r11));
(f[3]=cn_double(r10));
(f[4]=f[3]);
(f[4]=(f[4]+f[2]));
(f[4]=(f[4]+f[1]));
(f[4]=fabs(f[4]));
(f[4]=(f[4]+f[0]));
(r10=cn_bits(f[4]));
(f[4]=f[1]);
(f[4]=(f[4]-f[3]));
(f[4]=(f[4]-f[2]));
(f[4]=fabs(f[4]));
(f[4]=(f[4]+f[0]));
(r11=cn_bits(f[4]));
(f[4]=f[2]);
(f[4]=(f[4]-f[3]));
(f[4]=(f[4]-f[1]));
(f[4]=fabs(f[4]));
(f[4]=(f[4]+f[0]));
(r12=cn_bits(f[4]));
(f[2]=(f[3]-f[2]));
(f[1]=(f[2]-f[1]));
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
(r0=cn_bits(f[0]));
}
cn_break_b2:;
(f[0]=cn_double(r6));
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[4]=f[1]);
(f[4]=(f[4]*f[0]));
(f[4]=(f[4]+f[4]));
(f[5]=f[3]);
(f[5]=(f[5]*f[2]));
(f[5]=(f[5]+f[5]));
(f[6]=f[3]);
(f[6]=(f[6]*f[6]));
(f[7]=f[2]);
(f[7]=(f[7]*f[7]));
(f[6]=(f[6]-f[7]));
(f[7]=f[6]);
(f[7]=(f[7]+f[4]));
{
__auto_type cn_init_1551 = cn_double(r10); __auto_type v = cn_init_1551;
(f[7]=(f[7]+v));
}
(r3=cn_bits(f[7]));
(f[4]=(f[4]-f[6]));
cn_swap(f,5,4);
{
__auto_type cn_init_1610 = cn_double(r11); __auto_type v = cn_init_1610;
(f[5]=(f[5]+v));
}
(r4=cn_bits(f[5]));
cn_swap(f,4,1);
(f[4]=(f[4]*f[4]));
cn_swap(f,4,0);
(f[4]=(f[4]*f[4]));
(f[0]=(f[0]-f[4]));
(fsw=cn_compare(f[3],f[2]));
(f[2]=f[0]);
(f[2]=(f[2]+f[1]));
{
__auto_type cn_init_1748 = cn_double(r12); __auto_type v = cn_init_1748;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
(f[0]=(f[1]-f[0]));
{
__auto_type cn_init_1798 = cn_double(r0); __auto_type v = cn_init_1798;
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
cn_wr64(m,CN_REC+8*(0),r0);
cn_wr64(m,CN_REC+8*(3),r3);
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64(m,CN_REC+8*(10),r10);
cn_wr64(m,CN_REC+8*(11),r11);
cn_wr64(m,CN_REC+8*(12),r12);
cn_wr64(m,CN_REC+8*(33),r33);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_1843a4e57d14edaa(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(s2012=cn_bits(f[2]));
(f[1]=(f[1]*f[1]));
(s2013=cn_bits(f[1]));
(f[0]=(f[0]*f[0]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_1007 = cn_double(r5); __auto_type v = cn_init_1007;
(f[0]=(f[0]+v));
}
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1045 = cn_double(v29); __auto_type v = cn_init_1045;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1083 = cn_double(v30); __auto_type v = cn_init_1083;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1107 = cn_double(v34); __auto_type v = cn_init_1107;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1154 = cn_double(r5); __auto_type v = cn_init_1154;
(f[0]=(f[0]+v));
}
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1192 = cn_double(v29); __auto_type v = cn_init_1192;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1230 = cn_double(v30); __auto_type v = cn_init_1230;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1254 = cn_double(v34); __auto_type v = cn_init_1254;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1301 = cn_double(s2012); __auto_type v = cn_init_1301;
(f[0]=(f[0]+v));
}
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1339 = cn_double(v29); __auto_type v = cn_init_1339;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1377 = cn_double(v30); __auto_type v = cn_init_1377;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1424 = cn_double(r3); __auto_type v = cn_init_1424;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1460 = cn_double(r3); __auto_type v = cn_init_1460;
(f[1]=(f[1]-v));
}
(r4=cn_bits(f[1]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1518 = cn_double(v32); __auto_type v = cn_init_1518;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1554 = cn_double(v33); __auto_type v = cn_init_1554;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1605 = cn_double(v33); __auto_type v = cn_init_1605;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[2]=cn_double(r5));
{
__auto_type cn_init_1652 = cn_double(v32); __auto_type v = cn_init_1652;
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
int cn_f_19167e07a00f877b(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=cn_double(r4));
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
(r4=cn_bits(f[0]));
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
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_1941b230051d078c(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
{
__auto_type cn_init_487 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_487;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_537 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_537;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_587 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_587;
(f[2]=(f[2]-v));
}
(f[3]=f[2]);
{
__auto_type cn_init_635 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_635;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_683 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_683;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_746 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_746;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_809 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_809;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_857 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_857;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_920 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_920;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_973 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_973;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_1020 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1020;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1067 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1067;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1129 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1129;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
cn_swap(f,2,1);
{
__auto_type cn_init_1191 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1191;
(f[2]=(f[2]*v));
}
cn_swap(f,2,1);
(f[3]=f[0]);
(f[3]=(f[3]*f[3]));
(f[4]=f[1]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[3]=sqrt(f[3]));
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[3]-f[4]));
(f[4]=f[3]);
(f[4]=fabs(f[4]));
(f[5]=(((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))));
(f[5]=fabs(f[5]));
{
__auto_type cn_init_1434 = cn_double(r1); __auto_type v = cn_init_1434;
(f[5]=(f[5]+v));
}
(fsw=cn_compare(f[5],f[4]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
(r14=cn_bits(f[3]));
(fsw=cn_compare(f[2],f[1]));
(f[0]=f[0]);
{
__auto_type cn_init_1559 = 0x20U; __auto_type bv = cn_init_1559;
__auto_type cn_init_1567 = rg[4]; __auto_type av = cn_init_1567;
__auto_type cn_init_1585 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1585;
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
(s2014=cn_bits(f[3]));
(s2011=cn_bits(f[2]));
(s2012=cn_bits(f[1]));
(s2013=cn_bits(f[0]));
(rg[0]=rg[4]);
(rg[2]=((uint32_t)(((((v30>>32))&0xffffffffULL)))));
(rg[1]=rg[4]);
{
__auto_type cn_init_1766 = cn_map_px(true,((int32_t)(rg[EDX])),(CN_D3){cn_double(s2011),cn_double(s2012),cn_double(s2013)}); __auto_type r = cn_init_1766;
(s2011=cn_bits(r[0]));
(s2012=cn_bits(r[1]));
(s2013=cn_bits(r[2]));
}
(rg[1]=((uint32_t)(((((v30>>0))&0xffffffffULL)))));
{
__auto_type cn_init_1823 = 0x3U; __auto_type bv = cn_init_1823;
__auto_type cn_init_1831 = rg[1]; __auto_type av = cn_init_1831;
__auto_type cn_init_1849 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1849;
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
__auto_type cn_init_2083 = cn_double(v31); __auto_type v = cn_init_2083;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2121 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2121;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2145 = cn_double(s2014); __auto_type v = cn_init_2145;
(f[0]=(v-f[0]));
}
(r14=cn_bits(f[0]));
(rg[1]=((uint32_t)(((((v22>>0))&0xffffffffULL)))));
{
__auto_type cn_init_2192 = 0x3U; __auto_type bv = cn_init_2192;
__auto_type cn_init_2200 = rg[1]; __auto_type av = cn_init_2200;
__auto_type cn_init_2218 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2218;
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
__auto_type cn_init_2466 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2466;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2504 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2504;
(f[0]=(f[0]*v));
}
(r34=cn_bits(f[0]));
{
__auto_type cn_init_2534 = 0x20U; __auto_type bv = cn_init_2534;
__auto_type cn_init_2542 = rg[4]; __auto_type av = cn_init_2542;
__auto_type cn_init_2560 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2560;
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
int cn_f_19a98948a101c630(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_424 = cn_cell(vm,40); uint64_t v37 = cn_init_424;
__auto_type cn_init_437 = cn_cell(vm,48); uint64_t v38 = cn_init_437;
__auto_type cn_init_450 = cn_cell(vm,56); uint64_t v39 = cn_init_450;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_516 = 0xffffffc0U; __auto_type bv = cn_init_516;
__auto_type cn_init_524 = rg[4]; __auto_type av = cn_init_524;
__auto_type cn_init_542 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_542;
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
__auto_type cn_init_748 = cn_double(r3); __auto_type v = cn_init_748;
(f[0]=(f[0]*v));
}
(s2010=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_795 = cn_double(s2010); __auto_type v = cn_init_795;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_842 = cn_double(r4); __auto_type v = cn_init_842;
(f[0]=(f[0]*v));
}
(s2009=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_889 = cn_double(s2009); __auto_type v = cn_init_889;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_936 = cn_double(r5); __auto_type v = cn_init_936;
(f[0]=(f[0]*v));
}
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2008));
{
__auto_type cn_init_983 = cn_double(s2008); __auto_type v = cn_init_983;
(f[0]=(f[0]*v));
}
(s2011=cn_bits(f[0]));
(f[0]=cn_double(v36));
{
__auto_type cn_init_1030 = cn_double(r4); __auto_type v = cn_init_1030;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1054 = cn_double(r5); __auto_type v = cn_init_1054;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(v33));
{
__auto_type cn_init_1090 = cn_double(s2012); __auto_type v = cn_init_1090;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v37));
{
__auto_type cn_init_1126 = cn_double(s2011); __auto_type v = cn_init_1126;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v38));
{
__auto_type cn_init_1177 = cn_double(s2009); __auto_type v = cn_init_1177;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1201 = cn_double(s2008); __auto_type v = cn_init_1201;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(v39));
{
__auto_type cn_init_1237 = cn_double(s2009); __auto_type v = cn_init_1237;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(v32));
{
__auto_type cn_init_1273 = cn_double(s2008); __auto_type v = cn_init_1273;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_1312 = cn_double(s2010); __auto_type v = cn_init_1312;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]-f[3]));
(f[3]=cn_double(v35));
{
__auto_type cn_init_1363 = cn_double(s2013); __auto_type v = cn_init_1363;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_1402 = cn_double(v34); __auto_type v = cn_init_1402;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[0]=(f[0]*f[1]));
(rg[7]=rg[6]);
{
__auto_type cn_init_1461 = 0x18U; __auto_type bv = cn_init_1461;
__auto_type cn_init_1469 = rg[7]; __auto_type av = cn_init_1469;
__auto_type cn_init_1487 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1487;
(rg[7]=r);
}
{
__auto_type cn_init_1506 = cn_double(r10); __auto_type v = cn_init_1506;
(f[0]=(f[0]+v));
}
(s2007=cn_bits(f[0]));
(f[0]=cn_double(v36));
{
__auto_type cn_init_1553 = cn_double(r5); __auto_type v = cn_init_1553;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1577 = cn_double(r3); __auto_type v = cn_init_1577;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(v33));
{
__auto_type cn_init_1613 = cn_double(s2011); __auto_type v = cn_init_1613;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v37));
{
__auto_type cn_init_1649 = cn_double(s2013); __auto_type v = cn_init_1649;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v38));
{
__auto_type cn_init_1700 = cn_double(s2008); __auto_type v = cn_init_1700;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1724 = cn_double(s2010); __auto_type v = cn_init_1724;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(v39));
{
__auto_type cn_init_1760 = cn_double(s2008); __auto_type v = cn_init_1760;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(v32));
{
__auto_type cn_init_1796 = cn_double(s2010); __auto_type v = cn_init_1796;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_1835 = cn_double(s2009); __auto_type v = cn_init_1835;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]-f[3]));
(f[3]=cn_double(v35));
{
__auto_type cn_init_1886 = cn_double(s2012); __auto_type v = cn_init_1886;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_1925 = cn_double(v34); __auto_type v = cn_init_1925;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[0]=(f[0]*f[1]));
(rg[7]=rg[6]);
{
__auto_type cn_init_1984 = 0x20U; __auto_type bv = cn_init_1984;
__auto_type cn_init_1992 = rg[7]; __auto_type av = cn_init_1992;
__auto_type cn_init_2010 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2010;
(rg[7]=r);
}
{
__auto_type cn_init_2029 = cn_double(r11); __auto_type v = cn_init_2029;
(f[0]=(f[0]+v));
}
(s2006=cn_bits(f[0]));
(f[0]=cn_double(v36));
{
__auto_type cn_init_2076 = cn_double(r3); __auto_type v = cn_init_2076;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2100 = cn_double(r4); __auto_type v = cn_init_2100;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(v33));
{
__auto_type cn_init_2136 = cn_double(s2013); __auto_type v = cn_init_2136;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v37));
{
__auto_type cn_init_2172 = cn_double(s2012); __auto_type v = cn_init_2172;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v38));
{
__auto_type cn_init_2223 = cn_double(s2010); __auto_type v = cn_init_2223;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_2247 = cn_double(s2009); __auto_type v = cn_init_2247;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(v39));
{
__auto_type cn_init_2283 = cn_double(s2010); __auto_type v = cn_init_2283;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(v32));
{
__auto_type cn_init_2319 = cn_double(s2009); __auto_type v = cn_init_2319;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_2358 = cn_double(s2008); __auto_type v = cn_init_2358;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]-f[3]));
(f[3]=cn_double(v35));
{
__auto_type cn_init_2409 = cn_double(s2011); __auto_type v = cn_init_2409;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_2448 = cn_double(v34); __auto_type v = cn_init_2448;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_2497 = 0x28U; __auto_type bv = cn_init_2497;
__auto_type cn_init_2505 = rg[6]; __auto_type av = cn_init_2505;
__auto_type cn_init_2523 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2523;
(rg[6]=r);
}
{
__auto_type cn_init_2542 = cn_double(r12); __auto_type v = cn_init_2542;
(f[0]=(f[0]+v));
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
int cn_f_19adbddced1d7f99(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+160))); unsigned char * vm = cn_init_71;
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
__auto_type cn_init_227 = cn_cell(vm,0); uint64_t v20 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,8); uint64_t v21 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,16); uint64_t v22 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,24); uint64_t v23 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,32); uint64_t v24 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,40); uint64_t v25 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,48); uint64_t v26 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,56); uint64_t v27 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,64); uint64_t v28 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,72); uint64_t v29 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,80); uint64_t v30 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,88); uint64_t v31 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,96); uint64_t v32 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,104); uint64_t v33 = cn_init_396;
{
{
{
{
{
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2015=(((s2015&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[1])))&0xffffffffULL))<<0))));
}
{
__auto_type cn_init_470 = 0xffffffe0U; __auto_type bv = cn_init_470;
__auto_type cn_init_478 = rg[4]; __auto_type av = cn_init_478;
__auto_type cn_init_496 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_496;
(rg[4]=r);
}
(f[0]=cn_double(r5));
{
__auto_type cn_init_541 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_541;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_591 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_591;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_641 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_641;
(f[2]=(f[2]-v));
}
(f[3]=f[2]);
{
__auto_type cn_init_689 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_689;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_737 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_737;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_800 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_800;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_863 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_863;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_911 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_911;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_974 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_974;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_1027 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1027;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_1074 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1074;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1121 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1121;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1183 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1183;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
cn_swap(f,2,1);
{
__auto_type cn_init_1245 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1245;
(f[2]=(f[2]*v));
}
cn_swap(f,2,1);
(f[3]=f[0]);
(f[3]=(f[3]*f[3]));
(f[4]=f[1]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[3]=sqrt(f[3]));
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[3]-f[4]));
(f[4]=f[3]);
(f[4]=fabs(f[4]));
(f[5]=(((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))));
(f[5]=fabs(f[5]));
{
__auto_type cn_init_1488 = cn_double(r1); __auto_type v = cn_init_1488;
(f[5]=(f[5]+v));
}
{
__auto_type cn_init_1512 = cn_double(v33); __auto_type v = cn_init_1512;
(f[5]=(f[5]+v));
}
(fsw=cn_compare(f[5],f[4]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
(f[3]=fabs(f[3]));
(r14=cn_bits(f[3]));
(f[2]=f[2]);
(f[1]=f[1]);
(f[0]=f[0]);
goto cn_break_b9;
}
cn_break_b2:;
(s2014=cn_bits(f[3]));
(s2011=cn_bits(f[2]));
(s2012=cn_bits(f[1]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2011));
(f[0]=fabs(f[0]));
(f[1]=cn_double(s2012));
(f[1]=fabs(f[1]));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
(f[0]=f[1]);
goto cn_break_b5;
}
cn_break_b4:;
(f[1]=f[1]);
}
cn_break_b5:;
(f[1]=cn_double(s2013));
(f[1]=fabs(f[1]));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b7;
}
(f[0]=f[1]);
goto cn_break_b8;
}
cn_break_b7:;
(f[1]=f[1]);
}
cn_break_b8:;
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_2004 = cn_double(v20); __auto_type v = cn_init_2004;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_2040 = cn_double(v20); __auto_type v = cn_init_2040;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_2064 = cn_double(s2014); __auto_type v = cn_init_2064;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(s2014=cn_bits(f[0]));
(rg[0]=rg[4]);
(rg[2]=((uint32_t)(((((v30>>32))&0xffffffffULL)))));
(rg[1]=rg[4]);
{
__auto_type cn_init_2179 = cn_map_px(true,((int32_t)(rg[EDX])),(CN_D3){cn_double(s2011),cn_double(s2012),cn_double(s2013)}); __auto_type r = cn_init_2179;
(s2011=cn_bits(r[0]));
(s2012=cn_bits(r[1]));
(s2013=cn_bits(r[2]));
}
(rg[1]=((uint32_t)(((((v30>>0))&0xffffffffULL)))));
{
__auto_type cn_init_2236 = 0x3U; __auto_type bv = cn_init_2236;
__auto_type cn_init_2244 = rg[1]; __auto_type av = cn_init_2244;
__auto_type cn_init_2262 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2262;
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
__auto_type cn_init_2496 = cn_double(v31); __auto_type v = cn_init_2496;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2534 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2534;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2558 = cn_double(s2014); __auto_type v = cn_init_2558;
(f[0]=(v-f[0]));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_2596 = cn_double(v32); __auto_type v = cn_init_2596;
(f[0]=(f[0]-v));
}
(r14=cn_bits(f[0]));
(rg[1]=((uint32_t)(((((v22>>0))&0xffffffffULL)))));
{
__auto_type cn_init_2643 = 0x3U; __auto_type bv = cn_init_2643;
__auto_type cn_init_2651 = rg[1]; __auto_type av = cn_init_2651;
__auto_type cn_init_2669 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2669;
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
__auto_type cn_init_2917 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2917;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2955 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2955;
(f[0]=(f[0]*v));
}
(r34=cn_bits(f[0]));
}
cn_break_b9:;
{
__auto_type cn_init_2986 = 0x20U; __auto_type bv = cn_init_2986;
__auto_type cn_init_2994 = rg[4]; __auto_type av = cn_init_2994;
__auto_type cn_init_3012 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3012;
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
int cn_f_1adb0954ce48afa5(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_471 = cn_cell(vm,56); uint64_t v37 = cn_init_471;
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_537 = 0xffffffc0U; __auto_type bv = cn_init_537;
__auto_type cn_init_545 = rg[4]; __auto_type av = cn_init_545;
__auto_type cn_init_563 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_563;
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
__auto_type cn_init_769 = cn_double(r3); __auto_type v = cn_init_769;
(f[0]=(f[0]*v));
}
(s2009=cn_bits(f[0]));
(f[0]=cn_double(s2009));
{
__auto_type cn_init_816 = cn_double(s2009); __auto_type v = cn_init_816;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_863 = cn_double(r4); __auto_type v = cn_init_863;
(f[0]=(f[0]*v));
}
(s2008=cn_bits(f[0]));
(f[0]=cn_double(s2008));
{
__auto_type cn_init_910 = cn_double(s2008); __auto_type v = cn_init_910;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_957 = cn_double(r5); __auto_type v = cn_init_957;
(f[0]=(f[0]*v));
}
(s2007=cn_bits(f[0]));
(f[0]=cn_double(s2007));
{
__auto_type cn_init_1004 = cn_double(s2007); __auto_type v = cn_init_1004;
(f[0]=(f[0]*v));
}
(s2011=cn_bits(f[0]));
(rg[7]=((uint32_t)(((((s2015>>32))&0xffffffffULL)))));
(f[0]=cn_double(r6));
(rg[7]=((uint32_t)(((((s2015>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1085 = cn_double(r6); __auto_type v = cn_init_1085;
(f[0]=(f[0]*v));
}
(s2006=cn_bits(f[0]));
(f[0]=cn_double(s2006));
{
__auto_type cn_init_1132 = cn_double(s2006); __auto_type v = cn_init_1132;
(f[0]=(f[0]*v));
}
(s2010=cn_bits(f[0]));
(f[0]=cn_double(v32));
{
__auto_type cn_init_1179 = cn_double(r3); __auto_type v = cn_init_1179;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1215 = cn_double(s2008); __auto_type v = cn_init_1215;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2011));
{
__auto_type cn_init_1251 = cn_double(s2007); __auto_type v = cn_init_1251;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(s2010));
{
__auto_type cn_init_1302 = cn_double(s2006); __auto_type v = cn_init_1302;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_1341 = cn_double(v35); __auto_type v = cn_init_1341;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2012));
{
__auto_type cn_init_1377 = cn_double(s2007); __auto_type v = cn_init_1377;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2011));
{
__auto_type cn_init_1413 = cn_double(s2006); __auto_type v = cn_init_1413;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2010));
{
__auto_type cn_init_1464 = cn_double(s2008); __auto_type v = cn_init_1464;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2008));
{
__auto_type cn_init_1515 = cn_double(s2011); __auto_type v = cn_init_1515;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2007));
{
__auto_type cn_init_1566 = cn_double(s2010); __auto_type v = cn_init_1566;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2006));
{
__auto_type cn_init_1617 = cn_double(s2012); __auto_type v = cn_init_1617;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_1656 = cn_double(v36); __auto_type v = cn_init_1656;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v34));
{
__auto_type cn_init_1707 = cn_double(s2009); __auto_type v = cn_init_1707;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2012));
{
__auto_type cn_init_1743 = cn_double(s2011); __auto_type v = cn_init_1743;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_1767 = cn_double(s2010); __auto_type v = cn_init_1767;
(f[3]=(f[3]+v));
}
(f[4]=cn_double(s2008));
{
__auto_type cn_init_1803 = cn_double(s2007); __auto_type v = cn_init_1803;
(f[4]=(f[4]*v));
}
(f[5]=cn_double(s2007));
{
__auto_type cn_init_1839 = cn_double(s2006); __auto_type v = cn_init_1839;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=cn_double(s2006));
{
__auto_type cn_init_1890 = cn_double(s2008); __auto_type v = cn_init_1890;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_1929 = cn_double(v37); __auto_type v = cn_init_1929;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]-f[4]));
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v33));
{
__auto_type cn_init_2010 = cn_double(s2013); __auto_type v = cn_init_2010;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2008));
{
__auto_type cn_init_2046 = cn_double(s2007); __auto_type v = cn_init_2046;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_2070 = cn_double(s2006); __auto_type v = cn_init_2070;
(f[3]=(f[3]+v));
}
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v37));
{
__auto_type cn_init_2136 = cn_double(s2013); __auto_type v = cn_init_2136;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_2160 = cn_double(s2009); __auto_type v = cn_init_2160;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
(rg[7]=rg[6]);
{
__auto_type cn_init_2219 = 0x18U; __auto_type bv = cn_init_2219;
__auto_type cn_init_2227 = rg[7]; __auto_type av = cn_init_2227;
__auto_type cn_init_2245 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2245;
(rg[7]=r);
}
{
__auto_type cn_init_2264 = cn_double(r10); __auto_type v = cn_init_2264;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(v32));
{
__auto_type cn_init_2311 = cn_double(r4); __auto_type v = cn_init_2311;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2011));
{
__auto_type cn_init_2347 = cn_double(s2007); __auto_type v = cn_init_2347;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2010));
{
__auto_type cn_init_2383 = cn_double(s2006); __auto_type v = cn_init_2383;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(s2013));
{
__auto_type cn_init_2434 = cn_double(s2009); __auto_type v = cn_init_2434;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_2473 = cn_double(v35); __auto_type v = cn_init_2473;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2011));
{
__auto_type cn_init_2509 = cn_double(s2006); __auto_type v = cn_init_2509;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2010));
{
__auto_type cn_init_2545 = cn_double(s2009); __auto_type v = cn_init_2545;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2013));
{
__auto_type cn_init_2596 = cn_double(s2007); __auto_type v = cn_init_2596;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2007));
{
__auto_type cn_init_2647 = cn_double(s2010); __auto_type v = cn_init_2647;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2006));
{
__auto_type cn_init_2698 = cn_double(s2013); __auto_type v = cn_init_2698;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2009));
{
__auto_type cn_init_2749 = cn_double(s2011); __auto_type v = cn_init_2749;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_2788 = cn_double(v36); __auto_type v = cn_init_2788;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v34));
{
__auto_type cn_init_2839 = cn_double(s2008); __auto_type v = cn_init_2839;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2011));
{
__auto_type cn_init_2875 = cn_double(s2010); __auto_type v = cn_init_2875;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_2899 = cn_double(s2013); __auto_type v = cn_init_2899;
(f[3]=(f[3]+v));
}
(f[4]=cn_double(s2007));
{
__auto_type cn_init_2935 = cn_double(s2006); __auto_type v = cn_init_2935;
(f[4]=(f[4]*v));
}
(f[5]=cn_double(s2006));
{
__auto_type cn_init_2971 = cn_double(s2009); __auto_type v = cn_init_2971;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=cn_double(s2009));
{
__auto_type cn_init_3022 = cn_double(s2007); __auto_type v = cn_init_3022;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_3061 = cn_double(v37); __auto_type v = cn_init_3061;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]-f[4]));
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v33));
{
__auto_type cn_init_3142 = cn_double(s2012); __auto_type v = cn_init_3142;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2007));
{
__auto_type cn_init_3178 = cn_double(s2006); __auto_type v = cn_init_3178;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_3202 = cn_double(s2009); __auto_type v = cn_init_3202;
(f[3]=(f[3]+v));
}
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v37));
{
__auto_type cn_init_3268 = cn_double(s2012); __auto_type v = cn_init_3268;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_3292 = cn_double(s2008); __auto_type v = cn_init_3292;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
(rg[0]=rg[6]);
(rg[7]=rg[0]);
{
__auto_type cn_init_3361 = 0x20U; __auto_type bv = cn_init_3361;
__auto_type cn_init_3369 = rg[7]; __auto_type av = cn_init_3369;
__auto_type cn_init_3387 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_3387;
(rg[7]=r);
}
{
__auto_type cn_init_3406 = cn_double(r11); __auto_type v = cn_init_3406;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(v32));
{
__auto_type cn_init_3453 = cn_double(r5); __auto_type v = cn_init_3453;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2010));
{
__auto_type cn_init_3489 = cn_double(s2006); __auto_type v = cn_init_3489;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2013));
{
__auto_type cn_init_3525 = cn_double(s2009); __auto_type v = cn_init_3525;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(s2012));
{
__auto_type cn_init_3576 = cn_double(s2008); __auto_type v = cn_init_3576;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_3615 = cn_double(v35); __auto_type v = cn_init_3615;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2010));
{
__auto_type cn_init_3651 = cn_double(s2009); __auto_type v = cn_init_3651;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2013));
{
__auto_type cn_init_3687 = cn_double(s2008); __auto_type v = cn_init_3687;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2012));
{
__auto_type cn_init_3738 = cn_double(s2006); __auto_type v = cn_init_3738;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2006));
{
__auto_type cn_init_3789 = cn_double(s2013); __auto_type v = cn_init_3789;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2009));
{
__auto_type cn_init_3840 = cn_double(s2012); __auto_type v = cn_init_3840;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2008));
{
__auto_type cn_init_3891 = cn_double(s2010); __auto_type v = cn_init_3891;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_3930 = cn_double(v36); __auto_type v = cn_init_3930;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v34));
{
__auto_type cn_init_3981 = cn_double(s2007); __auto_type v = cn_init_3981;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2010));
{
__auto_type cn_init_4017 = cn_double(s2013); __auto_type v = cn_init_4017;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_4041 = cn_double(s2012); __auto_type v = cn_init_4041;
(f[3]=(f[3]+v));
}
(f[4]=cn_double(s2006));
{
__auto_type cn_init_4077 = cn_double(s2009); __auto_type v = cn_init_4077;
(f[4]=(f[4]*v));
}
(f[5]=cn_double(s2009));
{
__auto_type cn_init_4113 = cn_double(s2008); __auto_type v = cn_init_4113;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=cn_double(s2008));
{
__auto_type cn_init_4164 = cn_double(s2006); __auto_type v = cn_init_4164;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_4203 = cn_double(v37); __auto_type v = cn_init_4203;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]-f[4]));
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v33));
{
__auto_type cn_init_4284 = cn_double(s2011); __auto_type v = cn_init_4284;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2006));
{
__auto_type cn_init_4320 = cn_double(s2009); __auto_type v = cn_init_4320;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_4344 = cn_double(s2008); __auto_type v = cn_init_4344;
(f[3]=(f[3]+v));
}
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v37));
{
__auto_type cn_init_4410 = cn_double(s2011); __auto_type v = cn_init_4410;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_4434 = cn_double(s2007); __auto_type v = cn_init_4434;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
(rg[2]=rg[0]);
{
__auto_type cn_init_4493 = 0x28U; __auto_type bv = cn_init_4493;
__auto_type cn_init_4501 = rg[2]; __auto_type av = cn_init_4501;
__auto_type cn_init_4519 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_4519;
(rg[2]=r);
}
{
__auto_type cn_init_4538 = cn_double(r12); __auto_type v = cn_init_4538;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(v32));
(rg[2]=((uint32_t)(((((s2015>>32))&0xffffffffULL)))));
{
__auto_type cn_init_4602 = cn_double(r6); __auto_type v = cn_init_4602;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2013));
{
__auto_type cn_init_4638 = cn_double(s2009); __auto_type v = cn_init_4638;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2012));
{
__auto_type cn_init_4674 = cn_double(s2008); __auto_type v = cn_init_4674;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(s2011));
{
__auto_type cn_init_4725 = cn_double(s2007); __auto_type v = cn_init_4725;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_4764 = cn_double(v35); __auto_type v = cn_init_4764;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2013));
{
__auto_type cn_init_4800 = cn_double(s2008); __auto_type v = cn_init_4800;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2012));
{
__auto_type cn_init_4836 = cn_double(s2007); __auto_type v = cn_init_4836;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2011));
{
__auto_type cn_init_4887 = cn_double(s2009); __auto_type v = cn_init_4887;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2009));
{
__auto_type cn_init_4938 = cn_double(s2012); __auto_type v = cn_init_4938;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2008));
{
__auto_type cn_init_4989 = cn_double(s2011); __auto_type v = cn_init_4989;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(s2007));
{
__auto_type cn_init_5040 = cn_double(s2013); __auto_type v = cn_init_5040;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_5079 = cn_double(v36); __auto_type v = cn_init_5079;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v34));
{
__auto_type cn_init_5130 = cn_double(s2006); __auto_type v = cn_init_5130;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2013));
{
__auto_type cn_init_5166 = cn_double(s2012); __auto_type v = cn_init_5166;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_5190 = cn_double(s2011); __auto_type v = cn_init_5190;
(f[3]=(f[3]+v));
}
(f[4]=cn_double(s2009));
{
__auto_type cn_init_5226 = cn_double(s2008); __auto_type v = cn_init_5226;
(f[4]=(f[4]*v));
}
(f[5]=cn_double(s2008));
{
__auto_type cn_init_5262 = cn_double(s2007); __auto_type v = cn_init_5262;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=cn_double(s2007));
{
__auto_type cn_init_5313 = cn_double(s2009); __auto_type v = cn_init_5313;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_5352 = cn_double(v37); __auto_type v = cn_init_5352;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]-f[4]));
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v33));
{
__auto_type cn_init_5433 = cn_double(s2010); __auto_type v = cn_init_5433;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2009));
{
__auto_type cn_init_5469 = cn_double(s2008); __auto_type v = cn_init_5469;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_5493 = cn_double(s2007); __auto_type v = cn_init_5493;
(f[3]=(f[3]+v));
}
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(v37));
{
__auto_type cn_init_5559 = cn_double(s2010); __auto_type v = cn_init_5559;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_5583 = cn_double(s2006); __auto_type v = cn_init_5583;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_5632 = 0x38U; __auto_type bv = cn_init_5632;
__auto_type cn_init_5640 = rg[0]; __auto_type av = cn_init_5640;
__auto_type cn_init_5658 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_5658;
(rg[0]=r);
}
{
__auto_type cn_init_5677 = cn_double(r0); __auto_type v = cn_init_5677;
(f[0]=(f[0]+v));
}
(rg[0]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_5713 = 0x10U; __auto_type bv = cn_init_5713;
__auto_type cn_init_5721 = rg[0]; __auto_type av = cn_init_5721;
__auto_type cn_init_5739 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_5739;
(rg[0]=r);
}
{
__auto_type cn_init_5758 = cn_double(v30); __auto_type v = cn_init_5758;
(f[0]=(f[0]+v));
}
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
int cn_f_1b455c469f6af2bc(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_195;
__auto_type cn_init_208 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,0); uint64_t v20 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,8); uint64_t v21 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,16); uint64_t v22 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,24); uint64_t v23 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,32); uint64_t v24 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,40); uint64_t v25 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,48); uint64_t v26 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,56); uint64_t v27 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,64); uint64_t v28 = cn_init_325;
__auto_type cn_init_338 = cn_cell(vm,72); uint64_t v29 = cn_init_338;
__auto_type cn_init_351 = cn_cell(vm,80); uint64_t v30 = cn_init_351;
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
(f[3]=f[2]);
(f[3]=(f[3]*f[3]));
(f[4]=f[1]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(v23));
{
__auto_type cn_init_797 = cn_double(v21); __auto_type v = cn_init_797;
(f[4]=(f[4]*v));
}
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
(f[3]=f[3]);
(f[3]=cn_double(0x3ff0000000000000));
goto cn_break_b6;
}
cn_break_b2:;
(f[4]=cn_double(v22));
{
__auto_type cn_init_929 = cn_double(v21); __auto_type v = cn_init_929;
(f[4]=(f[4]*v));
}
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,6)){
goto cn_break_b5;
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008058U))))&0xffffffffULL))<<32))));
(f[3]=f[3]);
(f[3]=cn_double(v22));
{
__auto_type cn_init_1089 = cn_double(v21); __auto_type v = cn_init_1089;
(f[3]=(f[3]*v));
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b5:;
(f[4]=cn_double(v23));
{
__auto_type cn_init_1141 = cn_double(v21); __auto_type v = cn_init_1141;
(f[4]=(f[4]*v));
}
(f[3]=(f[4]/f[3]));
}
cn_break_b6:;
cn_swap(f,3,2);
(f[3]=(f[3]*f[2]));
cn_swap(f,3,1);
(f[3]=(f[3]*f[2]));
cn_swap(f,3,0);
(f[3]=(f[3]*f[2]));
(f[2]=f[3]);
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b10;
}
cn_swap(f,2,1);
}
cn_break_b10:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b12;
}
cn_swap(f,2,0);
}
cn_break_b12:;
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b14;
}
cn_swap(f,2,0);
}
cn_break_b14:;
{
__auto_type cn_init_1512 = cn_double(v25); __auto_type v = cn_init_1512;
(f[2]=(f[2]+v));
}
cn_swap(f,2,1);
{
__auto_type cn_init_1545 = cn_double(v26); __auto_type v = cn_init_1545;
(f[2]=(f[2]+v));
}
cn_swap(f,2,0);
{
__auto_type cn_init_1578 = cn_double(v24); __auto_type v = cn_init_1578;
(f[2]=(f[2]+v));
}
cn_swap(f,2,0);
cn_swap(f,2,1);
(f[3]=f[2]);
(f[3]=(f[3]*f[3]));
(f[4]=f[1]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
(f[4]=(f[4]*f[4]));
(f[3]=(f[3]+f[4]));
(fsw=cn_compare(f[3],cn_double(v23)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,7)){
goto cn_break_b27;
}
(fsw=cn_compare(f[3],cn_double(v22)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,7)){
goto cn_break_b17;
}
(f[3]=f[3]);
(f[3]=cn_double(v22));
}
cn_break_b17:;
(f[4]=cn_double(v23));
(f[3]=(f[4]/f[3]));
goto cn_break_b18;
}
cn_break_b27:;
(f[3]=f[3]);
(f[3]=cn_double(0x3ff0000000000000));
}
cn_break_b18:;
cn_swap(f,3,2);
(f[3]=(f[3]*f[2]));
{
__auto_type cn_init_1970 = cn_double(v25); __auto_type v = cn_init_1970;
(f[3]=(f[3]-v));
}
cn_swap(f,3,1);
(f[3]=(f[3]*f[2]));
{
__auto_type cn_init_2018 = cn_double(v26); __auto_type v = cn_init_2018;
(f[3]=(f[3]-v));
}
cn_swap(f,3,0);
(f[3]=(f[3]*f[2]));
{
__auto_type cn_init_2066 = cn_double(v24); __auto_type v = cn_init_2066;
(f[3]=(f[3]-v));
}
{
__auto_type cn_init_2085 = 0x0U; __auto_type bv = cn_init_2085;
__auto_type cn_init_2102 = (((uint32_t)(((((v20>>32))&0xffffffffULL))))); __auto_type av = cn_init_2102;
__auto_type cn_init_2120 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2120;
}
if(cn_cond(fl,4)){
goto cn_break_b29;
}
cn_swap(f,3,1);
cn_swap(f,3,2);
cn_swap(f,3,0);
cn_swap(f,3,2);
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b21;
}
cn_swap(f,3,2);
}
cn_break_b21:;
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b23;
}
cn_swap(f,3,1);
}
cn_break_b23:;
cn_swap(f,3,2);
(fsw=cn_compare(f[3],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b25;
}
cn_swap(f,3,1);
}
cn_break_b25:;
cn_swap(f,3,2);
cn_swap(f,3,1);
cn_swap(f,3,0);
goto cn_break_b26;
}
cn_break_b29:;
cn_swap(f,3,0);
cn_swap(f,3,1);
cn_swap(f,3,2);
}
cn_break_b26:;
(f[3]=f[3]);
(f[3]=cn_double(v30));
(f[4]=f[3]);
{
__auto_type cn_init_2520 = cn_double(r6); __auto_type v = cn_init_2520;
(f[4]=(f[4]*v));
}
(r6=cn_bits(f[4]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
(f[4]=f[3]);
(f[5]=cn_double(0x3ff0000000000000));
(f[4]=(f[4]-f[5]));
(f[5]=f[4]);
(f[6]=f[5]);
{
__auto_type cn_init_2642 = cn_double(v29); __auto_type v = cn_init_2642;
(f[6]=(f[6]*v));
}
(f[1]=(f[1]-f[6]));
{
__auto_type cn_init_2681 = cn_double(v28); __auto_type v = cn_init_2681;
(f[5]=(f[5]*v));
}
(f[2]=(f[2]-f[5]));
(f[4]=(f[4]/f[3]));
{
__auto_type cn_init_2735 = cn_double(v27); __auto_type v = cn_init_2735;
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
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_1b4a584dbcc33356(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+216))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_88;
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
(f[0]=cn_double(r4));
(f[1]=cn_double(v28));
(f[0]=(f[0]*f[1]));
(f[1]=cn_double(v30));
(f[0]=(f[0]+f[1]));
(r4=cn_bits(f[0]));
{
__auto_type cn_init_596 = (((uint32_t)(((((r4>>56))&0xffULL))))); __auto_type v = cn_init_596;
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
(r4=cn_bits(f[0]));
{
__auto_type cn_init_776 = cn_reg_get(rg,4,1); __auto_type bv = cn_init_776;
__auto_type cn_init_793 = (((uint32_t)(((((r4>>56))&0xffULL))))); __auto_type av = cn_init_793;
__auto_type cn_init_811 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_811;
(r4=(((r4&~((0xffULL<<56))))|(((((((uint64_t)((r))))&0xffULL))<<56))));
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
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_1c26f158990d75db(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_175 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,0); uint64_t v16 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,8); uint64_t v17 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,16); uint64_t v18 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,24); uint64_t v19 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,32); uint64_t v20 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,40); uint64_t v21 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,48); uint64_t v22 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,56); uint64_t v23 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,64); uint64_t v24 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,72); uint64_t v25 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,80); uint64_t v26 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,88); uint64_t v27 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,96); uint64_t v28 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,104); uint64_t v29 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,112); uint64_t v30 = cn_init_422;
__auto_type cn_init_435 = cn_cell(vm,128); uint64_t v32 = cn_init_435;
__auto_type cn_init_448 = cn_cell(vm,136); uint64_t v33 = cn_init_448;
__auto_type cn_init_461 = cn_cell(vm,144); uint64_t v34 = cn_init_461;
__auto_type cn_init_474 = cn_cell(vm,152); uint64_t v35 = cn_init_474;
__auto_type cn_init_487 = cn_cell(vm,160); uint64_t v36 = cn_init_487;
{
{
{
{
__auto_type cn_init_502 = 0xffffffceU; __auto_type bv = cn_init_502;
__auto_type cn_init_510 = rg[4]; __auto_type av = cn_init_510;
__auto_type cn_init_528 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_528;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_557 = r5; uint64_t s = cn_init_557;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_587 = (CN_U2){v28,v29}; CN_U2 s = cn_init_587;
__auto_type cn_init_597 = m->xmm[0]; __auto_type a = cn_init_597;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_667 = v28; uint64_t s = cn_init_667;
__auto_type cn_init_680 = m->xmm[1][0]; __auto_type a = cn_init_680;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_727 = (CN_U2){v24,v25}; CN_U2 s = cn_init_727;
__auto_type cn_init_737 = m->xmm[0]; __auto_type a = cn_init_737;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_807 = v26; uint64_t s = cn_init_807;
__auto_type cn_init_820 = m->xmm[1][0]; __auto_type a = cn_init_820;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_857 = 0x0U; __auto_type bv = cn_init_857;
__auto_type cn_init_874 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_874;
__auto_type cn_init_892 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_892;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_913 = r32; uint64_t s = cn_init_913;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_935 = v28; uint64_t s = cn_init_935;
__auto_type cn_init_948 = m->xmm[5][0]; __auto_type a = cn_init_948;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_1044 = m->xmm[0][0]; uint64_t v = cn_init_1044;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1103 = m->xmm[0][1]; uint64_t v = cn_init_1103;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1162 = m->xmm[1][0]; uint64_t v = cn_init_1162;
(s2011=(((s2011&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2012=(((s2012&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1211 = 0xffffffd4U; __auto_type bv = cn_init_1211;
__auto_type cn_init_1219 = rg[7]; __auto_type av = cn_init_1219;
__auto_type cn_init_1237 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1237;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
(f[3]=f[2]);
{
__auto_type cn_init_1364 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1364;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1412 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1412;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1475 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1475;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1538 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1538;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1586 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1586;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1649 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1649;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1711 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1711;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1758 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1758;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1820 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1820;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1863 = cn_bits(f[2]); uint64_t v = cn_init_1863;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1921 = cn_bits(f[1]); uint64_t v = cn_init_1921;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_1979 = cn_bits(f[0]); uint64_t v = cn_init_1979;
(s2011=(((s2011&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2012=(((s2012&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_2028 = 0x2cU; __auto_type bv = cn_init_2028;
__auto_type cn_init_2036 = rg[7]; __auto_type av = cn_init_2036;
__auto_type cn_init_2054 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2054;
(rg[7]=r);
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2101 = cn_double(v23); __auto_type v = cn_init_2101;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_2143 = cn_bits(f[0]); uint64_t v = cn_init_2143;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2225 = cn_double(v23); __auto_type v = cn_init_2225;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_2249 = cn_double(v32); __auto_type v = cn_init_2249;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2273 = cn_double(v32); __auto_type v = cn_init_2273;
(f[0]=(f[0]-v));
}
(f[0]=cn_round(m,f[0]));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2354 = cn_double(v23); __auto_type v = cn_init_2354;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_2405 = cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2405;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_2447 = cn_bits(f[0]); uint64_t v = cn_init_2447;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(v23));
{
__auto_type cn_init_2513 = cn_double(v33); __auto_type v = cn_init_2513;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2541 = cn_bits(f[0]); uint64_t v = cn_init_2541;
(s2012=(((s2012&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2013=(((s2013&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2639 = cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2639;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_2681 = cn_bits(f[0]); uint64_t v = cn_init_2681;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2779 = cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2779;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_2803 = cn_double(v32); __auto_type v = cn_init_2803;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2827 = cn_double(v32); __auto_type v = cn_init_2827;
(f[0]=(f[0]-v));
}
(f[0]=cn_round(m,f[0]));
(f[0]=(f[0]+f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2924 = cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2924;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_2975 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2975;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_3017 = cn_bits(f[0]); uint64_t v = cn_init_3017;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3099 = cn_double(v34); __auto_type v = cn_init_3099;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3151 = cn_double(v35); __auto_type v = cn_init_3151;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3190 = cn_double(v36); __auto_type v = cn_init_3190;
(f[0]=(f[0]+v));
}
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3268 = cn_bits(f[0]); uint64_t v = cn_init_3268;
(s2012=(((s2012&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2013=(((s2013&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[1]=f[0]);
{
__auto_type cn_init_3332 = cn_double(v34); __auto_type v = cn_init_3332;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
{
__auto_type cn_init_3383 = cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3383;
(f[1]=(f[1]+v));
}
(f[1]=fabs(f[1]));
{
__auto_type cn_init_3425 = cn_bits(f[1]); uint64_t v = cn_init_3425;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_3479 = cn_double(v35); __auto_type v = cn_init_3479;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_3530 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3530;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_3572 = cn_bits(f[0]); uint64_t v = cn_init_3572;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3654 = cn_double(v34); __auto_type v = cn_init_3654;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3706 = cn_double(v35); __auto_type v = cn_init_3706;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3745 = cn_double(v36); __auto_type v = cn_init_3745;
(f[0]=(f[0]+v));
}
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3823 = cn_bits(f[0]); uint64_t v = cn_init_3823;
(s2012=(((s2012&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2013=(((s2013&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[1]=f[0]);
{
__auto_type cn_init_3887 = cn_double(v34); __auto_type v = cn_init_3887;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
{
__auto_type cn_init_3938 = cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3938;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_3966 = cn_bits(f[1]); uint64_t v = cn_init_3966;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_4020 = cn_double(v35); __auto_type v = cn_init_4020;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
{
__auto_type cn_init_4071 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4071;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_4113 = cn_bits(f[0]); uint64_t v = cn_init_4113;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4209 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4209;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4275 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4275;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_4314 = cn_double(v16); __auto_type v = cn_init_4314;
(f[0]=(f[0]+v));
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2011>>16))|((s2012<<48))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_4425 = cn_double(v30); __auto_type v = cn_init_4425;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_4444 = 0x0U; __auto_type bv = cn_init_4444;
__auto_type cn_init_4461 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_4461;
__auto_type cn_init_4479 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_4479;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
{
__auto_type cn_init_4503 = cn_double(v28); __auto_type v = cn_init_4503;
(f[0]=(f[0]/v));
}
}
cn_break_b4:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_4534 = 0x32U; __auto_type bv = cn_init_4534;
__auto_type cn_init_4542 = rg[4]; __auto_type av = cn_init_4542;
__auto_type cn_init_4560 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_4560;
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
int cn_f_1c600993a98ac491(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r5));
(f[1]=cn_double(v30));
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(f[1]=cn_double(v30));
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
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
cn_wr64(m,CN_REC+8*(5),r5);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_1c69d5b83092035f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
{
__auto_type cn_init_2523 = 0x28U; __auto_type bv = cn_init_2523;
__auto_type cn_init_2531 = rg[7]; __auto_type av = cn_init_2531;
__auto_type cn_init_2549 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2549;
(rg[7]=r);
}
(f[1]=cn_double(v14));
(f[0]=(f[0]-f[1]));
(f[1]=cn_double(v30));
(f[0]=(f[0]*f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]-f[2]));
{
__auto_type cn_init_2649 = cn_double(v26); __auto_type v = cn_init_2649;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
(r6=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_2711 = cn_double(v15); __auto_type v = cn_init_2711;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_2747 = cn_double(v17); __auto_type v = cn_init_2747;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_2783 = cn_double(v16); __auto_type v = cn_init_2783;
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
__auto_type cn_init_2944 = cn_double(v29); __auto_type v = cn_init_2944;
(f[6]=(f[6]*v));
}
(f[1]=(f[1]-f[6]));
{
__auto_type cn_init_2983 = cn_double(v28); __auto_type v = cn_init_2983;
(f[5]=(f[5]*v));
}
(f[2]=(f[2]-f[5]));
(f[4]=(f[4]/f[3]));
{
__auto_type cn_init_3037 = cn_double(v27); __auto_type v = cn_init_3037;
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
