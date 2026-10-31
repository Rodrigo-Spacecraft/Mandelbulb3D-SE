#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface ReleaseLayoutProbe:AppDelegate
@end
@implementation ReleaseLayoutProbe
- (NSURL *)applicationMapsFolderURL {return [NSURL fileURLWithPath:@"/private/tmp/release-layout210/Maps" isDirectory:YES];}
- (void)requestNavigatorPreview {}
@end
int main(void){@autoreleasepool{[NSApplication sharedApplication];ReleaseLayoutProbe *a=[ReleaseLayoutProbe new];[a ensureWindow];[a.window orderOut:nil];
#ifdef USE_RUST_ENGINE
 assert([APP_TITLE isEqual:@"Mandelbulb3D SE"]&&a.cpuOnlyCheck.hidden);assert([a.renderHistory.directory.lastPathComponent isEqual:@"Mandelbulb3Dr-RenderHistory"]);
#endif
 RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));a.formulaKnown=YES;a.formulaSettings=o;[a showNavigator:nil];for(NSTextField *value in a.navigatorCameraDisplays){assert(value.frame.origin.y==677);assert(NSMaxX(value.frame)<=704);}assert(a.navigatorBrightnessSlider.frame.origin.x-NSMaxX(a.fixedZoomCheck.frame)>60);NSView *panel=a.navigatorWindow.contentView;NSRect row=NSMakeRect(0,650,720,55);NSBitmapImageRep *bitmap=[panel bitmapImageRepForCachingDisplayInRect:row];[panel cacheDisplayInRect:row toBitmapImageRep:bitmap];[[bitmap representationUsingType:NSBitmapImageFileTypePNG properties:@{}]writeToFile:@"/private/tmp/navrow210.png" atomically:YES];puts("Release name/debug control and stacked Navigator camera displays verified.");}return 0;}
