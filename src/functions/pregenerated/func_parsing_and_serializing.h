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


#ifndef ZORBA_FUNCTIONS_PARSING_AND_SERIALIZING_H
#define ZORBA_FUNCTIONS_PARSING_AND_SERIALIZING_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_parsing_and_serializing(static_context* sctx);




//fn:parse-xml
class fn_parse_xml_3_0 : public function
{
public:
  fn_parse_xml_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
}

  bool accessesDynCtx() const { return true; }

  bool isSource() const { return true; }

  CODEGEN_DECL();
};


//fn:serialize
class fn_serialize_3_0 : public function
{
public:
  fn_serialize_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
}

  bool accessesDynCtx() const { return true; }

  bool isSource() const { return true; }

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
