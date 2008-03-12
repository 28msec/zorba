#include "compiler/rewriter/framework/rule_driver.h"
#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/rewriters/default_optimizer.h"

namespace zorba {

#define ADD_SINGLETON_DRIVER(rule) m_childRewriters.push_back(rewriter_ptr_t(new SingletonRuleMajorDriver<rule>()))

DefaultOptimizer::DefaultOptimizer()
{
  ADD_SINGLETON_DRIVER(MarkNodesWithNodeIdProperties);
  ADD_SINGLETON_DRIVER(EliminateDocOrderSort);
  ADD_SINGLETON_DRIVER(EliminateTypeEnforcingOperations);
  ADD_SINGLETON_DRIVER(EliminateUnusedLetVars);
  ADD_SINGLETON_DRIVER(EliminateExtraneousPathSteps);
}

DefaultOptimizer::~DefaultOptimizer() throw ()
{
}

}
