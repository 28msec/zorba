/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: namespace.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author:  Paul Pedersen
 *
 */

#ifndef XQP_NAMESPACE_H
#define XQP_NAMESPACE_H

#include <string>

namespace xqp {

class name_space
{
protected:
	std::string uri;

public:
	name_space(std::string const& _uri) : uri(_uri) {}
	name_space() {}
	~name_space() {}

public:
	std::string get_uri() const { return uri; }

};


}	/* namespace xqp */
#endif	/* XQP_NAMESPACE_H */
