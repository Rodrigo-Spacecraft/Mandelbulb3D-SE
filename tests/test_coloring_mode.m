#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface ModeProbe : AppDelegate
@property(nonatomic) int renders;
@property(nonatomic,strong) id renderSender;
@end
@implementation ModeProbe
- (void)calculate:(id)sender {self.renders++;self.renderSender=sender;}
@end
int main(void){@autoreleasepool{
 [NSApplication sharedApplication];ModeProbe *app=[ModeProbe new];[app ensureWindow];[app.window orderOut:nil];char error[512];RenderOptions o;assert(read_scene_settings("example.m3i",&o,error));o.object.orbit_trap=0;app.formulaSettings=o;[app showLighting:nil];[app.lightingWindow orderOut:nil];assert(app.coloringMode.numberOfItems==7&&app.coloringMode.indexOfSelectedItem==0);assert(NSMinX(app.coloringMode.frame)>NSMaxX(app.objectMapCombine.frame));
 for(int mode=0;mode<7;mode++){[app.coloringMode selectItemAtIndex:mode];[app coloringModeChanged:app.coloringMode];assert(app.renders==mode+1&&app.renderSender==app.renderButton);assert(app.formulaSettings.color_option==MAX(0,mode-1)&&app.formulaSettings.object.orbit_trap==(mode>0));char path[]="/private/tmp/color-mode-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);unlink(path);assert(write_scene_parameters(NULL,app.formulaSettings,path,error));RenderOptions loaded;assert(read_scene_settings(path,&loaded,error));assert(loaded.color_option==MAX(0,mode-1)&&loaded.object.orbit_trap==(mode>0));unlink(path);RenderOptions render=app.formulaSettings;render.width=32;render.height=24;render.threads=2;render.reuse_surface=0;RenderResult image=render_scene_with_options(NULL,render);assert(image.rgba&&image.width==32&&image.height==24);free(image.rgba);}
 [app populateObjectLighting];assert(app.coloringMode.indexOfSelectedItem==6);[app setCalculating:YES];assert(!app.coloringMode.enabled);[app setCalculating:NO];assert(app.coloringMode.enabled);puts("All seven coloring modes select, request a full render and round-trip settings");
 }return 0;}
