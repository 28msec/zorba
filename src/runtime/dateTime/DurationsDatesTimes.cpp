  /*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Nicolae Brinza, Sorin Nasoi
 */
#include <zorba/item.h>

#include "errors/error_factory.h"
#include "util/Assert.h"

#include "types/casting.h"
#include "system/zorba.h"

#include "runtime/dateTime/DurationsDatesTimes.h"
#include "runtime/core/arithmetic_impl.h"

#include "store/api/item_factory.h"

using namespace std;

namespace xqp
{

Item_t FnDateTimeConstructorIterator::nextImpl(PlanState& planState) const
{
  Item_t item0;
  Item_t item1;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item0 = consumeNext(theChild0.getp(), planState);
  item1 = consumeNext(theChild1.getp(), planState);

  if (item0 == NULL || item1 == NULL)
    STACK_PUSH(NULL, state);
  else
    STACK_PUSH(Zorba::getItemFactory()->createDateTime(item0, item1), state);
     
  STACK_END();
}


Item_t 
OpDurationEqualIterator::nextImpl(PlanState& planState) const
{
  Item_t item0;
  Item_t item1;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // TODO: arguments should be of type xs:duration

  item0 = consumeNext(theChild0.getp(), planState);
  item1 = consumeNext(theChild1.getp(), planState);
  

  // theChild0 theChild1
  // if(theChildren.size() == 2 || theChildren.size()==3)
  {
    /*
    item0 = consumeNext ( theChildren[0], planState );
    if ( item0 != NULL )
    {
      item0 = item0->getAtomizationValue();
      if(item0->getStringValue().length() == 0)
      {
        STACK_PUSH( Zorba::getItemFactory()->createString(resStr), state );
      }
      else{
        item1 = consumeNext( theChildren[1], planState );
        if( item1 != NULL )
        {//note: The first character of a string is located at position 1, not position 0.
          item1 = item1->getAtomizationValue();
          if( theChildren.size() == 2 )
          {
            resStr = item0->getStringValue().substr((int32_t)round(item1->getDecimalValue())-1);
          }
          else{ //theChildren.size() ==3
            item2 = consumeNext ( theChildren[2], planState );
            if ( item2 != NULL )
            {
              item2 = item2->getAtomizationValue();
              resStr = item0->getStringValue().substr((int32_t)round(item1->getDecimalValue())-1,
                                             (int32_t)round(item2->getDecimalValue()));
            }
          }
          STACK_PUSH( Zorba::getItemFactory()->createString(resStr), state );
        }
      }
    }
    */
  }
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
Item_t
FnYearsFromDurationIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;
  int32_t lYears;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    lYears = itemArg->getDurationValue()->getYears();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnMonthsFromDurationIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnDaysFromDurationIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnHoursFromDurationIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnMinutesFromDurationIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnSecondsFromDurationIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;
  xqp_decimal lDecimal;
  bool lBool;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    lBool = Decimal::parseNativeDouble(itemArg->getDurationValue()->getSeconds(), lDecimal);
    Assert(lBool);
    STACK_PUSH( Zorba::getItemFactory()->createDecimal(lDecimal), state );
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
Item_t
FnYearFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH(
        Zorba::getItemFactory()->createInteger(
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
Item_t
FnMonthFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnDayFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnHoursFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnMinutesFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnSecondsFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;
  xqp_decimal lDecimal;
  bool lBool;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    lBool = Decimal::parseNativeDouble(itemArg->getDateTimeValue()->getSeconds(), lDecimal);
    Assert(lBool);
    STACK_PUSH( Zorba::getItemFactory()->createDecimal(lDecimal), state );
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
Item_t
FnTimezoneFromDatetimeIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;
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
      STACK_PUSH( Zorba::getItemFactory()->createDuration(tmpDuration), state );
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
Item_t
FnYearFromDateIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnMonthFromDateIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnDayFromDateIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnTimezoneFromDateIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;
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
      STACK_PUSH( Zorba::getItemFactory()->createDuration(tmpDuration), state );
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
Item_t
FnHoursFromTimeIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnMinutesFromTimeIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(
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
Item_t
FnSecondsFromTimeIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;
  xqp_decimal lDecimal;
  bool lBool;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    lBool = Decimal::parseNativeDouble(itemArg->getTimeValue()->getSeconds(), lDecimal);
    Assert(lBool);
    STACK_PUSH( Zorba::getItemFactory()->createDecimal(lDecimal), state );
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
Item_t
FnTimezoneFromTimeIterator::nextImpl(PlanState& planState) const
{
  Item_t itemArg;
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
      STACK_PUSH( Zorba::getItemFactory()->createDuration(tmpDuration), state );
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
/* begin class AddOperations */
//TODO: replace the types with XS_YM_DURATION and add another specialization for XS_DT_DURATION
/*
template<>
Item_t AddOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DURATION>
( const yy::location* loc,  const Item* i0, const Item* i1 )
{
  xqp_duration d = *i0->getDurationValue() + *i1->getDurationValue();
  return Zorba::getItemFactory()->createDuration (d);
}
*/
/* end class AddOperations */

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
/* start class SubtractOperations */
//TODO: replace the types with XS_YM_DURATION and add another specialization for XS_DT_DURATION
/*
template<>
Item_t SubtractOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DURATION>
( const yy::location* loc, const Item* i0, const Item* i1 )
{
  xqp_duration d = *i0->getDurationValue() - *i1->getDurationValue();
  return Zorba::getItemFactory()->createDuration (d);
}
*/
/* end class SubtractOperations */

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
/* start class MultiplyOperations */
//TODO: replace the types with XS_YM_DURATION and add another specialization for XS_DT_DURATION
/*
template<>
Item_t MultiplyOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DOUBLE>
( const yy::location* loc, const Item* i0, const Item* i1 )
{
  xqp_duration d;

  if( i1->getDoubleValue().isZero() )
    return Zorba::getItemFactory()->createDuration(0,0,0,0,0,0);
  else if ( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
    ZORBA_ERROR_ALERT( ZorbaError::FODT0002, NULL, DONT_CONTINUE_EXECUTION, "Overflow/underflow in duration operation.");
  else if (  i1->getDoubleValue().isNaN() )
    ZORBA_ERROR_ALERT( ZorbaError::FOCA0005, NULL, DONT_CONTINUE_EXECUTION, "NaN supplied as float/double value");
  else
    d = *i0->getDurationValue() * (i1->getDoubleValue());
  
  return Zorba::getItemFactory()->createDuration (d);
}
*/
/* end class MultiplyOperations */

/* start class DivideOperations */
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
//TODO: replace the first type with XS_YM_DURATION and add another specialization for XS_DT_DURATION
/*
template<>
Item_t DivideOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DOUBLE>
( const yy::location* loc, const Item* i0, const Item* i1 )
{
  xqp_duration d;

  if( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
    return Zorba::getItemFactory()->createDuration(0,0,0,0,0,0);
  else if ( i1->getDoubleValue().isZero() )
    ZORBA_ERROR_ALERT( ZorbaError::FODT0002, NULL, DONT_CONTINUE_EXECUTION, "Overflow/underflow in duration operation.");
  else if ( i1->getDoubleValue().isNaN() )
    ZORBA_ERROR_ALERT( ZorbaError::FOCA0005, NULL, DONT_CONTINUE_EXECUTION, "NaN supplied as float/double value");
  else
    d= *i0->getDurationValue() / i1->getDoubleValue();

  return Zorba::getItemFactory()->createDuration (d);
}
*/

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
//TODO: replace the types with XS_YM_DURATION and add another specialization for XS_DT_DURATION
/*
template<>
Item_t DivideOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DURATION>
( const yy::location* loc, const Item* i0, const Item* i1 )
{
  xqp_decimal d = *i0->getDurationValue() / *i1->getDurationValue();
  return Zorba::getItemFactory()->createDecimal(d);
}
*/
/* end class DivideOperations */
}
