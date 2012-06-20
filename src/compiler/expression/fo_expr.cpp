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

#include <vector>

#include "compiler/expression/fo_expr.h"
#include "compiler/expression/expr_visitor.h"

#include "context/static_context.h"

#include "functions/library.h"
#include "functions/function.h"
#include "functions/udf.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"


namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(fo_expr)


void fo_expr::accept(expr_visitor& v)
{
  if (v.begin_visit(*this))
  {
    accept_children(v); 
  }

  v.end_visit(*this);
}



/*******************************************************************************
  first-order expressions. Represents function invocations as well as:

  OrExpr, AndExpr, ComparisonExpr, RangeExpr, AdditiveExpr, MultiplicativeExpr,
  UnionExpr, and IntersectExceptExpr.
********************************************************************************/

fo_expr* fo_expr::create_seq(static_context* sctx, const QueryLoc& loc)
{
  function* f = BuiltinFunctionLibrary::getFunction(FunctionConsts::OP_CONCATENATE_N);

  std::auto_ptr<fo_expr> fo(new fo_expr(sctx, loc, f));

  return fo.release();
}


fo_expr::fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f)
  :
  expr(sctx, loc, fo_expr_kind),
  theFunction(const_cast<function*>(f))
{
  // This method is private and it is to be used only by the clone method
  assert(f != NULL);
  theScriptingKind = VACUOUS_EXPR;
}


fo_expr::fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const expr* arg)
  :
  expr(sctx, loc, fo_expr_kind),
  theFunction(const_cast<function*>(f))
{
  assert(f != NULL);
  theArgs.resize(1);
  theArgs[0] = arg;

  compute_scripting_kind();
}


fo_expr::fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const expr* arg1,
    const expr* arg2)
  :
  expr(sctx, loc, fo_expr_kind),
  theFunction(const_cast<function*>(f))
{
  assert(f != NULL);
  theArgs.resize(2);
  theArgs[0] = arg1;
  theArgs[1] = arg2;

  compute_scripting_kind();
}


fo_expr::fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const std::vector<expr_t>& args)
  :
  expr(sctx, loc, fo_expr_kind),
  theArgs(args),
  theFunction(const_cast<function*>(f))
{
  assert(f != NULL);
  compute_scripting_kind();
}


void fo_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theArgs;
  ar & ((function*&)theFunction);
}


const signature& fo_expr::get_signature() const
{
  return theFunction->getSignature();
}


const store::Item* fo_expr::get_fname() const
{
  return theFunction->getName();
}


void fo_expr::compute_scripting_kind()
{
  const function* func = get_func();
  csize numArgs = num_args();

  switch (func->getKind())
  {
  case FunctionConsts::OP_CONCATENATE_N:
  {
    bool vacuous = true;

    theScriptingKind = VACUOUS_EXPR;

    for (csize i = 0; i < numArgs; ++i)
    {
      if (theArgs[i] == NULL)
        continue;

      short argKind = theArgs[i]->get_scripting_detail();

      if (argKind == VACUOUS_EXPR)
        continue;

      vacuous = false;

      if (!theSctx->is_feature_set(feature::scripting))
      {
        if (is_updating() && !(argKind & UPDATING_EXPR) && argKind != VACUOUS_EXPR)
        {
          RAISE_ERROR(err::XUST0001, theArgs[i]->get_loc(),
          ERROR_PARAMS(ZED(XUST0001_CONCAT)));
        }
        
        if (i > 0 && !is_updating() && !is_vacuous() && (argKind & UPDATING_EXPR))
        {
          RAISE_ERROR(err::XUST0001, theArgs[i]->get_loc(),
          ERROR_PARAMS(ZED(XUST0001_CONCAT)));
        }
      }

      theScriptingKind |= argKind;
    }

    if (!vacuous)
      theScriptingKind &= ~VACUOUS_EXPR;

    if (theScriptingKind & UPDATING_EXPR)
      theScriptingKind &= ~SIMPLE_EXPR;

    if (is_sequential(theScriptingKind))
      theScriptingKind &= ~SIMPLE_EXPR;

    checkScriptingKind();

    break;
  }
  case FunctionConsts::OP_HOIST_1:
  case FunctionConsts::OP_UNHOIST_1:
  {
    theScriptingKind = theArgs[0]->get_scripting_detail();
    break;
  }
  default:
  {
    theScriptingKind = func->getScriptingKind();

    bool vacuous = (theScriptingKind == VACUOUS_EXPR);

    for (csize i = 0; i < numArgs; ++i)
    {
      if (theArgs[i] == NULL)
        continue;

      expr* arg = theArgs[i].getp();

      if (arg->is_updating())
      {
        RAISE_ERROR(err::XUST0001, theArgs[i]->get_loc(),
        ERROR_PARAMS(ZED(XUST0001_Generic)));
      }

      short argKind = arg->get_scripting_detail();

      if (arg->is_sequential())
      {
        vacuous = false;

        theScriptingKind |= argKind;
      }
    }

    if (!vacuous)
      theScriptingKind &= ~VACUOUS_EXPR;

    if (theScriptingKind & UPDATING_EXPR)
      theScriptingKind &= ~SIMPLE_EXPR;

    if (is_sequential(theScriptingKind))
      theScriptingKind &= ~SIMPLE_EXPR;

    checkScriptingKind();
  }
  }
}


expr_t fo_expr::clone(substitution_t& subst) const
{
  if (get_func()->getKind() == FunctionConsts::STATIC_COLLECTIONS_DML_COLLECTION_1)
  {
    expr::subst_iter_t i = subst.find(this);

    if (i != subst.end())
      return i->second;
  }

  std::auto_ptr<fo_expr> fo(new fo_expr(theSctx, get_loc(), get_func()));

  for (csize i = 0; i < theArgs.size(); ++i)
    fo->theArgs.push_back(theArgs[i]->clone(subst));

  fo->theScriptingKind  = theScriptingKind;

  return fo.release();
}


}

/* vim:set et sw=2 ts=2: */
