#ifndef INTEGER_POWER_RENDERER_H
#define INTEGER_POWER_RENDERER_H
#include <stddef.h>
#define RENDER_MAX_DIMENSION 16384
/* Creates an app scratch file in MB3DX_TEMP_DIR (or the caller temp dir). */
int render_create_temporary(char path[4096],const char *pattern,int suffix_length);
/* Include an 8192 x 8192 map (64 Mi pixels, rather than 64 million). */
#define MAP_MAX_PIXELS ((size_t)64 * 1024 * 1024)
/* File positions are unsigned words; the usual gradient display spans 0–32767. */
#define PALETTE_POSITION_MAX 65535
typedef struct {
    unsigned position;
    double diffuse[3],specular[3];
} ObjectColorStop;
typedef struct {
    char file[512]; /* filename inside the configured Maps folder; empty disables map */
    int number,mode,combine,disabled; /* modes: 0 iteration/trap, 1 normals, 2 wrap1, 3 wrap2 */
    double offset_x,offset_y,rotation,scale;
} ObjectMap;
typedef struct {
    ObjectMap map;
    double diffuse,specular,palette_start,palette_end,z_variation;
    int cycling,no_interpolation,orbit_trap;
    ObjectColorStop stops[10];
} ObjectLighting;
static inline ObjectLighting default_cutting_colors(void){
    ObjectLighting colors={0};colors.palette_start=colors.palette_end=60;
    const unsigned packed[4]={5873889,2988346,11287584,5873889};
    for(int i=0;i<10;i++){int k=i<4?i:3;colors.stops[i].position=k<3?k*10922:32700;for(int j=0;j<3;j++){colors.stops[i].diffuse[j]=((packed[k]>>(8*j))&255)/255.;colors.stops[i].specular[j]=160/255.;}}
    return colors;
}

typedef struct {
    int option,function;
    double amplitude,color[3],position[3];
} LightSettings;
typedef struct {
    int enabled,automatic,passes;
    double focus1,focus2,aperture,clip_radius;
} DepthOfFieldSettings;
typedef struct {
    int hard_enabled,hard_mask,soft,cosine,hard_auto,ambient_auto;
    double hard_length,hard_radius;
    int ambient_enabled,ambient_method,ambient_rays,ambient_steps;
    double ambient_length,ambient_strength;
} ShadowSettings;
typedef struct {
    double origin[3],axes[9],zoom,fov,distance;
    int optic;
} CameraSettings;
void camera_move(CameraSettings *camera,double right,double down,double forward);
void camera_turn(CameraSettings *camera,double yaw_degrees,double pitch_degrees,double roll_degrees);
typedef struct {
    double strength,depth,second_reflection,diffuse_shadow,roughness;
    double colors[4][3]; /* ambient top/bottom, background top/bottom */
    int relative_to_object,far_fog,gradient,light_mixing;
} AmbientLighting;
#define FORMULA_SLOTS 8 /* Six active slots plus two reserved records for legacy animation ABI. */
typedef struct {
    int kind,power,count;
    double z_multiplier,scale,min_radius,fold;
    double parameters[13]; /* Generic values 0..12; values 13..15 use legacy box fields via accessors. */
} FormulaSlot;
typedef struct {const char *name;double minimum,maximum,default_value;int integer;} FormulaParameter;
int formula_menu_count(void);
int formula_menu_kind(int index);
int formula_catalog_category(int kind);
int formula_parameter_is_angle(int kind,int index);
double formula_catalog_bailout(int kind);
const char *formula_name(int kind);
int formula_parameter_count(int kind);
const FormulaParameter *formula_parameter(int kind,int index);
FormulaSlot formula_slot_default(int kind);
double formula_slot_value(FormulaSlot slot,int index);
void formula_slot_set_value(FormulaSlot *slot,int index,double value);
typedef struct {
    FormulaSlot slots[FORMULA_SLOTS];
    int mode,repeat_from,min_iterations,numerical_de,render_mode;
    int split,repeat2,max_iterations2,combine;
    double bailout,smooth,formula_power;
} FormulaProgram;
/* MB3D uses the iteration-count word as IEEE single weights in Interpolate.
 * Keep the ABI and serialized word intact. Small integer words also support
 * older native snapshots and callers that set integer interpolation weights. */
static inline double formula_iteration_value(FormulaProgram p,int slot){
    int word=p.slots[slot].count;
    if(p.mode!=1||(word>=0&&word<=10000))return word;
    union {unsigned int word;float weight;} value={.word=(unsigned int)word};
    return value.weight;
}
static inline int formula_weight_word(double weight){
    union {float weight;unsigned int word;} value={.weight=(float)weight};
    return (int)value.word;
}

typedef struct {
    int enabled,automatic,transparency,only_difs,depth;
    double amount,absorption,refractive_index,scattering;
    int opacity_set;double opacity[2][10]; /* diffuse emission strength / specular transparency opacity */
} ReflectionSettings;
typedef struct {
    int mode,light,iterations,blend,only_add,map_size; /* modes: 0 dynamic, 1 volumetric, 2 emissive, 3 none; stable file IDs */
    double strength,offset,far_offset,colors[2][3];
} FogSettings;
enum { FOG_ONLY_ADD=1 };
static inline FogSettings fog_settings_default(void) {
    return (FogSettings){.light=1,.strength=53,.offset=128,.far_offset=128,.colors={{1,1,1},{1,1,1}}};
}
typedef struct {double threshold,mirror;int samples;} SSAOSettings;
typedef struct RenderCancelToken RenderCancelToken;
RenderCancelToken *render_cancel_create(void);
void render_cancel(RenderCancelToken *token);
void render_cancel_destroy(RenderCancelToken *token);
/* Progress for the current stage; -1 means an unknown-length pass. */
int render_progress_percent(RenderCancelToken *token);
const char *render_progress_stage(RenderCancelToken *token);
/* Serial: export cached depth as a 16-bit grayscale PNG, near white/background black. */
int render_export_zbuffer(const char *path,int preview,int width,int height,char error[512]);
typedef struct {
    RenderCancelToken *cancel_token; /* transient; caller retains until rendering completes */
    int preview_cache; /* transient: separate Navigator cache; zero keeps main image cache */
    int dof_override;DepthOfFieldSettings dof;
    int reuse_surface; /* transient: reuse matching completed geometry and shadow caches */
    int normals_override,normal_smoothing,normal_zbuffer;
    int program_override;FormulaProgram program;
    int ambient_override;AmbientLighting ambient;
    int navigation_count,navigation_operations[32];double navigation_fraction; /* transient adaptive directions 0–5; +100 = fine (1/10), never saved */
    int oversampling,viewing,size_flags; /* metadata: actual resolution is width/height; Viewing includes oversampling */
    int width,height,threads,iterations; /* 0: scene value; threads 0: automatic */
    double de_stop,ray_step;            /* 0: scene value */
    int formula_override,power;         /* override permits Z multiplier = 0 */
    double z_multiplier;
    int sequence_override,power2,count1,count2,repeat_from;
    int kind,kind2; /* MB3D built-ins: 0=Integer Power, 4=Amazing Box */
    double scale,min_radius,fold,scale2,min_radius2,fold2;
    int julia_override,julia;double julia_c[3];
    int camera_override;CameraSettings camera;
    int shadows_override;ShadowSettings shadows;
    int lights_override; LightSettings lights[6];
    int object_override;
    ObjectLighting object;
    double z_multiplier2; /* count2=0 disables slot 2; repeat_from is 0 or 1 */
    int reflections_override;ReflectionSettings reflections;
    int fog_override;FogSettings fog;
    int rotation4_override;double rotation4[3],julia_w; /* XW/YW/ZW radians */
    int ssao_override;SSAOSettings ssao;int color_option;double color_multiplier;
    double position[6]; /* X/Y/Z midpoint, Z start/end, zoom; scene metadata for Position editor */
    int retired_indirect_override,retired_indirect_enabled; /* Reserved layout padding for reading old animation projects; ignored. */
    int retired_indirect_strength_override;double retired_indirect_strength;
    int preserved_header_valid;unsigned char preserved_header[840]; /* Imported settings without native editors. */
    double gamma;int gamma_override; /* Original output gamma slider, encoded 0..63; 32 is neutral. */
    double stepcount;int stepcount_override; /* Binary-search refinements, integer 0..31; appended for animation compatibility. */
    double cutting[3];int cutting_override,cutting_mask; /* Original X/Y/Z cutting planes. */
    ObjectLighting cutting_colors;int cutting_colors_override;
} RenderOptions;
/* Work counts are actual CPU calls, not configured iteration limits.
   Field/DE phases: primary, normals, refinement, hard shadows, ambient, fog,
   reflection/transmission, other. Timings are non-overlapping wall seconds. */
typedef struct {
    unsigned long long evaluations[8], formula_calls[8];
    unsigned long long rays, steps, max_steps, capped_rays, hits;
    double seconds[8], elapsed;
    unsigned timing_mask;
    int valid, threads, gpu;
} RenderStatistics;
typedef struct {
    RenderStatistics statistics;
    unsigned char *rgba;
    int width,height;
    size_t stride;
    char error[512];
    RenderOptions settings;
    double local_distance; /* DE at the camera origin for adaptive Navigator stepping */
    int color_fit[2][2],color_fit_valid;
    unsigned color_histogram[3][256]; /* Outside iterations, orbit trap, inside. */
    int cancelled,navigation_applied;
    int reused_surface,reused_ambient,reused_hard_shadows;
} RenderResult;
/* Call serially: scene state is private to the renderer. Pixels use top-down
   RGBA8, alpha 255, and malloc ownership transferred to the caller. */
/* Convert modern Mandelbulb3D clipboard text to a validated temporary scene.
   Call serially with rendering. output must not exist; error has 512 bytes. */
int import_clipboard_scene(const char *text,const char *output,char error[512]);
/* Read parameters only, without allocating pixels or evaluating the fractal. Call serially. */
int read_scene_settings(const char *input,RenderOptions *settings,char error[512]);
RenderResult render_scene_to_m3i(const char *input,RenderOptions options,const char *output);
RenderResult render_scene(const char *input,int width,int height,int threads);
RenderResult render_scene_with_options(const char *input,RenderOptions options);
/* Serial, optional sharp-image capture before DoF; free *sharp with free().
 * output may be NULL. *sharp is NULL when no blur is applied. */
RenderResult render_scene_capturing_sharp(const char *input,RenderOptions options,const char *output,unsigned char **sharp);
/* Serial call: normalized top-left image coordinates; zero for background/no cache. */
int render_pick_surface(double x,double y,double position[3]);
int render_pick_focus(double x,double y,double *focus);
/* Serial, parameter-only snapshot: output must not exist; no fractal evaluation. */
int write_scene_parameters(const char *input,RenderOptions options,const char *output,char error[512]);
/* Parameter-only save plus optional existing RGBA8 image; no rendering. */
int write_scene_parameters_with_preview(const char *input,RenderOptions options,const char *output,const unsigned char *rgba,int width,int height,size_t stride,char error[512]);
#endif

/* Caller owns the returned parameter text. Does not render. */
int export_clipboard_scene(const char *input,RenderOptions options,char **text,char error[512]);
