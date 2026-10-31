#include <assert.h>
#include <stdatomic.h>
#include "renderer.h"
static atomic_ulong evaluations;
static RenderCancelToken *cancel_during_fog;
static void fog_test_count(const char *name){if(name[0]=='e'){unsigned long n=atomic_fetch_add(&evaluations,1);if(cancel_during_fog&&n>50)render_cancel(cancel_during_fog);}}
#define RENDER_COUNT(name) fog_test_count(#name)
#include "renderer.c"
static void compare(RenderResult a,RenderResult b){assert(a.rgba&&b.rgba);assert(a.stride==b.stride&&a.height==b.height);assert(!memcmp(a.rgba,b.rgba,a.stride*a.height));}
int main(void){
    /* Subtractive fog must see HDR lighting, not an already clipped pixel. */
    scene_defaults();scene.ambient=2;scene.diffuse=scene.specular=scene.indirect=scene.depth=0;scene.ao_enabled=0;
    scene.amb_top=scene.amb_bottom=(Vec){1,1,1};for(int i=0;i<6;i++)scene.lights[i].option=1;
    for(int i=0;i<10;i++)scene.stops[i].diffuse=(Vec){1,1,1};
    scene.fog.strength=38;scene.fog.offset=196;scene.fog.far_offset=128;scene.fog.blend=scene.fog.only_add=0;
    scene.fog.colors[0][0]=scene.fog.colors[0][1]=scene.fog.colors[0][2]=1;
    scene.fog.colors[1][0]=scene.fog.colors[1][1]=scene.fog.colors[1][2]=1;
    SurfacePixel hdr={.hit=1,.prepared=1,.normal={0,0,-1},.ray={0,0,1},.depth=1,.eps=.01,.ambient_visibility=1};
    float integral=0;FogCache fixture={.integral=&integral,.valid=1};fog_cache=&fixture;surface_cache.pixels=&hdr;fog_in_shading=1;
    Vec hdrActual=shade((Vec){0},hdr.ray,.5,1,.01,1,48,36,NULL,NULL,&hdr);
    Vec clipped=gamma_color(fog_mix((Vec){1,1,1},0,1));
    assert(hdrActual.x==1&&hdrActual.y==1&&hdrActual.z==1&&clipped.x<.99);
    fog_cache=NULL;surface_cache.pixels=NULL;fog_in_shading=0;

    RenderResult base=render_scene(NULL,48,36,2);assert(base.rgba);RenderOptions o=base.settings;o.reuse_surface=1;
    RenderResult neutral=render_scene_with_options(NULL,o);compare(base,neutral);free(neutral.rgba);
    o.fog.mode=1;o.fog.strength=120;o.fog.blend=1;o.fog.only_add=1;
    RenderResult fog=render_scene_with_options(NULL,o);assert(fog.rgba&&fog.reused_surface);assert(memcmp(base.rgba,fog.rgba,fog.stride*fog.height));
    assert(fog_cache->valid&&fog_cache->map&&fog_cache->integral);unsigned long builds=fog_cache->builds,integrations=fog_cache->integrations;
    atomic_store(&evaluations,0);o.fog.colors[0][0]=.2;o.fog.strength=90;RenderResult edit=render_scene_with_options(NULL,o);assert(edit.rgba&&edit.reused_surface);assert(fog_cache->builds==builds&&fog_cache->integrations==integrations&&!atomic_load(&evaluations));free(edit.rgba);
    RenderOptions freshOptions=o;freshOptions.reuse_surface=0;RenderResult fresh=render_scene_with_options(NULL,freshOptions);RenderResult cached=render_scene_with_options(NULL,o);compare(fresh,cached);free(fresh.rgba);free(cached.rgba);
    o.fog.light=6;o.lights[5]=o.lights[0];o.lights[5].position[0]+=.5;edit=render_scene_with_options(NULL,o);assert(edit.rgba&&fog_cache->builds==builds+1);free(edit.rgba);
    o.lights[5].option=4;o.lights[5].position[0]=0;o.lights[5].position[1]=0;o.lights[5].position[2]=-2;edit=render_scene_with_options(NULL,o);assert(edit.rgba&&fog_cache->positional&&fog_cache->size>=3);free(edit.rgba);
    /* Synthetic cube-map occluder: distances on either side of a hit. */
    for(size_t i=0;i<(size_t)6*fog_cache->size*fog_cache->size;i++)fog_cache->map[i]=1;
    assert(fog_visible(add(fog_cache->origin,(Vec){.5,0,0})));assert(!fog_visible(add(fog_cache->origin,(Vec){2,0,0})));
    o.fog.map_size=2;RenderCancelToken *cancel=render_cancel_create();o.cancel_token=cancel;cancel_during_fog=cancel;atomic_store(&evaluations,0);edit=render_scene_with_options(NULL,o);assert(edit.cancelled&&!edit.rgba&&!fog_cache->valid);cancel_during_fog=NULL;o.cancel_token=NULL;render_cancel_destroy(cancel);
    o.fog.map_size=1;o.fog.iterations=3;o.fog.offset=117.5;o.fog.far_offset=99.25;o.fog.colors[1][2]=.123;
    char path[]="/tmp/mb3dx-fog-XXXXXX",error[512];int fd=mkstemp(path);close(fd);unlink(path);assert(write_scene_parameters(NULL,o,path,error));RenderOptions loaded;assert(read_scene_settings(path,&loaded,error));assert(!memcmp(&o.fog,&loaded.fog,sizeof o.fog));
    /* Standard header also contains these parameters, without the native trailer. */
    FILE *file=fopen(path,"r+b");assert(file);assert(!ftruncate(fileno(file),840+(off_t)o.width*o.height*18+1136));fclose(file);
    assert(read_scene_settings(path,&loaded,error));assert(loaded.fog.mode==1&&loaded.fog.light==6&&loaded.fog.map_size==1&&loaded.fog.iterations==3&&loaded.fog.blend==1);unlink(path);
    o.fog.mode=0;o.fog.iterations=0;edit=render_scene_with_options(NULL,o);assert(edit.rgba);free(edit.rgba);
    o.fog.strength=53;edit=render_scene_with_options(NULL,o);assert(edit.rgba);RenderOptions plain=o;plain.fog_override=0;RenderResult reference=render_scene_with_options(NULL,plain);compare(reference,edit);free(reference.rgba);free(edit.rgba);free(base.rgba);free(fog.rgba);
    scene_defaults();scene.fog.mode=1;scene.fog.strength=54;scene.lights[0].amplitude=1;fog_cache=&fog_caches[0];fog_cache->positional=0;
    Vec saturated=fog_mix((Vec){0},1e20,0);assert(fabs(saturated.x-16256*.00002)<1e-6);
    uint32_t rowSeed=0x24563487u+8u*0x324594A1u;
    for(unsigned x=0;x<32;x++){rowSeed=rowSeed*214013u+2531011u;assert(fabs(fog_pixel_phase(x,7)-(rowSeed&0x7fffffffu)*(1./2147483647.))<1e-12);}
    scene_defaults();scene.vary=0;scene.width=scene.height=10000;fog_cache->mode=0;fog_cache->iteration=0;fog_cache->pixel=.01;
    Vec origin={3,2,2},ray={0,0,1};assert(fog_dynamic_de_scale()==2);scene.kind=4;assert(fog_dynamic_de_scale()==1);scene.kind=0;
    scene.program_enabled=1;scene.program=(FormulaProgram){0};scene.program.slots[0]=formula_slot_default(0);scene.program.slots[0].count=1;assert(fog_dynamic_de_scale()==2);scene.program.numerical_de=1;assert(fog_dynamic_de_scale()==1);scene.program.numerical_de=0;scene.program.slots[1]=formula_slot_default(4);scene.program.slots[1].count=1;assert(fog_dynamic_de_scale()==1);scene.program_enabled=0;
    double actual=fmax(.0011,evaluate(origin).distance*2*scene.ray_step),limit=.005*10000*.5*sqrt(scene.ray_step+.001);
    assert(actual<limit);double ordinary=fog_integrate(origin,ray,actual*.5);assert(fabs(ordinary-.5)<1e-12);
    scene.width=scene.height=16;limit=.005*16*.5*sqrt(scene.ray_step+.001);assert(actual>limit);
    double limited=fog_integrate(origin,ray,limit*.5);assert(fabs(limited-.5*limit/actual)<1e-12);
    scene.fog.mode=0;scene.fog.strength=59;Vec white=fog_mix((Vec){.2,.3,.4},30,0);assert(white.x>.2&&white.y>.3&&white.z>.4);
    puts("Dynamic fog counts ordinary steps fully and limited steps proportionally; white fog adds white light above the original offset.");
    puts("Depth fog: neutral identity, directional/cube maps, occlusion lookup, reuse, light selection, native and standard persistence passed.");
}
