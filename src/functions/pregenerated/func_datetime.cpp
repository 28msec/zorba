/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#include "runtime/datetime/datetime.h"
#include "functions/func_datetime.h"


namespace zorba{



PlanIter_t fn_zorba_dateTime_current_date::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new CurrentDate(sctx, loc, argv);
}

PlanIter_t fn_zorba_dateTime_current_dateTime::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new CurrentDateTime(sctx, loc, argv);
}

PlanIter_t fn_zorba_dateTime_current_time::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new CurrentTime(sctx, loc, argv);
}

PlanIter_t fn_zorba_dateTime_millis_to_dateTime::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MillisToDateTime(sctx, loc, argv);
}

PlanIter_t fn_zorba_dateTime_parse_date::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ParseDate(sctx, loc, argv);
}

PlanIter_t fn_zorba_dateTime_parse_dateTime::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ParseDateTime(sctx, loc, argv);
}

PlanIter_t fn_zorba_dateTime_parse_time::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ParseTime(sctx, loc, argv);
}

PlanIter_t fn_zorba_dateTime_timestamp::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new Timestamp(sctx, loc, argv);
}

PlanIter_t fn_zorba_dateTime_utc_offset::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new UTCOffset(sctx, loc, argv);
}

void populate_context_datetime(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, fn_zorba_dateTime_current_date,
        (createQName("http://www.zorba-xquery.com/modules/datetime","","current-date"), 
        GENV_TYPESYSTEM.DATE_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DATETIME_CURRENT_DATE_0);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_dateTime_current_dateTime,
        (createQName("http://www.zorba-xquery.com/modules/datetime","","current-dateTime"), 
        GENV_TYPESYSTEM.DATETIME_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DATETIME_CURRENT_DATETIME_0);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_dateTime_current_time,
        (createQName("http://www.zorba-xquery.com/modules/datetime","","current-time"), 
        GENV_TYPESYSTEM.TIME_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DATETIME_CURRENT_TIME_0);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_dateTime_millis_to_dateTime,
        (createQName("http://www.zorba-xquery.com/modules/datetime","","millis-to-dateTime"), 
        GENV_TYPESYSTEM.LONG_TYPE_ONE, 
        GENV_TYPESYSTEM.DATETIME_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DATETIME_MILLIS_TO_DATETIME_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_dateTime_parse_date,
        (createQName("http://www.zorba-xquery.com/modules/datetime","","parse-date"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.DATE_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DATETIME_PARSE_DATE_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_dateTime_parse_date,
        (createQName("http://www.zorba-xquery.com/modules/datetime","","parse-date"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.DATE_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DATETIME_PARSE_DATE_3);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_dateTime_parse_dateTime,
        (createQName("http://www.zorba-xquery.com/modules/datetime","","parse-dateTime"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.DATETIME_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DATETIME_PARSE_DATETIME_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_dateTime_parse_dateTime,
        (createQName("http://www.zorba-xquery.com/modules/datetime","","parse-dateTime"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.DATETIME_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DATETIME_PARSE_DATETIME_3);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_dateTime_parse_time,
        (createQName("http://www.zorba-xquery.com/modules/datetime","","parse-time"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.TIME_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DATETIME_PARSE_TIME_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_dateTime_parse_time,
        (createQName("http://www.zorba-xquery.com/modules/datetime","","parse-time"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.TIME_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DATETIME_PARSE_TIME_3);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_dateTime_timestamp,
        (createQName("http://www.zorba-xquery.com/modules/datetime","","timestamp"), 
        GENV_TYPESYSTEM.LONG_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DATETIME_TIMESTAMP_0);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_dateTime_utc_offset,
        (createQName("http://www.zorba-xquery.com/modules/datetime","","utc-offset"), 
        GENV_TYPESYSTEM.LONG_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DATETIME_UTC_OFFSET_0);

  }

}


}



