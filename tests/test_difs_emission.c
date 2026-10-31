#include "../renderer.c"
#include <assert.h>
static Vec dark_shade(Vec point){SurfacePixel s={.point=point,.ray={0,0,1},.normal={0,0,-1},.hit=1,.prepared=1,.sample={.smooth=1},.ambient_visibility=1};return shade(point,s.ray,.5,1,.0001,1,64,64,NULL,NULL,&s);}
int main(void){scene_defaults();scene.fog.mode=2;scene.fog.colors[0][0]=1;scene.fog.colors[0][1]=scene.fog.colors[0][2]=0;scene.width=scene.height=64;scene.ambient=scene.depth=0;scene.ao_enabled=0;for(int i=0;i<6;i++)scene.lights[i].option|=1;
 scene.program_enabled=1;scene.program=legacy_program();scene.program.mode=2;scene.program.split=1;scene.program.repeat2=1;scene.program.max_iterations2=1;scene.program.slots[1]=formula_slot_default(115);FormulaSlot *box=&scene.program.slots[1];box->count=1;box->parameters[0]=box->parameters[1]=box->parameters[2]=.3;box->parameters[3]=1;box->parameters[6]=2;box->parameters[9]=0;
 Vec difs={-2.30001,0,0},escape={0,0,1.00001};assert(reflection_surface_difs(difs)&&!reflection_surface_difs(escape));Vec red=dark_shade(difs),dark=dark_shade(escape);
#ifndef USE_RUST_ENGINE
 assert(red.x>.99&&red.y==0&&red.z==0);reflection_secondary=1;Vec reflected=dark_shade(difs);assert(reflected.x>.99&&reflected.y==0&&reflected.z==0);
#else
 assert(red.x==0&&red.y==0&&red.z==0);
#endif

#ifndef USE_RUST_ENGINE
 scene.fog.colors[0][0]=.3;scene.fog.colors[0][1]=.5;scene.fog.colors[0][2]=.8;
 for(int i=0;i<2;i++){scene.preserved_header_valid=i;scene.preserved_header[439]=1;Vec color=dark_shade(difs);assert(fabs(color.x-.3)<1e-12&&fabs(color.y-.5)<1e-12&&fabs(color.z-.8)<1e-12);}
#endif
 assert(dark.x==0&&dark.y==0&&dark.z==0);puts("DIFS C-only red emission is visible without lights, including secondary rays; escape surfaces outside the emitter hemisphere remain dark.");return 0;}
