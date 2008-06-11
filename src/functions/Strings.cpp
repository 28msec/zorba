#include "functions/function_impl.h"

#include "runtime/strings/StringsImpl.h"

namespace zorba {

  /*______________________________________________________________________
   *
   * 7.2 Functions to Assemble and Disassemble Strings
   *_______________________________________________________________________*/

  /*
   * 7.2.1 fn:codepoints-to-string
   * --------------------*/

  typedef function_impl<CodepointsToStringIterator> fn_codepoints_to_string;



  /*
   * 7.2.2 fn:string-to-codepoints
   * --------------------*/

  typedef function_impl<StringToCodepointsIterator> fn_string_to_codepoints;



  /*______________________________________________________________________
   *
   * 7.3 Equality and Comparison of Strings
   *_______________________________________________________________________*/

  /*
   * 7.3.2 fn:compare
   *-----------------------*/
  typedef function_impl<CompareStrIterator> fn_string_compare;


  /*
   * 7.3.3 fn:codepoint-equal
   * --------------------*/

  typedef function_impl<CodepointEqualIterator> fn_codepoint_equal;



  /*______________________________________________________________________
   *
   * 7.4 Functions on String Values
   *_______________________________________________________________________*/

  /*
   * 7.4.1 fn:concat
   *-----------------------*/

  typedef function_impl<ConcatStrIterator> fn_concat;


  /*
   * 7.4.2 fn:string-join
   * --------------------*/

  typedef function_impl<StringJoinIterator> fn_string_join;


  /*
   * 7.4.3 fn:substring
   *-----------------------*/
  
  typedef function_impl<SubstringIterator> fn_substring;


  /*
   * 7.4.4 fn:string-length
   * --------------------*/

  typedef function_impl<StringLengthIterator> fn_string_length;


  /*
   * 7.4.5 fn:normalize-space
   * --------------------*/

  typedef function_impl<NormalizeSpaceIterator> fn_normalize_space;


  /*
   * 7.4.6 fn:normalize-unicode
   *-----------------------*/

  typedef function_impl<NormalizeUnicodeIterator> fn_normalize_unicode;


  /*
   * 7.4.7 fn:upper-case
   * --------------------*/

  typedef function_impl<UpperCaseIterator> fn_upper_case;


  /*
   * 7.4.8 fn:lower-case
   * --------------------*/

  typedef function_impl<LowerCaseIterator> fn_lower_case;


  /*
   * 7.4.9 fn:translate
   *-----------------------*/

  typedef function_impl<TranslateIterator> fn_translate;


  /*
   * 7.4.10 fn:encode-for-uri
   * --------------------*/

  typedef function_impl<EncodeForUriIterator> fn_encode_for_uri;


  /*
   * 7.4.11 fn:iri-to-uri
   * --------------------*/

  typedef function_impl<IriToUriIterator> fn_iri_to_uri;


  /*
   * 7.4.12 fn:escape-html-uri
   * --------------------*/

  typedef function_impl<EscapeHtmlUriIterator> fn_escape_html_uri;


  /*______________________________________________________________________
   *
   * 7.5 Functions Based on Substring Matching
   *_______________________________________________________________________*/

  typedef function_impl<ContainsIterator> fn_contains;


  /*
   * 7.5.2 fn:starts-with
   *-----------------------*/

  typedef function_impl<StartsWithIterator> fn_starts_with;


  /*
   * 7.5.3 fn:ends-with
   *-----------------------*/

  typedef function_impl<EndsWithIterator> fn_ends_with;


  /*
   * 7.5.4 fn:substring-before
   *-----------------------*/

  typedef function_impl<SubstringBeforeIterator> fn_substring_before;


  /*
   * 7.5.5 fn:substring-after
   *-----------------------*/

  typedef function_impl<SubstringAfterIterator> fn_substring_after;


  /*______________________________________________________________________
   *
   * 7.6 String Functions that Use Pattern Matching
   *_______________________________________________________________________*/
  /*
   * 7.6.2 fn:matches
   *-----------------------*/

  typedef function_impl<FnMatchesIterator> fn_matches;


  /*
   * 7.6.3 fn:replace
   *-----------------------*/

  typedef function_impl<FnReplaceIterator> fn_replace;


  /*
   * 7.6.4 fn:tokenize
   *-----------------------*/

  typedef function_impl<FnTokenizeIterator> fn_tokenize;

void populateContext_Strings(static_context *sctx) {
// Strings
DECL(sctx, fn_codepoints_to_string,
     (createQName(XQUERY_FN_NS,"fn","codepoints-to-string"),
      GENV_TYPESYSTEM.INTEGER_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_string_to_codepoints,
     (createQName(XQUERY_FN_NS,"fn","string-to-codepoints"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

DECL(sctx, fn_string_compare,
     (createQName(XQUERY_FN_NS,"fn","compare"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_string_compare,
     (createQName(XQUERY_FN_NS,"fn","compare"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION));

DECL(sctx, fn_codepoint_equal,
     (createQName(XQUERY_FN_NS,"fn","codepoint-equal"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

// the string concat function, not the sequence op:concat
DECL(sctx, fn_concat,
     (createQName(XQUERY_FN_NS,"fn","concat"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      true, GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_string_join,
     (createQName(XQUERY_FN_NS,"fn","string-join"),
      GENV_TYPESYSTEM.STRING_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_substring,
     (createQName(XQUERY_FN_NS,"fn","substring"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_substring,
     (createQName(XQUERY_FN_NS,"fn","substring"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_string_length,
     (createQName(XQUERY_FN_NS,"fn","string-length"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

DECL(sctx, fn_normalize_space,
     (createQName(XQUERY_FN_NS,"fn","normalize-space"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_normalize_unicode,
     (createQName(XQUERY_FN_NS,"fn","normalize-unicode"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_normalize_unicode,
     (createQName(XQUERY_FN_NS,"fn","normalize-unicode"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_upper_case,
     (createQName(XQUERY_FN_NS,"fn","upper-case"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_lower_case,
     (createQName(XQUERY_FN_NS,"fn","lower-case"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_translate,
     (createQName(XQUERY_FN_NS,"fn","translate"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_encode_for_uri,
     (createQName(XQUERY_FN_NS,"fn","encode-for-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_iri_to_uri,
     (createQName(XQUERY_FN_NS,"fn","iri-to-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_escape_html_uri,
     (createQName(XQUERY_FN_NS,"fn","escape-html-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_contains,
     (createQName(XQUERY_FN_NS,"fn","contains"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
      
DECL(sctx, fn_contains,
     (createQName(XQUERY_FN_NS,"fn","contains"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_starts_with,
     (createQName(XQUERY_FN_NS,"fn","starts-with"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_starts_with,
     (createQName(XQUERY_FN_NS,"fn","starts-with"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_ends_with,
     (createQName(XQUERY_FN_NS,"fn","ends-with"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_ends_with,
     (createQName(XQUERY_FN_NS,"fn","ends-with"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_substring_before,
     (createQName(XQUERY_FN_NS,"fn","substring-before"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_substring_before,
     (createQName(XQUERY_FN_NS,"fn","substring-before"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_substring_after,
     (createQName(XQUERY_FN_NS,"fn","substring-after"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_substring_after,
     (createQName(XQUERY_FN_NS,"fn","substring-after"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_matches,
     (createQName(XQUERY_FN_NS,"fn","matches"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_matches,
     (createQName(XQUERY_FN_NS,"fn","matches"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_replace,
     (createQName(XQUERY_FN_NS,"fn","replace"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_replace,
     (createQName(XQUERY_FN_NS,"fn","replace"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

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
// end Strings

}
 
}
