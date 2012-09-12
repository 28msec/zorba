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




//static-collections-ddl:create
class static_collections_ddl_create : public function
{
public:
  static_collections_ddl_create(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 1; }

  CODEGEN_DECL();
};


//static-collections-ddl:delete
class static_collections_ddl_delete : public function
{
public:
  static_collections_ddl_delete(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//static-collections-ddl:is-available-collection
class static_collections_ddl_is_available_collection : public function
{
public:
  static_collections_ddl_is_available_collection(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//static-collections-ddl:available-collections
class static_collections_ddl_available_collections : public function
{
public:
  static_collections_ddl_available_collections(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn:collection
class fn_collection : public function
{
public:
  fn_collection(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  bool isSource() const { return true; }

  CODEGEN_DECL();
};


//static-collections-dml:collection
class static_collections_dml_collection : public function
{
public:
  static_collections_dml_collection(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
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


//static-collections-dml:collection-name
class static_collections_dml_collection_name : public function
{
public:
  static_collections_dml_collection_name(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//static-collections-dml:index-of
class static_collections_dml_index_of : public function
{
public:
  static_collections_dml_index_of(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//static-collections-dml:insert-nodes
class static_collections_dml_insert_nodes : public function
{
public:
  static_collections_dml_insert_nodes(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 1; }

  CODEGEN_DECL();
};


//static-collections-dml:insert-nodes-first
class static_collections_dml_insert_nodes_first : public function
{
public:
  static_collections_dml_insert_nodes_first(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 1; }

  CODEGEN_DECL();
};


//static-collections-dml:insert-nodes-last
class static_collections_dml_insert_nodes_last : public function
{
public:
  static_collections_dml_insert_nodes_last(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 1; }

  CODEGEN_DECL();
};


//static-collections-dml:insert-nodes-before
class static_collections_dml_insert_nodes_before : public function
{
public:
  static_collections_dml_insert_nodes_before(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 2; }

  CODEGEN_DECL();
};


//static-collections-dml:insert-nodes-after
class static_collections_dml_insert_nodes_after : public function
{
public:
  static_collections_dml_insert_nodes_after(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 2; }

  CODEGEN_DECL();
};


//static-collections-dml:apply-insert-nodes
class static_collections_dml_apply_insert_nodes : public function
{
public:
  static_collections_dml_apply_insert_nodes(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return APPLYING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool propagatesInputNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 1; }

  CODEGEN_DECL();
};


//static-collections-dml:apply-insert-nodes-first
class static_collections_dml_apply_insert_nodes_first : public function
{
public:
  static_collections_dml_apply_insert_nodes_first(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return APPLYING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool propagatesInputNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 1; }

  CODEGEN_DECL();
};


//static-collections-dml:apply-insert-nodes-last
class static_collections_dml_apply_insert_nodes_last : public function
{
public:
  static_collections_dml_apply_insert_nodes_last(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return APPLYING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool propagatesInputNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 1; }

  void processPragma(expr*, const std::vector<pragma*>&) const;

  CODEGEN_DECL();
};


//static-collections-dml:apply-insert-nodes-before
class static_collections_dml_apply_insert_nodes_before : public function
{
public:
  static_collections_dml_apply_insert_nodes_before(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return APPLYING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool propagatesInputNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 2; }

  CODEGEN_DECL();
};


//static-collections-dml:apply-insert-nodes-after
class static_collections_dml_apply_insert_nodes_after : public function
{
public:
  static_collections_dml_apply_insert_nodes_after(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return APPLYING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool propagatesInputNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 2; }

  CODEGEN_DECL();
};


//static-collections-dml:delete-nodes
class static_collections_dml_delete_nodes : public function
{
public:
  static_collections_dml_delete_nodes(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 0; }

  CODEGEN_DECL();
};


//static-collections-dml:delete-node-first
class static_collections_dml_delete_node_first : public function
{
public:
  static_collections_dml_delete_node_first(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//static-collections-dml:delete-node-last
class static_collections_dml_delete_node_last : public function
{
public:
  static_collections_dml_delete_node_last(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//static-collections-dml:truncate
class static_collections_dml_truncate : public function
{
public:
  static_collections_dml_truncate(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-indexes-static-ddl:is-available-index
class zorba_store_indexes_static_ddl_is_available_index : public function
{
public:
  zorba_store_indexes_static_ddl_is_available_index(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-indexes-static-ddl:available-indexes
class zorba_store_indexes_static_ddl_available_indexes : public function
{
public:
  zorba_store_indexes_static_ddl_available_indexes(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-integrity_constraints-static-ddl:is-activated-integrity-constraint
class zorba_store_integrity_constraints_static_ddl_is_activated_integrity_constraint : public function
{
public:
  zorba_store_integrity_constraints_static_ddl_is_activated_integrity_constraint(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-integrity_constraints-static-ddl:activated-integrity-constraints
class zorba_store_integrity_constraints_static_ddl_activated_integrity_constraints : public function
{
public:
  zorba_store_integrity_constraints_static_ddl_activated_integrity_constraints(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//static-collections-ddl:is-declared-collection
class static_collections_ddl_is_declared_collection : public function
{
public:
  static_collections_ddl_is_declared_collection(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//static-collections-ddl:declared-collections
class static_collections_ddl_declared_collections : public function
{
public:
  static_collections_ddl_declared_collections(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//zorba-store-indexes-static-ddl:is-declared-index
class zorba_store_indexes_static_ddl_is_declared_index : public function
{
public:
  zorba_store_indexes_static_ddl_is_declared_index(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//zorba-store-indexes-static-ddl:declared-indexes
class zorba_store_indexes_static_ddl_declared_indexes : public function
{
public:
  zorba_store_indexes_static_ddl_declared_indexes(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//zorba-store-integrity_constraints-static-ddl:is-declared-integrity-constraint
class zorba_store_integrity_constraints_static_ddl_is_declared_integrity_constraint : public function
{
public:
  zorba_store_integrity_constraints_static_ddl_is_declared_integrity_constraint(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//zorba-store-integrity_constraints-static-ddl:declared-integrity-constraints
class zorba_store_integrity_constraints_static_ddl_declared_integrity_constraints : public function
{
public:
  zorba_store_integrity_constraints_static_ddl_declared_integrity_constraints(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:uri-collection
class fn_uri_collection_3_0 : public function
{
public:
  fn_uri_collection_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
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
