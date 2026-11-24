/* Integer Power subset port of Mandelbulb3D. LGPL-2.1-or-later; see LICENSE.
 * Formula: Daniel White and Paul Nylander; original Mandelbulb3D: Jesse and contributors.
 */
#include "renderer.h"
#ifdef USE_RUST_ENGINE
#include "rust_engine.h"
#endif
#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <pthread.h>
#include <stdatomic.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <ImageIO/ImageIO.h>
#include <CoreGraphics/CoreGraphics.h>

struct RenderCancelToken { atomic_int cancelled,rows,total,stage; };
static RenderCancelToken *active_cancel;
RenderCancelToken *render_cancel_create(void) { RenderCancelToken *t=calloc(1,sizeof *t);if(t){atomic_init(&t->cancelled,0);atomic_init(&t->rows,0);atomic_init(&t->total,0);atomic_init(&t->stage,0);}return t; }
int render_progress_percent(RenderCancelToken *t){if(!t)return 0;int total=atomic_load(&t->total);return total? (int)fmin(100,100.0*atomic_load(&t->rows)/total):-1;}
const char *render_progress_stage(RenderCancelToken *t){static const char *names[]={"Geometry","Radiance","HShadows","Reflections","DOF","AShadows"};int s=t?atomic_load(&t->stage):0;return names[s>=0&&s<6?s:0];}
static void render_stage(int stage,int total){if(active_cancel){atomic_store(&active_cancel->total,0);atomic_store(&active_cancel->rows,0);atomic_store(&active_cancel->stage,stage);atomic_store(&active_cancel->total,total);}}
void render_cancel(RenderCancelToken *t) { if(t)atomic_store_explicit(&t->cancelled,1,memory_order_relaxed); }
void render_cancel_destroy(RenderCancelToken *t) { free(t); }
static int render_cancelled(void) { return active_cancel&&atomic_load_explicit(&active_cancel->cancelled,memory_order_relaxed); }
typedef struct { double x,y,z; } Vec;
static Vec add(Vec a, Vec b) { return (Vec){a.x+b.x,a.y+b.y,a.z+b.z}; }
static Vec mul(Vec a,double s) { return (Vec){a.x*s,a.y*s,a.z*s}; }
static double dot(Vec a,Vec b) { return a.x*b.x+a.y*b.y+a.z*b.z; }
static Vec unit(Vec a) { double l=sqrt(dot(a,a)); return l>1e-30?mul(a,1/l):(Vec){0,0,-1}; }
static double clamp(double a,double lo,double hi) { return fmax(lo,fmin(a,hi)); }
#define PI 3.14159265358979323846
#ifndef RENDER_COUNT
#define RENDER_COUNT(name) ((void)0)
#endif
#include "renderer.h"
#include "render_statistics.h"
#include "formula_support.h"
/* The GUI provides its container Maps directory to every rendering backend.
 * Preserve the legacy default for standalone command-line renderer clients. */
int render_create_temporary(char path[4096],const char *pattern,int suffix_length){
    const char *folder=getenv("MB3DX_TEMP_DIR");if(!folder||!folder[0])folder=getenv("TMPDIR");if(!folder||!folder[0])folder="/tmp";
    int count=snprintf(path,4096,"%s/%s",folder,pattern);
    if(count<0||count>=4096){path[0]=0;errno=ENAMETOOLONG;return -1;}
    return mkstemps(path,suffix_length);
}
static const char *map_folder(void){
    const char *configured=getenv("MB3DX_MAP_DIR");if(configured&&configured[0])return configured;
    static char fallback[4096];snprintf(fallback,sizeof fallback,"%s/M3D/M3Maps",getenv("HOME")?getenv("HOME"):"");return fallback;
}
static const char *background_folder(void){
    const char *configured=getenv("MB3DX_BACKGROUND_DIR");return configured&&configured[0]?configured:map_folder();
}
#include "scene.h"
#include "rand_cubes.h"
#include "extra_formulas.h"
#include "height_maps.h"
#include "difs_formulas.h"
/* Explicit little-endian encoding; never serialize C structs or pointers. */
static void put16(unsigned char *p,unsigned v){p[0]=v;p[1]=v>>8;}
static void put32(unsigned char *p,uint32_t v){for(int i=0;i<4;i++)p[i]=v>>(8*i);}
static void put64f(unsigned char *p,double v){uint64_t b;memcpy(&b,&v,8);for(int i=0;i<8;i++)p[i]=b>>(8*i);}
static void put32f(unsigned char *p,double v){float f=v;uint32_t b;memcpy(&b,&f,4);put32(p,b);}
static void put56f(unsigned char *p,double v){unsigned char b[8];put64f(b,v);memcpy(p,b+1,7);}
static void putColor(unsigned char *p,Vec v){p[0]=lround(clamp(v.x,0,1)*255);p[1]=lround(clamp(v.y,0,1)*255);p[2]=lround(clamp(v.z,0,1)*255);}
static void putShort(unsigned char *p,double v){int e=0;while(v>127&&e<25){v/=10;e++;}while(v>0&&v<12.7&&e> -25){v*=10;e--;}p[0]=(unsigned char)lround(v);p[1]=(unsigned char)(e+1);}
static int m3i_fd=-1;
static int scene_parameters_only;
static atomic_int m3i_io_error;
static void writeAt(const void *data,size_t size,off_t offset) {
    const unsigned char *p=data;
    while(size){ssize_t n=pwrite(m3i_fd,p,size,offset);if(n<0&&errno==EINTR)continue;if(n<=0){atomic_store(&m3i_io_error,1);return;}p+=n;size-=n;offset+=n;}
}
static void saveM3IHeaders(int width,int height) {
    unsigned char h[840]={0},a[1136]={0},extra[4096]={0};
    if(scene.preserved_header_valid)memcpy(h,scene.preserved_header,sizeof h);
    if(!scene.preserved_header_valid)h[132]=1;h[331]=scene.normal_zbuffer;if(!scene.preserved_header_valid){h[344]=1;h[345]=2;}put32(h,44);put16(h+16,(u16(h+16)&~(15u<<6))|(scene.normal_smoothing<<6));put32(h+4,width);put32(h+8,height);put32(h+12,scene.iterations);
    Vec center=scene.direct_origin?scene.view_origin:scene.center;
    double start=scene.direct_origin?center.z:scene.zstart,end=start+scene.zend-scene.zstart;
    put64f(h+20,start);put64f(h+28,end);put64f(h+36,center.x);put64f(h+44,center.y);put64f(h+52,center.z);
    for(int i=0;i<3;i++)put64f(h+60+i*8,scene.rotation4[i]);put64f(h+215,scene.julia_w);
    put64f(h+84,scene.zoom);put64f(h+92,scene.bailout);put64f(h+108,scene.fov);
    h[342]=scene.color_option;put32f(h+338,scene.color_multiplier);
    put32f(h+319,scene.ssao.threshold);h[127]=lround(scene.ssao.mirror*100);h[187]=scene.ssao.samples;
    h[133]=(scene.shadows.hard_enabled?1:0)|(scene.shadows.cosine?2:0)|(scene.shadows.hard_mask<<2);
    h[134]=scene.bin_search_steps;h[139]=scene.shadows.soft&&__builtin_popcount((unsigned)scene.shadows.hard_mask)==1;h[163]=scene.shadows.hard_enabled?scene.shadows.hard_mask<<2:0;h[148]=scene.optic;
    unsigned char *interior=h+432;unsigned packed=u32(interior+44);
    put32(interior+44,(packed&~16383u)|((unsigned)lround(scene.cutting_colors.palette_start)&127)|(((unsigned)lround(scene.cutting_colors.palette_end)&127)<<7));
    for(int i=0;i<4;i++){unsigned char *c=interior+360+i*6;put16(c,scene.cutting_colors.stops[i].position);for(int j=0;j<3;j++)c[2+j]=(unsigned char)lround(clamp(scene.cutting_colors.stops[i].diffuse[j],0,1)*255);c[5]=(unsigned char)lround(clamp(scene.cutting_colors.stops[i].specular[0],0,1)*255);}
    h[176]=(h[176]&~7)|scene.cutting_mask;for(int i=0;i<3;i++)put64f(h+346+i*8,scene.cutting[i]);
    h[149]=(scene.preserved_header_valid?(h[149]&~13):16)|(scene.shadows.ambient_enabled?1:0)|(scene.shadows.ambient_method==1?12:scene.shadows.ambient_method==3?8:scene.shadows.ambient_method==2?4:0);
    put64f(h+154,2.1345/(scene.zoom*width));h[162]=scene.vary;
    put32f(h+177,scene.de_stop);put32f(h+182,scene.ray_step);put32f(h+242,scene.raystep_limiter);h[189]=scene.viewing;h[190]=scene.julia;
    put64f(h+191,scene.julia_c.x);put64f(h+199,scene.julia_c.y);put64f(h+207,scene.julia_c.z);
    putShort(h+224,scene.shadows.hard_radius);put32f(h+226,scene.shadows.hard_length);
    for(int i=0;i<9;i++)put64f(h+246+i*8,((double *)scene.matrix)[i]);
    put32f(h+319,scene.ssao.threshold);put32f(h+374,scene.shadows.ambient_length);
    unsigned char *l=h+432;put16(l,(int)scene.z_variation);put32(l+12,lround(scene.depth/.8e-6));
    put32(l+16,lround(scene.diffuse*50));put32(l+20,53);put32(l+24,lround(scene.specular*50));put32(l+28,lround(scene.ambient*90));
    int cs=(int)lround(90*sqrt(fmax(0,(scene.cstart+10900)/32767))-30),ce=(int)lround(90*sqrt(fmax(0,(scene.cstart+scene.cspan+10900)/32767))-30);
    put32(l+32,cs);put32(l+36,ce);put32(l+40,(unsigned)lround(clamp(scene.ao_amount*53,0,255))|((unsigned)(unsigned char)(int8_t)lround(sqrt(scene.indirect)/.022-53)<<8));
    put32(l+44,((unsigned)lround(scene.cutting_colors.palette_start)&127)|(((unsigned)lround(scene.cutting_colors.palette_end)&127)<<7)|(7u<<20)|((unsigned)scene.gamma<<23)|(scene.cycle?1u<<14:0)|(scene.color_on_trap?1u<<17:0)|(scene.far_fog?1u<<18:0)|((unsigned)scene.ambient_object<<29)|((unsigned)scene.background_function<<30));
    putColor(l+52,scene.amb_top);putColor(l+56,scene.amb_bottom);putColor(l+60,scene.bg_top);putColor(l+64,scene.bg_bottom);
    for(int i=0;i<6;i++){unsigned char *q=l+68+i*32;Light light=scene.lights[i];q[0]=light.option;q[1]=light.function;putShort(q+2,light.amplitude);putColor(q+4,light.color);put56f(q+9,light.position.x);put56f(q+17,light.position.y);put56f(q+25,light.position.z);}
    /* The fields below use the current extended lighting layout. Without
       this marker readers migrate them as legacy data and reset map mode/scale. */
    if(l[68+16]<8)l[68+16]=8;
    l[3]=scene.map.disabled?0:scene.map.number&255;l[68+32+16]=scene.map.disabled?0:(scene.map.number>>8)&255;
    l[68+32+24]=(l[68+32+24]&~3)|scene.map.mode;l[7]=(l[7]&~4)|(scene.map.combine?4:0);
    if(scene.map.number) {
        unsigned x=(unsigned)lround((scene.map.offset_x-floor(scene.map.offset_x))*256)&255,y=(unsigned)lround((scene.map.offset_y-floor(scene.map.offset_y))*256)&255;
        unsigned rotation=(unsigned)lround(scene.map.rotation*256/360.+128)&255;
        put32(l+24,(u32(l+24)&4095)|(x<<12)|(y<<20));put32(l+28,(u32(l+28)&4095)|(rotation<<20));
        l[68+64+16]=(unsigned char)clamp(lround(log(scene.map.scale)/log(scene.map.mode?1.2:1.05)+30),0,255);
    }
    l[68+96+16]=(unsigned char)lround(scene.diffuse_shadow*255);
    l[2]=lround(scene.roughness*255);l[68+96+24]=scene.no_interpolation;l[68+64+24]=scene.light_mixing;
    for(int i=0;i<10;i++){unsigned char *q=l+260+i*10;put16(q,scene.stops[i].position);putColor(q+2,scene.stops[i].diffuse);putColor(q+6,scene.stops[i].specular);}
    FormulaProgram program=scene.program_enabled?scene.program:legacy_program();
    int endSlot=0,standardActive=0;for(int i=0;i<6;i++)if(program.slots[i].count){endSlot=i;standardActive=1;}
    a[0]=16;a[1]=program.mode;a[2]=program.numerical_de|(program.render_mode<<1);a[3]=program.combine;a[4]=6;a[5]=endSlot|(program.repeat_from<=endSlot?program.repeat_from:0)<<4;
    a[6]=program.split|(endSlot<<4);a[7]=program.repeat2;
    put16(h+135,program.min_iterations);put32(h+418,program.max_iterations2);put32f(h+378,program.smooth);
    for(int i=0;i<6;i++) {
        unsigned char *q=a+8+i*188;FormulaSlot f=program.slots[i];if(!standardActive&&!i){f=formula_slot_default(0);f.count=1;}
        if(program.mode==1)put32f(q,i<2?formula_iteration_value(program,i):0);else put32(q,(!endSlot&&i==0&&!f.count)?1:f.count);put32(q+4,formula_serial_id(f.kind));put32(q+8,formula_parameter_count(f.kind));
        const char *name=formula_name(f.kind);memcpy(q+12,name,strlen(name));
        for(int j=0;j<formula_parameter_count(f.kind);j++){put64f(q+60+j*8,formula_slot_value(f,j));q[44+j]=formula_option_type(f.kind,j);}
    }
    /* Optional extension preserves native precision and settings not in MB3D.
       MB3D reads the standard header/pixels/addon and ignores this trailer. */
    memcpy(extra,"IPMACM3I",8);put32(extra+8,2);put32(extra+12,sizeof extra);put32(extra+16,scene.oversampling);put32(extra+20,scene.viewing);
    double d[]={scene.diffuse,scene.specular,scene.cstart,scene.cspan,scene.ao_amount,scene.ambient,scene.depth,scene.indirect,scene.z_variation};
    for(int i=0;i<9;i++)put64f(extra+24+i*8,d[i]);
    ShadowSettings sh=scene.shadows;int ints[]={sh.hard_enabled,sh.hard_mask,sh.soft,sh.cosine,sh.hard_auto,sh.ambient_auto,sh.ambient_enabled,sh.ambient_method,sh.ambient_rays,sh.ambient_steps};
    for(int i=0;i<10;i++)put32(extra+96+i*4,ints[i]);
    double sd[]={sh.hard_length,sh.hard_radius,sh.ambient_length,sh.ambient_strength};for(int i=0;i<4;i++)put64f(extra+136+i*8,sd[i]);
    for(int i=0;i<10;i++){unsigned char *q=extra+168+i*52;Stop stop=scene.stops[i];put32(q,stop.position);double c[]={stop.diffuse.x,stop.diffuse.y,stop.diffuse.z,stop.specular.x,stop.specular.y,stop.specular.z};for(int j=0;j<6;j++)put64f(q+4+j*8,c[j]);}
    for(int i=0;i<6;i++){unsigned char *q=extra+688+i*64;Light light=scene.lights[i];put32(q,light.option);put32(q+4,light.function);double d[]={light.amplitude,light.color.x,light.color.y,light.color.z,light.position.x,light.position.y,light.position.z};for(int j=0;j<7;j++)put64f(q+8+j*8,d[j]);}
    int fi[]={scene.kind,scene.kind2,scene.power,scene.power2,scene.count1,scene.count2,scene.repeat_from};for(int i=0;i<7;i++)put32(extra+1072+i*4,fi[i]);
    double fd[]={scene.zmul,scene.zmul2,scene.scale,scene.min_radius,scene.fold,scene.scale2,scene.min_radius2,scene.fold2};for(int i=0;i<8;i++)put64f(extra+1100+i*8,fd[i]);
    put32(extra+1164,scene.size_flags);
    memcpy(extra+1168,"MAP2",4);memcpy(extra+1172,scene.map.file,sizeof scene.map.file);
    put32(extra+1684,scene.map.number);put32(extra+1688,scene.map.mode);put32(extra+1692,scene.map.combine);
    put64f(extra+1696,scene.map.offset_x);put64f(extra+1704,scene.map.offset_y);put64f(extra+1712,scene.map.rotation);put64f(extra+1720,scene.map.scale);put32(extra+1728,scene.map.disabled);
    memcpy(extra+1736,"AMB1",4);put64f(extra+1740,scene.diffuse_shadow);
    Vec ambientColors[]={scene.amb_top,scene.amb_bottom,scene.bg_top,scene.bg_bottom};
    for(int i=0;i<4;i++){put64f(extra+1748+i*24,ambientColors[i].x);put64f(extra+1756+i*24,ambientColors[i].y);put64f(extra+1764+i*24,ambientColors[i].z);}
    memcpy(extra+1880,"FRM6",4);
    for(int i=0;i<6;i++){unsigned char *q=extra+1884+i*52;FormulaSlot f=program.slots[i];put32(q,f.kind);put32(q+4,f.power);put32(q+8,f.count);put64f(q+12,f.z_multiplier);put64f(q+20,f.scale);put64f(q+28,f.min_radius);put64f(q+36,f.fold);}
    int globals[]={program.mode,program.repeat_from,program.min_iterations,program.numerical_de,program.render_mode,program.split,program.repeat2,program.max_iterations2,program.combine};for(int i=0;i<9;i++)put32(extra+2300+i*4,globals[i]);
    memcpy(extra+2400,"CFP1",4);for(int i=0;i<6;i++)for(int j=0;j<13;j++)put64f(extra+2404+i*104+j*8,program.slots[i].parameters[j]);
    put64f(extra+2340,program.bailout);put64f(extra+2348,program.smooth);put64f(extra+2356,program.formula_power);
    h[181]=scene.dof.automatic|((scene.dof.passes-1)<<1);put32f(h+164,scene.dof.focus1);put32f(h+168,scene.dof.clip_radius);put32f(h+172,scene.dof.aperture);put32f(h+410,scene.dof.focus2);
    memcpy(extra+3600,"DOF1",4);put32(extra+3604,scene.dof.enabled);put32(extra+3608,scene.dof.automatic);put32(extra+3612,scene.dof.passes);
    put64f(extra+3616,scene.dof.focus1);put64f(extra+3624,scene.dof.focus2);put64f(extra+3632,scene.dof.aperture);put64f(extra+3640,scene.dof.clip_radius);
    ReflectionSettings rf=scene.reflections;h[336]=rf.automatic|(rf.transparency<<1)|(rf.only_difs<<2);h[337]=rf.depth;put32f(h+332,rf.amount);put32f(h+370,rf.absorption);put32f(h+116,rf.refractive_index);put32f(h+120,rf.scattering);
    memcpy(extra+4080,"TLE1",4);
    extra[4084]=scene.translucency_mode==2;
    memcpy(extra+4088,"SSS2",4);
    float sssAmount=copysignf((float)clamp(scene.subsurface_amount,0,1),scene.subsurface_scattering?1.0f:-1.0f);
    uint32_t sssBits;memcpy(&sssBits,&sssAmount,4);put32(extra+4092,sssBits);
    if(scene.translucency_glow!=0){memcpy(extra+4068,"TGL1",4);put64f(extra+4072,scene.translucency_glow);}
    if(scene.translucency_mode||scene.transmission_blur>0){memcpy(extra+4056,"TBL1",4);put64f(extra+4060,scene.transmission_blur);}
    memcpy(extra+3712,"OPA1",4);put32(extra+3716,rf.opacity_set);for(int c=0;c<2;c++)for(int i=0;i<10;i++)put64f(extra+3720+(c*10+i)*8,rf.opacity_set?rf.opacity[c][i]:1);
    if(rf.opacity_set)for(int i=0;i<10;i++)l[260+i*10+9]=(l[260+i*10+9]&7)|((unsigned)lround((1-rf.opacity[1][i])*31)<<3);
    memcpy(extra+3656,"RFL1",4);put32(extra+3660,rf.enabled);put32(extra+3664,rf.automatic);put32(extra+3668,rf.transparency);put32(extra+3672,rf.only_difs);put32(extra+3676,rf.depth);put64f(extra+3680,rf.amount);put64f(extra+3688,rf.absorption);put64f(extra+3696,rf.refractive_index);put64f(extra+3704,rf.scattering);
    FogSettings fog=scene.fog;h[223]=fog.iterations;h[343]=((fog.map_size+2)<<4)|(fog.mode==1?fog.light:0);
    put16(l+8,lround(fog.mode==3?128:fog.offset));put16(l+10,lround(fog.mode==3?128:fog.far_offset));put32(l+20,lround(fog.mode>=2?53:fog.strength));l[92]=(l[92]&~3)|fog.blend|((fog.only_add&FOG_ONLY_ADD)<<1);
    l[55]=lround(fog.colors[0][0]*255);l[59]=lround(fog.colors[0][1]*255);l[63]=lround(fog.colors[0][2]*255);
    for(int i=0;i<3;i++)l[4+i]=lround(fog.colors[1][i]*255);
    memcpy(extra+3984,"SSA1",4);put64f(extra+3992,scene.ssao.threshold);put64f(extra+4000,scene.ssao.mirror);put32(extra+4008,scene.ssao.samples);put64f(extra+4016,scene.color_multiplier);
    memcpy(extra+3880,"FOG1",4);int fv[]={fog.mode,fog.light,fog.iterations,fog.blend,fog.only_add&FOG_ONLY_ADD,fog.map_size};
    for(int i=0;i<6;i++)put32(extra+3884+i*4,fv[i]);
    put64f(extra+3912,fog.strength);put64f(extra+3920,fog.offset);put64f(extra+3928,fog.far_offset);
    for(int c=0;c<2;c++)for(int i=0;i<3;i++)put64f(extra+3936+(c*3+i)*8,fog.colors[c][i]);
    if(scene.preserved_header_valid){
        const unsigned char *raw=scene.preserved_header,*rl=raw+432;
        /* Keep unedited packed fields; UI-owned fields above still take precedence. */
        unsigned mask=0x9ffffu&~((1u<<14)|16383u); /* interior stops, fine adjustment, background projection */
        /* Fine-adjusted endpoints are already decoded into editable palette endpoints. */
        mask&=~(1u<<16);
        put32(l+44,(u32(l+44)&~mask)|(u32(rl+44)&mask));
        if(u32(rl+44)&(1u<<16)){
            double low=pow(((int32_t)u32(rl+32)+30)/90.,2)*32767-10900;
            double high=pow(((int32_t)u32(rl+36)+30)/90.,2)*32767-10900;
            double first=low+(high-low)*((int)rl[48]-30)/60.;
            double last=low+(high-low)*((int)rl[49]-30)/60.;
            if(fabs(first-scene.cstart)<1e-6&&fabs((last-first)-scene.cspan)<1e-6){
                memcpy(l+32,rl+32,8);l[48]=rl[48];l[49]=rl[49];put32(l+44,u32(l+44)|(1u<<16));
            }
        }
        l[7]=(l[7]&4)|(rl[7]&~4);
        l[50]=rl[50];l[51]=rl[51];l[67]=rl[67];
        memcpy(l+384,rl+384,24); /* background filename */
        l[68+4*32+16]=rl[68+4*32+16]; /* background brightness */
        for(int i=0;i<6;i++)if(scene.lights[i].option&2){
            unsigned char *q=l+68+i*32;const unsigned char *rq=rl+68+i*32;
            memcpy(q+7,rq+7,2);for(int axis=0;axis<3;axis++)memcpy(q+9+axis*8,rq+9+axis*8,7);
        }
    }
    memset(h+382,0,28); /* Orig/Mod metadata is intentionally not retained. */
    put32f(h+424,2.01f); /* Original ProgramVersionStr displays 2.0.1. */
    writeAt(h,sizeof h,0);off_t addon=840+(off_t)width*height*18;writeAt(a,sizeof a,addon);writeAt(extra,sizeof extra,addon+sizeof a);
}

/* Configurable Integer Power; defaults: power 8, Z multiplier -1.
 * Matches CustomFormulas description and HybridIntP8 in formulas.pas.
 */
/* Integer complex powers evaluate the same spherical polynomial without
 * atan2/asin/sin/cos/pow. Normalize azimuth first to avoid pole divisions by
 * rho^n. At the exact pole use atan2(0,0)'s original azimuth convention (0).
 */
static void complex_power(double *real,double *imag,unsigned n) {
    double ar=*real,ai=*imag,rr=1,ri=0;
    while(n) {
        if(n&1) {double t=rr*ar-ri*ai;ri=rr*ai+ri*ar;rr=t;}
        n>>=1;
        if(n) {double t=ar*ar-ai*ai;ai=2*ar*ai;ar=t;}
    }
    *real=rr;*imag=ri;
}
static double integer_power(double x,unsigned n) {
    double result=1;
    while(n) {if(n&1)result*=x;n>>=1;if(n)x*=x;}
    return result;
}
static Vec integer_formula(Vec z,int power,double zmul) {
    if(dot(z,z)<1e-60)return (Vec){0,0,0};
    double rho=sqrt(z.x*z.x+z.y*z.y);
    double az_r=1,az_i=0,lat_r=rho,lat_i=z.z;
    if(rho>0){az_r=z.x/rho;az_i=z.y/rho;}
    complex_power(&az_r,&az_i,(unsigned)power);
    complex_power(&lat_r,&lat_i,(unsigned)power);
    return (Vec){lat_r*az_r,lat_r*az_i,zmul*lat_i};
}
static double box_fold(double x,double fold) {return fabs(x+fold)-fabs(x-fold)-x;}
static Vec amazing_box(Vec z,double scale,double radius,double fold,double *factor) {
    z=(Vec){box_fold(z.x,fold),box_fold(z.y,fold),box_fold(z.z,fold)};
    double rr=dot(z,z),minimum=pow(fmax(1e-40,radius),2);
    *factor=rr<minimum?scale/minimum:rr<1?scale/fmax(rr,1e-300):scale;
    return mul(z,*factor);
}
typedef struct { double distance, smooth,orbit_trap; } Sample;
static double legacy_ade_scale(void);
static Sample evaluate_legacy(Vec c) {
    Vec z=c; double dr=1,r=sqrt(dot(z,z)),old=r; int i,slot=0,remaining=scene.count1,power=scene.power,kind=scene.kind;double smoothing_power=power;
    double trap=dot(c,c);
    for(i=0;i<scene.iterations;i++) {info_local.formula_calls[0]++;
        if(render_cancelled())break;
        if(remaining==0) {
            slot=scene.count2?(slot==0?1:scene.repeat_from):0;
            remaining=slot?scene.count2:scene.count1;
        }
        power=slot?scene.power2:scene.power;kind=slot?scene.kind2:scene.kind;
        old=r;
        if(kind==4) {
            double factor,scale=slot?scene.scale2:scene.scale;
            z=amazing_box(z,scale,slot?scene.min_radius2:scene.min_radius,slot?scene.fold2:scene.fold,&factor);
            dr=fabs(factor)*dr+(scene.julia?0:1);smoothing_power=2;
        } else {
            double zmul=slot?scene.zmul2:scene.zmul;
            double r7=integer_power(r,(unsigned)(power-1));
            dr=power*r7*dr*fmax(1,fabs(zmul))+(scene.julia?0:1);
            z=integer_formula(z,power,zmul);smoothing_power=power;
        }
        z=add(z,scene.julia?scene.julia_c:c);r=sqrt(dot(z,z));trap=fmin(trap,r*r);
        remaining--;
        if(r>scene.bailout) { i++; break; }
    }
    if(r<=scene.bailout) return (Sample){kind==4?r/fmax(dr,1e-300)*legacy_ade_scale():0,scene.iterations,trap};
    double smooth=i;
    if(old>1) {
        double denominator=log(log(r))-log(log(old));
        if(fabs(denominator)>1e-15)smooth+=(log(log(scene.bailout))-log(log(r)))/denominator;
    } else smooth+=log(log(scene.bailout))-log(log(r))/log(smoothing_power);
    return (Sample){fmax(0,(kind==4?legacy_ade_scale():.5*log(r))*r/fmax(dr,1e-300)),smooth,trap};
}
#ifdef USE_C_FORMULA_VM
#include "c_formula_vm.h"
#endif
static Vec slot_step(Vec z,Vec c,FormulaSlot f,double *dr,double *power) {
    if(f.kind==132)return polyfold_sym(z,f.parameters);
    if(f.kind==131)return lincombine_xyz(z,f.parameters);
    if(f.kind==129)return transform_ifs(z,f.parameters,dr);
    if(f.kind==127)return amazing_ifs(z,f.parameters,dr);
    if(f.kind==124)return apollo_2d(z,f.parameters,dr);
    if(f.kind==122){z.y=reciprocal_y3b(z.y,f.parameters);return z;}
    if(f.kind==121){*dr*=fabs(f.parameters[0]);*power=fmax(1.000001,fabs(f.parameters[0]));return menger_smt(z,f.parameters);}
    if(f.kind==117)return formula_rotate(z,f.parameters,1);
    if(f.kind==110){*power=2;return tglad_dihed(z,c,f.parameters);}
    if(f.kind==109){double scale=NAN,factor;Vec result=amazing_surf(z,c,f.parameters,&scale,&factor);*dr*=fabs(factor);*power=fmax(1.000001,fabs(scale));return result;}
    if(f.kind==108)return torus_pinv3(z,f.parameters);
    if(f.kind==105)return add(z,(Vec){c.x*f.parameters[0],c.y*f.parameters[1],c.z*f.parameters[2]});
    if(f.kind==106){double *a=f.parameters[0]==0?&z.x:f.parameters[0]==1?&z.y:f.parameters[0]==2?&z.z:NULL;if(a)*a=sine_y(*a,f.parameters);*dr*=fmax(1,fabs((float)f.parameters[2]*(float)f.parameters[3]));return z;}
    if(f.kind==107){*dr=2*sqrt(dot(z,z))*(*dr)+(scene.julia?0:1);*power=2;return benesi3_pow2(z,c);}
    if(f.kind==102){*dr*=fabs(f.parameters[0]);*power=fmax(1.000001,fabs(f.parameters[0]));return sierpinski_full(z,f.parameters);}
    if(f.kind==103){double *coordinate=f.parameters[0]==0?&z.x:f.parameters[0]==1?&z.y:f.parameters[0]==2?&z.z:NULL;if(coordinate)*coordinate=sine_approx(*coordinate,f.parameters);*dr*=fmax(1,fabs((float)f.parameters[2]*(float)f.parameters[3]));return z;}
    if(f.kind==104){*dr*=fabs(f.parameters[0]);return transform_formula(z,f.parameters);}
    if(f.kind==6){z=(Vec){box_fold(z.x,f.fold),box_fold(z.y,f.fold),box_fold(z.z,f.fold)};}
    if(f.kind==100){double factor;z=amazing_box(z,f.scale,f.min_radius,1,&factor);*dr=fabs(factor)*(*dr);*power=2;return z;}
    if(f.kind==4){double factor;z=amazing_box(z,f.scale,f.min_radius,f.fold,&factor);*dr=fabs(factor)*(*dr)+(scene.julia?0:1);*power=2;}
    else{double r=sqrt(dot(z,z));*dr=f.power*integer_power(r,f.power-1)*(*dr)*fmax(1,fabs(f.z_multiplier))+(scene.julia?0:1);z=integer_formula(z,f.power,f.z_multiplier);*power=f.power;}
    return add(z,scene.julia?scene.julia_c:c);
}
static Vec slot_step_context4(Vec z,Vec *constant,double cw,double *w,FormulaSlot f,double *dr,double *power){
#ifdef USE_C_FORMULA_VM
    if(rust_formula(f.kind))return cf_step(z,constant,cw,w,f,dr,power);
#endif
    if(f.kind==130||f.kind==133){*dr*=f.parameters[0];*power=fmax(1.000001,fabs(f.parameters[0]));double values[15]={0};for(int i=0;i<formula_parameter_count(f.kind);i++)values[i]=formula_slot_value(f,i);return mixpinski4ex(z,w,values);}
    if(f.kind>=118&&f.kind<=120){double radius=sqrt(dot(z,z)+(*w)*(*w));*dr=2*radius*(*dr)+(scene.julia?0:1);*power=2;
        if(f.kind==118){Vec next=makin4_p4b(z,*constant,w,f.parameters);*w+=cw;return next;}
        if(f.kind==119){Vec next=cubic_quat(z,*constant,w,f.parameters);*w+=cw;return next;}
        return lambda4_cw(z,*constant,cw,w,f.parameters);
    }
    if(f.kind==2){
        double x=z.x,y=z.y,zz=z.z,ww=*w;
        *dr=2*sqrt(dot(z,z)+ww*ww)*(*dr)+(scene.julia?0:1);*power=2;
        *w=2*(ww*x+y*zz)+f.parameters[1]+cw;
        return (Vec){x*x-y*y-zz*zz-ww*ww+constant->x,2*(y*x+zz*ww)+constant->y,2*(zz*x+f.parameters[0]*y*ww)+constant->z};
    }
    if(f.kind==106&&f.parameters[0]==3){*w=sine_y(*w,f.parameters);return z;}
    if(f.kind==103&&f.parameters[0]==3){*w=sine_approx(*w,f.parameters);return z;}
    z=slot_step(z,*constant,f,dr,power);
    if(f.kind==121)*w*=f.parameters[0];
    if(f.kind==104){*w*=f.parameters[0];if(!scene.julia&&f.parameters[7]!=0)*constant=z;}
    return z;
}
static Vec slot_step_context(Vec z,Vec *constant,double *w,FormulaSlot f,double *dr,double *power){return slot_step_context4(z,constant,0,w,f,dr,power);}
/* BuildSMatrix4 uses single precision at each matrix multiplication. Angles
 * in the original file are radians, with the product ZW * YW * XW. */
static void prepare_rotation4(void){
    float *m=scene.matrix4;memset(m,0,sizeof scene.matrix4);for(int i=0;i<4;i++)m[i*4+i]=1;
    for(int k=0;k<3;k++){
        float rotation[16]={0},next[16];for(int i=0;i<4;i++)rotation[i*4+i]=1;
        float s=sin(scene.rotation4[k]),c=cos(scene.rotation4[k]);rotation[k*4+k]=rotation[15]=c;rotation[k*4+3]=-s;rotation[12+k]=s;
        for(int i=0;i<4;i++)for(int j=0;j<4;j++){double sum=0;for(int n=0;n<4;n++)sum+=(double)rotation[i*4+n]*m[n*4+j];next[i*4+j]=(float)sum;}
        memcpy(m,next,sizeof next);
    }
}
static Vec rotate_orbit4(Vec p,double *w){
    const float *m=scene.matrix4;
    *w=p.x*m[12]+p.y*m[13]+p.z*m[14];
    return (Vec){p.x*m[0]+p.y*m[1]+p.z*m[2],p.x*m[4]+p.y*m[5]+p.z*m[6],p.x*m[8]+p.y*m[9]+p.z*m[10]};
}
/* MB3D shares this varying scale across Amazing Surf calls in one orbit. */
static Vec slot_step_state(Vec z,Vec *c,double cw,double *w,FormulaSlot f,double *dr,double *power,double *surfScale){
    if(f.kind!=109)return slot_step_context4(z,c,cw,w,f,dr,power);
    double factor;z=amazing_surf(z,*c,f.parameters,surfScale,&factor);*dr*=fabs(factor);*power=2;return z;
}
static double render_formula_values[8][16];

/* Slot numbers are already known in the orbit loop. Compact kernels can
 * use their prepared constants directly, without rediscovering the slot or
 * transferring unchanged Julia/4D state through the generic native bridge. */
static inline Vec slot_step_prepared(Vec z,Vec *c,double cw,double *w,FormulaSlot f,double *dr,double *power,double *surfScale,int slot){
#ifdef USE_C_FORMULA_VM
    CFormulaVM *vm=cf_vm();if(vm&&vm->prepared&&vm->program.slots[slot].kind==f.kind&&!cf_reference_execution&&vm->compact[slot]){
        if(vm->retained_de){cf_wd(vm,CF_REC+112,dot(z,z)+(vm->slot_four_d[slot]?*w**w:0));cf_wd(vm,CF_REC+288,*dr);}
        if(!vm->modifiers[slot])*power=vm->powers[slot];const RustFormula *meta=vm->metadata[slot];double fourth=!vm->four_d&&(meta->de==2||meta->de==11)?*dr:*w;
        Vec next=cf_pure_dispatch(vm->compact[slot],z,&fourth,vm->variables[slot],CF_VAR(slot)+256);if(meta->de==2||meta->de==11)*dr=fabs(fourth);if(vm->four_d)*w=fourth;return next;
    }
    if(vm&&vm->prepared&&vm->program.slots[slot].kind==f.kind&&vm->metadata[slot])return cf_step_at(z,c,cw,w,f,dr,power,slot);
#else
    (void)slot;
#endif
    return slot_step_state(z,c,cw,w,f,dr,power,surfScale);
}
typedef struct {Sample sample;Vec z;int iterations,inside,kind;double radius,derivative;} OrbitResult;
/* A render's formula program is immutable. Prepare classifications and
   normalization once, rather than rescanning slots at every field sample.
   Standalone diagnostic/unit queries retain the uncached path. */
typedef struct {int begin,end,difs,custom,four_d,has_base,numerical,repeat,cycle_steps,stationary_maps,last_map,single_board;double weight,de_scale,ade;} ProgramPartPlan;
static ProgramPartPlan render_plans[2];static int render_plan_count;
static const ProgramPartPlan *part_plan(const FormulaProgram *p,int begin,int end){if(p==&scene.program)for(int i=0;i<render_plan_count;i++)if(render_plans[i].begin==begin&&render_plans[i].end==end)return &render_plans[i];return NULL;}
static OrbitResult program_orbit_ref(Vec c,const FormulaProgram *p,int begin,int end,int repeat,int maxits,int fixed) {
    Vec z=c,constant=scene.julia?scene.julia_c:c;double surfScale=NAN;double w=0,dr=1,r=sqrt(dot(c,c)),old=r,trap=dot(c,c),power=2;int slot=begin,left=0,lastKind=0,i;
    while(slot<=end&&!p->slots[slot].count)slot++;
    if(slot>end)return (OrbitResult){.sample={1e10,0,trap},.radius=1e10};
    double constantW=0;
    const ProgramPartPlan *plan=part_plan(p,begin,end);
    left=p->slots[slot].count;int fourD=plan?plan->four_d:0,hasBase=plan?plan->has_base:0;
    if(!plan)for(int j=begin;j<=end;j++)if(p->slots[j].count){if(formula_four_d(p->slots[j].kind))fourD=1;if(!formula_modifier(p->slots[j].kind))hasBase=1;}
    if(fourD){z=rotate_orbit4(c,&w);if(!scene.julia){constant=z;constantW=w;}else constantW=scene.julia_w;r=sqrt(dot(z,z)+w*w);old=r;trap=r*r;}
#ifdef USE_C_FORMULA_VM
    int custom_state=plan?plan->custom:0;if(!plan)for(int j=begin;j<=end;j++)if(p->slots[j].count&&rust_formula(p->slots[j].kind))custom_state=1;
    if(custom_state)cf_begin(c,constant,constantW,maxits);
#endif
    for(i=0;i<maxits;i++) {
#ifdef USE_C_FORMULA_VM
        if(custom_state){CFormulaVM *vm=cf_vm();if(vm){cf_wi(vm,CF_REC+120,i);cf_wd(vm,CF_REC+8,r*r);}}
#endif
        if(render_cancelled())break;
        old=r;
        if(p->mode==1){Vec sum={0};double total=0,derivative=0,sumW=0,oldW=w,length=0;Vec oldConstant=constant;
            for(int j=0;j<2;j++)if(p->slots[j].count){double weight=formula_iteration_value(*p,j),d=dr,pow=2,nextW=oldW;Vec nextConstant=oldConstant;info_local.formula_calls[j]++;Vec next=slot_step_prepared(z,&nextConstant,constantW,&nextW,p->slots[j],&d,&pow,&surfScale,j);sumW+=(fourD?nextW:fabs(nextW))*weight;sum=add(sum,mul(next,weight));length+=sqrt(dot(next,next)+(fourD?nextW*nextW:0))*weight;derivative+=fabs(d)*weight;total+=weight;if(!formula_modifier(p->slots[j].kind)){power=pow;lastKind=p->slots[j].kind;}}
            total=fmax(total,1e-300);z=mul(sum,1/total);dr=derivative/total;w=sumW/total;
            double blended=length/total,actual=sqrt(dot(z,z)+(fourD?w*w:0));double rescale=blended/sqrt(actual*actual+1e-40);z=mul(z,rescale);if(fourD)w*=rescale;
        }else{
            if(!left){slot++;if(slot>end)slot=repeat;while(slot<=end&&!p->slots[slot].count)slot++;if(slot>end){slot=repeat;while(slot<=end&&!p->slots[slot].count)slot++;}if(slot>end){slot=begin;while(!p->slots[slot].count)slot++;}left=p->slots[slot].count;}
            if(!formula_modifier(p->slots[slot].kind))lastKind=p->slots[slot].kind;info_local.formula_calls[slot]++;z=slot_step_prepared(z,&constant,constantW,&w,p->slots[slot],&dr,&power,&surfScale,slot);left--;
            if(hasBase&&formula_modifier(p->slots[slot].kind)){i--;continue;}
        }
        r=sqrt(dot(z,z)+(fourD?w*w:0));trap=fmin(trap,r*r);if(r>(fixed?p->bailout*p->bailout*8:p->bailout)){i++;break;}if(!isfinite(r)){r=1e150;i++;break;}
    }
    int inside=r<=p->bailout&&i>=maxits;
    double smooth=inside?maxits:i;
    if(!inside){if(old>1){double denominator=log(log(r))-log(log(old));if(fabs(denominator)>1e-15)smooth+=(log(log(p->bailout))-log(log(r)))/denominator;}else smooth+=log(log(p->bailout))-log(log(r))/log(fmax(2,fabs(power)));}
    double distance=inside?(formula_linear(lastKind)?r/fmax(dr,1e-300):0):fmax(0,(formula_linear(lastKind)?1:.5*log(r))*r/fmax(dr,1e-300));
    if(scene.color_option==1)trap=clamp(log(fmax(1e-300,r*r/(old*old+1)))*scene.color_multiplier*512,0,32767)/4096.;
    else if(scene.color_option>=2&&scene.color_option<=4){Vec delta=add(z,mul(c,-1));double angle=scene.color_option==2?atan2(delta.y,delta.x):scene.color_option==3?atan2(delta.z,delta.x):atan2(delta.z,delta.y);trap=clamp((angle+PI)*5200,0,32767)/4096.;}
    else if(scene.color_option==5)trap=clamp((atan2(z.x,z.y)+PI)*5215,0,32767)/4096.;
    return (OrbitResult){(Sample){distance,smooth,trap},z,i,inside,lastKind,r,dr};
}
static __attribute__((unused)) OrbitResult program_orbit(Vec c,FormulaProgram p,int begin,int end,int repeat,int maxits,int fixed){return program_orbit_ref(c,&p,begin,end,repeat,maxits,fixed);}
/* These map primitives sample the current point without advancing the orbit
 * or using the iteration number in their distance/color calculations. */
static int stationary_map_formula(int kind){
    if(kind==116)return 1;
#ifdef USE_C_FORMULA_VM
    static _Thread_local int ready,sphere,cylinder;
    if(!ready){sphere=formula_kind_from_name("SphereHeightMap");cylinder=formula_kind_from_name("CylinderHeightMap");ready=1;}
    return kind==sphere||kind==cylinder;
#else
    return 0;
#endif
}
/* Exact surface queries leave this zero; primary hit tests can terminate
 * a monotone dIFS minimum as soon as it is already a confirmed hit. */
static _Thread_local double difs_hit_threshold;
static OrbitResult difs_part_ref(Vec c,const FormulaProgram *p,int begin,int end,int repeat,int maxits) {
    Vec z=c,constant=scene.julia?scene.julia_c:c;double w=0;double scale=1,best=1e100,trap=0;int slot=begin,left=0,bestIteration=0,modifierSteps=0,cycleSteps=0;
    const ProgramPartPlan *prepared=part_plan(p,begin,end);if(prepared&&prepared->repeat!=repeat)prepared=NULL;
    if(prepared)cycleSteps=prepared->cycle_steps;else for(int j=begin;j<=end;j++)cycleSteps+=p->slots[j].count;
    while(slot<=end&&!p->slots[slot].count)slot++;if(slot>end)return (OrbitResult){.sample={1e10,0,0}};left=p->slots[slot].count;
    int stationary_maps=prepared?prepared->stationary_maps:1,last_map=prepared?prepared->last_map:end;
    if(!prepared){while(last_map>=repeat&&!p->slots[last_map].count)last_map--;for(int j=repeat;j<=end;j++)if(p->slots[j].count&&!stationary_map_formula(p->slots[j].kind))stationary_maps=0;}
    Vec cycle_point={0};double cycle_scale=0;int cycle_started=0;
    int single_board=prepared?prepared->single_board:p->slots[slot].kind==114&&p->slots[slot].parameters[6]==0;if(!prepared)for(int j=begin;j<=end;j++)if(j!=slot&&p->slots[j].count)single_board=0;
#ifdef USE_C_FORMULA_VM
    int custom_state=prepared?prepared->custom:0;if(!prepared)for(int j=begin;j<=end;j++)if(p->slots[j].count&&rust_formula(p->slots[j].kind))custom_state=1;
    if(custom_state)cf_begin(c,constant,0,maxits);
#endif
    for(int i=0;i<maxits;i++) {
        if(render_cancelled())break;
        if(!left){slot++;while(slot<=end&&!p->slots[slot].count)slot++;if(slot>end){slot=repeat;while(slot<=end&&!p->slots[slot].count)slot++;}left=p->slots[slot].count;}
        if(stationary_maps&&!cycle_started&&slot>=repeat){cycle_point=z;cycle_scale=scale;cycle_started=1;}
        FormulaSlot f=p->slots[slot];left--;info_local.formula_calls[slot]++;
        if(formula_modifier(f.kind)){double power=2;z=slot_step_context(z,&constant,&w,f,&scale,&power);if(!isfinite(scale)||fabs(scale)>1e150||!isfinite(dot(z,z))||++modifierSteps>cycleSteps)break;i--;continue;}
        modifierSteps=0;
        double currentTrap=trap;Vec next;double d;
#ifdef USE_C_FORMULA_VM
        if(rust_formula(f.kind)){CFormulaVM *vm=cf_vm();if(!vm)break;vm->count=left+1;cf_wi(vm,CF_REC+120,i);double power=2;next=cf_step_at(z,&constant,0,&w,f,&scale,&power,slot);d=cf_rd(vm,CF_REC+112)/fmax(fabs(scale),1e-300);currentTrap=cf_rd(vm,CF_REC+272);left=vm->count-1;if(vm->slot>=begin&&vm->slot<=end)slot=vm->slot;}
        else {
#endif
        d=(prepared?difs_formula_values(z,f,render_formula_values[slot],&next,&scale,&currentTrap,i):difs_formula(z,f,&next,&scale,&currentTrap,i))/fmax(fabs(scale),1e-300);
#ifdef USE_C_FORMULA_VM
        }
#endif
        z=next;
        if(d<best){best=d;trap=currentTrap;bestIteration=i+1;}
        if(difs_hit_threshold>0&&p->mode!=2&&p->render_mode==0&&best<=difs_hit_threshold&&(best<=0||bestIteration>=p->min_iterations))break;
        /* Without apply-scale/add, a lone board repeats the same distance.
           Its first iteration also wins the strict minimum/color comparison. */
        if(single_board)break;
        if(stationary_maps&&cycle_started&&slot==last_map&&!left&&z.x==cycle_point.x&&z.y==cycle_point.y&&z.z==cycle_point.z&&scale==cycle_scale)break;
        if(!isfinite(scale)||scale>1e150||!isfinite(dot(z,z)))break;
    }
    return (OrbitResult){.sample={best,best<=0?scene.iterations:fmin(scene.iterations-.001,bestIteration),trap},.z=z,.iterations=bestIteration,.inside=best<=0,.kind=101,.radius=sqrt(dot(z,z))};
}
static __attribute__((unused)) OrbitResult difs_part(Vec c,FormulaProgram p,int begin,int end,int repeat,int maxits){return difs_part_ref(c,&p,begin,end,repeat,maxits);}
/* DE options 5/11 use the scale-dependent ADE normalization from
   GetMCTparasFromHeader, rather than only the formula's dADEscale. */
static int scale_de_formula(FormulaSlot f){const RustFormula *meta=rust_formula(f.kind);return f.kind==4||f.kind==109||(meta&&(meta->de==5||meta->de==11));}
static double analytic_de_factor(FormulaSlot f){
    if(scale_de_formula(f)){double scale=formula_slot_value(f,0);if(scale==0)scale=1e-40;return scale<0?.65:(scale*1.2+1)/scale;}
    if(f.kind==130||f.kind==133)return 2;
#ifdef USE_C_FORMULA_VM
    const CFormulaCode *code=cf_code_for(f.kind);if(rust_formula(f.kind)&&code)return code->ade_scale;
#endif
    return 1;
}
static double legacy_ade_scale(void){if(scene.kind!=4||(scene.count2&&scene.kind2!=4))return 1;FormulaProgram p=legacy_program();double sum=0,total=0;for(int i=0;i<8;i++)if(p.slots[i].count){sum+=p.slots[i].count*analytic_de_factor(p.slots[i]);total+=p.slots[i].count;}return total?sum/total:1;}
static ProgramPartPlan make_part_plan(const FormulaProgram *p,int begin,int end){ProgramPartPlan plan={.begin=begin,.end=end};
    plan.repeat=p->mode==2&&begin==p->split?p->repeat2:p->repeat_from;plan.stationary_maps=1;plan.last_map=end;
    int first=begin;while(first<=end&&!p->slots[first].count)first++;
    plan.single_board=first<=end&&p->slots[first].kind==114&&p->slots[first].parameters[6]==0;
    for(int j=begin;j<=end;j++){plan.cycle_steps+=p->mode==1?(p->slots[j].count!=0):p->slots[j].count;if(j!=first&&p->slots[j].count)plan.single_board=0;}
    while(plan.last_map>=plan.repeat&&!p->slots[plan.last_map].count)plan.last_map--;
    for(int j=plan.repeat;j<=end;j++)if(p->slots[j].count&&!stationary_map_formula(p->slots[j].kind))plan.stationary_maps=0;
    for(int i=begin;i<=end;i++)if(p->slots[i].count&&formula_difs(p->slots[i].kind))plan.difs=1;
    int bulbs=0,linear=0,modifiers=0,folding=0,quadratics=0,torus=0;double deScale=0,weight=0;
    for(int i=begin;i<=end;i++)if(p->slots[i].count){FormulaSlot f=p->slots[i];torus+=f.kind==108;bulbs+=f.kind==0||f.kind==6;quadratics+=(formula_four_d(f.kind)&&!formula_linear(f.kind))||f.kind==107||f.kind==110;linear+=formula_linear(f.kind);modifiers+=formula_modifier(f.kind);folding+=f.kind==6;if(!formula_modifier(f.kind)){double factor=f.kind==6?.5:formula_linear(f.kind)?.2:1;
#ifdef USE_C_FORMULA_VM
        if(rust_formula(f.kind))factor=cf_de_scale(f.kind);
#endif
        double count=formula_iteration_value(*p,i);deScale+=count*factor;weight+=count;}}
    int automaticNumerical=torus||quadratics||folding||(bulbs&&(linear||modifiers));
#ifdef USE_C_FORMULA_VM
    for(int i=begin;i<=end;i++)if(p->slots[i].count&&rust_formula(p->slots[i].kind)&&!formula_modifier(p->slots[i].kind)&&!formula_linear(p->slots[i].kind))automaticNumerical=1;
#endif
    plan.numerical=p->numerical_de||automaticNumerical;plan.weight=weight;plan.de_scale=deScale;
    double ade=0,total=0;for(int i=begin;i<=end;i++)if(p->slots[i].count){if(formula_four_d(p->slots[i].kind))plan.four_d=1;if(rust_formula(p->slots[i].kind))plan.custom=1;if(!formula_modifier(p->slots[i].kind)){plan.has_base=1;double count=formula_iteration_value(*p,i);total+=count;ade+=count*analytic_de_factor(p->slots[i]);}}
    plan.ade=total?ade/total:1;return plan;
}
static OrbitResult program_part_ref(Vec c,const FormulaProgram *p,int begin,int end,int repeat,int maxits) {
    ProgramPartPlan fallback;const ProgramPartPlan *plan=part_plan(p,begin,end);if(!plan){fallback=make_part_plan(p,begin,end);plan=&fallback;}
    if(plan->difs)return difs_part_ref(c,p,begin,end,repeat,maxits);
    int numerical=plan->numerical;double deScale=plan->de_scale,weight=plan->weight;
    const FormulaProgram *orbitProgram=p;
    OrbitResult result=program_orbit_ref(c,orbitProgram,begin,end,repeat,maxits,0);
    if(numerical&&result.radius<=1)result.sample.distance=0;
    if(numerical&&result.iterations>0&&result.radius>1){
        double pixelUnit=2.1345/(scene.zoom*fmax(16,scene.width));
        double e=fmax(1e-15,fmin(scene.de_stop*.1,.004)*pixelUnit),gradient=0,baseSquared=result.radius*result.radius;
        for(int axis=0;axis<3;axis++){Vec next=c;if(axis==0)next.x+=e;if(axis==1)next.y+=e;if(axis==2)next.z+=e;double radius=program_orbit_ref(next,orbitProgram,begin,end,repeat,result.iterations,1).radius;double difference=radius*radius-baseSquared;gradient=hypot(gradient,difference);}
        result.sample.distance=0;
        if(isfinite(gradient)&&gradient>1e-300)result.sample.distance=fmax(0,baseSquared*log(baseSquared)*e*(weight?deScale/weight:1)/(gradient+e/pixelUnit*.06));
    }else if(!numerical)for(int i=begin;i<=end;i++)if(p->slots[i].count){if(formula_modifier(p->slots[i].kind))continue;if(p->slots[i].kind==6)result.sample.distance*=.5;break;}
    if(!numerical)result.sample.distance*=plan->ade;
    return result;
}
static __attribute__((unused)) OrbitResult program_part(Vec c,FormulaProgram p,int begin,int end,int repeat,int maxits){return program_part_ref(c,&p,begin,end,repeat,maxits);}
static Sample evaluate_uncut(Vec c) {
    if(render_cancelled())return (Sample){0};
    RENDER_COUNT(evaluations);info_local.evaluations[info_phase]++;
    if(!scene.program_enabled)return evaluate_legacy(c);
    const FormulaProgram *p=&scene.program;
    if(p->mode!=2)return program_part_ref(c,p,0,7,p->repeat_from,scene.iterations).sample;
    OrbitResult a=program_part_ref(c,p,0,p->split-1,p->repeat_from,scene.iterations);
    if(p->combine==5){OrbitResult mixed=difs_part_ref(a.z,p,p->split,7,p->repeat2,p->max_iterations2);double scale=formula_linear(a.kind)?fabs(a.derivative):pow(p->formula_power,a.iterations+1);Sample result=mixed.sample;result.distance/=fmax(1e-300,scale);result.smooth=mixed.inside?scene.iterations:fmin(scene.iterations-.001,(a.sample.smooth+mixed.sample.smooth)*(scene.iterations+1)/(scene.iterations+p->max_iterations2+1));result.orbit_trap=(a.sample.orbit_trap+mixed.sample.orbit_trap)*.5;return result;}
    OrbitResult b=program_part_ref(c,p,p->split,7,p->repeat2,p->max_iterations2);
    double da=a.inside?-fmax(1e-12,a.sample.distance):a.sample.distance,db=b.inside?-fmax(1e-12,b.sample.distance):b.sample.distance,d;
    switch(p->combine){case 0:d=fmin(da,db);break;case 1:d=fmax(da,db);break;case 2:d=fmax(da,-db);break;case 3:d=fmin(da-fmax(0,p->smooth-db),db-fmax(0,p->smooth-da));break;default:{double x=fmax(0,p->smooth-da),y=fmax(0,p->smooth-db);d=fmin(da-y*(p->smooth-x)/p->smooth,db-x*(p->smooth-y)/p->smooth);break;}}
    Sample s=da<db?a.sample:b.sample;s.distance=fmax(0,d);s.smooth=d<=0?scene.iterations:fmin(s.smooth,scene.iterations-.001);return s;
}
static Sample evaluate(Vec c) {
    Sample sample=evaluate_uncut(c);if(!scene.cutting_mask)return sample;
    double coordinates[]={c.x,c.y,c.z},distance=sample.smooth>=scene.iterations?-fabs(sample.distance):sample.distance;
    for(int i=0;i<3;i++)if(scene.cutting_mask&(1<<i)){
        double plane=(scene.cutting[i]-coordinates[i])*(scene.matrix[2][i]>0?1:-1);
        if(plane>distance){distance=plane;if(plane>0)sample.smooth=fmin(sample.smooth,scene.iterations-.001);}
    }
    sample.distance=fmax(0,distance);return sample;
}
static Sample evaluate_hit(Vec point,double threshold){double saved=difs_hit_threshold;difs_hit_threshold=threshold;Sample result=evaluate(point);difs_hit_threshold=saved;return result;}
static int cutout_blocked(Vec c) {
    if(!scene.program_enabled||scene.program.mode!=2||scene.program.combine!=2)return 0;
    FormulaProgram p=scene.program;return program_part(c,p,p.split,7,p.repeat2,p.max_iterations2).inside;
}
static double distance_bulb(Vec p) { double distance=evaluate(p).distance;if(scene.program_enabled)for(int i=0;i<8;i++)if(scene.program.slots[i].count&&formula_difs(scene.program.slots[i].kind))return distance;return fmax(scene.de_stop*.25*2.1345/(scene.zoom*fmax(16,scene.width)),distance); }
static double navigator_distance(Vec point) {
#ifdef USE_RUST_ENGINE
    if(scene.program_enabled)for(int i=0;i<6;i++)if(scene.program.slots[i].count&&rust_formula(scene.program.slots[i].kind))return mb3dx_rust_distance(point.x,point.y,point.z);
#endif
    Sample sample=evaluate(point);return sample.smooth>=scene.iterations?0:fmax(0,sample.distance);
}
/* Original Navigator.GetLocalAbsoluteDE: gather positive estimates at the
   camera and the corners of a small cube, then interpolate the 60th percentile. */
static _Thread_local double navigator_de_multiplier=1;
static double navigator_local_de(Vec origin,double pixel_step) {
    double samples[11];
    int count=0;
    for(int scale=1;count<=3&&scale<=40;scale*=2){
        for(int i=0;i<9&&count<11;i++){
            Vec point=origin;
            if(i<8)for(int axis=0;axis<3;axis++){
                Vec direction={scene.matrix[axis][0],scene.matrix[axis][1],scene.matrix[axis][2]};
                point=add(point,mul(direction,(i&(1<<axis)?16:-16)*scale*pixel_step));
            }
            double distance=navigator_distance(point);
            if(!isfinite(distance)||distance<=0||distance>=1e15*pixel_step)continue;
            int insert=count++;
            while(insert>0&&samples[insert-1]>distance){
                samples[insert]=samples[insert-1];
                insert--;
            }
            samples[insert]=distance;
        }
    }
    if(!count)return NAN;
    double rank=.6*(count-1);
    int index=(int)rank;
    double distance=samples[index];
    if(index+1<count)distance+=(rank-index)*(samples[index+1]-distance);
    return fmin(clamp(distance,3*pixel_step,20000*pixel_step),fmax(2,sqrt(dot(origin,origin))))*navigator_de_multiplier;
}

/* Original Navigator.SpeedButton1Click uses the average of the old and new
   local distances and reduces the step until their ratio settles. */
static Vec adaptive_move(Vec origin,int operation,double fraction,double fine,int width,int height) {
    int axis=operation<2?2:operation<4?0:1;
    double sign=(operation==1||operation==2||operation==5)?-1:1;
    Vec direction={scene.matrix[axis][0]*sign,scene.matrix[axis][1]*sign,scene.matrix[axis][2]*sign};
    double pixel_step=2.1345/(width*scene.zoom);
    double diagonal=hypot(width,height);
    double distance=navigator_local_de(origin,pixel_step);
    if(!isfinite(distance))return add(origin,mul(direction,fraction*fine*diagonal*pixel_step));
    double min_de=fmax(1e-13,distance*(1-fraction)*.8);
    double max_de=fmax(min_de*1.1,distance*(1+fraction)*1.25);
    double next=navigator_local_de(add(origin,mul(direction,fraction*fine*distance)),pixel_step);
    double scale=1.25;
    Vec candidate=origin;
    for(int retry=0;retry<=100;retry++){
        if(render_cancelled()||!isfinite(next))return origin;
        scale*=.8;
        candidate=add(origin,mul(direction,fraction*fine*.5*(distance+next)*scale));
        next=navigator_local_de(candidate,pixel_step);
        double coordinate=fmax(fabs(candidate.x),fmax(fabs(candidate.y),fabs(candidate.z)));
        if(next>min_de&&next<max_de&&coordinate<201+retry)break;
    }
    if(!isfinite(next))return origin;
    double zoom=clamp(2*diagonal/(next*width),1e-12,1e12);
    scene.zend=scene.zstart+clamp((scene.zend-scene.zstart)*scene.zoom/zoom,1e-9,9999);
    scene.zoom=zoom;
    scene.col_z=scene.z_variation*-.005/2.1345*zoom;
    navigator_de_multiplier=1+(navigator_de_multiplier-1)*.8;
    return candidate;
}

static Vec camera_rotate(Vec v);
static Vec surface_normal(Vec p,double e,double *roughness) {
    INFO_PHASE(1);
    RENDER_COUNT(normals);
    *roughness=0;
    Vec x=camera_rotate((Vec){e,0,0}),y=camera_rotate((Vec){0,e,0}),z=camera_rotate((Vec){0,0,e});
    Vec gradient={(distance_bulb(add(p,x))-distance_bulb(add(p,mul(x,-1))))*.5,(distance_bulb(add(p,y))-distance_bulb(add(p,mul(y,-1))))*.5,(distance_bulb(add(p,z))-distance_bulb(add(p,mul(z,-1))))*.5};
    int smooth=scene.normal_smoothing;
    if(smooth==8){
        gradient=(Vec){0};double spacing=e*1.3333;
        for(int iz=-2;iz<=2;iz++)for(int iy=-2;iy<=2;iy++)for(int ix=-2;ix<=2;ix++)if(ix||iy||iz){Vec delta=camera_rotate((Vec){ix*spacing,iy*spacing,iz*spacing});double d=distance_bulb(add(p,delta));if(ix)gradient.x+=d/ix;if(iy)gradient.y+=d/iy;if(iz)gradient.z+=d/iz;}
        gradient=mul(gradient,.0075);
    }
    if(smooth>0&&smooth<=8){
        Vec n=unit(gradient);double qx=0,qy=0,qw=cos(acos(clamp(-n.z,-1,1))*.5),len=hypot(n.x,n.y);
        if(len>1e-25){double f=sin(acos(clamp(-n.z,-1,1))*.5)/len;qx=-n.y*f;qy=n.x*f;}
        Vec vx=camera_rotate((Vec){1-2*qy*qy,2*qx*qy,2*qy*qw}),vy=camera_rotate((Vec){2*qx*qy,1-2*qx*qx,-2*qx*qw});
        double spacing=6*e/(smooth+.5),sumX=0,sumY=0,squares=0,center=distance_bulb(p);
        if(smooth<8)center=(center+distance_bulb(add(p,mul(x,2)))+distance_bulb(add(p,mul(x,-2)))+distance_bulb(add(p,mul(y,2)))+distance_bulb(add(p,mul(y,-2))))*.2;
        for(int i=-smooth;i<=smooth;i++)if(i){double a=(distance_bulb(add(p,mul(vx,i*spacing)))-center)/i,b=(distance_bulb(add(p,mul(vy,i*spacing)))-center)/i;sumX+=a;sumY+=b;squares+=a*a+b*b;}
        double weight=e/(2*smooth*spacing),variance=fmax(0,2*smooth*squares-sumX*sumX-sumY*sumY);*roughness=clamp(sqrt((1e-40+variance*7*weight*weight)/(1e-40+dot(gradient,gradient)))-.05,0,1);if(smooth<8){gradient.x+=sumX*weight;gradient.y+=sumY*weight;}
    }
    return camera_rotate(unit(gradient));
}
/* The file matrix stores camera axes as rows; normalize on load. */
static Vec camera_rotate(Vec v) {
    double (*m)[3]=scene.matrix;
    return (Vec){v.x*m[0][0]+v.y*m[1][0]+v.z*m[2][0],
                 v.x*m[0][1]+v.y*m[1][1]+v.z*m[2][1],
                 v.x*m[0][2]+v.y*m[1][2]+v.z*m[2][2]};
}
static Vec camera_unrotate(Vec v) {
    double (*m)[3]=scene.matrix;
    return (Vec){v.x*m[0][0]+v.y*m[0][1]+v.z*m[0][2],
                 v.x*m[1][0]+v.y*m[1][1]+v.z*m[1][2],
                 v.x*m[2][0]+v.y*m[2][1]+v.z*m[2][2]};
}
static Vec product(Vec a,Vec b) { return (Vec){a.x*b.x,a.y*b.y,a.z*b.z}; }
static Vec mix(Vec a,Vec b,double t) { return add(mul(a,1-t),mul(b,t)); }
/* Delphi colors are $00BBGGRR. All lighting is in the default non-I2 mode. */

static int reflection_surface_difs(Vec point);
static double color_iteration_limit(void){if(scene.program_enabled&&scene.program.mode==2)return scene.program.combine==5?scene.iterations+scene.program.max_iterations2:fmax(scene.iterations,scene.program.max_iterations2);return scene.iterations;}
static double color_gradient(double smooth,double trap){return nearbyint(scene.color_on_trap?clamp(trap*4096,0,32767):clamp(32767-fmax(0,smooth)*32767/(color_iteration_limit()+1),0,32767));}
static Sample surface_color_sample(Vec point,double eps);
static void palette(double smooth,double trap,double depth,Vec *dif,Vec *spe) {
    double gradient=color_gradient(smooth,trap);
    double pos=(gradient-scene.cstart)*32768/scene.cspan+scene.col_z*depth*16384;
    if(scene.cycle) {pos=fmod(pos,32768);if(pos<0)pos+=32768;}
    if(pos>=scene.stops[9].position) {
        /* CalcColors closes a cycling palette from stop 10 to stop 1.
           Holding the final stop here creates a sharp seam at wraparound. */
        double span=32767.-scene.stops[9].position;
        double t=scene.cycle&&!scene.no_interpolation&&span>0?clamp((pos-scene.stops[9].position)/span,0,1):0;
        *dif=mix(scene.stops[9].diffuse,scene.stops[0].diffuse,t);
        *spe=mix(scene.stops[9].specular,scene.stops[0].specular,t);return;
    }
    int b=1;
    if(pos<=scene.stops[0].position)b=0;
    else {while(b<9 && pos>scene.stops[b].position)b++;}
    int a=b?b-1:0;
    double span=scene.stops[b].position-scene.stops[a].position;
    double t=span>0?clamp((pos-scene.stops[a].position)/span,0,1):0;
    if(scene.no_interpolation)t=0;
    *dif=mix(scene.stops[a].diffuse,scene.stops[b].diffuse,t);
    *spe=mix(scene.stops[a].specular,scene.stops[b].specular,t);
}
static unsigned char *map_pixels;
static int map_width,map_height;
static void load_object_map_from_folder(const char *source_folder) {
    free(map_pixels);map_pixels=NULL;map_width=map_height=0;
    if(scene.map.disabled||(!scene.map.file[0]&&!scene.map.number))return;
    char folder[4096],path[4608];
    snprintf(folder,sizeof folder,"%s",source_folder);
    if(!scene.map.file[0]) {
        DIR *directory=opendir(folder);struct dirent *entry;
        if(directory){while((entry=readdir(directory))) {
            char *end;long number=strtol(entry->d_name,&end,10);
            if(end!=entry->d_name&&*end=='.'&&number==scene.map.number&&(!strcasecmp(end,".png")||!strcasecmp(end,".jpg")||!strcasecmp(end,".jpeg")||!strcasecmp(end,".bmp")||!strcasecmp(end,".gif")||!strcasecmp(end,".tif")||!strcasecmp(end,".tiff"))) {
                snprintf(scene.map.file,sizeof scene.map.file,"%s",entry->d_name);break;
            }
        }closedir(directory);}
    }
    snprintf(path,sizeof path,"%s/%s",folder,scene.map.file);
    CFURLRef url=CFURLCreateFromFileSystemRepresentation(NULL,(const UInt8 *)path,strlen(path),false);
    CGImageSourceRef source=url?CGImageSourceCreateWithURL(url,NULL):NULL;
    CGImageRef image=source?CGImageSourceCreateImageAtIndex(source,0,NULL):NULL;
    if(image) {
        size_t w=CGImageGetWidth(image),h=CGImageGetHeight(image);
        if(w&&h&&w<=RENDER_MAX_DIMENSION&&h<=RENDER_MAX_DIMENSION&&w*h<=MAP_MAX_PIXELS) {
            unsigned char *pixels=calloc(w*h,4);CGColorSpaceRef space=CGColorSpaceCreateWithName(kCGColorSpaceSRGB);
            CGContextRef context=pixels?CGBitmapContextCreate(pixels,w,h,8,w*4,space,kCGImageAlphaPremultipliedLast|kCGBitmapByteOrder32Big):NULL;
            if(context){CGContextTranslateCTM(context,0,h);CGContextScaleCTM(context,1,-1);CGContextDrawImage(context,CGRectMake(0,0,w,h),image);CGContextRelease(context);map_pixels=pixels;map_width=(int)w;map_height=(int)h;}else free(pixels);
            CGColorSpaceRelease(space);
        }
        CGImageRelease(image);
    }
    if(source)CFRelease(source);if(url)CFRelease(url);
    if(!map_pixels)fprintf(stderr,"Warning: Object map %d (%s) could not be loaded from %s; using diffuse palette.\n",scene.map.number,scene.map.file,folder);
}
static void load_object_map(void){load_object_map_from_folder(map_folder());}
static Vec map_texel(int x,int y) {
    x=(x%map_width+map_width)%map_width;y=(y%map_height+map_height)%map_height;
    const unsigned char *p=map_pixels+((size_t)y*map_width+x)*4;
    return (Vec){p[0]/255.,p[1]/255.,p[2]/255.};
}
static Vec map_sample(double u,double v) {
    double x=(u-floor(u))*map_width-.5,y=(v-floor(v))*map_height-.5;
    int ix=(int)floor(x),iy=(int)floor(y);double tx=x-ix,ty=y-iy;
    return mix(mix(map_texel(ix,iy),map_texel(ix+1,iy),tx),mix(map_texel(ix,iy+1),map_texel(ix+1,iy+1),tx),ty);
}
static Vec object_map_color(Vec p,Vec n,Sample sample,Vec palette_color) {
    ObjectMap m=scene.map;double a=m.rotation*PI/180,c=cos(a),s=sin(a);Vec color;
    if(!m.mode) {
        double u=clamp(sample.orbit_trap*4096,0,32767)/32767.-.5;
        double v=(32767-clamp(sample.smooth,0,scene.iterations)*32767/(scene.iterations+1))/32767.-.5;
        /* HeaderTrafos DCLMapOffX/Y include +256 before /256.
           This whole-tile offset must precede scaling in Its + OTrap mode. */
        color=map_sample((c*u+s*v+m.offset_x+1)*m.scale,(c*v-s*u+m.offset_y+1)*m.scale);
    } else if(m.mode==1) {
        Vec v=camera_unrotate(n);double x=c*v.x-s*v.y,y=s*v.x+c*v.y;
        double u=atan2(x,v.z)/(2*PI)+m.offset_x,vv=m.offset_y-asin(clamp(y,-1,1))/PI;
        color=map_sample((u-.5)*m.scale+.5,(vv-.5)*m.scale+.5);
    } else {
        Vec v=mul(p,m.scale),weights={fabs(n.x),fabs(n.y),fabs(n.z)};
        double total=weights.x+weights.y+weights.z;weights=mul(weights,1/fmax(total,1e-30));
        if(m.mode==3) {
            color=add(add(mul(map_sample(c*v.y+s*v.z+m.offset_x,c*v.z-s*v.y+m.offset_y),weights.x),mul(map_sample(c*v.x+s*v.z+m.offset_x,c*v.z-s*v.x+m.offset_y),weights.y)),mul(map_sample(c*v.x+s*v.y+m.offset_x,c*v.y-s*v.x+m.offset_y),weights.z));
        } else {
            v=(Vec){sin(v.x),sin(v.y),sin(v.z)};
            double u=v.y*weights.x+v.x*(weights.y+weights.z),w=v.z*(weights.x+weights.y)+v.y*weights.z;
            color=map_sample(c*u+s*w+m.offset_x,c*w-s*u+m.offset_y);
        }
    }
    if(m.combine) {
        double luminance=dot(color,(Vec){.299,.587,.114}),base=dot(palette_color,(Vec){.299,.587,.114});
        color=mul(palette_color,luminance/(.001+base));
    }
    return color;
}
static int internal_gamma2(void){return scene.preserved_header_valid&&(scene.preserved_header[439]&1);}
static Vec lighting_color(Vec c){return internal_gamma2()?product(c,c):c;}
static Vec gamma_color(Vec c) {
    if(internal_gamma2())c=(Vec){sqrt(fmax(0,c.x)),sqrt(fmax(0,c.y)),sqrt(fmax(0,c.z))};
    c=(Vec){clamp(c.x,0,1),clamp(c.y,0,1),clamp(c.z,0,1)};
    if(scene.gamma==32)return c;
    if(scene.gamma<32)return mix(c,product(c,c),1-scene.gamma/32.);
    Vec root={sqrt(c.x),sqrt(c.y),sqrt(c.z)};
    return mix(c,root,(scene.gamma-32)/31.);
}
/* Secondary rays use world coordinates and never alter primary hit data. */
static double shadow_ray(Vec origin,Vec direction,double max_length,double eps,int steps,double softness,double pixelStep,double depth,double (*field)(Vec)) {
    INFO_PHASE(3);RENDER_COUNT(hard);
    double t=0,visibility=1,distance=field(origin),factor=2;
    double depthSlope=dot(direction,camera_rotate((Vec){0,0,1})),perspective=scene.vary?(scene.optic==2?PI:scene.fov*PI/180)/(scene.height*pixelStep):0;
    double base=scene.de_stop*pixelStep;
    for(int i=0;i<steps&&t<max_length;i++) {
        double advance=fmax(pixelStep*.11,distance*scene.ray_step*factor);advance=fmin(advance,max_length-t);
        t+=advance;double next=field(add(origin,mul(direction,t)));
        double threshold=perspective?base*(1+fabs(depth+t*depthSlope)*perspective):eps;
        if(softness>0)visibility=fmin(visibility,(next-threshold)*80/(softness*(t+pixelStep*.11))+pow(t/max_length,8));
        if(next<=threshold){if(softness<=0)return 0;break;}
        next=fmin(next,distance+advance);factor=distance>next+1e-30?clamp(advance/(distance-next),.5,1):1;distance=next;
    }
    return clamp(visibility,0,1);
}
/* Exterior DEAO core follows CalcAmbShadowDE.pas: minimum normalized
   clearance, angular cone scale and neighboring-cone overlap correction.
   Distances are in world units; no contrast curve or distance fade is added. */
static int ambient_directions(int rays,Vec directions[64],double *stepMultiplier,double *neighborCos,double *correctionWeight){
    int quality=rays==7?1:rays==17?2:rays==33?3:0;
    if(rays==3){for(int i=0;i<3;i++){double angle=i*2*PI/3;directions[i]=(Vec){.5*cos(angle),.5*sin(angle),sqrt(.75)};}*stepMultiplier=1.8;*neighborCos=-1;*correctionWeight=.3;return rays;}
    if(quality){double spacing=PI*.5/(quality+.9);int count=1;directions[0]=(Vec){0,0,1};
        for(int row=1;row<=quality;row++){double theta=row*spacing;int countInRow=(int)lround(sin(theta)*2*PI/spacing);for(int i=0;i<countInRow;i++){double angle=i*2*PI/countInRow;directions[count++]=(Vec){sin(theta)*cos(angle),sin(theta)*sin(angle),cos(theta)};}}
        *stepMultiplier=1+sin(spacing);*neighborCos=cos(spacing*1.2);*correctionWeight=quality==1?.2:.1666;return count;
    }
    /* Preserve arbitrary native ray counts using a cap whose edge has full
       visibility on an unobstructed plane, like the original ring layouts. */
    double coneScale=sqrt(fmax(1,rays*.5)),minimumZ=1/coneScale;
    for(int i=0;i<rays;i++){double z=1-(1-minimumZ)*(i+.5)/rays,r=sqrt(fmax(0,1-z*z)),angle=i*2.399963229728653;directions[i]=(Vec){r*cos(angle),r*sin(angle),z};}
    double spacing=sqrt(2*PI/fmax(1,rays));*stepMultiplier=1+sin(fmin(PI*.5,spacing));*neighborCos=cos(spacing*1.2);*correctionWeight=.1666;return rays;
}
static double ambient_ray_visibility(Vec origin,Vec direction,double max_length,double eps,int steps,double coneScale,double stepMultiplier,double pixelUnit,double (*field)(Vec)) {
    if(max_length<=0)return 1;
    double t=pixelUnit*stepMultiplier,visibility=1;
    double threshold=eps/(stepMultiplier*stepMultiplier);
    double distanceBias=.1*pixelUnit/(max_length*fmax(coneScale,1e-300));
    for(int i=0;i<steps;i++){
        t=fmin(t,max_length);
        double distance=field(add(origin,mul(direction,t)));
        if(!isfinite(distance))break;
        visibility=fmin(visibility,(distance-threshold)/fmax(t,1e-300)+distanceBias);
        if(visibility<.02||t>=max_length)break;
        t+=fmax(distance,t*stepMultiplier);
    }
    return fmax(0,visibility)*coneScale;
}
/* Match Math3D.MakeRotQuatFromSNormals in camera coordinates. The original
   ray cap is around -Z, with a clockwise ring when viewed along the normal. */
static Vec ambient_orient_direction(Vec v,Vec normal){
    Vec n=camera_unrotate(normal);double length=hypot(n.x,n.y),half=acos(clamp(-n.z,-1,1))*.5;
    double qx=0,qy=0,qw=cos(half);
    if(length>1e-25){double factor=sin(half)/length;qx=-n.y*factor;qy=n.x*factor;}else if(n.z>0){qx=1;qw=0;}
    double m[]={1-2*qy*qy,2*qx*qy,-2*qy*qw,2*qx*qy,1-2*qx*qx,2*qx*qw,2*qy*qw,-2*qx*qw,1-2*(qx*qx+qy*qy)};
    for(int i=0;i<9;i++)m[i]=(float)m[i];v.y=-v.y;v.z=-v.z;
    return camera_rotate((Vec){m[0]*v.x+m[1]*v.y+m[2]*v.z,m[3]*v.x+m[4]*v.y+m[5]*v.z,m[6]*v.x+m[7]*v.y+m[8]*v.z});
}
static double ambient_shadow(Vec p,Vec n,double eps,int w,int h) {
    INFO_PHASE(4);RENDER_COUNT(ambient);
    if(!scene.shadows.ambient_method)return 1;
    Vec directions[64];double visibility[64],stepMultiplier,neighborCos,correctionWeight;
    int rays=ambient_directions(scene.shadows.ambient_rays,directions,&stepMultiplier,&neighborCos,&correctionWeight);
    double coneScale=sqrt(fmax(1,rays*.5));
    double baseEps=2.1345/(scene.zoom*w)*scene.de_stop;
    double max_length=1.06725/scene.zoom*hypot(1,(double)h/w)*scene.shadows.ambient_length*sqrt(eps/fmax(baseEps,1e-300));
    for(int i=0;i<rays;i++){
        Vec direction=ambient_orient_direction(directions[i],n);
        visibility[i]=ambient_ray_visibility(p,direction,max_length,eps,scene.shadows.ambient_steps,coneScale,stepMultiplier,eps/fmax(scene.de_stop,1e-6),distance_bulb);
    }
    double sum=0,angleScale=coneScale>1?1.2/asin(1/coneScale):0;
    for(int i=0;i<rays;i++){
        double correction=0;
        if(visibility[i]<1&&angleScale>0)for(int j=0;j<rays;j++)if(i!=j){double cosine=dot(directions[i],directions[j]);if(cosine>neighborCos){double overlap=visibility[j]-acos(clamp(cosine,-1,1))*angleScale+1;if(overlap>0)correction+=fmin(1-visibility[i],overlap)*correctionWeight;}}
        sum+=fmin(1,visibility[i]+correction);
    }
    return clamp(sum/rays,0,1);
}
/* PaintThread.pas calcAmbshadow blends toward squared visibility above 1x.
   Linear amplification above 1x clipped intermediate shadows prematurely. */
static double ambient_visibility_strength(double visibility,double strength){
    return clamp(strength>1?visibility+(strength-1)*(visibility*visibility-visibility):1-strength*(1-visibility),0,1);
}
static atomic_uint color_histogram[3][32768];
/* LightAdjust.SetCosTabFunction/GetCosTabVal: smooth and rough diffuse lobes. */
static double diffuse_table[8][128];
static pthread_once_t diffuse_once=PTHREAD_ONCE_INIT;
static void init_diffuse_table(void){
    for(int i=0;i<128;i++){double d=1-(i-2)/60.;diffuse_table[0][i]=d>.15?(d-.08)*1.0869565:d<=0?0:pow(d,fmax(1,(.505-d)*3.8));diffuse_table[1][i]=pow(fmax(0,d),2);diffuse_table[2][i]=d*.5+.5;diffuse_table[3][i]=pow(d*.5+.5,2);}
    for(int k=0;k<4;k++)for(int j=0;j<128;j++){double sum=0;for(int i=0;i<=60;i++){int index=abs(j+i-30);if(index<128)sum+=sqrt(fmax(0,diffuse_table[k][index]));}diffuse_table[k+4][j]=pow(sum*.011+pow(sum*.007,2),2);}
}
static double diffuse_lobe(int kind,double cosine,double roughness){
    pthread_once(&diffuse_once,init_diffuse_table);double t=62-60*cosine;int index=(int)t-1;if(index<0){index=0;t=0;}else if(index>124){index=124;t=1;}else t-=floor(t);
    double w[4];w[3]=t*t*t/6;w[0]=1./6+.5*t*(t-1)-w[3];w[2]=t+w[0]-2*w[3];w[1]=1-w[0]-w[2]-w[3];double smooth=0,rough=0;for(int i=0;i<4;i++){smooth+=w[i]*diffuse_table[kind][index+i];rough+=w[i]*diffuse_table[kind+4][index+i];}return smooth+(rough-smooth)*roughness;
}
static int reflection_surface_difs(Vec point);
static double color_de_correction(double eps){
    FormulaProgram p=scene.program_enabled?scene.program:legacy_program();double sum=0,weight=0;
    for(int i=0;i<8;i++){FormulaSlot f=p.slots[i];if(!f.count||formula_modifier(f.kind))continue;double factor=.6;
        if(formula_linear(f.kind)){double scale=formula_slot_value(f,0);if(fabs(scale)<=1)continue;if(fabs(scale)<1.2)scale=1.1+pow(fabs(scale)-1,2)*2.5;factor=.5/(log(fabs(scale))+.03);}
        double count=formula_iteration_value(p,i);sum+=factor*count;weight+=count;
    }
    return (weight?sum/weight:.6)*log(fmax(eps,1e-300));
}
/* One completed full-resolution surface, owned by the serial render queue.
   Workers write distinct pixels; cache dependency flags are immutable per pass. */
static double color_scale_offset(void){
    FormulaProgram p=scene.program_enabled?scene.program:legacy_program();double sum=0,count=0;
    for(int i=0;i<8;i++)if(p.slots[i].count&&!formula_modifier(p.slots[i].kind)&&scale_de_formula(p.slots[i])){double weight=formula_iteration_value(p,i);sum+=weight*fabs(formula_slot_value(p.slots[i],0));count+=weight;}
    return count?pow(sum/count,.25)*40-49:0;
}
static Sample surface_color_sample(Vec point,double eps){
    Sample sample=evaluate(point);
    if(reflection_surface_difs(point)){
        /* Geometry encodes inside as max iterations; material color needs
           the actual distance primitive's winning iteration, even inside. */
        double iteration=nearbyint(sample.smooth);if(scene.program.mode!=2)iteration=program_part(point,scene.program,0,7,scene.program.repeat_from,scene.iterations).iterations;
        sample.smooth=iteration+color_iteration_limit()*.1;
    }
    else if(sample.smooth<scene.iterations)sample.smooth+=color_de_correction(eps)+color_scale_offset()+color_iteration_limit()*.1;
    if(scene.color_option==5&&scene.program_enabled&&scene.program.mode!=2){
        OrbitResult orbit=program_orbit_ref(point,&scene.program,0,7,scene.program.repeat_from,scene.iterations,0);double radius=sqrt(dot(orbit.z,orbit.z)+1e-100);
        double gradient=clamp((PI+2*asin(clamp(orbit.z.z/radius,-1,1)))*5215,0,32767);
        sample.smooth=(32767-gradient)*(color_iteration_limit()+1)/32767.;
    }
    return sample;
}
typedef struct {Vec point,ray,normal;double depth,eps,roughness,ambient_visibility;Sample sample;double hard_visibility[6];int hit,prepared,emissive,emission_valid,emission_source;double emission_irradiance;} SurfacePixel;
typedef struct {SurfacePixel *pixels;Scene geometry,ambient_scene,hard_scene;int ambient_valid,hard_valid,emission_filtered;double local_distance;} SurfaceCache;
static SurfaceCache surface_caches[2];
static SurfaceCache *active_surface_cache=&surface_caches[0];
#define surface_cache (*active_surface_cache)
int render_pick_surface(double x,double y,double position[3]) {
#ifdef USE_RUST_ENGINE
    return mb3dx_rust_pick(x,y,position,NULL);
#endif
    SurfaceCache *cache=&surface_caches[0];
    if(!cache->pixels||!position||!isfinite(x)||!isfinite(y)||x<0||x>=1||y<0||y>=1)return 0;
    int w=cache->geometry.width,h=cache->geometry.height;
    SurfacePixel *pixel=&cache->pixels[(int)(y*h)*w+(int)(x*w)];
    if(!pixel->hit)return 0;
    /* Place just outside the surface, avoiding an embedded point light. */
    Vec offset=mul(pixel->normal,fmax(pixel->eps*4,1e-9));
    Vec point=add(pixel->point,offset);
    position[0]=point.x;position[1]=point.y;position[2]=point.z;return 1;
}
int render_pick_focus(double x,double y,double *focus){
#ifdef USE_RUST_ENGINE
    return mb3dx_rust_pick(x,y,NULL,focus);
#endif
    SurfaceCache *cache=&surface_caches[0];
    if(!cache->pixels||!focus||!isfinite(x)||!isfinite(y)||x<0||x>=1||y<0||y>=1)return 0;
    int w=cache->geometry.width,h=cache->geometry.height;SurfacePixel *p=&cache->pixels[(int)(y*h)*w+(int)(x*w)];
    if(!p->hit)return 0;*focus=p->depth*cache->geometry.zoom/2.1345;return 1;
}
int render_export_zbuffer(const char *path,int preview,int width,int height,char error[512]){
#ifdef USE_RUST_ENGINE
    return mb3dx_rust_depth(path,preview,width,height,error);
#endif
    error[0]=0;SurfaceCache *cache=&surface_caches[preview?1:0];int w=cache->geometry.width,h=cache->geometry.height;
    if(!cache->pixels||width<1||height<1||w%width||h%height){snprintf(error,512,"No matching depth buffer for export");return 0;}
    uint16_t *pixels=calloc((size_t)width*height,sizeof *pixels);if(!pixels){snprintf(error,512,"Not enough memory for Z-buffer export");return 0;}
    int sx=w/width,sy=h/height;double far=fmax(1e-30,cache->geometry.zend-cache->geometry.zstart);
    for(int y=0;y<height;y++)for(int x=0;x<width;x++){double sum=0;for(int j=0;j<sy;j++)for(int i=0;i<sx;i++){SurfacePixel *p=&cache->pixels[(y*sy+j)*w+x*sx+i];if(p->hit)sum+=fmax(1,65535*(1-clamp(p->depth/far,0,1)));}pixels[y*width+x]=(uint16_t)lround(sum/(sx*sy));}
    CGColorSpaceRef gray=CGColorSpaceCreateDeviceGray();CGDataProviderRef provider=CGDataProviderCreateWithData(NULL,pixels,(size_t)width*height*2,NULL);
    CGImageRef image=provider?CGImageCreate(width,height,16,16,width*2,gray,kCGImageAlphaNone|kCGBitmapByteOrder16Little,provider,NULL,false,kCGRenderingIntentDefault):NULL;
    CFURLRef url=CFURLCreateFromFileSystemRepresentation(NULL,(const UInt8*)path,strlen(path),false);CGImageDestinationRef destination=url?CGImageDestinationCreateWithURL(url,CFSTR("public.png"),1,NULL):NULL;
    int ok=0;if(destination&&image){CGImageDestinationAddImage(destination,image,NULL);ok=CGImageDestinationFinalize(destination);}if(destination)CFRelease(destination);if(url)CFRelease(url);if(image)CGImageRelease(image);if(provider)CGDataProviderRelease(provider);CGColorSpaceRelease(gray);free(pixels);
    if(!ok){unlink(path);snprintf(error,512,"Could not write Z-buffer PNG");}return ok;
}
static int reuse_ambient,reuse_hard;
static Scene geometry_key(void){
    Scene key;memset(&key,0,sizeof key);
#define GEOMETRY(field) key.field=scene.field
    key.program_enabled=1;FormulaProgram program=scene.program_enabled?scene.program:legacy_program();
#define PROGRAM(field) key.program.field=program.field
    PROGRAM(mode);PROGRAM(repeat_from);PROGRAM(min_iterations);PROGRAM(numerical_de);PROGRAM(render_mode);PROGRAM(split);PROGRAM(repeat2);PROGRAM(max_iterations2);PROGRAM(combine);PROGRAM(bailout);PROGRAM(smooth);PROGRAM(formula_power);
#undef PROGRAM
    for(int i=0;i<8;i++){FormulaSlot *a=&key.program.slots[i],*b=&program.slots[i];a->kind=b->kind;a->power=b->power;a->count=b->count;a->z_multiplier=b->z_multiplier;a->scale=b->scale;a->min_radius=b->min_radius;a->fold=b->fold;memcpy(a->parameters,b->parameters,sizeof a->parameters);}
    GEOMETRY(width);GEOMETRY(height);GEOMETRY(oversampling);
    GEOMETRY(bin_search_steps);GEOMETRY(normal_smoothing);GEOMETRY(normal_zbuffer);GEOMETRY(iterations);GEOMETRY(power);GEOMETRY(power2);
    GEOMETRY(kind);GEOMETRY(kind2);GEOMETRY(count1);GEOMETRY(count2);GEOMETRY(repeat_from);
    GEOMETRY(zmul);GEOMETRY(zmul2);GEOMETRY(scale);GEOMETRY(scale2);GEOMETRY(min_radius);GEOMETRY(min_radius2);GEOMETRY(fold);GEOMETRY(fold2);
    GEOMETRY(color_option);GEOMETRY(color_multiplier);
    GEOMETRY(cutting_mask);memcpy(key.cutting,scene.cutting,sizeof key.cutting);
    GEOMETRY(julia);GEOMETRY(julia_c);GEOMETRY(julia_w);memcpy(key.rotation4,scene.rotation4,sizeof key.rotation4);GEOMETRY(optic);GEOMETRY(vary);GEOMETRY(bailout);GEOMETRY(zstart);GEOMETRY(zend);
    GEOMETRY(zoom);GEOMETRY(fov);GEOMETRY(de_stop);GEOMETRY(ray_step);GEOMETRY(center);GEOMETRY(direct_origin);GEOMETRY(view_origin);
#undef GEOMETRY
    memcpy(key.matrix,scene.matrix,sizeof key.matrix);return key;
}
static int ambient_cache_matches(void){
    ShadowSettings a=surface_cache.ambient_scene.shadows,b=scene.shadows;
    return surface_cache.ambient_valid&&(surface_cache.ambient_scene.ssao.threshold==scene.ssao.threshold&&surface_cache.ambient_scene.ssao.mirror==scene.ssao.mirror&&surface_cache.ambient_scene.ssao.samples==scene.ssao.samples)&&a.ambient_method==b.ambient_method&&a.ambient_rays==b.ambient_rays&&a.ambient_steps==b.ambient_steps&&a.ambient_length==b.ambient_length;
}
static int hard_cache_matches(void){
    ShadowSettings a=surface_cache.hard_scene.shadows,b=scene.shadows;
    if(!surface_cache.hard_valid||a.hard_mask!=b.hard_mask||a.soft!=b.soft||a.hard_length!=b.hard_length||a.hard_radius!=b.hard_radius)return 0;
    for(int i=0;i<6;i++){
        if(!(b.hard_mask&(1<<i)))continue;
        Light old=surface_cache.hard_scene.lights[i],current=scene.lights[i];
        int old_traces=!(old.option&(1|64)),current_traces=!(current.option&(1|64));
        if(old_traces!=current_traces)return 0;
        if(!current_traces)continue;
        if(old.option!=current.option||memcmp(&old.position,&current.position,sizeof current.position))return 0;
    }
    return 1;
}
#include "ssao.h"
#include "background.h"
static _Thread_local int reflection_secondary,reflection_cached_lighting;
static _Thread_local Vec last_specular_lighting;
static int fog_in_shading;
#ifndef USE_RUST_ENGINE
static double reflection_palette_opacity(Sample sample,double depth,int channel);
#include "emission_lighting.h"
#endif
static Vec fog_shade_primary(Vec color,const SurfacePixel *surface);
static Vec shade(Vec p,Vec ray,double ypos,double depth,double eps,int hit,int w,int h,unsigned char *record,const Vec *depthNormal,SurfacePixel *cached) {
    last_specular_lighting=(Vec){0};double bg_y=ypos;
    if(scene.ambient_object)bg_y=asin(clamp(ray.y,-1,1))/PI+.5;
    else if(scene.background_function==1)bg_y*=bg_y;
    else if(scene.background_function>1)bg_y=sqrt(bg_y);
    Vec background=mix(lighting_color(scene.bg_top),lighting_color(scene.bg_bottom),bg_y);
    if(record){memset(record,0,18);put16(record+8,32768);}
    /* A miss already sees the fog/background color at infinity. Fog attenuates
       surface lighting, never the background color itself. */
    if(!hit){
        if(back_pixels){double u=cached&&surface_cache.pixels?((cached-surface_cache.pixels)%w+.5)/w:.5+atan2(camera_unrotate(ray).x,camera_unrotate(ray).z)/(scene.fov*PI/180*w/h);Vec pic=lighting_color(back_picture_sample(ray,u,ypos,0));double fade=clamp(28000*scene.depth,0,1);if(scene.far_fog)fade*=fade;background=scene.preserved_header[439]&8?add(pic,mul(background,fade)):mix(pic,background,fade);}
        return gamma_color(fog_in_shading&&cached?fog_shade_primary(background,cached):background);
    }
    double roughness=0;Vec n;Sample sample;
    if(cached&&cached->prepared){n=cached->normal;roughness=cached->roughness;sample=cached->sample;}
    else{
        double baseDE=scene.de_stop/fmax(1,scene.oversampling);
        if(depthNormal&&!scene.normal_smoothing)n=*depthNormal;else n=surface_normal(p,eps*.15*fmin(1,baseDE)/baseDE,&roughness);
        roughness=lround(roughness*255)/255.;
        if(scene.program_enabled&&scene.program.render_mode&&dot(n,ray)>0)n=mul(n,-1);
        if(depthNormal)n=*depthNormal;
        sample=surface_color_sample(p,eps);
        if(cached){cached->normal=n;cached->roughness=roughness;cached->sample=sample;cached->prepared=1;}
    }
    roughness*=scene.roughness;
    Vec view_n=camera_unrotate(n),view_ray=camera_unrotate(ray);
    double visibility=1;
    if(scene.ao_enabled){
        if(cached&&(reuse_ambient||reflection_cached_lighting||scene.shadows.ambient_method>=2))visibility=cached->ambient_visibility;
        else{
            double occ=0,weight=1,total=0;
            if(!scene.shadows.ambient_method)for(int i=1;i<=5;i++){
                double d=eps*(3+i*6);occ+=weight*clamp(1-distance_bulb(add(p,mul(n,d)))/d,0,1);total+=weight;weight*=.65;
            }
            visibility=total?clamp(1-occ/total,0,1):1;
            if(scene.shadows.ambient_method)visibility=ambient_shadow(p,n,eps,w,h);
            if(cached)cached->ambient_visibility=visibility;
        }
    }
    double ao=ambient_visibility_strength(visibility,scene.ao_amount);if(internal_gamma2())ao=(ao*ao+ao)*.5;
    int gradient=(int)nearbyint(clamp(32767-fmax(0,sample.smooth)*32767/(color_iteration_limit()+1),0,32767));
    int trap=(int)clamp(sample.orbit_trap*4096,0,32767);
    int cut_surface=0;double coordinates[]={p.x,p.y,p.z};for(int i=0;i<3;i++)if((scene.cutting_mask&(1<<i))&&fabs(coordinates[i]-scene.cutting[i])<=eps*2)cut_surface=1;
    if(!reflection_secondary){atomic_fetch_add_explicit(&color_histogram[cut_surface?2:0][gradient],1,memory_order_relaxed);
    atomic_fetch_add_explicit(&color_histogram[1][trap],1,memory_order_relaxed);}
    Vec dif,spe;palette(sample.smooth,sample.orbit_trap,depth,&dif,&spe);
    if(cut_surface){
        ObjectLighting *colors=&scene.cutting_colors;double start=pow(colors->palette_start,4)*.000158025+32768,span=(pow(colors->palette_end,4)-pow(colors->palette_start,4))*.000158025;
        double value=span?(32768+gradient-start)*16384/span:0;if(scene.cycle)value=(unsigned)(int)value&32767;value=clamp(value,0,32767);
        int index=1;while(index<3&&colors->stops[index].position<value)index++;ObjectColorStop a=colors->stops[index-1],b=colors->stops[index];double f=scene.no_interpolation?0:clamp((value-a.position)/fmax(1,(double)b.position-a.position),0,1);
        dif=mix((Vec){a.diffuse[0],a.diffuse[1],a.diffuse[2]},(Vec){b.diffuse[0],b.diffuse[1],b.diffuse[2]},f);spe=mix((Vec){a.specular[0],a.specular[1],a.specular[2]},(Vec){b.specular[0],b.specular[1],b.specular[2]},f);
    }
    if(map_pixels)dif=object_map_color(p,n,sample,dif);
    dif=lighting_color(dif);spe=lighting_color(spe);
    if(record) {
        put16(record,(int)lround(view_n.x*32767));put16(record+2,(int)lround(view_n.y*32767));put16(record+4,(int)lround(view_n.z*32767));
        double step=2.1345/(scene.zoom*w),zc=sin(fmax(scene.fov*PI/180,1)/h);
        double zm=8388352/(sqrt((scene.zend-scene.zstart)*zc/step+1)-.999999999);
        unsigned z=(unsigned)lround(clamp(8388352-zm*(sqrt(depth*zc/step+1)-1),0,8388352));
        put32(record+6,(z<<8)|(unsigned)lround(roughness*255));put16(record+12,lround((1-visibility)*16383));put16(record+14,gradient);put16(record+16,trap);
    }
    Vec ambient=mul(product(mix(lighting_color(scene.amb_top),lighting_color(scene.amb_bottom),
                  clamp((scene.ambient_object?n.y:view_n.y)*.5+.5,0,1)),dif),ao*scene.ambient);
    if(back_pixels&&(scene.preserved_header[439]&32))ambient=mul(product(lighting_color(back_picture_sample(n,0,0,1)),dif),ao*scene.ambient);
    Vec diffuse_obj=mul(dif,scene.diffuse),unshadowed={0,0,0},direct=ambient,highlights={0};
    for(int i=0;i<6;i++) {
        Light l=scene.lights[i];if(l.option&3)continue;
        double pixelStep=2.1345/(scene.zoom*w),depthInPixels=depth/pixelStep,rangeInPixels=(scene.zend-scene.zstart)/pixelStep;
        Vec light;double intensity=l.amplitude,max_shadow=pixelStep*(w+ypos*h)*.6*(1+.5*fmin(depthInPixels,rangeInPixels*.4)*(scene.optic==2?PI:scene.fov*PI/180)/h)*scene.shadows.hard_length;
        if(l.option&4) {
            Vec delta=add(l.position,mul(p,-1));double rr=dot(delta,delta);max_shadow=fmin(max_shadow,sqrt(rr));
            light=camera_unrotate(unit(delta));intensity*=1.3/fmax(rr,1e-30);
        } else {
            double xa=l.position.x,ya=l.position.y;
            light=unit((Vec){-sin(xa),-sin(ya),-cos(xa)*cos(ya)});
            if(l.option&32)light=camera_unrotate(light);
        }
        double d=clamp(dot(view_n,light),-1,1),diffuse;
        diffuse=diffuse_lobe(scene.shadows.hard_enabled&&scene.shadows.cosine&&(scene.shadows.hard_mask&(1<<i))?0:(l.function>>4)&3,d,roughness);
        int exponent=2<<(l.function&7);
        Vec half_vec=unit(add(light,mul(view_ray,-1)));
        double specular=pow(fmax(0,dot(view_n,half_vec)),exponent)*scene.specular*(1+fmin(1,roughness*2)*(1./exponent-1));
        /* PaintThread.bSubAmbSh: without a calculated hard shadow this
           light receives full AO. Diffuse shadow is the blend for lights
           whose hard shadows have been calculated. */
        int hasHardShadow=scene.shadows.hard_enabled&&(scene.shadows.hard_mask&(1<<i));
        double visibility=((l.option&64)||hasHardShadow)?1-scene.diffuse_shadow*(1-ao):ao;
        if(!(l.option&64)&&scene.shadows.hard_enabled&&(scene.shadows.hard_mask&(1<<i))) {
            double shadow;if(cached&&(reuse_hard||reflection_cached_lighting))shadow=cached->hard_visibility[i];else{shadow=d<=0?0:shadow_ray(add(p,mul(ray,-pixelStep*.1)),camera_rotate(light),max_shadow,eps,2048,scene.shadows.soft?scene.shadows.hard_radius*((l.option&4)?2:1):0,pixelStep,depth,distance_bulb);if(cached)cached->hard_visibility[i]=shadow;}
            visibility*=shadow;
            if(record){unsigned value=u16(record+10);if(scene.shadows.soft&&__builtin_popcount((unsigned)scene.shadows.hard_mask)==1)value=(unsigned)lround(shadow*63)<<10;else if(shadow<.5)value|=1u<<(10+i);put16(record+10,value);}
        }
        if(internal_gamma2())diffuse*=diffuse;
        Vec lc=mul(lighting_color(l.color),intensity);
        unshadowed=add(unshadowed,mul(lc,diffuse+scene.specular/exponent));
        highlights=add(highlights,mul(product(spe,lc),specular*visibility));
        direct=add(direct,add(mul(product(diffuse_obj,lc),diffuse*visibility),
                               mul(product(spe,lc),specular*visibility)));
    }
    Vec indirect=add(ambient,mul(product(diffuse_obj,unshadowed),ao*(internal_gamma2()?.11:.3)));
    double dark=1-ao,second=pow(dark,4);
    Vec bounce=product(indirect,product(dif,add(mul(dif,second*scene.indirect),
                                        (Vec){dark-second,dark-second,dark-second})));
    Vec lit=add(direct,bounce);
    if(scene.light_mixing){double amount=(1-ao)*(1-ao)*scene.indirect,luminance=dot(direct,(Vec){.3,.59,.11})*255+4;lit=add(direct,mul(product(direct,dif),amount));double out=fmax(0,dot(lit,(Vec){.3,.59,.11})*255);lit=mul(lit,(luminance+(luminance+128)*(amount+.11)*.04)/(out+3));}
#ifndef USE_RUST_ENGINE
    /* DIFS opacity blends emission with a normally shaded receiving surface. */
    int emissive=0;double irradiance=0;
    if(scene.fog.mode==2){
        if(cached&&cached->emission_valid){emissive=cached->emission_source;irradiance=cached->emission_irradiance;}
        else{emissive=reflection_surface_difs(p);if(!emissive||(scene.reflections.opacity_set&&reflection_palette_opacity(sample,depth,0)<1))irradiance=emission_red_irradiance(p,n,eps);
            if(cached&&!render_cancelled()){cached->emission_source=emissive;cached->emission_irradiance=irradiance;cached->emission_valid=1;}}
    }
    if(cached)cached->emissive=emissive;
    /* The displayed emitter and transported light use the same unit radiance. */
    if(scene.fog.mode==2){double strength=emissive?(scene.reflections.opacity_set?reflection_palette_opacity(sample,depth,0):1):0;lit=add(mul(lit,1-strength),lighting_color(mul(emission_color(),strength)));lit=add(lit,mul(emission_receiver_contrast(mul(product(diffuse_obj,emission_color()),irradiance*(1-strength))),EMISSION_ILLUMINATION_GAIN));lit=add(lit,mul(product(diffuse_obj,emission_bounce),1-strength));highlights=mul(highlights,1-strength);}
#endif
    double step=2.1345/(scene.zoom*w),zcorr=sin(fmax(scene.fov*PI/180,1)/h);
    double zpos=32767*(1-(sqrt(depth*zcorr/step+1)-1)/
                  (sqrt((scene.zend-scene.zstart)*zcorr/step+1)-.999999999));
    double blend=clamp((28000-zpos)*scene.depth,0,1);
    if(scene.far_fog)blend*=blend;
    last_specular_lighting=mul(highlights,1-blend);
    Vec linear=mix(lit,background,blend);
    return gamma_color(fog_in_shading&&cached?fog_shade_primary(linear,cached):linear);
}
static SurfacePixel *surface_pixels;
static int surface_pass;
static Vec cross(Vec a,Vec b){return (Vec){a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};}
static Vec depth_tangent(Vec a,Vec b,double scale){double wa=1/(dot(a,a)+scale*scale),wb=1/(dot(b,b)+scale*scale);return mul(add(mul(a,wa),mul(b,wb)),1/(wa+wb));}
static void compute_depth_normals(int w,int h){
    double step=2.1345/(scene.zoom*w),factor=(scene.optic==2?PI:scene.fov*PI/180)/h;
    for(int y=0;y<h;y++)for(int x=0;x<w;x++){
        SurfacePixel *s=surface_pixels+y*w+x;if(!s->hit)continue;
        SurfacePixel *left=x? s-1:NULL,*right=x+1<w?s+1:NULL,*up=y?s-w:NULL,*down=y+1<h?s+w:NULL;
        if(left&&!left->hit)left=NULL;if(right&&!right->hit)right=NULL;if(up&&!up->hit)up=NULL;if(down&&!down->hit)down=NULL;
        double scale=step+s->depth*factor;
        Vec dx=camera_rotate((Vec){-step,0,0}),dy=camera_rotate((Vec){0,-step,0});
        if(left)dx=add(left->point,mul(s->point,-1));if(right){Vec next=add(s->point,mul(right->point,-1));dx=left?depth_tangent(dx,next,scale):next;}
        if(up)dy=add(up->point,mul(s->point,-1));if(down){Vec next=add(s->point,mul(down->point,-1));dy=up?depth_tangent(dy,next,scale):next;}
        s->normal=unit(cross(dy,dx));
    }
}
static Vec pixel(int x,int y,int w,int h,unsigned char *record) {
    INFO_PHASE(0);unsigned info_steps=0;int info_capped=0;
    RENDER_COUNT(primary);
    const double fov=scene.optic==2?PI:scene.fov*PI/180, step=2.1345/(scene.zoom*w);
    double px=x+.5,py=y+.5;
    /* MB3D rays start across the Zstart plane, not at a pinhole. */
    Vec origin={(px-w*.5)*step,(py-h*.5)*step,scene.zstart-scene.center.z};
    double ax=(py/h-.5)*fov, ay=(w*.5-px)*fov/h;
    Vec ray=unit((Vec){-sin(ay),sin(ax),cos(ax)*cos(ay)});
    if(scene.optic==1)ray=unit((Vec){-ay,ax,cos(fov*.5)*(fov*.5)/sin(fov*.5)});
    else if(scene.optic==2) {
        origin=(Vec){0,0,scene.zstart-scene.center.z};
        double yaw=(px/w-.5)*2*PI,pitch=(py/h-.5)*PI;
        ray=(Vec){sin(yaw)*cos(pitch),sin(pitch),cos(yaw)*cos(pitch)};
    }
    if(scene.direct_origin) {
        origin.z=0;origin=add(scene.view_origin,camera_rotate(origin));
    } else origin=add(scene.center,camera_rotate(origin));
    ray=camera_rotate(ray);
    double t=0,previousT=0,eps=step*.5; Vec p=origin;
    int hit=0,start_inside=-1;double lastDE=0,lastStep=0,stepFactor=1;
    for(int s=0;s<10000 && t<=scene.zend-scene.zstart&&!render_cancelled();s++) {
        info_steps++;p=add(origin,mul(ray,t));eps=step*scene.de_stop*(1+(scene.vary?t*fov/(h*step):0));Sample raySample=evaluate_hit(p,eps);double d=fmax(scene.de_stop*.25*step,raySample.distance);
        eps=step*scene.de_stop*(1+(scene.vary?t*fov/(h*step):0));
        if(s>0){d=fmin(d,lastDE+lastStep);stepFactor=lastDE>d+1e-30?clamp(lastStep/(lastDE-d),.5,1):1;}
        if(scene.program_enabled&&scene.program.render_mode) {
            int inside=raySample.smooth>=scene.iterations;
            if(start_inside<0)start_inside=inside;
            /* Both mode selects the side at the start plane, rather than
               walking through the first object reached from outside. */
            if(scene.program.render_mode!=2||start_inside) {
            if(inside){double previous=t,walk=fmax(step*.5,eps*.5);int exit=0;
                for(int j=0;j<200000&&t<=scene.zend-scene.zstart;j++){info_steps++;previous=t;t+=walk;p=add(origin,mul(ray,t));if(evaluate(p).smooth<scene.iterations){exit=1;break;}if(j==199999&&t<=scene.zend-scene.zstart)info_capped=1;}
                if(exit){INFO_PHASE(2);double lo=previous,hi=t;for(int j=0;j<12;j++){double mid=(lo+hi)*.5;if(evaluate(add(origin,mul(ray,mid))).smooth>=scene.iterations)lo=mid;else hi=mid;}t=(lo+hi)*.5;p=add(origin,mul(ray,t));hit=1;}break;
            }
            if(scene.program.render_mode==1){previousT=t;t+=fmax(d*scene.ray_step,step*.5);continue;}
            }
        }
        if(d<=eps||raySample.smooth>=scene.iterations) { if(cutout_blocked(p)){previousT=t;t+=step*.5;continue;}if(!scene.program_enabled||raySample.smooth>=scene.program.min_iterations){
            if(t>previousT){INFO_PHASE(2);double lo=previousT,hi=t;for(int refine=0;refine<scene.bin_search_steps;refine++){double mid=(lo+hi)*.5,threshold=step*scene.de_stop*(1+(scene.vary?mid*fov/(h*step):0));Vec candidate=add(origin,mul(ray,mid));Sample candidateSample=evaluate_hit(candidate,threshold);if(candidateSample.distance<=threshold||candidateSample.smooth>=scene.iterations)hi=mid;else lo=mid;}t=hi;p=add(origin,mul(ray,t));eps=step*scene.de_stop*(1+(scene.vary?t*fov/(h*step):0));}
            hit=1;break;}previousT=t;t+=step;continue; }
        previousT=t;lastDE=d;lastStep=fmax(d*scene.ray_step*stepFactor,step*.11);t+=lastStep;if(s==9999&&t<=scene.zend-scene.zstart)info_capped=1;
    }
    info_ray(info_steps,hit,info_capped);
    if(surface_pixels){surface_pixels[y*w+x]=(SurfacePixel){.point=p,.ray=ray,.depth=t,.eps=eps,.hit=hit};return (Vec){0};}
    return shade(p,ray,py/h,t,eps,hit,w,h,record,NULL,NULL);

}
typedef struct {
    int width,height;
    size_t stride;
    unsigned char *pixels;
    atomic_int next_row,allocation_failed;
} RenderJob;
static void *render_worker(void *arg) {
    INFO_WORKER;info_phase=7;
    RenderJob *job=arg;unsigned char *records=m3i_fd>=0?malloc((size_t)job->width*18):NULL;
    if(m3i_fd>=0&&!records){atomic_store(&job->allocation_failed,1);return NULL;}
    for(;;) {
        int y=atomic_fetch_add_explicit(&job->next_row,1,memory_order_relaxed);
        if(y>=job->height||render_cancelled())break;
#ifdef USE_C_FORMULA_VM
        if(atomic_load(&cf_error))break;
#endif
        unsigned char *row=job->pixels+(size_t)(job->height-1-y)*job->stride;
        for(int x=0;x<job->width&&!render_cancelled();x++) {
            Vec c;unsigned char *record=m3i_fd>=0?records+x*18:NULL;
            if(surface_pass){SurfacePixel *s=surface_pixels+y*job->width+x;c=shade(s->point,s->ray,(y+.5)/job->height,s->depth,s->eps,s->hit,job->width,job->height,record,scene.normal_zbuffer?&s->normal:NULL,s);}
            else c=pixel(x,y,job->width,job->height,record);
            row[x*3]=(unsigned char)lround(255*clamp(c.z,0,1));
            row[x*3+1]=(unsigned char)lround(255*clamp(c.y,0,1));
            row[x*3+2]=(unsigned char)lround(255*clamp(c.x,0,1));
        }
        if(m3i_fd>=0&&(!surface_pixels||surface_pass))writeAt(records,(size_t)job->width*18,840+(off_t)y*job->width*18);
        if(active_cancel)atomic_fetch_add(&active_cancel->rows,1);
    }
    free(records);return NULL;
}
/* Main also renders, so a failed worker creation simply reduces concurrency.
 * Each claimed row has one writer; the scene is immutable and output writing
 * starts only after every worker has joined. Scheduling cannot change pixels.
 */
static void render_image(RenderJob *job,int threads) {
    pthread_t workers[255];int started=0;
    if(threads>job->height)threads=job->height;
    struct timespec start,end;clock_gettime(CLOCK_MONOTONIC,&start);
    for(int i=1;i<threads;i++) {
        int error=pthread_create(&workers[started],NULL,render_worker,job);
        if(error) {fprintf(stderr,"Warning: could not start worker: %s; using %d threads\n",strerror(error),started+1);break;}
        started++;
    }
    render_worker(job);
    for(int i=0;i<started;i++) {
        int error=pthread_join(workers[i],NULL);
        if(error){fprintf(stderr,"Could not join render worker: %s\n",strerror(error));exit(1);}
    }
    clock_gettime(CLOCK_MONOTONIC,&end);
    double elapsed=end.tv_sec-start.tv_sec+(end.tv_nsec-start.tv_nsec)*1e-9;
    fprintf(stderr,"Render: %.3f seconds, %d thread%s\n",elapsed,started+1,started?"s":"");
}

void camera_move(CameraSettings *camera,double right,double down,double forward) {
    for(int i=0;i<3;i++)camera->origin[i]+=right*camera->axes[i]+down*camera->axes[3+i]+forward*camera->axes[6+i];
}
static void turn_pair(double *a,double *b,double degrees) {
    double c=cos(degrees*PI/180),s=sin(degrees*PI/180);
    for(int i=0;i<3;i++){double old=a[i];a[i]=old*c+b[i]*s;b[i]=b[i]*c-old*s;}
}
void camera_turn(CameraSettings *camera,double yaw,double pitch,double roll) {
    turn_pair(camera->axes+6,camera->axes,yaw);
    turn_pair(camera->axes+6,camera->axes+3,pitch);
    turn_pair(camera->axes,camera->axes+3,roll);
}
static int valid_camera(CameraSettings camera) {
    double scalars[]={camera.zoom,camera.fov,camera.distance,camera.origin[0],camera.origin[1],camera.origin[2]};
    for(unsigned i=0;i<sizeof scalars/sizeof *scalars;i++)if(!isfinite(scalars[i])||fabs(scalars[i])>1e15)return 0;
    if(camera.zoom<1e-12||camera.zoom>1e12||camera.fov<.001||camera.fov>=180||camera.distance<=0||camera.optic<0||camera.optic>2)return 0;
    for(int i=0;i<3;i++)for(int j=0;j<=i;j++) {
        double d=0;for(int k=0;k<3;k++){if(!isfinite(camera.axes[i*3+k])||!isfinite(camera.axes[j*3+k]))return 0;d+=camera.axes[i*3+k]*camera.axes[j*3+k];}
        if(fabs(d-(i==j?1:0))>1e-5)return 0;
    }
    return 1;
}
#include "fog.h"
#include "reflections.h"

static RenderOptions scene_settings(int w,int h,int threads,int cameraOverride) {
    RenderOptions settings=(RenderOptions){.oversampling=scene.oversampling,.viewing=scene.viewing,.size_flags=scene.size_flags,.width=w,.height=h,.threads=threads,.iterations=scene.iterations,
        .de_stop=scene.de_stop,.ray_step=scene.ray_step,.formula_override=1,.power=scene.power,.z_multiplier=scene.zmul,.sequence_override=1,.power2=scene.power2,.z_multiplier2=scene.zmul2,
        .count1=scene.count1,.count2=scene.count2,.repeat_from=scene.repeat_from,.kind=scene.kind,.kind2=scene.kind2,
        .scale=scene.scale,.min_radius=scene.min_radius,.fold=scene.fold,.scale2=scene.scale2,.min_radius2=scene.min_radius2,.fold2=scene.fold2};
    Vec view_origin=scene.direct_origin?scene.view_origin:add(scene.center,camera_rotate((Vec){0,0,scene.zstart-scene.center.z}));
    Vec midpoint=scene.center;double start=scene.zstart,end=scene.zend;
    if(scene.direct_origin){midpoint=add(view_origin,camera_rotate((Vec){0,0,(end-start)*.5}));start=midpoint.z-(end-start)*.5;end=midpoint.z+(scene.zend-scene.zstart)*.5;}
    double position[]={midpoint.x,midpoint.y,midpoint.z,start,end,scene.zoom};memcpy(settings.position,position,sizeof position);
    settings.normals_override=1;settings.normal_smoothing=scene.normal_smoothing;settings.normal_zbuffer=scene.normal_zbuffer;
    settings.gamma_override=1;settings.gamma=scene.gamma;settings.stepcount_override=1;settings.stepcount=scene.bin_search_steps;
    settings.preserved_header_valid=scene.preserved_header_valid;memcpy(settings.preserved_header,scene.preserved_header,840);
    settings.program_override=1;settings.program=scene.program_enabled?scene.program:legacy_program();
    settings.cutting_colors_override=1;settings.cutting_colors=scene.cutting_colors;
    settings.cutting_override=1;settings.cutting_mask=scene.cutting_mask;memcpy(settings.cutting,scene.cutting,sizeof settings.cutting);
    settings.rotation4_override=1;memcpy(settings.rotation4,scene.rotation4,sizeof settings.rotation4);settings.julia_w=scene.julia_w;
    settings.julia_override=1;settings.julia=scene.julia;settings.julia_c[0]=scene.julia_c.x;settings.julia_c[1]=scene.julia_c.y;settings.julia_c[2]=scene.julia_c.z;
    settings.camera_override=cameraOverride;
    settings.camera=(CameraSettings){.origin={view_origin.x,view_origin.y,view_origin.z},.zoom=scene.zoom,
        .fov=scene.fov,.distance=scene.zend-scene.zstart,.optic=scene.optic};
    memcpy(settings.camera.axes,scene.matrix,sizeof scene.matrix);
    settings.ambient_override=1;settings.ambient=(AmbientLighting){.roughness=scene.roughness,.strength=scene.ambient,.depth=scene.depth,.second_reflection=scene.indirect,.diffuse_shadow=scene.diffuse_shadow,.relative_to_object=scene.ambient_object,.far_fog=scene.far_fog,.gradient=scene.background_function>2?2:scene.background_function,.light_mixing=scene.light_mixing};
    Vec ambientColors[]={scene.amb_top,scene.amb_bottom,scene.bg_top,scene.bg_bottom};for(int i=0;i<4;i++){settings.ambient.colors[i][0]=ambientColors[i].x;settings.ambient.colors[i][1]=ambientColors[i].y;settings.ambient.colors[i][2]=ambientColors[i].z;}
    settings.ssao_override=1;settings.ssao=scene.ssao;settings.color_option=scene.color_option;settings.color_multiplier=scene.color_multiplier;
    settings.fog_override=1;settings.fog=scene.fog;
    settings.dof_override=1;settings.dof=scene.dof;settings.reflections_override=1;settings.reflections=scene.reflections;settings.transmission_blur=scene.transmission_blur;settings.translucency_glow=scene.translucency_glow;settings.translucency_mode=scene.translucency_mode;settings.subsurface_scattering=scene.subsurface_scattering;settings.subsurface_amount=scene.subsurface_amount;
    settings.shadows_override=1;settings.shadows=scene.shadows;
    settings.lights_override=1;
    for(int i=0;i<6;i++) {
        Light l=scene.lights[i];settings.lights[i]=(LightSettings){l.option,l.function,l.amplitude,
            {l.color.x,l.color.y,l.color.z},{l.position.x,l.position.y,l.position.z}};
    }
    settings.object_override=1;
    ObjectLighting *object=&settings.object;
    *object=(ObjectLighting){.map=scene.map,.diffuse=scene.diffuse,.specular=scene.specular,.palette_start=scene.cstart,
        .palette_end=scene.cstart+scene.cspan,.z_variation=scene.z_variation,.cycling=scene.cycle,
        .no_interpolation=scene.no_interpolation,.orbit_trap=scene.color_on_trap};
    for(int i=0;i<10;i++) {
        Stop stop=scene.stops[i];object->stops[i]=(ObjectColorStop){stop.position,
            {stop.diffuse.x,stop.diffuse.y,stop.diffuse.z},{stop.specular.x,stop.specular.y,stop.specular.z}};
    }
    return settings;
}
int read_scene_settings(const char *input,RenderOptions *settings,char error[512]) {
    error[0]=0;scene_defaults();if(!input||!settings||!load_m3i(input)){snprintf(error,512,"%s",scene_error[0]?scene_error:"Cannot load scene parameters.");return 0;}

    *settings=scene_settings(scene.width,scene.height,0,0);return 1;
}
RenderResult render_scene(const char *input,int width,int height,int threads) {
    return render_scene_with_options(input,(RenderOptions){.width=width,.height=height,.threads=threads});
}
/* Native bounded-sample, depth-aware disc filter. Starts from freshly relit
   surface colors on every call, so parameter edits never accumulate blur. */
static double dof_blur_radius(double depth,int width,int height,double zoom,double fov,DepthOfFieldSettings d){
    double slope=fov*PI/180/height,lo=fmin(d.focus1,d.focus2)*width,hi=fmax(d.focus1,d.focus2)*width;
    double ratio=(1+lo*slope)/(1+hi*slope),focus=(ratio*hi+lo)/(1+ratio),aperture=d.aperture*.5;
    double subtract=fabs((lo-focus)/(1+lo*slope)*aperture),z=depth*zoom*width/2.1345;
    return fmin(d.clip_radius,fmax(0,fabs((z-focus)/(1+z*slope)*aperture)-subtract));
}
typedef struct {int width,height;atomic_int row;const unsigned char *source;unsigned char *dest;const float *radii;const SurfacePixel *surface;double taps[64][2];double pass_scale;} DofJob;
static void *dof_worker(void *arg){
    DofJob *job=arg;int w=job->width,h=job->height;
    for(;;){int y=atomic_fetch_add(&job->row,1);if(y>=h||render_cancelled())break;
        for(int x=0;x<w;x++){
            size_t index=(size_t)y*w+x;double radius=job->radii[index]*job->pass_scale;
            unsigned char *out=job->dest+index*4;const unsigned char *center=job->source+index*4;
            if(radius<.5){memcpy(out,center,4);continue;}
            double color[3]={center[0],center[1],center[2]},total=1;
            for(int k=0;k<64;k++){
                int sx=(int)lround(x+job->taps[k][0]*radius),sy=(int)lround(y+job->taps[k][1]*radius);
                if(sx<0||sx>=w||sy<0||sy>=h)continue;size_t n=(size_t)sy*w+sx;
                /* Keep sharply focused foreground from bleeding into a distant blur. */
                if(job->surface[n].hit&&job->surface[n].depth<job->surface[index].depth&&job->radii[n]<.5)continue;
                const unsigned char *pixel=job->source+n*4;for(int c=0;c<3;c++)color[c]+=pixel[c];total++;
            }
            for(int c=0;c<3;c++)out[c]=(unsigned char)lround(color[c]/total);out[3]=255;
        }
    }return NULL;
}
static unsigned char **sharp_capture; /* Serial, opt-in main-window snapshot. */
static int apply_depth_of_field(RenderResult *result,int threads){
    if(!scene.dof.enabled||scene.dof.aperture==0)return 1;
    int w=result->width,h=result->height;size_t count=(size_t)w*h;
    if(sharp_capture){*sharp_capture=malloc(result->stride*h);if(!*sharp_capture)return 0;memcpy(*sharp_capture,result->rgba,result->stride*h);}
    if(!surface_cache.pixels)return 0;
    float *radii=malloc(count*sizeof *radii);unsigned char *buffer=malloc(count*4);
    if(!radii||!buffer){free(radii);free(buffer);return 0;}
    for(size_t i=0;i<count;i++){SurfacePixel p=surface_cache.pixels[i];radii[i]=dof_blur_radius(p.hit?p.depth:scene.zend-scene.zstart,w,h,scene.zoom,scene.optic==2?180:scene.fov,scene.dof);}
    DofJob job={.width=w,.height=h,.radii=radii,.surface=surface_cache.pixels,.pass_scale=1/sqrt(scene.dof.passes)};
    for(int k=0;k<64;k++){double angle=k*2.399963229728653,r=sqrt((k+.5)/64.);job.taps[k][0]=cos(angle)*r;job.taps[k][1]=sin(angle)*r;}
    if(!threads){long n=sysconf(_SC_NPROCESSORS_ONLN);threads=(int)fmax(1,fmin(256,n));}
    for(int pass=0;pass<scene.dof.passes&&!render_cancelled();pass++){
        atomic_init(&job.row,0);job.source=result->rgba;job.dest=buffer;
        pthread_t workers[255];int started=0;
        for(int i=1;i<threads;i++){if(pthread_create(&workers[started],NULL,dof_worker,&job))break;started++;}
        dof_worker(&job);for(int i=0;i<started;i++)pthread_join(workers[i],NULL);
        unsigned char *swap=result->rgba;result->rgba=buffer;buffer=swap;
    }
    free(radii);free(buffer);return 1;
}
#ifndef USE_RUST_ENGINE
#include "emission_glow.h"
#endif
static RenderResult render_scene_core(const char *input,RenderOptions options) {
    int width=options.width,height=options.height,threads=options.threads;
    RenderResult result={0};
    scene_defaults();
#ifdef USE_C_FORMULA_VM
    atomic_store(&cf_error,0);cf_error_message[0]=0;
#endif
    if(input && !load_m3i(input)) {
        snprintf(result.error,sizeof result.error,"%s",scene_error[0]?scene_error:"Could not open scene file");
        return result;
    }
    if(options.preserved_header_valid){scene.preserved_header_valid=1;memcpy(scene.preserved_header,options.preserved_header,840);}
    if(options.cutting_colors_override)scene.cutting_colors=options.cutting_colors;
    if(options.cutting_override){
        if(options.cutting_mask<0||options.cutting_mask>7){snprintf(result.error,sizeof result.error,"Invalid cutting plane mask");return result;}
        for(int i=0;i<3;i++)if(!isfinite(options.cutting[i])){snprintf(result.error,sizeof result.error,"Cutting positions must be finite");return result;}
        scene.cutting_mask=options.cutting_mask;memcpy(scene.cutting,options.cutting,sizeof scene.cutting);
    }
    memset(scene.preserved_header+382,0,28); /* Never restore author names from saved UI/animation state. */
    scene.raystep_limiter=1;put32f(scene.preserved_header+242,1);
    if(options.preserved_header_valid&&!options.stepcount_override)scene.bin_search_steps=options.preserved_header[134]>31?31:options.preserved_header[134];
    if(options.stepcount_override){if(!isfinite(options.stepcount)||options.stepcount<0||options.stepcount>31||options.stepcount!=floor(options.stepcount)){snprintf(result.error,sizeof result.error,"Stepcount must be an integer 0–31");return result;}scene.bin_search_steps=(int)options.stepcount;}
    if(options.gamma_override){if(!isfinite(options.gamma)||options.gamma<0||options.gamma>63){snprintf(result.error,sizeof result.error,"Invalid gamma slider value (0–63)");return result;}scene.gamma=(int)lround(options.gamma); }
    if(options.rotation4_override){
        double values[]={options.rotation4[0],options.rotation4[1],options.rotation4[2],options.julia_w};
        for(int i=0;i<4;i++)if(!isfinite(values[i])||fabs(values[i])>1e15){snprintf(result.error,sizeof result.error,"Invalid 4D rotation or Julia W constant");return result;}
        memcpy(scene.rotation4,options.rotation4,sizeof scene.rotation4);scene.julia_w=options.julia_w;
    }
    prepare_rotation4();
    int w=width?width:scene.width,h=height?height:scene.height;
    if(options.oversampling){scene.oversampling=options.oversampling;scene.size_flags=options.size_flags;}
    if(options.viewing)scene.viewing=options.viewing;
    if(scene.oversampling<1||scene.oversampling>6||scene.viewing<1||scene.viewing>scene.oversampling*10||scene.viewing%scene.oversampling||w%scene.oversampling||h%scene.oversampling){snprintf(result.error,sizeof result.error,"Invalid oversampling or Viewing");return result;}
    if(w<16||w>RENDER_MAX_DIMENSION||h<16||h>RENDER_MAX_DIMENSION||threads<0||threads>256) {
        snprintf(result.error,sizeof result.error,"Invalid size or thread count");return result;
    }
    if(options.iterations<0||options.iterations>10000||!isfinite(options.de_stop)||
       !isfinite(options.ray_step)||options.de_stop<0||options.de_stop>100||
       (options.de_stop>0&&options.de_stop<1e-6)||options.ray_step<0||options.ray_step>1||
       (options.ray_step>0&&options.ray_step<1e-6)) {
        snprintf(result.error,sizeof result.error,"Invalid calculation settings");return result;
    }
    if(options.julia_override) {
        if(options.julia<0||options.julia>1){snprintf(result.error,sizeof result.error,"Invalid Julia mode");return result;}
        for(int i=0;i<3;i++)if(!isfinite(options.julia_c[i])||fabs(options.julia_c[i])>1e6){snprintf(result.error,sizeof result.error,"Julia coordinates must be finite and within −1000000..1000000");return result;}
        scene.julia=options.julia;scene.julia_c=(Vec){options.julia_c[0],options.julia_c[1],options.julia_c[2]};
    }
    if(options.camera_override) {
        CameraSettings camera=options.camera;
        if(!valid_camera(camera)){snprintf(result.error,sizeof result.error,"Invalid Navigator camera");return result;}
        scene.direct_origin=1;scene.view_origin=(Vec){camera.origin[0],camera.origin[1],camera.origin[2]};
        memcpy(scene.matrix,camera.axes,sizeof scene.matrix);
        scene.zoom=camera.zoom;scene.fov=camera.fov;scene.optic=camera.optic;
        scene.zstart=0;scene.zend=camera.distance;
        scene.col_z=scene.z_variation*-.005/2.1345*scene.zoom;
    }
    if(options.formula_override&&!options.program_override) {
        if(options.kind!=0&&options.kind!=4){snprintf(result.error,sizeof result.error,"Unsupported formula");return result;}
        if(options.kind==0) {
            if(options.power<2||options.power>8||!isfinite(options.z_multiplier)||fabs(options.z_multiplier)>100) {
                snprintf(result.error,sizeof result.error,"Integer Power requires power 2–8 and Z multiplier −100..100");return result;
            }
            scene.power=options.power;scene.zmul=options.z_multiplier;
        } else {
            if(!isfinite(options.scale)||fabs(options.scale)>100||!isfinite(options.min_radius)||fabs(options.min_radius)>100||!isfinite(options.fold)||fabs(options.fold)>100) {
                snprintf(result.error,sizeof result.error,"Amazing Box: scale/fold −100..100, Min R −100..100");return result;
            }
            scene.scale=options.scale;scene.min_radius=options.min_radius;scene.fold=options.fold;
        }
        scene.kind=options.kind;
    }
    if(options.sequence_override&&!options.program_override) {
        if(options.count1<1||options.count1>10000||options.count2<0||options.count2>10000||
           options.repeat_from<0||options.repeat_from>1||(options.repeat_from==1&&options.count2==0)) {
            snprintf(result.error,sizeof result.error,"Invalid iteration counts or repeat point");return result;
        }
        if(options.kind2!=0&&options.kind2!=4){snprintf(result.error,sizeof result.error,"Unsupported second formula");return result;}
        if(options.kind2==0) {
            if(options.power2<2||options.power2>8||!isfinite(options.z_multiplier2)||fabs(options.z_multiplier2)>100) {
                snprintf(result.error,sizeof result.error,"Second Integer Power: power 2–8, Z multiplier −100..100");return result;
            }
            scene.power2=options.power2;scene.zmul2=options.z_multiplier2;
        } else {
            if(!isfinite(options.scale2)||fabs(options.scale2)>100||!isfinite(options.min_radius2)||fabs(options.min_radius2)>100||!isfinite(options.fold2)||fabs(options.fold2)>100) {
                snprintf(result.error,sizeof result.error,"Second Amazing Box: scale/fold −100..100, Min R −100..100");return result;
            }
            scene.scale2=options.scale2;scene.min_radius2=options.min_radius2;scene.fold2=options.fold2;
        }
        scene.kind2=options.kind2;scene.count1=options.count1;scene.count2=options.count2;scene.repeat_from=options.repeat_from;
    }
    /* Keep valid inactive parameter values when switching formula menus. */
    if(options.formula_override && !options.program_override && options.kind==0 && isfinite(options.scale)&&fabs(options.scale)<=100&&
       isfinite(options.min_radius)&&fabs(options.min_radius)<=100&&isfinite(options.fold)&&fabs(options.fold)<=100) {
        scene.scale=options.scale;scene.min_radius=options.min_radius;scene.fold=options.fold;
    }
    if(options.formula_override && !options.program_override && options.kind==4 && options.power>=2&&options.power<=8&&isfinite(options.z_multiplier)&&fabs(options.z_multiplier)<=100) {
        scene.power=options.power;scene.zmul=options.z_multiplier;
    }
    if(options.sequence_override && !options.program_override && options.kind2==0 && isfinite(options.scale2)&&fabs(options.scale2)<=100&&
       isfinite(options.min_radius2)&&fabs(options.min_radius2)<=100&&isfinite(options.fold2)&&fabs(options.fold2)<=100) {
        scene.scale2=options.scale2;scene.min_radius2=options.min_radius2;scene.fold2=options.fold2;
    }
    if(options.sequence_override && !options.program_override && options.kind2==4 && options.power2>=2&&options.power2<=8&&isfinite(options.z_multiplier2)&&fabs(options.z_multiplier2)<=100) {
        scene.power2=options.power2;scene.zmul2=options.z_multiplier2;
    }
    if(options.reflections_override){if(!valid_reflections(options.reflections)){snprintf(result.error,sizeof result.error,"Invalid Reflections + Transparency settings");return result;}scene.reflections=options.reflections;scene.translucency_mode=options.translucency_mode;scene.subsurface_scattering=!!options.subsurface_scattering;scene.subsurface_amount=isfinite(options.subsurface_amount)?clamp(options.subsurface_amount,0,1):1;scene.transmission_blur=isfinite(options.transmission_blur)?clamp(options.transmission_blur,0,2):0;scene.translucency_glow=isfinite(options.translucency_glow)?clamp(options.translucency_glow,-1,1):0;
        if(!scene.translucency_mode)scene.translucency_mode=1+(scene.transmission_blur>0||scene.translucency_glow!=0);
    }
    if(options.normals_override){if(options.normal_smoothing<0||options.normal_smoothing>15||(options.normal_zbuffer&~1)){snprintf(result.error,sizeof result.error,"Invalid normal smoothing");return result;}scene.normal_smoothing=options.normal_smoothing;scene.normal_zbuffer=options.normal_zbuffer;}
    if(options.iterations)scene.iterations=options.iterations;
    if(options.de_stop)scene.de_stop=options.de_stop;
    if(options.ray_step)scene.ray_step=options.ray_step;
    if(options.program_override&&options.program.mode==1){options.program.repeat_from=0;for(int i=2;i<8;i++)options.program.slots[i].count=0;}
    if(options.program_override){const char *formulaError=program_formula_error(options.program);if(formulaError){snprintf(result.error,sizeof result.error,"%s",formulaError);return result;}if(!valid_program(options.program)||options.program.min_iterations>scene.iterations){snprintf(result.error,sizeof result.error,"Invalid formula program or minimum iterations");return result;}scene.program_enabled=1;scene.program=options.program;scene.bailout=options.program.bailout;
        FormulaSlot f=options.program.slots[0],g=options.program.slots[1];scene.kind=f.kind;scene.power=f.power;scene.count1=f.count;scene.zmul=f.z_multiplier;scene.scale=f.scale;scene.min_radius=f.min_radius;scene.fold=f.fold;scene.kind2=g.kind;scene.power2=g.power;scene.count2=g.count;scene.zmul2=g.z_multiplier;scene.scale2=g.scale;scene.min_radius2=g.min_radius;scene.fold2=g.fold;scene.repeat_from=options.program.repeat_from;
    }else if(options.formula_override||options.sequence_override)scene.program_enabled=0;
    if(!scene.program_enabled&&scene.count2>0&&scene.kind!=scene.kind2){scene.program=legacy_program();scene.program_enabled=1;}
    if(options.dof_override){if(!valid_dof(options.dof)){snprintf(result.error,sizeof result.error,"Invalid Depth of Field settings");return result;}scene.dof=options.dof;}
    if(options.shadows_override) {
        ShadowSettings v=options.shadows;
        if(v.hard_mask<0||v.hard_mask>63||v.ambient_method<0||v.ambient_method>3||v.ambient_rays<1||v.ambient_rays>64||v.ambient_steps<8||v.ambient_steps>512||
           !isfinite(v.hard_length)||v.hard_length<.001||v.hard_length>100||!isfinite(v.hard_radius)||v.hard_radius<.001||v.hard_radius>100||
           !isfinite(v.ambient_length)||v.ambient_length<.001||v.ambient_length>100||!isfinite(v.ambient_strength)||v.ambient_strength<0||v.ambient_strength>5) {
            snprintf(result.error,sizeof result.error,"Invalid shadow settings");return result;
        }
        scene.shadows=v;scene.ao_enabled=v.ambient_enabled;scene.ao_amount=v.ambient_strength;
    }
    if(options.ssao_override){SSAOSettings s=options.ssao;if(!isfinite(s.threshold)||s.threshold<.01||s.threshold>1e6||!isfinite(s.mirror)||s.mirror<0||s.mirror>.9||s.samples<1||s.samples>255){snprintf(result.error,sizeof result.error,"Invalid SSAO settings");return result;}scene.ssao=s;scene.color_option=options.color_option;scene.color_multiplier=options.color_multiplier;if(scene.color_option<0||scene.color_option>6||!isfinite(scene.color_multiplier)){snprintf(result.error,sizeof result.error,"Invalid secondary coloring settings");return result;}}
    if(options.fog_override){if(!valid_fog(options.fog)){snprintf(result.error,sizeof result.error,"Invalid depth fog settings");return result;}scene.fog=options.fog;}
    if(options.ambient_override) {
        AmbientLighting v=options.ambient;
        double values[]={v.strength,v.depth,v.second_reflection,v.diffuse_shadow,v.roughness};double maximum[]={3,.000192,6,1,1};
        for(int i=0;i<5;i++)if(!isfinite(values[i])||values[i]<0||values[i]>maximum[i]){snprintf(result.error,sizeof result.error,"Invalid ambient lighting value");return result;}
        if(v.light_mixing<0||v.light_mixing>255||v.gradient<0||v.gradient>2||(v.relative_to_object&~1)||(v.far_fog&~1)){snprintf(result.error,sizeof result.error,"Invalid ambient gradient options");return result;}
        for(int i=0;i<4;i++)for(int c=0;c<3;c++)if(!isfinite(v.colors[i][c])||v.colors[i][c]<0||v.colors[i][c]>1){snprintf(result.error,sizeof result.error,"Invalid ambient color");return result;}
        scene.roughness=v.roughness;scene.light_mixing=v.light_mixing;scene.ambient=v.strength;scene.depth=v.depth;scene.indirect=v.second_reflection;scene.diffuse_shadow=v.diffuse_shadow;
        scene.ambient_object=v.relative_to_object;scene.far_fog=v.far_fog;scene.background_function=v.gradient;
        scene.amb_top=(Vec){v.colors[0][0],v.colors[0][1],v.colors[0][2]};scene.amb_bottom=(Vec){v.colors[1][0],v.colors[1][1],v.colors[1][2]};scene.bg_top=(Vec){v.colors[2][0],v.colors[2][1],v.colors[2][2]};scene.bg_bottom=(Vec){v.colors[3][0],v.colors[3][1],v.colors[3][2]};
    }
    if(options.lights_override)for(int i=0;i<6;i++) {
        LightSettings l=options.lights[i];
        if((l.option&~127)||l.function<0||l.function>183||(l.function&8)||!isfinite(l.amplitude)||l.amplitude<0||l.amplitude>1e10) {
            snprintf(result.error,sizeof result.error,"Invalid light settings");return result;
        }
        for(int j=0;j<3;j++)if(!isfinite(l.position[j])||!isfinite(l.color[j])||l.color[j]<0||l.color[j]>1) {
            snprintf(result.error,sizeof result.error,"Invalid light color or position");return result;
        }
        scene.lights[i]=(Light){l.option,l.function,l.amplitude,{l.color[0],l.color[1],l.color[2]}, {l.position[0],l.position[1],l.position[2]}};
    }
    if(options.object_override) {
        ObjectLighting object=options.object;
        if(!isfinite(object.diffuse)||object.diffuse<0||object.diffuse>5||!isfinite(object.specular)||object.specular<0||object.specular>7||
           !isfinite(object.palette_start)||!isfinite(object.palette_end)||fabs(object.palette_start)>1e12||fabs(object.palette_end)>1e12||
           !isfinite(object.z_variation)||object.z_variation< -120||object.z_variation>360) {
            snprintf(result.error,sizeof result.error,"Invalid Object lighting values");return result;
        }
        for(int i=0;i<10;i++) {
            ObjectColorStop stop=object.stops[i];
            if(stop.position>PALETTE_POSITION_MAX||(i&&stop.position<object.stops[i-1].position)) {
                snprintf(result.error,sizeof result.error,"Palette positions must be sorted within 0–65535");return result;
            }
            for(int channel=0;channel<3;channel++)if(!isfinite(stop.diffuse[channel])||stop.diffuse[channel]<0||stop.diffuse[channel]>1||
                !isfinite(stop.specular[channel])||stop.specular[channel]<0||stop.specular[channel]>1) {
                snprintf(result.error,sizeof result.error,"Invalid palette color");return result;
            }
            scene.stops[i]=(Stop){stop.position,{stop.diffuse[0],stop.diffuse[1],stop.diffuse[2]},
                {stop.specular[0],stop.specular[1],stop.specular[2]}};
        }
        ObjectMap map=object.map;
        if(!memchr(map.file,0,sizeof map.file)||strchr(map.file,'/')||map.disabled<0||map.disabled>1||map.mode<0||map.mode>3||map.number<0||map.number>65535||!isfinite(map.offset_x)||!isfinite(map.offset_y)||!isfinite(map.rotation)||!isfinite(map.scale)||fabs(map.offset_x)>100||fabs(map.offset_y)>100||fabs(map.rotation)>36000||((map.file[0]||map.number)&&(map.scale<1e-12||map.scale>1e18))) {snprintf(result.error,sizeof result.error,"Invalid Object map settings");return result;}
        if(!map.file[0]&&!map.number&&map.scale<=0)map.scale=1;
        scene.map=map;
        scene.diffuse=object.diffuse;scene.specular=object.specular;
        scene.cstart=object.palette_start;scene.cspan=object.palette_end-object.palette_start;
        if(fabs(scene.cspan)<.001)scene.cspan=scene.cspan<0?-.001:.001;
        scene.cycle=object.cycling!=0;scene.no_interpolation=object.no_interpolation!=0;scene.color_on_trap=object.orbit_trap!=0;
        scene.z_variation=object.z_variation;scene.col_z=object.z_variation*-.005/2.1345*scene.zoom;
    }
    if(!scene_parameters_only&&load_height_maps())for(int i=0;i<2;i++){surface_caches[i].geometry.width=0;surface_caches[i].ambient_valid=surface_caches[i].hard_valid=0;}
    if(options.navigation_count<0||options.navigation_count>32||!isfinite(options.navigation_fraction)||options.navigation_fraction<0||options.navigation_fraction>.5) {snprintf(result.error,sizeof result.error,"Invalid adaptive navigation request");return result;}
    if(options.navigation_count) {
        Vec origin=scene.direct_origin?scene.view_origin:add(scene.center,camera_rotate((Vec){0,0,scene.zstart-scene.center.z}));
        for(int i=0;i<options.navigation_count;i++) {
            int operation=options.navigation_operations[i];
            double fine=operation>=100?.1:1;
            if(operation>=100)operation-=100;
            if(operation<0||operation>5){snprintf(result.error,sizeof result.error,"Invalid movement direction");return result;}
            int nav_width=(int)lround(clamp(580.0*w/h,1,640));
            int nav_height=(int)lround(fmax(1,(double)nav_width*h/w));
            if(options.navigation_fraction>0)
                origin=adaptive_move(origin,operation,options.navigation_fraction,fine,nav_width,nav_height);
        }
        scene.direct_origin=1;scene.view_origin=origin;
    }
    if(render_cancelled())return result;
    result.navigation_applied=options.navigation_count!=0;
    scene.width=w;scene.height=h;
    if(!scene_parameters_only){load_object_map();load_back_picture();}
    result.settings=scene_settings(w,h,threads,options.camera_override);
    if(scene_parameters_only)return result;
    memset(render_formula_values,0,sizeof render_formula_values);for(int slot=0;slot<8;slot++)for(int parameter=0;parameter<formula_parameter_count(scene.program.slots[slot].kind);parameter++)render_formula_values[slot][parameter]=formula_slot_value(scene.program.slots[slot],parameter);
    render_plans[0]=make_part_plan(&scene.program,0,scene.program.mode==2?scene.program.split-1:7);render_plan_count=1;
    if(scene.program.mode==2){render_plans[1]=make_part_plan(&scene.program,scene.program.split,7);render_plan_count=2;}
    Scene key=geometry_key();int reuse=options.reuse_surface&&surface_cache.pixels&&!memcmp(&key,&surface_cache.geometry,sizeof key);
    result.local_distance=reuse?surface_cache.local_distance:navigator_distance((Vec){result.settings.camera.origin[0],result.settings.camera.origin[1],result.settings.camera.origin[2]});
    if(!threads){long n=sysconf(_SC_NPROCESSORS_ONLN);threads=n>0?(int)(n>256?256:n):1;}
    size_t stride=((size_t)w*3+3)&~(size_t)3;
    unsigned char *pixels=calloc((size_t)h,stride);
    if(!pixels){snprintf(result.error,sizeof result.error,"Not enough memory to render image");return result;}
    RenderJob job={.width=w,.height=h,.stride=stride,.pixels=pixels};
    atomic_init(&job.next_row,0);atomic_init(&job.allocation_failed,0);
    for(int c=0;c<3;c++)for(int i=0;i<32768;i++)atomic_store(&color_histogram[c][i],0);
    surface_pass=0;surface_pixels=NULL;reuse_ambient=reuse_hard=0;
#ifndef USE_RUST_ENGINE
    emission_bounce=(Vec){0};
#endif
    if(reuse){
        surface_pixels=surface_cache.pixels;surface_pass=1;reuse_ambient=ambient_cache_matches();reuse_hard=hard_cache_matches();
        result.reused_surface=1;result.reused_ambient=scene.ao_enabled&&reuse_ambient;result.reused_hard_shadows=scene.shadows.hard_enabled&&reuse_hard;
    }else{
        free(surface_cache.pixels);memset(&surface_cache,0,sizeof surface_cache);
        surface_pixels=calloc((size_t)w*h,sizeof *surface_pixels);
        if(!surface_pixels&&scene.normal_zbuffer){free(pixels);snprintf(result.error,sizeof result.error,"Not enough memory for surface data");return result;}
        surface_cache.pixels=surface_pixels;surface_cache.geometry=key;surface_cache.local_distance=result.local_distance;
    }
    if(active_cancel){atomic_store(&active_cancel->rows,0);atomic_store(&active_cancel->total,h*((surface_pixels&&!reuse?2:1)+(scene.reflections.enabled&&scene.reflections.amount>0)));}
    fog_in_shading=0;
    double info_stage=info_clock();
    if(reuse&&scene.fog.mode<2&&scene.fog.strength!=53&&!(scene.reflections.enabled&&scene.reflections.amount>0)){if(fog_prepare(threads,options.preview_cache))fog_in_shading=1;else atomic_store(&job.allocation_failed,1);}
    info_total.seconds[4]+=info_clock()-info_stage;info_stage=info_clock();
    if(reuse&&scene.ao_enabled&&scene.shadows.ambient_method>=2&&!reuse_ambient&&!calculate_ssao(threads))atomic_store(&job.allocation_failed,1);
    info_total.seconds[2]+=info_clock()-info_stage;info_stage=info_clock();
    render_stage(reuse?1:0,h);render_image(&job,threads);
    info_total.seconds[reuse?1:0]+=info_clock()-info_stage;
    if(surface_pixels&&!render_cancelled()){
        if(!reuse){render_stage(5,0);info_stage=info_clock();if(scene.ao_enabled&&scene.shadows.ambient_method>=2&&!calculate_ssao(threads))atomic_store(&job.allocation_failed,1);if(scene.normal_zbuffer)compute_depth_normals(w,h);info_total.seconds[2]+=info_clock()-info_stage;surface_pass=1;atomic_store(&job.next_row,0);info_stage=info_clock();if(scene.fog.mode<2&&scene.fog.strength!=53&&!(scene.reflections.enabled&&scene.reflections.amount>0)){if(fog_prepare(threads,options.preview_cache))fog_in_shading=1;else atomic_store(&job.allocation_failed,1);}info_total.seconds[4]+=info_clock()-info_stage;info_stage=info_clock();render_stage(1,h);render_image(&job,threads);info_total.seconds[1]+=info_clock()-info_stage;}
#ifndef USE_RUST_ENGINE
        if(scene.fog.mode==2&&!render_cancelled()){
            if(!surface_cache.emission_filtered&&!filter_emission_primary(w,h)){if(!render_cancelled())atomic_store(&job.allocation_failed,1);}
            else{
                surface_cache.emission_filtered=1;
                update_emission_bounce(w,h);
                int ambient=reuse_ambient,hard=reuse_hard;reuse_ambient=reuse_hard=1;
                atomic_store(&job.next_row,0);info_stage=info_clock();render_stage(1,h);render_image(&job,threads);info_total.seconds[1]+=info_clock()-info_stage;
                reuse_ambient=ambient;reuse_hard=hard;
            }
        }
#endif
        if(scene.ao_enabled){surface_cache.ambient_valid=1;surface_cache.ambient_scene=scene;}
        if(scene.shadows.hard_enabled){surface_cache.hard_valid=1;surface_cache.hard_scene=scene;}
        surface_pixels=NULL;surface_pass=0;
    }
#ifdef USE_C_FORMULA_VM
    if(atomic_load(&cf_error)){snprintf(result.error,sizeof result.error,"%s",cf_error_message);free(pixels);free(surface_cache.pixels);memset(&surface_cache,0,sizeof surface_cache);surface_pixels=NULL;surface_pass=0;return result;}
#endif
    if(atomic_load(&job.allocation_failed)||render_cancelled()){
        if(atomic_load(&job.allocation_failed))snprintf(result.error,sizeof result.error,"Not enough memory for scene row buffers");
        free(pixels);free(surface_cache.pixels);memset(&surface_cache,0,sizeof surface_cache);
        surface_pixels=NULL;surface_pass=0;return result;
    }
    for(int c=0;c<3;c++)for(int i=0;i<32768;i++){
        double fraction=c==2?pow(i/.000158025,.25)/127:(90*sqrt((i+10900)/32767.))/120.;int bin=(int)clamp(lround(fraction*255),0,255);result.color_histogram[c][bin]+=atomic_load(&color_histogram[c][i]);
    }
    for(int c=0;c<2;c++) {
        unsigned total=0;for(int i=0;i<32768;i++)total+=atomic_load(&color_histogram[c][i]);
        if(!total)continue;
        result.color_fit_valid=1;unsigned threshold=total/2000;if(!threshold)threshold=1;
        unsigned n=0;for(int i=0;i<32768;i++){n+=atomic_load(&color_histogram[c][i]);if(n>=threshold){result.color_fit[c][0]=i;break;}}
        n=0;for(int i=32767;i>=0;i--){n+=atomic_load(&color_histogram[c][i]);if(n>=threshold){result.color_fit[c][1]=i;break;}}
    }
    result.stride=(size_t)w*4;
    result.rgba=malloc(result.stride*h);
    if(!result.rgba){free(pixels);snprintf(result.error,sizeof result.error,"Not enough memory to display image");return result;}
    for(int y=0;y<h;y++) {
        const unsigned char *src=pixels+(size_t)(h-1-y)*stride;
        unsigned char *dst=result.rgba+(size_t)y*result.stride;
        for(int x=0;x<w;x++) {
            dst[4*x]=src[3*x+2];dst[4*x+1]=src[3*x+1];dst[4*x+2]=src[3*x];dst[4*x+3]=255;
        }
    }
    free(pixels);result.width=w;result.height=h;
    info_stage=info_clock();
    if(scene.fog.mode<2&&scene.fog.strength!=53&&!fog_prepare(threads,options.preview_cache)){free(result.rgba);result.rgba=NULL;snprintf(result.error,sizeof result.error,"Could not calculate depth fog (cancelled or insufficient memory)");return result;}
    info_total.seconds[4]+=info_clock()-info_stage;info_stage=info_clock();
    render_stage(3,0);
    if(!apply_reflections(&result,threads)){free(result.rgba);result.rgba=NULL;snprintf(result.error,sizeof result.error,"No cached surface data for Reflections + Transparency");return result;}
    info_total.seconds[5]+=info_clock()-info_stage;info_stage=info_clock();
    render_stage(1,0);
    if(!apply_fog(&result,threads,options.preview_cache)){free(result.rgba);result.rgba=NULL;snprintf(result.error,sizeof result.error,"Could not calculate depth fog (cancelled or insufficient memory)");return result;}
    info_total.seconds[4]+=info_clock()-info_stage;info_stage=info_clock();
#ifndef USE_RUST_ENGINE
    if(!apply_emission_glow(&result)){free(result.rgba);result.rgba=NULL;snprintf(result.error,sizeof result.error,"Could not calculate emission glow (cancelled or insufficient memory)");return result;}
#endif
    render_stage(4,0);
    if(!apply_depth_of_field(&result,threads)){free(result.rgba);result.rgba=NULL;snprintf(result.error,sizeof result.error,"Not enough memory for Depth of Field");}
    info_total.seconds[6]+=info_clock()-info_stage;info_total.threads=threads;
    return result;
}

static RenderResult render_scene_with_options_c(const char *input,RenderOptions options) {
    active_cancel=options.cancel_token;
    active_surface_cache=&surface_caches[options.preview_cache?1:0];
    double info_start=info_clock();memset(&info_total,0,sizeof info_total);memset(&info_local,0,sizeof info_local);info_phase=7;
    render_plan_count=0;RenderResult result=render_scene_core(input,options);render_plan_count=0;
    info_flush(NULL);info_total.elapsed=info_clock()-info_start;info_total.valid=result.rgba!=NULL;info_total.timing_mask=0xf7;double info_accounted=0;for(int k=0;k<7;k++)info_accounted+=info_total.seconds[k];info_total.seconds[7]=fmax(0,info_total.elapsed-info_accounted);result.statistics=info_total;
    if(render_cancelled()){free(result.rgba);result.rgba=NULL;result.cancelled=1;result.error[0]=0;}
    active_cancel=NULL;active_surface_cache=&surface_caches[0];return result;
}

int write_scene_parameters(const char *input,RenderOptions options,const char *output,char error[512]){
    error[0]=0;options.cancel_token=NULL;options.navigation_count=0;
    scene_parameters_only=1;RenderResult result=render_scene_with_options_c(input,options);scene_parameters_only=0;
    if(result.error[0]){snprintf(error,512,"%s",result.error);return 0;}
    m3i_fd=open(output,O_CREAT|O_EXCL|O_WRONLY,0600);if(m3i_fd<0){snprintf(error,512,"Could not create scene snapshot: %s",strerror(errno));return 0;}
    atomic_store(&m3i_io_error,0);saveM3IHeaders(result.settings.width,result.settings.height);
    int failed=atomic_load(&m3i_io_error);if(close(m3i_fd))failed=1;m3i_fd=-1;
    if(failed){unlink(output);snprintf(error,512,"Could not write scene snapshot");return 0;}return 1;
}

/* Save the displayed color buffer in the original fullSizeImage BGRA layout,
 * retaining the native settings after it. Row streaming keeps memory bounded. */
int write_scene_parameters_with_preview(const char *input,RenderOptions options,const char *output,const unsigned char *rgba,int sourceWidth,int sourceHeight,size_t stride,char error[512]){
    if(!write_scene_parameters(input,options,output,error))return 0;
    if(!rgba||sourceWidth<1||sourceHeight<1||stride<(size_t)sourceWidth*4)return 1;
    int fd=open(output,O_RDWR);unsigned char header[12],extra[4096];int ok=fd>=0;
    if(ok)ok=pread(fd,header,sizeof header,0)==sizeof header;
    int w=ok?(int)u32(header+4):0,h=ok?(int)u32(header+8):0;
    off_t offset=840+(off_t)w*h*18+1136;
    if(ok)ok=pread(fd,extra,sizeof extra,offset)==sizeof extra;
    unsigned char *row=ok?malloc((size_t)w*4):NULL;if(!row)ok=0;
    double scale=fmin((double)w/sourceWidth,(double)h/sourceHeight),left=(w-sourceWidth*scale)/2,top=(h-sourceHeight*scale)/2;
    for(int y=0;ok&&y<h;y++){
        for(int x=0;x<w;x++){
            if(w==sourceWidth&&h==sourceHeight){const unsigned char *src=rgba+(size_t)y*stride+x*4;unsigned char *dst=row+x*4;dst[0]=src[2];dst[1]=src[1];dst[2]=src[0];dst[3]=255;continue;}
            double sx=(x+.5-left)/scale-.5,sy=(y+.5-top)/scale-.5;unsigned char *dst=row+x*4;
            if(x+.5<left||x+.5>=w-left||y+.5<top||y+.5>=h-top){dst[0]=dst[1]=dst[2]=0;dst[3]=255;continue;}
            sx=clamp(sx,0,sourceWidth-1);sy=clamp(sy,0,sourceHeight-1);int x0=(int)sx,y0=(int)sy,x1=x0+1<sourceWidth?x0+1:x0,y1=y0+1<sourceHeight?y0+1:y0;double fx=sx-x0,fy=sy-y0;
            for(int c=0;c<3;c++)dst[2-c]=(unsigned char)lround((1-fy)*((1-fx)*rgba[y0*stride+x0*4+c]+fx*rgba[y0*stride+x1*4+c])+fy*((1-fx)*rgba[y1*stride+x0*4+c]+fx*rgba[y1*stride+x1*4+c]));dst[3]=255;
        }
        ok=pwrite(fd,row,(size_t)w*4,offset+(off_t)y*w*4)==(ssize_t)w*4;
    }
    free(row);if(ok)ok=pwrite(fd,extra,sizeof extra,offset+(off_t)w*h*4)==sizeof extra&&ftruncate(fd,offset+(off_t)w*h*4+sizeof extra)==0;
    if(fd>=0&&close(fd))ok=0;
    if(!ok){unlink(output);snprintf(error,512,"Could not save .m3i preview image");}return ok;
}

#ifdef USE_RUST_ENGINE
#include "rust_engine.inc"
#endif
RenderResult render_scene_with_options(const char *input,RenderOptions options){
#ifdef USE_RUST_ENGINE
    RenderResult result=render_with_rust(input,options);
#else
    RenderResult result=render_scene_with_options_c(input,options);
#endif
    return result;
}

RenderResult render_navigator_with_options(const char *input,RenderOptions options,double de_multiplier){
    navigator_de_multiplier=isfinite(de_multiplier)&&de_multiplier>0?de_multiplier:1;
    RenderResult result=render_scene_with_options(input,options);
    result.navigator_de_multiplier=navigator_de_multiplier;
#ifdef USE_RUST_ENGINE
    if(result.rgba&&options.navigation_count&&options.preview_cache)
        result.navigator_de_multiplier*=mb3dx_rust_navigator_correction();
#endif
    navigator_de_multiplier=1;
    return result;
}

RenderResult render_scene_to_m3i(const char *input,RenderOptions options,const char *output) {
#ifdef USE_RUST_ENGINE
    RenderResult rustResult=render_scene_with_options(input,options);if(!rustResult.rgba)return rustResult;
    char snapshot[4096];int saveFd=render_create_temporary(snapshot,"mandelbulb3dr-save-XXXXXX",0);if(saveFd>=0){close(saveFd);unlink(snapshot);}
    if(saveFd<0||!write_scene_parameters_with_preview(input,rustResult.settings,snapshot,rustResult.rgba,rustResult.width,rustResult.height,rustResult.stride,rustResult.error)||!output||rename(snapshot,output)){
        unlink(snapshot);free(rustResult.rgba);rustResult.rgba=NULL;if(!rustResult.error[0])snprintf(rustResult.error,sizeof rustResult.error,"Could not save Rust scene image");
    }return rustResult;
#endif
    RenderResult result={0};if(!output||!*output){snprintf(result.error,sizeof result.error,"Missing save path");return result;}
    size_t len=strlen(output)+16;char *temporary=malloc(len);
    if(!temporary){snprintf(result.error,sizeof result.error,"Not enough memory to save");return result;}
    snprintf(temporary,len,"%s.XXXXXX",output);m3i_fd=mkstemp(temporary);atomic_store(&m3i_io_error,0);
    if(m3i_fd<0){snprintf(result.error,sizeof result.error,"Cannot save: %s",strerror(errno));free(temporary);return result;}
    result=render_scene_with_options(input,options);
    if(result.rgba)saveM3IHeaders(result.width,result.height);
    int error=atomic_load(&m3i_io_error);if(fsync(m3i_fd))error=1;if(close(m3i_fd))error=1;m3i_fd=-1;
    if(result.rgba&&!error&&rename(temporary,output))error=1;
    if(error){free(result.rgba);result.rgba=NULL;snprintf(result.error,sizeof result.error,"Could not write .m3i file; check destination and available disk space");}
    unlink(temporary);free(temporary);return result;
}

/* Optional snapshot is taken after lighting/reflections/fog, before DoF.
 * No persistent renderer copy, no work for other renderer callers. */
RenderResult render_scene_capturing_sharp(const char *input,RenderOptions options,const char *output,unsigned char **sharp){
    *sharp=NULL;sharp_capture=sharp;
    RenderResult result=output?render_scene_to_m3i(input,options,output):render_scene_with_options(input,options);
    sharp_capture=NULL;
    if(!result.rgba){free(*sharp);*sharp=NULL;}return result;
}

/* MB3D uses little-endian six-bit groups and the alphabet ./0..9A..Za..z. */
int export_clipboard_scene(const char *input,RenderOptions options,char **text,char error[512]) {
    *text=NULL;char path[4096];int fd=render_create_temporary(path,"mb3d-clipboard-XXXXXX",0);
    if(fd<0){snprintf(error,512,"Could not create clipboard snapshot: %s",strerror(errno));return 0;}
    close(fd);unlink(path);if(!write_scene_parameters(input,options,path,error))return 0;
    unsigned char data[1977]={0},native[4096];fd=open(path,O_RDONLY);unlink(path);
    int ok=fd>=0&&pread(fd,data,840,0)==840;uint64_t offset=840+(uint64_t)u32(data+4)*u32(data+8)*18;
    ok=ok&&pread(fd,data+840,1136,(off_t)offset)==1136&&pread(fd,native,4096,(off_t)(offset+1136))==4096;
    if(fd>=0)close(fd);if(!ok){snprintf(error,512,"Could not read clipboard snapshot.");return 0;}
    char *out=malloc(12000);if(!out){snprintf(error,512,"Not enough memory for clipboard parameters.");return 0;}
    size_t n=0;n+=sprintf(out+n,"Mandelbulb3Dv18{\n");int column=0;
    for(size_t i=0;i<sizeof data;i+=3){unsigned value=data[i]|data[i+1]<<8|data[i+2]<<16;for(int j=0;j<4;j++){unsigned c=value&63;value>>=6;out[n++]=(char)(c<12?c+46:c<38?c+53:c+59);if(++column==80){out[n++]='\n';column=0;}}}
    n+=sprintf(out+n,"\n}\nMandelbulb3DxNative1{\n");
    for(size_t i=0;i<sizeof native;i++)n+=sprintf(out+n,"%02x",native[i]);
    strcpy(out+n,"\n}\n");*text=out;return 1;
}

int import_clipboard_scene(const char *text,const char *output,char error[512]) {
    error[0]=0;if(!text||!output){snprintf(error,512,"Clipboard contains no parameter text.");return 0;}
    const char *start=strstr(text,"Mandelbulb3Dv");if(!start){snprintf(error,512,"Clipboard does not contain Mandelbulb3D parameter text.");return 0;}
    char *end;double version=strtod(start+13,&end);
    if(end==start+13||!isfinite(version)||version<16||version>99||*end!='{'){snprintf(error,512,"Unsupported clipboard format. Use Mandelbulb3Dv16 or newer parameter text.");return 0;}
    unsigned char decoded[1980];size_t used=0;unsigned value=0;int bits=0,closed=0;
    const unsigned char *cursor=(const unsigned char *)end+1;
    for(size_t scanned=0;*cursor&&scanned<1048576;cursor++,scanned++) {
        if(*cursor=='}'){closed=1;break;}if(isspace(*cursor))continue;
        unsigned char characters[3]={*cursor,0,0};int count=1;
        if(cursor[0]==0xe2&&cursor[1]==0x80&&cursor[2]==0xa6){characters[0]=characters[1]=characters[2]='.';count=3;cursor+=2;}
        for(int i=0;i<count;i++) {
            unsigned c=characters[i],n;
            if(c>='.'&&c<='9')n=c-46;else if(c>='A'&&c<='Z')n=c-53;else if(c>='a'&&c<='z')n=c-59;else{snprintf(error,512,"Invalid character in clipboard parameter data.");return 0;}
            value|=n<<bits;bits+=6;
            if(bits==24){if(used+3>sizeof decoded){snprintf(error,512,"Clipboard parameter block is too large.");return 0;}for(int b=0;b<3;b++)decoded[used++]=(unsigned char)(value>>(8*b));bits=0;value=0;}
        }
    }
    if(!closed||bits||used<848){snprintf(error,512,"Clipboard parameter block is incomplete or truncated.");return 0;}
    unsigned char header[840],addon[1136]={0};memcpy(header,decoded,840);size_t available=used-840;
    if(available>sizeof addon+2){snprintf(error,512,"Clipboard has too many formula records.");return 0;}
    memcpy(addon,decoded+840,available<sizeof addon?available:sizeof addon);
    int records=addon[4];if(records<1||records>6||available<(size_t)(8+records*188)){snprintf(error,512,"Clipboard formula records are incomplete or invalid.");return 0;}
    if(unsupported_formula_list(addon,records,error))return 0;
    uint32_t width=u32(header+4),height=u32(header+8);if(width<16||height<16||width>RENDER_MAX_DIMENSION||height>RENDER_MAX_DIMENSION){snprintf(error,512,"Clipboard image dimensions must be 16–16384 pixels.");return 0;}
    unsigned char native[4096];int hasNative=0;const char *extension=strstr((const char *)cursor,"Mandelbulb3DxNative1{");
    if(extension){const char *p=extension+21;while(isspace((unsigned char)*p))p++;
        for(size_t i=0;i<sizeof native;i++){unsigned value=0;for(int j=0;j<2;j++){unsigned char c=*p++;int digit=c>='0'&&c<='9'?c-'0':c>='a'&&c<='f'?c-'a'+10:-1;if(digit<0){snprintf(error,512,"Invalid native clipboard settings.");return 0;}value=value*16+(unsigned)digit;}native[i]=(unsigned char)value;}
        while(isspace((unsigned char)*p))p++;if(*p!='}'||memcmp(native,"IPMACM3I",8)||u32(native+8)!=2||u32(native+12)!=4096){snprintf(error,512,"Invalid native clipboard settings.");return 0;}hasNative=1;
    }
    uint64_t offset=840+(uint64_t)width*height*18;
    int fd=open(output,O_WRONLY|O_CREAT|O_EXCL,0600);if(fd<0){snprintf(error,512,"Could not create temporary clipboard scene: %s",strerror(errno));return 0;}
    int ok=pwrite(fd,header,sizeof header,0)==sizeof header&&pwrite(fd,addon,sizeof addon,(off_t)offset)==sizeof addon&&(!hasNative||pwrite(fd,native,sizeof native,(off_t)(offset+sizeof addon))==sizeof native)&&ftruncate(fd,(off_t)(offset+sizeof addon+(hasNative?sizeof native:0)))==0;
    int saved=errno;if(close(fd)&&ok){ok=0;saved=errno;}
    if(!ok){unlink(output);snprintf(error,512,"Could not write clipboard scene: %s",strerror(saved));return 0;}
    scene_defaults();if(!load_m3i(output)){snprintf(error,512,"%s",scene_error[0]?scene_error:"Clipboard contains invalid scene parameters.");unlink(output);return 0;}
    return 1;
}
