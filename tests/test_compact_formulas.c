#include "renderer.c"
#include <assert.h>
static uint32_t rng=19470821;
static double random_value(double span){rng=rng*1664525u+1013904223u;return ((double)rng/4294967295.-.5)*span;}
static int same(double a,double b){return a==b||(isnan(a)&&isnan(b))||(isfinite(a)&&isfinite(b)&&fabs(a-b)<=1e-12*fmax(1,fmax(fabs(a),fabs(b))));}
int main(void){int checked=0,formulas=0;
 for(size_t k=0;k<RUST_FORMULA_COUNT;k++){const RustFormula *meta=&rust_formulas[k];unsigned index=cf_pure_index(meta->name);if(!index||meta->de>=20)continue;formulas++;for(int edit=0;edit<100;edit++){
  scene_defaults();FormulaSlot f=formula_slot_default(meta->kind);f.count=1;
  for(int p=0;p<formula_parameter_count(f.kind);p++){const FormulaParameter *meta=formula_parameter(f.kind,p);double value=formula_slot_value(f,p);if(edit){value=meta->integer?nearbyint(random_value(4)):value+random_value(8);formula_slot_set_value(&f,p,value);}}
  scene.program=legacy_program();for(int s=0;s<8;s++)scene.program.slots[s].count=0;int slot=edit%8;scene.program.slots[slot]=f;scene.program_enabled=1;scene.program.slots[(slot+1)%8]=formula_slot_default(2);scene.program.slots[(slot+1)%8].count=edit%2;
  for(int point=0;point<200;point++){
   Vec z={random_value(20),random_value(20),random_value(20)},j={.17,-.31,.23},j0=j;double w=.19,dr=1+fabs(random_value(5)),dr0=dr,power=2;
   cf_reference_execution=0;cf_begin(z,j,.1,60);CFormulaVM *vm=cf_vm();int compact=vm->compact[slot];vm->compact[slot]=index;double surfScale=NAN;Vec a=slot_step_prepared(z,&j,.1,&w,f,&dr,&power,&surfScale,slot);
   cf_reference_execution=1;cf_begin(z,j0,.1,60);vm->compact[slot]=0;double w0=.19,power0=2;Vec b=cf_step(z,&j0,.1,&w0,f,&dr0,&power0);vm->compact[slot]=compact;
   assert(same(a.x,b.x)&&same(a.y,b.y)&&same(a.z,b.z)&&same(dr,dr0)&&same(w,w0)&&same(power,power0));assert(same(j.x,j0.x)&&same(j.y,j0.y)&&same(j.z,j0.z));checked++;
  }
 }}
 printf("%d direct C formulas match full native calculations for %d randomized cases, including edited options and mixed 4D/DE state.\n",formulas,checked);
}
