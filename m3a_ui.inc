/* Mandelbulb3D Animation.pas version-5 layout, plus an optional native trailer.
   All methods in this file that touch the C renderer run on renderQueue. */
- (NSData *)animationM3AData:(NSDictionary *)project error:(NSString **)message {
    return [self animationM3AData:project thumbnailBitmaps:nil error:message];
}
- (NSData *)animationM3AData:(NSDictionary *)project thumbnailBitmaps:(NSArray *)bitmaps error:(NSString **)message {
    NSArray *keys=project[@"keys"];if(!keys.count){*message=@"Capture a keyframe before saving.";return nil;}
    int width,height;if(!animationInteger(project[@"fields"][2],16,RENDER_MAX_DIMENSION,&width)||!animationInteger(project[@"fields"][3],16,RENDER_MAX_DIMENSION,&height)){*message=@"Invalid animation dimensions.";return nil;}
    NSMutableData *data=[NSMutableData dataWithLength:284];unsigned char *p=data.mutableBytes;
    animationPut32(p,5);animationPut32(p+4,width);animationPut32(p+8,height);animationPut32(p+12,[project[@"oversampling"] intValue]+1);animationPut32(p+16,1);
    NSData *folder=[(project[@"outputFolder"]?project[@"outputFolder"]:@"") dataUsingEncoding:NSUTF8StringEncoding];NSUInteger folderLength=MIN(255,folder.length);p[20]=(unsigned char)folderLength;memcpy(p+21,folder.bytes,folderLength);
    animationPut32(p+276,([project[@"loop"] boolValue]?4:0)|([project[@"interpolation"] intValue]?1:0)|8|256);animationPut32(p+280,(uint32_t)keys.count);
    for(NSUInteger i=0;i<keys.count;i++){
        NSDictionary *key=keys[i];RenderOptions options=animationUnpack(key[@"settings"]);
        NSString *source=[self animationRestoreSource:key[@"source"]];if(!source){*message=@"Could not restore keyframe source parameters.";return nil;}
        NSString *path=[[self applicationTemporaryFolderURL].path stringByAppendingPathComponent:[@"Mandelbulb3Dx-m3a-" stringByAppendingString:NSUUID.UUID.UUIDString]];char error[512];
        int encoded=write_scene_parameters(source.length?source.fileSystemRepresentation:NULL,options,path.fileSystemRepresentation,error);
        if(source.length){[NSFileManager.defaultManager removeItemAtPath:source error:nil];[self.animationTemporarySources removeObject:source];}
        if(!encoded){*message=[NSString stringWithFormat:@"Keyframe %lu: %s",(unsigned long)i+1,error];return nil;}
        NSData *compact=[self animationCompactSource:path];[NSFileManager.defaultManager removeItemAtPath:path error:nil];if(!compact||compact.length<1976){*message=@"Could not encode keyframe parameters.";return nil;}
        unsigned char record[12]={0};animationPut32(record,[key[@"frames"] intValue]);[data appendBytes:record length:12];[data appendData:[compact subdataWithRange:NSMakeRange(0,1976)]];
    }
    NSMutableArray *nativeKeys=[NSMutableArray arrayWithCapacity:keys.count];
    for(NSDictionary *key in keys)[nativeKeys addObject:[key mutableCopy]];
    for(NSUInteger index=0;index<keys.count;index++){@autoreleasepool{
        NSDictionary *key=keys[index];
        NSBitmapImageRep *image=index<bitmaps.count&&[bitmaps[index] isKindOfClass:NSBitmapImageRep.class]?bitmaps[index]:nil;
        if(!image&&[key[@"thumbnail"] isKindOfClass:NSData.class])image=[NSBitmapImageRep imageRepWithData:key[@"thumbnail"]];
        /* Convert the complete bitmap once rather than creating a color object
           and doing a color-space conversion for every pixel. */
        if(image)image=[image bitmapImageRepByConvertingToColorSpace:NSColorSpace.deviceRGBColorSpace renderingIntent:NSColorRenderingIntentDefault];
        if(image&&(image.pixelsWide>494||image.pixelsHigh>282)){NSImage *resolved=animationThumbnailToFit(image,494,282);if(resolved)image=(NSBitmapImageRep*)resolved.representations.firstObject;}
        if(image&&!key[@"thumbnail"]){NSData *png=[image representationUsingType:NSBitmapImageFileTypePNG properties:@{}];if(png)nativeKeys[index][@"thumbnail"]=png;}
        int w=image?(int)image.pixelsWide:1,h=image?(int)image.pixelsHigh:1;
        NSMutableData *thumb=[NSMutableData dataWithLength:8+(NSUInteger)w*h*4];unsigned char *pixels=thumb.mutableBytes;animationPut32(pixels,w);animationPut32(pixels+4,h);
        BOOL packed=image&&!image.isPlanar&&image.bitsPerSample==8&&(image.samplesPerPixel==3||image.samplesPerPixel==4)&&image.bitsPerPixel==image.samplesPerPixel*8&&!(image.bitmapFormat&(NSBitmapFormatSixteenBitLittleEndian|NSBitmapFormatThirtyTwoBitLittleEndian|NSBitmapFormatThirtyTwoBitBigEndian));
        for(int y=0;y<h;y++){
            const unsigned char *row=packed?image.bitmapData+y*image.bytesPerRow:NULL;
            for(int x=0;x<w;x++){
                unsigned char *pixel=pixels+8+((h-1-y)*w+x)*4;
                if(packed){const unsigned char *src=row+x*image.samplesPerPixel;BOOL first=image.hasAlpha&&(image.bitmapFormat&NSBitmapFormatAlphaFirst);int alpha=image.hasAlpha?src[first?0:3]:255;src+=first?1:0;
                    for(int c=0;c<3;c++){int value=src[2-c];if(image.hasAlpha&&!(image.bitmapFormat&NSBitmapFormatAlphaNonpremultiplied)&&alpha<255)value=alpha?MIN(255,(int)lround(value*255.0/alpha)):0;pixel[c]=value;}
                }else{NSColor *color=image?[[image colorAtX:x y:y] colorUsingColorSpace:NSColorSpace.deviceRGBColorSpace]:[NSColor colorWithDeviceRed:0 green:0 blue:0 alpha:1];pixel[0]=(unsigned char)lround(color.blueComponent*255);pixel[1]=(unsigned char)lround(color.greenComponent*255);pixel[2]=(unsigned char)lround(color.redComponent*255);}pixel[3]=255;
            }
        }
        [data appendData:thumb];
    }}
    NSMutableDictionary *nativeProject=[project mutableCopy];nativeProject[@"keys"]=nativeKeys;
    NSError *error=nil;NSData *extension=[NSPropertyListSerialization dataWithPropertyList:nativeProject format:NSPropertyListBinaryFormat_v1_0 options:0 error:&error];if(!extension||extension.length>UINT32_MAX){*message=error.localizedDescription?error.localizedDescription:@"Animation project is too large.";return nil;}
    const unsigned char magic[8]={'M','3','D','X','A','1',0,0};[data appendBytes:magic length:8];unsigned char length[4];animationPut32(length,(uint32_t)extension.length);[data appendBytes:length length:4];[data appendData:extension];return data;
}
- (NSDictionary *)animationReadM3A:(NSData *)data warning:(NSString **)warning error:(NSString **)message {
    if(data.length<284){*message=@"Truncated .m3a header.";return nil;}const unsigned char *p=data.bytes;
    uint32_t version=animationRead32(p),width=animationRead32(p+4),height=animationRead32(p+8),sampling=animationRead32(p+12),flags=animationRead32(p+276),count=animationRead32(p+280);
    if(version!=5){*message=@"Only version-5 .m3a projects are supported. Resave older projects using a current Mandelbulb3D version.";return nil;}
    if(width<16||width>RENDER_MAX_DIMENSION||height<16||height>RENDER_MAX_DIMENSION||sampling<1||sampling>6||width*sampling>RENDER_MAX_DIMENSION||height*sampling>RENDER_MAX_DIMENSION||count<1||count>1000){*message=@"Invalid or unsupported .m3a dimensions, oversampling, or keyframe count (maximum 1000).";return nil;}
    NSUInteger cursor=284;NSMutableArray *keys=[NSMutableArray array],*warnings=[NSMutableArray array];
    if(flags&192)[warnings addObject:@"Stereo animation is ignored."];if(flags&512)[warnings addObject:@"Z-buffer export is ignored."];if(((flags>>3)&7)!=1)[warnings addObject:@"Output will use PNG frames."];if((flags&3)==2)[warnings addObject:@"Cubic interpolation uses quadratic Bezier."];
    for(uint32_t i=0;i<count;i++){
        if(data.length-cursor<1988){*message=@"Truncated .m3a keyframe.";return nil;}
        int32_t frames=(int32_t)animationRead32(p+cursor);if(frames<0||frames>10000){*message=@"Unsupported .m3a keyframe duration (expected 0–10000).";return nil;}
        if(p[cursor+12+840]<16||p[cursor+12+840]>99){*message=@"Legacy formula addons are unsupported; resave the .m3a in a current Mandelbulb3D version.";return nil;}
        NSData *source=[data subdataWithRange:NSMakeRange(cursor+12,1976)];
        [keys addObject:@{@"name":[NSString stringWithFormat:@"Scene %u",i+1],@"frames":@(MAX(1,frames)),@"source":source}];cursor+=1988;
        if(!frames&&i+1<count)[warnings addObject:[NSString stringWithFormat:@"Keyframe %u has zero duration; using one interval.",i+1]];
    }
    for(uint32_t i=0;i<count;i++){
        if(data.length-cursor<8){*message=@"Truncated .m3a thumbnail header.";return nil;}uint64_t w=animationRead32(p+cursor),h=animationRead32(p+cursor+4);cursor+=8;
        if(w>RENDER_MAX_DIMENSION||h>RENDER_MAX_DIMENSION||w*h*4>data.length-cursor){*message=@"Invalid or truncated .m3a thumbnail.";return nil;}
        if(w&&h){double scale=fmin(1,fmin(494.0/w,282.0/h));int tw=MAX(1,(int)lround(w*scale)),th=MAX(1,(int)lround(h*scale));NSBitmapImageRep *thumb=[[NSBitmapImageRep alloc]initWithBitmapDataPlanes:NULL pixelsWide:tw pixelsHigh:th bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSCalibratedRGBColorSpace bytesPerRow:tw*4 bitsPerPixel:32];
            for(int y=0;y<th;y++)for(int x=0;x<tw;x++){const unsigned char *src=p+cursor+((h-1-MIN(h-1,(uint64_t)(y/scale)))*w+(uint64_t)(x/scale))*4;unsigned char *dest=thumb.bitmapData+y*thumb.bytesPerRow+x*4;dest[0]=src[2];dest[1]=src[1];dest[2]=src[0];dest[3]=255;}
            NSData *png=[thumb representationUsingType:NSBitmapImageFileTypePNG properties:@{}];if(png){NSMutableDictionary *key=[keys[i] mutableCopy];key[@"thumbnail"]=png;keys[i]=key;}}
        cursor+=(NSUInteger)(w*h*4);
    }
    const unsigned char magic[8]={'M','3','D','X','A','1',0,0};
    if(data.length-cursor>=12&&!memcmp(p+cursor,magic,8)){
        uint32_t length=animationRead32(p+cursor+8);if(length!=data.length-cursor-12){*message=@"Truncated native .m3a extension.";return nil;}
        NSDictionary *native=[NSPropertyListSerialization propertyListWithData:[data subdataWithRange:NSMakeRange(cursor+12,length)] options:NSPropertyListImmutable format:nil error:nil];
        if(![native isKindOfClass:NSDictionary.class]||![native[@"format"] isEqual:@"Mandelbulb3DxAnimation"]){*message=@"Invalid native .m3a extension.";return nil;}
        *warning=@"";return native;
    }
    /* Native projects above already preserve the formula slots. Decode the
       six-slot compatibility records only for files without that extension. */
    for(NSUInteger i=0;i<keys.count;i++){
        NSMutableDictionary *key=[keys[i] mutableCopy];NSString *path=[self animationRestoreSource:key[@"source"]];RenderOptions options;char error[512];
        if(!path||!read_scene_settings(path.fileSystemRepresentation,&options,error)){*message=[NSString stringWithFormat:@"Keyframe %lu: %s",(unsigned long)i+1,path?error:"Could not restore scene parameters"];return nil;}
        options.camera_override=1;options.cancel_token=NULL;options.navigation_count=0;options.preview_cache=options.reuse_surface=0;
        key[@"settings"]=[NSData dataWithBytes:&options length:sizeof options];keys[i]=key;
    }
    NSString *folder=[[NSString alloc]initWithBytes:p+21 length:p[20] encoding:NSUTF8StringEncoding];if(!folder)folder=[[NSString alloc]initWithBytes:p+21 length:p[20] encoding:NSWindowsCP1252StringEncoding];
    *warning=[warnings componentsJoinedByString:@" "];
    return @{@"format":@"Mandelbulb3DxAnimation",@"version":@1,@"optionsSize":@(sizeof(RenderOptions)),@"settingsLayout":@"build9",@"keys":keys,@"fields":@[@"30",@"1",[@(width) stringValue],[@(height) stringValue],@"30",@"1",@"1",@"last"],@"loop":@((flags&4)!=0),@"interpolation":@((flags&3)?1:0),@"oversampling":@(sampling-1),@"previewScale":@1,@"outputFolder":folder?folder:@""};
}
