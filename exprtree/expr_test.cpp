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
#include "../functions/signature.h"
#include "../functions/function_impl.h"
#include "../parser/location.hh"
#include "../parser/symbol_table.h"
#include "../types/base_types.h"
#include "../types/xs_primitive_types.h"
#include "../types/sequence_type.h"
#include "../util/xqp_exception.h"
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

	try {

/*...........................................
	: literal expresions                      :
	:.........................................:
*/
	cout << "\n>>>literal_expr\n";
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


/*...........................................
	: variables                               :
	:.........................................:
*/
	cout << "\n>>>var_expr\n";
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

	var1.put(cout,ctx) << endl;
	var2.put(cout,ctx) << endl;
	var3.put(cout,ctx) << endl;


/*...........................................
	: expression list                         :
	:.........................................:
*/
	cout << "\n>>>expr_list\n";
	expr_list exlist1(loc,ctx);
	exlist1.add(&var1);
	exlist1.add(&var2);
	exlist1.add(&var3);
	exlist1.put(cout,ctx);


/*...........................................
	: constructors                            :
	:.........................................:
*/
	cout << "\n>>>text_expr\n";
	text_expr text1(loc, ctx, &lit4);
	text_expr text2(loc, ctx, &lit5);
	text_expr text3(loc, ctx, &lit6);

	text1.put(cout,ctx) << endl;
	text2.put(cout,ctx) << endl;
	text3.put(cout,ctx) << endl;

	cout << "\n>>>comment_expr\n";
	comment_expr comment1(loc, ctx, &lit1);
	comment_expr comment2(loc, ctx, &lit2);
	comment_expr comment3(loc, ctx, &lit3);

	comment1.put(cout,ctx) << endl;
	comment2.put(cout,ctx) << endl;
	comment3.put(cout,ctx) << endl;

	cout << "\n>>>pi_expr\n";
	pi_expr pi1(loc, ctx, "?PI1", &lit1);
	pi_expr pi2(loc, ctx, "?PI2", &lit2);
	pi_expr pi3(loc, ctx, "?PI3", &lit3);

	pi1.put(cout,ctx) << endl;
	pi2.put(cout,ctx) << endl;
	pi3.put(cout,ctx) << endl;

	cout << "\n>>>attr_expr\n";
	attr_expr attr1(loc, ctx, new QName(QName::qn_attr,"attr1"), &lit1);
	attr_expr attr2(loc, ctx, new QName(QName::qn_attr,"attr2"), &lit2);
	attr_expr attr3(loc, ctx, new QName(QName::qn_attr,"attr3"), &lit3);

	attr1.put(cout,ctx) << endl;
	attr2.put(cout,ctx) << endl;
	attr3.put(cout,ctx) << endl;

	expr_list exlist2(loc,ctx);
	exlist2.add(&attr1);
	exlist2.add(&attr2);
	exlist2.add(&attr3);
	exlist2.add(&text1);
	exlist2.add(&text2);
	exlist2.add(&text3);

	cout << "\n>>>elem_expr\n";
	elem_expr elem1(loc, ctx, new QName(QName::qn_elem,"elem1"), &exlist2);
	elem_expr::nsbinding ns1("pre1","http://a1.b1.c1");
	elem_expr::nsbinding ns2("pre2","http://a2.b2.c2");
	elem1.add(ns1);
	elem1.add(ns2);
	elem1.put(cout,ctx) << endl;

	elem_expr elem2(loc, ctx, new QName(QName::qn_elem,"elem2"), &exlist2);
	elem2.add(ns1);
	elem2.add(ns2);
	elem2.put(cout,ctx) << endl;

	cout << "\n>>>doc_expr\n";
	doc_expr doc1(loc,ctx,&elem1);
	doc1.put(cout,ctx) << endl;


/*...........................................
	: function call                           :
	:.........................................:
*/
	cout << "\n>>>funcall_expr\n";
	funcall_expr fun1(loc, ctx, new QName(QName::qn_func,"fun1"));
	fun1.add_arg(&lit1);
	fun1.add_arg(&lit2);
	fun1.add_arg(&lit3);
	fun1.put(cout,ctx) << endl;
	for (unsigned i=0; i<fun1.arg_count(); ++i) {
		cout << "arg[" << i << "] = ";
		fun1[i]->put(cout,ctx) << endl;
	}


/*...........................................
	: typeswitch expression                   :
	:.........................................:
*/
	cout << "\n>>>typeswitch_expr\n";
	typeswitch_expr sw1(loc,ctx);
	sw1.set_switch_expr(&elem1);
	sw1.set_default_varname(&var1);
	sw1.set_default_clause(&elem1);

	case_clause cc1;
	cc1.var_h = &var2;
	cc1.case_expr_h = &lit1;
	cc1.seqtype = sequence_type::ANY_SEQUENCE;
	sw1.add_clause(cc1);

	case_clause cc2;
	cc2.var_h = &var3;
	cc2.case_expr_h = &lit2;
	cc2.seqtype = sequence_type::ANY_SEQUENCE;
	sw1.add_clause(cc2);

	sw1.put(cout,ctx);


/*...........................................
	: conditional expression                  :
	:.........................................:
*/
	cout << "\n>>>if_expr\n";
	if_expr if1(loc, ctx, &lit1, &lit2, &lit3);
	if1.put(cout,ctx);

	int a=1; 
	cout << "a = " << a << endl;


/*...........................................
	: cast-related expressions                :
	:.........................................:
*/
	cout << "\n>>>instanceof_expr\n";
	instanceof_expr inst1(loc,ctx,&lit4,sequence_type::SINGLE_ITEM);
	inst1.put(cout,ctx) << endl;

	cout << "\n>>>treat_expr\n";
	treat_expr treat1(loc, ctx, &lit5, sequence_type::SINGLE_INTEGER);
	treat1.put(cout,ctx) << endl;

	cout << "\n>>>castable_expr\n";
	castable_expr castable1(loc, ctx, &lit6, single_type_t(atomic_type(),true));
	castable1.put(cout,ctx) << endl;

	cout << "\n>>>cast_expr\n";
	cast_expr cast1(loc, ctx, &lit1, single_type_t(atomic_type(),true));
	cast1.put(cout,ctx) << endl;


/*...........................................
	: validate expression                     :
	:.........................................:
*/
	cout << "\n>>>validate_expr\n";
	validate_expr val1(loc, ctx, val_strict, &elem1);
	val1.put(cout,ctx) << endl;


/*...........................................
	: extension expressions                   :
	:.........................................:
*/
/*
	cout << "\n>>>extension_expr\n";
	extension_expr ext1(loc,ctx);
	ext1.add(new pragma(new QName(QName::qn_prag,"prag1"), "content1"));
	ext1.add(new pragma(new QName(QName::qn_prag,"prag2"), "content2"));
	ext1.put(cout,ctx) << endl;
*/

/*...........................................
	: path expressions                        :
	:.........................................:
*/
	cout << "\n>>>axis_step_expr\n";
	axis_step_expr ax1(loc,ctx);
	ax1.set_axis(axis_step_expr::child);
	ax1.set_test(axis_step_expr::name_test);
	ax1.set_name(new QName(QName::qn_elem,"elem1"));
	ax1.add_pred(&elem1);
	ax1.put(cout,ctx) << endl;

	axis_step_expr ax2(loc,ctx);
	ax2.set_axis(axis_step_expr::child);
	ax2.set_test(axis_step_expr::name_test);
	ax2.set_name(new QName(QName::qn_elem,"elem2"));
	ax2.add_pred(&elem2);
	ax2.put(cout,ctx) << endl;

	relpath_expr path1(loc,ctx);
	path1.add(&ax1);
	path1.add(&ax2);
	path1.put(cout,ctx) << endl;


/*...........................................
	: quantified expressions                  :
	:.........................................:
*/
	cout << "\n>>>quantified_expr\n";
	quantified_expr quant1(loc,ctx,quant_some);
	quant1.add(&var1);
	quant1.set_sat_expr(&elem1);
	quant1.put(cout,ctx) << endl;

	quantified_expr quant2(loc,ctx,quant_some);
	quant2.add(&var2);
	quant2.set_sat_expr(&elem2);
	quant2.put(cout,ctx) << endl;


/*...........................................
	: FO expressions                          :
	:.........................................:
*/
	cout << "\n>>>fo_expr\n";
	signature sig1(new QName(QName::qn_func,"func1"));
	sig1.add_arg(sequence_type::ANY_SEQUENCE);
	sig1.add_arg(sequence_type::ANY_SEQUENCE);
	function_impl func1(sig1);
	fo_expr fo1(loc, ctx);
	fo1.add(&lit1);
	fo1.add(&lit2);
	fo1.set_func(&func1);
	fo1.put(cout,ctx) << endl;


/*...........................................
	: FLWOR expressions                       :
	:.........................................:
*/
	cout << "\n>>>flwor_expr\n";
	flwor_expr flwor1(loc,ctx);
	forlet_clause flc1(forlet_clause::for_clause,&var1,NULL,NULL,&elem1);
	forlet_clause flc2(forlet_clause::let_clause,&var2,NULL,NULL,&elem2);
	flwor1.add(&flc1);
	flwor1.add(&flc2);
	flwor1.set_where(&var1);
	flwor1.set_retval(&var2);
	flwor1.put(cout,ctx) << endl;


	} catch (xqp_exception& e) {
		cout << "Application exception: " << e.get_msg() << endl;
	} catch (exception& e) {
		cout << "C++ exception: " << e.what() << endl;
	} catch (...) {
		cout << "unrecognized exception" << endl;
	}


};







/*
class ft_contains_expr : public expr
	ft_contains_expr(loc, ctx, exprref_t, exprref_t, exprref_t);
	exprref_t get_range() const { return range_h; }
	exprref_t get_ft_select() const { return ft_select_h; }
	exprref_t get_ignore() const { return ft_ignore_h; }
	virtual std::ostream& put(std::ostream&, ctx) const;
};

class unary_expr : public expr
	unary_expr(loc, ctx, bool neg_b, exprref_t);
	bool is_negative() const { return neg_b; }
	exprref_t get_expr() const { return expr_h; }
	virtual std::ostream& put(std::ostream&,ctx) const;
};

class order_expr : public expr
	enum order_type_t { ordered, unordered };
	order_expr(loc, ctx, order_type_t, exprref_t);
	order_type_t get_type() const { return type; }
	exprref_t get_expr() const { return expr_h; }
	std::ostream& put(std::ostream&, ctx) const;
};
*/

