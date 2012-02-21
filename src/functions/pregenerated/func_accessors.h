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
class fn_node_name_3_0 : public function
{
public:
  fn_node_name_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};

//fn:node-name
class fn_node_name : public function
{
public:
  fn_node_name(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:nilled
class fn_nilled : public function
{
public:
  fn_nilled(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:string
class fn_string : public function
{
public:
  fn_string(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:data
class fn_data : public function
{
public:
  fn_data(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  bool isMap(ulong producer) const { return producer == 0; }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  bool mustCopyInputNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};


//fn:base-uri
class fn_base_uri : public function
{
public:
  fn_base_uri(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return true; }

  CODEGEN_DECL();
};


//fn:document-uri
class fn_document_uri_3_0 : public function
{
public:
  fn_document_uri_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};

//fn:document-uri
class fn_document_uri : public function
{
public:
  fn_document_uri(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


//fn:root
class fn_root : public function
{
public:
  fn_root(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return true; }

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
