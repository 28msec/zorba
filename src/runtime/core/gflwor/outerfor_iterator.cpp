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

#include "system/globalenv.h"

#include "runtime/core/gflwor/outerfor_iterator.h"
#include "runtime/core/gflwor/common.h"

#include "runtime/core/var_iterators.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"

using namespace zorba;

namespace zorba
{
namespace flwor
{
SERIALIZABLE_CLASS_VERSIONS(OuterForIterator)


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OuterFor State                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

void OuterForState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  thePosition = 0;
}

void OuterForState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  thePosition = 0;
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OuterForIterator                                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

// theChild0 --> TupleIterator
// theChild1 --> InputIterator

OuterForIterator::OuterForIterator(
    static_context* sctx,
    const QueryLoc& loc,
    store::Item* aVarName,
    PlanIter_t aTupleIterator,
    PlanIter_t aInput,
    const std::vector<PlanIter_t>& aOuterForVars,
    const std::vector<PlanIter_t>& posRefs)
  :
  BinaryBaseIterator<OuterForIterator, OuterForState>(sctx,
                                                          loc,
                                                          aTupleIterator,
                                                          aInput),
  theVarName (aVarName),
  theOuterForVars(aOuterForVars),
  thePosVarRefs(posRefs)
{
  theHasPosVars = !thePosVarRefs.empty();
}


OuterForIterator::~OuterForIterator()
{
}


void OuterForIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
    (BinaryBaseIterator<OuterForIterator, OuterForState>*)this);

  ar & theVarName;
  ar & theHasPosVars;
  ar & theOuterForVars;
  ar & thePosVarRefs;
}


bool OuterForIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const
{
  store::Item_t lItem;
  store::Item_t lPosItem;

  OuterForState* lState;
  DEFAULT_STACK_INIT(OuterForState, lState, aPlanState);

  while (consumeNext(aResult, theChild0, aPlanState))
  {
    //using a if, to avoid an additional state
    if(consumeNext(lItem, theChild1, aPlanState))
    {
      lState->reset(aPlanState);
      do
      {
        if (theHasPosVars)
        {
          GENV_ITEMFACTORY->createInteger(lPosItem, Integer(lState->incReturnPosition()));
          bindVariables(lPosItem, thePosVarRefs, aPlanState);
        }
        bindVariables(lItem, theOuterForVars, aPlanState);
        STACK_PUSH(true, lState);
      }
      while (consumeNext(lItem, theChild1, aPlanState));
    }
    else
    {
      if (theHasPosVars)
      {
        GENV_ITEMFACTORY->createInteger(lPosItem, Integer(0));
        bindVariables(lPosItem, thePosVarRefs, aPlanState);
      }
      bindVariables(lItem, theOuterForVars, aPlanState);
      STACK_PUSH(true, lState);
    }

    theChild1->reset(aPlanState);
  }

  STACK_END(lState);
}


BINARY_ACCEPT(OuterForIterator);


} //Namespace flwor
}//Namespace zorba
/* vim:set et sw=2 ts=2: */
