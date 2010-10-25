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


#include "runtime/context/context.h"
#include "functions/func_context.h"


namespace zorba{



PlanIter_t fn_current_dateTime::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CurrentDateTimeIterator(sctx, loc, argv);
}

PlanIter_t fn_current_date::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CurrentDateIterator(sctx, loc, argv);
}

PlanIter_t fn_current_time::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CurrentTimeIterator(sctx, loc, argv);
}

PlanIter_t fn_implicit_timezone::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ImplicitTimezoneIterator(sctx, loc, argv);
}

PlanIter_t fn_default_collation::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DefaultCollationIterator(sctx, loc, argv);
}

void populate_context_context(static_context* sctx)
{
  DECL(sctx, fn_current_dateTime,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","current-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));


  DECL(sctx, fn_current_date,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","current-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE));


  DECL(sctx, fn_current_time,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","current-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE));


  DECL(sctx, fn_implicit_timezone,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","implicit-timezone"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));


  DECL(sctx, fn_default_collation,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","default-collation"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

}


}



