#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#define PI 3.14159265358979323846
extern void BoxIFS_reference(void*,void*),HeightMapIFS_reference(void*,void*);
static void pd(char*p,int n,double v){memcpy(p+n,&v,8);}static void pf(char*p,int n,float v){memcpy(p+n,&v,4);}static void pi(char*p,int n,int v){memcpy(p+n,&v,4);}static double gd(char*p,int n){double v;memcpy(&v,p+n,8);return v;}
static void matrix(char*k,double*v){double sx=sin(v[0]*PI/180),cx=cos(v[0]*PI/180),sy=sin(v[1]*PI/180),cy=cos(v[1]*PI/180),sz=sin(v[2]*PI/180),cz=cos(v[2]*PI/180);double m[]={cy*cz,-cy*sz,sy,sx*sy*cz+cx*sz,cx*cz-sx*sy*sz,-sx*cy,sx*sz-cx*sy*cz,cx*sy*sz+sx*cz,cx*cy};for(int i=0;i<9;i++)pf(k,-40-i*4,m[i]);}
int main(void){FILE*f=fopen("box_height_vectors.h","w");assert(f);fputs("/* Original BoxIFS and HeightMapIFS steps; map callback returns RGB .2/.4/.8. */\nstatic const BoxHeightVector box_height_vectors[]={\n",f);
for(int kind=115;kind<=116;kind++)for(int i=0;i<240;i++){
 double v[16]={0},p[]={sin(i*.73)*4,cos(i*.27)*3,sin(i*.41)*(kind==115?2:.15)};char mem[512]={0},block[512]={0};char*k=mem+256,*state=block+160;
 pd(state,-128,.001);pd(state,-136,.001);for(int j=0;j<3;j++)pd(state,-120+j*8,p[j]);pd(state,112,1.3);pd(state,128,.123);pd(state,144,NAN);pd(state,152,NAN);pd(k,-8,.5);
 if(kind==115){v[0]=v[1]=v[2]=1;v[3]=2;v[6]=2;v[9]=1;v[11]=v[12]=1;
 if(i>=20){v[0]=.7;v[1]=1.3;v[2]=.9;v[3]=i%7?-1.7:1.3;v[4]=-.3;v[5]=.2;v[6]=-.1;v[7]=sin(i*.19);v[8]=cos(i*.23);v[9]=i%2;v[10]=i%4;v[11]=.17;v[12]=-.23;}
 for(int j=0;j<3;j++)pd(k,-16-j*8,v[j]);pd(k,-40,v[3]);pd(k,-48,v[3]);pd(k,-56,v[4]);pd(k,-64,v[4]);pd(k,-72,v[5]);pd(k,-80,v[6]);pd(k,-88,v[7]);pf(k,-92,v[8]);pi(k,-96,v[9]);pi(k,-100,v[10]);pf(k,-104,v[11]);pf(k,-108,v[12]);unsigned long long mask=0x7fffffffffffffffULL;memcpy(k,&mask,8);memcpy(k+8,&mask,8);BoxIFS_reference(k,state);
 }else{v[0]=10;v[4]=v[5]=.2;v[6]=-.1;v[11]=v[13]=1;
 if(i>=20){v[1]=-.3;v[2]=.2;v[3]=.07;v[4]=.3;v[5]=-.4;v[6]=i%2?.17:-.21;v[7]=i%60;v[8]=-i%45;v[9]=i%90;v[10]=i%3;v[11]=(i/3)%3;v[12]=-.13;v[13]=1.7;}
 pi(k,-12,v[0]);for(int j=1;j<=6;j++)pf(k,-12-j*4,v[j]);matrix(k,v+7);pi(k,-76,v[10]);pi(k,-80,v[11]);pf(k,-84,v[12]);pf(k,-88,v[13]);HeightMapIFS_reference(k,state);}
 fprintf(f,"{%d,{%.17g,%.17g,%.17g},{",kind,p[0],p[1],p[2]);for(int j=0;j<16;j++)fprintf(f,"%.17g,",v[j]);fprintf(f,"},%.17g,%.17g,%.17g,{%.17g,%.17g,%.17g},",gd(state,-32),gd(state,112),gd(state,128),gd(state,-120),gd(state,-112),gd(state,-104));double u=gd(state,144),w=gd(state,152);if(isnan(u))fputs("NAN,NAN},\n",f);else fprintf(f,"%.17g,%.17g},\n",u,w);
}fputs("};\n",f);fclose(f);return 0;}
