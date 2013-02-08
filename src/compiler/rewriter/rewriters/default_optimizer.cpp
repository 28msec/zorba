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
#include "compiler/rewriter/rules/fold_rules.h"
#include "compiler/rewriter/rules/index_matching_rule.h"
#include "compiler/rewriter/rules/index_join_rule.h"
#include "compiler/rewriter/rewriters/common_rewriter.h"
#include "compiler/rewriter/rewriters/default_optimizer.h"
#include "compiler/rewriter/tools/expr_tools.h"

#include "compiler/xqddf/value_index.h"

#include "compiler/api/compilercb.h"

#include "functions/udf.h"

#include "system/properties.h"

#include "context/static_context.h"



namespace zorba
{


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

  // PathSimplification
  if (driverPathSimplify.rewrite(rCtx))
    modified = true;

  if (rCtx.theUDF != NULL)
  {
    RuleOnceDriver<MarkExprs> driverMarkLocalExprs;
    driverMarkLocalExprs.getRule()->setLocal(true);
    driverMarkLocalExprs.rewrite(rCtx);
  }

 repeat1:

  // TypeRules
  if (driverTypeRules.rewrite(rCtx))
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

  /*
 repeat2:

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
  */

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

    expr* e = rule.apply(rCtx, rCtx.getRoot(), local_modified);

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

  // index matching
  if (Properties::instance()->useIndexes())
  {
    static_context* sctx = rCtx.theRoot->get_sctx();

    std::vector<IndexDecl*> indexDecls;
    sctx->get_index_decls(indexDecls);

    if (!indexDecls.empty())
    {
      MarkFreeVars freeVarsRule;
      bool modified;
      freeVarsRule.apply(rCtx, rCtx.theRoot, modified);
    }

    std::vector<IndexDecl*>::const_iterator ite = indexDecls.begin();
    std::vector<IndexDecl*>::const_iterator end = indexDecls.end();
    for (; ite != end; ++ite)
    {
      bool local_modified = false;

      //store::Index* idx = GENV_STORE.getIndex((*ite)->getName());

      //if (idx != NULL)
      if (!(*ite)->isTemp())
      {
        IndexMatchingRule rule(*ite);

        expr* e = rule.apply(rCtx, rCtx.getRoot(), local_modified);

        if (e != rCtx.getRoot())
          rCtx.setRoot(e);
      }

      if (local_modified)
      {
        if (Properties::instance()->printIntermediateOpt())
        {
          std::cout << "After index matching : " << std::endl;
          rCtx.getRoot()->put(std::cout) << std::endl;
        }

        modified = true;
      }
    }
  }

  // Index Joins
  if (Properties::instance()->inferJoins())
  {
    bool local_modified = false;

    IndexJoinRule rule(&rCtx);

    do
    {
     local_modified = false;

      rule.reset();

      expr* e = rule.apply(rCtx, rCtx.getRoot(), local_modified);

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
