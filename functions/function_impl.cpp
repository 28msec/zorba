/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: mangle_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "function_impl.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace xqp {

string function_impl::mangle(signature const& sig)
{
  ostringstream oss;
  sig.fname.put(oss) << '(';
  vector<sequence_type>::const_iterator it = sig.arg_v.begin();
  for (; it!=sig.arg_v.end(); ++it) {
    if (it!=sig.arg_v.begin()) oss << ',';
    oss << (*it).describe();
  } oss << ')' << sig.ret_type.describe();
	string s = oss.str();
	signature::sigmap.put(s, &sig);
  return s;
}


signature const* function_impl::demangle(string const& sig)
{
	signature const* sig_p;
	if (!signature::sigmap.get(sig, sig_p)) return NULL;
	return sig_p;
}

} /* namespace xqp */

