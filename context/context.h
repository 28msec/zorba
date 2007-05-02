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
#include "runtime/item_iterator.h"
#include "values/qname.h"
#include "util/fxhashmap.h"
#include "util/rchandle.h"
#include "util/xqp_exception.h"

namespace xqp {

class zorba;

/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

class context : public rcobject
{
protected:
	rchandle<context> parent_h;
	fxhash64map<iterator_t> keymap;

public: // context interface
	rchandle<context> parent() const { return parent_h; }

	iterator_t context_value(qnamekey_t key) const
	{
		iterator_t it_h;
		if (!keymap.get(key, it_h)) return NULL;
		return it_h;
	}

};


}	/* namespace xqp */
#endif /*	XQP_CONTEXT_H */

