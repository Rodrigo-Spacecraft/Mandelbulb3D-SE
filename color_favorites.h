/* Color-only favorites. Includes map selection and mapping; excludes geometry, light sources and radiance state. */
typedef struct {
    ObjectColorStop outside[10],inside[10];
    double diffuse,specular,ambient,colors[4][3],opacity[2][10];
    int interpolation;
} LegacyColorFavoriteV2;
typedef struct {
    ObjectColorStop outside[10],inside[10];
    double diffuse,specular,ambient,colors[4][3],opacity[2][10];
    int interpolation;
    ObjectMap map;
} ColorFavorite;
/* Read the original private favorite records while discarding their range values. */
typedef struct {ObjectColorStop outside[10],inside[10];double diffuse,specular,start,end,insideStart,insideEnd,ambient,colors[4][3],opacity[2][10];int interpolation;} LegacyColorFavorite;
static NSData *colorFavoriteRecord(id entry){
    if(![entry isKindOfClass:NSData.class])return NSData.data;
    if([entry length]==sizeof(ColorFavorite))return entry;
    if([entry length]==sizeof(LegacyColorFavoriteV2)){ColorFavorite f={0};memcpy(&f,[entry bytes],sizeof(LegacyColorFavoriteV2));f.map=(ObjectMap){.disabled=1,.scale=1,.offset_x=.5,.offset_y=.5};return [NSData dataWithBytes:&f length:sizeof f];}
    if([entry length]!=sizeof(LegacyColorFavorite))return NSData.data;
    LegacyColorFavorite old;memcpy(&old,[entry bytes],sizeof old);ColorFavorite f={0};memcpy(f.outside,old.outside,sizeof f.outside);memcpy(f.inside,old.inside,sizeof f.inside);f.map=(ObjectMap){.disabled=1,.scale=1,.offset_x=.5,.offset_y=.5};f.diffuse=old.diffuse;f.specular=old.specular;f.ambient=old.ambient;f.interpolation=old.interpolation;memcpy(f.colors,old.colors,sizeof f.colors);memcpy(f.opacity,old.opacity,sizeof f.opacity);return [NSData dataWithBytes:&f length:sizeof f];
}
static ColorFavorite colorFavoriteCapture(RenderOptions o){
    ColorFavorite f={0};memcpy(f.outside,o.object.stops,sizeof f.outside);memcpy(f.inside,o.cutting_colors.stops,sizeof f.inside);
    f.map=o.object.map;f.diffuse=o.object.diffuse;f.specular=o.object.specular;f.ambient=o.ambient.strength;f.interpolation=o.object.no_interpolation;memcpy(f.colors,o.ambient.colors,sizeof f.colors);
    for(int c=0;c<2;c++)for(int i=0;i<10;i++)f.opacity[c][i]=o.reflections.opacity_set?o.reflections.opacity[c][i]:1;return f;
}
static RenderOptions colorFavoriteApply(RenderOptions o,ColorFavorite f){
    memcpy(o.object.stops,f.outside,sizeof f.outside);memcpy(o.cutting_colors.stops,f.inside,sizeof f.inside);o.object.map=f.map;o.object.diffuse=f.diffuse;o.object.specular=f.specular;o.object.no_interpolation=f.interpolation;o.ambient.strength=f.ambient;memcpy(o.ambient.colors,f.colors,sizeof f.colors);memcpy(o.reflections.opacity,f.opacity,sizeof f.opacity);o.reflections.opacity_set=1;o.object_override=o.ambient_override=o.cutting_colors_override=1;return o;
}
static ColorFavorite colorFavoriteBasic(int n){
    static const unsigned diffuse[5][4]={{0x2537A0,0x4E9FD1,0x62AEB3,0x71808E},{0xE0,0xFF0000,0xB800,0xABDD},{0x1D85F8,0xC0C0C0,0x47CCF8,0xB9B69B},{0x204080,0x349120,0x1E36C1,0xC5AAE6},{0xA0A0A0,0xA0A0A0,0xA0A0A0,0xA0A0A0}};
    static const unsigned specular[5][4]={{0x0B1026,0x132734,0x273639,0x1C2023},{0xF0F0F0,0xF0F0F0,0xF0F0F0,0xF0F0F0},{0x1D85F8,0xC0C0C0,0x47CCF8,0xB9B69B},{0,0x40491C,0x3B3D60,0x60487F},{0x404040,0x404040,0x404040,0x404040}};
    static const unsigned ambient[5][4]={{0xB1AA9F,0x3464AA,0xB1AA9F,0x3464AA},{0xFF6000,0x40B0,0x800000,0x50},{0xE89660,0x304860,0xA04B18,0xD0A488},{0xEC974A,0x5976A6,0xEC974A,0x5976A6},{0x905838,0x8BA8C7,0x905838,0x8BA8C7}};
    static const double strengths[5][3]={{50,50,90},{110,22,220},{160,50,30},{50,70,90},{50,70,90}};
    ColorFavorite f={0};f.map=(ObjectMap){.disabled=1,.scale=1,.offset_x=.5,.offset_y=.5};f.specular=strengths[n][0]/50;f.diffuse=strengths[n][1]/50;f.ambient=strengths[n][2]/90;
    for(int i=0;i<10;i++){int k=i<4?i:0;f.outside[i].position=i<4?i*8191:32200+(i-3)*84;f.inside[i].position=i<4?i*8191:32700;for(int c=0;c<3;c++){f.outside[i].diffuse[c]=((diffuse[n][k]>>(8*c))&255)/255.;f.outside[i].specular[c]=((specular[n][k]>>(8*c))&255)/255.;f.inside[i].diffuse[c]=f.outside[i].diffuse[c];f.inside[i].specular[c]=.627;}f.opacity[0][i]=f.opacity[1][i]=1;}
    for(int i=0;i<4;i++)for(int c=0;c<3;c++)f.colors[i][c]=((ambient[n][i]>>(8*c))&255)/255.;return f;
}
/* The original favorites use a hybrid quaternion sample, rather than a Mandelbulb. */
static double favoriteQuatIterations(double cx,double cy,double cz){
    double x=cx,y=cy,z=cz,w=0,r=0;int iteration=0;
    do{double xt=x,yt=y,zt=z;x=x*x-y*y-z*z-w*w+cx;y=2*(y*xt+z*w)+cy;z=2*(z*xt-yt*w)+cz;w=2*(w*xt+yt*zt);r=x*x+y*y+z*z+w*w;iteration++;}while(iteration<10&&r<=8);
    return r<=1?iteration:iteration-log(.5*log(r))*1.4427;
}
typedef struct {double r,g,b;} FavoriteRGB;
static FavoriteRGB favoriteMapSample(NSBitmapImageRep *map,double u,double v){
    NSInteger w=map.pixelsWide,h=map.pixelsHigh;double x=(u-floor(u))*w-.5,y=(v-floor(v))*h-.5;NSInteger ix=floor(x),iy=floor(y);double tx=x-ix,ty=y-iy;FavoriteRGB out={0};
    for(int j=0;j<2;j++)for(int i=0;i<2;i++){NSColor *c=[[map colorAtX:((ix+i)%w+w)%w y:((iy+j)%h+h)%h] colorUsingColorSpace:NSColorSpace.sRGBColorSpace];double weight=(i?tx:1-tx)*(j?ty:1-ty);out.r+=c.redComponent*weight;out.g+=c.greenComponent*weight;out.b+=c.blueComponent*weight;}return out;
}
static FavoriteRGB favoriteMappedColor(NSBitmapImageRep *image,ObjectMap m,double p[3],double n[3],double smooth,double trap){
    double a=m.rotation*M_PI/180,c=cos(a),s=sin(a),u=0,v=0,weights[3]={fabs(n[0]),fabs(n[1]),fabs(n[2])},total=fmax(1e-30,weights[0]+weights[1]+weights[2]);for(int i=0;i<3;i++)weights[i]/=total;
    if(m.mode==0){double x=fmax(0,fmin(32767,trap*4096))/32767.-.5,y=1-fmax(0,fmin(10,smooth))/11.-.5;u=(c*x+s*y+m.offset_x+1)*m.scale;v=(c*y-s*x+m.offset_y+1)*m.scale;}
    else if(m.mode==1){double x=c*n[0]-s*n[1],y=s*n[0]+c*n[1];u=(atan2(x,n[2])/(2*M_PI)+m.offset_x-.5)*m.scale+.5;v=(m.offset_y-asin(fmax(-1,fmin(1,y)))/M_PI-.5)*m.scale+.5;}
    else{double x=p[0]*m.scale,y=p[1]*m.scale,z=p[2]*m.scale;
        if(m.mode==3){FavoriteRGB a=favoriteMapSample(image,c*y+s*z+m.offset_x,c*z-s*y+m.offset_y),b=favoriteMapSample(image,c*x+s*z+m.offset_x,c*z-s*x+m.offset_y),d=favoriteMapSample(image,c*x+s*y+m.offset_x,c*y-s*x+m.offset_y);return (FavoriteRGB){a.r*weights[0]+b.r*weights[1]+d.r*weights[2],a.g*weights[0]+b.g*weights[1]+d.g*weights[2],a.b*weights[0]+b.b*weights[1]+d.b*weights[2]};}
        double q=sin(y)*weights[0]+sin(x)*(weights[1]+weights[2]),r=sin(z)*(weights[0]+weights[1])+sin(y)*weights[2];u=c*q+s*r+m.offset_x;v=c*r-s*q+m.offset_y;
    }return favoriteMapSample(image,u,v);
}
static NSImage *colorFavoriteThumbnail(ColorFavorite f,NSString *mapFolder){
    enum{W=50,H=34};typedef struct{double normal[3],point[3],smooth,trap,shade,position;BOOL hit;} Sample;static Sample samples[W*H];static dispatch_once_t once;
    dispatch_once(&once,^{for(int y=0;y<H;y++)for(int x=0;x<W;x++){
        double px=(x-(W-H)/2+1)*.07-1.75,py=(H-1-y)*.07-1.156,z=-1.5,de=.055,smooth=0;Sample *s=&samples[y*W+x];
        do{z+=de*.3;smooth=favoriteQuatIterations(px,py,z);de=fabs(1/(1+exp(smooth-3)))+.02;}while(z<=.5&&de>=.04);
        if(z<=.499){s->hit=YES;s->point[0]=px;s->point[1]=py;s->point[2]=z;s->smooth=smooth;s->trap=sqrt(px*px+py*py+z*z);double nx=favoriteQuatIterations(px-.0001,py,z)-smooth,ny=smooth-favoriteQuatIterations(px,py+.0001,z),nz=smooth-favoriteQuatIterations(px,py,z-.0001),len=fmax(1e-12,sqrt(nx*nx+ny*ny+nz*nz));s->normal[0]=nx/len;s->normal[1]=ny/len;s->normal[2]=nz/len;s->shade=fmax(0,(-nx*.4+ny*.5+nz*.76)/len);s->position=fmax(0,fmin(32767,(x-(W-H)/2+1)*1058-7800));}
    }});
    NSBitmapImageRep *map=nil;
    if(!f.map.disabled){NSString *file=[NSString stringWithUTF8String:f.map.file];if(!file.length&&f.map.number)file=[NSString stringWithFormat:@"%d.png",f.map.number];
        if(file.length&&[file.lastPathComponent isEqual:file]){NSImage *source=[[NSImage alloc]initWithContentsOfFile:[mapFolder stringByAppendingPathComponent:file]];if(source){map=[[NSBitmapImageRep alloc]initWithBitmapDataPlanes:NULL pixelsWide:128 pixelsHigh:128 bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSDeviceRGBColorSpace bytesPerRow:512 bitsPerPixel:32];[NSGraphicsContext saveGraphicsState];[NSGraphicsContext setCurrentContext:[NSGraphicsContext graphicsContextWithBitmapImageRep:map]];[source drawInRect:NSMakeRect(0,0,128,128) fromRect:NSZeroRect operation:NSCompositingOperationCopy fraction:1 respectFlipped:YES hints:nil];[NSGraphicsContext restoreGraphicsState];}}
    }
    NSBitmapImageRep *rep=[[NSBitmapImageRep alloc]initWithBitmapDataPlanes:NULL pixelsWide:W pixelsHigh:H bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSDeviceRGBColorSpace bytesPerRow:W*4 bitsPerPixel:32];ObjectLighting palette={0};memcpy(palette.stops,f.outside,sizeof f.outside);palette.no_interpolation=f.interpolation;
    for(int y=0;y<H;y++)for(int x=0;x<W;x++){Sample *s=&samples[y*W+x];double t=(double)y/(H-1);NSColor *dif=s->hit?[paletteColor(palette,s->position,NO) colorUsingColorSpace:NSColorSpace.sRGBColorSpace]:nil,*spec=s->hit?[paletteColor(palette,s->position,YES) colorUsingColorSpace:NSColorSpace.sRGBColorSpace]:nil;double d[3]={dif.redComponent,dif.greenComponent,dif.blueComponent},sp[3]={spec.redComponent,spec.greenComponent,spec.blueComponent};
        if(s->hit&&map){FavoriteRGB color=favoriteMappedColor(map,f.map,s->point,s->normal,s->smooth,s->trap);if(f.map.combine){double lum=color.r*.299+color.g*.587+color.b*.114,base=d[0]*.299+d[1]*.587+d[2]*.114;for(int i=0;i<3;i++)d[i]*=lum/(.001+base);}else{d[0]=color.r;d[1]=color.g;d[2]=color.b;}}
        for(int c=0;c<3;c++){double bg=f.colors[2][c]*(1-t)+f.colors[3][c]*t;double value=bg;if(s->hit){double amb=f.colors[0][c]*(1-t)+f.colors[1][c]*t;value=d[c]*(f.diffuse*s->shade*.75+f.ambient*amb*.18)+sp[c]*f.specular*pow(s->shade,22);}rep.bitmapData[(y*W+x)*4+c]=(unsigned char)lround(fmax(0,fmin(1,value))*255);}rep.bitmapData[(y*W+x)*4+3]=255;}
    NSImage *image=[[NSImage alloc]initWithSize:NSMakeSize(W,H)];[image addRepresentation:rep];return image;
}
@interface ColorFavoriteButton:NSButton
@property(nonatomic,copy) void (^clearFavorite)(void);
@end
@implementation ColorFavoriteButton
- (void)mouseDown:(NSEvent *)event {if(event.modifierFlags&NSEventModifierFlagControl){[self rightMouseDown:event];return;}[super mouseDown:event];}
- (void)drawRect:(NSRect)dirty {
    if(!self.image){[super drawRect:dirty];return;}
    [self.image drawInRect:self.bounds fromRect:NSZeroRect operation:NSCompositingOperationSourceOver fraction:self.enabled?1:.45 respectFlipped:YES hints:nil];
    if(self.highlighted){[NSColor.selectedControlColor setStroke];NSFrameRectWithWidth(self.bounds,2);}
}
- (void)rightMouseDown:(NSEvent *)event {if(!self.enabled||!self.clearFavorite)return;NSMenu *menu=[NSMenu new];NSMenuItem *item=[[NSMenuItem alloc]initWithTitle:@"Clear favorite" action:@selector(clearSlot:) keyEquivalent:@""];item.target=self;[menu addItem:item];[NSMenu popUpContextMenu:menu withEvent:event forView:self];}
- (void)clearSlot:(id)sender{(void)sender;if(self.clearFavorite)self.clearFavorite();}
@end
