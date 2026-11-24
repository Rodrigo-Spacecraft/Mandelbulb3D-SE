#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface GammaProbe : AppDelegate
@property(nonatomic) int updates;
@end
@implementation GammaProbe
- (void)queueLightingPreview {self.updates++;}
@end
int main(void){@autoreleasepool{
 [NSApplication sharedApplication];GammaProbe *app=[GammaProbe new];[app ensureWindow];[app.window orderOut:nil];RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));app.formulaSettings=o;[app showLighting:nil];[app.lightingWindow orderOut:nil];assert(app.gammaSlider&&app.gammaSlider.minValue==0&&app.gammaSlider.maxValue==63&&app.gammaSlider.doubleValue==o.gamma);assert(NSMinX(app.gammaSlider.frame)>NSMaxX(app.interpolationCheck.frame));
 app.reflectionsApplied=YES;app.gammaRepaint=YES;app.lightingRepaintRequested=YES;
 RenderOptions reflected=o;reflected.reflections.automatic=0;
 assert([app readReflections:&reflected]&&reflected.reflections.enabled&&!reflected.reflections.automatic);
 app.lightingRepaintRequested=NO;reflected=o;reflected.reflections.automatic=0;
 assert([app readReflections:&reflected]&&!reflected.reflections.enabled);
 [app requestLightingPreview];reflected=o;reflected.reflections.automatic=0;
 assert([app readReflections:&reflected]&&!reflected.reflections.enabled);
 app.formulaKnown=YES;[app showPostProcess:nil];[app populateReflections];[app.postWindow orderOut:nil];
 app.reflectionAutomatic.state=NSControlStateValueOff;app.reflectionsApplied=YES;app.gammaRepaint=YES;app.lightingRepaintRequested=YES;
 assert([app readReflections:&reflected]&&reflected.reflections.enabled&&!reflected.reflections.automatic);
 app.resettingReflections=YES;assert([app readReflections:&reflected]&&!reflected.reflections.enabled);app.resettingReflections=NO;
 app.lightingRepaintRequested=NO;assert([app readReflections:&reflected]&&!reflected.reflections.enabled);
 app.updates=0;
 setenv("MB3DX_TEMP_DIR","/private/tmp",1);
 NSData *first=nil;
 int values[]={0,32,63};for(int i=0;i<3;i++){
  app.gammaSlider.doubleValue=values[i];[app gammaChanged:app.gammaSlider];assert(app.gammaRepaint);assert(app.formulaSettings.gamma_override&&app.formulaSettings.gamma==values[i]&&app.updates==i+1);
  char path[]="/private/tmp/gamma-test-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);unlink(path);RenderOptions options=app.formulaSettings;options.width=32;options.height=24;options.threads=2;assert(write_scene_parameters(NULL,options,path,error));RenderOptions loaded;assert(read_scene_settings(path,&loaded,error)&&loaded.gamma_override&&loaded.gamma==values[i]);unlink(path);
  RenderResult r=render_scene_with_options("example.m3i",options);if(!r.rgba)fprintf(stderr,"Render failed: %s\n",r.error);assert(r.rgba);NSData *image=[NSData dataWithBytes:r.rgba length:r.stride*r.height];free(r.rgba);if(i==0)first=image;else assert(![first isEqual:image]);
 }
 RenderOptions a=app.formulaSettings,b=a;a.gamma=0;b.gamma=63;RenderOptions halfway=animation_interpolate(a,b,.5);assert(halfway.gamma_override&&halfway.gamma==31.5);assert(animationOptionsSize(offsetof(RenderOptions,gamma)));RenderOptions legacy=a;legacy.preserved_header_valid=1;uint32_t gammaBits=CFSwapInt32HostToLittle(17u<<23);memcpy(legacy.preserved_header+476,&gammaBits,4);RenderOptions migrated=animationUnpack([NSData dataWithBytes:&legacy length:offsetof(RenderOptions,gamma)]);assert(migrated.gamma_override&&migrated.gamma==17);
 [app setCalculating:YES];assert(!app.gammaSlider.enabled);[app setCalculating:NO];assert(app.gammaSlider.enabled);puts("Gamma UI, original header persistence, visible rendering, interpolation and old animation size passed");
 }return 0;}
