/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: item_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_ITEM_ITERATOR_H
#define XQP_ITEM_ITERATOR_H

#include "../util/rchandle.h"
#include "../values/values.h"

namespace xqp {

class item_iterator : public rcobject
{
protected:
  context *const ctx_p;

public:
	item_iterator(context *const _ctx_p) : ctx_p(_ctx_p) {}
	item_iterator() : ctx_p(NULL) {}
	~item_iterator() {}
  
public:
	// aquire resources
	void open() {}

	// release resources
	void close() {}

	// return handle to next item (or NULL)
	rchandle<item> next() { return NULL; }

	// return true <=> iterator has no more items
	bool done() { return true; }

	// rewind the iterator, equivalent to {close();open()}
	void rewind() {}

};


}	/* namespace xqp */
#endif	/* XQP_ITEM_ITERATOR_H */
