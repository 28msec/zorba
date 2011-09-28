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


#include "runtime/introspection/dctx.h"
#include "functions/func_dctx.h"


namespace zorba{



PlanIter_t fn_zorba_introspect_dctx_is_available_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAvailableCollectionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_dctx_available_collections::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new AvailableCollectionsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_dctx_is_available_index::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAvailableIndexIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_dctx_available_indexes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new AvailableIndexesIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_dctx_is_activated_integrity_constraint::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsActivatedICIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_dctx_activated_integrity_constraints::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ActivatedICsIterator(sctx, loc, argv);
}

void populate_context_dctx(static_context* sctx)
{
  DECL(sctx, fn_zorba_introspect_dctx_is_available_collection,
      (createQName("http://www.zorba-xquery.com/modules/introspection/dctx","","is-available-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_dctx_available_collections,
      (createQName("http://www.zorba-xquery.com/modules/introspection/dctx","","available-collections"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));


  DECL(sctx, fn_zorba_introspect_dctx_is_available_index,
      (createQName("http://www.zorba-xquery.com/modules/introspection/dctx","","is-available-index"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_dctx_available_indexes,
      (createQName("http://www.zorba-xquery.com/modules/introspection/dctx","","available-indexes"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));


  DECL(sctx, fn_zorba_introspect_dctx_is_activated_integrity_constraint,
      (createQName("http://www.zorba-xquery.com/modules/introspection/dctx","","is-activated-integrity-constraint"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_dctx_activated_integrity_constraints,
      (createQName("http://www.zorba-xquery.com/modules/introspection/dctx","","activated-integrity-constraints"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));

}


}



