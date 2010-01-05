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

PlanIter_t fn_zorba_ddl_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaCollectionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_index_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaIndexOfIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_create_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaCreateCollectionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_delete_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaDeleteCollectionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_insert_nodes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaInsertNodesIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_insert_nodes_first::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaInsertNodesFirstIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_insert_nodes_last::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaInsertNodesLastIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_insert_nodes_before::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaInsertNodesBeforeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_insert_nodes_after::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaInsertNodesAfterIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_delete_nodes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaDeleteNodesIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_delete_node_first::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaDeleteNodesFirstIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_delete_nodes_first::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaDeleteNodesFirstIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_delete_node_last::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaDeleteNodesLastIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_delete_nodes_last::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaDeleteNodesLastIterator(sctx, loc, argv);
}

void populate_context_collections(static_context* sctx)
{
  DECL(sctx, fn_collection,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","collection"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));


  DECL(sctx, fn_collection,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","collection"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));


  DECL(sctx, fn_zorba_ddl_collection,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));


  DECL(sctx, fn_zorba_ddl_index_of,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","index-of"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));


  DECL(sctx, fn_zorba_ddl_create_collection,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","create-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_create_collection,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","create-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_delete_collection,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","delete-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_insert_nodes,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","insert-nodes"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_insert_nodes_first,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","insert-nodes-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_insert_nodes_last,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","insert-nodes-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_insert_nodes_before,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","insert-nodes-before"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_insert_nodes_after,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","insert-nodes-after"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_delete_nodes,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","delete-nodes"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_delete_node_first,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","delete-node-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_delete_node_first,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","delete-nodes-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.UNSIGNED_LONG_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_delete_nodes_first,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","delete-node-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_delete_nodes_first,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","delete-nodes-first"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.UNSIGNED_LONG_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_delete_node_last,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","delete-node-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_delete_node_last,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","delete-nodes-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.UNSIGNED_LONG_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_delete_nodes_last,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","delete-node-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_delete_nodes_last,
      (createQName("http://www.zorba-xquery.com/modules/xqddf","fn-zorba-ddl","delete-nodes-last"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.UNSIGNED_LONG_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));

}


}