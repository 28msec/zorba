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
#include "compiler/rewriter/tools/expr_tools.h"

#include "system/properties.h"

namespace zorba 
{

class FoldRules : public RuleMajorDriver
{
public:
  FoldRules()
  {
    //ADD_RULE(MarkExpensiveOps);
    // Most rules try to update the freevars annotations, but for now let's stay on the safe side
    ADD_RULE(MarkExprs);
    ADD_RULE(MarkFreeVars);
    ADD_RULE(FoldConst(false));
    ADD_RULE(PartialEval);
    ADD_RULE(RefactorPredFLWOR);
    ADD_RULE(EliminateUnusedLetVars);
    ADD_RULE(MergeFLWOR);
  }
};


DefaultOptimizer::DefaultOptimizer()
{
}


DefaultOptimizer::~DefaultOptimizer() throw ()
{
}


bool DefaultOptimizer::rewrite(RewriterContext& rCtx)
{
  bool modified = false;

  SingletonRuleMajorDriver<EliminateTypeEnforcingOperations> driverTypeRules;
  SingletonRuleMajorDriver<EliminateExtraneousPathSteps> driverPathSimplify;
  SingletonRuleMajorDriver<ReplaceExprWithConstantOneWhenPossible> driverExprSimplify;
  SingletonRuleMajorDriver<EliminateUnusedLetVars> driverEliminateVars;
  SingletonRuleMajorDriver<MarkProducerNodeProps> driverMarkProducerNodeProps;
  SingletonRuleMajorDriver<MarkConsumerNodeProps> driverMarkConsumerNodeProps;
  SingletonRuleMajorDriver<EliminateNodeOps> driverEliminateNodeOps;
  SingletonRuleMajorDriver<SpecializeOperations> driverSpecializeOperations;
  SingletonRuleMajorDriver<HoistExprsOutOfLoops> driverHoistExprsOutOfLoops;
  RuleOnceDriver<IndexJoin> driverIndexJoin;

  SingletonRuleMajorDriver<MarkFreeVars> driverMarkFreeVars;
  FoldRules driverFoldRules;

  // InlineFunctions

  if (Properties::instance()->inlineUdf())
  {
    SingletonRuleMajorDriver<InlineFunctions> driverInlineFunctions;
    if (driverInlineFunctions.rewrite(rCtx))
      modified = true;
  }

  // TypeRules
  if (driverTypeRules.rewrite(rCtx))
    modified = true;

  // PathSimplification
  if (driverPathSimplify.rewrite(rCtx))
    modified = true;

  // Mark non-discardable and unfoldable expr
  //bool mod;
  //mark_exprs(rCtx, rCtx.getRoot().getp(), mod);

  // FoldRules
  driverFoldRules.rewrite(rCtx);

  //
  driverExprSimplify.rewrite(rCtx);

  //
  driverMarkFreeVars.rewrite(rCtx);

  //
  driverEliminateVars.rewrite(rCtx);

  //
  driverMarkProducerNodeProps.rewrite(rCtx);
  driverEliminateNodeOps.rewrite(rCtx);

  //
  driverMarkConsumerNodeProps.rewrite(rCtx);
  driverEliminateNodeOps.rewrite(rCtx);

  //
  driverSpecializeOperations.rewrite(rCtx);

  // FoldRules
  driverFoldRules.rewrite(rCtx);

  // TypeRules
  driverTypeRules.rewrite(rCtx);

  if (Properties::instance()->loopHoisting())
    driverHoistExprsOutOfLoops.rewrite(rCtx);

  // For UDFs, which need this annotation in udf::requires_dyn_ctx()
  // TODO: only do this for UDFs
  //ADD_ONCE_DRIVER(MarkUnfoldableExprs);

  if (Properties::instance()->inferJoins())
    driverIndexJoin.rewrite(rCtx);

  return modified;
}


}
