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

#ifndef ZORBA_COMPILER_FLWOR_EXPR_H
#define ZORBA_COMPILER_FLWOR_EXPR_H

#include "common/shared_types.h"

#include "compiler/expression/expr_base.h"
#include "compiler/expression/var_expr.h"


namespace zorba 
{

class order_modifier;
class flwor_clause;
class for_clause;
class let_clause;
class window_clause;
class flwor_wincond;
class orderby_clause;
class group_clause;
class flwor_expr;

typedef rchandle<flwor_clause> flwor_clause_t;
typedef rchandle<for_clause> for_clause_t;
typedef rchandle<let_clause> let_clause_t;
typedef rchandle<window_clause> window_clause_t;
typedef rchandle<flwor_wincond> flwor_wincond_t;
typedef rchandle<orderby_clause> orderby_clause_t;
typedef rchandle<group_clause> group_clause_t;

typedef rchandle<flwor_expr> flwor_expr_t;


/***************************************************************************//**

********************************************************************************/
class flwor_clause : public SimpleRCObject 
{
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
    where_clause
  } ClauseKind;

protected:
  short                     theContext;
  QueryLoc                  theLocation;

  ClauseKind                theKind;

public:
  SERIALIZABLE_ABSTRACT_CLASS(flwor_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(flwor_clause, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    //serialize_baseclass(ar, (SimpleRCObject*)this);
    ar & theContext;
    ar & theLocation;
    SERIALIZE_ENUM(ClauseKind, theKind);
  }

public:
  flwor_clause (short sctx, const QueryLoc& loc, ClauseKind kind) 
    :
    theContext(sctx),
    theLocation(loc),
    theKind(kind)
  {
  }

  const QueryLoc& get_loc() const { return theLocation; }

  ClauseKind get_kind() const { return theKind; }

  virtual flwor_clause_t clone(expr::substitution_t& substitution) = 0;
};


/***************************************************************************//**

  ForClause ::=	"outer"? "for" "$" VarName TypeDeclaration? PositionalVar?
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

protected:
  var_expr_t   theVarExpr;
  expr_t       theDomainExpr;

public:
  SERIALIZABLE_ABSTRACT_CLASS(forletwin_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(forletwin_clause, flwor_clause)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (flwor_clause*)this);
    ar & theVarExpr;
    ar & theDomainExpr;
  }

public:
  forletwin_clause(
        short sctx,
        const QueryLoc& loc,
        ClauseKind kind,
        var_expr_t varExpr,
        expr_t domainExpr);

  ~forletwin_clause();

  void set_expr(expr_t v) { theDomainExpr = v; }

  expr* get_expr() const { return theDomainExpr.getp(); }

  var_expr* get_var() const { return theVarExpr.getp(); }

  void set_var(var_expr_t v) 
  { 
    theVarExpr = v;
    if (theVarExpr != NULL)
      theVarExpr->set_flwor_clause(this); 
  }

  virtual var_expr* get_pos_var() const { return NULL; }

  virtual var_expr* get_score_var() const { return NULL; }
};


/***************************************************************************//**

********************************************************************************/
class for_clause : public forletwin_clause 
{
  friend class flwor_expr;

protected:
  var_expr_t    thePosVarExpr;
  var_expr_t    theScoreVarExpr;
  bool          theIsOuter;

public:
  SERIALIZABLE_CLASS(for_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(for_clause, forletwin_clause)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (forletwin_clause*)this);
    ar & thePosVarExpr;
    ar & theScoreVarExpr;
    ar & theIsOuter;
  }
public:
  for_clause(
        short sctx,
        const QueryLoc& loc,
        var_expr_t varExpr,
        expr_t domainExpr,
        var_expr_t posVarExpr = NULL,
        var_expr_t scoreVarExpr = NULL,
        bool isOuter = false);

  ~for_clause();

public:
  bool is_outer() const { return theIsOuter; }

  void set_outer(bool outer) { theIsOuter = outer; }

  var_expr* get_pos_var() const { return thePosVarExpr.getp(); }

  var_expr* get_score_var() const { return theScoreVarExpr.getp(); }

  void set_pos_var(var_expr_t v) 
  {
    thePosVarExpr = v;
    if (thePosVarExpr != NULL)
      thePosVarExpr->set_flwor_clause(this);
  }

  void set_score_var(var_expr_t v) 
  {
    theScoreVarExpr = v;
    if (theScoreVarExpr != NULL)
      theScoreVarExpr->set_flwor_clause(this); 
  }

  flwor_clause_t clone(expr::substitution_t& substitution);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class let_clause : public forletwin_clause 
{
  friend class flwor_expr;

protected:
  var_expr_t  theScoreVarExpr;

public:
  SERIALIZABLE_CLASS(let_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(let_clause, forletwin_clause)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (forletwin_clause*)this);
    ar & theScoreVarExpr;
  }
public:
  let_clause(
        short sctx,
        const QueryLoc& loc,
        var_expr_t varExpr,
        expr_t domainExpr,
        var_expr_t scoreVarExpr = NULL);

  ~let_clause();

public:
  var_expr* get_score_var() const { return theScoreVarExpr.getp(); }

  void set_score_var(var_expr_t v) 
  {
    theScoreVarExpr = v;
    if (theScoreVarExpr != NULL)
      theScoreVarExpr->set_flwor_clause(this); 
  }

  flwor_clause_t clone(expr::substitution_t& substitution);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class window_clause : public forletwin_clause 
{
  friend class flwor_expr;

public:
  typedef enum { tumbling_window, sliding_window } window_t;

protected:
  window_t          theWindowKind;
  flwor_wincond_t   theWinStartCond;
  flwor_wincond_t   theWinStopCond;

public:
  SERIALIZABLE_CLASS(window_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(window_clause, forletwin_clause)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (forletwin_clause*)this);
    SERIALIZE_ENUM(window_t, theWindowKind);
    ar & theWinStartCond;
    ar & theWinStopCond;
  }

public:
  window_clause(
        short sctx,
        const QueryLoc& loc,
        window_t winKind,
        var_expr_t varExpr,
        expr_t domainExpr,
        flwor_wincond_t winStart,
        flwor_wincond_t winStop);

  ~window_clause();

public:
  window_t get_winkind() const { return theWindowKind; }

  flwor_wincond* get_win_start() const { return theWinStartCond.getp(); }

  flwor_wincond* get_win_stop() const { return theWinStopCond.getp(); }

  void set_win_start(flwor_wincond* cond);

  void set_win_stop(flwor_wincond* cond);

  flwor_clause_t clone(expr::substitution_t& substitution);

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

public:
  struct vars 
  {
    var_expr_t posvar;
    var_expr_t curr;
    var_expr_t prev;
    var_expr_t next;

    void set_flwor_clause(flwor_clause* c);

    void clone(
        vars& cloneVars,
        expr::substitution_t& subst); 
      
    std::ostream& put(std::ostream&) const;
  };

protected:
  bool    theIsOnly;
  vars    theInputVars;
  vars    theOutputVars;
  expr_t  theCondExpr;

public:
  flwor_wincond(
        static_context* sctx,
        bool isOnly,
        const vars& in_vars,
        const vars& out_vars,
        expr_t cond);

  expr* get_cond() const { return theCondExpr.getp(); }

  void set_cond(expr* cond) { theCondExpr = cond; }

  bool is_only() const { return theIsOnly; }

  const vars& get_in_vars() const { return theInputVars; }

  const vars& get_out_vars() const { return theOutputVars; }

  void set_flwor_clause(flwor_clause *);

  flwor_wincond_t clone(expr::substitution_t& substitution);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**
  - Syntax:

  GroupByClause ::= "group" "by" GroupingSpecList

  GroupSpecList ::= 	GroupingSpec ("," GroupingSpec)*

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

protected:
  rebind_list_t            theGroupVars;
  rebind_list_t            theNonGroupVars;
  std::vector<std::string> theCollations;

public:
  SERIALIZABLE_ABSTRACT_CLASS(group_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(group_clause, flwor_clause)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (flwor_clause*)this);
    ar & theGroupVars;
    ar & theNonGroupVars;
    ar & theCollations;
  }

public:
  group_clause(
        short sctx,
        const QueryLoc& loc,
        const rebind_list_t& gvars,
        rebind_list_t ngvars,
        const std::vector<std::string>& collations);

  ~group_clause();

  const std::vector<std::string>& get_collations() const { return theCollations; }

  ulong getNumGroupingVars() const { return theGroupVars.size(); }

  ulong getNumNonGroupingVars() const { return theNonGroupVars.size(); }

  const rebind_list_t& get_grouping_vars() const { return theGroupVars; }

  const rebind_list_t& get_nongrouping_vars() const { return theNonGroupVars; }
  
  expr* get_input_for_group_var(const var_expr* var);

  expr* get_input_for_nongroup_var(const var_expr* var);

  flwor_clause_t clone(expr::substitution_t& substitution);

  std::ostream& put(std::ostream&) const;
};



/***************************************************************************//**

  OrderByClause ::= (("order" "by") | ("stable" "order" "by")) OrderSpecList

  OrderSpecList ::= 	OrderSpec ("," OrderSpec)*

  OrderSpec ::= 	ExprSingle OrderModifier

  OrderModifier ::= ("ascending" | "descending")?
                    ("empty" ("greatest" | "least"))?
                    ("collation" URILiteral)?

********************************************************************************/
class orderby_clause : public flwor_clause 
{
protected:
  friend class flwor_expr;

  bool                        theStableOrder;
  std::vector<order_modifier> theModifiers;
  std::vector<expr_t>         theOrderingExprs;

public:
  SERIALIZABLE_ABSTRACT_CLASS(orderby_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(orderby_clause, flwor_clause)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (flwor_clause*)this);
    ar & theStableOrder;
    ar & theModifiers;
    ar & theOrderingExprs;
  }
public:
  orderby_clause (
        short sctx,
        const QueryLoc& loc,
        bool stable,
        const std::vector<order_modifier>& modifiers,
        const std::vector<expr_t>& orderingExprs)
    :
    flwor_clause(sctx, loc, flwor_clause::order_clause),
    theStableOrder(stable),
    theModifiers(modifiers),
    theOrderingExprs(orderingExprs)
  {
  }

  bool is_stable() const { return theStableOrder; }

  const std::vector<order_modifier>& get_modifiers() const { return theModifiers; }

  const std::vector<expr_t>& get_column_exprs() const { return theOrderingExprs; }

  ulong num_columns() const { return theOrderingExprs.size(); }

  expr* get_column_expr(ulong i) const { return theOrderingExprs[i].getp(); }

  void set_column_expr(ulong i, expr_t e) { theOrderingExprs[i] = e; }

  flwor_clause_t clone(expr::substitution_t& substitution);

  std::ostream& put(std::ostream&) const;
};



/******************************************************************************

********************************************************************************/
class order_modifier : public SimpleRCObject 
{
public:
  ParseConstants::dir_spec_t theDirection;
  StaticContextConsts::order_empty_mode_t theEmptyMode;
  std::string theCollation;

public:
  order_modifier() 
    :
    theDirection(ParseConstants::dir_ascending),
    theEmptyMode(StaticContextConsts::empty_least)
  {
  }

  order_modifier(
        ParseConstants::dir_spec_t dir,
        StaticContextConsts::order_empty_mode_t empty_mode,
        const std::string& collation)
    :
    theDirection(dir), theEmptyMode(empty_mode), theCollation(collation)
  {
  }
};


/***************************************************************************//**
  CountClause ::= "count" "$" VarName
********************************************************************************/
class count_clause : public flwor_clause 
{
protected:
  var_expr_t theVarExpr;

public:
  SERIALIZABLE_ABSTRACT_CLASS(count_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(count_clause, flwor_clause)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (flwor_clause*)this);
    ar & theVarExpr;
  }
public:
  count_clause(short sctx, const QueryLoc& loc, var_expr_t var) 
    :
    flwor_clause(sctx, loc, flwor_clause::count_clause),
    theVarExpr(var)
  {
  }

  ~count_clause();

  var_expr* get_var() const { return theVarExpr.getp(); }

  flwor_clause_t clone(expr::substitution_t& substitution);
};


/***************************************************************************//**
   WhereClause ::= ExprSingle
********************************************************************************/
class where_clause : public flwor_clause 
{
  friend class flwor_expr;

  expr_t theWhereExpr;

public:
  SERIALIZABLE_ABSTRACT_CLASS(where_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(where_clause, flwor_clause)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (flwor_clause*)this);
    ar & theWhereExpr;
  }

public:
  where_clause(short sctx, const QueryLoc& loc, expr_t where) 
    :
    flwor_clause(sctx, loc, flwor_clause::where_clause),
    theWhereExpr(where)
  {
  }

  expr* get_where() const { return theWhereExpr.getp(); }

  void set_where(expr_t where) { theWhereExpr = where; }

  flwor_clause_t clone(expr::substitution_t& substitution);
};


/***************************************************************************//**
  FLWORExpr ::= InitialClause IntermediateClause* ReturnClause

  InitialClause ::= ForClause | LetClause | WindowClause

  IntermediateClause ::= InitialClause |
                         WhereClause |
                         GroupByClause |
                         OrderByClause |
                         CountClause
********************************************************************************/
class flwor_expr : public expr 
{
public:
  typedef std::vector<rchandle<flwor_clause> > clause_list_t;

protected:
  bool          theIsGeneral;
  clause_list_t theClauses;
  expr_t        theReturnExpr;

public:
  SERIALIZABLE_CLASS(flwor_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(flwor_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & theIsGeneral;
    ar & theClauses;
    ar & theReturnExpr;
  }

public:
  flwor_expr(short sctx, const QueryLoc& loc, bool general) 
    :
    expr(sctx, loc),
    theIsGeneral(general)
  {}

  expr_kind_t get_expr_kind() const 
  {
    return (theIsGeneral ? gflwor_expr_kind : flwor_expr_kind);
  }

  bool is_general() const { return theIsGeneral; }

  bool is_updating() const { return theReturnExpr->is_updating(); }

  expr* get_return_expr() const { return theReturnExpr.getp(); }

  void set_return_expr(expr_t e) { theReturnExpr = e; }

  xqtref_t return_type_impl(static_context* sctx);

  void compute_upd_seq_kind () const;

  ulong num_clauses() const { return theClauses.size(); }

  void add_clause(flwor_clause* c);

  void add_clause(ulong pos, flwor_clause* c);

  void add_where(expr_t e);

  void remove_clause(ulong pos);

  const flwor_clause* operator[](int i) const { return theClauses[i].getp(); }

  flwor_clause* operator[](int i) { return theClauses[i].getp(); }

  clause_list_t::const_iterator clause_begin() const { return theClauses.begin(); }

  clause_list_t::const_iterator clause_end() const { return theClauses.end(); }

  long defines_variable(const var_expr* v, const flwor_clause* limit) const;

  expr_t clone(substitution_t& substitution);

  expr_iterator_data* make_iter();

  void next_iter(expr_iterator_data&);

  // The following 5 methods are for the simple flwor only. They should be
  // removed eventually.
  expr* get_where() const;
  void set_where(expr* e);
  void remove_where_clause();
  group_clause* get_group_clause() const;
  ulong num_forlet_clauses();

  void accept(expr_visitor&);

  void accept_children(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};



}  // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
