#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface LoadRenderProbe:AppDelegate
@property(nonatomic) int starts;
@property(nonatomic) RenderOptions submitted;
@end
@implementation LoadRenderProbe
- (void)beginRenderPath:(NSString *)path options:(RenderOptions)options {
 assert(self.formulaKnown&&[self.currentPath isEqual:path]);
 assert(self.calculationFields[0].intValue==options.width/MAX(1,options.oversampling));
 assert(self.calculationFields[1].intValue==options.height/MAX(1,options.oversampling));
 assert(self.formulaSettings.program.slots[0].kind==options.program.slots[0].kind);
 assert(!options.reuse_surface);self.starts++;self.submitted=options;
}
@end
int main(void){@autoreleasepool{[NSApplication sharedApplication];LoadRenderProbe *a=[LoadRenderProbe new];[a ensureWindow];[a.window orderOut:nil];RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));
 [a loadClipboardSettings:o path:@"example.m3i"];assert(a.starts==1&&a.parametersPendingRender);
 o.width=320;o.height=240;[a loadParameterSettings:o path:@"example.m3i" source:@"Animation keyframe"];assert(a.starts==2&&a.submitted.width==320);
 [a loadParameterSettings:o path:@"example.m3i" source:@"History"];assert(a.starts==3);
 [a renderPath:@"example.m3i"];NSDate *limit=[NSDate dateWithTimeIntervalSinceNow:10];while(a.starts<4&&limit.timeIntervalSinceNow>0)CFRunLoopRunInMode(kCFRunLoopDefaultMode,.01,YES);assert(a.starts==4&&a.submitted.width!=320);
 a.calculationFields[0].stringValue=@"160";a.calculationFields[1].stringValue=@"120";[a calculate:a.renderButton];assert(a.starts==5&&a.submitted.width==160&&a.submitted.height==120);
 puts("File, clipboard, animation and history loads populate controls before automatic rendering; edited parameters restart a full render.");}return 0;}
