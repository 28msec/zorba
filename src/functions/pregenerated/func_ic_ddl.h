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


#ifndef ZORBA_FUNCTIONS_IC_DDL_H
#define ZORBA_FUNCTIONS_IC_DDL_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_ic_ddl(static_context* sctx);




//zorba-store-collections-static-init:activate-integrity-constraint
class zorba_store_collections_static_init_activate_integrity_constraint : public function
{
public:
  zorba_store_collections_static_init_activate_integrity_constraint(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-init:deactivate-integrity-constraint
class zorba_store_collections_static_init_deactivate_integrity_constraint : public function
{
public:
  zorba_store_collections_static_init_deactivate_integrity_constraint(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-collections-static-manip:check-integrity-constraint
class zorba_store_collections_static_manip_check_integrity_constraint : public function
{
public:
  zorba_store_collections_static_manip_check_integrity_constraint(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

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
