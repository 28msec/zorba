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


#ifndef ZORBA_FUNCTIONS_BASE64_H
#define ZORBA_FUNCTIONS_BASE64_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_base64(static_context* sctx);




//fn-zorba-base64:decode
class fn_zorba_base64_decode : public function
{
public:
  fn_zorba_base64_decode(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn-zorba-base64:encode
class fn_zorba_base64_encode : public function
{
public:
  fn_zorba_base64_encode(const signature& sig, FunctionConsts::FunctionKind kind)
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
