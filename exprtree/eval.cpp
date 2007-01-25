/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: eval.cpp.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "expr.h"

#include "../functions/function_impl.h"
#include "../util/Assert.h"
#include "../util/list.h"
#include "../util/xqp_exception.h"
#include "../values/node_values.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
namespace xqp {


/*...........................................
	: expr                                    :
	:.........................................:
*/

rchandle<item_iterator> expr::eval(
	context& ctx)
{
#ifdef DEBUG
	cout << "expr::"<<__FUNCTION__ << endl;
#endif
	return new item_iterator(ctx);
}


/*...........................................
	: literal expr                            :
	:.........................................:
*/

rchandle<item_iterator> literal_expr::eval(
	context& ctx)
{
#ifdef DEBUG
	cout << __FUNCTION__ << endl;
#endif
	switch (type) {
	case lit_string: {
  	return new singleton_iterator(ctx,ctx.string_storage.get(sref));
	}
	case lit_integer: return new singleton_iterator(ctx,ival);
	case lit_decimal: return new singleton_iterator(ctx,decval);
	case lit_double: return new singleton_iterator(ctx,dval);
	default: return new item_iterator(ctx);
	}
}


/*...........................................
	: expr_list                               :
	:.........................................:
*/

rchandle<item_iterator> expr_list::eval(
	context & ctx) 
{
#ifdef DEBUG
	cout << "expr_list::"<<__FUNCTION__ << endl;
#endif
	list<rchandle<item_iterator> > it_list;
	list_iterator<exprref_t> it = begin();
	for (; it!=end(); ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		it_list.push_back(&*e_h->eval(ctx));
	}
	return new concat_iterator(ctx, it_list);
}


/*...........................................
	: var_expr                                :
	:.........................................:
*/

rchandle<item_iterator> var_expr::eval(
	context & ctx) 
{
#ifdef DEBUG
	cout << "var_expr::"<<__FUNCTION__ << endl;
#endif
	rchandle<expr> e_h = get_valexpr();
	if (e_h==NULL) {
		cout << __FUNCTION__ << " : NULL value\n";
		return new item_iterator(ctx);
	}
	expr* e_p = &*e_h;
	rchandle<item_iterator> res_h = e_p->eval(ctx);
	return res_h;
}


/*...........................................
	: flwor_expr                              :
	:.........................................:
*/

rchandle<item_iterator> flwor_expr::eval(
	context & ctx) 
{
	/*
	vector<forletref_t>::const_iterator it = clause_begin();
	for (; it!=clause_end(); ++it) {
		forletref_t fl_h = *it;
		Assert<null_pointer>(fl_h!=NULL);
		fl_h->put(os,ctx);
	}
	if (where_h!=NULL) where_h->put(os,ctx);
	vector<orderspec_t>::const_iterator ord_it = orderspec_begin();
	for (; ord_it!=orderspec_end(); ++ord_it) {
		orderspec_t spec = *ord_it;
		exprref_t e_h = spec.first;
		Assert<null_pointer>(e_h!=NULL);
		orderref_t ord_h = spec.second;
		Assert<null_pointer>(ord_h!=NULL);
		os << e_h->put(os,ctx) << endl;
		switch (ord_h->dir) {
		case dir_ascending: os << "ASCENDING "; break;
		case dir_descending: os << "DESCENDING "; break;
		default: os << "?? ";
		}
		switch (ord_h->empty_mode) {
		case context::empty_greatest: os << "EMPTY GREATEST "; break;
		case context::empty_least: os << "EMPTY LEAST "; break;
		default: os << "?? ";
		}
		os << ord_h->collation << endl;
	}
	Assert<null_pointer>(retval_h!=NULL);
	return retval_h->put(os,ctx);
	*/
	return new item_iterator(ctx);
}


/*...........................................
	: quantified_expr                         :
	:.........................................:
*/

rchandle<item_iterator> quantified_expr::eval(
	context & ctx) 
{
	/*
	switch (qmode) {
	case quant_some: os << "SOME\n"; break;
	case quant_every: os << "EVERY\n"; break;
	default: os << "??\n";
	}
	vector<varref_t>::const_iterator it = var_v.begin();
	for (; it!=var_v.end(); ++it) {
		varref_t var_h = *it;
		Assert<null_pointer>(var_h!=NULL);
		Assert<null_pointer>(var_h->varname_h!=NULL);
		var_h->varname_h->put(os,ctx) << " in ";
		Assert<null_pointer>(var_h->valexpr_h!=NULL);
		var_h->valexpr_h->put(os,ctx) << endl;
	}
	Assert<null_pointer>(sat_expr_h!=NULL);
	sat_expr_h->put(os,ctx);
	*/

	return new item_iterator(ctx);
}


/*...........................................
	: typeswitch_expr                         :
	:.........................................:
*/

rchandle<item_iterator> typeswitch_expr::eval(
	context & ctx)
{
	/*
	Assert<null_pointer>(switch_expr_h!=NULL);
	switch_expr_h->put(os,ctx);
	vector<case_clause>::const_iterator it = case_clause_hv.begin();
	for (; it!=case_clause_hv.end(); ++it) {
		case_clause cc = *it;
		if (cc.var_h!=NULL) cc.var_h->put(os,ctx) << " as ";
		os << cc.seqtype.describe() << " return ";
		Assert<null_pointer>(cc.case_expr_h!=NULL);
		cc.case_expr_h->put(os,ctx) << endl;
	}
	*/

	return new item_iterator(ctx);
}


/*...........................................
	: if_expr                                 :
	:.........................................:
*/

rchandle<item_iterator> if_expr::eval(
	context & ctx)
{
	Assert<null_pointer>(cond_expr_h!=NULL);
	rchandle<item_iterator> cond_it_h = cond_expr_h->eval(ctx);
	item_iterator* cond_it_p = &*cond_it_h;

	if (cond_it_p->done()) {
		Assert<null_pointer>(then_expr_h!=NULL);
		return then_expr_h->eval(ctx);
	}
	else {
		Assert<null_pointer>(else_expr_h!=NULL);
		return else_expr_h->eval(ctx);
	}
}


/*...........................................
	: fo_expr                                 :
	:.........................................:
*/

rchandle<item_iterator> fo_expr::eval(
	context & ctx)
{
	Assert<null_pointer>(func!=NULL);
	rchandle<QName> fname_h = func->sig_h->get_fname();
	vector<rchandle<expr> >::const_iterator it = begin();
	for (; it!=end(); ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		e_h->eval(ctx);
	}

	return new item_iterator(ctx);
}


/*...........................................
	: text_expr                               :
	:.........................................:
*/

rchandle<item_iterator> text_expr::eval(
	context & ctx)
{
	Assert<null_pointer>(text_expr_h!=NULL);
	rchandle<item_iterator> it_h = text_expr_h->eval(ctx);
	string content = it_h->string_value(ctx);

	rchandle<text_node> tnode_h =
		new text_node(ctx.next_nodeid(),content,ctx.context_nodeid());

	return new singleton_iterator(ctx, &*tnode_h);
}


/*...........................................
	: comment_expr                            :
	:.........................................:
*/

rchandle<item_iterator> comment_expr::eval(
	context & ctx)
{
	Assert<null_pointer>(comment_expr_h!=NULL);
	return comment_expr_h->eval(ctx);
}



/*...........................................
	: doc_expr                                :
	:.........................................:
*/

rchandle<item_iterator> doc_expr::eval(
	context t& ctx) 
{
	Assert<null_pointer>(docuri_h!=NULL);
	return docuri_h->eval(ctx);
}



/*...........................................
	: elem_expr                               :
	:.........................................:
*/

rchandle<item_iterator> elem_expr::eval(
	context & ctx) 
{
	Assert<bad_arg>(qname_h!=NULL || qname_expr_h!=NULL);
	if (qname_h!=NULL) {
		qname_h->put(os,ctx) << ">\n";
	}
	else {
		qname_expr_h->put(os,ctx) << ">\n";
	}
	vector<nsbinding>::const_iterator it = begin();
	vector<nsbinding>::const_iterator en = end();
	for (; it!=en; ++it) {
		nsbinding nsb = *it;
		string ncname = nsb.first;
		string nsuri = nsb.second;
		os << INDENT << "xmlns:" << ncname << "=\"" << nsuri << "\"\n"; UNDENT;
	}
	Assert<null_pointer>(content_expr_h!=NULL);
	content_expr_h->put(os,ctx);
}



/*...........................................
	: attr_expr                               :
	:.........................................:
*/

rchandle<item_iterator> attr_expr::eval(
	context & ctx) 
{
	Assert<bad_arg>(qname_h!=NULL || qname_expr_h!=NULL);
	if (qname_h!=NULL) {
		qname_h->put(os,ctx);
	}
	else {
		qname_expr_h->put(os,ctx);
	}

	Assert<null_pointer>(val_expr_h!=NULL);
	rchandle<item_iterator> val_h = val_expr_h->eval(ctx);


	rchandle<item> i_h = ctx.get_context_item();
	elem_node* n_p = dynamic_cast<elem_node*>(&*i_h);
	if (n_p==NULL) {
		throw xqp_exception(__FUNCTION__,"expecting element node parent");
	}

	rchandle<attr_node> anode_h =
		new attr_node(rand(), name_h, value, n_p->get_nodeid());

	return new singleton_iterator(ctx, &*anode_h);

}




}	/* namespace xqp */
