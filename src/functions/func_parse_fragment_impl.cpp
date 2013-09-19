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
  // Note: the actual type of the 2nd param should be element(options)?
  // However, we cannot use a non-builtin type in the signature of a builtin
  // function. That's why we use type element() here and do special handling
  // of this function in the translator.
  DECL_WITH_KIND(sctx, fn_zorba_xml_parse,
                 (createQName(static_context::ZORBA_XML_FN_OPTIONS_NS, "", "parse"), 
                  GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
                  GENV_TYPESYSTEM.ELEMENT_TYPE_QUESTION, 
                  GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
                 FunctionConsts::FN_ZORBA_XML_PARSE_2);

}

}

/* vim:set et sw=2 ts=2: */
