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
int main(void){@autoreleasepool{[NSApplication sharedApplication];DragApp *app=[DragApp new];[app ensureWindow];[app.window orderOut:nil];RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));app.formulaKnown=YES;app.formulaSettings=o;[app showLighting:nil];[app showColorAdjustment:nil];[app.lightingWindow orderOut:nil];[app.colorWindow makeKeyAndOrderFront:nil];
for(int doubleClick=0;doubleClick<=1;doubleClick++)for(int specular=0;specular<=1;specular++){
 NSInteger stop=specular?2:1;
 PaletteView *bar=specular?app.colorSpecularBar:app.colorDiffuseBar;
 CGFloat x=paletteMarkerInset+(bar.bounds.size.width-2*paletteMarkerInset)*MIN(32767,bar.palette.stops[stop].position)/32767.;
 NSPoint location=[bar convertPoint:NSMakePoint(x,5) toView:nil];
 NSEvent *click=[NSEvent mouseEventWithType:NSEventTypeLeftMouseDown location:location modifierFlags:0 timestamp:0 windowNumber:app.colorWindow.windowNumber context:nil eventNumber:0 clickCount:doubleClick?2:1 pressure:1];
 if(!doubleClick)[NSColorPanel.sharedColorPanel orderOut:nil];
 [bar mouseDown:click];
 NSPoint jitter=location;jitter.x+=1;
 NSEvent *smallMove=[NSEvent mouseEventWithType:NSEventTypeLeftMouseDragged location:jitter modifierFlags:0 timestamp:0 windowNumber:app.colorWindow.windowNumber context:nil eventNumber:1 clickCount:1 pressure:1];
 [bar mouseDragged:smallMove];assert(!bar.draggingStop);
 [bar mouseUp:click];
 assert(app.previews==0&&app.finishes==0);
 NSColorWell *selected=specular?app.colorSpecularWell:app.colorDiffuseWell;
 NSColorWell *other=specular?app.colorDiffuseWell:app.colorSpecularWell;
 assert(app.colorStopMenu.indexOfSelectedItem==stop&&selected.active&&!other.active);
 NSColor *shown=[NSColorPanel.sharedColorPanel.color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];
 NSColor *expected=[selected.color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];
 assert(fabs(shown.redComponent-expected.redComponent)<1e-6&&fabs(shown.greenComponent-expected.greenComponent)<1e-6&&fabs(shown.blueComponent-expected.blueComponent)<1e-6&&fabs(shown.alphaComponent-expected.alphaComponent)<1e-6);
 assert(NSColorPanel.sharedColorPanel.visible);

 assert([(specular?app.colorSpecularBar:app.colorDiffuseBar) acceptsFirstMouse:nil]);
}
[NSColorPanel.sharedColorPanel orderOut:nil];[app.colorStopMenu selectItemAtIndex:3];[app refreshColorSelection:app.colorStopMenu];
assert(NSColorPanel.sharedColorPanel.visible&&app.colorSpecularWell.active&&app.finishes==0);
PaletteView *dragBar=app.colorDiffuseBar;
CGFloat dragX=paletteMarkerInset+(dragBar.bounds.size.width-2*paletteMarkerInset)*dragBar.palette.stops[1].position/32767.;
NSPoint dragStart=[dragBar convertPoint:NSMakePoint(dragX,5) toView:nil];
NSEvent *down=[NSEvent mouseEventWithType:NSEventTypeLeftMouseDown location:dragStart modifierFlags:0 timestamp:0 windowNumber:app.colorWindow.windowNumber context:nil eventNumber:0 clickCount:1 pressure:1];
[dragBar mouseDown:down];dragStart.x+=10;
NSEvent *drag=[NSEvent mouseEventWithType:NSEventTypeLeftMouseDragged location:dragStart modifierFlags:0 timestamp:0 windowNumber:app.colorWindow.windowNumber context:nil eventNumber:1 clickCount:1 pressure:1];
[dragBar mouseDragged:drag];assert(app.previews==1&&app.finishes==0);
[dragBar mouseUp:drag];assert(app.finishes==1&&!dragBar.draggingStop);
app.previews=app.finishes=0;
[NSColorPanel.sharedColorPanel orderOut:nil];[app moveColorStop:4 position:14000 finished:NO];assert(app.previews==1&&app.finishes==0&&app.lightingSliderTracking);[app moveColorStop:4 position:14500 finished:NO];assert(app.previews==2&&app.finishes==0);[app moveColorStop:4 position:14500 finished:YES];assert(app.finishes==1&&!app.lightingSliderTracking);puts("Palette stop drags request live repaints and finish once on release.");}return 0;}
