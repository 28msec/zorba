#include "timeout.h"

#include "runtime/base/plan_iterator.h"

#ifdef WIN32
#include <Windows.h>
#define sleep(n) Sleep(1000*n)
#else
#include <sys/time.h>
#include <limits.h>
#endif

namespace zorba {

  StateWrapper::StateWrapper( PlanState& aState )
    : theState(aState)
  {
  }

  void StateWrapper::doBreak()
  {
    theState.theHasToQuit = true;
  }

  Timeout::Timeout( long aTimeout, const StateWrapper& aWrapper, Mutex* aMutex )
    : theTimeout(aTimeout), theWrapper(aWrapper), theTimeoutMutex(aMutex)
  {
  }

  void Timeout::run()
  {
    suspend(1000*theTimeout);
    // before telling the query to terminate, we request
    // a lock, that allows the timeout thread to properly
    // finish cleanup (i.e. finish Runnable::terminate)
    // that way, the main thread cannot kill us while
    // the status is still running (see assertion in
    // Runnable::terminate)
    theTimeoutMutex->lock();
    theWrapper.doBreak();
  }

  void Timeout::finish()
  {
    theTimeoutMutex->unlock();
  }
} //namespace zorba
