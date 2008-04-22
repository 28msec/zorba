/**
 * @file exprtree/expr.h
 * @author: John Cowan, Paul Pedersen
 * @copyright 2006-2007 FLWOR FOundation.
 *
 * ========================================================================
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *    http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 * ========================================================================
 *
 */

#ifndef ZORBA_EXPR_H
#define ZORBA_EXPR_H

#include <string>
#include <map>
#include "zorbatypes/xqpstring.h"

#include "common/common.h"
#include <zorba/store_consts.h>
#include "context/static_context_consts.h"
#include "store/api/item.h" // TODO remove by putting functions and explicit destructors into the cpp file
#include "zorbatypes/representations.h"

#include "errors/errors.h"
#include "common/shared_types.h"
#include "compiler/parser/query_loc.h"
#include "compiler/parser/parse_constants.h"
#include "util/checked_vector.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/expression/expr_consts.h"
#include "compiler/semantic_annotations/annotation_holder.h"
#include "store/api/fullText/ft_options.h"
#include "store/api/update_consts.h"

namespace zorba {

enum expr_kind_t {
  expr_kind,
  sequential_expr_kind,
  constructor_expr_kind,
  var_expr_kind,
  flwor_expr_kind,
  trycatch_expr_kind,
  promote_expr_kind,
  typeswitch_expr_kind,
  if_expr_kind,
  function_def_expr_kind,
  fo_expr_kind,
  ft_contains_expr_kind,
  instanceof_expr_kind,
  treat_expr_kind,
  castable_expr_kind,
  cast_expr_kind,
  name_cast_expr_kind,
  validate_expr_kind,
  extension_expr_kind,
  relpath_expr_kind,
  axis_step_expr_kind,
  match_expr_kind,
  const_expr_kind,
  order_expr_kind,
  elem_expr_kind,
  doc_expr_kind,
  attr_expr_kind,
  text_expr_kind,
  pi_expr_kind,
  unknown_expr_kind
};

class match_expr;
class expr_visitor;
class var_expr;
class NodeNameTest;

class expr_iterator_data;
class expr_iterator {
  // should be an auto_ptr, but older gcc's don't like auto_ptr w/ forward decl
  expr_iterator_data *iter;
  // comparisson forbidden; use done()
  bool operator== (const expr_iterator &other) { return false; }

public:
  expr_iterator () : iter (0) {}
  expr_iterator (expr_iterator_data *iter_) : iter (iter_) {}
  expr_iterator (const expr_iterator &other);
  ~expr_iterator ();
  expr_iterator &operator= (const expr_iterator &other);

  expr_iterator &operator++ ();
  expr_iterator operator++ (int);
  expr_t &operator* ();
  bool done () const;
};


/*______________________________________________________________________
 |  
 | base class for the expression tree node hierarchy
 |_______________________________________________________________________*/

class expr : public SimpleRCObject, public AnnotationHolder {
public:
  virtual expr_kind_t get_expr_kind () { return expr_kind; }
  typedef rchandle<expr> expr_t;
  typedef std::map<var_expr *, expr_t> substitution_t;
  typedef substitution_t::iterator subst_iter_t;

protected:
  QueryLoc loc;

  struct {
    struct {
      bool valid;
      xqtref_t t;
      static_context *sctx;
    } type;
  } cache;
  void invalidate () { cache.type.valid = false; }
  virtual bool cache_compliant () { return false; }

protected:
  virtual expr_iterator_data *make_iter ();
  
public:
  expr(const QueryLoc&);
  virtual ~expr();

public:
  QueryLoc get_loc() const { return loc; }
  void set_loc(const QueryLoc& aLoc) { loc = aLoc; }

public:
  virtual expr_iterator expr_begin ();
  virtual void accept(expr_visitor&);
  virtual void accept_children(expr_visitor &v);
  virtual void next_iter (expr_iterator_data &) = 0;
  virtual std::ostream& put(std::ostream&) const = 0;
  virtual std::string toString () const;

  virtual xqtref_t return_type(static_context *sctx);
  virtual xqtref_t return_type_impl(static_context *sctx);

  expr_t clone();
  virtual expr_t clone(substitution_t& substitution);
};

typedef rchandle<expr> expr_t;

class expr_iterator_data {
protected:
  expr *e;
  
public:
  expr_t *i;
  int state;
  
public:
  expr_iterator_data (expr *e_) : e (e_), i (NULL), state (0) {}
  virtual ~expr_iterator_data () {}
  virtual void next () {
    e->next_iter (*this);
  }
  bool done () const;
};

// imperative construct: do this, then that
class sequential_expr : public expr {
  checked_vector<expr_t> sequence;

public:
  expr_kind_t get_expr_kind () { return constructor_expr_kind; }

  sequential_expr (const QueryLoc& loc, expr_t first, expr_t second)
    : expr (loc)
  {
    sequence.push_back (first);
    sequence.push_back (second);
  }

  sequential_expr (const QueryLoc& loc, checked_vector<expr_t> sequence_, expr_t result)
    : expr (loc), sequence (sequence_)
  {
    sequence.push_back (result);
  }

  const unsigned size () const { return sequence.size (); }

  const expr_t &operator [] (int i) const { return sequence [i]; }
  expr_t &operator [] (int i) { invalidate (); return sequence [i]; }

  bool cache_compliant () { return true; }

  virtual xqtref_t return_type_impl (static_context *);

  expr_iterator_data *make_iter ();
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
};

class constructor_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return constructor_expr_kind; }

  constructor_expr(const QueryLoc& loc) : expr (loc) {}
};

/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  XQuery 1.0 productions                                             //
//  [http://www.w3.org/TR/xquery/]                                     //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


// [29] [http://www.w3.org/TR/xquery/#prod-xquery-EnclosedExpr]

// [31] [http://www.w3.org/TR/xquery/#prod-xquery-Expr]


/******************************************************************************

  var_expr represents a variable reference within any kind of expression.

*******************************************************************************/

class forlet_clause;

class var_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return var_expr_kind; }

  enum var_kind {
    for_var,
    let_var,
    pos_var,
    score_var,
    quant_var,
    context_var,
    param_var,
    catch_var,
    copy_var,
    groupby_var,
    unknown_var  // TODO: get rid
  };

  var_kind kind;
  store::Item_t varname_h;
  xqtref_t type;

public:
  var_expr(const QueryLoc& loc, store::Item_t name);
  var_expr(const QueryLoc& loc, var_kind k, store::Item_t name);

public:
  store::Item_t get_varname() const;

  var_kind get_kind() const { return kind; }
  void set_kind(var_kind k) { kind = k; }

  xqtref_t get_type() const;
  void set_type(xqtref_t t);

public:
  static std::string decode_var_kind(enum var_kind);

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual expr_t clone(substitution_t& substitution);
  virtual xqtref_t return_type_impl (static_context *);

  void set_forlet_clause(forlet_clause *flclause) { m_forlet_clause = flclause; }
  forlet_clause *get_forlet_clause() { return m_forlet_clause; }

protected:
  forlet_clause *m_forlet_clause;
};


// [41] [http://www.w3.org/TR/xquery/#prod-xquery-OrderModifier]

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
public:
  enum forlet_t {
    for_clause,
    let_clause
  };

  typedef rchandle<var_expr> varref_t;
  typedef rchandle<expr> expr_t;

public: // state
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
public:
  rchandle<var_expr> theOuterVar;
  rchandle<var_expr> theInnerVar;
  std::string        theCollation;

public:
  group_clause(rchandle<var_expr> aOuterVar, rchandle<var_expr> aInnerVar) 
  : theOuterVar(aOuterVar), theInnerVar(aInnerVar), theCollation("") {}

  group_clause(rchandle<var_expr> aOuterVar, rchandle<var_expr> aInnerVar, const std::string aCollation)
  : theOuterVar(aOuterVar), theInnerVar(aInnerVar), theCollation(aCollation) {}

  rchandle<var_expr> getOuterVar() const { return theOuterVar; }
  rchandle<var_expr> getInnerVar() const { return theInnerVar; }

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

  expr_t get_retval() const { return retval_h; }
  void set_retval(expr_t e_h) { retval_h = e_h; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual expr_t clone(substitution_t& substitution);
  xqtref_t return_type_impl (static_context *sctx);
};

class catch_clause : public SimpleRCObject {
  public:
    typedef rchandle<var_expr> varref_t;

  public:
    rchandle<NodeNameTest> nametest_h;
    varref_t var_h;
    varref_t errorcode_var_h;
    varref_t errordesc_var_h;
    varref_t errorobj_var_h;
    expr_t catch_expr_h;

  public:
    catch_clause();
};

class trycatch_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return trycatch_expr_kind; }
private:
  public:
    typedef rchandle<catch_clause> clauseref_t;

  protected:
    expr_t try_expr_h;
    std::vector<clauseref_t> catch_clause_hv;

  public:
    trycatch_expr(const QueryLoc&);

  public:
    expr_t get_try_expr() const
    { return try_expr_h; }
    void set_try_expr(expr_t e_h)
    { try_expr_h = e_h; }

  public:
    void add_clause(clauseref_t cc_h)
    { catch_clause_hv.push_back(cc_h); }

    void add_clause_in_front(clauseref_t cc_h)
    { catch_clause_hv.insert(catch_clause_hv.begin(), cc_h); }

    std::vector<clauseref_t>::const_iterator begin() const
    { return catch_clause_hv.begin(); }
    std::vector<clauseref_t>::const_iterator end() const
    { return catch_clause_hv.end(); }
    std::vector<clauseref_t>::iterator begin()
    { return catch_clause_hv.begin(); }
    std::vector<clauseref_t>::iterator end()
    { return catch_clause_hv.end(); }

    uint32_t clause_count() const
    { return catch_clause_hv.size(); }

    clauseref_t & operator[](int i)
    { return catch_clause_hv[i]; }
    clauseref_t const& operator[](int i) const
    { return catch_clause_hv[i]; }

  public:
    expr_iterator_data *make_iter ();

    void next_iter (expr_iterator_data&);
    void accept (expr_visitor&);
    std::ostream& put(std::ostream&) const;
};

class eval_expr : public expr {
public:
  class eval_var {
  public:
    store::Item_t varname;
    expr_t val;

    eval_var (store::Item_t varname_, expr_t val_) : varname (varname_), val (val_) {}
  };

protected:
  expr_t expr_h;
  checked_vector<eval_var> vars;

public:
  eval_expr (const QueryLoc &loc, expr_t expr_)
    : expr (loc), expr_h (expr_)
  {}

  const expr_t &get_expr () const { return expr_h; }
  expr_t get_expr () { return expr_h; }

  unsigned var_count () const { return vars.size (); }
  eval_var &var_at (unsigned i) { return vars [i]; }

  void add_var (eval_var var) { vars.push_back (var); }

  expr_iterator_data *make_iter ();
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
};

// [42] [http://www.w3.org/TR/xquery/#prod-xquery-QuantifiedExpr]

// [43] [http://www.w3.org/TR/xquery/#prod-xquery-TypeswitchExpr]

class case_clause : public SimpleRCObject {
public:
  typedef rchandle<expr> expr_t;
  typedef rchandle<var_expr> varref_t;

public:
  varref_t var_h;
  expr_t case_expr_h;
  xqtref_t type;

public:
  case_clause();

};

class cast_or_castable_base_expr : public expr {
public:  
  cast_or_castable_base_expr(const QueryLoc& loc, expr_t input, xqtref_t type);

protected:
  expr_t input_expr_h;
  xqtref_t target_type;
  
public:
  bool cache_compliant () { return true; }
  expr_t get_input() { invalidate (); return input_expr_h; }
  void set_input(expr_t input) { invalidate (); input_expr_h = input; }
  
  xqtref_t get_target_type() const;
  void set_target_type(xqtref_t target);
};

class cast_base_expr : public cast_or_castable_base_expr {
public:

  cast_base_expr(const QueryLoc& loc, expr_t input, xqtref_t type);
  xqtref_t return_type_impl (static_context *sctx);
};

class promote_expr : public cast_base_expr {
public:
  expr_kind_t get_expr_kind () { return promote_expr_kind; }

  promote_expr(const QueryLoc& loc, expr_t input, xqtref_t type);

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
};

class castable_base_expr : public cast_or_castable_base_expr {
public:
  castable_base_expr (const QueryLoc&, expr_t, xqtref_t);

  xqtref_t return_type_impl (static_context *sctx);
};

/*______________________________________________________________________
| ::= TreatExpr ("instance" "of" SequenceType)?
|_______________________________________________________________________*/

class instanceof_expr : public castable_base_expr {
public:
  expr_kind_t get_expr_kind () { return instanceof_expr_kind; }
protected:
  bool forced;  // error if not instance?

public:
  instanceof_expr (const QueryLoc&,
                   expr_t,
                   xqtref_t);

public:
  bool isForced () { return forced; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
};



// [55] [http://www.w3.org/TR/xquery/#prod-xquery-TreatExpr]

/*______________________________________________________________________
| ::= CastableExpr ("treat" "as" SequenceType)?
|_______________________________________________________________________*/

class treat_expr : public cast_base_expr {
protected:
  enum ZorbaError::ErrorCode err;
  bool check_prime;

public:
  expr_kind_t get_expr_kind () { return treat_expr_kind; }
  treat_expr(
    const QueryLoc&,
    expr_t,
    xqtref_t,
    enum ZorbaError::ErrorCode,
    bool check_prime = true);

  enum ZorbaError::ErrorCode get_err () { return err; }
  bool get_check_prime () { return check_prime; }
  void set_check_prime (bool check_prime_) { check_prime = check_prime_; }

  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
  xqtref_t return_type_impl (static_context *sctx);  
};


// [56] [http://www.w3.org/TR/xquery/#prod-xquery-CastableExpr]

/*______________________________________________________________________
| ::= CastExpr ("castable" "as" SingleType)?
|_______________________________________________________________________*/

class castable_expr : public castable_base_expr {
public:
  expr_kind_t get_expr_kind () { return castable_expr_kind; }

public:
  castable_expr(
    const QueryLoc&,
    expr_t,
    xqtref_t);

public:
  bool is_optional() const;

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
};



// [57] [http://www.w3.org/TR/xquery/#prod-xquery-CastExpr]

/*______________________________________________________________________
| ::= UnaryExpr ("cast" "as" SingleType)?
|_______________________________________________________________________*/

class cast_expr : public cast_base_expr {
public:
  expr_kind_t get_expr_kind () { return cast_expr_kind; }
  cast_expr(
    const QueryLoc&,
    expr_t,
    xqtref_t);

  bool is_optional() const;

  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
};

class name_cast_expr : public expr {
private:
  expr_t input_expr_h;
  NamespaceContext_t theNCtx;
public:
  name_cast_expr (
    const QueryLoc&,
    expr_t,
    NamespaceContext_t);

  expr_kind_t get_expr_kind () { return name_cast_expr_kind; }
  expr_t get_input() { return input_expr_h; }
  NamespaceContext_t getNamespaceContext();

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
};


/*______________________________________________________________________
| ::= TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
|     | TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT 
|         DOLLAR  VARNAME  RETURN  ExprSingle
|_______________________________________________________________________*/

class typeswitch_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return typeswitch_expr_kind; }

  typedef rchandle<var_expr> varref_t;
  typedef rchandle<case_clause> clauseref_t;

protected:
  expr_t switch_expr_h;
  std::vector<clauseref_t> case_clause_hv;
  varref_t  default_var_h;
  expr_t default_clause_h;

public:
  typeswitch_expr(const QueryLoc&);

public:
  expr_t get_switch_expr() const
  { return switch_expr_h; }
  void set_switch_expr(expr_t e_h)
  { switch_expr_h = e_h; }
  
  varref_t get_default_varname() const
  { return default_var_h; }
  void set_default_varname(varref_t const& var_h)
  { default_var_h = var_h; }

  expr_t get_default_clause() const
  { return default_clause_h; }
  void set_default_clause(expr_t const& e_h)
  { default_clause_h = e_h; }
  
public:
  void add_clause(clauseref_t cc_h)
  { case_clause_hv.push_back(cc_h); }
  
  std::vector<clauseref_t>::const_iterator begin() const
  { return case_clause_hv.begin(); }
  std::vector<clauseref_t>::const_iterator end() const
  { return case_clause_hv.end(); }
  std::vector<clauseref_t>::iterator begin()
  { return case_clause_hv.begin(); }
  std::vector<clauseref_t>::iterator end()
  { return case_clause_hv.end(); }
  
  uint32_t clause_count() const
  { return case_clause_hv.size(); }
  
  clauseref_t & operator[](int i)
  { return case_clause_hv[i]; }
  clauseref_t const& operator[](int i) const
  { return case_clause_hv[i]; }
  
public:
  expr_iterator_data *make_iter ();
  
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

};



// [45] [http://www.w3.org/TR/xquery/#prod-xquery-IfExpr]

/*______________________________________________________________________
| ::= <"if" "("> Expr ")" "then" ExprSingle "else" ExprSingle
|_______________________________________________________________________*/

class if_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return if_expr_kind; }
protected:
  expr_t cond_expr_h;
  expr_t then_expr_h;
  expr_t else_expr_h;

public:
  if_expr(
    const QueryLoc&,
    expr_t,
    expr_t,
    expr_t);

  if_expr(
    const QueryLoc&);


public:
  bool cache_compliant () { return true; }
  
  expr_t get_cond_expr() { invalidate (); return cond_expr_h; }
  void set_cond_expr(expr_t e_h) { invalidate (); cond_expr_h = e_h; }

  expr_t get_then_expr() { invalidate (); return then_expr_h; }
  void set_then_expr(expr_t e_h) { invalidate (); then_expr_h = e_h; }

  expr_t get_else_expr() { invalidate (); return else_expr_h; }
  void set_else_expr(expr_t e_h) { invalidate (); else_expr_h = e_h; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  xqtref_t return_type_impl (static_context *sctx);
};

class signature;

class function_def_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return function_def_expr_kind; }
protected:
  store::Item_t name;
  std::vector<rchandle<var_expr> > params;
  expr_t body;
  std::auto_ptr<signature> sig;

public:
  function_def_expr (const QueryLoc& loc, store::Item_t name_, std::vector<rchandle<var_expr> > &params_, xqtref_t return_type_impl);

  store::Item_t get_name () const { return name; }
  expr_t get_body () { return body; }
  void set_body (expr_t body_) { body = body_; }
  std::vector<rchandle<var_expr> >::iterator param_begin () { return params.begin (); }
  std::vector<rchandle<var_expr> >::iterator param_end () { return params.end (); }
  std::vector<rchandle<var_expr> >::size_type param_size () const { return params.size (); }
  const signature &get_signature () const { return *sig; }

  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream &put (std::ostream &) const;
};


////////////////////////////////
//  first-order expressions
////////////////////////////////


// [46] [http://www.w3.org/TR/xquery/#prod-xquery-OrExpr]
// [47] [http://www.w3.org/TR/xquery/#prod-xquery-AndExpr]
// [48] [http://www.w3.org/TR/xquery/#prod-xquery-ComparisonExpr]


class fo_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return fo_expr_kind; }
protected:
  checked_vector<expr_t> argv;
  const function* func;

public:
  fo_expr (const QueryLoc& loc, const function *f)
   : expr(loc), func (f)  { assert (f != NULL); }
  fo_expr (const QueryLoc& loc, const function *f, expr_t arg)
   : expr(loc), func (f)
  {
    assert (f != NULL);
    add (arg);
  }
  fo_expr (const QueryLoc& loc, const function *f, expr_t arg1, expr_t arg2)
   : expr(loc), func (f)
  {
    assert (f != NULL);
    add (arg1); add (arg2);
  }
  fo_expr (const QueryLoc& loc, const function *f, expr_t arg1, expr_t arg2, expr_t arg3)
   : expr(loc), func (f)
  {
    assert (f != NULL);
    add (arg1); add (arg2); add (arg3);
  }


public:
  bool cache_compliant () { return true; }

  expr_iterator_data *make_iter ();
  
  void add(expr_t e_h) { invalidate (); assert (e_h != NULL); argv.push_back(e_h); }

  uint32_t size() const { return argv.size(); }

  expr_t& operator[](int i) { invalidate (); return argv[i]; }
  const expr_t& operator[](int i) const { return argv[i]; }

  std::vector<expr_t>::const_iterator begin() const { return argv.begin(); }
  std::vector<expr_t>::const_iterator end() const { return argv.end(); }
  std::vector<expr_t>::iterator begin() { invalidate (); return argv.begin(); }
  std::vector<expr_t>::iterator end() { invalidate (); return argv.end(); }

public:
  const function* get_func() const { return func; }
  void set_func (const function *f) { invalidate (); func = f; }
  const signature &get_signature () const;
  store::Item_t get_fname () const;

  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual xqtref_t return_type_impl(static_context *sctx);
};





// [48a] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTContainsExpr]
class ft_select_expr;

/*______________________________________________________________________
| ::= RangeExpr ("ftcontains" FTSelection FTIgnoreOption?)?
|_______________________________________________________________________*/

class ft_contains_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return ft_contains_expr_kind; }
protected:
  expr_t range_h;
  expr_t ft_select_h;
  expr_t ft_ignore_h;

public:
  ft_contains_expr(
    const QueryLoc&,
    expr_t,
    expr_t,
    expr_t);


public:
  expr_t get_range() const { return range_h; }
  expr_t get_ft_select() const { return ft_select_h; }
  expr_t get_ignore() const { return ft_ignore_h; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

};



// [49] [http://www.w3.org/TR/xquery/#prod-xquery-RangeExpr]
// [50] [http://www.w3.org/TR/xquery/#prod-xquery-AdditiveExpr]
// [51] [http://www.w3.org/TR/xquery/#prod-xquery-MultiplicativeExpr]
// [52] [http://www.w3.org/TR/xquery/#prod-xquery-UnionExpr]
// [53] [http://www.w3.org/TR/xquery/#prod-xquery-IntersectExceptExpr]
// [54] [http://www.w3.org/TR/xquery/#prod-xquery-InstanceofExpr]


// [63] [http://www.w3.org/TR/xquery/#prod-xquery-ValidateExpr]

/*______________________________________________________________________
| ::= "validate" ValidationMode? "{" Expr "}"
|_______________________________________________________________________*/

class validate_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return validate_expr_kind; }
protected:
  enum ParseConstants::validation_mode_t valmode;
  expr_t expr_h;

public:
  validate_expr(
    const QueryLoc&,
    enum ParseConstants::validation_mode_t,
    expr_t);

public:
  expr_t get_expr() const { return expr_h; }
  enum ParseConstants::validation_mode_t get_valmode() const { return valmode; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

};



// [65] [http://www.w3.org/TR/xquery/#prod-xquery-ExtensionExpr]

struct pragma : public SimpleRCObject
{
  store::Item_t name_h;
  std::string content;

  pragma(store::Item_t _name_h, std::string const& _content)
 : name_h(_name_h), content(_content) {}
};


/*______________________________________________________________________
| ::= PragmaList "{" Expr? "}"
|_______________________________________________________________________*/

class extension_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return extension_expr_kind; }
protected:
  rchandle<pragma> pragma_h;
  expr_t expr_h;

public:
  extension_expr(
    const QueryLoc&);
  extension_expr(
    const QueryLoc&,
    expr_t);

public:
  void add(rchandle<pragma> _pragma_h) { pragma_h = _pragma_h; }
  void add(expr_t _expr_h) { expr_h = _expr_h; }

/*
  uint32_t size() const
    { return pragma_hv.size(); }

  rchandle<pragma> & operator[](int i)
    { return pragma_hv[i]; }
  rchandle<pragma> const& operator[](int i) const
    { return pragma_hv[i]; }

  std::vector<rchandle<pragma> >::const_iterator begin() const
    { return pragma_hv.begin(); }
  std::vector<rchandle<pragma> >::const_iterator end() const
    { return pragma_hv.end(); }
*/

public:
  expr_t get_expr() const { return expr_h; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
};



/*******************************************************************************

  [69] [http://www.w3.org/TR/xquery/#prod-xquery-RelativePathExpr]

  Formal Semantics [http://www.w3.org/TR/xquery-semantics]:
    /    == fn:root(self::node())
    /A   == fn:root(self::node())/A
    //A  == fn:root(self::node())/descendant-or-self::node()/A
    A//B == A/descendant-or-self::node()/B
  This implies that all path expressions are relative path expressions. So a
  relative path is defined as follows:

 RelativPathExpr ::= "/" | ("/" | "//")?  StepExpr (("/" | "//") StepExpr)*

  p:l == (match "p:l" (children $dot))
  p1:l1/p2:l2 == (for ( ($x (match "p1:l1" (children $dot))) )
                     (match "p2:l2" (children $x)))

********************************************************************************/
class relpath_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return relpath_expr_kind; }
protected:
  std::vector<expr_t> theSteps;

public:
  relpath_expr(const QueryLoc&);

	size_t size() const        { return theSteps.size(); }
	void add_back(expr_t step)   { theSteps.push_back(step); }
  void erase(ulong i)          { theSteps.erase(theSteps.begin() + i); }

	expr_t& operator[](int n)    { return theSteps[n]; }

  std::vector<expr_t>::const_iterator begin() const { return theSteps.begin(); }
  std::vector<expr_t>::const_iterator end()   const { return theSteps.end(); }
  std::vector<expr_t>::iterator begin() { return theSteps.begin(); }
  std::vector<expr_t>::iterator end()   { return theSteps.end(); }

  expr_iterator_data *make_iter ();
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  xqtref_t return_type_impl(static_context *sctx);
};


/*******************************************************************************

  [70] [http://www.w3.org/TR/xquery/#prod-xquery-StepExpr]

  StepExpr ::= AxisStep  |  FilterExpr

********************************************************************************/


/*******************************************************************************

  [71] [http://www.w3.org/TR/xquery/#prod-xquery-AxisStep]

  AxisStep ::= Axis NodeTest Predicate*

********************************************************************************/
class axis_step_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return axis_step_expr_kind; }
protected:
  axis_kind_t          theAxis;
  rchandle<match_expr> theNodeTest;
  checked_vector<expr_t>  thePreds;

public:
  axis_step_expr(const QueryLoc&);

public:
  axis_kind_t getAxis() const          { return theAxis; }
  void setAxis(axis_kind_t v)          { theAxis = v; }
  bool is_reverse_axis () const        { return is_reverse_axis (getAxis ()); }

  rchandle<match_expr> getTest() const { return theNodeTest; }
  void setTest(rchandle<match_expr> v) { theNodeTest = v; }

  expr_iterator_data *make_iter ();
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  xqtref_t return_type_impl(static_context *sctx);

public:
  static bool is_reverse_axis (axis_kind_t kind);
};


/*******************************************************************************

  [78] NodeTest ::= KindTest | NameTest

  [79] NameTest ::= QName | Wildcard
  [80] Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)

  [123] KindTest ::= DocumentTest | ElementTest | AttributeTest |
                     SchemaElementTest | SchemaAttributeTest |
                     PITest | CommentTest | TextTest | AnyKindTest

  If a match_expr represents a KindTest, then theWildKind and theWildName data
  members are not used. If a match_expr represents a NameTest, then theTypeName
  and theNilledAllowed data members are not used.

********************************************************************************/
class match_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return match_expr_kind; }
protected:
  match_test_t  theTestKind;
  match_test_t  theDocTestKind;

  match_wild_t  theWildKind;
  xqp_string    theWildName;

  store::Item_t        theQName;
  store::Item_t        theTypeName;
  bool          theNilledAllowed;

public:
  match_expr(const QueryLoc&);

  match_test_t getTestKind() const         { return theTestKind; }
  match_test_t getDocTestKind() const      { return theDocTestKind; }
  void setTestKind(enum match_test_t v)    { theTestKind = v; }
  void setDocTestKind(enum match_test_t v) { theDocTestKind = v; }

  match_wild_t getWildKind() const         { return theWildKind; }
  const xqp_string& getWildName() const    { return theWildName; }
  void setWildKind(enum match_wild_t v)    { theWildKind = v; }
  void setWildName(const xqp_string& v)    { theWildName = v; } 

  store::Item_t getQName() const                  { return theQName; }
  store::Item_t getTypeName() const               { return theTypeName; }
  bool getNilledAllowed() const            { return theNilledAllowed; }
  void setQName(store::Item_t v)                  { theQName = v; }
  void setTypeName(store::Item_t v)               { theTypeName = v; }
  void setNilledAllowed(bool v)            { theNilledAllowed = v; }

  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  store::StoreConsts::NodeKind getNodeKind() const;

  xqtref_t return_type_impl(static_context *sctx);
};



// [84] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]
/*______________________________________________________________________
| primary_expr ::=
|       Literal
|     | VarRef
|     | ParenthesizedExpr
|     | ContextItemExpr
|     | FunctionCall
|     | Constructor
|     | OrderedExpr
|     | UnorderedExpr
|_______________________________________________________________________*/



// [85] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]

/*______________________________________________________________________
| ::= NumericLiteral | StringLiteral
|_______________________________________________________________________*/

class const_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return const_expr_kind; }
protected:
  store::Item_t val;

public:
  const_expr(const QueryLoc&, xqpString sval);
  const_expr(const QueryLoc&, xqp_integer);
  const_expr(const QueryLoc&, xqp_decimal);
  const_expr(const QueryLoc&, xqp_double);
  const_expr(const QueryLoc&, xqp_boolean);
  const_expr(const QueryLoc&, store::Item_t);  
  const_expr(const QueryLoc&, const char* aNamespace, const char* aPrefix, const char* aLocal);

public:
  store::Item_t get_val () const { return val; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
  virtual xqtref_t return_type_impl(static_context *sctx);
};



// [87] [http://www.w3.org/TR/xquery/#prod-xquery-VarRef]
// [91] [http://www.w3.org/TR/xquery/#prod-xquery-OrderedExpr]

/*______________________________________________________________________
| ::= ORDERED_LBRACE  Expr  RBRACE
|     | UNORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/

class order_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return order_expr_kind; }

  enum order_type_t {
    ordered,
    unordered
  };

protected:
  order_type_t type;
  expr_t expr_h;

public:
  order_expr(
    const QueryLoc&,
    order_type_t,
    expr_t);

public:
  order_type_t get_type() const { return type; }
  expr_t get_expr() const { return expr_h; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual xqtref_t return_type_impl(static_context *sctx);
};



// [93] [http://www.w3.org/TR/xquery/#prod-xquery-FunctionCall]
/*______________________________________________________________________
| ::= QNAME  LPAR  ArgList  RPAR  
|                                 gn:parensXQ
|                                 gn:reserved-function-namesXQ 
|_______________________________________________________________________*/


// [96] [http://www.w3.org/TR/xquery/#doc-xquery-DirElemConstructor]

class elem_expr : public constructor_expr {
public:
  expr_kind_t get_expr_kind () { return elem_expr_kind; }
protected:
  expr_t theQNameExpr;
  expr_t theAttrs;
  expr_t theContent;
  rchandle<namespace_context> theNSCtx;
  
public:
  elem_expr(
    const QueryLoc&,
    expr_t aQNameExpr,
    expr_t aAttrs,
    expr_t aContent,
    rchandle<namespace_context> aNSCtx);
  
  elem_expr(
    const QueryLoc&,
    expr_t aQNameExpr,
    expr_t aContent,
    rchandle<namespace_context> aNSCtx);
  
  
  expr_t getQNameExpr() const { return theQNameExpr; }
  void setQNameExpr(expr_t aQNameExpr) { theQNameExpr = aQNameExpr; }
  expr_t getContent() const { return theContent; }
  expr_t getAttrs() const { return theAttrs; }
  rchandle<namespace_context> getNSCtx();
  
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  xqtref_t return_type_impl (static_context *);
};



// [110] [http://www.w3.org/TR/xquery/#prod-xquery-CompDocConstructor]

/*______________________________________________________________________
| ::= DOCUMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/

class doc_expr : public constructor_expr {
public:
  expr_kind_t get_expr_kind () { return doc_expr_kind; }
protected:
  expr_t theContent;

public:
  doc_expr(
    const QueryLoc&,
    expr_t aContent);

public:
  expr_t getContent() const { return theContent; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual xqtref_t return_type_impl(static_context *sctx);

};



// // [111] [http://www.w3.org/TR/xquery/#prod-xquery-CompElemConstructor]


/******************************************************************************

  DirAttConstructor ::= QNAME EQUALS DirAttributeValue

  // [113] [http://www.w3.org/TR/xquery/#prod-xquery-CompAttrConstructor]

  CompAttConstructor ::= ATTRIBUTE  QNAME  LBRACE  RBRACE |
                         ATTRIBUTE  QNAME  LBRACE  Expr  RBRACE |
                         ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  RBRACE |
                         ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE

********************************************************************************/
class attr_expr : public constructor_expr {
public:
  expr_kind_t get_expr_kind () { return attr_expr_kind; }
protected:
  expr_t theQNameExpr;
  expr_t theValueExpr;

public:
  attr_expr(
    const QueryLoc& loc,
    expr_t aQNameExpr,
    expr_t aValueExpr);


public:
  expr_t getQNameExpr() const { return theQNameExpr; }
  void setQNameExpr(expr_t aQNameExpr) { theQNameExpr = aQNameExpr; }
  expr_t getValueExpr() const { return theValueExpr; }
  void setValueExpr(expr_t aValueExpr) { theValueExpr = aValueExpr; }

  store::Item* getQName() const;

  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual xqtref_t return_type_impl(static_context *sctx);

};



// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompTextConstructor]

/*______________________________________________________________________
| ::= TEXT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/

class text_expr : public constructor_expr {
public:
  expr_kind_t get_expr_kind () { return text_expr_kind; }

  typedef enum { text_constructor, comment_constructor, pi_constructor }
    text_constructor_type;

protected:
  text_constructor_type type;
  expr_t text;

public:
  text_expr(
    const QueryLoc&,
    text_constructor_type,
    expr_t);

public:
  expr_t get_text () const { return text; }
  text_constructor_type get_type () const { return type; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual xqtref_t return_type_impl(static_context *sctx);
};



// [115] [http://www.w3.org/TR/xquery/#prod-xquery-CompCommentConstructor]
/*______________________________________________________________________
| ::= COMMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/


// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompPIConstructor]

/*______________________________________________________________________
 |      ::= PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
 |                      |       PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RB
 |                      |       PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBR
 |                      |       PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBR
 |_______________________________________________________________________*/

class pi_expr : public text_expr {
public:
  expr_kind_t get_expr_kind () { return pi_expr_kind; }
protected:
  expr_t target_expr_h;
  
public:
  pi_expr (const QueryLoc&,
           expr_t,
           expr_t);
  
public:
  expr_t get_target_expr() const { return target_expr_h; }
  
public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
};

/* (some proposed optimizer interface methods:)
public: 
  typedef pair<var_expr*,expr*> substitution;
  typedef std::vector<substitution> subst_list;

public:
  rchandle<expr> clone() const;
  rchandle<expr> clone(subst_list) const;
  void sub(substitution);
  list<var_expr*> variables() const;  // free variables
  list<fo_expr*> functions() const;   // return all function calls
  rchandle<substitution> resolve(expr*, expr*);     // return subst_list expression match
  void resolve(expr*, expr*, rchandle<subst_list>); // return subst_list expression match
  void traverse(void* (*op) (void*), int flags);
*/

/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	Update expressions                                                 //
//  [http://www.w3.org/TR/xqupdate/]                                   //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

// [242] [http://www.w3.org/TR/xqupdate/#prod-xquery-InsertExpr]
class insert_expr : public expr
/*______________________________________________________________________
|	::= DO_INSERT  ExprSingle  INTO  ExprSingle
|			|	DO_INSERT  ExprSingle  AS  FIRST_INTO  ExprSingle
|			|	DO_INSERT  ExprSingle  AS  LAST_INTO  ExprSingle
|			| DO_INSERT  ExprSingle  AFTER  ExprSingle
|			| DO_INSERT  ExprSingle  BEFORE  ExprSingle
|_______________________________________________________________________*/
{
protected:
  store::UpdateConsts::InsertType theType;
	expr_t theSourceExpr;
	expr_t theTargetExpr;

public:
	insert_expr(
		const QueryLoc&,
    store::UpdateConsts::InsertType,
		expr_t,
		expr_t);
	virtual ~insert_expr();

public:
  store::UpdateConsts::InsertType getType() const { return theType; }
	expr_t getSouceExpr() const { return theSourceExpr; }
	expr_t getTargetExpr() const { return theTargetExpr; }
  

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
	std::ostream& put(std::ostream&) const;

};



// [243] [http://www.w3.org/TR/xqupdate/#prod-xquery-DeleteExpr]
class delete_expr : public expr
/*______________________________________________________________________
|	::= DO_DELETE  expr
|_______________________________________________________________________*/
{
protected:
	expr_t theTargetExpr;

public:
	delete_expr(
		const QueryLoc&,
		expr_t);
	virtual ~delete_expr();

public:
	expr_t getTargetExpr() const { return theTargetExpr; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
	std::ostream& put(std::ostream&) const;
};



// [244] [http://www.w3.org/TR/xqupdate/#prod-xquery-ReplaceExpr]
class replace_expr : public expr
/*______________________________________________________________________
|	::= DO_REPLACE  expr  WITH  expr
|			| DO_REPLACE  VALUE_OF  expr  WITH  expr
|_______________________________________________________________________*/
{
protected:
  store::UpdateConsts::ReplaceType theType;
	expr_t theTargetExpr;
	expr_t theReplaceExpr;

public:
	replace_expr(
		const QueryLoc&,
    store::UpdateConsts::ReplaceType aType,
		expr_t,
		expr_t);
	virtual ~replace_expr();

public:
  store::UpdateConsts::ReplaceType getType() const { return theType; }
	expr_t getTargetExpr() const { return theTargetExpr; }
	expr_t getReplaceExpr() const { return theReplaceExpr; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
	std::ostream& put(std::ostream&) const;

};



// [245] [http://www.w3.org/TR/xqupdate/#prod-xquery-RenameExpr]
class rename_expr : public expr
/*______________________________________________________________________
|	::= DO_RENAME  expr  AS  expr
|_______________________________________________________________________*/
{
protected:
	expr_t theTargetExpr;
	expr_t theNameExpr;

public:
	rename_expr(
		const QueryLoc&,
		expr_t,
		expr_t);
	virtual ~rename_expr();

public:
	expr_t getTargetExpr() const { return theTargetExpr; }
	expr_t getNameExpr() const { return theTargetExpr; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
	std::ostream& put(std::ostream&) const;

};


class copy_clause : public SimpleRCObject
{
  friend class transform_expr;
private:
  rchandle<var_expr> theVar;
  expr_t             theExpr;

public:
  copy_clause(rchandle<var_expr> aVar, expr_t aExpr);

  rchandle<var_expr> getVar()  const { return theVar; }
  expr_t             getExpr() const { return theExpr; }

  std::ostream& put(std::ostream&) const;
};

// [249] [http://www.w3.org/TR/xqupdate/#prod-xquery-TransformExpr]
class transform_expr : public expr
/*______________________________________________________________________
|	::= TRANSFORM_COPY_DOLLAR  VarNameList
|				MODIFY  expr  RETURN  expr
|_______________________________________________________________________*/
{
public:
	typedef rchandle<var_expr> varref_t;

protected:
	std::vector<rchandle<copy_clause> > theCopyClauses;
	expr_t theModifyExpr;
	expr_t theReturnExpr;

public:
	transform_expr(
		const QueryLoc&,
		expr_t aModifyExpr,
		expr_t aReturnExpr);
	~transform_expr() {}

public:
	expr_t getModifyExpr() const { return theModifyExpr; }
	expr_t getReturnExpr() const { return theReturnExpr; }

public:
	void add(rchandle<copy_clause> aCopyClause)
  { theCopyClauses.push_back(aCopyClause); }

	rchandle<copy_clause>& operator[](int i)
  { return theCopyClauses[i]; }
	rchandle<copy_clause> const& operator[](int i) const
  { return theCopyClauses[i]; }

	std::vector<rchandle<copy_clause> >::const_iterator begin() const
  { return theCopyClauses.begin(); }
	std::vector<rchandle<copy_clause> >::iterator begin()
  { return theCopyClauses.begin(); }
	std::vector<rchandle<copy_clause> >::const_iterator end() const
  { return theCopyClauses.end(); }
	std::vector<rchandle<copy_clause> >::iterator end()
  { return theCopyClauses.end(); }
	size_t size() const
  { return theCopyClauses.size(); }

  expr_iterator_data *make_iter ();

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
	std::ostream& put(std::ostream&) const;

};

} /* namespace zorba */
#endif  /*  ZORBA_EXPR_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
