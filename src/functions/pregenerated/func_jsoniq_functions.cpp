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
#include "runtime/json/jsoniq_functions.h"
#include "functions/func_jsoniq_functions.h"


namespace zorba{


#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_flatten::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new JSONFlattenIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_names::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new JSONNamesIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_name::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new JSONNameIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_pairs::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new JSONPairsIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_size::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new JSONSizeIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_values::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new JSONValuesIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_value::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new JSONValueIterator(sctx, loc, argv);
}

#endif

void populate_context_jsoniq_functions(static_context* sctx)
{

#ifdef ZORBA_WITH_JSON
  {
    

    DECL_WITH_KIND(sctx, fn_jsoniq_flatten,
        (createQName("http://www.jsoniq.org/functions","","flatten"), 
        GENV_TYPESYSTEM.JSON_ARRAY_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_FLATTEN_1);

  }


#endif


#ifdef ZORBA_WITH_JSON
  {
    

    DECL_WITH_KIND(sctx, fn_jsoniq_parse_json,
        (createQName("http://www.jsoniq.org/functions","","parse-json"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.JSON_ITEM_TYPE_QUESTION),
        FunctionConsts::FN_JSONIQ_PARSE_JSON_1);

  }


#endif


#ifdef ZORBA_WITH_JSON
  {
    

    DECL_WITH_KIND(sctx, fn_jsoniq_names,
        (createQName("http://www.jsoniq.org/functions","","names"), 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_JSONIQ_NAMES_1);

  }


#endif


#ifdef ZORBA_WITH_JSON
  {
    

    DECL_WITH_KIND(sctx, fn_jsoniq_name,
        (createQName("http://www.jsoniq.org/functions","","name"), 
        GENV_TYPESYSTEM.JSON_PAIR_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_JSONIQ_NAME_1);

  }


#endif


#ifdef ZORBA_WITH_JSON
  {
    

    DECL_WITH_KIND(sctx, fn_jsoniq_pairs,
        (createQName("http://www.jsoniq.org/functions","","pairs"), 
        GENV_TYPESYSTEM.JSON_ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.JSON_PAIR_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_PAIRS_1);

  }


#endif


#ifdef ZORBA_WITH_JSON
  {
    

    DECL_WITH_KIND(sctx, fn_jsoniq_size,
        (createQName("http://www.jsoniq.org/functions","","size"), 
        GENV_TYPESYSTEM.JSON_ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::FN_JSONIQ_SIZE_1);

  }


#endif


#ifdef ZORBA_WITH_JSON
  {
    

    DECL_WITH_KIND(sctx, fn_jsoniq_values,
        (createQName("http://www.jsoniq.org/functions","","values"), 
        GENV_TYPESYSTEM.JSON_ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_VALUES_1);

  }


#endif


#ifdef ZORBA_WITH_JSON
  {
    

    DECL_WITH_KIND(sctx, fn_jsoniq_value,
        (createQName("http://www.jsoniq.org/functions","","value"), 
        GENV_TYPESYSTEM.JSON_PAIR_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE),
        FunctionConsts::FN_JSONIQ_VALUE_1);

  }


#endif
}


}



