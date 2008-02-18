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
#include "types/root_typemanager.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace xqp {
  
#define ITEM_FACTORY (Store::getInstance().getItemFactory())

#define ACCEPT( m ) do { if ((m) != NULL) (m)->accept (v); } while (0)
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


void var_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR();
  END_VISITOR();
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


DECLARE_VISITOR_FUNCTOR (forletref_visitor_functor, flwor_expr::forletref_t, { ACCEPT (e->expr_h); });
DECLARE_VISITOR_FUNCTOR (orderspec_visitor_functor, flwor_expr::orderspec_t, { ACCEPT (e.first); });

void flwor_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR();

  for_each (clause_v.begin (), clause_v.end (), forletref_visitor_functor (v));
  
  ACCEPT (where_h);

  for_each (orderspec_rbegin (), orderspec_rend (), orderspec_visitor_functor (v));

  ACCEPT (retval_h);
  
  END_VISITOR(); 
}

expr::expr_t flwor_expr::clone(expr::substitution_t& substitution)
{
  expr_t flwor_copy = new flwor_expr(get_loc());
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

void promote_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR ();
  ACCEPT (input_expr_h);
  END_VISITOR ();
}


// [42] [http://www.w3.org/TR/xquery/#prod-xquery-QuantifiedExpr]

// [43] [http://www.w3.org/TR/xquery/#prod-xquery-TypeswitchExpr]

typeswitch_expr::typeswitch_expr(
  yy::location const& loc)
:
  expr(loc)
{
}


DECLARE_VISITOR_FUNCTOR (caseclause_visitor_functor, typeswitch_expr::clauseref_t, { ACCEPT (e->var_h); ACCEPT (e->case_expr_h); });

void typeswitch_expr::accept (expr_visitor& v) {
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


void if_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR();
  ACCEPT (cond_expr_h);
  ACCEPT (then_expr_h);
  ACCEPT (else_expr_h);
  END_VISITOR();
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

void fo_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR ();
  for_each (begin (), end (), visitor_functor (v));
  END_VISITOR ();
}

const signature &fo_expr::get_signature () const {
  return func->get_signature ();
}

Item_t fo_expr::get_fname () const
{ return func->get_fname (); }


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


void ft_contains_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR ();
  ACCEPT (range_h);
  ACCEPT (ft_select_h);
  ACCEPT (ft_ignore_h);
  END_VISITOR ();
}


// [54] [http://www.w3.org/TR/xquery/#prod-xquery-InstanceofExpr]

instanceof_expr::instanceof_expr(yy::location const& loc,
                                 rchandle<expr> _expr_h,
                                 xqtref_t _type)
:
  expr(loc), expr_h(_expr_h), type (_type)
{
}


void instanceof_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR();
  ACCEPT (expr_h);
  END_VISITOR();  
}


// [55] [http://www.w3.org/TR/xquery/#prod-xquery-TreatExpr]

treat_expr::treat_expr(
  yy::location const& loc,
  rchandle<expr> _expr_h,
  xqtref_t _type,
  enum ZorbaError::ErrorCodes err_)
:
  expr(loc),
  expr_h(_expr_h),
  type(_type),
  err (err_)
{
}


void treat_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}


// [56] [http://www.w3.org/TR/xquery/#prod-xquery-CastableExpr]

castable_expr::castable_expr(
  yy::location const& loc,
  rchandle<expr> _expr_h,
  xqtref_t _type)
:
  expr(loc),
  expr_h(_expr_h),
  type(_type)
{
}


void castable_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}


// [57] [http://www.w3.org/TR/xquery/#prod-xquery-CastExpr]

cast_expr::cast_expr(
  yy::location const& loc,
  rchandle<expr> _expr_h,
  xqtref_t _type)
:
  expr(loc),
  expr_h(_expr_h),
  type(_type)
{
}


void cast_expr::accept (expr_visitor& v) {
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


void validate_expr::accept (expr_visitor& v) {
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


void extension_expr::accept (expr_visitor& v) {
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


void relpath_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR();

  for_each (begin (), end (), visitor_functor (v));

  END_VISITOR();
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


void axis_step_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR();

  for_each (thePreds.begin (), thePreds.end (), visitor_functor (v));

  ACCEPT (theNodeTest);

  END_VISITOR();
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


void match_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR();
  END_VISITOR();
}


StoreConsts::NodeKind match_expr::getNodeKind() const
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


void const_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR();
  END_VISITOR();
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


void order_expr::accept (expr_visitor& v) {
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
    yy::location const& aLoc,
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
  


void elem_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR();
  ACCEPT (theQNameExpr);
  ACCEPT (theAttrs);
  ACCEPT (theContent);
  END_VISITOR();
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


void doc_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR();
  ACCEPT(theContent);
  END_VISITOR();
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


Item* attr_expr::getQName() const
{
  const_expr* qnExpr =  dynamic_cast<const_expr*>(theQNameExpr.getp());
  if (qnExpr != 0)
    return qnExpr->get_val().getp();

  return 0;
}


void attr_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR();
  ACCEPT (theQNameExpr);
  ACCEPT (theValueExpr);
  END_VISITOR();
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


void text_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR();
  ACCEPT (text);
  END_VISITOR();
}


// [115] [http://www.w3.org/TR/xquery/#prod-xquery-CompCommentConstructor]


// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompPIConstructor]

pi_expr::pi_expr(
  yy::location const& loc,
  rchandle<expr> _target_expr_h,
  rchandle<expr> _content_expr_h)
:
  text_expr(loc, text_expr::pi_constructor, _content_expr_h),
  target_expr_h(_target_expr_h)
{
}


void pi_expr::accept (expr_visitor& v) {
  BEGIN_VISITOR ();
  ACCEPT (target_expr_h);
  ACCEPT (text);
  END_VISITOR ();
}

void function_def_expr::accept (expr_visitor& v) {
}

function_def_expr::function_def_expr (yy::location const& loc, Item_t name_, std::vector<rchandle<var_expr> > &params_, xqtref_t return_type)
  : expr (loc), name (name_)
{
  assert (return_type != NULL);
  params.swap (params_);
  vector<xqtref_t> args;
  // TODO: copy param types into sig
  for (unsigned i = 0; i < param_size (); i++)
    args.push_back (GENV_TYPESYSTEM.ITEM_TYPE_STAR);
  sig = auto_ptr<signature> (new signature (get_name (), args, GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


} /* namespace xqp */
/* vim:set ts=2 sw=2: */
