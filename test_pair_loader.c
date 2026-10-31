#include "renderer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char **argv) {
    assert(argc==3);
    RenderResult loaded=render_scene(argv[1],31,17,2);
    if(!strcmp(argv[2],"reject")){assert(!loaded.rgba && loaded.error[0]);return 0;}
    if(!strcmp(argv[2],"shadows")) {
        assert(loaded.rgba);ShadowSettings s=loaded.settings.shadows;
        assert(s.hard_enabled&&s.hard_auto&&s.hard_mask==33&&s.cosine&&s.soft);
        assert(s.hard_length==2&&s.hard_radius==3&&s.ambient_enabled&&s.ambient_method==1&&s.ambient_rays==17&&s.ambient_length==.5);
        free(loaded.rgba);return 0;
    }
    int repeat=atoi(argv[2]);
    int boxFirst=!strcmp(argv[2],"box-first")||!strcmp(argv[2],"boxes"),boxSecond=!strcmp(argv[2],"box-second")||!strcmp(argv[2],"boxes");
    assert(loaded.rgba && loaded.settings.kind==(boxFirst?4:0) && loaded.settings.kind2==(boxSecond?4:0));
    if(!boxFirst)assert(loaded.settings.power==2);
    if(!boxSecond)assert(loaded.settings.power2==3);
    assert(loaded.settings.count1==1 && loaded.settings.count2==1 && loaded.settings.repeat_from==repeat);
    if(!boxFirst)assert(loaded.settings.z_multiplier==-1);
    if(!boxSecond)assert(loaded.settings.z_multiplier2==.7);
    RenderOptions expected={.width=31,.height=17,.threads=1,.formula_override=1,.power=2,.z_multiplier=-1,
        .sequence_override=1,.power2=3,.z_multiplier2=.7,.count1=1,.count2=1,.repeat_from=repeat};
    expected.kind=boxFirst?4:0;expected.kind2=boxSecond?4:0;
    expected.scale=expected.scale2=2;expected.min_radius=expected.min_radius2=.5;expected.fold=expected.fold2=1;
    RenderResult direct=render_scene_with_options(NULL,expected);
    assert(direct.rgba && !memcmp(loaded.rgba,direct.rgba,loaded.stride*loaded.height));
    free(direct.rgba);free(loaded.rgba);
}
