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


#ifndef ZORBA_FUNCTIONS_NUMERICS_H
#define ZORBA_FUNCTIONS_NUMERICS_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_numerics(static_context* sctx);




//fn:abs
class fn_abs : public function
{
public:
  fn_abs(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ABS_1)
  {
  }

  CODEGEN_DECL();
};


//fn:ceiling
class fn_ceiling : public function
{
public:
  fn_ceiling(const signature& sig)
    :
    function(sig, FunctionConsts::FN_CEILING_1)
  {
  }

  CODEGEN_DECL();
};


//fn:floor
class fn_floor : public function
{
public:
  fn_floor(const signature& sig)
    :
    function(sig, FunctionConsts::FN_FLOOR_1)
  {
  }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;

  CODEGEN_DECL();
};


//fn:round
class fn_round : public function
{
public:
  fn_round(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ROUND_1)
  {
  }

  CODEGEN_DECL();
};


//fn:round-half-to-even
class fn_round_half_to_even : public function
{
public:
  fn_round_half_to_even(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
                FunctionConsts::FN_ROUND_HALF_TO_EVEN_1 :
                FunctionConsts::FN_ROUND_HALF_TO_EVEN_2);
  }

  CODEGEN_DECL();
};


//fn:format-number
class fn_format_number : public function
{
public:
  fn_format_number(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 2 ?
                FunctionConsts::FN_FORMAT_NUMBER_2 :
                FunctionConsts::FN_FORMAT_NUMBER_3);
    theXQueryVersion = StaticContextConsts::xquery_version_1_1;
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
