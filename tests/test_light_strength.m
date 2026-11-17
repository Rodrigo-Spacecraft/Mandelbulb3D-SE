#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface StrengthProbe:AppDelegate
@end
@implementation StrengthProbe
- (void)requestLightingPreview{}
@end
int main(){@autoreleasepool{
 [NSApplication sharedApplication];StrengthProbe *a=[StrengthProbe new];[a ensureWindow];[a.window orderOut:nil];RenderOptions baseline;char error[512];assert(read_scene_settings("example.m3i",&baseline,error));a.formulaKnown=YES;a.formulaSettings=baseline;[a showLighting:nil];[a.lightingWindow orderOut:nil];
 assert(a.lightStrengthSteppers.count==6);
 for(int i=0;i<6;i++){
  NSTextField *field=a.lightControls[i][3];NSStepper *step=a.lightStrengthSteppers[i];assert(field.editable&&field.selectable&&!field.formatter&&step.enabled);assert(NSMaxX(field.frame)<NSMinX(step.frame));
  for(NSString *text in @[@"1e-9",@"2.5E-5",@"0.0000001"]){
   field.stringValue=text;RenderOptions o=baseline;assert([a readLights:&o]);double initial=text.doubleValue;assert(o.lights[i].amplitude==initial);
   step.integerValue=1;[a stepLightStrength:step];assert(step.integerValue==0);assert(fabs(field.doubleValue-initial*1.414)<initial*1e-12);
   step.integerValue=-1;[a stepLightStrength:step];assert(fabs(field.doubleValue-initial*1.414*.707)<initial*1e-12);assert([a readLights:&o]);assert(o.lights[i].amplitude==field.doubleValue);
  }
  field.stringValue=@"0";step.integerValue=-1;[a stepLightStrength:step];assert(field.doubleValue==0);
  field.stringValue=@"1e10";step.integerValue=1;[a stepLightStrength:step];assert(field.doubleValue==1e10);
  for(NSString *text in @[@"nan",@"1e",@"-1",@"1e11"]){field.stringValue=text;RenderOptions o=baseline;assert(![a readLights:&o]);step.integerValue=1;[a stepLightStrength:step];assert([field.stringValue isEqual:text]);}
  field.stringValue=@"1";
 }
 [NSObject cancelPreviousPerformRequestsWithTarget:a];[a setCalculating:YES];for(NSStepper *s in a.lightStrengthSteppers)assert(!s.enabled);[a setCalculating:NO];for(NSStepper *s in a.lightStrengthSteppers)assert(s.enabled);
 [a.lightingWindow close];a.window.delegate=nil;[a.window close];puts("PASS: six editable scientific-notation fields, original 1.414/0.707 steps, small-value precision, bounds, invalid input, busy state");
}return 0;}
