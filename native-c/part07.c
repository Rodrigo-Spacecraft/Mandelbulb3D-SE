/* Generated native C formula calculations. See tools/generate-native-c.py. */
#include "runtime.h"
int cn_f_7307f395e81dc750(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+192))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(7)); uint64_t r7 = cn_init_156;
__auto_type cn_init_173 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_173;
__auto_type cn_init_186 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_186;
__auto_type cn_init_199 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_199;
__auto_type cn_init_212 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_212;
__auto_type cn_init_225 = cn_cell(vm,0); uint64_t v24 = cn_init_225;
__auto_type cn_init_238 = cn_cell(vm,8); uint64_t v25 = cn_init_238;
__auto_type cn_init_251 = cn_cell(vm,16); uint64_t v26 = cn_init_251;
__auto_type cn_init_264 = cn_cell(vm,24); uint64_t v27 = cn_init_264;
__auto_type cn_init_277 = cn_cell(vm,32); uint64_t v28 = cn_init_277;
__auto_type cn_init_290 = cn_cell(vm,40); uint64_t v29 = cn_init_290;
__auto_type cn_init_303 = cn_cell(vm,48); uint64_t v30 = cn_init_303;
__auto_type cn_init_316 = cn_cell(vm,56); uint64_t v31 = cn_init_316;
__auto_type cn_init_329 = cn_cell(vm,64); uint64_t v32 = cn_init_329;
__auto_type cn_init_342 = cn_cell(vm,72); uint64_t v33 = cn_init_342;
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
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(m->xmm[2]=(CN_U2){r3,r4});
{
__auto_type cn_init_510 = r5; uint64_t s = cn_init_510;
(m->xmm[4]=(CN_U2){s,0});
}
(m->xmm[0]=m->xmm[2]);
{
__auto_type cn_init_554 = (CN_U2){v24,v25}; CN_U2 s = cn_init_554;
__auto_type cn_init_564 = m->xmm[0]; __auto_type a = cn_init_564;
(m->xmm[0]=(CN_U2){cn_bits(({__auto_type cn_tuple_602_0 = cn_double(a[0]);
__auto_type cn_tuple_602_1 = cn_double(s[0]);
__auto_type p = cn_tuple_602_0;
__auto_type q = cn_tuple_602_1; (((p>q))?(({p;})):(({q;})));})),cn_bits(({__auto_type cn_tuple_649_0 = cn_double(a[1]);
__auto_type cn_tuple_649_1 = cn_double(s[1]);
__auto_type p = cn_tuple_649_0;
__auto_type q = cn_tuple_649_1; (((p>q))?(({p;})):(({q;})));}))});
}
{
__auto_type cn_init_676 = v24; uint64_t s = cn_init_676;
__auto_type cn_init_689 = m->xmm[4][0]; __auto_type a = cn_init_689;
(m->xmm[4][0]=cn_bits(({__auto_type cn_tuple_723_0 = cn_double(a);
__auto_type cn_tuple_723_1 = cn_double(s);
__auto_type p = cn_tuple_723_0;
__auto_type q = cn_tuple_723_1; (((p>q))?(({p;})):(({q;})));})));
}
{
__auto_type cn_init_757 = (CN_U2){v26,v27}; CN_U2 s = cn_init_757;
__auto_type cn_init_767 = m->xmm[0]; __auto_type a = cn_init_767;
(m->xmm[0]=(CN_U2){cn_bits(({__auto_type cn_tuple_805_0 = cn_double(a[0]);
__auto_type cn_tuple_805_1 = cn_double(s[0]);
__auto_type p = cn_tuple_805_0;
__auto_type q = cn_tuple_805_1; (((p<q))?(({p;})):(({q;})));})),cn_bits(({__auto_type cn_tuple_852_0 = cn_double(a[1]);
__auto_type cn_tuple_852_1 = cn_double(s[1]);
__auto_type p = cn_tuple_852_0;
__auto_type q = cn_tuple_852_1; (((p<q))?(({p;})):(({q;})));}))});
}
{
__auto_type cn_init_879 = v26; uint64_t s = cn_init_879;
__auto_type cn_init_892 = m->xmm[4][0]; __auto_type a = cn_init_892;
(m->xmm[4][0]=cn_bits(({__auto_type cn_tuple_926_0 = cn_double(a);
__auto_type cn_tuple_926_1 = cn_double(s);
__auto_type p = cn_tuple_926_0;
__auto_type q = cn_tuple_926_1; (((p<q))?(({p;})):(({q;})));})));
}
{
__auto_type cn_init_961 = m->xmm[0]; CN_U2 s = cn_init_961;
__auto_type cn_init_971 = m->xmm[0]; __auto_type a = cn_init_971;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_1049 = m->xmm[4][0]; uint64_t s = cn_init_1049;
__auto_type cn_init_1062 = m->xmm[4][0]; __auto_type a = cn_init_1062;
(m->xmm[4][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_1110 = m->xmm[2]; CN_U2 s = cn_init_1110;
__auto_type cn_init_1120 = m->xmm[0]; __auto_type a = cn_init_1120;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])-cn_double(s[0])))),cn_bits(((cn_double(a[1])-cn_double(s[1]))))});
}
{
__auto_type cn_init_1190 = r5; uint64_t s = cn_init_1190;
__auto_type cn_init_1203 = m->xmm[4][0]; __auto_type a = cn_init_1203;
(m->xmm[4][0]=cn_bits(((cn_double(a)-cn_double(s)))));
}
(m->xmm[1]=m->xmm[0]);
(m->xmm[5][0]=m->xmm[4][0]);
{
__auto_type cn_init_1285 = m->xmm[1]; CN_U2 s = cn_init_1285;
__auto_type cn_init_1295 = m->xmm[1]; __auto_type a = cn_init_1295;
(m->xmm[1]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_1373 = m->xmm[5][0]; uint64_t s = cn_init_1373;
__auto_type cn_init_1386 = m->xmm[5][0]; __auto_type a = cn_init_1386;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_1434 = m->xmm[1]; CN_U2 s = cn_init_1434;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_1521 = m->xmm[5][0]; uint64_t s = cn_init_1521;
__auto_type cn_init_1534 = m->xmm[1][0]; __auto_type a = cn_init_1534;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_1581 = m->xmm[2][0]; uint64_t s = cn_init_1581;
__auto_type cn_init_1594 = m->xmm[1][0]; __auto_type a = cn_init_1594;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_1636 = cn_double(v28); __auto_type b = cn_init_1636;
__auto_type cn_init_1654 = cn_double(m->xmm[1][0]); __auto_type a = cn_init_1654;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_1687 = (isnan(a)||isnan(b)); __auto_type un = cn_init_1687;
(fl.zf=(un||(a==b)));
(fl.pf=un);
(fl.cf=(un||(a<b)));
}
if(cn_cond(fl,3)){
goto cn_break_b2;
}
{
__auto_type cn_init_1734 = v29; uint64_t s = cn_init_1734;
(m->xmm[3]=(CN_U2){s,0});
}
goto cn_break_b4;
}
cn_break_b2:;
{
__auto_type cn_init_1763 = cn_double(v32); __auto_type b = cn_init_1763;
__auto_type cn_init_1781 = cn_double(m->xmm[1][0]); __auto_type a = cn_init_1781;
(fl.of=false);
(fl.sf=false);
(fl.af=false);
__auto_type cn_init_1814 = (isnan(a)||isnan(b)); __auto_type un = cn_init_1814;
(fl.zf=(un||(a==b)));
(fl.pf=un);
(fl.cf=(un||(a<b)));
}
{
__auto_type cn_init_1849 = v30; uint64_t s = cn_init_1849;
(m->xmm[3]=(CN_U2){s,0});
}
if(cn_cond(fl,3)){
goto cn_break_b4;
}
{
__auto_type cn_init_1891 = m->xmm[1][0]; uint64_t s = cn_init_1891;
__auto_type cn_init_1904 = m->xmm[3][0]; __auto_type a = cn_init_1904;
(m->xmm[3][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
}
cn_break_b4:;
{
__auto_type cn_init_1944 = r6; uint64_t s = cn_init_1944;
(m->xmm[4][1]=s);
}
{
__auto_type cn_init_1974 = m->xmm[3]; CN_U2 s = cn_init_1974;
__auto_type cn_init_1984 = m->xmm[3]; __auto_type a = cn_init_1984;
(m->xmm[3]=(CN_U2){a[0],s[0]});
}
{
__auto_type cn_init_2021 = m->xmm[3]; CN_U2 s = cn_init_2021;
__auto_type cn_init_2031 = m->xmm[0]; __auto_type a = cn_init_2031;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_2110 = m->xmm[3]; CN_U2 s = cn_init_2110;
__auto_type cn_init_2120 = m->xmm[4]; __auto_type a = cn_init_2120;
(m->xmm[4]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[4][0]);
(r6=m->xmm[4][1]);
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
int cn_f_731ce2b1f7de0ce3(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_44 = 0ULL; __auto_type steps = cn_init_44;
__auto_type cn_init_49 = max_steps; __auto_type limit = cn_init_49;
__auto_type cn_init_62 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_62;
__auto_type cn_init_82 = cn_ptr(m,((uint32_t)(vb+160))); unsigned char * vm = cn_init_82;
__auto_type cn_init_95 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_95;
__auto_type cn_init_108 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_108;
__auto_type cn_init_121 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_121;
__auto_type cn_init_134 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_134;
__auto_type cn_init_147 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_147;
__auto_type cn_init_160 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_160;
__auto_type cn_init_173 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_173;
__auto_type cn_init_186 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_186;
__auto_type cn_init_199 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_199;
__auto_type cn_init_212 = cn_cell(vm,0); uint64_t v20 = cn_init_212;
__auto_type cn_init_225 = cn_cell(vm,8); uint64_t v21 = cn_init_225;
__auto_type cn_init_238 = cn_cell(vm,16); uint64_t v22 = cn_init_238;
__auto_type cn_init_251 = cn_cell(vm,24); uint64_t v23 = cn_init_251;
__auto_type cn_init_264 = cn_cell(vm,32); uint64_t v24 = cn_init_264;
__auto_type cn_init_277 = cn_cell(vm,40); uint64_t v25 = cn_init_277;
__auto_type cn_init_290 = cn_cell(vm,48); uint64_t v26 = cn_init_290;
__auto_type cn_init_303 = cn_cell(vm,56); uint64_t v27 = cn_init_303;
__auto_type cn_init_316 = cn_cell(vm,64); uint64_t v28 = cn_init_316;
__auto_type cn_init_329 = cn_cell(vm,72); uint64_t v29 = cn_init_329;
__auto_type cn_init_342 = cn_cell(vm,80); uint64_t v30 = cn_init_342;
__auto_type cn_init_355 = cn_cell(vm,96); uint64_t v32 = cn_init_355;
__auto_type cn_init_368 = cn_cell(vm,104); uint64_t v33 = cn_init_368;
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
(s2015=(((s2015&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_455 = 0x10U; __auto_type bv = cn_init_455;
__auto_type cn_init_463 = rg[4]; __auto_type av = cn_init_463;
__auto_type cn_init_481 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_481;
(rg[4]=r);
}
{
__auto_type cn_init_495 = 0xfffffff0U; __auto_type bv = cn_init_495;
__auto_type cn_init_503 = rg[4]; __auto_type av = cn_init_503;
__auto_type cn_init_521 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_521;
(rg[4]=r);
}
(m->xmm[2]=(CN_U2){r4,r5});
{
__auto_type cn_init_550 = r3; uint64_t s = cn_init_550;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_580 = (CN_U2){v26,v27}; CN_U2 s = cn_init_580;
__auto_type cn_init_590 = m->xmm[2]; __auto_type a = cn_init_590;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_660 = v26; uint64_t s = cn_init_660;
__auto_type cn_init_673 = m->xmm[1][0]; __auto_type a = cn_init_673;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_720 = (CN_U2){v24,v25}; CN_U2 s = cn_init_720;
__auto_type cn_init_730 = m->xmm[2]; __auto_type a = cn_init_730;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_800 = v23; uint64_t s = cn_init_800;
__auto_type cn_init_813 = m->xmm[1][0]; __auto_type a = cn_init_813;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_850 = 0x0U; __auto_type bv = cn_init_850;
__auto_type cn_init_867 = (((uint32_t)(((((v21>>32))&0xffffffffULL))))); __auto_type av = cn_init_867;
__auto_type cn_init_885 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_885;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_906 = r32; uint64_t s = cn_init_906;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_928 = v26; uint64_t s = cn_init_928;
__auto_type cn_init_941 = m->xmm[5][0]; __auto_type a = cn_init_941;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r4=m->xmm[2][0]);
(r5=m->xmm[2][1]);
(r3=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(rg[0]=((uint32_t)(((((v20>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1044 = 0x0U; __auto_type bv = cn_init_1044;
__auto_type cn_init_1061 = (((uint32_t)(((((v21>>0))&0xffffffffULL))))); __auto_type av = cn_init_1061;
__auto_type cn_init_1079 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1079;
}
if(cn_cond(fl,5)){
goto cn_break_b4;
}
(s2012=m->xmm[1][0]);
goto cn_break_b7;
}
cn_break_b4:;
{
__auto_type cn_init_1114 = 0x1U; __auto_type bv = cn_init_1114;
__auto_type cn_init_1131 = (((uint32_t)(((((v21>>0))&0xffffffffULL))))); __auto_type av = cn_init_1131;
__auto_type cn_init_1149 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1149;
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
(s2012=m->xmm[2][1]);
{
__auto_type cn_init_1191 = m->xmm[1]; CN_U2 s = cn_init_1191;
(m->xmm[2][1]=s[0]);
}
goto cn_break_b7;
}
cn_break_b6:;
(s2012=m->xmm[2][0]);
(m->xmm[2][0]=m->xmm[1][0]);
}
cn_break_b7:;
{
__auto_type cn_init_1253 = rg[0]; __auto_type v = cn_init_1253;
__auto_type cn_init_1260 = fl.cf; __auto_type cf = cn_init_1260;
__auto_type cn_init_1278 = cn_alu(&fl,Alu_Sub,v,1,4); __auto_type r = cn_init_1278;
(fl.cf=cf);
(rg[0]=r);
}
{
__auto_type cn_init_1298 = 0xfU; __auto_type bv = cn_init_1298;
__auto_type cn_init_1306 = rg[0]; __auto_type av = cn_init_1306;
__auto_type cn_init_1324 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1324;
(rg[0]=r);
}
(f[0]=cn_double(0x400921fb54442d18));
{
__auto_type cn_init_1350 = 0x1U; __auto_type bv = cn_init_1350;
__auto_type cn_init_1358 = rg[0]; __auto_type av = cn_init_1358;
__auto_type cn_init_1376 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1376;
}
if(cn_cond(fl,14)){
goto cn_break_b9;
}
{
__auto_type cn_init_1398 = rg[0]; __auto_type v = cn_init_1398;
__auto_type cn_init_1405 = fl.cf; __auto_type cf = cn_init_1405;
__auto_type cn_init_1423 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_1423;
(fl.cf=cf);
(rg[0]=r);
}
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
(f[1]=(((double)(((int32_t)(((uint32_t)(((((s2013>>0))&0xffffffffULL))))))))));
(f[0]=(f[0]/f[1]));
{
__auto_type cn_init_1514 = rg[0]; __auto_type v = cn_init_1514;
__auto_type cn_init_1521 = fl.cf; __auto_type cf = cn_init_1521;
__auto_type cn_init_1539 = cn_alu(&fl,Alu_Sub,v,1,4); __auto_type r = cn_init_1539;
(fl.cf=cf);
(rg[0]=r);
}
(f[0]=(f[0]+f[0]));
}
cn_break_b9:;
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1592 = cn_double(v30); __auto_type v = cn_init_1592;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_1613 = v32; uint64_t s = cn_init_1613;
(m->xmm[0]=(CN_U2){s,0});
}
cn_continue_l10:;
{
(f[2]=f[1]);
{
__auto_type cn_tuple_1658_0 = sin(f[2]);
__auto_type cn_tuple_1658_1 = cos(f[2]);
__auto_type s = cn_tuple_1658_0;
__auto_type c = cn_tuple_1658_1;
(f[2]=s);
(f[3]=c);
(fsw&=~0x0400);
}
{
__auto_type cn_init_1689 = cn_double(v28); __auto_type v = cn_init_1689;
(f[3]=(f[3]*v));
}
(s2012=cn_bits(f[3]));
{
__auto_type cn_init_1724 = cn_double(v29); __auto_type v = cn_init_1724;
(f[2]=(f[2]*v));
}
(s2013=cn_bits(f[2]));
(m->xmm[3]=m->xmm[2]);
(f[1]=(f[1]+f[0]));
{
__auto_type cn_init_1793 = (CN_U2){s2012,s2013}; CN_U2 s = cn_init_1793;
__auto_type cn_init_1803 = m->xmm[3]; __auto_type a = cn_init_1803;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])-cn_double(s[0])))),cn_bits(((cn_double(a[1])-cn_double(s[1]))))});
}
{
__auto_type cn_init_1882 = m->xmm[3]; CN_U2 s = cn_init_1882;
__auto_type cn_init_1892 = m->xmm[3]; __auto_type a = cn_init_1892;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_1971 = m->xmm[3]; CN_U2 s = cn_init_1971;

(m->xmm[4]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_2058 = m->xmm[4][0]; uint64_t s = cn_init_2058;
__auto_type cn_init_2071 = m->xmm[3][0]; __auto_type a = cn_init_2071;
(m->xmm[3][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_2118 = m->xmm[3][0]; uint64_t s = cn_init_2118;
(m->xmm[3][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_2160 = m->xmm[3][0]; uint64_t s = cn_init_2160;
__auto_type cn_init_2173 = m->xmm[0][0]; __auto_type a = cn_init_2173;
(m->xmm[0][0]=cn_bits(({__auto_type cn_tuple_2207_0 = cn_double(a);
__auto_type cn_tuple_2207_1 = cn_double(s);
__auto_type p = cn_tuple_2207_0;
__auto_type q = cn_tuple_2207_1; (((p<q))?(({p;})):(({q;})));})));
}
{
__auto_type cn_init_2231 = 0x1U; __auto_type bv = cn_init_2231;
__auto_type cn_init_2239 = rg[0]; __auto_type av = cn_init_2239;
__auto_type cn_init_2257 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_2257;
(rg[0]=r);
}
if(cn_cond(fl,9)){
(steps+=1);
if((steps>limit)){
return 1;
}
goto cn_continue_l10;
}
goto cn_break_b11;
}
goto cn_continue_l10;
cn_break_l10:;
}
cn_break_b11:;
{
__auto_type cn_init_2308 = v22; uint64_t s = cn_init_2308;
__auto_type cn_init_2321 = m->xmm[0][0]; __auto_type a = cn_init_2321;
(m->xmm[0][0]=cn_bits(((cn_double(a)-cn_double(s)))));
}
(fsw=cn_compare(f[1],f[0]));
{
__auto_type cn_init_2373 = 0x0U; __auto_type bv = cn_init_2373;
__auto_type cn_init_2390 = (((uint32_t)(((((v21>>32))&0xffffffffULL))))); __auto_type av = cn_init_2390;
__auto_type cn_init_2408 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2408;
}
if(cn_cond(fl,5)){
goto cn_break_b13;
}
{
__auto_type cn_init_2429 = v26; uint64_t s = cn_init_2429;
__auto_type cn_init_2442 = m->xmm[0][0]; __auto_type a = cn_init_2442;
(m->xmm[0][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
}
cn_break_b13:;
(r14=m->xmm[0][0]);
(rg[4]=rg[5]);
{
(rg[5]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
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
cn_wr64u(m,0x10007ef8U,s2015);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_737c34e38f81a08f(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_175 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,0); uint64_t v21 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,8); uint64_t v22 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,16); uint64_t v23 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,24); uint64_t v24 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,32); uint64_t v25 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,40); uint64_t v26 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,48); uint64_t v27 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,56); uint64_t v28 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,64); uint64_t v29 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,72); uint64_t v30 = cn_init_357;
{
{
{
{
{
{
{
__auto_type cn_init_381 = 0xffffffe0U; __auto_type bv = cn_init_381;
__auto_type cn_init_389 = rg[4]; __auto_type av = cn_init_389;
__auto_type cn_init_407 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_407;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_436 = r5; uint64_t s = cn_init_436;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_466 = (CN_U2){v28,v29}; CN_U2 s = cn_init_466;
__auto_type cn_init_476 = m->xmm[0]; __auto_type a = cn_init_476;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_546 = v28; uint64_t s = cn_init_546;
__auto_type cn_init_559 = m->xmm[1][0]; __auto_type a = cn_init_559;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_606 = (CN_U2){v24,v25}; CN_U2 s = cn_init_606;
__auto_type cn_init_616 = m->xmm[0]; __auto_type a = cn_init_616;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_686 = v26; uint64_t s = cn_init_686;
__auto_type cn_init_699 = m->xmm[1][0]; __auto_type a = cn_init_699;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_736 = 0x0U; __auto_type bv = cn_init_736;
__auto_type cn_init_753 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_753;
__auto_type cn_init_771 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_771;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_792 = r32; uint64_t s = cn_init_792;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_814 = v28; uint64_t s = cn_init_814;
__auto_type cn_init_827 = m->xmm[5][0]; __auto_type a = cn_init_827;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r3=m->xmm[0][0]);
(r4=m->xmm[0][1]);
(r5=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
{
__auto_type cn_init_923 = m->xmm[0][0]; uint64_t v = cn_init_923;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_982 = m->xmm[0][1]; uint64_t v = cn_init_982;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_1041 = m->xmm[1][0]; uint64_t v = cn_init_1041;
(s2013=(((s2013&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2014=(((s2014&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(rg[2]=((uint32_t)(((((v21>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1107 = 0x1U; __auto_type bv = cn_init_1107;
__auto_type cn_init_1115 = rg[2]; __auto_type av = cn_init_1115;
__auto_type cn_init_1133 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1133;
(rg[2]=r);
}
(f[0]=cn_double(v23));
cn_shift_reg_l(rg,&fl,Shift_Shl,2,4,4);
{
__auto_type cn_init_1189 = cn_bits(f[0]); uint64_t v = cn_init_1189;
(s2014=(((s2014&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2015=(((s2015&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
switch(((((rg[2]>>4))&1))){
case 0:
{
(f[0]=cn_double(((((((rg[2]>>4))&1))==0)?(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))):(((((((rg[2]>>4))&1))==1)?(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))):(0))))));
}
break;
case 1:
{
(f[0]=cn_double(((((((rg[2]>>4))&1))==0)?(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))):(((((((rg[2]>>4))&1))==1)?(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))):(0))))));
}
break;
default:
{
}
break;
}
{
__auto_type cn_init_1403 = 0x0U; __auto_type bv = cn_init_1403;
__auto_type cn_init_1420 = (((uint32_t)(((((v22>>0))&0xffffffffULL))))); __auto_type av = cn_init_1420;
__auto_type cn_init_1438 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1438;
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1549 = cn_double(v30); __auto_type v = cn_init_1549;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1568 = 0x0U; __auto_type bv = cn_init_1568;
__auto_type cn_init_1585 = (((uint32_t)(((((v21>>0))&0xffffffffULL))))); __auto_type av = cn_init_1585;
__auto_type cn_init_1603 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1603;
}
if(cn_cond(fl,4)){
goto cn_break_b5;
}
(f[1]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[0]));
{
__auto_type cn_init_1670 = cn_double(((((((s2014>>32))|((s2015<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1670;
(f[1]=(v/f[1]));
}
{
__auto_type cn_init_1698 = cn_bits(f[1]); uint64_t v = cn_init_1698;
(s2014=(((s2014&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2015=(((s2015&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
}
cn_break_b5:;
(f[0]=cos(f[0]));
(fsw&=~0x0400);
goto cn_break_b7;
}
cn_break_b6:;
{
__auto_type cn_init_1776 = cn_double(v30); __auto_type v = cn_init_1776;
(f[0]=(f[0]*v));
}
(f[0]=cos(f[0]));
(fsw&=~0x0400);
(f[1]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_1847 = cn_double(v30); __auto_type v = cn_init_1847;
(f[1]=(f[1]*v));
}
(f[1]=cos(f[1]));
(fsw&=~0x0400);
(f[0]=(f[0]+f[1]));
}
cn_break_b7:;
{
__auto_type cn_init_1904 = rg[2]; __auto_type v = cn_init_1904;
__auto_type cn_init_1922 = cn_alu(&fl,Alu_Sub,0,v,4); __auto_type r = cn_init_1922;
(fl.cf=((v&0xffffffff)!=0));
(rg[2]=r);
}
{
__auto_type cn_init_1967 = cn_double(((((((s2014>>32))|((s2015<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1967;
(f[0]=(f[0]*v));
}
switch(((1-((((((uint32_t)(0U-rg[2]))>>4))&1))))){
case 0:
{
{
__auto_type cn_init_2083 = cn_double(((((1-((((((uint32_t)(0U-rg[2]))>>4))&1))))==0)?(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))):(((((1-((((((uint32_t)(0U-rg[2]))>>4))&1))))==1)?(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))):(0))))); __auto_type v = cn_init_2083;
(f[0]=(f[0]-v));
}
}
break;
case 1:
{
{
__auto_type cn_init_2177 = cn_double(((((1-((((((uint32_t)(0U-rg[2]))>>4))&1))))==0)?(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))):(((((1-((((((uint32_t)(0U-rg[2]))>>4))&1))))==1)?(((((((s2013>>32))|((s2014<<32))))&0xffffffffffffffffULL))):(0))))); __auto_type v = cn_init_2177;
(f[0]=(f[0]-v));
}
}
break;
default:
{
}
break;
}
{
__auto_type cn_init_2202 = 0x0U; __auto_type bv = cn_init_2202;
__auto_type cn_init_2219 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_2219;
__auto_type cn_init_2237 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2237;
}
if(cn_cond(fl,5)){
goto cn_break_b9;
}
{
__auto_type cn_init_2261 = cn_double(v28); __auto_type v = cn_init_2261;
(f[0]=(f[0]/v));
}
}
cn_break_b9:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2292 = 0x20U; __auto_type bv = cn_init_2292;
__auto_type cn_init_2300 = rg[4]; __auto_type av = cn_init_2300;
__auto_type cn_init_2318 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2318;
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
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
cn_wr64u(m,0x10007ef8U,s2015);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_73a4cb2b7dd2ac6e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_149 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_188;
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
__auto_type cn_init_370 = cn_cell(vm,96); uint64_t v33 = cn_init_370;
{
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2015=(((s2015&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[1])))&0xffffffffULL))<<0))));
}
{
__auto_type cn_init_432 = 0xffffffd0U; __auto_type bv = cn_init_432;
__auto_type cn_init_440 = rg[4]; __auto_type av = cn_init_440;
__auto_type cn_init_458 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_458;
(rg[4]=r);
}
(f[0]=cn_double(r5));
{
__auto_type cn_init_503 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_503;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_553 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_553;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_603 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_603;
(f[2]=(f[2]-v));
}
(f[3]=f[2]);
{
__auto_type cn_init_651 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_651;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_699 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_699;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_762 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_762;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_825 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_825;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_873 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_873;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_936 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_936;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_998 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_998;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1045 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1045;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1107 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1107;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(s2010=cn_bits(f[2]));
(s2011=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(s2010));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2011));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_1276 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1276;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(s2012));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_1395 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1395;
(f[1]=(f[1]-v));
}
(f[2]=f[1]);
(f[2]=fabs(f[2]));
(f[3]=(((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))));
(f[3]=fabs(f[3]));
{
__auto_type cn_init_1483 = cn_double(v33); __auto_type v = cn_init_1483;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_1507 = cn_double(v33); __auto_type v = cn_init_1507;
(f[3]=(f[3]+v));
}
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
(f[1]=fabs(f[1]));
(r14=cn_bits(f[1]));
(f[0]=f[0]);
(f[7]=f[7]);
(f[6]=f[6]);
(f=(CN_D8){f[6],f[7],f[0],f[1],f[2],f[3],f[4],f[5]});
goto cn_break_b3;
}
cn_break_b2:;
(f[2]=f[0]);
(f[3]=cn_double(s2012));
(f[2]=atan2(f[2],f[3]));
{
__auto_type cn_init_1744 = cn_double(v32); __auto_type v = cn_init_1744;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(s2010));
(f[4]=cn_double(s2011));
(f[3]=atan2(f[3],f[4]));
{
__auto_type cn_init_1810 = cn_double(v32); __auto_type v = cn_init_1810;
(f[3]=(f[3]*v));
}
(s2009=cn_bits(f[3]));
(s2010=cn_bits(f[2]));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[1]))))))))&0xffffffffULL))<<0))));
(f[0]=f[0]);
(rg[0]=rg[4]);
(rg[2]=((uint32_t)(((((v30>>32))&0xffffffffULL)))));
(rg[1]=rg[4]);
{
__auto_type cn_init_1971 = cn_map_px(false,((int32_t)(rg[EDX])),(CN_D3){cn_double(s2009),cn_double(s2010),cn_double(s2011)}); __auto_type r = cn_init_1971;
(s2009=cn_bits(r[0]));
(s2010=cn_bits(r[1]));
(s2011=cn_bits(r[2]));
}
(rg[1]=((uint32_t)(((((v30>>0))&0xffffffffULL)))));
{
__auto_type cn_init_2028 = 0x3U; __auto_type bv = cn_init_2028;
__auto_type cn_init_2036 = rg[1]; __auto_type av = cn_init_2036;
__auto_type cn_init_2054 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2054;
(rg[1]=r);
}
switch(((((rg[1]>>0))&3))){
case 0:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2009):(((((((rg[1]>>0))&3))==1)?(s2010):(((((((rg[1]>>0))&3))==2)?(s2011):(((((((rg[1]>>0))&3))==3)?(s2012):(0))))))))));
}
break;
case 1:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2009):(((((((rg[1]>>0))&3))==1)?(s2010):(((((((rg[1]>>0))&3))==2)?(s2011):(((((((rg[1]>>0))&3))==3)?(s2012):(0))))))))));
}
break;
case 2:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2009):(((((((rg[1]>>0))&3))==1)?(s2010):(((((((rg[1]>>0))&3))==2)?(s2011):(((((((rg[1]>>0))&3))==3)?(s2012):(0))))))))));
}
break;
case 3:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2009):(((((((rg[1]>>0))&3))==1)?(s2010):(((((((rg[1]>>0))&3))==2)?(s2011):(((((((rg[1]>>0))&3))==3)?(s2012):(0))))))))));
}
break;
default:
{
}
break;
}
{
__auto_type cn_init_2288 = cn_double(v31); __auto_type v = cn_init_2288;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_2326 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2326;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2364 = (((double)(cn_float(((uint32_t)(((((s2012>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2364;
(f[0]=(v-f[0]));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_2402 = cn_double(v33); __auto_type v = cn_init_2402;
(f[0]=(f[0]-v));
}
(r14=cn_bits(f[0]));
(rg[1]=((uint32_t)(((((v22>>0))&0xffffffffULL)))));
{
__auto_type cn_init_2449 = 0x3U; __auto_type bv = cn_init_2449;
__auto_type cn_init_2457 = rg[1]; __auto_type av = cn_init_2457;
__auto_type cn_init_2475 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2475;
(rg[1]=r);
}
switch(((((rg[1]>>0))&3))){
case 0:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2009):(((((((rg[1]>>0))&3))==1)?(s2010):(((((((rg[1]>>0))&3))==2)?(s2011):(((((((rg[1]>>0))&3))==3)?(s2012):(0))))))))));
}
break;
case 1:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2009):(((((((rg[1]>>0))&3))==1)?(s2010):(((((((rg[1]>>0))&3))==2)?(s2011):(((((((rg[1]>>0))&3))==3)?(s2012):(0))))))))));
}
break;
case 2:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2009):(((((((rg[1]>>0))&3))==1)?(s2010):(((((((rg[1]>>0))&3))==2)?(s2011):(((((((rg[1]>>0))&3))==3)?(s2012):(0))))))))));
}
break;
case 3:
{
(f[0]=cn_double(((((((rg[1]>>0))&3))==0)?(s2009):(((((((rg[1]>>0))&3))==1)?(s2010):(((((((rg[1]>>0))&3))==2)?(s2011):(((((((rg[1]>>0))&3))==3)?(s2012):(0))))))))));
}
break;
default:
{
}
break;
}
{
__auto_type cn_init_2723 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2723;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_2761 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2761;
(f[0]=(f[0]*v));
}
(r34=cn_bits(f[0]));
}
cn_break_b3:;
{
__auto_type cn_init_2792 = 0x30U; __auto_type bv = cn_init_2792;
__auto_type cn_init_2800 = rg[4]; __auto_type av = cn_init_2800;
__auto_type cn_init_2818 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2818;
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
cn_wr64u(m,0x10007ec8U,s2009);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ef8U,s2015);
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_744b631186296222(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_149 = cn_rd64u(m,0x10001078U); uint64_t r15 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ec8U); uint64_t s2009 = cn_init_201;
__auto_type cn_init_214 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_214;
__auto_type cn_init_227 = cn_rd64u(m,0x10007ed8U); uint64_t s2011 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,0); uint64_t v18 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,8); uint64_t v19 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,16); uint64_t v20 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,24); uint64_t v21 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,32); uint64_t v22 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,40); uint64_t v23 = cn_init_305;
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
__auto_type cn_init_448 = cn_cell(vm,136); uint64_t v35 = cn_init_448;
__auto_type cn_init_461 = cn_cell(vm,144); uint64_t v36 = cn_init_461;
__auto_type cn_init_474 = cn_cell(vm,152); uint64_t v37 = cn_init_474;
__auto_type cn_init_487 = cn_cell(vm,160); uint64_t v38 = cn_init_487;
{
{
{
{
{
{
__auto_type cn_init_508 = 0xffffffccU; __auto_type bv = cn_init_508;
__auto_type cn_init_516 = rg[4]; __auto_type av = cn_init_516;
__auto_type cn_init_534 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_534;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r3,r4});
{
__auto_type cn_init_563 = r5; uint64_t s = cn_init_563;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_593 = (CN_U2){v28,v29}; CN_U2 s = cn_init_593;
__auto_type cn_init_603 = m->xmm[0]; __auto_type a = cn_init_603;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_673 = v28; uint64_t s = cn_init_673;
__auto_type cn_init_686 = m->xmm[1][0]; __auto_type a = cn_init_686;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_733 = (CN_U2){v24,v25}; CN_U2 s = cn_init_733;
__auto_type cn_init_743 = m->xmm[0]; __auto_type a = cn_init_743;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_813 = v26; uint64_t s = cn_init_813;
__auto_type cn_init_826 = m->xmm[1][0]; __auto_type a = cn_init_826;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_863 = 0x0U; __auto_type bv = cn_init_863;
__auto_type cn_init_880 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_880;
__auto_type cn_init_898 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_898;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_919 = r32; uint64_t s = cn_init_919;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_941 = v28; uint64_t s = cn_init_941;
__auto_type cn_init_954 = m->xmm[5][0]; __auto_type a = cn_init_954;
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
{
__auto_type cn_init_1076 = 0xffffffd4U; __auto_type bv = cn_init_1076;
__auto_type cn_init_1084 = rg[7]; __auto_type av = cn_init_1084;
__auto_type cn_init_1102 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1102;
(rg[7]=r);
}
(f[0]=cn_double(s2011));
(f[1]=cn_double(s2010));
(f[2]=cn_double(s2009));
(f[3]=f[2]);
{
__auto_type cn_init_1181 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1181;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1229 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1229;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1292 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1292;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1355 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1355;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1403 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1403;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1466 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1466;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1528 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1528;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1575 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1575;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1637 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1637;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(s2009=cn_bits(f[2]));
(s2010=cn_bits(f[1]));
(s2011=cn_bits(f[0]));
{
__auto_type cn_init_1704 = 0x2cU; __auto_type bv = cn_init_1704;
__auto_type cn_init_1712 = rg[7]; __auto_type av = cn_init_1712;
__auto_type cn_init_1730 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1730;
(rg[7]=r);
}
(f[0]=cn_double(s2010));
{
__auto_type cn_init_1761 = cn_double(v32); __auto_type v = cn_init_1761;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(s2011));
(f[2]=cn_double(s2009));
(f[2]=(f[2]*f[2]));
(s2011=cn_bits(f[2]));
cn_swap(f,2,1);
(f[2]=(f[2]*f[2]));
(s2009=cn_bits(f[2]));
(f[3]=cn_double(s2010));
(f[3]=(f[3]*f[3]));
(f[2]=(f[2]+f[3]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
cn_swap(f,1,0);
(f[1]=(f[1]*f[1]));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_1994 = cn_double(v33); __auto_type v = cn_init_1994;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(s2009));
{
__auto_type cn_init_2030 = cn_double(v34); __auto_type v = cn_init_2030;
(f[2]=(f[2]*v));
}
(f[1]=(f[2]/f[1]));
{
__auto_type cn_init_2069 = cn_double(s2011); __auto_type v = cn_init_2069;
(f[1]=(f[1]+v));
}
(f[1]=sqrt(f[1]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_2121 = cn_double(v36); __auto_type v = cn_init_2121;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2010));
{
__auto_type cn_init_2157 = cn_double(v35); __auto_type v = cn_init_2157;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=fabs(f[1]));
(f[1]=(f[1]*f[1]));
{
__auto_type cn_init_2225 = cn_double(s2011); __auto_type v = cn_init_2225;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(s2009));
{
__auto_type cn_init_2261 = cn_double(v37); __auto_type v = cn_init_2261;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]-f[2]));
cn_swap(f,1,0);
{
__auto_type cn_init_2350 = cn_double(v38); __auto_type v = cn_init_2350;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_2406 = 0x41U; __auto_type bv = cn_init_2406;
__auto_type cn_init_2419 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2419;
__auto_type cn_init_2437 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2437;
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
{
__auto_type cn_init_2494 = 0x0U; __auto_type bv = cn_init_2494;
__auto_type cn_init_2511 = (((uint32_t)(((((v23>>32))&0xffffffffULL))))); __auto_type av = cn_init_2511;
__auto_type cn_init_2529 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2529;
}
if(cn_cond(fl,5)){
goto cn_break_b7;
}
{
__auto_type cn_init_2553 = cn_double(v28); __auto_type v = cn_init_2553;
(f[0]=(f[0]/v));
}
}
cn_break_b7:;
(r14=cn_bits(f[0]));
(f[0]=cn_double(v30));
(f[1]=(((double)(((int32_t)(((uint32_t)(((((r15>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_2640 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2640;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(r34=cn_bits(f[0]));
{
__auto_type cn_init_2699 = 0x34U; __auto_type bv = cn_init_2699;
__auto_type cn_init_2707 = rg[4]; __auto_type av = cn_init_2707;
__auto_type cn_init_2725 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2725;
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
((*regs)=rg);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_761967f9cfb5d4ab(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=cn_double(r3));
{
__auto_type cn_init_463 = cn_double(v28); __auto_type v = cn_init_463;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_487 = cn_double(r5); __auto_type v = cn_init_487;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_511 = cn_double(v30); __auto_type v = cn_init_511;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_547 = cn_double(v28); __auto_type v = cn_init_547;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_571 = cn_double(r6); __auto_type v = cn_init_571;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_595 = cn_double(v30); __auto_type v = cn_init_595;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r4));
{
__auto_type cn_init_631 = cn_double(v27); __auto_type v = cn_init_631;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r3));
{
__auto_type cn_init_667 = cn_double(v26); __auto_type v = cn_init_667;
(f[3]=(f[3]*v));
}
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[3]));
(f[3]=-f[3]);
{
__auto_type cn_init_755 = cn_double(v24); __auto_type v = cn_init_755;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_779 = cn_double(v25); __auto_type v = cn_init_779;
(f[3]=(f[3]+v));
}
{
__auto_type cn_init_803 = cn_double(r5); __auto_type v = cn_init_803;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
{
__auto_type cn_init_854 = cn_double(v27); __auto_type v = cn_init_854;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r4));
{
__auto_type cn_init_890 = cn_double(v26); __auto_type v = cn_init_890;
(f[4]=(f[4]*v));
}
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[4]));
(f[4]=-f[4]);
{
__auto_type cn_init_978 = cn_double(v23); __auto_type v = cn_init_978;
(f[4]=(f[4]*v));
}
{
__auto_type cn_init_1002 = cn_double(v29); __auto_type v = cn_init_1002;
(f[4]=(f[4]+v));
}
{
__auto_type cn_init_1026 = cn_double(r6); __auto_type v = cn_init_1026;
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
int cn_f_761edaf86f8ce0b6(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
{
{
{
{
{
{
__auto_type cn_init_2691 = cn_bits(f[0]); uint64_t v = cn_init_2691;
(s2012=(((s2012&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2013=(((s2013&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(v23));
(f[1]=cn_double(((((((s2006>>16))|((s2007<<48))))&0xffffffffffffffffULL))));
(f[1]=(f[1]*f[0]));
{
__auto_type cn_init_2816 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2816;
(f[1]=(f[1]*v));
}
cn_continue_l12:;
{
{
__auto_type cn_tuple_2853_0 = f[1];
__auto_type cn_tuple_2853_1 = f[0];
__auto_type x = cn_tuple_2853_0;
__auto_type y = cn_tuple_2853_1;
__auto_type cn_init_2882 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_2882;
(f[1]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_2914 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_2914;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_3002 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_3002;
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
__auto_type cn_init_3125 = cn_double(((((((v13>>32))|((v14<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3125;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
(f[0]=-f[0]);
{
__auto_type cn_init_3174 = cn_double(v32); __auto_type v = cn_init_3174;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_3214 = cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3214;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(v23));
(f[2]=cn_double(((((((s2005>>16))|((s2006<<48))))&0xffffffffffffffffULL))));
(f[2]=(f[2]*f[1]));
{
__auto_type cn_init_3309 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3309;
(f[2]=(f[2]*v));
}
cn_continue_l14:;
{
{
__auto_type cn_tuple_3346_0 = f[2];
__auto_type cn_tuple_3346_1 = f[1];
__auto_type x = cn_tuple_3346_0;
__auto_type y = cn_tuple_3346_1;
__auto_type cn_init_3375 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_3375;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_3407 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_3407;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_3495 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_3495;
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
__auto_type cn_init_3618 = cn_double(((((((v13>>32))|((v14<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3618;
(f[1]=(f[1]-v));
}
(f[1]=fabs(f[1]));
(f[1]=-f[1]);
{
__auto_type cn_init_3667 = cn_double(v32); __auto_type v = cn_init_3667;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_3707 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3707;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(v23));
(f[3]=cn_double(((((((s2004>>16))|((s2005<<48))))&0xffffffffffffffffULL))));
(f[3]=(f[3]*f[2]));
{
__auto_type cn_init_3802 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3802;
(f[3]=(f[3]*v));
}
cn_continue_l16:;
{
{
__auto_type cn_tuple_3839_0 = f[3];
__auto_type cn_tuple_3839_1 = f[2];
__auto_type x = cn_tuple_3839_0;
__auto_type y = cn_tuple_3839_1;
__auto_type cn_init_3868 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_3868;
(f[3]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_3900 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_3900;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
{
__auto_type cn_init_3988 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_3988;
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
__auto_type cn_init_4111 = cn_double(((((((v13>>32))|((v14<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4111;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_4160 = cn_double(v32); __auto_type v = cn_init_4160;
(f[2]=(f[2]+v));
}
{
__auto_type cn_init_4200 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4200;
(f[2]=(f[2]+v));
}
(f[3]=f[2]);
{
__auto_type cn_init_4248 = (((double)(cn_float(((uint32_t)(((((v15>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4248;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_4296 = (((double)(cn_float(((uint32_t)(((((v15>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4296;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_4359 = (((double)(cn_float(((uint32_t)(((((v14>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4359;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_4422 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4422;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_4470 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4470;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_4533 = (((double)(cn_float(((uint32_t)(((((v17>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4533;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_4595 = (((double)(cn_float(((uint32_t)(((((v17>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4595;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_4642 = (((double)(cn_float(((uint32_t)(((((v16>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4642;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_4704 = (((double)(cn_float(((uint32_t)(((((v16>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4704;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_4747 = cn_bits(f[2]); uint64_t v = cn_init_4747;
(s2007=(((s2007&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2008=(((s2008&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_4805 = cn_bits(f[1]); uint64_t v = cn_init_4805;
(s2008=(((s2008&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2009=(((s2009&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_4863 = cn_bits(f[0]); uint64_t v = cn_init_4863;
(s2009=(((s2009&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2010=(((s2010&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[0]=cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))));
(f[1]=cn_double(((((((s2008>>16))|((s2009<<48))))&0xffffffffffffffffULL))));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_5005 = 0x41U; __auto_type bv = cn_init_5005;
__auto_type cn_init_5018 = cn_reg_get(rg,4,1); __auto_type av = cn_init_5018;
__auto_type cn_init_5036 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5036;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b19;
}
(f[0]=f[1]);
goto cn_break_b20;
}
cn_break_b19:;
(f[1]=f[1]);
}
cn_break_b20:;
(f[1]=cn_double(((((((s2007>>16))|((s2008<<48))))&0xffffffffffffffffULL))));
(f[2]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_5186 = 0x41U; __auto_type bv = cn_init_5186;
__auto_type cn_init_5199 = cn_reg_get(rg,4,1); __auto_type av = cn_init_5199;
__auto_type cn_init_5217 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5217;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b22;
}
(f[1]=f[2]);
goto cn_break_b23;
}
cn_break_b22:;
(f[2]=f[2]);
}
cn_break_b23:;
(f[2]=cn_double(((((((s2008>>16))|((s2009<<48))))&0xffffffffffffffffULL))));
(f[3]=cn_double(((((((s2009>>16))|((s2010<<48))))&0xffffffffffffffffULL))));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
{
__auto_type cn_init_5367 = 0x41U; __auto_type bv = cn_init_5367;
__auto_type cn_init_5380 = cn_reg_get(rg,4,1); __auto_type av = cn_init_5380;
__auto_type cn_init_5398 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5398;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b25;
}
(f[2]=f[3]);
goto cn_break_b26;
}
cn_break_b25:;
(f[3]=f[3]);
}
cn_break_b26:;
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_5492 = 0x41U; __auto_type bv = cn_init_5492;
__auto_type cn_init_5505 = cn_reg_get(rg,4,1); __auto_type av = cn_init_5505;
__auto_type cn_init_5523 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5523;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b28;
}
(f[1]=f[2]);
goto cn_break_b29;
}
cn_break_b28:;
(f[2]=f[2]);
}
cn_break_b29:;
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_5617 = 0x41U; __auto_type bv = cn_init_5617;
__auto_type cn_init_5630 = cn_reg_get(rg,4,1); __auto_type av = cn_init_5630;
__auto_type cn_init_5648 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5648;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b31;
}
(f[0]=f[1]);
goto cn_break_b32;
}
cn_break_b31:;
(f[1]=f[1]);
}
cn_break_b32:;
{
__auto_type cn_init_5726 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5726;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_5754 = cn_bits(f[0]); uint64_t v = cn_init_5754;
(s2011=(((s2011&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2012=(((s2012&~0xffffULL))|((((v>>48))&0xffffULL))));
}
(f[1]=cn_double(((((((s2012>>16))|((s2013<<48))))&0xffffffffffffffffULL))));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_5868 = 0x41U; __auto_type bv = cn_init_5868;
__auto_type cn_init_5881 = cn_reg_get(rg,4,1); __auto_type av = cn_init_5881;
__auto_type cn_init_5899 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_5899;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,5)){
goto cn_break_b34;
}
(f[0]=f[1]);
goto cn_break_b35;
}
cn_break_b34:;
(f[1]=f[1]);
}
cn_break_b35:;
(f[1]=cn_double(v30));
{
__auto_type cn_init_5989 = cn_double(((((((s2010>>16))|((s2011<<48))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5989;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_6017 = cn_bits(f[1]); uint64_t v = cn_init_6017;
(s2010=(((s2010&~((0xffffffffffffULL<<16))))|((((v&0xffffffffffffULL))<<16))));
(s2011=(((s2011&~0xffffULL))|((((v>>48))&0xffffULL))));
}
{
__auto_type cn_init_6069 = rg[2]; __auto_type v = cn_init_6069;
__auto_type cn_init_6076 = fl.cf; __auto_type cf = cn_init_6076;
__auto_type cn_init_6094 = cn_alu(&fl,Alu_Sub,v,1,4); __auto_type r = cn_init_6094;
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
goto cn_break_b36;
}
goto cn_continue_l11;
cn_break_l11:;
}
cn_break_b36:;
{
__auto_type cn_init_6149 = 0x0U; __auto_type bv = cn_init_6149;
__auto_type cn_init_6166 = (((uint32_t)(((((v22>>32))&0xffffffffULL))))); __auto_type av = cn_init_6166;
__auto_type cn_init_6184 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_6184;
}
if(cn_cond(fl,5)){
goto cn_break_b38;
}
{
__auto_type cn_init_6208 = cn_double(v28); __auto_type v = cn_init_6208;
(f[0]=(f[0]/v));
}
}
cn_break_b38:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_6239 = 0x5aU; __auto_type bv = cn_init_6239;
__auto_type cn_init_6247 = rg[4]; __auto_type av = cn_init_6247;
__auto_type cn_init_6265 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_6265;
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
int cn_f_76665bf51ca8f80e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+184))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(3)); uint64_t r3 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_156 = cn_rd64(m,CN_REC+8*(33)); uint64_t r33 = cn_init_156;
__auto_type cn_init_169 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_169;
__auto_type cn_init_182 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_182;
__auto_type cn_init_195 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_195;
__auto_type cn_init_208 = cn_rd64u(m,0x10007ef8U); uint64_t s2015 = cn_init_208;
__auto_type cn_init_221 = cn_cell(vm,0); uint64_t v23 = cn_init_221;
__auto_type cn_init_234 = cn_cell(vm,8); uint64_t v24 = cn_init_234;
__auto_type cn_init_247 = cn_cell(vm,16); uint64_t v25 = cn_init_247;
__auto_type cn_init_260 = cn_cell(vm,24); uint64_t v26 = cn_init_260;
__auto_type cn_init_273 = cn_cell(vm,32); uint64_t v27 = cn_init_273;
__auto_type cn_init_286 = cn_cell(vm,40); uint64_t v28 = cn_init_286;
__auto_type cn_init_299 = cn_cell(vm,48); uint64_t v29 = cn_init_299;
__auto_type cn_init_312 = cn_cell(vm,56); uint64_t v30 = cn_init_312;
__auto_type cn_init_325 = cn_cell(vm,72); uint64_t v32 = cn_init_325;
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
__auto_type cn_init_641 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_641;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_689 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_689;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_752 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_752;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_815 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_815;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_863 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_863;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_926 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_926;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_988 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_988;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1035 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1035;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1097 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1097;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[1]=cn_double(r3));
{
__auto_type cn_init_1200 = (((uint32_t)(((((r33>>0))&0xffffffffULL))))); __auto_type v = cn_init_1200;
__auto_type cn_init_1207 = fl.cf; __auto_type cf = cn_init_1207;
__auto_type cn_init_1225 = cn_alu(&fl,Alu_Add,v,1,4); __auto_type r = cn_init_1225;
(fl.cf=cf);
(r33=(((r33&~((0xffffffffULL<<0))))|(((((((uint64_t)((r))))&0xffffffffULL))<<0))));
}
(f[2]=(((double)(((int32_t)(((uint32_t)(((((r33>>0))&0xffffffffULL))))))))));
{
__auto_type cn_init_1311 = cn_double(((((((v24>>32))|((v25<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1311;
(f[2]=(f[2]-v));
}
(f[3]=cn_double(((((((v23>>32))|((v24<<32))))&0xffffffffffffffffULL))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008070U))))&0xffffffffULL))<<0))));
cn_swap(f,3,2);
(f[3]=fabs(f[3]));
(f[4]=cn_double(0x3fe62e42fefa39ef));
cn_swap(f,4,3);
(f[3]*=log2(f[4]));
cn_swap(f,3,2);
(f[2]=(f[2]*f[3]));
(f[3]=cn_double(0x3ff71547652b82fe));
(f[2]=(f[2]*f[3]));
(f[3]=f[2]);
(f[3]=cn_round(m,f[3]));
(f[2]=(f[2]-f[3]));
cn_swap(f,3,2);
(f[3]=(exp2(f[3])-1.0));
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[3]+f[4]));
(f[3]*=exp2(trunc(f[2])));
(f[2]=f[3]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_1667 = cn_double(((((((v25>>32))|((v26<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1667;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_1691 = cn_double(v32); __auto_type v = cn_init_1691;
(f[2]=(f[2]*v));
}
{
__auto_type cn_tuple_1721_0 = sin(f[2]);
__auto_type cn_tuple_1721_1 = cos(f[2]);
__auto_type s = cn_tuple_1721_0;
__auto_type c = cn_tuple_1721_1;
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
__auto_type cn_init_1944 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1944;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1992 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1992;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2055 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2055;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_2118 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2118;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_2166 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2166;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2229 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2229;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_2291 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2291;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_2338 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2338;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2400 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2400;
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
cn_wr64(m,CN_REC+8*(33),r33);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_76a1e74342587564(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+112))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,0); uint64_t v14 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,8); uint64_t v15 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,16); uint64_t v16 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,24); uint64_t v17 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,32); uint64_t v18 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,40); uint64_t v19 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,48); uint64_t v20 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,56); uint64_t v21 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,64); uint64_t v22 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,72); uint64_t v23 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,80); uint64_t v24 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,88); uint64_t v25 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,96); uint64_t v26 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,104); uint64_t v27 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,112); uint64_t v28 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,120); uint64_t v29 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,128); uint64_t v30 = cn_init_422;
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
__auto_type cn_init_461 = 0xffffffe4U; __auto_type bv = cn_init_461;
__auto_type cn_init_469 = rg[4]; __auto_type av = cn_init_469;
__auto_type cn_init_487 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_487;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r4,r5});
{
__auto_type cn_init_516 = r3; uint64_t s = cn_init_516;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_546 = (CN_U2){v26,v27}; CN_U2 s = cn_init_546;
__auto_type cn_init_556 = m->xmm[0]; __auto_type a = cn_init_556;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_626 = v26; uint64_t s = cn_init_626;
__auto_type cn_init_639 = m->xmm[1][0]; __auto_type a = cn_init_639;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_686 = (CN_U2){v24,v25}; CN_U2 s = cn_init_686;
__auto_type cn_init_696 = m->xmm[0]; __auto_type a = cn_init_696;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_766 = v23; uint64_t s = cn_init_766;
__auto_type cn_init_779 = m->xmm[1][0]; __auto_type a = cn_init_779;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_816 = 0x0U; __auto_type bv = cn_init_816;
__auto_type cn_init_833 = (((uint32_t)(((((v18>>32))&0xffffffffULL))))); __auto_type av = cn_init_833;
__auto_type cn_init_851 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_851;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_872 = r32; uint64_t s = cn_init_872;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_894 = v26; uint64_t s = cn_init_894;
__auto_type cn_init_907 = m->xmm[5][0]; __auto_type a = cn_init_907;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r4=m->xmm[0][0]);
(r5=m->xmm[0][1]);
(r3=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(s2012=m->xmm[0][0]);
(s2013=m->xmm[0][1]);
(s2014=m->xmm[1][0]);
(f[0]=cn_double(s2012));
(f[1]=cn_double(s2013));
(f[2]=cn_double(s2014));
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
(s2014=cn_bits(f[2]));
(s2013=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_1666 = cn_double(v22); __auto_type v = cn_init_1666;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2014));
{
__auto_type cn_init_1702 = cn_double(v21); __auto_type v = cn_init_1702;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1753 = cn_double(v21); __auto_type v = cn_init_1753;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2014));
{
__auto_type cn_init_1789 = cn_double(v22); __auto_type v = cn_init_1789;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(s2012=cn_bits(f[1]));
(s2014=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_1873 = cn_double(v20); __auto_type v = cn_init_1873;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1909 = cn_double(v19); __auto_type v = cn_init_1909;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1960 = cn_double(v19); __auto_type v = cn_init_1960;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2013));
{
__auto_type cn_init_1996 = cn_double(v20); __auto_type v = cn_init_1996;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(s2012=cn_bits(f[1]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_2080 = cn_double(v29); __auto_type v = cn_init_2080;
(f[0]=(f[0]-v));
}
(s2013=cn_bits(f[0]));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2014));
{
__auto_type cn_init_2142 = cn_double(v28); __auto_type v = cn_init_2142;
(f[1]=(f[1]-v));
}
(s2014=cn_bits(f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2221 = cn_double(v30); __auto_type v = cn_init_2221;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2012));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2287 = cn_double(((((((v17>>32))|((v18<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2287;
(f[1]=(f[1]-v));
}
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(s2013));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(s2014));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_2440 = cn_double(((((((v16>>32))|((v17<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2440;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_2496 = 0x41U; __auto_type bv = cn_init_2496;
__auto_type cn_init_2509 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2509;
__auto_type cn_init_2527 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2527;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b16;
}
(f[0]=f[1]);
(f[1]=cn_double(((((((v14>>32))|((v15<<32))))&0xffffffffffffffffULL))));
goto cn_break_b17;
}
cn_break_b16:;
(f[1]=f[1]);
(f[1]=cn_double(((((((v15>>32))|((v16<<32))))&0xffffffffffffffffULL))));
}
cn_break_b17:;
(r34=cn_bits(f[1]));
{
__auto_type cn_init_2651 = 0x0U; __auto_type bv = cn_init_2651;
__auto_type cn_init_2668 = (((uint32_t)(((((v18>>32))&0xffffffffULL))))); __auto_type av = cn_init_2668;
__auto_type cn_init_2686 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2686;
}
if(cn_cond(fl,5)){
goto cn_break_b19;
}
{
__auto_type cn_init_2710 = cn_double(v26); __auto_type v = cn_init_2710;
(f[0]=(f[0]/v));
}
}
cn_break_b19:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2741 = 0x1cU; __auto_type bv = cn_init_2741;
__auto_type cn_init_2749 = rg[4]; __auto_type av = cn_init_2749;
__auto_type cn_init_2767 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2767;
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
int cn_f_76b09de54fd4686e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+216))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(5)); uint64_t r5 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(6)); uint64_t r6 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_139;
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
(f[0]=cn_double(v30));
(r5=cn_bits(f[0]));
(f[0]=cn_double(v29));
(r6=cn_bits(f[0]));
(f[0]=cn_double(v28));
(r10=cn_bits(f[0]));
(f[0]=cn_double(v27));
(r11=cn_bits(f[0]));
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
cn_wr64(m,CN_REC+8*(6),r6);
cn_wr64(m,CN_REC+8*(10),r10);
cn_wr64(m,CN_REC+8*(11),r11);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_7724433f6933be63(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_22 = cn_initial_regs; __auto_type rg = cn_init_22;
__auto_type cn_init_32 = (CN_Flags){0}; __auto_type fl = cn_init_32;
__auto_type cn_init_38 = 0U; __auto_type fsw = cn_init_38;
__auto_type cn_init_51 = ((uint32_t)(rg[EDI]-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+112))); unsigned char * vm = cn_init_71;
__auto_type cn_init_84 = cn_rd64u(m,0x10001018U); uint64_t r3 = cn_init_84;
__auto_type cn_init_97 = cn_rd64u(m,0x10001020U); uint64_t r4 = cn_init_97;
__auto_type cn_init_110 = cn_rd64u(m,0x10001028U); uint64_t r5 = cn_init_110;
__auto_type cn_init_123 = cn_rd64u(m,0x10001070U); uint64_t r14 = cn_init_123;
__auto_type cn_init_136 = cn_rd64u(m,0x10001100U); uint64_t r32 = cn_init_136;
__auto_type cn_init_149 = cn_rd64u(m,0x10001108U); uint64_t r33 = cn_init_149;
__auto_type cn_init_162 = cn_rd64u(m,0x10001110U); uint64_t r34 = cn_init_162;
__auto_type cn_init_175 = cn_rd64u(m,0x10007ee0U); uint64_t s2012 = cn_init_175;
__auto_type cn_init_188 = cn_rd64u(m,0x10007ee8U); uint64_t s2013 = cn_init_188;
__auto_type cn_init_201 = cn_rd64u(m,0x10007ef0U); uint64_t s2014 = cn_init_201;
__auto_type cn_init_214 = cn_cell(vm,0); uint64_t v14 = cn_init_214;
__auto_type cn_init_227 = cn_cell(vm,8); uint64_t v15 = cn_init_227;
__auto_type cn_init_240 = cn_cell(vm,16); uint64_t v16 = cn_init_240;
__auto_type cn_init_253 = cn_cell(vm,24); uint64_t v17 = cn_init_253;
__auto_type cn_init_266 = cn_cell(vm,32); uint64_t v18 = cn_init_266;
__auto_type cn_init_279 = cn_cell(vm,40); uint64_t v19 = cn_init_279;
__auto_type cn_init_292 = cn_cell(vm,48); uint64_t v20 = cn_init_292;
__auto_type cn_init_305 = cn_cell(vm,56); uint64_t v21 = cn_init_305;
__auto_type cn_init_318 = cn_cell(vm,64); uint64_t v22 = cn_init_318;
__auto_type cn_init_331 = cn_cell(vm,72); uint64_t v23 = cn_init_331;
__auto_type cn_init_344 = cn_cell(vm,80); uint64_t v24 = cn_init_344;
__auto_type cn_init_357 = cn_cell(vm,88); uint64_t v25 = cn_init_357;
__auto_type cn_init_370 = cn_cell(vm,96); uint64_t v26 = cn_init_370;
__auto_type cn_init_383 = cn_cell(vm,104); uint64_t v27 = cn_init_383;
__auto_type cn_init_396 = cn_cell(vm,112); uint64_t v28 = cn_init_396;
__auto_type cn_init_409 = cn_cell(vm,120); uint64_t v29 = cn_init_409;
__auto_type cn_init_422 = cn_cell(vm,128); uint64_t v30 = cn_init_422;
{
{
{
{
{
{
{
{
{
__auto_type cn_init_452 = 0xffffffe4U; __auto_type bv = cn_init_452;
__auto_type cn_init_460 = rg[4]; __auto_type av = cn_init_460;
__auto_type cn_init_478 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_478;
(rg[4]=r);
}
(m->xmm[0]=(CN_U2){r4,r5});
{
__auto_type cn_init_507 = r3; uint64_t s = cn_init_507;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_537 = (CN_U2){v26,v27}; CN_U2 s = cn_init_537;
__auto_type cn_init_547 = m->xmm[0]; __auto_type a = cn_init_547;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_617 = v26; uint64_t s = cn_init_617;
__auto_type cn_init_630 = m->xmm[1][0]; __auto_type a = cn_init_630;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_677 = (CN_U2){v24,v25}; CN_U2 s = cn_init_677;
__auto_type cn_init_687 = m->xmm[0]; __auto_type a = cn_init_687;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(s[0])))),cn_bits(((cn_double(a[1])+cn_double(s[1]))))});
}
{
__auto_type cn_init_757 = v23; uint64_t s = cn_init_757;
__auto_type cn_init_770 = m->xmm[1][0]; __auto_type a = cn_init_770;
(m->xmm[1][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_807 = 0x0U; __auto_type bv = cn_init_807;
__auto_type cn_init_824 = (((uint32_t)(((((v18>>32))&0xffffffffULL))))); __auto_type av = cn_init_824;
__auto_type cn_init_842 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_842;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_863 = r32; uint64_t s = cn_init_863;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_885 = v26; uint64_t s = cn_init_885;
__auto_type cn_init_898 = m->xmm[5][0]; __auto_type a = cn_init_898;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r4=m->xmm[0][0]);
(r5=m->xmm[0][1]);
(r3=m->xmm[1][0]);
(r32=m->xmm[5][0]);
}
cn_break_b2:;
(s2012=m->xmm[0][0]);
(s2013=m->xmm[0][1]);
(s2014=m->xmm[1][0]);
(f[0]=cn_double(s2012));
(f[0]=fabs(f[0]));
(f[1]=cn_double(s2013));
(f[1]=fabs(f[1]));
(f[2]=cn_double(s2014));
(f[2]=fabs(f[2]));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_1135 = 0x41U; __auto_type bv = cn_init_1135;
__auto_type cn_init_1148 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1148;
__auto_type cn_init_1166 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1166;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
cn_swap(f,2,1);
}
cn_break_b4:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_1245 = 0x41U; __auto_type bv = cn_init_1245;
__auto_type cn_init_1258 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1258;
__auto_type cn_init_1276 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1276;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
cn_swap(f,2,0);
}
cn_break_b6:;
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_1364 = 0x41U; __auto_type bv = cn_init_1364;
__auto_type cn_init_1377 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1377;
__auto_type cn_init_1395 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1395;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
cn_swap(f,2,0);
}
cn_break_b8:;
(s2014=cn_bits(f[2]));
(s2013=cn_bits(f[1]));
(s2012=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_1487 = cn_double(v22); __auto_type v = cn_init_1487;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2014));
{
__auto_type cn_init_1523 = cn_double(v21); __auto_type v = cn_init_1523;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1574 = cn_double(v21); __auto_type v = cn_init_1574;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2014));
{
__auto_type cn_init_1610 = cn_double(v22); __auto_type v = cn_init_1610;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(s2012=cn_bits(f[1]));
(s2014=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_1694 = cn_double(v20); __auto_type v = cn_init_1694;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1730 = cn_double(v19); __auto_type v = cn_init_1730;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2012));
{
__auto_type cn_init_1781 = cn_double(v19); __auto_type v = cn_init_1781;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2013));
{
__auto_type cn_init_1817 = cn_double(v20); __auto_type v = cn_init_1817;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(s2012=cn_bits(f[1]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1901 = cn_double(v29); __auto_type v = cn_init_1901;
(f[0]=(f[0]-v));
}
(s2013=cn_bits(f[0]));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2014));
{
__auto_type cn_init_1963 = cn_double(v28); __auto_type v = cn_init_1963;
(f[1]=(f[1]-v));
}
(s2014=cn_bits(f[1]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2042 = cn_double(v30); __auto_type v = cn_init_2042;
(f[0]=(f[0]-v));
}
(f[1]=cn_double(s2012));
(f[1]=fabs(f[1]));
{
__auto_type cn_init_2108 = cn_double(((((((v17>>32))|((v18<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2108;
(f[1]=(f[1]-v));
}
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(s2013));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(s2014));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
{
__auto_type cn_init_2261 = cn_double(((((((v16>>32))|((v17<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2261;
(f[1]=(f[1]-v));
}
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_2317 = 0x41U; __auto_type bv = cn_init_2317;
__auto_type cn_init_2330 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2330;
__auto_type cn_init_2348 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2348;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b10;
}
(f[0]=f[1]);
(f[1]=cn_double(((((((v14>>32))|((v15<<32))))&0xffffffffffffffffULL))));
goto cn_break_b11;
}
cn_break_b10:;
(f[1]=f[1]);
(f[1]=cn_double(((((((v15>>32))|((v16<<32))))&0xffffffffffffffffULL))));
}
cn_break_b11:;
(r34=cn_bits(f[1]));
{
__auto_type cn_init_2472 = 0x0U; __auto_type bv = cn_init_2472;
__auto_type cn_init_2489 = (((uint32_t)(((((v18>>32))&0xffffffffULL))))); __auto_type av = cn_init_2489;
__auto_type cn_init_2507 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2507;
}
if(cn_cond(fl,5)){
goto cn_break_b13;
}
{
__auto_type cn_init_2531 = cn_double(v26); __auto_type v = cn_init_2531;
(f[0]=(f[0]/v));
}
}
cn_break_b13:;
(r14=cn_bits(f[0]));
{
__auto_type cn_init_2562 = 0x1cU; __auto_type bv = cn_init_2562;
__auto_type cn_init_2570 = rg[4]; __auto_type av = cn_init_2570;
__auto_type cn_init_2588 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2588;
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
int cn_f_778f7dea5adf2d48(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_428 = cn_cell(vm,104); uint64_t v35 = cn_init_428;
__auto_type cn_init_441 = cn_cell(vm,112); uint64_t v36 = cn_init_441;
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
__auto_type cn_init_725 = 0x80U; __auto_type bv = cn_init_725;
__auto_type cn_init_733 = rg[7]; __auto_type av = cn_init_733;
__auto_type cn_init_751 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_751;
(rg[7]=r);
}
(f[0]=cn_double(v27));
(f[1]=f[0]);
{
__auto_type cn_init_792 = cn_double(r3); __auto_type v = cn_init_792;
(f[1]=(f[1]*v));
}
(rg[0]=((uint32_t)(((((v22>>0))&0xffffffffULL)))));
{
__auto_type cn_init_828 = 0x1U; __auto_type bv = cn_init_828;
__auto_type cn_init_836 = rg[0]; __auto_type av = cn_init_836;
__auto_type cn_init_854 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_854;
(rg[0]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(f[1]=fabs(f[1]));
}
cn_break_b2:;
(r3=cn_bits(f[1]));
{
__auto_type cn_init_911 = cn_double(r4); __auto_type v = cn_init_911;
(f[0]=(f[0]*v));
}
(rg[0]=((uint32_t)(((((v22>>0))&0xffffffffULL)))));
{
__auto_type cn_init_947 = 0x2U; __auto_type bv = cn_init_947;
__auto_type cn_init_955 = rg[0]; __auto_type av = cn_init_955;
__auto_type cn_init_973 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_973;
(rg[0]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
(f[0]=fabs(f[0]));
}
cn_break_b4:;
(r4=cn_bits(f[0]));
{
__auto_type cn_init_1025 = 0x20U; __auto_type bv = cn_init_1025;
__auto_type cn_init_1033 = rg[4]; __auto_type av = cn_init_1033;
__auto_type cn_init_1051 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_1051;
(rg[4]=r);
}
(rg[0]=((uint32_t)(((((r3>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1082 = 0xfff00000U; __auto_type bv = cn_init_1082;
__auto_type cn_init_1090 = rg[0]; __auto_type av = cn_init_1090;
__auto_type cn_init_1108 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1108;
(rg[0]=r);
}
(s2015=(((s2015&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
(f[0]=cn_double(r3));
(f[1]=cn_double(v34));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b9;
}
(f[0]=cn_double(r3));
(f[1]=cn_double(v35));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b9;
}
(rg[0]=((uint32_t)(((((v22>>0))&0xffffffffULL)))));
{
__auto_type cn_init_1357 = 0x4U; __auto_type bv = cn_init_1357;
__auto_type cn_init_1365 = rg[0]; __auto_type av = cn_init_1365;
__auto_type cn_init_1383 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1383;
(rg[0]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[0]=cn_double(r3));
(f[1]=cn_double(v36));
(f[1]=(f[1]*f[0]));
(f[2]=f[0]);
(f[2]=fabs(f[2]));
(f[1]=(f[1]/f[2]));
(f[0]=(f[0]+f[1]));
(r3=cn_bits(f[0]));
(rg[0]=((uint32_t)(((((r3>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1530 = 0xfff00000U; __auto_type bv = cn_init_1530;
__auto_type cn_init_1538 = rg[0]; __auto_type av = cn_init_1538;
__auto_type cn_init_1556 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1556;
(rg[0]=r);
}
(s2015=(((s2015&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
}
cn_break_b8:;
{
__auto_type cn_init_1601 = 0xfffffU; __auto_type v = cn_init_1601;
(rg[0]=v);
}
{
__auto_type cn_init_1618 = rg[0]; __auto_type bv = cn_init_1618;
__auto_type cn_init_1635 = (((uint32_t)(((((r3>>32))&0xffffffffULL))))); __auto_type av = cn_init_1635;
__auto_type cn_init_1653 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1653;
(r3=(((r3&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_1689 = 0x3ff00000U; __auto_type v = cn_init_1689;
(rg[0]=v);
}
{
__auto_type cn_init_1706 = rg[0]; __auto_type bv = cn_init_1706;
__auto_type cn_init_1723 = (((uint32_t)(((((r3>>32))&0xffffffffULL))))); __auto_type av = cn_init_1723;
__auto_type cn_init_1741 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_1741;
(r3=(((r3&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
goto cn_break_b10;
}
cn_break_b9:;
(rg[0]=((uint32_t)(((((s2015>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1798 = 0x80000000U; __auto_type bv = cn_init_1798;
__auto_type cn_init_1806 = rg[0]; __auto_type av = cn_init_1806;
__auto_type cn_init_1824 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_1824;
(rg[0]=r);
}
{
__auto_type cn_init_1838 = 0x3ff00000U; __auto_type bv = cn_init_1838;
__auto_type cn_init_1846 = rg[0]; __auto_type av = cn_init_1846;
__auto_type cn_init_1864 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_1864;
(rg[0]=r);
}
(s2015=(((s2015&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
}
cn_break_b10:;
(f[0]=cn_double(r3));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1940 = cn_double(v32); __auto_type v = cn_init_1940;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
(f[0]=-f[0]);
{
__auto_type cn_init_1989 = cn_double(v33); __auto_type v = cn_init_1989;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
{
__auto_type cn_init_2019 = 0x0U; __auto_type v = cn_init_2019;
(rg[0]=v);
}
(s2015=(((s2015&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
(f[0]=cn_double(s2015));
{
__auto_type cn_init_2080 = cn_double(r3); __auto_type v = cn_init_2080;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(rg[0]=((uint32_t)(((((s2015>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2127 = 0x100000U; __auto_type bv = cn_init_2127;
__auto_type cn_init_2135 = rg[0]; __auto_type av = cn_init_2135;
__auto_type cn_init_2153 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2153;
(rg[0]=r);
}
cn_shift_reg_l(rg,&fl,Shift_Shl,0,11,4);
{
__auto_type cn_init_2191 = rg[0]; __auto_type bv = cn_init_2191;
__auto_type cn_init_2208 = (((uint32_t)(((((r3>>32))&0xffffffffULL))))); __auto_type av = cn_init_2208;
__auto_type cn_init_2226 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_2226;
(r3=(((r3&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
(rg[0]=((uint32_t)(((((r4>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2279 = 0xfff00000U; __auto_type bv = cn_init_2279;
__auto_type cn_init_2287 = rg[0]; __auto_type av = cn_init_2287;
__auto_type cn_init_2305 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2305;
(rg[0]=r);
}
(s2015=(((s2015&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
(f[0]=cn_double(r4));
(f[1]=cn_double(v34));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b15;
}
(f[0]=cn_double(r4));
(f[1]=cn_double(v35));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b15;
}
(rg[0]=((uint32_t)(((((v22>>0))&0xffffffffULL)))));
{
__auto_type cn_init_2554 = 0x8U; __auto_type bv = cn_init_2554;
__auto_type cn_init_2562 = rg[0]; __auto_type av = cn_init_2562;
__auto_type cn_init_2580 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2580;
(rg[0]=r);
}
if(cn_cond(fl,4)){
goto cn_break_b14;
}
(f[0]=cn_double(r4));
(f[1]=cn_double(v36));
(f[1]=(f[1]*f[0]));
(f[2]=f[0]);
(f[2]=fabs(f[2]));
(f[1]=(f[1]/f[2]));
(f[0]=(f[0]+f[1]));
(r4=cn_bits(f[0]));
(rg[0]=((uint32_t)(((((r4>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2727 = 0xfff00000U; __auto_type bv = cn_init_2727;
__auto_type cn_init_2735 = rg[0]; __auto_type av = cn_init_2735;
__auto_type cn_init_2753 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2753;
(rg[0]=r);
}
(s2015=(((s2015&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
}
cn_break_b14:;
{
__auto_type cn_init_2798 = 0xfffffU; __auto_type v = cn_init_2798;
(rg[0]=v);
}
{
__auto_type cn_init_2815 = rg[0]; __auto_type bv = cn_init_2815;
__auto_type cn_init_2832 = (((uint32_t)(((((r4>>32))&0xffffffffULL))))); __auto_type av = cn_init_2832;
__auto_type cn_init_2850 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_2850;
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_2886 = 0x3ff00000U; __auto_type v = cn_init_2886;
(rg[0]=v);
}
{
__auto_type cn_init_2903 = rg[0]; __auto_type bv = cn_init_2903;
__auto_type cn_init_2920 = (((uint32_t)(((((r4>>32))&0xffffffffULL))))); __auto_type av = cn_init_2920;
__auto_type cn_init_2938 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_2938;
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
goto cn_break_b16;
}
cn_break_b15:;
(rg[0]=((uint32_t)(((((s2015>>32))&0xffffffffULL)))));
{
__auto_type cn_init_2995 = 0x80000000U; __auto_type bv = cn_init_2995;
__auto_type cn_init_3003 = rg[0]; __auto_type av = cn_init_3003;
__auto_type cn_init_3021 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_3021;
(rg[0]=r);
}
{
__auto_type cn_init_3035 = 0x3ff00000U; __auto_type bv = cn_init_3035;
__auto_type cn_init_3043 = rg[0]; __auto_type av = cn_init_3043;
__auto_type cn_init_3061 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_3061;
(rg[0]=r);
}
(s2015=(((s2015&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<32))));
}
cn_break_b16:;
(f[0]=cn_double(r4));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_3137 = cn_double(v32); __auto_type v = cn_init_3137;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
(f[0]=-f[0]);
{
__auto_type cn_init_3186 = cn_double(v33); __auto_type v = cn_init_3186;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
{
__auto_type cn_init_3216 = 0x0U; __auto_type v = cn_init_3216;
(rg[0]=v);
}
(s2015=(((s2015&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[0])))&0xffffffffULL))<<0))));
(f[0]=cn_double(s2015));
{
__auto_type cn_init_3277 = cn_double(r4); __auto_type v = cn_init_3277;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(rg[0]=((uint32_t)(((((s2015>>32))&0xffffffffULL)))));
{
__auto_type cn_init_3324 = 0x100000U; __auto_type bv = cn_init_3324;
__auto_type cn_init_3332 = rg[0]; __auto_type av = cn_init_3332;
__auto_type cn_init_3350 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_3350;
(rg[0]=r);
}
cn_shift_reg_l(rg,&fl,Shift_Shl,0,11,4);
{
__auto_type cn_init_3388 = rg[0]; __auto_type bv = cn_init_3388;
__auto_type cn_init_3405 = (((uint32_t)(((((r4>>32))&0xffffffffULL))))); __auto_type av = cn_init_3405;
__auto_type cn_init_3423 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_3423;
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_3459 = 0xffffffe0U; __auto_type bv = cn_init_3459;
__auto_type cn_init_3467 = rg[4]; __auto_type av = cn_init_3467;
__auto_type cn_init_3485 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_3485;
(rg[4]=r);
}
(f[0]=cn_double(r3));
{
__auto_type cn_init_3516 = cn_double(v27); __auto_type v = cn_init_3516;
(f[0]=(f[0]/v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_3552 = cn_double(v27); __auto_type v = cn_init_3552;
(f[1]=(f[1]/v));
}
(f[2]=cn_double(r5));
(f[3]=f[2]);
{
__auto_type cn_init_3612 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3612;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_3660 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3660;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_3723 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3723;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_3786 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3786;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_3834 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3834;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_3897 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3897;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_3959 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3959;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_4006 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_4006;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_4068 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_4068;
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
goto cn_break_b18;
}
(f[3]=f[3]);
(f[3]=cn_double(v29));
goto cn_break_b21;
}
cn_break_b18:;
(f[4]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b20;
}
(f[4]=f[4]);
{
__auto_type cn_init_4402 = cn_double(v30); __auto_type v = cn_init_4402;
(f[3]=(v/f[3]));
}
goto cn_break_b21;
}
cn_break_b20:;
(fsw=cn_compare(f[4],f[3]));
(f[3]=cn_double(v30));
}
cn_break_b21:;
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[3]));
(r6=cn_bits(f[4]));
(f[0]=(f[0]*f[3]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
{
__auto_type cn_init_4541 = cn_double(r12); __auto_type v = cn_init_4541;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
{
__auto_type cn_init_4576 = cn_double(r11); __auto_type v = cn_init_4576;
(f[1]=(f[1]+v));
}
(r4=cn_bits(f[1]));
{
__auto_type cn_init_4611 = cn_double(r10); __auto_type v = cn_init_4611;
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
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
cn_wr64u(m,0x10007ef8U,s2015);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_7802538289b5cfe3(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
(f[0]=cn_double(s2009));
{
__auto_type cn_init_1430 = cn_double(s2012); __auto_type v = cn_init_1430;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1454 = cn_double(r10); __auto_type v = cn_init_1454;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_1501 = cn_double(s2007); __auto_type v = cn_init_1501;
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
(f[0]=cn_double(s2010));
{
__auto_type cn_init_1596 = cn_double(s2008); __auto_type v = cn_init_1596;
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
int cn_f_7820bdda2a825c7e(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

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
__auto_type cn_init_598 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_598;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_646 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_646;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_709 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_709;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_772 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_772;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_820 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_820;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_883 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_883;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_945 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_945;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_992 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_992;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1054 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1054;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1109 = cn_double(((((((v25>>32))|((v26<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1109;
(f[2]=(f[2]+v));
}
(f[2]=fabs(f[2]));
{
__auto_type cn_init_1163 = cn_double(((((((v24>>32))|((v25<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1163;
(f[2]=(f[2]-v));
}
(f[3]=f[2]);
{
__auto_type cn_init_1211 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1211;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1259 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1259;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1322 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1322;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1385 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1385;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1433 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1433;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1496 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1496;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1558 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1558;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1605 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1605;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1667 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1667;
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
int cn_f_789b0e6fa175e144(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+200))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(4)); uint64_t r4 = cn_init_88;
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
(f[0]=cn_double(r4));
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
{
__auto_type cn_init_423 = (((uint32_t)(((((r4>>56))&0xffULL))))); __auto_type v = cn_init_423;
cn_reg_set(rg,1,1,v);
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
(f[1]=cn_double(r4));
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
__auto_type cn_init_686 = cn_reg_get(rg,1,1); __auto_type av = cn_init_686;
__auto_type cn_init_704 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_704;
cn_reg_set(rg,1,1,r);
}
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[2]/f[1]));
(f[1]=-f[1]);
{
__auto_type cn_init_767 = cn_double(v27); __auto_type v = cn_init_767;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]+f[1]));
(r4=cn_bits(f[0]));
{
__auto_type cn_init_820 = cn_reg_get(rg,1,1); __auto_type bv = cn_init_820;
__auto_type cn_init_837 = (((uint32_t)(((((r4>>56))&0xffULL))))); __auto_type av = cn_init_837;
__auto_type cn_init_855 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_855;
(r4=(((r4&~((0xffULL<<56))))|(((((((uint64_t)((r))))&0xffULL))<<56))));
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
cn_wr64(m,CN_REC+8*(4),r4);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
int cn_f_7a40fec6e4674f50(CN_Machine *m, CN_U8 *regs, uint32_t pvar) { CN_U8 cn_initial_regs=*regs; uint64_t max_steps=2000000;

__auto_type cn_init_16 = (CN_D8){0}; __auto_type f = cn_init_16;
__auto_type cn_init_25 = (*regs); __auto_type rg = cn_init_25;
__auto_type cn_init_35 = (CN_Flags){0}; __auto_type fl = cn_init_35;
__auto_type cn_init_41 = 0U; __auto_type fsw = cn_init_41;
__auto_type cn_init_51 = ((uint32_t)(pvar-256)); __auto_type vb = cn_init_51;
__auto_type cn_init_71 = cn_ptr(m,((uint32_t)(vb+200))); unsigned char * vm = cn_init_71;
__auto_type cn_init_88 = cn_rd64(m,CN_REC+8*(10)); uint64_t r10 = cn_init_88;
__auto_type cn_init_105 = cn_rd64(m,CN_REC+8*(11)); uint64_t r11 = cn_init_105;
__auto_type cn_init_122 = cn_rd64(m,CN_REC+8*(12)); uint64_t r12 = cn_init_122;
__auto_type cn_init_139 = cn_rd64(m,CN_REC+8*(13)); uint64_t r13 = cn_init_139;
__auto_type cn_init_152 = cn_rd64u(m,0x10007ed0U); uint64_t s2010 = cn_init_152;
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
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[1])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
{
__auto_type cn_init_1025 = 0x18U; __auto_type bv = cn_init_1025;
__auto_type cn_init_1033 = rg[6]; __auto_type av = cn_init_1033;
__auto_type cn_init_1051 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_1051;
(rg[6]=r);
}
(m->xmm[6]=(CN_U2){v32,v33});
(m->xmm[0]=(CN_U2){r10,r11});
{
__auto_type cn_init_1093 = r12; uint64_t s = cn_init_1093;
(m->xmm[1]=(CN_U2){s,0});
}
(m->xmm[3]=m->xmm[0]);
(m->xmm[5][0]=m->xmm[1][0]);
{
__auto_type cn_init_1158 = m->xmm[3]; CN_U2 s = cn_init_1158;
__auto_type cn_init_1168 = m->xmm[3]; __auto_type a = cn_init_1168;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_1246 = m->xmm[5][0]; uint64_t s = cn_init_1246;
__auto_type cn_init_1259 = m->xmm[5][0]; __auto_type a = cn_init_1259;
(m->xmm[5][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_1307 = m->xmm[3]; CN_U2 s = cn_init_1307;
__auto_type cn_init_1317 = m->xmm[3]; __auto_type a = cn_init_1317;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_1395 = m->xmm[3][0]; uint64_t s = cn_init_1395;
__auto_type cn_init_1408 = m->xmm[5][0]; __auto_type a = cn_init_1408;
(m->xmm[5][0]=cn_bits(((cn_double(a)+cn_double(s)))));
}
{
__auto_type cn_init_1447 = v34; uint64_t s = cn_init_1447;
(m->xmm[2]=(CN_U2){s,0});
}
{
__auto_type cn_init_1477 = m->xmm[5][0]; uint64_t s = cn_init_1477;
(m->xmm[5][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_1519 = m->xmm[5][0]; uint64_t s = cn_init_1519;
__auto_type cn_init_1532 = m->xmm[2][0]; __auto_type a = cn_init_1532;
(m->xmm[2][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_1580 = m->xmm[2]; CN_U2 s = cn_init_1580;
(m->xmm[2][1]=s[0]);
}
{
__auto_type cn_init_1613 = m->xmm[2]; CN_U2 s = cn_init_1613;
__auto_type cn_init_1623 = m->xmm[0]; __auto_type a = cn_init_1623;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_1701 = m->xmm[2][0]; uint64_t s = cn_init_1701;
__auto_type cn_init_1714 = m->xmm[1][0]; __auto_type a = cn_init_1714;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_1751 = 0x0U; __auto_type bv = cn_init_1751;
__auto_type cn_init_1768 = (((uint32_t)(((((v30>>32))&0xffffffffULL))))); __auto_type av = cn_init_1768;
__auto_type cn_init_1786 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1786;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
{
__auto_type cn_init_1816 = m->xmm[0]; CN_U2 s = cn_init_1816;
__auto_type cn_init_1826 = m->xmm[0]; __auto_type a = cn_init_1826;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b2:;
(r11=m->xmm[5][0]);
(rg[2]=((uint32_t)(((((v30>>0))&0xffffffffULL)))));
(rg[3]=((uint32_t)(((((v29>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008069U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_1946 = rg[1]; __auto_type bv = cn_init_1946;
__auto_type cn_init_1954 = rg[1]; __auto_type av = cn_init_1954;
__auto_type cn_init_1972 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_1972;
(rg[1]=r);
}
{
__auto_type cn_init_1986 = 0x6U; __auto_type bv = cn_init_1986;
__auto_type cn_init_1994 = rg[3]; __auto_type av = cn_init_1994;
__auto_type cn_init_2012 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2012;
}
if(cn_cond(fl,12)){
goto cn_break_b14;
}
{
__auto_type cn_init_2031 = 0x1U; __auto_type bv = cn_init_2031;
__auto_type cn_init_2039 = rg[1]; __auto_type av = cn_init_2039;
__auto_type cn_init_2057 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_2057;
(rg[1]=r);
}
{
__auto_type cn_init_2071 = 0x6U; __auto_type bv = cn_init_2071;
__auto_type cn_init_2079 = rg[3]; __auto_type av = cn_init_2079;
__auto_type cn_init_2097 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_2097;
(rg[3]=r);
}
}
cn_break_b14:;
{
__auto_type cn_init_2112 = 0x1U; __auto_type bv = cn_init_2112;
__auto_type cn_init_2120 = rg[3]; __auto_type av = cn_init_2120;
__auto_type cn_init_2138 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_2138;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b23;
}
(m->xmm[3]=m->xmm[0]);
{
__auto_type cn_init_2189 = m->xmm[3]; CN_U2 s = cn_init_2189;
__auto_type cn_init_2199 = m->xmm[3]; __auto_type a = cn_init_2199;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_2278 = m->xmm[3]; CN_U2 s = cn_init_2278;
__auto_type cn_init_2288 = m->xmm[3]; __auto_type a = cn_init_2288;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_2366 = m->xmm[3][0]; uint64_t s = cn_init_2366;
(m->xmm[5][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_2400 = v34; uint64_t s = cn_init_2400;
(m->xmm[4]=(CN_U2){s,0});
}
{
__auto_type cn_init_2430 = m->xmm[5][0]; uint64_t s = cn_init_2430;
__auto_type cn_init_2443 = m->xmm[4][0]; __auto_type a = cn_init_2443;
(m->xmm[4][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_2491 = m->xmm[4]; CN_U2 s = cn_init_2491;
(m->xmm[4][1]=s[0]);
}
{
__auto_type cn_init_2524 = m->xmm[5]; CN_U2 s = cn_init_2524;
(m->xmm[5][1]=s[0]);
}
(r10=m->xmm[1][0]);
{
__auto_type cn_init_2569 = m->xmm[4]; CN_U2 s = cn_init_2569;
__auto_type cn_init_2579 = m->xmm[0]; __auto_type a = cn_init_2579;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100080f2U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_2691 = 0x0U; __auto_type bv = cn_init_2691;
__auto_type cn_init_2699 = rg[1]; __auto_type av = cn_init_2699;
__auto_type cn_init_2717 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2717;
}
if(cn_cond(fl,4)){
goto cn_break_b101;
}
{
__auto_type cn_init_2747 = m->xmm[0]; CN_U2 s = cn_init_2747;
__auto_type cn_init_2757 = m->xmm[0]; __auto_type a = cn_init_2757;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b101:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_2853 = m->xmm[0]; CN_U2 s = cn_init_2853;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_2941 = m->xmm[1]; CN_U2 s = cn_init_2941;
__auto_type cn_init_2951 = m->xmm[0]; __auto_type a = cn_init_2951;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_3030 = m->xmm[1]; CN_U2 s = cn_init_3030;
__auto_type cn_init_3040 = m->xmm[2]; __auto_type a = cn_init_3040;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_3119 = m->xmm[6]; CN_U2 s = cn_init_3119;
__auto_type cn_init_3129 = m->xmm[0]; __auto_type a = cn_init_3129;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_3176 = m->xmm[2]; CN_U2 s = cn_init_3176;
__auto_type cn_init_3186 = m->xmm[0]; __auto_type a = cn_init_3186;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_3269 = 0x2U; __auto_type bv = cn_init_3269;
__auto_type cn_init_3277 = rg[2]; __auto_type av = cn_init_3277;
__auto_type cn_init_3295 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3295;
}
if(cn_cond(fl,14)){
goto cn_break_b317;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_3328 = 0x4U; __auto_type bv = cn_init_3328;
__auto_type cn_init_3336 = rg[2]; __auto_type av = cn_init_3336;
__auto_type cn_init_3354 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3354;
}
if(cn_cond(fl,12)){
goto cn_break_b281;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_3456 = m->xmm[0]; CN_U2 s = cn_init_3456;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_3544 = m->xmm[1]; CN_U2 s = cn_init_3544;
__auto_type cn_init_3554 = m->xmm[0]; __auto_type a = cn_init_3554;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_3633 = m->xmm[1]; CN_U2 s = cn_init_3633;
__auto_type cn_init_3643 = m->xmm[2]; __auto_type a = cn_init_3643;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_3722 = m->xmm[6]; CN_U2 s = cn_init_3722;
__auto_type cn_init_3732 = m->xmm[0]; __auto_type a = cn_init_3732;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_3779 = m->xmm[2]; CN_U2 s = cn_init_3779;
__auto_type cn_init_3789 = m->xmm[0]; __auto_type a = cn_init_3789;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_3872 = 0x8U; __auto_type bv = cn_init_3872;
__auto_type cn_init_3880 = rg[2]; __auto_type av = cn_init_3880;
__auto_type cn_init_3898 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_3898;
}
if(cn_cond(fl,12)){
goto cn_break_b245;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_3986 = m->xmm[0]; CN_U2 s = cn_init_3986;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_4074 = m->xmm[1]; CN_U2 s = cn_init_4074;
__auto_type cn_init_4084 = m->xmm[0]; __auto_type a = cn_init_4084;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_4163 = m->xmm[1]; CN_U2 s = cn_init_4163;
__auto_type cn_init_4173 = m->xmm[2]; __auto_type a = cn_init_4173;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_4252 = m->xmm[6]; CN_U2 s = cn_init_4252;
__auto_type cn_init_4262 = m->xmm[0]; __auto_type a = cn_init_4262;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_4309 = m->xmm[2]; CN_U2 s = cn_init_4309;
__auto_type cn_init_4319 = m->xmm[0]; __auto_type a = cn_init_4319;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_4402 = 0xaU; __auto_type bv = cn_init_4402;
__auto_type cn_init_4410 = rg[2]; __auto_type av = cn_init_4410;
__auto_type cn_init_4428 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_4428;
}
if(cn_cond(fl,12)){
goto cn_break_b281;
}
goto cn_break_b263;
}
cn_break_b245:;
{
__auto_type cn_init_4451 = 0x6U; __auto_type bv = cn_init_4451;
__auto_type cn_init_4459 = rg[2]; __auto_type av = cn_init_4459;
__auto_type cn_init_4477 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_4477;
}
if(cn_cond(fl,12)){
goto cn_break_b281;
}
}
cn_break_b263:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_4566 = m->xmm[0]; CN_U2 s = cn_init_4566;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_4654 = m->xmm[1]; CN_U2 s = cn_init_4654;
__auto_type cn_init_4664 = m->xmm[0]; __auto_type a = cn_init_4664;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_4743 = m->xmm[1]; CN_U2 s = cn_init_4743;
__auto_type cn_init_4753 = m->xmm[2]; __auto_type a = cn_init_4753;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_4832 = m->xmm[6]; CN_U2 s = cn_init_4832;
__auto_type cn_init_4842 = m->xmm[0]; __auto_type a = cn_init_4842;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_4889 = m->xmm[2]; CN_U2 s = cn_init_4889;
__auto_type cn_init_4899 = m->xmm[0]; __auto_type a = cn_init_4899;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b281:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b317;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_5085 = m->xmm[0]; CN_U2 s = cn_init_5085;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_5173 = m->xmm[1]; CN_U2 s = cn_init_5173;
__auto_type cn_init_5183 = m->xmm[0]; __auto_type a = cn_init_5183;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_5262 = m->xmm[1]; CN_U2 s = cn_init_5262;
__auto_type cn_init_5272 = m->xmm[2]; __auto_type a = cn_init_5272;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_5351 = m->xmm[6]; CN_U2 s = cn_init_5351;
__auto_type cn_init_5361 = m->xmm[0]; __auto_type a = cn_init_5361;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_5408 = m->xmm[2]; CN_U2 s = cn_init_5408;
__auto_type cn_init_5418 = m->xmm[0]; __auto_type a = cn_init_5418;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b317:;
{
__auto_type cn_init_5502 = 0x0U; __auto_type bv = cn_init_5502;
__auto_type cn_init_5510 = rg[1]; __auto_type av = cn_init_5510;
__auto_type cn_init_5528 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_5528;
}
if(cn_cond(fl,4)){
goto cn_break_b353;
}
{
__auto_type cn_init_5558 = m->xmm[0]; CN_U2 s = cn_init_5558;
__auto_type cn_init_5568 = m->xmm[0]; __auto_type a = cn_init_5568;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b353:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_5612 = r10; uint64_t s = cn_init_5612;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_5643 = m->xmm[5]; CN_U2 s = cn_init_5643;
__auto_type cn_init_5653 = m->xmm[0]; __auto_type a = cn_init_5653;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b3;
}
cn_break_b23:;
{
__auto_type cn_init_5740 = 0x1U; __auto_type bv = cn_init_5740;
__auto_type cn_init_5748 = rg[3]; __auto_type av = cn_init_5748;
__auto_type cn_init_5766 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_5766;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b32;
}
(r10=m->xmm[0][1]);
{
__auto_type cn_init_5815 = m->xmm[1]; CN_U2 s = cn_init_5815;
(m->xmm[0][1]=s[0]);
}
(m->xmm[3]=m->xmm[0]);
{
__auto_type cn_init_5862 = m->xmm[3]; CN_U2 s = cn_init_5862;
__auto_type cn_init_5872 = m->xmm[3]; __auto_type a = cn_init_5872;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_5951 = m->xmm[3]; CN_U2 s = cn_init_5951;
__auto_type cn_init_5961 = m->xmm[3]; __auto_type a = cn_init_5961;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_6039 = m->xmm[3][0]; uint64_t s = cn_init_6039;
(m->xmm[5][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_6073 = v34; uint64_t s = cn_init_6073;
(m->xmm[4]=(CN_U2){s,0});
}
{
__auto_type cn_init_6103 = m->xmm[5][0]; uint64_t s = cn_init_6103;
__auto_type cn_init_6116 = m->xmm[4][0]; __auto_type a = cn_init_6116;
(m->xmm[4][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_6164 = m->xmm[4]; CN_U2 s = cn_init_6164;
(m->xmm[4][1]=s[0]);
}
{
__auto_type cn_init_6197 = m->xmm[5]; CN_U2 s = cn_init_6197;
(m->xmm[5][1]=s[0]);
}
{
__auto_type cn_init_6230 = m->xmm[4]; CN_U2 s = cn_init_6230;
__auto_type cn_init_6240 = m->xmm[0]; __auto_type a = cn_init_6240;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008132U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_6352 = 0x0U; __auto_type bv = cn_init_6352;
__auto_type cn_init_6360 = rg[1]; __auto_type av = cn_init_6360;
__auto_type cn_init_6378 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_6378;
}
if(cn_cond(fl,4)){
goto cn_break_b102;
}
{
__auto_type cn_init_6408 = m->xmm[0]; CN_U2 s = cn_init_6408;
__auto_type cn_init_6418 = m->xmm[0]; __auto_type a = cn_init_6418;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b102:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_6514 = m->xmm[0]; CN_U2 s = cn_init_6514;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_6602 = m->xmm[1]; CN_U2 s = cn_init_6602;
__auto_type cn_init_6612 = m->xmm[0]; __auto_type a = cn_init_6612;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_6691 = m->xmm[1]; CN_U2 s = cn_init_6691;
__auto_type cn_init_6701 = m->xmm[2]; __auto_type a = cn_init_6701;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_6780 = m->xmm[6]; CN_U2 s = cn_init_6780;
__auto_type cn_init_6790 = m->xmm[0]; __auto_type a = cn_init_6790;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_6837 = m->xmm[2]; CN_U2 s = cn_init_6837;
__auto_type cn_init_6847 = m->xmm[0]; __auto_type a = cn_init_6847;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_6930 = 0x2U; __auto_type bv = cn_init_6930;
__auto_type cn_init_6938 = rg[2]; __auto_type av = cn_init_6938;
__auto_type cn_init_6956 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_6956;
}
if(cn_cond(fl,14)){
goto cn_break_b318;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_6989 = 0x4U; __auto_type bv = cn_init_6989;
__auto_type cn_init_6997 = rg[2]; __auto_type av = cn_init_6997;
__auto_type cn_init_7015 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_7015;
}
if(cn_cond(fl,12)){
goto cn_break_b282;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_7117 = m->xmm[0]; CN_U2 s = cn_init_7117;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_7205 = m->xmm[1]; CN_U2 s = cn_init_7205;
__auto_type cn_init_7215 = m->xmm[0]; __auto_type a = cn_init_7215;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_7294 = m->xmm[1]; CN_U2 s = cn_init_7294;
__auto_type cn_init_7304 = m->xmm[2]; __auto_type a = cn_init_7304;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_7383 = m->xmm[6]; CN_U2 s = cn_init_7383;
__auto_type cn_init_7393 = m->xmm[0]; __auto_type a = cn_init_7393;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_7440 = m->xmm[2]; CN_U2 s = cn_init_7440;
__auto_type cn_init_7450 = m->xmm[0]; __auto_type a = cn_init_7450;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_7533 = 0x8U; __auto_type bv = cn_init_7533;
__auto_type cn_init_7541 = rg[2]; __auto_type av = cn_init_7541;
__auto_type cn_init_7559 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_7559;
}
if(cn_cond(fl,12)){
goto cn_break_b246;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_7647 = m->xmm[0]; CN_U2 s = cn_init_7647;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_7735 = m->xmm[1]; CN_U2 s = cn_init_7735;
__auto_type cn_init_7745 = m->xmm[0]; __auto_type a = cn_init_7745;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_7824 = m->xmm[1]; CN_U2 s = cn_init_7824;
__auto_type cn_init_7834 = m->xmm[2]; __auto_type a = cn_init_7834;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_7913 = m->xmm[6]; CN_U2 s = cn_init_7913;
__auto_type cn_init_7923 = m->xmm[0]; __auto_type a = cn_init_7923;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_7970 = m->xmm[2]; CN_U2 s = cn_init_7970;
__auto_type cn_init_7980 = m->xmm[0]; __auto_type a = cn_init_7980;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_8063 = 0xaU; __auto_type bv = cn_init_8063;
__auto_type cn_init_8071 = rg[2]; __auto_type av = cn_init_8071;
__auto_type cn_init_8089 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_8089;
}
if(cn_cond(fl,12)){
goto cn_break_b282;
}
goto cn_break_b264;
}
cn_break_b246:;
{
__auto_type cn_init_8112 = 0x6U; __auto_type bv = cn_init_8112;
__auto_type cn_init_8120 = rg[2]; __auto_type av = cn_init_8120;
__auto_type cn_init_8138 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_8138;
}
if(cn_cond(fl,12)){
goto cn_break_b282;
}
}
cn_break_b264:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_8227 = m->xmm[0]; CN_U2 s = cn_init_8227;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_8315 = m->xmm[1]; CN_U2 s = cn_init_8315;
__auto_type cn_init_8325 = m->xmm[0]; __auto_type a = cn_init_8325;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_8404 = m->xmm[1]; CN_U2 s = cn_init_8404;
__auto_type cn_init_8414 = m->xmm[2]; __auto_type a = cn_init_8414;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_8493 = m->xmm[6]; CN_U2 s = cn_init_8493;
__auto_type cn_init_8503 = m->xmm[0]; __auto_type a = cn_init_8503;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_8550 = m->xmm[2]; CN_U2 s = cn_init_8550;
__auto_type cn_init_8560 = m->xmm[0]; __auto_type a = cn_init_8560;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b282:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b318;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_8746 = m->xmm[0]; CN_U2 s = cn_init_8746;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_8834 = m->xmm[1]; CN_U2 s = cn_init_8834;
__auto_type cn_init_8844 = m->xmm[0]; __auto_type a = cn_init_8844;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_8923 = m->xmm[1]; CN_U2 s = cn_init_8923;
__auto_type cn_init_8933 = m->xmm[2]; __auto_type a = cn_init_8933;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_9012 = m->xmm[6]; CN_U2 s = cn_init_9012;
__auto_type cn_init_9022 = m->xmm[0]; __auto_type a = cn_init_9022;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_9069 = m->xmm[2]; CN_U2 s = cn_init_9069;
__auto_type cn_init_9079 = m->xmm[0]; __auto_type a = cn_init_9079;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b318:;
{
__auto_type cn_init_9163 = 0x0U; __auto_type bv = cn_init_9163;
__auto_type cn_init_9171 = rg[1]; __auto_type av = cn_init_9171;
__auto_type cn_init_9189 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_9189;
}
if(cn_cond(fl,4)){
goto cn_break_b354;
}
{
__auto_type cn_init_9219 = m->xmm[0]; CN_U2 s = cn_init_9219;
__auto_type cn_init_9229 = m->xmm[0]; __auto_type a = cn_init_9229;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b354:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_9282 = m->xmm[5]; CN_U2 s = cn_init_9282;
__auto_type cn_init_9292 = m->xmm[0]; __auto_type a = cn_init_9292;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_9371 = m->xmm[0]; CN_U2 s = cn_init_9371;

(m->xmm[1]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_9450 = r10; uint64_t s = cn_init_9450;
(m->xmm[0][1]=s);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b3;
}
cn_break_b32:;
{
__auto_type cn_init_9488 = 0x1U; __auto_type bv = cn_init_9488;
__auto_type cn_init_9496 = rg[3]; __auto_type av = cn_init_9496;
__auto_type cn_init_9514 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_9514;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b41;
}
(r10=m->xmm[0][0]);
{
__auto_type cn_init_9563 = m->xmm[0]; CN_U2 s = cn_init_9563;
__auto_type cn_init_9573 = m->xmm[0]; __auto_type a = cn_init_9573;
(m->xmm[0]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_9610 = m->xmm[1]; CN_U2 s = cn_init_9610;
(m->xmm[0][1]=s[0]);
}
(m->xmm[3]=m->xmm[0]);
{
__auto_type cn_init_9657 = m->xmm[3]; CN_U2 s = cn_init_9657;
__auto_type cn_init_9667 = m->xmm[3]; __auto_type a = cn_init_9667;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_9746 = m->xmm[3]; CN_U2 s = cn_init_9746;
__auto_type cn_init_9756 = m->xmm[3]; __auto_type a = cn_init_9756;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_9834 = m->xmm[3][0]; uint64_t s = cn_init_9834;
(m->xmm[5][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_9868 = v34; uint64_t s = cn_init_9868;
(m->xmm[4]=(CN_U2){s,0});
}
{
__auto_type cn_init_9898 = m->xmm[5][0]; uint64_t s = cn_init_9898;
__auto_type cn_init_9911 = m->xmm[4][0]; __auto_type a = cn_init_9911;
(m->xmm[4][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_9959 = m->xmm[4]; CN_U2 s = cn_init_9959;
(m->xmm[4][1]=s[0]);
}
{
__auto_type cn_init_9992 = m->xmm[5]; CN_U2 s = cn_init_9992;
(m->xmm[5][1]=s[0]);
}
{
__auto_type cn_init_10025 = m->xmm[4]; CN_U2 s = cn_init_10025;
__auto_type cn_init_10035 = m->xmm[0]; __auto_type a = cn_init_10035;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x1000817bU))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_10147 = 0x0U; __auto_type bv = cn_init_10147;
__auto_type cn_init_10155 = rg[1]; __auto_type av = cn_init_10155;
__auto_type cn_init_10173 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_10173;
}
if(cn_cond(fl,4)){
goto cn_break_b103;
}
{
__auto_type cn_init_10203 = m->xmm[0]; CN_U2 s = cn_init_10203;
__auto_type cn_init_10213 = m->xmm[0]; __auto_type a = cn_init_10213;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b103:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_10309 = m->xmm[0]; CN_U2 s = cn_init_10309;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_10397 = m->xmm[1]; CN_U2 s = cn_init_10397;
__auto_type cn_init_10407 = m->xmm[0]; __auto_type a = cn_init_10407;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_10486 = m->xmm[1]; CN_U2 s = cn_init_10486;
__auto_type cn_init_10496 = m->xmm[2]; __auto_type a = cn_init_10496;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_10575 = m->xmm[6]; CN_U2 s = cn_init_10575;
__auto_type cn_init_10585 = m->xmm[0]; __auto_type a = cn_init_10585;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_10632 = m->xmm[2]; CN_U2 s = cn_init_10632;
__auto_type cn_init_10642 = m->xmm[0]; __auto_type a = cn_init_10642;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_10725 = 0x2U; __auto_type bv = cn_init_10725;
__auto_type cn_init_10733 = rg[2]; __auto_type av = cn_init_10733;
__auto_type cn_init_10751 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_10751;
}
if(cn_cond(fl,14)){
goto cn_break_b319;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_10784 = 0x4U; __auto_type bv = cn_init_10784;
__auto_type cn_init_10792 = rg[2]; __auto_type av = cn_init_10792;
__auto_type cn_init_10810 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_10810;
}
if(cn_cond(fl,12)){
goto cn_break_b283;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_10912 = m->xmm[0]; CN_U2 s = cn_init_10912;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_11000 = m->xmm[1]; CN_U2 s = cn_init_11000;
__auto_type cn_init_11010 = m->xmm[0]; __auto_type a = cn_init_11010;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_11089 = m->xmm[1]; CN_U2 s = cn_init_11089;
__auto_type cn_init_11099 = m->xmm[2]; __auto_type a = cn_init_11099;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_11178 = m->xmm[6]; CN_U2 s = cn_init_11178;
__auto_type cn_init_11188 = m->xmm[0]; __auto_type a = cn_init_11188;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_11235 = m->xmm[2]; CN_U2 s = cn_init_11235;
__auto_type cn_init_11245 = m->xmm[0]; __auto_type a = cn_init_11245;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_11328 = 0x8U; __auto_type bv = cn_init_11328;
__auto_type cn_init_11336 = rg[2]; __auto_type av = cn_init_11336;
__auto_type cn_init_11354 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_11354;
}
if(cn_cond(fl,12)){
goto cn_break_b247;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_11442 = m->xmm[0]; CN_U2 s = cn_init_11442;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_11530 = m->xmm[1]; CN_U2 s = cn_init_11530;
__auto_type cn_init_11540 = m->xmm[0]; __auto_type a = cn_init_11540;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_11619 = m->xmm[1]; CN_U2 s = cn_init_11619;
__auto_type cn_init_11629 = m->xmm[2]; __auto_type a = cn_init_11629;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_11708 = m->xmm[6]; CN_U2 s = cn_init_11708;
__auto_type cn_init_11718 = m->xmm[0]; __auto_type a = cn_init_11718;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_11765 = m->xmm[2]; CN_U2 s = cn_init_11765;
__auto_type cn_init_11775 = m->xmm[0]; __auto_type a = cn_init_11775;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_11858 = 0xaU; __auto_type bv = cn_init_11858;
__auto_type cn_init_11866 = rg[2]; __auto_type av = cn_init_11866;
__auto_type cn_init_11884 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_11884;
}
if(cn_cond(fl,12)){
goto cn_break_b283;
}
goto cn_break_b265;
}
cn_break_b247:;
{
__auto_type cn_init_11907 = 0x6U; __auto_type bv = cn_init_11907;
__auto_type cn_init_11915 = rg[2]; __auto_type av = cn_init_11915;
__auto_type cn_init_11933 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_11933;
}
if(cn_cond(fl,12)){
goto cn_break_b283;
}
}
cn_break_b265:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_12022 = m->xmm[0]; CN_U2 s = cn_init_12022;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_12110 = m->xmm[1]; CN_U2 s = cn_init_12110;
__auto_type cn_init_12120 = m->xmm[0]; __auto_type a = cn_init_12120;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_12199 = m->xmm[1]; CN_U2 s = cn_init_12199;
__auto_type cn_init_12209 = m->xmm[2]; __auto_type a = cn_init_12209;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_12288 = m->xmm[6]; CN_U2 s = cn_init_12288;
__auto_type cn_init_12298 = m->xmm[0]; __auto_type a = cn_init_12298;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_12345 = m->xmm[2]; CN_U2 s = cn_init_12345;
__auto_type cn_init_12355 = m->xmm[0]; __auto_type a = cn_init_12355;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b283:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b319;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_12541 = m->xmm[0]; CN_U2 s = cn_init_12541;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_12629 = m->xmm[1]; CN_U2 s = cn_init_12629;
__auto_type cn_init_12639 = m->xmm[0]; __auto_type a = cn_init_12639;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_12718 = m->xmm[1]; CN_U2 s = cn_init_12718;
__auto_type cn_init_12728 = m->xmm[2]; __auto_type a = cn_init_12728;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_12807 = m->xmm[6]; CN_U2 s = cn_init_12807;
__auto_type cn_init_12817 = m->xmm[0]; __auto_type a = cn_init_12817;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_12864 = m->xmm[2]; CN_U2 s = cn_init_12864;
__auto_type cn_init_12874 = m->xmm[0]; __auto_type a = cn_init_12874;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b319:;
{
__auto_type cn_init_12958 = 0x0U; __auto_type bv = cn_init_12958;
__auto_type cn_init_12966 = rg[1]; __auto_type av = cn_init_12966;
__auto_type cn_init_12984 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_12984;
}
if(cn_cond(fl,4)){
goto cn_break_b355;
}
{
__auto_type cn_init_13014 = m->xmm[0]; CN_U2 s = cn_init_13014;
__auto_type cn_init_13024 = m->xmm[0]; __auto_type a = cn_init_13024;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b355:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_13077 = m->xmm[5]; CN_U2 s = cn_init_13077;
__auto_type cn_init_13087 = m->xmm[0]; __auto_type a = cn_init_13087;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_13166 = m->xmm[0]; CN_U2 s = cn_init_13166;

(m->xmm[1]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_13254 = m->xmm[0]; CN_U2 s = cn_init_13254;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_13278 = r10; uint64_t s = cn_init_13278;
(m->xmm[0][0]=s);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b3;
}
cn_break_b41:;
{
__auto_type cn_init_13316 = 0x1U; __auto_type bv = cn_init_13316;
__auto_type cn_init_13324 = rg[3]; __auto_type av = cn_init_13324;
__auto_type cn_init_13342 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_13342;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b50;
}
(m->xmm[5]=m->xmm[0]);
{
__auto_type cn_init_13393 = m->xmm[0]; CN_U2 s = cn_init_13393;
__auto_type cn_init_13403 = m->xmm[0]; __auto_type a = cn_init_13403;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_13482 = m->xmm[0]; CN_U2 s = cn_init_13482;
__auto_type cn_init_13492 = m->xmm[0]; __auto_type a = cn_init_13492;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_13570 = m->xmm[0][0]; uint64_t s = cn_init_13570;
(m->xmm[0][0]=cn_bits(sqrt(cn_double(s))));
}
(r10=m->xmm[0][0]);
{
__auto_type cn_init_13625 = m->xmm[1]; CN_U2 s = cn_init_13625;
(m->xmm[0][1]=s[0]);
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100081afU))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_13691 = 0x0U; __auto_type bv = cn_init_13691;
__auto_type cn_init_13699 = rg[1]; __auto_type av = cn_init_13699;
__auto_type cn_init_13717 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_13717;
}
if(cn_cond(fl,4)){
goto cn_break_b104;
}
{
__auto_type cn_init_13747 = m->xmm[0]; CN_U2 s = cn_init_13747;
__auto_type cn_init_13757 = m->xmm[0]; __auto_type a = cn_init_13757;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b104:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_13853 = m->xmm[0]; CN_U2 s = cn_init_13853;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_13941 = m->xmm[1]; CN_U2 s = cn_init_13941;
__auto_type cn_init_13951 = m->xmm[0]; __auto_type a = cn_init_13951;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_14030 = m->xmm[1]; CN_U2 s = cn_init_14030;
__auto_type cn_init_14040 = m->xmm[2]; __auto_type a = cn_init_14040;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_14119 = m->xmm[6]; CN_U2 s = cn_init_14119;
__auto_type cn_init_14129 = m->xmm[0]; __auto_type a = cn_init_14129;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_14176 = m->xmm[2]; CN_U2 s = cn_init_14176;
__auto_type cn_init_14186 = m->xmm[0]; __auto_type a = cn_init_14186;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_14269 = 0x2U; __auto_type bv = cn_init_14269;
__auto_type cn_init_14277 = rg[2]; __auto_type av = cn_init_14277;
__auto_type cn_init_14295 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_14295;
}
if(cn_cond(fl,14)){
goto cn_break_b320;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_14328 = 0x4U; __auto_type bv = cn_init_14328;
__auto_type cn_init_14336 = rg[2]; __auto_type av = cn_init_14336;
__auto_type cn_init_14354 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_14354;
}
if(cn_cond(fl,12)){
goto cn_break_b284;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_14456 = m->xmm[0]; CN_U2 s = cn_init_14456;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_14544 = m->xmm[1]; CN_U2 s = cn_init_14544;
__auto_type cn_init_14554 = m->xmm[0]; __auto_type a = cn_init_14554;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_14633 = m->xmm[1]; CN_U2 s = cn_init_14633;
__auto_type cn_init_14643 = m->xmm[2]; __auto_type a = cn_init_14643;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_14722 = m->xmm[6]; CN_U2 s = cn_init_14722;
__auto_type cn_init_14732 = m->xmm[0]; __auto_type a = cn_init_14732;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_14779 = m->xmm[2]; CN_U2 s = cn_init_14779;
__auto_type cn_init_14789 = m->xmm[0]; __auto_type a = cn_init_14789;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_14872 = 0x8U; __auto_type bv = cn_init_14872;
__auto_type cn_init_14880 = rg[2]; __auto_type av = cn_init_14880;
__auto_type cn_init_14898 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_14898;
}
if(cn_cond(fl,12)){
goto cn_break_b248;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_14986 = m->xmm[0]; CN_U2 s = cn_init_14986;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_15074 = m->xmm[1]; CN_U2 s = cn_init_15074;
__auto_type cn_init_15084 = m->xmm[0]; __auto_type a = cn_init_15084;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_15163 = m->xmm[1]; CN_U2 s = cn_init_15163;
__auto_type cn_init_15173 = m->xmm[2]; __auto_type a = cn_init_15173;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_15252 = m->xmm[6]; CN_U2 s = cn_init_15252;
__auto_type cn_init_15262 = m->xmm[0]; __auto_type a = cn_init_15262;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_15309 = m->xmm[2]; CN_U2 s = cn_init_15309;
__auto_type cn_init_15319 = m->xmm[0]; __auto_type a = cn_init_15319;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_15402 = 0xaU; __auto_type bv = cn_init_15402;
__auto_type cn_init_15410 = rg[2]; __auto_type av = cn_init_15410;
__auto_type cn_init_15428 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_15428;
}
if(cn_cond(fl,12)){
goto cn_break_b284;
}
goto cn_break_b266;
}
cn_break_b248:;
{
__auto_type cn_init_15451 = 0x6U; __auto_type bv = cn_init_15451;
__auto_type cn_init_15459 = rg[2]; __auto_type av = cn_init_15459;
__auto_type cn_init_15477 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_15477;
}
if(cn_cond(fl,12)){
goto cn_break_b284;
}
}
cn_break_b266:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_15566 = m->xmm[0]; CN_U2 s = cn_init_15566;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_15654 = m->xmm[1]; CN_U2 s = cn_init_15654;
__auto_type cn_init_15664 = m->xmm[0]; __auto_type a = cn_init_15664;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_15743 = m->xmm[1]; CN_U2 s = cn_init_15743;
__auto_type cn_init_15753 = m->xmm[2]; __auto_type a = cn_init_15753;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_15832 = m->xmm[6]; CN_U2 s = cn_init_15832;
__auto_type cn_init_15842 = m->xmm[0]; __auto_type a = cn_init_15842;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_15889 = m->xmm[2]; CN_U2 s = cn_init_15889;
__auto_type cn_init_15899 = m->xmm[0]; __auto_type a = cn_init_15899;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b284:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b320;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_16085 = m->xmm[0]; CN_U2 s = cn_init_16085;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_16173 = m->xmm[1]; CN_U2 s = cn_init_16173;
__auto_type cn_init_16183 = m->xmm[0]; __auto_type a = cn_init_16183;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_16262 = m->xmm[1]; CN_U2 s = cn_init_16262;
__auto_type cn_init_16272 = m->xmm[2]; __auto_type a = cn_init_16272;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_16351 = m->xmm[6]; CN_U2 s = cn_init_16351;
__auto_type cn_init_16361 = m->xmm[0]; __auto_type a = cn_init_16361;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_16408 = m->xmm[2]; CN_U2 s = cn_init_16408;
__auto_type cn_init_16418 = m->xmm[0]; __auto_type a = cn_init_16418;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b320:;
{
__auto_type cn_init_16502 = 0x0U; __auto_type bv = cn_init_16502;
__auto_type cn_init_16510 = rg[1]; __auto_type av = cn_init_16510;
__auto_type cn_init_16528 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_16528;
}
if(cn_cond(fl,4)){
goto cn_break_b356;
}
{
__auto_type cn_init_16558 = m->xmm[0]; CN_U2 s = cn_init_16558;
__auto_type cn_init_16568 = m->xmm[0]; __auto_type a = cn_init_16568;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b356:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(m->xmm[1]=m->xmm[0]);
{
__auto_type cn_init_16626 = r10; uint64_t s = cn_init_16626;
__auto_type cn_init_16639 = m->xmm[0][0]; __auto_type a = cn_init_16639;
(m->xmm[0][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_16687 = m->xmm[0]; CN_U2 s = cn_init_16687;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_16720 = m->xmm[1]; CN_U2 s = cn_init_16720;
__auto_type cn_init_16730 = m->xmm[1]; __auto_type a = cn_init_16730;
(m->xmm[1]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_16767 = m->xmm[5]; CN_U2 s = cn_init_16767;
__auto_type cn_init_16777 = m->xmm[0]; __auto_type a = cn_init_16777;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b3;
}
cn_break_b50:;
{
__auto_type cn_init_16864 = 0x1U; __auto_type bv = cn_init_16864;
__auto_type cn_init_16872 = rg[3]; __auto_type av = cn_init_16872;
__auto_type cn_init_16890 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_16890;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b59;
}
(r12=m->xmm[0][1]);
{
__auto_type cn_init_16939 = m->xmm[1]; CN_U2 s = cn_init_16939;
(m->xmm[0][1]=s[0]);
}
(m->xmm[5]=m->xmm[0]);
{
__auto_type cn_init_16986 = m->xmm[0]; CN_U2 s = cn_init_16986;
__auto_type cn_init_16996 = m->xmm[0]; __auto_type a = cn_init_16996;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_17075 = m->xmm[0]; CN_U2 s = cn_init_17075;
__auto_type cn_init_17085 = m->xmm[0]; __auto_type a = cn_init_17085;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_17163 = m->xmm[0][0]; uint64_t s = cn_init_17163;
(m->xmm[0][0]=cn_bits(sqrt(cn_double(s))));
}
(r10=m->xmm[0][0]);
{
__auto_type cn_init_17209 = r12; uint64_t s = cn_init_17209;
(m->xmm[0][1]=s);
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100081f0U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_17272 = 0x0U; __auto_type bv = cn_init_17272;
__auto_type cn_init_17280 = rg[1]; __auto_type av = cn_init_17280;
__auto_type cn_init_17298 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_17298;
}
if(cn_cond(fl,4)){
goto cn_break_b105;
}
{
__auto_type cn_init_17328 = m->xmm[0]; CN_U2 s = cn_init_17328;
__auto_type cn_init_17338 = m->xmm[0]; __auto_type a = cn_init_17338;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b105:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_17434 = m->xmm[0]; CN_U2 s = cn_init_17434;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_17522 = m->xmm[1]; CN_U2 s = cn_init_17522;
__auto_type cn_init_17532 = m->xmm[0]; __auto_type a = cn_init_17532;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_17611 = m->xmm[1]; CN_U2 s = cn_init_17611;
__auto_type cn_init_17621 = m->xmm[2]; __auto_type a = cn_init_17621;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_17700 = m->xmm[6]; CN_U2 s = cn_init_17700;
__auto_type cn_init_17710 = m->xmm[0]; __auto_type a = cn_init_17710;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_17757 = m->xmm[2]; CN_U2 s = cn_init_17757;
__auto_type cn_init_17767 = m->xmm[0]; __auto_type a = cn_init_17767;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_17850 = 0x2U; __auto_type bv = cn_init_17850;
__auto_type cn_init_17858 = rg[2]; __auto_type av = cn_init_17858;
__auto_type cn_init_17876 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_17876;
}
if(cn_cond(fl,14)){
goto cn_break_b321;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_17909 = 0x4U; __auto_type bv = cn_init_17909;
__auto_type cn_init_17917 = rg[2]; __auto_type av = cn_init_17917;
__auto_type cn_init_17935 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_17935;
}
if(cn_cond(fl,12)){
goto cn_break_b285;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_18037 = m->xmm[0]; CN_U2 s = cn_init_18037;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_18125 = m->xmm[1]; CN_U2 s = cn_init_18125;
__auto_type cn_init_18135 = m->xmm[0]; __auto_type a = cn_init_18135;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_18214 = m->xmm[1]; CN_U2 s = cn_init_18214;
__auto_type cn_init_18224 = m->xmm[2]; __auto_type a = cn_init_18224;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_18303 = m->xmm[6]; CN_U2 s = cn_init_18303;
__auto_type cn_init_18313 = m->xmm[0]; __auto_type a = cn_init_18313;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_18360 = m->xmm[2]; CN_U2 s = cn_init_18360;
__auto_type cn_init_18370 = m->xmm[0]; __auto_type a = cn_init_18370;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_18453 = 0x8U; __auto_type bv = cn_init_18453;
__auto_type cn_init_18461 = rg[2]; __auto_type av = cn_init_18461;
__auto_type cn_init_18479 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_18479;
}
if(cn_cond(fl,12)){
goto cn_break_b249;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_18567 = m->xmm[0]; CN_U2 s = cn_init_18567;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_18655 = m->xmm[1]; CN_U2 s = cn_init_18655;
__auto_type cn_init_18665 = m->xmm[0]; __auto_type a = cn_init_18665;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_18744 = m->xmm[1]; CN_U2 s = cn_init_18744;
__auto_type cn_init_18754 = m->xmm[2]; __auto_type a = cn_init_18754;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_18833 = m->xmm[6]; CN_U2 s = cn_init_18833;
__auto_type cn_init_18843 = m->xmm[0]; __auto_type a = cn_init_18843;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_18890 = m->xmm[2]; CN_U2 s = cn_init_18890;
__auto_type cn_init_18900 = m->xmm[0]; __auto_type a = cn_init_18900;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_18983 = 0xaU; __auto_type bv = cn_init_18983;
__auto_type cn_init_18991 = rg[2]; __auto_type av = cn_init_18991;
__auto_type cn_init_19009 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_19009;
}
if(cn_cond(fl,12)){
goto cn_break_b285;
}
goto cn_break_b267;
}
cn_break_b249:;
{
__auto_type cn_init_19032 = 0x6U; __auto_type bv = cn_init_19032;
__auto_type cn_init_19040 = rg[2]; __auto_type av = cn_init_19040;
__auto_type cn_init_19058 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_19058;
}
if(cn_cond(fl,12)){
goto cn_break_b285;
}
}
cn_break_b267:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_19147 = m->xmm[0]; CN_U2 s = cn_init_19147;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_19235 = m->xmm[1]; CN_U2 s = cn_init_19235;
__auto_type cn_init_19245 = m->xmm[0]; __auto_type a = cn_init_19245;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_19324 = m->xmm[1]; CN_U2 s = cn_init_19324;
__auto_type cn_init_19334 = m->xmm[2]; __auto_type a = cn_init_19334;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_19413 = m->xmm[6]; CN_U2 s = cn_init_19413;
__auto_type cn_init_19423 = m->xmm[0]; __auto_type a = cn_init_19423;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_19470 = m->xmm[2]; CN_U2 s = cn_init_19470;
__auto_type cn_init_19480 = m->xmm[0]; __auto_type a = cn_init_19480;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b285:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b321;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_19666 = m->xmm[0]; CN_U2 s = cn_init_19666;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_19754 = m->xmm[1]; CN_U2 s = cn_init_19754;
__auto_type cn_init_19764 = m->xmm[0]; __auto_type a = cn_init_19764;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_19843 = m->xmm[1]; CN_U2 s = cn_init_19843;
__auto_type cn_init_19853 = m->xmm[2]; __auto_type a = cn_init_19853;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_19932 = m->xmm[6]; CN_U2 s = cn_init_19932;
__auto_type cn_init_19942 = m->xmm[0]; __auto_type a = cn_init_19942;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_19989 = m->xmm[2]; CN_U2 s = cn_init_19989;
__auto_type cn_init_19999 = m->xmm[0]; __auto_type a = cn_init_19999;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b321:;
{
__auto_type cn_init_20083 = 0x0U; __auto_type bv = cn_init_20083;
__auto_type cn_init_20091 = rg[1]; __auto_type av = cn_init_20091;
__auto_type cn_init_20109 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_20109;
}
if(cn_cond(fl,4)){
goto cn_break_b357;
}
{
__auto_type cn_init_20139 = m->xmm[0]; CN_U2 s = cn_init_20139;
__auto_type cn_init_20149 = m->xmm[0]; __auto_type a = cn_init_20149;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b357:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(m->xmm[1]=m->xmm[0]);
{
__auto_type cn_init_20207 = r10; uint64_t s = cn_init_20207;
__auto_type cn_init_20220 = m->xmm[0][0]; __auto_type a = cn_init_20220;
(m->xmm[0][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_20268 = m->xmm[0]; CN_U2 s = cn_init_20268;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_20301 = m->xmm[5]; CN_U2 s = cn_init_20301;
__auto_type cn_init_20311 = m->xmm[0]; __auto_type a = cn_init_20311;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_20390 = m->xmm[0]; CN_U2 s = cn_init_20390;
__auto_type cn_init_20400 = m->xmm[1]; __auto_type a = cn_init_20400;
(m->xmm[1]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_20437 = m->xmm[1]; CN_U2 s = cn_init_20437;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_20470 = m->xmm[1]; CN_U2 s = cn_init_20470;
__auto_type cn_init_20480 = m->xmm[1]; __auto_type a = cn_init_20480;
(m->xmm[1]=(CN_U2){a[1],s[1]});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b3;
}
cn_break_b59:;
(r12=m->xmm[0][0]);
{
__auto_type cn_init_20548 = m->xmm[1]; CN_U2 s = cn_init_20548;
(m->xmm[1][1]=s[0]);
}
{
__auto_type cn_init_20581 = m->xmm[1]; CN_U2 s = cn_init_20581;
__auto_type cn_init_20591 = m->xmm[0]; __auto_type a = cn_init_20591;
(m->xmm[0]=(CN_U2){a[1],s[1]});
}
(m->xmm[5]=m->xmm[0]);
{
__auto_type cn_init_20642 = m->xmm[0]; CN_U2 s = cn_init_20642;
__auto_type cn_init_20652 = m->xmm[0]; __auto_type a = cn_init_20652;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_20731 = m->xmm[0]; CN_U2 s = cn_init_20731;
__auto_type cn_init_20741 = m->xmm[0]; __auto_type a = cn_init_20741;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_20819 = m->xmm[0][0]; uint64_t s = cn_init_20819;
(m->xmm[0][0]=cn_bits(sqrt(cn_double(s))));
}
(r10=m->xmm[0][0]);
{
__auto_type cn_init_20865 = r12; uint64_t s = cn_init_20865;
(m->xmm[0][1]=s);
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008238U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_20928 = 0x0U; __auto_type bv = cn_init_20928;
__auto_type cn_init_20936 = rg[1]; __auto_type av = cn_init_20936;
__auto_type cn_init_20954 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_20954;
}
if(cn_cond(fl,4)){
goto cn_break_b106;
}
{
__auto_type cn_init_20984 = m->xmm[0]; CN_U2 s = cn_init_20984;
__auto_type cn_init_20994 = m->xmm[0]; __auto_type a = cn_init_20994;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b106:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_21090 = m->xmm[0]; CN_U2 s = cn_init_21090;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_21178 = m->xmm[1]; CN_U2 s = cn_init_21178;
__auto_type cn_init_21188 = m->xmm[0]; __auto_type a = cn_init_21188;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_21267 = m->xmm[1]; CN_U2 s = cn_init_21267;
__auto_type cn_init_21277 = m->xmm[2]; __auto_type a = cn_init_21277;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_21356 = m->xmm[6]; CN_U2 s = cn_init_21356;
__auto_type cn_init_21366 = m->xmm[0]; __auto_type a = cn_init_21366;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_21413 = m->xmm[2]; CN_U2 s = cn_init_21413;
__auto_type cn_init_21423 = m->xmm[0]; __auto_type a = cn_init_21423;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_21506 = 0x2U; __auto_type bv = cn_init_21506;
__auto_type cn_init_21514 = rg[2]; __auto_type av = cn_init_21514;
__auto_type cn_init_21532 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_21532;
}
if(cn_cond(fl,14)){
goto cn_break_b322;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_21565 = 0x4U; __auto_type bv = cn_init_21565;
__auto_type cn_init_21573 = rg[2]; __auto_type av = cn_init_21573;
__auto_type cn_init_21591 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_21591;
}
if(cn_cond(fl,12)){
goto cn_break_b286;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_21693 = m->xmm[0]; CN_U2 s = cn_init_21693;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_21781 = m->xmm[1]; CN_U2 s = cn_init_21781;
__auto_type cn_init_21791 = m->xmm[0]; __auto_type a = cn_init_21791;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_21870 = m->xmm[1]; CN_U2 s = cn_init_21870;
__auto_type cn_init_21880 = m->xmm[2]; __auto_type a = cn_init_21880;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_21959 = m->xmm[6]; CN_U2 s = cn_init_21959;
__auto_type cn_init_21969 = m->xmm[0]; __auto_type a = cn_init_21969;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_22016 = m->xmm[2]; CN_U2 s = cn_init_22016;
__auto_type cn_init_22026 = m->xmm[0]; __auto_type a = cn_init_22026;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_22109 = 0x8U; __auto_type bv = cn_init_22109;
__auto_type cn_init_22117 = rg[2]; __auto_type av = cn_init_22117;
__auto_type cn_init_22135 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_22135;
}
if(cn_cond(fl,12)){
goto cn_break_b250;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_22223 = m->xmm[0]; CN_U2 s = cn_init_22223;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_22311 = m->xmm[1]; CN_U2 s = cn_init_22311;
__auto_type cn_init_22321 = m->xmm[0]; __auto_type a = cn_init_22321;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_22400 = m->xmm[1]; CN_U2 s = cn_init_22400;
__auto_type cn_init_22410 = m->xmm[2]; __auto_type a = cn_init_22410;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_22489 = m->xmm[6]; CN_U2 s = cn_init_22489;
__auto_type cn_init_22499 = m->xmm[0]; __auto_type a = cn_init_22499;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_22546 = m->xmm[2]; CN_U2 s = cn_init_22546;
__auto_type cn_init_22556 = m->xmm[0]; __auto_type a = cn_init_22556;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_22639 = 0xaU; __auto_type bv = cn_init_22639;
__auto_type cn_init_22647 = rg[2]; __auto_type av = cn_init_22647;
__auto_type cn_init_22665 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_22665;
}
if(cn_cond(fl,12)){
goto cn_break_b286;
}
goto cn_break_b268;
}
cn_break_b250:;
{
__auto_type cn_init_22688 = 0x6U; __auto_type bv = cn_init_22688;
__auto_type cn_init_22696 = rg[2]; __auto_type av = cn_init_22696;
__auto_type cn_init_22714 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_22714;
}
if(cn_cond(fl,12)){
goto cn_break_b286;
}
}
cn_break_b268:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_22803 = m->xmm[0]; CN_U2 s = cn_init_22803;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_22891 = m->xmm[1]; CN_U2 s = cn_init_22891;
__auto_type cn_init_22901 = m->xmm[0]; __auto_type a = cn_init_22901;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_22980 = m->xmm[1]; CN_U2 s = cn_init_22980;
__auto_type cn_init_22990 = m->xmm[2]; __auto_type a = cn_init_22990;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_23069 = m->xmm[6]; CN_U2 s = cn_init_23069;
__auto_type cn_init_23079 = m->xmm[0]; __auto_type a = cn_init_23079;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_23126 = m->xmm[2]; CN_U2 s = cn_init_23126;
__auto_type cn_init_23136 = m->xmm[0]; __auto_type a = cn_init_23136;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b286:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b322;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_23322 = m->xmm[0]; CN_U2 s = cn_init_23322;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_23410 = m->xmm[1]; CN_U2 s = cn_init_23410;
__auto_type cn_init_23420 = m->xmm[0]; __auto_type a = cn_init_23420;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_23499 = m->xmm[1]; CN_U2 s = cn_init_23499;
__auto_type cn_init_23509 = m->xmm[2]; __auto_type a = cn_init_23509;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_23588 = m->xmm[6]; CN_U2 s = cn_init_23588;
__auto_type cn_init_23598 = m->xmm[0]; __auto_type a = cn_init_23598;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_23645 = m->xmm[2]; CN_U2 s = cn_init_23645;
__auto_type cn_init_23655 = m->xmm[0]; __auto_type a = cn_init_23655;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b322:;
{
__auto_type cn_init_23739 = 0x0U; __auto_type bv = cn_init_23739;
__auto_type cn_init_23747 = rg[1]; __auto_type av = cn_init_23747;
__auto_type cn_init_23765 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_23765;
}
if(cn_cond(fl,4)){
goto cn_break_b358;
}
{
__auto_type cn_init_23795 = m->xmm[0]; CN_U2 s = cn_init_23795;
__auto_type cn_init_23805 = m->xmm[0]; __auto_type a = cn_init_23805;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b358:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(m->xmm[1]=m->xmm[0]);
{
__auto_type cn_init_23863 = r10; uint64_t s = cn_init_23863;
__auto_type cn_init_23876 = m->xmm[1][0]; __auto_type a = cn_init_23876;
(m->xmm[1][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_23924 = m->xmm[1]; CN_U2 s = cn_init_23924;
(m->xmm[1][1]=s[0]);
}
{
__auto_type cn_init_23957 = m->xmm[5]; CN_U2 s = cn_init_23957;
__auto_type cn_init_23967 = m->xmm[1]; __auto_type a = cn_init_23967;
(m->xmm[1]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_24046 = m->xmm[0]; CN_U2 s = cn_init_24046;
__auto_type cn_init_24056 = m->xmm[0]; __auto_type a = cn_init_24056;
(m->xmm[0]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_24093 = m->xmm[1]; CN_U2 s = cn_init_24093;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_24126 = m->xmm[1]; CN_U2 s = cn_init_24126;
__auto_type cn_init_24136 = m->xmm[1]; __auto_type a = cn_init_24136;
(m->xmm[1]=(CN_U2){a[1],s[1]});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b3:;
{
__auto_type cn_init_24178 = 0x0U; __auto_type bv = cn_init_24178;
__auto_type cn_init_24195 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_24195;
__auto_type cn_init_24213 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_24213;
}
if(cn_cond(fl,4)){
goto cn_break_b5;
}
(rg[2]=((uint32_t)(((((v28>>32))&0xffffffffULL)))));
(rg[3]=((uint32_t)(((((v28>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000807aU))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_24313 = rg[1]; __auto_type bv = cn_init_24313;
__auto_type cn_init_24321 = rg[1]; __auto_type av = cn_init_24321;
__auto_type cn_init_24339 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_24339;
(rg[1]=r);
}
{
__auto_type cn_init_24353 = 0x6U; __auto_type bv = cn_init_24353;
__auto_type cn_init_24361 = rg[3]; __auto_type av = cn_init_24361;
__auto_type cn_init_24379 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_24379;
}
if(cn_cond(fl,12)){
goto cn_break_b15;
}
{
__auto_type cn_init_24398 = 0x1U; __auto_type bv = cn_init_24398;
__auto_type cn_init_24406 = rg[1]; __auto_type av = cn_init_24406;
__auto_type cn_init_24424 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_24424;
(rg[1]=r);
}
{
__auto_type cn_init_24438 = 0x6U; __auto_type bv = cn_init_24438;
__auto_type cn_init_24446 = rg[3]; __auto_type av = cn_init_24446;
__auto_type cn_init_24464 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_24464;
(rg[3]=r);
}
}
cn_break_b15:;
{
__auto_type cn_init_24479 = 0x1U; __auto_type bv = cn_init_24479;
__auto_type cn_init_24487 = rg[3]; __auto_type av = cn_init_24487;
__auto_type cn_init_24505 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_24505;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b24;
}
(m->xmm[3]=m->xmm[0]);
{
__auto_type cn_init_24556 = m->xmm[3]; CN_U2 s = cn_init_24556;
__auto_type cn_init_24566 = m->xmm[3]; __auto_type a = cn_init_24566;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_24645 = m->xmm[3]; CN_U2 s = cn_init_24645;
__auto_type cn_init_24655 = m->xmm[3]; __auto_type a = cn_init_24655;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_24733 = m->xmm[3][0]; uint64_t s = cn_init_24733;
(m->xmm[5][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_24767 = v34; uint64_t s = cn_init_24767;
(m->xmm[4]=(CN_U2){s,0});
}
{
__auto_type cn_init_24797 = m->xmm[5][0]; uint64_t s = cn_init_24797;
__auto_type cn_init_24810 = m->xmm[4][0]; __auto_type a = cn_init_24810;
(m->xmm[4][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_24858 = m->xmm[4]; CN_U2 s = cn_init_24858;
(m->xmm[4][1]=s[0]);
}
{
__auto_type cn_init_24891 = m->xmm[5]; CN_U2 s = cn_init_24891;
(m->xmm[5][1]=s[0]);
}
(r10=m->xmm[1][0]);
{
__auto_type cn_init_24936 = m->xmm[4]; CN_U2 s = cn_init_24936;
__auto_type cn_init_24946 = m->xmm[0]; __auto_type a = cn_init_24946;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100080f2U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_25058 = 0x0U; __auto_type bv = cn_init_25058;
__auto_type cn_init_25066 = rg[1]; __auto_type av = cn_init_25066;
__auto_type cn_init_25084 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_25084;
}
if(cn_cond(fl,4)){
goto cn_break_b107;
}
{
__auto_type cn_init_25114 = m->xmm[0]; CN_U2 s = cn_init_25114;
__auto_type cn_init_25124 = m->xmm[0]; __auto_type a = cn_init_25124;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b107:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_25220 = m->xmm[0]; CN_U2 s = cn_init_25220;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_25308 = m->xmm[1]; CN_U2 s = cn_init_25308;
__auto_type cn_init_25318 = m->xmm[0]; __auto_type a = cn_init_25318;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_25397 = m->xmm[1]; CN_U2 s = cn_init_25397;
__auto_type cn_init_25407 = m->xmm[2]; __auto_type a = cn_init_25407;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_25486 = m->xmm[6]; CN_U2 s = cn_init_25486;
__auto_type cn_init_25496 = m->xmm[0]; __auto_type a = cn_init_25496;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_25543 = m->xmm[2]; CN_U2 s = cn_init_25543;
__auto_type cn_init_25553 = m->xmm[0]; __auto_type a = cn_init_25553;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_25636 = 0x2U; __auto_type bv = cn_init_25636;
__auto_type cn_init_25644 = rg[2]; __auto_type av = cn_init_25644;
__auto_type cn_init_25662 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_25662;
}
if(cn_cond(fl,14)){
goto cn_break_b323;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_25695 = 0x4U; __auto_type bv = cn_init_25695;
__auto_type cn_init_25703 = rg[2]; __auto_type av = cn_init_25703;
__auto_type cn_init_25721 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_25721;
}
if(cn_cond(fl,12)){
goto cn_break_b287;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_25823 = m->xmm[0]; CN_U2 s = cn_init_25823;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_25911 = m->xmm[1]; CN_U2 s = cn_init_25911;
__auto_type cn_init_25921 = m->xmm[0]; __auto_type a = cn_init_25921;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_26000 = m->xmm[1]; CN_U2 s = cn_init_26000;
__auto_type cn_init_26010 = m->xmm[2]; __auto_type a = cn_init_26010;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_26089 = m->xmm[6]; CN_U2 s = cn_init_26089;
__auto_type cn_init_26099 = m->xmm[0]; __auto_type a = cn_init_26099;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_26146 = m->xmm[2]; CN_U2 s = cn_init_26146;
__auto_type cn_init_26156 = m->xmm[0]; __auto_type a = cn_init_26156;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_26239 = 0x8U; __auto_type bv = cn_init_26239;
__auto_type cn_init_26247 = rg[2]; __auto_type av = cn_init_26247;
__auto_type cn_init_26265 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_26265;
}
if(cn_cond(fl,12)){
goto cn_break_b251;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_26353 = m->xmm[0]; CN_U2 s = cn_init_26353;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_26441 = m->xmm[1]; CN_U2 s = cn_init_26441;
__auto_type cn_init_26451 = m->xmm[0]; __auto_type a = cn_init_26451;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_26530 = m->xmm[1]; CN_U2 s = cn_init_26530;
__auto_type cn_init_26540 = m->xmm[2]; __auto_type a = cn_init_26540;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_26619 = m->xmm[6]; CN_U2 s = cn_init_26619;
__auto_type cn_init_26629 = m->xmm[0]; __auto_type a = cn_init_26629;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_26676 = m->xmm[2]; CN_U2 s = cn_init_26676;
__auto_type cn_init_26686 = m->xmm[0]; __auto_type a = cn_init_26686;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_26769 = 0xaU; __auto_type bv = cn_init_26769;
__auto_type cn_init_26777 = rg[2]; __auto_type av = cn_init_26777;
__auto_type cn_init_26795 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_26795;
}
if(cn_cond(fl,12)){
goto cn_break_b287;
}
goto cn_break_b269;
}
cn_break_b251:;
{
__auto_type cn_init_26818 = 0x6U; __auto_type bv = cn_init_26818;
__auto_type cn_init_26826 = rg[2]; __auto_type av = cn_init_26826;
__auto_type cn_init_26844 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_26844;
}
if(cn_cond(fl,12)){
goto cn_break_b287;
}
}
cn_break_b269:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_26933 = m->xmm[0]; CN_U2 s = cn_init_26933;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_27021 = m->xmm[1]; CN_U2 s = cn_init_27021;
__auto_type cn_init_27031 = m->xmm[0]; __auto_type a = cn_init_27031;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_27110 = m->xmm[1]; CN_U2 s = cn_init_27110;
__auto_type cn_init_27120 = m->xmm[2]; __auto_type a = cn_init_27120;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_27199 = m->xmm[6]; CN_U2 s = cn_init_27199;
__auto_type cn_init_27209 = m->xmm[0]; __auto_type a = cn_init_27209;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_27256 = m->xmm[2]; CN_U2 s = cn_init_27256;
__auto_type cn_init_27266 = m->xmm[0]; __auto_type a = cn_init_27266;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b287:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b323;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_27452 = m->xmm[0]; CN_U2 s = cn_init_27452;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_27540 = m->xmm[1]; CN_U2 s = cn_init_27540;
__auto_type cn_init_27550 = m->xmm[0]; __auto_type a = cn_init_27550;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_27629 = m->xmm[1]; CN_U2 s = cn_init_27629;
__auto_type cn_init_27639 = m->xmm[2]; __auto_type a = cn_init_27639;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_27718 = m->xmm[6]; CN_U2 s = cn_init_27718;
__auto_type cn_init_27728 = m->xmm[0]; __auto_type a = cn_init_27728;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_27775 = m->xmm[2]; CN_U2 s = cn_init_27775;
__auto_type cn_init_27785 = m->xmm[0]; __auto_type a = cn_init_27785;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b323:;
{
__auto_type cn_init_27869 = 0x0U; __auto_type bv = cn_init_27869;
__auto_type cn_init_27877 = rg[1]; __auto_type av = cn_init_27877;
__auto_type cn_init_27895 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_27895;
}
if(cn_cond(fl,4)){
goto cn_break_b359;
}
{
__auto_type cn_init_27925 = m->xmm[0]; CN_U2 s = cn_init_27925;
__auto_type cn_init_27935 = m->xmm[0]; __auto_type a = cn_init_27935;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b359:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_27979 = r10; uint64_t s = cn_init_27979;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_28010 = m->xmm[5]; CN_U2 s = cn_init_28010;
__auto_type cn_init_28020 = m->xmm[0]; __auto_type a = cn_init_28020;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b5;
}
cn_break_b24:;
{
__auto_type cn_init_28107 = 0x1U; __auto_type bv = cn_init_28107;
__auto_type cn_init_28115 = rg[3]; __auto_type av = cn_init_28115;
__auto_type cn_init_28133 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_28133;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b33;
}
(r10=m->xmm[0][1]);
{
__auto_type cn_init_28182 = m->xmm[1]; CN_U2 s = cn_init_28182;
(m->xmm[0][1]=s[0]);
}
(m->xmm[3]=m->xmm[0]);
{
__auto_type cn_init_28229 = m->xmm[3]; CN_U2 s = cn_init_28229;
__auto_type cn_init_28239 = m->xmm[3]; __auto_type a = cn_init_28239;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_28318 = m->xmm[3]; CN_U2 s = cn_init_28318;
__auto_type cn_init_28328 = m->xmm[3]; __auto_type a = cn_init_28328;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_28406 = m->xmm[3][0]; uint64_t s = cn_init_28406;
(m->xmm[5][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_28440 = v34; uint64_t s = cn_init_28440;
(m->xmm[4]=(CN_U2){s,0});
}
{
__auto_type cn_init_28470 = m->xmm[5][0]; uint64_t s = cn_init_28470;
__auto_type cn_init_28483 = m->xmm[4][0]; __auto_type a = cn_init_28483;
(m->xmm[4][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_28531 = m->xmm[4]; CN_U2 s = cn_init_28531;
(m->xmm[4][1]=s[0]);
}
{
__auto_type cn_init_28564 = m->xmm[5]; CN_U2 s = cn_init_28564;
(m->xmm[5][1]=s[0]);
}
{
__auto_type cn_init_28597 = m->xmm[4]; CN_U2 s = cn_init_28597;
__auto_type cn_init_28607 = m->xmm[0]; __auto_type a = cn_init_28607;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008132U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_28719 = 0x0U; __auto_type bv = cn_init_28719;
__auto_type cn_init_28727 = rg[1]; __auto_type av = cn_init_28727;
__auto_type cn_init_28745 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_28745;
}
if(cn_cond(fl,4)){
goto cn_break_b108;
}
{
__auto_type cn_init_28775 = m->xmm[0]; CN_U2 s = cn_init_28775;
__auto_type cn_init_28785 = m->xmm[0]; __auto_type a = cn_init_28785;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b108:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_28881 = m->xmm[0]; CN_U2 s = cn_init_28881;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_28969 = m->xmm[1]; CN_U2 s = cn_init_28969;
__auto_type cn_init_28979 = m->xmm[0]; __auto_type a = cn_init_28979;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_29058 = m->xmm[1]; CN_U2 s = cn_init_29058;
__auto_type cn_init_29068 = m->xmm[2]; __auto_type a = cn_init_29068;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_29147 = m->xmm[6]; CN_U2 s = cn_init_29147;
__auto_type cn_init_29157 = m->xmm[0]; __auto_type a = cn_init_29157;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_29204 = m->xmm[2]; CN_U2 s = cn_init_29204;
__auto_type cn_init_29214 = m->xmm[0]; __auto_type a = cn_init_29214;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_29297 = 0x2U; __auto_type bv = cn_init_29297;
__auto_type cn_init_29305 = rg[2]; __auto_type av = cn_init_29305;
__auto_type cn_init_29323 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_29323;
}
if(cn_cond(fl,14)){
goto cn_break_b324;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_29356 = 0x4U; __auto_type bv = cn_init_29356;
__auto_type cn_init_29364 = rg[2]; __auto_type av = cn_init_29364;
__auto_type cn_init_29382 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_29382;
}
if(cn_cond(fl,12)){
goto cn_break_b288;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_29484 = m->xmm[0]; CN_U2 s = cn_init_29484;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_29572 = m->xmm[1]; CN_U2 s = cn_init_29572;
__auto_type cn_init_29582 = m->xmm[0]; __auto_type a = cn_init_29582;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_29661 = m->xmm[1]; CN_U2 s = cn_init_29661;
__auto_type cn_init_29671 = m->xmm[2]; __auto_type a = cn_init_29671;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_29750 = m->xmm[6]; CN_U2 s = cn_init_29750;
__auto_type cn_init_29760 = m->xmm[0]; __auto_type a = cn_init_29760;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_29807 = m->xmm[2]; CN_U2 s = cn_init_29807;
__auto_type cn_init_29817 = m->xmm[0]; __auto_type a = cn_init_29817;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_29900 = 0x8U; __auto_type bv = cn_init_29900;
__auto_type cn_init_29908 = rg[2]; __auto_type av = cn_init_29908;
__auto_type cn_init_29926 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_29926;
}
if(cn_cond(fl,12)){
goto cn_break_b252;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_30014 = m->xmm[0]; CN_U2 s = cn_init_30014;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_30102 = m->xmm[1]; CN_U2 s = cn_init_30102;
__auto_type cn_init_30112 = m->xmm[0]; __auto_type a = cn_init_30112;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_30191 = m->xmm[1]; CN_U2 s = cn_init_30191;
__auto_type cn_init_30201 = m->xmm[2]; __auto_type a = cn_init_30201;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_30280 = m->xmm[6]; CN_U2 s = cn_init_30280;
__auto_type cn_init_30290 = m->xmm[0]; __auto_type a = cn_init_30290;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_30337 = m->xmm[2]; CN_U2 s = cn_init_30337;
__auto_type cn_init_30347 = m->xmm[0]; __auto_type a = cn_init_30347;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_30430 = 0xaU; __auto_type bv = cn_init_30430;
__auto_type cn_init_30438 = rg[2]; __auto_type av = cn_init_30438;
__auto_type cn_init_30456 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_30456;
}
if(cn_cond(fl,12)){
goto cn_break_b288;
}
goto cn_break_b270;
}
cn_break_b252:;
{
__auto_type cn_init_30479 = 0x6U; __auto_type bv = cn_init_30479;
__auto_type cn_init_30487 = rg[2]; __auto_type av = cn_init_30487;
__auto_type cn_init_30505 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_30505;
}
if(cn_cond(fl,12)){
goto cn_break_b288;
}
}
cn_break_b270:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_30594 = m->xmm[0]; CN_U2 s = cn_init_30594;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_30682 = m->xmm[1]; CN_U2 s = cn_init_30682;
__auto_type cn_init_30692 = m->xmm[0]; __auto_type a = cn_init_30692;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_30771 = m->xmm[1]; CN_U2 s = cn_init_30771;
__auto_type cn_init_30781 = m->xmm[2]; __auto_type a = cn_init_30781;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_30860 = m->xmm[6]; CN_U2 s = cn_init_30860;
__auto_type cn_init_30870 = m->xmm[0]; __auto_type a = cn_init_30870;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_30917 = m->xmm[2]; CN_U2 s = cn_init_30917;
__auto_type cn_init_30927 = m->xmm[0]; __auto_type a = cn_init_30927;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b288:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b324;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_31113 = m->xmm[0]; CN_U2 s = cn_init_31113;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_31201 = m->xmm[1]; CN_U2 s = cn_init_31201;
__auto_type cn_init_31211 = m->xmm[0]; __auto_type a = cn_init_31211;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_31290 = m->xmm[1]; CN_U2 s = cn_init_31290;
__auto_type cn_init_31300 = m->xmm[2]; __auto_type a = cn_init_31300;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_31379 = m->xmm[6]; CN_U2 s = cn_init_31379;
__auto_type cn_init_31389 = m->xmm[0]; __auto_type a = cn_init_31389;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_31436 = m->xmm[2]; CN_U2 s = cn_init_31436;
__auto_type cn_init_31446 = m->xmm[0]; __auto_type a = cn_init_31446;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b324:;
{
__auto_type cn_init_31530 = 0x0U; __auto_type bv = cn_init_31530;
__auto_type cn_init_31538 = rg[1]; __auto_type av = cn_init_31538;
__auto_type cn_init_31556 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_31556;
}
if(cn_cond(fl,4)){
goto cn_break_b360;
}
{
__auto_type cn_init_31586 = m->xmm[0]; CN_U2 s = cn_init_31586;
__auto_type cn_init_31596 = m->xmm[0]; __auto_type a = cn_init_31596;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b360:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_31649 = m->xmm[5]; CN_U2 s = cn_init_31649;
__auto_type cn_init_31659 = m->xmm[0]; __auto_type a = cn_init_31659;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_31738 = m->xmm[0]; CN_U2 s = cn_init_31738;

(m->xmm[1]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_31817 = r10; uint64_t s = cn_init_31817;
(m->xmm[0][1]=s);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b5;
}
cn_break_b33:;
{
__auto_type cn_init_31855 = 0x1U; __auto_type bv = cn_init_31855;
__auto_type cn_init_31863 = rg[3]; __auto_type av = cn_init_31863;
__auto_type cn_init_31881 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_31881;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b42;
}
(r10=m->xmm[0][0]);
{
__auto_type cn_init_31930 = m->xmm[0]; CN_U2 s = cn_init_31930;
__auto_type cn_init_31940 = m->xmm[0]; __auto_type a = cn_init_31940;
(m->xmm[0]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_31977 = m->xmm[1]; CN_U2 s = cn_init_31977;
(m->xmm[0][1]=s[0]);
}
(m->xmm[3]=m->xmm[0]);
{
__auto_type cn_init_32024 = m->xmm[3]; CN_U2 s = cn_init_32024;
__auto_type cn_init_32034 = m->xmm[3]; __auto_type a = cn_init_32034;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_32113 = m->xmm[3]; CN_U2 s = cn_init_32113;
__auto_type cn_init_32123 = m->xmm[3]; __auto_type a = cn_init_32123;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_32201 = m->xmm[3][0]; uint64_t s = cn_init_32201;
(m->xmm[5][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_32235 = v34; uint64_t s = cn_init_32235;
(m->xmm[4]=(CN_U2){s,0});
}
{
__auto_type cn_init_32265 = m->xmm[5][0]; uint64_t s = cn_init_32265;
__auto_type cn_init_32278 = m->xmm[4][0]; __auto_type a = cn_init_32278;
(m->xmm[4][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_32326 = m->xmm[4]; CN_U2 s = cn_init_32326;
(m->xmm[4][1]=s[0]);
}
{
__auto_type cn_init_32359 = m->xmm[5]; CN_U2 s = cn_init_32359;
(m->xmm[5][1]=s[0]);
}
{
__auto_type cn_init_32392 = m->xmm[4]; CN_U2 s = cn_init_32392;
__auto_type cn_init_32402 = m->xmm[0]; __auto_type a = cn_init_32402;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x1000817bU))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_32514 = 0x0U; __auto_type bv = cn_init_32514;
__auto_type cn_init_32522 = rg[1]; __auto_type av = cn_init_32522;
__auto_type cn_init_32540 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_32540;
}
if(cn_cond(fl,4)){
goto cn_break_b109;
}
{
__auto_type cn_init_32570 = m->xmm[0]; CN_U2 s = cn_init_32570;
__auto_type cn_init_32580 = m->xmm[0]; __auto_type a = cn_init_32580;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b109:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_32676 = m->xmm[0]; CN_U2 s = cn_init_32676;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_32764 = m->xmm[1]; CN_U2 s = cn_init_32764;
__auto_type cn_init_32774 = m->xmm[0]; __auto_type a = cn_init_32774;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_32853 = m->xmm[1]; CN_U2 s = cn_init_32853;
__auto_type cn_init_32863 = m->xmm[2]; __auto_type a = cn_init_32863;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_32942 = m->xmm[6]; CN_U2 s = cn_init_32942;
__auto_type cn_init_32952 = m->xmm[0]; __auto_type a = cn_init_32952;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_32999 = m->xmm[2]; CN_U2 s = cn_init_32999;
__auto_type cn_init_33009 = m->xmm[0]; __auto_type a = cn_init_33009;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_33092 = 0x2U; __auto_type bv = cn_init_33092;
__auto_type cn_init_33100 = rg[2]; __auto_type av = cn_init_33100;
__auto_type cn_init_33118 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_33118;
}
if(cn_cond(fl,14)){
goto cn_break_b325;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_33151 = 0x4U; __auto_type bv = cn_init_33151;
__auto_type cn_init_33159 = rg[2]; __auto_type av = cn_init_33159;
__auto_type cn_init_33177 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_33177;
}
if(cn_cond(fl,12)){
goto cn_break_b289;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_33279 = m->xmm[0]; CN_U2 s = cn_init_33279;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_33367 = m->xmm[1]; CN_U2 s = cn_init_33367;
__auto_type cn_init_33377 = m->xmm[0]; __auto_type a = cn_init_33377;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_33456 = m->xmm[1]; CN_U2 s = cn_init_33456;
__auto_type cn_init_33466 = m->xmm[2]; __auto_type a = cn_init_33466;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_33545 = m->xmm[6]; CN_U2 s = cn_init_33545;
__auto_type cn_init_33555 = m->xmm[0]; __auto_type a = cn_init_33555;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_33602 = m->xmm[2]; CN_U2 s = cn_init_33602;
__auto_type cn_init_33612 = m->xmm[0]; __auto_type a = cn_init_33612;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_33695 = 0x8U; __auto_type bv = cn_init_33695;
__auto_type cn_init_33703 = rg[2]; __auto_type av = cn_init_33703;
__auto_type cn_init_33721 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_33721;
}
if(cn_cond(fl,12)){
goto cn_break_b253;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_33809 = m->xmm[0]; CN_U2 s = cn_init_33809;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_33897 = m->xmm[1]; CN_U2 s = cn_init_33897;
__auto_type cn_init_33907 = m->xmm[0]; __auto_type a = cn_init_33907;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_33986 = m->xmm[1]; CN_U2 s = cn_init_33986;
__auto_type cn_init_33996 = m->xmm[2]; __auto_type a = cn_init_33996;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_34075 = m->xmm[6]; CN_U2 s = cn_init_34075;
__auto_type cn_init_34085 = m->xmm[0]; __auto_type a = cn_init_34085;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_34132 = m->xmm[2]; CN_U2 s = cn_init_34132;
__auto_type cn_init_34142 = m->xmm[0]; __auto_type a = cn_init_34142;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_34225 = 0xaU; __auto_type bv = cn_init_34225;
__auto_type cn_init_34233 = rg[2]; __auto_type av = cn_init_34233;
__auto_type cn_init_34251 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_34251;
}
if(cn_cond(fl,12)){
goto cn_break_b289;
}
goto cn_break_b271;
}
cn_break_b253:;
{
__auto_type cn_init_34274 = 0x6U; __auto_type bv = cn_init_34274;
__auto_type cn_init_34282 = rg[2]; __auto_type av = cn_init_34282;
__auto_type cn_init_34300 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_34300;
}
if(cn_cond(fl,12)){
goto cn_break_b289;
}
}
cn_break_b271:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_34389 = m->xmm[0]; CN_U2 s = cn_init_34389;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_34477 = m->xmm[1]; CN_U2 s = cn_init_34477;
__auto_type cn_init_34487 = m->xmm[0]; __auto_type a = cn_init_34487;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_34566 = m->xmm[1]; CN_U2 s = cn_init_34566;
__auto_type cn_init_34576 = m->xmm[2]; __auto_type a = cn_init_34576;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_34655 = m->xmm[6]; CN_U2 s = cn_init_34655;
__auto_type cn_init_34665 = m->xmm[0]; __auto_type a = cn_init_34665;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_34712 = m->xmm[2]; CN_U2 s = cn_init_34712;
__auto_type cn_init_34722 = m->xmm[0]; __auto_type a = cn_init_34722;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b289:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b325;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_34908 = m->xmm[0]; CN_U2 s = cn_init_34908;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_34996 = m->xmm[1]; CN_U2 s = cn_init_34996;
__auto_type cn_init_35006 = m->xmm[0]; __auto_type a = cn_init_35006;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_35085 = m->xmm[1]; CN_U2 s = cn_init_35085;
__auto_type cn_init_35095 = m->xmm[2]; __auto_type a = cn_init_35095;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_35174 = m->xmm[6]; CN_U2 s = cn_init_35174;
__auto_type cn_init_35184 = m->xmm[0]; __auto_type a = cn_init_35184;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_35231 = m->xmm[2]; CN_U2 s = cn_init_35231;
__auto_type cn_init_35241 = m->xmm[0]; __auto_type a = cn_init_35241;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b325:;
{
__auto_type cn_init_35325 = 0x0U; __auto_type bv = cn_init_35325;
__auto_type cn_init_35333 = rg[1]; __auto_type av = cn_init_35333;
__auto_type cn_init_35351 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_35351;
}
if(cn_cond(fl,4)){
goto cn_break_b361;
}
{
__auto_type cn_init_35381 = m->xmm[0]; CN_U2 s = cn_init_35381;
__auto_type cn_init_35391 = m->xmm[0]; __auto_type a = cn_init_35391;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b361:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_35444 = m->xmm[5]; CN_U2 s = cn_init_35444;
__auto_type cn_init_35454 = m->xmm[0]; __auto_type a = cn_init_35454;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_35533 = m->xmm[0]; CN_U2 s = cn_init_35533;

(m->xmm[1]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_35621 = m->xmm[0]; CN_U2 s = cn_init_35621;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_35645 = r10; uint64_t s = cn_init_35645;
(m->xmm[0][0]=s);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b5;
}
cn_break_b42:;
{
__auto_type cn_init_35683 = 0x1U; __auto_type bv = cn_init_35683;
__auto_type cn_init_35691 = rg[3]; __auto_type av = cn_init_35691;
__auto_type cn_init_35709 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_35709;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b51;
}
(m->xmm[5]=m->xmm[0]);
{
__auto_type cn_init_35760 = m->xmm[0]; CN_U2 s = cn_init_35760;
__auto_type cn_init_35770 = m->xmm[0]; __auto_type a = cn_init_35770;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_35849 = m->xmm[0]; CN_U2 s = cn_init_35849;
__auto_type cn_init_35859 = m->xmm[0]; __auto_type a = cn_init_35859;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_35937 = m->xmm[0][0]; uint64_t s = cn_init_35937;
(m->xmm[0][0]=cn_bits(sqrt(cn_double(s))));
}
(r10=m->xmm[0][0]);
{
__auto_type cn_init_35992 = m->xmm[1]; CN_U2 s = cn_init_35992;
(m->xmm[0][1]=s[0]);
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100081afU))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_36058 = 0x0U; __auto_type bv = cn_init_36058;
__auto_type cn_init_36066 = rg[1]; __auto_type av = cn_init_36066;
__auto_type cn_init_36084 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_36084;
}
if(cn_cond(fl,4)){
goto cn_break_b110;
}
{
__auto_type cn_init_36114 = m->xmm[0]; CN_U2 s = cn_init_36114;
__auto_type cn_init_36124 = m->xmm[0]; __auto_type a = cn_init_36124;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b110:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_36220 = m->xmm[0]; CN_U2 s = cn_init_36220;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_36308 = m->xmm[1]; CN_U2 s = cn_init_36308;
__auto_type cn_init_36318 = m->xmm[0]; __auto_type a = cn_init_36318;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_36397 = m->xmm[1]; CN_U2 s = cn_init_36397;
__auto_type cn_init_36407 = m->xmm[2]; __auto_type a = cn_init_36407;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_36486 = m->xmm[6]; CN_U2 s = cn_init_36486;
__auto_type cn_init_36496 = m->xmm[0]; __auto_type a = cn_init_36496;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_36543 = m->xmm[2]; CN_U2 s = cn_init_36543;
__auto_type cn_init_36553 = m->xmm[0]; __auto_type a = cn_init_36553;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_36636 = 0x2U; __auto_type bv = cn_init_36636;
__auto_type cn_init_36644 = rg[2]; __auto_type av = cn_init_36644;
__auto_type cn_init_36662 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_36662;
}
if(cn_cond(fl,14)){
goto cn_break_b326;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_36695 = 0x4U; __auto_type bv = cn_init_36695;
__auto_type cn_init_36703 = rg[2]; __auto_type av = cn_init_36703;
__auto_type cn_init_36721 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_36721;
}
if(cn_cond(fl,12)){
goto cn_break_b290;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_36823 = m->xmm[0]; CN_U2 s = cn_init_36823;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_36911 = m->xmm[1]; CN_U2 s = cn_init_36911;
__auto_type cn_init_36921 = m->xmm[0]; __auto_type a = cn_init_36921;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_37000 = m->xmm[1]; CN_U2 s = cn_init_37000;
__auto_type cn_init_37010 = m->xmm[2]; __auto_type a = cn_init_37010;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_37089 = m->xmm[6]; CN_U2 s = cn_init_37089;
__auto_type cn_init_37099 = m->xmm[0]; __auto_type a = cn_init_37099;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_37146 = m->xmm[2]; CN_U2 s = cn_init_37146;
__auto_type cn_init_37156 = m->xmm[0]; __auto_type a = cn_init_37156;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_37239 = 0x8U; __auto_type bv = cn_init_37239;
__auto_type cn_init_37247 = rg[2]; __auto_type av = cn_init_37247;
__auto_type cn_init_37265 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_37265;
}
if(cn_cond(fl,12)){
goto cn_break_b254;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_37353 = m->xmm[0]; CN_U2 s = cn_init_37353;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_37441 = m->xmm[1]; CN_U2 s = cn_init_37441;
__auto_type cn_init_37451 = m->xmm[0]; __auto_type a = cn_init_37451;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_37530 = m->xmm[1]; CN_U2 s = cn_init_37530;
__auto_type cn_init_37540 = m->xmm[2]; __auto_type a = cn_init_37540;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_37619 = m->xmm[6]; CN_U2 s = cn_init_37619;
__auto_type cn_init_37629 = m->xmm[0]; __auto_type a = cn_init_37629;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_37676 = m->xmm[2]; CN_U2 s = cn_init_37676;
__auto_type cn_init_37686 = m->xmm[0]; __auto_type a = cn_init_37686;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_37769 = 0xaU; __auto_type bv = cn_init_37769;
__auto_type cn_init_37777 = rg[2]; __auto_type av = cn_init_37777;
__auto_type cn_init_37795 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_37795;
}
if(cn_cond(fl,12)){
goto cn_break_b290;
}
goto cn_break_b272;
}
cn_break_b254:;
{
__auto_type cn_init_37818 = 0x6U; __auto_type bv = cn_init_37818;
__auto_type cn_init_37826 = rg[2]; __auto_type av = cn_init_37826;
__auto_type cn_init_37844 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_37844;
}
if(cn_cond(fl,12)){
goto cn_break_b290;
}
}
cn_break_b272:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_37933 = m->xmm[0]; CN_U2 s = cn_init_37933;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_38021 = m->xmm[1]; CN_U2 s = cn_init_38021;
__auto_type cn_init_38031 = m->xmm[0]; __auto_type a = cn_init_38031;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_38110 = m->xmm[1]; CN_U2 s = cn_init_38110;
__auto_type cn_init_38120 = m->xmm[2]; __auto_type a = cn_init_38120;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_38199 = m->xmm[6]; CN_U2 s = cn_init_38199;
__auto_type cn_init_38209 = m->xmm[0]; __auto_type a = cn_init_38209;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_38256 = m->xmm[2]; CN_U2 s = cn_init_38256;
__auto_type cn_init_38266 = m->xmm[0]; __auto_type a = cn_init_38266;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b290:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b326;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_38452 = m->xmm[0]; CN_U2 s = cn_init_38452;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_38540 = m->xmm[1]; CN_U2 s = cn_init_38540;
__auto_type cn_init_38550 = m->xmm[0]; __auto_type a = cn_init_38550;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_38629 = m->xmm[1]; CN_U2 s = cn_init_38629;
__auto_type cn_init_38639 = m->xmm[2]; __auto_type a = cn_init_38639;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_38718 = m->xmm[6]; CN_U2 s = cn_init_38718;
__auto_type cn_init_38728 = m->xmm[0]; __auto_type a = cn_init_38728;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_38775 = m->xmm[2]; CN_U2 s = cn_init_38775;
__auto_type cn_init_38785 = m->xmm[0]; __auto_type a = cn_init_38785;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b326:;
{
__auto_type cn_init_38869 = 0x0U; __auto_type bv = cn_init_38869;
__auto_type cn_init_38877 = rg[1]; __auto_type av = cn_init_38877;
__auto_type cn_init_38895 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_38895;
}
if(cn_cond(fl,4)){
goto cn_break_b362;
}
{
__auto_type cn_init_38925 = m->xmm[0]; CN_U2 s = cn_init_38925;
__auto_type cn_init_38935 = m->xmm[0]; __auto_type a = cn_init_38935;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b362:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(m->xmm[1]=m->xmm[0]);
{
__auto_type cn_init_38993 = r10; uint64_t s = cn_init_38993;
__auto_type cn_init_39006 = m->xmm[0][0]; __auto_type a = cn_init_39006;
(m->xmm[0][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_39054 = m->xmm[0]; CN_U2 s = cn_init_39054;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_39087 = m->xmm[1]; CN_U2 s = cn_init_39087;
__auto_type cn_init_39097 = m->xmm[1]; __auto_type a = cn_init_39097;
(m->xmm[1]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_39134 = m->xmm[5]; CN_U2 s = cn_init_39134;
__auto_type cn_init_39144 = m->xmm[0]; __auto_type a = cn_init_39144;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b5;
}
cn_break_b51:;
{
__auto_type cn_init_39231 = 0x1U; __auto_type bv = cn_init_39231;
__auto_type cn_init_39239 = rg[3]; __auto_type av = cn_init_39239;
__auto_type cn_init_39257 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_39257;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b60;
}
(r12=m->xmm[0][1]);
{
__auto_type cn_init_39306 = m->xmm[1]; CN_U2 s = cn_init_39306;
(m->xmm[0][1]=s[0]);
}
(m->xmm[5]=m->xmm[0]);
{
__auto_type cn_init_39353 = m->xmm[0]; CN_U2 s = cn_init_39353;
__auto_type cn_init_39363 = m->xmm[0]; __auto_type a = cn_init_39363;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_39442 = m->xmm[0]; CN_U2 s = cn_init_39442;
__auto_type cn_init_39452 = m->xmm[0]; __auto_type a = cn_init_39452;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_39530 = m->xmm[0][0]; uint64_t s = cn_init_39530;
(m->xmm[0][0]=cn_bits(sqrt(cn_double(s))));
}
(r10=m->xmm[0][0]);
{
__auto_type cn_init_39576 = r12; uint64_t s = cn_init_39576;
(m->xmm[0][1]=s);
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100081f0U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_39639 = 0x0U; __auto_type bv = cn_init_39639;
__auto_type cn_init_39647 = rg[1]; __auto_type av = cn_init_39647;
__auto_type cn_init_39665 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_39665;
}
if(cn_cond(fl,4)){
goto cn_break_b111;
}
{
__auto_type cn_init_39695 = m->xmm[0]; CN_U2 s = cn_init_39695;
__auto_type cn_init_39705 = m->xmm[0]; __auto_type a = cn_init_39705;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b111:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_39801 = m->xmm[0]; CN_U2 s = cn_init_39801;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_39889 = m->xmm[1]; CN_U2 s = cn_init_39889;
__auto_type cn_init_39899 = m->xmm[0]; __auto_type a = cn_init_39899;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_39978 = m->xmm[1]; CN_U2 s = cn_init_39978;
__auto_type cn_init_39988 = m->xmm[2]; __auto_type a = cn_init_39988;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_40067 = m->xmm[6]; CN_U2 s = cn_init_40067;
__auto_type cn_init_40077 = m->xmm[0]; __auto_type a = cn_init_40077;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_40124 = m->xmm[2]; CN_U2 s = cn_init_40124;
__auto_type cn_init_40134 = m->xmm[0]; __auto_type a = cn_init_40134;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_40217 = 0x2U; __auto_type bv = cn_init_40217;
__auto_type cn_init_40225 = rg[2]; __auto_type av = cn_init_40225;
__auto_type cn_init_40243 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_40243;
}
if(cn_cond(fl,14)){
goto cn_break_b327;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_40276 = 0x4U; __auto_type bv = cn_init_40276;
__auto_type cn_init_40284 = rg[2]; __auto_type av = cn_init_40284;
__auto_type cn_init_40302 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_40302;
}
if(cn_cond(fl,12)){
goto cn_break_b291;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_40404 = m->xmm[0]; CN_U2 s = cn_init_40404;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_40492 = m->xmm[1]; CN_U2 s = cn_init_40492;
__auto_type cn_init_40502 = m->xmm[0]; __auto_type a = cn_init_40502;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_40581 = m->xmm[1]; CN_U2 s = cn_init_40581;
__auto_type cn_init_40591 = m->xmm[2]; __auto_type a = cn_init_40591;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_40670 = m->xmm[6]; CN_U2 s = cn_init_40670;
__auto_type cn_init_40680 = m->xmm[0]; __auto_type a = cn_init_40680;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_40727 = m->xmm[2]; CN_U2 s = cn_init_40727;
__auto_type cn_init_40737 = m->xmm[0]; __auto_type a = cn_init_40737;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_40820 = 0x8U; __auto_type bv = cn_init_40820;
__auto_type cn_init_40828 = rg[2]; __auto_type av = cn_init_40828;
__auto_type cn_init_40846 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_40846;
}
if(cn_cond(fl,12)){
goto cn_break_b255;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_40934 = m->xmm[0]; CN_U2 s = cn_init_40934;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_41022 = m->xmm[1]; CN_U2 s = cn_init_41022;
__auto_type cn_init_41032 = m->xmm[0]; __auto_type a = cn_init_41032;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_41111 = m->xmm[1]; CN_U2 s = cn_init_41111;
__auto_type cn_init_41121 = m->xmm[2]; __auto_type a = cn_init_41121;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_41200 = m->xmm[6]; CN_U2 s = cn_init_41200;
__auto_type cn_init_41210 = m->xmm[0]; __auto_type a = cn_init_41210;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_41257 = m->xmm[2]; CN_U2 s = cn_init_41257;
__auto_type cn_init_41267 = m->xmm[0]; __auto_type a = cn_init_41267;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_41350 = 0xaU; __auto_type bv = cn_init_41350;
__auto_type cn_init_41358 = rg[2]; __auto_type av = cn_init_41358;
__auto_type cn_init_41376 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_41376;
}
if(cn_cond(fl,12)){
goto cn_break_b291;
}
goto cn_break_b273;
}
cn_break_b255:;
{
__auto_type cn_init_41399 = 0x6U; __auto_type bv = cn_init_41399;
__auto_type cn_init_41407 = rg[2]; __auto_type av = cn_init_41407;
__auto_type cn_init_41425 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_41425;
}
if(cn_cond(fl,12)){
goto cn_break_b291;
}
}
cn_break_b273:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_41514 = m->xmm[0]; CN_U2 s = cn_init_41514;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_41602 = m->xmm[1]; CN_U2 s = cn_init_41602;
__auto_type cn_init_41612 = m->xmm[0]; __auto_type a = cn_init_41612;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_41691 = m->xmm[1]; CN_U2 s = cn_init_41691;
__auto_type cn_init_41701 = m->xmm[2]; __auto_type a = cn_init_41701;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_41780 = m->xmm[6]; CN_U2 s = cn_init_41780;
__auto_type cn_init_41790 = m->xmm[0]; __auto_type a = cn_init_41790;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_41837 = m->xmm[2]; CN_U2 s = cn_init_41837;
__auto_type cn_init_41847 = m->xmm[0]; __auto_type a = cn_init_41847;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b291:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b327;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_42033 = m->xmm[0]; CN_U2 s = cn_init_42033;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_42121 = m->xmm[1]; CN_U2 s = cn_init_42121;
__auto_type cn_init_42131 = m->xmm[0]; __auto_type a = cn_init_42131;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_42210 = m->xmm[1]; CN_U2 s = cn_init_42210;
__auto_type cn_init_42220 = m->xmm[2]; __auto_type a = cn_init_42220;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_42299 = m->xmm[6]; CN_U2 s = cn_init_42299;
__auto_type cn_init_42309 = m->xmm[0]; __auto_type a = cn_init_42309;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_42356 = m->xmm[2]; CN_U2 s = cn_init_42356;
__auto_type cn_init_42366 = m->xmm[0]; __auto_type a = cn_init_42366;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b327:;
{
__auto_type cn_init_42450 = 0x0U; __auto_type bv = cn_init_42450;
__auto_type cn_init_42458 = rg[1]; __auto_type av = cn_init_42458;
__auto_type cn_init_42476 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_42476;
}
if(cn_cond(fl,4)){
goto cn_break_b363;
}
{
__auto_type cn_init_42506 = m->xmm[0]; CN_U2 s = cn_init_42506;
__auto_type cn_init_42516 = m->xmm[0]; __auto_type a = cn_init_42516;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b363:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(m->xmm[1]=m->xmm[0]);
{
__auto_type cn_init_42574 = r10; uint64_t s = cn_init_42574;
__auto_type cn_init_42587 = m->xmm[0][0]; __auto_type a = cn_init_42587;
(m->xmm[0][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_42635 = m->xmm[0]; CN_U2 s = cn_init_42635;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_42668 = m->xmm[5]; CN_U2 s = cn_init_42668;
__auto_type cn_init_42678 = m->xmm[0]; __auto_type a = cn_init_42678;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_42757 = m->xmm[0]; CN_U2 s = cn_init_42757;
__auto_type cn_init_42767 = m->xmm[1]; __auto_type a = cn_init_42767;
(m->xmm[1]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_42804 = m->xmm[1]; CN_U2 s = cn_init_42804;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_42837 = m->xmm[1]; CN_U2 s = cn_init_42837;
__auto_type cn_init_42847 = m->xmm[1]; __auto_type a = cn_init_42847;
(m->xmm[1]=(CN_U2){a[1],s[1]});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b5;
}
cn_break_b60:;
(r12=m->xmm[0][0]);
{
__auto_type cn_init_42915 = m->xmm[1]; CN_U2 s = cn_init_42915;
(m->xmm[1][1]=s[0]);
}
{
__auto_type cn_init_42948 = m->xmm[1]; CN_U2 s = cn_init_42948;
__auto_type cn_init_42958 = m->xmm[0]; __auto_type a = cn_init_42958;
(m->xmm[0]=(CN_U2){a[1],s[1]});
}
(m->xmm[5]=m->xmm[0]);
{
__auto_type cn_init_43009 = m->xmm[0]; CN_U2 s = cn_init_43009;
__auto_type cn_init_43019 = m->xmm[0]; __auto_type a = cn_init_43019;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_43098 = m->xmm[0]; CN_U2 s = cn_init_43098;
__auto_type cn_init_43108 = m->xmm[0]; __auto_type a = cn_init_43108;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_43186 = m->xmm[0][0]; uint64_t s = cn_init_43186;
(m->xmm[0][0]=cn_bits(sqrt(cn_double(s))));
}
(r10=m->xmm[0][0]);
{
__auto_type cn_init_43232 = r12; uint64_t s = cn_init_43232;
(m->xmm[0][1]=s);
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008238U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_43295 = 0x0U; __auto_type bv = cn_init_43295;
__auto_type cn_init_43303 = rg[1]; __auto_type av = cn_init_43303;
__auto_type cn_init_43321 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_43321;
}
if(cn_cond(fl,4)){
goto cn_break_b112;
}
{
__auto_type cn_init_43351 = m->xmm[0]; CN_U2 s = cn_init_43351;
__auto_type cn_init_43361 = m->xmm[0]; __auto_type a = cn_init_43361;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b112:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_43457 = m->xmm[0]; CN_U2 s = cn_init_43457;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_43545 = m->xmm[1]; CN_U2 s = cn_init_43545;
__auto_type cn_init_43555 = m->xmm[0]; __auto_type a = cn_init_43555;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_43634 = m->xmm[1]; CN_U2 s = cn_init_43634;
__auto_type cn_init_43644 = m->xmm[2]; __auto_type a = cn_init_43644;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_43723 = m->xmm[6]; CN_U2 s = cn_init_43723;
__auto_type cn_init_43733 = m->xmm[0]; __auto_type a = cn_init_43733;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_43780 = m->xmm[2]; CN_U2 s = cn_init_43780;
__auto_type cn_init_43790 = m->xmm[0]; __auto_type a = cn_init_43790;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_43873 = 0x2U; __auto_type bv = cn_init_43873;
__auto_type cn_init_43881 = rg[2]; __auto_type av = cn_init_43881;
__auto_type cn_init_43899 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_43899;
}
if(cn_cond(fl,14)){
goto cn_break_b328;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_43932 = 0x4U; __auto_type bv = cn_init_43932;
__auto_type cn_init_43940 = rg[2]; __auto_type av = cn_init_43940;
__auto_type cn_init_43958 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_43958;
}
if(cn_cond(fl,12)){
goto cn_break_b292;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_44060 = m->xmm[0]; CN_U2 s = cn_init_44060;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_44148 = m->xmm[1]; CN_U2 s = cn_init_44148;
__auto_type cn_init_44158 = m->xmm[0]; __auto_type a = cn_init_44158;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_44237 = m->xmm[1]; CN_U2 s = cn_init_44237;
__auto_type cn_init_44247 = m->xmm[2]; __auto_type a = cn_init_44247;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_44326 = m->xmm[6]; CN_U2 s = cn_init_44326;
__auto_type cn_init_44336 = m->xmm[0]; __auto_type a = cn_init_44336;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_44383 = m->xmm[2]; CN_U2 s = cn_init_44383;
__auto_type cn_init_44393 = m->xmm[0]; __auto_type a = cn_init_44393;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_44476 = 0x8U; __auto_type bv = cn_init_44476;
__auto_type cn_init_44484 = rg[2]; __auto_type av = cn_init_44484;
__auto_type cn_init_44502 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_44502;
}
if(cn_cond(fl,12)){
goto cn_break_b256;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_44590 = m->xmm[0]; CN_U2 s = cn_init_44590;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_44678 = m->xmm[1]; CN_U2 s = cn_init_44678;
__auto_type cn_init_44688 = m->xmm[0]; __auto_type a = cn_init_44688;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_44767 = m->xmm[1]; CN_U2 s = cn_init_44767;
__auto_type cn_init_44777 = m->xmm[2]; __auto_type a = cn_init_44777;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_44856 = m->xmm[6]; CN_U2 s = cn_init_44856;
__auto_type cn_init_44866 = m->xmm[0]; __auto_type a = cn_init_44866;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_44913 = m->xmm[2]; CN_U2 s = cn_init_44913;
__auto_type cn_init_44923 = m->xmm[0]; __auto_type a = cn_init_44923;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_45006 = 0xaU; __auto_type bv = cn_init_45006;
__auto_type cn_init_45014 = rg[2]; __auto_type av = cn_init_45014;
__auto_type cn_init_45032 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_45032;
}
if(cn_cond(fl,12)){
goto cn_break_b292;
}
goto cn_break_b274;
}
cn_break_b256:;
{
__auto_type cn_init_45055 = 0x6U; __auto_type bv = cn_init_45055;
__auto_type cn_init_45063 = rg[2]; __auto_type av = cn_init_45063;
__auto_type cn_init_45081 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_45081;
}
if(cn_cond(fl,12)){
goto cn_break_b292;
}
}
cn_break_b274:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_45170 = m->xmm[0]; CN_U2 s = cn_init_45170;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_45258 = m->xmm[1]; CN_U2 s = cn_init_45258;
__auto_type cn_init_45268 = m->xmm[0]; __auto_type a = cn_init_45268;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_45347 = m->xmm[1]; CN_U2 s = cn_init_45347;
__auto_type cn_init_45357 = m->xmm[2]; __auto_type a = cn_init_45357;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_45436 = m->xmm[6]; CN_U2 s = cn_init_45436;
__auto_type cn_init_45446 = m->xmm[0]; __auto_type a = cn_init_45446;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_45493 = m->xmm[2]; CN_U2 s = cn_init_45493;
__auto_type cn_init_45503 = m->xmm[0]; __auto_type a = cn_init_45503;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b292:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b328;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_45689 = m->xmm[0]; CN_U2 s = cn_init_45689;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_45777 = m->xmm[1]; CN_U2 s = cn_init_45777;
__auto_type cn_init_45787 = m->xmm[0]; __auto_type a = cn_init_45787;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_45866 = m->xmm[1]; CN_U2 s = cn_init_45866;
__auto_type cn_init_45876 = m->xmm[2]; __auto_type a = cn_init_45876;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_45955 = m->xmm[6]; CN_U2 s = cn_init_45955;
__auto_type cn_init_45965 = m->xmm[0]; __auto_type a = cn_init_45965;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_46012 = m->xmm[2]; CN_U2 s = cn_init_46012;
__auto_type cn_init_46022 = m->xmm[0]; __auto_type a = cn_init_46022;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b328:;
{
__auto_type cn_init_46106 = 0x0U; __auto_type bv = cn_init_46106;
__auto_type cn_init_46114 = rg[1]; __auto_type av = cn_init_46114;
__auto_type cn_init_46132 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_46132;
}
if(cn_cond(fl,4)){
goto cn_break_b364;
}
{
__auto_type cn_init_46162 = m->xmm[0]; CN_U2 s = cn_init_46162;
__auto_type cn_init_46172 = m->xmm[0]; __auto_type a = cn_init_46172;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b364:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(m->xmm[1]=m->xmm[0]);
{
__auto_type cn_init_46230 = r10; uint64_t s = cn_init_46230;
__auto_type cn_init_46243 = m->xmm[1][0]; __auto_type a = cn_init_46243;
(m->xmm[1][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_46291 = m->xmm[1]; CN_U2 s = cn_init_46291;
(m->xmm[1][1]=s[0]);
}
{
__auto_type cn_init_46324 = m->xmm[5]; CN_U2 s = cn_init_46324;
__auto_type cn_init_46334 = m->xmm[1]; __auto_type a = cn_init_46334;
(m->xmm[1]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_46413 = m->xmm[0]; CN_U2 s = cn_init_46413;
__auto_type cn_init_46423 = m->xmm[0]; __auto_type a = cn_init_46423;
(m->xmm[0]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_46460 = m->xmm[1]; CN_U2 s = cn_init_46460;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_46493 = m->xmm[1]; CN_U2 s = cn_init_46493;
__auto_type cn_init_46503 = m->xmm[1]; __auto_type a = cn_init_46503;
(m->xmm[1]=(CN_U2){a[1],s[1]});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b5:;
{
__auto_type cn_init_46545 = 0x0U; __auto_type bv = cn_init_46545;
__auto_type cn_init_46562 = (((uint32_t)(((((v27>>32))&0xffffffffULL))))); __auto_type av = cn_init_46562;
__auto_type cn_init_46580 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_46580;
}
if(cn_cond(fl,4)){
goto cn_break_b7;
}
(rg[2]=((uint32_t)(((((v27>>0))&0xffffffffULL)))));
(rg[3]=((uint32_t)(((((v26>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x1000808bU))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_46680 = rg[1]; __auto_type bv = cn_init_46680;
__auto_type cn_init_46688 = rg[1]; __auto_type av = cn_init_46688;
__auto_type cn_init_46706 = cn_alu(&fl,Alu_Xor,av,bv,4); __auto_type r = cn_init_46706;
(rg[1]=r);
}
{
__auto_type cn_init_46720 = 0x6U; __auto_type bv = cn_init_46720;
__auto_type cn_init_46728 = rg[3]; __auto_type av = cn_init_46728;
__auto_type cn_init_46746 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_46746;
}
if(cn_cond(fl,12)){
goto cn_break_b16;
}
{
__auto_type cn_init_46765 = 0x1U; __auto_type bv = cn_init_46765;
__auto_type cn_init_46773 = rg[1]; __auto_type av = cn_init_46773;
__auto_type cn_init_46791 = cn_alu(&fl,Alu_Add,av,bv,4); __auto_type r = cn_init_46791;
(rg[1]=r);
}
{
__auto_type cn_init_46805 = 0x6U; __auto_type bv = cn_init_46805;
__auto_type cn_init_46813 = rg[3]; __auto_type av = cn_init_46813;
__auto_type cn_init_46831 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_46831;
(rg[3]=r);
}
}
cn_break_b16:;
{
__auto_type cn_init_46846 = 0x1U; __auto_type bv = cn_init_46846;
__auto_type cn_init_46854 = rg[3]; __auto_type av = cn_init_46854;
__auto_type cn_init_46872 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_46872;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b25;
}
(m->xmm[3]=m->xmm[0]);
{
__auto_type cn_init_46923 = m->xmm[3]; CN_U2 s = cn_init_46923;
__auto_type cn_init_46933 = m->xmm[3]; __auto_type a = cn_init_46933;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_47012 = m->xmm[3]; CN_U2 s = cn_init_47012;
__auto_type cn_init_47022 = m->xmm[3]; __auto_type a = cn_init_47022;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_47100 = m->xmm[3][0]; uint64_t s = cn_init_47100;
(m->xmm[5][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_47134 = v34; uint64_t s = cn_init_47134;
(m->xmm[4]=(CN_U2){s,0});
}
{
__auto_type cn_init_47164 = m->xmm[5][0]; uint64_t s = cn_init_47164;
__auto_type cn_init_47177 = m->xmm[4][0]; __auto_type a = cn_init_47177;
(m->xmm[4][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_47225 = m->xmm[4]; CN_U2 s = cn_init_47225;
(m->xmm[4][1]=s[0]);
}
{
__auto_type cn_init_47258 = m->xmm[5]; CN_U2 s = cn_init_47258;
(m->xmm[5][1]=s[0]);
}
(r10=m->xmm[1][0]);
{
__auto_type cn_init_47303 = m->xmm[4]; CN_U2 s = cn_init_47303;
__auto_type cn_init_47313 = m->xmm[0]; __auto_type a = cn_init_47313;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100080f2U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_47425 = 0x0U; __auto_type bv = cn_init_47425;
__auto_type cn_init_47433 = rg[1]; __auto_type av = cn_init_47433;
__auto_type cn_init_47451 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_47451;
}
if(cn_cond(fl,4)){
goto cn_break_b113;
}
{
__auto_type cn_init_47481 = m->xmm[0]; CN_U2 s = cn_init_47481;
__auto_type cn_init_47491 = m->xmm[0]; __auto_type a = cn_init_47491;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b113:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_47587 = m->xmm[0]; CN_U2 s = cn_init_47587;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_47675 = m->xmm[1]; CN_U2 s = cn_init_47675;
__auto_type cn_init_47685 = m->xmm[0]; __auto_type a = cn_init_47685;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_47764 = m->xmm[1]; CN_U2 s = cn_init_47764;
__auto_type cn_init_47774 = m->xmm[2]; __auto_type a = cn_init_47774;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_47853 = m->xmm[6]; CN_U2 s = cn_init_47853;
__auto_type cn_init_47863 = m->xmm[0]; __auto_type a = cn_init_47863;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_47910 = m->xmm[2]; CN_U2 s = cn_init_47910;
__auto_type cn_init_47920 = m->xmm[0]; __auto_type a = cn_init_47920;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_48003 = 0x2U; __auto_type bv = cn_init_48003;
__auto_type cn_init_48011 = rg[2]; __auto_type av = cn_init_48011;
__auto_type cn_init_48029 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_48029;
}
if(cn_cond(fl,14)){
goto cn_break_b329;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_48062 = 0x4U; __auto_type bv = cn_init_48062;
__auto_type cn_init_48070 = rg[2]; __auto_type av = cn_init_48070;
__auto_type cn_init_48088 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_48088;
}
if(cn_cond(fl,12)){
goto cn_break_b293;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_48190 = m->xmm[0]; CN_U2 s = cn_init_48190;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_48278 = m->xmm[1]; CN_U2 s = cn_init_48278;
__auto_type cn_init_48288 = m->xmm[0]; __auto_type a = cn_init_48288;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_48367 = m->xmm[1]; CN_U2 s = cn_init_48367;
__auto_type cn_init_48377 = m->xmm[2]; __auto_type a = cn_init_48377;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_48456 = m->xmm[6]; CN_U2 s = cn_init_48456;
__auto_type cn_init_48466 = m->xmm[0]; __auto_type a = cn_init_48466;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_48513 = m->xmm[2]; CN_U2 s = cn_init_48513;
__auto_type cn_init_48523 = m->xmm[0]; __auto_type a = cn_init_48523;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_48606 = 0x8U; __auto_type bv = cn_init_48606;
__auto_type cn_init_48614 = rg[2]; __auto_type av = cn_init_48614;
__auto_type cn_init_48632 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_48632;
}
if(cn_cond(fl,12)){
goto cn_break_b257;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_48720 = m->xmm[0]; CN_U2 s = cn_init_48720;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_48808 = m->xmm[1]; CN_U2 s = cn_init_48808;
__auto_type cn_init_48818 = m->xmm[0]; __auto_type a = cn_init_48818;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_48897 = m->xmm[1]; CN_U2 s = cn_init_48897;
__auto_type cn_init_48907 = m->xmm[2]; __auto_type a = cn_init_48907;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_48986 = m->xmm[6]; CN_U2 s = cn_init_48986;
__auto_type cn_init_48996 = m->xmm[0]; __auto_type a = cn_init_48996;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_49043 = m->xmm[2]; CN_U2 s = cn_init_49043;
__auto_type cn_init_49053 = m->xmm[0]; __auto_type a = cn_init_49053;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_49136 = 0xaU; __auto_type bv = cn_init_49136;
__auto_type cn_init_49144 = rg[2]; __auto_type av = cn_init_49144;
__auto_type cn_init_49162 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_49162;
}
if(cn_cond(fl,12)){
goto cn_break_b293;
}
goto cn_break_b275;
}
cn_break_b257:;
{
__auto_type cn_init_49185 = 0x6U; __auto_type bv = cn_init_49185;
__auto_type cn_init_49193 = rg[2]; __auto_type av = cn_init_49193;
__auto_type cn_init_49211 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_49211;
}
if(cn_cond(fl,12)){
goto cn_break_b293;
}
}
cn_break_b275:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_49300 = m->xmm[0]; CN_U2 s = cn_init_49300;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_49388 = m->xmm[1]; CN_U2 s = cn_init_49388;
__auto_type cn_init_49398 = m->xmm[0]; __auto_type a = cn_init_49398;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_49477 = m->xmm[1]; CN_U2 s = cn_init_49477;
__auto_type cn_init_49487 = m->xmm[2]; __auto_type a = cn_init_49487;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_49566 = m->xmm[6]; CN_U2 s = cn_init_49566;
__auto_type cn_init_49576 = m->xmm[0]; __auto_type a = cn_init_49576;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_49623 = m->xmm[2]; CN_U2 s = cn_init_49623;
__auto_type cn_init_49633 = m->xmm[0]; __auto_type a = cn_init_49633;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b293:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b329;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_49819 = m->xmm[0]; CN_U2 s = cn_init_49819;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_49907 = m->xmm[1]; CN_U2 s = cn_init_49907;
__auto_type cn_init_49917 = m->xmm[0]; __auto_type a = cn_init_49917;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_49996 = m->xmm[1]; CN_U2 s = cn_init_49996;
__auto_type cn_init_50006 = m->xmm[2]; __auto_type a = cn_init_50006;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_50085 = m->xmm[6]; CN_U2 s = cn_init_50085;
__auto_type cn_init_50095 = m->xmm[0]; __auto_type a = cn_init_50095;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_50142 = m->xmm[2]; CN_U2 s = cn_init_50142;
__auto_type cn_init_50152 = m->xmm[0]; __auto_type a = cn_init_50152;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b329:;
{
__auto_type cn_init_50236 = 0x0U; __auto_type bv = cn_init_50236;
__auto_type cn_init_50244 = rg[1]; __auto_type av = cn_init_50244;
__auto_type cn_init_50262 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_50262;
}
if(cn_cond(fl,4)){
goto cn_break_b365;
}
{
__auto_type cn_init_50292 = m->xmm[0]; CN_U2 s = cn_init_50292;
__auto_type cn_init_50302 = m->xmm[0]; __auto_type a = cn_init_50302;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b365:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_50346 = r10; uint64_t s = cn_init_50346;
(m->xmm[1]=(CN_U2){s,0});
}
{
__auto_type cn_init_50377 = m->xmm[5]; CN_U2 s = cn_init_50377;
__auto_type cn_init_50387 = m->xmm[0]; __auto_type a = cn_init_50387;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b7;
}
cn_break_b25:;
{
__auto_type cn_init_50474 = 0x1U; __auto_type bv = cn_init_50474;
__auto_type cn_init_50482 = rg[3]; __auto_type av = cn_init_50482;
__auto_type cn_init_50500 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_50500;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b34;
}
(r10=m->xmm[0][1]);
{
__auto_type cn_init_50549 = m->xmm[1]; CN_U2 s = cn_init_50549;
(m->xmm[0][1]=s[0]);
}
(m->xmm[3]=m->xmm[0]);
{
__auto_type cn_init_50596 = m->xmm[3]; CN_U2 s = cn_init_50596;
__auto_type cn_init_50606 = m->xmm[3]; __auto_type a = cn_init_50606;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_50685 = m->xmm[3]; CN_U2 s = cn_init_50685;
__auto_type cn_init_50695 = m->xmm[3]; __auto_type a = cn_init_50695;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_50773 = m->xmm[3][0]; uint64_t s = cn_init_50773;
(m->xmm[5][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_50807 = v34; uint64_t s = cn_init_50807;
(m->xmm[4]=(CN_U2){s,0});
}
{
__auto_type cn_init_50837 = m->xmm[5][0]; uint64_t s = cn_init_50837;
__auto_type cn_init_50850 = m->xmm[4][0]; __auto_type a = cn_init_50850;
(m->xmm[4][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_50898 = m->xmm[4]; CN_U2 s = cn_init_50898;
(m->xmm[4][1]=s[0]);
}
{
__auto_type cn_init_50931 = m->xmm[5]; CN_U2 s = cn_init_50931;
(m->xmm[5][1]=s[0]);
}
{
__auto_type cn_init_50964 = m->xmm[4]; CN_U2 s = cn_init_50964;
__auto_type cn_init_50974 = m->xmm[0]; __auto_type a = cn_init_50974;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008132U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_51086 = 0x0U; __auto_type bv = cn_init_51086;
__auto_type cn_init_51094 = rg[1]; __auto_type av = cn_init_51094;
__auto_type cn_init_51112 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_51112;
}
if(cn_cond(fl,4)){
goto cn_break_b114;
}
{
__auto_type cn_init_51142 = m->xmm[0]; CN_U2 s = cn_init_51142;
__auto_type cn_init_51152 = m->xmm[0]; __auto_type a = cn_init_51152;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b114:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_51248 = m->xmm[0]; CN_U2 s = cn_init_51248;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_51336 = m->xmm[1]; CN_U2 s = cn_init_51336;
__auto_type cn_init_51346 = m->xmm[0]; __auto_type a = cn_init_51346;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_51425 = m->xmm[1]; CN_U2 s = cn_init_51425;
__auto_type cn_init_51435 = m->xmm[2]; __auto_type a = cn_init_51435;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_51514 = m->xmm[6]; CN_U2 s = cn_init_51514;
__auto_type cn_init_51524 = m->xmm[0]; __auto_type a = cn_init_51524;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_51571 = m->xmm[2]; CN_U2 s = cn_init_51571;
__auto_type cn_init_51581 = m->xmm[0]; __auto_type a = cn_init_51581;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_51664 = 0x2U; __auto_type bv = cn_init_51664;
__auto_type cn_init_51672 = rg[2]; __auto_type av = cn_init_51672;
__auto_type cn_init_51690 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_51690;
}
if(cn_cond(fl,14)){
goto cn_break_b330;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_51723 = 0x4U; __auto_type bv = cn_init_51723;
__auto_type cn_init_51731 = rg[2]; __auto_type av = cn_init_51731;
__auto_type cn_init_51749 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_51749;
}
if(cn_cond(fl,12)){
goto cn_break_b294;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_51851 = m->xmm[0]; CN_U2 s = cn_init_51851;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_51939 = m->xmm[1]; CN_U2 s = cn_init_51939;
__auto_type cn_init_51949 = m->xmm[0]; __auto_type a = cn_init_51949;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_52028 = m->xmm[1]; CN_U2 s = cn_init_52028;
__auto_type cn_init_52038 = m->xmm[2]; __auto_type a = cn_init_52038;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_52117 = m->xmm[6]; CN_U2 s = cn_init_52117;
__auto_type cn_init_52127 = m->xmm[0]; __auto_type a = cn_init_52127;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_52174 = m->xmm[2]; CN_U2 s = cn_init_52174;
__auto_type cn_init_52184 = m->xmm[0]; __auto_type a = cn_init_52184;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_52267 = 0x8U; __auto_type bv = cn_init_52267;
__auto_type cn_init_52275 = rg[2]; __auto_type av = cn_init_52275;
__auto_type cn_init_52293 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_52293;
}
if(cn_cond(fl,12)){
goto cn_break_b258;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_52381 = m->xmm[0]; CN_U2 s = cn_init_52381;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_52469 = m->xmm[1]; CN_U2 s = cn_init_52469;
__auto_type cn_init_52479 = m->xmm[0]; __auto_type a = cn_init_52479;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_52558 = m->xmm[1]; CN_U2 s = cn_init_52558;
__auto_type cn_init_52568 = m->xmm[2]; __auto_type a = cn_init_52568;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_52647 = m->xmm[6]; CN_U2 s = cn_init_52647;
__auto_type cn_init_52657 = m->xmm[0]; __auto_type a = cn_init_52657;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_52704 = m->xmm[2]; CN_U2 s = cn_init_52704;
__auto_type cn_init_52714 = m->xmm[0]; __auto_type a = cn_init_52714;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_52797 = 0xaU; __auto_type bv = cn_init_52797;
__auto_type cn_init_52805 = rg[2]; __auto_type av = cn_init_52805;
__auto_type cn_init_52823 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_52823;
}
if(cn_cond(fl,12)){
goto cn_break_b294;
}
goto cn_break_b276;
}
cn_break_b258:;
{
__auto_type cn_init_52846 = 0x6U; __auto_type bv = cn_init_52846;
__auto_type cn_init_52854 = rg[2]; __auto_type av = cn_init_52854;
__auto_type cn_init_52872 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_52872;
}
if(cn_cond(fl,12)){
goto cn_break_b294;
}
}
cn_break_b276:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_52961 = m->xmm[0]; CN_U2 s = cn_init_52961;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_53049 = m->xmm[1]; CN_U2 s = cn_init_53049;
__auto_type cn_init_53059 = m->xmm[0]; __auto_type a = cn_init_53059;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_53138 = m->xmm[1]; CN_U2 s = cn_init_53138;
__auto_type cn_init_53148 = m->xmm[2]; __auto_type a = cn_init_53148;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_53227 = m->xmm[6]; CN_U2 s = cn_init_53227;
__auto_type cn_init_53237 = m->xmm[0]; __auto_type a = cn_init_53237;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_53284 = m->xmm[2]; CN_U2 s = cn_init_53284;
__auto_type cn_init_53294 = m->xmm[0]; __auto_type a = cn_init_53294;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b294:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b330;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_53480 = m->xmm[0]; CN_U2 s = cn_init_53480;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_53568 = m->xmm[1]; CN_U2 s = cn_init_53568;
__auto_type cn_init_53578 = m->xmm[0]; __auto_type a = cn_init_53578;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_53657 = m->xmm[1]; CN_U2 s = cn_init_53657;
__auto_type cn_init_53667 = m->xmm[2]; __auto_type a = cn_init_53667;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_53746 = m->xmm[6]; CN_U2 s = cn_init_53746;
__auto_type cn_init_53756 = m->xmm[0]; __auto_type a = cn_init_53756;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_53803 = m->xmm[2]; CN_U2 s = cn_init_53803;
__auto_type cn_init_53813 = m->xmm[0]; __auto_type a = cn_init_53813;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b330:;
{
__auto_type cn_init_53897 = 0x0U; __auto_type bv = cn_init_53897;
__auto_type cn_init_53905 = rg[1]; __auto_type av = cn_init_53905;
__auto_type cn_init_53923 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_53923;
}
if(cn_cond(fl,4)){
goto cn_break_b366;
}
{
__auto_type cn_init_53953 = m->xmm[0]; CN_U2 s = cn_init_53953;
__auto_type cn_init_53963 = m->xmm[0]; __auto_type a = cn_init_53963;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b366:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_54016 = m->xmm[5]; CN_U2 s = cn_init_54016;
__auto_type cn_init_54026 = m->xmm[0]; __auto_type a = cn_init_54026;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_54105 = m->xmm[0]; CN_U2 s = cn_init_54105;

(m->xmm[1]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_54184 = r10; uint64_t s = cn_init_54184;
(m->xmm[0][1]=s);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b7;
}
cn_break_b34:;
{
__auto_type cn_init_54222 = 0x1U; __auto_type bv = cn_init_54222;
__auto_type cn_init_54230 = rg[3]; __auto_type av = cn_init_54230;
__auto_type cn_init_54248 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_54248;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b43;
}
(r10=m->xmm[0][0]);
{
__auto_type cn_init_54297 = m->xmm[0]; CN_U2 s = cn_init_54297;
__auto_type cn_init_54307 = m->xmm[0]; __auto_type a = cn_init_54307;
(m->xmm[0]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_54344 = m->xmm[1]; CN_U2 s = cn_init_54344;
(m->xmm[0][1]=s[0]);
}
(m->xmm[3]=m->xmm[0]);
{
__auto_type cn_init_54391 = m->xmm[3]; CN_U2 s = cn_init_54391;
__auto_type cn_init_54401 = m->xmm[3]; __auto_type a = cn_init_54401;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_54480 = m->xmm[3]; CN_U2 s = cn_init_54480;
__auto_type cn_init_54490 = m->xmm[3]; __auto_type a = cn_init_54490;
(m->xmm[3]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_54568 = m->xmm[3][0]; uint64_t s = cn_init_54568;
(m->xmm[5][0]=cn_bits(sqrt(cn_double(s))));
}
{
__auto_type cn_init_54602 = v34; uint64_t s = cn_init_54602;
(m->xmm[4]=(CN_U2){s,0});
}
{
__auto_type cn_init_54632 = m->xmm[5][0]; uint64_t s = cn_init_54632;
__auto_type cn_init_54645 = m->xmm[4][0]; __auto_type a = cn_init_54645;
(m->xmm[4][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_54693 = m->xmm[4]; CN_U2 s = cn_init_54693;
(m->xmm[4][1]=s[0]);
}
{
__auto_type cn_init_54726 = m->xmm[5]; CN_U2 s = cn_init_54726;
(m->xmm[5][1]=s[0]);
}
{
__auto_type cn_init_54759 = m->xmm[4]; CN_U2 s = cn_init_54759;
__auto_type cn_init_54769 = m->xmm[0]; __auto_type a = cn_init_54769;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x1000817bU))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_54881 = 0x0U; __auto_type bv = cn_init_54881;
__auto_type cn_init_54889 = rg[1]; __auto_type av = cn_init_54889;
__auto_type cn_init_54907 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_54907;
}
if(cn_cond(fl,4)){
goto cn_break_b115;
}
{
__auto_type cn_init_54937 = m->xmm[0]; CN_U2 s = cn_init_54937;
__auto_type cn_init_54947 = m->xmm[0]; __auto_type a = cn_init_54947;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b115:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_55043 = m->xmm[0]; CN_U2 s = cn_init_55043;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_55131 = m->xmm[1]; CN_U2 s = cn_init_55131;
__auto_type cn_init_55141 = m->xmm[0]; __auto_type a = cn_init_55141;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_55220 = m->xmm[1]; CN_U2 s = cn_init_55220;
__auto_type cn_init_55230 = m->xmm[2]; __auto_type a = cn_init_55230;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_55309 = m->xmm[6]; CN_U2 s = cn_init_55309;
__auto_type cn_init_55319 = m->xmm[0]; __auto_type a = cn_init_55319;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_55366 = m->xmm[2]; CN_U2 s = cn_init_55366;
__auto_type cn_init_55376 = m->xmm[0]; __auto_type a = cn_init_55376;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_55459 = 0x2U; __auto_type bv = cn_init_55459;
__auto_type cn_init_55467 = rg[2]; __auto_type av = cn_init_55467;
__auto_type cn_init_55485 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_55485;
}
if(cn_cond(fl,14)){
goto cn_break_b331;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_55518 = 0x4U; __auto_type bv = cn_init_55518;
__auto_type cn_init_55526 = rg[2]; __auto_type av = cn_init_55526;
__auto_type cn_init_55544 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_55544;
}
if(cn_cond(fl,12)){
goto cn_break_b295;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_55646 = m->xmm[0]; CN_U2 s = cn_init_55646;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_55734 = m->xmm[1]; CN_U2 s = cn_init_55734;
__auto_type cn_init_55744 = m->xmm[0]; __auto_type a = cn_init_55744;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_55823 = m->xmm[1]; CN_U2 s = cn_init_55823;
__auto_type cn_init_55833 = m->xmm[2]; __auto_type a = cn_init_55833;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_55912 = m->xmm[6]; CN_U2 s = cn_init_55912;
__auto_type cn_init_55922 = m->xmm[0]; __auto_type a = cn_init_55922;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_55969 = m->xmm[2]; CN_U2 s = cn_init_55969;
__auto_type cn_init_55979 = m->xmm[0]; __auto_type a = cn_init_55979;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_56062 = 0x8U; __auto_type bv = cn_init_56062;
__auto_type cn_init_56070 = rg[2]; __auto_type av = cn_init_56070;
__auto_type cn_init_56088 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_56088;
}
if(cn_cond(fl,12)){
goto cn_break_b259;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_56176 = m->xmm[0]; CN_U2 s = cn_init_56176;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_56264 = m->xmm[1]; CN_U2 s = cn_init_56264;
__auto_type cn_init_56274 = m->xmm[0]; __auto_type a = cn_init_56274;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_56353 = m->xmm[1]; CN_U2 s = cn_init_56353;
__auto_type cn_init_56363 = m->xmm[2]; __auto_type a = cn_init_56363;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_56442 = m->xmm[6]; CN_U2 s = cn_init_56442;
__auto_type cn_init_56452 = m->xmm[0]; __auto_type a = cn_init_56452;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_56499 = m->xmm[2]; CN_U2 s = cn_init_56499;
__auto_type cn_init_56509 = m->xmm[0]; __auto_type a = cn_init_56509;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_56592 = 0xaU; __auto_type bv = cn_init_56592;
__auto_type cn_init_56600 = rg[2]; __auto_type av = cn_init_56600;
__auto_type cn_init_56618 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_56618;
}
if(cn_cond(fl,12)){
goto cn_break_b295;
}
goto cn_break_b277;
}
cn_break_b259:;
{
__auto_type cn_init_56641 = 0x6U; __auto_type bv = cn_init_56641;
__auto_type cn_init_56649 = rg[2]; __auto_type av = cn_init_56649;
__auto_type cn_init_56667 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_56667;
}
if(cn_cond(fl,12)){
goto cn_break_b295;
}
}
cn_break_b277:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_56756 = m->xmm[0]; CN_U2 s = cn_init_56756;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_56844 = m->xmm[1]; CN_U2 s = cn_init_56844;
__auto_type cn_init_56854 = m->xmm[0]; __auto_type a = cn_init_56854;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_56933 = m->xmm[1]; CN_U2 s = cn_init_56933;
__auto_type cn_init_56943 = m->xmm[2]; __auto_type a = cn_init_56943;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_57022 = m->xmm[6]; CN_U2 s = cn_init_57022;
__auto_type cn_init_57032 = m->xmm[0]; __auto_type a = cn_init_57032;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_57079 = m->xmm[2]; CN_U2 s = cn_init_57079;
__auto_type cn_init_57089 = m->xmm[0]; __auto_type a = cn_init_57089;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b295:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b331;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_57275 = m->xmm[0]; CN_U2 s = cn_init_57275;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_57363 = m->xmm[1]; CN_U2 s = cn_init_57363;
__auto_type cn_init_57373 = m->xmm[0]; __auto_type a = cn_init_57373;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_57452 = m->xmm[1]; CN_U2 s = cn_init_57452;
__auto_type cn_init_57462 = m->xmm[2]; __auto_type a = cn_init_57462;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_57541 = m->xmm[6]; CN_U2 s = cn_init_57541;
__auto_type cn_init_57551 = m->xmm[0]; __auto_type a = cn_init_57551;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_57598 = m->xmm[2]; CN_U2 s = cn_init_57598;
__auto_type cn_init_57608 = m->xmm[0]; __auto_type a = cn_init_57608;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b331:;
{
__auto_type cn_init_57692 = 0x0U; __auto_type bv = cn_init_57692;
__auto_type cn_init_57700 = rg[1]; __auto_type av = cn_init_57700;
__auto_type cn_init_57718 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_57718;
}
if(cn_cond(fl,4)){
goto cn_break_b367;
}
{
__auto_type cn_init_57748 = m->xmm[0]; CN_U2 s = cn_init_57748;
__auto_type cn_init_57758 = m->xmm[0]; __auto_type a = cn_init_57758;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b367:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_57811 = m->xmm[5]; CN_U2 s = cn_init_57811;
__auto_type cn_init_57821 = m->xmm[0]; __auto_type a = cn_init_57821;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_57900 = m->xmm[0]; CN_U2 s = cn_init_57900;

(m->xmm[1]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_57988 = m->xmm[0]; CN_U2 s = cn_init_57988;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_58012 = r10; uint64_t s = cn_init_58012;
(m->xmm[0][0]=s);
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b7;
}
cn_break_b43:;
{
__auto_type cn_init_58050 = 0x1U; __auto_type bv = cn_init_58050;
__auto_type cn_init_58058 = rg[3]; __auto_type av = cn_init_58058;
__auto_type cn_init_58076 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_58076;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b52;
}
(m->xmm[5]=m->xmm[0]);
{
__auto_type cn_init_58127 = m->xmm[0]; CN_U2 s = cn_init_58127;
__auto_type cn_init_58137 = m->xmm[0]; __auto_type a = cn_init_58137;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_58216 = m->xmm[0]; CN_U2 s = cn_init_58216;
__auto_type cn_init_58226 = m->xmm[0]; __auto_type a = cn_init_58226;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_58304 = m->xmm[0][0]; uint64_t s = cn_init_58304;
(m->xmm[0][0]=cn_bits(sqrt(cn_double(s))));
}
(r10=m->xmm[0][0]);
{
__auto_type cn_init_58359 = m->xmm[1]; CN_U2 s = cn_init_58359;
(m->xmm[0][1]=s[0]);
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100081afU))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_58425 = 0x0U; __auto_type bv = cn_init_58425;
__auto_type cn_init_58433 = rg[1]; __auto_type av = cn_init_58433;
__auto_type cn_init_58451 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_58451;
}
if(cn_cond(fl,4)){
goto cn_break_b116;
}
{
__auto_type cn_init_58481 = m->xmm[0]; CN_U2 s = cn_init_58481;
__auto_type cn_init_58491 = m->xmm[0]; __auto_type a = cn_init_58491;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b116:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_58587 = m->xmm[0]; CN_U2 s = cn_init_58587;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_58675 = m->xmm[1]; CN_U2 s = cn_init_58675;
__auto_type cn_init_58685 = m->xmm[0]; __auto_type a = cn_init_58685;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_58764 = m->xmm[1]; CN_U2 s = cn_init_58764;
__auto_type cn_init_58774 = m->xmm[2]; __auto_type a = cn_init_58774;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_58853 = m->xmm[6]; CN_U2 s = cn_init_58853;
__auto_type cn_init_58863 = m->xmm[0]; __auto_type a = cn_init_58863;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_58910 = m->xmm[2]; CN_U2 s = cn_init_58910;
__auto_type cn_init_58920 = m->xmm[0]; __auto_type a = cn_init_58920;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_59003 = 0x2U; __auto_type bv = cn_init_59003;
__auto_type cn_init_59011 = rg[2]; __auto_type av = cn_init_59011;
__auto_type cn_init_59029 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_59029;
}
if(cn_cond(fl,14)){
goto cn_break_b332;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_59062 = 0x4U; __auto_type bv = cn_init_59062;
__auto_type cn_init_59070 = rg[2]; __auto_type av = cn_init_59070;
__auto_type cn_init_59088 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_59088;
}
if(cn_cond(fl,12)){
goto cn_break_b296;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_59190 = m->xmm[0]; CN_U2 s = cn_init_59190;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_59278 = m->xmm[1]; CN_U2 s = cn_init_59278;
__auto_type cn_init_59288 = m->xmm[0]; __auto_type a = cn_init_59288;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_59367 = m->xmm[1]; CN_U2 s = cn_init_59367;
__auto_type cn_init_59377 = m->xmm[2]; __auto_type a = cn_init_59377;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_59456 = m->xmm[6]; CN_U2 s = cn_init_59456;
__auto_type cn_init_59466 = m->xmm[0]; __auto_type a = cn_init_59466;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_59513 = m->xmm[2]; CN_U2 s = cn_init_59513;
__auto_type cn_init_59523 = m->xmm[0]; __auto_type a = cn_init_59523;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_59606 = 0x8U; __auto_type bv = cn_init_59606;
__auto_type cn_init_59614 = rg[2]; __auto_type av = cn_init_59614;
__auto_type cn_init_59632 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_59632;
}
if(cn_cond(fl,12)){
goto cn_break_b260;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_59720 = m->xmm[0]; CN_U2 s = cn_init_59720;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_59808 = m->xmm[1]; CN_U2 s = cn_init_59808;
__auto_type cn_init_59818 = m->xmm[0]; __auto_type a = cn_init_59818;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_59897 = m->xmm[1]; CN_U2 s = cn_init_59897;
__auto_type cn_init_59907 = m->xmm[2]; __auto_type a = cn_init_59907;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_59986 = m->xmm[6]; CN_U2 s = cn_init_59986;
__auto_type cn_init_59996 = m->xmm[0]; __auto_type a = cn_init_59996;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_60043 = m->xmm[2]; CN_U2 s = cn_init_60043;
__auto_type cn_init_60053 = m->xmm[0]; __auto_type a = cn_init_60053;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_60136 = 0xaU; __auto_type bv = cn_init_60136;
__auto_type cn_init_60144 = rg[2]; __auto_type av = cn_init_60144;
__auto_type cn_init_60162 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_60162;
}
if(cn_cond(fl,12)){
goto cn_break_b296;
}
goto cn_break_b278;
}
cn_break_b260:;
{
__auto_type cn_init_60185 = 0x6U; __auto_type bv = cn_init_60185;
__auto_type cn_init_60193 = rg[2]; __auto_type av = cn_init_60193;
__auto_type cn_init_60211 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_60211;
}
if(cn_cond(fl,12)){
goto cn_break_b296;
}
}
cn_break_b278:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_60300 = m->xmm[0]; CN_U2 s = cn_init_60300;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_60388 = m->xmm[1]; CN_U2 s = cn_init_60388;
__auto_type cn_init_60398 = m->xmm[0]; __auto_type a = cn_init_60398;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_60477 = m->xmm[1]; CN_U2 s = cn_init_60477;
__auto_type cn_init_60487 = m->xmm[2]; __auto_type a = cn_init_60487;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_60566 = m->xmm[6]; CN_U2 s = cn_init_60566;
__auto_type cn_init_60576 = m->xmm[0]; __auto_type a = cn_init_60576;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_60623 = m->xmm[2]; CN_U2 s = cn_init_60623;
__auto_type cn_init_60633 = m->xmm[0]; __auto_type a = cn_init_60633;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b296:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b332;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_60819 = m->xmm[0]; CN_U2 s = cn_init_60819;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_60907 = m->xmm[1]; CN_U2 s = cn_init_60907;
__auto_type cn_init_60917 = m->xmm[0]; __auto_type a = cn_init_60917;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_60996 = m->xmm[1]; CN_U2 s = cn_init_60996;
__auto_type cn_init_61006 = m->xmm[2]; __auto_type a = cn_init_61006;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_61085 = m->xmm[6]; CN_U2 s = cn_init_61085;
__auto_type cn_init_61095 = m->xmm[0]; __auto_type a = cn_init_61095;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_61142 = m->xmm[2]; CN_U2 s = cn_init_61142;
__auto_type cn_init_61152 = m->xmm[0]; __auto_type a = cn_init_61152;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b332:;
{
__auto_type cn_init_61236 = 0x0U; __auto_type bv = cn_init_61236;
__auto_type cn_init_61244 = rg[1]; __auto_type av = cn_init_61244;
__auto_type cn_init_61262 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_61262;
}
if(cn_cond(fl,4)){
goto cn_break_b368;
}
{
__auto_type cn_init_61292 = m->xmm[0]; CN_U2 s = cn_init_61292;
__auto_type cn_init_61302 = m->xmm[0]; __auto_type a = cn_init_61302;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b368:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(m->xmm[1]=m->xmm[0]);
{
__auto_type cn_init_61360 = r10; uint64_t s = cn_init_61360;
__auto_type cn_init_61373 = m->xmm[0][0]; __auto_type a = cn_init_61373;
(m->xmm[0][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_61421 = m->xmm[0]; CN_U2 s = cn_init_61421;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_61454 = m->xmm[1]; CN_U2 s = cn_init_61454;
__auto_type cn_init_61464 = m->xmm[1]; __auto_type a = cn_init_61464;
(m->xmm[1]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_61501 = m->xmm[5]; CN_U2 s = cn_init_61501;
__auto_type cn_init_61511 = m->xmm[0]; __auto_type a = cn_init_61511;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b7;
}
cn_break_b52:;
{
__auto_type cn_init_61598 = 0x1U; __auto_type bv = cn_init_61598;
__auto_type cn_init_61606 = rg[3]; __auto_type av = cn_init_61606;
__auto_type cn_init_61624 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_61624;
(rg[3]=r);
}
if(cn_cond(fl,9)){
goto cn_break_b61;
}
(r12=m->xmm[0][1]);
{
__auto_type cn_init_61673 = m->xmm[1]; CN_U2 s = cn_init_61673;
(m->xmm[0][1]=s[0]);
}
(m->xmm[5]=m->xmm[0]);
{
__auto_type cn_init_61720 = m->xmm[0]; CN_U2 s = cn_init_61720;
__auto_type cn_init_61730 = m->xmm[0]; __auto_type a = cn_init_61730;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_61809 = m->xmm[0]; CN_U2 s = cn_init_61809;
__auto_type cn_init_61819 = m->xmm[0]; __auto_type a = cn_init_61819;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_61897 = m->xmm[0][0]; uint64_t s = cn_init_61897;
(m->xmm[0][0]=cn_bits(sqrt(cn_double(s))));
}
(r10=m->xmm[0][0]);
{
__auto_type cn_init_61943 = r12; uint64_t s = cn_init_61943;
(m->xmm[0][1]=s);
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x100081f0U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_62006 = 0x0U; __auto_type bv = cn_init_62006;
__auto_type cn_init_62014 = rg[1]; __auto_type av = cn_init_62014;
__auto_type cn_init_62032 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_62032;
}
if(cn_cond(fl,4)){
goto cn_break_b117;
}
{
__auto_type cn_init_62062 = m->xmm[0]; CN_U2 s = cn_init_62062;
__auto_type cn_init_62072 = m->xmm[0]; __auto_type a = cn_init_62072;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b117:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_62168 = m->xmm[0]; CN_U2 s = cn_init_62168;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_62256 = m->xmm[1]; CN_U2 s = cn_init_62256;
__auto_type cn_init_62266 = m->xmm[0]; __auto_type a = cn_init_62266;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_62345 = m->xmm[1]; CN_U2 s = cn_init_62345;
__auto_type cn_init_62355 = m->xmm[2]; __auto_type a = cn_init_62355;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_62434 = m->xmm[6]; CN_U2 s = cn_init_62434;
__auto_type cn_init_62444 = m->xmm[0]; __auto_type a = cn_init_62444;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_62491 = m->xmm[2]; CN_U2 s = cn_init_62491;
__auto_type cn_init_62501 = m->xmm[0]; __auto_type a = cn_init_62501;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_62584 = 0x2U; __auto_type bv = cn_init_62584;
__auto_type cn_init_62592 = rg[2]; __auto_type av = cn_init_62592;
__auto_type cn_init_62610 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_62610;
}
if(cn_cond(fl,14)){
goto cn_break_b333;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_62643 = 0x4U; __auto_type bv = cn_init_62643;
__auto_type cn_init_62651 = rg[2]; __auto_type av = cn_init_62651;
__auto_type cn_init_62669 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_62669;
}
if(cn_cond(fl,12)){
goto cn_break_b297;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_62771 = m->xmm[0]; CN_U2 s = cn_init_62771;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_62859 = m->xmm[1]; CN_U2 s = cn_init_62859;
__auto_type cn_init_62869 = m->xmm[0]; __auto_type a = cn_init_62869;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_62948 = m->xmm[1]; CN_U2 s = cn_init_62948;
__auto_type cn_init_62958 = m->xmm[2]; __auto_type a = cn_init_62958;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_63037 = m->xmm[6]; CN_U2 s = cn_init_63037;
__auto_type cn_init_63047 = m->xmm[0]; __auto_type a = cn_init_63047;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_63094 = m->xmm[2]; CN_U2 s = cn_init_63094;
__auto_type cn_init_63104 = m->xmm[0]; __auto_type a = cn_init_63104;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_63187 = 0x8U; __auto_type bv = cn_init_63187;
__auto_type cn_init_63195 = rg[2]; __auto_type av = cn_init_63195;
__auto_type cn_init_63213 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_63213;
}
if(cn_cond(fl,12)){
goto cn_break_b261;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_63301 = m->xmm[0]; CN_U2 s = cn_init_63301;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_63389 = m->xmm[1]; CN_U2 s = cn_init_63389;
__auto_type cn_init_63399 = m->xmm[0]; __auto_type a = cn_init_63399;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_63478 = m->xmm[1]; CN_U2 s = cn_init_63478;
__auto_type cn_init_63488 = m->xmm[2]; __auto_type a = cn_init_63488;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_63567 = m->xmm[6]; CN_U2 s = cn_init_63567;
__auto_type cn_init_63577 = m->xmm[0]; __auto_type a = cn_init_63577;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_63624 = m->xmm[2]; CN_U2 s = cn_init_63624;
__auto_type cn_init_63634 = m->xmm[0]; __auto_type a = cn_init_63634;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_63717 = 0xaU; __auto_type bv = cn_init_63717;
__auto_type cn_init_63725 = rg[2]; __auto_type av = cn_init_63725;
__auto_type cn_init_63743 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_63743;
}
if(cn_cond(fl,12)){
goto cn_break_b297;
}
goto cn_break_b279;
}
cn_break_b261:;
{
__auto_type cn_init_63766 = 0x6U; __auto_type bv = cn_init_63766;
__auto_type cn_init_63774 = rg[2]; __auto_type av = cn_init_63774;
__auto_type cn_init_63792 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_63792;
}
if(cn_cond(fl,12)){
goto cn_break_b297;
}
}
cn_break_b279:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_63881 = m->xmm[0]; CN_U2 s = cn_init_63881;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_63969 = m->xmm[1]; CN_U2 s = cn_init_63969;
__auto_type cn_init_63979 = m->xmm[0]; __auto_type a = cn_init_63979;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_64058 = m->xmm[1]; CN_U2 s = cn_init_64058;
__auto_type cn_init_64068 = m->xmm[2]; __auto_type a = cn_init_64068;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_64147 = m->xmm[6]; CN_U2 s = cn_init_64147;
__auto_type cn_init_64157 = m->xmm[0]; __auto_type a = cn_init_64157;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_64204 = m->xmm[2]; CN_U2 s = cn_init_64204;
__auto_type cn_init_64214 = m->xmm[0]; __auto_type a = cn_init_64214;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b297:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b333;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_64400 = m->xmm[0]; CN_U2 s = cn_init_64400;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_64488 = m->xmm[1]; CN_U2 s = cn_init_64488;
__auto_type cn_init_64498 = m->xmm[0]; __auto_type a = cn_init_64498;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_64577 = m->xmm[1]; CN_U2 s = cn_init_64577;
__auto_type cn_init_64587 = m->xmm[2]; __auto_type a = cn_init_64587;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_64666 = m->xmm[6]; CN_U2 s = cn_init_64666;
__auto_type cn_init_64676 = m->xmm[0]; __auto_type a = cn_init_64676;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_64723 = m->xmm[2]; CN_U2 s = cn_init_64723;
__auto_type cn_init_64733 = m->xmm[0]; __auto_type a = cn_init_64733;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b333:;
{
__auto_type cn_init_64817 = 0x0U; __auto_type bv = cn_init_64817;
__auto_type cn_init_64825 = rg[1]; __auto_type av = cn_init_64825;
__auto_type cn_init_64843 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_64843;
}
if(cn_cond(fl,4)){
goto cn_break_b369;
}
{
__auto_type cn_init_64873 = m->xmm[0]; CN_U2 s = cn_init_64873;
__auto_type cn_init_64883 = m->xmm[0]; __auto_type a = cn_init_64883;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b369:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(m->xmm[1]=m->xmm[0]);
{
__auto_type cn_init_64941 = r10; uint64_t s = cn_init_64941;
__auto_type cn_init_64954 = m->xmm[0][0]; __auto_type a = cn_init_64954;
(m->xmm[0][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_65002 = m->xmm[0]; CN_U2 s = cn_init_65002;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_65035 = m->xmm[5]; CN_U2 s = cn_init_65035;
__auto_type cn_init_65045 = m->xmm[0]; __auto_type a = cn_init_65045;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_65124 = m->xmm[0]; CN_U2 s = cn_init_65124;
__auto_type cn_init_65134 = m->xmm[1]; __auto_type a = cn_init_65134;
(m->xmm[1]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_65171 = m->xmm[1]; CN_U2 s = cn_init_65171;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_65204 = m->xmm[1]; CN_U2 s = cn_init_65204;
__auto_type cn_init_65214 = m->xmm[1]; __auto_type a = cn_init_65214;
(m->xmm[1]=(CN_U2){a[1],s[1]});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
goto cn_break_b7;
}
cn_break_b61:;
(r12=m->xmm[0][0]);
{
__auto_type cn_init_65282 = m->xmm[1]; CN_U2 s = cn_init_65282;
(m->xmm[1][1]=s[0]);
}
{
__auto_type cn_init_65315 = m->xmm[1]; CN_U2 s = cn_init_65315;
__auto_type cn_init_65325 = m->xmm[0]; __auto_type a = cn_init_65325;
(m->xmm[0]=(CN_U2){a[1],s[1]});
}
(m->xmm[5]=m->xmm[0]);
{
__auto_type cn_init_65376 = m->xmm[0]; CN_U2 s = cn_init_65376;
__auto_type cn_init_65386 = m->xmm[0]; __auto_type a = cn_init_65386;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_65465 = m->xmm[0]; CN_U2 s = cn_init_65465;
__auto_type cn_init_65475 = m->xmm[0]; __auto_type a = cn_init_65475;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
{
__auto_type cn_init_65553 = m->xmm[0][0]; uint64_t s = cn_init_65553;
(m->xmm[0][0]=cn_bits(sqrt(cn_double(s))));
}
(r10=m->xmm[0][0]);
{
__auto_type cn_init_65599 = r12; uint64_t s = cn_init_65599;
(m->xmm[0][1]=s);
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2011=(((s2011&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x10008238U))))&0xffffffffULL))<<0))));
{
__auto_type cn_init_65662 = 0x0U; __auto_type bv = cn_init_65662;
__auto_type cn_init_65670 = rg[1]; __auto_type av = cn_init_65670;
__auto_type cn_init_65688 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_65688;
}
if(cn_cond(fl,4)){
goto cn_break_b118;
}
{
__auto_type cn_init_65718 = m->xmm[0]; CN_U2 s = cn_init_65718;
__auto_type cn_init_65728 = m->xmm[0]; __auto_type a = cn_init_65728;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b118:;
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008268U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_65824 = m->xmm[0]; CN_U2 s = cn_init_65824;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_65912 = m->xmm[1]; CN_U2 s = cn_init_65912;
__auto_type cn_init_65922 = m->xmm[0]; __auto_type a = cn_init_65922;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_66001 = m->xmm[1]; CN_U2 s = cn_init_66001;
__auto_type cn_init_66011 = m->xmm[2]; __auto_type a = cn_init_66011;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_66090 = m->xmm[6]; CN_U2 s = cn_init_66090;
__auto_type cn_init_66100 = m->xmm[0]; __auto_type a = cn_init_66100;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_66147 = m->xmm[2]; CN_U2 s = cn_init_66147;
__auto_type cn_init_66157 = m->xmm[0]; __auto_type a = cn_init_66157;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_66240 = 0x2U; __auto_type bv = cn_init_66240;
__auto_type cn_init_66248 = rg[2]; __auto_type av = cn_init_66248;
__auto_type cn_init_66266 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_66266;
}
if(cn_cond(fl,14)){
goto cn_break_b334;
}
(m->xmm[3]=m->xmm[1]);
{
__auto_type cn_init_66299 = 0x4U; __auto_type bv = cn_init_66299;
__auto_type cn_init_66307 = rg[2]; __auto_type av = cn_init_66307;
__auto_type cn_init_66325 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_66325;
}
if(cn_cond(fl,12)){
goto cn_break_b298;
}
(m->xmm[4]=m->xmm[0]);
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008283U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_66427 = m->xmm[0]; CN_U2 s = cn_init_66427;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_66515 = m->xmm[1]; CN_U2 s = cn_init_66515;
__auto_type cn_init_66525 = m->xmm[0]; __auto_type a = cn_init_66525;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_66604 = m->xmm[1]; CN_U2 s = cn_init_66604;
__auto_type cn_init_66614 = m->xmm[2]; __auto_type a = cn_init_66614;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_66693 = m->xmm[6]; CN_U2 s = cn_init_66693;
__auto_type cn_init_66703 = m->xmm[0]; __auto_type a = cn_init_66703;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_66750 = m->xmm[2]; CN_U2 s = cn_init_66750;
__auto_type cn_init_66760 = m->xmm[0]; __auto_type a = cn_init_66760;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_66843 = 0x8U; __auto_type bv = cn_init_66843;
__auto_type cn_init_66851 = rg[2]; __auto_type av = cn_init_66851;
__auto_type cn_init_66869 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_66869;
}
if(cn_cond(fl,12)){
goto cn_break_b262;
}
(m->xmm[1]=m->xmm[0]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x10008291U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_66957 = m->xmm[0]; CN_U2 s = cn_init_66957;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_67045 = m->xmm[1]; CN_U2 s = cn_init_67045;
__auto_type cn_init_67055 = m->xmm[0]; __auto_type a = cn_init_67055;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_67134 = m->xmm[1]; CN_U2 s = cn_init_67134;
__auto_type cn_init_67144 = m->xmm[2]; __auto_type a = cn_init_67144;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_67223 = m->xmm[6]; CN_U2 s = cn_init_67223;
__auto_type cn_init_67233 = m->xmm[0]; __auto_type a = cn_init_67233;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_67280 = m->xmm[2]; CN_U2 s = cn_init_67280;
__auto_type cn_init_67290 = m->xmm[0]; __auto_type a = cn_init_67290;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
{
__auto_type cn_init_67373 = 0xaU; __auto_type bv = cn_init_67373;
__auto_type cn_init_67381 = rg[2]; __auto_type av = cn_init_67381;
__auto_type cn_init_67399 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_67399;
}
if(cn_cond(fl,12)){
goto cn_break_b298;
}
goto cn_break_b280;
}
cn_break_b262:;
{
__auto_type cn_init_67422 = 0x6U; __auto_type bv = cn_init_67422;
__auto_type cn_init_67430 = rg[2]; __auto_type av = cn_init_67430;
__auto_type cn_init_67448 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_67448;
}
if(cn_cond(fl,12)){
goto cn_break_b298;
}
}
cn_break_b280:;
(m->xmm[1]=m->xmm[4]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082a6U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_67537 = m->xmm[0]; CN_U2 s = cn_init_67537;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_67625 = m->xmm[1]; CN_U2 s = cn_init_67625;
__auto_type cn_init_67635 = m->xmm[0]; __auto_type a = cn_init_67635;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_67714 = m->xmm[1]; CN_U2 s = cn_init_67714;
__auto_type cn_init_67724 = m->xmm[2]; __auto_type a = cn_init_67724;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_67803 = m->xmm[6]; CN_U2 s = cn_init_67803;
__auto_type cn_init_67813 = m->xmm[0]; __auto_type a = cn_init_67813;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_67860 = m->xmm[2]; CN_U2 s = cn_init_67860;
__auto_type cn_init_67870 = m->xmm[0]; __auto_type a = cn_init_67870;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b298:;
cn_shift_reg_l(rg,&fl,Shift_Shr,2,1,4);
if(cn_cond(fl,3)){
goto cn_break_b334;
}
(m->xmm[1]=m->xmm[3]);
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<32))))|(((((((uint64_t)((0x100082b3U))))&0xffffffffULL))<<32))));
{
__auto_type cn_init_68056 = m->xmm[0]; CN_U2 s = cn_init_68056;

(m->xmm[2]=(CN_U2){(({__auto_type cn_arg=2; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=3; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32)),(({__auto_type cn_arg=0; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})|(({__auto_type cn_arg=1; ({(((s[((size_t)(((cn_arg>>1))))]>>((((cn_arg&1))*32))))&0xFFFFFFFF);});})<<32))});
}
{
__auto_type cn_init_68144 = m->xmm[1]; CN_U2 s = cn_init_68144;
__auto_type cn_init_68154 = m->xmm[0]; __auto_type a = cn_init_68154;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_68233 = m->xmm[1]; CN_U2 s = cn_init_68233;
__auto_type cn_init_68243 = m->xmm[2]; __auto_type a = cn_init_68243;
(m->xmm[2]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_68322 = m->xmm[6]; CN_U2 s = cn_init_68322;
__auto_type cn_init_68332 = m->xmm[0]; __auto_type a = cn_init_68332;
(m->xmm[0]=(CN_U2){(a[0]^s[0]),(a[1]^s[1])});
}
{
__auto_type cn_init_68379 = m->xmm[2]; CN_U2 s = cn_init_68379;
__auto_type cn_init_68389 = m->xmm[0]; __auto_type a = cn_init_68389;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])+cn_double(a[1])))),cn_bits(((cn_double(s[0])+cn_double(s[1]))))});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b334:;
{
__auto_type cn_init_68473 = 0x0U; __auto_type bv = cn_init_68473;
__auto_type cn_init_68481 = rg[1]; __auto_type av = cn_init_68481;
__auto_type cn_init_68499 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_68499;
}
if(cn_cond(fl,4)){
goto cn_break_b370;
}
{
__auto_type cn_init_68529 = m->xmm[0]; CN_U2 s = cn_init_68529;
__auto_type cn_init_68539 = m->xmm[0]; __auto_type a = cn_init_68539;
(m->xmm[0]=(CN_U2){a[1],s[0]});
}
}
cn_break_b370:;
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
(m->xmm[1]=m->xmm[0]);
{
__auto_type cn_init_68597 = r10; uint64_t s = cn_init_68597;
__auto_type cn_init_68610 = m->xmm[1][0]; __auto_type a = cn_init_68610;
(m->xmm[1][0]=cn_bits(((cn_double(a)/cn_double(s)))));
}
{
__auto_type cn_init_68658 = m->xmm[1]; CN_U2 s = cn_init_68658;
(m->xmm[1][1]=s[0]);
}
{
__auto_type cn_init_68691 = m->xmm[5]; CN_U2 s = cn_init_68691;
__auto_type cn_init_68701 = m->xmm[1]; __auto_type a = cn_init_68701;
(m->xmm[1]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_68780 = m->xmm[0]; CN_U2 s = cn_init_68780;
__auto_type cn_init_68790 = m->xmm[0]; __auto_type a = cn_init_68790;
(m->xmm[0]=(CN_U2){a[1],s[1]});
}
{
__auto_type cn_init_68827 = m->xmm[1]; CN_U2 s = cn_init_68827;
(m->xmm[0][1]=s[0]);
}
{
__auto_type cn_init_68860 = m->xmm[1]; CN_U2 s = cn_init_68860;
__auto_type cn_init_68870 = m->xmm[1]; __auto_type a = cn_init_68870;
(m->xmm[1]=(CN_U2){a[1],s[1]});
}
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b7:;
{
__auto_type cn_init_68914 = r11; uint64_t s = cn_init_68914;
(m->xmm[5]=(CN_U2){s,0});
}
{
__auto_type cn_init_68945 = m->xmm[5]; CN_U2 s = cn_init_68945;
(m->xmm[5][1]=s[0]);
}
{
__auto_type cn_init_68977 = m->xmm[5][0]; uint64_t s = cn_init_68977;
__auto_type cn_init_68990 = m->xmm[1][0]; __auto_type a = cn_init_68990;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
{
__auto_type cn_init_69038 = m->xmm[5]; CN_U2 s = cn_init_69038;
__auto_type cn_init_69048 = m->xmm[0]; __auto_type a = cn_init_69048;
(m->xmm[0]=(CN_U2){cn_bits(((cn_double(a[0])*cn_double(s[0])))),cn_bits(((cn_double(a[1])*cn_double(s[1]))))});
}
{
__auto_type cn_init_69134 = ((((((v25>>32))|((v26<<32))))&0xffffffffffffffffULL)); uint64_t s = cn_init_69134;
__auto_type cn_init_69147 = m->xmm[1][0]; __auto_type a = cn_init_69147;
(m->xmm[1][0]=cn_bits(((cn_double(a)*cn_double(s)))));
}
(r10=m->xmm[0][0]);
(r11=m->xmm[0][1]);
(r12=m->xmm[1][0]);
{
(rg[1]=((uint32_t)(((((s2012>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
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
cn_wr64(m,CN_REC+8*(10),r10);
cn_wr64(m,CN_REC+8*(11),r11);
cn_wr64(m,CN_REC+8*(12),r12);
cn_wr64u(m,0x10007ed0U,s2010);
cn_wr64u(m,0x10007ed8U,s2011);
cn_wr64u(m,0x10007ee0U,s2012);
cn_wr64u(m,0x10007ee8U,s2013);
cn_wr64u(m,0x10007ef0U,s2014);
(*regs)=rg; m->regs=rg; return 0;
}
