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
    expr_script_kind_t scriptingKind)
  :
  function(sig, FunctionConsts::FN_UNKNOWN),
  theLoc(loc),
  theBodyExpr(expr_body),
  theScriptingKind(scriptingKind),
  theIsLeaf(true),
  theIsOptimized(false)
{
  setFlag(FunctionConsts::isUDF);
  resetFlag(FunctionConsts::isBuiltin);
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
      getPlan(ar.compiler_cb);
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
  SERIALIZE_ENUM(expr_script_kind_t, theScriptingKind);
  ar & theIsLeaf;
  ar & theIsOptimized;
  //ar.set_is_temp_field(true);
  //ar & save_plan;
  //ar.set_is_temp_field(false);
  //if(save_plan)
  ar & thePlan;
  ar & theArgVarRefs;
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
void user_function::setBody(const expr_t& body)
{
  theBodyExpr = body;
}


/*******************************************************************************

********************************************************************************/
expr_t user_function::getBody() const
{
  return theBodyExpr;
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
const std::vector<LetVarIter_t>& user_function::getArgVarRefIters() const
{
  return theArgVarRefs;
}


/*******************************************************************************

********************************************************************************/
PlanIter_t user_function::getPlan(CompilerCB* ccb)
{
  if (thePlan == NULL)
  {
    if (!theIsOptimized && 
        ccb->theConfig.opt_level > CompilerCB::config::O0)
    {
      theIsOptimized = true;

      expr_t body = getBody();
      RewriterContext rctx(ccb, body, this, zstring());
      GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rctx);
      body = rctx.getRoot();
      setBody(body);
    }

    std::vector<std::vector<LetVarIter_t> > param_iter_vec(theArgVars.size());
    hash64map<std::vector<LetVarIter_t> *> param_map;

    for (ulong i = 0; i < theArgVars.size(); ++i)
    {
      param_map.put((uint64_t)&*theArgVars[i], &param_iter_vec[i]);
    }

    const store::Item* lName = getName();
    //lName may be null of inlined functions
    thePlan = zorba::codegen((lName == 0 ?
                              "inline function" :
                              lName->getStringValue().c_str()),
                             &*theBodyExpr,
                             ccb,
                             &param_map);

    for (ulong i = 0; i < param_iter_vec.size(); ++i)
    {
      std::vector<LetVarIter_t>& vec = param_iter_vec[i];
      switch(vec.size())
      {
        case 0:
          theArgVarRefs.push_back(NULL);
          break;

        case 1:
          theArgVarRefs.push_back(vec[0]);
          break;

        default:
          ZORBA_ASSERT(false);
          break;
      }
    }
  }
  return thePlan;
}


/*******************************************************************************

********************************************************************************/
CODEGEN_DEF(user_function)
{
  return new UDFunctionCallIterator(aSctx, aLoc, aArgs, this);
}


}

