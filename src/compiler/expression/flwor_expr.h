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

namespace zorba {

/*______________________________________________________________________
| ::= ("ascending" | "descending")?
|     ("empty" ("greatest" | "least"))?
|     ("collation" URILiteral)?
|_______________________________________________________________________*/

class order_modifier : public SimpleRCObject {
public:
  ParseConstants::dir_spec_t dir;
  StaticContextConsts::order_empty_mode_t empty_mode;
  std::string collation;

public:
  order_modifier (ParseConstants::dir_spec_t _dir, StaticContextConsts::order_empty_mode_t _empty_mode, std::string _collation)
   : dir (_dir), empty_mode (_empty_mode), collation (_collation) {}

};


/******************************************************************************

  [33] [http://www.w3.org/TR/xquery/#prod-xquery-FLWORExpr]

   ::= VARNAME  ("in"|":=")  ExprSingle
     | VARNAME  TypeDeclaration  ("in"|":=")  ExprSingle
     | VARNAME  PositionalVar  "in"  ExprSingle
     | VARNAME  TypeDeclaration  PositionalVar  "in"  ExprSingle
     | VARNAME  FTScoreVar  ("in"|":=")  ExprSingle
     | VARNAME  TypeDeclaration  FTScoreVar  ("in"|":=")  ExprSingle
     | VARNAME  PositionalVar  FTScoreVar  "in"  ExprSingle
     | VARNAME  TypeDeclaration  PositionalVar  FTScoreVar  "in"  ExprSingle

********************************************************************************/
class forlet_clause : public SimpleRCObject {
  friend class flwor_expr;
public:
  enum forlet_t {
    for_clause,
    let_clause
  };

protected: // state
  enum forlet_t type;
  varref_t var_h;
  varref_t pos_var_h;
  varref_t score_var_h;
  expr_t expr_h;

public: // ctor,dtor
  forlet_clause(
    enum forlet_t _type,
    varref_t _var_h,
    varref_t _pos_var_h,
    varref_t _score_var_h,
    expr_t _expr_h);


public: // accessors
  enum forlet_t get_type() const { return type; }
  varref_t get_var() const { return var_h; }
  varref_t get_pos_var() const { return pos_var_h; }
  varref_t get_score_var() const { return score_var_h; }
  expr_t get_expr() const { return expr_h; }

  void set_type(enum forlet_t v) { type = v; }
  void set_var(varref_t v) { var_h = v; if (var_h != NULL) { var_h->set_forlet_clause(this); } }
  void set_pos_var(varref_t v) { pos_var_h = v; if (pos_var_h != NULL) { pos_var_h->set_forlet_clause(this); } }
  void set_score_var(varref_t v) { score_var_h = v; if (score_var_h != NULL) { score_var_h->set_forlet_clause(this); } }
  void set_expr(expr_t v) { expr_h = v; }

public:
  std::ostream& put(std::ostream&) const;
  
  rchandle<forlet_clause> clone(expr::substitution_t& substitution);
};

class group_clause : public SimpleRCObject {
  friend class flwor_expr;
protected:
  expr_t      theOuterVar;
  expr_t      theInnerVar;
  std::string theCollation;

public:
  group_clause(rchandle<var_expr> aOuterVar, rchandle<var_expr> aInnerVar) 
  : theOuterVar(aOuterVar.getp()), theInnerVar(aInnerVar.getp()), theCollation("") {}

  group_clause(rchandle<var_expr> aOuterVar, rchandle<var_expr> aInnerVar, const std::string aCollation)
  : theOuterVar(aOuterVar.getp()), theInnerVar(aInnerVar.getp()), theCollation(aCollation) {}

  rchandle<var_expr> getOuterVar() const {
    return rchandle<var_expr>(static_cast<var_expr*>(theOuterVar.getp())); 
  }
  rchandle<var_expr> getInnerVar() const { 
    return rchandle<var_expr>(static_cast<var_expr*>(theInnerVar.getp())); 
  }

  std::string getCollation() const { return theCollation; }
  
  // TODO clone?
};


/*______________________________________________________________________
| ::= ForLetClauseList  RETURN  ExprSingle
|     | ForLetClauseList  WhereClause  RETURN  ExprSingle
|     | ForLetClauseList  OrderByClause  RETURN  ExprSingle
|     | ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
|_______________________________________________________________________*/

class flwor_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return flwor_expr_kind; }
 // types
  typedef rchandle<forlet_clause> forletref_t;
  typedef rchandle<order_modifier> orderref_t;
  typedef std::pair<expr_t,orderref_t> orderspec_t;
  typedef std::vector<forletref_t> clause_list_t;
  typedef std::vector<orderspec_t> orderspec_list_t;
  typedef rchandle<group_clause> groupref_t;
  typedef std::vector<groupref_t> group_list_t;

protected:  // state
  clause_list_t clause_v;
  orderspec_list_t orderspec_v;
  bool order_stable;  // per clause, not per spec!
  expr_t where_h;
  group_list_t group_v;
  group_list_t non_group_v;
  expr_t group_where_h;
  expr_t retval_h;

public: // ctor,dtor
  flwor_expr(const QueryLoc& loc)
   : expr(loc), order_stable (false)
  {}
  flwor_expr(const QueryLoc& loc, clause_list_t clause_v_, expr_t retval_)
   : expr (loc), clause_v (clause_v_), order_stable (false), retval_h (retval_)
  {}

public: // accessors
  expr_iterator_data *make_iter ();
  void add(forletref_t v) { clause_v.push_back(v); }
  void add(int index, forletref_t v) { clause_v.insert(clause_v.begin() + index, v); }
  uint32_t forlet_count() const { return clause_v.size(); }
  forletref_t const& operator[](int i) const { return clause_v[i]; }
  forletref_t & operator[](int i) { return clause_v[i]; }
  clause_list_t::iterator remove_forlet_clause(clause_list_t::iterator i);
  clause_list_t::const_iterator clause_begin() const
  { return clause_v.begin(); }
  clause_list_t::const_iterator clause_end() const
  { return clause_v.end(); }
  clause_list_t::iterator clause_begin()
  { return clause_v.begin(); }
  clause_list_t::iterator clause_end()
  { return clause_v.end(); }
  clause_list_t::reverse_iterator clause_rbegin()
  { return clause_v.rbegin(); }
  clause_list_t::reverse_iterator clause_rend()
  { return clause_v.rend(); }

  group_list_t::const_iterator group_begin() const
  { return group_v.begin(); }
  group_list_t::const_iterator group_end() const
  { return group_v.end(); }

  group_list_t::reverse_iterator group_rbegin()
  { return group_v.rbegin(); }
  group_list_t::reverse_iterator group_rend()
  { return group_v.rend(); }

  group_list_t::const_iterator non_group_begin() const
  { return non_group_v.begin(); }
  group_list_t::const_iterator non_group_end() const
  { return non_group_v.end(); }

  group_list_t::reverse_iterator non_group_rbegin()
  { return non_group_v.rbegin(); }
  group_list_t::reverse_iterator non_group_rend()
  { return non_group_v.rend(); }

  void add(rchandle<group_clause> v) { group_v.push_back(v); }
  void add_non_group(rchandle<group_clause> v) { non_group_v.push_back(v); }

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

  expr_t get_where() const { return where_h; }
  void set_where(expr_t e_h) { where_h = e_h; }

  expr_t get_group_where() const { return group_where_h; }
  void set_group_where(expr_t e_h) { group_where_h = e_h; }

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
