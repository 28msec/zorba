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
    ExprManager* expMan,
    static_context* sctx,
    const QueryLoc& loc,
    expr_kind_t kind,
    const expr_t& targetExpr,
    const expr_t& sourceExpr)
  :
  expr(expMan, sctx, loc, kind),
  theTargetExpr(targetExpr),
  theSourceExpr(sourceExpr)
{
  compute_scripting_kind();
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
    ExprManager* expMan,
    static_context* sctx,
    const QueryLoc& loc,
    store::UpdateConsts::InsertType aType,
    const expr_t& sourceExpr,
    const expr_t& targetExpr)
  :
  update_expr_base(expMan, sctx, loc, insert_expr_kind, targetExpr, sourceExpr),
  theType(aType)
{
}


expr_t insert_expr::clone(substitution_t& subst) const
{
  return theExprManager->create_insert_expr(theSctx,
                         get_loc(),
                         getType(),
                         getSourceExpr()->clone(subst),
                         getTargetExpr()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
delete_expr::delete_expr(
    ExprManager* expMan,
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& targetExpr)
  :
  update_expr_base(expMan, sctx, loc, delete_expr_kind, targetExpr, NULL)
{
}


expr_t delete_expr::clone(substitution_t& subst) const
{
  return theExprManager->create_delete_expr(theSctx, get_loc(), getTargetExpr()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
replace_expr::replace_expr(
    ExprManager* expMan,
    static_context* sctx,
    const QueryLoc& loc,
    store::UpdateConsts::ReplaceType aType,
    const expr_t& targetExpr,
    const expr_t& replaceExpr)
  :
  update_expr_base(expMan, sctx, loc, replace_expr_kind, targetExpr, replaceExpr),
  theType(aType)
{
}


expr_t replace_expr::clone(substitution_t& subst) const
{
  return theExprManager->create_replace_expr(theSctx,
                          get_loc(),
                          getType(),
                          getTargetExpr()->clone(subst),
                          getReplaceExpr()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
rename_expr::rename_expr(
    ExprManager* expMan,
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& targetExpr,
    const expr_t& nameExpr)
  :
  update_expr_base(expMan, sctx, loc, rename_expr_kind, targetExpr, nameExpr)
{
}


expr_t rename_expr::clone(substitution_t& subst) const
{
  return theExprManager->create_rename_expr(theSctx,
                         get_loc(),
                         getTargetExpr()->clone(subst),
                         getNameExpr()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
copy_clause::copy_clause(var_expr_t aVar, expr_t aExpr)
  :
  theVar(aVar),
  theExpr(aExpr)
{
  theVar->set_copy_clause(this);
}


copy_clause::~copy_clause()
{
  if(theVar)
    theVar->set_copy_clause(NULL);
}


copy_clause_t copy_clause::clone(expr::substitution_t& subst) const
{
  ZORBA_ASSERT(theVar && theExpr);

  expr_t domainCopy = theExpr->clone(subst);

  var_expr_t varCopy = theExpr->get_exprMan()->create_var_expr(*theVar);

  subst[theVar.getp()] = varCopy.getp();

  return new copy_clause(varCopy, domainCopy);
}


transform_expr::transform_expr(
    ExprManager* expMan,
    static_context* sctx,
    const QueryLoc& loc)
  :
  expr(expMan, sctx, loc, transform_expr_kind)
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


void transform_expr::add_back(copy_clause_t c)
{
  theCopyClauses.push_back(c);

  checkNonUpdating(c->getExpr());
}


void transform_expr::compute_scripting_kind()
{
  ZORBA_ASSERT(false);
}


expr_t transform_expr::clone(substitution_t& subst) const
{
  ZORBA_ASSERT(theModifyExpr && theReturnExpr);

  rchandle<transform_expr> cloneExpr(theExprManager->create_transform_expr(theSctx, get_loc()));

  for (std::vector<copy_clause_t>::const_iterator lIter = theCopyClauses.begin();
       lIter != theCopyClauses.end();
       ++lIter)
  {
    cloneExpr->add_back((*lIter)->clone(subst));
  }

  cloneExpr->setModifyExpr(theModifyExpr->clone(subst));
  cloneExpr->setReturnExpr(theReturnExpr->clone(subst));

  return cloneExpr.getp();
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
