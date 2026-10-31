/* Original Back pic options, stored in the standard 408-byte lighting block. */
static unsigned char *back_pixels;
static int back_width,back_height;
static char back_key[24];static unsigned back_process;static off_t back_file_size;static struct timespec back_file_time;
static Vec back_small[16*8];
static Vec back_texel(int x,int y,int small){int w=small?16:back_width,h=small?8:back_height;x=(x%w+w)%w;y=(int)clamp(y,0,h-1);if(small)return back_small[y*w+x];unsigned char *p=back_pixels+((size_t)y*w+x)*4;return (Vec){p[0]/255.,p[1]/255.,p[2]/255.};}
static Vec back_uv(double u,double v,int small){int w=small?16:back_width,h=small?8:back_height;double x=(u-floor(u))*w,y=clamp(v,0,1)*(h-1);int ix=floor(x),iy=floor(y);return mix(mix(back_texel(ix,iy,small),back_texel(ix+1,iy,small),x-ix),mix(back_texel(ix,iy+1,small),back_texel(ix+1,iy+1,small),x-ix),y-iy);}
static void load_back_picture(void){
    if(!scene.preserved_header_valid||!scene.preserved_header[816]){free(back_pixels);back_pixels=NULL;back_width=back_height=0;back_key[0]=0;return;}
    const unsigned char *l=scene.preserved_header+432;int len=(int)strnlen((const char *)l+384,24);if(len<1||len>23){free(back_pixels);back_pixels=NULL;back_width=back_height=0;back_key[0]=0;return;}
    unsigned process=(l[7]&(16|128))|((u32(l+44)&(1u<<19))?1:0);char path[4608];snprintf(path,sizeof path,"%s/%.*s",background_folder(),len,l+384);struct stat st={0};int exists=stat(path,&st)==0;
    if(back_pixels&&exists&&!strcmp(back_key,(const char *)l+384)&&back_process==process&&back_file_size==st.st_size&&back_file_time.tv_sec==st.st_mtimespec.tv_sec&&back_file_time.tv_nsec==st.st_mtimespec.tv_nsec)return;
    free(back_pixels);back_pixels=NULL;back_width=back_height=0;memcpy(back_key,l+384,24);back_process=process;back_file_size=st.st_size;back_file_time=st.st_mtimespec;
    ObjectMap saved=scene.map;unsigned char *pixels=map_pixels;int w=map_width,h=map_height;scene.map=(ObjectMap){0};memcpy(scene.map.file,l+384,len);map_pixels=NULL;load_object_map_from_folder(background_folder());back_pixels=map_pixels;back_width=map_width;back_height=map_height;scene.map=saved;map_pixels=pixels;map_width=w;map_height=h;if(!back_pixels)return;
    w=back_width;h=back_height;size_t bytes=(size_t)w*h*4;unsigned char *copy=NULL;unsigned flags=u32(l+44);
    if((flags&(1u<<19))||(l[7]&128))copy=malloc(bytes);
    if(copy&&(flags&(1u<<19))){double weights[]={-.05,.25,.6,.25,-.05};for(int axis=1;axis>=0;axis--){memcpy(copy,back_pixels,bytes);for(int y=0;y<h;y++)for(int x=0;x<w;x++)for(int c=0;c<3;c++){double value=0;for(int k=-2;k<=2;k++){int xx=axis?x:(x+k+w*2)%w,yy=axis?(y+k+h*2)%h:y;value+=copy[((size_t)yy*w+xx)*4+c]*weights[k+2];}back_pixels[((size_t)y*w+x)*4+c]=(unsigned char)lround(clamp(value,0,255));}}}
    if(copy&&(l[7]&128)){memcpy(copy,back_pixels,bytes);for(int y=0;y<h;y++){double scale=sqrt(fmax(0,1-pow(2*(y+.5)/h-1,2))),center=(w-1)*.5;for(int x=0;x<w;x++){double sx=(x-center)*scale+center;int ix=floor(sx);for(int c=0;c<3;c++)back_pixels[((size_t)y*w+x)*4+c]=lround(copy[((size_t)y*w+ix)*4+c]*(1-(sx-ix))+copy[((size_t)y*w+((ix+1<w)?ix+1:w-1))*4+c]*(sx-ix));}}}free(copy);
    if(l[7]&16)for(int x=0;x<6&&x<w/2;x++){double b=.5-.5*sin(PI*.5*(x+.5)/6),a=1-b;for(int y=0;y<h;y++)for(int c=0;c<3;c++){unsigned char *p=back_pixels+((size_t)y*w+x)*4+c,*q=back_pixels+((size_t)y*w+w-x-1)*4+c;double v=*p,z=*q;*p=lround(v*a+z*b);*q=lround(v*b+z*a);}}
    memset(back_small,0,sizeof back_small);unsigned counts[128]={0};for(int y=0;y<h;y++)for(int x=0;x<w;x++){int i=((y*8/h<7)?y*8/h:7)*16+((x*16/w<15)?x*16/w:15);back_small[i]=add(back_small[i],back_texel(x,y,0));counts[i]++;}for(int i=0;i<128;i++)back_small[i]=counts[i]?mul(back_small[i],1./counts[i]):back_texel((i%16)*w/16,(i/16)*h/8,0);
}
static Vec back_picture_sample(Vec ray,double u,double v,int small){
    const unsigned char *l=scene.preserved_header+432;
    if(small||!(u32(l+44)&(1u<<15))){double k=PI/128,xa=PI-l[50]*k,ya=l[51]*k,za=l[67]*k,sx=sin(xa),cx=cos(xa),sy=sin(ya),cy=cos(ya),sz=sin(za),cz=cos(za);Vec q={ray.x*cy*cz+ray.y*(sx*sy*cz+cx*sz)+ray.z*(sx*sz-cx*sy*cz),ray.x*(-cy*sz)+ray.y*(cx*cz-sx*sy*sz)+ray.z*(cx*sy*sz+sx*cz),ray.x*sy-ray.y*sx*cy+ray.z*cx*cy};q=unit(q);u=.5-atan2(q.x,q.z)/(2*PI);v=.5-asin(clamp(q.y,-1,1))/PI;}
    return mul(back_uv(u,v,small),pow(1.04,(int)l[212]-40));
}
