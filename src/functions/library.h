/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
*
 *  $Id: function_library.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_LIBRARY_H
#define XQP_LIBRARY_H

#include <string>

#include "context/common.h"
#include "store/api/item_factory.h"
#include "util/fx/fxhashmap.h"

namespace xqp {

class function;
class zorba;

// template<typename FuncIter>
// class LibraryFunction {
// 	PlanIter_t operator() {
// 		
// 	}
// };

class library : public rcobject
{
public:
	library( );
	~library();
	static bool static_init;
	void init(ItemFactory*);
};

} /* namespace xqp */
#endif /* XQP_LIBRARY_H */

