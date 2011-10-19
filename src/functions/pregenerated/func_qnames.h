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


#ifndef ZORBA_FUNCTIONS_QNAMES_H
#define ZORBA_FUNCTIONS_QNAMES_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_qnames(static_context* sctx);




//fn:resolve-QName
class fn_resolve_QName : public function
{
public:
  fn_resolve_QName(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn:QName
class fn_QName : public function
{
public:
  fn_QName(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//op:QName-equal
class op_QName_equal : public function
{
public:
  op_QName_equal(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn:prefix-from-QName
class fn_prefix_from_QName : public function
{
public:
  fn_prefix_from_QName(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn:local-name-from-QName
class fn_local_name_from_QName : public function
{
public:
  fn_local_name_from_QName(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn:namespace-uri-from-QName
class fn_namespace_uri_from_QName : public function
{
public:
  fn_namespace_uri_from_QName(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn:namespace-uri-for-prefix
class fn_namespace_uri_for_prefix : public function
{
public:
  fn_namespace_uri_for_prefix(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn:in-scope-prefixes
class fn_in_scope_prefixes : public function
{
public:
  fn_in_scope_prefixes(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

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
