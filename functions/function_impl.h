/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: function_impl.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */
 
#ifndef XQP_FUNCTION_IMPL_H
#define XQP_FUNCTION_IMPL_H

#include "signature.h"
#include "../context/context.h"
#include "../util/rchandle.h"

#include <string>
 
namespace xqp {

//XXX this type is clearly incomplete,
//    since it does not contain any method
//		to return an actual function pointer.

class function_impl : public rcobject
{
public:
	rchandle<signature> sig_h;

public:
	function_impl(rchandle<signature> _sig_h) : sig_h(_sig_h) {}
	~function_impl() {}

public:
  static std::string mangle(
		context *,
		signature const& sig);

  static signature const* demangle(
		context *,
		std::string const& sigstr);

};


} /* namespace xqp */
#endif  /* XQP_FUNCTION_IMPL_H */

