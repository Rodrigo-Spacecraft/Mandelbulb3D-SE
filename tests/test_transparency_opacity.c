#include "../renderer.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static RenderResult render(const char *path,RenderOptions o,double diffuse,double specular){for(int i=0;i<10;i++){o.reflections.opacity[0][i]=diffuse;o.reflections.opacity[1][i]=specular;}RenderResult r=render_scene_with_options(path,o);if(!r.rgba){puts(r.error);exit(1);}return r;}
int main(int argc,char **argv){assert(argc==2);RenderOptions o;char error[512];assert(read_scene_settings(argv[1],&o,error));o.width=o.height=48;o.oversampling=o.viewing=1;o.threads=4;o.reuse_surface=0;o.fog_override=1;o.fog.mode=3;o.reflections_override=1;o.reflections.enabled=o.reflections.transparency=o.reflections.opacity_set=1;o.reflections.amount=1;o.reflections.depth=2;o.reflections.only_difs=0;o.shadows_override=1;o.shadows.ambient_auto=o.shadows.hard_auto=0;o.object_override=1;for(int i=0;i<10;i++)for(int c=0;c<3;c++)o.object.stops[i].specular[c]=.5;
 RenderResult a=render(argv[1],o,0,.5),b=render(argv[1],o,1,.5);for(int y=0;y<a.height;y++)assert(!memcmp(a.rgba+y*a.stride,b.rgba+y*b.stride,a.width*4));
 RenderResult c=render(argv[1],o,1,1);unsigned different=0;for(int y=0;y<a.height;y++)for(int x=0;x<a.width*4;x++)different+=b.rgba[y*b.stride+x]!=c.rgba[y*c.stride+x];assert(different>0);puts("Diffuse opacity leaves transparency unchanged; specular opacity changes it.");free(a.rgba);free(b.rgba);free(c.rgba);return 0;}
