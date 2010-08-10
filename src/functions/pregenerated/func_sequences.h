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


namespace zorba {


void populate_context_sequences(static_context* sctx);




//op:concatenate
class op_concatenate : public function
{
public:
  op_concatenate(const signature& sig)
    :
    function(sig, FunctionConsts::OP_CONCATENATE_N)
  {
  }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;

  COMPUTE_ANNOTATION_DECL();

  CODEGEN_DECL();
};


//fn:index-of
class fn_index_of : public function
{
public:
  fn_index_of(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 2 ?
                FunctionConsts::FN_INDEX_OF_2 :
                FunctionConsts::FN_INDEX_OF_3);
  
  }

  CODEGEN_DECL();
};


//fn:empty
class fn_empty : public function
{
public:
  fn_empty(const signature& sig)
    :
    function(sig, FunctionConsts::FN_EMPTY_1)
  {
  }

  CODEGEN_DECL();
};


//fn:exists
class fn_exists : public function
{
public:
  fn_exists(const signature& sig)
    :
    function(sig, FunctionConsts::FN_EXISTS_1)
  {
  }

  CODEGEN_DECL();
};


//fn:distinct-values
class fn_distinct_values : public function
{
public:
  fn_distinct_values(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 2 ?
                FunctionConsts::FN_DISTINCT_VALUES_2 :
                FunctionConsts::FN_DISTINCT_VALUES_1);
  
  }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;

  CODEGEN_DECL();
};


//fn:insert-before
class fn_insert_before : public function
{
public:
  fn_insert_before(const signature& sig)
    :
    function(sig, FunctionConsts::FN_INSERT_BEFORE_3)
  {
  }

  CODEGEN_DECL();
};


//fn:remove
class fn_remove : public function
{
public:
  fn_remove(const signature& sig)
    :
    function(sig, FunctionConsts::FN_REMOVE_2)
  {
  }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;

  bool propagatesDistinctNodes(ulong producer) const { return producer == 0; }

  bool propagatesSortedNodes(ulong producer) const { return producer == 0; }

  CODEGEN_DECL();
};


//fn:reverse
class fn_reverse : public function
{
public:
  fn_reverse(const signature& sig)
    :
    function(sig, FunctionConsts::FN_REVERSE_1)
  {
  }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;

  bool propagatesDistinctNodes(ulong producer) const { return producer == 0; }

  CODEGEN_DECL();
};


//fn:subsequence
class fn_subsequence : public function
{
public:
  fn_subsequence(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 2 ?
                FunctionConsts::FN_SUBSEQUENCE_2 :
                FunctionConsts::FN_SUBSEQUENCE_3);
  
  }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;

  bool propagatesDistinctNodes(ulong producer) const { return producer == 0; }

  bool propagatesSortedNodes(ulong producer) const { return producer == 0; }

  COMPUTE_ANNOTATION_DECL();

  CODEGEN_DECL();
};


//fn-zorba:subsequence-int
class fn_zorba_subsequence_int : public function
{
public:
  fn_zorba_subsequence_int(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 2 ?
                FunctionConsts::FN_ZORBA_SUBSEQUENCE_INT_2 :
                FunctionConsts::FN_ZORBA_SUBSEQUENCE_INT_3);
  
  }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;

  bool propagatesDistinctNodes(ulong producer) const { return producer == 0; }

  bool propagatesSortedNodes(ulong producer) const { return producer == 0; }

  COMPUTE_ANNOTATION_DECL();

  CODEGEN_DECL();
};


//fn-zorba:sequence-point-access
class fn_zorba_sequence_point_access : public function
{
public:
  fn_zorba_sequence_point_access(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_SEQUENCE_POINT_ACCESS_2)
  {
  }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;

  bool propagatesDistinctNodes(ulong producer) const { return producer == 0; }

  bool propagatesSortedNodes(ulong producer) const { return producer == 0; }

  COMPUTE_ANNOTATION_DECL();

  CODEGEN_DECL();
};


//fn:zero-or-one
class fn_zero_or_one : public function
{
public:
  fn_zero_or_one(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZERO_OR_ONE_1)
  {
  }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;

  CODEGEN_DECL();
};


//fn:one-or-more
class fn_one_or_more : public function
{
public:
  fn_one_or_more(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ONE_OR_MORE_1)
  {
  }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;

  bool isMap(ulong producer) const { return producer == 0; }

  bool propagatesDistinctNodes(ulong producer) const { return producer == 0; }

  bool propagatesSortedNodes(ulong producer) const { return producer == 0; }

  CODEGEN_DECL();
};


//fn:deep-equal
class fn_deep_equal : public function
{
public:
  fn_deep_equal(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 2 ?
                FunctionConsts::FN_DEEP_EQUAL_2 :
                FunctionConsts::FN_DEEP_EQUAL_3);
  
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn:count
class fn_count : public function
{
public:
  fn_count(const signature& sig)
    :
    function(sig, FunctionConsts::FN_COUNT_1)
  {
  }

  CODEGEN_DECL();
};


//fn:avg
class fn_avg : public function
{
public:
  fn_avg(const signature& sig)
    :
    function(sig, FunctionConsts::FN_AVG_1)
  {
  }

  CODEGEN_DECL();
};


//fn:sum
class fn_sum : public function
{
public:
  fn_sum(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
                FunctionConsts::FN_SUM_1 :
                FunctionConsts::FN_SUM_2);
  
  }

  bool specializable() const { return true; }

  function* specialize( static_context* sctx,
                        const std::vector<xqtref_t>& argTypes) const;

  CODEGEN_DECL();
};


//fn:sum_double
class fn_sum_double : public function
{
public:
  fn_sum_double(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
                FunctionConsts::FN_SUM_DOUBLE_1 :
                FunctionConsts::FN_SUM_DOUBLE_2);
  
  }

  CODEGEN_DECL();
};


//fn:sum_float
class fn_sum_float : public function
{
public:
  fn_sum_float(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
                FunctionConsts::FN_SUM_FLOAT_1 :
                FunctionConsts::FN_SUM_FLOAT_2);
  
  }

  CODEGEN_DECL();
};


//fn:sum_decimal
class fn_sum_decimal : public function
{
public:
  fn_sum_decimal(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
                FunctionConsts::FN_SUM_DECIMAL_1 :
                FunctionConsts::FN_SUM_DECIMAL_2);
  
  }

  CODEGEN_DECL();
};


//fn:sum_integer
class fn_sum_integer : public function
{
public:
  fn_sum_integer(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
                FunctionConsts::FN_SUM_INTEGER_1 :
                FunctionConsts::FN_SUM_INTEGER_2);
  
  }

  CODEGEN_DECL();
};


//op:to
class op_to : public function
{
public:
  op_to(const signature& sig)
    :
    function(sig, FunctionConsts::OP_TO_2)
  {
  }

  CODEGEN_DECL();
};


//fn:doc
class fn_doc : public function
{
public:
  fn_doc(const signature& sig)
    :
    function(sig, FunctionConsts::FN_DOC_1)
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
  fn_doc_available(const signature& sig)
    :
    function(sig, FunctionConsts::FN_DOC_AVAILABLE_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-util:parse
class fn_zorba_util_parse : public function
{
public:
  fn_zorba_util_parse(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_UTIL_PARSE_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  bool isSource() const { return true; }

  CODEGEN_DECL();
};


//fn:parse
class fn_parse : public function
{
public:
  fn_parse(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
                FunctionConsts::FN_PARSE_1 :
                FunctionConsts::FN_PARSE_2);
  
  }

  bool accessesDynCtx() const { return true; }

  bool isSource() const { return true; }

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
