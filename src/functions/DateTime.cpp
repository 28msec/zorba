/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Nicolae Brinza, Sorin Nasoi
 */

#include "functions/DateTime.h"
#include "system/globalenv.h"
#include "runtime/dateTime/DurationsDatesTimes.h"
#include "runtime/numerics/NumericsImpl.h"

namespace xqp
{

fn_datetime_ctor::fn_datetime_ctor (
    const signature& sig )
    :
    function ( sig )
{
}

PlanIter_t fn_datetime_ctor::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnDateTimeConstructorIterator(loc, argv[0], argv[1]);
}

bool fn_datetime_ctor::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return true;
}

xqtref_t fn_datetime_ctor::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION;
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
fn_years_from_duration::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnYearsFromDurationIterator(loc, argv);
}

bool
fn_years_from_duration::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_years_from_duration::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_QUESTION;
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
fn_months_from_duration::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnMonthsFromDurationIterator(loc, argv);
}

bool
fn_months_from_duration::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_months_from_duration::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_QUESTION;
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
fn_days_from_duration::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnDaysFromDurationIterator(loc, argv);
}

bool
fn_days_from_duration::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_days_from_duration::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_QUESTION;
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
fn_hours_from_duration::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnHoursFromDurationIterator(loc, argv);
}

bool
fn_hours_from_duration::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_hours_from_duration::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_QUESTION;
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
fn_minutes_from_duration::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnMinutesFromDurationIterator(loc, argv);
}

bool
fn_minutes_from_duration::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_minutes_from_duration::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_QUESTION;
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
fn_seconds_from_duration::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnSecondsFromDurationIterator(loc, argv);
}

bool
fn_seconds_from_duration::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_seconds_from_duration::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_QUESTION;
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
fn_year_from_datetime::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnYearFromDatetimeIterator(loc, argv);
}

bool
fn_year_from_datetime::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_year_from_datetime::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION;
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
fn_month_from_datetime::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnMonthFromDatetimeIterator(loc, argv);
}

bool
fn_month_from_datetime::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_month_from_datetime::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION;
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
fn_day_from_datetime::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnDayFromDatetimeIterator(loc, argv);
}

bool
fn_day_from_datetime::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_day_from_datetime::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION;
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
fn_hours_from_datetime::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnHoursFromDatetimeIterator(loc, argv);
}

bool
fn_hours_from_datetime::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_hours_from_datetime::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION;
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
fn_minutes_from_datetime::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnMinutesFromDatetimeIterator(loc, argv);
}

bool
fn_minutes_from_datetime::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_minutes_from_datetime::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION;
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
fn_seconds_from_datetime::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnSecondsFromDatetimeIterator(loc, argv);
}

bool
fn_seconds_from_datetime::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_seconds_from_datetime::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION;
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
fn_timezone_from_datetime::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnTimezoneFromDatetimeIterator(loc, argv);
}

bool
fn_timezone_from_datetime::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_timezone_from_datetime::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION;
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
fn_year_from_date::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnYearFromDateIterator(loc, argv);
}

bool
fn_year_from_date::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_year_from_date::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATE_TYPE_QUESTION;
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
fn_month_from_date::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnMonthFromDateIterator(loc, argv);
}

bool
fn_month_from_date::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_month_from_date::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATE_TYPE_QUESTION;
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
fn_day_from_date::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnDayFromDateIterator(loc, argv);
}

bool
fn_day_from_date::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_day_from_date::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATE_TYPE_QUESTION;
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
fn_timezone_from_date::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnTimezoneFromDateIterator(loc, argv);
}

bool
fn_timezone_from_date::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_timezone_from_date::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATE_TYPE_QUESTION;
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
fn_hours_from_time::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnHoursFromTimeIterator(loc, argv);
}

bool
fn_hours_from_time::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_hours_from_time::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.TIME_TYPE_QUESTION;
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
fn_minutes_from_time::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnMinutesFromTimeIterator(loc, argv);
}

bool
fn_minutes_from_time::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_minutes_from_time::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.TIME_TYPE_QUESTION;
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
fn_seconds_from_time::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnSecondsFromTimeIterator(loc, argv);
}

bool
fn_seconds_from_time::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_seconds_from_time::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.TIME_TYPE_QUESTION;
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
fn_timezone_from_time::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new FnTimezoneFromTimeIterator(loc, argv);
}

bool
fn_timezone_from_time::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

xqtref_t
fn_timezone_from_time::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.TIME_TYPE_QUESTION;
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
op_ym_durations_add::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new ArithmeticIteratorDurationDateTime<AddOperationsDuration>(loc, argv);
}

bool
op_ym_durations_add::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 2);
}

//TODO change the type to YM_DURATION_TYPE_ONE
xqtref_t
op_ym_durations_add::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE;
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
op_ym_durations_subtract::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new ArithmeticIteratorDurationDateTime<SubtractOperationsDuration>(loc, argv);
}

bool
op_ym_durations_subtract::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 2);
}

//TODO change the type to YM_DURATION_TYPE_ONE
xqtref_t
op_ym_durations_subtract::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_ONE;
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
op_ym_durations_multiply::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new ArithmeticIteratorDurationDateTime<MultiplyOperationsDuration>(loc, argv);
}

bool
op_ym_durations_multiply::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 2);
}

//TODO change the type to YM_DURATION_TYPE_ONE
xqtref_t
op_ym_durations_multiply::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_ONE;
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
op_ym_durations_divide::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new ArithmeticIteratorDurationDateTime<DivideOperationsDurationByDouble>(loc, argv);
}

bool
op_ym_durations_divide::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 2);
}

//TODO change the type to YM_DURATION_TYPE_ONE
xqtref_t
op_ym_durations_divide::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_ONE;
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
op_divide_ymd_by_ymd::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new ArithmeticIteratorDurationDateTime<DivideOperationsDurationByDuration>(loc, argv);
}

bool
op_divide_ymd_by_ymd::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 2);
}

//TODO change the type to YM_DURATION_TYPE_ONE
xqtref_t
op_divide_ymd_by_ymd::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_ONE;
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
op_dt_durations_add::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new ArithmeticIteratorDurationDateTime<AddOperationsDuration>(loc, argv);
}

bool
op_dt_durations_add::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 2);
}

xqtref_t
op_dt_durations_add::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE;
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
op_dt_durations_subtract::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new ArithmeticIteratorDurationDateTime<SubtractOperationsDuration>(loc, argv);
}

bool
op_dt_durations_subtract::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 2);
}

//TODO change the type to DT_DURATION_TYPE_ONE
xqtref_t
op_dt_durations_subtract::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_ONE;
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
op_dt_durations_multiply::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new ArithmeticIteratorDurationDateTime<MultiplyOperationsDuration>(loc, argv);
}

bool
op_dt_durations_multiply::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 2);
}

//TODO change the type to DT_DURATION_TYPE_ONE
xqtref_t
op_dt_durations_multiply::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_ONE;
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
op_dt_durations_divide::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new ArithmeticIteratorDurationDateTime<DivideOperationsDurationByDouble>(loc, argv);
}

bool
op_dt_durations_divide::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 2);
}

//TODO change the type to DT_DURATION_TYPE_ONE
xqtref_t
op_dt_durations_divide::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_ONE;
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
op_divide_dtd_by_dtd::operator() (
    const yy::location& loc,
    std::vector<PlanIter_t>& argv ) const
{
  return new ArithmeticIteratorDurationDateTime<DivideOperationsDurationByDuration>(loc, argv);
}

bool
op_divide_dtd_by_dtd::validate_args (
    std::vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 2);
}

//TODO change the type to DT_DURATION_TYPE_ONE
xqtref_t
op_divide_dtd_by_dtd::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DURATION_TYPE_ONE;
}
/*end class op_divide_dtd_by_dtd*/

} // namespace xqp

