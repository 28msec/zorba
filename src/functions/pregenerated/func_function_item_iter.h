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


#ifndef ZORBA_FUNCTIONS_FUNCTION_ITEM_ITER_H
#define ZORBA_FUNCTIONS_FUNCTION_ITEM_ITER_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_function_item_iter(static_context* sctx);




//fn:function-name
class fn_function_name : public function
{
public:
  fn_function_name(const signature& sig)
    :
    function(sig, FunctionConsts::FN_FUNCTION_NAME_1)
  {
  }

  CODEGEN_DECL();
};


//fn:function-arity
class fn_function_arity : public function
{
public:
  fn_function_arity(const signature& sig)
    :
    function(sig, FunctionConsts::FN_FUNCTION_ARITY_1)
  {
  }

  CODEGEN_DECL();
};


//fn:partial-apply
class fn_partial_apply : public function
{
public:
  fn_partial_apply(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 2 ?
                FunctionConsts::FN_PARTIAL_APPLY_2 :
                FunctionConsts::FN_PARTIAL_APPLY_3);
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
