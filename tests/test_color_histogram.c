#include "../renderer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int main(void){RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));o.width=o.height=32;o.threads=2;o.fog_override=1;o.fog.mode=3;o.reflections_override=o.dof_override=1;o.reflections.enabled=o.dof.enabled=0;RenderResult r=render_scene_with_options(NULL,o);assert(r.rgba);unsigned total[3]={0};for(int c=0;c<3;c++)for(int i=0;i<256;i++)total[c]+=r.color_histogram[c][i];assert(total[0]+total[2]>0&&total[0]+total[2]<=1024&&total[1]>0&&total[1]<=1024);printf("Histogram totals: %u outside, %u orbit, %u inside; background excluded.\n",total[0],total[1],total[2]);free(r.rgba);return 0;}
