#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#define PI 3.14159265358979323846
extern void surf_reference(void*,void*,void*);
static void pd(char*p,int n,double v){memcpy(p+n,&v,8);}static void pf(char*p,int n,float v){memcpy(p+n,&v,4);}
static void matrix(char*k,double*v){double sx=sin(v[0]*PI/180),cx=cos(v[0]*PI/180),sy=sin(v[1]*PI/180),cy=cos(v[1]*PI/180),sz=sin(v[2]*PI/180),cz=cos(v[2]*PI/180);double m[]={cy*cz,-cy*sz,sy,sx*sy*cz+cx*sz,cx*cz-sx*sy*sz,-sx*cy,sx*sz-cx*sy*cz,cx*sy*sz+sx*cz,cx*cy};for(int i=0;i<9;i++)pf(k,-44-i*4,m[i]);}
int main(void){FILE*f=fopen("surf_vectors.h","w");assert(f);fputs("/* Golden steps from original Amazing Surf x87 code. */\nstatic const SurfVector surf_vectors[]={\n",f);
for(int i=0;i<160;i++){
 double p[]={1.5,.5,1,5,0,0,0,1},c[]={.13,-.21,.07},xyz[]={sin(i*.73)*2,cos(i*.27)*1.3,sin(i*.41)*1.7,1};
 if(i>=20){p[0]=i%2?-1.7:2.2;p[1]=i%9==0?-.5:(i%4+1)*.2;p[2]=i%3==0?-.7:1.2;p[3]=i%70;p[4]=-i%40;p[5]=i%110;p[6]=i%5==0?-.13:.17;p[7]=i%3-1;}
 char mem[256]={0},state[256]={0};char*v=mem+160;pd(v,-16,p[0]);double min=fmax(1e-40,p[1]);pd(v,-24,p[0]/(min*min));pd(v,-32,min*min);pd(v,-40,p[2]);matrix(v,p+3);pd(v,-84,p[6]);int mode=p[7];memcpy(v-88,&mode,4);for(int j=0;j<3;j++)pd(state,24+j*8,c[j]);
 for(int step=0;step<6;step++){
 double in[3];memcpy(in,xyz,24);xyz[3]=1;double before=step?0:NAN;if(step)memcpy(&before,state+200,8);surf_reference(xyz,v,state);double after;memcpy(&after,state+200,8);
 if(!isfinite(xyz[0])||!isfinite(xyz[1])||!isfinite(xyz[2]))break;
 fprintf(f,"{{%.17g,%.17g,%.17g},{%.17g,%.17g,%.17g},{",in[0],in[1],in[2],c[0],c[1],c[2]);for(int j=0;j<8;j++)fprintf(f,"%.17g,",p[j]);fprintf(f,"},%s",step?"":"NAN");if(step)fprintf(f,"%.17g",before);fprintf(f,",%.17g,%.17g,{%.17g,%.17g,%.17g}},\n",after,xyz[3],xyz[0],xyz[1],xyz[2]);
 }
}fputs("};\n",f);fclose(f);return 0;}
