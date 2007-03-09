/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: common.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_COMMON_H
#define XQP_COMMON_H

#include <utility>
#include <sys/types.h>

using namespace std;
namespace xqp {

typedef uint64_t docid_t;			// document key
typedef uint64_t nodeid_t;		// node key
typedef uint64_t nskey_t;			// namespace hash key
typedef uint64_t urikey_t;		// URI hash key
typedef uint64_t qnamekey_t;	// QName hash key
typedef off_t    itemref_t;		// itemstore offset
typedef std::pair<qnamekey_t,itemref_t> qname_t;

} /* namespace xqp */
#endif /* XQP_COMMON_H */

