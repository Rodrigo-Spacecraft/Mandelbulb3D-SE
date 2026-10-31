#include "../renderer.h"
#include <ImageIO/ImageIO.h>
#include <CoreGraphics/CoreGraphics.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char **argv){assert(argc>=3);char error[512];RenderOptions o;assert(read_scene_settings(argv[1],&o,error));int size=argc>3?atoi(argv[3]):96;double ratio=(double)size/o.width;o.width=o.height=size;o.camera_override=1;o.de_stop*=ratio;o.threads=4;if(argc>4){o.fog.mode=0;o.fog.strength=53;}RenderResult r=render_scene_with_options(NULL,o);if(!r.rgba){fprintf(stderr,"%s\n",r.error);return 1;}CGDataProviderRef provider=CGDataProviderCreateWithData(NULL,r.rgba,r.stride*r.height,NULL);CGColorSpaceRef space=CGColorSpaceCreateDeviceRGB();CGImageRef image=CGImageCreate(r.width,r.height,8,32,r.stride,space,kCGImageAlphaLast,provider,NULL,false,kCGRenderingIntentDefault);CFURLRef url=CFURLCreateFromFileSystemRepresentation(NULL,(const UInt8*)argv[2],strlen(argv[2]),false);CGImageDestinationRef dst=CGImageDestinationCreateWithURL(url,CFSTR("public.png"),1,NULL);assert(dst);CGImageDestinationAddImage(dst,image,NULL);assert(CGImageDestinationFinalize(dst));CFRelease(dst);CFRelease(url);CGImageRelease(image);CGColorSpaceRelease(space);CGDataProviderRelease(provider);free(r.rgba);return 0;}
