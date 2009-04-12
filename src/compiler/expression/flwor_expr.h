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

#ifndef ZORBA_FLWOR_EXPR_H
#define ZORBA_FLWOR_EXPR_H

#include "compiler/expression/expr_base.h"
#include "context/dynamic_context.h"

namespace zorba {


#ifdef ZORBA_DEBUGGER

typedef rchandle<var_expr> var_expr_t;


/******************************************************************************


********************************************************************************/
class bound_var
{
public:
  store::Item_t varname;
  std::string var_key;
  xqtref_t type;
  expr_t val;
  var_expr_t var;

  bound_var() {};

  bound_var(var_expr* ve, var_expr_t var, expr_t val_)
    :
    varname (ve->get_varname ()),
    var_key (dynamic_context::var_key (ve)),
    type(ve->get_type()),
    val (val_),
    var(var){}
};
#endif


/******************************************************************************

  flwor_clause represents a syntactic entity that defines a variable within
  a flwor expr.

********************************************************************************/
class flwor_clause : public SimpleRCObject 
{
#ifdef ZORBA_DEBUGGER
private:
  std::list<global_binding> theGlobals;
  checked_vector<bound_var> theBoundVariables;

public:
  void set_bound_variables( checked_vector<var_expr_t> &aScopedVariables );
  
  checked_vector<bound_var> get_bound_variables() const
  {
    return theBoundVariables;
  }
    
  void set_global_variables( std::list<global_binding> &aGlobals )
  {
    theGlobals = aGlobals;
  }

  std::list<global_binding> get_global_variables() const
  {
    return theGlobals;
  }
#endif
};


/***************************************************************************//**

  - Syntax:

  InitialClause ::= ForClause | LetClause | WindowClause

  - Data Members:

  var_h  : The var_expr representing the variable defined by this clause (see
           compiler/expression/var_expr.h).
  expr_h : The expr that produces the value of the variable.

********************************************************************************/
class flwor_initial_clause : public flwor_clause 
{
protected:
  varref_t var_h;
  expr_t expr_h;

public:
  flwor_initial_clause (varref_t var_, expr_t expr_)
    :
    var_h (var_),
    expr_h (expr_) 
  {
  }

  void set_expr(expr_t v) { expr_h = v; }

  expr_t get_expr() const { return expr_h; }

  varref_t get_var() const { return var_h; }

  void set_var(varref_t v) 
  { 
    var_h = v;
    if (var_h != NULL)
      var_h->set_forlet_clause(this); 
  }
};


/******************************************************************************
  Represents a single FOR/LET variable definition

  - Syntax:

  ForClause ::=	"for" "$" VarName TypeDeclaration? PositionalVar? "in" ExprSingle

  LetClause ::= "let" "$" VarName TypeDeclaration? ":=" ExprSingle

  PositionalVar ::= "at" "$" VarName

  TypeDeclaration ::= "as" SequenceType

********************************************************************************/
class forlet_clause : public flwor_initial_clause
{
  friend class flwor_expr;
public:
  enum forlet_t { for_clause, let_clause };

protected:
  enum forlet_t theKind;
  varref_t pos_var_h;
  varref_t score_var_h;

public: 
  forlet_clause(
    enum forlet_t kind,
    varref_t _var_h,
    varref_t _pos_var_h,
    varref_t _score_var_h,
    expr_t _expr_h);

  enum forlet_t get_type() const { return theKind; }

  varref_t get_pos_var() const { return pos_var_h; }

  varref_t get_score_var() const { return score_var_h; }

  void set_type(enum forlet_t v) { theKind = v; }

  void set_pos_var(varref_t v) 
  {
    pos_var_h = v;
    if (pos_var_h != NULL)
      pos_var_h->set_forlet_clause(this);
  }

  void set_score_var(varref_t v) 
  {
    score_var_h = v;
    if (score_var_h != NULL)
      score_var_h->set_forlet_clause(this); 
  }


  std::ostream& put(std::ostream&) const;
  
  rchandle<forlet_clause> clone(expr::substitution_t& substitution);
};


/******************************************************************************
  If a flwor expr has a GroupBy clause, then there is one group_clause for
  each FOR/LET variable V that is defined in the flwor expr. For each V, the
  associated group_clause says whether V is a grouping variable or not, and
  if yes, it also specifies the colation to use when grouping the values of V.

  theOuterVar  : Reference to FOR/LET var V, if V is a grouping var; NULL
                 otherwise. 
  theInnerVar  : Reference to FOR/LET var V, if V is a non-grouping var; NULL
                 otherwise. 
  theCollation : The collation to use when comapring values of V, if V is a
                 gouping var.
********************************************************************************/
class group_clause : public flwor_clause 
{
  friend class flwor_expr;

protected:
  varref_t    theOuterVar;
  varref_t    theInnerVar;
  std::string theCollation;

public:
  group_clause(rchandle<var_expr> aOuterVar, rchandle<var_expr> aInnerVar) 
    :
    theOuterVar(aOuterVar.getp()),
    theInnerVar(aInnerVar.getp()),
    theCollation("") {}

  group_clause(
        rchandle<var_expr> aOuterVar,
        rchandle<var_expr> aInnerVar,
        const std::string aCollation)
    :
    theOuterVar(aOuterVar.getp()),
    theInnerVar(aInnerVar.getp()),
    theCollation(aCollation) {}

  rchandle<var_expr> getOuterVar() const { return theOuterVar; }

  rchandle<var_expr> getInnerVar() const {  return theInnerVar; }

  std::string getCollation() const { return theCollation; }
  
  // TODO clone?
};


/******************************************************************************

  OrderModifier ::= ("ascending" | "descending")?
                    ("empty" ("greatest" | "least"))?
                    ("collation" URILiteral)?

********************************************************************************/
class order_modifier : public SimpleRCObject 
{
public:
  ParseConstants::dir_spec_t dir;
  StaticContextConsts::order_empty_mode_t empty_mode;
  std::string collation;

public:
  order_modifier(
        ParseConstants::dir_spec_t _dir,
        StaticContextConsts::order_empty_mode_t _empty_mode,
        std::string _collation)
    :
    dir (_dir), empty_mode (_empty_mode), collation (_collation)
  {
  }
};


/***************************************************************************//**


********************************************************************************/
class flwor_expr : public expr 
{
public:
  typedef rchandle<forlet_clause> forletref_t;
  typedef std::vector<forletref_t> forlet_list_t;

  typedef rchandle<order_modifier> orderref_t;
  typedef std::pair<expr_t,orderref_t> orderspec_t;
  typedef std::vector<orderspec_t> orderspec_list_t;

  typedef rchandle<group_clause> groupref_t;
  typedef std::vector<groupref_t> group_list_t;

protected:
  forlet_list_t     theForLetClauses;

  orderspec_list_t  orderspec_v;
  bool              order_stable;  // per clause, not per spec!

  group_list_t      theGroupingVarClauses;
  group_list_t      theNonGroupingVarClauses;
  expr_t            group_where_h;

  expr_t            where_h;
  expr_t            retval_h;

public: // ctor,dtor
  flwor_expr(const QueryLoc& loc) : expr(loc), order_stable (false) {}

  flwor_expr(
        const QueryLoc& loc,
        forlet_list_t forletClauses,
        expr_t retExpr)
    :
    expr(loc),
    theForLetClauses(forletClauses),
    order_stable (false),
    retval_h (retExpr)
  {
  }

  expr_kind_t get_expr_kind () const { return flwor_expr_kind; }

public:
  expr_iterator_data* make_iter();

  bool defines_variable(const var_expr* v) const;

  //
  // ForLet Clauses
  //
  unsigned forlet_count() const 
  { return theForLetClauses.size(); }

  forletref_t const& operator[](int i) const 
  { return theForLetClauses[i]; }

  forletref_t & operator[](int i) 
  { return theForLetClauses[i]; }

  void add(forletref_t v) 
  { theForLetClauses.push_back(v); }

  void add(int idx, forletref_t v) 
  { theForLetClauses.insert(theForLetClauses.begin() + idx, v); }

  forlet_list_t::const_iterator forlet_begin() const
  { return theForLetClauses.begin(); }

  forlet_list_t::iterator forlet_begin()
  { return theForLetClauses.begin(); }

  forlet_list_t::const_iterator forlet_end() const
  { return theForLetClauses.end(); }

  forlet_list_t::iterator forlet_end()
  { return theForLetClauses.end(); }

  forlet_list_t::reverse_iterator forlet_rbegin()
  { return theForLetClauses.rbegin(); }

  forlet_list_t::reverse_iterator forlet_rend()
  { return theForLetClauses.rend(); }

  forlet_list_t::iterator remove_forlet(forlet_list_t::iterator i);


  //
  // GroupBy Clause
  //
  unsigned group_vars_count() const { return theGroupingVarClauses.size(); }

  group_list_t::const_iterator group_vars_begin() const
  { return theGroupingVarClauses.begin(); }

  group_list_t::reverse_iterator group_vars_rbegin()
  { return theGroupingVarClauses.rbegin(); }

  group_list_t::const_iterator group_vars_end() const
  { return theGroupingVarClauses.end(); }

  group_list_t::reverse_iterator group_vars_rend()
  { return theGroupingVarClauses.rend(); }

  group_list_t::const_iterator non_group_vars_begin() const
  { return theNonGroupingVarClauses.begin(); }

  group_list_t::const_iterator non_group_vars_end() const
  { return theNonGroupingVarClauses.end(); }

  group_list_t::reverse_iterator non_group_vars_rbegin()
  { return theNonGroupingVarClauses.rbegin(); }

  group_list_t::reverse_iterator non_group_vars_rend()
  { return theNonGroupingVarClauses.rend(); }

  void add(rchandle<group_clause> v)
  { theGroupingVarClauses.push_back(v); }

  void add_non_group(rchandle<group_clause> v)
  { theNonGroupingVarClauses.push_back(v); }

  expr_t get_group_where() const { return group_where_h; }

  void set_group_where(expr_t e_h) { group_where_h = e_h; }

  //
  // OrderBy Clause
  //
  void add(orderspec_t const& v)
  { orderspec_v.push_back(v); } 

  uint32_t orderspec_count() const
  { return orderspec_v.size(); }

  orderspec_t & orderspec_at(int i)
  { return orderspec_v[i]; }

  orderspec_t const& orderspec_at(int i) const
  { return orderspec_v[i]; }

  orderspec_list_t::const_iterator orderspec_begin() const
  { return orderspec_v.begin(); }

  orderspec_list_t::const_iterator orderspec_end() const
  { return orderspec_v.end(); }

  orderspec_list_t::iterator orderspec_begin()
  { return orderspec_v.begin(); }

  orderspec_list_t::iterator orderspec_end()
  { return orderspec_v.end(); }

  orderspec_list_t::reverse_iterator orderspec_rbegin()
  { return orderspec_v.rbegin(); }

  orderspec_list_t::reverse_iterator orderspec_rend()
  { return orderspec_v.rend(); }

  bool get_order_stable () const { return order_stable; }
  void set_order_stable (bool x) { order_stable = x; }

  //
  // WhereClause and ReturnClause
  //
  expr_t get_where() const { return where_h; }
  void set_where(expr_t e_h) { where_h = e_h; }

  expr_t get_retval() const { return retval_h; }
  void set_retval(expr_t e_h) { retval_h = e_h; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual expr_t clone(substitution_t& substitution);
  xqtref_t return_type_impl (static_context *sctx);
};

}  // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
