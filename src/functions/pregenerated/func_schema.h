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


#ifndef ZORBA_FUNCTIONS_SCHEMA_H
#define ZORBA_FUNCTIONS_SCHEMA_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_schema(static_context* sctx);




//fn-zorba-util:schema-type
class fn_zorba_util_schema_type : public function
{
public:
  fn_zorba_util_schema_type(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_UTIL_SCHEMA_TYPE_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-schema:schema-type
class fn_zorba_schema_schema_type : public function
{
public:
  fn_zorba_schema_schema_type(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_SCHEMA_SCHEMA_TYPE_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-schema:is-validated
class fn_zorba_schema_is_validated : public function
{
public:
  fn_zorba_schema_is_validated(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_SCHEMA_IS_VALIDATED_1)
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
