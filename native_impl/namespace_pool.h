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

namespace xqp {

class namespace_pool : public rcobject
{
public:
	typedef std::pair<off_t,off_t> nslocator;

protected:
	fxcharheap prefix_heap;
	fxcharheap uri_heap;
	fxvector<nslocator> ns_v; 

public:
	namespace_pool(std::string const& datapath);
	~namespace_pool();

public:

	int put(
		std::string const& prefix, 
		std::string const& uri);

	bool get(
		uint32_t key,
		std::string & prefix,
		std::string & uri) const
	throw (bad_arg);

	bool find(
		std::string const& prefix,
		std::string const& uri) const;

	uint32_t count() const;

};


} /* namespace xqp */
#endif /* XQP_NAMESPACE_POOL_H */

