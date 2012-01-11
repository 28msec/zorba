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

#include "system/globalenv.h"

#include "store/api/store.h"        // for checking if index exists
#include "store/api/item_factory.h" // for creating pul
#include "store/api/iterator_factory.h" // for creating the probe iterator
#include "store/api/pul.h"
#include "store/api/index.h"

#include "runtime/indexing/ic_ddl.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "compiler/xqddf/value_ic.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"


namespace zorba 
{

/*******************************************************************************
 Implementation for:
   activate($icName as xs:QName) as ()
******************************************************************************/
bool
ActivateICIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;
  ValueIC_t vic;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false); // error should already be raised by function call

  if ((vic = theSctx->lookup_ic(qname)) == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0031_IC_NOT_DECLARED,
      ERROR_PARAMS( qname->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  // already activated => noop
  if (GENV_STORE.getIC(qname) == NULL)
  {
    result = GENV_ITEMFACTORY->createPendingUpdateList();

    switch ( vic->getICKind() )
    {
    case store::IC::ic_collection:
      static_cast<store::PUL*>(result.getp())->addActivateIC(
          &loc,
          vic->getICName(),
          vic->getCollectionName());
      break;
      
    case store::IC::ic_foreignkey:
      static_cast<store::PUL*>(result.getp())->addActivateForeignKeyIC(
          &loc,
          vic->getICName(),
          vic->getFromCollectionName(),
          vic->getToCollectionName());
      break;
      
    default:
      ZORBA_ASSERT(false);
      break;
    }
  }

  STACK_PUSH(result!=NULL, state);

  STACK_END(state);
}


/*******************************************************************************
 Implementation for:
   deactivate($icName as xs:QName) as ()
******************************************************************************/
bool
DeactivateICIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if (theSctx->lookup_ic(qname) == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0031_IC_NOT_DECLARED,
      ERROR_PARAMS( qname->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  if (GENV_STORE.getIC(qname) == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0032_IC_NOT_ACTIVATED,
      ERROR_PARAMS( qname->getStringValue() ),
      ERROR_LOC( loc )
    );
  }
  else
  {
    result = GENV_ITEMFACTORY->createPendingUpdateList();
    static_cast<store::PUL*>(result.getp())->addDeActivateIC(&loc, qname);
  }

  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}

/*******************************************************************************
 Implementation for:
   check-integrity-constraint($icName as xs:QName) as xs:boolean
******************************************************************************/
bool
CheckICIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);
  else
  {
    ValueIC* vic = theSctx->lookup_ic(qname);
    
    if ( vic == NULL)
    {
      throw XQUERY_EXCEPTION(
        zerr::ZDDY0031_IC_NOT_DECLARED,
        ERROR_PARAMS( qname->getStringValue() ),
        ERROR_LOC( loc )
      );
    }        
    
    // run iterator
    store::Iterator_t iter = vic->getIterator();
    
    iter->open();
    iter->next(result);
    iter->close();
    
    // return result
    //xs_boolean icFuncResult;
    //STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, icFuncResult),
    //             state);    
  }

  STACK_PUSH(result.isNull(), state);
  
  STACK_PUSH(true, state);

  STACK_END(state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
