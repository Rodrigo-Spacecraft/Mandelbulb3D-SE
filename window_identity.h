/* Decorative app identity in the title bar; no document/proxy URL. */
@interface RoundedTitleIconView:NSImageView
@end
@implementation RoundedTitleIconView
- (void)drawRect:(NSRect)dirty {
    [NSGraphicsContext saveGraphicsState];
    CGFloat radius=MIN(self.bounds.size.width,self.bounds.size.height)*.23;
    [[NSBezierPath bezierPathWithRoundedRect:self.bounds xRadius:radius yRadius:radius] addClip];
    [super drawRect:dirty];
    [NSGraphicsContext restoreGraphicsState];
}
@end
@interface CenteredIdentityView:NSView
@end
@implementation CenteredIdentityView
- (void)layout {
    [super layout];
    if(!self.window || self.subviews.count!=2)return;
    NSImageView *icon=(NSImageView *)self.subviews[0];NSTextField *title=(NSTextField *)self.subviews[1];
    CGFloat textWidth=ceil([title.stringValue sizeWithAttributes:@{NSFontAttributeName:title.font}].width)+4;
    CGFloat width=MIN(textWidth+29,MAX(40,self.window.frame.size.width-180));
    CGFloat center=[self convertPoint:NSMakePoint(self.window.frame.size.width/2,0) fromView:nil].x;
    CGFloat left=center-width/2;
    icon.frame=NSMakeRect(left,1,22,22);title.frame=NSMakeRect(left+29,3,width-29,20);
}
- (void)viewDidMoveToWindow {[super viewDidMoveToWindow];self.needsLayout=YES;}
@end
@interface MainTitleWindow:NSWindow
@property(nonatomic,strong) NSTitlebarAccessoryViewController *identityAccessory;
@property(nonatomic,strong) NSTextField *identityTitle;
- (void)installAppIdentity;
@end
@implementation MainTitleWindow
- (void)updateIdentityTitle {
    if(!self.identityTitle)return;self.identityTitle.stringValue=self.title;self.identityTitle.toolTip=self.title;
    NSView *view=self.identityAccessory.view;
    view.frame=NSMakeRect(0,0,MAX(120,self.frame.size.width-100),24);
    view.needsLayout=YES;[view layoutSubtreeIfNeeded];
}
- (void)setTitle:(NSString *)title {[super setTitle:title];[self updateIdentityTitle];}
- (void)setFrame:(NSRect)frame display:(BOOL)display {[super setFrame:frame display:display];[self updateIdentityTitle];}
- (void)installAppIdentity {
    if(self.identityAccessory)return;self.titleVisibility=NSWindowTitleHidden;
    NSTitlebarAccessoryViewController *accessory=[NSTitlebarAccessoryViewController new];accessory.layoutAttribute=NSLayoutAttributeLeft;NSView *view=[[CenteredIdentityView alloc]initWithFrame:NSMakeRect(0,0,240,24)];
    NSImageView *icon=[[RoundedTitleIconView alloc]initWithFrame:NSMakeRect(2,1,22,22)];icon.image=[[NSImage alloc]initWithContentsOfFile:[NSBundle.mainBundle.resourcePath stringByAppendingPathComponent:@"AppIcon.icns"]]?:NSApp.applicationIconImage;icon.imageScaling=NSImageScaleProportionallyUpOrDown;icon.accessibilityLabel=@"Application icon";[view addSubview:icon];
    self.identityTitle=[NSTextField labelWithString:self.title];self.identityTitle.font=[NSFont titleBarFontOfSize:13];self.identityTitle.lineBreakMode=NSLineBreakByTruncatingTail;[view addSubview:self.identityTitle];accessory.view=view;self.identityAccessory=accessory;[self addTitlebarAccessoryViewController:accessory];[self updateIdentityTitle];
}
@end
/* Keep small symbol buttons legible independently of AppKit's bezel insets. */
@interface ReadableSymbolButton:NSButton
@property(nonatomic) CGFloat symbolSize;
@end
@implementation ReadableSymbolButton
- (void)drawRect:(NSRect)dirty {
    (void)dirty;[(NSButtonCell *)self.cell drawBezelWithFrame:self.bounds inView:self];CGFloat size=MIN(self.symbolSize?:18,MIN(self.bounds.size.width-6,self.bounds.size.height-6));
    NSRect rect=NSMakeRect((self.bounds.size.width-size)/2,(self.bounds.size.height-size)/2,size,size);[self.image drawInRect:rect fromRect:NSZeroRect operation:NSCompositingOperationSourceOver fraction:self.enabled?1:.35 respectFlipped:self.isFlipped hints:nil];
}
@end
