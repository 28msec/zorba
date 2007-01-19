/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: var_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_VAR_ITERATOR_H
#define XQP_VAR_ITERATOR_H

#include "item_iterator.h"
#include "../values/qname_value.h"

namespace xqp {

class var_iterator : public item_iterator
{
protected:
	rchandle<QName> varname_h;

public:	// iterator interface
	void open();
	void close();
	rchandle<item> next();
	bool done();
	void rewind();

public:	// ctor,dtor
	var_iterator(
		context const& ctx,
		rchandle<QName>);

	~var_iterator();

public:	// manipulators
	rchandle<QName> get_varname() const { return varname_h; };

};


}	/* namespace xqp */
#endif	/* XQP_VAR_ITERATOR_H */
