#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface ResetProbe : AppDelegate
@property(nonatomic) int repaints;
@end
@implementation ResetProbe
- (void)finishLightingSlider {self.repaints++;}
- (void)requestLightingPreview {}
@end
int main(void){@autoreleasepool{
[NSApplication sharedApplication];ResetProbe *a=[ResetProbe new];[a ensureWindow];[a.window orderOut:nil];RenderOptions o;char e[512];assert(read_scene_settings("example.m3i",&o,e));o.width=64;o.height=48;o.threads=2;o.gamma_override=1;o.gamma=17;o.reflections.automatic=1;o.object.stops[0].diffuse[0]=1;o.object.stops[0].diffuse[1]=0;o.preserved_header[439]|=1;a.formulaSettings=o;a.formulaKnown=YES;[a showLighting:nil];[a.lightingWindow orderOut:nil];assert(a.resetLightingButton.superview==a.saveLightingButton.superview);assert(NSMinX(a.resetLightingButton.frame)>NSMaxX(a.saveLightingButton.frame));assert(NSMaxX(a.resetLightingButton.frame)<NSMinX(a.lightingUndoButton.frame));
a.lightingUndoHistory=nil;[a recordLightingRepaint:o];[a resetLighting:nil];RenderOptions n=a.formulaSettings;assert(a.repaints==1);assert(n.gamma==32&&n.fog.strength==53&&n.ambient.depth==0);assert(n.object.map.disabled&&!n.object.cycling&&!n.object.orbit_trap&&n.object.z_variation==0);assert(!n.preserved_header[816]&&!(n.preserved_header[439]&1));assert(n.reflections.automatic==o.reflections.automatic);assert(!memcmp(&n.camera,&o.camera,sizeof n.camera)&&!memcmp(&n.program,&o.program,sizeof n.program));
for(int i=0;i<10;i++)for(int c=0;c<3;c++)assert(n.object.stops[i].diffuse[c]==.5&&n.object.stops[i].specular[c]==1);for(int i=0;i<6;i++){assert(n.lights[i].option==(i?1:0));for(int c=0;c<3;c++)assert(n.lights[i].color[c]==1);}
RenderResult r=render_scene_with_options("example.m3i",n);assert(r.rgba);for(int y=0;y<r.height;y++)for(int x=0;x<r.width;x++){unsigned char *p=r.rgba+y*r.stride+x*4;assert(p[0]==p[1]&&p[1]==p[2]);}free(r.rgba);
[a recordLightingRepaint:n];[a undoLighting:nil];assert(a.formulaSettings.gamma==17&&a.formulaSettings.object.stops[0].diffuse[0]==1&&a.formulaSettings.object.stops[0].diffuse[1]==0);assert(a.formulaSettings.preserved_header[439]&1);[a setCalculating:YES];assert(!a.resetLightingButton.enabled);[a setCalculating:NO];assert(a.resetLightingButton.enabled);puts("Neutral lighting reset renders monochrome, preserves geometry/automatic flags, and supports Undo");
}return 0;}
