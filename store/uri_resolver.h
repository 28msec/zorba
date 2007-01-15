/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: uri_resolver.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_URI_RESOLVER_H
#define XQP_URI_RESOLVER_H

#include "source.h"
#include "../util/rchandle.h"
#include "../util/URI.h"

#include <string>

namespace xqp {

class uri_resolver
{
public:
	uri_resolver() {}
	~uri_resolver() {}

public:
	std::string get_base(URI const&); 
	std::string get_base(std::string const&); 

	bool make_absolute(
	  std::string const& base,
	  std::string const& url,
	  std::string& result);

	bool make_absolute(
	  URI const& base,
	  URI const& url,
	  std::string& result);

	rchandle<source> resolve(
		std::string const& base,
		std::string const& uri);

	rchandle<source> resolve(
		URI const& base,
		URI const& uri);

};


} /* namespace xqp */
#endif /* XQP_URI_RESOLVER_H */

