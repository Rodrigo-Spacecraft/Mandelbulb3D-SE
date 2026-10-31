#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface CalculationProbe:AppDelegate
@end
@implementation CalculationProbe
- (void)startNavigatorPreview {}
- (NSURL *)applicationMapsFolderURL {return [NSURL fileURLWithPath:@"/private/tmp/calculation219/Data/Library/Application Support/Mandelbulb3D SE/Maps" isDirectory:YES];}
- (void)beginRenderPath:(NSString *)path options:(RenderOptions)options {(void)path;(void)options;}
@end
int main(void){@autoreleasepool{[NSApplication sharedApplication];CalculationProbe *a=[CalculationProbe new];[a ensureWindow];[a.window orderOut:nil];RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));[a loadParameterSettings:o path:@"example.m3i" source:@"Test"];[a showNavigator:nil];a.parametersPendingRender=NO;assert(a.navigatorCutSliders.count==3);CameraSettings camera=a.navigatorCamera;a.navigatorCutChecks[0].state=NSControlStateValueOn;a.navigatorCutFields[0].doubleValue=.25;[a navigatorCuttingChanged:a.navigatorCutFields[0]];assert(a.navigatorFormulaSettings.cutting_mask==1&&a.navigatorFormulaSettings.cutting[0]==.25);a.navigatorCutSliders[1].doubleValue=.5;a.navigatorCutChecks[1].state=NSControlStateValueOn;[a navigatorCuttingChanged:a.navigatorCutSliders[1]];RenderOptions applied=[a applyNavigatorFormulas:a.formulaSettings];assert(applied.cutting_override&&applied.cutting_mask==3&&applied.cutting[1]==.5);CameraSettings after=a.navigatorCamera;assert(!memcmp(&camera,&after,sizeof camera));char err[512];NSString *file=@"/private/tmp/cut243.m3i";unlink(file.fileSystemRepresentation);assert(write_scene_parameters(NULL,applied,file.fileSystemRepresentation,err));RenderOptions restored;assert(read_scene_settings(file.fileSystemRepresentation,&restored,err));assert(restored.cutting_mask==3&&restored.cutting[0]==.25&&restored.cutting[1]==.5);unlink(file.fileSystemRepresentation);puts("Cutting controls, slider edits, camera preservation, and standard-header round trip passed.");}return 0;}
