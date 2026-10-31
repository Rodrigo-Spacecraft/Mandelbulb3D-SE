#define main app_entry_not_used
#import "App.m"
#undef main
#include <assert.h>
#include <sys/xattr.h>
/* Keep tests independent of the OS pasteboard daemon and user's clipboard. */
@interface PaletteTestPasteboard : NSObject
@property(nonatomic,strong) NSMutableDictionary *values;
@end
@implementation PaletteTestPasteboard
- (NSInteger)clearContents{self.values=[NSMutableDictionary dictionary];return 1;}
- (NSInteger)declareTypes:(NSArray *)types owner:(id)owner{(void)types;(void)owner;return [self clearContents];}
- (BOOL)setPropertyList:(id)value forType:(NSString *)type{self.values[type]=value;return YES;}
- (id)propertyListForType:(NSString *)type{return self.values[type];}
- (void)releaseGlobally{}
@end
@interface RustPanelProbe : AppDelegate
@property(nonatomic) NSInteger colorEdits;
@end
@implementation RustPanelProbe
- (void)requestNavigatorPreview {}
- (void)paletteEdited:(id)sender {(void)sender;self.colorEdits++;}
@end
int main(void){@autoreleasepool{
[NSApplication sharedApplication];RustPanelProbe *app=[RustPanelProbe new];NSString *historyDirectory=[NSTemporaryDirectory() stringByAppendingPathComponent:[@"mb3dr-history-test-" stringByAppendingString:NSUUID.UUID.UUIDString]];app.renderHistory=[[RenderHistoryStore alloc]initWithDirectory:historyDirectory];[app ensureWindow];[app.window orderOut:nil];assert([app.window.title isEqual:@"Mandelbulb3Dr"]);
NSUInteger sizeGeneration=app.generation;app.imageSizeStepper.integerValue=1;[app stepImageSize:app.imageSizeStepper];assert(app.calculationFields[0].intValue==960&&app.calculationFields[1].intValue==720&&app.calculationFields[4].doubleValue==1&&app.imageSizeStepper.integerValue==0&&app.generation==sizeGeneration);
app.keepAspectCheck.state=NSControlStateValueOff;app.imageSizeStepper.integerValue=-1;[app stepImageSize:app.imageSizeStepper];assert(app.calculationFields[0].intValue==480&&app.calculationFields[1].intValue==360&&app.calculationFields[4].doubleValue==.5);
app.scaleDECheck.state=NSControlStateValueOff;app.imageSizeStepper.integerValue=1;[app stepImageSize:app.imageSizeStepper];assert(app.calculationFields[0].intValue==960&&app.calculationFields[1].intValue==720&&app.calculationFields[4].doubleValue==.5);
[app.oversamplingMenu selectItemAtIndex:5];app.calculationFields[0].intValue=2000;app.calculationFields[1].intValue=1500;app.imageSizeStepper.integerValue=1;[app stepImageSize:app.imageSizeStepper];assert(app.calculationFields[0].intValue==2000&&app.calculationFields[1].intValue==1500);
app.calculationFields[0].intValue=16;app.calculationFields[1].intValue=16;app.imageSizeStepper.integerValue=-1;[app stepImageSize:app.imageSizeStepper];assert(app.calculationFields[0].intValue==16&&app.calculationFields[1].intValue==16);
app.calculationFields[0].intValue=480;app.calculationFields[1].intValue=360;app.lastEditWidth=480;app.sizeAspect=4./3;app.keepAspectCheck.state=app.scaleDECheck.state=NSControlStateValueOn;[app.oversamplingMenu selectItemAtIndex:0];[app updateRenderSizeLabel];
assert(!app.displayActualSizeButton.enabled);setenv("MB3D_GPU","0",1);
RenderOptions displayOptions={.width=32,.height=24,.threads=2,.iterations=8};
[app beginRenderPath:nil options:displayOptions];assert(app.renderButton.hidden&&!app.stopButton.hidden&&app.stopButton.enabled&&NSEqualRects(app.renderButton.frame,app.stopButton.frame));NSDate *displayLimit=[NSDate dateWithTimeIntervalSinceNow:10];while(app.calculating&&displayLimit.timeIntervalSinceNow>0)CFRunLoopRunInMode(kCFRunLoopDefaultMode,.01,YES);
assert(!app.renderButton.hidden&&app.stopButton.hidden);assert(!app.calculating&&app.completedRender&&app.displayActualSizeButton.enabled&&app.completedOutputWidth==32&&app.completedOutputHeight==24);
[app showLighting:nil];[app.lightingWindow orderOut:nil];
RenderOptions mapOriginal=app.formulaSettings;RenderOptions withMap=mapOriginal;withMap.lights[5].option=2;app.formulaSettings=withMap;[app populateLights];for(NSControl *control in app.lightControls[5])assert(!control.enabled);RenderOptions mapRead=withMap;assert([app readLights:&mapRead]&&mapRead.lights[5].option==2);app.formulaSettings=mapOriginal;[app populateLights];[app setCalculating:NO];
BOOL previousFit=app.colorFitValid;assert(previousFit&&app.fitColorsButton.enabled);NSUInteger fitGeneration=app.generation;app.orbitCheck.state=NSControlStateValueOff;[app fitColors:app.fitColorsButton];assert(app.generation==fitGeneration&&app.objectFields[2].intValue!=app.objectFields[3].intValue);app.orbitCheck.state=NSControlStateValueOn;[app fitColors:app.fitColorsButton];assert(app.generation==fitGeneration);app.colorFitValid=NO;[app populateObjectLighting];assert(!app.fitColorsButton.enabled);app.colorFitValid=previousFit;[app populateObjectLighting];assert(app.fitColorsButton.enabled);
app.imageSizeStepper.integerValue=1;[app stepImageSize:app.imageSizeStepper];assert(!app.displayActualSizeButton.enabled);
app.calculationFields[0].intValue=32;app.calculationFields[1].intValue=24;[app updateRenderSizeLabel];assert(!app.displayActualSizeButton.enabled);
[app beginRenderPath:nil options:displayOptions];displayLimit=[NSDate dateWithTimeIntervalSinceNow:10];while(app.calculating&&displayLimit.timeIntervalSinceNow>0)CFRunLoopRunInMode(kCFRunLoopDefaultMode,.01,YES);
assert(!app.calculating&&app.displayActualSizeButton.enabled);
assert([app.renderHistory entries].count==2&&NSMinX(app.historyMenu.frame)>NSMaxX(app.renderButton.frame));
[app menuNeedsUpdate:app.historyMenu.menu];assert(app.historyMenu.numberOfItems==3&&[app.historyMenu itemAtIndex:1].image);
NSArray *savedHistory=[app.renderHistory entries];NSBitmapImageRep *savedBitmap=historyBitmap(savedHistory[0][@"path"],0);assert(savedBitmap.pixelsWide==32&&savedBitmap.pixelsHigh==24&&!memcmp(savedBitmap.bitmapData,app.completedRender.bitmapData,32*24*4));
[app restoreHistory:[app.historyMenu itemAtIndex:1]];displayLimit=[NSDate dateWithTimeIntervalSinceNow:10];while(app.calculating&&displayLimit.timeIntervalSinceNow>0)CFRunLoopRunInMode(kCFRunLoopDefaultMode,.01,YES);
assert(!app.calculating&&app.parametersPendingRender&&[app.renderHistory entries].count==2&&app.completedRender.pixelsWide==32&&!memcmp(savedBitmap.bitmapData,app.completedRender.bitmapData,32*24*4));
NSString *workingHistory=app.currentPath;assert([workingHistory.lastPathComponent isEqual:@".selected.m3i"]);
RenderResult historyFixture={.rgba=app.completedRender.bitmapData,.width=32,.height=24,.stride=app.completedRender.bytesPerRow,.settings=app.formulaSettings};NSString *historyError=nil,*latestHistory=nil;
for(int i=0;i<22;i++){latestHistory=[app.renderHistory record:historyFixture source:workingHistory error:&historyError];assert(latestHistory&&!historyError);usleep(2000);}
assert([app.renderHistory entries].count==20&&[NSFileManager.defaultManager fileExistsAtPath:workingHistory]);
assert(![NSFileManager.defaultManager fileExistsAtPath:savedHistory[0][@"path"]]);
/* A new store represents relaunch after a crash: initialization retains files. */
app.renderHistory=[[RenderHistoryStore alloc]initWithDirectory:historyDirectory];assert([app.renderHistory entries].count==20);[app menuNeedsUpdate:app.historyMenu.menu];assert(app.historyMenu.numberOfItems==21&&[[app.historyMenu itemAtIndex:1].representedObject isEqual:latestHistory]);
for(NSMenuItem *entry in app.historyMenu.itemArray){if(entry.action==@selector(restoreHistory:))assert(entry.image&&entry.title.length&&entry.image.size.width<=80&&entry.image.size.height<=80);}
RenderOptions historySettings;char historyReadError[512];assert(read_scene_settings(workingHistory.fileSystemRepresentation,&historySettings,historyReadError)&&historySettings.width==32);

app.calculationFields[0].stringValue=@"64";[app updateSizeFromField:app.calculationFields[0]];assert(!app.displayActualSizeButton.enabled);
assert(app.positionFields.count==6);assert(animationOptionsSize(offsetof(RenderOptions,position)));
RenderOptions positionRead=app.formulaSettings;assert([app readPosition:&positionRead]);CameraSettings originalCamera=positionRead.camera;
app.positionFields[0].doubleValue+=.25;assert([app readPosition:&positionRead]);assert(positionRead.camera_override&&fabs(positionRead.camera.origin[0]-originalCamera.origin[0]-.25)<1e-10);assert(fabs(positionRead.camera.distance-originalCamera.distance)<1e-10);
app.positionFields[4].stringValue=app.positionFields[3].stringValue;assert(![app readPosition:&positionRead]);[app populatePosition];
app.calculationFields[3].stringValue=@"7";assert([app readMainSettings:&positionRead sender:app.renderButton]);assert(positionRead.normal_smoothing==7&&positionRead.iterations==app.formulaSettings.iterations);
app.calculationFields[3].stringValue=@"16";assert(![app readMainSettings:&positionRead sender:app.renderButton]);app.calculationFields[3].stringValue=@"0";
RenderOptions settings={0};char error[512];assert(read_scene_settings("example.m3i",&settings,error));app.formulaKnown=YES;app.formulaSettings=settings;[app showFormulas:nil];[app.formulasWindow orderOut:nil];assert(app.formulaMenus.count==6&&app.formulaCountFields.count==6);[app populateFormulaWindow];RenderOptions read=settings;assert([app readFormulaWindow:&read]);
FormulaSearchController *search=[FormulaSearchController new];assert(search.matches.count==472);search.query.stringValue=@"aMaZiNg";[search controlTextDidChange:[NSNotification notificationWithName:NSControlTextDidChangeNotification object:search.query]];assert(search.matches.count>1&&search.matches.count<472);for(NSNumber *kind in search.matches)assert([[NSString stringWithUTF8String:formula_name(kind.intValue)].lowercaseString containsString:@"amazing"]);
__block int searchChoice=-1;search.choose=^(int kind){searchChoice=kind;};[search.table selectRowIndexes:[NSIndexSet indexSetWithIndex:0]byExtendingSelection:NO];[search selectFormula:search.table];assert(searchChoice==search.matches[0].intValue);search.query.stringValue=@"no-such-formula-128733";[search filter];assert(search.matches.count==0);searchChoice=-1;[search selectFormula:nil];assert(searchChoice==-1);search.query.stringValue=@"JosKn-KleinIFS";[search filter];assert(search.matches.count==1&&strcmp(formula_name(search.matches[0].intValue),"JosKn-KleinIFS")==0);search.query.stringValue=@"";[search filter];assert(search.matches.count==472);
NSPopUpButton *picker=app.formulaMenus[0];NSMutableSet *seen=[NSMutableSet set];assert(picker.itemArray.count==9);assert([picker.itemArray[1].title isEqual:@"Search…"]);
for(NSMenuItem *group in picker.itemArray){if(!group.hasSubmenu)continue;for(NSMenuItem *leaf in group.submenu.itemArray){assert(![seen containsObject:@(leaf.tag)]);[seen addObject:@(leaf.tag)];assert(formulaCategory((int)leaf.tag)==(NSInteger)[picker.itemArray indexOfObject:group]-2);}}
assert(seen.count==472);
for(int n=0;n<formula_menu_count();n++){
 int kind=formula_menu_kind(n);formulaSelectKind(picker,kind);[app formulaSelectionChanged:picker];RenderOptions values=settings;assert([app readFormulaWindow:&values]);assert(values.program.slots[0].kind==kind);FormulaSlot defaults=formula_slot_default(kind);
 for(int j=0;j<formula_parameter_count(kind);j++){double expected=formula_slot_value(defaults,j),actual=formula_slot_value(values.program.slots[0],j);assert(fabs(actual-expected)<=1e-10*fmax(1,fabs(expected)));}
 int selected=0,bold=0;for(NSMenuItem *group in picker.itemArray){if(!group.hasSubmenu)continue;bold+=group.attributedTitle!=nil;for(NSMenuItem *leaf in group.submenu.itemArray){selected+=leaf.state==NSControlStateValueOn;assert(leaf.attributedTitle==nil);}}
 assert(selected==1&&bold==1);
}
app.formulaSettings=settings;[app populateFormulaWindow];
[app showLighting:nil];[app.lightingWindow orderOut:nil];[app showColorAdjustment:nil];[app.colorWindow orderOut:nil];
NSString *oldPaletteEnd=app.palettePositions[9].stringValue;ObjectLighting extendedPalette=app.formulaSettings.object;app.palettePositions[9].stringValue=@"32772";assert([app readObjectLighting:&extendedPalette]&&extendedPalette.stops[9].position==32772);app.palettePositions[9].stringValue=@"65535";assert([app readObjectLighting:&extendedPalette]&&extendedPalette.stops[9].position==65535);app.palettePositions[9].stringValue=@"65536";assert(![app readObjectLighting:&extendedPalette]);app.palettePositions[9].stringValue=oldPaletteEnd;
app.palettePasteboard=(NSPasteboard *)[PaletteTestPasteboard new];[app.palettePasteboard clearContents];
PaletteView *bar=app.colorDiffuseBar;NSPoint at=[bar convertPoint:NSMakePoint(paletteMarkerInset,bar.bounds.size.height-15) toView:nil];
NSEvent *right=[NSEvent mouseEventWithType:NSEventTypeRightMouseDown location:at modifierFlags:0 timestamp:0 windowNumber:app.colorWindow.windowNumber context:nil eventNumber:1 clickCount:1 pressure:1];
NSMenu *menu=[bar menuForEvent:right];assert(menu.numberOfItems==4);NSArray *titles=@[@"Copy",@"Paste",@"Paste Diffuse",@"Paste Specular"],*keys=@[@"c",@"v",@"g",@"b"];
for(int i=0;i<4;i++){NSMenuItem *item=[menu itemAtIndex:i];assert([item.title isEqual:titles[i]]&&[item.keyEquivalent isEqual:keys[i]]&&item.keyEquivalentModifierMask==NSEventModifierFlagCommand);assert([bar validateMenuItem:item]==(i==0));}
app.diffuseWells[0].color=[NSColor colorWithSRGBRed:.2 green:.3 blue:.4 alpha:1];app.specularWells[0].color=[NSColor colorWithSRGBRed:.7 green:.2 blue:.1 alpha:.37];assert([app performColorStopCommand:0]);
app.diffuseWells[1].color=NSColor.blueColor;app.specularWells[1].color=[NSColor colorWithSRGBRed:0 green:1 blue:0 alpha:.81];[app.colorStopMenu selectItemAtIndex:1];[app refreshPaletteViews];NSString *position=app.palettePositions[1].stringValue;
for(NSString *key in @[@"g",@"b",@"v",@"c"]){
 NSEvent *event=[NSEvent keyEventWithType:NSEventTypeKeyDown location:NSZeroPoint modifierFlags:NSEventModifierFlagCommand timestamp:0 windowNumber:app.colorWindow.windowNumber context:nil characters:key charactersIgnoringModifiers:key isARepeat:NO keyCode:0];
 assert([(PaletteWindow *)app.colorWindow performKeyEquivalent:event]);
 NSColor *d=[app.diffuseWells[1].color colorUsingColorSpace:NSColorSpace.sRGBColorSpace],*sp=[app.specularWells[1].color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];assert(fabs(d.redComponent-.2)<1e-8&&fabs(d.blueComponent-.4)<1e-8);assert(fabs(sp.alphaComponent-([key isEqual:@"g"]?.81:.37))<1e-8);assert([position isEqual:app.palettePositions[1].stringValue]);
}
assert(app.colorEdits==3);assert([app colorStopClipboardColors].count==2);[app.palettePasteboard setPropertyList:@"invalid" forType:@"org.codex.mandelbulb3d.palette-stop"];assert(![bar validateMenuItem:[menu itemAtIndex:1]]);[app.palettePasteboard releaseGlobally];
/* Finder preview uses the already rendered bitmap; it must be stored on the
   scene file itself rather than in a sibling preview file. */
NSBitmapImageRep *preview=[[NSBitmapImageRep alloc]initWithBitmapDataPlanes:NULL pixelsWide:32 pixelsHigh:24 bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSCalibratedRGBColorSpace bytesPerRow:128 bitsPerPixel:32];memset(preview.bitmapData,255,preview.bytesPerRow*24);
char previewPath[]="/tmp/mandelbulb3dr-finder-XXXXXX.m3i";int previewFD=mkstemps(previewPath,4);assert(previewFD>=0);close(previewFD);unlink(previewPath);assert(write_scene_parameters_with_preview(NULL,(RenderOptions){.width=32,.height=24},previewPath,preview.bitmapData,32,24,128,error));
BOOL iconOK=setSceneFinderPreview([NSString stringWithUTF8String:previewPath],preview);assert(iconOK);assert(getxattr(previewPath,"com.apple.ResourceFork",NULL,0,0,0)>0);unlink(previewPath);
[app showNavigator:nil];[app.navigatorWindow orderOut:nil];assert(app.navigatorFormulaMenu.numberOfItems==6);assert(app.fixedZoomCheck.state==NSControlStateValueOff);CameraSettings modeCamera=app.navigatorCamera;NSString *modeStep=app.moveStepField.stringValue;NSUInteger modeGeneration=app.navigatorGeneration;app.fixedZoomCheck.state=NSControlStateValueOn;[app fixedZoomChanged:nil];app.fixedZoomCheck.state=NSControlStateValueOff;[app fixedZoomChanged:nil];CameraSettings unchangedModeCamera=app.navigatorCamera;assert(!memcmp(&modeCamera,&unchangedModeCamera,sizeof modeCamera)&&[modeStep isEqual:app.moveStepField.stringValue]&&app.navigatorGeneration==modeGeneration+2&&!app.previewPending);
puts("Navigator defaults to adaptive mode; toggling fixed mode preserves zoom and step without rendering.");
NSMenuItem *map=[NSMenuItem new];NSString *thumbnailPath=[NSTemporaryDirectory() stringByAppendingPathComponent:[NSUUID.UUID.UUIDString stringByAppendingString:@".png"]];assert([[preview representationUsingType:NSBitmapImageFileTypePNG properties:@{}] writeToFile:thumbnailPath atomically:YES]);addMapMenuThumbnail(map,thumbnailPath);NSImage *pendingThumbnail=map.image;NSDate *limit=[NSDate dateWithTimeIntervalSinceNow:10];while(map.image==pendingThumbnail&&limit.timeIntervalSinceNow>0)CFRunLoopRunInMode(kCFRunLoopDefaultMode,.02,YES);assert(map.image&&map.image!=pendingThumbnail&&map.image.size.width==48&&map.image.size.height==32);NSBitmapImageRep *decoded=[NSBitmapImageRep imageRepWithData:map.image.TIFFRepresentation];NSColor *middle=[[decoded colorAtX:decoded.pixelsWide/2 y:decoded.pixelsHigh/2] colorUsingColorSpace:NSColorSpace.sRGBColorSpace];assert(middle.redComponent>.9&&middle.alphaComponent>.9);[NSFileManager.defaultManager removeItemAtPath:thumbnailPath error:nil];
puts("Color-stop menu shortcuts, paired and selective paste, opacity and position preservation, and asynchronous map thumbnails pass.");

[app refreshNavigatorCameraDisplays];assert(app.navigatorCameraDisplays.count==4&&app.navigatorZoomStepper.hidden);NSArray *summary=[app.navigatorCameraDisplays valueForKey:@"stringValue"];app.fixedZoomCheck.state=NSControlStateValueOn;[app fixedZoomChanged:nil];assert(!app.navigatorZoomStepper.hidden&&[summary isEqual:[app.navigatorCameraDisplays valueForKey:@"stringValue"]]);app.fixedZoomCheck.state=NSControlStateValueOff;[app fixedZoomChanged:nil];assert(app.navigatorZoomStepper.hidden&&[summary isEqual:[app.navigatorCameraDisplays valueForKey:@"stringValue"]]);for(NSTextField *field in app.navigatorCameraDisplays)assert(!field.editable);assert(app.applyNavigatorButton.frame.origin.y==app.navigatorAddAnimationButton.frame.origin.y&&app.navigatorResetPosButton.frame.origin.y==app.navigatorResetValueButton.frame.origin.y);app.navigatorFormulaSlot=5;[app syncNavigatorFormulaArrows];assert(!app.navigatorFormulaArrows.lastObject.enabled);RenderOptions mainBeforeReset=app.formulaSettings,navBeforeReset=app.navigatorFormulaSettings;
[app resetNavigatorPosition:nil];assert(app.navigatorCamera.fov==30&&app.navigatorCamera.zoom==.8&&app.navigatorCamera.distance==32);assert(fabs(app.navigatorCamera.origin[2]+2)<1e-7);RenderOptions mainAfterReset=app.formulaSettings;assert(memcmp(&mainBeforeReset,&mainAfterReset,sizeof mainBeforeReset)==0);
RenderOptions wideReset=app.navigatorFormulaSettings;wideReset.program.bailout=501;app.navigatorFormulaSettings=wideReset;[app resetNavigatorPosition:nil];assert(app.navigatorCamera.zoom==.18&&app.navigatorCamera.distance==128&&fabs(app.navigatorCamera.origin[2]+8)<1e-7);assert(app.navigatorFormulaSettings.program.bailout==501);app.navigatorFormulaSettings=navBeforeReset;
assert(app.navigatorFormulaTypeMenu.itemArray.count==9);for(int i=0;i<6;i++)assert(([[app.navigatorFormulaMenu itemAtIndex:i].title isEqual:[NSString stringWithFormat:@"%d%@ — %s",i+1,app.navigatorFormulaSettings.program.slots[i].count>0?@"*":@"",formula_name(app.navigatorFormulaSettings.program.slots[i].kind)]]));
RenderOptions beforeType=app.navigatorFormulaSettings;FormulaSlot disabled=beforeType.program.slots[5];disabled.count=0;disabled.kind=0;beforeType.program.slots[5]=disabled;app.navigatorFormulaSettings=beforeType;[app populateNavigatorFormulaValues];assert([app.navigatorFormulaMenu.cell.title isEqual:@"6"]&&[[app.navigatorFormulaMenu itemAtIndex:5].title containsString:@"Integer Power"]);
NSMenuItem *boxChoice=nil;int formulaLeaves=0;for(NSMenuItem *group in app.navigatorFormulaTypeMenu.itemArray)for(NSMenuItem *leaf in group.submenu.itemArray){formulaLeaves++;if(leaf.tag==4)boxChoice=leaf;}assert(formulaLeaves==472&&boxChoice);[app navigatorFormulaTypeChosen:boxChoice];assert(app.navigatorFormulaSettings.program.slots[5].kind==4&&app.navigatorFormulaSettings.program.slots[5].count==1);assert([[app.navigatorFormulaMenu itemAtIndex:5].title isEqual:@"6* — Amazing Box"]);assert([app.navigatorFormulaMenu.cell.title isEqual:@"6*"]);assert(formulaSelectedKind(app.navigatorFormulaTypeMenu)==4);assert(app.navigatorFormulaLabels[0].stringValue.length>0);RenderOptions unchangedMain=app.formulaSettings;assert(memcmp(&mainBeforeReset,&unchangedMain,sizeof unchangedMain)==0);
[app showPostProcess:nil];[app.postWindow orderOut:nil];assert([app.reflectionOnlyDIFS.toolTip containsString:@"Limit transparency"]);app.reflectionFields[0].stringValue=@"4";[app reflectionEdited:app.reflectionFields[0]];RenderOptions highReflection=app.formulaSettings;assert([app readReflections:&highReflection]&&highReflection.reflections.amount==4&&app.reflectionAmountSlider.doubleValue==4&&app.reflectionAmountSlider.maxValue>=4);app.reflectionFields[0].stringValue=@"101";assert(![app readReflections:&highReflection]);
[app applicationWillTerminate:[NSNotification notificationWithName:NSApplicationWillTerminateNotification object:NSApp]];assert([NSFileManager.defaultManager fileExistsAtPath:historyDirectory]);assert(![app.renderHistory record:historyFixture source:nil error:&historyError]);RenderHistoryStore *reopened=[[RenderHistoryStore alloc]initWithDirectory:historyDirectory];assert(reopened.entries.count==20);[NSFileManager.defaultManager removeItemAtPath:historyDirectory error:nil];
puts("History retains 20 timestamped previews across relaunch, restores without rendering, protects the selected snapshot from pruning, and survives normal exit.");
puts("Mandelbulb3Dr UI has six formula tabs, six Navigator slots, bounded arrows and Rust reflection semantics.");
}return 0;}
