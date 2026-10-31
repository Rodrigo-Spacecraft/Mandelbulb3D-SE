/* MutaGen behavior adapted from MutaGen by Andreas Maschke (2016–2019),
   Mandelbulb3D, LGPL-2.1-or-later. Native implementation for this application. */
typedef struct {double probability[4],strength[3];} MutagenConfig;
static MutagenConfig mutagenDefaultConfig(void){return (MutagenConfig){{.75,1,.5,.5},{1,1,1}};}
static double mutagenRandom(uint64_t *state){*state^=*state<<13;*state^=*state>>7;*state^=*state<<17;return (*state>>11)*(1.0/9007199254740992.0);}
static int mutagenIndex(uint64_t *state,int count){return count>0?MIN(count-1,(int)(mutagenRandom(state)*count)):0;}
static int mutagenChooseKind(uint64_t *random,int category,BOOL modifier,int previous){
    int kinds[2048],count=0;for(int i=0;i<formula_menu_count()&&count<2048;i++){int k=formulaKindForMenu(i);const char *name=formula_name(k);if(formulaCategory(k)==category&&(name[0]=='_')==modifier&&k!=previous)kinds[count++]=k;}
    return count?kinds[mutagenIndex(random,count)]:previous;
}
static RenderOptions mutagenMutate(RenderOptions original,MutagenConfig config,uint64_t *random){
    RenderOptions out=original;FormulaProgram *p=&out.program;out.program_override=1;out.formula_override=out.sequence_override=0;
    if(mutagenRandom(random)<config.probability[0]){
        int family=0;for(int i=0;i<6;i++)if(p->slots[i].count){int category=(int)formulaCategory(p->slots[i].kind);if(category>=5){family=5;break;}if(category==2||category==3)family=2;}
        for(int i=0;i<6;i++)if(!p->slots[i].count){int category=i?family+mutagenIndex(random,family?2:3):family;if(!family&&category==2)category=4;int kind=mutagenChooseKind(random,category,NO,-1);if(kind>=0){p->slots[i]=formula_slot_default(kind);p->slots[i].count=1;}break;}
        for(int i=0;i<6;i++)if(p->slots[i].count){int old=p->slots[i].kind,kind=mutagenChooseKind(random,(int)formulaCategory(old),formula_name(old)[0]=='_',old);if(kind!=old){int count=p->slots[i].count;p->slots[i]=formula_slot_default(kind);p->slots[i].count=count;}break;}
        int active=0;for(int i=0;i<6;i++)active+=p->slots[i].count>0;
        if(active>4||(active>3&&mutagenRandom(random)>.5)){const int priority[]={6,3,1,4,5,2,0};BOOL removed=NO;for(int pass=0;pass<2&&!removed;pass++)for(int c=0;c<7&&!removed;c++)for(int i=5;i>=0;i--)if(p->slots[i].count&&formulaCategory(p->slots[i].kind)==priority[c]&&(pass||formula_name(p->slots[i].kind)[0]=='_')){p->slots[i]=formula_slot_default(0);p->slots[i].count=0;removed=YES;break;}}
    }
    if(mutagenRandom(random)<config.probability[1]){
        int slots[6],count=0;for(int i=0;i<6;i++)if(p->slots[i].count&&formula_parameter_count(p->slots[i].kind)>0)slots[count++]=i;
        if(count){FormulaSlot *f=&p->slots[slots[mutagenIndex(random,count)]];int n=formula_parameter_count(f->kind),passes=1;for(int i=2;i<=8;i++)if(n>i&&config.strength[0]>(i-1)*.25)passes++;
            for(int i=0;i<passes;i++){int j=mutagenIndex(random,n);FormulaParameter spec=formulaUIParameter(f->kind,j);double value=formula_slot_value(*f,j),delta;
                if(spec.integer)delta=(1+mutagenRandom(random)*1.5)*config.strength[0]*(mutagenRandom(random)>.5?-1:1);
                else delta=(fabs(value)>1e-12?exp(log10(fabs(value*.1))+.5+mutagenRandom(random)):1)*(.5-mutagenRandom(random))*config.strength[0];
                value=fmax(spec.minimum,fmin(spec.maximum,value+delta));if(spec.integer)value=round(value);if(isfinite(value))formula_slot_set_value(f,j,value);
            }
        }
    }
    if(mutagenRandom(random)<config.probability[2]){out.julia_override=out.rotation4_override=1;out.julia=mutagenRandom(random)>.25;if(out.julia){for(int i=0;i<4;i++)if(mutagenRandom(random)>(i==3?.75:.5)){double v=config.strength[1]*(.5-mutagenRandom(random))*1.5;if(i<3)out.julia_c[i]=v;else out.julia_w=v;}if(fabs(out.julia_c[0])+fabs(out.julia_c[1])+fabs(out.julia_c[2])<1e-12)out.julia_c[mutagenIndex(random,3)]=config.strength[1]*(.5-mutagenRandom(random))*1.5;}}
    if(mutagenRandom(random)<config.probability[3]){int slots[6],n=0;for(int i=0;i<6;i++)if(p->slots[i].count)slots[n++]=i;if(n>1){for(int i=0;i<n;i++)p->slots[slots[i]].count=1;int passes=1+(config.strength[2]>.5)+(config.strength[2]>1)+(config.strength[2]>1.5);for(int i=0;i<passes;i++)p->slots[slots[mutagenIndex(random,n)]].count=1+mutagenIndex(random,(int)round(2+2*config.strength[2]));}}
    return out;
}
static double mutagenCoverage(const unsigned char *pixels,const unsigned char *parent,int width,int height,double *difference){
    double edges=0,diff=0;for(int y=1;y<height-1;y++)for(int x=1;x<width-1;x++){int i=(y*width+x)*4,edge=0,other=0;for(int c=0;c<3;c++){edge=MAX(edge,abs(pixels[i+c]-pixels[i+4+c]));edge=MAX(edge,abs(pixels[i+c]-pixels[i+width*4+c]));if(parent){other=MAX(other,abs(parent[i+c]-parent[i+4+c]));other=MAX(other,abs(parent[i+c]-parent[i+width*4+c]));}}edges+=edge>12;diff+=(edge>12)!=(other>12);}double size=MAX(1,(width-2)*(height-2));*difference=diff/size;return edges/size;
}
