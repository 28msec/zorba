/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: qname_cache.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_QNAME_CACHE_H
#define XQP_QNAME_CACHE_H

#include "../context/common.h"
#include "../util/fxhashmap.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"

#include <string>

/*===========================================================+
|                                                            |
|  QName cache                                               |
|                                                            |
+============================================================*/

namespace xqp {

class qname_cache : public rcobject
{
protected:
	fxhash64map<itemid_t> qname_map;		// map: qname -> itemid
	fxhash64map<itemid_t> uri_map;			// map: prefix -> itemid

public:
	qname_cache(const std::string& datapath);
	qname_cache();
	~qname_cache() {}

public:
	uint32_t size() const { return qname_map.size(); }

	// map: qname -> qnameref 
	bool put(
		const std::string& prefix,
		const std::string& localname,
		itemid_t qnameid );

	bool get(
		const std::string& prefix,
		const std::string& localname,
		itemid_t& qnameid) const;

	// map: prefix -> uri 
	bool put_uri( const std::string&, itemid_t uriid );
	bool get_uri( const std::string&, itemid_t& uriid ) const;
	bool contains_uri( const std::string& ) const;

};


} /* namespace xqp */
#endif /* XQP_QNAME_CACHE_H */

