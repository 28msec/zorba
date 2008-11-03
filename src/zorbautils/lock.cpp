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

#include <cassert>

#include "zorbaerrors/error_manager.h"
#include "zorbautils/fatal.h"
#include "zorbautils/lock.h"


#ifndef ZORBA_FOR_ONE_THREAD_ONLY


namespace zorba { 


/*******************************************************************************

********************************************************************************/
Lock::~Lock()
{
  assert(theMode == NOLOCK);
  assert(theNumWaiters == 0);
  assert(theHolders.empty());
  assert(!theHaveUpgradeReq);
}


/*******************************************************************************

********************************************************************************/
void Lock::rlock()
{
  theMutex.lock();

  ThreadId thisThread = Thread::self();

retry:

  switch (theMode)
  {
  case NOLOCK:
  {
    assert(theNumWaiters == 0);
    assert(theHolders.size() == 0);
    assert(!theHaveUpgradeReq);

    LockRequest req(READ, thisThread);
    theHolders.push_back(req);
    theMode = READ;
    break;
  }
  case READ:
  {
    std::vector<LockRequest>::iterator iter = theHolders.begin();
    std::vector<LockRequest>::iterator end = theHolders.end();
    for (; iter != end; iter++)
    {
      if (iter->theThread == thisThread)
        break;
    }

    if (iter != end)
    {
      iter->theCount++;
    }
    else if (theNumWaiters > 0)
    {
      theNumWaiters++;
      theCondition.wait();
      theNumWaiters--;
      goto retry;
    }
    else
    {
      LockRequest req(READ, thisThread);
      theHolders.push_back(req);
    }

    break;
  }
  case WRITE:
  {
    assert(theHolders.size() == 1);
    assert(!theHaveUpgradeReq);

    if (theHolders[0].theThread == thisThread)
    {
      assert(theHolders[0].theMode == WRITE);
      theHolders[0].theCount++;
    }
    else
    {
      theNumWaiters++;
      theCondition.wait();
      theNumWaiters--;
      goto retry;
    }

    break;
  }
  default:
  {
    ZORBA_FATAL(false, "Corrupted lock structure");
  }
  }

  theMutex.unlock();
}


/*******************************************************************************

********************************************************************************/
void Lock::wlock()
{
  theMutex.lock();

  ThreadId thisThread = Thread::self();

retry:

  switch (theMode)
  {
  case NOLOCK:
  {
    assert(theNumWaiters == 0);
    assert(theHolders.size() == 0);
    assert(!theHaveUpgradeReq);

    LockRequest req(WRITE, thisThread);
    theHolders.push_back(req);
    theMode = WRITE;
    break;
  }
  case READ:
  {
    std::vector<LockRequest>::iterator iter = theHolders.begin();
    std::vector<LockRequest>::iterator end = theHolders.end();
    for (; iter != end; iter++)
    {
      if (iter->theThread == thisThread)
        break;
    }

    if (iter != end)
    {
      // This is an upgrade request

      // If the current thread is the only holder of the lock, the upgrade
      // request is granted immediatelly.
      if (theHolders.size() == 1)
      {
        iter->theMode = WRITE;
        iter->theCount++;
        theMode = WRITE;
        break;
      }

      // If another thread is waiting for an upgrade, allowing the current to
      // wait as well will result in a deadlock. Instead, we throw an exception.
      if (theHaveUpgradeReq)
      {
        theMutex.unlock();
        //ZORBA_ERROR(XQP0030_DEADLOCK);
      }

      // Else, the thread is made to wait
      iter->theUpgrade = true;
      theHaveUpgradeReq = true;
    }

    theNumWaiters++;
    theCondition.wait();
    theNumWaiters--;
    goto retry;
  }
  case WRITE:
  {
    assert(theHolders.size() == 1);

    if (theHolders[0].theThread == thisThread)
    {
      assert(theHolders[0].theMode == WRITE);
      theHolders[0].theCount++;
    }
    else
    {
      theNumWaiters++;
      theCondition.wait();
      theNumWaiters--;
      goto retry;
    }
  }
  default:
  {
    ZORBA_FATAL(false, "Corrupted lock structure");
  }
  }

  theMutex.unlock();
}


/*******************************************************************************

********************************************************************************/
void Lock::unlock()
{
  theMutex.lock();

  ThreadId thisThread = Thread::self();

  if (theMode == WRITE)
  {
    assert(theHolders.size() == 1);
    assert(theHolders[0].theThread == thisThread);
    assert(!theHaveUpgradeReq);

    LockRequest& req = theHolders[0];

    req.theCount--;

    if (req.theCount == 0)
    {
      theMode = NOLOCK;
      theHolders.clear();

      if (theNumWaiters > 0)
        theCondition.broadcast();
    }
  }
  else
  {
    assert(theMode == READ);

    std::vector<LockRequest>::iterator iter = theHolders.begin();
    std::vector<LockRequest>::iterator end = theHolders.end();
    for (; iter != end; iter++)
    {
      if (iter->theThread == thisThread)
        break;
    }

    assert(iter != end);

    LockRequest& req = *iter;

    assert(req.theMode == READ);
    assert(!req.theUpgrade);

    req.theCount--;

    if (req.theCount == 0)
    {
      theHolders.erase(iter);

      if (theHolders.empty())
      {
        theMode = NOLOCK;

        if (theNumWaiters > 0)
          theCondition.broadcast();
      }
      else if (theHaveUpgradeReq && theHolders.size() == 1)
      {
        assert(theNumWaiters > 0);
        assert(theHolders[0].theUpgrade);

        theCondition.broadcast();
      }
    }
  }

  theMutex.unlock();
}

}

#endif // ZORBA_FOR_ONE_THREAD_ONLY
