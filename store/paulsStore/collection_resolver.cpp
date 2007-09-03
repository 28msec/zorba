/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection_resolver.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: Paul Pedersen
 *
 */

#include "collection_resolver.h"

#include <string>

using namespace std;
namespace xqp {

Iterator_t resolve(
	static_context*,
	std::string const& base,
	std::string const& href)
throw (xqp_exception)
{
	return NULL;
}


} /* namespace xqp */

