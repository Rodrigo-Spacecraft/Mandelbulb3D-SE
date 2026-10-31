#include "../renderer.c"
#include <assert.h>
int main(void){
    scene_defaults();map_width=map_height=8;map_pixels=calloc(8*8,4);
    for(int y=0;y<8;y++)for(int x=0;x<8;x++){unsigned char *p=map_pixels+(y*8+x)*4;p[0]=x*30;p[1]=y*30;p[2]=(x+y)*15;p[3]=255;}
    scene.iterations=48;scene.map.mode=0;scene.map.combine=0;scene.map.offset_x=.125;scene.map.offset_y=.25;
    Sample sample={.smooth=17.5,.orbit_trap=2.125};double scales[]={1,.23137744865585788,2.3};
    for(int i=0;i<3;i++)for(int angle=0;angle<=90;angle+=90){
        scene.map.scale=scales[i];scene.map.rotation=angle;
        double c=cos(angle*PI/180),s=sin(angle*PI/180),u=sample.orbit_trap*4096/32767.-.5,v=(32767-sample.smooth*32767/49)/32767.-.5;
        Vec expected=map_sample((c*u+s*v+1.125)*scales[i],(c*v-s*u+1.25)*scales[i]);
        Vec actual=object_map_color((Vec){0},(Vec){0},sample,(Vec){0});
        assert(fabs(actual.x-expected.x)<1e-12&&fabs(actual.y-expected.y)<1e-12&&fabs(actual.z-expected.z)<1e-12);
    }
    free(map_pixels);puts("Diffuse map pre-scale offsets passed at unit, reduced and enlarged scales");return 0;
}
