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

#pragma once
#ifndef ZORBA_COMPILER_FLWOR_EXPR_H
#define ZORBA_COMPILER_FLWOR_EXPR_H

#include "common/shared_types.h"

#include "compiler/expression/expr_base.h"
#include "compiler/expression/var_expr.h"
#include "compiler/expression/expr_utils.h"

namespace zorba
{

class ExprManager;

class order_modifier;
class window_clause;
class flwor_wincond;
class orderby_clause;
class materialize_clause;
class group_clause;
class flwor_expr;

/***************************************************************************//**

********************************************************************************/
class flwor_clause
{
  friend class expr;
  friend class flwor_expr;
  friend class ExprIterator;
  friend class ExprManager;

public:
  typedef var_rebind_list_t rebind_list_t;

  enum ClauseKind
  {
    for_clause,
    let_clause,
    window_clause,
    groupby_clause,
    orderby_clause,
    count_clause,
    where_clause,
    materialize_clause
    // if you change this, also ensure that operator<< for it is still correct
  };

protected:
  static_context          * theContext;
  QueryLoc                  theLocation;

  ClauseKind                theKind;
  flwor_expr              * theFlworExpr;

  CompilerCB        * const theCCB;

protected:
  flwor_clause(
      static_context* sctx,
      CompilerCB* ccb,
      const QueryLoc& loc,
      ClauseKind kind)
    :
    theContext(sctx),
    theLocation(loc),
    theKind(kind),
    theFlworExpr(NULL),
    theCCB(ccb)
  {
  }

public:
  virtual ~flwor_clause();

  const QueryLoc& get_loc() const { return theLocation; }

  ClauseKind get_kind() const { return theKind; }

  void set_kind(ClauseKind k) { theKind = k; }

  flwor_expr* get_flwor_expr() const { return theFlworExpr; }

  virtual void set_expr(expr* v) { }

  virtual var_expr* get_pos_var() const { return NULL; }

  virtual flwor_clause* clone(
      user_function* udf,
      expr::substitution_t& substitution) const = 0;
};

// for debugging
std::ostream& operator<<( std::ostream&, flwor_clause::ClauseKind );

/***************************************************************************//**

  ForClause ::= "outer"? "for" "$" VarName TypeDeclaration? PositionalVar?
                "in" DomainExpr

  LetClause ::= "let" "$" VarName TypeDeclaration? ":=" DomainExpr

  WindowClause ::= "for" (TumblingWindowClause | SlidingWindowClause)

  TumblingWindowClause ::= "tumbling" "window"
                           "$" VarName TypeDeclaration? "in" DomainExpr
                           WindowStartCondition
                           WindowEndCondition?

  SlidingWindowClause ::= "sliding" "window"
                          "$" VarName TypeDeclaration? "in" DomainExpr
                          WindowStartCondition
                          WindowEndCondition

  DomainExpr ::= ExprSingle

  PositionalVar ::= "at" "$" VarName

  TypeDeclaration ::= "as" SequenceType

********************************************************************************/
class forletwin_clause : public flwor_clause
{
  friend class expr;
  friend class flwor_expr;
  friend class ExprManager;
  friend class ExprIterator;

protected:
  var_expr   * theVarExpr;
  expr       * theDomainExpr;

protected:
  forletwin_clause(
        static_context* sctx,
        CompilerCB* ccb,
        const QueryLoc& loc,
        ClauseKind kind,
        var_expr* varExpr,
        expr* domainExpr);

public:
  ~forletwin_clause();

  void set_expr(expr* v);

  expr* get_expr() const { return theDomainExpr; }

  expr** get_expr_ref() { return &theDomainExpr; }

  var_expr* get_var() const { return theVarExpr; }

  void set_var(var_expr* v);
};


/***************************************************************************//**

********************************************************************************/
class forlet_clause : public forletwin_clause
{
  friend class flwor_expr;
  friend class ExprManager;
  friend class ExprIterator;

protected:
  var_expr    * thePosVarExpr;
  var_expr    * theScoreVarExpr;
  bool          theAllowingEmpty;
  bool          theLazyEval;

protected:
  forlet_clause(
        static_context* sctx,
        CompilerCB* ccb,
        const QueryLoc& loc,
        flwor_clause::ClauseKind kind,
        var_expr* varExpr,
        expr* domainExpr,
        var_expr* posVarExpr,
        var_expr* scoreVarExpr,
        bool isOuter,
        bool lazy);

public:
  ~forlet_clause();

  bool is_allowing_empty() const { return theAllowingEmpty; }

  void set_allowing_empty(bool allowing_empty) { theAllowingEmpty = allowing_empty; }

  void setLazyEval(bool v) { theLazyEval = v; }

  bool lazyEval() const { return theLazyEval; }

  var_expr* get_pos_var() const;

  var_expr* get_score_var() const;

  void set_pos_var(var_expr* v);

  void set_score_var(var_expr* v);

  flwor_clause* clone(user_function* udf, expr::substitution_t& substitution) const;

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  theWindowKind   :
  theWinStartCond :
  theWinStopCond  :
  theLazyEval     : Whether the window var can be materilized lazily or not.
********************************************************************************/
class window_clause : public forletwin_clause
{
  friend class expr;
  friend class flwor_expr;
  friend class ExprManager;
  friend class ExprIterator;

protected:
  WindowKind       theWindowKind;
  flwor_wincond  * theWinStartCond;
  flwor_wincond  * theWinStopCond;
  bool             theLazyEval;

protected:
  window_clause(
      static_context* sctx,
      CompilerCB* ccb,
      const QueryLoc& loc,
      WindowKind winKind,
      var_expr* varExpr,
      expr* domainExpr,
      flwor_wincond* winStart,
      flwor_wincond* winStop,
      bool lazy = false);

public:
  ~window_clause();

  WindowKind get_winkind() const { return theWindowKind; }

  flwor_wincond* get_win_start() const { return theWinStartCond; }

  flwor_wincond* get_win_stop() const { return theWinStopCond; }

  void set_win_start(flwor_wincond* cond);

  void set_win_stop(flwor_wincond* cond);

  void setLazyEval(bool v) { theLazyEval = v; }

  bool lazyEval() const { return theLazyEval; }

  flwor_clause* clone(user_function* udf, expr::substitution_t& substitution) const;

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
struct flwor_wincond_vars
{
  var_expr* posvar;
  var_expr* curr;
  var_expr* prev;
  var_expr* next;

  flwor_wincond_vars();

  ~flwor_wincond_vars();

  void set_flwor_clause(flwor_clause* c);

  void clone(
      ExprManager* mgr,
      user_function* udf,
      flwor_wincond_vars& cloneVars,
      expr::substitution_t& subst) const;

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

  Class flwor_wincond represents a start/stop condition of a window clause.

  - Syntax:

  WindowStartCondition ::= "start" WindowVars "when" ExprSingle

  WindowEndCondition ::= "only"? "end" WindowVars "when" ExprSingle

  WindowVars ::= ("$" CurrentItem)?
                 PositionalVar?
                 ("previous" "$" PreviousItem)?
                 ("next" "$" NextItem)?

  - Data Members:

  theIsOnly    : The "only" flag, if this is an end condition
  theInputVars : The var_exprs for the 4 condition vars that iterate over the
                 window domain expr and whose values are used to compute the
                 condition expr during each iteration. These vars are visible
                 only during the evaluation of the condition expr.
  theOutputVars: When the condition expr evaluates to true, the current values
                 of theInputVars are copied to theOutputVars. So, theOutputVars
                 describe the starting/ending point of an established window
                 and they are visible to the rest of the query (i.e., they
                 become columns in the output stream produced by the window
                 clause).
  theCondExpr  : The start/end condition expr.
********************************************************************************/
class flwor_wincond
{
  friend class expr;
  friend class flwor_expr;
  friend class ExprManager;
  friend class ExprIterator;

public:
  typedef flwor_wincond_vars vars;

protected:
  bool         theIsOnly;
  vars         theInputVars;
  vars         theOutputVars;
  expr       * theCondExpr;

  CompilerCB * const theCCB;

protected:
  flwor_wincond(
      CompilerCB* ccb,
      static_context* sctx,
      bool isOnly,
      const vars& in_vars,
      const vars& out_vars,
      expr* cond);

public:
  ~flwor_wincond();

  expr* get_expr() const { return theCondExpr; }

  void set_expr(expr* cond) { theCondExpr = cond; }

  bool is_only() const { return theIsOnly; }

  const vars& get_in_vars() const { return theInputVars; }

  const vars& get_out_vars() const { return theOutputVars; }

  void set_flwor_clause(flwor_clause *);

  flwor_wincond* clone(user_function* udf, expr::substitution_t& substitution) const;

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  - Syntax:

  GroupByClause ::= "group" "by" GroupingSpecList

  GroupSpecList ::= GroupingSpec ("," GroupingSpec)*

  GroupSpec ::= "$" VarName (TypeDeclaration? ":=" ExprSingle)?
                ("collation" URILiteral)?

  - Data Members:

  theGroupVars:
  -------------
  For each grouping var X, theGroupVars contains a pair of exprs: the 1st
  element of the pair is the expr that computes the grouping keys for X;
  the 2nd element is a var_expr representing the variable gX that the groupby
  produces for X in its output tuple stream.

  theNonGroupVars:
  ----------------
  For each non-grouping var Y, theNonGroupVars contains a pair of exprs: the
  1st element of the pair is a reference to Y in the groupby's input tuple
  stream, and the 2nd element is a var_expr representing the variable gY that
  the groupby produces for Y in its output tuple stream. For each tuple T
  produced by the groupby, gY is the concatenation of all the Y values in the
  input tuples that were grouped into T.

  theCollations:
  --------------
  The collations to use when comparing values for grouping.
********************************************************************************/
class groupby_clause : public flwor_clause
{
  friend class expr;
  friend class flwor_expr;
  friend class ExprManager;
  friend class ExprIterator;

protected:
  rebind_list_t            theGroupVars;
  rebind_list_t            theNonGroupVars;
  std::vector<std::string> theCollations;

  groupby_clause(
      static_context* sctx,
      CompilerCB* ccb,
      const QueryLoc& loc,
      const rebind_list_t& gvars,
      const rebind_list_t& ngvars,
      const std::vector<std::string>& collations);

public:
  ~groupby_clause();

  const std::vector<std::string>& get_collations() const { return theCollations; }

  csize numGroupingVars() const { return theGroupVars.size(); }

  csize numNonGroupingVars() const { return theNonGroupVars.size(); }

  const rebind_list_t& get_grouping_vars() const { return theGroupVars; }

  const rebind_list_t& get_nongrouping_vars() const { return theNonGroupVars; }

  void set_grouping_vars(rebind_list_t& v) { theGroupVars = v; }

  void set_nongrouping_ars(rebind_list_t& v) { theNonGroupVars = v; }

  rebind_list_t::iterator removeNonGroupingVar(rebind_list_t::iterator& ite)
  {
    return theNonGroupVars.erase(ite);
  }

  rebind_list_t::iterator beginGroupVars() { return theGroupVars.begin(); }

  rebind_list_t::const_iterator beginGroupVars() const { return theGroupVars.begin(); }

  rebind_list_t::iterator endGroupVars() { return theGroupVars.end(); }

  rebind_list_t::const_iterator endGroupVars() const { return theGroupVars.end(); }

  rebind_list_t::iterator beginNonGroupVars() { return theNonGroupVars.begin(); }

  rebind_list_t::const_iterator beginNonGroupVars() const { return theNonGroupVars.begin(); }

  rebind_list_t::iterator endNonGroupVars() { return theNonGroupVars.end(); }

  rebind_list_t::const_iterator endNonGroupVars() const { return theNonGroupVars.end(); }

  expr* get_input_for_group_var(const var_expr* var);

  expr* get_input_for_nongroup_var(const var_expr* var);

  expr** get_gexpr_ref(csize i) { return &(theGroupVars[i].first); }

  expr** get_ngexpr_ref(csize i) { return &(theNonGroupVars[i].first); }

  flwor_clause* clone(user_function* udf, expr::substitution_t& substitution) const;

  std::ostream& put(std::ostream&) const;
};



/***************************************************************************//**

  OrderByClause ::= (("order" "by") | ("stable" "order" "by")) OrderSpecList

  OrderSpecList ::= OrderSpec ("," OrderSpec)*

  OrderSpec ::= ExprSingle OrderModifier

  OrderModifier ::= ("ascending" | "descending")?
                    ("empty" ("greatest" | "least"))?
                    ("collation" URILiteral)?

********************************************************************************/
class orderby_clause : public flwor_clause
{
  friend class expr;
  friend class ExprIterator;
  friend class ExprManager;
  friend class flwor_expr;

protected:

  bool                        theStableOrder;
  std::vector<OrderModifier>  theModifiers;
  std::vector<expr*>          theOrderingExprs;

protected:
  orderby_clause(
      static_context* sctx,
      CompilerCB* ccb,
      const QueryLoc& loc,
      bool stable,
      const std::vector<OrderModifier>& modifiers,
      const std::vector<expr*>& orderingExprs);

public:
  bool is_stable() const { return theStableOrder; }

  const std::vector<OrderModifier>& get_modifiers() const { return theModifiers; }

  bool is_ascending(csize i) const { return theModifiers[i].theAscending; }

  const std::string& get_collation(csize i) const { return theModifiers[i].theCollation; }

  const std::vector<expr*>& get_column_exprs() const { return theOrderingExprs; }

  std::vector<expr*>::iterator begin() { return theOrderingExprs.begin(); }

  std::vector<expr*>::iterator end() { return theOrderingExprs.end(); }

  std::vector<expr*>::const_iterator begin() const
  {
    return theOrderingExprs.begin();
  }

  std::vector<expr*>::const_iterator end() const
  {
    return theOrderingExprs.end();
  }

  csize num_columns() const { return theOrderingExprs.size(); }

  expr* get_column_expr(csize i) const { return theOrderingExprs[i]; }

  expr** get_expr_ref(csize i) { return &theOrderingExprs[i]; }

  void set_column_expr(csize i, expr* e) { theOrderingExprs[i] = e; }

  flwor_clause* clone(user_function* udf, expr::substitution_t& substitution) const;

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  Used to meterialize the tuple stream at the location where the clause
  appears at. It is needed to implement sequential flwor exprs. Materialize
  clauses are created and inserted in the flwor expr during codegen.
********************************************************************************/
class materialize_clause : public flwor_clause
{
  friend class ExprIterator;
  friend class ExprManager;
  friend class flwor_expr;

  materialize_clause(static_context* sctx, CompilerCB* ccb, const QueryLoc& loc);

public:
  flwor_clause* clone(user_function* udf, expr::substitution_t& substitution) const;

  std::ostream& put(std::ostream&) const;
};



/***************************************************************************//**
  CountClause ::= "count" "$" VarName
********************************************************************************/
class count_clause : public flwor_clause
{
  friend class ExprIterator;
  friend class ExprManager;

protected:
  var_expr * theVarExpr;

  count_clause(static_context* sctx, CompilerCB* ccb, const QueryLoc& loc, var_expr* var);

public:
  ~count_clause();

  var_expr* get_var() const { return theVarExpr; }

  flwor_clause* clone(user_function* udf, expr::substitution_t& substitution) const;
};


/***************************************************************************//**
   WhereClause ::= ExprSingle
********************************************************************************/
class where_clause : public flwor_clause
{
  friend class ExprIterator;
  friend class ExprManager;
  friend class flwor_expr;

  expr * theWhereExpr;

  where_clause(static_context* sctx, CompilerCB* ccb, const QueryLoc& loc, expr* where);

public:
  expr* get_expr() const { return theWhereExpr; }

  expr** get_expr_ref() { return &theWhereExpr; }

  void set_expr(expr* where);

  flwor_clause* clone(user_function* udf, expr::substitution_t& substitution) const;
};


/***************************************************************************//**

  - For the Generalized FLWOR:

  FLWORExpr ::= InitialClause IntermediateClause* ReturnClause

  InitialClause ::= ForClause | LetClause | WindowClause

  IntermediateClause ::= InitialClause |
                         WhereClause |
                         GroupByClause |
                         OrderByClause |
                         CountClause

  - For the traditional FLWOR:

  FLWORExpr ::= InitialClause FLWORClauseList? ReturnClause

  InitialClause ::= ForClause | LetClause

  FLWORClauseList ::= (ForClause | LetClause)*
                      WhereCluase?
                      GroupByClause?
                      OrderByClause?

********************************************************************************/
class flwor_expr : public expr
{
  friend class ExprIterator;
  friend class expr;
  friend class ExprManager;

public:
  typedef std::vector<flwor_clause*> clause_list_t;

protected:
  enum FlworFlags
  {
    HAS_SEQUENTIAL_CLAUSES = 0x1,
    IS_GENERAL             = 0x2
  };

protected:
  clause_list_t   theClauses;
  expr          * theReturnExpr;
  ulong           theFlworFlags;

protected:
  flwor_expr(
      CompilerCB* ccb,
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc);

public:
  void compute_scripting_kind();

  bool has_sequential_clauses() const { return theFlworFlags & HAS_SEQUENTIAL_CLAUSES; }

  void set_sequential_clauses(bool v);

  bool is_general() const { return !!(theFlworFlags & IS_GENERAL); }

  void set_general(bool v);

  bool compute_is_general();

  expr* get_return_expr() const { return theReturnExpr; }

  expr** get_return_expr_ref() { return &theReturnExpr; }

  void set_return_expr(expr* e)
  {
    theReturnExpr = e;
    compute_scripting_kind();
  }

  csize num_clauses() const { return theClauses.size(); }

  void add_clause(flwor_clause* c, bool computeScriptingKind = true);

  void add_clause(csize pos, flwor_clause* c);

  void add_where(expr* e);

  void remove_clause(csize pos);

  void remove_clause(flwor_clause* c, csize posHint);

  flwor_clause* get_clause(csize i) const;

  clause_list_t::const_iterator clause_begin() const { return theClauses.begin(); }

  clause_list_t::const_iterator clause_end() const { return theClauses.end(); }

  bool defines_var(const var_expr* v) const;

  bool get_var_pos(const var_expr* v, csize& pos) const;

  void get_vars(std::vector<var_expr*>& vars) const;

  bool is_single_for(csize& pos) const;

  // The following 2 methods are for the simple flwor only. They should be
  // removed eventually.
  groupby_clause* get_group_clause() const;
  orderby_clause* get_order_clause() const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};



}  // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
