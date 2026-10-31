/* Editor ranges are deliberately independent from import/render ranges. */
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include "formula_binary_parameters.h"
static int formulaBinaryUIParameter(int kind,int index){
    const FormulaParameter *p=formula_parameter(kind,index);if(!p||!p->integer)return 0;
    if(!strcasecmp(p->name,"Apply scale+add")||!strcasecmp(p->name,"Sphere or Cylinder"))return 1;
    const char *name=formula_name(kind);
    for(size_t i=0;i<sizeof formula_binary_parameters/sizeof *formula_binary_parameters;i++)if(!strcasecmp(name,formula_binary_parameters[i][0])&&!strcasecmp(p->name,formula_binary_parameters[i][1]))return 1;
    return 0;
}
static double formulaUIDisplayValue(int kind,int index,double value){
    if(!strcasecmp(formula_name(kind),"General")&&index>=7&&index<=9&&(value< -1||value>1))return 1;
    return formulaBinaryUIParameter(kind,index)&&(value<0||value>1)?1:value;
}
/* Explicit integer ranges in formula labels describe the editor domain. */
static int formulaNamedIntegerRange(const char *name,double *minimum,double *maximum){
    for(const char *q=name;*q;q++){
        if(!isdigit((unsigned char)*q)&&!(*q=='-'&&isdigit((unsigned char)q[1])))continue;
        char *end;long lo=strtol(q,&end,10);const char *sep=end;
        while(isspace((unsigned char)*sep))sep++;
        if(!strncasecmp(sep,"to",2)){sep+=2;}
        else if(*sep=='-'){sep++;}
        else if(sep[0]=='.'&&sep[1]=='.'){while(*sep=='.')sep++;}
        else continue;
        while(isspace((unsigned char)*sep))sep++;
        char *last;long hi=strtol(sep,&last,10);
        if(last==sep||lo>=hi||lo<INT_MIN||hi>INT_MAX)continue;
        *minimum=(double)lo;*maximum=(double)hi;return 1;
    }return 0;
}
static FormulaParameter formulaUIParameter(int kind,int index){
    FormulaParameter p=*formula_parameter(kind,index);
    if(p.integer)formulaNamedIntegerRange(p.name,&p.minimum,&p.maximum);
    if(formulaBinaryUIParameter(kind,index)){p.minimum=0;p.maximum=1;p.integer=1;p.default_value=formulaUIDisplayValue(kind,index,p.default_value);}
    if(!strcasecmp(formula_name(kind),"General")){
        if(index==3||index==5){p.minimum=0;p.maximum=23;}
        else if(index==4||index==6){p.minimum=0;p.maximum=3;}
        else if(index>=7&&index<=9){p.minimum=-1;p.maximum=1;}
        else if(index==10){p.minimum=0;p.maximum=2;}
    }
    return p;
}

/* Navigator.pas RxSlider1Change: slider positions -60..60, with
   divisors 10240, 640, 40, 2 (the original uses an integer shift). */
static double navigatorFormulaRadius(int kind,int index,int range){
 double divisor=(640*16)>>(range*4);
 const FormulaParameter *p=formula_parameter(kind,index);
 if(p->integer)divisor=fmax(3,fmin(50,divisor*.5));
 return 60*(formula_parameter_is_angle(kind,index)?15:1)/divisor;
}
