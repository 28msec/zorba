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
#include "functions/Misc.h"
#include "functions/function_impl.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/debug/debug_iterators.h"
#include "runtime/misc/MiscImpl.h"

using namespace std;

namespace zorba {


/*******************************************************************************
  3 The Error Function
********************************************************************************/
class fn_error : public function 
{
public:
  fn_error(const signature& sig) : function (sig) {}

  bool isFnError() const { return true; }

  virtual expr_update_t getUpdateType() const { return VACUOUS_EXPR; }

  DEFAULT_NARY_CODEGEN(FnErrorIterator);
};


/*******************************************************************************
  8.1 fn:resolve-uri
********************************************************************************/
class fn_resolve_uri : public function 
{
public:
  fn_resolve_uri(const signature& sig) : function (sig) {}

  DEFAULT_NARY_CODEGEN(FnResolveUriIterator);
};


/*******************************************************************************

********************************************************************************/
class fn_trace_func : public function 
{
public:
  fn_trace_func(const signature& sig) : function (sig) {}    

  CODEGEN_DECL();
};


PlanIter_t fn_trace_func::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder &ann) const
{
  // tracing can be disabled  using declare option exq:trace "disable";
  xqp_string lOption;
  bool lOptionFound = sctx->lookup_option("http://www.zorba-xquery.org/options",
                                          "trace",
                                          lOption);

  if (!lOptionFound || (lOptionFound && lOption != "disable")) 
  {
    return new FnTraceIterator ( sctx, loc, argv );
  }
  else
  {
    return argv[0];
  }
}


/*******************************************************************************

********************************************************************************/
class fn_read_string : public function 
{
public:
  fn_read_string(const signature& sig) : function (sig) {}

  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(FnReadStringIterator);
};


/*******************************************************************************

********************************************************************************/
class fn_print : public function 
{
public:
  fn_print(const signature& sig) : function (sig) {}

  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(FnPrintIterator);
};



/*******************************************************************************

********************************************************************************/
void populateContext_Error(static_context* sctx)
{
  DECL(sctx, fn_error,
       (createQName(XQUERY_FN_NS, "fn", "error"),
        GENV_TYPESYSTEM.NONE_TYPE));

  DECL(sctx, fn_error,
       (createQName(XQUERY_FN_NS, "fn", "error"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.NONE_TYPE));

  DECL(sctx, fn_error,
       (createQName(XQUERY_FN_NS, "fn", "error"),
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.NONE_TYPE));

  DECL(sctx, fn_error,
       (createQName(XQUERY_FN_NS, "fn", "error"),
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR ,
        GENV_TYPESYSTEM.NONE_TYPE));
}


void populateContext_AnyURI(static_context* sctx)
{
  DECL(sctx, fn_resolve_uri,
       (createQName(XQUERY_FN_NS, "fn", "resolve-uri"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));
}


void populateContext_Debug(static_context* sctx)
{
  DECL(sctx, fn_trace_func,
       (createQName(XQUERY_FN_NS,"fn","trace"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_read_string,
       (createQName (ZORBA_FN_NS, "fn-zorba", "read-line"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE));
  
  DECL(sctx, fn_print,
       (createQName (ZORBA_FN_NS, "fn-zorba", "print"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.EMPTY_TYPE));
}

}
/* vim:set ts=2 sw=2: */
