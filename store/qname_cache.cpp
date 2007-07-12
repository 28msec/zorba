/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: qname_cache.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan, Paul Pedersen
 *
 */

#include "qname_cache.h"
#include <string>

using namespace std;
namespace xqp {

qname_cache::qname_cache(
	const string& _datapath)
:
	qname_map( _datapath+"/qncache_",  0.6f, 1<<16),
	uri_map(   _datapath+"/uricache_", 0.6f, 1<<16)
{
}

qname_cache::qname_cache()
:
	qname_map( 0.6f, 1<<16),
	uri_map(   0.6f, 1<<16)
{
}


// URIs by key

bool qname_cache::put_uri(
	const string& prefix,
	nodeid_t uri)
{
	uint64_t pkey = hashfun::h64(prefix);
	return uri_map.put(pkey, uri);
}

bool qname_cache::contains_uri(
	const string& prefix) const
{
	uint32_t index;
	uint64_t pkey = hashfun::h64(prefix);
	return uri_map.find(pkey, index);
}

bool qname_cache::get_uri(
	const string& prefix,
	nodeid_t& uri) const
{
	uint64_t pkey = hashfun::h64(prefix);
	return uri_map.get(pkey, uri);
}



// qnames by value

bool qname_cache::put(
	const string& prefix,
	const string& localname,
	nodeid_t qname)
{
	uint64_t ukey = hashfun::h64(prefix);
	qnamekey_t qnkey = hashfun::h64(localname.c_str(),ukey);
	return qname_map.put(qnkey, qname);
}

bool qname_cache::get(
	const string& prefix,
	const string& localname,
	nodeid_t& qname) const
{
	uint64_t ukey = hashfun::h64(prefix);
	qnamekey_t qkey = hashfun::h64(localname.c_str(),ukey);
	return qname_map.get(qkey, qname);
}


}	/* namespace xqp */

