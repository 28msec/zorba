/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: binary_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_BINARY_ITERATOR_H
#define XQP_BINARY_ITERATOR_H

#include "item_iterator.h"

namespace xqp {

class binary_iterator : public item_iterator
{
protected:
	rchandle<item_iterator> it1_h;
	rchandle<item_iterator> it2_h;
	rchandle<item> (*op)(rchandle<item> const&,rchandle<item> const&);

public:	// iterator interface
	void open();
	void close();
	rchandle<item> next();
	bool done();
	void rewind();

public:	// ctor,dtor
	binary_iterator(
		context *const ctx_p,
		rchandle<item_iterator>,
		rchandle<item_iterator>,
		rchandle<item> (*op)(rchandle<item> const&, rchandle<item> const&));

	~binary_iterator();

public:	// manipulators
	rchandle<item_iterator> get_it1() const { return it1_h; };
	rchandle<item_iterator> get_it2() const { return it2_h; };

};


}	/* namespace xqp */
#endif	/* XQP_BINARY_ITERATOR_H */
