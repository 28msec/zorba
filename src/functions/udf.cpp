
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

#include "runtime/core/fncall_iterator.h"
#include "runtime/core/var_iterators.h"

#include "compiler/codegen/plan_visitor.h"
#include "compiler/expression/expr.h"
#include "compiler/api/compiler_api.h"
#include "compiler/api/compilercb.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"
#include "compiler/rewriter/tools/dataflow_annotations.h"

#include "functions/udf.h"
#include "functions/function_impl.h"

#include "annotations/annotations.h"

#include "diagnostics/xquery_warning.h"
#include "diagnostics/assert.h"

#include "types/typeops.h"

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"

#include "util/hashmap32.h"

#include "store/api/index.h" // needed for destruction of the cache


namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(user_function)


/*******************************************************************************

********************************************************************************/
user_function::user_function(
    const QueryLoc& loc,
    const signature& sig,
    expr* expr_body,
    unsigned short scriptingKind,
    CompilerCB* ccb)
  :
  function(sig, FunctionConsts::FN_UNKNOWN),
  theCCB(ccb),
  theLoc(loc),
  theScriptingKind(scriptingKind),
  theBodyExpr(expr_body),
  theIsExiting(false),
  theIsLeaf(true),
  theIsOptimized(false),
  thePlanStateSize(0),
  theCache(0),
  theCacheResults(false),
  theCacheComputed(false)
{
  setFlag(FunctionConsts::isUDF);
  resetFlag(FunctionConsts::isBuiltin);
  setDeterministic(true);
  setPrivate(false);
}


/*******************************************************************************

********************************************************************************/
user_function::user_function(::zorba::serialization::Archiver& ar)
  :
  function(ar)
{
  setFlag(FunctionConsts::isUDF);
  resetFlag(FunctionConsts::isBuiltin);

  theIsOptimized = true;
}


/*******************************************************************************

********************************************************************************/
user_function::~user_function()
{
}


/*******************************************************************************

********************************************************************************/
void user_function::serialize(::zorba::serialization::Archiver& ar)
{
  if (ar.is_serializing_out())
  {
    uint32_t planStateSize;
    getPlan(planStateSize);
    ZORBA_ASSERT(thePlan != NULL);

    computeResultCaching(theCCB->theXQueryDiagnostics);

    if (theCCB->theHasEval)
    {
      SourceFinder sourceFinder;
      std::vector<expr*> sources;
      sourceFinder.findLocalNodeSources(theBodyExpr, sources);

      if (!sources.empty())
      {
        std::vector<expr*>::const_iterator ite = sources.begin();
        std::vector<expr*>::const_iterator end = sources.end();
        for (; ite != end; ++ite)
        {
          expr* source = (*ite);

          if (source->get_expr_kind() == doc_expr_kind)
          {
            doc_expr* e = static_cast<doc_expr*>(source);
            if (!e->copyInputNodes())
              e->setCopyInputNodes();
          }
          else if (source->get_expr_kind() == elem_expr_kind)
          {
            elem_expr* e = static_cast<elem_expr*>(source);
            if (!e->copyInputNodes())
              e->setCopyInputNodes();
          }
          else
          {
            ZORBA_ASSERT(false);
          }
        }

        invalidatePlan();
        getPlan(planStateSize);
        ZORBA_ASSERT(thePlan != NULL);
      }
    }
  }
  else
  {
    thePlan = NULL;
    theBodyExpr = NULL;
  }

  serialize_baseclass(ar, (function*)this);
  ar & theCCB;
  //ar & theLoc;
  ar & theScriptingKind;
  //ar & theBodyExpr;
  //ar & theArgVars;
  ar & theIgnoresSortedNodes;
  ar & theIgnoresDuplicateNodes;

  ar & theMustCopyInputNodes;
  ar & thePropagatesInputNodes;

  //ar & theIsExiting;
  //ar & theIsLeaf;
  //ar & theMutuallyRecursiveUDFs;

  // ar & theIsOptimized;

  ar & thePlan;
  ar & thePlanStateSize;
  ar & theArgVarsRefs;

  ar & theCacheResults;
  ar & theCacheComputed;
}


#if 0
/*******************************************************************************

********************************************************************************/
xqtref_t user_function::getUDFReturnType(static_context* sctx) const
{
  xqtref_t bodyType = theBodyExpr->return_type(sctx);
  xqtref_t declaredType = get_signature().return_type();

  if (TypeOps::is_subtype(*bodyType, *declaredType))
    return bodyType;

  return declaredType;

}
#endif


/*******************************************************************************

********************************************************************************/
unsigned short user_function::getScriptingKind() const
{
  // Return the declared scripting kind. If the declared kind is updating/sequential,
  // but the function body is not really updating/sequential, an error/warning is
  // raised by the translator.
  return theScriptingKind;
}


/*******************************************************************************

********************************************************************************/
void user_function::setBody(expr* body)
{
  theBodyExpr = body;
}


/*******************************************************************************

********************************************************************************/
expr* user_function::getBody() const
{
  return theBodyExpr;
}


/*******************************************************************************

********************************************************************************/
void user_function::setArgVars(std::vector<var_expr*>& args)
{
  theArgVars = args;
}


/*******************************************************************************

********************************************************************************/
const std::vector<var_expr*>& user_function::getArgVars() const
{
  return theArgVars;
}


/*******************************************************************************

********************************************************************************/
void user_function::addMutuallyRecursiveUDFs(
    const std::vector<user_function*>& udfs,
    const std::vector<user_function*>::const_iterator& cycle)
{
  assert(theBodyExpr != NULL);

  theMutuallyRecursiveUDFs.insert(theMutuallyRecursiveUDFs.end(),
                                  cycle,
                                  udfs.end());
}


/*******************************************************************************

********************************************************************************/
void user_function::addRecursiveCall(expr* call)
{
  assert(theBodyExpr != NULL);

  if (std::find(theRecursiveCalls.begin(), theRecursiveCalls.end(), call) ==
      theRecursiveCalls.end())
  {
    theRecursiveCalls.push_back(call);
  }
}


/*******************************************************************************

********************************************************************************/
bool user_function::isRecursive() const
{
  assert(isOptimized());
  assert(theBodyExpr != NULL);
  return !theMutuallyRecursiveUDFs.empty();
}


/*******************************************************************************

********************************************************************************/
bool user_function::isMutuallyRecursiveWith(const user_function* udf)
{
  assert(isOptimized());
  assert(theBodyExpr != NULL);

  if (std::find(theMutuallyRecursiveUDFs.begin(),
                theMutuallyRecursiveUDFs.end(),
                udf) != theMutuallyRecursiveUDFs.end())
    return true;

  return false;
}


/*******************************************************************************

********************************************************************************/
bool user_function::accessesDynCtx() const
{
  if (!isOptimized())
  {
    std::cerr << "accessesDynCtx invoked on non-optimized UDF"
              << getName()->getStringValue() << std::endl;
    assert(isOptimized());
  }

  return testFlag(FunctionConsts::AccessesDynCtx);
}


/*******************************************************************************
  This method may be called after deserializing a query plan, and the query
  contains an eval expr.
********************************************************************************/
bool user_function::mustCopyInputNodes(expr* fo, csize input) const
{
  assert(theBodyExpr == NULL);

  return (theMustCopyInputNodes[input] == 0 ? false : true);
}


/*******************************************************************************
  This method may be called after deserializing a query plan, and the query
  contains an eval expr.
********************************************************************************/
bool user_function::propagatesInputNodes(expr* fo, csize input) const
{
  assert(theBodyExpr == NULL);

  return (thePropagatesInputNodes[input] == 0 ? false : true);
}


/*******************************************************************************

********************************************************************************/
BoolAnnotationValue user_function::ignoresSortedNodes(expr* fo, csize input) const
{
  assert(isOptimized());

  if (theBodyExpr == NULL)
  {
    assert(input < theIgnoresSortedNodes.size());
    return static_cast<BoolAnnotationValue>(theIgnoresSortedNodes[input]);
  }

  assert(input < theArgVars.size());
  return theArgVars[input]->getIgnoresSortedNodes();
}


/*******************************************************************************

********************************************************************************/
BoolAnnotationValue user_function::ignoresDuplicateNodes(
    expr* fo,
    csize input) const
{
  assert(isOptimized());

  if (theBodyExpr == NULL)
  {
    assert(input < theIgnoresDuplicateNodes.size());
    return static_cast<BoolAnnotationValue>(theIgnoresDuplicateNodes[input]);
  }

  assert(input < theArgVars.size());
  return theArgVars[input]->getIgnoresDuplicateNodes();
}


/*******************************************************************************

********************************************************************************/
void user_function::optimize()
{
  ZORBA_ASSERT(theBodyExpr);

  if (!theIsOptimized &&
      theCCB->theConfig.opt_level > CompilerCB::config::O0)
  {
    // Set the Optimized flag in advance to prevent an infinte loop (for
    // recursive functions, an optimization could be attempted again)
    theIsOptimized = true;

    csize numParams = theArgVars.size();

    expr* body = getBody();

    RewriterContext rctx(theCCB,
                         body,
                         this,
                         zstring(),
                         body->get_sctx()->is_in_ordered_mode());

    GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rctx);
    body = rctx.getRoot();
    setBody(body);

    if (theBodyExpr->isUnfoldable())
      setFlag(FunctionConsts::AccessesDynCtx);

    numParams = theArgVars.size();

    theIgnoresSortedNodes.resize(numParams);
    theIgnoresDuplicateNodes.resize(numParams);
    theMustCopyInputNodes.resize(numParams);
    thePropagatesInputNodes.resize(numParams);

    for (csize i = 0; i < numParams; ++i)
    {
      theIgnoresSortedNodes[i] = theArgVars[i]->getIgnoresSortedNodes();
      theIgnoresDuplicateNodes[i] = theArgVars[i]->getIgnoresDuplicateNodes();
      theMustCopyInputNodes[i] = 1;
      thePropagatesInputNodes[i] = 1;
    }

    if (theCCB->theConfig.optimize_cb != NULL)
    {
      if (getName())
      {
        theCCB->theConfig.optimize_cb(body, getName()->getStringValue().c_str());
      }
      else
      {
        theCCB->theConfig.optimize_cb(body, "inline function");
      }
    }
  }
}


/*******************************************************************************

********************************************************************************/
void user_function::invalidatePlan()
{
  thePlan = NULL;
  theArgVarsRefs.clear();
}


/*******************************************************************************

********************************************************************************/
PlanIter_t user_function::getPlan(uint32_t& planStateSize)
{
  if (thePlan == NULL)
  {
    optimize();

    csize numArgs = theArgVars.size();

    hash64map<std::vector<LetVarIter_t> *> argVarToRefsMap;

    theArgVarsRefs.resize(numArgs);

    for (csize i = 0; i < numArgs; ++i)
    {
      argVarToRefsMap.put((uint64_t)&*theArgVars[i], &theArgVarsRefs[i]);
    }

    ulong nextVarId = 1;
    const store::Item* lName = getName();
    //lName may be null of inlined functions
    thePlan = zorba::codegen((lName == 0 ?
                              "inline function" :
                              lName->getStringValue().c_str()),
                             &*theBodyExpr,
                             theCCB,
                             nextVarId,
                             &argVarToRefsMap);
  }

  planStateSize = thePlanStateSize;

  return thePlan;
}


/*******************************************************************************

********************************************************************************/
PlanIter_t user_function::codegen(
      CompilerCB* cb,
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& argv,
      expr& ann) const
{
  return new UDFunctionCallIterator(sctx, loc, argv, this);
}


/*******************************************************************************

********************************************************************************/
const std::vector<user_function::ArgVarRefs>& user_function::getArgVarsRefs() const
{
  return theArgVarsRefs;
}


/*******************************************************************************

********************************************************************************/
store::Index* user_function::getCache() const
{
  return theCache.getp();
}


/*******************************************************************************

********************************************************************************/
void user_function::setCache(store::Index* aCache)
{
  theCache = aCache;
}


/*******************************************************************************

********************************************************************************/
bool user_function::cacheResults() const
{
  return theCacheResults;
}


/*******************************************************************************
 only cache recursive (non-sequential, non-updating, deterministic)
 functions with singleton atomic input and output
********************************************************************************/
void user_function::computeResultCaching(XQueryDiagnostics* diag)
{
  if (theCacheComputed)
  {
    return;
  }

  struct OnExit
  {
  private:
    bool& theResult;
    bool& theCacheComputed;

  public:
    OnExit(bool& aResult, bool& aCacheComputed)
      :
      theResult(aResult),
      theCacheComputed(aCacheComputed) {}

    void cache() { theResult = true; }

    ~OnExit()
    {
      theCacheComputed = true;
    }
  };

  // will be destroyed when the function is exited
  // set caching to true if cache() is called
  OnExit lExit(theCacheResults, theCacheComputed);

  // check necessary conditions
  // %ann:cache or not %ann:no-cache
  if (theAnnotationList &&
      theAnnotationList->contains(AnnotationInternal::zann_nocache))
  {
    return;
  }

  // was the %ann:cache annotation given explicitly by the user
  bool lExplicitCacheRequest =
    (theAnnotationList ?
     theAnnotationList->contains(AnnotationInternal::zann_cache) :
     false);

  if (isVariadic())
  {
    if (lExplicitCacheRequest)
    {
      diag->add_warning(
      NEW_XQUERY_WARNING(zwarn::ZWST0005_CACHING_NOT_POSSIBLE,
      WARN_PARAMS(getName()->getStringValue(), ZED(ZWST0005_VARIADIC)),
      WARN_LOC(theLoc)));
    }
    return;
  }

  // parameter and return types are subtype of xs:anyAtomicType?
  const xqtref_t& lRes = theSignature.returnType();
  TypeManager* tm = theBodyExpr->get_sctx()->get_typemanager();

  if (!TypeOps::is_subtype(tm,
                           *lRes,
                           *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
                           theLoc))
  {
    if (lExplicitCacheRequest)
    {
      diag->add_warning(
      NEW_XQUERY_WARNING(zwarn::ZWST0005_CACHING_NOT_POSSIBLE,
      WARN_PARAMS(getName()->getStringValue(),
                  ZED(ZWST0005_RETURN_TYPE),
                  lRes->toString()),
      WARN_LOC(theLoc)));
    }
    return;
  }

  csize lArity = theSignature.paramCount();
  for (csize i = 0; i < lArity; ++i)
  {
    const xqtref_t& lArg = theSignature[i];
    if (!TypeOps::is_subtype(tm,
                             *lArg,
                             *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
                             theLoc))
    {
      if (lExplicitCacheRequest)
      {
        diag->add_warning(
        NEW_XQUERY_WARNING(zwarn::ZWST0005_CACHING_NOT_POSSIBLE,
        WARN_PARAMS(getName()->getStringValue(),
                    ZED(ZWST0005_PARAM_TYPE),
                    i+1,
                    lArg->toString()),
        WARN_LOC(theLoc)));
      }
      return;
    }
  }

  // function updating?
  if (isUpdating())
  {
    if (lExplicitCacheRequest)
    {
      diag->add_warning(
      NEW_XQUERY_WARNING(zwarn::ZWST0005_CACHING_NOT_POSSIBLE,
      WARN_PARAMS(getName()->getStringValue(), ZED(ZWST0005_UPDATING)),
      WARN_LOC(theLoc)));
    }
    return;
  }

  if (isSequential() || !isDeterministic())
  {
    if (lExplicitCacheRequest)
    {
      diag->add_warning(
      NEW_XQUERY_WARNING(zwarn::ZWST0006_CACHING_MIGHT_NOT_BE_INTENDED,
      WARN_PARAMS(getName()->getStringValue(),
                  (isSequential()?"sequential":"non-deterministic")),
      WARN_LOC(theLoc)));

      lExit.cache();
    }
    return;
  }


  // optimization is prerequisite before invoking isRecursive
  if (!lExplicitCacheRequest && isOptimized() && !isRecursive())
  {
    return;
  }

  lExit.cache();
}


}

/* vim:set et sw=2 ts=2: */
