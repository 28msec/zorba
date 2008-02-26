#ifndef XQP_DEFAULT_OPTIMIZER_H
#define XQP_DEFAULT_OPTIMIZER_H

#include "common/shared_types.h"
#include "compiler/rewriter/framework/sequential_rewriter.h"

namespace xqp {

class DefaultOptimizer : public SequentialRewriter {
  public:
    DefaultOptimizer();
    ~DefaultOptimizer() throw ();
};

}

#endif /* XQP_DEFAULT_OPTIMIZER_H */
/* vim:set ts=2 sw=2: */
