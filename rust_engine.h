/* Private C ABI for the locally copied Rust engine. LGPL-2.1-or-later. */
#ifndef MB3DX_RUST_ENGINE_H
#define MB3DX_RUST_ENGINE_H
#include "renderer.h"
void render_set_rust_assets(const char *path);
extern int mb3dx_rust_render(const char *,const char *,int,int,int,double,const double *,const double *,void *,int (*)(void *),void (*)(void *,int,int),unsigned char *,unsigned char *,double *,char *,RenderStatistics *);
extern void mb3dx_rust_set_cpu_only(int);
extern int mb3dx_rust_color_fit(int *);
extern int mb3dx_rust_color_histogram(unsigned *);
extern int mb3dx_rust_pick(double,double,double *,double *);
extern int mb3dx_rust_depth(const char *,int,int,int,char *);
extern double mb3dx_rust_distance(double,double,double);
#endif
