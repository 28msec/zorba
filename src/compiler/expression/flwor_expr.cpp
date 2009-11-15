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
}


/*******************************************************************************

********************************************************************************/
forletwin_clause::forletwin_clause(
    short sctx,
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


/*******************************************************************************

********************************************************************************/
for_clause::for_clause(
    short sctx,
    const QueryLoc& loc,
    varref_t varExpr,
    expr_t domainExpr,
    varref_t posVarExpr,
    varref_t scoreVarExpr,
    bool isOuter)
  :
  forletwin_clause(sctx, loc, flwor_clause::for_clause, varExpr, domainExpr),
  thePosVarExpr(posVarExpr),
  theScoreVarExpr(scoreVarExpr),
  theIsOuter(isOuter)
{
  if (thePosVarExpr != NULL)
    thePosVarExpr->set_flwor_clause(this);

  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(this);
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
  ar & theIsOuter;
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
                        theIsOuter);
}


/*******************************************************************************

********************************************************************************/
let_clause::let_clause(
    short sctx,
    const QueryLoc& loc,
    varref_t varExpr,
    expr_t domainExpr,
    varref_t scoreVarExpr)
  :
  forletwin_clause(sctx, loc, flwor_clause::let_clause, varExpr, domainExpr),
  theScoreVarExpr(scoreVarExpr)
{
  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(this);
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
}


flwor_clause_t let_clause::clone(expr::substitution_t& subst) const
{
  expr_t domainCopy = theDomainExpr->clone(subst);

  varref_t varCopy(new var_expr(*theVarExpr));
  subst[theVarExpr.getp()] = varCopy.getp();

  varref_t scorevarCopy;
  var_expr* score_var_ptr = theScoreVarExpr.getp();
  if (score_var_ptr) 
  {
    scorevarCopy = new var_expr(*score_var_ptr);
    subst[score_var_ptr] = scorevarCopy.getp();
  }

  return new let_clause(theContext, get_loc(), varCopy, domainCopy, scorevarCopy);
}



/*******************************************************************************

********************************************************************************/
window_clause::window_clause(
    short sctx,
    const QueryLoc& loc,
    window_t winKind,
    varref_t varExpr,
    expr_t domainExpr,
    flwor_wincond_t winStart,
    flwor_wincond_t winStop)
  :
  forletwin_clause(sctx, loc, flwor_clause::window_clause, varExpr, domainExpr),
  theWindowKind(winKind),
  theWinStartCond(winStart),
  theWinStopCond(winStop)
{
  if (theWinStartCond != NULL)
    theWinStartCond->set_flwor_clause(this);

  if (theWinStopCond != NULL)
    theWinStopCond->set_flwor_clause(this);
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
                           cloneStopCond);
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
    xqtref_t condType = theCondExpr->return_type(sctx);

    if(!TypeOps::is_equal(*condType, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
    {
      theCondExpr = new fo_expr(theCondExpr->get_sctx_id(),
                                theCondExpr->get_loc(),
                                GET_BUILTIN_FUNCTION(FN_BOOLEAN_1),
                                theCondExpr);
    }
  }
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
  if (posvar != NULL) {
    varref_t varCopy(new var_expr(*posvar));
    subst[posvar.getp()] = varCopy.getp();
    cloneVars.posvar = varCopy;
  }
 
  if (curr != NULL) {
    varref_t varCopy(new var_expr(*curr));
    subst[curr.getp()] = varCopy.getp();
    cloneVars.curr = varCopy;
  }

  if (prev != NULL) {
    varref_t varCopy(new var_expr(*prev));
    subst[prev.getp()] = varCopy.getp();
    cloneVars.prev = varCopy;
  }

  if (next != NULL) {
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
     short sctx,
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
  ulong numGVars = theGroupVars.size();
  ulong numNGVars = theNonGroupVars.size();
  
  for (ulong i = 0; i < numGVars; ++i)
    theGroupVars[i].second->set_flwor_clause(this);

  for (ulong i = 0; i < numNGVars; ++i)
    theNonGroupVars[i].second->set_flwor_clause(this);
}


group_clause::~group_clause() 
{
  ulong numGVars = theGroupVars.size();
  ulong numNGVars = theNonGroupVars.size();
  
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
  ulong numVars = theGroupVars.size();
  for (ulong i = 0; i < numVars; ++i)
  {
    if (theGroupVars[i].second.getp() == var)
      return theGroupVars[i].first.getp();
  }

  return NULL;
}


expr* group_clause::get_input_for_nongroup_var(const var_expr* var)
{
  ulong numVars = theNonGroupVars.size();
  for (ulong i = 0; i < numVars; ++i)
  {
    if (theNonGroupVars[i].second.getp() == var)
      return theNonGroupVars[i].first.getp();
  }

  return NULL;
}


flwor_clause_t group_clause::clone(expr::substitution_t& subst) const
{
  ulong numGroupVars = theGroupVars.size();
  ulong numNonGroupVars = theNonGroupVars.size();

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


flwor_clause_t where_clause::clone(expr::substitution_t& subst) const
{
  expr_t cloneExpr = theWhereExpr->clone(subst);

  return new where_clause(theContext, get_loc(), cloneExpr);
}


/*******************************************************************************

********************************************************************************/
class flwor_expr_iterator_data : public expr_iterator_data 
{
public:
  flwor_expr::clause_list_t::iterator    theClausesIter;
  flwor_expr::clause_list_t::iterator    theClausesEnd;
  std::vector<expr_t>::iterator          theOrderExprsIter;
  std::vector<expr_t>::iterator          theOrderExprsEnd;
  flwor_clause::rebind_list_t::iterator  theGroupVarsIter;
  flwor_clause::rebind_list_t::iterator  theGroupVarsEnd;
  flwor_clause::rebind_list_t::iterator  theNonGroupVarsIter;
  flwor_clause::rebind_list_t::iterator  theNonGroupVarsEnd;
  int                                    theWincondIter;

public:
  flwor_expr_iterator_data(expr* e) : expr_iterator_data(e), theWincondIter(0) {}
};



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
expr* flwor_expr::get_return_expr(bool invalidate) 
{
  if (invalidate) this->invalidate();
  return theReturnExpr.getp();
}


/*******************************************************************************

********************************************************************************/
flwor_clause* flwor_expr::get_clause(ulong i, bool invalidate)
{
  if (invalidate) this->invalidate();
  return theClauses[i].getp();
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::remove_clause(ulong pos) 
{
  theClauses.erase(theClauses.begin() + pos);
  invalidate();
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::add_clause(flwor_clause* c) 
{
  theClauses.push_back(c);
  invalidate();
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::add_clause(ulong pos, flwor_clause* c) 
{
  theClauses.insert(theClauses.begin() + pos, c);
  invalidate();
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::add_where(expr_t e) 
{
  where_clause* whereClause = new where_clause(theSctxId, e->get_loc(), e);

  theClauses.push_back(whereClause);

  invalidate();
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
    wc->set_where(e);
    return;
  }

  where_clause* wc = new where_clause(theSctxId, e->get_loc(), e);
  theClauses.insert(theClauses.begin() + i, wc);

  invalidate();
}


/*******************************************************************************
  For simple flwor only.
********************************************************************************/
void flwor_expr::remove_where_clause() 
{
  unsigned numClauses = num_clauses();
  for (unsigned i = 0; i < numClauses; ++i)
  {
    if (theClauses[i]->get_kind() == flwor_clause::where_clause)
    {
      theClauses.erase(theClauses.begin() + i);
      return;
    }
  }

  invalidate();
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
      return reinterpret_cast<where_clause*>(theClauses[i].getp())->get_where();
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
long flwor_expr::defines_variable(const var_expr* v, const flwor_clause* limit) const
{
  ulong numClauses = theClauses.size();

  for (ulong i = 0; i < numClauses; ++i)
  {
    const flwor_clause* c = theClauses[i];

    if (v->get_flwor_clause() == limit)
      break;

    if (c->get_kind() == flwor_clause::for_clause)
    {
      const for_clause* fc = static_cast<const for_clause *>(c);

      if (fc->get_var() == v || fc->get_pos_var() == v)
        return i;
    }
    else if (c->get_kind() == flwor_clause::let_clause)
    {
      const let_clause* lc = static_cast<const let_clause *>(c);

      if (lc->get_var() == v)
        return i;
    }
    else if (c->get_kind() == flwor_clause::window_clause)
    {
      const window_clause* wc = static_cast<const window_clause *>(c);

      if (wc->get_var() == v)
        return i;

      const flwor_wincond* startCond = wc->get_win_start();
      const flwor_wincond* stopCond = wc->get_win_stop();
      const flwor_wincond::vars& startVars = startCond->get_out_vars();
      const flwor_wincond::vars& stopVars = stopCond->get_out_vars();

      if (startVars.posvar.getp() == v) return i;
      if (startVars.curr.getp() == v) return i;
      if (startVars.prev.getp() == v) return i;
      if (startVars.next.getp() == v) return i;

      if (stopVars.posvar.getp() == v) return i;
      if (stopVars.curr.getp() == v) return i;
      if (stopVars.prev.getp() == v) return i;
      if (stopVars.next.getp() == v) return i;
    }
    else if (c->get_kind() == flwor_clause::group_clause) 
    {
      const group_clause* gc = static_cast<const group_clause *>(c);

      const flwor_clause::rebind_list_t& gvars = gc->get_grouping_vars();
      ulong numGroupVars = gvars.size();

      for (ulong k = 0; k < numGroupVars; ++k) {
        if (gvars[k].second.getp() == v)
          return i;
      }

      const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
      ulong numNonGroupVars = ngvars.size();

      for (ulong k = 0; k < numNonGroupVars; ++k) {
        if (ngvars[k].second.getp() == v)
          return i;
      }
    }
  }

  return -1;
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::get_vars_defined(std::vector<var_expr*>& varExprs) const
{
  // put in the given the var_exprs for the variables defined by this flwor expr

  ulong numClauses = theClauses.size();

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
xqtref_t flwor_expr::return_type_impl(static_context* sctx) const
{
  // TODO: quant multiplication
  return sctx->get_typemanager()->create_type(*theReturnExpr->return_type(sctx),
                                              TypeConstants::QUANT_STAR);
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::compute_scripting_kind() const 
{
  const expr* ret = get_return_expr();
  theCache.scripting_kind.kind = ret->get_scripting_kind();
  theCache.scripting_kind.valid = true;
}


/*******************************************************************************

********************************************************************************/
expr_t flwor_expr::clone(substitution_t& subst) const
{
  ulong numClauses = num_clauses();

  flwor_expr_t cloneFlwor = new flwor_expr(theSctxId, get_loc(), theIsGeneral);

  for (ulong i = 0; i < numClauses; ++i) {
    flwor_clause_t cloneClause = theClauses[i]->clone(subst);

    cloneFlwor->add_clause(cloneClause.getp());
  }

  cloneFlwor->set_return_expr(theReturnExpr->clone(subst));

  return cloneFlwor.getp();
}


/*******************************************************************************

********************************************************************************/
expr_iterator_data* flwor_expr::make_iter() 
{
  return new flwor_expr_iterator_data(this);
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::next_iter(expr_iterator_data& v) 
{
  flwor_clause* c = NULL;
  window_clause* wc = NULL;
  flwor_wincond* wincond = NULL;
  orderby_clause* oc = NULL;
  group_clause* gc = NULL;

  flwor_expr_iterator_data& iter = dynamic_cast<flwor_expr_iterator_data &>(v);

  BEGIN_EXPR_ITER();

  iter.theClausesIter = theClauses.begin();
  iter.theClausesEnd = theClauses.end();

  for (; iter.theClausesIter != iter.theClausesEnd; ++(iter.theClausesIter))
  {
    c = (iter.theClausesIter)->getp();

    if (c->get_kind() == flwor_clause::for_clause) 
    {
      ITER(static_cast<for_clause *>(c)->theDomainExpr);
    }

    else if (c->get_kind() == flwor_clause::let_clause) 
    {
      ITER(static_cast<let_clause *>(c)->theDomainExpr);
    }

    else if (c->get_kind() == flwor_clause::window_clause) 
    {
      for (iter.theWincondIter = 0; iter.theWincondIter < 2; iter.theWincondIter++) 
      {
        wc = static_cast<window_clause *>((iter.theClausesIter)->getp());

        wincond = (iter.theWincondIter == 0 ?
                   wc->theWinStartCond.getp() :
                   wc->theWinStopCond.getp());

        if (wincond != 0)
          ITER(wincond->theCondExpr);
      }

      wc = static_cast<window_clause *>((iter.theClausesIter)->getp());

      ITER(wc->theDomainExpr);
    }

    else if (c->get_kind() == flwor_clause::where_clause) 
    {
      ITER(static_cast<where_clause *>(c)->theWhereExpr);
    }

    else if (c->get_kind() == flwor_clause::group_clause) 
    {
      gc = static_cast<group_clause *>(c);

      iter.theGroupVarsIter = gc->theGroupVars.begin();
      iter.theGroupVarsEnd = gc->theGroupVars.end();
      iter.theNonGroupVarsIter = gc->theNonGroupVars.begin();
      iter.theNonGroupVarsEnd = gc->theNonGroupVars.end();

      for (; iter.theGroupVarsIter != iter.theGroupVarsEnd; ++iter.theGroupVarsIter)
      {
        ITER((*iter.theGroupVarsIter).first);
      }

      for (;
           iter.theNonGroupVarsIter != iter.theNonGroupVarsEnd;
           ++iter.theNonGroupVarsIter)
      {
        ITER((*iter.theNonGroupVarsIter).first);
      }
    }

    else if (c->get_kind() == flwor_clause::order_clause) {
      oc = static_cast<orderby_clause *>(c);

      iter.theOrderExprsIter = oc->theOrderingExprs.begin();
      iter.theOrderExprsEnd = oc->theOrderingExprs.end();

      for (; iter.theOrderExprsIter != iter.theOrderExprsEnd; ++iter.theOrderExprsIter)
      {
        ITER(*iter.theOrderExprsIter);
      }
    }
  }

  ITER(theReturnExpr);
  
  END_EXPR_ITER(); 
}



}
