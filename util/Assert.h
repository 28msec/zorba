/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: Assert.h,v 1.2 2006/10/13 06:53:29 Paul Pedersen Exp $
 *
 *  Copyright 2005-2006 FLWOR Foundation.
 *
 */


#ifndef XQP_ASSERT_H
#define XQP_ASSERT_H

#include <string>

namespace xqp {

/*_________________________________________________
|                                                  |
|  See: Stroustrup, Third Ed., Section 24.3.7.2.   |
|__________________________________________________*/

template<class X, class A>
inline void Assert(A assertion)
{
	if (!assertion) throw X();
}

template<class X, class A>
inline void Assert(A assertion, const std::string& location)
{
	if (!assertion) throw X(location);
}


}	/* namespace xqp */
#endif	/* XQP_ASSERT_H */
