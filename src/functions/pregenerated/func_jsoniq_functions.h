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

//fn-jsoniq:parse-json
class fn_jsoniq_parse_json : public function
{
public:
  fn_jsoniq_parse_json(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  bool isSource() const { return true; }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:keys
class fn_jsoniq_keys : public function
{
public:
  fn_jsoniq_keys(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool propagatesInputNodes(expr* fo, csize producer) const { return false; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:value
class fn_jsoniq_value : public function
{
public:
  fn_jsoniq_value(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool propagatesInputNodes(expr* fo, csize producer) const { return producer == 0; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:project
class fn_jsoniq_project : public function
{
public:
  fn_jsoniq_project(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool propagatesInputNodes(expr* fo, csize producer) const { return producer == 0; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:size
class fn_jsoniq_size : public function
{
public:
  fn_jsoniq_size(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool propagatesInputNodes(expr* fo, csize producer) const { return false; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:member
class fn_jsoniq_member : public function
{
public:
  fn_jsoniq_member(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool propagatesInputNodes(expr* fo, csize producer) const { return producer == 0; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:members
class fn_jsoniq_members : public function
{
public:
  fn_jsoniq_members(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool propagatesInputNodes(expr* fo, csize producer) const { return producer == 0; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:flatten
class fn_jsoniq_flatten : public function
{
public:
  fn_jsoniq_flatten(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool propagatesInputNodes(expr* fo, csize producer) const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//op-zorba:json-item-accessor
class op_zorba_json_item_accessor : public function
{
public:
  op_zorba_json_item_accessor(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool propagatesInputNodes(expr* fo, csize producer) const { return producer == 0; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//fn-jsoniq:null
class fn_jsoniq_null : public function
{
public:
  fn_jsoniq_null(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//op-zorba:json-array-insert
class op_zorba_json_array_insert : public function
{
public:
  op_zorba_json_array_insert(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//op-zorba:json-delete
class op_zorba_json_delete : public function
{
public:
  op_zorba_json_delete(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//op-zorba:json-replace-value
class op_zorba_json_replace_value : public function
{
public:
  op_zorba_json_replace_value(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//op-zorba:json-rename
class op_zorba_json_rename : public function
{
public:
  op_zorba_json_rename(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};
#endif
#ifdef ZORBA_WITH_JSON

//op-zorba:json-array-append
class op_zorba_json_array_append : public function
{
public:
  op_zorba_json_array_append(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const;

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
