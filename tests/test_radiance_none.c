#include "../renderer.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void){RenderOptions o;char error[512];assert(read_scene_settings("tests/emission-sphere-first.m3p",&o,error));o.de_stop*=24.0/o.width;o.width=o.height=24;o.camera_override=1;o.threads=2;o.reflections_override=o.dof_override=o.fog_override=1;o.reflections.enabled=o.dof.enabled=0;o.fog.mode=3;o.fog.strength=159;o.fog.offset=0;o.fog.far_offset=256;RenderResult none=render_scene_with_options(NULL,o);assert(none.rgba);o.fog.mode=0;o.fog.strength=53;o.fog.offset=o.fog.far_offset=128;RenderResult neutral=render_scene_with_options(NULL,o);assert(neutral.rgba);assert(!memcmp(none.rgba,neutral.rgba,none.stride*none.height));free(none.rgba);free(neutral.rgba);puts("None ignores nonneutral fog settings and matches a render without Radiance effects.");}
