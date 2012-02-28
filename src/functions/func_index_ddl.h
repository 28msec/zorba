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
#ifndef ZORBA_FUNCTIONS_INDEX_DDL_H
#define ZORBA_FUNCTIONS_INDEX_DDL_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba 
{

void populate_context_index_ddl(static_context* sctx);


/*******************************************************************************
  op:create-internal-index($indexName as xs:QName, $items as item*)

  The second param is bound to an exparession of the form :

  for $dot at $pos in domain_expr
  return index-entry-builder($$dot, key1_expr, ..., keyN_expr)
********************************************************************************/
class op_create_internal_index : public function
{
public:
  op_create_internal_index(const signature& sig)
    :
    function(sig, FunctionConsts::OP_CREATE_INTERNAL_INDEX_2)
  {
  }

  short getScriptingKind() const { return SIMPLE_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize input) const { return false; }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  CODEGEN_DECL();
};


/*******************************************************************************
  fn-zorba-ddl:create($indexName as xs:QName)
********************************************************************************/
class fn_zorba_ddl_create_index : public function
{
public:
  fn_zorba_ddl_create_index(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_XQDDF_CREATE_INDEX_1)
  {
  }

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


/*******************************************************************************
  fn-zorba-ddl:delete($indexName as xs:QName)
********************************************************************************/
class fn_zorba_ddl_delete_index : public function
{
public:
  fn_zorba_ddl_delete_index(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_XQDDF_DELETE_INDEX_1)
  {
  }

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


/*******************************************************************************
  fn-zorba-ddl:refresh-index($indexName as xs:QName)
********************************************************************************/
class fn_zorba_ddl_refresh_index : public function
{
public:
  fn_zorba_ddl_refresh_index(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_XQDDF_REFRESH_INDEX_1)
  {
  }

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


/*******************************************************************************
  op:value-index-entry-builder($node as node(), .....)

  This is a variadic function. The 1st input is a domain node, and the rest of
  the inputs are the key items that comprise the key tuple for that node
********************************************************************************/
class op_value_index_entry_builder : public function
{
public:
  op_value_index_entry_builder(const signature& sig)
    :
    function(sig, FunctionConsts::OP_VALUE_INDEX_ENTRY_BUILDER_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize input) const { return false; }

  CODEGEN_DECL();
};


/*******************************************************************************
  op:general-index-entry-builder($node as node(), .....)
********************************************************************************/
class op_general_index_entry_builder : public function
{
public:
  op_general_index_entry_builder(const signature& sig)
    :
    function(sig, FunctionConsts::OP_GENERAL_INDEX_ENTRY_BUILDER_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize input) const {  return false;  }

  CODEGEN_DECL();
};


/*******************************************************************************
  fn-zorba-ddl:probe-index-point-value(
      $indexName as xs:QName, 
      $key1 as xs:anyAtomicItem?,
      ....
      $keyN as xs:anyAtomicItem?) as node()*

  Note: the translator wraps calls to this function with an OP_NODE_SORT_ASC
  function.
********************************************************************************/
class fn_zorba_ddl_probe_index_point_value : public function
{
public:
  fn_zorba_ddl_probe_index_point_value(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_POINT_VALUE_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  FunctionConsts::AnnotationValue producesDistinctNodes() const 
  {
    return FunctionConsts::YES;
  }

  CODEGEN_DECL();
};


/*******************************************************************************
  fn-zorba-ddl:probe-index-point-general(
      $indexName as xs:QName,
      $keys      as xs:anyAtomicItem*) as node()*

  Note: the translator wraps calls to this function with an OP_NODE_SORT_DISTINCT_ASC
  function.
********************************************************************************/
class fn_zorba_ddl_probe_index_point_general : public function
{
public:
  fn_zorba_ddl_probe_index_point_general(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_POINT_GENERAL_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


/*******************************************************************************
  fn-zorba-ddl:probe-index-range-value(
      $indexName as xs:QName, ....) as node()*

  Note: the translator wraps calls to this function with an OP_NODE_SORT_ASC
  function.
********************************************************************************/
class fn_zorba_ddl_probe_index_range_value : public function
{
public:
  fn_zorba_ddl_probe_index_range_value(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_VALUE_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  FunctionConsts::AnnotationValue producesDistinctNodes() const 
  {
    return FunctionConsts::YES;
  }

  CODEGEN_DECL();
};


/*******************************************************************************
  fn-zorba-ddl:probe-index-range-general(
      $indexName           as xs:QName, 
      $lowerBoundKeys      as xs:anyAtomicType*,
      $upperBoundKeys      as xs:anyAtomicType*,
      $haveLowerBound      as xs:boolean,
      $haveUpperBound      as xs:boolean,
      $lowerBoundIncluded  as xs:boolean,
      $upperBoundIncluded  as xs:boolean) as node()*

  Note: the translator wraps calls to this function with an OP_NODE_SORT_DISTINCT_ASC
  function.
********************************************************************************/
class fn_zorba_ddl_probe_index_range_general : public function
{
public:
  fn_zorba_ddl_probe_index_range_general(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_GENERAL_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
/* vim:set et sw=2 ts=2: */
