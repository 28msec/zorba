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


#include "runtime/sequences/sequences.h"
#include "functions/func_sequences.h"
#include "system/globalenv.h"
#include "types/typeops.h"
#include "compiler/expression/expr_base.h"


namespace zorba{



PlanIter_t op_concatenate::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnConcatIterator(sctx, loc, argv, ann.is_updating() );
}

PlanIter_t fn_index_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnIndexOfIterator(sctx, loc, argv);
}

PlanIter_t fn_empty::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnEmptyIterator(sctx, loc, argv);
}

PlanIter_t fn_exists::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnExistsIterator(sctx, loc, argv);
}

PlanIter_t fn_distinct_values::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnDistinctValuesIterator(sctx, loc, argv);
}

PlanIter_t fn_insert_before::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnInsertBeforeIterator(sctx, loc, argv);
}

PlanIter_t fn_remove::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnRemoveIterator(sctx, loc, argv);
}

PlanIter_t fn_reverse::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnReverseIterator(sctx, loc, argv);
}





PlanIter_t fn_one_or_more::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnOneOrMoreIterator(sctx, loc, argv);
}

PlanIter_t fn_deep_equal::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnDeepEqualIterator(sctx, loc, argv);
}

PlanIter_t fn_count::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnCountIterator(sctx, loc, argv);
}

PlanIter_t fn_avg::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnAvgIterator(sctx, loc, argv);
}

PlanIter_t fn_sum::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnSumIterator(sctx, loc, argv);
}

PlanIter_t fn_sum_double::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnSumDoubleIterator(sctx, loc, argv);
}

PlanIter_t fn_sum_float::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnSumFloatIterator(sctx, loc, argv);
}

PlanIter_t fn_sum_decimal::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnSumDecimalIterator(sctx, loc, argv);
}

PlanIter_t fn_sum_integer::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnSumIntegerIterator(sctx, loc, argv);
}

PlanIter_t op_to::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new OpToIterator(sctx, loc, argv);
}

PlanIter_t fn_doc::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnDocIterator(sctx, loc, argv);
}

PlanIter_t fn_doc_available::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnDocAvailableIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_util_parse::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new UtilsParseIterator(sctx, loc, argv);
}

PlanIter_t fn_parse::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnParseIterator(sctx, loc, argv);
}

void populate_context_sequences(static_context* sctx)
{
  DECL(sctx, op_concatenate,
      (createQName("http://www.w3.org/2005/xpath-functions","op","concatenate"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


  DECL(sctx, fn_index_of,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","index-of"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_STAR));


  DECL(sctx, fn_index_of,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","index-of"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_STAR));


  DECL(sctx, fn_empty,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","empty"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_exists,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","exists"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_distinct_values,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","distinct-values"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));


  DECL(sctx, fn_distinct_values,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","distinct-values"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));


  DECL(sctx, fn_insert_before,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","insert-before"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


  DECL(sctx, fn_remove,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","remove"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


  DECL(sctx, fn_reverse,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","reverse"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


  DECL(sctx, fn_subsequence,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","subsequence"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


  DECL(sctx, fn_subsequence,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","subsequence"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


  DECL(sctx, fn_zorba_subsequence_int,
      (createQName("http://www.zorba-xquery.com/zorba/internal-functions","fn-zorba","subsequence-int"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


  DECL(sctx, fn_zorba_subsequence_int,
      (createQName("http://www.zorba-xquery.com/zorba/internal-functions","fn-zorba","subsequence-int"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


  DECL(sctx, fn_zorba_sequence_point_access,
      (createQName("http://www.zorba-xquery.com/zorba/internal-functions","fn-zorba","sequence-point-access"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_QUESTION));


  DECL(sctx, fn_zero_or_one,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","zero-or-one"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_QUESTION));


  DECL(sctx, fn_one_or_more,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","one-or-more"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_PLUS));


  DECL(sctx, fn_deep_equal,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","deep-equal"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_deep_equal,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","deep-equal"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_count,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","count"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));


  DECL(sctx, fn_avg,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","avg"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));


  DECL(sctx, fn_sum,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","sum"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));


  DECL(sctx, fn_sum,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","sum"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));


  DECL(sctx, fn_sum_double,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","sum_double"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_STAR,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));


  DECL(sctx, fn_sum_double,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","sum_double"),
      GENV_TYPESYSTEM.DOUBLE_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));


  DECL(sctx, fn_sum_float,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","sum_float"),
      GENV_TYPESYSTEM.FLOAT_TYPE_STAR,
      GENV_TYPESYSTEM.FLOAT_TYPE_ONE));


  DECL(sctx, fn_sum_float,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","sum_float"),
      GENV_TYPESYSTEM.FLOAT_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));


  DECL(sctx, fn_sum_decimal,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","sum_decimal"),
      GENV_TYPESYSTEM.DECIMAL_TYPE_STAR,
      GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));


  DECL(sctx, fn_sum_decimal,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","sum_decimal"),
      GENV_TYPESYSTEM.DECIMAL_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));


  DECL(sctx, fn_sum_integer,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","sum_integer"),
      GENV_TYPESYSTEM.INTEGER_TYPE_STAR,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));


  DECL(sctx, fn_sum_integer,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","sum_integer"),
      GENV_TYPESYSTEM.INTEGER_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));


  DECL(sctx, op_to,
      (createQName("http://www.w3.org/2005/xpath-functions","op","to"),
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_STAR));


  DECL(sctx, fn_doc,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","doc"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.DOCUMENT_UNTYPED_TYPE_QUESTION));


  DECL(sctx, fn_doc_available,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","doc-available"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_zorba_util_parse,
      (createQName("http://www.zorba-xquery.com/zorba/util-functions","fn-zorba-util","parse"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.DOCUMENT_UNTYPED_TYPE_ONE));


  DECL(sctx, fn_parse,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","parse"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.DOCUMENT_UNTYPED_TYPE_ONE));


  DECL(sctx, fn_parse,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","parse"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.DOCUMENT_UNTYPED_TYPE_ONE));

}


}