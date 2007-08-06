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
	yy::location &loc) const
{
	return new SingletonIterator(loc,new stringValue(rep->str()));
}

iterator_t zorba_document_node::base_uri(
	yy::location &loc) const
{
	data_manager* dmgr_p = zorba::getZorbaForCurrentThread()->get_data_manager();
	const qname* qn_p = dmgr_p->get_qname(rep->baseuri());
	return new SingletonIterator(loc,(item*)qn_p);
}

iterator_t zorba_document_node::document_uri(
	yy::location &loc) const
{
	data_manager* dmgr_p = zorba::getZorbaForCurrentThread()->get_data_manager();
	const qname* qn_p = dmgr_p->get_qname(rep->docuri());
	return new SingletonIterator(loc,(item*)qn_p);
}

iterator_t zorba_document_node::children(
	yy::location &loc) const
{
	return new child_iterator(*this,loc);
}

iterator_t zorba_document_node::typed_value(
	yy::location &loc) const
{
	return new SingletonIterator(loc,new stringValue(rep->str()));
}

iterator_t zorba_document_node::atomized_value(
	yy::location &loc) const
{
	return new SingletonIterator(loc,new stringValue(rep->str()));
}

ostream& zorba_document_node::put(
	ostream& os) const
{
	rep->put(os);
	return os;
}

string zorba_document_node::describe() const
{
	ostringstream oss;
	oss << "doc(" << get_base_uri() << ")";
	return oss.str();
}


// internal interface		
// (stubs for now)
string zorba_document_node::str() const 
{
	return "";
}

string zorba_document_node::get_base_uri() const
{
	return "";
}

string zorba_document_node::get_document_uri() const
{
	return "";
}

string zorba_document_node::get_typed_value() const
{
	return "";
}

const qname* zorba_document_node::get_type_name() const
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
	yy::location &loc) const
{
	return new SingletonIterator(loc,new stringValue(rep->str()));
}

iterator_t zorba_element_node::base_uri(
	yy::location &loc) const
{
	const node* n_p = get_parent();
	//d Assert<null_pointer>(n_p!=NULL);
	Assert(n_p!=NULL);
	return n_p->base_uri(loc);
}

iterator_t zorba_element_node::type_name(
	yy::location &loc) const
{
	const qname* qn_p = get_type_name();
	//d Assert<null_pointer>(qn_p!=NULL);
	Assert(qn_p!=NULL);
	return new SingletonIterator(loc,(item*)qn_p);
}

iterator_t zorba_element_node::node_name(
	yy::location &loc) const
{
	const qname* qn_p = get_node_name();
	//d Assert<null_pointer>(qn_p!=NULL);
	Assert(qn_p!=NULL);
	return new SingletonIterator(loc,(item*)qn_p);
}

iterator_t zorba_element_node::parent(
	yy::location &loc) const
{
	const node* n_p = get_parent();
	//d Assert<null_pointer>(n_p!=NULL);
	Assert(n_p!=NULL);
	return new SingletonIterator(loc,(item*)n_p);
}

iterator_t zorba_element_node::typed_value(
	yy::location &loc) const
{
	return string_value(loc);
}

iterator_t zorba_element_node::atomized_value(
	yy::location &loc) const
{
	return string_value(loc);
}

iterator_t zorba_element_node::attributes(
	yy::location &loc) const
{
	return new attribute_iterator(*this,loc);
}

iterator_t zorba_element_node::children(
	yy::location &loc) const
{
	return new child_iterator(*this,loc);
}

iterator_t zorba_element_node::namespace_nodes(
	yy::location &loc) const
{
	return new namespace_iterator(*this,loc);
}

// internal interface
string zorba_element_node::str() const { return ""; }
string zorba_element_node::get_base_uri() const { return ""; }
string zorba_element_node::get_document_uri() const { return ""; }
string zorba_element_node::get_typed_value() const { return ""; }
const qname* zorba_element_node::get_node_name() const { return 0; }
const qname* zorba_element_node::get_type_name() const { return 0; }

const node* zorba_element_node::get_parent() const
{
	data_manager* dmgr_p = zorba::getZorbaForCurrentThread()->get_data_manager();
	const node* p = dmgr_p->get_node(rep->parentid());

	switch (p->type()) {
	case documentNode: {
		document_noderep* q = new(p) document_noderep();
		//d Assert<null_pointer>(q!=NULL);
		Assert(q!=NULL);
		return new zorba_document_node(q);
	}
	case elementNode: {
		element_noderep* q = new (p) element_noderep();
		//d Assert<null_pointer>(q!=NULL);
		Assert(q!=NULL);
		return new zorba_element_node(q);
	}
	default: {
		return NULL;
	}}
}

// debugging, output
ostream& zorba_element_node::put(
	ostream& os) const
{
	rep->put(os);
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
	yy::location &loc) const
{
	return new SingletonIterator(loc,new stringValue(rep->str()));
}

iterator_t zorba_attribute_node::base_uri(
	yy::location &loc) const
{
	const node* n_p = get_parent();
	//d Assert<null_pointer>(n_p!=NULL);
	Assert(n_p!=NULL);
	return n_p->base_uri(loc);
}

iterator_t zorba_attribute_node::type_name(
	yy::location &loc) const
{
	const qname* qn_p = get_type_name();
	//d Assert<null_pointer>(qn_p!=NULL);
	Assert(qn_p!=NULL);
	return new SingletonIterator(loc,(item*)qn_p);
}

iterator_t zorba_attribute_node::node_name(
	yy::location &loc) const
{
	const qname* qn_p = get_node_name();
	//d Assert<null_pointer>(qn_p!=NULL);
	Assert(qn_p!=NULL);
	return new SingletonIterator(loc,(item*)qn_p);
}

iterator_t zorba_attribute_node::parent(
	yy::location &loc) const
{
	const node* n_p = get_parent();
	//d Assert<null_pointer>(n_p!=NULL);
	Assert(n_p!=NULL);
	return new SingletonIterator(loc,(item*)n_p);
}

iterator_t zorba_attribute_node::typed_value(
	yy::location &loc) const
{
	return string_value(loc);
}

iterator_t zorba_attribute_node::atomized_value(
	yy::location &loc) const
{
	return string_value(loc);
}

// internal interface

ostream& zorba_attribute_node::put(
	ostream& os) const
{
	rep->put(os);
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
	yy::location &loc) const
{
	return new SingletonIterator(loc,new stringValue(rep->uri()));
}

iterator_t zorba_namespace_node::node_name(
	yy::location &loc) const
{
	return new SingletonIterator(loc,new stringValue(rep->prefix()));
}

iterator_t zorba_namespace_node::typed_value(
	yy::location &loc) const
{
	return string_value(loc);
}

iterator_t zorba_namespace_node::atomized_value(
	yy::location &loc) const
{
	return string_value(loc);
}

// internal iterface

ostream& zorba_namespace_node::put(
	ostream& os) const
{
	rep->put(os);
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
	yy::location &loc) const 
{
	return new SingletonIterator(loc,new stringValue(rep->content()));
}

iterator_t zorba_pi_node::typed_value(
	yy::location &loc) const
{
	return string_value(loc);
}

iterator_t zorba_pi_node::atomized_value(
	yy::location &loc) const
{
	return string_value(loc);
}

iterator_t zorba_pi_node::base_uri(
	yy::location &loc) const
{
	const node* n_p = get_parent();
	//d Assert<null_pointer>(n_p!=NULL);
	Assert(n_p!=NULL);
	return n_p->base_uri(loc);
}

iterator_t zorba_pi_node::node_name(
	yy::location &loc) const
{
	const qname* qn_p = get_node_name();
	//d Assert<null_pointer>(qn_p!=NULL);
	Assert(qn_p!=NULL);
	return new SingletonIterator(loc,(item*)qn_p);
}

iterator_t zorba_pi_node::parent(
	yy::location &loc) const
{
	const node* n_p = get_parent();
	//d Assert<null_pointer>(n_p!=NULL);
	Assert(n_p!=NULL);
	return new SingletonIterator(loc,(item*)n_p);
}


// internal interface

ostream& zorba_pi_node::put(
	ostream& os) const
{
	rep->put(os);
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
	yy::location &loc) const
{
	return new SingletonIterator(loc,new stringValue(rep->str()));
}

iterator_t zorba_comment_node::base_uri(
	yy::location &loc) const
{
	const node* n_p = get_parent();
	//d Assert<null_pointer>(n_p!=NULL);
	Assert(n_p!=NULL);
	return n_p->base_uri(loc);
}

iterator_t zorba_comment_node::typed_value(
	yy::location &loc) const
{
	return new SingletonIterator(loc,(item*)this);
}

iterator_t zorba_comment_node::atomized_value(
	yy::location &loc) const
{
	return string_value(loc);
}

// internal interface

string zorba_comment_node::str() const
{
	return rep->str();
}

ostream& zorba_comment_node::put(
	ostream& os) const
{
	return os << "<!--" << rep->str() << "-->";
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
	yy::location &loc) const
{
	return new SingletonIterator(loc,new stringValue(rep->str()));
}

iterator_t zorba_text_node::base_uri(
	yy::location &loc) const
{
	const node* n_p = get_parent();
	//d Assert<null_pointer>(n_p!=NULL);
	Assert(n_p!=NULL);
	return n_p->base_uri(loc);
}

iterator_t zorba_text_node::typed_value(
	yy::location &loc) const
{
	return string_value(loc);
}

iterator_t zorba_text_node::atomized_value(
	yy::location &loc) const
{
	return string_value(loc);
}

// internal interface

ostream& zorba_text_node::put(
	ostream& os) const
{
	return os << rep->str();
}


}	/* namespace xqp */

