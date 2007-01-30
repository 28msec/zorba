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
	context * ctx_p)
{
#ifdef DEBUG
	cout << "expr::"<<__FUNCTION__ << endl;
#endif
	return new item_iterator(ctx_p);
}


/*...........................................
	: literal expr                            :
	:.........................................:
*/

rchandle<item_iterator> literal_expr::eval(
	context * ctx_p)
{
#ifdef DEBUG
	cout << __FUNCTION__ << endl;
#endif
	switch (type) {
	case lit_string: {
  	return new singleton_iterator(ctx_p,ctx_p->get_string(sref));
	}
	case lit_integer: return new singleton_iterator(ctx_p,ival);
	case lit_decimal: return new singleton_iterator(ctx_p,decval);
	case lit_double: return new singleton_iterator(ctx_p,dval);
	default: return new item_iterator(ctx_p);
	}
}


/*...........................................
	: expr_list                               :
	:.........................................:
*/

rchandle<item_iterator> expr_list::eval(
	context * ctx_p) 
{
#ifdef DEBUG
	cout << "expr_list::"<<__FUNCTION__ << endl;
#endif
	list<rchandle<item_iterator> > it_list;
	list_iterator<exprref_t> it = begin();
	for (; it!=end(); ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		it_list.push_back(&*e_h->eval(ctx_p));
	}
	return new concat_iterator(ctx_p, it_list);
}


/*...........................................
	: var_expr                                :
	:.........................................:
*/

rchandle<item_iterator> var_expr::eval(
	context * ctx_p) 
{
#ifdef DEBUG
	cout << "var_expr::"<<__FUNCTION__ << endl;
#endif
	rchandle<expr> e_h = get_valexpr();
	if (e_h==NULL) {
		cout << __FUNCTION__ << " : NULL value\n";
		return new item_iterator(ctx_p);
	}
	expr* e_p = &*e_h;
	rchandle<item_iterator> res_h = e_p->eval(ctx_p);
	return res_h;
}


/*...........................................
	: flwor_expr                              :
	:.........................................:
*/

rchandle<item_iterator> flwor_expr::eval(
	context * ctx_p) 
{
	/*
	vector<forletref_t>::const_iterator it = clause_begin();
	for (; it!=clause_end(); ++it) {
		forletref_t fl_h = *it;
		Assert<null_pointer>(fl_h!=NULL);
		fl_h->put(os,ctx_p);
	}
	if (where_h!=NULL) where_h->put(os,ctx_p);
	vector<orderspec_t>::const_iterator ord_it = orderspec_begin();
	for (; ord_it!=orderspec_end(); ++ord_it) {
		orderspec_t spec = *ord_it;
		exprref_t e_h = spec.first;
		Assert<null_pointer>(e_h!=NULL);
		orderref_t ord_h = spec.second;
		Assert<null_pointer>(ord_h!=NULL);
		os << e_h->put(os,ctx_p) << endl;
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
	return retval_h->put(os,ctx_p);
	*/
	return new item_iterator(ctx_p);
}


/*...........................................
	: quantified_expr                         :
	:.........................................:
*/

rchandle<item_iterator> quantified_expr::eval(
	context * ctx_p) 
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
		var_h->varname_h->put(os,ctx_p) << " in ";
		Assert<null_pointer>(var_h->valexpr_h!=NULL);
		var_h->valexpr_h->put(os,ctx_p) << endl;
	}
	Assert<null_pointer>(sat_expr_h!=NULL);
	sat_expr_h->put(os,ctx_p);
	*/

	return new item_iterator(ctx_p);
}


/*...........................................
	: typeswitch_expr                         :
	:.........................................:
*/

rchandle<item_iterator> typeswitch_expr::eval(
	context * ctx_p)
{
	/*
	Assert<null_pointer>(switch_expr_h!=NULL);
	switch_expr_h->put(os,ctx_p);
	vector<case_clause>::const_iterator it = case_clause_hv.begin();
	for (; it!=case_clause_hv.end(); ++it) {
		case_clause cc = *it;
		if (cc.var_h!=NULL) cc.var_h->put(os,ctx_p) << " as ";
		os << cc.seqtype.describe() << " return ";
		Assert<null_pointer>(cc.case_expr_h!=NULL);
		cc.case_expr_h->put(os,ctx_p) << endl;
	}
	*/

	return new item_iterator(ctx_p);
}


/*...........................................
	: if_expr                                 :
	:.........................................:
*/

rchandle<item_iterator> if_expr::eval(
	context * ctx_p)
{
	Assert<null_pointer>(cond_expr_h!=NULL);
	rchandle<item_iterator> cond_it_h = cond_expr_h->eval(ctx_p);
	item_iterator* cond_it_p = &*cond_it_h;

	if (cond_it_p->done()) {
		Assert<null_pointer>(then_expr_h!=NULL);
		return then_expr_h->eval(ctx_p);
	}
	else {
		Assert<null_pointer>(else_expr_h!=NULL);
		return else_expr_h->eval(ctx_p);
	}
}


/*...........................................
	: fo_expr                                 :
	:.........................................:
*/

rchandle<item_iterator> fo_expr::eval(
	context * ctx_p)
{
	Assert<null_pointer>(func!=NULL);
	rchandle<QName> fname_h = func->sig_h->get_fname();
	vector<rchandle<expr> >::const_iterator it = begin();
	for (; it!=end(); ++it) {
		rchandle<expr> e_h = *it;
		Assert<null_pointer>(e_h!=NULL);
		e_h->eval(ctx_p);
	}

	return new item_iterator(ctx_p);
}


/*...........................................
	: text_expr                               :
	:.........................................:
*/

rchandle<item_iterator> text_expr::eval(
	context * ctx_p)
{
	Assert<null_pointer>(text_expr_h!=NULL);
	rchandle<item_iterator> it_h = text_expr_h->eval(ctx_p);
	string content = it_h->string_value();

	rchandle<text_node> tnode_h =
		new text_node(ctx_p->next_nodeid(),
									ctx_p->context_nodeid(),
									content);

	return new singleton_iterator(ctx_p, &*tnode_h);
}


/*...........................................
	: comment_expr                            :
	:.........................................:
*/

rchandle<item_iterator> comment_expr::eval(
	context * ctx_p)
{
	Assert<null_pointer>(comment_expr_h!=NULL);
	return comment_expr_h->eval(ctx_p);
}



/*...........................................
	: document constructor                    :
	:.........................................:
*/

rchandle<item_iterator> doc_expr::eval(
	context * ctx_p) 
{
	Assert<null_pointer>(docuri_h!=NULL);
	return docuri_h->eval(ctx_p);
}



/*...........................................
	: element constructor                     :
	:.........................................:
*/

/*_________________________________________________________________________
|
|  [http://www.w3.org/TR/xquery/#id-computedElements]
|
|  Processing of the computed element constructor proceeds as follows:
|  
|  1.  Adjacent text nodes in the content sequence are merged into a 
|  single text node by concatenating their contents, with no intervening 
|  blanks. After concatenation, any text node whose content is a 
|  zero-length string is deleted from the content sequence. 
|  
|  2.  If the content sequence contains a document node, the document 
|  node is replaced in the content sequence by its children. 
|  
|  3.  If the content sequence contains an attribute node following a 
|  node that is not an attribute node, a type error is raised 
|  [err:XQTY0024]. 
|  
|  4.  The properties of the newly constructed element node are 
|  determined as follows: 
|    1.  node-name is the expanded QName resulting from processing the 
|    specified QName or name expression, as described above. 
|  
|    2.  base-uri is taken from the first of the following sources that 
|    exists: 
|      1.  the value of the constructed node's attribute named xml:base, 
|      if this attribute exists; 
|
|      2.  base URI in the static context. 
|  
|    3.  parent is empty. 
|  
|    4.  attributes consist of all the attribute nodes in the content 
|    sequence, in implementation-dependent order. If two or more of these 
|    attributes have the same node-name, a dynamic error is raised 
|    [err:XQDY0025]. Note that the parent property of each of these 
|    attribute nodes has been set to the newly constructed element node. 
|  
|    5.  children consist of all the element, text, comment, and 
|    processing instruction nodes in the content sequence. Note that the 
|    parent property of each of these nodes has been set to the newly 
|    constructed element node. 
|  
|    6.  in-scope-namespaces are computed as described in 3.7.4 In-scope 
|    Namespaces of a Constructed Element. 
|  
|    7.  The nilled property is false.
|  
|    8.  The string-value property is equal to the concatenated contents 
|    of the text-node descendants in document order. 
|  
|    9.  The typed-value property is equal to the string-value property, 
|    as an instance of xs:untypedAtomic. 
|  
|    10.  If construction mode in the static context is strip, the 
|    type-name property is xs:untyped. On the other hand, if construction 
|    mode is preserve, the type-name property is xs:anyType. 
|  
|    11.  The is-id and is-idrefs properties are set to false.
|__________________________________________________________________________*/


rchandle<item_iterator> elem_expr::eval(
	context * ctx_p) 
{
	Assert<bad_arg>(qname_h!=NULL || qname_expr_h!=NULL);
	if (qname_h==NULL) {
		rchandle<item_iterator> it_h = qname_expr_h->eval(ctx_p);
		qname_h = new QName(QName::qn_elem,it_h->string_value());
	}

	nodeid docid = ctx_p->context_docid();
	nodeid parentid = ctx_p->context_nodeid();
	nodeid id = ctx_p->next_nodeid();

	rchandle<element_node> enode_h =
		new element_node(id, parentid, docid, qname_h);

	vector<nsbinding>::const_iterator it = ns_begin();
	for (; it!=ns_end(); ++it) {
		nsbinding nsb = *it;
		string pre = nsb.first;
		string uri = nsb.second;
		rchandle<ns_node> nnode_h =
			new ns_node(ctx_p->next_nodeid(),parentid,pre,uri);
		enode_h->add_node(&*nnode_h);
	}

	Assert<null_pointer>(content_expr_h!=NULL);
	rchandle<item_iterator> child_it_h = content_expr_h->eval(ctx_p);
	ostringstream oss;
	for (; !child_it_h->done(); ++(*child_it_h)) {
		rchandle<item> i_h = **child_it_h;
		if (!i_h->is_node()) {
			oss << i_h->string_value(ctx_p);
			continue;
		}
		rchandle<node> n_h = dynamic_cast<node*>(&*i_h);
		nodeid child_id = ctx_p->next_nodeid();
		if (n_h->node_kind()==node::text_kind && oss.str().length()>0) {
			oss << n_h->string_value(ctx_p);
			n_h = new text_node(child_id,id,oss.str());
			oss.str("");
		}
		enode_h->add_node(&*n_h);
	}
	enode_h->set_nilled(false);
	enode_h->set_id(false);
	enode_h->set_idrefs(false);

	return new singleton_iterator(ctx_p, &*enode_h);

}



/*...........................................
	: attribute constructor                   :
	:.........................................:
*/

rchandle<item_iterator> attr_expr::eval(
	context * ctx_p) 
{
	Assert<bad_arg>(qname_h!=NULL || qname_expr_h!=NULL);
	if (qname_h==NULL) {
		rchandle<item_iterator> it_h = qname_expr_h->eval(ctx_p);
		qname_h = new QName(QName::qn_attr,it_h->string_value());
	}
	Assert<null_pointer>(val_expr_h!=NULL);
	rchandle<item_iterator> val_h = val_expr_h->eval(ctx_p);
	string valstr = val_h->string_value();
	nodeid parentid = ctx_p->context_nodeid();
	nodeid new_id = ctx_p->next_nodeid();

	rchandle<attribute_node> anode_h =
		new attribute_node(new_id, parentid, qname_h, valstr);

	return new singleton_iterator(ctx_p, &*anode_h);

}




}	/* namespace xqp */
