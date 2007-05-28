/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: Sequences.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "SequencesImpl.h"
#include "dom/dom_nodes.h"
#include "dom/dom_xml_handler.h"
#include "store/zorba_uri_resolver.h"
#include "store/xml_scanner.h"
#include "util/xqp_exception.h"

#include <string>
#include <vector>

using namespace std;
namespace xqp {


qname* op_concatenate_fname_p;
qname* fn_doc_fname_p;
  

/*______________________________________________________________________
|  
| 15.1 General Functions and Operators on Sequences
|_______________________________________________________________________*/

//15.1.1 fn:boolean



//15.1.2 op:concatenate 
//---------------------
item_t concat_iterator::_next()
{
	if (currit->done() && first_b) {
		currit = theNext;
		first_b = false;
	}
	return currit->next();
}

bool concat_iterator::done() const
{
	return (!first_b && currit->done());
}

concat_iterator::concat_iterator(
	zorba* zorp,
	iterator_t theFirst,
	iterator_t theSecond)
:
	basic_iterator(zorp),
	currit(theFirst),
	theNext(theSecond),
	first_b(true)
{
}

concat_iterator::concat_iterator(
	const concat_iterator& it)
:
	basic_iterator(it.zorp),
	currit(it.currit),
	theNext(it.theNext),
	first_b(it.first_b)
{
}

concat_iterator& concat_iterator::operator=(
	const concat_iterator& it)
{
	zorp = it.zorp;
	currit = it.currit;
	theNext = it.theNext;
	first_b = it.first_b;
	return *this;
}

item_t concat_iterator::operator*() const
{
	return **currit;
}

concat_iterator& concat_iterator::operator++()
{
	if (done()) throw xqp_exception("iterating past end");
	if (currit->done() && first_b) {
		currit = theNext;
		first_b = false;
	}
	++(*currit);
	return *this;
}


//15.1.3 fn:index-of

//15.1.4 fn:empty

//15.1.5 fn:exists

//15.1.6 fn:distinct-values

//15.1.7 fn:insert-before

//15.1.8 fn:remove

//15.1.9 fn:reverse

//15.1.10 fn:subsequence

//15.1.11 fn:unordered


/*______________________________________________________________________
|  
| 15.2 Functions That Test the Cardinality of Sequences
|_______________________________________________________________________*/

//15.2.1 fn:zero-or-one

//15.2.2 fn:one-or-more

//15.2.3 fn:exactly-one


/*______________________________________________________________________
|
| 15.3 Equals, Union, Intersection and Except
|_______________________________________________________________________*/

//15.3.1 fn:deep-equal

//15.3.2 op:union

//15.3.3 op:intersect

//15.3.4 op:except


/*______________________________________________________________________
|
| 15.4 Aggregate Functions
|_______________________________________________________________________*/

//15.4.1 fn:count

//15.4.2 fn:avg

//15.4.3 fn:max

//15.4.4 fn:min

//15.4.5 fn:sum


/*______________________________________________________________________
|
| 15.5 Functions and Operators that Generate Sequences
|_______________________________________________________________________*/

//15.5.1 op:to

//15.5.2 fn:id

//15.5.3 fn:idref



/*______________________________________________________________________
|	15.5.4 fn:doc
|
|		fn:doc($uri as xs:string?) as document-node()?
|	
|	Summary: Retrieves a document using an xs:anyURI, which may include a 
|	fragment identifier, supplied as an xs:string. If $uri is not a valid 
|	xs:anyURI, an error is raised [err:FODC0005]. If it is a relative URI 
|	Reference, it is resolved relative to the value of the base URI 
|	property from the static context. The resulting absolute URI Reference 
|	is promoted to an xs:string. If the Available documents discussed in 
|	Section 2.1.2 Dynamic ContextXP provides a mapping from this string to 
|	a document node, the function returns that document node. If the 
|	Available documents maps the string to an empty sequence, then the 
|	function returns an empty sequence. If the Available documents 
|	provides no mapping for the string, an error is raised [err:FODC0005]. 
|	
|	If $uri is the empty sequence, the result is an empty sequence.
|_______________________________________________________________________*/

void doc_iterator::_open()
{
	uri_resolver* urires_p = new zorba_uri_resolver();
	arg->open();
	string path = arg->next()->str(zorp);
	rchandle<source> src_h = urires_p->resolve(path);
	istream* is_p = src_h->get_input(zorp);
	ostringstream oss;
	string line;
	while (!is_p->eof()) {
		getline(*is_p,line);
		oss << line << endl;
	}
	string bufs = oss.str();
	size_t n = bufs.length();
	char buf[n+1];
	strcpy(buf, bufs.c_str());
	xml_scanner* scanner_p = new xml_scanner();
	dom_xml_handler* xhandler_p = new dom_xml_handler(zorp,"/",path);
	scanner_p->scan(buf, n, dynamic_cast<scan_handler*>(xhandler_p));
	doc_node = dynamic_cast<dom_document_node*>(xhandler_p->context_node());
	delete xhandler_p;
}
  
item_t doc_iterator::_next()
{
	document_node* result = doc_node;
	doc_node = NULL;
	return result;
}

void doc_iterator::_close()
{
}

bool doc_iterator::done() const
{
	return doc_node == NULL;
}

doc_iterator::doc_iterator(
	zorba* zorp,
	iterator_t _arg)
:
	basic_iterator(zorp),
	arg(_arg),
	doc_node(NULL)
{
}

doc_iterator::doc_iterator(
	const doc_iterator& it)
:
	basic_iterator(it.zorp),
	arg(it.arg),
	doc_node(it.doc_node)
{
}

doc_iterator& doc_iterator::operator=(
	const doc_iterator& it)
{
	zorp = it.zorp;
	arg = it.arg;
	doc_node = it.doc_node;
	return *this;
}

item_t doc_iterator::operator*() const
{
	return doc_node;
}

doc_iterator& doc_iterator::operator++()
{
	if (done()) throw xqp_exception("iterating past end");
	doc_node = NULL;
	return *this;
}



//15.5.5 fn:doc-available

//15.5.6 fn:collection


} /* namespace xqp */
 
