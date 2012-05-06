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
#pragma once
#ifndef ZORBA_FUNCTIONS_SEQUENCES_IMPLH_H
#define ZORBA_FUNCTIONS_SEQUENCES_IMPLH_H

#include "common/shared_types.h"

#include "functions/function_impl.h"

#include "compiler/expression/fo_expr.h"

namespace zorba {

void populate_context_sequences_impl(static_context* sctx);


/*******************************************************************************

********************************************************************************/
class fn_unordered : public function
{
public:
  fn_unordered(const signature& sig)
    :
    function(sig, FunctionConsts::FN_UNORDERED_1)
  {
  }

  xqtref_t getReturnType(const fo_expr* caller) const
  {
    return caller->get_arg(0)->get_return_type();
  }

  bool isMap(csize input) const
  {
    return true;
  }

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return false;
  }

  FunctionConsts::AnnotationValue producesSortedNodes() const
  {
    return FunctionConsts::PRESERVE;
  }

  FunctionConsts::AnnotationValue producesDistinctNodes() const
  {
    return FunctionConsts::PRESERVE;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const;

  CODEGEN_DECL();
};


/*******************************************************************************
  op:exactly-one-noraise($items as item()*)

  Returns true or false depending on whether the input sequence contains
  exactly one item or not.
********************************************************************************/
class fn_exactly_one_noraise : public function
{
protected:
  bool theRaiseError;

public:
  fn_exactly_one_noraise(const signature& sig)
    :
    function(sig, FunctionConsts::OP_EXACTLY_ONE_NORAISE_1),
    theRaiseError(false)
  {
  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return false;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  CODEGEN_DECL();
};


/*******************************************************************************
  15.2.3 fn:exactly-one($items as item()*)

  If the input sequence contains exactly one item, that item is returned;
  otherwise an error is raised.
********************************************************************************/
class fn_exactly_one : public fn_exactly_one_noraise
{
public:
  fn_exactly_one(const signature& sig) : fn_exactly_one_noraise(sig)
  {
    theRaiseError = true;
    theKind = FunctionConsts::FN_EXACTLY_ONE_1;
  }

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return false;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }
};


/*******************************************************************************
  fn:union is implemented as fn:concat wrapped in a sort-distinct-nodes-asc.
********************************************************************************/
class fn_union : public function
{
public:
  fn_union(const signature& sig)
    :
    function(sig, FunctionConsts::OP_UNION_2)
  {
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  bool propagatesInputNodes(expr* fo, csize input) const
  {
    return true;
  }

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return true;
  }

  CODEGEN_DECL();
};


/*******************************************************************************
  For intersect and except, it's always more efficient to sort the output
  and use hash-join than to sort the inputs and use mergesort-join. In this
  case, these 2 function are implemented by the HashSemiJoinIterator. Only if
  the inputs happen to be sorted for a different reason will we use mergesort:
  for $x in path/expr1 for $y in path/expr2 return ($x, $y, ($x intersect $y))

  The HashSemiJoinIterator build a hashmap with the 2nd operand, and probes
  the hashmap with the items in the 1st operand. An item goes into the result
  if a match in the hashmap is found/not found for fn:intersect/fn:except.
  Therefore, the order of the first producer is retained.

  For now, codegen doesn't know whether the inputs are sorted or not.
  TODO: annotate expressions with USE_HASH / USE_MERGESORT properties
  during optimization.
********************************************************************************/
class fn_intersect : public function
{
public:
  fn_intersect(const signature& sig)
    :
    function(sig, FunctionConsts::OP_INTERSECT_2)
  {
  }

  bool propagatesSortedNodes(csize producer) const
  {
    return producer == 0;
  }

  bool propagatesDistinctNodes(csize producer) const
  {
    return producer == 0;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const 
  {
    if (input == 0)
      return fo->getIgnoresSortedNodes();

    return ANNOTATION_TRUE;
  }

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const 
  {
    if (input == 0)
      return fo->getIgnoresDuplicateNodes();

    return ANNOTATION_TRUE;
  }

  bool propagatesInputNodes(expr* fo, csize input) const
  {
    return ANNOTATION_TRUE_FIXED;
  }

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return true;
  }

  CODEGEN_DECL();
};


/*******************************************************************************

********************************************************************************/
class fn_except: public function
{
public:
  fn_except(const signature& sig)
    :
    function(sig, FunctionConsts::OP_EXCEPT_2)
  {
  }

  bool propagatesSortedNodes(csize producer) const
  {
    return producer == 0;
  }

  bool propagatesDistinctNodes(csize producer) const
  {
    return  producer == 0;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const 
  {
    if (input == 0)
      return fo->getIgnoresSortedNodes();

    return ANNOTATION_TRUE;
  }

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const 
  {
    if (input == 0)
      return fo->getIgnoresDuplicateNodes();

    return ANNOTATION_TRUE;
  }

  bool propagatesInputNodes(expr* fo, csize input) const
  {
    return ANNOTATION_TRUE_FIXED;
  }

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return true;
  }

  CODEGEN_DECL();
};


/*******************************************************************************
  15.4.3 fn:max
********************************************************************************/
class fn_max : public function
{
public:
  fn_max(const signature& sig)
    :
    function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
               FunctionConsts::FN_MAX_1 :
               FunctionConsts::FN_MAX_2);
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  CODEGEN_DECL();
};


/*******************************************************************************
  15.4.4 fn:min
********************************************************************************/
class fn_min : public function
{
public:
  fn_min(const signature& sig)
    :
    function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
               FunctionConsts::FN_MIN_1 :
               FunctionConsts::FN_MIN_2);
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  CODEGEN_DECL();
};


/*******************************************************************************
  Fuction is implemented by translator, who turns it into subsequence(arg, 1, 1)
********************************************************************************/
class fn_head : public function
{
public:
  fn_head(const signature& sig)
    :
    function(sig, FunctionConsts::FN_HEAD_1)
  {
    theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  CODEGEN_DECL();
};


/*******************************************************************************
  Fuction is implemented by translator, who turns it into subsequence(arg, 2)
********************************************************************************/
class fn_tail : public function
{
public:
  fn_tail(const signature& sig)
    :
    function(sig, FunctionConsts::FN_TAIL_1)
  {
    theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  CODEGEN_DECL();
};



} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
