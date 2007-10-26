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

inline void ZorbaAssert(bool assertion, const char *where, const char *what)
{
	if (!assertion) {
    ZorbaErrorAlerts::error_alert
      (error_messages::XQP0005_SYSTEM_ASSERT_FAILED,
       error_messages::SYSTEM_ERROR,
       NULL, false,
       what, where);
	}
}

#define __Assert_aux3( line ) #line
#define __Assert_aux2( line ) __Assert_aux3( line )
#define __Assert_aux1( cond, line ) ZorbaAssert (cond, __FILE__ ":" __Assert_aux2 (line), #cond)
#define Assert( cond ) __Assert_aux1 (cond, __LINE__)

}	/* namespace xqp */
#endif	/* XQP_ASSERT_H */

