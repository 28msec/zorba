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


#include "stdafx.h"
#include "runtime/store/maps.h"
#include "functions/func_maps.h"


namespace zorba{



PlanIter_t zorba_store_data_structure_unordered_map_create::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapCreateIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_data_structure_unordered_map_delete::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapDestroyIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_data_structure_unordered_map_get::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapGetIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_data_structure_unordered_map_insert::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapInsertIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_data_structure_unordered_map_remove::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapRemoveIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_data_structure_unordered_map_keys::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapKeysIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_data_structure_unordered_map_size::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new MapSizeIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_data_structure_unordered_map_available_maps::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new AvailableMapsIterator(sctx, loc, argv);
}

void populate_context_maps(static_context* sctx)
{
  {
    std::vector<xqtref_t> lParamTypes;
    lParamTypes.push_back(GENV_TYPESYSTEM.QNAME_TYPE_ONE);
    lParamTypes.push_back(GENV_TYPESYSTEM.QNAME_TYPE_ONE);

    DECL_WITH_KIND(sctx, zorba_store_data_structure_unordered_map_create,
        (createQName("http://www.zorba-xquery.com/modules/store/data-structures/unordered-map","","create"), 
        lParamTypes, GENV_TYPESYSTEM.EMPTY_TYPE, true),
        FunctionConsts::ZORBA_STORE_DATA_STRUCTURE_UNORDERED_MAP_CREATE_N);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_data_structure_unordered_map_delete,
        (createQName("http://www.zorba-xquery.com/modules/store/data-structures/unordered-map","","delete"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DATA_STRUCTURE_UNORDERED_MAP_DELETE_1);

  }


  {
    std::vector<xqtref_t> lParamTypes;
    lParamTypes.push_back(GENV_TYPESYSTEM.QNAME_TYPE_ONE);
    lParamTypes.push_back(GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION);

    DECL_WITH_KIND(sctx, zorba_store_data_structure_unordered_map_get,
        (createQName("http://www.zorba-xquery.com/modules/store/data-structures/unordered-map","","get"), 
        lParamTypes, GENV_TYPESYSTEM.ITEM_TYPE_STAR, true),
        FunctionConsts::ZORBA_STORE_DATA_STRUCTURE_UNORDERED_MAP_GET_N);

  }


  {
    std::vector<xqtref_t> lParamTypes;
    lParamTypes.push_back(GENV_TYPESYSTEM.QNAME_TYPE_ONE);
    lParamTypes.push_back(GENV_TYPESYSTEM.ITEM_TYPE_STAR);
    lParamTypes.push_back(GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION);

    DECL_WITH_KIND(sctx, zorba_store_data_structure_unordered_map_insert,
        (createQName("http://www.zorba-xquery.com/modules/store/data-structures/unordered-map","","insert"), 
        lParamTypes, GENV_TYPESYSTEM.EMPTY_TYPE, true),
        FunctionConsts::ZORBA_STORE_DATA_STRUCTURE_UNORDERED_MAP_INSERT_N);

  }


  {
    std::vector<xqtref_t> lParamTypes;
    lParamTypes.push_back(GENV_TYPESYSTEM.QNAME_TYPE_ONE);
    lParamTypes.push_back(GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION);

    DECL_WITH_KIND(sctx, zorba_store_data_structure_unordered_map_remove,
        (createQName("http://www.zorba-xquery.com/modules/store/data-structures/unordered-map","","remove"), 
        lParamTypes, GENV_TYPESYSTEM.EMPTY_TYPE, true),
        FunctionConsts::ZORBA_STORE_DATA_STRUCTURE_UNORDERED_MAP_REMOVE_N);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_data_structure_unordered_map_keys,
        (createQName("http://www.zorba-xquery.com/modules/store/data-structures/unordered-map","","keys"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_DATA_STRUCTURE_UNORDERED_MAP_KEYS_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_data_structure_unordered_map_size,
        (createQName("http://www.zorba-xquery.com/modules/store/data-structures/unordered-map","","size"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_DATA_STRUCTURE_UNORDERED_MAP_SIZE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_data_structure_unordered_map_available_maps,
        (createQName("http://www.zorba-xquery.com/modules/store/data-structures/unordered-map","","available-maps"), 
        GENV_TYPESYSTEM.QNAME_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_DATA_STRUCTURE_UNORDERED_MAP_AVAILABLE_MAPS_0);

  }

}


}



