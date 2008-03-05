#ifndef ZORBA_DEFAULT_OPTIMIZER_H
#define ZORBA_DEFAULT_OPTIMIZER_H

#include "common/shared_types.h"
#include "compiler/rewriter/framework/sequential_rewriter.h"

namespace zorba {

class DefaultOptimizer : public SequentialRewriter {
  public:
    DefaultOptimizer();
    ~DefaultOptimizer() throw ();
};

}

#endif /* ZORBA_DEFAULT_OPTIMIZER_H */
/* vim:set ts=2 sw=2: */
