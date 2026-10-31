#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
int main(void){@autoreleasepool{
 [NSApplication sharedApplication];AppDelegate *a=[AppDelegate new];[a ensureWindow];[a.window orderOut:nil];RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));a.formulaSettings=o;a.formulaKnown=YES;
 [a showFormulas:nil];[a.formulasWindow orderOut:nil];assert(a.formulaTabs.numberOfTabViewItems==6);assert(a.formulaMenus.count==6);NSTabView *tabs=[[NSTabView alloc]initWithFrame:NSMakeRect(0,0,700,230)];[a addNavigatorFormulaTab:tabs];assert(a.navigatorFormulaMenu.numberOfItems==6);
 o.program.slots[6].count=o.program.slots[7].count=1;o.retired_indirect_enabled=1;o.retired_indirect_strength=2;RenderOptions clean=animationUnpack([NSData dataWithBytes:&o length:sizeof o]);assert(!clean.program.slots[6].count&&!clean.program.slots[7].count&&!clean.retired_indirect_enabled&&clean.retired_indirect_strength==0);
 puts("Both formula menus expose six slots; old animation snapshots discard retired settings.");
 }return 0;}
