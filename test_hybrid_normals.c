#include "renderer.c"
#include <assert.h>
static double shadow_sphere(Vec p){p.z-=3;return sqrt(dot(p,p))-.5;}
int main(void){
    scene_defaults();scene.vary=0;scene.ray_step=.5;scene.de_stop=1;
    double shortRay=shadow_ray((Vec){0},(Vec){0,0,1},1,.001,512,0,.001,0,shadow_sphere),longRay=shadow_ray((Vec){0},(Vec){0,0,1},10,.001,512,0,.001,0,shadow_sphere);assert(shortRay==1&&longRay==0);
    double nearEnd=shadow_ray((Vec){0},(Vec){0,0,1},3,.001,512,1,.001,0,shadow_sphere),nearStart=shadow_ray((Vec){0},(Vec){0,0,1},10,.001,512,1,.001,0,shadow_sphere);assert(nearEnd>nearStart&&nearEnd>0&&nearEnd<1);
    puts("Shadow rays ignore occluders beyond their length and soft shadows fade near the ray limit.");
    for(int kindIndex=0;kindIndex<2;kindIndex++){
        FormulaSlot f=formula_slot_default(kindIndex?100:4);f.min_radius=-1.4078125;Vec input={.1,.2,.3};double d1=1,d2=1,d3=1,power;Vec a=slot_step(input,(Vec){0},f,&d1,&power);f.min_radius=0;Vec b=slot_step(input,(Vec){0},f,&d2,&power);f.min_radius=1.4078125;Vec c=slot_step(input,(Vec){0},f,&d3,&power);assert(a.x==b.x&&a.y==b.y&&a.z==b.z&&d1==d2);assert(fabs(a.x-c.x)>.01);
    }
    puts("Negative Box Min R follows the original positive-floor conversion; it is not treated as its absolute value.");
    scene_defaults();scene.julia=1;scene.julia_c=(Vec){.1,-.2,.3};
    FormulaProgram program=legacy_program();for(int i=0;i<8;i++)program.slots[i].count=0;
    program.slots[0]=formula_slot_default(102);program.slots[0].count=2;
    program.slots[1]=formula_slot_default(103);program.slots[1].count=1;
    program.slots[2]=formula_slot_default(104);program.slots[2].count=1;program.slots[2].parameters[0]=.1;
    program.slots[3]=formula_slot_default(6);program.slots[3].count=3;program.slots[3].power=2;
    program.bailout=1e10;
    Vec input={.12,.23,.34},expected=input,constant=scene.julia_c;double derivative=1,power=2,w=0;
    int sequence[]={0,0,1,2,3,3,3};for(int i=0;i<7;i++)expected=slot_step_context(expected,&constant,&w,program.slots[sequence[i]],&derivative,&power);
    OrbitResult orbit=program_orbit(input,program,0,3,0,5,0);
    assert(orbit.iterations==5&&fabs(orbit.z.x-expected.x)<1e-12&&fabs(orbit.z.y-expected.y)<1e-12&&fabs(orbit.z.z-expected.z)<1e-12);
    puts("Alternate modifiers do not consume iterations; two IFS iterations plus modifiers plus three Folding iterations form one pass.");
    scene_defaults();memset(scene.matrix,0,sizeof scene.matrix);for(int i=0;i<3;i++)scene.matrix[i][i]=1;
    scene.zoom=2.1345/3;scene.fov=30;
    SurfacePixel plane[9]={0};surface_pixels=plane;
    for(int y=0;y<3;y++)for(int x=0;x<3;x++)plane[y*3+x]=(SurfacePixel){.point={x,y,2+.2*x+.3*y},.depth=2,.hit=1};
    compute_depth_normals(3,3);Vec normal=unit((Vec){.2,.3,-1});for(int i=0;i<9;i++)assert(dot(plane[i].normal,normal)>1-1e-12);
    plane[5].point.z+=100;compute_depth_normals(3,3);assert(dot(plane[4].normal,normal)>.99);surface_pixels=NULL;
    puts("Depth normals reproduce a tilted plane and reject a large depth discontinuity without blurring the image.");
    scene_defaults();RenderOptions options={.width=31,.height=17,.threads=2,.normals_override=1,.normal_smoothing=4,.normal_zbuffer=1};
    RenderResult initial=render_scene_with_options(NULL,options);assert(initial.rgba);options=initial.settings;options.ambient.light_mixing=1;options.ambient.roughness=1;free(initial.rgba);
    char path[]="/tmp/mandelbulb-depth-normals-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);
    RenderResult saved=render_scene_to_m3i(NULL,options,path);assert(saved.rgba);
    for(int standard=0;standard<2;standard++){
        if(standard)assert(!truncate(path,840+31*17*18+1136));
        RenderResult loaded=render_scene(path,0,0,1);assert(loaded.rgba&&loaded.settings.normal_zbuffer==1&&loaded.settings.normal_smoothing==4&&loaded.settings.ambient.light_mixing==1&&loaded.settings.ambient.roughness==1);
        assert(!memcmp(saved.rgba,loaded.rgba,saved.stride*saved.height));free(loaded.rgba);
    }
    free(saved.rgba);unlink(path);
    puts("Depth normals, smoothing, roughness and alternate light mixing survive native and standard .m3i round trips with identical pixels.");
}
