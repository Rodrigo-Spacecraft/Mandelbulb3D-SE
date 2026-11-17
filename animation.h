/* Native animation interpolation. LGPL-2.1-or-later. */
#ifndef MB3DX_ANIMATION_H
#define MB3DX_ANIMATION_H
#include "renderer.h"
#include <math.h>
static inline double animation_lerp(double a,double b,double t){return a+(b-a)*t;}
static inline double animation_positive(double a,double b,double t){return a>0&&b>0?exp(animation_lerp(log(a),log(b),t)):animation_lerp(a,b,t);}
static inline double animation_angle(double a,double b,double t,double turn){return a+remainder(b-a,turn)*t;}
static inline void animation_quaternion(const double m[9],double q[4]){
    double trace=m[0]+m[4]+m[8];
    if(trace>0){double s=sqrt(trace+1)*2;q[0]=s*.25;q[1]=(m[7]-m[5])/s;q[2]=(m[2]-m[6])/s;q[3]=(m[3]-m[1])/s;}
    else{int i=m[4]>m[0]?1:0;if(m[8]>m[i*3+i])i=2;int j=(i+1)%3,k=(i+2)%3;double s=sqrt(fmax(0,1+m[i*3+i]-m[j*3+j]-m[k*3+k]))*2;
        if(s<1e-12){q[0]=1;q[1]=q[2]=q[3]=0;return;}q[0]=(m[k*3+j]-m[j*3+k])/s;q[i+1]=s*.25;q[j+1]=(m[i*3+j]+m[j*3+i])/s;q[k+1]=(m[i*3+k]+m[k*3+i])/s;}
    double n=sqrt(q[0]*q[0]+q[1]*q[1]+q[2]*q[2]+q[3]*q[3]);for(int i=0;i<4;i++)q[i]/=n;
}
static inline void animation_axes(const double a[9],const double b[9],double t,double m[9]){
    double p[4],q[4],r[4],dot=0;animation_quaternion(a,p);animation_quaternion(b,q);for(int i=0;i<4;i++)dot+=p[i]*q[i];
    if(dot<0){dot=-dot;for(int i=0;i<4;i++)q[i]=-q[i];}dot=fmin(1,dot);
    double angle=acos(dot),s=sin(angle),left=s>1e-8?sin((1-t)*angle)/s:1-t,right=s>1e-8?sin(t*angle)/s:t,n=0;
    for(int i=0;i<4;i++){r[i]=left*p[i]+right*q[i];n+=r[i]*r[i];}for(int i=0;i<4;i++)r[i]/=sqrt(n);
    double w=r[0],x=r[1],y=r[2],z=r[3];double matrix[]={1-2*(y*y+z*z),2*(x*y-z*w),2*(x*z+y*w),2*(x*y+z*w),1-2*(x*x+z*z),2*(y*z-x*w),2*(x*z-y*w),2*(y*z+x*w),1-2*(x*x+y*y)};for(int i=0;i<9;i++)m[i]=matrix[i];
}
static inline RenderOptions animation_interpolate(RenderOptions a,RenderOptions b,double t){
    if(t<=0)return a;if(t>=1)return b;RenderOptions r=a;
#define ANI(field) r.field=animation_lerp(a.field,b.field,t)
#define ANG(field,turn) r.field=animation_angle(a.field,b.field,t,turn)
    r.gamma_override=a.gamma_override||b.gamma_override;r.gamma=animation_lerp(a.gamma_override?a.gamma:32,b.gamma_override?b.gamma:32,t);
    r.rotation4_override=a.rotation4_override||b.rotation4_override;
    for(int i=0;i<3;i++){ANI(camera.origin[i]);ANI(julia_c[i]);ANG(rotation4[i],6.283185307179586);}ANI(julia_w);animation_axes(a.camera.axes,b.camera.axes,t,r.camera.axes);
    r.camera.zoom=animation_positive(a.camera.zoom,b.camera.zoom,t);r.camera.distance=animation_positive(a.camera.distance,b.camera.distance,t);ANI(camera.fov);
    r.de_stop=animation_positive(a.de_stop/a.width,b.de_stop/b.width,t)*r.width;r.ray_step=animation_positive(a.ray_step,b.ray_step,t);
    r.iterations=(int)lround(animation_lerp(a.iterations,b.iterations,t));
    if(a.program.mode==b.program.mode&&a.program.split==b.program.split&&a.program.repeat_from==b.program.repeat_from&&a.program.repeat2==b.program.repeat2){
        r.program.bailout=animation_positive(a.program.bailout,b.program.bailout,t);ANI(program.smooth);ANI(program.formula_power);
        for(int i=0;i<8;i++)if(a.program.slots[i].kind==b.program.slots[i].kind){
            int kind=a.program.slots[i].kind;
            for(int j=0;j<formula_parameter_count(kind);j++){
                const FormulaParameter *spec=formula_parameter(kind,j);double x=formula_slot_value(a.program.slots[i],j),y=formula_slot_value(b.program.slots[i],j),v=animation_lerp(x,y,t);
                if(spec->integer)v=round(v);formula_slot_set_value(&r.program.slots[i],j,v);
            }
        }
    }
    ANI(shadows.hard_length);ANI(shadows.hard_radius);ANI(shadows.ambient_length);ANI(shadows.ambient_strength);
    ANI(ambient.strength);ANI(ambient.depth);ANI(ambient.second_reflection);ANI(ambient.diffuse_shadow);ANI(ambient.roughness);
    for(int i=0;i<4;i++)for(int j=0;j<3;j++){ANI(ambient.colors[i][j]);}
    ANI(object.map.offset_x);ANI(object.map.offset_y);ANG(object.map.rotation,360);r.object.map.scale=animation_positive(a.object.map.scale,b.object.map.scale,t);
    ANI(object.diffuse);ANI(object.specular);ANI(object.palette_start);ANI(object.palette_end);ANI(object.z_variation);
    for(int i=0;i<10;i++){r.object.stops[i].position=(unsigned)lround(animation_lerp(a.object.stops[i].position,b.object.stops[i].position,t));for(int j=0;j<3;j++){ANI(object.stops[i].diffuse[j]);ANI(object.stops[i].specular[j]);}}
    for(int i=0;i<6;i++)if((a.lights[i].option&4)==(b.lights[i].option&4)){
        ANI(lights[i].amplitude);for(int j=0;j<3;j++){ANI(lights[i].color[j]);if(!(a.lights[i].option&4)&&j<2){ANG(lights[i].position[j],6.283185307179586);}else{ANI(lights[i].position[j]);}}
    }
    if(a.reflections.opacity_set||b.reflections.opacity_set){r.reflections.opacity_set=1;for(int c=0;c<2;c++)for(int i=0;i<10;i++)r.reflections.opacity[c][i]=animation_lerp(a.reflections.opacity_set?a.reflections.opacity[c][i]:1,b.reflections.opacity_set?b.reflections.opacity[c][i]:1,t);}
    ANI(reflections.amount);ANI(reflections.absorption);ANI(reflections.refractive_index);ANI(reflections.scattering);ANI(transmission_blur);ANI(translucency_glow);
    r.translucency_glow=fmax(-1,fmin(1,r.translucency_glow));
    r.transmission_blur=fmax(0,fmin(2,r.transmission_blur));
    ANI(ssao.threshold);ANI(ssao.mirror);ANI(color_multiplier);
    ANI(fog.strength);ANI(fog.offset);ANI(fog.far_offset);
    for(int c=0;c<2;c++)for(int i=0;i<3;i++){ANI(fog.colors[c][i]);}
    ANI(dof.focus1);ANI(dof.focus2);ANI(dof.aperture);r.dof.clip_radius=animation_lerp(a.dof.clip_radius/a.width,b.dof.clip_radius/b.width,t)*r.width;
#undef ANI
#undef ANG
    return r;
}
/* Original Interpolation.pas: midpoint quadratic Bezier, with its time
   coordinate inverted using the neighboring keyframe durations. */
/* Convex Bezier weights cannot exceed the source range. Preserve that
   invariant against rounding (notably fully opaque alpha becoming 1+epsilon). */
static inline double animation_weighted(double a,double b,double c,double x,double y,double z){double lo=fmin(a,fmin(b,c)),hi=fmax(a,fmax(b,c));return fmax(lo,fmin(hi,a*x+b*y+c*z));}
static inline double animation_positive3(double a,double b,double c,double x,double y,double z){double lo=fmin(a,fmin(b,c)),hi=fmax(a,fmax(b,c));double v=a>0&&b>0&&c>0?exp(animation_weighted(log(a),log(b),log(c),x,y,z)):animation_weighted(a,b,c,x,y,z);return fmax(lo,fmin(hi,v));}
static inline double animation_angle3(double a,double b,double c,double x,double y,double z,double turn){a=b+remainder(a-b,turn);c=b+remainder(c-b,turn);return animation_weighted(a,b,c,x,y,z);}
static inline double animation_bezier_time(double t,double previous,double current,double next){
    previous=fmax(1,previous);current=fmax(1,current);next=fmax(1,next);
    double x1=t>=.5?current*.5:-previous*.5,x2=t>=.5?current:0,x3=t>=.5?current+next*.5:current*.5;
    double d=x1-2*x2+x3,delta=current*t-x1,u;
    if(fabs(d)<.0001)u=delta/(x3-x1);
    else{double b=x1-x2,root=sqrt(fabs(b*b+d*delta));u=(b+root)/d;if(u<0||u>1)u=(b-root)/d;}
    return fmax(0,fmin(1,u));
}
static inline RenderOptions animation_bezier_blend(RenderOptions a,RenderOptions b,RenderOptions c,RenderOptions base,double u){
    double w1=.5*(1-u)*(1-u),w3=.5*u*u,w2=1-w1-w3;RenderOptions r=base;
#define ANI(field) r.field=animation_weighted(a.field,b.field,c.field,w1,w2,w3)
#define ANG(field,turn) r.field=animation_angle3(a.field,b.field,c.field,w1,w2,w3,turn)
    r.gamma_override=a.gamma_override||b.gamma_override||c.gamma_override;r.gamma=animation_weighted(a.gamma_override?a.gamma:32,b.gamma_override?b.gamma:32,c.gamma_override?c.gamma:32,w1,w2,w3);
    r.rotation4_override=a.rotation4_override||b.rotation4_override||c.rotation4_override;
    for(int i=0;i<3;i++){ANI(camera.origin[i]);ANI(julia_c[i]);ANG(rotation4[i],6.283185307179586);}ANI(julia_w);double ab[9],bc[9],left[9],right[9];animation_axes(a.camera.axes,b.camera.axes,.5,ab);animation_axes(b.camera.axes,c.camera.axes,.5,bc);animation_axes(ab,b.camera.axes,u,left);animation_axes(b.camera.axes,bc,u,right);animation_axes(left,right,u,r.camera.axes);
    r.camera.zoom=animation_positive3(a.camera.zoom,b.camera.zoom,c.camera.zoom,w1,w2,w3);r.camera.distance=animation_weighted(a.camera.distance,b.camera.distance,c.camera.distance,w1,w2,w3);ANI(camera.fov);
    r.de_stop=animation_weighted(a.de_stop/a.width,b.de_stop/b.width,c.de_stop/c.width,w1,w2,w3)*r.width;r.ray_step=animation_weighted(a.ray_step,b.ray_step,c.ray_step,w1,w2,w3);
    r.iterations=(int)lround(animation_weighted(a.iterations,b.iterations,c.iterations,w1,w2,w3));
    if(a.program.mode==b.program.mode&&a.program.split==b.program.split&&a.program.repeat_from==b.program.repeat_from&&a.program.repeat2==b.program.repeat2&&b.program.mode==c.program.mode&&b.program.split==c.program.split&&b.program.repeat_from==c.program.repeat_from&&b.program.repeat2==c.program.repeat2){
        r.program.bailout=animation_positive3(a.program.bailout,b.program.bailout,c.program.bailout,w1,w2,w3);ANI(program.smooth);ANI(program.formula_power);
        for(int i=0;i<6;i++)if(a.program.slots[i].kind==b.program.slots[i].kind&&b.program.slots[i].kind==c.program.slots[i].kind){
            int kind=a.program.slots[i].kind;
            for(int j=0;j<formula_parameter_count(kind);j++){
                const FormulaParameter *spec=formula_parameter(kind,j);double x=formula_slot_value(a.program.slots[i],j),y=formula_slot_value(b.program.slots[i],j),v=animation_weighted(x,y,formula_slot_value(c.program.slots[i],j),w1,w2,w3);
                if(spec->integer)v=round(v);formula_slot_set_value(&r.program.slots[i],j,v);
            }
        }
    }
    ANI(shadows.hard_length);ANI(shadows.hard_radius);ANI(shadows.ambient_length);ANI(shadows.ambient_strength);
    ANI(ambient.strength);ANI(ambient.depth);ANI(ambient.second_reflection);ANI(ambient.diffuse_shadow);ANI(ambient.roughness);
    for(int i=0;i<4;i++)for(int j=0;j<3;j++){ANI(ambient.colors[i][j]);}
    ANI(object.map.offset_x);ANI(object.map.offset_y);ANG(object.map.rotation,360);r.object.map.scale=animation_positive3(a.object.map.scale,b.object.map.scale,c.object.map.scale,w1,w2,w3);
    ANI(object.diffuse);ANI(object.specular);ANI(object.palette_start);ANI(object.palette_end);ANI(object.z_variation);
    for(int i=0;i<10;i++){r.object.stops[i].position=(unsigned)lround(animation_weighted(a.object.stops[i].position,b.object.stops[i].position,c.object.stops[i].position,w1,w2,w3));for(int j=0;j<3;j++){ANI(object.stops[i].diffuse[j]);ANI(object.stops[i].specular[j]);}}
    for(int i=0;i<6;i++)if((a.lights[i].option&4)==(b.lights[i].option&4)&&(b.lights[i].option&4)==(c.lights[i].option&4)){
        ANI(lights[i].amplitude);for(int j=0;j<3;j++){ANI(lights[i].color[j]);if(!(a.lights[i].option&4)&&j<2){ANG(lights[i].position[j],6.283185307179586);}else{ANI(lights[i].position[j]);}}
    }
    if(a.reflections.opacity_set||b.reflections.opacity_set||c.reflections.opacity_set){r.reflections.opacity_set=1;for(int ch=0;ch<2;ch++)for(int i=0;i<10;i++)r.reflections.opacity[ch][i]=animation_weighted(a.reflections.opacity_set?a.reflections.opacity[ch][i]:1,b.reflections.opacity_set?b.reflections.opacity[ch][i]:1,c.reflections.opacity_set?c.reflections.opacity[ch][i]:1,w1,w2,w3);}
    ANI(reflections.amount);ANI(reflections.absorption);ANI(reflections.refractive_index);ANI(reflections.scattering);ANI(transmission_blur);ANI(translucency_glow);
    r.translucency_glow=fmax(-1,fmin(1,r.translucency_glow));
    r.transmission_blur=fmax(0,fmin(2,r.transmission_blur));
    ANI(ssao.threshold);ANI(ssao.mirror);ANI(color_multiplier);
    ANI(fog.strength);ANI(fog.offset);ANI(fog.far_offset);
    for(int ch=0;ch<2;ch++)for(int i=0;i<3;i++){ANI(fog.colors[ch][i]);}
    ANI(dof.focus1);ANI(dof.focus2);ANI(dof.aperture);r.dof.clip_radius=animation_weighted(a.dof.clip_radius/a.width,b.dof.clip_radius/b.width,c.dof.clip_radius/c.width,w1,w2,w3)*r.width;
#undef ANI
#undef ANG
    return r;
}
#endif
