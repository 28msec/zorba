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


#ifndef ZORBA_FUNCTIONS_NODES_H
#define ZORBA_FUNCTIONS_NODES_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_nodes(static_context* sctx);




//fn-zorba-ref:node-reference
class fn_zorba_ref_node_reference : public function
{
public:
  fn_zorba_ref_node_reference(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn-zorba-ref:node-by-reference
class fn_zorba_ref_node_by_reference : public function
{
public:
  fn_zorba_ref_node_by_reference(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn:local-name
class fn_local_name : public function
{
public:
  fn_local_name(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn:namespace-uri
class fn_namespace_uri : public function
{
public:
  fn_namespace_uri(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn:lang
class fn_lang : public function
{
public:
  fn_lang(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn:number
class fn_number : public function
{
public:
  fn_number(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn:has-children
class fn_has_children_3_0 : public function
{
public:
  fn_has_children_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
}

  CODEGEN_DECL();
};


//fn:innermost
class fn_innermost_3_0 : public function
{
public:
  fn_innermost_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
}

  CODEGEN_DECL();
};


//fn:outermost
class fn_outermost_3_0 : public function
{
public:
  fn_outermost_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {
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
