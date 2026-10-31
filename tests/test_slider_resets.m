#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface ResetProbe:NSObject
@property(nonatomic) int actions;
@end
@implementation ResetProbe
- (void)changed:(id)sender {(void)sender;self.actions++;}
@end
int main(void){@autoreleasepool{
    [NSApplication sharedApplication];ResetProbe *probe=[ResetProbe new];
    LiveSlider *slider=[LiveSlider sliderWithValue:3 minValue:2 maxValue:4 target:probe action:@selector(changed:)];
    __block int starts=0,finishes=0;slider.started=^{starts++;};slider.finished=^{finishes++;};slider.commandResetValue=@0;
    NSEvent *click=[NSEvent mouseEventWithType:NSEventTypeLeftMouseDown location:NSZeroPoint modifierFlags:NSEventModifierFlagCommand timestamp:0 windowNumber:0 context:nil eventNumber:0 clickCount:1 pressure:1];
    [slider mouseDown:click];assert(slider.doubleValue==0&&slider.minValue==0&&probe.actions==1&&starts==1&&finishes==1);
    slider.minValue=0;slider.maxValue=63;slider.doubleValue=57;slider.commandResetValue=@32;[slider mouseDown:click];assert(slider.doubleValue==32&&probe.actions==2&&starts==2&&finishes==2);
    slider.enabled=NO;slider.doubleValue=50;[slider mouseDown:click];assert(slider.doubleValue==50&&probe.actions==2);
    RenderOptions options;char error[512];assert(read_scene_settings("example.m3i",&options,error));options.width=options.height=16;options.shadows_override=1;
    unsigned previous=0;NSString *path=@"/private/tmp/ambient-strength276.m3i";
    for(int i=0;i<=500;i+=5){options.shadows.ambient_strength=i/100.;unlink(path.fileSystemRepresentation);if(!write_scene_parameters(NULL,options,path.fileSystemRepresentation,error)){fprintf(stderr,"%s\n",error);abort();}NSData *data=[NSData dataWithContentsOfFile:path];const unsigned char *bytes=data.bytes;unsigned encoded=bytes[472];assert(encoded>=previous);previous=encoded;if(i==500)assert(encoded==255);}
    [[NSFileManager defaultManager]removeItemAtPath:path error:nil];
    puts("Cmd-click resets, callbacks and disabled controls passed; ambient strength remains monotonic through its maximum.");
}return 0;}
