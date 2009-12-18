#ifndef TIMEOUT_H
#define TIMEOUT_H
#include "zorbautils/runnable.h"

namespace zorba {
  class PlanState;

  class StateWrapper {
  private:
    PlanState& theState;

  public:
    StateWrapper(PlanState& aState);

    void doBreak();
  };

  class Timeout : public Runnable {
  private:
    long theTimeout;
    StateWrapper theWrapper;
    Mutex* theTimeoutMutex; // shared with PlanWrapper

  public:
    Timeout(long aTimeout, const StateWrapper& aWrapper, Mutex* aMutex);

    virtual void run();
    // Note: this method is not allowd to throw an exception!
    virtual void finish();
  };
} //namespace zorba

#endif //TIMEOUT_H
