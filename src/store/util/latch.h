#ifndef ZORBA_LATCH
#define ZORBA_LATCH

#include <zorba/common/common.h>

#ifdef WIN32
#include "util/rwlock.h"
#endif

namespace zorba { namespace store {

#ifndef ZORBA_FOR_ONE_THREAD_ONLY

/*******************************************************************************

********************************************************************************/
class Latch
{
public:

  enum Mode { READ, WRITE };

protected:

#ifdef ZORBA_USE_PTHREAD_LIBRARY
  pthread_rwlock_t  theLatch;
#elif WIN32
  rwlock  theLatch;
  bool    rlocked;
  bool    wlocked;
#else
  #error Latch implemented for PTHREADs and WIN32 only
#endif

public:
  Latch();

  ~Latch();
    
  void rlock();
  void wlock();

  void unlock();

 private:
  Latch(const Latch &);
  void operator=(const Latch &);
};


/*******************************************************************************

********************************************************************************/
class AutoLatch
{
private:
  Latch & theLatch;

public:
  AutoLatch(Latch& l, Latch::Mode m) : theLatch(l)
  {
    if (m == Latch::READ)
      theLatch.rlock();
    else
      theLatch.wlock();
  }
    
  ~AutoLatch()
  {
    theLatch.unlock();
  }
};

#else // ZORBA_FOR_ONE_THREAD_ONLY

/*******************************************************************************

********************************************************************************/
class Latch
{
 public:
  Latch() {}
  ~Latch {}
};


/*******************************************************************************

********************************************************************************/
class AutoLatch
{
public:
  AutoLatch(Latch& l, Latch::Mode m) { }
    
  ~AutoLatch() { }
};

#endif // ZORBA_FOR_ONE_THREAD_ONLY
} // namespace store
} // namespace zorba


#endif
