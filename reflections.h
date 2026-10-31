/* Native deterministic secondary-ray transport. Called after primary lighting,
 * before DoF. Primary geometry/shadow caches remain reusable. */
static int reflection_group_difs(FormulaProgram p,int begin,int end){
    for(int i=begin;i<=end;i++)if(p.slots[i].count&&formula_difs(p.slots[i].kind))return 1;return 0;
}
static int reflection_surface_difs(Vec point){
    if(!scene.program_enabled)return 0;FormulaProgram p=scene.program;
    int aD=reflection_group_difs(p,0,p.mode==2?p.split-1:7);
    if(p.mode!=2)return aD;int bD=reflection_group_difs(p,p.split,7);
    if(aD==bD)return aD;if(p.combine==5)return bD;
    OrbitResult a=program_part(point,p,0,p.split-1,p.repeat_from,scene.iterations),b=program_part(point,p,p.split,7,p.repeat2,p.max_iterations2);
    double da=a.inside?-fmax(1e-12,a.sample.distance):a.sample.distance,db=b.inside?-fmax(1e-12,b.sample.distance):b.sample.distance;
    /* Select the contributor to the actual Boolean surface, rather than
       enabling transparency everywhere merely because a DIFS slot exists. */
    if(p.combine==1)return da>=db?aD:bD;
    if(p.combine==2)return da>=-db?aD:bD;
    return da<=db?aD:bD;
}
static double reflection_offset(double eps){return fmax(eps*.5,1e-12);}
static int reflection_refract(Vec ray,Vec normal,double eta,Vec *out){
    double cosine=clamp(-dot(ray,normal),0,1),k=1-eta*eta*(1-cosine*cosine);if(k<0)return 0;
    *out=unit(add(mul(ray,eta),mul(normal,eta*cosine-sqrt(k))));return 1;
}
/* Unpolarized dielectric Fresnel reflectance, as in the original CalcSR.
 * Zero material opacity still retains glass's physical surface reflection. */
static double reflection_fresnel(double cosine,double eta){
    cosine=clamp(cosine,0,1);double k=1-eta*eta*(1-cosine*cosine);if(k<=0)return 1;double transmitted=sqrt(k);
    double a=eta*cosine+transmitted,b=cosine+eta*transmitted;if(a==0||b==0)return 1;
    double rs=(eta*cosine-transmitted)/a,rp=(cosine-eta*transmitted)/b;return clamp((rs*rs+rp*rp)*.5,0,1);
}
static double reflection_inverse_channel(double v){
    v=clamp(v,0,1);if(scene.gamma==32)return v;
    if(scene.gamma<32){double t=1-scene.gamma/32.;return t>1e-12?2*v/(1-t+sqrt((1-t)*(1-t)+4*t*v)):v;}
    double t=(scene.gamma-32)/31.;if(t>=1)return v*v;double root=2*v/(t+sqrt(t*t+4*(1-t)*v));return root*root;
}
static Vec reflection_linear(Vec c){return lighting_color((Vec){reflection_inverse_channel(c.x),reflection_inverse_channel(c.y),reflection_inverse_channel(c.z)});}
/* Within a transparent DIFS union, the escape-time component remains an
 * opaque object, even though the union's distance is zero throughout the medium. */
static int reflection_opaque_part(void){
    FormulaProgram p=scene.program;
    if(!scene.program_enabled||!scene.reflections.only_difs||p.mode!=2||p.combine!=0)return -1;
    int a=reflection_group_difs(p,0,p.split-1),b=reflection_group_difs(p,p.split,7);
    return a==b?-1:a?1:0;
}
static Sample reflection_part_sample(Vec point,int part){
    FormulaProgram p=scene.program;return program_part(point,p,part?p.split:0,part?7:p.split-1,part?p.repeat2:p.repeat_from,part?p.max_iterations2:scene.iterations).sample;
}
static int reflection_hit(Vec origin,Vec direction,int inside,double eps,SurfacePixel *hit,int *opaque){
    *opaque=0;int part=inside?reflection_opaque_part():-1;
    double t=0,previous=0,maximum=fmax(eps*32,scene.zend-scene.zstart);
    for(int step=0;step<10000&&t<maximum&&!render_cancelled();step++){
        Vec p=add(origin,mul(direction,t));Sample sample=evaluate(p),object={0};int occupied=sample.smooth>=scene.iterations||sample.distance<=eps;
        int objectHit=0;if(part>=0){object=reflection_part_sample(p,part);objectHit=object.smooth>=scene.iterations||object.distance<=eps;}
        if(objectHit||(!inside&&occupied)||(inside&&!occupied)){
            double lo=previous,hi=t;for(int i=0;i<12&&hi>lo;i++){double m=(lo+hi)*.5;Vec q=add(origin,mul(direction,m));Sample s=objectHit?reflection_part_sample(q,part):evaluate(q);int solid=s.smooth>=scene.iterations||s.distance<=eps;if(objectHit?!solid:solid==inside)lo=m;else hi=m;}
            t=(lo+hi)*.5;*hit=(SurfacePixel){.point=add(origin,mul(direction,t)),.ray=direction,.depth=t,.eps=eps,.hit=1};
            if(objectHit){*opaque=1;double h=fmax(eps*.15,1e-12);Vec q=hit->point;double d=reflection_part_sample(q,part).distance;Vec gradient={reflection_part_sample(add(q,(Vec){h,0,0}),part).distance-d,reflection_part_sample(add(q,(Vec){0,h,0}),part).distance-d,reflection_part_sample(add(q,(Vec){0,0,h}),part).distance-d};hit->normal=unit(gradient);hit->sample=reflection_part_sample(q,part);hit->prepared=1;}
            return 1;
        }
        previous=t;double distance=inside?fabs(sample.distance):fmax(0,sample.distance);if(part>=0)distance=fmin(distance,fmax(0,object.distance));t+=fmax(inside?fmax(eps*.75,maximum/10000):eps*.75,distance*scene.ray_step);
    }return 0;
}
static Vec reflection_transport(SurfacePixel s,Vec base,Vec highlight,int remaining,int inside,int *budget);
static Vec reflection_ray(Vec origin,Vec direction,int inside,double eps,int remaining,int *budget,double *travel){
    *travel=0;if(*budget<=0||render_cancelled())return reflection_linear(shade(origin,direction,clamp(camera_unrotate(direction).y*.5+.5,0,1),scene.zend-scene.zstart,eps,0,scene.width,scene.height,NULL,NULL,NULL));
    --*budget;SurfacePixel hit;int opaque;
    if(!reflection_hit(origin,direction,inside,eps,&hit,&opaque))return fog_secondary(reflection_linear(shade(origin,direction,clamp(camera_unrotate(direction).y*.5+.5,0,1),scene.zend-scene.zstart,eps,0,scene.width,scene.height,NULL,NULL,NULL)),origin,direction,scene.zend-scene.zstart);
    *travel=hit.depth;
    Vec color=reflection_linear(shade(hit.point,direction,clamp(camera_unrotate(direction).y*.5+.5,0,1),hit.depth,eps,1,scene.width,scene.height,NULL,NULL,opaque?&hit:NULL));
    if(!opaque)color=reflection_transport(hit,color,last_specular_lighting,remaining,inside,budget);
    return fog_secondary(color,origin,direction,hit.depth);
}
static double reflection_palette_opacity(Sample sample,double depth,int channel){
    ReflectionSettings rf=scene.reflections;if(!rf.opacity_set)return 0; /* legacy global transmission */
    double gradient=color_gradient(sample.smooth,sample.orbit_trap);
    double pos=(gradient-scene.cstart)*32768/scene.cspan+scene.col_z*depth*16384;if(scene.cycle){pos=fmod(pos,32768);if(pos<0)pos+=32768;}
    if(pos>=scene.stops[9].position){double span=32767.-scene.stops[9].position,t=scene.cycle&&!scene.no_interpolation&&span>0?clamp((pos-scene.stops[9].position)/span,0,1):0;return rf.opacity[channel][9]*(1-t)+rf.opacity[channel][0]*t;}int b=1;if(pos<=scene.stops[0].position)b=0;else while(b<9&&pos>scene.stops[b].position)b++;int a=b?b-1:0;double span=scene.stops[b].position-scene.stops[a].position,t=span>0?clamp((pos-scene.stops[a].position)/span,0,1):0;if(scene.no_interpolation)t=0;return rf.opacity[channel][a]*(1-t)+rf.opacity[channel][b]*t;
}
static Vec reflection_transport(SurfacePixel s,Vec base,Vec highlight,int remaining,int inside,int *budget){
    if(!remaining||*budget<=0||render_cancelled())return base;
    if(scene.reflections.only_difs&&!reflection_surface_difs(s.point))return base;
    double roughness=0;Vec normal=s.prepared?s.normal:surface_normal(s.point,s.eps*.15,&roughness);if(dot(normal,s.ray)>0)normal=mul(normal,-1);
    Sample sample=s.prepared?s.sample:surface_color_sample(s.point,s.eps);Vec dif,spec;palette(sample.smooth,sample.orbit_trap,s.depth,&dif,&spec);
    ReflectionSettings rf=scene.reflections;double diffuseOpacity=rf.opacity_set?reflection_palette_opacity(sample,s.depth,0):1,specularOpacity=rf.opacity_set?reflection_palette_opacity(sample,s.depth,1):1;Vec amount=mul(spec,rf.amount);
    if(rf.transparency&&rf.opacity_set){double transmission=rf.amount*(1-diffuseOpacity*specularOpacity);amount=(Vec){fmax(amount.x,transmission),fmax(amount.y,transmission),fmax(amount.z,transmission)};}amount=(Vec){clamp(amount.x,0,1),clamp(amount.y,0,1),clamp(amount.z,0,1)};
    if(fmax(amount.x,fmax(amount.y,amount.z))<.0001)return base;
    /* Palette opacity controls transmission. Fully opaque stops remain
       reflective; zero-opacity glass retains physical Fresnel reflection. */
    int transmit=rf.transparency&&(!rf.opacity_set||diffuseOpacity*specularOpacity<1);Vec transmitted={0};double fresnel=1;
    /* Hits lie on the eps isosurface. A large offset can jump completely
       across a thin DIFS shell, losing its entry/exit refraction pair. */
    double offset=reflection_offset(s.eps);Vec refracted;
    if(transmit&&reflection_refract(s.ray,normal,inside?rf.refractive_index:1/rf.refractive_index,&refracted)){
        fresnel=reflection_fresnel(-dot(s.ray,normal),inside?rf.refractive_index:1/rf.refractive_index);if(rf.opacity_set)fresnel+=(1-fresnel)*diffuseOpacity*specularOpacity;
        double distance;transmitted=reflection_ray(add(s.point,mul(refracted,offset)),refracted,!inside,s.eps,remaining-1,budget,&distance);
        if(!inside){Vec attenuation={exp(-rf.absorption*distance*fmax(0,1-dif.x)),exp(-rf.absorption*distance*fmax(0,1-dif.y)),exp(-rf.absorption*distance*fmax(0,1-dif.z))};Vec scatter=mul(product(dif,(Vec){1-attenuation.x,1-attenuation.y,1-attenuation.z}),(-expm1(-fmin(700,rf.scattering*distance)))*.1);transmitted=add(product(transmitted,attenuation),scatter);}
    }
    Vec reflected={0};if(fresnel>.0001){Vec direction=unit(add(s.ray,mul(normal,-2*dot(s.ray,normal))));double distance;reflected=reflection_ray(add(s.point,mul(direction,offset)),direction,inside,s.eps,remaining-1,budget,&distance);}
    Vec transported=add(mul(reflected,fresnel),mul(transmitted,1-fresnel));return add(product(base,(Vec){1-amount.x,1-amount.y,1-amount.z}),product(amount,add(transported,highlight)));
}
typedef struct {RenderResult *result;atomic_int row;} ReflectionJob;
static void *reflection_worker(void *arg){
    INFO_WORKER;INFO_PHASE(6);
    ReflectionJob *job=arg;RenderResult *r=job->result;reflection_secondary=1;
    for(;;){int y=atomic_fetch_add(&job->row,1);if(y>=r->height||render_cancelled())break;
        for(int x=0;x<r->width&&!render_cancelled();x++){SurfacePixel s=surface_cache.pixels[y*r->width+x];if(!s.hit)continue;unsigned char *p=r->rgba+y*r->stride+x*4;Vec base=reflection_linear((Vec){p[0]/255.,p[1]/255.,p[2]/255.});int budget=128;
            reflection_cached_lighting=1;shade(s.point,s.ray,(y+.5)/r->height,s.depth,s.eps,1,r->width,r->height,NULL,NULL,&s);Vec highlight=last_specular_lighting;reflection_cached_lighting=0;
            Vec color=gamma_color(reflection_transport(s,base,highlight,scene.reflections.depth,scene.program_enabled&&scene.program.render_mode==1,&budget));p[0]=(unsigned char)lround(255*clamp(color.x,0,1));p[1]=(unsigned char)lround(255*clamp(color.y,0,1));p[2]=(unsigned char)lround(255*clamp(color.z,0,1));
        }
        if(active_cancel)atomic_fetch_add(&active_cancel->rows,1);
    }reflection_secondary=0;return NULL;
}
static int apply_reflections(RenderResult *r,int threads){
    if(!scene.reflections.enabled||scene.reflections.amount==0)return 1;if(!surface_cache.pixels)return 0;
    if(threads<1){long n=sysconf(_SC_NPROCESSORS_ONLN);threads=(int)fmax(1,fmin(256,n));}threads=threads>r->height?r->height:threads;
    ReflectionJob job={.result=r};atomic_init(&job.row,0);pthread_t workers[255];int started=0;
    for(int i=1;i<threads;i++)if(!pthread_create(&workers[started],NULL,reflection_worker,&job))started++;
    reflection_worker(&job);for(int i=0;i<started;i++)pthread_join(workers[i],NULL);return 1;
}
