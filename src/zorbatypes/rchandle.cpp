
#include "zorbatypes/rchandle.h"
#include <sstream>
#include <iostream>
#include <cstdlib>

#include <zorba/config.h>
#include "common/common.h"
#include "zorbautils/fatal.h"

namespace zorba {

#ifndef ZORBA_FOR_ONE_THREAD_ONLY

#define     NR_RCLOCKS_IN_POOL  100


/*******************************************************************************

********************************************************************************/
class SyncLock
{
protected:

#ifdef ZORBA_HAVE_PTHREAD_H

#if defined ZORBA_HAVE_PTHREAD_SPINLOCK
  pthread_spinlock_t       theLock;

#elif defined ZORBA_HAVE_PTHREAD_MUTEX
  mutable pthread_mutex_t  theLock;

#else
  #error must have pthread mutex or phread spinlock

#endif // ZORBA_HAVE_PTHREAD_SPINLOCK or ZORBA_HAVE_PTHREAD_MUTEX

#elif defined WIN32 || defined WINCE

  HANDLE                   theLock;

#endif

public:
  SyncLock();

  ~SyncLock();

  void acquire();

  void release();
};


#ifdef ZORBA_HAVE_PTHREAD_H

#if defined ZORBA_HAVE_PTHREAD_SPINLOCK
SyncLock::SyncLock()
{
  if (0 != pthread_spin_init(&theLock, PTHREAD_PROCESS_PRIVATE))
  {
    std::cerr << "Failed to initialize spinlock" << std::endl; 
    abort();
  }
} 

SyncLock::~SyncLock()
{
  if (0 != pthread_spin_destroy(&theLock))
  {
    std::cerr << "Failed to destroy spinlock" << std::endl; 
    abort();
  }

} 

void SyncLock::acquire()
{
  if (0 != pthread_spin_lock(&theLock))
  {
    std::cerr << "Failed to acquire spinlock" << std::endl; 
    abort();
  }
}

void SyncLock::release()
{
  if (0 != pthread_spin_unlock(&theLock))
  {
    std::cerr << "Failed to release spinlock" << std::endl; 
    abort();
  }
}

#elif defined ZORBA_HAVE_PTHREAD_MUTEX

SyncLock::SyncLock()
{
  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK | PTHREAD_PROCESS_PRIVATE);
  if (0 != pthread_mutex_init(&theLock, &attr))
  {
    std::cerr << "Failed to initialize SyncLock" << std::endl; 
    abort();
  }
  pthread_mutexattr_destroy(&attr);
} 

SyncLock::~SyncLock()
{
  if (0 != pthread_mutex_destroy(&theLock))
  {
    std::cerr << "Failed to destroy SyncLock" << std::endl; 
    abort();
  }
} 

void SyncLock::acquire()
{
  if (0 != pthread_mutex_lock(&theLock))
  {
    std::cerr << "Failed to acquire SyncLock" << std::endl; 
    abort();
  }

}

void SyncLock::release()
{
  if (0 != pthread_mutex_unlock(&theLock))
  {
    std::cerr << "Failed to release SyncLock" << std::endl; 
    abort();
  }
}


#endif // ZORBA_HAVE_PTHREAD_SPINLOCK or ZORBA_HAVE_PTHREAD_MUTEX

#elif defined WIN32 || defined WINCE

SyncLock::SyncLock()
{
  theLock = ::CreateEvent(NULL, FALSE, TRUE, NULL);
}


SyncLock::~SyncLock()
{
  ::CloseHandle(theLock);
} 

void SyncLock::acquire()
{
  ::WaitForSingleObject(theLock, INFINITE);
}

void SyncLock::release()
{
  ::SetEvent(theLock);
}

#endif // ZORBA_HAVE_PTHREAD_H or WIN32


/*******************************************************************************

********************************************************************************/
class RCLockPool
{
  SyncLock    * rclock_pool;
  int           current_idx;

public:

  RCLockPool()
  {
    rclock_pool = new SyncLock[NR_RCLOCKS_IN_POOL];
    current_idx = -1;
  }

  ~RCLockPool()
  {
    delete[] rclock_pool;
  }

  SyncLock  *getRCLockFromPool()
  {
    current_idx++;
    current_idx %= NR_RCLOCKS_IN_POOL;
    return &rclock_pool[current_idx];
  }

  static RCLockPool* getInstance();
};


RCLockPool* g_rclock_pool = NULL;


RCLockPool* RCLockPool::getInstance()
{
  if(!g_rclock_pool)
    g_rclock_pool = new RCLockPool;

  return g_rclock_pool;
}


/*******************************************************************************

********************************************************************************/


RCLock::RCLock()
{
  rcp = RCLockPool::getInstance()->getRCLockFromPool();
}


void RCLock::acquire()
{
  if(g_rclock_pool)
    rcp->acquire();
}


void RCLock::release()
{
  if(g_rclock_pool)
    rcp->release();
}

void RCLock::deletePool()
{
  delete g_rclock_pool;
  g_rclock_pool = NULL;
}



#else // ZORBA_FOR_ONE_THREAD_ONLY

#endif


/*******************************************************************************
  
  Base class for reference counted objects

  Any class wishing to take advantage of automatic reference counting
  must inherit from this class.

  rcobject encapsulates the reference count, as well as functions
  for incrementing and decrementing the count. It also contains code
  for destroying a value when it is no longer in use, i.e., when its
  reference count becomes 0.

********************************************************************************/
 
void RCObject::addReference(
    long* counter
    SYNC_PARAM2(RCLock* lock)) const
{
#if defined WIN32 && !defined CYGWIN &&!defined ZORBA_FOR_ONE_THREAD_ONLY
  if(lock)
  {
    if (counter) InterlockedIncrement(counter);
    InterlockedIncrement(&theRefCount);
  }
  else
  {
    if (counter) ++(*counter);
    ++theRefCount;
  }

#else

  SYNC_CODE(if (lock) lock->acquire());

  if (counter) ++(*counter);
  ++theRefCount;

  SYNC_CODE(if (lock) lock->release());

#endif
}


void RCObject::removeReference (
    long* counter 
    SYNC_PARAM2(RCLock* lock))
{
#if defined WIN32 && !defined CYGWIN &&!defined ZORBA_FOR_ONE_THREAD_ONLY
  if(lock)
  {
    if (counter)
    {
      InterlockedDecrement(&theRefCount);
      if (!InterlockedDecrement(counter))
      {
        free();
        return;
      }
    }
    else if (!InterlockedDecrement(&theRefCount))
    {
      free();
      return;
    }
  }
  else
  {
    if (counter)
    {
      --theRefCount;
      if (--(*counter) == 0)
      {
        free();
        return;
      }
    }
    else if (--theRefCount == 0)
    {
      free();
      return; 
    }
  }

#else

  SYNC_CODE(if (lock) lock->acquire());

  if (counter)
  {
    --theRefCount;
    if (--(*counter) == 0)
    {
      SYNC_CODE(if (lock) lock->release());
      free();
      return;
    }
  }
  else if (--theRefCount == 0)
  {
    SYNC_CODE(if (lock) lock->release());
    free();
    return; 
  }

  SYNC_CODE(if (lock) lock->release());

#endif
}



} /* namespace zorba */

