/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: expr_test.cpp,v 1.1.1.1 2006/11/06 08:42:18 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR FOundation.
 *
 *	Author: Paul Pedersen
 */

#include "expr.h"
#include "../context/context.h"
#include "../parser/location.hh"
#include "../parser/symbol_table.h"
#include "../types/base_types.h"
#include "../types/xs_primitive_types.h"
#include "../types/sequence_type.h"
#include <iostream>

/*
...........................................
:                                         :
: expression tree unit test module        :
:                                         :
:                                         :
:                                         :
:.........................................:
*/

using namespace std;
using namespace xqp;

typedef rchandle<expr> exprref_t;

int main(int argc, char* argv[])
{
	//typedef rchandle<expr> exprref_t;
	yy::location loc;
	context ctx;
	symbol_table symtab;

	uint32_t i1 = symtab.put("symbol1", 7);
	uint32_t i2 = symtab.put("symbol2", 7);
	uint32_t i3 = symtab.put("symbol3", 7);

/*
	...........................................
	: literal expresions                      :
	:.........................................:
*/
	literal_expr lit1(loc, ctx, i1);
	literal_expr lit2(loc, ctx, i2);
	literal_expr lit3(loc, ctx, i3);
	literal_expr lit4(loc, ctx, 123);
	literal_expr lit5(loc, ctx, 123456);
	literal_expr lit6(loc, ctx, 123.456);

	cout << "lit1 [" << literal_expr::decode_type(lit1.get_type()) << "] = ";
	lit1.put(cout,ctx) << " : " << symtab.get(lit1.get_sref()) << endl;
	cout << "lit2 [" << literal_expr::decode_type(lit2.get_type()) << "] = ";
	lit2.put(cout,ctx) << " : " << symtab.get(lit2.get_sref()) << endl;
	cout << "lit3 [" << literal_expr::decode_type(lit3.get_type()) << "] = ";
	lit3.put(cout,ctx) << " : " << symtab.get(lit3.get_sref()) << endl;

	cout << "lit4 [" << literal_expr::decode_type(lit4.get_type()) << "] = ";
	lit4.put(cout,ctx) << endl;
	cout << "lit5 [" << literal_expr::decode_type(lit5.get_type()) << "] = ";
	lit5.put(cout,ctx) << endl;
	cout << "lit6 [" << literal_expr::decode_type(lit6.get_type()) << "] = ";
	lit6.put(cout,ctx) << endl;

/*
	...........................................
	: variables                               :
	:.........................................:
*/
	var_expr var1(loc,ctx);
  var1.set_varname(new QName(QName::qn_var,"var1"));
  var1.set_valexpr(&lit1);
	var1.set_kind(var_expr::for_var);
  var1.set_type(&sequence_type::SINGLE_ATOMIC);

	var_expr var2(loc,ctx);
  var2.set_varname(new QName(QName::qn_var,"var2"));
  var2.set_valexpr(&lit1);
	var2.set_kind(var_expr::let_var);
  var2.set_type(&sequence_type::SINGLE_ATOMIC);

	var_expr var3(loc,ctx);
  var3.set_varname(new QName(QName::qn_var,"var3"));
  var3.set_valexpr(&lit1);
	var3.set_kind(var_expr::pos_var);
  var3.set_type(&sequence_type::SINGLE_ATOMIC);

	cout << "var1 = "; var1.put(cout,ctx) << endl;
	cout << "var2 = "; var2.put(cout,ctx) << endl;
	cout << "var3 = "; var3.put(cout,ctx) << endl;

/*
	...........................................
	: expr list                               :
	:.........................................:
*/
	expr_list exlist1(loc,ctx);
	exlist1.add(&var1);
	exlist1.add(&var2);
	exlist1.add(&var3);
	exlist1.put(cout,ctx);

/*
	...........................................
	: constructors                            :
	:.........................................:
*/
	text_expr text1(loc, ctx, &lit4);
	text_expr text2(loc, ctx, &lit5);
	text_expr text3(loc, ctx, &lit6);

	cout << "text1 = "; text1.put(cout,ctx) << endl;
	cout << "text2 = "; text2.put(cout,ctx) << endl;
	cout << "text3 = "; text3.put(cout,ctx) << endl;

	comment_expr comment1(loc, ctx, &lit1);
	comment_expr comment2(loc, ctx, &lit2);
	comment_expr comment3(loc, ctx, &lit3);

	cout << "comment1 = "; comment1.put(cout,ctx) << endl;
	cout << "comment2 = "; comment2.put(cout,ctx) << endl;
	cout << "comment3 = "; comment3.put(cout,ctx) << endl;

	pi_expr pi1(loc, ctx, "?PI1", &lit1);
	pi_expr pi2(loc, ctx, "?PI2", &lit2);
	pi_expr pi3(loc, ctx, "?PI3", &lit3);

	cout << "pi1 = "; pi1.put(cout,ctx) << endl;
	cout << "pi2 = "; pi2.put(cout,ctx) << endl;
	cout << "pi3 = "; pi3.put(cout,ctx) << endl;

	attr_expr attr1(loc, ctx, new QName(QName::qn_attr,"attr1"), &lit1);
	attr_expr attr2(loc, ctx, new QName(QName::qn_attr,"attr2"), &lit2);
	attr_expr attr3(loc, ctx, new QName(QName::qn_attr,"attr3"), &lit3);

	cout << "attr1 = "; attr1.put(cout,ctx) << endl;
	cout << "attr2 = "; attr2.put(cout,ctx) << endl;
	cout << "attr3 = "; attr3.put(cout,ctx) << endl;

	expr_list exlist2(loc,ctx);
	exlist2.add(&attr1);
	exlist2.add(&attr2);
	exlist2.add(&attr3);
	exlist2.add(&text1);
	exlist2.add(&text2);
	exlist2.add(&text3);

	elem_expr elem1(loc, ctx, new QName(QName::qn_elem,"elem1"), &exlist2);
	cout << "elem1 = "; elem1.put(cout,ctx) << endl;

	doc_expr doc1(loc,ctx,&elem1);
	doc1.put(cout,ctx) << endl;


/*
class elem_expr : public expr
	typedef std::pair<std::string,std::string> nsbinding;
	elem_expr(loc, ctx, rchandle<QName>, exprref_t);
	elem_expr(loc, ctx, exprref_t, exprref_t);
	rchandle<QName> get_qname() const { return qname_h; }
	exprref_t get_qname_expr() const { return qname_expr_h; }
	exprref_t get_content_expr() const { return content_expr_h; }
	void add(nsbinding const& nsb)
	uint32_t nsbinding_count() const
	std::vector<nsbinding>::const_iterator begin() const
	std::vector<nsbinding>::const_iterator end() const
	nsbinding & operator[](int i)
	nsbinding const& operator[](int i) const
	std::ostream& put(std::ostream&, ctx) const;
*/

};



/*

class order_modifier : public rcobject
{
	order_modifier()
};


class flwor_expr : public expr
{
	flwor_expr(loc const&,ctx);
	void add(vartriple_t const& v)
	uint32_t forlet_count() const
	vartriple_t & var_at(int i)
	vartriple_t const& var_at(int i) const
	std::vector<vartriple_t>::const_iterator var_begin() const
	std::vector<vartriple_t>::const_iterator var_end() const
	void add(orderspec_t const& v)
	uint32_t orderspec_count() const
	orderspec_t & orderspec_at(int i)
	orderspec_t const& orderspec_at(int i) const
	std::vector<orderspec_t>::const_iterator orderspec_begin() const
	std::vector<orderspec_t>::const_iterator orderspec_end() const
	exprref_t get_where() const { return where_h; }
	void set_where(exprref_t e_h) { where_h = e_h; }
	exprref_t get_retval() const { return retval_h; }
	void set_retval(exprref_t e_h) { retval_h = e_h; }
	std::ostream& put(std::ostream&,ctx) const;
};


class quantified_expr : public expr
{
	quantified_expr(loc, ctx, enum quantification_mode_t);
	void add(varref_t const& var_h)
	uint32_t var_count() const
	varref_t & operator[](int i)
	varref_t const& operator[](int i) const
	std::vector<varref_t>::const_iterator begin() const
	std::vector<varref_t>::const_iterator end() const
	enum quantification_mode_t get_qmode() const { return qmode; }
	void set_qmode(enum quantification_mode_t _qmode) { qmode = _qmode; }
	exprref_t get_sat_expr() const { return sat_expr_h; }
	void set_sat_expr(exprref_t e_h) { sat_expr_h = e_h; }
	std::ostream& put(std::ostream&,ctx) const;
};


class case_clause : public rcobject
{
	case_clause()
};


class typeswitch_expr : public expr
{
	typeswitch_expr(loc const&, ctx);
	exprref_t get_switch_expr() const
	void set_switch_expr(exprref_t e_h)
	varref_t get_default_varname() const
	void set_default_varname(varref_t const& var_h)
	exprref_t get_default_clause() const
	void set_default_clause(exprref_t const& e_h)
	void add_clause(case_clause cc)
	std::vector<case_clause>::const_iterator begin() const
	std::vector<case_clause>::const_iterator end() const
	uint32_t clause_count() const
	case_clause & operator[](int i)
	case_clause const& operator[](int i) const
	std::ostream& put(std::ostream&,ctx) const;
};


class if_expr : public expr
{
	if_expr(loc, ctx, exprref_t, exprref_t, exprref_t);
	if_expr(loc, ctx);
	exprref_t get_cond_expr() const { return cond_expr_h; }
	void set_cond_expr(exprref_t e_h) { cond_expr_h = e_h; }
	exprref_t get_then_expr() const { return then_expr_h; }
	void set_then_expr(exprref_t e_h) { then_expr_h = e_h; }
	exprref_t get_else_expr() const { return else_expr_h; }
	void set_else_expr(exprref_t e_h) { else_expr_h = e_h; }
	std::ostream& put(std::ostream&,ctx) const;
};


class fo_expr : public expr
{
	fo_expr(loc const&, ctx);
	void add(exprref_t e_h)
	uint32_t size() const
	exprref_t & operator[](int i)
	exprref_t const& operator[](int i) const
	std::vector<exprref_t >::const_iterator begin() const
	std::vector<exprref_t >::const_iterator end() const
	function_impl const* get_func() const { return func; }
	void set_func(function_impl const* _func) { func = _func; }
	virtual std::ostream& put(std::ostream&, ctx) const;
};


class ft_contains_expr : public expr
	ft_contains_expr(loc, ctx, exprref_t, exprref_t, exprref_t);
	exprref_t get_range() const { return range_h; }
	exprref_t get_ft_select() const { return ft_select_h; }
	exprref_t get_ignore() const { return ft_ignore_h; }
	virtual std::ostream& put(std::ostream&, ctx) const;
};


class instanceof_expr : public expr
{
	instanceof_expr(loc, ctx, exprref_t, sequence_type const&);
	exprref_t get_expr() const { return expr_h; }
	sequence_type get_seqtype() const { return seqtype; }
	virtual std::ostream& put(std::ostream&,ctx) const;
};


class treat_expr : public expr
	treat_expr(loc, ctx, exprref_t, sequence_type const&);
	exprref_t get_expr() const { return expr_h; }
	sequence_type get_seqtype() const { return seqtype; }
	virtual std::ostream& put(std::ostream&,ctx) const;
};


class castable_expr : public expr
{
	castable_expr(loc, ctx, exprref_t, single_type_t);
	exprref_t get_cast_expr() const { return expr_h; }
	single_type_t get_type() const { return stype; }
	atomic_type get_atomic_type() const { return stype.first; }
	bool is_optional() const { return stype.second; }
	virtual std::ostream& put(std::ostream&,ctx) const;
};


class cast_expr : public expr
	cast_expr(loc, ctx, exprref_t, single_type_t);
	exprref_t get_unary_expr() const { return expr_h; }
	single_type_t get_type() const { return stype; }
	atomic_type get_atomic_type() const { return stype.first; }
	bool is_optional() const { return stype.second; }
	virtual std::ostream& put(std::ostream&,ctx) const;
};


class unary_expr : public expr
	unary_expr(loc, ctx, bool neg_b, exprref_t);
	bool is_negative() const { return neg_b; }
	exprref_t get_expr() const { return expr_h; }
	virtual std::ostream& put(std::ostream&,ctx) const;
};


class validate_expr : public expr
	validate_expr(loc, ctx, enum validation_mode_t, exprref_t);
	exprref_t get_expr() const { return expr_h; }
	enum validation_mode_t get_valmode() const { return valmode; }
	std::ostream& put(std::ostream&,ctx) const;
};


struct pragma : public rcobject
{
	rchandle<QName> name_h;
	std::string content;
};


class extension_expr : public expr
	extension_expr(loc const&,ctx);
	void add(rchandle<pragma> pragma_h)
	uint32_t size() const
	rchandle<pragma> & operator[](int i)
	rchandle<pragma> const& operator[](int i) const
	std::vector<rchandle<pragma> >::const_iterator begin() const
	std::vector<rchandle<pragma> >::const_iterator end() const
	exprref_t get_expr() const { return expr_h; }
	std::ostream& put(std::ostream&,ctx) const;
};


class relpath_expr : public expr
	relpath_expr(loc const&,ctx);
	void add(exprref_t step_h)
	uint32_t size() const
	std::vector<exprref_t >::const_iterator begin() const
	std::vector<exprref_t >::const_iterator end() const
	exprref_t& operator[](int n)
	exprref_t const& operator[](int n) const
	std::ostream& put(std::ostream&,ctx) const;
};


class step_expr : public expr
	step_expr(loc const&,ctx);
	virtual std::ostream& put(std::ostream&,ctx) const;
};


class axis_step_expr : public expr
	enum axis_t { self, child, parent, descendant, descendant_or_self, ancestor, ancestor_or_self, following_sibling, following, preceding_sibling, preceding, attribute };

	enum test_t { no_test, name_test, doc_test, elem_test, attr_test, xs_elem_test, xs_attr_test, pi_test, comment_test, text_test, anykind_test };

	enum wild_t { no_wild, all_wild, prefix_wild, name_wild };
	axis_step_expr(loc,ctx);
	axis_t get_axis() const { return axis; }
	test_t get_test() const { return test; }
	test_t get_docnode_test() const { return docnode_test; }
	wild_t get_wild() const { return wild; }
	rchandle<QName> get_name() const { return name_h; }
	rchandle<QName> get_typename() const { return typename_h; }
	void set_axis(axis_t v) { axis = v; }
	void set_test(test_t v) { test = v; }
	void set_docnode_test(test_t v) { docnode_test = v; }
	void set_wild(wild_t v) { wild = v; }
	void set_name(rchandle<QName> v_h) { name_h = v_h; }
	void set_typename(rchandle<QName> v_h) { typename_h = v_h; }
	void add(exprref_t e_h)
	uint32_t size() const
	exprref_t & operator[](int i)
	exprref_t const& operator[](int i) const
	std::vector<exprref_t >::const_iterator begin() const
	std::vector<exprref_t >::const_iterator end() const
	virtual std::ostream& put(std::ostream&,ctx) const;
};


class primary_expr : public expr
	primary_expr(loc, ctx);
	virtual std::ostream& put(std::ostream&,ctx) const;
};


class order_expr : public expr
	enum order_type_t { ordered, unordered };
	order_expr(loc, ctx, order_type_t, exprref_t);
	order_type_t get_type() const { return type; }
	exprref_t get_expr() const { return expr_h; }
	std::ostream& put(std::ostream&, ctx) const;
};


class funcall_expr : public expr
	funcall_expr(loc, ctx, rchandle<QName>);
	rchandle<QName> get_fname() const { return fname_h; }
	void add(exprref_t const& arg_h)
	uint32_t arg_count() const
	std::vector<exprref_t >:: const_iterator begin() const
	std::vector<exprref_t >:: const_iterator end() const
	exprref_t & operator[](int i)
	exprref_t const& operator[](int i) const
	std::ostream& put(std::ostream&, ctx) const;
};


*/

