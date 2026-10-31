#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
extern void addc_reference(void*,void*,void*),siny_reference(void*,void*,void*),benesi_reference(void*,void*,void*);
static void pd(char *p,int n,double v){memcpy(p+n,&v,8);}static void pf(char*p,int n,float v){memcpy(p+n,&v,4);}
int main(void){FILE *f=fopen("new_vectors.h","w");assert(f);fputs("/* Golden steps from original MB3D x87 code, adapted to x86-64 calling convention. */\nstatic const NewFormulaVector new_vectors[]={\n",f);
for(int kind=105;kind<=107;kind++)for(int i=0;i<160;i++){
 double input[]={sin(i*.73)*2,cos(i*.27)*1.3,sin(i*.41)*1.7,cos(i*.13)},c[]={sin(i*.17),cos(i*.23),sin(i*.31)},p[5]={0};double output[4];memcpy(output,input,sizeof output);char constants[256]={0},block[128]={0};char *vars=constants+128;
 for(int j=0;j<3;j++)pd(block,24+j*8,c[j]);
 if(kind==105){for(int j=0;j<3;j++){p[j]=sin(i*.11+j)*2;pd(vars,-16-j*8,p[j]);}addc_reference(output,vars,block);}
 if(kind==106){p[0]=i%4;p[1]=sin(i*.2);p[2]=cos(i*.19)*4;p[3]=1.7;p[4]=-.2;int index=i%4;memcpy(vars-12,&index,4);for(int j=1;j<5;j++)pf(vars,-12-j*4,p[j]);siny_reference(output,vars,block);}
 if(kind==107)benesi_reference(output,vars,block);
 fprintf(f,"{%d,{%.17g,%.17g,%.17g,%.17g},{%.17g,%.17g,%.17g},{%.17g,%.17g,%.17g,%.17g,%.17g},{%.17g,%.17g,%.17g,%.17g}},\n",kind,input[0],input[1],input[2],input[3],c[0],c[1],c[2],p[0],p[1],p[2],p[3],p[4],output[0],output[1],output[2],output[3]);
}fputs("};\n",f);fclose(f);return 0;}
