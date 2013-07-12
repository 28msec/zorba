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
#include "runtime/json/json.h"
#include "functions/func_json.h"


namespace zorba{



PlanIter_t fn_zorba_json_json_to_xml_internal::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONtoXMLInternal(sctx, loc, argv);
}

PlanIter_t fn_zorba_json_xml_to_json_internal::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new XMLtoJSONInternal(sctx, loc, argv);
}

void populate_context_json(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, fn_zorba_json_json_to_xml_internal,
        (createQName("http://zorba.io/modules/json-xml","","json-to-xml-internal"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_STAR),
        FunctionConsts::FN_ZORBA_JSON_JSON_TO_XML_INTERNAL_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_json_xml_to_json_internal,
        (createQName("http://zorba.io/modules/json-xml","","xml-to-json-internal"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_JSON_XML_TO_JSON_INTERNAL_2);

  }

}


}



