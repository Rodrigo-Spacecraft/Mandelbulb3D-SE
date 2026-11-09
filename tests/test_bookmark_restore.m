#import <Cocoa/Cocoa.h>
#import <objc/runtime.h>
#include <assert.h>
#include <stdatomic.h>
static NSDictionary *saved;
@interface BookmarkDefaults:NSObject
+ (instancetype)standardUserDefaults;
- (NSDictionary *)dictionaryForKey:(NSString *)key;
- (void)setObject:(id)value forKey:(NSString *)key;
@end
@implementation BookmarkDefaults
+ (instancetype)standardUserDefaults {static BookmarkDefaults *d;static dispatch_once_t once;dispatch_once(&once,^{d=[self new];});return d;}
- (NSDictionary *)dictionaryForKey:(NSString *)key{(void)key;return saved;}
- (void)setObject:(id)value forKey:(NSString *)key{(void)value;(void)key;assert(0&&"Restoration must not rewrite saved bookmarks");}
@end
#define NSUserDefaults BookmarkDefaults
#import "../file_access.h"
#undef NSUserDefaults
static dispatch_semaphore_t entered,proceed,finished;
static BOOL blockResolver;
static atomic_int starts,stops;
@interface NSURL (BookmarkProbe)
+ (NSURL *)probeResolve:(NSData *)data options:(NSURLBookmarkResolutionOptions)options relativeToURL:(NSURL *)base bookmarkDataIsStale:(BOOL *)stale error:(NSError **)error;
- (BOOL)probeStart;
- (void)probeStop;
@end
@implementation NSURL (BookmarkProbe)
+ (NSURL *)probeResolve:(NSData *)data options:(NSURLBookmarkResolutionOptions)options relativeToURL:(NSURL *)base bookmarkDataIsStale:(BOOL *)stale error:(NSError **)error{
 (void)data;(void)base;(void)stale;(void)error;assert(!NSThread.isMainThread);assert(options&NSURLBookmarkResolutionWithoutUI);assert(options&NSURLBookmarkResolutionWithoutMounting);
 dispatch_semaphore_signal(entered);if(blockResolver)dispatch_semaphore_wait(proceed,DISPATCH_TIME_FOREVER);
 dispatch_semaphore_signal(finished);return [NSURL fileURLWithPath:@"/external/scene.m3i"];
}
- (BOOL)probeStart{atomic_fetch_add(&starts,1);return YES;}
- (void)probeStop{atomic_fetch_add(&stops,1);}
@end
int main(){@autoreleasepool{
 setenv("APP_SANDBOX_CONTAINER_ID","bookmark-test",1);
 saved=@{@"/external/scene.m3i":[NSData dataWithBytes:"bookmark" length:8]};NSDictionary *original=saved;
 method_exchangeImplementations(class_getClassMethod(NSURL.class,@selector(URLByResolvingBookmarkData:options:relativeToURL:bookmarkDataIsStale:error:)),class_getClassMethod(NSURL.class,@selector(probeResolve:options:relativeToURL:bookmarkDataIsStale:error:)));
 method_exchangeImplementations(class_getInstanceMethod(NSURL.class,@selector(startAccessingSecurityScopedResource)),class_getInstanceMethod(NSURL.class,@selector(probeStart)));
 method_exchangeImplementations(class_getInstanceMethod(NSURL.class,@selector(stopAccessingSecurityScopedResource)),class_getInstanceMethod(NSURL.class,@selector(probeStop)));
 entered=dispatch_semaphore_create(0);proceed=dispatch_semaphore_create(0);finished=dispatch_semaphore_create(0);
 [NSThread currentThread];[NSProcessInfo processInfo];
 [NSApplication sharedApplication];
 blockResolver=YES;restoreUserFileScopes();
 assert(dispatch_semaphore_wait(entered,dispatch_time(DISPATCH_TIME_NOW,NSEC_PER_SEC))==0);
 // The caller continues while the bookmark service is blocked.
 assert(dispatch_semaphore_wait(finished,DISPATCH_TIME_NOW)!=0);assert(saved==original);
 dispatch_semaphore_signal(proceed);
 assert(dispatch_semaphore_wait(finished,dispatch_time(DISPATCH_TIME_NOW,NSEC_PER_SEC))==0);
 BOOL active=NO;for(int i=0;i<1000&&!active;i++){@synchronized(activeFileScopes()){active=activeFileScopes().count==1;}if(!active)[NSThread sleepForTimeInterval:.001];}assert(active);assert(atomic_load(&starts)==1);
 releaseUserFileScopes();assert(atomic_load(&stops)==1);assert(saved==original);
 puts("PASS: blocked resolver does not block caller; saved bookmarks remain unchanged; resolved access restored and released");
}return 0;}
