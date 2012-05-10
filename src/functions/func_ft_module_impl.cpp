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
#include "functions/func_ft_module_impl.h"

#include "runtime/full_text/ft_module.h"

#define FT_MODULE_NS "http://www.zorba-xquery.com/modules/full-text"

namespace zorba 
{

#ifndef ZORBA_NO_FULL_TEXT

PlanIter_t full_text_tokenize::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new TokenizeIterator(sctx, loc, argv);
}


PlanIter_t full_text_tokenizer_properties::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new TokenizerPropertiesIterator(sctx, loc, argv);
}


PlanIter_t full_text_current_compare_options::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new CurrentCompareOptionsIterator(sctx, loc, argv);
}

#endif // ZORBA_NO_FULL_TEXT

///////////////////////////////////////////////////////////////////////////////

void populate_context_ft_module_impl(static_context* sctx) 
{
#ifndef ZORBA_NO_FULL_TEXT

  xqtref_t current_compare_options_return_type =
  GENV_TYPESYSTEM.create_node_type(store::StoreConsts::elementNode,
                                   createQName(FT_MODULE_NS, "", "compare-options"),
                                   NULL,
                                   TypeConstants::QUANT_ONE,
                                   false,
                                   false);
  {
    DECL_WITH_KIND(sctx,
                   full_text_current_compare_options,
                   (createQName(FT_MODULE_NS, "", "current-compare-options"),
                    current_compare_options_return_type),
                   FunctionConsts::FULL_TEXT_CURRENT_COMPARE_OPTIONS_0);
  }

  xqtref_t tokenize_return_type =
  GENV_TYPESYSTEM.create_node_type(store::StoreConsts::elementNode,
                                   createQName(FT_MODULE_NS, "", "token"),
                                   NULL,
                                   TypeConstants::QUANT_STAR,
                                   false,
                                   false);
  {
    DECL_WITH_KIND(sctx,
                   full_text_tokenize,
                   (createQName(FT_MODULE_NS, "", "tokenize"),
                    GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
                    tokenize_return_type),
                   FunctionConsts::FULL_TEXT_TOKENIZE_1);
  }
  {
    DECL_WITH_KIND(sctx,
                   full_text_tokenize,
                   (createQName( FT_MODULE_NS, "", "tokenize"),
                    GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
                    GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE,
                    tokenize_return_type),
                   FunctionConsts::FULL_TEXT_TOKENIZE_2);
  }
  {
    DECL_WITH_KIND(sctx,
                   full_text_tokenize,
                   (createQName( FT_MODULE_NS, "", "tokenize"),
                    GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
                    GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
                    GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
                    tokenize_return_type),
                   FunctionConsts::FULL_TEXT_TOKENIZE_3);
  }
  {
    DECL_WITH_KIND(sctx,
                   full_text_tokenize,
                   (createQName( FT_MODULE_NS, "", "tokenize"),
                    GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
                    GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
                    GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
                    GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE,
                    tokenize_return_type),
                   FunctionConsts::FULL_TEXT_TOKENIZE_4);
  }

  xqtref_t tokenizer_properties_return_type =
  GENV_TYPESYSTEM.create_node_type(store::StoreConsts::elementNode,
                                   createQName(FT_MODULE_NS, "", "tokenizer-properties"),
                                   NULL,
                                   TypeConstants::QUANT_ONE,
                                   false,
                                   false);
  {
    DECL_WITH_KIND(sctx,
                   full_text_tokenizer_properties,
                   (createQName(FT_MODULE_NS, "", "tokenizer-properties"),
                    tokenizer_properties_return_type),
                   FunctionConsts::FULL_TEXT_TOKENIZER_PROPERTIES_0);
  }
  {
    DECL_WITH_KIND(sctx, 
                   full_text_tokenizer_properties,
                   (createQName( FT_MODULE_NS, "", "tokenizer-properties"),
                    GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE,
                    tokenizer_properties_return_type),
                   FunctionConsts::FULL_TEXT_TOKENIZER_PROPERTIES_1);
  }
#endif /* ZORBA_NO_FULL_TEXT */
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
