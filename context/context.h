/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: abstract_context.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_CONTEXT_H
#define XQP_CONTEXT_H

#include "common.h"
#include "../runtime/abstract_iterator.h"
#include "../values/abstract_qname.h"

#include "../util/rchandle.h"
#include "../util/xqp_exception.h"

namespace xqp {

/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

class context : public rcobject
{
public:
	typedef rchandle<abstract_iterator> iterator_t; 

public:
	// context interface
	virtual rchandle<context> parent() const = 0;
	virtual iterator_t context_value(qnamekey_t key) const = 0;

};


}	/* namespace xqp */
#endif /*	XQP_CONTEXT_H */

