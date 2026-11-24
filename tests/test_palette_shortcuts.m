#define main app_entry_unused
#import "../App.m"
#undef main
#include <assert.h>
// Isolate shortcut routing from the system pasteboard service in UI tests.
@interface MemoryPalettePasteboard:NSObject
@property(nonatomic,strong) NSMutableDictionary *values;
@end
@implementation MemoryPalettePasteboard
- (NSInteger)declareTypes:(NSArray *)types owner:(id)owner{(void)types;(void)owner;self.values=[NSMutableDictionary new];return 1;}
- (BOOL)setPropertyList:(id)value forType:(NSString *)type{self.values[type]=value;return YES;}
- (id)propertyListForType:(NSString *)type{return self.values[type];}
@end
@interface ShortcutProbe:AppDelegate
@end
@implementation ShortcutProbe
- (void)paletteEdited:(id)sender {(void)sender;}
- (void)finishLightingSlider {}
@end
static NSEvent *shortcut(NSWindow *window,NSString *key){return [NSEvent keyEventWithType:NSEventTypeKeyDown location:NSZeroPoint modifierFlags:NSEventModifierFlagCommand timestamp:0 windowNumber:window.windowNumber context:nil characters:key charactersIgnoringModifiers:key isARepeat:NO keyCode:0];}
static BOOL sameColor(NSColor *a,NSColor *b){a=[a colorUsingColorSpace:NSColorSpace.sRGBColorSpace];b=[b colorUsingColorSpace:NSColorSpace.sRGBColorSpace];return fabs(a.redComponent-b.redComponent)<1e-6&&fabs(a.greenComponent-b.greenComponent)<1e-6&&fabs(a.blueComponent-b.blueComponent)<1e-6&&fabs(a.alphaComponent-b.alphaComponent)<1e-6;}
int main(){@autoreleasepool{
 [NSApplication sharedApplication];ShortcutProbe *a=[ShortcutProbe new];[a ensureWindow];[a.window orderOut:nil];
 RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));a.formulaKnown=YES;a.formulaSettings=o;
 [a showLighting:nil];[a showColorAdjustment:nil];[a.lightingWindow orderOut:nil];a.palettePasteboard=(NSPasteboard *)(id)[MemoryPalettePasteboard new];
 NSColor *diffuse=[NSColor colorWithSRGBRed:.2 green:.3 blue:.4 alpha:.6],*specular=[NSColor colorWithSRGBRed:.7 green:.8 blue:.9 alpha:.3];
 a.diffuseWells[1].color=diffuse;a.specularWells[1].color=specular;a.colorDiffuseBar.clicked(1,NO);
 NSColorPanel *picker=NSColorPanel.sharedColorPanel;
 assert([a handleColorStopKeyEvent:shortcut(picker,@"c") window:picker]);
 a.colorSpecularBar.clicked(2,NO);
 assert([a handleColorStopKeyEvent:shortcut(picker,@"v") window:picker]);
 assert(sameColor(a.diffuseWells[2].color,diffuse)&&sameColor(a.specularWells[2].color,specular));
 a.diffuseWells[2].color=NSColor.redColor;a.specularWells[2].color=NSColor.greenColor;
 assert([a handleColorStopKeyEvent:shortcut(picker,@"g") window:picker]);
 assert(sameColor(a.diffuseWells[2].color,diffuse)&&sameColor(a.specularWells[2].color,NSColor.greenColor));
 assert([a handleColorStopKeyEvent:shortcut(picker,@"b") window:picker]);assert(sameColor(a.specularWells[2].color,specular));
 [a.colorWindow makeFirstResponder:a.colorDiffuseBar];assert([a handleColorStopKeyEvent:shortcut(a.colorWindow,@"c") window:a.colorWindow]);
 assert(![a handleColorStopKeyEvent:shortcut(a.window,@"v") window:a.window]);
 [a.colorPosition selectText:nil];
 assert([a.colorWindow.firstResponder isKindOfClass:NSTextView.class]&&[(NSTextView *)a.colorWindow.firstResponder isFieldEditor]);
 assert(![a handleColorStopKeyEvent:shortcut(a.colorWindow,@"c") window:a.colorWindow]);assert(![a handleColorStopKeyEvent:shortcut(a.colorWindow,@"v") window:a.colorWindow]);
 [a.colorWindow orderOut:nil];assert(![a handleColorStopKeyEvent:shortcut(picker,@"g") window:picker]);
 [picker orderOut:nil];
 puts("Palette shortcuts work from the picker and adjustment window, preserve alpha and channel-specific paste, and leave text editing/other windows alone.");
}return 0;}
