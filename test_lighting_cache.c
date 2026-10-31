#include <stdatomic.h>
#include "renderer.h"
static RenderCancelToken *test_cancel;
static struct {atomic_ulong evaluations,primary,normals,ambient,hard;} counts;
#define RENDER_COUNT(name) do { atomic_fetch_add_explicit(&counts.name,1,memory_order_relaxed); if(test_cancel&&atomic_load(&counts.primary)>20)render_cancel(test_cancel); } while(0)
#include "renderer.c"
#include <assert.h>
static void reset_counts(void){atomic_store(&counts.evaluations,0);atomic_store(&counts.primary,0);atomic_store(&counts.normals,0);atomic_store(&counts.ambient,0);atomic_store(&counts.hard,0);}
static void same_pixels(RenderResult a,RenderResult b){assert(a.rgba&&b.rgba&&a.width==b.width&&a.height==b.height&&!memcmp(a.rgba,b.rgba,a.stride*a.height));}
static void check_fresh(RenderResult cached,RenderOptions options){options.reuse_surface=0;RenderResult fresh=render_scene_with_options(NULL,options);same_pixels(cached,fresh);free(cached.rgba);free(fresh.rgba);}
int main(void){
    RenderResult base=render_scene(NULL,61,45,2);assert(base.rgba);RenderOptions options=base.settings;options.reuse_surface=1;options.shadows.ambient_strength=2;
    double picked[3];int hitIndex=-1,backgroundIndex=-1;
    for(int i=0;i<base.width*base.height;i++){if(surface_cache.pixels[i].hit&&hitIndex<0)hitIndex=i;if(!surface_cache.pixels[i].hit&&backgroundIndex<0)backgroundIndex=i;}
    assert(hitIndex>=0);reset_counts();int px=hitIndex%base.width,py=hitIndex/base.width;
    assert(render_pick_surface((px+.5)/base.width,(py+.5)/base.height,picked));
    SurfacePixel *surface=&surface_cache.pixels[hitIndex];Vec expected=add(surface->point,mul(surface->normal,fmax(surface->eps*4,1e-9)));
    assert(picked[0]==expected.x&&picked[1]==expected.y&&picked[2]==expected.z&&!atomic_load(&counts.evaluations));
    assert(!render_pick_surface(-.1,.5,picked)&&!render_pick_surface(1,.5,picked));
    if(backgroundIndex>=0)assert(!render_pick_surface((backgroundIndex%base.width+.5)/base.width,(backgroundIndex/base.width+.5)/base.height,picked));
    puts("Surface picking returns the clicked world position with an outward offset; background is rejected without fractal evaluation.");
    reset_counts();RenderResult strength=render_scene_with_options(NULL,options);assert(strength.rgba&&strength.reused_surface&&strength.reused_ambient);assert(!atomic_load(&counts.evaluations)&&!atomic_load(&counts.primary)&&!atomic_load(&counts.normals));check_fresh(strength,options);free(base.rgba);
    options.shadows.ambient_method=1;options.shadows.hard_enabled=1;options.reuse_surface=0;
    base=render_scene_with_options(NULL,options);assert(base.rgba);free(base.rgba);options.reuse_surface=1;
    reset_counts();options.shadows.ambient_strength=1.75;strength=render_scene_with_options(NULL,options);assert(strength.reused_surface&&strength.reused_ambient&&strength.reused_hard_shadows);assert(!atomic_load(&counts.evaluations)&&!atomic_load(&counts.primary)&&!atomic_load(&counts.normals)&&!atomic_load(&counts.ambient)&&!atomic_load(&counts.hard));check_fresh(strength,options);
    for(int i=0;i<4;i++){
        if(i==0)options.shadows.ambient_length=.7;else if(i==1)options.shadows.ambient_rays=17;else if(i==2)options.shadows.ambient_steps=128;else options.shadows.ambient_method=0;
        reset_counts();RenderResult update=render_scene_with_options(NULL,options);assert(update.rgba&&update.reused_surface&&!update.reused_ambient&&update.reused_hard_shadows);assert(atomic_load(&counts.evaluations)>0&&!atomic_load(&counts.primary)&&!atomic_load(&counts.normals)&&!atomic_load(&counts.hard));check_fresh(update,options);
    }
    options.shadows.ambient_enabled=0;reset_counts();RenderResult off=render_scene_with_options(NULL,options);assert(off.reused_surface&&!atomic_load(&counts.evaluations));free(off.rgba);options.shadows.ambient_enabled=1;RenderResult on=render_scene_with_options(NULL,options);assert(on.reused_surface&&on.reused_ambient);check_fresh(on,options);
    for(int i=0;i<4;i++){
        if(i==0)options.shadows.hard_length=.7;else if(i==1)options.shadows.hard_radius=2.25;else if(i==2)options.shadows.soft=!options.shadows.soft;else options.shadows.hard_mask=3;
        reset_counts();RenderResult update=render_scene_with_options(NULL,options);assert(update.rgba&&update.reused_surface&&update.reused_ambient&&!update.reused_hard_shadows);assert(atomic_load(&counts.hard)>0&&!atomic_load(&counts.primary)&&!atomic_load(&counts.normals)&&!atomic_load(&counts.ambient));check_fresh(update,options);
    }
    options.lights[0].position[0]+=.2;reset_counts();RenderResult light=render_scene_with_options(NULL,options);assert(light.reused_surface&&light.reused_ambient&&!light.reused_hard_shadows&&atomic_load(&counts.hard)>0&&!atomic_load(&counts.primary)&&!atomic_load(&counts.normals));check_fresh(light,options);
    RenderOptions stable=options;
    for(int i=0;i<10;i++){
        RenderOptions changed=stable;
        if(i==0)changed.iterations+=1;else if(i==1)changed.de_stop*=.8;else if(i==2)changed.width+=1;else if(i==3){changed.camera_override=1;camera_move(&changed.camera,.1,0,0);}else if(i==4)changed.program.slots[0].power=3;else if(i==5){changed.normals_override=1;changed.normal_smoothing=1;}else if(i==6){changed.julia_override=1;changed.julia=1;changed.julia_c[0]=.2;}else if(i==7)changed.ray_step*=.9;else if(i==8){changed.oversampling=2;changed.viewing=2;changed.width*=2;changed.height*=2;changed.de_stop*=2;}else{changed.normals_override=1;changed.normal_zbuffer=1;}
        reset_counts();RenderResult geometry=render_scene_with_options(NULL,changed);assert(geometry.rgba&&!geometry.reused_surface&&atomic_load(&counts.primary)>0);free(geometry.rgba);
        stable.reuse_surface=0;RenderResult restore=render_scene_with_options(NULL,stable);assert(restore.rgba);free(restore.rgba);stable.reuse_surface=1;
    }
    options=stable;options.normals_override=1;options.normal_zbuffer=1;options.normal_smoothing=1;options.reuse_surface=0;base=render_scene_with_options(NULL,options);assert(base.rgba);free(base.rgba);options.reuse_surface=1;options.shadows.ambient_strength=.8;reset_counts();RenderResult depth=render_scene_with_options(NULL,options);assert(depth.reused_surface&&depth.reused_ambient&&!atomic_load(&counts.evaluations));check_fresh(depth,options);
    options.ambient.roughness=.6;reset_counts();RenderResult rough=render_scene_with_options(NULL,options);assert(rough.reused_surface&&rough.reused_ambient&&!atomic_load(&counts.evaluations));check_fresh(rough,options);
    char path[]="/tmp/mandelbulb-cached-save-XXXXXX";int fd=mkstemp(path);assert(fd>=0);close(fd);RenderResult saved=render_scene_to_m3i(NULL,options,path);assert(saved.rgba&&saved.reused_surface&&saved.reused_ambient);RenderResult loaded=render_scene(path,0,0,2);same_pixels(saved,loaded);free(saved.rgba);free(loaded.rgba);unlink(path);
    options.reuse_surface=0;RenderResult mainFrame=render_scene_with_options(NULL,options);assert(mainFrame.rgba);free(mainFrame.rgba);options.reuse_surface=1;
    for(int stage=0;stage<3;stage++){
        RenderOptions nav=options;nav.preview_cache=1;nav.width=24+stage*4;nav.height=18+stage*3;
        RenderResult preview=render_scene_with_options(NULL,nav);assert(preview.rgba);free(preview.rgba);
        reset_counts();RenderResult relight=render_scene_with_options(NULL,options);
        assert(relight.rgba&&relight.reused_surface&&relight.reused_ambient&&relight.reused_hard_shadows&&!atomic_load(&counts.primary)&&!atomic_load(&counts.normals)&&!atomic_load(&counts.evaluations));free(relight.rgba);
    }
    RenderCancelToken *navToken=render_cancel_create();RenderOptions nav=options;nav.preview_cache=1;nav.reuse_surface=0;nav.cancel_token=navToken;nav.threads=1;
    reset_counts();test_cancel=navToken;RenderResult interrupted=render_scene_with_options(NULL,nav);test_cancel=NULL;assert(interrupted.cancelled&&!interrupted.rgba);render_cancel_destroy(navToken);
    reset_counts();RenderResult afterNav=render_scene_with_options(NULL,options);assert(afterNav.rgba&&afterNav.reused_surface&&afterNav.reused_ambient&&!atomic_load(&counts.evaluations));free(afterNav.rgba);
    puts("Navigator refinement and cancellation preserve main-image geometry, normals and shadow caches.");
    RenderCancelToken *token=render_cancel_create();assert(token);options.cancel_token=token;options.reuse_surface=0;options.threads=1;
    render_cancel(token);RenderResult cancelled=render_scene_with_options(NULL,options);assert(cancelled.cancelled&&!cancelled.rgba&&!cancelled.error[0]);render_cancel_destroy(token);
    token=render_cancel_create();options.cancel_token=token;reset_counts();test_cancel=token;
    cancelled=render_scene_with_options(NULL,options);test_cancel=NULL;assert(cancelled.cancelled&&!cancelled.rgba&&!surface_cache.pixels);render_cancel_destroy(token);
    options.cancel_token=NULL;options.reuse_surface=1;RenderResult recovered=render_scene_with_options(NULL,options);assert(recovered.rgba&&!recovered.reused_surface);free(recovered.rgba);
    char cancelledPath[]="/tmp/mandelbulb-stopped-save-XXXXXX";int stoppedFd=mkstemp(cancelledPath);assert(stoppedFd>=0);assert(write(stoppedFd,"original",8)==8);close(stoppedFd);
    RenderCancelToken *stoppedToken=render_cancel_create();render_cancel(stoppedToken);RenderOptions stoppedOptions=options;stoppedOptions.cancel_token=stoppedToken;
    RenderResult stoppedSave=render_scene_to_m3i(NULL,stoppedOptions,cancelledPath);assert(stoppedSave.cancelled&&!stoppedSave.rgba);render_cancel_destroy(stoppedToken);
    char original[8];stoppedFd=open(cancelledPath,O_RDONLY);assert(read(stoppedFd,original,8)==8&&!memcmp(original,"original",8));close(stoppedFd);unlink(cancelledPath);
    RenderOptions positional=options;positional.lights_override=1;positional.reuse_surface=0;
    for(int light=0;light<6;light++)positional.lights[light].option=1;
    RenderResult unlit=render_scene_with_options(NULL,positional);assert(unlit.rgba);
    for(int light=0;light<6;light++){
        positional.lights[light].option=4;positional.lights[light].amplitude=1;
        for(int axis=0;axis<3;axis++){positional.lights[light].position[axis]=positional.camera.origin[axis];positional.lights[light].color[axis]=1;}
        RenderResult lit=render_scene_with_options(NULL,positional);assert(lit.rgba&&memcmp(unlit.rgba,lit.rgba,lit.stride*lit.height));free(lit.rgba);
        if(light<5)positional.lights[light].option=1;
    }
    free(unlit.rgba);
    char lightPath[]="/tmp/mandelbulb-positional-XXXXXX";int lightFd=mkstemp(lightPath);assert(lightFd>=0);close(lightFd);
    RenderResult positionalSaved=render_scene_to_m3i(NULL,positional,lightPath);assert(positionalSaved.rgba);
    RenderResult positionalLoaded=render_scene(lightPath,0,0,2);same_pixels(positionalSaved,positionalLoaded);assert(positionalLoaded.settings.lights[5].option&4);
    free(positionalSaved.rgba);free(positionalLoaded.rgba);unlink(lightPath);
    puts("All six positional light sources affect rendering; positional coordinates and pixels survive .m3i save/reload.");
    RenderOptions dofOptions=options;dofOptions.reuse_surface=0;dofOptions.dof_override=1;dofOptions.dof=(DepthOfFieldSettings){.passes=1,.aperture=1,.clip_radius=5};
    RenderResult sharp=render_scene_with_options(NULL,dofOptions);assert(sharp.rgba);dofOptions.reuse_surface=1;dofOptions.dof.enabled=1;
    unsigned char *capturedSharp=NULL;reset_counts();RenderResult blurred=render_scene_capturing_sharp(NULL,dofOptions,NULL,&capturedSharp);assert(capturedSharp&&!memcmp(capturedSharp,sharp.rgba,sharp.stride*sharp.height));free(capturedSharp);assert(blurred.rgba&&blurred.reused_surface&&blurred.reused_ambient&&blurred.reused_hard_shadows&&!atomic_load(&counts.evaluations)&&!atomic_load(&counts.primary)&&!atomic_load(&counts.normals));assert(memcmp(sharp.rgba,blurred.rgba,sharp.stride*sharp.height));
    RenderResult again=render_scene_with_options(NULL,dofOptions);same_pixels(blurred,again);free(again.rgba);
    dofOptions.dof.enabled=0;RenderResult reset=render_scene_with_options(NULL,dofOptions);same_pixels(sharp,reset);free(reset.rgba);free(sharp.rgba);free(blurred.rgba);
    DepthOfFieldSettings band={.passes=1,.aperture=1,.clip_radius=25,.focus1=1,.focus2=3};
    for(int n=0;n<5;n++)assert(dof_blur_radius((1+n*.5)*2.1345,480,360,1,30,band)<1e-10);
    assert(dof_blur_radius(0,480,360,1,30,band)>0&&dof_blur_radius(10*2.1345,480,360,1,30,band)>0);
    int focusPixel=-1;for(int i=0;i<dofOptions.width*dofOptions.height;i++)if(surface_cache.pixels[i].hit){focusPixel=i;break;}assert(focusPixel>=0);double focus;
    assert(render_pick_focus((focusPixel%dofOptions.width+.5)/dofOptions.width,(focusPixel/dofOptions.width+.5)/dofOptions.height,&focus));assert(fabs(focus-surface_cache.pixels[focusPixel].depth*surface_cache.geometry.zoom/2.1345)<1e-12);
    dofOptions.dof=(DepthOfFieldSettings){.enabled=1,.automatic=1,.passes=3,.aperture=.7123456789123,.clip_radius=5,.focus1=.123456789123,.focus2=.234567891234};
    char dofPath[]="/tmp/mandelbulb-dof-XXXXXX";int dofFd=mkstemp(dofPath);assert(dofFd>=0);close(dofFd);
    RenderResult dofSaved=render_scene_to_m3i(NULL,dofOptions,dofPath);assert(dofSaved.rgba);RenderResult dofLoaded=render_scene(dofPath,0,0,2);same_pixels(dofSaved,dofLoaded);assert(dofLoaded.settings.dof.focus1==dofOptions.dof.focus1&&dofLoaded.settings.dof.passes==3&&dofLoaded.settings.dof.automatic);
    assert(!truncate(dofPath,840+dofOptions.width*dofOptions.height*18+1136));RenderOptions standardDof;char dofError[512];assert(read_scene_settings(dofPath,&standardDof,dofError));assert(standardDof.dof.enabled&&standardDof.dof.passes==3&&standardDof.dof.aperture==(double)(float)dofOptions.dof.aperture);
    free(dofSaved.rgba);free(dofLoaded.rgba);unlink(dofPath);
    puts("Depth of Field reuses cached geometry/shadows with zero fractal evaluations, preserves the sharp band, never accumulates, resets exactly, picks normalized focus and round-trips native/standard settings.");
    char parametersPath[]="/tmp/mandelbulb-parameters-XXXXXX";int parametersFd=mkstemp(parametersPath);assert(parametersFd>=0);close(parametersFd);unlink(parametersPath);char parametersError[512];SurfacePixel *retained=surface_cache.pixels;
    reset_counts();assert(write_scene_parameters(NULL,dofOptions,parametersPath,parametersError));assert(!atomic_load(&counts.evaluations)&&surface_cache.pixels==retained);
    RenderOptions parameterSettings;assert(read_scene_settings(parametersPath,&parameterSettings,parametersError)&&parameterSettings.width==dofOptions.width&&parameterSettings.dof.focus1==dofOptions.dof.focus1);unlink(parametersPath);
    unsigned char previewPixels[16*16*4];for(int i=0;i<16*16;i++){previewPixels[4*i]=17;previewPixels[4*i+1]=83;previewPixels[4*i+2]=241;previewPixels[4*i+3]=255;}
    reset_counts();assert(write_scene_parameters_with_preview(NULL,dofOptions,parametersPath,previewPixels,16,16,64,parametersError));assert(!atomic_load(&counts.evaluations)&&surface_cache.pixels==retained);
    assert(read_scene_settings(parametersPath,&parameterSettings,parametersError)&&parameterSettings.dof.focus1==dofOptions.dof.focus1);
    FILE *previewFile=fopen(parametersPath,"rb");assert(previewFile);off_t imageOffset=840+(off_t)dofOptions.width*dofOptions.height*18+1136;assert(!fseeko(previewFile,imageOffset+(off_t)(dofOptions.height/2)*dofOptions.width*4+(dofOptions.width/2)*4,SEEK_SET));unsigned char previewCenter[4];assert(fread(previewCenter,1,4,previewFile)==4&&previewCenter[0]==241&&previewCenter[1]==83&&previewCenter[2]==17&&previewCenter[3]==255);assert(!fseeko(previewFile,imageOffset+(off_t)dofOptions.width*dofOptions.height*4,SEEK_SET));char trailerMagic[8];assert(fread(trailerMagic,1,8,previewFile)==8&&!memcmp(trailerMagic,"IPMACM3I",8));fclose(previewFile);unlink(parametersPath);
    puts("M3I preview saving uses original BGRA pixel order and preserves native settings, without any fractal evaluations.");
    puts("Parameter-only snapshots serialize current settings without evaluating fractals or evicting cached geometry.");
    puts("Stopped .m3i saves retain the existing destination file.");
    puts("Cancellation stops active rendering, discards incomplete cache data, and allows a clean next render.");
    puts("Strength relights with zero fractal evaluations; AO edits reuse geometry, normals and hard shadows; cached/fresh pixels match, including depth normals.");
    puts("Camera, formula, iterations, DE stop, dimensions and normal quality invalidate the surface cache; light movement only invalidates hard shadows.");
}
