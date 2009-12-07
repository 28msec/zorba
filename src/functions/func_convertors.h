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


#ifndef ZORBA_FUNCTIONS_CONVERTORS_H
#define ZORBA_FUNCTIONS_CONVERTORS_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba{


void populate_context_convertors(static_context* sctx);




//zorba-json:parse
class zorba_json_parse : public function
{
public:
  zorba_json_parse(const signature& sig)
    :
    function(sig, FunctionConsts::ZORBA_JSON_PARSE_1)
  {
  }

  CODEGEN_DECL();
};


//zorba-json:serialize
class zorba_json_serialize : public function
{
public:
  zorba_json_serialize(const signature& sig)
    :
    function(sig, FunctionConsts::ZORBA_JSON_SERIALIZE_1)
  {
  }

  CODEGEN_DECL();
};


//zorba-json-ml:parse
class zorba_json_ml_parse : public function
{
public:
  zorba_json_ml_parse(const signature& sig)
    :
    function(sig, FunctionConsts::ZORBA_JSON_ML_PARSE_1)
  {
  }

  CODEGEN_DECL();
};


//zorba-json-ml:serialize
class zorba_json_ml_serialize : public function
{
public:
  zorba_json_ml_serialize(const signature& sig)
    :
    function(sig, FunctionConsts::ZORBA_JSON_ML_SERIALIZE_1)
  {
  }

  CODEGEN_DECL();
};


//zorba-csv:csv2xml
class zorba_csv_csv2xml : public function
{
public:
  zorba_csv_csv2xml(const signature& sig)
    :
    function(sig, FunctionConsts::ZORBA_CSV_CSV2XML_7)
  {
  }

  CODEGEN_DECL();
};


//zorba-csv:txt2xml
class zorba_csv_txt2xml : public function
{
public:
  zorba_csv_txt2xml(const signature& sig)
    :
    function(sig, FunctionConsts::ZORBA_CSV_TXT2XML_5)
  {
  }

  CODEGEN_DECL();
};


//zorba-csv:csv2xmlFromFile
class zorba_csv_csv2xmlFromFile : public function
{
public:
  zorba_csv_csv2xmlFromFile(const signature& sig)
    :
    function(sig, FunctionConsts::ZORBA_CSV_CSV2XMLFROMFILE_7)
  {
  }

  CODEGEN_DECL();
};


//zorba-csv:txt2xmlFromFile
class zorba_csv_txt2xmlFromFile : public function
{
public:
  zorba_csv_txt2xmlFromFile(const signature& sig)
    :
    function(sig, FunctionConsts::ZORBA_CSV_TXT2XMLFROMFILE_5)
  {
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
