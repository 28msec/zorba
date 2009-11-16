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
#ifndef COMPILER_COMPILERCB_H
#define COMPILER_COMPILERCB_H

#include <vector>
#include <map>

#include <zorba/config.h>

#include "common/shared_types.h"

#include "context/static_context.h"

#include "zorbaserialization/class_serializer.h"

namespace zorba {

class ZorbaDebuggerCommons;
class static_context;

// exported for unit testing only

/*******************************************************************************
  There is one CompilerCB per module participating in a compilation. The
  compilerCB for the root module is created by the constructor of the XQueryImpl
  obj and remains alive for the whole duration of the query (including runtime).
  The CompilerCBs of imported modules are created and stay alive only during the
  translation of their associated modules.

  theConfig       :

  theRootSctx     : The root static ctx for the associated module. For each
                    module, this is a child of either a user provided static
                    ctx or the zorba default root context.

  theSctxMap      : A reference to the query-level map that maps sctx numeric ids
                    to sctx objs. (see api/xqueryimpl.h)

  theErrorManager : Pointer to an ErrorManager obj. In fact, all CompilerCBs
                    share the same ErrorManager.

  theDebuggerCommons :

  theIsLoadProlog :

  theIsUpdating   :
********************************************************************************/
class ZORBA_DLL_PUBLIC CompilerCB : public zorba::serialization::SerializeBaseClass
{
public:
  typedef struct config : public zorba::serialization::SerializeBaseClass
  {
    typedef enum 
    {
      O0,
      O1
    } opt_level_t;
    
    typedef void (* expr_callback) (const expr *, const std::string& name);
    typedef void (* ast_callback) (const parsenode *, const std::string& name);

    bool force_gflwor;
    opt_level_t opt_level;
    bool lib_module;
    ast_callback parse_cb;
    expr_callback translate_cb;
    expr_callback normalize_cb;
    expr_callback optimize_cb;
    bool print_item_flow;  // TODO: move to RuntimeCB

   public:
    SERIALIZABLE_CLASS(config)
    config(::zorba::serialization::Archiver& ar);

    config();

    ~config() {}

    void serialize(::zorba::serialization::Archiver& ar);
  }
  config_t;

public:  
  config_t                            theConfig;

  static_context_t                    theRootSctx;

  std::map<short, static_context_t> * theSctxMap;

  error::ErrorManager               * theErrorManager;

  ZorbaDebuggerCommons              * theDebuggerCommons;

  bool                                theIsLoadProlog;

  bool                                theIsUpdating;

public:
  SERIALIZABLE_CLASS(CompilerCB);
  CompilerCB(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  CompilerCB(std::map<short, static_context_t>&);

  CompilerCB(const CompilerCB&);

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
