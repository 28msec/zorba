/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: nodereps.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "nodereps.h"
#include "runtime/errors.h"
#include "runtime/zorba.h"
#include "util/Assert.h"
#include "util/tracer.h"
#include "util/xqp_exception.h"
#include "values/qname.h"

#include <stdlib.h>

using namespace std;
namespace xqp {

/*...........................................
	:             node                        :
	:.........................................*/

noderep::noderep(
	sequence_type_t type,		// XQuery type
	uint32_t length,				// item length
	off_t ref,							// forwarding item reference
	uint32_t gen,						// genration number
	itemid_t id,						// ordinal node id
	itemid_t parentid)			// parent node id
:
	itemRep(type,length),
	theRef(ref),
	theGen(gen),
	theID(id),
	theParentID(parentid)
{
}


/*..........................................
 :            document_node                :
 :.........................................*/

document_noderep::document_noderep(
	zorba* zorp,
	itemid_t baseuri,
	itemid_t uri)
:
	noderep(
		documentNode,	// XQuery type
		0,						// length
		0,						// forwarding ref
		// generation number
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->gen(),
		// ordinal item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->next_itemid(),
		// parent item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->context_itemid()),

	theBaseUriID(baseuri),
	theDocUriID(uri)
{
cout << TRACE << endl;
	theLength = sizeof(document_noderep);
}

noderep_it document_noderep::children( ) const
{
	return new child_noderep_iterator(this, new(rest) noderep());
} 

string document_noderep::str(
	zorba* zorp) const
{
	ostringstream oss;
	noderep* n_p = new(rest) noderep();
	child_const_noderep_iterator it(this,n_p);
	for (; !it.done(); ++it) {
		oss << (*it)->string_value();
	}
	return oss.str();
}

ostream& document_noderep::put(
	zorba* zorp,
	ostream& os) const
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

string collection_noderep::baseuri(
	zorba* zorp) const
{
	return "";
}

string collection_noderep::colluri(
	zorba* zorp) const
{
	return "";
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
	itemid_t qname)
:
	noderep(
		elementNode,							// typecode
		0,	                     	// the length
		0,												// forwarding off
		// generation number
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->gen(),
		// ordinal item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->next_itemid(),
		// parent item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->context_itemid()),

	theQNameID(qname),					// element qname id
	theNSID((dynamic_cast<itemstore*>(zorp->get_data_manager()))->in_scope_ns())
{
cout << TRACE << endl;
}

string element_noderep::str(
	zorba* zorp) const
{
	ostringstream oss;
	for (noderep_it it = children(); it->done(); ++(*it)) {
		(**it)->put(zorp,oss);
	}
	return oss.str();
}

noderep_it element_noderep::attributes() const
{
	return
		new attribute_noderep_iterator(
			this,
			new(&rest) noderep(),
			new(&rest[theNodeOffset]) noderep());
}

noderep_it element_noderep::children() const
{
	return
		new child_noderep_iterator(
			this,
			new(&rest[theNodeOffset]) noderep());
}

ostream& element_noderep::put(
	zorba* zorp,
	ostream& os) const
{
  cout << TRACE << " : element_node" << endl;

	data_manager* dmgr_p = zorp->get_data_manager();
  const qname* qn_p = dmgr_p->get_qname(theQNameID);
	Assert<null_pointer>(qn_p);
  qn_p->put(zorp,os);
  
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
 :           attribute nodes               :
 :.........................................*/

attribute_noderep::attribute_noderep(
	zorba* zorp,
	itemid_t qname)
:
	noderep(
		attributeNode,									// typecode
		sizeof(attribute_noderep),			// item length
		0,															// forwarding off
		// generation number
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->gen(),
		// ordinal item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->next_itemid(),
		// parent item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->context_itemid()),

	theQNameID(qname)
{
cout << TRACE << endl;
}

attribute_noderep::attribute_noderep(
	zorba* zorp,
	itemid_t qname,
	string const& val)
:
	noderep(
		attributeNode,									// typecode
		sizeof(attribute_noderep),			// item length
		0,															// forwarding off
		// generation number
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->gen(),
		// ordinal item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->next_itemid(),
		// parent item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->context_itemid()),

	theQNameID(qname)
{
	itemstore* istore_p = dynamic_cast<itemstore*>(zorp->get_data_manager());
	Assert<null_pointer>(istore_p!=NULL);
	istore_p->add_text(val);
}

string attribute_noderep::str(
	zorba* zorp) const
{
	contentRep* crep = new(rest) contentRep();
	return crep->str();
}

ostream& attribute_noderep::put(
	zorba* zorp,
	ostream& os) const
{
	data_manager* dmgr_p = zorp->get_data_manager();
	const qname* qn_p = dmgr_p->get_qname(theQNameID);
	qn_p->put(zorp,os);
	return os << "=\"" << string_value() << "\"";
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
		// generation number
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->gen(),
		// ordinal item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->next_itemid(),
		// parent item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->context_itemid())
{
	itemstore* istore_p = dynamic_cast<itemstore*>(zorp->get_data_manager());
	Assert<null_pointer>(istore_p!=NULL);
	itemstore& istore = *istore_p;
	contentRep* p = new(prefix.length()) contentRep(zorp,prefix);
	theURIOffset = istore.eos();
	contentRep* q = new(uri.length()) contentRep(zorp,uri);
	theLength = sizeof(namespace_noderep) + p->length() + q->length();
}

string namespace_noderep::prefix() const
{
	contentRep* crep = new(rest) contentRep();
	return crep->str();
}

string namespace_noderep::uri() const
{
	contentRep* crep = new(&rest[theURIOffset]) contentRep();
	return crep->str();
}

string namespace_noderep::str(
	zorba*) const
{
	return uri();
}

ostream& namespace_noderep::put(
	zorba* zorp,
	ostream& os) const
{
	return os << "xmlns:" << prefix() << "=\"" << uri() <<"\"";
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
		// generation number
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->gen(),
		// ordinal item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->next_itemid(),
		// parent item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->context_itemid())
{
}

string pi_noderep::str(
	zorba*) const
{
	return content();
}

string pi_noderep::target() const
{
	contentRep* crep = new(rest) contentRep();
	return crep->str();
}

string pi_noderep::content() const
{
	contentRep* crep = new(&rest[theContentOffset]) contentRep();
	return crep->str();
}

ostream& pi_noderep::put(
	zorba* zorp,
	ostream& os) const
{
	return os << "<?" << target() <<  ' ' << content() << " ?>";
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
		0,														// forwarding off
		// generation number
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->gen(),
		// ordinal item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->next_itemid(),
		// parent item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->context_itemid())
{
cout << TRACE << endl;
}

string comment_noderep::content() const
{
	contentRep* crep = new(rest) contentRep();
	return crep->str();
}

string comment_noderep::str(
	zorba*) const
{
	return content();
}

ostream& comment_noderep::put(
	zorba* zorp,
	ostream& os) const
{
	return os << "<!-- " << content() << " -->";
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
		// generation number
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->gen(),
		// ordinal item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->next_itemid(),
		// parent item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->context_itemid())
{
	new(content.length()) contentRep(zorp,content);
}

string text_noderep::str(
	zorba*) const
{
	contentRep* crep = new(rest) contentRep();
	return crep->str();
}

ostream& text_noderep::put(
	zorba* zorp,
	ostream& os) const
{
	contentRep* crep = new(rest) contentRep();
	return os << crep->str();
}



/*..........................................
 :       nsseq = namespaceNodeSeq          :
 :.........................................*/

nsseqrep::nsseqrep(
	zorba* zorp,
	const vector<itemid_t>& nsv)
:
	noderep(
		namespaceNodeSeq,					// type
		0,												// byte length
		0,												// forwarding reference
		// generation number
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->gen(),
		// ordinal item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->next_itemid(),
		// parent item id
		(dynamic_cast<itemstore*>(zorp->get_data_manager()))->context_itemid())
{
cout << TRACE << endl;
	theLength = sizeof(nsseqrep); // + count<<2;
}

ostream& nsseqrep::put(
	zorba* zorp,
	ostream& os) const
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


child_const_noderep_iterator&
child_const_noderep_iterator::operator++()
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
	const noderep* parent)
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
	const noderep* end)
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

