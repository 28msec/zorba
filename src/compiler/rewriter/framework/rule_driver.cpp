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
#include "compiler/expression/expr_base.h"
#include "compiler/rewriter/framework/rule_driver.h"
#include "compiler/rewriter/framework/rewrite_rule.h"
#include "compiler/rewriter/framework/rewriter_context.h"

#include "util/properties.h"

namespace zorba {

RuleMajorDriver::RuleMajorDriver() 
{ 
}


RuleMajorDriver::~RuleMajorDriver() 
{
}


void RuleMajorDriver::rewrite(RewriterContext& rCtx)
{
  rewriteRuleMajor(rCtx);
}


void RuleMajorDriver::rewriteRuleMajor(RewriterContext& rCtx)
{
  bool modified = false;
  rules_t::const_iterator end = m_rules.end();
  do 
  {
    modified = false;

    for(rules_t::iterator i = m_rules.begin(); i != end; ++i) 
    {
      bool rule_modified = false;
      expr_t newRoot = rewriteRec(rCtx, &**i, &*rCtx.getRoot(), rule_modified);

      if (rule_modified)
        modified = true;

      if (newRoot != NULL) {
        rCtx.setRoot(newRoot);
      }

      if (rule_modified && Properties::instance()->printIntermediateOpt ()) 
      {
        std::cout << "After " << (*i)->getRuleName () << ":" << std::endl;
        rCtx.getRoot ()->put (std::cout) << std::endl;
      }
    }
  } while(modified);
}


expr_t RuleMajorDriver::rewriteRec(
    RewriterContext& rCtx,
    RewriteRule *rule,
    expr* curExpr,
    bool& modified)
{
  expr_t result = NULL;

  expr_t newExpr = rule->rewritePre(&*curExpr, rCtx);
  if (newExpr != NULL) 
  {
    curExpr = newExpr;
    result = newExpr;
    modified = true;
  }

  for(expr_iterator i = curExpr->expr_begin(); !i.done(); ++i) 
  {
    expr_t new_e = rewriteRec(rCtx, rule, &**i, modified);
    if (new_e != NULL) {
      *i = &*new_e;
    }
  }

  newExpr = rule->rewritePost(&*curExpr, rCtx);
  if (newExpr != NULL) 
  {
    result = newExpr;
    modified = true;
  }
  return result;
}

}
/* vim:set ts=2 sw=2: */
