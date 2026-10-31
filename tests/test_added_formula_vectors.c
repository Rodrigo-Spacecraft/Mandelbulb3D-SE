#include "renderer.c"
#include <assert.h>
static int equal_value(double a,double b){return (isnan(a)&&isnan(b))||a==b||(isfinite(a)&&isfinite(b)&&fabs(a-b)<=1e-10+1e-8*fmax(fabs(a),fabs(b)));}
static void check_reset_plan(FormulaSlot f,Vec point){
 CFormulaVM *vm=cf_vm();int full=vm->full_reset;
 for(int repeat=0;repeat<3;repeat++){
  Vec input=add(point,(Vec){repeat*.017,-repeat*.013,repeat*.011}),j={.137,-.283,.317};double w=.193,dr=1,power=2;
  /* Old stack bytes must not leak into a subsequent orbit. Only a
     conservatively proven read-only option buffer may avoid restoration. */
  memset(vm->mem+0x4000,0xa5,0x3f00);vm->full_reset=full;cf_begin(input,j,.173,20);Vec a=cf_step(input,&j,.173,&w,f,&dr,&power);
  double fast[]={a.x,a.y,a.z,w,dr,cf_rd(vm,CF_REC+112),cf_rd(vm,CF_REC+272),j.x,j.y,j.z};
  j=(Vec){.137,-.283,.317};w=.193;dr=1;power=2;vm->full_reset=1;cf_begin(input,j,.173,20);a=cf_step(input,&j,.173,&w,f,&dr,&power);
  double slow[]={a.x,a.y,a.z,w,dr,cf_rd(vm,CF_REC+112),cf_rd(vm,CF_REC+272),j.x,j.y,j.z};
  for(int k=0;k<10;k++)if(!equal_value(fast[k],slow[k])){fprintf(stderr,"Reset plan %s repeat %d component %d\n",formula_name(f.kind),repeat,k);abort();}
 }vm->full_reset=full;
}
int main(void){FILE *fp=fopen("tests/added-formula-oracle.tsv","r");assert(fp);char line[4096];int tested=0;
while(fgets(line,sizeof line,fp)){if(line[0]=='#')continue;int scenario,kind,de;unsigned long long expectedHash;double expected[7];assert(sscanf(line,"%d\t%d\t%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%llx",&scenario,&kind,&de,expected,expected+1,expected+2,expected+3,expected+4,expected+5,expected+6,&expectedHash)==11);
scene_defaults();FormulaSlot f=formula_slot_default(kind);f.count=1;if(scenario==2&&formula_parameter_count(kind)){const FormulaParameter *p=formula_parameter(kind,0);formula_slot_set_value(&f,0,formula_slot_value(f,0)+(p->integer?1:.125));}if(expectedHash){unsigned char buffer[1024];cf_var_buffer(f,cf_code_for(kind),buffer);uint64_t hash=14695981039346656037ull;for(int i=0;i<1024;i++){hash^=buffer[i];hash*=1099511628211ull;}assert(hash==expectedHash);}
scene.program=legacy_program();for(int i=0;i<8;i++)scene.program.slots[i].count=0;scene.program.slots[0]=f;scene.program_enabled=1;scene.width=64;scene.height=48;atomic_store(&cf_error,0);Vec p=scenario==1?(Vec){-.713,.827,-1.131}:scenario==3?(Vec){0,0,0}:scenario==4?(Vec){2.31,-1.72,.93}:scenario==5?(Vec){.000001,-.000002,.000003}:(Vec){.371,.213,.419},j={.137,-.283,.317};double w=scenario==1?-.317:.193,dr=1,power=2;cf_begin(p,j,.173,20);Vec result=cf_step(p,&j,.173,&w,f,&dr,&power);CFormulaVM *vm=cf_vm();double actual[]={result.x,result.y,result.z,w,dr,cf_rd(vm,CF_REC+112),cf_rd(vm,CF_REC+272)};assert(!atomic_load(&cf_error));check_reset_plan(f,p);/* Preserve the C Bulbox zero-radius guard; the Rust reference returns NaN at this singularity. */ if(scenario==3&&!strcmp(formula_name(kind),"Bulbox")){assert(equal_value(result.x,j.x)&&equal_value(result.y,j.y)&&equal_value(result.z,j.z));tested++;continue;}for(int i=0;i<(de>=20?7:5);i++)if(!equal_value(actual[i],expected[i])){fprintf(stderr,"%s scenario %d component %d: %.17g expected %.17g\n",formula_name(kind),scenario,i,actual[i],expected[i]);abort();}tested++;
}fclose(fp);assert(tested==240);puts("All 40 added formulas match 240 Rust reference vectors in C, including edited parameters, negative/zero/tiny/large coordinates, 4D state, DE and color trap (C Bulbox origin guard retained).");}
