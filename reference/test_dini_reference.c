#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
extern void dini_reference(void*,void*);
static void pd(char*p,int i,double v){memcpy(p+i,&v,8);}static void pi(char*p,int i,int v){memcpy(p+i,&v,4);}
int main(){FILE*f=fopen("test_dini_vectors.h","w");assert(f);fputs("/* Original DiniIFS SSE2/x87 golden vectors. */\nstatic const DiniVector dini_vectors[]={\n",f);for(int i=0;i<240;i++){double in[]={sin(i*.37+.1)*4,cos(i*.21)*3,sin(i*.17)*4},v[]={3,2,0,0,0,2.85,1,.001,.1,0,0,.2};v[1]=i%4?-1.7:2;v[2]=sin(i*.3);v[3]=.3;v[4]=-.2;v[6]=i%2;v[9]=(i%3)-1;v[10]=i%2;v[11]=i%5?.2:-.35;char state[512]={0},constants[512]={0};char*s=state+128,*p=constants+256;for(int j=0;j<3;j++)pd(s,-120+j*8,in[j]);pd(s,112,1);pd(p,-16,v[0]);pd(p,-32,v[1]);pd(p,-24,v[1]);pd(p,-48,v[2]);pd(p,-40,v[2]);pd(p,-56,v[3]);pd(p,-64,v[4]);pd(p,-72,v[5]);pi(p,-76,v[6]);pd(p,-84,v[7]);pd(p,-92,v[8]);pi(p,-96,v[9]);pi(p,-100,v[10]);pd(p,-108,v[11]);pd(p,0,.3);pd(p,8,.02);pd(p,16,1e200);dini_reference(s,p);double dist,scale,xyz[3];memcpy(&dist,s-32,8);memcpy(&scale,s+112,8);memcpy(xyz,s-120,24);fprintf(f,"{{%.17g,%.17g,%.17g},{",in[0],in[1],in[2]);for(int j=0;j<12;j++)fprintf(f,"%.17g,",v[j]);fprintf(f,"},%.17g,{%.17g,%.17g,%.17g},%.17g},\n",dist,xyz[0],xyz[1],xyz[2],scale);}fputs("};\n",f);fclose(f);}
