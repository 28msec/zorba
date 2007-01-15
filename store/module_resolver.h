/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: module_resolver.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_MODULE_RESOLVER_H
#define XQP_MODULE_RESOLVER_H

#include "source.h"
#include <string>
#include <vector>

namespace xqp {

class module_resolver
{
	 /**
	 * Resolve a query module from the target namespace URI
	 * and a set of associated location hints. 
	 *
	 * @param base_uri   - input: base URI of the importing module
	 * @param module_uri - input: module target namespace URI
	 * @param location_v - input: "at" location hints
	 * @param source_v   - output: vector of source objects
	 * @return - false <=> module not found
	 */
	bool resolve(
		std::string const& base_uri,
		std::string const& module_uri,
		std::vector<std::string> const& location_v,
		std::vector<source>& source_v);

};


} /* namespace xqp */
#endif /* XQP_MODULE_RESOLVER_H */

