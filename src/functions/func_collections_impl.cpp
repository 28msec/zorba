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
#include "stdafx.h"

#include "functions/func_collections.h"
#include "runtime/collections/collections.h"

#include "compiler/expression/expr_consts.h"

namespace zorba
{

/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaCollectionIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_index_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaIndexOfIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_ddl_create::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaCreateCollectionIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_ddl_delete::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaDeleteCollectionIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_insert_nodes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaInsertNodesIterator(
      sctx, loc, argv, getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_insert_nodes_first::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaInsertNodesFirstIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_insert_nodes_last::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaInsertNodesLastIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_insert_nodes_before::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaInsertNodesBeforeIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_insert_nodes_after::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaInsertNodesAfterIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_apply_insert_nodes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaApplyInsertNodesIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_apply_insert_nodes_first::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaApplyInsertNodesFirstIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_apply_insert_nodes_last::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaApplyInsertNodesLastIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_apply_insert_nodes_before::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaApplyInsertNodesBeforeIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_apply_insert_nodes_after::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaApplyInsertNodesAfterIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_delete_nodes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaDeleteNodesIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_delete_node_first::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaDeleteNodesFirstIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_dml_delete_node_last::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaDeleteNodesLastIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_ddl_is_available_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAvailableCollectionIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t zorba_store_collections_static_ddl_available_collections::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new AvailableCollectionsIterator(sctx, loc, argv,
      getName()->getNamespace() == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS);
}

/*******************************************************************************

********************************************************************************/
BoolAnnotationValue zorba_store_collections_static_dml_delete_nodes::ignoresSortedNodes(
    expr* fo,
    ulong input) const 
{
  return ANNOTATION_TRUE;
}


/*******************************************************************************

********************************************************************************/
BoolAnnotationValue zorba_store_collections_static_dml_delete_nodes::ignoresDuplicateNodes(
    expr* fo, 
    ulong input) const 
{
  return ANNOTATION_TRUE;
}


}

/* vim:set et sw=2 ts=2: */
