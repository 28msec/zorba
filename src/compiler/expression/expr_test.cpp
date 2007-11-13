/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: expr_test.cpp,v 1.1.1.1 2006/11/06 08:42:18 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR FOundation.
 *
 *	Author: Paul Pedersen
 */

#include "compiler/expression/expr.h"
#include "context/context.h"
#include "functions/signature.h"
#include "functions/function.h"
#include "compiler/parser/location.hh"
#include "compiler/parser/symbol_table.h"
#include "errors/xqp_exception.h"

#include <iostream>

/*
...........................................
:                                         :
: expression tree unit test               :
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

		rchandle<qname_expr> qnv1_h = new qname_expr("var1");
		rchandle<qname_expr> qnv2_h = new qname_expr("var2");
		rchandle<qname_expr> qnv3_h = new qname_expr("var3");
		rchandle<qname_expr> qna1_h = new qname_expr("attr1");
		rchandle<qname_expr> qna2_h = new qname_expr("attr2");
		rchandle<qname_expr> qna3_h = new qname_expr("attr3");
		rchandle<qname_expr> qne1_h = new qname_expr("elem1");
		rchandle<qname_expr> qne2_h = new qname_expr("elem2");
		rchandle<qname_expr> qne3_h = new qname_expr("elem3");
		rchandle<qname_expr> qnf1_h = new qname_expr("func1");
		rchandle<qname_expr> qnp1_h = new qname_expr("prag1");
		rchandle<qname_expr> qnp2_h = new qname_expr("prag1");

	/*...........................................
		: literal expresions                      :
		:.........................................*/
		cout << "\n>>>literal_expr\n";
		rchandle<literal_expr> lit1_h = new literal_expr(loc, i1, true);
		rchandle<literal_expr> lit2_h = new literal_expr(loc, i2, true);
		rchandle<literal_expr> lit3_h = new literal_expr(loc, i3, true);
		rchandle<literal_expr> lit4_h = new literal_expr(loc, 123);
		rchandle<literal_expr> lit5_h = new literal_expr(loc, 123456);
		rchandle<literal_expr> lit6_h = new literal_expr(loc, 123.456);
	
		cout << "lit1 [" << literal_expr::decode_type(lit1_h->get_type()) << "] = ";
		lit1_h->put(cout,ctx) << " : " << symtab.get(lit1_h->get_sref()) << endl;
		cout << "lit2 [" << literal_expr::decode_type(lit2_h->get_type()) << "] = ";
		lit2_h->put(cout,ctx) << " : " << symtab.get(lit2_h->get_sref()) << endl;
		cout << "lit3 [" << literal_expr::decode_type(lit3_h->get_type()) << "] = ";
		lit3_h->put(cout,ctx) << " : " << symtab.get(lit3_h->get_sref()) << endl;
	
		cout << "lit4 [" << literal_expr::decode_type(lit4_h->get_type()) << "] = ";
		lit4_h->put(cout,ctx) << endl;
		cout << "lit5 [" << literal_expr::decode_type(lit5_h->get_type()) << "] = ";
		lit5_h->put(cout,ctx) << endl;
		cout << "lit6 [" << literal_expr::decode_type(lit6_h->get_type()) << "] = ";
		lit6_h->put(cout,ctx) << endl;
	
	
	/*...........................................
		: variables                               :
		:.........................................*/
		cout << "\n>>>var_expr\n";
		rchandle<var_expr> var1_h = new var_expr(loc);
	  var1_h->set_varname(&*qnv1_h);
	  var1_h->set_valexpr(&*lit1_h);
		var1_h->set_kind(var_expr::for_var);
	  var1_h->set_type(xs_untypedAtomicValue);
	
		rchandle<var_expr> var2_h = new var_expr(loc);
	  var2_h->set_varname(&*qnv2_h);
	  var2_h->set_valexpr(&*lit1_h);
		var2_h->set_kind(var_expr::let_var);
	  var2_h->set_type(xs_untypedAtomicValue);
	
		rchandle<var_expr> var3_h = new var_expr(loc);
	  var3_h->set_varname(&*qnv3_h);
	  var3_h->set_valexpr(&*lit1_h);
		var3_h->set_kind(var_expr::pos_var);
	  var3_h->set_type(xs_untypedAtomicValue);
	
		var1_h->put(cout,ctx) << endl;
		var2_h->put(cout,ctx) << endl;
		var3_h->put(cout,ctx) << endl;
	
	
	/*...........................................
		: expression list                         :
		:.........................................*/
		cout << "\n>>>expr_list\n";
		rchandle<expr_list> exlist1_h = new expr_list(loc);
		exlist1_h->add(&*var1_h);
		exlist1_h->add(&*var2_h);
		exlist1_h->add(&*var3_h);
		exlist1_h->put(cout,ctx);
	
	
	/*...........................................
		: constructors                            :
		:.........................................*/
		cout << "\n>>>text_expr\n";
		rchandle<text_expr> text1_h = new text_expr(loc, &*lit4_h);
		rchandle<text_expr> text2_h = new text_expr(loc, &*lit5_h);
		rchandle<text_expr> text3_h = new text_expr(loc, &*lit6_h);
	
		text1_h->put(cout,ctx) << endl;
		text2_h->put(cout,ctx) << endl;
		text3_h->put(cout,ctx) << endl;
	
		cout << "\n>>>comment_expr\n";
		rchandle<comment_expr> comment1_h = new comment_expr(loc, &*lit1_h);
		rchandle<comment_expr> comment2_h = new comment_expr(loc, &*lit2_h);
		rchandle<comment_expr> comment3_h = new comment_expr(loc, &*lit3_h);
	
		comment1_h->put(cout,ctx) << endl;
		comment2_h->put(cout,ctx) << endl;
		comment3_h->put(cout,ctx) << endl;
	
		cout << "\n>>>pi_expr\n";
		rchandle<pi_expr> pi1_h = new pi_expr(loc, "?PI1", &*lit1_h);
		rchandle<pi_expr> pi2_h = new pi_expr(loc, "?PI2", &*lit2_h);
		rchandle<pi_expr> pi3_h = new pi_expr(loc, "?PI3", &*lit3_h);
	
		pi1_h->put(cout,ctx) << endl;
		pi2_h->put(cout,ctx) << endl;
		pi3_h->put(cout,ctx) << endl;
	
		cout << "\n>>>attr_expr\n";
		rchandle<attr_expr> attr1_h = new attr_expr(loc, &*qna1_h, &*lit1_h);
		rchandle<attr_expr> attr2_h = new attr_expr(loc, &*qna2_h, &*lit2_h);
		rchandle<attr_expr> attr3_h = new attr_expr(loc, &*qna3_h, &*lit3_h);
	
		attr1_h->put(cout,ctx) << endl;
		attr2_h->put(cout,ctx) << endl;
		attr3_h->put(cout,ctx) << endl;
	
		rchandle<expr_list> exprlist2_h = new expr_list(loc);
		exprlist2_h->add(&*attr1_h);
		exprlist2_h->add(&*attr2_h);
		exprlist2_h->add(&*attr3_h);
		exprlist2_h->add(&*text1_h);
		exprlist2_h->add(&*text2_h);
		exprlist2_h->add(&*text3_h);
	
		cout << "\n>>>elem_expr\n";
		rchandle<elem_expr> elem1_h = new elem_expr(loc, &*qne1_h, &*exprlist2_h);
		elem_expr::nsbinding ns1("pre1","http://a1.b1.c1");
		elem_expr::nsbinding ns2("pre2","http://a2.b2.c2");
		elem1_h->add(ns1);
		elem1_h->add(ns2);
		elem1_h->put(cout,ctx) << endl;
	
		rchandle<elem_expr> elem2_h = new elem_expr(loc, &*qne2_h, &*exprlist2_h);
		elem2_h->add(ns1);
		elem2_h->add(ns2);
		elem2_h->put(cout,ctx) << endl;
	
		cout << "\n>>>doc_expr\n";
		rchandle<doc_expr> doc1_h = new doc_expr(loc, &*elem1_h);
		doc1_h->put(cout,ctx) << endl;
	
	
	/*...........................................
		: function call                           :
		:.........................................*/
		cout << "\n>>>funcall_expr\n";
		rchandle<funcall_expr> fun1_h = new funcall_expr(loc, &*qnf1_h);
		fun1_h->add_arg(&*lit1_h);
		fun1_h->add_arg(&*lit2_h);
		fun1_h->add_arg(&*lit3_h);
		fun1_h->put(cout,ctx) << endl;
		for (unsigned i=0; i<fun1_h->arg_count(); ++i) {
			cout << "arg[" << i << "] = ";
			(*fun1_h)[i]->put(cout,ctx) << endl;
		}
	
	
	/*...........................................
		: typeswitch expression                   :
		:.........................................*/
		cout << "\n>>>typeswitch_expr\n";
		rchandle<typeswitch_expr> sw1_h = new typeswitch_expr(loc);
		sw1_h->set_switch_expr(&*elem1_h);
		sw1_h->set_default_varname(&*var1_h);
		sw1_h->set_default_clause(&*elem1_h);
	
		case_clause cc1;
		cc1.var_h = var2_h;
		cc1.case_expr_h = &*lit1_h;
		cc1.type = xs_anyTypeSeq;
		sw1_h->add_clause(&cc1);
	
		case_clause cc2;
		cc2.var_h = var3_h;
		cc2.case_expr_h = &*lit2_h;
		cc2.type = xs_anyTypeSeq;
		sw1_h->add_clause(&cc2);
		sw1_h->put(cout,ctx);
	
	
	/*...........................................
		: conditional expression                  :
		:.........................................*/
		cout << "\n>>>if_expr\n";
		rchandle<if_expr> if1_h = new if_expr(loc, &*lit1_h, &*lit2_h, &*lit3_h);
		if1_h->put(cout,ctx);
	
	
	/*...........................................
		: cast-related expressions                :
		:.........................................*/
		cout << "\n>>>instanceof_expr\n";
		rchandle<instanceof_expr> inst1_h =
			new instanceof_expr(loc,&*lit4_h,xs_anyType);
		inst1_h->put(cout,ctx) << endl;
	
		cout << "\n>>>treat_expr\n";
		rchandle<treat_expr> treat1_h =
			new treat_expr(loc, &*lit5_h, xs_int);
		treat1_h->put(cout,ctx) << endl;
	
		cout << "\n>>>castable_expr\n";
		rchandle<castable_expr> castable1_h =
			new castable_expr(loc, &*lit6_h, xs_untypedAtomicValue);
		castable1_h->put(cout,ctx) << endl;
	
		cout << "\n>>>cast_expr\n";
		rchandle<cast_expr> cast1_h =
			new cast_expr(loc, &*lit1_h, xs_untypedAtomicValue);
		cast1_h->put(cout,ctx) << endl;
	
	
	/*...........................................
		: validate expression                     :
		:.........................................*/
		cout << "\n>>>validate_expr\n";
		rchandle<validate_expr> val1_h =
			new validate_expr(loc, val_strict, &*elem1_h);
		val1_h->put(cout,ctx) << endl;
	
	
	/*...........................................
		: extension expressions                   :
		:.........................................*/
		/*
		cout << "\n>>>extension_expr\n";
		rchandle<extension_expr> ext1_h =
			new extension_expr(loc,&*lit1_h);
		rchandle<pragma> prag1_h = new pragma(&*qnp1_h, "content1");
		ext1_h->add(prag1_h);
		ext1_h->put(cout,ctx) << endl;
		*/

	
	/*...........................................
		: path expressions                        :
		:.........................................*/
		cout << "\n>>>axis_step_expr\n";
		rchandle<axis_step_expr> ax1_h = new axis_step_expr(loc);
		ax1_h->set_axis(axis_step_expr::child);
		ax1_h->set_test(axis_step_expr::name_test);
		ax1_h->set_name(&*qne1_h);
		ax1_h->add_pred(&*elem1_h);
		ax1_h->put(cout,ctx) << endl;
	
		rchandle<axis_step_expr> ax2_h = new axis_step_expr(loc);
		ax2_h->set_axis(axis_step_expr::child);
		ax2_h->set_test(axis_step_expr::name_test);
		ax2_h->set_name(&*qne2_h);
		ax2_h->add_pred(&*elem2_h);
		ax2_h->put(cout,ctx) << endl;
	
		rchandle<relpath_expr> path1_h = new relpath_expr(loc);
		path1_h->add_back(&*ax1_h);
		path1_h->add_back(&*ax2_h);
		path1_h->put(cout,ctx) << endl;
	
	
	/*...........................................
		: quantified expressions                  :
		:.........................................*/
		cout << "\n>>>quantified_expr\n";
		rchandle<quantified_expr> quant1_h =
			new quantified_expr(loc,quant_some);
		quant1_h->add(&*var1_h);
		quant1_h->set_sat_expr(&*elem1_h);
		quant1_h->put(cout,ctx) << endl;
	
		rchandle<quantified_expr> quant2_h =
			new quantified_expr(loc,quant_some);
		quant2_h->add(&*var2_h);
		quant2_h->set_sat_expr(&*elem2_h);
		quant2_h->put(cout,ctx) << endl;
	
	
	/*...........................................
		: FO expressions                          :
		:.........................................*/
		cout << "\n>>>fo_expr\n";
		rchandle<signature> sig1_h = new signature(&ctx,"func1",anyNodeSeq);
		sig1_h->add_arg(anyNodeSeq);
		sig1_h->add_arg(anyNodeSeq);
		function func1(*sig1_h);
		rchandle<fo_expr> fo1_h = new fo_expr(loc);
		fo1_h->add(&*lit1_h);
		fo1_h->add(&*lit2_h);
		fo1_h->set_func(&func1);
		fo1_h->put(cout,ctx) << endl;
	
	
	/*...........................................
		: FLWOR expressions                       :
		:.........................................*/
		cout << "\n>>>flwor_expr\n";
		rchandle<flwor_expr> flwor1_h = new flwor_expr(loc);
		rchandle<forlet_clause> flc1_h =
			new forlet_clause(forlet_clause::for_clause,&*var1_h,NULL,NULL,&*elem1_h);
		rchandle<forlet_clause> flc2_h =
			new forlet_clause(forlet_clause::let_clause,&*var2_h,NULL,NULL,&*elem2_h);
		flwor1_h->add(&*flc1_h);
		flwor1_h->add(&*flc2_h);
		flwor1_h->set_where(&*var1_h);
		flwor1_h->set_retval(&*var2_h);
		flwor1_h->put(cout,ctx) << endl;

	} catch (null_pointer& e) {
		cout << "Application exception: " << e.get_msg() << endl;
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

