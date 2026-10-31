#include "renderer.c"
#include <assert.h>

/* Exercise the real numbered-map lookup and both C image decoders at 8K. */
int main(int argc,char **argv) {
    char root[]="/tmp/mb3dx-large-map-XXXXXX",folder[512],path[512];
    assert(mkdtemp(root));
    snprintf(folder,sizeof folder,"%s/M3D",root);assert(!mkdir(folder,0700));
    snprintf(folder,sizeof folder,"%s/M3D/M3Maps",root);assert(!mkdir(folder,0700));
    snprintf(path,sizeof path,"%s/5000.png",folder);
    if(argc>1) {assert(!symlink(argv[1],path));}
    else {
        CGColorSpaceRef space=CGColorSpaceCreateWithName(kCGColorSpaceSRGB);
        CGContextRef context=CGBitmapContextCreate(NULL,8192,8192,8,8192*4,space,kCGImageAlphaPremultipliedLast|kCGBitmapByteOrder32Big);
        assert(context);CGContextSetRGBFillColor(context,1,1,1,1);
        CGContextFillRect(context,CGRectMake(0,0,4096,8192));
        CGImageRef image=CGBitmapContextCreateImage(context);assert(image);
        CFURLRef url=CFURLCreateFromFileSystemRepresentation(NULL,(const UInt8*)path,strlen(path),false);
        CGImageDestinationRef dest=CGImageDestinationCreateWithURL(url,CFSTR("public.png"),1,NULL);assert(dest);
        CGImageDestinationAddImage(dest,image,NULL);assert(CGImageDestinationFinalize(dest));
        CFRelease(dest);CFRelease(url);CGImageRelease(image);CGContextRelease(context);CGColorSpaceRelease(space);
    }
    char *old_home=getenv("HOME")?strdup(getenv("HOME")):NULL;
    assert(!setenv("HOME",root,1));
    memset(&scene.map,0,sizeof scene.map);scene.map.number=5000;
    load_object_map();
    assert(map_pixels&&map_width==8192&&map_height==8192);
    int lo=255,hi=0;
    for(int y=0;y<map_height;y+=127)for(int x=0;x<map_width;x+=127){int v=map_pixels[((size_t)y*map_width+x)*4];if(v<lo)lo=v;if(v>hi)hi=v;}
    assert(hi-lo>100);free(map_pixels);map_pixels=NULL;
    HeightMapData height={0};decode_height_map(&height,path);
    assert(height.pixels&&height.width==8192&&height.height==8192);free(height.pixels);
    if(old_home){setenv("HOME",old_home,1);free(old_home);}else unsetenv("HOME");
    unlink(path);rmdir(folder);snprintf(folder,sizeof folder,"%s/M3D",root);rmdir(folder);rmdir(root);
    puts("8192 x 8192 numbered diffuse map and height map loaded successfully.");
    return 0;
}
