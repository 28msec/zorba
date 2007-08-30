/**
 * @file exprtree/expr.h
 * @author: John Cowan, Paul Pedersen
 * @copyright 2006-2007 FLWOR FOundation.
 *
 * ========================================================================
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 */

#ifndef XQP_EXPR_H
#define XQP_EXPR_H

#include <string>
#include <vector>

#include "context/static_context.h"
#include "functions/function.h"
#include "runtime/expr_visitor.h"
#include "runtime/item_iterator.h"
#include "parser/location.hh"
#include "parser/parse_constants.h"
#include "parser/parsenodes.h"
#include "types/sequence_type.h"
#include "util/list.h"
#include "util/rchandle.h"
#include "values/ft_options.h"
#include "values/item.h"

namespace xqp {

/*______________________________________________________________________
|  
|	base class for the expression tree node hierarchy
|_______________________________________________________________________*/

class expr : public rcobject
{
public:
	typedef rchandle<expr> expr_t;

protected:
	yy::location loc;

public:
	expr(yy::location const&);
  virtual ~expr() {}

public:
	yy::location get_loc() const { return loc; }

public:
	virtual void accept(expr_visitor&) const = 0;
	virtual std::ostream& put(std::ostream&) const;


/* (some proposed optimizer interface methods:)
public:	
	typedef pair<var_expr*,expr*> substitution;
	typedef std::vector<substitution> subst_list;

public:
	rchandle<expr> clone() const;
	rchandle<expr> clone(subst_list) const;
	void sub(substitution);
	list<var_expr*> variables() const;	// free variables
	list<fo_expr*> functions() const;		// return all function calls
	rchandle<substitution> resolve(expr*, expr*);			// return subst_list expression match
	void resolve(expr*, expr*, rchandle<subst_list>);	// return subst_list expression match
	void traverse(void* (*op) (void*), int flags);
*/

};



/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  XQuery 1.0 productions                                             //
//  [http://www.w3.org/TR/xquery/]                                     //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


// [31] [http://www.w3.org/TR/xquery/#prod-xquery-Expr]

// XXX replace with fo_expr(CONCAT)
class expr_list : public expr
/*______________________________________________________________________
|	::= ExprSingle  ( ","  ExprSingle )*
|_______________________________________________________________________*/
{
protected:
	list<expr_t> elist;

public:
	expr_list(yy::location const&);
	~expr_list();

public:
	void add(expr_t e_h)
		{ elist.push_back(e_h); }
	uint32_t size() const
		{ return elist.size(); }

	list_iterator<expr_t> begin() const
		{ return elist.begin(); }
	list_iterator<expr_t> end() const
		{ return elist.end(); }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};


class qname_expr : public rcobject
{
protected:
	yy::location m_loc;
	std::string m_name;

public:
	qname_expr(yy::location const& loc, std::string const& name)
		: m_loc(loc), m_name(name) {}
	qname_expr(std::string const& name) : m_name(name) {}
	~qname_expr() {}

public:
	std::string name() const { return m_name; }
	std::ostream& put(std::ostream& os) const { return os << m_name; }

};


class var_expr : public expr
/*______________________________________________________________________
| ::= VARNAME  ("in"|":=")  ExprSingle
|     | VARNAME  TypeDeclaration  ("in"|":=")  ExprSingle
|     | VARNAME  PositionalVar  "in"  ExprSingle
|     | VARNAME  TypeDeclaration  PositionalVar  "in"  ExprSingle
|     | VARNAME  FTScoreVar  ("in"|":=")  ExprSingle
|     | VARNAME  TypeDeclaration  FTScoreVar  ("in"|":=")  ExprSingle
|     | VARNAME  PositionalVar  FTScoreVar  "in"  ExprSingle
|     | VARNAME  TypeDeclaration  PositionalVar  FTScoreVar  "in"  ExprSingle
|_______________________________________________________________________*/
{
public:
	enum var_kind {
		for_var,
		let_var,
		pos_var,
		score_var,
		quant_var,
		extern_var,
		assign_var,
		context_var
	};

  rchandle<qname_expr> varname_h;
  expr_t valexpr_h;
	var_kind kind;
  sequence_type_t type;

public:
  var_expr(yy::location const&);
  ~var_expr();

public:
  rchandle<qname_expr> get_varname() const { return varname_h; }
  void set_varname(rchandle<qname_expr> q_h) { varname_h = q_h; }

  expr_t get_valexpr() const { return valexpr_h; }
  void set_valexpr(expr_t e_h) { valexpr_h = e_h; }

	var_kind get_kind() const { return kind; }
	void set_kind(var_kind k) { kind = k; }

  sequence_type_t get_type() const { return type; }
  void set_type(sequence_type_t t) { type = t; }

public:
	static std::string decode_var_kind(enum var_kind);

public:
	void accept(expr_visitor&) const;
  std::ostream& put(std::ostream&) const;

};


// [41] [http://www.w3.org/TR/xquery/#prod-xquery-OrderModifier]

class order_modifier : public rcobject
/*______________________________________________________________________
| ::= ("ascending" | "descending")?
|			("empty" ("greatest" | "least"))?
|			("collation" URILiteral)?
|_______________________________________________________________________*/
{
public:
	dir_spec_t dir;
	static_context::order_empty_mode_t empty_mode;
	std::string collation;

public:
	order_modifier()
	: dir(dir_descending),
		empty_mode(static_context::empty_least),
		collation("")
	{
	}

	~order_modifier() {}

};


// [33] [http://www.w3.org/TR/xquery/#prod-xquery-FLWORExpr]

class forlet_clause : public rcobject
{
public:	// types
	enum forlet_t {
		for_clause,
		let_clause
	};

	typedef rchandle<var_expr> varref_t;
	typedef rchandle<expr> expr_t;

public:	// state
	enum forlet_t type;
	varref_t var_h;
	varref_t pos_var_h;
	varref_t score_var_h;
	expr_t expr_h;

public:	// ctor,dtor
	forlet_clause(
		enum forlet_t _type,
		varref_t _var_h,
		varref_t _pos_var_h,
		varref_t _score_var_h,
		expr_t _expr_h);

	~forlet_clause();

public:	// accessors
	enum forlet_t get_type() const { return type; }
	varref_t get_var() const { return var_h; }
	varref_t get_pos_var() const { return pos_var_h; }
	varref_t get_score_var() const { return score_var_h; }
	expr_t get_expr() const { return expr_h; }

	void set_type(enum forlet_t v) { type = v; }
	void set_var(varref_t v) { var_h = v; }
	void set_pos_var(varref_t v) { pos_var_h = v; }
	void set_score_var(varref_t v) { score_var_h = v; }
	void set_expr(expr_t v) { expr_h = v; }

public:
	std::ostream& put(ostream&) const;
	
};


class flwor_expr : public expr
/*______________________________________________________________________
|	::= ForLetClauseList  RETURN  ExprSingle
|			|	ForLetClauseList  WhereClause  RETURN  ExprSingle
|			|	ForLetClauseList  OrderByClause  RETURN  ExprSingle
|			|	ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
|_______________________________________________________________________*/
{
public:	// types
	typedef rchandle<forlet_clause> forletref_t;
	typedef rchandle<order_modifier> orderref_t;
	typedef std::pair<expr_t,orderref_t> orderspec_t;

protected:	// state
	std::vector<forletref_t> clause_v;
	std::vector<orderspec_t> orderspec_v;
	expr_t where_h;
	expr_t retval_h;

public:	// ctor,dtor
	flwor_expr(yy::location const&);
	~flwor_expr();

public:	// accessors
	void add(forletref_t v) { clause_v.push_back(v); } 
	uint32_t forlet_count() const { return clause_v.size(); }

	forletref_t const& operator[](int i) const { return clause_v[i]; }
	forletref_t & operator[](int i) { return clause_v[i]; }

	std::vector<forletref_t>::const_iterator clause_begin() const
		{ return clause_v.begin(); }
	std::vector<forletref_t>::const_iterator clause_end() const
		{ return clause_v.end(); }

	void add(orderspec_t const& v)
		{ orderspec_v.push_back(v); } 

	uint32_t orderspec_count() const
		{ return orderspec_v.size(); }

	orderspec_t & orderspec_at(int i)
		{ return orderspec_v[i]; }
	orderspec_t const& orderspec_at(int i) const
		{ return orderspec_v[i]; }

	std::vector<orderspec_t>::const_iterator orderspec_begin() const
		{ return orderspec_v.begin(); }
	std::vector<orderspec_t>::const_iterator orderspec_end() const
		{ return orderspec_v.end(); }

	expr_t get_where() const { return where_h; }
	void set_where(expr_t e_h) { where_h = e_h; }

	expr_t get_retval() const { return retval_h; }
	void set_retval(expr_t e_h) { retval_h = e_h; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};


// [42] [http://www.w3.org/TR/xquery/#prod-xquery-QuantifiedExpr]
class quantified_expr : public expr
/*______________________________________________________________________
|	::= (<"some" "$">|<"every" "$">) QVarInDeclList "satisfies" ExprSingle
|_______________________________________________________________________*/
{
public:
	typedef rchandle<var_expr> varref_t;

protected:
	enum quantification_mode_t qmode;
	std::vector<varref_t> var_v;
	expr_t sat_expr_h;

public:
	quantified_expr(
		yy::location const&,
		enum quantification_mode_t);
	~quantified_expr();

public:
	void add(varref_t const& var_h)
		{ var_v.push_back(var_h); } 
	uint32_t var_count() const
		{ return var_v.size(); }

	varref_t & operator[](int i)
		{ return var_v[i]; }
	varref_t const& operator[](int i) const
		{ return var_v[i]; }

	std::vector<varref_t>::const_iterator begin() const
		{ return var_v.begin(); }
	std::vector<varref_t>::const_iterator end() const
		{ return var_v.end(); }

public:
	enum quantification_mode_t get_qmode() const { return qmode; }
	void set_qmode(enum quantification_mode_t _qmode) { qmode = _qmode; }

	expr_t get_sat_expr() const { return sat_expr_h; }
	void set_sat_expr(expr_t e_h) { sat_expr_h = e_h; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};


// [43] [http://www.w3.org/TR/xquery/#prod-xquery-TypeswitchExpr]

class case_clause : public rcobject
{
public:
	typedef rchandle<expr> expr_t;
	typedef rchandle<var_expr> varref_t;

public:
	varref_t var_h;
	expr_t case_expr_h;
	sequence_type_t type;

public:
	case_clause() : var_h(NULL), case_expr_h(NULL), type(xs_untypedValue) { }
	~case_clause() {}

};


class typeswitch_expr : public expr
/*______________________________________________________________________
|	::= TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
|			|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT 
|					DOLLAR  VARNAME  RETURN  ExprSingle
|_______________________________________________________________________*/
{
public:
	typedef rchandle<var_expr> varref_t;
	typedef rchandle<case_clause> clauseref_t;

protected:
	expr_t switch_expr_h;
	std::vector<clauseref_t> case_clause_hv;
	varref_t  default_var_h;
	expr_t default_clause_h;

public:
	typeswitch_expr(yy::location const&);
	~typeswitch_expr();

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

	uint32_t clause_count() const
		{ return case_clause_hv.size(); }

	clauseref_t & operator[](int i)
		{ return case_clause_hv[i]; }
	clauseref_t const& operator[](int i) const
		{ return case_clause_hv[i]; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [45] [http://www.w3.org/TR/xquery/#prod-xquery-IfExpr]
class if_expr : public expr
/*______________________________________________________________________
|	::= <"if" "("> Expr ")" "then" ExprSingle "else" ExprSingle
|_______________________________________________________________________*/
{
protected:
	expr_t cond_expr_h;
	expr_t then_expr_h;
	expr_t else_expr_h;

public:
	if_expr(
		yy::location const&,
		expr_t,
		expr_t,
		expr_t);

	if_expr(
		yy::location const&);

	~if_expr();

public:
	expr_t get_cond_expr() const { return cond_expr_h; }
	void set_cond_expr(expr_t e_h) { cond_expr_h = e_h; }

	expr_t get_then_expr() const { return then_expr_h; }
	void set_then_expr(expr_t e_h) { then_expr_h = e_h; }

	expr_t get_else_expr() const { return else_expr_h; }
	void set_else_expr(expr_t e_h) { else_expr_h = e_h; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};


////////////////////////////////
//	first-order expressions
////////////////////////////////


// [46] [http://www.w3.org/TR/xquery/#prod-xquery-OrExpr]
// [47] [http://www.w3.org/TR/xquery/#prod-xquery-AndExpr]
// [48] [http://www.w3.org/TR/xquery/#prod-xquery-ComparisonExpr]


class fo_expr : public expr
{
protected:
	std::vector<expr_t> argv;
	const function* func;

public:
	fo_expr(yy::location const&);
	~fo_expr();

public:
	void add(expr_t e_h) { argv.push_back(e_h); }
	uint32_t size() const { return argv.size(); }
	expr_t& operator[](int i) { return argv[i]; }
	const expr_t& operator[](int i) const { return argv[i]; }
	std::vector<expr_t>::const_iterator begin() const { return argv.begin(); }
	std::vector<expr_t>::const_iterator end() const { return argv.end(); }
	std::vector<expr_t>& get_argv() { return argv; }

public:
	const function* get_func() const { return func; }
	void set_func(function const* _func) { func = _func; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};





// [48a] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTContainsExpr]
class ft_select_expr;

class ft_contains_expr : public expr
/*______________________________________________________________________
|	::= RangeExpr ("ftcontains" FTSelection FTIgnoreOption?)?
|_______________________________________________________________________*/
{
protected:
	expr_t range_h;
	expr_t ft_select_h;
	expr_t ft_ignore_h;

public:
	ft_contains_expr(
		yy::location const&,
		expr_t,
		expr_t,
		expr_t);

	~ft_contains_expr();

public:
	expr_t get_range() const { return range_h; }
	expr_t get_ft_select() const { return ft_select_h; }
	expr_t get_ignore() const { return ft_ignore_h; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [49] [http://www.w3.org/TR/xquery/#prod-xquery-RangeExpr]
// [50] [http://www.w3.org/TR/xquery/#prod-xquery-AdditiveExpr]
// [51] [http://www.w3.org/TR/xquery/#prod-xquery-MultiplicativeExpr]
// [52] [http://www.w3.org/TR/xquery/#prod-xquery-UnionExpr]
// [53] [http://www.w3.org/TR/xquery/#prod-xquery-IntersectExceptExpr]
// [54] [http://www.w3.org/TR/xquery/#prod-xquery-InstanceofExpr]

class instanceof_expr : public expr
/*______________________________________________________________________
|	::= TreatExpr ("instance" "of" SequenceType)?
|_______________________________________________________________________*/
{
protected:
	expr_t expr_h;
	sequence_type_t type;

public:
	instanceof_expr(
		yy::location const&,
		expr_t,
		sequence_type_t);

	~instanceof_expr();

public:
	expr_t get_expr() const { return expr_h; }
	sequence_type_t get_type() const { return type; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [55] [http://www.w3.org/TR/xquery/#prod-xquery-TreatExpr]
class treat_expr : public expr
/*______________________________________________________________________
|	::= CastableExpr ("treat" "as" SequenceType)?
|_______________________________________________________________________*/
{
protected:
	expr_t expr_h;
	sequence_type_t type;

public:
	treat_expr(
		yy::location const&,
		expr_t,
		sequence_type_t);

	~treat_expr();

public:
	expr_t get_expr() const { return expr_h; }
	sequence_type_t get_type() const { return type; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [56] [http://www.w3.org/TR/xquery/#prod-xquery-CastableExpr]
class castable_expr : public expr
/*______________________________________________________________________
|	::= CastExpr ("castable" "as" SingleType)?
|_______________________________________________________________________*/
{
protected:
	expr_t expr_h;
	sequence_type_t type;

public:
	castable_expr(
		yy::location const&,
		expr_t,
		sequence_type_t);
	~castable_expr();

public:
	expr_t get_cast_expr() const { return expr_h; }
	sequence_type_t get_type() const { return type; }
	bool is_optional() const { return (type&ARITY_MASK)==OPT_ITEM_ARITY; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [57] [http://www.w3.org/TR/xquery/#prod-xquery-CastExpr]
class cast_expr : public expr
/*______________________________________________________________________
|	::= UnaryExpr ("cast" "as" SingleType)?
|_______________________________________________________________________*/
{
protected:
	expr_t expr_h;
	sequence_type_t type;

public:
	cast_expr(
		yy::location const&,
		expr_t,
		sequence_type_t);
	~cast_expr();

public:
	expr_t get_unary_expr() const { return expr_h; }
	sequence_type_t get_type() const { return type; }
	bool is_optional() const { return (type&ARITY_MASK)==OPT_ITEM_ARITY; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [58] [http://www.w3.org/TR/xquery/#prod-xquery-UnaryExpr]
class unary_expr : public expr
/*______________________________________________________________________
|	::= ("+"|"-")* ( ValidateExpr | PathExpr | ExtensionExpr )
|_______________________________________________________________________*/
{
protected:
	bool neg_b;
	expr_t expr_h;

public:
	unary_expr(
		yy::location const&,
		bool neg_b,
		expr_t);
	~unary_expr();

public:
	bool is_negative() const { return neg_b; }
	expr_t get_expr() const { return expr_h; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [63] [http://www.w3.org/TR/xquery/#prod-xquery-ValidateExpr]
class validate_expr : public expr
/*______________________________________________________________________
|	::= "validate" ValidationMode? "{" Expr "}"
|_______________________________________________________________________*/
{
protected:
	enum validation_mode_t valmode;
	expr_t expr_h;

public:
	validate_expr(
		yy::location const&,
		enum validation_mode_t,
		expr_t);
	~validate_expr();

public:
	expr_t get_expr() const { return expr_h; }
	enum validation_mode_t get_valmode() const { return valmode; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [65] [http://www.w3.org/TR/xquery/#prod-xquery-ExtensionExpr]

struct pragma : public rcobject
{
	rchandle<qname_expr> name_h;
	std::string content;

	pragma(rchandle<qname_expr> _name_h, std::string const& _content)
	: name_h(_name_h), content(_content) {}
	~pragma() {}
};


class extension_expr : public expr
/*______________________________________________________________________
|	::= PragmaList "{" Expr? "}"
|_______________________________________________________________________*/
{
protected:
	rchandle<pragma> pragma_h;
	expr_t expr_h;

public:
	extension_expr(
		yy::location const&);
	extension_expr(
		yy::location const&,
		expr_t);
	~extension_expr();

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
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [69] [http://www.w3.org/TR/xquery/#prod-xquery-RelativePathExpr]

// p:l == (match "p:l" (children $dot))
// p1:l1/p2:l2 == (for ( ($x (match "p1:l1" (children $dot))) )
//                     (match "p2:l2" (children $x)))
// 

// XXX remove this, replace with primitive_path_expr

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
	list<expr_t> step_hv;

public:
	relpath_expr(yy::location const&);
	~relpath_expr();

public:
	void add_back(expr_t step_h)
		{ step_hv.push_back(step_h); }
	void add_front(expr_t step_h)
		{ step_hv.push_front(step_h); }
	uint32_t size() const
		{ return step_hv.size(); }

	list_iterator<expr_t> begin() const
		{ return step_hv.begin(); }
	list_iterator<expr_t> end() const
		{ return step_hv.end(); }

	expr_t& operator[](int n)
		{ return step_hv[n]; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};


// [123] KindTest 
/*______________________________________________________________________
|	KindTest ::= DocumentTest | ElementTest | AttributeTest
|								| SchemaElementTest | SchemaAttributeTest
|								| PITest | CommentTest | TextTest | AnyKindTest
|_______________________________________________________________________*/
class match_expr : public expr
{
public:
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
		no_wild,
		all_wild,
		prefix_wild,
		name_wild
	};

protected:
	test_t test;
	test_t docnode_test;
	wild_t wild;
	rchandle<qname_expr> name_h;
	rchandle<qname_expr> typename_h;

public:
	match_expr(yy::location const&);
	~match_expr();

public:
	test_t get_test() const { return test; }
	test_t get_docnode_test() const { return docnode_test; }
	wild_t get_wild() const { return wild; }
	rchandle<qname_expr> get_name() const { return name_h; }
	rchandle<qname_expr> get_typename() const { return typename_h; }

	void set_test(enum test_t v) { test = v; }
	void set_docnode_test(enum test_t v) { docnode_test = v; }
	void set_wild(enum wild_t v) { wild = v; }
	void set_name(rchandle<qname_expr> v_h) { name_h = v_h; }
	void set_typename(rchandle<qname_expr> v_h) { typename_h = v_h; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};




// [70] [http://www.w3.org/TR/xquery/#prod-xquery-StepExpr]
/*______________________________________________________________________
|	StepExpr ::= AxisStep  |  FilterExpr
|_______________________________________________________________________*/


// XXX Add: primitive_path_expr - for $x/a/b/c/d/e

// [71] [http://www.w3.org/TR/xquery/#prod-xquery-AxisStep]

// XXX Move this to fo_expr: one function for each axis.

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
		descendant_or_self,
		ancestor,
		ancestor_or_self,
		following_sibling,
		following,
		preceding_sibling,
		preceding,
		attribute
	};

protected:
	axis_t axis;
	rchandle<match_expr> test_h;
	rchandle<qname_expr> name_h;
	rchandle<qname_expr> typename_h;
	std::vector<expr_t> pred_hv;

public:
	axis_step_expr(yy::location const&);
	~axis_step_expr();

public:
	axis_t get_axis() const { return axis; }
	void set_axis(axis_t v) { axis = v; }

	rchandle<match_expr> get_test() const { return test_h; }
	void set_test(rchandle<match_expr> v) { test_h = v; }

public:
	void add_pred(expr_t e_h) { pred_hv.push_back(e_h); }
	uint32_t size() const { return pred_hv.size(); }
	expr_t & operator[](int i) { return pred_hv[i]; }
	expr_t const& operator[](int i) const { return pred_hv[i]; }

	std::vector<expr_t>::const_iterator begin() const
		{ return pred_hv.begin(); }
	std::vector<expr_t>::const_iterator end() const
		{ return pred_hv.end(); }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [84] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]
/*______________________________________________________________________
|	primary_expr ::=
|       Literal
|			|	VarRef
|			|	ParenthesizedExpr
|			|	ContextItemExpr
|			|	FunctionCall
|			|	Constructor
|			|	OrderedExpr
|			|	UnorderedExpr
|_______________________________________________________________________*/



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
		lit_double,
		lit_bool
	};

protected:
	enum literal_type_t type;
	std::string sval;
	union {
		//uint32_t sref;
		int ival;
		decimal decval;
		double dval;
		bool bval;
	};

public:
	//literal_expr(yy::location const&, uint32_t sref, bool);
	literal_expr(yy::location const&, const std::string& sval);
	literal_expr(yy::location const&, int);
	literal_expr(yy::location const&, decimal);
	literal_expr(yy::location const&, double);
	literal_expr(yy::location const&, bool);
	~literal_expr();

public:
	enum literal_type_t get_type() const { return type; }
	//uint32_t get_sref() const { return sref; }
	std::string get_sval() const { return sval; }
	int get_ival() const { return ival; }
	decimal get_decval() const { return decval; }
	double get_dval() const { return dval; }
	bool get_bval() const { return bval; }

public:
	static std::string decode_type(enum literal_type_t t);
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [87] [http://www.w3.org/TR/xquery/#prod-xquery-VarRef]
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
	expr_t expr_h;

public:
	order_expr(
		yy::location const&,
		order_type_t,
		expr_t);
	~order_expr();

public:
	order_type_t get_type() const { return type; }
	expr_t get_expr() const { return expr_h; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [93] [http://www.w3.org/TR/xquery/#prod-xquery-FunctionCall]
/*______________________________________________________________________
|	::= QNAME  LPAR  ArgList  RPAR 	
|																	gn:parensXQ
|			 														gn:reserved-function-namesXQ 
|_______________________________________________________________________*/



// [110] [http://www.w3.org/TR/xquery/#prod-xquery-CompDocConstructor]
class doc_expr : public expr
/*______________________________________________________________________
|	::= DOCUMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	expr_t docuri_h;

public:
	doc_expr(
		yy::location const&,
		expr_t);
	~doc_expr();

public:
	expr_t get_docuri() const { return docuri_h; }

public:
	void accept(expr_visitor&) const;
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
	rchandle<qname_expr> qname_h;
	expr_t qname_expr_h;
	expr_t content_expr_h;
	std::vector<nsbinding> nsb_v;

public:
	elem_expr(
		yy::location const&,
		rchandle<qname_expr>,
		expr_t);
	elem_expr(
		yy::location const&,
		expr_t,
		expr_t);
	~elem_expr();

public:
	rchandle<qname_expr> get_qname() const { return qname_h; }
	expr_t get_qname_expr() const { return qname_expr_h; }
	expr_t get_content_expr() const { return content_expr_h; }

public:
	void add(nsbinding const& nsb)
		{ nsb_v.push_back(nsb); }
	uint32_t nsbinding_count() const
		{ return nsb_v.size(); }

	std::vector<nsbinding>::const_iterator ns_begin() const
		{ return nsb_v.begin(); }
	std::vector<nsbinding>::const_iterator ns_end() const
		{ return nsb_v.end(); }

public:
	void accept(expr_visitor&) const;
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
	rchandle<qname_expr> qname_h;
	expr_t qname_expr_h;
	expr_t val_expr_h;

public:
	attr_expr(
		yy::location const&,
		rchandle<qname_expr>,
		expr_t);
	attr_expr(
		yy::location const&,
		expr_t,
		expr_t);
	~attr_expr();

public:
	rchandle<qname_expr> get_qname() const { return qname_h; }
	expr_t get_qname_expr() const { return qname_expr_h; }
	expr_t get_val_expr() const { return val_expr_h; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompTextConstructor]
class text_expr : public expr
/*______________________________________________________________________
|	::= TEXT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	expr_t text_expr_h;

public:
	text_expr(
		yy::location const&,
		expr_t);
	~text_expr();

public:
	expr_t get_text_expr() const { return text_expr_h; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



// [115] [http://www.w3.org/TR/xquery/#prod-xquery-CompCommentConstructor]
class comment_expr : public expr
/*______________________________________________________________________
|	::= COMMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	expr_t comment_expr_h;

public:
	comment_expr(
		yy::location const&,
		expr_t);
	~comment_expr();

public:
	expr_t get_comment_expr() const { return comment_expr_h; }

public:
	void accept(expr_visitor&) const;
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
	expr_t target_expr_h;
	expr_t content_expr_h;

public:
	pi_expr(
		yy::location const&,
		std::string target,
		expr_t);
	pi_expr(
		yy::location const&,
		expr_t,
		expr_t);
	~pi_expr();

public:
	std::string get_target() const { return target; }
	expr_t get_target_expr() const { return target_expr_h; }
	expr_t get_content_expr() const { return content_expr_h; }

public:
	void accept(expr_visitor&) const;
	std::ostream& put(std::ostream&) const;

};



}	/* namespace xqp */
#endif	/*  XQP_EXPR_H */

