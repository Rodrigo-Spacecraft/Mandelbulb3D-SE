#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
extern void cage_reference(void*,void*);
static void pd(char*p,int i,double v){memcpy(p+i,&v,8);}static void pi(char*p,int i,int v){memcpy(p+i,&v,4);}
int main(){FILE*f=fopen("test_cage_vectors.h","w");assert(f);fputs("/* Original SphCageIFS SSE2/x87 reference. */\nstatic const CageVector cage_vectors[]={\n",f);for(int i=0;i<240;i++){double in[]={sin(i*.37+.1)*4,cos(i*.21)*3,sin(i*.17)*4},v[]={.5,1,0,0,0,.01,1,8,20};v[0]=i%5?.5:-.7;v[1]=i%3?1.7:-2;v[2]=sin(i*.3);v[3]=.3;v[4]=-.2;v[5]=.01+(i%3)*.02;v[6]=i%2;v[7]=2+i%31;v[8]=1+i%37;_Alignas(16) char state[512]={0},constants[512]={0};char*s=state+128,*p=constants+256;for(int j=0;j<3;j++)pd(s,-120+j*8,in[j]);pd(s,112,1);pd(p,-16,v[0]);pd(p,-32,v[1]);pd(p,-24,v[1]);pd(p,-48,v[2]);pd(p,-40,v[2]);pd(p,-56,v[3]);pd(p,-64,v[4]);pd(p,-72,v[5]);pi(p,-76,v[6]);pi(p,-80,v[7]);pi(p,-84,v[8]);pd(p,0,.159154943);pd(p,8,6.283185307);pd(p,16,1.57079632675);pd(p,24,2);cage_reference(s,p);double d,scale,xyz[3];memcpy(&d,s-32,8);memcpy(&scale,s+112,8);memcpy(xyz,s-120,24);fprintf(f,"{{%.17g,%.17g,%.17g},{",in[0],in[1],in[2]);for(int j=0;j<9;j++)fprintf(f,"%.17g,",v[j]);fprintf(f,"},%.17g,{%.17g,%.17g,%.17g},%.17g},\n",d,xyz[0],xyz[1],xyz[2],scale);}fputs("};\n",f);fclose(f);}
