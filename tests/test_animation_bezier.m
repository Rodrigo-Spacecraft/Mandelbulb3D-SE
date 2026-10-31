#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
static NSDictionary *key(double x,int frames){RenderOptions o={0};o.width=640;o.height=480;o.camera.zoom=1;o.camera.distance=32;o.de_stop=1;o.ray_step=.5;o.camera.axes[0]=o.camera.axes[4]=o.camera.axes[8]=1;o.camera.origin[0]=x;return @{@"frames":@(frames),@"settings":[NSData dataWithBytes:&o length:sizeof o],@"path":@""};}
static double position(AppDelegate *a,NSArray *keys,int frame,BOOL loop){return [a animationOptionsAtFrame:frame keys:keys loop:loop ease:YES path:NULL].camera.origin[0];}
int main(void){@autoreleasepool{
 for(int n=0;n<=10000;n++){double u=n/10000.,w1=.5*(1-u)*(1-u),w3=.5*u*u,w2=1-w1-w3;assert(animation_weighted(1,1,1,w1,w2,w3)==1);assert(animation_weighted(.1,.1,.1,w1,w2,w3)==.1);double v=animation_weighted(0,1,1,w1,w2,w3);assert(v>=0&&v<=1);assert(animation_positive3(.1,.1,.1,w1,w2,w3)==.1);}
 AppDelegate *a=[AppDelegate new];NSArray *keys=@[key(0,10),key(10,10),key(20,10),key(30,10)];
 for(int f=5;f<=25;f++)assert(fabs(position(a,keys,f,NO)-f)<1e-10);
 keys=@[key(0,5),key(5,15),key(20,10),key(30,10)];
 for(int f=3;f<=24;f++)assert(fabs(position(a,keys,f,NO)-f)<1e-9);
 // Independent inverse-time oracle: de Casteljau on the time control points.
 for(int prev=1;prev<=31;prev+=5)for(int cur=1;cur<=31;cur+=7)for(int next=1;next<=31;next+=9)for(int n=0;n<=100;n++){
 double t=n/100.,x=t>=.5?cur*.5:-prev*.5,y=t>=.5?cur:0,z=t>=.5?cur+next*.5:cur*.5,lo=0,hi=1;
 for(int i=0;i<60;i++){double u=(lo+hi)*.5,v=(1-u)*((1-u)*x+u*y)+u*((1-u)*y+u*z);if(v<cur*t)lo=u;else hi=u;}
 assert(fabs(animation_bezier_time(t,prev,cur,next)-(lo+hi)*.5)<1e-10);
 }
 keys=@[key(0,10),key(10,10),key(20,10)];
 assert(fabs(position(a,keys,0,YES)-3.75)<1e-12);assert(position(a,keys,29,YES)>position(a,keys,0,YES));
 keys=@[key(4,10)];for(int f=0;f<10;f++)assert(position(a,keys,f,YES)==4);
 keys=@[key(0,10),key(10,10)];assert(fabs(position(a,keys,0,NO)-1.25)<1e-12);assert(fabs(position(a,keys,10,NO)-8.75)<1e-12);
 RenderOptions p={0},q={0},r={0};p.camera.axes[0]=p.camera.axes[4]=p.camera.axes[8]=q.camera.axes[0]=q.camera.axes[4]=q.camera.axes[8]=r.camera.axes[0]=r.camera.axes[4]=r.camera.axes[8]=1;p.width=q.width=r.width=100;p.camera.zoom=q.camera.zoom=r.camera.zoom=1;p.program.slots[0]=q.program.slots[0]=r.program.slots[0]=formula_slot_default(0);
 camera_turn(&p.camera,-30,0,0);camera_turn(&r.camera,30,0,0);RenderOptions mid=animation_bezier_blend(p,q,r,q,.5);for(int i=0;i<9;i++)assert(fabs(mid.camera.axes[i]-q.camera.axes[i])<1e-12);
 puts("Original quadratic time inversion verified; constant motion through equal/unequal-duration keys, loop/end behavior and spherical rotations passed.");
}return 0;}
