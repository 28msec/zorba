
#include "errors/fatal.h"
#include "store/util/latch.h"
#include <iostream>

#ifdef HAVE_PTHREAD_H
#  include <pthread.h>
#endif


#ifndef ZORBA_FOR_ONE_THREAD_ONLY

namespace zorba { namespace store {

Latch::Latch()
{
#ifdef HAVE_PTHREAD_H
  pthread_rwlockattr_t attr;
  pthread_rwlockattr_init(&attr);

#ifndef NDEBUG
  int pshared;
  pthread_rwlockattr_getpshared(&attr, &pshared);
  ZORBA_FATAL(pshared == PTHREAD_PROCESS_PRIVATE,
              "rwlock pshared = " << pshared);
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
#ifdef HAVE_PTHREAD_H
  pthread_rwlock_destroy(&theLatch);
#elif WIN32
#endif
}


void Latch::rlock()
{ 
#ifdef HAVE_PTHREAD_H
  int ret= pthread_rwlock_rdlock(&theLatch); 
  ZORBA_FATAL(!ret, "Failed to acquire latch. Error code = " << ret);
#elif WIN32
  theLatch.readlock();
  rlocked = true;
#endif
}


void Latch::wlock()
{ 
#ifdef HAVE_PTHREAD_H
  int ret = pthread_rwlock_wrlock(&theLatch); 
  ZORBA_FATAL(!ret, "Failed to acquire latch. Error code = " << ret);
#elif WIN32
  theLatch.writelock();
  wlocked = true;
#endif
}


void Latch::unlock()
{ 
#ifdef HAVE_PTHREAD_H
  int ret= pthread_rwlock_unlock(&theLatch);
  ZORBA_FATAL(!ret, "Failed to release latch. Error code = " << ret);
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
