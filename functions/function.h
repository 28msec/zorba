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
#include "../values/values.h"

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
	qname_value const* get_fname(context * ctx_p) const
		{ return sig.get_name(); }

public:
	virtual rchandle<abstract_iterator> operator()(context *)
		{ return &abstract_iterator::emptySequence; }

};


} /* namespace xqp */
#endif  /* XQP_FUNCTION_H */

