/* Both mode must stop at the first boundary from either starting side. */
#include "renderer.c"
#include <assert.h>
static RenderOptions sphere_options(void){
 RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));o.width=32;o.height=24;o.threads=2;o.iterations=12;
 o.program_override=1;o.program.mode=0;o.program.repeat_from=0;o.program.min_iterations=1;for(int i=0;i<8;i++)o.program.slots[i].count=0;
 FormulaSlot f=formula_slot_default(125);f.count=1;f.parameters[0]=1;f.parameters[1]=1;f.parameters[2]=f.parameters[3]=f.parameters[4]=0;f.parameters[8]=0;o.program.slots[0]=f;
 o.camera_override=1;o.camera=(CameraSettings){.origin={0,0,-3},.axes={1,0,0,0,1,0,0,0,1},.zoom=1,.fov=40,.distance=6};
 o.shadows_override=o.reflections_override=o.dof_override=o.fog_override=1;o.shadows.hard_enabled=o.shadows.ambient_enabled=o.reflections.enabled=o.dof.enabled=0;o.fog=fog_settings_default();return o;
}
int main(void){
 RenderOptions o=sphere_options();RenderResult outside=render_scene_with_options(NULL,o);assert(outside.rgba);int center=12*32+16;assert(surface_cache.pixels[center].hit);double front=surface_cache.pixels[center].depth;assert(front>1.8&&front<2.2);
 o.program.render_mode=2;RenderResult both=render_scene_with_options(NULL,o);assert(both.rgba);assert(surface_cache.pixels[center].hit&&surface_cache.pixels[center].depth==front);assert(!memcmp(outside.rgba,both.rgba,outside.stride*outside.height));
 free(outside.rgba);free(both.rgba);
 o.camera.origin[2]=0;o.camera.distance=3;o.program.render_mode=1;RenderResult inside=render_scene_with_options(NULL,o);assert(inside.rgba);double back=surface_cache.pixels[center].depth;assert(surface_cache.pixels[center].hit&&back>.8&&back<1.2);
 o.program.render_mode=2;both=render_scene_with_options(NULL,o);assert(both.rgba);assert(surface_cache.pixels[center].hit&&surface_cache.pixels[center].depth==back);free(inside.rgba);free(both.rgba);
 /* A stationary board's first strict minimum wins, including its color. */
 scene_defaults();scene.width=64;scene.height=48;scene.program=legacy_program();for(int i=0;i<8;i++)scene.program.slots[i].count=0;FormulaSlot f=formula_slot_default(114);f.count=1;f.parameters[6]=0;formula_slot_set_value(&f,13,.37);scene.program.slots[0]=f;scene.program_enabled=1;
 for(int v=0;v<5;v++){scene.program.slots[0].parameters[10]=v;for(int n=0;n<8;n++){Vec point={.21+n*.03,.31+n*.01,.1-n*.04},z=point;double scale=1,best=1e100,trap=0;int winner=0;
  for(int i=0;i<60;i++){Vec next;double color=trap,d=difs_formula(z,scene.program.slots[0],&next,&scale,&color,i)/fabs(scale);if(d<best){best=d;trap=color;winner=i+1;}z=next;}
  OrbitResult fast=difs_part(point,scene.program,0,0,0,60);assert(fast.sample.distance==best&&fast.sample.orbit_trap==trap&&fast.iterations==winner);}}
 puts("Both mode hits the front from outside and exits from inside; stationary board orbit preserves distance and color minima.");
}
