#import <Cocoa/Cocoa.h>
#include "../file_access.h"
#include <assert.h>
int main(void){@autoreleasepool{
    NSString *root=[@"/private/tmp/m3dse-file-access-" stringByAppendingString:NSUUID.UUID.UUIDString];
    NSFileManager *fm=NSFileManager.defaultManager;assert([fm createDirectoryAtPath:root withIntermediateDirectories:YES attributes:nil error:nil]);
    NSString *scratch=[root stringByAppendingPathComponent:@"scratch"],*target=[root stringByAppendingPathComponent:@"selected.m3i"];
    assert([@"first" writeToFile:scratch atomically:YES encoding:NSUTF8StringEncoding error:nil]);NSError *error=nil;
    if(!installUserFile(scratch,target,&error)){fprintf(stderr,"%s\n",error.description.UTF8String);abort();}assert(![fm fileExistsAtPath:scratch]);assert([[NSString stringWithContentsOfFile:target encoding:NSUTF8StringEncoding error:nil]isEqual:@"first"]);
    assert([@"replacement" writeToFile:scratch atomically:YES encoding:NSUTF8StringEncoding error:nil]);if(!installUserFile(scratch,target,&error)){fprintf(stderr,"%s\n",error.description.UTF8String);abort();}assert([[NSString stringWithContentsOfFile:target encoding:NSUTF8StringEncoding error:nil]isEqual:@"replacement"]);assert(![fm fileExistsAtPath:scratch]);
    assert(!installUserFile([root stringByAppendingPathComponent:@"missing"],target,&error));assert(error);assert([[NSString stringWithContentsOfFile:target encoding:NSUTF8StringEncoding error:nil]isEqual:@"replacement"]);
    [fm removeItemAtPath:root error:nil];puts("Atomic new-file saves and replacements pass; a missing source leaves the existing destination intact.");
}return 0;}
