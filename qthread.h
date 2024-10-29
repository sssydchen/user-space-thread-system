
#ifndef __QTHREAD_H__
#define __QTHREAD_H__

struct qthread;
typedef struct qthread *qthread_t;

struct qthread_mutex;
typedef struct qthread_mutex qthread_mutex_t;

struct qthread_cond;
typedef struct qthread_cond qthread_cond_t;

typedef void (*f_2arg_t)(void *, void *);
typedef void *(*f_1arg_t)(void *);

void qthread_init(void);
qthread_t qthread_create(f_1arg_t f, void *arg1);
void qthread_yield(void);
void qthread_exit(void *val);
void *qthread_join(qthread_t thread);
qthread_mutex_t *qthread_mutex_create(void);
void qthread_mutex_lock(qthread_mutex_t *mutex);
void qthread_mutex_unlock(qthread_mutex_t *mutex);
void qthread_mutex_destroy(qthread_mutex_t *mutex);
qthread_cond_t *qthread_cond_create(void);
void qthread_cond_wait(qthread_cond_t *cond, qthread_mutex_t *mutex);
void qthread_cond_signal(qthread_cond_t *cond);
void qthread_cond_broadcast(qthread_cond_t *cond);
void qthread_cond_destroy(qthread_cond_t *cond);
void qthread_usleep(long int usecs);

#endif
