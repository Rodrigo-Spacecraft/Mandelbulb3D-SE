#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface NavigatorLightingProbe:AppDelegate
@property(nonatomic) int previews;
@property(nonatomic) BOOL adapted;
@end
@implementation NavigatorLightingProbe
- (void)requestNavigatorPreviewAdaptingDistance:(BOOL)adapt{self.previews++;self.adapted=adapt;}
@end
static void verifyRotation(NavigatorLightingProbe *a,BOOL active){
 // Check the visible tab strip immediately, without tab selection or forced layout.
 assert(a.navigatorRotationTab.dimmed==!active);NSSegmentedControl *s=a.navigatorTabControl;assert(s);
 NSInteger index=[a.navigatorRotationTab.tabView indexOfTabViewItem:a.navigatorRotationTab];assert([s isEnabledForSegment:index]==active);
 for(NSControl *c in a.navigatorRotationSliders)assert(c.enabled==active);
 assert(s.selectedSegment==0);assert([a.navigatorRotationTab.tabView indexOfTabViewItem:a.navigatorRotationTab.tabView.selectedTabViewItem]==0);
}
int main(){@autoreleasepool{
 [NSApplication sharedApplication];RenderOptions main;char error[512];assert(read_scene_settings("example.m3i",&main,error));NavigatorLightingProbe *a=[NavigatorLightingProbe new];a.formulaSettings=main;a.formulaKnown=YES;[a showNavigator:nil];
 // Give Navigator a different formula and parameter, Julia, cut and camera.
 RenderOptions local=a.navigatorFormulaSettings;local.program.slots[0]=formula_slot_default(2);local.program.slots[0].count=1;formula_slot_set_value(&local.program.slots[0],0,3);local.julia=1;local.julia_c[0]=.7;local.cutting_mask=1;local.cutting[0]=.2;local.rotation4[0]=.3;a.navigatorFormulaSettings=local;[a populateNavigatorFormulaValues];[a populateNavigatorJuliaValues];a.navigatorCamera=(CameraSettings){.origin={1,2,3},.axes={1,0,0,0,1,0,0,0,1},.zoom=7,.distance=9,.fov=30};CameraSettings camera=a.navigatorCamera;
 verifyRotation(a,YES);
 main.object.palette_start+=10;a.formulaSettings=main;int previews=a.previews;[a refreshNavigatorAfterMainRenderPreservingEdits:YES];
 RenderOptions retainedOptions=a.navigatorFormulaSettings;assert(!memcmp(&local.program,&retainedOptions.program,sizeof local.program));assert(a.navigatorFormulaSettings.julia_c[0]==.7&&a.navigatorFormulaSettings.cutting[0]==.2&&a.navigatorFormulaSettings.rotation4[0]==.3);CameraSettings retained=a.navigatorCamera;assert(!memcmp(&camera,&retained,sizeof camera));assert(a.previews==previews+1&&!a.adapted);
 RenderOptions preview=[a applyNavigatorFormulas:a.formulaSettings];assert(preview.object.palette_start==main.object.palette_start&&preview.program.slots[0].kind==2);
 // Reset from Main removes 4D; local formula selection restores it.
 [a refreshNavigatorAfterMainRenderPreservingEdits:NO];assert(a.navigatorFormulaSettings.program.slots[0].kind==main.program.slots[0].kind);verifyRotation(a,NO);
 NSMenuItem *item=[[NSMenuItem alloc]initWithTitle:@"4D" action:nil keyEquivalent:@""];item.tag=2;[a navigatorFormulaTypeChosen:item];verifyRotation(a,YES);
 // Reset Value restores only the most recently edited rotation from Main.
 for(int i=0;i<3;i++){
  RenderOptions baseline=a.formulaSettings;baseline.rotation4[i]=.1*(i+1);a.formulaSettings=baseline;
  NSSlider *slider=a.navigatorRotationSliders[i];slider.doubleValue=45+i;[a navigatorRotationChanged:slider];
  assert(a.navigatorResetValueButton.enabled);assert([a.navigatorResetTarget[@"rotation4"] intValue]==i);
  RenderOptions before=a.navigatorFormulaSettings;[a resetNavigatorValue:nil];
  assert(a.navigatorFormulaSettings.rotation4[i]==baseline.rotation4[i]);
  for(int j=0;j<3;j++)if(i!=j)assert(a.navigatorFormulaSettings.rotation4[j]==before.rotation4[j]);
  assert(!a.navigatorResetValueButton.enabled&&!a.navigatorResetTarget);
 }
 item.tag=0;[a navigatorFormulaTypeChosen:item];verifyRotation(a,NO);
 [a.navigatorWindow close];puts("PASS: lighting preserves Navigator geometry and camera, preview receives new lighting, reset/3D/4D switches update native tab and controls.");
}return 0;}
