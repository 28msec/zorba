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
#include "util/rchandle.h"
//#include "errors/errors.h"

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

class ZorbaError;
typedef rchandle<ZorbaError>		ZorbaError_t;

class ZorbaException //: public std::runtime_error 
{ 
public:
	ZorbaError_t		error_descr;

public: 
	virtual ~ZorbaException() {}

public:
  long getCode() const;
	ZorbaError_t getError();
};


std::ostream& operator<<(std::ostream& os, ZorbaException &x);

} /* namespace xqp */
#endif /* XQP_XQP_EXCEPTION_H */

