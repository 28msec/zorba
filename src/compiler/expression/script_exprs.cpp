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

#include "compiler/expression/script_exprs.h"
#include "compiler/expression/var_expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/expr_visitor.h"

#include "compiler/api/compilercb.h"

#include "functions/function.h"

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

namespace zorba
{

DEF_EXPR_ACCEPT(block_expr)
DEF_EXPR_ACCEPT(apply_expr)
DEF_EXPR_ACCEPT(var_decl_expr)
DEF_EXPR_ACCEPT(var_set_expr)
DEF_EXPR_ACCEPT(exit_expr)
DEF_EXPR_ACCEPT(exit_catcher_expr)
DEF_EXPR_ACCEPT(flowctl_expr)
DEF_EXPR_ACCEPT(while_expr)


/*******************************************************************************

********************************************************************************/
block_expr::block_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    bool allowLastUpdating,
    std::vector<expr*>& seq,
    std::vector<var_expr*>* assignedVars)
  :
  expr(ccb, sctx, udf, loc, block_expr_kind),
  theArgs(seq)
{
  compute_scripting_kind2(assignedVars, allowLastUpdating);
}


block_expr::~block_expr()
{
}


void block_expr::add(csize pos, expr* arg)
{
  assert(arg->get_expr_kind() != var_set_expr_kind);

  theArgs.insert(theArgs.begin() + pos, arg);
  compute_scripting_kind2(NULL, false);
}


void block_expr::compute_scripting_kind()
{
  ZORBA_ASSERT(false);
}


void block_expr::compute_scripting_kind2(
    std::vector<var_expr*>* assignedVars,
    bool allowLastUpdating)
{
  bool vacuous = true;

  bool hasAssignedVars = (assignedVars && !(*assignedVars).empty());

  theScriptingKind = VACUOUS_EXPR;

  csize numChildren = theArgs.size();

  for (csize i = 0; i < numChildren; ++i)
  {
    short kind = theArgs[i]->get_scripting_detail();

    if (theArgs[i]->get_expr_kind() == var_decl_expr_kind)
    {
      var_decl_expr* varDeclExpr = static_cast<var_decl_expr*>(theArgs[i]);

      var_expr* varExpr = varDeclExpr->get_var_expr();

      varExpr->set_block_expr(this);

      expr* initExpr = varDeclExpr->get_init_expr();

      if (initExpr != NULL)
      {
        kind = initExpr->get_scripting_detail();

        if (kind != VACUOUS_EXPR)
          vacuous = false;

        theScriptingKind |= kind;
      }

      if (assignedVars)
      {
        while (true)
        {
          std::vector<var_expr*>::iterator ite = (*assignedVars).begin();
          std::vector<var_expr*>::iterator end = (*assignedVars).end();

          ite = std::find(ite, end, varExpr);

          if (ite != end)
            ite = (*assignedVars).erase(ite);
          else
            break;
        }
      }

      continue;
    }

    if (kind != VACUOUS_EXPR)
      vacuous = false;

    theScriptingKind |= kind;
  }

  if (!vacuous)
    theScriptingKind &= ~VACUOUS_EXPR;

  if (hasAssignedVars)
  {
    if (!(*assignedVars).empty())
      theScriptingKind |= VAR_SETTING_EXPR;
    else
      theScriptingKind &= ~VAR_SETTING_EXPR;
  }

  if (theScriptingKind & UPDATING_EXPR)
    theScriptingKind &= ~SIMPLE_EXPR;

  if (expr::is_sequential(theScriptingKind))
    theScriptingKind &= ~SIMPLE_EXPR;

  if (allowLastUpdating &&
      numChildren > 0 &&
      theArgs[numChildren - 1]->is_updating())
  {
    theScriptingKind = UPDATING_EXPR;
  }

  checkScriptingKind();
}


bool block_expr::get_var_pos(const var_expr* v, csize& pos) const
{
  csize numArgs = theArgs.size();
  for (csize i = 0; i < numArgs; ++i)
  {
    if (theArgs[i]->get_expr_kind() == var_decl_expr_kind)
    {
      var_decl_expr* decl = static_cast<var_decl_expr*>(theArgs[i]);

      if (decl->get_var_expr() == v)
      {
        pos = i;
        return true;
      }
    }
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
apply_expr::apply_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* inExpr,
    bool discardXDM)
  :
  expr(ccb, sctx, udf, loc, apply_expr_kind),
  theExpr(inExpr),
  theDiscardXDM(discardXDM)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void apply_expr::compute_scripting_kind()
{
  if (theExpr->is_updating())
    theScriptingKind = APPLYING_EXPR;
  else
    theScriptingKind = theExpr->get_scripting_detail();
}


/*******************************************************************************

********************************************************************************/
var_decl_expr::var_decl_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    var_expr* varExpr,
    expr* initExpr)
  :
  var_set_expr(ccb, sctx, udf, loc, varExpr, initExpr, true)
{
  theKind = var_decl_expr_kind;

  compute_scripting_kind();
}


var_decl_expr::~var_decl_expr()
{
  // Note: var_expr objs for global vars live longer than their associated
  // var_decl_expr, because such var_expr objs are also registered in the sctx.
  //if (theInitExpr)
  //  theVarExpr->remove_set_expr(this);
}


void var_decl_expr::compute_scripting_kind()
{
  if (theVarExpr->get_kind() == var_expr::prolog_var)
    checkSimpleExpr(theExpr);
  else
    checkNonUpdating(theExpr);

  if (theExpr == NULL)
  {
    theScriptingKind = SIMPLE_EXPR;
  }
  else
  {
    theScriptingKind = theExpr->get_scripting_detail();
  }
}


/*******************************************************************************

********************************************************************************/
var_set_expr::var_set_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    var_expr* varExpr,
    expr* setExpr,
    bool isDecl)
  :
  expr(ccb, sctx, udf, loc, var_set_expr_kind),
  theVarExpr(varExpr),
  theExpr(setExpr)
{
  assert(varExpr->get_kind() == var_expr::prolog_var ||
         varExpr->get_kind() == var_expr::local_var);

  if (!isDecl)
    compute_scripting_kind();

  // var_set_expr and var_decl_expr are unfoldable because they require access
  // to the dyn ctx.
  setUnfoldable(ANNOTATION_TRUE_FIXED);

  if (setExpr)
    varExpr->add_set_expr(this);
}


var_set_expr::~var_set_expr()
{
  //theVarExpr->remove_set_expr(this);
}


void var_set_expr::set_expr(expr* e)
{
  assert(theExpr == NULL);

  theExpr = e;
  theVarExpr->add_set_expr(this);

  compute_scripting_kind();
}


void var_set_expr::compute_scripting_kind()
{
  checkNonUpdating(theExpr);

  theScriptingKind = VAR_SETTING_EXPR;
  theScriptingKind |= theExpr->get_scripting_detail();
  theScriptingKind &= ~VACUOUS_EXPR;
  theScriptingKind &= ~SIMPLE_EXPR;

  checkScriptingKind();
}


/*******************************************************************************

********************************************************************************/
exit_expr::exit_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* inExpr)
  :
  expr(ccb, sctx, udf, loc, exit_expr_kind),
  theExpr(inExpr),
  theCatcherExpr(NULL)
{
  compute_scripting_kind();

  // Exit exprs do more than just computing a result which is consumed by their
  // parent expr. So, they cannot be folded.
  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


exit_expr::~exit_expr()
{
  if (theCatcherExpr)
  {
    theCatcherExpr->removeExitExpr(this);
  }
}


void exit_expr::compute_scripting_kind()
{
  theScriptingKind = EXITING_EXPR;
}


/*******************************************************************************

********************************************************************************/
exit_catcher_expr::exit_catcher_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* inExpr,
    std::vector<expr*>& exitExprs)
  :
  expr(ccb, sctx, udf, loc, exit_catcher_expr_kind),
  theExpr(inExpr)
{
  theExitExprs.swap(exitExprs);

  std::vector<expr*>::const_iterator ite = theExitExprs.begin();
  std::vector<expr*>::const_iterator end = theExitExprs.end();
  for (; ite != end; ++ite)
  {
    static_cast<exit_expr*>(*ite)->setCatcherExpr(this);
  }

  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


exit_catcher_expr::~exit_catcher_expr()
{
  std::vector<expr*>::const_iterator ite = theExitExprs.begin();
  std::vector<expr*>::const_iterator end = theExitExprs.end();
  for (; ite != end; ++ite)
  {
    static_cast<exit_expr*>(*ite)->setCatcherExpr(NULL);
  }
}


void exit_catcher_expr::compute_scripting_kind()
{
  theScriptingKind = theExpr->get_scripting_detail();
}


void exit_catcher_expr::removeExitExpr(const expr* exitExpr)
{
  std::vector<expr*>::iterator ite = theExitExprs.begin();
  std::vector<expr*>::iterator end = theExitExprs.end();
  for (; ite != end; ++ite)
  {
    if (*ite == exitExpr)
    {
      theExitExprs.erase(ite);
      return;
    }
  }
}


/*******************************************************************************

********************************************************************************/
flowctl_expr::flowctl_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    FlowCtlAction action)
  :
  expr(ccb, sctx, udf, loc, flowctl_expr_kind),
  theAction(action)
{
  compute_scripting_kind();

  // Flow-control exprs do more than just computing a result which is consumed
  // by their parent expr. So, they cannot be folded.
  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void flowctl_expr::compute_scripting_kind()
{
  theScriptingKind = BREAKING_EXPR;
}


/*******************************************************************************

********************************************************************************/
while_expr::while_expr(
    CompilerCB* ccb,
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    expr* body)
  :
  expr(ccb, sctx, udf, loc, while_expr_kind),
  theBody(body)
{
  compute_scripting_kind();
}


void while_expr::compute_scripting_kind()
{
  block_expr* seqExpr = static_cast<block_expr*>(theBody);

  expr* condExpr = (*seqExpr)[0];

  ZORBA_ASSERT(condExpr->get_expr_kind() == if_expr_kind);

  if_expr* ifExpr = static_cast<if_expr*>(condExpr);
  condExpr = ifExpr->get_cond_expr();

  checkNonUpdating(condExpr);

  if (!seqExpr->is_sequential() && !seqExpr->is_vacuous())
  {
    throw XQUERY_EXCEPTION(zerr::XSST0008, ERROR_LOC(get_loc()));
  }

  theScriptingKind = theBody->get_scripting_detail();

  theScriptingKind &= ~BREAKING_EXPR;

  if (theScriptingKind == UNKNOWN_SCRIPTING_KIND)
    theScriptingKind = SIMPLE_EXPR;
}

}
/* vim:set et sw=2 ts=2: */
