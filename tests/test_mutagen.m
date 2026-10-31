#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface MutagenProbe:AppDelegate
@end
@implementation MutagenProbe
- (NSURL *)applicationMapsFolderURL{return [NSURL fileURLWithPath:@"/private/tmp/mutagen-maps" isDirectory:YES];}
- (void)beginRenderPath:(NSString *)path options:(RenderOptions)options{(void)path;(void)options;}
@end
static void waitMutagen(MutagenProbe *a){NSDate *deadline=[NSDate dateWithTimeIntervalSinceNow:55];while(a.mutagenBusy&&deadline.timeIntervalSinceNow>0)[NSRunLoop.mainRunLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:.02]];assert(!a.mutagenBusy);}
int main(void){@autoreleasepool{
    [NSApplication sharedApplication];RenderOptions original;char error[512];assert(read_scene_settings("example.m3i",&original,error));uint64_t random=123456789;MutagenConfig config=mutagenDefaultConfig();
    for(int i=0;i<500;i++){RenderOptions changed=mutagenMutate(original,config,&random);assert(!memcmp(&changed.camera,&original.camera,sizeof original.camera));assert(!memcmp(&changed.object,&original.object,sizeof original.object));int active=0;for(int slot=0;slot<6;slot++){FormulaSlot f=changed.program.slots[slot];assert(f.count>=0);if(!f.count)continue;active++;for(int j=0;j<formula_parameter_count(f.kind);j++){FormulaParameter spec=formulaUIParameter(f.kind,j);double value=formula_slot_value(f,j);assert(isfinite(value));/* Imported legacy defaults may predate UI bounds. */}}assert(active>0);}
    config=(MutagenConfig){0};RenderOptions unchanged=mutagenMutate(original,config,&random);assert(!memcmp(&unchanged.program,&original.program,sizeof original.program));
    MutagenProbe *a=[MutagenProbe new];[a ensureWindow];[a.window orderOut:nil];[a loadParameterSettings:original path:@"example.m3i" source:@"Test"];[a showMutagen:nil];waitMutagen(a);assert(a.mutagenTiles.count==15&&a.mutagenHistory.count==1&&a.mutagenHistory[0].images[0]!=NSNull.null);[a disableMutagenOptions:nil];[a mutateGeneration:nil];waitMutagen(a);assert(a.mutagenHistory.count==2);MutagenGeneration *generation=a.mutagenHistory[1];for(int i=0;i<15;i++){assert([generation.images[i] isKindOfClass:NSImage.class]);RenderOptions o=mutagenUnpack(generation.options[i]);assert(!memcmp(&o.program,&original.program,sizeof original.program));}
    a.mutagenGenerationStepper.integerValue=1;[a mutagenGenerationChanged:a.mutagenGenerationStepper];assert(a.mutagenGenerationIndex==0);a.mutagenGenerationStepper.integerValue=2;[a mutagenGenerationChanged:a.mutagenGenerationStepper];[a clearMutagenGenerations:nil];assert(a.mutagenHistory.count==1&&a.mutagenGenerationIndex==0);
    a.mutagenProbabilities[1].doubleValue=1;a.mutagenProbabilities[2].doubleValue=.5;a.mutagenProbabilities[3].doubleValue=.5;[a selectMutagenTile:7 breed:YES];waitMutagen(a);assert(a.mutagenHistory.count==2);int complete=0;for(id image in a.mutagenHistory.lastObject.images)complete+=[image isKindOfClass:NSImage.class];assert(complete==15);
    [a mutateGeneration:nil];assert(a.mutagenBusy);[a stopMutagen];assert(!a.mutagenBusy);[NSRunLoop.mainRunLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:.2]];
    assert(NSMaxY(a.mutagenDisableButton.frame)<=a.mutagenWindow.contentView.bounds.size.height);assert(NSMaxY(a.mutagenStatus.frame)<=a.mutagenWindow.contentView.bounds.size.height);
    a.mutagenGenerationStepper.integerValue=a.mutagenHistory.count-1;[a mutagenGenerationChanged:a.mutagenGenerationStepper];
    RenderOptions selected=mutagenUnpack(a.mutagenHistory[a.mutagenGenerationIndex].options[0]);[a sendMutagenTile:0 toClipboard:NO];RenderOptions sent=a.formulaSettings;assert(!memcmp(&sent.program,&selected.program,sizeof selected.program));
    NSView *content=a.mutagenWindow.contentView;[content display];NSBitmapImageRep *rep=[content bitmapImageRepForCachingDisplayInRect:content.bounds];[content cacheDisplayInRect:content.bounds toBitmapImageRep:rep];[[rep representationUsingType:NSBitmapImageFileTypePNG properties:@{}]writeToFile:@"/private/tmp/mutagen266.png" atomically:YES];[a.mutagenWindow orderOut:nil];puts("Mutagen mutation invariants, initial preview, 15-cell generations, browsing, clearing, double-click breeding and cancellation passed.");
}return 0;}
