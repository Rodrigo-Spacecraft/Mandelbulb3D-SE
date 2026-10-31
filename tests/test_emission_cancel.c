#define _POSIX_C_SOURCE 200809L
#include "../renderer.h"
#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static double now(void){struct timespec t;clock_gettime(CLOCK_MONOTONIC,&t);return t.tv_sec+t.tv_nsec*1e-9;}
static void *stop(void *token){struct timespec delay={0,100000000};nanosleep(&delay,NULL);render_cancel(token);return NULL;}
int main(void){RenderOptions o;char error[512];assert(read_scene_settings("tests/emission-sphere-first.m3p",&o,error));o.de_stop*=192.0/o.width;o.width=o.height=192;o.camera_override=1;o.threads=2;o.fog.mode=0;RenderResult warm=render_scene_with_options(NULL,o);assert(warm.rgba);free(warm.rgba);
 o.reuse_surface=1;o.fog.mode=2;o.cancel_token=render_cancel_create();assert(o.cancel_token);pthread_t thread;assert(!pthread_create(&thread,NULL,stop,o.cancel_token));double start=now();RenderResult r=render_scene_with_options(NULL,o);double seconds=now()-start;pthread_join(thread,NULL);assert(r.cancelled&&!r.rgba);render_cancel_destroy(o.cancel_token);printf("Cancelled emissive repaint in %.3f seconds\n",seconds);assert(seconds<1.0);return 0;}
