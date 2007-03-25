/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dom_namepool.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_DOM_NAMEPOOL_H
#define XQP_DOM_NAMEPOOL_H

#include "../context/common.h"
#include "../util/fxhashmap.h"
#include "../util/rchandle.h"

#include <string>

/*===========================================================+
|                                                            |
|  Name pool: namespaces, QNames 				                     |
|                                                            |
+============================================================*/

namespace xqp {

class dom_qname;

class dom_namepool : public rcobject
{
protected:
	fxhash64map<dom_qname*> qname_map;	// map: qnamekey -> dom_qname*

public:
	dom_namepool();
	~dom_namepool() {}

public:
	// qnames
	qnamekey_t put_qname(							// return: qname key
		dom_qname* qname_p);						// input:  dom qname*

	bool get_qname(										// return: true <-> found
		const qnamekey_t&,							// input:  qname key
		dom_qname*& qname_p) const;			// output: dom qname*

};


} /* namespace xqp */
#endif /* XQP_DOM_NAMEPOOL_H */

