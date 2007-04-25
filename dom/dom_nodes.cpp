/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dom_nodes.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "dom_nodes.h"
#include "runtime/item_iterator.h"

namespace xqp {

// dom_document_node
// -----------------

dom_document_node::dom_document_node(
	const std::string& baseuri,
	const std::string& docuri)
:
	theBaseURI(baseuri),
	theDocURI(docuri)
{}
	
dom_document_node::dom_document_node(
	dom_document_node::dom_document_node& dn)
:
	theBaseURI(dn.theBaseURI),
	theDocURI(dn.theDocURI)
{}

string dom_document_node::string_value() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}

iterator_t dom_document_node::children(
	dynamic_context* dctx_p) const
{
	return new child_iterator(dctx_p,this);
}

iterator_t dom_document_node::children() const
{
	return new child_const_iterator(this);
}

rchandle<item> dom_document_node::typed_value() const
{
	return new stringValue(string_value());
}

ostream& dom_document_node::put(ostream& os) const
{
	iterator_t it = children();
	for (; !it->done(); ++(*it)) {
		const dom_node& dn = dynamic_cast<const dom_node&>(**it);
		os << dn.string_value();
	}
	return os;
}

string dom_document_node::toXML() const
{
	return describe();
}

string dom_document_node::describe() const
{
	return "doc("+theBaseURI+theDocURI+")";
}



// dom_element_node
// ----------------

dom_element_node::dom_element_node(
	dom_qname* _qname_p,
	atomic_value* _value_p)
:
	qname_p(_qname_p),
	value_p(_value_p),
	id_b(false),
	idref_b(false)
{}


dom_element_node::dom_element_node(
	const dom_element_node& en)
:
	qname_p(en.qname_p),
	value_p(en.value_p),
	nsv(en.nsv),
	attrv(en.attrv),
	childv(en.childv),
	id_b(en.id_b),
	idref_b(en.idref_b)
{}


std::string dom_element_node::string_value() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}

void dom_element_node::add_namespace(dom_namespace_node* ns_p)
{
	nsv.push_back(ns_p);
}

void dom_element_node::add_attribute(dom_attribute_node* at_p)
{
	attrv.push_back(at_p);
}

void dom_element_node::add_child(dom_node* n_p)
{
	childv.push_back(n_p);
}

iterator_t dom_element_node::attributes(
	dynamic_context* dctx_p) const
{
	return new attribute_iterator(this);
}

string dom_element_node::base_uri() const
{
	return parent_p->base_uri();
}

string dom_element_node::document_uri() const
{
	return parent_p ? parent_p->document_uri() : "";
}

iterator_t dom_element_node::children(
	dynamic_context* dctx_p) const
{
	return new child_iterator(this);
}

iterator_t dom_element_node::namespace_nodes(
	dynamic_context* dctx_p) const
{
	return new namespace_iterator(this);
}

rchandle<qname> dom_element_node::node_name() const
{
	return qname_p;
}

rchandle<item> dom_element_node::typed_value() const
{
	if (value_p) {
		return value_p;
	} else {
		return new stringValue(string_value());
	}
}

ostream& dom_element_node::put(
	ostream& os) const
{
  os << '[' << childv.size() << ']';
	os << '<';
	qname_p->put(os);

	if (nsv.size() + attrv.size() > 0) os << ' ';
	vector<dom_node*>::const_iterator ns_it = nsv.begin();
	for (; ns_it!=nsv.end(); ++ns_it) {
		(*ns_it)->put(os) << ' ';
	}
	vector<dom_node*>::const_iterator at_it = attrv.begin();
	for (; at_it!=attrv.end(); ++at_it) {
		(*at_it)->put(os) << ' ';
	}
	os << '>';
	vector<dom_node*>::const_iterator nd_it = childv.begin();
	for (; nd_it!=childv.end(); ++nd_it) {
		(*nd_it)->put(os);
	}
	os << "</";
	qname_p->put(os);
	return os << '>';
}

string dom_element_node::toXML() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}

string dom_element_node::describe() const
{
	return "";
}



// dom_attribute_node
// ------------------

dom_attribute_node::dom_attribute_node(
	dom_qname* _qname_p,
	const std::string& _value,
	bool _id_b,
	bool _idref_b)
:
	qname_p(_qname_p),
	value(_value),
	id_b(_id_b),
	idref_b(_idref_b)
{}

dom_attribute_node::dom_attribute_node(
	dom_attribute_node& an)
:
	qname_p(an.qname_p),
	value(an.value),
	id_b(an.id_b),
	idref_b(an.idref_b)
{}

string dom_attribute_node::base_uri() const
{
	return parent_p ? parent_p->base_uri() : "";
}

rchandle<qname> dom_attribute_node::node_name() const
{
	return qname_p;
}

rchandle<item> dom_attribute_node::typed_value() const
{
	return new stringValue(value);
}

string dom_attribute_node::string_value() const
{
	return value;
}

ostream& dom_attribute_node::put(
	ostream& os) const
{
	qname_p->put(os);
	return os << "=\"" << value << "\"";
}

string dom_attribute_node::toXML() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}

string dom_attribute_node::describe() const
{
	return "";
}



// dom_namespace_node
// ------------------
dom_namespace_node::dom_namespace_node(
	const std::string& prefix,
	const std::string& uri)
:
	thePrefix(prefix),
	theURI(uri)
{
}

dom_namespace_node::dom_namespace_node(
	dom_namespace_node& nn)
:
	thePrefix(nn.thePrefix),
	theURI(nn.theURI)
{
}

rchandle<qname> dom_namespace_node::node_name() const
{
	return new dom_qname("","",thePrefix);
}

rchandle<item> dom_namespace_node::typed_value() const
{
	return NULL;
}

string dom_namespace_node::string_value() const
{
	return theURI;
}

std::ostream& dom_namespace_node::put(
	std::ostream& os) const
{
	return os << "xmlns:" << thePrefix << "=\"" << theURI << "\"";
}

string dom_namespace_node::toXML() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}

string dom_namespace_node::describe() const
{
	return "";
}



// dom_pi_node
// -----------
dom_pi_node::dom_pi_node(
	const string& target,
	const string& content)
:
	theTarget(target),
	theContent(content)
{}

dom_pi_node::dom_pi_node(
	const dom_pi_node& pn)
:
	theTarget(pn.theTarget),
	theContent(pn.theContent)
{}

string dom_pi_node::string_value() const 
{
	return theContent;
}

string dom_pi_node::base_uri() const
{
	return parent_p ? parent_p->base_uri() : "";
}

rchandle<item> dom_pi_node::typed_value() const
{
	return new stringValue(theContent);
}

rchandle<qname> dom_pi_node::node_name() const
{
	return NULL;
}

std::ostream& dom_pi_node::put(
	std::ostream& os) const
{
	return os << "<?" << theTarget << ' ' << theContent << "?>";
}

string dom_pi_node::toXML() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}

string dom_pi_node::describe() const
{
	return "";
}


// dom_comment_node
// ----------------
dom_comment_node::dom_comment_node(
	const string& content)
:
	theContent(content)
{
}

dom_comment_node::dom_comment_node(
	const dom_comment_node& cn)
:
	theContent(cn.theContent)
{
}

string dom_comment_node::string_value() const
{
	return theContent;
}

string dom_comment_node::base_uri() const
{
	return parent_p ? parent_p->base_uri() : "";
}

rchandle<item> dom_comment_node::typed_value() const
{
	return new stringValue(theContent);
}

std::ostream& dom_comment_node::put(
	std::ostream& os) const
{
	return os << "<!--" << theContent << "-->";
}

string dom_comment_node::toXML() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}

string dom_comment_node::describe() const
{
	return "";
}


// dom_text_node
// -------------
dom_text_node::dom_text_node(
	const string& content)
: theContent(content) {}

dom_text_node::dom_text_node(
	const dom_text_node& tn) 
: theContent(tn.theContent) {}

string dom_text_node::string_value() const
{
	return theContent;
}

string dom_text_node::base_uri() const
{
	return parent_p ? parent_p->base_uri() : "";
}

rchandle<item> dom_text_node::typed_value() const
{
	return new stringValue(theContent);
}

ostream& dom_text_node::put(ostream& os) const
{
	return os << theContent;
}

string dom_text_node::toXML() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}

string dom_text_node::describe() const
{
	return "";
}


}	/* namespace xqp */

