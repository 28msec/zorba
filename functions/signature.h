/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: signature.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */
 
#ifndef XQP_SIGNATURE_H
#define XQP_SIGNATURE_H

#include <vector>
#include <string>

#include "../types/sequence_type.h"
#include "../util/hashmap.h"
#include "../util/rchandle.h"
#include "../values/qname_value.h"
 
namespace xqp {

/*______________________________________________________________________
|  
|	By convention arg_v[0] = return type
|	              arg_v[1] = first input argument type
|	              arg_v[2] = second input argument type
|	               ...     =  ...                         
|_______________________________________________________________________*/

class signature : public rcobject
{
public:
	rchandle<QName> fname_h;
	std::vector<sequence_type> arg_v;
	static hashmap<signature const*> sigmap;

public:
	signature(rchandle<QName> _fname_h) : fname_h(_fname_h) {}
	~signature() {}

public:
	void add_arg(sequence_type t) { arg_v.push_back(t); }
	uint32_t arg_count() const { return arg_v.size(); }
	sequence_type const& operator[](int i) const { return arg_v[i]; }
	sequence_type & operator[](int i) { return arg_v[i]; }

	sequence_type const& return_type() const { return arg_v[0]; }
	sequence_type & return_type() { return arg_v[0]; }

	rchandle<QName> get_fname() const { return fname_h; }
	void set_fname(rchandle<QName> qn_h) { fname_h = qn_h; }

};

} /* namespace xqp */
#endif  /* XQP_SIGNATURE_H */

