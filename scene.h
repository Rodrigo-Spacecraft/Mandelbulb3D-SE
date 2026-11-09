/* Scene data and explicit little-endian MB3D decoding. LGPL-2.1-or-later. */
#include <limits.h>
typedef struct { int option,function; double amplitude; Vec color,position; } Light;
typedef struct { unsigned position; Vec diffuse,specular; } Stop;
typedef struct {
    int program_enabled;FormulaProgram program;
    int oversampling,viewing,size_flags,normal_smoothing,bin_search_steps,light_mixing,normal_zbuffer;
    int width,height,iterations,power,julia,optic,vary,cycle,no_interpolation;
    int power2,count1,count2,repeat_from;double zmul2;
    int kind,kind2;double scale,min_radius,fold,scale2,min_radius2,fold2;
    int gamma,background_function,ambient_object,far_fog,ao_enabled,color_on_trap;double z_variation;
    double roughness;
    double zmul,bailout,zstart,zend,zoom,fov,de_stop,ray_step,raystep_limiter;
    double diffuse,specular,ambient,depth,ao_amount,indirect,cstart,cspan,col_z,diffuse_shadow;
    Vec center,julia_c,amb_top,amb_bottom,bg_top,bg_bottom;
    double matrix[3][3]; Light lights[6]; Stop stops[10];
    ShadowSettings shadows;ObjectMap map;DepthOfFieldSettings dof;ReflectionSettings reflections;
    int cutting_mask;double cutting[3];ObjectLighting cutting_colors;
    int color_option;double color_multiplier;SSAOSettings ssao;FogSettings fog;double rotation4[3],julia_w;float matrix4[16];
    int preserved_header_valid;unsigned char preserved_header[840];
    int direct_origin;Vec view_origin;
} Scene;
static Scene scene;
static FormulaProgram legacy_program(void) {
    FormulaProgram p={.repeat_from=scene.repeat_from,.min_iterations=1,.bailout=scene.bailout,.split=1,.repeat2=1,.max_iterations2=scene.iterations,.formula_power=2,.smooth=.5};
    for(int i=0;i<8;i++)p.slots[i]=formula_slot_default(-1);
    p.slots[0]=(FormulaSlot){scene.kind,scene.power,scene.count1,scene.zmul,scene.scale,scene.min_radius,scene.fold,{0}};
    if(scene.count2||scene.kind2!=0)p.slots[1]=(FormulaSlot){scene.kind2,scene.power2,scene.count2,scene.zmul2,scene.scale2,scene.min_radius2,scene.fold2,{0}};return p;
}
static int valid_program(FormulaProgram p) {
    if(p.slots[6].count||p.slots[7].count)return 0;
    if(p.mode<0||p.mode>2||p.repeat_from<0||p.repeat_from>5||p.min_iterations<0||p.min_iterations>10000||p.numerical_de<0||p.numerical_de>1||p.render_mode<0||p.render_mode>2||p.split<1||p.split>5||p.repeat2<0||p.repeat2>5||p.max_iterations2<1||p.max_iterations2>10000||p.combine<0||p.combine>5||!isfinite(p.bailout)||p.bailout<=1||p.bailout>1e10||!isfinite(p.smooth)||p.smooth<1e-12||p.smooth>1e6||!isfinite(p.formula_power)||p.formula_power<1.000001||p.formula_power>100)return 0;
    int first=0,second=0,repeat=0,repeat2=0,repeatFirst=0;
    for(int i=0;i<8;i++){FormulaSlot f=p.slots[i];if(f.kind==-1&&!f.count)continue;if(!formula_supported(f.kind)||f.power<2||f.power>8||(p.mode==1?(!isfinite(formula_iteration_value(p,i))||formula_iteration_value(p,i)<0||formula_iteration_value(p,i)>10000):(f.count<0||f.count>10000))||!isfinite(f.z_multiplier)||fabs(f.z_multiplier)>100||(!formula_generic(f.kind)&&(!isfinite(f.scale)||fabs(f.scale)>100||!isfinite(f.min_radius)||fabs(f.min_radius)>100||!isfinite(f.fold)||fabs(f.fold)>100)))return 0;if(formula_generic(f.kind))for(int j=0;j<formula_parameter_count(f.kind);j++){const FormulaParameter *spec=formula_parameter(f.kind,j);double v=formula_slot_value(f,j);if(!isfinite(v)||v<spec->minimum||v>spec->maximum||(spec->integer&&v!=floor(v)))return 0;}if(f.count){first+=i<p.split;second+=i>=p.split;repeat+=i>=p.repeat_from;repeat2+=i>=p.repeat2;repeatFirst+=i>=p.repeat_from&&i<p.split;}}
    return (first+second)>0&&repeat&&(p.mode!=2||(first&&second&&repeatFirst&&repeat2&&p.repeat2>=p.split&&p.repeat_from<p.split));
}
static const char *program_formula_error(FormulaProgram p) {
    if(p.mode==2&&p.combine==5){for(int i=0;i<8;i++)if(p.slots[i].count&&((i<p.split&&formula_difs(p.slots[i].kind))||(i>=p.split&&!formula_difs(p.slots[i].kind)&&!formula_modifier(p.slots[i].kind))))return "Mix requires escape-time formulas in part 1 and direct-distance formulas in part 2.";}

    for(int group=0;group<(p.mode==2?2:1);group++){int difs=0,escape=0;for(int i=0;i<8;i++)if(p.slots[i].count&&(p.mode!=2||(i>=p.split)==group)){difs+=formula_difs(p.slots[i].kind);escape+=!formula_difs(p.slots[i].kind)&&!formula_modifier(p.slots[i].kind);}
        if(difs&&p.mode==1)return "Direct-distance IFS formulas cannot use Interpolate.";
        if(difs&&escape)return "Use separate DEcombinate groups to combine direct-distance IFS with escape-time formulas.";
    }return NULL;
}
static char scene_error[512];
static Vec raw_color(const unsigned char *p) { return (Vec){p[0]/255.,p[1]/255.,p[2]/255.}; }
static uint16_t u16(const unsigned char *p) { return (uint16_t)(p[0]|p[1]<<8); }
static uint32_t u32(const unsigned char *p) { return (uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24; }
static double f64(const unsigned char *p) {
    uint64_t bits=0; for(int i=0;i<8;i++) bits|=(uint64_t)p[i]<<(8*i);
    double v; memcpy(&v,&bits,8); return v;
}
static double f32(const unsigned char *p) { uint32_t bits=u32(p);float v;memcpy(&v,&bits,4);return v; }
static double f56(const unsigned char *p) { unsigned char b[8]={0};memcpy(b+1,p,7);return f64(b); }
static Vec packed_color(uint32_t c) { unsigned char b[3]={(unsigned char)c,(unsigned char)(c>>8),(unsigned char)(c>>16)};return raw_color(b); }
static int valid_dof(DepthOfFieldSettings d){return !(d.enabled&~1)&&!(d.automatic&~1)&&d.passes>=1&&d.passes<=3&&isfinite(d.focus1)&&isfinite(d.focus2)&&d.focus1>=0&&d.focus2>=0&&d.focus1<=1e6&&d.focus2<=1e6&&isfinite(d.aperture)&&d.aperture>=0&&d.aperture<=2&&isfinite(d.clip_radius)&&d.clip_radius>=.1&&d.clip_radius<=1000;}
static ReflectionSettings default_reflections(void){return (ReflectionSettings){.depth=2,.amount=1,.absorption=.2,.refractive_index=1.5,.scattering=1};}
static int valid_reflections(ReflectionSettings v){if(v.opacity_set&~1)return 0;if(v.opacity_set)for(int c=0;c<2;c++)for(int i=0;i<10;i++)if(!isfinite(v.opacity[c][i])||v.opacity[c][i]<0||v.opacity[c][i]>1)return 0;return !(v.enabled&~1)&&!(v.automatic&~1)&&!(v.transparency&~1)&&!(v.only_difs&~1)&&v.depth>=1&&v.depth<=30&&isfinite(v.amount)&&v.amount>=0&&v.amount<=100&&isfinite(v.absorption)&&v.absorption>=0&&v.absorption<=1e10&&isfinite(v.refractive_index)&&v.refractive_index>=.1&&v.refractive_index<=10&&isfinite(v.scattering)&&v.scattering>=0&&v.scattering<=1e30;}
static int valid_fog(FogSettings f) {
    if(f.mode<0||f.mode>3||f.light<1||f.light>6||f.iterations<0||f.iterations>255||f.blend<0||f.blend>1||(f.only_add<0||f.only_add>1)||f.map_size< -2||f.map_size>9)return 0;
    if(!isfinite(f.strength)||f.strength<0||f.strength>159||!isfinite(f.offset)||f.offset<0||f.offset>256||!isfinite(f.far_offset)||f.far_offset<0||f.far_offset>256)return 0;
    for(int c=0;c<2;c++)for(int i=0;i<3;i++)if(!isfinite(f.colors[c][i])||f.colors[c][i]<0||f.colors[c][i]>1)return 0;
    return 1;
}
static void scene_defaults(void) {
    scene_error[0]=0;
    memset(&scene,0,sizeof scene);
    for(int i=0;i<4;i++)scene.matrix4[i*4+i]=1;
    scene.color_multiplier=1;
    scene.ssao=(SSAOSettings){.threshold=2,.samples=1};
    scene.reflections=default_reflections();scene.fog=fog_settings_default();
    scene.dof=(DepthOfFieldSettings){.passes=1,.aperture=.02,.clip_radius=25};
    scene.oversampling=scene.viewing=1;scene.size_flags=3;scene.width=480;scene.height=360;scene.iterations=60;scene.power=8;
    scene.scale=scene.scale2=2;scene.min_radius=scene.min_radius2=.5;scene.fold=scene.fold2=1;
    scene.map.scale=1;scene.map.offset_x=scene.map.offset_y=.5;
    scene.power2=8;scene.zmul2=-1;scene.count1=1;scene.count2=0;scene.repeat_from=0;
    scene.zmul=-1;scene.bailout=16;scene.zstart=-2;scene.zend=30;
    scene.zoom=1;scene.fov=30;scene.de_stop=.5;scene.ray_step=.5;scene.raystep_limiter=1;scene.bin_search_steps=8;scene.vary=1;
    scene.diffuse_shadow=1;scene.diffuse=2.4;scene.specular=1;scene.ambient=1;scene.depth=27*.8e-6;
    scene.cycle=1;scene.gamma=32;scene.ao_enabled=1;scene.ao_amount=1;
    scene.shadows=(ShadowSettings){.hard_mask=1,.hard_length=1,.hard_radius=1,.ambient_enabled=1,
        .ambient_auto=1,.ambient_rays=7,.ambient_steps=64,.ambient_length=1,.ambient_strength=1};
    scene.indirect=pow(53*.022,2);
    scene.cstart=pow(98./90,2)*32767-10900;
    scene.cspan=(pow(102./90,2)-pow(98./90,2))*32767;
    scene.amb_top=scene.bg_top=packed_color(0x8B491D);
    scene.amb_bottom=scene.bg_bottom=packed_color(0xFFC49F);
    double sx=sin(-.7),cx=cos(-.7),sy=sin(-.0001),cy=cos(-.0001);
    double m[3][3]={{cy,0,sy},{sx*sy,cx,-sx*cy},{-cx*sy,sx,cx*cy}};
    memcpy(scene.matrix,m,sizeof m);
    for(int i=0;i<6;i++)scene.lights[i]=(Light){1,53,1,{1,1,1},{1500*PI/16384,5200*PI/16384,0}};
    scene.lights[0]=(Light){0,53,1,packed_color(0xA0E8FF),{1500*PI/16384,5200*PI/16384,0}};
    scene.cutting_colors=default_cutting_colors();
    uint32_t dif[3]={5873889,2988346,11287584},spe[3]={8837614,12248958,14579248};
    for(int i=0;i<10;i++) scene.stops[i]=(Stop){i<3?(unsigned)i*10922:32200+(unsigned)(i-3)*84,packed_color(dif[i<3?i:0]),packed_color(spe[i<3?i:0])};
}
static int unsupported_formula_list(const unsigned char *addon,int records,char error[512]){
    const char *builtin[]={"Integer Power","Real Power","Quaternion","Tricorn","Amazing Box","Bulbox","Folding Int Pow","test","testIFS","Aexion C"};
    size_t length=0;int unsupported=0;
    for(int i=0;i<records;i++){
        const unsigned char *q=addon+8+i*188;unsigned id=u32(q+4);char name[33];memcpy(name,q+12,32);name[32]=0;
        for(int j=0;name[j];j++)if((unsigned char)name[j]<32||(unsigned char)name[j]>126)name[j]='?';
        if(!u32(q)&&!name[0])continue;
        if((id<10&&formula_kind_from_name(builtin[id])>=0)||(id>=20&&id<INT_MAX&&formula_kind_from_name(name)>=0))continue;
        if(!unsupported)length=(size_t)snprintf(error,512,"Unsupported formulas:\n");
        const char *label=id<10?builtin[id]:name[0]?name:"Unknown formula";
        if(length<511)length+=(size_t)snprintf(error+length,512-length,"Slot %d: %s (ID %u)\n",i+1,label,id);unsupported++;
    }return unsupported;
}
static int reject_scene(const char *why) { snprintf(scene_error,sizeof scene_error,"%s",why);fprintf(stderr,"Cannot render .m3i: %s\n",why);return 0; }
static int reject_formula_parameter(int slot,int kind,const char *name,double value,double minimum,double maximum,int integer) {
    char message[512];snprintf(message,sizeof message,"Formula slot %d (%s): parameter \"%s\" is %.17g; expected %sa finite value from %.17g to %.17g.",slot+1,formula_name(kind),name,value,integer?"an integer and ":"",minimum,maximum);return reject_scene(message);
}
static double clamp_imported_parameter(double value,const FormulaParameter *spec){
    if(!isfinite(value))return value;
    value=fmax(spec->minimum,fmin(spec->maximum,value));
    return spec->integer?round(value):value;
}
static int validate_imported_slot(FormulaSlot *imported,int slot,int interpolate){
    FormulaSlot f=*imported;
    if(!formula_supported(f.kind))return 1; /* The program validator reports unknown formula kinds. */
    for(int j=0;j<formula_parameter_count(f.kind);j++){const FormulaParameter *spec=formula_parameter(f.kind,j);double value=clamp_imported_parameter(formula_slot_value(f,j),spec);if(!isfinite(value)||value<spec->minimum||value>spec->maximum||(spec->integer&&value!=floor(value)))return reject_formula_parameter(slot,f.kind,spec->name,value,spec->minimum,spec->maximum,spec->integer);formula_slot_set_value(&f,j,value);}
    if(!interpolate)f.count=fmax(0,fmin(10000,f.count));*imported=f;
    if(!interpolate&&(f.count<0||f.count>10000))return reject_formula_parameter(slot,f.kind,"Iterations per pass",f.count,0,10000,1);
    return 1;
}

static void warn_lighting(const char *what) {
    fprintf(stderr,"Warning: ignoring unsupported lighting feature: %s\n",what);
}
static int load_m3i(const char *path) {
    unsigned char h[840],a[1136]; FILE *f=fopen(path,"rb");
    if(!f){snprintf(scene_error,sizeof scene_error,"%s: %s",path,strerror(errno));perror(path);return 0;}
    if(fread(h,1,sizeof h,f)!=sizeof h){fclose(f);return reject_scene("truncated 840-byte header");}
    uint32_t id=u32(h),w=u32(h+4),height=u32(h+8);
    if(id<20||id>44){fclose(f);return reject_scene("supported binary format IDs are 20–44 (modern header layout)");}
    if(w<16||height<16||w>RENDER_MAX_DIMENSION||height>RENDER_MAX_DIMENSION){fclose(f);return reject_scene("image dimensions must be 16–16384");}
    if(u32(h+428)){fclose(f);return reject_scene("tiled files are not supported");}
    /* .m3i: 840-byte header, width*height 18-byte TsiLight5 records,
       then 1136-byte THeaderCustomAddon. Never load its serialized pointers. */
    const char *extension=strrchr(path,'.');
    int parameters=extension&&!strcasecmp(extension,".m3p");
    uint64_t offset=parameters?840:840+(uint64_t)w*height*18;
    if(fseek(f,0,SEEK_END)||ftell(f)<0||(uint64_t)ftell(f)<offset+sizeof a||
       fseek(f,(long)offset,SEEK_SET)||fread(a,1,sizeof a,f)!=sizeof a) {
        fclose(f);return reject_scene(parameters?"truncated parameter file or missing formula addon":"truncated pixel buffer or missing formula addon");
    }
    unsigned char extra[4096];size_t extra_count=fread(extra,1,sizeof extra,f);
    /* Old native files put settings immediately after the addon. Files with
       an original-format fullSizeImage put settings after its BGRA pixels. */
    if(!parameters&&(extra_count<8||memcmp(extra,"IPMACM3I",8))){
        uint64_t nativeOffset=offset+sizeof a+(uint64_t)w*height*4;
        if(!fseek(f,(long)nativeOffset,SEEK_SET))extra_count=fread(extra,1,sizeof extra,f);
        else extra_count=0;
    }
    fclose(f);
    if(a[0]<16||a[0]>99)return reject_scene("legacy formula addon version; resave with current MB3D");
    if((a[1]&3)>2||((a[2]>>1)&3)>2)return reject_scene("unsupported formula mode");
    char unsupported[512];if(unsupported_formula_list(a,6,unsupported))return reject_scene(unsupported);
    int slots[8],counts[8]={1,0},powers[8]={8,8,8,8,8,8,8,8},used=0,repeat=0;
    double zmuls[8]={-1,-1,-1,-1,-1,-1,-1,-1},scales[8]={2,2,2,2,2,2,2,2},radii[8]={.5,.5,.5,.5,.5,.5,.5,.5},folds[8]={1,1,1,1,1,1,1,1};int kinds[8]={0};
    FormulaSlot decodedSlots[8];for(int i=0;i<8;i++)decodedSlots[i]=formula_slot_default(0);
    for(int i=0;i<6;i++) {
        int32_t count=(int32_t)u32(a+8+i*188);if(((a[1]&3)==1&&i>=2)||!count)continue;


        const unsigned char *form=a+8+i*188;
        char name[33];memcpy(name,form+12,32);name[32]=0;
        uint32_t id=u32(form+4);int kind=-1;
        if(id==0||id==2||id==4||id==6)kind=(int)id;
#if defined(USE_RUST_ENGINE) || defined(USE_C_FORMULA_VM)
        else if(id<10){const char *names[]={"Integer Power","Real Power","Quaternion","Tricorn","Amazing Box","Bulbox","Folding Int Pow","test","testIFS","Aexion C"};kind=formula_kind_from_name(names[id]);}
#endif
        else if(id>=20&&id<INT_MAX)kind=formula_kind_from_name(name);
        if(kind<0){char message[256];snprintf(message,sizeof message,"unsupported formula in slot %d: %s (ID %u)",i+1,name[0]?name:"Unknown",id);return reject_scene(message);}
        if((a[1]&3)!=1)count=fmax(0,fmin(10000,count));
        if(u32(form+8)<(unsigned)formula_parameter_count(kind)||u32(form+8)>16)return reject_scene("invalid formula option count");
        FormulaSlot f=formula_slot_default(kind);f.count=count;
        for(int j=0;j<formula_parameter_count(kind);j++){const FormulaParameter *spec=formula_parameter(kind,j);double value=f64(form+60+j*8);if(kind==106&&j==0&&isfinite(value))value=fabs(fmod(value,4));value=clamp_imported_parameter(value,spec);if(!isfinite(value)||value<spec->minimum||value>spec->maximum||(spec->integer&&value!=floor(value)))return reject_formula_parameter(i,kind,spec->name,value,spec->minimum,spec->maximum,spec->integer);formula_slot_set_value(&f,j,value);}
        decodedSlots[used]=f;scales[used]=f.scale;radii[used]=f.min_radius;folds[used]=f.fold;int power=f.power;double zmul=f.z_multiplier;
        kinds[used]=kind;
        slots[used]=i;counts[used]=count;powers[used]=(int)power;zmuls[used]=zmul;used++;
    }
    if(!used)return reject_scene("no active formula");
    if(used>=2) {
        int source_repeat=a[5]>>4;repeat=-1;
        for(int i=0;i<used;i++)if(slots[i]>=source_repeat){repeat=i;break;}
        if(repeat<0)return reject_scene("repeat point is beyond the active formulas");
        if((a[5]&15)<slots[used-1]&&!(a[1]&3))return reject_scene("formula end slot excludes active formulas");
    }
    if(h[18]&1)return reject_scene("quaternion camera representation is not supported");
#ifndef USE_RUST_ENGINE
    if(h[126])warn_lighting("stereo rendering; rendering a single view, preserving stereo settings");
    /* bSliceCalc remembers a slice position even after Calculate 3D.
       bCalc3D determines whether an image was actually a slice. Parameter
       files are loaded as scenes for a new 3D calculation. */
    if(!h[344]&&h[345])warn_lighting("2D slice mode; rendering in 3D, preserving slice settings");
    if(h[19])warn_lighting("color-on-iteration; using smooth-iteration coloring");
#endif



    if(h[148]>2)return reject_scene("unsupported camera optic");
    Scene next=scene;
    next.cutting_mask=h[176]&7;for(int i=0;i<3;i++)next.cutting[i]=f64(h+346+i*8);
    next.preserved_header_valid=1;memcpy(next.preserved_header,h,840);memset(next.preserved_header+382,0,28); /* Ignore packed Orig/Mod names. */
    next.viewing=h[189]?h[189]:1;
    next.width=(int)w;next.height=(int)height;next.iterations=(int)u32(h+12);
    next.kind=kinds[0];next.kind2=kinds[1];next.scale=scales[0];next.scale2=scales[1];
    next.min_radius=radii[0];next.min_radius2=radii[1];next.fold=folds[0];next.fold2=folds[1];
    next.power=powers[0];next.zmul=zmuls[0];next.count1=counts[0];
    next.power2=powers[1];next.zmul2=zmuls[1];next.count2=counts[1];next.repeat_from=repeat;
    next.program=legacy_program();next.program.mode=a[1]&3;next.program.render_mode=(a[2]>>1)&3;next.program.numerical_de=a[2]&1;
    next.program.repeat_from=repeat;next.program.min_iterations=u16(h+135);next.program.bailout=f64(h+92);next.program.max_iterations2=u32(h+418)?(int)u32(h+418):(int)u32(h+12);next.program.combine=a[3]&7;next.program.smooth=f32(h+378)>0?f32(h+378):.5;
    next.program.split=1;next.program.repeat2=1;
    if(next.program.mode==2){int sourceSplit=a[6]&15,sourceRepeat=a[7]&15;for(int i=0;i<used;i++){if(slots[i]>=sourceSplit){next.program.split=i;break;}}for(int i=next.program.split;i<used;i++)if(slots[i]>=sourceRepeat){next.program.repeat2=i;break;}}
    /* Keep source slot positions, including empty slots, rather than packing
       every active formula to the left. Repeat/split indices use those slots. */
    for(int i=0;i<6;i++)next.program.slots[i]=formula_slot_default(-1);
    for(int i=0;i<used;i++)next.program.slots[slots[i]]=decodedSlots[i];
    next.program.repeat_from=a[5]>>4;
    if(next.program.mode==2){next.program.split=a[6]&15;next.program.repeat2=a[7]&15;}
    next.program_enabled=1;
    next.zstart=f64(h+20);next.zend=f64(h+28);
    next.center=(Vec){f64(h+36),f64(h+44),f64(h+52)};
    next.zoom=f64(h+84);next.bailout=f64(h+92);next.fov=f64(h+108);
    next.bin_search_steps=h[134]>31?31:h[134];next.normal_zbuffer=h[331]&1;next.normal_smoothing=(u16(h+16)>>6)&15;next.optic=h[148];next.vary=h[162]!=0;next.de_stop=f32(h+177);next.ray_step=f32(h+182);
    /* Imported Stepwidth limiter is always normalized to 1.0. */
    next.raystep_limiter=1;memcpy(next.preserved_header+242,"\0\0\x80\x3f",4);
    next.julia=h[190]!=0;next.julia_c=(Vec){f64(h+191),f64(h+199),f64(h+207)};
    for(int i=0;i<3;i++)next.rotation4[i]=f64(h+60+i*8);next.julia_w=f64(h+215);
    if(next.iterations<1||next.iterations>10000)return reject_scene("iteration count must be 1–10000");
    double values[]={next.zstart,next.zend,next.center.x,next.center.y,next.center.z,next.zoom,next.bailout,
        next.fov,next.de_stop,next.ray_step,next.julia_c.x,next.julia_c.y,next.julia_c.z,next.rotation4[0],next.rotation4[1],next.rotation4[2],next.julia_w};
    for(unsigned i=0;i<sizeof values/sizeof *values;i++)if(!isfinite(values[i])||fabs(values[i])>1e15)return reject_scene("non-finite or extreme scene parameter");
    if(next.zend<=next.zstart||next.zoom<1e-12||next.zoom>1e12||next.bailout<=1||next.bailout>1e10||next.fov<.001||next.fov>=180||next.de_stop<1e-6||next.de_stop>100||next.ray_step<1e-6||next.ray_step>1)
        return reject_scene("invalid camera, bailout or ray-marching range");
    for(int i=0;i<3;i++) {
        double norm=0;for(int j=0;j<3;j++){double v=f64(h+246+(i*3+j)*8);if(!isfinite(v))return reject_scene("non-finite camera matrix");next.matrix[i][j]=v;norm+=v*v;}
        if(norm<1e-30||norm>1e30)return reject_scene("degenerate camera matrix");
        for(int j=0;j<3;j++)next.matrix[i][j]/=sqrt(norm);
    }
    for(int i=0;i<3;i++)for(int j=0;j<i;j++) {
        double d=0;for(int k=0;k<3;k++)d+=next.matrix[i][k]*next.matrix[j][k];
        if(fabs(d)>1e-5)return reject_scene("camera matrix must have orthogonal axes");
    }
    const unsigned char *l=h+432;uint32_t options=u32(l+44);
    if(((options>>20)&7)!=7)return reject_scene("legacy lighting layout; resave with current MB3D");
    next.map.number=l[3]|l[68+32+16]<<8;
    if(next.map.number) {
        next.map.mode=l[68+32+24]&3;next.map.combine=(l[7]&4)!=0;
        next.map.offset_x=((u32(l+24)>>12)&255)/256.;next.map.offset_y=((u32(l+24)>>20)&255)/256.;
        next.map.rotation=((int)((u32(l+28)>>20)&255)-128)*360./256.;
        next.map.scale=pow(next.map.mode?1.2:1.05,(int)l[68+64+16]-30);
    }
#ifndef USE_RUST_ENGINE
    if((options&(1u<<17))&&h[342]>1)warn_lighting("unsupported second color choice; using smooth-iteration coloring");
#endif
    next.color_option=h[342];next.color_multiplier=f32(h+338);if(!isfinite(next.color_multiplier))return reject_scene("invalid last length increase multiplier");
    next.cutting_colors.palette_start=options&127;next.cutting_colors.palette_end=(options>>7)&127;
    for(int i=0;i<10;i++){int k=i<4?i:3;const unsigned char *c=l+360+k*6;next.cutting_colors.stops[i].position=u16(c);for(int j=0;j<3;j++){next.cutting_colors.stops[i].diffuse[j]=c[2+j]/255.;next.cutting_colors.stops[i].specular[j]=c[5]/255.;}}
    int empty_cut_palette=1;for(int i=0;i<24;i++)if(l[360+i])empty_cut_palette=0;
    if(empty_cut_palette)next.cutting_colors=default_cutting_colors();
    next.color_on_trap=(options&(1u<<17))!=0;
    next.light_mixing=l[68+64+24];
    next.fog=fog_settings_default();next.fog.mode=(h[343]&7)!=0;next.fog.light=(int)clamp(h[343]&7,1,6);
    next.fog.map_size=(int)clamp((h[343]>>4)-2,-2,9);next.fog.iterations=h[223];
    next.fog.strength=u32(l+20);next.fog.offset=u16(l+8);next.fog.far_offset=u16(l+10);
    next.fog.blend=l[92]&1;next.fog.only_add=(l[92]>>1)&1;
    next.fog.colors[0][0]=l[55]/255.;next.fog.colors[0][1]=l[59]/255.;next.fog.colors[0][2]=l[63]/255.;
    for(int i=0;i<3;i++)next.fog.colors[1][i]=l[4+i]/255.;
    next.diffuse=u32(l+16)*.02;next.specular=fmax(.004,(u32(l+24)&4095)*.02);
    next.ambient=(u32(l+28)&4095)/90.;next.depth=u32(l+12)*.8e-6;
    next.ao_enabled=(h[149]&1)!=0;next.ao_amount=(u32(l+40)&255)/53.;
    next.shadows.ambient_auto=next.ao_enabled;next.shadows.ambient_enabled=next.ao_enabled;next.shadows.ambient_strength=next.ao_amount;
    next.diffuse_shadow=l[68+96+16]?l[68+96+16]/255.:1; /* legacy files omitted this byte; AMB1 preserves explicit zero */
    next.indirect=pow(((int8_t)l[41]+53)*.022,2);
    next.gamma=(options>>23)&63;next.cycle=(options>>14)&1;
    next.ambient_object=(options>>29)&1;next.background_function=options>>30;
    next.far_fog=(options>>18)&1;next.no_interpolation=l[68+96+24]!=0;
    next.amb_top=raw_color(l+52);next.amb_bottom=raw_color(l+56);
    next.bg_top=raw_color(l+60);next.bg_bottom=raw_color(l+64);
    double start=pow(((int32_t)u32(l+32)+30)/90.,2)*32767-10900;
    double end=pow(((int32_t)u32(l+36)+30)/90.,2)*32767-10900;
    if(options&(1u<<16)){double old=start;start=old+(end-old)*((int)l[48]-30)/60.;end=old+(end-old)*((int)l[49]-30)/60.;}
    next.cstart=start;next.cspan=end-start;
    if(fabs(next.cspan)<.001)next.cspan=next.cspan<0?-.001:.001;
    next.z_variation=(int16_t)u16(l);
    next.col_z=next.z_variation*-.005/2.1345*next.zoom;
    for(int i=0;i<6;i++) {
        const unsigned char *q=l+68+i*32;Light *out=&next.lights[i];
        out->option=q[0];out->function=q[1];out->color=raw_color(q+4);
        out->amplitude=(int8_t)q[2]*pow(10,clamp((int8_t)q[3],-25,25)-1);
        out->position=(Vec){f56(q+9),f56(q+17),f56(q+25)};
#ifndef USE_RUST_ENGINE
        if(!(q[0]&1)&&(q[0]&2))fprintf(stderr,"Warning: light map source %d is not rendered by C; settings retained\n",i+1);
        if(!(q[0]&1)&&((q[0]&24)||(q[1]&128)))fprintf(stderr,"Warning: visible source %d is not rendered by C; illumination and settings retained\n",i+1);
#endif
        out->option&=127;out->function&=183;
        if(out->option&2)out->position=(Vec){0,0,0}; /* Map records pack bytes here, not coordinates. */
        if(!isfinite(out->position.x)||!isfinite(out->position.y)||!isfinite(out->position.z)||out->amplitude<0||out->amplitude>1e10)
            return reject_scene("invalid light position or amplitude");
    }
    for(int i=0;i<10;i++) {
        const unsigned char *q=l+260+i*10;
        next.stops[i]=(Stop){u16(q),raw_color(q+2),raw_color(q+6)};
        if(i && next.stops[i].position<next.stops[i-1].position)return reject_scene("palette positions are not sorted");
    }

    next.roughness=l[2]/255.;

    /* Both engines support minimum iterations; validate its range with the formula program below. */
    next.shadows.hard_auto=next.shadows.hard_enabled=(h[133]&1)!=0;
    next.shadows.hard_mask=h[133]>>2;next.shadows.cosine=(h[133]&2)!=0;next.shadows.soft=(h[139]&1)!=0;
    double hardLength=f32(h+226),ambientLength=f32(h+374);
    if(isfinite(hardLength)&&hardLength>=.001&&hardLength<=100)next.shadows.hard_length=hardLength;
    if(isfinite(ambientLength)&&ambientLength>=.001&&ambientLength<=100)next.shadows.ambient_length=ambientLength;
    double radius=(int8_t)h[224]*pow(10,clamp((int8_t)h[225],-25,25)-1);
    if(isfinite(radius)&&radius>=.001&&radius<=100)next.shadows.hard_radius=radius;
    if(((h[149]>>2)&3)==3) {
        next.shadows.ambient_method=1;const int rays[4]={3,7,17,33};next.shadows.ambient_rays=rays[(h[149]>>4)&3];
        if(h[149]&128)warn_lighting("random first-step ambient sampling; using deterministic DE rays");
    }else if(((h[149]>>2)&3)>0){next.shadows.ambient_method=((h[149]>>2)&3)==2?3:2;}
    next.ssao=(SSAOSettings){.threshold=f32(h+319),.mirror=fmin(.9,h[127]*.01),.samples=h[187]?h[187]:1};
    if(!isfinite(next.ssao.threshold)||next.ssao.threshold<=0)next.ssao.threshold=2;
    next.reflections=default_reflections();ReflectionSettings *rf=&next.reflections;rf->automatic=rf->enabled=h[336]&1;rf->transparency=(h[336]>>1)&1;rf->only_difs=(h[336]>>2)&1;
    if(h[337]){rf->depth=h[337];rf->amount=f32(h+332);rf->absorption=f32(h+370);}if(f32(h+116)>0)rf->refractive_index=f32(h+116);if(f32(h+120)>=0)rf->scattering=f32(h+120);
    if(extra_count==4096&&!memcmp(extra+3656,"RFL1",4)){rf->enabled=u32(extra+3660);rf->automatic=u32(extra+3664);rf->transparency=u32(extra+3668);rf->only_difs=u32(extra+3672);rf->depth=u32(extra+3676);rf->amount=f64(extra+3680);rf->absorption=f64(extra+3688);rf->refractive_index=f64(extra+3696);rf->scattering=f64(extra+3704);}
    for(int c=0;c<2;c++)for(int i=0;i<10;i++)rf->opacity[c][i]=1;
    for(int i=0;i<10;i++)if(l[260+i*10+9]&248){rf->opacity_set=1;rf->opacity[1][i]=1-(l[260+i*10+9]>>3)/31.;}
    if(extra_count==4096&&!memcmp(extra+3712,"OPA1",4)){rf->opacity_set=u32(extra+3716);for(int c=0;c<2;c++)for(int i=0;i<10;i++)rf->opacity[c][i]=f64(extra+3720+(c*10+i)*8);}
    if(!valid_reflections(*rf))return reject_scene("invalid Reflections + Transparency settings");
    next.dof=(DepthOfFieldSettings){.enabled=h[181]&1,.automatic=h[181]&1,.passes=1+((h[181]>>1)&3),.focus1=f32(h+164),.focus2=f32(h+410),.aperture=f32(h+172),.clip_radius=f32(h+168)};
    if(extra_count==4096&&!memcmp(extra+3600,"DOF1",4)){
        next.dof.enabled=u32(extra+3604);next.dof.automatic=u32(extra+3608);next.dof.passes=u32(extra+3612);
        next.dof.focus1=f64(extra+3616);next.dof.focus2=f64(extra+3624);next.dof.aperture=f64(extra+3632);next.dof.clip_radius=f64(extra+3640);
    }
    if(!next.dof.enabled&&!next.dof.automatic&&next.dof.aperture==0&&next.dof.clip_radius==0)next.dof=(DepthOfFieldSettings){.passes=1,.aperture=.02,.clip_radius=25};
    if(!valid_dof(next.dof))return reject_scene("invalid Depth of Field settings");

    if(h[181]&8)warn_lighting("forward depth-of-field method; using native depth-aware filtering");

    if(extra_count>=16&&!memcmp(extra,"IPMACM3I",8)) {
        if(!((extra_count==2048&&u32(extra+8)==1&&u32(extra+12)==2048)||(extra_count==4096&&u32(extra+8)==2&&u32(extra+12)==4096)))return reject_scene("invalid native settings trailer");
        int os=(int)u32(extra+16),view=(int)u32(extra+20);
        if(os<1||os>6||view<1||view>os*10||view%os||w%(unsigned)os||height%(unsigned)os)return reject_scene("invalid saved oversampling/viewing");
        next.oversampling=os;next.viewing=view;next.size_flags=(int)u32(extra+1164);if(next.size_flags<0||next.size_flags>3)return reject_scene("invalid saved size flags");
        double *targets[]={&next.diffuse,&next.specular,&next.cstart,&next.cspan,&next.ao_amount,&next.ambient,&next.depth,&next.indirect,&next.z_variation};
        for(int i=0;i<9;i++){double v=f64(extra+24+i*8);if(!isfinite(v)||fabs(v)>1e12)return reject_scene("invalid saved lighting value");*targets[i]=v;}
        if(next.diffuse<0||next.diffuse>5||next.specular<0||next.specular>7||next.ao_amount<0||next.ao_amount>5||next.z_variation< -120||next.z_variation>360)return reject_scene("saved lighting out of range");
        next.col_z=next.z_variation*-.005/2.1345*next.zoom;
        ShadowSettings *s=&next.shadows;
        int *ints[]={&s->hard_enabled,&s->hard_mask,&s->soft,&s->cosine,&s->hard_auto,&s->ambient_auto,&s->ambient_enabled,&s->ambient_method,&s->ambient_rays,&s->ambient_steps};
        for(int i=0;i<10;i++)*ints[i]=(int)u32(extra+96+i*4);
        double *sd[]={&s->hard_length,&s->hard_radius,&s->ambient_length,&s->ambient_strength};for(int i=0;i<4;i++){*sd[i]=f64(extra+136+i*8);if(!isfinite(*sd[i])||*sd[i]<0||*sd[i]>100)return reject_scene("invalid saved shadow value");}
        if(s->hard_mask<0||s->hard_mask>63||s->ambient_method<0||s->ambient_method>3||s->ambient_rays<1||s->ambient_rays>64||s->ambient_steps<8||s->ambient_steps>512||s->ambient_strength>5)return reject_scene("invalid saved shadows");
        next.ao_enabled=s->ambient_enabled;
        for(int i=0;i<10;i++) {
            const unsigned char *q=extra+168+i*52;unsigned pos=u32(q);double c[6];
            if(pos>PALETTE_POSITION_MAX||(i&&pos<next.stops[i-1].position))return reject_scene("invalid saved palette position");
            for(int j=0;j<6;j++){c[j]=f64(q+4+j*8);if(!isfinite(c[j])||c[j]<0||c[j]>1)return reject_scene("invalid saved palette color");}
            next.stops[i]=(Stop){pos,{c[0],c[1],c[2]},{c[3],c[4],c[5]}};
        }
        for(int i=0;i<6;i++) {
            const unsigned char *q=extra+688+i*64;double d[7];for(int j=0;j<7;j++){d[j]=f64(q+8+j*8);if(!isfinite(d[j])||fabs(d[j])>1e15)return reject_scene("invalid saved light");}
            int option=(int)u32(q),function=(int)u32(q+4);
            if((option&~127)||function<0||function>183||(function&8)||d[0]<0||d[0]>1e10)return reject_scene("invalid saved light function/strength");
            for(int j=1;j<4;j++)if(d[j]<0||d[j]>1)return reject_scene("invalid saved light color");
            next.lights[i]=(Light){option,function,d[0],{d[1],d[2],d[3]},{d[4],d[5],d[6]}};
        }
        if(!memcmp(extra+1168,"MAP1",4)||!memcmp(extra+1168,"MAP2",4)) {
            ObjectMap *m=&next.map;m->disabled=!memcmp(extra+1168,"MAP2",4)?(int)u32(extra+1728):0;memcpy(m->file,extra+1172,sizeof m->file);m->file[sizeof m->file-1]=0;
            m->number=(int)u32(extra+1684);m->mode=(int)u32(extra+1688);m->combine=(int)u32(extra+1692);
            m->offset_x=f64(extra+1696);m->offset_y=f64(extra+1704);m->rotation=f64(extra+1712);m->scale=f64(extra+1720);
            if(strchr(m->file,'/')||m->disabled<0||m->disabled>1||m->mode<0||m->mode>3||m->number<0||m->number>65535||!isfinite(m->offset_x)||!isfinite(m->offset_y)||!isfinite(m->rotation)||!isfinite(m->scale)||fabs(m->offset_x)>100||fabs(m->offset_y)>100||fabs(m->rotation)>36000||m->scale<1e-12||m->scale>1e18)return reject_scene("invalid saved Object map");
        }
        if(!memcmp(extra+1736,"AMB1",4)) {
            next.diffuse_shadow=f64(extra+1740);
            double *colors[]={&next.amb_top.x,&next.amb_top.y,&next.amb_top.z,&next.amb_bottom.x,&next.amb_bottom.y,&next.amb_bottom.z,&next.bg_top.x,&next.bg_top.y,&next.bg_top.z,&next.bg_bottom.x,&next.bg_bottom.y,&next.bg_bottom.z};
            for(int i=0;i<12;i++){*colors[i]=f64(extra+1748+i*8);if(!isfinite(*colors[i])||*colors[i]<0||*colors[i]>1)return reject_scene("invalid saved ambient color");}
            if(!isfinite(next.diffuse_shadow)||next.diffuse_shadow<0||next.diffuse_shadow>1)return reject_scene("invalid saved diffuse shadowing");
        }else next.diffuse_shadow=1; /* older native versions used full direct AO */
        int *fi[]={&next.kind,&next.kind2,&next.power,&next.power2,&next.count1,&next.count2,&next.repeat_from};for(int i=0;i<7;i++)*fi[i]=(int)u32(extra+1072+i*4);
        double *fd[]={&next.zmul,&next.zmul2,&next.scale,&next.min_radius,&next.fold,&next.scale2,&next.min_radius2,&next.fold2};
        const char *fieldNames[]={"Z multiplier","Z multiplier","Scale","Min R","Fold","Scale","Min R","Fold"};
        for(int i=0;i<8;i++){*fd[i]=f64(extra+1100+i*8);int slot=(i==1||i>=5)?1:0;int kind=slot?next.kind2:next.kind;if(!isfinite(*fd[i])){return reject_formula_parameter(slot,slot?next.kind2:next.kind,fieldNames[i],*fd[i],-100,100,0);}if(!formula_generic(kind))*fd[i]=fmax(-100,fmin(100,*fd[i]));}
        next.power=fmax(2,fmin(8,next.power));next.power2=fmax(2,fmin(8,next.power2));next.count1=fmax(0,fmin(10000,next.count1));next.count2=fmax(0,fmin(10000,next.count2));
        if((!formula_supported(next.kind)&&!(next.kind==-1&&!next.count1))||(!formula_supported(next.kind2)&&!(next.kind2==-1&&!next.count2))||next.power<2||next.power>8||next.power2<2||next.power2>8||next.count1<(u32(extra+8)==2?0:1)||next.count1>10000||next.count2<0||next.count2>10000||next.repeat_from<0||next.repeat_from>(u32(extra+8)==2?7:1)||(u32(extra+8)!=2&&!next.count2&&next.repeat_from)||(!formula_generic(next.kind)&&fabs(next.min_radius)>100)||(!formula_generic(next.kind2)&&fabs(next.min_radius2)>100))return reject_scene("invalid saved formula sequence");
    }

    if(extra_count==4096&&(!memcmp(extra+1880,"FRM8",4)||!memcmp(extra+1880,"FRM6",4))) {
        FormulaProgram *p=&next.program;next.program_enabled=1;
        for(int i=0;i<6;i++){const unsigned char *q=extra+1884+i*52;p->slots[i]=(FormulaSlot){(int)u32(q),(int)u32(q+4),(int)u32(q+8),f64(q+12),f64(q+20),f64(q+28),f64(q+36),{0}};}
        int *values[]={&p->mode,&p->repeat_from,&p->min_iterations,&p->numerical_de,&p->render_mode,&p->split,&p->repeat2,&p->max_iterations2,&p->combine};for(int i=0;i<9;i++)*values[i]=(int)u32(extra+2300+i*4);
        if(!memcmp(extra+2400,"CFP1",4))for(int i=0;i<6;i++)for(int j=0;j<13;j++)p->slots[i].parameters[j]=f64(extra+2404+i*104+j*8);
        p->bailout=f64(extra+2340);p->smooth=f64(extra+2348);p->formula_power=f64(extra+2356);
    } else if(extra_count>=2048&&!memcmp(extra,"IPMACM3I",8)) {
        /* Old native files include inactive parameters in their legacy pair. */
        next.program.slots[0]=(FormulaSlot){next.kind,next.power,next.count1,next.zmul,next.scale,next.min_radius,next.fold,{0}};
        next.program.slots[1]=(FormulaSlot){next.kind2,next.power2,next.count2,next.zmul2,next.scale2,next.min_radius2,next.fold2,{0}};next.program.repeat_from=next.repeat_from;
    }
    /* Discard retired slots in legacy native files. */
    for(int i=6;i<8;i++)next.program.slots[i]=formula_slot_default(0);
    if(next.program.repeat_from>5)next.program.repeat_from=0;
    if(next.program.repeat2>5)next.program.repeat2=5;
    if(next.program.split>5)next.program.split=5;
    for(int i=0;i<8;i++){FormulaSlot *slot=&next.program.slots[i];if(slot->kind==106&&isfinite(slot->parameters[0]))slot->parameters[0]=fabs(fmod(slot->parameters[0],4));if(!validate_imported_slot(slot,i,next.program.mode==1&&i<2))return 0;}
    if(next.program.mode==1){next.program.repeat_from=0;for(int i=2;i<8;i++)next.program.slots[i].count=0;}
    const char *formulaError=program_formula_error(next.program);if(formulaError)return reject_scene(formulaError);
    if(!valid_program(next.program)||next.program.min_iterations>next.iterations)return reject_scene("invalid formula program");
    next.bailout=next.program.bailout;
    if(extra_count>=16&&!memcmp(extra,"IPMACM3I",8))next.fog=fog_settings_default();
    if(extra_count==4096&&!memcmp(extra+3880,"FOG1",4)){
        int *v[]={&next.fog.mode,&next.fog.light,&next.fog.iterations,&next.fog.blend,&next.fog.only_add,&next.fog.map_size};
        for(int i=0;i<6;i++)*v[i]=(int)u32(extra+3884+i*4);
        /* Ignore the retired experimental indirect-light flag. */
        next.fog.only_add &= FOG_ONLY_ADD;
        next.fog.strength=f64(extra+3912);next.fog.offset=f64(extra+3920);next.fog.far_offset=f64(extra+3928);
        for(int c=0;c<2;c++)for(int i=0;i<3;i++)next.fog.colors[c][i]=f64(extra+3936+(c*3+i)*8);
    }
    if(extra_count==4096&&!memcmp(extra+3984,"SSA1",4)){next.ssao.threshold=f64(extra+3992);next.ssao.mirror=f64(extra+4000);next.ssao.samples=u32(extra+4008);next.color_multiplier=f64(extra+4016);}
    if(!isfinite(next.ssao.threshold)||next.ssao.threshold<.01||next.ssao.threshold>1e6||!isfinite(next.ssao.mirror)||next.ssao.mirror<0||next.ssao.mirror>.9||next.ssao.samples<1||next.ssao.samples>255)return reject_scene("invalid SSAO settings");
    if(!isfinite(next.color_multiplier))return reject_scene("invalid last length increase multiplier");
    if(!valid_fog(next.fog))return reject_scene("invalid depth fog settings");
    scene=next;
    fprintf(stderr,"Loaded %s: format %u, %ux%u, %d total iterations\n",path,id,w,height,scene.iterations);
    fprintf(stderr,"Formula 1: %s × %.9g\n",formula_name(scene.kind),formula_iteration_value(scene.program,0));
    if(scene.count2)fprintf(stderr,"Formula 2: %s × %.9g; repeat from formula %d\n",formula_name(scene.kind2),formula_iteration_value(scene.program,1),scene.repeat_from+1);
    return 1;
}
