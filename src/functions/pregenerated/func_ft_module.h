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


#ifndef ZORBA_FUNCTIONS_FT_MODULE_H
#define ZORBA_FUNCTIONS_FT_MODULE_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_ft_module(static_context* sctx);




//zorba-full-text:host-lang
class zorba_full_text_host_lang : public function
{
public:
  zorba_full_text_host_lang(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-full-text:is-stop-word
class zorba_full_text_is_stop_word : public function
{
public:
  zorba_full_text_is_stop_word(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-full-text:stem
class zorba_full_text_stem : public function
{
public:
  zorba_full_text_stem(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-full-text:strip-diacritics
class zorba_full_text_strip_diacritics : public function
{
public:
  zorba_full_text_strip_diacritics(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-full-text:thesaurus-lookup
class zorba_full_text_thesaurus_lookup : public function
{
public:
  zorba_full_text_thesaurus_lookup(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {

}

  CODEGEN_DECL();
};


//zorba-full-text:tokenize
class zorba_full_text_tokenize : public function
{
public:
  zorba_full_text_tokenize(const signature& sig, FunctionConsts::FunctionKind kind)
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
