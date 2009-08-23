#include "runnable.h"

#include <iostream>
#include <cassert>

#ifdef ZORBA_HAVE_PTHREAD_H
#    include <pthread.h>
#    define ZORBA_THREAD_RETURN void *
#else
#    include <Windows.h>
#    define ZORBA_THREAD_RETURN DWORD WINAPI
#endif

zorba::Runnable::~Runnable()
{
}

zorba::Runnable::Runnable()
  : theStatus(IDLE),
    theFinishCalled(false),
    theMutex(),
    theCondition(theMutex)
{
}

void zorba::Runnable::start()
{
    theStatus = RUNNING;
#ifdef WIN32
    theThread = CreateThread(NULL, 0, &startImpl, (void *) this, 0, &theThreadId);
#else
    if (pthread_create(&theThread, NULL, &startImpl, (void *) this))
        assert(false);
#endif
}

void zorba::Runnable::terminate()
{
  theMutex.lock();

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
  } else {
    assert(theStatus == IDLE);
  }

  theMutex.unlock();
  join();
  finishImpl();

}

void zorba::Runnable::suspend()
{
#ifdef WIN32
  theStatus = SUSPENDED;
  SuspendThread(theThread);
#else
  theMutex.lock();
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
  pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

  pthread_cleanup_push(mutexCleanupHandler, &theMutex);

  theStatus = SUSPENDED;
  theCondition.wait();

  theStatus = RUNNING;
  pthread_testcancel();

  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
  pthread_cleanup_pop(1);

#endif
}

#ifdef ZORBA_HAVE_PTHREAD_H
void
zorba::Runnable::mutexCleanupHandler(void* param)
{
  Mutex* lMutex = static_cast<Mutex*>(param);
  lMutex->unlock();
}
#endif

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

void zorba::Runnable::join()
{
  theMutex.lock();
  if (theStatus == TERMINATED || theStatus == IDLE) {
    theMutex.unlock();
    return;
  }
  theMutex.unlock();
#ifdef WIN32
  WaitForSingleObject( theThread, INFINITE );
#else
  if (pthread_join( theThread, 0 ))
    assert(false);
#endif
  theStatus = TERMINATED;
}

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

// called if the user's thread reaches the end of the control flow
// or terminate is requested
void zorba::Runnable::finishImpl()
{
#ifndef NDEBUG
  theMutex.lock();
  assert (!theFinishCalled);
  theMutex.unlock();
#endif

  finish();

  theMutex.lock();
  theFinishCalled = true;
  theStatus = TERMINATED;
  theMutex.unlock();
}
