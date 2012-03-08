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
PlanIter_t static_collections_dml_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaCollectionIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_index_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaIndexOfIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_ddl_create::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DDL_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaCreateCollectionIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_ddl_delete::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DDL_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaDeleteCollectionIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_insert_nodes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaInsertNodesIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_insert_nodes_first::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaInsertNodesFirstIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_insert_nodes_last::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaInsertNodesLastIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_insert_nodes_before::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaInsertNodesBeforeIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_insert_nodes_after::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaInsertNodesAfterIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_apply_insert_nodes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaApplyInsertNodesIterator(sctx, loc, argv, dynamic, jsoniq);
}


bool static_collections_dml_apply_insert_nodes::propagatesInputNodes(
    expr* fo,
    csize input) const
{
  return false;
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_apply_insert_nodes_first::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaApplyInsertNodesFirstIterator(sctx, loc, argv, dynamic, jsoniq);
}


bool static_collections_dml_apply_insert_nodes_first::propagatesInputNodes(
    expr* fo,
    csize input) const
{
  return false;
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_apply_insert_nodes_last::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaApplyInsertNodesLastIterator(sctx, loc, argv, dynamic, jsoniq);
}


bool static_collections_dml_apply_insert_nodes_last::propagatesInputNodes(
    expr* fo,
    csize input) const
{
  return false;
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_apply_insert_nodes_before::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaApplyInsertNodesBeforeIterator(sctx, loc, argv, dynamic, jsoniq);
}


bool 
static_collections_dml_apply_insert_nodes_before::propagatesInputNodes(
    expr* fo,
    csize input) const
{
  return false;
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_apply_insert_nodes_after::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaApplyInsertNodesAfterIterator(sctx, loc, argv, dynamic, jsoniq);
}


bool 
static_collections_dml_apply_insert_nodes_after::propagatesInputNodes(
    expr* fo,
    csize input) const
{
  return false;
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_delete_nodes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaDeleteNodesIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_delete_node_first::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaDeleteNodesFirstIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_delete_node_last::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new ZorbaDeleteNodesLastIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
BoolAnnotationValue static_collections_dml_delete_nodes::ignoresSortedNodes(
    expr* fo,
    csize input) const 
{
  return ANNOTATION_TRUE;
}


BoolAnnotationValue static_collections_dml_delete_nodes::ignoresDuplicateNodes(
    expr* fo, 
    csize input) const 
{
  return ANNOTATION_TRUE;
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_ddl_is_available_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DDL_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new IsAvailableCollectionIterator(sctx, loc, argv, dynamic, jsoniq);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_ddl_available_collections::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  bool dynamic = false;
  bool jsoniq = false;

  const zstring& ns = getName()->getNamespace();

  if (ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS)
  {
    dynamic = true;
  }
#ifdef ZORBA_WITH_JSON
  else if (ns == static_context::ZORBA_STORE_JSONIQ_DYNAMIC_COLLECTIONS_DDL_FN_NS)
  {
    dynamic = true;
    jsoniq = true;
  }
#endif

  return new AvailableCollectionsIterator(sctx, loc, argv, dynamic, jsoniq);
}



}

/* vim:set et sw=2 ts=2: */
