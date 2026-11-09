/* One-bounce transport from emissive DIFS surfaces.
   Cosine-weighted hemisphere sampling integrates emitter
   radiance directly: visibility and apparent solid angle supply falloff. */
#define EMISSION_ILLUMINATION_GAIN 1.5
static Vec emission_bounce;
static Vec emission_color(void){return (Vec){scene.fog.colors[0][0],scene.fog.colors[0][1],scene.fog.colors[0][2]};}
static Vec emission_receiver_contrast(Vec light){
    double peak=fmax(0,fmax(light.x,fmax(light.y,light.z))),brightness=internal_gamma2()?sqrt(peak):peak;
    double t=clamp(brightness/.5,0,1),gain=.75+.25*t*t*(3-2*t);
    if(internal_gamma2())gain*=gain;return mul(light,gain);
}
static double emission_ray(Vec origin,Vec direction,double eps){
    double t=0,maximum=fmax(eps*32,scene.zend-scene.zstart);
    for(int step=0;step<1024&&t<maximum&&!render_cancelled();step++){
        Vec p=add(origin,mul(direction,t));Sample s=evaluate(p);
        if(!isfinite(s.distance))return 0;
        if(s.smooth>=scene.iterations||s.distance<=eps*.5)return reflection_surface_difs(p)?1*(scene.reflections.opacity_set?reflection_palette_opacity(surface_color_sample(p,eps),dot(add(p,mul(scene.direct_origin?scene.view_origin:add(scene.center,camera_rotate((Vec){0,0,scene.zstart-scene.center.z})),-1)),camera_rotate((Vec){0,0,1})),0):1):0;
        t+=fmax(eps*.25,s.distance*.7);
    }return 0;
}
static double emission_red_irradiance(Vec point,Vec normal,double eps){
    if(scene.fog.mode!=2)return 0;
    int emitters=0;if(scene.program_enabled)for(int i=0;i<6;i++)if(scene.program.slots[i].count&&formula_difs(scene.program.slots[i].kind)){emitters=1;break;}
    if(!emitters)return 0;
    Vec origin=add(point,mul(normal,eps*2));double total=0;
    int saved=info_phase;info_phase=6;
    Vec axis=fabs(normal.z)<.9?(Vec){0,0,1}:(Vec){0,1,0};
    Vec tangent=unit((Vec){axis.y*normal.z-axis.z*normal.y,axis.z*normal.x-axis.x*normal.z,axis.x*normal.y-axis.y*normal.x});
    Vec bitangent={normal.y*tangent.z-normal.z*tangent.y,normal.z*tangent.x-normal.x*tangent.z,normal.x*tangent.y-normal.y*tangent.x};
    /* Stable spatial scrambling breaks up visibility bands without more rays. */
    unsigned seed=2166136261u;double coordinates[]={point.x,point.y,point.z};
    for(int c=0;c<3;c++){unsigned long long bits;memcpy(&bits,&coordinates[c],sizeof bits);seed=(seed^(unsigned)bits^(unsigned)(bits>>32))*16777619u;}
    seed^=seed>>16;seed*=0x7feb352du;seed^=seed>>15;seed*=0x846ca68bu;seed^=seed>>16;
    double radial=(double)seed/4294967296.;seed=seed*1664525u+1013904223u;double rotation=(double)seed/4294967296.;
    for(int i=0;i<64&&!render_cancelled();i++){
        unsigned bits=(unsigned)i;double radical=0,factor=.5;while(bits){radical+=(bits&1)*factor;bits>>=1;factor*=.5;}
        double r=sqrt((i+radial)/64.),angle=2*PI*(radical+rotation);
        Vec direction=add(mul(normal,sqrt(1-r*r)),add(mul(tangent,r*cos(angle)),mul(bitangent,r*sin(angle))));
        total+=emission_ray(origin,direction,eps)/64.;
    }
    info_phase=saved;return total;
}

/* Filter cached incoming light only; preserve geometry and material boundaries. */
static int filter_emission_primary(int w,int h){
    size_t count=(size_t)w*h;float *src=malloc(count*sizeof *src),*dst=malloc(count*sizeof *dst),*opacity=malloc(count*sizeof *opacity);
    if(!src||!dst||!opacity){free(src);free(dst);free(opacity);return 0;}
    for(size_t i=0;i<count;i++){SurfacePixel *p=&surface_cache.pixels[i];src[i]=p->emission_irradiance;opacity[i]=p->emission_source?(scene.reflections.opacity_set?reflection_palette_opacity(p->sample,p->depth,0):1):0;}
    int radius=(int)clamp(lround(fmin(w,h)/160.),2,32);double footprint=4*2.1345/(scene.zoom*w);
    for(int scale=1;scale<=2;scale++)for(int vertical=0;vertical<2;vertical++){
        int r=radius*scale;
        for(int y=0;y<h;y++){if(render_cancelled()){free(src);free(dst);free(opacity);return 0;}for(int x=0;x<w;x++){
            size_t i=(size_t)y*w+x;SurfacePixel *a=&surface_cache.pixels[i];dst[i]=src[i];if(!a->hit||opacity[i]>=1)continue;
            double sum=0,weight=0;
            for(int offset=-r;offset<=r;offset++){
                int xx=x+(vertical?0:offset),yy=y+(vertical?offset:0);if(xx<0||xx>=w||yy<0||yy>=h)continue;
                size_t j=(size_t)yy*w+xx;SurfacePixel *b=&surface_cache.pixels[j];
                if(!b->hit||a->emission_source!=b->emission_source||fabs(opacity[i]-opacity[j])>.1)continue;
                double cosine=dot(a->normal,b->normal);if(cosine<.85)continue;
                double dz=fabs(a->depth-b->depth)/fmax(1e-20,footprint*(abs(offset)+1));if(dz>1)continue;
                double spatial=1-(double)offset*offset/((r+1.)*(r+1.)),v=spatial*pow(fmin(1,cosine),16)*(1-dz*dz);
                sum+=src[j]*v;weight+=v;
            }
            if(weight>0)dst[i]=sum/weight;
        }}
        float *swap=src;src=dst;dst=swap;
    }
    for(size_t i=0;i<count;i++)surface_cache.pixels[i].emission_irradiance=src[i];
    free(src);free(dst);free(opacity);return 1;
}

/* Soft indirect fill inferred from visible lit receivers, not another ray pass. */
static void update_emission_bounce(int w,int h){
    emission_bounce=(Vec){0};
    size_t count=(size_t)w*h,stride=(count+4095)/4096;if(!stride)stride=1;double weight=0;Vec sum={0};
    for(size_t i=0;i<count;i+=stride){if(render_cancelled())return;SurfacePixel *p=&surface_cache.pixels[i];if(!p->hit)continue;
        double strength=p->emission_source?(scene.reflections.opacity_set?reflection_palette_opacity(p->sample,p->depth,0):1):0;if(strength>=1)continue;
        Vec dif,spe;palette(p->sample.smooth,p->sample.orbit_trap,p->depth,&dif,&spe);if(map_pixels)dif=object_map_color(p->point,p->normal,p->sample,dif);dif=lighting_color(dif);
        double energy=p->emission_irradiance*(1-strength)*fmin(1,scene.diffuse)*EMISSION_ILLUMINATION_GAIN;
        sum=add(sum,mul(product(dif,lighting_color(emission_color())),energy));weight++;
    }
    if(weight){sum=mul(sum,.45/weight);emission_bounce=(Vec){clamp(sum.x,0,.25),clamp(sum.y,0,.25),clamp(sum.z,0,.25)};}
}
