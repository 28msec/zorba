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
#ifndef ZORBA_FUNCTIONS_FT_MODULE_IMPL_H
#define ZORBA_FUNCTIONS_FT_MODULE_IMPL_H

#include "stdafx.h"

#include "functions/function.h"
#include "functions/function_impl.h"


namespace zorba 
{

#ifndef ZORBA_NO_FULL_TEXT

//full-text:tokenize
class full_text_tokenize : public function
{
public:
  SERIALIZABLE_CLASS(full_text_tokenize);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(full_text_tokenize, function)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  full_text_tokenize(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};



//full-text:tokenizer-properties
class full_text_tokenizer_properties : public function
{
public:
  SERIALIZABLE_CLASS(full_text_tokenizer_properties);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(full_text_tokenizer_properties, function)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  full_text_tokenizer_properties(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  // Mark the function as accessing the dyn ctx so that it won't be
  // const-folded. We must prevent const-folding because the function
  // returns a node that is validated with a schema that may not be
  // imported in the module where the function is invoked from.
  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};

#endif // ZORBA_NO_FULL_TEXT

}

#endif
/* vim:set et sw=2 ts=2: */
