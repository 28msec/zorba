

#ifndef PTHREAD_PORTING_ON_WINDOWS_14_JUN_2006
#define PTHREAD_PORTING_ON_WINDOWS_14_JUN_2006

//#include <windows.h>
#include <errno.h>

typedef void*(*pthread_start_routine)(void *);

typedef void (*cleanup_routine)(void*);

typedef struct _tcancellation_stack
{
	cleanup_routine		cl_routine;
	struct _tcancellation_stack	*prev;
	void			*arg;
}CANCELLATION_CLEANUP_STACK;

typedef struct _tpthread_t
{
	void			*hthread;///actually HANDLE
	void			*retval;
	pthread_start_routine		func;
	void			*arg;
	CANCELLATION_CLEANUP_STACK	*cl_stack;

	struct _tpthread_t	*next;

}_pthread_t, *pthread_t;

typedef void *		pthread_mutex_t;///actually HANDLE

typedef long pthread_mutex_attr_t;
typedef long pthread_attr_t;

int  pthread_create(pthread_t  *  thread, pthread_attr_t * attr, void *
       (*start_routine)(void *), void * arg);

void pthread_exit(void *retval);

int pthread_join(pthread_t th, void **thread_return);

pthread_t pthread_self(void);

#define		PTHREAD_MUTEX_INITIALIZER		{NULL}
#define		PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP		NULL

//#define		EBUSY							155
#define ETIMEDOUT 116		/* Connection timed out */

//pthread_mutex_t fastmutex = PTHREAD_MUTEX_INITIALIZER;

//pthread_mutex_t recmutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

//pthread_mutex_t errchkmutex = PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP;

int  pthread_mutex_init(pthread_mutex_t  *mutex,  const  pthread_mutex_attr_t *mutexattr);

int pthread_mutex_lock(pthread_mutex_t *mutex);

int pthread_mutex_trylock(pthread_mutex_t *mutex);

int pthread_mutex_unlock(pthread_mutex_t *mutex);

int pthread_mutex_destroy(pthread_mutex_t *mutex);



struct timespec {
        int tv_sec;     // seconds after the minute - [0,59] 
        //int tm_min;     // minutes after the hour - [0,59] 
        //int tm_hour;    // hours since midnight - [0,23] 
        //int tm_mday;    // day of the month - [1,31] 
        //int tm_mon;     // months since January - [0,11] 
        //int tm_year;    // years since 1900 
        //int tm_wday;    // days since Sunday - [0,6] 
        //int tm_yday;    // days since January 1 - [0,365] 
        //int tm_isdst;   // daylight savings time flag 
        };

//int pthread_delay_np( struct timespec *interval );

int pthread_equal( pthread_t thrid1, pthread_t thrid2 );


typedef void *		pthread_cond_t;///actually HANDLE
typedef long		pthread_condattr_t;

int pthread_cond_init (pthread_cond_t *cond, pthread_condattr_t *cond_attr);
int pthread_cond_signal (pthread_cond_t *cond);
int pthread_cond_broadcast (pthread_cond_t *cond);
int pthread_cond_wait (pthread_cond_t *cond, pthread_mutex_t *mutex);
int pthread_cond_timedwait (pthread_cond_t *cond, pthread_mutex_t *mutex, const struct timespec *abstime);
int pthread_cond_destroy (pthread_cond_t *cond);


void pthread_cleanup_push(void (*routine)(void*), void *arg);
void pthread_cleanup_pop(int execute);

#endif

