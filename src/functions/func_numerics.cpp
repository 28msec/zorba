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


#include "runtime/numerics/numerics.h"
#include "functions/func_numerics.h"


namespace zorba{



PlanIter_t fn_abs::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new AbsIterator(sctx, loc, argv);
}

PlanIter_t fn_ceiling::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CeilingIterator(sctx, loc, argv);
}

PlanIter_t fn_floor::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FloorIterator(sctx, loc, argv);
}

PlanIter_t fn_round::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new RoundIterator(sctx, loc, argv);
}

PlanIter_t fn_round_half_to_even::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new RoundHalfToEvenIterator(sctx, loc, argv);
}

PlanIter_t fn_format_number::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FormatNumberIterator(sctx, loc, argv);
}

void populate_context_numerics(static_context* sctx)
{
  DECL(sctx, fn_abs,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","abs"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));


  DECL(sctx, fn_ceiling,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","ceiling"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));


  DECL(sctx, fn_floor,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","floor"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));


  DECL(sctx, fn_round,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","round"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));


  DECL(sctx, fn_round_half_to_even,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","round-half-to-even"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));


  DECL(sctx, fn_round_half_to_even,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","round-half-to-even"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));


  DECL(sctx, fn_format_number,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","format-number"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));


  DECL(sctx, fn_format_number,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","format-number"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

}


}