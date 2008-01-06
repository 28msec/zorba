/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: expr.cpp.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "compiler/expression/expr.h"
#include "functions/function.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parsetree/parsenodes.h"
#include "util/Assert.h"
#include "util/tracer.h"
#include "errors/error_factory.h"
#include "compiler/expression/expr_visitor.h"
#include "system/zorba.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace xqp {
  
int printdepth0 = -2;

#define DENT      std::string(printdepth0, ' ')
#define INDENT    (printdepth0 += 2, std::string(printdepth0, ' '))
#define OUTDENT   (printdepth0 -= 2, std::string(printdepth0, ' '))
#define UNDENT    printdepth0 -= 2;

  static inline ostream &put_qname (Item_t qname, ostream &os) {
    xqp_string pfx = qname->getPrefix ();
    if (! pfx.empty ())
      os << pfx << "[=" << qname->getNamespace () << "]:";
    os << qname->getLocalName ();
    return os;
  }

#define ITEM_FACTORY (Store::getInstance().getItemFactory())

#define ACCEPT( m ) do { if (m != NULL) m->accept (v); } while (0)
#define BEGIN_VISITOR() do { if (!v.begin_visit(*this)) return; } while (0)
#define END_VISITOR() v.end_visit(*this);

#define DECLARE_VISITOR_FUNCTOR( name, type, body)                      \
  class name : public unary_function<rchandle<expr>, void> {            \
    expr_visitor &v;                                                    \
  public:                                                               \
  name (expr_visitor &v_) : v (v_) {}                                   \
  void operator () (type e) body                                        \
  }


DECLARE_VISITOR_FUNCTOR(visitor_functor, expr::expr_t, { ACCEPT(e); });


expr::expr(
  yy::location const& _loc)
:
  loc(_loc)
{
}

ostream& expr::put( ostream& os) const
{
  return os;
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
  case for_var: return "FOR_VAR"; break;
  case let_var: return "LET_VAR"; break;
  case pos_var: return "POS_VAR"; break;
  case score_var: return "SCORE_VAR"; break;
  case quant_var: return "QUANT_VAR"; break;
  case context_var: return "$DOT"; break;
  default: return "???";
  }
}

ostream& var_expr::put(ostream& os) const
{
  os << INDENT << "var_expr(" << this << ")[" << decode_var_kind(get_kind());
  if (varname_h != NULL)
  {
    os << " name=";
    put_qname (get_varname(), os);
  }
  os << ", type= ]\n"; // TODO(VRB) << sequence_type::describe(type);
  UNDENT;
  return os;
}

void var_expr::accept(expr_visitor& v)
{
  if (!v.begin_visit(*this)) return;
  v.end_visit(*this);
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
}

forlet_clause::~forlet_clause()
{
}

ostream & forlet_clause::put( ostream& os) const
{
  os << INDENT << "forlet(" << this << ")\n";
  os << DENT << "[\n";

  Assert(var_h != NULL);
  var_h->put(os);
  if (pos_var_h!=NULL) 
  {
    os << INDENT << " AT \n"; UNDENT;
    pos_var_h->put(os);
  }
  if (score_var_h!=NULL) 
  {
    os << INDENT << " SCORE \n"; UNDENT;
    score_var_h->put(os);
  }

  os << endl;
  Assert(expr_h != NULL);
  expr_h->put(os);

  os << DENT << "]\n"; UNDENT;
  return os;
}

rchandle<forlet_clause> forlet_clause::clone(expr::substitution_t& substitution)
{
  expr_t expr_copy_h = expr_h->clone(substitution);

  varref_t var_copy_h(new var_expr(*var_h));
  substitution[var_h.get_ptr()] = var_copy_h.get_ptr();

  varref_t pos_var_copy_h;
  var_expr *pos_var_ptr = pos_var_h.get_ptr();
  if (pos_var_ptr) {
    pos_var_copy_h = new var_expr(*pos_var_ptr);
    substitution[pos_var_ptr] = pos_var_copy_h.get_ptr();
  }

  varref_t score_var_copy_h;
  var_expr *score_var_ptr = score_var_h.get_ptr();
  if (score_var_ptr) {
    score_var_copy_h = new var_expr(*score_var_ptr);
    substitution[score_var_ptr] = score_var_copy_h.get_ptr();
  }

  return new forlet_clause(type, var_copy_h, pos_var_copy_h, score_var_copy_h, expr_copy_h);
}


ostream& flwor_expr::put( ostream& os) const
{
  os << INDENT << "flwor_expr(" << this << ")\n";
  os << DENT << "[\n";

  vector<forletref_t>::const_iterator it = clause_begin();
  for (; it!=clause_end(); ++it)
  {
    forletref_t fl_h = *it;
    Assert(fl_h != NULL);
    fl_h->put(os);
  }

  if (where_h!=NULL) where_h->put(os);

  
  for (vector<orderspec_t>::const_iterator ord_it = orderspec_begin();
       ord_it!=orderspec_end(); ++ord_it) 
  {
    orderspec_t spec = *ord_it;
    expr_t e_h = spec.first;
    Assert(e_h != NULL);
    orderref_t ord_h = spec.second;
    Assert(ord_h != NULL);

    os << INDENT << "ORDERBY\n"; UNDENT;
    e_h->put(os) << endl;

    os << INDENT;
    switch (ord_h->dir) 
    {
    case dir_ascending: os << "ASCENDING "; break;
    case dir_descending: os << "DESCENDING "; break;
    default: os << "?? ";
    }
    switch (ord_h->empty_mode) 
    {
    case StaticQueryContext::empty_greatest: os << "EMPTY GREATEST "; break;
    case StaticQueryContext::empty_least: os << "EMPTY LEAST "; break;
    default: os << "?? ";
    }
    os << ord_h->collation << endl;
    UNDENT;
  }

  Assert(retval_h!=NULL);
  os << INDENT << "RETURN\n"; UNDENT; 
  retval_h->put(os);

  os << DENT << "]\n"; UNDENT;
  return os;
}

DECLARE_VISITOR_FUNCTOR (forletref_visitor_functor, flwor_expr::forletref_t, { ACCEPT (e->expr_h); });
DECLARE_VISITOR_FUNCTOR (orderspec_visitor_functor, flwor_expr::orderspec_t, { ACCEPT (e.first); });

void flwor_expr::accept(expr_visitor& v)
{
  if (!v.begin_visit(*this)) return;

  for_each (clause_v.begin (), clause_v.end (), forletref_visitor_functor (v));
  
  ACCEPT (where_h);

  for_each (orderspec_rbegin (), orderspec_rend (), orderspec_visitor_functor (v));

  retval_h->accept(v);
  
  v.end_visit(*this); 
}

expr::expr_t flwor_expr::clone(expr::substitution_t& substitution)
{
  expr_t flwor_copy = new flwor_expr(get_loc());
  flwor_expr *flwor_copy_ptr = static_cast<flwor_expr *>(flwor_copy.get_ptr());

  for(clause_list_t::iterator i = clause_v.begin(); i != clause_v.end(); ++i) {
    flwor_copy_ptr->add((*i)->clone(substitution));
  }

  for(orderspec_list_t::iterator i = orderspec_v.begin(); i != orderspec_v.end(); ++i) {
    expr_t e_copy = i->first->clone(substitution);
    flwor_copy_ptr->add(orderspec_t(e_copy, i->second));
  }

  flwor_copy_ptr->set_order_stable(order_stable);

  if (where_h.get_ptr()) {
    flwor_copy_ptr->set_where(where_h->clone(substitution));
  }

  flwor_copy_ptr->set_retval(retval_h->clone(substitution));

  return flwor_copy;
}

void promote_expr::accept(expr_visitor& v)
{
  BEGIN_VISITOR ();
  ACCEPT (input_expr_h);
  END_VISITOR ();
}


std::ostream& promote_expr::put(std::ostream& os) const
{
  os << INDENT << "promote_expr(" << this << ")\n";
  os << DENT << "[ ";
  GENV_TYPESYSTEM.serialize(os, *target_type) << "\n";
  Assert(input_expr_h!=NULL);
  input_expr_h->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

// [42] [http://www.w3.org/TR/xquery/#prod-xquery-QuantifiedExpr]

// [43] [http://www.w3.org/TR/xquery/#prod-xquery-TypeswitchExpr]

typeswitch_expr::typeswitch_expr(
  yy::location const& loc)
:
  expr(loc)
{
}

typeswitch_expr::~typeswitch_expr()
{
}

ostream& typeswitch_expr::put( ostream& os) const
{
  os << INDENT << "typeswitch_expr(" << this << ")\n";
  os << DENT << "[\n";

  //d Assert<null_pointer>(switch_expr_h!=NULL);
  Assert(switch_expr_h!=NULL);
  switch_expr_h->put(os);

  for (vector<clauseref_t>::const_iterator it = case_clause_hv.begin();
       it!=case_clause_hv.end(); ++it)
  {
    clauseref_t cc_h = *it;
    os << INDENT << "case: ";
    if (cc_h->var_h!=NULL) cc_h->var_h->put(os) << " as ";
    // TODO(VRB) os << sequence_type::describe(cc_h->type);
        os << " return ";
    //d Assert<null_pointer>(cc_h->case_expr_h!=NULL);
    Assert(cc_h->case_expr_h!=NULL);
    cc_h->case_expr_h->put(os) << endl;
    UNDENT;
  }
  os << DENT << "]\n"; UNDENT;
  return os;
}

DECLARE_VISITOR_FUNCTOR (caseclause_visitor_functor, typeswitch_expr::clauseref_t, { ACCEPT (e->var_h); ACCEPT (e->case_expr_h); });

void typeswitch_expr::accept(expr_visitor& v) {
  BEGIN_VISITOR ();
  ACCEPT (switch_expr_h);
  caseclause_visitor_functor f (v);
  for_each (case_clause_hv.begin (), case_clause_hv.end (), f);
  ACCEPT (default_var_h);
  ACCEPT (default_clause_h);
  END_VISITOR ();
}


// [45] [http://www.w3.org/TR/xquery/#prod-xquery-IfExpr]

if_expr::if_expr(
  yy::location const& loc,
  rchandle<expr> _cond_expr_h,
  rchandle<expr> _then_expr_h,
  rchandle<expr> _else_expr_h)
:
  expr(loc),
  cond_expr_h(_cond_expr_h),
  then_expr_h(_then_expr_h),
  else_expr_h(_else_expr_h)
{
}

if_expr::if_expr(
  yy::location const& loc)
:
  expr(loc)
{
}

if_expr::~if_expr()
{
}

ostream& if_expr::put( ostream& os) const
{
  os << INDENT << "if_expr(" << this << ")\n";
  os << DENT << "[\n";
  //d Assert<null_pointer>(cond_expr_h!=NULL);
  Assert(cond_expr_h!=NULL);
  cond_expr_h->put(os);
  //d Assert<null_pointer>(then_expr_h!=NULL);
  Assert(then_expr_h!=NULL);
  then_expr_h->put(os);
  //d Assert<null_pointer>(else_expr_h!=NULL);
  Assert(else_expr_h!=NULL);
  else_expr_h->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

void if_expr::accept(
  expr_visitor& v)
{
  if (!v.begin_visit(*this)) return;
  cond_expr_h->accept(v);
  then_expr_h->accept(v);
  else_expr_h->accept(v);
  v.end_visit(*this);
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


fo_expr::fo_expr(yy::location const& loc, const function *f)
  : expr(loc), func (f)
{ assert (f != NULL); }

ostream& fo_expr::put( ostream& os) const
{
  Assert(func != NULL);
  os << INDENT << func->get_fname()->getStringProperty() << "/" << size ()
     << "(" << this << ")" << endl;
  os << DENT << "[\n";

  
  for (vector<rchandle<expr> >::const_iterator it = begin();
       it != end(); ++it)
  {
    rchandle<expr> e_h = *it;
    Assert(e_h!=NULL);
    e_h->put(os);
  }
  os << DENT << "]\n"; UNDENT;
  return os;
}

void fo_expr::accept(
  expr_visitor& v)
{
  BEGIN_VISITOR ();
  visitor_functor a (v);
  for_each (begin (), end (), a);
  END_VISITOR ();
}



// [48a] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTContainsExpr]

ft_contains_expr::ft_contains_expr(
  yy::location const& loc,
  rchandle<expr> _range_h,
  rchandle<expr> _ft_select_h,
  rchandle<expr> _ft_ignore_h)
:
  expr(loc),
  range_h(_range_h),
  ft_select_h(_ft_select_h),
  ft_ignore_h(_ft_ignore_h)
{
}

ft_contains_expr::~ft_contains_expr()
{
}

ostream& ft_contains_expr::put( ostream& os) const
{
  os << INDENT << "ft_contains_expr(" << this << ")\n";
  os << DENT << "[\n";
  //d Assert<null_pointer>(range_h!=NULL);
  Assert(range_h!=NULL);
  range_h->put(os) << endl;
  //d Assert<null_pointer>(ft_select_h!=NULL);
  Assert(ft_select_h!=NULL);
  os << "ft_contains\n";
  ft_select_h->put(os) << endl;
  if (ft_ignore_h!=NULL) ft_ignore_h->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

void ft_contains_expr::accept(
  expr_visitor& v)
{
  BEGIN_VISITOR ();
  ACCEPT (range_h);
  ACCEPT (ft_select_h);
  ACCEPT (ft_ignore_h);
  END_VISITOR ();
}




// [54] [http://www.w3.org/TR/xquery/#prod-xquery-InstanceofExpr]

instanceof_expr::instanceof_expr(
  yy::location const& loc,
  rchandle<expr> _expr_h,
  TypeSystem::xqtref_t _type)
:
  expr(loc),
  expr_h(_expr_h),
  type(_type)
{
}

instanceof_expr::~instanceof_expr()
{
}

ostream& instanceof_expr::put( ostream& os) const
{
  os << INDENT << "instanceof_expr(" << this << ")\n";
  os << DENT << "[\n";
  //d Assert<null_pointer>(expr_h!=NULL);
  Assert(expr_h!=NULL);
  expr_h->put(os) << endl;
  os << "instance of\n";
  // TODO(VRB) os << sequence_type::describe(type);
  os << DENT << "]\n"; UNDENT;
  return os;
}

void instanceof_expr::accept(
  expr_visitor& v)
{
  if (!v.begin_visit(*this)) return;
  expr_h->accept(v);
  v.end_visit(*this);  
}



// [55] [http://www.w3.org/TR/xquery/#prod-xquery-TreatExpr]

treat_expr::treat_expr(
  yy::location const& loc,
  rchandle<expr> _expr_h,
  TypeSystem::xqtref_t _type)
:
  expr(loc),
  expr_h(_expr_h),
  type(_type)
{
}

treat_expr::~treat_expr()
{
}

ostream& treat_expr::put( ostream& os) const
{
  os << INDENT << "treat_expr(" << this << ")\n";
  os << DENT << "[\n";
  //d Assert<null_pointer>(expr_h!=NULL);
  Assert(expr_h!=NULL);
  expr_h->put(os) << endl;
  os << "treat as\n";
  // TODO(VRB) os << sequence_type::describe(type);
  os << DENT << "]\n"; UNDENT;
  return os;
}

void treat_expr::accept(
  expr_visitor& v)
{
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [56] [http://www.w3.org/TR/xquery/#prod-xquery-CastableExpr]

castable_expr::castable_expr(
  yy::location const& loc,
  rchandle<expr> _expr_h,
  TypeSystem::xqtref_t _type)
:
  expr(loc),
  expr_h(_expr_h),
  type(_type)
{
}

castable_expr::~castable_expr()
{
}

ostream& castable_expr::put( ostream& os) const
{
  os << INDENT << "castable_expr(" << this << ")\n";
  os << DENT << "[\n";
  //d Assert<null_pointer>(expr_h!=NULL);
  Assert(expr_h!=NULL);
  expr_h->put(os) << endl;
  os << "castable as\n";
  // TODO(VRB) os << sequence_type::describe(get_type());
  if (is_optional()) os << "?";
  os << DENT << "]\n"; UNDENT;
  return os;
}

void castable_expr::accept(
  expr_visitor& v)
{
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [57] [http://www.w3.org/TR/xquery/#prod-xquery-CastExpr]

cast_expr::cast_expr(
  yy::location const& loc,
  rchandle<expr> _expr_h,
  TypeSystem::xqtref_t _type)
:
  expr(loc),
  expr_h(_expr_h),
  type(_type)
{
}

cast_expr::~cast_expr()
{
}

ostream& cast_expr::put( ostream& os) const
{
  os << INDENT << "cast_expr(" << this << ")\n";
  os << DENT << "[\n";

  Assert(expr_h!=NULL);
  expr_h->put(os) << endl;
  os << "cast as\n";
  // TODO(VRB) os << sequence_type::describe(type);
  if (is_optional()) os << "?";
  os << DENT << "]\n"; UNDENT;
  return os;
}

void cast_expr::accept(
  expr_visitor& v)
{
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}


// [63] [http://www.w3.org/TR/xquery/#prod-xquery-ValidateExpr]

validate_expr::validate_expr(
  yy::location const& loc,
  enum validation_mode_t _valmode,
  rchandle<expr> _expr_h)
:
  expr(loc),
  valmode(_valmode),
  expr_h(_expr_h)
{
}

validate_expr::~validate_expr()
{
}

ostream& validate_expr::put( ostream& os) const
{
  os << INDENT << "validate_expr(" << this << ")\n";
  os << DENT << "[\n";

  switch (valmode) {
  case val_strict: os << "strict\n"; break;
  case val_lax: os << "lax\n"; break;
  default: os << "??\n";
  }
  //d Assert<null_pointer>(expr_h!=NULL);
  Assert(expr_h!=NULL);
  expr_h->put(os) << endl;
  os << DENT << "]\n"; UNDENT;
  return os;
}

void validate_expr::accept(
  expr_visitor& v)
{
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [65] [http://www.w3.org/TR/xquery/#prod-xquery-ExtensionExpr]

extension_expr::extension_expr(
  yy::location const& loc)
:
  expr(loc)
{
}

extension_expr::extension_expr(
  yy::location const& loc,
  expr_t _expr_h)
:
  expr(loc),
  expr_h(_expr_h)
{
}

extension_expr::~extension_expr()
{
}

ostream& extension_expr::put( ostream& os) const
{
  os << INDENT << "extension_expr(" << this << ")\n";
  os << DENT << "[\n";

  /*
  vector<rchandle<pragma> >::const_iterator it = begin();
  for (; it!=end(); ++it) {
    os << INDENT;
    rchandle<pragma> p_h = *it;
    Assert<null_pointer>(p_h!=NULL);
    Assert<null_pointer>(p_h->name_h!=NULL);
    os << "?"; p_h->name_h->put(zorp,os);
    os << " " << p_h->content << endl;
    UNDENT;
  }
  */

  os << INDENT;
  //d Assert<null_pointer>(pragma_h!=NULL);
  Assert(pragma_h!=NULL);
  //d Assert<null_pointer>(pragma_h->name_h!=NULL);
  Assert(pragma_h->name_h!=NULL);
  os << "?"; put_qname (pragma_h->name_h, os);
  os << " " << pragma_h->content << endl;
  UNDENT;

  //d Assert<null_pointer>(expr_h!=NULL);
  Assert(expr_h!=NULL);
  expr_h->put(os) << endl;
  os << DENT << "]\n"; UNDENT;
  return os;
}

void extension_expr::accept(
  expr_visitor& v)
{
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}


/*******************************************************************************

 [69] [http://www.w3.org/TR/xquery/#prod-xquery-RelativePathExpr]

  RelativPathExpr ::= "/" | ("/" | "//")?  StepExpr (("/" | "//") StepExpr)*

********************************************************************************/
relpath_expr::relpath_expr(yy::location const& loc)
  :
  expr(loc)
{
}


relpath_expr::~relpath_expr()
{
}


ostream& relpath_expr::put( ostream& os) const
{
  os << INDENT << "relpath_expr(" << this << ")\n";
  os << DENT << "[\n";

  for (list_iterator<expr_t> it = begin(); it != end(); ++it)
  {
    expr_t expr = *it;
    Assert(expr != NULL);
    expr->put(os);
  }
  os << DENT << "]\n"; UNDENT;
  return os;
}


void relpath_expr::accept(expr_visitor& v)
{
  if (!v.begin_visit(*this)) return;

  for (list_iterator<expr_t> it = begin(); it != end(); ++it)
  {
    expr_t expr = *it;
    Assert(expr != NULL);
    expr->accept(v);
  }

  v.end_visit(*this);
}


/*******************************************************************************

  [71] [http://www.w3.org/TR/xquery/#prod-xquery-AxisStep]

  AxisStep ::= Axis NodeTest Predicate*

********************************************************************************/
axis_step_expr::axis_step_expr(yy::location const& loc)
  :
  expr(loc)
{
}


axis_step_expr::~axis_step_expr()
{
}


ostream& axis_step_expr::put(ostream& os) const
{
  os << INDENT << "axis_step_expr(" << this << ")\n";
  os << DENT << "[\n";

  os << INDENT;
  switch (theAxis)
  {
  case axis_kind_self:                os << "self::"; break;
  case axis_kind_child:               os << "child::"; break;
  case axis_kind_parent:              os << "parent::"; break;
  case axis_kind_descendant:          os << "descendant::"; break;
  case axis_kind_descendant_or_self:  os << "descendant-or-self::"; break;
  case axis_kind_ancestor:            os << "ancestor::"; break;
  case axis_kind_ancestor_or_self:    os << "ancestor-or-self::"; break;
  case axis_kind_following_sibling:   os << "following-sibling::"; break;
  case axis_kind_following:           os << "following::"; break;
  case axis_kind_preceding_sibling:   os << "preceding-sibling::"; break;
  case axis_kind_preceding:           os << "preceding::"; break;
  case axis_kind_attribute:           os << "attribute::"; break;
  default: os << "??";
  }
  UNDENT;

  int saveIndent = printdepth0;
  printdepth0 = 0;

  if (theNodeTest != NULL)
    theNodeTest->put(os);

  printdepth0 = saveIndent;
  
  for (vector<rchandle<expr> >::const_iterator it = thePreds.begin();
       it != thePreds.end(); ++it)
  {
    rchandle<expr> e = *it;
    //d Assert<null_pointer>(e_h!=NULL);
    Assert(e != NULL);
    e->put(os);
  }

  os << DENT << "]\n"; UNDENT;
  return os;
}


void axis_step_expr::accept(expr_visitor& v)
{
  if (!v.begin_visit(*this)) return;

  for_each (thePreds.begin (), thePreds.end (), visitor_functor (v));

  ACCEPT (theNodeTest);

  v.end_visit(*this);
}


/*******************************************************************************

  [78] NodeTest ::= KindTest | NameTest

  [79] NameTest ::= QName | Wildcard
  [80] Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)

  [123] KindTest ::= DocumentTest | ElementTest | AttributeTest |
                     SchemaElementTest | SchemaAttributeTest |
                     PITest | CommentTest | TextTest | AnyKindTest

********************************************************************************/
match_expr::match_expr(yy::location const& loc)
  :
  expr(loc),
  theWildKind(match_no_wild),
  theQName(NULL),
  theTypeName(NULL),
  theNilledAllowed(false)
{
}


match_expr::~match_expr()
{
}


ostream& match_expr::put(ostream& os) const
{
  os << INDENT << "match_expr[";
  switch (theTestKind)
  {
  case match_no_test:   os << "no_test("; break;
  case match_name_test: os << "name_test("; break;
  case match_doc_test:
  {
    os << "doc_test(";
    switch (theDocTestKind)
    {
    case match_no_test:   os << "no_test("; break;
    case match_elem_test: os << "element("; break;
    case match_attr_test: os << "attribute("; break;
    default: os << "(??";
    }
    break;
  }
  case match_elem_test:     os << "element("; break;
  case match_attr_test:     os << "attribute("; break;
  case match_xs_elem_test:  os << "schema-element("; break;
  case match_xs_attr_test:  os << "schema-element("; break;
  case match_pi_test:       os << "pi("; break;
  case match_comment_test:  os << "comment("; break;
  case match_text_test:     os << "text("; break;
  case match_anykind_test:  os << "node("; break;
  default: os << "(??";
  }

  switch (theWildKind)
  {
    case match_no_wild:
      if (theQName != NULL)
        put_qname (theQName, os);
      break;
    case match_all_wild:
      os << "*";
      break;
    case match_prefix_wild:
      os << "*:" << theWildName;
      break;
    case match_name_wild:
      os << theWildName << ":*";
      break;
    default:
      os << "??";
  }

  if (theTypeName != NULL)
  {
    put_qname (theTypeName, os) << endl;
  }

  os << ")";
  return os << "]\n";
}


void match_expr::accept(expr_visitor& v)
{
  if (!v.begin_visit(*this)) return;
  v.end_visit(*this);
}


StoreConsts::NodeKind_t match_expr::getNodeKind() const
{
  switch (theTestKind)
  {
  case match_name_test:
    return StoreConsts::elementNode;
  case match_doc_test:
    return StoreConsts::elementNode;
  case match_elem_test:
    return StoreConsts::elementNode;
  case match_attr_test:
    return StoreConsts::attributeNode;
  case match_xs_elem_test:
    return StoreConsts::elementNode;
  case match_xs_attr_test:
    return StoreConsts::attributeNode;
  case match_pi_test:
    return StoreConsts::piNode;
  case match_text_test:
    return StoreConsts::textNode;
  case match_comment_test:
    return StoreConsts::commentNode;
  case match_anykind_test:
    return StoreConsts::anyNode;
  default:
    ZORBA_ASSERT (false && "Unknown node test kind");
  }
  return StoreConsts::anyNode;
}


// [84] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]



// [85] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]

const_expr::const_expr(yy::location const& loc,
                           xqpString v)
  :
  expr(loc),
  val (ITEM_FACTORY.createString (v))
{
}

const_expr::const_expr(yy::location const& loc,
                           xqp_integer v)
:
  expr(loc),
  val (ITEM_FACTORY.createInteger (v))
{
}

const_expr::const_expr(
  yy::location const& loc,
  xqp_decimal v)
:
  expr(loc),
  val (ITEM_FACTORY.createDecimal (v))
{
}

const_expr::const_expr(
  yy::location const& loc,
  xqp_double v)
:
  expr(loc),
  val (ITEM_FACTORY.createDouble (v))
{
}

const_expr::const_expr(
  yy::location const& loc,
  xqp_boolean v)
:
  expr(loc),
  val (ITEM_FACTORY.createBoolean (v))
{
}

const_expr::const_expr(
  yy::location const& loc,
  Item_t v)
:
  expr(loc),
  val(v)
{
}

const_expr::const_expr(
  yy::location const& aLoc, 
  const char* aNamespace,
  const char* aPrefix, 
  const char* aLocal)
:
  expr(aLoc),
  val ((Item*)&*ITEM_FACTORY.createQName(aNamespace, aPrefix, aLocal))
{
}

const_expr::~const_expr()
{
}

ostream& const_expr::put( ostream& os) const
{
  os << INDENT << "const_expr(" << this << ")[ " << val->getStringProperty()
     << " ]\n"; UNDENT;
  return os;
}

void const_expr::accept(
  expr_visitor& v)
{
  if (!v.begin_visit(*this)) return;
  v.end_visit(*this);
}



// [91] [http://www.w3.org/TR/xquery/#prod-xquery-OrderedExpr]

order_expr::order_expr(
  yy::location const& loc,
  order_type_t _type,
  rchandle<expr> _expr_h)
:
  expr(loc),
  type(_type),
  expr_h(_expr_h)
{
}

order_expr::~order_expr()
{
}

ostream& order_expr::put( ostream& os) const
{
  os << INDENT << "order_expr(" << this << ")\n";
  os << DENT << "[ ";

  switch (type) 
  {
  case ordered: os << "ordered\n"; break;
  case unordered: os << "unordered\n"; break;
  default: os << "??\n";
  }
  //d Assert<null_pointer>(expr_h!=NULL);
  Assert(expr_h!=NULL);
  expr_h->put(os) << endl;
  os << DENT << "]\n"; UNDENT;
  return os;
}

void order_expr::accept(
  expr_visitor& v)
{
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [93] [http://www.w3.org/TR/xquery/#prod-xquery-FunctionCall]

// [96] [http://www.w3.org/TR/xquery/#doc-exquery-DirElemConstructor]
elem_expr::elem_expr (
    yy::location const& aLoc,
    expr_t aQNameExpr,
    expr_t aAttrs,
    expr_t aContent )
    :
    constructor_expr ( aLoc ),
    theQNameExpr ( aQNameExpr ),
    theAttrs ( aAttrs ),
    theContent ( aContent )
{
}

elem_expr::elem_expr (
    yy::location const& aLoc,
    expr_t aQNameExpr,
    expr_t aContent )
    :
    constructor_expr ( aLoc ),
    theQNameExpr ( aQNameExpr ),
    theAttrs ( 0 ),
    theContent ( aContent )
{
}
  

elem_expr::~elem_expr()
{
}


void elem_expr::accept(expr_visitor& v)
{
  if (!v.begin_visit(*this)) return;
  ACCEPT (theQNameExpr);
  ACCEPT (theAttrs);
  ACCEPT (theContent);
  v.end_visit(*this);
}


std::ostream& elem_expr::put(std::ostream& os) const
{
  os << INDENT << "elem_expr(" << this << ")\n";
  os << DENT << "[\n";

  if (theQNameExpr != NULL)
    theQNameExpr->put(os);
  if (theAttrs != NULL)
    theAttrs->put(os);
  if (theContent != NULL)
    theContent->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

// [110] [http://www.w3.org/TR/xquery/#prod-xquery-CompDocConstructor]

doc_expr::doc_expr(
  yy::location const& loc,
  rchandle<expr> aContent)
:
  constructor_expr(loc),
  theContent(aContent)
{
}

doc_expr::~doc_expr()
{
}

ostream& doc_expr::put( ostream& os) const
{
  os << INDENT << "doc_expr(" << this << ")\n";
  os << DENT << "[\n";

  Assert(theContent != NULL);
  theContent->put(os);
  os << DENT << "]\n"; UNDENT;
  return os;
}

void doc_expr::accept(
  expr_visitor& v)
{
  if (!v.begin_visit(*this)) return;
  ACCEPT(theContent);
  v.end_visit(*this);
}



// [111] [http://www.w3.org/TR/xquery/#prod-xquery-CompElemConstructor]



// [113] [http://www.w3.org/TR/xquery/#prod-xquery-CompAttrConstructor]

attr_expr::attr_expr(
  yy::location const& loc,
  expr_t aQNameExpr,
  expr_t aValueExpr)
:
  constructor_expr(loc),
  theQNameExpr(aQNameExpr),
  theValueExpr(aValueExpr)
{
}

attr_expr::~attr_expr()
{
}

ostream& attr_expr::put( ostream& os) const
{
  os << INDENT << "attr_expr(" << this << ")\n";
  os << DENT << "[\n";

  theQNameExpr->put (os);
  
  if (theValueExpr != NULL)
  {
    os << "=";
    theValueExpr->put(os);
  }
  os << DENT << "]\n"; UNDENT;
  return os;
}

void attr_expr::accept(
  expr_visitor& v)
{
  if (!v.begin_visit(*this)) return;
  ACCEPT (theQNameExpr);
  ACCEPT (theValueExpr);
  v.end_visit(*this);
}



// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompTextConstructor]

text_expr::text_expr(
  yy::location const& loc,
  text_constructor_type type_arg,
  expr_t text_arg)
:
  constructor_expr(loc),
  type (type_arg),
  text(text_arg)
{
}

text_expr::~text_expr()
{
}

ostream& text_expr::put(ostream& os) const
{
  os << INDENT << "text_expr(" << this << ")\n";
  os << DENT << "[\n";

  text->put(os);

  os << DENT << "]\n"; UNDENT;
  return os;
}

void text_expr::accept(
  expr_visitor& v)
{
  if (!v.begin_visit(*this)) return;
  ACCEPT (text);
  v.end_visit(*this);
}



// [115] [http://www.w3.org/TR/xquery/#prod-xquery-CompCommentConstructor]


// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompPIConstructor]

pi_expr::pi_expr(
  yy::location const& loc,
  std::string _target,
  rchandle<expr> _content_expr_h)
:
  text_expr(loc, text_expr::pi_constructor, _content_expr_h),
  target(_target),
  target_expr_h(NULL)
{
}

pi_expr::pi_expr(
  yy::location const& loc,
  rchandle<expr> _target_expr_h,
  rchandle<expr> _content_expr_h)
:
  text_expr(loc, text_expr::pi_constructor, _content_expr_h),
  target(""),
  target_expr_h(_target_expr_h)
{
}

pi_expr::~pi_expr()
{
}

ostream& pi_expr::put( ostream& os) const
{
  os << INDENT << "pi_expr(" << this << ")\n";
  os << DENT << "[\n";

  os << INDENT << "target=";
  Assert(target.length() > 0 || target_expr_h != NULL);
  if (target.length() > 0) {
    os << target;
  }
  else {
    target_expr_h->put(os);
  }
  Assert(get_text () != NULL);
  os << ", content=";
  get_text ()->put(os);

  os << DENT << "]\n"; UNDENT;
  return os;
}

void pi_expr::accept(
  expr_visitor& v)
{
  ACCEPT (target_expr_h);
}



} /* namespace xqp */
/* vim:set ts=2 sw=2: */

