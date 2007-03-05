/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname_cache.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan, Paul Pedersen
 *
 */

#include "qname_cache.h"

#include <vector>
#include <string.h>

using namespace std;
namespace xqp {

qname_cache::qname_cache(
	string const& _datapath)
:
	qname_map(	_datapath+"/qnamecache"),
	uri_map(		_datapath+"/uricache"),
	prefix_map(	_datapath+"/prefixcache")
{
}

qname_cache::~qname_cache()
{
}

bool qname_cache::put_qname(
	qnamekey_t qnamekey,
	itemref_t qnameref)
{
	return qname_map.put(qnamekey, qnameref);
}

bool qname_cache::find_qname(
	qnamekey_t qnamekey,
	uint32_t& qname_index) const
{
	return qname_map.find(qnamekey, qname_index);
}

itemref_t qname_cache::get_qname(
	qnamekey_t qnamekey) const
{
	itemref_t result;
	bool b = qname_map.get(qnamekey, result);
	return b ? result : 0;
}

uint32_t qname_cache::size() const
{
	return qname_map.size();
}

bool qname_cache::put_uri(
	urikey_t urikey,
	itemref_t uriref)
{
	return uri_map.put(urikey, uriref);
}

bool qname_cache::find_uri(
	urikey_t urikey,
	uint32_t& uri_index) const
{
	return uri_map.find(urikey, uri_index);
}

itemref_t qname_cache::get_uri(
	urikey_t urikey) const
{
	itemref_t result;
	bool b = uri_map.get(urikey, result);
	return b ? result : 0;
}

bool qname_cache::put_prefix_urikey(
	string const& prefix,
	urikey_t urikey)
{
	return prefix_map.put(prefix, urikey);
}

bool qname_cache::find_prefix_urikey(
	string const& prefix,
	uint32_t& prefix_index) const
{
	return prefix_map.find(prefix, prefix_index);
}

urikey_t qname_cache::get_prefix_urikey(
	string const& prefix) const
{
	urikey_t result;
	bool b = prefix_map.get(prefix, result);
	return b ? result : 0;
}

off_t qname_cache::put(
	string const& uri_s,
	string const& prefix_s,
	string const& name_s,
	char* store, off_t eos0)
{
	off_t eos = eos0;
	urikey_t ukey = hashfun::h32(uri_s);
	//qnamekey_t qnkey = hashfun::compose(ukey,hashfun::h32(name_s));
	qnamekey_t qnkey = ukey + 3*hashfun::h32(name_s);
	strcpy(&store[eos],uri_s.c_str());
	cout << "uri = " << &store[eos] << endl;
	put_uri(ukey,eos);
	eos += (uri_s.length()+1);
	strcpy(&store[eos],prefix_s.c_str());
	cout << "prefix = " << &store[eos] << endl;
	put_prefix_urikey(prefix_s, ukey);
	eos += (prefix_s.length()+1);
	strcpy(&store[eos],name_s.c_str());
	cout << "name = " << &store[eos] << endl;
	put_qname(qnkey, eos0);
	eos += (name_s.length()+1);
	return eos;
}

qnamekey_t qname_cache::get(
	string const& prefix_s,
	string const& name_s) const
{
	urikey_t ukey = get_prefix_urikey(prefix_s);
	return ukey + 3*hashfun::h32(name_s);
}


}	/* namespace xqp */

