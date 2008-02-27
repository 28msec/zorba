
#include "store/util/latch.h"


#ifndef ZORBA_FOR_ONE_THREAD_ONLY

namespace xqp
{

Latch::Latch()
{
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
}



Latch::~Latch()
{
  pthread_rwlock_destroy(&theLatch);
}


void Latch::rlock()
{ 
  if(int ret= pthread_rwlock_rdlock(&theLatch)) 
  {
    std::cerr << "Failed to acquire latch. Error code = " << ret << std::endl;
    abort();
  }
}


void Latch::wlock()
{ 
  if(int ret= pthread_rwlock_wrlock(&theLatch)) 
  {
    std::cerr << "Failed to acquire latch. Error code = " << ret << std::endl;
    abort();
  }
}


void Latch::unlock()
{ 
  if(int ret= pthread_rwlock_unlock(&theLatch)) 
  {
    std::cerr << "Failed to release latch. Error code = " << ret << std::endl;
    abort();
  }
}

}

#endif
