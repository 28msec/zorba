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

#include "functions/func_strings.h"

#include "system/globalenv.h"

#include "compiler/expression/expr_consts.h"


namespace zorba
{

/*******************************************************************************

********************************************************************************/
BoolAnnotationValue fn_concat::ignoresSortedNodes(
    expr* fo,
    csize input) const 
{
  return ANNOTATION_TRUE;
}


BoolAnnotationValue fn_concat::ignoresDuplicateNodes(
    expr* fo, 
    csize input) const 
{
  return ANNOTATION_TRUE;
}


/*******************************************************************************

********************************************************************************/
function* fn_substring::specialize( 
    static_context* sctx,
    const std::vector<xqtref_t>& argTypes) const
{
  assert(false);
  return NULL;
}


/*******************************************************************************

********************************************************************************/
void populate_context_strings_impl(static_context* sctx)
{
  xqtref_t lAnalyzeStringResultType =
    GENV_TYPESYSTEM.create_node_type(
        store::StoreConsts::elementNode,
        createQName("http://www.w3.org/2005/xpath-functions","","analyze-string-result"),
        NULL,
        TypeConstants::QUANT_ONE,
        false,
        false
      );

  {
    DECL_WITH_KIND(sctx, fn_analyze_string_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","analyze-string"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        lAnalyzeStringResultType),
        FunctionConsts::FN_ANALYZE_STRING_2);

  }


  {
    DECL_WITH_KIND(sctx, fn_analyze_string_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","analyze-string"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        lAnalyzeStringResultType),
        FunctionConsts::FN_ANALYZE_STRING_3);
  }
}

}

/* vim:set et sw=2 ts=2: */
