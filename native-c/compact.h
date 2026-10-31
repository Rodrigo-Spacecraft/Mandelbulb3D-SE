/* Prepared native C formula calls. LGPL-2.1-or-later. */
#ifndef CN_COMPACT_H
#define CN_COMPACT_H
#include "runtime.h"
#ifndef CN_REC
#define CN_REC 0x10001000U
#endif
typedef struct {
    CN_Machine *machine;
    CN_U8 regs;
    double xyz[3],constant[3],fourth,derivative,scale,radius;
} CN_CompactContext;
typedef int (*CN_CompactFunction)(CN_CompactContext *,const unsigned char *,uint32_t);
typedef struct {CN_CompactFunction function;unsigned parameter_offset;uint64_t reads,writes;unsigned state;} CN_CompactPlan;
CN_CompactPlan cn_compact_lookup(const char *name);
#endif
