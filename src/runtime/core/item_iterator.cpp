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

#include "diagnostics/assert.h"

#include "compiler/api/compilercb.h"
#include "compiler/expression/function_item_expr.h"
#include "functions/udf.h"

#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/var_iterators.h"
#include "runtime/function_item/function_item.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "runtime/misc/materialize.h"

#include "store/api/item.h"


namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(EmptyIterator)

SERIALIZABLE_CLASS_VERSIONS(SingletonIterator)

SERIALIZABLE_CLASS_VERSIONS(DynamicFunctionIterator)

SERIALIZABLE_CLASS_VERSIONS(IfThenElseIterator)


/*******************************************************************************

********************************************************************************/
bool EmptyIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  return false;
}


NOARY_ACCEPT(EmptyIterator);


/*******************************************************************************

********************************************************************************/
void SingletonIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (NoaryBaseIterator<SingletonIterator,
                                             PlanIteratorState>*)this);
  ar & theValue;
}


/*******************************************************************************

********************************************************************************/
void SingletonIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<PlanIteratorState>::
  createState(planState, theStateOffset, offset);
}


bool SingletonIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  result = theValue;
  STACK_PUSH ( result != NULL, state );
  STACK_END (state);
}


void SingletonIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);
  v.endVisit(*this);
}


uint32_t SingletonIterator::getStateSizeOfSubtree() const
{
  int32_t size = this->getStateSize();
  return size;
}


/*******************************************************************************

********************************************************************************/
void DynamicFunctionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (NoaryBaseIterator<DynamicFunctionIterator,
                      PlanIteratorState>*)this);
  ar & theDynamicFunctionInfo;
  // TODO: add var values?
}


/*******************************************************************************

********************************************************************************/
DynamicFunctionIterator::DynamicFunctionIterator(
      static_context* sctx,
      const QueryLoc& loc,
      CompilerCB* ccb,
      function_item_expr* expr,
      std::vector<store::Item_t>& scopedVarsNames,
      std::vector<PlanIter_t>& scopedVarsValues)
  :
  NaryBaseIterator<DynamicFunctionIterator, PlanIteratorState>(sctx, loc, scopedVarsValues),
  theDynamicFunctionInfo(new DynamicFunctionInfo(ccb, sctx, expr->get_loc(),
                          expr->get_function(), expr->get_qname(), expr->get_arity(),
                          scopedVarsNames, scopedVarsValues))
{
}

bool DynamicFunctionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  std::vector<store::Iterator_t> varsValues;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  varsValues.resize(theChildren.size());
  for (csize i=0; i<theChildren.size(); i++)
  {
    store::Item_t sequence;
    consumeNext(sequence, theChildren[i], planState);
    varsValues[i] = const_cast<MaterializeIterator*>(
            dynamic_cast<const MaterializeIterator*>(theChildren[i].getp()))->getSequenceIterator(planState);
  }
  
  std::cerr << "--> DynamicFunctionIterator::nextImpl() creating function item with params: " << std::endl;
  for (csize i=0; i<theChildren.size(); i++)
  {
    std::cerr << "    " 
        << (theDynamicFunctionInfo->theScopedVarsNames[i].getp() ?
                theDynamicFunctionInfo->theScopedVarsNames[i]->show()
              : "")
        << ": " << varsValues[i]->toString() << std::endl;
  }
  
  result = new FunctionItem(theDynamicFunctionInfo, varsValues);
  
  STACK_PUSH ( result != NULL, state );
  STACK_END (state);
}


void DynamicFunctionIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}


/*******************************************************************************

********************************************************************************/
IfThenElseIterator::IfThenElseIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& aCondIter,
    PlanIter_t& aThenIter,
    PlanIter_t& aElseIter,
    bool aIsBooleanIter)
  :
  Batcher<IfThenElseIterator>(sctx, loc),
  theCondIter(aCondIter),
  theThenIter(aThenIter),
  theElseIter(aElseIter),
  theIsBooleanIter(aIsBooleanIter)
{
}


void IfThenElseIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (Batcher<IfThenElseIterator>*)this);
  ar & theCondIter;
  ar & theThenIter;
  ar & theElseIter;
  ar & theIsBooleanIter;
}


void IfThenElseIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);
  theCondIter->accept(v);
  theThenIter->accept(v);
  theElseIter->accept(v);
  v.endVisit(*this);
}


bool IfThenElseIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  IfThenElseIteratorState* state;
  DEFAULT_STACK_INIT(IfThenElseIteratorState, state, planState);

  if (theIsBooleanIter)
  {
    store::Item_t condResult;
    consumeNext ( condResult, theCondIter.getp(), planState );
    state->theThenUsed = condResult->getBooleanValue();
  }
  else
  {
    state->theThenUsed = FnBooleanIterator::effectiveBooleanValue(this->loc,
                                                                  planState,
                                                                  theCondIter);
  }

  while (true)
  {
    STACK_PUSH(consumeNext(result,
                           (state->theThenUsed ? theThenIter.getp() : theElseIter.getp()),
                           planState),
               state);
  }

  STACK_END(state);
}


void IfThenElseIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<IfThenElseIteratorState>::
  createState(planState, theStateOffset, offset);

  theCondIter->open(planState, offset);
  theThenIter->open(planState, offset);
  theElseIter->open(planState, offset);
}


void IfThenElseIterator::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<IfThenElseIteratorState>::reset(planState, theStateOffset);

  theCondIter->reset(planState);
  theThenIter->reset(planState);
  theElseIter->reset(planState);
}


void IfThenElseIterator::closeImpl(PlanState& planState) const
{
  theCondIter->close(planState);
  theThenIter->close(planState);
  theElseIter->close(planState);

  StateTraitsImpl<IfThenElseIteratorState>::destroyState(planState, theStateOffset);
}


uint32_t IfThenElseIterator::getStateSizeOfSubtree() const
{
  return getStateSize()
      + theCondIter->getStateSizeOfSubtree()
      + theThenIter->getStateSizeOfSubtree()
      + theElseIter->getStateSizeOfSubtree();
}


} /* namespace zorba */

/* vim:set et sw=2 ts=2: */
