/* Direct-distance formulas translated from Luca GN's original MB3D routines.
 * Scale/add updates the orbit before rotation; rotation applies only to the
 * local distance calculation, matching the SSE2/x87 implementations. */
static double difs_formula_values(Vec input,FormulaSlot f,const double v[16],Vec *next,double *scale,double *trap,int iteration){
    if(f.kind==101)return rand_cubes(input,f.parameters,next,scale,trap);
    if(f.kind==128){
        Vec p=add(mul(input,v[1]),(Vec){v[4],v[3],v[2]});int apply=v[6]!=0;*next=apply?p:input;if(apply)*scale*=v[1];
        int parallels=(int)clamp(v[7],2,1000);double step=2*v[0]/parallels;
        double angle=nearbyint((1.57079632675-atan2(p.x,p.y))*.159154943*v[8])/v[8]*6.283185307;
        double co=cos(angle),si=sin(angle),a=p.x*co+p.y*si,b=p.x*si-p.y*co;
        double d=hypot(hypot(a,p.z)-v[0],b)-v[5],z=fabs(p.z)-v[0],height=-v[0];
        for(int k=0;k<parallels/2;k++){z+=step;height+=step;double radius=sqrt(v[0]*v[0]-height*height);d=fmin(d,hypot(hypot(p.x,p.y)-radius,z)-v[5]);}
        return apply?d:d/v[1];
    }
    if(f.kind==126){
        Vec p=add(mul(input,v[3]),(Vec){v[6],v[5],v[4]});int apply=v[8]!=0;*next=apply?p:input;if(apply)*scale*=v[3];
        Vec q={fmax(0,fabs(p.x)-v[2]+v[7]),fmax(0,fabs(p.y)-v[1]+v[7]),fmax(0,fabs(p.z)-v[0]+v[7])};double d=sqrt(dot(q,q))-v[7];if(!apply)d/=v[3];
        double values[]={scene.de_stop*2.1345/(scene.zoom*fmax(16,scene.width)),next->x,next->y,next->z};*trap=values[(int)v[9]&3]*(float)v[11]+(float)v[10];return d;
    }
    if(f.kind==125){
        Vec p=add(mul(input,v[1]),(Vec){v[4],v[3],v[2]});int apply=v[8]!=0;*next=apply?p:input;if(apply)*scale*=v[1];
        double rx=1/v[7],ry=1/v[6],rz=1/v[5];double radius=sqrt(p.z*rz*p.z*rz+p.x*rx*p.x*rx+p.y*ry*p.y*ry);
        double d=fmax(radius-v[0],v[12]-radius)/fmax(fabs(rx),fmax(fabs(ry),fabs(rz)));if(!apply)d/=v[1];
        double values[]={scene.de_stop*2.1345/(scene.zoom*fmax(16,scene.width)),next->x,next->y,next->z};*trap=values[(int)v[9]&3]*(float)v[11]+(float)v[10];return d;
    }
    if(f.kind==123){
        Vec p=add(mul(input,v[1]),(Vec){v[4],v[3],v[2]});int apply=v[6]!=0;*next=apply?p:input;if(apply)*scale*=v[1];
        if(v[9]==1){double t=p.x;p.x=p.z;p.z=t;}else if(v[9]==-1){double t=p.y;p.y=p.z;p.z=t;}if(v[10]!=0)p.z=-p.z;
        double best=1e200;
        for(int i=0;i<3;i++){
            double radius=sqrt(p.x*p.x+p.y*p.y),q=v[0]*v[0]-radius*radius,root=sqrt(q+fabs(q));
            double angle=atan2(p.y-p.x,p.y+p.x)*v[11];
            double d=(fabs(v[0]*log((root+v[0])/radius)-root-angle-p.z)-v[7])*fabs(radius*.3+.02);
            d=fmax(d,radius-v[5]);d=fmax(d,v[8]-radius);d=fmax(d,-p.y);best=fmin(best,d);
            p.x=-p.x;p.y=-p.y;p.z+=v[11]*PI;
        }
        return apply?best:best/v[1];
    }
    if(f.kind==115){
        Vec p=add(mul(input,v[3]),(Vec){v[6],v[5],v[4]});*next=v[9]!=0?p:input;if(v[9]!=0)*scale*=v[3];
        double x=p.x,y=p.y;if((float)v[8]!=0){double angle=(float)v[8]*p.z,co=cos(angle),si=sin(angle);x=p.x*si+p.y*co;y=p.x*co-p.y*si;}
        double d=fmax(fabs(p.z)-v[0],fmax(fabs(x)-v[2]-p.z*v[7],fabs(y)-v[1]));if(v[9]==0)d/=v[3];
        double values[]={scene.de_stop*2.1345/(scene.zoom*fmax(16,scene.width)),next->x,next->y,next->z};*trap=values[(int)v[10]]*(float)v[12]+(float)v[11];return d;
    }
    if(f.kind==116){
        Vec p=formula_rotate(input,v+7,1);*next=input;double stop=scene.de_stop*2.1345/(scene.zoom*fmax(16,scene.width));if(fabs((float)v[6])+stop<fabs(p.z+(float)v[3]-(float)v[6]*.5))return (float)v[6]*.5-(float)v[3]-p.z;Vec color=height_map_sample((int)v[0],p.x*(float)v[4]-(float)v[1],p.y*(float)v[5]-(float)v[2]);
        return height_map_formula(input,v,color,stop,trap);
    }
    int apply=f.kind==112?v[5]!=0:v[6]!=0;
    Vec p=add(mul(input,v[1]),(Vec){v[4],v[3],v[2]});
    *next=apply?p:input;if(apply)*scale*=v[1];
    p=formula_rotate(p,v+7,1);double d;
    if(f.kind==111){
        double xy=p.x*p.x+p.y*p.y;
        double positive=xy*xy+fabs(p.z*p.z*p.z*v[0]),negative=0;
        double q=p.x*(p.x*p.x-3*p.y*p.y)*v[5];
        if(q>0)positive+=q;else negative=-q;
        d=fmax(.5*(sqrt(sqrt(positive))-sqrt(sqrt(negative))),fabs(p.z)-5);
        *trap=fabs(sqrt(dot(p,p))*v[10]+iteration*v[11]+v[12]);
    }else if(f.kind==113){
        double y=fabs(p.y-2*nearbyint(p.y*.5));
        double a=fabs(p.x*.866025-3*nearbyint(p.x*.288675))+y*.5;
        double x=fmin(y,fmax(y,a)-v[5]);
        d=sqrt(x*x+p.z*p.z)-v[0];
    }else if(f.kind==114){
        double x=p.x,y=p.y;
        switch((int)v[10]){
            case 1:{double k=1/(x*x+y*y);x*=k;y*=k;break;}
            case 2:{double k=1/(x*x+(y+1)*(y+1)),nx=(x*x+y*y-1)*k;y=-2*x*k;x=nx;break;}
            case 3:{double k=1/log2(x*x+y*y);x*=k;y*=k;break;}
            case 4:{double nx=sqrt(x*x+y*y);y=atan2(y,x);x=nx;break;}
        }
        double wave=sin(x*v[5])*sin(y*v[5]);
        *trap=(wave<0?v[11]:v[12])+iteration*v[13];
        d=fmax(-p.z,fmin(-p.z+v[0],wave*300/v[5]));
    }else{
        double radial=v[13]>0?sqrt(p.x*p.x+p.y*p.y):fmax(fabs(p.x),fabs(p.y));
        double a=atan2(p.y,p.x)*.1591549430918953358*v[10],cell=nearbyint(a);
        double u=(a-cell)*6.2831853071795864769/v[10];
        double half=-fabs(v[11])*.5,period=fabs(v[10]*v[11]);
        double z=p.z-cell*fabs(v[11]);z-=nearbyint(z/period)*period;
        if(signbit(v[11])){
            d=-u;if(-z>u-half)d=z-half;else if(-z<u+half)d=z+half;
            d=fmax(fabs(d)-v[12],fabs(radial-fabs(v[13]))-v[14]);
        }else{
            d=fmax(signbit(z)?u:-u,fabs(fabs(z)+half))-v[12];
            double r=radial-fabs(v[13]);d=fmin(r+v[14],fmax(r-v[14],d));
        }
        *trap=fabs(v[0]+iteration*v[6]);
    }
    return apply?d:d/v[1];
}

/* Standalone queries retain the uncached path. Render workers use immutable
 * values packed once from the current program. */
static double difs_formula(Vec input,FormulaSlot f,Vec *next,double *scale,double *trap,int iteration){double values[16]={0};for(int j=0;j<formula_parameter_count(f.kind);j++)values[j]=formula_slot_value(f,j);return difs_formula_values(input,f,values,next,scale,trap,iteration);}
