/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: function_library.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_FUNCTION_LIBRARY_H
#define XQP_FUNCTION_LIBRARY_H

#include "../datamodel/sequence_type.h"

namespace xqp {

class funtab_entry
{
public:
	rchandle<QName> fname;
	const function_impl* impl;
	const typecheck_impl* checker;

	uint32_t minArgs;
	uint32_t maxArgs;
	sequence_type[] arg_types;
	sequence_type result_type;

	uint32_t character;

};


class function_library
{
protected:
	hashmap<funtab_entry> funtab;

public:
	function_library();
	~function_library();

public:
	void put(rchandle<funtab_entry>);
	rchandle<funtab_entry> get(std::string const&);

};


} /* namespace xqp */
#endif /* XQP_FUNCTION_LIBRARY_H */

