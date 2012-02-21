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


#ifndef ZORBA_FUNCTIONS_SEQUENCES_H
#define ZORBA_FUNCTIONS_SEQUENCES_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_sequences(static_context* sctx);




//op:concatenate
class op_concatenate : public function
{
public:
  op_concatenate(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:index-of
class fn_index_of : public function
{
public:
  fn_index_of(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:empty
class fn_empty : public function
{
public:
  fn_empty(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:exists
class fn_exists : public function
{
public:
  fn_exists(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:distinct-values
class fn_distinct_values : public function
{
public:
  fn_distinct_values(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};


//fn:insert-before
class fn_insert_before : public function
{
public:
  fn_insert_before(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:remove
class fn_remove : public function
{
public:
  fn_remove(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  bool propagatesDistinctNodes(csize producer) const { return producer == 0; }

  bool propagatesSortedNodes(csize producer) const { return producer == 0; }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:reverse
class fn_reverse : public function
{
public:
  fn_reverse(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  bool propagatesDistinctNodes(csize producer) const { return producer == 0; }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:subsequence
class fn_subsequence : public function
{
public:
  fn_subsequence(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  bool propagatesDistinctNodes(csize producer) const { return producer == 0; }

  bool propagatesSortedNodes(csize producer) const { return producer == 0; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  bool serializable() const { return true; }

  CODEGEN_DECL();
};


//op-zorba:subsequence-int
class op_zorba_subsequence_int : public function
{
public:
  op_zorba_subsequence_int(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  bool propagatesDistinctNodes(csize producer) const { return producer == 0; }

  bool propagatesSortedNodes(csize producer) const { return producer == 0; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//op-zorba:sequence-point-access
class op_zorba_sequence_point_access : public function
{
public:
  op_zorba_sequence_point_access(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  bool propagatesDistinctNodes(csize producer) const { return producer == 0; }

  bool propagatesSortedNodes(csize producer) const { return producer == 0; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:zero-or-one
class fn_zero_or_one : public function
{
public:
  fn_zero_or_one(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:one-or-more
class fn_one_or_more : public function
{
public:
  fn_one_or_more(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  bool isMap(ulong producer) const { return producer == 0; }

  bool propagatesDistinctNodes(csize producer) const { return producer == 0; }

  bool propagatesSortedNodes(csize producer) const { return producer == 0; }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:deep-equal
class fn_deep_equal : public function
{
public:
  fn_deep_equal(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:count
class fn_count : public function
{
public:
  fn_count(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:avg
class fn_avg : public function
{
public:
  fn_avg(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};


//fn:sum
class fn_sum : public function
{
public:
  fn_sum(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool specializable() const { return true; }

  function* specialize( static_context* sctx,
                        const std::vector<xqtref_t>& argTypes) const;

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};


//op:sum_double
class op_sum_double : public function
{
public:
  op_sum_double(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};


//op:sum_float
class op_sum_float : public function
{
public:
  op_sum_float(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};


//op:sum_decimal
class op_sum_decimal : public function
{
public:
  op_sum_decimal(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};


//op:sum_integer
class op_sum_integer : public function
{
public:
  op_sum_integer(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};


//op:to
class op_to : public function
{
public:
  op_to(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:id
class fn_id : public function
{
public:
  fn_id(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  FunctionConsts::AnnotationValue producesDistinctNodes() const 
  {
    return FunctionConsts::YES;
  }

  FunctionConsts::AnnotationValue producesSortedNodes() const 
  {
    return FunctionConsts::YES;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 1; }

  CODEGEN_DECL();
};


//fn:element-with-id
class fn_element_with_id : public function
{
public:
  fn_element_with_id(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  FunctionConsts::AnnotationValue producesDistinctNodes() const 
  {
    return FunctionConsts::YES;
  }

  FunctionConsts::AnnotationValue producesSortedNodes() const 
  {
    return FunctionConsts::YES;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 1; }

  CODEGEN_DECL();
};


//fn:idref
class fn_idref : public function
{
public:
  fn_idref(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  FunctionConsts::AnnotationValue producesDistinctNodes() const 
  {
    return FunctionConsts::YES;
  }

  FunctionConsts::AnnotationValue producesSortedNodes() const 
  {
    return FunctionConsts::YES;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 1; }

  CODEGEN_DECL();
};


//fn:doc
class fn_doc : public function
{
public:
  fn_doc(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  bool isSource() const { return true; }

  CODEGEN_DECL();
};


//fn:doc-available
class fn_doc_available : public function
{
public:
  fn_doc_available(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:available-environment-variables
class fn_available_environment_variables : public function
{
public:
  fn_available_environment_variables(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:environment-variable
class fn_environment_variable : public function
{
public:
  fn_environment_variable(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
