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

#include <cassert>

#include "zorbaerrors/Assert.h"

#ifdef ZORBA_HAVE_PTHREAD_H
#include <unistd.h>
#    include <pthread.h>
#    define ZORBA_THREAD_RETURN void *
#else
#    include <Windows.h>
#    define ZORBA_THREAD_RETURN DWORD WINAPI
#endif

//#define TRACING_ON

#ifdef TRACING_ON
#define TRACE(msg) std::cout << msg << std::endl;
#else
#define TRACE(msg)
#endif


zorba::Runnable::~Runnable()
{
}

zorba::Runnable::Runnable()
  : theStatus(IDLE),
    theFinishCalled(false),
    theMutex(),
    theCondition(theMutex),
    theDeleteAfterRun(false),
    theJoining(false)
#ifdef ZORBA_HAVE_PTHREAD_H
    ,theCalledTerminate(false)
#endif
{
}


/*******************************************************************************

********************************************************************************/
void zorba::Runnable::reset()
{
  theFinishCalled = false;
  theStatus = IDLE;
}


/*******************************************************************************
  This method is invoked by the parent thread and starts a child thread.
********************************************************************************/
void zorba::Runnable::start()
{
  theStatus = RUNNING;
#ifdef WIN32
  theThread = CreateThread(NULL, 0, &startImpl, (void *) this, 0, &theThreadId);
#else
  if (pthread_create(&theThread, NULL, &startImpl, (void *) this))
    assert(false);
#endif

  TRACE("Created child thread " << theThread << std::endl);
}


/*******************************************************************************
  This method is invoked by the parent thread
********************************************************************************/
void zorba::Runnable::terminate()
{
  TRACE("Terminating child thread " << theThread << std::endl);

retry:

  theMutex.lock();

#ifdef ZORBA_HAVE_PTHREAD_H
  theCalledTerminate = true;
#endif

  if (theStatus == SUSPENDED)
  {
#ifdef WIN32
    TerminateThread(theThread, 0);
#else

    pthread_cancel(theThread);

    theCondition.signal();

#endif
  }
  else if (theStatus == TERMINATED)
  {
    theMutex.unlock();
    return;
  }
  else if (theStatus == RUNNING)
  {
    // busy wait until the child thread terminates or suspends itself.
    theMutex.unlock();
#ifndef WIN32
    usleep(1000);
#else
    Sleep(1);
#endif
    goto retry;
  }
  else
  {
    assert(theStatus == IDLE);
  }

  theMutex.unlock();

  join();

  finishImpl();

  TRACE("Terminating child thread " << theThread << std::endl);
}


/*******************************************************************************
  This method is invoked by the parent thread
********************************************************************************/
void zorba::Runnable::join()
{
  theMutex.lock();

  if (theStatus == TERMINATED || theStatus == IDLE)
  {
    theMutex.unlock();
    return;
  }

  theJoining = true;

  theMutex.unlock();

#ifdef WIN32
  WaitForSingleObject( theThread, INFINITE );
#else
  if (pthread_join( theThread, 0 ))
    assert(false);
#endif

  theStatus = TERMINATED;
}


/*******************************************************************************
  This method is called by the child thread to suspend itself for a given
  amount of time.
********************************************************************************/
void zorba::Runnable::suspend(unsigned long aTimeInMs /*= 0*/)
{
#ifdef WIN32
  theStatus = SUSPENDED;
  if (aTimeInMs != 0)
  {
    DWORD lTime = aTimeInMs;
    WaitForSingleObject(theThread, lTime);
  }
  else
  {
    SuspendThread(theThread);
  }
#else

  // std::cout << "Suspending child thread " << theThread << std::endl << std::endl;

  theMutex.lock();

  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
  pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
  pthread_cleanup_push(mutexCleanupHandler, &theMutex);

  theStatus = SUSPENDED;

  if (aTimeInMs != 0)
    theCondition.timedWait(aTimeInMs);
  else
    theCondition.wait();

  TRACE("Resuming child thread " << theThread << std::endl);

  theStatus = RUNNING;

  pthread_testcancel();
  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
  pthread_cleanup_pop(1);
#endif
}


#ifdef ZORBA_HAVE_PTHREAD_H
void zorba::Runnable::mutexCleanupHandler(void* param)
{
  Mutex* lMutex = static_cast<Mutex*>(param);
  lMutex->unlock();
}
#endif


/*******************************************************************************

********************************************************************************/
void zorba::Runnable::resume()
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
  This method is the "main" method of the child thread.
********************************************************************************/
ZORBA_THREAD_RETURN
zorba::Runnable::startImpl( void* params )
{
  // run the users function in the thread
  Runnable* r = static_cast<Runnable*>(params);
  r->run();

  // finish if the thread reaches the end
  // of the control flow
  r->finishImpl();
  return NULL;
}


/*******************************************************************************
  Called if the child thread reaches the end of the control flow or terminate
  is requested
********************************************************************************/
void zorba::Runnable::finishImpl()
{
  theMutex.lock();

#ifndef NDEBUG
  assert (!theFinishCalled);
#endif

  finish();

  theFinishCalled = true;

  theStatus = TERMINATED;

  theMutex.unlock();

#ifdef ZORBA_HAVE_PTHREAD_H
  if (!theCalledTerminate && !theJoining)
  {
    pthread_detach(theThread);
  }
#endif

  if (theDeleteAfterRun)
  {
    delete this;
  }
}


/*******************************************************************************

********************************************************************************/
void zorba::Runnable::setDeleteAfterRun( bool aDeleteAfterRun )
{
  theDeleteAfterRun = aDeleteAfterRun;

  // Check postconditions
  ZORBA_ASSERT(theDeleteAfterRun == aDeleteAfterRun);
}
