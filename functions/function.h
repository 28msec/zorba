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
#include "context/common.h"
#include "runtime/item_iterator.h"
#include "runtime/zorba.h"
#include "values/qname.h"
#include "util/rchandle.h"

#include <string>
#include <vector>
 
namespace xqp {

class function : public rcobject
{
protected:
	signature sig;
	
public:
	function() {}
	function(const signature& _sig) : sig(_sig) {}
	virtual ~function() {}

public:
	// XQuery signature (name+arity)
	const qname* get_fname() const { return sig.get_name(); }
	void set_signature(signature& _sig) { sig = _sig; }

	// codegen: functor specification
	virtual iterator_t operator()(zorba*,std::vector<iterator_t>& argv) = 0;

	// polymorphic type inference
	virtual sequence_type_t type_check(signature&) = 0;

	// runtime arg validation: XXX move this out
	virtual bool validate_args(std::vector<iterator_t>& argv) = 0;

};

/*
class user_function : public function
{
private:
	parsenode* body_node;
	expr* body_expr;

};
*/


} /* namespace xqp */
#endif  /* XQP_FUNCTION_H */

