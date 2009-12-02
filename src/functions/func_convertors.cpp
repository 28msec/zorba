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



PlanIter_t zorba_json_parse::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaJsonParseIterator ( sctx, loc, argv);
}

PlanIter_t zorba_json_serialize::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaJsonSerializeIterator ( sctx, loc, argv);
}

PlanIter_t zorba_json_ml_parse::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaJsonMLParseIterator ( sctx, loc, argv);
}

PlanIter_t zorba_json_ml_serialize::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaJsonMLSerializeIterator ( sctx, loc, argv);
}

PlanIter_t zorba_csv_csv2xml::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ZorbaCSV2XMLIterator ( sctx, loc, argv);
}

void populate_context_convertors(static_context* sctx) {
  DECL(sctx, zorba_json_parse,
      (createQName("http://www.zorba-xquery.com/zorba/json-functions","zorba-json","parse"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));


  DECL(sctx, zorba_json_serialize,
      (createQName("http://www.zorba-xquery.com/zorba/json-functions","zorba-json","serialize"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_STAR));


  DECL(sctx, zorba_json_ml_parse,
      (createQName("http://www.zorba-xquery.com/zorba/json-ml-functions","zorba-json-ml","parse"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));


  DECL(sctx, zorba_json_ml_serialize,
      (createQName("http://www.zorba-xquery.com/zorba/json-ml-functions","zorba-json-ml","serialize"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_STAR));


  DECL(sctx, zorba_csv_csv2xml,
      (createQName("http://www.zorba-xquery.com/modules/csv2xml","zorba-csv","csv2xml"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

}


}