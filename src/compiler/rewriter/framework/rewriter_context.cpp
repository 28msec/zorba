#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/expression/expr.h"

namespace xqp {

RewriterContext::RewriterContext(static_context *sctx, expr_t root)
  : m_sctx(sctx),
  m_root(root) { }

RewriterContext::~RewriterContext() { }

expr_t RewriterContext::getRoot()
{
  return m_root;
}

void RewriterContext::setRoot(expr_t root)
{
  m_root = root;
}

}
/* vim:set ts=2 sw=2: */
