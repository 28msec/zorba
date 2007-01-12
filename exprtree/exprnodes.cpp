
/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: exprnodes.cpp.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "exprnodes.h"
#include "../parser/parse_constants.h"
#include "../util/Assert.h"
#include "../util/xqp_exception.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace xqp {
  
  

/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  XQuery 1.0 productions                                             //
//  [http://www.w3.org/TR/xquery/]                                     //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


// [31] [http://www.w3.org/TR/xquery/#prod-xquery-Expr]

expr_list::expr_list()
{
}

~expr_list::expr_list()
{
}

ostream& expr_list::put(ostream& os) const
{
	os << "expr_list[\n";
	vector<rchandle<expr> >::const_iterator it = begin();
	vector<rchandle<expr> >::const_iterator end = end();
	for (; it!=end; ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		e_h->put(os) << endl;
	}
	return os << "]\n";
}



// [33a]

std::ostream& var_binding::put(std::ostream&) const
{
	return os << "var_binding_expr[]\n";
}



// [33] [http://www.w3.org/TR/xquery/#prod-xquery-FLWORExpr]

flwor_expr::flwor_expr(
	yy::location const& loc)
:
	expr(loc),
{
}

~flwor_expr::flwor_expr()
{
}

ostream& flwor_expr::put(ostream& os) const
{
	os << "flwor_expr[\n";
	vector<rchandle<var_binding> >::const_iterator it = bind_hv.begin();
	vector<rchandle<var_binding> >::const_iterator end = bind_hv.end();
	for (; it!=end; ++it) put(os, *it);
	if (where_h!=NULL) where_h->put(os);
	if (orderby_h!=NULL) orderby_h->put(os);
	Assert<null_pointer>(retval_h!=NULL);
	retval_h->put(os);
	return os << "]\n";
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

~quantified_expr::quantified_expr()
{
}

ostream& quantified_expr::put(ostream& os)
{
	os << "quantified_expr[\n";
	switch (qmode) {
	case quant_some: os << "SOME\n"; break;
	case quant_every: os << "EVERY\n"; break;
	default: os << "??\n";
	}
	vector<var_binding>::const_iterator  it = bind_v.begin();
	vector<var_binding>::const_iterator end = bind_v.end();
	for (; it!=end; ++it) {
		var_binding vb = *it;
		Assert<null_pointer>(vb.varname_h!=NULL);
		vb.varname_h->put(os) << " in ";
		Assert<null_pointer>(vb.valexpr_h!=NULL);
		vb.valexpr_h->put(os) << endl;
	}
	os << " satisfies\n";
	Assert<null_pointer>(sat_expr_h!=NULL);
	sat_expr_h->put(os);
	return os << "\n]\n";
}



// [43] [http://www.w3.org/TR/xquery/#prod-xquery-TypeswitchExpr]

typeswitch_expr::typeswitch_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

~typeswitch_expr::typeswitch_expr()
{
}

ostream& typeswitch_expr::put(ostream& os)
{
	os << "typeswitch_expr[\n";
	Assert<null_pointer>(switch_expr_h!=NULL);
	switch_expr_h->put(os);
	vector<case_clause_t>::const_iterator  it = case_clause_hv.begin();
	vector<case_clause_t>::const_iterator end = case_clause_hv.end();
	for (; it!=end; ++it) {
		case_clause_t cc = *it;
		os << "case ";
		if (cc.varref_h!=NULL) cc.varref_h->put(os) << " as ";
		os << cc.seqtype.describe() << " return ";
		Assert<null_pointer>(cc.case_expr_h!=NULL);
		cc.case_expr_h->put(os) << endl;
	}
	return os << "\n]\n";
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

~if_expr::if_expr()
{
}

ostream& if_expr::put(ostream& os)
{
	os << "if_expr[\n";
	Assert<null_pointer>(cond_expr_h!=NULL);
	cond_expr_h->put(os);
	Assert<null_pointer>(then_expr_h!=NULL);
	then_expr_h->put(os);
	Assert<null_pointer>(else_expr_h!=NULL);
	else_expr_h->put(os);
	return os << "\n]\n";
}



// [46] [http://www.w3.org/TR/xquery/#prod-xquery-OrExpr]

or_expr::or_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

~or_expr::or_expr()
{
}

ostream& or_expr::put(ostream& os)
{
	os << "or_expr[\n";
	vector<rchandle<expr> >::const_iterator it = begin();
	vector<rchandle<expr> >::const_iterator end = end();
	for (; it!=end; ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		e_h->put(os) << endl;
	}
	return "]\n";
}



// [47] [http://www.w3.org/TR/xquery/#prod-xquery-AndExpr]

and_expr::and_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

~and_expr::and_expr()
{
}

ostream& and_expr::put(ostream& os)
{
	os << "and_expr[\n";
	vector<rchandle<expr> >::const_iterator it = begin();
	vector<rchandle<expr> >::const_iterator end = end();
	for (; it!=end; ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		e_h->put(os) << endl;
	}
	return "]\n";
}



// [48] [http://www.w3.org/TR/xquery/#prod-xquery-ComparisonExpr]

valcomp_expr::valcomp_expr(
	yy::location const& loc,
	enum valcomp_t _comp,
	rchandle<expr> lhs_h,
	rchandle<expr> rhs_h)
:
	expr(loc),
	comp(_comp),
	lhs_h(_lhs_h),
	rhs_h(_rhs_h)
{
}

~valcomp_expr::valcomp_expr()
{
}

ostream& valcomp_expr::put(ostream& os)
{
	os << "valcomp_expr[\n";
	Assert<null_pointer>(lhs_h!=NULL);
	lhs_h->put(os) << endl;
	switch (comp) {
	case op_val_eq: os << ".eq.\n"; break;
	case op_val_ne: os << ".ne.\n"; break;
	case op_val_lt: os << ".lt.\n"; break;
	case op_val_le: os << ".le.\n"; break;
	case op_val_gt: os << ".gt.\n"; break;
	case op_val_ge: os << ".ge.\n"; break;
	default: os << "??\n";
	}
	Assert<null_pointer>(rhs_h!=NULL);
	rhs_h->put(os) << endl;
	return "]\n";
}

gencomp_expr::gencomp_expr(
	yy::location const& loc,
	enum gencomp_t _comp,
	rchandle<expr> lhs_h,
	rchandle<expr> rhs_h)
:
	expr(loc),
	comp(_comp),
	lhs_h(_lhs_h),
	rhs_h(_rhs_h)
{
}

~gencomp_expr::gencomp_expr()
{
}

ostream& gencomp_expr::put(ostream& os)
{
	os << "gencomp_expr[\n";
	Assert<null_pointer>(lhs_h!=NULL);
	lhs_h->put(os) << endl;
	switch (comp) {
	case op_eq: os << "=\n"; break;
	case op_ne: os << "!=\n"; break;
	case op_lt: os << "<\n"; break;
	case op_le: os << "<=\n"; break;
	case op_gt: os << ">\n"; break;
	case op_ge: os << ">=\n"; break;
	default: os << "??\n";
	}
	Assert<null_pointer>(rhs_h!=NULL);
	rhs_h->put(os) << endl;
	return "]\n";
}

nodecomp_expr::nodecomp_expr(
	yy::location const& loc,
	enum nodecomp_t _comp,
	rchandle<expr> lhs_h,
	rchandle<expr> rhs_h)
:
	expr(loc),
	comp(_comp),
	lhs_h(_lhs_h),
	rhs_h(_rhs_h)
{
}

~nodecomp_expr::nodecomp_expr()
{
}

ostream& nodecomp_expr::put(ostream& os)
{
	os << "nodecomp_expr[\n";
	Assert<null_pointer>(lhs_h!=NULL);
	lhs_h->put(os) << endl;
	switch (comp) {
	case op_is: os << "is\n"; break;
	case op_preceeds: os << "<<\n"; break;
	case op_follows: os << ">>\n"; break;
	default: os << "??\n";
	}
	Assert<null_pointer>(rhs_h!=NULL);
	rhs_h->put(os) << endl;
	return "]\n";
}



// [48a] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTContainsExpr]

ft_contains_expr::ft_contains_expr(
	yy::location const& loc,
	rchandle<expr> _range_h,
	rchandle<ft_select_expr> _ft_select_h,
	rchandle<expr> _ignore_h)
:
	expr(loc),
	range_h(_range_h),
	ft_select_h(_ft_select_h),
	ignore_h(_ignore_h)
{
}

~ft_contains_expr::ft_contains_expr()
{
}

ostream& ft_contains_expr::put(ostream& os)
{
	os << "ft_contains_expr[\n";
	Assert<null_pointer>(range_h!=NULL);
	range_h->put(os) << endl;
	Assert(null_pointer>(ft_select_h!=NULL);
	os << "ft_contains\n";
	ft_select_h->put(os) << endl;
	if (ignore_h!=NULL) ignore_h->put(os);
	return os << "\n]\n";
}



// [49] [http://www.w3.org/TR/xquery/#prod-xquery-RangeExpr]

range_expr::range_expr(
	yy::location const& loc,
	rchandle<expr> _from_expr_h,
	rchandle<expr> _to_expr_h)
:
	expr(loc),
	from_expr_h(_from_expr_h),
	to_expr_h(_to_expr_h)
{
}

~range_expr::range_expr()
{
}

ostream& range_expr::put(ostream& os)
{
	return os << "range_expr[\n";
	Assert<null_pointer>(from_expr_h!=NULL);
	from_expr_h->put(os) << endl;
	Assert<null_pointer>(to_expr_h!=NULL);
	os "to\n";
	to_expr_h->put(os) << endl;
	return os << "\n]\n";
}



// [50] [http://www.w3.org/TR/xquery/#prod-xquery-AdditiveExpr]

add_expr::add_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

~add_expr::add_expr()
{
}

ostream& add_expr::put(ostream& os)
{
	os << "add_expr[\n";
	bool init = true;
	vector<rchandle<expr> >::const_iterator it = begin();
	vector<rchandle<expr> >::const_iterator end = end();
	for (; it!=end; ++it) {
		addop_pair addopp = *it;
		add_op_t op = addopp.first;
		rchandle<expr> e_h = addopp.second;
		Assert<null_pointer>(e_h!=NULL);
		if (op==op_minus) os << "-\n";
		if (!init && op==op_plus) os << "+\n";
		e_h->put(os) << endl;
		init = false;
	}
	return os << "]\n";
}



// [51] [http://www.w3.org/TR/xquery/#prod-xquery-MultiplicativeExpr]

mult_expr::mult_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

~mult_expr::mult_expr()
{
}

ostream& mult_expr::put(ostream& os)
{
	os << "mult_expr[\n";
	bool init = true;
	vector<rchandle<expr> >::const_iterator it = begin();
	vector<rchandle<expr> >::const_iterator end = end();
	for (; it!=end; ++it) {
		mulop_pair mulopp = *it;
		mul_op_t op = mulopp.first;
		rchandle<expr> e_h = mulopp.second;
		Assert<null_pointer>(e_h!=NULL);
		if (!init) {
			switch (op) {
			case op_times: os << "*\n"; break;
			case op_div: os << "div\n"; break;
			case op_idiv: os << "idiv\n"; break;
			case op_mod: os << "mod\n"; break;
			default: os << "??\n";
			}
		}
		else init = false;
		e_h->put(os) << endl;
	}
	return os << "]\n";
}



// [52] [http://www.w3.org/TR/xquery/#prod-xquery-UnionExpr]

union_expr::union_expr(
	yy::location const& loc)
	:
	expr(loc)
{
}

~union_expr::union_expr()
{
}

ostream& union_expr::put(ostream& os)
{
	os << "union_expr[\n";
	vector<rchandle<expr> >::const_iterator it = begin();
	vector<rchandle<expr> >::const_iterator end = end();
	for (; it!=end; ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		e_h->put(os) << endl;
	}
	return os << "]\n";
}



// [53] [http://www.w3.org/TR/xquery/#prod-xquery-IntersectExceptExpr]

intersect_except_expr::intersect_except_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

~intersect_except_expr::intersect_except_expr()
{
}

ostream& intersect_except_expr::put(ostream& os)
{
	os << "intersect_except_expr[\n";
	bool init = true;
	vector<rchandle<expr> >::const_iterator it = begin();
	vector<rchandle<expr> >::const_iterator end = end();
	for (; it!=end; ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		e_h->put(os) << endl;
	}
}



// [54] [http://www.w3.org/TR/xquery/#prod-xquery-InstanceofExpr]

instanceof_expr::instanceof_expr(
	yy::location const& loc,
	rchandle<expr> _expr_h,
	sequence_type _seqtype)
	:
	expr(loc),
	expr_h(_expr_h),
	seqtype(_seqtype)
{
}

~instanceof_expr::instanceof_expr()
{
}

ostream& instanceof_expr::put(ostream& os)
{
	os << "instanceof_expr[\n";
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(os) << endl;
	os << "instance of\n";
	os << seqtype.describe();
	return os << "\n]\n";
}



// [55] [http://www.w3.org/TR/xquery/#prod-xquery-TreatExpr]

treat_expr::treat_expr(
	yy::location const& loc)
	:
	expr(loc)
}



// [55] [http://www.w3.org/TR/xquery/#prod-xquery-TreatExpr]

treat_expr::treat_expr(
	yy::location const& loc,
	rchandle<expr> _expr_h,
	sequence_type _seqtype)
	:
	expr(loc),
	expr_h(_expr_h),
	seqtype(_seqtype)
{
}

~treat_expr::treat_expr()
{
}

ostream& treat_expr::put(ostream& os)
{
	os << "treat_expr[\n";
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(os) << endl;
	os << "treat as\n";
	os << seqtype.describe();
	return os << "\n]\n";
}



// [56] [http://www.w3.org/TR/xquery/#prod-xquery-CastableExpr]

castable_expr::castable_expr(
	yy::location const& loc,
	rchandle<expr> _expr_h,
	sequence_type _seqtype)
	:
	expr(loc),
	expr_h(_expr_h),
	seqtype(_seqtype)
{
}

~castable_expr::castable_expr()
{
}

ostream& castable_expr::put(ostream& os)
{
	os << "castable_expr[\n";
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(os) << endl;
	os << "castable as\n";
	os << seqtype.describe();
	return os << "\n]\n";
}



// [57] [http://www.w3.org/TR/xquery/#prod-xquery-CastExpr]

cast_expr::cast_expr(
	yy::location const& loc,
	rchandle<expr> _expr_h,
	sequence_type _seqtype)
	:
	expr(loc),
	expr_h(_expr_h),
	seqtype(_seqtype)
{
}

~cast_expr::cast_expr()
{
}

ostream& cast_expr::put(ostream& os)
{
	os << "cast_expr[\n";
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(os) << endl;
	os << "cast as\n";
	os << seqtype.describe();
	return os << "\n]\n";
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

~unary_expr::unary_expr()
{
}

ostream& unary_expr::put(ostream& os)
{
	os << "unary_expr[";
	os << (neg_b ? "MINUS\n" : "\n";
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(os) << endl;
	return os << "]\n";
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

~validate_expr::validate_expr()
{
}

ostream& validate_expr::put(ostream& os)
{
	os << "validate_expr[";
	switch (valmode) {
	case val_strict: os << "strict\n"; break;
	case val_lax: os << "lax\n"; break;
	default: os << "??\n";
	}
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(os) << endl;
	return os << "]\n";
}



// [65] [http://www.w3.org/TR/xquery/#prod-xquery-ExtensionExpr]

extension_expr::extension_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

~extension_expr::extension_expr()
{
}

ostream& extension_expr::put(ostream& os)
{
	os << "extension_expr[\n";
	vector<rchandle<pragma> >::const_iterator it = begin();
	vector<rchandle<pragma> >::const_iterator end = end();
	for (; it!=end; ++it) {
		rchandle<pragma> p_h = *it;
		Assert<null_pointer>(p_h!=NULL);
		Assert<null_pointer>(p_h->name_h!=NULL);
		p_h->name_h->put(os) << endl;
		os << p_h->content << endl;
	}
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(os) << endl;
	return os << "]\n";
}



// [69] [http://www.w3.org/TR/xquery/#prod-xquery-RelativePathExpr]

relpath_expr::relpath_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

~relpath_expr::relpath_expr()
{
}

ostream& relpath_expr::put(ostream& os)
{
	os << "relpath_expr[\n";
	vector<rchandle<step_expr> >::const_iterator it = begin();
	vector<rchandle<step_expr> >::const_iterator end = end();
	for (; it!=end; ++it) {
		rchandle<step_expr> se_h = *it;
		Assert<null_pointer>(se_h!=NULL);
		se_h->put(os) << endl;
	}
	return os << "]\n";
}



// [70] [http://www.w3.org/TR/xquery/#prod-xquery-StepExpr]

step_expr::step_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

~step_expr::step_expr()
{
}

ostream& step_expr::put(ostream& os)
{
	return os << "step_expr[]\n";
}



// [71] [http://www.w3.org/TR/xquery/#prod-xquery-AxisStep]

axis_step_expr::axis_step_expr(
	yy::location const& loc)
:
	expr(loc),
{
}

~axis_step_expr::axis_step_expr()
{
}

ostream& axis_step_expr::put(ostream& os)
{
	os << "axis_step_expr[";
	switch (axis) {
	case self: os << "self\n"; break;
	case child: os << "child\n"; break;
	case parent: os << "parent\n"; break;
	case descendant: os << "descendant\n"; break;
	case descendant-or-self: os << "descendant-or-self\n"; break;
	case ancestor: os << "ancestor\n"; break;
	case ancestor-or-self: os << "ancestor-or-self\n"; break;
	case following-sibling: os << "following-sibling\n"; break;
	case following: os << "following\n"; break;
	case preceding-sibling: os << "preceding-sibling\n"; break;
	case preceding: os << "preceding\n"; break;
	case attribute: os << "attribute\n"; break;
	default: os << "??\n";
	}

	switch (test) {
	case no_test: os << "no_test\n"; break;
	case name_test: os << "name_test\n"; break;
	case doc_test: {
		os << "doc_test\n";
		switch (docnode_test) {
		case no_test: os << "no_test\n"; break;
		case elem_test: os << "elem_test\n"; break;
		case attr_test: os << "attr_test\n"; break;
		default: os << "??\n";
		}
		break;
	}
	case elem_test: os << "elem_test\n"; break;
	case attr_test: os << "attr_test\n"; break;
	case xs_elem_test: os << "xs_elem_test\n"; break;
	case xs_attr_test: os << "xs_attr_test\n"; break;
	case pi_test: os << "pi_test\n"; break;
	case comment_test: os << "comment_test\n"; break;
	case text_test: os << "text_test\n"; break;
	case anykind_test: os << "anykind_test\n"; break;
	default: os << "??\n";
	}

	Assert<null_pointer>(name_h!=NULL);
	switch (wild) {
	case no_wild: name_h->put(os) << endl; break;
	case all_wild: os << "*\n"; break;
	case prefix_wild: os << "*:"; name_h->put(os) << endl; break;
	case name_wild: name_h->put(os) << ":*\n"; break;
	default: os << "??\n";
	}

	if (typename_h!=NULL) {
		typename_h->put(os) << endl;
	}

	vector<rchandle<expr> >::const_iterator it = pred_hv.begin();
	vector<rchandle<expr> >::const_iterator end = pred_hv.end();
	for (; it!=end; ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		e_h->put(os) << endl;
	}
	return os << "]\n";
}



// [84] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]

primary_expr::primary_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

~primary_expr::primary_expr()
{
}

ostream& primary_expr::put(ostream& os)
{
	return os << "primary_expr[]\n";
}



// [85] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]

literal_expr::literal_expr(
	yy::location const& loc,
	uint32_t _sref)
:
	expr(loc),
	type(lit_string),
	sref(_sref)
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

~literal_expr::literal_expr()
{
}

ostream& literal_expr::put(ostream& os)
{
	os << "literal_expr[\n";
	switch (type) {
	case lit_string: os << "string[" << sref << "]\n";
	case lit_integer: os << "integer[" << ival << "]\n";
	case lit_decimal: os << "decimal[" << decval << "]\n";
	case lit_double: os << "double[" << dval << "]\n";
	default: os << "??\n";
	}
	return os << "]\n";
}



// [87] [http://www.w3.org/TR/xquery/#prod-xquery-VarRef]

varref_expr::varref_expr(
	yy::location const& loc,
	string const& _varname)
:
	expr(loc),
	varname(_varname)
{
}

~varref_expr::varref_expr()
{
}

ostream& varref_expr::put(ostream& os)
{
	return os << "varref_expr[" << varname << "]\n";
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

~ordered_expr::ordered_expr()
{
}

ostream& ordered_expr::put(ostream& os)
{
	os << "order_expr[";
	switch (type) {
	case ordered: os << "ordered\n"; break;
	case unordered: os << "unordered\n"; break;
	default: os << "??\n";
	}
	Assert<null_pointer>(expr_h!=NULL);
	expr_h->put(os) << endl;
	return os << "]\n";
}



// [93] [http://www.w3.org/TR/xquery/#prod-xquery-FunctionCall]

funcall_expr::funcall_expr(
	yy::location const& loc,
	rchandle<QName> _fname_h)
:
	expr(loc),
	fname_h(_fname_h)
{
}

~funcall_expr::funcall_expr()
{
}

ostream& funcall_expr::put(ostream& os)
{
	os << "funcall_expr[";
	Assert<null_pointer>(fname_h!=NULL);
	fname_h->put(os) << endl;
	vector<rchandle<expr> >::const_iterator it = arg_hv.begin();
	vector<rchandle<expr> >::const_iterator end = arg_hv.end();
	for (; it!=end; ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		e_h->put(os) << endl;
	}
	return os << "]\n";
}



// [109] [http://www.w3.org/TR/xquery/#prod-xquery-ComputedConstructor]

cons_expr::cons_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

~cons_expr::cons_expr()
{
}

ostream& cons_expr::put(ostream& os)
{
	return os << "cons_expr[]\n";
}



// [110] [http://www.w3.org/TR/xquery/#prod-xquery-CompDocConstructor]

doc_expr::doc_expr(
	yy::location const& loc,
	rchandle<expr> _docuri_h)
:
	expr(loc),
	docuri_h(_docuri_h)
{
}

~doc_expr::doc_expr()
{
}

ostream& doc_expr::put(ostream& os)
{
	os << "doc_expr[\n";
	Assert<null_pointer>(docuri_h!=NULL);
	docuri_h->put(os) << endl;
	return os << "]\n";
}



// [111] [http://www.w3.org/TR/xquery/#prod-xquery-CompElemConstructor]

elem_expr::elem_expr(
	yy::location const& loc,
	rchandle<QName> _qname_h,
	rchandle<expr> _content_expr_h)
:
	expr(loc),
	qname_h(_qname_h),
	name_expr_h(NULL),
	content_expr_h(_content_expr_h)
{
}

elem_expr::elem_expr(
	yy::location const& loc,
	rchandle<expr> _name_expr_h,
	rchandle<expr> _content_expr_h)
:
	expr(loc),
	qname_h(NULL),
	name_expr_h(_name_expr_h),
	content_expr_h(_content_expr_h)
{
}

~elem_expr::elem_expr()
{
}

ostream& elem_expr::put(ostream& os)
{
	os << "elem_expr[\n";
	Assert<bad_arg>(qname_h!=NULL || name_expr_h!=NULL);
	if (qname_h!=NULL) {
		qname_h->put(os) << endl;
	}
	else {
		name_expr_h->put(os) << endl;
	}
	Assert<null_pointer>(content_expr_h!=NULL);
	content_expr_h->put(os) << endl;

	nsb_v;
	vector<rchandle<expr> >::const_iterator it = begin();
	vector<rchandle<expr> >::const_iterator end = end();
	for (; it!=end; ++it) {
		rchandle<nsbinding> nsb = *it;
		string ncname = nsb.first;
		string nsuri = nsb.second;
		os << "xmlns:" << ncname << "=\"" << nsuri << "\"\n";
	}
	return os << "]\n";
}



// [113] [http://www.w3.org/TR/xquery/#prod-xquery-CompAttrConstructor]

attr_expr(
	yy::location const& loc,
	rchandle<QName> _name_h,
	rchandle<expr> _val_expr_h)
:
	expr(loc),
	name_h(_name_h),
	name_expr_h(NULL),
	val_expr_h(_val_expr_h)
{
}

attr_expr(
	yy::location const&,
	rchandle<expr> _name_expr_h,
	rchandle<expr> _val_expr_h)
:
	expr(loc),
	name_h(NULL),
	name_expr_h(_name_expr_h),
	val_expr_h(_val_expr_h)
{
}

~attr_expr::attr_expr()
{
}

ostream& attr_expr::put(ostream& os)
{
	os << "attr_expr[\n";
	Assert<bad_arg>(name_h!=NULL || name_expr_h!=NULL);
	if (name_h!=NULL) {
		name_h->put(os) << endl;
	}
	else {
		name_expr_h->put(os) << endl;
	}
	Assert<null_pointer>(val_expr_h!=NULL);
	val_expr_h->put(os) << endl;
	return << "]\n";
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

~text_expr::text_expr()
{
}

ostream& text_expr::put(ostream& os)
{
	os << "text_expr[\n";
	Assert<null_pointer>(text_expr_h!=NULL);
	text_expr_h->put(os) << endl;
	return os << "]\n";
}



// [115] [http://www.w3.org/TR/xquery/#prod-xquery-CompCommentConstructor]

comment_expr::text_expr(
	yy::location const& loc,
	rchandle<expr> _comment_expr_h)
:
	expr(loc),
	comment_expr_h(_comment_expr_h)
{
}

~comment_expr::comment_expr()
{
}

ostream& comment_expr::put(ostream& os)
{
	os << "comment_expr[\n";
	Assert<null_pointer>(comment_expr_h!=NULL);
	comment_expr_h->put(os) << endl;
	return os << "]\n";
}



// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompPIConstructor]

std::string target;
rchandle<expr> target_expr_h;
rchandle<expr> content_expr_h;

pi_expr(
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

pi_expr(
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

~pi_expr::pi_expr()
{
}

ostream& pi_expr::put(ostream& os)
{
	os << "pi_expr[\n";
	Assert<bad_arg>(target.length()>0 || target_expr_h!=NULL);
	if (target.length()>0) {
		os << target << endl;
	}
	else {
		target_expr_h->put(os) << endl;
	}
	Assert<null_pointer>(content_expr_h!=NULL);
	content_expr_h->put(os) << endl;
	return << "]\n";
}




/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	Update productions                                                 //
//  [http://www.w3.org/TR/xqupdate/]                                   //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

// [242] [http://www.w3.org/TR/xqupdate/#prod-xquery-InsertExpr]

insert_expr::insert_expr(
	yy::location const& loc)
:
	expr(loc)
{
}

~insert_expr::insert_expr()
{
}

ostream& insert_expr::put(ostream& os)
{
	return os << "insert_expr[]\n";
}



// [243] [http://www.w3.org/TR/xqupdate/#prod-xquery-DeleteExpr]

delete_expr::delete_expr(
	yy::location const& loc)
	:
	expr(loc)
{
}

~delete_expr::delete_expr()
{
}

ostream& delete_expr::put(ostream& os)
{
	return os << "delete_expr[]\n";
}



// [244] [http://www.w3.org/TR/xqupdate/#prod-xquery-ReplaceExpr]

replace_expr::replace_expr(
	yy::location const& loc)
	:
	expr(loc)
{
}

~replace_expr::replace_expr()
{
}

ostream& replace_expr::put(ostream& os)
{
	return os << "replace_expr[]\n";
}



// [245] [http://www.w3.org/TR/xqupdate/#prod-xquery-RenameExpr]

rename_expr::rename_expr(
	yy::location const& loc)
	:
	expr(loc)
{
}

~rename_expr::rename_expr()
{
}

ostream& rename_expr::put(ostream& os)
{
	return os << "rename_expr[]\n";
}



// [249] [http://www.w3.org/TR/xqupdate/#prod-xquery-TransformExpr]

transform_expr::transform_expr(
	yy::location const& loc)
	:
	expr(loc)
{
}

~transform_expr::transform_expr()
{
}

ostream& transform_expr::put(ostream& os)
{
	return os << "transform_expr[]\n";
}




/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  Full-text productions                                              //
//  [http://www.w3.org/TR/xquery-full-text/]                           //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

//[344] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTSelection]

ft_expr::ft_expr(
	yy::location const& loc)
	:
	expr(loc)
{
}

~ft_expr::ft_expr()
{
}

ostream& ft_expr::put(ostream& os)
{
	return os << "ft_expr[]\n";
}



//[345] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTOr]

ft_or_expr::ft_or_expr(
	yy::location const& loc)
	:
	expr(loc)
{
}

~ft_or_expr::ft_or_expr()
{
}

ostream& ft_or_expr::put(ostream& os)
{
	return os << "ft_or_expr[]\n";
}



//[346] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTAnd]

ft_and_expr::ft_and_expr(
	yy::location const& loc)
	:
	expr(loc)
{
}

~ft_and_expr::ft_and_expr()
{
}

ostream& ft_and_expr::put(ostream& os)
{
	return os << "ft_and_expr[]\n";
}



//[347] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTMildnot]

ft_mildnot_expr::ft_mildnot_expr(
	yy::location const& loc)
	:
	expr(loc)
{
}

~ft_mildnot_expr::ft_mildnot_expr()
{
}

ostream& ft_mildnot_expr::put(ostream& os)
{
	return os << "ft_mildnot_expr[]\n";
}



//[348] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTUnaryNot]

ft_unarynot_expr::ft_unarynot_expr(
	yy::location const& loc)
	:
	expr(loc)
{
}

~ft_unarynot_expr::ft_unarynot_expr()
{
}

ostream& ft_unarynot_expr::put(ostream& os)
{
	return os << "ft_unarynot_expr[]\n";
}



//[349] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWordsSelection]

ft_words_selection_expr::ft_words_selection_expr(
	yy::location const& loc)
	:
	expr(loc)
{
}

~ft_words_selection_expr::ft_words_selection_expr()
{
}

ostream& ft_words_selection_expr::put(ostream& os)
{
	return os << "ft_words_selection_expr[]\n";
}



//[350] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWords]

ft_words_expr::ft_words_expr(
	yy::location const& loc)
	:
	expr(loc)
{
}

~ft_words_expr::ft_words_expr()
{
}

ostream& ft_words_expr::put(ostream& os)
{
	return os << "ft_words_expr[]\n";
}



} /* namespace xqp */

