/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "compiler/rewriter/framework/rule_driver.h"
#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/rewriters/common_rewriter.h"
#include "compiler/rewriter/rewriters/default_optimizer.h"

namespace zorba {

class FoldRules : public RuleMajorDriver {
  public:
    FoldRules() {
      ADD_RULE(MarkExpensiveOps);
      ADD_RULE(MarkUnfoldableExprs);
      ADD_RULE(MarkImpureExprs);
      // Most rules try to update the freevars annotations, but for now let's stay on the safe side
      ADD_RULE(MarkFreeVars);
      ADD_RULE(FoldConst (false));
      ADD_RULE(PartialEval);      
      ADD_RULE(RefactorPredFLWOR);
      ADD_RULE(EliminateUnusedLetVars);
    }
};

DefaultOptimizer::DefaultOptimizer()
{
  ADD_SINGLETON_DRIVER(InferVarTypes);
  ADD_SINGLETON_DRIVER(EliminateTypeEnforcingOperations);

  ADD_SINGLETON_DRIVER(EliminateExtraneousPathSteps);

  ADD_DRIVER(FoldRules);

  ADD_SINGLETON_DRIVER(ReplaceExprWithConstantOneWhenPossible);

  ADD_SINGLETON_DRIVER(HoistExprsOutOfLoops);

  ADD_SINGLETON_DRIVER(MarkFreeVars);
  ADD_SINGLETON_DRIVER(EliminateUnusedLetVars);

  ADD_SINGLETON_DRIVER(MarkConsumerNodeProps);
  ADD_SINGLETON_DRIVER(MarkProducerNodeProps);
  ADD_SINGLETON_DRIVER(EliminateNodeOps);

  // For UDFs, which need this annotation in udf::requires_dyn_ctx()
  // TODO: only do this for UDFs
  ADD_SINGLETON_DRIVER(MarkUnfoldableExprs);
}

DefaultOptimizer::~DefaultOptimizer() throw ()
{
}

}
