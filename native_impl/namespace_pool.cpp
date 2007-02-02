/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: namespace_pool.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "namespace_pool.h"

#include <vector>

using namespace std;
namespace xqp {


namespace_pool::namespace_pool(
	std::string const& datapath)
:
	prefix_heap(datapath+"/ns_prefix", 1<<16),
	uri_heap(datapath+"/ns_uri", 1<<!6),
	ns_v(datapath+"/ns_v")
{
}

namespace_pool::~namespace_pool()
{
}

int namespace_pool::put(
	string const& prefix,
	string const& uri)
{
	if (find(prefix,uri)) return -1;
	off_t prefix_offset = prefix_heap.put(prefix.c_str(), 0, prefix.length());
	off_t uri_offset = uri_heap.put(uri.c_str(), 0, uri.length());
	nslocator loc(prefix_offset, uri_offset);
	uint32_t result = ns_v.size();
	ns_v.push_back(loc);
	return result;
}

bool namespace_pool::get(
	uint32_t key,
	string & prefix,
	string & uri) const
throw (bad_arg)
{
	if (key>=ns_v.size()) {
		throw xqp_exception(__FUNCTION__,"key is out of range");
	}
	nslocator loc = ns_v[key];
	off_t prefix_offset = loc.first;
	off_t uri_offset = loc.second;
	char * prefix_p = prefix_heap.get(prefix_offset);
	char * uri_p = uri_heap.get(uri_offset);
	prefix = string(prefix_p,0,strlen(prefix_p));
	uri = string(uri_p,0,strlen(uri_p));
	return true;
}

bool namespace_pool::find(
	string const& prefix,
	string const& uri) const
{
	fxvector<nslocator>::const_iterator it = ns_v.begin();
	for (; it!=ns_v.end(); ++it) {
		nslocator loc = *it;
		off_t prefix_offset = loc.first;
		off_t uri_offset = loc.second;
		char * prefix_p = prefix_heap.get(prefix_offset);
		char * uri_p = uri_heap.get(uri_offset);
		if (strcmp(prefix_p,prefix.c_str())) continue;
		if (strcmp(uri_p,uri.c_str())) continue;
		return true;
	}
	return false;
}

uint32_t namespace_pool::count() const
{
	return ns_v.size();
}

 
  
} /* namespace xqp */

