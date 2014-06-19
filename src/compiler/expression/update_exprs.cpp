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

#include "compiler/expression/update_exprs.h"
#include "compiler/expression/var_expr.h"
#include "compiler/expression/expr_visitor.h"
#include "compiler/expression/expr_manager.h"

#include "compiler/api/compilercb.h"

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

namespace zorba
{


DEF_EXPR_ACCEPT (insert_expr)
DEF_EXPR_ACCEPT (delete_expr)
DEF_EXPR_ACCEPT (rename_expr)
DEF_EXPR_ACCEPT (replace_expr)
DEF_EXPR_ACCEPT (transform_expr)


/*******************************************************************************

********************************************************************************/
update_expr_base::update_expr_base(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr_kind_t kind,
    expr* targetExpr,
    expr* sourceExpr)
  :
  expr(ccb, sctx, udf, loc, kind),
  theTargetExpr(targetExpr),
  theSourceExpr(sourceExpr)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void update_expr_base::compute_scripting_kind()
{
  theScriptingKind = UPDATING_EXPR;

  checkSimpleExpr(theTargetExpr);

  if (theSourceExpr)
    checkSimpleExpr(theSourceExpr);
}


/*******************************************************************************

********************************************************************************/
insert_expr::insert_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    store::UpdateConsts::InsertType aType,
    expr* sourceExpr,
    expr* targetExpr)
  :
  update_expr_base(ccb, sctx, udf, loc, insert_expr_kind, targetExpr, sourceExpr),
  theType(aType)
{
}


/*******************************************************************************

********************************************************************************/
delete_expr::delete_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* targetExpr)
  :
  update_expr_base(ccb, sctx, udf, loc, delete_expr_kind, targetExpr, NULL)
{
}


/*******************************************************************************

********************************************************************************/
replace_expr::replace_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    store::UpdateConsts::ReplaceType aType,
    expr* targetExpr,
    expr* replaceExpr)
  :
  update_expr_base(ccb, sctx, udf, loc, replace_expr_kind, targetExpr, replaceExpr),
  theType(aType)
{
}


/*******************************************************************************

********************************************************************************/
rename_expr::rename_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* targetExpr,
    expr* nameExpr)
  :
  update_expr_base(ccb, sctx, udf, loc, rename_expr_kind, targetExpr, nameExpr)
{
}


/*******************************************************************************

********************************************************************************/
copy_clause::copy_clause(CompilerCB* ccb, var_expr* aVar, expr* aExpr)
  :
  theVar(aVar),
  theExpr(aExpr),
  theCCB(ccb)
{
  theVar->set_copy_clause(this);
}


copy_clause* copy_clause::clone(
    user_function* udf,
    expr::substitution_t& subst) const
{
  ZORBA_ASSERT(theVar && theExpr);

  expr* domainCopy = theExpr->clone(udf, subst);

  var_expr* varCopy = theExpr->get_ccb()->theEM->create_var_expr(udf, *theVar);

  subst[theVar] = varCopy;

  return theCCB->theEM->create_copy_clause(varCopy, domainCopy);
}


transform_expr::transform_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc)
  :
  expr(ccb, sctx, udf, loc, transform_expr_kind)
{
  theScriptingKind = SIMPLE_EXPR;
}


void transform_expr::setModifyExpr(expr* e)
{
  theModifyExpr = e;

  if (! theModifyExpr->is_updating_or_vacuous())
  {
    throw XQUERY_EXCEPTION(err::XUST0002,
                           ERROR_PARAMS(ZED(XUST0002_Transform)),
                           ERROR_LOC(theModifyExpr->get_loc()));
  }
}


void transform_expr::setReturnExpr(expr* e)
{
  theReturnExpr = e;

  checkNonUpdating(theReturnExpr);

  theScriptingKind = theReturnExpr->get_scripting_detail();

  theScriptingKind &= ~VACUOUS_EXPR;
}


void transform_expr::add_back(copy_clause* c)
{
  theCopyClauses.push_back(c);

  checkNonUpdating(c->getExpr());
}


void transform_expr::compute_scripting_kind()
{
  ZORBA_ASSERT(false);
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
