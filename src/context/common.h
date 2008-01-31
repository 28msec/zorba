/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author John Cowan,Paul Pedersen (pcp071098@yahoo.com)
 * @file context/common.h
 *
 */

#ifndef XQP_COMMON_H
#define XQP_COMMON_H

#ifndef WIN32
	#include <stdint.h>
#else
	#include "util/win32/compatib_defs.h"
#endif

#if defined (__FreeBSD__)
typedef unsigned long ulong;
#endif


#include <utility>

#ifndef _WIN32_WCE
	#include <sys/types.h>
#else
	#include <windows.h>
	#include <types.h>
#endif

#include <string>
#include "util/checked_vector.h"
#include "util/Assert.h"

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
#define XQUERY_FN_NS	"http://www.w3.org/2005/xpath-functions"
#define ZORBA_NS			XQUERY_FN_NS
#define ZORBA_PRE			"fn"
#define XQUERY_OP_NS	"http://www.w3.org/2005/xpath-functions"
#define XQUERY_PRE		"xqy"
#define NONAMESPACE		"http://nonamespace/"
#define NONS_PREFIX		"no-ns"

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

/*
 * Local variables:
 * mode: c++
 * End:
 */
