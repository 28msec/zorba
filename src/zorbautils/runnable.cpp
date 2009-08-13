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
#include "runnable.h"

#ifndef ZORBA_FOR_ONE_THREAD_ONLY

#ifdef ZORBA_HAVE_PTHREAD_H
#include <pthread.h>
#define ZORBA_THREAD_RETURN void *
#else
#include <Windows.h>
#define ZORBA_THREAD_RETURN DWORD WINAPI
#endif


zorba::Runnable::~Runnable()
{
}

zorba::Runnable::Runnable() : theStatus(IDLE), finishCalled(false)
{
}

void zorba::Runnable::start()
{
#ifdef WIN32
  theThread = CreateThread(NULL, 0, &startImpl, (void *) this, 0, &theThreadId);
#else
  // TODO handle errors (i.e. return value)
  pthread_create(&theThread, NULL, &startImpl, (void *) this);
#endif
  theStatus = RUNNING;
}

void zorba::Runnable::terminate()
{
  AutoLock(theThreadLock, Lock::WRITE);
#ifdef WIN32
  TerminateThread(theThread, 0);
#else
  pthread_mutex_lock( &theMutex );
  pthread_exit(0);
  pthread_mutex_unlock( &theMutex );
#endif
  finishImpl();
}

void zorba::Runnable::suspend()
{
#ifdef WIN32
  SuspendThread(theThread);
#else
  pthread_mutex_lock( &theMutex );
  pthread_cond_wait( &theCV, &theMutex ); 
  pthread_mutex_unlock( &theMutex );
#endif
  theStatus = SUSPENDED;
}

void zorba::Runnable::resume()
{
#ifdef WIN32
  ResumeThread(theThread);
#else
  pthread_mutex_lock( &theMutex );
  pthread_cond_signal( &theCV );
  pthread_mutex_unlock( &theMutex );
#endif
  theStatus = RUNNING;
}

void zorba::Runnable::join()
{
#ifdef ZORBA_HAVE_PTHREAD_H
  pthread_join( theThread, 0 );
#else
  WaitForSingleObject( theThread, INFINITE );
#endif
  finishImpl();
}

zorba::Runnable::ThreadState zorba::Runnable::status()
{
  return theStatus;
}

ZORBA_THREAD_RETURN zorba::Runnable::startImpl( void* params )
{
  Runnable* r = static_cast<Runnable*>(params);
  r->run();
  r->finishImpl();
  return NULL;
}
void zorba::Runnable::finishImpl()
{
  AutoLock l(theThreadLock, Lock::WRITE);
  if (finishCalled) {
    return;
  }
  theStatus = TERMINATED;
  finish();
  finishCalled = true;
}

#endif//#ifndef ZORBA_FOR_ONE_THREAD_ONLY
