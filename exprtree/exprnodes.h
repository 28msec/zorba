/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: expr_node.h,v 1.1.1.1 2006/11/06 08:42:18 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR FOundation.
 *
 *	Author: Paul Pedersen
 */


#ifndef XQP_EXPR_NODE_H
#define XQP_EXPR_NODE_H
#ifdef __GNUC__
#pragma interface
#endif


#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include <assert.h>

#include "../context/context.h"
#include "../types/qname.h"
#include "../util/rchandle.h"
#include "location.hh"



namespace xqp {

/*
**  base class:  nodes with values.
*/
class expr_node : public rcobject
{
protected:
	yy::location loc;

public:
	expr_node(yy::location const& _loc) : loc(_loc) {}
	expr_node() {}
  ~expr_node() {}

public:
	yy::location get_location() const { return loc; }
	virtual std::ostream& put(std::ostream& s) const;

};

std::ostream& operator<<(std::ostream& s, expr_node const& r)
{
	return r.put(s);
}




/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  XQuery 1.0 productions                                             //
//  [http://www.w3.org/TR/xquery/]                                     //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

// [31] [http://www.w3.org/TR/xquery/#prod-xquery-Expr]
class expr : public expr_node
/*______________________________________________________________________
|	::= ExprSingle | Expr  COMMA  ExprSingle
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<expr_node> > expr_hv;

public:
	expr(yy::location const&);
	~expr();

public:
	void push_back(rchandle<expr_node> expr_h) { expr_hv.push_back(expr_h); }
	rchandle<expr_node> operator[](int i) const { return expr_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;

};



// [32] [http://www.w3.org/TR/xquery/#prod-xquery-ExprSingle]
class expr_single : public expr_node
/*______________________________________________________________________
|	::= FLWORExpr | QuantifiedExpr | TypeswitchExpr | IfExpr | OrExpr
|_______________________________________________________________________*/
{
public:
	expr_single(yy::location const&);
	~expr_single();

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [33] [http://www.w3.org/TR/xquery/#prod-xquery-FLWORExpr]
class flwor_expr : public expr_node
/*______________________________________________________________________
|	::= ForLetClauseList  RETURN  ExprSingle
|			|	ForLetClauseList  WhereClause  RETURN  ExprSingle
|			|	ForLetClauseList  OrderByClause  RETURN  ExprSingle
|			|	ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<var_binding> > bind_hv;
	rchandle<expr_expr>  where_h;
	rchandle<order_expr> orderby_h;
	rchandle<expr_node>  retval_h;

public:
	flwor_expr(
		yy::location const&,
		std::vector<rchandle<var_binding> > bind_hv;
		rchandle<expr_expr>  where_h;
		rchandle<order_expr> orderby_h;
		rchandle<expr_node>  retval_h);
	~flwor_expr();

public:
	rchandle<var_binding> opertor[](int i);
	rchandle<expr_expr> get_where() const { return where_h; }
	rchandle<order_expr> get_orderby() const { return orderby_h; }
	rchandle<expr_node> get_retval() const { return retval_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [42] [http://www.w3.org/TR/xquery/#prod-xquery-QuantifiedExpr]
class quantified_expr : public expr_node
/*______________________________________________________________________
|	::= SOME_DOLLAR  QVarInDeclList | EVERY_DOLLAR  QVarInDeclList
|_______________________________________________________________________*/
{
protected:
	QuantifiedExpr::quantification_mode_t qmode;
	rchandle<QVarInDeclList> decl_list_h;
	rchandle<expr_node> expr_h;

public:
	QuantifiedExpr(
		yy::location const&,
		quantification_mode_t qmode,
		rchandle<QVarInDeclList>,
		rchandle<expr_node>);
	~QuantifiedExpr();

public:
	quantification_mode_t get_qmode() const { return qmode; }
	rchandle<QVarInDeclList> get_decl_list() const { return decl_list_h; }
	rchandle<expr_node> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [43] [http://www.w3.org/TR/xquery/#prod-xquery-TypeswitchExpr]
class typeswitch_expr : public expr_node
/*______________________________________________________________________
|	::= TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
|			|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT 
|					DOLLAR  VARNAME  RETURN  ExprSingle
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> switch_expr_h;
	rchandle<CaseClauseList> clause_list_h;
	std::string default_varname;
	rchandle<expr_node> default_clause_h;

public:
	typeswitch_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<CaseClauseList>,
		rchandle<expr_node>);
	typeswitch_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<CaseClauseList>,
		std::string default_varname,
		rchandle<expr_node>);
	~typeswitch_expr();

public:
	rchandle<expr_node> get_switch_expr() const { return switch_expr_h; }
	rchandle<CaseClauseList> get_clause_list() const { return clause_list_h; }
	std::string get_default_varname() const { return default_varname; }
	rchandle<expr_node> get_default_clause() const { return default_clause_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [45] [http://www.w3.org/TR/xquery/#prod-xquery-IfExpr]
class if_expr : public expr_node
/*______________________________________________________________________
|	::= <"if" "("> Expr ")" "then" ExprSingle "else" ExprSingle
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> cond_expr_h;
	rchandle<expr_node> then_expr_h;
	rchandle<expr_node> else_expr_h;

public:
	if_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<expr_node>,
		rchandle<expr_node>);
	~if_expr();

public:
	rchandle<expr_node> get_cond_expr() const { return cond_expr_h; }
	rchandle<expr_node> get_then_expr() const { return then_expr_h; }
	rchandle<expr_node> get_else_expr() const { return else_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [46] [http://www.w3.org/TR/xquery/#prod-xquery-OrExpr]
class or_expr : public expr_node
/*______________________________________________________________________
|	::= AndExpr ("or" AndExpr)*
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> or_expr_h;
	rchandle<expr_node> and_expr_h;

public:
	or_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<expr_node>);
	~or_expr();

public:
	rchandle<expr_node> get_or_expr() const { return or_expr_h; }
	rchandle<expr_node> get_and_expr() const { return and_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [47] [http://www.w3.org/TR/xquery/#prod-xquery-AndExpr]
class and_expr : public expr_node
/*______________________________________________________________________
|	::= ComparisonExpr ("and" ComparisonExpr)*
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> and_expr_h;
	rchandle<expr_node> comp_expr_h;

public:
	and_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<expr_node>);
	~and_expr();

public:
	rchandle<expr_node> get_and_expr() const { return and_expr_h; }
	rchandle<expr_node> get_comp_expr() const { return comp_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [48] [http://www.w3.org/TR/xquery/#prod-xquery-ComparisonExpr]
class valcomp_expr : public expr_node
/*______________________________________________________________________
|	::= FTContainsExpr ((ValueComp | GeneralComp | NodeComp) FTContainsExpr)?
|_______________________________________________________________________*/
{
protected:
	ValueComp::valcomp_t comp;
	rchandle<expr_node> left_h;
	rchandle<expr_node> right_h;

public:
	valcomp_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<expr_node>);
	~valcomp_expr();

public:
	rchandle<expr_node> get_left() const { return left_h; }
	rchandle<expr_node> get_right() const { return right_h; }
	enum valcomp_t get_comp() const { return comp; }

public:
	virtual std::ostream& put(std::ostream&) const;

};


class gencomp_expr : public expr_node
{
protected:
	GeneralComp::gencomp_t comp;
	rchandle<expr_node> left_h;
	rchandle<expr_node> right_h;

public:
	gencomp_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<expr_node>);
	~gencomp_expr();

public:
	rchandle<expr_node> get_left() const { return left_h; }
	rchandle<expr_node> get_right() const { return right_h; }
	enum gencomp_t get_comp() const { return comp; }

public:
	virtual std::ostream& put(std::ostream&) const;

};


class nodecomp_expr : public expr_node
{
protected:
	NodeComp::nodecomp_t comp;
	rchandle<expr_node> left_h;
	rchandle<expr_node> right_h;

public:
	valcomp_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<expr_node>);
	~valcomp_expr();

public:
	rchandle<expr_node> get_left() const { return left_h; }
	rchandle<expr_node> get_right() const { return right_h; }
	enum nodecomp_t get_comp() const { return comp; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [48a] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTContainsExpr]
class ftcontains_expr : public expr_node
/*______________________________________________________________________
|	::= RangeExpr ("ftcontains" FTSelection FTIgnoreOption?)?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> expr_h;

	rchandle<FTSelection> ftselect_h;
	rchandle<FTIgnoreOption> ftignore_h;

public:
	ftcontains_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<FTSelection>,
		rchandle<FTIgnoreOption>);
	~ftcontains_expr();

public:
	rchandle<expr_node> get_expr() const { return expr_h; }

	rchandle<FTSelection> get_ftselect() const { return ftselect_h; }
	rchandle<FTIgnoreOption> get_ftignore() const { return ftignore_h; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [49] [http://www.w3.org/TR/xquery/#prod-xquery-RangeExpr]
class range_expr : public expr_node
/*______________________________________________________________________
|	::= AdditiveExpr ("to" AdditiveExpr)?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> from_expr_h;
	rchandle<expr_node> to_expr_h;

public:
	range_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<expr_node>);
	~range_expr();

public:
	rchandle<expr_node> get_from_expr() const { return from_expr_h; }
	rchandle<expr_node> get_to_expr() const { return to_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [50] [http://www.w3.org/TR/xquery/#prod-xquery-AdditiveExpr]
class additive_expr : public expr_node
/*______________________________________________________________________
|	::= MultiplicativeExpr (("+"|"-") MultiplicativeExpr)*
|_______________________________________________________________________*/
{
public:
	typedef AdditivetiveExpr::add_op_t addop;
	typedef std::pair<expr_node,addop> addop_pair;

protected:
	std::vector<addop_pair> addop_hv;

public:
	additive_expr(
		yy::location const&,
		enum add_op_t add_op,
		rchandle<expr_node>,
		rchandle<expr_node>);
	~additive_expr();

public:
	add_op_t get_add_op() const { return add_op; }
	rchandle<expr_node> get_add_expr() const { return add_expr_h; }
	rchandle<expr_node> get_mult_expr() const { return mult_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [51] [http://www.w3.org/TR/xquery/#prod-xquery-MultiplicativeExpr]
class mult_expr : public expr_node
/*______________________________________________________________________
|	::= UnionExpr (("*"|"div"|"idiv"|"mod") UnionExpr)?
|_______________________________________________________________________*/
{
public:
	typedef MultiplicativeExpr::mult_op_t mulop;
	typedef std::pair<expr_node,mulop> mulop_pair;

protected:
	std::vector<mulop_pair> mulop_hv;

public:
	mult_expr(yy::location const&)
	~mult_expr();

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [52] [http://www.w3.org/TR/xquery/#prod-xquery-UnionExpr]
class union_expr : public expr_node
/*______________________________________________________________________
|	::= IntersectExceptExpr (("union" | "|") IntersectExceptExpr)*
|_______________________________________________________________________*/
{
protected:
	std::vector<expr_node> expr_hv;

public:
	union_expr(yy::location const&);
	~union_expr();

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [53] [http://www.w3.org/TR/xquery/#prod-xquery-IntersectExceptExpr]
class intersect_except_expr : public expr_node
/*______________________________________________________________________
|	::= InstanceofExpr (("intersect" | "except") InstanceofExpr)*
|_______________________________________________________________________*/
{
public:
	typedef IntersectExceptExpr::intex_op_t intexop;
	typedef std::pair<expr_node,intexop> intexop_pair;

protected:
	std::vector<intexop_pair> intexop_hv;

public:
	intersect_except_expr(yy::location const&);
	~intersect_except_expr();

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [54] [http://www.w3.org/TR/xquery/#prod-xquery-InstanceofExpr]
class instanceof_expr : public expr_node
/*______________________________________________________________________
|	::= TreatExpr ("instance" "of" SequenceType)?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> expr_h;
	rchandle<SequenceType> seqtype_h;

public:
	instanceof_expr(yy::location const&);
	~instanceof_expr();

public:
	rchandle<expr_node> get_expr() const { return expr_h; }
	virtual std::ostream& put(std::ostream&) const;

};



// [55] [http://www.w3.org/TR/xquery/#prod-xquery-TreatExpr]
class treat_expr : public expr_node
/*______________________________________________________________________
|	::= CastableExpr ("treat" "as" SequenceType)?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> expr_h;
	rchandle<SequenceType> seqtype_h;

public:
	treat_expr(yy::location const&);
	~treat_expr();

public:
	rchandle<expr_node> get_expr() const { return expr_h; }
	virtual std::ostream& put(std::ostream&) const;

};



// [56] [http://www.w3.org/TR/xquery/#prod-xquery-CastableExpr]
class castable_expr : public expr_node
/*______________________________________________________________________
|	::= CastExpr ("castable" "as" SingleType)?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> expr_h;
	rchandle<SingleType> singletype_h;

public:
	castable_expr(yy::location const&);
	~castable_expr();

public:
	rchandle<expr_node> get_expr() const { return expr_h; }
	virtual std::ostream& put(std::ostream&) const;

};



// [57] [http://www.w3.org/TR/xquery/#prod-xquery-CastExpr]
class cast_expr : public expr_node
/*______________________________________________________________________
|	::= UnaryExpr ("cast" "as" SingleType)?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> expr_h;
	rchandle<SingleType> singletype_h;

public:
	cast_expr(yy::location const&);
	~cast_expr();

public:
	rchandle<expr_node> get_expr() const { return expr_h; }
	virtual std::ostream& put(std::ostream&) const;

};



// [58] [http://www.w3.org/TR/xquery/#prod-xquery-UnaryExpr]
// --------------
class unary_expr : public expr_node
/*______________________________________________________________________
|	::= ("+"|"-")* ValueExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> expr_h;

public:
	unary_expr(
		yy::location const&,
		rchandle<SignList>,
		rchandle<expr_node>);
	~unary_expr();

public:
	rchandle<expr_node> get_expr() const { return expr_h; }
	virtual std::ostream& put(std::ostream&) const;

};



// [63] [http://www.w3.org/TR/xquery/#prod-xquery-ValidateExpr]
class validate_expr : public expr_node
/*______________________________________________________________________
|	::= "validate" ValidationMode? "{" Expr "}"
|_______________________________________________________________________*/
{
protected:
	ValidateExpr::validation_mode_t valmode;
	rchandle<expr_node> expr_h;

public:
	validate_expr(yy::location const&);
	~validate_expr();

public:
	rchandle<expr_node> get_expr() const { return expr_h; }
	ValidateExpr::validation_mode_t get_valmode() const { return valmode; }

public:
	std::ostream& put(std::ostream&) const;

};



// [65] [http://www.w3.org/TR/xquery/#prod-xquery-ExtensionExpr]
class extension_expr : public expr_node
/*______________________________________________________________________
|	::= PragmaList "{" Expr? "}"
|_______________________________________________________________________*/
{
protected:
	rchandle<PragmaList> pragma_list_h;
	rchandle<expr_node> expr_h;

public:
	extension_expr(
		yy::location const&,
		rchandle<PragmaList>,
		rchandle<expr_node>);
	~extension_expr();

public:
	rchandle<PragmaList> get_pragma_list() const { return pragma_list_h; }
	rchandle<expr_node> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [69] [http://www.w3.org/TR/xquery/#prod-xquery-RelativePathExpr]
class relpath_expr : public expr_node
/*______________________________________________________________________
|	::= "/" | ("/" | "//")?  StepExpr (("/" | "//") StepExpr)*
|
|	Formal Semantics [http://www.w3.org/TR/xquery-semantics]:
|		/    == fn:root(self::node())
|		/A   == fn:root(self::node())/A
|		//A  == fn:root(self::node())/descendant-or-self::node()/A
|	  A//B == A/descendant-or-self::node()/B
| implies that all path expressions are relative path expressions.
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<step_expr> > step_hv;

public:
	relpath_expr(yy::location const&);
	~relpath_expr();

public:
	std::ostream& put(std::ostream&) const;

};



// [70] [http://www.w3.org/TR/xquery/#prod-xquery-StepExpr]
class step_expr : public expr_node
/*______________________________________________________________________
|	::= AxisStep  |  FilterExpr
|_______________________________________________________________________*/
{
public:
	step_expr(yy::location const&);
	~step_expr();

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [71] [http://www.w3.org/TR/xquery/#prod-xquery-AxisStep]
class axis_step_expr : public expr_node
/*______________________________________________________________________
|	::= Axis NodeTest Predicate*
|_______________________________________________________________________*/
{
public:
	enum axis_t {
		self,
		parent,
		descendant,
		descendant-or-self,
		ancestor,
		ancestor-or-self,
		following-sibling,
		following,
		preceding-sibling,
		preceding,
		attribute
	};

	enum test_t {
		no_test,
		name_test,
		doc_test,
		elem_test,
		attr_test,
		xs_elem_test,
		xs_attr_test,
		pi_test,
		comment_test,
		text_test,
		anykind_test
	};

	enum wild_t {
		no_wild
		all_wild,
		prefix_wild,
		name_wild
	};

protected:
	axis_t axis;
	test_t test;
	test_t subtest;
	wild_t wild;
	rchandle<QName> name;
	rchandle<QName> type;
	std::vector<rchandle<expr_node> > pred_hv;

public:
	axis_step_expr(
		yy::location const&,
		axis_t, test_t, test_t,
		rchandle<node_test>);
	~axis_step_expr();

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [84] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]
class primary_expr : public expr_node
/*______________________________________________________________________
|	::= Literal
|			|	VarRef
|			|	ParenthesizedExpr
|			|	ContextItemExpr
|			|	FunctionCall
|			|	Constructor
|			|	OrderedExpr
|			|	UnorderedExpr
|_______________________________________________________________________*/
{
public:
	primary_expr(
		yy::location const&);
	~primary_expr();

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [85] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]
class literal_expr : public expr_node
/*______________________________________________________________________
|	::= NumericLiteral | StringLiteral
|_______________________________________________________________________*/
{
public:
	enum literal_type_t {
		lit_string,
		lit_integer,
		lit_decimal,
		lit_double
	};
	typedef long long decimal;

protected:
	enum literal_type_t type;
	union {
		uint32_t string_ref;
		int integer_val;
		decimal decimal_val;
		double double_val;
	};

public:
	literal_expr(
		uint32_t string_ref,
		yy::location const&);

	literal_expr(
		int,
		yy::location const&);

	literal_expr(
		decimal,
		yy::location const&);

	literal_expr(
		double,
		yy::location const&);

	~literal_expr();

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [87] [http://www.w3.org/TR/xquery/#prod-xquery-VarRef]
class varref_expr : public expr_node
/*______________________________________________________________________
|	::= DOLLAR  VARNAME
|_______________________________________________________________________*/
{
protected:
	std::string varname;

public:
	varref_expr(
		yy::location const&,
		std::string varname);
	~varref_expr();

public:
	std::string get_varname() const { return varname; }

public:
	std::ostream& put(std::ostream&) const;

};



// [91] [http://www.w3.org/TR/xquery/#prod-xquery-OrderedExpr]
class ordered_expr : public expr_node
/*______________________________________________________________________
|	::= ORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> expr_h;

public:
	ordered_expr(
		yy::location const&,
		rchandle<expr_node>);
	~ordered_expr();

public:
	rchandle<expr_node> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [92] [http://www.w3.org/TR/xquery/#prod-xquery-UnorderedExpr]
class unordered_expr : public expr_node
/*______________________________________________________________________
|	::= UNORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> expr_h;

public:
	unordered_expr(
		yy::location const&,
		rchandle<expr_node>);
	~unordered_expr();

public:
	rchandle<expr_node> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [93] [http://www.w3.org/TR/xquery/#prod-xquery-FunctionCall]
class funcall_expr : public expr_node
/*______________________________________________________________________
|	::= QNAME  LPAR  ArgList  RPAR 	
|																	gn:parensXQ
|			 														gn:reserved-function-namesXQ 
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> fname_h;
	std::vector<rchandle<expr_node> > arg_hv;

public:
	funcall(
		yy::location const&,
		rchandle<QName>,
		std::vector<rchandle<expr_node> > arg_hv);
	~funcall();

public:
	rchandle<QName> get_fname() const { return fname_h; }
	rchandle<expr_node> get_arg(uint32_t n) const { return arg_hv[n]; }
	uint32_t arg_count() const { return arg_hv.size(); }

	std::vector<rchandle<expr_node> >:: const_iterator arg_begin() const
		{ return arg_hv.begin(); }
	std::vector<rchandle<expr_node> >:: const_iterator arg_end() const
		{ return arg_hv.end(); }

public:
	std::ostream& put(std::ostream&) const;

};



// [109] [http://www.w3.org/TR/xquery/#prod-xquery-ComputedConstructor]
class cons_expr : public expr_node
/*______________________________________________________________________
|	::= CompDocConstructor
|			|	CompElemConstructor
|			|	CompAttrConstructor
|			|	CompTextConstructor
|			|	CompCommentConstructor
|			|	CompPIConstructor
|_______________________________________________________________________*/
{
public:
	ComputedConstructor(
		yy::location const&);
	~ComputedConstructor();

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [110] [http://www.w3.org/TR/xquery/#prod-xquery-CompDocConstructor]
class doc_expr : public expr_node
/*______________________________________________________________________
|	::= DOCUMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> expr_h;

public:
	doc_expr(
		yy::location const&,
		rchandle<expr_node>);
	~CompDocConstructor();

public:
	rchandle<expr_node> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [111] [http://www.w3.org/TR/xquery/#prod-xquery-CompElemConstructor]
class elem_expr : public expr_node
/*______________________________________________________________________
|	::= ELEMENT_QNAME_LBRACE  RBRACE
|			|	ELEMENT_QNAME_LBRACE  ContentExpr  RBRACE
|			|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  RBRACE
|			|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  ContentExpr  RBRACE
|_______________________________________________________________________*/
{
public:
	typedef std::pair<std::string,std::string> nsbinding;
#define ncname	FIRST
#define nsuri		SECOND

protected:
	rchandle<QName> qname_h;
	rchandle<expr_node> name_expr_h;
	rchandle<expr_node> content_expr_h;
	std::vector<rchandle<nsbinding> > nsb_hv;

public:
	elem_expr(
		yy::location const&,
		rchandle<QName>,
		rchandle<expr_node>);
	elem_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<expr_node>);
	~elem_expr();

public:
	rchandle<QName> get_name() const { return name_h; }
	rchandle<expr_node> get_name_expr() const { return name_expr_h; }
	rchandle<expr_node> get_content_expr() const { return content_expr_h; }

	void add(rchandle<nsbinding> nsb_h) { nsb_hv.push_back(nsb_h); }
	uint32_t nsbinding_count() const { return ns_hv.size(); }
	std::vector<rchandle<nsbinding> >::const_iterator ns_begin() const
		{ return ns_hv.begin(); }
	std::vector<rchandle<nsbinding> >::const_iterator ns_end() const
		{ return ns_hv.end(); }

public:
	std::ostream& put(std::ostream&) const;

};



// [113] [http://www.w3.org/TR/xquery/#prod-xquery-CompAttrConstructor]
class attr_expr : public expr_node
/*______________________________________________________________________
|	::= ATTRIBUTE  QNAME  LBRACE  RBRACE
|			|	ATTRIBUTE  QNAME  LBRACE  Expr  RBRACE
|			|	ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  RBRACE
|			|	ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> name_h;
	rchandle<expr_node> name_expr_h;
	rchandle<expr_node> val_expr_h;

public:
	attr_expr(
		yy::location const&,
		rchandle<QName>,
		rchandle<expr_node>);
	attr_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<expr_node>);
	~attr_expr();

public:
	rchandle<QName> get_name() const { return qname_h; }
	rchandle<expr_node> get_name_expr() const { return qname_expr_h; }
	rchandle<expr_node> get_val_expr() const { return val_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompTextConstructor]
class text_expr : public expr_node
/*______________________________________________________________________
|	::= TEXT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> text_expr_h;

public:
	text_expr(
		yy::location const&,
		rchandle<expr_node> text_expr_h);
	~text_expr();

public:
	rchandle<expr_node> get_text_expr() const { return text_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [115] [http://www.w3.org/TR/xquery/#prod-xquery-CompCommentConstructor]
class comment_expr : public expr_node
/*______________________________________________________________________
|	::= COMMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> comment_expr_h;

public:
	comment_expr(
		yy::location const&,
		rchandle<expr_node>);
	~comment_expr();

public:
	rchandle<expr_node> get_comment_expr() const { return comment_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompPIConstructor]
class pi_expr : public expr_node
/*______________________________________________________________________
|	::= PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
|			|	PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RBRACE
|			|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  RBRACE
|			|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	std::string target;
	rchandle<expr_node> target_expr_h;
	rchandle<expr_node> content_expr_h;

public:
	pi_expr(
		yy::location const&,
		std::string target,
		rchandle<expr_node>);
	pi_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<expr_node>);
	~pi_expr();

public:
	std::string get_target() const { return target; }
	rchandle<expr_node> get_target_expr() const { return target_expr_h; }
	rchandle<expr_node> get_content_expr() const { return content_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};




/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	Update productions                                                 //
//  [http://www.w3.org/TR/xqupdate/]                                   //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

// [242] [http://www.w3.org/TR/xqupdate/#prod-xquery-InsertExpr]
class insert_expr : public expr_node
/*______________________________________________________________________
|	::= DO_INSERT  ExprSingle  INTO  ExprSingle
|			|	DO_INSERT  ExprSingle  AS  FIRST_INTO  ExprSingle
|			|	DO_INSERT  ExprSingle  AS  LAST_INTO  ExprSingle
|			| DO_INSERT  ExprSingle  AFTER  ExprSingle
|			| DO_INSERT  ExprSingle  BEFORE  ExprSingle
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> source_expr_h;
	rchandle<expr_node> target_expr_h;

public:
	insert_expr(
		yy::location const&,
		rchandle<expr_node>,
		rchandle<expr_node>);
	~insert_expr();

public:
	rchandle<expr_node> get_source_expr() const { return source_expr_h; }
	rchandle<expr_node> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [243] [http://www.w3.org/TR/xqupdate/#prod-xquery-DeleteExpr]
class delete_expr : public expr_node
/*______________________________________________________________________
|	::= DO_DELETE  expr_node
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> target_expr_h;

public:
	delete_expr(
		yy::location const&,
		rchandle<expr_node>);
	~delete_expr();

public:
	rchandle<expr_node> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [244] [http://www.w3.org/TR/xqupdate/#prod-xquery-ReplaceExpr]
class replace_expr : public expr_node
/*______________________________________________________________________
|	::= DO_REPLACE  expr_node  WITH  expr_node
|			| DO_REPLACE  VALUE_OF  expr_node  WITH  expr_node
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> source_expr_h;
	rchandle<expr_node> target_expr_h;

public:
	replace_expr(
		yy::location const&,
		rchandle<expr_node> source_expr_h,
		rchandle<expr_node> target_expr_h);
	~replace_expr();

public:
	rchandle<expr_node> get_source_expr() const { return source_expr_h; }
	rchandle<expr_node> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [245] [http://www.w3.org/TR/xqupdate/#prod-xquery-RenameExpr]
class rename_expr : public expr_node
/*______________________________________________________________________
|	::= DO_RENAME  expr_node  AS  expr_node
|_______________________________________________________________________*/
{
protected:
	rchandle<expr_node> source_expr_h;
	rchandle<expr_node> target_expr_h;

public:
	rename_expr(
		yy::location const&,
		rchandle<expr_node> source_expr_h,
		rchandle<expr_node> target_expr_h);
	~rename_expr();

public:
	rchandle<expr_node> get_source_expr() const { return source_expr_h; }
	rchandle<expr_node> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [249] [http://www.w3.org/TR/xqupdate/#prod-xquery-TransformExpr]
class transform_expr : public expr_node
/*______________________________________________________________________
|	::= TRANSFORM_COPY_DOLLAR  VarNameList
|				MODIFY  expr_node  RETURN  expr_node
|_______________________________________________________________________*/
{
protected:
	rchandle<VarNameList> varname_list_h;
	rchandle<expr_node> source_expr_h;
	rchandle<expr_node> target_expr_h;

public:
	transform_expr(
		yy::location const&,
		rchandle<VarNameList>,
		rchandle<expr_node> source_expr_h,
		rchandle<expr_node> target_expr_h);
	~transform_expr();

public:
	rchandle<VarNameList> get_varname_list() const { return varname_list_h; }
	rchandle<expr_node> get_source_expr() const { return source_expr_h; }
	rchandle<expr_node> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};





/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  Full-text productions                                              //
//  [http://www.w3.org/TR/xquery-full-text/]                           //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

//[344] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTSelection]
class ftselection : public expr_node
/*______________________________________________________________________
|	::=	FTOr
|			|	FTOr  FTMatchOptionProximityList
|			|	FTOr  WEIGHT  RangeExpr
|			|	FTOr  FTMatchOptionProximityList  WEIGHT  RangeExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<FTOr> ftor_h;
	rchandle<FTMatchOptionProximityList> option_list_h;
	rchandle<RangeExpr> weight_expr_h;

public:
	FTSelection(
		yy::location const&,
		rchandle<FTOr>,
		rchandle<FTMatchOptionProximityList>,
		rchandle<RangeExpr>);
	~FTSelection();

public:
	rchandle<FTOr> get_ftor() const
		{ return ftor_h; }
	rchandle<FTMatchOptionProximityList> get_option_list() const
		{ return option_list_h; }
	rchandle<RangeExpr> get_weight_expr() const
		{ return weight_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[344a] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTMatchOptionProximityList]
class FTMatchOptionProximityList : public expr_node
/*______________________________________________________________________
|	::=	FTMatchOptionProximity
|			| FTMatchOptionProximityList  FTMatchOptionProximity
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<FTMatchOptionProximity> > opt_prox_hv;

public:
	FTMatchOptionProximityList(
		yy::location const&);
	~FTMatchOptionProximityList();

public:
	void push_back(rchandle<FTMatchOptionProximity> opt_prox_h)
		{ opt_prox_hv.push_back(opt_prox_h); }
	rchandle<FTMatchOptionProximity> operator[](int i)
		{ return opt_prox_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;

};



//[344b] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTMatchOptionProximity]
class FTMatchOptionProximity : public expr_node
/*______________________________________________________________________
|	::=	FTMatchOption | FTProximity
|_______________________________________________________________________*/
{
protected:
	rchandle<FTMatchOption> opt_h;
	rchandle<FTProximity> prox_h;

public:
	FTMatchOptionProximity(
		rchandle<FTMatchOption>,
		yy::location const&);
	FTMatchOptionProximity(
		rchandle<FTProximity>,
		yy::location const&);
	FTMatchOptionProximity(
		yy::location const&);
	~FTMatchOptionProximity();

public:
	std::ostream& put(std::ostream&) const;

};



//[345] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTOr]
class FTOr : public expr_node
/*______________________________________________________________________
|	::=	FTAnd
|			|	FTOr  FTOR  FTAnd
|_______________________________________________________________________*/
{
protected:
	rchandle<FTOr> ftor_h;
	rchandle<FTAnd> ftand_h;

public:
	FTOr(
		yy::location const&,
		rchandle<FTOr>,
		rchandle<FTAnd>);
	~FTOr();

public:
	rchandle<FTOr> get_ftor() const { return ftor_h; }
	rchandle<FTAnd> get_ftand() const { return ftand_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[346] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTAnd]
class FTAnd : public expr_node
/*______________________________________________________________________
|	::=	FTMildnot
|			|	FTAnd  FTAND  FTMildnot
|_______________________________________________________________________*/
{
protected:
	rchandle<FTAnd> ftand_h;
	rchandle<FTMildnot> ftmild_not_h;

public:
	FTAnd(
		yy::location const&,
		rchandle<FTAnd>,
		rchandle<FTMildnot>);
	~FTAnd();

public:
	rchandle<FTAnd> get_ftand() const { return ftand_h; }
	rchandle<FTMildnot> get_ftmild_not() const { return ftmild_not_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[347] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTMildnot]
class FTMildnot : public expr_node
/*______________________________________________________________________
|	::=	FTUnaryNot
|			|	FTMildnot  FTNOT_IN  FTUnaryNot
|_______________________________________________________________________*/
{
protected:
	rchandle<FTMildnot> ftmild_not_h;
	rchandle<FTUnaryNot> ftunary_not_h;

public:
	FTMildnot(
		yy::location const&,
		rchandle<FTMildnot>,
		rchandle<FTUnaryNot>);
	~FTMildnot();

public:
	rchandle<FTMildnot> get_ftmild_not() const { return ftmild_not_h; }
	rchandle<FTUnaryNot> get_ftunary_not() const { return ftunary_not_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[348] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTUnaryNot]
class FTUnaryNot : public expr_node
/*______________________________________________________________________
|	::=	FTWordsSelection
|			|	FTNOT  FTWordsSelection
|_______________________________________________________________________*/
{
protected:
	rchandle<FTWordsSelection> words_selection_h;
	bool not_b;

public:
	FTUnaryNot(
		yy::location const&,
		rchandle<FTWordsSelection>,
		bool not_b);
	~FTUnaryNot();

public:
	rchandle<FTWordsSelection> get_words_selection() const
		{ return words_selection_h; }
	bool get_not_bit() const
		{ return not_b; }

public:
	std::ostream& put(std::ostream&) const;

};



//[349] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWordsSelection]
class FTWordsSelection : public expr_node
/*______________________________________________________________________
|	::=	FTWords
|			|	FTWords FTTimes
|			| LPAR  FTSelection  RPAR
|_______________________________________________________________________*/
{
protected:
	rchandle<FTWords> words_h;
	rchandle<FTTimes> times_h;
	rchandle<FTSelection> selection_h;

public:
	FTWordsSelection(
		yy::location const&,
		rchandle<FTWords>,
		rchandle<FTTimes>,
		rchandle<FTSelection>);
	~FTWordsSelection();

public:
	rchandle<FTWords> get_words() const { return words_h; }
	rchandle<FTTimes> get_times() const { return times_h; }
	rchandle<FTSelection> get_selection() const { return selection_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[350] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWords]
class FTWords : public expr_node
/*______________________________________________________________________
|	::=	FTWordsValue 
|			|	FTWordsValue  FTAnyallOption
|_______________________________________________________________________*/
{
protected:
	rchandle<FTWordsValue> words_val_h;
	rchandle<FTAnyallOption> any_all_option_h;

public:
	FTWords(
		yy::location const&,
		rchandle<FTWordsValue>,
		rchandle<FTAnyallOption>);
	~FTWords();

public:
	rchandle<FTWordsValue> get_words_val() const
		{ return words_val_h; }
	rchandle<FTAnyallOption> get_any_all_option() const
		{ return any_all_option_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[351] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWordsValue]
class FTWordsValue : public expr_node
/*______________________________________________________________________
|	::=	Literal
|			| LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<Literal> lit_h;
	rchandle<Expr> expr_h;

public:
	FTWordsValue(
		yy::location const&,
		rchandle<Literal>,
		rchandle<Expr>);
	~FTWordsValue();

public:
	rchandle<Literal> get_lit() const { return lit_h; }
	rchandle<Expr> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[352] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTProximity]
class FTProximity : public expr_node
/*______________________________________________________________________
|	::=	FTOrderedIndicator
|			| FTWindow
|			| FTDistance
|			| FTScope
|			| FTContent
|_______________________________________________________________________*/
{
public:
	FTProximity(
		yy::location const&);
	~FTProximity();

public:
	std::ostream& put(std::ostream&) const;

};



//[353] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTOrderedIndicator]
class FTOrderedIndicator : public FTProximity
/*______________________________________________________________________
|	::=	ORDERED
|_______________________________________________________________________*/
{
public:
	FTOrderedIndicator(
		yy::location const&);
	~FTOrderedIndicator();

public:
	std::ostream& put(std::ostream&) const;

};



//[354] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTMatchOption] 	
class FTMatchOption : public expr_node
/*______________________________________________________________________
|	::=	FTCaseOption
|			| FTDiacriticsOption
|			| FTStemOption
|			| FTThesaurusOption
|			| FTStopwordOption
|			| FTLanguageOption
|			| FTWildcardOption
|_______________________________________________________________________*/
{
public:
	FTMatchOption(
		yy::location const&);
	~FTMatchOption();

public:
	std::ostream& put(std::ostream&) const;

};



//[355] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTCaseOption]
class FTCaseOption : public FTMatchOption
/*______________________________________________________________________
|	::=	LOWERCASE
|			| UPPERCASE
|			| CASE_SENSITIVE
|			| CASE_INSENSITIVE
|_______________________________________________________________________*/
{
public:
	enum ft_case_mode_t {
		lowercase,
		uppercase,
		senstive,
		insensitive
	};

protected:
	ft_case_mode_t mode;

public:
	FTCaseOption(
		yy::location const&,
		enum ft_case_mode_t);
	~FTCaseOption();

public:
	enum ft_case_mode_t get_mode() const { return mode; }

public:
	std::ostream& put(std::ostream&) const;

};



//[356] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTDiacriticsOption]
class FTDiacriticsOption : public FTMatchOption
/*______________________________________________________________________
|	::=	WITH_DIACRITICS
|			| WITHOUT_DIACRITICS
|			| DIACRITICS_SENSITIVE
|			| DIACRITICS_INSENSITIVE
|_______________________________________________________________________*/
{
public:
	enum ft_diacritics_mode_t {
		with,
		without,
		senstive,
		insensitive
	};

protected:
	ft_diacritics_mode_t mode;

public:
	FTDiacriticsOption(
		yy::location const&,
		ft_diacritics_mode_t);
	~FTDiacriticsOption();

public:
	enum ft_diacritics_mode_t get_mode() const { return mode; }

public:
	std::ostream& put(std::ostream&) const;

};



//[357] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTStemOption]
class FTStemOption : public FTMatchOption
/*______________________________________________________________________
|	::=	WITH_STEMMING
|			| WITHOUT_STEMMING
|_______________________________________________________________________*/
{
public:
	enum ft_stem_mode_t {
		with,
		without
	};

protected:
	ft_stem_mode_t mode;

public:
	FTStemOption(
		yy::location const&,
		ft_stem_mode_t);
	~FTStemOption();

public:
	enum ft_stem_mode_t get_mode() const { return mode; }

public:
	std::ostream& put(std::ostream&) const;

};



//[358] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTThesaurusOption]
class FTThesaurusOption : public FTMatchOption
/*______________________________________________________________________
|	::=	WITH_THESAURUS  FTThesaurusID
|			|	WITH_THESAURUS  DEFAULT
|			| WITH_THESAURUS  LPAR  FTThesaurusList  RPAR
|			| WITH_THESAURUS  LPAR  DEFAULT  RPAR
|			| WITH_THESAURUS  LPAR  DEFAULT  COMMA  FTThesaurusList  RPAR
|			| WITHOUT_THESAURUS
|_______________________________________________________________________*/
{
protected:
	rchandle<FTThesaurusID> thesaurusid_h;
	rchandle<FTThesaurusList> thesaurus_list_h;
	bool default_b;
	bool without_b;

public:
	FTThesaurusOption(
		yy::location const&,
		rchandle<FTThesaurusID>,
		rchandle<FTThesaurusList>,
		bool default_b,
		bool without_b);
	~FTThesaurusOption();

public:
	rchandle<FTThesaurusID> get_thesaurusid() const
		{ return thesaurusid_h; }
	rchandle<FTThesaurusList> get_thesaurus_list() const
		{ return thesaurus_list_h; }

	bool get_default_bit() const { return default_b; }
	bool get_without_bit() const { return without_b; }

public:
	std::ostream& put(std::ostream&) const;

};



//[358a] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTThesaurusList]
class FTThesaurusList : public expr_node
/*______________________________________________________________________
|	::=	FTThesaurusID
|			| FTThesaurusList  COMMA  FTThesaurusID
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<FTThesaurusID> > thesaurus_hv;

public:
	FTThesaurusList(
		yy::location const&);
	~FTThesaurusList();

public:
	void push_back(rchandle<FTThesaurusID> thesaurus_h)
		{ thesaurus_hv.push_back(thesaurus_h); }
	rchandle<FTThesaurusID> operator[](int i) const
		{ return thesaurus_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;

};



//[359] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTThesaurusID]
class FTThesaurusID : public expr_node
/*______________________________________________________________________
|	::=	AT  STRING_LITERAL
|			|	AT  STRING_LITERAL  RELATIONSHIP  STRING_LITERAL
|			|	AT  STRING_LITERAL  FTRange  LEVELS
|			|	AT  STRING_LITERAL  RELATIONSHIP  STRING_LITERAL  FTRange  LEVELS
|_______________________________________________________________________*/
{
protected:
	std::string thesaurus_name;
	std::string relationship_name;
	rchandle<FTRange> levels_h;

public:
	FTThesaurusID(
		yy::location const&,
		std::string thesaurus_name,
		std::string relationship_name,
		rchandle<FTRange> levels_h);
	~FTThesaurusID();

public:
	std::string get_thesaurus_name() const { return thesaurus_name; }
	std::string get_relationship_name() const { return relationship_name; }
	rchandle<FTRange> get_levels() const { return levels_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[360] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTStopwordOption]
//----------------------
class FTStopwordOption : public FTMatchOption
/*______________________________________________________________________
|	::=	WITH_STOP_WORDS  FTRefOrList
|			|	WITH_STOP_WORDS  FTRefOrList  FTInclExclStringLiteralList
|			| WITH_DEFAULT_STOP_WORDS 
|			| WITH_DEFAULT_STOP_WORDS  FTInclExclStringLiteralList
|			| WITHOUT_STOP_WORDS
|_______________________________________________________________________*/
{
public:
	enum stop_words_mode_t {
		with,
		with_default,
		without
	};

protected:
	rchandle<FTRefOrList> refor_list_h;
	rchandle<FTInclExclStringLiteralList> incl_excl_list_h;
	stop_words_mode_t mode;

public:
	FTStopwordOption(
		yy::location const&,
		rchandle<FTRefOrList>,
		rchandle<FTInclExclStringLiteralList>,
		stop_words_mode_t);
	~FTStopwordOption();

public:
	rchandle<FTRefOrList> get_refor_list() const
		{ return refor_list_h; }
	rchandle<FTInclExclStringLiteralList> get_incl_excl_list() const
		{ return incl_excl_list_h; }
	stop_words_mode_t get_mode() const
		{ return mode; }

public:
	std::ostream& put(std::ostream&) const;

};



//[360a] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTInclExclStringLiteralList]
//----------------------------------
class FTInclExclStringLiteralList : public expr_node
/*______________________________________________________________________
|
|	::=	FTInclExclStringLiteral
|			| FTInclExclStringLiteralList  FTInclExclStringLiteral
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<FTInclExclStringLiteral> > incl_excl_lit_hv;

public:
	FTInclExclStringLiteralList(
		yy::location const&);
	~FTInclExclStringLiteralList();

public:
	void push_back(rchandle<FTInclExclStringLiteral> incl_excl_lit_h)
		{ incl_excl_lit_hv.push_back(incl_excl_lit_h); }
	rchandle<FTInclExclStringLiteral> operator[](int i) const
		{ return incl_excl_lit_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;

};



//[361] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTRefOrList]
class FTRefOrList : public expr_node
/*______________________________________________________________________
|	::=	AT  STRING_LITERAL
|			| LPAR  FTStringLiteralList  RPAR 
|_______________________________________________________________________*/
{
protected:
	std::string at_str;
	rchandle<FTStringLiteralList> stringlit_list_h;

public:
	FTRefOrList(
		yy::location const&,
		std::string at_str,
		rchandle<FTStringLiteralList>);
	~FTRefOrList();

	std::string get_at_str() const
		{ return at_str; }
	rchandle<FTStringLiteralList> get_stringlit_list() const
		{ return stringlit_list_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[361a] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTStringLiteralList]
class FTStringLiteralList : public expr_node
/*______________________________________________________________________
|	::=	STRING_LITERAL
|			|	FTStringLiteralList  STRING_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::vector<std::string> strlit_v;

public:
	FTStringLiteralList(
		yy::location const&);
	~FTStringLiteralList();

public:
	void push_back(std::string strlit) { strlit_v.push_back(strlit); }
	std::string operator[](int i) const { return strlit_v[i]; }

public:
	std::ostream& put(std::ostream&) const;

};



//[362] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTInclExclStringLiteral]
class FTInclExclStringLiteral : public expr_node
/*______________________________________________________________________
|	::=	UNION  FTRefOrList
|			|	EXCEPT  FTRefOrList
|_______________________________________________________________________*/
{
public:
	enum incl_excl_mode_t {
		inex_union,
		inex_except
	};

protected:
	rchandle<FTRefOrList> ref_or_list_h;
	incl_excl_mode_t mode;

public:
	FTInclExclStringLiteral(
		yy::location const&,
		rchandle<FTRefOrList>,
		incl_excl_mode_t);
	~FTInclExclStringLiteral();

public:
	rchandle<FTRefOrList> get_ref_or_list() const
		{ return ref_or_list_h; }
	incl_excl_mode_t get_mode() const
		{ return mode; }

public:
	std::ostream& put(std::ostream&) const;

};



//[363] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTLanguageOption]
class FTLanguageOption : public FTMatchOption
/*______________________________________________________________________
|	::=	LANGUAGE  STRING_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::string lang;

public:
	FTLanguageOption(
		yy::location const&,
		std::string lang);
	~FTLanguageOption();

public:
	std::string get_lang() const { return lang; }

public:
	std::ostream& put(std::ostream&) const;

};



//[364] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWildcardOption]
class FTWildcardOption : public FTMatchOption
/*______________________________________________________________________
|	::=	WITH_WILDCARDS | WITHOUT_WILDCARDS
|_______________________________________________________________________*/
{
protected:
	bool with_b;

public:
	FTWildcardOption(
		yy::location const&,
		bool with_b);
	~FTWildcardOption();

public:
	bool get_with_bit() const { return with_b; }

public:
	std::ostream& put(std::ostream&) const;

};



//[365] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTContent]
class FTContent : public FTProximity
/*______________________________________________________________________
|	::=	AT_START | AT_END | ENTIRE_CONTENT
|_______________________________________________________________________*/
{
public:
	enum ft_content_mode_t {
		at_start,
		at_end,
		entire_content
	};

protected:
	ft_content_mode_t mode;

public:
	FTContent(
		yy::location const&,
		enum ft_content_mode_t);
	~FTContent();

public:
	enum ft_content_mode_t get_mode() const { return mode; }

public:
	std::ostream& put(std::ostream&) const;

};



//[366] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTAnyallOption]
class FTAnyallOption : public expr_node
/*______________________________________________________________________
|	::=	ANY | ANY_WORD | ALL | ALL_WORDS | PHRASE
|_______________________________________________________________________*/
{
public:
	enum ft_anyall_option_t {
		any,
		any_word,
		all,
		all_words,
		phrase
	};

protected:
	enum ft_anyall_option_t option;

public:
	FTAnyallOption(
		yy::location const&,
		enum ft_anyall_option_t);
	~FTAnyallOption();

public:
	enum ft_anyall_option_t get_option() const { return option; }

public:
	std::ostream& put(std::ostream&) const;

};



//[367] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTRange]
class FTRange : public expr_node
/*______________________________________________________________________
|	::=	EXACTLY  UnionExpr
|			| AT_LEAST  UnionExpr
|			| AT_MOST  UnionExpr
|			| FROM  UnionExpr  TO  UnionExpr
|_______________________________________________________________________*/
{
public:
	enum ft_range_mode_t {
		exactly,
		at_least,
		at_most,
		from_to
	};

protected:
	rchandle<UnionExpr> src_expr_h;
	rchandle<UnionExpr> dst_expr_h;

public:
	FTRange(
		yy::location const&,
		rchandle<UnionExpr> src_expr_h,
		rchandle<UnionExpr> dst_expr_h);
	~FTRange();

public:
	rchandle<UnionExpr> get_src_expr() const { return src_expr_h; }
	rchandle<UnionExpr> get_dst_expr() const { return dst_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[368] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTDistance]
class FTDistance : public FTProximity
/*______________________________________________________________________
|	::=	DISTANCE  FTRange  FTUnit
|_______________________________________________________________________*/
{
protected:
	rchandle<FTRange> dist_h;
	rchandle<FTUnit> unit_h;

public:
	FTDistance(
		yy::location const&,
		rchandle<FTRange>,
		rchandle<FTUnit>);
	~FTDistance();

public:
	rchandle<FTRange> get_dist() const { return dist_h; }
	rchandle<FTUnit> get_unit() const { return unit_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[369] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWindow]
class FTWindow : public FTProximity
/*______________________________________________________________________
|	::=	WINDOW  UnionExpr  FTUnit
|_______________________________________________________________________*/
{
protected:
	rchandle<UnionExpr> window_h;
	rchandle<FTUnit> unit_h;

public:
	FTWindow(
		yy::location const&,
		rchandle<UnionExpr> window_h,
		rchandle<FTUnit> unit_h);
	~FTWindow();

public:
	rchandle<UnionExpr> get_window() const { return window_h; }
	rchandle<FTUnit> get_unit() const { return unit_h; }

public:
	std::ostream& put(std::ostream&) const;

};




}	/* namespace xqp */
#endif	/*  XQP_EXPRNODES_H */

