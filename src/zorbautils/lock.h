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
#ifndef ZORBA_STORE_LOCK_H
#define ZORBA_STORE_LOCK_H

#ifndef ZORBA_FOR_ONE_THREAD_ONLY

#include<vector>

#include "zorbamisc/config/platform.h"

#include "zorbautils/thread.h"
#include "zorbautils/mutex.h"
#include "zorbautils/condition.h"

namespace zorba { 


/*******************************************************************************

********************************************************************************/

class Lock
{
public:
  enum Mode { NOLOCK, READ, WRITE };

protected:
  class LockRequest
  {
    friend class Lock;

    Lock::Mode    theMode;
    ulong         theCount;
    bool          theUpgrade;
    ThreadId      theThread;

    LockRequest(Mode m, ThreadId t)
      :
      theMode(m),
      theCount(1),
      theUpgrade(false),
      theThread(t)
    {
    }
  };

protected:
  Mutex                     theMutex;
  Condition                 theCondition;

  Mode                      theMode;
  bool                      theHaveUpgradeReq;
  ulong                     theNumWaiters;
  std::vector<LockRequest>  theHolders;

public:
  Lock()
    :
    theCondition(theMutex),
    theMode(NOLOCK),
    theHaveUpgradeReq(false),
    theNumWaiters(0)
  {
  }

  ~Lock();

#ifdef ZORBA_HAVE_PTHREAD_H    
  void rlock();
  void wlock();
  void unlock();
#else
  void rlock() {}
  void wlock() {}
  void unlock() {}
#endif

 private:
  Lock(const Lock &);
  void operator=(const Lock &);
};



/*******************************************************************************

********************************************************************************/
class AutoLock
{
private:
  Lock & theLock;

public:
  AutoLock(Lock& l, Lock::Mode m) : theLock(l)
  {
    if (m == Lock::READ)
      theLock.rlock();
    else
      theLock.wlock();
  }
    
  ~AutoLock()
  {
    theLock.unlock();
  }
};


}

#endif // ZORBA_FOR_ONE_THREAD_ONLY

#endif


