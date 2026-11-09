/* Sandboxed access is limited to the container and explicit user selections.
 * Keep scopes alive across asynchronous render/save jobs; remember grants for
 * later launches. Raw paths imported from scene files never create grants. */
#pragma once
static BOOL appSandboxBuild(void){return [NSBundle.mainBundle.infoDictionary[@"M3DAppSandboxed"] boolValue]||NSProcessInfo.processInfo.environment[@"APP_SANDBOX_CONTAINER_ID"].length;}
static NSMutableDictionary<NSString *,NSURL *> *activeFileScopes(void){static NSMutableDictionary *scopes;static dispatch_once_t once;dispatch_once(&once,^{scopes=[NSMutableDictionary new];});return scopes;}
static BOOL containerFileURL(NSURL *url){NSString *home=[NSHomeDirectory() stringByAppendingString:@"/"];return [url.path hasPrefix:home]||[url.path isEqual:NSHomeDirectory()]||[url.path hasPrefix:[NSBundle.mainBundle.bundlePath stringByAppendingString:@"/"]];}
static BOOL fileScopesClosed=NO;
static void activateUserFileScope(NSURL *url){
    NSMutableDictionary *scopes=activeFileScopes();
    @synchronized(scopes){if(fileScopesClosed||scopes[url.path])return;}
    // Do not hold the lock while making a potentially blocking system call.
    if(![url startAccessingSecurityScopedResource])return;
    BOOL keep=NO;
    @synchronized(scopes){if(!fileScopesClosed&&!scopes[url.path]){scopes[url.path]=url;keep=YES;}}
    if(!keep)[url stopAccessingSecurityScopedResource];
}
static void retainUserFileSelection(NSURL *url){
    if(!appSandboxBuild()||!url.isFileURL||containerFileURL(url))return;
    activateUserFileScope(url);
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
    // ScopedBookmarksAgent can stall indefinitely. Neither launch nor rendering
    // waits for this task. Keep the saved data unchanged, including failures.
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_UTILITY,0),^{@autoreleasepool{
        for(NSString *path in saved){
            @synchronized(activeFileScopes()){if(fileScopesClosed)return;}
            NSData *data=saved[path];if(![data isKindOfClass:NSData.class])continue;
            BOOL stale=NO;
            NSURL *url=[NSURL URLByResolvingBookmarkData:data options:NSURLBookmarkResolutionWithSecurityScope|NSURLBookmarkResolutionWithoutUI|NSURLBookmarkResolutionWithoutMounting relativeToURL:nil bookmarkDataIsStale:&stale error:nil];
            if(url)activateUserFileScope(url);
        }
    }});
}
static void releaseUserFileScopes(void){
    NSMutableDictionary *scopes=activeFileScopes();NSArray *urls;
    @synchronized(scopes){fileScopesClosed=YES;urls=scopes.allValues;[scopes removeAllObjects];}
    for(NSURL *url in urls)[url stopAccessingSecurityScopedResource];
}
/* Save to the exact user-selected URL with Foundation's atomic replacement.
 * Mapping avoids a second full heap copy of large .m3i files and supports
 * destinations on another volume. Render scratch data remains in the container. */
static BOOL installUserFile(NSString *temporary,NSString *destination,NSError **error){
    NSData *data=[NSData dataWithContentsOfFile:temporary options:NSDataReadingMappedAlways error:error];
    if(!data||![data writeToURL:[NSURL fileURLWithPath:destination] options:NSDataWritingAtomic error:error])return NO;
    [NSFileManager.defaultManager removeItemAtPath:temporary error:nil];return YES;
}
