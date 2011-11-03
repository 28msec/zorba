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
#include "functions/function_impl.h"

#include "diagnostics/xquery_warning.h"

#include "types/typeops.h"


namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(user_function)
END_SERIALIZABLE_CLASS_VERSIONS(user_function)


/*******************************************************************************

********************************************************************************/
user_function::user_function(
    const QueryLoc& loc,
    const signature& sig,
    expr_t expr_body,
    short scriptingKind)
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
  theCacheResults(false)
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
  //bool  save_plan = true;
  if(ar.is_serializing_out())
  {
    try
    {
#if 0
      // We shouldn't try to optimize the body during the process of serializing
      // the query plan, because udfs are serialized in some "random" order, and
      // as a result, they will be optimized in this random order, instead of a
      // bottom up order. This can have undesired effect, like const-folding
      // exprs that contain calls to functions that are non-deterministic, or
      // access the dynamic context.
      //
      // As a result, we don't call getPlan() unless the optimizer is off or
      // the udf has been optimized already. If getPlan is not called, only
      // the body expr of the udf will be serialized. 
      //
      // Note: The compiler attempts to collect and optimize all udfs that
      // may actually be invoked during the execution of a query. However,
      // some such udfs may go undetected; for example, udfs that appear
      // inside eval statements. Only such undetected udfs are affected by
      // this if condition.
      if (ar.compiler_cb->theConfig.opt_level == CompilerCB::config::O0 ||
          theIsOptimized)
      {
        getPlan(ar.compiler_cb);
      }
#else
      uint32_t planStateSize;
      getPlan(ar.compiler_cb, planStateSize);
#endif
    }
    catch(...)
    {
      // cannot compile user defined function, maybe it is not even used,
      // so don't fire an error yet
      //save_plan = false;
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
  ar & theIsOptimized;
  //ar.set_is_temp_field(true);
  //ar & save_plan;
  //ar.set_is_temp_field(false);
  //if(save_plan)
  ar & thePlan;
  ar & thePlanStateSize;
  ar & theArgVarsRefs;
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
void user_function::addMutuallyRecursiveUDFs(const std::vector<user_function*>& udfs)
{
  theMutuallyRecursiveUDFs.insert(theMutuallyRecursiveUDFs.end(),
                                  udfs.begin() + 1,
                                  udfs.end());
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
BoolAnnotationValue user_function::ignoresSortedNodes(
    expr* fo,
    ulong input) const
{
  assert(isOptimized());
  assert(input < theArgVars.size());

  return theArgVars[input]->getIgnoresSortedNodes();
}


/*******************************************************************************

********************************************************************************/
BoolAnnotationValue user_function::ignoresDuplicateNodes(
    expr* fo,
    ulong input) const
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
  return theCache;
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
void user_function::computeResultCaching(XQueryDiagnostics* diag) const
{
  static_context& lCtx = GENV_ROOT_STATIC_CONTEXT;
  // check necessary conditions
  // %ann:cache or not %ann:no-cache
  if (theAnnotationList)
  {
    if (theAnnotationList->contains(
          lCtx.lookup_ann(StaticContextConsts::zann_no_cache)))
    {
      theCacheResults = false;
      return;
    }
  }

  // was the %ann:cache annotation given explicitly by the user
  bool lExplicitCacheRequest = theAnnotationList
    ?theAnnotationList->contains(
        lCtx.lookup_ann(StaticContextConsts::zann_cache))
    :false;

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
        NEW_XQUERY_WARNING(
          zwarn::ZWST0005_CACHING_NOT_POSSIBLE,
          WARN_PARAMS(
            getName()->getStringValue(),
            ZED( ZWST0005_RETURN_TYPE ),
            lRes->toString()
          ),
          WARN_LOC(theLoc)
        )
      );
    }
    theCacheResults = false;
    return;
  }

  size_t lArity = theSignature.paramCount();
  for (size_t i = 0; i < lArity; ++i)
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
          NEW_XQUERY_WARNING(
            zwarn::ZWST0005_CACHING_NOT_POSSIBLE,
            WARN_PARAMS(
              getName()->getStringValue(),
              ZED( ZWST0005_PARAM_TYPE ),
              i+1,
              lArg->toString()
            ),
            WARN_LOC(theLoc)
          )
        );
      }
      theCacheResults = false;
      return;
    }
  }

  // function updating?
  if (isUpdating())
  {
    if (lExplicitCacheRequest)
    {
      diag->add_warning(
        NEW_XQUERY_WARNING(
          zwarn::ZWST0005_CACHING_NOT_POSSIBLE,
          WARN_PARAMS(
            getName()->getStringValue(),
            ZED( ZWST0005_UPDATING )
          ),
          WARN_LOC(theLoc)
        )
      );
    }
    theCacheResults = false;
    return;
  }

  if (lExplicitCacheRequest)
  {
    if (isSequential() || !isDeterministic())
    {
      if (lExplicitCacheRequest)
      {
        diag->add_warning(
          NEW_XQUERY_WARNING(
            zwarn::ZWST0006_CACHING_MIGHT_NOT_BE_INTENDED,
            WARN_PARAMS(
              getName()->getStringValue(),
              (isSequential()?"sequential":"non-deterministic")
            ),
            WARN_LOC(theLoc)
          )
        );
      }
    }
    theCacheResults = true;
    return;
  }

  if (!lExplicitCacheRequest)
  {
    if (!isRecursive())
    {
      theCacheResults = false;
      return;
    }
  }

  theCacheResults = true;
}

/*******************************************************************************

********************************************************************************/
PlanIter_t user_function::codegen(
      CompilerCB* cb,
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& argv,
      AnnotationHolder& ann) const
{
  return new UDFunctionCallIterator(sctx, loc, argv, this);
}


}

/* vim:set et sw=2 ts=2: */
