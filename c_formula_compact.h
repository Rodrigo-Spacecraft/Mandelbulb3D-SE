/* Generated direct C kernels; LGPL-2.1-or-later. */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-auto-type"
#pragma clang diagnostic ignored "-Wgnu-statement-expression"
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-parameter"
static inline Vec cf_pure_6ad79cbb14959655(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v15=cn_cell(vm,0);
uint64_t v16=cn_cell(vm,8);
uint64_t v17=cn_cell(vm,16);
uint64_t v18=cn_cell(vm,24);
uint64_t v19=cn_cell(vm,32);
uint64_t v20=cn_cell(vm,40);
uint64_t v21=cn_cell(vm,48);
uint64_t v22=cn_cell(vm,56);
uint64_t v23=cn_cell(vm,64);
uint64_t v24=cn_cell(vm,72);
uint64_t v25=cn_cell(vm,80);
uint64_t v26=cn_cell(vm,88);
uint64_t v27=cn_cell(vm,96);
uint64_t v28=cn_cell(vm,104);
uint64_t v29=cn_cell(vm,112);
uint64_t v30=cn_cell(vm,120);

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
{
__auto_type cn_init_628 = 0x7fffffffU; __auto_type v = cn_init_628;
(rg[0]=v);
}
{
__auto_type cn_init_645 = rg[0]; __auto_type bv = cn_init_645;
__auto_type cn_init_662 = (((uint32_t)(((((r5>>32))&0xffffffffULL))))); __auto_type av = cn_init_662;
__auto_type cn_init_680 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_680;
(r5=(((r5&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_719 = rg[0]; __auto_type bv = cn_init_719;
__auto_type cn_init_736 = (((uint32_t)(((((r4>>32))&0xffffffffULL))))); __auto_type av = cn_init_736;
__auto_type cn_init_754 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_754;
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_793 = rg[0]; __auto_type bv = cn_init_793;
__auto_type cn_init_810 = (((uint32_t)(((((r3>>32))&0xffffffffULL))))); __auto_type av = cn_init_810;
__auto_type cn_init_828 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_828;
(r3=(((r3&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_929 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_929;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_977 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_977;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1040 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1040;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1103 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1103;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1151 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1151;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1214 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1214;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1276 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1276;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1323 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1323;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1385 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1385;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_1456 = 0x41U; __auto_type bv = cn_init_1456;
__auto_type cn_init_1469 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1469;
__auto_type cn_init_1487 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1487;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
cn_swap(f,2,1);
}
cn_break_b2:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_1566 = 0x41U; __auto_type bv = cn_init_1566;
__auto_type cn_init_1579 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1579;
__auto_type cn_init_1597 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1597;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
cn_swap(f,2,0);
}
cn_break_b4:;
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_1685 = 0x41U; __auto_type bv = cn_init_1685;
__auto_type cn_init_1698 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1698;
__auto_type cn_init_1716 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1716;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
cn_swap(f,2,0);
}
cn_break_b6:;
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_1808 = cn_double(v30); __auto_type v = cn_init_1808;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_1832 = cn_double(v16); __auto_type v = cn_init_1832;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
(f[0]=(f[1]-f[0]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_1906 = cn_double(v30); __auto_type v = cn_init_1906;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_1930 = cn_double(v17); __auto_type v = cn_init_1930;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
(f[1]=(f[1]+f[0]));
(f[1]=fabs(f[1]));
(f[2]=cn_double(r3));
(f[2]=(f[2]-f[0]));
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_2047 = cn_double(r3); __auto_type v = cn_init_2047;
(f[2]=(f[2]-v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_2081 = 0x0U; __auto_type bv = cn_init_2081;
__auto_type cn_init_2098 = (((uint32_t)(((((v15>>32))&0xffffffffULL))))); __auto_type av = cn_init_2098;
__auto_type cn_init_2116 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2116;
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[1]=fabs(f[1]));
}
cn_break_b8:;
(r3=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(r5));
(f[1]=cn_double(r3));
(f[2]=cn_double(r4));
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
(f[3]=f[1]);
{
__auto_type cn_init_2485 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2485;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_2533 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2533;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2596 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2596;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_2659 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2659;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_2707 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2707;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2770 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2770;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_2832 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2832;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_2879 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2879;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2941 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2941;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(v30));
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[3]-f[4]));
(f[4]=f[3]);
(f[5]=f[4]);
{
__auto_type cn_init_3039 = cn_double(v29); __auto_type v = cn_init_3039;
(f[5]=(f[5]*v));
}
(f[1]=(f[1]-f[5]));
{
__auto_type cn_init_3078 = cn_double(v28); __auto_type v = cn_init_3078;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]-f[4]));
{
__auto_type cn_init_3117 = cn_double(v27); __auto_type v = cn_init_3117;
(f[3]=(f[3]*v));
}
(f[0]=(f[0]-f[3]));
(f[3]=f[3]);
(f[3]=cn_double(v30));
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[3]));
(r6=cn_bits(f[4]));
(f[0]=(f[0]*f[3]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
(f[3]=f[3]);
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_09c020b05d5686d9(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v16=cn_cell(vm,0);
uint64_t v17=cn_cell(vm,8);
uint64_t v18=cn_cell(vm,16);
uint64_t v19=cn_cell(vm,24);
uint64_t v20=cn_cell(vm,32);
uint64_t v21=cn_cell(vm,40);
uint64_t v22=cn_cell(vm,48);
uint64_t v23=cn_cell(vm,56);
uint64_t v24=cn_cell(vm,64);
uint64_t v25=cn_cell(vm,72);
uint64_t v26=cn_cell(vm,80);
uint64_t v27=cn_cell(vm,88);
uint64_t v28=cn_cell(vm,96);
uint64_t v29=cn_cell(vm,104);
uint64_t v30=cn_cell(vm,112);
uint64_t v31=cn_cell(vm,120);

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
__auto_type cn_init_619 = 0x7fffffffU; __auto_type v = cn_init_619;
(rg[0]=v);
}
{
__auto_type cn_init_636 = rg[0]; __auto_type bv = cn_init_636;
__auto_type cn_init_653 = (((uint32_t)(((((r5>>32))&0xffffffffULL))))); __auto_type av = cn_init_653;
__auto_type cn_init_671 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_671;
(r5=(((r5&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_710 = rg[0]; __auto_type bv = cn_init_710;
__auto_type cn_init_727 = (((uint32_t)(((((r4>>32))&0xffffffffULL))))); __auto_type av = cn_init_727;
__auto_type cn_init_745 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_745;
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_784 = rg[0]; __auto_type bv = cn_init_784;
__auto_type cn_init_801 = (((uint32_t)(((((r3>>32))&0xffffffffULL))))); __auto_type av = cn_init_801;
__auto_type cn_init_819 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_819;
(r3=(((r3&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_920 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_920;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_968 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_968;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1031 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1031;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1094 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1094;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1142 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1142;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1205 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1205;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1267 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1267;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1314 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1314;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1376 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1376;
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
(f[3]=cn_double(v17));
(f[3]=(f[3]-f[1]));
(f[3]=fabs(f[3]));
cn_swap(f,3,1);
(f[3]=f[3]);
{
__auto_type cn_init_1724 = cn_double(v16); __auto_type v = cn_init_1724;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[3]=f[1]);
{
__auto_type cn_init_1786 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1786;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_1834 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1834;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1897 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1897;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_1960 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1960;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_2008 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2008;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2071 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2071;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_2133 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2133;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_2180 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2180;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2242 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2242;
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
__auto_type cn_init_2423 = cn_double(v29); __auto_type v = cn_init_2423;
(f[5]=(f[5]*v));
}
(f[1]=(f[1]-f[5]));
{
__auto_type cn_init_2462 = cn_double(v28); __auto_type v = cn_init_2462;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]-f[4]));
{
__auto_type cn_init_2501 = cn_double(v27); __auto_type v = cn_init_2501;
(f[3]=(f[3]*v));
}
(f[4]=f[3]);
{
__auto_type cn_init_2535 = cn_double(v31); __auto_type v = cn_init_2535;
(f[4]=(f[4]*v));
}
(fsw=cn_compare(f[4],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
{
__auto_type cn_init_2591 = 0x41U; __auto_type bv = cn_init_2591;
__auto_type cn_init_2604 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2604;
__auto_type cn_init_2622 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2622;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[0]=(f[0]-f[3]));
}
cn_break_b8:;
(f[3]=f[3]);
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_d696fec44725d3b1(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v25=cn_cell(vm,0);
uint64_t v26=cn_cell(vm,8);
uint64_t v27=cn_cell(vm,16);
uint64_t v28=cn_cell(vm,24);
uint64_t v29=cn_cell(vm,32);
uint64_t v30=cn_cell(vm,40);

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
__auto_type cn_init_585 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_585;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_633 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_633;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_696 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_696;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_759 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_759;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_807 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_807;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_870 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_870;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_932 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_932;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_979 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_979;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1041 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1041;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(f[3]=f[2]);
{
__auto_type cn_init_1106 = cn_double(((((((v25>>32))|((v26<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1106;
(f[3]=(f[3]+v));
}
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_1170 = cn_double(((((((v25>>32))|((v26<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_1170;
(f[4]=(f[4]-v));
}
(f[4]=fabs(f[4]));
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[2]=(f[2]-f[3]));
(f[2]=-f[2]);
(f[3]=f[2]);
{
__auto_type cn_init_1284 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1284;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1332 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1332;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1395 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1395;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1458 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1458;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1506 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1506;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1569 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1569;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1631 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1631;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1678 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1678;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1740 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1740;
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_0202689ab0f2cd69(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);
uint64_t v32=cn_cell(vm,48);
uint64_t v33=cn_cell(vm,56);

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
__auto_type cn_init_620 = cn_double(v30); __auto_type v = cn_init_620;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_667 = cn_double(v29); __auto_type v = cn_init_667;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_714 = cn_double(v28); __auto_type v = cn_init_714;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
{
__auto_type cn_init_761 = cn_double(v27); __auto_type v = cn_init_761;
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
{
__auto_type cn_init_975 = 0x41U; __auto_type bv = cn_init_975;
__auto_type cn_init_988 = cn_reg_get(rg,4,1); __auto_type av = cn_init_988;
__auto_type cn_init_1006 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1006;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,2)){
goto cn_break_b2;
}
(f[1]=cn_double(r3));
{
__auto_type cn_tuple_1061_0 = sin(f[1]);
__auto_type cn_tuple_1061_1 = cos(f[1]);
__auto_type s = cn_tuple_1061_0;
__auto_type c = cn_tuple_1061_1;
(f[1]=s);
(f[2]=c);
(fsw&=~0x0400);
}
(f[3]=f[0]);
(f[4]=cn_double(0x3ff71547652b82fe));
(f[3]=(f[3]*f[4]));
(f[4]=cn_double(0x3ff0000000000000));
(f[5]=f[3]);
{
__auto_type cn_tuple_1160_0 = f[5];
__auto_type cn_tuple_1160_1 = f[4];
__auto_type x = cn_tuple_1160_0;
__auto_type y = cn_tuple_1160_1;
__auto_type cn_init_1189 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1189;
(f[5]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1221 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1221;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[5]=(exp2(f[5])-1.0));
(f[4]=(f[4]+f[5]));
(f[4]*=exp2(trunc(f[3])));
cn_swap(f,4,3);
(f[4]=f[4]);
(f[4]=f[3]);
(f[5]=cn_double(0x3ff0000000000000));
(f[6]=f[4]);
(f[5]=(f[5]/f[6]));
(f[5]=-f[5]);
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_1424 = cn_double(v32); __auto_type v = cn_init_1424;
(f[4]=(f[4]*v));
}
(f[5]=f[3]);
(f[6]=cn_double(0x3ff0000000000000));
(f[7]=f[5]);
(f[6]=(f[6]/f[7]));
(f[5]=(f[5]+f[6]));
{
__auto_type cn_init_1510 = cn_double(v32); __auto_type v = cn_init_1510;
(f[5]=(f[5]*v));
}
(f[3]=f[5]);
(f[5]=f[1]);
(f[5]=(f[5]*f[3]));
(r3=cn_bits(f[5]));
(f[5]=f[2]);
(f[5]=(f[5]*f[4]));
(f[5]=(f[5]/f[0]));
(f[4]=f[5]);
(f[3]=f[4]);
(f[2]=f[3]);
(f[1]=f[2]);
(f[0]=f[1]);
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[0]));
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[0]));
(r5=cn_bits(f[1]));
(f[1]=cn_double(r6));
(f[1]=(f[1]*f[0]));
(r6=cn_bits(f[1]));
(f[0]=f[0]);
(f[7]=f[7]);
(f=(CN_D8){f[7],f[0],f[1],f[2],f[3],f[4],f[5],f[6]});
goto cn_break_b3;
}
cn_break_b2:;
(f[1]=cn_double(r3));
(f[1]=sin(f[1]));
(fsw&=~0x0400);
(r3=cn_bits(f[1]));
(f[0]=f[0]);
}
cn_break_b3:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_1917 = cn_double(v26); __auto_type v = cn_init_1917;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1964 = cn_double(v26); __auto_type v = cn_init_1964;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_2011 = cn_double(v26); __auto_type v = cn_init_2011;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
{
__auto_type cn_init_2058 = cn_double(v26); __auto_type v = cn_init_2058;
(f[0]=(f[0]*v));
}
(r6=cn_bits(f[0]));
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_03738db42599e61c(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);
uint64_t v32=cn_cell(vm,48);

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
__auto_type cn_init_604 = cn_double(v30); __auto_type v = cn_init_604;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_640 = cn_double(v29); __auto_type v = cn_init_640;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_702 = cn_double(v28); __auto_type v = cn_init_702;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r6));
{
__auto_type cn_init_764 = cn_double(v27); __auto_type v = cn_init_764;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r3));
{
__auto_type cn_init_826 = cn_double(v29); __auto_type v = cn_init_826;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r4));
{
__auto_type cn_init_862 = cn_double(v30); __auto_type v = cn_init_862;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r5));
{
__auto_type cn_init_913 = cn_double(v27); __auto_type v = cn_init_913;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r6));
{
__auto_type cn_init_964 = cn_double(v28); __auto_type v = cn_init_964;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r3));
{
__auto_type cn_init_1026 = cn_double(v28); __auto_type v = cn_init_1026;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r4));
{
__auto_type cn_init_1062 = cn_double(v27); __auto_type v = cn_init_1062;
(f[3]=(f[3]*v));
}
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r5));
{
__auto_type cn_init_1124 = cn_double(v30); __auto_type v = cn_init_1124;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r6));
{
__auto_type cn_init_1175 = cn_double(v29); __auto_type v = cn_init_1175;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
{
__auto_type cn_init_1226 = cn_double(v27); __auto_type v = cn_init_1226;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r4));
{
__auto_type cn_init_1262 = cn_double(v28); __auto_type v = cn_init_1262;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r5));
{
__auto_type cn_init_1313 = cn_double(v29); __auto_type v = cn_init_1313;
(f[4]=(f[4]*v));
}
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r6));
{
__auto_type cn_init_1375 = cn_double(v30); __auto_type v = cn_init_1375;
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
__auto_type cn_tuple_1599_0 = sin(f[1]);
__auto_type cn_tuple_1599_1 = cos(f[1]);
__auto_type s = cn_tuple_1599_0;
__auto_type c = cn_tuple_1599_1;
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
__auto_type cn_tuple_1700_0 = f[5];
__auto_type cn_tuple_1700_1 = f[4];
__auto_type x = cn_tuple_1700_0;
__auto_type y = cn_tuple_1700_1;
__auto_type cn_init_1729 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_1729;
(f[5]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_1761 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_1761;
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
__auto_type cn_init_1996 = 0x41U; __auto_type bv = cn_init_1996;
__auto_type cn_init_2009 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2009;
__auto_type cn_init_2027 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2027;
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
(f[0]=cn_double(r6));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r3));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[1]=cn_double(r3));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r3));
(f[3]=cn_double(0x3ff0000000000000));
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
(f[1]=(f[1]*f[2]));
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r6));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r3));
(f[3]=cn_double(0x3ff0000000000000));
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_2710 = cn_double(r4); __auto_type v = cn_init_2710;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r4));
(f[4]=cn_double(r3));
(f[5]=cn_double(0x3ff0000000000000));
(f[5]=-f[5]);
(f[4]=(f[4]+f[5]));
(f[3]=(f[3]*f[4]));
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_2876 = cn_double(r5); __auto_type v = cn_init_2876;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r3));
(f[5]=cn_double(0x3ff0000000000000));
(f[5]=-f[5]);
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_2950 = cn_double(r5); __auto_type v = cn_init_2950;
(f[4]=(f[4]*v));
}
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
(f[5]=cn_double(0x3ff0000000000000));
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_3039 = cn_double(r6); __auto_type v = cn_init_3039;
(f[4]=(f[4]*v));
}
(f[5]=cn_double(r3));
(f[6]=cn_double(0x3ff0000000000000));
(f[6]=-f[6]);
(f[5]=(f[5]+f[6]));
{
__auto_type cn_init_3113 = cn_double(r6); __auto_type v = cn_init_3113;
(f[5]=(f[5]*v));
}
(f[5]=-f[5]);
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
(f[5]=(f[5]*f[1]));
{
__auto_type cn_init_3188 = cn_double(v26); __auto_type v = cn_init_3188;
(f[5]=(f[5]*v));
}
(r3=cn_bits(f[5]));
(f[5]=f[0]);
(f[5]=(f[5]*f[2]));
{
__auto_type cn_init_3248 = cn_double(v26); __auto_type v = cn_init_3248;
(f[5]=(f[5]*v));
}
(r4=cn_bits(f[5]));
(f[5]=f[0]);
(f[5]=(f[5]*f[3]));
{
__auto_type cn_init_3308 = cn_double(v26); __auto_type v = cn_init_3308;
(f[5]=(f[5]*v));
}
(r5=cn_bits(f[5]));
(f[5]=f[0]);
(f[5]=(f[5]*f[4]));
{
__auto_type cn_init_3368 = cn_double(v26); __auto_type v = cn_init_3368;
(f[5]=(f[5]*v));
}
(r6=cn_bits(f[5]));
(f[4]=f[4]);
(f[3]=f[3]);
(f[2]=f[2]);
(f[1]=f[1]);
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_04c5648d94adc5e4(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=-f[0]);
(f[1]=cn_double(v26));
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(f[1]=cn_double(r3));
(f[1]=fabs(f[1]));
(f[1]=(f[1]/f[0]));
(f[2]=cn_double(v27));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_767 = cn_double(v30); __auto_type v = cn_init_767;
(f[1]=(f[1]-v));
}
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
(f[1]=(f[1]/f[0]));
(f[2]=cn_double(v27));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_870 = cn_double(v29); __auto_type v = cn_init_870;
(f[1]=(f[1]-v));
}
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[1]=fabs(f[1]));
cn_swap(f,1,0);
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(v27));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_982 = cn_double(v28); __auto_type v = cn_init_982;
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_069ac184d3b6d59b(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

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
(f[0]=-f[0]);
{
__auto_type cn_init_349 = cn_double(v30); __auto_type v = cn_init_349;
(f[0]=(f[0]+v));
}
(f[0]=fabs(f[0]));
(f[1]=cn_double(r4));
(f[1]=cos(f[1]));
(fsw&=~0x0400);
(f[1]=fabs(f[1]));
(f[0]=(f[0]*f[1]));
(r3=cn_bits(f[0]));
(f[1]=cn_double(r4));
(f[1]=tan(f[1]));
(f[2]=1.0);
(fsw&=~0x0400);
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]*f[1]));
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
return (Vec){cn_double(r3),cn_double(r4),z.z};
}
static inline Vec cf_pure_06b6f1ba8ace3036(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2014=UINT64_C(0xfffffff000000000);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(f[0]=cn_double(r4));
(f[0]=-f[0]);
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=-f[0]);
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
(f[0]=-f[0]);
(r6=cn_bits(f[0]));
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}

cn_break_body:;
*fourth=cn_double(r6);return (Vec){z.x,cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_070a62f7d5d36334(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v28=cn_cell(vm,0);
uint64_t v29=cn_cell(vm,8);
uint64_t v30=cn_cell(vm,16);

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
(f[0]=cn_double(v28));
(f[1]=cn_double(v29));
(f[2]=cn_double(v30));
(f[3]=cn_double(r5));
(f[4]=cn_double(r4));
(f[5]=cn_double(r3));
(f[6]=f[5]);
(f[6]=(f[6]*f[2]));
(f[7]=f[4]);
(f[7]=(f[7]*f[1]));
(f[6]=(f[6]+f[7]));
(f[7]=f[3]);
(f[7]=(f[7]*f[0]));
(f[6]=(f[6]+f[7]));
(f[6]=(f[6]+f[6]));
(f[2]=(f[2]*f[6]));
(f[1]=(f[1]*f[6]));
(f[0]=(f[0]*f[6]));
(f[2]=(f[5]-f[2]));
(f[1]=(f[4]-f[1]));
(f[0]=(f[3]-f[0]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_075f0c3a3cc4a54d(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2003=0;
uint64_t s2008=0;
uint64_t s2009=0;
uint64_t s2010=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_335 = 0x50U; __auto_type bv = cn_init_335;
__auto_type cn_init_343 = rg[4]; __auto_type av = cn_init_343;
__auto_type cn_init_361 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_361;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2003=(((s2003&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r4));
{
__auto_type cn_init_473 = cn_double(v29); __auto_type v = cn_init_473;
(f[0]=(f[0]+v));
}
{
__auto_type cn_tuple_503_0 = sin(f[0]);
__auto_type cn_tuple_503_1 = cos(f[0]);
__auto_type s = cn_tuple_503_0;
__auto_type c = cn_tuple_503_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2012=cn_bits(f[1]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_tuple_574_0 = sin(f[0]);
__auto_type cn_tuple_574_1 = cos(f[0]);
__auto_type s = cn_tuple_574_0;
__auto_type c = cn_tuple_574_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(s2010=cn_bits(f[1]));
(s2009=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_639 = cn_double(s2012); __auto_type v = cn_init_639;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_663 = cn_double(v30); __auto_type v = cn_init_663;
(f[0]=(f[0]+v));
}
(s2008=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_710 = cn_double(s2011); __auto_type v = cn_init_710;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(s2008));
{
__auto_type cn_init_757 = cn_double(s2009); __auto_type v = cn_init_757;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2008));
{
__auto_type cn_init_804 = cn_double(s2010); __auto_type v = cn_init_804;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_07636de187847446(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v25=cn_cell(vm,0);
uint64_t v26=cn_cell(vm,8);
uint64_t v27=cn_cell(vm,16);
uint64_t v28=cn_cell(vm,24);
uint64_t v29=cn_cell(vm,32);
uint64_t v30=cn_cell(vm,40);

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
__auto_type cn_init_477 = cn_double(v28); __auto_type v = cn_init_477;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_513 = cn_double(v27); __auto_type v = cn_init_513;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_563 = cn_double(v26); __auto_type v = cn_init_563;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=atan2(f[0],f[1]));
{
__auto_type cn_init_617 = cn_double(r4); __auto_type v = cn_init_617;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(v29));
{
__auto_type cn_init_653 = cn_double(r3); __auto_type v = cn_init_653;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_677 = cn_double(v30); __auto_type v = cn_init_677;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v29));
{
__auto_type cn_init_713 = cn_double(r4); __auto_type v = cn_init_713;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r3));
{
__auto_type cn_init_749 = cn_double(v28); __auto_type v = cn_init_749;
(f[3]=(f[3]*v));
}
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_799 = cn_double(v25); __auto_type v = cn_init_799;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_823 = cn_double(r5); __auto_type v = cn_init_823;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_09bec55c100b1dd9(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2014=UINT64_C(0xfffffff000000000);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(f[0]=cn_double(r4));
(f[1]=cn_double(r5));
(f[1]=sin(f[1]));
(fsw&=~0x0400);
(f[0]=(f[0]+f[1]));
(r4=cn_bits(f[0]));
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}

cn_break_body:;
return (Vec){z.x,cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_09f9d674da6dccaf(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);
uint64_t v32=cn_cell(vm,40);

{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
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
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
{
__auto_type cn_init_588 = 0x0U; __auto_type bv = cn_init_588;
__auto_type cn_init_605 = (((uint32_t)(((((v29>>32))&0xffffffffULL))))); __auto_type av = cn_init_605;
__auto_type cn_init_623 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_623;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x1000801bU))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_698 = 0x0U; __auto_type bv = cn_init_698;
__auto_type cn_init_715 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_715;
__auto_type cn_init_733 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_733;
}
if(cn_cond(fl,5)){
goto cn_break_b33;
}
(f[0]=-f[0]);
}
cn_break_b33:;
(f[1]=cn_double(r4));
{
__auto_type cn_init_776 = 0x0U; __auto_type bv = cn_init_776;
__auto_type cn_init_793 = (((uint32_t)(((((v28>>32))&0xffffffffULL))))); __auto_type av = cn_init_793;
__auto_type cn_init_811 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_811;
}
if(cn_cond(fl,5)){
goto cn_break_b35;
}
(f[1]=-f[1]);
}
cn_break_b35:;
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_869 = 0x0U; __auto_type bv = cn_init_869;
__auto_type cn_init_886 = (((uint32_t)(((((v28>>0))&0xffffffffULL))))); __auto_type av = cn_init_886;
__auto_type cn_init_904 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_904;
}
if(cn_cond(fl,5)){
goto cn_break_b37;
}
(f[1]=-f[1]);
}
cn_break_b37:;
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_955 = cn_double(v32); __auto_type v = cn_init_955;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_986 = 0x0U; __auto_type bv = cn_init_986;
__auto_type cn_init_1003 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_1003;
__auto_type cn_init_1021 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1021;
}
if(cn_cond(fl,5)){
goto cn_break_b39;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b40;
}
cn_break_b39:;
(f[1]=(f[1]-f[0]));
}
cn_break_b40:;
(f[1]=-f[1]);
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_1109 = 0x0U; __auto_type bv = cn_init_1109;
__auto_type cn_init_1126 = (((uint32_t)(((((v28>>32))&0xffffffffULL))))); __auto_type av = cn_init_1126;
__auto_type cn_init_1144 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1144;
}
if(cn_cond(fl,5)){
goto cn_break_b42;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b43;
}
cn_break_b42:;
(f[1]=(f[1]-f[0]));
}
cn_break_b43:;
(f[1]=-f[1]);
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_1232 = 0x0U; __auto_type bv = cn_init_1232;
__auto_type cn_init_1249 = (((uint32_t)(((((v28>>0))&0xffffffffULL))))); __auto_type av = cn_init_1249;
__auto_type cn_init_1267 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1267;
}
if(cn_cond(fl,5)){
goto cn_break_b45;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b46;
}
cn_break_b45:;
(f[1]=(f[1]-f[0]));
}
cn_break_b46:;
(f[1]=-f[1]);
(r5=cn_bits(f[1]));
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b2:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_1381 = 0x0U; __auto_type bv = cn_init_1381;
__auto_type cn_init_1398 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_1398;
__auto_type cn_init_1416 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1416;
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
(f[0]=-f[0]);
}
cn_break_b4:;
(f[1]=cn_double(r4));
{
__auto_type cn_init_1459 = 0x0U; __auto_type bv = cn_init_1459;
__auto_type cn_init_1476 = (((uint32_t)(((((v28>>32))&0xffffffffULL))))); __auto_type av = cn_init_1476;
__auto_type cn_init_1494 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1494;
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
(f[1]=-f[1]);
}
cn_break_b6:;
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_1552 = 0x0U; __auto_type bv = cn_init_1552;
__auto_type cn_init_1569 = (((uint32_t)(((((v28>>0))&0xffffffffULL))))); __auto_type av = cn_init_1569;
__auto_type cn_init_1587 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1587;
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[1]=-f[1]);
}
cn_break_b8:;
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v30));
(f[1]=fabs(f[1]));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(fsw=cn_compare(f[1],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_1727 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1727;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
(f[1]=f[1]);
if(cn_cond(fl,2)){
goto cn_break_b19;
}
{
__auto_type cn_init_1811 = cn_double(v32); __auto_type v = cn_init_1811;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_1842 = 0x0U; __auto_type bv = cn_init_1842;
__auto_type cn_init_1859 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_1859;
__auto_type cn_init_1877 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1877;
}
if(cn_cond(fl,4)){
goto cn_break_b11;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b12;
}
cn_break_b11:;
(f[1]=(f[1]-f[0]));
}
cn_break_b12:;
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_1954 = 0x0U; __auto_type bv = cn_init_1954;
__auto_type cn_init_1971 = (((uint32_t)(((((v28>>32))&0xffffffffULL))))); __auto_type av = cn_init_1971;
__auto_type cn_init_1989 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1989;
}
if(cn_cond(fl,4)){
goto cn_break_b14;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b15;
}
cn_break_b14:;
(f[1]=(f[1]-f[0]));
}
cn_break_b15:;
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_2066 = 0x0U; __auto_type bv = cn_init_2066;
__auto_type cn_init_2083 = (((uint32_t)(((((v28>>0))&0xffffffffULL))))); __auto_type av = cn_init_2083;
__auto_type cn_init_2101 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2101;
}
if(cn_cond(fl,4)){
goto cn_break_b17;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b18;
}
cn_break_b17:;
(f[1]=(f[1]-f[0]));
}
cn_break_b18:;
(r5=cn_bits(f[1]));
goto cn_break_b30;
}
cn_break_b19:;
(f[1]=cn_double(v30));
(f[1]=fabs(f[1]));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2216 = cn_double(v27); __auto_type v = cn_init_2216;
(f[1]=(f[1]+v));
}
(f[0]=(f[0]+f[1]));
(f[1]=f[0]);
(fsw=cn_compare(f[1],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_2303 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_2303;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
(f[1]=f[1]);
if(cn_cond(fl,7)){
goto cn_break_b30;
}
{
__auto_type cn_init_2387 = cn_double(v32); __auto_type v = cn_init_2387;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_2418 = 0x0U; __auto_type bv = cn_init_2418;
__auto_type cn_init_2435 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_2435;
__auto_type cn_init_2453 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2453;
}
if(cn_cond(fl,4)){
goto cn_break_b22;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b23;
}
cn_break_b22:;
(f[1]=(f[1]-f[0]));
}
cn_break_b23:;
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_2530 = 0x0U; __auto_type bv = cn_init_2530;
__auto_type cn_init_2547 = (((uint32_t)(((((v28>>32))&0xffffffffULL))))); __auto_type av = cn_init_2547;
__auto_type cn_init_2565 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2565;
}
if(cn_cond(fl,4)){
goto cn_break_b25;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b26;
}
cn_break_b25:;
(f[1]=(f[1]-f[0]));
}
cn_break_b26:;
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_2642 = 0x0U; __auto_type bv = cn_init_2642;
__auto_type cn_init_2659 = (((uint32_t)(((((v28>>0))&0xffffffffULL))))); __auto_type av = cn_init_2659;
__auto_type cn_init_2677 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2677;
}
if(cn_cond(fl,4)){
goto cn_break_b28;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b29;
}
cn_break_b28:;
(f[1]=(f[1]-f[0]));
}
cn_break_b29:;
(r5=cn_bits(f[1]));
}
cn_break_b30:;
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_0aa79304be5365d1(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);

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
(f[0]=cn_double(v30));
(f[1]=cn_double(r5));
(f[2]=f[1]);
(f[2]=(f[2]-f[0]));
(f[2]=fabs(f[2]));
cn_swap(f,2,1);
{
__auto_type cn_init_428 = cn_double(v29); __auto_type v = cn_init_428;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_481 = cn_double(r5); __auto_type v = cn_init_481;
(f[1]=(f[1]+v));
}
(f[1]=(f[1]-f[0]));
(r5=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[2]=f[1]);
(f[2]=(f[2]-f[0]));
(f[2]=fabs(f[2]));
cn_swap(f,2,1);
{
__auto_type cn_init_591 = cn_double(v29); __auto_type v = cn_init_591;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_644 = cn_double(r4); __auto_type v = cn_init_644;
(f[1]=(f[1]+v));
}
(f[1]=(f[1]-f[0]));
(r4=cn_bits(f[1]));
(f[1]=cn_double(r3));
(f[2]=f[1]);
(f[2]=(f[2]-f[0]));
(f[2]=fabs(f[2]));
cn_swap(f,2,1);
{
__auto_type cn_init_754 = cn_double(v29); __auto_type v = cn_init_754;
(f[2]=(f[2]-v));
}
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_807 = cn_double(r3); __auto_type v = cn_init_807;
(f[1]=(f[1]+v));
}
(f[0]=(f[1]-f[0]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_0c932fcfcb9267a3(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v28=cn_cell(vm,0);
uint64_t v29=cn_cell(vm,8);
uint64_t v30=cn_cell(vm,16);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_0cb3daf3eba3172e(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_10b6bb1104349cbf(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v28=cn_cell(vm,0);
uint64_t v29=cn_cell(vm,8);
uint64_t v30=cn_cell(vm,16);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_117351c6664c8709(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v17=cn_cell(vm,0);
uint64_t v18=cn_cell(vm,8);
uint64_t v19=cn_cell(vm,16);
uint64_t v20=cn_cell(vm,24);
uint64_t v21=cn_cell(vm,32);
uint64_t v22=cn_cell(vm,40);
uint64_t v23=cn_cell(vm,48);
uint64_t v24=cn_cell(vm,56);
uint64_t v25=cn_cell(vm,64);
uint64_t v26=cn_cell(vm,72);
uint64_t v27=cn_cell(vm,80);
uint64_t v28=cn_cell(vm,88);
uint64_t v29=cn_cell(vm,96);
uint64_t v30=cn_cell(vm,104);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_12950cb060c90325(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_1303ccb7dbfec158(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v32=cn_cell(vm,0);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_13798995920dbc66(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){cn_double(r3),z.y,z.z};
}
static inline Vec cf_pure_14ea390f09101007(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v32=cn_cell(vm,0);
uint64_t v33=cn_cell(vm,8);
uint64_t v34=cn_cell(vm,16);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_170d88a7063dc19f(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_170d88a7063dc19f_fast(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_1843a4e57d14edaa(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);
uint64_t v32=cn_cell(vm,24);
uint64_t v33=cn_cell(vm,32);
uint64_t v34=cn_cell(vm,40);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_19167e07a00f877b(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r4=cn_bits(z.y);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){z.x,cn_double(r4),z.z};
}
static inline Vec cf_pure_1b455c469f6af2bc(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v20=cn_cell(vm,0);
uint64_t v21=cn_cell(vm,8);
uint64_t v22=cn_cell(vm,16);
uint64_t v23=cn_cell(vm,24);
uint64_t v24=cn_cell(vm,32);
uint64_t v25=cn_cell(vm,40);
uint64_t v26=cn_cell(vm,48);
uint64_t v27=cn_cell(vm,56);
uint64_t v28=cn_cell(vm,64);
uint64_t v29=cn_cell(vm,72);
uint64_t v30=cn_cell(vm,80);

{
{
{
{
{
{
{
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_1b4a584dbcc33356(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r4=cn_bits(z.y);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){z.x,cn_double(r4),z.z};
}
static inline Vec cf_pure_1c600993a98ac491(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

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
return (Vec){z.x,z.y,cn_double(r5)};
}
static inline Vec cf_pure_1c9a2f979ccd5056(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r4=cn_bits(z.y);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){z.x,cn_double(r4),z.z};
}
static inline Vec cf_pure_1e2a7e409a31e0cc(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v23=cn_cell(vm,0);
uint64_t v24=cn_cell(vm,8);
uint64_t v25=cn_cell(vm,16);
uint64_t v26=cn_cell(vm,24);
uint64_t v27=cn_cell(vm,32);
uint64_t v28=cn_cell(vm,40);
uint64_t v29=cn_cell(vm,48);
uint64_t v30=cn_cell(vm,56);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_205ab96c98f98fb9(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r4=cn_bits(z.y);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

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
return (Vec){z.x,cn_double(r4),z.z};
}
static inline Vec cf_pure_20f481396f51978b(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2003=0;
uint64_t s2004=0;
uint64_t s2005=0;
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2008=0;
uint64_t s2009=0;
uint64_t s2010=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);
uint64_t v32=cn_cell(vm,40);
uint64_t v33=cn_cell(vm,48);

{
{
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_29e575922b051916(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2014=UINT64_C(0xfffffff000000000);

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
return (Vec){z.x,cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_2a196bafa4357ec1(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_2aa886369f57321b(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_2dffd31d561b9853(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v28=cn_cell(vm,0);
uint64_t v29=cn_cell(vm,8);
uint64_t v30=cn_cell(vm,16);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_2e69ea4edc1c5736(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_30e2e60d6a23e99d(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_31ca3aecc58e5db3(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_31f1cc5bee2024dc(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){cn_double(r3),z.y,z.z};
}
static inline Vec cf_pure_333566b600828b95(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){cn_double(r3),z.y,z.z};
}
static inline Vec cf_pure_334f193283f9597c(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v18=cn_cell(vm,0);
uint64_t v19=cn_cell(vm,8);
uint64_t v20=cn_cell(vm,16);
uint64_t v21=cn_cell(vm,24);
uint64_t v22=cn_cell(vm,32);
uint64_t v23=cn_cell(vm,40);
uint64_t v24=cn_cell(vm,48);
uint64_t v25=cn_cell(vm,56);
uint64_t v26=cn_cell(vm,64);
uint64_t v27=cn_cell(vm,72);
uint64_t v28=cn_cell(vm,80);
uint64_t v29=cn_cell(vm,88);
uint64_t v30=cn_cell(vm,96);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_359551ba93faa981(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v25=cn_cell(vm,0);
uint64_t v26=cn_cell(vm,8);
uint64_t v27=cn_cell(vm,16);
uint64_t v28=cn_cell(vm,24);
uint64_t v29=cn_cell(vm,32);
uint64_t v30=cn_cell(vm,40);

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
return (Vec){cn_double(r3),z.y,z.z};
}
static inline Vec cf_pure_3a746f46e88503db(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
__auto_type cn_init_455 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_455;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_503 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_503;
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
__auto_type cn_init_677 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_677;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_740 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_740;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_802 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_802;
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
__auto_type cn_init_911 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_911;
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_3ac60c1633414f8d(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);
uint64_t v32=cn_cell(vm,40);

{
{
{
{
{
{
{
{
{
{
{
{
{
{
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
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
{
__auto_type cn_init_570 = 0x0U; __auto_type bv = cn_init_570;
__auto_type cn_init_587 = (((uint32_t)(((((v27>>32))&0xffffffffULL))))); __auto_type av = cn_init_587;
__auto_type cn_init_605 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_605;
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x1000801bU))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_680 = 0x0U; __auto_type bv = cn_init_680;
__auto_type cn_init_697 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_697;
__auto_type cn_init_715 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_715;
}
if(cn_cond(fl,5)){
goto cn_break_b24;
}
(f[0]=-f[0]);
}
cn_break_b24:;
(f[1]=cn_double(r4));
{
__auto_type cn_init_758 = 0x0U; __auto_type bv = cn_init_758;
__auto_type cn_init_775 = (((uint32_t)(((((v28>>32))&0xffffffffULL))))); __auto_type av = cn_init_775;
__auto_type cn_init_793 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_793;
}
if(cn_cond(fl,5)){
goto cn_break_b26;
}
(f[1]=-f[1]);
}
cn_break_b26:;
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_851 = 0x0U; __auto_type bv = cn_init_851;
__auto_type cn_init_868 = (((uint32_t)(((((v28>>0))&0xffffffffULL))))); __auto_type av = cn_init_868;
__auto_type cn_init_886 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_886;
}
if(cn_cond(fl,5)){
goto cn_break_b28;
}
(f[1]=-f[1]);
}
cn_break_b28:;
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_937 = cn_double(v32); __auto_type v = cn_init_937;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_968 = 0x0U; __auto_type bv = cn_init_968;
__auto_type cn_init_985 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_985;
__auto_type cn_init_1003 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1003;
}
if(cn_cond(fl,5)){
goto cn_break_b30;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b31;
}
cn_break_b30:;
(f[1]=(f[1]-f[0]));
}
cn_break_b31:;
(f[1]=-f[1]);
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_1091 = 0x0U; __auto_type bv = cn_init_1091;
__auto_type cn_init_1108 = (((uint32_t)(((((v28>>32))&0xffffffffULL))))); __auto_type av = cn_init_1108;
__auto_type cn_init_1126 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1126;
}
if(cn_cond(fl,5)){
goto cn_break_b33;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b34;
}
cn_break_b33:;
(f[1]=(f[1]-f[0]));
}
cn_break_b34:;
(f[1]=-f[1]);
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_1214 = 0x0U; __auto_type bv = cn_init_1214;
__auto_type cn_init_1231 = (((uint32_t)(((((v28>>0))&0xffffffffULL))))); __auto_type av = cn_init_1231;
__auto_type cn_init_1249 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1249;
}
if(cn_cond(fl,5)){
goto cn_break_b36;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b37;
}
cn_break_b36:;
(f[1]=(f[1]-f[0]));
}
cn_break_b37:;
(f[1]=-f[1]);
(r5=cn_bits(f[1]));
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b2:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_1363 = 0x0U; __auto_type bv = cn_init_1363;
__auto_type cn_init_1380 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_1380;
__auto_type cn_init_1398 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1398;
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
(f[0]=-f[0]);
}
cn_break_b4:;
(f[1]=cn_double(r4));
{
__auto_type cn_init_1441 = 0x0U; __auto_type bv = cn_init_1441;
__auto_type cn_init_1458 = (((uint32_t)(((((v28>>32))&0xffffffffULL))))); __auto_type av = cn_init_1458;
__auto_type cn_init_1476 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1476;
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
(f[1]=-f[1]);
}
cn_break_b6:;
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_1534 = 0x0U; __auto_type bv = cn_init_1534;
__auto_type cn_init_1551 = (((uint32_t)(((((v28>>0))&0xffffffffULL))))); __auto_type av = cn_init_1551;
__auto_type cn_init_1569 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1569;
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[1]=-f[1]);
}
cn_break_b8:;
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v30));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
{
__auto_type cn_init_1652 = 0x0U; __auto_type bv = cn_init_1652;
__auto_type cn_init_1669 = (((uint32_t)(((((v29>>32))&0xffffffffULL))))); __auto_type av = cn_init_1669;
__auto_type cn_init_1687 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1687;
}
if(cn_cond(fl,4)){
goto cn_break_b10;
}
(f[1]=-f[1]);
}
cn_break_b10:;
(fsw=cn_compare(f[1],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_1761 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1761;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
(f[1]=f[1]);
if(cn_cond(fl,2)){
goto cn_break_b21;
}
{
__auto_type cn_init_1845 = cn_double(v32); __auto_type v = cn_init_1845;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_1876 = 0x0U; __auto_type bv = cn_init_1876;
__auto_type cn_init_1893 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_1893;
__auto_type cn_init_1911 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1911;
}
if(cn_cond(fl,4)){
goto cn_break_b13;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b14;
}
cn_break_b13:;
(f[1]=(f[1]-f[0]));
}
cn_break_b14:;
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_1988 = 0x0U; __auto_type bv = cn_init_1988;
__auto_type cn_init_2005 = (((uint32_t)(((((v28>>32))&0xffffffffULL))))); __auto_type av = cn_init_2005;
__auto_type cn_init_2023 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2023;
}
if(cn_cond(fl,4)){
goto cn_break_b16;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b17;
}
cn_break_b16:;
(f[1]=(f[1]-f[0]));
}
cn_break_b17:;
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
{
__auto_type cn_init_2100 = 0x0U; __auto_type bv = cn_init_2100;
__auto_type cn_init_2117 = (((uint32_t)(((((v28>>0))&0xffffffffULL))))); __auto_type av = cn_init_2117;
__auto_type cn_init_2135 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2135;
}
if(cn_cond(fl,4)){
goto cn_break_b19;
}
(f[1]=(f[1]+f[0]));
goto cn_break_b20;
}
cn_break_b19:;
(f[1]=(f[1]-f[0]));
}
cn_break_b20:;
(r5=cn_bits(f[1]));
}
cn_break_b21:;
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_3f765c463884471f(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

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
__auto_type cn_init_358 = (((uint32_t)(((((r3>>56))&0xffULL))))); __auto_type v = cn_init_358;
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
(r3=cn_bits(f[0]));
{
__auto_type cn_init_530 = cn_reg_get(rg,2,1); __auto_type bv = cn_init_530;
__auto_type cn_init_547 = (((uint32_t)(((((r3>>56))&0xffULL))))); __auto_type av = cn_init_547;
__auto_type cn_init_565 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_565;
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
return (Vec){cn_double(r3),z.y,z.z};
}
static inline Vec cf_pure_40561823f83f886e(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v24=cn_cell(vm,0);
uint64_t v25=cn_cell(vm,8);
uint64_t v26=cn_cell(vm,16);
uint64_t v27=cn_cell(vm,24);
uint64_t v28=cn_cell(vm,32);
uint64_t v29=cn_cell(vm,40);
uint64_t v30=cn_cell(vm,48);

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
__auto_type cn_init_433 = cn_double(v30); __auto_type v = cn_init_433;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v26));
{
__auto_type cn_init_496 = cn_double(v29); __auto_type v = cn_init_496;
(f[2]=(f[2]-v));
}
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v25));
{
__auto_type cn_init_589 = cn_double(v28); __auto_type v = cn_init_589;
(f[2]=(f[2]-v));
}
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(v24));
{
__auto_type cn_init_682 = cn_double(v27); __auto_type v = cn_init_682;
(f[2]=(f[2]-v));
}
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r4));
{
__auto_type cn_init_748 = cn_double(v30); __auto_type v = cn_init_748;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r3));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(v24));
{
__auto_type cn_init_811 = cn_double(v29); __auto_type v = cn_init_811;
(f[3]=(f[3]-v));
}
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r4));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(v26));
{
__auto_type cn_init_904 = cn_double(v28); __auto_type v = cn_init_904;
(f[3]=(f[3]-v));
}
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[3]=cn_double(v25));
{
__auto_type cn_init_997 = cn_double(v27); __auto_type v = cn_init_997;
(f[3]=(f[3]-v));
}
(f[2]=(f[2]*f[3]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(r5));
{
__auto_type cn_init_1063 = cn_double(v30); __auto_type v = cn_init_1063;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[3]));
(f[4]=cn_double(v25));
{
__auto_type cn_init_1126 = cn_double(v29); __auto_type v = cn_init_1126;
(f[4]=(f[4]-v));
}
(f[3]=(f[3]*f[4]));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r4));
(f[3]=(f[3]*f[3]));
(f[4]=cn_double(v24));
{
__auto_type cn_init_1219 = cn_double(v28); __auto_type v = cn_init_1219;
(f[4]=(f[4]-v));
}
(f[3]=(f[3]*f[4]));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r5));
(f[3]=(f[3]*f[3]));
(f[4]=cn_double(v26));
{
__auto_type cn_init_1312 = cn_double(v27); __auto_type v = cn_init_1312;
(f[4]=(f[4]-v));
}
(f[3]=(f[3]*f[4]));
(f[2]=(f[2]+f[3]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_416ffd7ed9f878b8(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r4=cn_bits(z.y);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

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
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[1])))&0xffffffffULL))<<0))));
}
(f[0]=cn_double(r4));
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
{
__auto_type cn_init_358 = (((uint32_t)(((((r4>>56))&0xffULL))))); __auto_type v = cn_init_358;
cn_reg_set(rg,1,1,v);
}
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_414 = cn_double(v30); __auto_type v = cn_init_414;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_433 = 0x80U; __auto_type bv = cn_init_433;
__auto_type cn_init_446 = cn_reg_get(rg,1,1); __auto_type av = cn_init_446;
__auto_type cn_init_464 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_464;
cn_reg_set(rg,1,1,r);
}
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(r4=cn_bits(f[0]));
{
__auto_type cn_init_530 = cn_reg_get(rg,1,1); __auto_type bv = cn_init_530;
__auto_type cn_init_547 = (((uint32_t)(((((r4>>56))&0xffULL))))); __auto_type av = cn_init_547;
__auto_type cn_init_565 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_565;
(r4=(((r4&~((0xffULL<<56))))|(((((((uint64_t)((r))))&0xffULL))<<56))));
}
{
(rg[1]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
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
return (Vec){z.x,cn_double(r4),z.z};
}
static inline Vec cf_pure_43a8a7c55cb24ee2(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
(f[0]=cn_double(r5));
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
(r5=cn_bits(f[0]));
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
return (Vec){z.x,z.y,cn_double(r5)};
}
static inline Vec cf_pure_43f63d71687dcf8b(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);
uint64_t v32=cn_cell(vm,24);
uint64_t v33=cn_cell(vm,32);

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
__auto_type cn_init_377 = cn_double(v30); __auto_type v = cn_init_377;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(0x400921fb54442d18));
(f[0]=(f[0]*f[1]));
(f[0]=cos(f[0]));
(fsw&=~0x0400);
{
__auto_type cn_init_447 = cn_double(v29); __auto_type v = cn_init_447;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_471 = cn_double(v29); __auto_type v = cn_init_471;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_495 = cn_double(v32); __auto_type v = cn_init_495;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_519 = cn_double(v33); __auto_type v = cn_init_519;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
(f[1]=sin(f[1]));
(fsw&=~0x0400);
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_589 = cn_double(r4); __auto_type v = cn_init_589;
(f[0]=(f[0]+v));
}
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
return (Vec){z.x,cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_44e92884ff4d508e(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v18=cn_cell(vm,0);
uint64_t v19=cn_cell(vm,8);
uint64_t v20=cn_cell(vm,16);
uint64_t v21=cn_cell(vm,24);
uint64_t v22=cn_cell(vm,32);
uint64_t v23=cn_cell(vm,40);
uint64_t v24=cn_cell(vm,48);
uint64_t v25=cn_cell(vm,56);
uint64_t v26=cn_cell(vm,64);
uint64_t v27=cn_cell(vm,72);
uint64_t v28=cn_cell(vm,80);
uint64_t v29=cn_cell(vm,88);
uint64_t v30=cn_cell(vm,96);

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
(f[3]=f[2]);
{
__auto_type cn_init_1463 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1463;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1511 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1511;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1574 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1574;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1637 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1637;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1685 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1685;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1748 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1748;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1810 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1810;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1857 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1857;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1919 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1919;
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
__auto_type cn_init_2090 = cn_double(v27); __auto_type v = cn_init_2090;
(f[4]=(f[4]*v));
}
(f[0]=(f[0]-f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_2139 = cn_double(v28); __auto_type v = cn_init_2139;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]-f[4]));
{
__auto_type cn_init_2178 = cn_double(v29); __auto_type v = cn_init_2178;
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_4819d80a4da95daa(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
(f[1]=cn_double(r3));
(f[1]=fabs(f[1]));
(f[1]=(f[1]/f[0]));
(f[2]=cn_double(v27));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_765 = cn_double(v30); __auto_type v = cn_init_765;
(f[1]=(f[1]-v));
}
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
(f[1]=(f[1]/f[0]));
(f[2]=cn_double(v27));
(f[1]=(f[1]*f[2]));
{
__auto_type cn_init_868 = cn_double(v29); __auto_type v = cn_init_868;
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
__auto_type cn_init_980 = cn_double(v28); __auto_type v = cn_init_980;
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_4a43a2f50978fa91(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
(f[0]=cn_double(r5));
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
(r5=cn_bits(f[0]));
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
return (Vec){z.x,z.y,cn_double(r5)};
}
static inline Vec cf_pure_4aa26c3c41bb6ac8(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v25=cn_cell(vm,0);
uint64_t v26=cn_cell(vm,8);
uint64_t v27=cn_cell(vm,16);
uint64_t v28=cn_cell(vm,24);
uint64_t v29=cn_cell(vm,32);
uint64_t v30=cn_cell(vm,40);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_4c9b645e9971eba8(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r4=cn_bits(z.y);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){z.x,cn_double(r4),z.z};
}
static inline Vec cf_pure_4da5e2239ba1634f(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
__auto_type cn_init_424 = cn_double(r3); __auto_type v = cn_init_424;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_448 = cn_double(v29); __auto_type v = cn_init_448;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_472 = cn_double(r6); __auto_type v = cn_init_472;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_496 = cn_double(v30); __auto_type v = cn_init_496;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
{
__auto_type cn_init_532 = cn_double(v27); __auto_type v = cn_init_532;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_556 = cn_double(r4); __auto_type v = cn_init_556;
(f[1]=(f[1]-v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_592 = cn_double(r5); __auto_type v = cn_init_592;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_642 = cn_double(v30); __auto_type v = cn_init_642;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_678 = cn_double(r4); __auto_type v = cn_init_678;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r5));
{
__auto_type cn_init_714 = cn_double(v28); __auto_type v = cn_init_714;
(f[3]=(f[3]*v));
}
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_764 = cn_double(v30); __auto_type v = cn_init_764;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r6));
{
__auto_type cn_init_800 = cn_double(v26); __auto_type v = cn_init_800;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r4));
{
__auto_type cn_init_836 = cn_double(r5); __auto_type v = cn_init_836;
(f[4]=(f[4]*v));
}
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_886 = cn_double(v30); __auto_type v = cn_init_886;
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_4fc7552e2ed9ae63(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);
uint64_t v32=cn_cell(vm,24);
uint64_t v33=cn_cell(vm,32);
uint64_t v34=cn_cell(vm,40);
uint64_t v35=cn_cell(vm,48);
uint64_t v36=cn_cell(vm,56);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_404 = 0x30U; __auto_type bv = cn_init_404;
__auto_type cn_init_412 = rg[4]; __auto_type av = cn_init_412;
__auto_type cn_init_430 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_430;
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
__auto_type cn_init_646 = cn_double(v36); __auto_type v = cn_init_646;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r6));
{
__auto_type cn_init_682 = cn_double(v35); __auto_type v = cn_init_682;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_758 = cn_double(v35); __auto_type v = cn_init_758;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r6));
{
__auto_type cn_init_794 = cn_double(v36); __auto_type v = cn_init_794;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
(s2012=cn_bits(f[0]));
{
__auto_type cn_init_855 = cn_double(v32); __auto_type v = cn_init_855;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_891 = cn_double(v33); __auto_type v = cn_init_891;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_941 = cn_double(v34); __auto_type v = cn_init_941;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_988 = cn_double(v33); __auto_type v = cn_init_988;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1024 = cn_double(v32); __auto_type v = cn_init_1024;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(f[1]=cn_double(s2013));
(f[2]=cn_double(r4));
{
__auto_type cn_init_1101 = cn_double(v34); __auto_type v = cn_init_1101;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[1]=fabs(f[1]));
(f[2]=cn_double(s2013));
(f[3]=cn_double(r4));
{
__auto_type cn_init_1189 = cn_double(v34); __auto_type v = cn_init_1189;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[2]=fabs(f[2]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1287 = cn_double(r4); __auto_type v = cn_init_1287;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1311 = cn_double(v34); __auto_type v = cn_init_1311;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=-f[0]);
{
__auto_type cn_init_1369 = cn_double(r4); __auto_type v = cn_init_1369;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1393 = cn_double(v34); __auto_type v = cn_init_1393;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1440 = cn_double(v32); __auto_type v = cn_init_1440;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1476 = cn_double(v33); __auto_type v = cn_init_1476;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(s2012=cn_bits(f[0]));
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1538 = cn_double(v33); __auto_type v = cn_init_1538;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[2]=cn_double(r5));
{
__auto_type cn_init_1585 = cn_double(v32); __auto_type v = cn_init_1585;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(r5=cn_bits(f[1]));
{
__auto_type cn_init_1635 = cn_double(v36); __auto_type v = cn_init_1635;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
(f[1]=cn_double(s2011));
{
__auto_type cn_init_1682 = cn_double(v35); __auto_type v = cn_init_1682;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r6=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_1744 = cn_double(v35); __auto_type v = cn_init_1744;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2011));
{
__auto_type cn_init_1780 = cn_double(v36); __auto_type v = cn_init_1780;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_1819 = cn_double(v30); __auto_type v = cn_init_1819;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1843 = cn_double(v29); __auto_type v = cn_init_1843;
(f[0]=(f[0]-v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1890 = cn_double(v30); __auto_type v = cn_init_1890;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_1937 = cn_double(v30); __auto_type v = cn_init_1937;
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_558b81855fc0a4dd(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
(f[0]=(f[1]/f[0]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_58fc3b5da2368ee2(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);
uint64_t v32=cn_cell(vm,24);

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
{
__auto_type cn_init_452 = cn_double(v30); __auto_type v = cn_init_452;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(r5));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
(f[2]=f[0]);
(f[3]=cn_double(r5));
(f[2]=atan2(f[2],f[3]));
{
__auto_type cn_init_597 = cn_double(v29); __auto_type v = cn_init_597;
(f[2]=(f[2]-v));
}
{
__auto_type cn_init_621 = cn_double(v32); __auto_type v = cn_init_621;
(f[2]=(f[2]-v));
}
(f[3]=cn_double(r4));
(f[4]=cn_double(r3));
(f[3]=atan2(f[3],f[4]));
(r5=cn_bits(f[3]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_59d6a2c368055035(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);
uint64_t v32=cn_cell(vm,24);
uint64_t v33=cn_cell(vm,32);
uint64_t v34=cn_cell(vm,40);

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
{
__auto_type cn_init_1031 = cn_double(v29); __auto_type v = cn_init_1031;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1069 = cn_double(v30); __auto_type v = cn_init_1069;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1093 = cn_double(v34); __auto_type v = cn_init_1093;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1140 = cn_double(r5); __auto_type v = cn_init_1140;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1164 = cn_double(v29); __auto_type v = cn_init_1164;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1202 = cn_double(v30); __auto_type v = cn_init_1202;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1226 = cn_double(v34); __auto_type v = cn_init_1226;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1273 = cn_double(s2012); __auto_type v = cn_init_1273;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1297 = cn_double(v29); __auto_type v = cn_init_1297;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
{
__auto_type cn_init_1335 = cn_double(v30); __auto_type v = cn_init_1335;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1382 = cn_double(r3); __auto_type v = cn_init_1382;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1418 = cn_double(r3); __auto_type v = cn_init_1418;
(f[1]=(f[1]-v));
}
(r4=cn_bits(f[1]));
(s2013=cn_bits(f[0]));
(f[0]=cn_double(s2013));
{
__auto_type cn_init_1476 = cn_double(v32); __auto_type v = cn_init_1476;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_1512 = cn_double(v33); __auto_type v = cn_init_1512;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1563 = cn_double(v33); __auto_type v = cn_init_1563;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[2]=cn_double(r5));
{
__auto_type cn_init_1610 = cn_double(v32); __auto_type v = cn_init_1610;
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_5e299e82b7f6da6b(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_621449000c668362(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v20=cn_cell(vm,0);
uint64_t v21=cn_cell(vm,8);
uint64_t v22=cn_cell(vm,16);
uint64_t v23=cn_cell(vm,24);
uint64_t v24=cn_cell(vm,32);
uint64_t v25=cn_cell(vm,40);
uint64_t v26=cn_cell(vm,48);
uint64_t v27=cn_cell(vm,56);
uint64_t v28=cn_cell(vm,64);
uint64_t v29=cn_cell(vm,72);
uint64_t v30=cn_cell(vm,80);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_6405c0b3abe12770(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v25=cn_cell(vm,0);
uint64_t v26=cn_cell(vm,8);
uint64_t v27=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,32);
uint64_t v30=cn_cell(vm,40);

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
(f[1]=f[0]);
(f[1]=cos(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_419 = cn_double(v26); __auto_type v = cn_init_419;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=sin(f[0]));
(fsw&=~0x0400);
{
__auto_type cn_init_477 = cn_double(v27); __auto_type v = cn_init_477;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_513 = cn_double(r3); __auto_type v = cn_init_513;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_537 = cn_double(v25); __auto_type v = cn_init_537;
(f[1]=(f[1]*v));
}
(f[0]=(f[1]-f[0]));
(f[0]=sin(f[0]));
(fsw&=~0x0400);
{
__auto_type cn_init_595 = cn_double(v29); __auto_type v = cn_init_595;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_619 = cn_double(r4); __auto_type v = cn_init_619;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
(f[2]=f[1]);
(f[2]=cos(f[2]));
(fsw&=~0x0400);
{
__auto_type cn_init_684 = cn_double(v26); __auto_type v = cn_init_684;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_723 = cn_double(v27); __auto_type v = cn_init_723;
(f[1]=(f[1]*v));
}
(f[1]=sin(f[1]));
(fsw&=~0x0400);
(f[2]=cn_double(r4));
{
__auto_type cn_init_778 = cn_double(r3); __auto_type v = cn_init_778;
(f[2]=(v-f[2]));
}
{
__auto_type cn_init_802 = cn_double(v25); __auto_type v = cn_init_802;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=sin(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_860 = cn_double(v29); __auto_type v = cn_init_860;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_884 = cn_double(r3); __auto_type v = cn_init_884;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(v30));
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]*f[2]));
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
return (Vec){cn_double(r3),cn_double(r4),z.z};
}
static inline Vec cf_pure_6405c0b3abe12770_fast(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v25=cn_cell(vm,0);
uint64_t v26=cn_cell(vm,8);
uint64_t v27=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,32);
uint64_t v30=cn_cell(vm,40);

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
(f[1]=f[0]);
(f[1]=cn_fast_cos(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_419 = cn_double(v26); __auto_type v = cn_init_419;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=cn_fast_sin(f[0]));
(fsw&=~0x0400);
{
__auto_type cn_init_477 = cn_double(v27); __auto_type v = cn_init_477;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_513 = cn_double(r3); __auto_type v = cn_init_513;
(f[1]=(f[1]+v));
}
{
__auto_type cn_init_537 = cn_double(v25); __auto_type v = cn_init_537;
(f[1]=(f[1]*v));
}
(f[0]=(f[1]-f[0]));
(f[0]=cn_fast_sin(f[0]));
(fsw&=~0x0400);
{
__auto_type cn_init_595 = cn_double(v29); __auto_type v = cn_init_595;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_619 = cn_double(r4); __auto_type v = cn_init_619;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
(f[2]=f[1]);
(f[2]=cn_fast_cos(f[2]));
(fsw&=~0x0400);
{
__auto_type cn_init_684 = cn_double(v26); __auto_type v = cn_init_684;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
{
__auto_type cn_init_723 = cn_double(v27); __auto_type v = cn_init_723;
(f[1]=(f[1]*v));
}
(f[1]=cn_fast_sin(f[1]));
(fsw&=~0x0400);
(f[2]=cn_double(r4));
{
__auto_type cn_init_778 = cn_double(r3); __auto_type v = cn_init_778;
(f[2]=(v-f[2]));
}
{
__auto_type cn_init_802 = cn_double(v25); __auto_type v = cn_init_802;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[1]=cn_fast_sin(f[1]));
(fsw&=~0x0400);
{
__auto_type cn_init_860 = cn_double(v29); __auto_type v = cn_init_860;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_884 = cn_double(r3); __auto_type v = cn_init_884;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(v30));
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]*f[2]));
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
return (Vec){cn_double(r3),cn_double(r4),z.z};
}
static inline Vec cf_pure_66497f3d431c0918(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v32=cn_cell(vm,0);
uint64_t v33=cn_cell(vm,8);
uint64_t v34=cn_cell(vm,16);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_335 = 0x30U; __auto_type bv = cn_init_335;
__auto_type cn_init_343 = rg[4]; __auto_type av = cn_init_343;
__auto_type cn_init_361 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_361;
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
__auto_type cn_init_577 = cn_double(v34); __auto_type v = cn_init_577;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_624 = cn_double(v34); __auto_type v = cn_init_624;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(s2013));
(f[1]=cn_double(s2012));
(f[0]=(f[0]+f[1]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(s2012));
{
__auto_type cn_init_721 = cn_double(s2013); __auto_type v = cn_init_721;
(f[0]=(f[0]-v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(s2011));
{
__auto_type cn_init_768 = cn_double(v32); __auto_type v = cn_init_768;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_804 = cn_double(v33); __auto_type v = cn_init_804;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_866 = cn_double(v32); __auto_type v = cn_init_866;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2011));
{
__auto_type cn_init_902 = cn_double(v33); __auto_type v = cn_init_902;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_6dbf92dffd82a711(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

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
(f[4]=cn_double(v30));
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_6dd65a6c7247a4c4(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2007=0;
uint64_t s2008=0;
uint64_t s2009=0;
uint64_t s2010=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v18=cn_cell(vm,0);
uint64_t v19=cn_cell(vm,8);
uint64_t v20=cn_cell(vm,16);
uint64_t v21=cn_cell(vm,24);
uint64_t v22=cn_cell(vm,32);
uint64_t v23=cn_cell(vm,40);
uint64_t v24=cn_cell(vm,48);
uint64_t v25=cn_cell(vm,56);
uint64_t v26=cn_cell(vm,64);
uint64_t v27=cn_cell(vm,72);
uint64_t v28=cn_cell(vm,80);
uint64_t v29=cn_cell(vm,88);
uint64_t v30=cn_cell(vm,96);
uint64_t v32=cn_cell(vm,112);
uint64_t v33=cn_cell(vm,120);

{
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_510 = 0x28U; __auto_type bv = cn_init_510;
__auto_type cn_init_518 = rg[4]; __auto_type av = cn_init_518;
__auto_type cn_init_536 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_536;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2008=(((s2008&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2008=(((s2008&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2007=(((s2007&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_800 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_800;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_848 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_848;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_911 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_911;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_974 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_974;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1022 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1022;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1085 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1085;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1147 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1147;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1194 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1194;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1256 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1256;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
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
(s2012=cn_bits(f[0]));
(f[1]=cn_double(((((((v25>>32))|((v26<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[1]/f[0]));
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[0]));
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[0]));
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[0]));
(r5=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_1643 = cn_double(r3); __auto_type v = cn_init_1643;
(f[0]=(f[0]-v));
}
(f[1]=f[0]);
(f[2]=cn_double(((((((v18>>32))|((v19<<32))))&0xffffffffffffffffULL))));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b2;
}
(f[0]=f[0]);
(f[0]=cn_double(0x3ff0000000000000));
goto cn_break_b3;
}
cn_break_b2:;
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
}
cn_break_b3:;
(f[1]=cn_double(r5));
(f[1]=(f[1]*f[0]));
(s2011=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[0]));
(s2010=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(s2011));
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(s2010));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
(s2009=cn_bits(f[0]));
(f[0]=cn_double(s2011));
{
__auto_type cn_init_2034 = cn_double(v32); __auto_type v = cn_init_2034;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2074 = cn_double(((((((v22>>32))|((v23<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2074;
(f[0]=(f[0]+v));
}
(f[0]=sin(f[0]));
(fsw&=~0x0400);
(f[0]=fabs(f[0]));
(f[1]=cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(s2011=cn_bits(f[0]));
(f[0]=cn_double(s2010));
{
__auto_type cn_init_2211 = cn_double(v32); __auto_type v = cn_init_2211;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2251 = cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2251;
(f[0]=(f[0]+v));
}
(f[0]=sin(f[0]));
(fsw&=~0x0400);
(f[0]=fabs(f[0]));
(f[1]=cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(s2010=cn_bits(f[0]));
(f[0]=cn_double(s2012));
(f[1]=cn_double(s2009));
{
__auto_type cn_init_2416 = cn_double(((((((v24>>32))|((v25<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2416;
(f[1]=(f[1]*v));
}
cn_swap(f,1,0);
(f[1]=fabs(f[1]));
(f[0]*=log2(f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[2]=f[0]);
{
__auto_type cn_tuple_2508_0 = f[2];
__auto_type cn_tuple_2508_1 = f[1];
__auto_type x = cn_tuple_2508_0;
__auto_type y = cn_tuple_2508_1;
__auto_type cn_init_2537 = ((false)?(({nearbyint(((x/y)));})):(({trunc(((x/y)));}))); __auto_type q = cn_init_2537;
(f[2]=((false)?(({(x-(q*y));})):(({fmod(x,y);}))));
__auto_type cn_init_2569 = ((uint64_t)(fabs(q))); __auto_type qi = cn_init_2569;
(fsw=(((((((qi&4)!=0))?(({0x0100;})):(({0;}))))|(((((qi&2)!=0))?(({0x4000;})):(({0;})))))|(((((qi&1)!=0))?(({0x0200;})):(({0;}))))));
}
(f[2]=(exp2(f[2])-1.0));
(f[1]=(f[1]+f[2]));
(f[1]*=exp2(trunc(f[0])));
cn_swap(f,1,0);
(f[1]=f[1]);
{
__auto_type cn_init_2715 = cn_double(((((((v23>>32))|((v24<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2715;
(f[0]=(f[0]+v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(v33));
(f[1]=cn_double(s2011));
(f[1]=(f[1]*f[1]));
(f[2]=cn_double(s2010));
(f[2]=(f[2]*f[2]));
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]/f[1]));
(s2009=cn_bits(f[0]));
(f[0]=-f[0]);
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_2922 = cn_double(s2012); __auto_type v = cn_init_2922;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2012));
{
__auto_type cn_init_2958 = cn_double(s2010); __auto_type v = cn_init_2958;
(f[1]=(f[1]*v));
}
{
__auto_type cn_init_2982 = cn_double(s2009); __auto_type v = cn_init_2982;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2012));
{
__auto_type cn_init_3018 = cn_double(s2011); __auto_type v = cn_init_3018;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_3042 = cn_double(s2009); __auto_type v = cn_init_3042;
(f[2]=(f[2]*v));
}
(r5=cn_bits(f[2]));
(r4=cn_bits(f[1]));
{
__auto_type cn_init_3104 = cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3104;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s2007>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2008>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2008>>32))&0xffffffffULL)))));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_6e5886c6b8245080(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2014=UINT64_C(0xfffffff000000000);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(f[0]=cn_double(r4));
(f[0]=-f[0]);
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=-f[0]);
(r5=cn_bits(f[0]));
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}

cn_break_body:;
return (Vec){z.x,cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_706f52a872fbf811(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2014=UINT64_C(0xfffffff000000000);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(f[0]=cn_double(r4));
{
__auto_type cn_tuple_194_0 = sin(f[0]);
__auto_type cn_tuple_194_1 = cos(f[0]);
__auto_type s = cn_tuple_194_0;
__auto_type c = cn_tuple_194_1;
(f[0]=s);
(f[1]=c);
(fsw&=~0x0400);
}
(f[2]=cn_double(r5));
{
__auto_type cn_tuple_243_0 = sin(f[2]);
__auto_type cn_tuple_243_1 = cos(f[2]);
__auto_type s = cn_tuple_243_0;
__auto_type c = cn_tuple_243_1;
(f[2]=s);
(f[3]=c);
(fsw&=~0x0400);
}
cn_swap(f,3,1);
{
__auto_type cn_init_283 = cn_double(r3); __auto_type v = cn_init_283;
(f[3]=(f[3]*v));
}
(r5=cn_bits(f[3]));
cn_swap(f,2,0);
(f[1]=(f[1]*f[2]));
cn_swap(f,2,1);
{
__auto_type cn_init_351 = cn_double(r3); __auto_type v = cn_init_351;
(f[2]=(f[2]*v));
}
cn_swap(f,2,0);
cn_swap(f,2,1);
{
__auto_type cn_init_393 = cn_double(r3); __auto_type v = cn_init_393;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]*f[2]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_70eaf2b0be9e4ef8(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v28=cn_cell(vm,0);
uint64_t v29=cn_cell(vm,8);
uint64_t v30=cn_cell(vm,16);

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
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[1])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[1])))&0xffffffffULL))<<32))));
(rg[1]=rg[0]);
(rg[0]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r3));
(rg[0]=rg[3]);
{
__auto_type cn_init_542 = 0x10U; __auto_type bv = cn_init_542;
__auto_type cn_init_550 = rg[0]; __auto_type av = cn_init_550;
__auto_type cn_init_568 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_568;
(rg[0]=r);
}
(fsw=cn_compare(f[0],cn_double(v30)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_630 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_630;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,6)){
goto cn_break_b2;
}
(rg[0]=rg[3]);
{
__auto_type cn_init_709 = 0x10U; __auto_type bv = cn_init_709;
__auto_type cn_init_717 = rg[0]; __auto_type av = cn_init_717;
__auto_type cn_init_735 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_735;
(rg[0]=r);
}
(rg[6]=((uint32_t)(((((v30>>0))&0xffffffffULL)))));
(r3=(((r3&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
(rg[6]=((uint32_t)(((((v30>>32))&0xffffffffULL)))));
(r3=(((r3&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
cn_break_b2:;
(f[0]=cn_double(r4));
(rg[0]=rg[3]);
{
__auto_type cn_init_866 = 0x18U; __auto_type bv = cn_init_866;
__auto_type cn_init_874 = rg[0]; __auto_type av = cn_init_874;
__auto_type cn_init_892 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_892;
(rg[0]=r);
}
(fsw=cn_compare(f[0],cn_double(v29)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_954 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_954;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,6)){
goto cn_break_b4;
}
(rg[0]=rg[3]);
{
__auto_type cn_init_1033 = 0x18U; __auto_type bv = cn_init_1033;
__auto_type cn_init_1041 = rg[0]; __auto_type av = cn_init_1041;
__auto_type cn_init_1059 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_1059;
(rg[0]=r);
}
(rg[1]=((uint32_t)(((((v29>>0))&0xffffffffULL)))));
(r4=(((r4&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[1])))&0xffffffffULL))<<0))));
(rg[1]=((uint32_t)(((((v29>>32))&0xffffffffULL)))));
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[1])))&0xffffffffULL))<<32))));
}
cn_break_b4:;
(rg[0]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
(f[0]=cn_double(r5));
(rg[0]=rg[3]);
{
__auto_type cn_init_1207 = 0x20U; __auto_type bv = cn_init_1207;
__auto_type cn_init_1215 = rg[0]; __auto_type av = cn_init_1215;
__auto_type cn_init_1233 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_1233;
(rg[0]=r);
}
(fsw=cn_compare(f[0],cn_double(v28)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_1295 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1295;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,6)){
goto cn_break_b6;
}
(rg[0]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
{
__auto_type cn_init_1381 = 0x20U; __auto_type bv = cn_init_1381;
__auto_type cn_init_1389 = rg[3]; __auto_type av = cn_init_1389;
__auto_type cn_init_1407 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_1407;
(rg[3]=r);
}
(rg[2]=((uint32_t)(((((v28>>0))&0xffffffffULL)))));
(r5=(((r5&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[2])))&0xffffffffULL))<<0))));
(rg[2]=((uint32_t)(((((v28>>32))&0xffffffffULL)))));
(r5=(((r5&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[2])))&0xffffffffULL))<<32))));
}
cn_break_b6:;
{
(rg[6]=((uint32_t)(((((s2012>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2013>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[1]=((uint32_t)(((((s2013>>32))&0xffffffffULL)))));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_71785d1d5a875d8d(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v18=cn_cell(vm,0);
uint64_t v19=cn_cell(vm,8);
uint64_t v20=cn_cell(vm,16);
uint64_t v21=cn_cell(vm,24);
uint64_t v22=cn_cell(vm,32);
uint64_t v23=cn_cell(vm,40);
uint64_t v24=cn_cell(vm,48);
uint64_t v25=cn_cell(vm,56);
uint64_t v26=cn_cell(vm,64);
uint64_t v27=cn_cell(vm,72);
uint64_t v28=cn_cell(vm,80);
uint64_t v29=cn_cell(vm,88);
uint64_t v30=cn_cell(vm,96);

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
__auto_type cn_init_684 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_684;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_732 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_732;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_795 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_795;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_858 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_858;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_906 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_906;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_969 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_969;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1031 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1031;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1078 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1078;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1140 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1140;
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
__auto_type cn_init_1461 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1461;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_1509 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1509;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1572 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1572;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_1635 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1635;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1683 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1683;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1746 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1746;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_1808 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1808;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_1855 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1855;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1917 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1917;
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
__auto_type cn_init_2098 = cn_double(v29); __auto_type v = cn_init_2098;
(f[5]=(f[5]*v));
}
(f[1]=(f[1]-f[5]));
{
__auto_type cn_init_2137 = cn_double(v28); __auto_type v = cn_init_2137;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]-f[4]));
{
__auto_type cn_init_2176 = cn_double(v27); __auto_type v = cn_init_2176;
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_7179dcb1d7591178(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v16=cn_cell(vm,0);
uint64_t v17=cn_cell(vm,8);
uint64_t v18=cn_cell(vm,16);
uint64_t v19=cn_cell(vm,24);
uint64_t v20=cn_cell(vm,32);
uint64_t v21=cn_cell(vm,40);
uint64_t v22=cn_cell(vm,48);
uint64_t v23=cn_cell(vm,56);
uint64_t v24=cn_cell(vm,64);
uint64_t v25=cn_cell(vm,72);
uint64_t v26=cn_cell(vm,80);
uint64_t v27=cn_cell(vm,88);
uint64_t v28=cn_cell(vm,96);
uint64_t v29=cn_cell(vm,104);
uint64_t v30=cn_cell(vm,112);

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
{
__auto_type cn_init_612 = 0x7fffffffU; __auto_type v = cn_init_612;
(rg[0]=v);
}
{
__auto_type cn_init_629 = rg[0]; __auto_type bv = cn_init_629;
__auto_type cn_init_646 = (((uint32_t)(((((r5>>32))&0xffffffffULL))))); __auto_type av = cn_init_646;
__auto_type cn_init_664 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_664;
(r5=(((r5&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_703 = rg[0]; __auto_type bv = cn_init_703;
__auto_type cn_init_720 = (((uint32_t)(((((r4>>32))&0xffffffffULL))))); __auto_type av = cn_init_720;
__auto_type cn_init_738 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_738;
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_777 = rg[0]; __auto_type bv = cn_init_777;
__auto_type cn_init_794 = (((uint32_t)(((((r3>>32))&0xffffffffULL))))); __auto_type av = cn_init_794;
__auto_type cn_init_812 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_812;
(r3=(((r3&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_913 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_913;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_961 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_961;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1024 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1024;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1087 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1087;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1135 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1135;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1198 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1198;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1260 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1260;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1307 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1307;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1369 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1369;
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
(f[3]=cn_double(v30));
(f[4]=cn_double(r6));
(f[4]=(f[4]*f[3]));
(r6=cn_bits(f[4]));
(f[0]=(f[0]*f[3]));
(f[1]=(f[1]*f[3]));
(f[2]=(f[2]*f[3]));
(f[3]=f[3]);
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_1807 = cn_double(v30); __auto_type v = cn_init_1807;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_1831 = cn_double(v16); __auto_type v = cn_init_1831;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
(f[0]=(f[1]-f[0]));
(r3=cn_bits(f[0]));
(f[0]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_1905 = cn_double(v30); __auto_type v = cn_init_1905;
(f[0]=(v-f[0]));
}
{
__auto_type cn_init_1929 = cn_double(v17); __auto_type v = cn_init_1929;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
(f[1]=(f[1]+f[0]));
(f[1]=fabs(f[1]));
(f[2]=cn_double(r3));
(f[2]=(f[2]-f[0]));
(f[2]=fabs(f[2]));
(f[2]=-f[2]);
{
__auto_type cn_init_2046 = cn_double(r3); __auto_type v = cn_init_2046;
(f[2]=(f[2]-v));
}
(f[1]=(f[1]+f[2]));
(r3=cn_bits(f[1]));
(f[0]=f[0]);
(f[0]=cn_double(r5));
(f[1]=cn_double(r3));
(f[2]=cn_double(r4));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b8;
}
cn_swap(f,2,1);
}
cn_break_b8:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b10;
}
cn_swap(f,2,0);
}
cn_break_b10:;
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b12;
}
cn_swap(f,2,0);
}
cn_break_b12:;
(f[3]=f[1]);
{
__auto_type cn_init_2415 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2415;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_2463 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2463;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2526 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2526;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_2589 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2589;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_2637 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2637;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2700 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2700;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_2762 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2762;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_2809 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2809;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2871 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2871;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(v30));
(f[4]=cn_double(0x3ff0000000000000));
(f[3]=(f[3]-f[4]));
(f[4]=f[3]);
(f[5]=f[4]);
{
__auto_type cn_init_2969 = cn_double(v27); __auto_type v = cn_init_2969;
(f[5]=(f[5]*v));
}
(f[1]=(f[1]-f[5]));
{
__auto_type cn_init_3008 = cn_double(v28); __auto_type v = cn_init_3008;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]-f[4]));
{
__auto_type cn_init_3047 = cn_double(v29); __auto_type v = cn_init_3047;
(f[3]=(f[3]*v));
}
(f[0]=(f[3]-f[0]));
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_747c6c9d1edf0d4e(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v28=cn_cell(vm,0);
uint64_t v29=cn_cell(vm,8);
uint64_t v30=cn_cell(vm,16);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_761967f9cfb5d4ab(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v23=cn_cell(vm,0);
uint64_t v24=cn_cell(vm,8);
uint64_t v25=cn_cell(vm,16);
uint64_t v26=cn_cell(vm,24);
uint64_t v27=cn_cell(vm,32);
uint64_t v28=cn_cell(vm,40);
uint64_t v29=cn_cell(vm,48);
uint64_t v30=cn_cell(vm,56);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_7820bdda2a825c7e(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v24=cn_cell(vm,0);
uint64_t v25=cn_cell(vm,8);
uint64_t v26=cn_cell(vm,16);
uint64_t v27=cn_cell(vm,24);
uint64_t v28=cn_cell(vm,32);
uint64_t v29=cn_cell(vm,40);
uint64_t v30=cn_cell(vm,48);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_789b0e6fa175e144(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r4=cn_bits(z.y);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v25=cn_cell(vm,0);
uint64_t v26=cn_cell(vm,8);
uint64_t v27=cn_cell(vm,16);
uint64_t v28=cn_cell(vm,24);
uint64_t v29=cn_cell(vm,32);
uint64_t v30=cn_cell(vm,40);

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
return (Vec){z.x,cn_double(r4),z.z};
}
static inline Vec cf_pure_7a6c90aeb7f60905(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r5=cn_bits(z.z);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){z.x,z.y,cn_double(r5)};
}
static inline Vec cf_pure_7db073976a2f1e2e(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v25=cn_cell(vm,0);
uint64_t v26=cn_cell(vm,8);
uint64_t v27=cn_cell(vm,16);
uint64_t v28=cn_cell(vm,24);
uint64_t v29=cn_cell(vm,32);
uint64_t v30=cn_cell(vm,40);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_7efcd46b624cb1bb(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);
uint64_t v32=cn_cell(vm,24);
uint64_t v33=cn_cell(vm,32);
uint64_t v34=cn_cell(vm,40);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_7f9fef6fa0413ff0(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_7fb5cdafeec5dbf0(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t s2014=UINT64_C(0xfffffff000000000);

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
return (Vec){cn_double(r3),cn_double(r4),z.z};
}
static inline Vec cf_pure_85d2e5da4f43de0e(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2003=0;
uint64_t s2004=0;
uint64_t s2005=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v16=cn_cell(vm,0);
uint64_t v17=cn_cell(vm,8);
uint64_t v18=cn_cell(vm,16);
uint64_t v19=cn_cell(vm,24);
uint64_t v20=cn_cell(vm,32);
uint64_t v21=cn_cell(vm,40);
uint64_t v22=cn_cell(vm,48);
uint64_t v23=cn_cell(vm,56);
uint64_t v24=cn_cell(vm,64);
uint64_t v25=cn_cell(vm,72);
uint64_t v26=cn_cell(vm,80);
uint64_t v27=cn_cell(vm,88);
uint64_t v28=cn_cell(vm,96);
uint64_t v29=cn_cell(vm,104);
uint64_t v30=cn_cell(vm,112);

{
{
{
{
{
{
{
{
{
{
{
{
{
{
{
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_889ae4f4102ead81(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

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
return (Vec){z.x,z.y,cn_double(r5)};
}
static inline Vec cf_pure_8a7908c7e72f01c6(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_8ad16c5350b999d7(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2010=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);
uint64_t v32=cn_cell(vm,24);
uint64_t v33=cn_cell(vm,32);
uint64_t v34=cn_cell(vm,40);
uint64_t v35=cn_cell(vm,48);
uint64_t v36=cn_cell(vm,56);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_8b8b7877060a52b7(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v20=cn_cell(vm,0);
uint64_t v21=cn_cell(vm,8);
uint64_t v22=cn_cell(vm,16);
uint64_t v23=cn_cell(vm,24);
uint64_t v24=cn_cell(vm,32);
uint64_t v25=cn_cell(vm,40);
uint64_t v26=cn_cell(vm,48);
uint64_t v27=cn_cell(vm,56);
uint64_t v28=cn_cell(vm,64);
uint64_t v29=cn_cell(vm,72);
uint64_t v30=cn_cell(vm,80);
uint64_t v32=cn_cell(vm,96);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_8e56fc6ffe930349(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);
uint64_t v32=cn_cell(vm,48);
uint64_t v33=cn_cell(vm,56);
uint64_t v34=cn_cell(vm,64);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_8f3653401b1e95a6(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_8f5d0319bab0a995(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2010=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);
uint64_t v32=cn_cell(vm,16);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_8ff344f00b5b64dd(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_90df87328b904240(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_939f180fc0184ac7(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_99355b3a19457e8c(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v18=cn_cell(vm,0);
uint64_t v19=cn_cell(vm,8);
uint64_t v20=cn_cell(vm,16);
uint64_t v21=cn_cell(vm,24);
uint64_t v22=cn_cell(vm,32);
uint64_t v23=cn_cell(vm,40);
uint64_t v24=cn_cell(vm,48);
uint64_t v25=cn_cell(vm,56);
uint64_t v26=cn_cell(vm,64);
uint64_t v27=cn_cell(vm,72);
uint64_t v28=cn_cell(vm,80);
uint64_t v29=cn_cell(vm,88);
uint64_t v30=cn_cell(vm,96);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_9e2252b50e598467(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2003=0;
uint64_t s2004=0;
uint64_t s2005=0;
uint64_t s2006=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v22=cn_cell(vm,0);
uint64_t v23=cn_cell(vm,8);
uint64_t v24=cn_cell(vm,16);
uint64_t v25=cn_cell(vm,24);
uint64_t v26=cn_cell(vm,32);
uint64_t v27=cn_cell(vm,40);
uint64_t v28=cn_cell(vm,48);
uint64_t v29=cn_cell(vm,56);
uint64_t v30=cn_cell(vm,64);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_a11ae827485a8b8b(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v17=cn_cell(vm,0);
uint64_t v18=cn_cell(vm,8);
uint64_t v19=cn_cell(vm,16);
uint64_t v20=cn_cell(vm,24);
uint64_t v21=cn_cell(vm,32);
uint64_t v22=cn_cell(vm,40);
uint64_t v23=cn_cell(vm,48);
uint64_t v24=cn_cell(vm,56);
uint64_t v25=cn_cell(vm,64);
uint64_t v26=cn_cell(vm,72);
uint64_t v27=cn_cell(vm,80);
uint64_t v28=cn_cell(vm,88);
uint64_t v29=cn_cell(vm,96);
uint64_t v30=cn_cell(vm,104);
uint64_t v32=cn_cell(vm,120);
uint64_t v33=cn_cell(vm,128);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_a1f064eaf002bf06(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v16=cn_cell(vm,0);
uint64_t v17=cn_cell(vm,8);
uint64_t v18=cn_cell(vm,16);
uint64_t v19=cn_cell(vm,24);
uint64_t v20=cn_cell(vm,32);
uint64_t v21=cn_cell(vm,40);
uint64_t v22=cn_cell(vm,48);
uint64_t v23=cn_cell(vm,56);
uint64_t v24=cn_cell(vm,64);
uint64_t v25=cn_cell(vm,72);
uint64_t v26=cn_cell(vm,80);
uint64_t v27=cn_cell(vm,88);
uint64_t v28=cn_cell(vm,96);
uint64_t v29=cn_cell(vm,104);
uint64_t v30=cn_cell(vm,112);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_a20b4efe403de33c(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v25=cn_cell(vm,0);
uint64_t v26=cn_cell(vm,8);
uint64_t v27=cn_cell(vm,16);
uint64_t v28=cn_cell(vm,24);
uint64_t v29=cn_cell(vm,32);
uint64_t v30=cn_cell(vm,40);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_a4250598b4a80ded(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_a54e8329bc37d850(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_a6dbf2766292a63e(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2014=UINT64_C(0xfffffff000000000);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_a7936171b561b3d0(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v22=cn_cell(vm,0);
uint64_t v23=cn_cell(vm,8);
uint64_t v24=cn_cell(vm,16);
uint64_t v25=cn_cell(vm,24);
uint64_t v26=cn_cell(vm,32);
uint64_t v27=cn_cell(vm,40);
uint64_t v28=cn_cell(vm,48);
uint64_t v29=cn_cell(vm,56);
uint64_t v30=cn_cell(vm,64);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_a85da18b6fe095bc(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

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
return (Vec){cn_double(r3),cn_double(r4),z.z};
}
static inline Vec cf_pure_a9861b5923bb62f5(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v19=cn_cell(vm,0);
uint64_t v20=cn_cell(vm,8);
uint64_t v21=cn_cell(vm,16);
uint64_t v22=cn_cell(vm,24);
uint64_t v23=cn_cell(vm,32);
uint64_t v24=cn_cell(vm,40);
uint64_t v25=cn_cell(vm,48);
uint64_t v26=cn_cell(vm,56);
uint64_t v27=cn_cell(vm,64);
uint64_t v28=cn_cell(vm,72);
uint64_t v29=cn_cell(vm,80);
uint64_t v30=cn_cell(vm,88);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_aba37e0cdc6ee259(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);
uint64_t v32=cn_cell(vm,48);
uint64_t v33=cn_cell(vm,56);
uint64_t v34=cn_cell(vm,64);

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
__auto_type cn_init_560 = (((double)(cn_float(((uint32_t)(((((v27>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_560;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_608 = (((double)(cn_float(((uint32_t)(((((v27>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_608;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_671 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_671;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_748 = (((double)(cn_float(((uint32_t)(((((v30>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_748;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_796 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_796;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_859 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_859;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[4]=fabs(f[4]));
cn_swap(f,4,2);
{
__auto_type cn_init_935 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_935;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_982 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_982;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1044 = (((double)(cn_float(((uint32_t)(((((v28>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1044;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
cn_swap(f,2,1);
(f[2]=fabs(f[2]));
cn_swap(f,2,1);
(f[3]=f[2]);
{
__auto_type cn_init_1125 = cn_double(v32); __auto_type v = cn_init_1125;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1159 = cn_double(v33); __auto_type v = cn_init_1159;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1208 = cn_double(v34); __auto_type v = cn_init_1208;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(fsw=cn_compare(f[3],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
(f[3]=(f[3]+f[3]));
(f[4]=cn_double(v33));
(f[5]=cn_double(v32));
(f[6]=cn_double(v34));
cn_swap(f,6,3);
(f[3]=(f[3]*f[6]));
(f[4]=(f[4]*f[6]));
(f[5]=(f[5]*f[6]));
(f[2]=(f[2]-f[5]));
(f[1]=(f[1]-f[4]));
(f[0]=(f[0]-f[3]));
}
cn_break_b2:;
(f[3]=f[3]);
cn_swap(f,2,1);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
cn_swap(f,2,1);
(f[3]=f[2]);
{
__auto_type cn_init_1549 = cn_double(v32); __auto_type v = cn_init_1549;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1583 = cn_double(v33); __auto_type v = cn_init_1583;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1632 = cn_double(v34); __auto_type v = cn_init_1632;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(fsw=cn_compare(f[3],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
(f[3]=(f[3]+f[3]));
(f[4]=cn_double(v33));
(f[5]=cn_double(v32));
(f[6]=cn_double(v34));
cn_swap(f,6,3);
(f[3]=(f[3]*f[6]));
(f[4]=(f[4]*f[6]));
(f[5]=(f[5]*f[6]));
(f[2]=(f[2]-f[5]));
(f[1]=(f[1]-f[4]));
(f[0]=(f[0]-f[3]));
}
cn_break_b4:;
(f[3]=f[3]);
cn_swap(f,2,1);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
cn_swap(f,2,1);
(f[3]=f[2]);
{
__auto_type cn_init_1973 = cn_double(v32); __auto_type v = cn_init_1973;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_2007 = cn_double(v33); __auto_type v = cn_init_2007;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2056 = cn_double(v34); __auto_type v = cn_init_2056;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(fsw=cn_compare(f[3],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b6;
}
(f[3]=(f[3]+f[3]));
(f[4]=cn_double(v33));
(f[5]=cn_double(v32));
(f[6]=cn_double(v34));
cn_swap(f,6,3);
(f[3]=(f[3]*f[6]));
(f[4]=(f[4]*f[6]));
(f[5]=(f[5]*f[6]));
(f[2]=(f[2]-f[5]));
(f[1]=(f[1]-f[4]));
(f[0]=(f[0]-f[3]));
}
cn_break_b6:;
(f[3]=f[3]);
cn_swap(f,2,1);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_ac3ff5358b339fc8(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);

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
(f[0]=fabs(f[0]));
(f[1]=cn_double(r4));
(f[1]=fabs(f[1]));
(f[2]=cn_double(r3));
(f[2]=fabs(f[2]));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_442 = 0x41U; __auto_type bv = cn_init_442;
__auto_type cn_init_455 = cn_reg_get(rg,4,1); __auto_type av = cn_init_455;
__auto_type cn_init_473 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_473;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b2;
}
cn_swap(f,2,1);
}
cn_break_b2:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_552 = 0x41U; __auto_type bv = cn_init_552;
__auto_type cn_init_565 = cn_reg_get(rg,4,1); __auto_type av = cn_init_565;
__auto_type cn_init_583 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_583;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b4;
}
cn_swap(f,2,0);
}
cn_break_b4:;
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
{
__auto_type cn_init_671 = 0x41U; __auto_type bv = cn_init_671;
__auto_type cn_init_684 = cn_reg_get(rg,4,1); __auto_type av = cn_init_684;
__auto_type cn_init_702 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_702;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b6;
}
cn_swap(f,2,0);
}
cn_break_b6:;
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_ad57da69411cd8be(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r3=cn_bits(z.x);
uint64_t r5=cn_bits(z.z);
uint64_t s2014=UINT64_C(0xfffffff000000000);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(f[0]=cn_double(r5));
(f[1]=cn_double(r3));
(r5=cn_bits(f[1]));
(r3=cn_bits(f[0]));
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}

cn_break_body:;
return (Vec){cn_double(r3),z.y,cn_double(r5)};
}
static inline Vec cf_pure_b2453fefc3b1431c(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);

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
__auto_type cn_init_371 = (((uint32_t)(((((r5>>56))&0xffULL))))); __auto_type v = cn_init_371;
cn_reg_set(rg,2,1,v);
}
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_427 = cn_double(v30); __auto_type v = cn_init_427;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_446 = 0x80U; __auto_type bv = cn_init_446;
__auto_type cn_init_459 = cn_reg_get(rg,2,1); __auto_type av = cn_init_459;
__auto_type cn_init_477 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_477;
cn_reg_set(rg,2,1,r);
}
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[0]=-f[0]);
{
__auto_type cn_init_540 = cn_double(v29); __auto_type v = cn_init_540;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
{
__auto_type cn_init_578 = cn_reg_get(rg,2,1); __auto_type bv = cn_init_578;
__auto_type cn_init_595 = (((uint32_t)(((((r5>>56))&0xffULL))))); __auto_type av = cn_init_595;
__auto_type cn_init_613 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_613;
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
return (Vec){z.x,z.y,cn_double(r5)};
}
static inline Vec cf_pure_b31dd057e6ca45d3(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v32=cn_cell(vm,0);
uint64_t v33=cn_cell(vm,8);
uint64_t v34=cn_cell(vm,16);

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
(fsw=cn_compare(f[1],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_631 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_631;
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
__auto_type cn_init_891 = 0x41U; __auto_type bv = cn_init_891;
__auto_type cn_init_904 = cn_reg_get(rg,4,1); __auto_type av = cn_init_904;
__auto_type cn_init_922 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_922;
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
__auto_type cn_init_1004 = cn_double(v33); __auto_type v = cn_init_1004;
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
__auto_type cn_init_1270 = 0x41U; __auto_type bv = cn_init_1270;
__auto_type cn_init_1283 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1283;
__auto_type cn_init_1301 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1301;
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_b4cf373b9466e13e(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
(f[1]=cn_double(v27));
(f[0]=(f[0]*f[1]));
(r6=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[1]=cn_double(v28));
(f[0]=(f[0]*f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[1]=cn_double(v29));
(f[0]=(f[0]*f[1]));
(r4=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[1]=cn_double(v30));
(f[0]=(f[0]*f[1]));
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_b5d34f8186a0b281(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v19=cn_cell(vm,0);
uint64_t v20=cn_cell(vm,8);
uint64_t v21=cn_cell(vm,16);
uint64_t v22=cn_cell(vm,24);
uint64_t v23=cn_cell(vm,32);
uint64_t v24=cn_cell(vm,40);
uint64_t v25=cn_cell(vm,48);
uint64_t v26=cn_cell(vm,56);
uint64_t v27=cn_cell(vm,64);
uint64_t v28=cn_cell(vm,72);
uint64_t v29=cn_cell(vm,80);
uint64_t v30=cn_cell(vm,88);

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
(f[3]=f[2]);
{
__auto_type cn_init_579 = cn_double(v29); __auto_type v = cn_init_579;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_613 = cn_double(v28); __auto_type v = cn_init_613;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_662 = cn_double(v27); __auto_type v = cn_init_662;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_701 = cn_double(v30); __auto_type v = cn_init_701;
(f[3]=(f[3]+v));
}
(f[4]=f[2]);
(f[4]=(f[4]-f[3]));
(f[4]=fabs(f[4]));
cn_swap(f,4,3);
(f[4]=(f[4]+f[2]));
(f[4]=fabs(f[4]));
(f[3]=(f[4]-f[3]));
(f[3]=(f[3]-f[2]));
(f[4]=f[2]);
{
__auto_type cn_init_842 = cn_double(v25); __auto_type v = cn_init_842;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_876 = cn_double(v24); __auto_type v = cn_init_876;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_925 = cn_double(v23); __auto_type v = cn_init_925;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
{
__auto_type cn_init_964 = cn_double(v26); __auto_type v = cn_init_964;
(f[4]=(f[4]+v));
}
(f[5]=f[1]);
(f[5]=(f[5]-f[4]));
(f[5]=fabs(f[5]));
cn_swap(f,5,4);
(f[5]=(f[5]+f[1]));
(f[5]=fabs(f[5]));
(f[4]=(f[5]-f[4]));
(f[4]=(f[4]-f[1]));
cn_swap(f,4,2);
{
__auto_type cn_init_1104 = cn_double(v21); __auto_type v = cn_init_1104;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1137 = cn_double(v20); __auto_type v = cn_init_1137;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1186 = cn_double(v19); __auto_type v = cn_init_1186;
(f[4]=(f[4]*v));
}
{
__auto_type cn_init_1210 = cn_double(v22); __auto_type v = cn_init_1210;
(f[4]=(f[4]+v));
}
(f[1]=(f[1]+f[4]));
(f[4]=f[1]);
(f[4]=(f[4]-f[0]));
(f[4]=fabs(f[4]));
cn_swap(f,4,1);
(f[4]=(f[4]+f[0]));
(f[4]=fabs(f[4]));
(f[1]=(f[4]-f[1]));
cn_swap(f,3,0);
(f[1]=(f[1]-f[3]));
(r4=cn_bits(f[2]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_b79b4e171c1ff1e4(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);

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
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[3]=f[1]);
(f[3]=(f[3]*f[1]));
(f[4]=f[2]);
(f[4]=(f[4]*f[2]));
(f[5]=f[4]);
(f[5]=(f[5]+f[3]));
(f[6]=f[5]);
(f[6]=sqrt(f[6]));
{
__auto_type cn_init_508 = cn_double(v29); __auto_type v = cn_init_508;
(f[6]=(f[6]*v));
}
(f[6]=(f[6]*f[0]));
(f[6]=(f[6]+f[6]));
(r5=cn_bits(f[6]));
(f[6]=f[0]);
(f[0]=(f[0]*f[6]));
(f[6]=f[5]);
(f[0]=(f[6]-f[0]));
(f[0]=(f[0]/f[5]));
(f[3]=(f[4]-f[3]));
(f[3]=(f[3]*f[0]));
(r3=cn_bits(f[3]));
(f[1]=(f[1]*f[2]));
(f[0]=(f[0]*f[1]));
(f[0]=(f[0]+f[0]));
{
__auto_type cn_init_724 = cn_double(v30); __auto_type v = cn_init_724;
(f[0]=(f[0]*v));
}
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_b8c0565aa1a8fd35(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2010=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

{
{
{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_328 = 0x30U; __auto_type bv = cn_init_328;
__auto_type cn_init_336 = rg[4]; __auto_type av = cn_init_336;
__auto_type cn_init_354 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_354;
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
__auto_type cn_init_693 = 0x41U; __auto_type bv = cn_init_693;
__auto_type cn_init_706 = cn_reg_get(rg,4,1); __auto_type av = cn_init_706;
__auto_type cn_init_724 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_724;
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
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[1]=f[0]);
{
__auto_type cn_init_867 = cn_double(r4); __auto_type v = cn_init_867;
(f[1]=(f[1]*v));
}
(s2013=cn_bits(f[1]));
(f[1]=(f[1]*f[1]));
(s2010=cn_bits(f[1]));
{
__auto_type cn_init_928 = cn_double(r5); __auto_type v = cn_init_928;
(f[0]=(f[0]*v));
}
(s2012=cn_bits(f[0]));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_978 = cn_double(s2010); __auto_type v = cn_init_978;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r3));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_1088 = 0x41U; __auto_type bv = cn_init_1088;
__auto_type cn_init_1101 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1101;
__auto_type cn_init_1119 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1119;
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
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
{
__auto_type cn_init_1252 = cn_double(v30); __auto_type v = cn_init_1252;
(f[0]=(f[0]*v));
}
(s2011=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1299 = cn_double(s2011); __auto_type v = cn_init_1299;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1335 = cn_double(s2011); __auto_type v = cn_init_1335;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(s2012));
{
__auto_type cn_init_1371 = cn_double(s2011); __auto_type v = cn_init_1371;
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_bd743493286d2fa8(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v18=cn_cell(vm,0);
uint64_t v19=cn_cell(vm,8);
uint64_t v20=cn_cell(vm,16);
uint64_t v21=cn_cell(vm,24);
uint64_t v22=cn_cell(vm,32);
uint64_t v23=cn_cell(vm,40);
uint64_t v24=cn_cell(vm,48);
uint64_t v25=cn_cell(vm,56);
uint64_t v26=cn_cell(vm,64);
uint64_t v27=cn_cell(vm,72);
uint64_t v28=cn_cell(vm,80);
uint64_t v29=cn_cell(vm,88);
uint64_t v30=cn_cell(vm,96);
uint64_t v31=cn_cell(vm,104);

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
__auto_type cn_init_593 = 0x7fffffffU; __auto_type v = cn_init_593;
(rg[0]=v);
}
{
__auto_type cn_init_610 = rg[0]; __auto_type bv = cn_init_610;
__auto_type cn_init_627 = (((uint32_t)(((((r5>>32))&0xffffffffULL))))); __auto_type av = cn_init_627;
__auto_type cn_init_645 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_645;
(r5=(((r5&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_684 = rg[0]; __auto_type bv = cn_init_684;
__auto_type cn_init_701 = (((uint32_t)(((((r4>>32))&0xffffffffULL))))); __auto_type av = cn_init_701;
__auto_type cn_init_719 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_719;
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_758 = rg[0]; __auto_type bv = cn_init_758;
__auto_type cn_init_775 = (((uint32_t)(((((r3>>32))&0xffffffffULL))))); __auto_type av = cn_init_775;
__auto_type cn_init_793 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_793;
(r3=(((r3&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_894 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_894;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_942 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_942;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1005 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1005;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1068 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1068;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1116 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1116;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1179 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1179;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1241 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1241;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1288 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1288;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1350 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1350;
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
__auto_type cn_init_1662 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1662;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_1710 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1710;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1773 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1773;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_1836 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1836;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1884 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1884;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1947 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1947;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_2009 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2009;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_2056 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2056;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2118 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2118;
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
__auto_type cn_init_2299 = cn_double(v29); __auto_type v = cn_init_2299;
(f[5]=(f[5]*v));
}
(f[1]=(f[1]-f[5]));
{
__auto_type cn_init_2338 = cn_double(v28); __auto_type v = cn_init_2338;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]-f[4]));
{
__auto_type cn_init_2377 = cn_double(v27); __auto_type v = cn_init_2377;
(f[3]=(f[3]*v));
}
(f[4]=f[3]);
{
__auto_type cn_init_2411 = cn_double(v31); __auto_type v = cn_init_2411;
(f[4]=(f[4]*v));
}
(fsw=cn_compare(f[4],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
{
__auto_type cn_init_2467 = 0x41U; __auto_type bv = cn_init_2467;
__auto_type cn_init_2480 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2480;
__auto_type cn_init_2498 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2498;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(f[0]=(f[0]-f[3]));
}
cn_break_b8:;
(f[3]=f[3]);
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_bdee0a1f4f1c566e(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v28=cn_cell(vm,0);
uint64_t v29=cn_cell(vm,8);
uint64_t v30=cn_cell(vm,16);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_bfc76004fae4a28f(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v22=cn_cell(vm,0);
uint64_t v23=cn_cell(vm,8);
uint64_t v24=cn_cell(vm,16);
uint64_t v25=cn_cell(vm,24);
uint64_t v26=cn_cell(vm,32);
uint64_t v27=cn_cell(vm,40);
uint64_t v28=cn_cell(vm,48);
uint64_t v29=cn_cell(vm,56);
uint64_t v30=cn_cell(vm,64);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_c0d951c2712fba4d(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_c2594bf5906a27ea(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v25=cn_cell(vm,0);
uint64_t v26=cn_cell(vm,8);
uint64_t v27=cn_cell(vm,16);
uint64_t v28=cn_cell(vm,24);
uint64_t v29=cn_cell(vm,32);
uint64_t v30=cn_cell(vm,40);

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
return (Vec){z.x,z.y,cn_double(r5)};
}
static inline Vec cf_pure_c5f3828c89d58fc9(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);
uint64_t v32=cn_cell(vm,24);
uint64_t v33=cn_cell(vm,32);
uint64_t v34=cn_cell(vm,40);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_c8b3802efdcf5a9b(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v26=cn_cell(vm,0);
uint64_t v27=cn_cell(vm,8);
uint64_t v28=cn_cell(vm,16);
uint64_t v29=cn_cell(vm,24);
uint64_t v30=cn_cell(vm,32);

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
return (Vec){cn_double(r3),cn_double(r4),z.z};
}
static inline Vec cf_pure_ca112d82bc2dc67f(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t s2014=UINT64_C(0xfffffff000000000);

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
return (Vec){cn_double(r3),cn_double(r4),z.z};
}
static inline Vec cf_pure_ccc969eed4f1b60e(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v24=cn_cell(vm,0);
uint64_t v25=cn_cell(vm,8);
uint64_t v26=cn_cell(vm,16);
uint64_t v27=cn_cell(vm,24);
uint64_t v28=cn_cell(vm,32);
uint64_t v29=cn_cell(vm,40);
uint64_t v30=cn_cell(vm,48);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_cd09cc47b9ba875d(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

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
return (Vec){cn_double(r3),z.y,z.z};
}
static inline Vec cf_pure_d015ffb71f7f9999(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r4=cn_bits(z.y);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);

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
__auto_type cn_init_371 = (((uint32_t)(((((r4>>56))&0xffULL))))); __auto_type v = cn_init_371;
cn_reg_set(rg,1,1,v);
}
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_427 = cn_double(v30); __auto_type v = cn_init_427;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_446 = 0x80U; __auto_type bv = cn_init_446;
__auto_type cn_init_459 = cn_reg_get(rg,1,1); __auto_type av = cn_init_459;
__auto_type cn_init_477 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_477;
cn_reg_set(rg,1,1,r);
}
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[0]=-f[0]);
{
__auto_type cn_init_540 = cn_double(v29); __auto_type v = cn_init_540;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
{
__auto_type cn_init_578 = cn_reg_get(rg,1,1); __auto_type bv = cn_init_578;
__auto_type cn_init_595 = (((uint32_t)(((((r4>>56))&0xffULL))))); __auto_type av = cn_init_595;
__auto_type cn_init_613 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_613;
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
return (Vec){z.x,cn_double(r4),z.z};
}
static inline Vec cf_pure_d02a4629db0ffb5f(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2010=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);
uint64_t v32=cn_cell(vm,24);

{
{
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
__auto_type cn_init_349 = 0x10U; __auto_type bv = cn_init_349;
__auto_type cn_init_357 = rg[4]; __auto_type av = cn_init_357;
__auto_type cn_init_375 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_375;
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
(f[0]=cn_double(0x0));
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_723 = cn_double(r4); __auto_type v = cn_init_723;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b2;
}
(f[0]=cn_double(r3));
(f[0]=-f[0]);
(f[1]=cn_double(r4));
(f[1]=-f[1]);
(r3=cn_bits(f[1]));
(r4=cn_bits(f[0]));
(f[0]=cn_double(0x3ff0000000000000));
(s2013=(((s2013&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
}
cn_break_b2:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_962 = cn_double(r5); __auto_type v = cn_init_962;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
(f[0]=cn_double(r3));
(f[0]=-f[0]);
(f[1]=cn_double(r5));
(f[1]=-f[1]);
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(0x3ff0000000000000));
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<0))));
}
cn_break_b4:;
(f[0]=cn_double(r5));
{
__auto_type cn_init_1201 = cn_double(r4); __auto_type v = cn_init_1201;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b6;
}
(f[0]=cn_double(r5));
(f[0]=-f[0]);
(f[1]=cn_double(r4));
(f[1]=-f[1]);
(r5=cn_bits(f[1]));
(r4=cn_bits(f[0]));
(f[0]=cn_double(0x3ff0000000000000));
(s2012=(((s2012&~((0xffffffffULL<<32))))|(((((((uint64_t)(cn_bits((((float)((f[0]))))))))&0xffffffffULL))<<32))));
}
cn_break_b6:;
{
__auto_type cn_init_1423 = 0x0U; __auto_type bv = cn_init_1423;
__auto_type cn_init_1440 = (((uint32_t)(((((v29>>32))&0xffffffffULL))))); __auto_type av = cn_init_1440;
__auto_type cn_init_1458 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1458;
}
if(cn_cond(fl,4)){
goto cn_break_b8;
}
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2010=(((s2010&~((0xffffffffULL<<0))))|(((((((uint64_t)((0x1000808cU))))&0xffffffffULL))<<0))));
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_1592 = cn_double(v32); __auto_type v = cn_init_1592;
(f[0]=(f[0]*v));
}
(f[0]=-f[0]);
(f[1]=cn_double(r3));
(f[1]=(f[1]+f[0]));
(f[1]=-f[1]);
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]+f[0]));
(f[1]=-f[1]);
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]+f[0]));
(f[1]=-f[1]);
(r5=cn_bits(f[1]));
(f[0]=f[0]);
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
cn_break_b8:;
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(r5));
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(v30));
(f[0]=(f[0]-f[1]));
(f[1]=f[0]);
(fsw=cn_compare(f[1],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_1941 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_1941;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
(f[1]=f[1]);
if(cn_cond(fl,2)){
goto cn_break_b10;
}
{
__auto_type cn_init_2025 = cn_double(v32); __auto_type v = cn_init_2025;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r3));
(f[1]=(f[1]-f[0]));
(r3=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[1]=(f[1]-f[0]));
(r4=cn_bits(f[1]));
(f[1]=cn_double(r5));
(f[1]=(f[1]-f[0]));
(r5=cn_bits(f[1]));
}
cn_break_b10:;
(f[0]=f[0]);
{
__auto_type cn_init_2169 = 0x0U; __auto_type bv = cn_init_2169;
__auto_type cn_init_2186 = (((uint32_t)(((((v29>>0))&0xffffffffULL))))); __auto_type av = cn_init_2186;
__auto_type cn_init_2204 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2204;
}
if(cn_cond(fl,4)){
goto cn_break_b20;
}
{
__auto_type cn_init_2223 = 0x0U; __auto_type bv = cn_init_2223;
__auto_type cn_init_2240 = (((uint32_t)(((((s2012>>32))&0xffffffffULL))))); __auto_type av = cn_init_2240;
__auto_type cn_init_2258 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2258;
}
if(cn_cond(fl,5)){
goto cn_break_b15;
}
(f[0]=cn_double(r5));
(f[0]=-f[0]);
(f[1]=cn_double(r4));
(f[1]=-f[1]);
(r5=cn_bits(f[1]));
(r4=cn_bits(f[0]));
}
cn_break_b15:;
{
__auto_type cn_init_2346 = 0x0U; __auto_type bv = cn_init_2346;
__auto_type cn_init_2363 = (((uint32_t)(((((s2013>>0))&0xffffffffULL))))); __auto_type av = cn_init_2363;
__auto_type cn_init_2381 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2381;
}
if(cn_cond(fl,5)){
goto cn_break_b17;
}
(f[0]=cn_double(r3));
(f[0]=-f[0]);
(f[1]=cn_double(r5));
(f[1]=-f[1]);
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
}
cn_break_b17:;
{
__auto_type cn_init_2469 = 0x0U; __auto_type bv = cn_init_2469;
__auto_type cn_init_2486 = (((uint32_t)(((((s2013>>32))&0xffffffffULL))))); __auto_type av = cn_init_2486;
__auto_type cn_init_2504 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_2504;
}
if(cn_cond(fl,5)){
goto cn_break_b19;
}
(f[0]=cn_double(r3));
(f[0]=-f[0]);
(f[1]=cn_double(r4));
(f[1]=-f[1]);
(r3=cn_bits(f[1]));
(r4=cn_bits(f[0]));
}
cn_break_b19:;
}
cn_break_b20:;
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_d1e51e777240591a(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);

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
__auto_type cn_init_371 = (((uint32_t)(((((r3>>56))&0xffULL))))); __auto_type v = cn_init_371;
cn_reg_set(rg,2,1,v);
}
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_427 = cn_double(v30); __auto_type v = cn_init_427;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_446 = 0x80U; __auto_type bv = cn_init_446;
__auto_type cn_init_459 = cn_reg_get(rg,2,1); __auto_type av = cn_init_459;
__auto_type cn_init_477 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_477;
cn_reg_set(rg,2,1,r);
}
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(f[0]=-f[0]);
{
__auto_type cn_init_540 = cn_double(v29); __auto_type v = cn_init_540;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
{
__auto_type cn_init_578 = cn_reg_get(rg,2,1); __auto_type bv = cn_init_578;
__auto_type cn_init_595 = (((uint32_t)(((((r3>>56))&0xffULL))))); __auto_type av = cn_init_595;
__auto_type cn_init_613 = cn_alu(&fl,Alu_Xor,av,bv,1); __auto_type r = cn_init_613;
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
return (Vec){cn_double(r3),z.y,z.z};
}
static inline Vec cf_pure_d3df2096124fd53c(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v19=cn_cell(vm,0);
uint64_t v20=cn_cell(vm,8);
uint64_t v21=cn_cell(vm,16);
uint64_t v22=cn_cell(vm,24);
uint64_t v23=cn_cell(vm,32);
uint64_t v24=cn_cell(vm,40);
uint64_t v25=cn_cell(vm,48);
uint64_t v26=cn_cell(vm,56);
uint64_t v27=cn_cell(vm,64);
uint64_t v28=cn_cell(vm,72);
uint64_t v29=cn_cell(vm,80);
uint64_t v30=cn_cell(vm,88);

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
(f[3]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]+f[3]));
(f[3]=f[3]);
(f[3]=cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]+f[3]));
(f[3]=f[3]);
(f[3]=cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[0]+f[3]));
(f[3]=f[3]);
(f[3]=f[1]);
{
__auto_type cn_init_1079 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1079;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_1127 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1127;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1190 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1190;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_1253 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1253;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1301 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1301;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1364 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1364;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_1426 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1426;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_1473 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1473;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1535 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1535;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(((((((v21>>32))|((v22<<32))))&0xffffffffffffffffULL))));
(f[1]=(f[1]-f[3]));
(f[3]=f[3]);
(f[3]=cn_double(((((((v20>>32))|((v21<<32))))&0xffffffffffffffffULL))));
(f[2]=(f[2]-f[3]));
(f[3]=f[3]);
(f[3]=cn_double(((((((v19>>32))|((v20<<32))))&0xffffffffffffffffULL))));
(f[0]=(f[0]-f[3]));
(f[3]=f[3]);
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
__auto_type cn_init_1870 = cn_double(v29); __auto_type v = cn_init_1870;
(f[6]=(f[6]*v));
}
(f[1]=(f[1]-f[6]));
{
__auto_type cn_init_1909 = cn_double(v28); __auto_type v = cn_init_1909;
(f[5]=(f[5]*v));
}
(f[2]=(f[2]-f[5]));
(f[4]=(f[4]/f[3]));
{
__auto_type cn_init_1963 = cn_double(v27); __auto_type v = cn_init_1963;
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_d532c72efd01249a(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
__auto_type cn_init_466 = cn_double(v30); __auto_type v = cn_init_466;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_490 = cn_double(v29); __auto_type v = cn_init_490;
(f[0]=(f[0]+v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_552 = cn_double(v30); __auto_type v = cn_init_552;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_576 = cn_double(v28); __auto_type v = cn_init_576;
(f[0]=(f[0]+v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=(f[0]*f[0]));
{
__auto_type cn_init_638 = cn_double(v30); __auto_type v = cn_init_638;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_662 = cn_double(v27); __auto_type v = cn_init_662;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_d5af0918cbb46f3c(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v15=cn_cell(vm,0);
uint64_t v16=cn_cell(vm,8);
uint64_t v17=cn_cell(vm,16);
uint64_t v18=cn_cell(vm,24);
uint64_t v19=cn_cell(vm,32);
uint64_t v20=cn_cell(vm,40);
uint64_t v21=cn_cell(vm,48);
uint64_t v22=cn_cell(vm,56);
uint64_t v23=cn_cell(vm,64);
uint64_t v24=cn_cell(vm,72);
uint64_t v25=cn_cell(vm,80);
uint64_t v26=cn_cell(vm,88);
uint64_t v27=cn_cell(vm,96);
uint64_t v28=cn_cell(vm,104);
uint64_t v29=cn_cell(vm,112);
uint64_t v30=cn_cell(vm,120);

{
{
{
{
{
{
{
{
{
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
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_720 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_720;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_768 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_768;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_831 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_831;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_894 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_894;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_942 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_942;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1005 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1005;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1067 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1067;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1114 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1114;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1176 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1176;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
{
__auto_type cn_init_1210 = 0x0U; __auto_type bv = cn_init_1210;
__auto_type cn_init_1227 = (((uint32_t)(((((v15>>32))&0xffffffffULL))))); __auto_type av = cn_init_1227;
__auto_type cn_init_1245 = cn_alu(&fl,Alu_Cmp,av,bv,4); __auto_type r = cn_init_1245;
}
if(cn_cond(fl,5)){
goto cn_break_b14;
}
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b3;
}
cn_swap(f,2,1);
}
cn_break_b3:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b5;
}
cn_swap(f,2,0);
}
cn_break_b5:;
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b7;
}
cn_swap(f,2,0);
}
cn_break_b7:;
(f[2]=-f[2]);
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b9;
}
cn_swap(f,2,1);
}
cn_break_b9:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b11;
}
cn_swap(f,2,0);
}
cn_break_b11:;
(f[2]=-f[2]);
cn_swap(f,2,1);
(f[2]=-f[2]);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b13;
}
cn_swap(f,2,0);
}
cn_break_b13:;
(f[2]=-f[2]);
goto cn_break_b27;
}
cn_break_b14:;
(f[2]=-f[2]);
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b16;
}
cn_swap(f,2,1);
}
cn_break_b16:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b18;
}
cn_swap(f,2,0);
}
cn_break_b18:;
(f[2]=-f[2]);
cn_swap(f,2,1);
(f[2]=-f[2]);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b20;
}
cn_swap(f,2,0);
}
cn_break_b20:;
(f[2]=-f[2]);
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b22;
}
cn_swap(f,2,1);
}
cn_break_b22:;
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b24;
}
cn_swap(f,2,0);
}
cn_break_b24:;
cn_swap(f,2,1);
(fsw=cn_compare(f[2],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2800))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b26;
}
cn_swap(f,2,0);
}
cn_break_b26:;
}
cn_break_b27:;
(f[3]=cn_double(v17));
(f[4]=cn_double(0x0));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b29;
}
(f[3]=(f[3]-f[1]));
(f[3]=fabs(f[3]));
(f[3]=-f[3]);
{
__auto_type cn_init_2510 = cn_double(v17); __auto_type v = cn_init_2510;
(f[3]=(f[3]+v));
}
cn_swap(f,3,1);
}
cn_break_b29:;
(f[3]=f[3]);
(f[3]=cn_double(v16));
(f[4]=cn_double(0x0));
(fsw=cn_compare(f[4],f[3]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b31;
}
(f[3]=(f[3]-f[2]));
(f[3]=fabs(f[3]));
(f[3]=-f[3]);
{
__auto_type cn_init_2688 = cn_double(v16); __auto_type v = cn_init_2688;
(f[3]=(f[3]+v));
}
cn_swap(f,3,2);
}
cn_break_b31:;
(f[3]=f[3]);
(f[3]=f[2]);
{
__auto_type cn_init_2756 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2756;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_2804 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2804;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2867 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2867;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_2930 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2930;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_2978 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2978;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_3041 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3041;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_3103 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3103;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_3150 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_3150;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_3212 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_3212;
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
__auto_type cn_init_3383 = cn_double(v27); __auto_type v = cn_init_3383;
(f[4]=(f[4]*v));
}
(f[0]=(f[0]-f[4]));
(f[4]=f[3]);
{
__auto_type cn_init_3432 = cn_double(v28); __auto_type v = cn_init_3432;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]-f[4]));
{
__auto_type cn_init_3471 = cn_double(v29); __auto_type v = cn_init_3471;
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_daa911bbd21a5ba2(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t s2014=UINT64_C(0xfffffff000000000);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(f[0]=cn_double(r4));
(f[1]=cn_double(r3));
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
return (Vec){cn_double(r3),cn_double(r4),z.z};
}
static inline Vec cf_pure_db586ffc50e7c8e7(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v17=cn_cell(vm,0);
uint64_t v18=cn_cell(vm,8);
uint64_t v19=cn_cell(vm,16);
uint64_t v20=cn_cell(vm,24);
uint64_t v21=cn_cell(vm,32);
uint64_t v22=cn_cell(vm,40);
uint64_t v23=cn_cell(vm,48);
uint64_t v24=cn_cell(vm,56);
uint64_t v25=cn_cell(vm,64);
uint64_t v26=cn_cell(vm,72);
uint64_t v27=cn_cell(vm,80);
uint64_t v28=cn_cell(vm,88);
uint64_t v29=cn_cell(vm,96);
uint64_t v30=cn_cell(vm,104);

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
(f[0]=(f[0]*f[0]));
(f[1]=cn_double(r4));
(f[1]=(f[1]*f[1]));
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_658 = cn_double(v29); __auto_type v = cn_init_658;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_694 = cn_double(v30); __auto_type v = cn_init_694;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=fabs(f[0]));
(f[1]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_814 = 0x41U; __auto_type bv = cn_init_814;
__auto_type cn_init_827 = cn_reg_get(rg,4,1); __auto_type av = cn_init_827;
__auto_type cn_init_845 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_845;
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
goto cn_break_b3;
}
cn_break_b2:;
(f[0]=cn_double(0x3ff0000000000000));
(f[1]=cn_double(r5));
(f[0]=(f[0]/f[1]));
(f[1]=f[0]);
(f[1]=(f[1]*f[1]));
(f[1]=-f[1]);
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[1]=sqrt(f[1]));
}
cn_break_b3:;
(f[2]=cn_double(r3));
{
__auto_type cn_init_1104 = cn_double(v28); __auto_type v = cn_init_1104;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r4));
{
__auto_type cn_init_1140 = cn_double(v27); __auto_type v = cn_init_1140;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
(f[3]=(f[3]*f[3]));
{
__auto_type cn_init_1206 = cn_double(v26); __auto_type v = cn_init_1206;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r4));
(f[3]=(f[3]*f[3]));
{
__auto_type cn_init_1272 = cn_double(v25); __auto_type v = cn_init_1272;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
{
__auto_type cn_init_1323 = cn_double(r4); __auto_type v = cn_init_1323;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_1347 = cn_double(v24); __auto_type v = cn_init_1347;
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
__auto_type cn_init_1469 = cn_double(v23); __auto_type v = cn_init_1469;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[2]=(f[2]*f[0]));
(f[3]=cn_double(r3));
{
__auto_type cn_init_1535 = cn_double(v22); __auto_type v = cn_init_1535;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r4));
{
__auto_type cn_init_1571 = cn_double(v21); __auto_type v = cn_init_1571;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
(f[4]=(f[4]*f[4]));
{
__auto_type cn_init_1637 = cn_double(v20); __auto_type v = cn_init_1637;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[4]));
{
__auto_type cn_init_1703 = cn_double(v19); __auto_type v = cn_init_1703;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
{
__auto_type cn_init_1754 = cn_double(r4); __auto_type v = cn_init_1754;
(f[4]=(f[4]*v));
}
{
__auto_type cn_init_1778 = cn_double(v18); __auto_type v = cn_init_1778;
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
__auto_type cn_init_1900 = cn_double(v17); __auto_type v = cn_init_1900;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[3]=(f[3]*f[1]));
(f[2]=(f[2]+f[3]));
(f[3]=cn_double(r3));
{
__auto_type cn_init_1981 = cn_double(v28); __auto_type v = cn_init_1981;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r4));
{
__auto_type cn_init_2017 = cn_double(v27); __auto_type v = cn_init_2017;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
(f[4]=(f[4]*f[4]));
{
__auto_type cn_init_2083 = cn_double(v26); __auto_type v = cn_init_2083;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r4));
(f[4]=(f[4]*f[4]));
{
__auto_type cn_init_2149 = cn_double(v25); __auto_type v = cn_init_2149;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=cn_double(r3));
{
__auto_type cn_init_2200 = cn_double(r4); __auto_type v = cn_init_2200;
(f[4]=(f[4]*v));
}
{
__auto_type cn_init_2224 = cn_double(v24); __auto_type v = cn_init_2224;
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
__auto_type cn_init_2346 = cn_double(v23); __auto_type v = cn_init_2346;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[3]=(f[3]*f[1]));
(f[4]=cn_double(r3));
{
__auto_type cn_init_2412 = cn_double(v22); __auto_type v = cn_init_2412;
(f[4]=(f[4]*v));
}
(f[5]=cn_double(r4));
{
__auto_type cn_init_2448 = cn_double(v21); __auto_type v = cn_init_2448;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=cn_double(r3));
(f[5]=(f[5]*f[5]));
{
__auto_type cn_init_2514 = cn_double(v20); __auto_type v = cn_init_2514;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=cn_double(r4));
(f[5]=(f[5]*f[5]));
{
__auto_type cn_init_2580 = cn_double(v19); __auto_type v = cn_init_2580;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=cn_double(r3));
{
__auto_type cn_init_2631 = cn_double(r4); __auto_type v = cn_init_2631;
(f[5]=(f[5]*v));
}
{
__auto_type cn_init_2655 = cn_double(v18); __auto_type v = cn_init_2655;
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
__auto_type cn_init_2777 = cn_double(v17); __auto_type v = cn_init_2777;
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

cn_break_body:;
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_ddde751ec8e90b97(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
(r3=cn_bits(f[0]));
{
__auto_type cn_init_776 = cn_reg_get(rg,4,1); __auto_type bv = cn_init_776;
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
return (Vec){cn_double(r3),z.y,z.z};
}
static inline Vec cf_pure_de55c3c3116fbbd7(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v18=cn_cell(vm,0);
uint64_t v19=cn_cell(vm,8);
uint64_t v20=cn_cell(vm,16);
uint64_t v21=cn_cell(vm,24);
uint64_t v22=cn_cell(vm,32);
uint64_t v23=cn_cell(vm,40);
uint64_t v24=cn_cell(vm,48);
uint64_t v25=cn_cell(vm,56);
uint64_t v26=cn_cell(vm,64);
uint64_t v27=cn_cell(vm,72);
uint64_t v28=cn_cell(vm,80);
uint64_t v29=cn_cell(vm,88);
uint64_t v30=cn_cell(vm,96);

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
__auto_type cn_init_684 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_684;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_732 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_732;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_795 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_795;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_858 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_858;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_906 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_906;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_969 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_969;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1031 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1031;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1078 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1078;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1140 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1140;
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
(f[3]=f[1]);
{
__auto_type cn_init_1505 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1505;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_1553 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1553;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1616 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1616;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_1679 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1679;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_1727 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1727;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1790 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1790;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_1852 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1852;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_1899 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1899;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1961 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1961;
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
__auto_type cn_init_2142 = cn_double(v28); __auto_type v = cn_init_2142;
(f[5]=(f[5]*v));
}
(f[1]=(f[1]-f[5]));
{
__auto_type cn_init_2181 = cn_double(v29); __auto_type v = cn_init_2181;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]-f[4]));
{
__auto_type cn_init_2220 = cn_double(v27); __auto_type v = cn_init_2220;
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_e000d141ddd3a421(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_e04801556de19bc6(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v28=cn_cell(vm,0);
uint64_t v29=cn_cell(vm,8);
uint64_t v30=cn_cell(vm,16);

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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_e1bb3a40c593b4a2(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r3=cn_bits(z.x);
uint64_t s2014=UINT64_C(0xfffffff000000000);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(f[0]=cn_double(r3));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]/f[0]));
(r3=cn_bits(f[0]));
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}

cn_break_body:;
return (Vec){cn_double(r3),z.y,z.z};
}
static inline Vec cf_pure_e23b233b039146cd(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v22=cn_cell(vm,0);
uint64_t v23=cn_cell(vm,8);
uint64_t v24=cn_cell(vm,16);
uint64_t v25=cn_cell(vm,24);
uint64_t v26=cn_cell(vm,32);
uint64_t v27=cn_cell(vm,40);
uint64_t v28=cn_cell(vm,48);
uint64_t v29=cn_cell(vm,56);
uint64_t v30=cn_cell(vm,64);

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
__auto_type cn_init_493 = cn_double(v30); __auto_type v = cn_init_493;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_527 = cn_double(v29); __auto_type v = cn_init_527;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_576 = cn_double(v28); __auto_type v = cn_init_576;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(r3=cn_bits(f[3]));
(f[3]=f[2]);
{
__auto_type cn_init_636 = cn_double(v27); __auto_type v = cn_init_636;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_670 = cn_double(v26); __auto_type v = cn_init_670;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_719 = cn_double(v25); __auto_type v = cn_init_719;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(r4=cn_bits(f[3]));
{
__auto_type cn_init_769 = cn_double(v24); __auto_type v = cn_init_769;
(f[2]=(f[2]*v));
}
cn_swap(f,2,1);
{
__auto_type cn_init_802 = cn_double(v23); __auto_type v = cn_init_802;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
cn_swap(f,1,0);
{
__auto_type cn_init_850 = cn_double(v22); __auto_type v = cn_init_850;
(f[1]=(f[1]*v));
}
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_e3aa4cd1134817bf(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s1988=0;
uint64_t s1989=0;
uint64_t s1990=0;
uint64_t s1991=0;
uint64_t s1992=0;
uint64_t s1993=0;
uint64_t s1994=0;
uint64_t s1995=0;
uint64_t s1996=0;
uint64_t s1997=0;
uint64_t s1998=0;
uint64_t s1999=0;
uint64_t s2000=0;
uint64_t s2001=0;
uint64_t s2002=0;
uint64_t s2003=0;
uint64_t s2004=0;
uint64_t s2005=0;
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2008=0;
uint64_t s2009=0;
uint64_t s2010=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v19=cn_cell(vm,0);
uint64_t v20=cn_cell(vm,8);
uint64_t v21=cn_cell(vm,16);
uint64_t v22=cn_cell(vm,24);
uint64_t v23=cn_cell(vm,32);
uint64_t v24=cn_cell(vm,40);
uint64_t v25=cn_cell(vm,48);
uint64_t v26=cn_cell(vm,56);
uint64_t v27=cn_cell(vm,64);
uint64_t v28=cn_cell(vm,72);
uint64_t v29=cn_cell(vm,80);
uint64_t v30=cn_cell(vm,88);
uint64_t v32=cn_cell(vm,104);
uint64_t v33=cn_cell(vm,112);

{
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
__auto_type cn_init_775 = 0xc4U; __auto_type bv = cn_init_775;
__auto_type cn_init_783 = rg[4]; __auto_type av = cn_init_783;
__auto_type cn_init_801 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_801;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s1989=(((s1989&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s1988=(((s1988&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s1988=(((s1988&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(f[0]=cn_double(r3));
{
__auto_type cn_init_1021 = cn_bits(f[0]); uint64_t v = cn_init_1021;
(s1990=(((s1990&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1991=(((s1991&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(r4));
{
__auto_type cn_init_1091 = cn_bits(f[0]); uint64_t v = cn_init_1091;
(s1991=(((s1991&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1992=(((s1992&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(r5));
{
__auto_type cn_init_1161 = cn_bits(f[0]); uint64_t v = cn_init_1161;
(s1992=(((s1992&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1993=(((s1993&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(v30));
{
__auto_type cn_init_1231 = cn_bits(f[0]); uint64_t v = cn_init_1231;
(s1993=(((s1993&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1994=(((s1994&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(v29));
{
__auto_type cn_init_1301 = cn_bits(f[0]); uint64_t v = cn_init_1301;
(s1994=(((s1994&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1995=(((s1995&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(v28));
{
__auto_type cn_init_1371 = cn_bits(f[0]); uint64_t v = cn_init_1371;
(s1995=(((s1995&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1996=(((s1996&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(v27));
{
__auto_type cn_init_1441 = cn_bits(f[0]); uint64_t v = cn_init_1441;
(s1996=(((s1996&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1997=(((s1997&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(v26));
{
__auto_type cn_init_1511 = cn_bits(f[0]); uint64_t v = cn_init_1511;
(s1997=(((s1997&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1998=(((s1998&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(v25));
{
__auto_type cn_init_1581 = cn_bits(f[0]); uint64_t v = cn_init_1581;
(s1998=(((s1998&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1999=(((s1999&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(v24));
{
__auto_type cn_init_1651 = cn_bits(f[0]); uint64_t v = cn_init_1651;
(s1999=(((s1999&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2000=(((s2000&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(v23));
{
__auto_type cn_init_1721 = cn_bits(f[0]); uint64_t v = cn_init_1721;
(s2000=(((s2000&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2001=(((s2001&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(v22));
{
__auto_type cn_init_1791 = cn_bits(f[0]); uint64_t v = cn_init_1791;
(s2001=(((s2001&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2002=(((s2002&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(v21));
{
__auto_type cn_init_1861 = cn_bits(f[0]); uint64_t v = cn_init_1861;
(s2002=(((s2002&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2003=(((s2003&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(v20));
{
__auto_type cn_init_1931 = cn_bits(f[0]); uint64_t v = cn_init_1931;
(s2003=(((s2003&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2004=(((s2004&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(v19));
{
__auto_type cn_init_2001 = cn_bits(f[0]); uint64_t v = cn_init_2001;
(s2004=(((s2004&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2005=(((s2005&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s1990>>32))|((s1991<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2099 = cn_double(((((((s1990>>32))|((s1991<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2099;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s1991>>32))|((s1992<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2167 = cn_double(((((((s1991>>32))|((s1992<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2167;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2224 = cn_bits(f[0]); uint64_t v = cn_init_2224;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s1999>>32))|((s2000<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2322 = cn_double(((((((s1999>>32))|((s2000<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2322;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2000>>32))|((s2001<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2390 = cn_double(((((((s2000>>32))|((s2001<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2390;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_2447 = cn_bits(f[0]); uint64_t v = cn_init_2447;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2545 = cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2545;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_2622 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_2622;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,5)){
goto cn_break_b2;
}
(f[0]=cn_double(((((((s1992>>32))|((s1993<<32))))&0xffffffffffffffffULL))));
(f[0]=-f[0]);
{
__auto_type cn_init_2751 = cn_double(((((((s2001>>32))|((s2002<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2751;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2779 = cn_bits(f[0]); uint64_t v = cn_init_2779;
(s2007=(((s2007&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2008=(((s2008&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s1992>>32))|((s1993<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_2877 = cn_double(((((((s2001>>32))|((s2002<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_2877;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2905 = cn_bits(f[0]); uint64_t v = cn_init_2905;
(s2008=(((s2008&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2009=(((s2009&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
goto cn_break_b3;
}
cn_break_b2:;
(f[0]=cn_double(((((((s1992>>32))|((s1993<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3007 = cn_double(((((((s2001>>32))|((s2002<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3007;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3075 = cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3075;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]-f[0]));
(f[1]=cn_double(((((((s1990>>32))|((s1991<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3185 = cn_double(((((((s1999>>32))|((s2000<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3185;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s1991>>32))|((s1992<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3253 = cn_double(((((((s2000>>32))|((s2001<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3253;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3311 = cn_bits(f[0]); uint64_t v = cn_init_3311;
(s2007=(((s2007&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2008=(((s2008&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s1992>>32))|((s1993<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3409 = cn_double(((((((s2001>>32))|((s2002<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3409;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3477 = cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3477;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]-f[0]));
(f[1]=cn_double(((((((s1999>>32))|((s2000<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3587 = cn_double(((((((s1991>>32))|((s1992<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3587;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s1990>>32))|((s1991<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3655 = cn_double(((((((s2000>>32))|((s2001<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3655;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_3713 = cn_bits(f[0]); uint64_t v = cn_init_3713;
(s2008=(((s2008&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2009=(((s2009&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
}
cn_break_b3:;
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3812 = cn_double(((((((s2001>>32))|((s2002<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3812;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_3880 = cn_double(((((((s1992>>32))|((s1993<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_3880;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_3923 = cn_bits(f[0]); uint64_t v = cn_init_3923;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4021 = cn_double(((((((s2002>>32))|((s2003<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4021;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_4049 = cn_bits(f[0]); uint64_t v = cn_init_4049;
(s2007=(((s2007&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2008=(((s2008&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2008>>32))|((s2009<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4147 = cn_double(((((((s2003>>32))|((s2004<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4147;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_4175 = cn_bits(f[0]); uint64_t v = cn_init_4175;
(s2008=(((s2008&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2009=(((s2009&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4273 = cn_double(((((((s2004>>32))|((s2005<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4273;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_4301 = cn_bits(f[0]); uint64_t v = cn_init_4301;
(s2009=(((s2009&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2010=(((s2010&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4399 = cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4399;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2008>>32))|((s2009<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4467 = cn_double(((((((s2008>>32))|((s2009<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4467;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[1]=cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4550 = cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4550;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_4593 = cn_bits(f[0]); uint64_t v = cn_init_4593;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(fsw=cn_compare(f[0],cn_double(v32)));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_4690 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_4690;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,7)){
goto cn_break_b5;
}
(f[0]=cn_double(v33));
{
__auto_type cn_init_4780 = cn_bits(f[0]); uint64_t v = cn_init_4780;
(s1990=(((s1990&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1991=(((s1991&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_4838 = cn_bits(f[0]); uint64_t v = cn_init_4838;
(s1991=(((s1991&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1992=(((s1992&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
{
__auto_type cn_init_4896 = cn_bits(f[0]); uint64_t v = cn_init_4896;
(s1992=(((s1992&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1993=(((s1993&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
goto cn_break_b12;
}
cn_break_b5:;
(f[0]=cn_double(((((((s1993>>32))|((s1994<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_4998 = cn_double(((((((s1993>>32))|((s1994<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_4998;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s1994>>32))|((s1995<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5066 = cn_double(((((((s1994>>32))|((s1995<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5066;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_5123 = cn_bits(f[0]); uint64_t v = cn_init_5123;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5221 = cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5221;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_5298 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_5298;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,5)){
goto cn_break_b7;
}
(f[0]=cn_double(((((((s1992>>32))|((s1993<<32))))&0xffffffffffffffffULL))));
(f[0]=-f[0]);
{
__auto_type cn_init_5427 = cn_double(((((((s1995>>32))|((s1996<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5427;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5455 = cn_bits(f[0]); uint64_t v = cn_init_5455;
(s1989=(((s1989&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1990=(((s1990&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s1992>>32))|((s1993<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5553 = cn_double(((((((s1995>>32))|((s1996<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5553;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_5581 = cn_bits(f[0]); uint64_t v = cn_init_5581;
(s2005=(((s2005&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2006=(((s2006&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
goto cn_break_b8;
}
cn_break_b7:;
(f[0]=cn_double(((((((s1992>>32))|((s1993<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5683 = cn_double(((((((s1995>>32))|((s1996<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5683;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5751 = cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5751;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]-f[0]));
(f[1]=cn_double(((((((s1990>>32))|((s1991<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5861 = cn_double(((((((s1993>>32))|((s1994<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5861;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s1991>>32))|((s1992<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_5929 = cn_double(((((((s1994>>32))|((s1995<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_5929;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]-f[2]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_5987 = cn_bits(f[0]); uint64_t v = cn_init_5987;
(s1989=(((s1989&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1990=(((s1990&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s1992>>32))|((s1993<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_6085 = cn_double(((((((s1995>>32))|((s1996<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_6085;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_6153 = cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_6153;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]/f[1]));
(f[1]=cn_double(0x3ff0000000000000));
(f[0]=(f[1]-f[0]));
(f[1]=cn_double(((((((s1993>>32))|((s1994<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_6263 = cn_double(((((((s1991>>32))|((s1992<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_6263;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s1990>>32))|((s1991<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_6331 = cn_double(((((((s1994>>32))|((s1995<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_6331;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_6389 = cn_bits(f[0]); uint64_t v = cn_init_6389;
(s2005=(((s2005&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2006=(((s2006&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
}
cn_break_b8:;
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_6488 = cn_double(((((((s1995>>32))|((s1996<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_6488;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_6556 = cn_double(((((((s1992>>32))|((s1993<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_6556;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_6599 = cn_bits(f[0]); uint64_t v = cn_init_6599;
(s2006=(((s2006&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2007=(((s2007&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s1989>>32))|((s1990<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_6697 = cn_double(((((((s1996>>32))|((s1997<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_6697;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_6725 = cn_bits(f[0]); uint64_t v = cn_init_6725;
(s1989=(((s1989&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1990=(((s1990&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_6823 = cn_double(((((((s1997>>32))|((s1998<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_6823;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_6851 = cn_bits(f[0]); uint64_t v = cn_init_6851;
(s2005=(((s2005&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2006=(((s2006&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_6949 = cn_double(((((((s1998>>32))|((s1999<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_6949;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_6977 = cn_bits(f[0]); uint64_t v = cn_init_6977;
(s2006=(((s2006&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2007=(((s2007&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(0x3ff0000000000000));
{
__auto_type cn_init_7059 = cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_7059;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_7087 = cn_bits(f[0]); uint64_t v = cn_init_7087;
(s2010=(((s2010&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2011=(((s2011&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s1989>>32))|((s1990<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_7185 = cn_double(((((((s1989>>32))|((s1990<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_7185;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_7253 = cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_7253;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_7310 = cn_bits(f[0]); uint64_t v = cn_init_7310;
(s2011=(((s2011&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2012=(((s2012&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_7408 = cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_7408;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2008>>32))|((s2009<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_7476 = cn_double(((((((s2008>>32))|((s2009<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_7476;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=sqrt(f[0]));
{
__auto_type cn_init_7533 = cn_bits(f[0]); uint64_t v = cn_init_7533;
(s2012=(((s2012&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s2013=(((s2013&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_7631 = cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_7631;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(0x0));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_7708 = ((uint8_t)(((rg[EAX]>>8)))); __auto_type ah = cn_init_7708;
(fl.sf=((ah&0x80)!=0));
(fl.zf=((ah&0x40)!=0));
(fl.af=((ah&0x10)!=0));
(fl.pf=((ah&0x04)!=0));
(fl.cf=((ah&0x01)!=0));
}
if(cn_cond(fl,5)){
goto cn_break_b10;
}
(f[0]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_7826 = cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_7826;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_7854 = cn_bits(f[0]); uint64_t v = cn_init_7854;
(s1990=(((s1990&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1991=(((s1991&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
(f[0]=-f[0]);
{
__auto_type cn_init_7963 = cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_7963;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_7991 = cn_bits(f[0]); uint64_t v = cn_init_7991;
(s1991=(((s1991&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1992=(((s1992&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
goto cn_break_b11;
}
cn_break_b10:;
(f[0]=cn_double(((((((s1989>>32))|((s1990<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_8093 = cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_8093;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_8161 = cn_double(((((((s2008>>32))|((s2009<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_8161;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_8216 = cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_8216;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_8284 = cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_8284;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_8352 = cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_8352;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]/f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_8437 = cn_bits(f[0]); uint64_t v = cn_init_8437;
(s1990=(((s1990&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1991=(((s1991&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
(f[0]=cn_double(((((((s2007>>32))|((s2008<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_8535 = cn_double(((((((s2005>>32))|((s2006<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_8535;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s1989>>32))|((s1990<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_8603 = cn_double(((((((s2008>>32))|((s2009<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_8603;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_8658 = cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_8658;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_8726 = cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_8726;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_8794 = cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_8794;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]/f[2]));
(f[2]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]+f[2]));
(f[0]=(f[0]*f[1]));
{
__auto_type cn_init_8879 = cn_bits(f[0]); uint64_t v = cn_init_8879;
(s1991=(((s1991&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1992=(((s1992&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
}
cn_break_b11:;
(f[0]=cn_double(((((((s2012>>32))|((s2013<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_8978 = cn_double(((((((s2006>>32))|((s2007<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_8978;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(((((((s2011>>32))|((s2012<<32))))&0xffffffffffffffffULL))));
{
__auto_type cn_init_9046 = cn_double(((((((s2009>>32))|((s2010<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_9046;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]-f[1]));
{
__auto_type cn_init_9101 = cn_double(((((((s2010>>32))|((s2011<<32))))&0xffffffffffffffffULL))); __auto_type v = cn_init_9101;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_9129 = cn_bits(f[0]); uint64_t v = cn_init_9129;
(s1992=(((s1992&~((0xffffffffULL<<32))))|((((v&0xffffffffULL))<<32))));
(s1993=(((s1993&~0xffffffffULL))|((((v>>32))&0xffffffffULL))));
}
}
cn_break_b12:;
(f[0]=cn_double(((((((s1990>>32))|((s1991<<32))))&0xffffffffffffffffULL))));
(r3=cn_bits(f[0]));
(f[0]=cn_double(((((((s1991>>32))|((s1992<<32))))&0xffffffffffffffffULL))));
(r4=cn_bits(f[0]));
(f[0]=cn_double(((((((s1992>>32))|((s1993<<32))))&0xffffffffffffffffULL))));
(r5=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s1988>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s1988>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s1989>>0))&0xffffffffULL)))));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_e414957dff3bdb3b(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v18=cn_cell(vm,0);
uint64_t v19=cn_cell(vm,8);
uint64_t v20=cn_cell(vm,16);
uint64_t v21=cn_cell(vm,24);
uint64_t v22=cn_cell(vm,32);
uint64_t v23=cn_cell(vm,40);
uint64_t v24=cn_cell(vm,48);
uint64_t v25=cn_cell(vm,56);
uint64_t v26=cn_cell(vm,64);
uint64_t v27=cn_cell(vm,72);
uint64_t v28=cn_cell(vm,80);
uint64_t v29=cn_cell(vm,88);
uint64_t v30=cn_cell(vm,96);
uint64_t v32=cn_cell(vm,112);
uint64_t v33=cn_cell(vm,120);
uint64_t v34=cn_cell(vm,128);

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
__auto_type cn_init_681 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_681;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_729 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_729;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_792 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_792;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[3]=fabs(f[3]));
(f[4]=f[2]);
{
__auto_type cn_init_869 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_869;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_917 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_917;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_980 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_980;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[4]=fabs(f[4]));
cn_swap(f,4,2);
{
__auto_type cn_init_1056 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1056;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1103 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1103;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1165 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1165;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
cn_swap(f,2,1);
(f[2]=fabs(f[2]));
cn_swap(f,2,1);
(f[3]=f[2]);
{
__auto_type cn_init_1246 = cn_double(v32); __auto_type v = cn_init_1246;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1280 = cn_double(v33); __auto_type v = cn_init_1280;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1329 = cn_double(v34); __auto_type v = cn_init_1329;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(fsw=cn_compare(f[3],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b2;
}
(f[3]=(f[3]+f[3]));
(f[4]=cn_double(v33));
(f[5]=cn_double(v32));
(f[6]=cn_double(v34));
cn_swap(f,6,3);
(f[3]=(f[3]*f[6]));
(f[4]=(f[4]*f[6]));
(f[5]=(f[5]*f[6]));
(f[2]=(f[2]-f[5]));
(f[1]=(f[1]-f[4]));
(f[0]=(f[0]-f[3]));
}
cn_break_b2:;
(f[3]=f[3]);
cn_swap(f,2,1);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
cn_swap(f,2,1);
(f[3]=f[2]);
{
__auto_type cn_init_1670 = cn_double(v32); __auto_type v = cn_init_1670;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1704 = cn_double(v33); __auto_type v = cn_init_1704;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1753 = cn_double(v34); __auto_type v = cn_init_1753;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(fsw=cn_compare(f[3],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b4;
}
(f[3]=(f[3]+f[3]));
(f[4]=cn_double(v33));
(f[5]=cn_double(v32));
(f[6]=cn_double(v34));
cn_swap(f,6,3);
(f[3]=(f[3]*f[6]));
(f[4]=(f[4]*f[6]));
(f[5]=(f[5]*f[6]));
(f[2]=(f[2]-f[5]));
(f[1]=(f[1]-f[4]));
(f[0]=(f[0]-f[3]));
}
cn_break_b4:;
(f[3]=f[3]);
cn_swap(f,2,1);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
cn_swap(f,2,1);
(f[3]=f[2]);
{
__auto_type cn_init_2094 = cn_double(v32); __auto_type v = cn_init_2094;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_2128 = cn_double(v33); __auto_type v = cn_init_2128;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2177 = cn_double(v34); __auto_type v = cn_init_2177;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(fsw=cn_compare(f[3],0.0));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,3)){
goto cn_break_b6;
}
(f[3]=(f[3]+f[3]));
(f[4]=cn_double(v33));
(f[5]=cn_double(v32));
(f[6]=cn_double(v34));
cn_swap(f,6,3);
(f[3]=(f[3]*f[6]));
(f[4]=(f[4]*f[6]));
(f[5]=(f[5]*f[6]));
(f[2]=(f[2]-f[5]));
(f[1]=(f[1]-f[4]));
(f[0]=(f[0]-f[3]));
}
cn_break_b6:;
(f[3]=f[3]);
cn_swap(f,2,1);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
(f[2]=fabs(f[2]));
cn_swap(f,2,0);
(f[3]=f[1]);
{
__auto_type cn_init_2523 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2523;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_2571 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2571;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2634 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2634;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_2697 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2697;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_2745 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2745;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2808 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2808;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_2870 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2870;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_2917 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2917;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2979 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2979;
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
__auto_type cn_init_3160 = cn_double(v29); __auto_type v = cn_init_3160;
(f[5]=(f[5]*v));
}
(f[1]=(f[1]-f[5]));
{
__auto_type cn_init_3199 = cn_double(v28); __auto_type v = cn_init_3199;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]-f[4]));
{
__auto_type cn_init_3238 = cn_double(v27); __auto_type v = cn_init_3238;
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_e589ab23df662be4(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v28=cn_cell(vm,0);
uint64_t v29=cn_cell(vm,8);
uint64_t v30=cn_cell(vm,16);

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
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(0x3ff0000000000000));
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
(f[4]=(f[4]*f[3]));
(f[5]=f[2]);
(f[5]=(f[5]*f[2]));
(f[4]=(f[4]+f[5]));
(f[5]=f[1]);
(f[5]=(f[5]*f[1]));
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
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x1000))))));
cn_shift_reg_l(rg,&fl,Shift_Shr,4,1,1);
if(cn_cond(fl,2)){
goto cn_break_b4;
}
(f[5]=f[5]);
{
__auto_type cn_init_1116 = cn_double(v30); __auto_type v = cn_init_1116;
(f[4]=(v/f[4]));
}
goto cn_break_b5;
}
cn_break_b4:;
(fsw=cn_compare(f[5],f[4]));
(f[4]=cn_double(v30));
}
cn_break_b5:;
(f[5]=cn_double(r6));
(f[5]=(f[5]*f[4]));
(r6=cn_bits(f[5]));
(f[1]=(f[1]*f[4]));
(f[2]=(f[2]*f[4]));
(f[3]=(f[3]*f[4]));
(r5=cn_bits(f[3]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_e5b10d9b6546bbe5(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v28=cn_cell(vm,0);
uint64_t v29=cn_cell(vm,8);
uint64_t v30=cn_cell(vm,16);

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
(rg[6]=((uint32_t)(((((v30>>32))&0xffffffffULL)))));
{
__auto_type cn_init_445 = 0x3U; __auto_type bv = cn_init_445;
__auto_type cn_init_453 = rg[6]; __auto_type av = cn_init_453;
__auto_type cn_init_471 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_471;
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
__auto_type cn_init_719 = (((double)(cn_float(((uint32_t)(((((v30>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_719;
(f[0]=(f[0]-v));
}
{
__auto_type cn_init_757 = (((double)(cn_float(((uint32_t)(((((v29>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_757;
(f[0]=(f[0]*v));
}
(f[0]=sin(f[0]));
(fsw&=~0x0400);
{
__auto_type cn_init_814 = (((double)(cn_float(((uint32_t)(((((v29>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_814;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_852 = (((double)(cn_float(((uint32_t)(((((v28>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_852;
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_e60fa9d255bb9543(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v25=cn_cell(vm,0);
uint64_t v26=cn_cell(vm,8);
uint64_t v27=cn_cell(vm,16);
uint64_t v28=cn_cell(vm,24);
uint64_t v29=cn_cell(vm,32);
uint64_t v30=cn_cell(vm,40);

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
(s2013=(((s2013&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<0))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(rg[6]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(f[0]=cn_double(r3));
{
__auto_type cn_init_489 = cn_double(v28); __auto_type v = cn_init_489;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_525 = cn_double(v27); __auto_type v = cn_init_525;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_575 = cn_double(v26); __auto_type v = cn_init_575;
(f[0]=(f[0]+v));
}
(f[1]=f[0]);
(f[1]=fabs(f[1]));
(f[1]=sqrt(f[1]));
cn_swap(f,1,0);
(f[2]=f[1]);
(f[2]=fabs(f[2]));
(f[3]=cn_double(0x3ff0000000000000));
(fsw=cn_compare(f[3],f[2]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3000))))));
{
__auto_type cn_init_714 = 0x41U; __auto_type bv = cn_init_714;
__auto_type cn_init_727 = cn_reg_get(rg,4,1); __auto_type av = cn_init_727;
__auto_type cn_init_745 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_745;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,15)){
goto cn_break_b4;
}
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_826 = 0x41U; __auto_type bv = cn_init_826;
__auto_type cn_init_839 = cn_reg_get(rg,4,1); __auto_type av = cn_init_839;
__auto_type cn_init_857 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_857;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,15)){
goto cn_break_b3;
}
(f[0]=-f[0]);
}
cn_break_b3:;
(f=(CN_D8){f[7],f[0],f[1],f[2],f[3],f[4],f[5],f[6]});
goto cn_break_b7;
}
cn_break_b4:;
(f[2]=cn_double(0x0));
(fsw=cn_compare(f[2],f[1]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x3800))))));
{
__auto_type cn_init_998 = 0x41U; __auto_type bv = cn_init_998;
__auto_type cn_init_1011 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1011;
__auto_type cn_init_1029 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1029;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,15)){
goto cn_break_b6;
}
(f[0]=-f[0]);
}
cn_break_b6:;
(f[1]=cn_double(0x3ff0000000000000));
(f[1]=(f[1]/f[0]));
}
cn_break_b7:;
{
__auto_type cn_init_1106 = cn_double(r4); __auto_type v = cn_init_1106;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(v29));
{
__auto_type cn_init_1142 = cn_double(r3); __auto_type v = cn_init_1142;
(f[2]=(f[2]-v));
}
{
__auto_type cn_init_1166 = cn_double(v30); __auto_type v = cn_init_1166;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(v29));
{
__auto_type cn_init_1202 = cn_double(r4); __auto_type v = cn_init_1202;
(f[3]=(f[3]*v));
}
(f[4]=cn_double(r3));
{
__auto_type cn_init_1238 = cn_double(v28); __auto_type v = cn_init_1238;
(f[4]=(f[4]*v));
}
(f[4]=-f[4]);
(f[3]=(f[3]+f[4]));
{
__auto_type cn_init_1288 = cn_double(v25); __auto_type v = cn_init_1288;
(f[3]=(f[3]*v));
}
{
__auto_type cn_init_1312 = cn_double(r5); __auto_type v = cn_init_1312;
(f[3]=(f[3]+v));
}
(r5=cn_bits(f[3]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_ea6233620ddaa142(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r4=cn_bits(z.y);
uint64_t s2014=UINT64_C(0xfffffff000000000);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(f[0]=cn_double(r4));
(f[0]=-f[0]);
(r4=cn_bits(f[0]));
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}

cn_break_body:;
return (Vec){z.x,cn_double(r4),z.z};
}
static inline Vec cf_pure_eb5df2ab5cec6849(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2014=UINT64_C(0xfffffff000000000);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
(f[0]=cn_double(r6));
(f[1]=cn_double(r5));
(f[2]=cn_double(r4));
(f[3]=cn_double(r3));
(f[3]=fabs(f[3]));
(r3=cn_bits(f[3]));
(f[2]=fabs(f[2]));
(r4=cn_bits(f[2]));
(f[1]=fabs(f[1]));
(r5=cn_bits(f[1]));
(f[0]=fabs(f[0]));
(r6=cn_bits(f[0]));
{
(rg[5]=((uint32_t)(((((s2014>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
(rg[ESP]=((uint32_t)(rg[ESP]+12)));
goto cn_break_body;
}

cn_break_body:;
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_eba3ca997c3e90a6(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2006=0;
uint64_t s2007=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v29=cn_cell(vm,0);
uint64_t v30=cn_cell(vm,8);
uint64_t v32=cn_cell(vm,24);
uint64_t v33=cn_cell(vm,32);
uint64_t v34=cn_cell(vm,40);

{
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2014=(((s2014&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[5])))&0xffffffffULL))<<0))));
}
(rg[5]=rg[4]);
{
__auto_type cn_init_335 = 0x30U; __auto_type bv = cn_init_335;
__auto_type cn_init_343 = rg[4]; __auto_type av = cn_init_343;
__auto_type cn_init_361 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_361;
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
__auto_type cn_init_577 = cn_double(v32); __auto_type v = cn_init_577;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_613 = cn_double(v33); __auto_type v = cn_init_613;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_663 = cn_double(v34); __auto_type v = cn_init_663;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_710 = cn_double(v33); __auto_type v = cn_init_710;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_746 = cn_double(v32); __auto_type v = cn_init_746;
(f[1]=(f[1]*v));
}
(f[0]=(f[0]+f[1]));
(f[0]=fabs(f[0]));
(f[1]=cn_double(s2013));
(f[2]=cn_double(r4));
{
__auto_type cn_init_823 = cn_double(v34); __auto_type v = cn_init_823;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[1]=(f[1]+f[2]));
(f[1]=fabs(f[1]));
(f[2]=cn_double(s2013));
(f[3]=cn_double(r4));
{
__auto_type cn_init_911 = cn_double(v34); __auto_type v = cn_init_911;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(f[2]=fabs(f[2]));
(r4=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1009 = cn_double(r4); __auto_type v = cn_init_1009;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1033 = cn_double(v34); __auto_type v = cn_init_1033;
(f[0]=(f[0]*v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[0]=-f[0]);
{
__auto_type cn_init_1091 = cn_double(r4); __auto_type v = cn_init_1091;
(f[0]=(f[0]+v));
}
{
__auto_type cn_init_1115 = cn_double(v34); __auto_type v = cn_init_1115;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(s2013));
{
__auto_type cn_init_1151 = cn_double(v32); __auto_type v = cn_init_1151;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(r5));
{
__auto_type cn_init_1187 = cn_double(v33); __auto_type v = cn_init_1187;
(f[2]=(f[2]*v));
}
(f[1]=(f[1]+f[2]));
(f[2]=cn_double(s2013));
{
__auto_type cn_init_1238 = cn_double(v33); __auto_type v = cn_init_1238;
(f[2]=(f[2]*v));
}
(f[2]=-f[2]);
(f[3]=cn_double(r5));
{
__auto_type cn_init_1285 = cn_double(v32); __auto_type v = cn_init_1285;
(f[3]=(f[3]*v));
}
(f[2]=(f[2]+f[3]));
(r5=cn_bits(f[2]));
(r3=cn_bits(f[1]));
(r4=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_1369 = cn_double(v30); __auto_type v = cn_init_1369;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_1393 = cn_double(v29); __auto_type v = cn_init_1393;
(f[0]=(f[0]-v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_1440 = cn_double(v30); __auto_type v = cn_init_1440;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_1487 = cn_double(v30); __auto_type v = cn_init_1487;
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_f15e7033ae08e677(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2008=0;
uint64_t s2009=0;
uint64_t s2010=0;
uint64_t s2011=0;
uint64_t s2012=0;
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v20=cn_cell(vm,0);
uint64_t v21=cn_cell(vm,8);
uint64_t v22=cn_cell(vm,16);
uint64_t v23=cn_cell(vm,24);
uint64_t v24=cn_cell(vm,32);
uint64_t v25=cn_cell(vm,40);
uint64_t v26=cn_cell(vm,48);
uint64_t v27=cn_cell(vm,56);
uint64_t v28=cn_cell(vm,64);
uint64_t v29=cn_cell(vm,72);
uint64_t v30=cn_cell(vm,80);
uint64_t v33=cn_cell(vm,104);

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
__auto_type cn_init_500 = 0x20U; __auto_type bv = cn_init_500;
__auto_type cn_init_508 = rg[4]; __auto_type av = cn_init_508;
__auto_type cn_init_526 = cn_alu(&fl,Alu_Sub,av,bv,4); __auto_type r = cn_init_526;
(rg[4]=r);
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2009=(((s2009&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[3])))&0xffffffffULL))<<32))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2009=(((s2009&~((0xffffffffULL<<0))))|(((((((uint64_t)(rg[6])))&0xffffffffULL))<<0))));
}
{
(rg[ESP]=((uint32_t)(rg[ESP]-4)));
(s2008=(((s2008&~((0xffffffffULL<<32))))|(((((((uint64_t)(rg[7])))&0xffffffffULL))<<32))));
}
(rg[6]=((uint32_t)(((((s2015>>0))&0xffffffffULL)))));
(rg[7]=((uint32_t)(((((r13>>0))&0xffffffffULL)))));
(rg[3]=rg[0]);
(f[0]=cn_double(r3));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_756 = cn_double(v33); __auto_type v = cn_init_756;
(f[0]=(f[0]*v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_817 = cn_double(v33); __auto_type v = cn_init_817;
(f[0]=(f[0]*v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
(f[0]=fabs(f[0]));
{
__auto_type cn_init_878 = cn_double(v33); __auto_type v = cn_init_878;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(r6));
{
__auto_type cn_init_925 = cn_double(v33); __auto_type v = cn_init_925;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_949 = cn_double(v29); __auto_type v = cn_init_949;
(f[0]=(f[0]/v));
}
{
__auto_type cn_init_973 = cn_double(v30); __auto_type v = cn_init_973;
(f[0]=(f[0]*v));
}
(r6=cn_bits(f[0]));
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_1064 = 0x41U; __auto_type bv = cn_init_1064;
__auto_type cn_init_1077 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1077;
__auto_type cn_init_1095 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1095;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b2;
}
(f[0]=cn_double(r3));
(f[1]=cn_double(r4));
(r3=cn_bits(f[1]));
(r4=cn_bits(f[0]));
}
cn_break_b2:;
(f[0]=cn_double(r3));
(f[1]=cn_double(r5));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_1235 = 0x41U; __auto_type bv = cn_init_1235;
__auto_type cn_init_1248 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1248;
__auto_type cn_init_1266 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1266;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b4;
}
(f[0]=cn_double(r3));
(f[1]=cn_double(r5));
(r3=cn_bits(f[1]));
(r5=cn_bits(f[0]));
}
cn_break_b4:;
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_1406 = 0x41U; __auto_type bv = cn_init_1406;
__auto_type cn_init_1419 = cn_reg_get(rg,4,1); __auto_type av = cn_init_1419;
__auto_type cn_init_1437 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_1437;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,6)){
goto cn_break_b6;
}
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(r5=cn_bits(f[1]));
(r4=cn_bits(f[0]));
}
cn_break_b6:;
(f[0]=cn_double(r5));
{
__auto_type cn_init_1533 = cn_double(v25); __auto_type v = cn_init_1533;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(r4));
{
__auto_type cn_init_1569 = cn_double(v26); __auto_type v = cn_init_1569;
(f[1]=(f[1]+v));
}
(f[2]=cn_double(r3));
{
__auto_type cn_init_1605 = cn_double(v27); __auto_type v = cn_init_1605;
(f[2]=(f[2]+v));
}
(f[3]=f[2]);
{
__auto_type cn_init_1653 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1653;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_1701 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1701;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1764 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1764;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1827 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1827;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1875 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1875;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1938 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1938;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_2000 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2000;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_2047 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2047;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2109 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2109;
(f[3]=(f[3]*v));
}
(f[1]=(f[1]+f[3]));
(r3=cn_bits(f[2]));
(r4=cn_bits(f[1]));
(r5=cn_bits(f[0]));
(f[0]=cn_double(v28));
{
__auto_type cn_init_2193 = cn_double(r5); __auto_type v = cn_init_2193;
(f[0]=(f[0]-v));
}
(f[0]=fabs(f[0]));
(f[0]=-f[0]);
{
__auto_type cn_init_2242 = cn_double(v28); __auto_type v = cn_init_2242;
(f[0]=(f[0]+v));
}
(r5=cn_bits(f[0]));
(f[0]=cn_double(v33));
(f[1]=f[0]);
(f[2]=cn_double(v29));
(f[1]=(f[1]+f[2]));
(s2011=cn_bits(f[1]));
(f[1]=cn_double(v29));
(f[0]=(f[0]-f[1]));
(s2010=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_2387 = cn_double(s2010); __auto_type v = cn_init_2387;
(f[0]=(f[0]-v));
}
(s2013=cn_bits(f[0]));
(f[0]=cn_double(r3));
{
__auto_type cn_init_2434 = cn_double(s2011); __auto_type v = cn_init_2434;
(f[0]=(f[0]-v));
}
(s2012=cn_bits(f[0]));
(f[0]=cn_double(s2013));
(f[1]=cn_double(r4));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_2525 = 0x41U; __auto_type bv = cn_init_2525;
__auto_type cn_init_2538 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2538;
__auto_type cn_init_2556 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2556;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,7)){
goto cn_break_b8;
}
(f[0]=cn_double(s2013));
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_2628 = cn_double(s2010); __auto_type v = cn_init_2628;
(f[0]=(f[0]-v));
}
(r4=cn_bits(f[0]));
goto cn_break_b11;
}
cn_break_b8:;
(f[0]=cn_double(s2012));
(f[1]=cn_double(r4));
(fsw=cn_compare(f[1],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x0))))));
{
__auto_type cn_init_2723 = 0x41U; __auto_type bv = cn_init_2723;
__auto_type cn_init_2736 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2736;
__auto_type cn_init_2754 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2754;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,6)){
goto cn_break_b10;
}
(f[0]=cn_double(s2012));
(r3=cn_bits(f[0]));
goto cn_break_b11;
}
cn_break_b10:;
(f[0]=cn_double(r4));
(f[1]=cn_double(s2012));
(r4=cn_bits(f[1]));
(r3=cn_bits(f[0]));
}
cn_break_b11:;
(f[0]=cn_double(r3));
{
__auto_type cn_init_2877 = cn_double(v30); __auto_type v = cn_init_2877;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2901 = cn_double(v29); __auto_type v = cn_init_2901;
(f[0]=(f[0]/v));
}
(r3=cn_bits(f[0]));
(f[0]=cn_double(r4));
{
__auto_type cn_init_2948 = cn_double(v30); __auto_type v = cn_init_2948;
(f[0]=(f[0]*v));
}
{
__auto_type cn_init_2972 = cn_double(v29); __auto_type v = cn_init_2972;
(f[0]=(f[0]/v));
}
(r4=cn_bits(f[0]));
(f[0]=cn_double(r5));
{
__auto_type cn_init_3019 = cn_double(v30); __auto_type v = cn_init_3019;
(f[0]=(f[0]*v));
}
(r5=cn_bits(f[0]));
(rg[0]=rg[3]);
{
(rg[7]=((uint32_t)(((((s2008>>32))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[6]=((uint32_t)(((((s2009>>0))&0xffffffffULL)))));
(rg[ESP]=((uint32_t)(rg[ESP]+4)));
}
{
(rg[3]=((uint32_t)(((((s2009>>32))&0xffffffffULL)))));
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_f19722dc8c8c12d9(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t r6=cn_bits(*fourth);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v16=cn_cell(vm,0);
uint64_t v17=cn_cell(vm,8);
uint64_t v18=cn_cell(vm,16);
uint64_t v19=cn_cell(vm,24);
uint64_t v20=cn_cell(vm,32);
uint64_t v21=cn_cell(vm,40);
uint64_t v22=cn_cell(vm,48);
uint64_t v23=cn_cell(vm,56);
uint64_t v24=cn_cell(vm,64);
uint64_t v25=cn_cell(vm,72);
uint64_t v26=cn_cell(vm,80);
uint64_t v27=cn_cell(vm,88);
uint64_t v28=cn_cell(vm,96);
uint64_t v29=cn_cell(vm,104);
uint64_t v30=cn_cell(vm,112);
uint64_t v31=cn_cell(vm,120);

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
{
__auto_type cn_init_625 = 0x7fffffffU; __auto_type v = cn_init_625;
(rg[0]=v);
}
{
__auto_type cn_init_642 = rg[0]; __auto_type bv = cn_init_642;
__auto_type cn_init_659 = (((uint32_t)(((((r5>>32))&0xffffffffULL))))); __auto_type av = cn_init_659;
__auto_type cn_init_677 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_677;
(r5=(((r5&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_716 = rg[0]; __auto_type bv = cn_init_716;
__auto_type cn_init_733 = (((uint32_t)(((((r4>>32))&0xffffffffULL))))); __auto_type av = cn_init_733;
__auto_type cn_init_751 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_751;
(r4=(((r4&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
{
__auto_type cn_init_790 = rg[0]; __auto_type bv = cn_init_790;
__auto_type cn_init_807 = (((uint32_t)(((((r3>>32))&0xffffffffULL))))); __auto_type av = cn_init_807;
__auto_type cn_init_825 = cn_alu(&fl,Alu_And,av,bv,4); __auto_type r = cn_init_825;
(r3=(((r3&~((0xffffffffULL<<32))))|(((((((uint64_t)((r))))&0xffffffffULL))<<32))));
}
(f[0]=cn_double(r5));
(f[1]=cn_double(r4));
(f[2]=cn_double(r3));
(f[3]=f[2]);
{
__auto_type cn_init_926 = (((double)(cn_float(((uint32_t)(((((v23>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_926;
(f[3]=(f[3]*v));
}
(f[4]=f[1]);
{
__auto_type cn_init_974 = (((double)(cn_float(((uint32_t)(((((v23>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_974;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_1037 = (((double)(cn_float(((uint32_t)(((((v22>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1037;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[2]);
{
__auto_type cn_init_1100 = (((double)(cn_float(((uint32_t)(((((v26>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1100;
(f[4]=(f[4]*v));
}
(f[5]=f[1]);
{
__auto_type cn_init_1148 = (((double)(cn_float(((uint32_t)(((((v26>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1148;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_1211 = (((double)(cn_float(((uint32_t)(((((v25>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1211;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,2);
{
__auto_type cn_init_1273 = (((double)(cn_float(((uint32_t)(((((v25>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1273;
(f[4]=(f[4]*v));
}
cn_swap(f,4,1);
{
__auto_type cn_init_1320 = (((double)(cn_float(((uint32_t)(((((v24>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_1320;
(f[4]=(f[4]*v));
}
(f[1]=(f[1]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_1382 = (((double)(cn_float(((uint32_t)(((((v24>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_1382;
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
__auto_type cn_init_1804 = cn_double(v17); __auto_type v = cn_init_1804;
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
__auto_type cn_init_1982 = cn_double(v16); __auto_type v = cn_init_1982;
(f[3]=(f[3]+v));
}
cn_swap(f,3,2);
}
cn_break_b10:;
(f[3]=f[3]);
(f[3]=f[1]);
{
__auto_type cn_init_2050 = (((double)(cn_float(((uint32_t)(((((v19>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2050;
(f[3]=(f[3]*v));
}
(f[4]=f[2]);
{
__auto_type cn_init_2098 = (((double)(cn_float(((uint32_t)(((((v18>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2098;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[0]);
{
__auto_type cn_init_2161 = (((double)(cn_float(((uint32_t)(((((v18>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2161;
(f[4]=(f[4]*v));
}
(f[3]=(f[3]+f[4]));
(f[4]=f[1]);
{
__auto_type cn_init_2224 = (((double)(cn_float(((uint32_t)(((((v22>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2224;
(f[4]=(f[4]*v));
}
(f[5]=f[2]);
{
__auto_type cn_init_2272 = (((double)(cn_float(((uint32_t)(((((v21>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2272;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
(f[5]=f[0]);
{
__auto_type cn_init_2335 = (((double)(cn_float(((uint32_t)(((((v21>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2335;
(f[5]=(f[5]*v));
}
(f[4]=(f[4]+f[5]));
cn_swap(f,4,1);
{
__auto_type cn_init_2397 = (((double)(cn_float(((uint32_t)(((((v20>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2397;
(f[4]=(f[4]*v));
}
cn_swap(f,4,2);
{
__auto_type cn_init_2444 = (((double)(cn_float(((uint32_t)(((((v20>>0))&0xffffffffULL)))))))); __auto_type v = cn_init_2444;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]+f[4]));
cn_swap(f,3,0);
{
__auto_type cn_init_2506 = (((double)(cn_float(((uint32_t)(((((v19>>32))&0xffffffffULL)))))))); __auto_type v = cn_init_2506;
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
__auto_type cn_init_2687 = cn_double(v29); __auto_type v = cn_init_2687;
(f[5]=(f[5]*v));
}
(f[1]=(f[1]-f[5]));
{
__auto_type cn_init_2726 = cn_double(v28); __auto_type v = cn_init_2726;
(f[4]=(f[4]*v));
}
(f[2]=(f[2]-f[4]));
{
__auto_type cn_init_2765 = cn_double(v27); __auto_type v = cn_init_2765;
(f[3]=(f[3]*v));
}
(f[4]=f[3]);
{
__auto_type cn_init_2799 = cn_double(v31); __auto_type v = cn_init_2799;
(f[4]=(f[4]*v));
}
(fsw=cn_compare(f[4],f[0]));
(rg[EAX]=(((rg[EAX]&0xFFFF0000))|((uint32_t)(((fsw|0x2000))))));
{
__auto_type cn_init_2855 = 0x41U; __auto_type bv = cn_init_2855;
__auto_type cn_init_2868 = cn_reg_get(rg,4,1); __auto_type av = cn_init_2868;
__auto_type cn_init_2886 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_2886;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,4)){
goto cn_break_b12;
}
(f[0]=(f[0]-f[3]));
}
cn_break_b12:;
(f[3]=f[3]);
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
*fourth=cn_double(r6);return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_f1d590365a4793b6(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v25=cn_cell(vm,0);
uint64_t v26=cn_cell(vm,8);
uint64_t v27=cn_cell(vm,16);
uint64_t v28=cn_cell(vm,24);
uint64_t v29=cn_cell(vm,32);
uint64_t v30=cn_cell(vm,40);

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
__auto_type cn_init_480 = cn_double(v28); __auto_type v = cn_init_480;
(f[0]=(f[0]*v));
}
(f[1]=cn_double(r5));
{
__auto_type cn_init_516 = cn_double(v27); __auto_type v = cn_init_516;
(f[1]=(f[1]*v));
}
(f[1]=-f[1]);
(f[0]=(f[0]+f[1]));
{
__auto_type cn_init_566 = cn_double(v26); __auto_type v = cn_init_566;
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
__auto_type cn_init_681 = 0x41U; __auto_type bv = cn_init_681;
__auto_type cn_init_694 = cn_reg_get(rg,4,1); __auto_type av = cn_init_694;
__auto_type cn_init_712 = cn_alu(&fl,Alu_And,av,bv,1); __auto_type r = cn_init_712;
cn_reg_set(rg,4,1,r);
}
if(cn_cond(fl,15)){
goto cn_break_b2;
}
(f[0]=-f[0]);
}
cn_break_b2:;
{
__auto_type cn_init_761 = cn_double(r4); __auto_type v = cn_init_761;
(f[0]=(f[0]+v));
}
(f[1]=cn_double(v29));
{
__auto_type cn_init_797 = cn_double(r3); __auto_type v = cn_init_797;
(f[1]=(f[1]-v));
}
{
__auto_type cn_init_821 = cn_double(v30); __auto_type v = cn_init_821;
(f[1]=(f[1]*v));
}
(f[2]=cn_double(v29));
{
__auto_type cn_init_857 = cn_double(r4); __auto_type v = cn_init_857;
(f[2]=(f[2]*v));
}
(f[3]=cn_double(r3));
{
__auto_type cn_init_893 = cn_double(v28); __auto_type v = cn_init_893;
(f[3]=(f[3]*v));
}
(f[3]=-f[3]);
(f[2]=(f[2]+f[3]));
{
__auto_type cn_init_943 = cn_double(v25); __auto_type v = cn_init_943;
(f[2]=(f[2]*v));
}
{
__auto_type cn_init_967 = cn_double(r5); __auto_type v = cn_init_967;
(f[2]=(f[2]+v));
}
(r5=cn_bits(f[2]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static inline Vec cf_pure_f37a6105e1854b32(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v27=cn_cell(vm,0);
uint64_t v28=cn_cell(vm,8);
uint64_t v29=cn_cell(vm,16);
uint64_t v30=cn_cell(vm,24);

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
return (Vec){z.x,z.y,cn_double(r5)};
}
static inline Vec cf_pure_ff9c8cad98242cf2(Vec z,double *fourth,const unsigned char *vm,uint32_t pvar){
#pragma clang fp contract(off)
CN_D8 f={0};CN_U8 rg={0x10001018,0x10001028,0x10001020,0,0x10007ef4,0,0,0};CN_Flags fl={0};unsigned fsw=0;uint32_t vb=pvar-256;
uint64_t r13=pvar;
uint64_t r3=cn_bits(z.x);
uint64_t r4=cn_bits(z.y);
uint64_t r5=cn_bits(z.z);
uint64_t s2013=0;
uint64_t s2014=UINT64_C(0xfffffff000000000);
uint64_t s2015=UINT64_C(0x1000103010001038);
uint64_t v30=cn_cell(vm,0);

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
(f[0]=cn_double(v30));
(f[1]=cn_double(r5));
(f[2]=f[1]);
(f[2]=(f[2]-f[0]));
(f[2]=fabs(f[2]));
cn_swap(f,2,1);
(f[2]=(f[2]+f[0]));
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_459 = cn_double(r5); __auto_type v = cn_init_459;
(f[1]=(f[1]-v));
}
(r5=cn_bits(f[1]));
(f[1]=cn_double(r4));
(f[2]=f[1]);
(f[2]=(f[2]-f[0]));
(f[2]=fabs(f[2]));
cn_swap(f,2,1);
(f[2]=(f[2]+f[0]));
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_598 = cn_double(r4); __auto_type v = cn_init_598;
(f[1]=(f[1]-v));
}
(r4=cn_bits(f[1]));
(f[1]=cn_double(r3));
(f[2]=f[1]);
(f[2]=(f[2]-f[0]));
(f[2]=fabs(f[2]));
cn_swap(f,2,1);
(f[2]=(f[2]+f[0]));
(f[2]=fabs(f[2]));
(f[1]=(f[2]-f[1]));
{
__auto_type cn_init_737 = cn_double(r3); __auto_type v = cn_init_737;
(f[1]=(f[1]-v));
}
(r3=cn_bits(f[1]));
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
return (Vec){cn_double(r3),cn_double(r4),cn_double(r5)};
}
static unsigned cf_pure_index(const char *name){
if(!strcasecmp(name,"_T_AbsAddConditional"))return 17;
if(!strcasecmp(name,"_T_AbsOffset"))return 17;
if(!strcasecmp(name,"_F_MandalayFold"))return 37;
if(!strcasecmp(name,"_T_Wobble"))return 39;
if(!strcasecmp(name,"_F_AbsFold"))return 40;
if(!strcasecmp(name,"_T_ScaleOffset"))return 55;
if(!strcasecmp(name,"_F_MandalayFold4D"))return 62;
if(!strcasecmp(name,"CrossMenger"))return 63;
if(!strcasecmp(name,"_T_SqrtAdd"))return 74;
if(!strcasecmp(name,"_T_AbsOffset4D"))return 85;
if(!strcasecmp(name,"_T_Scale3D"))return 115;
if(!strcasecmp(name,"_T_Scale4D"))return 134;
if(!strcasecmp(name,"_T_Offset"))return 135;
if(!strcasecmp(name,"_Sin4Dplus"))return 4;
if(!strcasecmp(name,"_Tanh4D"))return 5;
if(!strcasecmp(name,"_poincare"))return 6;
if(!strcasecmp(name,"_invtorical"))return 7;
if(!strcasecmp(name,"_conj4D"))return 8;
if(!strcasecmp(name,"_planeFold"))return 9;
if(!strcasecmp(name,"_invtorical2"))return 10;
if(!strcasecmp(name,"_hopalm2"))return 11;
if(!strcasecmp(name,"_YplusSinZ"))return 12;
if(!strcasecmp(name,"MengerKoch"))return 2;
if(!strcasecmp(name,"_Fold45double"))return 13;
if(!strcasecmp(name,"_Folding2"))return 14;
if(!strcasecmp(name,"_Translate"))return 15;
if(!strcasecmp(name,"_rabinovich-f"))return 16;
if(!strcasecmp(name,"koch_oct"))return 18;
if(!strcasecmp(name,"_FoldingTetra3d"))return 19;
if(!strcasecmp(name,"_Exp4D"))return 20;
if(!strcasecmp(name,"_HopSqrtX"))return 21;
if(!strcasecmp(name,"_BRotateToMag"))return 22;
if(!strcasecmp(name,"_dynamic"))return 23;
if(!strcasecmp(name,"_BT2_Transform2"))return 25;
if(!strcasecmp(name,"_BenesiT2"))return 25;
if(!strcasecmp(name,"_NeoSqrY"))return 26;
if(!strcasecmp(name,"MengerHyper"))return 27;
if(!strcasecmp(name,"_LogY"))return 28;
if(!strcasecmp(name,"_AbsZ"))return 29;
if(!strcasecmp(name,"_SinhY"))return 30;
if(!strcasecmp(name,"_Rotate4d"))return 31;
if(!strcasecmp(name,"_AbsY"))return 32;
if(!strcasecmp(name,"_coordvspow"))return 33;
if(!strcasecmp(name,"_FlipYZ"))return 34;
if(!strcasecmp(name,"_skew"))return 35;
if(!strcasecmp(name,"_Rotate"))return 36;
if(!strcasecmp(name,"_sqr_4D"))return 38;
if(!strcasecmp(name,"_SinhX"))return 41;
if(!strcasecmp(name,"_NeoSqrX"))return 42;
if(!strcasecmp(name,"HalfOctIFS"))return 43;
if(!strcasecmp(name,"_reciprocalX3b"))return 44;
if(!strcasecmp(name,"_RotateBack"))return 45;
if(!strcasecmp(name,"_Fold45single"))return 46;
if(!strcasecmp(name,"_reciprocalX2"))return 47;
if(!strcasecmp(name,"_quadist"))return 48;
if(!strcasecmp(name,"_reciprocalY2"))return 49;
if(!strcasecmp(name,"_HopSqrtZ"))return 50;
if(!strcasecmp(name,"_YplusSinZ2"))return 51;
if(!strcasecmp(name,"Sierpinski3"))return 52;
if(!strcasecmp(name,"_toruspinv3"))return 53;
if(!strcasecmp(name,"_NeoSqrZ"))return 54;
if(!strcasecmp(name,"_HopSqrtY"))return 56;
if(!strcasecmp(name,"_lorenz"))return 57;
if(!strcasecmp(name,"_BT1_4D_Transform1"))return 58;
if(!strcasecmp(name,"_sphereZinv"))return 59;
if(!strcasecmp(name,"_totorical2"))return 60;
if(!strcasecmp(name,"_BT4_Transform4"))return 61;
if(!strcasecmp(name,"_gnarl2D_2"))return 64;
if(!strcasecmp(name,"_BRotateFromMag"))return 66;
if(!strcasecmp(name,"OctKoch"))return 1;
if(!strcasecmp(name,"_Scaling"))return 67;
if(!strcasecmp(name,"Riemann2"))return 68;
if(!strcasecmp(name,"_conj"))return 69;
if(!strcasecmp(name,"_invspherical"))return 70;
if(!strcasecmp(name,"_MaxClipping"))return 71;
if(!strcasecmp(name,"OctaFullIFS"))return 72;
if(!strcasecmp(name,"CrossBiFold"))return 73;
if(!strcasecmp(name,"_vanderpol"))return 75;
if(!strcasecmp(name,"_RotatedAbs"))return 76;
if(!strcasecmp(name,"_reciprocalY3b"))return 77;
if(!strcasecmp(name,"_LogZ"))return 78;
if(!strcasecmp(name,"_gnarl3D"))return 79;
if(!strcasecmp(name,"_BT3_Transform3"))return 80;
if(!strcasecmp(name,"_BenesiT3"))return 80;
if(!strcasecmp(name,"_toruspinv1"))return 81;
if(!strcasecmp(name,"_invcylindrical"))return 82;
if(!strcasecmp(name,"DodecahedronIFSex"))return 83;
if(!strcasecmp(name,"_reciprocalZ2"))return 84;
if(!strcasecmp(name,"_BT1_4D_clampXYZ"))return 86;
if(!strcasecmp(name,"MengerSmt"))return 87;
if(!strcasecmp(name,"_Atan4D"))return 88;
if(!strcasecmp(name,"_hyc3Dinv"))return 89;
if(!strcasecmp(name,"_invbisp"))return 90;
if(!strcasecmp(name,"_sphereXinv"))return 91;
if(!strcasecmp(name,"_toruspinv2"))return 92;
if(!strcasecmp(name,"_BenesiSpheric"))return 93;
if(!strcasecmp(name,"OctahedronIFS"))return 94;
if(!strcasecmp(name,"JCube3"))return 95;
if(!strcasecmp(name,"_kamtorcut"))return 96;
if(!strcasecmp(name,"SierpHilbert"))return 97;
if(!strcasecmp(name,"_asdamTrans"))return 98;
if(!strcasecmp(name,"_cosmartin"))return 99;
if(!strcasecmp(name,"_rossler"))return 100;
if(!strcasecmp(name,"_tospherical"))return 101;
if(!strcasecmp(name,"MengerIFS"))return 102;
if(!strcasecmp(name,"_totorical"))return 103;
if(!strcasecmp(name,"Sierpinski3alt"))return 104;
if(!strcasecmp(name,"_FoldingIcosa"))return 105;
if(!strcasecmp(name,"_FoldingOct"))return 106;
if(!strcasecmp(name,"_FlipXZ"))return 107;
if(!strcasecmp(name,"_reciprocalZ3"))return 108;
if(!strcasecmp(name,"_Log4D"))return 109;
if(!strcasecmp(name,"_Scalingplus"))return 110;
if(!strcasecmp(name,"_FoldingVar"))return 111;
if(!strcasecmp(name,"_SinePow2"))return 112;
if(!strcasecmp(name,"_BenesiUnSpheric"))return 113;
if(!strcasecmp(name,"Menger3"))return 114;
if(!strcasecmp(name,"_vanderpol2"))return 116;
if(!strcasecmp(name,"_sphereYinv"))return 117;
if(!strcasecmp(name,"_reciprocalZ3b"))return 118;
if(!strcasecmp(name,"_BT5b_Transform5b"))return 119;
if(!strcasecmp(name,"_gnarl2D"))return 120;
if(!strcasecmp(name,"_tocylindrical"))return 121;
if(!strcasecmp(name,"_sphereinv"))return 122;
if(!strcasecmp(name,"_AbsX"))return 123;
if(!strcasecmp(name,"_reciprocalY3"))return 124;
if(!strcasecmp(name,"_FoldingTetraKaleid"))return 125;
if(!strcasecmp(name,"_reciprocalX3"))return 126;
if(!strcasecmp(name,"MengerIFSplus"))return 127;
if(!strcasecmp(name,"_sqr_3D"))return 128;
if(!strcasecmp(name,"SierpinskiFull"))return 129;
if(!strcasecmp(name,"_RotatedFolding"))return 3;
if(!strcasecmp(name,"_FlipXY"))return 130;
if(!strcasecmp(name,"_kamtor"))return 131;
if(!strcasecmp(name,"_LogX"))return 132;
if(!strcasecmp(name,"CantorIFS"))return 133;
if(!strcasecmp(name,"_reciprocalX"))return 136;
if(!strcasecmp(name,"_LinCombineXYZ"))return 137;
if(!strcasecmp(name,"_MobiusTpx"))return 138;
if(!strcasecmp(name,"DodecahedronIFS"))return 139;
if(!strcasecmp(name,"IcosahedronIFS"))return 139;
if(!strcasecmp(name,"_AmazingBox"))return 140;
if(!strcasecmp(name,"_SinY"))return 141;
if(!strcasecmp(name,"_T_Sin_XYZ"))return 141;
if(!strcasecmp(name,"_hopalm1"))return 142;
if(!strcasecmp(name,"_conj2D"))return 143;
if(!strcasecmp(name,"_Abs4d"))return 144;
if(!strcasecmp(name,"_BT1_Transform1"))return 145;
if(!strcasecmp(name,"_BenesiT1"))return 145;
if(!strcasecmp(name,"koch_cube"))return 146;
if(!strcasecmp(name,"MengerKochV2"))return 147;
if(!strcasecmp(name,"_hopalong"))return 148;
if(!strcasecmp(name,"_SinhZ"))return 149;
if(!strcasecmp(name,"_Folding1"))return 150;
if(!strcasecmp(name,"_F_BoxFold"))return 150;
if(!strcasecmp(name,"_dynamicfast"))return 24;
if(!strcasecmp(name,"_gnarl2D_2fast"))return 65;
return 0;}
static inline __attribute__((always_inline)) Vec cf_pure_dispatch(unsigned index,Vec z,double *fourth,const unsigned char *variables,uint32_t pvar){switch(index){
case 1:return cf_pure_6ad79cbb14959655(z,fourth,variables+120,pvar);
case 2:return cf_pure_09c020b05d5686d9(z,fourth,variables+128,pvar);
case 3:return cf_pure_d696fec44725d3b1(z,fourth,variables+200,pvar);
case 4:return cf_pure_0202689ab0f2cd69(z,fourth,variables+208,pvar);
case 5:return cf_pure_03738db42599e61c(z,fourth,variables+208,pvar);
case 6:return cf_pure_04c5648d94adc5e4(z,fourth,variables+208,pvar);
case 7:return cf_pure_069ac184d3b6d59b(z,fourth,variables+240,pvar);
case 8:return cf_pure_06b6f1ba8ace3036(z,fourth,variables+0,pvar);
case 9:return cf_pure_070a62f7d5d36334(z,fourth,variables+224,pvar);
case 10:return cf_pure_075f0c3a3cc4a54d(z,fourth,variables+232,pvar);
case 11:return cf_pure_07636de187847446(z,fourth,variables+200,pvar);
case 12:return cf_pure_09bec55c100b1dd9(z,fourth,variables+0,pvar);
case 13:return cf_pure_09f9d674da6dccaf(z,fourth,variables+216,pvar);
case 14:return cf_pure_0aa79304be5365d1(z,fourth,variables+232,pvar);
case 15:return cf_pure_0c932fcfcb9267a3(z,fourth,variables+224,pvar);
case 16:return cf_pure_0cb3daf3eba3172e(z,fourth,variables+208,pvar);
case 17:return cf_pure_10b6bb1104349cbf(z,fourth,variables+224,pvar);
case 18:return cf_pure_117351c6664c8709(z,fourth,variables+136,pvar);
case 19:return cf_pure_12950cb060c90325(z,fourth,variables+240,pvar);
case 20:return cf_pure_1303ccb7dbfec158(z,fourth,variables+256,pvar);
case 21:return cf_pure_13798995920dbc66(z,fourth,variables+216,pvar);
case 22:return cf_pure_14ea390f09101007(z,fourth,variables+256,pvar);
case 23:return cf_pure_170d88a7063dc19f(z,fourth,variables+208,pvar);
case 24:return cf_pure_170d88a7063dc19f_fast(z,fourth,variables+208,pvar);
case 25:return cf_pure_1843a4e57d14edaa(z,fourth,variables+232,pvar);
case 26:return cf_pure_19167e07a00f877b(z,fourth,variables+216,pvar);
case 27:return cf_pure_1b455c469f6af2bc(z,fourth,variables+160,pvar);
case 28:return cf_pure_1b4a584dbcc33356(z,fourth,variables+216,pvar);
case 29:return cf_pure_1c600993a98ac491(z,fourth,variables+240,pvar);
case 30:return cf_pure_1c9a2f979ccd5056(z,fourth,variables+216,pvar);
case 31:return cf_pure_1e2a7e409a31e0cc(z,fourth,variables+184,pvar);
case 32:return cf_pure_205ab96c98f98fb9(z,fourth,variables+240,pvar);
case 33:return cf_pure_20f481396f51978b(z,fourth,variables+216,pvar);
case 34:return cf_pure_29e575922b051916(z,fourth,variables+0,pvar);
case 35:return cf_pure_2a196bafa4357ec1(z,fourth,variables+232,pvar);
case 36:return cf_pure_2aa886369f57321b(z,fourth,variables+208,pvar);
case 37:return cf_pure_2dffd31d561b9853(z,fourth,variables+224,pvar);
case 38:return cf_pure_2e69ea4edc1c5736(z,fourth,variables+208,pvar);
case 39:return cf_pure_30e2e60d6a23e99d(z,fourth,variables+216,pvar);
case 40:return cf_pure_31ca3aecc58e5db3(z,fourth,variables+0,pvar);
case 41:return cf_pure_31f1cc5bee2024dc(z,fourth,variables+216,pvar);
case 42:return cf_pure_333566b600828b95(z,fourth,variables+216,pvar);
case 43:return cf_pure_334f193283f9597c(z,fourth,variables+144,pvar);
case 44:return cf_pure_359551ba93faa981(z,fourth,variables+200,pvar);
case 45:return cf_pure_3a746f46e88503db(z,fourth,variables+208,pvar);
case 46:return cf_pure_3ac60c1633414f8d(z,fourth,variables+216,pvar);
case 47:return cf_pure_3f765c463884471f(z,fourth,variables+240,pvar);
case 48:return cf_pure_40561823f83f886e(z,fourth,variables+192,pvar);
case 49:return cf_pure_416ffd7ed9f878b8(z,fourth,variables+240,pvar);
case 50:return cf_pure_43a8a7c55cb24ee2(z,fourth,variables+216,pvar);
case 51:return cf_pure_43f63d71687dcf8b(z,fourth,variables+232,pvar);
case 52:return cf_pure_44e92884ff4d508e(z,fourth,variables+144,pvar);
case 53:return cf_pure_4819d80a4da95daa(z,fourth,variables+208,pvar);
case 54:return cf_pure_4a43a2f50978fa91(z,fourth,variables+216,pvar);
case 55:return cf_pure_4aa26c3c41bb6ac8(z,fourth,variables+200,pvar);
case 56:return cf_pure_4c9b645e9971eba8(z,fourth,variables+216,pvar);
case 57:return cf_pure_4da5e2239ba1634f(z,fourth,variables+208,pvar);
case 58:return cf_pure_4fc7552e2ed9ae63(z,fourth,variables+232,pvar);
case 59:return cf_pure_558b81855fc0a4dd(z,fourth,variables+216,pvar);
case 60:return cf_pure_58fc3b5da2368ee2(z,fourth,variables+232,pvar);
case 61:return cf_pure_59d6a2c368055035(z,fourth,variables+232,pvar);
case 62:return cf_pure_5e299e82b7f6da6b(z,fourth,variables+216,pvar);
case 63:return cf_pure_621449000c668362(z,fourth,variables+160,pvar);
case 64:return cf_pure_6405c0b3abe12770(z,fourth,variables+200,pvar);
case 65:return cf_pure_6405c0b3abe12770_fast(z,fourth,variables+200,pvar);
case 66:return cf_pure_66497f3d431c0918(z,fourth,variables+256,pvar);
case 67:return cf_pure_6dbf92dffd82a711(z,fourth,variables+240,pvar);
case 68:return cf_pure_6dd65a6c7247a4c4(z,fourth,variables+144,pvar);
case 69:return cf_pure_6e5886c6b8245080(z,fourth,variables+0,pvar);
case 70:return cf_pure_706f52a872fbf811(z,fourth,variables+0,pvar);
case 71:return cf_pure_70eaf2b0be9e4ef8(z,fourth,variables+224,pvar);
case 72:return cf_pure_71785d1d5a875d8d(z,fourth,variables+144,pvar);
case 73:return cf_pure_7179dcb1d7591178(z,fourth,variables+128,pvar);
case 74:return cf_pure_747c6c9d1edf0d4e(z,fourth,variables+224,pvar);
case 75:return cf_pure_761967f9cfb5d4ab(z,fourth,variables+184,pvar);
case 76:return cf_pure_7820bdda2a825c7e(z,fourth,variables+192,pvar);
case 77:return cf_pure_789b0e6fa175e144(z,fourth,variables+200,pvar);
case 78:return cf_pure_7a6c90aeb7f60905(z,fourth,variables+216,pvar);
case 79:return cf_pure_7db073976a2f1e2e(z,fourth,variables+200,pvar);
case 80:return cf_pure_7efcd46b624cb1bb(z,fourth,variables+232,pvar);
case 81:return cf_pure_7f9fef6fa0413ff0(z,fourth,variables+208,pvar);
case 82:return cf_pure_7fb5cdafeec5dbf0(z,fourth,variables+0,pvar);
case 83:return cf_pure_85d2e5da4f43de0e(z,fourth,variables+128,pvar);
case 84:return cf_pure_889ae4f4102ead81(z,fourth,variables+240,pvar);
case 85:return cf_pure_8a7908c7e72f01c6(z,fourth,variables+216,pvar);
case 86:return cf_pure_8ad16c5350b999d7(z,fourth,variables+232,pvar);
case 87:return cf_pure_8b8b7877060a52b7(z,fourth,variables+160,pvar);
case 88:return cf_pure_8e56fc6ffe930349(z,fourth,variables+208,pvar);
case 89:return cf_pure_8f3653401b1e95a6(z,fourth,variables+216,pvar);
case 90:return cf_pure_8f5d0319bab0a995(z,fourth,variables+240,pvar);
case 91:return cf_pure_8ff344f00b5b64dd(z,fourth,variables+216,pvar);
case 92:return cf_pure_90df87328b904240(z,fourth,variables+208,pvar);
case 93:return cf_pure_939f180fc0184ac7(z,fourth,variables+240,pvar);
case 94:return cf_pure_99355b3a19457e8c(z,fourth,variables+144,pvar);
case 95:return cf_pure_9e2252b50e598467(z,fourth,variables+176,pvar);
case 96:return cf_pure_a11ae827485a8b8b(z,fourth,variables+136,pvar);
case 97:return cf_pure_a1f064eaf002bf06(z,fourth,variables+128,pvar);
case 98:return cf_pure_a20b4efe403de33c(z,fourth,variables+200,pvar);
case 99:return cf_pure_a4250598b4a80ded(z,fourth,variables+208,pvar);
case 100:return cf_pure_a54e8329bc37d850(z,fourth,variables+208,pvar);
case 101:return cf_pure_a6dbf2766292a63e(z,fourth,variables+0,pvar);
case 102:return cf_pure_a7936171b561b3d0(z,fourth,variables+176,pvar);
case 103:return cf_pure_a85da18b6fe095bc(z,fourth,variables+240,pvar);
case 104:return cf_pure_a9861b5923bb62f5(z,fourth,variables+152,pvar);
case 105:return cf_pure_aba37e0cdc6ee259(z,fourth,variables+208,pvar);
case 106:return cf_pure_ac3ff5358b339fc8(z,fourth,variables+0,pvar);
case 107:return cf_pure_ad57da69411cd8be(z,fourth,variables+0,pvar);
case 108:return cf_pure_b2453fefc3b1431c(z,fourth,variables+232,pvar);
case 109:return cf_pure_b31dd057e6ca45d3(z,fourth,variables+256,pvar);
case 110:return cf_pure_b4cf373b9466e13e(z,fourth,variables+216,pvar);
case 111:return cf_pure_b5d34f8186a0b281(z,fourth,variables+152,pvar);
case 112:return cf_pure_b79b4e171c1ff1e4(z,fourth,variables+232,pvar);
case 113:return cf_pure_b8c0565aa1a8fd35(z,fourth,variables+240,pvar);
case 114:return cf_pure_bd743493286d2fa8(z,fourth,variables+144,pvar);
case 115:return cf_pure_bdee0a1f4f1c566e(z,fourth,variables+224,pvar);
case 116:return cf_pure_bfc76004fae4a28f(z,fourth,variables+176,pvar);
case 117:return cf_pure_c0d951c2712fba4d(z,fourth,variables+216,pvar);
case 118:return cf_pure_c2594bf5906a27ea(z,fourth,variables+200,pvar);
case 119:return cf_pure_c5f3828c89d58fc9(z,fourth,variables+232,pvar);
case 120:return cf_pure_c8b3802efdcf5a9b(z,fourth,variables+208,pvar);
case 121:return cf_pure_ca112d82bc2dc67f(z,fourth,variables+0,pvar);
case 122:return cf_pure_ccc969eed4f1b60e(z,fourth,variables+192,pvar);
case 123:return cf_pure_cd09cc47b9ba875d(z,fourth,variables+240,pvar);
case 124:return cf_pure_d015ffb71f7f9999(z,fourth,variables+232,pvar);
case 125:return cf_pure_d02a4629db0ffb5f(z,fourth,variables+232,pvar);
case 126:return cf_pure_d1e51e777240591a(z,fourth,variables+232,pvar);
case 127:return cf_pure_d3df2096124fd53c(z,fourth,variables+152,pvar);
case 128:return cf_pure_d532c72efd01249a(z,fourth,variables+216,pvar);
case 129:return cf_pure_d5af0918cbb46f3c(z,fourth,variables+120,pvar);
case 130:return cf_pure_daa911bbd21a5ba2(z,fourth,variables+0,pvar);
case 131:return cf_pure_db586ffc50e7c8e7(z,fourth,variables+136,pvar);
case 132:return cf_pure_ddde751ec8e90b97(z,fourth,variables+216,pvar);
case 133:return cf_pure_de55c3c3116fbbd7(z,fourth,variables+144,pvar);
case 134:return cf_pure_e000d141ddd3a421(z,fourth,variables+216,pvar);
case 135:return cf_pure_e04801556de19bc6(z,fourth,variables+224,pvar);
case 136:return cf_pure_e1bb3a40c593b4a2(z,fourth,variables+0,pvar);
case 137:return cf_pure_e23b233b039146cd(z,fourth,variables+176,pvar);
case 138:return cf_pure_e3aa4cd1134817bf(z,fourth,variables+152,pvar);
case 139:return cf_pure_e414957dff3bdb3b(z,fourth,variables+144,pvar);
case 140:return cf_pure_e589ab23df662be4(z,fourth,variables+224,pvar);
case 141:return cf_pure_e5b10d9b6546bbe5(z,fourth,variables+224,pvar);
case 142:return cf_pure_e60fa9d255bb9543(z,fourth,variables+200,pvar);
case 143:return cf_pure_ea6233620ddaa142(z,fourth,variables+0,pvar);
case 144:return cf_pure_eb5df2ab5cec6849(z,fourth,variables+0,pvar);
case 145:return cf_pure_eba3ca997c3e90a6(z,fourth,variables+232,pvar);
case 146:return cf_pure_f15e7033ae08e677(z,fourth,variables+160,pvar);
case 147:return cf_pure_f19722dc8c8c12d9(z,fourth,variables+128,pvar);
case 148:return cf_pure_f1d590365a4793b6(z,fourth,variables+200,pvar);
case 149:return cf_pure_f37a6105e1854b32(z,fourth,variables+216,pvar);
case 150:return cf_pure_ff9c8cad98242cf2(z,fourth,variables+240,pvar);
default:return z;}}
#pragma clang diagnostic pop
