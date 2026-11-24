#define main app_entry_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface OpacityProbe:AppDelegate
@property(nonatomic) int stopEdits;
@end
@implementation OpacityProbe
- (void)adjustmentColorEdited:(NSColorWell *)sender{self.stopEdits++;[super adjustmentColorEdited:sender];}
- (void)paletteEdited:(id)sender{(void)sender;}
@end
int main(){@autoreleasepool{
 [NSApplication sharedApplication];OpacityProbe *app=[OpacityProbe new];[app ensureWindow];[app.window orderOut:nil];
 RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));app.formulaKnown=YES;app.formulaSettings=o;
 [app showLighting:nil];[app showColorAdjustment:nil];[app.lightingWindow orderOut:nil];[app.colorWindow orderOut:nil];
 AdjustmentColorWell *light=(AdjustmentColorWell *)app.lightControls[0][2];
 for(int channel=0;channel<2;channel++)for(int i=0;i<3;i++){
  double alpha=(double[]){0.,0.35,1.}[i];
  (channel?app.colorSpecularBar:app.colorDiffuseBar).clicked(2,NO);
  NSColorWell *stop=channel?app.colorSpecularWell:app.colorDiffuseWell;
  stop.color=[stop.color colorWithAlphaComponent:alpha];[app adjustmentColorEdited:stop];
  NSArray *wells=channel?app.specularWells:app.diffuseWells;
  assert(fabs([wells[2] color].alphaComponent-alpha)<1e-10);
  int edits=app.stopEdits;
  [light activate:YES];
  assert(!NSColorPanel.sharedColorPanel.showsAlpha&&light.active&&!stop.active);
  assert(fabs(stop.color.alphaComponent-alpha)<1e-10&&fabs([wells[2] color].alphaComponent-alpha)<1e-10&&app.stopEdits==edits);
  [stop activate:YES];
  assert(NSColorPanel.sharedColorPanel.showsAlpha&&stop.active&&!light.active);
  assert(fabs(stop.color.alphaComponent-alpha)<1e-10&&fabs(NSColorPanel.sharedColorPanel.color.alphaComponent-alpha)<1e-10);
 }
 [NSColorPanel.sharedColorPanel orderOut:nil];puts("Switching between palette stops and light colors preserves diffuse/specular opacity, including zero, without editing the previous stop.");
}return 0;}
