
#include "store/util/latch.h"
#include <iostream>

#ifdef HAVE_PTHREAD_H
#  include <pthread.h>
#endif


#ifndef ZORBA_FOR_ONE_THREAD_ONLY

namespace zorba { namespace store {

Latch::Latch()
{
#ifdef ZORBA_USE_PTHREAD_LIBRARY
  pthread_rwlockattr_t attr;
  pthread_rwlockattr_init(&attr);

#ifndef NDEBUG
  int pshared;
  pthread_rwlockattr_getpshared(&attr, &pshared);
  if (pshared != PTHREAD_PROCESS_PRIVATE)
  {
    std::cout << "rwlock pshared = " << pshared << std::endl;
    abort();
  }
#endif

  pthread_rwlock_init(&theLatch, &attr);

  pthread_rwlockattr_destroy(&attr);

#elif WIN32
  rlocked = false;
  wlocked = false;
#endif
}



Latch::~Latch()
{
#ifdef ZORBA_USE_PTHREAD_LIBRARY
  pthread_rwlock_destroy(&theLatch);
#elif WIN32
#endif
}


void Latch::rlock()
{ 
#ifdef ZORBA_USE_PTHREAD_LIBRARY
  if(int ret= pthread_rwlock_rdlock(&theLatch)) 
  {
    std::cerr << "Failed to acquire latch. Error code = " << ret << std::endl;
    abort();
  }
#elif WIN32
  theLatch.readlock();
  rlocked = true;
#endif
}


void Latch::wlock()
{ 
#ifdef ZORBA_USE_PTHREAD_LIBRARY
  if(int ret= pthread_rwlock_wrlock(&theLatch)) 
  {
    std::cerr << "Failed to acquire latch. Error code = " << ret << std::endl;
    abort();
  }
#elif WIN32
  theLatch.writelock();
  wlocked = true;
#endif
}


void Latch::unlock()
{ 
#ifdef ZORBA_USE_PTHREAD_LIBRARY
  if(int ret= pthread_rwlock_unlock(&theLatch)) 
  {
    std::cerr << "Failed to release latch. Error code = " << ret << std::endl;
    abort();
  }
#elif WIN32
  if(wlocked)
    theLatch.writeunlock();
  if(rlocked)
    theLatch.readunlock();
  rlocked = false;
  wlocked = false;
#endif
}

} // namespace store
} // namespace zorba

#endif
