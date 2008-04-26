#ifndef ZORBA_LIBRARY_H
#define ZORBA_LIBRARY_H


#include "common/shared_types.h"

namespace zorba {

class static_context;

class BuiltinFunctionLibrary {
    private:
        static void populateContext(static_context *sctx);
        friend class GlobalEnvironment;
};


} /* namespace zorba */
#endif /* ZORBA_LIBRARY_H */

