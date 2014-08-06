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

#include <cstdlib>

#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/numconversions.h"
#include "zorbatypes/datetime/parse.h"
#include "util/ascii_util.h"
#include "util/string_util.h"
#include <zorba/internal/unique_ptr.h>

#include "system/globalenv.h"

#include "types/casting.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/durations_dates_times/DurationsDatesTimesImpl.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"

namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(FnDateTimeConstructorIterator)

SERIALIZABLE_CLASS_VERSIONS(FnAdjustToTimeZoneIterator_1)

SERIALIZABLE_CLASS_VERSIONS(FnAdjustToTimeZoneIterator_2)


BINARY_ACCEPT(FnDateTimeConstructorIterator);
DEF_GET_NAME_AS_STRING(FnDateTimeConstructorIterator)

UNARY_ACCEPT(FnAdjustToTimeZoneIterator_1);
DEF_GET_NAME_AS_STRING(FnAdjustToTimeZoneIterator_1)

BINARY_ACCEPT(FnAdjustToTimeZoneIterator_2);
DEF_GET_NAME_AS_STRING(FnAdjustToTimeZoneIterator_2)


bool FnDateTimeConstructorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;
  bool          b;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(item0, theChild0.getp(), planState) || !consumeNext(item1, theChild1.getp(), planState))
    STACK_PUSH(false, state);
  else {
    try {
      b = GENV_ITEMFACTORY->createDateTime(result, item0, item1);
    } catch (XQueryException& e) {
      set_source( e, loc );
      throw;
    }
    STACK_PUSH(b, state);
  }

  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.7.1 fn:adjust-dateTime-to-timezone
 * 10.7.2 fn:adjust-date-to-timezone
 * 10.7.3 fn:adjust-time-to-timezone
 *
 * fn:adjust-dateTime-to-timezone($arg as xs:dateTime?, $timezone as xs:dayTimeDuration?) as xs:dateTime?
 *
 *_______________________________________________________________________*/
bool
FnAdjustToTimeZoneIterator_1::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;
  std::unique_ptr<DateTime> dt;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // If $arg is the empty sequence, then the result is the empty sequence.
  if (!consumeNext(item0, theChild.getp(), planState))
  {
    STACK_PUSH(false, state);
  }
  else
  {
    try
    {
      dt = std::unique_ptr<DateTime>(item0->getDateTimeValue().adjustToTimeZone(
        planState.theLocalDynCtx->get_implicit_timezone()));
    }
    catch (InvalidTimezoneException const &e)
    {
      throw XQUERY_EXCEPTION(err::FODT0003, ERROR_PARAMS(e.get_tz_seconds()));
    }

    if (item0->getTypeCode() == store::XS_DATETIME)
    {
      STACK_PUSH(GENV_ITEMFACTORY->createDateTime(result, dt.get()), state);
    }
    else if (item0->getTypeCode() == store::XS_DATE)
    {
      STACK_PUSH(GENV_ITEMFACTORY->createDate(result, dt.get()), state);
    }
    else if (item0->getTypeCode() == store::XS_TIME)
    {
      STACK_PUSH(GENV_ITEMFACTORY->createTime(result, dt.get()), state);
    }
    else
    {
      ZORBA_ASSERT(false);
    }
  }

  STACK_END(state);
}


bool
FnAdjustToTimeZoneIterator_2::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;
  bool s1;
  std::unique_ptr<DateTime> dt;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(item0, theChild0.getp(), planState))
  {
    STACK_PUSH(false, state);
  }
  else
  {
    s1 = consumeNext(item1, theChild1.getp(), planState);
    try
    {
      dt = std::unique_ptr<DateTime>(item0->getDateTimeValue().adjustToTimeZone(!s1 ? NULL : &item1->getDayTimeDurationValue()));
    }
    catch (InvalidTimezoneException const &e)
    {
      throw XQUERY_EXCEPTION(err::FODT0003, ERROR_PARAMS(e.get_tz_seconds()));
    }

    if (item0->getTypeCode() == store::XS_DATETIME)
    {
      STACK_PUSH(GENV_ITEMFACTORY->createDateTime(result, dt.get()), state);
    }
    else if (item0->getTypeCode() == store::XS_DATE)
    {
      STACK_PUSH(GENV_ITEMFACTORY->createDate(result, dt.get()), state);
    }
    else if (item0->getTypeCode() == store::XS_TIME)
    {
      STACK_PUSH(GENV_ITEMFACTORY->createTime(result, dt.get()), state);
    }
    else if (item0->getTypeCode() == store::XS_DATETIME_STAMP)
    {
      STACK_PUSH(GENV_ITEMFACTORY->createDateTimeStamp(result, dt.get()), state);
    }
    else
    {
      ZORBA_ASSERT(false);
    }
  }

  STACK_END(state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
