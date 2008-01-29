/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Nicolae Brinza, Sorin Nasoi
 */

#ifndef XQP_DURATIONSDATESTIMES_H
#define XQP_DURATIONSDATESTIMES_H

#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/iterator.h"

namespace xqp
{

class FnDateTimeConstructorIterator : public BinaryBaseIterator<FnDateTimeConstructorIterator>
{
public:
  FnDateTimeConstructorIterator( const yy::location loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
    :
    BinaryBaseIterator<FnDateTimeConstructorIterator>(loc, arg0, arg1){}

  virtual ~FnDateTimeConstructorIterator() {};

public:
  Item_t nextImpl(PlanState& planState);
  virtual void accept(PlanIterVisitor&) const;
};
/*
10.1 Duration, Date and Time Types
10.1.1 Limits and Precision
10.2 Date/time datatype values
10.2.1 Examples
10.3 Two Totally Ordered Subtypes of Duration
10.3.1 xs:yearMonthDuration
10.3.2 xs:dayTimeDuration
10.4 Comparison Operators on Duration, Date and Time Values
10.4.1 op:yearMonthDuration-less-than
10.4.2 op:yearMonthDuration-greater-than
10.4.3 op:dayTimeDuration-less-than
10.4.4 op:dayTimeDuration-greater-than
*/

// 10.4.5 op:duration-equal
class OpDurationEqualIterator : public BinaryBaseIterator<OpDurationEqualIterator>{
public:
  OpDurationEqualIterator( const yy::location loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
  BinaryBaseIterator<OpDurationEqualIterator>(loc, arg0, arg1){}

  virtual ~OpDurationEqualIterator() {};
  
public:
  Item_t nextImpl(PlanState& planState);
  
  virtual void accept(PlanIterVisitor&) const;
};

/*
10.4.6 op:dateTime-equal
10.4.7 op:dateTime-less-than
10.4.8 op:dateTime-greater-than
10.4.9 op:date-equal
10.4.10 op:date-less-than
10.4.11 op:date-greater-than
10.4.12 op:time-equal
10.4.13 op:time-less-than
10.4.14 op:time-greater-than
10.4.15 op:gYearMonth-equal
10.4.16 op:gYear-equal
10.4.17 op:gMonthDay-equal
10.4.18 op:gMonth-equal
10.4.19 op:gDay-equal
*/

/*  
 * 10.5 Component Extraction Functions on Durations, Dates and Times
 * --------------------*/
/*
 * 10.5.1 fn:years-from-duration
 * --------------------*/
 
/*begin class YearsFromDurationIterator */
NARY_ITER(FnYearsFromDurationIterator);
/*end class YearsFromDurationIterator */

/*
 * 10.5.2 fn:months-from-duration
 * --------------------*/
 
/*begin class FnMonthsFromDurationIterator */
NARY_ITER(FnMonthsFromDurationIterator);
/*end class FnMonthsFromDurationIterator */

/*
 * 10.5.3 fn:days-from-duration
 * --------------------*/
 
/*begin class FnDaysFromDurationIterator */
NARY_ITER(FnDaysFromDurationIterator);
/*end class FnDaysFromDurationIterator */


/*
 * 10.5.4 fn:hours-from-duration
 * --------------------*/
 
/*begin class FnHoursFromDurationIterator */
NARY_ITER(FnHoursFromDurationIterator);
/*end class FnHoursFromDurationIterator */

/*
 * 10.5.5 fn:minutes-from-duration
 * --------------------*/
 
/*begin class FnMinutesFromDurationIterator */
NARY_ITER(FnMinutesFromDurationIterator);
/*end class FnMinutesFromDurationIterator */

/*
 * 10.5.6 fn:seconds-from-duration
 * --------------------*/
 
/*begin class FnSecondsFromDurationIterator */
NARY_ITER(FnSecondsFromDurationIterator);
/*end class FnSecondsFromDurationIterator */

/*
 * 10.5.7 fn:year-from-dateTime
 * --------------------*/
 
/*begin class FnYearFromDatetimeIterator */
NARY_ITER(FnYearFromDatetimeIterator);
/*end class FnYearFromDatetimeIterator */

/*
 * 10.5.8 fn:month-from-dateTime
 * --------------------*/
 
/*begin class FnMonthFromDatetimeIterator */
NARY_ITER(FnMonthFromDatetimeIterator);
/*end class FnMonthFromDatetimeIterator */

/*
 * 10.5.9 fn:day-from-dateTime
 * --------------------*/
 
/*begin class FnDayFromDatetimeIterator */
NARY_ITER(FnDayFromDatetimeIterator);
/*end class FnDayFromDatetimeIterator */

/*
 * 10.5.10 fn:hours-from-dateTime
 * --------------------*/
 
/*begin class FnHoursFromDatetimeIterator */
NARY_ITER(FnHoursFromDatetimeIterator);
/*end class FnHoursFromDatetimeIterator */

/*
 * 10.5.11 fn:minutes-from-dateTime
 * --------------------*/
 
/*begin class FnMinutesFromDatetimeIterator */
NARY_ITER(FnMinutesFromDatetimeIterator);
/*end class FnMinutesFromDatetimeIterator */

/*
 * 10.5.12 fn:seconds-from-dateTime
 * --------------------*/
 
/*begin class FnSecondsFromDatetimeIterator */
NARY_ITER(FnSecondsFromDatetimeIterator);
/*end class FnSecondsFromDatetimeIterator */

/*
 * 10.5.13 fn:timezone-from-dateTime
 * --------------------*/
 
/*begin class FnTimezoneFromDatetimeIterator */
NARY_ITER(FnTimezoneFromDatetimeIterator);
/*end class FnTimezoneFromDatetimeIterator */

/*
 * 10.5.14 fn:year-from-date
 * --------------------*/
 
/*begin class FnYearFromDateIterator */
NARY_ITER(FnYearFromDateIterator);
/*end class FnYearFromDateIterator */

/*
 * 10.5.15 fn:month-from-date
 * --------------------*/
 
/*begin class FnMonthFromDateIterator */
NARY_ITER(FnMonthFromDateIterator);
/*end class FnMonthFromDateIterator */

/*
 * 10.5.16 fn:day-from-date
 * --------------------*/
 
/*begin class FnDayFromDateIterator */
NARY_ITER(FnDayFromDateIterator);
/*end class FnDayFromDateIterator */

/*
 * 10.5.17 fn:timezone-from-date
 * --------------------*/
 
/*begin class FnTimezoneFromDateIterator */
NARY_ITER(FnTimezoneFromDateIterator);
/*end class FnTimezoneFromDateIterator */

/*
 * 10.5.18 fn:hours-from-time
 * --------------------*/
 
/*begin class FnHoursFromTimeIterator */
NARY_ITER(FnHoursFromTimeIterator);
/*end class FnHoursFromTimeIterator */

/*
 * 10.5.19 fn:minutes-from-time
 * --------------------*/
 
/*begin class FnMinutesFromTimeIterator */
NARY_ITER(FnMinutesFromTimeIterator);
/*end class FnMinutesFromTimeIterator */


/*
 * 10.5.20 fn:seconds-from-time
 * --------------------*/
 
/*begin class FnSecondsFromTimeIterator */
NARY_ITER(FnSecondsFromTimeIterator);
/*end class FnSecondsFromTimeIterator */

/*
 * 10.5.21 fn:timezone-from-time
 * --------------------*/
 
/*begin class FnTimezoneFromTimeIterator */
NARY_ITER(FnTimezoneFromTimeIterator);
/*end class FnTimezoneFromTimeIterator */

/*
10.6 Arithmetic Operators on Durations
10.6.1 op:add-yearMonthDurations
10.6.2 op:subtract-yearMonthDurations
10.6.3 op:multiply-yearMonthDuration
10.6.4 op:divide-yearMonthDuration
10.6.5 op:divide-yearMonthDuration-by-yearMonthDuration
10.6.6 op:add-dayTimeDurations
10.6.7 op:subtract-dayTimeDurations
10.6.8 op:multiply-dayTimeDuration
10.6.9 op:divide-dayTimeDuration
10.6.10 op:divide-dayTimeDuration-by-dayTimeDuration
10.7 Timezone Adjustment Functions on Dates and Time Values
10.7.1 fn:adjust-dateTime-to-timezone
10.7.2 fn:adjust-date-to-timezone
10.7.3 fn:adjust-time-to-timezone
10.8 Arithmetic Operators on Durations, Dates and Times
10.8.1 op:subtract-dateTimes
10.8.2 op:subtract-dates
10.8.3 op:subtract-times
10.8.4 op:add-yearMonthDuration-to-dateTime
10.8.5 op:add-dayTimeDuration-to-dateTime
10.8.6 op:subtract-yearMonthDuration-from-dateTime
10.8.7 op:subtract-dayTimeDuration-from-dateTime
10.8.8 op:add-yearMonthDuration-to-date
10.8.9 op:add-dayTimeDuration-to-date
10.8.10 op:subtract-yearMonthDuration-from-date
10.8.11 op:subtract-dayTimeDuration-from-date
10.8.12 op:add-dayTimeDuration-to-time
10.8.13 op:subtract-dayTimeDuration-from-time
*/

} // namespace xqp

#endif
