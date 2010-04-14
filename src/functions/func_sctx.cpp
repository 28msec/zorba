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
  return new IsDeclaredCollectionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_declared_collections::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DeclaredCollectionsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_is_declared_index::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDeclaredIndexIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_declared_indexes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DeclaredIndexesIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_statically_known_namespaces::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StaticNamespacesIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_statically_known_namespace_binding::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StaticNamespaceBindingIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_in_scope_variables::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InscopeVariablesIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_default_collection_type::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DefaultCollectionTypeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_xpath10_compatibility_mode::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new XPath10CompatModeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_statically_known_documents::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StaticallyKnownDocumentsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_statically_known_document_type::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StaticallyKnownDocumentTypeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_statically_known_collations::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StaticallyKnownCollationsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_construction_mode::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ConstructionModeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_ordering_mode::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new OrderingModeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_default_order::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DefaultOrderIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_boundary_space_policy::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new BoundarySpacePolicyIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_copy_namespaces_mode::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CopyNamespacesModeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_function_names::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FunctionNamesIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_function_arguments_count::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FunctionArgumentsCountIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_in_scope_schema_types::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InScopeSchemaTypesIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_in_scope_element_declarations::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InScopeElementDeclarationsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_in_scope_attribute_declarations::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InScopeAttributeDeclarationsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_is_declared_integrity_constraint::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDeclaredICIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_declared_integrity_constraints::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DeclaredICsIterator(sctx, loc, argv);
}

void populate_context_sctx(static_context* sctx)
{
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


  DECL(sctx, fn_zorba_introspect_sctx_statically_known_namespaces,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","statically-known-namespaces"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR));


  DECL(sctx, fn_zorba_introspect_sctx_statically_known_namespace_binding,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","statically-known-namespace-binding"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION));


  DECL(sctx, fn_zorba_introspect_sctx_in_scope_variables,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","in-scope-variables"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));


  DECL(sctx, fn_zorba_introspect_sctx_default_collection_type,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","default-collection-type"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_sctx_xpath10_compatibility_mode,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","xpath10-compatibility-mode"),
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_sctx_statically_known_documents,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","statically-known-documents"),
      GENV_TYPESYSTEM.ANY_URI_TYPE_STAR));


  DECL(sctx, fn_zorba_introspect_sctx_statically_known_document_type,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","statically-known-document-type"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_sctx_statically_known_collations,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","statically-known-collations"),
      GENV_TYPESYSTEM.ANY_URI_TYPE_STAR));


  DECL(sctx, fn_zorba_introspect_sctx_construction_mode,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","construction-mode"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_sctx_ordering_mode,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","ordering-mode"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_sctx_default_order,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","default-order"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_sctx_boundary_space_policy,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","boundary-space-policy"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_sctx_copy_namespaces_mode,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","copy-namespaces-mode"),
      GENV_TYPESYSTEM.STRING_TYPE_PLUS));


  DECL(sctx, fn_zorba_introspect_sctx_function_names,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","function-names"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));


  DECL(sctx, fn_zorba_introspect_sctx_function_arguments_count,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","function-arguments-count"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.INT_TYPE_STAR));


  DECL(sctx, fn_zorba_introspect_sctx_in_scope_schema_types,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","in-scope-schema-types"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));


  DECL(sctx, fn_zorba_introspect_sctx_in_scope_element_declarations,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","in-scope-element-declarations"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));


  DECL(sctx, fn_zorba_introspect_sctx_in_scope_attribute_declarations,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","in-scope-attribute-declarations"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));


  DECL(sctx, fn_zorba_introspect_sctx_is_declared_integrity_constraint,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","is-declared-integrity-constraint"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_zorba_introspect_sctx_declared_integrity_constraints,
      (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","fn-zorba-introspect-sctx","declared-integrity-constraints"),
      GENV_TYPESYSTEM.QNAME_TYPE_STAR));

}


}