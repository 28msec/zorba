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

int main(int argc, char* argv[])
{
	//typedef rchandle<expr> exprref_t;
	yy::location loc;
	context ctx;
	symbol_table symtab;

	uint32_t i1 = symtab.put("symbol1", 7);
	uint32_t i2 = symtab.put("symbol2", 7);
	uint32_t i3 = symtab.put("symbol3", 7);

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

};



/*
class expr_list : public expr
{
	expr_list(loc const&,ctx);
	void add(exprref_t e_h)
	uint32_t size() const
	exprref_t & operator[](int i)
	exprref_t const& operator[](int i) const
	std::vector<exprref_t>::const_iterator begin() const
	std::vector<exprref_t>::const_iterator end() const
	std::ostream& put(std::ostream&,ctx) const;

};


class var_expr : public expr
{
public:
	enum var_kind { for_var, let_var, pos_var, score_var, quant_var, extern_var, assign_var, };
  var_expr(loc const&,ctx);
  rchandle<QName> get_varname() const { return varname_h; }
  void set_varname(rchandle<QName> q_h) { varname_h = q_h; }
  exprref_t get_valexpr() const { return valexpr_h; }
  void set_valexpr(exprref_t e_h) { valexpr_h = e_h; }
	var_kind get_kind() const { return kind; }
	void set_kind(var_kind k) { kind = k; }
  rchandle<sequence_type> get_type() const { return type_h; }
  void set_type(rchandle<sequence_type> const& t_h) { type_h = t_h; }
  std::ostream& put(std::ostream&,ctx) const;
};


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


class cons_expr : public expr
	cons_expr(loc const&, ctx);
	virtual std::ostream& put(std::ostream&, ctx) const;
};


class doc_expr : public expr
	doc_expr(loc, ctx, exprref_t);
	exprref_t get_docuri() const { return docuri_h; }
	std::ostream& put(std::ostream&, ctx) const;
};


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
};


class attr_expr : public expr
	attr_expr(loc, ctx, rchandle<QName>, exprref_t);
	attr_expr(loc, ctx, exprref_t, exprref_t);
	rchandle<QName> get_qname() const { return qname_h; }
	exprref_t get_qname_expr() const { return qname_expr_h; }
	exprref_t get_val_expr() const { return val_expr_h; }
	std::ostream& put(std::ostream&, ctx) const;
};


class text_expr : public expr
	text_expr(loc, ctx, exprref_t);
	exprref_t get_text_expr() const { return text_expr_h; }
	std::ostream& put(std::ostream&, ctx) const;
};


class comment_expr : public expr
	comment_expr(loc, ctx, exprref_t);
	exprref_t get_comment_expr() const { return comment_expr_h; }
	std::ostream& put(std::ostream&, ctx) const;
};


class pi_expr : public expr
	pi_expr(loc, ctx, std::string target, exprref_t);
	pi_expr(loc, ctx, exprref_t, exprref_t);
	std::string get_target() const { return target; }
	exprref_t get_target_expr() const { return target_expr_h; }
	exprref_t get_content_expr() const { return content_expr_h; }
	std::ostream& put(std::ostream&, ctx) const;
};
*/


