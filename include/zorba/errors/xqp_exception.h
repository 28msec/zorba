/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xqp_exception.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_XQP_EXCEPTION_H
#define XQP_XQP_EXCEPTION_H

#include <stdexcept>
#include <string>
#include "errors/errors.h"

namespace xqp
{
/*
#define XQP_EXCEPTION_MACRO(X) \
		ostringstream os_loc_, os_err_; \
		os_loc_ << __FILE__ << ":" << __LINE__ << "::" << __FUNCTION__; \
		os_err_ << X; \
		throw xqp_exception(os_loc_.str(),os_err_.str());

#define BAD_ARG_MACRO(X) \
		ostringstream os_loc_, os_err_; \
		os_loc_ << __FILE__ << ":" << __LINE__ << "::" << __FUNCTION__; \
		os_err_ << X; \
		throw bad_arg(os_loc_.str(),os_err_.str());

#define NULL_POINTER_MACRO(X) \
		ostringstream os_loc_, os_err_; \
		os_loc_ << __FILE__ << ":" << __LINE__ << "::" << __FUNCTION__; \
		os_err_ << X; \
		throw null_pointer(os_loc_.str(),os_err_.str());

#define BAD_DYNAMIC_CAST_MACRO(X) \
		ostringstream os_loc_, os_err_; \
		os_loc_ << __FILE__ << ":" << __LINE__ << "::" << __FUNCTION__; \
		os_err_ << X; \
		throw bad_dynamic_cast(os_loc_.str(),os_err_.str());
*/

class xqp_exception //: public std::runtime_error 
{ 
public:
	ZorbaError		error_descr;

public: 
	xqp_exception(ZorbaError::ErrorCodes ecode);
	xqp_exception(ZorbaError &err);

  ~xqp_exception();

public:
  long getCode() const;
	ZorbaError	getError();
};


/*daniel
class bad_arg : public xqp_exception
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


class normalize_error : public xqp_exception
{
public:
	normalize_error();
  normalize_error(const normalize_error&);
	normalize_error(const std::string& loc);
	normalize_error(const std::string& loc, const std::string& msg);
	~normalize_error() throw();

public:
	std::string get_msg() const { return "normalize_error: " + msg; }
};


class null_pointer : public xqp_exception
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


class bad_dynamic_cast : public xqp_exception
{
public:
	bad_dynamic_cast();
  bad_dynamic_cast(const bad_dynamic_cast&);
	bad_dynamic_cast(const std::string& loc);
	bad_dynamic_cast(const std::string& loc, const std::string& msg);
	~bad_dynamic_cast() throw();

public:
	std::string get_msg() const { return "bad_dynamic_cast: " + msg; }
};


class invariant : public xqp_exception
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

*/

std::ostream& operator<<(std::ostream& os, xqp_exception &x);

} /* namespace xqp */
#endif /* XQP_XQP_EXCEPTION_H */

