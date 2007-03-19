/* -*- mode: c++; indent-tabs-mode: nil -*- *
 *  $Id: abstract_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ABSTRACT_ITERATOR_H
#define XQP_ABSTRACT_ITERATOR_H

#include "../util/rchandle.h"

namespace xqp {

class abstract_item;

class abstract_iterator : public rcobject
{
public:
	static abstract_iterator emptySequence;

public:
	void open();								// aquire resources
	void close();								// release resources
	abstract_item* next(uint32_t d = 1);	// seek + delta (or NULL)
	abstract_item* peek() const;					// current item (or NULL)
	bool done() const;					// true <-> no more items
	void rewind(); 							// equivalent to { close(); open() }

};


}	/* namespace xqp */
#endif	/* XQP_ABSTRACT_ITERATOR_H */

