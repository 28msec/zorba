/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: expr.h,v 1.1.1.1 2006/11/06 08:42:18 Paul Pedersen Exp $
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
#include "../types/type.h"
#include "../util/rchandle.h"

#include "location.hh"



namespace xqp {


/*______________________________________________________________________
|  
|	base class for the expression tree node hierarchy
|_______________________________________________________________________*/

class expr : public rcobject
{
protected:
	yy::location loc;

public:
	expr(yy::location const& _loc) : loc(_loc) {}
	expr() {}
  ~expr() {}

public:
	yy::location get_location() const { return loc; }
	virtual std::ostream& put(std::ostream& s) const;

};

std::ostream& operator<<(std::ostream& s, expr const& r)
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
class expr_list : public expr
/*______________________________________________________________________
|	::= ExprSingle | Expr  COMMA  ExprSingle
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<expr> > expr_hv;

public:
	expr_list(yy::location const&);
	~expr_list();

public:
	void push_back(rchandle<expr> expr_h) { expr_hv.push_back(expr_h); }
	rchandle<expr> operator[](int i) const { return expr_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;

};



// [32] [http://www.w3.org/TR/xquery/#prod-xquery-ExprSingle]
class expr_single : public expr
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
class flwor_expr : public expr
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
	rchandle<expr>  retval_h;

public:
	flwor_expr(
		yy::location const&,
		std::vector<rchandle<var_binding> > bind_hv;
		rchandle<expr_expr>  where_h;
		rchandle<order_expr> orderby_h;
		rchandle<expr>  retval_h);
	~flwor_expr();

public:
	rchandle<var_binding> opertor[](int i);
	rchandle<expr_expr> get_where() const { return where_h; }
	rchandle<order_expr> get_orderby() const { return orderby_h; }
	rchandle<expr> get_retval() const { return retval_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [42] [http://www.w3.org/TR/xquery/#prod-xquery-QuantifiedExpr]
class quantified_expr : public expr
/*______________________________________________________________________
|	::= SOME_DOLLAR  QVarInDeclList | EVERY_DOLLAR  QVarInDeclList
|_______________________________________________________________________*/
{
protected:
	QuantifiedExpr::quantification_mode_t qmode;
	rchandle<QVarInDeclList> decl_list_h;
	rchandle<expr> expr_h;

public:
	QuantifiedExpr(
		yy::location const&,
		quantification_mode_t qmode,
		rchandle<QVarInDeclList>,
		rchandle<expr>);
	~QuantifiedExpr();

public:
	quantification_mode_t get_qmode() const { return qmode; }
	rchandle<QVarInDeclList> get_decl_list() const { return decl_list_h; }
	rchandle<expr> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [43] [http://www.w3.org/TR/xquery/#prod-xquery-TypeswitchExpr]
class typeswitch_expr : public expr
/*______________________________________________________________________
|	::= TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
|			|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT 
|					DOLLAR  VARNAME  RETURN  ExprSingle
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> switch_expr_h;
	rchandle<CaseClauseList> clause_list_h;
	std::string default_varname;
	rchandle<expr> default_clause_h;

public:
	typeswitch_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<CaseClauseList>,
		rchandle<expr>);
	typeswitch_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<CaseClauseList>,
		std::string default_varname,
		rchandle<expr>);
	~typeswitch_expr();

public:
	rchandle<expr> get_switch_expr() const { return switch_expr_h; }
	rchandle<CaseClauseList> get_clause_list() const { return clause_list_h; }
	std::string get_default_varname() const { return default_varname; }
	rchandle<expr> get_default_clause() const { return default_clause_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [45] [http://www.w3.org/TR/xquery/#prod-xquery-IfExpr]
class if_expr : public expr
/*______________________________________________________________________
|	::= <"if" "("> Expr ")" "then" ExprSingle "else" ExprSingle
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> cond_expr_h;
	rchandle<expr> then_expr_h;
	rchandle<expr> else_expr_h;

public:
	if_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<expr>,
		rchandle<expr>);
	~if_expr();

public:
	rchandle<expr> get_cond_expr() const { return cond_expr_h; }
	rchandle<expr> get_then_expr() const { return then_expr_h; }
	rchandle<expr> get_else_expr() const { return else_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [46] [http://www.w3.org/TR/xquery/#prod-xquery-OrExpr]
class or_expr : public expr
/*______________________________________________________________________
|	::= AndExpr ("or" AndExpr)*
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> or_expr_h;
	rchandle<expr> and_expr_h;

public:
	or_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<expr>);
	~or_expr();

public:
	rchandle<expr> get_or_expr() const { return or_expr_h; }
	rchandle<expr> get_and_expr() const { return and_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [47] [http://www.w3.org/TR/xquery/#prod-xquery-AndExpr]
class and_expr : public expr
/*______________________________________________________________________
|	::= ComparisonExpr ("and" ComparisonExpr)*
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> and_expr_h;
	rchandle<expr> comp_expr_h;

public:
	and_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<expr>);
	~and_expr();

public:
	rchandle<expr> get_and_expr() const { return and_expr_h; }
	rchandle<expr> get_comp_expr() const { return comp_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [48] [http://www.w3.org/TR/xquery/#prod-xquery-ComparisonExpr]
class valcomp_expr : public expr
/*______________________________________________________________________
|	::= FTContainsExpr ((ValueComp | GeneralComp | NodeComp) FTContainsExpr)?
|_______________________________________________________________________*/
{
protected:
	ValueComp::valcomp_t comp;
	rchandle<expr> lhs_h;
	rchandle<expr> rhs_h;

public:
	valcomp_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<expr>);
	~valcomp_expr();

public:
	rchandle<expr> get_lhs() const { return lhs_h; }
	rchandle<expr> get_rhs() const { return rhs_h; }
	enum valcomp_t get_comp() const { return comp; }

public:
	virtual std::ostream& put(std::ostream&) const;

};


class gencomp_expr : public expr
{
protected:
	GeneralComp::gencomp_t comp;
	rchandle<expr> lhs_h;
	rchandle<expr> rhs_h;

public:
	gencomp_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<expr>);
	~gencomp_expr();

public:
	rchandle<expr> get_lhs() const { return lhs_h; }
	rchandle<expr> get_rhs() const { return rhs_h; }
	enum gencomp_t get_comp() const { return comp; }

public:
	virtual std::ostream& put(std::ostream&) const;

};


class nodecomp_expr : public expr
{
protected:
	NodeComp::nodecomp_t comp;
	rchandle<expr> lhs_h;
	rchandle<expr> rhs_h;

public:
	valcomp_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<expr>);
	~valcomp_expr();

public:
	rchandle<expr> get_lhs() const { return lhs_h; }
	rchandle<expr> get_rhs() const { return rhs_h; }
	enum nodecomp_t get_comp() const { return comp; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [48a] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTContainsExpr]
class ft_contains_expr : public expr
/*______________________________________________________________________
|	::= RangeExpr ("ftcontains" FTSelection FTIgnoreOption?)?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> range_h;
	rchandle<ft_select_expr> ft_select_h;
	rchandle<expr> ignore_h;

public:
	ft_contains_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<ft_select_expr>,
		rchandle<expr>);
	~ftcontains_expr();

public:
	rchandle<expr> get_range() const { return range_h; }
	rchandle<ft_select_expr> get_ft_select() const { return ft_select_h; }
	rchandle<expr> get_ignore() const { return ignore_h; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [49] [http://www.w3.org/TR/xquery/#prod-xquery-RangeExpr]
class range_expr : public expr
/*______________________________________________________________________
|	::= AdditiveExpr ("to" AdditiveExpr)?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> from_expr_h;
	rchandle<expr> to_expr_h;

public:
	range_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<expr>);
	~range_expr();

public:
	rchandle<expr> get_from_expr() const { return from_expr_h; }
	rchandle<expr> get_to_expr() const { return to_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [50] [http://www.w3.org/TR/xquery/#prod-xquery-AdditiveExpr]
class add_expr : public expr
/*______________________________________________________________________
|	::= MultiplicativeExpr (("+"|"-") MultiplicativeExpr)*
|_______________________________________________________________________*/
{
public:
	typedef AdditivetiveExpr::add_op_t addop;
	typedef std::pair<rchandle<expr>,addop> addop_pair;

protected:
	std::vector<addop_pair> aopp_hv;

public:
	add_expr(yy::location const&);
	~add_expr();

public:
	void add(addop_pair aopp) { aopp_hv.push_back(aopp); }

	std::vector<addop_pair>::const_iterator begin() const
		{ return aopp_hv.begin(); }
	std::vector<addop_pair>::const_iterator end() const
		{ return aopp_hv.end(); }
	uint32_t size() const { return aopp_hv.size(); }

	rchandle<expr> expr_at(uint32_t n) const
		{ return aopp_hv[n].first; }
	rchandle<expr> op_at(uint32_t n) const
		{ return aopp_hv[n].second; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [51] [http://www.w3.org/TR/xquery/#prod-xquery-MultiplicativeExpr]
class mult_expr : public expr
/*______________________________________________________________________
|	::= UnionExpr (("*"|"div"|"idiv"|"mod") UnionExpr)?
|_______________________________________________________________________*/
{
public:
	typedef MultiplicativeExpr::mult_op_t mulop;
	typedef std::pair<rchandle<expr>,mulop> mulop_pair;

protected:
	std::vector<mulop_pair> mopp_hv;

public:
	mult_expr(yy::location const&)
	~mult_expr();

public:
	void add(mulop_pair mopp) { mopp_hv.push_back(mopp); }

	std::vector<mulop_pair>::const_iterator begin() const
		{ return mopp_hv.begin(); }
	std::vector<mulop_pair>::const_iterator end() const
		{ return mopp_hv.end(); }
	uint32_t size() const { return mopp_hv.size(); }

	rchandle<expr> expr_at(uint32_t n) const
		{ return mopp_hv[n].first; }
	rchandle<expr> op_at(uint32_t n) const
		{ return mopp_hv[n].second; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [52] [http://www.w3.org/TR/xquery/#prod-xquery-UnionExpr]
class union_expr : public expr
/*______________________________________________________________________
|	::= IntersectExceptExpr (("union" | "|") IntersectExceptExpr)*
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<expr> > expr_hv;

public:
	union_expr(yy::location const&);
	~union_expr();

public:
	void add(rchandle<expr> e) { expr_hv.push_back(e); }

	std::vector<rchandle<expr> >::const_iterator begin() const
		{ return expr_hv.begin(); }
	std::vector<rchandle<expr> >::const_iterator end() const
		{ return expr_hv.end(); }
	uint32_t size() const { return expr_hv.size(); }
	rchandle<expr> expr_at(uint32_t n) const { return expr_hv[n]; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [53] [http://www.w3.org/TR/xquery/#prod-xquery-IntersectExceptExpr]
class intersect_except_expr : public expr
/*______________________________________________________________________
|	::= InstanceofExpr (("intersect" | "except") InstanceofExpr)*
|_______________________________________________________________________*/
{
public:
	typedef IntersectExceptExpr::intex_op_t intexop;
	typedef std::pair<expr,intexop> intexop_pair;

protected:
	std::vector<intexop_pair> ixopp_hv;

public:
	intersect_except_expr(yy::location const&);
	~intersect_except_expr();

public:
	void add(intexop_pair ixopp) { ixopp_hv.push_back(ixopp); }

	std::vector<intexop_pair>::const_iterator begin() const
		{ return ixopp_hv.begin(); }
	std::vector<intexop_pair>::const_iterator end() const
		{ return ixopp_hv.end(); }
	uint32_t size() const { return ixopp_hv.size(); }

	rchandle<expr> expr_at(uint32_t n) const
		{ return ixopp_hv[n].first; }
	rchandle<expr> op_at(uint32_t n) const
		{ return ixopp_hv[n].second; }

public:
	virtual std::ostream& put(std::ostream&) const;

};


/*______________________________________________________________________
|  
|	SequenceType ::= item_type ["?" | "*" | "+" ]  |  empty-sequence()
|_______________________________________________________________________*/

enum cardinality {
	empty,
	optional,
	zero_or_more,
	one_or_more
};

typedef std::pair<item_type,cardinality> seqtype_t;



// [54] [http://www.w3.org/TR/xquery/#prod-xquery-InstanceofExpr]
class instanceof_expr : public expr
/*______________________________________________________________________
|	::= TreatExpr ("instance" "of" SequenceType)?
|_______________________________________________________________________*/
{
public:

protected:
	rchandle<expr> expr_h;
	seqtype_t seqtype;

public:
	instanceof_expr(
		yy::location const&,
		rchandle<expr>,
		seqtype_t);
	~instanceof_expr();

public:
	rchandle<expr> get_expr() const { return expr_h; }
	seqtype_t get_seqtype() const { return seqtype; }
	virtual std::ostream& put(std::ostream&) const;

};



// [55] [http://www.w3.org/TR/xquery/#prod-xquery-TreatExpr]
class treat_expr : public expr
/*______________________________________________________________________
|	::= CastableExpr ("treat" "as" SequenceType)?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> expr_h;
	seqtype_t seqtype;

public:
	treat_expr(
		yy::location const&,
		rchandle<expr>,
		seqtype_t);
	~treat_expr();

public:
	rchandle<expr> get_expr() const { return expr_h; }
	seqtype_t get_seqtype() const { return seqtype; }
	virtual std::ostream& put(std::ostream&) const;

};



/*______________________________________________________________________
|  
| SingleType ::= AtomicType "?"?
|_______________________________________________________________________*/

typedef std::pair<atomic_type,bool> single_type_t;


// [56] [http://www.w3.org/TR/xquery/#prod-xquery-CastableExpr]
class castable_expr : public expr
/*______________________________________________________________________
|	::= CastExpr ("castable" "as" SingleType)?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> cast_expr_h;
	single_type_t t;

public:
	castable_expr(
		yy::location const&,
		rchandle<expr>,
		single_type_t);
	~castable_expr();

public:
	rchandle<expr> get_cast_expr() const { return cast_expr_h; }
	single_type_t get_type() const { return t; }
	atomic_type get_atomic_type() const { return t.first; }
	bool is_optional() const { return t.second; }
	virtual std::ostream& put(std::ostream&) const;

};



// [57] [http://www.w3.org/TR/xquery/#prod-xquery-CastExpr]
class cast_expr : public expr
/*______________________________________________________________________
|	::= UnaryExpr ("cast" "as" SingleType)?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> unary_expr_h;
	single_type_t t;

public:
	cast_expr(
		yy::location const&,
		rchandle<expr>,
		single_type_t);
	~cast_expr();

public:
	rchandle<expr> get_unary_expr() const { return unary_expr_h; }
	single_type_t get_type() const { return t; }
	atomic_type get_atomic_type() const { return t.first; }
	bool is_optional() const { return t.second; }
	virtual std::ostream& put(std::ostream&) const;

};



// [58] [http://www.w3.org/TR/xquery/#prod-xquery-UnaryExpr]
class unary_expr : public expr
/*______________________________________________________________________
|	::= ("+"|"-")* ValueExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> expr_h;

public:
	unary_expr(
		yy::location const&,
		rchandle<SignList>,
		rchandle<expr>);
	~unary_expr();

public:
	rchandle<expr> get_expr() const { return expr_h; }
	virtual std::ostream& put(std::ostream&) const;

};



// [63] [http://www.w3.org/TR/xquery/#prod-xquery-ValidateExpr]
class validate_expr : public expr
/*______________________________________________________________________
|	::= "validate" ValidationMode? "{" Expr "}"
|_______________________________________________________________________*/
{
protected:
	ValidateExpr::validation_mode_t valmode;
	rchandle<expr> expr_h;

public:
	validate_expr(yy::location const&);
	~validate_expr();

public:
	rchandle<expr> get_expr() const { return expr_h; }
	ValidateExpr::validation_mode_t get_valmode() const { return valmode; }

public:
	std::ostream& put(std::ostream&) const;

};



// [65] [http://www.w3.org/TR/xquery/#prod-xquery-ExtensionExpr]
class extension_expr : public expr
/*______________________________________________________________________
|	::= PragmaList "{" Expr? "}"
|_______________________________________________________________________*/
{
protected:
	rchandle<PragmaList> pragma_list_h;
	rchandle<expr> expr_h;

public:
	extension_expr(
		yy::location const&,
		rchandle<PragmaList>,
		rchandle<expr>);
	~extension_expr();

public:
	rchandle<PragmaList> get_pragma_list() const { return pragma_list_h; }
	rchandle<expr> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [69] [http://www.w3.org/TR/xquery/#prod-xquery-RelativePathExpr]
class relpath_expr : public expr
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
class step_expr : public expr
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
class axis_step_expr : public expr
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
	std::vector<rchandle<expr> > pred_hv;

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
class primary_expr : public expr
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
class literal_expr : public expr
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
class varref_expr : public expr
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
class ordered_expr : public expr
/*______________________________________________________________________
|	::= ORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> expr_h;

public:
	ordered_expr(
		yy::location const&,
		rchandle<expr>);
	~ordered_expr();

public:
	rchandle<expr> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [92] [http://www.w3.org/TR/xquery/#prod-xquery-UnorderedExpr]
class unordered_expr : public expr
/*______________________________________________________________________
|	::= UNORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> expr_h;

public:
	unordered_expr(
		yy::location const&,
		rchandle<expr>);
	~unordered_expr();

public:
	rchandle<expr> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [93] [http://www.w3.org/TR/xquery/#prod-xquery-FunctionCall]
class funcall_expr : public expr
/*______________________________________________________________________
|	::= QNAME  LPAR  ArgList  RPAR 	
|																	gn:parensXQ
|			 														gn:reserved-function-namesXQ 
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> fname_h;
	std::vector<rchandle<expr> > arg_hv;

public:
	funcall(
		yy::location const&,
		rchandle<QName>,
		std::vector<rchandle<expr> > arg_hv);
	~funcall();

public:
	rchandle<QName> get_fname() const { return fname_h; }
	rchandle<expr> get_arg(uint32_t n) const { return arg_hv[n]; }
	uint32_t arg_count() const { return arg_hv.size(); }

	std::vector<rchandle<expr> >:: const_iterator arg_begin() const
		{ return arg_hv.begin(); }
	std::vector<rchandle<expr> >:: const_iterator arg_end() const
		{ return arg_hv.end(); }

public:
	std::ostream& put(std::ostream&) const;

};



// [109] [http://www.w3.org/TR/xquery/#prod-xquery-ComputedConstructor]
class cons_expr : public expr
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
class doc_expr : public expr
/*______________________________________________________________________
|	::= DOCUMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> expr_h;

public:
	doc_expr(
		yy::location const&,
		rchandle<expr>);
	~CompDocConstructor();

public:
	rchandle<expr> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [111] [http://www.w3.org/TR/xquery/#prod-xquery-CompElemConstructor]
class elem_expr : public expr
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
	rchandle<expr> name_expr_h;
	rchandle<expr> content_expr_h;
	std::vector<rchandle<nsbinding> > nsb_hv;

public:
	elem_expr(
		yy::location const&,
		rchandle<QName>,
		rchandle<expr>);
	elem_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<expr>);
	~elem_expr();

public:
	rchandle<QName> get_name() const { return name_h; }
	rchandle<expr> get_name_expr() const { return name_expr_h; }
	rchandle<expr> get_content_expr() const { return content_expr_h; }

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
class attr_expr : public expr
/*______________________________________________________________________
|	::= ATTRIBUTE  QNAME  LBRACE  RBRACE
|			|	ATTRIBUTE  QNAME  LBRACE  Expr  RBRACE
|			|	ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  RBRACE
|			|	ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> name_h;
	rchandle<expr> name_expr_h;
	rchandle<expr> val_expr_h;

public:
	attr_expr(
		yy::location const&,
		rchandle<QName>,
		rchandle<expr>);
	attr_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<expr>);
	~attr_expr();

public:
	rchandle<QName> get_name() const { return qname_h; }
	rchandle<expr> get_name_expr() const { return qname_expr_h; }
	rchandle<expr> get_val_expr() const { return val_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompTextConstructor]
class text_expr : public expr
/*______________________________________________________________________
|	::= TEXT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> text_expr_h;

public:
	text_expr(
		yy::location const&,
		rchandle<expr> text_expr_h);
	~text_expr();

public:
	rchandle<expr> get_text_expr() const { return text_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [115] [http://www.w3.org/TR/xquery/#prod-xquery-CompCommentConstructor]
class comment_expr : public expr
/*______________________________________________________________________
|	::= COMMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> comment_expr_h;

public:
	comment_expr(
		yy::location const&,
		rchandle<expr>);
	~comment_expr();

public:
	rchandle<expr> get_comment_expr() const { return comment_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompPIConstructor]
class pi_expr : public expr
/*______________________________________________________________________
|	::= PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
|			|	PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RBRACE
|			|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  RBRACE
|			|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	std::string target;
	rchandle<expr> target_expr_h;
	rchandle<expr> content_expr_h;

public:
	pi_expr(
		yy::location const&,
		std::string target,
		rchandle<expr>);
	pi_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<expr>);
	~pi_expr();

public:
	std::string get_target() const { return target; }
	rchandle<expr> get_target_expr() const { return target_expr_h; }
	rchandle<expr> get_content_expr() const { return content_expr_h; }

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
	rchandle<expr> source_expr_h;
	rchandle<expr> target_expr_h;

public:
	insert_expr(
		yy::location const&,
		rchandle<expr>,
		rchandle<expr>);
	~insert_expr();

public:
	rchandle<expr> get_source_expr() const { return source_expr_h; }
	rchandle<expr> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [243] [http://www.w3.org/TR/xqupdate/#prod-xquery-DeleteExpr]
class delete_expr : public expr
/*______________________________________________________________________
|	::= DO_DELETE  expr
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> target_expr_h;

public:
	delete_expr(
		yy::location const&,
		rchandle<expr>);
	~delete_expr();

public:
	rchandle<expr> get_target_expr() const { return target_expr_h; }

public:
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
	rchandle<expr> source_expr_h;
	rchandle<expr> target_expr_h;

public:
	replace_expr(
		yy::location const&,
		rchandle<expr> source_expr_h,
		rchandle<expr> target_expr_h);
	~replace_expr();

public:
	rchandle<expr> get_source_expr() const { return source_expr_h; }
	rchandle<expr> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [245] [http://www.w3.org/TR/xqupdate/#prod-xquery-RenameExpr]
class rename_expr : public expr
/*______________________________________________________________________
|	::= DO_RENAME  expr  AS  expr
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> source_expr_h;
	rchandle<expr> target_expr_h;

public:
	rename_expr(
		yy::location const&,
		rchandle<expr> source_expr_h,
		rchandle<expr> target_expr_h);
	~rename_expr();

public:
	rchandle<expr> get_source_expr() const { return source_expr_h; }
	rchandle<expr> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [249] [http://www.w3.org/TR/xqupdate/#prod-xquery-TransformExpr]
class transform_expr : public expr
/*______________________________________________________________________
|	::= TRANSFORM_COPY_DOLLAR  VarNameList
|				MODIFY  expr  RETURN  expr
|_______________________________________________________________________*/
{
protected:
	rchandle<VarNameList> varname_list_h;
	rchandle<expr> source_expr_h;
	rchandle<expr> target_expr_h;

public:
	transform_expr(
		yy::location const&,
		rchandle<VarNameList>,
		rchandle<expr> source_expr_h,
		rchandle<expr> target_expr_h);
	~transform_expr();

public:
	rchandle<VarNameList> get_varname_list() const { return varname_list_h; }
	rchandle<expr> get_source_expr() const { return source_expr_h; }
	rchandle<expr> get_target_expr() const { return target_expr_h; }

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
class ftselection_expr : public expr
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
	ftselection_expr(
		yy::location const&,
		rchandle<FTOr>,
		rchandle<FTMatchOptionProximityList>,
		rchandle<RangeExpr>);
	~ftselection_expr();

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
class FTMatchOptionProximityList : public expr
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
class FTMatchOptionProximity : public expr
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
class FTOr : public expr
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
class FTAnd : public expr
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
class FTMildnot : public expr
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
class FTUnaryNot : public expr
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
class FTWordsSelection : public expr
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
class FTWords : public expr
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
class FTWordsValue : public expr
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
class FTProximity : public expr
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
class FTMatchOption : public expr
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
class FTThesaurusList : public expr
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
class FTThesaurusID : public expr
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
class FTInclExclStringLiteralList : public expr
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
class FTRefOrList : public expr
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
class FTStringLiteralList : public expr
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
class FTInclExclStringLiteral : public expr
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
class FTAnyallOption : public expr
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
class FTRange : public expr
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

