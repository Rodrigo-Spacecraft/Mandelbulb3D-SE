#include "../renderer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static unsigned long long work(RenderResult r){unsigned long long n=0;for(int i=0;i<8;i++)n+=r.statistics.evaluations[i];return n;}
int main(void){RenderOptions o;char error[512];assert(read_scene_settings("tests/emission-sphere-first.m3p",&o,error));o.de_stop*=64.0/o.width;o.width=o.height=64;o.camera_override=1;o.threads=2;o.reflections_override=o.dof_override=1;o.reflections.enabled=o.dof.enabled=0;
 RenderResult first=render_scene_with_options(NULL,o);assert(first.rgba);
 o.object_override=o.ambient_override=o.fog_override=1;o.ambient.strength=.25;
 for(int i=0;i<10;i++){o.object.stops[i].diffuse[0]=.3;o.object.stops[i].diffuse[1]=.5;o.object.stops[i].diffuse[2]=.7;}
 o.fog.colors[0][0]=.05;o.fog.colors[0][1]=.1;o.fog.colors[0][2]=.6;o.reuse_surface=1;
 RenderResult cached=render_scene_with_options(NULL,o);assert(cached.rgba&&cached.reused_surface);assert(memcmp(first.rgba,cached.rgba,cached.stride*cached.height));
 o.reuse_surface=0;RenderResult fresh=render_scene_with_options(NULL,o);assert(fresh.rgba&&!memcmp(fresh.rgba,cached.rgba,cached.stride*cached.height));
 printf("Cached repaint: %.4fs, %llu evaluations; fresh: %.4fs, %llu evaluations\n",cached.statistics.elapsed,work(cached),fresh.statistics.elapsed,work(fresh));assert(work(cached)*4<work(fresh));
 o.reuse_surface=1;o.camera.origin[0]+=.02;RenderResult moved=render_scene_with_options(NULL,o);assert(moved.rgba&&!moved.reused_surface&&work(moved)>work(cached)*4);
 o.reuse_surface=0;RenderResult movedFresh=render_scene_with_options(NULL,o);assert(movedFresh.rgba&&!memcmp(moved.rgba,movedFresh.rgba,moved.stride*moved.height));
 free(first.rgba);free(cached.rgba);free(fresh.rgba);free(moved.rgba);free(movedFresh.rgba);puts("Color, ambient and emitter-color repaints reuse transport exactly; camera movement invalidates it.");return 0;}
