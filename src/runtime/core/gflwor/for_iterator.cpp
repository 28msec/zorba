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

#include "runtime/core/gflwor/for_iterator.h"
#include "runtime/core/gflwor/common.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item_factory.h"

namespace zorba 
{
namespace flwor 
{
SERIALIZABLE_CLASS_VERSIONS(ForIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ForIterator)

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  For  State                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

void ForState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  thePosition = 0;
}

void ForState::reset(PlanState& planState) 
{
  PlanIteratorState::reset(planState);
  thePosition = 0;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ForIterator                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


ForIterator::ForIterator (
    static_context* sctx,
    const QueryLoc& loc,
    store::Item* varName,
    PlanIter_t tupleIter,
    PlanIter_t domainIter,
    const std::vector<PlanIter_t>& varRefs)
  :
  BinaryBaseIterator<ForIterator, ForState>(sctx, loc, tupleIter, domainIter),
  theVarName(varName),
  theHasPosVars(false),
  theVarRefs(varRefs)
{
}


ForIterator::ForIterator (
    static_context* sctx,
    const QueryLoc& loc,
    store::Item* varName,
    PlanIter_t tupleIter,
    PlanIter_t domainIter,
    const std::vector<PlanIter_t>& varRefs,
    const std::vector<PlanIter_t>& posRefs) 
  :
  BinaryBaseIterator<ForIterator, ForState>(sctx, loc, tupleIter, domainIter),
  theVarName(varName),
  theVarRefs(varRefs),
  thePosVarRefs(posRefs)
{
  theHasPosVars = !thePosVarRefs.empty();
}


ForIterator::~ForIterator() 
{
}


void ForIterator::accept(PlanIterVisitor& v) const 
{ 
  v.beginVisit(*this); 

  v.beginVisitFlworForVariable(theVarName->getStringValue(),
                               theVarRefs,
                               thePosVarRefs);
  v.endVisitFlworForVariable();

  theChild0->accept(v); 
  theChild1->accept(v); 

  v.endVisit(*this);
}


bool ForIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const 
{
  ForState* lState;
  store::Item_t lItem;
      
  DEFAULT_STACK_INIT(ForState, lState, aPlanState);

  while (consumeNext(aResult, theChild0, aPlanState)) 
  {
    while (consumeNext(lItem, theChild1, aPlanState)) 
    {
      bindVariables(lItem, theVarRefs, aPlanState);

      if (theHasPosVars) 
      {
        store::Item_t lPosItem;
        GENV_ITEMFACTORY->createInteger(lPosItem,
                                        xs_integer(lState->incReturnPosition()));
        bindVariables(lPosItem, thePosVarRefs, aPlanState);
      }
      STACK_PUSH(true, lState);
    }

    lState->resetPosition();

    theChild1->reset(aPlanState);
  }

  STACK_END(lState);
}
  
} //Namespace flwor
}//Namespace zorba
/* vim:set et sw=2 ts=2: */
