/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Nicolae Brinza, Sorin Nasoi
 */

#include "functions/DateTime.h"
#include "system/globalenv.h"
#include "runtime/dateTime/DurationsDatesTimes.h"

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
    vector<PlanIter_t>& argv ) const
{
  return new FnDateTimeConstructorIterator(loc, argv[0], argv[1]);
}

bool fn_datetime_ctor::validate_args (
    vector<PlanIter_t>& argv ) const
{
  return true;
}

TypeSystem::xqtref_t fn_datetime_ctor::type_check (
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
    vector<PlanIter_t>& argv ) const
{
  return new FnYearsFromDurationIterator(loc, argv[0]);
}

bool
fn_years_from_duration::validate_args (
    vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

TypeSystem::xqtref_t
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
    vector<PlanIter_t>& argv ) const
{
  return new FnMonthsFromDurationIterator(loc, argv[0]);
}

bool
fn_months_from_duration::validate_args (
    vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

TypeSystem::xqtref_t
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
    vector<PlanIter_t>& argv ) const
{
  return new FnDaysFromDurationIterator(loc, argv[0]);
}

bool
fn_days_from_duration::validate_args (
    vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

TypeSystem::xqtref_t
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
    vector<PlanIter_t>& argv ) const
{
  return new FnHoursFromDurationIterator(loc, argv[0]);
}

bool
fn_hours_from_duration::validate_args (
    vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

TypeSystem::xqtref_t
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
    vector<PlanIter_t>& argv ) const
{
  return new FnMinutesFromDurationIterator(loc, argv[0]);
}

bool
fn_minutes_from_duration::validate_args (
    vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

TypeSystem::xqtref_t
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
    vector<PlanIter_t>& argv ) const
{
  return new FnSecondsFromDurationIterator(loc, argv[0]);
}

bool
fn_seconds_from_duration::validate_args (
    vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

TypeSystem::xqtref_t
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
    vector<PlanIter_t>& argv ) const
{
  return new FnYearFromDatetimeIterator(loc, argv[0]);
}

bool
fn_year_from_datetime::validate_args (
    vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

TypeSystem::xqtref_t
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
    vector<PlanIter_t>& argv ) const
{
  return new FnMonthFromDatetimeIterator(loc, argv[0]);
}

bool
fn_month_from_datetime::validate_args (
    vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

TypeSystem::xqtref_t
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
    vector<PlanIter_t>& argv ) const
{
  return new FnDayFromDatetimeIterator(loc, argv[0]);
}

bool
fn_day_from_datetime::validate_args (
    vector<PlanIter_t>& argv ) const
{
  return (argv.size() == 1);
}

TypeSystem::xqtref_t
fn_day_from_datetime::type_check (
    signature& sig ) const
{
  return GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION;
}
/*end class fn_day_from_datetime*/


} // namespace xqp

