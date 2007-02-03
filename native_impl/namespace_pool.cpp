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
#include <string.h>

using namespace std;
namespace xqp {


namespace_pool::namespace_pool(
	string const& datapath)
:
	uriheap(datapath+"/uriheap",1<<16),
	uriv(datapath+"/uriv"),
	nsheap(datapath+"/nsheap"),
	nsv(datapath+"/nsv"),
	prefixv(datapath+"/pmap")
{
}


namespace_pool::~namespace_pool()
{
}


bool namespace_pool::prefix2uri(
	uint32_t docid,
	string const& prefix,
	off_t & uri_offset)
{
	fxvector<prefix_key>::const_iterator it = prefixv.begin();
	for (; it!=prefixv.end(); ++it) {
		prefix_key k = *it;
		if (docid==k.docid) {
			if (strcmp(prefix.c_str(),uriheap.get(k.prefix_offset))==0) {
				uri_offset = k.uri_offset;
				return true;
			}
		}
	}
	return false;
}


bool namespace_pool::uri2prefix(
	uint32_t docid,
	off_t uri_offset,
	off_t & prefix_offset) const
{
	fxvector<prefix_key>::const_iterator it = prefixv.begin();
	for (; it!=prefixv.end(); ++it) {
		prefix_key k = *it;
		if (docid==k.docid && uri_offset==k.uri_offset) {
			prefix_offset = k.prefix_offset;
			return true;
		}
	}
	return false;
}


uint32_t namespace_pool::put(
	uint32_t docid,
	string const& prefix,
	string const& uri)
{
	uint32_t uri_id;
	if (find(docid,prefix,uri,uri_id)) return uri_id;

	// not found: stuff it, and return new id
	off_t uri_offset = uriheap.put(uri.c_str(),0,uri.length());
	uri_id = uriv.size();
	uriv.push_back(uri_offset);
	off_t prefix_offset = uriheap.put(prefix.c_str(),0,prefix.length());
	prefix_key pkey(docid,prefix_offset,uri_offset);
	prefixv.push_back(pkey);
	return uri_id;
}


bool namespace_pool::find(
	uint32_t docid,
	string const& prefix,
	string const& uri,
	uint32_t& id) const
{
	for (uint32_t uri_id=0; uri_id<uriv.size(); ++uri_id) {
		off_t uri_offset = uriv[uri_id];
		if (strcmp(uri.c_str(),uriheap.get(uri_offset))==0) {
			string prefix0;
			if (get_prefix(docid,uri_id,prefix0)) {
				if (prefix==prefix0) {
					id = uri_id;
					return true;
				}
			}
		}
	}
	return false;
}


uint32_t namespace_pool::put_nslist(
	vector<uint32_t> nslist)
{
	uint32_t ns_id = nsv.size();
	nsheap.push_back(nslist.size());
	vector<uint32_t>::const_iterator it = nslist.begin();
	for (; it!=nslist.end(); ++it) {
		nsv.push_back(*it);
	}
	return ns_id;
}


bool namespace_pool::get_nslist(
	uint32_t id,
	vector<uint32_t> & nslist)
{
	uint32_t ns_offset = nsv[id];
	uint32_t len = nsheap[ns_offset++];
	for (uint32_t k=ns_offset; k<ns_offset+len; ++k) {
		nslist.push_back(nsheap[k]);
	}
	return true;
}


bool namespace_pool::get_uri(
	uint32_t uri_id,					
	string & uri) const			
throw (bad_arg)					
{
	if (uri_id>=uriv.size()) {
		throw bad_arg(__FUNCTION__,"id out of range");
	}
	off_t uri_offset = uriv[uri_id];
	char * uri_p = uriheap.get(uri_offset);
	uri = string(uri_p,0,strlen(uri_p));
	return true;
}


bool namespace_pool::get_prefix(
	uint32_t docid,							
	uint32_t uri_id,					
	string & prefix) const	
throw (bad_arg)					
{
	if (uri_id>=uriv.size()) {
		throw bad_arg(__FUNCTION__,"id out of range");
	}
	off_t uri_offset = uriv[uri_id];
	off_t prefix_offset;
	if (uri2prefix(docid, uri_offset, prefix_offset)) {
		char* prefix_p = uriheap.get(prefix_offset);
		prefix = string(prefix_p,0,strlen(prefix_p));
	}
	else {
		return false;
	}
	return true;
}


uint32_t namespace_pool::count() const
{
	return uriv.size();
}
 
  
} /* namespace xqp */

