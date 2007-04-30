/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: zorba_nodes.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "zorba_nodes.h"

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
	rep(dn.rep)
{
}

iterator_t zorba_document_node::string_value(zorba*) const
{
	return new singleton_iterator(rep->strval());
}

iterator_t zorba_document_node::base_uri(zorba*) const
{
	itemid_t id = rep->baseuri();
	return new singleton_iterator(zorba->get_uri(id));
}

iterator_t zorba_document_node::document_uri(zorba*) const
{
	itemid_t id = rep->docuri();
	return new singleton_iterator(zorba->get_uri(id));
}

iterator_t zorba_document_node::children(zorba*) const
{
	return new child_iterator(this);
}

iterator_t zorba_document_node::typed_value(zorba*) const
{
	return string_value();
}

ostream& zorba_document_node::put(ostream& os) const
{
	rep->put(os);
	return os;
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
	rep(en.rep)
{
}

iterator_t zorba_element_node::string_value() const
{
	return new singleton_iterator(rep->strval());
}

iterator_t zorba_element_node::base_uri(
	zorba* zorp) const
{
	node* n_p = zorp->get_store()->get_node(parentid());
	return (n_p ? n_p->base_uri(zorp) : NULL);
}

iterator_t zorba_element_node::type_name(
	zorba*) const
{
	itemid_t id = rep->typeID();
	itemstore* istore = reinterpret_cast<itemstore*>(zorp->get_store());
	Assert<NullPointer>(istore!=NULL, "storage manager NULL");
	const qnameRep* p = istore->get_qnamerep(id);
	return new qname_singleton(new zorba_qname(*p));
}

iterator_t zorba_element_node::node_name(zorba*) const
{
	const qname* p = rep->node_name();
	return new qname_singleton(*p);
}

iterator_t zorba_element_node::parent(
	zorba*) const
{
	itemid_t id = rep->parentid();
	itemstore* istore = reinterpret_cast<itemstore*>(zorp->get_store());
	Assert<NullPointer>(istore!=NULL, "storage manager NULL");
	const noderep* p = istore->get_noderep(id);
	switch (p->type()) {
	case documentNode: {
		document_noderep* q = reinterpret_cast<document_noderep*>(p)
		return new singleton_iterator(new zorba_document_node(q));
	}
	case elementNode: {
		element_noderep* q = reinterpret_cast<element_noderep*>(p)
		return new singleton_iterator(new zorba_element_node(q));
	}
	default: }
		return NULL;
	}}
}

iterator_t zorba_element_node::typed_value() const
{
	return string_value();
}

iterator_t zorba_element_node::attributes(zorba*) const
{
	return new attribute_iterator(this);
}

iterator_t zorba_element_node::children(zorba*) const
{
	return new child_iterator(this);
}

iterator_t zorba_element_node::namespace_nodes(zorba*) const
{
	return new namespace_iterator(this);
}

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
	rep(an.rep)
{
}

string zorba_attribute_node::string_value() const
{
	return new singleton_iterator(rep->strval());
}

iterator_t zorba_attribute_node::base_uri(zorba*) const
{
	return new singleton_iterator(rep->baseuri());
}

iterator_t zorba_attribute_node::node_name(zorba*) const
{
	const qname* p = rep->node_name();
	return new qname_singleton(*p);
}

iterator_t zorba_attribute_node::typed_value(zorba*) const
{
	return string_value();
}

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
	rep(nn.rep)
{
}

string zorba_namespace_node::string_value() const
{
	return new singleton_iterator(rep->uri());
}

iterator_t zorba_namespace_node::node_name(zorba*) const
{
	return new singleton_iterator(rep->prefix());
}

iterator_t zorba_namespace_node::typed_value(zorba*) const
{
	return string_value();
}

std::ostream& zorba_namespace_node::put(std::ostream& os) const
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
	rep(pn.rep)
{
}

string zorba_pi_node::string_value() const 
{
	return new singleton_iterator(rep->content());
}

iterator_t zorba_pi_node::base_uri(zorba*) const
{
	return new singleton_iterator(rep->baseuri());
}

iterator_t zorba_pi_node::node_name(zorba*) const
{
	return new singleton_iterator(rep->target());
}

iterator_t zorba_pi_node::typed_value(zorba*) const
{
	return string_value();
}

std::ostream& zorba_pi_node::put(std::ostream& os) const
{
	rep->put(os);
	return os;
}




// zorba_comment_node
// ----------------

zorba_comment_node::zorba_comment_node(
	const string& content)
: the_content(content) {}

zorba_comment_node::zorba_comment_node(
	const zorba_comment_node& cn)
: the_content(cn.the_content) {}

string zorba_comment_node::string_value() const
{ return the_content; }

iterator_t zorba_comment_node::base_uri(zorba*) const
{ return parent_p ? parent_p->base_uri() : NULL; }

iterator_t zorba_comment_node::typed_value(zorba*) const
{ return new singleton_iterator(this); }

std::ostream& zorba_comment_node::put(std::ostream& os) const
{ return os << "<!--" << the_content << "-->"; }




// zorba_text_node
// -------------

zorba_text_node::zorba_text_node(
	const string& content)
: the_content(content) {}

zorba_text_node::zorba_text_node(
	const zorba_text_node& tn) 
: the_content(tn.the_content) {}

string zorba_text_node::string_value() const
{ return the_content; }

iterator_t zorba_text_node::base_uri(zorba*) const
{ return parent_p ? parent_p->base_uri() : NULL; }

iterator_t zorba_text_node::typed_value(zorba*) const
{ return new singleton_iterator(the_content); }

ostream& zorba_text_node::put(ostream& os) const
{ return os << the_content; }


}	/* namespace xqp */

