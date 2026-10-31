#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
@interface RangeProbe : AppDelegate
@property(nonatomic) int previews;
@end
@implementation RangeProbe
- (void)requestNavigatorPreview {self.previews++;}
@end
int main(void){@autoreleasepool{
 [NSApplication sharedApplication];RangeProbe *app=[RangeProbe new];NSTabView *tabs=[[NSTabView alloc]initWithFrame:NSMakeRect(0,0,700,260)];[app addNavigatorFormulaTab:tabs];RenderOptions o={0};o.program.slots[0]=formula_slot_default(104);o.program.slots[0].count=1;app.navigatorFormulaSettings=o;[app populateNavigatorFormulaValues];assert(app.navigatorFormulaRange.numberOfItems==6&&[app.navigatorFormulaRange itemAtIndex:4].separatorItem&&[app.navigatorFormulaRange.lastItem.title isEqual:@"Center the slider"]);
 for(int range=0;range<4;range++){
  [app.navigatorFormulaRange selectItemAtIndex:range];[app navigatorFormulaRangeChanged:nil];double low=app.navigatorFormulaSliders[0].minValue;
  app.navigatorFormulaFields[0].doubleValue=3.25;[app.navigatorFormulaRange selectItemAtIndex:5];[app navigatorFormulaRangeChanged:app.navigatorFormulaRange];assert(app.navigatorFormulaRange.indexOfSelectedItem==range);assert(app.navigatorFormulaFields[0].doubleValue==3.25&&app.navigatorFormulaSliders[0].doubleValue==3.25);if(range<3)assert(fabs((app.navigatorFormulaSliders[0].minValue+app.navigatorFormulaSliders[0].maxValue)/2-3.25)<1e-12);else assert(app.navigatorFormulaSliders[0].minValue==low);assert(app.previews==0);
 }
 puts("Center the slider reapplies each range and preserves selection/value without rendering");
 }return 0;}
