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

#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/var_iterators.h"
#include "runtime/function_item/function_item.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"



namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(EmptyIterator)

SERIALIZABLE_CLASS_VERSIONS(SingletonIterator)

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

  if (theValue->isFunction())
  {
    FunctionItem* fnItem = static_cast<FunctionItem*>(theValue.getp());
    const std::vector<PlanIter_t> variableValues = fnItem->getVariables();
    std::vector<store::Iterator_t> wrappers;
    wrappers.resize(variableValues.size());
    for (unsigned int i=0; i<variableValues.size(); i++)
    {
      variableValues[i]->open(planState, offset);

      wrappers[i] = new PlanIteratorWrapper(variableValues[i], planState);

      std::cerr << "--> SingletonIterator::nextImp() " << theId <<" wrapping " << variableValues[i]->getId() << " = " << variableValues[i]->getClassName();

      SingletonIterator* singletonIter = dynamic_cast<SingletonIterator*>(variableValues[i].getp());
      LetVarIterator* letVarIter = dynamic_cast<LetVarIterator*>(variableValues[i].getp());
      if (singletonIter != NULL)
      {
        std::cerr << " value: " << singletonIter->getValue()->show()
            << " with PlanIteratorWrapper: " << wrappers[i] << std::endl;
      }
      else if (letVarIter != NULL)
      {
        std::cerr << " varName: " << letVarIter->getVarName()->getStringValue()
            << " with PlanIteratorWrapper: " << wrappers[i] << std::endl;
      }
      else
      {
        std::cerr
            << " with PlanIteratorWrapper: " << wrappers[i] << std::endl;
      }
    }

    fnItem->setVariableWrappers(wrappers);
  }
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

  if (theValue->isFunction())
  {
    const std::vector<PlanIter_t> variableValues = static_cast<FunctionItem*>(theValue.getp())->getVariables();
    for (unsigned int i=0; i<variableValues.size(); i++)
      variableValues[i]->accept(v);
  }

  v.endVisit(*this);
}

uint32_t SingletonIterator::getStateSizeOfSubtree() const
{
  int32_t size = this->getStateSize();

  if (theValue->isFunction())
  {
    const std::vector<PlanIter_t> variableValues = static_cast<FunctionItem*>(theValue.getp())->getVariables();
    for (unsigned int i=0; i<variableValues.size(); i++)
      size += variableValues[i]->getStateSizeOfSubtree();
  }

  return size;
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
