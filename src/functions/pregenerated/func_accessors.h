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


#ifndef ZORBA_FUNCTIONS_ACCESSORS_H
#define ZORBA_FUNCTIONS_ACCESSORS_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_accessors(static_context* sctx);




//fn:node-name
class fn_node_name : public function
{
public:
  fn_node_name(const signature& sig)
    :
    function(sig, FunctionConsts::FN_NODE_NAME_1)
  {
  }

  CODEGEN_DECL();
};


//fn:nilled
class fn_nilled : public function
{
public:
  fn_nilled(const signature& sig)
    :
    function(sig, FunctionConsts::FN_NILLED_1)
  {
  }

  CODEGEN_DECL();
};


//fn:string
class fn_string : public function
{
public:
  fn_string(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 0 ?
                FunctionConsts::FN_STRING_0 :
                FunctionConsts::FN_STRING_1);
  
  }

  CODEGEN_DECL();
};


//fn:data
class fn_data : public function
{
public:
  fn_data(const signature& sig)
    :
    function(sig, FunctionConsts::FN_DATA_1)
  {
  }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;

  bool isMap(ulong producer) const { return producer == 0; }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, ulong producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, ulong producer) const;

  CODEGEN_DECL();
};


//fn:base-uri
class fn_base_uri : public function
{
public:
  fn_base_uri(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 0 ?
                FunctionConsts::FN_BASE_URI_0 :
                FunctionConsts::FN_BASE_URI_1);
  
  }

  CODEGEN_DECL();
};


//fn:document-uri
class fn_document_uri : public function
{
public:
  fn_document_uri(const signature& sig)
    :
    function(sig, FunctionConsts::FN_DOCUMENT_URI_1)
  {
  }

  CODEGEN_DECL();
};


//fn:root
class fn_root : public function
{
public:
  fn_root(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 0 ?
                FunctionConsts::FN_ROOT_0 :
                FunctionConsts::FN_ROOT_1);
  
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
