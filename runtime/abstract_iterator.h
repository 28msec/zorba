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
	// open: aquire resources
	virtual void open() = 0;						

	// close: release resources
	virtual void close() = 0;

	// next: seek + delta (or NULL)
	virtual abstract_item* next(uint32_t d = 1) = 0;

	// current item (or NULL)
	virtual abstract_item* peek() const = 0;

	// done => true <-> no more items
	virtual bool done() const = 0;

	// rewind: equivalent to { close(); open() }
	virtual void rewind() = 0; 

};


}	/* namespace xqp */
#endif	/* XQP_ABSTRACT_ITERATOR_H */

