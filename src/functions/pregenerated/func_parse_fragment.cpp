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
#include "runtime/parsing_and_serializing/parse_fragment.h"
#include "functions/func_parse_fragment.h"


namespace zorba{



PlanIter_t fn_zorba_xml_parse_xml::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnParseXmlFragmentIterator(sctx, loc, argv);
}

void populate_context_parse_fragment(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_zorba_xml_parse_xml,
        (createQName("http://www.zorba-xquery.com/modules/xml","","parse-xml"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::FN_ZORBA_XML_PARSE_XML_2);

  }

}


}



