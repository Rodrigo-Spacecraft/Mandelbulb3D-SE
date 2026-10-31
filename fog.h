/* Light-space depth maps, following maps/Maps.pas and CalcThread.DoDynFog.
 * Map samples are first-hit distances: six cube faces for positional lights,
 * one orthographic plane for directional lights. No shadow rays per fog sample.
 */
typedef struct {
    Scene key;Light light;int mode,iteration,adjust,size,positional,valid,first_random;
    Vec origin,right,up,forward;double spacing,start,range,pixel;
    float *map,*integral;
    unsigned long builds,integrations;
} FogCache;
static FogCache fog_caches[2];
static FogCache *fog_cache;
static Vec fog_cube_direction(int face,double x,double y) {
    switch(face){case 0:return unit((Vec){1,x,y});case 1:return unit((Vec){-1,-x,-y});case 2:return unit((Vec){x,1,y});case 3:return unit((Vec){-x,-1,-y});case 4:return unit((Vec){x,y,1});default:return unit((Vec){-x,-y,-1});}
}
static double fog_first_hit(Vec origin,Vec ray,double range,double pixel) {
    double t=0,last=0,lastStep=0,factor=1;
    Vec camera=scene.direct_origin?scene.view_origin:add(scene.center,camera_rotate((Vec){0,0,scene.zstart-scene.center.z}));
    Vec delta=add(origin,mul(camera,-1));double initial=sqrt(dot(delta,delta)),advance=dot(ray,camera_rotate((Vec){0,0,1}));
    double maxStep=fmax(scene.de_stop,.4)*fmax(scene.width,scene.height)*.5*sqrt(scene.ray_step+.0001)*pixel;
    for(int i=0;i<100000&&t<range&&!render_cancelled();i++) {
        Sample sample=evaluate(add(origin,mul(ray,t)));double d=sample.distance;
        double eps=pixel*scene.de_stop*(1+(scene.vary?fabs(initial+t*advance)*(scene.fov*PI/180)/(scene.height*pixel):0));
        if(i&&(d<=eps||sample.smooth>=scene.iterations))return t;
        if(i){d=fmin(d,last+lastStep);factor=last>d+1e-30?clamp(lastStep/(last-d),.5,1):1;}
        last=d;lastStep=fmin(maxStep,fmax(pixel*.11,(d-eps*.25)*scene.ray_step*factor));t+=lastStep;
    }
    return range*1000;
}
static int fog_visible(Vec p) {
    FogCache *c=fog_cache;Vec v=add(p,mul(c->origin,-1));int face=0,x,y;double distance;
    if(c->positional){
        double ax=fabs(v.x),ay=fabs(v.y),az=fabs(v.z),u,w,den;
        if(ax>=ay&&ax>=az){face=v.x>0?0:1;den=v.x;u=v.y;w=v.z;}
        else if(ay>=az){face=v.y>0?2:3;den=v.y;u=v.x;w=v.z;}
        else{face=v.z>0?4:5;den=v.z;u=v.x;w=v.y;}
        if(fabs(den)<1e-30)return 1;
        x=(int)lrint(u/den*(c->size-1)*.5)+(c->size/2);y=(int)lrint(w/den*(c->size-1)*.5)+(c->size/2);distance=sqrt(dot(v,v));
    }else{x=(int)lrint(dot(v,c->right)/c->spacing)+c->size/2;y=(int)lrint(dot(v,c->up)/c->spacing)+c->size/2;distance=dot(v,c->forward);}
    x=(int)clamp(x,0,c->size-1);y=(int)clamp(y,0,c->size-1);
    return distance<c->map[((size_t)face*c->size+y)*c->size+x];
}
static int fog_iteration(Vec point,Sample sample) {
    if(!scene.program_enabled)return (int)ceil(sample.smooth);
    FormulaProgram p=scene.program;
    OrbitResult a=program_part(point,p,0,p.mode==2?p.split-1:7,p.repeat_from,scene.iterations);
    if(p.mode!=2)return a.iterations;
    OrbitResult b=program_part(point,p,p.split,7,p.repeat2,p.max_iterations2);
    return a.sample.distance<b.sample.distance?a.iterations:b.iterations;
}
/* Same per-pixel first-step phase as MB3D; independent of worker order. */
static double fog_pixel_phase(unsigned x,unsigned y) {
    uint32_t row=0x24563487u+(y+1)*0x324594A1u,a=214013u,c=2531011u,ra=1,rc=0;
    for(unsigned n=x;n;n>>=1){if(n&1){rc=rc*a+c;ra*=a;}c=c*a+c;a*=a;}
    uint32_t seed=(ra*row+rc)*214013u+2531011u;
    return fmax(1e-12,(seed&0x7fffffffu)*(1./2147483647.));
}
/* Integer Power geometry uses the conservative half-log bulb DE. The
 * original analytic fog accumulator uses r*log(r)/dr (Rout is squared).
 * Keep its step-count units without changing primary hit tolerances. */
static double fog_dynamic_de_scale(void) {
    if(!scene.program_enabled)return scene.kind==0&&(!scene.count2||scene.kind2==0)?2:1;
    const FormulaProgram *p=&scene.program;
    if(p->mode==2||p->numerical_de)return 1;
    int active=0;
    for(int i=0;i<8;i++)if(p->slots[i].count){if(p->slots[i].kind!=0)return 1;active=1;}
    return active?2:1;
}
static double fog_integrate_phase(Vec origin,Vec ray,double target,double phase) {
    FogCache *c=fog_cache;
    double count=0,t=0,lastDE=0,lastStep=0;int iterations=0;
    double deScale=fog_dynamic_de_scale(),rayStep=scene.ray_step,subtract=0;
    if(scene.preserved_header_valid&&(u16(scene.preserved_header+16)&4)){
        rayStep=rayStep*rayStep+1.2*rayStep*(1-rayStep);subtract=fmin(.9,sqrt(rayStep));
    }
    while(t<target&&!render_cancelled()){
        double step=c->pixel*(1+(scene.vary?t*(scene.fov*PI/180)/(scene.height*c->pixel):0));
        Vec p=add(origin,mul(ray,t));
        if(c->mode){
            step/=sqrt(1+.1*c->adjust);step=fmin(step,target-t);
            if(!(c->light.option&1)&&fog_visible(p)){
                double weight=step/c->pixel;
                if(c->positional){Vec v=add(p,mul(c->origin,-1));weight/=dot(v,v)+c->pixel*c->pixel;}
                count+=weight;
            }
        }else{
            Sample sample=evaluate(p);double eps=step*scene.de_stop,distance=sample.distance*deScale,factor=1;
            if(iterations){distance=fmin(distance,lastDE+lastStep);if(lastDE>distance+1e-30)factor=clamp(lastStep/(lastDE-distance),.5,1);}
            double actual=fmax(c->pixel*.11,(distance-eps*subtract)*rayStep*factor);
            double limit=fmax(eps,c->pixel*.4)*fmax(scene.width,scene.height)*.5*sqrt(scene.ray_step+.001)*fmax(.01,scene.raystep_limiter);
            double advance=fmin(actual,limit);if(!iterations)advance*=phase;step=fmin(advance,target-t);
            /* CalcThread.DoDynFog counts a full DE step unless the limiter
             * shortened it. Dividing every step by the limit under-counted
             * fog and made white additive fog subtract light instead. */
            if(!c->iteration||fog_iteration(p,sample)==c->iteration)count+=(actual>limit?limit/actual:1)*(step/advance);
            lastDE=distance;lastStep=step;
        }
        if(!(step>0))break;t+=step;
        /* Cancellation checked every step, including near positional lights. */
        if(++iterations>=1000000)break;
    }

    return c->mode?count:fmin(1023,count);
}
static double fog_integrate(Vec origin,Vec ray,double target){return fog_integrate_phase(origin,ray,target,1);}
typedef struct {atomic_int row;int map,rows;} FogJob;
static void *fog_worker(void *arg) {
    INFO_WORKER;INFO_PHASE(5);
    FogJob *job=arg;FogCache *c=fog_cache;int row;
    while((row=atomic_fetch_add(&job->row,1))<job->rows&&!render_cancelled()) {
        if(job->map){
            int face=row/c->size,y=row%c->size;double half=c->size/2;
            for(int x=0;x<c->size&&!render_cancelled();x++){
                Vec origin=c->origin,ray=c->forward;
                if(c->positional)ray=fog_cube_direction(face,(x-half)/half,(y-half)/half);
                else origin=add(add(add(origin,mul(c->forward,c->start)),mul(c->right,(x-half)*c->spacing)),mul(c->up,(y-half)*c->spacing));
                double d=fog_first_hit(origin,ray,c->range,c->pixel);if(!c->positional)d+=c->start;
                c->map[(size_t)row*c->size+x]=(float)d;
            }
        }else{
            for(int x=0;x<scene.width&&!render_cancelled();x++){
                size_t n=(size_t)row*scene.width+x;SurfacePixel s=surface_cache.pixels[n];double target=s.hit?s.depth:c->range;
                target=fmin(target,c->range);
                Vec offset={(x+.5-scene.width*.5)*c->pixel,(row+.5-scene.height*.5)*c->pixel,scene.direct_origin?0:scene.zstart-scene.center.z};
                if(scene.optic==2)offset.x=offset.y=0;
                Vec origin=add(scene.direct_origin?scene.view_origin:scene.center,camera_rotate(offset));
                c->integral[n]=(float)fog_integrate_phase(origin,s.ray,target,c->first_random?fog_pixel_phase(x,row):1);
            }
        }
        if(active_cancel)atomic_fetch_add(&active_cancel->rows,1);
    }
    return NULL;
}
static void fog_run(FogJob *job,int threads){
    atomic_init(&job->row,0);pthread_t workers[255];int started=0;
    for(int i=1;i<threads&&i<job->rows;i++){if(pthread_create(workers+started,NULL,fog_worker,job))break;started++;}
    fog_worker(job);for(int i=0;i<started;i++)pthread_join(workers[i],NULL);
}
static int fog_prepare(int threads,int preview) {
    if(scene.fog.mode>=2)return 1;
    FogCache *c=&fog_caches[preview?1:0];fog_cache=c;Scene key=geometry_key();key.raystep_limiter=scene.raystep_limiter;key.preserved_header[16]=scene.preserved_header_valid?(scene.preserved_header[16]&4):0;key.shadows.hard_length=scene.shadows.hard_length;FogSettings f=scene.fog;Light light=scene.lights[f.light-1];
    int first_random=!scene.preserved_header_valid||(u16(scene.preserved_header+16)&1);
    int match=c->first_random==first_random&&c->valid&&!memcmp(&key,&c->key,sizeof key)&&c->mode==f.mode&&c->iteration==f.iterations&&c->adjust==f.map_size&&c->key.shadows.hard_length==scene.shadows.hard_length;
    if(f.mode)match=match&&c->light.option==light.option&&!memcmp(&c->light.position,&light.position,sizeof(Vec));
    if(match)return 1;
    free(c->map);free(c->integral);c->map=c->integral=NULL;c->valid=0;c->key=key;c->key.shadows.hard_length=scene.shadows.hard_length;c->light=light;c->mode=f.mode;c->iteration=f.iterations;c->adjust=f.map_size;c->first_random=first_random;
    c->pixel=2.1345/(scene.zoom*scene.width);c->range=scene.zend-scene.zstart;c->positional=(light.option&4)!=0;
    c->integral=calloc((size_t)scene.width*scene.height,sizeof(float));if(!c->integral)return 0;
    if(f.mode){
        double s=fmax(scene.width,scene.height),factor=1+.2*f.map_size;
        if(c->positional){c->origin=light.position;c->size=(int)lrint(s*factor*.25)|1;c->size=c->size<3?3:c->size;}
        else{
            double distance=fmin(c->range/c->pixel,s*16),sm=fmax(distance,s)/s;
            c->size=(int)lrint(s*pow(sm,.36)*factor*.625)|1;c->size=c->size<3?3:c->size;
            Vec toward=unit((Vec){-sin(light.position.x),-sin(light.position.y),-cos(light.position.x)*cos(light.position.y)});
            if(!(light.option&32))toward=camera_rotate(toward);
            c->forward=mul(toward,-1);c->right=unit(cross(fabs(c->forward.y)<.9?(Vec){0,1,0}:(Vec){1,0,0},c->forward));c->up=unit(cross(c->forward,c->right));
            Vec origin=scene.direct_origin?scene.view_origin:add(scene.center,camera_rotate((Vec){0,0,scene.zstart-scene.center.z}));
            c->origin=add(origin,camera_rotate((Vec){0,0,distance*c->pixel*.5}));
            double span=distance*c->pixel*sqrt(sqrt(fmax(1,factor)));
            c->spacing=span*1.75/c->size;c->start=-span*fmax(.01,scene.shadows.hard_length);
            c->range=fmax(c->range,2*fabs(c->start));
        }
        size_t n=(size_t)c->size*c->size*(c->positional?6:1);
        if(n>SIZE_MAX/sizeof(float)||(c->map=malloc(n*sizeof(float)))==NULL)return 0;
        FogJob job={.map=1,.rows=c->size*(c->positional?6:1)};fog_run(&job,threads);c->builds++;
    }
    /* Camera integration ends at the far plane, independent of map ray length. */
    c->range=scene.zend-scene.zstart;
    FogJob job={.rows=scene.height};fog_run(&job,threads);c->integrations++;c->valid=!render_cancelled();return c->valid;
}
static Vec fog_mix(Vec color,double count,double depth) {
    FogSettings f=scene.fog;if(f.mode>=2)return color;
    double grad=(f.strength-53)*(f.mode?.00002:scene.ray_step*.00065*(f.iterations?4:1));
    double d=f.mode?50:2.2/scene.ray_step*(f.iterations?.25:1);
    double offset=((!f.mode&&!f.iterations?137:128)-sqrt(f.offset)*11.313708)*d*.28;
    double far=d*.7/(scene.zend-scene.zstart)*(128-sqrt(f.far_offset)*11.313708);
    double second=f.mode?.0005:scene.ray_step*.015*(f.iterations?4:1);
    Light light=scene.lights[f.light-1];double amplitude=f.mode?(fog_cache->positional?1000:300)*light.amplitude/scene.width:1;
        double ir=count*amplitude;
        /* RMcalcVLight / ConvertVLight: the original stores seven mantissa
         * bits plus an exponent, saturating its accumulator at 16383. */
        if(f.mode){unsigned value=(unsigned)lrint(clamp(ir,0,16383)),shift=0;while((value>>shift)>127)shift++;ir=(value>>shift)<<shift;}
        double amount=(ir-offset-far*depth)*grad;
        if(f.only_add)amount=fmax(0,amount);double intense=fmin(1,ir*second)*amount;
        if(f.blend){amount=clamp(amount,0,1);intense=clamp(intense,0,1);}
    Vec a={f.colors[0][0],f.colors[0][1],f.colors[0][2]},b={f.colors[1][0],f.colors[1][1],f.colors[1][2]};
    a=lighting_color(a);b=lighting_color(b);
    return add(mul(color,f.blend?1-amount:1),add(mul(a,amount-intense),mul(b,intense)));
}
/* Primary lighting remains in linear HDR until fog and final gamma/clipping. */
static Vec fog_shade_primary(Vec color,const SurfacePixel *surface) {
    size_t index=(size_t)(surface-surface_cache.pixels);
    double depth=surface->hit?surface->depth:scene.zend-scene.zstart;
    return fog_mix(color,fog_cache->integral[index],depth);
}
static Vec fog_secondary(Vec color,Vec origin,Vec ray,double depth) {
    if(scene.fog.mode>=2||scene.fog.strength==53||!fog_cache||!fog_cache->valid)return color;
    return fog_mix(color,fog_integrate(origin,ray,depth),depth);
}
static int apply_fog(RenderResult *result,int threads,int preview) {
    FogSettings f=scene.fog;if(f.mode>=2||f.strength==53||fog_in_shading)return 1;
    if(!surface_cache.pixels||!fog_prepare(threads,preview))return 0;
    for(int y=0;y<result->height&&!render_cancelled();y++)for(int x=0;x<result->width;x++){
        size_t n=(size_t)y*result->width+x;SurfacePixel s=surface_cache.pixels[n];double depth=s.hit?s.depth:scene.zend-scene.zstart;
        unsigned char *p=result->rgba+(size_t)y*result->stride+4*x;
        Vec color={0};double *channels[]={&color.x,&color.y,&color.z};
        for(int k=0;k<3;k++){
            double target=p[k]/255.,linear=target;
            if(scene.gamma<32){double a=1-scene.gamma/32.,b=1-a;linear=a>0?2*target/fmax(1e-30,b+sqrt(b*b+4*a*target)):target;}
            else if(scene.gamma>32){double a=(scene.gamma-32)/31.,b=1-a;double root=b>1e-12?2*target/(a+sqrt(a*a+4*b*target)):target/a;linear=root*root;}
            *channels[k]=internal_gamma2()?linear*linear:linear;
        }
        color=gamma_color(fog_mix(color,fog_cache->integral[n],depth));
        p[0]=lround(255*color.x);p[1]=lround(255*color.y);p[2]=lround(255*color.z);
    }
    return 1;
}
