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
  expr& ann) const
{
  return new FnConcatIterator(sctx, loc, argv);
}

PlanIter_t fn_index_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnIndexOfIterator(sctx, loc, argv);
}

PlanIter_t fn_empty::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnEmptyIterator(sctx, loc, argv);
}

PlanIter_t fn_exists::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnExistsIterator(sctx, loc, argv);
}

PlanIter_t fn_distinct_values::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnDistinctValuesIterator(sctx, loc, argv);
}

PlanIter_t fn_insert_before::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnInsertBeforeIterator(sctx, loc, argv);
}

PlanIter_t fn_remove::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnRemoveIterator(sctx, loc, argv);
}

PlanIter_t fn_reverse::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnReverseIterator(sctx, loc, argv);
}





PlanIter_t fn_one_or_more::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnOneOrMoreIterator(sctx, loc, argv);
}

PlanIter_t fn_deep_equal::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnDeepEqualIterator(sctx, loc, argv);
}


PlanIter_t fn_avg::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnAvgIterator(sctx, loc, argv);
}

PlanIter_t fn_sum::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnSumIterator(sctx, loc, argv);
}

PlanIter_t op_sum_double::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnSumDoubleIterator(sctx, loc, argv);
}

PlanIter_t op_sum_float::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnSumFloatIterator(sctx, loc, argv);
}

PlanIter_t op_sum_decimal::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnSumDecimalIterator(sctx, loc, argv);
}

PlanIter_t op_sum_integer::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnSumIntegerIterator(sctx, loc, argv);
}

PlanIter_t op_to::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new OpToIterator(sctx, loc, argv);
}

PlanIter_t fn_id::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnIdIterator(sctx, loc, argv);
}

PlanIter_t fn_element_with_id::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnElementWithIdIterator(sctx, loc, argv);
}

PlanIter_t fn_idref::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnIdRefIterator(sctx, loc, argv);
}

PlanIter_t fn_doc::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnDocIterator(sctx, loc, argv);
}

PlanIter_t fn_doc_available::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnDocAvailableIterator(sctx, loc, argv);
}

PlanIter_t fn_available_environment_variables::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnAvailableEnvironmentVariablesIterator(sctx, loc, argv);
}

PlanIter_t fn_environment_variable::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnEnvironmentVariableIterator(sctx, loc, argv);
}

PlanIter_t fn_unparsed_text::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnUnparsedTextIterator(sctx, loc, argv);
}

PlanIter_t fn_unparsed_text_available::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnUnparsedTextAvailableIterator(sctx, loc, argv);
}

void populate_context_sequences(static_context* sctx)
{
  {
    std::vector<xqtref_t> lParamTypes;
    lParamTypes.push_back(GENV_TYPESYSTEM.ITEM_TYPE_STAR);

    DECL_WITH_KIND(sctx, op_concatenate,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","concatenate"), 
        lParamTypes, GENV_TYPESYSTEM.ITEM_TYPE_STAR, true),
        FunctionConsts::OP_CONCATENATE_N);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_index_of,
        (createQName("http://www.w3.org/2005/xpath-functions","","index-of"), 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_STAR),
        FunctionConsts::FN_INDEX_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_index_of,
        (createQName("http://www.w3.org/2005/xpath-functions","","index-of"), 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_STAR),
        FunctionConsts::FN_INDEX_OF_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_empty,
        (createQName("http://www.w3.org/2005/xpath-functions","","empty"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_EMPTY_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_exists,
        (createQName("http://www.w3.org/2005/xpath-functions","","exists"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_EXISTS_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_distinct_values,
        (createQName("http://www.w3.org/2005/xpath-functions","","distinct-values"), 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR),
        FunctionConsts::FN_DISTINCT_VALUES_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_distinct_values,
        (createQName("http://www.w3.org/2005/xpath-functions","","distinct-values"), 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR),
        FunctionConsts::FN_DISTINCT_VALUES_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_insert_before,
        (createQName("http://www.w3.org/2005/xpath-functions","","insert-before"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_INSERT_BEFORE_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_remove,
        (createQName("http://www.w3.org/2005/xpath-functions","","remove"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_REMOVE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_reverse,
        (createQName("http://www.w3.org/2005/xpath-functions","","reverse"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_REVERSE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_subsequence,
        (createQName("http://www.w3.org/2005/xpath-functions","","subsequence"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_SUBSEQUENCE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_subsequence,
        (createQName("http://www.w3.org/2005/xpath-functions","","subsequence"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_SUBSEQUENCE_3);

  }


  {
    

    DECL_WITH_KIND(sctx, op_zorba_subsequence_int,
        (createQName("http://www.zorba-xquery.com/internal/zorba-ops","","subsequence-int"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::OP_ZORBA_SUBSEQUENCE_INT_2);

  }


  {
    

    DECL_WITH_KIND(sctx, op_zorba_subsequence_int,
        (createQName("http://www.zorba-xquery.com/internal/zorba-ops","","subsequence-int"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::OP_ZORBA_SUBSEQUENCE_INT_3);

  }


  {
    

    DECL_WITH_KIND(sctx, op_zorba_sequence_point_access,
        (createQName("http://www.zorba-xquery.com/internal/zorba-ops","","sequence-point-access"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION),
        FunctionConsts::OP_ZORBA_SEQUENCE_POINT_ACCESS_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zero_or_one,
        (createQName("http://www.w3.org/2005/xpath-functions","","zero-or-one"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION),
        FunctionConsts::FN_ZERO_OR_ONE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_one_or_more,
        (createQName("http://www.w3.org/2005/xpath-functions","","one-or-more"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_PLUS),
        FunctionConsts::FN_ONE_OR_MORE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_deep_equal,
        (createQName("http://www.w3.org/2005/xpath-functions","","deep-equal"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_DEEP_EQUAL_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_deep_equal,
        (createQName("http://www.w3.org/2005/xpath-functions","","deep-equal"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_DEEP_EQUAL_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_count,
        (createQName("http://www.w3.org/2005/xpath-functions","","count"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::FN_COUNT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_avg,
        (createQName("http://www.w3.org/2005/xpath-functions","","avg"), 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION),
        FunctionConsts::FN_AVG_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_sum,
        (createQName("http://www.w3.org/2005/xpath-functions","","sum"), 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE),
        FunctionConsts::FN_SUM_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_sum,
        (createQName("http://www.w3.org/2005/xpath-functions","","sum"), 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION),
        FunctionConsts::FN_SUM_2);

  }


  {
    

    DECL_WITH_KIND(sctx, op_sum_double,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","sum_double"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_STAR, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::OP_SUM_DOUBLE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, op_sum_double,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","sum_double"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION),
        FunctionConsts::OP_SUM_DOUBLE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, op_sum_float,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","sum_float"), 
        GENV_TYPESYSTEM.FLOAT_TYPE_STAR, 
        GENV_TYPESYSTEM.FLOAT_TYPE_ONE),
        FunctionConsts::OP_SUM_FLOAT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, op_sum_float,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","sum_float"), 
        GENV_TYPESYSTEM.FLOAT_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION),
        FunctionConsts::OP_SUM_FLOAT_2);

  }


  {
    

    DECL_WITH_KIND(sctx, op_sum_decimal,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","sum_decimal"), 
        GENV_TYPESYSTEM.DECIMAL_TYPE_STAR, 
        GENV_TYPESYSTEM.DECIMAL_TYPE_ONE),
        FunctionConsts::OP_SUM_DECIMAL_1);

  }


  {
    

    DECL_WITH_KIND(sctx, op_sum_decimal,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","sum_decimal"), 
        GENV_TYPESYSTEM.DECIMAL_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION),
        FunctionConsts::OP_SUM_DECIMAL_2);

  }


  {
    

    DECL_WITH_KIND(sctx, op_sum_integer,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","sum_integer"), 
        GENV_TYPESYSTEM.INTEGER_TYPE_STAR, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::OP_SUM_INTEGER_1);

  }


  {
    

    DECL_WITH_KIND(sctx, op_sum_integer,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","sum_integer"), 
        GENV_TYPESYSTEM.INTEGER_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION),
        FunctionConsts::OP_SUM_INTEGER_2);

  }


  {
    

    DECL_WITH_KIND(sctx, op_to,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","to"), 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_STAR),
        FunctionConsts::OP_TO_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_id,
        (createQName("http://www.w3.org/2005/xpath-functions","","id"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_STAR),
        FunctionConsts::FN_ID_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_id,
        (createQName("http://www.w3.org/2005/xpath-functions","","id"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_STAR),
        FunctionConsts::FN_ID_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_element_with_id,
        (createQName("http://www.w3.org/2005/xpath-functions","","element-with-id"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_STAR),
        FunctionConsts::FN_ELEMENT_WITH_ID_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_element_with_id,
        (createQName("http://www.w3.org/2005/xpath-functions","","element-with-id"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_STAR),
        FunctionConsts::FN_ELEMENT_WITH_ID_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_idref,
        (createQName("http://www.w3.org/2005/xpath-functions","","idref"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::FN_IDREF_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_idref,
        (createQName("http://www.w3.org/2005/xpath-functions","","idref"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::FN_IDREF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_doc,
        (createQName("http://www.w3.org/2005/xpath-functions","","doc"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOCUMENT_UNTYPED_TYPE_QUESTION),
        FunctionConsts::FN_DOC_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_doc_available,
        (createQName("http://www.w3.org/2005/xpath-functions","","doc-available"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_DOC_AVAILABLE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_available_environment_variables,
        (createQName("http://www.w3.org/2005/xpath-functions","","available-environment-variables"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR),
        FunctionConsts::FN_AVAILABLE_ENVIRONMENT_VARIABLES_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_environment_variable,
        (createQName("http://www.w3.org/2005/xpath-functions","","environment-variable"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_ENVIRONMENT_VARIABLE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_unparsed_text,
        (createQName("http://www.w3.org/2005/xpath-functions","","unparsed-text"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_UNPARSED_TEXT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_unparsed_text,
        (createQName("http://www.w3.org/2005/xpath-functions","","unparsed-text"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_UNPARSED_TEXT_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_unparsed_text_available,
        (createQName("http://www.w3.org/2005/xpath-functions","","unparsed-text-available"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_UNPARSED_TEXT_AVAILABLE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_unparsed_text_available,
        (createQName("http://www.w3.org/2005/xpath-functions","","unparsed-text-available"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_UNPARSED_TEXT_AVAILABLE_2);

  }

}


}



