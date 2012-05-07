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

class order_modifier;
class flwor_clause;
class for_clause;
class let_clause;
class window_clause;
class flwor_wincond;
class orderby_clause;
class materialize_clause;
class group_clause;
class flwor_expr;

typedef rchandle<flwor_clause> flwor_clause_t;
typedef rchandle<for_clause> for_clause_t;
typedef rchandle<let_clause> let_clause_t;
typedef rchandle<window_clause> window_clause_t;
typedef rchandle<flwor_wincond> flwor_wincond_t;
typedef rchandle<orderby_clause> orderby_clause_t;
typedef rchandle<materialize_clause> materialize_clause_t;
typedef rchandle<group_clause> group_clause_t;

typedef rchandle<flwor_expr> flwor_expr_t;


/***************************************************************************//**

********************************************************************************/
class flwor_clause : public SimpleRCObject
{
  friend class flwor_expr;
  friend class ExprIterator;

public:
  typedef std::vector<std::pair<expr_t, var_expr_t> > rebind_list_t;

  typedef enum
  {
    for_clause,
    let_clause,
    window_clause,
    group_clause,
    order_clause,
    count_clause,
    where_clause,
    materialize_clause
  } ClauseKind;

protected:
  static_context          * theContext;
  QueryLoc                  theLocation;

  ClauseKind                theKind;
  flwor_expr              * theFlworExpr;

public:
  SERIALIZABLE_ABSTRACT_CLASS(flwor_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(flwor_clause, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  flwor_clause(static_context* sctx, const QueryLoc& loc, ClauseKind kind)
    :
    theContext(sctx),
    theLocation(loc),
    theKind(kind),
    theFlworExpr(NULL)
  {
  }

  const QueryLoc& get_loc() const { return theLocation; }

  ClauseKind get_kind() const { return theKind; }

  flwor_expr* get_flwor_expr() const { return theFlworExpr; }

  virtual expr* get_expr() const { return NULL; }

  virtual void set_expr(expr_t v) { }

  virtual var_expr* get_pos_var() const { return NULL; }

  virtual var_expr* get_score_var() const { return NULL; }

  virtual flwor_clause_t clone(expr::substitution_t& substitution) const = 0;
};


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
  friend class flwor_expr;
  friend class ExprIterator;

protected:
  var_expr_t   theVarExpr;
  expr_t       theDomainExpr;

public:
  SERIALIZABLE_ABSTRACT_CLASS(forletwin_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(forletwin_clause, flwor_clause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  forletwin_clause(
        static_context* sctx,
        const QueryLoc& loc,
        ClauseKind kind,
        var_expr_t varExpr,
        expr_t domainExpr);

  ~forletwin_clause();

  void set_expr(expr_t v);

  expr* get_expr() const { return theDomainExpr.getp(); }

  var_expr* get_var() const { return theVarExpr.getp(); }

  void set_var(var_expr_t v);
};


/***************************************************************************//**

********************************************************************************/
class for_clause : public forletwin_clause
{
  friend class flwor_expr;
  friend class ExprIterator;

protected:
  var_expr_t    thePosVarExpr;
  var_expr_t    theScoreVarExpr;
  bool          theAllowingEmpty;

public:
  SERIALIZABLE_CLASS(for_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(for_clause, forletwin_clause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  for_clause(
        static_context* sctx,
        const QueryLoc& loc,
        var_expr_t varExpr,
        expr_t domainExpr,
        var_expr_t posVarExpr = NULL,
        var_expr_t scoreVarExpr = NULL,
        bool isOuter = false);

  ~for_clause();

public:
  bool is_allowing_empty() const { return theAllowingEmpty; }

  void set_allowing_empty(bool allowing_empty) { theAllowingEmpty = allowing_empty; }

  var_expr* get_pos_var() const;

  var_expr* get_score_var() const;

  void set_pos_var(var_expr_t v);

  void set_score_var(var_expr_t v);

  flwor_clause_t clone(expr::substitution_t& substitution) const;

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  theScoreVarExpr :
  theLazyEval     : Whether the window var can be materilized lazily or not.
********************************************************************************/
class let_clause : public forletwin_clause
{
  friend class flwor_expr;
  friend class ExprIterator;

protected:
  var_expr_t  theScoreVarExpr;
  bool        theLazyEval;

public:
  SERIALIZABLE_CLASS(let_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(let_clause, forletwin_clause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  let_clause(
        static_context* sctx,
        const QueryLoc& loc,
        var_expr_t varExpr,
        expr_t domainExpr,
        bool lazy = false);

  ~let_clause();

public:
  var_expr* get_score_var() const;

  void set_score_var(var_expr_t v);

  void setLazyEval(bool v) { theLazyEval = v; }

  bool lazyEval() const { return theLazyEval; }

  flwor_clause_t clone(expr::substitution_t& substitution) const;

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
  friend class flwor_expr;
  friend class ExprIterator;

public:
  typedef enum { tumbling_window, sliding_window } window_t;

protected:
  window_t          theWindowKind;
  flwor_wincond_t   theWinStartCond;
  flwor_wincond_t   theWinStopCond;
  bool              theLazyEval;

public:
  SERIALIZABLE_CLASS(window_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(window_clause, forletwin_clause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  window_clause(
        static_context* sctx,
        const QueryLoc& loc,
        window_t winKind,
        var_expr_t varExpr,
        expr_t domainExpr,
        flwor_wincond_t winStart,
        flwor_wincond_t winStop,
        bool lazy = false);

  ~window_clause();

public:
  window_t get_winkind() const { return theWindowKind; }

  flwor_wincond* get_win_start() const { return theWinStartCond.getp(); }

  flwor_wincond* get_win_stop() const { return theWinStopCond.getp(); }

  void set_win_start(flwor_wincond* cond);

  void set_win_stop(flwor_wincond* cond);

  void setLazyEval(bool v) { theLazyEval = v; }

  bool lazyEval() const { return theLazyEval; }

  flwor_clause_t clone(expr::substitution_t& substitution) const;

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
class flwor_wincond : public SimpleRCObject
{
  friend class flwor_expr;
  friend class ExprIterator;

public:
  struct vars : public SerializeBaseClass
  {
    var_expr_t posvar;
    var_expr_t curr;
    var_expr_t prev;
    var_expr_t next;

    vars();
    ~vars();
    void set_flwor_clause(flwor_clause* c);

    void clone(vars& cloneVars, expr::substitution_t& subst) const;

    std::ostream& put(std::ostream&) const;
  public:
    SERIALIZABLE_CLASS(vars)
    SERIALIZABLE_CLASS_CONSTRUCTOR(vars)
    void serialize(::zorba::serialization::Archiver& ar);
  };

protected:
  bool    theIsOnly;
  vars    theInputVars;
  vars    theOutputVars;
  expr_t  theCondExpr;

public:
  SERIALIZABLE_CLASS(flwor_wincond)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(flwor_wincond, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  flwor_wincond(
      static_context* sctx,
      bool isOnly,
      const vars& in_vars,
      const vars& out_vars,
      expr_t cond);

  ~flwor_wincond();

  expr* get_cond() const { return theCondExpr.getp(); }

  void set_cond(expr* cond) { theCondExpr = cond; }

  bool is_only() const { return theIsOnly; }

  const vars& get_in_vars() const { return theInputVars; }

  const vars& get_out_vars() const { return theOutputVars; }

  void set_flwor_clause(flwor_clause *);

  flwor_wincond_t clone(expr::substitution_t& substitution) const;

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  - Syntax:

  GroupByClause ::= "group" "by" GroupingSpecList

  GroupSpecList ::= GroupingSpec ("," GroupingSpec)*

  GroupSpec ::= "$" VarName ("collation" URILiteral)?

  - Data Members:

  theGroupVars    : For each grouping var X, theGroupVars contains a pair of
                    exprs: the 1st element of the pair is a reference to X in
                    the groupby's input tuple stream, and the 2nd element is
                    a var_expr representing the variable gX that the groupby
                    produces for X in its output tuple stream.
  theNonGroupVars : For each non-grouping var Y, theGroupVars contains a pair of
                    exprs: the 1st element of the pair is a reference to Y in
                    the groupby's input tuple stream, and the 2nd element is
                    a var_expr representing the variable gY that the groupby
                    produces for Y in its output tuple stream. For each tuple
                    T produced by the groupby, gY is the concatenation of all
                    the Y values in the input tuples that were grouped into T.
  theCollations   : The collations to use when comparing values for grouping.
********************************************************************************/
class group_clause : public flwor_clause
{
  friend class flwor_expr;
  friend class ExprIterator;

protected:
  rebind_list_t            theGroupVars;
  rebind_list_t            theNonGroupVars;
  std::vector<std::string> theCollations;

public:
  SERIALIZABLE_CLASS(group_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(group_clause, flwor_clause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  group_clause(
        static_context* sctx,
        const QueryLoc& loc,
        const rebind_list_t& gvars,
        rebind_list_t ngvars,
        const std::vector<std::string>& collations);

  ~group_clause();

  const std::vector<std::string>& get_collations() const { return theCollations; }

  csize getNumGroupingVars() const { return theGroupVars.size(); }

  csize getNumNonGroupingVars() const { return theNonGroupVars.size(); }

  const rebind_list_t& get_grouping_vars() const { return theGroupVars; }

  const rebind_list_t& get_nongrouping_vars() const { return theNonGroupVars; }

  void set_grouping_vars(rebind_list_t& new_group_vars){ theGroupVars = new_group_vars;}

  void set_nongrouping_vars(rebind_list_t& new_nongroup_vars){theNonGroupVars = new_nongroup_vars;}

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

  flwor_clause_t clone(expr::substitution_t& substitution) const;

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
  friend class ExprIterator;
  friend class flwor_expr;

protected:

  bool                        theStableOrder;
  std::vector<OrderModifier>  theModifiers;
  std::vector<expr_t>         theOrderingExprs;

public:
  SERIALIZABLE_CLASS(orderby_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(orderby_clause, flwor_clause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  orderby_clause (
      static_context* sctx,
      const QueryLoc& loc,
      bool stable,
      const std::vector<OrderModifier>& modifiers,
      const std::vector<expr_t>& orderingExprs);

  bool is_stable() const { return theStableOrder; }

  const std::vector<OrderModifier>& get_modifiers() const { return theModifiers; }

  const std::vector<expr_t>& get_column_exprs() const { return theOrderingExprs; }

  std::vector<expr_t>::iterator begin() { return theOrderingExprs.begin(); }

  std::vector<expr_t>::const_iterator begin() const
  { return theOrderingExprs.begin(); }

  std::vector<expr_t>::iterator end() { return theOrderingExprs.end(); }

  std::vector<expr_t>::const_iterator end() const
  { return theOrderingExprs.end(); }

  csize num_columns() const { return theOrderingExprs.size(); }

  expr* get_column_expr(csize i) const { return theOrderingExprs[i].getp(); }

  void set_column_expr(csize i, expr_t e) { theOrderingExprs[i] = e; }

  flwor_clause_t clone(expr::substitution_t& substitution) const;

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
  friend class flwor_expr;

public:
  SERIALIZABLE_CLASS(materialize_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(materialize_clause, flwor_clause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  materialize_clause(static_context* sctx, const QueryLoc& loc);

  flwor_clause_t clone(expr::substitution_t& substitution) const;

  std::ostream& put(std::ostream&) const;
};



/***************************************************************************//**
  CountClause ::= "count" "$" VarName
********************************************************************************/
class count_clause : public flwor_clause
{
  friend class ExprIterator;

protected:
  var_expr_t theVarExpr;

public:
  SERIALIZABLE_CLASS(count_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(count_clause, flwor_clause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  count_clause(static_context* sctx, const QueryLoc& loc, var_expr_t var);

  ~count_clause();

  var_expr* get_var() const { return theVarExpr.getp(); }

  flwor_clause_t clone(expr::substitution_t& substitution) const;
};


/***************************************************************************//**
   WhereClause ::= ExprSingle
********************************************************************************/
class where_clause : public flwor_clause
{
  friend class ExprIterator;
  friend class flwor_expr;

  expr_t theWhereExpr;

public:
  SERIALIZABLE_CLASS(where_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(where_clause, flwor_clause)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  where_clause(static_context* sctx, const QueryLoc& loc, expr_t where);

  expr* get_expr() const { return theWhereExpr.getp(); }

  void set_expr(expr_t where);

  flwor_clause_t clone(expr::substitution_t& substitution) const;
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

public:
  typedef std::vector<rchandle<flwor_clause> > clause_list_t;

protected:
  bool          theIsGeneral;
  bool          theHasSequentialClauses;
  clause_list_t theClauses;
  expr_t        theReturnExpr;

public:
  SERIALIZABLE_CLASS(flwor_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(flwor_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  flwor_expr(static_context* sctx, const QueryLoc& loc, bool general);

  bool is_general() const { return theIsGeneral; }

  void set_general(bool v) { theIsGeneral = true; }

  expr* get_return_expr() const { return theReturnExpr.getp(); }

  void set_return_expr(expr_t e)
  {
    theReturnExpr = e;
    compute_scripting_kind();
  }

  bool has_sequential_clauses() const { return theHasSequentialClauses; }

  void compute_scripting_kind();

  ulong num_clauses() const { return (ulong)theClauses.size(); }

  void add_clause(flwor_clause* c, bool computeScriptingKind = true);

  void add_clause(ulong pos, flwor_clause* c);

  void add_where(expr_t e);

  void remove_clause(csize pos);

  flwor_clause* get_clause(csize i) const;

  clause_list_t::const_iterator clause_begin() const { return theClauses.begin(); }

  clause_list_t::const_iterator clause_end() const { return theClauses.end(); }

  long defines_variable(const var_expr* v) const;

  void get_vars_defined(std::vector<var_expr*>& varExprs) const;

  expr_t clone(substitution_t& substitution) const;

  // The following 5 methods are for the simple flwor only. They should be
  // removed eventually.
  expr* get_where() const;
  void set_where(expr* e);
  void remove_where_clause();
  group_clause* get_group_clause() const;
  orderby_clause* get_order_clause() const;
  ulong num_forlet_clauses();

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
