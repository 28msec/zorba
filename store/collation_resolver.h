/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collation_resolver.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_COLLATION_RESOLVER_H
#define XQP_COLLATION_RESOLVER_H

#include <string>
#include "comparator.h"
#include "../util/rchandle.h"

namespace xqp {

template <class T>
class collation_resolver
{
public:
	/**
	 * Resolve a collation URI (expressed as a string) and return 
	 * the corresponding collation. 
	 *
	 * @param uri - the collation URI
	 * @return - a comparator representing the collation to be used.
	 *   If the collation URI cannot be resolved, return NULL.
   */
	rchandle<comparator<T> > resolve(std::string const& uri)
	{
		// stub
		return NULL;
	}

};

} /* namespace xqp */
#endif /* XQP_COLLATION_RESOLVER_H */

