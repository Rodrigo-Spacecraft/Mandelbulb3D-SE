#include "renderer.c"
/* Developer microbenchmark: compare prepared paths with full native C.
 * Compile via make ENGINE=c benchmark-c-formulas. Timings are diagnostic,
 * never correctness tests or quality settings. */
static volatile double sink;
static int selected_formula(const char *path,const char *name){if(!path)return 1;FILE *f=fopen(path,"r");if(!f)return 0;char line[256];int found=0;while(fgets(line,sizeof line,f)){line[strcspn(line,"\r\n")]=0;if(!strcmp(line,name)){found=1;break;}}fclose(f);return found;}
int main(int argc,char **argv){int repetitions=argc>1?atoi(argv[1]):20000;if(repetitions<1000)repetitions=1000;printf("formula\tprepared_ns\tnative_ns\tratio\tbest_probe\n");double total[2]={0};int n=0;
for(size_t k=0;k<RUST_FORMULA_COUNT;k++){
 const RustFormula *meta=&rust_formulas[k];if(meta->builtin<20||!selected_formula(argc>2?argv[2]:NULL,meta->name)||(!(argc>2)&&!cn_compact_lookup(meta->name).function))continue;
 scene_defaults();FormulaSlot f=formula_slot_default(meta->kind);f.count=1;scene.program=legacy_program();for(int i=0;i<8;i++)scene.program.slots[i].count=0;scene.program.slots[0]=f;scene.program_enabled=1;
 Vec z={.371,.213,.419},c={.137,-.283,.317};double times[2]={0},probe[4][2]={{0}};
 for(int round=0;round<4;round++)for(int pass=0;pass<2;pass++){
  z=round==0?(Vec){.371,.213,.419}:round==1?(Vec){-.713,.827,-1.131}:round==2?(Vec){2.31,-1.72,.93}:(Vec){1e-4,-2e-4,3e-4};int ref=(pass+round)%2;cf_reference_execution=ref;cf_begin(z,c,.173,60);CFormulaVM *vm=cf_vm();vm->contexts[0].state&=~16;vm->compact[0]=meta->de<20?cf_pure_index(meta->name):0;double start=info_clock();double sum=0;
  for(int i=0;i<repetitions;i++){Vec j=c;double w=.193,dr=1,power=2;Vec result=cf_step_at(z,&j,.173,&w,f,&dr,&power,0);sum+=result.x;}
  double elapsed=info_clock()-start;times[ref]+=elapsed;probe[round][ref]=elapsed;sink=sum;
 }
 double best=0;for(int p=0;p<4;p++)best=fmax(best,probe[p][1]/fmax(probe[p][0],1e-12));printf("%s\t%.3f\t%.3f\t%.3f\t%.3f\n",meta->name,times[0]*1e9/(4*repetitions),times[1]*1e9/(4*repetitions),times[1]/times[0],best);fflush(stdout);total[0]+=times[0];total[1]+=times[1];n++;
}fprintf(stderr,"%d formulas prepared %.6f native %.6f speedup %.3f\n",n,total[0],total[1],total[1]/total[0]);}
