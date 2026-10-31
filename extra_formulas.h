/* Portable translations of the original MB3D formula routines. */
static Vec formula_rotate(Vec p,const double *angles,int singles) {
    if(angles[0]==0&&angles[1]==0&&angles[2]==0)return p;
    /* Hybrid programs often alternate several rotations. Retain each matrix
     * instead of rebuilding trigonometry whenever the preceding slot differs. */
    typedef struct {int precision;double angles[3],matrix[9];} RotationCache;
    static _Thread_local RotationCache cache[32];static _Thread_local unsigned used,last,next;
    RotationCache *entry=NULL;
    if(used&&cache[last].precision==singles&&!memcmp(cache[last].angles,angles,3*sizeof(double)))entry=&cache[last];
    else for(unsigned i=0;i<used;i++)if(cache[i].precision==singles&&!memcmp(cache[i].angles,angles,3*sizeof(double))){entry=&cache[i];last=i;break;}
    if(entry){const double *m=entry->matrix;return (Vec){p.x*m[0]+p.y*m[1]+p.z*m[2],p.x*m[3]+p.y*m[4]+p.z*m[5],p.x*m[6]+p.y*m[7]+p.z*m[8]};}
    double sx=sin(angles[0]*PI/180),cx=cos(angles[0]*PI/180),sy=sin(angles[1]*PI/180),cy=cos(angles[1]*PI/180),sz=sin(angles[2]*PI/180),cz=cos(angles[2]*PI/180);
    double m[]={cy*cz,-cy*sz,sy,sx*sy*cz+cx*sz,cx*cz-sx*sy*sz,-sx*cy,sx*sz-cx*sy*cz,cx*sy*sz+sx*cz,cx*cy};
    if(singles)for(int i=0;i<9;i++)m[i]=(float)m[i];
    unsigned index=used<32?used++:next++%32;entry=&cache[index];memcpy(entry->matrix,m,sizeof entry->matrix);memcpy(entry->angles,angles,sizeof entry->angles);entry->precision=singles;last=index;
    return (Vec){p.x*m[0]+p.y*m[1]+p.z*m[2],p.x*m[3]+p.y*m[4]+p.z*m[5],p.x*m[6]+p.y*m[7]+p.z*m[8]};
}
static void formula_swap(double *a,double *b){double t=*a;*a=*b;*b=t;}
static Vec tetra_sort(Vec p){formula_swap(&p.x,&p.y);if(p.x<p.y)formula_swap(&p.x,&p.y);if(p.x<p.z)formula_swap(&p.x,&p.z);formula_swap(&p.x,&p.y);if(p.x<p.z)formula_swap(&p.x,&p.z);return p;}
static Vec tetra_signed(Vec p){p.x=-p.x;if(p.x>=p.y)formula_swap(&p.x,&p.y);if(p.x>=p.z)formula_swap(&p.x,&p.z);p.x=-p.x;formula_swap(&p.x,&p.y);p.x=-p.x;if(p.x>=p.z)formula_swap(&p.x,&p.z);p.x=-p.x;return p;}
static Vec sierpinski_full(Vec p,const double *v){
    p=formula_rotate(p,v+4,1);
    /* Preserve the original routine's fold order and coordinate permutations. */
    p=v[12]!=0?tetra_sort(tetra_signed(p)):tetra_signed(tetra_sort(p));
    if(v[10]>0)p.y=v[10]-fabs(v[10]-p.y);
    if(v[11]>0)p.x=v[11]-fabs(v[11]-p.x);
    p=formula_rotate(p,v+7,1);
    return (Vec){p.x*v[0]-(v[0]-1)*v[1],p.y*v[0]-(v[0]-1)*v[2],p.z*v[0]-(v[0]-1)*v[3]};
}
static double sine_approx(double a,const double *v){
    /* Original constants and float-valued user options, not libc sin(). */
    double t=(a-(float)v[1])*(float)v[2]*.1591549430918953;
    double x=2*(t-nearbyint(t-.5));int negative=0;
    if(x>1){x=2-x;negative^=1;}x*=PI;
    if(x>=1.5707963267948966){x-=PI;negative^=1;}
    double result=x-.1481481481481481*x*x*x;
    return (negative?-result:result)*(float)v[3]+(float)v[4];
}
static Vec transform_formula(Vec z,const double *v){return mul(formula_rotate(add(z,(Vec){v[1],v[2],v[3]}),v+4,0),v[0]);}

static Vec benesi3_pow2(Vec z,Vec c) {
    double yz=z.y*z.y+z.z*z.z;
    double nextX=z.x*z.x-yz;
    if(!(c.x<0||z.x<sqrt(yz)))nextX=-nextX;
    double factor=yz>0?-2*fabs(z.x)/sqrt(yz):0;
    return (Vec){nextX+c.x,factor*(z.y*z.y-z.z*z.z)+c.y,factor*2*z.y*z.z+c.z};
}
static double sine_y(double a,const double *v) {
    return sin((a-(float)v[1])*(float)v[2])*(float)v[3]+(float)v[4];
}

/* Match _toruspinv3's executable x87 code: no square root in rho,
 * and Z is multiplied by rho whereas X/Y are divided by it. */
static Vec torus_pinv3(Vec z,const double *v){
    z=add(z,(Vec){v[0],v[1],v[2]});
    double t=v[4]-(z.x*z.x+z.y*z.y),rho=t*t+z.z*z.z;
    return (Vec){fabs(z.x)/rho*v[3]-v[0],fabs(z.y)/rho*v[3]-v[1],fabs(z.z)*rho*v[3]-v[2]};
}

static Vec amazing_surf(Vec z,Vec c,const double *v,double *scale,double *factor){
    if(isnan(*scale))*scale=v[0];
    *scale+=v[6]*(fabs(*scale)-1);
    z.x=fabs(z.x+v[2])-fabs(z.x-v[2])-z.x;
    z.y=fabs(z.y+v[2])-fabs(z.y-v[2])-z.y;
    double rr=z.x*z.x+z.y*z.y+(v[7]==0?z.z*z.z:0);
    double minR=fmax(1e-40,v[1]),minSq=minR*minR;
    *factor=rr<minSq?v[0]/minSq:rr<=1?*scale/rr:*scale;
    return formula_rotate(add(mul(z,*factor),c),v+3,1);
}

/* Stereographic projection, dihedral rational map, inverse projection.
 * Counts 0 and 1 both execute once, as in the original do/while loops. */
static Vec tglad_dihed(Vec z,Vec c,const double *v){
    for(int outer=0;outer<(v[0]>1?(int)v[0]:1);outer++){
        long double xy=(long double)z.x*z.x+(long double)z.y*z.y;
        long double rr=xy+(long double)z.z*z.z;
        if(rr==0)return c;
        if(rr>=1e10)return (Vec){1e10,1e10,1e10};
        double radius=sqrtl(rr),height=z.z/sqrtl(rr);
        double t=(sqrtl(xy)-z.y)/z.x,t2=(long double)t*t;
        long double a=sqrtl((1-(long double)height)/(1+(long double)height))/(1+(long double)t2);
        z.x=2*a*t;z.y=(1-(long double)t2)*a;
        for(int inner=0;inner<(v[1]>1?(int)v[1]:1);inner++){
            long double j=(long double)z.x*z.x+(long double)z.y*z.y;
            if(j>=1e10)return (Vec){1e10,1e10,1e10};
            double jd=j;
            double ni=-(long double)z.y*(jd+1.L)*(jd-2.L*z.x-1)*(jd+2.L*z.x-1);
            double nr=(long double)z.x*(jd-1.L)*((long double)jd*jd+2.L*jd+4.L*z.y*z.y+1);
            long double den=(jd-2.L*z.y+1)*(jd+2.L*z.y+1),factor=2/(den*den);
            z.x=factor*nr;z.y=factor*ni;radius=(long double)radius*radius;
            if(radius==0)return c;
        }
        double j=(long double)z.x*z.x+(long double)z.y*z.y,root=sqrtl(j);
        t=(sqrtl(j)-z.y)/z.x;t2=(long double)t*t;
        double inv=1/(1+(long double)t2),oy=(1-(long double)t2)*inv,ox=2*(long double)t*inv;
        double d=2/(1+(long double)j),radial=(long double)d*root;
        z=(Vec){(long double)radius*ox*radial,(long double)radius*oy*radial,(d-1.L)*radius};
    }
    return add(z,c);
}

/* Four-dimensional kernels. W is the fourth orbit component; the current
 * Navigator exposes Cx/Cy/Cz and uses the original default Cw=0. */
static Vec makin4_p4b(Vec z,Vec c,double *w,const double *v){
    for(int pass=0;pass<2;pass++){double x=z.x,y=z.y,a=z.z,b=*w,m=x*x+y*y+a*a+b*b;
        double nextZ=2*(x*a-y*b),nextW=2*(x*b+y*a),nextX=2*(x*x-y*y),nextY=4*x*y,n=hypot(nextX,nextY);
        double factor=n>1e-300?1-m/n:0;z=(Vec){nextX*factor,nextY*factor,nextZ};*w=nextW;
    }*w+=v[0];return add(z,c);
}
static Vec cubic_quat(Vec z,Vec c,double *w,const double *v){
    double x=z.x,y=z.y,zz=z.z,ww=*w;*w=2*v[3]*x*ww+v[4];
    return (Vec){v[0]*x*x-(v[1]*y*y+v[2]*zz*zz+v[3]*ww*ww)+c.x+c.y*v[5],2*v[1]*x*y+c.y+c.x*v[6],2*v[2]*x*zz+c.z};
}
static Vec lambda4_cw(Vec z,Vec c,double cw,double *w,const double *v){
    double x=z.x,y=z.y,zz=z.z,ww=*w;
    double a=v[0]-x*x+y*y+zz*zz-ww*ww,b=v[1]-2*x*y+2*zz*ww,d=v[2]-2*x*zz+2*y*ww,e=v[3]-2*x*ww-2*y*zz;
    *w=e*c.x+d*c.y+b*c.z+a*cw;return (Vec){a*c.x-b*c.y-d*c.z+e*cw,b*c.x+a*c.y-e*c.z-d*cw,d*c.x-e*c.y+a*c.z-b*cw};
}

static double menger_smooth_abs(double x,double smoothing){
    if(smoothing>=0)return sqrt(x*x+smoothing);double square=x*x;return square>0?fabs(x)*square/(square-smoothing):0;
}
static void menger_smooth_sort(double *a,double *b,double smoothing){double d=*a-*b,t=.5*(d-menger_smooth_abs(d,smoothing));*a-=t;*b+=t;}
static Vec menger_smt(Vec z,const double *v){
    z=(Vec){menger_smooth_abs(z.x,v[7]),menger_smooth_abs(z.y,v[7]),menger_smooth_abs(z.z,v[7])};
    menger_smooth_sort(&z.x,&z.y,v[8]);menger_smooth_sort(&z.x,&z.z,v[8]);menger_smooth_sort(&z.y,&z.z,v[8]);z=formula_rotate(z,v+4,1);
    double scale=v[0],minus=scale-1,center=scale!=0?v[3]*minus/scale:0;
    return (Vec){scale*z.x-v[1]*minus,scale*z.y-v[2]*minus,scale*(center-menger_smooth_abs(z.z-center,v[7]))};
}
static double reciprocal_y3b(double y,const double *v){
    double result=1/fmax(1e-40,v[0])-1/(fabs(y*v[2])+v[0])+1/fmax(1e-40,v[1])-1/(fabs(y*y*v[3])+v[1]);return signbit(y)?-result:result;
}

/* Original DEoption 21: a dIFS orbit transform, not a distance primitive. */
static Vec apollo_2d(Vec z,const double *v,double *scale){
    double x=z.x*v[7]+v[0],y=z.y*v[7],cell=nearbyint(-atan2(y,x)*.159154943*v[6]);
    double angle=cell/v[6]*6.283185307,co=cos(angle),si=sin(angle);
    Vec folded={x*co-y*si,y*co+x*si,z.z};if(fmod(fabs(cell),2)==0)folded.y=-folded.y;folded.x+=v[1];
    Vec rotated=formula_rotate(folded,v+3,1);x=-rotated.y;y=rotated.x;double rr=x*x+y*y,den=v[7]*(rr+1+2*y);
    *scale*=fabs(v[2]);return (Vec){(rr-1)/den+v[8],-2*x/den,rotated.z*v[2]};
}

static Vec amazing_ifs(Vec z,const double *v,double *dr){
    z=(Vec){fabs(z.x+v[6])-fabs(z.x-v[6])-z.x,fabs(z.y+v[7])-fabs(z.y-v[7])-z.y,fabs(z.z+v[8])-fabs(z.z-v[8])-z.z};
    z=formula_rotate(add(z,(Vec){v[0],v[1],v[2]}),v+3,1);double r2=dot(z,z);
    if(r2<1){double factor=fmin(1/r2,v[9]);z=mul(z,factor);*dr=fabs(*dr*factor);}return z;
}

static Vec transform_ifs(Vec z,const double *v,double *dr){
    z=formula_rotate(add(mul(z,v[9]),(Vec){v[0],v[1],v[2]}),v+3,1);*dr*=v[9];
    if(v[6]!=0)z.x=fabs(z.x);if(v[7]!=0)z.y=fabs(z.y);if(v[8]!=0)z.z=fabs(z.z);return z;
}

static Vec lincombine_xyz(Vec p,const double *v){
    return (Vec){p.x*v[0]+p.y*v[1]+p.z*v[2],p.x*v[3]+p.y*v[4]+p.z*v[5],p.x*v[6]+p.y*v[7]+p.z*v[8]};
}
/* Math3D.BuildRotMatrix4d: six plane rotations, rounded to single precision
 * after each matrix product, just like the original option expansion. */
static const float *mixpinski_rotation(const double *angles){
    static _Thread_local int ready;static _Thread_local double saved[6];static _Thread_local float matrix[16];
    if(ready&&!memcmp(saved,angles,sizeof saved))return matrix;
    memset(matrix,0,sizeof matrix);for(int i=0;i<4;i++)matrix[i*4+i]=1;
    const int first[]={1,0,0,0,1,2},second[]={2,2,1,3,3,3};
    for(int k=0;k<6;k++){
        float rotation[16]={0},next[16];for(int i=0;i<4;i++)rotation[i*4+i]=1;
        int a=first[k],b=second[k];float s=sin(angles[k]*PI/180),c=cos(angles[k]*PI/180);
        rotation[a*4+a]=rotation[b*4+b]=c;rotation[a*4+b]=-s;rotation[b*4+a]=s;
        for(int i=0;i<4;i++)for(int j=0;j<4;j++){double sum=0;for(int n=0;n<4;n++)sum+=(double)rotation[i*4+n]*matrix[n*4+j];next[i*4+j]=(float)sum;}
        memcpy(matrix,next,sizeof matrix);
    }
    memcpy(saved,angles,sizeof saved);ready=1;return matrix;
}
static Vec mixpinski4ex(Vec z,double *w,const double *v){
    double a[]={z.x,z.y,z.z,*w};
    /* Original six signed pair folds, including its coordinate permutations. */
    a[0]=-a[0];if(a[0]>=a[1])formula_swap(a,a+1);if(a[0]>=a[2])formula_swap(a,a+2);a[0]=-a[0];formula_swap(a,a+1);
    a[0]=-a[0];if(a[0]>=a[2])formula_swap(a,a+2);a[0]=-a[0];formula_swap(a,a+1);
    a[0]=-a[0];if(a[0]>=a[3])formula_swap(a,a+3);a[0]=-a[0];formula_swap(a,a+1);
    a[0]=-a[0];if(a[0]>=a[3])formula_swap(a,a+3);a[0]=-a[0];formula_swap(a,a+1);formula_swap(a,a+2);
    a[0]=-a[0];if(a[0]>=a[3])formula_swap(a,a+3);a[0]=-a[0];formula_swap(a,a+2);
    a[0]+=v[12];a[1]+=v[11];a[2]+=v[13];a[3]+=v[14];
    const float *m=mixpinski_rotation(v+5);double r[4];
    for(int i=0;i<4;i++)r[i]=a[0]*m[i*4]+a[1]*m[i*4+1]+a[2]*m[i*4+2]+a[3]*m[i*4+3];
    double scale=v[0],minus=scale-1;
    *w=(r[3]-v[14])*scale-minus*v[4];
    double x=(r[1]-v[11])*scale-minus*v[1],y=(r[0]-v[12])*scale-minus*v[2];
    /* This division is present in the original executable (Scale=0 is singular). */
    double zz=(r[2]-v[13])-minus/scale*v[3];
    return (Vec){x,y,minus*v[3]-fabs(zz)*scale};
}

/* Original _PolyFold-sym uses nearest-even sector rounding and mirrors
 * alternate sectors. Constants retain the precision stored in the .m3f. */
static Vec polyfold_sym(Vec z,const double *v){
    double x=z.x+v[2],y=z.y+v[3],tau=6.283185307,rad=.017453293;
    double sector=nearbyint((atan2(y,x)+(v[4]+v[1])*rad)/tau*v[0]);
    double angle=-sector/v[0]*tau+v[1]*rad,c=cos(angle),s=sin(angle);
    double yy=x*s+y*c;if(fmod(fabs(sector),2)==0)yy=-yy;
    return (Vec){y*s-x*c-v[2],yy-v[3],z.z};
}
