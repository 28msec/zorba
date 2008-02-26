#ifndef XQP_COMPILER_API_IMPL_H
#define XQP_COMPILER_API_IMPL_H

#include "compiler/api/compiler_api.h"

namespace xqp {

class XQueryCompilerSubsystemImpl : public XQueryCompilerSubsystem {
  public:
    ~XQueryCompilerSubsystemImpl() throw ();

    Rewriter *getDefaultOptimizingRewriter();

  private:
    std::auto_ptr<Rewriter> m_defaultOptimizer;

    friend class XQueryCompilerSubsystem;
    XQueryCompilerSubsystemImpl();
};

} /* namespace xqp */
#endif /* XQP_COMPILER_API_IMPL_H */
/* vim:set ts=2 sw=2: */
