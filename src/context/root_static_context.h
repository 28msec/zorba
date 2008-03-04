#ifndef XQP_ROOT_STATIC_CONTEXT_H
#define XQP_ROOT_STATIC_CONTEXT_H

#include "context/static_context.h"

namespace zorba {

class root_static_context : public static_context {
    private:
        root_static_context();
        virtual ~root_static_context();

        friend class GlobalEnvironment;
};

}

#endif /* XQP_ROOT_STATIC_CONTEXT_H */
