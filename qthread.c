#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>
#include <errno.h>
#include "qthread.h"

extern void switch_thread(void **location_for_old_sp, void *new_value);
extern void start_thread(void *stack, void *func, void *arg1, void *arg2);
extern void *setup_stack(void *_stack, size_t len, void *func, void *arg1, void *arg2);

struct qthread
{
  struct qthread *next; // next pointer
  void *saved_sp;       // saved stack pointer for context swicthing
  void *stack;          // pointer to the allocated stack memory
};

struct threadq
{
  qthread_t head;
  qthread_t tail;
};

struct qthread_mutex
{
  int is_locked;         // flag
  struct threadq wait_q; // queue of threads waiting to acquire the mutex
};

struct qthread_cond
{
  struct threadq wait_q; // queue of threads waiting on the condition variable
};
