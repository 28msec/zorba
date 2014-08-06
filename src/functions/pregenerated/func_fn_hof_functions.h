/*
 * Copyright 2006-2012 The FLWOR Foundation.
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



#ifndef ZORBA_FUNCTIONS_FN_HOF_FUNCTIONS_H
#define ZORBA_FUNCTIONS_FN_HOF_FUNCTIONS_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_fn_hof_functions(static_context* sctx);




//fn:function-lookup
class fn_function_lookup_3_0 : public function
{
public:
  fn_function_lookup_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  CODEGEN_DECL();
};


//op-zorba:function-lookup
class op_zorba_function_lookup_3_0 : public function
{
public:
  op_zorba_function_lookup_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  CODEGEN_DECL();
};


//fn:function-name
class fn_function_name_3_0 : public function
{
public:
  fn_function_name_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  CODEGEN_DECL();
};


//fn:function-arity
class fn_function_arity_3_0 : public function
{
public:
  fn_function_arity_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  CODEGEN_DECL();
};


//fn:for-each-pair
class fn_for_each_pair_3_0 : public function
{
public:
  fn_for_each_pair_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  CODEGEN_DECL();
};


//fn:fold-left
class fn_fold_left_3_0 : public function
{
public:
  fn_fold_left_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  CODEGEN_DECL();
};


//fn:fold-right
class fn_fold_right_3_0 : public function
{
public:
  fn_fold_right_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
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
