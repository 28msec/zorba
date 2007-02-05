/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: namespace_pool.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_NAMESPACE_POOL_H
#define XQP_NAMESPACE_POOL_H

#include "../util/fxcharheap.h"
#include "../util/fxvector.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"

#include <string>
#include <utility>
#include <vector>

 /*============================================================+
	|                                                            |
	|  Namespace URI pool,                                       |
	|  Namespace sets pool,                                      |
	|  prefix -> namespace mapping                               |
	|                                                            |
	|	 We do not currently support:                              |
	|    overloaded prefixes (same prefix to different URIs      |
	|    within same doc).                                       |
	|                                                            |
	|  The following files support persistence of                |
	|  the pool:                                                 |
	|    nsheap  :  persistent heap of namespace sets            |
	|    nsv     :  persistent vector of namespace set ids       |
	|    pmap    :  persistent vector of prefix keys             |
	|    uriheap :  persistent charheap of uris and prefixes     |
	|    uriv    :  persistent vector of namespace uri ids       |
	|                                                            |
	+============================================================*/

namespace xqp {

struct prefix_key
{
	uint32_t docid;
	off_t prefix_offset;
	off_t uri_offset;
	uint32_t uri_id;

	prefix_key(
		uint32_t _docid,
		off_t _prefix_offset,
		off_t _uri_offset,
		uint32_t _uri_id)
	:
		docid(_docid),
		prefix_offset(_prefix_offset),
		uri_offset(_uri_offset),
		uri_id(_uri_id)
	{}

	~prefix_key() {}

};


class namespace_pool : public rcobject
{
public:
	typedef std::vector<uint32_t> nslist_t;

protected:
	string datapath;

	// (namespace key) -> uri string
	fxcharheap uriheap;						// zero-delimted strings heap
	fxvector<off_t> uriv;					// map: uriv[id] = uriheap offset

	// (namespace set key) -> namespace key list
	fxvector<uint32_t> nsheap;		// ns_id heap, encoded as (len,ns_id,..,ns_id)
	fxvector<uint32_t> nsv;				// map: nsv[ns_id] = nsheap offset

	// prefix map
	fxvector<prefix_key> prefixv;	// map: prefixv[pre_id] = prefix_key

public:
	namespace_pool(std::string const& datapath);
	~namespace_pool();

public:
	/**
	** map: prefix -> uri_offset,uri_id
	*/
	bool prefix2uri(							// return: true <-> prefix found
		uint32_t docid,							// input: document id
		string const& prefix,				// input: namespace prefix
		off_t & uri_offset,					// output: namespace uri_offset
		uint32_t & uri_id) const;		// output: namespace uri_id

	/**
	** map: uri -> prefix
	*/
	bool uri2prefix(							// return true <-> (docid,uri) found
		off_t uri_offset,						// input: uri
		off_t & prefix_offset				// output: prefix_offset
	) const;

	/**
	** add (docid,prefix,uri) to the pool
	*/
	uint32_t put(									// return: id of new, or previous
		uint32_t docid,							// input: document id
		string const& prefix,				// input: prefix
		string const& uri);					// input: uri

	/**
	** find id for a given (docid,prefix,uri)
	*/
	bool find(										// return: true <-> (docid,prefix,uri) found
		uint32_t docid,							// input: document id
		string const& prefix,				// input: namespace prefix
		string const& uri,					// input: namespace uri
		uint32_t& id) const;				// output: namespace id, if found

	/**
	** add set of (in-scope) namespaces to the pool
	*/
	uint32_t put_nslist(					// return: id of name list
		nslist_t nslist);						// input: list of namespaces

	/**
	** find a set of in-scope namespaces 
	*/
	bool get_nslist(							// return true <-> namespace set found
		uint32_t id,								// input: namespace set id
		nslist_t & nslist);					// output: list of namespace ids

	/**
	** find the URI for a given id
	*/
	bool get_uri(									// return: true <-> id found
		uint32_t uri_id,						// input: namespace id
		string & uri) const					// output: namespace URI
	throw (bad_arg);							// throw: id is out of range

	/**
	** find the prefix for a given (docid,uri) 
	*/
	bool get_prefix(							// return: true <-> id found
		uint32_t uri_id,						// input: namespace id
		string & prefix) const			// output: prefix, of any
	throw (bad_arg);							// throw: id is out of range

	/**
	** return count of namespaces in the pool
	*/
	uint32_t count() const;

};


} /* namespace xqp */
#endif /* XQP_NAMESPACE_POOL_H */

