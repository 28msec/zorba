#include "compiler/api/compiler_api_impl.h"
#include "compiler/rewriter/rewriters/default_optimizer.h"

namespace zorba {

XQueryCompilerSubsystemImpl::XQueryCompilerSubsystemImpl()
  : m_defaultOptimizer(new DefaultOptimizer())
{
}

XQueryCompilerSubsystemImpl::~XQueryCompilerSubsystemImpl() throw ()
{
}

Rewriter *XQueryCompilerSubsystemImpl::getDefaultOptimizingRewriter()
{
  return m_defaultOptimizer.get();
}

}
/* vim:set ts=2 sw=2: */
