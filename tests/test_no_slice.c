#include "renderer.h"
#include "rust_engine.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void){RenderOptions o;char error[512];const char *fixture="tests/perf-test3-parameters.m3p";assert(read_scene_settings(fixture,&o,error));assert(o.preserved_header_valid&&!o.preserved_header[344]&&!o.preserved_header[345]);o.de_stop*=96./o.width;o.width=96;o.height=54;o.threads=2;render_set_rust_assets("rust-assets/M3Formulas");setenv("MB3DX_HANDOFF_DUMP","/tmp/no-slice-test.m3p",1);
RenderResult implicit=render_scene_with_options(fixture,o);if(!implicit.rgba)fprintf(stderr,"%s\n",implicit.error);assert(implicit.rgba);unsigned char h[840];FILE *f=fopen("/tmp/no-slice-test.m3p","rb");assert(f&&fread(h,1,840,f)==840);fclose(f);assert(h[344]==1&&h[345]==2);assert(!implicit.settings.preserved_header[344]&&!implicit.settings.preserved_header[345]);
o.preserved_header[344]=1;o.preserved_header[345]=2;RenderResult explicit3d=render_scene_with_options(fixture,o);assert(explicit3d.rgba&&!memcmp(implicit.rgba,explicit3d.rgba,implicit.stride*implicit.height));free(implicit.rgba);free(explicit3d.rgba);
o.preserved_header[344]=0;o.preserved_header[345]=1;RenderResult slice=render_scene_with_options(fixture,o);assert(slice.rgba);free(slice.rgba);f=fopen("/tmp/no-slice-test.m3p","rb");assert(f&&fread(h,1,840,f)==840);fclose(f);assert(h[344]==0&&h[345]==1);unlink("/tmp/no-slice-test.m3p");puts("PerfTest3 zero/zero flags render identically to explicit 3D; real slices remain preserved.");}
