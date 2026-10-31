#include "renderer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
static unsigned get32(const unsigned char *p){return p[0]|p[1]<<8|p[2]<<16|(unsigned)p[3]<<24;}
static void set32(unsigned char *p,unsigned n){for(int i=0;i<4;i++)p[i]=n>>(8*i);}
static void encode(const unsigned char *data,size_t size,char *text){
    strcpy(text,"Some copied parameters\nMandelbulb3Dv18{\r\n");size_t n=strlen(text);
    for(size_t i=0;i<size;i+=3){unsigned bits=data[i]|data[i+1]<<8|data[i+2]<<16;for(int j=0;j<4;j++){unsigned c=bits&63;bits>>=6;text[n++]=(char)(c<12?c+46:c<38?c+53:c+59);}if(i%60==57){text[n++]='\r';text[n++]='\n';}}
    strcpy(text+n,"}\n{Titel: Clipboard test}\n");
}
int main(int argc,char **argv){
    assert(argc==2);unsigned char bytes[1980]={0};FILE *f=fopen(argv[1],"rb");assert(f&&fread(bytes,1,840,f)==840);
    unsigned w=get32(bytes+4),h=get32(bytes+8);assert(!fseek(f,840+(long)w*h*18,SEEK_SET));assert(fread(bytes+840,1,1136,f)==1136);fclose(f);
    char text[8192],error[512],path[]="/tmp/integer-power-clipboard-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);unlink(path);
    size_t size=(840+8+bytes[844]*188+2)/3*3;encode(bytes,size,text);
    assert(import_clipboard_scene(text,path,error));
    RenderOptions copied={0};assert(read_scene_settings(path,&copied,error));char *exported=NULL;assert(export_clipboard_scene(path,copied,&exported,error));assert(exported&&strstr(exported,"Mandelbulb3DxNative1{"));unlink(path);assert(import_clipboard_scene(exported,path,error));free(exported);
    RenderOptions settingsOnly={0};assert(read_scene_settings(path,&settingsOnly,error));assert(settingsOnly.width==(int)w&&settingsOnly.height==(int)h&&settingsOnly.program_override&&settingsOnly.object_override&&settingsOnly.shadows_override&&settingsOnly.lights_override);assert(settingsOnly.program.slots[0].kind==0);
    RenderResult imported=render_scene(path,31,17,1),original=render_scene(argv[1],31,17,1);assert(imported.rgba&&original.rgba);assert(!memcmp(imported.rgba,original.rgba,imported.stride*imported.height));free(imported.rgba);free(original.rgba);unlink(path);
    for(int index=0;index<25;index++) {
        const int kinds[]={100,101,102,103,104,6,2,105,106,107,108,109,110,111,112,113,114,115,116,124,125,126,127,128,129};int kind=kinds[index];
        unsigned char *q=bytes+848;memset(q,0,188);set32(q,1);set32(q+4,kind==2?2:20);set32(q+8,formula_parameter_count(kind));strcpy((char *)q+12,kind==115?"boxIFS":kind==116?"heightmapifs":formula_name(kind));FormulaSlot slot=formula_slot_default(kind);
        for(int j=0;j<formula_parameter_count(kind);j++){double value=formula_slot_value(slot,j);memcpy(q+60+j*8,&value,8);}
        encode(bytes,size,text);assert(import_clipboard_scene(text,path,error));RenderResult custom=render_scene(path,31,17,1);assert(custom.rgba&&custom.settings.program.slots[0].kind==kind);free(custom.rgba);unlink(path);
    }
    unsigned char *badParameter=bytes+848;memset(badParameter,0,188);set32(badParameter,1);set32(badParameter+4,20);set32(badParameter+8,formula_parameter_count(103));strcpy((char *)badParameter+12,"_SinApprox");FormulaSlot badSlot=formula_slot_default(103);for(int j=0;j<5;j++){double value=formula_slot_value(badSlot,j);memcpy(badParameter+60+j*8,&value,8);}double invalidIndex=4;memcpy(badParameter+60,&invalidIndex,8);encode(bytes,size,text);assert(!import_clipboard_scene(text,path,error));assert(strstr(error,"slot 1")&&strstr(error,"_SinApprox")&&strstr(error,"Index (X/Y/Z/W)"));assert(access(path,F_OK));
    FormulaSlot sierp=formula_slot_default(102);unsigned char *sierpRecord=bytes+848;memset(sierpRecord,0,188);set32(sierpRecord,1);set32(sierpRecord+4,20);set32(sierpRecord+8,13);strcpy((char *)sierpRecord+12,"SierpinskiFull");for(int j=0;j<13;j++){double value=formula_slot_value(sierp,j);memcpy(sierpRecord+60+j*8,&value,8);}float deStop=1;memcpy(bytes+177,&deStop,4);encode(bytes,size,text);assert(import_clipboard_scene(text,path,error));assert(read_scene_settings(path,&settingsOnly,error)&&settingsOnly.de_stop==1);unlink(path);
    /* Report all unsupported formulas, not just the first active slot. */
    bytes[844]=3;
    for(int i=0;i<3;i++){unsigned char *q=bytes+848+i*188;memset(q,0,188);set32(q,1);set32(q+4,i==2?8:20+i);if(i<2)strcpy((char *)q+12,i?"UnsupportedBeta":"UnsupportedAlpha");}
    size=(840+8+3*188+2)/3*3;encode(bytes,size,text);
    assert(!import_clipboard_scene(text,path,error));assert(strstr(error,"UnsupportedAlpha")&&strstr(error,"UnsupportedBeta")&&strstr(error,"testIFS"));assert(access(path,F_OK));
    FILE *badFile=fopen(path,"wb");assert(badFile);assert(fwrite(bytes,1,840,badFile)==840);assert(!fseek(badFile,840+(long)w*h*18,SEEK_SET));assert(fwrite(bytes+840,1,1136,badFile)==1136);fclose(badFile);
    assert(!read_scene_settings(path,&settingsOnly,error));assert(strstr(error,"Unsupported formulas")&&strstr(error,"Slot 1: UnsupportedAlpha")&&strstr(error,"Slot 2: UnsupportedBeta")&&strstr(error,"Slot 3: testIFS"));unlink(path);
    assert(!import_clipboard_scene("not a parameter block",path,error));
    assert(!import_clipboard_scene("Mandelbulb3Dv18{....}",path,error));
    assert(!import_clipboard_scene("Mandelbulb3Dv18{!!!!}",path,error));
    puts("Clipboard codec matches file rendering, lists every unsupported formula, and rejects malformed text without creating a scene.");
}
