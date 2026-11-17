#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface PostResetProbe:AppDelegate
@property RenderOptions captured;
@property int renders;
@end
@implementation PostResetProbe
- (void)setCalculating:(BOOL)busy{(void)busy;}
- (void)positionWindowRightOfMain:(NSWindow *)window{(void)window;}
- (void)calculate:(id)sender{(void)sender;RenderOptions o=self.formulaSettings;assert([self readShadowSettings:&o]);assert([self readReflections:&o]);assert([self readDepthOfField:&o]);self.captured=o;self.renders++;}
@end
int main(){@autoreleasepool{
 [NSApplication sharedApplication];RenderOptions baseline;char error[512];assert(read_scene_settings("example.m3i",&baseline,error));PostResetProbe *a=[PostResetProbe new];a.formulaKnown=YES;a.formulaSettings=baseline;[a showPostProcess:nil];[a.postWindow orderOut:nil];
 // Read older settings without treating retired fields as translucency strength.
 NSUInteger prefix=6240;
 assert(animationOptionsSize(prefix));
 RenderOptions legacy=animationUnpack([NSData dataWithBytes:&baseline length:prefix]);
 assert(legacy.translucency_mode==1&&legacy.transmission_blur==1&&legacy.reflections.depth==baseline.reflections.depth);
 NSMutableData *experimental=[NSMutableData dataWithLength:prefix+40];
 [experimental replaceBytesInRange:NSMakeRange(0,prefix) withBytes:&baseline];
 int retiredValue=2;
 [experimental replaceBytesInRange:NSMakeRange(prefix+32,sizeof(retiredValue)) withBytes:&retiredValue];
 legacy=animationUnpack(experimental);
 assert(legacy.translucency_mode==1&&legacy.transmission_blur==1&&legacy.reflections.depth==baseline.reflections.depth);
 NSButton *button=[NSButton buttonWithTitle:@"Reset" target:nil action:nil];
 for(int automatic=0;automatic<=1;automatic++){
  RenderOptions initial=baseline;initial.shadows.hard_auto=initial.shadows.ambient_auto=automatic;initial.shadows.hard_enabled=initial.shadows.ambient_enabled=1;initial.reflections.automatic=initial.dof.automatic=automatic;initial.reflections.enabled=initial.dof.enabled=1;
  for(int effect=0;effect<4;effect++){
   a.formulaSettings=initial;[a populateShadowSettings];
   if(effect<2){button.tag=effect*2;[a postProcessAction:button];assert(!(effect?a.captured.shadows.ambient_enabled:a.captured.shadows.hard_enabled));assert((effect?a.captured.shadows.hard_enabled:a.captured.shadows.ambient_enabled)==1);assert(a.captured.shadows.hard_auto==automatic&&a.captured.shadows.ambient_auto==automatic);assert(!a.resettingHardShadows&&!a.resettingAmbientShadows);}
   else if(effect==2){button.tag=0;[a reflectionAction:button];assert(!a.captured.reflections.enabled&&a.captured.reflections.automatic==automatic);}
   else{button.tag=0;[a dofAction:button];assert(!a.formulaSettings.dof.enabled&&a.formulaSettings.dof.automatic==automatic);}
   assert(a.shadowAutoChecks[0].state==automatic&&a.shadowAutoChecks[1].state==automatic&&a.reflectionAutomatic.state==automatic&&a.dofAutomatic.state==automatic);
   RenderOptions next=initial;assert([a readShadowSettings:&next]);assert([a readReflections:&next]);assert([a readDepthOfField:&next]);
   assert((effect==0?next.shadows.hard_enabled:effect==1?next.shadows.ambient_enabled:effect==2?next.reflections.enabled:next.dof.enabled)==automatic);
  }
 }
 RenderOptions manual=baseline;
 manual.shadows.hard_auto=manual.shadows.ambient_auto=0;
 manual.reflections.automatic=manual.dof.automatic=0;
 for(int effect=0;effect<4;effect++){
  a.formulaSettings=manual;[a populateShadowSettings];
  button.tag=effect<2?effect*2+1:1;
  if(effect<2)[a postProcessAction:button];
  else if(effect==2)[a reflectionAction:button];
  else [a dofAction:button];
  RenderOptions now=a.captured;
  assert(now.shadows.hard_enabled==(effect==0)&&now.shadows.ambient_enabled==(effect==1));
  assert(now.reflections.enabled==(effect==2)&&now.dof.enabled==(effect==3));
  a.formulaSettings=now;[a populateShadowSettings];
  RenderOptions next=now;
  assert([a readShadowSettings:&next]&&[a readReflections:&next]&&[a readDepthOfField:&next]);
  assert(!next.shadows.hard_enabled&&!next.shadows.ambient_enabled&&!next.reflections.enabled&&!next.dof.enabled);
 }
 [a.postWindow close];puts("PASS: Calculate now is one-shot and all four resets preserve automatic checkboxes on/off, clear only the selected effect, and retain automatic calculation for subsequent renders");
}return 0;}
