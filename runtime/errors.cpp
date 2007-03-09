/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: errors.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "errors.h"
#include "xqp_exception.h"

using namespace std;
namespace xqp {
  
void errors::error(
	enum errcode,
	string const& what)
{
	throw xqp_exception(errcode, what);
}
  
} /* namespace xqp */

