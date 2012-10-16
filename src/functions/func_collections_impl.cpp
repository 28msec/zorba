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
#include "compiler/expression/fo_expr.h"

#include "compiler/expression/pragma.h"
#include "compiler/api/compilercb.h"

namespace zorba
{

/*******************************************************************************

********************************************************************************/
bool
hasNoCopyPragma(expr& e)
{
  pragma* p;
  return e.get_ccb()->lookup_pragma(&e, "no-copy", p);
}


/*******************************************************************************

********************************************************************************/
void
processPragmaInternal(zorba::expr* e, const std::vector<zorba::pragma*>& p)
{
  for (std::vector<zorba::pragma*>::const_iterator lIter = p.begin();
       lIter != p.end();
       ++lIter)
  {
    pragma* p = *lIter;
    if (p->theQName->getNamespace() == ZORBA_EXTENSIONS_NS)
    {
      if (p->theQName->getLocalName() == "no-copy")
      {
        e->get_ccb()->add_pragma(e, p);
        e->setContainsPragma(ANNOTATION_TRUE);
      }
    }
  }
}


/*******************************************************************************

********************************************************************************/
xqtref_t static_collections_dml_collection::getReturnType(const fo_expr* caller) const
{
  if (getName()->getNamespace() ==
      static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS)
  {
    return theSignature.returnType();
  }

  static_context* sctx = caller->get_sctx();

  const store::Item* qname = caller->get_arg(0)->getQName(sctx);

  if (qname != NULL)
  {
    const StaticallyKnownCollection* collection = sctx->lookup_collection(qname);

    if (collection != NULL)
    {
      return collection->getCollectionType();
    }
    else
    {
      RAISE_ERROR(zerr::ZDDY0001_COLLECTION_NOT_DECLARED, caller->get_loc(),
      ERROR_PARAMS(qname->getStringValue()));
    }
  }
  else
  {
    return theSignature.returnType();
  }
}


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
void zorba::static_collections_dml_insert_nodes::processPragma(
    zorba::expr* e,
    const std::vector<zorba::pragma*>& p) const
{
  processPragmaInternal(e, p);
}


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

  bool const copy = !hasNoCopyPragma(ann);

  return new ZorbaInsertNodesIterator(sctx, loc, argv, dynamic, copy);
}


/*******************************************************************************

********************************************************************************/
void
zorba::static_collections_dml_insert_nodes_first::processPragma(
    zorba::expr* e,
    const std::vector<zorba::pragma*>& p) const
{
  processPragmaInternal(e, p);
}

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

  bool const copy = !hasNoCopyPragma(ann);

  return new ZorbaInsertNodesFirstIterator(sctx, loc, argv, dynamic, copy);
}


/*******************************************************************************

********************************************************************************/
void
zorba::static_collections_dml_insert_nodes_last::processPragma(
    zorba::expr* e,
    const std::vector<zorba::pragma*>& p) const
{
  processPragmaInternal(e, p);
}

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

  bool const copy = !hasNoCopyPragma(ann);

  return new ZorbaInsertNodesLastIterator(sctx, loc, argv, dynamic, copy);
}


/*******************************************************************************

********************************************************************************/
void
zorba::static_collections_dml_insert_nodes_before::processPragma(
    zorba::expr* e,
    const std::vector<zorba::pragma*>& p) const
{
  processPragmaInternal(e, p);
}

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

  bool const copy = !hasNoCopyPragma(ann);

  return new ZorbaInsertNodesBeforeIterator(sctx, loc, argv, dynamic, copy);
}


/*******************************************************************************

********************************************************************************/
void
zorba::static_collections_dml_insert_nodes_after::processPragma(
    zorba::expr* e,
    const std::vector<zorba::pragma*>& p) const
{
  processPragmaInternal(e, p);
}

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

  bool const copy = !hasNoCopyPragma(ann);

  return new ZorbaInsertNodesAfterIterator(sctx, loc, argv, dynamic, copy);
}


/*******************************************************************************

********************************************************************************/
void
zorba::static_collections_dml_apply_insert_nodes::processPragma(
    zorba::expr* e,
    const std::vector<zorba::pragma*>& p) const
{
  processPragmaInternal(e, p);
}

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

  bool const copy = !hasNoCopyPragma(ann);

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
void
zorba::static_collections_dml_apply_insert_nodes_first::processPragma(
    zorba::expr* e,
    const std::vector<zorba::pragma*>& p) const
{
  processPragmaInternal(e, p);
}

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

  bool const copy = !hasNoCopyPragma(ann);

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
void
zorba::static_collections_dml_apply_insert_nodes_last::processPragma(
    zorba::expr* e,
    const std::vector<zorba::pragma*>& p) const
{
  processPragmaInternal(e, p);
}


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

  bool const copy = !hasNoCopyPragma(ann);

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
void
zorba::static_collections_dml_apply_insert_nodes_before::processPragma(
    zorba::expr* e,
    const std::vector<zorba::pragma*>& p) const
{
  processPragmaInternal(e, p);
}

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

  bool const copy = !hasNoCopyPragma(ann);

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
void
zorba::static_collections_dml_apply_insert_nodes_after::processPragma(
    zorba::expr* e,
    const std::vector<zorba::pragma*>& p) const
{
  processPragmaInternal(e, p);
}

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

  bool const copy = !hasNoCopyPragma(ann);

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
