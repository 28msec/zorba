/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: trace_handler.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "trace_handler.h"
#include <string>

using namespace std;
namespace xqp {

string trace_handler::describe(enum trace_level t) const
{
	switch (t) {
	case debug: return "debug";
	case fine: return "fine";
	case finer: return "finer";
	case finest: return "finest";
	}
	return "??";
}


} /* namespace xqp */

