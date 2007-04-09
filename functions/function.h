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
#include "../context/common.h"
#include "../runtime/abstract_iterator.h"
#include "../values/abstract_values.h"
#include "../util/list.h"
#include "../util/rchandle.h"

#include <string>
 
namespace xqp {

class function : public rcobject
{
public:
	typedef rchandle<abstract_iterator> iterator_t;

protected:
	abstract_qname* fname;
	signature sig;

	// polymorphism inference
	sequence_type_t (*type_checker)(signature);
	
public:
	function(const signature&);
	virtual ~function() {}

public:
	const abstract_qname* get_fname() const;
	virtual iterator_t operator()(list<void*>);

};


} /* namespace xqp */
#endif  /* XQP_FUNCTION_H */

