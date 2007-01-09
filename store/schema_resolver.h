/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: schema_resolver.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_SCHEMA_RESOLVER_H
#define XQP_SCHEMA_RESOLVER_H

#include <string>
#include "../datasrc/source.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"

namespace xqp {

class schema_resolver
{
	 /**
	 * Resolve a query module from the target namespace URI
	 * and set of associated location hints. 
	 * @param base_uri - base URI of the importing module
	 * @param target_uri - schema target namespace URI
	 * @param location_v - "at" location hints
	 * @return a list of 'source' schema documents
	 * @throws xqp_exception - if the schema cannot be located
	 */
	rchandle<source_list> resolve(
		std::string const& base_uri,
		std::string const& module_uri,
		std::vector<std::string> const& location_v)
	throw (xqp_exception);

};


} /* namespace xqp */
#endif /* XQP_SCHEMA_RESOLVER_H */

