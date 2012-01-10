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


#ifndef ZORBA_FUNCTIONS_JSONIQ_FUNCTIONS_H
#define ZORBA_FUNCTIONS_JSONIQ_FUNCTIONS_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_jsoniq_functions(static_context* sctx);


#ifdef ZORBA_WITH_JSON

//fn-jsoniq:flatten
class fn_jsoniq_flatten : public function
{
public:
  fn_jsoniq_flatten(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:parse-json
class fn_jsoniq_parse_json : public function
{
public:
  fn_jsoniq_parse_json(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  bool accessesDynCtx() const { return true; }

  bool isSource() const { return true; }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:names
class fn_jsoniq_names : public function
{
public:
  fn_jsoniq_names(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:name
class fn_jsoniq_name : public function
{
public:
  fn_jsoniq_name(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:pairs
class fn_jsoniq_pairs : public function
{
public:
  fn_jsoniq_pairs(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:pair
class fn_jsoniq_pair : public function
{
public:
  fn_jsoniq_pair(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:member
class fn_jsoniq_member : public function
{
public:
  fn_jsoniq_member(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:size
class fn_jsoniq_size : public function
{
public:
  fn_jsoniq_size(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:values
class fn_jsoniq_values : public function
{
public:
  fn_jsoniq_values(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:value
class fn_jsoniq_value : public function
{
public:
  fn_jsoniq_value(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};
#endif


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
