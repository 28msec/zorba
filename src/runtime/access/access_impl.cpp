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

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"

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

/*******************************************************************************
  14.8.8 fn:environment-variable
********************************************************************************/
  bool FnEnvironmentVariableIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    store::Item_t item;
    zstring varname;

    PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

    if(consumeNext(item, theChildren[0].getp(),planState))
    {
      varname = item->getString();
      result = planState.theLocalDynCtx->get_environment_variable(varname);
      STACK_PUSH(true, state);
    }
    
    STACK_END(state);
  }

}//namespace zorba