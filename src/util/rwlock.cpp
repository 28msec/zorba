/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: rwlock.cpp,v 1.1 2006/10/09 07:08:02 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 */

#include "util/rwlock.h"

#ifndef WIN32
#include <pthread.h>
#else
#include "util/win32/pthread.h"
#endif

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
	valid = RWLOCK_VALID;
}

rwlock::~rwlock()
{
}



/*_____________________________________________________________
|
|  Destroy a read/write lock.
|______________________________________________________________*/

int rwlock::destroy()
{
	int status, status1, status2;

	if (valid!=RWLOCK_VALID) return EINVAL;
	status = pthread_mutex_lock(&mutex);
	if (status!=0) return status;
	
	// check if any threads own the lock, report "busy" if so.
	if (r_active > 0 || w_active) {
		pthread_mutex_unlock(&mutex);
		return EBUSY;
	}

	// check if any threads are known to be waiting, report "busy" if so
	if (r_wait > 0 || w_wait > 0) {
		pthread_mutex_unlock(&mutex);
		return EBUSY;
	}

	valid = RWLOCK_INVALID;
	status = pthread_mutex_unlock(&mutex);
	if (status!=0) return status;
	status = pthread_mutex_destroy(&mutex);
	status1 = pthread_cond_destroy(&read);
	status2 = pthread_cond_destroy(&write);
	return (status!=0 ? status
										: (status1 != 0 ? status1 : status2));
	
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
	pthread_mutex_unlock(&rwl->mutex);
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
	pthread_mutex_unlock(&rwl->mutex);
}


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
	if ( (status = pthread_mutex_lock(&mutex)) != 0) return status;

	if (w_active) {	// (as opposed to (w_wait > 0) )
		// writer is active
		r_wait++;
		pthread_cleanup_push(read_cleanup, (void*)this);

		// wait on read condition variable broadcast by writer
		while (w_active) {
			status = pthread_cond_wait(&read, &mutex);
			if (status!=0) break;
		}
		pthread_cleanup_pop(0);
		r_wait--;
	}
	if (status==0) r_active++;
	pthread_mutex_unlock(&mutex);
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
	if ( (status = pthread_mutex_lock(&mutex)) != 0) return status;
	if (w_active) {
		status = EBUSY;
	}
	else {
		r_active++;
	}
	status2 = pthread_mutex_unlock(&mutex);
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
	if ( (status = pthread_mutex_lock(&mutex)) != 0) return status;
	r_active--;
	if (r_active==0 && w_wait > 0) {
		status = pthread_cond_signal(&write);
	}
	status2 = pthread_mutex_unlock(&mutex);
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
	if ( (status = pthread_mutex_lock(&mutex)) != 0) return status;

	if (w_active || r_active > 0) {
		w_wait++;
		pthread_cleanup_push(write_cleanup, (void*)this);
		while (w_active || r_active > 0) {
			if ( (status = pthread_cond_wait(&write, &mutex)) != 0) break;
		}
		pthread_cleanup_pop(0);
		w_wait--;
	}
	if (status==0) w_active = 1;
	pthread_mutex_unlock(&mutex);
	return status;
}


int rwlock::writetrylock()
{
	int status, status2;

	if (valid!=RWLOCK_VALID) return EINVAL;
	if ( (status = pthread_mutex_lock(&mutex)) != 0) return status;

	if (w_active || r_active > 0) {
		status = EBUSY;
	}
	else {
		w_active = 1;
	}
	status2 = pthread_mutex_unlock(&mutex);
	return (status != 0 ? status : status2);
}


int rwlock::writeunlock()
{
	int status;

	if (valid!=RWLOCK_VALID) return EINVAL;
	if ( (status = pthread_mutex_lock(&mutex)) != 0) return status;

	w_active = 0;
	// preferrentially wake up waiting readers
	if (r_wait > 0) {
		if ( (status = pthread_cond_broadcast(&read)) != 0) {
			pthread_mutex_unlock(&mutex);
			return status;
		}
	}
	// if no waiting readers, look for waiting writers
	else if (w_wait > 0) {
		if ( (status = pthread_cond_signal(&write)) != 0) {
			pthread_mutex_unlock(&mutex);
			return status;
		}
	}

	return pthread_mutex_unlock(&mutex);
}


}	/* namespace xqp */
