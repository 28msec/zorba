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
#pragma once
#ifndef ZORBA_COMPILER_API_COMPILERCB
#define ZORBA_COMPILER_API_COMPILERCB

#include <vector>
#include <map>

#include <zorba/config.h>

#include "common/shared_types.h"

#ifdef MSVC
// The visual studio compiler is not able to compile the type rchandle<static_context>
// without having the definition of static_context availble.
# include "context/static_context.h"
#endif

#include "zorbaserialization/class_serializer.h"

namespace zorba {

#ifdef ZORBA_WITH_DEBUGGER
class DebuggerCommons;
#endif
class static_context;


/*******************************************************************************
  There is one CompilerCB per query plus one CompilerCB per invocation of an
  eval or xqdoc expression that appears in the query. The query-level ccb is
  created by the constructor of the XQueryImpl obj and remains alive for the
  whole duration of the query (including runtime). Each eval/xqdoc-level ccb is
  created as a copy of the query-level ccb during the execution of the eval/xqdoc
  expr.

  - theXQueryDiagnostics :
  Pointer to the query's XQueryDiagnostics obj. (see src/api/xqueryimpl.h). The eval
  CompilerCBs share the query's XQueryDiagnostics.

  - theSctxMap :
  A query-level (or eval-level) map that stores the sctx objs that need to be
  kept around for the whole duration of a query (including runtime). In non-
  DEBUGGER mode, the map stores only for root sctx of each module. In DEBUGGER
  mode, it stores all the sctxs created by each module. Each sctx stored in 
  this map has an associated numeric id, and theSctxMap actually maps these
  numeric ids to their associated sctx objs. The map is modified by the methods
  TranslatorImpl::end_visit(ModuleImport) and TranslatorImpl::push_scope().

  - theRootSctx :
  The root static ctx for the query or for one of the query's eval exprs. For
  an eval expr, its root sctx is a child of the query's root sctx. For the query,
  its root sctx may be (a) a child of a user-provided sctx, or (b) if the query
  is a load-prolog query, the user-provided sctx, or (c) if the user did not
  provide any sctx, a child of zorba's root sctx.

  - theDebuggerCommons :

  - theIsEval :
  True if this is the CCB for an eval query. This flag is needed to determine
  if a PUL returned by the main program must be applied or not.

  - theIsLoadProlog :
  Whether this is a load-prolog query or not (load-prolog queries are created
  internally by the StaticContextImpl::loadProlog() method).

  - theIsUpdating :
  Set to true if the root expr of the query or eval expr is an updating expr. 

  - theTimeout :

  - theTempIndexCounter :
  A counter used to create unique names for temporary (query-specific) indexes
  created to perform hashjoins (see rewriter/rules/index_join_rule.cpp).

  - theConfig.lib_module :
  If true, then if the query string that is given by the user is a library
  module, zorba will wrap it in a dummy main module and compile/execute that
  dummy module (see  XQueryCompiler::createMainModule() method). This flag is
  a copy of the lib_module flag in Zorba_CompilerHints_t.

  - theConfig.for_serialization_only :
  This flag is a copy of the for_serialization_only flag in Zorba_CompilerHints_t.

  - theConfig.parse_cb :
  Pointer to the function to call to print the AST that results from parsing
  the query.

  - theConfig.translate_cb :
  Pointer to the function to call to print the expr tree that results from
  translating the query AST.
********************************************************************************/
class ZORBA_DLL_PUBLIC CompilerCB : public zorba::serialization::SerializeBaseClass
{
public:
  struct config : public zorba::serialization::SerializeBaseClass
  {
    typedef enum 
    {
      O0,
      O1,
      O2
    } opt_level_t;
    
    typedef void (* expr_callback) (const expr *, const std::string& name);

    typedef void (* ast_callback) (const parsenode *, const std::string& name);

    bool           force_gflwor;
    opt_level_t    opt_level;
    bool           lib_module;
    bool           for_serialization_only;
    ast_callback   parse_cb;
    expr_callback  translate_cb;
    expr_callback  optimize_cb;
    bool           print_item_flow;  // TODO: move to RuntimeCB

   public:
    SERIALIZABLE_CLASS(config)
    config(::zorba::serialization::Archiver& ar);

    config();

    ~config() {}

    void serialize(::zorba::serialization::Archiver& ar);
  };

  typedef std::map<short, static_context_t> SctxMap;

public:  
  XQueryDiagnostics       * theXQueryDiagnostics;

  SctxMap                   theSctxMap;

  static_context          * theRootSctx;

#ifdef ZORBA_WITH_DEBUGGER
  DebuggerCommons*          theDebuggerCommons;
#endif

  bool                      theIsEval;

  bool                      theIsLoadProlog;

  bool                      theIsUpdating;

  bool                      theIsSequential;

  long                      theTimeout;

  ulong                     theTempIndexCounter;

  config                    theConfig;

public:
  SERIALIZABLE_CLASS(CompilerCB);
  CompilerCB(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  CompilerCB(XQueryDiagnostics*, long timeout = -1);

  CompilerCB(const CompilerCB& ccb);

  ~CompilerCB();

  bool isLoadPrologQuery() const { return theIsLoadProlog; }

  void setLoadPrologQuery() { theIsLoadProlog = true; }

  void setIsUpdating(bool aIsUpdating) { theIsUpdating = aIsUpdating; }

  bool isUpdating() const { return theIsUpdating; }

  void setIsSequential(bool aIsSequential) {theIsSequential = aIsSequential;}

  bool isSequential() const { return theIsSequential;}

  static_context* getStaticContext(short id);
};


}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
