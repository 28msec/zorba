/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "zorbautils/fatal.h"
#include "zorbautils/latch.h"

#ifdef HAVE_PTHREAD_H
#  include <pthread.h>
#endif


namespace zorba { 


#ifndef ZORBA_FOR_ONE_THREAD_ONLY


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  pthread Latch                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#ifdef HAVE_PTHREAD_H


Latch::Latch()
{
  pthread_rwlockattr_t attr;
  pthread_rwlockattr_init(&attr);

#ifndef NDEBUG
  int pshared;
  pthread_rwlockattr_getpshared(&attr, &pshared);
  ZORBA_FATAL(pshared == PTHREAD_PROCESS_PRIVATE,
              "rwlock pshared = " << pshared);
#endif

  pthread_rwlock_init(&theLatch, &attr);

  pthread_rwlockattr_destroy(&attr);
}



Latch::~Latch()
{
  pthread_rwlock_destroy(&theLatch);
}


void Latch::rlock()
{ 
  int ret= pthread_rwlock_rdlock(&theLatch); 
  ZORBA_FATAL(!ret, "Failed to acquire latch. Error code = " << ret);
}


void Latch::wlock()
{ 
  int ret = pthread_rwlock_wrlock(&theLatch); 
  ZORBA_FATAL(!ret, "Failed to acquire latch. Error code = " << ret);
}


void Latch::unlock()
{ 
  int ret= pthread_rwlock_unlock(&theLatch);
  ZORBA_FATAL(!ret, "Failed to release latch. Error code = " << ret);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  WIN32 Latch                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


#elif defined WIN32
#include <errno.h>

Latch::Latch()
  :
	valid(LATCH_INVALID),
	r_active(0),
	w_active(0),
	r_wait(0),
	w_wait(0),
  rlocked(false),
  wlocked(false)
{
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

	valid = LATCH_VALID;
}


Latch::~Latch()
{
  destroy();
}

void Latch::rlock()
{ 
  readlock();
  rlocked = true;
}

void Latch::wlock()
{ 
  writelock();
  wlocked = true;
}

void Latch::unlock()
{ 
  if(wlocked)
    writeunlock();

  if(rlocked)
    readunlock();

  rlocked = false;
  wlocked = false;
}


int Latch::lock_mutex()
{
  // return 0 for success

  if(WaitForSingleObject(mutex, INFINITE) != WAIT_OBJECT_0)
    return 1;

  return 0;
}


int Latch::unlock_mutex()
{
  // return 0 for success
  return !SetEvent(mutex);
}


int Latch::signal_cond_read()
{
	return !SetEvent(cond_read);
}


int Latch::broadcast_cond_read()
{
	return !PulseEvent(cond_read);
}


int Latch::wait_cond_read()
{
  DWORD   retwait;
	unlock_mutex();
	retwait = WaitForSingleObject(cond_read, INFINITE);
  lock_mutex();
  return retwait != WAIT_OBJECT_0;
}


int Latch::signal_cond_write()
{
	return !SetEvent(cond_write);
}


int Latch::broadcast_cond_write()
{
	return !PulseEvent(cond_write);
}


int Latch::wait_cond_write()
{
  DWORD   retwait;
	unlock_mutex();
	retwait = WaitForSingleObject(cond_write, INFINITE);
  lock_mutex();
  return retwait != WAIT_OBJECT_0;
}


/*_____________________________________________________________
|
|  Destroy a read/write lock.
|______________________________________________________________*/

int Latch::destroy()
{
	int status;

	if (valid != LATCH_VALID) return EINVAL;

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

	valid = LATCH_INVALID;
	status = unlock_mutex();
	if (status!=0) return status;

  CloseHandle(mutex);
  CloseHandle(cond_read);
  CloseHandle(cond_write);
  return 0;
}


/*******************************************************************************
  Lock a read/write lock for read access.

  "Read preference" expressed by waiting only for active writers, as opposed
  to waiting writers.
********************************************************************************/
int Latch::readlock()
{
	int status;

	if (valid != LATCH_VALID) return EINVAL;

	if ( (status = lock_mutex()) != 0) return status;

	if (w_active) 
  {
		// writer is active
		r_wait++;

		// wait on read condition variable broadcast by writer
		while (w_active) {
			status = wait_cond_read();
			if (status!=0) break;
		}

		r_wait--;
	}

	if (status==0) r_active++;

	unlock_mutex();
	return status;
}


/*******************************************************************************
  Attempt to lock a read/write lock for read access, but  don't block if
  unavailable.
********************************************************************************/
int Latch::readtrylock()
{
	int status, status2;

	if (valid != LATCH_VALID) return EINVAL;

	if ( (status = lock_mutex()) != 0) return status;

	if (w_active)
		status = EBUSY;
	else
		r_active++;

	status2 = unlock_mutex();
	return (status2 != 0 ? status2 : status);
}


/*******************************************************************************
  Unlock a read/write lock from read access.

  If no more active readers, and at least one waiting writer, signal the write
  condition variable.  Race for access may select readlock or readtrylock.
********************************************************************************/
int Latch::readunlock()
{
	int status, status2;
	
	if (valid != LATCH_VALID) return EINVAL;

	if ( (status = lock_mutex()) != 0) return status;

	r_active--;
	if (r_active == 0 && w_wait > 0) 
		status = signal_cond_write();

	status2 = unlock_mutex();
	return (status2==0 ? status : status2);
}


/*******************************************************************************
  Lock a read/write lock for write access.
********************************************************************************/
int Latch::writelock()
{
	int status;

	if (valid != LATCH_VALID) return EINVAL;

	if ( (status = lock_mutex()) != 0) return status;

	if (w_active || r_active > 0) 
  {
		w_wait++;

		while (w_active || r_active > 0) 
    {
			if ( (status = wait_cond_write()) != 0) break;
		}

		w_wait--;
	}

	if (status==0) w_active = 1;

	unlock_mutex();
	return status;
}


int Latch::writetrylock()
{
	int status, status2;

	if (valid != LATCH_VALID) return EINVAL;

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


int Latch::writeunlock()
{
	int status;

	if (valid != LATCH_VALID) return EINVAL;

	if ( (status = lock_mutex()) != 0) return status;

	w_active = 0;
	// preferrentially wake up waiting readers
	if (r_wait > 0) 
  {
		if ( (status = broadcast_cond_read()) != 0) 
    {
			unlock_mutex();
			return status;
		}
	}
	// if no waiting readers, look for waiting writers
	else if (w_wait > 0) 
  {
		if ( (status = signal_cond_write()) != 0) 
    {
			unlock_mutex();
			return status;
		}
	}

	return unlock_mutex();
}

#endif


#endif

} // namespace zorba
