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
#ifndef ZORBA_EXPR_H
#define ZORBA_EXPR_H

#include <string>
#include <vector>
#include <set>
#include <map>

#include "zorbautils/checked_vector.h"

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"

#include "zorbaerrors/errors.h"

#include "compiler/expression/var_expr.h"
#include "compiler/expression/flwor_expr.h"

#include "context/static_context.h"
#include "context/namespace_context.h"
#include "types/node_test.h"
#include "types/typeimpl.h"

#include <zorba/store_consts.h>
#include "store/api/fullText/ft_options.h"
#include "store/api/update_consts.h"
#include "store/api/item.h" // TODO remove by putting functions and explicit destructors into the cpp file

#include "functions/signature.h"

namespace zorba {

class expr_visitor;
class NodeNameTest;
class match_expr;


/***************************************************************************//**
  imperative construct: do this, then that
********************************************************************************/
class sequential_expr : public expr
{
  checked_vector<expr_t> sequence;

public:
  SERIALIZABLE_CLASS(sequential_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(sequential_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & sequence;
  }
public:
  expr_kind_t get_expr_kind () const { return sequential_expr_kind; }

  sequential_expr(short sctx, const QueryLoc& loc)
    :
    expr (sctx, loc)
  {
  }

  sequential_expr(short sctx, const QueryLoc& loc, expr_t first, expr_t second)
    :
    expr (sctx, loc)
  {
    sequence.push_back (first);
    sequence.push_back (second);
  }

  sequential_expr(short sctx, const QueryLoc& loc, checked_vector<expr_t> seq, expr_t result)
    :
    expr (sctx, loc),
    sequence (seq)
  {
    sequence.push_back (result);
  }

  sequential_expr(short sctx, const QueryLoc& loc, checked_vector<expr_t> seq)
    :
    expr (sctx, loc),
    sequence (seq)
  {
  }

  unsigned size () const { return sequence.size (); }

  const expr_t &operator [] (int i) const { return sequence [i]; }
  expr_t &operator [] (int i) { invalidate (); return sequence [i]; }

  void push_back (expr_t expr) 
  {
    invalidate ();
    sequence.push_back(expr);
  }

  void push_front (expr_t front) 
  {
    invalidate ();
    sequence.insert (sequence.begin(), front);
  }

  bool is_updating_kind() const;

  bool cache_compliant () { return true; }

  virtual xqtref_t return_type_impl (static_context *);
  void compute_upd_seq_kind () const;

  expr_iterator_data *make_iter ();
  void next_iter (expr_iterator_data&);

  void accept (expr_visitor&);

  std::ostream& put(std::ostream&) const;

  virtual expr_t clone(substitution_t &s);
};


/***************************************************************************//**

********************************************************************************/
class constructor_expr : public expr 
{
protected:
  constructor_expr(short sctx, const QueryLoc& loc) : expr (sctx, loc) {}
public:
  SERIALIZABLE_ABSTRACT_CLASS(constructor_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(constructor_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
  }
};


class catch_clause : public SimpleRCObject 
{
  friend class trycatch_expr;
  public:
    typedef rchandle<NodeNameTest> nt_t;
    typedef std::vector<nt_t> nt_list_t;
  protected:
    nt_list_t nametests_h;
    varref_t errorcode_var_h;
    varref_t errordesc_var_h;
    varref_t errorobj_var_h;
    expr_t catch_expr_h;

  public:
    SERIALIZABLE_CLASS(catch_clause)
    SERIALIZABLE_CLASS_CONSTRUCTOR2(catch_clause, SimpleRCObject)
    void serialize(::zorba::serialization::Archiver &ar)
    {
      //serialize_baseclass(ar, (SimpleRCObject*)this);
      ar & nametests_h;
      ar & errorcode_var_h;
      ar & errordesc_var_h;
      ar & errorobj_var_h;
      ar & catch_expr_h;
    }
  public:
    catch_clause();

    void set_nametests(nt_list_t& a) { nametests_h = a; }
    nt_list_t& get_nametests() { return nametests_h; }

    void add_nametest_h(nt_t n) { nametests_h.push_back(n); }

    void set_errorcode_var_h(varref_t a) { errorcode_var_h = a; }
    varref_t get_errorcode_var_h() const { return errorcode_var_h; }

    void set_errordesc_var_h(varref_t a) { errordesc_var_h = a; }
    varref_t get_errordesc_var_h() const { return errordesc_var_h; }

    void set_errorobj_var_h(varref_t a) { errorobj_var_h = a; }
    varref_t get_errorobj_var_h() const { return errorobj_var_h; }

    void set_catch_expr_h(expr_t a) { catch_expr_h = a; }
    expr_t get_catch_expr_h() const { return catch_expr_h; }
};


class trycatch_expr : public expr 
{
public:
  expr_kind_t get_expr_kind () const { return trycatch_expr_kind; }

public:
    typedef rchandle<catch_clause> clauseref_t;

protected:
    expr_t try_expr_h;
    std::vector<clauseref_t> catch_clause_hv;

public:
  SERIALIZABLE_CLASS(trycatch_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(trycatch_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & try_expr_h;
    ar & catch_clause_hv;
  }
public:
    trycatch_expr(short sctx, const QueryLoc&);

    expr_t get_try_expr() const
    { return try_expr_h; }
    void set_try_expr(expr_t e_h)
    { try_expr_h = e_h; }

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

    expr_iterator_data *make_iter ();

    void next_iter (expr_iterator_data&);
    void accept (expr_visitor&);
    std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class eval_expr : public expr 
{
public:
  class eval_var : public ::zorba::serialization::SerializeBaseClass
  {
  public:
    store::Item_t varname;
    std::string var_key;
    xqtref_t type;
    expr_t val;
  public:
    SERIALIZABLE_CLASS(eval_var)
    SERIALIZABLE_CLASS_CONSTRUCTOR(eval_var)
    void serialize(::zorba::serialization::Archiver &ar)
    {
      ar & varname;
      ar & var_key;
      ar & type;
      ar & val;
    }

    eval_var() {}
    eval_var (var_expr *ve, expr_t val);
    virtual ~eval_var() {}
  };

protected:
  expr_t expr_h;
  checked_vector<eval_var> vars;

public:
  SERIALIZABLE_CLASS(eval_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(eval_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & expr_h;
    ar & vars;
  }
public:
  expr_kind_t get_expr_kind () const { return eval_expr_kind; }

  eval_expr (short sctx, const QueryLoc &loc, expr_t expr_)
    : expr (sctx, loc), expr_h (expr_)
  {}

  checked_vector<eval_var> &get_vars () { return vars; }

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

#ifdef ZORBA_DEBUGGER
//debugger expression
class debugger_expr: public eval_expr
{
public:
  expr_kind_t get_expr_kind () const { return debugger_expr_kind; }

private:
    std::list<global_binding> theGlobals;
    bool theForExpr;
    
public:
    debugger_expr(short sctx, const QueryLoc& loc, expr_t aChild, std::list<global_binding> aGlobals ):
      eval_expr(sctx, loc, aChild ), theGlobals( aGlobals ){}
    
  debugger_expr( short sctx, const QueryLoc& loc, expr_t aChild,
                 checked_vector<varref_t> aScopedVariables,
                 std::list<global_binding> aGlobals,
                 bool aForExpr = false):
    eval_expr(sctx, loc, aChild ), theGlobals( aGlobals ), theForExpr(aForExpr)
  {
    store_local_variables( aScopedVariables );
  }

  expr_iterator_data *make_iter();
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  std::list<global_binding> getGlobals() const
  {
    return theGlobals;
  }

  bool isForExpr() const { return theForExpr; }

private:
  void store_local_variables(checked_vector<varref_t> &aScopedVariables)
  {
    std::set<store::Item_t> lQNames;
    checked_vector<varref_t>::reverse_iterator it;
    for ( it = aScopedVariables.rbegin(); it != aScopedVariables.rend(); ++it )
    {
      if ( lQNames.find( (*it)->get_varname() ) == lQNames.end() )
      {
        lQNames.insert( (*it)->get_varname() );
        varref_t lValue = (*it);
        varref_t lVariable( new var_expr( context, loc, var_expr::eval_var, lValue->get_varname() ) );
        lVariable->set_type( lValue->get_type() );
        add_var(eval_expr::eval_var(&*lVariable, lValue.getp()));
      }
    }
  }
};
#endif  // ZORBA_DEBUGGER


/***************************************************************************//**

********************************************************************************/
class wrapper_expr : public expr 
{
  expr_t wrapped;

public:
  SERIALIZABLE_CLASS(wrapper_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(wrapper_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & wrapped;
  }
public:
  wrapper_expr (short sctx, const QueryLoc& loc_, expr_t wrapped_)
    :
    expr (sctx, loc_),
    wrapped (wrapped_)
  {
  }

  expr_kind_t get_expr_kind () const { return wrapper_expr_kind; }

  expr_t get_expr() const { return wrapped; }

  void set_expr(expr* e) { wrapped = e; }

  void next_iter (expr_iterator_data&);

  void accept (expr_visitor&);

  xqtref_t return_type_impl (static_context *sctx);

  virtual expr_t clone(substitution_t &s);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
// [42] [http://www.w3.org/TR/xquery/#prod-xquery-QuantifiedExpr]

// [43] [http://www.w3.org/TR/xquery/#prod-xquery-TypeswitchExpr]

class case_clause : public SimpleRCObject {
  friend class typeswitch_expr;
protected:
  expr_t var_h;
  expr_t case_expr_h;
  xqtref_t type;

public:
  SERIALIZABLE_CLASS(case_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(case_clause, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & var_h;
    ar & case_expr_h;
    ar & type;
  }
public:
  case_clause();

  void set_var_h(varref_t a) { var_h = a.getp(); }
  varref_t get_var_h() const { 
    return varref_t(static_cast<var_expr*>(var_h.getp())); 
  }

  void set_case_expr_h(expr_t a) { case_expr_h = a; }
  expr_t get_case_expr_h() const { return case_expr_h; }

  void set_type(xqtref_t a) { type = a; }
  xqtref_t get_type() const { return type; }

};


/***************************************************************************//**
  Base for cast, treat, promote, castable, instanceof
********************************************************************************/
class cast_or_castable_base_expr : public expr {
protected:
  expr_t input_expr_h;
  xqtref_t target_type;

protected:
  cast_or_castable_base_expr(short sctx, const QueryLoc& loc, expr_t input, xqtref_t type);
  
public:
  SERIALIZABLE_ABSTRACT_CLASS(cast_or_castable_base_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(cast_or_castable_base_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & input_expr_h;
    ar & target_type;
  }
public:
  bool cache_compliant () { return true; }

  expr_t get_input() { invalidate (); return input_expr_h; }

  void set_input(expr_t input) { invalidate (); input_expr_h = input; }
  
  xqtref_t get_target_type() const;

  void set_target_type(xqtref_t target);
};


/***************************************************************************//**
  Base for cast, treat, promote
********************************************************************************/
class cast_base_expr : public cast_or_castable_base_expr {
public:
  cast_base_expr(short sctx, const QueryLoc& loc, expr_t input, xqtref_t type);

  xqtref_t return_type_impl (static_context *sctx);
public:
  SERIALIZABLE_ABSTRACT_CLASS(cast_base_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(cast_base_expr, cast_or_castable_base_expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (cast_or_castable_base_expr*)this);
  }
};


/***************************************************************************//**
  Base for castable, instanceof
********************************************************************************/
class castable_base_expr : public cast_or_castable_base_expr {
protected:
  castable_base_expr (short sctx, const QueryLoc&, expr_t, xqtref_t);

public:
  xqtref_t return_type_impl (static_context *sctx);
public:
  SERIALIZABLE_ABSTRACT_CLASS(castable_base_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(castable_base_expr, cast_or_castable_base_expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (cast_or_castable_base_expr*)this);
  }
};


/***************************************************************************//**
  CastExpr ::= UnaryExpr ( "cast" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
class cast_expr : public cast_base_expr {
public:
  cast_expr(
    short sctx, 
    const QueryLoc&,
    expr_t,
    xqtref_t);

  expr_kind_t get_expr_kind () const { return cast_expr_kind; }

  bool is_optional() const;

  expr_t clone (substitution_t& s);

  void next_iter (expr_iterator_data&);

  void accept (expr_visitor&);

  std::ostream& put(std::ostream&) const;
public:
  SERIALIZABLE_CLASS(cast_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(cast_expr, cast_base_expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (cast_base_expr*)this);
  }
};


/***************************************************************************//**
  CastableExpr ::= CastExpr ( "castable" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
class castable_expr : public castable_base_expr {
public:
  expr_kind_t get_expr_kind () const { return castable_expr_kind; }

public:
  SERIALIZABLE_CLASS(castable_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(castable_expr, castable_base_expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (castable_base_expr*)this);
  }
public:
  castable_expr(
    short sctx, 
    const QueryLoc&,
                   expr_t,
                   xqtref_t);

public:
  bool is_optional() const;

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
  expr_t clone (substitution_t& s);
};


/***************************************************************************//**
	TreatExpr ::= CastableExpr ( "treat" "as" SequenceType )?
********************************************************************************/
class treat_expr : public cast_base_expr {
protected:
  XQUERY_ERROR err;
  bool check_prime;

public:
  SERIALIZABLE_CLASS(treat_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(treat_expr, cast_base_expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (cast_base_expr*)this);
    SERIALIZE_ENUM(XQUERY_ERROR, err);
    ar & check_prime;
  }
public:
  expr_kind_t get_expr_kind () const { return treat_expr_kind; }
  treat_expr(
    short sctx, 
    const QueryLoc&,
    expr_t,
    xqtref_t,
    XQUERY_ERROR,
    bool check_prime = true);

  XQUERY_ERROR get_err () { return err; }
  bool get_check_prime () { return check_prime; }
  void set_check_prime (bool check_prime_) { check_prime = check_prime_; }

  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
  xqtref_t return_type_impl (static_context *sctx);  
  expr_t clone (substitution_t& s);
};


/***************************************************************************//**
	InstanceofExpr ::= TreatExpr ( "instance" "of" SequenceType )?
********************************************************************************/
class instanceof_expr : public castable_base_expr {
public:

protected:
  bool forced;  // error if not instance?

public:
  SERIALIZABLE_CLASS(instanceof_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(instanceof_expr, castable_base_expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (castable_base_expr*)this);
    ar & forced;
  }
public:
  instanceof_expr (short sctx, 
                   const QueryLoc&,
    expr_t,
    xqtref_t);

  expr_kind_t get_expr_kind () const { return instanceof_expr_kind; }

  bool isForced () { return forced; }

  expr_t clone (substitution_t& s);

  void next_iter (expr_iterator_data&);

  void accept (expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/***************************************************************************//**

********************************************************************************/
class promote_expr : public cast_base_expr {
public:
  expr_kind_t get_expr_kind () const { return promote_expr_kind; }

  promote_expr(short sctx, const QueryLoc& loc, expr_t input, xqtref_t type);
  xqtref_t return_type_impl (static_context *sctx);

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
  expr_t clone (substitution_t& s);
public:
  SERIALIZABLE_CLASS(promote_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(promote_expr, cast_base_expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (cast_base_expr*)this);
  }
};


/***************************************************************************//**

********************************************************************************/
class name_cast_expr : public expr {
private:
  expr_t input_expr_h;
  NamespaceContext_t theNCtx;
public:
  SERIALIZABLE_CLASS(name_cast_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(name_cast_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar);
public:
  name_cast_expr (
    short sctx,
    const QueryLoc&,
    expr_t,
    NamespaceContext_t);

  expr_kind_t get_expr_kind () const { return name_cast_expr_kind; }
  expr_t get_input() { return input_expr_h; }
  NamespaceContext_t getNamespaceContext();

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
  expr_t clone (substitution_t& s);
};


/***************************************************************************//**
 TypeswitchExpr ::= "typeswitch" "(" Expr ")"
                    CaseClause+
                    "default" ("$" VarName)? "return" ExprSingle

  CaseClause ::= "case" ("$" VarName "as")? SequenceType "return" ExprSingle
********************************************************************************/
class typeswitch_expr : public expr {
public:
  typedef rchandle<case_clause> clauseref_t;

protected:
  expr_t switch_expr_h;
  std::vector<clauseref_t> case_clause_hv;
  expr_t  default_var_h;
  expr_t default_clause_h;

  // typeswitch_expr is not fully supported, so prevent instantiation
  typeswitch_expr(short sctx, const QueryLoc&);

public:
  SERIALIZABLE_CLASS(typeswitch_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(typeswitch_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & switch_expr_h;
    ar & case_clause_hv;
    ar & default_var_h;
    ar & default_clause_h;
  }
public:
  expr_kind_t get_expr_kind () const { return typeswitch_expr_kind; }

  expr_t get_switch_expr() const { return switch_expr_h; }

  void set_switch_expr(expr_t e_h) { switch_expr_h = e_h; }
  
  varref_t get_default_varname() const
  { return varref_t(static_cast<var_expr*>(default_var_h.getp())); }

  void set_default_varname(varref_t const& var_h)
  { default_var_h = var_h.getp(); }

  expr_t get_default_clause() const { return default_clause_h; }

  void set_default_clause(expr_t const& e_h) { default_clause_h = e_h; }
  
  void add_clause(clauseref_t cc_h) { case_clause_hv.push_back(cc_h); }
  
  std::vector<clauseref_t>::const_iterator begin() const
  { return case_clause_hv.begin(); }

  std::vector<clauseref_t>::const_iterator end() const
  { return case_clause_hv.end(); }

  std::vector<clauseref_t>::iterator begin()
  { return case_clause_hv.begin(); }

  std::vector<clauseref_t>::iterator end()
  { return case_clause_hv.end(); }
  
  uint32_t clause_count() const { return case_clause_hv.size(); }
  
  clauseref_t & operator[](int i)  { return case_clause_hv[i]; }

  clauseref_t const& operator[](int i) const { return case_clause_hv[i]; }
  
  expr_iterator_data *make_iter ();
  
  void next_iter (expr_iterator_data&);

  void accept (expr_visitor&);

  std::ostream& put(std::ostream&) const;
};



/*______________________________________________________________________
| ::= <"if" "("> Expr ")" "then" ExprSingle "else" ExprSingle
|_______________________________________________________________________*/

class if_expr : public expr {
public:
  expr_kind_t get_expr_kind () const { return if_expr_kind; }
protected:
  expr_t cond_expr_h;
  expr_t then_expr_h;
  expr_t else_expr_h;

public:
  SERIALIZABLE_CLASS(if_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(if_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & cond_expr_h;
    ar & then_expr_h;
    ar & else_expr_h;
  }
public:
  if_expr(
    short sctx,
    const QueryLoc&,
    expr_t,
    expr_t,
    expr_t);

  if_expr(
    short sctx,
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
  void compute_upd_seq_kind () const;
  virtual expr_t clone(substitution_t &s);
};

class signature;


/***************************************************************************//**

********************************************************************************/
class function_def_expr : public expr {
protected:
  store::Item_t name;
  std::vector<rchandle<var_expr> > params;
  expr_t body;
  std::auto_ptr<signature> sig;

  function_def_expr (short sctx,
                     const QueryLoc& loc,
                     store::Item_t name_,
                     std::vector<rchandle<var_expr> > &params_,
                     xqtref_t return_type_impl);

public:
  SERIALIZABLE_ABSTRACT_CLASS(function_def_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(function_def_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar);

public:

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


/***************************************************************************//**

********************************************************************************/
class fo_expr : public expr 
{
public:
  expr_kind_t get_expr_kind () const { return fo_expr_kind; }
protected:
  checked_vector<expr_t>   argv;
  const function         * func;

public:
  SERIALIZABLE_CLASS(fo_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(fo_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar);

public:
  fo_expr (short sctx, const QueryLoc& loc, const function *f)
   : expr(sctx, loc), func (f)  { assert (f != NULL); }

  fo_expr (short sctx, const QueryLoc& loc, const function *f, expr_t arg)
   : expr(sctx, loc), func (f)
  {
    assert (f != NULL);
    add (arg);
  }

  fo_expr (short sctx, const QueryLoc& loc, const function *f, expr_t arg1, expr_t arg2)
   : expr(sctx, loc), func (f)
  {
    assert (f != NULL);
    add (arg1); add (arg2);
  }

  fo_expr (short sctx, const QueryLoc& loc, const function *f, expr_t arg1, expr_t arg2, expr_t arg3)
   : expr(sctx, loc), func (f)
  {
    assert (f != NULL);
    add (arg1); add (arg2); add (arg3);
  }

  fo_expr (short sctx, const QueryLoc& loc, const function *f, const std::vector<expr_t>& args)
   : expr(sctx, loc), argv(args), func(f)
  {
    assert (f != NULL);
  }

  static fo_expr *create_seq (short sctx, const QueryLoc &);
  bool is_concatenation () const;

  bool cache_compliant () { return true; }

  expr_iterator_data *make_iter ();
  
  void add(expr_t e) 
  {
    invalidate();
    assert(e != NULL);
    argv.push_back(e); 
  }

  void addFront(expr_t e) 
  {
    invalidate();
    assert(e != NULL);
    argv.insert(argv.begin(), e); 
  }

  uint32_t size() const { return argv.size(); }

  expr_t& operator[](int i) { invalidate (); return argv[i]; }
  const expr_t& operator[](int i) const { return argv[i]; }

  std::vector<expr_t>::const_iterator begin() const { return argv.begin(); }
  std::vector<expr_t>::const_iterator end() const { return argv.end(); }
  std::vector<expr_t>::iterator begin() { invalidate (); return argv.begin(); }
  std::vector<expr_t>::iterator end() { invalidate (); return argv.end(); }

  const function* get_func() const { return func; }
  void set_func (const function *f) { invalidate (); func = f; }
  const signature &get_signature () const;
  store::Item_t get_fname () const;

  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual xqtref_t return_type_impl(static_context *sctx);
  void compute_upd_seq_kind () const;
  virtual expr_t clone(substitution_t &s);
};


/*______________________________________________________________________
| ::= "validate" ValidationMode? "{" Expr "}"
|_______________________________________________________________________*/
/***************************************************************************//**

********************************************************************************/
class validate_expr : public expr {
public:
  expr_kind_t get_expr_kind () const { return validate_expr_kind; }
protected:
  ParseConstants::validation_mode_t valmode;
  store::Item_t typeName;
  rchandle<TypeManager> typemgr;
  expr_t expr_h;

public:
  SERIALIZABLE_CLASS(validate_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(validate_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    SERIALIZE_ENUM(ParseConstants::validation_mode_t, valmode);
    ar & typeName;
    SERIALIZE_TYPEMANAGER_RCHANDLE(TypeManager, typemgr);
    ar & expr_h;
  }
public:
  validate_expr(short sctx, const QueryLoc&, ParseConstants::validation_mode_t,
                store::Item_t aTypeName,
                expr_t, rchandle<TypeManager>);

public:
  expr_t get_expr() const { return expr_h; }
  store::Item_t get_type_name() { return typeName; }
  rchandle<TypeManager> get_typemgr () const { return typemgr; }
  ParseConstants::validation_mode_t get_valmode() const { return valmode; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual expr_t clone(substitution_t &s);
};



/***************************************************************************//**

********************************************************************************/
struct pragma : public SimpleRCObject
{
  store::Item_t name_h;
  std::string content;

  pragma(store::Item_t _name_h, std::string const& _content)
 : name_h(_name_h), content(_content) {}
public:
  SERIALIZABLE_CLASS(pragma)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(pragma, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & name_h;
    ar & content;
  }
};


/*______________________________________________________________________
| ::= PragmaList "{" Expr? "}"
|_______________________________________________________________________*/
/***************************************************************************//**

********************************************************************************/
class extension_expr : public expr {
public:
  expr_kind_t get_expr_kind () const { return extension_expr_kind; }
protected:
  rchandle<pragma> pragma_h;
  expr_t expr_h;

public:
  SERIALIZABLE_CLASS(extension_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(extension_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & pragma_h;
    ar & expr_h;
  }
public:
  extension_expr(
    short sctx,
    const QueryLoc&);
  extension_expr(
    short sctx,
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

  PathExpr ::= 	("/" RelativePathExpr?) |
                ("//" RelativePathExpr) |
                RelativePathExpr

  RelativePathExpr ::= StepExpr (("/" | "//") StepExpr)*


  Formal Semantics [http://www.w3.org/TR/xquery-semantics]:
    /    == fn:root(self::node())
    /A   == fn:root(self::node())/A
    //A  == fn:root(self::node())/descendant-or-self::node()/A
    A//B == A/descendant-or-self::node()/B
  This implies that all path expressions are relative path expressions. So a
  relative path is defined as follows:

 RelativPathExpr ::= "/" | ("/" | "//")?  StepExpr (("/" | "//") StepExpr)*

********************************************************************************/
class relpath_expr : public expr 
{
protected:
  std::vector<expr_t> theSteps;

public:
  SERIALIZABLE_CLASS(relpath_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(relpath_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & theSteps;
  }
public:
  relpath_expr(short sctx, const QueryLoc&);

  expr_kind_t get_expr_kind () const { return relpath_expr_kind; }

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
  expr_t clone (substitution_t &);
};


/*******************************************************************************

  StepExpr ::= AxisStep  |  FilterExpr

********************************************************************************/


/*******************************************************************************

  AxisStep ::= Axis NodeTest Predicate*

********************************************************************************/
class axis_step_expr : public expr 
{
protected:
  axis_kind_t             theAxis;
  expr_t                  theNodeTest;

public:
  SERIALIZABLE_CLASS(axis_step_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(axis_step_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    SERIALIZE_ENUM(axis_kind_t, theAxis);
    ar & theNodeTest;
  }
public:
  axis_step_expr(short sctx, const QueryLoc&);

  expr_kind_t get_expr_kind () const { return axis_step_expr_kind; }

  axis_kind_t getAxis() const          { return theAxis; }
  void setAxis(axis_kind_t v)          { theAxis = v; }
  bool is_reverse_axis () const        { return is_reverse_axis (getAxis ()); }

  rchandle<match_expr> getTest() const 
  {
    return reinterpret_cast<match_expr*>(theNodeTest.getp());
  }

  void setTest(rchandle<match_expr> v) { theNodeTest = v.getp(); }

  expr_iterator_data *make_iter ();
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  xqtref_t return_type_impl(static_context *sctx);
  expr_t clone (substitution_t &);

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
class match_expr : public expr 
{
protected:
  match_test_t  theTestKind;
  match_test_t  theDocTestKind;

  match_wild_t  theWildKind;
  xqp_string    theWildName;

  store::Item_t theQName;
  store::Item_t theTypeName;
  bool          theNilledAllowed;

public:
  SERIALIZABLE_CLASS(match_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(match_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    SERIALIZE_ENUM(match_test_t, theTestKind);
    SERIALIZE_ENUM(match_test_t, theDocTestKind);
    SERIALIZE_ENUM(match_wild_t, theWildKind);
    ar & theWildName;
    ar & theQName;
    ar & theTypeName;
    ar & theNilledAllowed;
  }
public:
  match_expr(short sctx, const QueryLoc&);

  expr_kind_t get_expr_kind () const       { return match_expr_kind; }

  match_test_t getTestKind() const         { return theTestKind; }
  void setTestKind(enum match_test_t v)    { theTestKind = v; }

  match_test_t getDocTestKind() const      { return theDocTestKind; }
  void setDocTestKind(enum match_test_t v) { theDocTestKind = v; }

  match_wild_t getWildKind() const         { return theWildKind; }
  void setWildKind(enum match_wild_t v)    { theWildKind = v; }

  const xqp_string& getWildName() const    { return theWildName; }
  void setWildName(const xqp_string& v)    { theWildName = v; } 

  store::Item* getQName() const            { return theQName.getp(); }
  void setQName(const store::Item_t& v)    { theQName = v; }

  store::Item* getTypeName() const         { return theTypeName.getp(); }
  void setTypeName(const store::Item_t& v) { theTypeName = v; }

  bool getNilledAllowed() const            { return theNilledAllowed; }
  void setNilledAllowed(bool v)            { theNilledAllowed = v; }

  store::StoreConsts::NodeKind getNodeKind() const;

  xqtref_t return_type_impl(static_context *sctx);

  expr_t clone (substitution_t &);

  void next_iter (expr_iterator_data&);

  void accept (expr_visitor&);

  std::ostream& put(std::ostream&) const;
};



/***************************************************************************//**

********************************************************************************/
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



/*______________________________________________________________________
| ::= NumericLiteral | StringLiteral
|_______________________________________________________________________*/
/***************************************************************************//**

********************************************************************************/
class const_expr : public expr 
{
public:
  expr_kind_t get_expr_kind () const { return const_expr_kind; }
protected:
  store::Item_t val;

public:
  SERIALIZABLE_CLASS(const_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(const_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & val;
  }
public:
  const_expr(short sctx, const QueryLoc&, xqpString sval);
  const_expr(short sctx, const QueryLoc&, xqp_integer);
  const_expr(short sctx, const QueryLoc&, xqp_decimal);
  const_expr(short sctx, const QueryLoc&, xqp_double);
  const_expr(short sctx, const QueryLoc&, xqp_boolean);
  const_expr(short sctx, const QueryLoc&, store::Item_t);  
  const_expr(short sctx, const QueryLoc&, const char* aNamespace, const char* aPrefix, const char* aLocal);

public:
  store::Item_t get_val () const { return val; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;
  virtual xqtref_t return_type_impl(static_context *sctx);
  virtual expr_t clone(substitution_t &s);
};



/*______________________________________________________________________
| ::= ORDERED_LBRACE  Expr  RBRACE
|     | UNORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
/***************************************************************************//**

********************************************************************************/
class order_expr : public expr {
public:
  expr_kind_t get_expr_kind () const { return order_expr_kind; }

  enum order_type_t {
    ordered,
    unordered
  };

protected:
  order_type_t type;
  expr_t expr_h;

public:
  SERIALIZABLE_CLASS(order_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(order_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    SERIALIZE_ENUM(order_type_t, type);
    ar & expr_h;
  }
public:
  order_expr(
    short sctx,
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

  virtual expr_t clone(substitution_t &s);
};


/*______________________________________________________________________
| ::= QNAME  LPAR  ArgList  RPAR  
|                                 gn:parensXQ
|                                 gn:reserved-function-namesXQ 
|_______________________________________________________________________*/


// [96] [http://www.w3.org/TR/xquery/#doc-xquery-DirElemConstructor]

class elem_expr : public constructor_expr {
public:
  expr_kind_t get_expr_kind () const { return elem_expr_kind; }
protected:
  expr_t theQNameExpr;
  expr_t theAttrs;
  expr_t theContent;
  rchandle<namespace_context> theNSCtx;
  
public:
  SERIALIZABLE_CLASS(elem_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(elem_expr, constructor_expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (constructor_expr*)this);
    ar & theQNameExpr;
    ar & theAttrs;
    ar & theContent;
    ar & theNSCtx;
  }
public:
  elem_expr(
    short sctx,
    const QueryLoc&,
    expr_t aQNameExpr,
    expr_t aAttrs,
    expr_t aContent,
    rchandle<namespace_context> aNSCtx);
  
  elem_expr(
    short sctx,
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

  virtual expr_t clone(substitution_t &s);  

  xqtref_t return_type_impl (static_context *);
};



/*______________________________________________________________________
| ::= DOCUMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
/***************************************************************************//**

********************************************************************************/
class doc_expr : public constructor_expr {
public:
  expr_kind_t get_expr_kind () const { return doc_expr_kind; }
protected:
  expr_t theContent;

public:
  SERIALIZABLE_CLASS(doc_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(doc_expr, constructor_expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (constructor_expr*)this);
    ar & theContent;
  }
public:
  doc_expr(
    short sctx,
    const QueryLoc&,
    expr_t aContent);

public:
  expr_t getContent() const { return theContent; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual expr_t clone(substitution_t &s);  

  virtual xqtref_t return_type_impl(static_context *sctx);

};



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
  expr_kind_t get_expr_kind () const { return attr_expr_kind; }
protected:
  expr_t theQNameExpr;
  expr_t theValueExpr;

public:
  SERIALIZABLE_CLASS(attr_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(attr_expr, constructor_expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (constructor_expr*)this);
    ar & theQNameExpr;
    ar & theValueExpr;
  }
public:
  attr_expr(
    short sctx,
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

  virtual expr_t clone(substitution_t &s);

  virtual xqtref_t return_type_impl(static_context *sctx);

};



/*______________________________________________________________________
| ::= TEXT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/

class text_expr : public constructor_expr {
public:
  expr_kind_t get_expr_kind () const { return text_expr_kind; }

  typedef enum { text_constructor, comment_constructor, pi_constructor }
    text_constructor_type;

protected:
  text_constructor_type type;
  expr_t text;

public:
  SERIALIZABLE_CLASS(text_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(text_expr, constructor_expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (constructor_expr*)this);
    SERIALIZE_ENUM(text_constructor_type, type);
    ar & text;
  }
public:
  text_expr(
    short sctx,
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

  virtual expr_t clone(substitution_t &s);  

  virtual xqtref_t return_type_impl(static_context *sctx);
};



/*______________________________________________________________________
| ::= COMMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/


/*______________________________________________________________________
 |      ::= PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
 |                      |       PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RB
 |                      |       PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBR
 |                      |       PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBR
 |_______________________________________________________________________*/

class pi_expr : public text_expr {
public:
  expr_kind_t get_expr_kind () const { return pi_expr_kind; }
protected:
  expr_t target_expr_h;

public:
  SERIALIZABLE_CLASS(pi_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(pi_expr, text_expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (text_expr*)this);
    ar & target_expr_h;
  }
public:
  pi_expr (short sctx,
           const QueryLoc&,
           expr_t,
           expr_t);
  
public:
  expr_t get_target_expr() const { return target_expr_h; }
  
public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual expr_t clone(substitution_t &s);  
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
  SERIALIZABLE_CLASS(insert_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(insert_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    SERIALIZE_ENUM(store::UpdateConsts::InsertType, theType);
    ar & theSourceExpr;
    ar & theTargetExpr;
  }
public:
	insert_expr(
    short sctx,
		const QueryLoc&,
    store::UpdateConsts::InsertType,
		expr_t aSourceExpr,
		expr_t aTargetExpr);

  expr_kind_t get_expr_kind () const { return insert_expr_kind; }

  store::UpdateConsts::InsertType getType() const { return theType; }
	expr_t getSourceExpr() const { return theSourceExpr; }
	expr_t getTargetExpr() const { return theTargetExpr; }
  
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
	std::ostream& put(std::ostream&) const;
  bool is_updating_kind() const { return true; }
  void compute_upd_seq_kind () const;

  virtual expr_t clone (substitution_t& s);
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
  SERIALIZABLE_CLASS(delete_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(delete_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & theTargetExpr;
  }
public:
	delete_expr(
    short sctx,
		const QueryLoc&,
		expr_t);

  expr_kind_t get_expr_kind () const { return delete_expr_kind; }

public:
	expr_t getTargetExpr() const { return theTargetExpr; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
	std::ostream& put(std::ostream&) const;
  bool is_updating_kind() const { return true; }
  void compute_upd_seq_kind () const;

  virtual expr_t clone (substitution_t& s);
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
  SERIALIZABLE_CLASS(replace_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(replace_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    SERIALIZE_ENUM(store::UpdateConsts::ReplaceType, theType);
    ar & theTargetExpr;
    ar & theTargetExpr;
  }
public:
	replace_expr(
    short sctx,
		const QueryLoc&,
    store::UpdateConsts::ReplaceType aType,
		expr_t,
		expr_t);

  expr_kind_t get_expr_kind () const { return replace_expr_kind; }

public:
  store::UpdateConsts::ReplaceType getType() const { return theType; }
	expr_t getTargetExpr() const { return theTargetExpr; }
	expr_t getReplaceExpr() const { return theReplaceExpr; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
	std::ostream& put(std::ostream&) const;
  bool is_updating_kind() const { return true; }
  void compute_upd_seq_kind () const;

  virtual expr_t clone (substitution_t& s);
};



class rename_expr : public expr
/*______________________________________________________________________
|	::= DO_RENAME  expr  AS  expr
|_______________________________________________________________________*/
{
protected:
	expr_t theTargetExpr;
	expr_t theNameExpr;

public:
  SERIALIZABLE_CLASS(rename_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(rename_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & theTargetExpr;
    ar & theNameExpr;
  }
public:
	rename_expr(
    short sctx,
		const QueryLoc&,
		expr_t,
		expr_t);
  expr_kind_t get_expr_kind () const { return rename_expr_kind; }

public:
	expr_t getTargetExpr() const { return theTargetExpr; }
	expr_t getNameExpr() const { return theNameExpr; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
	std::ostream& put(std::ostream&) const;
  bool is_updating_kind() const { return true; }
  void compute_upd_seq_kind () const;

  virtual expr_t clone (substitution_t& s);
};


/*******************************************************************************
  TransformExpr ::= "copy" "$" VarName ":=" ExprSingle
                    ("," "$" VarName ":=" ExprSingle)*
                    "modify"  ExprSingle "return" ExprSingle
********************************************************************************/
class copy_clause : public SimpleRCObject
{
  friend class transform_expr;
private:
  rchandle<var_expr> theVar;
  expr_t             theExpr;

public:
  SERIALIZABLE_CLASS(copy_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(copy_clause, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    ar & theVar;
    ar & theExpr;
  }

public:
  copy_clause(rchandle<var_expr> aVar, expr_t aExpr);

  rchandle<var_expr> getVar()  const { return theVar; }
  expr_t             getExpr() const { return theExpr; }

  std::ostream& put(std::ostream&) const;
};


class transform_expr : public expr
{
protected:
	std::vector<rchandle<copy_clause> > theCopyClauses;
	expr_t theModifyExpr;
	expr_t theReturnExpr;

public:
  SERIALIZABLE_CLASS(transform_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(transform_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & theCopyClauses;
    ar & theModifyExpr;
    ar & theReturnExpr;
  }
public:
	transform_expr(
    short sctx,
		const QueryLoc&,
		expr_t aModifyExpr,
		expr_t aReturnExpr);
  expr_kind_t get_expr_kind () const { return transform_expr_kind; }

public:
	expr_t getModifyExpr() const { return theModifyExpr; }
	expr_t getReturnExpr() const { return theReturnExpr; }

public:
	void add_front(rchandle<copy_clause> aCopyClause)
  { theCopyClauses.insert(theCopyClauses.begin(), aCopyClause); }

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

  void next_iter (expr_iterator_data&);

  void accept (expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


class exit_expr : public expr {
  expr_t val;

public:
  SERIALIZABLE_CLASS(exit_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(exit_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & val;
  }
public:
  exit_expr (short sctx, const QueryLoc &loc, expr_t val_)
    : expr (sctx, loc), val (val_)
  {}
  expr_kind_t get_expr_kind () const { return exit_expr_kind; }
  expr_t get_value () { return val; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
	std::ostream& put(std::ostream&) const;

  virtual expr_t clone(substitution_t &s);
};

class flowctl_expr : public expr {
public:
  enum action { BREAK, CONTINUE };

protected:
  enum action action;

public:
  SERIALIZABLE_CLASS(flowctl_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(flowctl_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    SERIALIZE_ENUM(enum action, action);
  }
public:
  flowctl_expr (short sctx, const QueryLoc &loc, enum action action_)
    : expr (sctx, loc), action (action_)
  {}
  expr_kind_t get_expr_kind () const { return flowctl_expr_kind; }
  enum action get_action () const { return action; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
	std::ostream& put(std::ostream&) const;

  virtual expr_t clone(substitution_t &s);
};

class while_expr : public expr {
  expr_t body;

public:
  SERIALIZABLE_CLASS(while_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(while_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & body;
  }
public:
  while_expr (short sctx, const QueryLoc &loc, expr_t body_)
    : expr (sctx, loc), body (body_)
  {}
  expr_kind_t get_expr_kind () const { return while_expr_kind; }
  expr_t get_body () { return body; }

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
	std::ostream& put(std::ostream&) const;

  virtual expr_t clone(substitution_t &s);
};


class ft_select_expr : public expr 
{
public:
  ft_select_expr (short sctx, const QueryLoc &loc) : expr (sctx, loc) {}
public:
  SERIALIZABLE_ABSTRACT_CLASS(ft_select_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ft_select_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
  }
};


class ft_contains_expr : public expr 
{
protected:
  expr_t range_h;
  expr_t ft_select_h;
  expr_t ft_ignore_h;

public:
  SERIALIZABLE_ABSTRACT_CLASS(ft_contains_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ft_contains_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & range_h;
    ar & ft_select_h;
    ar & ft_ignore_h;
  }
public:
  ft_contains_expr(
        short sctx,
        const QueryLoc&,
        expr_t,
        expr_t,
        expr_t);

  expr_t get_range() const { return range_h; }
  expr_t get_ft_select() const { return ft_select_h; }
  expr_t get_ignore() const { return ft_ignore_h; }

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
