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
    const QueryLoc& loc,
    expr_kind_t kind,
    expr* targetExpr,
    expr* sourceExpr)
  :
  expr(ccb, sctx, loc, kind),
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
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc,
    store::UpdateConsts::InsertType aType,
    expr* sourceExpr,
    expr* targetExpr)
  :
  update_expr_base(ccb, sctx, loc, insert_expr_kind, targetExpr, sourceExpr),
  theType(aType)
{
}


expr* insert_expr::clone(substitution_t& subst) const
{
  return theCCB->theEM->create_insert_expr(theSctx,
                         get_loc(),
                         getType(),
                         getSourceExpr()->clone(subst),
                         getTargetExpr()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
delete_expr::delete_expr(
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc,
    expr* targetExpr)
  :
  update_expr_base(ccb, sctx, loc, delete_expr_kind, targetExpr, NULL)
{
}


expr* delete_expr::clone(substitution_t& subst) const
{
  return theCCB->theEM->create_delete_expr(theSctx, get_loc(), getTargetExpr()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
replace_expr::replace_expr(
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc,
    store::UpdateConsts::ReplaceType aType,
    expr* targetExpr,
    expr* replaceExpr)
  :
  update_expr_base(ccb, sctx, loc, replace_expr_kind, targetExpr, replaceExpr),
  theType(aType)
{
}


expr* replace_expr::clone(substitution_t& subst) const
{
  return theCCB->theEM->create_replace_expr(theSctx,
                          get_loc(),
                          getType(),
                          getTargetExpr()->clone(subst),
                          getReplaceExpr()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
rename_expr::rename_expr(
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc,
    expr* targetExpr,
    expr* nameExpr)
  :
  update_expr_base(ccb, sctx, loc, rename_expr_kind, targetExpr, nameExpr)
{
}


expr* rename_expr::clone(substitution_t& subst) const
{
  return theCCB->theEM->create_rename_expr(theSctx,
                         get_loc(),
                         getTargetExpr()->clone(subst),
                         getNameExpr()->clone(subst));
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


copy_clause::~copy_clause()
{
  if (theVar)
    theVar->set_copy_clause(NULL);
}


copy_clause* copy_clause::clone(expr::substitution_t& subst) const
{
  ZORBA_ASSERT(theVar && theExpr);

  expr* domainCopy = theExpr->clone(subst);

  var_expr* varCopy = theExpr->get_ccb()->theEM->create_var_expr(*theVar);

  subst[theVar] = varCopy;

  return theCCB->theEM->create_copy_clause(varCopy, domainCopy);
}


transform_expr::transform_expr(
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc)
  :
  expr(ccb, sctx, loc, transform_expr_kind)
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


expr* transform_expr::clone(substitution_t& subst) const
{
  ZORBA_ASSERT(theModifyExpr && theReturnExpr);

  transform_expr* cloneExpr =
    theCCB->theEM->create_transform_expr(theSctx, get_loc());

  for (std::vector<copy_clause*>::const_iterator lIter = theCopyClauses.begin();
       lIter != theCopyClauses.end();
       ++lIter)
  {
    cloneExpr->add_back((*lIter)->clone(subst));
  }

  cloneExpr->setModifyExpr(theModifyExpr->clone(subst));
  cloneExpr->setReturnExpr(theReturnExpr->clone(subst));

  return cloneExpr;
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
