#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
int main(){@autoreleasepool{
 [NSApplication sharedApplication];
 assert(formulaHasThumbnail(0));assert(formulaHasThumbnail(2));assert(formulaHasThumbnail(4));
 assert(!formulaHasThumbnail(-1));assert(!formulaHasThumbnail(103));assert(!formulaHasThumbnail(124));
 NSMutableSet *keys=[NSMutableSet new];int count=0;
 for(int i=0;i<formula_menu_count();i++){int kind=formulaKindForMenu(i);if(!formulaHasThumbnail(kind))continue;NSString *key=formulaThumbnailFile(kind);assert([key isEqual:key.lastPathComponent]);assert(![keys containsObject:key]);[keys addObject:key];count++;}
 NSString *path=[@"/private/tmp" stringByAppendingPathComponent:[NSUUID.UUID.UUIDString stringByAppendingPathExtension:@"png"]];
 NSTask *task=[NSTask new];task.executableURL=[NSURL fileURLWithPath:[NSFileManager.defaultManager.currentDirectoryPath stringByAppendingPathComponent:@"Mandelbulb3D SE.app/Contents/MacOS/Mandelbulb3DSE"]];task.arguments=@[@"--formula-thumbnail",@"0",path];assert([task launchAndReturnError:nil]);[task waitUntilExit];assert(task.terminationStatus==0);NSImage *image=[[NSImage alloc]initWithContentsOfFile:path];assert(image);assert(image.size.width==64&&image.size.height==64);
 FormulaThumbnails *cache=[FormulaThumbnails new];cache.images=[NSMutableDictionary new];cache.items=[NSMutableDictionary new];image.size=NSMakeSize(32,32);cache.images[@0]=image;
 NSMenuItem *first=[[NSMenuItem alloc]initWithTitle:@"Integer Power" action:nil keyEquivalent:@""],*second=[[NSMenuItem alloc]initWithTitle:@"Integer Power" action:nil keyEquivalent:@""],*add=[[NSMenuItem alloc]initWithTitle:@"Add" action:nil keyEquivalent:@""];
 [cache addItem:first kind:0];[cache addItem:second kind:0];[cache addItem:add kind:103];assert(first.image==image&&second.image==image&&!add.image);assert(cache.items[@0].count==2);
 NSData *bulb=[NSData dataWithContentsOfFile:path];
 NSTask *box=[NSTask new];box.executableURL=task.executableURL;box.arguments=@[@"--formula-thumbnail",@"85717081",path];assert([box launchAndReturnError:nil]);[box waitUntilExit];assert(box.terminationStatus==0);
 NSData *boxData=[NSData dataWithContentsOfFile:path];assert(boxData.length&&! [bulb isEqualToData:boxData]);
 [NSFileManager.defaultManager removeItemAtPath:path error:nil];printf("PASS: %d unique cache keys; real preview render; menu image reuse; additive exclusions\n",count);
}return 0;}
