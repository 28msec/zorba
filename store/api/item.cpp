/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *
 */

#include "item.h"

#include "../../errors/errors.h"
#include "../../errors/Error.h"
#include "util/hashfun.h"

namespace xqp
{

	/* begin class Item */
	void Item::showError() const
	{
		ZorbaErrorAlerts::error_alert (
		    error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
		    error_messages::SYSTEM_ERROR,
		    NULL
		);
	}

	xqp_string Item::show() const {
		return  std::string(typeid(*this).name()) + ": 'show' not implemented!";
	}
	
	qnamekey_t Item::createQNameKey(xqp_string _namespace, xqp_string prefix, xqp_string localName) {
		return hashfun::h64(prefix,hashfun::h64(localName,hashfun::h64(_namespace)));
	}
	/* end class Item */
}
