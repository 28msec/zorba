#ifndef ZORBA_REWRITER_CONTEXT_H
#define ZORBA_REWRITER_CONTEXT_H

#include "common/shared_types.h"

namespace zorba {

class RewriterContext {
  public:
    RewriterContext(CompilerCB*, expr_t root);
    ~RewriterContext();

    static_context *getStaticContext() { return m_sctx; }

    expr_t getRoot();
    void setRoot(expr_t root);

    CompilerCB* getCompilerCB() { return compilerCB; }

  private:
    CompilerCB     *compilerCB;
    static_context *m_sctx;
    expr_t m_root;
};

}

#endif /* ZORBA_REWRITER_CONTEXT_H */
/* vim:set ts=2 sw=2: */
