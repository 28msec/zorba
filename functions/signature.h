/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: signature.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */
 
#ifndef XQP_SIGNATURE_H
#define XQP_SIGNATURE_H

#include <string>
#include <vector>

#include "context/common.h"
#include "types/sequence_type.h"
#include "util/fxhashmap.h"

namespace xqp {

class context;


/*******************************************************************************
  
  By convention, argv[0]    = return type
	               argv[1]    = first input argument type
                 argv[2]    = second input argument type
	                ...       =  ...  

********************************************************************************/
class signature : public rcobject
{
public:
	const Item* qname_p;
	std::vector<sequence_type_t> argv;
	static fxhashmap<signature const*> sigmap;	// map: fname -> signture

public:
	signature() {}
	signature(Item const*,
						sequence_type_t return_type);
	signature(Item const*,
						sequence_type_t arg1,
						sequence_type_t return_type);
	signature(Item const*,
						sequence_type_t arg1,
						sequence_type_t arg2,
						sequence_type_t return_type);
	signature(Item const*,
						sequence_type_t arg1,
						sequence_type_t arg2,
						sequence_type_t arg3,
						sequence_type_t return_type);
	signature(Item const*,
						sequence_type_t arg1,
						sequence_type_t arg2,
						sequence_type_t arg3,
						sequence_type_t arg4,
						sequence_type_t return_type);
	signature(Item const*,
						const std::vector<sequence_type_t>& argv);
	~signature();

public:
	Item const* get_name() const                   { return qname_p; }
	void set_name(const Item* name)                { qname_p = name; }
	void add_arg(sequence_type_t t)                { argv.push_back(t); }
	uint32_t arg_count() const                     { return argv.size() - 1; }

	sequence_type_t const& operator[](int i) const { return argv[i]; }
	sequence_type_t & operator[](int i)            { return argv[i]; }
	sequence_type_t const& return_type() const     { return argv[0]; }
	sequence_type_t & return_type()                { return argv[0]; }

	void set_return_type(sequence_type_t t);
};

} /* namespace xqp */
#endif  /* XQP_SIGNATURE_H */

