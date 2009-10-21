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
#include "functions/function_impl.h"

#include "functions/strings_impl.h"
#include "runtime/strings/StringsImpl.h"

namespace zorba {

// 7.2.2 fn:string-to-codepoints
typedef function_impl<StringToCodepointsIterator> fn_string_to_codepoints;

// 7.6.4 fn:tokenize
typedef function_impl<FnTokenizeIterator> fn_tokenize;

void populate_context_strings_impl(static_context* sctx)
{
  DECL(sctx, fn_string_to_codepoints,
       (createQName(XQUERY_FN_NS,"fn","string-to-codepoints"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

  DECL(sctx, fn_tokenize,
       (createQName(XQUERY_FN_NS,"fn","tokenize"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_STAR));

  DECL(sctx, fn_tokenize,
       (createQName(XQUERY_FN_NS,"fn","tokenize"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_STAR));
}

}/* namespace zorba */
