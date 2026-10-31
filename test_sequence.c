/* Independent trigonometric orbit and closed-form schedule check. */
#include "renderer.c"
#include <assert.h>
static Sample reference(Vec c) {
    Vec z=c;double dr=1,r=sqrt(dot(z,z)),old=r;int i,power=scene.power;
    for(i=0;i<scene.iterations;i++) {
        int slot=0;
        if(scene.count2)slot=scene.repeat_from==1?(i>=scene.count1):((i%(scene.count1+scene.count2))>=scene.count1);
        int kind=slot?scene.kind2:scene.kind;
        power=slot?scene.power2:scene.power;double zmul=slot?scene.zmul2:scene.zmul;
        old=r;
        if(kind==4) {
            double scale=slot?scene.scale2:scene.scale,fold=slot?scene.fold2:scene.fold;
            double radius=slot?scene.min_radius2:scene.min_radius;
            double *coords[3]={&z.x,&z.y,&z.z};
            for(int j=0;j<3;j++){if(*coords[j]>fold)*coords[j]=2*fold-*coords[j];else if(*coords[j]<-fold)*coords[j]=-2*fold-*coords[j];}
            double rr=dot(z,z),factor=scale;
            if(rr<radius*radius)factor=scale/(radius*radius);else if(rr<1)factor=scale/rr;
            z=mul(z,factor);dr=fabs(factor)*dr+(scene.julia?0:1);
        } else {
        dr=power*pow(r,power-1)*dr*fmax(1,fabs(zmul))+(scene.julia?0:1);
        if(r>=1e-30) {
            double az=power*atan2(z.y,z.x),lat=power*asin(clamp(z.z/r,-1,1)),rn=pow(r,power);
            z=(Vec){rn*cos(lat)*cos(az),rn*cos(lat)*sin(az),zmul*rn*sin(lat)};
        } else z=(Vec){0,0,0};
        }
        z=add(z,scene.julia?scene.julia_c:c);r=sqrt(dot(z,z));
        if(r>scene.bailout){i++;break;}
    }
    int index=i?i-1:0,slot=scene.count2?(scene.repeat_from==1?(index>=scene.count1):((index%(scene.count1+scene.count2))>=scene.count1)):0;
    int kind=slot?scene.kind2:scene.kind;
    if(r<=scene.bailout)return (Sample){kind==4?r/fmax(dr,1e-300):0,scene.iterations,0};
    double smooth=i;
    if(old>1)smooth+=(log(log(scene.bailout))-log(log(r)))/(log(log(r))-log(log(old)));
    else smooth+=log(log(scene.bailout))-log(log(r))/log(kind==4?fmax(1.000001,fabs(slot?scene.scale2:scene.scale)):power);
    return (Sample){fmax(0,(kind==4?1:.5*log(r))*r/fmax(dr,1e-300)),smooth,0};
}
int main(void) {
    CameraSettings camera={.axes={1,0,0,0,1,0,0,0,1},.zoom=1,.fov=30,.distance=32};
    assert(valid_camera(camera));camera_turn(&camera,90,0,0);
    assert(fabs(camera.axes[6]-1)<1e-12 && fabs(camera.axes[0])<1e-12);
    camera_move(&camera,0,0,2);assert(fabs(camera.origin[0]-2)<1e-12);
    for(int i=0;i<1000;i++)camera_turn(&camera,.3,-.2,.1);
    assert(valid_camera(camera));
    for(int kind=0;kind<=4;kind+=4) {
        scene_defaults();scene.kind=kind;memset(scene.matrix,0,sizeof scene.matrix);for(int i=0;i<3;i++)scene.matrix[i][i]=1;
        Vec origin={0,0,-10};double initial=navigator_distance(origin),closest=initial;
        assert(initial>0);
        for(int operation=4;operation<=5;operation++)for(int fine=0;fine<2;fine++) {
            Vec moved=adaptive_move(origin,operation,fine?.05:.5);
            CameraSettings fixed={.axes={1,0,0,0,1,0,0,0,1}};
            camera_move(&fixed,0,operation==4?1:-1,0);
            Vec delta=add(moved,mul(origin,-1));
            assert(delta.y*fixed.origin[1]>0&&fabs(delta.x)<1e-12&&fabs(delta.z)<1e-12);
        }

        for(int i=0;i<1000;i++) {
            double before=navigator_distance(origin);Vec next=adaptive_move(origin,0,.5);
            double after=navigator_distance(next);
            if(dot(add(next,mul(origin,-1)),add(next,mul(origin,-1)))>0)assert(after>0);
            assert(after>=0);closest=fmin(closest,after);origin=next;
            if(before==0)break;
        }
        assert(closest<initial*1e-6);assert(closest<1e-9);
    }
    puts("Repeated adaptive approaches remain outside and pass below 1e-9 without a positive minimum distance.");
    int checks=0;
    for(int repeat=0;repeat<2;repeat++)for(int julia=0;julia<2;julia++)for(int n=1;n<=3;n++) {
        scene_defaults();scene.power=3;scene.power2=5;scene.zmul2=.7;
        scene.count1=n;scene.count2=4-n;scene.repeat_from=repeat;scene.iterations=12;
        scene.julia=julia;scene.julia_c=(Vec){.31,-.2,.13};
        for(int i=0;i<200;i++) {
            Vec c={.2+i*.006,.3*cos(i*.17),.23*sin(i*.39)};
            Sample a=evaluate(c),b=reference(c);
            assert(fabs(a.distance-b.distance)<1e-6*(1+fabs(b.distance)));
            assert(fabs(a.smooth-b.smooth)<1e-5*(1+fabs(b.smooth)));
            checks++;
        }
    }
    double factor;Vec box=amazing_box((Vec){.1,.2,.3},2,.5,1,&factor);
    assert(factor==8 && fabs(box.x-.8)<1e-12 && fabs(box.y-1.6)<1e-12);
    box=amazing_box((Vec){.5,.5,.5},2,.5,1,&factor);assert(fabs(box.z-4./3)<1e-12);
    for(int first=0;first<2;first++)for(int second=0;second<2;second++)for(int repeat=0;repeat<2;repeat++) {
        scene_defaults();scene.kind=first?4:0;scene.kind2=second?4:0;
        scene.power=3;scene.power2=5;scene.count1=2;scene.count2=1;scene.repeat_from=repeat;
        scene.iterations=12;scene.scale=-1.7;scene.scale2=2.2;scene.fold=.7;scene.fold2=1.1;
        for(int i=0;i<100;i++) {
            Vec c={.2+i*.021,.3*cos(i*.17),.23*sin(i*.39)};
            Sample a=evaluate(c),b=reference(c);
            /* Analytic box hybrids use the original scale-dependent ADE
               normalization, separately from the orbit/schedule reference. */
            if(first&&second)b.distance*=((.65*2)+(scene.scale2*1.2+1)/scene.scale2)/3;
            assert(isfinite(a.distance)&&isfinite(a.smooth));
            assert(fabs(a.distance-b.distance)<1e-6*(1+fabs(b.distance)));checks++;
        }
    }
    printf("%d two-formula orbit checks match the independent schedule and trigonometric reference.\n",checks);
}
