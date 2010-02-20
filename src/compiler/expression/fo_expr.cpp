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
#include <vector>

#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/expr_visitor.h"
#include "compiler/xqddf/collection_decl.h"

#include "context/static_context.h"

#include "functions/library.h"
#include "functions/function.h"

namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(fo_expr)
END_SERIALIZABLE_CLASS_VERSIONS(fo_expr)

DEF_EXPR_ACCEPT (fo_expr)



/*******************************************************************************

********************************************************************************/
class fo_expr_iterator_data : public expr_iterator_data
{
public:
  ulong theCurrentArg;
  ulong theNumArgs;

public:
  fo_expr_iterator_data(expr* e)
    :
    expr_iterator_data(e),
    theCurrentArg(0),
    theNumArgs(static_cast<fo_expr*>(e)->num_args())
  {
  }
};


/*******************************************************************************
  first-order expressions. Represents function invocations as well as:

  OrExpr, AndExpr, ComparisonExpr, RangeExpr, AdditiveExpr, MultiplicativeExpr,
  UnionExpr, and IntersectExceptExpr.
********************************************************************************/

fo_expr* fo_expr::create_seq(short sctx, const QueryLoc& loc)
{
  function* f = BuiltinFunctionLibrary::getFunction(FunctionConsts::OP_CONCATENATE_N);

  std::auto_ptr<fo_expr> fo(new fo_expr(sctx, loc, f));

  return fo.release();
}


fo_expr::fo_expr(
    short sctx,
    const QueryLoc& loc,
    const function* f)
  :
  expr(sctx, loc),
  theFunction(const_cast<function*>(f))
{
  assert(f != NULL);
  compute_scripting_kind();
}


fo_expr::fo_expr(
    short sctx,
    const QueryLoc& loc,
    const function* f,
    const expr* arg)
  :
  expr(sctx, loc),
  theFunction(const_cast<function*>(f))
{
  assert(f != NULL);
  theArgs.resize(1);
  theArgs[0] = arg;

  compute_scripting_kind();
}


fo_expr::fo_expr(
    short sctx,
    const QueryLoc& loc,
    const function* f,
    const expr* arg1,
    const expr* arg2)
  :
  expr(sctx, loc),
  theFunction(const_cast<function*>(f))
{
  assert(f != NULL);
  theArgs.resize(2);
  theArgs[0] = arg1;
  theArgs[1] = arg2;

  compute_scripting_kind();
}


fo_expr::fo_expr(
    short sctx,
    const QueryLoc& loc,
    const function* f,
    const std::vector<expr_t>& args)
  :
  expr(sctx, loc),
  theArgs(args),
  theFunction(const_cast<function*>(f))
{
  assert(f != NULL);
  compute_scripting_kind();
}


void fo_expr::serialize(::zorba::serialization::Archiver &ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theArgs;
  SERIALIZE_FUNCTION((function*&)theFunction);
}


const signature& fo_expr::get_signature() const
{
  return theFunction->get_signature();
}


const store::Item* fo_expr::get_fname() const
{
  return theFunction->getName();
}


void fo_expr::compute_scripting_kind() const
{
  const function* func = get_func();
  ulong numArgs = num_args();

  if (func->getKind() == FunctionConsts::OP_CONCATENATE_N)
  {
    expr_script_kind_t kind = VACUOUS_EXPR;

    for (ulong i = 0; i < numArgs; ++i)
    {
      if (theArgs[i] == NULL)
        continue;

      expr_script_kind_t argKind = theArgs[i]->get_scripting_kind();

      kind = scripting_kind_anding(kind, argKind, theArgs[i]->get_loc());
    }

    theCache.scripting_kind.kind = kind;
  }
  else if (func->getKind() == FunctionConsts::OP_VAR_ASSIGN_1)
  {
    for (ulong i = 0; i < numArgs; ++i)
    {
      if (theArgs[i] == NULL)
        continue;

      expr_script_kind_t argKind = theArgs[i]->get_scripting_kind();

      if (argKind == UPDATE_EXPR)
      {
        ZORBA_ERROR_LOC(XUST0001, theArgs[i]->get_loc());
      }
    }
  }
  else
  {
    theCache.scripting_kind.kind = func->getUpdateType();

    for (ulong i = 0; i < numArgs; ++i)
    {
      if (theArgs[i] == NULL)
        continue;

      expr_script_kind_t argKind = theArgs[i]->get_scripting_kind();

      if (argKind == UPDATE_EXPR || argKind == SEQUENTIAL_EXPR)
      {
        ZORBA_ERROR_LOC(XUST0001, theArgs[i]->get_loc());
      }
    }
  }

  theCache.scripting_kind.valid = true;
}


xqtref_t fo_expr::return_type_impl(static_context* sctx) const
{
  const function* func = get_func();

  if (func->getKind() == FunctionConsts::FN_ZORBA_DDL_COLLECTION_1)
  {
    const store::Item* qname = theArgs[0]->getQName(sctx);

    if (qname != NULL)
    {
      const StaticallyKnownCollection* collection = sctx->lookup_collection(qname);
      if (collection != NULL)
      {
        return collection->getCollectionType();
      }
      else
      {
        ZORBA_ERROR_LOC_PARAM(XDDY0001_COLLECTION_NOT_DECLARED, get_loc(),
                              qname->getStringValue(), "");
      }
    }
  }

  std::vector<xqtref_t> types;

  std::vector<expr_t>::const_iterator i = theArgs.begin();
  std::vector<expr_t>::const_iterator end = theArgs.end();

  for (; i != end; ++i)
    types.push_back((*i)->return_type(sctx));

  return theFunction->getReturnType(types);
}


expr_t fo_expr::clone(substitution_t& subst) const
{
  if (get_func()->getKind() == FunctionConsts::FN_ZORBA_DDL_COLLECTION_1)
  {
    expr::subst_iter_t i = subst.find(this);

     if (i != subst.end())
       return i->second;
  }

  std::auto_ptr<fo_expr> fo(new fo_expr(theSctxId, get_loc(), get_func()));

  for (unsigned i = 0; i < theArgs.size(); ++i)
    fo->theArgs.push_back(theArgs[i]->clone(subst));

  fo->theCache.scripting_kind.kind  = theCache.scripting_kind.kind;

  return fo.release();
}


expr_iterator_data* fo_expr::make_iter()
{
  return new fo_expr_iterator_data(this);
}


void fo_expr::next_iter(expr_iterator_data& v)
{
  fo_expr_iterator_data& vv = static_cast<fo_expr_iterator_data&>(v);

  BEGIN_EXPR_ITER();

  for (; vv.theCurrentArg < vv.theNumArgs; ++vv.theCurrentArg)
  {
    ITER(theArgs[vv.theCurrentArg]);
  }

  END_EXPR_ITER();
}


}

