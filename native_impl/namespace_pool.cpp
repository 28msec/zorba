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

#define REDUNDANT_KEY (uint32_t)-1

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

// scan prefix map for a given (docid,prefix),
// set uri_offset, return true if found
bool namespace_pool::find_prefix(
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

// scan prefix map for a given (docid,uri),
// set prefix_offset, return true if found
bool namespace_pool::ns2prefix(
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

// add (docid,prefix,uri) to the pool
uint32_t namespace_pool::put(
	uint32_t docid,
	string const& prefix,
	string const& uri)
{
	off_t uri_offset;
	if (find_prefix(docid,prefix,uri_offset)) {
		if (strcmp(uri.c_str(),uriheap.get(uri_offset))==0) return REDUNDANT_KEY;
	}
	uri_offset = uriheap.put(uri.c_str(),0,uri.length());
	uint32_t uri_id = uriv.size();
	uriv.push_back(uri_offset);
	off_t prefix_offset = uriheap.put(prefix.c_str(),0,prefix.length());
	prefix_key pkey(docid,prefix_offset,uri_offset);
	prefixv.push_back(pkey);
	return uri_id;
}

// add a set of in-scope namespace id's to the pool
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

// find a set of in-scope namespace id's 
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

bool namespace_pool::get_uri(			// return: true <-> id found
	uint32_t uri_id,								// input: namespace uri id
	string & uri) const							// output: namespace URI
throw (bad_arg)										// throw: id is out of range
{
	if (uri_id>=uriv.size()) {
		throw bad_arg(__FUNCTION__,"id out of range");
	}
	off_t uri_offset = uriv[uri_id];
	char * uri_p = uriheap.get(uri_offset);
	uri = string(uri_p,0,strlen(uri_p));
	return true;
}

bool namespace_pool::get_prefix(	// return: true <-> id found
	uint32_t docid,									// input: doc id
	uint32_t uri_id,								// input: namespace uri id
	string & prefix) const					// output: prefix, of any
throw (bad_arg)										// throw: id is out of rang
{
	if (uri_id>=uriv.size()) {
		throw bad_arg(__FUNCTION__,"id out of range");
	}
	off_t uri_offset = uriv[uri_id];
	off_t prefix_offset;
	if (ns2prefix(docid, uri_offset, prefix_offset)) {
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

