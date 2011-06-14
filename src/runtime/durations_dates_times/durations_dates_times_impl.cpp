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

#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/numconversions.h"
#include "zorbatypes/datetime/parse.h"

#include "system/globalenv.h"

#include "types/casting.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/durations_dates_times/durations_dates_times.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"

namespace zorba
{

/**
 *______________________________________________________________________
 *
 * 10.5.1 fn:years-from-duration
 *
 * fn:years-from-duration($arg as xs:duration?) as xs:integer?
 *_______________________________________________________________________*/
bool YearsFromDurationIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t itemArg;
  int32_t lYears;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    lYears = itemArg->getDurationValue().getYears();

    STACK_PUSH(GENV_ITEMFACTORY->createInteger(result,
                                               Integer(lYears)), 
               state);
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.2 fn:months-from-duration
 *
 * fn:months-from-duration($arg as xs:duration?) as xs:integer?
 *_______________________________________________________________________*/
bool MonthsFromDurationIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    GENV_ITEMFACTORY->
    createInteger(result,
                  Integer(itemArg->getDurationValue().getMonths()));

    STACK_PUSH(true, state);
  }
  STACK_END(state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.3 fn:days-from-duration
 *
 * fn:days-from-duration($arg as xs:duration?) as xs:integer?
 *_______________________________________________________________________*/
bool DaysFromDurationIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    GENV_ITEMFACTORY->
    createInteger(result,
                  Integer(itemArg->getDurationValue().getDays()));

    STACK_PUSH(true, state);
  }
  STACK_END(state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.4 fn:hours-from-duration
 *
 * fn:hours-from-duration($arg as xs:duration?) as xs:integer?
 *_______________________________________________________________________*/
bool HoursFromDurationIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    GENV_ITEMFACTORY->
    createInteger(result,
                  Integer(itemArg->getDurationValue().getHours()));

    STACK_PUSH(true, state);
  }
  STACK_END(state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.5 fn:minutes-from-duration
 *
 * fn:minutes-from-duration($arg as xs:duration?) as xs:integer?
 *_______________________________________________________________________*/
bool MinutesFromDurationIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer(itemArg->getDurationValue().getMinutes())),
      state 
    );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.6 fn:seconds-from-duration
 *
 * fn:seconds-from-duration($arg as xs:duration?) as xs:decimal?
 *_______________________________________________________________________*/
bool SecondsFromDurationIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t itemArg;
  xs_decimal lDecimal;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    lDecimal = itemArg->getDurationValue().getSeconds();
    STACK_PUSH( GENV_ITEMFACTORY->createDecimal(result, lDecimal), state );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.7 fn:year-from-dateTime
 *
 * fn:year-from-dateTime($arg as xs:dateTime?) as xs:integer?
 *_______________________________________________________________________*/
bool YearFromDatetimeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    STACK_PUSH(
        GENV_ITEMFACTORY->createInteger(
          result,
          Integer(itemArg->getDateTimeValue().getYear())), state );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.8 fn:month-from-dateTime
 *
 * fn:month-from-dateTime($arg as xs:dateTime?) as xs:integer?
 *_______________________________________________________________________*/
bool MonthFromDatetimeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer(itemArg->getDateTimeValue().getMonth())), 
      state 
    );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.9 fn:day-from-dateTime
 *
 * fn:day-from-dateTime($arg as xs:dateTime?) as xs:integer?
 *_______________________________________________________________________*/
bool DayFromDatetimeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer(itemArg->getDateTimeValue().getDay())), 
      state 
    );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.10 fn:hours-from-dateTime
 *
 * fn:hours-from-dateTime($arg as xs:dateTime?) as xs:integer?
 *_______________________________________________________________________*/
bool HoursFromDatetimeIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer(itemArg->getDateTimeValue().getHours())), 
      state 
    );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.11 fn:minutes-from-dateTime
 *
 * fn:minutes-from-dateTime($arg as xs:dateTime?) as xs:integer?
 *_______________________________________________________________________*/
bool MinutesFromDatetimeIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer(itemArg->getDateTimeValue().getMinutes())), 
      state 
    );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.12 fn:seconds-from-dateTime
 *
 * fn:seconds-from-dateTime($arg as xs:dateTime?) as xs:decimal?
 *_______________________________________________________________________*/
bool SecondsFromDatetimeIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t itemArg;
  xs_decimal lDecimal;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    lDecimal = itemArg->getDateTimeValue().getSeconds();
    STACK_PUSH( GENV_ITEMFACTORY->createDecimal(result, lDecimal), state );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.13 fn:timezone-from-dateTime
 *
 * fn:timezone-from-dateTime($arg as xs:dateTime?) as xs:dayTimeDuration?
 *_______________________________________________________________________*/
bool TimezoneFromDatetimeIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t itemArg;
  xs_dayTimeDuration tmpDuration;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    if (0 == Duration::fromTimezone(itemArg->getDateTimeValue().getTimezone(), tmpDuration))
      STACK_PUSH( GENV_ITEMFACTORY->createDayTimeDuration(result, &tmpDuration), state );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.14 fn:year-from-date
 *
 * fn:year-from-date($arg as xs:date?) as xs:integer?
 *_______________________________________________________________________*/
bool YearFromDateIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer(itemArg->getDateValue().getYear())), 
      state 
    );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.15 fn:month-from-date
 *
 * fn:month-from-date($arg as xs:date?) as xs:integer?
 *_______________________________________________________________________*/
bool MonthFromDateIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer(itemArg->getDateValue().getMonth())), 
      state 
    );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.16 fn:day-from-date
 *
 * fn:day-from-date($arg as xs:date?) as xs:integer?
 *_______________________________________________________________________*/
bool DayFromDateIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer(itemArg->getDateValue().getDay())), 
      state 
    );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.17 fn:timezone-from-date
 *
 * fn:timezone-from-date($arg as xs:date?) as xs:dayTimeDuration?
 *_______________________________________________________________________*/
bool TimezoneFromDateIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t itemArg;
  xs_dayTimeDuration tmpDuration;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    if (0 == Duration::fromTimezone(itemArg->getDateValue().getTimezone(), tmpDuration))
      STACK_PUSH( GENV_ITEMFACTORY->createDayTimeDuration(result, &tmpDuration), state );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.18 fn:hours-from-time
 *
 * fn:hours-from-time($arg as xs:time?) as xs:integer?
 *_______________________________________________________________________*/
bool HoursFromTimeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer(itemArg->getTimeValue().getHours())), 
      state 
    );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.19 fn:minutes-from-time
 *
 * fn:minutes-from-time($arg as xs:time?) as xs:integer?
 *_______________________________________________________________________*/
bool MinutesFromTimeIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer(itemArg->getTimeValue().getMinutes())), 
      state 
    );
  }
  STACK_END (state);
}



/**
 *______________________________________________________________________
 *
 * 10.5.20 fn:seconds-from-time
 *
 * fn:seconds-from-time($arg as xs:time?) as xs:decimal?
 *_______________________________________________________________________*/
bool SecondsFromTimeIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t itemArg;
  xs_decimal lDecimal;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    lDecimal = itemArg->getTimeValue().getSeconds();
    STACK_PUSH( GENV_ITEMFACTORY->createDecimal(result, lDecimal), state );
  }
  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.5.21 fn:timezone-from-time
 *
 * fn:timezone-from-time($arg as xs:time?) as xs:dayTimeDuration?
 *_______________________________________________________________________*/
bool TimezoneFromTimeIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t itemArg;
  xs_dayTimeDuration tmpDuration;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  if ( itemArg != NULL )
  {
    if (0 == Duration::fromTimezone(itemArg->getTimeValue().getTimezone(), tmpDuration))
      STACK_PUSH( GENV_ITEMFACTORY->createDayTimeDuration(result, &tmpDuration), state );
  }
  STACK_END (state);
}

}
/* vim:set et sw=2 ts=2: */
