/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: function_library.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_LIBRARY_H
#define XQP_LIBRARY_H

#include "../util/hashmap.h"
#include "../util/rchandle.h"
#include "../values/values.h"

namespace xqp {

class function;
class qname_value;

class library : public rcobject
{
protected:
	hashmap<const function*> funtab;

public:
	library();
	~library();

public:
	void put(const function*);
	const function* get(const qname_value*);

};

} /* namespace xqp */
#endif /* XQP_LIBRARY_H */

