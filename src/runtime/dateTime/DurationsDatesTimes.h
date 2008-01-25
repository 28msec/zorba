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
class FnYearsFromDurationIterator : public UnaryBaseIterator<FnYearsFromDurationIterator>
{
  public:
    FnYearsFromDurationIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<FnYearsFromDurationIterator>( loc, arg ){};
  
    ~FnYearsFromDurationIterator(){};
  public:
    Item_t nextImpl(PlanState& planState);
    
    virtual void accept(PlanIterVisitor&) const;
};
/*end class YearsFromDurationIterator */

/*
 * 10.5.2 fn:months-from-duration
 * --------------------*/
 
/*begin class FnMonthsFromDurationIterator */
class FnMonthsFromDurationIterator : public UnaryBaseIterator<FnMonthsFromDurationIterator>
{
  public:
    FnMonthsFromDurationIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<FnMonthsFromDurationIterator>( loc, arg ){};
  
    ~FnMonthsFromDurationIterator(){};
  public:
    Item_t nextImpl(PlanState& planState);
    
    virtual void accept(PlanIterVisitor&) const;
};
/*end class FnMonthsFromDurationIterator */

/*
 * 10.5.3 fn:days-from-duration
 * --------------------*/
 
/*begin class FnDaysFromDurationIterator */
class FnDaysFromDurationIterator : public UnaryBaseIterator<FnDaysFromDurationIterator>
{
  public:
    FnDaysFromDurationIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<FnDaysFromDurationIterator>( loc, arg ){};
  
    ~FnDaysFromDurationIterator(){};
  public:
    Item_t nextImpl(PlanState& planState);
    
    virtual void accept(PlanIterVisitor&) const;
};

/*
 * 10.5.4 fn:hours-from-duration
 * --------------------*/
 
/*begin class FnHoursFromDurationIterator */
class FnHoursFromDurationIterator : public UnaryBaseIterator<FnHoursFromDurationIterator>
{
  public:
    FnHoursFromDurationIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<FnHoursFromDurationIterator>( loc, arg ){};
  
    ~FnHoursFromDurationIterator(){};
  public:
    Item_t nextImpl(PlanState& planState);
    
    virtual void accept(PlanIterVisitor&) const;
};
/*end class FnHoursFromDurationIterator */

/*
 * 10.5.5 fn:minutes-from-duration
 * --------------------*/
 
/*begin class FnMinutesFromDurationIterator */
class FnMinutesFromDurationIterator : public UnaryBaseIterator<FnMinutesFromDurationIterator>
{
  public:
    FnMinutesFromDurationIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<FnMinutesFromDurationIterator>( loc, arg ){};
  
    ~FnMinutesFromDurationIterator(){};
  public:
    Item_t nextImpl(PlanState& planState);
    
    virtual void accept(PlanIterVisitor&) const;
};
/*end class FnMinutesFromDurationIterator */

/*
 * 10.5.6 fn:seconds-from-duration
 * --------------------*/
 
/*begin class FnSecondsFromDurationIterator */
class FnSecondsFromDurationIterator : public UnaryBaseIterator<FnSecondsFromDurationIterator>
{
  public:
    FnSecondsFromDurationIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<FnSecondsFromDurationIterator>( loc, arg ){};
  
    ~FnSecondsFromDurationIterator(){};
  public:
    Item_t nextImpl(PlanState& planState);
    
    virtual void accept(PlanIterVisitor&) const;
};
/*end class FnSecondsFromDurationIterator */

/*
 * 10.5.7 fn:year-from-dateTime
 * --------------------*/
 
/*begin class FnYearFromDatetimeIterator */
class FnYearFromDatetimeIterator : public UnaryBaseIterator<FnYearFromDatetimeIterator>
{
  public:
    FnYearFromDatetimeIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<FnYearFromDatetimeIterator>( loc, arg ){};
  
    ~FnYearFromDatetimeIterator(){};
  public:
    Item_t nextImpl(PlanState& planState);
    
    virtual void accept(PlanIterVisitor&) const;
};
/*end class FnYearFromDatetimeIterator */

/*
 * 10.5.8 fn:month-from-dateTime
 * --------------------*/
 
/*begin class FnMonthFromDatetimeIterator */
class FnMonthFromDatetimeIterator : public UnaryBaseIterator<FnMonthFromDatetimeIterator>
{
  public:
    FnMonthFromDatetimeIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<FnMonthFromDatetimeIterator>( loc, arg ){};
  
    ~FnMonthFromDatetimeIterator(){};
  public:
    Item_t nextImpl(PlanState& planState);
    
    virtual void accept(PlanIterVisitor&) const;
};
/*end class FnMonthFromDatetimeIterator */

/*
 * 10.5.9 fn:day-from-dateTime
 * --------------------*/
 
/*begin class FnDayFromDatetimeIterator */
class FnDayFromDatetimeIterator : public UnaryBaseIterator<FnDayFromDatetimeIterator>
{
  public:
    FnDayFromDatetimeIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<FnDayFromDatetimeIterator>( loc, arg ){};
  
    ~FnDayFromDatetimeIterator(){};
  public:
    Item_t nextImpl(PlanState& planState);
    
    virtual void accept(PlanIterVisitor&) const;
};
/*end class FnDayFromDatetimeIterator */

/*
 * 10.5.10 fn:hours-from-dateTime
 * --------------------*/
 
/*begin class FnHoursFromDatetimeIterator */
class FnHoursFromDatetimeIterator : public UnaryBaseIterator<FnHoursFromDatetimeIterator>
{
  public:
    FnHoursFromDatetimeIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<FnHoursFromDatetimeIterator>( loc, arg ){};
  
    ~FnHoursFromDatetimeIterator(){};
  public:
    Item_t nextImpl(PlanState& planState);
    
    virtual void accept(PlanIterVisitor&) const;
};
/*end class FnHoursFromDatetimeIterator */

/*
 * 10.5.11 fn:minutes-from-dateTime
 * --------------------*/
 
/*begin class FnMinutesFromDatetimeIterator */
class FnMinutesFromDatetimeIterator : public UnaryBaseIterator<FnMinutesFromDatetimeIterator>
{
  public:
    FnMinutesFromDatetimeIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<FnMinutesFromDatetimeIterator>( loc, arg ){};
  
    ~FnMinutesFromDatetimeIterator(){};
  public:
    Item_t nextImpl(PlanState& planState);
    
    virtual void accept(PlanIterVisitor&) const;
};
/*end class FnMinutesFromDatetimeIterator */
/*
10.5.12 fn:seconds-from-dateTime
10.5.13 fn:timezone-from-dateTime
10.5.14 fn:year-from-date
10.5.15 fn:month-from-date
10.5.16 fn:day-from-date
10.5.17 fn:timezone-from-date
10.5.18 fn:hours-from-time
10.5.19 fn:minutes-from-time
10.5.20 fn:seconds-from-time
10.5.21 fn:timezone-from-time

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
