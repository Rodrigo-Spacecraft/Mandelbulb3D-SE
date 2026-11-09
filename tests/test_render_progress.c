/* Validate the shared polling contract, including per-stage restarts and
 * unknown-length passes. Includes the engine to exercise its ABI callback. */
#include "../renderer.c"
#include <assert.h>
int main(int argc,char **argv){
 RenderCancelToken *t=render_cancel_create();assert(t);active_cancel=t;
 assert(render_progress_percent(t)==-1);
 const char *names[]={"Geometry","Radiance","HShadows","Reflections","DOF","AShadows"};
 for(int i=0;i<6;i++){
  rust_progress(t,-i-1,0);assert(!strcmp(render_progress_stage(t),names[i]));assert(render_progress_percent(t)==-1);
  rust_progress(t,25,100);assert(render_progress_percent(t)==25);
  rust_progress(t,100,100);assert(render_progress_percent(t)==100);
 }
 render_stage(0,10);assert(render_progress_percent(t)==0);
 render_cancel(t);assert(rust_cancel(t));active_cancel=NULL;render_cancel_destroy(t);
 render_set_rust_assets("rust-assets/M3Formulas");
 RenderOptions options;char error[512];assert(read_scene_settings(argc>1?argv[1]:"example.m3i",&options,error));
 options.width=64;options.height=48;options.threads=2;options.reuse_surface=0;
 RenderResult baseline=render_scene_with_options(NULL,options);assert(baseline.rgba);
 t=render_cancel_create();options.cancel_token=t;
 RenderResult tracked=render_scene_with_options(NULL,options);assert(tracked.rgba);
 assert(!memcmp(baseline.rgba,tracked.rgba,baseline.stride*baseline.height));
 assert(render_progress_percent(t)>=-1&&render_progress_percent(t)<=100);
 free(baseline.rgba);free(tracked.rgba);render_cancel_destroy(t);
 puts("PASS: stage labels, percentages, unknown progress, restart, cancellation");
}
