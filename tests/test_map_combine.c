#include "renderer.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static void empty_path(char *path){int fd=mkstemp(path);assert(fd>=0);close(fd);unlink(path);}
static unsigned read_flag(const char *path){unsigned char flag;int fd=open(path,O_RDONLY);assert(fd>=0&&pread(fd,&flag,1,439)==1);close(fd);return flag;}
int main(int argc,char **argv){
 char on[]="/private/tmp/map-combine-on-XXXXXX",off[]="/private/tmp/map-combine-off-XXXXXX",again[]="/private/tmp/map-combine-again-XXXXXX",error[512];empty_path(on);empty_path(off);empty_path(again);
 RenderOptions o={0};if(argc>1)assert(read_scene_settings(argv[1],&o,error));else assert(read_scene_settings("example.m3i",&o,error));
 o.width=31;o.height=17;o.camera_override=0;o.object_override=1;o.object.map.combine=1;
 assert(write_scene_parameters(argc>1?argv[1]:"example.m3i",o,on,error));assert(read_flag(on)&4);
 assert(read_scene_settings(on,&o,error));assert(o.object.map.combine==1);o.object_override=1;o.object.map.combine=0;
 assert(write_scene_parameters(on,o,off,error));assert(!(read_flag(off)&4));assert((read_flag(off)&~4)==(read_flag(on)&~4));
 assert(read_scene_settings(off,&o,error));assert(o.object.map.combine==0);
 /* Remove the native extension: standard-only readers must also see off. */
 int fd=open(off,O_RDWR);assert(fd>=0&&ftruncate(fd,840+(off_t)o.width*o.height*18+1136)==0);close(fd);
 assert(read_scene_settings(off,&o,error));assert(o.object.map.combine==0);o.object_override=1;o.object.map.combine=1;
 assert(write_scene_parameters(off,o,again,error));assert(read_flag(again)&4);assert(read_scene_settings(again,&o,error)&&o.object.map.combine==1);
 unlink(on);unlink(off);unlink(again);puts("Map combination on/off/on agrees in native and standard headers, preserving unrelated flags.");
}
