#ifndef XQP_SEQUENTIAL_REWRITER_H
#define XQP_SEQUENTIAL_REWRITER_H

#include <vector>
#include "common/shared_types.h"
#include "compiler/rewriter/framework/rewriter.h"

namespace xqp {

class SequentialRewriter : public Rewriter {
  public:
    void rewrite(RewriterContext& rCtx);

  protected:
    SequentialRewriter();
    ~SequentialRewriter() throw ();

    std::vector<Rewriter *> m_childRewriters;
};

}

#endif /* XQP_SEQUENTIAL_REWRITER_H */
/* vim:set ts=2 sw=2: */
