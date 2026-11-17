#include "file_access.h"
/* Shared dialog defaults: animations have their own location/name; scene
 * parameters and exported images share another. Persist across launches. */
static NSString *dialogHistoryKey(BOOL animation){return animation?@"FileDialog.AnimationURL":@"FileDialog.SceneImageURL";}
static void rememberDialogURL(NSURL *url,BOOL animation){
    retainUserFileSelection(url);
    if(url.isFileURL&&url.lastPathComponent.length)[NSUserDefaults.standardUserDefaults setURL:url forKey:dialogHistoryKey(animation)];
}
static void restoreDialogLocation(NSSavePanel *panel,BOOL animation,NSString *extension,NSString *fallbackName){
    NSURL *last=[NSUserDefaults.standardUserDefaults URLForKey:dialogHistoryKey(animation)];
    if(last.isFileURL){NSURL *folder=last.URLByDeletingLastPathComponent;BOOL directory=NO;
        if([NSFileManager.defaultManager fileExistsAtPath:folder.path isDirectory:&directory]&&directory)panel.directoryURL=folder;
    }
    NSString *name=last.lastPathComponent.length?last.lastPathComponent:fallbackName;
    if(extension.length)name=[name.stringByDeletingPathExtension stringByAppendingPathExtension:extension];
    if(name.length)panel.nameFieldStringValue=name;
}

@interface SaveFileExtensionDelegate : NSObject<NSOpenSavePanelDelegate>
@end

@implementation SaveFileExtensionDelegate
- (void)panelSelectionDidChange:(id)sender {
    NSSavePanel *panel=sender;
    NSString *extension=panel.allowedFileTypes.firstObject;
    NSString *name=panel.nameFieldStringValue;
    if(!extension.length||!name.pathExtension.length||
       [name.pathExtension caseInsensitiveCompare:extension]==NSOrderedSame)return;

    panel.nameFieldStringValue=[name.stringByDeletingPathExtension stringByAppendingPathExtension:extension];
}
@end
