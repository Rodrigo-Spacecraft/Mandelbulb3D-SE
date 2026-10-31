/* RandCubesIFS, Luca GN (2012), translated from the shipped MB3D v6 routine.
   Integer arithmetic deliberately wraps at 32 bits; local cells use nearest-even. */
static int32_t rand_cell(double value) {double rounded=nearbyint(value);return isfinite(rounded)&&rounded>=INT32_MIN&&rounded<=INT32_MAX?(int32_t)rounded:INT32_MIN;}
static double rand_cubes(Vec input,const double v[13],Vec *next,double *scale,double *trap) {
    Vec p=add(mul(input,v[1]),(Vec){v[4],v[3],v[2]});
    if(v[6]!=0){*next=p;*scale*=v[1];}else *next=input;
    int32_t cellX=rand_cell(p.x),cellY=rand_cell(p.y);
    double x=fabs(p.x-cellX),y=fabs(p.y-cellY);
    uint32_t cx=(uint32_t)cellX,cy=(uint32_t)cellY;
    uint32_t a=cy^0xb641,b=cx^0x9d81;uint64_t product=(uint64_t)a*b;
    uint32_t seed=~(uint32_t)product,hy=(seed&0x5a5a)^((uint32_t)(product>>32)|0x5a5a),hx=(a|0x5a5a)^(b&0x5a5a);
    uint32_t n=(hy-(uint32_t)(int32_t)v[9])*hy+seed;hy=((n>>8)^(n<<8))&65535;
    n=(hx-(uint32_t)(int32_t)v[8])*hx+seed;hx=((n>>8)^(n<<8))&65535;
    uint32_t hz=((hx>>6)^(hy<<6))&65535,flight=(hx&0xaaaa)^(hy&0x5555);
    const double k=-6.86656e-6,h=-.45;
    double z=p.z-flight*k*v[12],vertical=fabs(z)+hz*k*v[7],d;
    *trap=hz*1.5e-5;int type=(int)((hx&64)?v[11]:v[10]);
    double bx=hx*k*v[0]+(1-v[0])*h,by=hy*k*v[5]+(1-v[5])*h;
    switch(type) {
        case 1:d=fmax(vertical,hypot(x,y)+bx-hy*k*v[5]*fabs(z));break;
        case 2:d=fmax(vertical,sqrt(fmax(0,x*x+y*y-z*z*hx*(-1.37331e-5)*v[0]))+by);break;
        case 3:d=fmax(vertical,fmax(x-hx*k*v[0]*fabs(z),y-hy*k*v[5]*fabs(z))+h);break;
        case 4:{if(hx>=hy){double t=x;x=y;y=t;}double w=z-hz*k*v[7];w=(w-fabs(w))*h;d=fmax(z,fmax(x+bx,hypot(y,w)+by));break;}
        case 5:{if(hx>=hy){double t=x;x=y;y=t;uint32_t u=hx;hx=hy;hy=u;}float a1=(float)fabs(hx*(-3.1e-6)*v[0]),b1=(float)(hy*(-10.3e-6)*v[5]);double w=z-hz*k*v[7];w=(w-fabs(w))*h;double q=w*w;d=fmax(z,sqrt(q+y*y+x*x+a1*b1*b1)+sqrt(sqrt(q+x*x))*b1);break;}
        case 6:{float b1=(float)(hy*(-10.3e-6)*v[5]);float a1=(float)(bx-b1);double xx=fmax(0,x+a1),yy=fmax(0,y+a1),zz=fmax(0,vertical+a1);d=.9*sqrt(xx*xx+yy*yy+zz*zz)+b1;break;}
        default:d=fmax(vertical,fmax(x+bx,y+by));break;
    }
    return v[6]!=0?d:d/v[1];
}
