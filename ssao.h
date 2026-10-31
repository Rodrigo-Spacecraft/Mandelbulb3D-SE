/* AmbHiQ.pas: 24-bit depth, a-trous levels, 32 horizon directions and
 * threshold-compressed slopes. Random jitter is reproducible across threads.
 */
typedef struct {atomic_int row;uint32_t *depth,*base;int16_t *horizons;int level,levels,pass,random;double scale,threshold,multiplier;float directions[32][2];} SSAOJob;
static int ssao_border(int x,int size,double mirror){
    if(x<0){x=-x;if(x>=(int)lrint(size*mirror))return -1;}
    else if(x>=size){x=2*(size-1)-x;if(x<size-1-(int)lrint(size*mirror))return -1;}
    return x>=0&&x<size?x:-1;
}
static void *ssao_worker(void *argument){
    SSAOJob *j=argument;int w=scene.width,h=scene.height,y,step=1<<(j->level-1);double radius=step<2?1:3.25*step;int steps=step<2?5:3;
    double threshold=scene.ssao.threshold*.7*4096/j->scale*pow(j->levels/(double)j->level,.25),compression=j->scale*threshold;
    while((y=atomic_fetch_add(&j->row,1))<h&&!render_cancelled()){
        for(int x=0;x<w;x++){
            size_t n=(size_t)y*w+x;if(!surface_cache.pixels[n].hit)continue;int16_t *maxima=j->horizons+n*32;uint32_t seed=(uint32_t)(n*747796405u+j->pass*2891336453u+j->level*277803737u);
            for(int d=0;d<32;d++){
                double sx=j->directions[d][0]*radius,sy=j->directions[d][1]*radius;if(j->random){sx-=(step-1)*.5;sy-=(step-1)*.5;}
                for(int k=0;k<steps;k++){
                    int dx=(int)lrint(sx),dy=(int)lrint(sy);seed=214013u*seed+2531011u;
                    if(j->random){dx+=(seed>>16)&(step-1);dy+=(seed>>10)&(step-1);}
                    double distance=j->random?hypot(dx,dy):radius+k*step+.1;if(distance<=0)continue;
                    int xx=ssao_border(x+dx,w,scene.ssao.mirror),yy=ssao_border(y+dy,h,scene.ssao.mirror);if(xx<0||yy<0)break;
                    double slope=((double)j->depth[(size_t)yy*w+xx]-j->base[n])/distance;
                    int value=(int)lrint(clamp(slope*compression/(threshold+fabs(slope)),-32768,32767));if(value>maxima[d])maxima[d]=(int16_t)value;
                    sx+=j->directions[d][0]*step;sy+=j->directions[d][1]*step;
                }
            }
            if(j->level==j->levels){double sum=0;for(int d=0;d<32;d++)if(maxima[d]>-32768)sum+=atan(maxima[d]/4096.);
                double occlusion=clamp(lrint(sum*j->multiplier),0,16383/(double)scene.ssao.samples)/16383.;
                surface_cache.pixels[n].ambient_visibility=fmax(0,surface_cache.pixels[n].ambient_visibility-occlusion);
            }
        }
    }return NULL;
}
static void ssao_run(SSAOJob *j,int threads){atomic_init(&j->row,0);pthread_t workers[255];int count=0;for(int i=1;i<threads&&i<scene.height;i++){if(pthread_create(workers+count,NULL,ssao_worker,j))break;count++;}ssao_worker(j);for(int i=0;i<count;i++)pthread_join(workers[i],NULL);}
static int calculate_ssao(int threads){
    int w=scene.width,h=scene.height;size_t count=(size_t)w*h;
    uint32_t *base=malloc(count*4),*depth=malloc(count*4),*temp=malloc(count*4);int16_t *horizons=malloc(count*32*sizeof(int16_t));
    if(!base||!depth||!temp||!horizons){free(base);free(depth);free(temp);free(horizons);return 0;}
    double pixel=2.1345/(scene.zoom*w),zc=sin(fmax(scene.fov*PI/180,1)/h),zm=8388352/(sqrt((scene.zend-scene.zstart)*zc/pixel+1)-.999999999);
    double factor=(pow(256/zm+1,2)-1)/zc;
    int levels=1,span=5,diagonal=(int)lrint(hypot(w,h)*.5);do{levels++;span*=2;}while(levels<15&&span<=diagonal);
    SSAOJob job={.depth=depth,.base=base,.horizons=horizons,.levels=levels,.random=scene.shadows.ambient_method==3,.scale=factor/22000*4096};
    job.multiplier=1.5*32767/(PI*32*pow(atan(scene.ssao.threshold*(job.random?.65:.6)*pow(levels,.25)),.9))/scene.ssao.samples;
    for(int d=0;d<32;d++){job.directions[d][0]=sin(d*PI/16);job.directions[d][1]=cos(d*PI/16);}
    for(size_t n=0;n<count;n++){SurfacePixel *s=surface_cache.pixels+n;uint32_t z=(uint32_t)lrint(clamp(8388352-zm*(sqrt(s->depth*zc/pixel+1)-1),0,8388352));base[n]=s->hit?z<<7:0;s->ambient_visibility=1;}
    for(int pass=0;pass<scene.ssao.samples&&!render_cancelled();pass++){
        memcpy(depth,base,count*4);for(size_t n=0;n<count*32;n++)horizons[n]=-32768;job.pass=pass;
        for(int level=1;level<=levels&&!render_cancelled();level++){
            if(level>1){int step=1<<(level-1);for(int y=0;y<h;y++)for(int x=0;x<w;x++){int a=x-step,b=x+step;if(a<0)a=0;if(b>=w)b=w-1;temp[(size_t)y*w+x]=(depth[(size_t)y*w+x]+((depth[(size_t)y*w+a]+depth[(size_t)y*w+b])>>1))>>1;}
                for(int y=0;y<h;y++)for(int x=0;x<w;x++){int a=y-step,b=y+step;if(a<0)a=0;if(b>=h)b=h-1;depth[(size_t)y*w+x]=(temp[(size_t)y*w+x]+((temp[(size_t)a*w+x]+temp[(size_t)b*w+x])>>1))>>1;}}
            job.level=level;ssao_run(&job,threads);
        }
    }
    free(base);free(depth);free(temp);free(horizons);return !render_cancelled();
}
