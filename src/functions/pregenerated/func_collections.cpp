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


#include "runtime/collections/collections.h"
#include "functions/func_collections.h"


namespace zorba{



PlanIter_t fn_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnCollectionIterator(sctx, loc, argv);
}


















PlanIter_t zorba_store_collections_static_manip_collection_name::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaCollectionNameIterator(sctx, loc, argv);
}



PlanIter_t zorba_store_collections_static_manip_is_available_index::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAvailableIndexIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_collections_static_manip_available_indexes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new AvailableIndexesIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_collections_static_manip_is_activated_integrity_constraint::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsActivatedICIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_collections_static_manip_activated_integrity_constraints::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ActivatedICsIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_collections_static_init_is_declared_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDeclaredCollectionIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_collections_static_init_declared_collections::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DeclaredCollectionsIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_collections_static_init_is_declared_index::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDeclaredIndexIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_collections_static_init_declared_indexes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DeclaredIndexesIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_collections_static_init_is_declared_integrity_constraint::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDeclaredICIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_collections_static_init_declared_integrity_constraints::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DeclaredICsIterator(sctx, loc, argv);
}

void populate_context_collections(static_context* sctx)
{
  DECL_WITH_KIND(sctx, fn_collection,
      (createQName("http://www.w3.org/2005/xpath-functions","","collection"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::FN_COLLECTION_0);


  DECL_WITH_KIND(sctx, fn_collection,
      (createQName("http://www.w3.org/2005/xpath-functions","","collection"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::FN_COLLECTION_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_collection,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_COLLECTION_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_collection,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_COLLECTION_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_index_of,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","index-of"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_INDEX_OF_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_index_of,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","index-of"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_INDEX_OF_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_init_create_collection,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/initialization","","create-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_INIT_CREATE_COLLECTION_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_init_create_collection,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/initialization","","create-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_INIT_CREATE_COLLECTION_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_init_create_collection,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","create-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_CREATE_COLLECTION_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_init_create_collection,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","create-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_CREATE_COLLECTION_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_init_delete_collection,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/initialization","","delete-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_INIT_DELETE_COLLECTION_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_init_delete_collection,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","delete-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_DELETE_COLLECTION_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_insert_nodes,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","insert-nodes"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_INSERT_NODES_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_insert_nodes_first,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","insert-nodes-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_INSERT_NODES_FIRST_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_insert_nodes_first,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","insert-nodes-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_INSERT_NODES_FIRST_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_insert_nodes_last,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","insert-nodes-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_INSERT_NODES_LAST_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_insert_nodes_last,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","insert-nodes-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_INSERT_NODES_LAST_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_insert_nodes_before,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","insert-nodes-before"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_INSERT_NODES_BEFORE_3);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_insert_nodes_before,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","insert-nodes-before"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_INSERT_NODES_BEFORE_3);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_insert_nodes_after,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","insert-nodes-after"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_INSERT_NODES_AFTER_3);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_insert_nodes_after,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","insert-nodes-after"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_INSERT_NODES_AFTER_3);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_apply_insert_nodes,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","apply-insert-nodes"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_APPLY_INSERT_NODES_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_apply_insert_nodes_first,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","apply-insert-nodes-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_APPLY_INSERT_NODES_FIRST_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_apply_insert_nodes_first,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","apply-insert-nodes-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_APPLY_INSERT_NODES_FIRST_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_apply_insert_nodes_last,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","apply-insert-nodes-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_APPLY_INSERT_NODES_LAST_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_apply_insert_nodes_last,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","apply-insert-nodes-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_APPLY_INSERT_NODES_LAST_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_apply_insert_nodes_before,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","apply-insert-nodes-before"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_APPLY_INSERT_NODES_BEFORE_3);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_apply_insert_nodes_before,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","apply-insert-nodes-before"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_APPLY_INSERT_NODES_BEFORE_3);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_apply_insert_nodes_after,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","apply-insert-nodes-after"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_APPLY_INSERT_NODES_AFTER_3);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_apply_insert_nodes_after,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","apply-insert-nodes-after"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_APPLY_INSERT_NODES_AFTER_3);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_delete_nodes,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","delete-nodes"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_DELETE_NODES_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_delete_nodes,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","delete-nodes"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_DELETE_NODES_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_delete_node_first,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","delete-node-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_DELETE_NODE_FIRST_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_delete_node_first,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","delete-nodes-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.UNSIGNED_LONG_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_DELETE_NODES_FIRST_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_delete_node_first,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","delete-node-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_DELETE_NODE_FIRST_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_delete_node_first,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","delete-nodes-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.UNSIGNED_LONG_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_DELETE_NODES_FIRST_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_delete_node_last,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","delete-node-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_DELETE_NODE_LAST_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_delete_node_last,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","delete-nodes-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.UNSIGNED_LONG_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_DELETE_NODES_LAST_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_delete_node_last,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","delete-node-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_DELETE_NODE_LAST_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_delete_node_last,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","delete-nodes-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.UNSIGNED_LONG_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_DELETE_NODES_LAST_2);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_collection_name,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","collection-name"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_COLLECTION_NAME_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_collection_name,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","collection-name"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_COLLECTION_NAME_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_is_available_collection,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","is-available-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_IS_AVAILABLE_COLLECTION_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_is_available_collection,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","is-available-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_IS_AVAILABLE_COLLECTION_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_available_collections,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","available-collections"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_AVAILABLE_COLLECTIONS_0);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_available_collections,
      (createQName("http://www.zorba-xquery.com/modules/store/collections","","available-collections"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_AVAILABLE_COLLECTIONS_0);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_is_available_index,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","is-available-index"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_IS_AVAILABLE_INDEX_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_available_indexes,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","available-indexes"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_AVAILABLE_INDEXES_0);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_is_activated_integrity_constraint,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","is-activated-integrity-constraint"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_IS_ACTIVATED_INTEGRITY_CONSTRAINT_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_manip_activated_integrity_constraints,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/manipulation","","activated-integrity-constraints"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_MANIP_ACTIVATED_INTEGRITY_CONSTRAINTS_0);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_init_is_declared_collection,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/initialization","","is-declared-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_INIT_IS_DECLARED_COLLECTION_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_init_declared_collections,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/initialization","","declared-collections"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_INIT_DECLARED_COLLECTIONS_0);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_init_is_declared_index,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/initialization","","is-declared-index"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_INIT_IS_DECLARED_INDEX_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_init_declared_indexes,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/initialization","","declared-indexes"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_INIT_DECLARED_INDEXES_0);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_init_is_declared_integrity_constraint,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/initialization","","is-declared-integrity-constraint"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_INIT_IS_DECLARED_INTEGRITY_CONSTRAINT_1);


  DECL_WITH_KIND(sctx, zorba_store_collections_static_init_declared_integrity_constraints,
      (createQName("http://www.zorba-xquery.com/modules/store/static-collections/initialization","","declared-integrity-constraints"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR),
      FunctionConsts::ZORBA_STORE_COLLECTIONS_STATIC_INIT_DECLARED_INTEGRITY_CONSTRAINTS_0);

}


}



