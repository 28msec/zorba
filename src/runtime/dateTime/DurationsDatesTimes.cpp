/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Nicolae Brinza, Sorin Nasoi
 */

#include "runtime/dateTime/DurationsDatesTimes.h"
#include "runtime/base/iterator.h"

#include <iostream>
using namespace std;

namespace xqp
{

Item_t FnDateTimeConstructorIterator::nextImpl(PlanState& planState)
{
  Item_t item0;
  Item_t item1;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item0 = consumeNext(theChild0, planState);
  item1 = consumeNext(theChild1, planState);

  if (item0 == NULL || item1 == NULL)
    STACK_PUSH(NULL, state);
  else
    STACK_PUSH(Zorba::getItemFactory()->createDateTime(item0, item1), state);
     
  STACK_END();
}


Item_t 
OpDurationEqualIterator::nextImpl(PlanState& planState)
{
  Item_t item0;
  Item_t item1;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // TODO: arguments should be of type xs:duration

  item0 = consumeNext(theChild0, planState);
  item1 = consumeNext(theChild1, planState);
  

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
FnYearsFromDurationIterator::nextImpl(PlanState& planState)
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChild, planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(itemArg->getYears()), state );
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
FnMonthsFromDurationIterator::nextImpl(PlanState& planState)
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChild, planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(itemArg->getMonths()), state );
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
FnDaysFromDurationIterator::nextImpl(PlanState& planState)
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChild, planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(itemArg->getDays()), state );
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
FnHoursFromDurationIterator::nextImpl(PlanState& planState)
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChild, planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(itemArg->getHours()), state );
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
FnMinutesFromDurationIterator::nextImpl(PlanState& planState)
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChild, planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(itemArg->getMinutes()), state );
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
FnSecondsFromDurationIterator::nextImpl(PlanState& planState)
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChild, planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createDecimal(itemArg->getSeconds()), state );
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
FnYearFromDatetimeIterator::nextImpl(PlanState& planState)
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChild, planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(itemArg->getYear()), state );
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
FnMonthFromDatetimeIterator::nextImpl(PlanState& planState)
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChild, planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(itemArg->getMonth()), state );
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
FnDayFromDatetimeIterator::nextImpl(PlanState& planState)
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChild, planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(itemArg->getDay()), state );
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
FnHoursFromDatetimeIterator::nextImpl(PlanState& planState)
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChild, planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(itemArg->getHours()), state );
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
FnMinutesFromDatetimeIterator::nextImpl(PlanState& planState)
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChild, planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createInteger(itemArg->getMinutes()), state );
  }
  STACK_END();
}
/*end class FnMinutesFromDatetimeIterator */

/**
 *______________________________________________________________________
 *
 * 10.5.11 fn:seconds-from-dateTime
 *
 * fn:seconds-from-dateTime($arg as xs:dateTime?) as xs:decimal?
 *_______________________________________________________________________*/

/*begin class FnSecondsFromDatetimeIterator */
Item_t 
FnSecondsFromDatetimeIterator::nextImpl(PlanState& planState)
{
  Item_t itemArg;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemArg = consumeNext(theChild, planState);
  if ( itemArg != NULL )
  {
    itemArg = itemArg->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createDecimal(itemArg->getSeconds()), state );
  }
  STACK_END();
}
/*end class FnSecondsFromDatetimeIterator */


}
