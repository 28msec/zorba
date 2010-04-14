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


#ifndef ZORBA_FUNCTIONS_SCTX_H
#define ZORBA_FUNCTIONS_SCTX_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_sctx(static_context* sctx);




//fn-zorba-introspect-sctx:is-declared-collection
class fn_zorba_introspect_sctx_is_declared_collection : public function
{
public:
  fn_zorba_introspect_sctx_is_declared_collection(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IS_DECLARED_COLLECTION_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:declared-collections
class fn_zorba_introspect_sctx_declared_collections : public function
{
public:
  fn_zorba_introspect_sctx_declared_collections(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_DECLARED_COLLECTIONS_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:is-declared-index
class fn_zorba_introspect_sctx_is_declared_index : public function
{
public:
  fn_zorba_introspect_sctx_is_declared_index(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IS_DECLARED_INDEX_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:declared-indexes
class fn_zorba_introspect_sctx_declared_indexes : public function
{
public:
  fn_zorba_introspect_sctx_declared_indexes(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_DECLARED_INDEXES_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:statically-known-namespaces
class fn_zorba_introspect_sctx_statically_known_namespaces : public function
{
public:
  fn_zorba_introspect_sctx_statically_known_namespaces(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_STATICALLY_KNOWN_NAMESPACES_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:statically-known-namespace-binding
class fn_zorba_introspect_sctx_statically_known_namespace_binding : public function
{
public:
  fn_zorba_introspect_sctx_statically_known_namespace_binding(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_STATICALLY_KNOWN_NAMESPACE_BINDING_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:in-scope-variables
class fn_zorba_introspect_sctx_in_scope_variables : public function
{
public:
  fn_zorba_introspect_sctx_in_scope_variables(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IN_SCOPE_VARIABLES_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:default-collection-type
class fn_zorba_introspect_sctx_default_collection_type : public function
{
public:
  fn_zorba_introspect_sctx_default_collection_type(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_DEFAULT_COLLECTION_TYPE_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:xpath10-compatibility-mode
class fn_zorba_introspect_sctx_xpath10_compatibility_mode : public function
{
public:
  fn_zorba_introspect_sctx_xpath10_compatibility_mode(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_XPATH10_COMPATIBILITY_MODE_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:statically-known-documents
class fn_zorba_introspect_sctx_statically_known_documents : public function
{
public:
  fn_zorba_introspect_sctx_statically_known_documents(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_STATICALLY_KNOWN_DOCUMENTS_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:statically-known-document-type
class fn_zorba_introspect_sctx_statically_known_document_type : public function
{
public:
  fn_zorba_introspect_sctx_statically_known_document_type(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_STATICALLY_KNOWN_DOCUMENT_TYPE_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:statically-known-collations
class fn_zorba_introspect_sctx_statically_known_collations : public function
{
public:
  fn_zorba_introspect_sctx_statically_known_collations(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_STATICALLY_KNOWN_COLLATIONS_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:construction-mode
class fn_zorba_introspect_sctx_construction_mode : public function
{
public:
  fn_zorba_introspect_sctx_construction_mode(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_CONSTRUCTION_MODE_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:ordering-mode
class fn_zorba_introspect_sctx_ordering_mode : public function
{
public:
  fn_zorba_introspect_sctx_ordering_mode(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_ORDERING_MODE_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:default-order
class fn_zorba_introspect_sctx_default_order : public function
{
public:
  fn_zorba_introspect_sctx_default_order(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_DEFAULT_ORDER_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:boundary-space-policy
class fn_zorba_introspect_sctx_boundary_space_policy : public function
{
public:
  fn_zorba_introspect_sctx_boundary_space_policy(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_BOUNDARY_SPACE_POLICY_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:copy-namespaces-mode
class fn_zorba_introspect_sctx_copy_namespaces_mode : public function
{
public:
  fn_zorba_introspect_sctx_copy_namespaces_mode(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_COPY_NAMESPACES_MODE_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:function-names
class fn_zorba_introspect_sctx_function_names : public function
{
public:
  fn_zorba_introspect_sctx_function_names(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_FUNCTION_NAMES_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:function-arguments-count
class fn_zorba_introspect_sctx_function_arguments_count : public function
{
public:
  fn_zorba_introspect_sctx_function_arguments_count(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_FUNCTION_ARGUMENTS_COUNT_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:in-scope-schema-types
class fn_zorba_introspect_sctx_in_scope_schema_types : public function
{
public:
  fn_zorba_introspect_sctx_in_scope_schema_types(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IN_SCOPE_SCHEMA_TYPES_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:in-scope-element-declarations
class fn_zorba_introspect_sctx_in_scope_element_declarations : public function
{
public:
  fn_zorba_introspect_sctx_in_scope_element_declarations(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IN_SCOPE_ELEMENT_DECLARATIONS_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:in-scope-attribute-declarations
class fn_zorba_introspect_sctx_in_scope_attribute_declarations : public function
{
public:
  fn_zorba_introspect_sctx_in_scope_attribute_declarations(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IN_SCOPE_ATTRIBUTE_DECLARATIONS_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:is-declared-integrity-constraint
class fn_zorba_introspect_sctx_is_declared_integrity_constraint : public function
{
public:
  fn_zorba_introspect_sctx_is_declared_integrity_constraint(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_IS_DECLARED_INTEGRITY_CONSTRAINT_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-introspect-sctx:declared-integrity-constraints
class fn_zorba_introspect_sctx_declared_integrity_constraints : public function
{
public:
  fn_zorba_introspect_sctx_declared_integrity_constraints(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_SCTX_DECLARED_INTEGRITY_CONSTRAINTS_0)
  {
  }

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
