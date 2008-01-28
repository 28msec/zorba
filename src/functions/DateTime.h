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
    TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
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
      TypeSystem::xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  }; 
} // namespace xqp

#endif
