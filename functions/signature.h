/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: signature.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */
 
#ifndef XQP_SIGNATURE_H
#define XQP_SIGNATURE_H

#include "../context/common.h"
#include "../types/sequence_type.h"
#include "../util/fxhashmap.h"
#include "../util/rchandle.h"
#include <vector>

namespace xqp {

/*______________________________________________________________________
|  
|	By convention arg_v[0] = return type
|	              arg_v[1] = first input argument type
|	              arg_v[2] = second input argument type
|	               ...     =  ...                         
|_______________________________________________________________________*/

class context;

class signature : public rcobject
{
public:
	qnameid_t qname;
	std::vector<sequence_type_t> arg_v;
	static fxhashmap<signature const*> sigmap;

public:
	signature(qnameid_t _qname, sequence_type_t return_type);
	~signature();

public:
	void add_arg(sequence_type_t t) { arg_v.push_back(t); }
	uint32_t arg_count() const { return arg_v.size(); }
	sequence_type_t const& operator[](int i) const { return arg_v[i]; }
	sequence_type_t & operator[](int i) { return arg_v[i]; }
	sequence_type_t const& return_type() const { return arg_v[0]; }
	sequence_type_t & return_type() { return arg_v[0]; }
	qnameid_t get_name() const { return qname; }

};

} /* namespace xqp */
#endif  /* XQP_SIGNATURE_H */

