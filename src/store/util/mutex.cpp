
#include "store/util/mutex.h"


#ifndef ZORBA_FOR_ONE_THREAD_ONLY

namespace xqp
{

Mutex::Mutex()
{
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
}



Mutex::~Mutex()
{
  pthread_mutex_destroy(&theMutex);
}


void Mutex::lock()
{ 
  if(int ret= pthread_mutex_lock(&theMutex)) 
  {
    std::cerr << "Failed to acquire mutex. Error code = " << ret << std::endl;
    abort();
  }
}


void Mutex::unlock()
{ 
  if(int ret= pthread_mutex_unlock(&theMutex)) 
  {
    std::cerr << "Failed to release mutex. Error code = " << ret << std::endl;
    abort();
  }
}

}

#endif
