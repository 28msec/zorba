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
#ifndef ZORBA_SEQUENCES_IMPL_H
#define ZORBA_SEQUENCES_IMPL_H

#include <memory>
#include <vector>
#include <stack>

#include "common/shared_types.h"

#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/narybase.h"
#include "runtime/core/path_iterators.h"

#include "store/api/iterator.h"
#include "store/api/iterator_factory.h"

namespace zorba
{

namespace store 
{
  class NodeHashSet;
}

class ValueCollCompareParam;


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.1 General Functions and Operators on Sequences                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////



/*******************************************************************************
  15.4.3 fn:max
  15.4.4 fn:min
********************************************************************************/
class FnMinMaxIterator : public NaryBaseIterator<FnMinMaxIterator, PlanIteratorState> 
{
public:
  enum Type {
    MIN = 0,
    MAX
  };

private:
  Type                       theType;
  CompareConsts::CompareType theCompareType;

public:
  SERIALIZABLE_CLASS(FnMinMaxIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  FnMinMaxIterator,
  NaryBaseIterator<FnMinMaxIterator, PlanIteratorState >);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnMinMaxIterator, PlanIteratorState >*)this);

    SERIALIZE_ENUM(Type, theType);
    SERIALIZE_ENUM(CompareConsts::CompareType, theCompareType);
  }

public:
  FnMinMaxIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& aChildren, 
        Type aType);

  Type getType() const { return theType; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

} /* namespace zorba */
#endif 


/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
