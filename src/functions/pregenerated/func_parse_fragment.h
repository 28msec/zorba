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


#ifndef ZORBA_FUNCTIONS_PARSE_FRAGMENT_H
#define ZORBA_FUNCTIONS_PARSE_FRAGMENT_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_parse_fragment(static_context* sctx);




//fn-zorba-xml:parse
class fn_zorba_xml_parse : public function
{
public:
  fn_zorba_xml_parse(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


//fn:parse-xml-fragment
class fn_parse_xml_fragment_3_0 : public function
{
public:
  fn_parse_xml_fragment_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
