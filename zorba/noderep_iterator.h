/* -*- mode: c++; indent-tabs-mode: nil -*- *
 *
 *  $Id: noderep_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_NODEREP_ITERATOR_H
#define XQP_NODEREP_ITERATOR_H

#include "../util/rchandle.h"

namespace xqp {

class noderep;

class noderep_iterator : public rcobject
{
public:
	// open: aquire resources
	virtual void open() = 0;						

	// close: release resources
	virtual void close() = 0;

	// next: seek + delta (or NULL)
	virtual noderep* next(uint32_t d = 1) = 0;

	// current item (or NULL)
	virtual noderep* peek() const = 0;

	// done => true <-> no more items
	virtual bool done() const = 0;

public:	// C++ interface
	virtual noderep* operator*() const = 0;
	virtual noderep_iterator& operator++() = 0;

};


}	/* namespace xqp */
#endif	/* XQP_NODEREP_ITERATOR_H */

