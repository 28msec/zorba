
/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: error_handler.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_ERROR_HANDLER_H
#define XQP_ERROR_HANDLER_H

#include <string>

namespace xqp {

class error_handler
{
public:
  enum error_level {
		info,
		debug,
    warning,
    error,
    critical,
    alert,
    emergency
  };

public:
	error_handler() {}
	~error_handler() {}

public:
	std::string describe(enum error_level) const;

};

} /* namespace xqp */
#endif /* XQP_ERROR_HANDLER_H */

