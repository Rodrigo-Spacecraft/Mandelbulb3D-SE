#include "../renderer.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
static void check_file(const char *path,int w,int h){
 FILE *f=fopen(path,"rb");assert(f);unsigned char e[4096];fseek(f,840+(long)w*h*18+1136,SEEK_SET);assert(fread(e,1,4096,f)==4096);fclose(f);
 assert(!memcmp(e+1880,"FRM6",4));for(int i=1884+6*52;i<1884+8*52;i++)assert(e[i]==0);for(int i=2404+6*104;i<2404+8*104;i++)assert(e[i]==0);for(int i=4024;i<4040;i++)assert(e[i]==0);
}
int main(void){
 const char *path="/private/tmp/retired171.m3i";char error[512];RenderOptions o;assert(read_scene_settings("example.m3i",&o,error));o.width=32;o.height=24;o.camera_override=1;unlink(path);
 if(!write_scene_parameters(NULL,o,path,error)){fprintf(stderr,"save o: %s\n",error);abort();}check_file(path,32,24);
 FILE *f=fopen(path,"r+b");assert(f);long start=840+32*24*18+1136;fseek(f,start+1880,SEEK_SET);fwrite("FRM8",1,4,f);uint32_t one=1;fseek(f,start+1884+6*52+8,SEEK_SET);fwrite(&one,4,1,f);fseek(f,start+4024,SEEK_SET);fwrite("HGI2",1,4,f);fwrite(&one,4,1,f);double strength=2;fwrite(&strength,8,1,f);fclose(f);
 RenderOptions r;assert(read_scene_settings(path,&r,error));assert(!r.program.slots[6].count&&!r.program.slots[7].count&&!r.retired_indirect_enabled);unlink(path);if(!write_scene_parameters(NULL,r,path,error)){fprintf(stderr,"save r: %s\n",error);abort();}check_file(path,32,24);
 unlink("/private/tmp/retired-invalid171.m3i");r.program_override=1;r.program.slots[6].count=1;assert(!write_scene_parameters(NULL,r,"/private/tmp/retired-invalid171.m3i",error));
 puts("Six-slot saves omit retired records and GI; old native imports discard retired settings; new extra-slot requests rejected.");
 return 0;
}
