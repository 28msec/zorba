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

#include "functions/function.h"

#include "diagnostics/assert.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(block_expr)
END_SERIALIZABLE_CLASS_VERSIONS(block_expr)

SERIALIZABLE_CLASS_VERSIONS(apply_expr)
END_SERIALIZABLE_CLASS_VERSIONS(apply_expr)

SERIALIZABLE_CLASS_VERSIONS(var_decl_expr)
END_SERIALIZABLE_CLASS_VERSIONS(var_decl_expr)

SERIALIZABLE_CLASS_VERSIONS(var_set_expr)
END_SERIALIZABLE_CLASS_VERSIONS(var_set_expr)

SERIALIZABLE_CLASS_VERSIONS(exit_expr)
END_SERIALIZABLE_CLASS_VERSIONS(exit_expr)

SERIALIZABLE_CLASS_VERSIONS(exit_catcher_expr)
END_SERIALIZABLE_CLASS_VERSIONS(exit_catcher_expr)

SERIALIZABLE_CLASS_VERSIONS(flowctl_expr)
END_SERIALIZABLE_CLASS_VERSIONS(flowctl_expr)

SERIALIZABLE_CLASS_VERSIONS(while_expr)
END_SERIALIZABLE_CLASS_VERSIONS(while_expr)

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
    static_context* sctx,
    const QueryLoc& loc,
    bool allowLastUpdating,
    std::vector<expr_t>& seq,
    std::vector<var_expr*>* assignedVars)
  :
  expr(sctx, loc, block_expr_kind),
  theArgs(seq)
{
  compute_scripting_kind2(assignedVars, allowLastUpdating);
}


void block_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theArgs;
}


void block_expr::add_at(csize pos, const expr_t& arg)
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
      var_decl_expr* varDeclExpr = static_cast<var_decl_expr*>(theArgs[i].getp());

      var_expr* varExpr = varDeclExpr->get_var_expr();

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


expr_t block_expr::clone(substitution_t& subst) const
{
  checked_vector<expr_t> seq2;
  for (csize i = 0; i < theArgs.size(); ++i)
    seq2.push_back(theArgs[i]->clone(subst));

  return new block_expr(theSctx, get_loc(), true, seq2, NULL);
}


/*******************************************************************************

********************************************************************************/
apply_expr::apply_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& inExpr,
    bool discardXDM)
  :
  expr(sctx, loc, apply_expr_kind),
  theExpr(inExpr),
  theDiscardXDM(discardXDM)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void apply_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theExpr;
  ar & theDiscardXDM;
}


void apply_expr::compute_scripting_kind()
{
  if (theExpr->is_updating())
    theScriptingKind = APPLYING_EXPR;
  else
    theScriptingKind = theExpr->get_scripting_detail();
}


expr_t apply_expr::clone(substitution_t& subst) const
{
  return new apply_expr(theSctx, get_loc(), theExpr->clone(subst), theDiscardXDM);
}


/*******************************************************************************

********************************************************************************/
var_decl_expr::var_decl_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const var_expr_t& varExpr,
    const expr_t& initExpr)
  :
  expr(sctx, loc, var_decl_expr_kind),
  theVarExpr(varExpr),
  theInitExpr(initExpr)
{
  compute_scripting_kind();

  // var_decl_expr is unfoldable because it requires access to the dyn ctx.
  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void var_decl_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theVarExpr;
  ar & theInitExpr;
}


void var_decl_expr::compute_scripting_kind()
{
  if (theVarExpr->get_kind() == var_expr::prolog_var)
    checkSimpleExpr(theInitExpr);
  else
    checkNonUpdating(theInitExpr);

  if (theInitExpr == NULL)
  {
    theScriptingKind = SIMPLE_EXPR;
  }
  else
  {
    theScriptingKind = theInitExpr->get_scripting_detail();
  }
}


expr_t var_decl_expr::clone(substitution_t& s) const
{
  var_expr_t varCopy(new var_expr(*theVarExpr));
  s[theVarExpr.getp()] = varCopy.getp();

  return new var_decl_expr(theSctx,
                           get_loc(),
                           varCopy,
                           (theInitExpr ? theInitExpr->clone(s) : NULL));
}


/*******************************************************************************

********************************************************************************/
var_set_expr::var_set_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const var_expr_t& varExpr,
    const expr_t& setExpr)
  :
  expr(sctx, loc, var_set_expr_kind),
  theVarExpr(varExpr),
  theExpr(setExpr)
{
  assert(varExpr->get_kind() == var_expr::prolog_var || 
         varExpr->get_kind() == var_expr::local_var);

  compute_scripting_kind();

  // var_set_expr is unfoldable because it requires access to the dyn ctx.
  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void var_set_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theVarExpr;
  ar & theExpr;
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


expr_t var_set_expr::clone(substitution_t& s) const
{
  expr_t varClone = theVarExpr->clone(s);

  ZORBA_ASSERT(varClone->get_expr_kind() == var_expr_kind);

  return new var_set_expr(theSctx,
                          get_loc(),
                          static_cast<var_expr*>(varClone.getp()),
                          theExpr->clone(s));
}


/*******************************************************************************

********************************************************************************/
exit_expr::exit_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& inExpr)
  :
  expr(sctx, loc, exit_expr_kind),
  theExpr(inExpr)
{
  compute_scripting_kind();

  // Exit exprs do more than just computing a result which is consumed by their
  // parent expr. So, they cannot be folded.
  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void exit_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theExpr;
}


void exit_expr::compute_scripting_kind()
{
  theScriptingKind = EXITING_EXPR;
}


expr_t exit_expr::clone(substitution_t& subst) const
{
  return new exit_expr(theSctx, get_loc(), get_value()->clone(subst));
}


/*******************************************************************************

********************************************************************************/
exit_catcher_expr::exit_catcher_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& inExpr)
  :
  expr(sctx, loc, exit_catcher_expr_kind),
  theExpr(inExpr)
{
  compute_scripting_kind();

  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void exit_catcher_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theExpr;
}


void exit_catcher_expr::compute_scripting_kind()
{
  theScriptingKind = theExpr->get_scripting_detail();
}


expr_t exit_catcher_expr::clone(substitution_t& subst) const
{
  return new exit_catcher_expr(theSctx, get_loc(), get_expr()->clone(subst));
}



/*******************************************************************************

********************************************************************************/
flowctl_expr::flowctl_expr(static_context* sctx, const QueryLoc& loc, enum action action)
  :
  expr(sctx, loc, flowctl_expr_kind),
  theAction(action)
{
  compute_scripting_kind();

  // Flow-control exprs do more than just computing a result which is consumed
  // by their parent expr. So, they cannot be folded.
  setUnfoldable(ANNOTATION_TRUE_FIXED);
}


void flowctl_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  SERIALIZE_ENUM(enum action, theAction);
}


void flowctl_expr::compute_scripting_kind()
{
  theScriptingKind = BREAKING_EXPR;
}


expr_t flowctl_expr::clone(substitution_t& subst) const
{
  return new flowctl_expr(theSctx, get_loc(), get_action());
}


/*******************************************************************************

********************************************************************************/
while_expr::while_expr(static_context* sctx, const QueryLoc& loc, expr_t body)
  : 
  expr(sctx, loc, while_expr_kind),
  theBody(body)
{
  compute_scripting_kind();
}


void while_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theBody;
}


void while_expr::compute_scripting_kind()
{
  block_expr* seqExpr = static_cast<block_expr*>(theBody.getp());

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


expr_t while_expr::clone(substitution_t& subst) const
{
  return new while_expr(theSctx, get_loc(), get_body()->clone(subst));
}



}
/* vim:set et sw=2 ts=2: */
