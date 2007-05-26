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

//15.5.4 fn:doc

//15.5.5 fn:doc-available

//15.5.6 fn:collection


} /* namespace xqp */
 
