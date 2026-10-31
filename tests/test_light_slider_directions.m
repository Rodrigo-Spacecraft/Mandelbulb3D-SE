#define main app_main_unused
#import "App.m"
#undef main
#include <assert.h>
@interface SliderDirectionProbe : AppDelegate
@end
@implementation SliderDirectionProbe
- (void)requestLightingPreview {}
@end
int main(void){@autoreleasepool{
[NSApplication sharedApplication];SliderDirectionProbe *app=[SliderDirectionProbe new];[app ensureWindow];[app.window orderOut:nil];RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));app.formulaSettings=o;[app showLighting:nil];[app.lightingWindow orderOut:nil];[app populateLights];
for(int light=0;light<6;light++)for(int positional=0;positional<2;positional++){
NSArray *controls=app.lightControls[light];[(NSPopUpButton *)controls[1] selectItemAtIndex:positional];for(int axis=0;axis<3;axis++)[(NSTextField *)controls[4+axis] setDoubleValue:12+axis];[app syncLightSliders];
for(int axis=0;axis<3;axis++){NSSlider *slider=app.lightSliders[light][axis];double sign=(!positional&&axis==0)||(positional&&axis==1)?-1:1;assert(slider.doubleValue==sign*(12+axis));slider.doubleValue=-5;[app lightSliderChanged:slider];assert([(NSTextField *)controls[4+axis] doubleValue]==sign*-5);[app syncLightSliders];assert(slider.doubleValue==-5);[(NSTextField *)controls[4+axis] setDoubleValue:500];[app syncLightSliders];assert(slider.doubleValue==sign*500&&slider.doubleValue>=slider.minValue&&slider.doubleValue<=slider.maxValue);}
}
puts("All six lights: X angle and Y position are reversed, other axes unchanged; text edits and slider synchronization retain signed values and expanded bounds.");}}
