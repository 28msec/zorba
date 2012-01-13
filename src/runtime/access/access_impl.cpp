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
#include "diagnostics/xquery_diagnostics.h"


#include "system/globalenv.h"

#include "context/namespace_context.h"
#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "runtime/access/access.h"

#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"

#include "api/dynamiccontextimpl.h"
#include "api/unmarshaller.h"
#include "api/xqueryimpl.h"

namespace zorba {

/*******************************************************************************
  14.8.5 fn:uri-collection
********************************************************************************/
  FnURICollectionIteratorState::~FnURICollectionIteratorState()
  {
    if(theIterator != NULL)
    {
      if(theIteratorOpened)
      {
        theIterator->close();
        theIteratorOpened = false;
      }
      theIterator = NULL;
    }
  }

  void FnURICollectionIteratorState::init(PlanState& planState)
  {
    PlanIteratorState::init(planState);
    theIterator = NULL;
  }

  void FnURICollectionIteratorState::reset(PlanState& planState)
  {
    PlanIteratorState::reset(planState);

    if(theIterator != NULL)
    {
      if(theIteratorOpened)
      {
        theIterator->close();
        theIteratorOpened = false;
      }
      theIterator = NULL;
    }
  }
  
  bool FnURICollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    store::Item_t lURI, resolvedURIItem, lIte;
    store::Collection_t coll;
    std::auto_ptr<internal::Resource> lResource;
    internal::CollectionResource* lCollResource;
    zstring resolvedURIString;
    zstring lErrorMessage;
    zstring docuri;

    FnURICollectionIteratorState* state;
    DEFAULT_STACK_INIT(FnURICollectionIteratorState, state, planState);

    if(theChildren.size() == 1 &&
      consumeNext(lURI, theChildren[0].getp(),planState))
    {
      try
      {
        resolvedURIString= theSctx->resolve_relative_uri(lURI->getStringValue());
      }
      catch (ZorbaException const&)
      {
        throw XQUERY_EXCEPTION(
          err::FODC0004,
          ERROR_PARAMS(lURI->getStringValue(), ZED( BadAnyURI ) ),
          ERROR_LOC( loc )
        );
      }
    }
    else
    {
      resolvedURIItem = planState.theGlobalDynCtx->get_default_collection();

      if ( NULL == resolvedURIItem )
        throw XQUERY_EXCEPTION(
        err::FODC0002,
        ERROR_PARAMS( ZED( DefaultCollection), ZED( NotDefInDynamicCtx ) ),
        ERROR_LOC( loc )
      );

      resolvedURIString = theSctx->resolve_relative_uri(resolvedURIItem->getStringValue());
    }

    lResource = theSctx->resolve_uri(resolvedURIString,
                                    internal::EntityData::COLLECTION,
                                    lErrorMessage);

    lCollResource = dynamic_cast<internal::CollectionResource*>(lResource.get());

    if( lCollResource == 0 || !(coll = lCollResource->getCollection()) )
    {
      throw XQUERY_EXCEPTION(
        err::FODC0002,
        ERROR_PARAMS( resolvedURIString, lErrorMessage ),
        ERROR_LOC( loc )
      );
    }

    // return collection nodes
    state->theIterator = coll->getIterator();
    ZORBA_ASSERT(state->theIterator != NULL);
    state->theIterator->open();
    state->theIteratorOpened = true;

    //return the DocumentURI of the Collection
    while(state->theIterator->next(lIte))
    {
      lIte->getDocumentURI(docuri);
      if(!docuri.empty())
      {
        STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(result, docuri), state);
      }
    }

    //close iterator
    state->theIterator->close();
    state->theIteratorOpened = false;

    STACK_END(state);
  }


/*******************************************************************************
  14.8.5 fn:unparsed-text
********************************************************************************/
  bool FnUnparsedTextIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

    STACK_PUSH(false, state);

    STACK_END(state);
  }


/*******************************************************************************
  14.8.7 fn:unparsed-text-available
********************************************************************************/
  bool FnUnparsedTextAvailableIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

    STACK_PUSH(false, state);

    STACK_END(state);
  }

/*******************************************************************************
  14.8.8 fn:environment-variable
********************************************************************************/
  bool FnEnvironmentVariableIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    store::Item_t item;
    store::Item_t item2;
    zstring varname;

    PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

    if(consumeNext(item, theChildren[0].getp(),planState))
    {
      varname = item->getString();
      result = planState.theLocalDynCtx->get_environment_variable(varname);
      if(result)
      {
        STACK_PUSH(true, state);
      }
      STACK_PUSH(false, state);
      
    }
    
    STACK_END(state);
  }

/*******************************************************************************
  14.8.9 fn:available-environment-variables
********************************************************************************/
  bool FnAvailableEnvironmentVariablesIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    store::Iterator_t lIte;
    std::string a;
    FnAvailableEnvironmentVariablesIteratorState* state;
    DEFAULT_STACK_INIT(FnAvailableEnvironmentVariablesIteratorState, state, planState);
    
    state->theIterator = planState.theLocalDynCtx->available_environment_variables();

    state->theIterator->open();
    while(state->theIterator->next(result))
    {
      a = result->getStringValue().c_str();
      STACK_PUSH(true, state);
    }
    state->theIterator->close();
    STACK_END(state);
  }

  void FnAvailableEnvironmentVariablesIteratorState::init(PlanState& planState)
  {
    PlanIteratorState::init(planState);
    theIterator = 0;
  }

  void FnAvailableEnvironmentVariablesIteratorState::reset(PlanState& planState)
  {
    PlanIteratorState::reset(planState);
    theIterator = 0;
  }

}//namespace zorba