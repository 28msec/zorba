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
	cond_event[0] = CreateEvent(NULL, FALSE, FALSE, NULL);//auto-reset, for signal
	cond_event[1] = CreateEvent(NULL, TRUE, FALSE, NULL);//manual-reset, for broadcast
	
  cond_door = CreateEvent(NULL, FALSE, TRUE, NULL);//auto-reset, initial ON
  cond_broadcast = CreateEvent(NULL, FALSE, FALSE, NULL);//auto-reset, initial OFF

  InitializeCriticalSection(&cond_cs);
  waiters = 0;

  ZORBA_FATAL(cond_event[0]!=INVALID_HANDLE_VALUE && cond_event[1]!=INVALID_HANDLE_VALUE && cond_door!=INVALID_HANDLE_VALUE && cond_broadcast!=INVALID_HANDLE_VALUE, 
            "Failed to create condition variable. Error code = " << GetLastError());
}


Condition::~Condition()
{
//  int ret = pthread_cond_destroy(&theCondition); 
  BOOL ret = CloseHandle(cond_event[0]);
  ret &= CloseHandle(cond_event[1]);
  ret &= CloseHandle(cond_door);
  ret &= CloseHandle(cond_broadcast);

  DeleteCriticalSection(&cond_cs);

  ZORBA_FATAL(ret, "Failed to destroy condition variable. Error code = " << GetLastError());
}


void Condition::wait() 
{
  //int ret = pthread_cond_wait(&theCondition, theMutex.getMutex());

  WaitForSingleObject(cond_door, INFINITE);

  EnterCriticalSection(&cond_cs);
  waiters++;
  LeaveCriticalSection(&cond_cs);
  
  SetEvent(cond_door);//let other waits/signal/broadcast to enter

  theMutex.unlock();
	int result = WaitForMultipleObjects(2,cond_event, FALSE, INFINITE);//wait any of them

  EnterCriticalSection(&cond_cs);
  waiters--;
  if((result == WAIT_OBJECT_0 + 1) && !waiters || (result == WAIT_OBJECT_0))
  {
    SetEvent(cond_broadcast);
  }
  LeaveCriticalSection(&cond_cs);

	theMutex.lock();
}


void Condition::signal() 
{
  //int ret = pthread_cond_signal(&theCondition);
  WaitForSingleObject(cond_door, INFINITE);//allow one broadcast/signal at a time

  EnterCriticalSection(&cond_cs);
  bool have_waiters = waiters > 0;
  LeaveCriticalSection(&cond_cs);

  if(!have_waiters)
  {
    SetEvent(cond_door);//no reason to bother
    return;
  }

  SetEvent(cond_event[0]);

  WaitForSingleObject(cond_broadcast, INFINITE);//wait for one waiting thread to wake up

  SetEvent(cond_door);

  //ZORBA_FATAL(!ret, "Failed to signal condition variable. Error code = " << GetLastError());
}


void Condition::broadcast() 
{
  //int ret = pthread_cond_broadcast(&theCondition);
  WaitForSingleObject(cond_door, INFINITE);//allow one broadcast/signal at a time

  EnterCriticalSection(&cond_cs);
  bool have_waiters = waiters > 0;
  LeaveCriticalSection(&cond_cs);

  if(!have_waiters)
  {
    SetEvent(cond_door);//no reason to bother
    return;
  }

  SetEvent(cond_event[1]);//signal broadcast

  WaitForSingleObject(cond_broadcast, INFINITE);//wait for all waiting threads to wake up
  ResetEvent(cond_event[1]);//stop the broadcast
  SetEvent(cond_door);//open the door for waits/signal/broadcast

  //ZORBA_FATAL(!ret, "Failed to brodcast condition variable. Error code = " << GetLastError());
}

#endif // ZORBA_HAVE_PTHREAD_H

}


#endif // ZORBA_FOR_ONE_THREAD_ONLY
