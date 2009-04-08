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
#ifndef ZORBA_RULE_DRIVER_H
#define ZORBA_RULE_DRIVER_H

#include <vector>
#include "common/shared_types.h"
#include "compiler/rewriter/framework/rewriter.h"

namespace zorba {

class RewriterContext;
class RewriteRule;

/***************************************************************************//**
  Represents a class of rules that are applied "together". This means that the
  rules that are registered with a RuleMajorDriver R are applied one after the
  other in the order that they were registerred; if any of these rules modifies
  the expression graph, the whole set of rules are applied again. This process
  (which is implemented by the rewrite() method) repeats until the first full
  appliaction of the rule set that produces no graph modifications. No rules
  other than those belonging to R are applied while R->rewrite() is running.
********************************************************************************/
class RuleMajorDriver : public Rewriter 
{
public:
  typedef rchandle<RewriteRule> rule_ptr_t;
  typedef std::vector<rule_ptr_t> rules_t;

protected:
  rules_t m_rules;

public:
  RuleMajorDriver();;

  virtual ~RuleMajorDriver();

  void rewrite(RewriterContext& rCtx);

protected:
  void rewriteRuleMajor(RewriterContext& rCtx);

  expr_t rewriteRec(RewriterContext& rCtx, RewriteRule *rule, expr *parent, bool& modified);
};


/***************************************************************************//**
  A RuleMajorDriver whose rule set contains a single rule.
********************************************************************************/
class SingletonRuleMajorDriverBase : public RuleMajorDriver 
{
public:
  SingletonRuleMajorDriverBase (rule_ptr_t rule) { m_rules.push_back(rule); }
};


template <class R>
class SingletonRuleMajorDriver : public SingletonRuleMajorDriverBase 
{
public:
  SingletonRuleMajorDriver() : SingletonRuleMajorDriverBase (rule_ptr_t (new R ())) {}
};

}

#endif /* ZORBA_RULE_DRIVER_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
