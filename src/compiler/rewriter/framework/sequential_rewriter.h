#ifndef XQP_SEQUENTIAL_REWRITER_H
#define XQP_SEQUENTIAL_REWRITER_H

#include <vector>
#include <boost/shared_ptr.hpp>
#include "common/shared_types.h"
#include "compiler/rewriter/framework/rewriter.h"

namespace xqp {

class SequentialRewriter : public Rewriter {
  public:
    void rewrite(RewriterContext& rCtx);

  protected:
    typedef boost::shared_ptr<Rewriter> rewriter_ptr_t;
    typedef std::vector<rewriter_ptr_t> rewriters_t;
    SequentialRewriter();
    ~SequentialRewriter() throw ();

    rewriters_t m_childRewriters;
};

}

#endif /* XQP_SEQUENTIAL_REWRITER_H */
/* vim:set ts=2 sw=2: */
