/* Export straight (unpremultiplied) A/R/G/B planes for small ICNS images. */
#import <Cocoa/Cocoa.h>
int main(int argc,const char **argv){@autoreleasepool{
    if(argc!=2)return 2;
    NSBitmapImageRep *image=[[NSBitmapImageRep alloc]initWithData:[NSData dataWithContentsOfFile:[NSString stringWithUTF8String:argv[1]]]];
    if(!image)return 1;
    for(int channel=0;channel<4;channel++)for(NSInteger y=0;y<image.pixelsHigh;y++)for(NSInteger x=0;x<image.pixelsWide;x++){
        NSColor *color=[[image colorAtX:x y:y] colorUsingColorSpace:NSColorSpace.sRGBColorSpace];
        CGFloat values[]={color.alphaComponent,color.redComponent,color.greenComponent,color.blueComponent};
        unsigned char byte=(unsigned char)lround(fmax(0,fmin(1,values[channel]))*255);if(fwrite(&byte,1,1,stdout)!=1)return 1;
    }
    return 0;
}}
