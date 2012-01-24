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
#include "store/api/shared_types.h"
#include "store/api/pul.h"
#include "store/api/index.h"
#include "store/api/annotation.h"
#include "store/api/ic.h"
#include "api/dynamiccontextimpl.h"
#include "api/unmarshaller.h"
#include "api/xqueryimpl.h"

namespace zorba {

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

}//namespace zorba
