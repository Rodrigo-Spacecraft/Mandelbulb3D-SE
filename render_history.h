/* Main-render snapshots are retained across normal exits and crashes. */
static void historyReleaseMapping(void *info,const void *data,size_t size){(void)data;(void)size;CFRelease(info);}
static NSBitmapImageRep *historyBitmap(NSString *path,NSUInteger limit){
    NSData *data=[NSData dataWithContentsOfFile:path options:NSDataReadingMappedIfSafe error:nil];if(data.length<12)return nil;
    const unsigned char *b=data.bytes;uint32_t raw[3];memcpy(raw,b,12);uint64_t w=CFSwapInt32LittleToHost(raw[1]),h=CFSwapInt32LittleToHost(raw[2]);
    uint32_t version=CFSwapInt32LittleToHost(raw[0]);
    if(version<20||version>99||w<16||h<16||w>RENDER_MAX_DIMENSION||h>RENDER_MAX_DIMENSION)return nil;
    uint64_t offset=840+w*h*18+1136,count=w*h*4;// Original MB3D appends its fullSizeImage BGRA buffer here, without
    // our native settings trailer. A native parameters-only file has its
    // settings marker at this offset instead of an image.
    if(offset+count>data.length||(offset+8<=data.length&&!memcmp(b+offset,"IPMACM3I",8)))return nil;
    if(limit){
        // Read a few source rows per thumbnail row instead of decoding a huge
        // full-resolution image just to display an 80-pixel menu preview.
        double factor=fmin(1,(double)limit/fmax(w,h));NSUInteger tw=MAX(1,lround(w*factor)),th=MAX(1,lround(h*factor));
        NSBitmapImageRep *small=[[NSBitmapImageRep alloc]initWithBitmapDataPlanes:NULL pixelsWide:tw pixelsHigh:th bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSCalibratedRGBColorSpace bitmapFormat:NSBitmapFormatAlphaNonpremultiplied bytesPerRow:tw*4 bitsPerPixel:32];if(!small)return nil;
        for(NSUInteger y=0;y<th;y++)for(NSUInteger x=0;x<tw;x++){
            uint64_t x0=x*w/tw,x1=(x+1)*w/tw,y0=y*h/th,y1=(y+1)*h/th;unsigned sums[3]={0},samples=0;NSUInteger rows=MIN(4,y1-y0);
            for(NSUInteger r=0;r<rows;r++){uint64_t sy=y0+(2*r+1)*(y1-y0)/(2*rows);for(uint64_t sx=x0;sx<x1;sx++){const unsigned char *pixel=b+offset+(sy*w+sx)*4;for(int c=0;c<3;c++)sums[c]+=pixel[2-c];samples++;}}
            unsigned char *pixel=small.bitmapData+y*small.bytesPerRow+x*4;for(int c=0;c<3;c++)pixel[c]=(sums[c]+samples/2)/samples;pixel[3]=255;
        }
        return small;
    }
    CGDataProviderRef provider=CGDataProviderCreateWithData((__bridge_retained void *)data,b+offset,(size_t)count,historyReleaseMapping);if(!provider)return nil;
    CGColorSpaceRef color=CGColorSpaceCreateDeviceRGB();CGImageRef source=CGImageCreate(w,h,8,32,w*4,color,kCGBitmapByteOrder32Little|kCGImageAlphaNoneSkipFirst,provider,NULL,NO,kCGRenderingIntentDefault);CGDataProviderRelease(provider);
    double scale=limit?fmin(1,(double)limit/fmax(w,h)):1;NSUInteger width=MAX(1,lround(w*scale)),height=MAX(1,lround(h*scale));
    NSBitmapImageRep *bitmap=source?[[NSBitmapImageRep alloc]initWithBitmapDataPlanes:NULL pixelsWide:width pixelsHigh:height bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSCalibratedRGBColorSpace bitmapFormat:NSBitmapFormatAlphaNonpremultiplied bytesPerRow:width*4 bitsPerPixel:32]:nil;
    CGContextRef context=bitmap?CGBitmapContextCreate(bitmap.bitmapData,width,height,8,bitmap.bytesPerRow,color,kCGBitmapByteOrder32Big|kCGImageAlphaPremultipliedLast):NULL;
    if(context){CGContextSetInterpolationQuality(context,kCGInterpolationHigh);CGContextDrawImage(context,CGRectMake(0,0,width,height),source);CGContextRelease(context);}else bitmap=nil;
    if(source)CGImageRelease(source);CGColorSpaceRelease(color);return bitmap;
}
@interface RenderHistoryStore : NSObject
@property(nonatomic,copy) NSString *directory;
@property(nonatomic) BOOL closed;
@property(nonatomic,strong) NSCache<NSString *,NSImage *> *thumbnails;
- (instancetype)initWithDirectory:(NSString *)directory;
- (NSArray<NSDictionary *> *)entries;
- (NSString *)record:(RenderResult)result source:(NSString *)source error:(NSString **)error;
- (void)close;
@end
@implementation RenderHistoryStore
- (instancetype)initWithDirectory:(NSString *)directory{if((self=[super init])){_directory=[directory copy];_thumbnails=[NSCache new];_thumbnails.countLimit=50;}return self;}
- (NSArray<NSDictionary *> *)entries {
    @synchronized(self){NSMutableArray *items=[NSMutableArray array];
        for(NSString *name in [NSFileManager.defaultManager contentsOfDirectoryAtPath:self.directory error:nil]){
            if([name hasPrefix:@"."]||![name.pathExtension.lowercaseString isEqual:@"msi"])continue;
            NSString *path=[self.directory stringByAppendingPathComponent:name];NSDictionary *attributes=[NSFileManager.defaultManager attributesOfItemAtPath:path error:nil];
            if([attributes[NSFileType]isEqual:NSFileTypeRegular])[items addObject:@{@"path":path,@"date":attributes[NSFileModificationDate]?attributes[NSFileModificationDate]:NSDate.distantPast}];
        }
        [items sortUsingComparator:^NSComparisonResult(NSDictionary *a,NSDictionary *b){NSComparisonResult order=[b[@"date"]compare:a[@"date"]];return order==NSOrderedSame?[b[@"path"]compare:a[@"path"]]:order;}];return items;
    }
}
- (NSString *)record:(RenderResult)result source:(NSString *)source error:(NSString **)error {
    @synchronized(self){if(self.closed||!result.rgba||result.cancelled)return nil;NSError *failure=nil;
        if(![NSFileManager.defaultManager createDirectoryAtPath:self.directory withIntermediateDirectories:YES attributes:@{NSFilePosixPermissions:@0700} error:&failure]){if(error)*error=failure.localizedDescription;return nil;}
        NSDateFormatter *format=[NSDateFormatter new];format.locale=[[NSLocale alloc]initWithLocaleIdentifier:@"en_US_POSIX"];format.timeZone=[NSTimeZone timeZoneForSecondsFromGMT:0];format.dateFormat=@"yyyyMMdd'T'HHmmss.SSS'Z'";
        NSString *name=[NSString stringWithFormat:@"%@-%@.msi",[format stringFromDate:NSDate.date],NSUUID.UUID.UUIDString];NSString *path=[self.directory stringByAppendingPathComponent:name],*partial=[self.directory stringByAppendingPathComponent:[@"." stringByAppendingString:name]];
        char message[512];RenderOptions options=result.settings;options.camera_override=1;options.cancel_token=NULL;options.navigation_count=0;
        BOOL ok=write_scene_parameters_with_preview(source.fileSystemRepresentation,options,partial.fileSystemRepresentation,result.rgba,result.width,result.height,result.stride,message);
        if(ok&&rename(partial.fileSystemRepresentation,path.fileSystemRepresentation)){snprintf(message,sizeof message,"Could not finish history snapshot: %s",strerror(errno));ok=NO;}
        if(!ok){unlink(partial.fileSystemRepresentation);if(error)*error=[NSString stringWithUTF8String:message];return nil;}
        NSArray *entries=[self entries];for(NSUInteger i=50;i<entries.count;i++){NSString *old=entries[i][@"path"];if(![NSFileManager.defaultManager removeItemAtPath:old error:&failure]&&error)*error=failure.localizedDescription;[self.thumbnails removeObjectForKey:old];}
        return path;
    }
}
- (void)close {@synchronized(self){self.closed=YES;[self.thumbnails removeAllObjects];}}
@end
