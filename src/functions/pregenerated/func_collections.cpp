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


#include "stdafx.h"
#include "runtime/collections/collections.h"
#include "functions/func_collections.h"


namespace zorba{



PlanIter_t fn_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnCollectionIterator(sctx, loc, argv);
}



















PlanIter_t zorba_store_collections_static_dml_collection_name::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ZorbaCollectionNameIterator(sctx, loc, argv);
}



PlanIter_t zorba_store_indexes_static_ddl_is_available_index::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new IsAvailableIndexIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_indexes_static_ddl_available_indexes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new AvailableIndexesIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_integrity_constraints_static_ddl_is_activated_integrity_constraint::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new IsActivatedICIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_integrity_constraints_static_ddl_activated_integrity_constraints::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ActivatedICsIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_collections_static_ddl_is_declared_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new IsDeclaredCollectionIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_collections_static_ddl_declared_collections::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DeclaredCollectionsIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_indexes_static_ddl_is_declared_index::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new IsDeclaredIndexIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_indexes_static_ddl_declared_indexes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DeclaredIndexesIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_integrity_constraints_static_ddl_is_declared_integrity_constraint::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new IsDeclaredICIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_integrity_constraints_static_ddl_declared_integrity_constraints::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DeclaredICsIterator(sctx, loc, argv);
}

PlanIter_t fn_uri_collection_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnURICollectionIterator(sctx, loc, argv);
}

void populate_context_collections(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_collection,
        (createQName("http://www.w3.org/2005/xpath-functions","","collection"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::FN_COLLECTION_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_collection,
        (createQName("http://www.w3.org/2005/xpath-functions","","collection"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::FN_COLLECTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_collection,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","collection"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_COLLECTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_collection,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","collection"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_COLLECTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_index_of,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","index-of"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_INDEX_OF_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_index_of,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","index-of"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_INDEX_OF_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_ddl_create,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/ddl","","create"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DDL_CREATE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_ddl_create,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/ddl","","create"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DDL_CREATE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_ddl_create,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl","","create"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_CREATE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_ddl_create,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl","","create"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_CREATE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_ddl_delete,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/ddl","","delete"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DDL_DELETE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_ddl_delete,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl","","delete"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_DELETE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_insert_nodes,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","insert-nodes"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_INSERT_NODES_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_insert_nodes_first,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","insert-nodes-first"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_INSERT_NODES_FIRST_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_insert_nodes_first,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","insert-nodes-first"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_INSERT_NODES_FIRST_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_insert_nodes_last,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","insert-nodes-last"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_INSERT_NODES_LAST_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_insert_nodes_last,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","insert-nodes-last"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_INSERT_NODES_LAST_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_insert_nodes_before,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","insert-nodes-before"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_INSERT_NODES_BEFORE_3);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_insert_nodes_before,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","insert-nodes-before"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_INSERT_NODES_BEFORE_3);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_insert_nodes_after,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","insert-nodes-after"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_INSERT_NODES_AFTER_3);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_insert_nodes_after,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","insert-nodes-after"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_INSERT_NODES_AFTER_3);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_apply_insert_nodes,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","apply-insert-nodes"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_APPLY_INSERT_NODES_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_apply_insert_nodes_first,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","apply-insert-nodes-first"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_APPLY_INSERT_NODES_FIRST_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_apply_insert_nodes_first,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","apply-insert-nodes-first"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_APPLY_INSERT_NODES_FIRST_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_apply_insert_nodes_last,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","apply-insert-nodes-last"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_APPLY_INSERT_NODES_LAST_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_apply_insert_nodes_last,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","apply-insert-nodes-last"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_APPLY_INSERT_NODES_LAST_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_apply_insert_nodes_before,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","apply-insert-nodes-before"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_APPLY_INSERT_NODES_BEFORE_3);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_apply_insert_nodes_before,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","apply-insert-nodes-before"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_APPLY_INSERT_NODES_BEFORE_3);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_apply_insert_nodes_after,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","apply-insert-nodes-after"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_APPLY_INSERT_NODES_AFTER_3);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_apply_insert_nodes_after,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","apply-insert-nodes-after"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_APPLY_INSERT_NODES_AFTER_3);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_delete_nodes,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","delete-nodes"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_DELETE_NODES_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_delete_nodes,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","delete-nodes"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_DELETE_NODES_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_delete_node_first,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","delete-node-first"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_DELETE_NODE_FIRST_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_delete_node_first,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","delete-nodes-first"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_DELETE_NODES_FIRST_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_delete_node_first,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","delete-node-first"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_DELETE_NODE_FIRST_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_delete_node_first,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","delete-nodes-first"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_DELETE_NODES_FIRST_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_delete_node_last,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","delete-node-last"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_DELETE_NODE_LAST_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_delete_node_last,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","delete-nodes-last"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_DELETE_NODES_LAST_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_delete_node_last,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","delete-node-last"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_DELETE_NODE_LAST_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_delete_node_last,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","delete-nodes-last"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_DELETE_NODES_LAST_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_truncate,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","truncate"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_TRUNCATE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_truncate,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","truncate"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_TRUNCATE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_collection_name,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/dml","","collection-name"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DML_COLLECTION_NAME_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_dml_collection_name,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/dml","","collection-name"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_COLLECTION_NAME_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_ddl_is_available_collection,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/ddl","","is-available-collection"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DDL_IS_AVAILABLE_COLLECTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_ddl_is_available_collection,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl","","is-available-collection"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_IS_AVAILABLE_COLLECTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_ddl_available_collections,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/ddl","","available-collections"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DDL_AVAILABLE_COLLECTIONS_0);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_ddl_available_collections,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl","","available-collections"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_AVAILABLE_COLLECTIONS_0);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_indexes_static_ddl_is_available_index,
        (createQName("http://www.zorba-xquery.com/modules/store/static/indexes/ddl","","is-available-index"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_INDEXES_STATIC_DDL_IS_AVAILABLE_INDEX_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_indexes_static_ddl_available_indexes,
        (createQName("http://www.zorba-xquery.com/modules/store/static/indexes/ddl","","available-indexes"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_INDEXES_STATIC_DDL_AVAILABLE_INDEXES_0);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_integrity_constraints_static_ddl_is_activated_integrity_constraint,
        (createQName("http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl","","is-activated-integrity-constraint"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_INTEGRITY_CONSTRAINTS_STATIC_DDL_IS_ACTIVATED_INTEGRITY_CONSTRAINT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_integrity_constraints_static_ddl_activated_integrity_constraints,
        (createQName("http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl","","activated-integrity-constraints"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_INTEGRITY_CONSTRAINTS_STATIC_DDL_ACTIVATED_INTEGRITY_CONSTRAINTS_0);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_ddl_is_declared_collection,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/ddl","","is-declared-collection"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DDL_IS_DECLARED_COLLECTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_collections_static_ddl_declared_collections,
        (createQName("http://www.zorba-xquery.com/modules/store/static/collections/ddl","","declared-collections"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_DDL_DECLARED_COLLECTIONS_0);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_indexes_static_ddl_is_declared_index,
        (createQName("http://www.zorba-xquery.com/modules/store/static/indexes/ddl","","is-declared-index"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_INDEXES_STATIC_DDL_IS_DECLARED_INDEX_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_indexes_static_ddl_declared_indexes,
        (createQName("http://www.zorba-xquery.com/modules/store/static/indexes/ddl","","declared-indexes"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_INDEXES_STATIC_DDL_DECLARED_INDEXES_0);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_integrity_constraints_static_ddl_is_declared_integrity_constraint,
        (createQName("http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl","","is-declared-integrity-constraint"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_INTEGRITY_CONSTRAINTS_STATIC_DDL_IS_DECLARED_INTEGRITY_CONSTRAINT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_integrity_constraints_static_ddl_declared_integrity_constraints,
        (createQName("http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl","","declared-integrity-constraints"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_INTEGRITY_CONSTRAINTS_STATIC_DDL_DECLARED_INTEGRITY_CONSTRAINTS_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_uri_collection_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","uri-collection"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_STAR),
        FunctionConsts::FN_URI_COLLECTION_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_uri_collection_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","uri-collection"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_STAR),
        FunctionConsts::FN_URI_COLLECTION_1);

  }

}


}



