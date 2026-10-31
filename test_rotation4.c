#include <assert.h>
#include "renderer.c"
typedef struct {int kind,julia;double input[3],angles[3],output[4];} Rotation4Vector;
#include "test_rotation4_vectors.h"
int main(void){
 for(size_t i=0;i<sizeof rotation4_vectors/sizeof *rotation4_vectors;i++){
    const Rotation4Vector *t=rotation4_vectors+i;scene_defaults();memcpy(scene.rotation4,t->angles,sizeof scene.rotation4);scene.julia=t->julia;scene.julia_c=(Vec){.17,-.09,.13};scene.julia_w=-.07;scene.iterations=4;prepare_rotation4();
    FormulaProgram p=legacy_program();p.slots[0]=formula_slot_default(t->kind);p.slots[0].count=1;p.bailout=1e10;
    for(int mode=0;mode<2;mode++){p.mode=mode;
    OrbitResult o=program_orbit((Vec){t->input[0],t->input[1],t->input[2]},p,0,7,0,4,0);
    double expected=sqrt(t->output[0]*t->output[0]+t->output[1]*t->output[1]+t->output[2]*t->output[2]+t->output[3]*t->output[3]);
    double values[]={o.z.x,o.z.y,o.z.z,o.radius},targets[]={t->output[0],t->output[1],t->output[2],expected};
    for(int k=0;k<4;k++){if(fabs(values[k]-targets[k])>2e-10*(1+fabs(targets[k])))fprintf(stderr,"Rotation vector %zu formula %d Julia %d channel %d %.17g != %.17g\n",i,t->kind,t->julia,k,values[k],targets[k]);assert(fabs(values[k]-targets[k])<=2e-10*(1+fabs(targets[k])));}
    }
 }
 RenderResult base=render_scene_with_options(NULL,(RenderOptions){.width=48,.height=36,.threads=2,.program_override=1,.program={0}});assert(!base.rgba); /* invalid programs still rejected */
 scene_defaults();FormulaProgram p=legacy_program();p.slots[0]=formula_slot_default(130);p.slots[0].count=1;
 RenderOptions options={.width=48,.height=36,.iterations=12,.threads=2,.program_override=1,.program=p,.rotation4_override=1};
 base=render_scene_with_options(NULL,options);assert(base.rgba);options=base.settings;options.reuse_surface=1;
 RenderResult zero=render_scene_with_options(NULL,options);assert(zero.rgba&&zero.reused_surface&&!memcmp(base.rgba,zero.rgba,base.stride*base.height));free(zero.rgba);
 options.rotation4[0]=.37;options.rotation4[1]=-.61;options.rotation4[2]=.19;options.julia_w=.23;
 RenderResult rotated=render_scene_with_options(NULL,options);assert(rotated.rgba&&!rotated.reused_surface&&memcmp(base.rgba,rotated.rgba,base.stride*base.height));
 RenderResult cached=render_scene_with_options(NULL,options);assert(cached.rgba&&cached.reused_surface&&!memcmp(cached.rgba,rotated.rgba,cached.stride*cached.height));free(cached.rgba);
 char path[]="/tmp/mb3dx-rotation4-XXXXXX",error[512];int fd=mkstemp(path);close(fd);unlink(path);assert(write_scene_parameters(NULL,options,path,error));RenderOptions loaded;assert(read_scene_settings(path,&loaded,error));assert(loaded.rotation4_override&&!memcmp(loaded.rotation4,options.rotation4,sizeof options.rotation4)&&loaded.julia_w==options.julia_w);
 RenderResult native=render_scene(path,0,0,1);assert(native.rgba&&!memcmp(native.rgba,rotated.rgba,native.stride*native.height));free(native.rgba);
 assert(!truncate(path,840+48*36*18+1136));RenderResult standard=render_scene(path,0,0,1);assert(standard.rgba&&!memcmp(standard.rgba,rotated.rgba,standard.stride*standard.height));free(standard.rgba);unlink(path);
 options.rotation4[0]=NAN;RenderResult bad=render_scene_with_options(NULL,options);assert(!bad.rgba&&strstr(bad.error,"4D"));free(base.rgba);free(rotated.rgba);
 puts("600 original 4D orbit cases, nonzero W constants, neutral rotations, cache invalidation/reuse and native/standard persistence passed.");
}
