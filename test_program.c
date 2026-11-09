/* Six-slot schedules, modes, native persistence and invalid program checks. */
#include "renderer.c"
#include <assert.h>
static int changed(RenderResult a,RenderResult b){assert(a.rgba&&b.rgba);return memcmp(a.rgba,b.rgba,a.stride*a.height)!=0;}
int main(void){
    scene_defaults();FormulaProgram p=legacy_program();p.slots[0].power=2;p.bailout=1e10;
    for(int i=0;i<6;i++){p.slots[i]=formula_slot_default(0);p.slots[i].count=1;p.slots[i].power=2;p.slots[i].z_multiplier=-.2-i*.07;}
    /* Explicit schedule: initial 0..5, then repeat slots 3..5. */
    int schedule[]={0,1,2,3,4,5,3,4,5,3,4,5,3,4};p.repeat_from=3;
    Vec c={.02,.03,.01},expected=c;double dr=1,power;
    for(int i=0;i<14;i++)expected=slot_step(expected,c,p.slots[schedule[i]],&dr,&power);
    OrbitResult orbit=program_orbit(c,p,0,5,3,14,1);
    assert(fabs(orbit.z.x-expected.x)<1e-14&&fabs(orbit.z.y-expected.y)<1e-14&&fabs(orbit.z.z-expected.z)<1e-14);
    RenderOptions options={.width=31,.height=17,.threads=2,.iterations=20,.program_override=1,.program=p};options.program.bailout=16;
    RenderResult all=render_scene_with_options(NULL,options);assert(all.rgba);
    for(int i=0;i<6;i++){
        RenderOptions one=options;for(int j=0;j<8;j++)one.program.slots[j].count=0;one.program.slots[i].count=1;one.program.repeat_from=i;
        char path[]="/tmp/integer-power-six-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);
        RenderResult saved=render_scene_to_m3i(NULL,one,path);assert(saved.rgba);
        RenderResult loaded=render_scene(path,0,0,1);if(!loaded.rgba)fprintf(stderr,"slot %d: %s\n",i,loaded.error);assert(loaded.rgba);
        assert(loaded.settings.program.repeat_from==i&&loaded.settings.program.slots[i].count==1);
        assert(!memcmp(saved.rgba,loaded.rgba,saved.stride*saved.height));unlink(path);free(saved.rgba);free(loaded.rgba);
    }
    RenderOptions modes=options;modes.program.repeat_from=0;modes.program.slots[1].power=3;
    RenderResult alt=render_scene_with_options(NULL,modes);assert(alt.rgba);
    modes.program.mode=1;RenderResult interpolated=render_scene_with_options(NULL,modes);assert(changed(alt,interpolated));
    modes.program.mode=2;modes.program.split=1;modes.program.repeat2=1;modes.program.max_iterations2=20;
    for(int combine=0;combine<5;combine++){
        modes.program.combine=combine;char path[]="/tmp/integer-power-combine-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);
        RenderResult combined=render_scene_to_m3i(NULL,modes,path);assert(combined.rgba);
        RenderResult reopened=render_scene(path,0,0,1);assert(reopened.rgba);assert(reopened.settings.program.mode==2&&reopened.settings.program.combine==combine&&reopened.settings.program.slots[5].count==1);assert(!memcmp(combined.rgba,reopened.rgba,combined.stride*combined.height));
        free(combined.rgba);free(reopened.rgba);unlink(path);
    }
    modes.program.mode=0;modes.program.numerical_de=1;RenderResult numeric=render_scene_with_options(NULL,modes);assert(numeric.rgba);free(numeric.rgba);
    for(int side=1;side<3;side++){modes.program.numerical_de=0;modes.program.render_mode=side;RenderResult inside=render_scene_with_options(NULL,modes);assert(inside.rgba);free(inside.rgba);}
    modes.program.slots[7].count=-1;RenderResult invalid=render_scene_with_options(NULL,modes);assert(!invalid.rgba&&invalid.error[0]);
    free(all.rgba);free(alt.rgba);free(interpolated.rgba);
    puts("Six-slot repeat schedule, each slot including 5/6 save/reload, interpolation, DE combinations, numerical DE and render sides passed.");
}
