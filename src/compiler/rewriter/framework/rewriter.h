#ifndef XQP_REWRITER_H
#define XQP_REWRITER_H

#include "common/shared_types.h"

namespace xqp {

class Rewriter {
  public:
    virtual ~Rewriter() { }

    virtual void rewrite(RewriterContext& rCtx) = 0;
};

}

#endif /* XQP_REWRITER_H */
/* vim:set ts=2 sw=2: */
