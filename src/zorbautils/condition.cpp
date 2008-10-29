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
#include "zorbautils/mutex.h"
#include "zorbautils/condition.h"


#ifndef ZORBA_FOR_ONE_THREAD_ONLY

namespace zorba { 

#ifdef ZORBA_HAVE_PTHREAD_H


Condition::Condition(Mutex& m) : theMutex(m) 
{
  int ret = pthread_cond_init(&theCondition, NULL); 

  ZORBA_FATAL(!ret, "Failed to create condition variable. Error code = " << ret);
}


Condition::~Condition()
{
  int ret = pthread_cond_destroy(&theCondition); 

  ZORBA_FATAL(!ret, "Failed to destroy condition variable. Error code = " << ret);
}


void Condition::wait() 
{
  int ret = pthread_cond_wait(&theCondition, theMutex.getMutex());

  ZORBA_FATAL(!ret, "Failed to wait on condition variable. Error code = " << ret);
}


void Condition::signal() 
{
  int ret = pthread_cond_signal(&theCondition);

  ZORBA_FATAL(!ret, "Failed to signal condition variable. Error code = " << ret);
}


void Condition::broadcast() 
{
  int ret = pthread_cond_broadcast(&theCondition);

  ZORBA_FATAL(!ret, "Failed to brodcast condition variable. Error code = " << ret);
}

#elif WIN32
Condition::Condition(Mutex& m) : theMutex(m) 
{
//  int ret = pthread_cond_init(&theCondition, NULL); 
	cond_event = CreateEvent(NULL, FALSE, FALSE, NULL);

  ZORBA_FATAL(cond_event==INVALID_HANDLE_VALUE, "Failed to create condition variable. Error code = " << GetLastError());
}


Condition::~Condition()
{
//  int ret = pthread_cond_destroy(&theCondition); 
  BOOL ret = CloseHandle(cond_event);

  ZORBA_FATAL(!ret, "Failed to destroy condition variable. Error code = " << GetLastError());
}


void Condition::wait() 
{
  //int ret = pthread_cond_wait(&theCondition, theMutex.getMutex());
  theMutex.unlock();
	WaitForSingleObject(cond_event, INFINITE);
	theMutex.lock();
}


void Condition::signal() 
{
  //int ret = pthread_cond_signal(&theCondition);
	BOOL ret = SetEvent(cond_event);

  ZORBA_FATAL(!ret, "Failed to signal condition variable. Error code = " << GetLastError());
}


void Condition::broadcast() 
{
  //int ret = pthread_cond_broadcast(&theCondition);
	BOOL ret = PulseEvent(cond_event);

  ZORBA_FATAL(!ret, "Failed to brodcast condition variable. Error code = " << GetLastError());
}

#endif // ZORBA_HAVE_PTHREAD_H

}


#endif // ZORBA_FOR_ONE_THREAD_ONLY
