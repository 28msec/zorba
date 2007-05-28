/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: SequencesImpl.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan, Paul Pedersen
 */

#ifndef XQP_SEQUENCES_IMPL_H
#define XQP_SEQUENCES_IMPL_H

#include "function.h"
#include "context/common.h"
#include "runtime/item_iterator.h"
#include "util/rchandle.h"
#include "values/nodes.h"

#include <string>
#include <vector>

namespace xqp {

class zorba;

/*______________________________________________________________________
|  
| 15.1 General Functions and Operators on Sequences
|_______________________________________________________________________*/


//15.1.1 fn:boolean


//15.1.2 op:concatenate
class concat_iterator : public basic_iterator
{
protected:
	iterator_t currit;
	iterator_t theNext;
	bool first_b;

public:	
	void _open() {}
	void _close() {}
	item_t _next();
	bool done() const;

public:
	item_t operator*() const;
	concat_iterator& operator++();
	concat_iterator& operator=(const concat_iterator& it);

public:	// ctor,dtor
	concat_iterator(zorba*, iterator_t, iterator_t);
	concat_iterator(const concat_iterator& it);
	~concat_iterator() {}

};


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


//15.5.4 fn:doc
class doc_iterator : public basic_iterator
{
private:
	iterator_t arg;
	document_node* doc_node;

public:	
	void _open();
	void _close();
	item_t _next();
	bool done() const;

public:
	item_t operator*() const;
	doc_iterator& operator++();
	doc_iterator& operator=(const doc_iterator& it);

public:	// ctor,dtor
	doc_iterator(zorba*, iterator_t);
	doc_iterator(const doc_iterator&);
	~doc_iterator() {}

};


//15.5.5 fn:doc-available

//15.5.6 fn:collection


/*______________________________________________________________________
|
| Extensions
|_______________________________________________________________________*/


} /* namespace xqp */
#endif /* XQP_SEQUENCES_H */
