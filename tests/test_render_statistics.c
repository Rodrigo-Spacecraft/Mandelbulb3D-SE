#include "renderer.h"
#ifdef USE_RUST_ENGINE
#include "rust_engine.h"
#endif
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static unsigned long long sum(const unsigned long long *a){unsigned long long n=0;for(int i=0;i<8;i++)n+=a[i];return n;}
int main(void){
 RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));
 o.width=32;o.height=24;o.threads=1;o.de_stop=.1;o.camera_override=1;
 o.shadows_override=1;o.shadows.hard_enabled=o.shadows.ambient_enabled=0;
 o.dof_override=1;o.dof.enabled=0;o.reflections_override=1;o.reflections.enabled=0;o.fog_override=1;o.fog.strength=53;
 RenderResult a=render_scene_with_options(NULL,o);assert(a.rgba);RenderStatistics x=a.statistics;
 assert(x.valid&&x.threads==1&&x.elapsed>0&&x.rays==32*24&&x.hits>0&&x.hits<=x.rays&&x.steps>0&&x.max_steps>0&&x.steps>=x.max_steps);
 fprintf(stderr,"diagnostics DE %llu formulas %llu primary %llu normals %llu refine %llu\n",sum(x.evaluations),sum(x.formula_calls),x.evaluations[0],x.evaluations[1],x.evaluations[2]);
 assert(sum(x.evaluations)>0&&sum(x.formula_calls)>0&&x.evaluations[0]>0&&x.evaluations[1]>0);
 o.threads=4;RenderResult b=render_scene_with_options(NULL,o);assert(b.rgba);RenderStatistics y=b.statistics;
 assert(y.valid&&y.threads==4&&y.rays==x.rays&&y.hits==x.hits&&y.steps==x.steps&&y.max_steps==x.max_steps);
 assert(!memcmp(x.evaluations,y.evaluations,sizeof x.evaluations));assert(!memcmp(x.formula_calls,y.formula_calls,sizeof x.formula_calls));assert(!memcmp(a.rgba,b.rgba,a.stride*a.height));
 o.reuse_surface=1;RenderResult c=render_scene_with_options(NULL,o);assert(c.rgba&&c.reused_surface&&c.statistics.valid&&c.statistics.rays==0&&c.statistics.steps==0&&c.statistics.evaluations[0]==0);assert(!memcmp(b.rgba,c.rgba,b.stride*b.height));
 o.reuse_surface=0;RenderResult d=render_scene_with_options(NULL,o);assert(d.rgba&&d.statistics.rays==x.rays&&sum(d.statistics.formula_calls)==sum(x.formula_calls));
 o.shadows.hard_enabled=1;o.shadows.hard_mask=1;o.shadows.hard_auto=1;o.shadows.ambient_enabled=1;o.shadows.ambient_auto=1;o.shadows.ambient_method=1;o.shadows.ambient_rays=3;o.shadows.ambient_steps=16;
 o.fog.strength=59;
 RenderResult e=render_scene_with_options(NULL,o);assert(e.rgba&&e.statistics.evaluations[3]>0&&e.statistics.evaluations[4]>0);
#ifndef USE_RUST_ENGINE
 assert(e.statistics.evaluations[5]>0);
#endif
 free(e.rgba);
 printf("DE=%llu formulas=%llu rays=%llu steps=%llu max=%llu hits=%llu; one/four threads identical; cached update and reset verified.\n",sum(x.evaluations),sum(x.formula_calls),x.rays,x.steps,x.max_steps,x.hits);
#ifdef USE_RUST_ENGINE
 /* CPU-only requests are applied per render, not only at first startup;
    mode changes must invalidate geometry even with reuse requested. */
 const char *environment=getenv("MB3DX_GPU");char *saved=environment?strdup(environment):NULL;unsetenv("MB3DX_GPU");
 o.shadows.hard_enabled=o.shadows.ambient_enabled=0;o.fog.strength=53;o.reuse_surface=1;
 mb3dx_rust_set_cpu_only(1);RenderResult cpu=render_scene_with_options(NULL,o);assert(cpu.rgba&&!cpu.statistics.gpu);free(cpu.rgba);
 mb3dx_rust_set_cpu_only(0);RenderResult automatic=render_scene_with_options(NULL,o);assert(automatic.rgba&&!automatic.reused_surface);free(automatic.rgba);
 mb3dx_rust_set_cpu_only(1);cpu=render_scene_with_options(NULL,o);assert(cpu.rgba&&!cpu.reused_surface&&!cpu.statistics.gpu&&cpu.statistics.rays==768);free(cpu.rgba);
 cpu=render_scene_with_options(NULL,o);assert(cpu.rgba&&cpu.reused_surface);free(cpu.rgba);mb3dx_rust_set_cpu_only(0);
 if(saved){setenv("MB3DX_GPU",saved,1);free(saved);}else unsetenv("MB3DX_GPU");
 puts("CPU-only switching applies on subsequent renders and invalidates caches across backend choices.");
#endif
 free(a.rgba);free(b.rgba);free(c.rgba);free(d.rgba);
}
