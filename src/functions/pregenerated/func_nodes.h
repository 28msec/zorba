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




//zorba-node-identifier:node-identifier
class zorba_node_identifier_node_identifier : public function
{
public:
  zorba_node_identifier_node_identifier(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-node-identifier:current-node-identifier
class zorba_node_identifier_current_node_identifier : public function
{
public:
  zorba_node_identifier_current_node_identifier(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-node-identifier:has-identifier
class zorba_node_identifier_has_identifier : public function
{
public:
  zorba_node_identifier_has_identifier(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-node-identifier:node-by-identifier
class zorba_node_identifier_node_by_identifier : public function
{
public:
  zorba_node_identifier_node_by_identifier(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


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


//fn:generate-id
class fn_generate_id_3_0 : public function
{
public:
  fn_generate_id_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
}

  CODEGEN_DECL();
};


//fn-zorba-node:ancestor-of
class fn_zorba_node_ancestor_of : public function
{
public:
  fn_zorba_node_ancestor_of(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn-zorba-node:descendant-of
class fn_zorba_node_descendant_of : public function
{
public:
  fn_zorba_node_descendant_of(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn-zorba-node:parent-of
class fn_zorba_node_parent_of : public function
{
public:
  fn_zorba_node_parent_of(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn-zorba-node:child-of
class fn_zorba_node_child_of : public function
{
public:
  fn_zorba_node_child_of(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn-zorba-node:following-of
class fn_zorba_node_following_of : public function
{
public:
  fn_zorba_node_following_of(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn-zorba-node:preceding-of
class fn_zorba_node_preceding_of : public function
{
public:
  fn_zorba_node_preceding_of(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn-zorba-node:following-sibling-of
class fn_zorba_node_following_sibling_of : public function
{
public:
  fn_zorba_node_following_sibling_of(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn-zorba-node:preceding-sibling-of
class fn_zorba_node_preceding_sibling_of : public function
{
public:
  fn_zorba_node_preceding_sibling_of(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn-zorba-node:level
class fn_zorba_node_level : public function
{
public:
  fn_zorba_node_level(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn-zorba-node:least-common-ancestor
class fn_zorba_node_least_common_ancestor : public function
{
public:
  fn_zorba_node_least_common_ancestor(const signature& sig, FunctionConsts::FunctionKind kind)
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
