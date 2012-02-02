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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************


#include "stdafx.h"
#include "runtime/durations_dates_times/durations_dates_times.h"
#include "functions/func_durations_dates_times.h"


namespace zorba{



PlanIter_t fn_years_from_duration::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new YearsFromDurationIterator(sctx, loc, argv);
}

PlanIter_t fn_months_from_duration::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new MonthsFromDurationIterator(sctx, loc, argv);
}

PlanIter_t fn_days_from_duration::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DaysFromDurationIterator(sctx, loc, argv);
}

PlanIter_t fn_hours_from_duration::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new HoursFromDurationIterator(sctx, loc, argv);
}

PlanIter_t fn_minutes_from_duration::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new MinutesFromDurationIterator(sctx, loc, argv);
}

PlanIter_t fn_seconds_from_duration::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new SecondsFromDurationIterator(sctx, loc, argv);
}

PlanIter_t fn_year_from_dateTime::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new YearFromDatetimeIterator(sctx, loc, argv);
}

PlanIter_t fn_month_from_dateTime::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new MonthFromDatetimeIterator(sctx, loc, argv);
}

PlanIter_t fn_day_from_dateTime::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DayFromDatetimeIterator(sctx, loc, argv);
}

PlanIter_t fn_hours_from_dateTime::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new HoursFromDatetimeIterator(sctx, loc, argv);
}

PlanIter_t fn_minutes_from_dateTime::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new MinutesFromDatetimeIterator(sctx, loc, argv);
}

PlanIter_t fn_seconds_from_dateTime::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new SecondsFromDatetimeIterator(sctx, loc, argv);
}

PlanIter_t fn_timezone_from_dateTime::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new TimezoneFromDatetimeIterator(sctx, loc, argv);
}

PlanIter_t fn_year_from_date::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new YearFromDateIterator(sctx, loc, argv);
}

PlanIter_t fn_month_from_date::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new MonthFromDateIterator(sctx, loc, argv);
}

PlanIter_t fn_day_from_date::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DayFromDateIterator(sctx, loc, argv);
}

PlanIter_t fn_timezone_from_date::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new TimezoneFromDateIterator(sctx, loc, argv);
}

PlanIter_t fn_hours_from_time::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new HoursFromTimeIterator(sctx, loc, argv);
}

PlanIter_t fn_minutes_from_time::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new MinutesFromTimeIterator(sctx, loc, argv);
}

PlanIter_t fn_seconds_from_time::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new SecondsFromTimeIterator(sctx, loc, argv);
}

PlanIter_t fn_timezone_from_time::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new TimezoneFromTimeIterator(sctx, loc, argv);
}

void populate_context_durations_dates_times(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, fn_years_from_duration,
        (createQName("http://www.w3.org/2005/xpath-functions","","years-from-duration"), 
        GENV_TYPESYSTEM.DURATION_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_YEARS_FROM_DURATION_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_months_from_duration,
        (createQName("http://www.w3.org/2005/xpath-functions","","months-from-duration"), 
        GENV_TYPESYSTEM.DURATION_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_MONTHS_FROM_DURATION_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_days_from_duration,
        (createQName("http://www.w3.org/2005/xpath-functions","","days-from-duration"), 
        GENV_TYPESYSTEM.DURATION_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_DAYS_FROM_DURATION_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_hours_from_duration,
        (createQName("http://www.w3.org/2005/xpath-functions","","hours-from-duration"), 
        GENV_TYPESYSTEM.DURATION_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_HOURS_FROM_DURATION_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_minutes_from_duration,
        (createQName("http://www.w3.org/2005/xpath-functions","","minutes-from-duration"), 
        GENV_TYPESYSTEM.DURATION_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_MINUTES_FROM_DURATION_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_seconds_from_duration,
        (createQName("http://www.w3.org/2005/xpath-functions","","seconds-from-duration"), 
        GENV_TYPESYSTEM.DURATION_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DECIMAL_TYPE_QUESTION),
        FunctionConsts::FN_SECONDS_FROM_DURATION_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_year_from_dateTime,
        (createQName("http://www.w3.org/2005/xpath-functions","","year-from-dateTime"), 
        GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_YEAR_FROM_DATETIME_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_month_from_dateTime,
        (createQName("http://www.w3.org/2005/xpath-functions","","month-from-dateTime"), 
        GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_MONTH_FROM_DATETIME_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_day_from_dateTime,
        (createQName("http://www.w3.org/2005/xpath-functions","","day-from-dateTime"), 
        GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_DAY_FROM_DATETIME_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_hours_from_dateTime,
        (createQName("http://www.w3.org/2005/xpath-functions","","hours-from-dateTime"), 
        GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_HOURS_FROM_DATETIME_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_minutes_from_dateTime,
        (createQName("http://www.w3.org/2005/xpath-functions","","minutes-from-dateTime"), 
        GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_MINUTES_FROM_DATETIME_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_seconds_from_dateTime,
        (createQName("http://www.w3.org/2005/xpath-functions","","seconds-from-dateTime"), 
        GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DECIMAL_TYPE_QUESTION),
        FunctionConsts::FN_SECONDS_FROM_DATETIME_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_timezone_from_dateTime,
        (createQName("http://www.w3.org/2005/xpath-functions","","timezone-from-dateTime"), 
        GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION),
        FunctionConsts::FN_TIMEZONE_FROM_DATETIME_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_year_from_date,
        (createQName("http://www.w3.org/2005/xpath-functions","","year-from-date"), 
        GENV_TYPESYSTEM.DATE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_YEAR_FROM_DATE_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_month_from_date,
        (createQName("http://www.w3.org/2005/xpath-functions","","month-from-date"), 
        GENV_TYPESYSTEM.DATE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_MONTH_FROM_DATE_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_day_from_date,
        (createQName("http://www.w3.org/2005/xpath-functions","","day-from-date"), 
        GENV_TYPESYSTEM.DATE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_DAY_FROM_DATE_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_timezone_from_date,
        (createQName("http://www.w3.org/2005/xpath-functions","","timezone-from-date"), 
        GENV_TYPESYSTEM.DATE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION),
        FunctionConsts::FN_TIMEZONE_FROM_DATE_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_hours_from_time,
        (createQName("http://www.w3.org/2005/xpath-functions","","hours-from-time"), 
        GENV_TYPESYSTEM.TIME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_HOURS_FROM_TIME_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_minutes_from_time,
        (createQName("http://www.w3.org/2005/xpath-functions","","minutes-from-time"), 
        GENV_TYPESYSTEM.TIME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_MINUTES_FROM_TIME_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_seconds_from_time,
        (createQName("http://www.w3.org/2005/xpath-functions","","seconds-from-time"), 
        GENV_TYPESYSTEM.TIME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DECIMAL_TYPE_QUESTION),
        FunctionConsts::FN_SECONDS_FROM_TIME_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_timezone_from_time,
        (createQName("http://www.w3.org/2005/xpath-functions","","timezone-from-time"), 
        GENV_TYPESYSTEM.TIME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION),
        FunctionConsts::FN_TIMEZONE_FROM_TIME_1);

  }

}


}



