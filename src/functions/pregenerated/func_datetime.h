/*
 * Copyright 2006-2012 The FLWOR Foundation.
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



#ifndef ZORBA_FUNCTIONS_DATETIME_H
#define ZORBA_FUNCTIONS_DATETIME_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_datetime(static_context* sctx);




//fn-zorba-dateTime:current-date
class fn_zorba_dateTime_current_date : public function
{
public:
  fn_zorba_dateTime_current_date(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
setDeterministic(false);

  }

  CODEGEN_DECL();
};


//fn-zorba-dateTime:current-dateTime
class fn_zorba_dateTime_current_dateTime : public function
{
public:
  fn_zorba_dateTime_current_dateTime(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
setDeterministic(false);

  }

  CODEGEN_DECL();
};


//fn-zorba-dateTime:current-time
class fn_zorba_dateTime_current_time : public function
{
public:
  fn_zorba_dateTime_current_time(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
setDeterministic(false);

  }

  CODEGEN_DECL();
};


//fn-zorba-dateTime:millis-to-dateTime
class fn_zorba_dateTime_millis_to_dateTime : public function
{
public:
  fn_zorba_dateTime_millis_to_dateTime(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn-zorba-dateTime:parse-date
class fn_zorba_dateTime_parse_date : public function
{
public:
  fn_zorba_dateTime_parse_date(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn-zorba-dateTime:parse-dateTime
class fn_zorba_dateTime_parse_dateTime : public function
{
public:
  fn_zorba_dateTime_parse_dateTime(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn-zorba-dateTime:parse-time
class fn_zorba_dateTime_parse_time : public function
{
public:
  fn_zorba_dateTime_parse_time(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn-zorba-dateTime:timestamp
class fn_zorba_dateTime_timestamp : public function
{
public:
  fn_zorba_dateTime_timestamp(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
setDeterministic(false);

  }

  CODEGEN_DECL();
};


//fn-zorba-dateTime:utc-offset
class fn_zorba_dateTime_utc_offset : public function
{
public:
  fn_zorba_dateTime_utc_offset(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
setDeterministic(false);

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
