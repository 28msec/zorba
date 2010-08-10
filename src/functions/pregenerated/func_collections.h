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


#ifndef ZORBA_FUNCTIONS_COLLECTIONS_H
#define ZORBA_FUNCTIONS_COLLECTIONS_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_collections(static_context* sctx);




//fn:collection
class fn_collection : public function
{
public:
  fn_collection(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 0 ?
                FunctionConsts::FN_COLLECTION_0 :
                FunctionConsts::FN_COLLECTION_1);
  
  }

  bool accessesDynCtx() const { return true; }

  bool isSource() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:collection
class fn_zorba_ddl_collection : public function
{
public:
  fn_zorba_ddl_collection(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_COLLECTION_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  bool isSource() const { return true; }

  FunctionConsts::AnnotationValue producesDistinctNodes() const 
  {
    return FunctionConsts::YES;
  }

  FunctionConsts::AnnotationValue producesSortedNodes() const 
  {
    return FunctionConsts::YES;
  }

  CODEGEN_DECL();
};


//fn-zorba-ddl:index-of
class fn_zorba_ddl_index_of : public function
{
public:
  fn_zorba_ddl_index_of(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_INDEX_OF_2)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:create-collection
class fn_zorba_ddl_create_collection : public function
{
public:
  fn_zorba_ddl_create_collection(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
                FunctionConsts::FN_ZORBA_DDL_CREATE_COLLECTION_1 :
                FunctionConsts::FN_ZORBA_DDL_CREATE_COLLECTION_2);
  
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:delete-collection
class fn_zorba_ddl_delete_collection : public function
{
public:
  fn_zorba_ddl_delete_collection(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_DELETE_COLLECTION_1)
  {
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:insert-nodes
class fn_zorba_ddl_insert_nodes : public function
{
public:
  fn_zorba_ddl_insert_nodes(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_INSERT_NODES_2)
  {
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:insert-nodes-first
class fn_zorba_ddl_insert_nodes_first : public function
{
public:
  fn_zorba_ddl_insert_nodes_first(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_INSERT_NODES_FIRST_2)
  {
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:insert-nodes-last
class fn_zorba_ddl_insert_nodes_last : public function
{
public:
  fn_zorba_ddl_insert_nodes_last(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_INSERT_NODES_LAST_2)
  {
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:insert-nodes-before
class fn_zorba_ddl_insert_nodes_before : public function
{
public:
  fn_zorba_ddl_insert_nodes_before(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_INSERT_NODES_BEFORE_3)
  {
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:insert-nodes-after
class fn_zorba_ddl_insert_nodes_after : public function
{
public:
  fn_zorba_ddl_insert_nodes_after(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_INSERT_NODES_AFTER_3)
  {
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:delete-nodes
class fn_zorba_ddl_delete_nodes : public function
{
public:
  fn_zorba_ddl_delete_nodes(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_DDL_DELETE_NODES_2)
  {
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:delete-node-first
class fn_zorba_ddl_delete_node_first : public function
{
public:
  fn_zorba_ddl_delete_node_first(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
                FunctionConsts::FN_ZORBA_DDL_DELETE_NODE_FIRST_1 :
                FunctionConsts::FN_ZORBA_DDL_DELETE_NODES_FIRST_2);
  
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-ddl:delete-node-last
class fn_zorba_ddl_delete_node_last : public function
{
public:
  fn_zorba_ddl_delete_node_last(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
                FunctionConsts::FN_ZORBA_DDL_DELETE_NODE_LAST_1 :
                FunctionConsts::FN_ZORBA_DDL_DELETE_NODES_LAST_2);
  
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

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
