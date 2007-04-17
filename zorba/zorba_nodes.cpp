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
// -----------------

zorba_document_node::zorba_document_node()
{}
	
zorba_document_node::zorba_document_node(
	zorba_document_node& dn)
{}

string zorba_document_node::string_value() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}

iterator_t zorba_document_node::base_uri() const
{ return new zorba_singleton_iterator(baseuri()); }

iterator_t zorba_document_node::document_uri() const
{ return new zorba_singleton_iterator(docuri()); }

iterator_t zorba_document_node::children() const
{ return new child_iterator(this); }

iterator_t zorba_document_node::typed_value() const
{ return new singleton_iterator(string_value()); }

ostream& zorba_document_node::put(ostream& os) const
{
	iterator_t it = children();
	while (!it->done()) {
	node* n_p = it->next();
		os << n_p->string_value();
	}
	return os;
}



// zorba_element_node
// ----------------

zorba_element_node::zorba_element_node(
	zorba_qname* _qname_p,
	atomic_value* _value_p)
:
	qname_p(_qname_p),
	value_p(_value_p),
	id_b(false),
	idrefs_b(false)
{}


zorba_element_node::zorba_element_node(
	const zorba_element_node& en)
:
	qname_p(en.qname_p),
	value_p(en.value_p),
	nsv(en.nsv),
	attrv(en.attrv),
	childv(en.childv),
	id_b(en.id_b),
	idrefs_b(en.idrefs_b)
{}


std::string zorba_element_node::string_value() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}

iterator_t zorba_element_node::attributes() const
{ return new attribute_iterator(this); }

iterator_t zorba_element_node::base_uri() const
{ return parent_p->base_uri(); }

iterator_t zorba_element_node::document_uri() const
{ return parent_p ? parent_p->document_uri() : NULL; }

iterator_t zorba_element_node::children() const
{ return new child_iterator(this); }

iterator_t zorba_element_node::namespace_nodes() const
{ return new namespace_iterator(this); }

iterator_t zorba_element_node::node_name() const
{ return new singleton_iterator(qname_p); }

iterator_t zorba_element_node::typed_value() const
{
	if (value_p) {
		return new singleton_iterator(value_p);
	} else {
		return new singleton_iterator(string_value());
	}
}

ostream& zorba_element_node::put(
	ostream& os) const
{
  os << '[' << childv.size() << ']';
	os << '<';
	qname_p->put(os);

	if (nsv.size() + attrv.size() > 0) os << ' ';
	vector<zorba_namespace_node*>::const_iterator ns_it = nsv.begin();
	for (; ns_it!=nsv.end(); ++ns_it) {
		(*ns_it)->put(os) << ' ';
	}
	vector<zorba_attribute_node*>::const_iterator at_it = attrv.begin();
	for (; at_it!=attrv.end(); ++at_it) {
		(*at_it)->put(os) << ' ';
	}
	os << '>';
	vector<zorba_node*>::const_iterator nd_it = childv.begin();
	for (; nd_it!=childv.end(); ++nd_it) {
		(*nd_it)->put(os);
	}
	os << "</";
	qname_p->put(os);
	return os << '>';
}



// zorba_attribute_node
// ------------------

zorba_attribute_node::zorba_attribute_node(
	zorba_qname* _qname_p,
	const std::string& _value,
	bool _id_b,
	bool _idrefs_b)
:
	qname_p(_qname_p),
	value(_value),
	id_b(_id_b),
	idrefs_b(_idrefs_b)
{}

zorba_attribute_node::zorba_attribute_node(
	zorba_attribute_node& an)
:
	qname_p(an.qname_p),
	value(an.value),
	id_b(an.id_b),
	idrefs_b(an.idrefs_b)
{}

iterator_t zorba_attribute_node::base_uri() const
{ return parent_p ? parent_p->base_uri() : NULL; }

iterator_t zorba_attribute_node::node_name() const
{ return new singleton_iterator(qname_p); }

iterator_t zorba_attribute_node::typed_value() const
{ return new singleton_iterator(value); }

string zorba_attribute_node::string_value() const
{ return value; }

ostream& zorba_attribute_node::put(
	ostream& os) const
{
	qname_p->put(os);
	return os << "=\"" << value << "\"";
}




// zorba_namespace_node
// ------------------

zorba_namespace_node::zorba_namespace_node(
	const std::string& prefix,
	const std::string& uri)
:
	iprefix(prefix),
	iuri(uri)
{}

zorba_namespace_node::zorba_namespace_node(
	zorba_namespace_node& nn)
:
	iprefix(nn.iprefix),
	iuri(nn.iuri)
{}

iterator_t zorba_namespace_node::node_name() const
{ return new singleton_iterator(new zorba_qname("","",iprefix)); }

iterator_t zorba_namespace_node::typed_value() const
{ return NULL; }

string zorba_namespace_node::string_value() const
{ return iuri; }

std::ostream& zorba_namespace_node::put(std::ostream& os) const
{ return os << "xmlns:" << iprefix << "=\"" << iuri << "\""; }




// zorba_pi_node
// -----------

zorba_pi_node::zorba_pi_node(
	const string& target,
	const string& content)
:
	itarget(target),
	icontent(content)
{}

zorba_pi_node::zorba_pi_node(const zorba_pi_node& pn)
:
	itarget(pn.itarget),
	icontent(pn.icontent)
{}

string zorba_pi_node::string_value() const 
{ return icontent; }

iterator_t zorba_pi_node::base_uri() const
{ return parent_p ? parent_p->base_uri() : NULL; }

iterator_t zorba_pi_node::typed_value() const
{ return new singleton_iterator(icontent); }

iterator_t zorba_pi_node::node_name() const
{ return new singleton_iterator(itarget); }

std::ostream& zorba_pi_node::put(std::ostream& os) const
{ return os << "<?" << itarget << ' ' << icontent << "?>"; }




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

iterator_t zorba_comment_node::base_uri() const
{ return parent_p ? parent_p->base_uri() : NULL; }

iterator_t zorba_comment_node::typed_value() const
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

iterator_t zorba_text_node::base_uri() const
{ return parent_p ? parent_p->base_uri() : NULL; }

iterator_t zorba_text_node::typed_value() const
{ return new singleton_iterator(the_content); }

ostream& zorba_text_node::put(ostream& os) const
{ return os << the_content; }


}	/* namespace xqp */

