
#include<iostream>
#include<pthread.h>
#include<errno.h>
#include<memory>

#ifndef THREADEX_H
#define THREADEX_H 1

extern int glob;
extern pthread_mutex_t mtx;

void ptAttributesEx();
void* threadFunc(void* x);
void mutexExFunc(int argc, char* argv[]);

#endif