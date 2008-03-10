#include "compiler/rewriter/framework/rule_driver.h"
#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/rewriters/default_optimizer.h"

namespace zorba {

class TestRuleDriver : public RuleMajorDriver {
  public:
    TestRuleDriver()
    {
      m_rules.push_back(rule_ptr_t(new EchoNodeRule()));
    }
};

class NodeidMarkingRuleDriver : public RuleMajorDriver {
  public:
    NodeidMarkingRuleDriver()
    {
      m_rules.push_back(rule_ptr_t(new MarkNodesWithNodeIdPropertiesRule()));
    }
};

class NodeidRuleDriver : public RuleMajorDriver {
  public:
    NodeidRuleDriver()
    {
      m_rules.push_back(rule_ptr_t(new EliminateDocOrderSortRule()));
    }
};

class EliminateTypeEnforcingOperationsRuleDriver : public RuleMajorDriver {
  public:
    EliminateTypeEnforcingOperationsRuleDriver()
    {
      m_rules.push_back(rule_ptr_t(new EliminateTypeEnforcingOperations()));
    }
};

class EliminateUnusedLetVarsRuleDriver : public RuleMajorDriver {
  public:
    EliminateUnusedLetVarsRuleDriver()
    {
      m_rules.push_back(rule_ptr_t(new EliminateUnusedLetVars()));
    }
};

DefaultOptimizer::DefaultOptimizer()
{
  //m_childRewriters.push_back(rewriter_ptr_t(new TestRuleDriver()));
  m_childRewriters.push_back(rewriter_ptr_t(new NodeidMarkingRuleDriver()));
  m_childRewriters.push_back(rewriter_ptr_t(new NodeidRuleDriver()));
  m_childRewriters.push_back(rewriter_ptr_t(new EliminateTypeEnforcingOperationsRuleDriver()));
  m_childRewriters.push_back(rewriter_ptr_t(new EliminateUnusedLetVarsRuleDriver()));
}

DefaultOptimizer::~DefaultOptimizer() throw ()
{
}

}
