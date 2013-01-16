/*
 * Copyright 2006-2012 The FLWOR Foundation.
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


#ifndef ZORBA_FUNCTIONS_REFERENCE_H
#define ZORBA_FUNCTIONS_REFERENCE_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_reference(static_context* sctx);




//fn-reference:reference
class fn_reference_reference : public function
{
public:
  fn_reference_reference(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return true; }

  CODEGEN_DECL();
};


//fn-reference:has-reference
class fn_reference_has_reference : public function
{
public:
  fn_reference_has_reference(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn-reference:assign-reference
class fn_reference_assign_reference : public function
{
public:
  fn_reference_assign_reference(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return SEQUENTIAL_FUNC_EXPR; }

  CODEGEN_DECL();
};


//fn-reference:dereference
class fn_reference_dereference : public function
{
public:
  fn_reference_dereference(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
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
