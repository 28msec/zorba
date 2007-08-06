/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: dom_nodes.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "dom_nodes.h"
#include "runtime/item_iterator.h"
#include "values/primitive_values.h"
#include "runtime/zorba.h"

namespace xqp {


// dom_node
// --------

// XQuery interface
iterator_t dom_node::parent(
	yy::location &loc) const
{
	return new SingletonIterator(loc, (item*)parent_p);
}


// internal interface
string dom_node::get_base_uri() const
{
	return parent_p ? parent_p->get_base_uri() : "";
}

string dom_node::get_document_uri() const
{
	return parent_p ? parent_p->get_document_uri() : "";
}


// XQuery interface
iterator_t dom_node::string_value(yy::location &loc) const
{
	return new SingletonIterator(loc, new stringValue(str()));
}

iterator_t dom_node::base_uri(yy::location &loc) const
{
	return new SingletonIterator(loc, new stringValue(get_base_uri()));
}

iterator_t dom_node::document_uri(yy::location &loc) const
{
	return new SingletonIterator(loc, new stringValue(get_document_uri()));
}

iterator_t dom_node::node_name(
	yy::location &loc) const
{
	return new SingletonIterator(loc, (item*)get_node_name());
}

iterator_t dom_node::type_name(
	yy::location &loc) const
{
	return new SingletonIterator(loc, (item*)get_type_name());
}

iterator_t dom_node::typed_value(yy::location &loc) const
{
	return string_value(loc);
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
	const dom_document_node& dn)
:
  item (dn), node (dn), dom_node (dn), document_node (dn),
	theBaseURI(dn.theBaseURI),
	theDocURI(dn.theDocURI)
{}

// XQuery interface
iterator_t dom_document_node::children(yy::location &loc) const
{
	return new dom_child_iterator(*this, loc);
}


// internal interface
string dom_document_node::str() const 
{
	ostringstream oss;
	iterator_t it_h = children( zorba::getZorbaForCurrentThread()->GetCurrentLocation());
	it_h->open();
	while (!it_h->done()) {
		item_t dn_h = it_h->next();
		oss << dn_h->str();
	}
	it_h->close();
	return oss.str();
}

string dom_document_node::get_base_uri() const
{
	return theBaseURI;
}

string dom_document_node::get_document_uri() const
{
	return theDocURI;
}

string dom_document_node::get_typed_value() const
{
	return str();
}

const qname* dom_document_node::get_type_name() const
{
	return 0;
}

// output, serialization
ostream& dom_document_node::put(
	ostream& os) const
{
	iterator_t it_h = children(zorba::getZorbaForCurrentThread()->GetCurrentLocation());
	it_h->open();
	while (!it_h->done()) {
		item_t dn_h = it_h->next();
		os << dn_h->str();
	}
	it_h->close();
	return os;
}

string dom_document_node::toXML() const
{
	ostringstream oss;
	iterator_t it_h = children(zorba::getZorbaForCurrentThread()->GetCurrentLocation());
	it_h->open();
	while (!it_h->done()) {
		item_t i_h = it_h->next();
		dom_node* dn_p = dynamic_cast<dom_node*>(&*i_h);
		oss << dn_p->toXML();
	}
	it_h->close();
	return oss.str();
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
  item (en), node (en), dom_node (en), element_node (en),
	qname_p(en.qname_p),
	value_p(en.value_p),
	nsv(en.nsv),
	attrv(en.attrv),
	childv(en.childv),
	id_b(en.id_b),
	idref_b(en.idref_b)
{}


// internal interface
std::string dom_element_node::str() const
{
	ostringstream oss;
	iterator_t it_h = children(zorba::getZorbaForCurrentThread()->GetCurrentLocation());
	it_h->open();
	while (!it_h->done()) {
		item_t dn_h = it_h->next();
		oss << dn_h->str();
	}
	it_h->close();
	return oss.str();
}

string dom_element_node::get_typed_value() const
{
	return str();
}

const qname* dom_element_node::get_type_name() const
{
	return 0;
}

const qname* dom_element_node::get_node_name() const
{
	return qname_p;
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
iterator_t dom_element_node::typed_value(yy::location &loc) const
{
	if (value_p) {
		return new SingletonIterator(loc,value_p);
	} else {
		return string_value(loc);
	}
}

iterator_t dom_element_node::attributes(yy::location &loc) const
{
	return new dom_attribute_iterator(*this,loc);
}

iterator_t dom_element_node::children(yy::location &loc) const
{
	return new dom_child_iterator(*this,loc);
}

iterator_t dom_element_node::namespace_nodes(yy::location &loc) const
{
	return new dom_namespace_iterator(*this,loc);
}


// output, serialization
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
	ostringstream oss;
	get_node_name()->put(oss);
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
  item (an), node (an), attribute_node (an), dom_node (an),
	qname_p(an.qname_p),
	value(an.value),
	id_b(an.id_b),
	idrefs_b(an.idrefs_b)
{}


// internal interface
string dom_attribute_node::str() const
{
	return value;
}

string dom_attribute_node::get_typed_value() const
{
	return value;
}

const qname* dom_attribute_node::get_node_name() const
{
	return qname_p;
}

const qname* dom_attribute_node::get_type_name() const
{
	return 0;
}


// output, serialization
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
	ostringstream oss;
	qname_p->put(oss);
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
  item (nn), node (nn), dom_node (nn), namespace_node (nn),
	thePrefix(nn.thePrefix),
	theURI(nn.theURI)
{
}


// internal interface
string dom_namespace_node::str() const
{
	return theURI;
}

const qname* dom_namespace_node::get_node_name() const
{
	return NULL;
}

string dom_namespace_node::get_typed_value() const
{
	return "";
}


// output, serialization
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
	return toXML();
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
  item (pn), node (pn), dom_node (pn), pi_node (pn),
	theTarget(pn.theTarget),
	theContent(pn.theContent)
{}


// internal interface
string dom_pi_node::str() const 
{
	return theContent;
}

string dom_pi_node::get_typed_value() const
{
	return theContent;
}

const qname* dom_pi_node::get_node_name() const
{
	return new dom_qname("","",theTarget);
}


// output, serialization
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
	return toXML();
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
  item (cn), node (cn), comment_node (cn), dom_node (cn),
	theContent(cn.theContent)
{
}


// internal interface
string dom_comment_node::str() const
{
	return theContent;
}

string dom_comment_node::get_typed_value() const
{
	return theContent;
}


// output, serialization
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
: item (tn), node (tn), dom_node (tn), text_node (tn), theContent(tn.theContent)
{}


// internal interface
string dom_text_node::str() const
{
	return theContent;
}

string dom_text_node::get_typed_value() const
{
	return str();
}


// output, serialization
ostream& dom_text_node::put(
	ostream& os) const
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
	return toXML();
}


// dom_doc_child_iterator
dom_doc_child_iterator::dom_doc_child_iterator(
	const dom_node& dn, yy::location &loc)
:
	BasicIterator(loc),
	parent(dn)
{
	const dom_document_node* dn_p =
		dynamic_cast<const dom_document_node*>(&dn);
	//d Assert<bad_arg>(dn_p!=NULL);
	Assert(dn_p!=NULL);
	it = dn_p->childv.begin();
	end = dn_p->childv.end();
}


// dom_child_iterator
dom_child_iterator::dom_child_iterator(
	const dom_node& dn, yy::location &loc)
:
	BasicIterator(loc),
	parent(dn)
{
	const dom_element_node* en_p =
		dynamic_cast<const dom_element_node*>(&dn);
	//d Assert<bad_arg>(en_p!=NULL);
	Assert(en_p!=NULL);
	it = en_p->childv.begin();
	end = en_p->childv.end();
}


// dom_attribute_iterator
dom_attribute_iterator::dom_attribute_iterator(
	const dom_node& dn, yy::location &loc)
:
	BasicIterator(loc),
	parent(dn)
{
	const dom_element_node* en_p =
		dynamic_cast<const dom_element_node*>(&dn);
	//d Assert<bad_arg>(en_p!=NULL);
	Assert(en_p!=NULL);
	it = en_p->attrv.begin();
	end = en_p->attrv.end();
}


// dom_namespace_iterator
dom_namespace_iterator::dom_namespace_iterator(
	const dom_node& dn, yy::location &loc)
:
	BasicIterator(loc),
	parent(dn)
{
	const dom_element_node* en_p =
		dynamic_cast<const dom_element_node*>(&dn);
	//d Assert<bad_arg>(en_p!=NULL);
	Assert(en_p!=NULL);
	it = en_p->nsv.begin();
	end = en_p->nsv.end();
}


}	/* namespace xqp */

