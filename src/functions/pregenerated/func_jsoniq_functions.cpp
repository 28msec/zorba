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
#include "runtime/json/jsoniq_functions.h"
#include "functions/func_jsoniq_functions.h"


namespace zorba{



PlanIter_t fn_jsoniq_decode_from_roundtrip::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONDecodeFromRoundtripIterator(sctx, loc, argv);
}

PlanIter_t fn_jsoniq_encode_for_roundtrip::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONEncodeForRoundtripIterator(sctx, loc, argv);
}



PlanIter_t op_zorba_keys::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new SingleObjectKeysIterator(sctx, loc, argv[0]);
}


PlanIter_t op_zorba_single_object_lookup::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new SingleObjectLookupIterator(sctx, loc, argv[0], argv[1]);
}

PlanIter_t fn_jsoniq_project::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONObjectProjectIterator(sctx, loc, argv[0], argv[1]);
}

PlanIter_t fn_jsoniq_trim::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONObjectTrimIterator(sctx, loc, argv[0], argv[1]);
}


PlanIter_t op_zorba_members::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new SingleArrayMembersIterator(sctx, loc, argv[0]);
}


PlanIter_t op_zorba_single_array_lookup::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new SingleArrayLookupIterator(sctx, loc, argv[0], argv[1]);
}

PlanIter_t fn_jsoniq_size::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONArraySizeIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_jsoniq_flatten::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONArrayFlattenIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_jsoniq_null::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONNullIterator(sctx, loc);
}

PlanIter_t op_zorba_json_object_insert::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONObjectInsertIterator(sctx, loc, argv);
}

PlanIter_t op_zorba_json_array_insert::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONArrayInsertIterator(sctx, loc, argv);
}

PlanIter_t op_zorba_json_delete::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONDeleteIterator(sctx, loc, argv[0], argv[1]);
}


PlanIter_t op_zorba_json_rename::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONRenameIterator(sctx, loc, argv);
}

PlanIter_t op_zorba_json_array_append::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONArrayAppendIterator(sctx, loc, argv);
}

PlanIter_t op_zorba_json_box::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONBoxIterator(sctx, loc, argv[0]);
}

void populate_context_jsoniq_functions(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, fn_jsoniq_decode_from_roundtrip,
        (createQName("http://jsoniq.org/functions","","decode-from-roundtrip"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_DECODE_FROM_ROUNDTRIP_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_jsoniq_decode_from_roundtrip,
        (createQName("http://jsoniq.org/functions","","decode-from-roundtrip"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_DECODE_FROM_ROUNDTRIP_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_jsoniq_encode_for_roundtrip,
        (createQName("http://jsoniq.org/functions","","encode-for-roundtrip"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_ENCODE_FOR_ROUNDTRIP_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_jsoniq_encode_for_roundtrip,
        (createQName("http://jsoniq.org/functions","","encode-for-roundtrip"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_ENCODE_FOR_ROUNDTRIP_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_jsoniq_parse_json,
        (createQName("http://jsoniq.org/functions","","parse-json"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.JSON_ITEM_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_PARSE_JSON_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_jsoniq_parse_json,
        (createQName("http://jsoniq.org/functions","","parse-json"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.JSON_ITEM_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_PARSE_JSON_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_jsoniq_keys,
        (createQName("http://jsoniq.org/functions","","keys"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_KEYS_1);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_keys,
        (createQName("http://zorba.io/internal/zorba-ops","","keys"), 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_STAR),
        FunctionConsts::OP_ZORBA_KEYS_1);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_multi_object_lookup,
        (createQName("http://zorba.io/internal/zorba-ops","","multi-object-lookup"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::OP_ZORBA_MULTI_OBJECT_LOOKUP_2);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_single_object_lookup,
        (createQName("http://zorba.io/internal/zorba-ops","","single-object-lookup"), 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION),
        FunctionConsts::OP_ZORBA_SINGLE_OBJECT_LOOKUP_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_jsoniq_project,
        (createQName("http://jsoniq.org/functions","","project"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_PROJECT_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_jsoniq_trim,
        (createQName("http://jsoniq.org/functions","","trim"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_TRIM_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_jsoniq_members,
        (createQName("http://jsoniq.org/functions","","members"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_MEMBERS_1);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_members,
        (createQName("http://zorba.io/internal/zorba-ops","","members"), 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::OP_ZORBA_MEMBERS_1);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_multi_array_lookup,
        (createQName("http://zorba.io/internal/zorba-ops","","multi-array-lookup"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::OP_ZORBA_MULTI_ARRAY_LOOKUP_2);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_single_array_lookup,
        (createQName("http://zorba.io/internal/zorba-ops","","single-array-lookup"), 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION),
        FunctionConsts::OP_ZORBA_SINGLE_ARRAY_LOOKUP_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_jsoniq_size,
        (createQName("http://jsoniq.org/functions","","size"), 
        GENV_TYPESYSTEM.JSON_ARRAY_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_JSONIQ_SIZE_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_jsoniq_flatten,
        (createQName("http://jsoniq.org/functions","","flatten"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_JSONIQ_FLATTEN_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_jsoniq_null,
        (createQName("http://jsoniq.org/functions","","null"), 
        GENV_TYPESYSTEM.JS_NULL_TYPE_ONE),
        FunctionConsts::FN_JSONIQ_NULL_0);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_json_object_insert,
        (createQName("http://zorba.io/internal/zorba-ops","","json-object-insert"), 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::OP_ZORBA_JSON_OBJECT_INSERT_2);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_json_array_insert,
        (createQName("http://zorba.io/internal/zorba-ops","","json-array-insert"), 
        GENV_TYPESYSTEM.JSON_ARRAY_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::OP_ZORBA_JSON_ARRAY_INSERT_3);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_json_delete,
        (createQName("http://zorba.io/internal/zorba-ops","","json-delete"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::OP_ZORBA_JSON_DELETE_2);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_json_replace_value,
        (createQName("http://zorba.io/internal/zorba-ops","","json-replace-value"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::OP_ZORBA_JSON_REPLACE_VALUE_3);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_json_rename,
        (createQName("http://zorba.io/internal/zorba-ops","","json-rename"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::OP_ZORBA_JSON_RENAME_3);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_json_array_append,
        (createQName("http://zorba.io/internal/zorba-ops","","json-array-append"), 
        GENV_TYPESYSTEM.JSON_ARRAY_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::OP_ZORBA_JSON_ARRAY_APPEND_2);

  }




      {
    DECL_WITH_KIND(sctx, op_zorba_json_box,
        (createQName("http://zorba.io/internal/zorba-ops","","json-box"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE),
        FunctionConsts::OP_ZORBA_JSON_BOX_1);

  }

}


}



