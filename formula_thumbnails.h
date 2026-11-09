/* Independent preview renders: never touch the interactive engine's caches. */
static BOOL formulaHasThumbnail(int kind){NSInteger category=formulaCategory(kind);return kind>=0&&category!=4&&category!=6;}
static NSString *formulaThumbnailFile(int kind){
    NSData *name=[[NSString stringWithUTF8String:formula_name(kind)] dataUsingEncoding:NSUTF8StringEncoding];
    NSString *key=[[name base64EncodedStringWithOptions:0] stringByReplacingOccurrencesOfString:@"/" withString:@"_"];
    return [key stringByAppendingPathExtension:@"png"];
}
static NSURL *formulaThumbnailFolder(void){
    NSURL *cache=[NSFileManager.defaultManager URLsForDirectory:NSCachesDirectory inDomains:NSUserDomainMask].firstObject;
    return [cache URLByAppendingPathComponent:@"Mandelbulb3D SE/FormulaThumbnails/v7-startup-camera" isDirectory:YES];
}
static int renderFormulaThumbnailInResources(int kind,NSString *path,NSString *resources){
    if(!formulaHasThumbnail(kind))return 2;
#ifdef USE_RUST_ENGINE
    render_set_rust_assets([resources stringByAppendingPathComponent:@"M3Formulas"].fileSystemRepresentation);
    mb3dx_rust_set_cpu_only(1);
#endif
    RenderOptions o={.width=64,.height=64,.threads=1,.iterations=60,.de_stop=1./15,.program_override=1};
    o.program.split=1;o.program.max_iterations2=60;o.program.smooth=.5;o.program.formula_power=2;o.program.mode=0;o.program.repeat_from=0;o.program.min_iterations=1;o.program.bailout=16;
    for(int i=0;i<FORMULA_SLOTS;i++)o.program.slots[i]=formula_slot_default(-1);
    o.program.slots[0]=formula_slot_default(kind);o.program.slots[0].count=1;
    double bailout=formula_catalog_bailout(kind);if(isfinite(bailout)&&bailout>1&&bailout<=1e10)o.program.bailout=bailout;
    // No camera or lighting overrides: use the same defaults as a normal launch.
    RenderResult result=render_scene_with_options(NULL,o);if(!result.rgba){fprintf(stderr,"Formula thumbnail %d: %s\n",kind,result.error);return 1;}
    NSImage *image=imageForRender(result,1);free(result.rgba);
    NSBitmapImageRep *bitmap=(NSBitmapImageRep *)image.representations.firstObject;
    NSData *png=[bitmap representationUsingType:NSBitmapImageFileTypePNG properties:@{}];
    return [png writeToFile:path options:NSDataWritingAtomic error:nil]?0:1;
}
static int renderFormulaThumbnail(int kind,NSString *path){return renderFormulaThumbnailInResources(kind,path,NSBundle.mainBundle.resourcePath);}
@interface FormulaThumbnails:NSObject
@property(nonatomic,strong) NSMutableDictionary<NSNumber *,NSImage *> *images;
@property(nonatomic,strong) NSMutableDictionary<NSNumber *,NSHashTable<NSMenuItem *> *> *items;
+ (instancetype)shared;
- (void)addItem:(NSMenuItem *)item kind:(int)kind;
- (void)start;
@end
@implementation FormulaThumbnails
+ (instancetype)shared{static FormulaThumbnails *cache;static dispatch_once_t once;dispatch_once(&once,^{cache=[self new];cache.images=[NSMutableDictionary new];cache.items=[NSMutableDictionary new];});return cache;}
- (void)addItem:(NSMenuItem *)item kind:(int)kind{
    if(!formulaHasThumbnail(kind))return;
    NSNumber *key=@(kind);NSHashTable *items=self.items[key];if(!items){items=[NSHashTable weakObjectsHashTable];self.items[key]=items;}[items addObject:item];
    NSImage *image=self.images[key];
    if(!image){image=[[NSImage alloc]initWithContentsOfURL:[formulaThumbnailFolder() URLByAppendingPathComponent:formulaThumbnailFile(kind)]];if(image){image.size=NSMakeSize(32,32);self.images[key]=image;}}
    item.image=image;
}
- (void)start{
    static dispatch_once_t once;dispatch_once(&once,^{
        NSURL *folder=formulaThumbnailFolder();NSString *resources=NSBundle.mainBundle.resourcePath;
        NSString *executable=appSandboxBuild()?[NSBundle.mainBundle.bundlePath stringByAppendingPathComponent:@"Contents/Helpers/FormulaThumbnailRenderer"]:NSBundle.mainBundle.executablePath;
        NSMutableArray *missing=[NSMutableArray new];
        for(int i=0;i<formula_menu_count();i++){int kind=formulaKindForMenu(i);if(formulaHasThumbnail(kind)&&![NSFileManager.defaultManager fileExistsAtPath:[folder URLByAppendingPathComponent:formulaThumbnailFile(kind)].path])[missing addObject:@(kind)];}
        dispatch_async(dispatch_get_global_queue(QOS_CLASS_BACKGROUND,0),^{@autoreleasepool{
            if(![NSFileManager.defaultManager createDirectoryAtURL:folder withIntermediateDirectories:YES attributes:nil error:nil])return;
            NSString *logPath=[folder.path stringByAppendingPathComponent:@"generation.log"];
            if(![NSFileManager.defaultManager fileExistsAtPath:logPath])[NSFileManager.defaultManager createFileAtPath:logPath contents:nil attributes:nil];
            NSFileHandle *log=[NSFileHandle fileHandleForWritingAtPath:logPath];[log seekToEndOfFile];
            for(NSNumber *key in missing){@autoreleasepool{
                NSURL *file=[folder URLByAppendingPathComponent:formulaThumbnailFile(key.intValue)];
                if([NSFileManager.defaultManager fileExistsAtPath:file.path])continue;
                NSTask *task=[NSTask new];task.executableURL=[NSURL fileURLWithPath:executable];task.arguments=@[@"--formula-thumbnail",key.stringValue,file.path,resources];task.qualityOfService=NSQualityOfServiceBackground;
                task.standardOutput=NSFileHandle.fileHandleWithNullDevice;task.standardError=log?:NSFileHandle.fileHandleWithNullDevice;
                NSError *launchError=nil;if(![task launchAndReturnError:&launchError]){[log writeData:[[NSString stringWithFormat:@"%@ launch failed: %@\n",key,launchError] dataUsingEncoding:NSUTF8StringEncoding]];continue;}
                // Pathological formulas must not hold up the rest of the catalog.
                dispatch_after(dispatch_time(DISPATCH_TIME_NOW,10*NSEC_PER_SEC),dispatch_get_global_queue(QOS_CLASS_UTILITY,0),^{if(task.running)[task terminate];});
                [task waitUntilExit];if(task.terminationStatus!=0){[log writeData:[[NSString stringWithFormat:@"%@ exited %d\n",key,task.terminationStatus] dataUsingEncoding:NSUTF8StringEncoding]];continue;}
                dispatch_async(dispatch_get_main_queue(),^{NSImage *image=[[NSImage alloc]initWithContentsOfURL:file];if(!image)return;image.size=NSMakeSize(32,32);self.images[key]=image;for(NSMenuItem *item in self.items[key])item.image=image;});
            }}
            [log closeFile];
        }});
    });
}
@end
