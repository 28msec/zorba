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

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "context/static_context_consts.h"
#include "context/namespace_context.h"
#include "context/dynamic_context.h"

#include "compiler/expression/expr.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/expression/expr_visitor.h"

#include "system/globalenv.h"
#include "functions/function.h"

#include "util/tracer.h"

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"

#include "types/root_typemanager.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"

using namespace std;
namespace zorba {
  
#define ITEM_FACTORY (GENV.getStore().getItemFactory())

  static QueryLoc null_loc;

  static expr_t dummy_expr;
  static expr_t *expr_iter_done = &dummy_expr;

#define BEGIN_EXPR_ITER() switch (v.state) { case 0:
#define BEGIN_EXPR_ITER2( type )                                        \
  type##_iterator_data &vv = dynamic_cast<type##_iterator_data &> (v);  \
  BEGIN_EXPR_ITER()
#define END_EXPR_ITER()   v.i = expr_iter_done; }
#define ITER( m )                                                \
  do {                                                           \
    v.state = __LINE__; v.i = reinterpret_cast<expr_t *> (&(m)); \
    if ((m) != NULL) { invalidate (); return; }                  \
  case __LINE__:; } while (0)
#define ITER_FOR_EACH( iter, begin, end, expr )                      \
  for (vv.iter = (begin); vv.iter != (end); ++(vv.iter))  {          \
    ITER (expr);                                                     \
  }

// Other iterators

bool expr_iterator_data::done () const { return i == expr_iter_done; }

class fo_expr_iterator_data : public expr_iterator_data {
public:
  std::vector<expr_t>::iterator arg_iter;
  
public:
  fo_expr_iterator_data (expr *e_) : expr_iterator_data (e_) {}
};

class flwor_expr_iterator_data : public expr_iterator_data {
public:
  flwor_expr::clause_list_t::iterator clause_iter;
  flwor_expr::group_list_t::iterator group_iter;
  flwor_expr::group_list_t::iterator non_group_iter;
  flwor_expr::orderspec_list_t::iterator order_mod_iter;
  
public:
  flwor_expr_iterator_data (expr *e_) : expr_iterator_data (e_) {}
};

class trycatch_expr_iterator_data : public expr_iterator_data {
public:
  std::vector<trycatch_expr::clauseref_t>::const_iterator clause_iter;

  trycatch_expr_iterator_data (expr *e_) : expr_iterator_data (e_) {}
};

class typeswitch_expr_iterator_data : public expr_iterator_data {
public:
  std::vector<typeswitch_expr::clauseref_t>::const_iterator clause_iter;

  typeswitch_expr_iterator_data (expr *e_) : expr_iterator_data (e_) {}
};

class relpath_expr_iterator_data : public expr_iterator_data {
public:
  std::vector<expr_t>::iterator step_iter;

  relpath_expr_iterator_data (expr *e_) : expr_iterator_data (e_) {}
};

class axis_step_expr_iterator_data : public expr_iterator_data {
public:
  std::vector<expr_t>::iterator pred_iter;

  axis_step_expr_iterator_data (expr *e_) : expr_iterator_data (e_) {}
};

class transform_expr_iterator_data : public expr_iterator_data {
public:
  std::vector<rchandle<copy_clause> >::iterator clause_iter;
  transform_expr_iterator_data (expr *e_) : expr_iterator_data(e_) {}
};


class eval_expr_iterator_data : public expr_iterator_data {
public:
  checked_vector<eval_expr::eval_var>::iterator var_iter;

  eval_expr_iterator_data (expr *e_) : expr_iterator_data (e_) {}
};

class sequential_expr_iterator_data : public expr_iterator_data {
public:
  checked_vector<expr_t>::iterator iter;

  sequential_expr_iterator_data (expr *e_) : expr_iterator_data (e_) {}
};

#define DEF_ACCEPT( type )                         \
  void type::accept (expr_visitor &v) {            \
    if (v.begin_visit (*this))                     \
      accept_children (v);                         \
    v.end_visit (*this);                           \
  }

DEF_ACCEPT (expr)
#ifdef ZORBA_DEBUGGER
DEF_ACCEPT (debugger_expr)
#endif
DEF_ACCEPT (sequential_expr)
DEF_ACCEPT (var_expr)
DEF_ACCEPT (flwor_expr)
DEF_ACCEPT (promote_expr)
DEF_ACCEPT (trycatch_expr)
DEF_ACCEPT (eval_expr)
DEF_ACCEPT (typeswitch_expr)
DEF_ACCEPT (if_expr)
DEF_ACCEPT (function_def_expr)
DEF_ACCEPT (fo_expr)
DEF_ACCEPT (ft_contains_expr)
DEF_ACCEPT (instanceof_expr)
DEF_ACCEPT (treat_expr)
DEF_ACCEPT (castable_expr)
DEF_ACCEPT (cast_expr)
DEF_ACCEPT (name_cast_expr)
DEF_ACCEPT (validate_expr)
DEF_ACCEPT (extension_expr)
DEF_ACCEPT (relpath_expr)
DEF_ACCEPT (axis_step_expr)
DEF_ACCEPT (match_expr)
DEF_ACCEPT (const_expr)
DEF_ACCEPT (order_expr)
DEF_ACCEPT (elem_expr)
DEF_ACCEPT (doc_expr)
DEF_ACCEPT (attr_expr)
DEF_ACCEPT (text_expr)
DEF_ACCEPT (pi_expr)
DEF_ACCEPT (insert_expr)
DEF_ACCEPT (delete_expr)
DEF_ACCEPT (rename_expr)
DEF_ACCEPT (replace_expr)
DEF_ACCEPT (transform_expr)
DEF_ACCEPT (exit_expr)
DEF_ACCEPT (flowctl_expr)
DEF_ACCEPT (while_expr)

#undef DEF_ACCEPT

expr_iterator::expr_iterator (const expr_iterator &other) : iter (new expr_iterator_data (*other.iter)) {}
  expr_iterator &expr_iterator::operator= (const expr_iterator &other) {
    if (this != &other) {
      delete iter;
      iter = new expr_iterator_data (*other.iter);
    }
    return *this;
  }
  expr_iterator &expr_iterator::operator++ () { iter->next (); return *this; }
  expr_iterator expr_iterator::operator++ (int) { expr_iterator old; old = *this; ++*this; return old; }
  expr_t &expr_iterator::operator* () { return *(iter->i); }
  bool expr_iterator::done () const { return iter->done (); }
  expr_iterator::~expr_iterator () { delete iter; }

  
  expr::expr(const QueryLoc& _loc)
    : loc(_loc)
  {
    invalidate ();
  }
  
  expr::~expr() {}
  
  string expr::toString () const {
    ostringstream oss;
    put (oss);
    return oss.str ();
  }

  expr_iterator_data *expr::make_iter () {
    return new expr_iterator_data (this);
  }
  
  void expr::accept_children (expr_visitor &v) {
    for (expr_iterator i = expr_begin (); ! i.done (); ++i) {
      if (*i != NULL)
        (*i)->accept (v);
    }
  }

  expr_iterator expr::expr_begin() {
    invalidate ();
    expr_iterator_data *iter_data = make_iter ();
    iter_data->next ();
    return expr_iterator (iter_data);
  }

  void expr::next_iter (expr_iterator_data &v) {
    BEGIN_EXPR_ITER();
    ZORBA_ASSERT (false);
    END_EXPR_ITER();
  }

  expr_t expr::clone()
  {
      substitution_t s;
      return clone(s);
  }

  expr_t expr::clone(substitution_t& substitution)
  {
    ZORBA_ASSERT(false);
    return NULL; // Make the compiler happy
  }
#ifdef ZORBA_DEBUGGER
  void debugger_expr::next_iter (expr_iterator_data& v)
  {
    BEGIN_EXPR_ITER();
    ITER(child);
    END_EXPR_ITER();
  }  
#endif

  expr_iterator_data *sequential_expr::make_iter () {
    return new sequential_expr_iterator_data (this);
  }

  void sequential_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER2 (sequential_expr);

  ITER_FOR_EACH (iter, sequence.begin (), sequence.end (),
                 (*vv.iter));

  END_EXPR_ITER();
  }

/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  XQuery 1.0 productions                                             //
//  [http://www.w3.org/TR/xquery/]                                     //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

// [29]
// [33a]

string var_expr::decode_var_kind(
  enum var_kind k)
{
  switch (k) {
  case for_var: return "FOR"; break;
  case let_var: return "LET"; break;
  case pos_var: return "POS"; break;
  case score_var: return "SCORE"; break;
  case quant_var: return "QUANT"; break;
  case context_var: return "CTX"; break;
  case catch_var: return "CATCH"; break;
  case copy_var: return "COPY"; break;
  case groupby_var: return "GROUPBY"; break;
  case param_var: return "PARAM"; break;
  default: return "???";
  }
}

var_expr::var_expr(const QueryLoc& loc, store::Item_t name) : expr (loc), varname_h (name), type (NULL), m_forlet_clause(NULL) {}

var_expr::var_expr(const QueryLoc& loc, var_kind k, store::Item_t name) : expr (loc), kind (k), varname_h (name), type (NULL), m_forlet_clause(NULL) {}  // TODO

store::Item_t var_expr::get_varname() const { return varname_h; }
xqtref_t var_expr::get_type() const { return type; }
void var_expr::set_type(xqtref_t t) { type = t; }

void var_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  END_EXPR_ITER();
}

expr::expr_t var_expr::clone(expr::substitution_t& substitution)
{
  expr::subst_iter_t i = substitution.find(this);
  if (i == substitution.end()) {
    return this;
  }
  return i->second->clone(substitution);
}

// [33] [http://www.w3.org/TR/xquery/#prod-xquery-FLWORExpr]


forlet_clause::forlet_clause(
  enum forlet_t _type,
  varref_t _var_h,
  varref_t _pos_var_h,
  varref_t _score_var_h,
  expr_t _expr_h)
:
  type(_type),
  var_h(_var_h),
  pos_var_h(_pos_var_h),
  score_var_h(_score_var_h),
  expr_h(_expr_h)
{
  if (var_h != NULL) {
    var_h->set_forlet_clause(this);
  }
  if (pos_var_h != NULL) {
    pos_var_h->set_forlet_clause(this);
  }
  if (score_var_h != NULL) {
    score_var_h->set_forlet_clause(this);
  }
}

rchandle<forlet_clause> forlet_clause::clone(expr::substitution_t& substitution)
{
  expr_t expr_copy_h = expr_h->clone(substitution);

  varref_t var_copy_h(new var_expr(*var_h));
  substitution[var_h.getp()] = var_copy_h.getp();

  varref_t pos_var_copy_h;
  var_expr *pos_var_ptr = pos_var_h.getp();
  if (pos_var_ptr) {
    pos_var_copy_h = new var_expr(*pos_var_ptr);
    substitution[pos_var_ptr] = pos_var_copy_h.getp();
  }

  varref_t score_var_copy_h;
  var_expr *score_var_ptr = score_var_h.getp();
  if (score_var_ptr) {
    score_var_copy_h = new var_expr(*score_var_ptr);
    substitution[score_var_ptr] = score_var_copy_h.getp();
  }

  return new forlet_clause(type, var_copy_h, pos_var_copy_h, score_var_copy_h, expr_copy_h);
}

  flwor_expr::clause_list_t::iterator flwor_expr::remove_forlet_clause(flwor_expr::clause_list_t::iterator i) {
  (*i)->get_var ()->set_forlet_clause (NULL);
  var_expr *pvar = (*i)->get_pos_var ();
  if (pvar != NULL)
    pvar->set_forlet_clause (NULL);
  return clause_v.erase(i); 
}

expr_iterator_data *flwor_expr::make_iter () {
  return new flwor_expr_iterator_data (this);
}

void flwor_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER2 (flwor_expr);

  ITER_FOR_EACH (clause_iter, clause_v.begin (), clause_v.end (),
                 (*vv.clause_iter)->expr_h);
  
  ITER (where_h);

  ITER_FOR_EACH (group_iter, group_v.begin(), group_v.end(),
                 (*vv.group_iter)->theOuterVar);

  ITER_FOR_EACH (non_group_iter, non_group_v.begin(), non_group_v.end(),
                 (*vv.non_group_iter)->theOuterVar);

  ITER (group_where_h);

  ITER_FOR_EACH (order_mod_iter, orderspec_begin (), orderspec_end (),
                 (*vv.order_mod_iter).first);

  ITER (retval_h);
  
  END_EXPR_ITER(); 
}

expr::expr_t flwor_expr::clone(expr::substitution_t& substitution)
{
  expr_t flwor_copy = new flwor_expr(get_loc());
  flwor_copy->setUpdateType(getUpdateType());
  flwor_expr *flwor_copy_ptr = static_cast<flwor_expr *>(flwor_copy.getp());

  for(clause_list_t::iterator i = clause_v.begin(); i != clause_v.end(); ++i) {
    flwor_copy_ptr->add((*i)->clone(substitution));
  }

  for(orderspec_list_t::iterator i = orderspec_v.begin(); i != orderspec_v.end(); ++i) {
    expr_t e_copy = i->first->clone(substitution);
    flwor_copy_ptr->add(orderspec_t(e_copy, i->second));
  }

  flwor_copy_ptr->set_order_stable(order_stable);

  if (where_h.getp()) {
    flwor_copy_ptr->set_where(where_h->clone(substitution));
  }

  flwor_copy_ptr->set_retval(retval_h->clone(substitution));

  return flwor_copy;
}

catch_clause::catch_clause()
  : nametest_h(NULL),
  var_h(NULL),
  catch_expr_h(NULL) { }

expr_iterator_data *trycatch_expr::make_iter()
{
  return new trycatch_expr_iterator_data(this);
}

trycatch_expr::trycatch_expr(const QueryLoc& loc)
  : expr(loc) { }

void trycatch_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER2 (trycatch_expr);
  ITER (try_expr_h);
  for (vv.clause_iter = begin (); vv.clause_iter != end (); ++(vv.clause_iter)) {
    ITER ((*vv.clause_iter)->var_h);
    ITER ((*vv.clause_iter)->catch_expr_h);
  }
  END_EXPR_ITER ();
}

case_clause::case_clause() : var_h(NULL), case_expr_h(NULL), type(GENV_TYPESYSTEM.UNTYPED_TYPE) { }


expr_iterator_data *eval_expr::make_iter () {
  return new eval_expr_iterator_data (this);
}

void eval_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER2 (eval_expr);
  ITER (expr_h);
  ITER_FOR_EACH (var_iter, vars.begin (), vars.end (), vv.var_iter->val);
  END_EXPR_ITER ();
}

  eval_expr::eval_var::eval_var (var_expr *ve, expr_t val_)
    : varname (ve->get_varname ()),
      var_key (dynamic_context::var_key (ve)), val (val_)
  {
  }

cast_or_castable_base_expr::cast_or_castable_base_expr(const QueryLoc& loc, expr_t input, xqtref_t type)
  : expr (loc), input_expr_h (input), target_type (type)
{
  assert (type != NULL);
  assert (input != NULL);
}

xqtref_t cast_or_castable_base_expr::get_target_type() const {
  return target_type;
}

void cast_or_castable_base_expr::set_target_type(xqtref_t target) {
  invalidate ();
  target_type = target;
}


cast_base_expr::cast_base_expr(const QueryLoc& loc, expr_t input, xqtref_t type)
  : cast_or_castable_base_expr (loc, input, type)
{}


promote_expr::promote_expr(const QueryLoc& loc, expr_t input, xqtref_t type)
  : cast_base_expr (loc, input, type)
{}

void promote_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (input_expr_h);
  END_EXPR_ITER ();
}


// [42] [http://www.w3.org/TR/xquery/#prod-xquery-QuantifiedExpr]

// [43] [http://www.w3.org/TR/xquery/#prod-xquery-TypeswitchExpr]

typeswitch_expr::typeswitch_expr(
  const QueryLoc& loc)
:
  expr(loc)
{
}

expr_iterator_data *typeswitch_expr::make_iter () {
  return new typeswitch_expr_iterator_data (this);
}

void typeswitch_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER2 (typeswitch_expr);
  ITER (switch_expr_h);
  for (vv.clause_iter = begin (); vv.clause_iter != end (); ++(vv.clause_iter)) {
    ITER ((*vv.clause_iter)->var_h);
    ITER ((*vv.clause_iter)->case_expr_h);
  }
  ITER (default_var_h);
  ITER (default_clause_h);
  END_EXPR_ITER ();
}


// [45] [http://www.w3.org/TR/xquery/#prod-xquery-IfExpr]

if_expr::if_expr(
  const QueryLoc& loc,
  expr_t _cond_expr_h,
  expr_t _then_expr_h,
  expr_t _else_expr_h)
:
  expr(loc),
  cond_expr_h(_cond_expr_h),
  then_expr_h(_then_expr_h),
  else_expr_h(_else_expr_h)
{
}

if_expr::if_expr(
  const QueryLoc& loc)
:
  expr(loc)
{
}


void if_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  ITER (cond_expr_h);
  ITER (then_expr_h);
  ITER (else_expr_h);
  END_EXPR_ITER();
}

////////////////////////////////
//  first-order expressions
////////////////////////////////
// includes:
// [46] [http://www.w3.org/TR/xquery/#prod-xquery-OrExpr]
// [47] [http://www.w3.org/TR/xquery/#prod-xquery-AndExpr]
// [48] [http://www.w3.org/TR/xquery/#prod-xquery-ComparisonExpr]
// [49] [http://www.w3.org/TR/xquery/#prod-xquery-RangeExpr]
// [50] [http://www.w3.org/TR/xquery/#prod-xquery-AdditiveExpr]
// [51] [http://www.w3.org/TR/xquery/#prod-xquery-MultiplicativeExpr]
// [52] [http://www.w3.org/TR/xquery/#prod-xquery-UnionExpr]
// [53] [http://www.w3.org/TR/xquery/#prod-xquery-IntersectExceptExpr]

expr_iterator_data *fo_expr::make_iter () { return new fo_expr_iterator_data (this); }

void fo_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER2 (fo_expr);
  ITER_FOR_EACH (arg_iter, begin (), end (), *vv.arg_iter);
  END_EXPR_ITER ();
}

const signature &fo_expr::get_signature () const {
  return func->get_signature ();
}

store::Item_t fo_expr::get_fname () const
{ return func->get_fname (); }


// [48a] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTContainsExpr]

ft_contains_expr::ft_contains_expr(
  const QueryLoc& loc,
  expr_t _range_h,
  expr_t _ft_select_h,
  expr_t _ft_ignore_h)
:
  expr(loc),
  range_h(_range_h),
  ft_select_h(_ft_select_h),
  ft_ignore_h(_ft_ignore_h)
{
}


void ft_contains_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (range_h);
  ITER (ft_select_h);
  ITER (ft_ignore_h);
  END_EXPR_ITER ();
}


// [54] [http://www.w3.org/TR/xquery/#prod-xquery-InstanceofExpr]

castable_base_expr::castable_base_expr (const QueryLoc& loc,
                                        expr_t _expr_h,
                                        xqtref_t _type)
  : cast_or_castable_base_expr (loc, _expr_h, _type)
{}

instanceof_expr::instanceof_expr(const QueryLoc& loc,
                                 expr_t _expr_h,
                                 xqtref_t _type)
  : castable_base_expr (loc, _expr_h, _type)
{}

void instanceof_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  ITER (input_expr_h);
  END_EXPR_ITER();  
}


// [55] [http://www.w3.org/TR/xquery/#prod-xquery-TreatExpr]

treat_expr::treat_expr(
  const QueryLoc& loc,
  expr_t _expr_h,
  xqtref_t _type,
  XQUERY_ERROR err_,
  bool check_prime_)
:
  cast_base_expr (loc, _expr_h, _type),
  err (err_), check_prime (check_prime_)
{
}

void treat_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (input_expr_h);
  END_EXPR_ITER ();
}

// [56] [http://www.w3.org/TR/xquery/#prod-xquery-CastableExpr]

castable_expr::castable_expr(
  const QueryLoc& loc,
  expr_t _expr_h,
  xqtref_t _type)
:
  castable_base_expr (loc, _expr_h, _type)
{}

void castable_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (input_expr_h);
  END_EXPR_ITER ();
}


// [57] [http://www.w3.org/TR/xquery/#prod-xquery-CastExpr]

cast_expr::cast_expr(
  const QueryLoc& loc,
  expr_t _expr_h,
  xqtref_t _type)
  : cast_base_expr (loc, _expr_h, _type)
{
}

void cast_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (input_expr_h);
  END_EXPR_ITER ();
}

name_cast_expr::name_cast_expr(
  const QueryLoc& loc,
  expr_t _expr_h,
  NamespaceContext_t aNCtx)
: expr(loc), input_expr_h(_expr_h), theNCtx(aNCtx) 
{}

void name_cast_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (input_expr_h);
  END_EXPR_ITER ();
}

rchandle<namespace_context> name_cast_expr::getNamespaceContext() { return theNCtx; }

// [63] [http://www.w3.org/TR/xquery/#prod-xquery-ValidateExpr]

validate_expr::validate_expr(
  const QueryLoc& loc,
  enum ParseConstants::validation_mode_t _valmode,
  expr_t _expr_h)
:
  expr(loc),
  valmode(_valmode),
  expr_h(_expr_h)
{
}


void validate_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (expr_h);
  END_EXPR_ITER ();
}


// [65] [http://www.w3.org/TR/xquery/#prod-xquery-ExtensionExpr]

extension_expr::extension_expr(
  const QueryLoc& loc)
:
  expr(loc)
{
}

extension_expr::extension_expr(
  const QueryLoc& loc,
  expr_t _expr_h)
:
  expr(loc),
  expr_h(_expr_h)
{
}


void extension_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (expr_h);
  END_EXPR_ITER ();
}


/*******************************************************************************

 [69] [http://www.w3.org/TR/xquery/#prod-xquery-RelativePathExpr]

  RelativPathExpr ::= "/" | ("/" | "//")?  StepExpr (("/" | "//") StepExpr)*

********************************************************************************/
relpath_expr::relpath_expr(const QueryLoc& loc)
  :
  expr(loc)
{
}

expr_iterator_data *relpath_expr::make_iter () { return new relpath_expr_iterator_data (this); }

void relpath_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER2 (relpath_expr);

  ITER_FOR_EACH (step_iter, begin (), end (), *vv.step_iter);

  END_EXPR_ITER();
}

/*******************************************************************************

  [71] [http://www.w3.org/TR/xquery/#prod-xquery-AxisStep]

  AxisStep ::= Axis NodeTest Predicate*

********************************************************************************/
axis_step_expr::axis_step_expr(const QueryLoc& loc)
  :
  expr(loc)
{
}

expr_iterator_data *axis_step_expr::make_iter () {
  return new axis_step_expr_iterator_data (this);
}

void axis_step_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER2 (axis_step_expr);

  ITER_FOR_EACH (pred_iter, thePreds.begin (), thePreds.end (), *vv.pred_iter);

  ITER (theNodeTest);

  END_EXPR_ITER();
}

bool axis_step_expr::is_reverse_axis (axis_kind_t k) {
  return k == axis_kind_ancestor || k == axis_kind_ancestor_or_self || k == axis_kind_parent;
}

/*******************************************************************************

  [78] NodeTest ::= KindTest | NameTest

  [79] NameTest ::= QName | Wildcard
  [80] Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)

  [123] KindTest ::= DocumentTest | ElementTest | AttributeTest |
                     SchemaElementTest | SchemaAttributeTest |
                     PITest | CommentTest | TextTest | AnyKindTest

********************************************************************************/
match_expr::match_expr(const QueryLoc& loc)
  :
  expr(loc),
  theWildKind(match_no_wild),
  theQName(NULL),
  theTypeName(NULL),
  theNilledAllowed(false)
{
}


void match_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  END_EXPR_ITER();
}


store::StoreConsts::NodeKind match_expr::getNodeKind() const
{
  switch (theTestKind)
  {
  case match_name_test:
    return store::StoreConsts::elementNode;
  case match_doc_test:
    return store::StoreConsts::elementNode;
  case match_elem_test:
    return store::StoreConsts::elementNode;
  case match_attr_test:
    return store::StoreConsts::attributeNode;
  case match_xs_elem_test:
    return store::StoreConsts::elementNode;
  case match_xs_attr_test:
    return store::StoreConsts::attributeNode;
  case match_pi_test:
    return store::StoreConsts::piNode;
  case match_text_test:
    return store::StoreConsts::textNode;
  case match_comment_test:
    return store::StoreConsts::commentNode;
  case match_anykind_test:
    return store::StoreConsts::anyNode;
  default:
    ZORBA_ASSERT (false && "Unknown node test kind");
  }
  return store::StoreConsts::anyNode;
}

// [84] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]


// [85] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]

const_expr::const_expr(const QueryLoc& loc, xqpString v)
  :
  expr(loc)
{
  xqpStringStore_t tmp = v.getStore();
  ITEM_FACTORY->createString(val, tmp); 
}

const_expr::const_expr(const QueryLoc& loc, xqp_integer v)
  :
  expr(loc)
{
  ITEM_FACTORY->createInteger (val, v);
}

const_expr::const_expr(
  const QueryLoc& loc,
  xqp_decimal v)
:
  expr(loc)
{
  ITEM_FACTORY->createDecimal (val, v);
}

const_expr::const_expr(
  const QueryLoc& loc,
  xqp_double v)
:
  expr(loc)
{
  ITEM_FACTORY->createDouble (val, v);
}

const_expr::const_expr(
  const QueryLoc& loc,
  xqp_boolean v)
:
  expr(loc)
{
  ITEM_FACTORY->createBoolean (val, v);
}

const_expr::const_expr(
  const QueryLoc& loc,
  store::Item_t v)
:
  expr(loc),
  val(v)
{
}

const_expr::const_expr(
  const QueryLoc& aLoc, 
  const char* aNamespace,
  const char* aPrefix, 
  const char* aLocal)
:
  expr(aLoc)
{
  ITEM_FACTORY->createQName(val, aNamespace, aPrefix, aLocal);
}


void const_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  END_EXPR_ITER();
}


// [91] [http://www.w3.org/TR/xquery/#prod-xquery-OrderedExpr]

order_expr::order_expr(
  const QueryLoc& loc,
  order_type_t _type,
  expr_t _expr_h)
:
  expr(loc),
  type(_type),
  expr_h(_expr_h)
{
}


void order_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (expr_h);
  END_EXPR_ITER ();
}


// [93] [http://www.w3.org/TR/xquery/#prod-xquery-FunctionCall]

// [96] [http://www.w3.org/TR/xquery/#doc-exquery-DirElemConstructor]
elem_expr::elem_expr (
    const QueryLoc& aLoc,
    expr_t aQNameExpr,
    expr_t aAttrs,
    expr_t aContent,
    rchandle<namespace_context> aNSCtx)
    :
    constructor_expr ( aLoc ),
    theQNameExpr ( aQNameExpr ),
    theAttrs ( aAttrs ),
    theContent ( aContent ),
    theNSCtx(aNSCtx)
{
}

elem_expr::elem_expr (
    const QueryLoc& aLoc,
    expr_t aQNameExpr,
    expr_t aContent,
    rchandle<namespace_context> aNSCtx)
    :
    constructor_expr ( aLoc ),
    theQNameExpr ( aQNameExpr ),
    theAttrs ( 0 ),
    theContent ( aContent ),
    theNSCtx(aNSCtx)
{
}
  

rchandle<namespace_context> elem_expr::getNSCtx() { return theNSCtx; }

void elem_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  ITER (theQNameExpr);
  ITER (theAttrs);
  ITER (theContent);
  END_EXPR_ITER();
}


// [110] [http://www.w3.org/TR/xquery/#prod-xquery-CompDocConstructor]

doc_expr::doc_expr(
  const QueryLoc& loc,
  expr_t aContent)
:
  constructor_expr(loc),
  theContent(aContent)
{
}


void doc_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  ITER(theContent);
  END_EXPR_ITER();
}


// [111] [http://www.w3.org/TR/xquery/#prod-xquery-CompElemConstructor]


// [113] [http://www.w3.org/TR/xquery/#prod-xquery-CompAttrConstructor]

attr_expr::attr_expr(
  const QueryLoc& loc,
  expr_t aQNameExpr,
  expr_t aValueExpr)
:
  constructor_expr(loc),
  theQNameExpr(aQNameExpr),
  theValueExpr(aValueExpr)
{
}


store::Item* attr_expr::getQName() const
{
  const_expr* qnExpr =  dynamic_cast<const_expr*>(theQNameExpr.getp());
  if (qnExpr != 0)
    return qnExpr->get_val().getp();

  return 0;
}


void attr_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  ITER (theQNameExpr);
  ITER (theValueExpr);
  END_EXPR_ITER();
}

// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompTextConstructor]

text_expr::text_expr(
  const QueryLoc& loc,
  text_constructor_type type_arg,
  expr_t text_arg)
:
  constructor_expr(loc),
  type (type_arg),
  text(text_arg)
{
}


void text_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  ITER (text);
  END_EXPR_ITER();
}

// [115] [http://www.w3.org/TR/xquery/#prod-xquery-CompCommentConstructor]


// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompPIConstructor]

pi_expr::pi_expr(
  const QueryLoc& loc,
  expr_t _target_expr_h,
  expr_t _content_expr_h)
:
  text_expr(loc, text_expr::pi_constructor, _content_expr_h),
  target_expr_h(_target_expr_h)
{
}


void pi_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (target_expr_h);
  ITER (text);
  END_EXPR_ITER ();
}


void function_def_expr::next_iter (expr_iterator_data& v) {
}

function_def_expr::function_def_expr (const QueryLoc& loc, store::Item_t name_, std::vector<rchandle<var_expr> > &params_, xqtref_t return_type_impl)
  : expr (loc), name (name_)
{
  assert (return_type_impl != NULL);
  params.swap (params_);
  vector<xqtref_t> args;
  // TODO: copy param types into sig
  for (unsigned i = 0; i < param_size (); i++)
    args.push_back (GENV_TYPESYSTEM.ITEM_TYPE_STAR);
  sig = auto_ptr<signature> (new signature (get_name (), args, GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}

// [242] [http://www.w3.org/TR/xqupdate/#prod-xquery-InsertExpr]

insert_expr::insert_expr(
	const QueryLoc& loc,
  store::UpdateConsts::InsertType aType,
	expr_t aSourceExpr,
	expr_t aTargetExpr)
:
	expr(loc),
  theType(aType),
	theSourceExpr(aSourceExpr),
	theTargetExpr(aTargetExpr)
{
  setUpdateType(UPDATE_EXPR);
}

void 
insert_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theSourceExpr);
  ITER(theTargetExpr);
  END_EXPR_ITER(); 
}



// [243] [http://www.w3.org/TR/xqupdate/#prod-xquery-DeleteExpr]

delete_expr::delete_expr(
	const QueryLoc& loc,
	expr_t aTargetExpr)
:
	expr(loc),
	theTargetExpr(aTargetExpr)
{
  setUpdateType(UPDATE_EXPR);
}

void delete_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theTargetExpr);
  END_EXPR_ITER(); 
}



// [244] [http://www.w3.org/TR/xqupdate/#prod-xquery-ReplaceExpr]

replace_expr::replace_expr(
	const QueryLoc& loc,
  store::UpdateConsts::ReplaceType aType,
	expr_t aTargetExpr,
	expr_t aReplaceExpr)
:
	expr(loc),
  theType(aType),
	theTargetExpr(aTargetExpr),
	theReplaceExpr(aReplaceExpr)
{
  setUpdateType(UPDATE_EXPR);
}

void replace_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theTargetExpr);
  ITER(theReplaceExpr);
  END_EXPR_ITER();
}



// [245] [http://www.w3.org/TR/xqupdate/#prod-xquery-RenameExpr]

rename_expr::rename_expr(
	const QueryLoc& loc,
	expr_t aTargetExpr,
	expr_t aNameExpr)
:
	expr(loc),
	theTargetExpr(aTargetExpr),
	theNameExpr(aNameExpr)
{
  setUpdateType(UPDATE_EXPR);
}

void rename_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theTargetExpr);
  ITER(theNameExpr);
  END_EXPR_ITER();
}


copy_clause::copy_clause(rchandle<var_expr> aVar, expr_t aExpr)
: theVar(aVar), theExpr(aExpr) {}

// [249] [http://www.w3.org/TR/xqupdate/#prod-xquery-TransformExpr]

transform_expr::transform_expr(
	const QueryLoc& loc,
	expr_t aModifyExpr,
	expr_t aReturnExpr)
:
	expr(loc),
	theModifyExpr(aModifyExpr),
	theReturnExpr(aReturnExpr)
{}

expr_iterator_data *transform_expr::make_iter () { return new transform_expr_iterator_data(this); }

void transform_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER2 (transform_expr);
  ITER_FOR_EACH(clause_iter, theCopyClauses.begin(), theCopyClauses.end(),
                (*vv.clause_iter)->theExpr);
  ITER(theModifyExpr);
  ITER(theReturnExpr);
  END_EXPR_ITER();
} 

void exit_expr::next_iter (expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(val);
  END_EXPR_ITER();
}

void flowctl_expr::next_iter (expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  END_EXPR_ITER();
}

void while_expr::next_iter (expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER (body);
  END_EXPR_ITER();
}

} /* namespace zorba */
/* vim:set ts=2 sw=2: */
