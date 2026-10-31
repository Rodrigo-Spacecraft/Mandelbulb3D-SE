#define main app_entry_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface RepaintApp : AppDelegate
@end
@implementation RepaintApp
- (void)resetNavigator {}
@end
static void wait_render(AppDelegate *app){NSDate *limit=[NSDate dateWithTimeIntervalSinceNow:20];while(app.calculating&&limit.timeIntervalSinceNow>0)CFRunLoopRunInMode(kCFRunLoopDefaultMode,.02,YES);assert(!app.calculating);}
int main(void){@autoreleasepool{
 [NSApplication sharedApplication];RepaintApp *app=[RepaintApp new];[app ensureWindow];[app.window orderOut:nil];RenderOptions options;char error[512];assert(read_scene_settings("example.m3i",&options,error));double ratio=32.0/options.width;options.width=32;options.height=24;options.de_stop*=ratio;options.camera_override=1;options.threads=2;options.reflections_override=1;options.reflections.enabled=1;options.reflections.amount=1;options.reflections.depth=2;options.dof_override=1;options.dof.enabled=0;options.reuse_surface=1;
#ifdef USE_RUST_ENGINE
 render_set_rust_assets("rust-assets/M3Formulas");
#endif
 app.lightingRepaintRequested=YES;[app beginRenderPath:@"example.m3i" options:options];app.lightingRepaintRequested=NO;wait_render(app);assert(app.completedRender&&app.formulaSettings.reflections.enabled);assert([app.renderInfoText.string containsString:@"Refl/transmission: 0\n"]);assert([app.statusLabel.stringValue containsString:@"Reflections discarded"]);
 [app beginRenderPath:@"example.m3i" options:options];wait_render(app);assert(app.formulaSettings.reflections.enabled);assert(![app.renderInfoText.string containsString:@"Refl/transmission: 0\n"]);
 puts("Lighting repaint drops reflection rays, preserves enabled settings, and a manual render restores the reflection pass.");
}}
