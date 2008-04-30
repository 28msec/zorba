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
   *-----------------------*/
  class fn_codepoints_to_string: public function
  {
  public:
    fn_codepoints_to_string(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 7.2.2 fn:string-to-codepoints
   *-----------------------*/
  class fn_string_to_codepoints: public function
  {
  public:
    fn_string_to_codepoints(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

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
   *-----------------------*/
  class fn_codepoint_equal: public function
  {
  public:
    fn_codepoint_equal(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*______________________________________________________________________
   *
   * 7.4 Functions on String Values
   *_______________________________________________________________________*/

  /*
   * 7.4.1 fn:concat
   *-----------------------*/
  class fn_concat: public function
  {
  public:
    fn_concat(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 7.4.2 fn:string-join
   *-----------------------*/
  class fn_string_join: public function
  {
  public:
    fn_string_join(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 7.4.3 fn:substring
   *-----------------------*/
  
  typedef function_impl<SubstringIterator> fn_substring;

  /*
   * 7.4.4 fn:string-length
   * --------------------*/
  class fn_string_length: public function
  {
  public:
    fn_string_length(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 7.4.5 fn:normalize-space
   *-----------------------*/
  class fn_normalize_space: public function
  {
  public:
    fn_normalize_space(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 7.4.6 fn:normalize-unicode
   *-----------------------*/
  typedef function_impl<NormalizeUnicodeIterator> fn_normalize_unicode;

  /*
   * 7.4.7 fn:upper-case
   *-----------------------*/
  class fn_upper_case: public function
  {
  public:
    fn_upper_case(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 7.4.8 fn:lower-case
   *-----------------------*/
  class fn_lower_case: public function
  {
  public:
    fn_lower_case(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 7.4.9 fn:translate
   *-----------------------*/

  typedef function_impl<TranslateIterator> fn_translate;

  /*
   * 7.4.10 fn:encode-for-uri
   *-----------------------*/
  class fn_encode_for_uri: public function
  {
  public:
    fn_encode_for_uri(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 7.4.11 fn:iri-to-uri
   *-----------------------*/
  class fn_iri_to_uri : public function
  {
  public:
    fn_iri_to_uri(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*
   * 7.4.12 fn:escape-html-uri
   *-----------------------*/
  class fn_escape_html_uri: public function
  {
  public:
    fn_escape_html_uri(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


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
