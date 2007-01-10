
/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: trace_handler.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_TRACE_HANDLER_H
#define XQP_TRACE_HANDLER_H

#include <string>

namespace xqp {

class trace_handler
{
public:
  enum trace_level {
		debug,
		fine,
		finer,
		finest
	};

public:
	trace_handler() {}
	~trace_handler() {}

public:
	std::string describe(enum trace_level) const;

};

} /* namespace xqp */
#endif /* XQP_TRACE_HANDLER_H */

