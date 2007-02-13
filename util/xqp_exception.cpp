/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xqp_exception.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "xqp_exception.h"

#include <sstream>
#include <typeinfo>
#include <iostream>

using namespace std;
namespace xqp
{


// xqp_exception implementations
// -------------------------
xqp_exception::xqp_exception()
: runtime_error(string())
{}

xqp_exception::xqp_exception(const xqp_exception& e)
: runtime_error(e),
	loc(e.loc),
  msg(e.msg)
{}

xqp_exception::xqp_exception(
	const string& _loc)
:
	runtime_error("APPLICATION_EXCEPTION"),
	loc(_loc)
{}

xqp_exception::xqp_exception(
	const string& _loc,
	const string& _msg)
:
	runtime_error("APPLICATION_EXCEPTION"),
	loc(_loc),
	msg(_msg)
{}


xqp_exception::xqp_exception(
	const char*   _err,
	const string& _loc,
	const string  _msg)
:
	runtime_error(_err),
	loc(_loc),
	msg(_msg)
{
}

xqp_exception::xqp_exception(
	const char*   _err,
	const char*   _op,
	const string  _msg)
:
	runtime_error(_err),
	loc(_op),
	msg(_msg)
{
}


xqp_exception::xqp_exception(
	const char*   _err,
	const char*   _op,
	const string& _loc,
	const string  _msg)
:
	runtime_error(_err),
	loc(_op+':'+_loc),
	msg(_msg)
{
}


xqp_exception::~xqp_exception() throw() { }


// bad_arg implementations
// ----------------------
bad_arg::bad_arg()
: xqp_exception(string())
{
}

bad_arg::bad_arg(const bad_arg& e)
: xqp_exception(e.loc, e.msg)
{
}

bad_arg::bad_arg(const string& loc)
: xqp_exception(loc)
{
}

bad_arg::bad_arg(const string& loc, const string& msg)
: xqp_exception(loc,msg)
{
}

bad_arg::~bad_arg()
throw()
{
}


// null_pointer implementations
// ----------------------------
null_pointer::null_pointer()
: xqp_exception(string())
{
}

null_pointer::null_pointer(const null_pointer& e)
: xqp_exception(e.loc, e.msg)
{
}

null_pointer::null_pointer(const string& loc)
: xqp_exception(loc)
{
}

null_pointer::null_pointer(const string& loc, const string& msg)
: xqp_exception(loc,msg)
{
}


null_pointer::~null_pointer() throw() { }



// bad_dynamic_cast implementations
// ----------------------------
bad_dynamic_cast::bad_dynamic_cast()
: xqp_exception(string())
{
}

bad_dynamic_cast::bad_dynamic_cast(const bad_dynamic_cast& e)
: xqp_exception(e.loc, e.msg)
{
}

bad_dynamic_cast::bad_dynamic_cast(const string& loc)
: xqp_exception(loc)
{
}

bad_dynamic_cast::bad_dynamic_cast(const string& loc, const string& msg)
: xqp_exception(loc,msg)
{
}


bad_dynamic_cast::~bad_dynamic_cast() throw() { }



// invariant implementations
// -------------------------
invariant::invariant()
: xqp_exception(string())
{
}

invariant::invariant(const invariant& e)
: xqp_exception(e.loc, e.msg)
{
}

invariant::invariant(const string& loc)
: xqp_exception(loc)
{
}

invariant::invariant(const string& loc, const string& msg)
: xqp_exception(loc,msg)
{
}


invariant::~invariant()
throw()
{
}


} /* namespace xqp */


