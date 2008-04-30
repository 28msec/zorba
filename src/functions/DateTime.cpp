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
#include "system/globalenv.h"
#include "runtime/dateTime/DurationsDatesTimes.h"
#include "runtime/numerics/NumericsImpl.h"

namespace zorba
{



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

} // namespace zorba

