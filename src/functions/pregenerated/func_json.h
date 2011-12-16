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


#ifndef ZORBA_FUNCTIONS_JSON_H
#define ZORBA_FUNCTIONS_JSON_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_json(static_context* sctx);




//fn-zorba-json:parse-internal
class fn_zorba_json_parse_internal : public function
{
public:
  fn_zorba_json_parse_internal(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//fn-zorba-json:serialize-internal
class fn_zorba_json_serialize_internal : public function
{
public:
  fn_zorba_json_serialize_internal(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

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
