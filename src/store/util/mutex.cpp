
#include "store/util/mutex.h"


#ifndef ZORBA_FOR_ONE_THREAD_ONLY

namespace zorba
{

Mutex::Mutex()
{
#ifdef ZORBA_USE_PTHREAD_LIBRARY
  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);

#ifndef NDEBUG
  int pshared;
  pthread_mutexattr_getpshared(&attr, &pshared);
  if (pshared != PTHREAD_PROCESS_PRIVATE)
  {
    std::cout << "mutex pshared = " << pshared << std::endl;
    abort();
  }
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
#ifdef ZORBA_USE_PTHREAD_LIBRARY
  pthread_mutex_destroy(&theMutex);
#elif WIN32
  CloseHandle(theMutex);
#endif
}


void Mutex::lock()
{ 
#ifdef ZORBA_USE_PTHREAD_LIBRARY
  if(int ret= pthread_mutex_lock(&theMutex)) 
  {
    std::cerr << "Failed to acquire mutex. Error code = " << ret << std::endl;
    abort();
  }
#elif WIN32
  WaitForSingleObject(theMutex, INFINITE);
#endif
}


void Mutex::unlock()
{ 
#ifdef ZORBA_USE_PTHREAD_LIBRARY
  if(int ret= pthread_mutex_unlock(&theMutex)) 
  {
    std::cerr << "Failed to release mutex. Error code = " << ret << std::endl;
    abort();
  }
#elif WIN32
  ReleaseMutex(theMutex);
#endif
}

}

#endif
