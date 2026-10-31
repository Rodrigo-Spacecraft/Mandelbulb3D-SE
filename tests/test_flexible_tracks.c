#include "renderer.c"
#include <assert.h>
int main(void){
 RenderOptions o;char error[512];assert(read_scene_settings("tests/flexible-tracks-parameters.m3p",&o,error));load_height_maps();
 FILE *fp=fopen("tests/flexible-tracks-de.tsv","r");assert(fp);char line[2048];int n=0;
 while(fgets(line,sizeof line,fp)){if(line[0]=='#')continue;Vec p;double de,smooth,trap,correction;assert(sscanf(line,"%lf %lf %lf %lf %lf %lf %lf",&p.x,&p.y,&p.z,&de,&smooth,&trap,&correction)==7);Sample direct=evaluate(p);render_plans[0]=make_part_plan(&scene.program,0,7);render_plan_count=1;Sample s=evaluate(p);render_plan_count=0;assert(s.distance==direct.distance&&s.smooth==direct.smooth&&s.orbit_trap==direct.orbit_trap);
 if(fabs(s.distance-de)>1e-8+fabs(de)*5e-7){fprintf(stderr,"DE sample %d C %.17g Rust %.17g\n",n,s.distance,de);abort();}
 if(s.smooth<scene.iterations&&fabs(s.smooth-smooth)>2e-5){fprintf(stderr,"Smooth sample %d C %.17g Rust %.17g\n",n,s.smooth,smooth);abort();}
 assert(fabs(s.orbit_trap-trap)<1e-8+fabs(trap)*1e-7);
 double eps=scene.de_stop*2.1345/(scene.zoom*scene.width),actual=color_de_correction(eps)+color_scale_offset()+color_iteration_limit()*.1;
 if(fabs(actual-correction)>2e-5){fprintf(stderr,"Color correction C %.17g Rust %.17g\n",actual,correction);abort();}n++;
 }fclose(fp);assert(n==189);
 assert(!scale_de_formula(formula_slot_default(100)));
 FormulaSlot f=formula_slot_default(109);f.parameters[0]=2;assert(fabs(analytic_de_factor(f)-1.7)<1e-15);f.parameters[0]=-2;assert(analytic_de_factor(f)==.65);f.parameters[0]=0;assert(isfinite(analytic_de_factor(f)));
 puts("FlexibleTracks: 189 world-space DE, smooth iteration, trap and color-correction samples match the Rust CPU reference; positive/negative/zero scale cases pass.");
}
