#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
extern void sphere_reference(void*,void*);
static void pd(char*p,int i,double v){memcpy(p+i,&v,8);}static void pf(char*p,int i,float v){memcpy(p+i,&v,4);}static void pi(char*p,int i,int v){memcpy(p+i,&v,4);}
int main(){FILE*f=fopen("test_sphere_vectors.h","w");assert(f);fputs("/* Original SphereIFS SSE2/x87 reference. */\nstatic const SphereVector sphere_vectors[]={\n",f);for(int i=0;i<240;i++){double in[]={sin(i*.37+.1)*4,cos(i*.21)*3,sin(i*.17)*4},v[]={1,2,0,0,3,1,1,1,1,0,1,1,-1};v[1]=i%3?1.7:-2;v[2]=sin(i*.3);v[3]=.3;v[4]=-.2;v[5]=.4+(i%7)*.2;v[6]=i%2?-.8:1.3;v[7]=1.9;v[8]=i%2;v[9]=i%4;v[10]=.31;v[11]=.7;v[12]=i%3?.8:-1;_Alignas(16) char state[512]={0},constants[512]={0};char*s=state+128,*p=constants+256;for(int j=0;j<3;j++)pd(s,-120+j*8,in[j]);pd(s,112,1);pd(s,-128,.0123);pd(p,-16,v[0]);pd(p,-32,v[1]);pd(p,-24,v[1]);pd(p,-48,v[2]);pd(p,-40,v[2]);pd(p,-56,v[3]);pd(p,-72,v[4]);pd(p,-64,v[4]);pd(p,-80,1/v[5]);pd(p,-88,1/v[6]);pd(p,-96,1/v[7]);pi(p,-100,v[8]);pi(p,-104,v[9]);pf(p,-108,v[10]);pf(p,-112,v[11]);pd(p,-120,v[12]);uint64_t mask=0x7fffffffffffffff;memcpy(p,&mask,8);memcpy(p+8,&mask,8);sphere_reference(s,p);double d,scale,trap,xyz[3];memcpy(&d,s-32,8);memcpy(&scale,s+112,8);memcpy(&trap,s+128,8);memcpy(xyz,s-120,24);fprintf(f,"{{%.17g,%.17g,%.17g},{",in[0],in[1],in[2]);for(int j=0;j<13;j++)fprintf(f,"%.17g,",v[j]);fprintf(f,"},%.17g,{%.17g,%.17g,%.17g},%.17g,%.17g},\n",d,xyz[0],xyz[1],xyz[2],scale,trap);}fputs("};\n",f);fclose(f);}
