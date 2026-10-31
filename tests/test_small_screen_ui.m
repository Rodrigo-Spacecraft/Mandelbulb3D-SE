#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface SmallScreenProbe:AppDelegate
@end
@implementation SmallScreenProbe
- (void)requestNavigatorPreviewAdaptingDistance:(BOOL)adapt{(void)adapt;}
- (NSURL *)applicationMapsFolderURL{return [NSURL fileURLWithPath:@"/private/tmp/ui269-maps" isDirectory:YES];}
- (void)beginRenderPath:(NSString *)path options:(RenderOptions)options{(void)path;(void)options;}
@end
static void snapshot(NSView *view,NSString *path){[view display];NSBitmapImageRep *rep=[view bitmapImageRepForCachingDisplayInRect:view.bounds];[view cacheDisplayInRect:view.bounds toBitmapImageRep:rep];[[rep representationUsingType:NSBitmapImageFileTypePNG properties:@{}]writeToFile:path atomically:YES];}
int main(void){@autoreleasepool{[NSApplication sharedApplication];SmallScreenProbe *a=[SmallScreenProbe new];[a ensureWindow];assert([a.window isKindOfClass:MainTitleWindow.class]);MainTitleWindow *w=(MainTitleWindow *)a.window;assert(w.identityAccessory&&w.titleVisibility==NSWindowTitleHidden);assert(w.identityAccessory.view.subviews.count==2);assert([(NSImageView *)w.identityAccessory.view.subviews[0] image]);w.title=@"Mandelbulb3D SE — Sample.m3i";assert([w.identityTitle.stringValue isEqual:w.title]);
[w display];[w.identityAccessory.view layoutSubtreeIfNeeded];
NSRect iconRect=[w.identityAccessory.view.subviews[0] convertRect:w.identityAccessory.view.subviews[0].bounds toView:nil];
NSRect titleRect=[w.identityTitle convertRect:w.identityTitle.bounds toView:nil];
assert(fabs((NSMinX(iconRect)+NSMaxX(titleRect))/2-w.frame.size.width/2)<1);
NSRect resized=w.frame;resized.size.width+=100;[w setFrame:resized display:YES];[w display];[w.identityAccessory.view layoutSubtreeIfNeeded];
iconRect=[w.identityAccessory.view.subviews[0] convertRect:w.identityAccessory.view.subviews[0].bounds toView:nil];titleRect=[w.identityTitle convertRect:w.identityTitle.bounds toView:nil];
assert(fabs((NSMinX(iconRect)+NSMaxX(titleRect))/2-w.frame.size.width/2)<1);
RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));[a loadParameterSettings:o path:@"example.m3i" source:@"Test"];assert(([a.window.title isEqual:[NSString stringWithFormat:@"%@ — example.m3i",APP_TITLE]]));[a showNavigator:nil];assert(a.navigatorFormulaRange.frame.size.width>=72);assert([a.navigatorFormulaRange.selectedItem.title isEqual:@"mid"]);for(NSButton *button in a.navigatorExploreArrows)assert([button isKindOfClass:ReadableSymbolButton.class]&&((ReadableSymbolButton *)button).symbolSize==16);[a showLighting:nil];assert(((ReadableSymbolButton *)a.addColorFavoriteButton).symbolSize==20);
snapshot(a.window.contentView.superview,@"/private/tmp/main270.png");[a.navigatorRotationTab.tabView selectTabViewItemAtIndex:1];snapshot(a.navigatorRotationTab.tabView.selectedTabViewItem.view,@"/private/tmp/navigator269.png");snapshot(a.addColorFavoriteButton.superview,@"/private/tmp/lighting269.png");[a.window orderOut:nil];[a.navigatorWindow orderOut:nil];[a.lightingWindow orderOut:nil];puts("Decorative title icon, clean model title, readable range menu and larger heart/explore glyphs passed.");}return 0;}
