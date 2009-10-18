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
#include "zorbaerrors/error_manager.h"

#include "system/globalenv.h"

#include "types/typeimpl.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "indexing/value_index.h"

#include "runtime/indexing/value_index_impl.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "store/api/store.h"
#include "store/api/iterator_factory.h"
#include "store/api/item_factory.h"
#include "store/api/pul.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(CreateInternalIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CreateInternalIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(CreateIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CreateIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(RefreshIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(RefreshIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(DropIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(DropIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(IndexEntryBuilderIterator)
END_SERIALIZABLE_CLASS_VERSIONS(IndexEntryBuilderIterator)

SERIALIZABLE_CLASS_VERSIONS(IndexPointProbeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(IndexPointProbeIterator)

SERIALIZABLE_CLASS_VERSIONS(IndexRangeProbeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(IndexRangeProbeIterator)

UNARY_ACCEPT(CreateInternalIndexIterator);

UNARY_ACCEPT(CreateIndexIterator);

UNARY_ACCEPT(RefreshIndexIterator);

UNARY_ACCEPT(DropIndexIterator);

NARY_ACCEPT(IndexEntryBuilderIterator);

NARY_ACCEPT(IndexPointProbeIterator);

NARY_ACCEPT(IndexRangeProbeIterator);


/*******************************************************************************

********************************************************************************/
static void createIndexSpec(
    ValueIndex* zorbaIndex,
    store::IndexSpecification& spec)
{
  const std::vector<xqtref_t>& keyTypes(zorbaIndex->getKeyTypes());
  const std::vector<OrderModifier>& keyModifiers(zorbaIndex->getOrderModifiers());
  ulong numColumns = keyTypes.size();

  spec.resize(numColumns);

  for(ulong i = 0; i < numColumns; ++i) 
  {
    const XQType& t = *keyTypes[i];
    spec.theKeyTypes[i] = t.get_qname();
    spec.theCollations.push_back(keyModifiers[i].theCollation);
  }

  spec.theIsUnique = zorbaIndex->getUnique();
  spec.theIsSorted = zorbaIndex->getMethod() == ValueIndex::BTREE;
  spec.theIsTemp = zorbaIndex->isTemp();
  spec.theIsThreadSafe = true;
}


/***************************************************************************//**

********************************************************************************/
bool CreateInternalIndexIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  ValueIndex* zorbaIndex;
  store::IndexSpecification spec;
  store::Iterator_t planIteratorWrapper;
  store::Index_t storeIndex;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  zorbaIndex = theSctx->lookup_index(theQName);
  ZORBA_ASSERT(zorbaIndex);

  planIteratorWrapper = new PlanIteratorWrapper(theChild, planState);

  createIndexSpec(zorbaIndex, spec);

  try
  {
    storeIndex = GENV_STORE.createIndex(zorbaIndex->getName(), spec, planIteratorWrapper);
  }
  catch(error::ZorbaError& e)
  {
    // Store raises error if index exists already
    ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
  }

  try
  {
    planState.dctx()->bindIndex(zorbaIndex->getName(), storeIndex);
  }
  catch(...)
  {
    // Dynamic context raises error if index exists already
    GENV_STORE.deleteIndex(zorbaIndex->getName());
    throw;
  }

  STACK_END (state);
}



/***************************************************************************//**

********************************************************************************/
bool CreateIndexIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;
  ValueIndex_t zorbaIndex;
  store::IndexSpecification spec;
  PlanIterator* buildPlan;
  store::Iterator_t planWrapper;

  dynamic_context* dctx = planState.dctx();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if ((zorbaIndex = theSctx->lookup_index(qname)) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0037_INDEX_IS_NOT_DECLARED, loc,
                          qname->getStringValue()->c_str(), "");
  }

  if (dctx->getIndex(qname) != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0034_INDEX_ALREADY_EXISTS, loc,
                          qname->getStringValue()->c_str(), "");
  }

  buildPlan = zorbaIndex->getBuildPlan(planState.theCompilerCB, loc);

  planWrapper = new PlanWrapper(buildPlan, planState.theCompilerCB, dctx,
                                0); // no query, yet and hence no external functions

  createIndexSpec(zorbaIndex, spec);

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addCreateIndex(qname, spec, planWrapper);

  STACK_PUSH(true, state);

  STACK_END(state);
}


/***************************************************************************//**

********************************************************************************/
bool DropIndexIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if (theSctx->lookup_index(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0037_INDEX_IS_NOT_DECLARED, loc,
                          qname->getStringValue()->c_str(), "");
  }

  if (GENV_STORE.getIndex(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0033_INDEX_DOES_NOT_EXIST, loc,
                          qname->getStringValue()->c_str(), "");
  }

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addDropIndex(qname);

  STACK_PUSH(true, state);

  STACK_END(state);
}


/***************************************************************************//**

********************************************************************************/
bool RefreshIndexIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;
  ValueIndex_t zorbaIndex;
  PlanIterator* buildPlan;
  store::Iterator_t planWrapper;

  dynamic_context* dctx = planState.dctx();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if ((zorbaIndex = theSctx->lookup_index(qname)) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0037_INDEX_IS_NOT_DECLARED, loc,
                          qname->getStringValue()->c_str(), "");
  }

  if (GENV_STORE.getIndex(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0033_INDEX_DOES_NOT_EXIST, loc,
                          qname->getStringValue()->c_str(), "");
  }

  buildPlan = zorbaIndex->getBuildPlan(planState.theCompilerCB, loc);

  planWrapper = new PlanWrapper(buildPlan, planState.theCompilerCB, dctx,
                                0); // no query, yet and hence no external functions
  
  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addRefreshIndex(qname, planWrapper);

  STACK_PUSH(true, state);

  STACK_END(state);
}


/***************************************************************************//**

********************************************************************************/
void IndexEntryBuilderIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  theCurChild = 0;
}


void IndexEntryBuilderIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset(planState);
  theCurChild = 0;
}


bool IndexEntryBuilderIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  IndexEntryBuilderIteratorState* state;
  DEFAULT_STACK_INIT(IndexEntryBuilderIteratorState, state, planState);

  for (; state->theCurChild < theChildren.size(); ++state->theCurChild) 
  {
    if (!consumeNext(result, theChildren[state->theCurChild].getp(), planState))
      result = NULL;

    STACK_PUSH(true, state);
  }
  
  STACK_END(state);
}


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
  store::Item_t qname;
  ValueIndex_t zorbaIndex;
  store::IndexPointCondition_t cond;
  int numChildren;
  bool status;

  IndexPointProbeState* state;
  DEFAULT_STACK_INIT(IndexPointProbeState, state, planState);

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

  cond = state->theIndex->createPointCondition();

  numChildren = theChildren.size();
  for(int i = 1; i < numChildren; ++i) 
  {
    store::Item_t temp;
    if (!consumeNext(temp, theChildren[i], planState)) 
    {
      temp = NULL;
    }
    cond->pushItem(temp);
  }

  state->theIterator->init((const zorba::store::IndexPointCondition_t&)cond);
  state->theIterator->open();

  while(state->theIterator->next(result)) 
  {
    STACK_PUSH(true, state);
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
