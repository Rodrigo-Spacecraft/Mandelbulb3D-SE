#include "../renderer.c"
#include <assert.h>
int main(void){surface_cache.hard_valid=1;scene.shadows.hard_mask=1;scene.lights[0].option=64;surface_cache.hard_scene=scene;scene.lights[0].position.x+=10;assert(hard_cache_matches());scene.lights[0].option=0;assert(!hard_cache_matches());surface_cache.hard_scene=scene;scene.lights[0].position.x+=1;assert(!hard_cache_matches());puts("Ignored-light cache reuse and re-enable invalidation passed.");}
