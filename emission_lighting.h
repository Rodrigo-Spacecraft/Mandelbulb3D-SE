/* C-only one-bounce transport from the experimental red DIFS emitters.
   Cosine-weighted deterministic hemisphere sampling integrates emitter
   radiance directly: visibility and apparent solid angle supply falloff. */
static Vec emission_color(void){return (Vec){scene.fog.colors[0][0],scene.fog.colors[0][1],scene.fog.colors[0][2]};}
static double emission_ray(Vec origin,Vec direction,double eps){
    double t=0,maximum=fmax(eps*32,scene.zend-scene.zstart);
    for(int step=0;step<1024&&t<maximum&&!render_cancelled();step++){
        Vec p=add(origin,mul(direction,t));Sample s=evaluate(p);
        if(!isfinite(s.distance))return 0;
        if(s.smooth>=scene.iterations||s.distance<=eps*.5)return reflection_surface_difs(p)?4:0;
        t+=fmax(eps*.25,s.distance*.7);
    }return 0;
}
static double emission_red_irradiance(Vec point,Vec normal,double eps){
    if(scene.fog.mode!=2)return 0;
    int emitters=0;if(scene.program_enabled)for(int i=0;i<6;i++)if(scene.program.slots[i].count&&formula_difs(scene.program.slots[i].kind)){emitters=1;break;}
    if(!emitters)return 0;
    Vec axis=fabs(normal.z)<.9?(Vec){0,0,1}:(Vec){0,1,0};
    Vec tangent=unit((Vec){axis.y*normal.z-axis.z*normal.y,axis.z*normal.x-axis.x*normal.z,axis.x*normal.y-axis.y*normal.x});
    Vec bitangent={normal.y*tangent.z-normal.z*tangent.y,normal.z*tangent.x-normal.x*tangent.z,normal.x*tangent.y-normal.y*tangent.x};
    Vec origin=add(point,mul(normal,eps*2));double total=0;
    int saved=info_phase;info_phase=6;
    for(int i=0;i<64&&!render_cancelled();i++){
        unsigned bits=(unsigned)i;double radical=0,factor=.5;while(bits){radical+=(bits&1)*factor;bits>>=1;factor*=.5;}
        double r=sqrt((i+.5)/64.),angle=2*PI*radical;
        Vec direction=add(mul(normal,sqrt(1-r*r)),add(mul(tangent,r*cos(angle)),mul(bitangent,r*sin(angle))));
        total+=emission_ray(origin,direction,eps);
    }
    info_phase=saved;return total/64;
}
