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

#include "../datamodel/types.h"
#include "../datamodel/qname.h"
#include "../util/rchandle.h"
 
namespace xqp {

struct signature : public rcobject
{
	QName fname;
	std::vector<item_type> arg_v;
	item_type ret_type;
	signature(QName const& q) : fname(q) {}
};


class function_impl : public rcobject
{
protected:
  rchandle<item_iterator> val; 

public:
	static string decode_type(type::typecode)
	static type::typecode function_impl::encode_type(string const& s)
  static std::string mangle(signature const& sig);
  static rchandle<signature> demangle(std::string const& sig);
};


} /* namespace xqp */
#endif  /* XQP_FUNCTION_IMPL_H */

