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
#include "stdafx.h"

#include "zorbatypes/rchandle.h"

#include "zorbaserialization/archiver.h"

#include "diagnostics/assert.h"

namespace zorba 
{


/*******************************************************************************
  
  Base class for reference counted objects

  Any class wishing to take advantage of automatic reference counting
  must inherit from this class.

  rcobject encapsulates the reference count, as well as functions
  for incrementing and decrementing the count. It also contains code
  for destroying a value when it is no longer in use, i.e., when its
  reference count becomes 0.

********************************************************************************/

SERIALIZABLE_CLASS_VERSIONS(RCObject)

SERIALIZABLE_CLASS_VERSIONS_2(SimpleRCObject, TYPE_RCObject)


void RCObject::serialize(::zorba::serialization::Archiver& ar)
{
  ZORBA_ASSERT(false);

  if (!ar.is_serializing_out())
    theRefCount = 0;
}


void RCObject::addReference(SYNC_CODE(RCLock* lock)) const
{
#if defined WIN32 && !defined CYGWIN &&!defined ZORBA_FOR_ONE_THREAD_ONLY
  if(lock)
  {
    InterlockedIncrement(&theRefCount);
  }
  else
  {
    ++theRefCount;
  }

#else

  SYNC_CODE(if (lock) lock->acquire());

  ++theRefCount;

  SYNC_CODE(if (lock) lock->release());

#endif
}


void RCObject::removeReference(SYNC_CODE(RCLock* lock))
{
#if defined WIN32 && !defined CYGWIN &&!defined ZORBA_FOR_ONE_THREAD_ONLY
  if (lock)
  {
    if (!InterlockedDecrement(&theRefCount))
    {
      free();
      return;
    }
  }
  else
  {
    if (--theRefCount == 0)
    {
      free();
      return; 
    }
  }

#else

  SYNC_CODE(if (lock) lock->acquire());

  if (--theRefCount == 0)
  {
    SYNC_CODE(if (lock) lock->release());
    free();
    return; 
  }

  SYNC_CODE(if (lock) lock->release());

#endif
}


/*******************************************************************************

********************************************************************************/
void SimpleRCObject::serialize(::zorba::serialization::Archiver& ar)
{
  ZORBA_ASSERT(false);

  if (!ar.is_serializing_out())
    theRefCount = 0;
}


} /* namespace zorba */

/* vim:set et sw=2 ts=2: */
