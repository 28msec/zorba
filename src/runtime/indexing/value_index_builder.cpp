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

#include "runtime/indexing/value_index_builder.h"
#include "runtime/visitors/planitervisitor.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "store/api/store.h"

namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(CreateValueIndex)
END_SERIALIZABLE_CLASS_VERSIONS(CreateValueIndex)

SERIALIZABLE_CLASS_VERSIONS(CreateInternalIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CreateInternalIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(DropValueIndex)
END_SERIALIZABLE_CLASS_VERSIONS(DropValueIndex)


static store::Index* createIndex(ValueIndex* zorbaIndex, dynamic_context* dctx)
{
  const std::vector<xqtref_t>& keyTypes(zorbaIndex->getKeyTypes());
  const std::vector<std::string>& keyCollations(zorbaIndex->getKeyCollations());
  ulong numColumns = keyTypes.size();

  xqp_string defaultCollation;
  std::string defaultCollationStr;
  if (zorbaIndex->getSctx()->lookup_default_collation(defaultCollation))
    defaultCollationStr = defaultCollation.getStore()->str();

  store::IndexSpecification spec(numColumns);

  for(ulong i = 0; i < numColumns; ++i) 
  {
    const XQType& t = *keyTypes[i];
    spec.theKeyTypes[i] = t.get_qname();
    const std::string& coll = keyCollations[i];
    spec.theCollations.push_back(coll.empty() ? defaultCollationStr : coll);
  }

  spec.theIsUnique = zorbaIndex->getUnique();
  spec.theIsSorted = zorbaIndex->getMethod() == ValueIndex::BTREE;
  spec.theIsTemp = zorbaIndex->getTemp();
  spec.theIsThreadSafe = true;
  
  store::Index_t storeIndex = GENV_STORE.createIndex(zorbaIndex->getName(), spec);

  dctx->bind_index(zorbaIndex->getName(), storeIndex);

  return storeIndex.getp();
}


/***************************************************************************//**

********************************************************************************/
bool CreateValueIndex::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool status;
  store::Item_t qname;
  ValueIndex_t zorbaIndex;
  store::Index_t storeIndex;
  PlanIterator* buildPlan;
  store::Iterator_t planWrapper;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  status = consumeNext(qname, theChild, planState);
  ZORBA_ASSERT(status);

  zorbaIndex = theSctx->lookup_index(qname);

  storeIndex = createIndex(zorbaIndex, planState.dctx());

  buildPlan = zorbaIndex->getBuildPlan(planState.theCompilerCB, loc);

  planWrapper = new PlanWrapper(buildPlan, planState.theCompilerCB, planState.dctx());

  try
  {
    storeIndex->build(planWrapper);
  }
  catch(error::ZorbaError& e)
  {
    storeIndex->clear();
    ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
  }
  catch(...)
  {
    storeIndex->clear();
    throw;
  }

  STACK_END (state);
}


UNARY_ACCEPT(CreateValueIndex);


/***************************************************************************//**

********************************************************************************/
bool CreateInternalIndexIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Iterator_t planIteratorWrapper;
  store::Index* storeIndex;
  ValueIndex* zorbaIndex;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  zorbaIndex = theSctx->lookup_index(theQName);

  storeIndex = createIndex(zorbaIndex, planState.dctx());

  planIteratorWrapper = new PlanIteratorWrapper(theChild, planState);

  storeIndex = planState.dctx()->lookup_index(theQName);

  try
  {
    storeIndex->build(planIteratorWrapper);
  }
  catch(error::ZorbaError& e)
  {
    storeIndex->clear();
    ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
  }
  catch (...)
  {
    storeIndex->clear();
    throw;
  }

  STACK_END (state);
}


UNARY_ACCEPT(CreateInternalIndexIterator);


/***************************************************************************//**

********************************************************************************/
bool DropValueIndex::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool status;
  store::Item_t qname;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  status = consumeNext(qname, theChild, planState);
  ZORBA_ASSERT(status);

  planState.dctx()->unbind_index(qname);
  GENV_STORE.deleteIndex(qname);

  STACK_END(state);
}


UNARY_ACCEPT(DropValueIndex);


}
/* vim:set ts=2 sw=2: */
