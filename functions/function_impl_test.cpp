/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: function_impl_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author:  Paul Pedersen
 *
 */

#include "function_impl.h"

#include "../context/context.h"
#include "../values/qname_value.h"
#include "../util/rchandle.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	context ctx;
  signature sig(new QName(QName::qn_func,"xqp","testfun"));
  sig.add_arg(sequence_type::SINGLE_ATOMIC);	// arg[0] = return type
  sig.add_arg(sequence_type::SINGLE_ATOMIC);
  sig.add_arg(sequence_type::SINGLE_ATOMIC);
  sig.add_arg(sequence_type::SINGLE_ATOMIC);
  string s = function_impl::mangle(&ctx, sig);
  cout << s << endl;
  
  signature const* sig_p = function_impl::demangle(&ctx, s);
  cout << "signature[\n  fname = ";
	sig_p->get_fname()->put(cout,&ctx) << endl;
  cout << "  ret_type = " << (*sig_p)[0].describe() << "\n]\n";
  for (uint32_t k=1; k<sig_p->arg_count(); ++k) {
    cout << "  arg["<<k<<"] = " << (*sig_p)[k].describe() << endl;
  }
	cout << "]\n";
  return 0;
}

/*
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
*/

/*
class function_impl : public rcobject
{
public:
	rchandle<signature> sig_h;
	function_impl(rchandle<signature> _sig_h) : sig_h(_sig_h) {}
	~function_impl() {}
  static std::string mangle( context *, signature const& sig);
  static signature const* demangle( context *, std::string const& sigstr);
*/

