#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface AssetFolderProbe:AppDelegate
@property(nonatomic,copy) NSString *fixtureRoot;
@end
@implementation AssetFolderProbe
- (NSURL *)applicationMapsFolderURL {return [NSURL fileURLWithPath:[self.fixtureRoot stringByAppendingPathComponent:@"Maps"] isDirectory:YES];}
@end
int main(void){@autoreleasepool{[NSApplication sharedApplication];AssetFolderProbe *a=[AssetFolderProbe new];a.fixtureRoot=[@"/private/tmp" stringByAppendingPathComponent:NSUUID.UUID.UUIDString];[a ensureWindow];[a.window orderOut:nil];BOOL directory=NO;assert([NSFileManager.defaultManager fileExistsAtPath:[a applicationMapsFolderURL].path isDirectory:&directory]&&directory);assert([NSFileManager.defaultManager fileExistsAtPath:[a applicationBackgroundsFolderURL].path isDirectory:&directory]&&directory);assert(!strcmp(getenv("MB3DX_BACKGROUND_DIR"),[a applicationBackgroundsFolderURL].fileSystemRepresentation));NSView *panel=a.animationButton.superview;int found=0;for(NSView *v in panel.subviews)if([v isKindOfClass:NSButton.class]){NSButton *b=(NSButton *)v;if([b.title isEqual:@"Open Map Folder"]||[b.title isEqual:@"Open Bkgnd Folder"]){assert(NSMaxX(b.frame)<=panel.bounds.size.width);found++;}}assert(found==2);NSBitmapImageRep *bitmap=[panel bitmapImageRepForCachingDisplayInRect:panel.bounds];[panel cacheDisplayInRect:panel.bounds toBitmapImageRep:bitmap];[[bitmap representationUsingType:NSBitmapImageFileTypePNG properties:@{}]writeToFile:@"/private/tmp/assets202.png" atomically:YES];[NSFileManager.defaultManager removeItemAtPath:a.fixtureRoot error:nil];puts("Launch creates Maps and Backgrounds, configures engine paths, and shows both folder buttons.");}return 0;}
