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

#include "zorbaerrors/Assert.h"

#include "system/globalenv.h"

#include "types/root_typemanager.h"
#include "types/typeops.h"

#include "context/static_context.h"

#include "functions/library.h"

#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/expr_visitor.h"

#include "zorbaserialization/serialization_engine.h"

namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(flwor_clause)
END_SERIALIZABLE_CLASS_VERSIONS(flwor_clause)

SERIALIZABLE_CLASS_VERSIONS(forletwin_clause)
END_SERIALIZABLE_CLASS_VERSIONS(forletwin_clause)

SERIALIZABLE_CLASS_VERSIONS(for_clause)
END_SERIALIZABLE_CLASS_VERSIONS(for_clause)

SERIALIZABLE_CLASS_VERSIONS(let_clause)
END_SERIALIZABLE_CLASS_VERSIONS(let_clause)

SERIALIZABLE_CLASS_VERSIONS(window_clause)
END_SERIALIZABLE_CLASS_VERSIONS(window_clause)

SERIALIZABLE_CLASS_VERSIONS(group_clause)
END_SERIALIZABLE_CLASS_VERSIONS(group_clause)

SERIALIZABLE_CLASS_VERSIONS(orderby_clause)
END_SERIALIZABLE_CLASS_VERSIONS(orderby_clause)

SERIALIZABLE_CLASS_VERSIONS(count_clause)
END_SERIALIZABLE_CLASS_VERSIONS(count_clause)

SERIALIZABLE_CLASS_VERSIONS(where_clause)
END_SERIALIZABLE_CLASS_VERSIONS(where_clause)

SERIALIZABLE_CLASS_VERSIONS(flwor_expr)
END_SERIALIZABLE_CLASS_VERSIONS(flwor_expr)


DEF_EXPR_ACCEPT (flwor_expr)


/*******************************************************************************

********************************************************************************/
void flwor_clause::serialize(::zorba::serialization::Archiver& ar)
{
  //serialize_baseclass(ar, (SimpleRCObject*)this);
  ar & theContext;
  ar & theLocation;
  SERIALIZE_ENUM(ClauseKind, theKind);
  ar & theFlworExpr;
}


/*******************************************************************************

********************************************************************************/
forletwin_clause::forletwin_clause(
    static_context* sctx,
    const QueryLoc& loc,
    flwor_clause::ClauseKind kind,
    varref_t varExpr,
    expr_t domainExpr)
  :
  flwor_clause(sctx, loc, kind),
  theVarExpr(varExpr),
  theDomainExpr(domainExpr)
{
  if (theVarExpr != NULL)
    theVarExpr->set_flwor_clause(this);
}


forletwin_clause::~forletwin_clause()
{
  if (theVarExpr != NULL)
    theVarExpr->set_flwor_clause(NULL);
}


void forletwin_clause::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (flwor_clause*)this);
  ar & theVarExpr;
  ar & theDomainExpr;
}


void forletwin_clause::set_expr(expr_t v)
{
  theDomainExpr = v;
}


void forletwin_clause::set_var(var_expr_t v)
{
  theVarExpr = v;
  if (theVarExpr != NULL)
    theVarExpr->set_flwor_clause(this);
}


/*******************************************************************************

********************************************************************************/
for_clause::for_clause(
    static_context* sctx,
    const QueryLoc& loc,
    var_expr_t varExpr,
    expr_t domainExpr,
    varref_t posVarExpr,
    varref_t scoreVarExpr,
    bool isAllowingEmpty)
  :
  forletwin_clause(sctx, loc, flwor_clause::for_clause, varExpr, domainExpr),
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
    TypeManager* tm = sctx->get_typemanager();

    xqtref_t declaredType = varExpr->get_type();
    if (declaredType != NULL)
    {
      if (TypeOps::is_empty(tm, *declaredType))
        ZORBA_ERROR_LOC_PARAM(XPTY0004, loc, "empty-sequence()", "");

      xqtref_t domainType = domainExpr->get_return_type();

      if (!TypeOps::is_subtype(tm, *GENV_TYPESYSTEM.ITEM_TYPE_STAR, *declaredType))
      {
        declaredType = tm->create_type(*declaredType, TypeConstants::QUANT_STAR);

        if (!TypeOps::is_subtype(tm, *domainType, *declaredType))
        {
          xqtref_t varType = TypeOps::intersect_type(*domainType, *declaredType, tm);
          if (TypeOps::is_equal(tm, *varType, *GENV_TYPESYSTEM.NONE_TYPE))
          {
            ZORBA_ERROR_LOC_DESC_OSS(XPTY0004, get_loc(),
                                     "Cannot treat " << domainType->toString()
                                     <<" as " << declaredType->toString());
          }

          domainExpr = new treat_expr(sctx, loc, domainExpr, declaredType, XPTY0004);

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


void for_clause::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (forletwin_clause*)this);
  ar & thePosVarExpr;
  ar & theScoreVarExpr;
  ar & theAllowingEmpty;
}


var_expr* for_clause::get_pos_var() const
{
  return thePosVarExpr.getp();
}


var_expr* for_clause::get_score_var() const
{
  return theScoreVarExpr.getp();
}


void for_clause::set_pos_var(var_expr_t v)
{
  thePosVarExpr = v;
  if (thePosVarExpr != NULL)
    thePosVarExpr->set_flwor_clause(this);
}


void for_clause::set_score_var(var_expr_t v)
{
  theScoreVarExpr = v;
  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(this);
}


flwor_clause_t for_clause::clone(expr::substitution_t& subst) const
{
  expr_t domainCopy = theDomainExpr->clone(subst);

  varref_t varCopy(new var_expr(*theVarExpr));
  subst[theVarExpr.getp()] = varCopy.getp();

  varref_t posvarCopy;
  var_expr* pos_var_ptr = thePosVarExpr.getp();
  if (pos_var_ptr)
  {
    posvarCopy = new var_expr(*pos_var_ptr);
    subst[pos_var_ptr] = posvarCopy.getp();
  }

  varref_t scorevarCopy;
  var_expr* score_var_ptr = theScoreVarExpr.getp();
  if (score_var_ptr)
  {
    scorevarCopy = new var_expr(*score_var_ptr);
    subst[score_var_ptr] = scorevarCopy.getp();
  }

  return new for_clause(theContext,
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
    const QueryLoc& loc,
    varref_t varExpr,
    expr_t domainExpr,
    bool lazy)
  :
  forletwin_clause(sctx, loc, flwor_clause::let_clause, varExpr, domainExpr),
  theScoreVarExpr(NULL),
  theLazyEval(lazy)
{
  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(this);

  if (varExpr != NULL && sctx != NULL)
  {
    TypeManager* tm = sctx->get_typemanager();

    xqtref_t declaredType = varExpr->get_type();
    if (declaredType != NULL)
    {
      xqtref_t domainType = domainExpr->get_return_type();

      if (!TypeOps::is_subtype(tm, *GENV_TYPESYSTEM.ITEM_TYPE_STAR, *declaredType) &&
          !TypeOps::is_subtype(tm, *domainType, *declaredType))
      {
        xqtref_t varType = TypeOps::intersect_type(*domainType, *declaredType, tm);
        if (TypeOps::is_equal(tm, *varType, *GENV_TYPESYSTEM.NONE_TYPE))
        {
          ZORBA_ERROR_LOC_DESC_OSS(XPTY0004, get_loc(),
                                   "Cannot treat " << domainType->toString()
                                   <<" as " << declaredType->toString());
        }

        domainExpr = new treat_expr(sctx, loc, domainExpr, declaredType, XPTY0004);

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


void let_clause::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (forletwin_clause*)this);
  ar & theScoreVarExpr;
  ar & theLazyEval;
}


var_expr* let_clause::get_score_var() const
{
  return theScoreVarExpr.getp();
}


void let_clause::set_score_var(var_expr_t v)
{
  theScoreVarExpr = v;
  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(this);
}


flwor_clause_t let_clause::clone(expr::substitution_t& subst) const
{
  expr_t domainCopy = theDomainExpr->clone(subst);

  varref_t varCopy(new var_expr(*theVarExpr));
  subst[theVarExpr.getp()] = varCopy.getp();

#if 0
  varref_t scorevarCopy;
  var_expr* score_var_ptr = theScoreVarExpr.getp();
  if (score_var_ptr)
  {
    scorevarCopy = new var_expr(*score_var_ptr);
    subst->get(score_var_ptr) = scorevarCopy.getp();
  }
#endif

  return new let_clause(theContext, get_loc(), varCopy, domainCopy, theLazyEval);
}



/*******************************************************************************

********************************************************************************/
window_clause::window_clause(
    static_context* sctx,
    const QueryLoc& loc,
    window_t winKind,
    varref_t varExpr,
    expr_t domainExpr,
    flwor_wincond_t winStart,
    flwor_wincond_t winStop,
    bool lazy)
  :
  forletwin_clause(sctx, loc, flwor_clause::window_clause, varExpr, domainExpr),
  theWindowKind(winKind),
  theWinStartCond(winStart),
  theWinStopCond(winStop),
  theLazyEval(lazy)
{
  if (theWinStartCond != NULL)
    theWinStartCond->set_flwor_clause(this);

  if (theWinStopCond != NULL)
    theWinStopCond->set_flwor_clause(this);

  if (varExpr != NULL && sctx != NULL)
  {
    TypeManager* tm = sctx->get_typemanager();

    xqtref_t varType = varExpr->get_type();
    if (varType != NULL)
    {
      xqtref_t domainType = domainExpr->get_return_type();

      if (!TypeOps::is_subtype(tm, *GENV_TYPESYSTEM.ITEM_TYPE_STAR, *varType) &&
          !TypeOps::is_subtype(tm, *domainType, *varType))
      {
        domainExpr = new treat_expr(sctx, loc, domainExpr, varType, XPTY0004);

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


void window_clause::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (forletwin_clause*)this);
  SERIALIZE_ENUM(window_t, theWindowKind);
  ar & theWinStartCond;
  ar & theWinStopCond;
  ar & theLazyEval;
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


flwor_clause_t window_clause::clone(expr::substitution_t& subst) const
{
  expr_t domainCopy = theDomainExpr->clone(subst);

  varref_t varCopy(new var_expr(*theVarExpr));
  subst[theVarExpr.getp()] = varCopy.getp();

  flwor_wincond_t cloneStartCond;
  flwor_wincond_t cloneStopCond;

  if (theWinStartCond != NULL)
    cloneStartCond = theWinStartCond->clone(subst);

  if (theWinStopCond != NULL)
    cloneStopCond = theWinStopCond->clone(subst);

  return new window_clause(theContext,
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
    static_context* sctx,
    bool isOnly,
    const vars& in_vars,
    const vars& out_vars,
    expr_t cond)
  :
  theIsOnly(isOnly),
  theInputVars(in_vars),
  theOutputVars(out_vars),
  theCondExpr(cond)
{
  if (sctx != NULL)
  {
    TypeManager* tm = sctx->get_typemanager();

    xqtref_t condType = theCondExpr->get_return_type();

    if(!TypeOps::is_equal(tm, *condType, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
    {
      theCondExpr = new fo_expr(theCondExpr->get_sctx(),
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
    flwor_wincond::vars& cloneVars,
    expr::substitution_t& subst) const
{
  if (posvar != NULL)
  {
    varref_t varCopy(new var_expr(*posvar));
    subst[posvar.getp()] = varCopy.getp();
    cloneVars.posvar = varCopy;
  }

  if (curr != NULL)
  {
    varref_t varCopy(new var_expr(*curr));
    subst[curr.getp()] = varCopy.getp();
    cloneVars.curr = varCopy;
  }

  if (prev != NULL)
  {
    varref_t varCopy(new var_expr(*prev));
    subst[prev.getp()] = varCopy.getp();
    cloneVars.prev = varCopy;
  }

  if (next != NULL)
  {
    varref_t varCopy(new var_expr(*next));
    subst[next.getp()] = varCopy.getp();
    cloneVars.next = varCopy;
  }
}


void flwor_wincond::set_flwor_clause(flwor_clause* c)
{
  theInputVars.set_flwor_clause(c);
  theOutputVars.set_flwor_clause(c);
}


flwor_wincond_t flwor_wincond::clone(expr::substitution_t& subst) const
{
  flwor_wincond::vars cloneInVars;
  flwor_wincond::vars cloneOutVars;

  theInputVars.clone(cloneInVars, subst);
  theOutputVars.clone(cloneOutVars, subst);

  expr_t cloneCondExpr = theCondExpr->clone(subst);

  return new flwor_wincond(NULL, theIsOnly, cloneInVars, cloneOutVars, cloneCondExpr);
}


/*******************************************************************************

********************************************************************************/
group_clause::group_clause(
     static_context* sctx,
     const QueryLoc& loc,
     const rebind_list_t& gvars,
     rebind_list_t ngvars,
     const std::vector<std::string>& collations)
  :
  flwor_clause(sctx, loc, flwor_clause::group_clause),
  theGroupVars(gvars),
  theNonGroupVars(ngvars),
  theCollations(collations)
{
  ulong numGVars = (ulong)theGroupVars.size();
  ulong numNGVars = (ulong)theNonGroupVars.size();

  for (ulong i = 0; i < numGVars; ++i)
    theGroupVars[i].second->set_flwor_clause(this);

  for (ulong i = 0; i < numNGVars; ++i)
    theNonGroupVars[i].second->set_flwor_clause(this);
}


group_clause::~group_clause()
{
  ulong numGVars = (ulong)theGroupVars.size();
  ulong numNGVars = (ulong)theNonGroupVars.size();

  for (ulong i = 0; i < numGVars; ++i)
    theGroupVars[i].second->set_flwor_clause(NULL);

  for (ulong i = 0; i < numNGVars; ++i)
    theNonGroupVars[i].second->set_flwor_clause(NULL);
}


void group_clause::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (flwor_clause*)this);
  ar & theGroupVars;
  ar & theNonGroupVars;
  ar & theCollations;
}


expr* group_clause::get_input_for_group_var(const var_expr* var)
{
  ulong numVars = (ulong)theGroupVars.size();
  for (ulong i = 0; i < numVars; ++i)
  {
    if (theGroupVars[i].second.getp() == var)
      return theGroupVars[i].first.getp();
  }

  return NULL;
}


expr* group_clause::get_input_for_nongroup_var(const var_expr* var)
{
  ulong numVars = (ulong)theNonGroupVars.size();
  for (ulong i = 0; i < numVars; ++i)
  {
    if (theNonGroupVars[i].second.getp() == var)
      return theNonGroupVars[i].first.getp();
  }

  return NULL;
}


flwor_clause_t group_clause::clone(expr::substitution_t& subst) const
{
  ulong numGroupVars = (ulong)theGroupVars.size();
  ulong numNonGroupVars = (ulong)theNonGroupVars.size();

  rebind_list_t cloneGroupVars(numGroupVars);
  rebind_list_t cloneNonGroupVars(numNonGroupVars);

  for (ulong i = 0; i < numGroupVars; ++i)
  {
    cloneGroupVars[i].first = theGroupVars[i].first->clone(subst);
    cloneGroupVars[i].second = new var_expr(*theGroupVars[i].second);
    subst[theGroupVars[i].second.getp()] = cloneGroupVars[i].second.getp();
  }

  for (ulong i = 0; i < numNonGroupVars; ++i)
  {
    cloneNonGroupVars[i].first = theNonGroupVars[i].first->clone(subst);
    cloneNonGroupVars[i].second = new var_expr(*theNonGroupVars[i].second);
    subst[theNonGroupVars[i].second.getp()] = cloneNonGroupVars[i].second.getp();
  }

  return new group_clause(theContext,
                          get_loc(),
                          cloneGroupVars,
                          cloneNonGroupVars,
                          theCollations);
}


/*******************************************************************************

********************************************************************************/
void orderby_clause::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (flwor_clause*)this);
  ar & theStableOrder;
  ar & theModifiers;
  ar & theOrderingExprs;
}


flwor_clause_t orderby_clause::clone(expr::substitution_t& subst) const
{
  ulong numColumns = num_columns();

  std::vector<expr_t> cloneExprs(numColumns);

  for (ulong i = 0; i < numColumns; ++i)
  {
    cloneExprs[i] = theOrderingExprs[i]->clone(subst);
  }

  return new orderby_clause(theContext,
                            get_loc(),
                            theStableOrder,
                            theModifiers,
                            cloneExprs);
}


/*******************************************************************************

********************************************************************************/
count_clause::~count_clause()
{
  if (theVarExpr != NULL)
    theVarExpr->set_flwor_clause(NULL);
}


void count_clause::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (flwor_clause*)this);
  ar & theVarExpr;
}


flwor_clause_t count_clause::clone(expr::substitution_t& subst) const
{
  varref_t cloneVar = new var_expr(*theVarExpr);
  subst[theVarExpr.getp()] = cloneVar;

  return new count_clause(theContext, get_loc(), cloneVar);
}


/*******************************************************************************

********************************************************************************/
void where_clause::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (flwor_clause*)this);
  ar & theWhereExpr;
}


void where_clause::set_expr(expr_t where)
{
  theWhereExpr = where;
}


flwor_clause_t where_clause::clone(expr::substitution_t& subst) const
{
  expr_t cloneExpr = theWhereExpr->clone(subst);

  return new where_clause(theContext, get_loc(), cloneExpr);
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theIsGeneral;
  ar & theClauses;
  ar & theReturnExpr;
}


/*******************************************************************************

********************************************************************************/
flwor_clause* flwor_expr::get_clause(ulong i)
{
  return theClauses[i].getp();
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::remove_clause(ulong pos)
{
  if (theClauses[pos]->theFlworExpr == this)
    theClauses[pos]->theFlworExpr = NULL;

  theClauses.erase(theClauses.begin() + pos);
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::add_clause(flwor_clause* c)
{
  theClauses.push_back(c);
  c->theFlworExpr = this;
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::add_clause(ulong pos, flwor_clause* c)
{
  theClauses.insert(theClauses.begin() + pos, c);
  c->theFlworExpr = this;
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::add_where(expr_t e)
{
  where_clause* whereClause = new where_clause(theSctx, e->get_loc(), e);

  add_clause(whereClause);
}


/*******************************************************************************
  For simple flwor only. If a where clause exists already, replace its expr
  with the given expr. Otherwise, add a where clause with the given expr.
********************************************************************************/
void flwor_expr::set_where(expr* e)
{
  ZORBA_ASSERT(e != NULL);

  unsigned numClauses = num_clauses();
  unsigned i;

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
    where_clause* wc = reinterpret_cast<where_clause*>(theClauses[i].getp());
    wc->set_expr(e);
    return;
  }

  where_clause* wc = new where_clause(theSctx, e->get_loc(), e);
  theClauses.insert(theClauses.begin() + i, wc);
  wc->theFlworExpr = this;
}


/*******************************************************************************
  For simple flwor only.
********************************************************************************/
void flwor_expr::remove_where_clause()
{
  unsigned numClauses = num_clauses();
  for (ulong i = 0; i < numClauses; ++i)
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
  unsigned numClauses = num_clauses();
  for (unsigned i = 0; i < numClauses; ++i)
  {
    if (theClauses[i]->get_kind() == flwor_clause::where_clause)
      return reinterpret_cast<where_clause*>(theClauses[i].getp())->get_expr();
  }

  return NULL;
}


/*******************************************************************************
  For simple flwor only.
********************************************************************************/
group_clause* flwor_expr::get_group_clause() const
{
  ulong numClauses = num_clauses();
  for (ulong i = 0; i < numClauses; ++i)
  {
    if (theClauses[i]->get_kind() == flwor_clause::group_clause)
      return reinterpret_cast<group_clause*>(theClauses[i].getp());
  }

  return NULL;
}


/*******************************************************************************
  For simple flwor only.
********************************************************************************/
orderby_clause* flwor_expr::get_order_clause() const
{
  ulong numClauses = num_clauses();
  for (ulong i = 0; i < numClauses; ++i)
  {
    if (theClauses[i]->get_kind() == flwor_clause::order_clause)
      return reinterpret_cast<orderby_clause*>(theClauses[i].getp());
  }

  return NULL;
}


/*******************************************************************************
  For simple flwor only.
********************************************************************************/
ulong flwor_expr::num_forlet_clauses()
{
  ulong num = 0;
  ulong numClauses = num_clauses();
  for (ulong i = 0; i < numClauses; ++i)
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

  ulong numClauses = (ulong)theClauses.size();

  for (ulong i = 0; i < numClauses; ++i)
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
  ulong numClauses = (ulong)theClauses.size();

  for (ulong i = 0; i < numClauses; ++i)
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

      if (startVars.posvar) varExprs.push_back(startVars.posvar.getp());
      if (startVars.curr) varExprs.push_back(startVars.curr.getp());
      if (startVars.prev) varExprs.push_back(startVars.prev.getp());
      if (startVars.next) varExprs.push_back(startVars.next.getp());

      if (stopVars.posvar) varExprs.push_back(stopVars.posvar.getp());
      if (stopVars.curr) varExprs.push_back(stopVars.curr.getp());
      if (stopVars.prev) varExprs.push_back(stopVars.prev.getp());
      if (stopVars.next) varExprs.push_back(stopVars.next.getp());
    }
  }
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::compute_scripting_kind()
{
  const expr* ret = get_return_expr();
  if (ret)
    theScriptingKind = ret->get_scripting_kind();
}


/*******************************************************************************

********************************************************************************/
expr_t flwor_expr::clone(substitution_t& subst) const
{
  ulong numClauses = num_clauses();

  flwor_expr_t cloneFlwor = new flwor_expr(theSctx, get_loc(), theIsGeneral);

  for (ulong i = 0; i < numClauses; ++i)
  {
    flwor_clause_t cloneClause = theClauses[i]->clone(subst);

    cloneFlwor->add_clause(cloneClause.getp());
  }

  cloneFlwor->set_return_expr(theReturnExpr->clone(subst));

  return cloneFlwor.getp();
}


}
