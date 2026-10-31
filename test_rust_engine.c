#include "renderer.h"
#include "rust_engine.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
static char map_test_dir[]="/tmp/mb3dr-map-scale-XXXXXX";
static void map_test_setup(void){
    assert(mkdtemp(map_test_dir));assert(!setenv("MB3D_MAPS",map_test_dir,1));char path[512];snprintf(path,sizeof path,"%s/31001.bmp",map_test_dir);FILE *f=fopen(path,"wb");assert(f);unsigned char h[54]={0};h[0]='B';h[1]='M';unsigned v[][2]={{2,54+64*32*3},{10,54},{14,40},{18,64},{22,32},{26,1},{28,24},{34,64*32*3}};for(unsigned i=0;i<sizeof v/sizeof v[0];i++)for(int j=0;j<4;j++)h[v[i][0]+j]=(v[i][1]>>(8*j))&255;h[26]=1;h[27]=0;h[28]=24;h[29]=0;assert(fwrite(h,1,54,f)==54);for(int y=0;y<32;y++)for(int x=0;x<64;x++){unsigned char rgb[]={x*4,y*8,(x*17+y*29)&255};assert(fwrite(rgb,1,3,f)==3);}fclose(f);
}
static void check_map_scale(RenderOptions base){
    base.object_override=1;base.object.map=(ObjectMap){.number=31001,.offset_x=.5,.offset_y=.5,.scale=1};strcpy(base.object.map.file,"31001.bmp");base.reflections.enabled=0;base.reflections_override=1;base.dof.enabled=0;base.dof_override=1;base.reuse_surface=1;
    for(int mode=0;mode<4;mode++){base.object.map.mode=mode;base.object.map.scale=1;RenderResult a=render_scene_with_options(NULL,base);assert(a.rgba);base.object.map.scale=1.01;RenderResult b=render_scene_with_options(NULL,base);assert(b.rgba&&b.reused_surface&&b.settings.object.map.scale==1.01);assert(memcmp(a.rgba,b.rgba,a.stride*a.height));free(a.rgba);free(b.rgba);}
    base.shadows.hard_enabled=1;base.shadows.hard_mask=1;base.shadows.hard_length=1;base.shadows.hard_radius=1;
    RenderResult shadowed=render_scene_with_options(NULL,base);assert(shadowed.rgba);free(shadowed.rgba);base.object.map.scale=1.02;
    RenderResult repainted=render_scene_with_options(NULL,base);assert(repainted.rgba&&repainted.reused_surface&&!repainted.statistics.evaluations[3]&&!repainted.statistics.evaluations[4]);
    base.reuse_surface=0;RenderResult fresh=render_scene_with_options(NULL,base);assert(fresh.rgba&&!memcmp(fresh.rgba,repainted.rgba,fresh.stride*fresh.height));free(fresh.rgba);free(repainted.rgba);base.reuse_surface=1;
    base.object.map.mode=1;base.object.map.scale=.05;RenderResult a=render_scene_with_options(NULL,base);assert(a.rgba);base.object.map.scale=.1;RenderResult b=render_scene_with_options(NULL,base);assert(b.rgba&&memcmp(a.rgba,b.rgba,a.stride*a.height));free(a.rgba);free(b.rgba);char path[512];snprintf(path,sizeof path,"%s/31001.bmp",map_test_dir);unlink(path);rmdir(map_test_dir);
}
static void check_post_sides(RenderOptions o){
    o.width=48;o.height=36;o.threads=2;o.iterations=12;o.program_override=1;o.program.mode=0;o.program.repeat_from=0;o.program.min_iterations=1;o.program.render_mode=0;for(int i=0;i<8;i++)o.program.slots[i].count=0;
    FormulaSlot f=formula_slot_default(125);f.count=1;f.parameters[0]=1;f.parameters[1]=1;f.parameters[5]=f.parameters[6]=f.parameters[7]=1;f.parameters[10]=f.parameters[11]=1;f.parameters[12]=-1;o.program.slots[0]=f;
    o.camera_override=1;o.camera=(CameraSettings){.origin={0,0,-3},.axes={1,0,0,0,1,0,0,0,1},.zoom=1,.fov=40,.distance=6};
    o.reflections_override=o.dof_override=o.shadows_override=1;o.reflections.enabled=o.dof.enabled=0;o.shadows.hard_enabled=1;o.shadows.hard_mask=1;o.shadows.hard_length=1;o.shadows.hard_radius=1;o.shadows.ambient_enabled=1;o.shadows.ambient_method=1;o.shadows.ambient_rays=7;o.shadows.ambient_steps=64;o.shadows.ambient_length=1;
    o.reuse_surface=0;
    RenderResult outside=render_scene_with_options(NULL,o);if(!outside.rgba)fprintf(stderr,"Post-side test: %s\n",outside.error);assert(outside.rgba);o.program.render_mode=2;RenderResult both=render_scene_with_options(NULL,o);assert(both.rgba);assert(!memcmp(outside.rgba,both.rgba,outside.stride*outside.height));free(outside.rgba);free(both.rgba);
    puts("Both-sided outside hits retain the same hard shadows and DEAO as outside-only rendering.");
}
static void check_extended_palette(void){
    RenderOptions o;char error[512];assert(read_scene_settings("tests/palette-17Nov24.m3p",&o,error));assert(o.object.stops[9].position==32772);
    double scale=32.0/o.width;o.width=32;o.height=18;o.de_stop*=scale;o.camera_override=1;o.threads=2;o.shadows_override=1;o.shadows.hard_enabled=o.shadows.ambient_enabled=0;o.reflections_override=1;o.reflections.enabled=0;o.dof_override=1;o.dof.enabled=0;
    RenderResult r=render_scene_with_options(NULL,o);if(!r.rgba)fprintf(stderr,"Extended palette: %s\n",r.error);assert(r.rgba&&r.settings.object.stops[9].position==32772);free(r.rgba);
    char path[]="/tmp/mb3dr-palette-XXXXXX.m3i";int fd=mkstemps(path,4);assert(fd>=0);close(fd);unlink(path);
    for(unsigned pos=32772;pos<=65535;pos+=32763){o.object.stops[9].position=pos;assert(write_scene_parameters(NULL,o,path,error));RenderOptions saved;assert(read_scene_settings(path,&saved,error)&&saved.object.stops[9].position==pos);assert(!truncate(path,840+32*18*18+1136));assert(read_scene_settings(path,&saved,error)&&saved.object.stops[9].position==pos);unlink(path);}
    o.object.stops[9].position=65536;assert(!write_scene_parameters(NULL,o,path,error)&&strstr(error,"Palette positions"));o.object.stops[9].position=32772;o.object.stops[2].position=o.object.stops[1].position-1;assert(!write_scene_parameters(NULL,o,path,error)&&strstr(error,"Palette positions"));
    puts("Original 32772 palette endpoint renders and survives standard/native saves; full unsigned-word range is accepted and unsorted/overflow positions remain rejected.");
}
static void check_parameter_imports(void){
    char image[]="/tmp/mandelbulb3dr-import-XXXXXX.m3i",parameters[]="/tmp/mandelbulb3dr-import-XXXXXX.m3p",error[512];
    int fd=mkstemps(image,4);assert(fd>=0);close(fd);unlink(image);fd=mkstemps(parameters,4);assert(fd>=0);close(fd);
    RenderOptions o={.width=64,.height=48},loaded;
    assert(write_scene_parameters(NULL,o,image,error));
    unsigned char header[840],addon[1136];FILE *fp=fopen(image,"rb");assert(fp&&fread(header,1,sizeof header,fp)==sizeof header);assert(header[344]==1&&header[345]==2&&header[432+68+16]>=8);assert(!fseek(fp,840+64*48*18,SEEK_SET)&&fread(addon,1,sizeof addon,fp)==sizeof addon);fclose(fp);
    assert(read_scene_settings(image,&loaded,error));
    /* A parameter file need not have a rendered image (bCalc3D can be 0). */
    header[344]=0;header[345]=2;fp=fopen(parameters,"wb");assert(fp&&fwrite(header,1,sizeof header,fp)==sizeof header&&fwrite(addon,1,sizeof addon,fp)==sizeof addon);fclose(fp);
    assert(read_scene_settings(parameters,&loaded,error)&&loaded.width==64&&loaded.height==48);
    RenderResult r=render_scene_with_options(parameters,(RenderOptions){.width=32,.height=24,.threads=2});assert(r.rgba);free(r.rgba);
    /* Rust supports imported slices, stereo and cutting planes without editors. */
    for(int n=0;n<4;n++){
        header[344]=n==1?0:1;header[345]=2;header[126]=n==2;header[176]=n==3;
        fp=fopen(image,"r+b");assert(fp&&fwrite(header,1,sizeof header,fp)==sizeof header);fclose(fp);
        assert(read_scene_settings(image,&loaded,error)&&loaded.preserved_header_valid);
        assert(loaded.preserved_header[344]==header[344]&&loaded.preserved_header[126]==header[126]&&loaded.preserved_header[176]==header[176]);
    }
    assert(!truncate(parameters,840));assert(!read_scene_settings(parameters,&loaded,error)&&strstr(error,"truncated"));unlink(image);unlink(parameters);
}
int main(void){
    map_test_setup();render_set_rust_assets("rust-assets/M3Formulas");
    check_parameter_imports();
    RenderOptions o={.width=64,.height=48,.threads=2};
    /* Import normalizes the Stepwidth limiter to 1.0, including legacy
       files that stored zero or another fractional value. */
    char input[]="/tmp/mandelbulb3dr-limiter-input-XXXXXX",output[]="/tmp/mandelbulb3dr-limiter-output-XXXXXX",save_error[512];
    int input_fd=mkstemp(input),output_fd=mkstemp(output);assert(input_fd>=0&&output_fd>=0);close(input_fd);close(output_fd);unlink(input);unlink(output);
    assert(write_scene_parameters(NULL,o,input,save_error));
    FILE *fp=fopen(input,"rb");float limiter;assert(fp&&fseek(fp,242,SEEK_SET)==0&&fread(&limiter,4,1,fp)==1);fclose(fp);assert(limiter==1);
    float values[]={0,.375f,1};for(int n=0;n<3;n++){
        fp=fopen(input,"r+b");assert(fp&&fseek(fp,242,SEEK_SET)==0&&fwrite(&values[n],4,1,fp)==1);fclose(fp);
        assert(write_scene_parameters(input,o,output,save_error));fp=fopen(output,"rb");assert(fp&&fseek(fp,242,SEEK_SET)==0&&fread(&limiter,4,1,fp)==1);fclose(fp);assert(limiter==1);unlink(output);
    }unlink(input);
    RenderResult a=render_scene_with_options(NULL,o);if(!a.rgba)fprintf(stderr,"%s\n",a.error);assert(a.rgba&&a.width==64&&a.height==48);assert(a.color_fit_valid);for(int c=0;c<2;c++)assert(a.color_fit[c][0]>=0&&a.color_fit[c][0]<=a.color_fit[c][1]&&a.color_fit[c][1]<=32767);assert(a.color_fit[0][0]<a.color_fit[0][1]||a.color_fit[1][0]<a.color_fit[1][1]);
    int varied=0;for(int i=1;i<64*48;i++){assert(a.rgba[i*4+3]==255);varied|=memcmp(a.rgba,a.rgba+i*4,3)!=0;}assert(varied);
    o=a.settings;o.reuse_surface=1;RenderResult b=render_scene_with_options(NULL,o);assert(b.rgba&&b.reused_surface&&!memcmp(a.rgba,b.rgba,a.stride*a.height));assert(b.color_fit_valid&&!memcmp(a.color_fit,b.color_fit,sizeof a.color_fit));free(b.rgba);
    for(int amount=4;amount<=100;amount+=96){RenderOptions high=o;high.reflections_override=1;high.reflections.amount=amount;char path[]="/tmp/mb3dr-reflection-range-XXXXXX",error[512];int fd=mkstemp(path);assert(fd>=0);close(fd);unlink(path);assert(write_scene_parameters(NULL,high,path,error));RenderOptions imported;assert(read_scene_settings(path,&imported,error)&&imported.reflections.amount==amount);assert(!truncate(path,840+64*48*18+1136));assert(read_scene_settings(path,&imported,error)&&imported.reflections.amount==amount);unlink(path);}
    char error[512];assert(render_export_zbuffer("/tmp/mandelbulb3dr-depth.png",0,32,24,error));unlink("/tmp/mandelbulb3dr-depth.png");
    int hit=0;for(int y=0;y<48&&!hit;y++)for(int x=0;x<64&&!hit;x++){double point[3],focus;hit=render_pick_surface((x+.5)/64,(y+.5)/48,point);if(hit)assert(render_pick_focus((x+.5)/64,(y+.5)/48,&focus)&&focus>=0);}assert(hit);
    o.dof_override=1;o.dof.enabled=o.dof.automatic=1;o.dof.passes=1;o.dof.aperture=1;o.dof.clip_radius=5;
    unsigned char *sharp=NULL;RenderResult d=render_scene_capturing_sharp(NULL,o,NULL,&sharp);if(!d.rgba)fprintf(stderr,"%s\n",d.error);assert(d.rgba&&sharp&&!memcmp(sharp,a.rgba,a.stride*a.height));free(sharp);free(d.rgba);
    RenderCancelToken *token=render_cancel_create();render_cancel(token);o.cancel_token=token;RenderResult cancelled=render_scene_with_options(NULL,o);assert(cancelled.cancelled&&!cancelled.rgba);render_cancel_destroy(token);o.cancel_token=NULL;
    o.program_override=1;o.program.slots[7].count=1;RenderResult bad=render_scene_with_options(NULL,o);assert(!bad.rgba&&strstr(bad.error,"six formula"));o.program.slots[7].count=0;
    check_extended_palette();check_map_scale(a.settings);check_post_sides(a.settings);free(a.rgba);puts("Rust engine produces deterministic pixels, cached rendering, depth export, surface picking, a sharp DoF image, cancellation and explicit six-slot validation.");return 0;
}
