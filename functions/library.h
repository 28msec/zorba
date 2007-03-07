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

#include "../context/common.h"
#include "../util/hashmap.h"
#include "../util/rchandle.h"
#include "../values/values.h"

namespace xqp {

class context;

class library : public rcobject
{
protected:
	hashmap<function> funtab;

public:
	library();
	~library();

public:
	void put(function const&);
	function* get(context *, qname_value const*);

};

} /* namespace xqp */
#endif /* XQP_LIBRARY_H */

