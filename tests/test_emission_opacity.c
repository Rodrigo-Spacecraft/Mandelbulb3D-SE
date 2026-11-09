#include "../renderer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char **argv){
 assert(argc==2);RenderOptions o;char error[512];assert(read_scene_settings(argv[1],&o,error));
 o.width=64;o.height=48;o.oversampling=1;o.viewing=1;o.threads=4;o.reuse_surface=0;
 o.fog_override=1;o.fog.mode=2;o.fog.colors[0][0]=1;o.fog.colors[0][1]=o.fog.colors[0][2]=0;
 o.reflections_override=1;o.reflections.enabled=0;o.reflections.opacity_set=1;
 o.shadows_override=1;o.shadows.ambient_auto=o.shadows.hard_auto=0;
 unsigned char *middle=NULL;size_t bytes=0;unsigned long sums[3];for(int k=0;k<3;k++){
  for(int i=0;i<10;i++){o.reflections.opacity[0][i]=k*.5;o.reflections.opacity[1][i]=1;}
  RenderResult r=render_scene_with_options(argv[1],o);if(!r.rgba){fprintf(stderr,"%s\n",r.error);return 1;}
  sums[k]=0;for(int y=0;y<r.height;y++)for(int x=0;x<r.width;x++)sums[k]+=r.rgba[y*r.stride+x*4];if(k==1){bytes=r.stride*r.height;middle=malloc(bytes);assert(middle);memcpy(middle,r.rgba,bytes);}free(r.rgba);
 }
 printf("Red totals at opacity 0, .5, 1: %lu %lu %lu\n",sums[0],sums[1],sums[2]);assert(sums[0]<sums[1]&&sums[1]<sums[2]);for(int i=0;i<10;i++){o.reflections.opacity[0][i]=.5;o.reflections.opacity[1][i]=0;}
 RenderResult independent=render_scene_with_options(argv[1],o);assert(independent.rgba);assert(!memcmp(middle,independent.rgba,bytes));free(middle);free(independent.rgba);puts("Specular opacity does not change emissive lighting.");return 0;
}
