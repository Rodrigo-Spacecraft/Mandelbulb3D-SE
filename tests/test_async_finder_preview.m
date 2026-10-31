#define main app_main_unused
#import "../App.m"
#undef main
#import <objc/runtime.h>
#include <assert.h>
static dispatch_semaphore_t started,releaseIcon,finished;
static BOOL interceptedIcon(id workspace,SEL selector,NSImage *icon,NSString *path,NSWorkspaceIconCreationOptions options){
    (void)workspace;(void)selector;(void)icon;(void)path;(void)options;
    assert(!NSThread.isMainThread);dispatch_semaphore_signal(started);
    dispatch_semaphore_wait(releaseIcon,DISPATCH_TIME_FOREVER);dispatch_semaphore_signal(finished);return YES;
}
int main(void){@autoreleasepool{
    [NSApplication sharedApplication];started=dispatch_semaphore_create(0);releaseIcon=dispatch_semaphore_create(0);finished=dispatch_semaphore_create(0);
    Method method=class_getInstanceMethod(NSWorkspace.class,@selector(setIcon:forFile:options:));IMP original=method_setImplementation(method,(IMP)interceptedIcon);
    NSString *path=[@"/private/tmp/finder-preview-" stringByAppendingString:NSUUID.UUID.UUIDString];int fd=open(path.fileSystemRepresentation,O_CREAT|O_EXCL|O_WRONLY,0600);assert(fd>=0);close(fd);
    NSBitmapImageRep *bitmap=[[NSBitmapImageRep alloc]initWithBitmapDataPlanes:NULL pixelsWide:16 pixelsHigh:16 bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSDeviceRGBColorSpace bytesPerRow:64 bitsPerPixel:32];memset(bitmap.bitmapData,255,16*64);
    scheduleSceneFinderPreview(path,bitmap);
    assert(dispatch_semaphore_wait(started,dispatch_time(DISPATCH_TIME_NOW,5*NSEC_PER_SEC))==0);
    // Finder is deliberately blocked, but the caller has already returned.
    dispatch_semaphore_signal(releaseIcon);assert(dispatch_semaphore_wait(finished,dispatch_time(DISPATCH_TIME_NOW,5*NSEC_PER_SEC))==0);
    method_setImplementation(method,original);unlink(path.fileSystemRepresentation);
    puts("Slow Finder metadata runs away from the UI thread and does not block the save caller.");
}return 0;}
