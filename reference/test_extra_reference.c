#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef struct {double x,y,z;} Vec;
static Vec add(Vec a,Vec b){return (Vec){a.x+b.x,a.y+b.y,a.z+b.z};}static Vec mul(Vec a,double s){return (Vec){a.x*s,a.y*s,a.z*s};}
#define PI 3.14159265358979323846
#include "../extra_formulas.h"
extern void sierp_reference(void*,void*,void*),transform_reference(void*,void*,void*),sin_reference(void*,void*,void*);
static void pd(char *p,int o,double x){memcpy(p+o,&x,8);}static void pf(char *p,int o,double x){float f=x;memcpy(p+o,&f,4);}static void pi(char*p,int o,int x){memcpy(p+o,&x,4);}
static void matrix(char*k,int start,double *v,int single){double sx=sin(v[0]*PI/180),cx=cos(v[0]*PI/180),sy=sin(v[1]*PI/180),cy=cos(v[1]*PI/180),sz=sin(v[2]*PI/180),cz=cos(v[2]*PI/180);double m[]={cy*cz,-cy*sz,sy,sx*sy*cz+cx*sz,cx*cz-sx*sy*sz,-sx*cy,sx*sz-cx*sy*cz,cx*sy*sz+sx*cz,cx*cy};for(int i=0;i<9;i++)if(single)pf(k,start-i*4,m[i]);else pd(k,start-i*8,m[i]);}
int main(void){FILE *file=fopen("extra_vectors.h","w");assert(file);fprintf(file,"/* Golden orbit steps evaluated by original x86 formula code. */\nstatic const ExtraVector extra_vectors[]={\n");int total=0;
 for(int kind=102;kind<=104;kind++)for(int i=0;i<700;i++){
  double v[13]={0};double points[4]={sin(i*.37)*7,cos(i*.13)*5,sin(i*.27)*3,1},original[4];memcpy(original,points,sizeof points);char constants[512]={0},state[512]={0};char*k=constants+256;Vec expected;
  if(kind==102){v[0]=1.1+(i%13)*.2;v[1]=.5;v[2]=1.3;v[3]=-.4;for(int j=4;j<10;j++)v[j]=i%3?(i%100-50)*(j+1)*.31:0;v[10]=i%5?1.3:0;v[11]=i%7?.7:0;v[12]=i%2;for(int j=0;j<4;j++)pd(k,-16-j*8,v[j]);matrix(k,-44,v+4,1);matrix(k,-80,v+7,1);pd(k,-120,v[10]);pd(k,-128,v[11]);pi(k,-132,v[12]);sierp_reference(points,k,state);expected=sierpinski_full((Vec){original[0],original[1],original[2]},v);}
  else if(kind==103){v[0]=i%4;v[1]=.35;v[2]=2.7;v[3]=-.8;v[4]=-.2;pi(k,-12,v[0]);for(int j=1;j<5;j++)pf(k,-12-j*4,v[j]);pd(k,-8,.5);pd(k,0,.1591549430918953);pd(k,8,1.5707963267948966);pd(k,16,.1481481481481481);sin_reference(points,k,state);memcpy(&expected,original,sizeof expected);if(v[0]<3){double out=sine_approx(original[(int)v[0]],v);if(v[0]==0)expected.x=out;else if(v[0]==1)expected.y=out;else expected.z=out;}else assert(fabs(points[3]-sine_approx(original[3],v))<1e-10);}
  else {v[0]=i%2?-1.7:2.2;v[1]=.3;v[2]=-.4;v[3]=1.2;v[4]=i%90;v[5]=i%130;v[6]=-i%180;v[7]=i%2;for(int j=0;j<4;j++)pd(k,-16-j*8,v[j]);matrix(k,-48,v+4,0);pi(k,-116,v[7]);transform_reference(points,k,state);expected=transform_formula((Vec){original[0],original[1],original[2]},v);if(v[7])assert(!memcmp(points,state+24,24));}
  double e[]={expected.x,expected.y,expected.z};for(int j=0;j<3;j++)if(fabs(e[j]-points[j])>1e-10*(1+fabs(points[j]))){printf("kind%d i%d axis%d C %.17g ref %.17g\n",kind,i,j,e[j],points[j]);return 1;}
  if(i%49==0){fprintf(file,"{%d,{%.17g,%.17g,%.17g},{",kind,original[0],original[1],original[2]);for(int j=0;j<13;j++)fprintf(file,"%s%.17g",j?",":"",v[j]);fprintf(file,"},{%.17g,%.17g,%.17g}},\n",points[0],points[1],points[2]);}total++;
 }fprintf(file,"};\n");fclose(file);printf("%d formula steps match original x86 code.\n",total);
}
