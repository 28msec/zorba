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

#include "source.h"
#include <string>
#include <vector>

namespace xqp {

class schema_resolver
{
	 /**
	 * Resolve a query module from the target namespace URI
	 * and set of associated location hints. 
	 * @param base_uri  -  input: base URI of the importing module
	 * @param target_uri - input: schema target namespace URI
	 * @param location_v - input: "at" location hints
	 * @param source_v -  output: list of schema 'source's
	 * @return - true <=> schema is found, false otherwise
	 */
	bool resolve(
		std::string const& base_uri,
		std::string const& module_uri,
		std::vector<std::string> const& location_v,
		std::vector<source> & source_v);

};


} /* namespace xqp */
#endif /* XQP_SCHEMA_RESOLVER_H */

