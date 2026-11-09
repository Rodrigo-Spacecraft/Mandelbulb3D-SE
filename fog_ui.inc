/* Original dynamic fog / volumetric lighting controls. */
- (void)addDepthFogTab:(NSTabView *)tabs {
    NSTabViewItem *tab=[[NSTabViewItem alloc] initWithIdentifier:@"depthFog"];tab.label=@"Radiance";
    CalculationPanel *panel=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,552,700)];
    NSMutableArray *controls=[NSMutableArray array],*fields=[NSMutableArray array],*sliders=[NSMutableArray array],*wells=[NSMutableArray array],*colorLabels=[NSMutableArray array],*fieldLabels=[NSMutableArray array];
    NSTextField *label=[NSTextField labelWithString:@"Mode"];label.frame=NSMakeRect(16,22,150,24);[panel addSubview:label];
    self.fogMode=[[NSPopUpButton alloc] initWithFrame:NSMakeRect(180,18,356,30) pullsDown:NO];[self.fogMode addItemsWithTitles:@[@"None",@"Dynamic fog on iterations",@"Volumetric lighting"]];
    [self.fogMode addItemWithTitle:@"Emissive DIFS"];
    int modeTags[]={3,0,1,2};for(int i=0;i<4;i++)[self.fogMode itemAtIndex:i].tag=modeTags[i];
    self.fogMode.target=self;self.fogMode.action=@selector(fogEdited:);[panel addSubview:self.fogMode];[controls addObject:self.fogMode];
    label=[NSTextField labelWithString:@"Volumetric light source"];self.fogLightLabel=label;label.frame=NSMakeRect(16,68,170,24);[panel addSubview:label];
    self.fogLight=[[NSPopUpButton alloc] initWithFrame:NSMakeRect(180,64,150,30) pullsDown:NO];[self.fogLight addItemsWithTitles:@[@"Light 1",@"Light 2",@"Light 3",@"Light 4",@"Light 5",@"Light 6"]];self.fogLight.target=self;self.fogLight.action=@selector(fogEdited:);[panel addSubview:self.fogLight];[controls addObject:self.fogLight];
    NSArray *names=@[@"Intensity",@"Level",@"Offset",@"Fog iteration (0 = all)",@"Map size adjustment"];
    NSArray *hints=@[@"Dynamic fog or volumetric light intensity. 53 is neutral.",@"Offset for dynamic fog / volumetric lighting.",@"Depth-dependent offset for dynamic fog / volumetric lighting.",@"Dynamic fog on this iteration only. Zero includes all iterations.",@"Tune the size of the volumetric map in 20% steps. Zero is the original default."];
    double maximum[]={159,256,256,255,9};
    for(int i=0;i<5;i++){
        CGFloat y=118+i*48+(i>=3?136:0);label=[NSTextField labelWithString:names[i]];[fieldLabels addObject:label];label.frame=NSMakeRect(16,y+4,165,24);[panel addSubview:label];
        NSTextField *field=[[NumericTextField alloc] initWithFrame:NSMakeRect(i>=3?180:438,y,70,26)];field.tag=i;field.target=self;field.action=@selector(fogEdited:);field.toolTip=hints[i];field.accessibilityLabel=names[i];if(i>=3)numericIntegerField(field,YES);[fields addObject:field];[controls addObject:field];[panel addSubview:field];
        if(i<3){LiveSlider *slider=[LiveSlider sliderWithValue:i?128:53 minValue:0 maxValue:maximum[i] target:self action:@selector(fogSlider:)];slider.frame=NSMakeRect(180,y,240,26);slider.tag=i;slider.continuous=YES;slider.toolTip=hints[i];slider.accessibilityLabel=names[i];__weak AppDelegate *weakSelf=self;slider.started=^{[weakSelf beginLightingSlider];};slider.finished=^{[weakSelf endLightingSlider];};[sliders addObject:slider];[controls addObject:slider];[panel addSubview:slider];}
        else {NSStepper *step=[[NSStepper alloc] initWithFrame:NSMakeRect(254,y-1,19,28)];step.minValue=i==4?-2:0;step.maxValue=maximum[i];step.increment=1;step.tag=i;step.target=self;step.action=@selector(fogStepper:);step.toolTip=hints[i];[controls addObject:step];[panel addSubview:step];}
    }
    for(int i=0;i<2;i++){CGFloat y=306+i*44;label=[NSTextField labelWithString:i?@"Intense Fog Color":@"Fog Color"];[colorLabels addObject:label];label.frame=NSMakeRect(16,y+4,160,24);[panel addSubview:label];NSColorWell *well=[[AdjustmentColorWell alloc] initWithFrame:NSMakeRect(180,y,75,30)];well.target=self;well.action=@selector(fogEdited:);[panel addSubview:well];[wells addObject:well];[controls addObject:well];}
    self.fogBlend=[NSButton checkboxWithTitle:@"Blend dFog" target:self action:@selector(fogEdited:)];self.fogBlend.frame=NSMakeRect(16,514,245,26);self.fogBlend.toolTip=@"Blend dynamic fog instead of adding light; the background vanishes with increasing fog.";[panel addSubview:self.fogBlend];[controls addObject:self.fogBlend];
    self.fogOnlyAdd=[NSButton checkboxWithTitle:@"Only add light" target:self action:@selector(fogEdited:)];self.fogOnlyAdd.frame=NSMakeRect(280,514,250,26);self.fogOnlyAdd.toolTip=@"Prevent subtracting light when dynamic fog is not blended.";[panel addSubview:self.fogOnlyAdd];[controls addObject:self.fogOnlyAdd];
    NSButton *color=[NSButton buttonWithTitle:@"Use source light color" target:self action:@selector(fogUseLightColor:)];self.fogUseColorButton=color;color.frame=NSMakeRect(280,306,210,32);[panel addSubview:color];[controls addObject:color];
    NSButton *reset=[NSButton buttonWithTitle:@"Reset sliders to zero effect" target:self action:@selector(fogReset:)];reset.frame=NSMakeRect(180,254,230,32);[panel addSubview:reset];[controls addObject:reset];
    label=[NSTextField wrappingLabelWithString:@"Map size affects volumetric shadow detail and calculation time. Fog color, intensity and offset reuse the calculated fog. Navigator previews omit this effect for speed."];label.frame=NSMakeRect(16,554,520,48);label.font=[NSFont systemFontOfSize:12];label.textColor=NSColor.secondaryLabelColor;[panel addSubview:label];
    self.fogColorLabels=colorLabels;self.fogFieldLabels=fieldLabels;self.fogFields=fields;self.fogSliders=sliders;self.fogWells=wells;self.fogControls=controls;
    tab.view=panel;[tabs addTabViewItem:tab];[self syncFogMode];
}
- (void)syncFogMode {
    int mode=(int)self.fogMode.selectedItem.tag;BOOL volume=mode==1,emissive=mode==2,none=mode==3,dynamic=mode==0;self.fogLight.enabled=volume;
    self.fogLight.hidden=NO;self.fogLightLabel.hidden=NO;self.fogLightLabel.enabled=volume;self.fogLightLabel.textColor=volume?NSColor.labelColor:NSColor.disabledControlTextColor;self.fogUseColorButton.hidden=!volume;
    self.fogColorLabels[0].stringValue=emissive?@"Emissive Light Color":(volume?@"Vol Light Color":@"Fog Color");
    self.fogColorLabels[1].hidden=NO;self.fogWells[1].hidden=NO;self.fogWells[1].enabled=dynamic;self.fogColorLabels[1].enabled=dynamic;self.fogColorLabels[1].textColor=(dynamic)?NSColor.labelColor:NSColor.disabledControlTextColor;
    for(int i=0;i<3;i++){self.fogFields[i].enabled=(!emissive&&!none);self.fogSliders[i].enabled=(!emissive&&!none);}self.fogBlend.enabled=self.fogOnlyAdd.enabled=(!emissive&&!none);
    self.fogWells[0].enabled=!none;self.fogColorLabels[0].enabled=!none;self.fogColorLabels[0].textColor=none?NSColor.disabledControlTextColor:NSColor.labelColor;
    for(int i=0;i<2;i++)self.fogWells[i].accessibilityLabel=self.fogColorLabels[i].stringValue;
    self.fogFields[3].enabled=dynamic;self.fogFields[4].enabled=volume;
    for(int i=0;i<5;i++){BOOL relevant=self.fogFields[i].enabled;self.fogFieldLabels[i].enabled=relevant;self.fogFieldLabels[i].textColor=relevant?NSColor.labelColor:NSColor.disabledControlTextColor;}
    for(NSControl *c in self.fogControls)if(c.action==@selector(fogReset:))c.enabled=(!emissive&&!none);
    for(NSControl *c in self.fogControls)if([c isKindOfClass:NSStepper.class])c.enabled=c.tag==4?volume:(dynamic);
}
- (void)populateDepthFog {
    if(!self.fogFields||!self.formulaKnown)return;
    FogSettings f=self.formulaSettings.fog_override?self.formulaSettings.fog:fog_settings_default();
    [self.fogMode selectItemWithTag:f.mode];[self.fogLight selectItemAtIndex:f.light-1];double v[]={f.strength,f.offset,f.far_offset,f.iterations,f.map_size};
    for(int i=0;i<5;i++){self.fogFields[i].stringValue=[NSString stringWithFormat:@"%.17g",v[i]];if(i<3)self.fogSliders[i].doubleValue=v[i];}
    for(NSControl *c in self.fogControls)if([c isKindOfClass:NSStepper.class])c.doubleValue=v[c.tag];
    for(int i=0;i<2;i++)self.fogWells[i].color=[NSColor colorWithSRGBRed:f.colors[i][0] green:f.colors[i][1] blue:f.colors[i][2] alpha:1];
    self.fogBlend.state=f.blend;self.fogOnlyAdd.state=(f.only_add&FOG_ONLY_ADD)?NSControlStateValueOn:NSControlStateValueOff;[self syncFogMode];
}
- (BOOL)readDepthFog:(RenderOptions *)options {
    if(!self.fogFields)return YES;FogSettings f=fog_settings_default();double v[5],maximum[]={159,256,256,255,9};
    for(int i=0;i<5;i++){NSScanner *scan=[NSScanner scannerWithString:numericInputString(self.fogFields[i])];if(![scan scanDouble:&v[i]]||!scan.isAtEnd||!isfinite(v[i])||v[i]<(i==4?-2:0)||v[i]>maximum[i]||(i>=3&&v[i]!=floor(v[i]))){self.statusLabel.stringValue=@"Check Depth Fog values: intensity 0–159, offsets 0–256, iteration 0–255, map size −2–9.";return NO;}}
    f.mode=(int)self.fogMode.selectedItem.tag;f.light=(int)self.fogLight.indexOfSelectedItem+1;f.strength=v[0];f.offset=v[1];f.far_offset=v[2];f.iterations=(int)v[3];f.map_size=(int)v[4];f.blend=self.fogBlend.state==NSControlStateValueOn;f.only_add=(self.fogOnlyAdd.state==NSControlStateValueOn?FOG_ONLY_ADD:0);
    for(int i=0;i<2;i++){NSColor *c=[self.fogWells[i].color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];f.colors[i][0]=c.redComponent;f.colors[i][1]=c.greenComponent;f.colors[i][2]=c.blueComponent;}
    options->fog_override=1;options->fog=f;return YES;
}
- (void)fogSlider:(NSSlider *)sender {self.fogFields[sender.tag].stringValue=[NSString stringWithFormat:@"%.17g",sender.doubleValue];[self requestLightingPreview];}
- (void)fogStepper:(NSStepper *)sender {self.fogFields[sender.tag].integerValue=sender.integerValue;[self fogEdited:sender];}
- (void)fogEdited:(id)sender {
    (void)sender;[self syncFogMode];for(int i=0;i<3;i++)self.fogSliders[i].doubleValue=self.fogFields[i].doubleValue;
    for(NSControl *c in self.fogControls)if([c isKindOfClass:NSStepper.class])c.doubleValue=self.fogFields[c.tag].doubleValue;
    [self finishLightingSlider];
}
- (void)fogUseLightColor:(id)sender {
    (void)sender;int n=(int)self.fogLight.indexOfSelectedItem;RenderOptions settings=self.formulaSettings;if(![self readLights:&settings])return;LightSettings light=settings.lights[n];
    for(NSColorWell *well in self.fogWells)well.color=[NSColor colorWithSRGBRed:light.color[0] green:light.color[1] blue:light.color[2] alpha:1];[self fogEdited:nil];
}
- (void)fogReset:(id)sender {(void)sender;self.fogFields[0].doubleValue=53;self.fogFields[1].doubleValue=128;self.fogFields[2].doubleValue=128;[self fogEdited:nil];}
