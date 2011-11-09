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
#include "runtime/strings/strings.h"
#include "functions/func_strings.h"


namespace zorba{



PlanIter_t fn_codepoints_to_string::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CodepointsToStringIterator(sctx, loc, argv);
}

PlanIter_t fn_string_to_codepoints::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StringToCodepointsIterator(sctx, loc, argv);
}

PlanIter_t fn_compare::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CompareStrIterator(sctx, loc, argv);
}

PlanIter_t fn_codepoint_equal::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CodepointEqualIterator(sctx, loc, argv);
}

PlanIter_t fn_concat::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ConcatStrIterator(sctx, loc, argv);
}

PlanIter_t fn_string_join_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StringJoinIterator(sctx, loc, argv);
}
PlanIter_t fn_string_join::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StringJoinIterator(sctx, loc, argv);
}

PlanIter_t fn_substring::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new SubstringIterator(sctx, loc, argv);
}

PlanIter_t fn_string_length::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StringLengthIterator(sctx, loc, argv);
}

PlanIter_t fn_normalize_space::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NormalizeSpaceIterator(sctx, loc, argv);
}

PlanIter_t fn_normalize_unicode::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NormalizeUnicodeIterator(sctx, loc, argv);
}

PlanIter_t fn_upper_case::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new UpperCaseIterator(sctx, loc, argv);
}

PlanIter_t fn_lower_case::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new LowerCaseIterator(sctx, loc, argv);
}

PlanIter_t fn_translate::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new TranslateIterator(sctx, loc, argv);
}

PlanIter_t fn_encode_for_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new EncodeForUriIterator(sctx, loc, argv);
}

PlanIter_t fn_iri_to_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IriToUriIterator(sctx, loc, argv);
}

PlanIter_t fn_escape_html_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new EscapeHtmlUriIterator(sctx, loc, argv);
}

PlanIter_t fn_contains::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ContainsIterator(sctx, loc, argv);
}

PlanIter_t fn_starts_with::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StartsWithIterator(sctx, loc, argv);
}

PlanIter_t fn_ends_with::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new EndsWithIterator(sctx, loc, argv);
}

PlanIter_t fn_substring_before::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new SubstringBeforeIterator(sctx, loc, argv);
}

PlanIter_t fn_substring_after::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new SubstringAfterIterator(sctx, loc, argv);
}

PlanIter_t fn_matches::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnMatchesIterator(sctx, loc, argv);
}

PlanIter_t fn_replace::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnReplaceIterator(sctx, loc, argv);
}

PlanIter_t fn_tokenize::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnTokenizeIterator(sctx, loc, argv);
}

PlanIter_t fn_analyze_string_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnAnalyzeStringIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_string_materialize::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StringMaterializeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_string_is_streamable::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new StringIsStreamableIterator(sctx, loc, argv);
}

void populate_context_strings(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_codepoints_to_string,
        (createQName("http://www.w3.org/2005/xpath-functions","","codepoints-to-string"), 
        GENV_TYPESYSTEM.INTEGER_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_CODEPOINTS_TO_STRING_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_string_to_codepoints,
        (createQName("http://www.w3.org/2005/xpath-functions","","string-to-codepoints"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_STAR),
        FunctionConsts::FN_STRING_TO_CODEPOINTS_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_compare,
        (createQName("http://www.w3.org/2005/xpath-functions","","compare"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_COMPARE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_compare,
        (createQName("http://www.w3.org/2005/xpath-functions","","compare"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION),
        FunctionConsts::FN_COMPARE_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_codepoint_equal,
        (createQName("http://www.w3.org/2005/xpath-functions","","codepoint-equal"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION),
        FunctionConsts::FN_CODEPOINT_EQUAL_2);

  }


  {
    std::vector<xqtref_t> lParamTypes;
    lParamTypes.push_back(GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION);

    DECL_WITH_KIND(sctx, fn_concat,
        (createQName("http://www.w3.org/2005/xpath-functions","","concat"), 
        lParamTypes, GENV_TYPESYSTEM.STRING_TYPE_ONE, true),
        FunctionConsts::FN_CONCAT_N);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_string_join_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","string-join"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_STRING_JOIN_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_string_join,
        (createQName("http://www.w3.org/2005/xpath-functions","","string-join"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_STRING_JOIN_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_substring,
        (createQName("http://www.w3.org/2005/xpath-functions","","substring"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_SUBSTRING_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_substring,
        (createQName("http://www.w3.org/2005/xpath-functions","","substring"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_SUBSTRING_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_string_length,
        (createQName("http://www.w3.org/2005/xpath-functions","","string-length"), 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::FN_STRING_LENGTH_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_string_length,
        (createQName("http://www.w3.org/2005/xpath-functions","","string-length"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::FN_STRING_LENGTH_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_normalize_space,
        (createQName("http://www.w3.org/2005/xpath-functions","","normalize-space"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_NORMALIZE_SPACE_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_normalize_space,
        (createQName("http://www.w3.org/2005/xpath-functions","","normalize-space"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_NORMALIZE_SPACE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_normalize_unicode,
        (createQName("http://www.w3.org/2005/xpath-functions","","normalize-unicode"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_NORMALIZE_UNICODE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_normalize_unicode,
        (createQName("http://www.w3.org/2005/xpath-functions","","normalize-unicode"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_NORMALIZE_UNICODE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_upper_case,
        (createQName("http://www.w3.org/2005/xpath-functions","","upper-case"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_UPPER_CASE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_lower_case,
        (createQName("http://www.w3.org/2005/xpath-functions","","lower-case"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_LOWER_CASE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_translate,
        (createQName("http://www.w3.org/2005/xpath-functions","","translate"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_TRANSLATE_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_encode_for_uri,
        (createQName("http://www.w3.org/2005/xpath-functions","","encode-for-uri"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ENCODE_FOR_URI_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_iri_to_uri,
        (createQName("http://www.w3.org/2005/xpath-functions","","iri-to-uri"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_IRI_TO_URI_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_escape_html_uri,
        (createQName("http://www.w3.org/2005/xpath-functions","","escape-html-uri"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ESCAPE_HTML_URI_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_contains,
        (createQName("http://www.w3.org/2005/xpath-functions","","contains"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_CONTAINS_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_contains,
        (createQName("http://www.w3.org/2005/xpath-functions","","contains"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_CONTAINS_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_starts_with,
        (createQName("http://www.w3.org/2005/xpath-functions","","starts-with"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_STARTS_WITH_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_starts_with,
        (createQName("http://www.w3.org/2005/xpath-functions","","starts-with"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_STARTS_WITH_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_ends_with,
        (createQName("http://www.w3.org/2005/xpath-functions","","ends-with"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ENDS_WITH_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_ends_with,
        (createQName("http://www.w3.org/2005/xpath-functions","","ends-with"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ENDS_WITH_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_substring_before,
        (createQName("http://www.w3.org/2005/xpath-functions","","substring-before"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_SUBSTRING_BEFORE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_substring_before,
        (createQName("http://www.w3.org/2005/xpath-functions","","substring-before"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_SUBSTRING_BEFORE_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_substring_after,
        (createQName("http://www.w3.org/2005/xpath-functions","","substring-after"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_SUBSTRING_AFTER_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_substring_after,
        (createQName("http://www.w3.org/2005/xpath-functions","","substring-after"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_SUBSTRING_AFTER_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_matches,
        (createQName("http://www.w3.org/2005/xpath-functions","","matches"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_MATCHES_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_matches,
        (createQName("http://www.w3.org/2005/xpath-functions","","matches"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_MATCHES_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_replace,
        (createQName("http://www.w3.org/2005/xpath-functions","","replace"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_REPLACE_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_replace,
        (createQName("http://www.w3.org/2005/xpath-functions","","replace"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_REPLACE_4);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_tokenize,
        (createQName("http://www.w3.org/2005/xpath-functions","","tokenize"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_STAR),
        FunctionConsts::FN_TOKENIZE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_tokenize,
        (createQName("http://www.w3.org/2005/xpath-functions","","tokenize"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_STAR),
        FunctionConsts::FN_TOKENIZE_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_analyze_string_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","analyze-string"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_ONE),
        FunctionConsts::FN_ANALYZE_STRING_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_analyze_string_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","analyze-string"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_ONE),
        FunctionConsts::FN_ANALYZE_STRING_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_string_materialize,
        (createQName("http://www.zorba-xquery.com/modules/string","","materialize"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRING_MATERIALIZE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_string_is_streamable,
        (createQName("http://www.zorba-xquery.com/modules/string","","is-streamable"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRING_IS_STREAMABLE_1);

  }

}


}



