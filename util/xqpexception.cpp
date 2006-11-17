
#include "xqpexception.h"

#include <sstream>
#include <typeinfo>
#include <iostream>

using namespace std;
namespace xqp
{


// xqpexception implementations
// -------------------------
xqpexception::xqpexception()
: runtime_error(string())
{}

xqpexception::xqpexception(const xqpexception& e)
: runtime_error(e),
	loc(e.loc),
  msg(e.msg)
{}

xqpexception::xqpexception(
	const string& _loc)
:
	runtime_error("APPLICATION_EXCEPTION"),
	loc(_loc)
{}

xqpexception::xqpexception(
	const string& _loc,
	const string& _msg)
:
	runtime_error("APPLICATION_EXCEPTION"),
	loc(_loc),
	msg(_msg)
{}


xqpexception::xqpexception(
	const char*   _err,
	const string& _loc,
	const string  _msg)
:
	runtime_error(_err),
	loc(_loc),
	msg(_msg)
{
}

xqpexception::xqpexception(
	const char*   _err,
	const char*   _op,
	const string  _msg)
:
	runtime_error(_err),
	loc(_op),
	msg(_msg)
{
}


xqpexception::xqpexception(
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


xqpexception::~xqpexception() throw() { }


// bad_arg implementations
// ----------------------
bad_arg::bad_arg()
: xqpexception(string())
{}

bad_arg::bad_arg(const bad_arg& e)
: xqpexception(e.loc, e.msg)
{}

bad_arg::bad_arg(const string& loc)
: xqpexception(loc)
{}

bad_arg::bad_arg(const string& loc, const string& msg)
: xqpexception(loc,msg)
{}


bad_arg::~bad_arg() throw() { }


// null_pointer implementations
// ---------------------------
null_pointer::null_pointer()
: xqpexception(string())
{}

null_pointer::null_pointer(const null_pointer& e)
: xqpexception(e.loc, e.msg)
{}

null_pointer::null_pointer(const string& loc)
: xqpexception(loc)
{}

null_pointer::null_pointer(const string& loc, const string& msg)
: xqpexception(loc,msg)
{}


null_pointer::~null_pointer() throw() { }



// invariant implementations
// -------------------------
invariant::invariant()
: xqpexception(string())
{}

invariant::invariant(const invariant& e)
: xqpexception(e.loc, e.msg)
{}

invariant::invariant(const string& loc)
: xqpexception(loc)
{}

invariant::invariant(const string& loc, const string& msg)
: xqpexception(loc,msg)
{}


invariant::~invariant() throw() { }


} /* namespace xqp */


