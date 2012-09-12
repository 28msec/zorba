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
#include "runtime/context/context.h"
#include "functions/func_context.h"


namespace zorba{



PlanIter_t fn_current_dateTime::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new CurrentDateTimeIterator(sctx, loc, argv);
}

PlanIter_t fn_current_date::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new CurrentDateIterator(sctx, loc, argv);
}

PlanIter_t fn_current_time::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new CurrentTimeIterator(sctx, loc, argv);
}

PlanIter_t fn_implicit_timezone::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ImplicitTimezoneIterator(sctx, loc, argv);
}

PlanIter_t fn_default_collation::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DefaultCollationIterator(sctx, loc, argv);
}

PlanIter_t fn_position::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return NULL;
}

PlanIter_t fn_last::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return NULL;
}

PlanIter_t fn_static_base_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return NULL;
}

void populate_context_context(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, fn_current_dateTime,
        (createQName("http://www.w3.org/2005/xpath-functions","","current-dateTime"), 
        GENV_TYPESYSTEM.DATETIME_TYPE_ONE),
        FunctionConsts::FN_CURRENT_DATETIME_0);

  }




      {
    DECL_WITH_KIND(sctx, fn_current_date,
        (createQName("http://www.w3.org/2005/xpath-functions","","current-date"), 
        GENV_TYPESYSTEM.DATE_TYPE_ONE),
        FunctionConsts::FN_CURRENT_DATE_0);

  }




      {
    DECL_WITH_KIND(sctx, fn_current_time,
        (createQName("http://www.w3.org/2005/xpath-functions","","current-time"), 
        GENV_TYPESYSTEM.TIME_TYPE_ONE),
        FunctionConsts::FN_CURRENT_TIME_0);

  }




      {
    DECL_WITH_KIND(sctx, fn_implicit_timezone,
        (createQName("http://www.w3.org/2005/xpath-functions","","implicit-timezone"), 
        GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE),
        FunctionConsts::FN_IMPLICIT_TIMEZONE_0);

  }




      {
    DECL_WITH_KIND(sctx, fn_default_collation,
        (createQName("http://www.w3.org/2005/xpath-functions","","default-collation"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_DEFAULT_COLLATION_0);

  }




      {
    DECL_WITH_KIND(sctx, fn_position,
        (createQName("http://www.w3.org/2005/xpath-functions","","position"), 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::FN_POSITION_0);

  }




      {
    DECL_WITH_KIND(sctx, fn_last,
        (createQName("http://www.w3.org/2005/xpath-functions","","last"), 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::FN_LAST_0);

  }




      {
    DECL_WITH_KIND(sctx, fn_static_base_uri,
        (createQName("http://www.w3.org/2005/xpath-functions","","static-base-uri"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION),
        FunctionConsts::FN_STATIC_BASE_URI_0);

  }

}


}



