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


#ifndef ZORBA_FUNCTIONS_DCTX_H
#define ZORBA_FUNCTIONS_DCTX_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_dctx(static_context* sctx);




//fn-zorba-introspect-dctx:is-available-collection
class fn_zorba_introspect_dctx_is_available_collection : public function
{
public:
  fn_zorba_introspect_dctx_is_available_collection(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_DCTX_IS_AVAILABLE_COLLECTION_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-introspect-dctx:available-collections
class fn_zorba_introspect_dctx_available_collections : public function
{
public:
  fn_zorba_introspect_dctx_available_collections(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_DCTX_AVAILABLE_COLLECTIONS_0)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-introspect-dctx:is-available-index
class fn_zorba_introspect_dctx_is_available_index : public function
{
public:
  fn_zorba_introspect_dctx_is_available_index(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_DCTX_IS_AVAILABLE_INDEX_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-introspect-dctx:available-indexes
class fn_zorba_introspect_dctx_available_indexes : public function
{
public:
  fn_zorba_introspect_dctx_available_indexes(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_DCTX_AVAILABLE_INDEXES_0)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-introspect-dctx:is-activated-integrity-constraint
class fn_zorba_introspect_dctx_is_activated_integrity_constraint : public function
{
public:
  fn_zorba_introspect_dctx_is_activated_integrity_constraint(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_DCTX_IS_ACTIVATED_INTEGRITY_CONSTRAINT_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-introspect-dctx:activated-integrity-constraints
class fn_zorba_introspect_dctx_activated_integrity_constraints : public function
{
public:
  fn_zorba_introspect_dctx_activated_integrity_constraints(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INTROSPECT_DCTX_ACTIVATED_INTEGRITY_CONSTRAINTS_0)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
