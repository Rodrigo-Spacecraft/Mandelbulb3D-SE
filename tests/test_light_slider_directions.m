#define main app_main_unused
#import "../App.m"
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
for(int axis=0;axis<3;axis++){
 LiveSlider *slider=(LiveSlider *)app.lightSliders[light][axis];double before=[(NSTextField *)controls[4+axis] doubleValue];
 if(positional){double start=slider.doubleValue;slider.doubleValue=start-1;[app lightSliderChanged:slider];double after=[(NSTextField *)controls[4+axis] doubleValue];assert(axis==1?after>before:after<before);[app syncLightSliders];assert(slider.doubleValue==start-1);[(NSTextField *)controls[4+axis] setDoubleValue:500];[app syncLightSliders];assert(slider.doubleValue==start-1);}
 else{double sign=axis==0?-1:1;assert(slider.doubleValue==sign*before);slider.doubleValue=-5;[app lightSliderChanged:slider];assert([(NSTextField *)controls[4+axis] doubleValue]==sign*-5);[(NSTextField *)controls[4+axis] setDoubleValue:500];[app syncLightSliders];assert(slider.doubleValue==sign*500);}
}
}
puts("All six lights: directional signs retained; relative positional movement signs correct; typed coordinates do not recenter the sliders.");}}
