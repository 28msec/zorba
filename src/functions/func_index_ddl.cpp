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

#include "runtime/indexing/index_ddl.h"

#include "compiler/expression/fo_expr.h"
#include "compiler/expression/expr.h"

#include "functions/func_index_ddl.h"


namespace zorba
{


PlanIter_t op_create_internal_index::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder& ann) const
{
  fo_expr* fo = static_cast<fo_expr*>(&ann);

  const const_expr* qnameExpr = static_cast<const const_expr*>(fo->get_arg(0));
  const store::Item* qname = qnameExpr->get_val();

  return new CreateInternalIndexIterator(sctx,
                                         loc,
                                         argv[1],
                                         const_cast<store::Item*>(qname));
}


PlanIter_t fn_zorba_ddl_create_index::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CreateIndexIterator(sctx, loc, argv[0]);
}


PlanIter_t fn_zorba_ddl_delete_index::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DeleteIndexIterator(sctx, loc, argv[0]);
}


PlanIter_t fn_zorba_ddl_refresh_index::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new RefreshIndexIterator(sctx, loc, argv[0]);
}


PlanIter_t op_value_index_entry_builder::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ValueIndexEntryBuilderIterator(sctx, loc, argv);
}


PlanIter_t op_general_index_entry_builder::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new GeneralIndexEntryBuilderIterator(sctx, loc, argv);
}


PlanIter_t fn_zorba_ddl_probe_index_point_value::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ProbeIndexPointValueIterator(sctx, loc, argv);
}


PlanIter_t fn_zorba_ddl_probe_index_point_general::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ProbeIndexPointGeneralIterator(sctx, loc, argv);
}


PlanIter_t fn_zorba_ddl_probe_index_range_value::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ProbeIndexRangeValueIterator(sctx, loc, argv);
}


PlanIter_t fn_zorba_ddl_probe_index_range_general::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ProbeIndexRangeGeneralIterator(sctx, loc, argv);
}


void populate_context_index_ddl(static_context* sctx)
{
  const char* zorba_op_ns = static_context::ZORBA_OP_NS.c_str();

  DECL(sctx, op_value_index_entry_builder,
       (createQName(zorba_op_ns, "", "value-index-entry-builder"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_general_index_entry_builder,
       (createQName(zorba_op_ns, "", "general-index-entry-builder"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_create_internal_index,
       (createQName(zorba_op_ns, "", "create-internal-index"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, fn_zorba_ddl_create_index,
       (createQName("http://www.zorba-xquery.com/modules/store/static/indexes/ddl",
                    "",
                    "create"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, fn_zorba_ddl_delete_index,
       (createQName("http://www.zorba-xquery.com/modules/store/static/indexes/ddl",
                    "",
                    "delete"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, fn_zorba_ddl_refresh_index,
       (createQName("http://www.zorba-xquery.com/modules/store/static/indexes/dml",
                    "",
                    "refresh-index"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, fn_zorba_ddl_probe_index_point_value,
       (createQName("http://www.zorba-xquery.com/modules/store/static/indexes/dml",
                    "",
                    "probe-index-point-value"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, fn_zorba_ddl_probe_index_point_general,
       (createQName("http://www.zorba-xquery.com/modules/store/static/indexes/dml",
                    "",
                    "probe-index-point-general"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));


  DECL(sctx, fn_zorba_ddl_probe_index_range_value,
       (createQName("http://www.zorba-xquery.com/modules/store/static/indexes/dml",
                    "",
                    "probe-index-range-value"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, fn_zorba_ddl_probe_index_range_general,
       (createQName("http://www.zorba-xquery.com/modules/store/static/indexes/dml",
                    "",
                    "probe-index-range-general"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
}


}
/* vim:set et sw=2 ts=2: */
