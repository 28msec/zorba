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
#include "runtime/introspection/sctx.h"
#include "functions/func_sctx.h"


namespace zorba{



PlanIter_t fn_zorba_introspect_sctx_function_annotations::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FunctionAnnotationsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_option::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new OptionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_in_scope_attribute_groups::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new InScopeAttributeGroupsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_in_scope_element_groups::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new InScopeElementGroupsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_in_scope_attribute_declarations::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new InScopeAttributeDeclarationsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_in_scope_element_declarations::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new InScopeElementDeclarationsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_in_scope_schema_types::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new InScopeSchemaTypesIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_function_arguments_count::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FunctionArgumentsCountIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_function_names::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FunctionNamesIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_copy_namespaces_mode::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new CopyNamespacesModeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_boundary_space_policy::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new BoundarySpacePolicyIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_default_order::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DefaultOrderIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_ordering_mode::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new OrderingModeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_construction_mode::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ConstructionModeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_statically_known_collations::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new StaticallyKnownCollationsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_statically_known_document_type::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new StaticallyKnownDocumentTypeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_statically_known_documents::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new StaticallyKnownDocumentsIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_xpath10_compatibility_mode::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new XPath10CompatModeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_default_collection_type::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DefaultCollectionTypeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_in_scope_variables::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new InscopeVariablesIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_statically_known_namespace_binding::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new StaticNamespaceBindingIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_default_collation::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new SctxDefaultCollationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_base_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new SctxBaseUriIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_default_function_namespace::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DefaultFunctionNamespaceIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_introspect_sctx_statically_known_namespaces::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new StaticNamespacesIterator(sctx, loc, argv);
}

void populate_context_sctx(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_function_annotations,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","function-annotations"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_FUNCTION_ANNOTATIONS_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_option,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","option"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_OPTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_in_scope_attribute_groups,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","in-scope-attribute-groups"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IN_SCOPE_ATTRIBUTE_GROUPS_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_in_scope_element_groups,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","in-scope-element-groups"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IN_SCOPE_ELEMENT_GROUPS_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_in_scope_attribute_declarations,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","in-scope-attribute-declarations"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IN_SCOPE_ATTRIBUTE_DECLARATIONS_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_in_scope_element_declarations,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","in-scope-element-declarations"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IN_SCOPE_ELEMENT_DECLARATIONS_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_in_scope_schema_types,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","in-scope-schema-types"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IN_SCOPE_SCHEMA_TYPES_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_function_arguments_count,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","function-arguments-count"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.INT_TYPE_STAR),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_FUNCTION_ARGUMENTS_COUNT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_function_names,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","function-names"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_FUNCTION_NAMES_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_copy_namespaces_mode,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","copy-namespaces-mode"), 
        GENV_TYPESYSTEM.STRING_TYPE_PLUS),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_COPY_NAMESPACES_MODE_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_boundary_space_policy,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","boundary-space-policy"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_BOUNDARY_SPACE_POLICY_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_default_order,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","default-order"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_DEFAULT_ORDER_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_ordering_mode,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","ordering-mode"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_ORDERING_MODE_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_construction_mode,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","construction-mode"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_CONSTRUCTION_MODE_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_statically_known_collations,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","statically-known-collations"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_STAR),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_STATICALLY_KNOWN_COLLATIONS_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_statically_known_document_type,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","statically-known-document-type"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_STATICALLY_KNOWN_DOCUMENT_TYPE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_statically_known_documents,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","statically-known-documents"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_STAR),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_STATICALLY_KNOWN_DOCUMENTS_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_xpath10_compatibility_mode,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","xpath10-compatibility-mode"), 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_XPATH10_COMPATIBILITY_MODE_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_default_collection_type,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","default-collection-type"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_DEFAULT_COLLECTION_TYPE_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_in_scope_variables,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","in-scope-variables"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IN_SCOPE_VARIABLES_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_statically_known_namespace_binding,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","statically-known-namespace-binding"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_STATICALLY_KNOWN_NAMESPACE_BINDING_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_default_collation,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","default-collation"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_DEFAULT_COLLATION_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_base_uri,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","base-uri"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_BASE_URI_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_default_function_namespace,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","default-function-namespace"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_DEFAULT_FUNCTION_NAMESPACE_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_introspect_sctx_statically_known_namespaces,
        (createQName("http://www.zorba-xquery.com/modules/introspection/sctx","","statically-known-namespaces"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR),
        FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_STATICALLY_KNOWN_NAMESPACES_0);

  }

}


}



