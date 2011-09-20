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
#include "stdafx.h"

#include "runnable.h"

#include <cassert>
#include <errno.h>

#include "diagnostics/assert.h"

#ifdef ZORBA_HAVE_PTHREAD_H
#include <unistd.h>
#include <pthread.h>
#define ZORBA_THREAD_RETURN void *
#else
#include <Windows.h>
#define ZORBA_THREAD_RETURN DWORD WINAPI
#endif

#ifdef WIN32
#define THREAD_ID " theThreadID: " << theThreadId
#else
#define THREAD_ID ""
#endif


/*******************************************************************************

********************************************************************************/
zorba::Runnable::Runnable()
  : 
  theStatus(IDLE),
  theFinishCalled(false),
  theMutex(),
  theFinishMutex(),
  theFinishCondition(theFinishMutex)
#ifdef ZORBA_HAVE_PTHREAD_H
  ,
  theCondition(theMutex),
  theCalledTerminate(false)
#endif
{
}


/*******************************************************************************

********************************************************************************/
zorba::Runnable::~Runnable()
{
}


/*******************************************************************************
  This method is invoked by the parent thread. It creates and starts a child 
  thread. The child thread will use the static method startImpl as its "main"
  function.
********************************************************************************/
void
zorba::Runnable::start()
{
  theStatus = RUNNING;
#ifdef WIN32
  theThread = CreateThread(NULL, 0, &startImpl, (void *) this, 0, &theThreadId);
#else
  if (pthread_create(&theThread, NULL, &startImpl, (void *) this))
    assert(false);
#endif
}


/*******************************************************************************
  This method is invoked by the parent thread
********************************************************************************/
void
zorba::Runnable::terminate()
{
retry:
  theMutex.lock();

#ifdef ZORBA_HAVE_PTHREAD_H
  theCalledTerminate = true;
#endif

  if (theStatus == SUSPENDED) {
#ifdef WIN32
    TerminateThread(theThread, 0);
#else
    pthread_cancel(theThread);
    theCondition.signal();
#endif
  } else if (theStatus == TERMINATED) {
    theMutex.unlock();
    return;
  }
  else if (theStatus == RUNNING) {
    // busy wait until the child thread terminates or suspends itself.
    theMutex.unlock();
#ifndef WIN32
    usleep(1000);
#else
    Sleep(1);
#endif
    goto retry;
  } else {
    assert(theStatus == IDLE);
  }

  theMutex.unlock();

  finishImpl();
}


/*******************************************************************************
  This method is invoked by the parent thread
********************************************************************************/
void
zorba::Runnable::join()
{
  theMutex.lock();

  if (theStatus == TERMINATED || theStatus == IDLE) {
    theMutex.unlock();
    return;
  }

  // the finish condition will wait on this mutex until finishImpl
  // will signal the finish condition.
  theFinishMutex.lock();
  theMutex.unlock();

  // wait for the Runnable to finish executing the user code
  // only finishImpl will signal this as the last thing to to
  theFinishCondition.wait();
  theFinishMutex.unlock();

  theMutex.lock();
  // wait for the real thread to terminate
#ifdef WIN32
  DWORD lExitCode;
  if (GetExitCodeThread(theThread, &lExitCode) && lExitCode == STILL_ACTIVE) {
    WaitForSingleObject(theThread, INFINITE);
  }
#else
  if (!theFinishCalled) {
    int status = pthread_join(theThread, 0);
    if (status != EINVAL && status != 0) {
       assert(false);
    }
  }
#endif
  theMutex.unlock();
}


/*******************************************************************************
  This method is called by the child thread to suspend itself for a given
  amount of time.
********************************************************************************/
void
zorba::Runnable::suspend(unsigned long aTimeInMs /*= 0*/)
{
#ifdef WIN32
  theStatus = SUSPENDED;
  if (aTimeInMs != 0) {
    DWORD lTime = aTimeInMs;
    WaitForSingleObject(theThread, lTime);
  } else {
    SuspendThread(theThread);
  }
#else

  theMutex.lock();

  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
  pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
  pthread_cleanup_push(mutexCleanupHandler, &theCondition);

  theStatus = SUSPENDED;

  if (aTimeInMs != 0) 
  {
    theCondition.timedWait(aTimeInMs);
  }
  else 
  {
    theCondition.wait();
  }

  theStatus = RUNNING;

  pthread_testcancel();
  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
  pthread_cleanup_pop(1);
  theMutex.unlock();
#endif
}


#ifdef ZORBA_HAVE_PTHREAD_H
/*******************************************************************************
  Static private method
********************************************************************************/
void
zorba::Runnable::mutexCleanupHandler(void* param)
{
  //Mutex* lMutex = static_cast<Mutex*>(param);
  //lMutex->unlock();
  Condition *lCondition = static_cast<Condition*>(param);
  lCondition->signal();
}
#endif


/*******************************************************************************

********************************************************************************/
void
zorba::Runnable::resume()
{
  theMutex.lock();

#ifdef WIN32
  ResumeThread(theThread);
#else

  assert (theStatus == SUSPENDED);

  theCondition.signal();

#endif
  theStatus = RUNNING;

  theMutex.unlock();
}


/*******************************************************************************
  This is a private static method that serves as the "main" method of the child 
  thread. It is called by the start() method, and is given the Runnable obj as
  input.
********************************************************************************/
ZORBA_THREAD_RETURN
zorba::Runnable::startImpl( void* params )
{
  Runnable* r = static_cast<Runnable*>(params);

  // run the users function in the thread
  r->run();

  // finish if the thread reaches the end of the control flow
  r->finishImpl();

  return NULL;
}


/*******************************************************************************
  Called if the child thread reaches the end of the control flow or terminate
  is requested
********************************************************************************/
void
zorba::Runnable::finishImpl()
{
  theMutex.lock();

#ifndef NDEBUG
  assert (!theFinishCalled);
#endif

  // call the user defined finish
  finish();

  theFinishCalled = true;
  theStatus = TERMINATED;

#ifndef WIN32
  if (!theCalledTerminate) {
    pthread_detach(theThread);
  }
#endif

  // the last thing to do is to signal a possible join waiting
  // for this Runnable to terminate
  theFinishCondition.signal();

  theMutex.unlock();
}


void
zorba::Runnable::sleep_(unsigned long useconds) {
#ifdef WIN32
  Sleep(useconds);
#else
  usleep(useconds);
#endif
}

/*******************************************************************************

********************************************************************************/
void
zorba::Runnable::reset()
{
  theFinishCalled = false;
  theStatus = IDLE;
}
/* vim:set et sw=2 ts=2: */
