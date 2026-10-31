#include "renderer.c"
#include <assert.h>
static void expect(Vec a,Vec b){assert(fabs(a.x-b.x)<1e-12&&fabs(a.y-b.y)<1e-12&&fabs(a.z-b.z)<1e-12);}
int main(void){
 scene_defaults();scene.color_on_trap=1;scene.cstart=0;scene.cspan=32768;scene.col_z=0;scene.cycle=1;scene.no_interpolation=0;
 for(int i=0;i<10;i++)scene.stops[i]=(Stop){i*30000/9,{0,0,1},{1,0,0}};
 scene.stops[0].diffuse=(Vec){1,0,0};scene.stops[0].specular=(Vec){0,1,0};
 Vec d,s;palette(0,31400./4096,0,&d,&s);double t=1400./2767;
 expect(d,(Vec){t,0,1-t});expect(s,(Vec){1-t,t,0});
 scene.reflections.opacity_set=1;scene.reflections.opacity[1][9]=0;scene.reflections.opacity[1][0]=1;assert(fabs(reflection_palette_opacity((Sample){.orbit_trap=31400./4096},0,1)-t)<1e-12);
 palette(0,32766./4096,0,&d,&s);assert(d.x>.999&&s.y>.999);
 scene.cstart=-1;palette(0,32767./4096,0,&d,&s);expect(d,scene.stops[0].diffuse);expect(s,scene.stops[0].specular);
 scene.cstart=0;scene.cycle=0;palette(0,31400./4096,0,&d,&s);expect(d,scene.stops[9].diffuse);expect(s,scene.stops[9].specular);
 scene.cycle=1;scene.no_interpolation=1;palette(0,31400./4096,0,&d,&s);expect(d,scene.stops[9].diffuse);expect(s,scene.stops[9].specular);
 scene.no_interpolation=0;scene.stops[9].position=32767;palette(0,32767./4096,0,&d,&s);expect(d,scene.stops[9].diffuse);expect(s,scene.stops[9].specular);
 puts("Cycling diffuse/specular palettes interpolate across the closing segment; clamp, stepped mode and endpoint behavior pass.");
}
