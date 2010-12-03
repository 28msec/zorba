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


#include "runtime/convertors/convertors.h"
#include "functions/func_convertors.h"
#include "system/globalenv.h"
#include "types/typeops.h"


namespace zorba{



PlanIter_t fn_zorba_json_parse::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaJsonParseIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_json_serialize::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaJsonSerializeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_json_parse_ml::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaJsonParseMLIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_json_serialize_ml::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaJsonSerializeMLIterator(sctx, loc, argv);
}

void populate_context_convertors(static_context* sctx)
{
  DECL(sctx, fn_zorba_json_parse,
      (createQName("http://www.zorba-xquery.com/modules/json","","parse"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));


  DECL(sctx, fn_zorba_json_serialize,
      (createQName("http://www.zorba-xquery.com/modules/json","","serialize"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_STAR));


  DECL(sctx, fn_zorba_json_parse_ml,
      (createQName("http://www.zorba-xquery.com/modules/json","","parse-ml"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));


  DECL(sctx, fn_zorba_json_serialize_ml,
      (createQName("http://www.zorba-xquery.com/modules/json","","serialize-ml"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_STAR));

}


}



