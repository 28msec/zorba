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

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_names::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONNamesIterator(sctx, loc, argv[0]);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_value::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONValueAccessorIterator(sctx, loc, argv[0], argv[1]);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_size::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONSizeIterator(sctx, loc, argv[0]);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_member::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONMemberAccessorIterator(sctx, loc, argv[0], argv[1]);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_flatten::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONFlattenIterator(sctx, loc, argv[0]);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t op_zorba_json_item_accessor::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONItemAccessorIterator(sctx, loc, argv[0], argv[1]);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t op_zorba_json_empty_item_accessor::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONEmptyItemAccessorIterator(sctx, loc, argv[0]);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_values::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONValuesIterator(sctx, loc, argv[0]);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_null::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONNullIterator(sctx, loc);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_insert_as_first::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONInsertAsFirstIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_insert_after::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONInsertAfterIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_insert_before::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONInsertBeforeIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_insert_as_last::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONInsertAsLastIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_delete_pair::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONDeleteIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_rename::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONRenameIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t fn_jsoniq_replace_value_in_object::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONReplaceValueIterator(sctx, loc, argv);
}

#endif
#ifdef ZORBA_WITH_JSON
PlanIter_t op_zorba_json_unbox::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONUnboxingIterator(sctx, loc, argv[0]);
}

#endif

void populate_context_jsoniq_functions(static_context* sctx)
{

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
        GENV_TYPESYSTEM.STRING_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_NAMES_1);

  }


#endif


#ifdef ZORBA_WITH_JSON


      {
    DECL_WITH_KIND(sctx, fn_jsoniq_value,
        (createQName("http://www.jsoniq.org/functions","","value"), 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION),
        FunctionConsts::FN_JSONIQ_VALUE_2);

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
    DECL_WITH_KIND(sctx, fn_jsoniq_member,
        (createQName("http://www.jsoniq.org/functions","","member"), 
        GENV_TYPESYSTEM.JSON_ARRAY_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION),
        FunctionConsts::FN_JSONIQ_MEMBER_2);

  }


#endif


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
    DECL_WITH_KIND(sctx, op_zorba_json_item_accessor,
        (createQName("http://www.zorba-xquery.com/internal/zorba-ops","","json-item-accessor"), 
        GENV_TYPESYSTEM.JSON_ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION),
        FunctionConsts::OP_ZORBA_JSON_ITEM_ACCESSOR_2);

  }


#endif


#ifdef ZORBA_WITH_JSON


      {
    DECL_WITH_KIND(sctx, op_zorba_json_empty_item_accessor,
        (createQName("http://www.zorba-xquery.com/internal/zorba-ops","","json-empty-item-accessor"), 
        GENV_TYPESYSTEM.JSON_ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_STAR),
        FunctionConsts::OP_ZORBA_JSON_EMPTY_ITEM_ACCESSOR_1);

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
    DECL_WITH_KIND(sctx, fn_jsoniq_null,
        (createQName("http://www.jsoniq.org/functions","","null"), 
        GENV_TYPESYSTEM.JDM_NULL_TYPE_ONE),
        FunctionConsts::FN_JSONIQ_NULL_0);

  }


#endif


#ifdef ZORBA_WITH_JSON


      {
    DECL_WITH_KIND(sctx, fn_jsoniq_insert_as_first,
        (createQName("http://www.jsoniq.org/functions","","insert-as-first"), 
        GENV_TYPESYSTEM.JSON_ARRAY_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::FN_JSONIQ_INSERT_AS_FIRST_2);

  }


#endif


#ifdef ZORBA_WITH_JSON


      {
    DECL_WITH_KIND(sctx, fn_jsoniq_insert_after,
        (createQName("http://www.jsoniq.org/functions","","insert-after"), 
        GENV_TYPESYSTEM.JSON_ARRAY_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::FN_JSONIQ_INSERT_AFTER_3);

  }


#endif


#ifdef ZORBA_WITH_JSON


      {
    DECL_WITH_KIND(sctx, fn_jsoniq_insert_before,
        (createQName("http://www.jsoniq.org/functions","","insert-before"), 
        GENV_TYPESYSTEM.JSON_ARRAY_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::FN_JSONIQ_INSERT_BEFORE_3);

  }


#endif


#ifdef ZORBA_WITH_JSON


      {
    DECL_WITH_KIND(sctx, fn_jsoniq_insert_as_last,
        (createQName("http://www.jsoniq.org/functions","","insert-as-last"), 
        GENV_TYPESYSTEM.JSON_ARRAY_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::FN_JSONIQ_INSERT_AS_LAST_2);

  }


#endif


#ifdef ZORBA_WITH_JSON


      {
    DECL_WITH_KIND(sctx, fn_jsoniq_delete_pair,
        (createQName("http://www.jsoniq.org/functions","","delete-pair"), 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::FN_JSONIQ_DELETE_PAIR_2);

  }


#endif


#ifdef ZORBA_WITH_JSON


      {
    DECL_WITH_KIND(sctx, fn_jsoniq_delete_pair,
        (createQName("http://www.jsoniq.org/functions","","delete-member"), 
        GENV_TYPESYSTEM.JSON_ARRAY_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::FN_JSONIQ_DELETE_MEMBER_2);

  }


#endif


#ifdef ZORBA_WITH_JSON


      {
    DECL_WITH_KIND(sctx, fn_jsoniq_rename,
        (createQName("http://www.jsoniq.org/functions","","rename"), 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::FN_JSONIQ_RENAME_3);

  }


#endif


#ifdef ZORBA_WITH_JSON


      {
    DECL_WITH_KIND(sctx, fn_jsoniq_replace_value_in_object,
        (createQName("http://www.jsoniq.org/functions","","replace-value-in-object"), 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::FN_JSONIQ_REPLACE_VALUE_IN_OBJECT_3);

  }


#endif


#ifdef ZORBA_WITH_JSON


      {
    DECL_WITH_KIND(sctx, fn_jsoniq_replace_value_in_object,
        (createQName("http://www.jsoniq.org/functions","","replace-value-in-array"), 
        GENV_TYPESYSTEM.JSON_ARRAY_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::FN_JSONIQ_REPLACE_VALUE_IN_ARRAY_3);

  }


#endif


#ifdef ZORBA_WITH_JSON


      {
    DECL_WITH_KIND(sctx, op_zorba_json_unbox,
        (createQName("http://www.zorba-xquery.com/internal/zorba-ops","","json-unbox"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::OP_ZORBA_JSON_UNBOX_1);

  }


#endif
}


}



