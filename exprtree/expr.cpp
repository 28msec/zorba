/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: expr.cpp.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "expr.h"
#include "functions/function.h"
#include "parser/indent.h"
#include "parser/parse_constants.h"
#include "parser/parsenodes.h"
#include "util/Assert.h"
#include "util/tracer.h"
#include "util/xqp_exception.h"
//#include "values/qname.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace xqp {
  
int printdepth0 = 0;
#define DENT		indent[printdepth0 % 30]
#define INDENT	indent[++printdepth0 % 30]
#define OUTDENT	indent[printdepth0-- % 30]
#define UNDENT	printdepth0--

expr::expr(
	yy::location const& _loc)
:
	loc(_loc)
{
}

ostream& expr::put(zorba* zorp,ostream& os) const
{
	return os;
}



/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  XQuery 1.0 productions                                             //
//  [http://www.w3.org/TR/xquery/]                                     //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


// [31] [http://www.w3.org/TR/xquery/#prod-xquery-Expr]

expr_list::expr_list(
	yy::location const& loc)
:
	expr(loc)
{
}

expr_list::~expr_list()
{
}

ostream& expr_list::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "expr_list[\n";
	list_iterator<expr_t> it = begin();
	for (; it!=end(); ++it) {
		rchandle<expr> e_h = *it;
		if (e_h==NULL) {
			cout << TRACE << ": e_h==NULL\n";
			continue;
		}
		//cout << TRACE << ": typeid(*e_h) = " << typeid(*e_h).name() << endl;
		e_h->put(zorp,os);
	}
	return os << OUTDENT << "]\n";
}

void expr_list::accept(
	expr_visitor& v) const
{
  if (!v.begin_visit(*this)) return;
	list_iterator<expr_t> it = begin();
	for (; it!=end(); ++it) {
		rchandle<expr> e_h = *it;
		if (e_h==NULL) { cout << TRACE << ": e_h==NULL\n"; continue; }
		e_h->accept(v);
	}
	v.end_visit(*this);
}


// [33a]

var_expr::var_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

var_expr::~var_expr()
{
}

string var_expr::decode_var_kind(
	enum var_kind k)
{
	switch (k) {
	case for_var: return "FOR_VAR"; break;
	case let_var: return "LET_VAR"; break;
	case pos_var: return "POS_VAR"; break;
	case score_var: return "SCORE_VAR"; break;
	case quant_var: return "QUANT_VAR"; break;
	case extern_var: return "EXTERN_VAR"; break;
	case assign_var: return "ASSIGN_VAR"; break;
	case context_var: return "$DOT"; break;
	default: return "???";
	}
}

ostream& var_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "var_expr[" << decode_var_kind(get_kind());
	if (varname_h!=NULL) {
		os << " name=";
		get_varname()->put(zorp,os);
	}
	if (valexpr_h!=NULL) {
		os << ", expr=";
		get_valexpr()->put(zorp,os);
	}
	os << ", type=" << sequence_type::describe(type);
	return os << OUTDENT << "]\n";
}

void var_expr::accept(
	expr_visitor& v) const
{
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

ostream & forlet_clause::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "forlet[";
	switch (type) {
	case for_clause: os << "FOR\n"; break;
	case let_clause: os << "LET\n"; break;
	default: os << "??\n";
	}
	Assert<null_pointer>(var_h!=NULL);
	var_h->put(zorp,os);
	if (pos_var_h!=NULL) {
		os << INDENT << " AT "; pos_var_h->put(zorp,os); UNDENT;
	}
	if (score_var_h!=NULL) {
		os << INDENT << " SCORE "; score_var_h->put(zorp,os); UNDENT;
	}
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(zorp,os);
	return os << OUTDENT << "]\n";
}


flwor_expr::flwor_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

flwor_expr::~flwor_expr()
{
}

ostream& flwor_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "flwor_expr[\n";
	vector<forletref_t>::const_iterator it = clause_begin();
	for (; it!=clause_end(); ++it) {
		forletref_t fl_h = *it;
		Assert<null_pointer>(fl_h!=NULL);
		fl_h->put(zorp,os);
	}
	if (where_h!=NULL) where_h->put(zorp,os);

	vector<orderspec_t>::const_iterator ord_it = orderspec_begin();
	for (; ord_it!=orderspec_end(); ++ord_it) {
		orderspec_t spec = *ord_it;
		expr_t e_h = spec.first;
		Assert<null_pointer>(e_h!=NULL);
		orderref_t ord_h = spec.second;
		Assert<null_pointer>(ord_h!=NULL);

		os << INDENT << "ORDERBY\n";
		os << e_h->put(zorp,os) << endl;
		UNDENT;

		os << INDENT;
		switch (ord_h->dir) {
		case dir_ascending: os << "ASCENDING "; break;
		case dir_descending: os << "DESCENDING "; break;
		default: os << "?? ";
		}
		switch (ord_h->empty_mode) {
		case static_context::empty_greatest: os << "EMPTY GREATEST "; break;
		case static_context::empty_least: os << "EMPTY LEAST "; break;
		default: os << "?? ";
		}
		os << ord_h->collation << endl;
		UNDENT;
	}
	Assert<null_pointer>(retval_h!=NULL);
	os << INDENT << "RETURN\n"; retval_h->put(zorp,os); UNDENT;
	return os << OUTDENT << "]\n";

}

void flwor_expr::accept(
	expr_visitor& v) const
{
}



// [42] [http://www.w3.org/TR/xquery/#prod-xquery-QuantifiedExpr]

quantified_expr::quantified_expr(
	yy::location const& loc,
	enum quantification_mode_t _qmode)
:
	expr(loc),
	qmode(_qmode)
{
}

quantified_expr::~quantified_expr()
{
}

ostream& quantified_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "quantified_expr[";
	switch (qmode) {
	case quant_some: os << "SOME\n"; break;
	case quant_every: os << "EVERY\n"; break;
	default: os << "??\n";
	}

	vector<varref_t>::const_iterator it = var_v.begin();
	vector<varref_t>::const_iterator en = var_v.end();

	for (; it!=en; ++it) {
		varref_t var_h = *it;
		Assert<null_pointer>(var_h!=NULL);
		Assert<null_pointer>(var_h->varname_h!=NULL);
		os << INDENT;
		var_h->varname_h->put(zorp,os) << " in ";
		Assert<null_pointer>(var_h->valexpr_h!=NULL);
		var_h->valexpr_h->put(zorp,os) << endl;
		UNDENT;
	}

	os << " SATISFIES\n";
	Assert<null_pointer>(sat_expr_h!=NULL);
	sat_expr_h->put(zorp,os);
	return os << OUTDENT << "\n]\n";
}

void quantified_expr::accept(
	expr_visitor& v) const
{
}



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

ostream& typeswitch_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "typeswitch_expr[\n";
	Assert<null_pointer>(switch_expr_h!=NULL);
	switch_expr_h->put(zorp,os);

	vector<clauseref_t>::const_iterator it = case_clause_hv.begin();
	for (; it!=case_clause_hv.end(); ++it) {
		clauseref_t cc_h = *it;
		os << INDENT << "case: ";
		if (cc_h->var_h!=NULL) cc_h->var_h->put(zorp,os) << " as ";
		os << sequence_type::describe(cc_h->type) << " return ";
		Assert<null_pointer>(cc_h->case_expr_h!=NULL);
		cc_h->case_expr_h->put(zorp,os) << endl;
		UNDENT;
	}
	return os << OUTDENT << "]\n";
}

void typeswitch_expr::accept(
	expr_visitor& v) const
{
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

ostream& if_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "if_expr[\n";
	Assert<null_pointer>(cond_expr_h!=NULL);
	cond_expr_h->put(zorp,os);
	Assert<null_pointer>(then_expr_h!=NULL);
	then_expr_h->put(zorp,os);
	Assert<null_pointer>(else_expr_h!=NULL);
	else_expr_h->put(zorp,os);
	return os << OUTDENT << "\n]\n";
}

void if_expr::accept(
	expr_visitor& v) const
{
}



////////////////////////////////
//	first-order expressions
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


fo_expr::fo_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

fo_expr::~fo_expr()
{
}

ostream& fo_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "fo_expr[\n";
	Assert<null_pointer>(func!=NULL);
	os << INDENT << func->get_fname()->str(zorp) << endl;

	vector<rchandle<expr> >::const_iterator it = begin();
	for (; it!=end(); ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		e_h->put(zorp,os) << endl;
	}
	return os << OUTDENT << "]\n";
}

void fo_expr::accept(
	expr_visitor& v) const
{
	if (!v.begin_visit(*this)) return;
	vector<expr_t>::const_iterator it = begin();
	for (; it!=end(); ++it) {
		(*it)->accept(v);
	}
	v.end_visit(*this);
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

ostream& ft_contains_expr::put(zorba* zorp,ostream& os) const
{
	os << "ft_contains_expr[\n";
	Assert<null_pointer>(range_h!=NULL);
	range_h->put(zorp,os) << endl;
	Assert<null_pointer>(ft_select_h!=NULL);
	os << "ft_contains\n";
	ft_select_h->put(zorp,os) << endl;
	if (ft_ignore_h!=NULL) ft_ignore_h->put(zorp,os);
	return os << "\n]\n";
}

void ft_contains_expr::accept(
	expr_visitor& v) const
{
}




// [54] [http://www.w3.org/TR/xquery/#prod-xquery-InstanceofExpr]

instanceof_expr::instanceof_expr(
	yy::location const& loc,
	rchandle<expr> _expr_h,
	sequence_type_t _type)
:
	expr(loc),
	expr_h(_expr_h),
	type(_type)
{
}

instanceof_expr::~instanceof_expr()
{
}

ostream& instanceof_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "instanceof_expr[\n";
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(zorp,os) << endl;
	os << "instance of\n";
	os << sequence_type::describe(type);
	return os << OUTDENT << "]\n";
}

void instanceof_expr::accept(
	expr_visitor& v) const
{
}



// [55] [http://www.w3.org/TR/xquery/#prod-xquery-TreatExpr]

treat_expr::treat_expr(
	yy::location const& loc,
	rchandle<expr> _expr_h,
	sequence_type_t _type)
:
	expr(loc),
	expr_h(_expr_h),
	type(_type)
{
}

treat_expr::~treat_expr()
{
}

ostream& treat_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "treat_expr[\n";
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(zorp,os) << endl;
	os << "treat as\n";
	os << sequence_type::describe(type);
	return os << OUTDENT << "]\n";
}

void treat_expr::accept(
	expr_visitor& v) const
{
}



// [56] [http://www.w3.org/TR/xquery/#prod-xquery-CastableExpr]

castable_expr::castable_expr(
	yy::location const& loc,
	rchandle<expr> _expr_h,
	sequence_type_t _type)
:
	expr(loc),
	expr_h(_expr_h),
	type(_type)
{
}

castable_expr::~castable_expr()
{
}

ostream& castable_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "castable_expr[\n";
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(zorp,os) << endl;
	os << "castable as\n";
	os << sequence_type::describe(get_type());
	if (is_optional()) os << "?";
	return os << OUTDENT << "]\n";
}

void castable_expr::accept(
	expr_visitor& v) const
{
}



// [57] [http://www.w3.org/TR/xquery/#prod-xquery-CastExpr]

cast_expr::cast_expr(
	yy::location const& loc,
	rchandle<expr> _expr_h,
	sequence_type_t _type)
:
	expr(loc),
	expr_h(_expr_h),
	type(_type)
{
}

cast_expr::~cast_expr()
{
}

ostream& cast_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "cast_expr[\n";
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(zorp,os) << endl;
	os << "cast as\n";
	os << sequence_type::describe(type);
	if (is_optional()) os << "?";
	return os << OUTDENT << "]\n";
}

void cast_expr::accept(
	expr_visitor& v) const
{
}



// [58] [http://www.w3.org/TR/xquery/#prod-xquery-UnaryExpr]

unary_expr::unary_expr(
	yy::location const& loc,
	bool _neg_b,
	rchandle<expr> _expr_h)
:
	expr(loc),
	neg_b(_neg_b),
	expr_h(_expr_h)
{
}

unary_expr::~unary_expr()
{
}

ostream& unary_expr::put(zorba* zorp,ostream& os) const
{
	os << "unary_expr[";
	os << (neg_b ? "MINUS\n" : "\n");
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(zorp,os) << endl;
	return os << "]\n";
}

void unary_expr::accept(
	expr_visitor& v) const
{
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

ostream& validate_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "validate_expr[";
	switch (valmode) {
	case val_strict: os << "strict\n"; break;
	case val_lax: os << "lax\n"; break;
	default: os << "??\n";
	}
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(zorp,os) << endl;
	return os << OUTDENT << "]\n";
}

void validate_expr::accept(
	expr_visitor& v) const
{
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

ostream& extension_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "extension_expr[\n";
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
	Assert<null_pointer>(pragma_h!=NULL);
	Assert<null_pointer>(pragma_h->name_h!=NULL);
	os << "?"; pragma_h->name_h->put(zorp,os);
	os << " " << pragma_h->content << endl;
	UNDENT;

	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(zorp,os) << endl;
	return os << OUTDENT << "]\n";
}

void extension_expr::accept(
	expr_visitor& v) const
{
}



// [69] [http://www.w3.org/TR/xquery/#prod-xquery-RelativePathExpr]

relpath_expr::relpath_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

relpath_expr::~relpath_expr()
{
}

ostream& relpath_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "relpath_expr[\n";
	list_iterator<expr_t> it = begin();
	for (; it!=end(); ++it) {
		expr_t e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		e_h->put(zorp,os);
	}
	return os << OUTDENT << "]\n";
}

void relpath_expr::accept(
	expr_visitor& v) const
{
}



// match_epxr
// [123] [http://www.w3.org/TR/xquery/#prod-xquery-KindTest]

match_expr::match_expr(
	yy::location const& loc)
:
	expr(loc),
	wild(no_wild),
	name_h(NULL),
	typename_h(NULL)
{
}

match_expr::~match_expr()
{
}

ostream& match_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "match_expr[";
	switch (test) {
	case no_test:   os << "no_test("; break;
	case name_test: os << "name_test("; break;
	case doc_test: {
		os << "doc_test(";
		switch (docnode_test) {
		case no_test:   os << "no_test("; break;
		case elem_test: os << "element("; break;
		case attr_test: os << "attribute("; break;
		default: os << "(??";
		}
		break;
	}
	case elem_test:			os << "element("; break;
	case attr_test:			os << "attribute("; break;
	case xs_elem_test:	os << "schema-element("; break;
	case xs_attr_test:	os << "schema-element("; break;
	case pi_test:				os << "pi("; break;
	case comment_test:	os << "comment("; break;
	case text_test:			os << "text("; break;
	case anykind_test:	os << "anykind("; break;
	default: os << "(??";
	}
	if (name_h!=NULL) {
  	switch (wild) {
  	case no_wild: name_h->put(zorp,os); break;
  	case all_wild: os << "*"; break;
  	case prefix_wild: os << "*:"; name_h->put(zorp,os); break;
  	case name_wild: name_h->put(zorp,os) << ":*"; break;
  	default: os << "??";
  	}
  }
	if (typename_h!=NULL) {
		typename_h->put(zorp,os) << endl;
	}
	os << ")\n";
	return os << OUTDENT << "]\n";
}

void match_expr::accept(
	expr_visitor& v) const
{
}



// [70] [http://www.w3.org/TR/xquery/#prod-xquery-StepExpr]
// [71] [http://www.w3.org/TR/xquery/#prod-xquery-AxisStep]

axis_step_expr::axis_step_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

axis_step_expr::~axis_step_expr()
{
}

ostream& axis_step_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "axis_step_expr[";
	switch (axis) {
	case self:								os << "self::"; break;
	case child:								os << "child::"; break;
	case parent:							os << "parent::"; break;
	case descendant:					os << "descendant::"; break;
	case descendant_or_self:	os << "descendant-or-self::"; break;
	case ancestor:						os << "ancestor::"; break;
	case ancestor_or_self:		os << "ancestor-or-self::"; break;
	case following_sibling:		os << "following-sibling::"; break;
	case following:						os << "following::"; break;
	case preceding_sibling:		os << "preceding-sibling::"; break;
	case preceding:						os << "preceding::"; break;
	case attribute:						os << "attribute::"; break;
	default: os << "??";
	}
	os << endl;

	if (test_h!=NULL) {
		test_h->put(zorp,os);
  }
	if (name_h!=NULL) {
		name_h->put(zorp,os);
  }
	vector<rchandle<expr> >::const_iterator it = pred_hv.begin();
	vector<rchandle<expr> >::const_iterator en = pred_hv.end();
	for (; it!=en; ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		e_h->put(zorp,os);
	}
	return os << OUTDENT << "]\n";
}

void axis_step_expr::accept(
	expr_visitor& v) const
{
}



// [84] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]



// [85] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]

literal_expr::literal_expr(
	yy::location const& loc,
	const string& _sval)
:
	expr(loc),
	type(lit_string),
	sval(_sval)
{
}

literal_expr::literal_expr(
	yy::location const& loc,
	int i)
:
	expr(loc),
	type(lit_integer),
	ival(i)
{
}

literal_expr::literal_expr(
	yy::location const& loc,
	decimal d)
:
	expr(loc),
	type(lit_decimal),
	decval(d)
{
}

literal_expr::literal_expr(
	yy::location const& loc,
	double d)
:
	expr(loc),
	type(lit_double),
	dval(d)
{
}

literal_expr::~literal_expr()
{
}

string literal_expr::decode_type(enum literal_type_t t) 
{
	switch (t) {
	case lit_string: return "STRING"; break;
	case lit_integer: return "INTEGER"; break;
	case lit_decimal: return "DECIMAL"; break;
	case lit_double: return "DOUBLE"; break;
	default: return "???";
	}
}

ostream& literal_expr::put(zorba* zorp,ostream& os) const
{
	switch (type) {
	case lit_string: os << INDENT << "string[" << sval; break;
	case lit_integer: os << INDENT << "integer[" << ival; break;
	case lit_decimal: os << INDENT << "decimal[" << decval; break;
	case lit_double: os << INDENT << "double[" << dval; break;
	default: os << INDENT << "???[]";
	}
	return os << OUTDENT << "]\n";
}

void literal_expr::accept(
	expr_visitor& v) const
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

ostream& order_expr::put(zorba* zorp,ostream& os) const
{
	os << "order_expr[";
	switch (type) {
	case ordered: os << "ordered\n"; break;
	case unordered: os << "unordered\n"; break;
	default: os << "??\n";
	}
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(zorp,os) << endl;
	return os << "]\n";
}

void order_expr::accept(
	expr_visitor& v) const
{
}



// [93] [http://www.w3.org/TR/xquery/#prod-xquery-FunctionCall]



// [110] [http://www.w3.org/TR/xquery/#prod-xquery-CompDocConstructor]

doc_expr::doc_expr(
	yy::location const& loc,
	rchandle<expr> _docuri_h)
:
	expr(loc),
	docuri_h(_docuri_h)
{
}

doc_expr::~doc_expr()
{
}

ostream& doc_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "doc_expr[\n";
	Assert<null_pointer>(docuri_h!=NULL);
	docuri_h->put(zorp,os);
	return os << OUTDENT << "]\n";
}

void doc_expr::accept(
	expr_visitor& v) const
{
}



// [111] [http://www.w3.org/TR/xquery/#prod-xquery-CompElemConstructor]

elem_expr::elem_expr(
	yy::location const& loc,
	rchandle<qname_expr> _qname_h,
	rchandle<expr> _content_expr_h)
:
	expr(loc),
	qname_h(_qname_h),
	qname_expr_h(NULL),
	content_expr_h(_content_expr_h)
{
}

elem_expr::elem_expr(
	yy::location const& loc,
	rchandle<expr> _qname_expr_h,
	rchandle<expr> _content_expr_h)
:
	expr(loc),
	qname_h(NULL),
	qname_expr_h(_qname_expr_h),
	content_expr_h(_content_expr_h)
{
}

elem_expr::~elem_expr()
{
}

ostream& elem_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "elem_expr[<";
	Assert<bad_arg>(qname_h!=NULL || qname_expr_h!=NULL);
	if (qname_h!=NULL) {
		qname_h->put(zorp,os) << ">\n";
	}
	else {
		qname_expr_h->put(zorp,os) << ">\n";
	}
	vector<nsbinding>::const_iterator it = ns_begin();
	vector<nsbinding>::const_iterator en = ns_end();
	for (; it!=en; ++it) {
		nsbinding nsb = *it;
		string ncname = nsb.first;
		string nsuri = nsb.second;
		os << INDENT << "xmlns:" << ncname << "=\"" << nsuri << "\"\n"; UNDENT;
	}
	Assert<null_pointer>(content_expr_h!=NULL);
	content_expr_h->put(zorp,os);
	return os << OUTDENT << "]\n";
}

void elem_expr::accept(
	expr_visitor& v) const
{
}



// [113] [http://www.w3.org/TR/xquery/#prod-xquery-CompAttrConstructor]

attr_expr::attr_expr(
	yy::location const& loc,
	rchandle<qname_expr> _qname_h,
	rchandle<expr> _val_expr_h)
:
	expr(loc),
	qname_h(_qname_h),
	qname_expr_h(NULL),
	val_expr_h(_val_expr_h)
{
}

attr_expr::attr_expr(
	yy::location const& loc,
	rchandle<expr> _qname_expr_h,
	rchandle<expr> _val_expr_h)
:
	expr(loc),
	qname_h(NULL),
	qname_expr_h(_qname_expr_h),
	val_expr_h(_val_expr_h)
{
}

attr_expr::~attr_expr()
{
}

ostream& attr_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "attr_expr[@";
	Assert<bad_arg>(qname_h!=NULL || qname_expr_h!=NULL);
	if (qname_h!=NULL) {
		qname_h->put(zorp,os);
	}
	else {
		qname_expr_h->put(zorp,os);
	}
	Assert<null_pointer>(val_expr_h!=NULL);
	os << "=";
	val_expr_h->put(zorp,os);
	return os << OUTDENT << "]\n";
}

void attr_expr::accept(
	expr_visitor& v) const
{
}



// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompTextConstructor]

text_expr::text_expr(
	yy::location const& loc,
	rchandle<expr> _text_expr_h)
:
	expr(loc),
	text_expr_h(_text_expr_h)
{
}

text_expr::~text_expr()
{
}

ostream& text_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "text_expr[";
	Assert<null_pointer>(text_expr_h!=NULL);
	text_expr_h->put(zorp,os);
	return os << OUTDENT << "]\n";
}

void text_expr::accept(
	expr_visitor& v) const
{
}



// [115] [http://www.w3.org/TR/xquery/#prod-xquery-CompCommentConstructor]

comment_expr::comment_expr(
	yy::location const& loc,
	rchandle<expr> _comment_expr_h)
:
	expr(loc),
	comment_expr_h(_comment_expr_h)
{
}

comment_expr::~comment_expr()
{
}

ostream& comment_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "comment_expr[";
	Assert<null_pointer>(comment_expr_h!=NULL);
	comment_expr_h->put(zorp,os);
	return os << OUTDENT << "]\n";
}

void comment_expr::accept(
	expr_visitor& v) const
{
}



// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompPIConstructor]

pi_expr::pi_expr(
	yy::location const& loc,
	std::string _target,
	rchandle<expr> _content_expr_h)
:
	expr(loc),
	target(_target),
	target_expr_h(NULL),
	content_expr_h(_content_expr_h)
{
}

pi_expr::pi_expr(
	yy::location const& loc,
	rchandle<expr> _target_expr_h,
	rchandle<expr> _content_expr_h)
:
	expr(loc),
	target(""),
	target_expr_h(_target_expr_h),
	content_expr_h(_content_expr_h)
{
}

pi_expr::~pi_expr()
{
}

ostream& pi_expr::put(zorba* zorp,ostream& os) const
{
	os << INDENT << "pi_expr[target=";
	Assert<bad_arg>(target.length()>0 || target_expr_h!=NULL);
	if (target.length()>0) {
		os << target;
	}
	else {
		target_expr_h->put(zorp,os);
	}
	Assert<null_pointer>(content_expr_h!=NULL);
	os << ", context=";
	content_expr_h->put(zorp,os);
	return os << OUTDENT << "]\n";
}

void pi_expr::accept(
	expr_visitor& v) const
{
}



} /* namespace xqp */

