/* Original .m3l: the 408-byte TLightingParas9 block, without scene geometry. */
#include <fcntl.h>
#include <unistd.h>
static NSData *lightingFileScene(NSString *source,RenderOptions options,NSString **message){
    char temporary[4096],error[512];int fd=render_create_temporary(temporary,"mb3dx-lighting-XXXXXX.m3p",4);if(fd<0){if(message)*message=@"Cannot create temporary lighting parameters.";return nil;}close(fd);unlink(temporary);
    if(!write_scene_parameters(source.fileSystemRepresentation,options,temporary,error)){if(message)*message=[NSString stringWithUTF8String:error];return nil;}
    fd=open(temporary,O_RDONLY);unsigned char header[840],addon[1136];BOOL ok=fd>=0&&pread(fd,header,840,0)==840;uint32_t w=0,h=0;if(ok){memcpy(&w,header+4,4);memcpy(&h,header+8,4);w=CFSwapInt32LittleToHost(w);h=CFSwapInt32LittleToHost(h);ok=pread(fd,addon,1136,840+(off_t)w*h*18)==1136;}if(fd>=0)close(fd);unlink(temporary);
    if(!ok){if(message)*message=@"Could not encode lighting parameters.";return nil;}NSMutableData *data=[NSMutableData dataWithBytes:header length:840];[data appendBytes:addon length:1136];return data;
}
static BOOL lightingFileWrite(NSString *source,RenderOptions options,NSString *path,NSString **message){
    NSData *scene=lightingFileScene(source,options,message);if(!scene)return NO;NSError *error=nil;BOOL ok=[[scene subdataWithRange:NSMakeRange(432,408)]writeToFile:path options:NSDataWritingAtomic error:&error];if(!ok&&message)*message=error.localizedDescription;return ok;
}
static BOOL lightingFileReadKeepingLights(NSString *path,NSString *source,RenderOptions base,BOOL keepLights,RenderOptions *result,NSString **message){
    NSError *failure=nil;NSData *light=[NSData dataWithContentsOfFile:path options:0 error:&failure];if(!light){if(message)*message=failure.localizedDescription;return NO;}
    if(light.length!=408){if(message)*message=@"Expected an original .m3l lighting file with 408 bytes. Older lighting-file layouts are not supported.";return NO;}
    NSMutableData *scene=[lightingFileScene(source,base,message) mutableCopy];if(!scene)return NO;NSData *current=[scene copy];[scene replaceBytesInRange:NSMakeRange(432,408) withBytes:light.bytes];unsigned char *bytes=scene.mutableBytes;
    for(int i=0;i<6;i++){unsigned char *q=bytes+432+68+i*32;
        if(keepLights){const unsigned char *old=(const unsigned char *)current.bytes+432+68+i*32;memcpy(q,old,16);memcpy(q+17,old+17,7);memcpy(q+25,old+25,7);}
        else if(*q&4)*q|=1;
    }
    char temporary[4096],error[512];int fd=render_create_temporary(temporary,"mb3dx-light-import-XXXXXX.m3p",4);if(fd<0){if(message)*message=@"Cannot create temporary lighting import.";return NO;}close(fd);BOOL ok=[scene writeToFile:[NSString stringWithUTF8String:temporary] options:0 error:&failure];RenderOptions loaded={0};if(ok)ok=read_scene_settings(temporary,&loaded,error);unlink(temporary);
    if(!ok){if(message)*message=failure?failure.localizedDescription:[NSString stringWithUTF8String:error];return NO;}
    *result=base;result->object_override=result->lights_override=result->ambient_override=result->gamma_override=1;result->cutting_colors=loaded.cutting_colors;result->cutting_colors_override=1;result->object=loaded.object;result->ambient=loaded.ambient;result->gamma=loaded.gamma;memcpy(result->lights,loaded.lights,sizeof result->lights);
    result->shadows_override=1;result->shadows.ambient_strength=loaded.shadows.ambient_strength;
    result->fog_override=1;result->fog.strength=loaded.fog.strength;result->fog.offset=loaded.fog.offset;result->fog.far_offset=loaded.fog.far_offset;result->fog.blend=loaded.fog.blend;result->fog.only_add=loaded.fog.only_add;memcpy(result->fog.colors,loaded.fog.colors,sizeof result->fog.colors);
    result->reflections.opacity_set=loaded.reflections.opacity_set;memcpy(result->reflections.opacity,loaded.reflections.opacity,sizeof result->reflections.opacity);
    if(keepLights)memcpy(result->lights,base.lights,sizeof result->lights);
    result->preserved_header_valid=1;memcpy(result->preserved_header,bytes,840);return YES;
}
static BOOL lightingFileRead(NSString *path,NSString *source,RenderOptions base,RenderOptions *result,NSString **message){return lightingFileReadKeepingLights(path,source,base,NO,result,message);}
/* Exact lighting-only history; camera, geometry and transport settings stay current. */
static RenderOptions lightingHistoryState(RenderOptions source){
    RenderOptions r={0};r.cutting_colors=source.cutting_colors;r.cutting_colors_override=1;r.object=source.object;r.ambient=source.ambient;memcpy(r.lights,source.lights,sizeof r.lights);r.gamma=source.gamma_override?source.gamma:32;r.fog=source.fog;r.color_option=source.color_option;r.color_multiplier=source.color_multiplier;r.shadows.ambient_strength=source.shadows.ambient_strength;r.reflections.opacity_set=source.reflections.opacity_set;memcpy(r.reflections.opacity,source.reflections.opacity,sizeof r.reflections.opacity);if(source.preserved_header_valid)memcpy(r.preserved_header+432,source.preserved_header+432,408);return r;
}
static RenderOptions lightingHistoryRestore(RenderOptions current,RenderOptions state){
    current.object_override=current.lights_override=current.ambient_override=current.gamma_override=current.fog_override=current.ssao_override=current.shadows_override=1;
    current.cutting_colors=state.cutting_colors;current.cutting_colors_override=1;current.object=state.object;current.ambient=state.ambient;memcpy(current.lights,state.lights,sizeof current.lights);current.gamma=state.gamma;current.fog=state.fog;current.color_option=state.color_option;current.color_multiplier=state.color_multiplier;current.shadows.ambient_strength=state.shadows.ambient_strength;current.reflections.opacity_set=state.reflections.opacity_set;memcpy(current.reflections.opacity,state.reflections.opacity,sizeof current.reflections.opacity);if(current.preserved_header_valid)memcpy(current.preserved_header+432,state.preserved_header+432,408);return current;
}
/* A monochrome lighting baseline; scene geometry and post-process switches stay current. */
static RenderOptions lightingNeutralSettings(RenderOptions base){
    RenderOptions r=base;r.object_override=r.ambient_override=r.lights_override=r.gamma_override=r.fog_override=r.shadows_override=r.ssao_override=1;
    r.cutting_colors_override=1;r.cutting_colors.palette_start=r.cutting_colors.palette_end=60;
    for(int i=0;i<4;i++){r.cutting_colors.stops[i].position=i*10922;for(int j=0;j<3;j++){r.cutting_colors.stops[i].diffuse[j]=.5;r.cutting_colors.stops[i].specular[j]=160/255.;}}
    r.object=(ObjectLighting){.map={.disabled=1,.scale=1,.offset_x=.5,.offset_y=.5},.diffuse=1,.specular=.5,.palette_end=32767};
    for(int i=0;i<10;i++)r.object.stops[i]=(ObjectColorStop){.position=(unsigned)lround(i*32767./9),.diffuse={.5,.5,.5},.specular={1,1,1}};
    for(int i=0;i<6;i++)r.lights[i]=(LightSettings){.option=i?1:0,.function=5,.amplitude=1,.color={1,1,1},.position={i?0:0.7853981633974483,0,0}};
    r.ambient=(AmbientLighting){.strength=.2,.diffuse_shadow=1,.colors={{1,1,1},{1,1,1},{.5,.5,.5},{.5,.5,.5}}};
    r.gamma=32;r.fog=fog_settings_default();r.color_option=0;r.color_multiplier=1;r.shadows.ambient_strength=0;
    r.reflections.opacity_set=1;for(int c=0;c<2;c++)for(int i=0;i<10;i++)r.reflections.opacity[c][i]=1;
    if(r.preserved_header_valid){unsigned char *l=r.preserved_header+432;memset(l,0,408);uint32_t bits=CFSwapInt32HostToLittle(60u|(60u<<7)|(32u<<23));memcpy(l+44,&bits,4);l[84]=8;l[50]=l[51]=l[67]=128;l[212]=40;
        for(int i=0;i<4;i++){uint16_t pos=CFSwapInt16HostToLittle(i*10922);memcpy(l+360+i*6,&pos,2);l[362+i*6]=l[363+i*6]=l[364+i*6]=128;l[365+i*6]=255;}}
    return r;
}
