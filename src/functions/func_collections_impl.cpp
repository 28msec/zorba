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
#include "compiler/expression/expr_base.h"
#include "compiler/expression/pragma.h"
#include "compiler/api/compilercb.h"

namespace zorba
{

/*******************************************************************************

********************************************************************************/
bool
mustCopyNodes(expr& e)
{
  pragma_t p;
  return e.get_sctx()->lookup_pragma(&e, "no-copy", p);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  return new ZorbaCollectionIterator(sctx, loc, argv, dynamic);
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
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  return new ZorbaIndexOfIterator(sctx, loc, argv, dynamic);
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
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS;

  return new ZorbaCreateCollectionIterator(sctx, loc, argv, dynamic);
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
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS;

  return new ZorbaDeleteCollectionIterator(sctx, loc, argv, dynamic);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_insert_nodes::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  bool const copy = mustCopyNodes(ann);

  return new ZorbaInsertNodesIterator(sctx, loc, argv, dynamic, copy);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_insert_nodes_first::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  bool const copy = mustCopyNodes(ann);

  return new ZorbaInsertNodesFirstIterator(sctx, loc, argv, dynamic, copy);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_insert_nodes_last::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  bool const copy = mustCopyNodes(ann);

  return new ZorbaInsertNodesLastIterator(sctx, loc, argv, dynamic, copy);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_insert_nodes_before::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  bool const copy = mustCopyNodes(ann);

  return new ZorbaInsertNodesBeforeIterator(sctx, loc, argv, dynamic, copy);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_insert_nodes_after::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  bool const copy = mustCopyNodes(ann);

  return new ZorbaInsertNodesAfterIterator(sctx, loc, argv, dynamic, copy);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t static_collections_dml_apply_insert_nodes::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  bool const copy = mustCopyNodes(ann);

  return new ZorbaApplyInsertNodesIterator(sctx, loc, argv, dynamic, copy);
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
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  bool const copy = mustCopyNodes(ann);

  return new ZorbaApplyInsertNodesFirstIterator(sctx, loc, argv, dynamic, copy);
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
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  const zstring& ns = getName()->getNamespace();

  bool const dynamic = 
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  bool const copy = mustCopyNodes(ann);

  return new ZorbaApplyInsertNodesLastIterator(sctx, loc, argv, dynamic, copy);
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
  CompilerCB* cb,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  const zstring& ns = getName()->getNamespace();

  bool const dynamic = 
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  bool const copy = mustCopyNodes(ann);

  return new ZorbaApplyInsertNodesBeforeIterator(sctx, loc, argv, dynamic, copy);
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
  CompilerCB* cb,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  bool const copy = mustCopyNodes(ann);

  return new ZorbaApplyInsertNodesAfterIterator(sctx, loc, argv, dynamic, copy);
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
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  return new ZorbaDeleteNodesIterator(sctx, loc, argv, dynamic);
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
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  return new ZorbaDeleteNodesFirstIterator(sctx, loc, argv, dynamic);
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
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  return new ZorbaDeleteNodesLastIterator(sctx, loc, argv, dynamic);
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
PlanIter_t static_collections_dml_truncate::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;

  return new ZorbaTruncateCollectionIterator(sctx, loc, argv, dynamic);
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
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS;

  return new IsAvailableCollectionIterator(sctx, loc, argv, dynamic);
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
  const zstring& ns = getName()->getNamespace();

  bool const dynamic =
    ns == static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS;

  return new AvailableCollectionsIterator(sctx, loc, argv, dynamic);
}


} // namespace zorbs
/* vim:set et sw=2 ts=2: */
