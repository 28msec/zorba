/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Nicolae Brinza, Sorin Nasoi
 */

#ifndef XQP_DATETIME_H
#define XQP_DATETIME_H

#include "functions/function.h"

namespace xqp
{

class fn_datetime_ctor : public function
{
  public:
    fn_datetime_ctor(const signature&);
    virtual ~fn_datetime_ctor() {};

  public:
    PlanIter_t operator()(const yy::location& loc,std::vector<PlanIter_t>&) const;
    xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

  /*______________________________________________________________________
  *
  * 10.5 Component Extraction Functions on Durations, Dates and Times
  *_______________________________________________________________________*/
 
/*
 * 10.5.1 fn:years-from-duration
 *-----------------------*/
  class fn_years_from_duration : public function
  {
    public:
      fn_years_from_duration(const signature&);
      ~fn_years_from_duration() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.2 fn:months-from-duration
 *-----------------------*/
  class fn_months_from_duration : public function
  {
    public:
      fn_months_from_duration(const signature&);
      ~fn_months_from_duration() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.3 fn:days-from-duration
 *-----------------------*/
  class fn_days_from_duration : public function
  {
    public:
      fn_days_from_duration(const signature&);
      ~fn_days_from_duration() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.4 fn:hours-from-duration
 *-----------------------*/
  class fn_hours_from_duration : public function
  {
    public:
      fn_hours_from_duration(const signature&);
      ~fn_hours_from_duration() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.5 fn:minutes-from-duration
 *-----------------------*/
  class fn_minutes_from_duration : public function
  {
    public:
      fn_minutes_from_duration(const signature&);
      ~fn_minutes_from_duration() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.6 fn:seconds-from-duration
 *-----------------------*/
  class fn_seconds_from_duration : public function
  {
    public:
      fn_seconds_from_duration(const signature&);
      ~fn_seconds_from_duration() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.7 fn:year-from-dateTime
 *-----------------------*/
  class fn_year_from_datetime : public function
  {
    public:
      fn_year_from_datetime(const signature&);
      ~fn_year_from_datetime() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.8 fn:month-from-dateTime
 *-----------------------*/
  class fn_month_from_datetime : public function
  {
    public:
      fn_month_from_datetime(const signature&);
      ~fn_month_from_datetime() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.9 fn:day-from-dateTime
 *-----------------------*/
  class fn_day_from_datetime : public function
  {
    public:
      fn_day_from_datetime(const signature&);
      ~fn_day_from_datetime() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.10 fn:hours-from-dateTime
 *-----------------------*/
  class fn_hours_from_datetime : public function
  {
    public:
      fn_hours_from_datetime(const signature&);
      ~fn_hours_from_datetime() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };
  
/*
 * 10.5.11 fn:minutes-from-dateTime
 *-----------------------*/
  class fn_minutes_from_datetime : public function
  {
    public:
      fn_minutes_from_datetime(const signature&);
      ~fn_minutes_from_datetime() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.12 fn:seconds-from-dateTime
 *-----------------------*/
  class fn_seconds_from_datetime : public function
  {
    public:
      fn_seconds_from_datetime(const signature&);
      ~fn_seconds_from_datetime() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.13 fn:timezone-from-dateTime
 *-----------------------*/
  class fn_timezone_from_datetime : public function
  {
    public:
      fn_timezone_from_datetime(const signature&);
      ~fn_timezone_from_datetime() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.14 fn:year-from-date
 *-----------------------*/
  class fn_year_from_date : public function
  {
    public:
      fn_year_from_date(const signature&);
      ~fn_year_from_date() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.15 fn:month-from-date
 *-----------------------*/
  class fn_month_from_date : public function
  {
    public:
      fn_month_from_date(const signature&);
      ~fn_month_from_date() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.16 fn:day-from-date
 *-----------------------*/
  class fn_day_from_date : public function
  {
    public:
      fn_day_from_date(const signature&);
      ~fn_day_from_date() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.17 fn:timezone-from-date
 *-----------------------*/
  class fn_timezone_from_date : public function
  {
    public:
      fn_timezone_from_date(const signature&);
      ~fn_timezone_from_date() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.18 fn:hours-from-time
 *-----------------------*/
  class fn_hours_from_time : public function
  {
    public:
      fn_hours_from_time(const signature&);
      ~fn_hours_from_time() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.19 fn:minutes-from-time
 *-----------------------*/
  class fn_minutes_from_time : public function
  {
    public:
      fn_minutes_from_time(const signature&);
      ~fn_minutes_from_time() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.20 fn:seconds-from-time
 *-----------------------*/
  class fn_seconds_from_time : public function
  {
    public:
      fn_seconds_from_time(const signature&);
      ~fn_seconds_from_time() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.5.21 fn:timezone-from-time
 *-----------------------*/
  class fn_timezone_from_time : public function
  {
    public:
      fn_timezone_from_time(const signature&);
      ~fn_timezone_from_time() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.6.1 op:add-yearMonthDurations
 *-----------------------*/
  class op_ym_durations_add : public function
  {
    public:
      op_ym_durations_add(const signature&);
      ~op_ym_durations_add() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.6.2 op:subtract-yearMonthDurations
 *-----------------------*/
  class op_ym_durations_subtract : public function
  {
    public:
      op_ym_durations_subtract(const signature&);
      ~op_ym_durations_subtract() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.6.3 op:multiply-yearMonthDuration
 *-----------------------*/
  class op_ym_durations_multiply : public function
  {
    public:
      op_ym_durations_multiply(const signature&);
      ~op_ym_durations_multiply() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.6.4 op:divide-yearMonthDuration
 *-----------------------*/
  class op_ym_durations_divide : public function
  {
    public:
      op_ym_durations_divide(const signature&);
      ~op_ym_durations_divide() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.6.5 op:divide-yearMonthDuration-by-yearMonthDuration
 *-----------------------*/
  class op_divide_ymd_by_ymd : public function
  {
    public:
      op_divide_ymd_by_ymd(const signature&);
      ~op_divide_ymd_by_ymd() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };
  
/*
 * 10.6.6 op:add-dayTimeDurations
 *-----------------------*/
  class op_dt_durations_add : public function
  {
    public:
      op_dt_durations_add(const signature&);
      ~op_dt_durations_add() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.6.7 op:subtract-dayTimeDurations
 *-----------------------*/
  class op_dt_durations_subtract : public function
  {
    public:
      op_dt_durations_subtract(const signature&);
      ~op_dt_durations_subtract() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.6.8 op:multiply-dayTimeDuration
 *-----------------------*/
  class op_dt_durations_multiply : public function
  {
    public:
      op_dt_durations_multiply(const signature&);
      ~op_dt_durations_multiply() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.6.9 op:divide-dayTimeDuration
 *-----------------------*/
  class op_dt_durations_divide : public function
  {
    public:
      op_dt_durations_divide(const signature&);
      ~op_dt_durations_divide() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 10.6.10 op:divide-dayTimeDuration-by-dayTimeDuration
 *-----------------------*/
  class op_divide_dtd_by_dtd : public function
  {
    public:
      op_divide_dtd_by_dtd(const signature&);
      ~op_divide_dtd_by_dtd() {}

    public:
      PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };
} // namespace xqp

#endif
