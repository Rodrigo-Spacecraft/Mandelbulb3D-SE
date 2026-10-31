#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
extern void makin4_reference(void*,void*,void*),cubicquat_reference(void*,void*,void*),lambda4_reference(void*,void*,void*);
int main(void){FILE *f=fopen("fourd_vectors.h","w");assert(f);fputs("/* Original MB3D x87 kernels, evaluated through x86-64 reference wrappers. */\nstatic const FourDVector fourd_vectors[]={\n",f);
for(int kind=118;kind<=120;kind++)for(int i=0;i<160;i++){
 double in[]={sin(i*.73+.1)*2,cos(i*.27)*1.3,sin(i*.41)*1.7,cos(i*.13)},c[]={sin(i*.17),cos(i*.23),sin(i*.31)},v[7]={0},out[4];memcpy(out,in,sizeof out);char constants[256]={0},block[256]={0};char *vars=constants+128,*state=block+128;
 for(int j=0;j<3;j++)memcpy(state+24+j*8,c+j,8);
 for(int j=0;j<7;j++){v[j]=sin(i*.11+j)*1.4;memcpy(vars-16-j*8,v+j,8);}
 if(kind==118)makin4_reference(out,vars,state);else if(kind==119)cubicquat_reference(out,vars,state);else lambda4_reference(out,vars,state);
 fprintf(f,"{%d,{",kind);for(int j=0;j<4;j++)fprintf(f,"%.17g,",in[j]);fputs("},{",f);for(int j=0;j<3;j++)fprintf(f,"%.17g,",c[j]);fputs("},{",f);for(int j=0;j<7;j++)fprintf(f,"%.17g,",v[j]);fputs("},{",f);for(int j=0;j<4;j++)fprintf(f,"%.17g,",out[j]);fputs("}},\n",f);
}fputs("};\n",f);fclose(f);return 0;}
