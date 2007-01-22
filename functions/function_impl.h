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

#include <vector>
#include <string>

#include "signature.h"
#include "../context/context.h"
#include "../types/sequence_type.h"
#include "../values/qname_value.h"
#include "../util/hashmap.h"
 
namespace xqp {

//XXX this type is clearly incomplete,
//    since it does not contain any method
//		to return an actual function pointer.

class function_impl : public rcobject
{
public:
	signature sig;

public:
	function_impl(signature const& _sig) : sig(_sig) {}
	~function_impl() {}

public:
  static std::string mangle(context const&,signature const& sig);
  static signature const* demangle(context const&,std::string const& sig);

};


} /* namespace xqp */
#endif  /* XQP_FUNCTION_IMPL_H */

