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
#include "runtime/indexing/index_ddl.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "compiler/indexing/value_index.h"

#include "runtime/api/plan_wrapper.h"

#include "store/api/store.h"        // for checking if index exists
#include "store/api/item_factory.h" // for creating pul
#include "store/api/pul.h"
#include "store/api/index.h"

namespace zorba {

/*******************************************************************************

********************************************************************************/
void createIndexSpec(
    ValueIndex* zorbaIndex,
    store::IndexSpecification& spec);

/***************************************************************************//**

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
    ZORBA_ERROR_LOC_PARAM(XQP0037_INDEX_IS_NOT_DECLARED, loc,
                          qname->getStringValue()->c_str(), "");
  }

  if (GENV_STORE.getIndex(qname) != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0034_INDEX_ALREADY_EXISTS, loc,
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

/***************************************************************************//**

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
    ZORBA_ERROR_LOC_PARAM(XQP0037_INDEX_IS_NOT_DECLARED, loc,
                          qname->getStringValue()->c_str(), "");
  }

  if (GENV_STORE.getIndex(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0033_INDEX_DOES_NOT_EXIST, loc,
                          qname->getStringValue()->c_str(), "");
  }

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addDeleteIndex(qname);

  STACK_PUSH(true, state);

  STACK_END(state);
}

} /* namespace zorba */
