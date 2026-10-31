#define main app_main_unused
#import "App.m"
#undef main
#include <assert.h>
static NSTabView *findTabs(NSView *v){if([v isKindOfClass:NSTabView.class])return (NSTabView *)v;for(NSView *child in v.subviews){NSTabView *tabs=findTabs(child);if(tabs)return tabs;}return nil;}
int main(void){@autoreleasepool{
[NSApplication sharedApplication];AppDelegate *app=[AppDelegate new];[app ensureWindow];[app.window orderOut:nil];
assert(app.renderInfoText&&!app.renderInfoText.editable&&app.renderInfoText.selectable);
NSTabView *tabs=findTabs(app.window.contentView);
assert(tabs&&[[tabs tabViewItemAtIndex:2].label isEqual:@"Info"]);
NSString *before=app.renderInfoText.string;RenderResult r={0};[app displayRenderInfo:r];assert([app.renderInfoText.string isEqual:before]);
r.width=480;r.height=360;r.statistics.valid=1;r.statistics.threads=8;r.statistics.elapsed=2.5;r.statistics.rays=172800;r.statistics.steps=345600;r.statistics.max_steps=99;r.statistics.formula_calls[0]=12345;r.statistics.evaluations[1]=67;r.statistics.timing_mask=3;r.statistics.seconds[0]=2;r.statistics.seconds[1]=.25;r.settings.program.slots[0].count=1;
[app displayRenderInfo:r];NSString *text=app.renderInfoText.string;assert([text containsString:@"480 × 360"]&&[text containsString:@"Elapsed: 2.500"]&&[text containsString:@"Slot 1"]&&[text containsString:@"12345"]&&[text containsString:@"Normals: 67"]&&[text containsString:@"Average per ray: 2.00"]);
r.reused_surface=1;r.statistics.gpu=1;[app displayRenderInfo:r];assert([app.renderInfoText.string containsString:@"Cached geometry"]&&[app.renderInfoText.string containsString:@"CPU work only"]);
[tabs selectTabViewItemWithIdentifier:@"info"];[app.window.contentView layoutSubtreeIfNeeded];[app.renderInfoText.layoutManager ensureLayoutForTextContainer:app.renderInfoText.textContainer];assert(app.renderInfoText.frame.size.height>app.renderInfoText.enclosingScrollView.contentSize.height);
/* Exercise the actual asynchronous main-window completion, rather than
   just invoking the formatter directly. */
NSString *historyDirectory=[NSTemporaryDirectory() stringByAppendingPathComponent:[@"info-test-" stringByAppendingString:NSUUID.UUID.UUIDString]];app.renderHistory=[[RenderHistoryStore alloc]initWithDirectory:historyDirectory];
#ifdef USE_RUST_ENGINE
assert(app.cpuOnlyCheck&&app.cpuOnlyCheck.state==NSControlStateValueOff);[app.cpuOnlyCheck performClick:nil];assert(app.cpuOnlyCheck.state==NSControlStateValueOn);assert([app.statusLabel.stringValue containsString:@"CPU only enabled"]);
for(NSUInteger i=2;i<app.calculationFields.count;i++)assert(NSMaxY(app.calculationFields[i].frame)<=NSMinY(app.cpuOnlyCheck.frame));
#else
assert(!app.cpuOnlyCheck);
#endif
RenderOptions options={.width=32,.height=24,.threads=2,.iterations=6};
app.renderInfoText.string=@"Waiting for a real render";[app beginRenderPath:nil options:options];
NSDate *deadline=[NSDate dateWithTimeIntervalSinceNow:20];while(app.calculating&&deadline.timeIntervalSinceNow>0)CFRunLoopRunInMode(kCFRunLoopDefaultMode,.02,YES);
assert(!app.calculating&&app.completedRender);assert([app.renderInfoText.string containsString:@"32 × 24"]&&[app.renderInfoText.string containsString:@"Field evaluations:"]&&![app.renderInfoText.string containsString:@"Waiting for a real render"]);
[NSFileManager.defaultManager removeItemAtPath:historyDirectory error:nil];
#ifdef USE_RUST_ENGINE
assert([app.renderInfoText.string containsString:@"Primary rays: 768"]&&![app.renderInfoText.string containsString:@"GPU assisted"]);assert(app.cpuOnlyCheck.enabled);[app.cpuOnlyCheck performClick:nil];assert(app.cpuOnlyCheck.state==NSControlStateValueOff);
#endif
puts("Main-window render completion updates Info automatically.");
puts("Info tab is selectable, copyable, scrollable, and formats completed render statistics; invalid results retain previous statistics.");}}
