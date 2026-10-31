#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface LightingProbe : AppDelegate
@end
@implementation LightingProbe
- (void)finishLightingSlider {}
- (void)requestLightingPreview {}
@end
int main(void){@autoreleasepool{
[NSApplication sharedApplication];LightingProbe *a=[LightingProbe new];[a ensureWindow];[a.window orderOut:nil];RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));a.formulaSettings=o;a.formulaKnown=YES;[a showLighting:nil];[a.lightingWindow orderOut:nil];
assert(a.objectSliders.count==5);NSSlider *z=a.objectSliders[4];assert(z.minValue==-120&&z.maxValue==360);z.doubleValue=123;[a objectSliderChanged:z];assert(a.objectFields[4].doubleValue==123);a.objectFields[4].doubleValue=-42;[a objectStrengthEdited:a.objectFields[4]];assert(z.doubleValue==-42);
assert(NSMinX(a.fitColorsButton.frame)>NSMaxX(a.objectFields[4].frame));assert(fabs(NSMinY(a.fitColorsButton.frame)-NSMinY(z.frame))<=1);assert(NSMaxX(z.frame)<NSMinX(a.objectFields[4].frame));assert(a.openLightingButton.superview==a.lightingWindow.contentView);assert(a.keepLightsCheck.superview==a.openLightingButton.superview);assert(NSMinX(a.keepLightsCheck.frame)>NSMaxX(a.openLightingButton.frame));assert(NSMaxX(a.keepLightsCheck.frame)<NSMinX(a.saveLightingButton.frame));assert(a.keepLightsCheck.state==NSControlStateValueOff);assert(a.lightingUndoButton.superview==a.applyLightingButton.superview);assert(NSMaxX(a.lightingUndoButton.frame)<NSMinX(a.applyLightingButton.frame));NSTabView *tabs=nil;for(NSView *v in a.lightingWindow.contentView.subviews)if([v isKindOfClass:NSTabView.class])tabs=(NSTabView *)v;assert(tabs.numberOfTabViewItems==5);for(NSTabViewItem *item in tabs.tabViewItems){NSMutableArray *pending=[NSMutableArray arrayWithObject:item.view];while(pending.count){NSView *v=pending.lastObject;[pending removeLastObject];if([v isKindOfClass:NSButton.class])assert(![[(NSButton *)v title]isEqualToString:@"Apply & Render"]);[pending addObjectsFromArray:v.subviews];}}for(int i=0;i<5;i++){[tabs selectTabViewItemAtIndex:i];assert(!a.openLightingButton.hidden&&!a.lightingUndoButton.hidden);assert(NSMaxY(a.applyLightingButton.frame)<NSMinY(tabs.frame));}assert([a.lightingUndoButton isKindOfClass:LightingUndoButton.class]);
a.lightingUndoHistory=nil;[a recordLightingRepaint:o];a.lightingSliderTracking=YES;RenderOptions dragged=o;dragged.gamma=12;[a recordLightingRepaint:dragged];assert(a.lightingUndoHistory.count==1);a.lightingSliderTracking=NO;RenderOptions b=o;b.gamma_override=1;b.gamma=17;[a recordLightingRepaint:b];a.formulaSettings=b;[a undoLighting:nil];assert(a.formulaSettings.gamma==o.gamma);[a recordLightingRepaint:a.formulaSettings];[a.lightingUndoButton rightMouseDown:nil];assert(a.formulaSettings.gamma==17);[a recordLightingRepaint:a.formulaSettings];for(int i=0;i<70;i++){b.gamma=i;[a recordLightingRepaint:b];}assert(a.lightingUndoHistory.count==64);puts("Lighting layout, Z slider, undo/redo and history limit passed");
}return 0;}
