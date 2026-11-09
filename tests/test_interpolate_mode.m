#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
int main(int argc,const char **argv){@autoreleasepool{
    [NSApplication sharedApplication];setenv("MB3DX_TEMP_DIR","/private/tmp",1);setenv("MB3DX_GPU","cpu",1);
    const char *source=argc>1?argv[1]:"tests/fixtures/interpolate.m3p";RenderOptions o;char error[512];assert(read_scene_settings(source,&o,error));
    assert(o.program.mode==1);assert(formula_iteration_value(o.program,0)==1);assert(formula_iteration_value(o.program,1)==12);
    AppDelegate *a=[AppDelegate new];a.formulaSettings=o;a.formulaKnown=YES;[a showFormulas:nil];
    assert(a.formulaTabs.numberOfTabViewItems==2);assert(a.formulaCountFields[0].doubleValue==1&&a.formulaCountFields[1].doubleValue==12);
    [a.formulaTabs selectTabViewItemAtIndex:1];assert(!a.formulaMoveRight.enabled);assert([a readFormulaWindow:&o]);
    assert(formula_iteration_value(o.program,1)==12);for(int i=2;i<6;i++)assert(!o.program.slots[i].count);
    const char *path="/private/tmp/interpolate-test.m3i";unlink(path);assert(write_scene_parameters(source,o,path,error));
    RenderOptions loaded;assert(read_scene_settings(path,&loaded,error));assert(formula_iteration_value(loaded.program,0)==1&&formula_iteration_value(loaded.program,1)==12);
    FILE *f=fopen(path,"rb");assert(f);fseek(f,840+(long)o.width*o.height*18+8,SEEK_SET);float weights[2];fread(&weights[0],4,1,f);fseek(f,184,SEEK_CUR);fread(&weights[1],4,1,f);fclose(f);assert(weights[0]==1&&weights[1]==12);
    a.formulaCountFields[0].stringValue=@"0.25";a.formulaCountFields[1].stringValue=@"0.75";assert([a readFormulaWindow:&o]);unlink(path);assert(write_scene_parameters(source,o,path,error));assert(read_scene_settings(path,&loaded,error));assert(formula_iteration_value(loaded.program,0)==.25&&formula_iteration_value(loaded.program,1)==.75);unlink(path);
    [a.formulaMode selectItemAtIndex:0];[a formulaModeChanged:nil];assert(a.formulaTabs.numberOfTabViewItems==6);[a.formulaMode selectItemAtIndex:1];[a formulaModeChanged:nil];assert(a.formulaTabs.numberOfTabViewItems==2);
    assert(read_scene_settings(source,&o,error));o.width=480;o.height=360;o.threads=4;o.shadows.ambient_auto=0;o.shadows.hard_auto=0;
    RenderResult r=render_scene_with_options(source,o);if(!r.rgba){puts(r.error);return 1;}
    NSBitmapImageRep *bitmap=[[NSBitmapImageRep alloc]initWithBitmapDataPlanes:NULL pixelsWide:r.width pixelsHigh:r.height bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSDeviceRGBColorSpace bytesPerRow:r.width*4 bitsPerPixel:32];for(int y=0;y<r.height;y++)memcpy(bitmap.bitmapData+y*bitmap.bytesPerRow,r.rgba+y*r.stride,r.width*4);
    assert([[bitmap representationUsingType:NSBitmapImageFileTypePNG properties:@{}]writeToFile:@"/private/tmp/interpolate-fixed.png" atomically:NO]);free(r.rgba);
    puts("Interpolation weights and fractional edits survive standard/native saves; only two tabs are available; render succeeds.");
}return 0;}
