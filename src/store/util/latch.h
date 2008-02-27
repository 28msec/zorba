#ifndef XQP_LATCH
#define XQP_LATCH

#include <zorba/common/common.h>


namespace xqp
{

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
#else
  #error Latch implemented for PTHREADs only
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
}


#endif
