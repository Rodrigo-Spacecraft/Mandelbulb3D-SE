#include "../renderer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void){FILE *in=fopen("example.m3i","rb");assert(in);fseek(in,0,SEEK_END);long length=ftell(in);rewind(in);unsigned char *bytes=malloc(length);assert(fread(bytes,1,length,in)==(size_t)length);fclose(in);memset(bytes+382,0x55,28);const char *source="/private/tmp/author-import248.m3i",*target="/private/tmp/author-save248.m3i";FILE *out=fopen(source,"wb");assert(out);assert(fwrite(bytes,1,length,out)==(size_t)length);fclose(out);free(bytes);RenderOptions options;char error[512];assert(read_scene_settings(source,&options,error));for(int i=382;i<410;i++)assert(options.preserved_header[i]==0);memset(options.preserved_header+382,0x77,28);unlink(target);assert(write_scene_parameters(source,options,target,error));in=fopen(target,"rb");assert(in);unsigned char header[840];assert(fread(header,1,840,in)==840);fclose(in);for(int i=382;i<410;i++)assert(header[i]==0);unlink(source);unlink(target);puts("Orig/Mod discarded on import and excluded from save, including stale parameter state.");return 0;}
