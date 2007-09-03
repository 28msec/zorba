/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
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
#include "util/rchandle.h"
#include "util/URI.h"

#include <string>

namespace xqp {

class uri_resolver
{
public:
	uri_resolver() {}
	virtual ~uri_resolver() {}

public:
	std::string get_base(const URI&); 
	std::string get_base(const std::string&); 

	bool make_absolute(
	  const std::string& base,
	  const std::string& url,
	  std::string& result);

	bool make_absolute(
	  const URI& base,
	  const URI& url,
	  std::string& result);

	virtual rchandle<source> resolve(
		const std::string& base,
		const std::string& uri) = 0;

	virtual rchandle<source> resolve(
		const std::string& uri) = 0;

	virtual rchandle<source> resolve(
		const URI& base,
		const URI& uri) = 0;

	virtual rchandle<source> resolve(
		const URI& uri) = 0;

};


} /* namespace xqp */
#endif /* XQP_URI_RESOLVER_H */

