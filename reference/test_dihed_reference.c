#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
extern void dihed_reference(void*,void*,void*);
static void pd(char*p,int n,double v){memcpy(p+n,&v,8);}
int main(void){FILE*f=fopen("dihed_vectors.h","w");assert(f);fputs("/* Golden steps from original TgladDihed x87 code. */\nstatic const ExtraVector dihed_vectors[]={\n",f);
for(int i=0;i<320;i++){
 double in[]={sin(i*.73+.1)*.8,cos(i*.27)*.7,sin(i*.41)*.6},out[3],c[]={.13,-.21,.07};char mem[256]={0},block[128]={0};char*v=mem+128;int power=i%8,map=(i/8)%8;if(i>=256){in[0]=3;in[1]=2;in[2]=1;}memcpy(v-12,&power,4);memcpy(v-16,&map,4);
 double constants[]={.5,-3,2.8284271247461901,.3535533905932738,3.1819805153394639,2,1e10};for(int j=0;j<7;j++)pd(v,j*8,constants[j]);for(int j=0;j<3;j++)pd(block,24+j*8,c[j]);memcpy(out,in,24);dihed_reference(out,v,block);
 if(!isfinite(out[0])||!isfinite(out[1])||!isfinite(out[2]))continue;
 fprintf(f,"{110,{%.17g,%.17g,%.17g},{%d,%d},{%.17g,%.17g,%.17g}},\n",in[0],in[1],in[2],power,map,out[0],out[1],out[2]);
}fputs("};\n",f);fclose(f);return 0;}
