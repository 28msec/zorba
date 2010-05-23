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
#include "compiler/semantic_annotations/tsv_annotation.h"
#include "compiler/semantic_annotations/annotation_keys.h"

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
  function(sig),
  theLoc(loc), 
  theBodyExpr(expr_body), 
  theScriptingKind(scriptingKind),
  theIsLeaf(true)
{
}


/*******************************************************************************

********************************************************************************/
user_function::user_function(::zorba::serialization::Archiver& ar)
  :
  function(ar)
{
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
  if(ar.is_serializing_out())
    getPlan(ar.compiler_cb);

  serialize_baseclass(ar, (function*)this);
  ar & theLoc;
  SERIALIZE_ENUM(expr_script_kind_t, theScriptingKind);
  ar & theIsLeaf;
  ar & thePlan;
  ar & theArgVarRefs;
}


/*******************************************************************************

********************************************************************************/
const QueryLoc& user_function::get_location() const
{
  return theLoc;
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
void user_function::setBody(expr_t body)
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
bool user_function::accessesDynCtx() const
{
  // All undeclared functions unfoldable. TODO: better analysis
  return (theBodyExpr == NULL || theBodyExpr->isUnfoldable());
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
                              lName->getStringValue()->c_str()),
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

