/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xqpexception.h,v 1.2 2006/11/01 17:56:20 Paul Pedersen Exp $
 *
 *
 */

#ifndef XQP_XQPEXCEPTION_H
#define XQP_XQPEXCEPTION_H

#include <stdexcept>
#include <string>

namespace xqp
{

class xqpexception : public std::runtime_error 
{ 
public:
  std::string loc;
  std::string msg;

public: 
  xqpexception();
  xqpexception(const xqpexception&);
  xqpexception(
		const std::string& loc);
  xqpexception(
		const std::string& loc,
		const std::string& msg);
	xqpexception(
		const char* err_code,
		const std::string& loc,
		const std::string msg);
	xqpexception(
		const char* err_code,
		const char* op_name,
		const std::string msg);
	xqpexception(
		const char* err_code,
		const char* op_name,
		const std::string& loc,
		const std::string msg);
  ~xqpexception() throw();

public:
	std::string get_loc() const { return loc; }
	std::string get_msg() const { return msg; }
};


class bad_arg : public xqpexception
{
public:
	bad_arg();
  bad_arg(const bad_arg&);
	bad_arg(const std::string& loc);
	bad_arg(const std::string& loc, const std::string& msg);
	~bad_arg() throw();

public:
	std::string get_msg() const { return "bad_arg: " + msg; }
};


class null_pointer : public xqpexception
{
public:
	null_pointer();
  null_pointer(const null_pointer&);
	null_pointer(const std::string& loc);
	null_pointer(const std::string& loc, const std::string& msg);
	~null_pointer() throw();

public:
	std::string get_msg() const { return "null_pointer: " + msg; }
};


class invariant : public xqpexception
{
public:
	invariant();
  invariant(const invariant&);
	invariant(const std::string& loc);
	invariant(const std::string& loc, const std::string& msg);
	~invariant() throw();

public:
	std::string get_msg() const { return "invariant: " + msg; }
};


} /* namespace xqp */
#endif /* XQP_XQPEXCEPTION_H */

