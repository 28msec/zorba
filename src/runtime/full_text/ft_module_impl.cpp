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

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "zorbatypes/URI.h"

#include "system/globalenv.h"

#include "runtime/full_text/ft_module.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

#include "store/api/pul.h"
#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator_factory.h" // for creating the probe iterator
#include "store/api/iterator.h"
#include "store/api/index.h"

#include "runtime/core/apply_updates.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/casting.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

bool
IsStopWordIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);


  STACK_END(state);
}

///////////////////////////////////////////////////////////////////////////////

bool
StemIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);


  STACK_END(state);
}

///////////////////////////////////////////////////////////////////////////////

bool
StripDiacriticsIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);


  STACK_END(state);
}

///////////////////////////////////////////////////////////////////////////////

bool
HostLangWordIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);


  STACK_END(state);
}

///////////////////////////////////////////////////////////////////////////////

bool
ThesaurusLookupIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);


  STACK_END(state);
}

///////////////////////////////////////////////////////////////////////////////

bool
TokenizeIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);


  STACK_END(state);
}


///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
