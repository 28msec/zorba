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
#include "system/globalenv.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "compiler/indexing/value_index.h"

#include "runtime/indexing/value_index_probe.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/store.h" 
#include "store/api/iterator_factory.h"
#include "store/api/index.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(IndexPointProbeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(IndexPointProbeIterator)

SERIALIZABLE_CLASS_VERSIONS(IndexRangeProbeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(IndexRangeProbeIterator)


NARY_ACCEPT(IndexPointProbeIterator);

NARY_ACCEPT(IndexRangeProbeIterator);


/***************************************************************************//**

********************************************************************************/
void IndexPointProbeState::init(PlanState& state)
{
  PlanIteratorState::init(state);
  theQname = NULL;
  theIndex = NULL;
  theIterator = NULL;
}

void IndexPointProbeState::reset(PlanState& state)
{
  PlanIteratorState::reset(state);
  if (theIterator != NULL) {
    theIterator->close();
  }
}


bool IndexPointProbeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qnameItem;
  store::Item_t keyItem;
  ValueIndex_t zorbaIndex;
  store::IndexPointCondition_t cond;
  ulong numChildren;
  ulong i;
  bool status;

  IndexPointProbeState* state;
  DEFAULT_STACK_INIT(IndexPointProbeState, state, planState);

  status = consumeNext(qnameItem, theChildren[0], planState);
  ZORBA_ASSERT(status);

  if (state->theQname == NULL || !state->theQname->equals(qnameItem)) 
  {
    state->theQname = qnameItem;

    if ((zorbaIndex = theSctx->lookup_index(qnameItem)) == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XQP0037_INDEX_IS_NOT_DECLARED, loc,
                            qnameItem->getStringValue()->c_str(), "");
    }

    state->theIndex = (zorbaIndex->isTemp() ?
                       planState.dctx()->getIndex(qnameItem) :
                       GENV_STORE.getIndex(state->theQname));

    if (state->theIndex == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XQP0033_INDEX_DOES_NOT_EXIST, loc,
                            qnameItem->getStringValue()->c_str(), "");
    }

    state->theIterator = GENV_STORE.getIteratorFactory()->
                         createIndexProbeIterator(state->theIndex);
  }

  cond = state->theIndex->createPointCondition();

  numChildren = theChildren.size();
  for(i = 1; i < numChildren; ++i) 
  {
    if (!consumeNext(keyItem, theChildren[i], planState)) 
    {
      break;
    }
    cond->pushItem(keyItem);
  }

  if (i == numChildren)
  {
    state->theIterator->init((const zorba::store::IndexPointCondition_t&)cond);
    state->theIterator->open();

    while(state->theIterator->next(result)) 
    {
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}



/***************************************************************************//**

********************************************************************************/
void IndexRangeProbeState::init(PlanState& state)
{
  PlanIteratorState::init(state);
  theQname = NULL;
  theIndex = NULL;
  theIterator = NULL;
}


void IndexRangeProbeState::reset(PlanState& state)
{
  PlanIteratorState::reset(state);
  if (theIterator != NULL) {
    theIterator->close();
  }
}


bool IndexRangeProbeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;
  ValueIndex_t zorbaIndex;
  store::IndexBoxCondition_t cond;
  int numChildren;
  bool status;
 
  IndexRangeProbeState* state;
  DEFAULT_STACK_INIT(IndexRangeProbeState, state, planState);

  status = consumeNext(qname, theChildren[0], planState);
  ZORBA_ASSERT(status);

  if (state->theQname == NULL || !state->theQname->equals(qname)) 
  {
    state->theQname = qname;

    if ((zorbaIndex = theSctx->lookup_index(qname)) == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XQP0037_INDEX_IS_NOT_DECLARED, loc,
                            qname->getStringValue()->c_str(), "");
    }

    state->theIndex = (zorbaIndex->isTemp() ?
                       planState.dctx()->getIndex(qname) :
                       GENV_STORE.getIndex(state->theQname));

    if (state->theIndex == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XQP0033_INDEX_DOES_NOT_EXIST, loc,
                            qname->getStringValue()->c_str(), "");
    }

    state->theIterator = GENV_STORE.getIteratorFactory()->
                         createIndexProbeIterator(state->theIndex);
  }

  cond = state->theIndex->createBoxCondition();

  numChildren = theChildren.size();
  for(int i = 1; i < numChildren; i += 6) 
  {
    store::Item_t tempLeft;
    store::Item_t tempRight;
    store::Item_t tempHaveLeft;
    store::Item_t tempHaveRight;
    store::Item_t tempInclLeft;
    store::Item_t tempInclRight;

    if (!consumeNext(tempLeft, theChildren[i], planState))
      tempLeft = NULL;
 
    if (!consumeNext(tempRight, theChildren[i + 1], planState))
      tempRight = NULL;
    if (!consumeNext(tempHaveLeft, theChildren[i + 2], planState))
      tempHaveLeft = NULL;

    if (!consumeNext(tempHaveRight, theChildren[i + 3], planState))
      tempHaveRight = NULL;

    if (!consumeNext(tempInclLeft, theChildren[i + 4], planState))
      tempInclLeft = NULL;
 
    if (!consumeNext(tempInclRight, theChildren[i + 5], planState))
      tempInclRight = NULL;

    bool haveLeft = tempHaveLeft != NULL && tempHaveLeft->getBooleanValue();
    bool haveRight = tempHaveRight != NULL && tempHaveRight->getBooleanValue();
    bool inclLeft = tempInclLeft != NULL && tempInclLeft->getBooleanValue();
    bool inclRight = tempInclRight != NULL && tempInclRight->getBooleanValue();

    cond->pushRange(tempLeft, tempRight, haveLeft, haveRight, inclLeft, inclRight);
  }

  state->theIterator->init((const zorba::store::IndexBoxCondition_t&)cond);
  state->theIterator->open();

  while(state->theIterator->next(result)) 
  {
    STACK_PUSH(true, state);
  }

  STACK_END(state);
}



}
/* vim:set ts=2 sw=2: */
