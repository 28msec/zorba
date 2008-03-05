#ifndef ZORBA_REWRITER_H
#define ZORBA_REWRITER_H

#include "common/shared_types.h"

namespace zorba {

class Rewriter {
  public:
    virtual ~Rewriter() { }

    virtual void rewrite(RewriterContext& rCtx) = 0;
};

}

#endif /* ZORBA_REWRITER_H */
/* vim:set ts=2 sw=2: */
