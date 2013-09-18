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


#include "stdafx.h"
#include "runtime/store/maps.h"
#include "functions/func_maps.h"


namespace zorba{



PlanIter_t zorba_store_unordered_maps_create::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapCreateIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_unordered_maps_drop::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapDropIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_unordered_maps_get::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapGetIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_unordered_maps_insert::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapInsertIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_unordered_maps_delete::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapDeleteIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_unordered_maps_keys::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapKeysIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_unordered_maps_size::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapSizeIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_unordered_maps_available_maps::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new AvailableMapsIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_unordered_maps_options::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapOptionsIterator(sctx, loc, argv);
}

void populate_context_maps(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, zorba_store_unordered_maps_create,
        (createQName("http://zorba.io/modules/unordered-maps","","create"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_UNORDERED_MAPS_CREATE_2);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_unordered_maps_create,
        (createQName("http://zorba.io/modules/unordered-maps","","create"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_UNORDERED_MAPS_CREATE_3);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_unordered_maps_drop,
        (createQName("http://zorba.io/modules/unordered-maps","","drop"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_UNORDERED_MAPS_DROP_1);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_unordered_maps_get,
        (createQName("http://zorba.io/modules/unordered-maps","","get"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_UNORDERED_MAPS_GET_2);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_unordered_maps_insert,
        (createQName("http://zorba.io/modules/unordered-maps","","insert"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_UNORDERED_MAPS_INSERT_3);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_unordered_maps_delete,
        (createQName("http://zorba.io/modules/unordered-maps","","delete"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_UNORDERED_MAPS_DELETE_2);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_unordered_maps_keys,
        (createQName("http://zorba.io/modules/unordered-maps","","keys"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.JSON_ARRAY_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_UNORDERED_MAPS_KEYS_1);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_unordered_maps_size,
        (createQName("http://zorba.io/modules/unordered-maps","","size"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_UNORDERED_MAPS_SIZE_1);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_unordered_maps_available_maps,
        (createQName("http://zorba.io/modules/unordered-maps","","available-maps"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_UNORDERED_MAPS_AVAILABLE_MAPS_0);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_unordered_maps_options,
        (createQName("http://zorba.io/modules/unordered-maps","","options"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_UNORDERED_MAPS_OPTIONS_1);

  }

}


}



