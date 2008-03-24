#ifndef ZORBA_ROOT_STATIC_CONTEXT_H
#define ZORBA_ROOT_STATIC_CONTEXT_H

#include "context/static_context.h"

namespace zorba {

class root_static_context : public static_context {
    private:
        root_static_context();
        void init();
        virtual ~root_static_context();

        friend class GlobalEnvironment;
};

}

#endif /* ZORBA_ROOT_STATIC_CONTEXT_H */
