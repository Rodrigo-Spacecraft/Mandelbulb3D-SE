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
int main(void){@autoreleasepool{[NSApplication sharedApplication];CalculationProbe *a=[CalculationProbe new];[a ensureWindow];[a.window orderOut:nil];RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));[a loadParameterSettings:o path:@"example.m3i" source:@"Test"];[a showNavigator:nil];a.parametersPendingRender=NO;assert(a.navigatorRotationTab.dimmed&&!a.navigatorRotationSliders[0].enabled);RenderOptions nav=a.navigatorFormulaSettings;nav.program.slots[0]=formula_slot_default(2);nav.program.slots[0].count=1;a.navigatorFormulaSettings=nav;[a populateNavigatorFormulaValues];assert(!a.navigatorRotationTab.dimmed&&a.navigatorRotationSliders[0].enabled);CameraSettings camera=a.navigatorCamera;for(int i=0;i<3;i++){a.navigatorRotationSliders[i].doubleValue=30*(i+1);[a navigatorRotationChanged:a.navigatorRotationSliders[i]];assert(fabs(a.navigatorFormulaSettings.rotation4[i]-(i+1)*M_PI/6)<1e-10);}RenderOptions applied=[a applyNavigatorFormulas:a.formulaSettings];assert(applied.rotation4_override&&fabs(applied.rotation4[2]-M_PI/2)<1e-10);CameraSettings after=a.navigatorCamera;assert(!memcmp(&camera,&after,sizeof camera));nav=a.navigatorFormulaSettings;nav.program.slots[0].count=0;a.navigatorFormulaSettings=nav;[a populateNavigatorRotation];assert(a.navigatorRotationTab.dimmed&&!a.navigatorRotationFields[2].enabled);assert(fabs(a.navigatorFormulaSettings.rotation4[2]-M_PI/2)<1e-10);puts("4D rotation activation, degree conversion, transfer and camera preservation passed.");}return 0;}
