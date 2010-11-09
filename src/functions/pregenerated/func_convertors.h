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


namespace zorba {


void populate_context_convertors(static_context* sctx);




//fn-zorba-json:parse
class fn_zorba_json_parse : public function
{
public:
  fn_zorba_json_parse(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_JSON_PARSE_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-json:serialize
class fn_zorba_json_serialize : public function
{
public:
  fn_zorba_json_serialize(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_JSON_SERIALIZE_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-json:parse-ml
class fn_zorba_json_parse_ml : public function
{
public:
  fn_zorba_json_parse_ml(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_JSON_PARSE_ML_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-json:serialize-ml
class fn_zorba_json_serialize_ml : public function
{
public:
  fn_zorba_json_serialize_ml(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_JSON_SERIALIZE_ML_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-csv:csv-to-xml
class fn_zorba_csv_csv_to_xml : public function
{
public:
  fn_zorba_csv_csv_to_xml(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_CSV_CSV_TO_XML_7)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-csv:txt-to-xml
class fn_zorba_csv_txt_to_xml : public function
{
public:
  fn_zorba_csv_txt_to_xml(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_CSV_TXT_TO_XML_5)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-csv:csv-file-to-xml
class fn_zorba_csv_csv_file_to_xml : public function
{
public:
  fn_zorba_csv_csv_file_to_xml(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_CSV_CSV_FILE_TO_XML_7)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-csv:txt-file-to-xml
class fn_zorba_csv_txt_file_to_xml : public function
{
public:
  fn_zorba_csv_txt_file_to_xml(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_CSV_TXT_FILE_TO_XML_5)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-csv:xml-to-csv
class fn_zorba_csv_xml_to_csv : public function
{
public:
  fn_zorba_csv_xml_to_csv(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_CSV_XML_TO_CSV_6)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-csv:xml-to-csv-file
class fn_zorba_csv_xml_to_csv_file : public function
{
public:
  fn_zorba_csv_xml_to_csv_file(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_CSV_XML_TO_CSV_FILE_7)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-csv:xml-to-txt
class fn_zorba_csv_xml_to_txt : public function
{
public:
  fn_zorba_csv_xml_to_txt(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_CSV_XML_TO_TXT_4)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-csv:xml-to-txt-file
class fn_zorba_csv_xml_to_txt_file : public function
{
public:
  fn_zorba_csv_xml_to_txt_file(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_CSV_XML_TO_TXT_FILE_5)
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
