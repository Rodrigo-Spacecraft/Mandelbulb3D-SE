#include "renderer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
static void check_image(RenderResult r) {
    assert(r.rgba && r.width==31 && r.height==17 && r.stride==124);
    int varied=0;
    for(int y=0;y<r.height;y++)for(int x=0;x<r.width;x++) {
        const unsigned char *p=r.rgba+y*r.stride+x*4;
        assert(p[3]==255);
        if(memcmp(p,r.rgba,3))varied=1;
    }
    assert(varied);
}
int main(int argc,char **argv) {
    assert(argc==2);
    RenderCancelToken *progress=render_cancel_create();assert(progress&&render_progress_percent(progress)==0);
    RenderResult progressImage=render_scene_with_options(NULL,(RenderOptions){.width=31,.height=17,.threads=4,.cancel_token=progress});check_image(progressImage);assert(render_progress_percent(progress)==95);free(progressImage.rgba);render_cancel_destroy(progress);
    char largePath[]="/tmp/m3dx-large-XXXXXX";int largeFd=mkstemp(largePath);assert(largeFd>=0);close(largeFd);unlink(largePath);
    RenderOptions largeOptions={.width=RENDER_MAX_DIMENSION,.height=16,.threads=4,.iterations=1};
    RenderResult largeWide=render_scene_to_m3i(NULL,largeOptions,largePath);assert(largeWide.rgba&&largeWide.width==16384&&largeWide.height==16);free(largeWide.rgba);
    char largeError[512];RenderOptions largeRead;assert(read_scene_settings(largePath,&largeRead,largeError)&&largeRead.width==16384);unlink(largePath);
    largeOptions.width=16;largeOptions.height=16384;RenderResult tall=render_scene_with_options(NULL,largeOptions);assert(tall.rgba&&tall.height==16384);free(tall.rgba);
    largeOptions.width=16385;RenderResult oversized=render_scene_with_options(NULL,largeOptions);assert(!oversized.rgba&&oversized.error[0]);
    largeOptions.width=15360;largeOptions.height=11520;assert(write_scene_parameters(NULL,largeOptions,largePath,largeError));assert(read_scene_settings(largePath,&largeRead,largeError)&&largeRead.width==15360&&largeRead.height==11520);unlink(largePath);
    puts("16384-wide M3I export/import, 16384-high rendering, oversized rejection and 15360x11520 parameter round trips pass.");
    RenderResult serial=render_scene(NULL,31,17,1);check_image(serial);
    /* Odd supersampling factors share every base pixel's exact center ray.
       Surface/lighting must agree there: only extra subpixel rays may differ. */
    RenderResult baseAA=render_scene_with_options(NULL,(RenderOptions){.width=31,.height=17,.threads=1,.de_stop=.5});
    for(int n=3;n<=5;n+=2) {
        RenderResult aa=render_scene_with_options(NULL,(RenderOptions){.width=31*n,.height=17*n,.threads=2,.de_stop=.5*n,.oversampling=n,.viewing=n});
        assert(aa.rgba&&aa.width==31*n&&aa.height==17*n);
        for(int y=0;y<17;y++)for(int x=0;x<31;x++)for(int c=0;c<3;c++) {
            int a=baseAA.rgba[y*baseAA.stride+x*4+c];
            int b=aa.rgba[(y*n+n/2)*aa.stride+(x*n+n/2)*4+c];
            assert(abs(a-b)<=1);
        }
        free(aa.rgba);
    }
    free(baseAA.rgba);
    puts("Oversampling preserves surface and lighting at shared pixel-center rays.");
    RenderResult parallel=render_scene(NULL,31,17,4);check_image(parallel);
    assert(!memcmp(serial.rgba,parallel.rgba,serial.stride*serial.height));
    RenderResult loaded=render_scene(argv[1],31,17,4);check_image(loaded);
    assert(!memcmp(serial.rgba,loaded.rgba,serial.stride*serial.height));
    /* Top-down output has a dark blue top and a brighter gradient bottom. */
    assert(serial.rgba[2]>serial.rgba[0]);
    assert(serial.rgba[16*serial.stride+2]>serial.rgba[2]);
    RenderOptions options={.width=31,.height=17,.threads=2,.iterations=3,.de_stop=.1,.ray_step=.25};
    RenderResult adjusted=render_scene_with_options(argv[1],options);check_image(adjusted);
    assert(adjusted.settings.iterations==3 && adjusted.settings.threads==2);
    assert(adjusted.settings.de_stop==.1 && adjusted.settings.ray_step==.25);
    assert(memcmp(serial.rgba,adjusted.rgba,serial.stride*serial.height));
    free(adjusted.rgba);
    RenderResult restored=render_scene(NULL,31,17,1);
    assert(!memcmp(serial.rgba,restored.rgba,serial.stride*serial.height));free(restored.rgba);
    RenderOptions bad[]={ {.iterations=-1}, {.iterations=10001}, {.de_stop=NAN},
                         {.de_stop=101}, {.ray_step=1.1}, {.ray_step=-.1} };
    for(unsigned i=0;i<sizeof bad/sizeof *bad;i++) {
        RenderResult rejected=render_scene_with_options(NULL,bad[i]);
        assert(!rejected.rgba && rejected.error[0]);
    }
    RenderResult resized=render_scene_with_options(NULL,(RenderOptions){.width=40,.height=20,.threads=1});
    assert(resized.rgba && resized.width==40 && resized.height==20 && resized.stride==160);
    free(resized.rgba);
    assert(loaded.settings.formula_override==1 && loaded.settings.power==8 && loaded.settings.z_multiplier==-1);
    RenderOptions formula={.width=31,.height=17,.threads=2,.formula_override=1,.power=3,.z_multiplier=-1};
    RenderResult changedPower=render_scene_with_options(argv[1],formula);check_image(changedPower);
    assert(changedPower.settings.power==3 && changedPower.settings.z_multiplier==-1);
    assert(memcmp(serial.rgba,changedPower.rgba,serial.stride*serial.height));
    formula.z_multiplier=0;
    RenderResult zeroZ=render_scene_with_options(argv[1],formula);check_image(zeroZ);
    assert(zeroZ.settings.power==3 && zeroZ.settings.z_multiplier==0);
    assert(memcmp(zeroZ.rgba,changedPower.rgba,zeroZ.stride*zeroZ.height));
    free(changedPower.rgba);free(zeroZ.rgba);
    RenderOptions badFormula[]={ {.formula_override=1,.power=1,.z_multiplier=-1},
        {.formula_override=1,.power=9,.z_multiplier=-1},
        {.formula_override=1,.power=8,.z_multiplier=NAN},
        {.formula_override=1,.power=8,.z_multiplier=101} };
    for(unsigned i=0;i<sizeof badFormula/sizeof *badFormula;i++) {
        RenderResult rejected=render_scene_with_options(NULL,badFormula[i]);assert(!rejected.rgba && rejected.error[0]);
    }
    RenderResult original=render_scene(argv[1],31,17,1);
    assert(original.settings.power==8 && original.settings.z_multiplier==-1);
    assert(!memcmp(serial.rgba,original.rgba,serial.stride*serial.height));free(original.rgba);
    RenderOptions dual={.width=31,.height=17,.threads=2,.formula_override=1,.power=8,.z_multiplier=-1,
        .sequence_override=1,.power2=8,.z_multiplier2=-1,.count1=2,.count2=3};
    RenderResult same=render_scene_with_options(NULL,dual);check_image(same);
    assert(!memcmp(serial.rgba,same.rgba,serial.stride*serial.height));free(same.rgba);
    dual.power=2;dual.power2=3;dual.count1=1;dual.count2=1;
    RenderResult mixed=render_scene_with_options(NULL,dual);check_image(mixed);
    assert(memcmp(serial.rgba,mixed.rgba,serial.stride*serial.height));
    dual.repeat_from=1;
    RenderResult tail=render_scene_with_options(NULL,dual);check_image(tail);
    assert(memcmp(tail.rgba,mixed.rgba,serial.stride*serial.height));
    assert(tail.settings.power2==3 && tail.settings.count1==1 && tail.settings.count2==1 && tail.settings.repeat_from==1);
    free(mixed.rgba);free(tail.rgba);
    dual.power=8;dual.count2=0;dual.repeat_from=0;
    RenderResult disabled=render_scene_with_options(NULL,dual);check_image(disabled);
    assert(!memcmp(serial.rgba,disabled.rgba,serial.stride*serial.height));free(disabled.rgba);
    dual.repeat_from=1;
    RenderResult badRepeat=render_scene_with_options(NULL,dual);assert(!badRepeat.rgba && badRepeat.error[0]);
    dual.repeat_from=0;dual.count1=0;
    RenderResult badCount=render_scene_with_options(NULL,dual);assert(!badCount.rgba && badCount.error[0]);
    RenderOptions box={.width=31,.height=17,.threads=2,.formula_override=1,.kind=4,.scale=2,.min_radius=.5,.fold=1};
    RenderResult boxed=render_scene_with_options(NULL,box);check_image(boxed);
    assert(boxed.settings.kind==4 && boxed.settings.scale==2 && boxed.settings.min_radius==.5 && boxed.settings.fold==1);
    assert(memcmp(serial.rgba,boxed.rgba,serial.stride*serial.height));free(boxed.rgba);
    box.min_radius=-101;RenderResult badRadius=render_scene_with_options(NULL,box);assert(!badRadius.rgba&&badRadius.error[0]);
    box.min_radius=.5;box.fold=NAN;RenderResult badFold=render_scene_with_options(NULL,box);assert(!badFold.rgba&&badFold.error[0]);
    RenderOptions lighting=serial.settings;lighting.object_override=1;
    RenderResult unchangedLighting=render_scene_with_options(NULL,lighting);
    assert(unchangedLighting.rgba&&!memcmp(serial.rgba,unchangedLighting.rgba,serial.stride*serial.height));free(unchangedLighting.rgba);
    for(int feature=0;feature<6;feature++) {
        RenderOptions edited=lighting;
        if(feature==0)edited.object.diffuse=0;
        if(feature==1)for(int stop=0;stop<10;stop++) {
            edited.object.stops[stop].diffuse[0]=1;edited.object.stops[stop].diffuse[1]=edited.object.stops[stop].diffuse[2]=0;
        }
        if(feature==2)edited.object.palette_start+=2000;
        if(feature==3)edited.object.no_interpolation=1;
        if(feature==4)edited.object.orbit_trap=1;
        if(feature==5)edited.object.z_variation=150;
        RenderResult changed=render_scene_with_options(NULL,edited);check_image(changed);
        assert(memcmp(serial.rgba,changed.rgba,serial.stride*serial.height));free(changed.rgba);
    }
    RenderOptions badLighting=lighting;badLighting.object.stops[1].position=32767;
    RenderResult invalidStop=render_scene_with_options(NULL,badLighting);assert(!invalidStop.rgba&&invalidStop.error[0]);
    badLighting=lighting;badLighting.object.diffuse=NAN;
    RenderResult invalidDiffuse=render_scene_with_options(NULL,badLighting);assert(!invalidDiffuse.rgba&&invalidDiffuse.error[0]);
    badLighting=lighting;badLighting.object.stops[0].specular[0]=1.1;
    RenderResult invalidColor=render_scene_with_options(NULL,badLighting);assert(!invalidColor.rgba&&invalidColor.error[0]);
    assert(serial.color_fit_valid&&parallel.color_fit_valid);
    assert(!memcmp(serial.color_fit,parallel.color_fit,sizeof serial.color_fit));
    for(int c=0;c<2;c++)assert(serial.color_fit[c][0]>=0&&serial.color_fit[c][1]<=32767&&serial.color_fit[c][0]<=serial.color_fit[c][1]);
    for(int i=1;i<6;i++) {
        RenderOptions enabled=serial.settings;
        assert(enabled.lights[i].amplitude==1&&enabled.lights[i].color[0]==1);
        enabled.lights[i].option&=~1;
        RenderResult extra=render_scene_with_options(NULL,enabled);check_image(extra);
        assert(memcmp(serial.rgba,extra.rgba,serial.stride*serial.height));free(extra.rgba);
    }
    RenderOptions lights=serial.settings;
    RenderResult lightRoundtrip=render_scene_with_options(NULL,lights);check_image(lightRoundtrip);
    assert(!memcmp(serial.rgba,lightRoundtrip.rgba,serial.stride*serial.height));free(lightRoundtrip.rgba);
    for(int i=0;i<6;i++) {
        lights=serial.settings;
        for(int j=0;j<6;j++)lights.lights[j].option=1;
        RenderResult dark=render_scene_with_options(NULL,lights);check_image(dark);
        lights.lights[i]=(LightSettings){.option=0,.function=53,.amplitude=2,.color={1,1,1},.position={.3,1,0}};
        RenderResult lit=render_scene_with_options(NULL,lights);check_image(lit);
        assert(memcmp(dark.rgba,lit.rgba,dark.stride*dark.height));free(dark.rgba);free(lit.rgba);
    }
    lights.lights[5].amplitude=NAN;
    RenderResult badLight=render_scene_with_options(NULL,lights);assert(!badLight.rgba&&badLight.error[0]);
    RenderOptions shadowOptions=serial.settings;
    shadowOptions.shadows.hard_enabled=1;
    RenderResult hard=render_scene_with_options(NULL,shadowOptions);check_image(hard);
    assert(memcmp(serial.rgba,hard.rgba,serial.stride*serial.height));
    shadowOptions.threads=4;
    RenderResult hardParallel=render_scene_with_options(NULL,shadowOptions);check_image(hardParallel);
    assert(!memcmp(hard.rgba,hardParallel.rgba,hard.stride*hard.height));free(hardParallel.rgba);
    RenderOptions sixthShadow=shadowOptions;
    sixthShadow.lights[5]=sixthShadow.lights[0];sixthShadow.lights[0].option=1;sixthShadow.shadows.hard_mask=32;
    RenderResult sixthHard=render_scene_with_options(NULL,sixthShadow);check_image(sixthHard);
    assert(!memcmp(hard.rgba,sixthHard.rgba,hard.stride*hard.height));free(sixthHard.rgba);
    shadowOptions.shadows.hard_mask=0;
    RenderResult noMask=render_scene_with_options(NULL,shadowOptions);check_image(noMask);
    assert(!memcmp(serial.rgba,noMask.rgba,serial.stride*serial.height));free(noMask.rgba);
    shadowOptions.shadows.hard_mask=1;shadowOptions.shadows.soft=1;shadowOptions.shadows.hard_radius=3;
    RenderResult soft=render_scene_with_options(NULL,shadowOptions);check_image(soft);
    assert(memcmp(hard.rgba,soft.rgba,hard.stride*hard.height));free(hard.rgba);free(soft.rgba);
    shadowOptions=serial.settings;shadowOptions.shadows.ambient_method=1;
    RenderResult ambient=render_scene_with_options(NULL,shadowOptions);check_image(ambient);
    assert(memcmp(serial.rgba,ambient.rgba,serial.stride*serial.height));free(ambient.rgba);
    RenderOptions aoBlend=shadowOptions;aoBlend.ambient_override=1;aoBlend.ambient.diffuse_shadow=0;aoBlend.shadows.hard_enabled=0;
    RenderResult fullAO=render_scene_with_options(NULL,aoBlend);check_image(fullAO);aoBlend.ambient.diffuse_shadow=1;RenderResult fullAOAgain=render_scene_with_options(NULL,aoBlend);check_image(fullAOAgain);assert(!memcmp(fullAO.rgba,fullAOAgain.rgba,fullAO.stride*fullAO.height));free(fullAO.rgba);free(fullAOAgain.rgba);
    aoBlend.shadows.hard_enabled=1;aoBlend.shadows.hard_mask=1;aoBlend.ambient.diffuse_shadow=0;RenderResult hardOnlyAO=render_scene_with_options(NULL,aoBlend);check_image(hardOnlyAO);aoBlend.ambient.diffuse_shadow=1;RenderResult combinedAO=render_scene_with_options(NULL,aoBlend);check_image(combinedAO);assert(memcmp(hardOnlyAO.rgba,combinedAO.rgba,hardOnlyAO.stride*hardOnlyAO.height));free(hardOnlyAO.rgba);free(combinedAO.rgba);
    puts("Full AO applies without hard shadows; Diffuse shadow blends only lights with calculated hard shadows.");
    shadowOptions.shadows.ambient_enabled=0;
    RenderResult noAmbient=render_scene_with_options(NULL,shadowOptions);check_image(noAmbient);free(noAmbient.rgba);
    shadowOptions.shadows.ambient_rays=0;
    RenderResult badShadow=render_scene_with_options(NULL,shadowOptions);assert(!badShadow.rgba&&badShadow.error[0]);
    RenderOptions cameraOptions=serial.settings;cameraOptions.camera_override=1;
    RenderResult cameraRoundtrip=render_scene_with_options(NULL,cameraOptions);check_image(cameraRoundtrip);
    assert(!memcmp(serial.rgba,cameraRoundtrip.rgba,serial.stride*serial.height));free(cameraRoundtrip.rgba);
    assert(isfinite(cameraRoundtrip.local_distance)&&cameraRoundtrip.local_distance>0);
    RenderOptions clippedOptions=cameraOptions;clippedOptions.camera.distance=.01;
    RenderResult clipped=render_scene_with_options(NULL,clippedOptions);check_image(clipped);
    assert(memcmp(serial.rgba,clipped.rgba,serial.stride*serial.height)&&clipped.settings.camera.distance==.01);free(clipped.rgba);
    RenderOptions wideOptions=cameraOptions;wideOptions.camera.fov=45;
    RenderResult wide=render_scene_with_options(NULL,wideOptions);check_image(wide);
    assert(memcmp(serial.rgba,wide.rgba,serial.stride*serial.height)&&wide.settings.camera.fov==45);free(wide.rgba);
    camera_move(&cameraOptions.camera,.2,0,0);
    RenderResult moved=render_scene_with_options(NULL,cameraOptions);check_image(moved);
    assert(memcmp(serial.rgba,moved.rgba,serial.stride*serial.height));free(moved.rgba);
    camera_turn(&cameraOptions.camera,10,-5,3);
    RenderResult turned=render_scene_with_options(NULL,cameraOptions);check_image(turned);
    assert(turned.settings.camera_override && fabs(turned.settings.camera.origin[0]-cameraOptions.camera.origin[0])<1e-12);
    free(turned.rgba);
    cameraOptions.camera.fov=180;
    RenderResult badFOV=render_scene_with_options(NULL,cameraOptions);assert(!badFOV.rgba&&badFOV.error[0]);
    cameraOptions.camera.fov=30;cameraOptions.camera.axes[0]=NAN;
    RenderResult badAxes=render_scene_with_options(NULL,cameraOptions);assert(!badAxes.rgba&&badAxes.error[0]);
    RenderResult invalid=render_scene(NULL,1,17,4);assert(!invalid.rgba&&invalid.error[0]);
    RenderResult missing=render_scene("/nonexistent/integer-power-scene.m3i",31,17,1);
    assert(!missing.rgba&&missing.error[0]);
    for(int feature=0;feature<8;feature++) {
        RenderOptions ambience=serial.settings;ambience.ambient_override=1;
        switch(feature){case 0:ambience.ambient.strength=0;break;case 1:ambience.ambient.depth=.00015;break;case 2:ambience.ambient.second_reflection=5;break;case 3:ambience.ambient.diffuse_shadow=0;break;case 4:ambience.ambient.colors[0][0]=1;ambience.ambient.colors[0][1]=0;break;case 5:ambience.ambient.colors[2][0]=1;break;case 6:ambience.ambient.relative_to_object=1;camera_turn(&ambience.camera,20,15,5);ambience.camera_override=1;break;case 7:ambience.ambient.gradient=1;break;}
        RenderResult ar=render_scene_with_options(NULL,ambience);check_image(ar);if(feature==3)assert(!memcmp(ar.rgba,serial.rgba,serial.stride*serial.height));else assert(memcmp(ar.rgba,serial.rgba,serial.stride*serial.height));free(ar.rgba);
    }
    puts("Ambient strength, fog, reflection, shadow, colors, relative coordinates and gradients affect rendering.");
    for(int far=0;far<2;far++) {
        RenderOptions fog=serial.settings;fog.ambient_override=1;fog.ambient.far_fog=far;fog.ambient.depth=0;
        RenderResult clear=render_scene_with_options(NULL,fog);check_image(clear);
        fog.ambient.depth=240*.8e-6;RenderResult dense=render_scene_with_options(NULL,fog);check_image(dense);
        /* Both upper corners miss the fractal and must retain background RGB. */
        for(int x=0;x<31;x+=30)for(int c=0;c<4;c++)assert(clear.rgba[x*4+c]==dense.rgba[x*4+c]);
        assert(memcmp(clear.rgba,dense.rgba,clear.stride*clear.height));
        assert(dense.rgba[2]>0);free(clear.rgba);free(dense.rgba);
    }
    puts("Depth fog blends surface lighting without darkening background pixels, with far fog on or off.");
    char savePath[]="/tmp/integer-power-save-XXXXXX";int saveFD=mkstemp(savePath);assert(saveFD>=0);close(saveFD);
    RenderOptions savedOptions=serial.settings;savedOptions.camera_override=1;camera_turn(&savedOptions.camera,13,-7,2);
    savedOptions.oversampling=3;savedOptions.viewing=3;savedOptions.width=93;savedOptions.height=51;
    savedOptions.julia_override=1;savedOptions.julia=1;savedOptions.julia_c[0]=.2;savedOptions.julia_c[1]=-.3;savedOptions.julia_c[2]=.4;
    savedOptions.ambient_override=1;savedOptions.ambient.strength=1.25;savedOptions.ambient.depth=.00006;savedOptions.ambient.second_reflection=.75;savedOptions.ambient.diffuse_shadow=.123456789;savedOptions.ambient.relative_to_object=1;savedOptions.ambient.far_fog=1;savedOptions.ambient.gradient=2;
    savedOptions.ambient.colors[0][0]=.123456789;savedOptions.ambient.colors[2][1]=.333333333;
    savedOptions.object.specular=0;savedOptions.object.palette_start=12345.6789;savedOptions.object.palette_end=28000.123;
    savedOptions.object.stops[1].diffuse[0]=.123456789;savedOptions.lights[4].amplitude=.123456789;
    savedOptions.lights[4].option=0;savedOptions.shadows.hard_enabled=1;savedOptions.shadows.hard_mask=17;
    savedOptions.shadows.ambient_method=1;savedOptions.shadows.ambient_rays=13;
    RenderResult saved=render_scene_to_m3i(NULL,savedOptions,savePath);assert(saved.rgba&&saved.width==93);
    RenderResult reopened=render_scene(savePath,0,0,2);assert(reopened.rgba);
    assert(reopened.settings.oversampling==3&&reopened.settings.viewing==3&&reopened.settings.width==93);
    assert(reopened.settings.ambient.strength==1.25&&reopened.settings.ambient.depth==.00006&&reopened.settings.ambient.second_reflection==.75&&reopened.settings.ambient.diffuse_shadow==.123456789);
    assert(reopened.settings.ambient.colors[0][0]==.123456789&&reopened.settings.ambient.colors[2][1]==.333333333&&reopened.settings.ambient.relative_to_object&&reopened.settings.ambient.far_fog&&reopened.settings.ambient.gradient==2);
    assert(reopened.settings.julia==1&&reopened.settings.julia_c[0]==.2&&reopened.settings.julia_c[1]==-.3&&reopened.settings.julia_c[2]==.4);
    assert(reopened.settings.object.specular==0&&reopened.settings.object.palette_start==savedOptions.object.palette_start);
    assert(reopened.settings.lights[4].amplitude==savedOptions.lights[4].amplitude);
    assert(!memcmp(saved.rgba,reopened.rgba,saved.stride*saved.height));
    FILE *savedFile=fopen(savePath,"rb");assert(savedFile);assert(!fseek(savedFile,0,SEEK_END));assert(ftell(savedFile)==840+93*51*18+1136+4096);fclose(savedFile);
    /* Existing 2048-byte v1 native trailers remain readable. */
    FILE *legacyTrailer=fopen(savePath,"r+b");assert(legacyTrailer);long extraOffset=840+93*51*18+1136;
    assert(!fseek(legacyTrailer,extraOffset+8,SEEK_SET));unsigned char v1Header[8]={1,0,0,0,0,8,0,0};assert(fwrite(v1Header,1,8,legacyTrailer)==8);fclose(legacyTrailer);assert(!truncate(savePath,extraOffset+2048));
    RenderResult oldNative=render_scene(savePath,0,0,1);assert(oldNative.rgba);assert(!memcmp(oldNative.rgba,saved.rgba,saved.stride*saved.height));free(oldNative.rgba);
    free(saved.rgba);free(reopened.rgba);
    assert(!truncate(savePath,840+93*51*18+1136));
    RenderResult standard=render_scene(savePath,0,0,2);assert(standard.rgba&&standard.settings.width==93);free(standard.rgba);unlink(savePath);
    char mapPath[4096];snprintf(mapPath,sizeof mapPath,"%s/M3D/M3Maps/1.png",getenv("HOME"));
    if(!access(mapPath,R_OK)) {
        RenderOptions mapped=serial.settings;snprintf(mapped.object.map.file,sizeof mapped.object.map.file,"1.png");
        mapped.object.map.number=1;mapped.object.map.scale=1;mapped.object.map.offset_x=.5;mapped.object.map.offset_y=.5;
        for(int mode=0;mode<4;mode++) {
            mapped.object.map.mode=mode;
            RenderResult mr=render_scene_with_options(NULL,mapped);check_image(mr);
            assert(memcmp(mr.rgba,serial.rgba,mr.stride*mr.height));free(mr.rgba);
        }
        for(int i=0;i<4;i++) {
            const char *names[]={"1000.jpg","1012.png","1023.PNG","3000.jpg"};
            snprintf(mapPath,sizeof mapPath,"%s/M3D/M3Maps/%s",getenv("HOME"),names[i]);if(access(mapPath,R_OK))continue;
            RenderOptions highMap=serial.settings;strcpy(highMap.object.map.file,names[i]);highMap.object.map.number=atoi(names[i]);
            RenderResult hm=render_scene_with_options(NULL,highMap);check_image(hm);assert(memcmp(hm.rgba,serial.rgba,serial.stride*serial.height));free(hm.rgba);
        }
        char mapSave[]="/tmp/integer-power-map-XXXXXX";int fd=mkstemp(mapSave);assert(fd>=0);close(fd);
        mapped.object.map.combine=1;mapped.object.map.offset_x=.123456789;mapped.object.map.rotation=37.25;mapped.object.map.scale=2.3;
        RenderResult ms=render_scene_to_m3i(NULL,mapped,mapSave);check_image(ms);
        RenderResult ml=render_scene(mapSave,0,0,1);check_image(ml);
        assert(!memcmp(ms.rgba,ml.rgba,ms.stride*ms.height));
        assert(!strcmp(ml.settings.object.map.file,"1.png")&&ml.settings.object.map.mode==3&&ml.settings.object.map.combine==1);
        assert(ml.settings.object.map.offset_x==mapped.object.map.offset_x&&ml.settings.object.map.rotation==37.25&&ml.settings.object.map.scale==2.3);
        free(ms.rgba);free(ml.rgba);
        mapped.object.map.disabled=1;
        RenderResult off=render_scene_to_m3i(NULL,mapped,mapSave);check_image(off);
        assert(!memcmp(off.rgba,serial.rgba,serial.stride*serial.height));
        RenderResult offReload=render_scene(mapSave,0,0,1);check_image(offReload);
        assert(offReload.settings.object.map.disabled==1&&!strcmp(offReload.settings.object.map.file,"1.png")&&offReload.settings.object.map.number==1);
        assert(!memcmp(offReload.rgba,serial.rgba,serial.stride*serial.height));
        mapped=offReload.settings;mapped.object.map.disabled=0;
        RenderResult onAgain=render_scene_with_options(NULL,mapped);check_image(onAgain);assert(memcmp(onAgain.rgba,serial.rgba,serial.stride*serial.height));
        free(off.rgba);free(offReload.rgba);free(onAgain.rgba);unlink(mapSave);
        puts("All four Object map modes affect rendering; map settings and pixels round-trip exactly.");
    }
    RenderOptions missingMap=serial.settings;strcpy(missingMap.object.map.file,"__missing_test_map__.png");missingMap.object.map.scale=1;
    RenderResult missingTexture=render_scene_with_options(NULL,missingMap);check_image(missingTexture);
    assert(!memcmp(missingTexture.rgba,serial.rgba,serial.stride*serial.height));free(missingTexture.rgba);
    strcpy(missingMap.object.map.file,"../invalid.png");RenderResult invalidMap=render_scene_with_options(NULL,missingMap);assert(!invalidMap.rgba);
    puts("Missing maps warn and preserve palette rendering; paths outside the map folder are rejected.");
    RenderResult noSave=render_scene_to_m3i(NULL,serial.settings,"/nonexistent/render.m3i");assert(!noSave.rgba&&noSave.error[0]);
    free(serial.rgba);free(parallel.rgba);free(loaded.rgba);
    puts("Display buffer orientation, RGBA colors/alpha, .m3i loading, thread determinism, calculation/formula overrides, Object lighting edits, zero Z multiplier and validation passed.");
}
