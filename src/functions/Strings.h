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
#ifndef ZORBA_STRINGS_H
#define ZORBA_STRINGS_H

#include <vector>

#include "common/shared_types.h"

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
 
} /* namespace zorba */
#endif /* ZORBA_STRINGS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
