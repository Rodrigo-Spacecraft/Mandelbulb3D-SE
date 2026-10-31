/* Native formula support. Generated calculations operate on local values;
 * no instruction decoder, emulator, JIT or Rust runtime is used. */
#ifndef CN_RUNTIME_H
#define CN_RUNTIME_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
typedef uint64_t CN_U2 __attribute__((ext_vector_type(2)));
typedef uint32_t CN_U8 __attribute__((ext_vector_type(8)));
typedef double CN_D8 __attribute__((ext_vector_type(8)));
typedef double CN_D3 __attribute__((ext_vector_type(3)));
typedef struct {bool cf,zf,sf,of,pf,af;} CN_Flags;
typedef struct {unsigned char *mem; CN_U2 xmm[8]; CN_U8 regs; CN_Flags fl; CN_D8 st; uint16_t fsw_cc,cw; uint64_t steps;} CN_Machine;
#define CN_REC 0x10001000U
#define EAX 0
#define ECX 1
#define EDX 2
#define EBX 3
#define ESP 4
#define EBP 5
#define ESI 6
#define EDI 7
#define RETURN_SENTINEL 0xfffffff0U
#define Alu_Add 0
#define Alu_Or 1
#define Alu_Adc 2
#define Alu_Sbb 3
#define Alu_And 4
#define Alu_Sub 5
#define Alu_Xor 6
#define Alu_Cmp 7
#define Shift_Shl 0
#define Shift_Shr 1
#define Shift_Sar 2
#define FKind_I32 2
#define FKind_F32 0
#define FKind_F64 1
static inline unsigned char *cn_ptr(CN_Machine *m,uint32_t a){return m->mem+(a&65535);}
static inline double cn_round(CN_Machine *m,double x){switch((m->cw>>10)&3){case 1:return floor(x);case 2:return ceil(x);case 3:return trunc(x);default:return nearbyint(x);}}
static inline double cn_fast_sin(double x){double n=nearbyint(x*0.31830988618379067154),v=x*0.31830988618379067154-n,q=v*v;double y=v*(3.14159265358979323846+q*(-5.167375251323450+q*(2.543310591226590+q*(-0.557168173477934))));return fmod(fabs(n),2)>=1?-y:y;}
static inline double cn_fast_cos(double x){return cn_fast_sin(x+1.57079632679489661923);}
static inline double cn_remainder(double x,double y){return fmod(x,y);}
static inline uint16_t cn_rd16u(CN_Machine *m,uint32_t a){uint16_t v;memcpy(&v,cn_ptr(m,a),2);return v;}
static inline void cn_wr16u(CN_Machine *m,uint32_t a,uint16_t v){memcpy(cn_ptr(m,a),&v,2);}
static inline uint8_t cn_rd8u(CN_Machine *m,uint32_t a){return *cn_ptr(m,a);}
static inline void cn_wr8u(CN_Machine *m,uint32_t a,uint8_t v){*cn_ptr(m,a)=v;}
static inline uint64_t cn_rd64(CN_Machine *m,uint32_t a){uint64_t v;memcpy(&v,cn_ptr(m,a),8);return v;}
static inline void cn_wr64(CN_Machine *m,uint32_t a,uint64_t v){memcpy(cn_ptr(m,a),&v,8);}
static inline uint32_t cn_rd32u(CN_Machine *m,uint32_t a){uint32_t v;memcpy(&v,cn_ptr(m,a),4);return v;}
static inline void cn_wr32u(CN_Machine *m,uint32_t a,uint32_t v){memcpy(cn_ptr(m,a),&v,4);}
#define cn_rd64u cn_rd64
#define cn_wr64u cn_wr64
#define cn_rd32 cn_rd32u
#define cn_wr32 cn_wr32u
static inline double cn_double(uint64_t v){double d;memcpy(&d,&v,8);return d;}
static inline float cn_float(uint32_t v){float d;memcpy(&d,&v,4);return d;}
static inline uint64_t cn_dbits(double d){uint64_t v;memcpy(&v,&d,8);return v;}
static inline uint32_t cn_fbits(float d){uint32_t v;memcpy(&v,&d,4);return v;}
#define cn_bits(d) _Generic((d),float:cn_fbits,default:cn_dbits)(d)
static inline double cn_rdf64u(CN_Machine *m,uint32_t a){return cn_double(cn_rd64(m,a));}
#define cn_rdf64 cn_rdf64u
static inline void cn_wrf64u(CN_Machine *m,uint32_t a,double d){cn_wr64(m,a,cn_dbits(d));}
static inline void cn_fstoreu(CN_Machine *m,int k,uint32_t a,double x){(void)k;double r=cn_round(m,x);int32_t v=!isfinite(r)||r<INT32_MIN||r>INT32_MAX?INT32_MIN:(int32_t)r;cn_wr32u(m,a,(uint32_t)v);}
static inline double cn_floadu(CN_Machine *m,int k,uint32_t a){return k==FKind_I32?(double)(int32_t)cn_rd32u(m,a):k==FKind_F32?cn_float(cn_rd32u(m,a)):cn_rdf64u(m,a);}
static inline uint64_t cn_cell(const unsigned char *p,size_t o){uint64_t v;memcpy(&v,p+o,8);return v;}
static inline void cn_swap_impl(CN_D8 *f,int a,int b){double t=(*f)[a];(*f)[a]=(*f)[b];(*f)[b]=t;}
#define cn_swap(f,a,b) cn_swap_impl(&(f),a,b)
static inline uint32_t cn_mask(uint32_t v,int s){return s==4?v:v&((1U<<(s*8))-1);}
static inline void cn_szp(CN_Flags *f,uint32_t r,int s){f->zf=cn_mask(r,s)==0;f->sf=(r>>(s*8-1))&1;f->pf=!(__builtin_popcount(r&255)&1);}
static inline uint32_t cn_alu(CN_Flags *f,int op,uint32_t a,uint32_t b,int s){uint32_t mask=cn_mask(~0U,s),sign=1U<<(s*8-1),r;a&=mask;b&=mask;uint64_t c=0,full;
 if(op==Alu_Add||op==Alu_Adc){c=op==Alu_Adc&&f->cf;full=(uint64_t)a+b+c;r=full&mask;f->cf=full>mask;f->of=((a^r)&(b^r)&sign)!=0;f->af=((a^b^r)&16)!=0;}
 else if(op==Alu_Sub||op==Alu_Sbb||op==Alu_Cmp){c=op==Alu_Sbb&&f->cf;r=((uint64_t)a-b-c)&mask;f->cf=(uint64_t)b+c>a;f->of=((a^b)&(a^r)&sign)!=0;f->af=((a^b^r)&16)!=0;}
 else{r=op==Alu_And?a&b:op==Alu_Or?a|b:a^b;f->cf=f->of=false;}
 cn_szp(f,r,s);return r;}
static inline bool cn_cond(CN_Flags f,int cc){bool v;switch(cc>>1){case 0:v=f.of;break;case 1:v=f.cf;break;case 2:v=f.zf;break;case 3:v=f.cf||f.zf;break;case 4:v=f.sf;break;case 5:v=f.pf;break;case 6:v=f.sf!=f.of;break;default:v=f.zf||(f.sf!=f.of);}return cc&1?!v:v;}
static inline uint32_t cn_reg_get(CN_U8 r,int i,int s){return s==1?(i<4?r[i]&255:(r[i-4]>>8)&255):s==2?r[i]&65535:r[i];}
static inline void cn_reg_set_impl(CN_U8 *r,int i,int s,uint32_t v){if(s==1&&i>=4){i-=4;(*r)[i]=((*r)[i]&~0xff00)|((v&255)<<8);}else{uint32_t mask=cn_mask(~0U,s);(*r)[i]=((*r)[i]&~mask)|(v&mask);}}
#define cn_reg_set(r,i,s,v) cn_reg_set_impl(&(r),i,s,v)
static inline void cn_shift_impl(CN_U8 *r,CN_Flags *f,int op,int i,uint32_t c,int s){c&=31;if(!c)return;int bits=s*8;uint32_t v=cn_reg_get(*r,i,s),out;if(op==Shift_Shl){f->cf=c<=(unsigned)bits&&((v>>(bits-c))&1);out=cn_mask(v<<c,s);f->of=(((out>>(bits-1))&1)!=f->cf);}else if(op==Shift_Shr){f->cf=(v>>(c-1))&1;f->of=(v>>(bits-1))&1;out=v>>c;}else{int32_t sv=s==1?(int8_t)v:s==2?(int16_t)v:(int32_t)v;f->cf=(sv>>(c-1))&1;f->of=false;out=cn_mask(sv>>c,s);}cn_szp(f,out,s);cn_reg_set_impl(r,i,s,out);}
#define cn_shift_reg_l(r,f,op,i,c,s) cn_shift_impl(&(r),f,op,i,c,s)
static inline uint16_t cn_compare(double a,double b){bool un=isnan(a)||isnan(b);return ((a<b||un)<<8)|((a==b||un)<<14)|(un<<10);}
static inline void cn_push_impl(CN_Machine *m,CN_U8 *r,uint32_t v){(*r)[ESP]-=4;cn_wr32u(m,(*r)[ESP],v);}
static inline uint32_t cn_pop_impl(CN_Machine *m,CN_U8 *r){uint32_t v=cn_rd32u(m,(*r)[ESP]);(*r)[ESP]+=4;return v;}
#define cn_push_lu(m,r,v) cn_push_impl(m,&(r),v)
#define cn_pop_lu(m,r) cn_pop_impl(m,&(r))
CN_D3 cn_map_px(bool spherical,int number,CN_D3 xyz);
int cn_height_host(CN_Machine *m,CN_U8 rg,CN_D8 f);
typedef int (*CN_Function)(CN_Machine *,CN_U8 *,uint32_t);
CN_Function cn_lookup(const char *name);
/* A conservative reset plan from statically addressed generated accesses. */
typedef struct {int full;unsigned low;} CN_ResetInfo;
CN_ResetInfo cn_reset_info(const char *name);
#endif
