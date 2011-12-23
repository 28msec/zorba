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
  fn_codepoints_to_string(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:string-to-codepoints
class fn_string_to_codepoints : public function
{
public:
  fn_string_to_codepoints(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:compare
class fn_compare : public function
{
public:
  fn_compare(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:codepoint-equal
class fn_codepoint_equal : public function
{
public:
  fn_codepoint_equal(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:concat
class fn_concat : public function
{
public:
  fn_concat(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};


//fn:string-join
class fn_string_join_3_0 : public function
{
public:
  fn_string_join_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  CODEGEN_DECL();
};

//fn:string-join
class fn_string_join : public function
{
public:
  fn_string_join(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:substring
class fn_substring : public function
{
public:
  fn_substring(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool specializable() const { return true; }

  function* specialize( static_context* sctx,
                        const std::vector<xqtref_t>& argTypes) const;

  CODEGEN_DECL();
};


//op:substring_int
class op_substring_int : public function
{
public:
  op_substring_int(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:string-length
class fn_string_length : public function
{
public:
  fn_string_length(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:normalize-space
class fn_normalize_space : public function
{
public:
  fn_normalize_space(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:normalize-unicode
class fn_normalize_unicode : public function
{
public:
  fn_normalize_unicode(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:upper-case
class fn_upper_case : public function
{
public:
  fn_upper_case(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:lower-case
class fn_lower_case : public function
{
public:
  fn_lower_case(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:translate
class fn_translate : public function
{
public:
  fn_translate(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:encode-for-uri
class fn_encode_for_uri : public function
{
public:
  fn_encode_for_uri(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:iri-to-uri
class fn_iri_to_uri : public function
{
public:
  fn_iri_to_uri(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:escape-html-uri
class fn_escape_html_uri : public function
{
public:
  fn_escape_html_uri(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:contains
class fn_contains : public function
{
public:
  fn_contains(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:starts-with
class fn_starts_with : public function
{
public:
  fn_starts_with(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:ends-with
class fn_ends_with : public function
{
public:
  fn_ends_with(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:substring-before
class fn_substring_before : public function
{
public:
  fn_substring_before(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:substring-after
class fn_substring_after : public function
{
public:
  fn_substring_after(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:matches
class fn_matches : public function
{
public:
  fn_matches(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:replace
class fn_replace : public function
{
public:
  fn_replace(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:tokenize
class fn_tokenize : public function
{
public:
  fn_tokenize(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn:analyze-string
class fn_analyze_string_3_0 : public function
{
public:
  fn_analyze_string_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  CODEGEN_DECL();
};


//fn-zorba-string:materialize
class fn_zorba_string_materialize : public function
{
public:
  fn_zorba_string_materialize(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn-zorba-string:is-streamable
class fn_zorba_string_is_streamable : public function
{
public:
  fn_zorba_string_is_streamable(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn-zorba-string:split
class fn_zorba_string_split : public function
{
public:
  fn_zorba_string_split(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

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
