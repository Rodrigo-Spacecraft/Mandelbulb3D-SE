/* Batch changes affect captured keyframes, not the main-window scene. */
- (void)showAnimationProcessing:(id)sender {
    (void)sender;if(!self.animationProcessingWindow){
        self.animationProcessingWindow=[[NSWindow alloc]initWithContentRect:NSMakeRect(0,0,640,590) styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable backing:NSBackingStoreBuffered defer:NO];self.animationProcessingWindow.title=@"Animation Processing";self.animationProcessingWindow.releasedWhenClosed=NO;self.animationProcessingWindow.delegate=self;
        CalculationPanel *panel=[[CalculationPanel alloc]initWithFrame:NSMakeRect(0,0,640,590)];NSMutableArray *checks=[NSMutableArray array],*fields=[NSMutableArray array],*buttons=[NSMutableArray array];
        NSTextField *hint=[NSTextField wrappingLabelWithString:@"Check the values to change, then choose which keyframes to update."];hint.frame=NSMakeRect(16,12,608,30);[panel addSubview:hint];
        NSArray *names=@[@"Frames to next",@"Frame count multiplier",@"DE stop",@"Raystep multiplier",@"Smooth normals",@"Max iterations",@"Min iterations",@"Main light and color settings",@"Main hard shadow settings",@"Main ambient shadow settings",@"Main depth of field settings",@"Main camera FOV / optic",@"Main normals on ZBuffer"];
        RenderOptions o=self.formulaSettings;double defaults[]={30,1,o.de_stop>0?o.de_stop:.5,o.ray_step>0?o.ray_step:.5,o.normal_smoothing,o.iterations>0?o.iterations:60,o.program.min_iterations};
        for(int i=0;i<13;i++){
            NSButton *check=[NSButton checkboxWithTitle:names[i] target:self action:@selector(animationProcessingCheck:)];check.frame=NSMakeRect(i<7?16:322,48+(i<7?i:i-7)*34,i<7?190:300,26);[panel addSubview:check];[checks addObject:check];
            if(i<7){NSTextField *field=[[NumericTextField alloc]initWithFrame:NSMakeRect(214,48+i*34,88,26)];numericIntegerField(field,i==0||i>=4);field.stringValue=[NSString stringWithFormat:@"%.17g",defaults[i]];field.accessibilityLabel=names[i];[panel addSubview:field];[fields addObject:field];}
        }
        NSArray *scopes=@[@"Put values to all keyframes",@"To selected and following",@"To selected and all before",@"Only selected keyframe"];
        for(int i=0;i<4;i++){NSButton *button=[NSButton buttonWithTitle:scopes[i] target:self action:@selector(applyAnimationProcessing:)];button.tag=i;button.frame=NSMakeRect(16+(i%2)*310,304+(i/2)*36,298,30);[panel addSubview:button];[buttons addObject:button];}
        NSButton *rerender=[NSButton buttonWithTitle:@"Rerender all keyframe preview images" target:self action:@selector(rerenderAnimationKeyPreviews:)];rerender.frame=NSMakeRect(16,392,390,30);[panel addSubview:rerender];[buttons addObject:rerender];
        NSButton *reverse=[NSButton buttonWithTitle:@"Reverse the order of all keyframes" target:self action:@selector(reverseAnimationKeys:)];reverse.frame=NSMakeRect(16,432,390,30);[panel addSubview:reverse];[buttons addObject:reverse];
        self.animationProcessingStop=[NSButton buttonWithTitle:@"Stop" target:self action:@selector(stopRender:)];self.animationProcessingStop.frame=NSMakeRect(486,392,138,30);[panel addSubview:self.animationProcessingStop];
        self.animationProcessingStatus=[NSTextField wrappingLabelWithString:@"Only checked settings are changed. Preview images can be regenerated after editing."];self.animationProcessingStatus.frame=NSMakeRect(16,486,608,80);[panel addSubview:self.animationProcessingStatus];
        self.animationProcessingChecks=checks;self.animationProcessingFields=fields;self.animationProcessingButtons=buttons;self.animationProcessingWindow.contentView=panel;[self.animationProcessingWindow center];
    }
    [self syncAnimationProcessing];[self positionWindowRightOfMain:self.animationProcessingWindow];[self.animationProcessingWindow makeKeyAndOrderFront:nil];
}
- (void)syncAnimationProcessing {
    for(NSButton *check in self.animationProcessingChecks)check.enabled=!self.calculating;
    for(NSUInteger i=0;i<self.animationProcessingFields.count;i++)self.animationProcessingFields[i].enabled=!self.calculating&&self.animationProcessingChecks[i].state==NSControlStateValueOn;
    for(NSButton *button in self.animationProcessingButtons)button.enabled=!self.calculating&&self.animationKeys.count>0;
    self.animationProcessingStop.enabled=self.calculating&&self.animationRegeneratingPreviews;
}
- (void)animationProcessingCheck:(id)sender {(void)sender;[self syncAnimationProcessing];}
- (void)applyAnimationProcessing:(NSButton *)sender {
    if(self.calculating||!self.animationKeys.count)return;
    NSInteger first=0,last=self.animationKeys.count-1,selected=self.animationTable.selectedRow;
    if(sender.tag&&(selected<0||selected>=(NSInteger)self.animationKeys.count)){self.animationProcessingStatus.stringValue=@"Select a keyframe first.";return;}
    if(sender.tag==1||sender.tag==3)first=selected;if(sender.tag==2||sender.tag==3)last=selected;
    double values[7]={0},low[]={1,.0001,.000001,.000001,0,1,0},high[]={10000,100,100,1,15,10000,10000};
    for(int i=0;i<7;i++)if(self.animationProcessingChecks[i].state==NSControlStateValueOn){NSScanner *scan=[NSScanner scannerWithString:numericInputString(self.animationProcessingFields[i])];if(![scan scanDouble:&values[i]]||!scan.isAtEnd||!isfinite(values[i])||values[i]<low[i]||values[i]>high[i]||((i==0||i>=4)&&floor(values[i])!=values[i])){self.animationProcessingStatus.stringValue=[NSString stringWithFormat:@"%@: enter %@%.9g–%.9g.",self.animationProcessingFields[i].accessibilityLabel,i==0||i>=4?@"an integer ":@"",low[i],high[i]];return;}}
    RenderOptions main=self.formulaSettings;
    if(self.animationProcessingChecks[7].state==NSControlStateValueOn){if(self.lightingWindow&&(![self readObjectLighting:&main.object]||![self readLights:&main]))return;if(![self readAmbientLighting:&main])return;}
    if((self.animationProcessingChecks[8].state||self.animationProcessingChecks[9].state)&&![self readShadowSettings:&main])return;
    if(self.animationProcessingChecks[10].state&&![self readDepthOfField:&main])return;
    NSMutableArray *updated=[self.animationKeys mutableCopy];
    for(NSInteger i=first;i<=last;i++){
        NSMutableDictionary *key=[self.animationKeys[i] mutableCopy];RenderOptions o=animationUnpack(key[@"settings"]);NSInteger frames=[key[@"frames"] integerValue];
        if(self.animationProcessingChecks[0].state)frames=(NSInteger)values[0];if(self.animationProcessingChecks[1].state)frames=lround(frames*values[1]);
        if(frames<1||frames>10000){self.animationProcessingStatus.stringValue=@"Resulting Frames to next must be 1–10000. No keyframes were changed.";return;}
        if(self.animationProcessingChecks[2].state)o.de_stop=values[2];if(self.animationProcessingChecks[3].state)o.ray_step=values[3];
        if(self.animationProcessingChecks[4].state){o.normals_override=1;o.normal_smoothing=(int)values[4];}
        if(self.animationProcessingChecks[5].state)o.iterations=(int)values[5];if(self.animationProcessingChecks[6].state){o.program_override=1;o.program.min_iterations=(int)values[6];}
        if(o.program.min_iterations>o.iterations){self.animationProcessingStatus.stringValue=@"Min iterations must not exceed Max iterations. No keyframes were changed.";return;}
        if(self.animationProcessingChecks[7].state){o.object_override=o.lights_override=o.ambient_override=1;o.object=main.object;o.ambient=main.ambient;memcpy(o.lights,main.lights,sizeof o.lights);}
        if(self.animationProcessingChecks[8].state){o.shadows_override=1;o.shadows.hard_enabled=main.shadows.hard_enabled;o.shadows.hard_auto=main.shadows.hard_auto;o.shadows.hard_mask=main.shadows.hard_mask;o.shadows.hard_length=main.shadows.hard_length;o.shadows.hard_radius=main.shadows.hard_radius;o.shadows.soft=main.shadows.soft;o.shadows.cosine=main.shadows.cosine;}
        if(self.animationProcessingChecks[9].state){o.shadows_override=1;o.shadows.ambient_enabled=main.shadows.ambient_enabled;o.shadows.ambient_auto=main.shadows.ambient_auto;o.shadows.ambient_method=main.shadows.ambient_method;o.shadows.ambient_rays=main.shadows.ambient_rays;o.shadows.ambient_steps=main.shadows.ambient_steps;o.shadows.ambient_length=main.shadows.ambient_length;o.shadows.ambient_strength=main.shadows.ambient_strength;}
        if(self.animationProcessingChecks[10].state){o.dof_override=1;o.dof=main.dof;o.dof.clip_radius*=o.width/fmax(1,main.width);}
        if(self.animationProcessingChecks[11].state){o.camera_override=1;o.camera.fov=main.camera.fov;o.camera.optic=main.camera.optic;}
        if(self.animationProcessingChecks[12].state){o.normals_override=1;o.normal_zbuffer=main.normal_zbuffer;}
        key[@"frames"]=@(frames);key[@"settings"]=[NSData dataWithBytes:&o length:sizeof o];updated[i]=key;
    }
    [self clearAnimationPlayback];self.animationKeys=updated;[self refreshAnimationKeys:selected];self.animationProcessingStatus.stringValue=[NSString stringWithFormat:@"Updated %ld keyframes. Rerender preview images to see the changes.",(long)(last-first+1)];
}
- (void)reverseAnimationKeys:(id)sender {
    (void)sender;if(self.calculating||!self.animationKeys.count)return;NSInteger selected=self.animationTable.selectedRow;
    [self clearAnimationPlayback];self.animationKeys=[[[self.animationKeys reverseObjectEnumerator] allObjects] mutableCopy];[self refreshAnimationKeys:selected>=0&&selected<(NSInteger)self.animationKeys.count?(NSInteger)self.animationKeys.count-1-selected:self.animationKeys.count];self.animationProcessingStatus.stringValue=@"Keyframe order reversed.";
}
- (void)rerenderAnimationKeyPreviews:(id)sender {
    (void)sender;if(self.calculating||!self.animationKeys.count)return;[self renderAnimationKeyPreviewsFrom:0 through:self.animationKeys.count-1];
}
- (void)renderAnimationKeyPreviewsFrom:(NSUInteger)first through:(NSUInteger)last {
    if(self.calculating||first>last||last>=self.animationKeys.count)return;[self clearAnimationPlayback];
    RenderCancelToken *token=render_cancel_create();if(!token){self.animationProcessingStatus.stringValue=@"Not enough memory to render previews.";return;}
    NSArray *keys=[self.animationKeys copy];NSInteger selected=self.animationTable.selectedRow;
    render_cancel(self.navigatorCancelToken);self.navigatorGeneration++;self.navigatorRefinementTicket++;self.previewPending=NO;self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;
    NSUInteger generation=++self.generation;self.mainCancelToken=token;self.animationRenderKind=0;self.animationStopRequested=NO;self.animationRunning=self.animationRegeneratingPreviews=YES;[self setCalculating:YES];self.animationProcessingStatus.stringValue=@"Rendering keyframe previews…";
    dispatch_async(self.renderQueue,^{
        __block NSUInteger completed=0;NSString *failure=nil;BOOL stopped=NO;
        for(NSUInteger i=first;i<=last;i++){@autoreleasepool{
            RenderOptions o=animationUnpack(keys[i][@"settings"]);int oldWidth=o.width;double factor=fmax(fmin(494.0/o.width,282.0/o.height),16.0/fmin(o.width,o.height));o.width=MAX(16,(int)lround(o.width*factor));o.height=MAX(16,(int)lround(o.height*factor));o.de_stop=fmax(.000001,o.de_stop*o.width/oldWidth);o.dof.clip_radius=fmax(.1,fmin(1000,o.dof.clip_radius*o.width/oldWidth));o.oversampling=o.viewing=1;o.preview_cache=o.reuse_surface=1;o.cancel_token=token;
            NSString *path=keys[i][@"path"];RenderResult result=render_scene_with_options(path.length?path.fileSystemRepresentation:NULL,o);
            if(result.cancelled){free(result.rgba);stopped=YES;break;}if(!result.rgba){failure=[NSString stringWithUTF8String:result.error];break;}
            NSImage *rendered=imageForRender(result,1);free(result.rgba);NSImage *image=rendered?animationThumbnail((NSBitmapImageRep*)rendered.representations.firstObject):nil;
            if(!image){failure=@"Could not create a keyframe preview.";break;}completed++;
            NSUInteger index=i,count=completed;interactiveUI(^{if(generation!=self.generation)return;NSMutableDictionary *key=[self.animationKeys[index] mutableCopy];key[@"image"]=image;if(result.statistics.elapsed>0)key[@"secondsPerPixel"]=@(result.statistics.elapsed/((double)o.width*o.height));self.animationKeys[index]=key;[self updateAnimationPreviewEstimate];[self.animationTable reloadDataForRowIndexes:[NSIndexSet indexSetWithIndex:index] columnIndexes:[NSIndexSet indexSetWithIndex:0]];if(self.animationTable.selectedRow==(NSInteger)index){self.animationView.imageScaling=NSImageScaleProportionallyUpOrDown;self.animationView.image=image;}self.animationProcessingStatus.stringValue=[NSString stringWithFormat:@"Updated %lu / %lu keyframe previews",(unsigned long)count,(unsigned long)(last-first+1)];});
        }}
        interactiveUI(^{if(self.mainCancelToken==token)self.mainCancelToken=NULL;render_cancel_destroy(token);if(generation!=self.generation)return;self.animationRunning=self.animationRegeneratingPreviews=NO;[self setCalculating:NO];[self refreshAnimationKeys:selected];self.animationProcessingStatus.stringValue=failure?failure:[NSString stringWithFormat:@"%@ · %lu / %lu preview images updated",stopped?@"Stopped":@"Complete",(unsigned long)completed,(unsigned long)(last-first+1)];NSString *message=failure?failure:[NSString stringWithFormat:@"%@ · %lu preview images updated",stopped?@"Stopped":@"Complete",(unsigned long)completed];self.animationStatus.stringValue=message;self.statusLabel.stringValue=message;});
    });
}
