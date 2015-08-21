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

#include "compiler/api/compilercb.h"

#include "runtime/context/context.h"
#include "runtime/visitors/planiter_visitor.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "zorbatypes/datetime.h"

#include "store/api/item_factory.h"

#include <zorba/internal/unique_ptr.h>
#include <zorba/util/debug.h>

namespace zorba
{
//16.3 fn:current-dateTime
bool
CurrentDateTimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  DEBUG_SS("---------------EVALUATING--------------");

  result = planState.theLocalDynCtx->get_current_date_time();
  if (result != NULL)
    STACK_PUSH(true, state );

  STACK_END (state);
}

//16.4 fn:current-date
bool
CurrentDateIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemRes;
  std::unique_ptr<xs_date> d;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemRes = planState.theLocalDynCtx->get_current_date_time();
  if( NULL != itemRes )
  {
    d.reset (itemRes->getDateTimeValue().getDate());
    STACK_PUSH( GENV_ITEMFACTORY->createDate(result, d.get ()), state );
  }

  STACK_END (state);
}

//16.5 fn:current-time
bool
CurrentTimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemRes;
  std::unique_ptr<xs_time> t;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemRes = planState.theLocalDynCtx->get_current_date_time();
  if( NULL != itemRes )
  {
    t.reset (itemRes->getDateTimeValue().getTime());
    STACK_PUSH( GENV_ITEMFACTORY->createTime(result, t.get ()), state );
  }

  STACK_END (state);
}
//16.6 fn:implicit-timezone
bool
ImplicitTimezoneIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  long secs;
  bool neg;
  xs_dayTimeDuration dtd;
  std::unique_ptr<Duration> dur;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  secs = planState.theLocalDynCtx->get_implicit_timezone();
  neg = secs < 0;
  if (neg)
    secs = -secs;
  dur = std::unique_ptr<Duration>(new Duration(Duration::DAYTIMEDURATION_FACET, neg, 0, 0, 0, 0, 0 , secs));

  STACK_PUSH( GENV_ITEMFACTORY->createDayTimeDuration(result, dur.get()), state );

  STACK_END (state);
}


//16.7 fn:default-collation
bool
DefaultCollationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  zstring strColUri;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  strColUri = theSctx->get_default_collation(loc);

  STACK_PUSH(GENV_ITEMFACTORY->createString(result, strColUri), state );

  STACK_END (state);
}


}/* namespace zorba */
/* vim:set et sw=2 ts=2: */
