#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
int main(int argc,const char **argv){@autoreleasepool{
    [NSApplication sharedApplication];AppDelegate *a=[AppDelegate new];
    RenderOptions o;char error[512];assert(read_scene_settings(argc>1?argv[1]:"example.m3i",&o,error));
    o.ambient.depth=240*.8e-6;
    a.formulaSettings=o;a.formulaKnown=YES;
    NSTabView *tabs=[[NSTabView alloc]initWithFrame:NSMakeRect(0,0,552,700)];
    [a addAmbientTab:tabs];[a populateAmbientLighting];
    assert([a readAmbientLighting:&o]);assert(o.ambient.depth==240*.8e-6);
    for(int i=0;i<3;i++){a.formulaSettings=o;[a populateAmbientLighting];assert([a readAmbientLighting:&o]);}
    a.ambientFields[1].stringValue=@"241";assert(![a readAmbientLighting:&o]);
    a.ambientFields[1].stringValue=@"-1";assert(![a readAmbientLighting:&o]);
    puts("Ambient endpoint survives repeated UI readback; genuinely invalid depth values are rejected.");
}return 0;}
