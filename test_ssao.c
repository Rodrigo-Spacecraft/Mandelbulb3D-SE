#include <assert.h>
#include "renderer.c"
int main(void){
 scene_defaults();scene.width=41;scene.height=31;scene.shadows.ambient_method=2;scene.ssao=(SSAOSettings){.threshold=2,.samples=1};size_t count=41*31;
 surface_cache.pixels=calloc(count,sizeof(SurfacePixel));assert(surface_cache.pixels);
 for(size_t i=0;i<count;i++)surface_cache.pixels[i]=(SurfacePixel){.hit=1,.depth=1};
 assert(calculate_ssao(2));for(size_t i=0;i<count;i++)assert(surface_cache.pixels[i].ambient_visibility==1);
 for(int y=0;y<31;y++)for(int x=22;x<41;x++)surface_cache.pixels[y*41+x].depth=.4;
 assert(calculate_ssao(1));double reference[1271];for(size_t i=0;i<count;i++)reference[i]=surface_cache.pixels[i].ambient_visibility;
 assert(reference[15*41+18]<.9&&reference[15*41+28]>.9);
 assert(calculate_ssao(4));for(size_t i=0;i<count;i++)assert(reference[i]==surface_cache.pixels[i].ambient_visibility);
 scene.shadows.ambient_method=3;scene.ssao.samples=2;assert(calculate_ssao(1));for(size_t i=0;i<count;i++)reference[i]=surface_cache.pixels[i].ambient_visibility;
 assert(calculate_ssao(4));for(size_t i=0;i<count;i++)assert(reference[i]==surface_cache.pixels[i].ambient_visibility);
 free(surface_cache.pixels);memset(&surface_cache,0,sizeof surface_cache);
 RenderResult r=render_scene(NULL,41,31,2);assert(r.rgba);RenderOptions options=r.settings;free(r.rgba);options.reuse_surface=1;options.shadows.ambient_method=3;options.ssao=(SSAOSettings){.threshold=2.25,.mirror=.16,.samples=2};
 r=render_scene_with_options(NULL,options);assert(r.rgba&&r.reused_surface&&!r.reused_ambient);free(r.rgba);
 options.shadows.ambient_strength=1.2;r=render_scene_with_options(NULL,options);assert(r.rgba&&r.reused_surface&&r.reused_ambient);free(r.rgba);
 options.ssao.threshold=2.5;r=render_scene_with_options(NULL,options);assert(r.rgba&&r.reused_surface&&!r.reused_ambient);free(r.rgba);
 char path[]="/tmp/ssao-roundtrip-XXXXXX",error[512];int fd=mkstemp(path);close(fd);unlink(path);options.color_option=1;options.color_multiplier=1.123456789;options.object.map.number=4005;options.object.map.mode=2;
 assert(write_scene_parameters(NULL,options,path,error));unsigned char header[840];FILE *saved=fopen(path,"rb");assert(saved&&fread(header,1,840,saved)==840);fclose(saved);assert((header[432+68+32+24]&3)==2&&header[432+68+32+8]==0);RenderOptions loaded;assert(read_scene_settings(path,&loaded,error));assert(loaded.ssao_override&&loaded.shadows.ambient_method==3&&loaded.ssao.threshold==2.5&&loaded.ssao.mirror==.16&&loaded.ssao.samples==2&&loaded.color_option==1&&loaded.color_multiplier==options.color_multiplier);
 assert(!truncate(path,840+(off_t)41*31*18+1136));assert(read_scene_settings(path,&loaded,error));assert(loaded.shadows.ambient_method==3&&loaded.ssao.threshold==2.5&&loaded.ssao.mirror==.16&&loaded.ssao.samples==2&&loaded.color_option==1&&loaded.object.map.mode==2&&loaded.object.map.number==4005);unlink(path);
 scene_defaults();scene.color_option=1;scene.color_multiplier=2;FormulaProgram p=legacy_program();p.slots[0].power=2;p.slots[0].z_multiplier=1;p.bailout=1e10;
 Vec c={.7,.3,.2},z=c;double old=0;for(int i=0;i<3;i++){old=dot(z,z);z=add(integer_formula(z,2,1),c);}
 OrbitResult orbit=program_orbit(c,p,0,7,0,3,0);double expected=clamp(log(dot(z,z)/(old+1))*1024,0,32767);
 assert(fabs(orbit.sample.orbit_trap*4096-expected)<1e-9);
 puts("SSAO plane/occluder behavior, thread determinism, random passes, cache reuse/invalidation, native/standard settings and last-length-increase coloring passed.");
}
