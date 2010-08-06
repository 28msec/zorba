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
#ifndef ZORBA_COMPILER_API_COMPILERCB
#define ZORBA_COMPILER_API_COMPILERCB

#include <vector>
#include <map>

#include <zorba/config.h>

#include "common/shared_types.h"

#include "zorbaserialization/class_serializer.h"

namespace zorba {

class ZorbaDebuggerCommons;
class static_context;

// exported for unit testing only

/*******************************************************************************
  There is one CompilerCB per query plus one CompilerCB per invocation of an
  eval or xqdoc expression that appears in the query. The query-level ccb is
  created by the constructor of the XQueryImpl obj and remains alive for the
  whole duration of the query (including runtime). Each eval/xqdoc-level ccb is
  created as a copy of the query-level ccb during the execution of the eval/xqdoc
  expr.

  - theErrorManager :
  Pointer to the query's ErrorManager obj. (see src/api/xqueryimpl.h). The eval
  CompilerCBs share the query's ErrorManager.

  - theSctxMap :
  A reference to the query-level map that maps sctx numeric ids to sctx objs.
  (see src/api/xqueryimpl.h). The eval CompilerCBs share the query's sctx map.

  - theRootSctx :
  The root static ctx for the query or for one of the query's eval exprs. For
  an eval expr, its root sctx is a child of the query's root sctx. For the query,
  its root sctx may be (a) a child of a user-provided sctx, or (b) if the query
  is a load-prolog query, the user-provided sctx, or (c) if the user did not
  provide any sctx, a child of zorba's root sctx.

  - theDebuggerCommons :

  - theIsLoadProlog :
  Whether this is a load-prolog query or not (load-prolog queries are created
  internally by the StaticContextImpl::loadProlog() method).

  - theIsUpdating :
  Set to true if the root expr of the query or eval expr is an updating expr. 

  - theConfig.lib_module :
  If true, then if the query string that is given by the user is a library
  module, zorba will wrap it in a dummy main module and compile/execute that
  dummy module (see  XQueryCompiler::createMainModule() method). This flag is
  a copy of the lib_module flag in Zorba_CompilerHints_t.
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
    ast_callback   parse_cb;
    expr_callback  translate_cb;
    expr_callback  normalize_cb;
    expr_callback  optimize_cb;
    bool           print_item_flow;  // TODO: move to RuntimeCB

   public:
    SERIALIZABLE_CLASS(config)
    config(::zorba::serialization::Archiver& ar);

    config();

    ~config() {}

    void serialize(::zorba::serialization::Archiver& ar);
  };

public:  
  error::ErrorManager               * theErrorManager;

  std::map<short, static_context_t> * theSctxMap;

  static_context                    * theRootSctx;

  ZorbaDebuggerCommons              * theDebuggerCommons;

  bool                                theIsLoadProlog;

  bool                                theIsUpdating;

  bool                                theIsSerializingOut;

  config                              theConfig;

  long                                theTimeout;

public:
  SERIALIZABLE_CLASS(CompilerCB);
  CompilerCB(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  CompilerCB(
        std::map<short, static_context_t>&,
        error::ErrorManager*,
        long timeout = -1);

  CompilerCB(const CompilerCB& ccb);

  virtual ~CompilerCB();

  bool isLoadPrologQuery() const { return theIsLoadProlog; }

  void setLoadPrologQuery() { theIsLoadProlog = true; }

  void setIsUpdating(bool aIsUpdating) { theIsUpdating = aIsUpdating; }

  bool isUpdating() const { return theIsUpdating; }

  static_context* getStaticContext(short c);
};


}

#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
