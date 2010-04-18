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

#include "compiler/api/compilercb.h"
#include "compiler/expression/expr_base.h"

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
DEF_PRINT_EXPR_TREE(normalization);
DEF_PRINT_EXPR_TREE(optimization);


CompilerCB::config::config()
  :
  opt_level(O1),
  lib_module(false),
  parse_cb(NULL)
{
  translate_cb = normalize_cb = optimize_cb = NULL;
  // TODO: move these out
  print_item_flow = Properties::instance()->printItemFlow();

  if (Properties::instance()->printTranslated())
    translate_cb = print_expr_tree_translation;

  if (Properties::instance()->printNormalized())
    normalize_cb = print_expr_tree_normalization;

  if (Properties::instance()->printOptimized())
    optimize_cb = print_expr_tree_optimization;

  force_gflwor = Properties::instance()->forceGflwor();
}


CompilerCB::config::config(::zorba::serialization::Archiver& ar) 
  :
  parse_cb(NULL),
  translate_cb(NULL),
  normalize_cb(NULL),
  optimize_cb(NULL)
{
}


void CompilerCB::config::serialize(::zorba::serialization::Archiver& ar)
{
  ar & force_gflwor;
  SERIALIZE_ENUM(opt_level_t, opt_level);
  ar & lib_module;
  ar & print_item_flow;
}


CompilerCB::CompilerCB(
    std::map<short, static_context_t>& sctx_map,
    error::ErrorManager* errmgr,
    long timeout)
  :
  theErrorManager(errmgr),
  theSctxMap(&sctx_map),
  theRootSctx(0),
  theDebuggerCommons(0),
  theIsLoadProlog(false),
  theIsUpdating(false),
  theTimeout(timeout)
{
}


CompilerCB::CompilerCB(const CompilerCB& cb)
  :
  zorba::serialization::SerializeBaseClass(cb),
  theErrorManager(cb.theErrorManager),
  theSctxMap(cb.theSctxMap),
  theRootSctx(NULL),
  theDebuggerCommons(cb.theDebuggerCommons),
  theIsLoadProlog(false),
  theIsUpdating(false),
  theConfig(cb.theConfig),
  theTimeout(cb.theTimeout)
{
}


CompilerCB::CompilerCB(::zorba::serialization::Archiver& ar)
  :
  ::zorba::serialization::SerializeBaseClass(),
  theDebuggerCommons(NULL)
{
}

CompilerCB::~CompilerCB() 
{
}


void CompilerCB::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theIsLoadProlog;
  ar & theIsUpdating;
  ar & theSctxMap;
  ar & theRootSctx;
  if(!ar.is_serializing_out())
  {
    theErrorManager = NULL;//don't serialize this
    theDebuggerCommons = NULL;
  }
  ar & theConfig;
  ar & theTimeout;
}


static_context* CompilerCB::getStaticContext(short c)
{
  std::map<short, static_context_t>::iterator lIter;
  lIter = theSctxMap->find(c);
  assert(lIter != theSctxMap->end());
  return lIter->second.getp();
}


  
} /* namespace zorba */
