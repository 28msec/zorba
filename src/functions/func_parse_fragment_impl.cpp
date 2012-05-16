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
#include "stdafx.h"

#include "common/shared_types.h"
#include "types/typeops.h"

#include "functions/function.h"
#include "functions/function_impl.h"

#include "functions/func_parse_fragment.h"

#include "system/globalenv.h"

#include "compiler/expression/expr_consts.h"


namespace zorba
{


/*******************************************************************************

********************************************************************************/
void populate_context_parse_fragment_impl(static_context* sctx)
{
  xqtref_t lParseOptType =
    GENV_TYPESYSTEM.create_node_type(
        store::StoreConsts::elementNode,
        createQName("http://www.zorba-xquery.com/modules/xml-options","","options"),
        NULL,
        TypeConstants::QUANT_QUESTION,
        false,
        false
      );

  {
    DECL_WITH_KIND(sctx, fn_zorba_xml_parse,
        (createQName("http://www.zorba-xquery.com/modules/xml","","parse"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        lParseOptType, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::FN_ZORBA_XML_PARSE_2);
  }
}

}

/* vim:set et sw=2 ts=2: */
