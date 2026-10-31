#include <math.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
extern void mix4_reference(void*,void*,void*),poly_reference(void*,void*,void*);
/* Independent expansion of the original Pascal option block. */
static void options(char *vars,double *v){
 for(int i=0;i<5;i++)memcpy(vars-16-i*8,v+i,8);
 float m[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
 int a[]={1,0,0,0,1,2},b[]={2,2,1,3,3,3};
 for(int k=0;k<6;k++){
  float c=cos(v[5+k]*acos(-1)/180),s=sin(v[5+k]*acos(-1)/180),r[4][4]={{0}},n[4][4];for(int i=0;i<4;i++)r[i][i]=1;
  r[a[k]][a[k]]=r[b[k]][b[k]]=c;r[a[k]][b[k]]=-s;r[b[k]][a[k]]=s;
  for(int i=0;i<4;i++)for(int j=0;j<4;j++){long double x=0;for(int q=0;q<4;q++)x+=(long double)r[i][q]*m[q][j];n[i][j]=x;}memcpy(m,n,sizeof m);
 }
 for(int i=0;i<16;i++)memcpy(vars-52-i*4,&m[0][0]+i,4);
 
}
int main(void){FILE *f=fopen("test_add72_vectors.h","w");assert(f);fputs("/* Original x87 formula steps, independently evaluated on x86-64. */\nstatic const MixVector add72_vectors[]={\n",f);
 for(int kind=132;kind<=133;kind++)for(int i=0;i<240;i++){
  double in[]={sin(i*.73+.1)*3,cos(i*.27)*2,sin(i*.41)*2.7,cos(i*.13)*1.8},out[4],v[15]={2,1,1,.5,.5,0,0,0,0,0,0,.5,.5,.5,.5},dr=1.25;
  if(i){if(kind==133){v[0]=i%2?2.3:-1.7;for(int j=1;j<5;j++)v[j]=cos(i*.17+j);for(int j=5;j<11;j++)v[j]=sin(i*.31+j)*77;for(int j=11;j<15;j++)v[j]=cos(i*.21+j)*.7;}else {v[0]=2+i%7*.5;for(int j=1;j<5;j++)v[j]=sin(i*.11+j)*2;}}else if(kind==132){memset(v,0,sizeof v);v[0]=4;}
  memcpy(out,in,sizeof out);char constants[512]={0},state[512]={0};char *vars=constants+256;
  if(kind==133){options(vars,v);memcpy(state+232,&dr,8);mix4_reference(out,vars,state);memcpy(&dr,state+232,8);}else{for(int j=0;j<5;j++)memcpy(vars-16-j*8,v+j,8);double tau=6.283185307,rad=.017453293;memcpy(vars,&tau,8);memcpy(vars+8,&rad,8);poly_reference(out,vars,state);}
  fprintf(f,"{%d,{",kind);for(int j=0;j<4;j++)fprintf(f,"%.17g,",in[j]);fputs("},{",f);for(int j=0;j<15;j++)fprintf(f,"%.17g,",v[j]);fputs("},{",f);for(int j=0;j<4;j++)fprintf(f,"%.17g,",out[j]);fprintf(f,"},%.17g},\n",dr);
 }fputs("};\n",f);fclose(f);return 0;}
