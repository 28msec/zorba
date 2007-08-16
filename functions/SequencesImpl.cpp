/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
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
#include "errors/Error.h"

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
std::ostream& ConcatIterator::_show(std::ostream& os)
const
{
	std::vector<iterator_t>::const_iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		(*iter)->show(os);
	}
	return os;
}

item_t ConcatIterator::nextImpl() {
	item_t item;
	
	STACK_INIT();
	
	this->cursor = 0;
	
	for (; this->cursor < this->argv.size (); this->cursor++) {;
		this->currit_h = this->argv[this->cursor];
		item = this->consumeNext(this->currit_h);
		while (item != NULL) {
			STACK_PUSH (item);
			item = this->consumeNext(this->currit_h);
		}
	}
	
	STACK_PUSH(NULL);
	STACK_END();
}

void ConcatIterator::resetImpl() {
	std::vector<iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->resetChild(*iter);
	}
}

void ConcatIterator::releaseResourcesImpl() {
	std::vector<iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->releaseChildResources(*iter);
	}
}

// ConcatIterator::ConcatIterator(
// 	yy::location loc,
// 	const vector<iterator_t>& _argv)
// :
// 	Batcher<ConcatIterator>(loc),
// 	argv(_argv),
// 	currit_h(NULL),
// 	cursor(0)
// {
// }
// 
// ConcatIterator::ConcatIterator(
// 	const ConcatIterator& concat_it)
// :
// 	Batcher<ConcatIterator>(concat_it),
// 	argv(concat_it.argv),
// 	currit_h(concat_it.currit_h),
// 	cursor(concat_it.cursor)
// {
// }


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
	string path = arg->next()->str();
	rchandle<source> src_h = urires_p->resolve(path);
	istream* is_p = src_h->get_input();
	assert(is_p!=NULL);

	ostringstream oss;
	string line;
	while (!is_p->eof()) {
		getline(*is_p,line);
		oss << line << endl;
	}
	string bufs = oss.str();
	size_t n = bufs.length();
	char *buf;
	buf = (char*)malloc(n+1);
	strcpy(buf, bufs.c_str());

	xml_scanner* scanner_p = new xml_scanner();
	dom_xml_handler* xhandler_p = new dom_xml_handler("/",path);
	scanner_p->scan(buf, n, dynamic_cast<scan_handler*>(xhandler_p));
	doc_node = dynamic_cast<dom_document_node*>(xhandler_p->context_node());

	free(buf);

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

std::ostream& doc_iterator::_show(std::ostream& os)
const
{
	arg->show(os);
	return os;
}

bool doc_iterator::done() const
{
	return doc_node == NULL;
}

doc_iterator::doc_iterator(
	yy::location loc,
	iterator_t _arg)
:
	BasicIterator(loc),
	arg(_arg),
	doc_node(NULL)
{
}

doc_iterator::doc_iterator(
	const doc_iterator& it)
:
	BasicIterator(it),
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



//15.5.5 fn:doc-available

//15.5.6 fn:collection


} /* namespace xqp */
 
