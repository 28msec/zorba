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

#define VARIADIC_SIG_SIZE 1000000

/*******************************************************************************

  By convention, theTypes[0]    = return type
                 theTypes[1]    = first param type
                 theTypes[2]    = second param type
                  ...       =  ...

********************************************************************************/
class signature: public SimpleRCObject
{
 protected:
  store::Item_t            theQName;
  checked_vector<xqtref_t> theTypes;
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

  bool equals(
      const TypeManager* tm,
      const signature& s,
      const QueryLoc& loc) const;

  bool subtype(
      const TypeManager* tm,
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
