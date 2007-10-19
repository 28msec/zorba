

#include "util/win32/pthread.h"
#include <windows.h>
#include <errno.h>
#include "time.h"
#ifndef _WIN32_WCE
#include <io.h>
#else
#include <altcecrt.h>
#endif

_pthread_t		*head_thread = NULL;///head of thread list
HANDLE			pthread_hevent = NULL;

DWORD WINAPI pthread_win_thread_func(  LPVOID lpParameter )
{
	pthread_t emul_thread = (pthread_t)lpParameter;

	emul_thread->retval = emul_thread->func(emul_thread->arg);


	return 0;
}

int  pthread_create(pthread_t  *thread, pthread_attr_t * attr, void *
       (*start_routine)(void *), void * arg)
{
	if(!pthread_hevent)
	{
		pthread_hevent = CreateEvent(NULL, FALSE, TRUE, NULL);
	}

	if(!thread)
		return 1;

	WaitForSingleObject(pthread_hevent, INFINITE);

	DWORD	threadID;

	*thread = (pthread_t)malloc(sizeof(_pthread_t));
	memset(*thread, 0, sizeof(_pthread_t));
	thread[0]->arg = arg;
	thread[0]->func = start_routine;
	thread[0]->next = head_thread;
//	if(!head_thread)
		head_thread = thread[0];

	thread[0]->hthread = CreateThread(NULL, 0, 
							pthread_win_thread_func, *thread, 0, &threadID);
	if(!thread[0]->hthread)
	{
		head_thread = head_thread->next;
		SetEvent(pthread_hevent);
		return 1;
	}

	SetEvent(pthread_hevent);
	return 0;
}

void pthread_exit(void *retval)
{
	pthread_t	current_thread;
	current_thread = pthread_self();
	if(!current_thread || !current_thread->hthread)
		return;

	while(current_thread->cl_stack)
		pthread_cleanup_pop(1);

	TerminateThread(current_thread->hthread, (DWORD)retval);
//	current_thread->hthread = NULL;
	current_thread->retval = retval;


}

int pthread_join(pthread_t th, void **thread_return)
{
	if(!th || !th->hthread)
		return 1;
	if(th->hthread == GetCurrentThread())
		return 2;
	WaitForSingleObject(th->hthread, INFINITE);
	if(thread_return)
		*thread_return = th->retval;
	CloseHandle(th->hthread);
	th->hthread = NULL;

	pthread_t	tempthread;

	WaitForSingleObject(pthread_hevent, INFINITE);
	if(head_thread == th)
	{
		head_thread = head_thread->next;
	}
	else
	{
		tempthread = head_thread;
		while(tempthread)
		{
			if(tempthread->next == th)
			{
				tempthread->next = th->next;
				break;
			}
			tempthread = tempthread->next;
		}
	}
	free(th);
	SetEvent(pthread_hevent);

	return 0;
}

pthread_t pthread_self(void)
{
	HANDLE	hthread = GetCurrentThread();
	pthread_t	tempthread;

	WaitForSingleObject(pthread_hevent, INFINITE);

	tempthread = head_thread;
	while(tempthread)
	{
		if(tempthread->hthread == hthread)
		{
			SetEvent(pthread_hevent);
			return tempthread;
		}
		tempthread = tempthread->next;
	}

	SetEvent(pthread_hevent);
	return NULL;
}


int  pthread_mutex_init(pthread_mutex_t  *mutex,  const  pthread_mutex_attr_t *mutexattr)
{
	if(!pthread_hevent)
	{
		pthread_hevent = CreateEvent(NULL, FALSE, TRUE, NULL);
	}

	if(!mutex)
		return 0;
	*mutex = CreateMutex(NULL, FALSE, NULL);
	return 0;
}

int pthread_mutex_lock(pthread_mutex_t *mutex)
{
	WaitForSingleObject(pthread_hevent, INFINITE);
	if(*mutex == NULL)
		*mutex = CreateMutex(NULL, FALSE, NULL);
	SetEvent(pthread_hevent);

	WaitForSingleObject(*mutex, INFINITE);
	return 0;
}

int pthread_mutex_trylock(pthread_mutex_t *mutex)
{
	WaitForSingleObject(pthread_hevent, INFINITE);
	if(*mutex == NULL)
		*mutex = CreateMutex(NULL, FALSE, NULL);
	SetEvent(pthread_hevent);

	if(WaitForSingleObject(*mutex, 1) == WAIT_TIMEOUT)
		return EBUSY;
	return 0;
}

int pthread_mutex_unlock(pthread_mutex_t *mutex)
{
	WaitForSingleObject(pthread_hevent, INFINITE);
	if(*mutex == NULL)
		*mutex = CreateMutex(NULL, FALSE, NULL);
	SetEvent(pthread_hevent);

	ReleaseMutex(*mutex);
	return 0;
}

int pthread_mutex_destroy(pthread_mutex_t *mutex)
{
	if(mutex)
		CloseHandle(*mutex);
	return 0;
}


/*
int pthread_delay_np( struct timespec *interval )
{
	Sleep(interval->tv_sec*1000);
	return 0;
}
*/

int pthread_equal( pthread_t thrid1, pthread_t thrid2 )
{
	if(thrid1->hthread == thrid2->hthread)
		return 0;
	else
		return 1;
}


int pthread_cond_init (pthread_cond_t *cond, pthread_condattr_t *cond_attr)
{
	if(!pthread_hevent)
	{
		pthread_hevent = CreateEvent(NULL, FALSE, TRUE, NULL);
	}

	if(!cond)
		return 0;
	*cond = CreateEvent(NULL, FALSE, FALSE, NULL);

	return 0;

}

int pthread_cond_signal (pthread_cond_t *cond)
{
	if(cond)
		SetEvent((HANDLE)*cond);

	return 0;
}

int pthread_cond_broadcast (pthread_cond_t *cond)
{
	if(cond)
		PulseEvent((HANDLE)*cond);
	return 0;
}

int pthread_cond_wait (pthread_cond_t *cond, pthread_mutex_t *mutex)
{
	if(!cond)
		return 0;
	pthread_mutex_unlock(mutex);
	WaitForSingleObject((HANDLE)*cond, INFINITE);
	pthread_mutex_lock(mutex);

	return 0;
}

int pthread_cond_timedwait (pthread_cond_t *cond, pthread_mutex_t *mutex, const struct timespec *abstime)
{
	DWORD	wait_ret;

	if(!cond)
		return 0;
	pthread_mutex_unlock(mutex);
	if(!abstime || abstime->tv_sec == 0)
		wait_ret = WaitForSingleObject((HANDLE)*cond, INFINITE);
	else
		wait_ret = WaitForSingleObject((HANDLE)*cond, abstime->tv_sec*1000);
	pthread_mutex_lock(mutex);

	if(wait_ret == WAIT_TIMEOUT)
		return ETIMEDOUT;
	else
		return 0;
}

int pthread_cond_destroy (pthread_cond_t *cond)
{
	if(cond)
		CloseHandle((HANDLE)*cond);
	*cond = NULL;
	return 0;
}

void pthread_cleanup_push(void (*routine)(void*), void *arg)
{
	pthread_t myself = pthread_self();

	WaitForSingleObject(pthread_hevent, INFINITE);

	CANCELLATION_CLEANUP_STACK	*next_routine;

	next_routine = (CANCELLATION_CLEANUP_STACK*)malloc(sizeof(CANCELLATION_CLEANUP_STACK));
	next_routine->cl_routine = routine;
	next_routine->arg = arg;
	next_routine->prev = myself->cl_stack;
	myself->cl_stack = next_routine;

	SetEvent(pthread_hevent);
}

void pthread_cleanup_pop(int execute)
{
	pthread_t myself = pthread_self();

	WaitForSingleObject(pthread_hevent, INFINITE);

	CANCELLATION_CLEANUP_STACK	*temp_routine;
	if(myself->cl_stack)
	{
		if(execute)
			myself->cl_stack->cl_routine(myself->cl_stack->arg);
		temp_routine = myself->cl_stack->prev;
		free(myself->cl_stack);
		myself->cl_stack = temp_routine;
	}

	SetEvent(pthread_hevent);
}








//////////////////////////////
/*
int isatty( int fd )
{
	return _isatty(fd);
}
*/