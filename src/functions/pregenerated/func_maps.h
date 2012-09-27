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




//zorba-store-data-structure-unordered-map:create
class zorba_store_data_structure_unordered_map_create : public function
{
public:
  zorba_store_data_structure_unordered_map_create(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return SEQUENTIAL_FUNC_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-data-structure-unordered-map:create-transient
class zorba_store_data_structure_unordered_map_create_transient : public function
{
public:
  zorba_store_data_structure_unordered_map_create_transient(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return SEQUENTIAL_FUNC_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-data-structure-unordered-map:delete
class zorba_store_data_structure_unordered_map_delete : public function
{
public:
  zorba_store_data_structure_unordered_map_delete(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return SEQUENTIAL_FUNC_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-data-structure-unordered-map:get
class zorba_store_data_structure_unordered_map_get : public function
{
public:
  zorba_store_data_structure_unordered_map_get(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-data-structure-unordered-map:insert
class zorba_store_data_structure_unordered_map_insert : public function
{
public:
  zorba_store_data_structure_unordered_map_insert(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return SEQUENTIAL_FUNC_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-data-structure-unordered-map:remove
class zorba_store_data_structure_unordered_map_remove : public function
{
public:
  zorba_store_data_structure_unordered_map_remove(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  unsigned short getScriptingKind() const { return SEQUENTIAL_FUNC_EXPR; }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-data-structure-unordered-map:keys
class zorba_store_data_structure_unordered_map_keys : public function
{
public:
  zorba_store_data_structure_unordered_map_keys(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-data-structure-unordered-map:size
class zorba_store_data_structure_unordered_map_size : public function
{
public:
  zorba_store_data_structure_unordered_map_size(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-data-structure-unordered-map:available-maps
class zorba_store_data_structure_unordered_map_available_maps : public function
{
public:
  zorba_store_data_structure_unordered_map_available_maps(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//zorba-store-data-structure-unordered-map:is-transient
class zorba_store_data_structure_unordered_map_is_transient : public function
{
public:
  zorba_store_data_structure_unordered_map_is_transient(const signature& sig, FunctionConsts::FunctionKind kind)
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
