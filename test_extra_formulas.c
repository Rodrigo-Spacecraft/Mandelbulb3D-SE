#include "renderer.c"
#include <assert.h>
typedef struct {Vec p;double values[13],distance,trap;} RandVector;
#include "test_rand_vectors.h"
typedef struct {int kind;Vec input;double values[13];Vec output;} ExtraVector;
#include "test_extra_vectors.h"
#include "test_dihed_vectors.h"
typedef struct {Vec input;double parameters[13],distance;} SierpDEVector;
#include "test_sierp_de_vectors.h"
typedef struct {int kind;double input[4],constant[3],parameters[5],output[4];} NewFormulaVector;
#include "test_new_formula_vectors.h"
#include "test_torus_vectors.h"
typedef struct {Vec input,constant;double parameters[8],scaleBefore,scaleAfter,factor;Vec output;} SurfVector;
#include "test_surf_vectors.h"
typedef struct {int kind;Vec input;double parameters[16];int iteration;double distance,scale,trap;Vec next;} DifsVector;
#include "test_difs_vectors.h"
typedef struct {int kind;Vec input;double parameters[16],distance,scale,trap;Vec next;double u,v;} BoxHeightVector;
#include "test_box_height_vectors.h"
static double test_ao_sphere(Vec p){p.z-=3;return sqrt(dot(p,p))-1;}
static double test_ao_plane(Vec p){return p.y;}
typedef struct {int kind;double input[4],constant[3],parameters[7],output[4];} FourDVector;
#include "test_fourd_vectors.h"
typedef struct {int kind;double input[4],parameters[9],output[4];} SmoothVector;
#include "test_smooth_vectors.h"
typedef struct {double input[3],v[9],next[3],scale;} ApolloVector;
#include "test_apollo_vectors.h"
typedef struct {double input[3],v[12],distance,next[3],scale;} DiniVector;
#include "test_dini_vectors.h"
typedef struct {double input[3],v[13],distance,next[3],scale,trap;} SphereVector;
#include "test_sphere_vectors.h"
typedef struct {int kind;double input[3],v[12],distance,next[3],scale,trap;} ShapeVector;
#include "test_shapes_vectors.h"
typedef struct {double input[3],v[9],distance,next[3],scale;} CageVector;
#include "test_cage_vectors.h"
typedef struct {double input[3],v[10],next[3],scale;} TransformIFSVector;
#include "test_transformifs_vectors.h"
typedef struct {int kind;double input[4],v[15],output[4],derivative;} MixVector;
#include "test_mix_vectors.h"
#include "test_add72_vectors.h"
int main(void){
    scene_defaults();assert(formula_kind_from_name("_LinCombXYZ")==131&&formula_kind_from_name("_LinCombineXYZ")==131);
    for(unsigned i=0;i<sizeof(add72_vectors)/sizeof(*add72_vectors);i++){
        const MixVector *t=add72_vectors+i;FormulaSlot f=formula_slot_default(t->kind);for(int j=0;j<formula_parameter_count(t->kind);j++)formula_slot_set_value(&f,j,t->v[j]);
        double w=t->input[3],derivative=1.25,power=2;Vec constant={.1,.2,.3};Vec next=slot_step_context((Vec){t->input[0],t->input[1],t->input[2]},&constant,&w,f,&derivative,&power);double values[]={next.x,next.y,next.z,w};
        for(int j=0;j<4;j++)if(fabs(values[j]-t->output[j])>1e-10*(1+fabs(t->output[j]))){fprintf(stderr,"Mix vector %u kind %d channel %d actual %.17g expected %.17g\n",i,t->kind,j,values[j],t->output[j]);assert(0);}
        assert(fabs(derivative-t->derivative)<1e-12);
    }
    puts("_PolyFold-sym and MixPinski4 match 480 original x87 evaluations.");
    for(unsigned i=0;i<sizeof(mix_vectors)/sizeof(*mix_vectors);i++){
        const MixVector *t=mix_vectors+i;FormulaSlot f=formula_slot_default(t->kind);for(int j=0;j<formula_parameter_count(t->kind);j++)formula_slot_set_value(&f,j,t->v[j]);
        double w=t->input[3],derivative=1.25,power=2;Vec constant={.1,.2,.3};Vec next=slot_step_context((Vec){t->input[0],t->input[1],t->input[2]},&constant,&w,f,&derivative,&power);double values[]={next.x,next.y,next.z,w};
        for(int j=0;j<4;j++)if(fabs(values[j]-t->output[j])>1e-10*(1+fabs(t->output[j]))){fprintf(stderr,"Mix vector %u kind %d channel %d actual %.17g expected %.17g\n",i,t->kind,j,values[j],t->output[j]);assert(0);}
        assert(fabs(derivative-t->derivative)<1e-12);
    }
    puts("MixPinski4ex and _LinCombineXYZ match 480 original x87 evaluations, including 4D rotations, offsets, signed scales, W state and derivative.");

    for(unsigned i=0;i<sizeof(transformifs_vectors)/sizeof(*transformifs_vectors);i++){const TransformIFSVector *t=transformifs_vectors+i;double scale=1;Vec next=transform_ifs((Vec){t->input[0],t->input[1],t->input[2]},t->v,&scale);assert(fabs(next.x-t->next[0])<1e-11&&fabs(next.y-t->next[1])<1e-11&&fabs(next.z-t->next[2])<1e-11&&scale==t->scale);}
    puts("transformIFS matches 240 original x87 evaluations, including signed scales, rotation and nonzero absolute-axis flags.");

    scene_defaults();for(unsigned i=0;i<sizeof(cage_vectors)/sizeof(*cage_vectors);i++){const CageVector *t=cage_vectors+i;FormulaSlot f=formula_slot_default(128);for(int j=0;j<9;j++)formula_slot_set_value(&f,j,t->v[j]);Vec next;double scale=1,trap=.75;double d=difs_formula((Vec){t->input[0],t->input[1],t->input[2]},f,&next,&scale,&trap,0);assert(isfinite(d)&&fabs(d-t->distance)<1e-10*(1+fabs(t->distance))&&scale==t->scale&&next.x==t->next[0]&&next.y==t->next[1]&&next.z==t->next[2]&&trap==.75);}
    puts("SphCageIFS matches 240 original SSE2/x87 evaluations across odd/even parallels, meridians and signed scales.");

    scene_defaults();FormulaProgram schedule=legacy_program();for(int j=0;j<8;j++)schedule.slots[j].count=0;schedule.slots[0]=formula_slot_default(126);schedule.slots[0].count=1;schedule.slots[1]=formula_slot_default(127);schedule.slots[1].count=2;
    for(int point=0;point<120;point++){Vec input={sin(point*.37)*2,cos(point*.21)*3,sin(point*.17)},z=input;double scale=1,expected=1e100,trap=0;int bestIt=0;for(int iteration=0;iteration<4;iteration++){Vec next;double d=difs_formula(z,schedule.slots[0],&next,&scale,&trap,iteration)/fabs(scale);z=next;if(d<expected){expected=d;bestIt=iteration+1;}if(iteration<3)for(int j=0;j<2;j++)z=amazing_ifs(z,schedule.slots[1].parameters,&scale);}OrbitResult actual=difs_part(input,schedule,0,1,0,4);assert(fabs(actual.sample.distance-expected)<1e-11&&actual.iterations==bestIt);}
    puts("IFS iteration limits count distance shapes, not intervening transforms: 120 independent four-shape/two-transform schedules pass.");

    scene_defaults();scene.de_stop=.0123;scene.zoom=2.1345/scene.width;
    for(unsigned i=0;i<sizeof(shape_vectors)/sizeof(*shape_vectors);i++){const ShapeVector *t=shape_vectors+i;FormulaSlot f=formula_slot_default(t->kind);for(int j=0;j<formula_parameter_count(t->kind);j++)formula_slot_set_value(&f,j,t->v[j]);Vec next;double scale=1,trap=0,d=0;if(t->kind==126)d=difs_formula((Vec){t->input[0],t->input[1],t->input[2]},f,&next,&scale,&trap,0);else next=amazing_ifs((Vec){t->input[0],t->input[1],t->input[2]},t->v,&scale);if(fabs(d-t->distance)>1e-10||fabs(trap-t->trap)>1e-10||fabs(scale-t->scale)>1e-10||fabs(next.x-t->next[0])>1e-10||fabs(next.y-t->next[1])>1e-10||fabs(next.z-t->next[2])>1e-10){fprintf(stderr,"Shape %u kind%d d%g exp%g XYZ %g %g %g exp%g %g %g scale%g exp%g\n",i,t->kind,d,t->distance,next.x,next.y,next.z,t->next[0],t->next[1],t->next[2],scale,t->scale);abort();}}
    puts("RoundedBox and amazingIFS match 480 original SSE2/x87 evaluations.");

    scene_defaults();scene.de_stop=.0123;scene.zoom=2.1345/scene.width;
    for(unsigned i=0;i<sizeof(sphere_vectors)/sizeof(*sphere_vectors);i++){const SphereVector *t=sphere_vectors+i;FormulaSlot f=formula_slot_default(125);for(int j=0;j<13;j++)formula_slot_set_value(&f,j,t->v[j]);Vec next;double scale=1,trap;double d=difs_formula((Vec){t->input[0],t->input[1],t->input[2]},f,&next,&scale,&trap,0);assert(isfinite(d)&&fabs(d-t->distance)<1e-11*(1+fabs(t->distance))&&fabs(trap-t->trap)<1e-11&&scale==t->scale&&next.x==t->next[0]&&next.y==t->next[1]&&next.z==t->next[2]);}
    puts("SphereIFS matches 240 original SSE2/x87 evaluations, including hollow shells, sizing and all trap options.");

    scene_defaults();FormulaSlot sphere=formula_slot_default(125);sphere.parameters[1]=1;sphere.parameters[4]=0;sphere.parameters[12]=.8;Vec sphereNext;double sphereScale=1,sphereTrap;
    assert(fabs(difs_formula((Vec){0,0,.9},sphere,&sphereNext,&sphereScale,&sphereTrap,0)+.1)<1e-12);
    assert(fabs(difs_formula((Vec){0,0,.3},sphere,&sphereNext,&sphereScale,&sphereTrap,0)-.5)<1e-12);
    assert(formula_kind_from_name("sphereifs")==125&&formula_difs(125));

    for(unsigned i=0;i<sizeof(apollo_vectors)/sizeof(*apollo_vectors);i++){const ApolloVector *t=apollo_vectors+i;double scale=1;Vec next=apollo_2d((Vec){t->input[0],t->input[1],t->input[2]},t->v,&scale);if(!isfinite(next.x)||fabs(next.x-t->next[0])>1e-9*(1+fabs(t->next[0]))||fabs(next.y-t->next[1])>1e-9*(1+fabs(t->next[1]))||fabs(next.z-t->next[2])>1e-9*(1+fabs(t->next[2]))){fprintf(stderr,"Apollo %u got %g %g %g expected %g %g %g\n",i,next.x,next.y,next.z,t->next[0],t->next[1],t->next[2]);abort();}assert(scale==t->scale);}
    puts("Apollo2D-IFS matches 240 original x87 reference evaluations.");

    assert(formula_kind_from_name("DiniIFS")==123&&formula_difs(123)&&formula_parameter_count(123)==12);
    for(unsigned i=0;i<sizeof(dini_vectors)/sizeof(*dini_vectors);i++){const DiniVector *t=dini_vectors+i;FormulaSlot f=formula_slot_default(123);for(int j=0;j<12;j++)formula_slot_set_value(&f,j,t->v[j]);Vec next;double scale=1,trap=.75;double d=difs_formula((Vec){t->input[0],t->input[1],t->input[2]},f,&next,&scale,&trap,0);if(!isfinite(d)||fabs(d-t->distance)>1e-10*fmax(1,fabs(t->distance))){fprintf(stderr,"Dini %u got %.17g expected %.17g\n",i,d,t->distance);abort();}assert(scale==t->scale&&next.x==t->next[0]&&next.y==t->next[1]&&next.z==t->next[2]&&trap==.75);}
    puts("DiniIFS matches 240 original SSE2/x87 reference evaluations.");

    scene_defaults();
    for(size_t i=0;i<sizeof smooth_vectors/sizeof *smooth_vectors;i++){SmoothVector vector=smooth_vectors[i];FormulaSlot slot=formula_slot_default(vector.kind);for(int j=0;j<formula_parameter_count(slot.kind);j++)slot.parameters[j]=vector.parameters[j];Vec z={vector.input[0],vector.input[1],vector.input[2]},constant={0};double w=vector.input[3],dr=1,power=2;Vec out=slot_step_context(z,&constant,&w,slot,&dr,&power);double actual[]={out.x,out.y,out.z,w};for(int j=0;j<4;j++){if(fabs(actual[j]-vector.output[j])>1e-10*fmax(1,fabs(vector.output[j])))fprintf(stderr,"Smoothing mismatch %d case %zu coordinate %d: %.17g expected %.17g\n",slot.kind,i,j,actual[j],vector.output[j]);assert(fabs(actual[j]-vector.output[j])<=1e-10*fmax(1,fabs(vector.output[j])));}}
    puts("MengerSmt and _reciprocalY3b match 440 original x87 reference steps, including signed smoothing and W scaling.");

    for(size_t i=0;i<sizeof fourd_vectors/sizeof *fourd_vectors;i++){FourDVector vector=fourd_vectors[i];FormulaSlot slot=formula_slot_default(vector.kind);for(int j=0;j<formula_parameter_count(slot.kind);j++)slot.parameters[j]=vector.parameters[j];Vec z={vector.input[0],vector.input[1],vector.input[2]},constant={vector.constant[0],vector.constant[1],vector.constant[2]};double w=vector.input[3],derivative=1,power=2;Vec out=slot_step_context(z,&constant,&w,slot,&derivative,&power);double actual[]={out.x,out.y,out.z,w};for(int j=0;j<4;j++){if(fabs(actual[j]-vector.output[j])>1e-10*fmax(1,fabs(vector.output[j])))fprintf(stderr,"4D mismatch %d case %zu coordinate %d: %.17g expected %.17g\n",slot.kind,i,j,actual[j],vector.output[j]);assert(fabs(actual[j]-vector.output[j])<=1e-10*fmax(1,fabs(vector.output[j])));}}
    for(int kind=118;kind<=120;kind++){FormulaProgram four=legacy_program();four.slots[0]=formula_slot_default(kind);four.slots[0].count=1;four.bailout=1.5;four.slots[0].parameters[kind==118?0:kind==119?4:3]=2;Vec c=kind==120?(Vec){1,0,0}:(Vec){0};OrbitResult result=program_orbit(c,four,0,7,0,4,0);assert(result.iterations==1&&result.radius>=2);}
    puts("Makin4D p4b, CubicQuat and Lambda4Dc match 480 original x87 reference steps, including W.");

    assert(formula_supported(117)&&formula_modifier(117)&&formula_kind_from_name("_rotate")==117&&formula_parameter_count(117)==3);
    FormulaSlot rotate=formula_slot_default(117);Vec original={1,2,3};double rotateDr=7,rotatePower=8,rotateW=9;Vec rotateC={4,5,6};
    Vec identity=slot_step_context(original,&rotateC,&rotateW,rotate,&rotateDr,&rotatePower);assert(identity.x==1&&identity.y==2&&identity.z==3&&rotateDr==7&&rotatePower==8&&rotateW==9&&rotateC.x==4);
    const Vec quarter[]={{1,-3,2},{3,2,-1},{-2,1,3}};
    for(int axis=0;axis<3;axis++){rotate=formula_slot_default(117);rotate.parameters[axis]=90;Vec actual=slot_step(original,rotateC,rotate,&rotateDr,&rotatePower);assert(fabs(actual.x-quarter[axis].x)<1e-6&&fabs(actual.y-quarter[axis].y)<1e-6&&fabs(actual.z-quarter[axis].z)<1e-6);}
    puts("_Rotate identity, XYZ quarter turns, defaults and unchanged constant/W/DE derivative pass.");

    assert(formula_kind_from_name("boxIFS")==115&&formula_kind_from_name("BOXIFS")==115&&formula_kind_from_name("heightmapifs")==116&&formula_kind_from_name("amazingsurf")==109);
    scene.de_stop=.001*scene.zoom*fmax(16,scene.width)/2.1345;
    for(size_t i=0;i<sizeof box_height_vectors/sizeof *box_height_vectors;i++){
        BoxHeightVector v=box_height_vectors[i];FormulaSlot f=formula_slot_default(v.kind);for(int j=0;j<formula_parameter_count(f.kind);j++)formula_slot_set_value(&f,j,v.parameters[j]);double scale=1.3,trap=.123;Vec next=v.input;
        double d=v.kind==115?difs_formula(v.input,f,&next,&scale,&trap,0):height_map_formula(v.input,v.parameters,(Vec){.2,.4,.8},.001,&trap);
        double a[]={d,scale,trap,next.x,next.y,next.z},b[]={v.distance,v.scale,v.trap,v.next.x,v.next.y,v.next.z};for(int j=0;j<6;j++)if(!(fabs(a[j]-b[j])<1e-9*(1+fabs(b[j])))){fprintf(stderr,"Box/height vector %zu kind %d component %d: %.17g != %.17g\n",i,v.kind,j,a[j],b[j]);assert(0);}
        if(!isnan(v.u)){Vec p=formula_rotate(v.input,v.parameters+7,1);assert(fabs(v.u-(p.x*(float)v.parameters[4]-(float)v.parameters[1]))<1e-10);assert(fabs(v.v-(p.y*(float)v.parameters[5]-(float)v.parameters[2]))<1e-10);}
    }
    char heightPath[]="/tmp/mandelbulb-height16-XXXXXX";int heightFD=mkstemp(heightPath);assert(heightFD>=0);close(heightFD);
    uint16_t heightPixel[]={32768,12345,60000,65535};CGColorSpaceRef heightSpace=CGColorSpaceCreateWithName(kCGColorSpaceSRGB);CGDataProviderRef heightProvider=CGDataProviderCreateWithData(NULL,heightPixel,sizeof heightPixel,NULL);CGImageRef heightImage=CGImageCreate(1,1,16,64,8,heightSpace,kCGImageAlphaPremultipliedLast|kCGBitmapByteOrder16Little,heightProvider,NULL,false,kCGRenderingIntentDefault);assert(heightImage);
    CFURLRef heightURL=CFURLCreateFromFileSystemRepresentation(NULL,(const UInt8*)heightPath,strlen(heightPath),false);CGImageDestinationRef heightDest=CGImageDestinationCreateWithURL(heightURL,CFSTR("public.png"),1,NULL);assert(heightDest);CGImageDestinationAddImage(heightDest,heightImage,NULL);assert(CGImageDestinationFinalize(heightDest));CFRelease(heightDest);CFRelease(heightURL);CGImageRelease(heightImage);CGDataProviderRelease(heightProvider);CGColorSpaceRelease(heightSpace);
    free(height_maps[0].pixels);height_maps[0]=(HeightMapData){.valid=1,.number=50123};decode_height_map(height_maps,heightPath);assert(height_maps[0].pixels&&height_maps[0].width==1&&height_maps[0].height==1);Vec heightColor=height_map_sample(50123,-.23,1.47);assert(fabs(heightColor.x-32768/65535.)<2/65535.&&fabs(heightColor.y-12345/65535.)<2/65535.&&fabs(heightColor.z-60000/65535.)<2/65535.);unlink(heightPath);
    free(height_maps[0].pixels);height_maps[0].width=height_maps[0].height=2;height_maps[0].pixels=calloc(16,sizeof(uint16_t));height_maps[0].pixels[0]=65535;height_maps[0].pixels[5]=65535;height_maps[0].pixels[10]=65535;height_maps[0].pixels[12]=65535;
    Vec center=height_map_sample(50123,0,0);assert(fabs(center.x-5./9)<1e-12&&fabs(center.y-2./9)<1e-12&&fabs(center.z-2./9)<1e-12);
    for(int i=0;i<20;i++){double u=i*.13-.7,v=i*.19-.8;Vec a=height_map_sample(50123,u,v),b=height_map_sample(50123,u+3,v-2);assert(fabs(a.x-b.x)<1e-12&&fabs(a.y-b.y)<1e-12&&fabs(a.z-b.z)<1e-12);}
    free(height_maps[0].pixels);height_maps[0]=(HeightMapData){0};puts("Height maps decode 16-bit channels, preserve RGB, use cubic spline weights and tile over negative coordinates.");
    scene_defaults();puts("480 original BoxIFS/HeightMapIFS steps match signed distances, twist, channels, map coordinates and orbit traps.");

    for(size_t i=0;i<sizeof difs_vectors/sizeof *difs_vectors;i++){
        DifsVector v=difs_vectors[i];FormulaSlot f=formula_slot_default(v.kind);for(int j=0;j<formula_parameter_count(f.kind);j++)formula_slot_set_value(&f,j,v.parameters[j]);
        double scale=1.3,trap=.123;Vec next;double d=difs_formula(v.input,f,&next,&scale,&trap,v.iteration);
        double a[]={d,scale,trap,next.x,next.y,next.z},b[]={v.distance,v.scale,v.trap,v.next.x,v.next.y,v.next.z};
        for(int j=0;j<6;j++)if(!(fabs(a[j]-b[j])<1e-9*(1+fabs(b[j])))){fprintf(stderr,"DIFS vector %zu kind %d component %d: %.17g != %.17g\n",i,v.kind,j,a[j],b[j]);assert(0);}
    }
    puts("1280 original SSE2/x87 steps match trifoliumIFS, helistairsIFS, hextgrid2IFS and boardIFS.");

    for(size_t i=0;i<sizeof dihed_vectors/sizeof *dihed_vectors;i++){
        ExtraVector v=dihed_vectors[i];Vec result=tglad_dihed(v.input,(Vec){.13,-.21,.07},v.values);
        double actual[]={result.x,result.y,result.z},expected[]={v.output.x,v.output.y,v.output.z};
        for(int j=0;j<3;j++)if(!(fabs(actual[j]-expected[j])<1e-8*(1+fabs(expected[j])))){fprintf(stderr,"Dihed vector %zu component %d: %.17g != %.17g\n",i,j,actual[j],expected[j]);assert(0);}
    }
    puts("TgladDihed matches original x87 steps across all 64 power combinations.");

    for(size_t i=0;i<sizeof surf_vectors/sizeof *surf_vectors;i++){
        SurfVector v=surf_vectors[i];double scale=v.scaleBefore,factor;Vec result=amazing_surf(v.input,v.constant,v.parameters,&scale,&factor);
        double actual[]={result.x,result.y,result.z,scale,factor},expected[]={v.output.x,v.output.y,v.output.z,v.scaleAfter,v.factor};
        for(int j=0;j<5;j++)if(!(fabs(actual[j]-expected[j])<1e-10*(1+fabs(expected[j])))){fprintf(stderr,"Surf vector %zu component %d: %.17g != %.17g\n",i,j,actual[j],expected[j]);assert(0);}
    }
    FormulaProgram surfProgram=legacy_program();surfProgram.slots[0]=formula_slot_default(109);surfProgram.slots[0].count=1;surfProgram.slots[0].parameters[6]=.17;surfProgram.bailout=1e10;
    Vec surfInput={.2,.3,.4},surfExpected=surfInput;double surfScale=NAN,surfFactor;
    for(int i=0;i<3;i++)surfExpected=amazing_surf(surfExpected,surfInput,surfProgram.slots[0].parameters,&surfScale,&surfFactor);
    OrbitResult surfOrbit=program_orbit(surfInput,surfProgram,0,0,0,3,1);
    assert(fabs(surfOrbit.z.x-surfExpected.x)<1e-12&&fabs(surfOrbit.z.y-surfExpected.y)<1e-12&&fabs(surfOrbit.z.z-surfExpected.z)<1e-12);
    assert(formula_kind_from_name("AmazingSurf")==109&&formula_kind_from_name("Amazing Surf")==109);
    puts("Amazing Surf matches original x87 steps, varying scale state, sphere/cylinder folds and rotation.");

    for(size_t i=0;i<sizeof new_vectors/sizeof *new_vectors;i++){
        NewFormulaVector v=new_vectors[i];FormulaSlot f=formula_slot_default(v.kind);memcpy(f.parameters,v.parameters,sizeof v.parameters);
        Vec input={v.input[0],v.input[1],v.input[2]},c={v.constant[0],v.constant[1],v.constant[2]};double w=v.input[3],dr=1,power=2;
        Vec actual=slot_step_context(input,&c,&w,f,&dr,&power);double result[]={actual.x,actual.y,actual.z,w};
        for(int j=0;j<4;j++)assert(fabs(result[j]-v.output[j])<1e-10*(1+fabs(v.output[j])));
    }
    for(size_t i=0;i<sizeof torus_vectors/sizeof *torus_vectors;i++){
        NewFormulaVector v=torus_vectors[i];FormulaSlot f=formula_slot_default(108);memcpy(f.parameters,v.parameters,sizeof v.parameters);
        double dr=1,power=2;Vec actual=slot_step((Vec){v.input[0],v.input[1],v.input[2]},(Vec){0},f,&dr,&power);
        double result[]={actual.x,actual.y,actual.z};for(int j=0;j<3;j++)assert(fabs(result[j]-v.output[j])<1e-10*(1+fabs(v.output[j])));
    }
    FormulaSlot torus=formula_slot_default(108);Vec singular=torus_pinv3((Vec){1,0,0},torus.parameters);assert(!isfinite(singular.x)&&!isfinite(singular.y)&&singular.z==0);
    assert(formula_modifier(108)&&formula_parameter_count(108)==5&&formula_kind_from_name("_toruspinv3")==108);
    puts("200 original x87 steps match _toruspinv3, including default and negative parameter values.");
    for(int i=0;i<100;i++){
        FormulaSlot f=formula_slot_default(2);f.parameters[0]=sin(i*.17)*2;f.parameters[1]=cos(i*.13);
        Vec z={sin(i*.37),cos(i*.29),sin(i*.11)},c={.17,-.23,.31};double oldW=cos(i*.19),w=oldW,dr=1,power=2;
        Vec actual=slot_step_context(z,&c,&w,f,&dr,&power);
        assert(fabs(actual.x-(z.x*z.x-z.y*z.y-z.z*z.z-oldW*oldW+c.x))<1e-12);
        assert(fabs(actual.y-(2*(z.y*z.x+z.z*oldW)+c.y))<1e-12);
        assert(fabs(actual.z-(2*(z.z*z.x+f.parameters[0]*z.y*oldW)+c.z))<1e-12);
        assert(fabs(w-(2*(oldW*z.x+z.y*z.z)+f.parameters[1]))<1e-12);
    }
    FormulaProgram quaternion=legacy_program();quaternion.slots[0]=formula_slot_default(2);quaternion.slots[0].count=1;quaternion.bailout=1e10;
    Vec input={.2,.3,.4},quaternionConstant=input;double qw=0,qd=1,qp=2;Vec one=slot_step_context(input,&quaternionConstant,&qw,quaternion.slots[0],&qd,&qp);
    OrbitResult orbit=program_orbit(input,quaternion,0,0,0,1,0);assert(fabs(orbit.radius-sqrt(dot(one,one)+qw*qw))<1e-12);
    puts("480 original x87 steps match _addC, _SinY and Benesi3Pow2; Quaternion matches the original 4D equations and escape radius.");
    double previous=-1;int distinct=0;for(int i=0;i<40;i++){double visibility=fmin(1,ambient_ray_visibility((Vec){1.05+i*.025,0,0},(Vec){0,0,1},10,.0001,128,sqrt(3.5),1.7357,.0002,test_ao_sphere));assert(isfinite(visibility)&&visibility>=0&&visibility<=1);assert(visibility>=previous-1e-7);if(visibility-previous>1e-5)distinct++;previous=visibility;}assert(distinct>20);
    assert(ambient_visibility_strength(.25,2)==.0625);assert(ambient_visibility_strength(.5,2)==.25);assert(ambient_visibility_strength(.25,0)==1);assert(ambient_visibility_strength(.25,1)==.25);
    int rayCounts[]={3,7,17,33};for(int q=0;q<4;q++){Vec directions[64];double step,neighbor,weight;int count=ambient_directions(rayCounts[q],directions,&step,&neighbor,&weight);assert(count==rayCounts[q]);for(int i=0;i<count;i++){Vec v=directions[i];double visibility=ambient_ray_visibility((Vec){0,.001,0},(Vec){v.x,v.z,v.y},1,.001,64,sqrt(count*.5),step,.002,test_ao_plane);assert(fmin(1,visibility)==1);}double enclosed=ambient_ray_visibility((Vec){0,0,0},(Vec){0,0,1},10,.0001,128,sqrt(count*.5),step,.0002,test_ao_sphere);assert(enclosed<.001);}
    assert(fmin(1,ambient_ray_visibility((Vec){0,0,0},(Vec){0,0,1},1,.0001,128,sqrt(3.5),1.7357,.0002,test_ao_sphere))==1);
    puts("DEAO is continuous, preserves full visibility on open planes at original ray counts, and reaches deep occlusion without a brightness floor.");
    for(size_t i=0;i<sizeof rand_vectors/sizeof *rand_vectors;i++){RandVector v=rand_vectors[i];double scale=1,trap;Vec next;double d=rand_cubes(v.p,v.values,&next,&scale,&trap);assert(fabs(d-v.distance)<1e-7*(1+fabs(v.distance))&&fabs(trap-v.trap)<1e-12);}
    for(size_t i=0;i<sizeof extra_vectors/sizeof *extra_vectors;i++){ExtraVector v=extra_vectors[i];Vec actual=v.kind==102?sierpinski_full(v.input,v.values):v.kind==104?transform_formula(v.input,v.values):v.input;if(v.kind==103&&v.values[0]<3){double value=sine_approx(v.values[0]==0?v.input.x:v.values[0]==1?v.input.y:v.input.z,v.values);if(v.values[0]==0)actual.x=value;else if(v.values[0]==1)actual.y=value;else actual.z=value;}assert(fabs(actual.x-v.output.x)<1e-10&&fabs(actual.y-v.output.y)<1e-10&&fabs(actual.z-v.output.z)<1e-10);}
    scene_defaults();
    for(size_t i=0;i<sizeof sierp_de_vectors/sizeof *sierp_de_vectors;i++){SierpDEVector v=sierp_de_vectors[i];FormulaProgram p=legacy_program();p.slots[0]=formula_slot_default(102);p.slots[0].count=1;memcpy(p.slots[0].parameters,v.parameters,sizeof v.parameters);p.bailout=1e10;p.numerical_de=0;OrbitResult result=program_part(v.input,p,0,0,0,12);assert(fabs(result.sample.distance-v.distance)<1e-10*(1+fabs(v.distance)));}
    puts("100 complete SierpinskiFull analytic distances match original x86 orbits with ADE scale 1.");
    Vec normalsToTest[]={{0,0,-1},{0,0,1},{.3,.4,.8660254037844386},{.8,.6,0}};for(int i=0;i<4;i++){Vec n=normalsToTest[i],direction=ambient_orient_direction((Vec){0,0,1},n);assert(dot(direction,n)>1-1e-6);Vec ring=ambient_orient_direction((Vec){.5,0,sqrt(.75)},n);assert(fabs(dot(ring,n)-sqrt(.75))<1e-6);}
    for(int power=2;power<=8;power++)for(int i=0;i<100;i++){FormulaSlot f=formula_slot_default(6);f.power=power;Vec p={sin(i*.37)*3,cos(i*.13)*4,sin(i*.21)*5},c={.1,.2,-.3};double a[]={p.x,p.y,p.z};for(int j=0;j<3;j++){if(a[j]>2)a[j]=4-a[j];else if(a[j]<-2)a[j]=-4-a[j];}double radius=sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]),az=power*atan2(a[1],a[0]),lat=power*asin(radius?a[2]/radius:0),rn=pow(radius,power);Vec reference={rn*cos(lat)*cos(az)+c.x,rn*cos(lat)*sin(az)+c.y,-rn*sin(lat)+c.z};double derivative=1,pow;Vec actual=slot_step(p,c,f,&derivative,&pow);assert(fabs(actual.x-reference.x)<1e-7*(1+fabs(reference.x))&&fabs(actual.y-reference.y)<1e-7*(1+fabs(reference.y))&&fabs(actual.z-reference.z)<1e-7*(1+fabs(reference.z)));}
    FormulaProgram p=legacy_program();p.slots[0]=formula_slot_default(100);p.slots[0].count=1;p.bailout=1024;
    double dr=1,power;Vec c={.17,.23,.31};Vec noC=slot_step(c,c,p.slots[0],&dr,&power);double factor;Vec folded=amazing_box(c,2,.5,1,&factor);assert(fabs(noC.x-folded.x)<1e-12&&fabs(dr-fabs(factor))<1e-12);
    RenderOptions options={.width=31,.height=17,.threads=2,.iterations=12,.program_override=1,.program=p};
    for(int index=0;index<36;index++) {
        const int kinds[]={100,101,102,103,104,6,2,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133};int kind=kinds[index];
        options.program.slots[0]=formula_slot_default(kind);options.program.slots[0].count=1;
        if(kind==112){formula_slot_set_value(&options.program.slots[0],13,123.25);formula_slot_set_value(&options.program.slots[0],14,.47);}
        if(kind==114)formula_slot_set_value(&options.program.slots[0],13,123.75);
        if(kind==102){options.program.slots[0].parameters[4]=23;options.program.slots[0].parameters[8]=-17;options.program.slots[0].parameters[10]=.6;options.program.slots[0].parameters[12]=1;}
        if(formula_modifier(kind)){options.program.slots[1]=formula_slot_default(0);options.program.slots[1].count=1;options.program.repeat_from=1;options.program.slots[0].parameters[1]=.3;}
        else {options.program.slots[1].count=0;options.program.repeat_from=0;}
        char path[]="/tmp/integer-power-extra-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);
        RenderResult saved=render_scene_to_m3i(NULL,options,path);if(!saved.rgba)fprintf(stderr,"%s\n",saved.error);assert(saved.rgba);
        RenderResult loaded=render_scene(path,0,0,1);if(!loaded.rgba)fprintf(stderr,"%s\n",loaded.error);assert(loaded.rgba&&loaded.settings.program.slots[0].kind==kind);assert(!memcmp(saved.rgba,loaded.rgba,saved.stride*saved.height));for(int j=0;j<formula_parameter_count(options.program.slots[0].kind);j++)assert(formula_slot_value(options.program.slots[0],j)==formula_slot_value(loaded.settings.program.slots[0],j));
        assert(!truncate(path,840+31*17*18+1136));RenderResult standard=render_scene(path,0,0,1);if(!standard.rgba)fprintf(stderr,"standard: %s\n",standard.error);assert(standard.rgba&&standard.settings.program.slots[0].kind==kind);assert(!memcmp(saved.rgba,standard.rgba,saved.stride*saved.height));for(int j=0;j<formula_parameter_count(options.program.slots[0].kind);j++)assert(formula_slot_value(options.program.slots[0],j)==formula_slot_value(standard.settings.program.slots[0],j));free(standard.rgba);
        unlink(path);free(saved.rgba);free(loaded.rgba);
    }
    options.program.slots[1].count=0;options.program.repeat_from=0;
    for(int kindIndex=0;kindIndex<2;kindIndex++)for(int radiusIndex=0;radiusIndex<3;radiusIndex++){
        int kind=kindIndex?100:4;double radius=radiusIndex==0?-100:radiusIndex==1?-.5:0;
        options.program.slots[0]=formula_slot_default(kind);options.program.slots[0].count=1;options.program.slots[0].min_radius=radius;
        assert(valid_program(options.program));assert(formula_parameter(kind,1)->minimum==-100);
        double derivative=1,pow;Vec origin=slot_step((Vec){0},(Vec){0},options.program.slots[0],&derivative,&pow);assert(isfinite(origin.x)&&isfinite(derivative));
        char path[]="/tmp/integer-power-negative-radius-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);
        RenderResult saved=render_scene_to_m3i(NULL,options,path);assert(saved.rgba);
        RenderResult loaded=render_scene(path,0,0,1);assert(loaded.rgba&&loaded.settings.program.slots[0].min_radius==radius);free(loaded.rgba);
        assert(!truncate(path,840+31*17*18+1136));loaded=render_scene(path,0,0,1);assert(loaded.rgba&&loaded.settings.program.slots[0].min_radius==radius);assert(!memcmp(saved.rgba,loaded.rgba,saved.stride*saved.height));for(int j=0;j<formula_parameter_count(options.program.slots[0].kind);j++)assert(formula_slot_value(options.program.slots[0],j)==formula_slot_value(loaded.settings.program.slots[0],j));free(loaded.rgba);free(saved.rgba);unlink(path);
    }
    puts("Both Box formulas accept negative and zero Min R and preserve them in native/standard files.");
    for(int reversed=0;reversed<=6;reversed++){
        FormulaSlot f=formula_slot_default(102);formula_slot_set_value(&f,12,reversed);assert(formula_parameter(102,12)->maximum==6);assert(validate_imported_slot(&f,2));options.program.slots[0]=f;options.program.slots[0].count=1;
        char path[]="/tmp/integer-power-reversed-fold-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);RenderResult saved=render_scene_to_m3i(NULL,options,path);assert(saved.rgba);RenderResult loaded=render_scene(path,0,0,1);assert(loaded.rgba&&loaded.settings.program.slots[0].parameters[12]==reversed);free(loaded.rgba);assert(!truncate(path,840+31*17*18+1136));loaded=render_scene(path,0,0,1);assert(loaded.rgba&&loaded.settings.program.slots[0].parameters[12]==reversed);assert(!memcmp(saved.rgba,loaded.rgba,saved.stride*saved.height));for(int j=0;j<formula_parameter_count(options.program.slots[0].kind);j++)assert(formula_slot_value(options.program.slots[0],j)==formula_slot_value(loaded.settings.program.slots[0],j));free(loaded.rgba);free(saved.rgba);unlink(path);
    }
    FormulaSlot outOfRange=formula_slot_default(102);outOfRange.parameters[12]=7;assert(validate_imported_slot(&outOfRange,2)&&outOfRange.parameters[12]==6);
    puts("SierpinskiFull Reversed fold accepts and round-trips every integer 0–6; rejects 7.");
    scene_defaults();Vec constant={.1,.2,.3},z={1,2,3};double w=1,derivative=1;power=2;FormulaSlot transform=formula_slot_default(104);transform.parameters[0]=2;transform.parameters[1]=1;Vec changed=slot_step_context(z,&constant,&w,transform,&derivative,&power);assert(changed.x==4&&constant.x==4&&constant.y==4&&constant.z==6&&w==2&&derivative==2);
    scene.julia=1;constant=(Vec){.1,.2,.3};changed=slot_step_context(z,&constant,&w,transform,&derivative,&power);assert(constant.x==.1);scene.julia=0;
    FormulaSlot sine=formula_slot_default(103);sine.parameters[0]=3;double oldW=w;changed=slot_step_context(z,&constant,&w,sine,&derivative,&power);assert(changed.x==z.x&&w==sine_approx(oldW,sine.parameters));
    options.program.slots[0]=transform;options.program.slots[0].count=1;options.program.slots[1]=formula_slot_default(101);options.program.slots[1].count=1;options.program.repeat_from=1;RenderResult transformedIFS=render_scene_with_options(NULL,options);assert(transformedIFS.rgba);free(transformedIFS.rgba);options.program.repeat_from=0;
    for(int copy=-4;copy<=2;copy++){
        FormulaSlot f=formula_slot_default(104);formula_slot_set_value(&f,7,copy);f.parameters[1]=.3;assert(validate_imported_slot(&f,0));
        for(int julia=0;julia<2;julia++){scene.julia=julia;Vec c={.1,.2,.3};double localW=0,d=1,pow=2;Vec result=slot_step_context((Vec){1,2,3},&c,&localW,f,&d,&pow);assert(c.x==(!julia&&copy!=0?result.x:.1));}scene.julia=0;
        FormulaProgram program=legacy_program();for(int i=0;i<8;i++){program.slots[i]=formula_slot_default(0);program.slots[i].count=0;}program.slots[0]=f;program.slots[0].count=1;program.slots[1].count=1;program.mode=0;program.repeat_from=1;options.program=program;
        char path[]="/tmp/integer-power-copy-to-c-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);RenderResult saved=render_scene_to_m3i(NULL,options,path);assert(saved.rgba);RenderResult loaded=render_scene(path,0,0,1);assert(loaded.rgba&&loaded.settings.program.slots[0].parameters[7]==copy);free(loaded.rgba);assert(!truncate(path,840+31*17*18+1136));loaded=render_scene(path,0,0,1);assert(loaded.rgba&&loaded.settings.program.slots[0].parameters[7]==copy);assert(!memcmp(saved.rgba,loaded.rgba,saved.stride*saved.height));for(int j=0;j<formula_parameter_count(options.program.slots[0].kind);j++)assert(formula_slot_value(options.program.slots[0],j)==formula_slot_value(loaded.settings.program.slots[0],j));free(loaded.rgba);free(saved.rgba);unlink(path);
    }
    puts("Copy to C -4..2 preserves original zero/nonzero and Julia behavior, and round-trips both file formats.");
    puts("New formula kernels, Folding powers 2-8, modifier C/W state and modifier-plus-IFS chains passed.");
    options.program.slots[0]=formula_slot_default(100);options.program.slots[0].count=1;options.program.slots[1]=formula_slot_default(101);options.program.slots[1].count=1;options.program.mode=2;options.program.repeat_from=0;options.program.max_iterations2=12;
    RenderResult combo=render_scene_with_options(NULL,options);assert(combo.rgba);free(combo.rgba);
    options.program.combine=5;RenderResult mixed=render_scene_with_options(NULL,options);assert(mixed.rgba);free(mixed.rgba);
    options.program.mode=0;RenderResult rejected=render_scene_with_options(NULL,options);assert(!rejected.rgba&&strstr(rejected.error,"DEcombinate"));
    options.program=legacy_program();for(int i=0;i<8;i++){options.program.slots[i]=formula_slot_default(0);options.program.slots[i].count=0;}options.program.slots[0].count=1;options.program.slots[2]=formula_slot_default(102);options.program.slots[2].count=1;options.program.slots[7]=formula_slot_default(104);options.program.slots[7].count=1;options.program.mode=0;options.program.repeat_from=0;
    char errorPath[]="/tmp/integer-power-import-error-XXXXXX";int errorFD=mkstemp(errorPath);assert(errorFD>=0);close(errorFD);RenderResult errorBase=render_scene_to_m3i(NULL,options,errorPath);assert(errorBase.rgba);free(errorBase.rgba);
    int errorFile=open(errorPath,O_RDWR);assert(errorFile>=0);off_t addon=840+31*17*18,native=addon+1136;unsigned char number[8];put64f(number,3);assert(pwrite(errorFile,number,8,native+2404+7*104+7*8)==8);
    RenderResult badNative=render_scene(errorPath,0,0,1);assert(!badNative.rgba&&strstr(badNative.error,"slot 8")&&strstr(badNative.error,"_Transform")&&strstr(badNative.error,"Copy to C"));
    assert(!ftruncate(errorFile,native));double invalidValues[]={101,.5,NAN};int indices[]={0,12,4};const char *names[]={"Scale","Reversed fold","Rotation1 X"};for(int i=0;i<3;i++){put64f(number,invalidValues[i]);assert(pwrite(errorFile,number,8,addon+8+2*188+60+indices[i]*8)==8);RenderResult badStandard=render_scene(errorPath,0,0,1);assert(!badStandard.rgba&&strstr(badStandard.error,"slot 3")&&strstr(badStandard.error,"SierpinskiFull")&&strstr(badStandard.error,names[i]));put64f(number,formula_parameter(102,indices[i])->default_value);assert(pwrite(errorFile,number,8,addon+8+2*188+60+indices[i]*8)==8);}
    close(errorFile);unlink(errorPath);puts("Import errors identify exact source slots, formulas and parameters, including native slot 8, non-finite and fractional values.");
    puts("_AmazingBox omits C; RandCubesIFS matches x86 golden vectors; both formulas round-trip native/standard files and combine in separate DE groups.");
}
