#include "../renderer.c"
#include <assert.h>
int main(void){scene_defaults();scene.fog.mode=2;scene.fog.colors[0][0]=1;scene.fog.colors[0][1]=scene.fog.colors[0][2]=0;RenderResult r={.width=64,.height=64,.stride=256};r.rgba=calloc(64*64,4);surface_cache.pixels=calloc(64*64,sizeof(SurfacePixel));assert(r.rgba&&surface_cache.pixels);
 for(int y=30;y<34;y++)for(int x=30;x<34;x++){int i=y*64+x;surface_cache.pixels[i].hit=surface_cache.pixels[i].emissive=1;r.rgba[i*4]=255;}
 r.rgba[(32*64+35)*4+1]=50;r.rgba[(32*64+35)*4+3]=255;
 assert(apply_emission_glow(&r));assert(r.rgba[(32*64+35)*4]>0);assert(r.rgba[(32*64+35)*4+1]==50&&r.rgba[(32*64+35)*4+3]==255);assert(r.rgba[(32*64+45)*4]==0);assert(r.rgba[(32*64+32)*4]==255);
 memset(surface_cache.pixels,0,64*64*sizeof(SurfacePixel));unsigned char before[64*64*4];memcpy(before,r.rgba,sizeof before);assert(apply_emission_glow(&r)&&!memcmp(before,r.rgba,sizeof before));free(r.rgba);free(surface_cache.pixels);surface_cache.pixels=NULL;
 puts("Red glow extends beyond emissive silhouettes, preserves other channels, and leaves non-emissive scenes unchanged.");return 0;}
