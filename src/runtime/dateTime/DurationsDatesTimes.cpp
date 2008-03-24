  /*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Nicolae Brinza, Sorin Nasoi
 */
#include "store/api/item.h"

#include "util/Assert.h"

#include "types/casting.h"
#include "context/dynamic_context.h"

#include "runtime/dateTime/DurationsDatesTimes.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/api/runtimecb.h"
#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"

using namespace std;

namespace zorba
{

store::Item_t FnDateTimeConstructorIterator::nextImpl(PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item0 = consumeNext(theChild0.getp(), planState);
  item1 = consumeNext(theChild1.getp(), planState);

  if (item0 == NULL || item1 == NULL)
    STACK_PUSH(NULL, state);
  else
    STACK_PUSH(GENV_ITEMFACTORY->createDateTime(item0, item1), state);
     
  STACK_END();
}

/**
 *______________________________________________________________________
 *
 * 10.5.1 fn:years-from-duration
 *
 * fn:years-from-duration($arg as xs:duration?) as xs:integer?
 *_______________________________________________________________________*/

/*begin class FnYearsFromDurationIterator */
store::Item_t
FnYearsFromDurationIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;
  int32_t lYears;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    lYears = itemArg->getDurationValue()->getYears();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(lYears)), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnMonthsFromDurationIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getDurationValue()->getMonths())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnDaysFromDurationIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getDurationValue()->getDays())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnHoursFromDurationIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getDurationValue()->getHours())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnMinutesFromDurationIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getDurationValue()->getMinutes())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnSecondsFromDurationIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;
  xqp_decimal lDecimal;
  bool lBool;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    lBool = Decimal::parseNativeDouble(itemArg->getDurationValue()->getSeconds(), lDecimal);
    ZORBA_ASSERT(lBool);
    STACK_PUSH( GENV_ITEMFACTORY->createDecimal(lDecimal), state );
  }
  STACK_END();
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
store::Item_t
FnYearFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH(
        GENV_ITEMFACTORY->createInteger(
          Integer::parseInt(itemArg->getDateTimeValue()->getYear())), state );
  }
  STACK_END();
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
store::Item_t
FnMonthFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getDateTimeValue()->getMonth())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnDayFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getDateTimeValue()->getDay())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnHoursFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getDateTimeValue()->getHours())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnMinutesFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getDateTimeValue()->getMinutes())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnSecondsFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;
  xqp_decimal lDecimal;
  bool lBool;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    lBool = Decimal::parseNativeDouble(itemArg->getDateTimeValue()->getSeconds(), lDecimal);
    ZORBA_ASSERT(lBool);
    STACK_PUSH( GENV_ITEMFACTORY->createDecimal(lDecimal), state );
  }
  STACK_END();
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
store::Item_t
FnTimezoneFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;
  xqp_duration tmpDuration;
  bool res = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    res = DayTimeDuration::from_Timezone(itemArg->getDateTimeValue()->getTimezone(), tmpDuration);
    if(res)
      STACK_PUSH( GENV_ITEMFACTORY->createDuration(tmpDuration), state );
  }
  STACK_END();
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
store::Item_t
FnYearFromDateIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getDateValue()->getYear())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnMonthFromDateIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getDateValue()->getMonth())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnDayFromDateIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getDateValue()->getDay())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnTimezoneFromDateIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;
  xqp_duration tmpDuration;
  bool res = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    res = DayTimeDuration::from_Timezone(itemArg->getDateValue()->getTimezone(), tmpDuration);
    if(res)
      STACK_PUSH( GENV_ITEMFACTORY->createDuration(tmpDuration), state );
  }
  STACK_END();
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
store::Item_t
FnHoursFromTimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getTimeValue()->getHours())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnMinutesFromTimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( GENV_ITEMFACTORY->createInteger(
      Integer::parseInt(itemArg->getTimeValue()->getMinutes())), 
      state 
    );
  }
  STACK_END();
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
store::Item_t
FnSecondsFromTimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;
  xqp_decimal lDecimal;
  bool lBool;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    lBool = Decimal::parseNativeDouble(itemArg->getTimeValue()->getSeconds(), lDecimal);
    ZORBA_ASSERT(lBool);
    STACK_PUSH( GENV_ITEMFACTORY->createDecimal(lDecimal), state );
  }
  STACK_END();
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
store::Item_t
FnTimezoneFromTimeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemArg;
  xqp_duration tmpDuration;
  bool res = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    res = DayTimeDuration::from_Timezone(itemArg->getTimeValue()->getTimezone(), tmpDuration);
    if(res)
      STACK_PUSH( GENV_ITEMFACTORY->createDuration(tmpDuration), state );
  }
  STACK_END();
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
store::Item_t FnAdjustToTimeZoneIterator_1::nextImpl(PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;
  DateTime_t dt_t;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item0 = consumeNext(theChild.getp(), planState);

  // If $arg is the empty sequence, then the result is the empty sequence.
  if (item0 == NULL)
    STACK_PUSH(NULL, state);
  else
  {
    try {
      dt_t = item0->getDateTimeValue()->adjustToTimeZone(
        planState.theRuntimeCB->theDynamicContext->get_implicit_timezone());
    } catch (InvalidTimezoneException) {
      ZORBA_ERROR(ZorbaError::FODT0003);
    }
    STACK_PUSH(GENV_ITEMFACTORY->createDateTime(dt_t), state);
  }
    
  STACK_END();
}

store::Item_t FnAdjustToTimeZoneIterator_2::nextImpl(PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;
  DateTime_t dt_t;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item0 = consumeNext(theChild0.getp(), planState);
  
  if (item0 == NULL)
    STACK_PUSH(NULL, state);
  else
  {
    item1 = consumeNext(theChild1.getp(), planState);
    try {
      dt_t = item0->getDateTimeValue()->adjustToTimeZone(item1.isNull()? NULL : item1->getDurationValue());
    } catch (InvalidTimezoneException) {
      ZORBA_ERROR(ZorbaError::FODT0003);
    }
    STACK_PUSH(GENV_ITEMFACTORY->createDateTime(dt_t), state);
  }
     
  STACK_END();
}


}
