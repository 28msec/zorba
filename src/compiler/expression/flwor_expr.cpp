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

#include "system/globalenv.h"

#include "context/static_context.h"

#include "functions/library.h"

#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/expr_visitor.h"

#include "compiler/api/compilercb.h"

#include "types/root_typemanager.h"
#include "types/typeops.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"
#include "diagnostics/xquery_diagnostics.h"

namespace zorba
{

/*******************************************************************************

********************************************************************************/
DEF_EXPR_ACCEPT (flwor_expr)

flwor_clause::~flwor_clause()
{
}


/*******************************************************************************

********************************************************************************/
forletwin_clause::forletwin_clause(
    static_context* sctx,
    CompilerCB* ccb,
    const QueryLoc& loc,
    flwor_clause::ClauseKind kind,
    var_expr* varExpr,
    expr* domainExpr)
  :
  flwor_clause(sctx, ccb, loc, kind),
  theVarExpr(varExpr),
  theDomainExpr(domainExpr)
{
  if (theVarExpr != NULL)
    theVarExpr->set_flwor_clause(this);

  expr::checkNonUpdating(theDomainExpr);
  //expr::checkSimpleExpr(theDomainExpr);
}


forletwin_clause::~forletwin_clause()
{
  if (theVarExpr != NULL)
    theVarExpr->set_flwor_clause(NULL);
}


void forletwin_clause::set_expr(expr* v)
{
  theDomainExpr = v;
}


void forletwin_clause::set_var(var_expr* v)
{
  theVarExpr = v;

  if (theVarExpr != NULL)
  {
    theVarExpr->set_flwor_clause(this);

    if (theKind == window_clause && theVarExpr->get_type() != NULL)
    {
      RootTypeManager& rtm = GENV_TYPESYSTEM;
      TypeManager* tm = theVarExpr->get_type_manager();

      const QueryLoc& loc = theVarExpr->get_loc();

      xqtref_t varType = theVarExpr->get_type();
      xqtref_t domainType = theDomainExpr->get_return_type();

      if (!TypeOps::is_subtype(tm, *rtm.ITEM_TYPE_STAR, *varType, loc) &&
          !TypeOps::is_subtype(tm, *domainType, *varType, loc))
      {
        theDomainExpr = theCCB->theEM->
        create_treat_expr(theDomainExpr->get_sctx(),
                          theDomainExpr->get_loc(),
                          theDomainExpr,
                          varType,
                          TreatIterator::TYPE_MATCH);
      }
    }
  }
}


/*******************************************************************************

********************************************************************************/
for_clause::for_clause(
    static_context* sctx,
    CompilerCB* ccb,
    const QueryLoc& loc,
    var_expr* varExpr,
    expr* domainExpr,
    var_expr* posVarExpr,
    var_expr* scoreVarExpr,
    bool isAllowingEmpty)
  :
  forletwin_clause(sctx, ccb, loc, flwor_clause::for_clause, varExpr, domainExpr),
  thePosVarExpr(posVarExpr),
  theScoreVarExpr(scoreVarExpr),
  theAllowingEmpty(isAllowingEmpty)
{
  if (thePosVarExpr != NULL)
    thePosVarExpr->set_flwor_clause(this);

  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(this);

  if (varExpr != NULL && sctx != NULL)
  {
    RootTypeManager& rtm = GENV_TYPESYSTEM;
    TypeManager* tm = sctx->get_typemanager();

    xqtref_t declaredType = varExpr->get_type();
    if (declaredType != NULL)
    {
      if (declaredType->is_empty())
      {
        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(ZED(BadType_23o), "empty-sequence"));
      }

      xqtref_t domainType = domainExpr->get_return_type();

      if (!TypeOps::is_subtype(tm, *rtm.ITEM_TYPE_STAR, *declaredType, loc))
      {
        declaredType = tm->create_type(*declaredType, TypeConstants::QUANT_STAR);

        if (!TypeOps::is_subtype(tm, *domainType, *declaredType, loc))
        {
          xqtref_t varType = TypeOps::intersect_type(*domainType, *declaredType, tm);
          if (TypeOps::is_equal(tm, *varType, *rtm.NONE_TYPE, loc))
          {
            RAISE_ERROR(err::XPTY0004, loc,
            ERROR_PARAMS(ZED(BadType_23o),
                         *domainType,
                         ZED(NoTreatAs_4),
                         *declaredType));
          }

          domainExpr = theCCB->theEM->create_treat_expr(sctx,
                                            loc,
                                            domainExpr,
                                            declaredType,
                                            TreatIterator::TYPE_MATCH);

          set_expr(domainExpr);
        }
      }
    }
  }
}


for_clause::~for_clause()
{
  if (thePosVarExpr != NULL)
    thePosVarExpr->set_flwor_clause(NULL);

  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(NULL);
}


var_expr* for_clause::get_pos_var() const
{
  return thePosVarExpr;
}


var_expr* for_clause::get_score_var() const
{
  return theScoreVarExpr;
}


void for_clause::set_pos_var(var_expr* v)
{
  thePosVarExpr = v;
  if (thePosVarExpr != NULL)
    thePosVarExpr->set_flwor_clause(this);
}


void for_clause::set_score_var(var_expr* v)
{
  theScoreVarExpr = v;
  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(this);
}


flwor_clause* for_clause::clone(expr::substitution_t& subst) const
{
  expr* domainCopy = theDomainExpr->clone(subst);

  var_expr* varCopy = theCCB->theEM->create_var_expr(*theVarExpr);
  subst[theVarExpr] = varCopy;

  var_expr* posvarCopy = NULL;
  var_expr* pos_var_ptr = thePosVarExpr;
  if (pos_var_ptr)
  {
    posvarCopy = theCCB->theEM->create_var_expr(*pos_var_ptr);
    subst[pos_var_ptr] = posvarCopy;
  }

  var_expr* scorevarCopy = NULL;
  var_expr* score_var_ptr = theScoreVarExpr;
  if (score_var_ptr)
  {
    scorevarCopy = theCCB->theEM->create_var_expr(*score_var_ptr);
    subst[score_var_ptr] = scorevarCopy;
  }

  return theCCB->theEM->create_for_clause(theContext,
                        get_loc(),
                        varCopy,
                        domainCopy,
                        posvarCopy,
                        scorevarCopy,
                        theAllowingEmpty);
}


/*******************************************************************************

********************************************************************************/
let_clause::let_clause(
    static_context* sctx,
    CompilerCB* ccb,
    const QueryLoc& loc,
    var_expr* varExpr,
    expr* domainExpr,
    bool lazy)
  :
  forletwin_clause(sctx, ccb, loc, flwor_clause::let_clause, varExpr, domainExpr),
  theScoreVarExpr(NULL),
  theLazyEval(lazy)
{
  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(this);

  if (varExpr != NULL && sctx != NULL)
  {
    RootTypeManager& rtm = GENV_TYPESYSTEM;
    TypeManager* tm = sctx->get_typemanager();

    xqtref_t declaredType = varExpr->get_type();

    if (declaredType != NULL)
    {
      xqtref_t domainType = domainExpr->get_return_type();

      if (!TypeOps::is_subtype(tm, *rtm.ITEM_TYPE_STAR, *declaredType, loc) &&
          !TypeOps::is_subtype(tm, *domainType, *declaredType, loc))
      {
        xqtref_t varType = TypeOps::intersect_type(*domainType, *declaredType, tm);

        if (TypeOps::is_equal(tm, *varType, *rtm.NONE_TYPE, loc))
        {
          RAISE_ERROR(err::XPTY0004, loc,
          ERROR_PARAMS(ZED(BadType_23o), *domainType, ZED(NoTreatAs_4), *declaredType));
        }

        domainExpr = theCCB->theEM->create_treat_expr(sctx,
                                    loc,
                                    domainExpr,
                                    declaredType,
                                    TreatIterator::TYPE_MATCH);

        set_expr(domainExpr);
      }
    }
  }
}


let_clause::~let_clause()
{
  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(NULL);
}


var_expr* let_clause::get_score_var() const
{
  return theScoreVarExpr;
}


void let_clause::set_score_var(var_expr* v)
{
  theScoreVarExpr = v;
  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(this);
}


flwor_clause* let_clause::clone(expr::substitution_t& subst) const
{
  expr* domainCopy = theDomainExpr->clone(subst);

  var_expr* varCopy = theCCB->theEM->create_var_expr(*theVarExpr);
  subst[theVarExpr] = varCopy;

#if 0
  var_expr* scorevarCopy = NULL;
  var_expr* score_var_ptr = theScoreVarExpr;
  if (score_var_ptr)
  {
    scorevarCopy = theCCB->theEM->create_var_expr(*score_var_ptr);
    subst->get(score_var_ptr) = scorevarCopy;
  }
#endif

  return theCCB->theEM->create_let_clause(theContext,
                        get_loc(),
                        varCopy,
                        domainCopy,
                        theLazyEval);
}



/*******************************************************************************

********************************************************************************/
window_clause::window_clause(
    static_context* sctx,
    CompilerCB* ccb,
    const QueryLoc& loc,
    window_t winKind,
    var_expr* varExpr,
    expr* domainExpr,
    flwor_wincond* winStart,
    flwor_wincond* winStop,
    bool lazy)
  :
  forletwin_clause(sctx, ccb, loc, flwor_clause::window_clause, varExpr, domainExpr),
  theWindowKind(winKind),
  theWinStartCond(winStart),
  theWinStopCond(winStop),
  theLazyEval(lazy)
{
  if (theWinStartCond != NULL)
    theWinStartCond->set_flwor_clause(this);

  if (theWinStopCond != NULL)
    theWinStopCond->set_flwor_clause(this);

  if (winKind == tumbling_window)
    theLazyEval = true;

  if (varExpr != NULL && sctx != NULL)
  {
    RootTypeManager& rtm = GENV_TYPESYSTEM;
    TypeManager* tm = sctx->get_typemanager();

    xqtref_t varType = varExpr->get_type();

    if (varType != NULL)
    {
      xqtref_t domainType = domainExpr->get_return_type();

      if (!TypeOps::is_subtype(tm, *rtm.ITEM_TYPE_STAR, *varType, loc) &&
          !TypeOps::is_subtype(tm, *domainType, *varType, loc))
      {
        domainExpr = theCCB->theEM->
        create_treat_expr(sctx,
                          loc,
                          domainExpr,
                          varType,
                          TreatIterator::TYPE_MATCH);

        set_expr(domainExpr);
      }
    }
  }
}


window_clause::~window_clause()
{
  if (theWinStartCond != NULL)
    theWinStartCond->set_flwor_clause(NULL);

  if (theWinStopCond != NULL)
    theWinStopCond->set_flwor_clause(NULL);
}


void window_clause::set_win_start(flwor_wincond* cond)
{
  theWinStartCond = cond;
  if (theWinStartCond != NULL)
    theWinStartCond->set_flwor_clause(this);
}


void window_clause::set_win_stop(flwor_wincond* cond)
{
  theWinStopCond = cond;
  if (theWinStopCond != NULL)
    theWinStopCond->set_flwor_clause(this);
}


flwor_clause* window_clause::clone(expr::substitution_t& subst) const
{
  expr* domainCopy = theDomainExpr->clone(subst);

  var_expr* varCopy = theCCB->theEM->create_var_expr(*theVarExpr);
  subst[theVarExpr] = varCopy;

  flwor_wincond* cloneStartCond = NULL;
  flwor_wincond* cloneStopCond = NULL;

  if (theWinStartCond != NULL)
    cloneStartCond = theWinStartCond->clone(subst);

  if (theWinStopCond != NULL)
    cloneStopCond = theWinStopCond->clone(subst);

  return theCCB->theEM->create_window_clause(theContext,
                                             get_loc(),
                                             theWindowKind,
                                             varCopy,
                                             domainCopy,
                                             cloneStartCond,
                                             cloneStopCond,
                                             theLazyEval);
}


/*******************************************************************************

********************************************************************************/
flwor_wincond::flwor_wincond(
    CompilerCB* ccb,
    static_context* sctx,
    bool isOnly,
    const vars& in_vars,
    const vars& out_vars,
    expr* cond)
  :
  theIsOnly(isOnly),
  theInputVars(in_vars),
  theOutputVars(out_vars),
  theCondExpr(cond),
  theCCB(ccb)
{
  expr::checkSimpleExpr(theCondExpr);

  if (sctx != NULL)
  {
    TypeManager* tm = sctx->get_typemanager();

    xqtref_t condType = theCondExpr->get_return_type();

    if(!TypeOps::is_equal(tm,
                          *condType,
                          *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE,
                          theCondExpr->get_loc()))
    {
      theCondExpr = theCCB->theEM->create_fo_expr(theCondExpr->get_sctx(),
                                theCondExpr->get_loc(),
                                GET_BUILTIN_FUNCTION(FN_BOOLEAN_1),
                                theCondExpr);
    }
  }
}


flwor_wincond::~flwor_wincond()
{
  set_flwor_clause(NULL);
}


flwor_wincond::vars::vars()
:
posvar(NULL),
curr(NULL),
prev(NULL),
next(NULL)
{
}

flwor_wincond::vars::~vars()
{
//  set_flwor_clause(NULL);
}


void flwor_wincond::vars::set_flwor_clause(flwor_clause* c)
{
  if (posvar != NULL) posvar->set_flwor_clause(c);
  if (curr != NULL) curr->set_flwor_clause(c);
  if (prev != NULL) prev->set_flwor_clause(c);
  if (next != NULL) next->set_flwor_clause(c);
}


void flwor_wincond::vars::clone(
    ExprManager* mgr,
    flwor_wincond::vars& cloneVars,
    expr::substitution_t& subst) const
{
  if (posvar != NULL)
  {
    var_expr* varCopy = mgr->create_var_expr(*posvar);
    subst[posvar] = varCopy;
    cloneVars.posvar = varCopy;
  }

  if (curr != NULL)
  {
    var_expr* varCopy = mgr->create_var_expr(*curr);
    subst[curr] = varCopy;
    cloneVars.curr = varCopy;
  }

  if (prev != NULL)
  {
    var_expr* varCopy = mgr->create_var_expr(*prev);
    subst[prev] = varCopy;
    cloneVars.prev = varCopy;
  }

  if (next != NULL)
  {
    var_expr* varCopy = mgr->create_var_expr(*next);
    subst[next] = varCopy;
    cloneVars.next = varCopy;
  }
}


void flwor_wincond::set_flwor_clause(flwor_clause* c)
{
  theInputVars.set_flwor_clause(c);
  theOutputVars.set_flwor_clause(c);
}


flwor_wincond* flwor_wincond::clone(expr::substitution_t& subst) const
{
  flwor_wincond::vars cloneInVars;
  flwor_wincond::vars cloneOutVars;

  theInputVars.clone(theCCB->theEM, cloneInVars, subst);
  theOutputVars.clone(theCCB->theEM, cloneOutVars, subst);

  expr* cloneCondExpr = theCondExpr->clone(subst);

  return theCCB->theEM->create_flwor_wincond(NULL,
                           theIsOnly,
                           cloneInVars,
                           cloneOutVars,
                           cloneCondExpr);
}


/*******************************************************************************

********************************************************************************/
group_clause::group_clause(
     static_context* sctx,
     CompilerCB* ccb,
     const QueryLoc& loc,
     const rebind_list_t& gvars,
     rebind_list_t ngvars,
     const std::vector<std::string>& collations)
  :
  flwor_clause(sctx, ccb, loc, flwor_clause::group_clause),
  theGroupVars(gvars),
  theNonGroupVars(ngvars),
  theCollations(collations)
{
  csize numGVars = theGroupVars.size();
  csize numNGVars = theNonGroupVars.size();

  for (csize i = 0; i < numGVars; ++i)
    theGroupVars[i].second->set_flwor_clause(this);

  for (csize i = 0; i < numNGVars; ++i)
    theNonGroupVars[i].second->set_flwor_clause(this);
}


group_clause::~group_clause()
{
  csize numGVars = theGroupVars.size();
  csize numNGVars = theNonGroupVars.size();

  for (csize i = 0; i < numGVars; ++i)
    theGroupVars[i].second->set_flwor_clause(NULL);

  for (csize i = 0; i < numNGVars; ++i)
    theNonGroupVars[i].second->set_flwor_clause(NULL);
}


expr* group_clause::get_input_for_group_var(const var_expr* var)
{
  csize numVars = theGroupVars.size();
  for (csize i = 0; i < numVars; ++i)
  {
    if (theGroupVars[i].second == var)
      return theGroupVars[i].first;
  }

  return NULL;
}


expr* group_clause::get_input_for_nongroup_var(const var_expr* var)
{
  csize numVars = theNonGroupVars.size();
  for (csize i = 0; i < numVars; ++i)
  {
    if (theNonGroupVars[i].second == var)
      return theNonGroupVars[i].first;
  }

  return NULL;
}


flwor_clause* group_clause::clone(expr::substitution_t& subst) const
{
  csize numGroupVars = theGroupVars.size();
  csize numNonGroupVars = theNonGroupVars.size();

  rebind_list_t cloneGroupVars(numGroupVars);
  rebind_list_t cloneNonGroupVars(numNonGroupVars);

  ExprManager* exprMgr = NULL;

  if (numGroupVars > 0)
    exprMgr = theGroupVars[0].first->get_ccb()->theEM;
  else if (numNonGroupVars > 0)
    exprMgr = theNonGroupVars[0].first->get_ccb()->theEM;

  for (csize i = 0; i < numGroupVars; ++i)
  {
    cloneGroupVars[i].first = theGroupVars[i].first->clone(subst);
    cloneGroupVars[i].second = exprMgr->create_var_expr(*theGroupVars[i].second);
    subst[theGroupVars[i].second] = cloneGroupVars[i].second;
  }

  for (csize i = 0; i < numNonGroupVars; ++i)
  {
    cloneNonGroupVars[i].first = theNonGroupVars[i].first->clone(subst);
    cloneNonGroupVars[i].second = exprMgr->create_var_expr(*theNonGroupVars[i].second);
    subst[theNonGroupVars[i].second] = cloneNonGroupVars[i].second;
  }

  return theCCB->theEM->create_group_clause(theContext,
                          get_loc(),
                          cloneGroupVars,
                          cloneNonGroupVars,
                          theCollations);
}


/*******************************************************************************

********************************************************************************/
orderby_clause::orderby_clause(
    static_context* sctx,
    CompilerCB* ccb,
    const QueryLoc& loc,
    bool stable,
    const std::vector<OrderModifier>& modifiers,
    const std::vector<expr*>& orderingExprs)
  :
  flwor_clause(sctx, ccb, loc, flwor_clause::order_clause),
  theStableOrder(stable),
  theModifiers(modifiers),
  theOrderingExprs(orderingExprs)
{
  std::vector<expr*>::const_iterator ite = orderingExprs.begin();
  std::vector<expr*>::const_iterator end = orderingExprs.end();

  for (; ite != end; ++ite)
  {
    expr::checkSimpleExpr((*ite));
  }
}


flwor_clause* orderby_clause::clone(expr::substitution_t& subst) const
{
  csize numColumns = num_columns();

  std::vector<expr*> cloneExprs(numColumns);

  for (csize i = 0; i < numColumns; ++i)
  {
    cloneExprs[i] = theOrderingExprs[i]->clone(subst);
  }

  return theCCB->theEM->create_orderby_clause(theContext,
                            get_loc(),
                            theStableOrder,
                            theModifiers,
                            cloneExprs);
}


/*******************************************************************************

********************************************************************************/
materialize_clause::materialize_clause(
    static_context* sctx,
    CompilerCB* ccb,
    const QueryLoc& loc)
  :
  flwor_clause(sctx, ccb, loc, flwor_clause::materialize_clause)
{
}


flwor_clause* materialize_clause::clone(expr::substitution_t& subst) const
{
  // we will reach here under the following scenario:
  // 1. We do plan seriazation
  // 2. getPlan is called on udf A; this causes a mat clause to be created
  //    during the codegen on A's body
  // 3. getPlan is called on udf B, which invokes A, and A's body is
  //    inlined (and as a result cloned) inside B's body.
  return theCCB->theEM->create_materialize_clause(theContext, get_loc());
}


/*******************************************************************************

********************************************************************************/
count_clause::count_clause(
    static_context* sctx,
    CompilerCB* ccb,
    const QueryLoc& loc,
    var_expr* var)
  :
  flwor_clause(sctx, ccb, loc, flwor_clause::count_clause),
  theVarExpr(var)
{
}


count_clause::~count_clause()
{
  if (theVarExpr != NULL)
    theVarExpr->set_flwor_clause(NULL);
}


flwor_clause* count_clause::clone(expr::substitution_t& subst) const
{
  ExprManager* exprMgr = theVarExpr->get_ccb()->theEM;

  var_expr* cloneVar = exprMgr->create_var_expr(*theVarExpr);
  subst[theVarExpr] = cloneVar;

  return theCCB->theEM->create_count_clause(theContext, get_loc(), cloneVar);
}


/*******************************************************************************

********************************************************************************/
where_clause::where_clause(
    static_context* sctx,
    CompilerCB* ccb,
    const QueryLoc& loc,
    expr* where)
  :
  flwor_clause(sctx, ccb, loc, flwor_clause::where_clause),
  theWhereExpr(where)
{
  expr::checkSimpleExpr(theWhereExpr);
}


void where_clause::set_expr(expr* where)
{
  theWhereExpr = where;
}


flwor_clause* where_clause::clone(expr::substitution_t& subst) const
{
  expr* cloneExpr = theWhereExpr->clone(subst);

  return theCCB->theEM->create_where_clause(theContext, get_loc(), cloneExpr);
}


/*******************************************************************************

********************************************************************************/
flwor_expr::flwor_expr(
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc,
    bool general)
  :
  expr(ccb, sctx, loc, (general ? gflwor_expr_kind : flwor_expr_kind)),
  theIsGeneral(general),
  theHasSequentialClauses(false),
  theReturnExpr(NULL)
{
  theScriptingKind = SIMPLE_EXPR;
}


/*******************************************************************************

********************************************************************************/
flwor_clause* flwor_expr::get_clause(csize i) const
{
  assert(i < theClauses.size());

  return theClauses[i];
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::remove_clause(csize pos)
{
  assert(pos < theClauses.size());

  if (theClauses[pos]->theFlworExpr == this)
    theClauses[pos]->theFlworExpr = NULL;

  theClauses.erase(theClauses.begin() + pos);
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::add_clause(flwor_clause* c, bool computeScriptingKind)
{
  theClauses.push_back(c);
  c->theFlworExpr = this;

  if (computeScriptingKind)
    compute_scripting_kind();
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::add_clause(csize pos, flwor_clause* c)
{
  theClauses.insert(theClauses.begin() + pos, c);
  c->theFlworExpr = this;

  compute_scripting_kind();
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::add_where(expr* e)
{
  where_clause* whereClause = theCCB->theEM->
  create_where_clause(theSctx, e->get_loc(), e);

  add_clause(whereClause);
}


/*******************************************************************************
  For simple flwor only. If a where clause exists already, replace its expr
  with the given expr. Otherwise, add a where clause with the given expr.
********************************************************************************/
void flwor_expr::set_where(expr* e)
{
  ZORBA_ASSERT(e != NULL);

  csize numClauses = num_clauses();
  csize i;

  for (i = 0; i < numClauses; ++i)
  {
    if (theClauses[i]->get_kind() != flwor_clause::for_clause &&
        theClauses[i]->get_kind() != flwor_clause::let_clause)
    {
      break;
    }
  }

  if (i == numClauses)
  {
    add_where(e);
    return;
  }

  if (theClauses[i]->get_kind() == flwor_clause::where_clause)
  {
    where_clause* wc = reinterpret_cast<where_clause*>(theClauses[i]);
    wc->set_expr(e);
    return;
  }

  where_clause* wc = theCCB->theEM->create_where_clause(theSctx, e->get_loc(), e);
  theClauses.insert(theClauses.begin() + i, wc);
  wc->theFlworExpr = this;
}


/*******************************************************************************
  For simple flwor only.
********************************************************************************/
void flwor_expr::remove_where_clause()
{
  csize numClauses = num_clauses();
  for (csize i = 0; i < numClauses; ++i)
  {
    if (theClauses[i]->get_kind() == flwor_clause::where_clause)
    {
      theClauses[i]->theFlworExpr = NULL;
      theClauses.erase(theClauses.begin() + i);
      return;
    }
  }
}


/*******************************************************************************
  For simple flwor only.
********************************************************************************/
expr* flwor_expr::get_where() const
{
  csize numClauses = num_clauses();
  for (csize i = 0; i < numClauses; ++i)
  {
    if (theClauses[i]->get_kind() == flwor_clause::where_clause)
      return reinterpret_cast<where_clause*>(theClauses[i])->get_expr();
  }

  return NULL;
}


/*******************************************************************************
  For simple flwor only.
********************************************************************************/
group_clause* flwor_expr::get_group_clause() const
{
  csize numClauses = num_clauses();
  for (csize i = 0; i < numClauses; ++i)
  {
    if (theClauses[i]->get_kind() == flwor_clause::group_clause)
      return reinterpret_cast<group_clause*>(theClauses[i]);
  }

  return NULL;
}


/*******************************************************************************
  For simple flwor only.
********************************************************************************/
orderby_clause* flwor_expr::get_order_clause() const
{
  csize numClauses = num_clauses();
  for (csize i = 0; i < numClauses; ++i)
  {
    if (theClauses[i]->get_kind() == flwor_clause::order_clause)
      return reinterpret_cast<orderby_clause*>(theClauses[i]);
  }

  return NULL;
}


/*******************************************************************************
  For simple flwor only.
********************************************************************************/
csize flwor_expr::num_forlet_clauses()
{
  csize num = 0;
  csize numClauses = num_clauses();
  for (csize i = 0; i < numClauses; ++i)
  {
    const flwor_clause* c = theClauses[i];

    if (c->get_kind() == flwor_clause::for_clause ||
        c->get_kind() == flwor_clause::let_clause)
    {
      ++num;
    }
  }

  return num;
}


/*******************************************************************************

********************************************************************************/
long flwor_expr::defines_variable(const var_expr* v) const
{
  const flwor_clause* varClause = v->get_flwor_clause();

  if (varClause == NULL)
    return -1;

  csize numClauses = theClauses.size();

  for (csize i = 0; i < numClauses; ++i)
  {
    if (theClauses[i] == varClause)
      return i;
  }

  return -1;
}


/*******************************************************************************
  Put in the given vector the var_exprs for the variables defined by this flwor
  expr.
********************************************************************************/
void flwor_expr::get_vars_defined(std::vector<var_expr*>& varExprs) const
{
  csize numClauses = theClauses.size();

  for (csize i = 0; i < numClauses; ++i)
  {
    const flwor_clause* c = theClauses[i];

    if (c->get_kind() == flwor_clause::for_clause)
    {
      const for_clause* fc = static_cast<const for_clause *>(c);

      varExprs.push_back(fc->get_var());

      if (fc->get_pos_var())
        varExprs.push_back(fc->get_pos_var());
    }
    else if (c->get_kind() == flwor_clause::let_clause)
    {
      const let_clause* lc = static_cast<const let_clause *>(c);

      varExprs.push_back(lc->get_var());
    }
    else if (c->get_kind() == flwor_clause::window_clause)
    {
      const window_clause* wc = static_cast<const window_clause *>(c);

      varExprs.push_back(wc->get_var());

      const flwor_wincond* startCond = wc->get_win_start();
      const flwor_wincond* stopCond = wc->get_win_stop();
      const flwor_wincond::vars& startVars = startCond->get_out_vars();
      const flwor_wincond::vars& stopVars = stopCond->get_out_vars();

      if (startVars.posvar) varExprs.push_back(startVars.posvar);
      if (startVars.curr) varExprs.push_back(startVars.curr);
      if (startVars.prev) varExprs.push_back(startVars.prev);
      if (startVars.next) varExprs.push_back(startVars.next);

      if (stopVars.posvar) varExprs.push_back(stopVars.posvar);
      if (stopVars.curr) varExprs.push_back(stopVars.curr);
      if (stopVars.prev) varExprs.push_back(stopVars.prev);
      if (stopVars.next) varExprs.push_back(stopVars.next);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::compute_scripting_kind()
{
  ulong numClauses = num_clauses();

  for (ulong i = 0; i < numClauses; ++i)
  {
    const flwor_clause* c = theClauses[i];
    flwor_clause::ClauseKind k = c->get_kind();

    if (k == flwor_clause::for_clause ||
        k == flwor_clause::let_clause ||
        k == flwor_clause::window_clause)
    {
      const forletwin_clause* c2 = static_cast<const forletwin_clause*>(c);

      theScriptingKind |= c2->get_expr()->get_scripting_detail();

      if (c2->get_expr()->is_sequential())
        theHasSequentialClauses = true;
    }
  }

  const expr* ret = get_return_expr();
  if (ret)
    theScriptingKind |= ret->get_scripting_detail();

  if (is_sequential(theScriptingKind))
  {
    theScriptingKind &= ~SIMPLE_EXPR;
    theScriptingKind &= ~VACUOUS_EXPR;
  }

  if (theScriptingKind & UPDATING_EXPR)
  {
    theScriptingKind &= ~SIMPLE_EXPR;
    theScriptingKind &= ~VACUOUS_EXPR;
  }

  if (theScriptingKind & VACUOUS_EXPR)
  {
    if (ret && ret->is_vacuous())
      theScriptingKind &= ~SIMPLE_EXPR;
    else
      theScriptingKind &= ~VACUOUS_EXPR;
  }

  checkScriptingKind();
}


/*******************************************************************************

********************************************************************************/
expr* flwor_expr::cloneImpl(substitution_t& subst) const
{
  ulong numClauses = num_clauses();

  flwor_expr* cloneFlwor = theCCB->theEM->create_flwor_expr(theSctx, get_loc(), theIsGeneral);

  for (ulong i = 0; i < numClauses; ++i)
  {
    flwor_clause* cloneClause = theClauses[i]->clone(subst);

    cloneFlwor->add_clause(cloneClause, false);
  }

  cloneFlwor->set_return_expr(theReturnExpr->clone(subst));

  return cloneFlwor;
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
