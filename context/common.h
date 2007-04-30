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

#include "../util/rchandle.h"

#include <utility>
#include <sys/types.h>
#include <string>

using namespace std;
namespace xqp {

// zorba id types
typedef uint32_t itemid_t;		// item identifier
typedef uint32_t docid_t;			// document identifier

// zorba key tyeps
typedef uint64_t nskey_t;			// namespace hash key
typedef uint64_t urikey_t;		// URI hash key
typedef uint64_t qnamekey_t;	// QName hash key

// zorba reference types
typedef uint32_t offset_t;    // itemstore short offset

// namespaces
#define ZORBA_NS			"http://www.zorba.org/"
#define XQUERY_FN			"http://www.w3.org/2005/xpath-functions"
#define NONAMESPACE		"http://nonamespace/"
#define NONS_PREFIX		"no-ns"


// iterator type
class item_iterator;
typedef rchandle<item_iterator> iterator_t;


typedef struct qnamekeyref
{
	qnamekey_t qnamekey;
	off_t qnameref;

	qnamekeyref(qnamekey_t _qnamekey, off_t _qnameref)
	: qnamekey(_qnamekey), qnameref(_qnameref) {}

} qnamekeyref_t;


typedef struct qnamepair
{
	qnamekey_t qnamekey;
	off_t qnameref;

	qnamepair(qnamekey_t _qnamekey, off_t _qnameref)
	: qnamekey(_qnamekey), qnameref(_qnameref) {}

} qnamepair_t;


typedef struct attrname
{
	off_t uriref;
	std::string name;

	attrname(off_t _uriref, const std::string& _name)
	: uriref(_uriref), name(_name) {}

} attrname_t;


typedef struct attrpair
{
	off_t attrref;
	std::string value;

	attrpair(off_t _attrref, const std::string& _value)
	: attrref(_attrref), value(_value) {}

} attrpair_t;


typedef struct elempair
{
	qnamekey_t qnamekey;
	off_t noderef;

	elempair(qnamekey_t _qnamekey, off_t _noderef)
	: qnamekey(_qnamekey), noderef(_noderef) {}

} elempair_t;


} /* namespace xqp */
#endif /* XQP_COMMON_H */

