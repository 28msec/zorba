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
#include "stdafx.h"

#include "compiler/api/compilercb.h"
#include "compiler/expression/expr_base.h"

#ifdef ZORBA_WITH_DEBUGGER
#include "debugger/debugger_commons.h"
#endif

#include "context/static_context.h"

#include "system/properties.h"

#include "zorbaserialization/serialization_engine.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(CompilerCB)
END_SERIALIZABLE_CLASS_VERSIONS(CompilerCB)

SERIALIZABLE_CLASS_VERSIONS(CompilerCB::config)
END_SERIALIZABLE_CLASS_VERSIONS(CompilerCB::config)


#define DEF_PRINT_EXPR_TREE( phase )                                    \
static void print_expr_tree_##phase(const expr* e, const std::string& name) \
{                                                                       \
  std::ostream& os = Properties::instance()->debug_out();               \
  os << "Expression tree after " << #phase                              \
     << " for " << name << "\n";                                        \
  e->put(os) << std::endl;                                              \
}


DEF_PRINT_EXPR_TREE(translation);
DEF_PRINT_EXPR_TREE(optimization);


/*******************************************************************************

********************************************************************************/
CompilerCB::config::config()
  :
  opt_level(O1),
  lib_module(false),
  parse_cb(NULL)
{
  translate_cb = optimize_cb = NULL;

  // TODO: move these out
  print_item_flow = Properties::instance()->printItemFlow();

  if (Properties::instance()->printTranslated())
    translate_cb = print_expr_tree_translation;

  if (Properties::instance()->printOptimized())
    optimize_cb = print_expr_tree_optimization;

  force_gflwor = Properties::instance()->forceGflwor();
}


/*******************************************************************************

********************************************************************************/
CompilerCB::config::config(::zorba::serialization::Archiver& ar) 
  :
  parse_cb(NULL),
  translate_cb(NULL),
  optimize_cb(NULL)
{
}


/*******************************************************************************

********************************************************************************/
void CompilerCB::config::serialize(::zorba::serialization::Archiver& ar)
{
  ar & force_gflwor;
  SERIALIZE_ENUM(opt_level_t, opt_level);
  ar & lib_module;
  ar & print_item_flow;
}


/*******************************************************************************

********************************************************************************/
CompilerCB::CompilerCB(XQueryDiagnostics* errmgr, long timeout)
  :
  theXQueryDiagnostics(errmgr),
  theRootSctx(0),
#ifdef ZORBA_WITH_DEBUGGER
  theDebuggerCommons(0),
#endif
  theIsEval(false),
  theIsLoadProlog(false),
  theIsUpdating(false),
  theIsSequential(false),
  theTimeout(timeout),
  theTempIndexCounter(0)
{
}


/*******************************************************************************
  Used by the eval iterator to create a new ccb as a copy of the ccb of the
  enclosing query. 
*******************************************************************************/
CompilerCB::CompilerCB(const CompilerCB& cb)
  :
  zorba::serialization::SerializeBaseClass(cb),
  theXQueryDiagnostics(cb.theXQueryDiagnostics),
  theRootSctx(NULL),
#ifdef ZORBA_WITH_DEBUGGER
  theDebuggerCommons(cb.theDebuggerCommons),
#endif
  theIsEval(false),
  theIsLoadProlog(false),
  theIsUpdating(false),
  theTimeout(cb.theTimeout),
  theTempIndexCounter(0),
  theConfig(cb.theConfig)
{
}


/*******************************************************************************

********************************************************************************/
CompilerCB::CompilerCB(::zorba::serialization::Archiver& ar)
  :
  ::zorba::serialization::SerializeBaseClass(),
  theXQueryDiagnostics(NULL),
  theRootSctx(NULL),
#ifdef ZORBA_WITH_DEBUGGER
  theDebuggerCommons(NULL),
#endif
  theIsEval(false)
{
}


/*******************************************************************************

********************************************************************************/
CompilerCB::~CompilerCB() 
{
}


/*******************************************************************************

********************************************************************************/
void CompilerCB::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theIsEval;
  ar & theIsLoadProlog;
  ar & theIsUpdating;
  ar & theSctxMap;
  ar & theRootSctx;
#ifdef ZORBA_WITH_DEBUGGER
  ar & theDebuggerCommons;
#endif
  if (!ar.is_serializing_out()) 
  {
    //don't serialize this
    theXQueryDiagnostics = NULL;
  }
  ar & theConfig;
  ar & theTimeout;
  ar & theTempIndexCounter;
}



/*******************************************************************************

********************************************************************************/
static_context* CompilerCB::getStaticContext(short c)
{
  std::map<short, static_context_t>::iterator lIter;
  lIter = theSctxMap.find(c);
  assert(lIter != theSctxMap.end());
  return lIter->second.getp();
}

  
} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
