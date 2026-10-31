/* Native MutaGen workflow; original design and mutations by Andreas Maschke. */
- (void)showMutagen:(id)sender {
    (void)sender;if(self.calculating)return;[self.window makeFirstResponder:nil];
    if(!self.mutagenWindow){
        self.mutagenHistory=[NSMutableArray array];self.mutagenGenerationIndex=-1;
        self.mutagenWindow=[[NSWindow alloc]initWithContentRect:NSMakeRect(0,0,1060,640) styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable|NSWindowStyleMaskMiniaturizable|NSWindowStyleMaskResizable backing:NSBackingStoreBuffered defer:NO];self.mutagenWindow.title=@"Mutagen";self.mutagenWindow.releasedWhenClosed=NO;self.mutagenWindow.delegate=self;self.mutagenWindow.minSize=NSMakeSize(900,590);
        CalculationPanel *content=[[CalculationPanel alloc]initWithFrame:NSMakeRect(0,0,1060,640)];
        self.mutagenTree=[[MutagenTree alloc]initWithFrame:NSMakeRect(238,8,814,624)];self.mutagenTree.autoresizingMask=NSViewWidthSizable|NSViewHeightSizable;[content addSubview:self.mutagenTree];
        __weak AppDelegate *owner=self;NSMutableArray *tiles=[NSMutableArray array];
        for(int i=0;i<15;i++){MutagenTile *tile=[[MutagenTile alloc]initWithFrame:mutagenTileFrame(self.mutagenTree.bounds.size,i)];tile.toolTip=@"Double-click to breed from this preview. Right-click to send to Main or copy parameters.";tile.accessibilityLabel=[NSString stringWithFormat:@"Mutation preview %d",i+1];tile.choose=^(BOOL breed){[owner selectMutagenTile:i breed:breed];};tile.sendToMain=^{[owner sendMutagenTile:i toClipboard:NO];};tile.copyParameters=^{[owner sendMutagenTile:i toClipboard:YES];};[self.mutagenTree addSubview:tile];[tiles addObject:tile];}self.mutagenTiles=tiles;
        NSArray *sectionNames=@[@"Generations",@"Mutate",@"Options"];CGFloat sectionY[]={12,132,238};for(int i=0;i<3;i++){NSTextField *label=[NSTextField labelWithString:sectionNames[i]];label.font=[NSFont boldSystemFontOfSize:13];label.frame=NSMakeRect(14,sectionY[i],210,22);[content addSubview:label];}
        self.mutagenGenerationLabel=[NSTextField labelWithString:@"Generation 0 of 0"];self.mutagenGenerationLabel.frame=NSMakeRect(16,40,166,22);[content addSubview:self.mutagenGenerationLabel];
        self.mutagenGenerationStepper=[[NSStepper alloc]initWithFrame:NSMakeRect(194,35,19,28)];self.mutagenGenerationStepper.target=self;self.mutagenGenerationStepper.action=@selector(mutagenGenerationChanged:);self.mutagenGenerationStepper.increment=1;[content addSubview:self.mutagenGenerationStepper];
        self.mutagenClearButton=[NSButton buttonWithTitle:@"Clear all previous" target:self action:@selector(clearMutagenGenerations:)];self.mutagenClearButton.frame=NSMakeRect(14,70,210,28);[content addSubview:self.mutagenClearButton];
        self.mutagenResetButton=[NSButton buttonWithTitle:@"Reset from Main" target:self action:@selector(resetMutagenFromMain:)];self.mutagenResetButton.frame=NSMakeRect(14,100,210,26);[content addSubview:self.mutagenResetButton];
        self.mutagenMutateButton=[NSButton buttonWithTitle:@"Mutate!" target:self action:@selector(mutateGeneration:)];self.mutagenMutateButton.frame=NSMakeRect(14,160,210,38);[content addSubview:self.mutagenMutateButton];
        self.mutagenProgress=[[NSProgressIndicator alloc]initWithFrame:NSMakeRect(16,208,206,14)];self.mutagenProgress.indeterminate=NO;self.mutagenProgress.maxValue=15;[content addSubview:self.mutagenProgress];
        NSArray *headings=@[@"Mutation type",@"Probability",@"Strength"];CGFloat hx[]={14,108,174};for(int i=0;i<3;i++){NSTextField *label=[NSTextField labelWithString:headings[i]];label.font=[NSFont systemFontOfSize:10];label.frame=NSMakeRect(hx[i],262,i?58:94,18);[content addSubview:label];}
        NSArray *names=@[@"Exchange, add\nand remove\nformulas",@"Change formula\nparameters",@"Change\nJulia mode",@"Change iteration\ncounts"];MutagenConfig defaults=mutagenDefaultConfig();NSMutableArray *probability=[NSMutableArray array],*strength=[NSMutableArray array];
        for(int i=0;i<4;i++){CGFloat y=286+i*54;NSTextField *label=[NSTextField wrappingLabelWithString:names[i]];label.font=[NSFont systemFontOfSize:11];label.frame=NSMakeRect(14,y,92,46);[content addSubview:label];
            NSSlider *slider=[NSSlider sliderWithValue:defaults.probability[i] minValue:0 maxValue:1 target:nil action:nil];slider.vertical=YES;slider.frame=NSMakeRect(121,y,20,46);slider.toolTip=[NSString stringWithFormat:@"%@ probability (0–100%%)",names[i]];[content addSubview:slider];[probability addObject:slider];
            if(i){NSSlider *amount=[NSSlider sliderWithValue:defaults.strength[i-1] minValue:0 maxValue:2 target:nil action:nil];amount.vertical=YES;amount.frame=NSMakeRect(190,y,20,46);amount.toolTip=[NSString stringWithFormat:@"%@ strength (0–2)",names[i]];[content addSubview:amount];[strength addObject:amount];}
        }self.mutagenProbabilities=probability;self.mutagenStrengths=strength;
        self.mutagenDisableButton=[NSButton buttonWithTitle:@"Disable all" target:self action:@selector(disableMutagenOptions:)];self.mutagenDisableButton.frame=NSMakeRect(14,502,210,28);[content addSubview:self.mutagenDisableButton];
        self.mutagenStatus=[NSTextField wrappingLabelWithString:@"Double-click a preview to breed a new generation."];self.mutagenStatus.font=[NSFont systemFontOfSize:11];self.mutagenStatus.maximumNumberOfLines=1;self.mutagenStatus.lineBreakMode=NSLineBreakByTruncatingTail;self.mutagenStatus.toolTip=@"Double-click a preview to breed a new generation. Right-click to send to Main or copy parameters.";self.mutagenStatus.frame=NSMakeRect(14,536,210,18);[content addSubview:self.mutagenStatus];self.mutagenWindow.contentView=content;
    }
    [self positionWindowRightOfMain:self.mutagenWindow];[self.mutagenWindow makeKeyAndOrderFront:nil];if(!self.mutagenBusy)[self resetMutagenFromMain:nil];
}
- (void)syncMutagenControls {
    BOOL idle=!self.mutagenBusy&&!self.calculating;self.mutagenMutateButton.title=self.mutagenBusy?@"Cancel":@"Mutate!";self.mutagenMutateButton.enabled=!self.calculating;
    self.mutagenGenerationStepper.minValue=1;self.mutagenGenerationStepper.maxValue=MAX(1,self.mutagenHistory.count);self.mutagenGenerationStepper.integerValue=self.mutagenGenerationIndex+1;self.mutagenGenerationStepper.enabled=idle&&self.mutagenHistory.count>1;
    self.mutagenGenerationLabel.stringValue=[NSString stringWithFormat:@"Generation %ld of %lu",(long)self.mutagenGenerationIndex+1,(unsigned long)self.mutagenHistory.count];self.mutagenClearButton.enabled=idle&&self.mutagenGenerationIndex>0;self.mutagenResetButton.enabled=idle;self.mutagenDisableButton.enabled=idle;
    for(NSSlider *slider in self.mutagenProbabilities)slider.enabled=idle;for(NSSlider *slider in self.mutagenStrengths)slider.enabled=idle;
}
- (void)displayMutagenGeneration {
    if(self.mutagenGenerationIndex<0||self.mutagenGenerationIndex>=(NSInteger)self.mutagenHistory.count)return;MutagenGeneration *generation=self.mutagenHistory[self.mutagenGenerationIndex];
    for(int i=0;i<15;i++){MutagenTile *tile=self.mutagenTiles[i];tile.image=[generation.images[i] isKindOfClass:NSImage.class]?generation.images[i]:nil;tile.selected=i==self.mutagenSelected;tile.caption=nil;if([generation.options[i] isKindOfClass:NSData.class]){RenderOptions options=mutagenUnpack(generation.options[i]);NSMutableArray *names=[NSMutableArray array];for(int slot=0;slot<6;slot++)if(options.program.slots[slot].count)[names addObject:[NSString stringWithUTF8String:formula_name(options.program.slots[slot].kind)]];tile.caption=[names componentsJoinedByString:@", "];tile.toolTip=[NSString stringWithFormat:@"%@\nDouble-click to breed; right-click for Main or clipboard.",tile.caption];}tile.needsDisplay=YES;}[self syncMutagenControls];
}
- (void)selectMutagenTile:(NSInteger)index breed:(BOOL)breed {
    if(self.mutagenBusy||self.calculating)return;MutagenGeneration *g=self.mutagenHistory[self.mutagenGenerationIndex];if(![g.options[index] isKindOfClass:NSData.class])return;self.mutagenSelected=index;[self displayMutagenGeneration];if(breed)[self mutateGeneration:nil];
}
- (void)resetMutagenFromMain:(id)sender {
    (void)sender;if(self.mutagenBusy||self.calculating)return;RenderOptions options;if(![self readMainSettings:&options sender:nil])return;[self startMutagenGeneration:options source:self.currentPath mutations:NO];
}
- (void)mutateGeneration:(id)sender {
    if(self.mutagenBusy){[self stopMutagen];return;}if(self.calculating||self.mutagenGenerationIndex<0)return;if(sender==self.mutagenMutateButton)self.mutagenSelected=0;MutagenGeneration *g=self.mutagenHistory[self.mutagenGenerationIndex];if(![g.options[self.mutagenSelected] isKindOfClass:NSData.class])return;RenderOptions root=mutagenUnpack(g.options[self.mutagenSelected]);[self startMutagenGeneration:root source:g.source mutations:YES];
}
- (void)startMutagenGeneration:(RenderOptions)root source:(NSString *)source mutations:(BOOL)mutations {
    MutagenGeneration *g=[MutagenGeneration new];g.source=source;g.options[0]=mutagenPack(root);[self.mutagenHistory addObject:g];self.mutagenGenerationIndex=self.mutagenHistory.count-1;self.mutagenSelected=0;self.mutagenCell=0;self.mutagenCellCount=mutations?15:1;self.mutagenBusy=YES;self.mutagenRun++;MutagenConfig config=mutagenDefaultConfig();for(int i=0;i<4;i++)config.probability[i]=self.mutagenProbabilities[i].doubleValue;for(int i=0;i<3;i++)config.strength[i]=self.mutagenStrengths[i].doubleValue;self.mutagenConfig=config;self.mutagenProgress.doubleValue=0;[self displayMutagenGeneration];[self renderNextMutagenCell];
}
- (void)stopMutagen {
    render_cancel(self.mutagenCancelToken);self.mutagenRun++;self.mutagenBusy=NO;self.mutagenStatus.stringValue=@"Cancelled. Completed previews are retained.";[self syncMutagenControls];
}
- (void)renderNextMutagenCell {
    if(!self.mutagenBusy)return;if(self.mutagenCell>=self.mutagenCellCount){self.mutagenBusy=NO;self.mutagenStatus.stringValue=@"Double-click a preview to breed. Right-click for Main or clipboard.";[self syncMutagenControls];return;}
    NSInteger index=self.mutagenCell;NSUInteger run=self.mutagenRun;MutagenGeneration *generation=self.mutagenHistory[self.mutagenGenerationIndex];RenderOptions parent=mutagenUnpack(generation.options[index?(index-1)/2:0]);NSData *parentProbe=index&&[generation.probes[(index-1)/2] isKindOfClass:NSData.class]?generation.probes[(index-1)/2]:nil;NSString *source=generation.source;MutagenConfig config=self.mutagenConfig;RenderCancelToken *token=render_cancel_create();self.mutagenCancelToken=token;uint64_t seed=((uint64_t)arc4random()<<32)|arc4random();if(!seed)seed=1;
    self.mutagenStatus.stringValue=[NSString stringWithFormat:@"Rendering preview %ld of %ld…",(long)index+1,(long)self.mutagenCellCount];
    dispatch_async(self.renderQueue,^{
        uint64_t random=seed;RenderOptions best=parent;NSData *bestProbe=nil;double bestScore=-1;BOOL cancelled=NO;NSString *failure=nil;
        for(int attempt=0;attempt<(index?9:1);attempt++){
            RenderOptions candidate=index?mutagenMutate(parent,config,&random):parent;RenderResult probe=render_scene_with_options(source.fileSystemRepresentation,mutagenPreview(candidate,40,32,token));if(probe.cancelled){cancelled=YES;free(probe.rgba);break;}if(!probe.rgba){failure=[NSString stringWithUTF8String:probe.error];continue;}
            double difference=0,coverage=mutagenCoverage(probe.rgba,parentProbe.bytes,probe.width,probe.height,&difference);double score=coverage+(difference>=.16?1:0);if(score>bestScore){bestScore=score;best=candidate;bestProbe=[NSData dataWithBytes:probe.rgba length:probe.stride*probe.height];}free(probe.rgba);if(!index||(coverage>=.32&&difference>=.16))break;
        }
        NSImage *image=nil;if(!cancelled&&bestProbe){RenderResult result=render_scene_with_options(source.fileSystemRepresentation,mutagenPreview(best,160,120,token));cancelled=result.cancelled;if(result.rgba)image=imageForRender(result,1);else if(!cancelled)failure=[NSString stringWithUTF8String:result.error];free(result.rgba);}
        interactiveUI(^{if(self.mutagenCancelToken==token)self.mutagenCancelToken=NULL;render_cancel_destroy(token);if(run!=self.mutagenRun)return;
            if(cancelled){[self stopMutagen];return;}if(image){generation.options[index]=mutagenPack(best);generation.images[index]=image;generation.probes[index]=bestProbe;self.mutagenStatus.stringValue=@"Preview complete.";}else self.mutagenStatus.stringValue=[NSString stringWithFormat:@"Preview %ld: %@",(long)index+1,failure?:@"No valid mutation."];
            // Keep a valid parent record even if its preview cannot be rendered.
            if(![generation.options[index] isKindOfClass:NSData.class])generation.options[index]=mutagenPack(parent);
            self.mutagenCell++;self.mutagenProgress.maxValue=self.mutagenCellCount;self.mutagenProgress.doubleValue=self.mutagenCell;[self displayMutagenGeneration];[self renderNextMutagenCell];
        });
    });
}
- (void)disableMutagenOptions:(id)sender{(void)sender;for(NSSlider *slider in self.mutagenProbabilities)slider.doubleValue=0;}
- (void)mutagenGenerationChanged:(NSStepper *)sender{if(self.mutagenBusy)return;self.mutagenGenerationIndex=MAX(0,MIN((NSInteger)self.mutagenHistory.count-1,sender.integerValue-1));self.mutagenSelected=0;[self displayMutagenGeneration];}
- (void)clearMutagenGenerations:(id)sender{(void)sender;if(self.mutagenBusy||self.mutagenGenerationIndex<=0)return;[self.mutagenHistory removeObjectsInRange:NSMakeRange(0,self.mutagenGenerationIndex)];self.mutagenGenerationIndex=0;[self displayMutagenGeneration];}
- (void)sendMutagenTile:(NSInteger)index toClipboard:(BOOL)clipboard {
    if(self.calculating||self.mutagenBusy||self.mutagenGenerationIndex<0)return;MutagenGeneration *g=self.mutagenHistory[self.mutagenGenerationIndex];if(![g.options[index] isKindOfClass:NSData.class])return;RenderOptions options=mutagenUnpack(g.options[index]);NSString *source=g.source;
    if(!clipboard){[self loadParameterSettings:options path:source source:@"Mutagen"];return;}
    dispatch_async(self.renderQueue,^{char error[512],*text=NULL;BOOL ok=export_clipboard_scene(source.fileSystemRepresentation,options,&text,error);NSString *value=ok?[NSString stringWithUTF8String:text]:nil;free(text);NSString *failure=ok?nil:[NSString stringWithUTF8String:error];interactiveUI(^{if(value){[NSPasteboard.generalPasteboard clearContents];[NSPasteboard.generalPasteboard setString:value forType:NSPasteboardTypeString];self.mutagenStatus.stringValue=@"Parameters copied to clipboard.";}else self.mutagenStatus.stringValue=failure?:@"Could not copy parameters.";});});
}
