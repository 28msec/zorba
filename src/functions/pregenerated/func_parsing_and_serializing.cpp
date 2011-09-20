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
#include "runtime/parsing_and_serializing/parsing_and_serializing.h"
#include "functions/func_parsing_and_serializing.h"


namespace zorba{



PlanIter_t fn_parse_xml_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnParseXmlIterator(sctx, loc, argv);
}

PlanIter_t fn_serialize_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnSerializeIterator(sctx, loc, argv);
}

void populate_context_parsing_and_serializing(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_parse_xml_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","parse-xml"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE),
        FunctionConsts::FN_PARSE_XML_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_parse_xml_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","parse-xml"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::FN_PARSE_XML_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_serialize_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","serialize"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_SERIALIZE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_serialize_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","serialize"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_SERIALIZE_2);

  }

}


}



