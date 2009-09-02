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
#include "system/globalenv.h"

#include "functions/ContextFunctions.h"
#include "functions/function_impl.h"

#include "runtime/context/ContextImpl.h"


namespace zorba
{

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
// 16 Context Functions                                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


// 16.3 fn:current-dateTime
class fn_current_dateTime : public function
{
public:
  fn_current_dateTime(const signature& sig) : function (sig) {}
     
  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(FnCurrentDateTimeIterator);
};


// 16.4 fn:current-date
class fn_current_date : public function
{
public:
  fn_current_date(const signature& sig) : function (sig) {}
  
  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(FnCurrentDateIterator);
};


// 16.5 fn:current-time
class fn_current_time : public function
{
public:
  fn_current_time(const signature& sig) : function (sig) {}
  
  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(FnCurrentTimeIterator);
};


// 16.6 fn:implicit-timezone
class fn_implicit_timezone : public function
{
public:
  fn_implicit_timezone(const signature& sig) : function (sig) {}
     
  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(FnImplicitTimezoneIterator);
};


// 16.7 fn:default-collation
class fn_default_collation : public function
{
public:
  fn_default_collation(const signature& sig) : function (sig) {}
  
  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(FnDefaultCollationIterator);
};


void populateContext_Context(static_context* sctx)
{
DECL(sctx, fn_current_dateTime,
     (createQName(XQUERY_FN_NS,"fn","current-dateTime"),
      GENV_TYPESYSTEM.DATETIME_TYPE_ONE));

DECL(sctx, fn_current_date,
     (createQName(XQUERY_FN_NS,"fn","current-date"),
      GENV_TYPESYSTEM.DATE_TYPE_ONE));

DECL(sctx, fn_current_time,
     (createQName(XQUERY_FN_NS,"fn","current-time"),
      GENV_TYPESYSTEM.TIME_TYPE_ONE));

DECL(sctx, fn_implicit_timezone,
     (createQName(XQUERY_FN_NS,"fn","implicit-timezone"),
      GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE));

DECL(sctx, fn_default_collation,
     (createQName(XQUERY_FN_NS,"fn","default-collation"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));
}


} /* namespace zorba */
