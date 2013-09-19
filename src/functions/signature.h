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
#pragma once
#ifndef ZORBA_FUNCTIONS_SIGNATURE_H
#define ZORBA_FUNCTIONS_SIGNATURE_H

#include "zorbautils/checked_vector.h"

#include "common/shared_types.h"

#include "types/root_typemanager.h"

namespace zorba {

class function;

#define VARIADIC_SIG_SIZE 1000000

/*******************************************************************************

  theQName :
  the qname of the function

  theTypes:
  The return type and the paremater types. By convention, theTypes[0] holds the
  return type, theTypes[1] holds the first param type, theTypes[2] holds the 2nd
  param type, etc.

  theNonOptimizedReturnType:
  This is the original, non-optimized return type of a function. Used in function
  literals type checks.

  theIsVariadic:
  Whether thefunction is variadic.

********************************************************************************/
class signature: public SimpleRCObject
{
 protected:
  store::Item_t            theQName;
  checked_vector<xqtref_t> theTypes;
  xqtref_t                 theNonOptimizedReturnType;
  bool                     theIsVariadic;

 public:
  SERIALIZABLE_CLASS(signature)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(signature, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  signature(
        const store::Item_t& name,
        const xqtref_t& paramType1,
        bool variadic,
        const xqtref_t& returnType);

  signature(
        const store::Item_t& name,
        const xqtref_t& paramType1,
        const xqtref_t& paramType2,
        bool variadic,
        const xqtref_t& returnType);

  signature(
        const store::Item_t& name,
        const xqtref_t& returnType);

  signature(
        const store::Item_t& name,
        const xqtref_t& paramType1,
        const xqtref_t& returnType);

  signature(
        const store::Item_t& name,
        const xqtref_t& paramType1,
        const xqtref_t& paramType2,
        const xqtref_t& returnType);

  signature(
        const store::Item_t& name,
        const xqtref_t& paramType1,
        const xqtref_t& paramType2,
        const xqtref_t& paramType3,
        const xqtref_t& returnType);

  signature(
        const store::Item_t& name,
        const xqtref_t& paramType1,
        const xqtref_t& paramType2,
        const xqtref_t& paramType3,
        const xqtref_t& paramType4,
        const xqtref_t& returnType);

  signature(
        const store::Item_t& name,
        const xqtref_t& paramType1,
        const xqtref_t& paramType2,
        const xqtref_t& paramType3,
        const xqtref_t& paramType4,
        const xqtref_t& paramType5,
        const xqtref_t& returnType);

  signature(
        const store::Item_t& name,
        const xqtref_t& paramType1,
        const xqtref_t& paramType2,
        const xqtref_t& paramType3,
        const xqtref_t& paramType4,
        const xqtref_t& paramType5,
        const xqtref_t& paramType6,
        const xqtref_t& returnType);

  signature(
        const store::Item_t& name,
        const xqtref_t& paramType1,
        const xqtref_t& paramType2,
        const xqtref_t& paramType3,
        const xqtref_t& paramType4,
        const xqtref_t& paramType5,
        const xqtref_t& paramType6,
        const xqtref_t& paramType7,
        const xqtref_t& returnType);

  signature(
        const store::Item_t& name,
        const xqtref_t& paramType1,
        const xqtref_t& paramType2,
        const xqtref_t& paramType3,
        const xqtref_t& paramType4,
        const xqtref_t& paramType5,
        const xqtref_t& paramType6,
        const xqtref_t& paramType7,
        const xqtref_t& paramType8,
        const xqtref_t& returnType);

  signature(
        const store::Item_t& name,
        const std::vector<xqtref_t>& paramTypes,
        const xqtref_t& returnType,
        bool isVariadic = false);

  store::Item* getName() const   { return theQName.getp(); }

  bool isVariadic() const { return theIsVariadic; }

  size_t paramCount() const
  {
    return isVariadic() ? VARIADIC_SIG_SIZE : (uint32_t)(theTypes.size() - 1);
  }

  size_t definedParamCount() const
  {
    return (uint32_t)(theTypes.size() - 1);
  }

  xqtref_t const& operator[](int i) const
  {
    return theTypes[theIsVariadic
                      ? i >= (int)theTypes.size() - 1
                        ? theTypes.size() - 1
                        : i + 1
                      : i + 1];
  }

  xqtref_t& operator[](int i)
  {
    return theTypes[theIsVariadic
                      ? i >= (int)theTypes.size() - 1
                        ? theTypes.size() - 1
                        : i + 1
                      : i + 1];
  }

  const xqtref_t& returnType() const { return theTypes[0]; }

  xqtref_t& returnType() { return theTypes[0]; }

  const xqtref_t& getNonOptimizedReturnType() const { return theNonOptimizedReturnType; }

  void setNonOptimizedReturnType(const xqtref_t& nonOptimizedReturnType)
  {
    theNonOptimizedReturnType = nonOptimizedReturnType;
  }

  bool equals(
      const TypeManager* tm,
      const signature& s,
      const QueryLoc& loc) const;

  bool subtype(
      const TypeManager* tm,
      const function* func,
      const signature& s,
      const QueryLoc& loc) const;
};

} /* namespace zorba */
#endif  /* ZORBA_SIGNATURE_H */


/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
