- (void)menuNeedsUpdate:(NSMenu *)menu {
    if(menu!=self.historyMenu.menu)return;
    [menu removeAllItems];[menu addItemWithTitle:@"History" action:nil keyEquivalent:@""];
    NSArray *entries=[self.renderHistory entries];NSDateFormatter *format=[NSDateFormatter new];format.locale=[[NSLocale alloc]initWithLocaleIdentifier:@"en_US_POSIX"];format.dateFormat=@"ddMMM HH:mm";
    for(NSDictionary *entry in [entries subarrayWithRange:NSMakeRange(0,MIN(50,entries.count))]){
        NSString *path=entry[@"path"];NSMenuItem *item=[[NSMenuItem alloc]initWithTitle:[format stringFromDate:entry[@"date"]] action:@selector(restoreHistory:) keyEquivalent:@""];item.target=self;item.representedObject=path;item.enabled=!self.calculating;
        NSImage *image=[self.renderHistory.thumbnails objectForKey:path];if(!image){NSBitmapImageRep *bitmap=historyBitmap(path,80);if(bitmap){image=[[NSImage alloc]initWithSize:NSMakeSize(bitmap.pixelsWide,bitmap.pixelsHigh)];[image addRepresentation:bitmap];[self.renderHistory.thumbnails setObject:image forKey:path];}}
        item.image=image;[menu addItem:item];
    }
    if(!entries.count){NSMenuItem *empty=[menu addItemWithTitle:@"No completed renders" action:nil keyEquivalent:@""];empty.enabled=NO;}
}
- (void)restoreHistory:(NSMenuItem *)item {
    if(self.calculating)return;NSString *path=item.representedObject;
    if(![path.stringByDeletingLastPathComponent isEqual:self.renderHistory.directory])return;
    render_cancel(self.navigatorCancelToken);self.navigatorGeneration++;self.navigatorRefinementTicket++;self.previewPending=NO;
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(finishLightingSlider) object:nil];self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;
    NSUInteger generation=++self.generation;[self setCalculating:YES];self.statusLabel.stringValue=@"Loading render history…";
    NSString *working=[self.renderHistory.directory stringByAppendingPathComponent:@".selected.m3i"],*partial=[working stringByAppendingFormat:@".%@",NSUUID.UUID.UUIDString];
    dispatch_async(self.renderQueue,^{
        NSError *copyError=nil;BOOL copied=[NSFileManager.defaultManager copyItemAtPath:path toPath:partial error:&copyError];
        char error[512]={0};RenderOptions settings={0};BOOL ok=copied&&read_scene_settings(partial.fileSystemRepresentation,&settings,error);NSBitmapImageRep *bitmap=ok?historyBitmap(partial,0):nil;
        if(ok&&bitmap&&rename(partial.fileSystemRepresentation,working.fileSystemRepresentation)){ok=NO;snprintf(error,sizeof error,"Could not restore history: %s",strerror(errno));}
        NSString *message=copyError.localizedDescription?copyError.localizedDescription:error[0]?[NSString stringWithUTF8String:error]:@"The saved history image could not be read.";unlink(partial.fileSystemRepresentation);
        interactiveUI(^{if(generation!=self.generation)return;[self setCalculating:NO];if(!ok||!bitmap){[self showFileError:@"Could not restore history" message:message];return;}
            NSImage *image=[[NSImage alloc]initWithSize:NSMakeSize((bitmap.pixelsWide+MAX(1,settings.viewing)-1)/MAX(1,settings.viewing),(bitmap.pixelsHigh+MAX(1,settings.viewing)-1)/MAX(1,settings.viewing))];[image addRepresentation:bitmap];
            self.imageView.image=image;self.completedRender=bitmap;self.sharpRenderImage=nil;self.pngButton.enabled=YES;
            self.completedOutputWidth=settings.width/MAX(1,settings.oversampling);self.completedOutputHeight=settings.height/MAX(1,settings.oversampling);self.actualSizeNeedsRender=NO;[self updateActualSizeAvailability];
            [self loadParameterSettings:settings path:working source:@"History"];
        });
    });
}
