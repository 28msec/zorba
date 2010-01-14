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
#include "store/api/store.h"        // for checking if index exists
#include "store/api/item_factory.h" // for creating pul
#include "store/api/iterator_factory.h" // for creating the probe iterator
#include "store/api/pul.h"
#include "store/api/index.h"

#include "runtime/indexing/index_ddl.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "compiler/indexing/value_index.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"


namespace zorba 
{

/*******************************************************************************

********************************************************************************/
void createIndexSpec(
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
  spec.theIsSorted = zorbaIndex->getMethod() == ValueIndex::TREE;
  spec.theIsTemp = zorbaIndex->isTemp();
  spec.theIsThreadSafe = true;
  spec.theIsAutomatic = zorbaIndex->getMaintenanceMode() != ValueIndex::MANUAL;

  ulong numSources = zorbaIndex->numSources();

  spec.theSources.resize(numSources);

  for (ulong i = 0; i < numSources; ++i)
  {
    spec.theSources[i] = const_cast<store::Item*>(zorbaIndex->getSourceName(i));
  }
}


/*******************************************************************************

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


/*******************************************************************************

********************************************************************************/
bool CreateIndexIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;
  ValueIndex_t zorbaIndex;
  store::IndexSpecification spec;
  PlanIter_t buildPlan;
  store::Iterator_t planWrapper;

  CompilerCB* ccb = planState.theCompilerCB;
  dynamic_context* dctx = planState.dctx();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if ((zorbaIndex = theSctx->lookup_index(qname)) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0021_INDEX_IS_NOT_DECLARED, loc,
                          qname->getStringValue()->c_str(), "");
  }

  if (GENV_STORE.getIndex(qname) != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0022_INDEX_EXISTS_ALREADY, loc,
                          qname->getStringValue()->c_str(), "");
  }

  buildPlan = zorbaIndex->getBuildPlan(ccb, loc); 
  
  planWrapper = new PlanWrapper(buildPlan, ccb, dctx, NULL); 

  createIndexSpec(zorbaIndex, spec);

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addCreateIndex(qname, spec, planWrapper);

  STACK_PUSH(true, state);

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool DeleteIndexIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if (theSctx->lookup_index(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0021_INDEX_IS_NOT_DECLARED, loc,
                          qname->getStringValue()->c_str(), "");
  }

  if (GENV_STORE.getIndex(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0023_INDEX_DOES_NOT_EXIST, loc,
                          qname->getStringValue()->c_str(), "");
  }

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addDeleteIndex(qname);

  STACK_PUSH(true, state);

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool RefreshIndexIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t qname;
  ValueIndex_t zorbaIndex;
  PlanIter_t buildPlan;
  store::Iterator_t planWrapper;

  dynamic_context* dctx = planState.dctx();
  CompilerCB* ccb = planState.theCompilerCB;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if ((zorbaIndex = theSctx->lookup_index(qname)) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0021_INDEX_IS_NOT_DECLARED, loc,
                          qname->getStringValue()->c_str(), "");
  }

  if (GENV_STORE.getIndex(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0023_INDEX_DOES_NOT_EXIST, loc,
                          qname->getStringValue()->c_str(), "");
  }

  buildPlan = zorbaIndex->getBuildPlan(ccb, loc); 
  
  planWrapper = new PlanWrapper(buildPlan, ccb, dctx, NULL); 

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addRefreshIndex(qname, planWrapper);

  STACK_PUSH(true, state);

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
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


/*******************************************************************************

********************************************************************************/
void IndexPointProbeIteratorState::reset(PlanState& state)
{
  PlanIteratorState::reset(state);
  if (theIterator != NULL) 
  {
    theIterator->close();
  }
}


bool IndexPointProbeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qnameItem;
  store::Item_t keyItem;
  ValueIndex_t indexDecl;
  store::IndexPointCondition_t cond;
  ulong numChildren = theChildren.size();
  ulong i;
  bool status;

  IndexPointProbeIteratorState* state;
  DEFAULT_STACK_INIT(IndexPointProbeIteratorState, state, planState);

  status = consumeNext(qnameItem, theChildren[0], planState);
  ZORBA_ASSERT(status);

  if (state->theQname == NULL || !state->theQname->equals(qnameItem)) 
  {
    state->theQname = qnameItem;

    if ((indexDecl = theSctx->lookup_index(qnameItem)) == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0021_INDEX_IS_NOT_DECLARED, loc,
                            qnameItem->getStringValue()->c_str(), "");
    }

    if (indexDecl->getKeyExpressions().size() != numChildren-1)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
                            qnameItem->getStringValue()->c_str(), "");
    }

    state->theIndex = (indexDecl->isTemp() ?
                       planState.dctx()->getIndex(qnameItem) :
                       GENV_STORE.getIndex(state->theQname));

    if (state->theIndex == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0023_INDEX_DOES_NOT_EXIST, loc,
                            qnameItem->getStringValue()->c_str(), "");
    }

    state->theIterator = GENV_STORE.getIteratorFactory()->
                         createIndexProbeIterator(state->theIndex);
  }

  cond = state->theIndex->createPointCondition();

  for (i = 1; i < numChildren; ++i) 
  {
    if (!consumeNext(keyItem, theChildren[i], planState)) 
    {
      // We may reach here in the case of internally-generated hashjoins
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


/*******************************************************************************

********************************************************************************/
void IndexRangeProbeIteratorState::reset(PlanState& state)
{
  PlanIteratorState::reset(state);
  if (theIterator != NULL) 
  {
    theIterator->close();
  }
}


bool IndexRangeProbeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;
  ValueIndex_t indexDecl;
  store::IndexBoxCondition_t cond;
  ulong numChildren = theChildren.size();
  bool status;
 
  IndexRangeProbeIteratorState* state;
  DEFAULT_STACK_INIT(IndexRangeProbeIteratorState, state, planState);

  status = consumeNext(qname, theChildren[0], planState);
  ZORBA_ASSERT(status);

  if (state->theQname == NULL || !state->theQname->equals(qname)) 
  {
    state->theQname = qname;

    if ((indexDecl = theSctx->lookup_index(qname)) == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0021_INDEX_IS_NOT_DECLARED, loc,
                            qname->getStringValue()->c_str(), "");
    }

    if (indexDecl->getMethod() != ValueIndex::TREE)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0026_INDEX_RANGE_PROBE_NOT_ALLOWED, loc,
                            qname->getStringValue()->c_str(), "");
    }

    if ((numChildren-1) % 6 != 0)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
                            qname->getStringValue()->c_str(), "");
    }

    if (indexDecl->getKeyExpressions().size() * 6 > numChildren-1)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
                            qname->getStringValue()->c_str(), "");
    }

    state->theIndex = (indexDecl->isTemp() ?
                       planState.dctx()->getIndex(qname) :
                       GENV_STORE.getIndex(state->theQname));

    if (state->theIndex == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0023_INDEX_DOES_NOT_EXIST, loc,
                            qname->getStringValue()->c_str(), "");
    }

    state->theIterator = GENV_STORE.getIteratorFactory()->
                         createIndexProbeIterator(state->theIndex);
  }

  cond = state->theIndex->createBoxCondition();

  for(ulong i = 1; i < numChildren; i += 6) 
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
      ZORBA_ASSERT(false);

    if (!consumeNext(tempHaveRight, theChildren[i + 3], planState))
     ZORBA_ASSERT(false);

    if (!consumeNext(tempInclLeft, theChildren[i + 4], planState))
     ZORBA_ASSERT(false);
 
    if (!consumeNext(tempInclRight, theChildren[i + 5], planState))
     ZORBA_ASSERT(false);

    bool haveLeft = tempHaveLeft->getBooleanValue();
    bool haveRight = tempHaveRight->getBooleanValue();
    bool inclLeft = tempInclLeft->getBooleanValue();
    bool inclRight = tempInclRight->getBooleanValue();

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


} /* namespace zorba */
