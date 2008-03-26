
#include "errors/fatal.h"

#include "store/util/mutex.h"
#include <iostream>


#ifndef ZORBA_FOR_ONE_THREAD_ONLY

namespace zorba { namespace store {

Mutex::Mutex()
{
#ifdef HAVE_PTHREAD_H
  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);

#ifndef NDEBUG
  int pshared;
  pthread_mutexattr_getpshared(&attr, &pshared);
  ZORBA_FATAL(pshared == PTHREAD_PROCESS_PRIVATE, "mutex pshared = " << pshared);
#endif

  pthread_mutex_init(&theMutex, &attr);

  pthread_mutexattr_destroy(&attr);

#elif WIN32
  //threads can acquire same mutex multiple times
  theMutex = CreateMutex(NULL, FALSE, "");
#endif
}



Mutex::~Mutex()
{
#ifdef HAVE_PTHREAD_H
  pthread_mutex_destroy(&theMutex);
#elif WIN32
  CloseHandle(theMutex);
#endif
}


void Mutex::lock()
{ 
#ifdef HAVE_PTHREAD_H
  int ret= pthread_mutex_lock(&theMutex);
  ZORBA_FATAL(!ret, "Failed to acquire mutex. Error code = " << ret);
#elif WIN32
  WaitForSingleObject(theMutex, INFINITE);
#endif
}


void Mutex::unlock()
{ 
#ifdef HAVE_PTHREAD_H
  int ret= pthread_mutex_unlock(&theMutex);
  ZORBA_FATAL(!ret, "Failed to release mutex. Error code = " << ret);
#elif WIN32
  ReleaseMutex(theMutex);
#endif
}

} // namespace store
} // namespace zorba

#endif
