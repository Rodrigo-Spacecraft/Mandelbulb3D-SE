#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
int main(void){@autoreleasepool{[NSApplication sharedApplication];double stored=(double)(float).2;
 NumericTextField *field=[[NumericTextField alloc]initWithFrame:NSMakeRect(0,0,160,24)];field.stringValue=[NSString stringWithFormat:@"%.17g",stored];assert([field.stringValue isEqual:@"0.2"]&&field.doubleValue==stored);assert(numericInputString(field).doubleValue==stored);
 NSScanner *scan=[NSScanner scannerWithString:numericInputString(field)];double parsed;assert([scan scanDouble:&parsed]&&parsed==stored);
 field.stringValue=@"0.25";assert(field.doubleValue==.25);field.integerValue=3;assert(field.doubleValue==3);field.intValue=4;assert(field.doubleValue==4);
 field.stringValue=[NSString stringWithFormat:@"%.17g",stored];[field.cell setObjectValue:@"0.25"];[field textDidChange:[NSNotification notificationWithName:NSTextDidChangeNotification object:[NSTextView new]]];assert(field.doubleValue==.25);
 double precise=.12345678901234567;field.doubleValue=precise;assert(field.doubleValue==precise&&field.stringValue.doubleValue==precise);
 float adjacent=nextafterf(.2f,0.f);assert(![numericDisplayString([NSString stringWithFormat:@"%.17g",(double)adjacent]) isEqual:@"0.2"]);
 for(uint32_t bits=1;bits<UINT32_MAX-100000000;bits+=12345679){float f;memcpy(&f,&bits,4);if(!isfinite(f))continue;NSString *shown=numericDisplayString([NSString stringWithFormat:@"%.17g",(double)f]);assert((float)shown.doubleValue==f&&[shown rangeOfString:@"e" options:NSCaseInsensitiveSearch].location==NSNotFound);}
 AppDelegate *app=[AppDelegate new];[app ensureWindow];[app.window orderOut:nil];RenderOptions o;char error[512];assert(read_scene_settings("example.m3i",&o,error));o.program_override=1;o.program.slots[0]=formula_slot_default(125);o.program.slots[0].count=1;formula_slot_set_value(&o.program.slots[0],0,stored);formula_slot_set_value(&o.program.slots[0],1,precise);app.formulaKnown=YES;app.formulaSettings=o;[app showFormulas:nil];[app.formulasWindow orderOut:nil];assert([app.randFormulaFields[0][0].stringValue isEqual:@"0.2"]);RenderOptions read=o;assert([app readFormulaWindow:&read]);assert(formula_slot_value(read.program.slots[0],0)==stored&&formula_slot_value(read.program.slots[0],1)==precise);
 puts("Shortest float/double displays round-trip, adjacent values stay distinct, and unedited formula fields retain imported precision.");}return 0;}
