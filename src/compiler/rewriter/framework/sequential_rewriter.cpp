#include "compiler/rewriter/framework/sequential_rewriter.h"

namespace zorba {

SequentialRewriter::SequentialRewriter()
{
}

SequentialRewriter::~SequentialRewriter() throw ()
{
}

void SequentialRewriter::rewrite(RewriterContext& rCtx)
{
  rewriters_t::const_iterator end = m_childRewriters.end();
  for(rewriters_t::const_iterator i = m_childRewriters.begin(); i != end; ++i) {
    (*i)->rewrite(rCtx);
  }
}

}
/* vim:set ts=2 sw=2: */
