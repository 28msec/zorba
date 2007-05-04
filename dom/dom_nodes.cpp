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
#include "runtime/singleton_iterators.h"
#include "values/primitive_values.h"

namespace xqp {


// dom_node
// --------

// XQuery interface
iterator_t dom_node::parent(
	zorba* zorp) const
{
	return new node_singleton(parent_p);
}


// internal interface
string dom_node::get_base_uri(
	zorba* zorp) const
{
	return parent_p ? parent_p->get_base_uri(zorp) : "";
}

string dom_node::get_document_uri(
	zorba* zorp) const
{
	return parent_p ? parent_p->get_document_uri(zorp) : "";
}


// XQuery interface
iterator_t dom_node::string_value(
	zorba* zorp) const
{
	return new string_singleton(stringValue(str(zorp)));
}

iterator_t dom_node::base_uri(
	zorba* zorp) const
{
	return new string_singleton(stringValue(get_base_uri(zorp)));
}

iterator_t dom_node::document_uri(
	zorba* zorp) const
{
	return new string_singleton(stringValue(get_document_uri(zorp)));
}



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

// XQuery interface
iterator_t dom_document_node::children(
	zorba* zorp) const
{
	return new dom_child_iterator(*this);
}

iterator_t dom_document_node::typed_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

iterator_t dom_document_node::atomized_value(
	zorba* zorp) const
{
	return string_value(zorp);
}


// internal interface
string dom_document_node::str(
	zorba* zorp) const 
{
	ostringstream oss;
	iterator_t it = children(zorp);
	for (; !it->done(); ++(*it)) {
		const dom_node& dn = dynamic_cast<const dom_node&>(**it);
		oss << dn.str(zorp);
	}
	return oss.str();
}

string dom_document_node::get_base_uri(
	zorba* zorp) const
{
	return theBaseURI;
}

string dom_document_node::get_document_uri(
	zorba* zorp) const
{
	return theDocURI;
}

string dom_document_node::get_typed_value(
	zorba* zorp) const
{
	return str(zorp);
}

const qname* dom_document_node::get_type_name(
	zorba* zorp) const
{
	return 0;
}

// output, serialization
ostream& dom_document_node::put(
	zorba* zorp,
	ostream& os) const
{
	iterator_t it = children(zorp);
	for (; !it->done(); ++(*it)) {
		const dom_node& dn = dynamic_cast<const dom_node&>(**it);
		os << dn.str(zorp);
	}
	return os;
}

string dom_document_node::toXML(
	zorba* zorp) const
{
	ostringstream oss;
	iterator_t it = children(zorp);
	for (; !it->done(); ++(*it)) {
		const dom_node& dn = dynamic_cast<const dom_node&>(**it);
		oss << dn.toXML(zorp);
	}
	return oss.str();
}

string dom_document_node::describe(
	zorba* zorp) const
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


// internal interface
std::string dom_element_node::str(
	zorba* zorp) const
{
	ostringstream oss;
	iterator_t it = children(zorp);
	for (; !it->done(); ++(*it)) {
		const dom_node& dn = dynamic_cast<const dom_node&>(**it);
		oss << dn.str(zorp);
	}
	return oss.str();
}

string dom_element_node::get_typed_value(
	zorba* zorp) const
{
	return str(zorp);
}

const qname* dom_element_node::get_type_name(
	zorba* zorp) const
{
	return 0;
}

void dom_element_node::add_namespace(
	dom_namespace_node* ns_p)
{
	nsv.push_back(ns_p);
}

void dom_element_node::add_attribute(
	dom_attribute_node* at_p)
{
	attrv.push_back(at_p);
}

void dom_element_node::add_child(
	dom_node* n_p)
{
	childv.push_back(n_p);
}


// XQuery interface
iterator_t dom_element_node::node_name(
	zorba* zorp) const
{
	return new qname_singleton(qname_p);
}

iterator_t dom_element_node::typed_value(
	zorba* zorp) const
{
	if (value_p) {
		return new item_singleton(value_p);
	} else {
		return string_value(zorp);
	}
}

iterator_t dom_element_node::attributes(
	zorba* zorp) const
{
	return new dom_attribute_iterator(*this);
}

iterator_t dom_element_node::children(
	zorba* zorp) const
{
	return new dom_child_iterator(*this);
}

iterator_t dom_element_node::namespace_nodes(
	zorba* zorp) const
{
	return new dom_namespace_iterator(*this);
}


// output, serialization
ostream& dom_element_node::put(
	zorba* zorp,
	ostream& os) const
{
  os << '[' << childv.size() << ']';
	os << '<';
	qname_p->put(zorp,os);

	if (nsv.size() + attrv.size() > 0) os << ' ';
	vector<dom_node*>::const_iterator ns_it = nsv.begin();
	for (; ns_it!=nsv.end(); ++ns_it) {
		(*ns_it)->put(zorp,os) << ' ';
	}
	vector<dom_node*>::const_iterator at_it = attrv.begin();
	for (; at_it!=attrv.end(); ++at_it) {
		(*at_it)->put(zorp,os) << ' ';
	}
	os << '>';
	vector<dom_node*>::const_iterator nd_it = childv.begin();
	for (; nd_it!=childv.end(); ++nd_it) {
		(*nd_it)->put(zorp,os);
	}
	os << "</";
	qname_p->put(zorp,os);
	return os << '>';
}

string dom_element_node::toXML(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}

string dom_element_node::describe(
	zorba* zorp) const
{
	ostringstream oss;
	get_node_name(zorp)->put(oss);
	return oss.str();
}



// dom_attribute_node
// ------------------

dom_attribute_node::dom_attribute_node(
	dom_qname* _qname_p,
	const std::string& _value,
	bool _id_b,
	bool _idrefs_b)
:
	qname_p(_qname_p),
	value(_value),
	id_b(_id_b),
	idrefs_b(_idrefs_b)
{}

dom_attribute_node::dom_attribute_node(
	dom_attribute_node& an)
:
	qname_p(an.qname_p),
	value(an.value),
	id_b(an.id_b),
	idrefs_b(an.idrefs_b)
{}


// internal interface
string dom_attribute_node::str(
	zorba* zorp) const
{
	return value;
}

string dom_attribute_node::get_typed_value(
	zorba* zorp) const
{
	return value;
}

const qname* dom_attribute_node::get_node_name(
	zorba* zorp) const
{
	return qname_p;
}

const qname* dom_attribute_node::get_type_name(
	zorba* zorp) const
{
	return 0;
}


// XQuery interface
iterator_t dom_attribute_node::node_name(
	zorba* zorp) const
{
	return new qname_singleton(qname_p);
}

iterator_t dom_attribute_node::typed_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

iterator_t dom_attribute_node::type_name(
	zorba* zorp) const
{
	return 0;
}

iterator_t dom_attribute_node::atomized_value(
	zorba* zorp) const
{
	return string_value(zorp);
}


// output, serialization
ostream& dom_attribute_node::put(
	zorba* zorp,
	ostream& os) const
{
	qname_p->put(zorp,os);
	return os << "=\"" << value << "\"";
}

string dom_attribute_node::toXML(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}

string dom_attribute_node::describe(
	zorba* zorp) const
{
	ostringstream oss;
	qname_p->put(zorp,oss);
	return "@"+oss.str();
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


// internal interface
string dom_namespace_node::str(
	zorba* zorp) const
{
	return theURI;
}

const qname* dom_namespace_node::get_node_name(
	zorba* zorp) const
{
	return NULL;
}

string dom_namespace_node::get_typed_value(
	zorba* zorp) const
{
	return "";
}


// XQuery interface
iterator_t dom_namespace_node::node_name(
	zorba* zorp) const
{
	return new qname_singleton(get_node_name(zorp));
}

iterator_t dom_namespace_node::typed_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

iterator_t dom_namespace_node::atomized_value(
	zorba* zorp) const
{
	return string_value(zorp);
}


// output, serialization
std::ostream& dom_namespace_node::put(
	zorba* zorp,
	std::ostream& os) const
{
	return os << "xmlns:" << thePrefix << "=\"" << theURI << "\"";
}

string dom_namespace_node::toXML(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}

string dom_namespace_node::describe(
	zorba* zorp) const
{
	return toXML(zorp);
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


// internal interface
string dom_pi_node::str(
	zorba* zorp) const 
{
	return theContent;
}

string dom_pi_node::get_typed_value(
	zorba* zorp) const
{
	return theContent;
}

const qname* dom_pi_node::get_node_name(
	zorba* zorp) const
{
	return NULL;
}


// XQuery interface
iterator_t dom_pi_node::typed_value(
	zorba* zorp) const
{
	return string_value(zorp);
}

iterator_t dom_pi_node::node_name(
	zorba* zorp) const
{
	return NULL;
}

iterator_t dom_pi_node::atomized_value(
	zorba* zorp) const
{
	return string_value(zorp);
}


// output, serialization
std::ostream& dom_pi_node::put(
	zorba* zorp,
	std::ostream& os) const
{
	return os << "<?" << theTarget << ' ' << theContent << "?>";
}

string dom_pi_node::toXML(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}

string dom_pi_node::describe(
	zorba* zorp) const
{
	return toXML(zorp);
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


// internal interface
string dom_comment_node::str(
	zorba* zorp) const
{
	return theContent;
}

string dom_comment_node::get_typed_value(
	zorba* zorp) const
{
	return theContent;
}


// XQuery interface
iterator_t dom_comment_node::typed_value(
	zorba* zorp) const
{
	return string_value(zorp);
}


// output, serialization
std::ostream& dom_comment_node::put(
	zorba* zorp,
	std::ostream& os) const
{
	return os << "<!--" << theContent << "-->";
}

string dom_comment_node::toXML(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}

string dom_comment_node::describe(
	zorba* zorp) const
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


// internal interface
string dom_text_node::str(
	zorba* zorp) const
{
	return theContent;
}

string dom_text_node::get_typed_value(
	zorba* zorp) const
{
	return str(zorp);
}


// XQuery interface
iterator_t dom_text_node::typed_value(
	zorba* zorp) const
{
	return string_value(zorp);
}


// output, serialization
ostream& dom_text_node::put(
	zorba* zorp,
	ostream& os) const
{
	return os << theContent;
}

string dom_text_node::toXML(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	return oss.str();
}

string dom_text_node::describe(
	zorba* zorp) const
{
	return toXML(zorp);
}


}	/* namespace xqp */

