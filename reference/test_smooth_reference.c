#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
extern void menger_reference(void*,void*),reciprocal_reference(void*,void*);
static void pd(char *p,int offset,double v){memcpy(p+offset,&v,8);}static void pf(char *p,int offset,float v){memcpy(p+offset,&v,4);}
static void matrix(char *p,double *v){double sx=sin(v[0]*M_PI/180),cx=cos(v[0]*M_PI/180),sy=sin(v[1]*M_PI/180),cy=cos(v[1]*M_PI/180),sz=sin(v[2]*M_PI/180),cz=cos(v[2]*M_PI/180);double m[]={cy*cz,-cy*sz,sy,sx*sy*cz+cx*sz,cx*cz-sx*sy*sz,-sx*cy,sx*sz-cx*sy*cz,cx*sy*sz+sx*cz,cx*cy};for(int i=0;i<9;i++)pf(p,-44-i*4,m[i]);}
int main(void){FILE *f=fopen("smooth_vectors.h","w");assert(f);fputs("/* Golden steps from original MB3D x87 kernels. */\nstatic const SmoothVector smooth_vectors[]={\n",f);
for(int kind=121;kind<=122;kind++)for(int i=0;i<220;i++){
 double input[]={sin(i*.37+.1)*7,cos(i*.13)*5,sin(i*.27+.2)*3,cos(i*.17)},v[9]={0},output[4];memcpy(output,input,sizeof output);char constants[512]={0};char *p=constants+256;
 if(kind==121){v[0]=i%5?2.1+sin(i*.2):-2.3;v[1]=.7;v[2]=1.2;v[3]=.5;for(int j=4;j<7;j++)v[j]=i%4?sin(i*.19+j)*130:0;v[7]=i%3==0?.005:i%3==1?-.04:0;v[8]=i%4==0?.007:i%4==1?-.08:i%4==2?0:.02;for(int j=0;j<4;j++)pd(p,-16-j*8,v[j]);matrix(p,v+4);pd(p,-84,v[7]);pd(p,-92,v[8]);pd(p,0,.5);menger_reference(output,p);}
 else{v[0]=.1+(i%17)*.1;v[1]=.05+(i%13)*.07;v[2]=sin(i*.31)*2;v[3]=cos(i*.21)*3;pd(p,-16,v[0]);pd(p,-24,1/v[0]);pd(p,-32,v[1]);pd(p,-40,1/v[1]);pd(p,-48,v[2]);pd(p,-56,v[3]);reciprocal_reference(output,p);}
 fprintf(f,"{%d,{",kind);for(int j=0;j<4;j++)fprintf(f,"%.17g,",input[j]);fputs("},{",f);for(int j=0;j<9;j++)fprintf(f,"%.17g,",v[j]);fputs("},{",f);for(int j=0;j<4;j++)fprintf(f,"%.17g,",output[j]);fputs("}},\n",f);
}fputs("};\n",f);fclose(f);return 0;}
