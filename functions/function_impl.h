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

#include "../types/builtin_types.h"
#include "../types/qname.h"
#include "../util/rchandle.h"
 
namespace xqp {

struct signature : public rcobject
{
	QName fname;
	std::vector<static_type_t> arg_v;
	static_type_t ret_type;
	signature(QName const& q) : fname(q) {}
};


class function_impl : public rcobject
{
public:
  static std::string decode_type(static_type_t t);
  static static_type_t encode_type(std::string const& s);
  static std::string mangle(signature const& sig);
  static rchandle<signature> demangle(std::string const& sig);
};


} /* namespace xqp */
#endif  /* XQP_FUNCTION_IMPL_H */
