/* Mutagen family-tree layout follows the original MutaGen window. */
static const double mutagenPositions[15][2]={{0,-1},{-.5,0},{.5,0},{-1.5,-.5},{-1.5,.5},{1.5,-.5},{1.5,.5},{-2,-1.5},{-1,-1.5},{-2,1.5},{-1,1.5},{1,-1.5},{2,-1.5},{1,1.5},{2,1.5}};
static NSRect mutagenTileFrame(NSSize size,int index){double ux=size.width/5,uy=size.height/4;return NSMakeRect(size.width/2+(mutagenPositions[index][0]-.45)*ux,size.height/2+(mutagenPositions[index][1]-.4)*uy,.9*ux,.8*uy);}
@interface MutagenTile:NSView
@property(nonatomic,strong) NSImage *image;
@property(nonatomic,copy) NSString *caption;
@property(nonatomic) BOOL selected;
@property(nonatomic,copy) void (^choose)(BOOL breed);
@property(nonatomic,copy) void (^sendToMain)(void),(^copyParameters)(void);
@end
@implementation MutagenTile
- (BOOL)isFlipped{return YES;}
- (void)drawRect:(NSRect)dirty{(void)dirty;[NSColor.controlBackgroundColor setFill];NSRectFill(self.bounds);if(self.image)[self.image drawInRect:self.bounds fromRect:NSZeroRect operation:NSCompositingOperationSourceOver fraction:1 respectFlipped:YES hints:nil];[(self.selected?NSColor.controlAccentColor:NSColor.separatorColor) setStroke];NSFrameRectWithWidth(self.bounds,self.selected?3:1);if(self.caption.length){[[NSColor.blackColor colorWithAlphaComponent:.6]setFill];NSRectFill(NSMakeRect(0,self.bounds.size.height-18,self.bounds.size.width,18));[self.caption drawInRect:NSMakeRect(4,self.bounds.size.height-17,self.bounds.size.width-8,16) withAttributes:@{NSFontAttributeName:[NSFont systemFontOfSize:10],NSForegroundColorAttributeName:NSColor.whiteColor}];}}
- (void)mouseDown:(NSEvent *)event{if(event.modifierFlags&NSEventModifierFlagControl){[self rightMouseDown:event];return;}if(self.choose)self.choose(event.clickCount>1);}
- (void)rightMouseDown:(NSEvent *)event{if(!self.image)return;NSMenu *menu=[NSMenu new];for(int i=0;i<2;i++){NSMenuItem *item=[[NSMenuItem alloc]initWithTitle:i?@"To clipboard":@"Send to Main" action:i?@selector(copyScene:):@selector(sendScene:) keyEquivalent:@""];item.target=self;[menu addItem:item];}[NSMenu popUpContextMenu:menu withEvent:event forView:self];}
- (void)sendScene:(id)sender{(void)sender;if(self.sendToMain)self.sendToMain();}
- (void)copyScene:(id)sender{(void)sender;if(self.copyParameters)self.copyParameters();}
@end
@interface MutagenTree:NSView
@end
@implementation MutagenTree
- (BOOL)isFlipped{return YES;}
- (void)layout{[super layout];int i=0;for(NSView *view in self.subviews)if([view isKindOfClass:MutagenTile.class])view.frame=mutagenTileFrame(self.bounds.size,i++);self.needsDisplay=YES;}
- (void)drawRect:(NSRect)dirty{(void)dirty;[NSColor.windowBackgroundColor setFill];NSRectFill(self.bounds);[NSColor.secondaryLabelColor setStroke];for(int i=1;i<15;i++){NSRect a=mutagenTileFrame(self.bounds.size,(i-1)/2),b=mutagenTileFrame(self.bounds.size,i);NSPoint p=NSMakePoint(NSMidX(a),NSMidY(a)),q=NSMakePoint(NSMidX(b),NSMidY(b));NSBezierPath *path=[NSBezierPath bezierPath];[path moveToPoint:p];if(i<3){[path lineToPoint:NSMakePoint(p.x,q.y)];}else if(i<7){[path lineToPoint:NSMakePoint(q.x,p.y)];}else [path lineToPoint:NSMakePoint(p.x,q.y)];[path lineToPoint:q];[path stroke];}}
@end
@interface MutagenGeneration:NSObject
@property(nonatomic,strong) NSMutableArray *options,*images,*probes;
@property(nonatomic,copy) NSString *source,*identifier;
@end
@implementation MutagenGeneration
- (instancetype)init{if((self=[super init])){self.options=[NSMutableArray array];self.images=[NSMutableArray array];self.probes=[NSMutableArray array];for(int i=0;i<15;i++){[self.options addObject:NSNull.null];[self.images addObject:NSNull.null];[self.probes addObject:NSNull.null];}self.identifier=NSUUID.UUID.UUIDString;}return self;}
@end
static NSData *mutagenPack(RenderOptions options){options.cancel_token=NULL;options.navigation_count=0;return [NSData dataWithBytes:&options length:sizeof options];}
static RenderOptions mutagenUnpack(NSData *data){RenderOptions result={0};if([data isKindOfClass:NSData.class]&&data.length==sizeof result)memcpy(&result,data.bytes,sizeof result);return result;}
static RenderOptions mutagenPreview(RenderOptions options,int width,int height,RenderCancelToken *token){
    int original=MAX(16,options.width);double stop=options.de_stop;options=navigatorPreviewOptions(options,1);options.width=width;options.height=height;options.de_stop=fmax(1e-6,stop*width/original);options.reuse_surface=0;options.preview_cache=1;options.cancel_token=token;options.navigation_count=0;return options;
}
