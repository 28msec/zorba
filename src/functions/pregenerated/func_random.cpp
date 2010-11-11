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


#include "runtime/random/random.h"
#include "functions/func_random.h"


namespace zorba{



PlanIter_t op_zorba_numgen::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NumGenIterator(sctx, loc);
}

PlanIter_t fn_zorba_util_random::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new RandomIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_random_random::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new PseudoRandomIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_util_uuid::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new UuidIterator(sctx, loc, argv);
}

void populate_context_random(static_context* sctx)
{
  DECL(sctx, op_zorba_numgen,
      (createQName("http://www.zorba-xquery.com/internal/zorba-ops","op-zorba","numgen"),
      GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));


  DECL(sctx, fn_zorba_util_random,
      (createQName("http://www.zorba-xquery.com/zorba/util-functions","fn-zorba-util","random"),
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));


  DECL(sctx, fn_zorba_util_random,
      (createQName("http://www.zorba-xquery.com/zorba/util-functions","fn-zorba-util","random"),
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));


  DECL(sctx, fn_zorba_random_random,
      (createQName("http://www.zorba-xquery.com/modules/random","fn-zorba-random","random"),
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));


  DECL(sctx, fn_zorba_random_random,
      (createQName("http://www.zorba-xquery.com/modules/random","fn-zorba-random","random"),
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));


  DECL(sctx, fn_zorba_util_uuid,
      (createQName("http://www.zorba-xquery.com/zorba/util-functions","fn-zorba-util","uuid"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));


  DECL(sctx, fn_zorba_util_uuid,
      (createQName("http://www.zorba-xquery.com/modules/random","fn-zorba-random","uuid"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

}


}



