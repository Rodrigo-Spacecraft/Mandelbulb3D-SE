#include "../renderer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int main(void){RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));o.width=o.height=32;o.threads=2;o.fog_override=1;o.fog.mode=3;o.reflections_override=o.dof_override=1;o.reflections.enabled=o.dof.enabled=0;o.cutting_override=1;o.cutting_mask=0;RenderResult a=render_scene_with_options(NULL,o);assert(a.rgba&&a.statistics.hits>0);o.cutting_mask=4;o.cutting[2]=100;RenderResult b=render_scene_with_options(NULL,o);if(!b.rgba){puts(b.error);return 1;}printf("Cutting: %llu to %llu hits\n",a.statistics.hits,b.statistics.hits);assert(b.statistics.hits==0);free(a.rgba);free(b.rgba);return 0;}
