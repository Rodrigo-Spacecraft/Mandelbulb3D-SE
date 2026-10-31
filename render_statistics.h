/* Private C instrumentation. Each worker counts in TLS; aggregation happens
   once on worker exit, never with a contended atomic per formula/evaluation. */
static RenderStatistics info_total;
static pthread_mutex_t info_lock=PTHREAD_MUTEX_INITIALIZER;
static _Thread_local RenderStatistics info_local;
static _Thread_local int info_phase;
static double info_clock(void){struct timespec t;clock_gettime(CLOCK_MONOTONIC,&t);return t.tv_sec+t.tv_nsec*1e-9;}
static void info_flush(int *unused){(void)unused;pthread_mutex_lock(&info_lock);
    for(int i=0;i<8;i++){info_total.evaluations[i]+=info_local.evaluations[i];info_total.formula_calls[i]+=info_local.formula_calls[i];}
    info_total.rays+=info_local.rays;info_total.steps+=info_local.steps;info_total.hits+=info_local.hits;info_total.capped_rays+=info_local.capped_rays;
    if(info_local.max_steps>info_total.max_steps)info_total.max_steps=info_local.max_steps;
    pthread_mutex_unlock(&info_lock);memset(&info_local,0,sizeof info_local);
}
static void info_restore(int *old){info_phase=*old;}
#define INFO_PHASE(n) int info_old __attribute__((cleanup(info_restore)))=info_phase; info_phase=(n)
#define INFO_WORKER int info_worker __attribute__((cleanup(info_flush)))=0
static void info_ray(unsigned n,int hit,int capped){info_local.rays++;info_local.steps+=n;info_local.hits+=hit;info_local.capped_rays+=capped;if(n>info_local.max_steps)info_local.max_steps=n;}
