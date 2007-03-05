/* -*- mode: c++; indent-tabs-mode: nil -*-
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
#include <vector>

/*===========================================================+
|                                                            |
|  QName cache                                               |
|                                                            |
+============================================================*/

namespace xqp {

class qname_cache : public rcobject
{
protected:
	fxhash64map<itemref_t> qname_map;		// map: qnamekey_t -> qname itemref
	fxhash64map<itemref_t> uri_map;			// map: urikey_t -> uri itemref
	fxhashmap<urikey_t> prefix_map;			// map: prefix -> uri hash key

public:
	qname_cache(std::string const& datapath);
	~qname_cache();

public:
	bool put_qname( qnamekey_t qnamekey, itemref_t qnameref );
	bool find_qname( qnamekey_t qnamekey, uint32_t& index ) const;
	itemref_t get_qname( qnamekey_t qnamekey ) const;

	uint32_t size() const;

	bool put_uri( urikey_t urikey, itemref_t uriref );
	bool find_uri( urikey_t urikey, uint32_t& index ) const;
	itemref_t get_uri( urikey_t urikey ) const;

	bool put_prefix_urikey( std::string const& prefix, urikey_t urikey );
	bool find_prefix_urikey( std::string const& prefix, uint32_t& index ) const;
	urikey_t get_prefix_urikey( std::string const& prefix ) const;

	off_t put(
		std::string const& uri_s,
		std::string const& prefix_s,
		std::string const& name_s,
		char* store, off_t eos);

	qnamekey_t get(
		std::string const& prefix_s,
		std::string const& name_s) const;

};


} /* namespace xqp */
#endif /* XQP_QNAME_CACHE_H */

