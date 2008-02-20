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


#include "common/shared_types.h"

namespace xqp {

class static_context;

class BuiltinFunctionLibrary {
    private:
        static void populateContext(static_context *sctx);
        friend class GlobalEnvironment;
};


} /* namespace xqp */
#endif /* XQP_LIBRARY_H */

