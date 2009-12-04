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


#include "runtime/introspection/sctx.h"
#include "functions/func_sctx.h"


namespace zorba{



PlanIter_t fn_zorba_introspect_sctx_is_declared_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDeclaredCollectionIterator ( sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_declared_collections::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DeclaredCollectionsIterator ( sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_is_declared_index::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDeclaredIndexIterator ( sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_declared_indexes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DeclaredIndexesIterator ( sctx, loc, argv);
}

void populate_context_sctx(static_context* sctx) {
  DECL(sctx, fn_zorba_introspect_sctx_is_declared_collection,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","is-declared-collection"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_sctx_declared_collections,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","declared-collections"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));


  DECL(sctx, fn_zorba_introspect_sctx_is_declared_index,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","is-declared-index"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_sctx_declared_indexes,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","declared-indexes"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));

}


}