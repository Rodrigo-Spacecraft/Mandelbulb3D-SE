#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface PreviewSelection : NSObject
@property(nonatomic,strong) NSURL *URL;
@end
@implementation PreviewSelection
@end
int main(void){@autoreleasepool{
 [NSApplication sharedApplication];SceneOpenPreview *preview=[SceneOpenPreview new];PreviewSelection *selection=[PreviewSelection new];NSString *path=[@"/private/tmp/open-preview-" stringByAppendingString:NSUUID.UUID.UUIDString];
 RenderOptions settings;char error[512];assert(read_scene_settings("example.m3i",&settings,error));settings.width=32;settings.height=24;unsigned char rgba[32*24*4];for(int i=0;i<32*24;i++){rgba[i*4]=200;rgba[i*4+1]=80;rgba[i*4+2]=30;rgba[i*4+3]=255;}
 assert(write_scene_parameters_with_preview(NULL,settings,path.fileSystemRepresentation,rgba,32,24,32*4,error));selection.URL=[NSURL fileURLWithPath:path];[preview panelSelectionDidChange:selection];
 NSDate *deadline=[NSDate dateWithTimeIntervalSinceNow:5];while(!preview.image.image&&deadline.timeIntervalSinceNow>0)CFRunLoopRunInMode(kCFRunLoopDefaultMode,.01,YES);assert(preview.image.image&&[preview.caption.stringValue isEqual:path.lastPathComponent]);
 // Remove the native extension: original .m3i files end after fullSizeImage.
 assert(!truncate(path.fileSystemRepresentation,840+32*24*22+1136));
 NSBitmapImageRep *legacy=historyBitmap(path,320);assert(legacy&&legacy.pixelsWide==32&&legacy.pixelsHigh==24);
 assert(legacy.bitmapData[0]==200&&legacy.bitmapData[1]==80&&legacy.bitmapData[2]==30);
 NSString *parameters=[path stringByAppendingString:@"-params"];assert(write_scene_parameters(NULL,settings,parameters.fileSystemRepresentation,error));assert(!historyBitmap(parameters,320));unlink(parameters.fileSystemRepresentation);
 selection.URL=nil;[preview panelSelectionDidChange:selection];assert(!preview.image.image);unlink(path.fileSystemRepresentation);
 AppDelegate *app=[AppDelegate new];[app ensureWindow];assert([app.openM3IButton.title isEqual:@"Open .m3i"]);assert(!NSIntersectsRect(app.openM3IButton.frame,app.animationButton.frame));[app setCalculating:YES];assert(!app.openM3IButton.enabled);[app setCalculating:NO];assert(app.openM3IButton.enabled);[app.window orderOut:nil];puts("Open button and embedded dialog preview passed");
 }return 0;}
