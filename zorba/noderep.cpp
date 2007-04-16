/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: noderep.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "noderep.h"

#include "../runtime/errors.h"
#include "../runtime/zorba.h"
#include "../util/tracer.h"
#include "../values/qname_value.h"
#include "../values/xs_primitive_values.h"

#include <stdlib.h>

using namespace std;
namespace xqp {

/*...........................................
	:             node                        :
	:.........................................*/

noderep::noderep(
	sequence_type_t type,		// node type
	uint32_t length,				// item length
	itemref_t ref,					// forwarding item reference
	uint32_t gen,						// genration number
	nodeid_t id,						// ordinal node id
	nodeid_t parentid)			// parent node id
:
	theType(type),
	theLength(length),
	theRef(ref),
	theGen(gen),
	theID(id),
	theParentID(parentid)
{
}

noderep* noderep::parent(zorba* zorp) const
{
	return zorp->istore()->get_noderep(theParentID);
}


/*..........................................
 :            document_node                :
 :.........................................*/

document_noderep::document_noderep(
	zorba* zorp,
	nodeid_t baseuri,
	nodeid_t uri)
:
	noderep(
		documentNode,							/* type								*/
		0,												/* length 						*/
		0,												/* forwarding ref			*/
		zorp->gen(),							/* generation number	*/
		zorp->next_nodeid(),			/* ordinal node id		*/
		zorp->context_nodeid()),	/* parent node id			*/
	theBaseuri(baseuri),
	theDocuri(uri)
{
cout << TRACE << endl;
	theLength = sizeof(document_noderep);
}

const xs_stringValue* document_noderep::baseuri(
	zorba* zorp) const
{
	return new(zorp->istore()->get_addr(theBaseuri)) xs_stringValue();
} 

const xs_stringValue* document_noderep::docuri(
	zorba* zorp) const
{
	return new(zorp->istore()->get_addr(theDocuri)) xs_stringValue();
} 

noderep_it document_noderep::children() const
{
	return new child_noderep_iterator(this, new(rest) noderep());
} 

string document_noderep::string_value() const
{
	ostringstream oss;
	noderep* n_p = new(rest) noderep();
	child_const_noderep_iterator it(this,n_p);
	for (; !it.done(); ++it) {
		oss << (*it)->string_value();
	}
	return oss.str();
}

ostream& document_noderep::put(zorba* zorp,ostream& os) const
{
	os << "<?xml version=\"1.0\"?>\n";
	noderep* n_p = new(rest) noderep();
	child_const_noderep_iterator it(this,n_p);
	for (; !it.done(); ++it) {
    noderep* rep = *it;
		switch (rep->type()) {
		case documentNode: {
			cout << TRACE << " : documentNode" << endl;
			document_noderep* d_p = new(rep) document_noderep();
			d_p->put(zorp,os);
			break;
		}
		case attributeNode: {
			cout << TRACE << " : attributeNode" << endl;
			attribute_noderep* a_p = new(rep) attribute_noderep();
			a_p->put(zorp,os);
			break;
		}
		case elementNode: {
			cout << TRACE << " : elementNode" << endl;
			element_noderep* e_p = new(rep) element_noderep();
			e_p->put(zorp,os);
			break;
		}
		case processingInstructionNode: {
			pi_noderep* pi_p = new(rep) pi_noderep();
			pi_p->put(zorp,os);
			break;
		}
		case commentNode: {
			comment_noderep* c_p = new(rep) comment_noderep();
			c_p->put(zorp,os);
			break;
		}
		case textNode: {
			cout << TRACE << " : textNode" << endl;
			text_noderep* t_p = new(rep) text_noderep();
			t_p->put(zorp,os);
			break;
		}
		default: {
  		cout << TRACE << " : unrecognized type = "
  		      << sequence_type::describe(rep->type()) << endl;
		}}
	}
	return os;
}


/*..........................................
 :  collection nodes                       :
 :.........................................*/

const xs_stringValue* collection_noderep::baseuri(
	zorba* zorp) const
{
	return NULL;
}

const xs_stringValue* collection_noderep::colluri(
	zorba* zorp) const
{
	return NULL;
}

noderep_it collection_noderep::children() const
{
	return NULL;
}


/*..........................................
 :  element nodes                          :
 :.........................................*/

element_noderep::element_noderep(
	zorba* zorp,
	nodeid_t qname)
:
	noderep(
		elementNode,							// typecode
		0,	                     	// the length
		0,												// forwarding itemref
		zorp->gen(),							// generation number
		zorp->next_nodeid(),			// ordinal node id
		zorp->context_nodeid()),	// parent node id
	qnameID(qname),							// element QName id
	namespacesID(0)							// XXX in-scope namespaces
{
cout << TRACE << endl;
}

string element_noderep::string_value() const
{
	return "";
}

const xs_stringValue* element_noderep::baseuri(
	zorba* zorp) const
{
	return parent(zorp)->baseuri(zorp);
}

qname_value* element_noderep::node_name(
	zorba* zorp) const
{
	return zorp->get_qname(qnameID);
}

const xs_stringValue* element_noderep::docuri(
	zorba* zorp) const
{
	return parent(zorp)->docuri(zorp);
}

noderep_it element_noderep::attributes() const
{
	return new attribute_noderep_iterator(
		this,
		new(&rest) noderep(),
		new(&rest[nodeOffset]) noderep());
}

noderep_it element_noderep::children() const
{
	return new child_noderep_iterator(
		this,
		new(&rest[nodeOffset]) noderep());
}

noderep_it element_noderep::namespaces(
	zorba* zorp) const
{
	return new namespace_noderep_iterator(this);
}

ostream& element_noderep::put(zorba* zorp, ostream& os) const
{
  cout << TRACE << " : element_node" << endl;

  qname_value* q_p = zorp->get_qname(qnameID);
  q_p->put(os);
  
	noderep* n_p = new(rest) noderep();
	child_const_noderep_iterator it(this,n_p);
	for (; !it.done(); ++it) {
    noderep* rep = *it;
		switch (rep->type()) {
		case documentNode: {
			cout << TRACE << " : documentNode" << endl;
			document_noderep* d_p = new(rep) document_noderep();
			d_p->put(zorp,os);
			break;
		}
		case attributeNode: {
			cout << TRACE << " : attributeNode" << endl;
			attribute_noderep* a_p = new(rep) attribute_noderep();
			a_p->put(zorp,os);
			break;
		}
		case elementNode: {
			cout << TRACE << " : elementNode" << endl;
			element_noderep* e_p = new(rep) element_noderep();
			e_p->put(zorp,os);
			break;
		}
		case processingInstructionNode: {
			pi_noderep* pi_p = new(rep) pi_noderep();
			pi_p->put(zorp,os);
			break;
		}
		case commentNode: {
			comment_noderep* c_p = new(rep) comment_noderep();
			c_p->put(zorp,os);
			break;
		}
		case textNode: {
			cout << TRACE << " : textNode" << endl;
			text_noderep* t_p = new(rep) text_noderep();
			t_p->put(zorp,os);
			break;
		}
		default: {
  		cout << TRACE << " : unrecognized type = "
  		      << sequence_type::describe(rep->type()) << endl;
		}}
	}
	return os;
}

noderep* element_noderep::node_at(uint32_t n) const
{
	child_const_noderep_iterator it(this, new(&rest[nodeOffset]) noderep());
	uint32_t i = 0;
	for (; i<n && !it.done(); ++it);
	Assert<bad_arg>(i==n);
	return *it;
}

namespace_noderep* element_noderep::name_space_at(uint32_t) const
{ return NULL; }

attribute_noderep* element_noderep::attr_at(uint32_t) const
{ return NULL; }


/*..........................................
 :           attribute nodes               :
 :.........................................*/

attribute_noderep::attribute_noderep(
	zorba* zorp,
	nodeid_t qname)
:
	noderep(
		attributeNode,									// typecode
		sizeof(attribute_noderep),			// item length
		0,															// forwarding itemref
		zorp->gen(),										// generation number
		zorp->next_nodeid(),						// ordinal node id
		zorp->context_nodeid()),				// parent node id
	qnameID(qname)
{
cout << TRACE << endl;
}

attribute_noderep::attribute_noderep(
	zorba* zorp,
	nodeid_t qname,
	string const& val)
:
	noderep(
		attributeNode,									// typecode
		sizeof(attribute_noderep),			// item length
		0,															// forwarding itemref
		zorp->gen(),										// generation number
		zorp->next_nodeid(),						// ordinal node id
		zorp->context_nodeid()),				// parent node id
	qnameID(qname)
{
	itemstore& istore = *zorp->istore();
	new(istore) xs_stringValue(istore,val);
	cout << TRACE << endl;
}

qname_value* attribute_noderep::node_name(
	zorba* zorp) const
{
	return zorp->get_qname(qnameID);
}

string attribute_noderep::string_value() const
{
	xs_stringValue* sp = new(rest) xs_stringValue();
	return sp->str();
}

const xs_stringValue* attribute_noderep::baseuri(
	zorba* zorp) const
{
	return parent(zorp)->baseuri(zorp);
}

ostream& attribute_noderep::put(
	zorba* zorp,
	ostream& os) const
{
	return os << "@" << node_name(zorp)->string_value()
						<< "=\"" << string_value() << "\"";
}


/*..........................................
 :          namespace nodes                :
 .........................................*/

namespace_noderep::namespace_noderep(
	zorba* zorp,
	const string& prefix,
	const string& uri)
:
	noderep(
		namespaceNode,						// type
		0,                    		// length
		0,												// forwarding reference
		zorp->gen(),							// generation number
		zorp->next_nodeid(),			// ordinal node id
		zorp->context_nodeid())		// parent node id
{
	itemstore& istore = *zorp->istore();
	xs_stringValue* p = new(istore) xs_stringValue(istore,prefix);
	uriOffset = istore.eos();
	xs_stringValue* q = new(istore) xs_stringValue(istore,uri);
	theLength = sizeof(namespace_noderep) + p->length() + q->length();
}

qname_value* namespace_noderep::node_name(
	zorba* zorp) const
{
	return NULL;
}

string namespace_noderep::string_value() const
{
	return "";
}

ostream& namespace_noderep::put(zorba* z_p,ostream& os) const
{
	return os << "xmlns:pre=\"..\"";
}

	
/*..........................................
 :    processing instruction nodes         :
 :.........................................*/

pi_noderep::pi_noderep(
	zorba* zorp)
:
	noderep(
		processingInstructionNode,
		sizeof(pi_noderep)>>2,
		0,
		zorp->next_gen(),
		zorp->next_nodeid(),
		zorp->context_nodeid())
{
}

string pi_noderep::string_value() const
{
	return "";
}

const xs_stringValue* pi_noderep::baseuri(
	zorba* zorp) const
{
	return parent(zorp)->baseuri(zorp);
}

qname_value* pi_noderep::node_name(
	zorba*) const
{
	return NULL;
}

ostream& pi_noderep::put(
	zorba* zorp,
	ostream& os) const
{
	return os << "<?..?>";
}



/*..........................................
 :          comment nodes                  :
 :.........................................*/

comment_noderep::comment_noderep(
	zorba* zorp)
:
	noderep(
		commentNode,									// typecode
		sizeof(comment_noderep),			// item length in bytes
		0,														// forwarding itemref
		zorp->gen(),									// generation number
		zorp->next_nodeid(),					// ordinal node id
		zorp->context_nodeid())				// parent node id
{
cout << TRACE << endl;
}

const xs_stringValue* comment_noderep::baseuri(
	zorba* zorp) const
{
	return parent(zorp)->baseuri(zorp);
}

string comment_noderep::string_value() const
{
	return "";
}

ostream& comment_noderep::put(
	zorba* zorp,
	ostream& os) const
{
	return os << "<!-- ... -->";
}


/*..........................................
 :             text nodes                  :
 :.........................................*/

text_noderep::text_noderep(
	zorba* zorp,
	string const& content)
:
	noderep(
		textNode,									// type
		0,												// length
		0,												// forwarding reference
		zorp->gen(),								// generation number
		zorp->next_nodeid(),				// ordinal node id
		zorp->context_nodeid())		// parent node id
{
cout << TRACE << endl;
	itemstore& istore = *zorp->istore();
	new(istore) xs_stringValue(istore,content);
}

const xs_stringValue* text_noderep::baseuri(
	zorba* zorp) const
{
	return parent(zorp)->baseuri(zorp);
}

string text_noderep::string_value() const
{
	xs_stringValue* s_p = new(rest) xs_stringValue();
	return s_p->str();
}

ostream& text_noderep::put(
	zorba* zorp,
	ostream& os) const
{
	xs_stringValue* s_p = new(rest) xs_stringValue();
	return os << s_p->str();
}

string text_noderep::str() const
{
	xs_stringValue* s_p = new(rest) xs_stringValue();
	return s_p->str();
}


/*..........................................
 :       nsseq = namespaceNodeSeq          :
 :.........................................*/

nsseqrep::nsseqrep(
	zorba* zorp,
	const vector<nodeid_t>& nsv)
:
	noderep(
		namespaceNodeSeq,					// type
		0,												// byte length
		0,												// forwarding reference
		zorp->gen(),							// generation number
		zorp->next_nodeid(),			// ordinal node id
		zorp->context_nodeid())		// parent node id
{
cout << TRACE << endl;
	vector<nodeid_t>::const_iterator it = nsv.begin();
	for (; it!=nsv.end(); ++it) { zorp->istore()->put(*it); }
	theLength = sizeof(nsseqrep) + count<<4;
}

ostream& nsseqrep::put(zorba*,ostream& os) const
{
	return os;
}


/*..........................................
 :     child_noderep_iterator              :
 :.........................................*/

child_noderep_iterator::child_noderep_iterator(
	const noderep* parent,
	noderep* current)
:
	theParentNodePtr(parent),
	theCurrentNodePtr(current)
{
cout << TRACE << endl;
	char* p = ((char*)theCurrentNodePtr)+theParentNodePtr->length();
	theEndNodePtr = new(p) noderep();
}
	
noderep* child_noderep_iterator::operator*() const
{
	switch (theCurrentNodePtr->type()) {
	case attributeNode: {
		return new(theCurrentNodePtr) attribute_noderep();
	}
	case elementNode: {
		return new(theCurrentNodePtr) element_noderep();
	}
	case processingInstructionNode: {
		return new(theCurrentNodePtr) pi_noderep();
	}
	case commentNode: {
		return new(theCurrentNodePtr) comment_noderep();
	}
	case textNode: {
		return new(theCurrentNodePtr) text_noderep();
	}
	default: {
		errors::err(errors::XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD);
	}}
	return NULL;
}

child_noderep_iterator& child_noderep_iterator::operator++()
{
	if (theCurrentNodePtr >= theEndNodePtr) {
		errors::err(errors::XQP0001_DYNAMIC_ITERATOR_OVERRUN);
	}
	char* p = ((char*)theCurrentNodePtr)+theCurrentNodePtr->length();
	theCurrentNodePtr = new(p) noderep();
	return *this;
}


/*..........................................
 :     child_const_noderep_iterator        :
 :.........................................*/

child_const_noderep_iterator::child_const_noderep_iterator(
	const noderep* parent,
	const noderep* current)
:
	theParentNodePtr(parent),
	theCurrentNodePtr(current)
{
cout << TRACE << endl;
	char* p = ((char*)theCurrentNodePtr)+theParentNodePtr->length();
	theEndNodePtr = new(p) noderep();
}
	

noderep* child_const_noderep_iterator::operator*() const
{
cout << TRACE << endl;

	while (true) {
		switch (theCurrentNodePtr->type()) {
		case documentNode: {
			cout << TRACE << " : documentNode" << endl;
			return new(theCurrentNodePtr) document_noderep();
		}
		case attributeNode: {
			cout << TRACE << " : attributeNode" << endl;
			return new(theCurrentNodePtr) attribute_noderep();
		}
		case elementNode: {
			cout << TRACE << " : elementNode" << endl;
			return new(theCurrentNodePtr) element_noderep();
		}
		case processingInstructionNode: {
			return new(theCurrentNodePtr) pi_noderep();
		}
		case commentNode: {
			return new(theCurrentNodePtr) comment_noderep();
		}
		case textNode: {
			cout << TRACE << " : textNode" << endl;
			return new(theCurrentNodePtr) text_noderep();
		}
		default: {
			cout << TRACE << " : not a node: "
					 << sequence_type::describe(theCurrentNodePtr->type()) 
					 << " (" << theCurrentNodePtr->length() << ')' << endl;
			return NULL;
			}
		}
	}
}


child_const_noderep_iterator& child_const_noderep_iterator::operator++()
{
cout << TRACE << endl;
	if (theCurrentNodePtr >= theEndNodePtr) {
		cout << TRACE << " : iterator overrun" << endl;
		errors::err(errors::XQP0001_DYNAMIC_ITERATOR_OVERRUN);
	}
	cout << TRACE << " : length = " << theCurrentNodePtr->length() << endl;
	char* p = ((char*)theCurrentNodePtr)+theCurrentNodePtr->length();
	theCurrentNodePtr = new(p) noderep();
	return *this;
}



/*..........................................
 :     namespace_noderep_iterator          :
 :.........................................*/

namespace_noderep_iterator::namespace_noderep_iterator(
	const element_noderep* parent)
:
	theParentNodePtr(parent)
{
}
	


/*..........................................
 :     attribute_noderep_iterator          :
 :.........................................*/

attribute_noderep_iterator::attribute_noderep_iterator(
	const noderep* parent,
	noderep* current,
	noderep* end)
:
	theParentNodePtr(parent),
	theCurrentNodePtr(current),
	theEndNodePtr(end)
{
cout << TRACE << endl;
}
	
noderep* attribute_noderep_iterator::operator*() const
{
	switch (theCurrentNodePtr->type()) {
	case attributeNode: {
		return new(theCurrentNodePtr) attribute_noderep();
	}
	default: {
		errors::err(errors::XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD);
	}}
	return NULL;
}

attribute_noderep_iterator& attribute_noderep_iterator::operator++()
{
	if (theCurrentNodePtr >= theEndNodePtr) {
		errors::err(errors::XQP0001_DYNAMIC_ITERATOR_OVERRUN);
	}
	char* p = ((char*)theCurrentNodePtr)+theCurrentNodePtr->length();
	theCurrentNodePtr = new(p) noderep();
	return *this;
}


}	/* namespace xqp */

