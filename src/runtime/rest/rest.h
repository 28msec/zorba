#ifndef ZORBA_RUNTIME_REST_H
#define ZORBA_RUNTIME_REST_H

#include "common/shared_types.h"
#include "runtime/base/narybase.h"

typedef void CURL;

namespace zorba {

class ZorbaRestGetIteratorState : public PlanIteratorState
{
  public:
    ZorbaRestGetIteratorState();
    ~ZorbaRestGetIteratorState();

    void init(PlanState&);
    void reset(PlanState&);

    CURL* theCurlHandle;
    char*       theCurlErrorBuffer;
};

NARY_ITER_STATE(ZorbaRestGetIterator, ZorbaRestGetIteratorState);

} /* namespace zorba */

#endif
