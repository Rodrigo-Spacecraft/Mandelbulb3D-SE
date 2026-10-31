/* Default images and their terms are bundled read-only, then copied into the writable Maps
 * folder. Existing user files always win, including maps with default names. */
static BOOL installDefaultMapFiles(NSURL *source,NSURL *destination,NSError **error){
    NSFileManager *files=NSFileManager.defaultManager;BOOL directory=NO;
    if(!source||![files fileExistsAtPath:source.path isDirectory:&directory]||!directory)return YES;
    NSArray<NSURL *> *images=[files contentsOfDirectoryAtURL:source includingPropertiesForKeys:@[NSURLIsRegularFileKey,NSURLIsSymbolicLinkKey] options:NSDirectoryEnumerationSkipsHiddenFiles error:error];if(!images)return NO;
    NSSet *extensions=[NSSet setWithArray:@[@"png",@"jpg",@"jpeg",@"bmp",@"gif",@"tif",@"tiff",@"pgm"]];
    for(NSURL *image in images){
        if(![extensions containsObject:image.pathExtension.lowercaseString]&&![image.lastPathComponent isEqualToString:@"m3maps terms of use.txt"])continue;
        NSNumber *regular=nil,*link=nil;[image getResourceValue:&regular forKey:NSURLIsRegularFileKey error:nil];[image getResourceValue:&link forKey:NSURLIsSymbolicLinkKey error:nil];if(!regular.boolValue||link.boolValue)continue;
        NSURL *target=[destination URLByAppendingPathComponent:image.lastPathComponent];if([files fileExistsAtPath:target.path])continue;
        if(![files createDirectoryAtURL:destination withIntermediateDirectories:YES attributes:nil error:error])return NO;
        NSError *copyError=nil;if(![files copyItemAtURL:image toURL:target error:&copyError]){if([copyError.domain isEqual:NSCocoaErrorDomain]&&copyError.code==NSFileWriteFileExistsError)continue;if(error)*error=copyError;return NO;}
    }
    return YES;
}
