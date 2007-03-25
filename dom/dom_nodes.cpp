/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dom_nodes.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "dom_nodes.h"

namespace xqp {

typedef rchandle<abstract_iterator> iterator_t;



ostream& dom_node::put(ostream& os) const
{
  switch (node_kind()) {
    case doc_kind: {
      const dom_document_node* doc_p = dynamic_cast<const dom_document_node*>(this);
      return doc_p->put(os);
    }
    case elem_kind: {
      const dom_element_node* elem_p = dynamic_cast<const dom_element_node*>(this);
      return elem_p->put(os);
    }
    case attr_kind: {
      const dom_attribute_node* at_p = dynamic_cast<const dom_attribute_node*>(this);
      return at_p->put(os);
    }
    case ns_kind: {
      const dom_namespace_node* ns_p = dynamic_cast<const dom_namespace_node*>(this);
      return ns_p->put(os);
    }
    case text_kind: {
      const dom_text_node* txt_p = dynamic_cast<const dom_text_node*>(this);
      return txt_p->put(os);
    }
    case comment_kind: {
      const dom_comment_node* cmnt_p = dynamic_cast<const dom_comment_node*>(this);
      return cmnt_p->put(os);
    }
    case pi_kind: {
      const dom_pi_node* pi_p = dynamic_cast<const dom_pi_node*>(this);
      return pi_p->put(os);
    }
		default: return os << "??";
  }
}


// dom_document_node
// -----------------

dom_document_node::dom_document_node(
	const std::string& baseuri,
	const std::string& docuri)
:
	the_baseuri(baseuri),
	the_docuri(docuri)
{}
	
dom_document_node::dom_document_node(
	dom_document_node::dom_document_node& dn)
:
	the_baseuri(dn.the_baseuri),
	the_docuri(dn.the_docuri)
{}

string dom_document_node::string_value() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}

iterator_t dom_document_node::base_uri() const
{ return new dom_singleton_iterator(the_baseuri); }

iterator_t dom_document_node::document_uri() const
{ return new dom_singleton_iterator(the_docuri); }

iterator_t dom_document_node::children() const
{ return new child_iterator(this); }

iterator_t dom_document_node::typed_value() const
{ return new dom_singleton_iterator(string_value()); }

ostream& dom_document_node::put(ostream& os) const
{
	iterator_t it = children();
	while (!it->done()) {
		dom_node* n_p = (dom_node*)(it->next());
		os << n_p->string_value();
	}
	return os;
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
	idrefs_b(false)
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
	idrefs_b(en.idrefs_b)
{}


std::string dom_element_node::string_value() const
{
	ostringstream oss;
	put(oss);
	return oss.str();
}

iterator_t dom_element_node::attributes() const
{ return new attribute_iterator(this); }

iterator_t dom_element_node::base_uri() const
{ return parent_p->base_uri(); }

iterator_t dom_element_node::document_uri() const
{ return parent_p ? parent_p->document_uri() : NULL; }

iterator_t dom_element_node::children() const
{ return new child_iterator(this); }

iterator_t dom_element_node::namespace_nodes() const
{ return new namespace_iterator(this); }

iterator_t dom_element_node::node_name() const
{ return new dom_singleton_iterator(qname_p); }

iterator_t dom_element_node::typed_value() const
{
	if (value_p) {
		return new dom_singleton_iterator(value_p);
	} else {
		return new dom_singleton_iterator(string_value());
	}
}

ostream& dom_element_node::put(
	ostream& os) const
{
  os << '[' << childv.size() << ']';
	os << '<';
	qname_p->put(os);

	if (nsv.size() + attrv.size() > 0) os << ' ';
	vector<dom_namespace_node*>::const_iterator ns_it = nsv.begin();
	for (; ns_it!=nsv.end(); ++ns_it) {
		(*ns_it)->put(os) << ' ';
	}
	vector<dom_attribute_node*>::const_iterator at_it = attrv.begin();
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

iterator_t dom_attribute_node::base_uri() const
{ return parent_p ? parent_p->base_uri() : NULL; }

iterator_t dom_attribute_node::node_name() const
{ return new dom_singleton_iterator(qname_p); }

iterator_t dom_attribute_node::typed_value() const
{ return new dom_singleton_iterator(value); }

string dom_attribute_node::string_value() const
{ return value; }

ostream& dom_attribute_node::put(
	ostream& os) const
{
	qname_p->put(os);
	return os << "=\"" << value << "\"";
}




// dom_namespace_node
// ------------------

dom_namespace_node::dom_namespace_node(
	const std::string& prefix,
	const std::string& uri)
:
	iprefix(prefix),
	iuri(uri)
{}

dom_namespace_node::dom_namespace_node(
	dom_namespace_node& nn)
:
	iprefix(nn.iprefix),
	iuri(nn.iuri)
{}

iterator_t dom_namespace_node::node_name() const
{ return new dom_singleton_iterator(new dom_qname("","",iprefix)); }

iterator_t dom_namespace_node::typed_value() const
{ return NULL; }

string dom_namespace_node::string_value() const
{ return iuri; }

std::ostream& dom_namespace_node::put(std::ostream& os) const
{ return os << "xmlns:" << iprefix << '=' << iuri; }




// dom_pi_node
// -----------

dom_pi_node::dom_pi_node(
	const string& target,
	const string& content)
:
	itarget(target),
	icontent(content)
{}

dom_pi_node::dom_pi_node(const dom_pi_node& pn)
:
	itarget(pn.itarget),
	icontent(pn.icontent)
{}

string dom_pi_node::string_value() const 
{ return icontent; }

iterator_t dom_pi_node::base_uri() const
{ return parent_p ? parent_p->base_uri() : NULL; }

iterator_t dom_pi_node::typed_value() const
{ return new dom_singleton_iterator(icontent); }

iterator_t dom_pi_node::node_name() const
{ return new dom_singleton_iterator(itarget); }

std::ostream& dom_pi_node::put(std::ostream& os) const
{ return os << "<?" << itarget << ' ' << icontent << "?>"; }




// dom_comment_node
// ----------------

dom_comment_node::dom_comment_node(
	const string& content)
: the_content(content) {}

dom_comment_node::dom_comment_node(
	const dom_comment_node& cn)
: the_content(cn.the_content) {}

string dom_comment_node::string_value() const
{ return the_content; }

iterator_t dom_comment_node::base_uri() const
{ return parent_p ? parent_p->base_uri() : NULL; }

iterator_t dom_comment_node::typed_value() const
{ return new dom_singleton_iterator(this); }

std::ostream& dom_comment_node::put(std::ostream& os) const
{ return os << "<!--" << the_content << "-->"; }




// dom_text_node
// -------------

dom_text_node::dom_text_node(
	const string& content)
: the_content(content) {}

dom_text_node::dom_text_node(
	const dom_text_node& tn) 
: the_content(tn.the_content) {}

string dom_text_node::string_value() const
{ return the_content; }

iterator_t dom_text_node::base_uri() const
{ return parent_p ? parent_p->base_uri() : NULL; }

iterator_t dom_text_node::typed_value() const
{ return new dom_singleton_iterator(the_content); }

ostream& dom_text_node::put(ostream& os) const
{ return os << the_content; }


}	/* namespace xqp */

