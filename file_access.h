/* Sandboxed access is limited to the container and explicit user selections.
 * Keep scopes alive across asynchronous render/save jobs; remember grants for
 * later launches. Raw paths imported from scene files never create grants. */
#pragma once
static BOOL appSandboxBuild(void){return [NSBundle.mainBundle.infoDictionary[@"M3DAppSandboxed"] boolValue]||NSProcessInfo.processInfo.environment[@"APP_SANDBOX_CONTAINER_ID"].length;}
static NSMutableDictionary<NSString *,NSURL *> *activeFileScopes(void){static NSMutableDictionary *scopes;static dispatch_once_t once;dispatch_once(&once,^{scopes=[NSMutableDictionary new];});return scopes;}
static BOOL containerFileURL(NSURL *url){NSString *home=[NSHomeDirectory() stringByAppendingString:@"/"];return [url.path hasPrefix:home]||[url.path isEqual:NSHomeDirectory()]||[url.path hasPrefix:[NSBundle.mainBundle.bundlePath stringByAppendingString:@"/"]];}
static void retainUserFileSelection(NSURL *url){
    if(!appSandboxBuild()||!url.isFileURL||containerFileURL(url))return;
    NSMutableDictionary *scopes=activeFileScopes();
    if(!scopes[url.path]&&[url startAccessingSecurityScopedResource])scopes[url.path]=url;
    // Resolving volume identity for a bookmark can block on a network share.
    // Keep the active scope immediately; serialize persistence away from the UI.
    static dispatch_queue_t bookmarks;static dispatch_once_t once;dispatch_once(&once,^{bookmarks=dispatch_queue_create("com.greenoak.m3dse.bookmarks",DISPATCH_QUEUE_SERIAL);});
    dispatch_async(bookmarks,^{@autoreleasepool{
        NSError *error=nil;NSData *bookmark=[url bookmarkDataWithOptions:NSURLBookmarkCreationWithSecurityScope includingResourceValuesForKeys:nil relativeToURL:nil error:&error];
        if(bookmark){NSMutableDictionary *saved=[[NSUserDefaults.standardUserDefaults dictionaryForKey:@"UserFileScopes.v1"] mutableCopy]?:[NSMutableDictionary new];saved[url.path]=bookmark;while(saved.count>128){NSString *old=saved.allKeys.firstObject;if([old isEqual:url.path]&&saved.count>1)old=saved.allKeys.lastObject;[saved removeObjectForKey:old];}[NSUserDefaults.standardUserDefaults setObject:saved forKey:@"UserFileScopes.v1"];}
    }});
}
static void restoreUserFileScopes(void){
    if(!appSandboxBuild())return;
    NSDictionary *saved=[NSUserDefaults.standardUserDefaults dictionaryForKey:@"UserFileScopes.v1"];
    for(NSString *path in saved){NSData *data=saved[path];if(![data isKindOfClass:NSData.class])continue;BOOL stale=NO;NSURL *url=[NSURL URLByResolvingBookmarkData:data options:NSURLBookmarkResolutionWithSecurityScope|NSURLBookmarkResolutionWithoutUI relativeToURL:nil bookmarkDataIsStale:&stale error:nil];if(url){retainUserFileSelection(url);}}
}
static void releaseUserFileScopes(void){for(NSURL *url in activeFileScopes().allValues)[url stopAccessingSecurityScopedResource];[activeFileScopes() removeAllObjects];}
/* Save to the exact user-selected URL with Foundation's atomic replacement.
 * Mapping avoids a second full heap copy of large .m3i files and supports
 * destinations on another volume. Render scratch data remains in the container. */
static BOOL installUserFile(NSString *temporary,NSString *destination,NSError **error){
    NSData *data=[NSData dataWithContentsOfFile:temporary options:NSDataReadingMappedAlways error:error];
    if(!data||![data writeToURL:[NSURL fileURLWithPath:destination] options:NSDataWritingAtomic error:error])return NO;
    [NSFileManager.defaultManager removeItemAtPath:temporary error:nil];return YES;
}
