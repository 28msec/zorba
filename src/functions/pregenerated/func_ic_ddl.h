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




//fn-zorba-xqddf:activate-integrity-constraint
class fn_zorba_xqddf_activate_integrity_constraint : public function
{
public:
  fn_zorba_xqddf_activate_integrity_constraint(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_XQDDF_ACTIVATE_INTEGRITY_CONSTRAINT_1)
  {
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-xqddf:deactivate-integrity-constraint
class fn_zorba_xqddf_deactivate_integrity_constraint : public function
{
public:
  fn_zorba_xqddf_deactivate_integrity_constraint(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_XQDDF_DEACTIVATE_INTEGRITY_CONSTRAINT_1)
  {
  }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn-zorba-xqddf:check-integrity-constraint
class fn_zorba_xqddf_check_integrity_constraint : public function
{
public:
  fn_zorba_xqddf_check_integrity_constraint(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_XQDDF_CHECK_INTEGRITY_CONSTRAINT_1)
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
