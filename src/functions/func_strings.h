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


#ifndef ZORBA_FUNCTIONS_STRINGS_H
#define ZORBA_FUNCTIONS_STRINGS_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_strings(static_context* sctx);




//fn:codepoints-to-string
class fn_codepoints_to_string : public function
{
public:
  fn_codepoints_to_string(const signature& sig)
    :
    function(sig, FunctionConsts::FN_CODEPOINTS_TO_STRING_1)
  {
  }

  CODEGEN_DECL();
};


//fn:string-to-codepoints
class fn_string_to_codepoints : public function
{
public:
  fn_string_to_codepoints(const signature& sig)
    :
    function(sig, FunctionConsts::FN_STRING_TO_CODEPOINTS_1)
  {
  }

  CODEGEN_DECL();
};


//fn:compare
class fn_compare : public function
{
public:
  fn_compare(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.arg_count() == 2 ?
                FunctionConsts::FN_COMPARE_2 :
                FunctionConsts::FN_COMPARE_3);
  }

  CODEGEN_DECL();
};


//fn:codepoint-equal
class fn_codepoint_equal : public function
{
public:
  fn_codepoint_equal(const signature& sig)
    :
    function(sig, FunctionConsts::FN_CODEPOINT_EQUAL_2)
  {
  }

  CODEGEN_DECL();
};


//fn:concat
class fn_concat : public function
{
public:
  fn_concat(const signature& sig)
    :
    function(sig, FunctionConsts::FN_CONCAT_N)
  {
  }

  CODEGEN_DECL();
};


//fn:string-join
class fn_string_join : public function
{
public:
  fn_string_join(const signature& sig)
    :
    function(sig, FunctionConsts::FN_STRING_JOIN_2)
  {
  }

  CODEGEN_DECL();
};


//fn:substring
class fn_substring : public function
{
public:
  fn_substring(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.arg_count() == 2 ?
                FunctionConsts::FN_SUBSTRING_2 :
                FunctionConsts::FN_SUBSTRING_3);
  }

  CODEGEN_DECL();
};


//fn:string-length
class fn_string_length : public function
{
public:
  fn_string_length(const signature& sig)
    :
    function(sig, FunctionConsts::FN_STRING_LENGTH_1)
  {
  }

  CODEGEN_DECL();
};


//fn:normalize-space
class fn_normalize_space : public function
{
public:
  fn_normalize_space(const signature& sig)
    :
    function(sig, FunctionConsts::FN_NORMALIZE_SPACE_1)
  {
  }

  CODEGEN_DECL();
};


//fn:normalize-unicode
class fn_normalize_unicode : public function
{
public:
  fn_normalize_unicode(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.arg_count() == 1 ?
                FunctionConsts::FN_NORMALIZE_UNICODE_1 :
                FunctionConsts::FN_NORMALIZE_UNICODE_2);
  }

  CODEGEN_DECL();
};


//fn:upper-case
class fn_upper_case : public function
{
public:
  fn_upper_case(const signature& sig)
    :
    function(sig, FunctionConsts::FN_UPPER_CASE_1)
  {
  }

  CODEGEN_DECL();
};


//fn:lower-case
class fn_lower_case : public function
{
public:
  fn_lower_case(const signature& sig)
    :
    function(sig, FunctionConsts::FN_LOWER_CASE_1)
  {
  }

  CODEGEN_DECL();
};


//fn:translate
class fn_translate : public function
{
public:
  fn_translate(const signature& sig)
    :
    function(sig, FunctionConsts::FN_TRANSLATE_3)
  {
  }

  CODEGEN_DECL();
};


//fn:encode-for-uri
class fn_encode_for_uri : public function
{
public:
  fn_encode_for_uri(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ENCODE_FOR_URI_1)
  {
  }

  CODEGEN_DECL();
};


//fn:iri-to-uri
class fn_iri_to_uri : public function
{
public:
  fn_iri_to_uri(const signature& sig)
    :
    function(sig, FunctionConsts::FN_IRI_TO_URI_1)
  {
  }

  CODEGEN_DECL();
};


//fn:escape-html-uri
class fn_escape_html_uri : public function
{
public:
  fn_escape_html_uri(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ESCAPE_HTML_URI_1)
  {
  }

  CODEGEN_DECL();
};


//fn:contains
class fn_contains : public function
{
public:
  fn_contains(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.arg_count() == 2 ?
                FunctionConsts::FN_CONTAINS_2 :
                FunctionConsts::FN_CONTAINS_3);
  }

  CODEGEN_DECL();
};


//fn:starts-with
class fn_starts_with : public function
{
public:
  fn_starts_with(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.arg_count() == 2 ?
                FunctionConsts::FN_STARTS_WITH_2 :
                FunctionConsts::FN_STARTS_WITH_3);
  }

  CODEGEN_DECL();
};


//fn:ends-with
class fn_ends_with : public function
{
public:
  fn_ends_with(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.arg_count() == 2 ?
                FunctionConsts::FN_ENDS_WITH_2 :
                FunctionConsts::FN_ENDS_WITH_3);
  }

  CODEGEN_DECL();
};


//fn:substring-before
class fn_substring_before : public function
{
public:
  fn_substring_before(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.arg_count() == 2 ?
                FunctionConsts::FN_SUBSTRING_BEFORE_2 :
                FunctionConsts::FN_SUBSTRING_BEFORE_3);
  }

  CODEGEN_DECL();
};


//fn:substring-after
class fn_substring_after : public function
{
public:
  fn_substring_after(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.arg_count() == 2 ?
                FunctionConsts::FN_SUBSTRING_AFTER_2 :
                FunctionConsts::FN_SUBSTRING_AFTER_3);
  }

  CODEGEN_DECL();
};


//fn:matches
class fn_matches : public function
{
public:
  fn_matches(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.arg_count() == 2 ?
                FunctionConsts::FN_MATCHES_2 :
                FunctionConsts::FN_MATCHES_3);
  }

  CODEGEN_DECL();
};


//fn:replace
class fn_replace : public function
{
public:
  fn_replace(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.arg_count() == 3 ?
                FunctionConsts::FN_REPLACE_3 :
                FunctionConsts::FN_REPLACE_4);
  }

  CODEGEN_DECL();
};


//fn:tokenize
class fn_tokenize : public function
{
public:
  fn_tokenize(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.arg_count() == 2 ?
                FunctionConsts::FN_TOKENIZE_2 :
                FunctionConsts::FN_TOKENIZE_3);
  }

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
