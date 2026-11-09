#define main app_main_unused
#import "../App.m"
#undef main
#include <assert.h>
_Static_assert(sizeof(FogSettings)==96,"Preserve animation parameter layout");
static unsigned long brightness(RenderResult r){unsigned long n=0;for(int y=0;y<r.height;y++)for(int x=0;x<r.width;x++)for(int c=0;c<3;c++)n+=r.rgba[y*r.stride+4*x+c];return n;}
int main(int argc,char **argv){@autoreleasepool{
 assert(argc==2);[NSApplication sharedApplication];setenv("MB3DX_GPU","cpu",1);RenderOptions o;char error[512];assert(read_scene_settings(argv[1],&o,error));
 o.fog.mode=2;for(int i=0;i<10;i++)o.reflections.opacity[0][i]=o.reflections.opacity[1][i];
 AppDelegate *a=[AppDelegate new];a.formulaKnown=YES;a.formulaSettings=o;NSTabView *tabs=[NSTabView new];[a addDepthFogTab:tabs];[a populateDepthFog];
 for(NSView *v in tabs.tabViewItems.lastObject.view.subviews)if([v isKindOfClass:[NSButton class]])assert(![[(NSButton *)v title] containsString:@"Indirect"]);
 const char *file="/private/tmp/emissive-indirect-settings.m3i";
 for(int flag=0;flag<4;flag++){
  o.fog.only_add=flag&1;unlink(file);assert(write_scene_parameters(argv[1],o,file,error));RenderOptions saved;assert(read_scene_settings(file,&saved,error));assert(saved.fog.only_add==(flag&1));
  FILE *f=fopen(file,"r+b");assert(f);fseek(f,524,SEEK_SET);assert((fgetc(f)&2)==((flag&1)<<1));
  /* Locate the native settings block and emulate an older experimental file. */
  fseek(f,0,SEEK_END);long n=ftell(f);rewind(f);unsigned char *data=malloc(n);assert(fread(data,1,n,f)==(size_t)n);
  long pos=-1;for(long i=0;i<n-24;i++)if(!memcmp(data+i,"FOG1",4)){pos=i;break;}free(data);assert(pos>=0);
  unsigned char old[4]={(unsigned char)flag,0,0,0};fseek(f,pos+20,SEEK_SET);assert(fwrite(old,1,4,f)==4);fclose(f);
  assert(read_scene_settings(file,&saved,error));assert(saved.fog.only_add==(flag&1));
 }
 o.width=o.height=64;o.oversampling=o.viewing=1;o.threads=4;o.reuse_surface=0;o.fog.only_add=0;
 o.shadows_override=1;o.shadows.ambient_auto=o.shadows.hard_auto=0;
 RenderResult first=render_scene_with_options(argv[1],o);if(!first.rgba){puts(first.error);return 1;}
 o.reuse_surface=1;RenderResult repaint=render_scene_with_options(argv[1],o);assert(repaint.rgba&&repaint.reused_surface);
 for(int y=0;y<first.height;y++)assert(!memcmp(first.rgba+y*first.stride,repaint.rgba+y*repaint.stride,(size_t)first.width*4));
 printf("Automatic indirect brightness: %lu; native/legacy flags and identical cached repaint pass.\n",brightness(first));
 free(first.rgba);free(repaint.rgba);unlink(file);
 }return 0;}
