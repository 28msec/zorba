/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: error_handler.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "error_handler.h"
#include <string>

using namespace std;
namespace xqp {

string error_handler::describe(enum error_level e) const
{
	switch (e) {
	case info: return "info";
	case debug: return "debug";
	case warning: return "warning";
	case error: return "error";
	case critical: return "critical";
	case alert: return "alert";
	case emergency: return "emergency";
	}
}


} /* namespace xqp */

