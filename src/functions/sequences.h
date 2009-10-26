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
#include "functions/single_seq_func.h"


namespace zorba{


void populate_context_sequences(static_context* sctx);



//op:concatenate
class op_concatenate : public function
{
public:
  op_concatenate(const signature& sig) : function(sig, FunctionConsts::FN_CONCATENATE) {}

  CODEGEN_DECL();

  xqtref_t return_type(const std::vector<xqtref_t>& arg_types) const;

  void compute_annotation(AnnotationHolder* parent,
                          std::vector<AnnotationHolder *>& kids,
                          Annotations::Key k) const;
};

//fn:index-of
class fn_index_of : public function
{
public:
  fn_index_of(const signature& sig) : function(sig, FunctionConsts::FN_INDEX_OF) {}

  CODEGEN_DECL();
};

//fn:empty
class fn_empty : public function
{
public:
  fn_empty(const signature& sig) : function(sig, FunctionConsts::FN_EMPTY) {}

  CODEGEN_DECL();
};

//fn:exists
class fn_exists : public function
{
public:
  fn_exists(const signature& sig) : function(sig, FunctionConsts::FN_EXISTS) {}

  CODEGEN_DECL();
};

//fn:insert-before
class fn_insert_before : public function
{
public:
  fn_insert_before(const signature& sig) : function(sig, FunctionConsts::FN_INSERT_BEFORE) {}

  CODEGEN_DECL();
};

//fn:remove
class fn_remove : public single_seq_opt_function
{
public:
  fn_remove(const signature& sig) : single_seq_opt_function(sig, FunctionConsts::FN_REMOVE) {}

  CODEGEN_DECL();
};

//fn:reverse
class fn_reverse : public single_seq_opt_function
{
public:
  fn_reverse(const signature& sig) : single_seq_opt_function(sig, FunctionConsts::FN_REVERSE) {}

  FunctionConsts::AnnotationValue producesNodeIdSorted() const {
    return FunctionConsts::NO;
  }

  CODEGEN_DECL();
};

//fn:subsequence
class fn_subsequence : public single_seq_opt_function
{
public:
  fn_subsequence(const signature& sig) : single_seq_opt_function(sig, FunctionConsts::FN_SUBSEQUENCE) {}

  CODEGEN_DECL();

  void compute_annotation(AnnotationHolder* parent,
                          std::vector<AnnotationHolder *>& kids,
                          Annotations::Key k) const;
};

//fn:zero-or-one
class fn_zero_or_one : public function
{
public:
  fn_zero_or_one(const signature& sig) : function(sig, FunctionConsts::FN_ZERO_OR_ONE) {}

  CODEGEN_DECL();

  xqtref_t return_type(const std::vector<xqtref_t>& arg_types) const;
};

//fn:one-or-more
class fn_one_or_more : public single_seq_opt_function
{
public:
  fn_one_or_more(const signature& sig) : single_seq_opt_function(sig, FunctionConsts::FN_ONE_OR_MORE) {}

  CODEGEN_DECL();
};

//fn:deep-equal
class fn_deep_equal : public function
{
public:
  fn_deep_equal(const signature& sig) : function(sig, FunctionConsts::FN_DEEP_EQUAL) {}

  CODEGEN_DECL();
};

//fn:count
class fn_count : public function
{
public:
  fn_count(const signature& sig) : function(sig, FunctionConsts::FN_COUNT) {}

  CODEGEN_DECL();
};

//fn:avg
class fn_avg : public function
{
public:
  fn_avg(const signature& sig) : function(sig, FunctionConsts::FN_AVG) {}

  CODEGEN_DECL();
};

//fn:sum
class fn_sum : public function
{
public:
  fn_sum(const signature& sig) : function(sig, FunctionConsts::FN_SUM) {}

  bool specializable() const { return true; }

  function* specialize( static_context* sctx,
                        const std::vector<xqtref_t>& argTypes) const;

  CODEGEN_DECL();
};

//fn:sum_double
class fn_sum_double : public function
{
public:
  fn_sum_double(const signature& sig) : function(sig, FunctionConsts::FN_SUM_DOUBLE) {}

  CODEGEN_DECL();
};

//fn:sum_float
class fn_sum_float : public function
{
public:
  fn_sum_float(const signature& sig) : function(sig, FunctionConsts::FN_SUM_FLOAT) {}

  CODEGEN_DECL();
};

//fn:sum_decimal
class fn_sum_decimal : public function
{
public:
  fn_sum_decimal(const signature& sig) : function(sig, FunctionConsts::FN_SUM_DECIMAL) {}

  CODEGEN_DECL();
};

//fn:sum_integer
class fn_sum_integer : public function
{
public:
  fn_sum_integer(const signature& sig) : function(sig, FunctionConsts::FN_SUM_INTEGER) {}

  CODEGEN_DECL();
};

//op:to
class op_to : public function
{
public:
  op_to(const signature& sig) : function(sig, FunctionConsts::FN_TO) {}

  CODEGEN_DECL();
};

//fn:doc
class fn_doc : public function
{
public:
  fn_doc(const signature& sig) : function(sig, FunctionConsts::FN_DOC) {}

  bool requires_dyn_ctx () const { return true; }

  virtual bool isSource() const { return true; }

  CODEGEN_DECL();

  bool propagatesInputToOutput(uint32_t aProducer) const;
};

//fn:doc-available
class fn_doc_available : public function
{
public:
  fn_doc_available(const signature& sig) : function(sig, FunctionConsts::FN_DOC_AVAILABLE) {}

  CODEGEN_DECL();
};

//fn-zorba-util:parse
class fn_zorba_util_parse : public function
{
public:
  fn_zorba_util_parse(const signature& sig) : function(sig, FunctionConsts::FN_ZORBA_UTIL_PARSE) {}

  bool requires_dyn_ctx () const { return true; }

  virtual bool isSource() const { return true; }

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
