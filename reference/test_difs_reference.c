#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#define PI 3.14159265358979323846
extern void trifoliumIFS_reference(void*,void*),helistairsIFS_reference(void*,void*),hextgrid2IFS_reference(void*,void*),boardIFS_reference(void*,void*);
static void pd(char*p,int n,double v){memcpy(p+n,&v,8);}static void pf(char*p,int n,float v){memcpy(p+n,&v,4);}static void pi(char*p,int n,int v){memcpy(p+n,&v,4);}static double gd(char*p,int n){double v;memcpy(&v,p+n,8);return v;}
static void matrix(char*k,double*v){double sx=sin(v[0]*PI/180),cx=cos(v[0]*PI/180),sy=sin(v[1]*PI/180),cy=cos(v[1]*PI/180),sz=sin(v[2]*PI/180),cz=cos(v[2]*PI/180);double m[]={cy*cz,-cy*sz,sy,sx*sy*cz+cx*sz,cx*cz-sx*sy*sz,-sx*cy,sx*sz-cx*sy*cz,cx*sy*sz+sx*cz,cx*cy};for(int i=0;i<9;i++)pf(k,-80-i*4,m[i]);}
int main(void){FILE*f=fopen("difs_vectors.h","w");assert(f);fputs("/* Golden results from original MB3D SSE2/x87 routines. */\nstatic const DifsVector difs_vectors[]={\n",f);
for(int kind=111;kind<=114;kind++)for(int i=0;i<320;i++){
 double v[16]={0},p[]={sin(i*.73)*4,cos(i*.27)*3,sin(i*.41)*2},scale=1.3,trap=.123;int its=i%40;
 v[0]=kind==111?16:kind==112?0:kind==113?.2:.1;v[1]=kind==114?1:2;v[2]=kind==114?-.1:0;v[4]=kind==111?3:0;
 if(kind==111){v[5]=1;v[6]=1;v[10]=v[11]=.1;v[12]=-1;}
 if(kind==112){v[6]=.25;v[10]=9;v[11]=-.35;v[12]=.05;v[13]=1;v[14]=.45;}
 if(kind==113){v[5]=1;v[6]=1;}
 if(kind==114){v[5]=2;v[11]=1;v[13]=.1;v[10]=i%5;}
 if(i>=20){v[0]=sin(i*.13)*(kind==111?20:1);v[1]=i%7==0?-1.7:1.3;v[2]=-.3;v[3]=.2;v[4]=-.1;v[7]=i%60;v[8]=-i%90;v[9]=i%120;
 if(kind==111){v[5]=sin(i*.19)*3;v[6]=i%2;v[10]=.17;v[11]=-.23;v[12]=.3;}
 if(kind==112){v[5]=i%2;v[10]=i%13+1;v[11]=(i%4<2?1:-1)*(.05+i%9*.07);v[12]=.07;v[13]=i%3?1.2:-1.1;v[14]=.35;}
 if(kind==113){v[5]=sin(i*.23)*2;v[6]=i%2;}
 if(kind==114){v[5]=1.1+i%13*.3;v[6]=i%2;v[11]=-.3;v[12]=.7;v[13]=.17;}
 }
 char mem[512]={0},block[512]={0};char*k=mem+256,*state=block+160;
 pd(k,-16,v[0]);pd(k,-24,v[1]);pd(k,-32,v[1]);pd(k,-40,v[2]);pd(k,-48,v[2]);pd(k,-56,v[3]);pd(k,-64,v[4]);
 if(kind==112){pi(k,-68,v[5]);pd(k,-76,v[6]);pi(k,-116,v[10]);for(int j=11;j<=14;j++)pd(k,-124-(j-11)*8,v[j]);double c[]={PI/2,1/(2*PI),2*PI,.5,.5};for(int j=0;j<5;j++)pd(k,j*8,c[j]);}
 else{pd(k,-72,v[5]);pi(k,-76,v[6]);if(kind==111){pd(k,-120,v[10]);pd(k,-128,v[11]);pd(k,-136,v[12]);pd(k,0,-3);pd(k,8,.5);pd(k,16,5);}if(kind==113){double c[]={-2,.5,.866025,-3,.288675};for(int j=0;j<5;j++)pd(k,j*8,c[j]);}if(kind==114){pi(k,-116,v[10]);pd(k,-124,v[11]);pd(k,-132,v[12]);pd(k,-140,v[13]);pd(k,0,300);}}
 matrix(k,v+7);for(int j=0;j<3;j++)pd(state,-120+j*8,p[j]);pd(state,112,scale);pd(state,128,trap);pi(state,-24,its);
 if(kind==111)trifoliumIFS_reference(k,state);if(kind==112)helistairsIFS_reference(k,state);if(kind==113)hextgrid2IFS_reference(k,state);if(kind==114)boardIFS_reference(k,state);
 double d=gd(state,-32),outTrap=gd(state,128);assert(isfinite(d)&&isfinite(outTrap));
 fprintf(f,"{%d,{%.17g,%.17g,%.17g},{",kind,p[0],p[1],p[2]);for(int j=0;j<16;j++)fprintf(f,"%.17g,",v[j]);fprintf(f,"},%d,%.17g,%.17g,%.17g,{%.17g,%.17g,%.17g}},\n",its,d,gd(state,112),outTrap,gd(state,-120),gd(state,-112),gd(state,-104));
}fputs("};\n",f);fclose(f);return 0;}
