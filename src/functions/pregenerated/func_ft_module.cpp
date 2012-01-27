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
#include "runtime/full_text/ft_module.h"
#include "functions/func_ft_module.h"


namespace zorba{



PlanIter_t zorba_full_text_current_lang::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CurrentLangIterator(sctx, loc, argv);
}

PlanIter_t zorba_full_text_host_lang::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new HostLangIterator(sctx, loc, argv);
}

PlanIter_t zorba_full_text_is_stop_word::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsStopWordIterator(sctx, loc, argv);
}

PlanIter_t zorba_full_text_stem::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StemIterator(sctx, loc, argv);
}

PlanIter_t zorba_full_text_strip_diacritics::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StripDiacriticsIterator(sctx, loc, argv);
}

PlanIter_t zorba_full_text_thesaurus_lookup::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ThesaurusLookupIterator(sctx, loc, argv);
}

PlanIter_t zorba_full_text_tokenize::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new TokenizeIterator(sctx, loc, argv);
}

PlanIter_t zorba_full_text_tokenizer_properties::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new TokenizerPropertiesIterator(sctx, loc, argv);
}

void populate_context_ft_module(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_current_lang,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","current-lang"), 
        GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE),
        FunctionConsts::ZORBA_FULL_TEXT_CURRENT_LANG_0);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_host_lang,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","host-lang"), 
        GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE),
        FunctionConsts::ZORBA_FULL_TEXT_HOST_LANG_0);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_is_stop_word,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","is-stop-word"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::ZORBA_FULL_TEXT_IS_STOP_WORD_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_is_stop_word,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","is-stop-word"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::ZORBA_FULL_TEXT_IS_STOP_WORD_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_stem,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","stem"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::ZORBA_FULL_TEXT_STEM_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_stem,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","stem"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::ZORBA_FULL_TEXT_STEM_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_strip_diacritics,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","strip-diacritics"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::ZORBA_FULL_TEXT_STRIP_DIACRITICS_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_thesaurus_lookup,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","thesaurus-lookup"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_PLUS),
        FunctionConsts::ZORBA_FULL_TEXT_THESAURUS_LOOKUP_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_thesaurus_lookup,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","thesaurus-lookup"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_PLUS),
        FunctionConsts::ZORBA_FULL_TEXT_THESAURUS_LOOKUP_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_thesaurus_lookup,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","thesaurus-lookup"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_PLUS),
        FunctionConsts::ZORBA_FULL_TEXT_THESAURUS_LOOKUP_3);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_thesaurus_lookup,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","thesaurus-lookup"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_PLUS),
        FunctionConsts::ZORBA_FULL_TEXT_THESAURUS_LOOKUP_4);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_thesaurus_lookup,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","thesaurus-lookup"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_PLUS),
        FunctionConsts::ZORBA_FULL_TEXT_THESAURUS_LOOKUP_6);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_tokenize,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","tokenize"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_FULL_TEXT_TOKENIZE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_tokenize,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","tokenize"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_FULL_TEXT_TOKENIZE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_tokenizer_properties,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","tokenizer-properties"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE),
        FunctionConsts::ZORBA_FULL_TEXT_TOKENIZER_PROPERTIES_0);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_full_text_tokenizer_properties,
        (createQName("http://www.zorba-xquery.com/modules/full-text","","tokenizer-properties"), 
        GENV_TYPESYSTEM.LANGUAGE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE),
        FunctionConsts::ZORBA_FULL_TEXT_TOKENIZER_PROPERTIES_1);

  }

}


}



