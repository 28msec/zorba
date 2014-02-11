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
#include "compiler/expression/expr_manager.h"

#ifdef ZORBA_WITH_DEBUGGER
#include "debugger/debugger_commons.h"
#endif

#include "context/static_context.h"

#include <zorba/properties.h>

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"


namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(CompilerCB)

SERIALIZABLE_CLASS_VERSIONS_2(CompilerCB::config, TYPE_CompilerCB_config)


#define DEF_PRINT_EXPR_TREE( phase )                          \
static void print_expr_tree_##phase(const expr* e, const std::string& name) { \
  std::ostream& os = Properties::instance().getDebugStream(); \
  os << "Expression tree after " << #phase                    \
     << " for " << name << "\n";                              \
  e->put(os) << std::endl;                                    \
}


DEF_PRINT_EXPR_TREE(translation);
DEF_PRINT_EXPR_TREE(optimization);


/*******************************************************************************

********************************************************************************/
CompilerCB::config::config()
  :
  opt_level(O1),
  lib_module(false),
  for_serialization_only(false),
  parse_cb(NULL)
{
  translate_cb = optimize_cb = NULL;

  // TODO: move these out
  print_item_flow = Properties::instance().getPrintItemFlow();

  if (Properties::instance().getPrintTranslated())
    translate_cb = print_expr_tree_translation;

  if (Properties::instance().getPrintOptimized())
    optimize_cb = print_expr_tree_optimization;

  force_gflwor = Properties::instance().getForceGFLWOR();
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
  ar & for_serialization_only;
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
  thePhase(NONE),
  theHasEval(false),
  theIsEval(false),
  theIsLoadProlog(false),
  theIsUpdating(false),
  theIsSequential(false),
  theHaveTimeout(false),
  theTimeout(timeout),
  theTempIndexCounter(0),
  theNextVisitId(1),
  theEM(new ExprManager(this)),
  theCommonLanguageEnabled(false)
{
  if (timeout >= 0)
    theHaveTimeout = true;
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
  thePhase(NONE),
  theHasEval(false),
  theIsEval(false),
  theIsLoadProlog(false),
  theIsUpdating(false),
  theIsSequential(false),
  theHaveTimeout(cb.theHaveTimeout),
  theTimeout(cb.theTimeout),
  theTempIndexCounter(0),
  theNextVisitId(cb.theNextVisitId+1),
  theConfig(cb.theConfig),
  theEM(new ExprManager(this)),
  theCommonLanguageEnabled(cb.theCommonLanguageEnabled)
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
  thePhase(RUNTIME),
  theHasEval(false),
  theIsEval(false),
  theNextVisitId(1),
  theEM(new ExprManager(this))
{
}


/*******************************************************************************

********************************************************************************/
CompilerCB::~CompilerCB()
{
  delete theEM;
}


/*******************************************************************************

********************************************************************************/
void CompilerCB::serialize(::zorba::serialization::Archiver& ar)
{
  ar.set_ccb(this);

  ar & theHasEval;
  ar & theIsEval;
  ar & theIsLoadProlog;
  ar & theIsUpdating;
  ar & theIsSequential;
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
  ar & theHaveTimeout;
  ar & theTimeout;
  ar & theTempIndexCounter;
  ar & theCommonLanguageEnabled;
}



/*******************************************************************************

********************************************************************************/
static_context* CompilerCB::getStaticContext(int c)
{
  SctxMap::iterator lIter;
  lIter = theSctxMap.find(c);
  assert(lIter != theSctxMap.end());
  return lIter->second.getp();
}


/***************************************************************************//**

********************************************************************************/
void CompilerCB::add_pragma(const expr* e, pragma* p)
{
  thePragmas.insert(std::make_pair(e, p));
}


void
CompilerCB::lookup_pragmas(const expr* e, std::vector<pragma*>& pragmas) const
{
  pragmas.clear();

  std::pair<PragmaMapIter, PragmaMapIter> lRange = thePragmas.equal_range(e);
  while (lRange.first != lRange.second)
  {
    pragmas.push_back(lRange.first->second);
    ++lRange.first;
  }
}

bool
CompilerCB::lookup_pragma(
    const expr* e,
    const zstring& localname,
    pragma*& p) const
{
  std::pair<PragmaMapIter, PragmaMapIter> lRange = thePragmas.equal_range(e);
  while (lRange.first != lRange.second)
  {
    if (lRange.first->second->theQName->getLocalName() == localname)
    {
      p = lRange.first->second;
      return true;
    }
    ++lRange.first;
  }
  return false;
}



} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
