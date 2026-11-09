#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
int main(void){@autoreleasepool{
    [NSApplication sharedApplication];
    RenderOptions o;char error[512];assert(read_scene_settings("tests/fixtures/interpolate.m3p",&o,error));
    AppDelegate *a=[AppDelegate new];a.formulaSettings=o;a.formulaKnown=YES;[a showFormulas:nil];
    for(int i=0;i<3;i++){
        int expected[]={61,120,30};a.formulaGlobalFields[1].stringValue=[NSString stringWithFormat:@"%d",expected[i]];
        assert([a readFormulaWindow:&o]);assert(o.iterations==expected[i]);
        a.formulaSettings=o;[a populateFormulaWindow];assert(a.formulaGlobalFields[1].intValue==expected[i]);
    }
    a.formulaGlobalFields[1].stringValue=@"0";assert(![a readFormulaWindow:&o]);assert(o.iterations==30);
    puts("Max iterations edits reach render settings, survive UI refresh, and reject invalid values.");
}return 0;}
