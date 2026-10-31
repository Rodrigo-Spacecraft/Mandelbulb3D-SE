#define main app_entry_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface DragApp:AppDelegate
@property(nonatomic) int previews,finishes;
@end
@implementation DragApp
- (void)requestLightingPreview {self.previews++;}
- (void)calculate:(id)sender {(void)sender;self.finishes++;}
@end
int main(void){@autoreleasepool{[NSApplication sharedApplication];DragApp *app=[DragApp new];[app ensureWindow];[app.window orderOut:nil];RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));app.formulaKnown=YES;app.formulaSettings=o;[app showLighting:nil];[app showColorAdjustment:nil];[app.lightingWindow orderOut:nil];[app.colorWindow orderOut:nil];[app moveColorStop:4 position:14000 finished:NO];assert(app.previews==1&&app.finishes==0&&app.lightingSliderTracking);[app moveColorStop:4 position:14500 finished:NO];assert(app.previews==2&&app.finishes==0);[app moveColorStop:4 position:14500 finished:YES];assert(app.finishes==1&&!app.lightingSliderTracking);puts("Palette stop drags request live repaints and finish once on release.");}return 0;}
