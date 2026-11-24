/* Native parameter/camera helpers remain C; pixels and post-processing are
 * produced only by the local Rust engine. Never silently fall back to C. */
static char rust_assets[4096]="rust-assets/M3Formulas";
void render_set_rust_assets(const char *path){if(path)snprintf(rust_assets,sizeof rust_assets,"%s",path);}
static int rust_cancel(void *context){RenderCancelToken *t=context;return t&&atomic_load_explicit(&t->cancelled,memory_order_relaxed);}
/* Negative done values name a stage (-(index+1)) and reset its progress. */
static void rust_progress(void *context,int done,int total){RenderCancelToken *t=context;if(t){if(done<0){atomic_store(&t->total,0);atomic_store(&t->rows,0);atomic_store(&t->stage,-done-1);return;}atomic_store(&t->rows,done);atomic_store(&t->total,total);}}
static RenderResult render_with_rust(const char *input,RenderOptions options){
    struct timespec profile_start;clock_gettime(CLOCK_MONOTONIC,&profile_start);
    RenderResult result={0};
    if(options.program_override&&(options.program.slots[6].count||options.program.slots[7].count)){
        snprintf(result.error,sizeof result.error,"Mandelbulb3Dr uses six formula slots. Slots 7 and 8 are no longer supported.");return result;
    }
    scene_parameters_only=1;result=render_scene_with_options_c(input,options);scene_parameters_only=0;
    if(result.error[0]||result.cancelled)return result;
    if(result.settings.program.slots[6].count||result.settings.program.slots[7].count){snprintf(result.error,sizeof result.error,"This scene uses formula slots 7 or 8; Mandelbulb3Dr supports six slots.");return result;}
    char snapshot[4096];int fd=render_create_temporary(snapshot,"mandelbulb3dr-scene-XXXXXX.m3p",4);
    if(fd<0){snprintf(result.error,sizeof result.error,"Cannot create Rust scene snapshot");return result;}close(fd);unlink(snapshot);
    if(!write_scene_parameters(input,result.settings,snapshot,result.error))return result;
    /* Standard flags encode automatic calculation. Pass the effective enabled
       state for this render, including manual Calculate now and previews. */
    fd=open(snapshot,O_RDWR);unsigned char header[840];int ready=fd>=0&&pread(fd,header,sizeof header,0)==sizeof header;
    if(ready){if(!result.settings.preserved_header_valid||(!header[344]&&!header[345])){header[344]=1;header[345]=2;}header[181]=(header[181]&~1)|!!result.settings.dof.enabled;header[336]=(header[336]&~1)|!!result.settings.reflections.enabled;
        if(result.settings.reflections.opacity_set)for(int i=0;i<10;i++)header[432+260+i*10+9]=(unsigned char)lround((1-clamp(result.settings.reflections.opacity[1][i],0,1))*255);
        /* The engine consumes a compact .m3p handoff, avoiding a multi-GB
           sparse image allocation when the requested resolution is large. */
        unsigned char addon[1136];off_t addonOffset=840+(off_t)result.settings.width*result.settings.height*18;
        ready=pread(fd,addon,sizeof addon,addonOffset)==sizeof addon&&pwrite(fd,header,sizeof header,0)==sizeof header&&pwrite(fd,addon,sizeof addon,840)==sizeof addon&&ftruncate(fd,1976)==0;}
    if(ready&&getenv("MB3DX_HANDOFF_DUMP")){int dump=open(getenv("MB3DX_HANDOFF_DUMP"),O_WRONLY|O_CREAT|O_TRUNC,0600);unsigned char bytes[1976];if(dump>=0){if(pread(fd,bytes,sizeof bytes,0)==sizeof bytes){ssize_t written=write(dump,bytes,sizeof bytes);(void)written;}close(dump);}}
    if(fd>=0)close(fd);if(!ready){unlink(snapshot);snprintf(result.error,sizeof result.error,"Cannot encode Rust scene snapshot");return result;}
    result.width=result.settings.width;result.height=result.settings.height;result.stride=(size_t)result.width*4;
    result.rgba=malloc(result.stride*result.height);unsigned char *sharp=NULL;
    if(sharp_capture&&result.settings.dof.enabled)sharp=malloc(result.stride*result.height);
    if(!result.rgba||(sharp_capture&&result.settings.dof.enabled&&!sharp)){free(result.rgba);free(sharp);result.rgba=NULL;unlink(snapshot);snprintf(result.error,sizeof result.error,"Not enough memory for Rust render");return result;}
    struct timespec profile_engine;clock_gettime(CLOCK_MONOTONIC,&profile_engine);
    if(getenv("MB3DX_PROFILE"))fprintf(stderr,"Rust handoff preparation: %.4fs\n",profile_engine.tv_sec-profile_start.tv_sec+(profile_engine.tv_nsec-profile_start.tv_nsec)*1e-9);
    double emissionOpacity[10];for(int i=0;i<10;i++)emissionOpacity[i]=result.settings.reflections.opacity_set?result.settings.reflections.opacity[0][i]:1;
    int ok=mb3dx_rust_render(snapshot,rust_assets,options.threads,options.preview_cache,options.reuse_surface,result.settings.object.map.scale,result.settings.fog.mode==2?result.settings.fog.colors[0]:NULL,emissionOpacity,result.settings.transmission_blur,result.settings.translucency_glow,result.settings.translucency_mode==2,!!result.settings.subsurface_scattering,result.settings.subsurface_amount,options.cancel_token,rust_cancel,rust_progress,result.rgba,sharp,&result.local_distance,result.error,&result.statistics);unlink(snapshot);
    result.cancelled=rust_cancel(options.cancel_token);
    if(!ok||result.cancelled){free(result.rgba);free(sharp);result.rgba=NULL;if(result.cancelled)result.error[0]=0;return result;}
    result.reused_surface=(ok&2)!=0;result.transmission_cached=(ok&4)!=0;double info_elapsed=info_clock()-(profile_start.tv_sec+profile_start.tv_nsec*1e-9);result.statistics.seconds[7]+=fmax(0,info_elapsed-result.statistics.elapsed);result.statistics.elapsed=info_elapsed;
    if(!options.preview_cache){result.color_fit_valid=mb3dx_rust_color_fit(&result.color_fit[0][0]);mb3dx_rust_color_histogram(&result.color_histogram[0][0]);}
    if(sharp_capture)*sharp_capture=sharp;
    fprintf(stderr,"Rendered with the local Rust engine: %dx%d\n",result.width,result.height);return result;
}
