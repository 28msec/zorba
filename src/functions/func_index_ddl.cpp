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


#include "runtime/indexing/index_ddl.h"
#include "functions/func_index_ddl.h"


namespace zorba{



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

PlanIter_t op_index_entry_builder::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IndexEntryBuilderIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_probe_index_point::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IndexPointProbeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ddl_probe_index_range::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IndexRangeProbeIterator(sctx, loc, argv);
}

void populate_context_index_ddl(static_context* sctx)
{
  DECL(sctx, fn_zorba_ddl_create_index,
      (createQName("http://www.zorba-xquery.com/modules/ddl","fn-zorba-ddl","create-index"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_delete_index,
      (createQName("http://www.zorba-xquery.com/modules/ddl","fn-zorba-ddl","delete-index"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, op_create_internal_index,
      (createQName("http://www.w3.org/2005/xpath-functions","op","create-internal-index"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, fn_zorba_ddl_refresh_index,
      (createQName("http://www.zorba-xquery.com/modules/ddl","fn-zorba-ddl","refresh-index"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));


  DECL(sctx, op_index_entry_builder,
      (createQName("http://www.w3.org/2005/xpath-functions","op","index-entry-builder"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      true,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


  DECL(sctx, fn_zorba_ddl_probe_index_point,
      (createQName("http://www.zorba-xquery.com/modules/ddl","fn-zorba-ddl","probe-index-point"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      true,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));


  DECL(sctx, fn_zorba_ddl_probe_index_range,
      (createQName("http://www.zorba-xquery.com/modules/ddl","fn-zorba-ddl","probe-index-range"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      true,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

}


}