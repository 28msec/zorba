/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id:: parsenodes.cpp,v 1.1.1.1 2006/11/06 08:42:18 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR FOundation.
 *
 */

#include "functions/DateTime.h"
#include "system/globalenv.h"
#include "runtime/dateTime/DurationsDatesTimes.h"
#include "runtime/numerics/NumericsImpl.h"

namespace zorba
{

fn_datetime_ctor::fn_datetime_ctor (
    const signature& sig )
    :
    function ( sig )
{
}

PlanIter_t fn_datetime_ctor::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnDateTimeConstructorIterator(loc, argv[0], argv[1]);
}



/*
 * 10.5.1 fn:years-from-duration
 * --------------------*/
/*begin class fn_years_from_duration*/
fn_years_from_duration::fn_years_from_duration (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_years_from_duration::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnYearsFromDurationIterator(loc, argv);
}

/*end class fn_years_from_duration*/

/*
 * 10.5.2 fn:months-from-duration
 * --------------------*/
/*begin class fn_months_from_duration*/
fn_months_from_duration::fn_months_from_duration (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_months_from_duration::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnMonthsFromDurationIterator(loc, argv);
}

/*end class fn_months_from_duration*/

/*
 * 10.5.3 fn:days-from-duration
 * --------------------*/
/*begin class fn_days_from_duration*/
fn_days_from_duration::fn_days_from_duration (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_days_from_duration::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnDaysFromDurationIterator(loc, argv);
}

/*end class fn_days_from_duration*/

/*
 * 10.5.4 fn:hours-from-duration
 * --------------------*/
/*begin class fn_hours_from_duration*/
fn_hours_from_duration::fn_hours_from_duration (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_hours_from_duration::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnHoursFromDurationIterator(loc, argv);
}

/*end class fn_hours_from_duration*/

/*
 * 10.5.5 fn:minutes-from-duration
 * --------------------*/
/*begin class fn_minutes_from_duration*/
fn_minutes_from_duration::fn_minutes_from_duration (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_minutes_from_duration::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnMinutesFromDurationIterator(loc, argv);
}

/*end class fn_minutes_from_duration*/

/*
 * 10.5.6 fn:seconds-from-duration
 * --------------------*/
/*begin class fn_seconds_from_duration*/
fn_seconds_from_duration::fn_seconds_from_duration (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_seconds_from_duration::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnSecondsFromDurationIterator(loc, argv);
}

/*end class fn_seconds_from_duration*/

/*
 * 10.5.7 fn:year-from-dateTime
 * --------------------*/
/*begin class fn_year_from_datetime*/
fn_year_from_datetime::fn_year_from_datetime (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_year_from_datetime::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnYearFromDatetimeIterator(loc, argv);
}

/*end class fn_seconds_from_duration*/

/*
 * 10.5.8 fn:month-from-dateTime
 * --------------------*/
/*begin class fn_month_from_datetime*/
fn_month_from_datetime::fn_month_from_datetime (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_month_from_datetime::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnMonthFromDatetimeIterator(loc, argv);
}

/*end class fn_month_from_datetime*/

/*
 * 10.5.9 fn:day-from-dateTime
 * --------------------*/
/*begin class fn_day_from_datetime*/
fn_day_from_datetime::fn_day_from_datetime (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_day_from_datetime::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnDayFromDatetimeIterator(loc, argv);
}

/*end class fn_day_from_datetime*/

/*
 * 10.5.10 fn:hours-from-dateTime
 * --------------------*/
/*begin class fn_hours_from_datetime*/
fn_hours_from_datetime::fn_hours_from_datetime (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_hours_from_datetime::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnHoursFromDatetimeIterator(loc, argv);
}

/*end class fn_hours_from_datetime*/

/*
 * 10.5.11 fn:minutes-from-dateTime
 * --------------------*/
/*begin class fn_minutes_from_datetime*/
fn_minutes_from_datetime::fn_minutes_from_datetime (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_minutes_from_datetime::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnMinutesFromDatetimeIterator(loc, argv);
}

/*end class fn_minutes_from_datetime*/

/*
 * 10.5.12 fn:seconds-from-dateTime
 * --------------------*/
/*begin class fn_seconds_from_datetime*/
fn_seconds_from_datetime::fn_seconds_from_datetime (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_seconds_from_datetime::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnSecondsFromDatetimeIterator(loc, argv);
}

/*end class fn_seconds_from_datetime*/


/*
 * 10.5.13 fn:timezone-from-dateTime
 * --------------------*/
/*begin class fn_timezone_from_datetime*/
fn_timezone_from_datetime::fn_timezone_from_datetime (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_timezone_from_datetime::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnTimezoneFromDatetimeIterator(loc, argv);
}

/*end class fn_timezone_from_datetime*/

/*
 * 10.5.14 fn:year-from-date
 * --------------------*/
/*begin class fn_year_from_date*/
fn_year_from_date::fn_year_from_date (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_year_from_date::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnYearFromDateIterator(loc, argv);
}

/*end class fn_year_from_date*/

/*
 * 10.5.15 fn:month-from-date
 * --------------------*/
/*begin class fn_month_from_date*/
fn_month_from_date::fn_month_from_date (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_month_from_date::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnMonthFromDateIterator(loc, argv);
}

/*end class fn_month_from_date*/


/*
 * 10.5.16 fn:day-from-date
 * --------------------*/
/*begin class fn_day_from_date*/
fn_day_from_date::fn_day_from_date (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_day_from_date::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnDayFromDateIterator(loc, argv);
}

/*end class fn_day_from_date*/

/*
 * 10.5.17 fn:timezone-from-date
 * --------------------*/
/*begin class fn_timezone_from_date*/
fn_timezone_from_date::fn_timezone_from_date (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_timezone_from_date::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnTimezoneFromDateIterator(loc, argv);
}

/*end class fn_timezone_from_date*/

/*
 * 10.5.18 fn:hours-from-time
 * --------------------*/
/*begin class fn_hours_from_time*/
fn_hours_from_time::fn_hours_from_time (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_hours_from_time::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnHoursFromTimeIterator(loc, argv);
}

/*end class fn_hours_from_time*/

/*
 * 10.5.19 fn:minutes-from-time
 * --------------------*/
/*begin class fn_minutes_from_time*/
fn_minutes_from_time::fn_minutes_from_time (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_minutes_from_time::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnMinutesFromTimeIterator(loc, argv);
}

/*end class fn_minutes_from_time*/

/*
 * 10.5.20 fn:seconds-from-time
 * --------------------*/
/*begin class fn_seconds_from_time*/
fn_seconds_from_time::fn_seconds_from_time (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_seconds_from_time::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnSecondsFromTimeIterator(loc, argv);
}

/*end class fn_seconds_from_time*/


/*
 * 10.5.21 fn:timezone-from-time
 * --------------------*/
/*begin class fn_timezone_from_time*/
fn_timezone_from_time::fn_timezone_from_time (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
fn_timezone_from_time::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnTimezoneFromTimeIterator(loc, argv);
}

/*end class fn_timezone_from_time*/

/*
 * 10.6.1 op:add-yearMonthDurations
 * --------------------*/
/*begin class op_ym_durations_add*/
op_ym_durations_add::op_ym_durations_add (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_ym_durations_add::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<AddOperation>(loc, argv[0], argv[1]);
}

/*end class op_ym_durations_add*/

/*
 * 10.6.2 op:subtract-yearMonthDurations
 * --------------------*/
/*begin class op_ym_durations_subtract*/
op_ym_durations_subtract::op_ym_durations_subtract (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_ym_durations_subtract::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<SubtractOperation>(loc, argv[0], argv[1]);
}

/*end class op_ym_durations_subtract*/

/*
 * 10.6.3 op:multiply-yearMonthDuration
 * --------------------*/
/*begin class op_ym_durations_multiply*/
op_ym_durations_multiply::op_ym_durations_multiply (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_ym_durations_multiply::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<MultiplyOperation>(loc,  argv[0], argv[1]);
}

/*end class op_ym_durations_multiply*/

/*
 * 10.6.4 op:divide-yearMonthDuration
 * --------------------*/
/*begin class op_ym_durations_divide*/
op_ym_durations_divide::op_ym_durations_divide (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_ym_durations_divide::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<DivideOperation>(loc,  argv[0], argv[1]);
}

/*end class op_ym_durations_divide*/

/*
 * 10.6.5 op:divide-yearMonthDuration-by-yearMonthDuration
 * --------------------*/
/*begin class op_divide_ymd_by_ymd*/
op_divide_ymd_by_ymd::op_divide_ymd_by_ymd (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_divide_ymd_by_ymd::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<DivideOperation>(loc,  argv[0], argv[1]);
}

/*end class op_divide_ymd_by_ymd*/

/*
 * 10.6.6 op:add-dayTimeDurations
 * --------------------*/
/*begin class op_dt_durations_add*/
op_dt_durations_add::op_dt_durations_add (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_dt_durations_add::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<AddOperation>(loc,  argv[0], argv[1]);
}

/*end class op_dt_durations_add*/

/*
 * 10.6.7 op:subtract-dayTimeDurations
 * --------------------*/
/*begin class op_dt_durations_subtract*/
op_dt_durations_subtract::op_dt_durations_subtract (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_dt_durations_subtract::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<SubtractOperation>(loc,  argv[0], argv[1]);
}

/*end class op_dt_durations_subtract*/

/*
 *  10.6.8 op:multiply-dayTimeDuration
 * --------------------*/
/*begin class op_dt_durations_multiply*/
op_dt_durations_multiply::op_dt_durations_multiply (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_dt_durations_multiply::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<MultiplyOperation>(loc,  argv[0], argv[1]);
}

/*end class op_dt_durations_multiply*/

/*
 *  10.6.9 op:divide-dayTimeDuration
 * --------------------*/
/*begin class op_dt_durations_divide*/
op_dt_durations_divide::op_dt_durations_divide (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_dt_durations_divide::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<DivideOperation>(loc,  argv[0], argv[1]);
}

/*end class op_dt_durations_divide*/


/*
 *  10.6.10 op:divide-dayTimeDuration-by-dayTimeDuration
 * --------------------*/
/*begin class op_divide_dtd_by_dtd*/
op_divide_dtd_by_dtd::op_divide_dtd_by_dtd (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_divide_dtd_by_dtd::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<DivideOperation>(loc,  argv[0], argv[1]);
}

/*end class op_divide_dtd_by_dtd*/

/*
 *  10.8.1 op:subtract-dateTimes
 * --------------------*/
/*begin class op_sub_dt*/
op_sub_dt::op_sub_dt (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_sub_dt::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<SubtractOperation>(loc,  argv[0], argv[1]);
}

/*end class op_sub_dt*/

/*
 *  10.8.2 op:subtract-dates
 * --------------------*/
/*begin class op_sub_d*/
op_sub_d::op_sub_d (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_sub_d::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<SubtractOperation>(loc,  argv[0], argv[1]);
}

/*end class op_sub_d*/

/*
 *  10.8.3 op:subtract-times
 * --------------------*/
/*begin class op_sub_t*/
op_sub_t::op_sub_t (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_sub_t::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<SubtractOperation>(loc,  argv[0], argv[1]);
}

/*end class op_sub_t*/

/*
 *  10.8.4 op:add-yearMonthDuration-to-dateTime
 * --------------------*/
/*begin class op_add_ymd_to_dt*/
op_add_ymd_to_dt::op_add_ymd_to_dt (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_add_ymd_to_dt::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<AddOperation>(loc,  argv[0], argv[1]);
}

/*end class op_add_ymd_to_dt*/

/*
 *  10.8.5 op:add-dayTimeDuration-to-dateTime
 * --------------------*/
/*begin class op_add_dtd_to_dt*/
op_add_dtd_to_dt::op_add_dtd_to_dt (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_add_dtd_to_dt::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<AddOperation>(loc,  argv[0], argv[1]);
}

/*end class op_add_dtd_to_dt*/


/*
 *  10.8.6 op:subtract-yearMonthDuration-from-dateTime
 * --------------------*/
/*begin class op_sub_ymd_from_dt*/
op_sub_ymd_from_dt::op_sub_ymd_from_dt (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_sub_ymd_from_dt::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<SubtractOperation>(loc,  argv[0], argv[1]);
}

/*end class op_sub_ymd_from_dt*/

/*
 *  10.8.7 op:subtract-dayTimeDuration-from-dateTime
 * --------------------*/
/*begin class op_sub_dtd_from_dt*/
op_sub_dtd_from_dt::op_sub_dtd_from_dt (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_sub_dtd_from_dt::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<SubtractOperation>(loc,  argv[0], argv[1]);
}

/*end class op_sub_dtd_from_dt*/

/*
 *  10.8.8 op:add-yearMonthDuration-to-date
 * --------------------*/
/*begin class op_add_ymd_to_d*/
op_add_ymd_to_d::op_add_ymd_to_d (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_add_ymd_to_d::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<AddOperation>(loc,  argv[0], argv[1]);
}

/*end class op_add_ymd_to_d*/

/*
 *  10.8.9 op:add-dayTimeDuration-to-date
 * --------------------*/
/*begin class op_add_dtd_to_d*/
op_add_dtd_to_d::op_add_dtd_to_d (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_add_dtd_to_d::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<AddOperation>(loc,  argv[0], argv[1]);
}

/*end class op_add_dtd_to_d*/


/*
 *  10.8.10 op:subtract-yearMonthDuration-from-date
 * --------------------*/
/*begin class op_sub_ymd_from_d*/
op_sub_ymd_from_d::op_sub_ymd_from_d (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_sub_ymd_from_d::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<SubtractOperation>(loc,  argv[0], argv[1]);
}

/*end class op_sub_ymd_from_d*/

/*
 *  10.8.11 op:subtract-dayTimeDuration-from-date
 * --------------------*/
/*begin class op_sub_dtd_from_d*/
op_sub_dtd_from_d::op_sub_dtd_from_d (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_sub_dtd_from_d::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<SubtractOperation>(loc,  argv[0], argv[1]);
}

/*end class op_sub_dtd_from_d*/

/*
 *  10.8.12 op:add-dayTimeDuration-to-time
 * --------------------*/
/*begin class op_add_dtd_to_t*/
op_add_dtd_to_t::op_add_dtd_to_t (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_add_dtd_to_t::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<AddOperation>(loc,  argv[0], argv[1]);
}

/*end class op_add_dtd_to_t*/

/*
 *  10.8.13 op:subtract-dayTimeDuration-from-time
 * --------------------*/
/*begin class op_sub_dtd_from_t*/
op_sub_dtd_from_t::op_sub_dtd_from_t (
    const signature& sig )
  :
    function ( sig )
{
}

PlanIter_t
op_sub_dtd_from_t::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new NumArithIterator<SubtractOperation>(loc,  argv[0], argv[1]);
}

/*end class op_sub_dtd_from_t*/


/*
 *  10.7.1 fn:adjust-dateTime-to-timezone
 * --------------------*/
/* begin class fn_adjust_dt_to_tz_1 */
fn_adjust_dt_to_tz_1::fn_adjust_dt_to_tz_1(const signature& sig )
  : function ( sig )
{
}

PlanIter_t fn_adjust_dt_to_tz_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnAdjustToTimeZoneIterator_1(loc, argv[0]);
}


/* end class fn_adjust_dt_to_tz_1 */

/* begin class fn_adjust_dt_to_tz_2 */
fn_adjust_dt_to_tz_2::fn_adjust_dt_to_tz_2(const signature& sig )
  : function ( sig )
{
}

PlanIter_t fn_adjust_dt_to_tz_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnAdjustToTimeZoneIterator_2(loc, argv[0], argv[1]);
}


/* end class fn_adjust_dt_to_tz_2 */

/*
 *  10.7.2 fn:adjust-date-to-timezone
 * --------------------*/
/* begin class fn_adjust_d_to_tz_1 */
fn_adjust_d_to_tz_1::fn_adjust_d_to_tz_1(const signature& sig )
  : function ( sig )
{
}

PlanIter_t fn_adjust_d_to_tz_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnAdjustToTimeZoneIterator_1(loc, argv[0]);
}


/* end class fn_adjust_d_to_tz_1 */

/* begin class fn_adjust_d_to_tz_2 */
fn_adjust_d_to_tz_2::fn_adjust_d_to_tz_2(const signature& sig )
  : function ( sig )
{
}

PlanIter_t fn_adjust_d_to_tz_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnAdjustToTimeZoneIterator_2(loc, argv[0], argv[1]);
}


/* end class fn_adjust_d_to_tz_2 */

/*
 *  10.7.3 fn:adjust-time-to-timezone
 * --------------------*/
/* begin class fn_adjust_t_to_tz_1 */
fn_adjust_t_to_tz_1::fn_adjust_t_to_tz_1(const signature& sig )
  : function ( sig )
{
}

PlanIter_t fn_adjust_t_to_tz_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnAdjustToTimeZoneIterator_1(loc, argv[0]);
}


/* end class fn_adjust_t_to_tz_1 */

/* begin class fn_adjust_t_to_tz_2 */
fn_adjust_t_to_tz_2::fn_adjust_t_to_tz_2(const signature& sig )
  : function ( sig )
{
}

PlanIter_t fn_adjust_t_to_tz_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnAdjustToTimeZoneIterator_2(loc, argv[0], argv[1]);
}


/* end class fn_adjust_t_to_tz_2 */

} // namespace zorba

