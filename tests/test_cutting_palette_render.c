#include "../renderer.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(void){RenderOptions o;char e[512];assert(read_scene_settings("example.m3i",&o,e));o.width=o.height=48;o.threads=2;o.cutting_override=1;o.cutting_mask=4;o.cutting[2]=0;o.cutting_colors_override=1;o.cutting_colors.palette_start=0;o.cutting_colors.palette_end=127;o.fog_override=1;o.fog.mode=3;o.reflections_override=o.dof_override=1;o.reflections.enabled=o.dof.enabled=0;for(int i=0;i<4;i++){o.cutting_colors.stops[i].position=i*10922;for(int k=0;k<3;k++)o.cutting_colors.stops[i].diffuse[k]=k==0;}RenderResult a=render_scene_with_options(NULL,o);assert(a.rgba);for(int i=0;i<4;i++)for(int k=0;k<3;k++)o.cutting_colors.stops[i].diffuse[k]=k==1;o.reuse_surface=1;RenderResult b=render_scene_with_options(NULL,o);assert(b.reused_surface&&b.statistics.rays==0&&b.statistics.evaluations[0]==0);assert(b.rgba&&memcmp(a.rgba,b.rgba,a.stride*a.height));puts("Cut palette changes rendered colors.");free(a.rgba);free(b.rgba);}
