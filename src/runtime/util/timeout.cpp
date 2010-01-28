/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
