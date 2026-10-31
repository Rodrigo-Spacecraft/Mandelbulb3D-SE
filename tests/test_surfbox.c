#include "../renderer.c"
#include <assert.h>
int main(void){
 int kind=formula_kind_from_name("SurfBox");assert(kind>=1000&&formula_parameter_count(kind)==9);assert(cn_lookup("SurfBox")&&cn_compact_lookup("SurfBox").function);
 FILE *fp=fopen("tests/surfbox-vectors.tsv","r");assert(fp);int scenario;double expected[5];int checked=0;
 while(fscanf(fp,"%d%lf%lf%lf%lf%lf",&scenario,expected,expected+1,expected+2,expected+3,expected+4)==6){
 scene_defaults();FormulaSlot f=formula_slot_default(kind);f.count=1;if(scenario==2)f.parameters[0]+=.125;
 scene.program=legacy_program();for(int i=0;i<8;i++)scene.program.slots[i].count=0;scene.program.slots[0]=f;scene.program_enabled=1;scene.width=64;scene.height=48;
 Vec p=scenario==1?(Vec){-.713,.827,-1.131}:scenario==3?(Vec){0}:scenario==4?(Vec){2.31,-1.72,.93}:scenario==5?(Vec){.000001,-.000002,.000003}:(Vec){.371,.213,.419},j={.137,-.283,.317};double w=scenario==1?-.317:.193,dr=1,power=2;cf_begin(p,j,.173,20);Vec r=cf_step(p,&j,.173,&w,f,&dr,&power);assert(!atomic_load(&cf_error));double values[]={r.x,r.y,r.z,w,dr};for(int i=0;i<5;i++)assert(fabs(values[i]-expected[i])<1e-10+1e-8*fmax(fabs(values[i]),fabs(expected[i])));checked++;
 }fclose(fp);assert(checked==6);
 RenderOptions o=scene_settings(48,32,2,0);o.program_override=1;char error[512],path[]="/private/tmp/surfbox-test-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);unlink(path);assert(write_scene_parameters(NULL,o,path,error));RenderOptions loaded;assert(read_scene_settings(path,&loaded,error)&&loaded.program.slots[0].kind==kind);unlink(path);
 puts("SurfBox native C matches six original-instruction vectors and round-trips parameters");return 0;
}
