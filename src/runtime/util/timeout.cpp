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

  Timeout::Timeout( long aTimeout, const StateWrapper& aWrapper )
    : theTimeout(aTimeout), theWrapper(aWrapper)
  {
  }

  void Timeout::run()
  {
    suspend(1000*theTimeout);
    theWrapper.doBreak();
  }

  void Timeout::finish()
  {
  }
} //namespace zorba
