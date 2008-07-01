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

#include "functions/DateTime.h"
#include "functions/function_impl.h"

#include "system/globalenv.h"
#include "runtime/dateTime/DurationsDatesTimes.h"
#include "runtime/numerics/NumericsImpl.h"

namespace zorba
{

  class fn_datetime_ctor : public function
  {
  public:
    fn_datetime_ctor(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*______________________________________________________________________
   *
   * 10.5 Component Extraction Functions on Durations, Dates and Times
   *_______________________________________________________________________*/


  /*
   * 10.5.1 fn:years-from-duration
   * --------------------*/
  /*begin class fn_years_from_duration*/


  typedef function_impl<FnYearsFromDurationIterator> fn_years_from_duration;
  /*end class fn_years_from_duration*/

  /*
   * 10.5.2 fn:months-from-duration
   * --------------------*/
  /*begin class fn_months_from_duration*/


  typedef function_impl<FnMonthsFromDurationIterator> fn_months_from_duration;
  /*end class fn_months_from_duration*/

  /*
   * 10.5.3 fn:days-from-duration
   * --------------------*/
  /*begin class fn_days_from_duration*/


  typedef function_impl<FnDaysFromDurationIterator> fn_days_from_duration;
  /*end class fn_days_from_duration*/

  /*
   * 10.5.4 fn:hours-from-duration
   * --------------------*/
  /*begin class fn_hours_from_duration*/


  typedef function_impl<FnHoursFromDurationIterator> fn_hours_from_duration;
  /*end class fn_hours_from_duration*/

  /*
   * 10.5.5 fn:minutes-from-duration
   * --------------------*/
  /*begin class fn_minutes_from_duration*/


  typedef function_impl<FnMinutesFromDurationIterator> fn_minutes_from_duration;
  /*end class fn_minutes_from_duration*/

  /*
   * 10.5.6 fn:seconds-from-duration
   * --------------------*/
  /*begin class fn_seconds_from_duration*/


  typedef function_impl<FnSecondsFromDurationIterator> fn_seconds_from_duration;
  /*end class fn_seconds_from_duration*/

  /*
   * 10.5.7 fn:year-from-dateTime
   * --------------------*/
  /*begin class fn_year_from_datetime*/


  typedef function_impl<FnYearFromDatetimeIterator> fn_year_from_datetime;
  /*end class fn_seconds_from_duration*/

  /*
   * 10.5.8 fn:month-from-dateTime
   * --------------------*/
  /*begin class fn_month_from_datetime*/


  typedef function_impl<FnMonthFromDatetimeIterator> fn_month_from_datetime;
  /*end class fn_month_from_datetime*/

  /*
   * 10.5.9 fn:day-from-dateTime
   * --------------------*/
  /*begin class fn_day_from_datetime*/


  typedef function_impl<FnDayFromDatetimeIterator> fn_day_from_datetime;
  /*end class fn_day_from_datetime*/

  /*
   * 10.5.10 fn:hours-from-dateTime
   * --------------------*/
  /*begin class fn_hours_from_datetime*/


  typedef function_impl<FnHoursFromDatetimeIterator> fn_hours_from_datetime;
  /*end class fn_hours_from_datetime*/

  /*
   * 10.5.11 fn:minutes-from-dateTime
   * --------------------*/
  /*begin class fn_minutes_from_datetime*/


  typedef function_impl<FnMinutesFromDatetimeIterator> fn_minutes_from_datetime;
  /*end class fn_minutes_from_datetime*/

  /*
   * 10.5.12 fn:seconds-from-dateTime
   * --------------------*/
  /*begin class fn_seconds_from_datetime*/


  typedef function_impl<FnSecondsFromDatetimeIterator> fn_seconds_from_datetime;
  /*end class fn_seconds_from_datetime*/


  /*
   * 10.5.13 fn:timezone-from-dateTime
   * --------------------*/
  /*begin class fn_timezone_from_datetime*/


  typedef function_impl<FnTimezoneFromDatetimeIterator> fn_timezone_from_datetime;
  /*end class fn_timezone_from_datetime*/

  /*
   * 10.5.14 fn:year-from-date
   * --------------------*/
  /*begin class fn_year_from_date*/


  typedef function_impl<FnYearFromDateIterator> fn_year_from_date;
  /*end class fn_year_from_date*/

  /*
   * 10.5.15 fn:month-from-date
   * --------------------*/
  /*begin class fn_month_from_date*/


  typedef function_impl<FnMonthFromDateIterator> fn_month_from_date;
  /*end class fn_month_from_date*/


  /*
   * 10.5.16 fn:day-from-date
   * --------------------*/
  /*begin class fn_day_from_date*/


  typedef function_impl<FnDayFromDateIterator> fn_day_from_date;
  /*end class fn_day_from_date*/

  /*
   * 10.5.17 fn:timezone-from-date
   * --------------------*/
  /*begin class fn_timezone_from_date*/


  typedef function_impl<FnTimezoneFromDateIterator> fn_timezone_from_date;
  /*end class fn_timezone_from_date*/

  /*
   * 10.5.18 fn:hours-from-time
   * --------------------*/
  /*begin class fn_hours_from_time*/


  typedef function_impl<FnHoursFromTimeIterator> fn_hours_from_time;
  /*end class fn_hours_from_time*/

  /*
   * 10.5.19 fn:minutes-from-time
   * --------------------*/
  /*begin class fn_minutes_from_time*/


  typedef function_impl<FnMinutesFromTimeIterator> fn_minutes_from_time;
  /*end class fn_minutes_from_time*/

  /*
   * 10.5.20 fn:seconds-from-time
   * --------------------*/
  /*begin class fn_seconds_from_time*/


  typedef function_impl<FnSecondsFromTimeIterator> fn_seconds_from_time;
  /*end class fn_seconds_from_time*/


  /*
   * 10.5.21 fn:timezone-from-time
   * --------------------*/
  /*begin class fn_timezone_from_time*/


  typedef function_impl<FnTimezoneFromTimeIterator> fn_timezone_from_time;
  /*end class fn_timezone_from_time*/
 

  /*
   * 10.6.1 op:add-yearMonthDurations
   *-----------------------*/
  class op_ym_durations_add : public function
  {
  public:
    op_ym_durations_add(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.6.2 op:subtract-yearMonthDurations
   *-----------------------*/
  class op_ym_durations_subtract : public function
  {
  public:
    op_ym_durations_subtract(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.6.3 op:multiply-yearMonthDuration
   *-----------------------*/
  class op_ym_durations_multiply : public function
  {
  public:
    op_ym_durations_multiply(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.6.4 op:divide-yearMonthDuration
   *-----------------------*/
  class op_ym_durations_divide : public function
  {
  public:
    op_ym_durations_divide(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.6.5 op:divide-yearMonthDuration-by-yearMonthDuration
   *-----------------------*/
  class op_divide_ymd_by_ymd : public function
  {
  public:
    op_divide_ymd_by_ymd(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
  /*
   * 10.6.6 op:add-dayTimeDurations
   *-----------------------*/
  class op_dt_durations_add : public function
  {
  public:
    op_dt_durations_add(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.6.7 op:subtract-dayTimeDurations
   *-----------------------*/
  class op_dt_durations_subtract : public function
  {
  public:
    op_dt_durations_subtract(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.6.8 op:multiply-dayTimeDuration
   *-----------------------*/
  class op_dt_durations_multiply : public function
  {
  public:
    op_dt_durations_multiply(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.6.9 op:divide-dayTimeDuration
   *-----------------------*/
  class op_dt_durations_divide : public function
  {
  public:
    op_dt_durations_divide(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.6.10 op:divide-dayTimeDuration-by-dayTimeDuration
   *-----------------------*/
  class op_divide_dtd_by_dtd : public function
  {
  public:
    op_divide_dtd_by_dtd(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.8.1 op:subtract-dateTimes
   *-----------------------*/
  class op_sub_dt : public function
  {
  public:
    op_sub_dt(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.8.2 op:subtract-dates
   *-----------------------*/
  class op_sub_d : public function
  {
  public:
    op_sub_d(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.8.3 op:subtract-times
   *-----------------------*/
  class op_sub_t : public function
  {
  public:
    op_sub_t(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
  /*
   * 10.8.4 op:add-yearMonthDuration-to-dateTime
   *-----------------------*/
  class op_add_ymd_to_dt : public function
  {
  public:
    op_add_ymd_to_dt(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.8.5 op:add-dayTimeDuration-to-dateTime
   *-----------------------*/
  class op_add_dtd_to_dt : public function
  {
  public:
    op_add_dtd_to_dt(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.8.6 op:subtract-yearMonthDuration-from-dateTime
   *-----------------------*/
  class op_sub_ymd_from_dt : public function
  {
  public:
    op_sub_ymd_from_dt(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.8.7 op:subtract-dayTimeDuration-from-dateTime
   *-----------------------*/
  class op_sub_dtd_from_dt : public function
  {
  public:
    op_sub_dtd_from_dt(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
  /*
   * 10.8.8 op:add-yearMonthDuration-to-date
   *-----------------------*/
  class op_add_ymd_to_d : public function
  {
  public:
    op_add_ymd_to_d(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.8.9 op:add-dayTimeDuration-to-date
   *-----------------------*/
  class op_add_dtd_to_d : public function
  {
  public:
    op_add_dtd_to_d(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  
  /*
   * 10.8.10 op:subtract-yearMonthDuration-from-date
   *-----------------------*/
  class op_sub_ymd_from_d : public function
  {
  public:
    op_sub_ymd_from_d(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.8.11 op:subtract-dayTimeDuration-from-date
   *-----------------------*/
  class op_sub_dtd_from_d : public function
  {
  public:
    op_sub_dtd_from_d(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.8.12 op:add-dayTimeDuration-to-time
   *-----------------------*/
  class op_add_dtd_to_t : public function
  {
  public:
    op_add_dtd_to_t(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.8.13 op:subtract-dayTimeDuration-from-time
   *-----------------------*/
  class op_sub_dtd_from_t : public function
  {
  public:
    op_sub_dtd_from_t(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.7.1 fn:adjust-dateTime-to-timezone
   *-----------------------*/
  class fn_adjust_dt_to_tz_1 : public function
  {
  public:
    bool requires_dyn_ctx () const { return true; }
    fn_adjust_dt_to_tz_1(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_adjust_dt_to_tz_2 : public function
  {
  public:
    fn_adjust_dt_to_tz_2(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.7.2 fn:adjust-date-to-timezone
   *-----------------------*/
  class fn_adjust_d_to_tz_1 : public function
  {
  public:
    fn_adjust_d_to_tz_1(const signature& sig) : function (sig) {}
    bool requires_dyn_ctx () const { return true; }
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_adjust_d_to_tz_2 : public function
  {
  public:
    fn_adjust_d_to_tz_2(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 10.7.3 fn:adjust-time-to-timezone
   *-----------------------*/
  class fn_adjust_t_to_tz_1 : public function
  {
  public:
    fn_adjust_t_to_tz_1(const signature& sig) : function (sig) {}
    bool requires_dyn_ctx () const { return true; }
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_adjust_t_to_tz_2 : public function
  {
  public:
    fn_adjust_t_to_tz_2(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


PlanIter_t fn_datetime_ctor::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnDateTimeConstructorIterator(loc, argv[0], argv[1]);
}


/*
 * 10.6.1 op:add-yearMonthDurations
 * --------------------*/
/*begin class op_ym_durations_add*/


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

PlanIter_t fn_adjust_dt_to_tz_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnAdjustToTimeZoneIterator_1(loc, argv[0]);
}


/* end class fn_adjust_dt_to_tz_1 */

/* begin class fn_adjust_dt_to_tz_2 */

PlanIter_t fn_adjust_dt_to_tz_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnAdjustToTimeZoneIterator_2(loc, argv[0], argv[1]);
}


/* end class fn_adjust_dt_to_tz_2 */

/*
 *  10.7.2 fn:adjust-date-to-timezone
 * --------------------*/
/* begin class fn_adjust_d_to_tz_1 */

PlanIter_t fn_adjust_d_to_tz_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnAdjustToTimeZoneIterator_1(loc, argv[0]);
}


/* end class fn_adjust_d_to_tz_1 */

/* begin class fn_adjust_d_to_tz_2 */

PlanIter_t fn_adjust_d_to_tz_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnAdjustToTimeZoneIterator_2(loc, argv[0], argv[1]);
}


/* end class fn_adjust_d_to_tz_2 */

/*
 *  10.7.3 fn:adjust-time-to-timezone
 * --------------------*/
/* begin class fn_adjust_t_to_tz_1 */

PlanIter_t fn_adjust_t_to_tz_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnAdjustToTimeZoneIterator_1(loc, argv[0]);
}


/* end class fn_adjust_t_to_tz_1 */

/* begin class fn_adjust_t_to_tz_2 */

PlanIter_t fn_adjust_t_to_tz_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
{
  return new FnAdjustToTimeZoneIterator_2(loc, argv[0], argv[1]);
}



/* end class fn_adjust_t_to_tz_2 */


void populateContext_Datetime(static_context *sctx)
{
// begin date time
DECL(sctx, fn_datetime_ctor,
     (createQName(XQUERY_OP_NS,"fn", "dateTime"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION));

DECL(sctx, fn_years_from_duration,
     (createQName(XQUERY_FN_NS,"fn", "years-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_months_from_duration,
     (createQName(XQUERY_FN_NS,"fn", "months-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_days_from_duration,
     (createQName(XQUERY_FN_NS,"fn", "days-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_hours_from_duration,
     (createQName(XQUERY_FN_NS,"fn", "hours-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_minutes_from_duration,
     (createQName(XQUERY_FN_NS,"fn", "minutes-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_seconds_from_duration,
     (createQName(XQUERY_FN_NS,"fn", "seconds-from-duration"),
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.DECIMAL_TYPE_QUESTION));

DECL(sctx, fn_year_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "year-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_month_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "month-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_day_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "day-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_hours_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "hours-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_minutes_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "minutes-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_seconds_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "seconds-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DECIMAL_TYPE_QUESTION));

DECL(sctx, fn_timezone_from_datetime,
     (createQName(XQUERY_FN_NS,"fn", "timezone-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

DECL(sctx, fn_year_from_date,
     (createQName(XQUERY_FN_NS,"fn", "year-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_month_from_date,
     (createQName(XQUERY_FN_NS,"fn", "month-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_day_from_date,
     (createQName(XQUERY_FN_NS,"fn", "day-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_timezone_from_date,
     (createQName(XQUERY_FN_NS,"fn", "timezone-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

DECL(sctx, fn_hours_from_time,
     (createQName(XQUERY_FN_NS,"fn", "hours-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_minutes_from_time,
     (createQName(XQUERY_FN_NS,"fn", "minutes-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_seconds_from_time,
     (createQName(XQUERY_FN_NS,"fn", "seconds-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DECIMAL_TYPE_QUESTION));

DECL(sctx, fn_timezone_from_time,
     (createQName(XQUERY_FN_NS,"fn", "timezone-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

DECL(sctx, op_ym_durations_add,
     (createQName (XQUERY_FN_NS,"fn", "add-yearMonthDurations"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE));

DECL(sctx, op_dt_durations_add,
     (createQName (XQUERY_FN_NS,"fn", "add-dayTimeDurations"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(sctx, op_ym_durations_subtract,
     (createQName (XQUERY_FN_NS,"fn", "subtract-yearMonthDurations"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE));

DECL(sctx, op_dt_durations_subtract,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDurations"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(sctx, op_ym_durations_multiply,
     (createQName (XQUERY_FN_NS,"fn", "multiply-yearMonthDuration"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE));

DECL(sctx, op_dt_durations_multiply,
     (createQName (XQUERY_FN_NS,"fn", "multiply-dayTimeDuration"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(sctx, op_ym_durations_divide,
     (createQName (XQUERY_FN_NS,"fn", "divide-yearMonthDuration"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE));

DECL(sctx, op_dt_durations_divide,
     (createQName (XQUERY_FN_NS,"fn", "divide-dayTimeDuration"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(sctx, op_divide_ymd_by_ymd,
     (createQName (XQUERY_FN_NS,"fn", "divide-yearMonthDuration-by-yearMonthDuration"),
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));

DECL(sctx, op_divide_dtd_by_dtd,
     (createQName (XQUERY_FN_NS,"fn", "divide-dayTimeDuration-by-dayTimeDuration"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));

 //TODO change the returned type to DT_DURATION_TYPE_QUESTION
DECL(sctx, op_sub_dt,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dateTimes"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

 //TODO change the returned type to DT_DURATION_TYPE_QUESTION
DECL(sctx, op_sub_d,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dates"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

 //TODO change the returned type to DT_DURATION_TYPE_QUESTION
DECL(sctx, op_sub_t,
     (createQName (XQUERY_FN_NS,"fn", "subtract-times"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_QUESTION));

 //TODO change the type of the second arg to YM_DURATION_TYPE_ONE
DECL(sctx, op_add_ymd_to_dt,
     (createQName (XQUERY_FN_NS,"fn", "add-yearMonthDuration-to-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(sctx, op_add_dtd_to_dt,
     (createQName (XQUERY_FN_NS,"fn", "add-dayTimeDuration-to-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

 //TODO change the type of the second arg to YM_DURATION_TYPE_ONE
DECL(sctx, op_sub_ymd_from_dt,
     (createQName (XQUERY_FN_NS,"fn", "subtract-yearMonthDuration-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(sctx, op_sub_dtd_from_dt,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDuration-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

 //TODO change the type of the second arg to YM_DURATION_TYPE_ONE
DECL(sctx, op_add_ymd_to_d,
     (createQName (XQUERY_FN_NS,"fn", "add-yearMonthDuration-to-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(sctx, op_add_dtd_to_d,
     (createQName (XQUERY_FN_NS,"fn", "add-dayTimeDuration-to-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

 //TODO change the type of the second arg to YM_DURATION_TYPE_ONE
DECL(sctx, op_sub_ymd_from_d,
     (createQName (XQUERY_FN_NS,"fn", "subtract-yearMonthDuration-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(sctx, op_sub_dtd_from_d,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDuration-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(sctx, op_add_dtd_to_t,
     (createQName (XQUERY_FN_NS,"fn", "add-dayTimeDuration-to-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.TIME_TYPE_ONE));

 //TODO change the type of the second arg to DT_DURATION_TYPE_ONE
DECL(sctx, op_sub_dtd_from_t,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDuration-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.TIME_TYPE_ONE));

DECL(sctx, fn_adjust_dt_to_tz_1,
     (createQName (XQUERY_FN_NS,"fn", "adjust-dateTime-to-timezone"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION));

DECL(sctx, fn_adjust_dt_to_tz_2,
     (createQName (XQUERY_FN_NS,"fn", "adjust-dateTime-to-timezone"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION));

DECL(sctx, fn_adjust_d_to_tz_1,
     (createQName (XQUERY_FN_NS,"fn", "adjust-date-to-timezone"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION));

DECL(sctx, fn_adjust_d_to_tz_2,
     (createQName (XQUERY_FN_NS,"fn", "adjust-date-to-timezone"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION));

DECL(sctx, fn_adjust_t_to_tz_1,
     (createQName (XQUERY_FN_NS,"fn", "adjust-time-to-timezone"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION));

DECL(sctx, fn_adjust_t_to_tz_2,
     (createQName (XQUERY_FN_NS,"fn", "adjust-time-to-timezone"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION,
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION));
  
// end date time

}

} // namespace zorba

