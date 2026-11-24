/* Native macOS shell. Fractal computation and file parsing are C. LGPL-2.1-or-later. */
#import <Cocoa/Cocoa.h>
#import <ImageIO/ImageIO.h>
#import "renderer.h"
#import "animation.h"
#include "numeric_input.h"
#include "formula_ui.h"
#include "file_dialog_history.h"
#include "default_maps.h"
#include "window_identity.h"
#include "lighting_files.h"
#ifdef USE_RUST_ENGINE
#include "rust_engine.h"
#define FORMULA_UI_SLOTS 6
#define APP_TITLE @"Mandelbulb3D SE"
#define HISTORY_STORE_NAME @"Mandelbulb3Dr"
#else
#define FORMULA_UI_SLOTS 6
#define APP_TITLE @"Mandelbulb3Dx"
#define HISTORY_STORE_NAME APP_TITLE
#endif

static const BOOL automaticColorUpdates=YES;

/* Event-tracking loops must be able to display completed previews mid-drag. */
static void interactiveUI(dispatch_block_t block) {
    CFRunLoopPerformBlock(CFRunLoopGetMain(),kCFRunLoopCommonModes,block);CFRunLoopWakeUp(CFRunLoopGetMain());
}
static int formulaKindForMenu(NSInteger index){return formula_menu_kind((int)index);}
static NSInteger formulaMenuForKind(int kind){for(NSInteger i=0;i<formula_menu_count();i++)if(formulaKindForMenu(i)==kind)return i;return 0;}
/* Original FormulaNames categories, classified by each formula's DEoption. */
static NSInteger formulaCategory(int kind){
    int catalog=formula_catalog_category(kind);if(catalog>=0)return catalog;
    switch(kind){
        case 4:case 100:case 102:case 109:case 121:return 1; /* 3Da */
        case 2:case 118:case 119:case 120:return 2; /* 4D */
        case 133:case 130:return 3; /* 4Da */
        case 103:case 104:case 105:case 106:case 108:case 117:case 122:case 132:case 131:return 4; /* Ads */
        case 101:case 111:case 112:case 113:case 114:case 115:case 116:case 123:case 125:case 126:case 128:return 5; /* dIFS shapes */
        case 124:case 127:case 129:return 6; /* dIFS transformations */
        default:return 0;
    }
}
static int formulaSelectedKind(NSPopUpButton *button){return [button.itemArray.firstObject.representedObject intValue];}
static void formulaSelectKind(NSPopUpButton *button,int kind){
    if(kind!=-1)kind=formulaKindForMenu(formulaMenuForKind(kind));
    NSMenuItem *display=button.itemArray.firstObject;display.title=[NSString stringWithUTF8String:formula_name(kind)];display.representedObject=@(kind);
    [button selectItemAtIndex:0];
    NSFont *bold=[NSFont boldSystemFontOfSize:NSFont.systemFontSize];
    for(NSMenuItem *category in button.itemArray){
        if(!category.hasSubmenu)continue;
        BOOL selectedCategory=NO;
        for(NSMenuItem *leaf in category.submenu.itemArray){
            BOOL selected=leaf.tag==kind;selectedCategory|=selected;
            leaf.state=selected?NSControlStateValueOn:NSControlStateValueOff;
            leaf.attributedTitle=nil;
        }
        category.attributedTitle=selectedCategory?[[NSAttributedString alloc]initWithString:category.title attributes:@{NSFontAttributeName:bold}]:nil;
    }
}
static BOOL usesGenericFormulaEditor(int kind){return kind==2||kind==6||kind>=101;}
static FormulaProgram defaultFormulaProgram(void) {
    FormulaProgram p={.min_iterations=1,.split=1,.repeat2=1,.max_iterations2=60,.bailout=16,.smooth=.5,.formula_power=2};
    for(int i=0;i<8;i++){p.slots[i]=formula_slot_default(i?-1:0);p.slots[i].count=i?0:1;}return p;
}
static RenderOptions navigatorPreviewOptions(RenderOptions options,NSInteger stage) {
    /* Prioritize first-frame latency. Refinement is canceled by the next edit. */
    double targetWidth=stage==0?80:stage==1?160:320,targetHeight=stage==0?60:stage==1?120:240;
    int originalWidth=options.width;
    double scale=fmin(1.0,fmax(fmin(targetWidth/options.width,targetHeight/options.height),16.0/fmin(options.width,options.height)));
    options.width=MAX(16,(int)lround(options.width*scale));options.height=MAX(16,(int)lround(options.height*scale));
    /* Preserve the world-space hit threshold and full formula schedule. */
    options.de_stop=fmax(1e-6,options.de_stop*options.width/originalWidth);
    options.oversampling=options.viewing=1;
    options.fog_override=1;options.fog=fog_settings_default();
    options.reflections_override=1;options.reflections.enabled=options.reflections.automatic=0;
    options.dof_override=1;if(!options.dof.passes)options.dof=(DepthOfFieldSettings){.passes=1,.aperture=.02,.clip_radius=25};options.dof.enabled=options.dof.automatic=0;
    options.normals_override=1;options.normal_smoothing=0;options.normal_zbuffer=1;
    options.shadows_override=1;
    if(stage<2){
        options.shadows.hard_enabled=options.shadows.hard_auto=0;
        options.shadows.ambient_method=0; /* inexpensive local ambient approximation */
    }else{
        if(options.shadows.ambient_method>=2)options.shadows.ambient_method=0;
        options.shadows.ambient_rays=MIN(options.shadows.ambient_rays,7);
        options.shadows.ambient_steps=MIN(options.shadows.ambient_steps,32);
    }
    options.reuse_surface=1;options.preview_cache=1;
    return options;
}
@interface LiveSlider : NSSlider
@property(nonatomic) BOOL trackingPosition,lightPositionRange;
@property(nonatomic) double trackingValue,lastPointerX,lastActionValue;
@property(nonatomic,strong) NSNumber *commandResetValue;
@property(nonatomic,copy) void (^started)(void);
@property(nonatomic,copy) void (^finished)(void);
@end
@implementation LiveSlider
- (void)redrawSlider {
    /* Custom tracking bypasses NSSliderCell's focus-mask invalidation. Tell
       AppKit the knob moved so its separate focus-ring layer follows it. */
    [self noteFocusRingMaskChanged];
    /* NSSlider is transparent. Redrawing it alone can leave the old knob in
       the shared backing store during our custom event-tracking loop. Dirty
       the complete control area in its parent so the background is repainted. */
    self.needsDisplay=YES;
    if(self.superview){[self.superview setNeedsDisplayInRect:[self convertRect:self.bounds toView:self.superview]];[self.superview displayIfNeeded];}
    else [self displayIfNeeded];
}
- (void)updateFromEvent:(NSEvent *)event {
    NSPoint point=[self convertPoint:event.locationInWindow fromView:nil];
    double travel=fmax(1,self.bounds.size.width-16),range=self.maxValue-self.minValue;
    BOOL fine=(event.modifierFlags&NSEventModifierFlagShift)!=0;
    if(!self.trackingPosition)self.trackingValue=fine?self.doubleValue:self.minValue+fmax(0,fmin(1,(point.x-8)/travel))*range;
    else self.trackingValue+=(point.x-self.lastPointerX)*range/travel*(fine?.1:1);
    self.trackingValue=fmax(self.minValue,fmin(self.maxValue,self.trackingValue));
    self.lastPointerX=point.x;self.trackingPosition=YES;
    double value=self.trackingValue;
    if(self.allowsTickMarkValuesOnly&&self.numberOfTickMarks>1) {
        double step=(self.maxValue-self.minValue)/(self.numberOfTickMarks-1);value=self.minValue+round((value-self.minValue)/step)*step;
    }
    self.doubleValue=value;[self sendAction:self.action to:self.target];[self redrawSlider];
}
- (void)mouseDown:(NSEvent *)event {
    if(!self.enabled)return;
    if((event.modifierFlags&NSEventModifierFlagCommand)&&self.commandResetValue){
        if(self.started)self.started();
        double value=self.commandResetValue.doubleValue;
        self.minValue=fmin(self.minValue,value);self.maxValue=fmax(self.maxValue,value);
        self.doubleValue=self.trackingValue=value;self.trackingPosition=NO;
        [self sendAction:self.action to:self.target];
        if(self.finished)self.finished();
        [self redrawSlider];return;
    }
    self.trackingPosition=NO;
    if(self.started)self.started();
    [self.window makeFirstResponder:self];[self updateFromEvent:event];
    for(;;) {
        NSEvent *next=[NSApp nextEventMatchingMask:NSEventMaskLeftMouseDragged|NSEventMaskLeftMouseUp untilDate:NSDate.distantFuture inMode:NSEventTrackingRunLoopMode dequeue:YES];
        if(!next)break;[self updateFromEvent:next];if(next.type==NSEventTypeLeftMouseUp)break;
    }
    self.trackingPosition=NO;
    if(self.finished)self.finished();
    [self redrawSlider];
}
@end

/* Preserve the stored precision when an unchanged display field is read back.
   Formatting a value for the UI must not invalidate a completed surface. */
static double unchangedFieldValue(NSTextField *field,double parsed,double stored,NSString *format){
    return [field.stringValue isEqualToString:numericDisplayString([NSString stringWithFormat:format,stored])]?stored:parsed;
}

static NSImage *imageForRender(RenderResult result,int viewing) {
    int width=result.width,height=result.height;
    NSBitmapImageRep *bitmap=[[NSBitmapImageRep alloc] initWithBitmapDataPlanes:NULL pixelsWide:width pixelsHigh:height bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSCalibratedRGBColorSpace bitmapFormat:NSBitmapFormatAlphaNonpremultiplied bytesPerRow:(NSInteger)width*4 bitsPerPixel:32];
    if(!bitmap)return nil;
    for(int y=0;y<height;y++)memcpy(bitmap.bitmapData+(size_t)y*bitmap.bytesPerRow,result.rgba+(size_t)y*result.stride,(size_t)width*4);
    NSImage *image=[[NSImage alloc] initWithSize:NSMakeSize((width+viewing-1)/viewing,(height+viewing-1)/viewing)];[image addRepresentation:bitmap];return image;
}

@interface FractalView : NSImageView
@property(nonatomic,copy) void (^openScene)(NSString *path);
@property(nonatomic,copy) void (^placeLight)(NSPoint point);
@property(nonatomic) BOOL pickingLight;
@property(nonatomic) BOOL showFrameNumber,whiteFrameNumber;
@property(nonatomic) NSInteger frameNumber;
@end
@implementation FractalView
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];if(!self.showFrameNumber||!self.image)return;
    NSSize size=self.image.size;double scale=fmin(self.bounds.size.width/size.width,self.bounds.size.height/size.height);if(self.imageScaling==NSImageScaleProportionallyDown)scale=fmin(1,scale);
    NSRect area=NSMakeRect(NSMidX(self.bounds)-size.width*scale/2,NSMidY(self.bounds)-size.height*scale/2,size.width*scale,size.height*scale);
    NSString *text=[NSString stringWithFormat:@"%ld",(long)self.frameNumber];
    double fontSize=fmax(4,fmin(12,(area.size.width-8)/fmax(1,text.length)*1.5));
    [NSGraphicsContext saveGraphicsState];NSRectClip(area);
    [text drawAtPoint:NSMakePoint(area.origin.x+5,self.isFlipped?area.origin.y+4:NSMaxY(area)-fontSize-7) withAttributes:@{NSFontAttributeName:[NSFont monospacedDigitSystemFontOfSize:fontSize weight:NSFontWeightMedium],NSForegroundColorAttributeName:self.whiteFrameNumber?NSColor.whiteColor:NSColor.blackColor}];[NSGraphicsContext restoreGraphicsState];
}
- (void)mouseDown:(NSEvent *)event {
    if(!self.pickingLight||!self.image||!self.placeLight){[super mouseDown:event];return;}
    NSSize size=self.image.size;NSRect bounds=self.bounds;
    double scale=fmin(bounds.size.width/size.width,bounds.size.height/size.height);
    NSRect imageRect=NSMakeRect(NSMidX(bounds)-size.width*scale/2,NSMidY(bounds)-size.height*scale/2,size.width*scale,size.height*scale);
    NSPoint p=[self convertPoint:event.locationInWindow fromView:nil];
    if(!NSPointInRect(p,imageRect))return;
    double y=(p.y-imageRect.origin.y)/imageRect.size.height;
    self.placeLight(NSMakePoint((p.x-imageRect.origin.x)/imageRect.size.width,self.isFlipped?y:1-y));
}
- (instancetype)initWithFrame:(NSRect)frame {
    if((self=[super initWithFrame:frame])) {
        self.imageScaling=NSImageScaleProportionallyUpOrDown;
        self.imageAlignment=NSImageAlignCenter;
        self.editable=NO;
        [self registerForDraggedTypes:@[NSPasteboardTypeFileURL]];
    }
    return self;
}
- (NSString *)sceneFromDrag:(id<NSDraggingInfo>)sender {
    NSArray<NSURL *> *urls=[sender.draggingPasteboard readObjectsForClasses:@[NSURL.class]
                   options:@{NSPasteboardURLReadingFileURLsOnlyKey:@YES}];
    if(urls.count==1 && [@[@"m3i",@"m3p",@"msi"] containsObject:urls.firstObject.pathExtension.lowercaseString])
        return urls.firstObject.path;
    return nil;
}
- (NSDragOperation)draggingEntered:(id<NSDraggingInfo>)sender {
    return [self sceneFromDrag:sender]?NSDragOperationCopy:NSDragOperationNone;
}
- (BOOL)prepareForDragOperation:(id<NSDraggingInfo>)sender {
    return [self sceneFromDrag:sender]!=nil;
}
- (BOOL)performDragOperation:(id<NSDraggingInfo>)sender {
    NSString *path=[self sceneFromDrag:sender];
    if(!path)return NO;
    if(self.openScene)self.openScene(path);
    return YES;
}
@end

static NSNumber *navigatorKeyOperation(NSEvent *event) {
    if(event.modifierFlags&(NSEventModifierFlagCommand|NSEventModifierFlagControl|NSEventModifierFlagOption))return nil;
    NSString *key=event.charactersIgnoringModifiers.lowercaseString;if(!key)return nil;
    NSDictionary *keys=@{@"w":@0,@"s":@1,@"a":@2,@"d":@3,@"c":@4,@"e":@5,@"j":@6,@"l":@7,@"i":@8,@"k":@9,@"z":@10,@"x":@11,@"u":@10,@"o":@11,@"+":@12,@"=":@12,@"-":@13};
    NSNumber *operation=keys[key];
    if(!operation&&key.length)switch([key characterAtIndex:0]) {
        case NSF1FunctionKey:operation=@16;break;case NSF2FunctionKey:operation=@17;break;
        case NSLeftArrowFunctionKey:operation=@6;break;case NSRightArrowFunctionKey:operation=@7;break;
        case NSUpArrowFunctionKey:operation=@8;break;case NSDownArrowFunctionKey:operation=@9;break;
    }
    if(operation&&(event.modifierFlags&NSEventModifierFlagShift))return @(operation.integerValue+100);
    return operation;
}
@interface NavigatorWindow : NSWindow
@property(nonatomic,weak) NSView *preview;
@property(nonatomic,copy) void (^navigate)(NSInteger operation);
@end
@implementation NavigatorWindow
- (void)sendEvent:(NSEvent *)event {
    if(event.type==NSEventTypeKeyDown) {
        NSNumber *operation=navigatorKeyOperation(event);
        BOOL editing=[self.firstResponder isKindOfClass:NSTextView.class]&&[(NSTextView *)self.firstResponder isFieldEditor];
        NSString *key=event.charactersIgnoringModifiers;
        BOOL textKey=key.length&&([@"+-=" containsString:key]||[key characterAtIndex:0]==NSLeftArrowFunctionKey||[key characterAtIndex:0]==NSRightArrowFunctionKey||[key characterAtIndex:0]==NSUpArrowFunctionKey||[key characterAtIndex:0]==NSDownArrowFunctionKey);
        if(operation&&self.navigate&&!(editing&&textKey)) {
            if(editing&&![self makeFirstResponder:self.preview])return;
            self.navigate(operation.integerValue);return;
        }
    }
    [super sendEvent:event];
}
@end

@interface NavigatorView : FractalView
@property(nonatomic,copy) void (^navigate)(NSInteger operation);
@property(nonatomic,copy) void (^look)(double yaw,double pitch);
@property(nonatomic) NSPoint dragPoint;
@property(nonatomic,strong) NSImage *unadjustedImage;
@property(nonatomic) double displayGain;
@end
@implementation NavigatorView
- (instancetype)initWithFrame:(NSRect)frame {if((self=[super initWithFrame:frame]))_displayGain=1;return self;}
- (void)setImage:(NSImage *)image {self.unadjustedImage=image;[self updateBrightnessDisplay];}
- (void)setDisplayGain:(double)gain {_displayGain=gain;[self updateBrightnessDisplay];}
- (void)updateBrightnessDisplay {
    NSImage *source=self.unadjustedImage;
    if(!source||self.displayGain==1){[super setImage:source];return;}
    NSBitmapImageRep *original=(NSBitmapImageRep *)source.representations.firstObject;
    if(![original isKindOfClass:NSBitmapImageRep.class]||original.bitsPerSample!=8||original.samplesPerPixel!=4||original.isPlanar){[super setImage:source];return;}
    NSBitmapImageRep *adjusted=[[NSBitmapImageRep alloc]initWithBitmapDataPlanes:NULL pixelsWide:original.pixelsWide pixelsHigh:original.pixelsHigh bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:original.colorSpaceName bitmapFormat:original.bitmapFormat bytesPerRow:original.bytesPerRow bitsPerPixel:original.bitsPerPixel];
    if(!adjusted){[super setImage:source];return;}
    memcpy(adjusted.bitmapData,original.bitmapData,original.bytesPerRow*original.pixelsHigh);BOOL first=original.bitmapFormat&NSBitmapFormatAlphaFirst;
    for(NSInteger y=0;y<adjusted.pixelsHigh;y++){unsigned char *row=adjusted.bitmapData+y*adjusted.bytesPerRow;for(NSInteger x=0;x<adjusted.pixelsWide;x++)for(int c=0;c<3;c++){int i=(int)(x*4)+(first?1:0)+c;row[i]=(unsigned char)lround(fmin(255,row[i]*self.displayGain));}}
    NSImage *display=[[NSImage alloc]initWithSize:source.size];[display addRepresentation:adjusted];[super setImage:display];
}
- (BOOL)acceptsFirstResponder {return YES;}
- (void)mouseDown:(NSEvent *)event {
    [self.window makeFirstResponder:self];self.dragPoint=[self convertPoint:event.locationInWindow fromView:nil];
}
- (void)mouseDragged:(NSEvent *)event {
    NSPoint point=[self convertPoint:event.locationInWindow fromView:nil];
    double rate=(event.modifierFlags&NSEventModifierFlagShift)?.025:.25;
    if(self.look)self.look(-(point.x-self.dragPoint.x)*rate,(point.y-self.dragPoint.y)*rate);
    self.dragPoint=point;
}
- (void)keyDown:(NSEvent *)event {
    NSNumber *operation=navigatorKeyOperation(event);
    if(operation&&self.navigate)self.navigate(operation.integerValue);else [super keyDown:event];
}
@end

/* Brightness is a display preference; Command-click restores its neutral value. */
@interface NavigatorBrightnessSlider : NSSlider
@end
@implementation NavigatorBrightnessSlider
- (void)mouseDown:(NSEvent *)event {
    if(event.modifierFlags&NSEventModifierFlagCommand){if(!self.enabled)return;self.doubleValue=0;[self sendAction:self.action to:self.target];return;}
    [super mouseDown:event];
}
@end

@interface RenderProgressPie : NSView
@property(nonatomic) double fraction;
@property(nonatomic) BOOL indeterminate;
@property(nonatomic) double rotation;
@end
@implementation RenderProgressPie
- (void)setFraction:(double)fraction {_fraction=fmax(0,fmin(1,fraction));self.needsDisplay=YES;}
- (void)drawRect:(NSRect)dirtyRect {
    (void)dirtyRect;NSRect circle=NSInsetRect(self.bounds,1,1);NSPoint center=NSMakePoint(NSMidX(circle),NSMidY(circle));CGFloat radius=MIN(circle.size.width,circle.size.height)*.5;
    [NSColor.quaternaryLabelColor setFill];[[NSBezierPath bezierPathWithOvalInRect:circle]fill];
    if(self.indeterminate){NSBezierPath *arc=[NSBezierPath bezierPath];[arc appendBezierPathWithArcWithCenter:center radius:radius-2 startAngle:self.rotation endAngle:self.rotation-90 clockwise:YES];arc.lineWidth=2;[NSColor.controlAccentColor setStroke];[arc stroke];}
    else if(self.fraction>0){NSBezierPath *pie=[NSBezierPath bezierPath];[pie moveToPoint:center];[pie lineToPoint:NSMakePoint(center.x,center.y+radius)];[pie appendBezierPathWithArcWithCenter:center radius:radius startAngle:90 endAngle:90-360*self.fraction clockwise:YES];[pie closePath];[NSColor.controlAccentColor setFill];[pie fill];}
    [NSColor.secondaryLabelColor setStroke];NSBezierPath *outline=[NSBezierPath bezierPathWithOvalInRect:circle];outline.lineWidth=1;[outline stroke];
}
@end

@interface CalculationPanel : NSView
@end
@implementation CalculationPanel
- (BOOL)isFlipped {return YES;}
- (BOOL)wantsDefaultClipping {return YES;}
- (void)drawRect:(NSRect)dirtyRect {
    [NSGraphicsContext saveGraphicsState];
    NSRectClip(self.bounds);
    [NSColor.windowBackgroundColor setFill];
    NSRectFill(NSIntersectionRect(dirtyRect,self.bounds));
    [NSGraphicsContext restoreGraphicsState];
}
@end

@interface FormulaSearchController : NSObject<NSTableViewDataSource,NSTableViewDelegate,NSTextFieldDelegate>
@property(nonatomic,strong) NSWindow *window;
@property(nonatomic,strong) NSTextField *query,*countLabel;
@property(nonatomic,strong) NSTableView *table;
@property(nonatomic,strong) NSArray<NSNumber *> *matches;
@property(nonatomic,copy) void (^choose)(int kind);
- (void)filter;
@end
@implementation FormulaSearchController
- (instancetype)init {
    if(!(self=[super init]))return nil;
    self.window=[[NSWindow alloc]initWithContentRect:NSMakeRect(0,0,420,430) styleMask:NSWindowStyleMaskTitled backing:NSBackingStoreBuffered defer:NO];self.window.title=@"Search Formulas";self.window.releasedWhenClosed=NO;
    CalculationPanel *panel=[[CalculationPanel alloc]initWithFrame:NSMakeRect(0,0,420,430)];self.window.contentView=panel;
    self.query=[[NSTextField alloc]initWithFrame:NSMakeRect(16,16,388,26)];self.query.placeholderString=@"Search formula names";self.query.accessibilityLabel=@"Search formulas";self.query.delegate=self;self.query.target=self;self.query.action=@selector(selectFormula:);[panel addSubview:self.query];
    self.countLabel=[NSTextField labelWithString:@""];self.countLabel.frame=NSMakeRect(16,48,388,20);self.countLabel.font=[NSFont systemFontOfSize:11];[panel addSubview:self.countLabel];
    NSScrollView *scroll=[[NSScrollView alloc]initWithFrame:NSMakeRect(16,72,388,302)];scroll.hasVerticalScroller=YES;scroll.borderType=NSBezelBorder;
    self.table=[[NSTableView alloc]initWithFrame:scroll.bounds];NSTableColumn *column=[[NSTableColumn alloc]initWithIdentifier:@"formula"];column.width=366;[self.table addTableColumn:column];self.table.headerView=nil;self.table.dataSource=self;self.table.delegate=self;self.table.target=self;self.table.action=@selector(selectFormula:);self.table.accessibilityLabel=@"Matching formulas";scroll.documentView=self.table;[panel addSubview:scroll];
    NSButton *cancel=[NSButton buttonWithTitle:@"Cancel" target:self action:@selector(cancel:)];cancel.frame=NSMakeRect(210,386,92,30);cancel.keyEquivalent=@"\033";[panel addSubview:cancel];
    NSButton *choose=[NSButton buttonWithTitle:@"Select" target:self action:@selector(selectFormula:)];choose.frame=NSMakeRect(308,386,96,30);choose.keyEquivalent=@"\r";[panel addSubview:choose];[self filter];return self;
}
- (void)filter {
    NSString *query=[self.query.stringValue stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceAndNewlineCharacterSet];NSMutableArray *matches=[NSMutableArray array];
    for(int i=0;i<formula_menu_count();i++){int kind=formula_menu_kind(i);NSString *name=[NSString stringWithUTF8String:formula_name(kind)];if(!query.length||[name rangeOfString:query options:NSCaseInsensitiveSearch|NSDiacriticInsensitiveSearch].location!=NSNotFound)[matches addObject:@(kind)];}
    [matches sortUsingComparator:^NSComparisonResult(NSNumber *a,NSNumber *b){return [[NSString stringWithUTF8String:formula_name(a.intValue)]localizedStandardCompare:[NSString stringWithUTF8String:formula_name(b.intValue)]];}];self.matches=matches;[self.table deselectAll:nil];[self.table reloadData];self.countLabel.stringValue=matches.count?[NSString stringWithFormat:@"%lu formulas",(unsigned long)matches.count]:@"No matching formulas";
}
- (void)controlTextDidChange:(NSNotification *)notification {(void)notification;[self filter];}
- (NSInteger)numberOfRowsInTableView:(NSTableView *)table {(void)table;return self.matches.count;}
- (NSView *)tableView:(NSTableView *)table viewForTableColumn:(NSTableColumn *)column row:(NSInteger)row {
    (void)table;(void)column;NSTextField *label=[NSTextField labelWithString:[NSString stringWithUTF8String:formula_name(self.matches[row].intValue)]];label.lineBreakMode=NSLineBreakByTruncatingTail;return label;
}
- (void)cancel:(id)sender {(void)sender;[self.window.sheetParent endSheet:self.window];[self.window orderOut:nil];}
- (void)selectFormula:(id)sender {
    NSInteger row=self.table.selectedRow;if(row<0&&sender!=self.table&&self.matches.count)row=0;if(row<0||row>=(NSInteger)self.matches.count)return;
    int kind=self.matches[row].intValue;[self cancel:nil];if(self.choose)self.choose(kind);
}
@end

/* Use the same palette intervals for color and opacity. */
static double paletteInterval(const ObjectLighting *palette,int count,double position,int *a,int *b) {
    if(position<=palette->stops[0].position){*a=*b=0;return 0;}
    if(position>=palette->stops[count-1].position){*a=*b=count-1;return 0;}
    *b=1;
    while(*b<count-1&&position>palette->stops[*b].position)(*b)++;
    *a=*b-1;
    double span=palette->stops[*b].position-palette->stops[*a].position;
    return span>0&&!palette->no_interpolation?(position-palette->stops[*a].position)/span:0;
}
static NSColor *paletteColor(ObjectLighting palette,double position,BOOL specular) {
    int a,b;
    double t=paletteInterval(&palette,10,position,&a,&b);
    double *ca=specular?palette.stops[a].specular:palette.stops[a].diffuse;
    double *cb=specular?palette.stops[b].specular:palette.stops[b].diffuse;
    return [NSColor colorWithSRGBRed:ca[0]+(cb[0]-ca[0])*t green:ca[1]+(cb[1]-ca[1])*t blue:ca[2]+(cb[2]-ca[2])*t alpha:1];
}
@interface AdjustmentColorWell : NSColorWell
@property(nonatomic) BOOL allowsOpacity;
@end
@interface RotationTabItem : NSTabViewItem
@property(nonatomic) BOOL dimmed;
@end
@implementation RotationTabItem
- (void)drawLabel:(BOOL)truncate inRect:(NSRect)rect {
    if(!self.dimmed){[super drawLabel:truncate inRect:rect];return;}
    [self.label drawInRect:rect withAttributes:@{NSFontAttributeName:[NSFont systemFontOfSize:NSFont.systemFontSize],NSForegroundColorAttributeName:NSColor.disabledControlTextColor}];
}
@end

/* Restore to YES to show the retained Navigator exploration feature. */
static const BOOL NavigatorExploreControlsVisible=NO;
@interface ExploreBackground : NSView
@end
@implementation ExploreBackground
- (void)drawRect:(NSRect)dirty {if(!NavigatorExploreControlsVisible)return;[[NSColor colorWithWhite:.5 alpha:.18] setFill];NSRectFill(NSIntersectionRect(dirty,self.bounds));}
@end
@interface ExploreParameterRows : CalculationPanel
@end
@implementation ExploreParameterRows
- (void)drawRect:(NSRect)dirty {
    [super drawRect:dirty];if(NavigatorExploreControlsVisible){[[NSColor colorWithWhite:.5 alpha:.18]setFill];NSRectFill(NSIntersectionRect(dirty,NSMakeRect(626,0,MAX(0,self.bounds.size.width-626),self.bounds.size.height)));}
}
@end
@interface ExploreButton : NSButton
@end
@implementation ExploreButton
- (void)mouseDown:(NSEvent *)event {if(event.modifierFlags&NSEventModifierFlagControl){[self rightMouseDown:event];return;}[super mouseDown:event];}
- (void)rightMouseDown:(NSEvent *)event {
    (void)event;if(self.enabled&&[self.title isEqual:@"Resume"])[NSApp sendAction:@selector(exploreSelectionChanged:) to:self.target from:self];
}
@end

#include "color_favorites.h"
#include "formula_thumbnails.h"
#include "formula_menu_groups.h"

#include "mutagen_engine.h"
#include "mutagen_views.h"

@interface ColorHistogramView : NSView
@property(nonatomic,strong) NSData *bins;
@property(nonatomic) NSInteger firstBin,lastBin;
@end
@implementation ColorHistogramView
- (instancetype)initWithFrame:(NSRect)frame {if((self=[super initWithFrame:frame]))self.lastBin=255;return self;}
- (void)drawRect:(NSRect)dirty {
    (void)dirty;[NSColor.whiteColor setFill];NSRectFill(self.bounds);
    if(self.bins.length!=256*sizeof(unsigned))return;const unsigned *bins=self.bins.bytes;unsigned maximum=0;for(NSInteger i=MAX(0,self.firstBin);i<=MIN(255,self.lastBin);i++)maximum=MAX(maximum,bins[i]);if(!maximum)return;
    [NSColor.secondaryLabelColor setFill];CGFloat width=self.bounds.size.width,height=self.bounds.size.height;
    for(int x=0;x<(int)ceil(width);x++){int span=(int)(self.lastBin-self.firstBin+1);int lo=(int)self.firstBin+x*span/fmax(1,width),hi=MAX(lo+1,self.firstBin+(x+1)*span/fmax(1,width));unsigned count=0;for(int i=MAX(0,lo);i<MIN(256,MIN(self.lastBin+1,hi));i++)count=MAX(count,bins[i]);[[NSColor colorWithWhite:1-(double)count/maximum alpha:1] setFill];NSRectFill(NSMakeRect(x,0,1,height));}
}
@end

@interface CommonColorPalette : NSView
@end
@implementation CommonColorPalette
- (instancetype)initWithFrame:(NSRect)frame {
    if((self=[super initWithFrame:frame])){
        NSArray *names=@[@"Black",@"Dark gray",@"Gray",@"White",@"Red",@"Orange",@"Yellow",@"Brown",@"Green",@"Lime",@"Cyan",@"Teal",@"Blue",@"Purple",@"Magenta",@"Pink"];
        const unsigned colors[]={0x000000,0x404040,0x808080,0xFFFFFF,0xFF0000,0xFF8000,0xFFFF00,0x804020,0x008000,0x80FF00,0x00FFFF,0x008080,0x0000FF,0x8000FF,0xFF00FF,0xFF80B0};
        for(int i=0;i<16;i++){
            unsigned c=colors[i];NSColor *color=[NSColor colorWithSRGBRed:((c>>16)&255)/255. green:((c>>8)&255)/255. blue:(c&255)/255. alpha:1];
            NSImage *image=[NSImage imageWithSize:NSMakeSize(18,18) flipped:NO drawingHandler:^BOOL(NSRect rect){[color setFill];NSRectFill(rect);[NSColor.grayColor setStroke];NSFrameRectWithWidth(rect,1);return YES;}];
            NSButton *button=[NSButton buttonWithImage:image target:self action:@selector(chooseColor:)];button.bordered=NO;button.frame=NSMakeRect(6+(i%8)*25,30-(i/8)*24,22,22);button.tag=c;button.toolTip=names[i];button.accessibilityLabel=names[i];[self addSubview:button];
        }
    }return self;
}
- (void)chooseColor:(NSButton *)sender {
    unsigned c=(unsigned)sender.tag;NSColorPanel *panel=NSColorPanel.sharedColorPanel;
    CGFloat alpha=panel.showsAlpha?panel.color.alphaComponent:1;
    panel.color=[NSColor colorWithSRGBRed:((c>>16)&255)/255. green:((c>>8)&255)/255. blue:(c&255)/255. alpha:alpha];
}
@end
static void installCommonColorPalette(void){
    NSColorPanel *panel=NSColorPanel.sharedColorPanel;
    if(![panel.accessoryView isKindOfClass:CommonColorPalette.class])panel.accessoryView=[[CommonColorPalette alloc]initWithFrame:NSMakeRect(0,0,210,58)];
}
static __weak AdjustmentColorWell *activeAdjustmentColorWell;
@implementation AdjustmentColorWell
- (void)setColor:(NSColor *)color {[super setColor:self.allowsOpacity?color:[color colorWithAlphaComponent:1]];}
- (void)drawWellInside:(NSRect)insideRect {
    NSColor *rgb=[self.color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];
    if(!rgb){[super drawWellInside:insideRect];return;}
    [[rgb colorWithAlphaComponent:1]setFill];NSRectFill(insideRect);
    if(!self.allowsOpacity)return;
    /* Keep RGB visible even at zero alpha; a narrow strip still shows alpha. */
    NSRect strip=NSMakeRect(insideRect.origin.x,insideRect.origin.y,insideRect.size.width,MIN(4,insideRect.size.height));
    [NSGraphicsContext saveGraphicsState];NSRectClip(strip);
    for(CGFloat x=NSMinX(strip);x<NSMaxX(strip);x+=4){[(fmod(floor((x-NSMinX(strip))/4),2)==0?NSColor.whiteColor:[NSColor colorWithWhite:.65 alpha:1])setFill];NSRectFill(NSMakeRect(x,NSMinY(strip),4,strip.size.height));}
    [rgb setFill];NSRectFillUsingOperation(strip,NSCompositingOperationSourceOver);[NSGraphicsContext restoreGraphicsState];
}
- (void)activate:(BOOL)exclusive {
    // Hiding alpha can change the panel's color. Disconnect its previous
    // recipient first so changing picker modes cannot edit that material.
    if(exclusive)[activeAdjustmentColorWell deactivate];
    installCommonColorPalette();NSColorPanel *panel=NSColorPanel.sharedColorPanel;
    panel.continuous=YES;panel.showsAlpha=self.allowsOpacity;
    [super activate:exclusive];activeAdjustmentColorWell=self;
    panel.showsAlpha=self.allowsOpacity;
}
- (void)mouseDown:(NSEvent *)event {
    (void)event;if(!self.enabled)return;[self activate:YES];[NSColorPanel.sharedColorPanel makeKeyAndOrderFront:nil];
}
@end
/* Finder stores the custom preview icon in this file's resource fork, so no
 * sidecar or render is needed. The standard M3I image remains in the data fork. */
static BOOL setSceneFinderPreview(NSString *path,NSBitmapImageRep *bitmap){
    if(!bitmap||bitmap.pixelsWide<1||bitmap.pixelsHigh<1)return NO;
    NSImage *source=[[NSImage alloc]initWithSize:NSMakeSize(bitmap.pixelsWide,bitmap.pixelsHigh)];[source addRepresentation:bitmap];
    NSImage *icon=[[NSImage alloc]initWithSize:NSMakeSize(512,512)];[icon lockFocus];
    [NSColor.clearColor setFill];NSRectFillUsingOperation(NSMakeRect(0,0,512,512),NSCompositingOperationCopy);
    NSGraphicsContext.currentContext.imageInterpolation=NSImageInterpolationHigh;
    double scale=fmin(512./bitmap.pixelsWide,512./bitmap.pixelsHigh);NSSize size=NSMakeSize(bitmap.pixelsWide*scale,bitmap.pixelsHigh*scale);
    [source drawInRect:NSMakeRect((512-size.width)/2,(512-size.height)/2,size.width,size.height) fromRect:NSZeroRect operation:NSCompositingOperationSourceOver fraction:1];[icon unlockFocus];
    return [NSWorkspace.sharedWorkspace setIcon:icon forFile:path options:0];
}
/* Finder metadata is optional: network resource forks can block for minutes.
 * Preserve the embedded M3I preview everywhere; custom Finder icons are local only.
 * Use a separate queue so neither UI events nor the next render wait for Finder. */
static void scheduleSceneFinderPreview(NSString *path,NSBitmapImageRep *bitmap){
    if(!bitmap)return;
    static dispatch_queue_t icons;static dispatch_once_t once;dispatch_once(&once,^{icons=dispatch_queue_create("com.greenoak.m3dse.finder-previews",DISPATCH_QUEUE_SERIAL);});
    dispatch_async(icons,^{@autoreleasepool{
        NSNumber *local=nil;NSURL *url=[NSURL fileURLWithPath:path];
        if([url getResourceValue:&local forKey:NSURLVolumeIsLocalKey error:nil]&&local.boolValue)setSceneFinderPreview(path,bitmap);
    }});
}
/* Menu items retain thumbnails; only the collapsed popup draws text alone. */
static NSString *formulaInformationText(int kind){
    NSString *name=[NSString stringWithUTF8String:formula_name(kind)];
    NSArray *roots=@[NSBundle.mainBundle.resourcePath?:@"",@"resources"];
    for(NSString *root in roots){NSDictionary *builtins=[NSDictionary dictionaryWithContentsOfFile:[root stringByAppendingPathComponent:@"FormulaInfo.plist"]];NSString *description=builtins[[@(kind) stringValue]];if(description.length)return [NSString stringWithFormat:@"%@\n\n%@",name,description];}
    NSArray *folders=@[[NSBundle.mainBundle.resourcePath?:@"" stringByAppendingPathComponent:@"M3Formulas"],@"rust-assets/M3Formulas"];
    for(NSString *folder in folders){NSString *file=[folder stringByAppendingPathComponent:[name stringByAppendingPathExtension:@"m3f"]];NSData *data=[NSData dataWithContentsOfFile:file];if(!data)continue;NSString *text=[[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];if(!text)text=[[NSString alloc]initWithData:data encoding:NSWindowsCP1252StringEncoding];NSRange end=[text rangeOfString:@"[END]" options:NSCaseInsensitiveSearch];if(text&&end.location!=NSNotFound){NSString *description=[[text substringFromIndex:NSMaxRange(end)] stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceAndNewlineCharacterSet];description=[[description stringByReplacingOccurrencesOfString:@"\r\n" withString:@"\n"]stringByReplacingOccurrencesOfString:@"\r" withString:@"\n"];if(description.length)return [NSString stringWithFormat:@"%@\n\n%@",name,description];}}
    return [NSString stringWithFormat:@"%@\n\nNo additional information is included with this formula.",name];
}
@interface MapFilenameCell : NSPopUpButtonCell
@end
@implementation MapFilenameCell
- (NSCellImagePosition)imagePosition{return NSNoImage;}
- (void)setImagePosition:(NSCellImagePosition)position{(void)position;[super setImagePosition:NSNoImage];}
- (void)drawWithFrame:(NSRect)frame inView:(NSView *)view {
    /* NSPopUpButtonCell can draw the selected menu item's image even when
       imagePosition is NSNoImage. Hide it for this draw, then restore it so
       the expanded menu keeps its thumbnail. All drawing runs on the UI thread. */
    NSMenuItem *item=self.selectedItem;NSImage *thumbnail=item.image;item.image=nil;
    @try {[super drawWithFrame:frame inView:view];}
    @finally {item.image=thumbnail;}
}
@end
/* The open menu describes every slot; the compact control shows its number. */
@interface NavigatorSlotCell : NSPopUpButtonCell
@end
@implementation NavigatorSlotCell
- (NSString *)title {id compact=self.selectedItem.representedObject;return [compact isKindOfClass:NSString.class]?compact:[super title];}
- (NSRect)drawTitle:(NSAttributedString *)title withFrame:(NSRect)frame inView:(NSView *)view {
    NSDictionary *attributes=title.length?[title attributesAtIndex:0 effectiveRange:NULL]:@{};
    NSAttributedString *compact=[[NSAttributedString alloc]initWithString:self.title attributes:attributes];
    return [super drawTitle:compact withFrame:frame inView:view];
}
@end
/* Decode only small images on a serial utility queue; map menus stay responsive
 * even when the source folder contains hundreds of large textures. */
static void addMapMenuThumbnail(NSMenuItem *item,NSString *path){
    static dispatch_queue_t queue;static NSCache *cache;static NSImage *placeholder;static dispatch_once_t once;
    dispatch_once(&once,^{queue=dispatch_queue_create("org.codex.mandelbulb3d.map-thumbnails",dispatch_queue_attr_make_with_qos_class(DISPATCH_QUEUE_SERIAL,QOS_CLASS_UTILITY,0));cache=[NSCache new];cache.totalCostLimit=16*1024*1024;placeholder=[NSImage imageWithSize:NSMakeSize(48,32) flipped:NO drawingHandler:^BOOL(NSRect rect){(void)rect;return YES;}];});
    NSImage *hit=[cache objectForKey:path];if(hit){item.image=hit;return;}item.image=placeholder;
    dispatch_async(queue,^{@autoreleasepool{
        CGImageSourceRef source=CGImageSourceCreateWithURL((__bridge CFURLRef)[NSURL fileURLWithPath:path],(__bridge CFDictionaryRef)@{(id)kCGImageSourceShouldCache:@NO});if(!source)return;
        CGImageRef thumbnail=CGImageSourceCreateThumbnailAtIndex(source,0,(__bridge CFDictionaryRef)@{(id)kCGImageSourceCreateThumbnailFromImageAlways:@YES,(id)kCGImageSourceCreateThumbnailWithTransform:@YES,(id)kCGImageSourceThumbnailMaxPixelSize:@96});CFRelease(source);if(!thumbnail)return;
        double w=CGImageGetWidth(thumbnail),h=CGImageGetHeight(thumbnail),scale=fmin(48./w,32./h);
        NSImage *sourceImage=[[NSImage alloc]initWithCGImage:thumbnail size:NSMakeSize(w,h)];NSImage *image=[NSImage imageWithSize:NSMakeSize(48,32) flipped:NO drawingHandler:^BOOL(NSRect rect){(void)rect;[sourceImage drawInRect:NSMakeRect((48-w*scale)/2,(32-h*scale)/2,w*scale,h*scale) fromRect:NSZeroRect operation:NSCompositingOperationSourceOver fraction:1];return YES;}];NSUInteger cost=CGImageGetBytesPerRow(thumbnail)*CGImageGetHeight(thumbnail);CGImageRelease(thumbnail);[cache setObject:image forKey:path cost:cost];
        interactiveUI(^{item.image=image;});
    }});
}
static const CGFloat paletteMarkerInset=10,paletteMarkerHeight=30;
static NSNumber *paletteShortcut(NSEvent *event){
    NSEventModifierFlags flags=event.modifierFlags&NSEventModifierFlagDeviceIndependentFlagsMask;
    if((flags&(NSEventModifierFlagCommand|NSEventModifierFlagControl|NSEventModifierFlagOption|NSEventModifierFlagShift))!=NSEventModifierFlagCommand)return nil;
    NSString *key=event.charactersIgnoringModifiers.lowercaseString;NSArray *keys=@[@"c",@"v",@"g",@"b"];NSUInteger n=[keys indexOfObject:key];return n==NSNotFound?nil:@(n);
}
@interface PaletteWindow : NSWindow
@property(nonatomic,copy) BOOL (^stopCommand)(NSInteger command);
@end
@implementation PaletteWindow
- (BOOL)performKeyEquivalent:(NSEvent *)event {
    NSNumber *command=paletteShortcut(event);
    BOOL editing=[self.firstResponder isKindOfClass:NSTextView.class]&&[(NSTextView *)self.firstResponder isFieldEditor];
    if(command&&!(editing&&command.integerValue<2)&&self.stopCommand&&self.stopCommand(command.integerValue))return YES;
    return [super performKeyEquivalent:event];
}
@end
@interface PaletteView : NSView<NSMenuItemValidation>
@property(nonatomic) ObjectLighting palette;
@property(nonatomic) NSInteger stopCount;
@property(nonatomic) BOOL specular,markers,enabled,stacked,showOpacityBand,hoverBezel,hovered,draggingStop;
@property(nonatomic,strong) NSTrackingArea *hoverTrackingArea;
@property(nonatomic,strong) NSArray<NSNumber *> *opacityStops;
@property(nonatomic) NSInteger selected;
@property(nonatomic) NSPoint stopDragOrigin;
@property(nonatomic,copy) void (^clicked)(NSInteger stop,BOOL pickColor);
@property(nonatomic,copy) void (^moved)(NSInteger stop,unsigned position,BOOL finished);
@property(nonatomic,copy) BOOL (^stopCommand)(NSInteger command);
@property(nonatomic,copy) BOOL (^canPaste)(void);
@end
@implementation PaletteView
- (void)updateTrackingAreas {
    [super updateTrackingAreas];
    if(self.hoverTrackingArea)[self removeTrackingArea:self.hoverTrackingArea];
    self.hoverTrackingArea=nil;
    if(self.hoverBezel){
        self.hoverTrackingArea=[[NSTrackingArea alloc]initWithRect:NSZeroRect options:NSTrackingMouseEnteredAndExited|NSTrackingActiveInKeyWindow|NSTrackingInVisibleRect owner:self userInfo:nil];
        [self addTrackingArea:self.hoverTrackingArea];
        self.hovered=self.window&&NSPointInRect([self convertPoint:self.window.mouseLocationOutsideOfEventStream fromView:nil],self.bounds);
    }else self.hovered=NO;
    self.needsDisplay=YES;
}
- (void)mouseEntered:(NSEvent *)event {(void)event;self.hovered=YES;self.needsDisplay=YES;}
- (void)mouseExited:(NSEvent *)event {(void)event;self.hovered=NO;self.needsDisplay=YES;}
- (BOOL)acceptsFirstMouse:(NSEvent *)event {(void)event;return self.enabled;}
- (BOOL)acceptsFirstResponder{return self.markers&&self.enabled;}
- (BOOL)isFlipped{return YES;}
- (BOOL)wantsDefaultClipping{return YES;}
- (void)drawRect:(NSRect)dirty {
    (void)dirty;[NSGraphicsContext saveGraphicsState];NSRectClip(self.bounds);
    CGFloat padding=self.hoverBezel?5:0;
    CGFloat width=self.bounds.size.width-2*padding,height=self.bounds.size.height-2*padding-(self.markers?paletteMarkerHeight:0);
    if(self.hoverBezel&&self.hovered&&self.enabled){
        [[NSColor colorWithWhite:.78 alpha:1]setFill];NSRectFill(self.bounds);
        NSRect bezel=NSInsetRect(self.bounds,1,1);
        NSBezierPath *light=[NSBezierPath bezierPath];light.lineWidth=2;
        [light moveToPoint:NSMakePoint(NSMinX(bezel),NSMaxY(bezel))];[light lineToPoint:bezel.origin];[light lineToPoint:NSMakePoint(NSMaxX(bezel),NSMinY(bezel))];
        [[NSColor colorWithWhite:.94 alpha:1]setStroke];[light stroke];
        NSBezierPath *shadow=[NSBezierPath bezierPath];shadow.lineWidth=2;
        [shadow moveToPoint:NSMakePoint(NSMaxX(bezel),NSMinY(bezel))];[shadow lineToPoint:NSMakePoint(NSMaxX(bezel),NSMaxY(bezel))];[shadow lineToPoint:NSMakePoint(NSMinX(bezel),NSMaxY(bezel))];
        [[NSColor colorWithWhite:.42 alpha:1]setStroke];[shadow stroke];
    }
    NSAffineTransform *inset=[NSAffineTransform transform];[inset translateXBy:padding yBy:padding];[inset concat];
    CGFloat markerInset=self.markers?paletteMarkerInset:0;
    ObjectLighting palette=self.palette;
    int count=self.stopCount?:10;
    for(int x=0;x<(int)ceil(width);x++) {
        double position=32767*fmax(0,fmin(1,(x+.5-markerInset)/fmax(1,width-2*markerInset)));
        double opacity=1;
        if(self.opacityStops.count>=(NSUInteger)count){
            int a,b;
            double t=paletteInterval(&palette,count,position,&a,&b);
            opacity=self.opacityStops[a].doubleValue*(1-t)+self.opacityStops[b].doubleValue*t;
        }
        if(self.stacked){
            CGFloat opacityHeight=height*.15,specularHeight=height*.35;
            [paletteColor(self.palette,position,NO)setFill];NSRectFill(NSMakeRect(x,opacityHeight+specularHeight,1,height*.5));
            [paletteColor(self.palette,position,YES)setFill];NSRectFill(NSMakeRect(x,opacityHeight,1,specularHeight));
            [[NSColor colorWithWhite:opacity alpha:1]setFill];NSRectFill(NSMakeRect(x,0,1,opacityHeight));
        }else{[paletteColor(self.palette,position,self.specular) setFill];NSRectFill(NSMakeRect(x,0,1,height));if(self.showOpacityBand){[[NSColor colorWithWhite:opacity alpha:1]setFill];NSRectFill(NSMakeRect(x,0,1,height/3));}}
    }
    [NSColor.blackColor setFill];NSFrameRectWithWidth(NSMakeRect(0,0,width,height),.5);
    if(self.markers)for(int i=0;i<(self.stopCount?:10);i++) {
        CGFloat x=paletteMarkerInset+(width-2*paletteMarkerInset)*MIN(32767,self.palette.stops[i].position)/32767.;
        NSBezierPath *p=[NSBezierPath bezierPath];[p moveToPoint:NSMakePoint(x,height)];
        [p lineToPoint:NSMakePoint(x-9,height+15)];[p lineToPoint:NSMakePoint(x+9,height+15)];[p closePath];
        [(i==self.selected?NSColor.controlAccentColor:NSColor.labelColor) setFill];[p fill];
        NSString *number=[NSString stringWithFormat:@"%d",i+1];
        if(i==self.selected||(i<(self.stopCount?:10)-1&&(self.palette.stops[i+1].position-self.palette.stops[i].position)*(width-2*paletteMarkerInset)/32767.>20)) [number drawAtPoint:NSMakePoint(fmax(0,fmin(width-14,x-4)),height+15) withAttributes:@{NSFontAttributeName:[NSFont systemFontOfSize:9],NSForegroundColorAttributeName:NSColor.labelColor}];
    }
    [NSGraphicsContext restoreGraphicsState];
}
- (void)mouseDown:(NSEvent *)event {
    self.draggingStop=NO;self.stopDragOrigin=[self convertPoint:event.locationInWindow fromView:nil];
    if(event.modifierFlags&NSEventModifierFlagControl){NSMenu *menu=[self menuForEvent:event];if(menu)[NSMenu popUpContextMenu:menu withEvent:event forView:self];return;}
    [self selectStopForEvent:event];
}
- (void)selectStopForEvent:(NSEvent *)event {
    if(!self.enabled)return;[self.window makeFirstResponder:self];NSPoint p=[self convertPoint:event.locationInWindow fromView:nil];
    NSInteger nearest=0;double distance=1e20;
    for(int i=0;i<(self.stopCount?:10);i++){double x=paletteMarkerInset+(self.bounds.size.width-2*paletteMarkerInset)*MIN(32767,self.palette.stops[i].position)/32767.;if(fabs(x-p.x)<distance){distance=fabs(x-p.x);nearest=i;}}
    self.selected=nearest;self.needsDisplay=YES;if(self.clicked)self.clicked(nearest,event.clickCount>1);
}
- (NSMenu *)menuForEvent:(NSEvent *)event {
    if(!self.enabled||!self.markers||!self.stopCommand)return nil;
    [self selectStopForEvent:event];NSMenu *menu=[[NSMenu alloc]initWithTitle:@"Color stop"];
    NSArray *titles=@[@"Copy",@"Paste",@"Paste Diffuse",@"Paste Specular"],*keys=@[@"c",@"v",@"g",@"b"];
    for(int i=0;i<4;i++){NSMenuItem *item=[[NSMenuItem alloc]initWithTitle:titles[i] action:@selector(paletteStopCommand:) keyEquivalent:keys[i]];item.keyEquivalentModifierMask=NSEventModifierFlagCommand;item.tag=i;item.target=self;[menu addItem:item];}
    return menu;
}
- (BOOL)validateMenuItem:(NSMenuItem *)item {return self.enabled&&(item.tag==0||(self.canPaste&&self.canPaste()));}
- (void)paletteStopCommand:(NSMenuItem *)item {if(self.enabled&&self.stopCommand)self.stopCommand(item.tag);}
- (void)mouseDragged:(NSEvent *)event {
    if(!self.enabled||!self.markers)return;
    NSPoint p=[self convertPoint:event.locationInWindow fromView:nil];
    if(!self.draggingStop&&hypot(p.x-self.stopDragOrigin.x,p.y-self.stopDragOrigin.y)<3)return;
    unsigned position=(unsigned)lround(fmax(0,fmin(32767,(p.x-paletteMarkerInset)*32767/fmax(1,self.bounds.size.width-2*paletteMarkerInset))));
    self.draggingStop=YES;if(self.moved)self.moved(self.selected,position,NO);
}
- (void)mouseUp:(NSEvent *)event {
    (void)event;BOOL dragged=self.draggingStop;self.draggingStop=NO;
    if(dragged&&self.enabled&&self.markers&&self.moved)self.moved(self.selected,self.palette.stops[self.selected].position,YES);
}
@end

/* Box resolve: every subpixel contributes, unlike nearest-neighbor resizing. */
static NSImage *animationResolvedImage(RenderResult result,int sampling){
    if(sampling<=1)return imageForRender(result,1);
    if(result.width%sampling||result.height%sampling)return nil;
    int width=result.width/sampling,height=result.height/sampling;
    NSBitmapImageRep *bitmap=[[NSBitmapImageRep alloc]initWithBitmapDataPlanes:NULL pixelsWide:width pixelsHigh:height bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSCalibratedRGBColorSpace bitmapFormat:NSBitmapFormatAlphaNonpremultiplied bytesPerRow:width*4 bitsPerPixel:32];if(!bitmap)return nil;
    for(int y=0;y<height;y++)for(int x=0;x<width;x++){
        unsigned sums[3]={0};for(int sy=0;sy<sampling;sy++)for(int sx=0;sx<sampling;sx++){const unsigned char *p=result.rgba+(y*sampling+sy)*result.stride+(x*sampling+sx)*4;for(int c=0;c<3;c++)sums[c]+=p[c];}
        unsigned char *out=bitmap.bitmapData+y*bitmap.bytesPerRow+x*4;int count=sampling*sampling;for(int c=0;c<3;c++)out[c]=(sums[c]+count/2)/count;out[3]=255;
    }
    NSImage *image=[[NSImage alloc]initWithSize:NSMakeSize(width,height)];[image addRepresentation:bitmap];return image;
}
static NSImage *animationThumbnailToFit(NSBitmapImageRep *source,double maxWidth,double maxHeight){
    if(!source||source.bitsPerPixel!=32||source.samplesPerPixel!=4)return nil;
    double scale=fmin(1,fmin(maxWidth/source.pixelsWide,maxHeight/source.pixelsHigh));int w=MAX(1,(int)lround(source.pixelsWide*scale)),h=MAX(1,(int)lround(source.pixelsHigh*scale));
    NSBitmapImageRep *small=[[NSBitmapImageRep alloc]initWithBitmapDataPlanes:NULL pixelsWide:w pixelsHigh:h bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSCalibratedRGBColorSpace bytesPerRow:w*4 bitsPerPixel:32];if(!small)return nil;
    /* Area averaging retains all source samples and avoids thumbnail aliasing. */
    double dx=(double)source.pixelsWide/w,dy=(double)source.pixelsHigh/h;
    for(int y=0;y<h;y++)for(int x=0;x<w;x++){
        double x0=x*dx,x1=(x+1)*dx,y0=y*dy,y1=(y+1)*dy,sum[4]={0};
        for(int sy=(int)floor(y0);sy<(int)ceil(y1)&&sy<source.pixelsHigh;sy++)for(int sx=(int)floor(x0);sx<(int)ceil(x1)&&sx<source.pixelsWide;sx++){
            double weight=(fmin(x1,sx+1)-fmax(x0,sx))*(fmin(y1,sy+1)-fmax(y0,sy));const unsigned char *pixel=source.bitmapData+sy*source.bytesPerRow+sx*4;for(int c=0;c<4;c++)sum[c]+=pixel[c]*weight;
        }
        unsigned char *pixel=small.bitmapData+y*small.bytesPerRow+x*4;for(int c=0;c<4;c++)pixel[c]=(unsigned char)lround(sum[c]/(dx*dy));
    }
    NSImage *image=[[NSImage alloc]initWithSize:NSMakeSize(w,h)];[image addRepresentation:small];return image;
}
static NSImage *animationThumbnail(NSBitmapImageRep *source){return animationThumbnailToFit(source,494,282);}
static BOOL animationInteger(NSString *text,int minimum,int maximum,int *out){double value;NSScanner *scanner=[NSScanner scannerWithString:text];if(![scanner scanDouble:&value]||!scanner.isAtEnd||!isfinite(value)||value!=floor(value)||value<minimum||value>maximum)return NO;*out=(int)value;return YES;}
// Builds with experimental material settings appended 24 or 32 bytes.
static NSUInteger animationLegacyMaterialSize(NSUInteger size){
    NSUInteger prefix=offsetof(RenderOptions,transmission_blur);
    if(size==prefix+24||size==prefix+32||size==prefix+40)return prefix;
    return 0;
}
static BOOL animationOptionsSize(NSUInteger size){return size==sizeof(RenderOptions)||size==offsetof(RenderOptions,subsurface_amount)||size==offsetof(RenderOptions,subsurface_scattering)||size==offsetof(RenderOptions,translucency_mode)||size==offsetof(RenderOptions,translucency_glow)||size==offsetof(RenderOptions,transmission_blur)||animationLegacyMaterialSize(size)||size==offsetof(RenderOptions,cutting_colors)||size==offsetof(RenderOptions,cutting)||size==offsetof(RenderOptions,stepcount)||size==offsetof(RenderOptions,gamma)||size==offsetof(RenderOptions,preserved_header_valid)||size==offsetof(RenderOptions,retired_indirect_strength_override)||size==offsetof(RenderOptions,retired_indirect_override)||size==offsetof(RenderOptions,position)||size==offsetof(RenderOptions,ssao_override)||size==offsetof(RenderOptions,rotation4_override)||size==offsetof(RenderOptions,fog_override)||size==offsetof(RenderOptions,reflections_override)||size==offsetof(RenderOptions,reflections)+offsetof(ReflectionSettings,opacity_set);}
static RenderOptions animationUnpack(NSData *data){RenderOptions options={0};NSUInteger legacy=animationLegacyMaterialSize(data.length);if(legacy)memcpy(&options,data.bytes,legacy);else if(animationOptionsSize(data.length))memcpy(&options,data.bytes,data.length);if(data.length<=offsetof(RenderOptions,gamma)&&options.preserved_header_valid){uint32_t bits;memcpy(&bits,options.preserved_header+476,4);options.gamma=(CFSwapInt32LittleToHost(bits)>>23)&63;options.gamma_override=1;}for(int i=6;i<8;i++)options.program.slots[i]=formula_slot_default(0);if(options.program.repeat_from>5)options.program.repeat_from=0;if(options.program.repeat2>5)options.program.repeat2=5;if(options.program.split>5)options.program.split=5;options.retired_indirect_override=options.retired_indirect_enabled=options.retired_indirect_strength_override=0;options.retired_indirect_strength=0;if(!options.translucency_mode){options.translucency_mode=1+(options.transmission_blur>0||options.translucency_glow!=0);if(options.translucency_mode==1)options.transmission_blur=1;}if(data.length<=offsetof(RenderOptions,subsurface_amount))options.subsurface_amount=1;options.cancel_token=NULL;options.navigation_count=0;options.reuse_surface=options.preview_cache=0;return options;}
static void animationPut32(unsigned char *p,uint32_t n){for(int i=0;i<4;i++)p[i]=(unsigned char)(n>>(8*i));}
static uint32_t animationRead32(const unsigned char *p){return p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24;}
#include "render_history.h"

@interface FormulaCopyButton : NSButton
@end
@implementation FormulaCopyButton
- (void)mouseDown:(NSEvent *)event {if(event.modifierFlags&NSEventModifierFlagControl){[self rightMouseDown:event];return;}[super mouseDown:event];}
- (void)rightMouseDown:(NSEvent *)event {
    (void)event;if(self.enabled)[NSApp sendAction:@selector(copyActiveFormulaNames:) to:self.target from:self];
}
@end

@interface LightingUndoButton : NSButton
@property(nonatomic,copy) void (^redoAction)(void);
@end
@implementation LightingUndoButton
- (void)mouseDown:(NSEvent *)event {if(event.modifierFlags&NSEventModifierFlagControl){[self rightMouseDown:event];return;}[super mouseDown:event];}
- (void)rightMouseDown:(NSEvent *)event {(void)event;if(self.enabled&&self.redoAction)self.redoAction();}
@end

@interface SceneOpenPreview : NSObject<NSOpenSavePanelDelegate>
@property(nonatomic,strong) NSView *view;
@property(nonatomic,strong) NSImageView *image;
@property(nonatomic,strong) NSTextField *caption;
@property(nonatomic,strong) NSButton *allowFolderButton;
@property(nonatomic,strong) NSURL *previewFolder;
@property(nonatomic,copy) void (^requestFolderAccess)(NSURL *folder);
@property(nonatomic) NSUInteger generation;
@end
@implementation SceneOpenPreview
- (instancetype)init {
    if((self=[super init])){
        _view=[[NSView alloc]initWithFrame:NSMakeRect(0,0,360,208)];
        _image=[[NSImageView alloc]initWithFrame:NSMakeRect(8,30,344,170)];_image.imageScaling=NSImageScaleProportionallyUpOrDown;_image.accessibilityLabel=@"Selected scene preview";[_view addSubview:_image];
        _caption=[NSTextField labelWithString:@"Select an .m3i file to preview"];_caption.frame=NSMakeRect(8,4,344,22);_caption.alignment=NSTextAlignmentCenter;_caption.lineBreakMode=NSLineBreakByTruncatingMiddle;[_view addSubview:_caption];
        _allowFolderButton=[NSButton buttonWithTitle:@"Allow Folder Previews…" target:self action:@selector(allowFolderPreviews:)];
        [_allowFolderButton sizeToFit];
        [_allowFolderButton setFrameOrigin:NSMakePoint((360-_allowFolderButton.frame.size.width)/2,83)];
        _allowFolderButton.hidden=YES;
        [_view addSubview:_allowFolderButton];
    }return self;
}
- (void)allowFolderPreviews:(id)sender {
    if(self.previewFolder&&self.requestFolderAccess)self.requestFolderAccess(self.previewFolder);
}
- (void)panelSelectionDidChange:(id)sender {
    NSOpenPanel *panel=sender;NSURL *url=panel.URLs.firstObject?:panel.URL;NSUInteger generation=++self.generation;
    NSString *extension=url.pathExtension.lowercaseString;
    BOOL selectedScene=url.isFileURL&&([extension isEqualToString:@"m3i"]||[extension isEqualToString:@"msi"]);
    self.allowFolderButton.hidden=YES;
    self.previewFolder=nil;
    self.image.image=nil;self.caption.stringValue=selectedScene?@"Loading preview…":@"Select an .m3i file to preview";
    if(!selectedScene)return;
    __weak SceneOpenPreview *weakSelf=self;
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{
        BOOL scoped=[url startAccessingSecurityScopedResource];
        NSError *error=nil;
        NSData *data=[NSData dataWithContentsOfURL:url options:NSDataReadingMappedIfSafe error:&error];
        NSBitmapImageRep *bitmap=embeddedSceneBitmap(data,320);
        if(scoped)[url stopAccessingSecurityScopedResource];
        dispatch_async(dispatch_get_main_queue(),^{SceneOpenPreview *owner=weakSelf;if(!owner||owner.generation!=generation)return;
            if(bitmap){NSImage *image=[[NSImage alloc]initWithSize:NSMakeSize(bitmap.pixelsWide,bitmap.pixelsHigh)];[image addRepresentation:bitmap];owner.image.image=image;owner.caption.stringValue=url.lastPathComponent;}
            else if([error.domain isEqualToString:NSCocoaErrorDomain]&&error.code==NSFileReadNoPermissionError){
                owner.caption.stringValue=@"Preview needs access to this folder";
                owner.previewFolder=url.URLByDeletingLastPathComponent;
                owner.allowFolderButton.hidden=owner.requestFolderAccess==nil;
            }
            else owner.caption.stringValue=error?@"Could not read preview":@"No embedded preview";
        });
    });
}
@end

typedef NS_ENUM(NSInteger, PostProcessEffect) {
    PostProcessNone, PostProcessHardShadows, PostProcessAmbientShadows,
    PostProcessReflections, PostProcessDepthOfField
};

@interface AppDelegate : NSObject<NSApplicationDelegate,NSWindowDelegate,NSTextFieldDelegate,NSTableViewDataSource,NSTableViewDelegate,NSMenuDelegate,NSTabViewDelegate>
@property(nonatomic,strong) NSWindow *animationWindow,*animationProcessingWindow;
@property(nonatomic,strong) NSArray<NSButton *> *animationProcessingChecks,*animationProcessingButtons;
@property(nonatomic,strong) NSArray<NSTextField *> *animationProcessingFields;
@property(nonatomic,strong) NSButton *animationProcessingStop;
@property(nonatomic,strong) NSTextField *animationProcessingStatus;
@property(nonatomic) BOOL animationRegeneratingPreviews;
@property(nonatomic,strong) NSButton *animationButton,*animationLoop,*animationProcessingsButton,*animationZBuffer;
@property(nonatomic,strong) NSButton *animationRenderFrameButton,*animationRenderPreviewButton,*animationExportButton;
@property(nonatomic) NSInteger animationRenderKind; /* 0 processing, 1 frame, 2 preview, 3 export */
@property(nonatomic) BOOL animationStopRequested;
@property(nonatomic,strong) FractalView *animationView;
@property(nonatomic,strong) NSTableView *animationTable;
@property(nonatomic,strong) NSMutableArray<NSMutableDictionary *> *animationKeys;
@property(nonatomic,strong) NSArray<NSTextField *> *animationFields;
@property(nonatomic,strong) NSArray<NSControl *> *animationControls;
@property(nonatomic,strong) NSPopUpButton *animationSampling,*animationInterpolation;
@property(nonatomic,strong) NSTextField *animationStatus,*animationPreviewEstimate;
@property(nonatomic) double animationSecondsPerPixel;
@property(nonatomic,strong) NSSlider *animationTimeline;
@property(nonatomic,strong) NSPopUpButton *animationPreviewScale;
@property(nonatomic,strong) NSTextField *animationOutputLabel;
@property(nonatomic,copy) NSString *animationOutputFolder;
@property(nonatomic,strong) NSMutableSet<NSString *> *animationTemporarySources;
@property(nonatomic) BOOL animationRunning;
@property(nonatomic,strong) NSButton *animationPause,*animationFrameOverlay;
@property(nonatomic,strong) NSPopUpButton *animationFrameColor;
@property(nonatomic,strong) NSTimer *animationPlaybackTimer;
@property(nonatomic,strong) NSArray<NSDictionary *> *animationPlaybackFrames;
@property(nonatomic,copy) NSString *animationPlaybackFolder;
@property(nonatomic) NSUInteger animationPlaybackIndex;
@property(nonatomic) double animationPlaybackInterval;
@property(nonatomic,strong) NSTimer *mainProgressTimer;
@property(nonatomic,strong) NSWindow *window;
@property(nonatomic,strong) FractalView *imageView;
@property(nonatomic,strong) dispatch_queue_t renderQueue;
@property(nonatomic,copy) NSString *initialPath;
@property(nonatomic) NSUInteger generation;
@property(nonatomic) BOOL receivedFile;
@property(nonatomic) int renderWidth,renderHeight,threads;
@property(nonatomic,copy) NSString *currentPath;
@property(nonatomic,strong) NSButton *clipboardButton,*saveClipboardButton,*pngButton,*openM3IButton;
@property(nonatomic,strong) RenderHistoryStore *renderHistory;
@property(nonatomic,strong) NSPopUpButton *historyMenu;
@property(nonatomic,strong) NSBitmapImageRep *completedRender;
@property(nonatomic,strong) NSImage *sharpRenderImage;
@property(nonatomic,strong) NSMutableSet<NSString *> *clipboardScenes;
@property(nonatomic,strong) FormulaSearchController *formulaSearch;
@property(nonatomic,strong) NSPopUpButton *navigatorFormulaTypeMenu;
@property(nonatomic,strong) RenderProgressPie *renderProgressPie;
@property(nonatomic,strong) NSArray<NSTextField *> *calculationFields;
@property(nonatomic,strong) NSTextView *renderInfoText;
@property(nonatomic,strong) NSButton *cpuOnlyCheck;
@property(nonatomic,strong) NSTextField *stepcountField;
@property(nonatomic,strong) NSArray<NSStepper *> *calculationSteppers;
@property(nonatomic,strong) NSArray<NSTextField *> *positionFields;
@property(nonatomic,strong) NSArray<NSString *> *positionPasteValues;
@property(nonatomic) CameraSettings positionPasteCamera;
@property(nonatomic,strong) NSButton *positionCopyButton,*positionPasteButton;
@property(nonatomic,strong) NSArray<NSString *> *positionBaseline;
@property(nonatomic) BOOL midpointPicking;
@property(nonatomic,strong) NSButton *dofAutomatic;
@property(nonatomic,strong) NSPopUpButton *dofPasses;
@property(nonatomic,strong) NSArray<NSTextField *> *dofFields;
@property(nonatomic,strong) NSArray<NSSlider *> *dofSliders;
@property(nonatomic,strong) NSArray<NSControl *> *dofControls;
@property(nonatomic) BOOL dofApplied;
@property(nonatomic) PostProcessEffect postProcessOnce;
@property(nonatomic) NSInteger focusPicking;
@property(nonatomic,strong) NSButton *stopButton;
@property(nonatomic,strong) NSButton *navigatorResetPosButton;
@property(nonatomic) RenderCancelToken *mainCancelToken;
@property(nonatomic) NSInteger placingLight;
@property(nonatomic,strong) NSArray<NSControl *> *positionControls;
@property(nonatomic,strong) NSArray<NSTextField *> *lightMoveSteps;
@property(nonatomic,strong) NSButton *renderButton,*saveButton,*keepAspectCheck,*scaleDECheck,*displayActualSizeButton;
@property(nonatomic) BOOL actualSizeNeedsRender;
@property(nonatomic) NSInteger completedOutputWidth,completedOutputHeight;
@property(nonatomic,strong) NSPopUpButton *oversamplingMenu;
@property(nonatomic,strong) NSStepper *imageSizeStepper;
@property(nonatomic,strong) NSPopUpButton *objectMapMenu,*objectMapMode;
@property(nonatomic,strong) NSPopUpButton *fogMode,*fogLight;
@property(nonatomic,strong) NSArray<NSTextField *> *fogFields,*fogColorLabels,*fogFieldLabels;
@property(nonatomic,strong) NSTextField *fogLightLabel;
@property(nonatomic,strong) NSArray<NSSlider *> *fogSliders;
@property(nonatomic,strong) NSArray<NSColorWell *> *fogWells;
@property(nonatomic,strong) NSButton *fogBlend,*fogOnlyAdd,*fogUseColorButton;
@property(nonatomic,strong) NSArray<NSControl *> *fogControls;
@property(nonatomic,strong) NSArray<NSTextField *> *ambientFields;
@property(nonatomic,strong) NSArray<NSSlider *> *ambientSliders;
@property(nonatomic,strong) NSArray<NSColorWell *> *ambientWells;
@property(nonatomic,strong) NSButton *ambientRelative,*ambientFarFog;
@property(nonatomic,strong) NSPopUpButton *ambientGradient;
@property(nonatomic,copy) NSString *ambientAOBaseline;
@property(nonatomic,strong) NSWindow *mutagenWindow;
@property(nonatomic,strong) NSButton *mutagenButton,*mutagenMutateButton,*mutagenClearButton,*mutagenResetButton,*mutagenDisableButton;
@property(nonatomic,strong) MutagenTree *mutagenTree;
@property(nonatomic,strong) NSArray<MutagenTile *> *mutagenTiles;
@property(nonatomic,strong) NSArray<NSSlider *> *mutagenProbabilities,*mutagenStrengths;
@property(nonatomic,strong) NSMutableArray<MutagenGeneration *> *mutagenHistory;
@property(nonatomic,strong) NSTextField *mutagenGenerationLabel,*mutagenStatus;
@property(nonatomic,strong) NSStepper *mutagenGenerationStepper;
@property(nonatomic,strong) NSProgressIndicator *mutagenProgress;
@property(nonatomic) NSInteger mutagenGenerationIndex,mutagenSelected,mutagenCell,mutagenCellCount;
@property(nonatomic) BOOL mutagenBusy;
@property(nonatomic) NSUInteger mutagenRun;
@property(nonatomic) MutagenConfig mutagenConfig;
@property(nonatomic) RenderCancelToken *mutagenCancelToken;
@property(nonatomic,strong) NSButton *objectMapCombine,*objectMapEnabled;
@property(nonatomic,strong) NSArray<NSButton *> *objectColoringChoices;
@property(nonatomic,strong) NSMutableArray *customColorFavorites;
@property(nonatomic,strong) NSArray<ColorFavoriteButton *> *colorFavoriteButtons;
@property(nonatomic,strong) NSButton *addColorFavoriteButton;
@property(nonatomic,strong) NSArray<NSView *> *paletteColoringViews,*mapColoringViews;
@property(nonatomic,strong) PaletteView *strengthDiffuseBar,*strengthSpecularBar;
@property(nonatomic,strong) NSTextField *objectMapNumber;
@property(nonatomic,strong) NSImageView *objectMapPreview;
@property(nonatomic,strong) NSArray<NSTextField *> *objectMapFields;
@property(nonatomic,strong) NSArray<NSSlider *> *objectMapSliders;
@property(nonatomic,strong) NSTextField *renderSizeLabel;
@property(nonatomic) double sizeAspect,lastEditWidth;
@property(nonatomic,copy) NSString *pendingSavePath;
@property(nonatomic) BOOL savingM3I,savingAnimation;
@property(nonatomic,strong) NSMenuItem *quitMenuItem;
@property(nonatomic,strong) NSTextField *statusLabel;
@property(nonatomic,strong) NSWindow *formulasWindow;
@property(nonatomic,strong) NSButton *formulasButton,*applyFormulaButton;
@property(nonatomic,strong) NSArray<NSPopUpButton *> *powerPopups,*formulaMenus;
@property(nonatomic,strong) NSArray<NSView *> *integerGroups,*boxGroups;
@property(nonatomic,strong) NSArray<NSArray<NSTextField *> *> *boxFields;
@property(nonatomic,strong) NSArray<NSTextField *> *zMultiplierFields,*formulaCountFields;
@property(nonatomic,strong) NSTabView *formulaTabs;
@property(nonatomic,strong) NSArray<NSTabViewItem *> *formulaSlotTabs;
@property(nonatomic) NSInteger formulaClipboardMode;
@property(nonatomic,strong) NSButton *formulaInfoButton;
@property(nonatomic,strong) NSArray<NSScrollView *> *formulaInfoViews;
@property(nonatomic,strong) NSData *formulaClipboard;
@property(nonatomic,strong) NSButton *formulaMoveLeft,*formulaMoveRight;
@property(nonatomic) BOOL populatingFormulas;
@property(nonatomic,strong) NSArray<NSSlider *> *lightStrengthSliders;
@property(nonatomic,strong) NSArray<NSStepper *> *lightStrengthSteppers;
@property(nonatomic,strong) NSPopUpButton *repeatPopup;
@property(nonatomic,strong) NSTextField *formulaStatus;
@property(nonatomic) BOOL calculating,formulaKnown,parametersPendingRender;
@property(nonatomic) RenderOptions formulaSettings;
@property(nonatomic,strong) NSWindow *lightingWindow,*colorWindow;
@property(nonatomic,strong) ColorHistogramView *outsideHistogram,*insideHistogram;
@property(nonatomic,strong) NSArray<NSButton *> *histogramZoomButtons;
@property(nonatomic,strong) NSMutableDictionary<NSNumber *,NSValue *> *histogramZoomRanges;
@property(nonatomic,strong) NSData *renderColorHistograms;
@property(nonatomic,strong) PaletteView *diffuseBar,*colorDiffuseBar,*colorSpecularBar,*cuttingBar;
@property(nonatomic,strong) NSArray<NSSlider *> *cuttingColorSliders;
@property(nonatomic,strong) NSArray<NSTextField *> *cuttingColorFields;
@property(nonatomic,strong) NSPopUpButton *colorStopMenu,*objectColorsMenu;
@property(nonatomic,strong) NSPasteboard *palettePasteboard;
@property(nonatomic,strong) id colorStopKeyMonitor;
@property(nonatomic,strong) NSTextField *colorPosition,*colorStatus;
@property(nonatomic,strong) NSColorWell *colorDiffuseWell,*colorSpecularWell;
@property(nonatomic,strong) NSButton *glueColors,*updateColors;
@property(nonatomic,strong) NSArray<NSColorWell *> *randomReferences;
@property(nonatomic,strong) NSArray<NSTextField *> *randomAmounts;
@property(nonatomic,strong) NSArray<NSSlider *> *randomAmountSliders;
@property(nonatomic,strong) NSArray<NSButton *> *randomButtons;
@property(nonatomic) BOOL refreshingColors;
@property(nonatomic,strong) NSButton *internalGammaCheck;
@property(nonatomic,strong) NSButton *backPictureEnabled,*backPictureChoose;
@property(nonatomic,strong) NSArray<NSButton *> *backPictureChecks;
@property(nonatomic,strong) NSArray<NSSlider *> *backPictureSliders;
@property(nonatomic,strong) NSArray<NSTextField *> *backPictureFields;
@property(nonatomic,strong) NSTextField *backPictureFile,*backPictureStatus;
@property(nonatomic,strong) NSImageView *backPicturePreview;
@property(nonatomic,copy) NSString *backPictureName;
@property(nonatomic,strong) NSButton *lightingButton,*applyLightingButton,*cyclingCheck,*interpolationCheck,*orbitCheck;
@property(nonatomic,strong) NSPopUpButton *coloringMode;
@property(nonatomic,strong) NSSlider *gammaSlider;
@property(nonatomic,strong) NSButton *openLightingButton,*saveLightingButton,*keepLightsCheck,*resetLightingButton;
@property(nonatomic,strong) LightingUndoButton *lightingUndoButton;
@property(nonatomic,strong) NSMutableArray<NSData *> *lightingUndoHistory;
@property(nonatomic) NSInteger lightingUndoIndex;
@property(nonatomic) BOOL lightingRestoringHistory;
@property(nonatomic,strong) NSArray<NSTextField *> *objectFields,*palettePositions;
@property(nonatomic,strong) NSArray<NSSlider *> *objectSliders;
@property(nonatomic,strong) NSButton *fitColorsButton;
@property(nonatomic,strong) NSArray<NSArray<NSControl *> *> *lightControls;
@property(nonatomic,strong) NSArray<NSView *> *lightVisibilityControls;
@property(nonatomic) BOOL colorFitValid;
@property(nonatomic) int fitStart,fitEnd,trapStart,trapEnd;
@property(nonatomic,strong) NSArray<NSColorWell *> *diffuseWells,*specularWells;
@property(nonatomic,strong) NSTabView *lightSourceTabs;
@property(nonatomic,strong) NSTextField *lightingStatus;
@property(nonatomic,copy) NSArray<NSString *> *rangeBaseline;
@property(nonatomic,strong) NSWindow *postWindow;
@property(nonatomic,strong) NSArray<NSTextField *> *reflectionFields;
@property(nonatomic,strong) NSSlider *reflectionAmountSlider,*translucencyGlowSlider,*translucencyStrengthSlider;
@property(nonatomic,strong) NSButton *translucencyCheck,*subsurfaceCheck;
@property(nonatomic,strong) NSSlider *subsurfaceAmountSlider;
@property(nonatomic,strong) NSTextField *subsurfaceAmountField;
@property(nonatomic) BOOL glowPreviewBusy,glowPreviewPending,glowCacheReady;
@property(nonatomic) RenderOptions glowCacheOptions;
@property(nonatomic,copy) NSString *glowCacheSourcePath;
@property(nonatomic,strong) NSArray<NSControl *> *reflectionControls;
@property(nonatomic,strong) NSButton *reflectionAutomatic,*reflectionTransparency,*reflectionOnlyDIFS;
@property(nonatomic,strong) NSStepper *reflectionDepth;
@property(nonatomic) BOOL reflectionsApplied,resettingReflections;
@property(nonatomic,strong) NSButton *postButton,*softShadowCheck,*cosineShadowCheck;
@property(nonatomic,strong) NSArray<NSButton *> *shadowLightChecks,*shadowAutoChecks,*postButtons;
@property(nonatomic,strong) NSArray<NSTextField *> *shadowFields;
@property(nonatomic,strong) NSPopUpButton *ambientMethod;
@property(nonatomic,strong) NSArray<NSSlider *> *ambientShadowSliders;
@property(nonatomic) BOOL hardShadowsApplied,ambientShadowsApplied,resettingHardShadows,resettingAmbientShadows;
@property(nonatomic,strong) NSArray<NSArray<NSSlider *> *> *lightSliders;
@property(nonatomic) NSUInteger lightingPreviewGeneration;
@property(nonatomic) BOOL lightingPreviewPending,lightingPreviewBusy,lightingSliderTracking,lightingRepaintRequested,gammaRepaint,cuttingColorRepaintPending,preserveNavigatorForLighting;
@property(nonatomic,strong) NSWindow *navigatorWindow;
@property(nonatomic,strong) NSSegmentedControl *navigatorTabControl;
@property(nonatomic,strong) NSPopUpButton *navigatorFormulaMenu,*navigatorFormulaRange;
@property(nonatomic) NSInteger navigatorFormulaRangeChoice;
@property(nonatomic,strong) NSTextField *navigatorIterationField,*navigatorIterationLabel;
@property(nonatomic,strong) NSStepper *navigatorIterationStepper;
@property(nonatomic,strong) NSArray<NSTextField *> *navigatorFormulaLabels,*navigatorFormulaFields;
@property(nonatomic,strong) NSArray<NSButton *> *navigatorFormulaArrows;
@property(nonatomic,strong) NSButton *navigatorResetValueButton;
@property(nonatomic,copy) NSDictionary *navigatorResetTarget;
@property(nonatomic,strong) NSArray<NSSlider *> *navigatorFormulaSliders;
@property(nonatomic,strong) NSPopUpButton *formulaMode,*formulaRenderMode,*formulaCombine,*formulaSplit,*formulaRepeat2;
@property(nonatomic,strong) NSButton *formulaNumerical;
@property(nonatomic,strong) NSArray<NSTextField *> *formulaGlobalFields;
@property(nonatomic,strong) NSArray<NSArray<NSTextField *> *> *randFormulaFields;
@property(nonatomic,strong) NSArray<NSView *> *randFormulaGroups;
@property(nonatomic,copy) NSString *formulaMaxBaseline;
@property(nonatomic) RenderOptions navigatorFormulaSettings;
@property(nonatomic) NSInteger navigatorFormulaSlot;
@property(nonatomic,strong) NSButton *navigatorJuliaMode,*navigatorJuliaSphericalCheck;
@property(nonatomic,strong) NSArray<NSTextField *> *navigatorJuliaFields,*navigatorJuliaLabels;
@property(nonatomic,strong) NSArray<NSSlider *> *navigatorJuliaSliders;
@property(nonatomic,strong) NSArray<NSSlider *> *navigatorCutSliders;
@property(nonatomic,strong) NSArray<NSTextField *> *navigatorCutFields;
@property(nonatomic,strong) NSArray<NSButton *> *navigatorCutChecks;
@property(nonatomic) BOOL cuttingPicking;
@property(nonatomic,strong) NSButton *navigatorCutPickButton;
@property(nonatomic,strong) RotationTabItem *navigatorRotationTab;
@property(nonatomic,strong) NSArray<NSSlider *> *navigatorRotationSliders;
@property(nonatomic,strong) NSArray<NSTextField *> *navigatorRotationFields,*navigatorRotationLabels;

@property(nonatomic) BOOL navigatorJuliaSpherical;
@property(nonatomic,strong) NavigatorView *navigatorView;
@property(nonatomic,strong) NSButton *navigatorButton,*applyNavigatorButton;
@property(nonatomic,strong) NSArray<NSTextField *> *navigatorCameraDisplays;
@property(nonatomic,strong) NSSlider *navigatorBrightnessSlider;
@property(nonatomic,strong) NSStepper *navigatorZoomStepper;
@property(nonatomic,strong) NSTextField *moveStepField,*lookStepField,*navigatorFOVField,*navigatorStatus,*navigatorFarField;
@property(nonatomic,strong) NSButton *fixedZoomCheck;
@property(nonatomic) double navigatorLocalDistance,navigatorReferenceDistance,navigatorReferenceZoom,navigatorReferenceMove,navigatorMoveFraction;
@property(nonatomic) double navigatorDEMultiplier;
@property(nonatomic,strong) NSMutableArray<NSNumber *> *navigatorMoves;
@property(nonatomic) NSUInteger navigatorMotionEpoch;
@property(nonatomic) BOOL navigatorApplyPending,navigatorAddPending;
@property(nonatomic,strong) NSButton *navigatorAddAnimationButton;
@property(nonatomic) CameraSettings navigatorCamera;
@property(nonatomic) NSUInteger navigatorGeneration;
@property(nonatomic) RenderCancelToken *navigatorCancelToken;
@property(nonatomic) NSInteger navigatorPreviewStage;
@property(nonatomic) NSInteger navigatorRunningStage;
@property(nonatomic) NSUInteger navigatorRefinementTicket;
@property(nonatomic) BOOL navigatorSliderTracking;
@property(nonatomic) BOOL navigatorDistanceAdapted;
@property(nonatomic,strong) NSButton *navigatorExploreButton;
@property(nonatomic,strong) NSArray<NSButton *> *navigatorExploreChecks;
@property(nonatomic,strong) NSArray<NSArray<NSNumber *> *> *navigatorExploreSamples;
@property(nonatomic,strong) NSArray<NSNumber *> *navigatorExploreParameters;
@property(nonatomic,strong) NSMutableArray<NSNumber *> *navigatorExploreDigits;
@property(nonatomic) BOOL navigatorExploring,navigatorExploreNeedsDisplay;
@property(nonatomic) NSUInteger navigatorExploreTicket,navigatorExploreRun;
@property(nonatomic,strong) NSArray<NSButton *> *navigatorExploreArrows;
@property(nonatomic,strong) NSMutableArray<NSData *> *navigatorExploreHistory;
@property(nonatomic) NSInteger navigatorExploreHistoryIndex;


@property(nonatomic) BOOL previewBusy,previewPending,applyingNavigator;
@end

@implementation AppDelegate
#include "history_ui.inc"
- (void)sizeOptionsChanged:(id)sender {
    (void)sender;double width=self.calculationFields[0].doubleValue,height=self.calculationFields[1].doubleValue;
    if(width>0&&height>0)self.sizeAspect=width/height;
    [self updateRenderSizeLabel];
}
- (void)stepImageSize:(NSStepper *)sender {
    NSInteger direction=sender.integerValue;sender.integerValue=0;if(!direction||self.calculating)return;
    double values[3];NSArray *fields=@[self.calculationFields[0],self.calculationFields[1],self.calculationFields[4]];
    for(int i=0;i<3;i++){NSScanner *scan=[NSScanner scannerWithString:numericInputString(fields[i])];if(![scan scanDouble:&values[i]]||!scan.isAtEnd||!isfinite(values[i])){self.statusLabel.stringValue=@"Enter valid width, height and DE stop values before resizing.";return;}}
    if(values[0]<16||values[1]<16||values[0]>RENDER_MAX_DIMENSION||values[1]>RENDER_MAX_DIMENSION||values[0]!=floor(values[0])||values[1]!=floor(values[1])){self.statusLabel.stringValue=@"Width and height must be integers from 16 to 16384.";return;}
    double factor=direction>0?2:.5;NSInteger width=lround(values[0]*factor),height=lround(values[1]*factor),sampling=self.oversamplingMenu.indexOfSelectedItem+1;
    if(width<16||height<16||width*sampling>RENDER_MAX_DIMENSION||height*sampling>RENDER_MAX_DIMENSION){self.statusLabel.stringValue=@"Cannot resize beyond the image dimension limits, including oversampling.";return;}
    double de=values[2];if(self.scaleDECheck.state==NSControlStateValueOn){de*=width/values[0];if(de<1e-6||de*sampling>100){self.statusLabel.stringValue=@"DEStop+C would exceed the supported DE stop range.";return;}}
    self.calculationFields[0].integerValue=width;self.calculationFields[1].integerValue=height;
    if(self.scaleDECheck.state==NSControlStateValueOn)self.calculationFields[4].stringValue=[NSString stringWithFormat:@"%.17g",de];
    self.actualSizeNeedsRender=YES;self.lastEditWidth=width;self.sizeAspect=(double)width/height;[self updateRenderSizeLabel];
    self.statusLabel.stringValue=[NSString stringWithFormat:@"Image size %ld × %ld. Press Render to calculate.",(long)width,(long)height];
}
- (void)updateRenderSizeLabel {
    int n=(int)self.oversamplingMenu.indexOfSelectedItem+1;
    self.renderSizeLabel.stringValue=[NSString stringWithFormat:@"Render %d × %d",self.calculationFields[0].intValue*n,self.calculationFields[1].intValue*n];
    [self updateActualSizeAvailability];
}
- (void)updateActualSizeAvailability {
    if(self.completedOutputWidth>0&&(self.calculationFields[0].doubleValue!=self.completedOutputWidth||self.calculationFields[1].doubleValue!=self.completedOutputHeight))self.actualSizeNeedsRender=YES;
    self.displayActualSizeButton.enabled=!self.calculating&&self.completedRender&&self.completedOutputWidth>0&&!self.actualSizeNeedsRender;
}
- (void)controlTextDidChange:(NSNotification *)notification {
    if(notification.object==self.stepcountField||(self.calculationFields.count>3&&(notification.object==self.calculationFields[2]||notification.object==self.calculationFields[3])))[self syncCalculationSteppers];
    NSTextField *field=notification.object;
    if([self.animationFields containsObject:field]){[self updateAnimationPreviewEstimate];return;}
    if([self.formulaCountFields containsObject:field]){[self refreshFormulaTabLabels];return;}
    if(field==self.navigatorIterationField) {
        double count;NSScanner *scanner=[NSScanner scannerWithString:numericInputString(field)];
        if([scanner scanDouble:&count]&&scanner.isAtEnd&&isfinite(count)&&(self.navigatorFormulaSettings.program.mode==1||count==floor(count))&&count>=0&&count<=10000)self.navigatorIterationStepper.doubleValue=count;
        return;
    }
    if(field==self.calculationFields[0]||field==self.calculationFields[1])[self updateSizeFromField:field];
}
- (void)updateSizeFromField:(NSTextField *)field {
    self.actualSizeNeedsRender=YES;[self updateActualSizeAvailability];
    double value;NSScanner *scanner=[NSScanner scannerWithString:numericInputString(field)];
    if(![scanner scanDouble:&value]||!scanner.isAtEnd||!isfinite(value)||value<16||value>RENDER_MAX_DIMENSION||floor(value)!=value)return;
    double width=self.calculationFields[0].doubleValue,height=self.calculationFields[1].doubleValue;
    if(self.keepAspectCheck.state==NSControlStateValueOn&&self.sizeAspect>0) {
        if(field==self.calculationFields[0])height=lround(width/self.sizeAspect);else width=lround(height*self.sizeAspect);
        if(width<16||height<16||width>RENDER_MAX_DIMENSION||height>RENDER_MAX_DIMENSION)return;
        self.calculationFields[0].stringValue=[NSString stringWithFormat:@"%.0f",width];self.calculationFields[1].stringValue=[NSString stringWithFormat:@"%.0f",height];
    }
    if(width>=16&&height>=16&&self.lastEditWidth>0&&self.scaleDECheck.state==NSControlStateValueOn) {
        double de=self.calculationFields[4].doubleValue*width/self.lastEditWidth;
        self.calculationFields[4].stringValue=[NSString stringWithFormat:@"%.17g",de];
    }
    self.lastEditWidth=width;[self updateRenderSizeLabel];
}
- (void)saveM3I:(id)sender {
    (void)sender;if(self.calculating)return;[self.window makeFirstResponder:nil];RenderOptions options;if(![self readMainSettings:&options sender:nil])return;
    NSSavePanel *panel=[NSSavePanel savePanel];panel.allowedFileTypes=@[@"m3i"];panel.canCreateDirectories=YES;panel.nameFieldStringValue=(self.currentPath&&![self.clipboardScenes containsObject:self.currentPath]&&![self.currentPath.stringByDeletingLastPathComponent isEqual:self.renderHistory.directory])?[[self.currentPath.lastPathComponent stringByDeletingPathExtension] stringByAppendingPathExtension:@"m3i"]:[APP_TITLE stringByAppendingPathExtension:@"m3i"];
    restoreDialogLocation(panel,NO,@"m3i",panel.nameFieldStringValue);
    SaveFileExtensionDelegate *extensionDelegate=[SaveFileExtensionDelegate new];
    panel.delegate=extensionDelegate;
    [panel beginSheetModalForWindow:self.window completionHandler:^(NSModalResponse response){
        if(panel.delegate==extensionDelegate)panel.delegate=nil;
        if(response==NSModalResponseOK){rememberDialogURL(panel.URL,NO);[self saveM3IParametersTo:panel.URL.path options:options];}
    }];
}
- (void)saveM3IParametersTo:(NSString *)destination options:(RenderOptions)options {
    if(self.calculating)return;NSString *source=self.currentPath,*temporary=[[self applicationTemporaryFolderURL].path stringByAppendingPathComponent:[@"scene-save-" stringByAppendingString:NSUUID.UUID.UUIDString]];
    render_cancel(self.navigatorCancelToken);self.navigatorGeneration++;self.navigatorRefinementTicket++;self.previewPending=NO;self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;NSUInteger generation=++self.generation;
    self.savingM3I=YES;self.quitMenuItem.enabled=NO;
    [self setCalculating:YES];self.statusLabel.stringValue=@"Saving .m3i parameters…";
    NSImageRep *shown=self.imageView.image.representations.firstObject;
    NSBitmapImageRep *preview=[shown isKindOfClass:NSBitmapImageRep.class]?(NSBitmapImageRep *)shown:self.completedRender;
    dispatch_async(self.renderQueue,^{char error[512];BOOL ok=write_scene_parameters_with_preview(source.fileSystemRepresentation,options,temporary.fileSystemRepresentation,preview.bitmapData,(int)preview.pixelsWide,(int)preview.pixelsHigh,(size_t)preview.bytesPerRow,error);if(ok){NSError *saveError=nil;if(!installUserFile(temporary,destination,&saveError)){snprintf(error,sizeof error,"Could not save .m3i: %s",saveError.localizedDescription.UTF8String?:"File replacement failed");ok=NO;}}if(!ok)unlink(temporary.fileSystemRepresentation);NSString *message=ok?nil:[NSString stringWithUTF8String:error];
        interactiveUI(^{if(generation!=self.generation){self.savingM3I=NO;self.quitMenuItem.enabled=YES;return;}[self setCalculating:NO];if(ok){retainUserFileSelection([NSURL fileURLWithPath:destination]);self.currentPath=destination;scheduleSceneFinderPreview(destination,preview);self.statusLabel.stringValue=preview?@"Saved .m3i parameters with embedded preview. Image unchanged.":@"Saved .m3i parameters. No rendered preview is available.";}else{self.statusLabel.stringValue=message;[self showFileError:@"Could not save .m3i" message:message];}self.savingM3I=NO;self.quitMenuItem.enabled=YES;});
    });
}

- (void)showFileError:(NSString *)title message:(NSString *)message {
    NSAlert *alert=[NSAlert new];alert.alertStyle=NSAlertStyleCritical;alert.messageText=title;alert.informativeText=message;[alert addButtonWithTitle:@"OK"];[alert beginSheetModalForWindow:self.window completionHandler:nil];
}
- (void)saveToClipboard:(id)sender {
    (void)sender;if(self.calculating)return;[self.window makeFirstResponder:nil];RenderOptions options;if(![self readMainSettings:&options sender:nil])return;
    NSString *source=self.currentPath;[self setCalculating:YES];
    dispatch_async(self.renderQueue,^{char error[512],*text=NULL;BOOL ok=export_clipboard_scene(source.fileSystemRepresentation,options,&text,error);NSString *parameters=ok?[NSString stringWithUTF8String:text]:nil;free(text);NSString *message=ok?nil:[NSString stringWithUTF8String:error];
        interactiveUI(^{[self setCalculating:NO];if(parameters){NSPasteboard *pasteboard=NSPasteboard.generalPasteboard;[pasteboard clearContents];[pasteboard setString:parameters forType:NSPasteboardTypeString];self.statusLabel.stringValue=@"Parameters copied to clipboard. Image unchanged.";}else [self showFileError:@"Cannot save to clipboard" message:message?:@"Could not encode parameters."];});
    });
}
- (void)openFromClipboard:(id)sender {
    (void)sender;if(self.calculating)return;
    NSString *text=[NSPasteboard.generalPasteboard stringForType:NSPasteboardTypeString];
    if(!text.length){[self showFileError:@"Cannot import clipboard" message:@"The clipboard contains no text parameters."];return;}
    if(text.length>1048576){[self showFileError:@"Cannot import clipboard" message:@"The clipboard text is too large."];return;}
    NSString *path=[[self applicationTemporaryFolderURL].path stringByAppendingPathComponent:[NSString stringWithFormat:@"Mandelbulb3Dx-Clipboard-%@.m3i",NSUUID.UUID.UUIDString]];
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(finishLightingSlider) object:nil];
    self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;
    render_cancel(self.navigatorCancelToken);self.navigatorGeneration++;self.previewPending=NO;self.navigatorApplyPending=NO;self.navigatorAddPending=NO;self.navigatorMotionEpoch++;[self.navigatorMoves removeAllObjects];
    NSUInteger importGeneration=++self.generation;
    [self setCalculating:YES];self.statusLabel.stringValue=@"Checking clipboard parameters…";
    dispatch_async(self.renderQueue,^{
        char error[512];RenderOptions settings={0};BOOL ok=import_clipboard_scene(text.UTF8String,path.fileSystemRepresentation,error);if(ok)ok=read_scene_settings(path.fileSystemRepresentation,&settings,error);
        NSString *message=ok?nil:[NSString stringWithUTF8String:error];
        dispatch_async(dispatch_get_main_queue(),^{
            if(importGeneration!=self.generation){[NSFileManager.defaultManager removeItemAtPath:path error:nil];return;}
            [self setCalculating:NO];
            if(!ok){self.statusLabel.stringValue=@"Clipboard import failed. Current render is unchanged.";[self showFileError:@"Cannot import clipboard" message:message?message:@"Invalid clipboard parameters."];return;}
            if(!self.clipboardScenes)self.clipboardScenes=[NSMutableSet set];[self.clipboardScenes addObject:path];
            [self loadClipboardSettings:settings path:path];
        });
    });
}
- (void)loadClipboardSettings:(RenderOptions)settings path:(NSString *)path {
    [self loadParameterSettings:settings path:path source:@"Clipboard"];
}
- (void)loadParameterSettings:(RenderOptions)settings path:(NSString *)path source:(NSString *)source {
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(finishLightingSlider) object:nil];
    self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;
    render_cancel(self.navigatorCancelToken);self.navigatorGeneration++;self.navigatorRefinementTicket++;self.previewPending=NO;self.navigatorApplyPending=NO;self.navigatorAddPending=NO;self.navigatorMotionEpoch++;[self.navigatorMoves removeAllObjects];self.generation++;
    self.parametersPendingRender=YES;self.glowCacheReady=NO;self.glowPreviewPending=NO;[self syncTransparencyControls];self.currentPath=path;self.formulaKnown=YES;self.formulaSettings=settings;
    self.colorFitValid=NO;self.navigatorLocalDistance=0;
    [self resetNavigator];[self populateObjectLighting];[self populateShadowSettings];[self populateFormulaWindow];
    int n=MAX(1,settings.oversampling);[self.oversamplingMenu selectItemAtIndex:n-1];
    self.keepAspectCheck.state=(settings.size_flags&1)!=0;self.scaleDECheck.state=(settings.size_flags&2)!=0;
    self.lastEditWidth=settings.width/n;self.sizeAspect=(double)settings.width/settings.height;
    NSArray *values=@[[NSString stringWithFormat:@"%d",settings.width/n],[NSString stringWithFormat:@"%d",settings.height/n],[NSString stringWithFormat:@"%d",settings.threads],[NSString stringWithFormat:@"%d",settings.normal_smoothing],[NSString stringWithFormat:@"%.17g",settings.de_stop/n],[NSString stringWithFormat:@"%.17g",settings.ray_step]];
    for(NSUInteger i=0;i<values.count;i++)self.calculationFields[i].stringValue=values[i];[self populatePosition];[self populateStepcount];
    [self updateRenderSizeLabel];[self setCalculating:NO];
    NSString *message=[NSString stringWithFormat:@"%@ parameters loaded. Edit settings, then press Render.",source];
    self.statusLabel.stringValue=message;self.formulaStatus.stringValue=message;self.lightingStatus.stringValue=message;self.navigatorStatus.stringValue=message;
    self.window.title=[NSString stringWithFormat:@"%@ — %@",APP_TITLE,path.lastPathComponent?:source];
    settings.reuse_surface=0;[self beginRenderPath:path options:settings];
}
- (NSBitmapImageRep *)resolvedExportBitmap {
    NSBitmapImageRep *bitmap=self.completedRender;int sampling=MAX(1,self.formulaSettings.oversampling);if(!bitmap||sampling==1)return bitmap;
    RenderResult result={.rgba=bitmap.bitmapData,.width=(int)bitmap.pixelsWide,.height=(int)bitmap.pixelsHigh,.stride=(size_t)bitmap.bytesPerRow};NSImage *image=animationResolvedImage(result,sampling);return (NSBitmapImageRep *)image.representations.firstObject;
}
- (void)exportPNG:(id)sender {
    (void)sender;if(self.calculating||!self.completedRender)return;
    NSBitmapImageRep *bitmap=[self resolvedExportBitmap];if(!bitmap){self.statusLabel.stringValue=@"Could not resolve oversampled image.";return;}NSSavePanel *panel=[NSSavePanel savePanel];panel.allowedFileTypes=@[@"png"];panel.canCreateDirectories=YES;
    NSString *name=(self.currentPath&&![self.clipboardScenes containsObject:self.currentPath]&&![self.currentPath.stringByDeletingLastPathComponent isEqual:self.renderHistory.directory])?self.currentPath.lastPathComponent.stringByDeletingPathExtension:APP_TITLE;panel.nameFieldStringValue=[name stringByAppendingPathExtension:@"png"];restoreDialogLocation(panel,NO,@"png",panel.nameFieldStringValue);
    SaveFileExtensionDelegate *extensionDelegate=[SaveFileExtensionDelegate new];
    panel.delegate=extensionDelegate;
    [panel beginSheetModalForWindow:self.window completionHandler:^(NSModalResponse response){
        if(panel.delegate==extensionDelegate)panel.delegate=nil;
        if(response!=NSModalResponseOK)return;
        rememberDialogURL(panel.URL,NO);
        NSData *png=[bitmap representationUsingType:NSBitmapImageFileTypePNG properties:@{}];NSError *error=nil;
        if(!png||![png writeToURL:panel.URL options:NSDataWritingAtomic error:&error]){[self showFileError:@"PNG export failed" message:error.localizedDescription?error.localizedDescription:@"Could not encode the render as PNG."];return;}
        retainUserFileSelection(panel.URL);self.statusLabel.stringValue=[NSString stringWithFormat:@"Exported %@ (%ld × %ld).",panel.URL.lastPathComponent,(long)bitmap.pixelsWide,(long)bitmap.pixelsHigh];
    }];
}
- (void)applicationWillTerminate:(NSNotification *)notification {
    if(self.colorStopKeyMonitor){[NSEvent removeMonitor:self.colorStopKeyMonitor];self.colorStopKeyMonitor=nil;}
    releaseUserFileScopes();
    [self.renderHistory close];
    [self clearAnimationPlayback];
    for(NSString *path in self.animationTemporarySources)[NSFileManager.defaultManager removeItemAtPath:path error:nil];
    (void)notification;for(NSString *path in self.clipboardScenes)[NSFileManager.defaultManager removeItemAtPath:path error:nil];
}
- (void)fullSize:(id)sender {
    (void)sender;[self updateActualSizeAvailability];if(!self.displayActualSizeButton.enabled||!self.imageView.image||!self.completedRender)return;
    NSScreen *screen=self.window.screen?self.window.screen:NSScreen.mainScreen;
    CGFloat backing=MAX(1,self.window.backingScaleFactor);
    NSSize imageSize=NSMakeSize(self.completedOutputWidth/backing,self.completedOutputHeight/backing);
    NSSize contentSize=NSMakeSize(MAX(self.window.contentMinSize.width,304+imageSize.width),MAX(self.window.contentMinSize.height,imageSize.height));
    NSRect frame=[self.window frameRectForContentRect:NSMakeRect(0,0,contentSize.width,contentSize.height)];
    NSRect visible=screen.visibleFrame;BOOL limited=frame.size.width>visible.size.width||frame.size.height>visible.size.height;
    frame.size.width=MIN(frame.size.width,visible.size.width);frame.size.height=MIN(frame.size.height,visible.size.height);
    frame.origin.x=MAX(NSMinX(visible),MIN(self.window.frame.origin.x,NSMaxX(visible)-frame.size.width));
    frame.origin.y=MAX(NSMinY(visible),MIN(NSMaxY(self.window.frame)-frame.size.height,NSMaxY(visible)-frame.size.height));
    [self.window setFrame:frame display:YES];
    self.imageView.image.size=imageSize;self.imageView.imageScaling=NSImageScaleProportionallyDown;
    self.statusLabel.stringValue=limited?@"Image exceeds the screen; displayed at the largest size that fits.":@"Actual Size: one output pixel per screen pixel.";
}
- (void)windowDidResize:(NSNotification *)notification {
    if(notification.object==self.window)self.imageView.imageScaling=NSImageScaleProportionallyUpOrDown;
}
- (void)ensureWindow {
    if(self.window)return;
    restoreUserFileScopes();
    NSString *legacyHistory=[NSTemporaryDirectory() stringByAppendingPathComponent:[HISTORY_STORE_NAME stringByAppendingString:@"-RenderHistory"]];
    setenv("MB3DX_MAP_DIR",[self applicationMapsFolderURL].fileSystemRepresentation,1);
    setenv("MB3DX_BACKGROUND_DIR",[self applicationBackgroundsFolderURL].fileSystemRepresentation,1);
    setenv("MB3DX_TEMP_DIR",[self applicationTemporaryFolderURL].fileSystemRepresentation,1);
    setenv("TMPDIR",[self applicationTemporaryFolderURL].fileSystemRepresentation,1);
    NSURL *cache=[[[[self applicationMapsFolderURL] URLByDeletingLastPathComponent] URLByDeletingLastPathComponent] URLByDeletingLastPathComponent];
    cache=[[cache URLByAppendingPathComponent:@"Caches" isDirectory:YES] URLByAppendingPathComponent:@"Mandelbulb3D SE" isDirectory:YES];setenv("XDG_CACHE_HOME",cache.fileSystemRepresentation,1);
    NSError *assetFolderError=nil;
    for(NSURL *folder in @[[self applicationMapsFolderURL],[self applicationBackgroundsFolderURL],[self applicationTemporaryFolderURL],cache])
        if(![NSFileManager.defaultManager createDirectoryAtURL:folder withIntermediateDirectories:YES attributes:nil error:&assetFolderError])break;
    if(!assetFolderError)installDefaultMapFiles([NSBundle.mainBundle.resourceURL URLByAppendingPathComponent:@"DefaultMaps" isDirectory:YES],[self applicationMapsFolderURL],&assetFolderError);
    NSString *historyFolder=[[self applicationTemporaryFolderURL].path stringByAppendingPathComponent:[HISTORY_STORE_NAME stringByAppendingString:@"-RenderHistory"]];
    [self migrateHistoryFrom:legacyHistory to:historyFolder];
    self.renderQueue=dispatch_queue_create("org.codex.integer-power.render",DISPATCH_QUEUE_SERIAL);
    NSRect frame=NSMakeRect(0,0,1000,700);
    self.window=[[MainTitleWindow alloc] initWithContentRect:frame
        styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable|NSWindowStyleMaskMiniaturizable|NSWindowStyleMaskResizable
        backing:NSBackingStoreBuffered defer:NO];
    self.window.releasedWhenClosed=NO;
    self.window.delegate=self;
    self.window.backgroundColor=[NSColor colorWithSRGBRed:.035 green:.05 blue:.075 alpha:1];
    self.window.contentMinSize=NSMakeSize(800,700);
    self.window.title=APP_TITLE;[(MainTitleWindow *)self.window installAppIdentity];
#ifdef USE_RUST_ENGINE
    render_set_rust_assets([[NSBundle.mainBundle.resourcePath stringByAppendingPathComponent:@"M3Formulas"] fileSystemRepresentation]);
#endif
    self.imageView=[[FractalView alloc] initWithFrame:NSMakeRect(0,0,696,700)];
    self.imageView.autoresizingMask=NSViewWidthSizable|NSViewHeightSizable;
    __weak AppDelegate *weakSelf=self;
    self.placingLight=-1;self.imageView.placeLight=^(NSPoint point){[weakSelf placeLightAt:point];};
    self.imageView.openScene=^(NSString *path){[weakSelf renderPath:path];};
    NSView *root=[[NSView alloc] initWithFrame:frame];
    [root addSubview:self.imageView];
    CalculationPanel *panel=[[CalculationPanel alloc]initWithFrame:NSMakeRect(708,12,280,676)];panel.autoresizingMask=NSViewMinXMargin|NSViewHeightSizable;
    NSTabView *tabs=[[NSTabView alloc]initWithFrame:NSMakeRect(0,472,280,160)];tabs.controlSize=NSControlSizeSmall;tabs.font=[NSFont systemFontOfSize:12];
    NSTabViewItem *tab=[[NSTabViewItem alloc]initWithIdentifier:@"calculation"];tab.label=@"Calc";
    CalculationPanel *calculationPanel=[[CalculationPanel alloc]initWithFrame:NSMakeRect(0,0,260,130)];
    CalculationPanel *settingsPanel=[[CalculationPanel alloc]initWithFrame:NSMakeRect(0,0,260,130)];
    NSArray *labels=@[@"Image width (px)",@"Image height (px)",@"CPU Thread (0=auto)",@"Smooth normals",@"DE Stop",@"Raystep multiplier"];
    NSArray *values=@[@"480",@"360",@"0",@"0",@"0.5",@"0.5"];
    NSArray *tips=@[@"Pixels, 16–16384",@"Pixels, 16–16384",@"0 = automatic; otherwise 1–256",@"Normal smoothing, integer 0–15",@"Surface threshold, 0.000001–100; smaller adds detail",@"Distance step factor, 0.000001–1; smaller is slower"];
    NSMutableArray *fields=[NSMutableArray array];
    for(NSUInteger i=0;i<labels.count;i++) {
        NSTextField *label=[NSTextField labelWithString:labels[i]];
        NSView *container=i<2?panel:i==2?settingsPanel:calculationPanel;
        CGFloat rows[]={0,0,0,2,0,1};CGFloat y=i<2?14+i*34:4+rows[i]*30;
        label.frame=NSMakeRect(10,y+4,148,22);label.font=[NSFont systemFontOfSize:12];label.textColor=NSColor.labelColor;
        [container addSubview:label];
        NSTextField *field=[[NumericTextField alloc] initWithFrame:NSMakeRect(162,y,i==0?66:(i==2||i==3)?64:88,26)];
        numericIntegerField(field,i<4);field.stringValue=values[i];field.toolTip=tips[i];
        field.accessibilityLabel=labels[i];field.target=self;field.action=@selector(calculate:);if(i<4)field.delegate=self;
        [container addSubview:field];[fields addObject:field];
    }
    NSTextField *stepLabel=[NSTextField labelWithString:@"Stepcount"];stepLabel.font=[NSFont systemFontOfSize:12];stepLabel.frame=NSMakeRect(10,98,148,22);[calculationPanel addSubview:stepLabel];
    self.stepcountField=[[NumericTextField alloc]initWithFrame:NSMakeRect(162,94,64,26)];numericIntegerField(self.stepcountField,YES);self.stepcountField.stringValue=@"8";self.stepcountField.accessibilityLabel=@"Stepcount";self.stepcountField.toolTip=@"Stepcount for binary search, integer 0–31.";self.stepcountField.target=self;self.stepcountField.action=@selector(calculate:);self.stepcountField.delegate=self;[calculationPanel addSubview:self.stepcountField];
    NSMutableArray *integerSteppers=[NSMutableArray array];int indices[]={2,3,6};double limits[]={256,15,31};
    for(int j=0;j<3;j++){NSStepper *step=[[NSStepper alloc]initWithFrame:NSMakeRect(232,j==0?3:j==1?63:93,19,28)];step.minValue=0;step.maxValue=limits[j];step.increment=1;step.tag=indices[j];step.target=self;step.action=@selector(calculationStepped:);step.accessibilityLabel=j==0?@"CPU Thread stepper":j==1?@"Smooth normals stepper":@"Stepcount stepper";[(j==0?settingsPanel:calculationPanel) addSubview:step];[integerSteppers addObject:step];}self.calculationSteppers=integerSteppers;
#ifdef USE_RUST_ENGINE
    self.cpuOnlyCheck=[NSButton checkboxWithTitle:@"CPU only" target:self action:@selector(cpuOnlyChanged:)];self.cpuOnlyCheck.frame=NSMakeRect(10,104,240,22);self.cpuOnlyCheck.toolTip=@"Disable GPU acceleration for rendering and post-processing. Applies to subsequent renders; press Render for a full comparison.";self.cpuOnlyCheck.hidden=YES;[settingsPanel addSubview:self.cpuOnlyCheck];mb3dx_rust_set_cpu_only(0);
#endif
    self.calculationFields=fields;self.lastEditWidth=480;self.sizeAspect=4./3;
    self.imageSizeStepper=[[NSStepper alloc]initWithFrame:NSMakeRect(232,13,19,28)];self.imageSizeStepper.minValue=-1;self.imageSizeStepper.maxValue=1;self.imageSizeStepper.increment=1;self.imageSizeStepper.integerValue=0;self.imageSizeStepper.target=self;self.imageSizeStepper.action=@selector(stepImageSize:);self.imageSizeStepper.accessibilityLabel=@"Double or halve image dimensions";self.imageSizeStepper.toolTip=@"Up doubles both width and height; down halves both. DEStop+C follows the size change.";[panel addSubview:self.imageSizeStepper];

    self.keepAspectCheck=[NSButton checkboxWithTitle:@"Keep aspect" target:self action:@selector(sizeOptionsChanged:)];self.keepAspectCheck.frame=NSMakeRect(10,80,130,24);self.keepAspectCheck.state=NSControlStateValueOn;[panel addSubview:self.keepAspectCheck];
    self.scaleDECheck=[NSButton checkboxWithTitle:@"DEStop+C" target:nil action:nil];self.scaleDECheck.frame=NSMakeRect(142,80,112,24);self.scaleDECheck.state=NSControlStateValueOn;self.scaleDECheck.toolTip=@"Scale DE stop with width to preserve detail/colors (DoF focus depths retain their normalized units).";[panel addSubview:self.scaleDECheck];
    NSTextField *samplingLabel=[NSTextField labelWithString:@"Oversampling"];samplingLabel.frame=NSMakeRect(10,182,140,22);[panel addSubview:samplingLabel];
    self.oversamplingMenu=[[NSPopUpButton alloc]initWithFrame:NSMakeRect(162,176,88,28) pullsDown:NO];for(int n=1;n<=6;n++)[self.oversamplingMenu addItemWithTitle:[NSString stringWithFormat:@"%d×",n]];
    self.oversamplingMenu.target=self;self.oversamplingMenu.action=@selector(sizeOptionsChanged:);self.oversamplingMenu.accessibilityLabel=@"Oversampling";[panel addSubview:self.oversamplingMenu];
    self.renderSizeLabel=[NSTextField labelWithString:@""];self.renderSizeLabel.frame=NSMakeRect(10,204,244,18);self.renderSizeLabel.font=[NSFont systemFontOfSize:10];[panel addSubview:self.renderSizeLabel];[self updateRenderSizeLabel];
    self.renderButton=[NSButton buttonWithTitle:@"Render" target:self action:@selector(calculate:)];
    self.renderButton.frame=NSMakeRect(10,144,118,28);self.renderButton.keyEquivalent=@"\r";
    [panel addSubview:self.renderButton];
    if(!self.renderHistory)self.renderHistory=[[RenderHistoryStore alloc]initWithDirectory:[[self applicationTemporaryFolderURL].path stringByAppendingPathComponent:[HISTORY_STORE_NAME stringByAppendingString:@"-RenderHistory"]]];
    self.historyMenu=[[NSPopUpButton alloc]initWithFrame:NSMakeRect(136,144,118,28) pullsDown:YES];[self.historyMenu addItemWithTitle:@"History"];self.historyMenu.menu.delegate=self;self.historyMenu.menu.autoenablesItems=NO;self.historyMenu.accessibilityLabel=@"Render history";self.historyMenu.toolTip=@"Restore one of the last 50 completed main renders. History is retained when the app quits or crashes.";[panel addSubview:self.historyMenu];
    self.stopButton=[NSButton buttonWithTitle:@"Stop" target:self action:@selector(stopRender:)];self.stopButton.frame=self.renderButton.frame;self.stopButton.enabled=NO;self.stopButton.hidden=YES;[panel addSubview:self.stopButton];
    self.saveButton=[NSButton buttonWithTitle:@"Save..." target:self action:@selector(saveM3I:)];self.saveButton.frame=NSMakeRect(94,380,80,28);self.saveButton.font=[NSFont systemFontOfSize:12];[panel addSubview:self.saveButton];
    self.pngButton=[NSButton buttonWithTitle:@"Export .png" target:self action:@selector(exportPNG:)];self.pngButton.frame=NSMakeRect(178,380,96,28);self.pngButton.font=[NSFont systemFontOfSize:12];self.pngButton.enabled=NO;[panel addSubview:self.pngButton];
    self.clipboardButton=[NSButton buttonWithTitle:@"Open from clipboard" target:self action:@selector(openFromClipboard:)];self.clipboardButton.frame=NSMakeRect(10,348,142,28);self.clipboardButton.font=[NSFont systemFontOfSize:11];self.clipboardButton.controlSize=NSControlSizeSmall;[panel addSubview:self.clipboardButton];
    self.saveClipboardButton=[NSButton buttonWithTitle:@"Save to clipboard" target:self action:@selector(saveToClipboard:)];self.saveClipboardButton.frame=NSMakeRect(156,348,118,28);self.saveClipboardButton.font=[NSFont systemFontOfSize:11];self.saveClipboardButton.controlSize=NSControlSizeSmall;[panel addSubview:self.saveClipboardButton];
    NSBox *renderDivider=[[NSBox alloc]initWithFrame:NSMakeRect(10,240,244,1)];renderDivider.boxType=NSBoxSeparator;[panel addSubview:renderDivider];
    self.formulasButton=[NSButton buttonWithTitle:@"Formulas…" target:self action:@selector(showFormulas:)];
    self.formulasButton.frame=NSMakeRect(10,244,128,28);
    [panel addSubview:self.formulasButton];
    self.lightingButton=[NSButton buttonWithTitle:@"Lighting…" target:self action:@selector(showLighting:)];
    self.lightingButton.frame=NSMakeRect(144,244,130,28);[panel addSubview:self.lightingButton];
    self.navigatorButton=[NSButton buttonWithTitle:@"Navigator…" target:self action:@selector(showNavigator:)];
    self.navigatorButton.frame=NSMakeRect(10,276,128,28);[panel addSubview:self.navigatorButton];
    self.postButton=[NSButton buttonWithTitle:@"Post-process…" target:self action:@selector(showPostProcess:)];
    self.postButton.frame=NSMakeRect(144,276,130,28);[panel addSubview:self.postButton];
    self.animationButton=[NSButton buttonWithTitle:@"Animation…" target:self action:@selector(showAnimation:)];self.animationButton.frame=NSMakeRect(10,308,128,28);[panel addSubview:self.animationButton];
    self.mutagenButton=[NSButton buttonWithTitle:@"Mutagen…" target:self action:@selector(showMutagen:)];self.mutagenButton.frame=NSMakeRect(144,308,130,28);[panel addSubview:self.mutagenButton];
    self.openM3IButton=[NSButton buttonWithTitle:@"Open..." target:self action:@selector(openM3I:)];self.openM3IButton.frame=NSMakeRect(10,380,80,28);self.openM3IButton.font=[NSFont systemFontOfSize:12];[panel addSubview:self.openM3IButton];
    NSBox *animationDivider=[[NSBox alloc]initWithFrame:NSMakeRect(10,340,264,1)];animationDivider.boxType=NSBoxSeparator;[panel addSubview:animationDivider];
    NSBox *mapsDivider=[[NSBox alloc]initWithFrame:NSMakeRect(10,414,264,1)];mapsDivider.boxType=NSBoxSeparator;[panel addSubview:mapsDivider];
    NSButton *maps=[NSButton buttonWithTitle:@"Open Map Folder" target:self action:@selector(openMapFolder:)];maps.frame=NSMakeRect(10,422,130,28);maps.font=[NSFont systemFontOfSize:11];[panel addSubview:maps];
    NSButton *backgrounds=[NSButton buttonWithTitle:@"Open Bkgnd Folder" target:self action:@selector(openBackgroundsFolder:)];backgrounds.frame=NSMakeRect(144,422,130,28);backgrounds.font=[NSFont systemFontOfSize:11];[panel addSubview:backgrounds];
    NSButton *fullSize=[NSButton buttonWithTitle:@"Display Actual Size" target:self action:@selector(fullSize:)];self.displayActualSizeButton=fullSize;fullSize.enabled=NO;fullSize.frame=NSMakeRect(10,112,244,28);fullSize.toolTip=@"Size the window for one output pixel per screen pixel, excluding oversampling. Limited to the available screen. You can still resize the window normally.";[panel addSubview:fullSize];
    self.statusLabel=[NSTextField wrappingLabelWithString:@"Settings are applied when you render."];
    self.renderProgressPie=[[RenderProgressPie alloc]initWithFrame:NSMakeRect(10,640,18,18)];self.renderProgressPie.hidden=YES;self.renderProgressPie.accessibilityLabel=@"Render progress";[panel addSubview:self.renderProgressPie];
    self.statusLabel.frame=NSMakeRect(34,638,240,36);self.statusLabel.font=[NSFont systemFontOfSize:11];
    self.statusLabel.textColor=NSColor.secondaryLabelColor;[panel addSubview:self.statusLabel];
    tab.view=calculationPanel;[tabs addTabViewItem:tab];[self addPositionTab:tabs];[self addInfoTab:tabs];NSTabViewItem *settingsTab=[[NSTabViewItem alloc]initWithIdentifier:@"settings"];settingsTab.label=@"Settings";settingsTab.view=settingsPanel;[tabs addTabViewItem:settingsTab];[panel addSubview:tabs];[root addSubview:panel];
    self.window.contentView=root;
    [self.window center];
    [self.window makeKeyAndOrderFront:nil];
    if(assetFolderError)[self showFileError:@"Could not create asset folders" message:assetFolderError.localizedDescription];
}
#include "animation_ui.inc"
#include "animation_processing.inc"
#include "m3a_ui.inc"
- (void)populateStepcount {
    RenderOptions o=self.formulaSettings;int value=o.stepcount_override?(int)o.stepcount:o.preserved_header_valid?MIN(31,o.preserved_header[134]):8;
    self.stepcountField.integerValue=value;[self syncCalculationSteppers];
}
- (void)syncCalculationSteppers {
    for(NSStepper *step in self.calculationSteppers){NSTextField *field=step.tag==6?self.stepcountField:self.calculationFields[step.tag];step.doubleValue=fmax(step.minValue,fmin(step.maxValue,field.doubleValue));}
}
- (void)calculationStepped:(NSStepper *)sender {
    NSTextField *field=sender.tag==6?self.stepcountField:self.calculationFields[sender.tag];field.integerValue=sender.integerValue;
}
- (void)cpuOnlyChanged:(NSButton *)sender {
#ifdef USE_RUST_ENGINE
    mb3dx_rust_set_cpu_only(sender.state==NSControlStateValueOn);
    self.statusLabel.stringValue=sender.state==NSControlStateValueOn?@"CPU only enabled. Press Render to render entirely on the CPU.":@"Automatic GPU acceleration enabled. Press Render to render again.";
#else
    (void)sender;
#endif
}
- (void)addInfoTab:(NSTabView *)tabs {
    NSTabViewItem *tab=[[NSTabViewItem alloc]initWithIdentifier:@"info"];tab.label=@"Info";
    NSScrollView *scroll=[[NSScrollView alloc]initWithFrame:NSMakeRect(0,0,260,130)];scroll.hasVerticalScroller=YES;scroll.autoresizingMask=NSViewWidthSizable|NSViewHeightSizable;
    NSTextView *text=[[NSTextView alloc]initWithFrame:NSMakeRect(0,0,240,130)];text.editable=NO;text.selectable=YES;text.richText=NO;text.verticallyResizable=YES;text.horizontallyResizable=NO;text.autoresizingMask=NSViewWidthSizable;text.textContainer.widthTracksTextView=YES;text.textContainer.containerSize=NSMakeSize(240,CGFLOAT_MAX);text.minSize=NSMakeSize(0,130);text.maxSize=NSMakeSize(CGFLOAT_MAX,CGFLOAT_MAX);text.textContainerInset=NSMakeSize(6,6);text.font=[NSFont monospacedSystemFontOfSize:11 weight:NSFontWeightRegular];text.textColor=NSColor.labelColor;text.backgroundColor=NSColor.controlBackgroundColor;text.string=@"Statistics appear here after a main-window render finishes. Select and copy the text to compare renders.";text.accessibilityLabel=@"Completed render statistics";
    scroll.documentView=text;self.renderInfoText=text;tab.view=scroll;[tabs addTabViewItem:tab];
}
- (void)displayRenderInfo:(RenderResult)result {
    RenderStatistics s=result.statistics;if(!s.valid)return;
    if(!result.reused_surface&&result.width>0&&result.height>0){self.animationSecondsPerPixel=s.elapsed/((double)result.width*result.height);[self updateAnimationPreviewEstimate];}
#ifdef USE_RUST_ENGINE
    NSString *engine=@"Engine";
#else
    NSString *engine=@"C engine";
#endif
    NSMutableString *text=[NSMutableString stringWithFormat:@"%@ — %d × %d\n%@\nCPU thread limit: %d\nElapsed: %.3f s\n\n",engine,result.width,result.height,result.reused_surface?@"Cached geometry update":@"Full render",s.threads,s.elapsed];
    [text appendFormat:@"DE stop: %.9g\nRaystep: %.9g\nMax iterations: %d\n\n",result.settings.de_stop,result.settings.ray_step,result.settings.iterations];
    if(s.gpu)[text appendString:@"GPU assisted: work counters below cover CPU work only.\n\n"];
    NSArray *phases=@[@"Primary",@"Normals",@"Hit refinement",@"Hard shadows",@"Ambient shadows",@"Fog",@"Refl/transmission",@"Other / coloring"];
    unsigned long long total=0,formulas=0;for(int i=0;i<8;i++){total+=s.evaluations[i];formulas+=s.formula_calls[i];}
    [text appendFormat:@"Field evaluations: %llu\n",total];for(int i=0;i<8;i++)[text appendFormat:@"  %@: %llu\n",phases[i],s.evaluations[i]];
    [text appendFormat:@"\nFormula executions: %llu\n",formulas];for(int i=0;i<8;i++)if(result.settings.program.slots[i].count||s.formula_calls[i])[text appendFormat:@"  Slot %d (%s × %.9g): %llu\n",i+1,formula_name(result.settings.program.slots[i].kind),formula_iteration_value(result.settings.program,i),s.formula_calls[i]];
    [text appendString:@"Includes modifier calls and numerical-DE probes.\n"];
    [text appendFormat:@"\nPrimary rays: %llu\nSurface hits: %llu\nMarch loop passes: %llu\nAverage per ray: %.2f\nMaximum per ray: %llu\nRays reaching limit: %llu\n\nWall timings\n",s.rays,s.hits,s.steps,s.rays?(double)s.steps/s.rays:0,s.max_steps,s.capped_rays];
    NSArray *stages=@[@"Geometry",@"Surface lighting",@"Ambient post-pass",@"Hard shadow pass",@"Fog pass",@"Refl/transmission",@"Depth of field",@"Setup / other"];
    for(int i=0;i<8;i++)if(s.timing_mask&(1u<<i))[text appendFormat:@"  %@: %.3f s\n",stages[i],s.seconds[i]];
#ifdef USE_RUST_ENGINE
    [text appendString:@"\nGeometry includes normals, refinement and dynamic fog. Separate fog time is unavailable. Reflection time may include its own shadow calculations.\n"];
#else
    [text appendString:@"\nSurface lighting includes normals, DEAO and hard shadows. Those costs are not separately timed. Ambient post-pass covers SSAO and depth-buffer normals.\n"];
#endif
    [text appendString:@"\nField evaluations count distance or iteration queries at a point. Counts describe this update only. Reused geometry contributes no primary rays. March loop passes exclude the initial DE query and refinement; engines use different step limits. Times exclude image display and history saving.\n"];
    self.renderInfoText.string=text;
}
- (void)addPositionTab:(NSTabView *)tabs {
    NSTabViewItem *tab=[[NSTabViewItem alloc]initWithIdentifier:@"position"];tab.label=@"Camera";
    NSScrollView *scroll=[[NSScrollView alloc]initWithFrame:NSMakeRect(0,0,260,130)];scroll.hasVerticalScroller=YES;scroll.autoresizingMask=NSViewWidthSizable|NSViewHeightSizable;
    CalculationPanel *panel=[[CalculationPanel alloc]initWithFrame:NSMakeRect(0,0,240,361)];scroll.documentView=panel;
    NSMutableArray *fields=[NSMutableArray array];NSArray *names=@[@"X mid",@"Y mid",@"Z mid",@"Z start",@"Z end",@"Zoom",@"Yaw (°)",@"Pitch (°)",@"Roll (°)",@"FOV Y (°)"];
    for(int i=0;i<10;i++){NSTextField *label=[NSTextField labelWithString:names[i]];label.frame=NSMakeRect(10,5+i*29,65,22);[panel addSubview:label];NSTextField *field=[[NumericTextField alloc]initWithFrame:NSMakeRect(78,1+i*29,158,25)];field.accessibilityLabel=names[i];field.stringValue=i==3?@"-2":i==4?@"30":i==5?@"1":i==9?@"30":@"0";[panel addSubview:field];[fields addObject:field];}
    self.positionFields=fields;self.positionBaseline=[fields valueForKey:@"stringValue"];
    NSButton *pick=[NSButton buttonWithTitle:@"Get mid" target:self action:@selector(getMidpoint:)];pick.frame=NSMakeRect(8,294,132,28);[panel addSubview:pick];NSButton *reset=[NSButton buttonWithTitle:@"Reset" target:self action:@selector(resetPosition:)];reset.frame=NSMakeRect(145,294,90,28);[panel addSubview:reset];
    self.positionCopyButton=[NSButton buttonWithTitle:@"Copy" target:self action:@selector(copyPosition:)];self.positionCopyButton.frame=NSMakeRect(8,326,110,28);self.positionCopyButton.toolTip=@"Copy this view to the temporary Camera buffer.";[panel addSubview:self.positionCopyButton];
    self.positionPasteButton=[NSButton buttonWithTitle:@"Paste" target:self action:@selector(pastePosition:)];self.positionPasteButton.frame=NSMakeRect(125,326,110,28);self.positionPasteButton.enabled=self.positionPasteValues!=nil;self.positionPasteButton.toolTip=@"Restore the copied camera and render.";[panel addSubview:self.positionPasteButton];
    tab.view=scroll;[tabs addTabViewItem:tab];
}
- (void)populatePosition {
    if(!self.positionFields)return;RenderOptions settings=self.formulaSettings;double values[10];memcpy(values,settings.position,sizeof settings.position);
    if(settings.camera_override){CameraSettings c=settings.camera;for(int i=0;i<3;i++)values[i]=c.origin[i]+c.axes[6+i]*c.distance*.5;values[3]=values[2]-c.distance*.5;values[4]=values[2]+c.distance*.5;values[5]=c.zoom;}
    CameraSettings camera=settings.camera;
    double horizontal=hypot(camera.axes[6],camera.axes[8]);
    double yaw=horizontal>1e-12?atan2(camera.axes[6],camera.axes[8]):atan2(-camera.axes[2],camera.axes[0]);
    double pitch=atan2(camera.axes[7],horizontal);
    double roll=horizontal>1e-12?atan2(camera.axes[1]/horizontal,camera.axes[0]*cos(yaw)-camera.axes[2]*sin(yaw)):0;
    values[6]=yaw*180/M_PI;values[7]=pitch*180/M_PI;values[8]=roll*180/M_PI;
    values[9]=camera.fov>0?camera.fov:30;
    for(int i=0;i<10;i++)self.positionFields[i].stringValue=[NSString stringWithFormat:@"%.17g",values[i]];self.positionBaseline=[self.positionFields valueForKey:@"stringValue"];
}
- (BOOL)readPosition:(RenderOptions *)options {
    if([[self.positionFields valueForKey:@"stringValue"]isEqual:self.positionBaseline])return YES;
    double v[10];for(int i=0;i<10;i++){NSScanner *scan=[NSScanner scannerWithString:numericInputString(self.positionFields[i])];if(![scan scanDouble:&v[i]]||!scan.isAtEnd||!isfinite(v[i])||fabs(v[i])>1e15){self.statusLabel.stringValue=@"Enter finite Camera values.";return NO;}}
    if(v[4]<=v[3]||v[5]<1e-12||v[5]>1e12){self.statusLabel.stringValue=@"Z end must exceed Z start; Zoom must be 0.000000000001–1000000000000.";return NO;}
    if(v[9]<.001||v[9]>=180){self.statusLabel.stringValue=@"Vertical field of view must be at least 0.001° and less than 180°.";return NO;}
    CameraSettings c=options->camera;
    if(c.zoom<=0)c=(CameraSettings){.axes={1,0,0,0,1,0,0,0,1},.fov=30};
    NSArray *values=[self.positionFields valueForKey:@"stringValue"];
    BOOL rotated=self.positionBaseline.count!=10;
    for(int i=6;i<9&&!rotated;i++)rotated=![values[i] isEqual:self.positionBaseline[i]];
    BOOL repositioned=rotated;
    for(int i=0;i<6&&!repositioned;i++)repositioned=![values[i] isEqual:self.positionBaseline[i]];
    if(rotated){
        const double identity[]={1,0,0,0,1,0,0,0,1};
        memcpy(c.axes,identity,sizeof identity);
        camera_turn(&c,remainder(v[6],360),remainder(v[7],360),remainder(v[8],360));
    }
    if(repositioned){
        for(int i=0;i<3;i++)c.origin[i]=v[i]+c.axes[6+i]*(v[3]-v[2]);
        c.distance=v[4]-v[3];c.zoom=v[5];
    }
    c.fov=v[9];options->camera=c;options->camera_override=1;
    memcpy(options->position,v,sizeof options->position);
    return YES;
}
- (void)copyPosition:(id)sender {
    (void)sender;if(self.calculating)return;
    [self.window makeFirstResponder:nil];
    RenderOptions options=self.formulaSettings;
    if(![self readPosition:&options])return;
    self.positionPasteValues=[self.positionFields valueForKey:@"stringValue"];self.positionPasteCamera=options.camera;self.positionPasteButton.enabled=YES;
}
- (void)pastePosition:(id)sender {
    (void)sender;if(self.calculating||!self.positionPasteValues)return;
    [self.window makeFirstResponder:nil];
    for(int i=0;i<10;i++)self.positionFields[i].stringValue=self.positionPasteValues[i];
    RenderOptions options=self.formulaSettings;options.camera=self.positionPasteCamera;options.camera_override=1;self.formulaSettings=options;self.positionBaseline=self.positionPasteValues;
    [self calculate:self.renderButton];
}
- (void)resetPosition:(id)sender {
    (void)sender;if(self.calculating)return;double v[]={0,0,0,-2,30,1,0,0,0,30};for(int i=0;i<10;i++)self.positionFields[i].stringValue=[NSString stringWithFormat:@"%.17g",v[i]];RenderOptions settings=self.formulaSettings;double axes[]={1,0,0,0,1,0,0,0,1};memcpy(settings.camera.axes,axes,sizeof axes);settings.camera.fov=30;settings.camera.optic=0;self.formulaSettings=settings;self.positionBaseline=nil;
}
- (void)getMidpoint:(id)sender {
    (void)sender;if(self.calculating||!self.completedRender)return;self.placingLight=-1;self.midpointPicking=YES;self.imageView.pickingLight=YES;self.statusLabel.stringValue=@"Click the rendered object to set the midpoint.";
}
- (void)pickMidpointAt:(NSPoint)point {
    NSUInteger generation=self.generation;dispatch_async(self.renderQueue,^{double p[3]={0};BOOL hit=render_pick_surface(point.x,point.y,p);double x=p[0],y=p[1],z=p[2];interactiveUI(^{if(generation!=self.generation||self.calculating)return;if(!hit){self.statusLabel.stringValue=@"No surface at that point.";return;}double dz=z-self.positionFields[2].doubleValue;NSArray *coordinates=@[@(x),@(y),@(z)];for(int i=0;i<3;i++)self.positionFields[i].stringValue=[NSString stringWithFormat:@"%.17g",[coordinates[i] doubleValue]];for(int i=3;i<5;i++)self.positionFields[i].stringValue=[NSString stringWithFormat:@"%.17g",self.positionFields[i].doubleValue+dz];self.midpointPicking=NO;self.imageView.pickingLight=NO;self.statusLabel.stringValue=@"Midpoint updated. Press Render to apply.";});});
}
- (void)addNavigatorCuttingTab:(NSTabView *)tabs {
    NSTabViewItem *tab=[[NSTabViewItem alloc]initWithIdentifier:@"cutting"];tab.label=@"Cutting";
    CalculationPanel *panel=[[CalculationPanel alloc]initWithFrame:NSMakeRect(0,0,672,194)];
    NSMutableArray *sliders=[NSMutableArray array],*fields=[NSMutableArray array],*checks=[NSMutableArray array];
    for(int i=0;i<3;i++){
        CGFloat y=12+i*38;NSString *name=@[@"X",@"Y",@"Z"][i];NSTextField *label=[NSTextField labelWithString:name];label.frame=NSMakeRect(12,y+4,30,22);[panel addSubview:label];
        LiveSlider *slider=[LiveSlider sliderWithValue:0 minValue:-2 maxValue:2 target:self action:@selector(navigatorCuttingChanged:)];slider.commandResetValue=@0;slider.toolTip=@"Hold Shift for fine control. Cmd-click to reset to zero.";slider.tag=i;slider.frame=NSMakeRect(52,y,350,26);slider.continuous=YES;slider.accessibilityLabel=[@"Cutting " stringByAppendingString:name];
        __weak AppDelegate *owner=self;slider.started=^{[owner beginNavigatorSlider];};slider.finished=^{[owner endNavigatorSlider];};[panel addSubview:slider];[sliders addObject:slider];
        NSTextField *field=[[NumericTextField alloc]initWithFrame:NSMakeRect(420,y,166,26)];field.tag=i;field.target=self;field.action=@selector(navigatorCuttingChanged:);field.accessibilityLabel=slider.accessibilityLabel;[panel addSubview:field];[fields addObject:field];
        NSButton *check=[NSButton checkboxWithTitle:@"" target:self action:@selector(navigatorCuttingChanged:)];check.tag=i;check.frame=NSMakeRect(612,y,24,26);check.accessibilityLabel=[@"Enable cutting " stringByAppendingString:name];[panel addSubview:check];[checks addObject:check];
    }
    NSButton *mid=[NSButton buttonWithTitle:@"Insert mid values" target:self action:@selector(insertNavigatorCutMid:)];mid.frame=NSMakeRect(52,138,200,28);[panel addSubview:mid];
    self.navigatorCutPickButton=[NSButton buttonWithTitle:@"Get values from image" target:self action:@selector(pickNavigatorCutValues:)];self.navigatorCutPickButton.frame=NSMakeRect(270,138,240,28);self.navigatorCutPickButton.toolTip=@"Click a surface in the main render to get its cutting coordinates.";[panel addSubview:self.navigatorCutPickButton];
    self.navigatorCutSliders=sliders;self.navigatorCutFields=fields;self.navigatorCutChecks=checks;tab.view=panel;[tabs addTabViewItem:tab];[self populateNavigatorCutting];
}
- (void)populateNavigatorCutting {
    RenderOptions settings=self.navigatorFormulaSettings;
    for(int i=0;i<self.navigatorCutFields.count;i++){
        double value=settings.cutting[i],radius=fmax(.001,fmax(self.navigatorCamera.distance*.1,1/self.navigatorCamera.zoom));if(!isfinite(radius))radius=2;
        self.navigatorCutFields[i].stringValue=[NSString stringWithFormat:@"%.17g",value];self.navigatorCutChecks[i].state=(settings.cutting_mask>>i)&1;
        self.navigatorCutSliders[i].minValue=value-radius;self.navigatorCutSliders[i].maxValue=value+radius;self.navigatorCutSliders[i].doubleValue=value;
        self.navigatorCutFields[i].enabled=!self.calculating;self.navigatorCutChecks[i].enabled=!self.calculating;self.navigatorCutSliders[i].enabled=!self.calculating&&((settings.cutting_mask>>i)&1);
    }
}
- (void)navigatorCuttingChanged:(NSControl *)sender {
    if(self.calculating)return;
    if([sender isKindOfClass:NSSlider.class])self.navigatorCutFields[sender.tag].doubleValue=sender.doubleValue;
    RenderOptions settings=self.navigatorFormulaSettings;settings.cutting_override=1;settings.cutting_mask=0;
    for(int i=0;i<3;i++){
        NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.navigatorCutFields[i])];double value;
        if(![scanner scanDouble:&value]||!scanner.isAtEnd||!isfinite(value)){self.navigatorStatus.stringValue=@"Cutting coordinates must be finite numbers.";return;}
        settings.cutting[i]=value;if(self.navigatorCutChecks[i].state==NSControlStateValueOn)settings.cutting_mask|=1<<i;
    }
    self.navigatorFormulaSettings=settings;
    if(![sender isKindOfClass:NSSlider.class])[self populateNavigatorCutting];
    [self requestNavigatorPreviewAdaptingDistance:NO];
}
- (void)insertNavigatorCutMid:(id)sender {
    (void)sender;for(int i=0;i<3;i++)self.navigatorCutFields[i].doubleValue=self.navigatorFormulaSettings.position[i];[self navigatorCuttingChanged:nil];
}
- (void)pickNavigatorCutValues:(id)sender {
    (void)sender;if(self.calculating||!self.completedRender)return;
    self.cuttingPicking=!self.cuttingPicking;self.midpointPicking=NO;self.focusPicking=0;self.placingLight=-1;self.imageView.pickingLight=self.cuttingPicking;
    self.navigatorCutPickButton.title=self.cuttingPicking?@"Click on main render":@"Get values from image";
    if(self.cuttingPicking){self.statusLabel.stringValue=@"Click a surface to obtain cutting coordinates.";[self.window makeKeyAndOrderFront:nil];}
}
- (void)pickNavigatorCutAt:(NSPoint)point {
    NSUInteger generation=self.generation;dispatch_async(self.renderQueue,^{double position[3]={0};BOOL hit=render_pick_surface(point.x,point.y,position);double x=position[0],y=position[1],z=position[2];interactiveUI(^{
        if(generation!=self.generation||!self.cuttingPicking)return;
        if(!hit){self.statusLabel.stringValue=@"Click a rendered surface to obtain cutting coordinates.";return;}
        double values[]={x,y,z};for(int i=0;i<3;i++)self.navigatorCutFields[i].doubleValue=values[i];self.cuttingPicking=NO;self.imageView.pickingLight=NO;self.navigatorCutPickButton.title=@"Get values from image";[self navigatorCuttingChanged:nil];[self.navigatorWindow makeKeyAndOrderFront:nil];
    });});
}
- (BOOL)navigatorHas4DFormula {
    FormulaProgram program=self.navigatorFormulaSettings.program;
    for(int i=0;i<FORMULA_UI_SLOTS;i++)if(program.slots[i].count>0){NSInteger category=formulaCategory(program.slots[i].kind);if(category==2||category==3)return YES;}
    return NO;
}
- (void)addNavigatorRotationTab:(NSTabView *)tabs {
    self.navigatorRotationTab=[[RotationTabItem alloc]initWithIdentifier:@"rotation4"];self.navigatorRotationTab.label=@"4D Rotation";
    CalculationPanel *panel=[[CalculationPanel alloc]initWithFrame:NSMakeRect(0,0,672,194)];
    NSMutableArray *sliders=[NSMutableArray array],*fields=[NSMutableArray array],*labels=[NSMutableArray array];
    for(int i=0;i<3;i++){
        CGFloat y=22+i*44;NSString *name=@[@"XW",@"YW",@"ZW"][i];
        NSTextField *label=[NSTextField labelWithString:[name stringByAppendingString:@" (°)"]];label.frame=NSMakeRect(12,y+4,140,22);[panel addSubview:label];[labels addObject:label];
        LiveSlider *slider=[LiveSlider sliderWithValue:0 minValue:-180 maxValue:180 target:self action:@selector(navigatorRotationChanged:)];slider.commandResetValue=@0;slider.toolTip=@"Hold Shift for fine control. Cmd-click to reset to zero.";slider.frame=NSMakeRect(158,y,300,26);slider.tag=i;slider.continuous=YES;slider.accessibilityLabel=[@"4D rotation " stringByAppendingString:name];
        __weak AppDelegate *owner=self;slider.started=^{[owner beginNavigatorSlider];};slider.finished=^{[owner endNavigatorSlider];};[panel addSubview:slider];[sliders addObject:slider];
        NSTextField *field=[[NumericTextField alloc]initWithFrame:NSMakeRect(476,y,182,26)];field.tag=i;field.target=self;field.action=@selector(navigatorRotationChanged:);field.accessibilityLabel=slider.accessibilityLabel;[panel addSubview:field];[fields addObject:field];
    }
    self.navigatorRotationSliders=sliders;self.navigatorRotationFields=fields;self.navigatorRotationLabels=labels;
    self.navigatorRotationTab.view=panel;[tabs addTabViewItem:self.navigatorRotationTab];[self populateNavigatorRotation];
}
- (void)navigatorTabChanged:(NSSegmentedControl *)sender {
    [self.navigatorRotationTab.tabView selectTabViewItemAtIndex:sender.selectedSegment];
}
- (void)populateNavigatorRotation {
    BOOL enabled=[self navigatorHas4DFormula]&&!self.calculating;
    self.navigatorRotationTab.dimmed=![self navigatorHas4DFormula];
    if(self.navigatorTabControl){
        NSInteger index=[self.navigatorRotationTab.tabView indexOfTabViewItem:self.navigatorRotationTab];
        [self.navigatorTabControl setEnabled:!self.navigatorRotationTab.dimmed forSegment:index];
        self.navigatorTabControl.needsDisplay=YES;
    }
    for(int i=0;i<self.navigatorRotationSliders.count;i++){
        double degrees=self.navigatorFormulaSettings.rotation4[i]*180/M_PI;
        self.navigatorRotationSliders[i].minValue=fmin(-180,degrees);self.navigatorRotationSliders[i].maxValue=fmax(180,degrees);self.navigatorRotationSliders[i].doubleValue=degrees;
        self.navigatorRotationFields[i].stringValue=[NSString stringWithFormat:@"%.17g",degrees];self.navigatorRotationFields[i].enabled=enabled;self.navigatorRotationSliders[i].enabled=enabled;
        self.navigatorRotationLabels[i].textColor=enabled?NSColor.labelColor:NSColor.disabledControlTextColor;
    }
}
- (void)navigatorRotationChanged:(NSControl *)sender {
    if(self.calculating||![self navigatorHas4DFormula])return;
    double degrees=sender.doubleValue;if(!isfinite(degrees)){self.navigatorStatus.stringValue=@"4D rotation must be finite.";return;}
    RenderOptions settings=self.navigatorFormulaSettings;settings.rotation4_override=1;settings.rotation4[sender.tag]=degrees*M_PI/180;
    if(!isfinite(settings.rotation4[sender.tag]))return;
    self.navigatorFormulaSettings=settings;[self rememberNavigatorValue:@{@"rotation4":@(sender.tag)}];[self populateNavigatorRotation];[self requestNavigatorPreviewAdaptingDistance:NO];
}
- (void)addNavigatorJuliaTab:(NSTabView *)tabs {
    NSTabViewItem *tab=[[NSTabViewItem alloc] initWithIdentifier:@"julia-values"];tab.label=@"Julia Values";
    CalculationPanel *panel=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,672,194)];
    self.navigatorJuliaMode=[NSButton checkboxWithTitle:@"Julia mode" target:self action:@selector(navigatorJuliaEdited:)];self.navigatorJuliaMode.frame=NSMakeRect(12,2,200,26);[panel addSubview:self.navigatorJuliaMode];
    self.navigatorJuliaSphericalCheck=[NSButton checkboxWithTitle:@"Spherical coordinates" target:self action:@selector(navigatorJuliaEdited:)];self.navigatorJuliaSphericalCheck.frame=NSMakeRect(230,2,300,26);[panel addSubview:self.navigatorJuliaSphericalCheck];
    NSMutableArray *fields=[NSMutableArray array],*labels=[NSMutableArray array],*sliders=[NSMutableArray array];
    for(int i=0;i<3;i++) {
        CGFloat y=36+i*36;NSTextField *label=[NSTextField labelWithString:@""];label.frame=NSMakeRect(12,y+4,140,22);[panel addSubview:label];[labels addObject:label];
        LiveSlider *slider=[LiveSlider sliderWithValue:0 minValue:-2 maxValue:2 target:self action:@selector(navigatorJuliaSlider:)];slider.commandResetValue=@0;slider.toolTip=@"Hold Shift for fine control. Cmd-click to reset to zero.";slider.frame=NSMakeRect(158,y,300,26);slider.tag=i;slider.continuous=YES;
        __weak __typeof__(self) weakNavigator=self;slider.started=^{[weakNavigator beginNavigatorSlider];};slider.finished=^{[weakNavigator endNavigatorSlider];};
        [panel addSubview:slider];[sliders addObject:slider];
        NSTextField *field=[[NumericTextField alloc] initWithFrame:NSMakeRect(476,y,182,26)];field.target=self;field.action=@selector(navigatorJuliaEdited:);[panel addSubview:field];[fields addObject:field];
    }
    self.navigatorJuliaFields=fields;self.navigatorJuliaLabels=labels;self.navigatorJuliaSliders=sliders;
    NSTextField *hint=[NSTextField labelWithString:@"Preview edits here; Apply to Main commits them. Hold Shift for fine sliders."];hint.frame=NSMakeRect(12,150,650,24);hint.font=[NSFont systemFontOfSize:11];[panel addSubview:hint];
    tab.view=panel;[tabs addTabViewItem:tab];
}
- (void)populateNavigatorJuliaValues {
    if(!self.navigatorJuliaFields)return;
    RenderOptions settings=self.navigatorFormulaSettings;double x=settings.julia_c[0],y=settings.julia_c[1],z=settings.julia_c[2],radius=hypot(hypot(x,y),z);
    double values[]={x,y,z},low[]={-2,-2,-2},high[]={2,2,2};NSArray *names=@[@"Julia X",@"Julia Y",@"Julia Z"];
    if(self.navigatorJuliaSpherical){values[0]=radius;values[1]=atan2(x,z)*180/M_PI;values[2]=radius?asin(fmax(-1,fmin(1,y/radius)))*180/M_PI:0;low[0]=0;high[0]=4;low[1]=-180;high[1]=180;low[2]=-90;high[2]=90;names=@[@"Radius",@"Longitude (°)",@"Latitude (°)"];}
    self.navigatorJuliaMode.state=settings.julia?NSControlStateValueOn:NSControlStateValueOff;
    self.navigatorJuliaSphericalCheck.state=self.navigatorJuliaSpherical?NSControlStateValueOn:NSControlStateValueOff;
    for(int i=0;i<3;i++) {
        self.navigatorJuliaFields[i].stringValue=[NSString stringWithFormat:@"%.17g",values[i]];self.navigatorJuliaLabels[i].stringValue=names[i];self.navigatorJuliaFields[i].accessibilityLabel=names[i];self.navigatorJuliaSliders[i].accessibilityLabel=names[i];
        self.navigatorJuliaSliders[i].minValue=fmin(low[i],values[i]);self.navigatorJuliaSliders[i].maxValue=fmax(high[i],values[i]);self.navigatorJuliaSliders[i].doubleValue=values[i];
    }
}
- (BOOL)readNavigatorJuliaValues {
    if(!self.navigatorJuliaFields)return YES;
    double v[3];for(int i=0;i<3;i++){NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.navigatorJuliaFields[i])];if(![scanner scanDouble:&v[i]]||!scanner.isAtEnd||!isfinite(v[i])||fabs(v[i])>1e6){self.navigatorStatus.stringValue=@"Julia values must be finite and within −1000000..1000000.";return NO;}}
    if(self.navigatorJuliaSpherical){if(v[0]<0||v[2]<-90||v[2]>90){self.navigatorStatus.stringValue=@"Julia radius must be nonnegative; latitude must be −90..90°.";return NO;}double r=v[0],longitude=v[1]*M_PI/180,latitude=v[2]*M_PI/180;v[0]=r*cos(latitude)*sin(longitude);v[1]=r*sin(latitude);v[2]=r*cos(latitude)*cos(longitude);}
    RenderOptions settings=self.navigatorFormulaSettings;settings.julia_override=1;settings.julia=self.navigatorJuliaMode.state==NSControlStateValueOn;memcpy(settings.julia_c,v,sizeof v);self.navigatorFormulaSettings=settings;return YES;
}
- (void)navigatorJuliaEdited:(id)sender {
    RenderOptions previous=self.navigatorFormulaSettings;
    if(![self readNavigatorJuliaValues]){if(sender==self.navigatorJuliaSphericalCheck)self.navigatorJuliaSphericalCheck.state=self.navigatorJuliaSpherical?NSControlStateValueOn:NSControlStateValueOff;return;}
    if(sender==self.navigatorJuliaMode&&previous.julia!=self.navigatorFormulaSettings.julia)[self rememberNavigatorValue:@{@"julia":@(-1)}];
    if(sender!=self.navigatorJuliaSphericalCheck){for(int i=0;i<3;i++)if(sender==self.navigatorJuliaFields[i]||sender==self.navigatorJuliaSliders[i]){[self rememberNavigatorValue:@{@"julia":@(i),@"spherical":@(self.navigatorJuliaSpherical)}];break;}}
    if(sender==self.navigatorJuliaSphericalCheck)self.navigatorJuliaSpherical=self.navigatorJuliaSphericalCheck.state==NSControlStateValueOn;
    if(![sender isKindOfClass:NSSlider.class])[self populateNavigatorJuliaValues];[self requestNavigatorPreviewAdaptingDistance:NO];
    if([sender isKindOfClass:NSTextField.class]||[sender isKindOfClass:NSButton.class])[self.navigatorWindow makeFirstResponder:self.navigatorView];
}
- (void)navigatorJuliaSlider:(NSSlider *)sender {
    self.navigatorJuliaFields[sender.tag].stringValue=[NSString stringWithFormat:@"%.17g",sender.doubleValue];[self navigatorJuliaEdited:sender];
}
- (void)addNavigatorFormulaTab:(NSTabView *)tabs {
    NSTabViewItem *tab=[[NSTabViewItem alloc] initWithIdentifier:@"formula-values"];tab.label=@"Formula Values";
    CalculationPanel *panel=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,672,194)];
    if(NavigatorExploreControlsVisible){ExploreBackground *group=[[ExploreBackground alloc]initWithFrame:NSMakeRect(532,0,140,36)];[panel addSubview:group];}
    self.navigatorFormulaMenu=[[NSPopUpButton alloc] initWithFrame:NSMakeRect(46,2,62,28) pullsDown:NO];self.navigatorFormulaMenu.cell=[[NavigatorSlotCell alloc]initTextCell:@"" pullsDown:NO];
    for(int i=0;i<FORMULA_UI_SLOTS;i++)[self.navigatorFormulaMenu addItemWithTitle:[NSString stringWithFormat:@"%d",i+1]];self.navigatorFormulaMenu.target=self;
    self.navigatorFormulaMenu.action=@selector(navigatorFormulaSelected:);self.navigatorFormulaMenu.accessibilityLabel=@"Navigator formula slot";[panel addSubview:self.navigatorFormulaMenu];
    NSMutableArray *arrows=[NSMutableArray array];for(int i=0;i<2;i++){NSImage *image=[NSImage imageWithSystemSymbolName:i?@"arrowtriangle.right.fill":@"arrowtriangle.left.fill" accessibilityDescription:i?@"Next formula slot":@"Previous formula slot"];NSButton *arrow=[NSButton buttonWithImage:image target:self action:@selector(navigatorFormulaArrow:)];arrow.imagePosition=NSImageOnly;arrow.imageScaling=NSImageScaleProportionallyDown;arrow.controlSize=NSControlSizeSmall;arrow.frame=NSMakeRect(i?112:12,2,28,28);arrow.tag=i?1:-1;arrow.accessibilityLabel=i?@"Next formula slot":@"Previous formula slot";[panel addSubview:arrow];[arrows addObject:arrow];}self.navigatorFormulaArrows=arrows;
    NSPopUpButton *menu=[[NSPopUpButton alloc]initWithFrame:NSMakeRect(146,2,NavigatorExploreControlsVisible?158:218,28) pullsDown:YES];self.navigatorFormulaTypeMenu=menu;
            [menu addItemWithTitle:@"Integer Power"];menu.menu.autoenablesItems=NO;
            NSArray *categories=@[@"3D",@"3Da",@"4D",@"4Da",@"Ads",@"dIFS",@"dIFSa"];
            NSArray *hints=@[@"Escape-time 3D formulas",@"3D formulas with analytic DE",@"Escape-time 4D formulas",@"4D formulas with analytic DE",@"Additional transformations",@"dIFS shapes",@"dIFS transformations"];
            for(int category=0;category<7;category++){
                NSMutableArray<NSMenuItem*> *leaves=[NSMutableArray array];
                for(int index=0;index<formula_menu_count();index++){int kind=formulaKindForMenu(index);if(formulaCategory(kind)!=category)continue;NSMenuItem *leaf=[[NSMenuItem alloc]initWithTitle:[NSString stringWithUTF8String:formula_name(kind)] action:@selector(navigatorFormulaTypeChosen:) keyEquivalent:@""];leaf.tag=kind;leaf.target=self;[[FormulaThumbnails shared]addItem:leaf kind:kind];[leaves addObject:leaf];}
                addFormulaMenuGroups(menu.menu,leaves,category,categories[category],hints[category]);
            }
    [self addFormulaSearch:menu slot:-1];
    menu.accessibilityLabel=@"Navigator formula type";menu.toolTip=@"Choose the formula for the selected slot";[panel addSubview:menu];
    NSTextField *iterationLabel=[NSTextField labelWithString:@"Iterations"];self.navigatorIterationLabel=iterationLabel;iterationLabel.frame=NavigatorExploreControlsVisible?NSMakeRect(310,6,70,22):NSMakeRect(372,6,78,22);[panel addSubview:iterationLabel];
    self.navigatorIterationField=[[NumericTextField alloc] initWithFrame:NavigatorExploreControlsVisible?NSMakeRect(372,2,30,26):NSMakeRect(452,2,38,26)];
    numericIntegerField(self.navigatorIterationField,YES);
    self.navigatorIterationField.target=self;self.navigatorIterationField.action=@selector(navigatorFormulaEdited:);self.navigatorIterationField.delegate=self;
    self.navigatorIterationField.accessibilityLabel=@"Navigator formula iterations per pass";
    self.navigatorIterationField.toolTip=@"Iterations per pass for the selected slot: 0–10000; zero disables it. At least one slot and a valid repeat range must remain active. Press Return to preview.";
    [panel addSubview:self.navigatorIterationField];
    self.navigatorIterationStepper=[[NSStepper alloc] initWithFrame:NSMakeRect(NavigatorExploreControlsVisible?406:496,1,19,28)];
    self.navigatorIterationStepper.minValue=0;self.navigatorIterationStepper.maxValue=10000;self.navigatorIterationStepper.increment=1;self.navigatorIterationStepper.valueWraps=NO;self.navigatorIterationStepper.autorepeat=YES;
    self.navigatorIterationStepper.target=self;self.navigatorIterationStepper.action=@selector(navigatorIterationsStepped:);self.navigatorIterationStepper.accessibilityLabel=@"Navigator formula iteration stepper";
    [panel addSubview:self.navigatorIterationStepper];
    NSTextField *rangeLabel=[NSTextField labelWithString:@"Range"];rangeLabel.frame=NavigatorExploreControlsVisible?NSMakeRect(426,6,32,22):NSMakeRect(530,6,52,22);rangeLabel.font=[NSFont systemFontOfSize:NavigatorExploreControlsVisible?11:13];[panel addSubview:rangeLabel];
    self.navigatorFormulaRange=[[NSPopUpButton alloc]initWithFrame:NavigatorExploreControlsVisible?NSMakeRect(458,2,72,28):NSMakeRect(584,2,82,28) pullsDown:NO];self.navigatorFormulaRange.controlSize=NSControlSizeSmall;self.navigatorFormulaRange.font=[NSFont systemFontOfSize:12];[self.navigatorFormulaRange addItemsWithTitles:@[@"min",@"fine",@"mid",@"big"]];[self.navigatorFormulaRange selectItemAtIndex:2];self.navigatorFormulaRangeChoice=2;[self.navigatorFormulaRange.menu addItem:NSMenuItem.separatorItem];[self.navigatorFormulaRange addItemWithTitle:@"Re-center sliders"];self.navigatorFormulaRange.target=self;self.navigatorFormulaRange.action=@selector(navigatorFormulaRangeChanged:);self.navigatorFormulaRange.accessibilityLabel=@"Formula slider range";[panel addSubview:self.navigatorFormulaRange];
    self.navigatorExploreButton=[ExploreButton buttonWithTitle:@"Explore" target:self action:@selector(toggleNavigatorExplore:)];self.navigatorExploreButton.frame=NSMakeRect(560,2,80,28);self.navigatorExploreButton.hidden=!NavigatorExploreControlsVisible;self.navigatorExploreButton.toolTip=@"Explore combinations of checked parameters across their current slider ranges. Click again to stop at the current values. Right-click Resume to reset exploration.";[panel addSubview:self.navigatorExploreButton];
    NSMutableArray *exploreArrows=[NSMutableArray array];for(int direction=0;direction<2;direction++){
        NSImage *image=[NSImage imageWithSystemSymbolName:direction?@"arrowtriangle.right.fill":@"arrowtriangle.left.fill" accessibilityDescription:direction?@"Next explored scene":@"Previous explored scene"];
        ReadableSymbolButton *button=[ReadableSymbolButton buttonWithImage:image target:self action:@selector(browseNavigatorExplore:)];button.symbolSize=16;button.hidden=!NavigatorExploreControlsVisible;button.frame=NSMakeRect(direction?642:534,2,24,28);button.controlSize=NSControlSizeSmall;button.imageScaling=NSImageScaleProportionallyDown;button.tag=direction?1:-1;button.enabled=NO;button.toolTip=direction?@"Next displayed exploration scene":@"Previous displayed exploration scene";[panel addSubview:button];[exploreArrows addObject:button];
    }self.navigatorExploreArrows=exploreArrows;
    NSScrollView *scroll=[[NSScrollView alloc]initWithFrame:NSMakeRect(0,36,672,158)];scroll.hasVerticalScroller=YES;scroll.autohidesScrollers=YES;scroll.autoresizingMask=NSViewWidthSizable|NSViewHeightSizable;
    ExploreParameterRows *rows=[[ExploreParameterRows alloc]initWithFrame:NSMakeRect(0,0,scroll.contentSize.width,582)];scroll.documentView=rows;[panel addSubview:scroll];
    NSMutableArray *labels=[NSMutableArray array],*fields=[NSMutableArray array],*sliders=[NSMutableArray array],*exploreChecks=[NSMutableArray array];
    for(int i=0;i<16;i++) {
        CGFloat y=i*36;
        NSButton *check=[NSButton checkboxWithTitle:@"" target:self action:@selector(exploreSelectionChanged:)];check.frame=NSMakeRect(632,y,22,26);check.hidden=!NavigatorExploreControlsVisible;check.accessibilityLabel=[NSString stringWithFormat:@"Explore parameter %d",i+1];[rows addSubview:check];[exploreChecks addObject:check];
        NSTextField *label=[NSTextField labelWithString:@""];label.frame=NSMakeRect(12,y+4,NavigatorExploreControlsVisible?140:184,22);[rows addSubview:label];[labels addObject:label];
        LiveSlider *slider=[LiveSlider sliderWithValue:0 minValue:-100 maxValue:100 target:self action:@selector(navigatorFormulaSlider:)];
        slider.frame=NSMakeRect(NavigatorExploreControlsVisible?158:202,y,300,26);slider.tag=i;slider.continuous=YES;
        __weak __typeof__(self) weakNavigator=self;__weak LiveSlider *weakSlider=slider;slider.started=^{[weakNavigator beginNavigatorSlider];};slider.finished=^{[weakNavigator navigatorFormulaSliderReleased:weakSlider];[weakNavigator endNavigatorSlider];};
        [rows addSubview:slider];[sliders addObject:slider];
        NSTextField *field=[[NumericTextField alloc] initWithFrame:NSMakeRect(NavigatorExploreControlsVisible?476:516,y,MIN(140,rows.bounds.size.width-(NavigatorExploreControlsVisible?530:528)),26)];field.target=self;field.action=@selector(navigatorFormulaEdited:);[rows addSubview:field];[fields addObject:field];
    }
    self.navigatorExploreChecks=exploreChecks;
    self.navigatorFormulaLabels=labels;self.navigatorFormulaFields=fields;self.navigatorFormulaSliders=sliders;
    tab.view=panel;[tabs addTabViewItem:tab];
}
- (void)syncNavigatorExploreArrows {
    BOOL selected=NO;for(NSButton *check in self.navigatorExploreChecks)if(!check.hidden&&check.state==NSControlStateValueOn){selected=YES;break;}
    self.navigatorExploreButton.enabled=!self.calculating&&(self.navigatorExploring||selected);
    if(self.navigatorExploreArrows.count<2)return;
    BOOL available=!self.navigatorExploring&&!self.calculating;
    self.navigatorExploreArrows[0].enabled=available&&self.navigatorExploreHistoryIndex>0;
    self.navigatorExploreArrows[1].enabled=available&&self.navigatorExploreHistoryIndex+1<(NSInteger)self.navigatorExploreHistory.count;
}
- (void)recordNavigatorExploreSlot:(FormulaSlot)slot {
    self.navigatorExploreNeedsDisplay=NO;
    [self.navigatorExploreHistory addObject:[NSData dataWithBytes:&slot length:sizeof slot]];
    self.navigatorExploreHistoryIndex=self.navigatorExploreHistory.count-1;[self syncNavigatorExploreArrows];
}
- (void)browseNavigatorExplore:(NSButton *)sender {
    if(self.navigatorExploring||self.calculating)return;
    NSInteger index=self.navigatorExploreHistoryIndex+sender.tag;
    if(index<0||index>=(NSInteger)self.navigatorExploreHistory.count)return;
    FormulaSlot slot;[self.navigatorExploreHistory[index] getBytes:&slot length:sizeof slot];
    RenderOptions settings=self.navigatorFormulaSettings;settings.program.slots[self.navigatorFormulaSlot]=slot;self.navigatorFormulaSettings=settings;
    for(int i=0;i<formula_parameter_count(slot.kind);i++){
        double value=formula_slot_value(slot,i);self.navigatorFormulaFields[i].stringValue=[NSString stringWithFormat:@"%.17g",value];self.navigatorFormulaSliders[i].doubleValue=value;
    }
    self.navigatorExploreHistoryIndex=index;[self syncNavigatorExploreArrows];[self requestNavigatorPreviewAdaptingDistance:NO];
}
- (void)stopNavigatorExplore {
    self.navigatorExploring=NO;self.navigatorExploreTicket++;self.navigatorExploreButton.title=self.navigatorExploreSamples.count?@"Resume":@"Explore";[self syncNavigatorExploreArrows];
}
- (void)resetNavigatorExplore {
    self.navigatorExploreSamples=nil;self.navigatorExploreParameters=nil;self.navigatorExploreDigits=nil;
    self.navigatorExploreHistory=nil;self.navigatorExploreHistoryIndex=-1;self.navigatorExploreRun++;[self stopNavigatorExplore];
}
- (void)exploreSelectionChanged:(id)sender {(void)sender;[self resetNavigatorExplore];}
- (void)toggleNavigatorExplore:(id)sender {
    (void)sender;if(self.navigatorExploring){[self stopNavigatorExplore];[self scheduleNavigatorRefinement];return;}
    if(self.calculating||self.parametersPendingRender||![self readNavigatorFormulaValues])return;
    if(self.navigatorExploreSamples.count){
        self.navigatorExploring=YES;self.navigatorExploreTicket++;self.navigatorExploreButton.title=@"Exploring";[self syncNavigatorExploreArrows];
        if(self.navigatorExploreNeedsDisplay)[self applyNavigatorExploreValues];else [self advanceNavigatorExplore];return;
    }
    NSMutableArray *parameters=[NSMutableArray array],*samples=[NSMutableArray array],*digits=[NSMutableArray array];
    FormulaSlot slot=self.navigatorFormulaSettings.program.slots[self.navigatorFormulaSlot];
    for(int i=0;i<formula_parameter_count(slot.kind);i++)if(self.navigatorExploreChecks[i].state==NSControlStateValueOn){
        NSSlider *slider=self.navigatorFormulaSliders[i];FormulaParameter spec=formulaUIParameter(slot.kind,i);NSMutableArray *values=[NSMutableArray array];
        for(int n=0;n<16;n++){double v=slider.minValue+(slider.maxValue-slider.minValue)*(n/15.);if(spec.integer)v=round(v);NSNumber *value=@(v);if(![values.lastObject isEqual:value])[values addObject:value];}
        [parameters addObject:@(i)];[samples addObject:values];[digits addObject:@0];
    }
    if(!parameters.count){self.navigatorStatus.stringValue=@"Check one or more parameters to explore.";return;}
    self.navigatorExploreHistory=[NSMutableArray array];self.navigatorExploreHistoryIndex=-1;self.navigatorExploreRun++;
    self.navigatorExploreParameters=parameters;self.navigatorExploreSamples=samples;self.navigatorExploreDigits=digits;
    self.navigatorExploring=YES;self.navigatorExploreTicket++;self.navigatorExploreButton.title=@"Exploring";[self syncNavigatorExploreArrows];
    [self applyNavigatorExploreValues];
}
- (void)applyNavigatorExploreValues {
    if(!self.navigatorWindow.visible||self.calculating){[self stopNavigatorExplore];return;}
    self.navigatorExploreNeedsDisplay=YES;
    for(NSUInteger i=0;i<self.navigatorExploreParameters.count;i++){
        NSInteger parameter=self.navigatorExploreParameters[i].integerValue;double value=self.navigatorExploreSamples[i][self.navigatorExploreDigits[i].unsignedIntegerValue].doubleValue;
        self.navigatorFormulaSliders[parameter].doubleValue=value;self.navigatorFormulaFields[parameter].stringValue=[NSString stringWithFormat:@"%.17g",value];
    }
    [self requestNavigatorPreviewAdaptingDistance:NO];
}
- (void)advanceNavigatorExplore {
    for(NSUInteger i=0;i<self.navigatorExploreDigits.count;i++){
        NSUInteger next=self.navigatorExploreDigits[i].unsignedIntegerValue+1;
        if(next<self.navigatorExploreSamples[i].count){self.navigatorExploreDigits[i]=@(next);[self applyNavigatorExploreValues];return;}
        self.navigatorExploreDigits[i]=@0;
    }
    self.navigatorExploreSamples=nil;[self stopNavigatorExplore];self.navigatorStatus.stringValue=@"Exploration complete.";
    [self scheduleNavigatorRefinement];
}
- (void)populateNavigatorFormulaValues {
    [self resetNavigatorExplore];[self populateNavigatorRotation];[self populateNavigatorCutting];
    if(!self.navigatorFormulaMenu)return;
    BOOL interpolate=self.navigatorFormulaSettings.program.mode==1;
    self.navigatorIterationLabel.stringValue=interpolate?@"weight":@"Iterations";
    self.navigatorIterationField.accessibilityLabel=interpolate?@"Navigator interpolation weight":@"Navigator formula iterations per pass";
    self.navigatorIterationField.toolTip=interpolate?@"Blend weight for the selected formula. Fractional values are supported; zero disables its contribution.":@"Iterations per pass for the selected slot: 0–10000; zero disables it.";
    if(self.navigatorFormulaRange.indexOfSelectedItem>=0&&self.navigatorFormulaRange.indexOfSelectedItem<4)self.navigatorFormulaRangeChoice=self.navigatorFormulaRange.indexOfSelectedItem;
    RenderOptions settings=self.navigatorFormulaSettings;NSInteger available=settings.program.mode==1?2:FORMULA_UI_SLOTS;
    self.navigatorFormulaSlot=MIN(self.navigatorFormulaSlot,available-1);NSInteger slot=self.navigatorFormulaSlot;
    while(self.navigatorFormulaMenu.numberOfItems>available)[self.navigatorFormulaMenu removeItemAtIndex:self.navigatorFormulaMenu.numberOfItems-1];
    while(self.navigatorFormulaMenu.numberOfItems<available)[self.navigatorFormulaMenu addItemWithTitle:@""];
    for(int i=0;i<available;i++) {
        FormulaSlot f=settings.program.slots[i];NSString *title=[NSString stringWithFormat:@"%d%@",i+1,f.count>0?@"*":@""];
        NSMenuItem *item=[self.navigatorFormulaMenu itemAtIndex:i];item.representedObject=title;item.title=[NSString stringWithFormat:@"%@ — %s",title,formula_name(f.kind)];
    }
    [self.navigatorFormulaMenu selectItemAtIndex:slot];[self.navigatorFormulaMenu setNeedsDisplay:YES];[self syncNavigatorFormulaArrows];
    FormulaSlot f=settings.program.slots[slot];formulaSelectKind(self.navigatorFormulaTypeMenu,f.kind);int count=formula_parameter_count(f.kind);
    numericIntegerField(self.navigatorIterationField,settings.program.mode!=1);self.navigatorIterationField.stringValue=[NSString stringWithFormat:@"%.9g",formula_iteration_value(settings.program,(int)slot)];self.navigatorIterationStepper.minValue=0;self.navigatorIterationStepper.doubleValue=formula_iteration_value(settings.program,(int)slot);self.navigatorIterationField.enabled=f.kind!=-1&&!self.calculating;self.navigatorIterationStepper.enabled=f.kind!=-1&&!self.calculating;
    for(int i=0;i<16;i++) {
        BOOL hidden=i>=count;self.navigatorExploreChecks[i].hidden=hidden||!NavigatorExploreControlsVisible;self.navigatorFormulaLabels[i].hidden=hidden;self.navigatorFormulaFields[i].hidden=hidden;self.navigatorFormulaSliders[i].hidden=hidden;if(hidden)continue;
        FormulaParameter uiSpec=formulaUIParameter(f.kind,i);const FormulaParameter *spec=&uiSpec;NSString *name=[NSString stringWithUTF8String:spec->name];double value=formulaUIDisplayValue(f.kind,i,formula_slot_value(f,i));
        numericIntegerField(self.navigatorFormulaFields[i],spec->integer);self.navigatorFormulaLabels[i].stringValue=name;self.navigatorFormulaFields[i].stringValue=[NSString stringWithFormat:@"%.17g",value];self.navigatorFormulaFields[i].accessibilityLabel=[@"Navigator " stringByAppendingString:name];
        NSSlider *slider=self.navigatorFormulaSliders[i];double low=spec->minimum,high=spec->maximum;
        {double radius=navigatorFormulaRadius(f.kind,i,(int)self.navigatorFormulaRange.indexOfSelectedItem);double center=fmax(spec->minimum,fmin(spec->maximum,value));low=fmax(low,center-radius);high=fmin(high,center+radius);}
        if(spec->integer){low=ceil(low);high=fmax(low,floor(high));}
        slider.minValue=low;slider.maxValue=high;slider.numberOfTickMarks=spec->integer&&low==floor(low)&&high==floor(high)&&high-low<=10?(NSInteger)(high-low+1):0;slider.allowsTickMarkValuesOnly=slider.numberOfTickMarks>1;slider.doubleValue=value;slider.accessibilityLabel=self.navigatorFormulaFields[i].accessibilityLabel;
    }
    NSView *rows=self.navigatorFormulaSliders[0].superview;NSScrollView *scroll=rows.enclosingScrollView;NSRect frame=rows.frame;frame.size.height=MAX(scroll.contentSize.height,6+count*36);rows.frame=frame;
    NSPoint origin=scroll.contentView.bounds.origin;origin.y=MIN(origin.y,MAX(0,frame.size.height-scroll.contentSize.height));[scroll.contentView scrollToPoint:origin];[scroll reflectScrolledClipView:scroll.contentView];
    [self syncNavigatorExploreArrows];

}
- (void)navigatorFormulaTypeChosen:(NSMenuItem *)item {
    if(self.calculating||![self readNavigatorFormulaValues])return;
    RenderOptions settings=self.navigatorFormulaSettings;FormulaSlot previous=settings.program.slots[self.navigatorFormulaSlot];
    if(previous.kind==(int)item.tag)return;
    FormulaSlot replacement=formula_slot_default((int)item.tag);replacement.count=MAX(1,previous.count);settings.program.slots[self.navigatorFormulaSlot]=replacement;settings.program_override=1;self.navigatorFormulaSettings=settings;
    self.navigatorResetTarget=nil;self.navigatorResetValueButton.enabled=NO;[self populateNavigatorFormulaValues];[self requestNavigatorPreviewAdaptingDistance:NO];[self.navigatorWindow makeFirstResponder:self.navigatorView];
}
- (void)navigatorFormulaRangeChanged:(id)sender {
    (void)sender;if(self.navigatorFormulaRange.indexOfSelectedItem>=4)[self.navigatorFormulaRange selectItemAtIndex:self.navigatorFormulaRangeChoice];else self.navigatorFormulaRangeChoice=self.navigatorFormulaRange.indexOfSelectedItem;
    if(![self readNavigatorFormulaValues])return;[self populateNavigatorFormulaValues];[self.navigatorWindow makeFirstResponder:self.navigatorView];
}
- (BOOL)readNavigatorFormulaValues {
    if(![self readNavigatorJuliaValues])return NO;
    if(!self.navigatorFormulaMenu)return YES;
    RenderOptions settings=self.navigatorFormulaSettings;FormulaSlot f=settings.program.slots[self.navigatorFormulaSlot];
    if(f.kind==-1)return YES;
    double count;NSScanner *countScanner=[NSScanner scannerWithString:numericInputString(self.navigatorIterationField)];
    if(![countScanner scanDouble:&count]||!countScanner.isAtEnd||!isfinite(count)||(settings.program.mode!=1&&count!=floor(count))||count<0||count>10000) {
        self.navigatorStatus.stringValue=@"Formula iterations must be an integer 0–10000; zero disables a slot.";return NO;
    }
    f.count=settings.program.mode==1?formula_weight_word(count):(int)count;
    for(int i=0;i<formula_parameter_count(f.kind);i++) {
        double value;NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.navigatorFormulaFields[i])];FormulaParameter uiSpec=formulaUIParameter(f.kind,i);const FormulaParameter *spec=&uiSpec;
        if(![scanner scanDouble:&value]||!scanner.isAtEnd||!isfinite(value)||value<spec->minimum||value>spec->maximum||(spec->integer&&value!=floor(value))){self.navigatorStatus.stringValue=[NSString stringWithFormat:@"%s must be %@between %.9g and %.9g.",spec->name,spec->integer?@"an integer ":@"",spec->minimum,spec->maximum];return NO;}
        formula_slot_set_value(&f,i,value);
    }
    FormulaSlot previous=self.navigatorFormulaSettings.program.slots[self.navigatorFormulaSlot];NSInteger changed=-2;
    if(previous.count!=f.count)changed=-1;
    for(int i=0;i<formula_parameter_count(f.kind);i++)if(formula_slot_value(previous,i)!=formula_slot_value(f,i))changed=i;
    if(changed>=-1)[self rememberNavigatorValue:@{@"slot":@(self.navigatorFormulaSlot),@"kind":@(f.kind),@"parameter":@(changed)}];
    settings.program.slots[self.navigatorFormulaSlot]=f;settings.program_override=1;
    self.navigatorFormulaSettings=settings;[self populateNavigatorRotation];return YES;
}
- (void)syncNavigatorFormulaArrows {
    self.navigatorFormulaArrows.firstObject.enabled=!self.calculating&&self.navigatorFormulaSlot>0;
    self.navigatorFormulaArrows.lastObject.enabled=!self.calculating&&self.navigatorFormulaSlot<self.navigatorFormulaMenu.numberOfItems-1;
}
- (void)navigatorFormulaArrow:(NSButton *)sender {
    NSInteger slot=self.navigatorFormulaSlot+sender.tag;if(self.calculating||slot<0||slot>=self.navigatorFormulaMenu.numberOfItems)return;
    [self.navigatorFormulaMenu selectItemAtIndex:slot];[self navigatorFormulaSelected:self.navigatorFormulaMenu];
}
- (void)navigatorFormulaSelected:(NSPopUpButton *)sender {
    if(![self readNavigatorFormulaValues]){[sender selectItemAtIndex:self.navigatorFormulaSlot];return;}
    self.navigatorFormulaSlot=sender.indexOfSelectedItem;[self populateNavigatorFormulaValues];[self.navigatorFormulaMenu.superview scrollPoint:NSZeroPoint];
    [self.navigatorWindow makeFirstResponder:self.navigatorView];
}
- (void)navigatorFormulaEdited:(id)sender {
    (void)sender;if(![self readNavigatorFormulaValues])return;
    [self populateNavigatorFormulaValues];[self requestNavigatorPreviewAdaptingDistance:NO];
    if([sender isKindOfClass:NSTextField.class])[self.navigatorWindow makeFirstResponder:self.navigatorView];
}
- (void)navigatorIterationsStepped:(NSStepper *)sender {
    self.navigatorIterationField.stringValue=[NSString stringWithFormat:@"%.9g",sender.doubleValue];
    [self navigatorFormulaEdited:sender];[self.navigatorWindow makeFirstResponder:self.navigatorView];
}
- (void)navigatorBrightnessChanged:(NSSlider *)sender {
    self.navigatorView.displayGain=sender.doubleValue==0?1:pow(sender.doubleValue*.05+.85,2)+.2775;
}
- (void)navigatorFormulaSliderReleased:(LiveSlider *)slider {
    if(!slider)return;
    FormulaSlot slot=self.navigatorFormulaSettings.program.slots[self.navigatorFormulaSlot];
    int index=(int)slider.tag;FormulaParameter spec=formulaUIParameter(slot.kind,index);
    double value=formula_slot_value(slot,index);
    BOOL left=slider.trackingValue<=slider.minValue,right=slider.trackingValue>=slider.maxValue;
    if(!((left&&value>spec.minimum)||(right&&value<spec.maximum)))return;
    double radius=navigatorFormulaRadius(slot.kind,index,(int)self.navigatorFormulaRangeChoice);
    double low=fmax(spec.minimum,value-radius),high=fmin(spec.maximum,value+radius);
    if(spec.integer){low=ceil(low);high=fmax(low,floor(high));}
    slider.minValue=low;slider.maxValue=high;
    slider.numberOfTickMarks=spec.integer&&low==floor(low)&&high==floor(high)&&high-low<=10?(NSInteger)(high-low+1):0;
    slider.allowsTickMarkValuesOnly=slider.numberOfTickMarks>1;slider.doubleValue=value;
}
- (void)navigatorFormulaSlider:(NSSlider *)sender {
    FormulaSlot slot=self.navigatorFormulaSettings.program.slots[self.navigatorFormulaSlot];FormulaParameter uiSpec=formulaUIParameter(slot.kind,(int)sender.tag);const FormulaParameter *spec=&uiSpec;double value=spec->integer?round(sender.doubleValue):sender.doubleValue;
    self.navigatorFormulaFields[sender.tag].stringValue=[NSString stringWithFormat:@"%.17g",value];
    /* Repopulating would recenter broad parameter ranges around this value,
       pinning the thumb to the middle on every drag event. */
    if(![self readNavigatorFormulaValues])return;
    sender.doubleValue=value;[self requestNavigatorPreviewAdaptingDistance:NO];
}
/* Only formula parameters transfer from Navigator; calculation and lighting edits
   are collected by the main Render action as usual. */
- (RenderOptions)applyNavigatorFormulas:(RenderOptions)options {
    RenderOptions nav=self.navigatorFormulaSettings;
    options.cutting_override=1;options.cutting_mask=nav.cutting_mask;memcpy(options.cutting,nav.cutting,sizeof options.cutting);
    options.rotation4_override=1;memcpy(options.rotation4,nav.rotation4,sizeof options.rotation4);options.julia_w=nav.julia_w;
    options.program_override=1;options.program=nav.program;
    options.julia_override=1;options.julia=nav.julia;memcpy(options.julia_c,nav.julia_c,sizeof options.julia_c);
    options.formula_override=1;options.sequence_override=1;
    options.kind=nav.kind;options.kind2=nav.kind2;options.power=nav.power;options.power2=nav.power2;
    options.z_multiplier=nav.z_multiplier;options.z_multiplier2=nav.z_multiplier2;
    options.scale=nav.scale;options.scale2=nav.scale2;options.min_radius=nav.min_radius;options.min_radius2=nav.min_radius2;
    options.fold=nav.fold;options.fold2=nav.fold2;
    options.count1=nav.count1;options.count2=nav.count2;options.repeat_from=nav.repeat_from;
    options.formula_override=0;options.sequence_override=0;
    return options;
}

- (void)refreshNavigatorCameraDisplays {
    CameraSettings c=self.navigatorCamera;
    double midZ=c.origin[2]+c.axes[8]*c.distance*.5;
    double values[]={c.zoom,midZ-c.distance*.5,midZ+c.distance*.5,c.distance};
    for(NSUInteger i=0;i<self.navigatorCameraDisplays.count;i++)self.navigatorCameraDisplays[i].stringValue=[NSString stringWithFormat:@"%.6g",values[i]];
    self.navigatorZoomStepper.hidden=self.fixedZoomCheck.state!=NSControlStateValueOn;
}
- (void)stepNavigatorZoom:(NSStepper *)sender {
    NSInteger direction=sender.integerValue;sender.integerValue=0;
    if(self.fixedZoomCheck.state==NSControlStateValueOn&&direction)[self navigateOperation:direction>0?12:13];
}
- (double)navigatorDistanceUnit {
    if(self.fixedZoomCheck.state==NSControlStateValueOn||self.navigatorLocalDistance<=0) {
        double width=MAX(16,self.formulaSettings.width),height=MAX(16,self.formulaSettings.height);
        return 2.1345*hypot(width,height)/(width*self.navigatorCamera.zoom);
    }
    return fmax(1e-300,self.navigatorLocalDistance);
}
- (void)rebaseNavigatorSteps {
    self.navigatorReferenceDistance=fmax(0,self.navigatorLocalDistance);
    self.navigatorReferenceZoom=self.navigatorCamera.zoom;
    self.navigatorReferenceMove=self.moveStepField.doubleValue;
    if(self.navigatorLocalDistance>0)self.navigatorMoveFraction=fmax(0,fmin(.5,self.navigatorReferenceMove/self.navigatorLocalDistance));
    double factor=fmax(.001,fmin(10000,self.navigatorCamera.distance/[self navigatorDistanceUnit]));
    self.navigatorFarField.stringValue=[NSString stringWithFormat:@"%.17g",factor];
}
- (void)fixedZoomChanged:(id)sender {
    (void)sender;self.navigatorMotionEpoch++;[self.navigatorMoves removeAllObjects];
    // This changes future navigation policy, not the current camera or step.
    render_cancel(self.navigatorCancelToken);self.navigatorGeneration++;self.navigatorRefinementTicket++;self.previewPending=NO;
    [self rebaseNavigatorSteps];self.navigatorDistanceAdapted=YES;
    self.navigatorZoomStepper.hidden=self.fixedZoomCheck.state!=NSControlStateValueOn;
    [self.navigatorWindow makeFirstResponder:self.navigatorView];
}
- (void)adaptNavigatorDistance:(double)distance {
    if(!isfinite(distance)||self.navigatorDistanceAdapted)return;
    double width=MAX(16,self.formulaSettings.width),height=MAX(16,self.formulaSettings.height);
    double viewScale=2*hypot(width,height)/width;
    self.navigatorLocalDistance=fmax(0,distance);
    if(self.fixedZoomCheck.state==NSControlStateValueOn)return;
    self.navigatorDistanceAdapted=YES;
    double local=self.navigatorLocalDistance;if(!(local>0))return;
    CameraSettings camera=self.navigatorCamera;
    /* Original Navigator.SetZoom: 2 * image diagonal / (local DE * width).
       MB3D rays originate across a near plane. Anchoring zoom to an arbitrary
       imported zoom can leave that plane intersecting the object forever. */
    double zoom=fmax(1e-12,fmin(1e12,viewScale/local));
    if(self.navigatorReferenceDistance<=0){
        // Establish the far-plane ratio without changing the imported depth.
        self.navigatorFarField.doubleValue=fmax(.001,fmin(10000,camera.distance/local));
        self.navigatorReferenceDistance=local;
    }
    double fraction=self.navigatorMoveFraction;
    double move=fmin(1e9,fraction*self.navigatorLocalDistance);
    double far=fmax(1e-15,fmin(1e12,self.navigatorFarField.doubleValue*[self navigatorDistanceUnit]));
    BOOL changed=fabs(log(zoom/camera.zoom))>1e-8||fabs(far-camera.distance)>1e-8*fmax(1,far);
    camera.zoom=zoom;camera.distance=far;self.navigatorCamera=camera;[self refreshNavigatorCameraDisplays];
    self.moveStepField.stringValue=[NSString stringWithFormat:@"%.17g",move];
    /* A camera correction belongs to this edit. Do not start a new edit or
       repeatedly feed zoom-dependent numerical DE back into auto-zoom. */
    if(changed){self.navigatorPreviewStage=0;self.previewPending=YES;}
}

- (void)positionWindowRightOfMain:(NSWindow *)window {
    if(!window||!self.window||window==self.window)return;
    NSRect main=self.window.frame,frame=window.frame;frame.origin=NSMakePoint(NSMaxX(main)+10,NSMaxY(main)-frame.size.height);
    NSScreen *screen=self.window.screen?:NSScreen.mainScreen;CGFloat best=0;
    for(NSScreen *candidate in NSScreen.screens){NSRect overlap=NSIntersectionRect(frame,candidate.visibleFrame);CGFloat area=overlap.size.width*overlap.size.height;if(area>best){best=area;screen=candidate;}}
    if(screen){NSRect visible=screen.visibleFrame;frame.origin.x=MAX(NSMinX(visible),MIN(frame.origin.x,NSMaxX(visible)-frame.size.width));frame.origin.y=MIN(NSMaxY(visible)-frame.size.height,MAX(NSMinY(visible),frame.origin.y));}
    [window setFrameOrigin:frame.origin];
}
- (void)showNavigator:(id)sender {
    (void)sender;
    if(!self.navigatorWindow) {
        self.navigatorWindow=[[NavigatorWindow alloc] initWithContentRect:NSMakeRect(0,0,720,740)
            styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable backing:NSBackingStoreBuffered defer:NO];
        self.navigatorWindow.title=@"Navigator";self.navigatorWindow.releasedWhenClosed=NO;self.navigatorWindow.delegate=self;
        CalculationPanel *panel=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,720,740)];
        self.navigatorView=[[NavigatorView alloc] initWithFrame:NSMakeRect(16,16,688,400)];
        __weak AppDelegate *weakSelf=self;
        self.navigatorView.openScene=^(NSString *path){[weakSelf renderPath:path];};
        self.navigatorView.navigate=^(NSInteger operation){[weakSelf navigateOperation:operation];};
        NavigatorWindow *navigator=(NavigatorWindow *)self.navigatorWindow;
        navigator.preview=self.navigatorView;navigator.navigate=^(NSInteger operation){[weakSelf navigateOperation:operation];};
        self.navigatorView.look=^(double yaw,double pitch){
            CameraSettings camera=weakSelf.navigatorCamera;camera_turn(&camera,yaw,pitch,0);weakSelf.navigatorCamera=camera;
            [weakSelf requestNavigatorPreviewAdaptingDistance:NO];
        };
        [panel addSubview:self.navigatorView];
        NSTabView *tabs=[[NSTabView alloc] initWithFrame:NSMakeRect(12,452,696,202)];
        tabs.tabViewType=NSNoTabsBezelBorder;tabs.delegate=self;
        NSTabViewItem *movement=[[NSTabViewItem alloc] initWithIdentifier:@"navigation"];movement.label=@"Navigation";
        CalculationPanel *controls=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,672,194)];
        NSArray *titles=@[@"Forward (W)",@"Back (S)",@"Left (A)",@"Right (D)",@"Down (C)",@"Up (E)",
            @"Look left (J)",@"Look right (L)",@"Look up (I)",@"Look down (K)",@"Roll left (U)",@"Roll right (O)"];
        for(int i=0;i<12;i++) {
            NSButton *button=[NSButton buttonWithTitle:titles[i] target:self action:@selector(navigatorControl:)];
            button.font=[NSFont systemFontOfSize:11];button.tag=i;button.frame=NSMakeRect(8+(i%6)*110,2+(i/6)*34,106,30);[controls addSubview:button];
        }
        NSArray *labels=@[@"Move step",@"Look step (°)",@"FOVy (°)"];
        NSMutableArray *fields=[NSMutableArray array];
        for(int i=0;i<3;i++) {
            NSTextField *label=[NSTextField labelWithString:labels[i]];label.frame=NSMakeRect(8+i*222,76,104,22);[controls addSubview:label];
            NSTextField *field=[[NumericTextField alloc] initWithFrame:NSMakeRect(116+i*222,72,100,26)];
            field.stringValue=i==0?@"0.1":i==1?@"5":@"30";field.accessibilityLabel=labels[i];
            field.target=self;field.action=@selector(navigatorValuesChanged:);[controls addSubview:field];[fields addObject:field];
        }
        self.moveStepField=fields[0];self.moveStepField.toolTip=@"With fixed zoom off, movement scales with distance to the nearest surface. Default: 10% per step; maximum: 50%. Hold Shift for a tenth of the step.";self.lookStepField=fields[1];self.navigatorFOVField=fields[2];
        NSArray *actions=@[@"Zoom in (+)",@"Zoom out (−)"];
        for(int i=0;i<2;i++) {
            NSButton *button=[NSButton buttonWithTitle:actions[i] target:self action:@selector(navigatorControl:)];
            button.tag=12+i;button.frame=NSMakeRect(8+i*166,110,160,32);[controls addSubview:button];
        }
        self.fixedZoomCheck=[NSButton checkboxWithTitle:@"Fixed zoom/steps" target:self action:@selector(fixedZoomChanged:)];
        self.fixedZoomCheck.frame=NSMakeRect(16,670,124,24);self.fixedZoomCheck.font=[NSFont systemFontOfSize:12];self.fixedZoomCheck.state=NSControlStateValueOff;[panel addSubview:self.fixedZoomCheck];
        self.fixedZoomCheck.toolTip=@"Keep zoom and movement steps fixed. Switching modes preserves the current view and step.";
        NSTextField *brightLabel=[NSTextField labelWithString:@"Bright"];brightLabel.font=[NSFont systemFontOfSize:12];brightLabel.frame=NSMakeRect(158,674,36,20);[panel addSubview:brightLabel];
        self.navigatorBrightnessSlider=[NavigatorBrightnessSlider sliderWithValue:0 minValue:-20 maxValue:20 target:self action:@selector(navigatorBrightnessChanged:)];self.navigatorBrightnessSlider.frame=NSMakeRect(206,670,74,24);self.navigatorBrightnessSlider.continuous=YES;self.navigatorBrightnessSlider.controlSize=NSControlSizeSmall;self.navigatorBrightnessSlider.accessibilityLabel=@"Navigator Bright";self.navigatorBrightnessSlider.toolTip=@"Adjust Navigator display brightness only. Cmd-click to reset to neutral. Not saved.";[panel addSubview:self.navigatorBrightnessSlider];
        self.navigatorFarField=[[NumericTextField alloc]initWithFrame:NSZeroRect];self.navigatorFarField.stringValue=@"50";
        NSMutableArray *displays=[NSMutableArray array];NSArray *cameraLabels=@[@"Zoom",@"Z Start",@"Z End",@"Far plane"];
        for(int i=0;i<4;i++){
            CGFloat positions[]={310,408,508,610},widths[]={84,90,90,94};CGFloat x=positions[i],labelWidth=widths[i];NSTextField *label=[NSTextField labelWithString:cameraLabels[i]];label.font=[NSFont systemFontOfSize:12];label.frame=NSMakeRect(x,658,labelWidth,20);[panel addSubview:label];
            NSTextField *value=[NSTextField labelWithString:@"0"];value.font=[NSFont monospacedDigitSystemFontOfSize:12 weight:NSFontWeightRegular];value.frame=NSMakeRect(x,677,labelWidth,20);value.accessibilityLabel=cameraLabels[i];if(i==3)value.toolTip=@"Current render depth: Z End minus Z Start. Adjust with F1/F2.";value.selectable=YES;[panel addSubview:value];[displays addObject:value];
        }
        self.navigatorCameraDisplays=displays;
        self.navigatorZoomStepper=[[NSStepper alloc]initWithFrame:NSMakeRect(286,673,19,27)];self.navigatorZoomStepper.minValue=-1;self.navigatorZoomStepper.maxValue=1;self.navigatorZoomStepper.increment=1;self.navigatorZoomStepper.target=self;self.navigatorZoomStepper.action=@selector(stepNavigatorZoom:);self.navigatorZoomStepper.hidden=YES;self.navigatorZoomStepper.accessibilityLabel=@"Adjust Navigator zoom";[panel addSubview:self.navigatorZoomStepper];
        for(int i=0;i<2;i++) {
            NSButton *button=[NSButton buttonWithTitle:i?@"Far + (F2)":@"Far − (F1)" target:self action:@selector(navigatorControl:)];button.tag=16+i;button.frame=NSMakeRect(350+i*166,110,160,32);[controls addSubview:button];
        }
        for(int i=0;i<2;i++) {
            NSButton *button=[NSButton buttonWithTitle:i?@"Apply to Main":@"Reset from Main" target:self action:@selector(navigatorControl:)];
            button.tag=14+i;button.frame=NSMakeRect(i?570:16,708,134,28);[panel addSubview:button];if(i)self.applyNavigatorButton=button;
        }
        self.navigatorResetValueButton=[NSButton buttonWithTitle:@"Reset Value" target:self action:@selector(resetNavigatorValue:)];self.navigatorResetValueButton.frame=NSMakeRect(156,708,134,28);self.navigatorResetValueButton.enabled=NO;self.navigatorResetValueButton.toolTip=@"Restore the most recently edited formula, Julia, or 4D rotation value from Main, keeping other Navigator edits.";[panel addSubview:self.navigatorResetValueButton];
        self.navigatorResetPosButton=[NSButton buttonWithTitle:@"Reset Pos" target:self action:@selector(resetNavigatorPosition:)];self.navigatorResetPosButton.frame=NSMakeRect(296,708,128,28);self.navigatorResetPosButton.toolTip=@"Reset position, rotation and FOV to the original starting view; zoom out further when bailout exceeds 500. Keep Navigator formula edits.";[panel addSubview:self.navigatorResetPosButton];
        self.navigatorAddAnimationButton=[NSButton buttonWithTitle:@"Add to Anim" target:self action:@selector(addNavigatorToAnimation:)];self.navigatorAddAnimationButton.frame=NSMakeRect(430,708,134,28);[panel addSubview:self.navigatorAddAnimationButton];
        movement.view=controls;[tabs addTabViewItem:movement];[self addNavigatorFormulaTab:tabs];[self addNavigatorJuliaTab:tabs];[self addNavigatorRotationTab:tabs];[self addNavigatorCuttingTab:tabs];[panel addSubview:tabs];
        self.navigatorTabControl=[NSSegmentedControl segmentedControlWithLabels:@[@"Navigation",@"Formula Values",@"Julia Values",@"4D Rotation",@"Cutting"] trackingMode:NSSegmentSwitchTrackingSelectOne target:self action:@selector(navigatorTabChanged:)];
        self.navigatorTabControl.segmentStyle=NSSegmentStyleRounded;self.navigatorTabControl.font=[NSFont systemFontOfSize:12];[self.navigatorTabControl sizeToFit];
        NSRect tabFrame=self.navigatorTabControl.frame;tabFrame.origin=NSMakePoint((720-tabFrame.size.width)/2,424);self.navigatorTabControl.frame=tabFrame;
        self.navigatorTabControl.selectedSegment=0;[panel addSubview:self.navigatorTabControl];[self populateNavigatorRotation];
        self.navigatorStatus=[NSTextField wrappingLabelWithString:@"W/S/A/D/C/E move, J/L/I/K or arrows look, U/O roll; Shift fine, +/− zoom, F1/F2 far plane."];
        self.navigatorStatus.frame=NSMakeRect(8,150,650,40);self.navigatorStatus.font=[NSFont systemFontOfSize:12];
        self.navigatorStatus.textColor=NSColor.secondaryLabelColor;[controls addSubview:self.navigatorStatus];
        self.navigatorWindow.contentView=panel;[self.navigatorWindow center];
        [self resetNavigator];
    }
    self.navigatorResetPosButton.enabled=!self.calculating&&self.formulaKnown;self.applyNavigatorButton.enabled=!self.calculating&&self.formulaKnown;self.navigatorAddAnimationButton.enabled=!self.calculating&&self.formulaKnown&&!self.navigatorAddPending;
    [self positionWindowRightOfMain:self.navigatorWindow];[self.navigatorWindow makeKeyAndOrderFront:nil];[self.navigatorWindow makeFirstResponder:self.navigatorView];
    if(self.formulaKnown)[self requestNavigatorPreviewAdaptingDistance:NO];
}
- (BOOL)navigatorValues:(double *)move look:(double *)look {
    NSTextField *fields[4]={self.moveStepField,self.lookStepField,self.navigatorFOVField,self.navigatorFarField};double values[4];
    for(int i=0;i<4;i++) {
        NSScanner *scanner=[NSScanner scannerWithString:numericInputString(fields[i])];
        if(![scanner scanDouble:&values[i]]||!scanner.isAtEnd||!isfinite(values[i])) {
            self.navigatorStatus.stringValue=@"Enter finite movement, angle, FOVy and Far plane values.";return NO;
        }
    }
    if(values[0]<0||values[0]>1e9||values[1]<=0||values[1]>180||values[2]<.001||values[2]>=180||values[3]<.001||values[3]>10000) {
        self.navigatorStatus.stringValue=@"Move step: 0–1000000000; look step: >0–180°; FOVy: 0.001–179.999°; Far plane: 0.001–10000.";return NO;
    }
    *move=values[0];*look=values[1];CameraSettings camera=self.navigatorCamera;camera.fov=values[2];camera.distance=fmax(1e-9,fmin(1e12,values[3]*[self navigatorDistanceUnit]));self.navigatorCamera=camera;return YES;
}
- (void)navigatorValuesChanged:(id)sender {
    double move,look;if([self navigatorValues:&move look:&look]){
        if(sender==self.moveStepField){
            double local=[self navigatorDistanceUnit];
            self.navigatorMoveFraction=fmax(0,fmin(.5,move/local));
            if(self.fixedZoomCheck.state!=NSControlStateValueOn)self.moveStepField.doubleValue=fmin(1e9,self.navigatorMoveFraction*local);
        }
        [self requestNavigatorPreview];[self.navigatorWindow makeFirstResponder:self.navigatorView];}
}
- (void)navigatorControl:(NSButton *)sender {[self navigateOperation:sender.tag+((NSApp.currentEvent.modifierFlags&NSEventModifierFlagShift)&&sender.tag!=14&&sender.tag!=15?100:0)];[self.navigatorWindow makeFirstResponder:self.navigatorView];}
- (void)navigateOperation:(NSInteger)operation {
    double fine=operation>=100?.1:1;if(operation>=100)operation-=100;
    if(!self.formulaKnown)return;
    if(operation==14){[self resetNavigator];return;}
    double move,look;if(![self navigatorValues:&move look:&look])return;
    if(operation==15) {
        if(self.calculating||![self readNavigatorFormulaValues])return;
        if(self.previewBusy||self.navigatorMoves.count){self.navigatorApplyPending=YES;return;}
        self.applyingNavigator=YES;[self calculate:nil];self.applyingNavigator=NO;return;
    }
    move*=fine;look*=fine;
    if(operation<6&&self.fixedZoomCheck.state!=NSControlStateValueOn) {
        if(!self.navigatorMoves)self.navigatorMoves=[NSMutableArray array];
        [self.navigatorMoves addObject:@(operation+(fine<1?100:0))];[self requestNavigatorPreview];return;
    }
    CameraSettings camera=self.navigatorCamera;
    switch(operation) {
        case 0:camera_move(&camera,0,0,move);break;case 1:camera_move(&camera,0,0,-move);break;
        case 2:camera_move(&camera,-move,0,0);break;case 3:camera_move(&camera,move,0,0);break;
        case 4:camera_move(&camera,0,move,0);break;case 5:camera_move(&camera,0,-move,0);break;
        case 6:camera_turn(&camera,-look,0,0);break;case 7:camera_turn(&camera,look,0,0);break;
        case 8:camera_turn(&camera,0,-look,0);break;case 9:camera_turn(&camera,0,look,0);break;
        case 10:camera_turn(&camera,0,0,-look);break;case 11:camera_turn(&camera,0,0,look);break;
        case 16:case 17: {double far=self.navigatorFarField.doubleValue*pow(operation==16?.8:1.25,fine);far=fmax(.001,fmin(10000,far));self.navigatorFarField.stringValue=[NSString stringWithFormat:@"%.17g",far];camera.distance=fmax(1e-9,fmin(1e12,far*[self navigatorDistanceUnit]));break;}
        case 12:camera.zoom=fmin(1e12,camera.zoom*pow(1.2,fine));break;case 13:camera.zoom=fmax(1e-12,camera.zoom/pow(1.2,fine));break;
        default:return;
    }
    self.navigatorCamera=camera;
    if(operation==12||operation==13){camera.distance=fmax(1e-9,fmin(1e12,self.navigatorFarField.doubleValue*[self navigatorDistanceUnit]));self.navigatorCamera=camera;[self rebaseNavigatorSteps];}
    [self requestNavigatorPreviewAdaptingDistance:NO];
}
- (void)rememberNavigatorValue:(NSDictionary *)target {
    self.navigatorResetTarget=target;self.navigatorResetValueButton.enabled=!self.calculating;
}
- (void)resetNavigatorValue:(id)sender {
    (void)sender;if(self.calculating||!self.formulaKnown||!self.navigatorResetTarget)return;
    NSDictionary *target=self.navigatorResetTarget;RenderOptions options=self.navigatorFormulaSettings,main=self.formulaSettings;
    if(target[@"rotation4"]){NSInteger i=[target[@"rotation4"] integerValue];
        options.rotation4[i]=main.rotation4[i];options.rotation4_override=1;self.navigatorFormulaSettings=options;[self populateNavigatorRotation];
    }else if(target[@"julia"]){NSInteger i=[target[@"julia"] integerValue];
        if(i<0){options.julia=main.julia;self.navigatorFormulaSettings=options;}
        else if([target[@"spherical"] boolValue]){
            double x=main.julia_c[0],y=main.julia_c[1],z=main.julia_c[2],r=hypot(hypot(x,y),z);double original[]={r,atan2(x,z)*180/M_PI,r?asin(fmax(-1,fmin(1,y/r)))*180/M_PI:0};
            double a=options.julia_c[0],b=options.julia_c[1],c=options.julia_c[2],radius=hypot(hypot(a,b),c);double v[]={radius,atan2(a,c),radius?asin(fmax(-1,fmin(1,b/radius))):0};v[i]=original[i]*(i?M_PI/180:1);
            options.julia_c[0]=v[0]*cos(v[2])*sin(v[1]);options.julia_c[1]=v[0]*sin(v[2]);options.julia_c[2]=v[0]*cos(v[2])*cos(v[1]);self.navigatorFormulaSettings=options;
        }else{options.julia_c[i]=main.julia_c[i];self.navigatorFormulaSettings=options;}
    }else{
        NSInteger slot=[target[@"slot"] integerValue],parameter=[target[@"parameter"] integerValue];FormulaSlot f=options.program.slots[slot],original=main.program.slots[slot];
        if(f.kind!=[target[@"kind"] intValue]||f.kind!=original.kind){self.navigatorStatus.stringValue=@"That formula differs from Main; use Reset from Main to restore it.";return;}
        if(parameter<0)f.count=original.count;else formula_slot_set_value(&f,(int)parameter,formula_slot_value(original,(int)parameter));options.program.slots[slot]=f;self.navigatorFormulaSettings=options;
    }
    [self populateNavigatorFormulaValues];if(![sender isKindOfClass:NSSlider.class])[self populateNavigatorJuliaValues];[self requestNavigatorPreviewAdaptingDistance:NO];self.navigatorResetTarget=nil;self.navigatorResetValueButton.enabled=NO;[self.navigatorWindow makeFirstResponder:self.navigatorView];
}
- (void)resetNavigatorPosition:(id)sender {
    (void)sender;if(self.calculating||!self.formulaKnown||![self readNavigatorFormulaValues])return;
    BOOL wide=self.navigatorFormulaSettings.program.bailout>500;double start=wide?-8:-2;
    /* Math3D.BuildRotMatrix(0.0001, -0.0001, 0), as in the original reset. */
    double sx=sin(.0001),cx=cos(.0001),sy=sin(-.0001),cy=cos(-.0001);
    CameraSettings camera={.axes={cy,0,sy,sx*sy,cx,-sx*cy,-cx*sy,sx,cx*cy},.zoom=wide?.18:.8,.fov=30,.distance=wide?128:32,.optic=self.navigatorCamera.optic};
    for(int i=0;i<3;i++)camera.origin[i]=camera.axes[6+i]*start;
    self.navigatorCamera=camera;self.navigatorFOVField.stringValue=@"30";self.navigatorLocalDistance=0;self.navigatorDEMultiplier=1;self.navigatorMotionEpoch++;[self.navigatorMoves removeAllObjects];
    [self rebaseNavigatorSteps];self.navigatorMoveFraction=.1;[self requestNavigatorPreview];[self.navigatorWindow makeFirstResponder:self.navigatorView];
}
- (void)refreshNavigatorAfterMainRenderPreservingEdits:(BOOL)preserve {
    if(!preserve){[self resetNavigator];return;}
    // Lighting belongs to Main; pending Navigator geometry and camera stay local.
    if(self.navigatorWindow.visible)[self requestNavigatorPreviewAdaptingDistance:NO];
}
- (void)resetNavigator {
    if(!self.formulaKnown||!self.navigatorWindow)return;
    self.navigatorResetTarget=nil;self.navigatorResetValueButton.enabled=NO;
    self.navigatorApplyPending=NO;self.navigatorAddPending=NO;self.navigatorAddAnimationButton.enabled=!self.calculating&&self.formulaKnown;self.navigatorMotionEpoch++;[self.navigatorMoves removeAllObjects];
    self.navigatorFormulaSettings=self.formulaSettings;[self populateNavigatorFormulaValues];[self populateNavigatorJuliaValues];
    self.navigatorCamera=self.formulaSettings.camera;
    self.navigatorDEMultiplier=1;
    self.navigatorFOVField.stringValue=[NSString stringWithFormat:@"%.17g",self.navigatorCamera.fov];
    self.navigatorLocalDistance=0;[self rebaseNavigatorSteps];self.navigatorDistanceAdapted=YES;self.navigatorMoveFraction=.1;[self refreshNavigatorCameraDisplays];
    if(self.navigatorWindow.visible)[self requestNavigatorPreviewAdaptingDistance:NO];
}
- (void)beginNavigatorSlider { [self stopNavigatorExplore];self.navigatorSliderTracking=YES; }
- (void)endNavigatorSlider { self.navigatorSliderTracking=NO;[self scheduleNavigatorRefinement]; }
- (void)scheduleNavigatorRefinement {
    if(self.navigatorExploring)return;
    NSUInteger generation=self.navigatorGeneration,ticket=++self.navigatorRefinementTicket;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW,250*NSEC_PER_MSEC),dispatch_get_main_queue(),^{
        if(ticket!=self.navigatorRefinementTicket||generation!=self.navigatorGeneration||self.navigatorSliderTracking||!self.navigatorWindow.visible||self.navigatorPreviewStage>=2)return;
        self.navigatorPreviewStage++;self.previewPending=YES;
        if(!self.previewBusy)[self startNavigatorPreview];
    });
}
- (void)requestNavigatorPreview {[self requestNavigatorPreviewAdaptingDistance:YES];}
- (void)requestNavigatorPreviewAdaptingDistance:(BOOL)adaptDistance {
    [self refreshNavigatorCameraDisplays];
    if(self.parametersPendingRender)return;
    if(!self.formulaKnown||![self readNavigatorFormulaValues])return;
    self.navigatorDistanceAdapted=!adaptDistance;
    /* Let a coarse frame finish so continuous input cannot starve display.
       Coalesce newer edits; cancel costly refinement immediately. */
    if(self.navigatorRunningStage>0)render_cancel(self.navigatorCancelToken);self.navigatorPreviewStage=self.navigatorExploring?1:0;
    self.navigatorGeneration++;self.previewPending=YES;
    if(self.previewBusy)return;
    [self startNavigatorPreview];
}
- (void)startNavigatorPreview {
    if(self.mutagenBusy)[self stopMutagen];
    if(!self.previewPending||self.previewBusy)return;
    self.previewPending=NO;self.previewBusy=YES;
    NSUInteger generation=self.navigatorGeneration,mainGeneration=self.generation,motionEpoch=self.navigatorMotionEpoch;
    NSInteger stage=self.navigatorPreviewStage;self.navigatorRunningStage=stage;
    RenderCancelToken *token=render_cancel_create();self.navigatorCancelToken=token;
    RenderOptions options=[self applyNavigatorFormulas:self.formulaSettings];options.cancel_token=token;options.camera_override=1;options.camera=self.navigatorCamera;
    NSArray *inflightMoves=@[];
    if(self.fixedZoomCheck.state!=NSControlStateValueOn&&self.navigatorMoves.count) {
        options.navigation_count=(int)MIN(32,self.navigatorMoves.count);
        options.navigation_fraction=self.navigatorMoveFraction;
        for(int i=0;i<options.navigation_count;i++){
            int operation=self.navigatorMoves[i].intValue;
            options.navigation_operations[i]=operation;
        }
        inflightMoves=[self.navigatorMoves subarrayWithRange:NSMakeRange(0,options.navigation_count)];
        [self.navigatorMoves removeObjectsInRange:NSMakeRange(0,options.navigation_count)];
    }
    options=navigatorPreviewOptions(options,stage);
    BOOL exploreFrame=self.navigatorExploring;NSUInteger exploreRun=self.navigatorExploreRun;NSInteger exploreSlot=self.navigatorFormulaSlot;
    NSString *path=self.currentPath;
    self.navigatorStatus.stringValue=@"Rendering preview… Main viewpoint is unchanged until Apply to Main.";
    double deMultiplier=self.navigatorDEMultiplier;
    dispatch_async(self.renderQueue,^{
        RenderResult result=render_navigator_with_options(path.fileSystemRepresentation,options,deMultiplier);
        interactiveUI(^{
            self.previewBusy=NO;
            if(self.navigatorCancelToken==token)self.navigatorCancelToken=NULL;
            render_cancel_destroy(token);
            if(result.cancelled&&!result.navigation_applied&&motionEpoch==self.navigatorMotionEpoch&&mainGeneration==self.generation&&inflightMoves.count)
                [self.navigatorMoves insertObjects:inflightMoves atIndexes:[NSIndexSet indexSetWithIndexesInRange:NSMakeRange(0,inflightMoves.count)]];
            if(result.navigation_applied&&options.navigation_count&&mainGeneration==self.generation&&motionEpoch==self.navigatorMotionEpoch) {
                CameraSettings camera=self.navigatorCamera;
                memcpy(camera.origin,result.settings.camera.origin,sizeof camera.origin);
                camera.zoom=result.settings.camera.zoom;
                camera.distance=result.settings.camera.distance;
                self.navigatorCamera=camera;
                self.navigatorDEMultiplier=result.navigator_de_multiplier;
                self.navigatorDistanceAdapted=YES;
                double width=MAX(16,self.formulaSettings.width),height=MAX(16,self.formulaSettings.height);
                self.navigatorLocalDistance=2*hypot(width,height)/(width*camera.zoom);
                self.moveStepField.doubleValue=fmin(1e9,self.navigatorMoveFraction*self.navigatorLocalDistance);
                self.navigatorFarField.doubleValue=fmax(.001,fmin(10000,camera.distance/self.navigatorLocalDistance));
                [self refreshNavigatorCameraDisplays];
            }
            if(self.navigatorMoves.count&&motionEpoch==self.navigatorMotionEpoch)self.previewPending=YES;
            if(mainGeneration==self.generation&&self.navigatorWindow.visible&&(generation==self.navigatorGeneration||(stage==0&&self.previewPending))) {
                if(result.rgba) {
                    if(generation==self.navigatorGeneration)[self adaptNavigatorDistance:result.local_distance];
                    NSBitmapImageRep *bitmap=[[NSBitmapImageRep alloc] initWithBitmapDataPlanes:NULL pixelsWide:result.width pixelsHigh:result.height
                        bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSCalibratedRGBColorSpace
                        bitmapFormat:NSBitmapFormatAlphaNonpremultiplied bytesPerRow:result.stride bitsPerPixel:32];
                    if(bitmap) {
                        memcpy(bitmap.bitmapData,result.rgba,result.stride*result.height);
                        NSImage *image=[[NSImage alloc] initWithSize:NSMakeSize(result.width,result.height)];[image addRepresentation:bitmap];self.navigatorView.image=image;
                        if(exploreFrame&&exploreRun==self.navigatorExploreRun&&generation==self.navigatorGeneration)[self recordNavigatorExploreSlot:options.program.slots[exploreSlot]];
                        self.navigatorStatus.stringValue=@"W/S/A/D/C/E move, J/L/I/K or arrows look, U/O roll; Shift fine, +/− zoom, F1/F2 far plane.";
                    } else self.navigatorStatus.stringValue=@"Not enough memory to display preview.";
                } else if(!result.rgba&&!result.cancelled)self.navigatorStatus.stringValue=[NSString stringWithUTF8String:result.error];
            }
            if(generation==self.navigatorGeneration&&!self.previewPending){
                if(self.navigatorExploring){
                    if(result.cancelled||!result.rgba)[self stopNavigatorExplore];
                    else {NSUInteger ticket=self.navigatorExploreTicket;dispatch_after(dispatch_time(DISPATCH_TIME_NOW,300*NSEC_PER_MSEC),dispatch_get_main_queue(),^{if(self.navigatorExploring&&ticket==self.navigatorExploreTicket)[self advanceNavigatorExplore];});}
                }else if(!result.cancelled)[self scheduleNavigatorRefinement];
            }
            free(result.rgba);if(self.previewPending)[self startNavigatorPreview];else if(self.navigatorAddPending){self.navigatorAddPending=NO;[self addNavigatorToAnimation:nil];}else if(self.navigatorApplyPending){self.navigatorApplyPending=NO;[self navigateOperation:15];}
        });
    });
}
- (void)fitColors:(id)sender {
    (void)sender;if(self.calculating||!self.colorFitValid)return;
    BOOL trap=self.orbitCheck.state==NSControlStateValueOn;
    int lo=trap?self.trapStart:self.fitStart,hi=trap?self.trapEnd:self.fitEnd;
    int start=(int)lround(90*sqrt((lo+10900)/32767.)-30);
    int end=(int)lround(90*sqrt((hi+10900)/32767.)-30);
    if(start==end){if(start>0)start--;else end++;}
    self.objectFields[2].intValue=start;self.objectFields[3].intValue=end;
    self.objectSliders[2].intValue=start;self.objectSliders[3].intValue=end;
    self.lightingStatus.stringValue=@"Range fitted to the last main render (0.05% trimmed at each end).";
    self.histogramZoomButtons[0].state=NSControlStateValueOn;[self histogramZoomChanged:self.histogramZoomButtons[0]];
    [self finishLightingSlider];
}
- (void)beginLightingSlider {
    self.gammaRepaint=NO;self.lightingSliderTracking=YES;
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(finishLightingSlider) object:nil];
}
- (void)endLightingSlider {
    self.lightingSliderTracking=NO;[self finishLightingSlider];
}
- (void)finishLightingSlider {
    if(self.lightingSliderTracking)return;
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(finishLightingSlider) object:nil];
    if(self.cuttingColorRepaintPending){self.cuttingColorRepaintPending=NO;[self requestLightingPreview];return;}
    self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;
    if(!self.calculating){self.lightingRepaintRequested=YES;[self calculate:nil];self.lightingRepaintRequested=NO;}
    self.gammaRepaint=NO;
}
- (void)requestGammaPreview {
    self.gammaRepaint=YES;[self queueLightingPreview];
}
- (void)requestLightingPreview {
    self.gammaRepaint=NO;[self queueLightingPreview];
}
- (void)queueLightingPreview {
    if(self.parametersPendingRender)return;
    if(!self.formulaKnown||self.calculating)return;
    /* Give lighting edits priority over background Navigator refinement. */
    render_cancel(self.navigatorCancelToken);self.navigatorRefinementTicket++;
    self.glowCacheReady=NO;[self syncTransparencyControls];
    self.lightingPreviewGeneration++;self.lightingPreviewPending=YES;
    if(!self.lightingPreviewBusy)[self startLightingPreview];
}
- (void)startLightingPreview {
    if(!self.lightingPreviewPending||self.calculating)return;
    RenderOptions options=self.formulaSettings;
    if(self.lightingWindow&&(![self readObjectLighting:&options.object]||![self readLights:&options]))return;
    if(![self readShadowSettings:&options]||![self readDepthFog:&options]||![self readAmbientLighting:&options]||![self readDepthOfField:&options]||![self readReflections:&options])return;
    options.object_override=1;
    options.reuse_surface=1;
    self.lightingPreviewPending=NO;self.lightingPreviewBusy=YES;
    BOOL saveLightingHistory=!self.lightingSliderTracking;
    BOOL preserveReflections=self.gammaRepaint;
    NSUInteger generation=self.lightingPreviewGeneration,mainGeneration=self.generation;NSString *path=self.currentPath;
    self.lightingStatus.stringValue=@"Updating lighting and shadows…";
    dispatch_async(self.renderQueue,^{
        unsigned char *sharp=NULL;RenderOptions repaint=options;repaint.reflections_override=1;repaint.reflections.enabled=preserveReflections?options.reflections.enabled:0;RenderResult result=render_scene_capturing_sharp(path.fileSystemRepresentation,repaint,NULL,&sharp);result.settings.reflections=options.reflections;
        interactiveUI(^{
            self.lightingPreviewBusy=NO;
            if((generation==self.lightingPreviewGeneration||self.lightingPreviewPending)&&mainGeneration==self.generation&&!self.calculating) {
                if(result.rgba) {
                    NSImage *image=imageForRender(result,MAX(1,result.settings.viewing));if(image){if(saveLightingHistory&&generation==self.lightingPreviewGeneration)[self recordLightingRepaint:options];[self displayRenderInfo:result];self.imageView.image=image;RenderResult sharpResult=result;sharpResult.rgba=sharp;self.sharpRenderImage=sharp?imageForRender(sharpResult,MAX(1,result.settings.viewing)):nil;}
                }else self.lightingStatus.stringValue=[NSString stringWithUTF8String:result.error];
            }
            free(sharp);free(result.rgba);if(self.lightingPreviewPending&&!self.calculating)[self startLightingPreview];
        });
    });
}
- (void)lightStrengthChanged:(NSSlider *)sender {
    [(NSTextField *)self.lightControls[sender.tag][3] setStringValue:[NSString stringWithFormat:@"%.17g",sender.doubleValue]];[self requestLightingPreview];
}
- (void)stepLightStrength:(NSStepper *)sender {
    NSInteger direction=sender.integerValue;sender.integerValue=0;if(!direction||self.calculating)return;
    [self.lightingWindow endEditingFor:nil];
    NSTextField *field=(NSTextField *)self.lightControls[sender.tag][3];double value;
    NSScanner *scanner=[NSScanner scannerWithString:numericInputString(field)];
    if(![scanner scanDouble:&value]||!scanner.isAtEnd||!isfinite(value)||value<0||value>1e10){self.lightingStatus.stringValue=@"Enter a finite light strength from 0 to 10000000000.";return;}
    value=fmin(1e10,value*(direction>0?1.414:.707));
    field.stringValue=[NSString stringWithFormat:@"%.17g",value];
    [self lightValuesEdited:sender];
}
- (CameraSettings)lightSliderCamera {
    CameraSettings camera=self.formulaSettings.camera;double norm=0;for(int k=0;k<3;k++)norm+=camera.axes[k]*camera.axes[k];
    if(!(norm>0)){camera=(CameraSettings){.axes={1,0,0,0,1,0,0,0,1}};}
    return camera;
}
- (double)screenLightCoordinate:(NSInteger)light axis:(NSInteger)axis {
    CameraSettings camera=[self lightSliderCamera];double coordinate=0;
    for(int k=0;k<3;k++)coordinate+=([(NSTextField *)self.lightControls[light][4+k] doubleValue]-camera.origin[k])*camera.axes[axis*3+k];
    return axis==1?-coordinate:coordinate;
}
- (void)positionalLightSliderReleased:(LiveSlider *)slider {
    if(!slider||[(NSPopUpButton *)self.lightControls[slider.tag/3][1] indexOfSelectedItem]!=1)return;
    if(slider.trackingValue>slider.minValue&&slider.trackingValue<slider.maxValue)return;
    double value=slider.doubleValue,radius=(slider.maxValue-slider.minValue)*.5;
    if(!(radius>0)||!isfinite(value-radius)||!isfinite(value+radius))return;
    slider.minValue=value-radius;slider.maxValue=value+radius;slider.doubleValue=value;slider.lightPositionRange=YES;
}
- (void)lightSliderChanged:(NSSlider *)sender {
    NSInteger light=sender.tag/3,axis=sender.tag%3;
    BOOL positional=[(NSPopUpButton *)self.lightControls[light][1] indexOfSelectedItem]==1;
    if(positional){
        LiveSlider *slider=(LiveSlider *)sender;double change=sender.doubleValue-slider.lastActionValue;slider.lastActionValue=sender.doubleValue;
        CameraSettings camera=[self lightSliderCamera];double width=fmax(1,self.formulaSettings.width),height=fmax(1,self.formulaSettings.height);
        double step=2.1345/(fmax(1e-12,camera.zoom)*width),fov=camera.optic==2?180:camera.fov;
        double half=fmin(180,fabs(fov))*M_PI/360;
        double offset=camera.optic==2?0:step*height*.5*cos(half)/fmax(.01,sin(half));
        double position[3],view[3],distance=0;
        for(int k=0;k<3;k++){position[k]=[(NSTextField *)self.lightControls[light][4+k] doubleValue];view[k]=position[k]-(camera.origin[k]-camera.axes[6+k]*offset);distance+=view[k]*view[k];}
        distance=sqrt(distance);
        // LightAdjust.TrackBar16Change: world movement per original slider unit.
        double scale=(step+distance*sin(fov*M_PI/180/height))*hypot(width,height)*.0025;
        double delta=change*scale*(axis==1?-1:1);if(!isfinite(delta))return;
        for(int k=0;k<3;k++){double direction=axis==2?(distance>1e-30?view[k]/distance:camera.axes[6+k]):camera.axes[axis*3+k];NSTextField *field=(NSTextField *)self.lightControls[light][4+k];field.stringValue=[NSString stringWithFormat:@"%.17g",position[k]+delta*direction];}
    }else{
        [(NSTextField *)self.lightControls[light][4+axis] setStringValue:[NSString stringWithFormat:@"%.17g",(axis==0?-1:1)*sender.doubleValue]];
    }
    [self requestLightingPreview];
}
- (void)lightValuesEdited:(NSControl *)sender {
    (void)sender;[self syncLightSliders];[self syncLightSourceLabels];[self requestLightingPreview];
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(finishLightingSlider) object:nil];
    if(!self.lightingSliderTracking)[self performSelector:@selector(finishLightingSlider) withObject:nil afterDelay:.2 inModes:@[NSRunLoopCommonModes]];
}
- (void)lightEnabledChanged:(NSButton *)sender {
    NSArray *controls=self.lightControls[sender.tag];
    if(sender.state==NSControlStateValueOn) {
        NSTextField *strength=(NSTextField *)controls[3];
        if(strength.doubleValue==0)strength.stringValue=@"1";
        NSColorWell *well=(NSColorWell *)controls[2];
        NSColor *color=[well.color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];
        if(color&&color.redComponent==0&&color.greenComponent==0&&color.blueComponent==0)
            well.color=[NSColor colorWithSRGBRed:1 green:1 blue:1 alpha:1];
    }
    [self syncLightSourceLabels];[self finishLightingSlider];
}
- (void)syncLightSliders {

    for(NSUInteger i=0;i<self.lightControls.count;i++){
        BOOL positional=[(NSPopUpButton *)self.lightControls[i][1] indexOfSelectedItem]==1;
        [(NSControl *)self.lightControls[i][7] setHidden:positional];
        self.lightMoveSteps[i].hidden=!positional;
        [self.lightMoveSteps[i].superview viewWithTag:900+i].hidden=!positional;
        for(NSUInteger j=0;j<5;j++)self.positionControls[i*5+j].hidden=!positional;
    }
    for(NSUInteger i=0;i<self.lightVisibilityControls.count;i++)self.lightVisibilityControls[i].hidden=[(NSPopUpButton *)self.lightControls[i/2][1] indexOfSelectedItem]!=1;
    for(NSUInteger i=0;i<self.lightStrengthSliders.count;i++){NSSlider *slider=self.lightStrengthSliders[i];double v=[(NSTextField *)self.lightControls[i][3] doubleValue];slider.maxValue=fmax(5,fmin(1e10,v*2));slider.doubleValue=v;slider.enabled=!self.calculating;self.lightStrengthSteppers[i].enabled=!self.calculating;}
    for(int i=0;i<6;i++)for(int axis=0;axis<3;axis++) {
        BOOL point=[(NSPopUpButton *)self.lightControls[i][1] indexOfSelectedItem]!=0;
        NSSlider *slider=self.lightSliders[i][axis];double direction=(!point&&axis==0)||(point&&axis==1)?-1:1;
        double value=direction*[(NSTextField *)self.lightControls[i][4+axis] doubleValue];
        slider.toolTip=point?@[@"Screen X: left to right. Movement follows camera zoom and light distance; Shift gives finer control.",@"Screen Y: down to up. Movement follows camera zoom and light distance; Shift gives finer control.",@"Depth along the camera-to-light line. Movement follows camera zoom and light distance; Shift gives finer control."][axis]:@"Light direction angle";
        LiveSlider *live=(LiveSlider *)slider;
        if(point){
            // Keep the thumb's position across edits and renders. Only an
            // endpoint release recenters it, unlike the original spring-back.
            if(!live.lightPositionRange){slider.minValue=-180;slider.maxValue=180;slider.doubleValue=0;live.lastActionValue=0;}
        }else{slider.minValue=axis<2?fmin(-180,value):fmin(-10,value);slider.maxValue=axis<2?fmax(180,value):fmax(10,value);slider.doubleValue=value;}
        live.lightPositionRange=point;slider.enabled=!self.calculating&&(point||axis<2);
    }
    for(NSUInteger i=0;i<self.lightControls.count;i++)if(self.formulaSettings.lights[i].option&2){
        for(NSControl *control in self.lightControls[i]){control.enabled=NO;control.toolTip=@"Imported light map source: preserved for rendering and saving; no editor is available.";}
        self.lightStrengthSliders[i].enabled=NO;self.lightStrengthSteppers[i].enabled=NO;for(NSSlider *slider in self.lightSliders[i])slider.enabled=NO;
    }
}

/* Active means applied or enabled for automatic calculation, consistent with
 * the settings consumed by the post-processing readers. */
- (BOOL)resettingPostProcess {
    return self.resettingReflections||self.resettingHardShadows||self.resettingAmbientShadows;
}
- (void)syncPostProcessLabels {
    if(![self.postWindow.contentView isKindOfClass:NSTabView.class])return;
    NSTabView *tabs=(NSTabView *)self.postWindow.contentView;
    NSArray *names=@[@"Hard Shadows",@"Ambient Shadows",@"Refl/Trans",@"Depth of Field"];
    BOOL active[]={self.hardShadowsApplied||self.shadowAutoChecks[0].state==NSControlStateValueOn,
        self.ambientShadowsApplied||self.shadowAutoChecks[1].state==NSControlStateValueOn,
        self.reflectionsApplied||self.reflectionAutomatic.state==NSControlStateValueOn,
        self.dofApplied||self.dofAutomatic.state==NSControlStateValueOn};
    for(NSUInteger i=0;i<MIN(names.count,(NSUInteger)tabs.numberOfTabViewItems);i++)[tabs tabViewItemAtIndex:i].label=[names[i] stringByAppendingString:active[i]?@"*":@""];
}
- (void)postProcessAutomaticChanged:(NSButton *)sender {
    if(sender.state==NSControlStateValueOff){
        RenderOptions settings=self.formulaSettings;
        if(sender==self.shadowAutoChecks[0]){self.hardShadowsApplied=NO;settings.shadows.hard_auto=0;settings.shadows.hard_enabled=0;}
        if(sender==self.shadowAutoChecks[1]){self.ambientShadowsApplied=NO;settings.shadows.ambient_auto=0;settings.shadows.ambient_enabled=0;}
        self.formulaSettings=settings;
    }
    [self syncPostProcessLabels];
}
- (void)showPostProcess:(id)sender {
    (void)sender;
    if(!self.postWindow) {
        self.postWindow=[[NSWindow alloc] initWithContentRect:NSMakeRect(0,0,540,440) styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable backing:NSBackingStoreBuffered defer:NO];
        self.postWindow.title=@"Post-process";self.postWindow.releasedWhenClosed=NO;self.postWindow.delegate=self;
        NSTabView *tabs=[[NSTabView alloc] initWithFrame:NSMakeRect(12,12,516,416)];
        NSMutableArray *fields=[NSMutableArray array],*checks=[NSMutableArray array],*buttons=[NSMutableArray array],*ambientSliders=[NSMutableArray array];
        for(int tabIndex=0;tabIndex<2;tabIndex++) {
            NSTabViewItem *tab=[[NSTabViewItem alloc] initWithIdentifier:@(tabIndex)];tab.label=tabIndex?@"Ambient Shadows":@"Hard Shadows";
            CalculationPanel *panel=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,492,380)];
            NSButton *enable=[NSButton checkboxWithTitle:tabIndex?@"Calculate ambient shadows automatically":@"Calculate hard shadows automatically" target:nil action:nil];
            enable.target=self;enable.action=@selector(postProcessAutomaticChanged:);
            enable.frame=NSMakeRect(16,14,460,24);[panel addSubview:enable];[checks addObject:enable];
            if(!tabIndex) {
                NSMutableArray *lights=[NSMutableArray array];
                for(int i=0;i<6;i++) {
                    NSButton *light=[NSButton checkboxWithTitle:[NSString stringWithFormat:@"Light %d",i+1] target:nil action:nil];light.frame=NSMakeRect(16+(i%3)*155,52+(i/3)*32,150,24);[panel addSubview:light];[lights addObject:light];
                }
                self.shadowLightChecks=lights;
                self.softShadowCheck=[NSButton checkboxWithTitle:@"Softer hard shadows" target:nil action:nil];self.softShadowCheck.frame=NSMakeRect(16,122,230,24);[panel addSubview:self.softShadowCheck];
                self.cosineShadowCheck=[NSButton checkboxWithTitle:@"Set light function to cosine" target:nil action:nil];self.cosineShadowCheck.frame=NSMakeRect(16,154,400,24);[panel addSubview:self.cosineShadowCheck];
            }else {
                NSTextField *label=[NSTextField labelWithString:@"Method"];label.frame=NSMakeRect(16,54,120,22);[panel addSubview:label];
                self.ambientMethod=[[NSPopUpButton alloc] initWithFrame:NSMakeRect(210,50,264,28) pullsDown:NO];[self.ambientMethod addItemsWithTitles:@[@"Fast approximation",@"DE ray tracing",@"SSAO 24-bit",@"SSAO 24-bit random"]];[panel addSubview:self.ambientMethod];
            }
            NSArray *names=tabIndex?@[@"Strength (0–5)",@"Max length (0.001–100)",@"Rays (1–64)",@"Max steps (8–512)"]:@[@"Max length (0.001–100)",@"Radius (0.001–100)"];
            for(NSUInteger i=0;i<names.count;i++) {
                CGFloat y=(tabIndex?94:196)+i*34;
                NSTextField *label=[NSTextField labelWithString:names[i]];label.frame=NSMakeRect(16,y+4,260,22);[panel addSubview:label];
                NSTextField *field=[[NumericTextField alloc] initWithFrame:tabIndex?NSMakeRect(382,y,92,26):NSMakeRect(300,y,174,26)];numericIntegerField(field,tabIndex&&i>=2);field.accessibilityLabel=[NSString stringWithFormat:@"%@ %@",tab.label,names[i]];[panel addSubview:field];[fields addObject:field];
                if(tabIndex){
                    label.frame=NSMakeRect(16,y+4,166,22);
                    double low[]={0,-3,1,8},high[]={5,2,64,512};
                    LiveSlider *slider=[LiveSlider sliderWithValue:low[i] minValue:low[i] maxValue:high[i] target:self action:@selector(ambientShadowSliderChanged:)];slider.frame=NSMakeRect(184,y,184,26);slider.tag=i;slider.continuous=YES;slider.accessibilityLabel=field.accessibilityLabel;slider.toolTip=i==1?@"Logarithmic length scale, 0.001–100. Hold Shift for fine control.":@"Hold Shift for fine control.";
                    __weak AppDelegate *weakSelf=self;slider.started=^{[weakSelf beginLightingSlider];};slider.finished=^{[weakSelf endLightingSlider];};[panel addSubview:slider];[ambientSliders addObject:slider];
                    field.tag=i;field.target=self;field.action=@selector(ambientShadowValueEdited:);
                }
            }
            NSTextField *hint=[NSTextField wrappingLabelWithString:tabIndex?@"DE ray tracing samples the surface hemisphere. More rays and steps increase quality and rendering time. SSAO uses cached screen-space depth; random sampling uses a repeatable seed.":@"Shadows are traced for the selected lights. Radius controls softness. Max length scales the scene’s ray distance."];
            hint.frame=NSMakeRect(16,tabIndex?240:274,458,58);hint.font=[NSFont systemFontOfSize:11];[panel addSubview:hint];
            for(int i=0;i<2;i++) {
                NSButton *button=[NSButton buttonWithTitle:i?@"Calculate now":@"Reset shadows" target:self action:@selector(postProcessAction:)];button.tag=tabIndex*2+i;button.frame=NSMakeRect(16+i*238,340,220,32);[panel addSubview:button];[buttons addObject:button];
            }
            tab.view=panel;[tabs addTabViewItem:tab];
        }
        self.shadowFields=fields;self.shadowAutoChecks=checks;self.postButtons=buttons;self.ambientShadowSliders=ambientSliders;
        [self addReflectionTab:tabs];[self addDepthOfFieldTab:tabs];
        self.postWindow.contentView=tabs;[self.postWindow center];[self populateShadowSettings];
    }
    [self syncPostProcessLabels];[self setCalculating:self.calculating];[self positionWindowRightOfMain:self.postWindow];[self.postWindow makeKeyAndOrderFront:nil];
}
- (void)addReflectionTab:(NSTabView *)tabs {
    NSTabViewItem *tab=[[NSTabViewItem alloc]initWithIdentifier:@"reflections"];tab.label=@"Refl/Trans";
    CalculationPanel *panel=[[CalculationPanel alloc]initWithFrame:NSMakeRect(0,0,492,380)];NSMutableArray *controls=[NSMutableArray array],*fields=[NSMutableArray array];
    self.reflectionAutomatic=[NSButton checkboxWithTitle:@"Calculate Reflections (and, if selected, Transparency) automatically" target:self action:@selector(reflectionEdited:)];self.reflectionAutomatic.frame=NSMakeRect(16,14,458,24);[panel addSubview:self.reflectionAutomatic];[controls addObject:self.reflectionAutomatic];
    NSArray *labels=@[@"Amount (0–1)",@"Depth (1–30)",@"Absorption (0–10000000000)",@"Refractive index (0.1–10)",@"Light scattering"];
    NSArray *tips=@[@"Total amount of reflectivity + transparency, 0–100, multiplied by the local object specular color and transparency amount. The slider normally spans 0–1 and expands for larger values.",@"Depth of reflections: 1 shows one reflection; 2 also shows reflections in the reflected object, and so on.",@"Absolute absorption amount inside the material (high zooms need big values). The diffuse object color is also used inside.",@"Refractive index of the material: air ≈ 1, water ≈ 1.33, glass ≈ 1.5, diamond ≈ 2.4.",@"Light scattered inside transparent material. Higher values brighten longer paths. Press Calculate now to apply."];
    self.reflectionAutomatic.toolTip=@"Calculate reflections and transparency automatically after the preceding calculations on subsequent renders. Editing these controls does not start a render.";
    for(int i=0;i<5;i++){CGFloat y=i<2?50+i*44:158+(i-2)*38;NSTextField *label=[NSTextField labelWithString:labels[i]];label.frame=NSMakeRect(16,y+4,i==0?120:270,22);label.toolTip=tips[i];[panel addSubview:label];NSTextField *field=[[NumericTextField alloc]initWithFrame:NSMakeRect(302,y,i==1?136:172,26)];numericIntegerField(field,i==1);field.target=self;field.action=@selector(reflectionEdited:);field.toolTip=tips[i];field.accessibilityLabel=[@"Reflections " stringByAppendingString:labels[i]];[panel addSubview:field];[fields addObject:field];[controls addObject:field];}
    self.reflectionAmountSlider=[LiveSlider sliderWithValue:1 minValue:0 maxValue:1 target:self action:@selector(reflectionAmountChanged:)];self.reflectionAmountSlider.frame=NSMakeRect(140,50,152,26);self.reflectionAmountSlider.continuous=YES;self.reflectionAmountSlider.toolTip=tips[0];self.reflectionAmountSlider.accessibilityLabel=@"Reflection amount";[panel addSubview:self.reflectionAmountSlider];[controls addObject:self.reflectionAmountSlider];
#ifdef USE_RUST_ENGINE
    self.translucencyCheck=[NSButton checkboxWithTitle:@"Translucency" target:self action:@selector(reflectionEdited:)];
    self.translucencyCheck.frame=NSMakeRect(16,286,110,26);
    self.translucencyCheck.toolTip=@"Calculate translucency during the reflection and transparency pass.";
    [panel addSubview:self.translucencyCheck];
    [controls addObject:self.translucencyCheck];
    self.subsurfaceCheck=[NSButton checkboxWithTitle:@"Subsurface scattering" target:self action:@selector(subsurfaceChanged:)];
    self.subsurfaceCheck.frame=NSMakeRect(16,314,198,24);
    self.subsurfaceCheck.toolTip=@"Trace light through the material, with absorption and internal scattering. Adds light rays when enabled.";
    [panel addSubview:self.subsurfaceCheck];[controls addObject:self.subsurfaceCheck];
    NSTextField *sssLabel=[NSTextField labelWithString:@"Amount"];sssLabel.font=self.subsurfaceCheck.font;NSRect sssTitle=[self.subsurfaceCheck.cell titleRectForBounds:self.subsurfaceCheck.bounds];NSSize sssSize=sssLabel.intrinsicContentSize;sssLabel.frame=NSMakeRect(216,round(NSMinY(self.subsurfaceCheck.frame)+NSMidY(sssTitle)-sssSize.height/2),52,sssSize.height);[panel addSubview:sssLabel];
    LiveSlider *sssAmount=[LiveSlider sliderWithValue:1 minValue:0 maxValue:1 target:self action:@selector(subsurfaceAmountChanged:)];
    sssAmount.frame=NSMakeRect(272,313,106,26);sssAmount.continuous=YES;self.subsurfaceAmountSlider=sssAmount;
    __weak AppDelegate *sssOwner=self;sssAmount.finished=^{[sssOwner recalculateSubsurface];};
    sssAmount.toolTip=@"Higher amounts make the material scatter more strongly. Zero preserves ordinary translucency. Recalculates light paths when released.";
    [panel addSubview:sssAmount];[controls addObject:sssAmount];
    self.subsurfaceAmountField=[[NumericTextField alloc]initWithFrame:NSMakeRect(388,313,86,26)];
    self.subsurfaceAmountField.target=self;self.subsurfaceAmountField.action=@selector(subsurfaceAmountEdited:);
    self.subsurfaceAmountField.toolTip=sssAmount.toolTip;[panel addSubview:self.subsurfaceAmountField];[controls addObject:self.subsurfaceAmountField];

    NSArray *translucencyLabels=@[@"Strength",@"Glow"];
    NSArray *translucencyTips=@[@"Soften transmitted light and increase opacity on longer paths.",
        @"Negative values favor clear edges. Positive values favor the opaque interior. Cmd-click the slider to reset to zero."];
    for(int i=0;i<2;i++){
        CGFloat x=i?310:130;
        NSTextField *label=[NSTextField labelWithString:translucencyLabels[i]];
        label.font=self.translucencyCheck.font;
        // Align with the visible checkbox title, whose AppKit baseline anchor
        // sits above the text drawn by the checkbox cell.
        NSRect titleRect=[self.translucencyCheck.cell titleRectForBounds:self.translucencyCheck.bounds];
        CGFloat titleCenter=NSMinY(self.translucencyCheck.frame)+NSMidY(titleRect);
        NSSize labelSize=label.intrinsicContentSize;
        label.frame=NSMakeRect(x,round(titleCenter-labelSize.height/2),i?36:54,labelSize.height);
        [panel addSubview:label];
        LiveSlider *slider=[LiveSlider sliderWithValue:i?0:1 minValue:i?-1:0 maxValue:i?1:2
            target:self action:i?@selector(translucencyGlowChanged:):@selector(translucencyStrengthChanged:)];
        slider.frame=NSMakeRect(x+(i?36:54),286,i?62:66,26);
        slider.continuous=YES;
        slider.accessibilityLabel=[NSString stringWithFormat:@"Translucency %@ slider",translucencyLabels[i]];
        slider.toolTip=translucencyTips[i];
        if(i){slider.commandResetValue=@0;self.translucencyGlowSlider=slider;}
        else self.translucencyStrengthSlider=slider;
        [panel addSubview:slider];
        [controls addObject:slider];
        NSTextField *field=[[NumericTextField alloc] initWithFrame:NSMakeRect(i?412:254,286,i?62:51,26)];
        field.target=self;
        field.action=@selector(reflectionEdited:);
        field.accessibilityLabel=[@"Translucency " stringByAppendingString:translucencyLabels[i]];
        field.toolTip=translucencyTips[i];
        [panel addSubview:field];
        [fields addObject:field];
        [controls addObject:field];
    }
#endif
    self.reflectionFields=fields;self.reflectionDepth=[[NSStepper alloc]initWithFrame:NSMakeRect(446,93,22,28)];self.reflectionDepth.minValue=1;self.reflectionDepth.maxValue=30;self.reflectionDepth.increment=1;self.reflectionDepth.toolTip=tips[1];self.reflectionDepth.target=self;self.reflectionDepth.action=@selector(reflectionDepthChanged:);[panel addSubview:self.reflectionDepth];[controls addObject:self.reflectionDepth];
    self.reflectionTransparency=[NSButton checkboxWithTitle:@"Calculate transparency" target:self action:@selector(reflectionEdited:)];self.reflectionTransparency.toolTip=@"If enabled, the specular amount is split into an inside-going ray and a reflection.";self.reflectionTransparency.frame=NSMakeRect(16,125,238,24);[panel addSubview:self.reflectionTransparency];[controls addObject:self.reflectionTransparency];
    self.reflectionOnlyDIFS=[NSButton checkboxWithTitle:@"Only DIFS" target:self action:@selector(reflectionEdited:)];self.reflectionOnlyDIFS.frame=NSMakeRect(258,125,100,24);self.reflectionOnlyDIFS.toolTip=
#ifdef USE_RUST_ENGINE
    @"Limit transparency to direct-distance IFS surfaces.";
#else
    @"Apply reflections and transparency only at direct-distance IFS surfaces; escape-time surfaces keep their original lighting.";
#endif
[panel addSubview:self.reflectionOnlyDIFS];[controls addObject:self.reflectionOnlyDIFS];
    for(int i=0;i<2;i++){NSButton *button=[NSButton buttonWithTitle:i?@"Calculate now":@"Reset" target:self action:@selector(reflectionAction:)];button.toolTip=i?@"Enable automatic hard and ambient shadow calculation if you want those shadows considered in reflections.":@"Remove applied reflections and transparency without changing Automatically or the parameter values.";button.tag=i;button.frame=NSMakeRect(16+i*238,340,220,32);[panel addSubview:button];[controls addObject:button];}self.reflectionControls=controls;tab.view=panel;[tabs addTabViewItem:tab];
}
- (void)syncTransparencyControls {
    BOOL enabled=!self.calculating&&self.reflectionTransparency.state==NSControlStateValueOn;
    self.reflectionOnlyDIFS.enabled=enabled;
    self.translucencyCheck.enabled=enabled;
    BOOL translucency=enabled&&self.translucencyCheck.state==NSControlStateValueOn;
    self.subsurfaceCheck.enabled=translucency;
    self.subsurfaceAmountSlider.enabled=self.subsurfaceAmountField.enabled=translucency&&self.subsurfaceCheck.state==NSControlStateValueOn;
    BOOL livePreview=translucency&&self.glowCacheReady&&!self.parametersPendingRender&&self.completedRender!=nil;
    self.translucencyStrengthSlider.enabled=livePreview;
    self.translucencyGlowSlider.enabled=livePreview;
    self.translucencyStrengthSlider.toolTip=livePreview
        ?@"Adjust how much transmitted light softens and becomes opaque."
        :@"Live Strength adjustments require cached transmission data from the current render.";
    self.translucencyGlowSlider.toolTip=self.translucencyGlowSlider.enabled
        ?@"Adjust edge or interior glow on the current render. Cmd-click to reset to zero."
        :@"Live Glow adjustments require cached transmission data from the current render.";
    for(NSUInteger i=2;i<self.reflectionFields.count;i++)self.reflectionFields[i].enabled=i<5?enabled:translucency;
}
- (void)populateReflections {
    if(!self.reflectionFields.count)return;ReflectionSettings rf=self.formulaSettings.reflections;if(!rf.depth)rf=(ReflectionSettings){.depth=2,.amount=1,.absorption=.2,.refractive_index=1.5,.scattering=1};self.reflectionsApplied=rf.enabled;
    self.reflectionAutomatic.state=rf.automatic;self.reflectionTransparency.state=rf.transparency;self.reflectionOnlyDIFS.state=rf.only_difs;self.reflectionDepth.integerValue=rf.depth;self.translucencyCheck.state=self.formulaSettings.translucency_mode==2;self.subsurfaceCheck.state=self.formulaSettings.subsurface_scattering?NSControlStateValueOn:NSControlStateValueOff;self.subsurfaceAmountSlider.doubleValue=self.formulaSettings.subsurface_amount;self.subsurfaceAmountField.doubleValue=self.formulaSettings.subsurface_amount;[self syncTransparencyControls];
    self.reflectionAmountSlider.maxValue=fmax(1,rf.amount);self.reflectionAmountSlider.doubleValue=rf.amount;[self syncPostProcessLabels];
    double strength=self.formulaSettings.translucency_mode?self.formulaSettings.transmission_blur:1;
    self.translucencyStrengthSlider.doubleValue=strength;
    self.translucencyGlowSlider.doubleValue=self.formulaSettings.translucency_glow;
    double values[]={rf.amount,rf.depth,rf.absorption,rf.refractive_index,rf.scattering,strength,self.formulaSettings.translucency_glow};for(NSUInteger i=0;i<self.reflectionFields.count;i++)self.reflectionFields[i].stringValue=[NSString stringWithFormat:@"%.17g",values[i]];
}
- (BOOL)readReflections:(RenderOptions *)options {
    if(self.diffuseWells.count==10&&self.specularWells.count==10){if(!options->reflections.depth)options->reflections=(ReflectionSettings){.depth=2,.amount=1,.absorption=.2,.refractive_index=1.5,.scattering=1};options->reflections_override=1;options->reflections.opacity_set=1;for(int i=0;i<10;i++){options->reflections.opacity[0][i]=self.diffuseWells[i].color.alphaComponent;options->reflections.opacity[1][i]=self.specularWells[i].color.alphaComponent;}}
    if(!self.reflectionFields.count){options->reflections.enabled=options->reflections.automatic||(self.gammaRepaint&&(self.lightingRepaintRequested||self.lightingPreviewPending)&&self.reflectionsApplied);return YES;}ReflectionSettings previous=options->reflections;double values[7]={previous.amount,previous.depth,previous.absorption,previous.refractive_index,previous.scattering,options->transmission_blur,options->translucency_glow},low[]={0,1,0,.1,0,0,-1},high[]={100,30,1e10,10,1e30,2,1};
    for(NSUInteger i=0;i<self.reflectionFields.count;i++){double value;
        NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.reflectionFields[i])];
        if(![scanner scanDouble:&value]||!scanner.isAtEnd||!isfinite(value)||value<low[i]||value>high[i]||(i==1&&value!=floor(value))){
            if(i>=2&&self.reflectionTransparency.state!=NSControlStateValueOn)continue;
            self.statusLabel.stringValue=@"Check Reflections + Transparency values and ranges.";return NO;
        }
        values[i]=value;
    }
    options->translucency_mode=1+(self.translucencyCheck.state==NSControlStateValueOn);
    options->transmission_blur=values[5];
    options->translucency_glow=values[6];
    options->subsurface_scattering=self.subsurfaceCheck.state==NSControlStateValueOn;
    double sssAmount;NSScanner *sssScanner=[NSScanner scannerWithString:numericInputString(self.subsurfaceAmountField)];
    if(![sssScanner scanDouble:&sssAmount]||!sssScanner.isAtEnd||!isfinite(sssAmount)||sssAmount<0||sssAmount>1){
        if(self.subsurfaceAmountField.enabled){self.statusLabel.stringValue=@"Subsurface Amount must be between 0 and 1.";return NO;}
        sssAmount=isfinite(options->subsurface_amount)?fmax(0,fmin(1,options->subsurface_amount)):1;
        self.subsurfaceAmountField.doubleValue=sssAmount;self.subsurfaceAmountSlider.doubleValue=sssAmount;
    }
    options->subsurface_amount=sssAmount;
    options->reflections_override=1;options->reflections=(ReflectionSettings){.enabled=!self.resettingReflections&&(self.postProcessOnce==PostProcessReflections||([self resettingPostProcess]&&self.reflectionsApplied)||(self.gammaRepaint&&(self.lightingRepaintRequested||self.lightingPreviewPending)&&self.reflectionsApplied)||self.reflectionAutomatic.state==NSControlStateValueOn),.automatic=self.reflectionAutomatic.state==NSControlStateValueOn,.transparency=self.reflectionTransparency.state==NSControlStateValueOn,.only_difs=self.reflectionOnlyDIFS.state==NSControlStateValueOn,.depth=(int)values[1],.amount=values[0],.absorption=values[2],.refractive_index=values[3],.scattering=values[4]};options->reflections.opacity_set=previous.opacity_set;memcpy(options->reflections.opacity,previous.opacity,sizeof previous.opacity);return YES;
}
- (void)reflectionAction:(NSButton *)sender {self.resettingReflections=sender.tag==0;self.postProcessOnce=sender.tag?PostProcessReflections:PostProcessNone;[self calculate:nil];self.postProcessOnce=PostProcessNone;self.resettingReflections=NO;}
- (void)recalculateSubsurface {
    if(self.calculating)return;
    RenderOptions settings=self.formulaSettings;if(![self readReflections:&settings])return;
    self.formulaSettings=settings;self.glowCacheReady=NO;[self syncTransparencyControls];
    self.postProcessOnce=PostProcessReflections;[self calculate:nil];self.postProcessOnce=PostProcessNone;
}
- (void)subsurfaceChanged:(NSButton *)sender {
    (void)sender;if(self.calculating)return;
    RenderOptions settings=self.formulaSettings;
    settings.subsurface_scattering=self.subsurfaceCheck.state==NSControlStateValueOn;
    self.formulaSettings=settings;self.glowCacheReady=NO;
    [self syncTransparencyControls];
}
- (void)subsurfaceAmountChanged:(NSSlider *)sender {
    self.subsurfaceAmountField.stringValue=[NSString stringWithFormat:@"%.4f",sender.doubleValue];
}
- (void)subsurfaceAmountEdited:(id)sender {(void)sender;[self recalculateSubsurface];}
- (void)translucencyGlowChanged:(NSSlider *)sender {
    if(!sender.enabled)return;
    self.reflectionFields[6].stringValue=[NSString stringWithFormat:@"%.4f",sender.doubleValue];
    self.glowPreviewPending=YES;
    [self updateTranslucencyPreview];
}
- (void)updateTranslucencyPreview {
#ifdef USE_RUST_ENGINE
    if(self.glowPreviewBusy||!self.glowPreviewPending||!self.translucencyGlowSlider.enabled)return;
    self.glowPreviewPending=NO;
    // Replay the inputs that produced this cache, including one-shot effects.
    RenderOptions options=self.glowCacheOptions;
    options.transmission_blur=self.reflectionFields[5].doubleValue;
    options.translucency_glow=self.reflectionFields[6].doubleValue;
    options.subsurface_scattering=self.subsurfaceCheck.state==NSControlStateValueOn;
    options.subsurface_amount=self.subsurfaceAmountField.doubleValue;
    if(!self.dofApplied&&self.dofFields.count){
        options.dof=self.formulaSettings.dof;
        options.dof_override=1;
    }
    options.reuse_surface=2; // Require a hit before tracing any rays.
    self.glowPreviewBusy=YES;
    NSUInteger generation=self.generation, lightingGeneration=self.lightingPreviewGeneration;
    NSString *path=self.glowCacheSourcePath;
    dispatch_async(self.renderQueue,^{
        unsigned char *sharp=NULL;
        RenderResult result=render_scene_capturing_sharp(path.fileSystemRepresentation,options,NULL,&sharp);
        interactiveUI(^{
            self.glowPreviewBusy=NO;
            if(generation==self.generation&&lightingGeneration==self.lightingPreviewGeneration&&!self.calculating&&self.glowCacheReady){
                NSImage *image=result.rgba?imageForRender(result,MAX(1,result.settings.viewing)):nil;
                if(image){
                    // Actual Size changes the image's display size only.
                    if(self.imageView.imageScaling==NSImageScaleProportionallyDown)
                        image.size=self.imageView.image.size;
                    self.imageView.image=image;
                    self.completedRender=(NSBitmapImageRep *)image.representations.firstObject;
                    RenderResult sharpResult=result;sharpResult.rgba=sharp;
                    self.sharpRenderImage=sharp?imageForRender(sharpResult,MAX(1,result.settings.viewing)):nil;
                    RenderOptions current=self.formulaSettings;
                    current.transmission_blur=result.settings.transmission_blur;
                    current.translucency_glow=result.settings.translucency_glow;
                    self.formulaSettings=current;
                }else{
                    self.glowCacheReady=NO;
                    self.glowPreviewPending=NO;
                    self.statusLabel.stringValue=@"Translucency preview cache unavailable. Calculate transparency again to refresh it.";
                    [self syncTransparencyControls];
                }
            }
            free(sharp);free(result.rgba);
            [self updateTranslucencyPreview];
        });
    });
#endif
}
- (void)reflectionEdited:(id)sender {[self syncTransparencyControls];if(sender!=self.reflectionFields.lastObject&&(self.reflectionFields.count<7||sender!=self.reflectionFields[5])){self.glowCacheReady=NO;[self syncTransparencyControls];}if(sender==self.reflectionAutomatic)self.reflectionsApplied=self.reflectionAutomatic.state==NSControlStateValueOn;RenderOptions options=self.formulaSettings;if(![self readReflections:&options])return;self.reflectionDepth.integerValue=self.reflectionFields[1].integerValue;self.reflectionAmountSlider.maxValue=fmax(1,self.reflectionFields[0].doubleValue);self.reflectionAmountSlider.doubleValue=self.reflectionFields[0].doubleValue;if(self.reflectionFields.count==7){self.translucencyStrengthSlider.doubleValue=options.transmission_blur;self.translucencyGlowSlider.doubleValue=options.translucency_glow;}[self syncPostProcessLabels];}
- (void)translucencyStrengthChanged:(NSSlider *)sender {
    if(!sender.enabled)return;
    self.reflectionFields[5].stringValue=[NSString stringWithFormat:@"%.4f",sender.doubleValue];
    self.glowPreviewPending=YES;
    [self updateTranslucencyPreview];
}
- (void)reflectionAmountChanged:(NSSlider *)sender {self.reflectionFields[0].stringValue=[NSString stringWithFormat:@"%.17g",sender.doubleValue];[self reflectionEdited:sender];}
- (void)reflectionDepthChanged:(NSStepper *)sender {self.reflectionFields[1].integerValue=sender.integerValue;[self reflectionEdited:sender];}
- (void)addDepthOfFieldTab:(NSTabView *)tabs {
    NSTabViewItem *tab=[[NSTabViewItem alloc]initWithIdentifier:@"dof"];tab.label=@"Depth of Field";
    CalculationPanel *panel=[[CalculationPanel alloc]initWithFrame:NSMakeRect(0,0,490,390)];
    NSMutableArray *controls=[NSMutableArray array],*fields=[NSMutableArray array],*sliders=[NSMutableArray array];
    self.dofAutomatic=[NSButton checkboxWithTitle:@"Calculate DoF automatically" target:self action:@selector(dofEdited:)];self.dofAutomatic.frame=NSMakeRect(16,12,450,26);[panel addSubview:self.dofAutomatic];[controls addObject:self.dofAutomatic];
    NSArray *names=@[@"Z1 sharp",@"Z2 sharp",@"Aperture",@"Clipping radius"];
    __weak AppDelegate *weakSelf=self;
    for(int i=0;i<4;i++){
        CGFloat y=52+i*46;NSTextField *label=[NSTextField labelWithString:names[i]];label.frame=NSMakeRect(16,y+4,94,22);[panel addSubview:label];
        LiveSlider *slider=[LiveSlider sliderWithValue:0 minValue:0 maxValue:i<2?10:i==2?2:1000 target:self action:@selector(dofSliderChanged:)];slider.frame=NSMakeRect(144,y,146,26);slider.tag=i;slider.continuous=YES;slider.accessibilityLabel=[@"Depth of Field " stringByAppendingString:names[i]];slider.started=^{[weakSelf beginLightingSlider];};slider.finished=^{[weakSelf endLightingSlider];};[panel addSubview:slider];[sliders addObject:slider];[controls addObject:slider];
        NSTextField *field=[[NumericTextField alloc]initWithFrame:NSMakeRect(300,y,84,26)];field.target=self;field.action=@selector(dofEdited:);field.accessibilityLabel=slider.accessibilityLabel;field.toolTip=i<2?@"Depth from the viewer, normalized to image width. Use Get Z to pick a surface.":i==2?@"0–2; larger values increase blur.":@"Maximum blur radius in render pixels: 0.1–1000.";[panel addSubview:field];[fields addObject:field];[controls addObject:field];
        if(i<2){NSButton *pick=[NSButton buttonWithTitle:[NSString stringWithFormat:@"Get Z%d",i+1] target:self action:@selector(chooseDofFocus:)];pick.frame=NSMakeRect(392,y,82,26);pick.tag=i+1;[panel addSubview:pick];[controls addObject:pick];}
    }
    NSButton *copy=[NSButton buttonWithTitle:@"Copy Z1 to Z2" target:self action:@selector(copyDofFocus:)];copy.frame=NSMakeRect(16,242,180,28);[panel addSubview:copy];[controls addObject:copy];
    NSTextField *passLabel=[NSTextField labelWithString:@"Passes"];passLabel.frame=NSMakeRect(280,246,70,22);[panel addSubview:passLabel];
    self.dofPasses=[[NSPopUpButton alloc]initWithFrame:NSMakeRect(360,242,114,28) pullsDown:NO];[self.dofPasses addItemsWithTitles:@[@"1",@"2",@"3"]];self.dofPasses.target=self;self.dofPasses.action=@selector(dofEdited:);[panel addSubview:self.dofPasses];[controls addObject:self.dofPasses];
    NSTextField *hint=[NSTextField wrappingLabelWithString:@"Pick Z1 and Z2 on the object for a sharp depth range. Native depth-aware disc filtering uses cached depth; changes start from the sharp image."];hint.frame=NSMakeRect(16,282,458,48);hint.font=[NSFont systemFontOfSize:11];[panel addSubview:hint];
    for(int i=0;i<2;i++){NSButton *button=[NSButton buttonWithTitle:i?@"Calculate now":@"Reset DoF" target:self action:@selector(dofAction:)];button.tag=i;button.frame=NSMakeRect(16+i*238,340,220,32);[panel addSubview:button];[controls addObject:button];}
    self.dofFields=fields;self.dofSliders=sliders;self.dofControls=controls;tab.view=panel;[tabs addTabViewItem:tab];
}
- (void)populateDepthOfField {
    if(!self.dofFields.count)return;DepthOfFieldSettings d=self.formulaSettings.dof;
    if(!d.passes)d=(DepthOfFieldSettings){.passes=1,.aperture=.02,.clip_radius=25};
    self.dofApplied=d.enabled;self.dofAutomatic.state=d.automatic;[self.dofPasses selectItemAtIndex:d.passes-1];
    double values[]={d.focus1,d.focus2,d.aperture,d.clip_radius};
    for(int i=0;i<4;i++)self.dofFields[i].stringValue=[NSString stringWithFormat:@"%.17g",values[i]];
    [self syncDofSliders];[self syncPostProcessLabels];
}
- (void)syncDofSliders {
    for(int i=0;i<4;i++){double value=self.dofFields[i].doubleValue;if(i<2)self.dofSliders[i].maxValue=fmin(1e6,fmax(10,value*2));self.dofSliders[i].minValue=i==3?.1:0;self.dofSliders[i].doubleValue=value;}
}
- (BOOL)readDepthOfField:(RenderOptions *)options {
    if(!self.dofFields.count){options->dof.enabled=options->dof.automatic;return YES;}double values[4],minimum[]={0,0,0,.1},maximum[]={1e6,1e6,2,1000};
    NSArray *names=@[@"Z1 sharp",@"Z2 sharp",@"Aperture",@"Clipping radius"];
    for(int i=0;i<4;i++){NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.dofFields[i])];if(![scanner scanDouble:&values[i]]||!scanner.isAtEnd||!isfinite(values[i])||values[i]<minimum[i]||values[i]>maximum[i]){self.statusLabel.stringValue=[NSString stringWithFormat:@"Depth of Field %@ must be %.9g–%.9g.",names[i],minimum[i],maximum[i]];return NO;}}
    options->dof_override=1;options->dof=(DepthOfFieldSettings){.enabled=self.postProcessOnce==PostProcessDepthOfField||([self resettingPostProcess]&&self.dofApplied)||self.dofAutomatic.state==NSControlStateValueOn,.automatic=self.dofAutomatic.state==NSControlStateValueOn,.passes=(int)self.dofPasses.indexOfSelectedItem+1,.focus1=values[0],.focus2=values[1],.aperture=values[2],.clip_radius=values[3]};return YES;
}
- (void)disableDepthOfField {
    self.dofApplied=NO;
    RenderOptions settings=self.formulaSettings;settings.dof.enabled=0;settings.dof.automatic=self.dofAutomatic.state==NSControlStateValueOn;settings.dof_override=1;self.formulaSettings=settings;
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(finishLightingSlider) object:nil];
    self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;
    if(self.sharpRenderImage){self.imageView.image=self.sharpRenderImage;self.completedRender=(NSBitmapImageRep *)self.sharpRenderImage.representations.firstObject;}
    [self syncPostProcessLabels];
}
- (void)dofAction:(NSButton *)sender {if(!sender.tag){[self disableDepthOfField];return;}self.postProcessOnce=PostProcessDepthOfField;[self calculate:nil];self.postProcessOnce=PostProcessNone;}
- (void)dofEdited:(id)sender {if(sender==self.dofAutomatic&&self.dofAutomatic.state==NSControlStateValueOff){[self disableDepthOfField];return;}if(sender==self.dofAutomatic)self.dofApplied=YES;RenderOptions options=self.formulaSettings;if(![self readDepthOfField:&options]||![self readReflections:&options])return;[self syncDofSliders];[self syncPostProcessLabels];[self finishLightingSlider];}
- (void)dofSliderChanged:(NSSlider *)sender {self.dofFields[sender.tag].stringValue=[NSString stringWithFormat:@"%.17g",sender.doubleValue];[self requestLightingPreview];}
- (void)copyDofFocus:(id)sender {(void)sender;self.dofFields[1].stringValue=self.dofFields[0].stringValue;[self dofEdited:nil];}
- (void)chooseDofFocus:(NSButton *)sender {
    if(self.calculating||!self.completedRender)return;
    if(self.focusPicking==sender.tag){self.focusPicking=0;self.imageView.pickingLight=NO;return;}
    self.focusPicking=sender.tag;self.placingLight=-1;self.imageView.pickingLight=YES;self.statusLabel.stringValue=[NSString stringWithFormat:@"Click the object to select Z%ld sharp.",(long)sender.tag];[self.window makeKeyAndOrderFront:nil];
}
- (void)pickDofFocusAt:(NSPoint)point {
    if(self.calculating)return;NSInteger selected=self.focusPicking;NSUInteger generation=self.generation;
    dispatch_async(self.renderQueue,^{double focus=0;BOOL hit=render_pick_focus(point.x,point.y,&focus);interactiveUI(^{
        if(self.calculating||generation!=self.generation||self.focusPicking!=selected)return;
        if(!hit){self.statusLabel.stringValue=@"Click a rendered surface, or render again if the depth cache was cleared.";return;}
        self.dofFields[selected-1].stringValue=[NSString stringWithFormat:@"%.17g",focus];self.focusPicking=0;self.imageView.pickingLight=NO;[self syncDofSliders];
        self.statusLabel.stringValue=@"Focus depth selected. Press Calculate now to apply Depth of Field.";
        if(self.dofApplied||self.dofAutomatic.state==NSControlStateValueOn)[self finishLightingSlider];
    });});
}
- (void)populateShadowSettings {
    if(!self.postWindow||!self.formulaKnown)return;
    ShadowSettings s=self.formulaSettings.shadows;
    self.hardShadowsApplied=s.hard_enabled;self.ambientShadowsApplied=s.ambient_enabled;
    self.shadowAutoChecks[0].state=s.hard_auto;self.shadowAutoChecks[1].state=s.ambient_auto;
    self.softShadowCheck.state=s.soft;self.cosineShadowCheck.state=s.cosine;
    for(int i=0;i<6;i++)self.shadowLightChecks[i].state=(s.hard_mask&(1<<i))!=0;
    [self.ambientMethod selectItemAtIndex:s.ambient_method];
    double values[]={s.hard_length,s.hard_radius,s.ambient_strength,s.ambient_length,s.ambient_rays,s.ambient_steps};
    for(int i=0;i<6;i++)self.shadowFields[i].stringValue=[NSString stringWithFormat:@"%.17g",values[i]];
    [self syncAmbientShadowSliders];[self populateDepthOfField];[self populateReflections];[self syncPostProcessLabels];
}
- (void)syncAmbientShadowSliders {
    for(int i=0;i<4;i++){double value=self.shadowFields[i+2].doubleValue;self.ambientShadowSliders[i].doubleValue=i==1?log10(fmax(.001,value)):value;}
}
- (void)syncAmbientShadowStrength {
    if(self.ambientFields.count>2){double value=self.shadowFields[2].doubleValue*53;self.ambientFields[2].stringValue=[NSString stringWithFormat:@"%.17g",value];self.ambientSliders[2].doubleValue=value;}
}
- (void)ambientShadowSliderChanged:(NSSlider *)sender {
    NSInteger index=sender.tag;double value=index==1?pow(10,sender.doubleValue):sender.doubleValue;
    if(index>=2){value=round(value);sender.doubleValue=value;}
    self.shadowFields[index+2].stringValue=[NSString stringWithFormat:@"%.17g",value];
    if(index==0)[self syncAmbientShadowStrength];
    [self requestLightingPreview];
}
- (void)ambientShadowValueEdited:(NSTextField *)sender {
    RenderOptions options=self.formulaSettings;if(![self readShadowSettings:&options])return;
    [self syncAmbientShadowSliders];if(sender.tag==0)[self syncAmbientShadowStrength];
    [self finishLightingSlider];
}
- (BOOL)readShadowSettings:(RenderOptions *)options {
    if(!self.postWindow){options->shadows.hard_enabled=options->shadows.hard_auto;options->shadows.ambient_enabled=options->shadows.ambient_auto;return YES;}
    double values[6],min[]={.001,.001,0,.001,1,8},max[]={100,100,5,100,64,512};
    for(int i=0;i<6;i++) {
        NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.shadowFields[i])];
        if(![scanner scanDouble:&values[i]]||!scanner.isAtEnd||!isfinite(values[i])||values[i]<min[i]||values[i]>max[i]||(i>=4&&floor(values[i])!=values[i])) {
            self.statusLabel.stringValue=@"Check Post-process values: enter finite numbers within each labeled range; Rays/Steps must be integers.";return NO;
        }
    }
    ShadowSettings s=options->shadows;double stored[]={s.hard_length,s.hard_radius,s.ambient_strength,s.ambient_length,s.ambient_rays,s.ambient_steps};
    for(int i=0;i<6;i++)values[i]=unchangedFieldValue(self.shadowFields[i],values[i],stored[i],@"%.17g");
    s.hard_auto=(int)self.shadowAutoChecks[0].state;s.ambient_auto=(int)self.shadowAutoChecks[1].state;s.hard_enabled=!self.resettingHardShadows&&(self.postProcessOnce==PostProcessHardShadows||([self resettingPostProcess]&&self.hardShadowsApplied)||self.shadowAutoChecks[0].state==NSControlStateValueOn);
    s.ambient_enabled=!self.resettingAmbientShadows&&(self.postProcessOnce==PostProcessAmbientShadows||([self resettingPostProcess]&&self.ambientShadowsApplied)||self.shadowAutoChecks[1].state==NSControlStateValueOn);
    s.hard_mask=0;for(int i=0;i<6;i++)if(self.shadowLightChecks[i].state==NSControlStateValueOn)s.hard_mask|=1<<i;
    s.soft=self.softShadowCheck.state==NSControlStateValueOn;s.cosine=self.cosineShadowCheck.state==NSControlStateValueOn;
    s.hard_length=values[0];s.hard_radius=values[1];s.ambient_strength=values[2];s.ambient_length=values[3];s.ambient_rays=(int)values[4];s.ambient_steps=(int)values[5];s.ambient_method=(int)self.ambientMethod.indexOfSelectedItem;
    options->shadows_override=1;options->shadows=s;[self syncPostProcessLabels];return YES;
}
- (void)postProcessAction:(NSButton *)sender {
    BOOL ambient=sender.tag>=2,calculate=sender.tag%2;
    self.postProcessOnce=calculate?(ambient?PostProcessAmbientShadows:PostProcessHardShadows):PostProcessNone;
    self.resettingHardShadows=!calculate&&!ambient;self.resettingAmbientShadows=!calculate&&ambient;
    [self syncPostProcessLabels];[self calculate:nil];
    self.postProcessOnce=PostProcessNone;
    self.resettingHardShadows=self.resettingAmbientShadows=NO;
}

- (void)addLightTabs:(NSTabView *)tabs {
    NSTabViewItem *item=[[NSTabViewItem alloc] initWithIdentifier:@"lights"];item.label=@"Light sources";
    CalculationPanel *panel=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,552,700)];
    NSTabView *sources=[[NSTabView alloc] initWithFrame:NSMakeRect(12,12,528,540)];
    NSMutableArray *strengthSliders=[NSMutableArray array],*strengthSteppers=[NSMutableArray array],*visibilityControls=[NSMutableArray array];
    NSMutableArray *all=[NSMutableArray array],*allSliders=[NSMutableArray array],*positionControls=[NSMutableArray array],*steps=[NSMutableArray array];
    __weak AppDelegate *weakSelf=self;
    for(int i=0;i<6;i++) {
        NSTabViewItem *source=[[NSTabViewItem alloc] initWithIdentifier:@(i)];source.label=[NSString stringWithFormat:@"Light %d",i+1];
        CalculationPanel *view=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,504,570)];
        NSMutableArray *controls=[NSMutableArray array];
        NSArray *names=@[@"Enabled",@"Type",@"Color",@"Strength",@"X angle (degrees) / X position",@"Y angle (degrees) / Y position",@"Z position (point lights)",@"Relative to object (directional)",@"Ignore hard / ambient shadows",@"Diffuse function",@"Specular exponent"];
        for(int j=0;j<11;j++) {
            CGFloat y=20+j*43;NSControl *control;
            if(j==0||j==7||j==8)control=[NSButton checkboxWithTitle:names[j] target:nil action:nil];
            else {
                NSTextField *label=[NSTextField labelWithString:names[j]];label.frame=NSMakeRect(12,y+4,j>=4&&j<=6?190:270,24);if(j>=4&&j<=6)label.stringValue=@[@"X angle / position",@"Y angle / position",@"Z position"][j-4];[view addSubview:label];
                if(j==1||j==9||j==10) {
                    NSPopUpButton *menu=[[NSPopUpButton alloc] initWithFrame:NSZeroRect pullsDown:NO];
                    [menu addItemsWithTitles:j==1?@[@"Directional",@"Positional"]:j==9?@[@"Cosine",@"Cosine squared",@"Wrapped",@"Wrapped squared"]:@[@"2",@"4",@"8",@"16",@"32",@"64",@"128",@"256"]];control=menu;
                }else if(j==2)control=[[AdjustmentColorWell alloc] initWithFrame:NSZeroRect];
                else control=j==3?[[NSTextField alloc]initWithFrame:NSZeroRect]:[[NumericTextField alloc] initWithFrame:NSZeroRect];
            }
            control.frame=NSMakeRect(j==0||j==7||j==8?12:290,y,j==0||j==7||j==8?470:195,28);
            control.accessibilityLabel=[NSString stringWithFormat:@"Light %d %@",i+1,names[j]];
            [view addSubview:control];[controls addObject:control];
        }
        for(int j=0;j<11;j++) {
            NSControl *control=controls[j];control.target=self;control.action=j==0?@selector(lightEnabledChanged:):@selector(lightValuesEdited:);control.tag=i;
        }
        [(NSControl *)controls[1] setFrame:NSMakeRect(60,63,112,28)];
        [(NSControl *)controls[2] setFrame:NSMakeRect(60,106,80,28)];
        NSTextField *visibleLabel=[NSTextField labelWithString:@"Visible"];visibleLabel.frame=NSMakeRect(374,67,48,22);[view addSubview:visibleLabel];[visibilityControls addObject:visibleLabel];
        NSPopUpButton *visible=[[NSPopUpButton alloc]initWithFrame:NSMakeRect(430,63,54,28) pullsDown:NO];[visible addItemsWithTitles:@[@"0",@"1",@"2",@"3",@"4"]];visible.target=self;visible.action=@selector(lightValuesEdited:);visible.tag=i;visible.accessibilityLabel=[NSString stringWithFormat:@"Light %d Visible",i+1];visible.toolTip=@"Determines whether the light should be visible and its shape. 0 hides the source.";[view addSubview:visible];[controls addObject:visible];[visibilityControls addObject:visible];
        NSTextField *strengthField=(NSTextField *)controls[3];strengthField.frame=NSMakeRect(390,149,70,26);strengthField.editable=YES;strengthField.selectable=YES;
        strengthField.toolTip=@"Light strength, including scientific notation (for example 1e-6).";
        NSStepper *strengthStep=[[NSStepper alloc]initWithFrame:NSMakeRect(466,149,19,27)];strengthStep.minValue=-1;strengthStep.maxValue=1;strengthStep.increment=1;strengthStep.integerValue=0;strengthStep.autorepeat=YES;strengthStep.tag=i;strengthStep.target=self;strengthStep.action=@selector(stepLightStrength:);strengthStep.accessibilityLabel=[NSString stringWithFormat:@"Light %d strength step",i+1];strengthStep.toolTip=@"Increase strength ×1.414; decrease ×0.707.";[view addSubview:strengthStep];[strengthSteppers addObject:strengthStep];
        LiveSlider *strength=[LiveSlider sliderWithValue:1 minValue:0 maxValue:5 target:self action:@selector(lightStrengthChanged:)];strength.frame=NSMakeRect(150,149,230,26);strength.tag=i;strength.continuous=YES;strength.accessibilityLabel=[NSString stringWithFormat:@"Light %d strength slider",i+1];strength.started=^{[weakSelf beginLightingSlider];};strength.finished=^{[weakSelf endLightingSlider];};[view addSubview:strength];[strengthSliders addObject:strength];
        NSMutableArray *sliders=[NSMutableArray array];
        for(int axis=0;axis<3;axis++) {
            NSTextField *field=(NSTextField *)controls[4+axis];field.frame=NSMakeRect(390,20+(4+axis)*43,95,26);
            LiveSlider *slider=[LiveSlider sliderWithValue:0 minValue:-180 maxValue:180 target:self action:@selector(lightSliderChanged:)];
            slider.frame=NSMakeRect(210,20+(4+axis)*43,170,26);slider.tag=i*3+axis;slider.continuous=YES;
            slider.accessibilityLabel=[NSString stringWithFormat:@"Light %d %@ slider",i+1,@[@"X",@"Y",@"Z"][axis]];
            __weak LiveSlider *weakPositionSlider=slider;slider.started=^{[weakSelf beginLightingSlider];};slider.finished=^{[weakSelf positionalLightSliderReleased:weakPositionSlider];[weakSelf endLightingSlider];};[view addSubview:slider];[sliders addObject:slider];
            field.target=self;field.action=@selector(lightValuesEdited:);
        }
        [(NSPopUpButton *)controls[1] setTarget:self];[(NSPopUpButton *)controls[1] setAction:@selector(lightValuesEdited:)];
        NSButton *place=[NSButton buttonWithTitle:@"Place on render…" target:self action:@selector(chooseLightPosition:)];place.tag=i;place.frame=NSMakeRect(180,63,187,28);[view addSubview:place];[positionControls addObject:place];
        NSTextField *stepLabel=[NSTextField labelWithString:@"Move step (world)"];stepLabel.frame=NSMakeRect(12,325,150,22);stepLabel.tag=900+i;[view addSubview:stepLabel];
        NSTextField *step=[[NumericTextField alloc]initWithFrame:NSMakeRect(175,321,110,26)];step.stringValue=@"0.01";step.accessibilityLabel=[NSString stringWithFormat:@"Light %d move step",i+1];[view addSubview:step];[steps addObject:step];[positionControls addObject:step];
        for(int axis=0;axis<3;axis++){
            CGFloat y=20+(4+axis)*43;
            [(NSTextField *)controls[4+axis] setFrame:NSMakeRect(390,y,70,26)];
            NSStepper *move=[[NSStepper alloc]initWithFrame:NSMakeRect(466,y,19,27)];
            move.minValue=-1;move.maxValue=1;move.increment=1;move.integerValue=0;move.autorepeat=YES;
            move.tag=i*3+axis;move.target=self;move.action=@selector(stepPositionalLight:);
            move.accessibilityLabel=[NSString stringWithFormat:@"Light %d %@ position step",i+1,@[@"X",@"Y",@"Z"][axis]];
            move.toolTip=@"Move along the screen axis using Move step; hold Shift for one-tenth step.";
            [view addSubview:move];[positionControls addObject:move];
        }
        source.view=view;[sources addTabViewItem:source];[all addObject:controls];[allSliders addObject:sliders];
    }
    self.lightSourceTabs=sources;self.lightVisibilityControls=visibilityControls;
    self.positionControls=positionControls;self.lightMoveSteps=steps;
    self.lightControls=all;self.lightSliders=allSliders;self.lightStrengthSliders=strengthSliders;self.lightStrengthSteppers=strengthSteppers;[panel addSubview:sources];
    NSTextField *hint=[NSTextField wrappingLabelWithString:@"Directional lights use X/Y angles. Positional lights use world X/Y/Z coordinates. Place on render, then move using the screen X/Y/Z sliders or steppers. Strength: 0–10000000000. Visible selects the light source shape (0 hides it). Light maps are ignored."];
    hint.frame=NSMakeRect(16,556,520,38);hint.font=[NSFont systemFontOfSize:11];[panel addSubview:hint];
    item.view=panel;[tabs addTabViewItem:item];
}
- (void)setPlacingLight:(NSInteger)light {
    _placingLight=light;
    for(NSUInteger i=0;i<self.lightControls.count;i++){
        NSButton *button=(NSButton *)self.positionControls[i*5];
        button.title=(NSInteger)i==light?@"Click on render":@"Place on render…";
    }
}
- (void)chooseLightPosition:(NSButton *)sender {
    if(self.calculating||!self.completedRender)return;
    if(self.imageView.pickingLight&&self.placingLight==sender.tag){self.imageView.pickingLight=NO;self.placingLight=-1;self.statusLabel.stringValue=@"Light placement cancelled.";return;}
    self.focusPicking=0;self.placingLight=sender.tag;self.imageView.pickingLight=YES;
    self.statusLabel.stringValue=[NSString stringWithFormat:@"Click the rendered object to place light %ld.",(long)sender.tag+1];
    [self.window makeKeyAndOrderFront:nil];
}
- (void)placeLightAt:(NSPoint)point {
    if(self.cuttingPicking){[self pickNavigatorCutAt:point];return;}
    if(self.midpointPicking){[self pickMidpointAt:point];return;}
    if(self.focusPicking){[self pickDofFocusAt:point];return;}
    if(self.calculating||self.placingLight<0)return;
    NSInteger light=self.placingLight;NSUInteger generation=self.generation;
    dispatch_async(self.renderQueue,^{
        double position[3]={0};BOOL hit=render_pick_surface(point.x,point.y,position);
        double x=position[0],y=position[1],z=position[2];
        interactiveUI(^{
            if(generation!=self.generation||self.calculating||self.placingLight!=light)return;
            if(!hit){self.statusLabel.stringValue=@"No surface at that point. Click the object, or render again if the cache was cleared.";return;}
            NSArray *controls=self.lightControls[light];[(NSPopUpButton *)controls[1] selectItemAtIndex:1];
            [(NSButton *)controls[0] setState:NSControlStateValueOn];
            double values[]={x,y,z};for(int axis=0;axis<3;axis++)[(NSTextField *)controls[axis+4] setStringValue:[NSString stringWithFormat:@"%.17g",values[axis]]];
            self.imageView.pickingLight=NO;self.placingLight=-1;[self lightEnabledChanged:controls[0]];[self syncLightSliders];
            self.statusLabel.stringValue=@"Positional light placed. Adjust X/Y/Z or use the move buttons.";
        });
    });
}
- (void)stepPositionalLight:(NSStepper *)sender {
    NSInteger direction=sender.integerValue;sender.integerValue=0;if(!direction)return;
    NSInteger light=sender.tag/3,axis=sender.tag%3;
    if(self.calculating||[(NSPopUpButton *)self.lightControls[light][1] indexOfSelectedItem]!=1)return;
    double step;NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.lightMoveSteps[light])];
    if(![scanner scanDouble:&step]||!scanner.isAtEnd||!isfinite(step)||step<=0){self.lightingStatus.stringValue=@"Move step must be a positive finite number.";return;}
    if(NSApp.currentEvent.modifierFlags&NSEventModifierFlagShift)step*=.1;
    CameraSettings camera=[self lightSliderCamera];double delta=direction*step*(axis==1?-1:1),values[3];
    for(int k=0;k<3;k++){
        NSTextField *field=(NSTextField *)self.lightControls[light][4+k];NSScanner *coordinate=[NSScanner scannerWithString:numericInputString(field)];
        if(![coordinate scanDouble:&values[k]]||!coordinate.isAtEnd||!isfinite(values[k]))return;
        values[k]+=delta*camera.axes[axis*3+k];if(!isfinite(values[k]))return;
    }
    for(int k=0;k<3;k++)[(NSTextField *)self.lightControls[light][4+k] setStringValue:[NSString stringWithFormat:@"%.17g",values[k]]];
    [self lightValuesEdited:sender];
}
- (void)syncLightSourceLabels {
    for(NSUInteger i=0;i<(NSUInteger)self.lightSourceTabs.numberOfTabViewItems&&i<self.lightControls.count;i++){
        BOOL active=[(NSButton *)self.lightControls[i][0] state]==NSControlStateValueOn;
        self.lightSourceTabs.tabViewItems[i].label=[NSString stringWithFormat:@"Light %lu%@",(unsigned long)i+1,active?@"*":@""];
    }
}
- (void)populateLights {
    for(int i=0;i<6;i++) {
        NSArray *c=self.lightControls[i];LightSettings l=self.formulaSettings.lights[i];
        [(NSButton *)c[0] setState:(l.option&1)?NSControlStateValueOff:NSControlStateValueOn];
        [(NSPopUpButton *)c[1] selectItemAtIndex:(l.option&4)?1:0];
        [(NSColorWell *)c[2] setColor:[NSColor colorWithSRGBRed:l.color[0] green:l.color[1] blue:l.color[2] alpha:1]];
        [(NSTextField *)c[3] setStringValue:[NSString stringWithFormat:@"%.17g",l.amplitude]];
        for(int j=0;j<3;j++)[(NSTextField *)c[4+j] setStringValue:[NSString stringWithFormat:@"%.17g",l.position[j]*(!(l.option&4)&&j<2?180/M_PI:1)]];
        [(NSButton *)c[7] setState:(l.option&32)?NSControlStateValueOn:NSControlStateValueOff];
        [(NSButton *)c[8] setState:(l.option&64)?NSControlStateValueOn:NSControlStateValueOff];
        [(NSPopUpButton *)c[9] selectItemAtIndex:(l.function>>4)&3];
        [(NSPopUpButton *)c[10] selectItemAtIndex:l.function&7];
        int visibleIndices[]={0,3,1,2};[(NSPopUpButton *)c[11] selectItemAtIndex:MIN(4,visibleIndices[(l.option>>3)&3]|((l.function&128)>>5))];
    }
    [self syncLightSliders];[self syncLightSourceLabels];
}
- (BOOL)readLights:(RenderOptions *)options {
    for(int i=0;i<6;i++) {
        NSArray *c=self.lightControls[i];if(options->lights[i].option&2)continue; /* Imported light maps have no editor. */
        LightSettings l={0};double values[4];
        for(int j=0;j<4;j++) {
            NSScanner *scanner=[NSScanner scannerWithString:numericInputString((NSTextField *)c[3+j])];
            if(![scanner scanDouble:&values[j]]||!scanner.isAtEnd||!isfinite(values[j])||(j==0&&(values[j]<0||values[j]>1e10))) {
                self.lightingStatus.stringValue=[NSString stringWithFormat:@"Light %d: enter finite coordinates and strength 0–10000000000.",i+1];return NO;
            }
        }
        l.option=([(NSButton *)c[0] state]==NSControlStateValueOn?0:1)|([(NSPopUpButton *)c[1] indexOfSelectedItem]?4:0)|([(NSButton *)c[7] state]==NSControlStateValueOn?32:0)|([(NSButton *)c[8] state]==NSControlStateValueOn?64:0);
        l.function=(int)([(NSPopUpButton *)c[9] indexOfSelectedItem]<<4)|(int)[(NSPopUpButton *)c[10] indexOfSelectedItem];
        int visibility=(int)[(NSPopUpButton *)c[11] indexOfSelectedItem];int visibilityBits[]={0,16,24,8};l.option|=visibilityBits[visibility&3];l.function|=(visibility&4)<<5;
        l.amplitude=values[0];for(int j=0;j<3;j++)l.position[j]=values[j+1]*(!(l.option&4)&&j<2?M_PI/180:1);
        LightSettings stored=options->lights[i];if((stored.option&4)==(l.option&4))for(int j=0;j<3;j++){
            double unit=(!(l.option&4)&&j<2?180/M_PI:1),shown=stored.position[j]*unit;
            if([[(NSTextField *)c[4+j] stringValue] isEqualToString:numericDisplayString([NSString stringWithFormat:@"%.17g",shown])])l.position[j]=stored.position[j];
        }
        NSColor *color=[[(NSColorWell *)c[2] color] colorUsingColorSpace:NSColorSpace.sRGBColorSpace];
        if(!color)return NO;l.color[0]=color.redComponent;l.color[1]=color.greenComponent;l.color[2]=color.blueComponent;
        options->lights[i]=l;
    }
    options->lights_override=1;return YES;
}

- (void)showColorAdjustment:(id)sender {
    (void)sender;
    if(!self.colorWindow) {
        self.colorWindow=[[PaletteWindow alloc] initWithContentRect:NSMakeRect(0,0,780,455) styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable backing:NSBackingStoreBuffered defer:NO];
        self.colorWindow.title=@"Color adjustment";self.colorWindow.releasedWhenClosed=NO;self.colorWindow.delegate=self;
        CalculationPanel *panel=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,780,455)];self.colorWindow.contentView=panel;
        __weak AppDelegate *weakSelf=self;
        ((PaletteWindow *)self.colorWindow).stopCommand=^BOOL(NSInteger command){return [weakSelf performColorStopCommand:command];};
        self.colorStopKeyMonitor=[NSEvent addLocalMonitorForEventsMatchingMask:NSEventMaskKeyDown handler:^NSEvent *(NSEvent *event){
            return [weakSelf handleColorStopKeyEvent:event window:event.window?:NSApp.keyWindow]?nil:event;
        }];
        for(int row=0;row<2;row++) {
            NSTextField *label=[NSTextField labelWithString:row?@"Specular":@"Diffuse"];
            label.frame=NSMakeRect(16,16+row*88,120,22);[panel addSubview:label];
            PaletteView *bar=[[PaletteView alloc] initWithFrame:NSMakeRect(16,40+row*88,748,60)];bar.markers=YES;bar.specular=row;bar.showOpacityBand=YES;bar.enabled=YES;
            bar.accessibilityLabel=row?@"Specular palette stops":@"Diffuse palette stops";
            bar.clicked=^(NSInteger stop,BOOL pick){
                (void)pick;AppDelegate *owner=weakSelf;[owner.colorStopMenu selectItemAtIndex:stop];[owner refreshPaletteViews];
                [owner showSelectedStopColor:row!=0];
            };
            bar.moved=^(NSInteger stop,unsigned position,BOOL finished){[weakSelf moveColorStop:stop position:position finished:finished];};
            bar.stopCommand=^BOOL(NSInteger command){return [weakSelf performColorStopCommand:command];};
            bar.canPaste=^BOOL{return [weakSelf colorStopClipboardColors].count==2;};
            [panel addSubview:bar];if(row)self.colorSpecularBar=bar;else self.colorDiffuseBar=bar;
        }
        NSArray *names=@[@"Stop",@"Position (0–32767)",@"Diffuse color",@"Specular color"];
        CGFloat x[]={16,150,390,580};
        for(int i=0;i<4;i++){NSTextField *label=[NSTextField labelWithString:names[i]];label.frame=NSMakeRect(x[i],196,180,22);[panel addSubview:label];}
        self.colorStopMenu=[[NSPopUpButton alloc] initWithFrame:NSMakeRect(16,222,115,28) pullsDown:NO];
        for(int i=0;i<10;i++)[self.colorStopMenu addItemWithTitle:[NSString stringWithFormat:@"Stop %d",i+1]];
        self.colorStopMenu.target=self;self.colorStopMenu.action=@selector(refreshColorSelection:);self.colorStopMenu.accessibilityLabel=@"Selected palette stop";[panel addSubview:self.colorStopMenu];
        self.colorPosition=[[NumericTextField alloc] initWithFrame:NSMakeRect(150,222,190,26)];numericIntegerField(self.colorPosition,YES);self.colorPosition.target=self;self.colorPosition.action=@selector(colorPositionEdited:);self.colorPosition.accessibilityLabel=@"Selected stop position";[panel addSubview:self.colorPosition];
        self.colorDiffuseWell=[[AdjustmentColorWell alloc] initWithFrame:NSMakeRect(390,222,170,28)];((AdjustmentColorWell *)self.colorDiffuseWell).allowsOpacity=YES;self.colorDiffuseWell.target=self;self.colorDiffuseWell.action=@selector(adjustmentColorEdited:);self.colorDiffuseWell.accessibilityLabel=@"Selected diffuse color";self.colorDiffuseWell.toolTip=@"Opacity controls DIFS emissive strength; re-render after changing it.";[panel addSubview:self.colorDiffuseWell];
        self.colorSpecularWell=[[AdjustmentColorWell alloc] initWithFrame:NSMakeRect(580,222,184,28)];((AdjustmentColorWell *)self.colorSpecularWell).allowsOpacity=YES;self.colorSpecularWell.target=self;self.colorSpecularWell.action=@selector(adjustmentColorEdited:);self.colorSpecularWell.accessibilityLabel=@"Selected specular color";[panel addSubview:self.colorSpecularWell];
        self.glueColors=[NSButton checkboxWithTitle:@"Glue sliders" target:nil action:nil];self.glueColors.frame=NSMakeRect(16,268,180,24);self.glueColors.toolTip=@"Stretch neighboring stop positions proportionally while moving a stop.";[panel addSubview:self.glueColors];
        NSMutableArray *references=[NSMutableArray array],*amounts=[NSMutableArray array],*buttons=[NSMutableArray array],*amountSliders=[NSMutableArray array];
        for(int i=0;i<2;i++) {
            CGFloat y=310+i*38;
            NSButton *button=[NSButton buttonWithTitle:i?@"Random specular":@"Random diffuse" target:self action:@selector(randomizeColors:)];button.frame=NSMakeRect(16,y,180,28);button.tag=i;[panel addSubview:button];[buttons addObject:button];
            NSTextField *label=[NSTextField labelWithString:@"Reference color"];label.frame=NSMakeRect(220,y+4,110,22);[panel addSubview:label];
            NSColorWell *well=[[AdjustmentColorWell alloc] initWithFrame:NSMakeRect(332,y,95,28)];well.color=[NSColor colorWithSRGBRed:.5 green:.5 blue:.5 alpha:1];well.accessibilityLabel=i?@"Specular random reference":@"Diffuse random reference";[panel addSubview:well];[references addObject:well];
            NSTextField *amountLabel=[NSTextField labelWithString:@"Multiplier (0–3)"];amountLabel.frame=NSMakeRect(442,y+4,120,22);[panel addSubview:amountLabel];
            LiveSlider *amountSlider=[LiveSlider sliderWithValue:1 minValue:0 maxValue:3 target:self action:@selector(randomAmountChanged:)];amountSlider.frame=NSMakeRect(566,y,130,26);amountSlider.tag=i;amountSlider.continuous=YES;amountSlider.accessibilityLabel=i?@"Specular random multiplier slider":@"Diffuse random multiplier slider";[panel addSubview:amountSlider];[amountSliders addObject:amountSlider];
            NSTextField *amount=[[NumericTextField alloc] initWithFrame:NSMakeRect(706,y,58,26)];amount.stringValue=@"1";amount.tag=i;amount.target=self;amount.action=@selector(randomAmountEdited:);amount.accessibilityLabel=i?@"Specular random multiplier":@"Diffuse random multiplier";[panel addSubview:amount];[amounts addObject:amount];
        }
        self.randomAmountSliders=amountSliders;
        self.randomReferences=references;self.randomAmounts=amounts;self.randomButtons=buttons;
        self.colorStatus=[NSTextField wrappingLabelWithString:@"Click a stop to select it and open its color picker; drag a marker to move it. Right-click for Copy and Paste commands (⌘C, ⌘V, ⌘G, ⌘B)."];
        self.colorStatus.frame=NSMakeRect(16,398,540,42);self.colorStatus.font=[NSFont systemFontOfSize:11];[panel addSubview:self.colorStatus];
        self.updateColors=[NSButton buttonWithTitle:@"Update Image" target:self action:@selector(calculate:)];self.updateColors.frame=NSMakeRect(580,402,184,32);[panel addSubview:self.updateColors];
        for(NSView *view in panel.subviews){NSRect frame=view.frame;frame.origin.y+=38;view.frame=frame;}
        [self.colorWindow setContentSize:NSMakeSize(780,493)];panel.frame=NSMakeRect(0,0,780,493);
        NSTextField *objectLabel=[NSTextField labelWithString:@"Object colors"];objectLabel.frame=NSMakeRect(16,10,100,22);[panel addSubview:objectLabel];
        self.objectColorsMenu=[[NSPopUpButton alloc]initWithFrame:NSMakeRect(126,6,140,28) pullsDown:NO];[self.objectColorsMenu addItemsWithTitles:@[@"Outside",@"Inside"]];self.objectColorsMenu.target=self;self.objectColorsMenu.action=@selector(objectColorsChanged:);[panel addSubview:self.objectColorsMenu];
        [self.colorWindow center];
    }
    [self.objectColorsMenu selectItemAtIndex:[sender isKindOfClass:NSNumber.class]?[sender integerValue]:0];
    [self refreshPaletteViews];[self setCalculating:self.calculating];[self positionWindowRightOfMain:self.colorWindow];[self.colorWindow makeKeyAndOrderFront:nil];
}
/* Copy the pair, including both opacity channels, without moving either stop. */
- (NSArray<NSColor *> *)colorStopClipboardColors {
    NSPasteboard *pb=self.palettePasteboard?self.palettePasteboard:NSPasteboard.generalPasteboard;
    id data=[pb propertyListForType:@"org.codex.mandelbulb3d.palette-stop"];
    if(![data isKindOfClass:NSArray.class]||[data count]!=2)return nil;
    NSMutableArray *colors=[NSMutableArray array];
    for(id channels in data){if(![channels isKindOfClass:NSArray.class]||[channels count]!=4)return nil;double c[4];for(int j=0;j<4;j++){id value=channels[j];if(![value isKindOfClass:NSNumber.class])return nil;c[j]=[value doubleValue];if(!isfinite(c[j])||c[j]<0||c[j]>1)return nil;}[colors addObject:[NSColor colorWithSRGBRed:c[0] green:c[1] blue:c[2] alpha:c[3]]];}
    return colors;
}
- (BOOL)handleColorStopKeyEvent:(NSEvent *)event window:(NSWindow *)window {
    NSNumber *command=paletteShortcut(event);if(!command||!self.colorWindow.visible)return NO;
    BOOL picker=window==NSColorPanel.sharedColorPanel&&(self.colorDiffuseWell.active||self.colorSpecularWell.active);
    if(window!=self.colorWindow&&!picker)return NO;
    BOOL editing=[window.firstResponder isKindOfClass:NSTextView.class]&&[(NSTextView *)window.firstResponder isFieldEditor];
    if(editing&&command.integerValue<2)return NO;
    return [self performColorStopCommand:command.integerValue];
}
- (BOOL)performColorStopCommand:(NSInteger)command {
    if(self.calculating||!self.formulaKnown||!self.colorWindow||command<0||command>3)return NO;
    NSInteger stop=self.colorStopMenu.indexOfSelectedItem;if(stop<0||stop>=10)return NO;
    if(command==0){
        NSMutableArray *pair=[NSMutableArray array];
        for(NSColorWell *well in (self.objectColorsMenu.indexOfSelectedItem==1?@[self.colorDiffuseWell,self.colorSpecularWell]:@[self.diffuseWells[stop],self.specularWells[stop]])){NSColor *c=[well.color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];if(!c)return NO;[pair addObject:@[@(c.redComponent),@(c.greenComponent),@(c.blueComponent),@(c.alphaComponent)]];}
        NSPasteboard *pb=self.palettePasteboard?self.palettePasteboard:NSPasteboard.generalPasteboard;[pb declareTypes:@[@"org.codex.mandelbulb3d.palette-stop"] owner:nil];return [pb setPropertyList:pair forType:@"org.codex.mandelbulb3d.palette-stop"];
    }
    NSArray<NSColor *> *pair=[self colorStopClipboardColors];if(pair.count!=2){NSBeep();return YES;}
    if(self.objectColorsMenu.indexOfSelectedItem==1){ObjectLighting colors=self.formulaSettings.cutting_colors;if(command==1||command==2){NSColor *c=pair[0];colors.stops[stop].diffuse[0]=c.redComponent;colors.stops[stop].diffuse[1]=c.greenComponent;colors.stops[stop].diffuse[2]=c.blueComponent;}if(command==1||command==3){NSColor *c=pair[1];for(int i=0;i<3;i++)colors.stops[stop].specular[i]=(c.redComponent+c.greenComponent+c.blueComponent)/3;}[self commitInsideColors:colors];[self finishLightingSlider];return YES;}
    if(command==1||command==2)self.diffuseWells[stop].color=pair[0];
    if(command==1||command==3)self.specularWells[stop].color=pair[1];
    [self refreshPaletteViews];[self paletteEdited:self.colorSpecularWell];return YES;
}
- (void)showSelectedStopColor:(BOOL)specular {
    NSColorWell *well=specular?self.colorSpecularWell:self.colorDiffuseWell;
    [well activate:YES];NSColorPanel *picker=NSColorPanel.sharedColorPanel;
    picker.color=well.color;[picker makeFirstResponder:nil];[picker orderFront:nil];
    // Selection owns the stop shortcuts. The picker remains immediately
    // available for mouse editing without taking keyboard focus from the stop.
    [self.colorWindow makeKeyWindow];
    [self.colorWindow makeFirstResponder:specular?self.colorSpecularBar:self.colorDiffuseBar];
}
- (void)refreshColorSelection:(id)sender {
    (void)sender;BOOL specular=self.colorSpecularWell.active;
    [self refreshPaletteViews];[self showSelectedStopColor:specular];
}
- (void)refreshPaletteViews {
    if(!self.lightingWindow||!self.formulaKnown)return;
    if(!self.lightingUndoHistory.count)[self recordLightingRepaint:self.formulaSettings];
    ObjectLighting object=self.formulaSettings.object;
    if(![self readObjectLighting:&object])return;
    self.refreshingColors=YES;
    NSInteger selected=MAX(0,self.colorStopMenu.indexOfSelectedItem);
    NSMutableArray *opacity=[NSMutableArray array];for(NSColorWell *well in self.specularWells)[opacity addObject:@(well.color.alphaComponent)];self.diffuseBar.opacityStops=opacity;
    for(PaletteView *bar in @[self.diffuseBar,self.strengthDiffuseBar,self.strengthSpecularBar]){bar.palette=object;bar.needsDisplay=YES;}
    ObjectLighting insidePalette=self.formulaSettings.cutting_colors;insidePalette.no_interpolation=object.no_interpolation;for(int i=4;i<10;i++)insidePalette.stops[i]=insidePalette.stops[3];self.cuttingBar.palette=insidePalette;self.cuttingBar.needsDisplay=YES;
    if(self.colorWindow) {
        BOOL inside=self.objectColorsMenu.indexOfSelectedItem==1;
        if(inside){object=self.formulaSettings.cutting_colors;object.no_interpolation=self.interpolationCheck.state==NSControlStateValueOn;}
        NSInteger count=inside?4:10;self.colorSpecularBar.opacityStops=inside?@[@1,@1,@1,@1]:opacity;
        NSMutableArray *diffuseOpacity=[NSMutableArray array];for(NSColorWell *well in self.diffuseWells)[diffuseOpacity addObject:@(well.color.alphaComponent)];self.colorDiffuseBar.opacityStops=inside?@[@1,@1,@1,@1]:diffuseOpacity;
        if(self.colorStopMenu.numberOfItems!=count){[self.colorStopMenu removeAllItems];for(int i=0;i<count;i++)[self.colorStopMenu addItemWithTitle:[NSString stringWithFormat:@"Stop %d",i+1]];selected=0;}
        selected=MIN(count-1,selected);[self.colorStopMenu selectItemAtIndex:selected];
        self.colorDiffuseBar.stopCount=self.colorSpecularBar.stopCount=count;
        ((AdjustmentColorWell *)self.colorDiffuseWell).allowsOpacity=!inside;
        ((AdjustmentColorWell *)self.colorSpecularWell).allowsOpacity=!inside;
        self.colorDiffuseBar.palette=object;self.colorSpecularBar.palette=object;
        self.colorDiffuseBar.selected=selected;self.colorSpecularBar.selected=selected;
        self.colorDiffuseBar.needsDisplay=YES;self.colorSpecularBar.needsDisplay=YES;
        self.colorPosition.stringValue=[NSString stringWithFormat:@"%u",object.stops[selected].position];
        if(inside){ObjectColorStop c=object.stops[selected];self.colorDiffuseWell.color=[NSColor colorWithSRGBRed:c.diffuse[0] green:c.diffuse[1] blue:c.diffuse[2] alpha:1];self.colorSpecularWell.color=[NSColor colorWithWhite:c.specular[0] alpha:1];}
        else {self.colorDiffuseWell.color=self.diffuseWells[selected].color;self.colorSpecularWell.color=self.specularWells[selected].color;}
    }
    self.refreshingColors=NO;
}
- (void)paletteEdited:(id)sender {
    (void)sender;[self updateColorHistograms];[self refreshPaletteViews];
    if([sender isKindOfClass:NSColorWell.class]){if(!self.calculating)[self lightValuesEdited:sender];}
    else if(automaticColorUpdates&&!self.calculating)[self finishLightingSlider];
}
- (void)adjustmentColorEdited:(NSColorWell *)sender {
    if(self.refreshingColors||self.calculating)return;
    NSInteger stop=self.colorStopMenu.indexOfSelectedItem;
    if(self.objectColorsMenu.indexOfSelectedItem==1){ObjectLighting colors=self.formulaSettings.cutting_colors;NSColor *c=[sender.color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];if(sender==self.colorDiffuseWell){colors.stops[stop].diffuse[0]=c.redComponent;colors.stops[stop].diffuse[1]=c.greenComponent;colors.stops[stop].diffuse[2]=c.blueComponent;}else{double strength=(c.redComponent+c.greenComponent+c.blueComponent)/3;for(int i=0;i<3;i++)colors.stops[stop].specular[i]=strength;}[self commitInsideColors:colors];[self lightValuesEdited:sender];return;}
    (sender==self.colorDiffuseWell?self.diffuseWells:self.specularWells)[stop].color=sender.color;
    [self paletteEdited:sender];
}
- (void)colorPositionEdited:(NSTextField *)sender {
    NSScanner *scanner=[NSScanner scannerWithString:numericInputString(sender)];double value;
    if(![scanner scanDouble:&value]||!scanner.isAtEnd||!isfinite(value)||value<0||value>PALETTE_POSITION_MAX||floor(value)!=value){self.colorStatus.stringValue=@"Position must be an integer from 0 to 65535.";return;}
    [self moveColorStop:self.colorStopMenu.indexOfSelectedItem position:(unsigned)value finished:YES];
}
- (void)moveColorStop:(NSInteger)stop position:(unsigned)position finished:(BOOL)finished {
    if(self.calculating)return;
    if(self.objectColorsMenu.indexOfSelectedItem==1){
        ObjectLighting colors=self.formulaSettings.cutting_colors;unsigned old=colors.stops[stop].position;position=MIN(32767,position);
        if(self.glueColors.state==NSControlStateValueOn)for(int i=0;i<4;i++)if(i!=stop){double p=colors.stops[i].position;if(i<stop)p=old?p*position/old:position;else p=old<32767?32767-(32767-p)*(32767-position)/(32767.-old):position;colors.stops[i].position=lround(fmax(0,fmin(32767,p)));}
        colors.stops[stop].position=position;while(stop>0&&colors.stops[stop].position<colors.stops[stop-1].position){ObjectColorStop tmp=colors.stops[stop-1];colors.stops[stop-1]=colors.stops[stop];colors.stops[stop]=tmp;stop--;}while(stop<3&&colors.stops[stop].position>colors.stops[stop+1].position){ObjectColorStop tmp=colors.stops[stop+1];colors.stops[stop+1]=colors.stops[stop];colors.stops[stop]=tmp;stop++;}[self.colorStopMenu selectItemAtIndex:stop];[self commitInsideColors:colors];if(finished)[self endLightingSlider];else{[self beginLightingSlider];[self requestLightingPreview];}return;
    }
    if(!self.lightingUndoHistory.count)[self recordLightingRepaint:self.formulaSettings];
    ObjectLighting object=self.formulaSettings.object;if(![self readObjectLighting:&object])return;
    NSMutableArray *diffuse=[NSMutableArray array],*specular=[NSMutableArray array];for(int i=0;i<10;i++){[diffuse addObject:self.diffuseWells[i].color];[specular addObject:self.specularWells[i].color];}
    unsigned old=object.stops[stop].position;double paletteLimit=fmax(32767,fmax(position,object.stops[9].position));
    if(old!=position) {
        if(self.glueColors.state==NSControlStateValueOn) {
            for(int i=0;i<10;i++)if(i!=stop) {
                double p=object.stops[i].position;
                if(i<stop)p=old?p*position/old:position;
                else p=old<paletteLimit?paletteLimit-(paletteLimit-p)*(paletteLimit-position)/(paletteLimit-old):position;
                object.stops[i].position=(unsigned)lround(fmax(0,fmin(PALETTE_POSITION_MAX,p)));
            }
        }
        object.stops[stop].position=position;
        while(stop>0&&object.stops[stop].position<object.stops[stop-1].position){ObjectColorStop tmp=object.stops[stop-1];object.stops[stop-1]=object.stops[stop];object.stops[stop]=tmp;[diffuse exchangeObjectAtIndex:stop-1 withObjectAtIndex:stop];[specular exchangeObjectAtIndex:stop-1 withObjectAtIndex:stop];stop--;}
        while(stop<9&&object.stops[stop].position>object.stops[stop+1].position){ObjectColorStop tmp=object.stops[stop+1];object.stops[stop+1]=object.stops[stop];object.stops[stop]=tmp;[diffuse exchangeObjectAtIndex:stop+1 withObjectAtIndex:stop];[specular exchangeObjectAtIndex:stop+1 withObjectAtIndex:stop];stop++;}
        for(int i=0;i<10;i++) {
            self.palettePositions[i].stringValue=[NSString stringWithFormat:@"%u",object.stops[i].position];
            self.diffuseWells[i].color=diffuse[i];
            self.specularWells[i].color=specular[i];
        }
        [self.colorStopMenu selectItemAtIndex:stop];[self refreshPaletteViews];
    }
    if(automaticColorUpdates){if(finished)[self endLightingSlider];else{[self beginLightingSlider];[self requestLightingPreview];}}
}
- (void)randomAmountChanged:(NSSlider *)sender {
    self.randomAmounts[sender.tag].stringValue=[NSString stringWithFormat:@"%.17g",sender.doubleValue];
}
- (void)randomAmountEdited:(NSTextField *)sender {
    double value;NSScanner *scanner=[NSScanner scannerWithString:numericInputString(sender)];if(![scanner scanDouble:&value]||!scanner.isAtEnd||!isfinite(value)||value<0||value>3){self.colorStatus.stringValue=@"Random multiplier must be between 0 and 3.";return;}
    self.randomAmountSliders[sender.tag].doubleValue=value;
}
- (void)randomizeColors:(NSButton *)sender {
    int channel=(int)sender.tag;double amount;NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.randomAmounts[channel])];
    if(![scanner scanDouble:&amount]||!scanner.isAtEnd||!isfinite(amount)||amount<0||amount>3){self.colorStatus.stringValue=@"Random multiplier must be between 0 and 3.";return;}
    self.randomAmountSliders[channel].doubleValue=amount;
    NSColor *reference=[self.randomReferences[channel].color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];
    double ref[]={reference.redComponent,reference.greenComponent,reference.blueComponent};
    if(self.objectColorsMenu.indexOfSelectedItem==1){ObjectLighting colors=self.formulaSettings.cutting_colors;for(int i=0;i<4;i++){double scalar=0;for(int k=0;k<3;k++){double value=fmax(0,fmin(1,ref[k]+(arc4random_uniform(1000000)/1000000.-.5)*amount));if(!channel)colors.stops[i].diffuse[k]=value;scalar+=value/3;}if(channel)for(int k=0;k<3;k++)colors.stops[i].specular[k]=scalar;}[self commitInsideColors:colors];[self finishLightingSlider];return;}

    for(int i=0;i<10;i++) {
        double rgb[3];NSColor *diffuse=[self.diffuseWells[i].color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];
        double dif[]={diffuse.redComponent,diffuse.greenComponent,diffuse.blueComponent};
        double r1=cos(arc4random_uniform(1000000)/1000000.*2*M_PI)*.5+.5;
        double blend=sqrt(fmin(1,fmax(1,amount)-arc4random_uniform(1000000)/1000000.*amount));
        for(int j=0;j<3;j++) {
            double random=arc4random_uniform(1000000)/1000000.;
            rgb[j]=channel?(ref[j]+(.5-r1)*amount)*blend+dif[j]*(1-blend):ref[j]+(pow(random,log(fmax(.05,fmin(.95,ref[j])))/log(.5))-ref[j])*amount;
            rgb[j]=fmax(0,fmin(1,rgb[j]));
        }
        (channel?self.specularWells:self.diffuseWells)[i].color=[NSColor colorWithSRGBRed:rgb[0] green:rgb[1] blue:rgb[2] alpha:(channel?self.specularWells:self.diffuseWells)[i].color.alphaComponent];
    }
    [self paletteEdited:sender];
}

- (void)showLighting:(id)sender {
    (void)sender;
    if(!self.lightingWindow) {
        self.lightingWindow=[[NSWindow alloc] initWithContentRect:NSMakeRect(0,0,600,760)
            styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable backing:NSBackingStoreBuffered defer:NO];
        self.lightingWindow.title=@"Lighting";self.lightingWindow.releasedWhenClosed=NO;
        self.lightingWindow.delegate=self;
        NSTabView *tabs=[[NSTabView alloc] initWithFrame:NSMakeRect(12,56,576,692)];
        NSTabViewItem *tab=[[NSTabViewItem alloc] initWithIdentifier:@"object"];tab.label=@"Object";
        CalculationPanel *panel=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,552,700)];
        NSArray *names=@[@"Diffuse strength",@"Specular strength",@"Color start",@"Color end",@"Color variation on Z"];
        NSArray *defaults=@[@"120",@"50",@"68",@"72",@"0"];
        NSMutableArray *fields=[NSMutableArray array],*sliders=[NSMutableArray array];
        for(int i=0;i<5;i++) {
            CGFloat y=i<2?16+i*38:96+(i-2)*38;
            NSTextField *label=[NSTextField labelWithString:names[i]];
            label.frame=NSMakeRect(16,y+4,(i==2||i==3)?94:174,22);[panel addSubview:label];
            NSTextField *field=[[NumericTextField alloc] initWithFrame:NSMakeRect(438,y,100,26)];
            if(i==4)field.frame=NSMakeRect(296,y,66,26);
            if(i==2||i==3){field.frame=NSMakeRect(430,y,44,26);((NumericInputFormatter *)field.formatter).singleDecimal=YES;}
            field.stringValue=defaults[i];field.accessibilityLabel=names[i];
            field.toolTip=i<2?(i?@"0–350, default 50":@"0–250, default 120"):i==4?@"−120..360":@"MB3D palette-range value; default 68 / 72";
            field.target=self;field.action=@selector(objectStrengthEdited:);field.tag=i;
            [panel addSubview:field];[fields addObject:field];
            if(i<5) {
                LiveSlider *slider=[LiveSlider sliderWithValue:i?50:120 minValue:i<2?0:(i==4?-120:-30) maxValue:i<2?(i?350:250):(i==4?360:90) target:self action:@selector(objectSliderChanged:)];
                slider.frame=NSMakeRect(190,y,i==4?98:230,26);slider.tag=i;slider.continuous=YES;
                __weak AppDelegate *weakSelf=self;slider.started=^{[weakSelf beginLightingSlider];};slider.finished=^{[weakSelf endLightingSlider];};
                if(i==4){slider.commandResetValue=@0;slider.toolTip=@"Cmd-click to reset to zero.";}
                slider.accessibilityLabel=names[i];[panel addSubview:slider];[sliders addObject:slider];
            }
        }
        self.fitColorsButton=[NSButton buttonWithTitle:@"Fit" target:self action:@selector(fitColors:)];
        self.fitColorsButton.toolTip=@"Fit to color values in the last completed main render. After importing parameters or restoring history, press Render first. Background pixels are excluded.";self.fitColorsButton.frame=NSMakeRect(480,96,58,26);[panel addSubview:self.fitColorsButton];
        self.objectFields=fields;self.objectSliders=sliders;
        self.outsideHistogram=[[ColorHistogramView alloc]initWithFrame:NSMakeRect(190,127,230,4)];self.outsideHistogram.toolTip=@"Distribution of surface color values in the last main render; background excluded.";[panel addSubview:self.outsideHistogram];
        self.cyclingCheck=[NSButton checkboxWithTitle:@"Color cycling" target:nil action:nil];
        self.cyclingCheck.frame=NSMakeRect(16,212,160,24);[panel addSubview:self.cyclingCheck];
        self.interpolationCheck=[NSButton checkboxWithTitle:@"No interpolation" target:self action:@selector(paletteEdited:)];
        self.interpolationCheck.frame=NSMakeRect(190,212,172,24);[panel addSubview:self.interpolationCheck];
        self.orbitCheck=[NSButton checkboxWithTitle:@"Orbit trap coloring" target:nil action:nil];
        self.orbitCheck.frame=NSMakeRect(368,212,180,24);self.orbitCheck.hidden=YES;
        NSTextField *gammaLabel=[NSTextField labelWithString:@"Gamma"];gammaLabel.frame=NSMakeRect(366,214,56,22);[panel addSubview:gammaLabel];
        LiveSlider *gamma=[LiveSlider sliderWithValue:32 minValue:0 maxValue:63 target:self action:@selector(gammaChanged:)];gamma.frame=NSMakeRect(432,210,60,26);gamma.continuous=YES;gamma.numberOfTickMarks=3;gamma.accessibilityLabel=@"Gamma";gamma.commandResetValue=@32;gamma.toolTip=@"Output gamma: 0.5 to 2, neutral at the center (1). Cmd-click to reset to neutral.";__weak AppDelegate *weakGamma=self;gamma.started=^{[weakGamma beginLightingSlider];};gamma.finished=^{[weakGamma endLightingSlider];};self.gammaSlider=gamma;[panel addSubview:gamma];
        self.internalGammaCheck=[NSButton checkboxWithTitle:@"i2" target:self action:@selector(internalGammaChanged:)];self.internalGammaCheck.frame=NSMakeRect(498,212,42,24);self.internalGammaCheck.toolTip=@"Enable internal gamma of 2 for light calculations.\nThis is independent from the Gamma slider.";[panel addSubview:self.internalGammaCheck];
        NSTextField *zDefault=[NSTextField labelWithString:@"│"];zDefault.frame=NSMakeRect(215,199,8,10);zDefault.font=[NSFont systemFontOfSize:10];zDefault.textColor=NSColor.secondaryLabelColor;zDefault.toolTip=@"Default Color variation on Z: 0";zDefault.accessibilityLabel=@"Color variation on Z default: zero";[panel addSubview:zDefault];
        LightingUndoButton *undo=[LightingUndoButton buttonWithImage:[NSImage imageWithSystemSymbolName:@"arrow.uturn.backward" accessibilityDescription:@"Undo lighting"] target:self action:@selector(undoLighting:)];undo.frame=NSMakeRect(508,210,30,26);undo.imagePosition=NSImageOnly;undo.imageScaling=NSImageScaleProportionallyDown;undo.controlSize=NSControlSizeSmall;undo.toolTip=@"Leftclick:   Undo -> Sets the light parameter to the state before the last painting\nRightclick: Redo";undo.accessibilityLabel=@"Undo lighting; right click to redo";undo.redoAction=^{[weakGamma restoreLightingRedo:YES];};self.lightingUndoButton=undo;[panel addSubview:undo];[self syncLightingUndoButton];
        NSTextField *barLabel=[NSTextField labelWithString:@"Outside colors"];
        barLabel.frame=NSMakeRect(16,242,130,22);[panel addSubview:barLabel];
        self.diffuseBar=[[PaletteView alloc] initWithFrame:NSMakeRect(150,240,388,34.5)];
        self.diffuseBar.enabled=YES;self.diffuseBar.hoverBezel=YES;self.diffuseBar.stacked=YES;self.diffuseBar.accessibilityLabel=@"Outside colors — diffuse, specular, opacity";
        self.diffuseBar.toolTip=@"Outside colors: opacity, specular, diffuse (top to bottom). Click to adjust.";
        __weak AppDelegate *weakSelf=self;
        self.diffuseBar.clicked=^(NSInteger stop,BOOL pick){(void)stop;(void)pick;[weakSelf showColorAdjustment:nil];};
        [panel addSubview:self.diffuseBar];
        NSArray *headings=@[@"Stop",@"Position (0–32767)",@"Diffuse color",@"Specular color"];
        CGFloat x[4]={16,72,260,408};
        for(int i=0;i<4;i++) {
            NSTextField *label=[NSTextField labelWithString:headings[i]];
            label.frame=NSMakeRect(x[i],268,i==1?175:132,22);label.font=[NSFont boldSystemFontOfSize:12];[panel addSubview:label];
        }
        NSMutableArray *positions=[NSMutableArray array],*diffuse=[NSMutableArray array],*specular=[NSMutableArray array];
        [NSColorPanel setPickerMask:NSColorPanelRGBModeMask|NSColorPanelHSBModeMask|NSColorPanelGrayModeMask|NSColorPanelWheelModeMask];
        NSColorPanel.sharedColorPanel.showsAlpha=NO;
        for(int i=0;i<10;i++) {
            CGFloat y=300+i*31;
            NSTextField *label=[NSTextField labelWithString:[NSString stringWithFormat:@"%d",i+1]];
            label.frame=NSMakeRect(16,y+3,40,22);[panel addSubview:label];
            NSTextField *position=[[NumericTextField alloc] initWithFrame:NSMakeRect(72,y,144,26)];
            numericIntegerField(position,YES);position.target=self;position.action=@selector(paletteEdited:);
            position.accessibilityLabel=[NSString stringWithFormat:@"Palette stop %d position",i+1];
            [panel addSubview:position];[positions addObject:position];
            for(int channel=0;channel<2;channel++) {
                NSColorWell *well=[[AdjustmentColorWell alloc] initWithFrame:NSMakeRect(channel?408:260,y,128,26)];
                ((AdjustmentColorWell *)well).allowsOpacity=YES;well.toolTip=channel?@"Solid area shows the RGB color; the narrow checkerboard strip shows transparency.":@"Object diffuse color. Opacity controls DIFS emissive strength; re-render after changing it.";well.target=self;well.action=@selector(paletteEdited:);
                well.accessibilityLabel=[NSString stringWithFormat:@"Palette stop %d %@ color",i+1,channel?@"specular":@"diffuse"];
                [panel addSubview:well];[(channel?specular:diffuse) addObject:well];
            }
        }
        self.palettePositions=positions;self.diffuseWells=diffuse;self.specularWells=specular;
        self.lightingStatus=[NSTextField wrappingLabelWithString:@"Palette positions must remain sorted. Edits apply to the render only."];
        self.lightingStatus.frame=NSMakeRect(16,620,522,36);self.lightingStatus.font=[NSFont systemFontOfSize:11];
        self.lightingStatus.textColor=NSColor.secondaryLabelColor;[panel addSubview:self.lightingStatus];
        self.openLightingButton=[NSButton buttonWithTitle:@"Open…" target:self action:@selector(openLightingFile:)];self.openLightingButton.frame=NSMakeRect(16,662,100,32);[panel addSubview:self.openLightingButton];
        self.saveLightingButton=[NSButton buttonWithTitle:@"Save…" target:self action:@selector(saveLightingFile:)];self.saveLightingButton.frame=NSMakeRect(126,662,100,32);[panel addSubview:self.saveLightingButton];
        self.applyLightingButton=[NSButton buttonWithTitle:@"Apply & Render" target:self action:@selector(calculate:)];
        self.applyLightingButton.frame=NSMakeRect(358,662,180,32);self.applyLightingButton.keyEquivalent=@"\r";
        [panel addSubview:self.applyLightingButton];
        for(NSButton *button in @[self.openLightingButton,self.saveLightingButton,self.lightingUndoButton,self.applyLightingButton])[button removeFromSuperview];
        // Put the outside palette before its range controls; keep following sections clear.
        for(NSView *view in panel.subviews){NSRect f=view.frame;
            if(f.origin.y==240)f.origin.y=96;
            else if(f.origin.y==242)f.origin.y=98;
            else if(f.origin.y>=96&&f.origin.y<240)f.origin.y+=46;
            else if(f.origin.y>=268)f.origin.y+=190;
            view.frame=f;
        }
        [self addCuttingColors:panel];
        NSBox *insideSeparator=[[NSBox alloc]initWithFrame:NSMakeRect(16,290,522,1)];insideSeparator.boxType=NSBoxSeparator;[panel addSubview:insideSeparator];

        NSMutableArray *zoomButtons=[NSMutableArray array];for(int i=0;i<2;i++){NSButton *button=[NSButton buttonWithTitle:@"Zoom" target:self action:@selector(histogramZoomChanged:)];[button setButtonType:NSButtonTypePushOnPushOff];button.tag=i;button.frame=NSMakeRect(480,i?382:180,58,26);button.controlSize=NSControlSizeSmall;button.toolTip=@"Zoom the slider and histogram display ranges so Color start is at 25% and Color end at 75%. Turn off to restore the full range. Parameter values do not change.";[panel addSubview:button];[zoomButtons addObject:button];}self.histogramZoomButtons=zoomButtons;

        NSMutableArray *paletteViews=[NSMutableArray array];
        for(NSView *view in panel.subviews){NSRect f=view.frame;
            if(f.origin.y<90){f.origin.y+=34;} // Strength rows directly below the mode choices.
            else if(f.origin.y<450){[paletteViews addObject:view];f.origin.y+=38;}
            else f.origin.y+=28;
            view.frame=f;
        }

        NSArray *existingViews=panel.subviews.copy;[self addObjectMapControls:panel];
        NSMutableArray *mapViews=[NSMutableArray array];
        for(NSView *view in panel.subviews)if(![existingViews containsObject:view]){NSRect f=view.frame;f.origin.y+=122;view.frame=f;[mapViews addObject:view];}
        [self.objectMapEnabled removeFromSuperview];[mapViews removeObject:self.objectMapEnabled];
        for(NSView *view in mapViews.copy){
            if(view==self.objectMapNumber||([view isKindOfClass:NSTextField.class]&&[[(NSTextField *)view stringValue] isEqual:@"Map number"])) {[view removeFromSuperview];[mapViews removeObject:view];continue;}
            if(view==self.coloringMode||([view isKindOfClass:NSTextField.class]&&[[(NSTextField *)view stringValue] isEqual:@"Mode"])){
                [mapViews removeObject:view];view.frame=view==self.coloringMode?NSMakeRect(150,124,258,28):NSMakeRect(16,128,130,22);continue;
            }
            NSRect f=view.frame;f.origin.y-=32;view.frame=f;
        }
        for(NSView *view in paletteViews){NSRect f=view.frame;f.origin.y+=34;view.frame=f;}
        [paletteViews addObject:self.coloringMode];
        for(NSView *view in panel.subviews)if([view isKindOfClass:NSTextField.class]&&[[(NSTextField *)view stringValue] isEqual:@"Mode"])[paletteViews addObject:view];
        // Output/internal gamma apply to palette and map coloring alike.
        [paletteViews removeObject:gamma];[paletteViews removeObject:gammaLabel];
        [paletteViews removeObject:self.internalGammaCheck];
        self.paletteColoringViews=paletteViews;self.mapColoringViews=mapViews;
        NSMutableArray *choices=[NSMutableArray array];
        for(int i=0;i<2;i++){NSButton *choice=[NSButton radioButtonWithTitle:i?@"Map coloring":@"Palette coloring" target:self action:@selector(objectColoringChanged:)];choice.tag=i;choice.frame=NSMakeRect(96+i*190,12,180,26);[panel addSubview:choice];[choices addObject:choice];}self.objectColoringChoices=choices;
        self.objectFields[0].frame=NSMakeRect(300,50,64,26);self.objectFields[1].frame=NSMakeRect(300,88,64,26);
        self.objectSliders[0].frame=NSMakeRect(190,50,100,26);self.objectSliders[1].frame=NSMakeRect(190,88,100,26);
        for(int i=0;i<2;i++){PaletteView *bar=[[PaletteView alloc]initWithFrame:NSMakeRect(378,54+i*38,160,18)];bar.specular=i;bar.enabled=YES;bar.hoverBezel=YES;bar.accessibilityLabel=i?@"Outside specular colors":@"Outside diffuse colors";bar.clicked=^(NSInteger stop,BOOL pick){(void)stop;(void)pick;[weakSelf showColorAdjustment:nil];};[panel addSubview:bar];if(i)self.strengthSpecularBar=bar;else self.strengthDiffuseBar=bar;}
        for(NSView *view in existingViews)if(![paletteViews containsObject:view]&&view.frame.origin.y>=480)[view removeFromSuperview];
        NSArray *beforeFavorites=panel.subviews.copy;[self addColorFavorites:panel];
        for(NSView *view in panel.subviews)if(![beforeFavorites containsObject:view]){NSRect f=view.frame;f.origin.y+=34;view.frame=f;}
        // Reserve a gray bezel surround without shrinking or moving the palette itself.
        for(PaletteView *bar in @[self.diffuseBar,self.cuttingBar,self.strengthDiffuseBar,self.strengthSpecularBar])bar.frame=NSInsetRect(bar.frame,-5,-5);
        self.lightingStatus.frame=NSMakeRect(16,612,522,18);self.lightingStatus.maximumNumberOfLines=1;self.lightingStatus.lineBreakMode=NSLineBreakByTruncatingTail;[panel addSubview:self.lightingStatus];panel.frame=NSMakeRect(0,0,552,636);
        tab.view=panel;[tabs addTabViewItem:tab];
        [self addLightTabs:tabs];[self addAmbientTab:tabs];[self addDepthFogTab:tabs];[self addBackPictureTab:tabs];
        CGFloat paneHeight=636;
        for(NSTabViewItem *item in tabs.tabViewItems)for(NSView *view in item.view.subviews)if(!view.hidden)paneHeight=MAX(paneHeight,NSMaxY(view.frame)+6);
        NSRect tabFrame=tabs.frame;tabFrame.size.height=paneHeight+tabs.frame.size.height-tabs.contentRect.size.height;tabs.frame=tabFrame;
        CGFloat contentHeight=NSMaxY(tabFrame)+12;[self.lightingWindow setContentSize:NSMakeSize(600,contentHeight)];
        NSView *content=[[NSView alloc]initWithFrame:NSMakeRect(0,0,600,contentHeight)];[content addSubview:tabs];
        self.openLightingButton.frame=NSMakeRect(26,12,72,32);self.saveLightingButton.frame=NSMakeRect(210,12,70,32);
        self.keepLightsCheck=[NSButton checkboxWithTitle:@"Keep lights" target:nil action:nil];self.keepLightsCheck.frame=NSMakeRect(104,16,100,24);self.keepLightsCheck.toolTip=@"Ignore light sources in an opened lighting file and retain the current light sources.";[content addSubview:self.keepLightsCheck];
        self.resetLightingButton=[NSButton buttonWithTitle:@"Reset" target:self action:@selector(resetLighting:)];self.resetLightingButton.frame=NSMakeRect(286,12,70,32);self.resetLightingButton.toolTip=@"Reset lighting to gray diffuse colors and one white directional light. Undo restores the previous lighting.";[content addSubview:self.resetLightingButton];
        self.lightingUndoButton.frame=NSMakeRect(360,12,36,32);self.applyLightingButton.frame=NSMakeRect(400,12,174,32);
        for(NSButton *button in @[self.openLightingButton,self.saveLightingButton,self.lightingUndoButton,self.applyLightingButton])[content addSubview:button];
        self.lightingWindow.contentView=content;
        [self.lightingWindow center];[self populateObjectLighting];
    }
    [self setCalculating:self.calculating];[self positionWindowRightOfMain:self.lightingWindow];[self.lightingWindow makeKeyAndOrderFront:nil];
}
#include "mutagen_ui.inc"
#include "fog_ui.inc"
#include "background_ui.inc"
- (void)addCuttingColors:(NSView *)panel {
    NSMutableArray *sliders=[NSMutableArray array],*fields=[NSMutableArray array];
    for(int i=0;i<2;i++){
        CGFloat y=346+i*36;NSTextField *label=[NSTextField labelWithString:i?@"Color end":@"Color start"];label.frame=NSMakeRect(16,y+4,94,22);[panel addSubview:label];
        LiveSlider *slider=[LiveSlider sliderWithValue:60 minValue:0 maxValue:127 target:self action:@selector(cuttingColorsChanged:)];slider.tag=i;slider.frame=NSMakeRect(190,y,230,26);slider.continuous=YES;slider.accessibilityLabel=[@"Cutting " stringByAppendingString:label.stringValue];__weak AppDelegate *owner=self;slider.started=^{[owner beginLightingSlider];};slider.finished=^{[owner endLightingSlider];};[panel addSubview:slider];[sliders addObject:slider];
        NSTextField *field=[[NumericTextField alloc]initWithFrame:NSMakeRect(430,y,44,26)];((NumericInputFormatter *)field.formatter).singleDecimal=YES;numericIntegerField(field,YES);field.tag=i;field.target=self;field.action=@selector(cuttingColorsChanged:);[panel addSubview:field];[fields addObject:field];
    }self.cuttingColorSliders=sliders;self.cuttingColorFields=fields;
    self.insideHistogram=[[ColorHistogramView alloc]initWithFrame:NSMakeRect(190,375,230,4)];self.insideHistogram.toolTip=@"Distribution of inside/cutting color values in the last main render.";[panel addSubview:self.insideHistogram];
    NSTextField *label=[NSTextField labelWithString:@"Inside colors"];label.frame=NSMakeRect(16,302,130,22);[panel addSubview:label];
    self.cuttingBar=[[PaletteView alloc]initWithFrame:NSMakeRect(150,300,388,34.5)];self.cuttingBar.stopCount=4;self.cuttingBar.hoverBezel=YES;self.cuttingBar.stacked=YES;self.cuttingBar.accessibilityLabel=@"Inside colors — diffuse, specular, opacity";self.cuttingBar.markers=NO;self.cuttingBar.enabled=YES;self.cuttingBar.toolTip=@"Inside colors: opacity, specular, diffuse (top to bottom). Click to adjust inside colors.";
    __weak AppDelegate *owner=self;
    self.cuttingBar.clicked=^(NSInteger stop,BOOL pick){(void)stop;(void)pick;[owner showCuttingColorAdjustment:nil];};
    [panel addSubview:self.cuttingBar];
}
- (void)showCuttingColorAdjustment:(id)sender {(void)sender;[self showColorAdjustment:@1];}
- (void)objectColorsChanged:(id)sender {(void)sender;[self refreshPaletteViews];}
- (void)commitInsideColors:(ObjectLighting)colors {
    self.cuttingColorRepaintPending=YES;
    for(int i=4;i<10;i++)colors.stops[i]=colors.stops[3];RenderOptions settings=self.formulaSettings;settings.cutting_colors=colors;settings.cutting_colors_override=1;self.formulaSettings=settings;[self populateCuttingColors];[self refreshPaletteViews];
}
- (void)histogramZoomChanged:(NSButton *)sender {
    if(!self.histogramZoomRanges)self.histogramZoomRanges=[NSMutableDictionary dictionary];
    NSNumber *key=@(sender.tag);
    if(sender.state==NSControlStateValueOn){
        NSArray<NSTextField *> *fields=sender.tag?self.cuttingColorFields:@[self.objectFields[2],self.objectFields[3]];
        double start=fields[0].doubleValue,end=fields[1].doubleValue,delta=fabs(end-start);
        if(delta<1e-9)delta=fmax(1,fabs(start)*.01);
        double low=fmin(start,end)-delta*.5,high=fmax(start,end)+delta*.5;
        self.histogramZoomRanges[key]=[NSValue valueWithPoint:NSMakePoint(low,high)];
    }else [self.histogramZoomRanges removeObjectForKey:key];
    [self updateHistogramZoom];
}
- (void)updateHistogramZoom {
    if(self.histogramZoomButtons.count!=2)return;
    for(int channel=0;channel<2;channel++){
        ColorHistogramView *histogram=channel?self.insideHistogram:self.outsideHistogram;NSButton *button=self.histogramZoomButtons[channel];
        button.enabled=!self.calculating;
        double minimum=channel?0:-30,maximum=channel?127:90,span=maximum-minimum;
        NSValue *range=self.histogramZoomRanges[@(channel)];BOOL zoom=button.state==NSControlStateValueOn&&range!=nil;
        NSPoint bounds=range.pointValue;double low=zoom?bounds.x:minimum,high=zoom?bounds.y:maximum;
        histogram.firstBin=zoom?(NSInteger)floor((low-minimum)/span*256):0;histogram.lastBin=zoom?(NSInteger)ceil((high-minimum)/span*256)-1:255;histogram.needsDisplay=YES;
        for(int end=0;end<2;end++){
            NSSlider *slider=channel?self.cuttingColorSliders[end]:self.objectSliders[2+end];NSTextField *field=channel?self.cuttingColorFields[end]:self.objectFields[2+end];
            slider.minValue=minimum;slider.maxValue=maximum;slider.minValue=low;slider.maxValue=high;slider.doubleValue=field.doubleValue;
        }
    }
}
- (void)updateColorHistograms {
    if(self.renderColorHistograms.length!=3*256*sizeof(unsigned))return;
    const unsigned *bins=self.renderColorHistograms.bytes;BOOL trap=self.orbitCheck.state==NSControlStateValueOn;
    self.outsideHistogram.bins=[NSData dataWithBytes:bins+(trap?256:0) length:256*sizeof(unsigned)];self.insideHistogram.bins=[NSData dataWithBytes:bins+512 length:256*sizeof(unsigned)];self.outsideHistogram.needsDisplay=YES;self.insideHistogram.needsDisplay=YES;[self updateHistogramZoom];
}
- (void)populateCuttingColors {
    if(!self.cuttingColorFields.count)return;ObjectLighting colors=self.formulaSettings.cutting_colors;colors.no_interpolation=self.interpolationCheck.state==NSControlStateValueOn;
    self.cuttingColorFields[0].doubleValue=colors.palette_start;self.cuttingColorFields[1].doubleValue=colors.palette_end;self.cuttingColorSliders[0].doubleValue=colors.palette_start;self.cuttingColorSliders[1].doubleValue=colors.palette_end;
    for(int i=4;i<10;i++)colors.stops[i]=colors.stops[3];self.cuttingBar.palette=colors;self.cuttingBar.needsDisplay=YES;[self updateHistogramZoom];

}
- (void)cuttingColorsChanged:(NSControl *)sender {
    self.cuttingColorRepaintPending=YES;
    if([sender isKindOfClass:NSSlider.class])self.cuttingColorFields[sender.tag].integerValue=lround(sender.doubleValue);
    double start=self.cuttingColorFields[0].doubleValue,end=self.cuttingColorFields[1].doubleValue;if(!isfinite(start)||!isfinite(end)||start<0||end<0||start>127||end>127)return;
    RenderOptions settings=self.formulaSettings;settings.cutting_colors_override=1;settings.cutting_colors.palette_start=round(start);settings.cutting_colors.palette_end=round(end);self.formulaSettings=settings;[self populateCuttingColors];[self requestLightingPreview];if(!self.lightingSliderTracking)[self finishLightingSlider];
}
- (void)addAmbientTab:(NSTabView *)tabs {
    NSTabViewItem *tab=[[NSTabViewItem alloc] initWithIdentifier:@"ambient"];tab.label=@"Ambient";
    CalculationPanel *panel=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,552,700)];
    NSMutableArray *wells=[NSMutableArray array],*fields=[NSMutableArray array],*sliders=[NSMutableArray array];
    NSArray *colorNames=@[@"Ambient top color",@"Ambient bottom color",@"Background top color",@"Background bottom color"];
    for(int i=0;i<4;i++) {
        CGFloat x=16+(i%2)*270,y=18+(i/2)*60;NSTextField *label=[NSTextField labelWithString:colorNames[i]];label.frame=NSMakeRect(x,y+4,172,24);[panel addSubview:label];
        NSColorWell *well=[[AdjustmentColorWell alloc] initWithFrame:NSMakeRect(x+180,y,70,30)];well.accessibilityLabel=colorNames[i];well.target=self;well.action=@selector(ambientEdited:);[panel addSubview:well];[wells addObject:well];
    }
    NSArray *names=@[@"Ambient strength",@"Depth fog",@"Ambient shadow",@"2nd reflection",@"Diffuse shadow"];
    double maximum[]={270,240,106,106,255};
    for(int i=0;i<5;i++) {
        CGFloat y=154+i*48;NSTextField *label=[NSTextField labelWithString:names[i]];label.frame=NSMakeRect(16,y+4,168,24);[panel addSubview:label];
        LiveSlider *slider=[LiveSlider sliderWithValue:0 minValue:0 maxValue:maximum[i] target:self action:@selector(ambientSlider:)];slider.frame=NSMakeRect(180,y,240,26);slider.tag=i;slider.continuous=YES;slider.accessibilityLabel=names[i];__weak AppDelegate *weakSelf=self;slider.started=^{[weakSelf beginLightingSlider];};slider.finished=^{[weakSelf endLightingSlider];};[panel addSubview:slider];[sliders addObject:slider];
        NSTextField *field=[[NumericTextField alloc] initWithFrame:NSMakeRect(438,y,98,26)];field.accessibilityLabel=names[i];field.tag=i;field.target=self;field.action=@selector(ambientEdited:);[panel addSubview:field];[fields addObject:field];
    }
    self.ambientWells=wells;self.ambientFields=fields;self.ambientSliders=sliders;
    self.ambientFarFog=[NSButton checkboxWithTitle:@"Far depth fog" target:self action:@selector(ambientEdited:)];self.ambientFarFog.frame=NSMakeRect(16,404,245,26);[panel addSubview:self.ambientFarFog];
    self.ambientRelative=[NSButton checkboxWithTitle:@"Relative to object" target:self action:@selector(ambientEdited:)];self.ambientRelative.frame=NSMakeRect(286,404,250,26);[panel addSubview:self.ambientRelative];
    NSTextField *label=[NSTextField labelWithString:@"Background gradient"];label.frame=NSMakeRect(16,456,170,24);[panel addSubview:label];
    self.ambientGradient=[[NSPopUpButton alloc] initWithFrame:NSMakeRect(180,450,356,30) pullsDown:NO];[self.ambientGradient addItemsWithTitles:@[@"Linear",@"Squared",@"Square root"]];self.ambientGradient.target=self;self.ambientGradient.action=@selector(ambientEdited:);self.ambientGradient.accessibilityLabel=@"Background gradient";[panel addSubview:self.ambientGradient];
    label=[NSTextField wrappingLabelWithString:@"Ambient shadow changes the strength of the calculated occlusion. Diffuse shadow blends occlusion on lights with calculated hard shadows; other lights use full occlusion. Roughness requires smooth-normal data and is unavailable."];label.frame=NSMakeRect(16,510,520,64);label.font=[NSFont systemFontOfSize:12];label.textColor=NSColor.secondaryLabelColor;[panel addSubview:label];
    tab.view=panel;[tabs addTabViewItem:tab];
}
- (void)populateAmbientLighting {
    if(!self.ambientFields||!self.formulaKnown)return;
    AmbientLighting a=self.formulaSettings.ambient;double values[]={a.strength*90,a.depth/.8e-6,self.formulaSettings.shadows.ambient_strength*53,sqrt(fmax(0,a.second_reflection))/.022,a.diffuse_shadow*255};
    for(int i=0;i<5;i++){self.ambientFields[i].stringValue=[NSString stringWithFormat:@"%.17g",values[i]];self.ambientSliders[i].doubleValue=values[i];}
    self.ambientAOBaseline=self.ambientFields[2].stringValue;
    for(int i=0;i<4;i++)self.ambientWells[i].color=[NSColor colorWithSRGBRed:a.colors[i][0] green:a.colors[i][1] blue:a.colors[i][2] alpha:1];
    self.ambientRelative.state=a.relative_to_object?NSControlStateValueOn:NSControlStateValueOff;self.ambientFarFog.state=a.far_fog?NSControlStateValueOn:NSControlStateValueOff;[self.ambientGradient selectItemAtIndex:a.gradient];
}
- (BOOL)readAmbientLighting:(RenderOptions *)options {
    if(!self.ambientFields)return YES;
    double values[5],maximum[]={270,240,265,106,255};
    for(int i=0;i<5;i++){NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.ambientFields[i])];if(![scanner scanDouble:&values[i]]||!scanner.isAtEnd||!isfinite(values[i])||values[i]<-1e-12||values[i]>maximum[i]+1e-12*maximum[i]){self.statusLabel.stringValue=@"Check Ambient values: strength 0–270, depth 0–240, shadow 0–265, reflection 0–106, diffuse shadow 0–255.";return NO;}
        // Scaling imported endpoints can put them a few ulps outside the UI range.
        values[i]=fmin(maximum[i],fmax(0,values[i]));}
    AmbientLighting a=options->ambient;a.strength=values[0]/90;a.depth=values[1]*.8e-6;a.second_reflection=pow(values[3]*.022,2);a.diffuse_shadow=values[4]/255;
    for(int i=0;i<4;i++){NSColor *c=[self.ambientWells[i].color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];if(!c)return NO;a.colors[i][0]=c.redComponent;a.colors[i][1]=c.greenComponent;a.colors[i][2]=c.blueComponent;}
    a.relative_to_object=self.ambientRelative.state==NSControlStateValueOn;a.far_fog=self.ambientFarFog.state==NSControlStateValueOn;a.gradient=(int)self.ambientGradient.indexOfSelectedItem;
    if(![self.ambientFields[2].stringValue isEqual:self.ambientAOBaseline]){options->shadows_override=1;options->shadows.ambient_strength=values[2]/53;}
    options->ambient_override=1;options->ambient=a;return [self readBackPicture:options];
}
- (void)ambientSlider:(NSSlider *)sender {
    self.ambientFields[sender.tag].stringValue=[NSString stringWithFormat:@"%.17g",sender.doubleValue];
    if(sender.tag==2&&self.shadowFields.count>2)self.shadowFields[2].stringValue=[NSString stringWithFormat:@"%.17g",sender.doubleValue/53];
    if(sender.tag==2&&self.ambientShadowSliders.count)[self syncAmbientShadowSliders];
    [self requestLightingPreview];
}
- (void)ambientEdited:(id)sender {
    for(int i=0;i<5;i++)self.ambientSliders[i].doubleValue=self.ambientFields[i].doubleValue;
    if(sender==self.ambientFields[2]&&self.shadowFields.count>2){self.shadowFields[2].stringValue=[NSString stringWithFormat:@"%.17g",self.ambientFields[2].doubleValue/53];[self syncAmbientShadowSliders];}
    if([sender isKindOfClass:NSColorWell.class])[self lightValuesEdited:sender];else [self finishLightingSlider];
}
- (NSString *)objectMapFolder {return [self applicationMapsFolderURL].path;}
- (void)addObjectMapControls:(NSView *)panel {
    self.objectMapEnabled=[NSButton checkboxWithTitle:@"Diffuse map coloring" target:self action:@selector(objectMapChanged:)];self.objectMapEnabled.frame=NSMakeRect(16,12,230,26);[panel addSubview:self.objectMapEnabled];
    NSTextField *numberLabel=[NSTextField labelWithString:@"Map number"];numberLabel.frame=NSMakeRect(250,16,96,24);[panel addSubview:numberLabel];
    self.objectMapNumber=[[NumericTextField alloc] initWithFrame:NSMakeRect(350,12,58,26)];numericIntegerField(self.objectMapNumber,YES);self.objectMapNumber.stringValue=@"0";self.objectMapNumber.accessibilityLabel=@"Diffuse map number";self.objectMapNumber.target=self;self.objectMapNumber.action=@selector(objectMapChanged:);[panel addSubview:self.objectMapNumber];
    NSTextField *label=[NSTextField labelWithString:@"Diffuse map"];label.frame=NSMakeRect(16,48,138,24);[panel addSubview:label];
    self.objectMapMenu=[[NSPopUpButton alloc] initWithFrame:NSMakeRect(150,44,258,28) pullsDown:NO];
    self.objectMapMenu.cell=[[MapFilenameCell alloc]initTextCell:@"" pullsDown:NO];
    self.objectMapMenu.accessibilityLabel=@"Diffuse map file";self.objectMapMenu.target=self;self.objectMapMenu.action=@selector(objectMapChanged:);
    [self.objectMapMenu addItemWithTitle:@"None — diffuse palette"];self.objectMapMenu.lastItem.representedObject=@"";
    NSArray *files=[[NSFileManager.defaultManager contentsOfDirectoryAtPath:[self objectMapFolder] error:nil] sortedArrayUsingSelector:@selector(localizedStandardCompare:)];
    for(NSString *file in files)if([@[@"png",@"jpg",@"jpeg",@"bmp",@"gif",@"tif",@"tiff"] containsObject:file.pathExtension.lowercaseString]) {
        [self.objectMapMenu addItemWithTitle:file];self.objectMapMenu.lastItem.representedObject=file;
        addMapMenuThumbnail(self.objectMapMenu.lastItem,[[self objectMapFolder] stringByAppendingPathComponent:file]);
    }
    self.objectMapMenu.toolTip=[self objectMapFolder];[panel addSubview:self.objectMapMenu];
    self.objectMapPreview=[[NSImageView alloc] initWithFrame:NSMakeRect(420,44,116,64)];self.objectMapPreview.imageScaling=NSImageScaleProportionallyUpOrDown;[panel addSubview:self.objectMapPreview];
    label=[NSTextField labelWithString:@"Map mode"];label.frame=NSMakeRect(16,83,130,24);[panel addSubview:label];
    self.objectMapMode=[[NSPopUpButton alloc] initWithFrame:NSMakeRect(150,79,258,28) pullsDown:NO];
    [self.objectMapMode addItemsWithTitles:@[@"Iteration / trap",@"Normals",@"Wrap 1",@"Wrap 2"]];self.objectMapMode.accessibilityLabel=@"Diffuse map mode";self.objectMapMode.target=self;self.objectMapMode.action=@selector(objectMapChanged:);[panel addSubview:self.objectMapMode];
    NSMutableArray *fields=[NSMutableArray array],*sliders=[NSMutableArray array];
    NSArray *names=@[@"Map X offset",@"Map Y offset",@"Map rotation (°)",@"Map scale"];
    double low[]={0,0,-180,.05},high[]={1,1,180,20},value[]={.5,.5,0,1};
    for(int i=0;i<4;i++) {
        CGFloat y=116+28*i;label=[NSTextField labelWithString:names[i]];label.frame=NSMakeRect(16,y+3,138,24);[panel addSubview:label];
        LiveSlider *slider=[LiveSlider sliderWithValue:value[i] minValue:low[i] maxValue:high[i] target:self action:@selector(objectMapSlider:)];slider.frame=NSMakeRect(150,y,258,25);slider.tag=i;slider.accessibilityLabel=names[i];slider.continuous=YES;
        __weak AppDelegate *weakSelf=self;slider.started=^{[weakSelf beginLightingSlider];};slider.finished=^{[weakSelf endLightingSlider];};[panel addSubview:slider];[sliders addObject:slider];
        NSTextField *field=[[NumericTextField alloc] initWithFrame:NSMakeRect(420,y,116,25)];field.doubleValue=value[i];field.tag=i;field.accessibilityLabel=names[i];field.target=self;field.action=@selector(objectMapChanged:);[panel addSubview:field];[fields addObject:field];
    }
    self.objectMapFields=fields;self.objectMapSliders=sliders;
    self.objectMapCombine=[NSButton checkboxWithTitle:@"Combine map intensity with palette colors" target:self action:@selector(objectMapChanged:)];self.objectMapCombine.frame=NSMakeRect(16,232,294,24);self.objectMapCombine.font=[NSFont systemFontOfSize:11];[panel addSubview:self.objectMapCombine];
    NSTextField *modeLabel=[NSTextField labelWithString:@"Mode"];modeLabel.frame=NSMakeRect(314,234,38,22);[panel addSubview:modeLabel];
    self.coloringMode=[[NSPopUpButton alloc]initWithFrame:NSMakeRect(352,230,184,28) pullsDown:NO];[self.coloringMode addItemsWithTitles:@[@"Smooth Iterations",@"Orbit trap (mindist. to 0)",@"Last length increase",@"Rout angle of X, Y",@"Rout angle of X, Z",@"Rout angle of Y, Z",@"Map on output vector"]];self.coloringMode.target=self;self.coloringMode.action=@selector(coloringModeChanged:);self.coloringMode.accessibilityLabel=@"Coloring Mode";self.coloringMode.toolTip=@"Changing the coloring mode recalculates the scene.";[panel addSubview:self.coloringMode];
}
- (void)addColorFavorites:(NSView *)panel {
    self.customColorFavorites=[NSMutableArray array];NSArray *saved=[NSUserDefaults.standardUserDefaults arrayForKey:@"ColorFavorites.v3"]?:[NSUserDefaults.standardUserDefaults arrayForKey:@"ColorFavorites.v2"]?:[NSUserDefaults.standardUserDefaults arrayForKey:@"ColorFavorites.v1"];
    for(int i=0;i<20;i++){id entry=i<(int)saved.count?saved[i]:nil;[self.customColorFavorites addObject:colorFavoriteRecord(entry)];}
    NSBox *line=[[NSBox alloc]initWithFrame:NSMakeRect(16,456,522,1)];line.boxType=NSBoxSeparator;[panel addSubview:line];
    NSTextField *label=[NSTextField labelWithString:@"Favorites"];label.font=[NSFont boldSystemFontOfSize:12];label.frame=NSMakeRect(16,465,120,22);[panel addSubview:label];
    self.addColorFavoriteButton=[ReadableSymbolButton buttonWithImage:[NSImage imageWithSystemSymbolName:@"heart" accessibilityDescription:@"Favorite"] target:self action:@selector(addColorFavorite:)];((ReadableSymbolButton *)self.addColorFavoriteButton).symbolSize=20;self.addColorFavoriteButton.frame=NSMakeRect(130,460,32,28);self.addColorFavoriteButton.imageScaling=NSImageScaleProportionallyDown;self.addColorFavoriteButton.toolTip=@"Save the current colors and strengths in the first empty custom slot.";[panel addSubview:self.addColorFavoriteButton];
    NSMutableArray *buttons=[NSMutableArray array];NSArray *names=@[@"Sand",@"Slime",@"Metallic",@"Flower",@"Neutral"];
    __weak AppDelegate *owner=self;
    for(int i=0;i<25;i++){ColorFavoriteButton *button=[ColorFavoriteButton buttonWithTitle:@"" target:self action:@selector(applyColorFavorite:)];button.tag=i;button.bezelStyle=NSBezelStyleRegularSquare;button.frame=NSMakeRect(i<5?174+i*54:16+((i-5)%10)*52,i<5?460:500+((i-5)/10)*38,50,34);button.imagePosition=NSImageOnly;button.imageScaling=NSImageScaleProportionallyUpOrDown;button.toolTip=i<5?names[i]:[NSString stringWithFormat:@"Custom %d — empty",i-4];button.accessibilityLabel=button.toolTip;
        if(i>=5){NSInteger slot=i-5;button.clearFavorite=^{[owner.customColorFavorites replaceObjectAtIndex:slot withObject:NSData.data];[owner saveColorFavorites];};}
        [panel addSubview:button];[buttons addObject:button];
    }self.colorFavoriteButtons=buttons;[self refreshColorFavorites];
}
- (void)refreshColorFavorites {
    BOOL full=YES;
    for(int i=0;i<25;i++){ColorFavoriteButton *button=self.colorFavoriteButtons[i];ColorFavorite favorite={0};BOOL filled=i<5;
        if(filled)favorite=colorFavoriteBasic(i);else{NSData *entry=self.customColorFavorites[i-5];filled=entry.length==sizeof favorite;if(filled)memcpy(&favorite,entry.bytes,sizeof favorite);else full=NO;button.toolTip=[NSString stringWithFormat:@"Custom %d%@",i-4,filled?@" — click to apply; right-click to clear":@" — empty"];button.accessibilityLabel=button.toolTip;}
        button.image=filled?colorFavoriteThumbnail(favorite,[self objectMapFolder]):nil;button.title=filled?@"":[NSString stringWithFormat:@"%d",i-4];button.imagePosition=filled?NSImageOnly:NSNoImage;button.enabled=filled&&!self.calculating;
    }self.addColorFavoriteButton.enabled=!full&&!self.calculating;
}
- (void)saveColorFavorites {[NSUserDefaults.standardUserDefaults setObject:self.customColorFavorites forKey:@"ColorFavorites.v3"];[NSUserDefaults.standardUserDefaults removeObjectForKey:@"ColorFavorites.v2"];[NSUserDefaults.standardUserDefaults removeObjectForKey:@"ColorFavorites.v1"];[self refreshColorFavorites];}
- (void)addColorFavorite:(id)sender {
    (void)sender;if(self.calculating)return;RenderOptions current;if(![self lightingFileOptions:&current])return;
    for(int i=0;i<20;i++)if(![self.customColorFavorites[i] length]){ColorFavorite favorite=colorFavoriteCapture(current);self.customColorFavorites[i]=[NSData dataWithBytes:&favorite length:sizeof favorite];[self saveColorFavorites];return;}
}
- (void)applyColorFavorite:(NSButton *)sender {
    if(self.calculating)return;ColorFavorite favorite={0};if(sender.tag<5)favorite=colorFavoriteBasic((int)sender.tag);else{NSData *entry=self.customColorFavorites[sender.tag-5];if(entry.length!=sizeof favorite)return;memcpy(&favorite,entry.bytes,sizeof favorite);}
    RenderOptions current;if(![self lightingFileOptions:&current])return;self.formulaSettings=colorFavoriteApply(current,favorite);[self populateObjectLighting];self.cuttingColorRepaintPending=YES;[self finishLightingSlider];
}
- (void)updateObjectColoringMode {
    BOOL map=self.objectMapEnabled.state==NSControlStateValueOn;
    for(NSButton *choice in self.objectColoringChoices){choice.state=(choice.tag==map)?NSControlStateValueOn:NSControlStateValueOff;choice.enabled=!self.calculating;}
    for(NSView *view in self.paletteColoringViews)view.hidden=map;
    for(NSView *view in self.mapColoringViews)view.hidden=!map;
}
- (void)objectColoringChanged:(NSButton *)sender {
    self.objectMapEnabled.state=sender.tag?NSControlStateValueOn:NSControlStateValueOff;
    [self objectMapChanged:self.objectMapEnabled];[self updateObjectColoringMode];
}
- (void)updateObjectMapPreview {
    NSString *file=self.objectMapMenu.selectedItem.representedObject;
    self.objectMapPreview.image=file.length?[[NSImage alloc] initWithContentsOfFile:[[self objectMapFolder] stringByAppendingPathComponent:file]]:nil;
    if(file.length&&!self.objectMapPreview.image)self.lightingStatus.stringValue=@"Warning: map unavailable; rendering with the diffuse palette.";
}
- (void)objectMapSlider:(NSSlider *)sender {
    self.objectMapFields[sender.tag].doubleValue=sender.doubleValue;[self requestLightingPreview];
}
- (BOOL)selectObjectMapNumber {
    NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.objectMapNumber)];int number;
    if(![scanner scanInt:&number]||!scanner.isAtEnd||number<0||number>65535){self.lightingStatus.stringValue=@"Map number must be an integer from 0 to 65535.";return NO;}
    NSString *selected=self.objectMapMenu.selectedItem.representedObject;
    if(selected.stringByDeletingPathExtension.intValue==number&&(selected.length||number==0))return YES;
    if(!number){[self.objectMapMenu selectItemAtIndex:0];return YES;}
    for(NSMenuItem *item in self.objectMapMenu.itemArray) {
        NSString *file=item.representedObject;
        if(file.length&&file.stringByDeletingPathExtension.intValue==number){[self.objectMapMenu selectItem:item];return YES;}
    }
    NSString *file=[NSString stringWithFormat:@"%d.png",number];
    [self.objectMapMenu addItemWithTitle:[file stringByAppendingString:@" (unavailable)"]];self.objectMapMenu.lastItem.representedObject=file;[self.objectMapMenu selectItem:self.objectMapMenu.lastItem];return YES;
}
- (BOOL)lightingFileOptions:(RenderOptions *)settings {
    *settings=self.formulaSettings;
    if(![self readObjectLighting:&settings->object]||![self readLights:settings]||![self readAmbientLighting:settings]||![self readDepthFog:settings]||![self readReflections:settings])return NO;
    settings->object_override=1;return YES;
}
- (void)lightingFileDialog:(BOOL)saving {
    if(self.calculating)return;RenderOptions settings;if(![self lightingFileOptions:&settings])return;
    NSSavePanel *panel=saving?[NSSavePanel savePanel]:[NSOpenPanel openPanel];panel.allowedFileTypes=@[@"m3l"];panel.canCreateDirectories=saving;
    NSURL *last=[NSUserDefaults.standardUserDefaults URLForKey:@"FileDialog.LightingURL"];if(last)panel.directoryURL=last.URLByDeletingLastPathComponent;
    if(saving)panel.nameFieldStringValue=last.lastPathComponent.length?last.lastPathComponent:@"Lighting.m3l";
    BOOL keepLights=self.keepLightsCheck.state==NSControlStateValueOn;NSString *source=self.currentPath;
    [panel beginSheetModalForWindow:self.lightingWindow completionHandler:^(NSModalResponse response){if(response!=NSModalResponseOK)return;retainUserFileSelection(panel.URL);
        [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(finishLightingSlider) object:nil];self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;NSUInteger generation=++self.generation;[self setCalculating:YES];
        self.lightingStatus.stringValue=saving?@"Saving lighting…":@"Opening lighting…";
        dispatch_async(self.renderQueue,^{NSString *message=nil;RenderOptions imported={0};BOOL ok=saving?lightingFileWrite(source,settings,panel.URL.path,&message):lightingFileReadKeepingLights(panel.URL.path,source,settings,keepLights,&imported,&message);
            interactiveUI(^{if(generation!=self.generation)return;[self setCalculating:NO];if(!ok){[self showFileError:saving?@"Could not save lighting":@"Could not open lighting" message:message?:@"Invalid lighting file."];return;}
                retainUserFileSelection(panel.URL);[NSUserDefaults.standardUserDefaults setURL:panel.URL forKey:@"FileDialog.LightingURL"];
                if(saving)self.lightingStatus.stringValue=@"Lighting saved.";
                else{self.formulaSettings=imported;[self populateObjectLighting];[self finishLightingSlider];self.lightingStatus.stringValue=keepLights?@"Lighting imported. Current light sources retained.":@"Lighting imported. Imported positional lights are disabled.";}
            });
        });
    }];
}
- (void)resetLighting:(id)sender {
    (void)sender;if(self.calculating||!self.formulaKnown)return;
    RenderOptions current=self.formulaSettings;
    if(!current.preserved_header_valid){NSString *message=nil;NSData *data=lightingFileScene(self.currentPath,current,&message);if(!data){[self showFileError:@"Could not reset lighting" message:message];return;}memcpy(current.preserved_header,data.bytes,840);current.preserved_header_valid=1;}
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(finishLightingSlider) object:nil];self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;
    self.formulaSettings=lightingNeutralSettings(current);self.backPictureName=nil;[self populateObjectLighting];[self finishLightingSlider];self.lightingStatus.stringValue=@"Neutral lighting: gray diffuse colors and one white directional light.";
}
- (void)openLightingFile:(id)sender {(void)sender;[self lightingFileDialog:NO];}
- (void)saveLightingFile:(id)sender {(void)sender;[self lightingFileDialog:YES];}
#include "lighting_history.inc"
- (void)internalGammaChanged:(id)sender {
    (void)sender;RenderOptions o=self.formulaSettings;if(!o.preserved_header_valid){NSString *message=nil;NSData *data=lightingFileScene(self.currentPath,o,&message);if(!data)return;memcpy(o.preserved_header,data.bytes,840);o.preserved_header_valid=1;}o.preserved_header[439]=(o.preserved_header[439]&~1)|(self.internalGammaCheck.state==NSControlStateValueOn?1:0);self.formulaSettings=o;[self finishLightingSlider];
}
- (void)gammaChanged:(NSSlider *)sender {
    if(self.calculating)return;RenderOptions settings=self.formulaSettings;settings.gamma_override=1;settings.gamma=lround(sender.doubleValue);self.formulaSettings=settings;[self requestGammaPreview];
}
- (void)coloringModeChanged:(NSPopUpButton *)sender {
    if(self.calculating)return;NSInteger mode=sender.indexOfSelectedItem;
    self.orbitCheck.state=mode>0?NSControlStateValueOn:NSControlStateValueOff;
    RenderOptions settings=self.formulaSettings;settings.ssao_override=1;settings.color_option=(int)MAX(0,mode-1);settings.object_override=1;settings.object.orbit_trap=mode>0;self.formulaSettings=settings;
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(finishLightingSlider) object:nil];self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;
    self.lightingRepaintRequested=NO;self.preserveNavigatorForLighting=YES;[self calculate:self.renderButton];self.preserveNavigatorForLighting=NO;
}
- (void)objectMapChanged:(id)sender {
    if(sender==self.objectMapNumber){if(![self selectObjectMapNumber])return;self.objectMapEnabled.state=self.objectMapNumber.intValue?NSControlStateValueOn:NSControlStateValueOff;}
    else if(sender==self.objectMapMenu){NSString *file=self.objectMapMenu.selectedItem.representedObject;self.objectMapNumber.stringValue=[NSString stringWithFormat:@"%d",file.stringByDeletingPathExtension.intValue];self.objectMapEnabled.state=file.length?NSControlStateValueOn:NSControlStateValueOff;}
    else if(sender==self.objectMapEnabled&&self.objectMapEnabled.state==NSControlStateValueOn){
        if(![self selectObjectMapNumber])return;
        if(self.objectMapMenu.indexOfSelectedItem==0&&self.objectMapMenu.numberOfItems>1){[self.objectMapMenu selectItemAtIndex:1];NSString *file=self.objectMapMenu.selectedItem.representedObject;self.objectMapNumber.stringValue=[NSString stringWithFormat:@"%d",file.stringByDeletingPathExtension.intValue];}
    }
    for(int i=0;i<4;i++)self.objectMapSliders[i].doubleValue=self.objectMapFields[i].doubleValue;
    [self updateObjectColoringMode];[self updateObjectMapPreview];[self finishLightingSlider];
}
- (void)objectSliderChanged:(NSSlider *)sender {
    self.objectFields[sender.tag].stringValue=[NSString stringWithFormat:@"%.17g",sender.doubleValue];
    [self requestLightingPreview];
}
- (void)objectStrengthEdited:(NSTextField *)sender {
    if(sender.tag<5)self.objectSliders[sender.tag].doubleValue=sender.doubleValue;
}
- (void)populateObjectLighting {
    self.fitColorsButton.enabled=!self.calculating&&self.colorFitValid;
    if(!self.lightingWindow||!self.formulaKnown)return;
    if(!self.lightingUndoHistory.count)[self recordLightingRepaint:self.formulaSettings];
    ObjectLighting object=self.formulaSettings.object;
    NSString *file=[NSString stringWithUTF8String:object.map.file];NSInteger selected=-1;
    for(NSMenuItem *item in self.objectMapMenu.itemArray)if([item.representedObject isEqual:file])selected=[self.objectMapMenu indexOfItem:item];
    if(selected<0&&file.length){[self.objectMapMenu addItemWithTitle:[file stringByAppendingString:@" (unavailable)"]];self.objectMapMenu.lastItem.representedObject=file;selected=self.objectMapMenu.numberOfItems-1;}
    self.objectMapNumber.stringValue=[NSString stringWithFormat:@"%d",object.map.number];self.objectMapEnabled.state=(!object.map.disabled&&(file.length||object.map.number))?NSControlStateValueOn:NSControlStateValueOff;
    [self.objectMapMenu selectItemAtIndex:MAX(0,selected)];[self.objectMapMode selectItemAtIndex:object.map.mode];self.objectMapCombine.state=object.map.combine?NSControlStateValueOn:NSControlStateValueOff;
    double mapValues[]={object.map.offset_x,object.map.offset_y,object.map.rotation,object.map.scale>0?object.map.scale:1};
    for(int i=0;i<4;i++){self.objectMapFields[i].doubleValue=mapValues[i];self.objectMapSliders[i].doubleValue=mapValues[i];}
    [self updateObjectColoringMode];[self updateObjectMapPreview];
    double rangeStart=90*sqrt(fmax(0,(object.palette_start+10900)/32767))-30;
    double rangeEnd=90*sqrt(fmax(0,(object.palette_end+10900)/32767))-30;
    NSArray *values=@[[NSString stringWithFormat:@"%.17g",object.diffuse*50],
        [NSString stringWithFormat:@"%.17g",object.specular*50],[NSString stringWithFormat:@"%.17g",rangeStart],
        [NSString stringWithFormat:@"%.17g",rangeEnd],[NSString stringWithFormat:@"%.17g",object.z_variation]];
    for(int i=0;i<5;i++)self.objectFields[i].stringValue=values[i];
    self.rangeBaseline=@[self.objectFields[2].stringValue,self.objectFields[3].stringValue];
    self.objectSliders[0].doubleValue=object.diffuse*50;self.objectSliders[1].doubleValue=object.specular*50;
    self.objectSliders[2].doubleValue=rangeStart;self.objectSliders[3].doubleValue=rangeEnd;self.objectSliders[4].doubleValue=object.z_variation;
    [self populateLights];
    self.cyclingCheck.state=object.cycling?NSControlStateValueOn:NSControlStateValueOff;
    self.interpolationCheck.state=object.no_interpolation?NSControlStateValueOn:NSControlStateValueOff;
    self.internalGammaCheck.state=(self.formulaSettings.preserved_header_valid&&(self.formulaSettings.preserved_header[439]&1))?NSControlStateValueOn:NSControlStateValueOff;
    self.gammaSlider.doubleValue=self.formulaSettings.gamma_override?self.formulaSettings.gamma:32;
    self.orbitCheck.state=object.orbit_trap?NSControlStateValueOn:NSControlStateValueOff;[self.coloringMode selectItemAtIndex:object.orbit_trap?MAX(1,MIN(6,self.formulaSettings.color_option+1)):0];
    for(int i=0;i<10;i++) {
        ObjectColorStop stop=object.stops[i];self.palettePositions[i].stringValue=[NSString stringWithFormat:@"%u",stop.position];
        self.diffuseWells[i].color=[NSColor colorWithSRGBRed:stop.diffuse[0] green:stop.diffuse[1] blue:stop.diffuse[2] alpha:self.formulaSettings.reflections.opacity_set?self.formulaSettings.reflections.opacity[0][i]:1];
        self.specularWells[i].color=[NSColor colorWithSRGBRed:stop.specular[0] green:stop.specular[1] blue:stop.specular[2] alpha:self.formulaSettings.reflections.opacity_set?self.formulaSettings.reflections.opacity[1][i]:1];
    }
    [self updateColorHistograms];[self populateCuttingColors];[self refreshPaletteViews];[self populateAmbientLighting];[self populateDepthFog];[self populateBackPicture];
    self.lightingStatus.stringValue=@"Ready. Edit colors and press Apply & Render. The scene file is unchanged.";
}
- (BOOL)readObjectLighting:(ObjectLighting *)object {
    double values[5];
    for(int i=0;i<5;i++) {
        NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.objectFields[i])];
        if(![scanner scanDouble:&values[i]]||!scanner.isAtEnd||!isfinite(values[i])) {
            self.lightingStatus.stringValue=@"Enter finite numeric values in all Object fields.";return NO;
        }
    }
    if(values[0]<0||values[0]>250||values[1]<0||values[1]>350||values[2]<-30||values[2]>10000||values[3]<-30||values[3]>10000||values[4]<-120||values[4]>360) {
        self.lightingStatus.stringValue=@"Diffuse: 0–250; Specular: 0–350; range: −30..10000; Z variation: −120..360.";return NO;
    }
    if(self.objectMapMenu) {
        if(![self selectObjectMapNumber])return NO;
        NSString *file=self.objectMapMenu.selectedItem.representedObject;
        if([file lengthOfBytesUsingEncoding:NSUTF8StringEncoding]>=sizeof object->map.file){self.lightingStatus.stringValue=@"Map filename is too long.";return NO;}
        ObjectMap map={0};map.disabled=self.objectMapEnabled.state!=NSControlStateValueOn;snprintf(map.file,sizeof map.file,"%s",file.UTF8String?file.UTF8String:"");
        map.number=MIN(65535,MAX(0,file.stringByDeletingPathExtension.intValue));map.mode=(int)self.objectMapMode.indexOfSelectedItem;map.combine=self.objectMapCombine.state==NSControlStateValueOn;
        double *targets[]={&map.offset_x,&map.offset_y,&map.rotation,&map.scale};
        for(int i=0;i<4;i++){NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.objectMapFields[i])];if(![scanner scanDouble:targets[i]]||!scanner.isAtEnd||!isfinite(*targets[i])){self.lightingStatus.stringValue=@"Enter finite map offset, rotation and scale values.";return NO;}}
        if(fabs(map.offset_x)>100||fabs(map.offset_y)>100||fabs(map.rotation)>36000||map.scale<1e-12||map.scale>1e18){self.lightingStatus.stringValue=@"Map offsets: −100..100; rotation: −36000..36000°; scale: 1e-12..1e18.";return NO;}
        object->map=map;
    }
    object->diffuse=values[0]/50;object->specular=values[1]/50;
    if(![self.objectFields[2].stringValue isEqualToString:self.rangeBaseline[0]])object->palette_start=pow((values[2]+30)/90,2)*32767-10900;
    if(![self.objectFields[3].stringValue isEqualToString:self.rangeBaseline[1]])object->palette_end=pow((values[3]+30)/90,2)*32767-10900;
    object->z_variation=values[4];object->cycling=self.cyclingCheck.state==NSControlStateValueOn;
    object->no_interpolation=self.interpolationCheck.state==NSControlStateValueOn;object->orbit_trap=self.orbitCheck.state==NSControlStateValueOn;
    for(int i=0;i<10;i++) {
        NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.palettePositions[i])];double position;
        if(![scanner scanDouble:&position]||!scanner.isAtEnd||!isfinite(position)||position!=floor(position)||position<0||position>PALETTE_POSITION_MAX||(i&&position<object->stops[i-1].position)) {
            self.lightingStatus.stringValue=@"Palette positions must be sorted integers from 0 to 65535.";return NO;
        }
        NSColor *diffuse=[self.diffuseWells[i].color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];
        NSColor *specular=[self.specularWells[i].color colorUsingColorSpace:NSColorSpace.sRGBColorSpace];
        if(!diffuse||!specular){self.lightingStatus.stringValue=@"Choose RGB colors for the palette.";return NO;}
        object->stops[i]=(ObjectColorStop){(unsigned)position,{diffuse.redComponent,diffuse.greenComponent,diffuse.blueComponent},
            {specular.redComponent,specular.greenComponent,specular.blueComponent}};
    }
    return YES;
}
- (void)showFormulas:(id)sender {
    (void)sender;
    if(!self.formulasWindow) {
        self.formulasWindow=[[NSWindow alloc] initWithContentRect:NSMakeRect(0,0,640,740) styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskClosable backing:NSBackingStoreBuffered defer:NO];self.formulasWindow.title=@"Formulas";self.formulasWindow.releasedWhenClosed=NO;self.formulasWindow.delegate=self;
        CalculationPanel *panel=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,640,740)];
        NSArray *names=@[@"Formula mode",@"Repeat from",@"DE combination",@"Render",@"Part 2 starts",@"Part 2 repeats"];
        NSMutableArray *menusGlobal=[NSMutableArray array];
        for(int i=0;i<6;i++){CGFloat x=i<3?16:330,y=14+(i%3)*38;NSTextField *label=[NSTextField labelWithString:names[i]];label.frame=NSMakeRect(x,y+4,120,24);[panel addSubview:label];NSPopUpButton *menu=[[NSPopUpButton alloc] initWithFrame:NSMakeRect(x+122,y,174,28) pullsDown:NO];menu.accessibilityLabel=names[i];menu.target=self;menu.action=@selector(formulaModeChanged:);[panel addSubview:menu];[menusGlobal addObject:menu];}
        self.formulaMode=menusGlobal[0];[self.formulaMode addItemsWithTitles:@[@"Alternate",@"Interpolate",@"DEcombinate"]];self.repeatPopup=menusGlobal[1];self.formulaCombine=menusGlobal[2];[self.formulaCombine addItemsWithTitles:@[@"Min",@"Max",@"Inv max",@"Min lin",@"Min nlin",@"Mix"]];self.formulaRenderMode=menusGlobal[3];[self.formulaRenderMode addItemsWithTitles:@[@"Outside",@"Inside",@"In and outside"]];self.formulaSplit=menusGlobal[4];self.formulaRepeat2=menusGlobal[5];
        for(int i=0;i<FORMULA_UI_SLOTS;i++){NSString *name=[NSString stringWithFormat:@"Formula %d",i+1];[self.repeatPopup addItemWithTitle:name];[self.formulaRepeat2 addItemWithTitle:name];if(i)[self.formulaSplit addItemWithTitle:name];}
        NSTabView *tabs=[[NSTabView alloc] initWithFrame:NSMakeRect(12,172,616,346)];self.formulaTabs=tabs;tabs.delegate=self;
        for(int direction=0;direction<2;direction++){NSButton *move=[NSButton buttonWithTitle:direction?@"Move Right >":@"< Move Left" target:self action:@selector(moveFormulaSlot:)];move.tag=direction?1:-1;move.frame=NSMakeRect(16+direction*130,130,124,28);[panel addSubview:move];if(direction)self.formulaMoveRight=move;else self.formulaMoveLeft=move;}
        for(int paste=0;paste<2;paste++){NSButton *button=[(paste?NSButton.class:FormulaCopyButton.class) buttonWithTitle:paste?@"Paste":@"Copy" target:self action:@selector(formulaClipboardAction:)];if(!paste)button.toolTip=@"Copy this formula slot. Right-click to copy all active formula names as a comma-separated line.";button.tag=paste;button.frame=NSMakeRect(276+paste*130,130,124,28);[panel addSubview:button];}
        self.formulaInfoButton=[NSButton buttonWithTitle:@"Info" target:self action:@selector(toggleFormulaInfo:)];[self.formulaInfoButton setButtonType:NSButtonTypePushOnPushOff];self.formulaInfoButton.frame=NSMakeRect(536,130,84,28);self.formulaInfoButton.toolTip=@"Show information for the selected formula instead of its parameter controls.";[panel addSubview:self.formulaInfoButton];
        NSMutableArray *infoViews=[NSMutableArray array];
        NSMutableArray *powers=[NSMutableArray array],*multipliers=[NSMutableArray array],*counts=[NSMutableArray array],*menus=[NSMutableArray array],*integerGroups=[NSMutableArray array],*boxGroups=[NSMutableArray array],*boxes=[NSMutableArray array],*randGroups=[NSMutableArray array],*randFields=[NSMutableArray array];
        RenderOptions settings=self.formulaSettings;
        for(int i=0;i<FORMULA_UI_SLOTS;i++) {
            FormulaSlot f=settings.program.slots[i];
            NSTabViewItem *tab=[[NSTabViewItem alloc] initWithIdentifier:@(i)];
            tab.label=[NSString stringWithFormat:@"F%d",i+1];
            CalculationPanel *content=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,384,274)];
            NSPopUpButton *menu=[[NSPopUpButton alloc] initWithFrame:NSMakeRect(10,4,365,30) pullsDown:YES];
            [menu addItemWithTitle:@"Integer Power"];menu.menu.autoenablesItems=NO;
            NSArray *categories=@[@"3D",@"3Da",@"4D",@"4Da",@"Ads",@"dIFS",@"dIFSa"];
            NSArray *hints=@[@"Escape-time 3D formulas",@"3D formulas with analytic DE",@"Escape-time 4D formulas",@"4D formulas with analytic DE",@"Additional transformations",@"dIFS shapes",@"dIFS transformations"];
            for(int category=0;category<7;category++){
                NSMutableArray<NSMenuItem*> *leaves=[NSMutableArray array];
                for(int index=0;index<formula_menu_count();index++){int kind=formulaKindForMenu(index);if(formulaCategory(kind)!=category)continue;NSMenuItem *leaf=[[NSMenuItem alloc]initWithTitle:[NSString stringWithUTF8String:formula_name(kind)] action:@selector(formulaMenuChosen:) keyEquivalent:@""];leaf.tag=kind;leaf.representedObject=@(i);leaf.target=self;[[FormulaThumbnails shared]addItem:leaf kind:kind];[leaves addObject:leaf];}
                addFormulaMenuGroups(menu.menu,leaves,category,categories[category],hints[category]);
            }
            formulaSelectKind(menu,f.kind);
            [self addFormulaSearch:menu slot:i];
            menu.tag=i;menu.target=self;menu.action=@selector(formulaSelectionChanged:);
            menu.accessibilityLabel=[NSString stringWithFormat:@"Formula %d type",i+1];
            [content addSubview:menu];[menus addObject:menu];
            CalculationPanel *integerGroup=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,38,384,116)];
            NSArray *labels=@[@"Integer power",@"Z multiplier"];
            for(NSUInteger row=0;row<2;row++) {
                NSTextField *label=[NSTextField labelWithString:labels[row]];
                label.frame=NSMakeRect(10,5+row*38,190,22);[integerGroup addSubview:label];
            }
            NSPopUpButton *power=[[NSPopUpButton alloc] initWithFrame:NSMakeRect(230,0,145,30) pullsDown:NO];
            [power addItemsWithTitles:@[@"2",@"3",@"4",@"5",@"6",@"7",@"8"]];
            [power selectItemWithTitle:[NSString stringWithFormat:@"%d",f.power]];
            power.accessibilityLabel=[NSString stringWithFormat:@"Formula %d integer power",i+1];
            [integerGroup addSubview:power];[powers addObject:power];
            NSTextField *z=[[NumericTextField alloc] initWithFrame:NSMakeRect(230,40,145,26)];
            z.stringValue=[NSString stringWithFormat:@"%.17g",f.z_multiplier];
            z.toolTip=@"Finite number from −100 to 100. Default: −1.";
            z.accessibilityLabel=[NSString stringWithFormat:@"Formula %d Z multiplier",i+1];
            z.target=self;z.action=@selector(calculate:);[integerGroup addSubview:z];[multipliers addObject:z];
            [content addSubview:integerGroup];[integerGroups addObject:integerGroup];
            CalculationPanel *boxGroup=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,38,384,116)];
            NSArray *boxNames=@[@"Scale",@"Min R",@"Fold"];
            double defaults[3]={f.scale,f.min_radius,f.fold};
            NSMutableArray *slotFields=[NSMutableArray array];
            for(int row=0;row<3;row++) {
                NSTextField *label=[NSTextField labelWithString:boxNames[row]];
                label.frame=NSMakeRect(10,5+row*38,190,22);[boxGroup addSubview:label];
                NSTextField *field=[[NumericTextField alloc] initWithFrame:NSMakeRect(230,2+row*38,145,26)];
                field.stringValue=[NSString stringWithFormat:@"%.17g",defaults[row]];
                field.accessibilityLabel=[NSString stringWithFormat:@"Formula %d %@",i+1,boxNames[row]];
                field.toolTip=row==1?@"Minimum sphere radius: −100–100. Default: 0.5.":row==0?@"Scale: −100..100. Default: 2.":@"Box fold: −100..100. Default: 1.";
                field.target=self;field.action=@selector(calculate:);[boxGroup addSubview:field];[slotFields addObject:field];
            }
            [content addSubview:boxGroup];[boxGroups addObject:boxGroup];[boxes addObject:slotFields];
            CalculationPanel *randPanel=[[CalculationPanel alloc] initWithFrame:NSMakeRect(0,0,560,490)];NSMutableArray *randValues=[NSMutableArray array];FormulaSlot randDefaults=formula_slot_default(101);
            for(int j=0;j<16;j++){FormulaParameter uiSpec=formulaUIParameter(101,j<13?j:0);const FormulaParameter *spec=&uiSpec;NSTextField *label=[NSTextField labelWithString:[NSString stringWithUTF8String:spec->name]];label.frame=NSMakeRect(10,j*30+4,230,24);label.tag=100+j;[randPanel addSubview:label];NSTextField *field=[[NumericTextField alloc] initWithFrame:NSMakeRect(250,j*30,260,26)];field.stringValue=[NSString stringWithFormat:@"%.17g",formula_slot_value(f.parameters[1]>0?f:randDefaults,j)];field.accessibilityLabel=[NSString stringWithFormat:@"Formula %d %s",i+1,spec->name];field.target=self;field.action=@selector(calculate:);[randPanel addSubview:field];[randValues addObject:field];}
            NSScrollView *randScroll=[[NSScrollView alloc] initWithFrame:NSMakeRect(0,38,584,210)];randScroll.hasVerticalScroller=YES;randScroll.autohidesScrollers=YES;randScroll.documentView=randPanel;[content addSubview:randScroll];[randGroups addObject:randScroll];[randFields addObject:randValues];

            NSTextField *countLabel=[NSTextField labelWithString:@"Iterations per pass"];
            countLabel.tag=90;countLabel.frame=NSMakeRect(10,168,190,22);[content addSubview:countLabel];
            NSTextField *count=[[NumericTextField alloc] initWithFrame:NSMakeRect(230,164,145,26)];
            count.stringValue=[NSString stringWithFormat:@"%d",f.count];
            count.toolTip=@"0 disables this slot; 1–10000 applications per pass or interpolation weight.";
            count.accessibilityLabel=[NSString stringWithFormat:@"Formula %d iterations per pass",i+1];
            numericIntegerField(count,YES);count.target=self;count.action=@selector(calculate:);[content addSubview:count];[counts addObject:count];
            NSTextField *hint=[NSTextField labelWithString:@"Zero disables this slot. Interpolate uses counts as weights."];
            hint.frame=NSMakeRect(10,208,365,40);hint.font=[NSFont systemFontOfSize:11];hint.textColor=NSColor.secondaryLabelColor;
            NSScrollView *info=[[NSScrollView alloc]initWithFrame:NSMakeRect(0,38,584,250)];info.hasVerticalScroller=YES;info.autohidesScrollers=YES;info.hidden=YES;
            NSTextView *description=[[NSTextView alloc]initWithFrame:NSMakeRect(0,0,564,250)];description.editable=NO;description.selectable=YES;description.richText=NO;description.font=[NSFont systemFontOfSize:13];description.textContainerInset=NSMakeSize(10,8);description.verticallyResizable=YES;description.autoresizingMask=NSViewWidthSizable;description.textContainer.widthTracksTextView=YES;description.textContainer.containerSize=NSMakeSize(564,CGFLOAT_MAX);info.documentView=description;[content addSubview:info];[infoViews addObject:info];
            [content addSubview:hint];tab.view=content;[tabs addTabViewItem:tab];
        }
        self.formulaInfoViews=infoViews;self.randFormulaFields=randFields;self.randFormulaGroups=randGroups;
        self.formulaMenus=menus;self.integerGroups=integerGroups;self.boxGroups=boxGroups;self.boxFields=boxes;
        self.powerPopups=powers;self.zMultiplierFields=multipliers;self.formulaCountFields=counts;for(NSTextField *field in counts)field.delegate=self;
        self.formulaSlotTabs=[tabs.tabViewItems copy];[panel addSubview:tabs];
        NSArray *globalNames=@[@"Min iterations",@"Max iterations",@"R bailout",@"Maxits part 2",@"Smooth DEcomb",@"Fpow"];NSMutableArray *fields=[NSMutableArray array];
        for(int i=0;i<6;i++){CGFloat x=16+(i%3)*208,y=538+(i/3)*40;NSTextField *label=[NSTextField labelWithString:globalNames[i]];label.frame=NSMakeRect(x,y+4,112,22);[panel addSubview:label];NSTextField *field=[[NumericTextField alloc] initWithFrame:NSMakeRect(x+114,y,80,26)];numericIntegerField(field,i==0||i==1||i==3);field.accessibilityLabel=globalNames[i];field.target=self;field.action=@selector(calculate:);[panel addSubview:field];[fields addObject:field];}
        self.formulaGlobalFields=fields;
        self.formulaNumerical=[NSButton checkboxWithTitle:@"Disable analytical DE (use numerical DE)" target:self action:@selector(formulaModeChanged:)];self.formulaNumerical.frame=NSMakeRect(16,620,600,26);[panel addSubview:self.formulaNumerical];
        self.formulaStatus=[NSTextField wrappingLabelWithString:@""];self.formulaStatus.frame=NSMakeRect(16,653,604,32);self.formulaStatus.font=[NSFont systemFontOfSize:11];self.formulaStatus.textColor=NSColor.secondaryLabelColor;[panel addSubview:self.formulaStatus];
        self.applyFormulaButton=[NSButton buttonWithTitle:@"Apply & Render" target:self action:@selector(calculate:)];self.applyFormulaButton.frame=NSMakeRect(440,692,180,32);self.applyFormulaButton.keyEquivalent=@"\r";[panel addSubview:self.applyFormulaButton];
        NSButton *reset=[NSButton buttonWithTitle:@"Reset formulas" target:self action:@selector(resetFormulaProgram:)];reset.frame=NSMakeRect(16,692,180,32);[panel addSubview:reset];
        self.formulasWindow.contentView=panel;[self.formulasWindow center];[self populateFormulaWindow];
    }
    [self setCalculating:self.calculating];[self positionWindowRightOfMain:self.formulasWindow];[self.formulasWindow makeKeyAndOrderFront:nil];
}
- (void)formulaModeChanged:(id)sender {
    (void)sender;BOOL combined=self.formulaMode.indexOfSelectedItem==2,interpolate=self.formulaMode.indexOfSelectedItem==1;
    NSInteger available=interpolate?2:FORMULA_UI_SLOTS;
    if([self.formulaTabs indexOfTabViewItem:self.formulaTabs.selectedTabViewItem]>=available)[self.formulaTabs selectTabViewItemAtIndex:0];
    while(self.formulaTabs.numberOfTabViewItems>available)[self.formulaTabs removeTabViewItem:self.formulaTabs.tabViewItems.lastObject];
    while(self.formulaTabs.numberOfTabViewItems<available)[self.formulaTabs addTabViewItem:self.formulaSlotTabs[self.formulaTabs.numberOfTabViewItems]];
    for(NSTextField *count in self.formulaCountFields){numericIntegerField(count,!interpolate);NSTextField *label=(NSTextField *)[count.superview viewWithTag:90];label.stringValue=interpolate?@"Interpolation weight":@"Iterations per pass";count.toolTip=interpolate?@"Interpolation weight, 0–10000. Fractional weights are supported.":@"Iterations per pass, 0–10000.";}
    self.repeatPopup.enabled=!interpolate&&!self.calculating;[self updateFormulaMoveButtons];[self refreshFormulaTabLabels];
    if(combined&&self.formulaRepeat2.indexOfSelectedItem<self.formulaSplit.indexOfSelectedItem+1)[self.formulaRepeat2 selectItemAtIndex:self.formulaSplit.indexOfSelectedItem+1];
    self.formulaCombine.enabled=combined;self.formulaSplit.enabled=combined;self.formulaRepeat2.enabled=combined;self.formulaGlobalFields[3].enabled=combined;self.formulaGlobalFields[4].enabled=combined;self.formulaGlobalFields[5].enabled=self.formulaNumerical.state==NSControlStateValueOn||(combined&&self.formulaCombine.indexOfSelectedItem==5);
    self.formulaStatus.stringValue=self.formulaMode.indexOfSelectedItem==1?@"Interpolate blends slots 1 and 2 each iteration, using their values as weights.":combined?@"DEcombinate evaluates two groups. Mix runs escape-time part 1, then direct-distance IFS part 2.":@"Alternate runs enabled slots in order, then returns to Repeat from. Zero disables a slot.";
}
- (void)populateFormulaWindow {
    if(!self.formulasWindow)return;FormulaProgram p=self.formulaSettings.program;
    self.populatingFormulas=YES;
    for(int i=0;i<FORMULA_UI_SLOTS;i++){FormulaSlot f=p.slots[i];formulaSelectKind(self.formulaMenus[i],f.kind);[self formulaSelectionChanged:self.formulaMenus[i]];[self.powerPopups[i] selectItemWithTitle:[NSString stringWithFormat:@"%d",f.power]];self.zMultiplierFields[i].stringValue=[NSString stringWithFormat:@"%.17g",f.z_multiplier];double values[]={f.scale,f.min_radius,f.fold};for(int j=0;j<3;j++)self.boxFields[i][j].stringValue=[NSString stringWithFormat:@"%.17g",values[j]];self.formulaCountFields[i].stringValue=[NSString stringWithFormat:@"%.9g",formula_iteration_value(p,i)];if(usesGenericFormulaEditor(f.kind))for(int j=0;j<formula_parameter_count(f.kind);j++)self.randFormulaFields[i][j].stringValue=[NSString stringWithFormat:@"%.17g",formulaUIDisplayValue(f.kind,j,formula_slot_value(f,j))];}
    [self.formulaMode selectItemAtIndex:p.mode];[self.formulaRenderMode selectItemAtIndex:p.render_mode];[self.formulaCombine selectItemAtIndex:p.combine];[self.repeatPopup selectItemAtIndex:p.repeat_from];[self.formulaSplit selectItemAtIndex:p.split-1];[self.formulaRepeat2 selectItemAtIndex:p.repeat2];self.formulaNumerical.state=p.numerical_de?NSControlStateValueOn:NSControlStateValueOff;
    double values[]={p.min_iterations,self.formulaSettings.iterations,p.bailout,p.max_iterations2,p.smooth,p.formula_power};for(int i=0;i<6;i++)self.formulaGlobalFields[i].stringValue=[NSString stringWithFormat:@"%.17g",values[i]];self.formulaMaxBaseline=self.formulaGlobalFields[1].stringValue;[self formulaModeChanged:nil];
    self.populatingFormulas=NO;[self refreshFormulaTabLabels];
}
- (void)copyActiveFormulaNames:(id)sender {
    (void)sender;NSMutableArray<NSString *> *names=[NSMutableArray array];
    for(NSUInteger slot=0;slot<(self.formulaMode.indexOfSelectedItem==1?2:self.formulaMenus.count);slot++)if(self.formulaCountFields[slot].doubleValue>0)
        [names addObject:[NSString stringWithUTF8String:formula_name(formulaSelectedKind(self.formulaMenus[slot]))]];
    NSPasteboard *clipboard=NSPasteboard.generalPasteboard;[clipboard clearContents];[clipboard setString:[names componentsJoinedByString:@", "] forType:NSPasteboardTypeString];
    self.formulaStatus.stringValue=@"Active formula names copied to clipboard.";
}
- (void)formulaClipboardAction:(NSButton *)sender {
    if(self.calculating)return;
    NSInteger slot=[self.formulaTabs indexOfTabViewItem:self.formulaTabs.selectedTabViewItem];if(slot<0||slot>=FORMULA_UI_SLOTS)return;
    if(sender.tag&&!self.formulaClipboard){self.formulaStatus.stringValue=@"Copy a formula slot before pasting.";return;}
    [self.formulasWindow makeFirstResponder:nil];RenderOptions settings=self.formulaSettings;
    if(![self readFormulaWindow:&settings])return;settings.iterations=self.formulaGlobalFields[1].intValue;
    if(sender.tag){FormulaSlot copied;[self.formulaClipboard getBytes:&copied length:sizeof copied];FormulaProgram from={.mode=(int)self.formulaClipboardMode};from.slots[0]=copied;double value=formula_iteration_value(from,0);copied.count=settings.program.mode==1?formula_weight_word(value):(int)lround(value);settings.program.slots[slot]=copied;}
    else {self.formulaClipboardMode=settings.program.mode;self.formulaClipboard=[NSData dataWithBytes:&settings.program.slots[slot] length:sizeof(FormulaSlot)];}
    self.formulaSettings=settings;[self populateFormulaWindow];self.formulaStatus.stringValue=sender.tag?@"Formula slot pasted.":@"Formula slot copied.";
}
- (void)updateFormulaMoveButtons {
    NSInteger slot=[self.formulaTabs indexOfTabViewItem:self.formulaTabs.selectedTabViewItem];
    self.formulaMoveLeft.enabled=!self.calculating&&slot>0;
    self.formulaMoveRight.enabled=!self.calculating&&slot>=0&&slot<self.formulaTabs.numberOfTabViewItems-1;
}
- (void)tabView:(NSTabView *)tabView didSelectTabViewItem:(NSTabViewItem *)item {
    (void)item;if(tabView==self.formulaTabs){[self updateFormulaMoveButtons];[self syncFormulaInfo];}
    if(tabView==self.navigatorRotationTab.tabView)self.navigatorTabControl.selectedSegment=[tabView indexOfTabViewItem:item];
}
- (void)moveFormulaSlot:(NSButton *)sender {
    if(self.calculating)return;
    NSInteger slot=[self.formulaTabs indexOfTabViewItem:self.formulaTabs.selectedTabViewItem],destination=slot+sender.tag;
    if(slot<0||destination<0||destination>=self.formulaTabs.numberOfTabViewItems)return;
    [self.formulasWindow makeFirstResponder:nil];RenderOptions settings=self.formulaSettings;
    if(![self readFormulaWindow:&settings])return;
    settings.iterations=self.formulaGlobalFields[1].intValue;
    FormulaSlot displaced=settings.program.slots[destination];settings.program.slots[destination]=settings.program.slots[slot];settings.program.slots[slot]=displaced;
    self.formulaSettings=settings;[self populateFormulaWindow];[self.formulaTabs selectTabViewItemAtIndex:destination];
}
- (void)resetFormulaProgram:(id)sender {
    (void)sender;RenderOptions settings=self.formulaSettings;settings.program=defaultFormulaProgram();settings.program_override=1;settings.iterations=60;self.formulaSettings=settings;[self populateFormulaWindow];
}
- (BOOL)readFormulaWindow:(RenderOptions *)options {
    [self refreshFormulaTabLabels];
    FormulaProgram p=options->program;BOOL interpolate=self.formulaMode.indexOfSelectedItem==1;
    for(int i=0;i<FORMULA_UI_SLOTS;i++){if(interpolate&&i>=2){p.slots[i].count=0;continue;}FormulaSlot f=p.slots[i];f.kind=formulaSelectedKind(self.formulaMenus[i]);if(f.kind==-1){p.slots[i]=formula_slot_default(-1);continue;}f.power=self.powerPopups[i].selectedItem.title.intValue;double values[5];NSArray *fields=@[self.zMultiplierFields[i],self.boxFields[i][0],self.boxFields[i][1],self.boxFields[i][2],self.formulaCountFields[i]];
        for(int j=0;j<5;j++){NSScanner *scanner=[NSScanner scannerWithString:numericInputString(fields[j])];if(![scanner scanDouble:&values[j]]||!scanner.isAtEnd||!isfinite(values[j])){self.formulaStatus.stringValue=@"Enter finite numbers in all formula fields.";return NO;}}
        if((!usesGenericFormulaEditor(f.kind)&&(fabs(values[0])>100||fabs(values[1])>100||fabs(values[2])>100||fabs(values[3])>100))||values[4]<0||values[4]>10000||(!interpolate&&values[4]!=floor(values[4]))){self.formulaStatus.stringValue=@"Counts: 0–10000; Z multiplier/Scale/Fold: −100..100; Min R: −100..100.";return NO;}
        f.z_multiplier=values[0];f.scale=values[1];f.min_radius=values[2];f.fold=values[3];f.count=interpolate?formula_weight_word(values[4]):(int)values[4];
        if(usesGenericFormulaEditor(f.kind))for(int j=0;j<formula_parameter_count(f.kind);j++){NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.randFormulaFields[i][j])];double v;FormulaParameter uiSpec=formulaUIParameter(f.kind,j);const FormulaParameter *spec=&uiSpec;if(![scanner scanDouble:&v]||!scanner.isAtEnd||!isfinite(v)||v<spec->minimum||v>spec->maximum||(spec->integer&&floor(v)!=v)){self.formulaStatus.stringValue=[NSString stringWithFormat:@"%s: enter %@%.9g..%.9g.",spec->name,spec->integer?@"an integer ":@"",spec->minimum,spec->maximum];return NO;}formula_slot_set_value(&f,j,v);}
        p.slots[i]=f;
    }
    double values[6],minimum[]={0,1,1.000001,1,1e-12,1.000001},maximum[]={10000,10000,1e10,10000,1e6,100};
    for(int i=0;i<6;i++){NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.formulaGlobalFields[i])];if(![scanner scanDouble:&values[i]]||!scanner.isAtEnd||!isfinite(values[i])||values[i]<minimum[i]||values[i]>maximum[i]||((i==0||i==1||i==3)&&floor(values[i])!=values[i])){self.formulaStatus.stringValue=@"Check iteration limits, bailout (>1), smooth distance (>0) and numerical formula power (>1).";return NO;}}
    p.mode=(int)self.formulaMode.indexOfSelectedItem;p.repeat_from=interpolate?0:(int)self.repeatPopup.indexOfSelectedItem;p.render_mode=(int)self.formulaRenderMode.indexOfSelectedItem;p.combine=(int)self.formulaCombine.indexOfSelectedItem;p.split=(int)self.formulaSplit.indexOfSelectedItem+1;p.repeat2=(int)self.formulaRepeat2.indexOfSelectedItem;p.min_iterations=(int)values[0];p.bailout=values[2];p.max_iterations2=(int)values[3];p.smooth=values[4];p.formula_power=values[5];p.numerical_de=self.formulaNumerical.state==NSControlStateValueOn;
    options->iterations=(int)values[1];options->program_override=1;options->program=p;return YES;
}
- (void)refreshFormulaTabLabels {
    CGFloat width=24;
    for(NSUInteger i=0;i<(NSUInteger)self.formulaTabs.numberOfTabViewItems;i++){
        NSString *name=[NSString stringWithUTF8String:formula_name(formulaSelectedKind(self.formulaMenus[i]))];
        NSString *label=[NSString stringWithFormat:@"%lu%@%@%@",(unsigned long)i+1,self.formulaCountFields[i].doubleValue>0?@"*":@"",name.length?@" ":@"",name];
        [self.formulaTabs tabViewItemAtIndex:i].label=label;
        width+=ceil([label sizeWithAttributes:@{NSFontAttributeName:self.formulaTabs.font}].width)+32;
    }
    if(self.populatingFormulas)return;
    NSScreen *screen=self.formulasWindow.screen?:self.window.screen?:NSScreen.mainScreen;
    CGFloat available=screen?screen.visibleFrame.size.width:1200;
    width=MIN(MAX(640,width),available);
    NSRect frame=self.formulasWindow.frame;frame.size.width=width;
    if(screen)frame.origin.x=MAX(NSMinX(screen.visibleFrame),MIN(frame.origin.x,NSMaxX(screen.visibleFrame)-width));
    [self.formulasWindow setFrame:frame display:YES];
    NSRect tabsFrame=self.formulaTabs.frame;tabsFrame.size.width=width-24;self.formulaTabs.frame=tabsFrame;
}
- (void)addFormulaSearch:(NSPopUpButton *)menu slot:(NSInteger)slot {
    NSMenuItem *search=[[NSMenuItem alloc]initWithTitle:@"Search…" action:@selector(searchFormulas:) keyEquivalent:@""];search.target=self;search.representedObject=@(slot);[menu.menu insertItem:search atIndex:1];
    NSMenuItem *clear=[[NSMenuItem alloc]initWithTitle:@"Clear" action:@selector(clearFormulaSlot:) keyEquivalent:@""];clear.target=self;clear.representedObject=@(slot);[menu.menu insertItem:clear atIndex:2];
}
- (void)clearFormulaSlot:(NSMenuItem *)item {
    if(self.calculating)return;
    NSInteger slot=[item.representedObject integerValue];
    FormulaSlot empty=formula_slot_default(-1);
    if(slot<0){
        if(![self readNavigatorFormulaValues])return;
        RenderOptions settings=self.navigatorFormulaSettings;settings.program.slots[self.navigatorFormulaSlot]=empty;settings.program_override=1;self.navigatorFormulaSettings=settings;
        [self populateNavigatorFormulaValues];[self requestNavigatorPreviewAdaptingDistance:NO];
    }else{
        if(slot>=FORMULA_UI_SLOTS)return;
        [self.formulasWindow makeFirstResponder:nil];RenderOptions settings=self.formulaSettings;
        if(![self readFormulaWindow:&settings])return;
        settings.iterations=self.formulaGlobalFields[1].intValue;settings.program.slots[slot]=empty;settings.program_override=1;self.formulaSettings=settings;
        [self populateFormulaWindow];self.formulaStatus.stringValue=@"Formula slot cleared.";
    }
}
- (void)searchFormulas:(NSMenuItem *)item {
    if(self.calculating)return;NSInteger slot=[item.representedObject integerValue];BOOL navigator=slot<0;if(navigator)slot=self.navigatorFormulaSlot;
    NSWindow *parent=navigator?self.navigatorWindow:self.formulasWindow;if(parent.attachedSheet)return;
    self.formulaSearch=[FormulaSearchController new];__weak AppDelegate *owner=self;
    self.formulaSearch.choose=^(int kind){AppDelegate *app=owner;if(!app||app.calculating)return;NSMenuItem *choice=[[NSMenuItem alloc]initWithTitle:@"" action:nil keyEquivalent:@""];choice.tag=kind;choice.representedObject=@(slot);if(navigator){if(app.navigatorFormulaSlot!=slot)return;[app navigatorFormulaTypeChosen:choice];}else [app formulaMenuChosen:choice];};
    [parent beginSheet:self.formulaSearch.window completionHandler:nil];[self.formulaSearch.window makeFirstResponder:self.formulaSearch.query];
}
- (void)formulaMenuChosen:(NSMenuItem *)item {
    NSInteger slot=[item.representedObject integerValue];if(slot<0||slot>=(NSInteger)self.formulaMenus.count)return;
    NSPopUpButton *menu=self.formulaMenus[slot];formulaSelectKind(menu,(int)item.tag);[self formulaSelectionChanged:menu];
}
- (void)syncFormulaInfo {
    BOOL info=self.formulaInfoButton.state==NSControlStateValueOn;
    for(NSUInteger slot=0;slot<self.formulaInfoViews.count;slot++){
        NSScrollView *scroll=self.formulaInfoViews[slot];scroll.hidden=!info;
        if(!info)continue;
        for(NSView *view in scroll.superview.subviews)if(view!=scroll&&view!=self.formulaMenus[slot])view.hidden=YES;
        NSTextView *text=(NSTextView *)scroll.documentView;NSString *description=formulaInformationText(formulaSelectedKind(self.formulaMenus[slot]));if(![text.string isEqual:description]){text.string=description;[text scrollRangeToVisible:NSMakeRange(0,0)];}
    }
}
- (void)toggleFormulaInfo:(id)sender {
    (void)sender;[self.formulasWindow makeFirstResponder:nil];
    if(self.formulaInfoButton.state==NSControlStateValueOff){BOOL populating=self.populatingFormulas;self.populatingFormulas=YES;for(NSUInteger slot=0;slot<self.formulaInfoViews.count;slot++){for(NSView *view in self.formulaInfoViews[slot].superview.subviews)view.hidden=NO;[self formulaSelectionChanged:self.formulaMenus[slot]];}self.populatingFormulas=populating;}
    [self syncFormulaInfo];
}
- (void)formulaSelectionChanged:(NSPopUpButton *)menu {
    NSInteger slot=menu.tag;int kind=formulaSelectedKind(menu);BOOL rand=usesGenericFormulaEditor(kind);
    self.integerGroups[slot].hidden=kind!=0;self.boxGroups[slot].hidden=kind!=4&&kind!=100;self.randFormulaGroups[slot].hidden=!rand;
    if(rand){
        NSScrollView *scroll=(NSScrollView *)self.randFormulaGroups[slot];NSView *document=scroll.documentView;
        NSString *kindID=[NSString stringWithFormat:@"%d",kind];BOOL changed=![document.identifier isEqual:kindID];document.identifier=kindID;FormulaSlot defaults=formula_slot_default(kind);int count=formula_parameter_count(kind);
        for(int j=0;j<16;j++){NSTextField *field=self.randFormulaFields[slot][j];NSTextField *label=(NSTextField *)[document viewWithTag:100+j];BOOL hidden=j>=count;field.hidden=hidden;label.hidden=hidden;if(hidden)continue;
            FormulaParameter uiSpec=formulaUIParameter(kind,j);const FormulaParameter *spec=&uiSpec;numericIntegerField(field,spec->integer);label.stringValue=[NSString stringWithUTF8String:spec->name];field.accessibilityLabel=[NSString stringWithFormat:@"Formula %ld %@",(long)slot+1,label.stringValue];
            field.toolTip=[NSString stringWithFormat:@"%@%.9g to %.9g. Default %.9g.",spec->integer?@"Integer ":@"",spec->minimum,spec->maximum,spec->default_value];if(changed)field.stringValue=[NSString stringWithFormat:@"%.17g",formula_slot_value(defaults,j)];
        }
        NSRect frame=document.frame;frame.size.height=MAX(210,count*30+8);document.frame=frame;
        if(changed)[scroll.contentView scrollToPoint:NSZeroPoint];
    }
    for(NSView *view in self.boxGroups[slot].subviews)if(view.frame.origin.y>=76)view.hidden=kind==100;
    NSTextField *count=self.formulaCountFields[slot];NSView *content=count.superview;NSRect f=count.frame;f.origin.y=rand?270:164;count.frame=f;
    for(NSView *view in content.subviews)if([view isKindOfClass:NSTextField.class]&&![(NSTextField *)view isEditable]){NSTextField *label=(NSTextField *)view;NSRect frame=view.frame;if((label.tag==90))frame.origin.y=rand?274:168;else if([label.stringValue hasPrefix:@"Zero disables"]){frame.origin.y=rand?304:208;label.hidden=rand;}view.frame=frame;}
    if((kind==100||kind==102||kind==6)&&self.formulaGlobalFields.count>2&&[self.formulaGlobalFields[2].stringValue isEqual:@"16"])self.formulaGlobalFields[2].stringValue=@"1024";
    if(!self.populatingFormulas&&formula_catalog_category(kind)>=0&&self.formulaGlobalFields.count>2&&[self.formulaGlobalFields[2].stringValue isEqual:@"16"]){double bailout=formula_catalog_bailout(kind);if(bailout>1&&bailout<=1e10)self.formulaGlobalFields[2].stringValue=[NSString stringWithFormat:@"%.17g",bailout];}
    count.hidden=kind==-1;
    for(NSView *view in content.subviews)if([view isKindOfClass:NSTextField.class]&&![(NSTextField *)view isEditable]){NSString *text=[(NSTextField *)view stringValue];if(view.tag==90||[text hasPrefix:@"Zero disables"])view.hidden=kind==-1||([text hasPrefix:@"Zero disables"]&&rand);}
    if(!self.populatingFormulas&&kind!=-1&&count.doubleValue==0)count.stringValue=@"1";
    [self refreshFormulaTabLabels];[self syncFormulaInfo];
}
- (void)setCalculating:(BOOL)busy {
    if(!busy)self.renderProgressPie.hidden=YES;
    if(busy)[self stopNavigatorExplore];self.navigatorExploreButton.enabled=!busy;
    if(busy&&self.mutagenBusy)[self stopMutagen];self.mutagenButton.enabled=!busy;
    _calculating=busy;[self syncMutagenControls];for(NSButton *button in self.colorFavoriteButtons)button.enabled=!busy&&(button.tag<5||[self.customColorFavorites[button.tag-5] length]>0);self.addColorFavoriteButton.enabled=!busy&&[self.customColorFavorites containsObject:NSData.data];[self updateHistogramZoom];[self populateNavigatorCutting];[self populateNavigatorRotation];[self syncNavigatorExploreArrows];self.stepcountField.enabled=!busy;for(NSStepper *step in self.calculationSteppers)step.enabled=!busy;[self syncCalculationSteppers];[self updateFormulaMoveButtons];[self syncAnimationProcessing];
    for(NSArray<NSTextField *> *fields in self.randFormulaFields)for(NSTextField *field in fields)field.enabled=!busy;
    for(NSPopUpButton *power in self.powerPopups)power.enabled=!busy;
    for(NSPopUpButton *menu in self.formulaMenus)menu.enabled=!busy;
    for(NSArray<NSTextField *> *slot in self.boxFields)for(NSTextField *field in slot)field.enabled=!busy;
    for(NSTextField *field in self.zMultiplierFields)field.enabled=!busy;
    for(NSTextField *field in self.formulaCountFields)field.enabled=!busy;
    self.repeatPopup.enabled=!busy&&self.formulaMode.indexOfSelectedItem!=1;
    for(NSTextField *field in self.objectFields)field.enabled=!busy;
    for(NSTextField *field in self.palettePositions)field.enabled=!busy;
    for(NSSlider *slider in self.objectSliders)slider.enabled=!busy;
    for(NSSlider *slider in self.cuttingColorSliders)slider.enabled=!busy;for(NSTextField *field in self.cuttingColorFields)field.enabled=!busy;self.cuttingBar.enabled=!busy;
    [self syncLightSliders];
    for(NSButton *button in self.shadowLightChecks)button.enabled=!busy;
    for(NSButton *button in self.shadowAutoChecks)button.enabled=!busy;
    for(NSButton *button in self.postButtons)button.enabled=!busy;
    for(NSTextField *field in self.shadowFields)field.enabled=!busy;
    for(NSSlider *slider in self.ambientShadowSliders)slider.enabled=!busy;
    self.softShadowCheck.enabled=!busy;self.cosineShadowCheck.enabled=!busy;self.ambientMethod.enabled=!busy;
    self.fitColorsButton.enabled=!busy&&self.colorFitValid;
    for(NSArray *controls in self.lightControls)for(NSControl *control in controls)control.enabled=!busy;
    [self syncLightSliders];
    for(NSColorWell *well in self.diffuseWells)well.enabled=!busy;
    for(NSColorWell *well in self.specularWells)well.enabled=!busy;
    [self syncLightingUndoButton];self.resetLightingButton.enabled=!busy;self.keepLightsCheck.enabled=!busy;self.openLightingButton.enabled=!busy;self.saveLightingButton.enabled=!busy;self.gammaSlider.enabled=!busy;self.cyclingCheck.enabled=!busy;self.interpolationCheck.enabled=!busy;self.orbitCheck.enabled=!busy;
    self.diffuseBar.enabled=!busy;self.colorDiffuseBar.enabled=!busy;self.colorSpecularBar.enabled=!busy;
    self.objectColorsMenu.enabled=!busy;self.colorStopMenu.enabled=!busy;self.colorPosition.enabled=!busy;
    self.colorDiffuseWell.enabled=!busy;self.colorSpecularWell.enabled=!busy;
    self.glueColors.enabled=!busy;self.updateColors.enabled=!busy;
    for(NSColorWell *well in self.randomReferences)well.enabled=!busy;
    for(NSTextField *field in self.randomAmounts)field.enabled=!busy;
    for(NSSlider *slider in self.randomAmountSliders)slider.enabled=!busy;
    for(NSButton *button in self.randomButtons)button.enabled=!busy;
    for(NSControl *control in self.fogControls)control.enabled=!busy;
    if(!busy)[self syncFogMode];
    for(NSTextField *field in self.ambientFields)field.enabled=!busy;
    for(NSSlider *slider in self.ambientSliders)slider.enabled=!busy;
    for(NSColorWell *well in self.ambientWells)well.enabled=!busy;
    self.ambientRelative.enabled=!busy;self.ambientFarFog.enabled=!busy;self.ambientGradient.enabled=!busy;
    self.objectMapEnabled.enabled=!busy;self.objectMapNumber.enabled=!busy;[self updateObjectColoringMode];
    self.objectMapMenu.enabled=!busy;self.objectMapMode.enabled=!busy;self.objectMapCombine.enabled=!busy;self.coloringMode.enabled=!busy;
    for(NSTextField *field in self.objectMapFields)field.enabled=!busy;
    for(NSSlider *slider in self.objectMapSliders)slider.enabled=!busy;
    self.internalGammaCheck.enabled=!busy;self.applyLightingButton.enabled=!busy;[self syncBackPicture];
    self.navigatorFarField.enabled=!busy;self.navigatorFOVField.enabled=!busy;self.fixedZoomCheck.enabled=!busy;
    self.navigatorJuliaMode.enabled=!busy;self.navigatorJuliaSphericalCheck.enabled=!busy;
    for(NSTextField *field in self.navigatorJuliaFields)field.enabled=!busy;
    for(NSSlider *slider in self.navigatorJuliaSliders)slider.enabled=!busy;
    [self syncNavigatorFormulaArrows];
    self.navigatorFormulaTypeMenu.enabled=!busy;self.navigatorFormulaMenu.enabled=!busy;self.navigatorIterationField.enabled=!busy;self.navigatorIterationStepper.enabled=!busy;
    for(NSTextField *field in self.navigatorFormulaFields)field.enabled=!busy;
    for(NSSlider *slider in self.navigatorFormulaSliders)slider.enabled=!busy;
    self.navigatorAddAnimationButton.enabled=!busy&&self.formulaKnown&&!self.navigatorAddPending;
    self.navigatorResetPosButton.enabled=!busy&&self.formulaKnown;self.applyNavigatorButton.enabled=!busy&&self.formulaKnown;self.navigatorResetValueButton.enabled=!busy&&self.navigatorResetTarget!=nil;
    self.formulaMode.enabled=!busy;self.formulaRenderMode.enabled=!busy;self.formulaNumerical.enabled=!busy;
    for(NSTextField *field in self.formulaGlobalFields)field.enabled=!busy;
    if(!busy&&self.formulasWindow)[self formulaModeChanged:nil];else{self.formulaCombine.enabled=NO;self.formulaSplit.enabled=NO;self.formulaRepeat2.enabled=NO;}
    self.applyFormulaButton.enabled=!busy;
    self.openM3IButton.enabled=!busy;self.clipboardButton.enabled=!busy;self.saveClipboardButton.enabled=!busy;self.pngButton.enabled=!busy&&self.completedRender!=nil;
    self.saveButton.enabled=!busy&&self.formulaKnown;self.keepAspectCheck.enabled=!busy;self.scaleDECheck.enabled=!busy;
    self.oversamplingMenu.enabled=!busy;self.imageSizeStepper.enabled=!busy;[self updateActualSizeAvailability];
    if(busy)[self pauseAnimationPlayback];self.animationPause.enabled=!busy&&self.animationPlaybackFrames.count>0;
    for(NSControl *control in self.reflectionControls)control.enabled=!busy;
    [self syncTransparencyControls];
    self.animationButton.enabled=!busy;for(NSControl *control in self.animationControls)control.enabled=!busy;self.animationTable.enabled=!busy;
    NSButton *animationRenderButtons[]={self.animationRenderFrameButton,self.animationRenderPreviewButton,self.animationExportButton};NSString *animationRenderTitles[]={@"Render Current Frame",@"Render preview",@"Start Render"};
    for(int i=0;i<3;i++){BOOL active=busy&&self.animationRunning&&self.animationRenderKind==i+1;animationRenderButtons[i].title=active?(i==1?@"Stop Preview":@"Stop Render"):animationRenderTitles[i];animationRenderButtons[i].enabled=!busy||(active&&!self.animationStopRequested);}
    self.historyMenu.enabled=!busy;self.renderButton.enabled=!busy;self.renderButton.hidden=busy;self.stopButton.hidden=!busy;self.stopButton.enabled=busy&&self.mainCancelToken!=NULL;
    for(NSControl *control in self.positionControls)control.enabled=!busy;
    for(NSControl *control in self.dofControls)control.enabled=!busy;
    if(busy){self.imageView.pickingLight=NO;self.placingLight=-1;self.focusPicking=0;}
    self.cpuOnlyCheck.enabled=!busy;
    for(NSTextField *field in self.calculationFields)field.enabled=!busy;
    for(NSTextField *field in self.positionFields)field.enabled=!busy;
    self.positionCopyButton.enabled=!busy;self.positionPasteButton.enabled=!busy&&self.positionPasteValues!=nil;
}
- (void)calculate:(id)sender {
    if(self.parametersPendingRender&&sender!=self.renderButton){self.statusLabel.stringValue=@"Adjust image size, then press Render.";return;}
    (void)sender;if(self.lightingSliderTracking)return;
    if(!self.renderButton.enabled)return;
    RenderOptions options;if(![self readMainSettings:&options sender:sender])return;
    if(self.applyingNavigator){
        // Apply transfers the scene before rendering, so Stop only cancels the image.
        self.formulaSettings=options;
        [self populateFormulaWindow];
        [self populatePosition];
    }
    self.parametersPendingRender=NO;[self beginRenderPath:self.currentPath options:options];
}
- (BOOL)readMainSettings:(RenderOptions *)result sender:(id)sender {
    double values[6];
    for(NSUInteger i=0;i<6;i++) {
        NSScanner *scanner=[NSScanner scannerWithString:numericInputString(self.calculationFields[i])];
        if(![scanner scanDouble:&values[i]]||!scanner.isAtEnd||!isfinite(values[i])) {
            self.statusLabel.stringValue=@"Enter a valid number in every field.";return NO;
        }
    }
    if(values[0]<16||values[0]>RENDER_MAX_DIMENSION||values[1]<16||values[1]>RENDER_MAX_DIMENSION||
       values[2]<0||values[2]>256||values[3]<0||values[3]>15||
       values[4]<1e-6||values[4]>100||values[5]<1e-6||values[5]>1||
       values[0]!=floor(values[0])||values[1]!=floor(values[1])||
       values[2]!=floor(values[2])||values[3]!=floor(values[3])) {
        self.statusLabel.stringValue=@"Width/height: 16–16384; threads: 0–256; smooth normals: 0–15; DE stop: 0.000001–100; raystep: 0.000001–1.";return NO;
    }
    int stepcount=0;if(!animationInteger(numericInputString(self.stepcountField),0,31,&stepcount)){self.statusLabel.stringValue=@"Stepcount must be an integer 0–31.";return NO;}
    RenderOptions options=self.formulaSettings;options.reuse_surface=sender!=self.renderButton;
    options.stepcount_override=1;options.stepcount=stepcount;
    if(self.formulasWindow&&!self.applyingNavigator&&![self readFormulaWindow:&options])return NO;
    if(self.lightingWindow) {
        ObjectLighting object=options.object;
        if(![self readObjectLighting:&object]){self.statusLabel.stringValue=@"Check the Object lighting settings.";return NO;}
        if(![self readLights:&options]){self.statusLabel.stringValue=@"Check the light settings.";return NO;}
        options.object_override=1;options.object=object;
    }
    int n=(int)self.oversamplingMenu.indexOfSelectedItem+1;
    if(values[0]*n>RENDER_MAX_DIMENSION||values[1]*n>RENDER_MAX_DIMENSION){self.statusLabel.stringValue=@"Oversampled width and height must each be at most 16384 pixels.";return NO;}
    options.oversampling=n;options.viewing=n;
    options.size_flags=(self.keepAspectCheck.state==NSControlStateValueOn?1:0)|(self.scaleDECheck.state==NSControlStateValueOn?2:0);
    options.width=(int)values[0]*n;options.height=(int)values[1]*n;options.threads=(int)values[2];
    options.normals_override=1;options.normal_smoothing=(int)values[3];
    double storedDE=self.formulaSettings.de_stop/MAX(1,self.formulaSettings.oversampling);
    options.de_stop=unchangedFieldValue(self.calculationFields[4],values[4],storedDE,@"%.17g")*n;
    options.ray_step=unchangedFieldValue(self.calculationFields[5],values[5],self.formulaSettings.ray_step,@"%.17g");
    if(options.de_stop>100){self.statusLabel.stringValue=@"Oversampled DE stop exceeds 100; reduce DE stop or oversampling.";return NO;}
    if(![self readShadowSettings:&options]||![self readDepthFog:&options]||![self readAmbientLighting:&options]||![self readDepthOfField:&options]||![self readReflections:&options])return NO;
    if(self.applyingNavigator){options=[self applyNavigatorFormulas:options];options.camera_override=1;options.camera=self.navigatorCamera;}
    if(options.program_override){options.formula_override=0;options.sequence_override=0;}
    if(!self.applyingNavigator&&![self readPosition:&options])return NO;
    *result=options;return YES;
}
- (void)openM3I:(id)sender {
    (void)sender;
    [self openSceneInDirectory:nil];
}
- (void)openSceneInDirectory:(NSURL *)directory {
    if(self.calculating)return;
    NSOpenPanel *panel=[NSOpenPanel openPanel];panel.allowedFileTypes=@[@"m3i",@"msi"];panel.allowsMultipleSelection=NO;panel.canChooseDirectories=NO;panel.canChooseFiles=YES;panel.prompt=@"Open";
    if(directory)panel.directoryURL=directory;
    else restoreDialogLocation(panel,NO,@"m3i",nil);
    SceneOpenPreview *preview=[SceneOpenPreview new];panel.delegate=preview;panel.accessoryView=preview.view;panel.accessoryViewDisclosed=YES;
    __block NSURL *folderToAuthorize=nil;
    __weak NSOpenPanel *weakPanel=panel;
    if(appSandboxBuild())preview.requestFolderAccess=^(NSURL *folder){
        folderToAuthorize=folder;
        [weakPanel cancel:nil];
    };
    [panel beginSheetModalForWindow:self.window completionHandler:^(NSModalResponse response){
        preview.generation++;
        panel.delegate=nil;
        if(response==NSModalResponseOK){rememberDialogURL(panel.URL,NO);[self renderPath:panel.URL.path];}
        else if(folderToAuthorize)dispatch_async(dispatch_get_main_queue(),^{[self authorizeScenePreviewFolder:folderToAuthorize];});
    }];
}
- (void)authorizeScenePreviewFolder:(NSURL *)directory {
    NSOpenPanel *panel=[NSOpenPanel openPanel];
    panel.accessoryView=nil;
    panel.directoryURL=directory;
    panel.canChooseDirectories=YES;
    panel.canChooseFiles=NO;
    panel.allowsMultipleSelection=NO;
    panel.canCreateDirectories=NO;
    panel.prompt=@"Allow Previews";
    panel.message=@"Choose the folder containing the scenes you want to preview.";
    [panel beginSheetModalForWindow:self.window completionHandler:^(NSModalResponse response){
        NSURL *selected=response==NSModalResponseOK?panel.URL:nil;
        if(selected)retainUserFileSelection(selected);
        dispatch_async(dispatch_get_main_queue(),^{[self openSceneInDirectory:selected?:directory];});
    }];
}
- (void)renderPath:(NSString *)path {
    if(path.length)retainUserFileSelection([NSURL fileURLWithPath:path]);
    self.parametersPendingRender=NO;
    [self ensureWindow];
    if(path.length&&[@[@"m3i",@"msi",@"m3p"] containsObject:path.pathExtension.lowercaseString]&&![self.clipboardScenes containsObject:path]&&![path.stringByDeletingLastPathComponent isEqual:self.renderHistory.directory]&&![self.animationTemporarySources containsObject:path])rememberDialogURL([NSURL fileURLWithPath:path],NO);
    if(!path.length){[self beginRenderPath:path options:(RenderOptions){.width=self.renderWidth,.height=self.renderHeight,.threads=self.threads}];return;}
    render_cancel(self.mainCancelToken);render_cancel(self.navigatorCancelToken);
    NSUInteger generation=++self.generation;[self setCalculating:YES];self.statusLabel.stringValue=@"Loading parameters…";
    dispatch_async(self.renderQueue,^{
        RenderOptions settings;char error[512];BOOL ok=read_scene_settings(path.fileSystemRepresentation,&settings,error);
        NSString *message=ok?nil:[NSString stringWithUTF8String:error];
        dispatch_async(dispatch_get_main_queue(),^{
            if(generation!=self.generation)return;
            [self setCalculating:NO];if(!ok){[self showFileError:@"Could not open model" message:message];return;}
            RenderOptions loaded=settings;if(self.renderWidth)loaded.width=self.renderWidth;if(self.renderHeight)loaded.height=self.renderHeight;if(self.threads)loaded.threads=self.threads;
            [self loadParameterSettings:loaded path:path source:path.lastPathComponent];
        });
    });
}
- (void)stopRender:(id)sender {
    (void)sender;if(!self.mainCancelToken)return;
    render_cancel(self.mainCancelToken);self.stopButton.enabled=NO;self.statusLabel.stringValue=@"Stopping render…";
    if(self.animationRunning){self.animationStopRequested=YES;self.animationRenderFrameButton.enabled=NO;self.animationRenderPreviewButton.enabled=NO;self.animationExportButton.enabled=NO;self.animationStatus.stringValue=@"Stopping render…";}
}
- (void)beginRenderPath:(NSString *)path options:(RenderOptions)options {
    self.glowCacheReady=NO;self.glowPreviewPending=NO;
    BOOL appliedNavigator=self.applyingNavigator;
    BOOL omitReflections=self.lightingRepaintRequested&&!self.gammaRepaint;
    // Capture the reset scope before the action clears its synchronous flags.
    BOOL postProcessOnly=self.postProcessOnce||[self resettingPostProcess];
    BOOL preserveNavigator=postProcessOnly||self.lightingRepaintRequested||self.preserveNavigatorForLighting;
    render_cancel(self.mainCancelToken);self.animationRunning=NO;self.animationRenderKind=0;self.animationStopRequested=NO;
    RenderCancelToken *token=render_cancel_create();self.mainCancelToken=token;options.cancel_token=token;
    if(!postProcessOnly){
        render_cancel(self.navigatorCancelToken);self.navigatorGeneration++;self.previewPending=NO;
    }
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(finishLightingSlider) object:nil];
    self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;
    [self setCalculating:YES];self.renderProgressPie.indeterminate=NO;self.renderProgressPie.fraction=0;self.renderProgressPie.hidden=NO;self.statusLabel.stringValue=@"Geometry — 0:00";
    self.formulaStatus.stringValue=@"Rendering…";self.lightingStatus.stringValue=@"Rendering…";
    NSUInteger generation=postProcessOnly?self.generation:++self.generation;
    NSString *savePath=self.pendingSavePath;self.pendingSavePath=nil;
    NSString *name=savePath?savePath.lastPathComponent:([path.stringByDeletingLastPathComponent isEqual:self.renderHistory.directory]?@"History parameters":[self.clipboardScenes containsObject:path]?@"Clipboard parameters":path?path.lastPathComponent:@"Default Integer Power");
    self.window.title=[NSString stringWithFormat:@"%@ — %@",APP_TITLE,name];
    [self.mainProgressTimer invalidate];__weak AppDelegate *progressOwner=self;
    NSTimeInterval renderStarted=NSProcessInfo.processInfo.systemUptime;
    self.mainProgressTimer=[NSTimer timerWithTimeInterval:.1 repeats:YES block:^(NSTimer *timer){AppDelegate *owner=progressOwner;if(!owner||owner.generation!=generation||owner.mainCancelToken!=token){[timer invalidate];return;}int percent=render_progress_percent(token);double elapsed=NSProcessInfo.processInfo.systemUptime-renderStarted;owner.renderProgressPie.indeterminate=percent<0;owner.renderProgressPie.rotation=90-elapsed*240;owner.renderProgressPie.fraction=percent<0?0:percent/100.;if(owner.stopButton.enabled)owner.statusLabel.stringValue=[NSString stringWithFormat:@"%s%@ — %ld:%02ld",render_progress_stage(token),percent<0?@"…":[NSString stringWithFormat:@" %d%%",percent],(long)(elapsed/60),(long)elapsed%60];}];[[NSRunLoop mainRunLoop]addTimer:self.mainProgressTimer forMode:NSRunLoopCommonModes];
    dispatch_async(self.renderQueue, ^{
        @autoreleasepool {
            unsigned char *sharp=NULL;RenderOptions rendering=options;if(omitReflections){rendering.reflections_override=1;rendering.reflections.enabled=0;}RenderResult result=render_scene_capturing_sharp(path.fileSystemRepresentation,rendering,savePath.fileSystemRepresentation,&sharp);if(omitReflections)result.settings.reflections=options.reflections;
            BOOL glowReady=result.rgba&&!omitReflections&&result.transmission_cached;
            rendering.cancel_token=NULL;
            NSString *historyWarning=nil;
            if(result.rgba&&!result.cancelled)[self.renderHistory record:result source:path error:&historyWarning];
            dispatch_async(dispatch_get_main_queue(), ^{
                if(self.mainCancelToken==token){[self.mainProgressTimer invalidate];self.mainProgressTimer=nil;self.mainCancelToken=NULL;}render_cancel_destroy(token);
                if(generation!=self.generation){free(result.rgba);free(sharp);return;}
                [self setCalculating:NO];
                if(result.cancelled){self.statusLabel.stringValue=appliedNavigator?@"Render stopped. Navigator scene retained. Press Render to update the image.":@"Render stopped. Previous image retained.";self.formulaStatus.stringValue=@"Render stopped.";self.lightingStatus.stringValue=@"Render stopped.";return;}
                if(!result.rgba) {
                    NSString *error=[NSString stringWithUTF8String:result.error];
                    if(!error)error=@"Render failed";
                    self.statusLabel.stringValue=error;
                    self.formulaStatus.stringValue=error;self.lightingStatus.stringValue=error;
                    NSLog(@"Cannot render %@: %@",name,error);
                    [self showFileError:@"Could not render .m3i" message:error];
                    self.window.title=[NSString stringWithFormat:@"%@ — %@",APP_TITLE,name];
                    return;
                }
                NSImage *image=imageForRender(result,MAX(1,result.settings.viewing));
                RenderResult sharpResult=result;sharpResult.rgba=sharp;self.sharpRenderImage=sharp?imageForRender(sharpResult,MAX(1,result.settings.viewing)):nil;free(sharp);free(result.rgba);
                if(!image){self.statusLabel.stringValue=@"Not enough memory to display image";return;}
                [self displayRenderInfo:result];
                self.imageView.image=image;self.completedRender=(NSBitmapImageRep *)image.representations.firstObject;self.pngButton.enabled=YES;
                self.currentPath=savePath?savePath:path;
                RenderOptions settings=result.settings;
                self.parametersPendingRender=NO;self.formulaKnown=YES;self.formulaSettings=settings;self.glowCacheReady=glowReady;
                self.glowCacheOptions=rendering;
                self.glowCacheSourcePath=glowReady?path:nil;
                [self recordLightingRepaint:settings];if(!preserveNavigator)self.navigatorLocalDistance=result.local_distance;
                self.applyNavigatorButton.enabled=YES;
                if(!postProcessOnly)[self refreshNavigatorAfterMainRenderPreservingEdits:preserveNavigator];
                self.renderColorHistograms=[NSData dataWithBytes:result.color_histogram length:sizeof result.color_histogram];[self updateColorHistograms];
                self.colorFitValid=result.color_fit_valid;
                self.fitStart=result.color_fit[0][0];self.fitEnd=result.color_fit[0][1];
                self.trapStart=result.color_fit[1][0];self.trapEnd=result.color_fit[1][1];
                [self populateObjectLighting];[self populateShadowSettings];
                [self populateFormulaWindow];
                int n=settings.oversampling;[self.oversamplingMenu selectItemAtIndex:n-1];
                self.keepAspectCheck.state=(settings.size_flags&1)!=0;self.scaleDECheck.state=(settings.size_flags&2)!=0;
                self.lastEditWidth=settings.width/n;self.sizeAspect=(double)settings.width/settings.height;
                NSArray *values=@[[NSString stringWithFormat:@"%d",settings.width/n],
                    [NSString stringWithFormat:@"%d",settings.height/n],[NSString stringWithFormat:@"%d",settings.threads],
                    [NSString stringWithFormat:@"%d",settings.normal_smoothing],[NSString stringWithFormat:@"%.17g",settings.de_stop/n],
                    [NSString stringWithFormat:@"%.17g",settings.ray_step]];
                for(NSUInteger i=0;i<values.count;i++)self.calculationFields[i].stringValue=values[i];[self populatePosition];[self populateStepcount];
                self.completedOutputWidth=settings.width/n;self.completedOutputHeight=settings.height/n;self.actualSizeNeedsRender=NO;
                [self updateRenderSizeLabel];self.saveButton.enabled=YES;
                self.statusLabel.stringValue=savePath?@"Saved .m3i parameters and calculated image data.":@"Ready. Change settings and press Render.";
                if(omitReflections&&options.reflections.enabled){self.statusLabel.stringValue=@"Lighting updated. Reflections discarded; press Render to recalculate.";self.lightingStatus.stringValue=self.statusLabel.stringValue;}
                if(historyWarning.length)self.statusLabel.stringValue=[self.statusLabel.stringValue stringByAppendingFormat:@" History: %@",historyWarning];
                self.window.title=[NSString stringWithFormat:@"%@ — %@",APP_TITLE,name];
            });
        }
    });
}
- (NSURL *)applicationMapsFolderURL {
    NSFileManager *files=NSFileManager.defaultManager;
    NSURL *support;
    if(appSandboxBuild()){
        support=[[files URLsForDirectory:NSApplicationSupportDirectory inDomains:NSUserDomainMask] firstObject];
    }else{
        NSString *identifier=NSBundle.mainBundle.bundleIdentifier;
        if(!identifier.length){
#ifdef USE_RUST_ENGINE
            identifier=@"com.greenoak.m3dse";
#else
            identifier=@"org.codex.integer-power";
#endif
        }
        support=[NSURL fileURLWithPath:[NSHomeDirectory() stringByAppendingPathComponent:[NSString stringWithFormat:@"Library/Containers/%@/Data/Library/Application Support",identifier]] isDirectory:YES];
    }
    return [[support URLByAppendingPathComponent:@"Mandelbulb3D SE" isDirectory:YES] URLByAppendingPathComponent:@"Maps" isDirectory:YES];
}
- (NSURL *)applicationTemporaryFolderURL {
    NSURL *data=[self applicationMapsFolderURL];for(int i=0;i<4;i++)data=data.URLByDeletingLastPathComponent;
    return [[data URLByAppendingPathComponent:@"tmp" isDirectory:YES] URLByAppendingPathComponent:@"Mandelbulb3D SE" isDirectory:YES];
}
- (void)migrateHistoryFrom:(NSString *)oldDirectory to:(NSString *)directory {
    if([oldDirectory isEqual:directory])return;
    NSFileManager *files=NSFileManager.defaultManager;NSString *marker=[directory stringByAppendingPathComponent:@".history-location-migrated"];
    if([files fileExistsAtPath:marker])return;
    NSError *error=nil;if(![files createDirectoryAtPath:directory withIntermediateDirectories:YES attributes:nil error:&error])return;
    for(NSString *name in [files contentsOfDirectoryAtPath:oldDirectory error:nil]){
        if(![@[@"m3i",@"msi"] containsObject:name.pathExtension.lowercaseString]||[name hasPrefix:@"."])continue;
        NSString *target=[directory stringByAppendingPathComponent:name];
        if(![files fileExistsAtPath:target]&&![files copyItemAtPath:[oldDirectory stringByAppendingPathComponent:name] toPath:target error:&error]){NSLog(@"Could not migrate render history: %@",error);return;}
    }
    [@"Migrated" writeToFile:marker atomically:YES encoding:NSUTF8StringEncoding error:nil];
}
- (NSURL *)applicationBackgroundsFolderURL {
    return [[[self applicationMapsFolderURL] URLByDeletingLastPathComponent] URLByAppendingPathComponent:@"Backgrounds" isDirectory:YES];
}
- (void)openBackgroundsFolder:(id)sender {
    (void)sender;NSURL *folder=[self applicationBackgroundsFolderURL];NSError *error=nil;
    if(![NSFileManager.defaultManager createDirectoryAtURL:folder withIntermediateDirectories:YES attributes:nil error:&error]){[self showFileError:@"Could not open Backgrounds folder" message:error.localizedDescription];return;}
    if(![NSWorkspace.sharedWorkspace openURL:folder])[self showFileError:@"Could not open Backgrounds folder" message:@"Finder could not open the Backgrounds folder."];
}
- (void)openMapFolder:(id)sender {
    (void)sender;NSURL *folder=[self applicationMapsFolderURL];NSError *error=nil;
    if(![NSFileManager.defaultManager createDirectoryAtURL:folder withIntermediateDirectories:YES attributes:nil error:&error]){[self showFileError:@"Could not open Maps folder" message:error.localizedDescription];return;}
    if(![NSWorkspace.sharedWorkspace openURL:folder])[self showFileError:@"Could not open Maps folder" message:@"Finder could not open the Maps folder."];
}
- (void)showBundledLicenses {
    NSURL *folder=[NSBundle.mainBundle.resourceURL URLByAppendingPathComponent:@"Licenses" isDirectory:YES];
    NSMutableString *body=[NSMutableString string];
    for(NSString *name in @[@"ThirdPartyNotices.txt",@"LGPL-2.1.txt",@"GPL-2.0.txt",@"Map-terms.txt"]){
        NSString *content=[NSString stringWithContentsOfURL:[folder URLByAppendingPathComponent:name] encoding:NSUTF8StringEncoding error:nil];
        [body appendFormat:@"%@\n%@\n\n",name,content?:@"License file unavailable."];
    }
    NSAlert *alert=[NSAlert new];alert.messageText=@"Licenses and third-party notices";
    NSScrollView *scroll=[[NSScrollView alloc]initWithFrame:NSMakeRect(0,0,650,430)];
    scroll.hasVerticalScroller=YES;scroll.borderType=NSBezelBorder;
    NSTextView *text=[[NSTextView alloc]initWithFrame:scroll.contentView.bounds];
    text.editable=NO;text.selectable=YES;text.font=[NSFont systemFontOfSize:12];
    text.textContainerInset=NSMakeSize(8,8);text.verticallyResizable=YES;text.horizontallyResizable=NO;
    text.autoresizingMask=NSViewWidthSizable;text.textContainer.widthTracksTextView=YES;text.string=body;
    scroll.documentView=text;alert.accessoryView=scroll;[alert addButtonWithTitle:@"OK"];[alert runModal];
}
- (void)showMandelbulbSECredits:(id)sender {
    (void)sender;NSAlert *alert=[NSAlert new];alert.alertStyle=NSAlertStyleInformational;
    alert.messageText=@"Mandelbulb3D SE";
    NSString *sourceURL=@"https://github.com/Rodrigo-Spacecraft/Mandelbulb3D-SE/tree/rel5";
    NSString *body=[@"Version 2.0.4\n\nSupport: https://greenoak-software.com/m3dse_support.html\n\nmacOS application, interface, and additional rendering features by Glenn Olander.\nwww.facebook.com/RodrigoSpacecraft\n\nBased on Mandelbulb3D, originally developed by Jesse, with contributions from the Mandelbulb3D community.\n\nRendering engine adapted from mb3d-rs by Sebastian Paluch.\n\nIncludes formulas by their respective authors.\n\nPrivacy policy: https://greenoak-software.com/PrivacyPolicy.html\n\nSource code: " stringByAppendingString:sourceURL];
    NSTextView *credits=[[NSTextView alloc]initWithFrame:NSMakeRect(0,0,560,240)];
    credits.editable=NO;credits.selectable=YES;credits.drawsBackground=NO;
    credits.textContainerInset=NSZeroSize;credits.textContainer.lineFragmentPadding=0;
    credits.textContainer.containerSize=NSMakeSize(560,CGFLOAT_MAX);
    NSMutableAttributedString *text=[[NSMutableAttributedString alloc]initWithString:body attributes:@{NSFontAttributeName:[NSFont systemFontOfSize:13],NSForegroundColorAttributeName:NSColor.labelColor}];
    [text addAttributes:@{NSLinkAttributeName:[NSURL URLWithString:@"https://greenoak-software.com/m3dse_support.html"],NSForegroundColorAttributeName:NSColor.linkColor,NSUnderlineStyleAttributeName:@(NSUnderlineStyleSingle)} range:[body rangeOfString:@"https://greenoak-software.com/m3dse_support.html"]];
    [text addAttributes:@{NSLinkAttributeName:[NSURL URLWithString:@"https://www.facebook.com/RodrigoSpacecraft"],NSForegroundColorAttributeName:NSColor.linkColor,NSUnderlineStyleAttributeName:@(NSUnderlineStyleSingle)} range:[body rangeOfString:@"www.facebook.com/RodrigoSpacecraft"]];
    [text addAttributes:@{NSLinkAttributeName:[NSURL URLWithString:@"https://greenoak-software.com/PrivacyPolicy.html"],NSForegroundColorAttributeName:NSColor.linkColor,NSUnderlineStyleAttributeName:@(NSUnderlineStyleSingle)} range:[body rangeOfString:@"https://greenoak-software.com/PrivacyPolicy.html"]];
    [text addAttributes:@{NSLinkAttributeName:[NSURL URLWithString:sourceURL],NSForegroundColorAttributeName:NSColor.linkColor,NSUnderlineStyleAttributeName:@(NSUnderlineStyleSingle)} range:[body rangeOfString:sourceURL]];
    [credits.textStorage setAttributedString:text];
    [credits.layoutManager ensureLayoutForTextContainer:credits.textContainer];
    credits.frame=NSMakeRect(0,0,560,ceil([credits.layoutManager usedRectForTextContainer:credits.textContainer].size.height)+4);
    alert.accessoryView=credits;
    [alert addButtonWithTitle:@"OK"];[alert addButtonWithTitle:@"Licenses…"];
    while([alert runModal]==NSAlertSecondButtonReturn)[self showBundledLicenses];
}
- (void)applicationDidFinishLaunching:(NSNotification *)notification {
    (void)notification;
    // Let macOS retain its system-presented Dock icon instead of replacing it with raw artwork.
    [self ensureWindow];
    [[FormulaThumbnails shared]start];
    if(!self.receivedFile)[self renderPath:self.initialPath];
    [NSApp activateIgnoringOtherApps:YES];
}
- (void)application:(NSApplication *)application openFiles:(NSArray<NSString *> *)files {
    for(NSString *path in files) {
        if([@[@"m3i",@"m3p",@"msi"] containsObject:path.pathExtension.lowercaseString]) {
            self.receivedFile=YES;[self renderPath:path];break;
        }
    }
    [application replyToOpenOrPrint:NSApplicationDelegateReplySuccess];
}
- (void)windowWillClose:(NSNotification *)notification {
    if(notification.object==self.mutagenWindow)[self stopMutagen];
    if(notification.object==self.animationProcessingWindow&&self.animationRegeneratingPreviews)[self stopRender:nil];
    if(notification.object==self.animationWindow)[self pauseAnimationPlayback];
    if(notification.object==self.animationWindow&&self.animationRunning)[self stopRender:nil];
    if(notification.object==self.navigatorWindow){render_cancel(self.navigatorCancelToken);self.navigatorGeneration++;self.navigatorMotionEpoch++;self.navigatorApplyPending=NO;self.navigatorAddPending=NO;[self.navigatorMoves removeAllObjects];self.previewPending=NO;}
    if(notification.object==self.window) {
        [self.mutagenWindow close];[self.animationWindow close];[self.animationProcessingWindow close];[self.postWindow close];[self.colorWindow close];[self.formulasWindow close];[self.lightingWindow close];[self.navigatorWindow close];[NSApp terminate:nil];
    }
}
- (BOOL)validateMenuItem:(NSMenuItem *)item {
    return item.action==@selector(quitApplication:)?!(self.savingM3I||self.savingAnimation):YES;
}
- (void)quitApplication:(id)sender {if(!self.savingM3I&&!self.savingAnimation)[NSApp terminate:sender];}
- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender {
    (void)sender;return (self.savingM3I||self.savingAnimation)?NSTerminateCancel:NSTerminateNow;
}
- (BOOL)windowShouldClose:(NSWindow *)window {return !((window==self.window&&(self.savingM3I||self.savingAnimation))||(window==self.animationWindow&&self.savingAnimation));}
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    (void)sender;return YES;
}
@end

static int number(const char *s,int low,int high) {
    char *end;errno=0;long n=strtol(s,&end,10);
    return errno||!*s||*end||n<low||n>high?0:(int)n;
}
int main(int argc,char **argv) {
    @autoreleasepool {
        if(argc==5&&!strcmp(argv[1],"--formula-thumbnail"))return renderFormulaThumbnailInResources(atoi(argv[2]),[NSString stringWithUTF8String:argv[3]],[NSString stringWithUTF8String:argv[4]]);
        if(argc==4&&!strcmp(argv[1],"--formula-thumbnail"))return renderFormulaThumbnail(atoi(argv[2]),[NSString stringWithUTF8String:argv[3]]);
        AppDelegate *delegate=[AppDelegate new];
        for(int i=1;i<argc;i++) {
            if(!strcmp(argv[i],"--help")) {
                puts("Usage: Mandelbulb3Dx [scene.m3i] [--width N] [--height N] [--threads N]\nDisplays a render in a native window. No image file is written.");return 0;
            }
            if(!strncmp(argv[i],"-psn_",5))continue;
            if(argv[i][0]!='-') {
                if(delegate.initialPath){fputs("Only one scene file may be supplied.\n",stderr);return 2;}
                delegate.initialPath=[NSString stringWithUTF8String:argv[i]];continue;
            }
            if(i+1>=argc){fprintf(stderr,"Missing value for %s\n",argv[i]);return 2;}
            if(!strcmp(argv[i],"--width")) {delegate.renderWidth=number(argv[++i],16,RENDER_MAX_DIMENSION);if(!delegate.renderWidth)return 2;}
            else if(!strcmp(argv[i],"--height")){delegate.renderHeight=number(argv[++i],16,RENDER_MAX_DIMENSION);if(!delegate.renderHeight)return 2;}
            else if(!strcmp(argv[i],"--threads")){delegate.threads=number(argv[++i],1,256);if(!delegate.threads)return 2;}
            else {fprintf(stderr,"Unknown option: %s\n",argv[i]);return 2;}
        }
        NSApplication *app=NSApplication.sharedApplication;
        [app setActivationPolicy:NSApplicationActivationPolicyRegular];
        app.delegate=delegate;
        // Only the standard macOS application menu; the window contains just the image.
        NSMenu *menu=[NSMenu new];NSMenuItem *root=[NSMenuItem new];
        NSMenu *appMenu=[NSMenu new];
        NSMenuItem *credits=[appMenu addItemWithTitle:@"Mandelbulb3D SE" action:@selector(showMandelbulbSECredits:) keyEquivalent:@""];credits.target=delegate;
        [appMenu addItem:NSMenuItem.separatorItem];
        NSMenuItem *hideOthers=[appMenu addItemWithTitle:@"Hide Others" action:@selector(hideOtherApplications:) keyEquivalent:@"h"];
        hideOthers.target=app;hideOthers.keyEquivalentModifierMask=NSEventModifierFlagCommand|NSEventModifierFlagOption;
        [appMenu addItem:NSMenuItem.separatorItem];
        delegate.quitMenuItem=[appMenu addItemWithTitle:[@"Quit " stringByAppendingString:APP_TITLE] action:@selector(quitApplication:) keyEquivalent:@"q"];delegate.quitMenuItem.target=delegate;
        root.submenu=appMenu;[menu addItem:root];app.mainMenu=menu;
        [app run];
    }
    return 0;
}
