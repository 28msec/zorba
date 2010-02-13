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


#ifndef ZORBA_FUNCTIONS_INDEX_DDL_H
#define ZORBA_FUNCTIONS_INDEX_DDL_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_index_ddl(static_context* sctx);




//fn-zorba-ddl:create-index
class fn_zorba_ddl_create_index : public function
{
public:
  fn_zorba_ddl_create_index(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_CREATE_INDEX_1)
  {
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:delete-index
class fn_zorba_ddl_delete_index : public function
{
public:
  fn_zorba_ddl_delete_index(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_DELETE_INDEX_1)
  {
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//op:create-internal-index
class op_create_internal_index : public function
{
public:
  op_create_internal_index(const signature& sig)
    :
    function(sig, FunctionConsts::OP_CREATE_INTERNAL_INDEX_2)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:refresh-index
class fn_zorba_ddl_refresh_index : public function
{
public:
  fn_zorba_ddl_refresh_index(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_REFRESH_INDEX_1)
  {
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//op:index-entry-builder
class op_index_entry_builder : public function
{
public:
  op_index_entry_builder(const signature& sig)
    :
    function(sig, FunctionConsts::OP_INDEX_ENTRY_BUILDER_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:probe-index-point
class fn_zorba_ddl_probe_index_point : public function
{
public:
  fn_zorba_ddl_probe_index_point(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_PROBE_INDEX_POINT_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  FunctionConsts::AnnotationValue producesDistinctNodes() const 
  {
    return FunctionConsts::YES;
  }

  CODEGEN_DECL();
};


//fn-zorba-ddl:probe-index-range
class fn_zorba_ddl_probe_index_range : public function
{
public:
  fn_zorba_ddl_probe_index_range(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_PROBE_INDEX_RANGE_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  FunctionConsts::AnnotationValue producesDistinctNodes() const 
  {
    return FunctionConsts::YES;
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
