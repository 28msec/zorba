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

#include "../datamodel/sequence_type.h"
#include "../datamodel/qname.h"
#include "../runtime/item_iterator.h"
#include "../util/hashmap.h"
#include "../util/rchandle.h"
 
namespace xqp {

class signature : public rcobject
{
public:
	QName fname;
	std::vector<sequence_type> arg_v;
	sequence_type ret_type;
	static hashmap<signature const*> sigmap;

public:
	signature(QName const& _fname) : fname(_fname) {}
	~signature() {}

};


class function_impl : public rcobject
{
protected:
  rchandle<item_iterator> val; 

public:
  static std::string mangle(signature const& sig);
  static signature const* demangle(std::string const& sig);

};


} /* namespace xqp */
#endif  /* XQP_FUNCTION_IMPL_H */

