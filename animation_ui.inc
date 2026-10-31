/* Animation window methods, included inside AppDelegate. */
- (void)showAnimation:(id)sender {
    (void)sender;[self ensureAnimationWindow];[self setCalculating:self.calculating];[self positionWindowRightOfMain:self.animationWindow];[self.animationWindow makeKeyAndOrderFront:nil];
}
- (void)ensureAnimationWindow {
    if(!self.animationWindow){
        self.animationKeys=[NSMutableArray array];self.animationTemporarySources=[NSMutableSet set];
        self.animationWindow=[[NSWindow alloc]initWithContentRect:NSMakeRect(0,0,900,620) styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable backing:NSBackingStoreBuffered defer:NO];self.animationWindow.title=@"Animation maker";self.animationWindow.delegate=self;self.animationWindow.releasedWhenClosed=NO;
        CalculationPanel *panel=[[CalculationPanel alloc]initWithFrame:NSMakeRect(0,0,900,620)];NSMutableArray *controls=[NSMutableArray array];
        NSScrollView *scroll=[[NSScrollView alloc]initWithFrame:NSMakeRect(16,16,354,282)];scroll.hasVerticalScroller=YES;
        self.animationTable=[[NSTableView alloc]initWithFrame:scroll.bounds];
        NSArray *ids=@[@"thumbnail",@"number",@"frames",@"first-frame"],*titles=@[@"Preview",@"Key",@"To next",@"Frame"];
        for(int i=0;i<4;i++){NSTableColumn *column=[[NSTableColumn alloc]initWithIdentifier:ids[i]];column.title=titles[i];column.width=i==0?66:i==1?62:i==2?84:100;[self.animationTable addTableColumn:column];}
        self.animationTable.allowsEmptySelection=NO;self.animationTable.rowHeight=54;self.animationTable.target=self;self.animationTable.action=@selector(animationKeyClicked:);self.animationTable.dataSource=self;self.animationTable.delegate=self;self.animationTable.headerView.frame=NSMakeRect(0,0,354,24);scroll.documentView=self.animationTable;[panel addSubview:scroll];
        self.animationView=[[FractalView alloc]initWithFrame:NSMakeRect(390,16,494,282)];self.animationView.imageScaling=NSImageScaleProportionallyUpOrDown;[panel addSubview:self.animationView];
        NSArray *buttons=@[@"Capture",@"Insert",@"Interp",@"To Main",@"Remove",@"Move up",@"Move Dn",@"Clear"];
        NSInteger tags[]={1,0,6,5,2,3,4,7};
        for(int i=0;i<8;i++){NSButton *button=[NSButton buttonWithTitle:buttons[i] target:self action:@selector(animationKeyAction:)];button.tag=tags[i];button.frame=i<4?NSMakeRect(16+i*90,310,86,28):NSMakeRect(16+(i-4)*90,344,86,28);[panel addSubview:button];[controls addObject:button];}
        NSArray *labels=@[@"Frames to next",@"Current frame",@"Width",@"Height",@"Frames / second",@"Preview every nth",@"Start frame",@"End frame"];
        NSMutableArray *fields=[NSMutableArray array];RenderOptions settings=self.formulaSettings;
        NSArray *defaults=@[@"30",@"1",[NSString stringWithFormat:@"%d",settings.width?MAX(16,settings.width/MAX(1,settings.oversampling)):480],[NSString stringWithFormat:@"%d",settings.height?MAX(16,settings.height/MAX(1,settings.oversampling)):360],@"24",@"1",@"1",@"last"];
        for(int i=0;i<8;i++){
            int column=i%2,row=i/2;CGFloat x=16+column*244,y=380+row*32;
            NSTextField *label=[NSTextField labelWithString:labels[i]];label.frame=NSMakeRect(x,y+4,145,22);[panel addSubview:label];
            NSTextField *field=[[NumericTextField alloc]initWithFrame:NSMakeRect(x+150,y,80,26)];numericIntegerField(field,YES);((NumericInputFormatter*)field.formatter).allowLast=i==7;field.stringValue=defaults[i];field.accessibilityLabel=[@"Animation " stringByAppendingString:labels[i]];field.delegate=self;field.target=self;field.action=@selector(animationFieldEdited:);field.tag=i;[panel addSubview:field];[fields addObject:field];[controls addObject:field];
        }
        self.animationFields=fields;
        LiveSlider *timeline=[LiveSlider sliderWithValue:1 minValue:1 maxValue:2 target:self action:@selector(animationScrub:)];timeline.frame=NSMakeRect(390,310,494,28);timeline.continuous=YES;timeline.accessibilityLabel=@"Animation timeline";__weak AppDelegate *weakAnimation=self;timeline.started=^{[weakAnimation pauseAnimationPlayback];};timeline.finished=^{if(weakAnimation.animationPlaybackFrames.count)[weakAnimation seekAnimationPlayback:weakAnimation.animationFields[1].integerValue];else [weakAnimation animationRenderFrame:nil];};self.animationTimeline=timeline;[panel addSubview:timeline];[controls addObject:timeline];
        self.animationFrameOverlay=[NSButton checkboxWithTitle:@"Frame number" target:self action:@selector(animationOverlayChanged:)];self.animationFrameOverlay.frame=NSMakeRect(390,346,140,26);[panel addSubview:self.animationFrameOverlay];
        self.animationFrameColor=[[NSPopUpButton alloc]initWithFrame:NSMakeRect(534,346,112,28) pullsDown:NO];[self.animationFrameColor addItemsWithTitles:@[@"White",@"Black"]];self.animationFrameColor.target=self;self.animationFrameColor.action=@selector(animationOverlayChanged:);[panel addSubview:self.animationFrameColor];
        self.animationPause=[NSButton buttonWithTitle:@"Resume" target:self action:@selector(toggleAnimationPlayback:)];self.animationPause.frame=NSMakeRect(750,346,134,28);self.animationPause.enabled=NO;[panel addSubview:self.animationPause];
        self.animationProcessingsButton=[NSButton buttonWithTitle:@"Processings…" target:self action:@selector(showAnimationProcessing:)];self.animationProcessingsButton.frame=NSMakeRect(742,378,132,28);self.animationProcessingsButton.accessibilityLabel=@"Open Processings window";[panel addSubview:self.animationProcessingsButton];[controls addObject:self.animationProcessingsButton];
        self.animationLoop=[NSButton checkboxWithTitle:@"Loop animation" target:self action:@selector(animationFieldEdited:)];self.animationLoop.frame=NSMakeRect(510,380,220,26);[panel addSubview:self.animationLoop];[controls addObject:self.animationLoop];
        NSTextField *interpLabel=[NSTextField labelWithString:@"Interp"];interpLabel.frame=NSMakeRect(670,416,44,22);[panel addSubview:interpLabel];
        self.animationInterpolation=[[NSPopUpButton alloc]initWithFrame:NSMakeRect(716,412,158,28) pullsDown:NO];[self.animationInterpolation addItemsWithTitles:@[@"Linear",@"Quadratic Bezier"]];[panel addSubview:self.animationInterpolation];[controls addObject:self.animationInterpolation];
        NSTextField *samplingLabel=[NSTextField labelWithString:@"Oversampling"];samplingLabel.frame=NSMakeRect(510,416,100,22);[panel addSubview:samplingLabel];
        self.animationSampling=[[NSPopUpButton alloc]initWithFrame:NSMakeRect(610,412,54,28) pullsDown:NO];for(int i=1;i<=6;i++)[self.animationSampling addItemWithTitle:[NSString stringWithFormat:@"%d×",i]];[panel addSubview:self.animationSampling];[controls addObject:self.animationSampling];
        self.animationPreviewEstimate=[NSTextField labelWithString:@"Preview estimate: available after first frame"];self.animationPreviewEstimate.frame=NSMakeRect(510,448,364,22);self.animationPreviewEstimate.lineBreakMode=NSLineBreakByTruncatingTail;[panel addSubview:self.animationPreviewEstimate];
        NSTextField *previewLabel=[NSTextField labelWithString:@"Preview scale down"];previewLabel.frame=NSMakeRect(510,480,150,22);[panel addSubview:previewLabel];
        self.animationPreviewScale=[[NSPopUpButton alloc]initWithFrame:NSMakeRect(666,476,208,28) pullsDown:NO];[self.animationPreviewScale addItemsWithTitles:@[@"1×",@"1/2×",@"1/4×",@"1/8×"]];[self.animationPreviewScale selectItemAtIndex:1];self.animationPreviewScale.accessibilityLabel=@"Animation preview scale down";self.animationPreviewScale.target=self;self.animationPreviewScale.action=@selector(animationEstimateEdited:);[panel addSubview:self.animationPreviewScale];[controls addObject:self.animationPreviewScale];
        NSArray *actions=@[@"Open animation…",@"Render Current Frame",@"Render preview",@"Choose Output Folder…",@"Start Render",@"Save animation..."];
        SEL selectors[]={@selector(animationOpen:),@selector(animationRenderFrame:),@selector(animationRenderPreview:),@selector(chooseAnimationOutputFolder:),@selector(animationExport:),@selector(animationSave:)};
        CGFloat buttonX[]={16,166,332,458,634,752},buttonWidth[]={142,158,118,168,110,132};
        for(int i=0;i<6;i++){NSButton *button=[NSButton buttonWithTitle:actions[i] target:self action:selectors[i]];button.font=[NSFont systemFontOfSize:12];button.controlSize=NSControlSizeSmall;button.frame=NSMakeRect(buttonX[i],516,buttonWidth[i],30);[panel addSubview:button];[controls addObject:button];if(i==1)self.animationRenderFrameButton=button;else if(i==2)self.animationRenderPreviewButton=button;else if(i==4)self.animationExportButton=button;}
        self.animationOutputLabel=[NSTextField labelWithString:@"Output folder: not chosen"];self.animationOutputLabel.frame=NSMakeRect(16,556,686,28);self.animationOutputLabel.lineBreakMode=NSLineBreakByTruncatingMiddle;self.animationOutputLabel.selectable=YES;[panel addSubview:self.animationOutputLabel];
        self.animationZBuffer=[NSButton checkboxWithTitle:@"Export Z-buffer" target:nil action:NULL];self.animationZBuffer.frame=NSMakeRect(714,556,170,28);[panel addSubview:self.animationZBuffer];[controls addObject:self.animationZBuffer];
        self.animationStatus=[NSTextField labelWithString:@"Capture rendered main scenes as keyframes. Apply Navigator edits to Main and render before capturing. Output is a numbered PNG sequence."];self.animationStatus.frame=NSMakeRect(16,590,868,20);self.animationStatus.lineBreakMode=NSLineBreakByTruncatingTail;self.animationStatus.maximumNumberOfLines=1;[panel addSubview:self.animationStatus];
        self.animationControls=controls;self.animationWindow.contentView=panel;[self.animationWindow center];[self refreshAnimationKeys:0];
    }
}
- (NSInteger)numberOfRowsInTableView:(NSTableView *)tableView {(void)tableView;return self.animationKeys.count+1;}
- (NSView *)tableView:(NSTableView *)tableView viewForTableColumn:(NSTableColumn *)column row:(NSInteger)row {
    BOOL empty=row==(NSInteger)self.animationKeys.count;NSDictionary *key=empty?@{@"name":@"Empty keyframe",@"frames":@""}:self.animationKeys[row];BOOL thumbnail=[column.identifier isEqual:@"thumbnail"];
    NSString *identifier=[@"animation-" stringByAppendingString:column.identifier];NSTableCellView *cell=[tableView makeViewWithIdentifier:identifier owner:self];
    if(!cell){cell=[[NSTableCellView alloc]initWithFrame:NSMakeRect(0,0,column.width,54)];cell.identifier=identifier;
        if(thumbnail){NSImageView *view=[[NSImageView alloc]initWithFrame:NSMakeRect(3,3,column.width-6,48)];view.imageScaling=NSImageScaleProportionallyUpOrDown;view.autoresizingMask=NSViewWidthSizable;[cell addSubview:view];cell.imageView=view;}
        else{NSTextField *field=[NSTextField labelWithString:@""];field.frame=NSMakeRect(2,18,column.width-4,20);field.autoresizingMask=NSViewWidthSizable;field.lineBreakMode=NSLineBreakByTruncatingTail;[cell addSubview:field];cell.textField=field;}
    }
    if(thumbnail){cell.imageView.image=key[@"image"];cell.imageView.accessibilityLabel=[@"Keyframe preview: " stringByAppendingString:key[@"name"]];}
    else if([column.identifier isEqualToString:@"first-frame"]){NSInteger first=1;for(NSInteger i=0;i<row;i++)first+=[self.animationKeys[i][@"frames"] integerValue];cell.textField.stringValue=[NSString stringWithFormat:@"%ld",(long)first];}
    else cell.textField.stringValue=[column.identifier isEqualToString:@"number"]?(empty?@"Empty":[NSString stringWithFormat:@"%ld",(long)row+1]):[column.identifier isEqualToString:@"name"]?key[@"name"]:(empty?@"":[key[@"frames"] stringValue]);return cell;
}
- (void)animationKeyClicked:(NSTableView *)sender {
    if(self.calculating)return;[self tableViewSelectionDidChange:[NSNotification notificationWithName:NSTableViewSelectionDidChangeNotification object:sender]];
}
- (void)tableViewSelectionDidChange:(NSNotification *)notification {
    if(notification.object!=self.animationTable)return;NSInteger row=self.animationTable.selectedRow;
    if(row<0)return;
    [self pauseAnimationPlayback];if(row==(NSInteger)self.animationKeys.count){self.animationView.image=nil;[self.animationView setNeedsDisplay:YES];return;}
    self.animationView.imageScaling=NSImageScaleProportionallyUpOrDown;
    self.animationFields[0].stringValue=[self.animationKeys[row][@"frames"] stringValue];self.animationView.image=self.animationKeys[row][@"image"];
    NSInteger frame=1;for(NSInteger i=0;i<row;i++)frame+=[self.animationKeys[i][@"frames"] integerValue];self.animationView.frameNumber=frame;self.animationFields[1].integerValue=frame;self.animationTimeline.doubleValue=frame;[self.animationView setNeedsDisplay:YES];
}
- (NSInteger)animationFrameCount {
    if(self.animationKeys.count<2)return self.animationKeys.count;
    NSInteger total=0;for(NSUInteger i=0;i<self.animationKeys.count;i++)if(i+1<self.animationKeys.count||self.animationLoop.state==NSControlStateValueOn)total+=[self.animationKeys[i][@"frames"] integerValue];
    return self.animationLoop.state==NSControlStateValueOn&&self.animationKeys.count>1?total:self.animationKeys.count?total+1:0;
}
- (void)animationScrub:(NSSlider *)sender {self.animationFields[1].integerValue=(NSInteger)lround(sender.doubleValue);}
- (void)animationEstimateEdited:(id)sender {(void)sender;[self updateAnimationPreviewEstimate];}
- (void)updateAnimationPreviewEstimate {
    if(!self.animationPreviewEstimate||self.animationFields.count<8)return;
    int width,height,step,start,end;
    if(!animationInteger(self.animationFields[2].stringValue,16,RENDER_MAX_DIMENSION,&width)||!animationInteger(self.animationFields[3].stringValue,16,RENDER_MAX_DIMENSION,&height)||!animationInteger(self.animationFields[5].stringValue,1,1000,&step)||!animationInteger(self.animationFields[6].stringValue,1,INT_MAX,&start)){self.animationPreviewEstimate.stringValue=@"Preview estimate: —";return;}
    NSInteger total=[self animationFrameCount];end=[self.animationFields[7].stringValue.lowercaseString isEqual:@"last"]?(int)total:self.animationFields[7].intValue;
    if(!total||start>end||end>total){self.animationPreviewEstimate.stringValue=@"Preview estimate: —";return;}
    double rate=0;int samples=0;for(NSDictionary *key in self.animationKeys){double sample=[key[@"secondsPerPixel"] doubleValue];if(isfinite(sample)&&sample>0){rate+=sample;samples++;}}
    rate=samples?rate/samples:self.animationSecondsPerPixel;
    if(!(rate>0)){self.animationPreviewEstimate.stringValue=@"Preview estimate: needs a rendered keyframe";return;}
    double divisor=1<<(int)self.animationPreviewScale.indexOfSelectedItem;double factor=fmax(1/divisor,16.0/fmin(width,height));
    double seconds=rate*MAX(16,lround(width*factor))*MAX(16,lround(height*factor))*((end-start)/step+1);
    NSInteger estimate=(NSInteger)ceil(seconds);self.animationPreviewEstimate.stringValue=[NSString stringWithFormat:@"Estimated preview total: ~%ld:%02ld",(long)(estimate/60),(long)(estimate%60)];
}
- (void)refreshAnimationKeys:(NSInteger)selection {
    [self updateAnimationPreviewEstimate];
    self.animationTimeline.maxValue=MAX(2,[self animationFrameCount]);self.animationTimeline.doubleValue=MAX(1,MIN([self animationFrameCount],self.animationFields[1].integerValue));
    [self.animationTable reloadData];selection=MAX(0,MIN(selection,(NSInteger)self.animationKeys.count));[self.animationTable selectRowIndexes:[NSIndexSet indexSetWithIndex:selection] byExtendingSelection:NO];[self.animationTable scrollRowToVisible:selection];[self tableViewSelectionDidChange:[NSNotification notificationWithName:NSTableViewSelectionDidChangeNotification object:self.animationTable]];
    self.animationStatus.stringValue=[NSString stringWithFormat:@"%lu keyframes · %ld frames. Capture uses the last completed main render.",(unsigned long)self.animationKeys.count,(long)[self animationFrameCount]];
}
- (void)animationFieldEdited:(id)sender {
    if(self.calculating)return;
    [self updateAnimationPreviewEstimate];
    if(sender==self.animationFields[1]&&self.animationPlaybackFrames.count){[self pauseAnimationPlayback];[self seekAnimationPlayback:self.animationFields[1].integerValue];return;}
    if((sender==self.animationFields[4]||sender==self.animationFields[5])&&self.animationPlaybackFrames.count){int fps,step;if(!animationInteger(self.animationFields[4].stringValue,1,240,&fps)||!animationInteger(self.animationFields[5].stringValue,1,1000,&step)){self.animationStatus.stringValue=@"FPS must be 1–240 and preview every nth must be 1–1000.";return;}self.animationPlaybackInterval=(double)step/fps;if(self.animationPlaybackTimer)[self resumeAnimationPlayback];return;}
    [self clearAnimationPlayback];
    if(sender==self.animationFields[0]){int frames;if(!animationInteger(self.animationFields[0].stringValue,1,10000,&frames)){self.animationStatus.stringValue=@"Frames to next must be 1–10000.";return;}NSInteger row=self.animationTable.selectedRow;if(row>=0&&row<(NSInteger)self.animationKeys.count){NSMutableDictionary *key=[self.animationKeys[row] mutableCopy];key[@"frames"]=@(frames);self.animationKeys[row]=key;}}
    [self refreshAnimationKeys:self.animationTable.selectedRow];
}
- (void)clearAnimation {
    [self.animationWindow makeFirstResponder:nil];[self clearAnimationPlayback];
    [self.animationKeys removeAllObjects];
    RenderOptions settings=self.formulaSettings;
    NSArray *defaults=@[@"30",@"1",[NSString stringWithFormat:@"%d",settings.width?MAX(16,settings.width/MAX(1,settings.oversampling)):480],[NSString stringWithFormat:@"%d",settings.height?MAX(16,settings.height/MAX(1,settings.oversampling)):360],@"24",@"1",@"1",@"last"];
    for(int i=0;i<8;i++)self.animationFields[i].stringValue=defaults[i];
    self.animationLoop.state=self.animationFrameOverlay.state=self.animationZBuffer.state=NSControlStateValueOff;
    [self.animationInterpolation selectItemAtIndex:0];[self.animationSampling selectItemAtIndex:0];[self.animationPreviewScale selectItemAtIndex:1];[self.animationFrameColor selectItemAtIndex:0];[self animationOverlayChanged:nil];
    self.animationOutputFolder=nil;self.animationOutputLabel.stringValue=@"Output folder: not chosen";
    self.animationWindow.representedURL=nil;self.animationWindow.title=@"Animation maker";
    self.animationSecondsPerPixel=0;self.animationView.image=nil;self.animationView.frameNumber=1;
    for(NSButton *check in self.animationProcessingChecks)check.state=NSControlStateValueOff;
    double processingDefaults[]={30,1,settings.de_stop>0?settings.de_stop:.5,settings.ray_step>0?settings.ray_step:.5,settings.normal_smoothing,settings.iterations>0?settings.iterations:60,settings.program.min_iterations};
    for(NSUInteger i=0;i<self.animationProcessingFields.count;i++)self.animationProcessingFields[i].doubleValue=processingDefaults[i];
    [self syncAnimationProcessing];[self refreshAnimationKeys:0];
}
- (void)animationKeyAction:(NSButton *)sender {
    if(self.calculating)return;if(sender.tag==7){[self clearAnimation];return;}[self clearAnimationPlayback];NSInteger row=self.animationTable.selectedRow;
    if(sender.tag<2){
        if(!self.formulaKnown||!self.completedRender||self.parametersPendingRender){self.animationStatus.stringValue=@"Render the main scene before capturing a keyframe.";return;}
        if(self.animationKeys.count>=1000&&(sender.tag==0||row==(NSInteger)self.animationKeys.count)){self.animationStatus.stringValue=@"At most 1000 keyframes are supported.";return;}
        if(sender.tag==1&&row<0)return;int frames=30;if(!animationInteger(self.animationFields[0].stringValue,1,10000,&frames)){self.animationStatus.stringValue=@"Frames to next must be 1–10000.";return;}
        NSData *source=[self animationCompactSource:self.currentPath];if(!source){self.animationStatus.stringValue=@"The current scene file is unavailable.";return;}NSString *frozenPath=[self animationRestoreSource:source];if(!frozenPath){self.animationStatus.stringValue=@"Could not snapshot the current scene file.";return;}
        RenderOptions settings=self.formulaSettings;settings.camera_override=1;settings.cancel_token=NULL;settings.navigation_count=0;settings.reuse_surface=settings.preview_cache=0;
        NSMutableDictionary *key=[@{@"name":[NSString stringWithFormat:@"Scene %lu",(unsigned long)(sender.tag==0?self.animationKeys.count+1:row+1)],@"settings":[NSData dataWithBytes:&settings length:sizeof settings],@"path":frozenPath,@"frames":@(frames)} mutableCopy];
        if(self.animationSecondsPerPixel>0)key[@"secondsPerPixel"]=@(self.animationSecondsPerPixel);NSImage *thumbnail=animationThumbnail(self.completedRender);if(thumbnail)key[@"image"]=thumbnail;
        if(sender.tag==0){row=MIN(row+1,(NSInteger)self.animationKeys.count);[self.animationKeys insertObject:key atIndex:row];}
        else if(row==(NSInteger)self.animationKeys.count){[self.animationKeys addObject:key];row=self.animationKeys.count;}
        else{key[@"frames"]=self.animationKeys[row][@"frames"];self.animationKeys[row]=key;}
    }else if(sender.tag==6){
        if(row<0||row+1>=(NSInteger)self.animationKeys.count){self.animationStatus.stringValue=@"Select a keyframe with a following keyframe to interpolate.";return;}
        if(self.animationKeys.count>=1000){self.animationStatus.stringValue=@"At most 1000 keyframes are supported.";return;}
        NSDictionary *left=self.animationKeys[row],*right=self.animationKeys[row+1];
        RenderOptions midpoint=animation_interpolate(animationUnpack(left[@"settings"]),animationUnpack(right[@"settings"]),.5);
        NSMutableDictionary *key=[@{@"name":@"Interpolated scene",@"settings":[NSData dataWithBytes:&midpoint length:sizeof midpoint],@"path":left[@"path"],@"frames":left[@"frames"]} mutableCopy];
        [self.animationKeys insertObject:key atIndex:++row];[self refreshAnimationKeys:row];[self renderAnimationKeyPreviewsFrom:row through:row];return;
    }else{
        if(row<0||row>=(NSInteger)self.animationKeys.count)return;
        if(sender.tag==2){[self.animationKeys removeObjectAtIndex:row];row=MIN(row,(NSInteger)self.animationKeys.count);}
        if(sender.tag==3&&row>0){[self.animationKeys exchangeObjectAtIndex:row withObjectAtIndex:row-1];row--;}
        if(sender.tag==4&&row+1<(NSInteger)self.animationKeys.count){[self.animationKeys exchangeObjectAtIndex:row withObjectAtIndex:row+1];row++;}
        if(sender.tag==5){NSDictionary *key=self.animationKeys[row];RenderOptions options=animationUnpack(key[@"settings"]);NSString *path=key[@"path"];[self loadParameterSettings:options path:path.length?path:nil source:@"Animation keyframe"];self.animationStatus.stringValue=@"Keyframe parameters loaded to Main. Rendering…";}
    }
    [self refreshAnimationKeys:row];
}
- (RenderOptions)animationOptionsAtFrame:(NSInteger)frame keys:(NSArray *)keys loop:(BOOL)loop ease:(BOOL)ease path:(NSString **)path {
    NSInteger index=0;double t=0;
    for(NSUInteger i=0;i<keys.count;i++){
        if(i+1==keys.count&&!loop){index=i;t=0;break;}
        NSInteger length=[keys[i][@"frames"] integerValue];if(frame<length){index=i;t=(double)frame/length;break;}frame-=length;
    }
    NSDictionary *left=keys[index],*right=keys[(index+1)%keys.count];RenderOptions a=animationUnpack(left[@"settings"]),b=animationUnpack(right[@"settings"]);
    if(path){NSString *source=left[@"path"];*path=source.length?source:nil;}
    if(!ease)return animation_interpolate(a,b,t);
    NSInteger previous=loop?(index+keys.count-1)%keys.count:MAX(0,index-1);
    NSInteger next=loop?(index+1)%keys.count:MIN((NSInteger)keys.count-1,index+1);
    NSInteger following=loop?(index+2)%keys.count:MIN((NSInteger)keys.count-1,index+2);
    double u=animation_bezier_time(t,[keys[previous][@"frames"] doubleValue],[keys[index][@"frames"] doubleValue],[keys[next][@"frames"] doubleValue]);
    RenderOptions before=animationUnpack(keys[previous][@"settings"]),after=animationUnpack(keys[following][@"settings"]);
    b=animationUnpack(keys[next][@"settings"]);
    return t<.5?animation_bezier_blend(before,a,b,a,u):animation_bezier_blend(a,b,after,a,u);
}
- (BOOL)animationRenderValues:(int *)width height:(int *)height fps:(int *)fps step:(int *)step start:(int *)start end:(int *)end {
    NSInteger total=[self animationFrameCount];if(!self.animationKeys.count||total<1||total>100000){self.animationStatus.stringValue=@"Capture keyframes first; animations may contain at most 100000 frames.";return NO;}
    if(!animationInteger(self.animationFields[2].stringValue,16,RENDER_MAX_DIMENSION,width)||!animationInteger(self.animationFields[3].stringValue,16,RENDER_MAX_DIMENSION,height)||!animationInteger(self.animationFields[4].stringValue,1,240,fps)||!animationInteger(self.animationFields[5].stringValue,1,1000,step)||!animationInteger(self.animationFields[6].stringValue,1,(int)total,start)||(![self.animationFields[7].stringValue.lowercaseString isEqualToString:@"last"]&&!animationInteger(self.animationFields[7].stringValue,*start,(int)total,end))){self.animationStatus.stringValue=@"Check dimensions (16–16384), FPS (1–240), preview step (1–1000), and frame range (1–last).";return NO;}
    if([self.animationFields[7].stringValue.lowercaseString isEqualToString:@"last"])*end=(int)total;
    int sampling=(int)self.animationSampling.indexOfSelectedItem+1;if(*width*sampling>RENDER_MAX_DIMENSION||*height*sampling>RENDER_MAX_DIMENSION){self.animationStatus.stringValue=@"Oversampled animation dimensions must not exceed 16384.";return NO;}return YES;
}
- (void)animationRenderFrame:(id)sender {if(self.calculating){if(self.animationRunning&&self.animationRenderKind==1)[self stopRender:sender];return;}[self startAnimationPreview:YES single:YES output:nil];}
- (void)animationRenderPreview:(id)sender {if(self.calculating){if(self.animationRunning&&self.animationRenderKind==2)[self stopRender:sender];return;}[self startAnimationPreview:YES single:NO output:nil];}
- (void)chooseAnimationOutputFolder:(id)sender {
    (void)sender;if(self.calculating)return;NSOpenPanel *panel=[NSOpenPanel openPanel];panel.canChooseDirectories=YES;panel.canChooseFiles=NO;panel.canCreateDirectories=YES;panel.prompt=@"Choose Output Folder";
    if(self.animationOutputFolder.length)panel.directoryURL=[NSURL fileURLWithPath:self.animationOutputFolder];
    [panel beginSheetModalForWindow:self.animationWindow completionHandler:^(NSModalResponse response){if(response!=NSModalResponseOK)return;retainUserFileSelection(panel.URL);self.animationOutputFolder=panel.URL.path;self.animationOutputLabel.stringValue=[@"Output folder: " stringByAppendingString:self.animationOutputFolder];self.animationStatus.stringValue=@"Output folder chosen. Press Start Render when ready.";}];
}
- (void)animationExport:(id)sender {
    if(self.calculating){if(self.animationRunning&&self.animationRenderKind==3)[self stopRender:sender];return;}int width,height,fps,step,start,end;if(![self animationRenderValues:&width height:&height fps:&fps step:&step start:&start end:&end])return;
    BOOL directory=NO;if(!self.animationOutputFolder.length||![NSFileManager.defaultManager fileExistsAtPath:self.animationOutputFolder isDirectory:&directory]||!directory){self.animationStatus.stringValue=@"Choose an existing output folder before pressing Start Render.";return;}
    [self startAnimationPreview:NO single:NO output:self.animationOutputFolder];
}
- (void)startAnimationPreview:(BOOL)preview single:(BOOL)single output:(NSString *)output {
    if(self.calculating)return;int width,height,fps,step,start,end;if(![self animationRenderValues:&width height:&height fps:&fps step:&step start:&start end:&end])return;
    if(single){if(!animationInteger(self.animationFields[1].stringValue,1,(int)[self animationFrameCount],&start)){self.animationStatus.stringValue=@"Current frame is outside the animation.";return;}end=start;}
    if(!preview)step=1;
    [self clearAnimationPlayback];self.animationView.imageScaling=NSImageScaleProportionallyDown;
    NSString *previewFolder=preview&&!single?[[self applicationTemporaryFolderURL].path stringByAppendingPathComponent:[@"Mandelbulb3Dx-preview-" stringByAppendingString:NSUUID.UUID.UUIDString]]:nil;
    if(previewFolder&&![NSFileManager.defaultManager createDirectoryAtPath:previewFolder withIntermediateDirectories:NO attributes:nil error:nil]){self.animationStatus.stringValue=@"Could not create preview frame cache.";return;}
    BOOL exportDepth=output&&self.animationZBuffer.state==NSControlStateValueOn;
    NSArray *keys=[self.animationKeys copy];BOOL loop=self.animationLoop.state==NSControlStateValueOn,ease=self.animationInterpolation.indexOfSelectedItem==1;int sampling=(int)self.animationSampling.indexOfSelectedItem+1,previewDivisor=1<<(int)self.animationPreviewScale.indexOfSelectedItem;
    render_cancel(self.navigatorCancelToken);self.navigatorGeneration++;self.previewPending=NO;self.navigatorRefinementTicket++;self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;
    RenderCancelToken *token=render_cancel_create();if(!token){if(previewFolder)[NSFileManager.defaultManager removeItemAtPath:previewFolder error:nil];self.animationStatus.stringValue=@"Not enough memory to start animation.";return;}self.mainCancelToken=token;self.animationPlaybackFolder=previewFolder;NSUInteger animationGeneration=++self.generation;self.animationRunning=YES;self.animationRenderKind=preview?(single?1:2):3;self.animationStopRequested=NO;[self setCalculating:YES];
    [self updateAnimationPreviewEstimate];
    NSTimeInterval animationStarted=NSProcessInfo.processInfo.systemUptime;
    self.animationFields[1].intValue=start;
    self.animationStatus.stringValue=@"Rendering animation… · Elapsed 0:00";self.statusLabel.stringValue=self.animationStatus.stringValue;
    dispatch_async(self.renderQueue,^{
        __block int completed=0;NSInteger elapsedSeconds=0;int skipped=0;NSString *failure=nil;BOOL stopped=NO;NSMutableArray *cachedFrames=[NSMutableArray array];
        for(int frame=start;frame<=end;frame+=step){@autoreleasepool{
            NSString *outputImage=output?[output stringByAppendingPathComponent:[NSString stringWithFormat:@"frame-%06d.png",frame]]:nil;
            NSString *outputDepth=exportDepth?[output stringByAppendingPathComponent:[NSString stringWithFormat:@"zbuffer-%06d.png",frame]]:nil;
            BOOL imageExists=outputImage&&[NSFileManager.defaultManager fileExistsAtPath:outputImage];
            BOOL depthExists=outputDepth&&[NSFileManager.defaultManager fileExistsAtPath:outputDepth];
            if(imageExists&&(!exportDepth||depthExists)){completed++;skipped++;continue;}

            int completedBeforeFrame=completed;NSInteger elapsedBeforeFrame=elapsedSeconds;
            interactiveUI(^{if(animationGeneration!=self.generation)return;self.animationFields[1].intValue=frame;NSString *message=[NSString stringWithFormat:@"Rendering frame %d / %d · %d completed%@ · Elapsed %ld:%02ld",frame,end,completedBeforeFrame,preview?@" (preview)":@"",(long)(elapsedBeforeFrame/60),(long)(elapsedBeforeFrame%60)];self.animationStatus.stringValue=message;self.statusLabel.stringValue=message;});
            NSString *path;RenderOptions options=[self animationOptionsAtFrame:frame-1 keys:keys loop:loop ease:ease path:&path];
            double threshold=options.de_stop/options.width,blurLimit=options.dof.clip_radius/options.width;options.width=width*sampling;options.height=height*sampling;options.oversampling=options.viewing=sampling;options.de_stop=threshold*options.width;options.dof.clip_radius=fmax(.1,fmin(1000,blurLimit*options.width));options.camera_override=1;options.reuse_surface=1;options.preview_cache=1;
            if(preview){
                /* Preview sampling and resolution are independent of exported dimensions. */
                int fullWidth=options.width;double factor=fmax(1.0/previewDivisor,16.0/fmin(width,height));
                options.width=MAX(16,(int)lround(width*factor));options.height=MAX(16,(int)lround(height*factor));
                options.de_stop=fmax(1e-6,options.de_stop*options.width/fullWidth);options.dof.clip_radius=fmax(.1,options.dof.clip_radius*options.width/fullWidth);
                options.oversampling=options.viewing=1;options.normals_override=1;options.normal_smoothing=MIN(2,options.normal_smoothing);
                options.shadows_override=1;options.shadows.ambient_rays=MIN(7,options.shadows.ambient_rays);options.shadows.ambient_steps=MIN(64,options.shadows.ambient_steps);
            }options.cancel_token=token;
            RenderResult result=render_scene_with_options(path.fileSystemRepresentation,options);
            if(result.cancelled){stopped=YES;free(result.rgba);break;}
            if(!result.rgba){failure=[NSString stringWithUTF8String:result.error];break;}
            NSImage *image=preview?imageForRender(result,1):animationResolvedImage(result,sampling);free(result.rgba);
            if(!image){failure=@"Not enough memory to display frame.";break;}
            if((output&&!imageExists)||previewFolder){NSBitmapImageRep *bitmap=(NSBitmapImageRep *)image.representations.firstObject;NSData *png=[bitmap representationUsingType:NSBitmapImageFileTypePNG properties:@{}];NSError *error=nil;NSString *file=[(output?output:previewFolder) stringByAppendingPathComponent:[NSString stringWithFormat:@"frame-%06d.png",frame]];
                if(!png||![png writeToFile:file options:NSDataWritingAtomic error:&error]){failure=error.localizedDescription?error.localizedDescription:@"Could not encode animation frame.";break;}if(previewFolder)[cachedFrames addObject:@{@"path":file,@"frame":@(frame)}];}
            if(exportDepth&&!depthExists){char depthError[512];NSString *depthPath=[output stringByAppendingPathComponent:[NSString stringWithFormat:@"zbuffer-%06d.png",frame]];if(!render_export_zbuffer(depthPath.fileSystemRepresentation,1,width,height,depthError)){failure=[NSString stringWithUTF8String:depthError];break;}}
            elapsedSeconds=(NSInteger)(NSProcessInfo.processInfo.systemUptime-animationStarted);NSInteger frameElapsed=elapsedSeconds;completed++;int displayed=frame,count=completed;interactiveUI(^{if(animationGeneration!=self.generation)return;self.imageView.image=image;self.animationView.image=image;self.animationView.frameNumber=displayed;[self.animationView setNeedsDisplay:YES];self.animationFields[1].intValue=displayed;self.animationTimeline.doubleValue=displayed;self.animationStatus.stringValue=[NSString stringWithFormat:@"Frame %d / %d · %d completed%@ · Elapsed %ld:%02ld",displayed,end,count,preview?@" (preview)":@"",(long)(frameElapsed/60),(long)(frameElapsed%60)];self.statusLabel.stringValue=self.animationStatus.stringValue;if(preview&&!single){NSInteger total=(end-start)/step+1;NSInteger estimate=(NSInteger)ceil((NSProcessInfo.processInfo.systemUptime-animationStarted)*total/count);self.animationSecondsPerPixel=(NSProcessInfo.processInfo.systemUptime-animationStarted)/count/((double)options.width*options.height);self.animationPreviewEstimate.stringValue=[NSString stringWithFormat:@"Estimated preview total: ~%ld:%02ld",(long)(estimate/60),(long)(estimate%60)];}});

        }}
        if(output){NSDictionary *manifest=@{@"format":@"Mandelbulb3Dx PNG sequence",@"fps":@(fps),@"firstFrame":@(start),@"lastRequestedFrame":@(end),@"completedFrames":@(completed),@"skippedFrames":@(skipped),@"zbuffer":@(exportDepth),@"width":@(width),@"height":@(height),@"status":failure?@"failed":stopped?@"stopped":@"complete"};NSData *json=[NSJSONSerialization dataWithJSONObject:manifest options:NSJSONWritingPrettyPrinted error:nil];[json writeToFile:[output stringByAppendingPathComponent:@"animation.json"] atomically:YES];}
        interactiveUI(^{if(self.mainCancelToken==token)self.mainCancelToken=NULL;render_cancel_destroy(token);if(animationGeneration!=self.generation){if(previewFolder)[NSFileManager.defaultManager removeItemAtPath:previewFolder error:nil];return;}self.animationRunning=NO;self.animationRenderKind=0;self.animationStopRequested=NO;[self setCalculating:NO];if(previewFolder&&!failure&&cachedFrames.count){self.animationPlaybackFolder=previewFolder;self.animationPlaybackFrames=[cachedFrames copy];self.animationPlaybackIndex=0;self.animationPlaybackInterval=(double)step/fps;if(stopped)[self pauseAnimationPlayback];else [self resumeAnimationPlayback];}else if(previewFolder)[NSFileManager.defaultManager removeItemAtPath:previewFolder error:nil];NSString *message=failure?failure:[NSString stringWithFormat:@"%@ · %d frames · Elapsed %ld:%02ld%@",stopped?@"Animation stopped":@"Animation complete",completed,(long)((NSProcessInfo.processInfo.systemUptime-animationStarted)/60),(long)(NSProcessInfo.processInfo.systemUptime-animationStarted)%60,output?[@" · " stringByAppendingString:output]:@""];self.animationStatus.stringValue=message;self.statusLabel.stringValue=message;});
    });
}
- (NSData *)animationCompactSource:(NSString *)path {
    if(!path.length)return [NSData data];NSFileHandle *file=[NSFileHandle fileHandleForReadingAtPath:path];if(!file)return nil;
    NSData *result=nil;@try{
        NSData *header=[file readDataOfLength:840];if(header.length==840){const unsigned char *p=header.bytes;uint64_t w=animationRead32(p+4),h=animationRead32(p+8),offset=840+w*h*18,length=[file seekToEndOfFile];
            if(w>=16&&w<=RENDER_MAX_DIMENSION&&h>=16&&h<=RENDER_MAX_DIMENSION&&length>=offset+1136){
                [file seekToFileOffset:offset];NSMutableData *compact=[header mutableCopy];[compact appendData:[file readDataOfLength:1136]];
                uint64_t nativeOffset=offset+1136;[file seekToFileOffset:nativeOffset];NSData *magic=[file readDataOfLength:8];
                if(magic.length!=8||memcmp(magic.bytes,"IPMACM3I",8))nativeOffset+=w*h*4;
                if(length>=nativeOffset+16&&length-nativeOffset<=65536){[file seekToFileOffset:nativeOffset];NSData *extra=[file readDataToEndOfFile];if(extra.length>=8&&!memcmp(extra.bytes,"IPMACM3I",8))[compact appendData:extra];}
                result=compact;
            }
        }
    }@catch(NSException *exception){(void)exception;}[file closeFile];return result;
}
- (NSString *)animationRestoreSource:(NSData *)data {
    if(!data.length)return @"";if(data.length<1976||data.length>66376)return nil;
    const unsigned char *p=data.bytes;uint64_t w=animationRead32(p+4),h=animationRead32(p+8);if(w<16||w>RENDER_MAX_DIMENSION||h<16||h>RENDER_MAX_DIMENSION)return nil;
    NSString *path=[[self applicationTemporaryFolderURL].path stringByAppendingPathComponent:[@"Mandelbulb3Dx-animation-" stringByAppendingString:NSUUID.UUID.UUIDString]];
    if(![NSFileManager.defaultManager createFileAtPath:path contents:[data subdataWithRange:NSMakeRange(0,840)] attributes:nil])return nil;
    NSFileHandle *file=[NSFileHandle fileHandleForWritingAtPath:path];BOOL ok=YES;@try{[file seekToFileOffset:840+w*h*18];[file writeData:[data subdataWithRange:NSMakeRange(840,data.length-840)]];}@catch(NSException *exception){(void)exception;ok=NO;}[file closeFile];
    if(!ok){[NSFileManager.defaultManager removeItemAtPath:path error:nil];return nil;}[self.animationTemporarySources addObject:path];return path;
}
- (NSDictionary *)animationProject {return [self animationProjectIncludingThumbnails:YES];}
- (NSDictionary *)animationProjectIncludingThumbnails:(BOOL)includeThumbnails {
    NSMutableArray *keys=[NSMutableArray array];for(NSDictionary *key in self.animationKeys){NSData *source=[self animationCompactSource:key[@"path"]];if(!source){self.animationStatus.stringValue=@"A keyframe source file is unavailable; load and recapture that scene.";return nil;}NSMutableDictionary *entry=[@{@"name":key[@"name"],@"frames":key[@"frames"],@"settings":key[@"settings"],@"source":source} mutableCopy];if(key[@"secondsPerPixel"])entry[@"secondsPerPixel"]=key[@"secondsPerPixel"];NSImage *image=key[@"image"];NSBitmapImageRep *bitmap=(NSBitmapImageRep *)image.representations.firstObject;if(includeThumbnails&&[bitmap isKindOfClass:NSBitmapImageRep.class]){NSData *thumbnail=[bitmap representationUsingType:NSBitmapImageFileTypePNG properties:@{}];if(thumbnail)entry[@"thumbnail"]=thumbnail;}[keys addObject:entry];}
    NSMutableArray *fields=[NSMutableArray array];for(NSTextField *field in self.animationFields)[fields addObject:field.stringValue];
    return @{@"exportZBuffer":@(self.animationZBuffer.state==NSControlStateValueOn),@"format":@"Mandelbulb3DxAnimation",@"version":@1,@"optionsSize":@(sizeof(RenderOptions)),@"settingsLayout":@"build9",@"keys":keys,@"fields":fields,@"loop":@(self.animationLoop.state==NSControlStateValueOn),@"interpolation":@(self.animationInterpolation.indexOfSelectedItem),@"oversampling":@(self.animationSampling.indexOfSelectedItem),@"previewScale":@(self.animationPreviewScale.indexOfSelectedItem),@"outputFolder":self.animationOutputFolder?self.animationOutputFolder:@"",@"frameOverlay":@(self.animationFrameOverlay.state==NSControlStateValueOn),@"frameColor":@(self.animationFrameColor.indexOfSelectedItem)};
}
- (BOOL)loadAnimationProject:(NSDictionary *)project {
    if(![project isKindOfClass:NSDictionary.class]||![project[@"format"] isEqual:@"Mandelbulb3DxAnimation"]||![project[@"version"] isEqual:@1]||!animationOptionsSize([project[@"optionsSize"] unsignedIntegerValue])||![project[@"settingsLayout"] isEqual:@"build9"]||![project[@"keys"] isKindOfClass:NSArray.class]||[project[@"keys"] count]>1000||![project[@"fields"] isKindOfClass:NSArray.class]||[project[@"fields"] count]!=8)return NO;
    for(id field in project[@"fields"])if(![field isKindOfClass:NSString.class]||[field length]>128)return NO;
    for(NSString *key in @[@"loop",@"interpolation",@"oversampling"])if(![project[key] isKindOfClass:NSNumber.class])return NO;
    NSMutableArray *keys=[NSMutableArray array];for(id entry in project[@"keys"]){
        if(![entry isKindOfClass:NSDictionary.class]||![entry[@"settings"] isKindOfClass:NSData.class]||!animationOptionsSize([entry[@"settings"] length])||![entry[@"source"] isKindOfClass:NSData.class]||![entry[@"name"] isKindOfClass:NSString.class]||[entry[@"name"] length]>256||![entry[@"frames"] isKindOfClass:NSNumber.class]||[entry[@"frames"] integerValue]<1||[entry[@"frames"] integerValue]>10000||[entry[@"frames"] doubleValue]!=[entry[@"frames"] integerValue])return NO;
        RenderOptions options=animationUnpack(entry[@"settings"]);if(options.width<16||options.width>RENDER_MAX_DIMENSION||options.height<16||options.height>RENDER_MAX_DIMENSION||!isfinite(options.de_stop)||options.de_stop<=0)return NO;
#ifdef USE_RUST_ENGINE
        if(options.program.slots[6].count||options.program.slots[7].count)return NO;
#endif
        NSString *path=[self animationRestoreSource:entry[@"source"]];if(!path)return NO;
        NSMutableDictionary *key=[@{@"name":entry[@"name"],@"frames":entry[@"frames"],@"settings":[NSData dataWithBytes:&options length:sizeof options],@"path":path} mutableCopy];if([entry[@"secondsPerPixel"] isKindOfClass:NSNumber.class]&&[entry[@"secondsPerPixel"] doubleValue]>0)key[@"secondsPerPixel"]=entry[@"secondsPerPixel"];if([entry[@"thumbnail"] isKindOfClass:NSData.class]&&[entry[@"thumbnail"] length]<4000000){NSImage *image=[[NSImage alloc]initWithData:entry[@"thumbnail"]];if(image)key[@"image"]=image;}[keys addObject:key];
    }
    for(NSString *key in @[@"frameOverlay",@"frameColor"])if(project[key]&&![project[key] isKindOfClass:NSNumber.class])return NO;
    self.animationZBuffer.state=[project[@"exportZBuffer"] boolValue];
    self.animationFrameOverlay.state=[project[@"frameOverlay"] boolValue];[self.animationFrameColor selectItemAtIndex:[project[@"frameColor"] intValue]==1?1:0];[self animationOverlayChanged:nil];
    if(project[@"previewScale"]&&![project[@"previewScale"] isKindOfClass:NSNumber.class])return NO;
    if(project[@"outputFolder"]&&![project[@"outputFolder"] isKindOfClass:NSString.class])return NO;
    [self.animationPreviewScale selectItemAtIndex:project[@"previewScale"]?MAX(0,MIN(3,[project[@"previewScale"] integerValue])):1];self.animationOutputFolder=project[@"outputFolder"]?project[@"outputFolder"]:@"";self.animationOutputLabel.stringValue=self.animationOutputFolder.length?[@"Output folder: " stringByAppendingString:self.animationOutputFolder]:@"Output folder: not chosen";
    [self clearAnimationPlayback];self.animationKeys=keys;self.animationView.image=nil;for(int i=0;i<8;i++)self.animationFields[i].stringValue=project[@"fields"][i];self.animationLoop.state=[project[@"loop"] boolValue];[self.animationInterpolation selectItemAtIndex:MAX(0,MIN(1,[project[@"interpolation"] integerValue]))];[self.animationSampling selectItemAtIndex:MAX(0,MIN(5,[project[@"oversampling"] integerValue]))];[self refreshAnimationKeys:keys.count];return YES;
}
- (void)animationSave:(id)sender {
    (void)sender;if(self.calculating)return;NSDictionary *project=[self animationProjectIncludingThumbnails:NO];if(!project)return;
    NSMutableArray *thumbnailBitmaps=[NSMutableArray array];for(NSDictionary *key in self.animationKeys){NSImage *image=key[@"image"];id bitmap=image.representations.firstObject;[thumbnailBitmaps addObject:[bitmap isKindOfClass:NSBitmapImageRep.class]?bitmap:NSNull.null];}
    NSSavePanel *panel=[NSSavePanel savePanel];panel.allowedFileTypes=@[@"m3a"];panel.nameFieldStringValue=@"Animation.m3a";restoreDialogLocation(panel,YES,@"m3a",panel.nameFieldStringValue);
    [panel beginSheetModalForWindow:self.animationWindow completionHandler:^(NSModalResponse response){if(response!=NSModalResponseOK)return;rememberDialogURL(panel.URL,YES);
        [self saveAnimationProject:project thumbnailBitmaps:thumbnailBitmaps toURL:panel.URL];
    }];
}
- (void)saveAnimationProject:(NSDictionary *)project thumbnailBitmaps:(NSArray *)thumbnailBitmaps toURL:(NSURL *)url {
    if(self.calculating)return;
    render_cancel(self.navigatorCancelToken);self.navigatorGeneration++;self.previewPending=NO;self.navigatorRefinementTicket++;NSUInteger fileGeneration=++self.generation;
    self.savingAnimation=YES;self.quitMenuItem.enabled=NO;[self setCalculating:YES];self.animationStatus.stringValue=@"Saving .m3a parameters…";
    dispatch_async(self.renderQueue,^{
        NSString *message=nil;NSData *data=[self animationM3AData:project thumbnailBitmaps:thumbnailBitmaps error:&message];NSError *error=nil;
        if(!data&&!message)message=@"Could not encode animation parameters.";
        if(data&&![data writeToURL:url options:NSDataWritingAtomic error:&error])message=error.localizedDescription;
        interactiveUI(^{
            self.savingAnimation=NO;self.quitMenuItem.enabled=!self.savingM3I;
            if(fileGeneration!=self.generation)return;
            [self setCalculating:NO];if(!message){retainUserFileSelection(url);self.animationWindow.representedURL=url;self.animationWindow.title=[@"Animation maker — " stringByAppendingString:url.lastPathComponent];}
            self.animationStatus.stringValue=message?message:@"Saved .m3a (version 5). Native preview/FPS settings are preserved in an optional extension.";
        });
    });
}
- (void)animationOpen:(id)sender {
    (void)sender;if(self.calculating)return;NSOpenPanel *panel=[NSOpenPanel openPanel];panel.allowedFileTypes=@[@"m3a",@"m3dxanim"];restoreDialogLocation(panel,YES,nil,nil);
    [panel beginSheetModalForWindow:self.animationWindow completionHandler:^(NSModalResponse response){if(response!=NSModalResponseOK)return;rememberDialogURL(panel.URL,YES);
        render_cancel(self.navigatorCancelToken);self.navigatorGeneration++;self.previewPending=NO;self.navigatorRefinementTicket++;NSUInteger fileGeneration=++self.generation;[self setCalculating:YES];self.animationStatus.stringValue=@"Opening animation…";
        dispatch_async(self.renderQueue,^{NSError *error=nil;NSData *data=[NSData dataWithContentsOfURL:panel.URL options:NSDataReadingMappedIfSafe error:&error];NSString *message=error.localizedDescription,*warning=nil;NSDictionary *project=nil;
            if(data){if([panel.URL.pathExtension.lowercaseString isEqualToString:@"m3a"])project=[self animationReadM3A:data warning:&warning error:&message];else project=[NSPropertyListSerialization propertyListWithData:data options:NSPropertyListImmutable format:nil error:&error];}
            interactiveUI(^{if(fileGeneration!=self.generation)return;[self setCalculating:NO];if(!project||![self loadAnimationProject:project])self.animationStatus.stringValue=message?message:@"Invalid or incompatible animation project.";else {self.animationWindow.representedURL=panel.URL;self.animationWindow.title=[@"Animation maker — " stringByAppendingString:panel.URL.lastPathComponent];if(warning.length)self.animationStatus.stringValue=warning;}});});
    }];
}

- (void)animationOverlayChanged:(id)sender {(void)sender;self.animationView.showFrameNumber=self.animationFrameOverlay.state==NSControlStateValueOn;self.animationView.whiteFrameNumber=self.animationFrameColor.indexOfSelectedItem==0;[self.animationView setNeedsDisplay:YES];}
- (void)pauseAnimationPlayback {[self.animationPlaybackTimer invalidate];self.animationPlaybackTimer=nil;self.animationPause.title=@"Resume";self.animationPause.enabled=self.animationPlaybackFrames.count>0;}
- (void)clearAnimationPlayback {[self pauseAnimationPlayback];self.animationPlaybackFrames=nil;self.animationPlaybackIndex=0;self.animationPause.enabled=NO;if(self.animationPlaybackFolder)[NSFileManager.defaultManager removeItemAtPath:self.animationPlaybackFolder error:nil];self.animationPlaybackFolder=nil;}
- (void)advanceAnimationPlayback {
    if(!self.animationPlaybackFrames.count)return;
    NSDictionary *frame=self.animationPlaybackFrames[self.animationPlaybackIndex%self.animationPlaybackFrames.count];NSImage *image=[[NSImage alloc]initWithContentsOfFile:frame[@"path"]];
    if(!image){[self pauseAnimationPlayback];self.animationStatus.stringValue=@"A cached preview frame is missing. Render the preview again.";return;}
    self.animationView.image=image;NSInteger number=[frame[@"frame"] integerValue];self.animationView.frameNumber=number;[self.animationView setNeedsDisplay:YES];self.animationFields[1].integerValue=number;self.animationTimeline.doubleValue=number;self.animationPlaybackIndex=(self.animationPlaybackIndex+1)%self.animationPlaybackFrames.count;
}
- (void)resumeAnimationPlayback {
    if(self.calculating||!self.animationPlaybackFrames.count)return;self.animationView.imageScaling=NSImageScaleProportionallyDown;[self pauseAnimationPlayback];[self advanceAnimationPlayback];__weak AppDelegate *weakSelf=self;
    self.animationPlaybackTimer=[NSTimer timerWithTimeInterval:fmax(.004,self.animationPlaybackInterval) repeats:YES block:^(NSTimer *timer){(void)timer;[weakSelf advanceAnimationPlayback];}];[[NSRunLoop mainRunLoop] addTimer:self.animationPlaybackTimer forMode:NSRunLoopCommonModes];self.animationPause.title=@"Pause";self.animationPause.enabled=YES;
}
- (void)toggleAnimationPlayback:(id)sender {(void)sender;if(self.animationPlaybackTimer)[self pauseAnimationPlayback];else [self resumeAnimationPlayback];}

- (void)seekAnimationPlayback:(NSInteger)number {
    if(!self.animationPlaybackFrames.count)return;NSUInteger selected=0;NSInteger distance=NSIntegerMax;
    for(NSUInteger i=0;i<self.animationPlaybackFrames.count;i++){NSInteger next=labs([self.animationPlaybackFrames[i][@"frame"] integerValue]-number);if(next<distance){selected=i;distance=next;}}
    self.animationPlaybackIndex=selected;[self advanceAnimationPlayback];
}

- (void)addNavigatorToAnimation:(id)sender {
    (void)sender;if(self.calculating||!self.formulaKnown)return;
    if(![self readNavigatorFormulaValues])return;double move,look;if(![self navigatorValues:&move look:&look])return;
    if(self.previewBusy||self.navigatorMoves.count){self.navigatorAddPending=YES;self.navigatorAddAnimationButton.enabled=NO;if(!self.previewBusy)[self requestNavigatorPreview];self.navigatorStatus.stringValue=@"Waiting for Navigator movement before adding keyframe…";return;}
    self.navigatorAddPending=NO;self.navigatorAddAnimationButton.enabled=YES;
    [self ensureAnimationWindow];
    if(self.animationKeys.count>=1000){self.animationStatus.stringValue=@"At most 1000 keyframes are supported.";return;}
    int frames;if(!animationInteger(self.animationFields[0].stringValue,1,10000,&frames)){self.animationStatus.stringValue=@"Frames to next must be 1–10000.";return;}
    NSData *source=[self animationCompactSource:self.currentPath];NSString *path=source?[self animationRestoreSource:source]:nil;
    if(!path){self.animationStatus.stringValue=@"Could not snapshot the Navigator scene parameters.";return;}
    RenderOptions options=[self applyNavigatorFormulas:self.formulaSettings];options.camera_override=1;options.camera=self.navigatorCamera;options.navigation_count=0;options.cancel_token=NULL;options.preview_cache=options.reuse_surface=0;
    NSUInteger index=self.animationKeys.count;NSMutableDictionary *key=[@{@"name":[NSString stringWithFormat:@"Scene %lu",(unsigned long)index+1],@"settings":[NSData dataWithBytes:&options length:sizeof options],@"path":path,@"frames":@(frames)} mutableCopy];
    [self clearAnimationPlayback];[self.animationKeys addObject:key];[self refreshAnimationKeys:self.animationKeys.count];
    [self renderAnimationKeyPreviewsFrom:index through:index];self.navigatorStatus.stringValue=@"Navigator parameters added to animation. Main is unchanged.";
}
