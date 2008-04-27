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
#include <boost/shared_ptr.hpp>
#include "common/shared_types.h"
#include "compiler/rewriter/framework/rewriter.h"

namespace zorba {

class RewriterContext;
class RewriteRule;

class RuleMajorDriver : public Rewriter {
  public:
    RuleMajorDriver();;
    virtual ~RuleMajorDriver();

    void rewrite(RewriterContext& rCtx);

    typedef boost::shared_ptr<RewriteRule> rule_ptr_t;
    typedef std::vector<rule_ptr_t> rules_t;

  protected:
    rules_t m_rules;

    void rewriteRuleMajor(RewriterContext& rCtx);
    expr_t rewriteRec(RewriterContext& rCtx, RewriteRule *rule, expr *parent, bool& modified);
};

class SingletonRuleMajorDriverBase : public RuleMajorDriver {
public:
  SingletonRuleMajorDriverBase (rule_ptr_t rule) { m_rules.push_back(rule); }
};

template <class R>
class SingletonRuleMajorDriver : public SingletonRuleMajorDriverBase {
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
