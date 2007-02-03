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

/*+====================================================+
	| 
	|  Namespace URI pool, 
	|  Namespace sets pool,
	|  prefix -> namespace mapping
	| 
	|	 We do not currently support:
	|    overloaded prefixes (same prefix to different URIs
	|    within same doc).
	| 
	+====================================================+ */

namespace xqp {

struct prefix_key
{
	uint32_t docid;
	off_t prefix_offset;
	off_t uri_offset;

	prefix_key(
		uint32_t _docid,
		off_t _prefix_offset,
		off_t _uri_offset)
	:
		docid(_docid),
		prefix_offset(_prefix_offset),
		uri_offset(_uri_offset)
	{}

	~prefix_key() {}

};


class namespace_pool : public rcobject
{
protected:
	// (namespace key) -> uri string
	fxcharheap uriheap;						// zero-delimted strings heap
	fxvector<off_t> uriv;					// map: uriv[id] = uriheap offset

	// (namespace set key) -> namespace key list
	fxvector<uint32_t> nsheap;		// ns_id heap, encoded as (len,ns_id,..,ns_id)
	fxvector<uint32_t> nsv;				// map: nsv[ns_id] = nsheap offset

	// prefix map
	fxvector<prefix_key> prefixv;	// map: prefixv[pre_id] = (docid,prefix-offset,ns-offset)

public:
	namespace_pool(std::string const& datapath);
	~namespace_pool();

public:

	// scan prefix map for a given (docid,prefix),
	// set uri_offset, return true if found
	bool find_prefix(
		uint32_t docid,
		string const& prefix,
		off_t & uri_offset);

	// scan prefix map for a given (docid,uri),
	// set prefix_offset, return true if found
	bool ns2prefix(
		uint32_t docid,
		off_t uri_offset,
		off_t & prefix_offset) const;

	// add (docid,prefix,uri) to the pool
	uint32_t put(
		uint32_t docid,
		string const& prefix,
		string const& uri);

	// add a set of in-scope namespace id's to the pool
	uint32_t put_nslist(
		std::vector<uint32_t> nslist);

	// find a set of in-scope namespace id's 
	bool get_nslist(
		uint32_t id,
		std::vector<uint32_t> & nslist);

	// find the URI for a given id
	bool get_uri(								// return: true <-> id found
		uint32_t uri_id,					// input: namespace id
		string & uri) const				// output: namespace URI
	throw (bad_arg);						// throw: id is out of range

	// find the prefix for a given (docid,uri) 
	bool get_prefix(						// return: true <-> id found
		uint32_t docid,						// input: doc id
		uint32_t uri_id,					// input: namespace id
		string & prefix) const		// output: prefix, of any
	throw (bad_arg);						// throw: id is out of range

	uint32_t count() const;

};


} /* namespace xqp */
#endif /* XQP_NAMESPACE_POOL_H */

