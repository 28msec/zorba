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

#include "functions/udf.h"
#include "annotations/annotations.h"
#include "functions/function_impl.h"

#include "diagnostics/xquery_warning.h"

#include "types/typeops.h"

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"

#include "store/api/index.h" // needed for destruction of the cache


namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(user_function)


/*******************************************************************************

********************************************************************************/
user_function::user_function(
    const QueryLoc& loc,
    const signature& sig,
    expr_t expr_body,
    short scriptingKind,
    CompilerCB* compilerCB)
  :
  function(sig, FunctionConsts::FN_UNKNOWN),
  theLoc(loc),
  theBodyExpr(expr_body),
  theScriptingKind(scriptingKind),
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
  theLocalUdfs = compilerCB->get_local_udfs();
  theLocalUdfs->push_back(this);
}


/*******************************************************************************

********************************************************************************/
user_function::user_function(::zorba::serialization::Archiver& ar)
  :
  function(ar)
{
  setFlag(FunctionConsts::isUDF);
  resetFlag(FunctionConsts::isBuiltin);
}


/*******************************************************************************

********************************************************************************/
user_function::~user_function()
{
  if (theLocalUdfs != NULL)
    theLocalUdfs->remove(this);
}


/*******************************************************************************

********************************************************************************/
void user_function::prepare_for_serialize(CompilerCB* compilerCB)
{
  uint32_t planStateSize;
  getPlan(compilerCB, planStateSize);

  std::vector<user_function*>::iterator udf_it;
  for(udf_it = theMutuallyRecursiveUDFs.begin();
      udf_it != theMutuallyRecursiveUDFs.end();
      ++udf_it)
  {
    if ((*udf_it)->thePlan == NULL)
      (*udf_it)->prepare_for_serialize(compilerCB);
  }
}


/*******************************************************************************

********************************************************************************/
void user_function::serialize(::zorba::serialization::Archiver& ar)
{
  if (ar.is_serializing_out())
  {
    try
    {
      //uint32_t planStateSize;
      //getPlan(ar.compiler_cb, planStateSize);
      assert(thePlan != NULL);
      ZORBA_ASSERT(thePlan != NULL);
    }
    catch(...)
    {
      // cannot compile user defined function, maybe it is not even used,
      // so don't fire an error yet
    }
  }
  else
  {
    thePlan = NULL;
    theBodyExpr = NULL;
  }

  serialize_baseclass(ar, (function*)this);
  ar & theLoc;
  ar & theBodyExpr;
  ar & theArgVars;
  ar & theScriptingKind;
  ar & theIsExiting;
  ar & theIsLeaf;
  ar & theMutuallyRecursiveUDFs;
  ar & theIsOptimized;
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
short user_function::getScriptingKind() const 
{
  // Return the declared scripting kind. If the declared kind is updating/sequential,
  // but the function body is not really updating/sequential, an error/warning is
  // raised by the translator.
  return theScriptingKind;

#if 0
  if (theBodyExpr == NULL)
    return theScriptingKind;

  return theBodyExpr->get_scripting_detail();
#endif
}


/*******************************************************************************

********************************************************************************/
void user_function::setBody(const expr_t& body)
{
  theBodyExpr = body;
}


/*******************************************************************************

********************************************************************************/
expr* user_function::getBody() const
{
  return theBodyExpr.getp();
}


/*******************************************************************************

********************************************************************************/
void user_function::setArgVars(std::vector<var_expr_t>& args)
{
  theArgVars = args;
}


/*******************************************************************************

********************************************************************************/
const std::vector<var_expr_t>& user_function::getArgVars() const
{
  return theArgVars;
}


/*******************************************************************************

********************************************************************************/
void user_function::addMutuallyRecursiveUDFs(
    const std::vector<user_function*>& udfs,
    const std::vector<user_function*>::const_iterator& cycle)
{
  theMutuallyRecursiveUDFs.insert(theMutuallyRecursiveUDFs.end(),
                                  cycle,
                                  udfs.end());
}


/*******************************************************************************

********************************************************************************/
void user_function::addRecursiveCall(expr* call)
{
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
  return !theMutuallyRecursiveUDFs.empty();
}


/*******************************************************************************

********************************************************************************/
bool user_function::isMutuallyRecursiveWith(const user_function* udf)
{
  assert(isOptimized());

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

  // All undeclared functions unfoldable. TODO: better analysis
  return (theBodyExpr == NULL || theBodyExpr->isUnfoldable());
}


/*******************************************************************************

********************************************************************************/
BoolAnnotationValue user_function::ignoresSortedNodes(expr* fo, csize input) const
{
  assert(isOptimized());
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
  assert(input < theArgVars.size());

  return theArgVars[input]->getIgnoresDuplicateNodes();
}


/*******************************************************************************

********************************************************************************/
const std::vector<user_function::ArgVarRefs>& user_function::getArgVarsRefs() const
{
  return theArgVarsRefs;
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
PlanIter_t user_function::getPlan(CompilerCB* ccb, uint32_t& planStateSize)
{
  if (thePlan == NULL)
  {
    if (!theIsOptimized && 
        ccb->theConfig.opt_level > CompilerCB::config::O0)
    {
      theIsOptimized = true;

      expr_t body = getBody();

      RewriterContext rctx(ccb,
                           body,
                           this,
                           zstring(),
                           body->get_sctx()->is_in_ordered_mode());

      GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rctx);
      body = rctx.getRoot();
      setBody(body);
    }

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
                             ccb,
                             nextVarId,
                             &argVarToRefsMap);
  }

  planStateSize = thePlanStateSize;

  return thePlan;
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
  TypeManager* tm = lRes->get_manager();

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


}

/* vim:set et sw=2 ts=2: */
