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
#include "stdafx.h"

#include "compiler/rewriter/framework/rule_driver.h"
#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/rewriters/common_rewriter.h"
#include "compiler/rewriter/rewriters/default_optimizer.h"
#include "compiler/rewriter/tools/expr_tools.h"
//#include "compiler/rewriter/tools/udf_graph.h"
#include "compiler/api/compilercb.h"

#include "functions/udf.h"

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


DefaultOptimizer::~DefaultOptimizer()
{
}


bool DefaultOptimizer::rewrite(RewriterContext& rCtx)
{
  bool modified = false;

  SingletonRuleMajorDriver<EliminateTypeEnforcingOperations> driverTypeRules;
  SingletonRuleMajorDriver<EliminateExtraneousPathSteps> driverPathSimplify;
  //SingletonRuleMajorDriver<ReplaceExprWithConstantOneWhenPossible> driverExprSimplify;
  RuleOnceDriver<EliminateUnusedLetVars> driverEliminateVars;
  RuleOnceDriver<MarkProducerNodeProps> driverMarkProducerNodeProps;
  RuleOnceDriver<MarkConsumerNodeProps> driverMarkConsumerNodeProps;
  RuleOnceDriver<EliminateNodeOps> driverEliminateNodeOps;
  SingletonRuleMajorDriver<SpecializeOperations> driverSpecializeOperations;

  SingletonRuleMajorDriver<MarkFreeVars> driverMarkFreeVars;
  FoldRules driverFoldRules;

  // InlineFunctions

  if (Properties::instance()->inlineUdf())
  {
    SingletonRuleMajorDriver<InlineFunctions> driverInlineFunctions;
    if (driverInlineFunctions.rewrite(rCtx))
      modified = true;
  }

 repeat1:

  // TypeRules
  if (driverTypeRules.rewrite(rCtx))
    modified = true;

  // PathSimplification
  if (driverPathSimplify.rewrite(rCtx))
    modified = true;

  // FoldRules
  driverFoldRules.rewrite(rCtx);

  //
  bool local_modified = false;
  rCtx.theRoot->compute_return_type(true, &local_modified);
  if (local_modified)
  {
    //std::cout << "TYPES MODIFIED 1 !!!" << std::endl << std::endl;
    goto repeat1;
  }

 repeat2:

  // This rule has been merged into the PartialEval rule
  //driverExprSimplify.rewrite(rCtx);

  //
  driverMarkFreeVars.rewrite(rCtx);

  //
  driverEliminateVars.rewrite(rCtx);

  //  Recompute static types
  local_modified = false;
  rCtx.theRoot->compute_return_type(true, &local_modified);
  if (local_modified)
  {
    //std::cout << "TYPES MODIFIED 2 !!!" << std::endl << std::endl;
    goto repeat2;
  }

  //
  driverMarkProducerNodeProps.rewrite(rCtx);
  driverEliminateNodeOps.rewrite(rCtx);

  //
  driverMarkConsumerNodeProps.rewrite(rCtx);
  driverEliminateNodeOps.rewrite(rCtx);

 repeat4:

  // SpecializeOps
  driverSpecializeOperations.rewrite(rCtx);

  // FoldRules
  driverFoldRules.rewrite(rCtx);

  // TypeRules
  driverTypeRules.rewrite(rCtx);

  // Recompute static types
  local_modified = false;
  rCtx.theRoot->compute_return_type(true, &local_modified);
  if (local_modified)
  {
    //std::cout << "TYPES MODIFIED 4 !!!" << std::endl << std::endl;
    goto repeat4;
  }

  // Loop Hoisting
  if (Properties::instance()->loopHoisting())
  {
    HoistRule rule;
    bool local_modified = false;

    expr_t e = rule.apply(rCtx, rCtx.getRoot().getp(), local_modified);

    if (e != rCtx.getRoot())
      rCtx.setRoot(e);

    // Mark exprs again time because hoisting may have created new exprs.
    if (local_modified)
    {
      modified = true;

      if (Properties::instance()->printIntermediateOpt()) 
      {
        std::cout << "After hoisting : " << std::endl;
        rCtx.getRoot()->put(std::cout) << std::endl;
      }

      RuleOnceDriver<MarkExprs> driverMarkExpr;
      driverMarkExpr.rewrite(rCtx);
    }
  }

  // formatSparqlXml getSparqlResult optional matches

  // Index Joins
  if (Properties::instance()->inferJoins())
  {
    IndexJoinRule rule;
    bool local_modified = false;

    rCtx.theVarIdMap = new VarIdMap;
    rCtx.theIdVarMap = new IdVarMap;
    rCtx.theExprVarsMap = new ExprVarsMap;

    ulong numVars = 0;
    expr_tools::index_flwor_vars(rCtx.getRoot(),
                                 numVars,
                                 *rCtx.theVarIdMap,
                                 rCtx.theIdVarMap);

    do
    {
      assert(rCtx.theFlworStack.empty());

      rCtx.theExprVarsMap->clear();

      DynamicBitset freeset(numVars);
      expr_tools::build_expr_to_vars_map(rCtx.getRoot(),
                                         *rCtx.theVarIdMap,
                                         freeset,
                                         *rCtx.theExprVarsMap);

      local_modified = false; 

      expr_t e = rule.apply(rCtx, rCtx.getRoot().getp(), local_modified);

      if (e != rCtx.getRoot())
        rCtx.setRoot(e);

      if (local_modified)
      {
        modified = true;

        if (Properties::instance()->printIntermediateOpt()) 
        {
          std::cout << "After index join : " << std::endl;
          rCtx.getRoot()->put(std::cout) << std::endl;
        }

        // Mark exprs again because index joins may have created new exprs.
        RuleOnceDriver<MarkExprs> driverMarkExpr;
        driverMarkExpr.rewrite(rCtx);
      }
    }
    while (local_modified);
  }

  // Mark node copy property
  if (Properties::instance()->noCopyOptim())
  {
    if (rCtx.theUDF == NULL)
    {
      RuleOnceDriver<MarkNodeCopyProps> driverMarkNodeCopyProps;
      driverMarkNodeCopyProps.rewrite(rCtx);
    }
  }

  return modified;
}


}
/* vim:set et sw=2 ts=2: */
