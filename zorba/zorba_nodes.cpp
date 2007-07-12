/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: zorba_nodes.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "zorba_nodes.h"
#include "runtime/zorba.h"
#include "store/data_manager.h"
#include "values/qname.h"

using namespace std;
namespace xqp {


// zorba_document_node
// -------------------

zorba_document_node::zorba_document_node(
	document_noderep* _rep)
:
	rep(_rep)
{
}

zorba_document_node::zorba_document_node(
	zorba_document_node& dn)
:
	item (dn), node (dn), zorba_node (dn), document_node (dn),
	rep(dn.rep)
{
}

// XQuery interface
iterator_t zorba_document_node::string_value(
	zorba* zorp) const
{
	return new singleton_iterator(new stringValue(rep->str(zorp)));
}

iterator_t zorba_document_node::base_uri(
	zorba* zorp) const
{
	data_manager* dmgr_p = zorp->get_data_manager();
	const qname* qn_p = dmgr_p->get_qname(rep->baseuri());
	return new singleton_iterator((item*)qn_p);
}

iterator_t zorba_document_node::document_uri(
	zorba* zorp) const
{
	data_manager* dmgr_p = zorp->get_data_manager();
	const qname* qn_p = dmgr_p->get_qname(rep->docuri());
	return new singleton_iterator((item*)qn_p);
}

iterator_t zorba_document_node::children(
	zorba* zorp) const
{
	return new child_iterator(*this);
}

iterator_t zorba_document_node::typed_value(
	zorba* zorp) const
{
	return new singleton_iterator(new stringValue(rep->str(zorp)));
}

iterator_t zorba_document_node::atomized_value(
	zorba* zorp) const
{
	return new singleton_iterator(new stringValue(rep->str(zorp)));
}

ostream& zorba_document_node::put(
	zorba* zorp,
	ostream& os) const
{
	rep->put(zorp,os);
	return os;
}

string zorba_document_node::describe(
	zorba* zorp) const
{
	ostringstream oss;
	oss << "doc(" << get_base_uri(zorp) << ")";
	return oss.str();
}


// internal interface		
// (stubs for now)
string zorba_document_node::str(
	zorba* zorp) const 
{
	return "";
}

string zorba_document_node::get_base_uri(
	zorba* zorp) const
{
	return "";
}

string zorba_document_node::get_document_uri(
	zorba* zorp) const
{
	return "";
}

string zorba_document_node::get_typed_value(
	zorba* zorp) const
{
	return "";
}

const qname* zorba_document_node::get_type_name(
	zorba* zorp) const
{
	return 0;
}




// zorba_element_node
// ------------------

zorba_element_node::zorba_element_node(
	element_noderep* _rep)
:
	rep(_rep)
{
}

zorba_element_node::zorba_element_node(
	const zorba_element_node& en)
:
  item (en), node (en), zorba_node (en), element_node (en),
	rep(en.rep)
{
}

// XQuery interface
iterator_t zorba_element_node::string_value(
	zorba* zorp) const
{
	return new singleton_iterator(new stringValue(rep->str(zorp)));
}

iterator_t zorba_element_node::base_uri(
	zorba* zorp) const
{
	const node* n_p = get_parent(zorp);
	Assert<null_pointer>(n_p!=NULL);
	return n_p->base_uri(zorp);
}

iterator_t zorba_element_node::type_name(
	zorba* zorp) const
{
	const qname* qn_p = get_type_name(zorp);
	Assert<null_pointer>(qn_p!=NULL);
	return new singleton_iterator((item*)qn_p);
}

iterator_t zorba_element_node::node_name(
	zorba* zorp) const
{
	const qname* qn_p = get_node_name(zorp);
	Assert<null_pointer>(qn_p!=NULL);
	return new singleton_iterator((item*)qn_p);
}

iterator_t zorba_element_node::parent(
	zorba* zorp) const
{
	const node* n_p = get_parent(zorp);
	Assert<null_pointer>(n_p!=NULL);
	return new singleton_iterator((item*)n_p);
}

iterator_t zorba_element_node::typed_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

iterator_t zorba_element_node::atomized_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

iterator_t zorba_element_node::attributes(
	zorba*) const
{
	return new attribute_iterator(*this);
}

iterator_t zorba_element_node::children(
	zorba*) const
{
	return new child_iterator(*this);
}

iterator_t zorba_element_node::namespace_nodes(
	zorba*) const
{
	return new namespace_iterator(*this);
}

// internal interface
string zorba_element_node::str(zorba*) const { return ""; }
string zorba_element_node::get_base_uri(zorba*) const { return ""; }
string zorba_element_node::get_document_uri(zorba*) const { return ""; }
string zorba_element_node::get_typed_value(zorba*) const { return ""; }
const qname* zorba_element_node::get_node_name(zorba*) const { return 0; }
const qname* zorba_element_node::get_type_name(zorba*) const { return 0; }

const node* zorba_element_node::get_parent(
	zorba* zorp) const
{
	data_manager* dmgr_p = zorp->get_data_manager();
	const node* p = dmgr_p->get_node(rep->parentid());

	switch (p->type()) {
	case documentNode: {
		document_noderep* q = new(p) document_noderep();
		Assert<null_pointer>(q!=NULL);
		return new zorba_document_node(q);
	}
	case elementNode: {
		element_noderep* q = new (p) element_noderep();
		Assert<null_pointer>(q!=NULL);
		return new zorba_element_node(q);
	}
	default: {
		return NULL;
	}}
}

// debugging, output
ostream& zorba_element_node::put(
	zorba* zorp,
	ostream& os) const
{
	rep->put(zorp,os);
	return os;
}



// zorba_attribute_node
// --------------------

zorba_attribute_node::zorba_attribute_node(
	attribute_noderep* _rep)
:
	rep(_rep)
{
}

zorba_attribute_node::zorba_attribute_node(
	zorba_attribute_node& an)
:
  item (an), node (an), zorba_node (an), attribute_node (an),
	rep(an.rep)
{
}

// XQuery interface
iterator_t zorba_attribute_node::string_value(
	zorba* zorp) const
{
	return new singleton_iterator(new stringValue(rep->str(zorp)));
}

iterator_t zorba_attribute_node::base_uri(
	zorba* zorp) const
{
	const node* n_p = get_parent(zorp);
	Assert<null_pointer>(n_p!=NULL);
	return n_p->base_uri(zorp);
}

iterator_t zorba_attribute_node::type_name(
	zorba* zorp) const
{
	const qname* qn_p = get_type_name(zorp);
	Assert<null_pointer>(qn_p!=NULL);
	return new singleton_iterator((item*)qn_p);
}

iterator_t zorba_attribute_node::node_name(
	zorba* zorp) const
{
	const qname* qn_p = get_node_name(zorp);
	Assert<null_pointer>(qn_p!=NULL);
	return new singleton_iterator((item*)qn_p);
}

iterator_t zorba_attribute_node::parent(
	zorba* zorp) const
{
	const node* n_p = get_parent(zorp);
	Assert<null_pointer>(n_p!=NULL);
	return new singleton_iterator((item*)n_p);
}

iterator_t zorba_attribute_node::typed_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

iterator_t zorba_attribute_node::atomized_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

// internal interface

ostream& zorba_attribute_node::put(
	zorba* zorp,
	ostream& os) const
{
	rep->put(zorp,os);
	return os;
}



// zorba_namespace_node
// --------------------

zorba_namespace_node::zorba_namespace_node(
	namespace_noderep* _rep)
:
	rep(_rep)
{
}

zorba_namespace_node::zorba_namespace_node(
	zorba_namespace_node& nn)
:
  item (nn), node (nn), zorba_node (nn), namespace_node (nn),
	rep(nn.rep)
{
}

// XQuery interface
iterator_t zorba_namespace_node::string_value(
	zorba* zorp) const
{
	return new singleton_iterator(new stringValue(rep->uri()));
}

iterator_t zorba_namespace_node::node_name(
	zorba* zorp) const
{
	return new singleton_iterator(new stringValue(rep->prefix()));
}

iterator_t zorba_namespace_node::typed_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

iterator_t zorba_namespace_node::atomized_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

// internal iterface

ostream& zorba_namespace_node::put(
	zorba* zorp,
	ostream& os) const
{
	rep->put(zorp,os);
	return os;
}



// zorba_pi_node
// -------------

zorba_pi_node::zorba_pi_node(
	pi_noderep* _rep)
:
	rep(_rep)
{
}

zorba_pi_node::zorba_pi_node(
	const zorba_pi_node& pn)
:
  item (pn), node (pn), zorba_node (pn), pi_node (pn),
	rep(pn.rep)
{
}

// XQuery interface
iterator_t zorba_pi_node::string_value(
	zorba* zorp) const 
{
	return new singleton_iterator(new stringValue(rep->content()));
}

iterator_t zorba_pi_node::typed_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

iterator_t zorba_pi_node::atomized_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

iterator_t zorba_pi_node::base_uri(
	zorba* zorp) const
{
	const node* n_p = get_parent(zorp);
	Assert<null_pointer>(n_p!=NULL);
	return n_p->base_uri(zorp);
}

iterator_t zorba_pi_node::node_name(
	zorba* zorp) const
{
	const qname* qn_p = get_node_name(zorp);
	Assert<null_pointer>(qn_p!=NULL);
	return new singleton_iterator((item*)qn_p);
}

iterator_t zorba_pi_node::parent(
	zorba* zorp) const
{
	const node* n_p = get_parent(zorp);
	Assert<null_pointer>(n_p!=NULL);
	return new singleton_iterator((item*)n_p);
}


// internal interface

ostream& zorba_pi_node::put(
	zorba* zorp,
	ostream& os) const
{
	rep->put(zorp,os);
	return os;
}




// zorba_comment_node
// ----------------

zorba_comment_node::zorba_comment_node(
	comment_noderep* _rep)
:
	rep(_rep)
{
}

zorba_comment_node::zorba_comment_node(
	const zorba_comment_node& cn)
:
  item (cn), node (cn), zorba_node (cn), comment_node (cn),
	rep(cn.rep)
{
}

// XQuery interface
iterator_t zorba_comment_node::string_value(
	zorba* zorp) const
{
	return new singleton_iterator(new stringValue(rep->str(zorp)));
}

iterator_t zorba_comment_node::base_uri(
	zorba* zorp) const
{
	const node* n_p = get_parent(zorp);
	Assert<null_pointer>(n_p!=NULL);
	return n_p->base_uri(zorp);
}

iterator_t zorba_comment_node::typed_value(
	zorba* zorp) const
{
	return new singleton_iterator((item*)this);
}

iterator_t zorba_comment_node::atomized_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

// internal interface

string zorba_comment_node::str(
	zorba* zorp) const
{
	return rep->str(zorp);
}

ostream& zorba_comment_node::put(
	zorba* zorp,
	ostream& os) const
{
	return os << "<!--" << rep->str(zorp) << "-->";
}




// zorba_text_node
// -------------

zorba_text_node::zorba_text_node(
	text_noderep* _rep)
:
	rep(_rep)
{
}

zorba_text_node::zorba_text_node(
	const zorba_text_node& tn) 
:
  item (tn), node (tn), zorba_node (tn), text_node (tn),
	rep(tn.rep)
{
}


// XQuery interface
iterator_t zorba_text_node::string_value(
	zorba* zorp) const
{
	return new singleton_iterator(new stringValue(rep->str(zorp)));
}

iterator_t zorba_text_node::base_uri(
	zorba* zorp) const
{
	const node* n_p = get_parent(zorp);
	Assert<null_pointer>(n_p!=NULL);
	return n_p->base_uri(zorp);
}

iterator_t zorba_text_node::typed_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

iterator_t zorba_text_node::atomized_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

// internal interface

ostream& zorba_text_node::put(
	zorba* zorp,
	ostream& os) const
{
	return os << rep->str(zorp);
}


}	/* namespace xqp */

