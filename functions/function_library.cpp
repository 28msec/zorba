/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: function_library.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include  "function_library.h"
#include  "../util/rchandle.h"

#include <string>

using namespace std;
namespace xqp {

function_library::function_library()
{
}

function_library::~function_library()
{
}

void function_library::put(
	const char* fname_p,
	const function_impl* impl_p,
	uint32_t minArgs,
	uint32_t maxArgs,
	sequence_type[] arg_types,
	sequence_type result_type,
	uint32_t character)
{
	funtab_entry e(fname_p,impl_p,min_args,max_args,arg_types,result_type,character);
	funtab.put(*fname_p,e);
}

void function_library::put(
	rchandle<funtab_entry> e)
{
	funtab.put(e->fname,e);
}

rchandle<funtab_entry> function_library::get(
	std::string const& fname)
{
	rchandle
	if (
}



} /* namespace xqp */



