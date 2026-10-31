#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface ParameterViewApp:AppDelegate
@property(nonatomic) NSInteger previews;
@end
@implementation ParameterViewApp
- (BOOL)readNavigatorFormulaValues{return YES;}
- (void)startNavigatorPreview{self.previews++;}
@end
int main(void){@autoreleasepool{[NSApplication sharedApplication];ParameterViewApp *a=[ParameterViewApp new];a.formulaKnown=YES;a.formulaSettings=(RenderOptions){.width=800,.height=600};RenderOptions f=a.formulaSettings;f.program.slots[0]=formula_slot_default(0);f.program.slots[0].count=1;a.navigatorFormulaSettings=f;
 a.moveStepField=[NSTextField new];a.moveStepField.doubleValue=.1;a.navigatorFarField=[NSTextField new];a.fixedZoomCheck=[NSButton checkboxWithTitle:@"" target:nil action:nil];a.navigatorZoomStepper=[NSStepper new];a.navigatorCamera=(CameraSettings){.axes={1,0,0,0,1,0,0,0,1},.origin={1,2,3},.zoom=2,.distance=32,.fov=30};a.navigatorLocalDistance=1;[a rebaseNavigatorSteps];CameraSettings camera=a.navigatorCamera;double step=a.moveStepField.doubleValue,far=a.navigatorFarField.doubleValue;
 for(int action=0;action<4;action++){
  if(action==0)[a navigatorFormulaEdited:nil];
  if(action==1){NSSlider *slider=[NSSlider sliderWithValue:3 minValue:1 maxValue:10 target:nil action:NULL];slider.tag=0;[a navigatorFormulaSlider:slider];}
  if(action==2)[a navigatorJuliaEdited:nil];
  if(action==3){NSMenuItem *item=[[NSMenuItem alloc]initWithTitle:@"SphereIFS" action:NULL keyEquivalent:@""];item.tag=125;[a navigatorFormulaTypeChosen:item];}
  [a adaptNavigatorDistance:.1*(action+1)];CameraSettings after=a.navigatorCamera;assert(!memcmp(&camera,&after,sizeof camera));assert(a.moveStepField.doubleValue==step&&a.navigatorFarField.doubleValue==far&&a.navigatorLocalDistance==1);
 }
 assert(a.previews==4);[a requestNavigatorPreview];[a adaptNavigatorDistance:.5];assert(a.navigatorCamera.zoom!=camera.zoom);puts("Formula and Julia previews preserve camera, far plane and steps; navigation still adapts distance.");}return 0;}
