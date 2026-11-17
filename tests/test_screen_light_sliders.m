#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface ScreenLightProbe : AppDelegate
@end
@implementation ScreenLightProbe
- (void)requestLightingPreview {}
@end
static double originalMovement(CameraSettings camera,int w,int h,const double position[3],double toward[3]){
 double pixel=2.1345/(camera.zoom*w),angle=(camera.optic==2?180:camera.fov)*M_PI/180;
 double viewPlaneOffset=camera.optic==2?0:pixel*h*.5*cos(angle*.5)/fmax(.01,sin(angle*.5));
 double length=0;for(int k=0;k<3;k++){toward[k]=position[k]-camera.origin[k]+camera.axes[6+k]*viewPlaneOffset;length+=toward[k]*toward[k];}length=sqrt(length);for(int k=0;k<3;k++)toward[k]=length?toward[k]/length:camera.axes[6+k];
 return (pixel+length*sin(angle/h))*hypot(w,h)*.0025;
}
int main(void){@autoreleasepool{
 [NSApplication sharedApplication];ScreenLightProbe *app=[ScreenLightProbe new];[app ensureWindow];[app.window orderOut:nil];RenderOptions settings;char error[512];assert(read_scene_settings("example.m3i",&settings,error));app.formulaSettings=settings;[app showLighting:nil];[app.lightingWindow orderOut:nil];[(NSPopUpButton *)app.lightControls[0][1] selectItemAtIndex:1];
 for(int orientation=0;orientation<3;orientation++)for(int zoom=0;zoom<3;zoom++)for(int optic=0;optic<3;optic++){
  CameraSettings camera={.axes={1,0,0,0,1,0,0,0,1},.origin={.3,-.7,1.1},.distance=3,.zoom=pow(10,zoom),.fov=30,.optic=optic};camera_turn(&camera,orientation*43,orientation*27,orientation*39);settings.camera=camera;app.formulaSettings=settings;
  for(int axis=0;axis<3;axis++){
   double before[]={.7,.2,-.4};for(int k=0;k<3;k++)[(NSTextField *)app.lightControls[0][4+k] setDoubleValue:before[k]];
   [app syncLightSliders];LiveSlider *slider=(LiveSlider *)app.lightSliders[0][axis];double start=slider.doubleValue;double toward[3],scale=originalMovement(camera,settings.width,settings.height,before,toward);
   slider.doubleValue=start+2;[app lightSliderChanged:slider];
   for(int k=0;k<3;k++){double expected=before[k]+2*scale*(axis==1?-1:1)*(axis==2?toward[k]:camera.axes[3*axis+k]);assert(fabs([(NSTextField *)app.lightControls[0][4+k] doubleValue]-expected)<1e-11);}
   [app syncLightSliders];assert(slider.doubleValue==start+2);double position[3];for(int k=0;k<3;k++)position[k]=[(NSTextField *)app.lightControls[0][4+k] doubleValue];slider.trackingValue=slider.doubleValue;[app positionalLightSliderReleased:slider];assert(slider.doubleValue==start+2);for(int k=0;k<3;k++)assert([(NSTextField *)app.lightControls[0][4+k] doubleValue]==position[k]);
  }
 }
 // At the view plane, zooming by ten scales movement by precisely one tenth.
 CameraSettings camera={.axes={1,0,0,0,1,0,0,0,1},.zoom=1,.fov=30};double zero[3]={0},view[3];double a=originalMovement(camera,640,480,zero,view);camera.zoom=10;double b=originalMovement(camera,640,480,zero,view);assert(fabs(a/b-10)<1e-12);
 for(int axis=0;axis<3;axis++)for(int edge=0;edge<2;edge++){
  [app syncLightSliders];LiveSlider *slider=(LiveSlider *)app.lightSliders[0][axis];double radius=(slider.maxValue-slider.minValue)*.5,value=edge?slider.maxValue:slider.minValue;slider.doubleValue=slider.trackingValue=value;[app lightSliderChanged:slider];double position[3];for(int k=0;k<3;k++)position[k]=[(NSTextField *)app.lightControls[0][4+k] doubleValue];[app positionalLightSliderReleased:slider];assert(slider.minValue==value-radius&&slider.maxValue==value+radius&&slider.doubleValue==value);[app syncLightSliders];assert(slider.doubleValue==value&&slider.minValue==value-radius&&slider.maxValue==value+radius);for(int k=0;k<3;k++)assert([(NSTextField *)app.lightControls[0][4+k] doubleValue]==position[k]);
 }
 [(NSPopUpButton *)app.lightControls[0][1] selectItemAtIndex:0];[(NSTextField *)app.lightControls[0][4] setDoubleValue:30];[app syncLightSliders];assert(app.lightSliders[0][0].doubleValue==-30);app.lightSliders[0][0].doubleValue=-45;[app lightSliderChanged:app.lightSliders[0][0]];assert([(NSTextField *)app.lightControls[0][4] doubleValue]==45);
 puts("PASS: original view-scaled movement for all axes, rotations, zooms, optics; Z follows camera-to-light line; only endpoint releases recenter; directional angles unchanged");
 }return 0;}
