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

#include "functions/durations_dates_times_impl.h"
#include "functions/function_impl.h"

#include "runtime/durations_dates_times/DurationsDatesTimesImpl.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/core/arithmetic_impl.h"

namespace zorba
{

class fn_datetime_ctor : public function
{
public:
  fn_datetime_ctor(const signature& sig) : function (sig) {}

  DEFAULT_BINARY_CODEGEN(FnDateTimeConstructorIterator);
};


/*
 * 10.6.1 op:add-yearMonthDurations
 *-----------------------*/
class op_ym_durations_add : public function
{
public:
  op_ym_durations_add(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<AddOperation>);
};


/*
 * 10.6.2 op:subtract-yearMonthDurations
 *-----------------------*/
class op_ym_durations_subtract : public function
{
public:
  op_ym_durations_subtract(const signature& sig) : function (sig) {}

  DEFAULT_BINARY_CODEGEN(NumArithIterator<SubtractOperation>);
};
  

/*
 * 10.6.3 op:multiply-yearMonthDuration
 *-----------------------*/
class op_ym_durations_multiply : public function
{
public:
  op_ym_durations_multiply(const signature& sig) : function (sig) {}

  DEFAULT_BINARY_CODEGEN(NumArithIterator<MultiplyOperation>);
};


/*
 * 10.6.4 op:divide-yearMonthDuration
 *-----------------------*/
class op_ym_durations_divide : public function
{
public:
  op_ym_durations_divide(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<DivideOperation>);
};


/*
 * 10.6.5 op:divide-yearMonthDuration-by-yearMonthDuration
 *-----------------------*/
class op_divide_ymd_by_ymd : public function
{
public:
  op_divide_ymd_by_ymd(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<DivideOperation>);
};


/*
 * 10.6.6 op:add-dayTimeDurations
 *-----------------------*/
class op_dt_durations_add : public function
{
public:
  op_dt_durations_add(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<AddOperation>);
};


/*
 * 10.6.7 op:subtract-dayTimeDurations
 *-----------------------*/
class op_dt_durations_subtract : public function
{
public:
  op_dt_durations_subtract(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<SubtractOperation>);
};


/*
 * 10.6.8 op:multiply-dayTimeDuration
 *-----------------------*/
class op_dt_durations_multiply : public function
{
public:
  op_dt_durations_multiply(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<MultiplyOperation>);
};


/*
 * 10.6.9 op:divide-dayTimeDuration
 *-----------------------*/
class op_dt_durations_divide : public function
{
public:
  op_dt_durations_divide(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<DivideOperation>);
};


/*
 * 10.6.10 op:divide-dayTimeDuration-by-dayTimeDuration
 *-----------------------*/
class op_divide_dtd_by_dtd : public function
{
public:
  op_divide_dtd_by_dtd(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<DivideOperation>);
};


/*
 * 10.8.1 op:subtract-dateTimes
 *-----------------------*/
class op_sub_dt : public function
{
public:
  op_sub_dt(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<SubtractOperation>);
};
  
  
/*
 * 10.8.2 op:subtract-dates
 *-----------------------*/
class op_sub_d : public function
{
public:
  op_sub_d(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<SubtractOperation>);
};


/*
 * 10.8.3 op:subtract-times
 *-----------------------*/
class op_sub_t : public function
{
public:
  op_sub_t(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<SubtractOperation>);
};


/*
 * 10.8.4 op:add-yearMonthDuration-to-dateTime
 *-----------------------*/
class op_add_ymd_to_dt : public function
{
public:
  op_add_ymd_to_dt(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<AddOperation>);
};


/*
 * 10.8.5 op:add-dayTimeDuration-to-dateTime
 *-----------------------*/
class op_add_dtd_to_dt : public function
{
public:
  op_add_dtd_to_dt(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<AddOperation>);
};


/*
 * 10.8.6 op:subtract-yearMonthDuration-from-dateTime
 *-----------------------*/
class op_sub_ymd_from_dt : public function
{
public:
  op_sub_ymd_from_dt(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<SubtractOperation>);
};


/*
 * 10.8.7 op:subtract-dayTimeDuration-from-dateTime
 *-----------------------*/
class op_sub_dtd_from_dt : public function
{
public:
  op_sub_dtd_from_dt(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<SubtractOperation>);
};


/*
 * 10.8.8 op:add-yearMonthDuration-to-date
 *-----------------------*/
class op_add_ymd_to_d : public function
{
public:
  op_add_ymd_to_d(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<AddOperation>);
};


/*
 * 10.8.9 op:add-dayTimeDuration-to-date
 *-----------------------*/
class op_add_dtd_to_d : public function
{
public:
  op_add_dtd_to_d(const signature& sig) : function (sig) {}

  DEFAULT_BINARY_CODEGEN(NumArithIterator<AddOperation>);
};


/*
 * 10.8.10 op:subtract-yearMonthDuration-from-date
 *-----------------------*/
class op_sub_ymd_from_d : public function
{
public:
  op_sub_ymd_from_d(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(NumArithIterator<SubtractOperation>);
};


/*
 * 10.8.11 op:subtract-dayTimeDuration-from-date
 *-----------------------*/
class op_sub_dtd_from_d : public function
{
public:
  op_sub_dtd_from_d(const signature& sig) : function (sig) {}

  DEFAULT_BINARY_CODEGEN(NumArithIterator<SubtractOperation>);  
};


/*
 * 10.8.12 op:add-dayTimeDuration-to-time
 *-----------------------*/
class op_add_dtd_to_t : public function
{
public:
  op_add_dtd_to_t(const signature& sig) : function (sig) {}

  DEFAULT_BINARY_CODEGEN(NumArithIterator<AddOperation>);
};


/*
 * 10.8.13 op:subtract-dayTimeDuration-from-time
 *-----------------------*/
class op_sub_dtd_from_t : public function
{
public:
  op_sub_dtd_from_t(const signature& sig) : function (sig) {}

  DEFAULT_BINARY_CODEGEN(NumArithIterator<SubtractOperation>);  
};


/*
 * 10.7.1 fn:adjust-dateTime-to-timezone
 *-----------------------*/
class fn_adjust_dt_to_tz_1 : public function
{
public:
  bool requires_dyn_ctx () const { return true; }

  fn_adjust_dt_to_tz_1(const signature& sig) : function (sig) {}

  DEFAULT_UNARY_CODEGEN(FnAdjustToTimeZoneIterator_1);
};


class fn_adjust_dt_to_tz_2 : public function
{
public:
  fn_adjust_dt_to_tz_2(const signature& sig) : function (sig) {}

  DEFAULT_BINARY_CODEGEN(FnAdjustToTimeZoneIterator_2);
};


/*
 * 10.7.2 fn:adjust-date-to-timezone
 *-----------------------*/
class fn_adjust_d_to_tz_1 : public function
{
public:
  fn_adjust_d_to_tz_1(const signature& sig) : function (sig) {}

  bool requires_dyn_ctx () const { return true; }

  DEFAULT_UNARY_CODEGEN(FnAdjustToTimeZoneIterator_1);
};


class fn_adjust_d_to_tz_2 : public function
{
public:
  fn_adjust_d_to_tz_2(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(FnAdjustToTimeZoneIterator_2);
};


/*
 * 10.7.3 fn:adjust-time-to-timezone
 *-----------------------*/
class fn_adjust_t_to_tz_1 : public function
{
public:
  fn_adjust_t_to_tz_1(const signature& sig) : function (sig) {}
  
  bool requires_dyn_ctx () const { return true; }

  DEFAULT_UNARY_CODEGEN(FnAdjustToTimeZoneIterator_1);
};


class fn_adjust_t_to_tz_2 : public function
{
public:
  fn_adjust_t_to_tz_2(const signature& sig) : function (sig) {}

  DEFAULT_BINARY_CODEGEN(FnAdjustToTimeZoneIterator_2);
};


/*
 * XQuery1.1 formatting functions
 *------------------------------------------------*/
  
class fn_format_datetime_4 : public function
{
public:
  fn_format_datetime_4(const signature& sig) : function (sig) {}

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new FnFormatDateTimeIterator(sctx, loc, argv, DateTime::DATETIME_FACET);
  }
};


class fn_format_datetime_2 : public function
{
public:
  fn_format_datetime_2(const signature& sig) : function (sig) {}

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new FnFormatDateTimeIterator(sctx, loc, argv, DateTime::DATETIME_FACET);
  }
};


class fn_format_date_4 : public function
{
public:
  fn_format_date_4(const signature& sig) : function (sig) {}

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new FnFormatDateTimeIterator(sctx, loc, argv, DateTime::DATE_FACET);
  }
};


class fn_format_date_2 : public function
{
public:
  fn_format_date_2(const signature& sig) : function (sig) {}

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new FnFormatDateTimeIterator(sctx, loc, argv, DateTime::DATE_FACET);
  }
};


class fn_format_time_4 : public function
{
public:
  fn_format_time_4(const signature& sig) : function (sig) {}

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new FnFormatDateTimeIterator(sctx, loc, argv, DateTime::TIME_FACET);
  }
};


class fn_format_time_2 : public function
{
public:
  fn_format_time_2(const signature& sig) : function (sig) {}

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new FnFormatDateTimeIterator(sctx, loc, argv, DateTime::TIME_FACET);
  }
};



void populate_context_durations_dates_times_impl(static_context *sctx)
{
// begin date time
DECL(sctx, fn_datetime_ctor,
     (createQName(XQUERY_OP_NS,"fn", "dateTime"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION));

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

DECL(sctx, op_sub_dt,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dateTimes"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION));

DECL(sctx, op_sub_d,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dates"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_QUESTION));

DECL(sctx, op_sub_t,
     (createQName (XQUERY_FN_NS,"fn", "subtract-times"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(sctx, op_add_ymd_to_dt,
     (createQName (XQUERY_FN_NS,"fn", "add-yearMonthDuration-to-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

DECL(sctx, op_add_dtd_to_dt,
     (createQName (XQUERY_FN_NS,"fn", "add-dayTimeDuration-to-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

DECL(sctx, op_sub_ymd_from_dt,
     (createQName (XQUERY_FN_NS,"fn", "subtract-yearMonthDuration-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

DECL(sctx, op_sub_dtd_from_dt,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDuration-from-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

DECL(sctx, op_add_ymd_to_d,
     (createQName (XQUERY_FN_NS,"fn", "add-yearMonthDuration-to-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

DECL(sctx, op_add_dtd_to_d,
     (createQName (XQUERY_FN_NS,"fn", "add-dayTimeDuration-to-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

DECL(sctx, op_sub_ymd_from_d,
     (createQName (XQUERY_FN_NS,"fn", "subtract-yearMonthDuration-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

DECL(sctx, op_sub_dtd_from_d,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDuration-from-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

DECL(sctx, op_add_dtd_to_t,
     (createQName (XQUERY_FN_NS,"fn", "add-dayTimeDuration-to-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
      GENV_TYPESYSTEM.TIME_TYPE_ONE));

DECL(sctx, op_sub_dtd_from_t,
     (createQName (XQUERY_FN_NS,"fn", "subtract-dayTimeDuration-from-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE,
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE,
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

DECL(sctx, fn_format_datetime_4,
     (createQName (XQUERY_FN_NS, "fn", "format-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION));

DECL(sctx, fn_format_datetime_2,
     (createQName (XQUERY_FN_NS, "fn", "format-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION));

DECL(sctx, fn_format_date_4,
     (createQName (XQUERY_FN_NS, "fn", "format-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION));

DECL(sctx, fn_format_date_2,
     (createQName (XQUERY_FN_NS, "fn", "format-date"),
      GENV_TYPESYSTEM.DATE_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION));

DECL(sctx, fn_format_time_4,
     (createQName (XQUERY_FN_NS, "fn", "format-time"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION));

DECL(sctx, fn_format_time_2,
     (createQName (XQUERY_FN_NS, "fn", "format-TIME"),
      GENV_TYPESYSTEM.TIME_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION));

// end date time

}

} // namespace zorba

