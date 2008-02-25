/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xqp_exception.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */
#include <sstream>
#include <typeinfo>
#include <iostream>

#include <zorba/xqp_exception.h>

#include "errors/error_factory.h"
#include "system/zorba.h"
#include "system/zorba_engine.h"
#include "errors/error_manager.h"


using namespace std;
namespace xqp
{


// xqp_exception implementations
// -------------------------
xqp_exception::xqp_exception(ZorbaError::ErrorCodes ecode)
{
	error_descr = new ZorbaError;
	error_descr->theCode = ecode;
}

xqp_exception::xqp_exception(ZorbaError_t err)
{
	error_descr = err;
}

xqp_exception::~xqp_exception()
{
}

long ZorbaException::getCode() const 
{ 
	return error_descr->theCode; 
}
ZorbaError_t	ZorbaException::getError()
{
	return error_descr;
}

void	xqp_exception::setLocation(const yy::location* ploc)
{
	if(error_descr == NULL)
		return;
	if(error_descr->theLocation.location_is_set)//already set
		return;
	
	if(ploc)
	{
		if(ploc->begin.filename)
			error_descr->theLocation.filename = *ploc->begin.filename;
		error_descr->theLocation.line = ploc->begin.line;
		error_descr->theLocation.column = ploc->begin.column;
		error_descr->theLocation.location_is_set = true;
	}
	
	Zorba	*z = ZORBA_FOR_CURRENT_THREAD();
	if(!z)
		return;
	int		retval;
	z->getErrorManager()->sendAlertByCallback(z, &*error_descr, false, &retval);
}


std::ostream& operator<<(std::ostream& os, ZorbaException &x)
{
	return (os << *x.error_descr);
}


} /* namespace xqp */


