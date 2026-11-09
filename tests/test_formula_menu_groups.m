#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
int main(){@autoreleasepool{
 [NSApplication sharedApplication];NSPopUpButton *button=[[NSPopUpButton alloc]initWithFrame:NSZeroRect pullsDown:YES];[button addItemWithTitle:@"Current"];
 NSMutableSet *seen=[NSMutableSet new];int total=0;
 for(int category=0;category<7;category++){
  NSMutableArray *leaves=[NSMutableArray new];for(int index=0;index<formula_menu_count();index++){int kind=formulaKindForMenu(index);if(formulaCategory(kind)!=category)continue;NSMenuItem *item=[[NSMenuItem alloc]initWithTitle:[NSString stringWithUTF8String:formula_name(kind)] action:@selector(formulaMenuChosen:) keyEquivalent:@""];item.tag=kind;item.representedObject=@3;[leaves addObject:item];}
  NSInteger start=button.menu.numberOfItems;addFormulaMenuGroups(button.menu,leaves,category,@"Category",@"Hint");NSInteger parts=(category==0||category==4)?3:category==5?2:1;assert(button.menu.numberOfItems-start==parts);
  NSUInteger min=NSUIntegerMax,max=0;NSString *previous=nil;
  for(NSInteger part=0;part<parts;part++){NSMenuItem *group=[button itemAtIndex:start+part];assert(group.tag==category);NSMenu *submenu=group.submenu;min=MIN(min,submenu.numberOfItems);max=MAX(max,submenu.numberOfItems);
   for(NSMenuItem *item in submenu.itemArray){assert(![seen containsObject:@(item.tag)]);[seen addObject:@(item.tag)];assert(item.representedObject==@3&&item.action==@selector(formulaMenuChosen:));assert(!previous||[previous localizedStandardCompare:item.title]!=NSOrderedDescending);previous=item.title;total++;}
  }assert(max-min<=1);
 }
 assert(button.numberOfItems==13&&total==formula_menu_count());
 for(NSNumber *kind in seen){formulaSelectKind(button,kind.intValue);int checked=0,bold=0;for(NSMenuItem *group in button.itemArray)if(group.submenu){bold+=group.attributedTitle!=nil;for(NSMenuItem *leaf in group.submenu.itemArray)if(leaf.state==NSControlStateValueOn){assert(leaf.tag==kind.intValue);checked++;}}assert(checked==1&&bold==1);}
 printf("PASS: all %d formulas retained exactly once, balanced 3/3/2 splits, alphabetical order, selection checkmark and category highlighting\n",total);
}return 0;}
