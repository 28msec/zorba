/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: rwlock.cpp,v 1.1 2006/10/09 07:08:02 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 */

#include "util/rwlock.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
namespace xqp {

rwlock::rwlock()
:
	valid(RWLOCK_INVALID),
	r_active(0),
	w_active(0),
	r_wait(0),
	w_wait(0)
{
#ifdef WIN32
 	mutex = CreateEvent(NULL, FALSE, TRUE, NULL);
  if(mutex == NULL)
    return;
 	cond_read = CreateEvent(NULL, FALSE, FALSE, NULL);
  if(cond_read == NULL)
  {
    CloseHandle(mutex);
    return;
  }
 	cond_write = CreateEvent(NULL, FALSE, FALSE, NULL);
  if(cond_read == NULL)
  {
    CloseHandle(mutex);
    CloseHandle(cond_read);
    return;
  }

#elif defined ZORBA_USE_PTHREAD_LIBRARY
	if (pthread_mutex_init(&mutex, NULL)!=0) return;
	if (pthread_cond_init(&read, NULL)!=0) {
		pthread_mutex_destroy(&mutex);
		return;
	}
	if (pthread_cond_init(&write, NULL)!=0) {
		pthread_mutex_destroy(&mutex);
		pthread_cond_destroy(&read);
		return;
	}
#else
  #error Unsupported thread system
#endif
	valid = RWLOCK_VALID;
}

rwlock::~rwlock()
{
  destroy();
}

/*
return 0 for success
*/
int rwlock::lock_mutex()
{
#ifdef WIN32
  if(WaitForSingleObject(mutex, INFINITE) != WAIT_OBJECT_0)
    return 1;
  return 0;
#elif defined ZORBA_USE_PTHREAD_LIBRARY
  return pthread_mutex_lock(&mutex);
#else
  #error Unsupported thread system
#endif
}

/*
return 0 for success
*/
int rwlock::unlock_mutex()
{
#ifdef WIN32
  return !SetEvent(mutex);
#elif defined ZORBA_USE_PTHREAD_LIBRARY
  return pthread_mutex_unlock(&mutex);
#else
  #error Unsupported thread system
#endif
}


int rwlock::signal_cond_read()
{
#ifdef WIN32
	return !SetEvent(cond_read);
#elif defined ZORBA_USE_PTHREAD_LIBRARY
  return pthread_cond_signal(&read);
#else
  #error Unsupported thread system
#endif
}

int rwlock::broadcast_cond_read ()
{
#ifdef WIN32
	return !PulseEvent(cond_read);
#elif defined ZORBA_USE_PTHREAD_LIBRARY
  return pthread_cond_broadcast(&read);
#else
  #error Unsupported thread system
#endif
}

int rwlock::wait_cond_read ()
{
#ifdef WIN32
  DWORD   retwait;
	unlock_mutex();
	retwait = WaitForSingleObject(cond_read, INFINITE);
  lock_mutex();
  return retwait != WAIT_OBJECT_0;
#elif defined ZORBA_USE_PTHREAD_LIBRARY
  return pthread_cond_wait(&read, &mutex);
#else
  #error Unsupported thread system
#endif
	
}


int rwlock::signal_cond_write()
{
#ifdef WIN32
	return !SetEvent(cond_write);
#elif defined ZORBA_USE_PTHREAD_LIBRARY
  return pthread_cond_signal(&write);
#else
  #error Unsupported thread system
#endif
}

int rwlock::broadcast_cond_write ()
{
#ifdef WIN32
	return !PulseEvent(cond_write);
#elif defined ZORBA_USE_PTHREAD_LIBRARY
  return pthread_cond_broadcast(&write);
#else
  #error Unsupported thread system
#endif
}

int rwlock::wait_cond_write ()
{
#ifdef WIN32
  DWORD   retwait;
	unlock_mutex();
	retwait = WaitForSingleObject(cond_write, INFINITE);
  lock_mutex();
  return retwait != WAIT_OBJECT_0;
#elif defined ZORBA_USE_PTHREAD_LIBRARY
  return pthread_cond_wait(&write, &mutex);
#else
  #error Unsupported thread system
#endif
}


/*_____________________________________________________________
|
|  Destroy a read/write lock.
|______________________________________________________________*/

int rwlock::destroy()
{
	int status;

	if (valid!=RWLOCK_VALID) return EINVAL;
	status = lock_mutex();
	if (status!=0) return status;
	
	// check if any threads own the lock, report "busy" if so.
	if (r_active > 0 || w_active) {
		unlock_mutex();
		return EBUSY;
	}

	// check if any threads are known to be waiting, report "busy" if so
	if (r_wait > 0 || w_wait > 0) {
		unlock_mutex();
		return EBUSY;
	}

	valid = RWLOCK_INVALID;
	status = unlock_mutex();
	if (status!=0) return status;
#ifdef WIN32
  CloseHandle(mutex);
  CloseHandle(cond_read);
  CloseHandle(cond_write);
  return 0;
#elif defined ZORBA_USE_PTHREAD_LIBRARY
  int status1, status2;
	status = pthread_mutex_destroy(&mutex);
	status1 = pthread_cond_destroy(&read);
	status2 = pthread_cond_destroy(&write);
	return (status!=0 ? status
										: (status1 != 0 ? status1 : status2));
#else
  #error Unsupported thread system
#endif
	
}


/*_____________________________________________________________
|
|  Handle cleanup when the read lock condition variable
|  wait is cancelled.  Record that the thread is no longer
|  waiting and unlock the mutex.
|______________________________________________________________*/

void rwlock::read_cleanup(void* arg)
{
	rwlock *rwl = (rwlock*)arg;
	rwl->r_wait--;
  rwl->unlock_mutex();
}


/*_____________________________________________________________
|
|  Handle cleanup when the write lock condition variable
|  wait is cancelled.  Record that the thread is no longer
|  waiting and unlock the mutex.
|______________________________________________________________*/

void rwlock::write_cleanup(void* arg)
{
	rwlock *rwl = (rwlock*)arg;
	rwl->w_wait--;
	rwl->unlock_mutex();
}

#ifdef WIN32
#define cleanup_push_read()
#define cleanup_pop()
#define cleanup_push_write()
#elif defined ZORBA_USE_PTHREAD_LIBRARY
#define cleanup_push_read()	  pthread_cleanup_push(read_cleanup, (void*)this)
#define cleanup_pop()         pthread_cleanup_pop(0)
#define cleanup_push_write()  pthread_cleanup_push(write_cleanup, (void*)this)
#else
 #error Unsupported thread system
#endif


/*_____________________________________________________________
|
|  Lock a read/write lock for read access.
|
|  "Read preference" expressed by waiting only for active
|  writers, as opposed to waiting writers.
|______________________________________________________________*/

int rwlock::readlock()
{
	int status;

	if (valid!=RWLOCK_VALID) return EINVAL;
	if ( (status = lock_mutex()) != 0) return status;

	if (w_active) {	// (as opposed to (w_wait > 0) )
		// writer is active
		r_wait++;
		cleanup_push_read();

		// wait on read condition variable broadcast by writer
		while (w_active) {
			status = wait_cond_read();
			if (status!=0) break;
		}
		cleanup_pop();
		r_wait--;
	}
	if (status==0) r_active++;
	unlock_mutex();
	return status;
}


/*_____________________________________________________________
|
|  Attempt to lock a read/write lock for read access, but
|  don't block if unavailable.
|______________________________________________________________*/
int rwlock::readtrylock()
{
	int status, status2;

	if (valid!=RWLOCK_VALID) return EINVAL;
	if ( (status = lock_mutex()) != 0) return status;
	if (w_active) {
		status = EBUSY;
	}
	else {
		r_active++;
	}
	status2 = unlock_mutex();
	return (status2 != 0 ? status2 : status);
}


/*_____________________________________________________________
|
|  Unlock a read/write lock from read access.
|
|  If no more active readers, and at least one waiting
|  writer, signal the write condition variable.  Race for
|  access may may select readlock or readtrylock.
|______________________________________________________________*/
int rwlock::readunlock()
{
	int status, status2;
	
	if (valid != RWLOCK_VALID) return EINVAL;
	if ( (status = lock_mutex()) != 0) return status;
	r_active--;
	if (r_active==0 && w_wait > 0) {
		status = signal_cond_write();
	}
	status2 = unlock_mutex();
	return (status2==0 ? status : status2);
	
}


/*_____________________________________________________________
|
|  Lock a read/write lock for write access.
|______________________________________________________________*/
int rwlock::writelock()
{
	int status;

	if (valid!=RWLOCK_VALID) return EINVAL;
	if ( (status = lock_mutex()) != 0) return status;

	if (w_active || r_active > 0) {
		w_wait++;
		cleanup_push_write();
		while (w_active || r_active > 0) {
			if ( (status = wait_cond_write()) != 0) break;
		}
		cleanup_pop();
		w_wait--;
	}
	if (status==0) w_active = 1;
	unlock_mutex();
	return status;
}


int rwlock::writetrylock()
{
	int status, status2;

	if (valid!=RWLOCK_VALID) return EINVAL;
	if ( (status = lock_mutex()) != 0) return status;

	if (w_active || r_active > 0) {
		status = EBUSY;
	}
	else {
		w_active = 1;
	}
	status2 = unlock_mutex();
	return (status != 0 ? status : status2);
}


int rwlock::writeunlock()
{
	int status;

	if (valid!=RWLOCK_VALID) return EINVAL;
	if ( (status = lock_mutex()) != 0) return status;

	w_active = 0;
	// preferrentially wake up waiting readers
	if (r_wait > 0) {
		if ( (status = broadcast_cond_read()) != 0) {
			unlock_mutex();
			return status;
		}
	}
	// if no waiting readers, look for waiting writers
	else if (w_wait > 0) {
		if ( (status = signal_cond_write()) != 0) {
			unlock_mutex();
			return status;
		}
	}

	return unlock_mutex();
}


}	/* namespace xqp */
