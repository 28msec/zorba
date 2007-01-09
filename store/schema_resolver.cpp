/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: schema_resolver.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "schema_resolver.h"
#include "../datasrc/source.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"

#include <string>
#include <vector>

using namespace std;
namespace xqp {

rchandle<source_list> schema_resolver::resolve(
	string const& base_uri,
	string const& schema_target_uri,
	vector<string> const& location_v)
throw (xqp_exception)
{
	rchandle<source_list> v_h = new source_list();
	return v_h;
}


} /* namespace xqp */

