#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface OpacityProbe:AppDelegate
@end
@implementation OpacityProbe
- (void)finishLightingSlider {}
- (void)requestLightingPreview {}
@end
int main(int argc,char **argv){@autoreleasepool{assert(argc==2);[NSApplication sharedApplication];RenderOptions o;char e[512];assert(read_scene_settings(argv[1],&o,e));o.reflections.opacity_set=1;o.reflections.opacity[0][0]=.25;o.reflections.opacity[1][0]=.75;
 OpacityProbe *a=[OpacityProbe new];a.formulaSettings=o;a.formulaKnown=YES;[a showLighting:nil];[a showColorAdjustment:nil];assert(((AdjustmentColorWell *)a.diffuseWells[0]).allowsOpacity);assert(((AdjustmentColorWell *)a.colorDiffuseWell).allowsOpacity);assert(fabs(a.diffuseWells[0].color.alphaComponent-.25)<1e-6);
 [a.colorStopMenu selectItemAtIndex:0];[a refreshColorSelection:nil];a.colorDiffuseWell.color=[NSColor colorWithSRGBRed:.4 green:.3 blue:.2 alpha:.4];[a adjustmentColorEdited:a.colorDiffuseWell];assert([a readReflections:&o]);assert(fabs(o.reflections.opacity[0][0]-.4)<1e-6);assert(fabs(o.reflections.opacity[1][0]-.75)<1e-6);
 const char *file="/private/tmp/diffuse-opacity-ui.m3i";unlink(file);assert(write_scene_parameters(argv[1],o,file,e));RenderOptions restored;assert(read_scene_settings(file,&restored,e));assert(fabs(restored.reflections.opacity[0][0]-.4)<1e-6&&fabs(restored.reflections.opacity[1][0]-.75)<1e-6);unlink(file);puts("Diffuse opacity picker, UI readback and independent opacity channels survive save/load.");}return 0;}
