/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: Assert.h,v 1.2 2006/10/13 06:53:29 Paul Pedersen Exp $
 *
 *  Copyright 2005-2006 FLWOR Foundation.
 *
 */


#ifndef XQP_ASSERT_H
#define XQP_ASSERT_H

#include <string>
#include "errors/Error.h"

namespace xqp {

/*_________________________________________________
|                                                  |
|  See: Stroustrup, Third Ed., Section 24.3.7.2.   |
|__________________________________________________*/

//template<class X, class A>
inline void Assert(bool assertion)
{
	if (!assertion) 
	{
		//daniel throw X();
		ZorbaErrorAlerts::error_alert(error_messages::XQP0005_SYSTEM_ASSERT_FAILED,
														error_messages::SYSTEM_ERROR);
	}
}

//template<class X, class A>
inline void Assert(bool assertion, const std::string& location)
{
	if (!assertion) 
	{
	//daniel	throw X(location);
		ZorbaErrorAlerts::error_alert(error_messages::XQP0005_SYSTEM_ASSERT_FAILED,
														error_messages::SYSTEM_ERROR,
														NULL, false,
														location);
	}
}


}	/* namespace xqp */
#endif	/* XQP_ASSERT_H */

