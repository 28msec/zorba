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
#include "../runtime/abstract_iterator.h"
#include "../util/rchandle.h"
#include "../values/abstract_values.h"

#include <string>
 
namespace xqp {

class function : public rcobject
{
public:
	typedef rchandle<abstract_iterator> iterator_t;
protected:
	signature sig;
	
public:
	function(const signature& _sig) : sig(_sig) {}
	virtual ~function() {}

public:
	const abstract_qname* get_fname(context* ctx_p) const
		{ return (abstract_qname*)sig.get_name(); }

public:
	virtual iterator_t operator()(context *) { return NULL; }

};


} /* namespace xqp */
#endif  /* XQP_FUNCTION_H */

