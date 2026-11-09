#include "../renderer.c"
#include <assert.h>
int main(int argc,char **argv){assert(argc==2);RenderOptions o;char error[512];assert(read_scene_settings(argv[1],&o,error));
 o.reflections_override=1;
 o.width=96;o.height=72;o.oversampling=o.viewing=1;o.threads=4;o.reuse_surface=0;
 o.shadows_override=1;o.shadows.ambient_auto=o.shadows.hard_auto=0;
 RenderResult r=render_scene_with_options(argv[1],o);if(!r.rgba){fprintf(stderr,"%s\n",r.error);return 1;}
 unsigned receivers=0;for(int i=0;i<r.width*r.height;i++){SurfacePixel *p=&surface_cache.pixels[i];if(p->hit&&p->emission_source&&p->emission_irradiance>0&&reflection_palette_opacity(p->sample,p->depth,0)<1)receivers++;}
 printf("Palette-masked DIFS receivers lit: %u\n",receivers);assert(receivers>0);free(r.rgba);return 0;}
