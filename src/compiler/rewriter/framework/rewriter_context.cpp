#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/expression/expr.h"
#include "compiler/api/compilercb.h"

namespace zorba {

RewriterContext::RewriterContext(CompilerCB* aCompilerCB, expr_t root)
  : compilerCB(aCompilerCB),
    m_sctx(aCompilerCB->m_sctx),
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
