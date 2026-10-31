#include "../renderer.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void){RenderOptions o;char err[512];assert(read_scene_settings("example.m3i",&o,err));o.width=48;o.height=36;o.camera_override=1;o.camera=(CameraSettings){.axes={1,0,0,0,1,0,0,0,1},.origin={0,0,-3},.zoom=.7,.fov=30,.distance=10};o.threads=2;o.de_stop=.3;o.iterations=8;o.program_override=1;o.program.mode=0;o.program.repeat_from=0;o.program.min_iterations=1;o.program.numerical_de=0;for(int i=0;i<8;i++)o.program.slots[i]=formula_slot_default(0);o.program.slots[0]=formula_slot_default(115);o.program.slots[0].count=1;for(int i=0;i<3;i++)o.program.slots[0].parameters[i]=.6;o.program.slots[0].parameters[3]=1;o.program.slots[0].parameters[6]=0;o.shadows_override=o.dof_override=o.reflections_override=1;o.shadows.hard_enabled=o.shadows.ambient_enabled=o.dof.enabled=o.reflections.enabled=0;o.ambient_override=1;o.ambient.strength=o.ambient.depth=0;memset(o.ambient.colors,0,sizeof o.ambient.colors);o.lights_override=1;for(int i=0;i<6;i++)o.lights[i].option|=1;o.fog_override=1;o.fog.mode=0;o.fog.strength=53;
 RenderResult dark=render_scene_with_options(NULL,o);if(!dark.rgba)fprintf(stderr,"%s\n",dark.error);assert(dark.rgba);
 o.fog.mode=2;o.fog.colors[0][0]=0;o.fog.colors[0][1]=0;o.fog.colors[0][2]=1;o.reuse_surface=1;RenderResult blue=render_scene_with_options(NULL,o);if(!blue.rgba)fprintf(stderr,"%s\n",blue.error);assert(blue.rgba&&memcmp(blue.rgba,dark.rgba,blue.stride*blue.height));int lit=0,halo=0;for(int i=0;i<48*36;i++){if(blue.rgba[i*4+2]>100&&blue.rgba[i*4]<10&&blue.rgba[i*4+1]<10)lit++;if(blue.rgba[i*4+2]>0&&blue.rgba[i*4+2]<200)halo++;}assert(lit>0&&halo>0);
 RenderResult repeat=render_scene_with_options(NULL,o);assert(repeat.rgba&&!memcmp(repeat.rgba,blue.rgba,blue.stride*blue.height));free(repeat.rgba);
 o.fog.colors[0][0]=1;o.fog.colors[0][2]=0;RenderResult red=render_scene_with_options(NULL,o);assert(red.rgba&&memcmp(red.rgba,blue.rgba,blue.stride*blue.height));o.fog.mode=0;RenderResult off=render_scene_with_options(NULL,o);assert(off.rgba&&!memcmp(off.rgba,dark.rgba,dark.stride*dark.height));
 o.program.mode=2;o.program.split=1;o.program.repeat_from=0;o.program.repeat2=1;o.program.max_iterations2=1;o.program.slots[1]=o.program.slots[0];o.program.slots[1].parameters[0]=o.program.slots[1].parameters[1]=o.program.slots[1].parameters[2]=.3;o.program.slots[1].parameters[6]=1.2;o.program.slots[0]=formula_slot_default(0);o.program.slots[0].count=1;o.program.slots[0].power=2;o.iterations=20;o.object_override=1;o.object.diffuse=1;for(int i=0;i<10;i++)for(int c=0;c<3;c++)o.object.stops[i].diffuse[c]=1;o.fog.mode=2;
 RenderResult mixed=render_scene_with_options(NULL,o);if(!mixed.rgba)fprintf(stderr,"mixed: %s\n",mixed.error);assert(mixed.rgba);int receivers=0;for(int y=0;y<36;y++)for(int x=0;x<48;x++){double pos[3];if(!render_pick_surface((x+.5)/48,(y+.5)/36,pos))continue;if(pos[0]>-.3&&mixed.rgba[y*mixed.stride+4*x]>5)receivers++;}fprintf(stderr,"Red escape-time receiving pixels: %d\n",receivers);assert(receivers>0);free(mixed.rgba);
/* A DIFS-first union must leave the escape-time architecture shaded. */
 assert(read_scene_settings("tests/emission-sphere-first.m3p",&o,err));
 o.de_stop*=96.0/o.width;o.width=o.height=96;o.camera_override=1;o.threads=2;
 RenderResult architecture=render_scene_with_options(NULL,o);assert(architecture.rgba);
 int neutral=0,red_pixels=0;
 for(int y=0;y<96;y++)for(int x=0;x<96;x++){unsigned char *v=architecture.rgba+y*architecture.stride+4*x;
 if(v[0]>10&&v[1]>10&&v[2]>10&&v[0]<v[1]*2&&v[0]<v[2]*2)neutral++;
 if(v[0]>60&&v[0]>v[1]*2&&v[0]>v[2]*2)red_pixels++;
 }
 fprintf(stderr,"Mixed scene neutral pixels: %d; red pixels: %d\n",neutral,red_pixels);
 assert(neutral>500&&red_pixels>50&&red_pixels<4000);free(architecture.rgba);
 free(off.rgba);free(red.rgba);free(blue.rgba);free(dark.rgba);puts("Rust emissive mode changes emitter color, adds a glow, is deterministic, and restores the original render when disabled.");return 0;}
