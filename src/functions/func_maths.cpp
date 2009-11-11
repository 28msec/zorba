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


#include "runtime/maths/maths.h"
#include "functions/func_maths.h"


namespace zorba{



PlanIter_t fn_zorba_math_sqrt::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnSQRTIterator ( sctx, loc, argv[0]);
}




PlanIter_t fn_zorba_math_atan2::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnAtan2Iterator ( sctx, loc, argv[0], argv[1]);
}



void populate_context_maths(static_context* sctx) {

  DECL(sctx, fn_zorba_math_sqrt,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","sqrt"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));

  DECL(sctx, fn_zorba_math_atan2,
      (createQName("http://www.zorba-xquery.com/modules/math","fn-zorba-math","atan2"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_PLUS));
}


}