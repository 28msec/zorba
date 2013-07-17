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

SERIALIZABLE_CLASS_VERSIONS(SyncedRCObject)

SERIALIZABLE_CLASS_VERSIONS_2(SimpleRCObject, TYPE_SimpleRCObject)


/*******************************************************************************

********************************************************************************/
void SyncedRCObject::serialize(::zorba::serialization::Archiver& ar)
{
  ZORBA_ASSERT(false);

  if (!ar.is_serializing_out())
    theRefCount = 0;
}


/*******************************************************************************

********************************************************************************/
void SimpleRCObject::serialize(::zorba::serialization::Archiver& ar)
{
  ZORBA_ASSERT(false);

  if (!ar.is_serializing_out())
    theRefCount = 0;
}


size_t SimpleRCObject::alloc_size() const
{
  return 0;
}


size_t SimpleRCObject::dynamic_size() const
{
  return sizeof( *this );
}


} /* namespace zorba */

/* vim:set et sw=2 ts=2: */
