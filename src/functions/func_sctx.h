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


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
