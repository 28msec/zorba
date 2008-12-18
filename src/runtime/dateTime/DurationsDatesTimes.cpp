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
#include "store/api/item.h"

#include "zorbaerrors/Assert.h"

#include "types/casting.h"
#include "context/dynamic_context.h"

#include "runtime/dateTime/DurationsDatesTimes.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/api/runtimecb.h"
#include "zorbaerrors/error_manager.h"
#include "system/globalenv.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/numconversions.h"

using namespace std;

namespace zorba
{

bool FnDateTimeConstructorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(item0, theChild0.getp(), planState) || !consumeNext(item1, theChild1.getp(), planState))
    STACK_PUSH(false, state);
  else
    STACK_PUSH(GENV_ITEMFACTORY->createDateTime(result, item0, item1), state);
     
  STACK_END (state);
}

/**
 *______________________________________________________________________
 *
 * 10.5.1 fn:years-from-duration
 *
 * fn:years-from-duration($arg as xs:duration?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnYearsFromDurationIterator */
bool
FnYearsFromDurationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;
  int32_t lYears;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    lYears = itemArg->getDurationValue().getYears();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(lYears)), 
      state 
    );
  }
  STACK_END (state);
}
/*end class FnYearsFromDurationIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.2 fn:months-from-duration
 *
 * fn:months-from-duration($arg as xs:duration?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnMonthsFromDurationIterator */
bool
FnMonthsFromDurationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getDurationValue().getMonths())),
      state 
    );
  }
  STACK_END (state);
}
/*end class FnMonthsFromDurationIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.3 fn:days-from-duration
 *
 * fn:days-from-duration($arg as xs:duration?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnDaysFromDurationIterator */
bool
FnDaysFromDurationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getDurationValue().getDays())),
      state 
    );
  }
  STACK_END (state);
}
/*end class FnDaysFromDurationIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.4 fn:hours-from-duration
 *
 * fn:hours-from-duration($arg as xs:duration?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnHoursFromDurationIterator */
bool
FnHoursFromDurationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getDurationValue().getHours())),
      state 
    );
  }
  STACK_END (state);
}
/*end class FnHoursFromDurationIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.5 fn:minutes-from-duration
 *
 * fn:minutes-from-duration($arg as xs:duration?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnMinutesFromDurationIterator */
bool
FnMinutesFromDurationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getDurationValue().getMinutes())),
      state 
    );
  }
  STACK_END (state);
}
/*end class FnMinutesFromDurationIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.6 fn:seconds-from-duration
 *
 * fn:seconds-from-duration($arg as xs:duration?) as xs:decimal?
 *_______________________________________________________________________*/

/*begin class FnSecondsFromDurationIterator */
bool
FnSecondsFromDurationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;
  xqp_decimal lDecimal;
  bool lBool;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    lBool = Decimal::parseNativeDouble(itemArg->getDurationValue().getSeconds(), lDecimal);
    ZORBA_ASSERT(lBool);
    STACK_PUSH( GENV_ITEMFACTORY->createDecimal(result, lDecimal), state );
  }
  STACK_END (state);
}
/*end class FnSecondsFromDurationIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.7 fn:year-from-dateTime
 *
 * fn:year-from-dateTime($arg as xs:dateTime?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnYearFromDatetimeIterator */
bool
FnYearFromDatetimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH(
        GENV_ITEMFACTORY->createInteger(
          result,
          Integer::parseInt(itemArg->getDateTimeValue().getYear())), state );
  }
  STACK_END (state);
}
/*end class FnYearFromDatetimeIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.8 fn:month-from-dateTime
 *
 * fn:month-from-dateTime($arg as xs:dateTime?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnMonthFromDatetimeIterator */
bool
FnMonthFromDatetimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getDateTimeValue().getMonth())), 
      state 
    );
  }
  STACK_END (state);
}
/*end class FnMonthFromDatetimeIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.9 fn:day-from-dateTime
 *
 * fn:day-from-dateTime($arg as xs:dateTime?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnDayFromDatetimeIterator */
bool
FnDayFromDatetimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getDateTimeValue().getDay())), 
      state 
    );
  }
  STACK_END (state);
}
/*end class FnDayFromDatetimeIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.10 fn:hours-from-dateTime
 *
 * fn:hours-from-dateTime($arg as xs:dateTime?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnHoursFromDatetimeIterator */
bool
FnHoursFromDatetimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getDateTimeValue().getHours())), 
      state 
    );
  }
  STACK_END (state);
}
/*end class FnHoursFromDatetimeIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.11 fn:minutes-from-dateTime
 *
 * fn:minutes-from-dateTime($arg as xs:dateTime?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnMinutesFromDatetimeIterator */
bool
FnMinutesFromDatetimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getDateTimeValue().getMinutes())), 
      state 
    );
  }
  STACK_END (state);
}
/*end class FnMinutesFromDatetimeIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.12 fn:seconds-from-dateTime
 *
 * fn:seconds-from-dateTime($arg as xs:dateTime?) as xs:decimal?
 *_______________________________________________________________________*/

/*begin class FnSecondsFromDatetimeIterator */
bool
FnSecondsFromDatetimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;
  xqp_decimal lDecimal;
  bool lBool;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    lBool = Decimal::parseNativeDouble(itemArg->getDateTimeValue().getSeconds(), lDecimal);
    ZORBA_ASSERT(lBool);
    STACK_PUSH( GENV_ITEMFACTORY->createDecimal(result, lDecimal), state );
  }
  STACK_END (state);
}
/*end class FnSecondsFromDatetimeIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.13 fn:timezone-from-dateTime
 *
 * fn:timezone-from-dateTime($arg as xs:dateTime?) as xs:dayTimeDuration?
 *_______________________________________________________________________*/

/*begin class FnTimezoneFromDatetimeIterator */
bool
FnTimezoneFromDatetimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;
  xqp_dayTimeDuration tmpDuration;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    if (0 == Duration::fromTimezone(itemArg->getDateTimeValue().getTimezone(), tmpDuration))
      STACK_PUSH( GENV_ITEMFACTORY->createDayTimeDuration(result, &tmpDuration), state );
  }
  STACK_END (state);
}
/*end class FnTimezoneFromDatetimeIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.14 fn:year-from-date
 *
 * fn:year-from-date($arg as xs:date?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnYearFromDateIterator */
bool
FnYearFromDateIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getDateValue().getYear())), 
      state 
    );
  }
  STACK_END (state);
}
/*end class FnYearFromDateIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.15 fn:month-from-date
 *
 * fn:month-from-date($arg as xs:date?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnMonthFromDateIterator */
bool
FnMonthFromDateIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getDateValue().getMonth())), 
      state 
    );
  }
  STACK_END (state);
}
/*end class FnMonthFromDateIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.16 fn:day-from-date
 *
 * fn:day-from-date($arg as xs:date?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnDayFromDateIterator */
bool
FnDayFromDateIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getDateValue().getDay())), 
      state 
    );
  }
  STACK_END (state);
}
/*end class FnDayFromDateIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.17 fn:timezone-from-date
 *
 * fn:timezone-from-date($arg as xs:date?) as xs:dayTimeDuration?
 *_______________________________________________________________________*/

/*begin class FnTimezoneFromDateIterator */
bool
FnTimezoneFromDateIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;
  xqp_dayTimeDuration tmpDuration;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    if (0 == Duration::fromTimezone(itemArg->getDateValue().getTimezone(), tmpDuration))
      STACK_PUSH( GENV_ITEMFACTORY->createDayTimeDuration(result, &tmpDuration), state );
  }
  STACK_END (state);
}
/*end class FnTimezoneFromDateIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.18 fn:hours-from-time
 *
 * fn:hours-from-time($arg as xs:time?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnHoursFromTimeIterator */
bool
FnHoursFromTimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getTimeValue().getHours())), 
      state 
    );
  }
  STACK_END (state);
}
/*end class FnHoursFromTimeIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.19 fn:minutes-from-time
 *
 * fn:minutes-from-time($arg as xs:time?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnMinutesFromTimeIterator */
bool
FnMinutesFromTimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      result,
      Integer::parseInt(itemArg->getTimeValue().getMinutes())), 
      state 
    );
  }
  STACK_END (state);
}
/*end class FnMinutesFromTimeIterator */


/**
 *______________________________________________________________________
 *
 * 10.5.20 fn:seconds-from-time
 *
 * fn:seconds-from-time($arg as xs:time?) as xs:decimal?
 *_______________________________________________________________________*/

/*begin class FnSecondsFromTimeIterator */
bool
FnSecondsFromTimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;
  xqp_decimal lDecimal;
  bool lBool;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  {
    itemArg = itemArg->getAtomizationValue();
    lBool = Decimal::parseNativeDouble(itemArg->getTimeValue().getSeconds(), lDecimal);
    ZORBA_ASSERT(lBool);
    STACK_PUSH( GENV_ITEMFACTORY->createDecimal(result, lDecimal), state );
  }
  STACK_END (state);
}
/*end class FnSecondsFromTimeIterator */



/**
 *______________________________________________________________________
 *
 * 10.5.21 fn:timezone-from-time
 *
 * fn:timezone-from-time($arg as xs:time?) as xs:dayTimeDuration?
 *_______________________________________________________________________*/

/*begin class FnTimezoneFromTimeIterator */
bool
FnTimezoneFromTimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemArg;
  xqp_dayTimeDuration tmpDuration;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemArg, theChildren[0].getp(), planState))
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    if (0 == Duration::fromTimezone(itemArg->getTimeValue().getTimezone(), tmpDuration))
      STACK_PUSH( GENV_ITEMFACTORY->createDayTimeDuration(result, &tmpDuration), state );
  }
  STACK_END (state);
}
/*end class FnTimezoneFromTimeIterator */

/**
 *______________________________________________________________________
 *
 * 10.6.1 op:add-yearMonthDurations
 *
 * op:add-yearMonthDurations(   $arg1    as xs:yearMonthDuration,
 *                                             $arg2    as xs:yearMonthDuration) as xs:yearMonthDuration
 *_______________________________________________________________________*/
 /**
 *______________________________________________________________________
 *
 * 10.6.6 op:add-dayTimeDurations
 *
 * op:add-dayTimeDurations(  $arg1    as xs:dayTimeDuration,
 *                                         $arg2    as xs:dayTimeDuration) as xs:dayTimeDuration
 *_______________________________________________________________________*/

 /**
 *______________________________________________________________________
 *
 * 10.6.2 op:subtract-yearMonthDurations
 *
 * op:subtract-yearMonthDurations(  $arg1    as xs:yearMonthDuration,
 *                                                  $arg2    as xs:yearMonthDuration) as xs:yearMonthDuration
 *_______________________________________________________________________*/
 /**
 *______________________________________________________________________
 *
 * 10.6.7 op:subtract-dayTimeDurations
 *
 * op:subtract-dayTimeDurations(  $arg1    as xs:dayTimeDuration,
 *                                               $arg2    as xs:dayTimeDuration) as xs:dayTimeDuration
 *_______________________________________________________________________*/

 /**
 *______________________________________________________________________
 *
 * 10.6.3 op:multiply-yearMonthDuration
 *
 * op:multiply-yearMonthDuration(   $arg1    as xs:yearMonthDuration,
 *                                                 $arg2    as xs:double) as xs:yearMonthDuration
 *_______________________________________________________________________*/
 /**
 *______________________________________________________________________
 *
 * 10.6.8 op:multiply-dayTimeDuration
 *
 * op:multiply-dayTimeDuration(   $arg1    as xs:dayTimeDuration,
 *                                              $arg2    as xs:double) as xs:dayTimeDuration
 *_______________________________________________________________________*/

  /**
 *______________________________________________________________________
 *
 * 10.6.4 op:divide-yearMonthDuration
 *
 * op:divide-yearMonthDuration(   $arg1    as xs:yearMonthDuration,
 *                                              $arg2    as xs:double) as xs:yearMonthDuration
 *_______________________________________________________________________*/
  /**
 *______________________________________________________________________
 *
 * 10.6.9 op:divide-dayTimeDuration
 *
 * op:divide-dayTimeDuration(   $arg1    as xs:dayTimeDuration,
 *                                            $arg2    as xs:double) as xs:dayTimeDuration
 *_______________________________________________________________________*/

 /**
 *______________________________________________________________________
 *
 * 10.6.5 op:divide-yearMonthDuration-by-yearMonthDuration
 *
 * op:divide-yearMonthDuration-by-yearMonthDuration(  $arg1    as xs:yearMonthDuration,
 *                                                                              $arg2    as xs:yearMonthDuration) as xs:decimal
 *_______________________________________________________________________*/

/**
 *______________________________________________________________________
 *
 * 10.6.10 op:divide-dayTimeDuration-by-dayTimeDuration
 *
 * op:divide-dayTimeDuration-by-dayTimeDuration(  $arg1    as xs:dayTimeDuration,
 *                                                                         $arg2    as xs:dayTimeDuration) as xs:decimal
 *_______________________________________________________________________*/
/* end class DivideOperations */

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
  std::auto_ptr<DateTime> dt;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // If $arg is the empty sequence, then the result is the empty sequence.
  if (!consumeNext(item0, theChild.getp(), planState))
    STACK_PUSH(false, state);
  else
  {
    try 
    {
      dt = std::auto_ptr<DateTime>(item0->getDateTimeValue().adjustToTimeZone(
        planState.theRuntimeCB->theDynamicContext->get_implicit_timezone()));
    }
    catch (InvalidTimezoneException)
    {
      ZORBA_ERROR(FODT0003);
    }
    STACK_PUSH(GENV_ITEMFACTORY->createDateTime(result, dt.get()), state);
  }
    
  STACK_END (state);
}

bool
FnAdjustToTimeZoneIterator_2::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;
  bool s1;
  std::auto_ptr<DateTime> dt;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(item0, theChild0.getp(), planState))
    STACK_PUSH(false, state);
  else
  {
    s1 = consumeNext(item1, theChild1.getp(), planState);
    try 
    {
      dt = std::auto_ptr<DateTime>(item0->getDateTimeValue().adjustToTimeZone(!s1 ? NULL : &item1->getDayTimeDurationValue()));
    }
    catch (InvalidTimezoneException)
    {
      ZORBA_ERROR(FODT0003);
    }
    STACK_PUSH(GENV_ITEMFACTORY->createDateTime(result, dt.get()), state);
  }
     
  STACK_END (state);
}

/**
 *______________________________________________________________________
 * 
 *_______________________________________________________________________*/

void output_number(xqpStringStore_t& str, long number, xqpStringStore& presentation_modifier, xqpStringStore& second_modifier)
{
  // Presentation modifier can be:
  // 'Ww', "Nn', 'W', 'w', 'N', 'n'
  // 'i', 'I', '1', '00...01'
  // the modifier will not be checked if it is supported or not
    
  if (presentation_modifier.byteAt(0) == '0')
  {
    xqpString temp = xqpString("");
    temp.append_in_place(NumConversions::longToStr(number));
    while (temp.bytes() < presentation_modifier.bytes())      
      temp = "0" + temp;    
    str->append_in_place(temp);
  }
  else // "1" or fallback
  {  
    str->append_in_place(NumConversions::longToStr(number));
  }
  
  if (second_modifier.byteEqual("o"))
  {
    if ((number % 10) == 1 && (number % 100) != 11)
      str->append_in_place("st");
    else if ((number % 10) == 2 && (number % 100) != 12)
      str->append_in_place("nd");
    else if ((number % 10) == 3 && (number % 100) != 13)
      str->append_in_place("rd");
    else
      str->append_in_place("th");
  }  
}

void output_month(xqpStringStore_t& str, long number, xqpStringStore& presentation_modifier, xqpStringStore& second_modifier)
{
  static const char* n_month[12]  = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
  static const char* Nn_month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  static const char* N_month[12]  = { "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

  if (presentation_modifier.byteEqual("n"))
    str->append_in_place(n_month[number-1]);
  else if (presentation_modifier.byteEqual("N"))
    str->append_in_place(N_month[number-1]);
  else if (presentation_modifier.byteEqual("Nn"))
    str->append_in_place(Nn_month[number-1]);
  else
    output_number(str, number, presentation_modifier, second_modifier);
}

void output_day_of_week(xqpStringStore_t& str, long number, xqpStringStore& presentation_modifier, xqpStringStore& second_modifier)
{
  static const char* n_day[7]  = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
  static const char* Nn_day[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  static const char* N_day[7]  = { "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};
  
  if (presentation_modifier.byteEqual("n"))
    str->append_in_place(n_day[number]);
  else if (presentation_modifier.byteEqual("N"))
    str->append_in_place(N_day[number]);
  else if (presentation_modifier.byteEqual("Nn"))
    str->append_in_place(Nn_day[number]);
  else
    output_number(str, number, presentation_modifier, second_modifier);
}

void parse_presentation_modifier(xqpStringStore_t& str, unsigned int& position, xqpStringStore& result)
{
  result = xqpStringStore("");
  
  if (position+1 >= str->bytes())
    return;
  
  xqpString modifier = xqpString("");
  
  if (position+2 < str->bytes() && 
      (str->substr(position+1, 2)->byteEqual("Ww") ||  str->substr(position+1, 2)->byteEqual("Nn")))
  {
    modifier.append_in_place(str->substr(position+1, 2));
    position += 2;
  }
  else if (str->byteAt(position+1) == '1' || str->byteAt(position+1) == 'i' || str->byteAt(position+1) == 'I' 
           || str->byteAt(position+1) == 'a' || str->byteAt(position+1) == 'A'
           || str->byteAt(position+1) == 'w' || str->byteAt(position+1) == 'W' 
           || str->byteAt(position+1) == 'n' || str->byteAt(position+1) == 'N' )
  {
    modifier.append_in_place(str->byteAt(position+1));
    position++;
  }
  else if (str->byteAt(position+1) == '0')
  {
    int start = position;
    while (position+1 < str->bytes() && str->byteAt(position+1) == '0')
    {
      modifier.append_in_place(str->byteAt(position+1));
      position++;
    }
    
    if (position+1 >= str->bytes() || str->byteAt(position+1) != '1')
    {
      position = start;
      return;
    }
    
    modifier.append_in_place(str->byteAt(position+1));
    position++;
  }
  
  result = *modifier.theStrStore;
}

void parse_second_modifier(xqpStringStore_t& str, unsigned int& position, xqpStringStore& result)
{
  result = xqpStringStore("");
  
  if (position+1 >= str->bytes())
    return;
  
  position++;
  if (str->byteAt(position) == 't')
    result = xqpStringStore("t");
  else if (str->byteAt(position) == 'o')
    result = xqpStringStore("o");
  else
    position--;
}

void parse_width_modifier(xqpStringStore_t& str, unsigned int& position, xqpStringStore& result)
{
  // TODO
}

/*begin class FnFormatDateTimeIterator */
bool
FnFormatDateTimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool variable_marker;
  xqpStringStore_t pictureString, resultString;
  store::Item_t dateTimeItem, picture;
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(dateTimeItem, theChildren[0].getp(), planState))
  {
    // Got void, returning void
    STACK_PUSH(false, state);
  }
  else
  { 
  	consumeNext(picture, theChildren[1].getp(), planState);
    pictureString = picture->getStringValue();
    resultString = xqpString("").theStrStore;
    variable_marker = false;
    for (unsigned int i=0; i<pictureString->bytes(); i++)
    {      
      if (variable_marker)
      {
        char component = 0;
        xqpStringStore presentation_modifier;
        xqpStringStore second_modifier;
        xqpStringStore width_modifier;

        switch (pictureString->byteAt(i))
        {
        case 'Y': case 'M': case 'D': case 'd': case 'F': case 'W': case 'w': 
        case 'H': case 'h': case 'P': case 'm': case 's': case 'f':
        case 'Z': case 'z': case 'C': case 'E': 
          component = pictureString->byteAt(i);          
          break;

        case ']':
          variable_marker = false;
          break;

        default:          
          ZORBA_ERROR(XTDE1340);          
          break;
        }
        
        if (variable_marker == false)
          continue;

        parse_presentation_modifier(pictureString, i, presentation_modifier);
        parse_second_modifier(pictureString, i, second_modifier);
        parse_width_modifier(pictureString, i, width_modifier);
        
        // TODO: width modifier
        
        // std::cout << "Got pres. modifier: " << presentation_modifier << "  Second modifier: " << second_modifier << std::endl;

        switch (component)
        {
        case 'Y': 
          // TODO: year can be negative
          output_number(resultString, dateTimeItem->getDateTimeValue().getYear(), presentation_modifier, second_modifier);
          break;
        case 'M': 
          output_month(resultString, dateTimeItem->getDateTimeValue().getMonth(), presentation_modifier, second_modifier);
          break; 
        case 'D': 
          output_number(resultString, dateTimeItem->getDateTimeValue().getDay(), presentation_modifier, second_modifier);
          break; 
        case 'd':  // day in year
          output_number(resultString, dateTimeItem->getDateTimeValue().getDayOfYear(), presentation_modifier, second_modifier);
          break;
        case 'F':  // day of week
          output_day_of_week(resultString, dateTimeItem->getDateTimeValue().getDayOfWeek(), presentation_modifier, second_modifier);
          break;
        case 'W':  // week in year
          break;
        case 'w':  // week in month
          break;
        case 'H':  // hour in day (24 hours)
          output_number(resultString, dateTimeItem->getDateTimeValue().getHours(), presentation_modifier, second_modifier);
          break;
        case 'h':  // hour in half-day (12 hours)
          if (dateTimeItem->getDateTimeValue().getHours() >= 12)
            output_number(resultString, dateTimeItem->getDateTimeValue().getHours() - 12, presentation_modifier, second_modifier);
          else
            output_number(resultString, dateTimeItem->getDateTimeValue().getHours(), presentation_modifier, second_modifier);
          break;
        case 'P':  // am/pm marker
          if (presentation_modifier.byteEqual("N"))
            resultString->append_in_place(dateTimeItem->getDateTimeValue().getHours() >= 12? "PM" : "AM");
          else if (presentation_modifier.byteEqual("Nn"))
            resultString->append_in_place(dateTimeItem->getDateTimeValue().getHours() >= 12? "Pm" : "Am");
          else
            resultString->append_in_place(dateTimeItem->getDateTimeValue().getHours() >= 12? "pm" : "am");          
          break;
        case 'm':  
          output_number(resultString, dateTimeItem->getDateTimeValue().getMinutes(), presentation_modifier, second_modifier);
          break;
        case 's':
          output_number(resultString, dateTimeItem->getDateTimeValue().getIntSeconds(), presentation_modifier, second_modifier);
          break;
        case 'f': // fractional seconds
          break;
        case 'Z': // timezone as a time offset from UTC, or if an alphabetic modifier is present the conventional name of a timezone (such as PST)
          break;
        case 'z': // timezone as a time offset using GMT, for example GMT+1
          break;
        case 'C': // calendar: the name or abbreviation of a calendar name
          break;
        case 'E': // era: the name of a baseline for the numbering of years, for example the reign of a monarch
          break;
        }
      }
      else
      {
        if (pictureString->byteAt(i) == '[')
        {
          // check for quoted "[["
          if (i<pictureString->bytes()-1 && pictureString->byteAt(i+1) == '[')
            i++;
          else
          {
            variable_marker = true;
            continue;
          }
        }
        else if (pictureString->byteAt(i) == ']')
        {
          // check for quoted "]]"
          if (i<pictureString->bytes()-1 && pictureString->byteAt(i+1) == ']')
            i++;
        }

        resultString->append_in_place(pictureString->byteAt(i));
      }
    }

  	STACK_PUSH(GENV_ITEMFACTORY->createString(result, resultString), state);
  }

  STACK_END (state);
}
/*end class FnFormatDateTimeIterator */



}
