
#include "zorbatypes/rchandle.h"
#include <sstream>
#include <iostream>
#include <cstdlib>

#include <zorba/config.h>
#include "common/common.h"
#include "zorbautils/fatal.h"

namespace zorba {


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
    long* sharedCounter
    SYNC_PARAM2(RCLock* lock)) const
{
#if defined WIN32 && !defined CYGWIN &&!defined ZORBA_FOR_ONE_THREAD_ONLY
  if(lock)
  {
    if (sharedCounter) InterlockedIncrement(sharedCounter);
    InterlockedIncrement(&theRefCount);
  }
  else
  {
    if (sharedCounter) ++(*sharedCounter);
    ++theRefCount;
  }

#else

  SYNC_CODE(if (lock) lock->acquire());

  if (sharedCounter) ++(*sharedCounter);
  ++theRefCount;

  SYNC_CODE(if (lock) lock->release());

#endif
}


void RCObject::removeReference (
    long* sharedCounter 
    SYNC_PARAM2(RCLock* lock))
{
#if defined WIN32 && !defined CYGWIN &&!defined ZORBA_FOR_ONE_THREAD_ONLY
  if(lock)
  {
    if (sharedCounter)
    {
      InterlockedDecrement(&theRefCount);
      if (!InterlockedDecrement(sharedCounter))
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
    if (sharedCounter)
    {
      --theRefCount;
      if (--(*sharedCounter) == 0)
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

  if (sharedCounter)
  {
    --theRefCount;
    if (--(*sharedCounter) == 0)
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

