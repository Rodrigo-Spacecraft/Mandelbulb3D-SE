#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
int main(void){@autoreleasepool{
[NSApplication sharedApplication];AppDelegate *a=[AppDelegate new];
a.moveStepField=[NSTextField new];a.navigatorFarField=[NSTextField new];a.fixedZoomCheck=[NSButton checkboxWithTitle:@"" target:nil action:nil];a.navigatorZoomStepper=[NSStepper new];
a.formulaSettings=(RenderOptions){.width=800,.height=600};
for(int scale=-9;scale<=9;scale+=3){
 double d=pow(10,scale);a.navigatorCamera=(CameraSettings){.zoom=1,.distance=32};a.navigatorLocalDistance=0;a.moveStepField.doubleValue=.1;[a rebaseNavigatorSteps];a.navigatorMoveFraction=.1;a.navigatorDistanceAdapted=NO;
 [a adaptNavigatorDistance:d];assert(fabs(a.moveStepField.doubleValue/d-.1)<1e-10);assert(fabs(a.navigatorCamera.zoom*d-2.5)<1e-10);
 a.navigatorDistanceAdapted=NO;[a adaptNavigatorDistance:d*.5];assert(fabs(a.moveStepField.doubleValue/(d*.5)-.1)<1e-10);assert(fabs(a.navigatorCamera.zoom*(d*.5)-2.5)<1e-10);double planeRadius=1.06725*hypot(800,600)/(800*a.navigatorCamera.zoom);assert(planeRadius<d*.5);
 double step=a.moveStepField.doubleValue,zoom=a.navigatorCamera.zoom;
 a.fixedZoomCheck.state=NSControlStateValueOn;[a fixedZoomChanged:nil];assert(a.moveStepField.doubleValue==step&&a.navigatorCamera.zoom==zoom);
 a.fixedZoomCheck.state=NSControlStateValueOff;[a fixedZoomChanged:nil];assert(a.moveStepField.doubleValue==step&&a.navigatorCamera.zoom==zoom);
 assert(fabs(a.navigatorMoveFraction-.1)<1e-10);
}
for(int i=0;i<3;i++){a.navigatorCamera=(CameraSettings){.zoom=pow(10,-i*3),.distance=32};a.navigatorLocalDistance=1;a.moveStepField.doubleValue=.1;[a rebaseNavigatorSteps];a.navigatorDistanceAdapted=NO;[a adaptNavigatorDistance:1];assert(fabs(a.navigatorCamera.zoom-2.5)<1e-12);}
puts("Auto-zoom matches original absolute DE rule across scales and starting zooms, keeps the near plane within clearance, and preserves fixed-mode toggles.");
}return 0;}
