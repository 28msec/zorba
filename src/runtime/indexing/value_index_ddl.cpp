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

#include "compiler/indexing/value_index.h"

#include "runtime/indexing/value_index_ddl.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "store/api/store.h"        // for checking if index exists
#include "store/api/item_factory.h" // for creating pul
#include "store/api/pul.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(CreateInternalIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CreateInternalIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(RebuildIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(RebuildIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(IndexEntryBuilderIterator)
END_SERIALIZABLE_CLASS_VERSIONS(IndexEntryBuilderIterator)


UNARY_ACCEPT(CreateInternalIndexIterator);

UNARY_ACCEPT(RebuildIndexIterator);

NARY_ACCEPT(IndexEntryBuilderIterator);


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
bool RebuildIndexIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
    ZORBA_ERROR_LOC_PARAM(XQP0037_INDEX_IS_NOT_DECLARED, loc,
                          qname->getStringValue()->c_str(), "");
  }

  if (GENV_STORE.getIndex(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0033_INDEX_DOES_NOT_EXIST, loc,
                          qname->getStringValue()->c_str(), "");
  }

  buildPlan = zorbaIndex->getBuildPlan(ccb, loc); 
  
  planWrapper = new PlanWrapper(buildPlan, ccb, dctx, NULL); 

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addRebuildIndex(qname, planWrapper);

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





}
/* vim:set ts=2 sw=2: */
