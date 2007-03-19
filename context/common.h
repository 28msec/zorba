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
#include <string>

using namespace std;
namespace xqp {

typedef uint32_t nodeid_t;		// node id
typedef uint32_t qnameid_t;		// qname id
typedef uint64_t nskey_t;			// namespace hash key
typedef uint64_t urikey_t;		// URI hash key
typedef uint64_t qnamekey_t;	// QName hash key
typedef uint32_t itemref_t;		// itemstore offset
typedef uint32_t offset_t;    // itemstore short offset

#define NONAMESPACE	"http://nonamespace"
#define NON_PREFIX	"non#prefix"

typedef struct {
	qnamekey_t qnamekey;
	itemref_t qnameref;
} qname_t;

typedef struct {
	qnameid_t qnameid;
	itemref_t qnameref;
} qnamepair_t;

typedef struct {
	itemref_t uriref;
	std::string name;
} attrname_t;

typedef struct {
	itemref_t attrref;
	std::string value;
} attrpair_t;

typedef struct {
	qnamekey_t qnamekey;
	itemref_t noderef;
} elempair_t;


} /* namespace xqp */
#endif /* XQP_COMMON_H */

