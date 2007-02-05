/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: qname_pool.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_QNAME_POOL_H
#define XQP_QNAME_POOL_H

#include "namespace_pool.h"
#include "../util/fxcharheap.h"
#include "../util/fxvector.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"
#include "../values/qname_value.h"

#include <string>
#include <utility>
#include <vector>

/*===========================================================+
|                                                            |
|  QName pool,                                               |
|                                                            |
|  The following files support persistence of                |
|  the pool:                                                 |
|                                                            |
|    nspool  :  persistent namespace pool                    |
|    qnamev  :  persistent vector of qname ids               |
|    qnheap  :  persistent charheap of localnames            |
|                                                            |
+============================================================*/

namespace xqp {

struct qname_key
{
	off_t qn_offset;
	uint32_t uri_id;
	QName::qname_type_t type;

	qname_key( off_t _qn_offset, uint32_t _uri_id, QName::qname_type_t _type)
	: qn_offset(_qn_offset), uri_id(_uri_id), type(_type) { }

	~qname_key() {}
};


class qname_pool : public rcobject
{
protected:
	std::string datapath;
	rchandle<namespace_pool> nspool_h;
	fxvector<qname_key> qnamev;
	fxcharheap qnheap;

public:
	qname_pool(
		std::string const& datapath,
		rchandle<namespace_pool>);

	~qname_pool();

public:
	/**
	** add (docid,qname) to the pool
	*/
	uint32_t put(									// return: id of new, or previous
		uint32_t docid,							// input: document id
		QName::qname_type_t type,		// input: QName type
		string const& qname);				// input: "prefix:localname" string

	/**
	** add (docid,qname) to the pool
	*/
	uint32_t put(									// return: id of new, or previous
		uint32_t docid,							// input: document id
		rchandle<QName> qname);			// input: (parsed) QName

	/**
	** find qname_id for a given uri_id
	*/
	bool find(										// return: true <-> uri_id found
		uint32_t uri_id,						// input: uri index
		uint32_t& qname_id					// output: qname index, if found
	) const;

	/**
	** return QName for a given uri_id
	*/
	rchandle<QName> get(					// return: new QName or NULL, if not found
		uint32_t qname_id) const;		// input: qname index

	/**
	** return count of qnames in the pool
	*/
	uint32_t count() const;

};


} /* namespace xqp */
#endif /* XQP_QNAME_POOL_H */

