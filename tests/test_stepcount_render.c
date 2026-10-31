#include "../renderer.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
int main(void){RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));o.width=o.height=32;o.threads=2;o.fog_override=1;o.fog.mode=3;o.reflections_override=o.dof_override=1;o.reflections.enabled=o.dof.enabled=0;o.stepcount_override=1;o.stepcount=2;RenderResult a=render_scene_with_options(NULL,o);assert(a.rgba&&a.settings.stepcount==2);o.stepcount=12;RenderResult b=render_scene_with_options(NULL,o);assert(b.rgba&&b.settings.stepcount==12);assert(b.statistics.evaluations[2]>a.statistics.evaluations[2]);o.stepcount=32;RenderResult invalid=render_scene_with_options(NULL,o);assert(!invalid.rgba&&invalid.error[0]);printf("Stepcount changes refinement work (%llu to %llu field queries) and rejects out-of-range values.\n",a.statistics.evaluations[2],b.statistics.evaluations[2]);free(a.rgba);free(b.rgba);return 0;}
