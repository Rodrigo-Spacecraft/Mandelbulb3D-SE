#include "../renderer.c"
#include <assert.h>
int main(void){
 FormulaSlot f=formula_slot_default(6);f.count=1;f.power=99;f.z_multiplier=-999;f.fold=999;
 assert(validate_imported_slot(&f,0));assert(f.power==8&&f.z_multiplier==-100&&f.fold==100);
 f.power=-9;assert(validate_imported_slot(&f,0));assert(f.power==2);
 int checked=0;for(int m=0;m<formula_menu_count();m++){
 int kind=formula_menu_kind(m);for(int j=0;j<formula_parameter_count(kind);j++){
 const FormulaParameter *p=formula_parameter(kind,j);assert(clamp_imported_parameter(p->minimum-1,p)==p->minimum);assert(clamp_imported_parameter(p->maximum+1,p)==p->maximum);checked++;
 }}
 f=formula_slot_default(106);f.parameters[1]=NAN;assert(!validate_imported_slot(&f,0));
 printf("%d formula parameter limits verified; Folding Int Pow clamps both ends; NaN rejected.\n",checked);
 return 0;
}
