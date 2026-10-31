/* C-only emission bloom. Three separable box blurs approximate a Gaussian;
   sliding sums keep cost linear in pixel count regardless of glow radius. */
static int emission_glow_blur(const float *src,float *dst,int w,int h,int radius,int vertical){
    int lines=vertical?w:h,length=vertical?h:w;size_t step=vertical?(size_t)w:1;
    for(int line=0;line<lines;line++){
        if(render_cancelled())return 0;
        size_t base=vertical?(size_t)line:(size_t)line*w;double sum=0;
        for(int i=0;i<=radius&&i<length;i++)sum+=src[base+(size_t)i*step];
        for(int i=0;i<length;i++){
            int low=i-radius>0?i-radius:0,high=i+radius<length?i+radius:length-1;
            dst[base+(size_t)i*step]=(float)(sum/(high-low+1));
            if(i-radius>=0)sum-=src[base+(size_t)(i-radius)*step];
            if(i+radius+1<length)sum+=src[base+(size_t)(i+radius+1)*step];
        }
    }return 1;
}
static int apply_emission_glow(RenderResult *result){
    if(scene.fog.mode!=2||!surface_cache.pixels)return 1;
    int w=result->width,h=result->height,found=0;size_t count=(size_t)w*h;
    for(size_t i=0;i<count;i++)if(surface_cache.pixels[i].hit&&surface_cache.pixels[i].emissive){found=1;break;}
    if(!found)return 1;
    float *mask=calloc(count,sizeof *mask),*tmp=malloc(count*sizeof *tmp);
    if(!mask||!tmp){free(mask);free(tmp);return 0;}
    for(int y=0;y<h;y++)for(int x=0;x<w;x++){
        SurfacePixel *p=&surface_cache.pixels[(size_t)y*w+x];
        if(p->hit&&p->emissive){unsigned char *q=result->rgba+(size_t)y*result->stride+4*x;mask[(size_t)y*w+x]=fmax(q[0],fmax(q[1],q[2]))/255.f;}
    }
    int radius=(int)fmax(1,lround(fmin(w,h)*.015));
    for(int pass=0;pass<3;pass++)if(!emission_glow_blur(mask,tmp,w,h,radius,0)||!emission_glow_blur(tmp,mask,w,h,radius,1)){free(mask);free(tmp);return 0;}
    for(int y=0;y<h;y++){
        if(render_cancelled()){free(mask);free(tmp);return 0;}
        for(int x=0;x<w;x++){
            unsigned char *p=result->rgba+(size_t)y*result->stride+4*x;
            double glow=clamp(mask[(size_t)y*w+x]*1.5,0,1);
            for(int c=0;c<3;c++)p[c]=(unsigned char)lround(p[c]+(255-p[c])*glow*scene.fog.colors[0][c]);
        }
    }
    free(mask);free(tmp);return 1;
}
