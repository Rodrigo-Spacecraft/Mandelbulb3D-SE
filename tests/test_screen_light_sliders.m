#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface ScreenLightProbe : AppDelegate
@end
@implementation ScreenLightProbe
- (void)requestLightingPreview {}
@end
int main(void){@autoreleasepool{
 [NSApplication sharedApplication];ScreenLightProbe *app=[ScreenLightProbe new];[app ensureWindow];[app.window orderOut:nil];RenderOptions settings;char error[512];assert(read_scene_settings("example.m3i",&settings,error));app.formulaSettings=settings;[app showLighting:nil];[app.lightingWindow orderOut:nil];[(NSPopUpButton *)app.lightControls[0][1] selectItemAtIndex:1];
 for(int orientation=0;orientation<3;orientation++){
  CameraSettings camera={.axes={1,0,0,0,1,0,0,0,1},.origin={.3,-.7,1.1},.distance=3,.zoom=1,.fov=30};camera_turn(&camera,orientation*43,orientation*27,orientation*39);settings.camera=camera;app.formulaSettings=settings;
  for(int axis=0;axis<3;axis++){
   double before[]={.7,.2,-.4};for(int k=0;k<3;k++)[(NSTextField *)app.lightControls[0][4+k] setDoubleValue:before[k]];
   [app syncLightSliders];for(int k=0;k<3;k++)assert(fabs([(NSTextField *)app.lightControls[0][4+k] doubleValue]-before[k])<1e-12);
   NSSlider *slider=app.lightSliders[0][axis];double start=slider.doubleValue;slider.doubleValue=start+.125;[app lightSliderChanged:slider];
   for(int projected=0;projected<3;projected++){double delta=0;for(int k=0;k<3;k++)delta+=([(NSTextField *)app.lightControls[0][4+k] doubleValue]-before[k])*camera.axes[3*projected+k];assert(fabs(delta-(projected==axis?(axis==1?-.125:.125):0))<1e-12);}
   [app syncLightSliders];assert(fabs(slider.doubleValue-start-.125)<1e-12);
  }
 }
 for(int axis=0;axis<3;axis++)for(int edge=0;edge<2;edge++){
  [app syncLightSliders];LiveSlider *slider=(LiveSlider *)app.lightSliders[0][axis];double radius=(slider.maxValue-slider.minValue)*.5,value=edge?slider.maxValue:slider.minValue;slider.doubleValue=slider.trackingValue=value;[app lightSliderChanged:slider];double position[3];for(int k=0;k<3;k++)position[k]=[(NSTextField *)app.lightControls[0][4+k] doubleValue];[app positionalLightSliderReleased:slider];assert(slider.minValue==value-radius&&slider.maxValue==value+radius&&slider.doubleValue==value);[app syncLightSliders];assert(fabs(slider.minValue-(value-radius))<1e-12&&fabs(slider.maxValue-(value+radius))<1e-12);for(int k=0;k<3;k++)assert([(NSTextField *)app.lightControls[0][4+k] doubleValue]==position[k]);double low=slider.minValue,high=slider.maxValue;slider.trackingValue=slider.doubleValue;[app positionalLightSliderReleased:slider];assert(slider.minValue==low&&slider.maxValue==high);
 }
 [(NSPopUpButton *)app.lightControls[0][1] selectItemAtIndex:0];[(NSTextField *)app.lightControls[0][4] setDoubleValue:30];[app syncLightSliders];assert(app.lightSliders[0][0].doubleValue==-30);app.lightSliders[0][0].doubleValue=-45;[app lightSliderChanged:app.lightSliders[0][0]];assert([(NSTextField *)app.lightControls[0][4] doubleValue]==45);
 puts("Positional sliders follow screen axes through yaw, pitch and roll; endpoint releases recenter without moving lights, retain ranges after sync, and leave interior releases and directional sliders unchanged");
 }return 0;}
