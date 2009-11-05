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


namespace zorba{


void populate_context_strings(static_context* sctx);



//fn:codepoints-to-string
class fn_codepoints_to_string : public function
{
public:
  fn_codepoints_to_string(const signature& sig) : function(sig, FunctionConsts::FN_CODEPOINTS_TO_STRING) {}

  CODEGEN_DECL();
};

//fn:compare
class fn_compare : public function
{
public:
  fn_compare(const signature& sig) : function(sig, FunctionConsts::FN_COMPARE) {}

  CODEGEN_DECL();
};

//fn:codepoint-equal
class fn_codepoint_equal : public function
{
public:
  fn_codepoint_equal(const signature& sig) : function(sig, FunctionConsts::FN_CODEPOINT_EQUAL) {}

  CODEGEN_DECL();
};

//fn:concat
class fn_concat : public function
{
public:
  fn_concat(const signature& sig) : function(sig, FunctionConsts::FN_CONCAT) {}

  CODEGEN_DECL();
};

//fn:string-join
class fn_string_join : public function
{
public:
  fn_string_join(const signature& sig) : function(sig, FunctionConsts::FN_STRING_JOIN) {}

  CODEGEN_DECL();
};

//fn:substring
class fn_substring : public function
{
public:
  fn_substring(const signature& sig) : function(sig, FunctionConsts::FN_SUBSTRING) {}

  CODEGEN_DECL();
};

//fn:string-length
class fn_string_length : public function
{
public:
  fn_string_length(const signature& sig) : function(sig, FunctionConsts::FN_STRING_LENGTH) {}

  CODEGEN_DECL();
};

//fn:normalize-space
class fn_normalize_space : public function
{
public:
  fn_normalize_space(const signature& sig) : function(sig, FunctionConsts::FN_NORMALIZE_SPACE) {}

  CODEGEN_DECL();
};

//fn:normalize-unicode
class fn_normalize_unicode : public function
{
public:
  fn_normalize_unicode(const signature& sig) : function(sig, FunctionConsts::FN_NORMALIZE_UNICODE) {}

  CODEGEN_DECL();
};

//fn:upper-case
class fn_upper_case : public function
{
public:
  fn_upper_case(const signature& sig) : function(sig, FunctionConsts::FN_UPPER_CASE) {}

  CODEGEN_DECL();
};

//fn:lower-case
class fn_lower_case : public function
{
public:
  fn_lower_case(const signature& sig) : function(sig, FunctionConsts::FN_LOWER_CASE) {}

  CODEGEN_DECL();
};

//fn:translate
class fn_translate : public function
{
public:
  fn_translate(const signature& sig) : function(sig, FunctionConsts::FN_TRANSLATE) {}

  CODEGEN_DECL();
};

//fn:encode-for-uri
class fn_encode_for_uri : public function
{
public:
  fn_encode_for_uri(const signature& sig) : function(sig, FunctionConsts::FN_ENCODE_FOR_URI) {}

  CODEGEN_DECL();
};

//fn:iri-to-uri
class fn_iri_to_uri : public function
{
public:
  fn_iri_to_uri(const signature& sig) : function(sig, FunctionConsts::FN_IRI_TO_URI) {}

  CODEGEN_DECL();
};

//fn:escape-html-uri
class fn_escape_html_uri : public function
{
public:
  fn_escape_html_uri(const signature& sig) : function(sig, FunctionConsts::FN_ESCAPE_HTML_URI) {}

  CODEGEN_DECL();
};

//fn:contains
class fn_contains : public function
{
public:
  fn_contains(const signature& sig) : function(sig, FunctionConsts::FN_CONTAINS) {}

  CODEGEN_DECL();
};

//fn:starts-with
class fn_starts_with : public function
{
public:
  fn_starts_with(const signature& sig) : function(sig, FunctionConsts::FN_STARTS_WITH) {}

  CODEGEN_DECL();
};

//fn:ends-with
class fn_ends_with : public function
{
public:
  fn_ends_with(const signature& sig) : function(sig, FunctionConsts::FN_ENDS_WITH) {}

  CODEGEN_DECL();
};

//fn:substring-before
class fn_substring_before : public function
{
public:
  fn_substring_before(const signature& sig) : function(sig, FunctionConsts::FN_SUBSTRING_BEFORE) {}

  CODEGEN_DECL();
};

//fn:substring-after
class fn_substring_after : public function
{
public:
  fn_substring_after(const signature& sig) : function(sig, FunctionConsts::FN_SUBSTRING_AFTER) {}

  CODEGEN_DECL();
};

//fn:matches
class fn_matches : public function
{
public:
  fn_matches(const signature& sig) : function(sig, FunctionConsts::FN_MATCHES) {}

  CODEGEN_DECL();
};

//fn:replace
class fn_replace : public function
{
public:
  fn_replace(const signature& sig) : function(sig, FunctionConsts::FN_REPLACE) {}

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
