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

#include "compiler/expression/expr_base.h"
#include "compiler/rewriter/framework/rule_driver.h"
#include "compiler/rewriter/rules/rule_base.h"
#include "compiler/rewriter/framework/rewriter_context.h"

#include "system/properties.h"


namespace zorba
{


/*******************************************************************************

********************************************************************************/
RuleMajorDriver::RuleMajorDriver()
{
}


/*******************************************************************************

********************************************************************************/
RuleMajorDriver::~RuleMajorDriver()
{
}


/*******************************************************************************

********************************************************************************/
bool RuleMajorDriver::rewrite(RewriterContext& rCtx)
{
  bool totalModified = false;
  bool modified = false;
  rules_t::const_iterator end = m_rules.end();
  do
  {
    modified = false;

    for (rules_t::iterator i = m_rules.begin(); i != end; ++i)
    {
      bool rule_modified = false;
      expr_t newRoot = (*i)->apply(rCtx, &*rCtx.getRoot(), rule_modified);

      if (newRoot != NULL)
      {
        rCtx.setRoot(newRoot);
      }

      if (rule_modified)
      {
        modified = true;
        totalModified = true;

        if (Properties::instance()->printIntermediateOpt())
        {
          std::cout << rCtx.theMessage << std::endl
                    << "After " << (*i)->getRuleName() << " :" << std::endl;
          rCtx.getRoot()->put(std::cout) << std::endl;
        }

        if ((*i)->getKind() != RewriteRule::MarkExprs)
          break;
      }
    }
  } while(modified);

  return totalModified;
}


/*******************************************************************************

********************************************************************************/
bool RuleOnceDriverBase::rewrite(RewriterContext& rCtx)
{
  bool modified = false;

  expr_t newRoot = theRule->apply(rCtx, &*rCtx.getRoot(), modified);

  if (newRoot != NULL)
  {
    rCtx.setRoot(newRoot);
  }

  if (modified && Properties::instance()->printIntermediateOpt())
  {
    std::cout << rCtx.theMessage << std::endl
              << "After " << theRule->getRuleName() << " :" << std::endl;
    rCtx.getRoot()->put(std::cout) << std::endl;
  }

  return modified;
}


}
/* vim:set et sw=2 ts=2: */
