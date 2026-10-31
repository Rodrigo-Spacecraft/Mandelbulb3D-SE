/* Offscreen regression: a sidebar redraw must not paint over its siblings. */
#define main app_entry_not_used
#import "App.m"
#undef main
#include <assert.h>
@interface LightingCommitProbe : AppDelegate
@property(nonatomic) int commits;
@property(nonatomic) double editedAngle,committedAngle;
@end
@implementation LightingCommitProbe
- (void)calculate:(id)sender {(void)sender;self.commits++;self.committedAngle=self.editedAngle;}
- (void)refreshPaletteViews {}
- (void)populateLights {}
@end
@interface ManualRenderProbe : AppDelegate
@property(nonatomic) int renderStarts;
@property(nonatomic) RenderOptions submittedOptions;
@property(nonatomic) BOOL submittedLightingRepaint;
@end
@implementation ManualRenderProbe
- (void)beginRenderPath:(NSString *)path options:(RenderOptions)options {(void)path;self.renderStarts++;self.submittedOptions=options;self.submittedLightingRepaint=self.lightingRepaintRequested;}
@end
@interface PostShadowSliderProbe : AppDelegate
@property(nonatomic) int previews,commits;
@property(nonatomic) RenderOptions captured;
@end
@implementation PostShadowSliderProbe
- (void)requestLightingPreview {self.previews++;RenderOptions options=self.formulaSettings;assert([self readShadowSettings:&options]);self.captured=options;}
- (void)calculate:(id)sender {(void)sender;self.commits++;RenderOptions options=self.formulaSettings;assert([self readShadowSettings:&options]);self.captured=options;}
@end
@interface PositionalLightProbe : AppDelegate
@property(nonatomic) int lightUpdates;
@end
@implementation PositionalLightProbe
- (void)requestLightingPreview {self.lightUpdates++;}
- (void)finishLightingSlider {}
@end
@interface FormulaDragProbe : AppDelegate
@property(nonatomic) int formulaPreviews;
@end
@implementation FormulaDragProbe
- (void)requestNavigatorPreview {self.formulaPreviews++;}
@end
@interface ColorPreviewProbe : AppDelegate
@property(nonatomic) int colorPreviews,colorCommits;
@property(nonatomic) RenderOptions colorOptions;
@end
@implementation ColorPreviewProbe
- (void)captureColors {RenderOptions o=self.formulaSettings;assert([self readObjectLighting:&o.object]&&[self readLights:&o]&&[self readAmbientLighting:&o]);self.colorOptions=o;}
- (void)requestLightingPreview {self.colorPreviews++;[self captureColors];}
- (void)calculate:(id)sender {(void)sender;self.colorCommits++;[self captureColors];}
@end
int main(void) {
    @autoreleasepool {
        NumericInputFormatter *decimal=[NumericInputFormatter new],*integer=[NumericInputFormatter new];integer.integerOnly=YES;
        for(NSString *text in @[@"",@"-",@".",@"-.",@"0",@"-.125",@"123.",@"-123.45"])assert([decimal isPartialStringValid:text newEditingString:NULL errorDescription:NULL]);
        for(NSString *text in @[@"a",@"1e3",@"NaN",@"inf",@"+1",@"1,2",@" 12",@"12 ",@"1..2",@"1-2",@"１２",@"1\n2"])assert(![decimal isPartialStringValid:text newEditingString:NULL errorDescription:NULL]);
        for(NSString *text in @[@"",@"-",@"0",@"-4",@"12345"])assert([integer isPartialStringValid:text newEditingString:NULL errorDescription:NULL]);
        for(NSString *text in @[@".",@"1.",@"1.5",@"1e2",@"12x"])assert(![integer isPartialStringValid:text newEditingString:NULL errorDescription:NULL]);
        id parsed=nil;assert([decimal getObjectValue:&parsed forString:@"-.25" errorDescription:NULL]&&[parsed isEqual:@"-.25"]);assert(![decimal getObjectValue:&parsed forString:@"-." errorDescription:NULL]);assert(![integer getObjectValue:&parsed forString:@"1.5" errorDescription:NULL]);
        integer.allowLast=YES;assert([integer isPartialStringValid:@"las" newEditingString:NULL errorDescription:NULL]&&[integer getObjectValue:&parsed forString:@"LAST" errorDescription:NULL]);assert(![integer isPartialStringValid:@"latest" newEditingString:NULL errorDescription:NULL]);
        for(NSString *text in @[@"1e-6",@"-1.2345678901234567e20",@"1e-300",@"3.141592653589793e-12"]){NSString *expanded=numericDisplayString(text);assert([expanded rangeOfString:@"e" options:NSCaseInsensitiveSearch].location==NSNotFound&&expanded.doubleValue==text.doubleValue);}
        for(NSString *key in @[@"u",@"o",@"w",@"j"]) {
            NSInteger expected=[@{@"u":@10,@"o":@11,@"w":@0,@"j":@6}[key] integerValue];
            for(int fine=0;fine<2;fine++) {
                NSEvent *event=[NSEvent keyEventWithType:NSEventTypeKeyDown location:NSZeroPoint modifierFlags:fine?NSEventModifierFlagShift:0 timestamp:0 windowNumber:0 context:nil characters:key charactersIgnoringModifiers:key isARepeat:NO keyCode:0];
                assert(navigatorKeyOperation(event).integerValue==expected+(fine?100:0));
            }
        }
        puts("U/O roll and Shift fine navigation shortcuts passed.");
        LiveSlider *fineSlider=[[LiveSlider alloc] initWithFrame:NSMakeRect(0,0,116,24)];fineSlider.minValue=0;fineSlider.maxValue=100;fineSlider.doubleValue=50;
        double mouseX[]={58,68,78,78};NSEventModifierFlags modifiers[]={NSEventModifierFlagShift,NSEventModifierFlagShift,0,NSEventModifierFlagShift};double expectedValue[]={50,51,61,61};
        for(int i=0;i<4;i++) {
            NSEvent *event=[NSEvent mouseEventWithType:i?NSEventTypeLeftMouseDragged:NSEventTypeLeftMouseDown location:NSMakePoint(mouseX[i],12) modifierFlags:modifiers[i] timestamp:0 windowNumber:0 context:nil eventNumber:0 clickCount:1 pressure:1];
            [fineSlider updateFromEvent:event];assert(fabs(fineSlider.doubleValue-expectedValue[i])<1e-9);
        }
        AppDelegate *mapUI=[AppDelegate new];mapUI.objectMapMenu=[[NSPopUpButton alloc] initWithFrame:NSZeroRect pullsDown:NO];
        for(NSString *file in @[@"",@"1.png",@"10.jpg"]){[mapUI.objectMapMenu addItemWithTitle:file.length?file:@"None"];mapUI.objectMapMenu.lastItem.representedObject=file;}
        mapUI.objectMapNumber=[NSTextField new];mapUI.objectMapNumber.stringValue=@"10";
        assert([mapUI selectObjectMapNumber]&&[mapUI.objectMapMenu.selectedItem.representedObject isEqual:@"10.jpg"]);
        mapUI.objectMapNumber.stringValue=@"bad";assert(![mapUI selectObjectMapNumber]);
        LightingCommitProbe *mapFormat=[LightingCommitProbe new];mapFormat.formulaKnown=YES;mapFormat.lightingWindow=[NSWindow new];mapFormat.objectMapMenu=mapUI.objectMapMenu;mapFormat.objectMapNumber=[NSTextField new];
        RenderOptions mapSettings={0};strcpy(mapSettings.object.map.file,"1000.jpg");mapSettings.object.map.number=1000;mapSettings.object.map.scale=1;mapFormat.formulaSettings=mapSettings;
        [mapFormat populateObjectLighting];assert([mapFormat.objectMapNumber.stringValue isEqual:@"1000"]);assert([mapFormat selectObjectMapNumber]);
        AppDelegate *julia=[AppDelegate new];julia.navigatorJuliaMode=[NSButton new];julia.navigatorJuliaMode.state=NSControlStateValueOn;
        julia.navigatorJuliaFields=@[[NSTextField new],[NSTextField new],[NSTextField new]];
        julia.navigatorJuliaFields[0].stringValue=@"0.2";julia.navigatorJuliaFields[1].stringValue=@"-0.3";julia.navigatorJuliaFields[2].stringValue=@"0.4";
        assert([julia readNavigatorJuliaValues]);RenderOptions transferred=[julia applyNavigatorFormulas:(RenderOptions){0}];assert(transferred.julia_override&&transferred.julia&&transferred.julia_c[0]==.2&&transferred.julia_c[1]==-.3&&transferred.julia_c[2]==.4);
        julia.navigatorJuliaSpherical=YES;julia.navigatorJuliaFields[0].stringValue=@"2";julia.navigatorJuliaFields[1].stringValue=@"90";julia.navigatorJuliaFields[2].stringValue=@"0";
        assert([julia readNavigatorJuliaValues]);assert(fabs(julia.navigatorFormulaSettings.julia_c[0]-2)<1e-12&&fabs(julia.navigatorFormulaSettings.julia_c[1])<1e-12&&fabs(julia.navigatorFormulaSettings.julia_c[2])<1e-12);
        puts("Map numbers remain ungrouped after population; Julia XYZ/spherical edits transfer to render options.");
        PositionalLightProbe *fogUI=[PositionalLightProbe new];fogUI.formulaKnown=YES;RenderOptions fogOptions={.fog_override=1,.fog=fog_settings_default()};fogOptions.fog.mode=1;fogOptions.fog.light=6;fogOptions.fog.map_size=3;fogUI.formulaSettings=fogOptions;
        NSTabView *fogTabs=[[NSTabView alloc]initWithFrame:NSMakeRect(0,0,552,700)];[fogUI addDepthFogTab:fogTabs];[fogUI populateDepthFog];
        assert([fogTabs.tabViewItems[0].label isEqual:@"DFog/VolLt"]&&fogUI.fogFields.count==5&&fogUI.fogSliders.count==3&&fogUI.fogWells.count==2);
        assert(fogUI.fogLight.indexOfSelectedItem==5&&fogUI.fogFields[4].integerValue==3&&fogUI.fogFields[4].enabled&&!fogUI.fogFields[3].enabled);
        [fogUI.fogMode selectItemAtIndex:0];[fogUI fogEdited:nil];assert(!fogUI.fogLight.enabled&&!fogUI.fogFields[4].enabled&&fogUI.fogFields[3].enabled);
        fogUI.fogSliders[0].doubleValue=109;[fogUI fogSlider:fogUI.fogSliders[0]];assert(fogUI.fogFields[0].doubleValue==109&&fogUI.lightUpdates==1);assert([fogUI readDepthFog:&fogOptions]&&fogOptions.fog.mode==0&&fogOptions.fog.light==6&&fogOptions.fog.strength==109);
        fogUI.fogFields[4].stringValue=@"10";assert(![fogUI readDepthFog:&fogOptions]);fogUI.fogFields[4].stringValue=@"3";[fogUI fogReset:nil];assert([fogUI readDepthFog:&fogOptions]&&fogOptions.fog.strength==53&&fogOptions.fog.offset==128&&fogOptions.fog.far_offset==128&&fogOptions.fog.light==6);
        assert(animationOptionsSize(offsetof(RenderOptions,fog_override)));RenderOptions legacyFog=animationUnpack([NSData dataWithBytes:&fogOptions length:offsetof(RenderOptions,fog_override)]);assert(!legacyFog.fog_override);
        puts("Depth Fog UI has six lights, mode-dependent controls, live sliders, validation, reset and backward-compatible animation snapshots.");
        puts("Shift sliders use one-tenth movement without modifier jumps; typed map numbers select matching files.");
        AppDelegate *ambientUI=[AppDelegate new];NSMutableArray *ambientFields=[NSMutableArray array],*ambientWells=[NSMutableArray array];
        for(NSString *value in @[@"90",@"27",@"53",@"53",@"255"]){NSTextField *field=[NSTextField new];field.stringValue=value;[ambientFields addObject:field];}
        for(int i=0;i<4;i++){NSColorWell *well=[NSColorWell new];well.color=[NSColor colorWithSRGBRed:.2 green:.3 blue:.4 alpha:1];[ambientWells addObject:well];}
        ambientUI.ambientFields=ambientFields;ambientUI.ambientWells=ambientWells;ambientUI.ambientAOBaseline=@"53";ambientUI.ambientGradient=[[NSPopUpButton alloc] initWithFrame:NSZeroRect pullsDown:NO];[ambientUI.ambientGradient addItemWithTitle:@"Linear"];
        RenderOptions ambientOptions={0};ambientOptions.shadows.ambient_strength=3;
        assert([ambientUI readAmbientLighting:&ambientOptions]&&ambientOptions.shadows.ambient_strength==3&&ambientOptions.ambient_override);
        ambientUI.ambientFields[2].stringValue=@"106";assert([ambientUI readAmbientLighting:&ambientOptions]&&ambientOptions.shadows.ambient_strength==2&&ambientOptions.shadows_override);
        puts("Ambient edits preserve unchanged Post-process AO strength and transfer explicit AO edits.");
        AppDelegate *randNavigator=[AppDelegate new];NSTabView *randTabs=[[NSTabView alloc] initWithFrame:NSMakeRect(0,0,696,230)];[randNavigator addNavigatorFormulaTab:randTabs];RenderOptions randSettings={0};randSettings.program=defaultFormulaProgram();randSettings.program.slots[0]=formula_slot_default(101);randSettings.program.slots[0].count=1;randNavigator.navigatorFormulaSettings=randSettings;[randNavigator populateNavigatorFormulaValues];assert(randNavigator.navigatorFormulaFields.count==16);assert([randNavigator readNavigatorFormulaValues]);assert(randNavigator.navigatorFormulaSettings.program.slots[0].parameters[8]==127);
        NSView *fixedHeader=randNavigator.navigatorFormulaMenu.superview;NSView *parameterRows=randNavigator.navigatorFormulaSliders[0].superview;NSScrollView *parameterScroll=parameterRows.enclosingScrollView;assert(parameterScroll&&fixedHeader!=parameterRows&&parameterScroll.superview==fixedHeader&&randNavigator.navigatorIterationField.superview==fixedHeader&&randNavigator.navigatorFormulaRange.superview==fixedHeader);NSRect fixedMenu=randNavigator.navigatorFormulaMenu.frame;CGFloat fixedHeight=fixedHeader.frame.size.height;[parameterScroll.contentView scrollToPoint:NSMakePoint(0,120)];[parameterScroll reflectScrolledClipView:parameterScroll.contentView];assert(parameterScroll.contentView.bounds.origin.y==120&&NSEqualRects(fixedMenu,randNavigator.navigatorFormulaMenu.frame)&&fixedHeader.frame.size.height==fixedHeight);[randNavigator populateNavigatorFormulaValues];assert(parameterScroll.contentView.bounds.origin.y==120&&fixedHeader.frame.size.height==fixedHeight);
        puts("Navigator formula controls stay outside the scrolling parameter document; scrolling and repopulation preserve the fixed toolbar.");
        puts("RandCubesIFS Navigator creates, displays and reads all 13 parameters.");
        AppDelegate *formulaUI=[AppDelegate new];RenderOptions extraSettings={0};extraSettings.iterations=60;extraSettings.program=defaultFormulaProgram();formulaUI.formulaSettings=extraSettings;[formulaUI showFormulas:nil];[formulaUI.formulasWindow orderOut:nil];
        for(int kindIndex=0;kindIndex<4;kindIndex++){int kind=kindIndex==3?6:102+kindIndex;formulaSelectKind(formulaUI.formulaMenus[0],kind);[formulaUI formulaSelectionChanged:formulaUI.formulaMenus[0]];RenderOptions read=extraSettings;assert([formulaUI readFormulaWindow:&read]);assert(read.program.slots[0].kind==kind);for(int j=0;j<formula_parameter_count(kind);j++)assert(formula_slot_value(read.program.slots[0],j)==formula_parameter(kind,j)->default_value);randSettings.program.slots[0]=formula_slot_default(kind);randSettings.program.slots[0].count=1;randNavigator.navigatorFormulaSettings=randSettings;[randNavigator populateNavigatorFormulaValues];assert([randNavigator readNavigatorFormulaValues]);}
        randSettings.program.slots[0]=formula_slot_default(102);randSettings.program.slots[0].parameters[12]=6;randSettings.program.slots[0].count=1;randNavigator.navigatorFormulaSettings=randSettings;[randNavigator populateNavigatorFormulaValues];assert(randNavigator.navigatorFormulaSliders[12].maxValue==6);assert([randNavigator readNavigatorFormulaValues]&&randNavigator.navigatorFormulaSettings.program.slots[0].parameters[12]==6);
        randSettings.program.slots[0]=formula_slot_default(104);randSettings.program.slots[0].parameters[7]=-4;randSettings.program.slots[0].count=1;randNavigator.navigatorFormulaSettings=randSettings;[randNavigator populateNavigatorFormulaValues];assert(randNavigator.navigatorFormulaSliders[7].minValue==-4&&randNavigator.navigatorFormulaSliders[7].maxValue==2);assert([randNavigator readNavigatorFormulaValues]&&randNavigator.navigatorFormulaSettings.program.slots[0].parameters[7]==-4);
        formulaSelectKind(formulaUI.formulaMenus[0],104);[formulaUI formulaSelectionChanged:formulaUI.formulaMenus[0]];formulaUI.randFormulaFields[0][7].stringValue=@"-4";RenderOptions copySettings=extraSettings;assert([formulaUI readFormulaWindow:&copySettings]&&copySettings.program.slots[0].parameters[7]==-4);
        puts("Four new formulas expose original defaults in Formulas and Navigator editors.");
        assert(formulaUI.formulaMenus[0].pullsDown&&formulaUI.formulaMenus[0].numberOfItems==9);NSMutableSet *menuKinds=[NSMutableSet set];
        NSArray *categoryTitles=@[@"3D",@"3Da",@"4D",@"4Da",@"Ads",@"dIFS",@"dIFSa"];
        for(int c=0;c<7;c++){NSMenuItem *category=[formulaUI.formulaMenus[0] itemAtIndex:c+2];assert([category.title isEqual:categoryTitles[c]]&&category.submenu.numberOfItems>0);for(NSMenuItem *leaf in category.submenu.itemArray){assert(formulaCategory((int)leaf.tag)==c);assert(![menuKinds containsObject:@(leaf.tag)]);[menuKinds addObject:@(leaf.tag)];}}
        for(int index=0;index<formula_menu_count();index++){
            int selected=formulaKindForMenu(index);formulaSelectKind(formulaUI.formulaMenus[0],selected);int boldCategories=0,boldFormulas=0;
            for(NSMenuItem *category in formulaUI.formulaMenus[0].itemArray){
                if(!category.hasSubmenu)continue;
                if(category.attributedTitle.length){NSFont *font=[category.attributedTitle attribute:NSFontAttributeName atIndex:0 effectiveRange:NULL];assert([NSFontManager.sharedFontManager traitsOfFont:font]&NSBoldFontMask);boldCategories++;}
                for(NSMenuItem *leaf in category.submenu.itemArray){BOOL current=leaf.tag==selected;assert(leaf.attributedTitle.length==0);assert((leaf.state==NSControlStateValueOn)==current);if(current){assert(category.attributedTitle.length>0);boldFormulas++;}}
            }
            assert(boldCategories==1&&boldFormulas==1);
        }
        assert(menuKinds.count==(NSUInteger)formula_menu_count());NSMenuItem *pick=nil;for(NSMenuItem *category in formulaUI.formulaMenus[0].itemArray)for(NSMenuItem *leaf in category.submenu.itemArray)if(leaf.tag==133)pick=leaf;assert(pick);[formulaUI formulaMenuChosen:pick];assert(formulaSelectedKind(formulaUI.formulaMenus[0])==133&&[formulaUI.formulaMenus[0].title isEqual:@"MixPinski4"]);
        const int newKinds[]={2,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133};for(int i=0;i<30;i++){
            int kind=newKinds[i];assert(formulaKindForMenu(formulaMenuForKind(kind))==kind);
            formulaSelectKind(formulaUI.formulaMenus[0],kind);[formulaUI formulaSelectionChanged:formulaUI.formulaMenus[0]];
            RenderOptions read=extraSettings;assert([formulaUI readFormulaWindow:&read]);assert(read.program.slots[0].kind==kind);
            randSettings.program.slots[0]=formula_slot_default(kind);randSettings.program.slots[0].count=1;randNavigator.navigatorFormulaSettings=randSettings;[randNavigator populateNavigatorFormulaValues];assert([randNavigator readNavigatorFormulaValues]);
            for(int j=0;j<formula_parameter_count(kind);j++)assert(formula_slot_value(randNavigator.navigatorFormulaSettings.program.slots[0],j)==formula_parameter(kind,j)->default_value);
        }
        puts("All added formulas expose correct defaults in Formulas and Navigator.");
        RenderOptions longValues=extraSettings;longValues.program=defaultFormulaProgram();longValues.program.slots[0]=formula_slot_default(112);longValues.program.slots[0].count=1;formula_slot_set_value(&longValues.program.slots[0],13,1234.25);formula_slot_set_value(&longValues.program.slots[0],14,.47);formulaUI.formulaSettings=longValues;[formulaUI populateFormulaWindow];assert([formulaUI readFormulaWindow:&longValues]);assert(formula_slot_value(longValues.program.slots[0],13)==1234.25&&formula_slot_value(longValues.program.slots[0],14)==.47);
        randNavigator.navigatorFormulaSettings=longValues;[randNavigator populateNavigatorFormulaValues];assert(!randNavigator.navigatorFormulaFields[14].hidden&&[randNavigator readNavigatorFormulaValues]);assert(formula_slot_value(randNavigator.navigatorFormulaSettings.program.slots[0],13)==1234.25);
        RenderOptions otherLong=longValues;formula_slot_set_value(&otherLong.program.slots[0],13,1236.25);assert(formula_slot_value(animation_interpolate(longValues,otherLong,.5).program.slots[0],13)==1235.25);

        ManualRenderProbe *manual=[ManualRenderProbe new];[manual ensureWindow];[manual.window orderOut:nil];RenderOptions clipboardSettings={0};char loadError[512];assert(read_scene_settings("example.m3i",&clipboardSettings,loadError));NSImage *oldImage=[[NSImage alloc] initWithSize:NSMakeSize(10,10)];manual.imageView.image=oldImage;[manual loadClipboardSettings:clipboardSettings path:@"example.m3i"];assert(manual.renderStarts==0&&manual.parametersPendingRender&&manual.imageView.image==oldImage);assert(manual.calculationFields[0].intValue==clipboardSettings.width/MAX(1,clipboardSettings.oversampling));[manual requestNavigatorPreview];[manual requestLightingPreview];[manual calculate:nil];assert(manual.renderStarts==0&&!manual.previewPending&&!manual.lightingPreviewPending);manual.calculationFields[0].stringValue=@"320";manual.calculationFields[1].stringValue=@"240";[manual calculate:manual.renderButton];assert(manual.renderStarts==1&&!manual.parametersPendingRender&&manual.submittedOptions.width==320&&manual.submittedOptions.height==240&&!manual.submittedOptions.reuse_surface);[manual calculate:nil];assert(manual.submittedOptions.reuse_surface);[manual finishLightingSlider];assert(manual.submittedLightingRepaint&&!manual.lightingRepaintRequested);[manual calculate:manual.renderButton];assert(!manual.submittedLightingRepaint);
        ManualRenderProbe *precision=[ManualRenderProbe new];[precision ensureWindow];[precision.window orderOut:nil];RenderOptions precise=clipboardSettings;precise.de_stop=.16827499866485596;precise.ray_step=.05000000074505806;precise.shadows.hard_length=.123456789123456;precise.shadows.hard_radius=3.141592653589793;precise.shadows.ambient_length=.23456789123456;precise.lights[0].position[0]=-.12214322023539381;
        [precision loadClipboardSettings:precise path:@"example.m3i"];precision.parametersPendingRender=NO;[precision showLighting:nil];[precision.lightingWindow orderOut:nil];[precision showPostProcess:nil];[precision.postWindow orderOut:nil];[precision calculate:nil];RenderOptions submitted=precision.submittedOptions;
        assert(submitted.reuse_surface&&submitted.de_stop==precise.de_stop&&submitted.ray_step==precise.ray_step&&submitted.shadows.hard_length==precise.shadows.hard_length&&submitted.shadows.hard_radius==precise.shadows.hard_radius&&submitted.shadows.ambient_length==precise.shadows.ambient_length&&submitted.lights[0].position[0]==precise.lights[0].position[0]);
        precision.shadowFields[0].stringValue=@"2";[precision calculate:nil];assert(precision.submittedOptions.shadows.hard_length==2);
        puts("Lighting edits preserve unchanged calculation, shadow and angular-light precision so display formatting cannot invalidate caches.");
        puts("Clipboard settings load without rendering or replacing the image; previews wait and Render uses edited dimensions.");
        PostShadowSliderProbe *postSliders=[PostShadowSliderProbe new];postSliders.formulaKnown=YES;postSliders.formulaSettings=clipboardSettings;[postSliders showPostProcess:nil];[postSliders.postWindow orderOut:nil];assert(postSliders.ambientShadowSliders.count==4);
        LiveSlider *strengthSlider=(LiveSlider *)postSliders.ambientShadowSliders[0];assert(strengthSlider.started&&strengthSlider.finished);strengthSlider.started();strengthSlider.doubleValue=2.3;[postSliders ambientShadowSliderChanged:strengthSlider];assert(postSliders.previews==1&&fabs(postSliders.captured.shadows.ambient_strength-2.3)<1e-12);[postSliders finishLightingSlider];assert(postSliders.commits==0);strengthSlider.finished();assert(postSliders.commits==1&&fabs(postSliders.captured.shadows.ambient_strength-2.3)<1e-12);
        postSliders.ambientShadowSliders[1].doubleValue=-2;[postSliders ambientShadowSliderChanged:postSliders.ambientShadowSliders[1]];assert(fabs(postSliders.captured.shadows.ambient_length-.01)<1e-12);
        postSliders.ambientShadowSliders[2].doubleValue=17.4;[postSliders ambientShadowSliderChanged:postSliders.ambientShadowSliders[2]];assert(postSliders.captured.shadows.ambient_rays==17&&postSliders.ambientShadowSliders[2].doubleValue==17);
        postSliders.shadowFields[5].stringValue=@"256";[postSliders ambientShadowValueEdited:postSliders.shadowFields[5]];assert(postSliders.captured.shadows.ambient_steps==256&&postSliders.ambientShadowSliders[3].doubleValue==256);
        [postSliders setCalculating:YES];for(NSSlider *slider in postSliders.ambientShadowSliders)assert(!slider.enabled);[postSliders setCalculating:NO];for(NSSlider *slider in postSliders.ambientShadowSliders)assert(slider.enabled);
        puts("Ambient Shadows sliders preview continuously, commit on release, preserve typed values and snap integer counts; Shift uses LiveSlider fine control.");
        AppDelegate *adaptive=[AppDelegate new];
        adaptive.fixedZoomCheck=[NSButton new];adaptive.fixedZoomCheck.state=NSControlStateValueOff;
        adaptive.moveStepField=[NSTextField new];adaptive.moveStepField.stringValue=@"0.1";
        adaptive.navigatorFarField=[NSTextField new];adaptive.navigatorFarField.stringValue=@"50";
        adaptive.navigatorCamera=(CameraSettings){.zoom=2,.distance=50};
        adaptive.formulaSettings=(RenderOptions){.width=480,.height=360};
        adaptive.navigatorReferenceDistance=1;adaptive.navigatorReferenceZoom=2;adaptive.navigatorReferenceMove=.1;
        [adaptive adaptNavigatorDistance:.5];
        assert(fabs(adaptive.navigatorCamera.zoom-4)<1e-12&&fabs(adaptive.moveStepField.doubleValue-.05)<1e-12&&fabs(adaptive.navigatorCamera.distance-25)<1e-12);
        assert(adaptive.previewPending&&adaptive.navigatorDistanceAdapted);
        adaptive.previewPending=NO;CameraSettings corrected=adaptive.navigatorCamera;
        [adaptive adaptNavigatorDistance:.25];[adaptive adaptNavigatorDistance:.125];
        assert(!adaptive.previewPending&&adaptive.navigatorCamera.zoom==corrected.zoom&&adaptive.navigatorCamera.distance==corrected.distance);
        adaptive.navigatorDistanceAdapted=NO;[adaptive adaptNavigatorDistance:.5];assert(!adaptive.previewPending);
        puts("Navigator auto-zoom corrects once per edit; completion and refinement cannot trigger a render feedback loop.");
        adaptive.fixedZoomCheck.state=NSControlStateValueOn;[adaptive adaptNavigatorDistance:.25];
        assert(fabs(adaptive.navigatorCamera.zoom-4)<1e-12&&fabs(adaptive.moveStepField.doubleValue-.05)<1e-12);
        puts("Navigator adaptive zoom/steps track local distance; fixed mode retains both.");
        CameraSettings toggleStart=adaptive.navigatorCamera;toggleStart.zoom=.37;adaptive.navigatorCamera=toggleStart;adaptive.navigatorLocalDistance=.25;adaptive.moveStepField.stringValue=@"0.8";CameraSettings toggleCamera=adaptive.navigatorCamera;
        adaptive.fixedZoomCheck.state=NSControlStateValueOn;[adaptive fixedZoomChanged:nil];CameraSettings afterFixed=adaptive.navigatorCamera;assert(!memcmp(&toggleCamera,&afterFixed,sizeof toggleCamera)&&[adaptive.moveStepField.stringValue isEqual:@"0.8"]);
        adaptive.fixedZoomCheck.state=NSControlStateValueOff;[adaptive fixedZoomChanged:nil];[adaptive adaptNavigatorDistance:.25];CameraSettings afterToggle=adaptive.navigatorCamera;assert(!memcmp(&toggleCamera,&afterToggle,sizeof toggleCamera)&&[adaptive.moveStepField.stringValue isEqual:@"0.8"]);
        adaptive.navigatorDistanceAdapted=NO;[adaptive adaptNavigatorDistance:.125];assert(fabs(adaptive.navigatorCamera.zoom-.74)<1e-12&&fabs(adaptive.moveStepField.doubleValue-.4)<1e-12);
        adaptive.moveStepField.stringValue=@"0";adaptive.fixedZoomCheck.state=NSControlStateValueOn;[adaptive fixedZoomChanged:nil];assert([adaptive.moveStepField.stringValue isEqual:@"0"]);
        puts("Fixed-mode toggles preserve zoom, camera and step, including zero; adaptive changes remain relative to the captured view.");

        LightingCommitProbe *probe=[LightingCommitProbe new];
        probe.editedAngle=10;[probe beginLightingSlider];
        [probe finishLightingSlider];assert(probe.commits==0);
        probe.editedAngle=75;[probe finishLightingSlider];assert(probe.commits==0);
        [probe endLightingSlider];assert(probe.commits==1&&probe.committedAngle==75);
        puts("Lighting commits defer during tracking and retain the final slider value.");
        NSBitmapImageRep *bitmap=[[NSBitmapImageRep alloc] initWithBitmapDataPlanes:NULL
            pixelsWide:100 pixelsHigh:100 bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES
            isPlanar:NO colorSpaceName:NSDeviceRGBColorSpace bytesPerRow:400 bitsPerPixel:32];
        NSGraphicsContext *context=[NSGraphicsContext graphicsContextWithBitmapImageRep:bitmap];
        [NSGraphicsContext saveGraphicsState];[NSGraphicsContext setCurrentContext:context];
        [[NSColor colorWithDeviceRed:1 green:0 blue:1 alpha:1] setFill];NSRectFill(NSMakeRect(0,0,100,100));
        CalculationPanel *panel=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,20,20)];
        [panel drawRect:NSMakeRect(0,0,100,100)];
        [context flushGraphics];[NSGraphicsContext restoreGraphicsState];
        NSColor *outside=[[bitmap colorAtX:70 y:70] colorUsingColorSpace:NSColorSpace.deviceRGBColorSpace];
        assert(outside.redComponent>.99 && outside.greenComponent<.01 && outside.blueComponent>.99);
        assert(panel.wantsDefaultClipping);
        unsigned char samplePixels[16]={0,0,0,255,100,100,100,255,200,200,200,255,252,252,252,255};
        RenderResult sample={.rgba=samplePixels,.width=2,.height=2,.stride=8};
        NSImage *reduced=imageForRender(sample,2);assert(reduced.size.width==1&&reduced.size.height==1);
        NSBitmapImageRep *rep=(NSBitmapImageRep *)reduced.representations[0];assert(rep.pixelsWide==2&&rep.pixelsHigh==2&&rep.bitmapData[0]==0&&rep.bitmapData[4]==100&&rep.bitmapData[3]==255);
        NSData *png=[rep representationUsingType:NSBitmapImageFileTypePNG properties:@{}];assert(png.length>8);
        const unsigned char *signature=png.bytes;assert(signature[0]==137&&signature[1]=='P'&&signature[2]=='N'&&signature[3]=='G');
        NSBitmapImageRep *pngRead=[[NSBitmapImageRep alloc] initWithData:png];assert(pngRead.pixelsWide==2&&pngRead.pixelsHigh==2);
        NSColor *pngPixel=[pngRead colorAtX:1 y:0];assert(fabs(pngPixel.redComponent-100./255)<.001);
        puts("PNG encoding retains the supplied bitmap dimensions and pixel colors.");
        RenderOptions source={.width=1920,.height=1080,.oversampling=3,.viewing=3,.de_stop=1.5,.iterations=120,.normal_smoothing=8};
        source.program=defaultFormulaProgram();source.program.slots[0].count=9;source.shadows.ambient_rays=32;source.shadows.ambient_steps=128;
        source.shadows.hard_enabled=1;source.lights[5].amplitude=2;source.reflections=(ReflectionSettings){.enabled=1,.automatic=1,.depth=4,.amount=1,.refractive_index=1.5};source.dof=(DepthOfFieldSettings){.enabled=1,.automatic=1,.passes=2,.aperture=.1,.clip_radius=25};
        for(int stage=0;stage<3;stage++){
            RenderOptions preview=navigatorPreviewOptions(source,stage);
            assert(preview.width==(stage==0?80:stage==1?160:320));
            assert(fabs(preview.de_stop/preview.width-source.de_stop/source.width)<1e-15);
            assert(preview.preview_cache==1);
            assert(preview.oversampling==1&&preview.iterations==source.iterations&&preview.program.slots[0].count==9);
            assert(preview.shadows.hard_enabled==(stage==2)&&preview.lights[5].amplitude==2);
            assert(preview.reflections_override&&!preview.reflections.enabled&&!preview.reflections.automatic&&preview.dof_override&&!preview.dof.enabled&&!preview.dof.automatic);
            assert(preview.normals_override&&preview.normal_zbuffer&&preview.normal_smoothing==0);
            if(stage==2)assert(preview.shadows.ambient_rays==7&&preview.shadows.ambient_steps==32);else assert(preview.shadows.ambient_method==0);
        }
        puts("Navigator fast preview preserves world DE threshold, formula iterations and lights; uses depth normals, simplified shadows and no reflections/transparency/DoF.");
        AppDelegate *priority=[AppDelegate new];priority.formulaKnown=YES;priority.lightingPreviewBusy=YES;
        RenderCancelToken *background=render_cancel_create();priority.navigatorCancelToken=background;
        [priority requestLightingPreview];assert(priority.lightingPreviewPending&&priority.navigatorRefinementTicket==1);
        RenderResult stopped=render_scene_with_options(NULL,(RenderOptions){.width=16,.height=16,.cancel_token=background});assert(stopped.cancelled&&!stopped.rgba);
        priority.navigatorCancelToken=NULL;render_cancel_destroy(background);
        puts("Lighting edits cancel background Navigator rendering and invalidate delayed refinement.");
        PositionalLightProbe *positional=[PositionalLightProbe new];NSTabView *lightTabs=[[NSTabView alloc]initWithFrame:NSMakeRect(0,0,552,700)];[positional addLightTabs:lightTabs];
        PositionalLightProbe *markedLights=[PositionalLightProbe new];NSTabView *markedTabs=[[NSTabView alloc]initWithFrame:NSMakeRect(0,0,552,700)];[markedLights addLightTabs:markedTabs];RenderOptions markedSettings={0};for(int i=0;i<6;i++)markedSettings.lights[i].option=i%2;markedLights.formulaSettings=markedSettings;[markedLights populateLights];
        for(int i=0;i<6;i++)assert(([markedLights.lightSourceTabs.tabViewItems[i].label isEqual:[NSString stringWithFormat:@"Light %d%@",i+1,i%2?@"":@"*"]]));
        NSButton *enableMarked=(NSButton*)markedLights.lightControls[1][0];enableMarked.state=NSControlStateValueOn;[markedLights lightEnabledChanged:enableMarked];assert([markedLights.lightSourceTabs.tabViewItems[1].label isEqual:@"Light 2*"]);enableMarked.state=NSControlStateValueOff;[markedLights lightEnabledChanged:enableMarked];assert([markedLights.lightSourceTabs.tabViewItems[1].label isEqual:@"Light 2"]);
        assert(positional.lightMoveSteps.count==6&&positional.positionControls.count==48);
        for(int light=0;light<6;light++){
            NSArray *controls=positional.lightControls[light];NSPopUpButton *type=(NSPopUpButton *)controls[1];assert([type itemAtIndex:1].title.length);[type selectItemAtIndex:1];
            positional.lightMoveSteps[light].stringValue=@"0.25";for(int axis=0;axis<3;axis++)[(NSTextField *)controls[axis+4] setStringValue:@"1"];
            NSButton *move=[NSButton new];move.tag=light*6+1;[positional movePositionalLight:move];assert([(NSTextField *)controls[4] doubleValue]==1.25);
            move.tag=light*6+4;[positional movePositionalLight:move];assert([(NSTextField *)controls[6] doubleValue]==.75);
        }
        assert(positional.lightUpdates==12);
        RenderCancelToken *stopToken=render_cancel_create();manual.mainCancelToken=stopToken;[manual setCalculating:YES];assert(manual.stopButton.enabled&&!manual.renderButton.enabled);
        NSImage *previousImage=manual.imageView.image;[manual stopRender:nil];assert(!manual.stopButton.enabled&&manual.imageView.image==previousImage);
        RenderResult stopResult=render_scene_with_options(NULL,(RenderOptions){.width=16,.height=16,.cancel_token=stopToken});assert(stopResult.cancelled&&!stopResult.rgba);manual.mainCancelToken=NULL;render_cancel_destroy(stopToken);[manual setCalculating:NO];assert(manual.renderButton.enabled&&!manual.stopButton.enabled);
        FractalView *pickView=[[FractalView alloc]initWithFrame:NSMakeRect(0,0,400,300)];pickView.image=[[NSImage alloc]initWithSize:NSMakeSize(200,100)];pickView.pickingLight=YES;__block NSPoint clicked=NSZeroPoint;__block int clickCount=0;pickView.placeLight=^(NSPoint point){clicked=point;clickCount++;};
        NSEvent *click=[NSEvent mouseEventWithType:NSEventTypeLeftMouseDown location:NSMakePoint(100,100) modifierFlags:0 timestamp:0 windowNumber:0 context:nil eventNumber:0 clickCount:1 pressure:1];[pickView mouseDown:click];assert(clickCount==1&&fabs(clicked.x-.25)<1e-12&&fabs(clicked.y-.75)<1e-12);
        click=[NSEvent mouseEventWithType:NSEventTypeLeftMouseDown location:NSMakePoint(100,10) modifierFlags:0 timestamp:0 windowNumber:0 context:nil eventNumber:0 clickCount:1 pressure:1];[pickView mouseDown:click];assert(clickCount==1);
        puts("Stop Render cancels without replacing the image; all six positional lights move; scaled image clicks map to surface coordinates and reject margins.");
        ManualRenderProbe *dofUI=[ManualRenderProbe new];[dofUI ensureWindow];[dofUI.window orderOut:nil];dofUI.formulaKnown=YES;dofUI.formulaSettings=clipboardSettings;
        [dofUI showPostProcess:nil];[dofUI.postWindow orderOut:nil];assert([(NSTabView *)dofUI.postWindow.contentView numberOfTabViewItems]==4&&dofUI.dofFields.count==4&&dofUI.dofSliders.count==4);
        NSTabView *postTabs=(NSTabView *)dofUI.postWindow.contentView;
        RenderOptions postOriginal=dofUI.formulaSettings,postState=postOriginal;
        postState.shadows.hard_enabled=0;postState.shadows.hard_auto=0;
        postState.shadows.ambient_enabled=0;postState.shadows.ambient_auto=0;
        postState.reflections.enabled=0;postState.reflections.automatic=0;
        postState.dof.enabled=0;postState.dof.automatic=0;
        dofUI.formulaSettings=postState;[dofUI populateShadowSettings];for(NSTabViewItem *tab in postTabs.tabViewItems)assert(![tab.label hasSuffix:@"*"]);
        for(NSButton *check in dofUI.shadowAutoChecks){[check performClick:nil];}dofUI.reflectionAutomatic.state=NSControlStateValueOn;[dofUI reflectionEdited:dofUI.reflectionAutomatic];dofUI.dofAutomatic.state=NSControlStateValueOn;[dofUI dofEdited:dofUI.dofAutomatic];
        for(NSTabViewItem *tab in postTabs.tabViewItems)assert([tab.label hasSuffix:@"*"]);
        postState.shadows.hard_enabled=1;postState.shadows.ambient_enabled=1;postState.reflections.enabled=1;postState.dof.enabled=1;
        dofUI.formulaSettings=postState;[dofUI populateShadowSettings];for(NSTabViewItem *tab in postTabs.tabViewItems)assert([tab.label hasSuffix:@"*"]);
        dofUI.formulaSettings=postOriginal;[dofUI populateShadowSettings];
        puts("Post-process tab stars follow automatic toggles and loaded applied states across all four tabs.");
        dofUI.dofFields[0].stringValue=@"0.123456789123";dofUI.dofFields[1].stringValue=@"0.25";dofUI.dofFields[2].stringValue=@"0.125";dofUI.dofFields[3].stringValue=@"12.5";[dofUI.dofPasses selectItemAtIndex:2];dofUI.dofAutomatic.state=NSControlStateValueOn;
        RenderOptions dofRead=clipboardSettings;assert([dofUI readDepthOfField:&dofRead]&&dofRead.dof.enabled&&dofRead.dof.passes==3&&dofRead.dof.aperture==.125&&dofRead.dof.focus1==.123456789123);
        [dofUI setCalculating:YES];for(NSControl *control in dofUI.dofControls)assert(!control.enabled);[dofUI setCalculating:NO];for(NSControl *control in dofUI.dofControls)assert(control.enabled);
        [dofUI copyDofFocus:nil];assert([dofUI.dofFields[0].stringValue isEqualToString:dofUI.dofFields[1].stringValue]);
        NSImage *sharpPreview=[[NSImage alloc]initWithSize:NSMakeSize(10,10)];dofUI.sharpRenderImage=sharpPreview;int beforeDofOff=dofUI.renderStarts;
        dofUI.dofAutomatic.state=NSControlStateValueOff;[dofUI dofEdited:dofUI.dofAutomatic];assert(dofUI.renderStarts==beforeDofOff&&dofUI.imageView.image==sharpPreview&&!dofUI.formulaSettings.dof.enabled&&!dofUI.formulaSettings.dof.automatic);
        dofUI.dofApplied=YES;NSButton *dofReset=[NSButton new];dofReset.tag=0;[dofUI dofAction:dofReset];assert(!dofUI.dofApplied&&dofUI.dofAutomatic.state==NSControlStateValueOff&&dofUI.renderStarts==beforeDofOff&&dofUI.imageView.image==sharpPreview);
        puts("Turning off or resetting DoF restores the sharp image without starting a render.");
        assert(dofUI.reflectionFields.count==5&&dofUI.reflectionOnlyDIFS&&dofUI.reflectionAutomatic);RenderOptions reflectionRead=dofUI.formulaSettings;
        dofUI.reflectionTransparency.state=NSControlStateValueOn;dofUI.reflectionOnlyDIFS.state=NSControlStateValueOn;dofUI.reflectionDepth.integerValue=3;[dofUI reflectionDepthChanged:dofUI.reflectionDepth];assert([dofUI readReflections:&reflectionRead]&&reflectionRead.reflections.transparency&&reflectionRead.reflections.only_difs&&reflectionRead.reflections.depth==3);
        int beforeReflectionEdits=dofUI.renderStarts;dofUI.reflectionAutomatic.state=NSControlStateValueOn;[dofUI reflectionEdited:dofUI.reflectionAutomatic];
        for(NSTextField *field in dofUI.reflectionFields)[dofUI reflectionEdited:field];[dofUI reflectionEdited:dofUI.reflectionTransparency];[dofUI reflectionEdited:dofUI.reflectionOnlyDIFS];[dofUI reflectionDepthChanged:dofUI.reflectionDepth];assert(dofUI.renderStarts==beforeReflectionEdits);
        assert([[(NSTabView *)dofUI.postWindow.contentView tabViewItemAtIndex:2].label isEqualToString:@"Refl/Trans*"]);
        assert(dofUI.reflectionAmountSlider.minValue==0&&dofUI.reflectionAmountSlider.maxValue==1&&dofUI.reflectionAmountSlider.isContinuous);
        dofUI.reflectionAmountSlider.doubleValue=.375;[dofUI reflectionAmountChanged:dofUI.reflectionAmountSlider];assert(dofUI.reflectionFields[0].doubleValue==.375&&dofUI.renderStarts==beforeReflectionEdits);
        dofUI.reflectionFields[0].stringValue=@"0.625";[dofUI reflectionEdited:dofUI.reflectionFields[0]];assert(dofUI.reflectionAmountSlider.doubleValue==.625&&dofUI.renderStarts==beforeReflectionEdits);
        for(NSControl *control in dofUI.reflectionControls)assert(control.toolTip.length>0);
        dofUI.reflectionFields[0].stringValue=@"100.01";assert(![dofUI readReflections:&reflectionRead]);dofUI.reflectionFields[0].stringValue=@"0";assert([dofUI readReflections:&reflectionRead]);dofUI.reflectionFields[0].stringValue=@"1";assert([dofUI readReflections:&reflectionRead]);
        NSButton *reflectionReset=[NSButton new];reflectionReset.tag=0;[dofUI reflectionAction:reflectionReset];assert(dofUI.reflectionAutomatic.state==NSControlStateValueOn&&dofUI.submittedOptions.reflections.automatic&&!dofUI.submittedOptions.reflections.enabled&&!dofUI.resettingReflections);[dofUI calculate:nil];assert(dofUI.submittedOptions.reflections.enabled&&dofUI.submittedOptions.reflections.automatic);
        for(NSTabViewItem *item in [(NSTabView*)dofUI.postWindow.contentView tabViewItems])for(NSView *view in item.view.subviews)if([view isKindOfClass:NSButton.class])assert(![[(NSButton*)view title] hasPrefix:@"Calculate only"]);
        dofUI.calculationFields[0].stringValue=@"123";dofUI.calculationFields[1].stringValue=@"77";dofUI.parametersPendingRender=YES;RenderOptions saveParameters;assert([dofUI readMainSettings:&saveParameters sender:nil]);int beforeParameterSave=dofUI.renderStarts;NSImage *imageBeforeSave=dofUI.imageView.image;NSString *parameterPath=[NSTemporaryDirectory() stringByAppendingPathComponent:[NSString stringWithFormat:@"m3dx-parameter-save-%@.m3i",NSUUID.UUID.UUIDString]];assert([[@"old contents" dataUsingEncoding:NSUTF8StringEncoding] writeToFile:parameterPath atomically:YES]);[dofUI saveM3IParametersTo:parameterPath options:saveParameters];NSDate *saveLimit=[NSDate dateWithTimeIntervalSinceNow:10];while(dofUI.calculating&&saveLimit.timeIntervalSinceNow>0)CFRunLoopRunInMode(kCFRunLoopDefaultMode,.02,YES);assert(!dofUI.calculating&&dofUI.renderStarts==beforeParameterSave&&dofUI.imageView.image==imageBeforeSave&&dofUI.parametersPendingRender);char parameterError[512];RenderOptions savedParameters;assert(read_scene_settings(parameterPath.fileSystemRepresentation,&savedParameters,parameterError)&&savedParameters.width==123&&savedParameters.height==77);[NSFileManager.defaultManager removeItemAtPath:parameterPath error:nil];
        puts("Save M3I writes pending current parameters and replaces an existing file without rendering, changing the image or clearing pending-render state.");
        puts("Depth of Field tab reads focus/aperture/clipping/passes, copies focus, resets, and disables controls during rendering.");
        RenderOptions first=clipboardSettings,lastKey=first;first.camera_override=lastKey.camera_override=1;lastKey.camera.origin[0]+=2;lastKey.camera.zoom*=4;camera_turn(&lastKey.camera,170,0,0);lastKey.program.slots[0].power=2;lastKey.lights[0].position[0]=-170*M_PI/180;first.lights[0].position[0]=170*M_PI/180;
        RenderOptions midpoint=animation_interpolate(first,lastKey,.5);assert(fabs(midpoint.camera.origin[0]-first.camera.origin[0]-1)<1e-10&&fabs(midpoint.camera.zoom-first.camera.zoom*2)<1e-10&&midpoint.program.slots[0].power==5);assert(fabs(fabs(midpoint.lights[0].position[0])-M_PI)<1e-10);
        for(int row=0;row<3;row++)for(int other=0;other<3;other++){double sum=0;for(int j=0;j<3;j++)sum+=midpoint.camera.axes[row*3+j]*midpoint.camera.axes[other*3+j];assert(fabs(sum-(row==other))<1e-10);}
        RenderOptions endpoint=animation_interpolate(first,lastKey,1);assert(!memcmp(endpoint.camera.axes,lastKey.camera.axes,sizeof endpoint.camera.axes));
        RenderOptions different=lastKey;different.program.slots[0]=formula_slot_default(107);different.program.slots[0].count=1;assert(animation_interpolate(first,different,.99).program.slots[0].kind==0);
        ManualRenderProbe *animation=[ManualRenderProbe new];[animation ensureWindow];[animation.window orderOut:nil];animation.formulaKnown=YES;animation.formulaSettings=first;animation.currentPath=@"example.m3i";animation.completedRender=manual.completedRender?manual.completedRender:[[NSBitmapImageRep alloc]initWithBitmapDataPlanes:NULL pixelsWide:2 pixelsHigh:2 bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSDeviceRGBColorSpace bytesPerRow:8 bitsPerPixel:32];animation.imageView.image=[[NSImage alloc]initWithSize:NSMakeSize(2,2)];
        [animation showAnimation:nil];[animation.animationWindow orderOut:nil];animation.animationFields[0].stringValue=@"2";NSButton *keyAction=[NSButton new];keyAction.tag=0;[animation animationKeyAction:keyAction];animation.formulaSettings=lastKey;[animation animationKeyAction:keyAction];assert(animation.animationKeys.count==2&&[animation animationFrameCount]==3);
        NSString *framePath;RenderOptions sampled=[animation animationOptionsAtFrame:1 keys:animation.animationKeys loop:NO ease:NO path:&framePath];assert(fabs(sampled.camera.origin[0]-midpoint.camera.origin[0])<1e-10&&framePath.length>0);sampled=[animation animationOptionsAtFrame:2 keys:animation.animationKeys loop:NO ease:NO path:&framePath];assert(sampled.camera.origin[0]==lastKey.camera.origin[0]);
        animation.animationLoop.state=NSControlStateValueOn;assert([animation animationFrameCount]==4);sampled=[animation animationOptionsAtFrame:3 keys:animation.animationKeys loop:YES ease:NO path:&framePath];assert(fabs(sampled.camera.origin[0]-midpoint.camera.origin[0])<1e-10);
        NSDictionary *project=[animation animationProject];assert(project&&[project[@"keys"][0][@"source"] length]<10000);NSData *serialized=[NSPropertyListSerialization dataWithPropertyList:project format:NSPropertyListBinaryFormat_v1_0 options:0 error:nil];assert(serialized);NSDictionary *decoded=[NSPropertyListSerialization propertyListWithData:serialized options:NSPropertyListImmutable format:nil error:nil];assert([animation loadAnimationProject:decoded]&&animation.animationKeys.count==2&&[animation animationFrameCount]==4);
        NSString *restored=animation.animationKeys[0][@"path"];RenderOptions restoredSettings;char animationError[512];assert(read_scene_settings(restored.fileSystemRepresentation,&restoredSettings,animationError)&&restoredSettings.width==clipboardSettings.width);
        NSMutableDictionary *invalid=[decoded mutableCopy];invalid[@"optionsSize"]=@1;assert(![animation loadAnimationProject:invalid]);
        keyAction.tag=3;[animation.animationTable selectRowIndexes:[NSIndexSet indexSetWithIndex:1] byExtendingSelection:NO];[animation animationKeyAction:keyAction];assert(animationUnpack(animation.animationKeys[0][@"settings"]).camera.origin[0]==lastKey.camera.origin[0]);
        keyAction.tag=2;[animation animationKeyAction:keyAction];assert(animation.animationKeys.count==1&&[animation animationFrameCount]==1);
        int beforeKeyLoad=animation.renderStarts;NSImage *beforeKeyImage=animation.imageView.image;NSBitmapImageRep *beforeKeyBitmap=animation.completedRender;
        [animation.animationTable selectRowIndexes:[NSIndexSet indexSetWithIndex:0] byExtendingSelection:NO];keyAction.tag=5;RenderOptions keyLoaded=animationUnpack(animation.animationKeys[0][@"settings"]);[animation animationKeyAction:keyAction];
        assert(animation.renderStarts==beforeKeyLoad&&animation.parametersPendingRender&&animation.imageView.image==beforeKeyImage&&animation.completedRender==beforeKeyBitmap&&animation.formulaSettings.camera.origin[0]==keyLoaded.camera.origin[0]);
        animation.keepAspectCheck.state=NSControlStateValueOff;animation.calculationFields[0].stringValue=@"123";animation.calculationFields[1].stringValue=@"77";[animation calculate:nil];assert(animation.renderStarts==beforeKeyLoad);[animation calculate:animation.renderButton];assert(animation.renderStarts==beforeKeyLoad+1&&!animation.parametersPendingRender&&animation.submittedOptions.width==123&&animation.submittedOptions.height==77);
        puts("To Main loads keyframe controls and preserves the image without rendering; only Render submits subsequent edits.");
        for(NSString *temporary in animation.animationTemporarySources)[NSFileManager.defaultManager removeItemAtPath:temporary error:nil];
        puts("Animation interpolates camera, formula values and light angles; keyframes reorder, loop and survive compact native project save/reload.");
        RenderOptions slots=extraSettings;slots.program=defaultFormulaProgram();formulaUI.formulaSettings=slots;[formulaUI populateFormulaWindow];assert([formulaUI.formulaTabs tabViewItemAtIndex:0].label&&[[formulaUI.formulaTabs tabViewItemAtIndex:0].label isEqual:@"F1*"]);assert([[formulaUI.formulaTabs tabViewItemAtIndex:1].label isEqual:@"F2"]&&formulaUI.formulaCountFields[1].intValue==0);
        formulaSelectKind(formulaUI.formulaMenus[1],115);[formulaUI formulaSelectionChanged:formulaUI.formulaMenus[1]];assert(formulaUI.formulaCountFields[1].intValue==1&&[[formulaUI.formulaTabs tabViewItemAtIndex:1].label isEqual:@"F2*"]);
        formulaUI.formulaCountFields[1].stringValue=@"3";formulaSelectKind(formulaUI.formulaMenus[1],116);[formulaUI formulaSelectionChanged:formulaUI.formulaMenus[1]];assert(formulaUI.formulaCountFields[1].intValue==3);
        formulaUI.formulaCountFields[1].stringValue=@"0";[formulaUI controlTextDidChange:[NSNotification notificationWithName:NSControlTextDidChangeNotification object:formulaUI.formulaCountFields[1]]];assert([[formulaUI.formulaTabs tabViewItemAtIndex:1].label isEqual:@"F2"]);[formulaUI populateFormulaWindow];assert(formulaUI.formulaCountFields[1].intValue==0);
        assert(precision.lightStrengthSliders.count==6);for(int i=0;i<6;i++){NSSlider *slider=precision.lightStrengthSliders[i];slider.doubleValue=1.25+i*.25;[precision lightStrengthChanged:slider];RenderOptions lights=precise;assert([precision readLights:&lights]);assert(lights.lights[i].amplitude==1.25+i*.25);[precision syncLightSliders];assert(slider.doubleValue==1.25+i*.25);}
        [NSObject cancelPreviousPerformRequestsWithTarget:precision];
        puts("Formula selection enables zero-count slots, preserves positive counts and updates active tab stars without enabling loaded slots; six strength sliders preserve edits.");
        randSettings.program=defaultFormulaProgram();randNavigator.navigatorFormulaSettings=randSettings;randNavigator.navigatorFormulaSlot=0;[randNavigator.navigatorFormulaMenu selectItemAtIndex:0];[randNavigator populateNavigatorFormulaValues];
        assert(randNavigator.navigatorIterationField.frame.size.width<=55&&randNavigator.navigatorFormulaArrows.count==2&&!randNavigator.navigatorFormulaArrows[0].enabled&&randNavigator.navigatorFormulaArrows[1].enabled);
        randNavigator.navigatorFormulaFields[1].stringValue=@"-2.25";[randNavigator navigatorFormulaArrow:randNavigator.navigatorFormulaArrows[1]];assert(randNavigator.navigatorFormulaSlot==1&&randNavigator.navigatorFormulaSettings.program.slots[0].z_multiplier==-2.25);
        for(int i=1;i<7;i++)[randNavigator navigatorFormulaArrow:randNavigator.navigatorFormulaArrows[1]];assert(randNavigator.navigatorFormulaSlot==7&&!randNavigator.navigatorFormulaArrows[1].enabled);[randNavigator navigatorFormulaArrow:randNavigator.navigatorFormulaArrows[1]];assert(randNavigator.navigatorFormulaSlot==7);
        [randNavigator navigatorFormulaArrow:randNavigator.navigatorFormulaArrows[0]];assert(randNavigator.navigatorFormulaSlot==6);randNavigator.navigatorFormulaFields[0].stringValue=@"invalid";[randNavigator navigatorFormulaArrow:randNavigator.navigatorFormulaArrows[0]];assert(randNavigator.navigatorFormulaSlot==6&&randNavigator.navigatorFormulaMenu.indexOfSelectedItem==6);
        ColorPreviewProbe *colorProbe=[ColorPreviewProbe new];[colorProbe ensureWindow];[colorProbe.window orderOut:nil];colorProbe.formulaKnown=YES;colorProbe.formulaSettings=clipboardSettings;[colorProbe showLighting:nil];[colorProbe.lightingWindow orderOut:nil];[colorProbe showColorAdjustment:nil];[colorProbe.colorWindow orderOut:nil];assert(automaticColorUpdates);
        assert(!((AdjustmentColorWell*)colorProbe.colorDiffuseWell).allowsOpacity&&((AdjustmentColorWell*)colorProbe.colorSpecularWell).allowsOpacity);for(int i=0;i<10;i++)assert(!((AdjustmentColorWell*)colorProbe.diffuseWells[i]).allowsOpacity&&((AdjustmentColorWell*)colorProbe.specularWells[i]).allowsOpacity);
        NSArray<NSColorWell*> *pickerWells=@[colorProbe.colorDiffuseWell,colorProbe.colorSpecularWell,colorProbe.diffuseWells[1],(NSColorWell*)colorProbe.lightControls[0][2],colorProbe.ambientWells[0],colorProbe.ambientWells[2]];
        for(NSColorWell *well in pickerWells){int before=colorProbe.colorPreviews;[well activate:YES];assert(NSColorPanel.sharedColorPanel.continuous);assert(NSColorPanel.sharedColorPanel.showsAlpha==((AdjustmentColorWell*)well).allowsOpacity);NSColorPanel.sharedColorPanel.color=[NSColor colorWithSRGBRed:.17 green:.38 blue:.61 alpha:1];CFRunLoopRunInMode(kCFRunLoopDefaultMode,.02,NO);assert(colorProbe.colorPreviews>before);[well deactivate];}
        [NSColorPanel.sharedColorPanel orderOut:nil];NSDate *colorLimit=[NSDate dateWithTimeIntervalSinceNow:2];while(!colorProbe.colorCommits&&colorLimit.timeIntervalSinceNow>0)CFRunLoopRunInMode(kCFRunLoopDefaultMode,.02,YES);assert(colorProbe.colorCommits>0);assert(fabs(colorProbe.colorOptions.object.stops[0].diffuse[0]-.17)<1e-5&&fabs(colorProbe.colorOptions.lights[0].color[1]-.38)<1e-5&&fabs(colorProbe.colorOptions.ambient.colors[0][2]-.61)<1e-5);
        assert(colorProbe.randomAmountSliders.count==2);for(NSView *control in colorProbe.colorWindow.contentView.subviews)if([control isKindOfClass:NSButton.class])assert(![[(NSButton*)control title] isEqual:@"Auto update image"]);
        for(int i=0;i<2;i++){NSSlider *slider=colorProbe.randomAmountSliders[i];assert(slider.minValue==0&&slider.maxValue==3);slider.doubleValue=1.75+i*.5;[colorProbe randomAmountChanged:slider];assert(colorProbe.randomAmounts[i].doubleValue==1.75+i*.5);colorProbe.randomAmounts[i].stringValue=@"0.375";[colorProbe randomAmountEdited:colorProbe.randomAmounts[i]];assert(slider.doubleValue==.375);}
        colorProbe.diffuseWells[0].color=[NSColor colorWithSRGBRed:.2 green:.3 blue:.4 alpha:.25];colorProbe.specularWells[0].color=[NSColor colorWithSRGBRed:.6 green:.7 blue:.8 alpha:.65];RenderOptions opacityOptions=colorProbe.formulaSettings;assert([colorProbe readReflections:&opacityOptions]);assert(opacityOptions.reflections.opacity_set&&opacityOptions.reflections.opacity[0][0]==1&&fabs(opacityOptions.reflections.opacity[1][0]-.65)<1e-6);colorProbe.formulaSettings=opacityOptions;[colorProbe populateObjectLighting];assert(colorProbe.diffuseWells[0].color.alphaComponent==1&&fabs(colorProbe.specularWells[0].color.alphaComponent-.65)<1e-6);
        int colorCommitCount=colorProbe.colorCommits;[colorProbe paletteEdited:colorProbe.colorPosition];assert(colorProbe.colorCommits==colorCommitCount+1);
        NSButton *randomButton=[NSButton new];randomButton.tag=0;[colorProbe randomizeColors:randomButton];assert(colorProbe.colorCommits==colorCommitCount+2);
        [NSObject cancelPreviousPerformRequestsWithTarget:colorProbe];puts("Formula arrows preserve pending edits and bounds; actual shared-picker changes preview and commit palette, light and ambient colors with automatic color updates permanently enabled.");
        assert(((NumericInputFormatter*)precision.calculationFields[3].formatter).integerOnly&&((NumericInputFormatter*)formulaUI.formulaCountFields[0].formatter).integerOnly&&((NumericInputFormatter*)randNavigator.navigatorIterationField.formatter).integerOnly);
        formulaSelectKind(formulaUI.formulaMenus[0],104);[formulaUI formulaSelectionChanged:formulaUI.formulaMenus[0]];assert(((NumericInputFormatter*)formulaUI.randFormulaFields[0][7].formatter).integerOnly&&!((NumericInputFormatter*)formulaUI.randFormulaFields[0][0].formatter).integerOnly);
        NSWindow *numericWindow=[[NSWindow alloc]initWithContentRect:NSMakeRect(0,0,220,90) styleMask:NSWindowStyleMaskTitled backing:NSBackingStoreBuffered defer:NO];numericWindow.releasedWhenClosed=NO;NumericTextField *numberField=[[NumericTextField alloc]initWithFrame:NSMakeRect(12,12,180,26)];[numericWindow.contentView addSubview:numberField];numberField.stringValue=@"12";[numericWindow makeFirstResponder:numberField];NSTextView *editor=(NSTextView*)numberField.currentEditor;assert(editor);[editor insertText:@"x" replacementRange:NSMakeRange(2,0)];assert([editor.string isEqual:@"12"]);[editor insertText:@".5" replacementRange:NSMakeRange(2,0)];assert([editor.string isEqual:@"12.5"]);[numericWindow makeFirstResponder:nil];assert(numberField.doubleValue==12.5);
        numericIntegerField(numberField,YES);numberField.stringValue=@"12";[numericWindow makeFirstResponder:numberField];editor=(NSTextView*)numberField.currentEditor;[editor insertText:@".5" replacementRange:NSMakeRange(2,0)];assert([editor.string isEqual:@"12"]);[editor insertText:@"3" replacementRange:NSMakeRange(2,0)];assert([editor.string isEqual:@"123"]);[numericWindow makeFirstResponder:nil];assert(numberField.integerValue==123);[numericWindow orderOut:nil];
        puts("Numeric formatters reject invalid typing/paste and decimal iteration counts, allow partial edits and animation last, and expand exponent displays without losing precision.");
        FormulaDragProbe *dragProbe=[FormulaDragProbe new];NSWindow *dragWindow=[[NSWindow alloc]initWithContentRect:NSMakeRect(0,0,720,300) styleMask:NSWindowStyleMaskTitled backing:NSBackingStoreBuffered defer:NO];dragWindow.releasedWhenClosed=NO;NSTabView *dragTabs=[[NSTabView alloc]initWithFrame:NSMakeRect(0,0,700,260)];[dragWindow.contentView addSubview:dragTabs];[dragProbe addNavigatorFormulaTab:dragTabs];RenderOptions dragOptions=randSettings;dragOptions.program=defaultFormulaProgram();dragOptions.program.slots[0]=formula_slot_default(104);dragOptions.program.slots[0].count=1;dragProbe.navigatorFormulaSettings=dragOptions;[dragProbe populateNavigatorFormulaValues];
        LiveSlider *dragSlider=(LiveSlider*)dragProbe.navigatorFormulaSliders[1];double dragLow=dragSlider.minValue,dragHigh=dragSlider.maxValue;assert(dragLow==-10&&dragHigh==10);
        for(int eventIndex=0;eventIndex<4;eventIndex++){NSPoint point=[dragSlider convertPoint:NSMakePoint(150+eventIndex*20,12) toView:nil];NSEvent *event=[NSEvent mouseEventWithType:eventIndex?NSEventTypeLeftMouseDragged:NSEventTypeLeftMouseDown location:point modifierFlags:0 timestamp:0 windowNumber:dragWindow.windowNumber context:nil eventNumber:eventIndex clickCount:1 pressure:1];[dragSlider updateFromEvent:event];assert(dragSlider.minValue==dragLow&&dragSlider.maxValue==dragHigh);assert(fabs(dragSlider.doubleValue-dragProbe.navigatorFormulaFields[1].doubleValue)<1e-12&&fabs(dragSlider.doubleValue-formula_slot_value(dragProbe.navigatorFormulaSettings.program.slots[0],1))<1e-12);}
        assert(dragSlider.doubleValue>3&&dragProbe.formulaPreviews==4);double beforeFine=dragSlider.doubleValue;NSPoint finePoint=[dragSlider convertPoint:NSMakePoint(220,12) toView:nil];NSEvent *fineDrag=[NSEvent mouseEventWithType:NSEventTypeLeftMouseDragged location:finePoint modifierFlags:NSEventModifierFlagShift timestamp:0 windowNumber:dragWindow.windowNumber context:nil eventNumber:5 clickCount:1 pressure:1];[dragSlider updateFromEvent:fineDrag];assert(fabs(dragSlider.doubleValue-beforeFine-10*(dragHigh-dragLow)/(dragSlider.bounds.size.width-16)*.1)<1e-12);dragSlider.trackingPosition=NO;
        dragProbe.navigatorFormulaFields[1].stringValue=@"100";[dragProbe navigatorFormulaEdited:dragProbe.navigatorFormulaFields[1]];assert(dragSlider.minValue==90&&dragSlider.maxValue==110);
        assert(dragProbe.navigatorFormulaRange.numberOfItems==4&&dragProbe.navigatorFormulaRange.indexOfSelectedItem==2);
        [dragProbe.navigatorFormulaRange selectItemAtIndex:0];[dragProbe navigatorFormulaRangeChanged:nil];assert(dragSlider.maxValue-dragSlider.minValue<.1);
        [dragProbe.navigatorFormulaRange selectItemAtIndex:3];[dragProbe navigatorFormulaRangeChanged:nil];const FormulaParameter *fullSpec=formula_parameter(104,1);assert(dragSlider.minValue==fullSpec->minimum&&dragSlider.maxValue==fullSpec->maximum);
        [dragProbe.navigatorFormulaRange selectItemAtIndex:2];[dragProbe navigatorFormulaRangeChanged:nil];
        dragProbe.formulaKnown=YES;dragProbe.formulaSettings=dragOptions;dragProbe.navigatorFormulaSettings=dragOptions;[dragProbe populateNavigatorFormulaValues];
        dragProbe.navigatorFormulaFields[1].stringValue=@"2";[dragProbe navigatorFormulaEdited:dragProbe.navigatorFormulaFields[1]];
        dragProbe.navigatorFormulaFields[2].stringValue=@"3";[dragProbe navigatorFormulaEdited:dragProbe.navigatorFormulaFields[2]];assert([dragProbe.navigatorResetTarget[@"parameter"] intValue]==2);
        [dragProbe resetNavigatorValue:nil];assert(formula_slot_value(dragProbe.navigatorFormulaSettings.program.slots[0],1)==2&&formula_slot_value(dragProbe.navigatorFormulaSettings.program.slots[0],2)==0&&!dragProbe.navigatorResetTarget);
        dragProbe.navigatorIterationField.stringValue=@"7";[dragProbe navigatorFormulaEdited:dragProbe.navigatorIterationField];assert([dragProbe.navigatorResetTarget[@"parameter"] intValue]==-1);[dragProbe resetNavigatorValue:nil];assert(dragProbe.navigatorFormulaSettings.program.slots[0].count==1&&formula_slot_value(dragProbe.navigatorFormulaSettings.program.slots[0],1)==2);
        puts("Navigator Reset Value restores only the last changed parameter or iteration count from Main, preserving other edits.");
        dragOptions.program.slots[0]=formula_slot_default(102);dragOptions.program.slots[0].count=1;dragProbe.navigatorFormulaSettings=dragOptions;[dragProbe populateNavigatorFormulaValues];NSSlider *integerSlider=dragProbe.navigatorFormulaSliders[12];integerSlider.doubleValue=3.7;[dragProbe navigatorFormulaSlider:integerSlider];assert(integerSlider.doubleValue==4&&dragProbe.navigatorFormulaFields[12].intValue==4);[dragWindow orderOut:nil];
        puts("Broad-range Navigator slider thumbs advance with values and previews, preserve fixed drag ranges and Shift-fine movement, fit typed values and snap integers.");
        ObjectLighting palette={0};
        for(int i=0;i<10;i++)palette.stops[i].position=(unsigned)(i*32767/9);
        palette.stops[0].diffuse[0]=1;palette.stops[1].diffuse[2]=1;
        palette.stops[0].specular[1]=1;
        NSColor *mid=paletteColor(palette,palette.stops[1].position/2.,NO);
        assert(fabs(mid.redComponent-.5)<1e-6&&fabs(mid.blueComponent-.5)<1e-6);
        palette.no_interpolation=1;
        NSColor *stepped=paletteColor(palette,palette.stops[1].position,NO);
        assert(stepped.redComponent>.99&&stepped.blueComponent<.01);
        NSColor *spec=paletteColor(palette,0,YES);assert(spec.greenComponent>.99);
        palette.stops[9].diffuse[1]=1;
        NSColor *last=paletteColor(palette,32767,NO);assert(last.greenComponent>.99);
        puts("Palette preview interpolation, stepped boundaries and diffuse/specular separation passed.");
        puts("Oversized panel redraw preserves neighboring image pixels.");
    }
}
