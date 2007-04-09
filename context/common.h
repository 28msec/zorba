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
typedef uint32_t docid_t;			// document id

typedef uint64_t nskey_t;			// namespace hash key
typedef uint64_t urikey_t;		// URI hash key
typedef uint64_t qnamekey_t;	// QName hash key

typedef uint32_t itemref_t;		// itemstore offset
typedef uint32_t offset_t;    // itemstore short offset

#define ZORBA 			"http://www.zorba.org/"
#define NONAMESPACE	"http://nonamespace/"
#define NONS_PREFIX	"no-ns"


typedef struct qnamekeyref
{
	qnamekey_t qnamekey;
	itemref_t qnameref;

	qnamekeyref(qnamekey_t _qnamekey, itemref_t _qnameref)
	: qnamekey(_qnamekey), qnameref(_qnameref) {}

} qnamekeyref_t;


typedef struct qnamepair
{
	qnamekey_t qnamekey;
	itemref_t qnameref;

	qnamepair(qnamekey_t _qnamekey, itemref_t _qnameref)
	: qnamekey(_qnamekey), qnameref(_qnameref) {}

} qnamepair_t;


typedef struct attrname
{
	itemref_t uriref;
	std::string name;

	attrname(itemref_t _uriref, const std::string& _name)
	: uriref(_uriref), name(_name) {}

} attrname_t;


typedef struct attrpair
{
	itemref_t attrref;
	std::string value;

	attrpair(itemref_t _attrref, const std::string& _value)
	: attrref(_attrref), value(_value) {}

} attrpair_t;


typedef struct elempair
{
	qnamekey_t qnamekey;
	itemref_t noderef;

	elempair(qnamekey_t _qnamekey, itemref_t _noderef)
	: qnamekey(_qnamekey), noderef(_noderef) {}

} elempair_t;


} /* namespace xqp */
#endif /* XQP_COMMON_H */

