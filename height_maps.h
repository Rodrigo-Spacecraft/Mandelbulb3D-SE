/* Geometry maps are separate from the Object lighting map, and are loaded once
 * on the serial render queue. Pixel sampling is read-only on worker threads. */
typedef struct {int valid,number,width,height;uint16_t *pixels;char path[4608];struct timespec modified;off_t size;} HeightMapData;
static HeightMapData height_maps[8];
static void decode_height_map(HeightMapData *m,const char *path){
        CFURLRef url=path[0]?CFURLCreateFromFileSystemRepresentation(NULL,(const UInt8*)path,strlen(path),false):NULL;
        CGImageSourceRef src=url?CGImageSourceCreateWithURL(url,NULL):NULL;CGImageRef image=src?CGImageSourceCreateImageAtIndex(src,0,NULL):NULL;
        if(image){size_t w=CGImageGetWidth(image),h=CGImageGetHeight(image);if(w&&h&&w<=16384&&h<=16384&&w*h<=MAP_MAX_PIXELS){uint16_t *pixels=calloc(w*h,8);CGColorSpaceRef space=CGColorSpaceCreateWithName(kCGColorSpaceSRGB);CGContextRef ctx=pixels?CGBitmapContextCreate(pixels,w,h,16,w*8,space,kCGImageAlphaPremultipliedLast|kCGBitmapByteOrder16Little):NULL;if(ctx){CGContextTranslateCTM(ctx,0,h);CGContextScaleCTM(ctx,1,-1);CGContextDrawImage(ctx,CGRectMake(0,0,w,h),image);CGContextRelease(ctx);m->pixels=pixels;m->width=(int)w;m->height=(int)h;}else free(pixels);CGColorSpaceRelease(space);}CGImageRelease(image);}
        if(src)CFRelease(src);if(url)CFRelease(url);
}
static int load_height_maps(void){
    int changed=0;FormulaProgram p=scene.program_enabled?scene.program:legacy_program();
    for(int i=0;i<8;i++)if(!p.slots[i].count||formula_map_parameter(p.slots[i].kind)<0){free(height_maps[i].pixels);height_maps[i]=(HeightMapData){0};}
    for(int i=0;i<8;i++)if(p.slots[i].count&&formula_map_parameter(p.slots[i].kind)>=0){
        int nr=(int)formula_slot_value(p.slots[i],formula_map_parameter(p.slots[i].kind));char folder[4096],path[4608]={0};snprintf(folder,sizeof folder,"%s",map_folder());
        struct stat existing;HeightMapData *cached=height_maps+i;
        if(cached->valid&&cached->number==nr&&cached->path[0]&&!stat(cached->path,&existing))snprintf(path,sizeof path,"%s",cached->path);
        DIR *dir=path[0]?NULL:opendir(folder);struct dirent *e;if(dir){while((e=readdir(dir))){char *end;long n=strtol(e->d_name,&end,10);if(end!=e->d_name&&n==nr&&(!strcasecmp(end,".png")||!strcasecmp(end,".jpg")||!strcasecmp(end,".jpeg")||!strcasecmp(end,".bmp")||!strcasecmp(end,".gif")||!strcasecmp(end,".tif")||!strcasecmp(end,".tiff"))){snprintf(path,sizeof path,"%s/%s",folder,e->d_name);break;}}closedir(dir);}
        struct stat st={0};if(path[0])stat(path,&st);HeightMapData *m=height_maps+i;
        if(m->valid&&m->number==nr&&!strcmp(m->path,path)&&m->size==st.st_size&&m->modified.tv_sec==st.st_mtimespec.tv_sec&&m->modified.tv_nsec==st.st_mtimespec.tv_nsec)continue;
        changed=1;free(m->pixels);*m=(HeightMapData){.valid=1,.number=nr,.modified=st.st_mtimespec,.size=st.st_size};snprintf(m->path,sizeof m->path,"%s",path);
        decode_height_map(m,path);if(!m->pixels)fprintf(stderr,"Warning: HeightMapIFS map %d could not be loaded from %s; using a black height map.\n",nr,folder);
    }
    return changed;
}
static void height_spline(double t,double w[4]){w[3]=t*t*t/6;w[0]=1./6+.5*t*(t-1)-w[3];w[2]=t+w[0]-2*w[3];w[1]=1-w[0]-w[2]-w[3];}
static Vec height_map_sample(int number,double u,double v){
    HeightMapData *m=NULL;for(int i=0;i<8;i++)if(height_maps[i].valid&&height_maps[i].number==number&&height_maps[i].pixels){m=height_maps+i;break;}if(!m||!isfinite(u)||!isfinite(v))return (Vec){0};
    double x=(u-floor(u))*m->width,y=(v-floor(v))*m->height,wx[4],wy[4];int ix=(int)floor(x),iy=(int)floor(y);height_spline(x-ix,wx);height_spline(y-iy,wy);Vec color={0};
    for(int j=0;j<4;j++)for(int i=0;i<4;i++){int px=((ix+i-1)%m->width+m->width)%m->width,py=((iy+j-1)%m->height+m->height)%m->height;const uint16_t *p=m->pixels+((size_t)py*m->width+px)*4;double w=wx[i]*wy[j]/65535.;color.x+=w*p[0];color.y+=w*p[1];color.z+=w*p[2];}return color;
}
static double height_map_formula(Vec input,const double *v,Vec color,double stop,double *trap){
    Vec p=formula_rotate(input,v+7,1);double hs=(float)v[6],offset=(float)v[3];
    if(fabs(hs)+stop<fabs(p.z+offset-hs*.5))return hs*.5-offset-p.z;
    double rgb[]={color.x,color.y,color.z};*trap=(rgb[(int)v[11]]+(float)v[12])*(float)v[13];return rgb[(int)v[10]]*hs-offset-p.z;
}
