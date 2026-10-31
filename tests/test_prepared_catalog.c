#include "renderer.c"
#include <assert.h>
static int forceContext;
static uint32_t rng=1209814;
static double random_value(double span){rng=rng*1664525u+1013904223u;return ((double)rng/4294967295.-.5)*span;}
static int same(double a,double b){return a==b||(isnan(a)&&isnan(b))||(isfinite(a)&&isfinite(b)&&fabs(a-b)<=1e-12*fmax(1,fmax(fabs(a),fabs(b))));}
typedef struct {Vec z,j;double w,dr,power,record[64];int count,slot;} Snapshot;
static Snapshot run(FormulaSlot f,int slot,Vec z,int reference){
 cf_reference_execution=reference;Vec j={.13,-.27,.31};double w=.19,dr=1.37,power=2;
 cf_begin(z,j,.23,60);CFormulaVM *vm=cf_vm();unsigned previousState=vm->contexts[slot].state;if(forceContext)vm->contexts[slot].state&=~16;int previousCompact=vm->compact[slot];if(forceContext)vm->compact[slot]=0;
 for(int step=0;step<4;step++){
  cf_wi(vm,CF_REC+120,step);cf_wd(vm,CF_REC+8,dot(z,z));double scale=NAN;
  z=slot_step_prepared(z,&j,.23,&w,f,&dr,&power,&scale,slot);
  if(!isfinite(z.x)||!isfinite(z.y)||!isfinite(z.z)||fabs(z.x)+fabs(z.y)+fabs(z.z)>1e6)break;
 }
 vm->compact[slot]=previousCompact;vm->contexts[slot].state=previousState;Snapshot result={.z=z,.j=j,.w=w,.dr=dr,.power=power,.count=vm->count,.slot=vm->slot};memcpy(result.record,vm->mem+0x1000,512);return result;
}
int main(void){int checked=0,prepared=0,native=0;
 for(forceContext=0;forceContext<2;forceContext++)for(size_t k=0;k<RUST_FORMULA_COUNT;k++){
  const RustFormula *meta=&rust_formulas[k];FormulaSlot f=formula_slot_default(meta->kind);f.count=1;
  if(meta->builtin<20)continue;
  CN_CompactPlan plan=cn_compact_lookup(meta->name);if(!forceContext){if(plan.function)prepared++;else native++;}
  for(int edit=0;edit<4;edit++){
   scene_defaults();if(edit){int p=(edit-1)%(int)fmax(1,formula_parameter_count(f.kind));if(formula_parameter_count(f.kind)){const FormulaParameter *option=formula_parameter(f.kind,p);formula_slot_set_value(&f,p,formula_slot_value(f,p)+(option->integer?1:.125));}}
   if(edit==3)for(int p=0;p<formula_parameter_count(f.kind);p++){const FormulaParameter *option=formula_parameter(f.kind,p);formula_slot_set_value(&f,p,formula_slot_value(f,p)+(option->integer?1:random_value(.25)));}
   scene.program=legacy_program();for(int s=0;s<8;s++)scene.program.slots[s].count=0;int slot=(k+edit)%8;scene.program.slots[slot]=f;scene.program_enabled=1;
   for(int point=0;point<12;point++){
    Vec z=point==0?(Vec){0,0,0}:point==1?(Vec){1e-6,-1e-6,2e-6}:(Vec){random_value(4),random_value(4),random_value(4)};
    scene.program.slots[(slot+1)%8]=formula_slot_default(2);scene.program.slots[(slot+1)%8].count=point%2;
    Snapshot a=run(f,slot,z,0),b=run(f,slot,z,1);
    double actual[]={a.z.x,a.z.y,a.z.z,a.j.x,a.j.y,a.j.z,a.w,a.dr,a.power,a.record[14],a.record[32],a.record[34],a.record[36]},expected[]={b.z.x,b.z.y,b.z.z,b.j.x,b.j.y,b.j.z,b.w,b.dr,b.power,b.record[14],b.record[32],b.record[34],b.record[36]};
    for(int n=0;n<(forceContext||!cf_pure_index(meta->name)||meta->de>=20?13:9);n++)if(!same(actual[n],expected[n])){fprintf(stderr,"%s edit %d point %d component %d: %.17g != %.17g\n",meta->name,edit,point,n,actual[n],expected[n]);abort();}
    if(a.count!=b.count||a.slot!=b.slot){fprintf(stderr,"%s changed schedule\n",meta->name);abort();}checked++;
   }
  }
 }
 cf_reference_execution=0;assert(prepared>400);printf("%d prepared formulas, %d full-native formulas; %d multi-step comparisons passed (XYZ, Julia, 4D, DE, traps and schedule).\n",prepared,native,checked);
}
