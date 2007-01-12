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

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include <assert.h>

#include "../context/context.h"
#include "../parser/parse_constants.h"
#include "../datamodel/qname.h"
#include "../datamodel/sequence_type.h"
#include "../datamodel/type.h"
#include "../util/rchandle.h"
#include "../values/ft_options.h"

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
|	::= ExprSingle  ( ","  ExprSingle )*
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<expr> > expr_hv;

public:
	expr_list(yy::location const&);
	~expr_list();

public:
	void add(rchandle<expr> expr_h) { expr_hv.push_back(expr_h); }
	rchandle<expr> & operator[](int i) { return expr_hv[i]; }
	rchandle<expr> const& operator[](int i) const { return expr_hv[i]; }

	std::vector<rchandle<expr> >::const_iterator begin()
		{ return expr_hv.begin(); }
	std::vector<rchandle<expr> >::const_iterator end()
		{ return expr_hv.end(); }
	uint32_t size() const { return expr_hv.size(); }

public:
	std::ostream& put(std::ostream&) const;

};


// [33a] var_binding
struct var_binding : public rcobject
/*______________________________________________________________________
| ::= VARNAME  ("in"|":=")  ExprSingle
|     | VARNAME  TypeDeclaration  ("in"|":=")  ExprSingle
|     | VARNAME  PositionalVar  "in"  ExprSingle
|     | VARNAME  TypeDeclaration  PositionalVar  ("in"|":=")  ExprSingle
| 
|     | VARNAME  FTScoreVar  ("in"|":=")  ExprSingle
|     | VARNAME  TypeDeclaration  FTScoreVar  ("in"|":=")  ExprSingle
|     | VARNAME  PositionalVar  FTScoreVar  "in"  ExprSingle
|     | VARNAME  TypeDeclaration  PositionalVar  FTScoreVar  "in"  ExprSingle
|_______________________________________________________________________*/
{
  rchandle<QName> varname_h;
  sequence_type   type;
  rchandle<QName> posvar_h;
  rchandle<QName> ft_scorevar_h;
  rchandle<expr>  valexpr_h;

  var_binding() {}
  ~var_binding() {}

  rchandle<QName> get_varname() const { return varname_h; }
  void set_varname(rchandle<QName> q_h) { varname_h = q_h; }

  sequence_type get_type() const { return type; }
  void set_type(sequence_type t) { type = t; }

  rchandle<QName> get_posvar() const { return posvar_h; }
  void set_posvar(rchandle<QName> q_h) { posvar_h = q_h; }

  rchandle<QName> get_ft_scorevar() const { return ftscorevar_h; }
  void get_ft_scorevar(rchandle<QName> q_h) { ftscorevar_h = q_h; }

  rchandle<expr> get_valexpr() const { return valexpr_h; }
  void get_valexpr(rchandle<expr> e_h ) { valexpr_h = e_h; }

  std::ostream& put(std::ostream&) const;

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
	std::vector<var_binding> bind_v;
	rchandle<expr> where_h;
	rchandle<expr> orderby_h;
	rchandle<expr> retval_h;

public:
	flwor_expr(yy::location const&);
	~flwor_expr();

public:
	var_binding & opertor[](int i)
		{ return bind_v[i]; }
	var_binding const& opertor[](int i) const
		{ return bind_v[i]; }
	void add(var_binding const& bind_h)
		{ bind_v.push_back(bind_h); } 

	std::vector<var_binding>::const_iterator begin() const
		{ return bind_v.begin(); }
	std::vector<var_binding>::const_iterator end() const
		{ return bind_v.end(); }
	uint32_t bind_count() const { return bind_v.size(); }

	rchandle<expr> get_where() const { return where_h; }
	void set_where(rchandle<expr> e_h) { where_h = e_h; }

	rchandle<expr> get_orderby() const { return orderby_h; }
	void set_orderby(rchandle<expr> e_h) { orderby_h = e_h; }

	rchandle<expr> get_retval() const { return retval_h; }
	void set_retval(rchandle<expr> e_h) { retval_h = e_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [42] [http://www.w3.org/TR/xquery/#prod-xquery-QuantifiedExpr]
class quantified_expr : public expr
/*______________________________________________________________________
|	::= (<"some" "$">|<"every" "$">) QVarInDeclList "satisfies" ExprSingle
|_______________________________________________________________________*/
{
protected:
	enum quantification_mode_t qmode;
	std::vector<var_binding> bind_v;
	rchandle<expr> sat_expr_h;

public:
	quantified_expr(
		yy::location const&,
		enum quantification_mode_t);
	~quantified_expr();

public:
	var_binding & operator[](int i)
		{ return bind_v[i]; }
	var_binding const& operator[](int i) const
		{ return bind_v[i]; }
	void add(var_binding const& bind_h)
		{ bind_v.push_back(bind_h); } 

	std::vector<var_binding>::const_iterator begin() const
		{ return bind_v.begin(); }
	std::vector<var_binding>::const_iterator end() const
		{ return bind_v.end(); }
	uint32_t bind_count() const { return bind_v.size(); }

	enum quantification_mode_t get_qmode() const { return qmode; }
	void set_qmode(enum quantification_mode_t _qmode) { qmode = _qmode; }

	rchandle<expr> get_sat_expr() const { return sat_expr_h; }
	void set_sat_expr(rchandle<expr> e_h) { sat_expr_h = e_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [43] [http://www.w3.org/TR/xquery/#prod-xquery-TypeswitchExpr]

typedef struct case_clause
{
	rchandle<varref_expr> varref_h;
	sequence_type seqtype;
	rchandle<expr> case_expr_h;
} case_clause_t;


class typeswitch_expr : public expr
/*______________________________________________________________________
|	::= TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
|			|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT 
|					DOLLAR  VARNAME  RETURN  ExprSingle
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> switch_expr_h;
	std::vector<case_clause_t> case_clause_hv;
	rchandle<varref_expr> default_varname_h;
	rchandle<expr> default_clause_h;

public:
	typeswitch_expr(yy::location const&);
	~typeswitch_expr();

public:
	rchandle<expr> get_switch_expr() const { return switch_expr_h; }
	void set_switch_expr(rchandle<expr> e_h) { switch_expr_h = e_h; }

	rchandle<varref_expr> get_default_varname() const
		{ return default_varname; }
	void set_default_varname(rchandle<varref_expr> const& var) const
		{ default_varname = var; }

	rchandle<expr> get_default_clause() const { return default_clause_h; }
	void set_default_clause(rchandle<expr> const& e_h) { default_clause_h = e_h; }

	void add_clause(case_clause_t cc)
		{ case_clause_hv.push_back(cc); }

	std::vector<case_clause_t>::const_iterator begin() const
		{ return case_clause_hv.begin(); }
	std::vector<case_clause_t>::const_iterator end() const
		{ return case_clause_hv.end(); }
	uint32_t clause_count() const { return case_clause_hv.size(); }

	case_clause_t & operator[](int i) { return case_clause_hv[i]; }
	case_clause_t const& operator[](int i) const { return case_clause_hv[i]; }

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

	if_expr(
		yy::location const&);

	~if_expr();

public:
	rchandle<expr> get_cond_expr() const { return cond_expr_h; }
	void set_cond_expr(rchandle<expr> e_h) { cond_expr_h = e_h; }

	rchandle<expr> get_then_expr() const { return then_expr_h; }
	void set_then_expr(rchandle<expr> e_h) { then_expr_h = e_h; }

	rchandle<expr> get_else_expr() const { return else_expr_h; }
	void set_else_expr(rchandle<expr> e_h) { else_expr_h = e_h; }

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
	std::vector<rchandle<expr> > and_expr_hv;

public:
	or_expr(yy::location const&);
	~or_expr();

public:
	void add(rchandle<expr> e_h) { and_expr_hv.push_back(e_h); }

	rchandle<expr> & operator[](int i)
		{ return and_expr_hv[i]; }
	rchandle<expr> const& operator[](int i) const
		{ return and_expr_hv[i]; }

	std::vector<rchandle<expr> >::const_iterator begin()
		{ return and_expr_hv.begin(); }
	std::vector<rchandle<expr> >::const_iterator end()
		{ return and_expr_hv.end(); }
	uint32_t size() const { return and_expr_hv.size(); }

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
	std::vector<rchandle<expr> > comp_expr_hv;

public:
	and_expr(yy::location const&);
	~and_expr();

public:
	void add(rchandle<expr> expr_h) { comp_expr_hv.push_back(expr_h); }
	rchandle<expr> operator[](int i) const { return comp_expr_hv[i]; }

	std::vector<rchandle<expr> >::const_iterator begin()
		{ return comp_expr_hv.begin(); }
	std::vector<rchandle<expr> >::const_iterator end()
		{ return comp_expr_hv.end(); }
	uint32_t size() const { return comp_expr_hv.size(); }

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
	enum valcomp_t comp;
	rchandle<expr> lhs_h;
	rchandle<expr> rhs_h;

public:
	valcomp_expr(
		yy::location const&,
		enum valcomp_t comp,
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
	enum gencomp_t comp;
	rchandle<expr> lhs_h;
	rchandle<expr> rhs_h;

public:
	gencomp_expr(
		yy::location const&,
		enum gencomp_t,
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
	nodecomp_t comp;
	rchandle<expr> lhs_h;
	rchandle<expr> rhs_h;

public:
	valcomp_expr(
		yy::location const&,
		nodecomp_t comp,
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
	typedef std::pair<add_op_t,rchandle<expr> > addop_pair;

protected:
	std::vector<addop_pair> addopp_hv;

public:
	add_expr(yy::location const&);
	~add_expr();

public:
	void add(addop_pair const& addopp) { addopp_hv.push_back(addopp); }

	std::vector<addop_pair>::const_iterator begin() const
		{ return addopp_hv.begin(); }
	std::vector<addop_pair>::const_iterator end() const
		{ return addopp_hv.end(); }
	uint32_t size() const { return addopp_hv.size(); }

	rchandle<expr> expr_at(uint32_t n) const
		{ return addopp_hv[n].second; }
	enum add_op_t op_at(uint32_t n) const
		{ return addopp_hv[n].first; }

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
	typedef std::pair<mul_op_t,rchandle<expr> > mulop_pair;

protected:
	std::vector<mulop_pair> mulopp_hv;

public:
	mult_expr(yy::location const&)
	~mult_expr();

public:
	void add(mulop_pair mulopp) { mulopp_hv.push_back(mulopp); }

	std::vector<mulop_pair>::const_iterator begin() const
		{ return mulopp_hv.begin(); }
	std::vector<mulop_pair>::const_iterator end() const
		{ return mulopp_hv.end(); }
	uint32_t size() const { return mulopp_hv.size(); }

	rchandle<expr> expr_at(uint32_t n) const { return mulopp_hv[n].second; }
	enum mul_op_t op_at(uint32_t n) const { return mulopp_hv[n].first; }

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
	std::vector<rchandle<expr> > intex_expr_hv;

public:
	union_expr(yy::location const&);
	~union_expr();

public:
	void add(rchandle<expr> e) { intex_expr_hv.push_back(e); }

	std::vector<rchandle<expr> >::const_iterator begin() const
		{ return intex_expr_hv.begin(); }
	std::vector<rchandle<expr> >::const_iterator end() const
		{ return intex_expr_hv.end(); }
	uint32_t size() const { return intex_expr_hv.size(); }

	rchandle<expr> expr_at(uint32_t n) const { return intex_expr_hv[n]; }

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
	typedef std::pair<expr,intex_op_t> intexop_pair;

protected:
	std::vector<intexop_pair> intexopp_hv;

public:
	intersect_except_expr(yy::location const&);
	~intersect_except_expr();

public:
	void add(intexop_pair intexopp) { intexopp_hv.push_back(intexopp); }

	std::vector<intexop_pair>::const_iterator begin() const
		{ return intexopp_hv.begin(); }
	std::vector<intexop_pair>::const_iterator end() const
		{ return intexopp_hv.end(); }
	uint32_t size() const { return intexopp_hv.size(); }

	rchandle<expr> expr_at(uint32_t n) const { return intexopp_hv[n].first; }
	enum intex_op_t op_at(uint32_t n) const { return intexopp_hv[n].second; }

public:
	virtual std::ostream& put(std::ostream&) const;

};



// [54] [http://www.w3.org/TR/xquery/#prod-xquery-InstanceofExpr]
class instanceof_expr : public expr
/*______________________________________________________________________
|	::= TreatExpr ("instance" "of" SequenceType)?
|_______________________________________________________________________*/
{
public:

protected:
	rchandle<expr> expr_h;
	sequence_type seqtype;

public:
	instanceof_expr(
		yy::location const&,
		rchandle<expr>,
		sequence_type const&);

	~instanceof_expr();

public:
	rchandle<expr> get_expr() const { return expr_h; }
	sequence_type get_seqtype() const { return seqtype; }
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
	sequence_type seqtype;

public:
	treat_expr(
		yy::location const&,
		rchandle<expr>,
		sequence_type const&);

	~treat_expr();

public:
	rchandle<expr> get_expr() const { return expr_h; }
	sequence_type get_seqtype() const { return seqtype; }
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
	bool neg_b;
	rchandle<expr> expr_h;

public:
	unary_expr(
		yy::location const&,
		bool neg_b,
		rchandle<expr>);
	~unary_expr();

public:
	bool is_negative() const { return neg_b; }
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
	enum validation_mode_t valmode;
	rchandle<expr> expr_h;

public:
	validate_expr(
		yy::location const&,
		enum validation_mode_t,
		rchandle<expr>);
	~validate_expr();

public:
	rchandle<expr> get_expr() const { return expr_h; }
	enum validation_mode_t get_valmode() const { return valmode; }

public:
	std::ostream& put(std::ostream&) const;

};



// [65] [http://www.w3.org/TR/xquery/#prod-xquery-ExtensionExpr]

struct pragma
{
	rchandle<QName> name_h;
	std::string content;
};


class extension_expr : public expr
/*______________________________________________________________________
|	::= PragmaList "{" Expr? "}"
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<pragma_name> > pragma_hv;
	rchandle<expr> expr_h;

public:
	extension_expr(yy::location const&);
	~extension_expr();

public:
	void add(rchandle<pragma> pragma_h)
		{ pragma_hv.push_back(pragma_h); }
	rchandle<pragma> & operator[](int i)
		{ return pragma_hv[i]; }
	rchandle<pragma> const& operator[](int i) const
		{ return pragma_hv[i]; }

	std::vector<rchandle<pragma> >::const_iterator begin()
		{ return pragma_hv.begin(); }
	std::vector<rchandle<pragma> >::const_iterator end()
		{ return pragma_hv.end(); }
	uint32_t size() const { return pragma_hv.size(); }

public:
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
	void add(rchandle<step_expr> step_h) { step_hv.push_back(step_h); }

	std::vector<rchandle<step_expr>>::const_iterator begin() const
		{ return step_hv.begin(); }
	std::vector<rchandle<step_expr>>::const_iterator end() const
		{ return step_hv.end(); }
	uint32_t size() const { return step_h_hv.size(); }

	rchandle<expr>& operator[](int n) { return step_hv[n]; }
	rchandle<expr> const& operator[](int n) const { return step_hv[n]; }

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
		child,
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
	test_t docnode_test;
	wild_t wild;
	rchandle<QName> name_h;
	rchandle<QName> typename_h;
	std::vector<rchandle<expr> > pred_hv;

public:
	axis_step_expr( yy::location const&);
	~axis_step_expr();

public:
	axis_t get_axis() const { return axis; }
	test_t get_test() const { return test; }
	test_t get_docnode_test() const { return docnode_test; }
	wild_t get_wild() const { return wild; }
	rchandle<QName> get_name() const { return name_h; }
	rchandle<QName> get_typename() const { return typename_h; }

	void set_axis(axis_t v) const { axis = v; }
	void set_test(test_t v) const { test = v; }
	void set_docnode_test(test_t v) const { docnode_test = v; }
	void set_wild(wild_t v) const { wild = v; }
	void set_name(rchandle<QName> v_h) const { name_h = v_h; }
	void set_typename(rchandle<QName> v_h) const { typename_h = v_h; }

public:
	void add(rchandle<expr> e_h) { pred_hv.push_back(e_h); }
	rchandle<expr> & operator[](int i) { return pred_hv[i]; }
	rchandle<expr> const& operator[](int i) const { return pred_hv[i]; }

	std::vector<rchandle<expr> >::const_iterator begin()
		{ return pred_hv.begin(); }
	std::vector<rchandle<expr> >::const_iterator end()
		{ return pred_hv.end(); }
	uint32_t size() const { return pred_hv.size(); }

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
		uint32_t sref;
		int ival;
		decimal decval;
		double dval;
	};

public:
	literal_expr(yy::location const&, uint32_t sref);
	literal_expr(yy::location const&, int);
	literal_expr(yy::location const&, decimal);
	literal_expr(yy::location const&, double);
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
class order_expr : public expr
/*______________________________________________________________________
|	::= ORDERED_LBRACE  Expr  RBRACE
|			| UNORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
public:
	enum order_type_t {
		ordered,
		unordered
	};

protected:
	order_type_t type;
	rchandle<expr> expr_h;

public:
	ordered_expr(
		yy::location const&,
		order_type_t,
		rchandle<expr>);
	~ordered_expr();

public:
	order_type_t get_type() const { return type; }
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
		rchandle<QName>);

	~funcall();

public:
	rchandle<QName> get_fname() const { return fname_h; }

	void add(rchandle<QName> const& arg_h)
		{ arg_hv.push_back(arg_h); }
	uint32_t arg_count() const
		{ return arg_hv.size(); }

	std::vector<rchandle<expr> >:: const_iterator begin() const
		{ return arg_hv.begin(); }
	std::vector<rchandle<expr> >:: const_iterator end() const
		{ return arg_hv.end(); }

	rchandle<QName> & operator(int i)
		{ return arg_hv[i]; }
	rchandle<QName> const& operator(int i) const
		{ return arg_hv[i]; }

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
	rchandle<expr> docuri_h;

public:
	doc_expr(
		yy::location const&,
		rchandle<expr>);
	~CompDocConstructor();

public:
	rchandle<expr> get_docuri() const { return docuri_h; }

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

protected:
	rchandle<QName> qname_h;
	rchandle<expr> name_expr_h;
	rchandle<expr> content_expr_h;
	std::vector<nsbinding> nsb_v;

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

	void add(nsbinding const& nsb) { nsb_v.push_back(nsb); }
	uint32_t nsbinding_count() const { return nsb_v.size(); }

	std::vector<nsbinding>::const_iterator begin() const
		{ return nsb_v.begin(); }
	std::vector<nsbinding>::const_iterator end() const
		{ return nsb_v.end(); }

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
		rchandle<expr>);
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
class ft_expr : public expr
/*______________________________________________________________________
|	::=	 FTOr  FTMatchOptionProximityList?  ("weight"  FTRangeExpr)?
|_______________________________________________________________________*/
{
protected:
	rchandle<ft_expr> ft_or_h;
	rchandle<ft_options> ft_opt_h;

public:
	ftselection_expr(
		yy::location const&,
		rchandle<ft_or_expr>,
		rchandle<ft_options>);

	~ftselection_expr();

public:
	rchandle<ft_expr> get_ft_or() const { return ft_or_h; }
	rchandle<ft_options> get_ft_options() const { return ft_opt_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[345] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTOr]
class ft_or_expr : public ft_expr
/*______________________________________________________________________
|	::=	FTAnd ( "||" FTAnd )*
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<ft_expr> > ft_and_expr_hv;

public:
	ft_or_expr(yy::location const&);
	~ft_or_expr();

public:
	uint32_t size() const { return ft_and_expr_hv.size(); }
	void add(rchandle<ft_expr> ft_h) { ft_and_expr_hv.push_back(ft_h); }

	rchandle<ft_expr> & operator[](int i)
		{ return ft_and_expr_hv[i]; }
	rchandle<ft_expr> const& operator[](int i) const
		{ return ft_and_expr_hv[i]; }

	std::vector<rchandle<ft_expr> >::const_iterator begin()
		{ return ft_and_expr_hv.begin(); }
	std::vector<rchandle<ft_expr> >::const_iterator end()
		{ return ft_and_expr_hv.end(); }

public:
	std::ostream& put(std::ostream&) const;

};



//[346] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTAnd]
class ft_and_expr : public ft_expr
/*______________________________________________________________________
|	::=	FTMildnot ( '&&' FTMildNot )*
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<ft_expr> > ft_mildnot_expr_hv;

public:
	ft_and_expr(yy::location const&);
	~ft_and_expr();

public:
	void add(rchandle<ft_expr> ft_h) { ft_mildnot_expr_hv.push_back(ft_h); }

	rchandle<ft_expr> & operator[](int i)
		{ return ft_mildnot_expr_hv[i]; }
	rchandle<ft_expr> const& operator[](int i) const
		{ return ft_mildnot_expr_hv[i]; }

	std::vector<rchandle<ft_expr> >::const_iterator begin()
		{ return ft_mildnot_expr_hv.begin(); }
	std::vector<rchandle<ft_expr> >::const_iterator end()
		{ return ft_mildnot_expr_hv.end(); }
	uint32_t size() const { return ft_mildnot_expr_hv.size(); }

public:
	std::ostream& put(std::ostream&) const;

};



//[347] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTMildnot]
class ft_mildnot_expr : public ft_expr
/*______________________________________________________________________
|	::=	FTUnaryNot ( "not" "in" FTUnaryNot )*
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<ft_expr> > ft_unary_expr_hv;

public:
	ft_mildnot_expr(yy::location const&);
	~ft_mildnot_expr();

public:
	void add(rchandle<ft_expr> ft_h) { ft_unary_expr_hv.push_back(ft_h); }

	rchandle<ft_expr> & operator[](int i)
		{ return ft_unary_expr_hv[i]; }
	rchandle<ft_expr> const& operator[](int i) const
		{ return ft_unary_expr_hv[i]; }

	std::vector<rchandle<ft_expr> >::const_iterator begin()
		{ return ft_unary_expr_hv.begin(); }
	std::vector<rchandle<ft_expr> >::const_iterator end()
		{ return ft_unary_expr_hv.end(); }
	uint32_t size() const { return ft_unary_expr_hv.size(); }

public:
	std::ostream& put(std::ostream&) const;

};



//[348] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTUnaryNot]
class ft_unarynot_expr : public ft_expr
/*______________________________________________________________________
|	::=	("!")? FTWordsSelection
|_______________________________________________________________________*/
{
protected:
	rchandle<FTWordsSelection> words_selection_h;
	bool not_b;

public:
	ft_unarynot_expr(
		yy::location const&,
		rchandle<FTWordsSelection>,
		bool not_b);

	~ft_unarynot_expr();

public:
	rchandle<FTWordsSelection> get_words_selection() const
		{ return words_selection_h; }
	bool get_not_bit() const
		{ return not_b; }

public:
	std::ostream& put(std::ostream&) const;

};



//[349] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWordsSelection]
class ft_words_selection_expr : public ft_expr
/*______________________________________________________________________
|	::=	FTWords	 FTTimes?
|			| LPAR  FTSelection  RPAR
|_______________________________________________________________________*/
{
protected:
	rchandle<FTWords> words_h;
	rchandle<FTTimes> times_h;
	rchandle<FTSelection> selection_h;

public:
	ft_words_selection_expr(
		yy::location const&,
		rchandle<FTWords>,
		rchandle<FTTimes>,
		rchandle<FTSelection>);
	
	~ft_words_selection();

public:
	rchandle<FTWords> get_words() const { return words_h; }
	rchandle<FTTimes> get_times() const { return times_h; }
	rchandle<FTSelection> get_selection() const { return selection_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[350] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWords]
class ft_words_exor : public expr
/*______________________________________________________________________
|	::=	FTWordsValue  FTAnyallOption?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> words_expr_h;
	ft_anyall_option_t anyall_opt;

public:
	ft_words_expr(
		yy::location const&,
		rchandle<expr>,
		ft_anyall_option);

	~ft_words_expr();

public:
	rchandle<expr> get_words_expr() const
		{ return words_expr_h; }
	ft_anyall_option_t get_anyall_option() const
		{ return anyall_opt; }

public:
	std::ostream& put(std::ostream&) const;

};



}	/* namespace xqp */
#endif	/*  XQP_EXPRNODES_H */

