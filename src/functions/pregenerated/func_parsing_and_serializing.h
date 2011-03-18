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
class fn_parse_xml : public function
{
public:
  fn_parse_xml(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
                FunctionConsts::FN_PARSE_XML_1 :
                FunctionConsts::FN_PARSE_XML_2);
  }

  bool accessesDynCtx() const { return true; }

  bool isSource() const { return true; }

  CODEGEN_DECL();
};


//fn:serialize
class fn_serialize : public function
{
public:
  fn_serialize(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 1 ?
                FunctionConsts::FN_SERIALIZE_1 :
                FunctionConsts::FN_SERIALIZE_2);
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
