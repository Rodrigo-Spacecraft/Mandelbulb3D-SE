#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
extern void rounded_reference(void*,void*),amazingifs_reference(void*,void*);
static void pd(char*p,int i,double v){memcpy(p+i,&v,8);}static void pf(char*p,int i,float v){memcpy(p+i,&v,4);}static void pi(char*p,int i,int v){memcpy(p+i,&v,4);}
int main(){FILE*f=fopen("test_shapes_vectors.h","w");assert(f);fputs("/* Original RoundedBox / amazingIFS SSE2/x87 kernels. */\nstatic const ShapeVector shape_vectors[]={\n",f);for(int kind=126;kind<=127;kind++)for(int i=0;i<240;i++){double in[]={sin(i*.37+.1)*4,cos(i*.21)*3,sin(i*.17)*4},v[12]={0};_Alignas(16) char state[512]={0},constants[512]={0};char*s=state+128,*p=constants+256;for(int j=0;j<3;j++)pd(s,-120+j*8,in[j]);pd(s,112,1);pd(s,-128,.0123);
if(kind==126){double q[]={1,.8,1.2,2,0,0,2,.1,1,0,1,1};memcpy(v,q,sizeof q);v[3]=i%3?1.7:-2;v[4]=sin(i*.3);v[5]=.3;v[6]=-.2;v[7]=i%5?.17:-.1;v[8]=i%2;v[9]=i%4;v[10]=.31;v[11]=.7;pd(p,-16,v[0]);pd(p,-24,v[1]);pd(p,-32,v[2]);pd(p,-48,v[3]);pd(p,-40,v[3]);pd(p,-64,v[4]);pd(p,-56,v[4]);pd(p,-72,v[5]);pd(p,-80,v[6]);pd(p,-96,v[7]);pd(p,-88,v[7]);pi(p,-100,v[8]);pi(p,-104,v[9]);pf(p,-108,v[10]);pf(p,-112,v[11]);uint64_t mask=0x7fffffffffffffff;memcpy(p,&mask,8);memcpy(p+8,&mask,8);rounded_reference(s,p);}
else{v[0]=sin(i*.3);v[1]=.2;v[2]=-.1;for(int j=3;j<6;j++)v[j]=i%4?sin(i*.17+j)*90:0;v[6]=.5;v[7]=i%3?.7:-.1;v[8]=.2;v[9]=i%5?31:.5;for(int j=0;j<3;j++)pd(p,-16-j*8,v[j]);double sx=sin(v[3]*M_PI/180),cx=cos(v[3]*M_PI/180),sy=sin(v[4]*M_PI/180),cy=cos(v[4]*M_PI/180),sz=sin(v[5]*M_PI/180),cz=cos(v[5]*M_PI/180);double m[]={cy*cz,-cy*sz,sy,sx*sy*cz+cx*sz,cx*cz-sx*sy*sz,-sx*cy,sx*sz-cx*sy*cz,cx*sy*sz+sx*cz,cx*cy};for(int j=0;j<9;j++)pf(p,-36-j*4,m[j]);pd(p,-92,v[6]);pd(p,-84,v[7]);pd(p,-76,v[8]);pd(p,-100,v[9]);amazingifs_reference(s,p);}
double d=0,scale,trap=0,xyz[3];if(kind==126){memcpy(&d,s-32,8);memcpy(&trap,s+128,8);}memcpy(&scale,s+112,8);memcpy(xyz,s-120,24);fprintf(f,"{%d,{%.17g,%.17g,%.17g},{",kind,in[0],in[1],in[2]);for(int j=0;j<12;j++)fprintf(f,"%.17g,",v[j]);fprintf(f,"},%.17g,{%.17g,%.17g,%.17g},%.17g,%.17g},\n",d,xyz[0],xyz[1],xyz[2],scale,trap);}fputs("};\n",f);fclose(f);}
