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
  fn_collection(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  bool accessesDynCtx() const { return true; }

  bool isSource() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:collection
class zorba_store_collections_static_manip_collection : public function
{
public:
  zorba_store_collections_static_manip_collection(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

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


//zorba-store-collections-static-manip:index-of
class zorba_store_collections_static_manip_index_of : public function
{
public:
  zorba_store_collections_static_manip_index_of(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-init:create-collection
class zorba_store_collections_static_init_create_collection : public function
{
public:
  zorba_store_collections_static_init_create_collection(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-init:delete-collection
class zorba_store_collections_static_init_delete_collection : public function
{
public:
  zorba_store_collections_static_init_delete_collection(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:insert-nodes
class zorba_store_collections_static_manip_insert_nodes : public function
{
public:
  zorba_store_collections_static_manip_insert_nodes(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:insert-nodes-first
class zorba_store_collections_static_manip_insert_nodes_first : public function
{
public:
  zorba_store_collections_static_manip_insert_nodes_first(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:insert-nodes-last
class zorba_store_collections_static_manip_insert_nodes_last : public function
{
public:
  zorba_store_collections_static_manip_insert_nodes_last(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:insert-nodes-before
class zorba_store_collections_static_manip_insert_nodes_before : public function
{
public:
  zorba_store_collections_static_manip_insert_nodes_before(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:insert-nodes-after
class zorba_store_collections_static_manip_insert_nodes_after : public function
{
public:
  zorba_store_collections_static_manip_insert_nodes_after(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:apply-insert-nodes
class zorba_store_collections_static_manip_apply_insert_nodes : public function
{
public:
  zorba_store_collections_static_manip_apply_insert_nodes(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return (APPLYING_EXPR | SEQUENTIAL_EXPR); }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:apply-insert-nodes-first
class zorba_store_collections_static_manip_apply_insert_nodes_first : public function
{
public:
  zorba_store_collections_static_manip_apply_insert_nodes_first(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return (APPLYING_EXPR | SEQUENTIAL_EXPR); }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:apply-insert-nodes-last
class zorba_store_collections_static_manip_apply_insert_nodes_last : public function
{
public:
  zorba_store_collections_static_manip_apply_insert_nodes_last(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return (APPLYING_EXPR | SEQUENTIAL_EXPR); }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:apply-insert-nodes-before
class zorba_store_collections_static_manip_apply_insert_nodes_before : public function
{
public:
  zorba_store_collections_static_manip_apply_insert_nodes_before(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return (APPLYING_EXPR | SEQUENTIAL_EXPR); }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:apply-insert-nodes-after
class zorba_store_collections_static_manip_apply_insert_nodes_after : public function
{
public:
  zorba_store_collections_static_manip_apply_insert_nodes_after(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return (APPLYING_EXPR | SEQUENTIAL_EXPR); }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:delete-nodes
class zorba_store_collections_static_manip_delete_nodes : public function
{
public:
  zorba_store_collections_static_manip_delete_nodes(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, ulong producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, ulong producer) const;

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:delete-node-first
class zorba_store_collections_static_manip_delete_node_first : public function
{
public:
  zorba_store_collections_static_manip_delete_node_first(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:delete-node-last
class zorba_store_collections_static_manip_delete_node_last : public function
{
public:
  zorba_store_collections_static_manip_delete_node_last(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:collection-name
class zorba_store_collections_static_manip_collection_name : public function
{
public:
  zorba_store_collections_static_manip_collection_name(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:is-available-collection
class zorba_store_collections_static_manip_is_available_collection : public function
{
public:
  zorba_store_collections_static_manip_is_available_collection(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:available-collections
class zorba_store_collections_static_manip_available_collections : public function
{
public:
  zorba_store_collections_static_manip_available_collections(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:is-available-index
class zorba_store_collections_static_manip_is_available_index : public function
{
public:
  zorba_store_collections_static_manip_is_available_index(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:available-indexes
class zorba_store_collections_static_manip_available_indexes : public function
{
public:
  zorba_store_collections_static_manip_available_indexes(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:is-activated-integrity-constraint
class zorba_store_collections_static_manip_is_activated_integrity_constraint : public function
{
public:
  zorba_store_collections_static_manip_is_activated_integrity_constraint(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:activated-integrity-constraints
class zorba_store_collections_static_manip_activated_integrity_constraints : public function
{
public:
  zorba_store_collections_static_manip_activated_integrity_constraints(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-init:is-declared-collection
class zorba_store_collections_static_init_is_declared_collection : public function
{
public:
  zorba_store_collections_static_init_is_declared_collection(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-store-collections-static-init:declared-collections
class zorba_store_collections_static_init_declared_collections : public function
{
public:
  zorba_store_collections_static_init_declared_collections(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-store-collections-static-init:is-declared-index
class zorba_store_collections_static_init_is_declared_index : public function
{
public:
  zorba_store_collections_static_init_is_declared_index(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-store-collections-static-init:declared-indexes
class zorba_store_collections_static_init_declared_indexes : public function
{
public:
  zorba_store_collections_static_init_declared_indexes(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-store-collections-static-init:is-declared-integrity-constraint
class zorba_store_collections_static_init_is_declared_integrity_constraint : public function
{
public:
  zorba_store_collections_static_init_is_declared_integrity_constraint(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-store-collections-static-init:declared-integrity-constraints
class zorba_store_collections_static_init_declared_integrity_constraints : public function
{
public:
  zorba_store_collections_static_init_declared_integrity_constraints(const signature& sig, FunctionConsts::FunctionKind kind)
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
