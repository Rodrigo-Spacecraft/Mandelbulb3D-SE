#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
extern void torus_reference(void*,void*);
int main(void){
 FILE*f=fopen("torus_vectors.h","w");assert(f);
 fputs("/* Golden steps from original _toruspinv3 x87 code. */\nstatic const NewFormulaVector torus_vectors[]={\n",f);
 for(int i=0;i<200;i++){
 double in[]={sin(i*.73)*2,cos(i*.27)*1.3,sin(i*.41)*1.7,.123},out[4],p[]={sin(i*.11),cos(i*.13),sin(i*.17),cos(i*.19)*2,sin(i*.23)*3};
 if(i<20){p[0]=p[1]=p[2]=0;p[3]=p[4]=1;}
 char mem[128]={0};char*vars=mem+96;for(int j=0;j<5;j++)memcpy(vars-16-j*8,p+j,8);memcpy(out,in,sizeof out);torus_reference(out,vars);
 fprintf(f,"{108,{%.17g,%.17g,%.17g,%.17g},{0,0,0},{%.17g,%.17g,%.17g,%.17g,%.17g},{%.17g,%.17g,%.17g,%.17g}},\n",in[0],in[1],in[2],in[3],p[0],p[1],p[2],p[3],p[4],out[0],out[1],out[2],out[3]);
 }fputs("};\n",f);fclose(f);return 0;
}
