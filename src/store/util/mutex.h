#ifndef ZORBA_STORE_MUTEX_H
#define ZORBA_STORE_MUTEX_H

#include "common/common.h"

#ifdef HAVE_PTHREAD_H
#  include <pthread.h>
#endif

namespace zorba { namespace store {

#ifndef ZORBA_FOR_ONE_THREAD_ONLY

/*******************************************************************************

********************************************************************************/
class Mutex
{
protected:

#ifdef ZORBA_USE_PTHREAD_LIBRARY
  pthread_mutex_t  theMutex;
#elif WIN32
  HANDLE          theMutex;
#else
  #error Mutex implemented for PTHREADs AND WIN32 only
#endif

public:
  Mutex();

  ~Mutex();
    
  void lock();
    
  void unlock();

 private:
  Mutex(const Mutex &);
  void operator=(const Mutex &);
};


/*******************************************************************************

********************************************************************************/
class AutoMutex
{
private:
  Mutex & theMutex;

public:
  AutoMutex(Mutex& mutex) : theMutex(mutex)
  { 
    theMutex.lock();   
  }
    
  ~AutoMutex()
  {
    theMutex.unlock();
  }
};

#endif // ZORBA_FOR_ONE_THREAD_ONLY

} // namespace store
} // namespace zorba


#endif
