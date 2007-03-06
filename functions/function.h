/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: function.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */
 
#ifndef XQP_FUNCTION_H
#define XQP_FUNCTION_H

#include "signature.h"
#include "../context/context.h"
#include "../context/common.h"
#include "../runtime/iterator.h"
#include "../util/rchandle.h"
#include "../values/qname_value.h"

#include <string>
 
namespace xqp {

class function : public rcobject
{
protected:
	signature sig;
	
public:
	function(signature const& _sig) : sig(_sig) {}
	virtual ~function() {}

public:
	qname get_fname(context * ctx_p) const
		{ return sig.get_name(ctx_p); }

public:
	virtual rchandle<item_iterator> operator()(context *)
		{ return new item_iterator(NULL); }

};


} /* namespace xqp */
#endif  /* XQP_FUNCTION_H */

