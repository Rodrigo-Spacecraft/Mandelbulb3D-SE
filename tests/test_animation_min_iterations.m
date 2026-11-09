#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface MinIterationProbe:AppDelegate
@property(nonatomic,strong) NSURL *testFolder;
@end
@implementation MinIterationProbe
- (NSURL *)applicationTemporaryFolderURL{return self.testFolder;}
@end
int main(int argc,char **argv){@autoreleasepool{
 assert(argc==2);[NSApplication sharedApplication];setenv("MB3DX_GPU","cpu",1);
 MinIterationProbe *a=[MinIterationProbe new];a.testFolder=[NSURL fileURLWithPath:[NSTemporaryDirectory() stringByAppendingPathComponent:NSUUID.UUID.UUIDString] isDirectory:YES];assert([NSFileManager.defaultManager createDirectoryAtURL:a.testFolder withIntermediateDirectories:YES attributes:nil error:nil]);a.animationTemporarySources=[NSMutableSet set];
 NSString *error=nil,*warning=nil;NSData *data=[NSData dataWithContentsOfFile:[NSString stringWithUTF8String:argv[1]]];NSDictionary *project=[a animationReadM3A:data warning:&warning error:&error];if(!project){fprintf(stderr,"%s\n",error.UTF8String);return 1;}
 NSArray *keys=project[@"keys"];assert(keys.count==41);RenderOptions o=animationUnpack(keys[8][@"settings"]);assert(o.program.min_iterations==10&&o.iterations==25);
 NSString *path=[a animationRestoreSource:keys[8][@"source"]];assert(path);o.width=64;o.height=48;o.oversampling=o.viewing=1;o.threads=4;o.reuse_surface=0;
 RenderResult result=render_scene_with_options(path.fileSystemRepresentation,o);if(!result.rgba){fprintf(stderr,"%s\n",result.error);return 2;}assert(result.settings.program.min_iterations==10);free(result.rgba);
 char message[512];NSString *saved=[a.testFolder.path stringByAppendingPathComponent:@"saved.m3i"];assert(write_scene_parameters(path.fileSystemRepresentation,o,saved.fileSystemRepresentation,message));RenderOptions roundtrip;assert(read_scene_settings(saved.fileSystemRepresentation,&roundtrip,message));assert(roundtrip.program.min_iterations==10);
 NSMutableData *invalid=[data mutableCopy];unsigned char *p=invalid.mutableBytes;NSUInteger minOffset=284+8*1988+12+135;p[minOffset]=26;p[minOffset+1]=0;error=nil;assert(![a animationReadM3A:invalid warning:&warning error:&error]);assert([error containsString:@"Keyframe 9"]);
 [NSFileManager.defaultManager removeItemAtURL:a.testFolder error:nil];puts("PASS: all 41 keyframes load; minimum 10 preserved, rendered and saved; invalid minimum above maximum rejected.");
}return 0;}
