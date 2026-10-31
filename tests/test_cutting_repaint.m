#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface CalculationProbe:AppDelegate
@property(nonatomic) NSInteger fullRenders,repaints;
@end
@implementation CalculationProbe
- (void)calculate:(id)sender {(void)sender;self.fullRenders++;}
- (void)requestLightingPreview {self.repaints++;}
- (NSURL *)applicationMapsFolderURL {return [NSURL fileURLWithPath:@"/private/tmp/calculation219/Data/Library/Application Support/Mandelbulb3D SE/Maps" isDirectory:YES];}
- (void)beginRenderPath:(NSString *)path options:(RenderOptions)options {(void)path;(void)options;}
@end
int main(void){@autoreleasepool{[NSApplication sharedApplication];CalculationProbe *a=[CalculationProbe new];[a ensureWindow];[a.window orderOut:nil];RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));[a loadParameterSettings:o path:@"example.m3i" source:@"Test"];[a showLighting:nil];[a commitInsideColors:a.formulaSettings.cutting_colors];[a finishLightingSlider];assert(a.fullRenders==0&&a.repaints==1);[a beginLightingSlider];[a commitInsideColors:a.formulaSettings.cutting_colors];[a finishLightingSlider];assert(a.repaints==1);[a endLightingSlider];assert(a.fullRenders==0&&a.repaints==2);puts("Cutting color release uses repaint rather than main render.");}return 0;}
