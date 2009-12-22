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

#include "runtime/indexing/ic_ddl.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "compiler/indexing/value_ic.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"


namespace zorba 
{

/*******************************************************************************
 Implementation for:
   activate-integrity-constraint($icName as xs:QName) as ()
******************************************************************************/
bool ActivateICIterator::nextImpl(store::Item_t& result, PlanState& planState) 
  const
{
  store::Item_t qname;
  ValueIC_t vic;
  store::IndexSpecification spec;
  PlanIter_t buildPlan;
  store::Iterator_t planWrapper;

  dynamic_context* dctx = planState.dctx();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if ((vic = theSctx->lookup_ic(qname)) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0047_IC_IS_NOT_DECLARED, loc,
                          qname->getStringValue()->c_str(), "");
  }

  if (GENV_STORE.getIC(qname) != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0044_IC_ALREADY_EXISTS, loc,
                          qname->getStringValue()->c_str(), "");
  }

  
  switch ( vic->getICKind() )
  {
  case store::IC::ic_collection:
    dctx->activateIC(vic->getName(), vic->getCollectionName());
    break;
  case store::IC::ic_foreignkey:
    dctx->activateForeignKeyIC(vic->getName(), 
                               vic->getToCollectionName(),
                               vic->getFromCollectionName());
    break;
  }


  STACK_PUSH(true, state);

  STACK_END(state);
}


/*******************************************************************************
 Implementation for:
   deactivate-integrity-constraint($icName as xs:QName) as ()
******************************************************************************/
bool DeactivateICIterator::nextImpl(store::Item_t& result, PlanState& planState)
  const
{
  store::Item_t qname;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if (theSctx->lookup_ic(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0047_IC_IS_NOT_DECLARED, loc,
                          qname->getStringValue()->c_str(), "");
  }

  if (GENV_STORE.getIC(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0043_IC_DOES_NOT_EXIST, loc,
                          qname->getStringValue()->c_str(), "");
  } 


  GENV_STORE.deactivateIC(qname);


  STACK_PUSH(true, state);

  STACK_END(state);
}

/*******************************************************************************
 Implementation for:
   check-integrity-constraint($icName as xs:QName) as xs:boolean
******************************************************************************/
bool CheckICIterator::nextImpl(store::Item_t& result, PlanState& planState)
  const
{
  store::Item_t qname;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if (theSctx->lookup_ic(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0047_IC_IS_NOT_DECLARED, loc,
                          qname->getStringValue()->c_str(), "");
  }

  if (GENV_STORE.getIC(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQP0043_IC_DOES_NOT_EXIST, loc,
                          qname->getStringValue()->c_str(), "");
  } 


  // call the function
  // return result
  xqp_boolean icFuncResult;
  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, icFuncResult),
               state);

  STACK_PUSH(true, state);

  STACK_END(state);
}



} // namespace zorba
