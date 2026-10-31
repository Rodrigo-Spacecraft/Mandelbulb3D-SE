/* Independent translation of Math3D.BuildSMatrix4 / Rotate4Dex and
 * formulas.doHybrid4DPas initialization, driving original formula kernels. */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
extern void makin4_reference(void*,void*,void*),cubicquat_reference(void*,void*,void*),lambda4_reference(void*,void*,void*),mixpinski_reference(void*,void*,void*);
static void matrix(float m[4][4],const double angles[3]){
 memset(m,0,64);for(int i=0;i<4;i++)m[i][i]=1;
 for(int k=0;k<3;k++){
  float r[4][4]={{0}},n[4][4],s=sin(angles[k]),c=cos(angles[k]);for(int i=0;i<4;i++)r[i][i]=1;r[k][k]=r[3][3]=c;r[k][3]=-s;r[3][k]=s;
  for(int i=0;i<4;i++)for(int j=0;j<4;j++){long double total=0;for(int q=0;q<4;q++)total+=(long double)r[i][q]*m[q][j];n[i][j]=total;}memcpy(m,n,64);
 }
}
int main(void){FILE *file=fopen("test_rotation4_vectors.h","w");assert(file);fputs("/* Original 4D initialization and original x87 kernels, four complete steps. */\nstatic const Rotation4Vector rotation4_vectors[]={\n",file);int kinds[]={2,118,119,120,130};
 for(int kindIndex=0;kindIndex<5;kindIndex++)for(int i=0;i<120;i++){
  int kind=kinds[kindIndex],julia=i%2;double input[]={sin(i*.19)*.4,cos(i*.37)*.3,sin(i*.71)*.2},angles[]={sin(i*.13)*2,cos(i*.27)*1.5,sin(i*.11)*2.7},constant[]={.17,-.09,.13,-.07},out[4]={0};if(i<4){angles[0]=angles[1]=angles[2]=0;if(i)angles[i-1]=acos(-1)*.5;}
  float m[4][4];matrix(m,angles);for(int k=0;k<4;k++)out[k]=input[0]*m[k][0]+input[1]*m[k][1]+input[2]*m[k][2];if(!julia)memcpy(constant,out,sizeof constant);
  char data[512]={0},state[512]={0};char *vars=data+256,*st=state+128;double derivative=1;
  for(int j=0;j<3;j++)memcpy(st+24+j*8,constant+j,8);memcpy(st-56,constant+3,8);memcpy(st+232,&derivative,8);
  double defaults[15]={0};if(kind==119){defaults[0]=defaults[1]=defaults[2]=defaults[3]=1;}if(kind==120)defaults[0]=1;
  if(kind==130){double v[]={2,1,1,.5,.5};for(int j=0;j<5;j++)memcpy(vars-16-j*8,v+j,8);for(int j=0;j<16;j++){float f=j%5==0?1:0;memcpy(vars-52-j*4,&f,4);}for(int j=0;j<4;j++){double f=.5;memcpy(vars-120-j*8,&f,8);}}
  else for(int j=0;j<7;j++)memcpy(vars-16-j*8,defaults+j,8);
  for(int step=0;step<4;step++){
   if(kind==118)makin4_reference(out,vars,st);else if(kind==119)cubicquat_reference(out,vars,st);else if(kind==120)lambda4_reference(out,vars,st);else if(kind==130)mixpinski_reference(out,vars,st);else{
    double x=out[0],y=out[1],z=out[2],w=out[3];out[0]=x*x-y*y-z*z-w*w+constant[0];out[1]=2*(y*x+z*w)+constant[1];out[2]=2*(z*x-y*w)+constant[2];out[3]=2*(w*x+y*z)+constant[3];
   }
  }
  fprintf(file,"{%d,%d,{",kind,julia);for(int j=0;j<3;j++)fprintf(file,"%.17g,",input[j]);fputs("},{",file);for(int j=0;j<3;j++)fprintf(file,"%.17g,",angles[j]);fputs("},{",file);for(int j=0;j<4;j++)fprintf(file,"%.17g,",out[j]);fputs("}},\n",file);
 }fputs("};\n",file);fclose(file);return 0;
}
