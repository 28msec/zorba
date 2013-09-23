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


#ifndef ZORBA_FUNCTIONS_MAPS_H
#define ZORBA_FUNCTIONS_MAPS_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_maps(static_context* sctx);




//zorba-store-unordered-maps:create
class zorba_store_unordered_maps_create : public function
{
public:
  zorba_store_unordered_maps_create(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return SEQUENTIAL_FUNC_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-unordered-maps:drop
class zorba_store_unordered_maps_drop : public function
{
public:
  zorba_store_unordered_maps_drop(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return SEQUENTIAL_FUNC_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-unordered-maps:get
class zorba_store_unordered_maps_get : public function
{
public:
  zorba_store_unordered_maps_get(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-unordered-maps:insert
class zorba_store_unordered_maps_insert : public function
{
public:
  zorba_store_unordered_maps_insert(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return SEQUENTIAL_FUNC_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return true; }

  CODEGEN_DECL();
};


//zorba-store-unordered-maps:delete
class zorba_store_unordered_maps_delete : public function
{
public:
  zorba_store_unordered_maps_delete(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return SEQUENTIAL_FUNC_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-unordered-maps:keys
class zorba_store_unordered_maps_keys : public function
{
public:
  zorba_store_unordered_maps_keys(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-unordered-maps:size
class zorba_store_unordered_maps_size : public function
{
public:
  zorba_store_unordered_maps_size(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-unordered-maps:available-maps
class zorba_store_unordered_maps_available_maps : public function
{
public:
  zorba_store_unordered_maps_available_maps(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-unordered-maps:options
class zorba_store_unordered_maps_options : public function
{
public:
  zorba_store_unordered_maps_options(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
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
