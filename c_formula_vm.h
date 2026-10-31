/* Native C execution of the complete bundled formula catalog.
 * No Rust code is linked or called by this executor. LGPL-2.1-or-later. */
#include "native-c/runtime.h"
#include "native-c/compact.h"
#include "c_formula_code.h"
#include "c_formula_native.h"
#include "c_formula_compact.h"
#define CF_BASE 0x10000000u
#define CF_REC (CF_BASE+0x1000u)
#define CF_VAR(n) (CF_BASE+0x2000u+(n)*0x400u)
#define CF_CODE(n) (0x20000000u+(n)*0x10000u)
#define CF_TOP (CF_BASE+0x7f00u)
#define CF_RETURN 0xfffffff0u
static const CFormulaCode *cf_code_for(int kind){static _Thread_local int keys[16];static _Thread_local const CFormulaCode *values[16];static _Thread_local unsigned cursor;for(int i=0;i<16;i++)if(keys[i]==kind&&keys[i])return values[i];const char *name=formula_name(kind);for(size_t i=0;i<sizeof c_formula_codes/sizeof *c_formula_codes;i++)if(!strcasecmp(name,c_formula_codes[i].name)){unsigned n=cursor++%16;keys[n]=kind;values[n]=c_formula_codes+i;return c_formula_codes+i;}unsigned n=cursor++%16;keys[n]=kind;values[n]=NULL;return NULL;}
static atomic_int cf_error;
/* Diagnostic oracle switch; production always uses prepared execution. */
static _Thread_local int cf_reference_execution;
static char cf_error_message[512];
static void cf_fail(int kind,const char *reason){int expected=0;if(atomic_compare_exchange_strong(&cf_error,&expected,1))snprintf(cf_error_message,sizeof cf_error_message,"Formula %s: %s",formula_name(kind),reason);}
static void cf_matrix(double x,double y,double z,double m[9]){double sx=sin(x),cx=cos(x),sy=sin(y),cy=cos(y),sz=sin(z),cz=cos(z);double a[]={cy*cz,-cy*sz,sy,sx*sy*cz+cx*sz,cx*cz-sx*sy*sz,-sx*cy,sx*sz-cx*sy*cz,cx*sy*sz+sx*cz,cx*cy};memcpy(m,a,sizeof a);}
static void cf_down(unsigned char *b,int *p,double v,int type){int bytes=type==0?8:4;*p-=bytes;if(*p<0)return;if(!type)memcpy(b+*p,&v,8);else if(type==1){float f=v;memcpy(b+*p,&f,4);}else{int32_t n=isfinite(v)?(int32_t)clamp(nearbyint(v),INT32_MIN,INT32_MAX):0;memcpy(b+*p,&n,4);}}
static void cf_var_buffer(FormulaSlot f,const CFormulaCode *code,unsigned char b[1024]){
    static const int needed[]={8,4,4,16,8,72,36,16,40,8,0,32,64,8,16,8,8,16,36,8,8,8,16};
    memset(b,0,1024);if(code&&code->constant_size<=768)memcpy(b+256,code->constants,code->constant_size);int p=256;cf_down(b,&p,.5,0);double a[24]={0};int n=formula_parameter_count(f.kind);for(int i=0;i<n;i++)a[i]=formula_slot_value(f,i);
    for(int i=0;i<n;i++){int t=formula_option_type(f.kind,i);double v=a[i];if(t<0||t>22||256-p+needed[t]>=257)continue;
#define DOWN(v,t) cf_down(b,&p,(v),(t))
        switch(t){case 0:DOWN(v,0);break;case 1:DOWN(v,1);break;case 2:DOWN(v,2);break;
        case 3:case 4:DOWN(sin(v*PI/180),t==3?0:1);DOWN(cos(v*PI/180),t==3?0:1);break;
        case 5:case 6:{double m[9];cf_matrix(v*PI/180,a[i+1]*PI/180,a[i+2]*PI/180,m);for(int j=0;j<9;j++)DOWN(m[j],t==5?0:1);i+=2;break;}
        case 7:{double r=fmax(1e-40,v);DOWN((i?a[i-1]:0)/(r*r),0);DOWN(r*r,0);break;}
        case 8:DOWN(v,0);DOWN(2*v,0);DOWN(-v,0);DOWN(-2*v,0);p-=4;if(i>1){uint32_t ptr=CF_BASE+0xf000+(unsigned)clamp(nearbyint(a[i-2]),2,8)*16;memcpy(b+p,&ptr,4);}break;
        case 9:DOWN(v*v,0);break;case 10:break;case 11:DOWN(v,0);DOWN(v,0);DOWN(-v,0);DOWN(-v,0);break;
        case 12:{int u[]={1,0,0,0,1,2},w[]={2,2,1,3,3,3};float m[16]={0};for(int j=0;j<4;j++)m[j*4+j]=1;
            for(int k=0;k<6;k++){float r[16]={0},next[16]={0};for(int j=0;j<4;j++)r[j*4+j]=1;double angle=a[i+k]*PI/180;r[u[k]*4+u[k]]=r[w[k]*4+w[k]]=cos(angle);r[u[k]*4+w[k]]=-sin(angle);r[w[k]*4+u[k]]=sin(angle);for(int x=0;x<4;x++)for(int y=0;y<4;y++)for(int z=0;z<4;z++)next[x*4+y]+=r[x*4+z]*m[z*4+y];memcpy(m,next,sizeof m);}for(int j=0;j<16;j++)DOWN(m[j],1);i+=5;break;}
        case 13:DOWN(1/(fabs(v)<1e-40?(v<0?-1e-40:1e-40):v),0);break;case 14:DOWN(v,0);DOWN(v,0);break;case 15:DOWN(1/fmax(1e-40,v*v),0);break;
        case 16:case 17:for(int j=0;j<(t==17?4:2);j++)DOWN(v,1);break;
        case 18:{double m[9];cf_matrix(a[i+1]*PI/180,a[i+2]*PI/180,a[i+3]*PI/180,m);for(int j=0;j<9;j++)DOWN(m[j]*v,1);i+=3;break;}
        case 19:DOWN(sin(a[i+1]*PI/180)*v,1);DOWN(cos(a[i+1]*PI/180)*v,1);i++;break;
        case 20:DOWN(v,2);DOWN(v,2);break;case 21:DOWN(v,1);DOWN(1/fmaxf(1e-30f,(float)v),1);break;case 22:DOWN(v,0);DOWN(1/fmax(1e-40,v),0);break;
        }
#undef DOWN
    }
}
typedef struct {CN_Machine native;CN_Function functions[8];CN_CompactPlan contexts[8];const RustFormula *metadata[8];double powers[8],values[8][16];unsigned char modifiers[8],slot_four_d[8],procedural[8],compact[8];unsigned char *mem;unsigned char variables[8][1024];FormulaProgram program;int prepared,kind,count,slot,four_d,full_reset,retained_de;unsigned stack_low;float power_logs[6];} CFormulaVM;
static pthread_key_t cf_key;static pthread_once_t cf_once=PTHREAD_ONCE_INIT;
static void cf_destroy(void *ptr){CFormulaVM *v=ptr;if(!v)return;free(v->mem);free(v);}
static void cf_key_init(void){pthread_key_create(&cf_key,cf_destroy);}
static unsigned char *cf_ptr(CFormulaVM *v,uint32_t a,size_t n){if(a<CF_BASE||(uint64_t)a+n>CF_BASE+65536)return NULL;return v->mem+a-CF_BASE;}
static double cf_rd(CFormulaVM *v,uint32_t a){double d=NAN;unsigned char *p=cf_ptr(v,a,8);if(p)memcpy(&d,p,8);return d;}

static void cf_wd(CFormulaVM *v,uint32_t a,double d){unsigned char *p=cf_ptr(v,a,8);if(p)memcpy(p,&d,8);}
static void cf_wi(CFormulaVM *v,uint32_t a,uint32_t d){unsigned char *p=cf_ptr(v,a,4);if(p)memcpy(p,&d,4);}
CN_D3 cn_map_px(bool spherical,int number,CN_D3 xyz){Vec p={xyz[0],xyz[1],xyz[2]};double u=p.x,w=p.y;if(spherical){double len=fmax(1e-300,sqrt(dot(p,p)));u=atan2(p.x,p.y)*(-.5/PI)+.5;w=.5-asin(clamp(p.z/len,-1,1))/PI;}Vec c=height_map_sample(number,u,w);return (CN_D3){c.x,c.y,c.z};}
int cn_height_host(CN_Machine *m,CN_U8 rg,CN_D8 f){(void)f;CN_D3 p={cn_rdf64u(m,rg[EAX]),cn_rdf64u(m,rg[EAX]+8),cn_rdf64u(m,rg[EAX]+16)};CN_D3 c=cn_map_px(false,(int)rg[EDX],p);for(int i=0;i<3;i++)cn_wrf64u(m,rg[ECX]+8*i,c[i]);return 0;}
static CFormulaVM *cf_vm(void){static _Thread_local CFormulaVM *cached;if(cached)return cached;pthread_once(&cf_once,cf_key_init);CFormulaVM *v=pthread_getspecific(cf_key);if(v){cached=v;return v;}v=calloc(1,sizeof *v);if(!v)return NULL;v->mem=calloc(1,65536+16);if(!v->mem){free(v);return NULL;}v->native.mem=v->mem;pthread_setspecific(cf_key,v);cached=v;return v;}
static void cf_begin(Vec point,Vec constant,double jw,int maxits){CFormulaVM *v=cf_vm();if(!v){cf_fail(0,"cannot initialize C formula executor");return;}const FormulaProgram *p=&scene.program;
    if(!v->prepared||memcmp(&v->program,p,sizeof *p)){for(int i=0;i<8;i++){const CFormulaCode *code=cf_code_for(p->slots[i].kind);unsigned char buf[1024];cf_var_buffer(p->slots[i],code,buf);memset(v->values[i],0,sizeof v->values[i]);for(int parameter=0;parameter<formula_parameter_count(p->slots[i].kind);parameter++)v->values[i][parameter]=formula_slot_value(p->slots[i],parameter);memcpy(v->variables[i],buf,1024);v->functions[i]=cn_lookup(formula_name(p->slots[i].kind));v->contexts[i]=cn_compact_lookup(formula_name(p->slots[i].kind));v->metadata[i]=rust_formula(p->slots[i].kind);v->modifiers[i]=formula_modifier(p->slots[i].kind);v->slot_four_d[i]=formula_four_d(p->slots[i].kind);double sip=code?code->si_pow:0;v->powers[i]=fmax(1.000001,sip>1?sip:formula_parameter_count(p->slots[i].kind)?fabs(formula_slot_value(p->slots[i],0)):2);const char *name=formula_name(p->slots[i].kind);v->compact[i]=v->metadata[i]&&v->metadata[i]->de<20&&!(v->contexts[i].state&16)?cf_pure_index(name):0;v->procedural[i]=!strcmp(name,"PseudoKleinian")?1:!strcmp(name,"SphereTree")?2:!strcmp(name,"UlamSpiral")?3:0;}v->program=*p;v->prepared=1;v->full_reset=0;v->stack_low=0x7f00;v->four_d=0;v->retained_de=0;for(int i=0;i<8;i++)if(p->slots[i].count){if(v->metadata[i]&&v->metadata[i]->de>=20)v->retained_de=1;if(formula_four_d(p->slots[i].kind))v->four_d=1;if(rust_formula(p->slots[i].kind)){CN_ResetInfo reset=cn_reset_info(formula_name(p->slots[i].kind));v->full_reset|=reset.full;if(reset.low<v->stack_low)v->stack_low=reset.low;}}
        for(int i=0;i<6;i++){const CFormulaCode *code=cf_code_for(p->slots[i].kind);double power=!p->slots[i].count?2:code&&code->si_pow>1?code->si_pow:fabs(formula_slot_value(p->slots[i],0));v->power_logs[i]=1/log(fmax(2,power));}
        memcpy(v->mem+0x2000,v->variables,sizeof v->variables);}

    if(v->full_reset){memcpy(v->mem+0x2000,v->variables,sizeof v->variables);memset(v->mem+0x4000,0,0x3f00);}else if(v->stack_low<0x7f00)memset(v->mem+v->stack_low,0,0x7f00-v->stack_low);
    v->native.cw=0x37f;
    memset(v->mem+0x1000,0,512);cf_wd(v,CF_REC,jw);cf_wd(v,CF_REC+8,scene.de_stop*2.1345/(scene.zoom*fmax(16,scene.width)));cf_wd(v,CF_REC+16,cf_rd(v,CF_REC+8));
    cf_wd(v,CF_REC+56,point.x);cf_wd(v,CF_REC+64,point.y);cf_wd(v,CF_REC+72,point.z);cf_wd(v,CF_REC+80,constant.x);cf_wd(v,CF_REC+88,constant.y);cf_wd(v,CF_REC+96,constant.z);
    memcpy(v->mem+0x1000+220,v->power_logs,sizeof v->power_logs);
    cf_wi(v,CF_REC+124,maxits);float stop=(float)(p->bailout*p->bailout);memcpy(v->mem+0x1000+128,&stop,4);cf_wi(v,CF_REC+208,scene.julia?~0u:0);
    for(int i=0;i<6;i++)cf_wi(v,CF_REC+132+i*4,p->slots[i].count);
    for(int i=0;i<8;i++)cf_wi(v,CF_REC+156+i*4,CF_VAR(i)+256);
    int end=0;for(int i=0;i<8;i++)if(p->slots[i].count)end=i;put16(v->mem+0x1000+206,end);put16(v->mem+0x1000+244,p->repeat_from);
    float lnstop=log(log((double)stop));memcpy(v->mem+0x1000+212,&lnstop,4);
    cf_wd(v,CF_REC+376,scene.julia_c.x);cf_wd(v,CF_REC+384,scene.julia_c.y);cf_wd(v,CF_REC+392,scene.julia_c.z);cf_wd(v,CF_REC+400,scene.julia_w);cf_wd(v,CF_REC+256,1);cf_wd(v,CF_REC+288,1);for(int i=0;i<16;i++)memcpy(v->mem+0x1000+312+4*i,&scene.matrix4[i],4);cf_wi(v,CF_REC+408,CF_BASE+0xf200);cf_wi(v,CF_REC+412,CF_BASE+0xf210);cf_wi(v,CF_REC+440,scene.program.render_mode==1?~0u:0);v->count=1;v->slot=0;
}
static int cf_slot_index(FormulaSlot f){for(int i=0;i<8;i++)if(scene.program.slots[i].kind==f.kind&&!memcmp(&scene.program.slots[i],&f,sizeof f))return i;for(int i=0;i<8;i++)if(scene.program.slots[i].kind==f.kind)return i;return 0;}
static Vec cf_source_step(Vec z,Vec *j,FormulaSlot f,const double p[16]){const char *name=formula_name(f.kind);
    if(!strcmp(name,"JITTrigExample")){z.x=sinh(z.x*p[0]);return z;}
    if(!strcmp(name,"JIT_IQ_Bulb")){double r=pow(sqrt(dot(z,z)),p[0]),a=atan2(hypot(z.x,z.z),z.y)*p[0],b=atan2(z.x,z.z)*p[0];return add((Vec){sin(b)*sin(a)*r,cos(a)*r,sin(a)*cos(b)*r},*j);}
    if(!strcmp(name,"JITBenesiPineTree")){double a=z.x*.816496580927726-z.z*.577350269189626,c=z.x*.577350269189626+z.z*.816496580927726,x=fabs((a-z.y)*.707106781186548),y=fabs((a+z.y)*.707106781186548);c=fabs(c);a=(x+y)*.707106781186548;y=(-x+y)*.707106781186548;x=a*.816496580927726+c*.577350269189626;c=-a*.577350269189626+c*.816496580927726;x=p[1]*x-p[0];y*=p[1];c*=p[1];double k=2*x/hypot(y,c);return (Vec){x*x-y*y-c*c+j->x,k*2*y*c,k*(y*y-c*c)};}
    cf_fail(f.kind,"missing C formula implementation");return (Vec){NAN,NAN,NAN};
}
static Vec cf_builtin_step(Vec z,Vec *j,FormulaSlot f,const RustFormula *meta,const double p[16]){double r=dot(z,z);
    if(meta->builtin==1){double a=atan2(z.y,z.x)*p[0],b=atan2(z.z,hypot(z.x,z.y))*p[0],v=pow(r,p[0]*.5);return add((Vec){cos(a)*cos(b)*v,sin(a)*cos(b)*v,sin(b)*v*p[1]},*j);}
    if(meta->builtin==3)return (Vec){z.x*z.x-z.y*z.y-z.z*z.z+j->x,2*z.x*z.y+j->y,z.z*z.x*p[0]+j->z*p[1]};
    if(meta->builtin==5){double factor=1;Vec box=add(amazing_box(z,p[0],p[1],p[2],&factor),*j);if(r>=p[4]*p[4])return box;Vec bulb=add(mul(integer_formula(mul(z,1/p[3]),2,-1),p[3]),*j);if(r<p[5]*p[5])return bulb;double m=(r-p[5]*p[5])/(p[4]*p[4]-p[5]*p[5]);Vec v=add(mul(box,m),mul(bulb,1-m));return mul(v,(sqrt(dot(box,box))*m+(1-m)*sqrt(dot(bulb,bulb)))/sqrt(dot(v,v)+1e-40));}
    if(meta->builtin==9){double a=atan2(hypot(z.x,z.z),z.y)*p[0],b=atan2(z.z,z.x)*p[0],v=pow(r,p[0]*.5);z=add((Vec){cos(b)*cos(a)*v,cos(a)*sin(b)*v,sin(a)*v*p[1]},*j);if(p[2]!=0){double power=p[4];if(p[6]!=0){Vec d=add(z,mul(*j,-1));power*=sqrt(dot(d,d));}double radius=sqrt(dot(*j,*j)),x=j->y,y=j->z,c=j->x;int mode=(int)p[7],ofs=0,ecx=8;if(mode&16){x=z.y-j->y;y=z.z-j->z;c=z.x-j->x;}if(mode&8){double t=x;x=y;y=t;ecx=16;}double t=hypot(y,c),theta=mode&1?atan2(x,t):atan2(t,x),phi;if(mode&2){ofs=24-ecx;phi=atan2(c,y);}else phi=atan2(y,c);if(mode&4){double t=theta;theta=phi;phi=t;ofs=ecx;}if(p[3]!=0){double test=ofs==0?z.x:ofs==8?z.y:z.z;if(!signbit(test))phi=-phi;}*j=(Vec){cos(phi*power)*cos(theta*power)*radius,cos(theta*power)*sin(phi*power)*radius,sin(theta*power)*radius*p[5]};}return z;}
    cf_fail(f.kind,"unknown built-in formula");return (Vec){NAN,NAN,NAN};
}
static Vec cf_step_at(Vec z,Vec *j,double jw,double *w,FormulaSlot f,double *dr,double *power,int slot){
    (void)jw;CFormulaVM *v=cf_vm();if(!v||atomic_load(&cf_error))return (Vec){NAN,NAN,NAN};if(slot<0)slot=cf_slot_index(f);v->kind=f.kind;
    const RustFormula *meta=v->metadata[slot];if(!meta)return z;if(!v->modifiers[slot])*power=v->powers[slot];
    if(meta->builtin<20)return cf_builtin_step(z,j,f,meta,v->values[slot]);
    if(!v->functions[slot])return cf_source_step(z,j,f,v->values[slot]);
    double pd,pt;if(v->procedural[slot]&&cf_procedural(z,v->procedural[slot],v->values[slot],&pd,&pt)){cf_wd(v,CF_REC+112,pd);cf_wd(v,CF_REC+272,pt);v->slot=slot;return z;}
    if(!cf_reference_execution&&v->compact[slot]){if(v->retained_de){cf_wd(v,CF_REC+112,dot(z,z)+(v->slot_four_d[slot]?*w**w:0));cf_wd(v,CF_REC+288,*dr);}double fourth=!v->four_d&&(meta->de==2||meta->de==11)?*dr:*w;Vec next=cf_pure_dispatch(v->compact[slot],z,&fourth,v->variables[slot],CF_VAR(slot)+256);if(meta->de==2||meta->de==11)*dr=fabs(fourth);if(v->four_d)*w=fourth;return next;}

    if(!cf_reference_execution&&v->contexts[slot].function&&!(v->contexts[slot].state&16)){
        CN_CompactPlan plan=v->contexts[slot];CN_CompactContext ctx;
        ctx.machine=&v->native;ctx.xyz[0]=z.x;ctx.xyz[1]=z.y;ctx.xyz[2]=z.z;if(plan.reads&(UINT64_C(1)<<10))ctx.constant[0]=j->x;if(plan.reads&(UINT64_C(1)<<11))ctx.constant[1]=j->y;if(plan.reads&(UINT64_C(1)<<12))ctx.constant[2]=j->z;ctx.fourth=!v->four_d&&(meta->de==2||meta->de==11)?*dr:*w;ctx.regs=(CN_U8){0};
        v->native.cw=0x37f;
        if(plan.state&1)memset(v->native.xmm,0,sizeof v->native.xmm);
        if(plan.state&2)v->native.fl=(CN_Flags){0};
        if(plan.state&4)v->native.fsw_cc=0;
        if(plan.state&8)v->native.steps=0;
        if(plan.reads&(UINT64_C(1)<<14))ctx.radius=meta->de<20?dot(z,z)+(v->slot_four_d[slot]?*w**w:0):cf_rd(v,CF_REC+112);
        if(plan.reads&(UINT64_C(1)<<32))ctx.scale=meta->de>=20?*dr:cf_rd(v,CF_REC+256);
        if(plan.reads&(UINT64_C(1)<<36))ctx.derivative=meta->de<20?*dr:cf_rd(v,CF_REC+288);
        /* Unchanged values also provide the return value for formulas that
         * do not read or write these components. */
        if(meta->de==5||meta->de==6)ctx.derivative=*dr;
        if(meta->de>=20)ctx.scale=*dr;
        /* Keep the native record coherent for mixed escape-time/dIFS calls,
         * including formulas that read another formula's retained DE state. */
        if(meta->de<20){cf_wd(v,CF_REC+288,*dr);cf_wd(v,CF_REC+112,dot(z,z)+(v->slot_four_d[slot]?*w**w:0));}else cf_wd(v,CF_REC+256,*dr);
        cf_wi(v,CF_REC+104,CF_VAR(slot)+256);cf_wi(v,CF_REC+216,(uint32_t)meta->de);
        if(meta->de>=20){ctx.regs[6]=CF_REC+144;ctx.regs[7]=CF_VAR(slot)+256;ctx.regs[3]=slot;ctx.regs[1]=v->count;ctx.regs[2]=CF_REC+272;ctx.regs[4]=CF_TOP-4;cf_wi(v,CF_TOP-4,CF_RETURN);}
        else{ctx.regs[0]=CF_REC+24;ctx.regs[2]=CF_REC+32;ctx.regs[1]=CF_REC+40;ctx.regs[4]=CF_TOP-12;cf_wi(v,CF_TOP-12,CF_RETURN);cf_wi(v,CF_TOP-8,CF_REC+56);cf_wi(v,CF_TOP-4,CF_REC+48);}
        int failed=plan.function(&ctx,v->mem+0x2000+slot*1024+plan.parameter_offset,CF_VAR(slot)+256);
        if(failed){cf_fail(f.kind,"prepared C formula execution failed");return (Vec){NAN,NAN,NAN};}
        if(plan.writes&(UINT64_C(1)<<10))j->x=ctx.constant[0];if(plan.writes&(UINT64_C(1)<<11))j->y=ctx.constant[1];if(plan.writes&(UINT64_C(1)<<12))j->z=ctx.constant[2];
        if(meta->de==2||meta->de==11)*dr=fabs(ctx.fourth);else if(meta->de==5||meta->de==6)*dr=fabs(ctx.derivative);
        if(v->four_d)*w=ctx.fourth;
        if(meta->de>=20){*dr=ctx.scale;v->count=ctx.regs[ECX];v->slot=ctx.regs[EBX];}
        return (Vec){ctx.xyz[0],ctx.xyz[1],ctx.xyz[2]};
    }
    cf_wd(v,CF_REC+24,z.x);cf_wd(v,CF_REC+32,z.y);cf_wd(v,CF_REC+40,z.z);cf_wd(v,CF_REC+48,!v->four_d&&(meta->de==2||meta->de==11)?*dr:*w);cf_wd(v,CF_REC+80,j->x);cf_wd(v,CF_REC+88,j->y);cf_wd(v,CF_REC+96,j->z);cf_wi(v,CF_REC+104,CF_VAR(slot)+256);if(meta->de<20)cf_wd(v,CF_REC+288,*dr);cf_wi(v,CF_REC+216,(uint32_t)meta->de);
    if(meta->de<20)cf_wd(v,CF_REC+112,dot(z,z)+(v->slot_four_d[slot]?*w**w:0));else cf_wd(v,CF_REC+256,*dr);
    CN_U8 regs={0};memset(v->native.xmm,0,sizeof v->native.xmm);v->native.fl=(CN_Flags){0};v->native.fsw_cc=0;v->native.cw=0x37f;v->native.steps=0;
    if(meta->de>=20){regs[6]=CF_REC+144;regs[7]=CF_VAR(slot)+256;regs[3]=slot;regs[1]=v->count;regs[2]=CF_REC+272;regs[4]=CF_TOP-4;cf_wi(v,CF_TOP-4,CF_RETURN);}
    else{regs[0]=CF_REC+24;regs[2]=CF_REC+32;regs[1]=CF_REC+40;regs[4]=CF_TOP-12;cf_wi(v,CF_TOP-12,CF_RETURN);cf_wi(v,CF_TOP-8,CF_REC+56);cf_wi(v,CF_TOP-4,CF_REC+48);}
    if(!v->functions[slot]){cf_fail(f.kind,"missing native C formula");return (Vec){NAN,NAN,NAN};}
    v->native.regs=regs;int failed=v->functions[slot](&v->native,&regs,CF_VAR(slot)+256);if(failed){cf_fail(f.kind,"native C formula execution failed");return (Vec){NAN,NAN,NAN};}
    z=(Vec){cf_rd(v,CF_REC+24),cf_rd(v,CF_REC+32),cf_rd(v,CF_REC+40)};*j=(Vec){cf_rd(v,CF_REC+80),cf_rd(v,CF_REC+88),cf_rd(v,CF_REC+96)};
    if(meta->de==2||meta->de==11)*dr=fabs(cf_rd(v,CF_REC+48));else if(meta->de==5||meta->de==6)*dr=fabs(cf_rd(v,CF_REC+288));
    if(v->four_d)*w=cf_rd(v,CF_REC+48);
    if(meta->de>=20){*dr=cf_rd(v,CF_REC+256);v->count=regs[ECX];v->slot=regs[EBX];}
    return z;
}
static Vec cf_step(Vec z,Vec *j,double jw,double *w,FormulaSlot f,double *dr,double *power){return cf_step_at(z,j,jw,w,f,dr,power,-1);}



static double cf_de_scale(int kind){const CFormulaCode *c=cf_code_for(kind);const RustFormula *f=rust_formula(kind);return c?c->de_scale:f&&f->builtin==5?.2:1;}
