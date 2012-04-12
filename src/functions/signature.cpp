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

#include "signature.h"

#include "store/api/item.h"

#include "types/typeops.h"

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"

#include <iterator>


namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(signature)


signature::signature(
    const store::Item_t& name,
    const xqtref_t& paramType1,
    bool variadic,
    const xqtref_t& returnType)
  :
  theQName(name),
  theIsVariadic(variadic)
{
  theTypes.push_back(returnType);
  theTypes.push_back(paramType1);
}


signature::signature(
    const store::Item_t& name,
    const xqtref_t& returnType)
  :
  theQName(name),
  theIsVariadic(false)
{
  theTypes.push_back(returnType);
}


signature::signature(
    const store::Item_t& name,
    const xqtref_t& paramType1,
    const xqtref_t& returnType)
  :
  theQName(name),
  theIsVariadic(false)
{
  theTypes.push_back(returnType);
  theTypes.push_back(paramType1);
}


signature::signature(
    const store::Item_t& name,
    const xqtref_t& paramType1,
    const xqtref_t& paramType2,
    const xqtref_t& returnType)
  :
  theQName(name),
  theIsVariadic(false)
{
  theTypes.push_back(returnType);
  theTypes.push_back(paramType1);
  theTypes.push_back(paramType2);
}


signature::signature(
    const store::Item_t& name,
    const xqtref_t& paramType1,
    const xqtref_t& paramType2,
    const xqtref_t& paramType3,
    const xqtref_t& returnType)
  :
  theQName(name),
  theIsVariadic(false)
{
  theTypes.push_back(returnType);
  theTypes.push_back(paramType1);
  theTypes.push_back(paramType2);
  theTypes.push_back(paramType3);
}


signature::signature(
    const store::Item_t& name,
    const xqtref_t& paramType1,
    const xqtref_t& paramType2,
    const xqtref_t& paramType3,
    const xqtref_t& paramType4,
    const xqtref_t& returnType)
  :
  theQName(name),
  theIsVariadic(false)
{
  theTypes.push_back(returnType);
  theTypes.push_back(paramType1);
  theTypes.push_back(paramType2);
  theTypes.push_back(paramType3);
  theTypes.push_back(paramType4);
}


signature::signature(
    const store::Item_t& name,
    const xqtref_t& paramType1,
    const xqtref_t& paramType2,
    const xqtref_t& paramType3,
    const xqtref_t& paramType4,
    const xqtref_t& paramType5,
    const xqtref_t& returnType)
  :
  theQName(name),
  theIsVariadic(false)
{
  theTypes.push_back(returnType);
  theTypes.push_back(paramType1);
  theTypes.push_back(paramType2);
  theTypes.push_back(paramType3);
  theTypes.push_back(paramType4);
  theTypes.push_back(paramType5);
}


signature::signature(
    const store::Item_t& name,
    const xqtref_t& paramType1,
    const xqtref_t& paramType2,
    const xqtref_t& paramType3,
    const xqtref_t& paramType4,
    const xqtref_t& paramType5,
    const xqtref_t& paramType6,
    const xqtref_t& returnType)
  :
  theQName(name),
  theIsVariadic(false)
{
  theTypes.push_back(returnType);
  theTypes.push_back(paramType1);
  theTypes.push_back(paramType2);
  theTypes.push_back(paramType3);
  theTypes.push_back(paramType4);
  theTypes.push_back(paramType5);
  theTypes.push_back(paramType6);
}


signature::signature(
    const store::Item_t& name,
    const xqtref_t& paramType1,
    const xqtref_t& paramType2,
    const xqtref_t& paramType3,
    const xqtref_t& paramType4,
    const xqtref_t& paramType5,
    const xqtref_t& paramType6,
    const xqtref_t& paramType7,
    const xqtref_t& returnType)
  :
  theQName(name),
  theIsVariadic(false)
{
  theTypes.push_back(returnType);
  theTypes.push_back(paramType1);
  theTypes.push_back(paramType2);
  theTypes.push_back(paramType3);
  theTypes.push_back(paramType4);
  theTypes.push_back(paramType5);
  theTypes.push_back(paramType6);
  theTypes.push_back(paramType7);
}


signature::signature(
    const store::Item_t& name,
    const xqtref_t& paramType1,
    const xqtref_t& paramType2,
    const xqtref_t& paramType3,
    const xqtref_t& paramType4,
    const xqtref_t& paramType5,
    const xqtref_t& paramType6,
    const xqtref_t& paramType7,
    const xqtref_t& paramType8,
    const xqtref_t& returnType)
  :
  theQName(name),
  theIsVariadic(false)
{
  theTypes.push_back(returnType);
  theTypes.push_back(paramType1);
  theTypes.push_back(paramType2);
  theTypes.push_back(paramType3);
  theTypes.push_back(paramType4);
  theTypes.push_back(paramType5);
  theTypes.push_back(paramType6);
  theTypes.push_back(paramType7);
  theTypes.push_back(paramType8);
}


signature::signature(
    const store::Item_t& name,
    const std::vector<xqtref_t>& types,
    const xqtref_t& returnType,
    bool isVariadic)
  :
  theQName(name),
  theIsVariadic(isVariadic)
{
  theTypes.push_back(returnType);
  std::copy(types.begin(), types.end(), std::back_inserter(theTypes));
}


void signature::serialize(::zorba::serialization::Archiver& ar)
{
  //serialize_baseclass(ar, (SimpleRCObject*)this);
  ar & theQName;
  ar & theTypes;
  ar & theIsVariadic;
}


bool signature::equals(
    const TypeManager* tm,
    const signature& s,
    const QueryLoc& loc) const
{
  if (paramCount() != s.paramCount())
    return false;

  if (!theQName->equals(s.theQName.getp()))
    return false;

  assert (s.theTypes.size() == theTypes.size() || theIsVariadic );
  for (csize i = 0; i < s.theTypes.size(); ++i)
  {
    if (!TypeOps::is_equal(tm,
                           *theTypes[i].getp(),
                           *s.theTypes[i].getp(), 
                           loc))
    {
      return false;
    }
  }

  return true;
}


bool signature::subtype(
    const TypeManager* tm,
    const signature& s,
    const QueryLoc& loc) const
{
  if (paramCount() != s.paramCount())
    return false;

  if (!theQName->equals(s.theQName.getp()))
    return false;

  assert (s.theTypes.size() == theTypes.size() || theIsVariadic );
  for (csize i = 0; i < theTypes.size(); ++i)
  {
    if (!TypeOps::is_subtype(tm,
                             *theTypes[i].getp(),
                             *s.theTypes[i].getp(), 
                             loc))
    {
      return false;
    }
  }

  return true;
}

} /* namespace zorba */

/* vim:set et sw=2 ts=2: */
