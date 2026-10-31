#include "../renderer.c"
#include <assert.h>
int main(void){scene_defaults();scene.fog.mode=2;scene.fog.colors[0][0]=1;scene.fog.colors[0][1]=scene.fog.colors[0][2]=0;scene.program_enabled=1;scene.program=legacy_program();scene.program.mode=2;scene.program.split=1;scene.program.repeat2=1;scene.program.max_iterations2=1;scene.program.slots[1]=formula_slot_default(115);FormulaSlot *box=&scene.program.slots[1];box->count=1;box->parameters[0]=box->parameters[1]=box->parameters[2]=.3;box->parameters[3]=1;box->parameters[6]=2;box->parameters[9]=0;double e=.0001;
 double direct=emission_ray((Vec){-1.5,0,0},(Vec){-1,0,0},e),blocked=emission_ray((Vec){2,0,0},(Vec){-1,0,0},e);fprintf(stderr,"direct %.3f blocked %.3f\n",direct,blocked);assert(direct==4&&blocked==0);
 double near=emission_red_irradiance((Vec){-1.5,0,0},(Vec){-1,0,0},e),far=emission_red_irradiance((Vec){-5,0,0},(Vec){1,0,0},e);fprintf(stderr,"near %.3f far %.3f\n",near,far);assert(near>far&&near>0);
 assert(near==emission_red_irradiance((Vec){-1.5,0,0},(Vec){-1,0,0},e));assert(emission_red_irradiance((Vec){-1.5,0,0},(Vec){1,0,0},e)==0);
 SurfacePixel hit;int opaque;assert(reflection_hit((Vec){-1.5,0,0},(Vec){1,0,0},0,e,&hit,&opaque));assert(!reflection_surface_difs(hit.point));
 scene.ambient=scene.depth=0;scene.ao_enabled=0;for(int i=0;i<6;i++)scene.lights[i].option|=1;for(int i=0;i<10;i++)scene.stops[i].diffuse=(Vec){1,1,1};
 hit.normal=(Vec){-1,0,0};hit.sample=surface_color_sample(hit.point,e);hit.prepared=1;hit.ambient_visibility=1;Vec lit=shade(hit.point,hit.ray,.5,hit.depth,e,1,64,64,NULL,NULL,&hit);fprintf(stderr,"receiver RGB %.3f %.3f %.3f\n",lit.x,lit.y,lit.z);assert(lit.x>0&&lit.y==0&&lit.z==0);
 scene.fog.colors[0][0]=0;scene.fog.colors[0][2]=1;Vec blue=shade(hit.point,hit.ray,.5,hit.depth,e,1,64,64,NULL,NULL,&hit);assert(blue.z>0&&blue.x==0&&blue.y==0);
 for(int mode=0;mode<2;mode++){scene.fog.mode=mode;assert(emission_red_irradiance((Vec){-1.5,0,0},(Vec){-1,0,0},e)==0);}scene.fog.mode=2;
 scene.program.slots[1].count=0;assert(emission_red_irradiance((Vec){-1.5,0,0},(Vec){-1,0,0},e)==0);
 puts("DIFS light reaches receivers, is blocked by escape-time geometry, falls with emitter solid angle and is deterministic.");return 0;}
