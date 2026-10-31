#include "../renderer.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc,char **argv){char error[512];RenderOptions o;assert(read_scene_settings("example.m3i",&o,error));o.width=o.height=32;o.program_override=1;o.program.slots[0]=formula_slot_default(106);o.program.slots[0].count=1;for(int i=1;i<8;i++)o.program.slots[i].count=0;
 double indices[]={9,-9,4,-4,3,2147483648.0};
 for(int native=0;native<2;native++)for(int i=0;i<6;i++){char path[]="/private/tmp/siny-index-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);unlink(path);assert(write_scene_parameters(NULL,o,path,error));fd=open(path,O_RDWR);double value=indices[i];off_t extra=840+32*32*18+1136;assert(pwrite(fd,&value,8,840+32*32*18+8+60)==8);assert(pwrite(fd,&value,8,extra+2404)==8);if(!native)assert(!ftruncate(fd,extra));close(fd);RenderOptions loaded;assert(read_scene_settings(path,&loaded,error));assert(loaded.program.slots[0].parameters[0]==fabs(fmod(value,4)));unlink(path);}
 if(argc>1){assert(read_scene_settings(argv[1],&o,error));int found=0;for(int i=0;i<8;i++)if(o.program.slots[i].kind==106&&o.program.slots[i].count){assert(o.program.slots[i].parameters[0]==1);found=1;}assert(found);}
 puts("_SinY indices normalize for positive/negative values in standard and native files; user scene imports");return 0;}
