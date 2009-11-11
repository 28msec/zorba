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


#ifndef ZORBA_FUNCTIONS_MATHS_H
#define ZORBA_FUNCTIONS_MATHS_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba{


void populate_context_maths(static_context* sctx);




//fn-zorba-math:sqrt
class fn_zorba_math_sqrt : public function
{
public:
  fn_zorba_math_sqrt(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_SQRT_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:atan2
class fn_zorba_math_atan2 : public function
{
public:
  fn_zorba_math_atan2(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_ATAN2_2)
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
