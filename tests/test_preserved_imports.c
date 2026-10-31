#include "renderer.h"
#include "rust_engine.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
static void put32(unsigned char *p,unsigned v){memcpy(p,&v,4);}
static void real64(unsigned char *p,double v){memcpy(p,&v,8);}
static void header(const char *path,unsigned char h[840]){FILE *f=fopen(path,"rb");assert(f&&fread(h,1,840,f)==840);fclose(f);}
int main(void){
char err[512];const char *path="/tmp/mb3dr-preserved.m3i",*saved="/tmp/mb3dr-preserved-save.m3i";unlink(path);unlink(saved);
assert(write_scene_parameters(NULL,(RenderOptions){.width=32,.height=24,.iterations=8},path,err));unsigned char h[840],out[840];header(path,h);unsigned char *l=h+432;
h[16]|=5;h[132]=0;h[134]=7;h[149]|=128|32|2;h[188]=2;h[19]=3;h[126]=1;h[176]=1;real64(h+346,.15);h[344]=0;h[345]=1;
l[7]|=1|8|32;memcpy(l+384,"missing-background.jpg",23);l[50]=19;l[51]=32;l[67]=7;l[68+4*32+16]=61;
unsigned tb;memcpy(&tb,l+44,4);put32(l+44,tb|0x8000|13|(88<<7));
for(int i=0;i<24;i++)l[360+i]=(unsigned char)(i+1);
unsigned char *q=l+68+5*32;q[0]=2;q[7]=19;q[8]=1;q[9]=12;q[17]=34;q[25]=56;
int fd=open(path,O_WRONLY);assert(fd>=0&&pwrite(fd,h,840,0)==840);assert(!ftruncate(fd,840+32*24*18+1136));close(fd);
RenderOptions o;assert(read_scene_settings(path,&o,err));assert(o.preserved_header_valid&&o.lights[5].option==2);o.width=48;o.iterations=9;assert(write_scene_parameters(NULL,o,saved,err));header(saved,out);
assert((out[16]&5)==5&&out[132]==0&&out[134]==7&&out[188]==2&&(out[149]&(128|32|2))==(128|32|2));
assert(out[19]==3&&out[126]==1&&out[176]==1&&out[344]==0&&out[345]==1&&!memcmp(out+346,h+346,24));
unsigned char *ol=out+432;assert(ol[7]==l[7]&&!memcmp(ol+384,l+384,24)&&!memcmp(ol+360,l+360,24));assert(ol[50]==19&&ol[51]==32&&ol[67]==7&&ol[68+4*32+16]==61);unsigned otb;memcpy(&otb,ol+44,4);assert((otb&0xbfff)==((tb|0x8000|13|(88<<7))&0xbfff));
unsigned char *oq=ol+68+5*32;assert(oq[0]==2&&!memcmp(oq+7,q+7,2));for(int i=0;i<3;i++)assert(!memcmp(oq+9+i*8,q+9+i*8,7));
RenderOptions reloaded;assert(read_scene_settings(saved,&reloaded,err)&&reloaded.width==48&&reloaded.iterations==9&&reloaded.lights[5].option==2);assert(!truncate(saved,840+48*24*18+1136));assert(read_scene_settings(saved,&reloaded,err));
#ifdef USE_RUST_ENGINE
/* The handoff must retain these fields too, rather than force 3D or strip maps. */
setenv("MB3DX_HANDOFF_DUMP","/tmp/mb3dr-preserved-handoff.m3p",1);render_set_rust_assets("rust-assets/M3Formulas");reloaded.threads=2;RenderResult r=render_scene_with_options(NULL,reloaded);if(!r.rgba)fprintf(stderr,"%s\n",r.error);assert(r.rgba);free(r.rgba);header("/tmp/mb3dr-preserved-handoff.m3p",out);assert(out[126]==1&&out[176]==1&&out[344]==0&&out[345]==1&&out[432+68+5*32]==2&&out[432+7]==l[7]);
#else
RenderResult r=render_scene_with_options(NULL,reloaded);assert(r.rgba);free(r.rgba);
#endif
unlink(path);unlink(saved);unlink("/tmp/mb3dr-preserved-handoff.m3p");puts("Uneditable lighting, light maps, stereo, cuts and slices survive edits, standard/native saves and rendering handoff.");}
