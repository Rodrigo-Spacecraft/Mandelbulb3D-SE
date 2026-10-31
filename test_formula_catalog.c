#include "renderer.h"
#include "rust_engine.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
static int kind_named(const char *name){for(int i=0;i<formula_menu_count();i++){int k=formula_menu_kind(i);if(!strcmp(formula_name(k),name))return k;}assert(!"missing formula");return 0;}
int main(void){
#ifdef USE_RUST_ENGINE
    render_set_rust_assets("rust-assets/M3Formulas");
#endif
    assert(formula_menu_count()==513);
    RenderOptions base;char error[512];assert(read_scene_settings("example.m3i",&base,error));base.width=32;base.height=24;base.iterations=12;base.program.mode=0;base.program.repeat_from=0;base.program.bailout=1024;base.program.min_iterations=1;
    char path[]="/tmp/mandelbulb3dr-catalog-XXXXXX.m3i";int fd=mkstemps(path,4);assert(fd>=0);close(fd);unlink(path);
    for(int i=0;i<formula_menu_count();i++){
        int kind=formula_menu_kind(i);for(int j=0;j<i;j++)assert(strcmp(formula_name(kind),formula_name(formula_menu_kind(j))));
        RenderOptions o=base;for(int j=0;j<8;j++){o.program.slots[j]=formula_slot_default(0);o.program.slots[j].count=0;}o.program.slots[0]=formula_slot_default(kind);o.program.slots[0].count=1;o.program_override=1;
        int count=formula_parameter_count(kind);assert(count>=0&&count<=16);
        for(int j=0;j<count;j++){const FormulaParameter *p=formula_parameter(kind,j);double v=formula_slot_value(o.program.slots[0],j);assert(p&&p->name&&isfinite(v)&&v>=p->minimum&&v<=p->maximum&&(!p->integer||v==floor(v)));}
        if(!write_scene_parameters(NULL,o,path,error)){fprintf(stderr,"%s: %s\n",formula_name(kind),error);abort();}
        /* Remove the private extension: imports must resolve standard IDs,
           names, types and all 16 options without relying on native IDs. */
        assert(!truncate(path,840+32*24*18+1136));RenderOptions loaded;
        if(!read_scene_settings(path,&loaded,error)){fprintf(stderr,"%s: %s\n",formula_name(kind),error);abort();}
        assert(loaded.program.slots[0].kind==kind&&loaded.program.slots[0].count==1);
        for(int j=0;j<count;j++)assert(formula_slot_value(loaded.program.slots[0],j)==formula_slot_value(o.program.slots[0],j));unlink(path);
    }
    /* Exercise new built-ins, compiled custom formulas, a 4D formula and
       a direct-distance shape through the actual Rust rendering bridge. */
    const char *samples[]={"Real Power","Tricorn","Bulbox","Aexion C","Menger3","NewMengerIFS","_ScaleC4d","JosKn-KleinIFS","SurfBox","ApolloTetraIFS","BuddhiRotX3","BuddhiRotX3b","CosAziTwoStage","CrossMenger","EiffieQ","JosKn-ModIFS","K-TowerIFS","LoHexCIFS","LoHexIFS","LoHexTIFS","LoResCIFS","LoResIFS","LoResTIFS","MandelCup","ScherkIFS","Wobblybulb","YPicartP8","_BTwistBraid_V3v2after","_F_AbsFold","_F_BoxFold","_F_MandalayFold","_F_MandalayFold4D","_Simplex3DShift","_T_AbsAddConditional","_T_AbsOffset","_T_AbsOffset4D","_T_Offset","_T_Scale3D","_T_Scale4D","_T_ScaleOffset","_T_Sin_XYZ","_T_SqrtAdd","_T_Wobble","_loresmode","eiffieCarIFS","invcylIFS","loresmodeIFS","murl","teapot"};
    for(unsigned i=0;i<sizeof samples/sizeof *samples;i++){
        RenderOptions o=base;o.width=32;o.height=24;o.threads=2;for(int j=0;j<8;j++){o.program.slots[j]=formula_slot_default(0);o.program.slots[j].count=0;}o.program.slots[0]=formula_slot_default(kind_named(samples[i]));o.program.slots[0].count=1;o.program_override=1;
        if(formula_catalog_category(o.program.slots[0].kind)==4){o.program.slots[1]=formula_slot_default(0);o.program.slots[1].count=1;}
        if(formula_catalog_category(o.program.slots[0].kind)==6){o.program.slots[1]=formula_slot_default(kind_named("SphereIFS"));o.program.slots[1].count=1;}
        RenderResult r=render_scene_with_options(NULL,o);if(!r.rgba){fprintf(stderr,"%s: %s\n",samples[i],r.error);abort();}assert(r.width==32&&r.height==24);free(r.rgba);
    }

    int klein=kind_named("JosKn-KleinIFS");assert(formula_catalog_category(klein)==5&&formula_parameter_count(klein)==15);assert(formula_parameter(klein,6)->integer&&formula_parameter(klein,7)->integer&&formula_parameter(klein,8)->integer);assert(fabs(formula_parameter(klein,0)->default_value-1.775)<1e-12);
    puts("All 513 formula defaults and standard parameter round trips pass; 49 sampled formulas render through the selected engine.");
}
