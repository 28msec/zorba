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
#ifndef ZORBA_COMPILER_REWRITER_RULE_H
#define ZORBA_COMPILER_REWRITER_RULE_H

#include "common/shared_types.h"


namespace zorba {

class CompilerCB;
class RewriterContext;


/*******************************************************************************

********************************************************************************/
class RewriteRule : public SimpleRCObject 
{
private:
  std::string theRuleName;     

public:
  RewriteRule(const std::string& name) : theRuleName(name) {}

  virtual ~RewriteRule() { }

  const std::string& getRuleName() const { return theRuleName; }

  virtual expr_t apply(RewriterContext& rCtx, expr* node, bool& modified) = 0;
};


/*******************************************************************************

********************************************************************************/
class PrePostRewriteRule : public RewriteRule
{
public:
  PrePostRewriteRule(const std::string& name) : RewriteRule(name) {}

  virtual ~PrePostRewriteRule() { }

  expr_t apply(RewriterContext& rCtx, expr* node, bool& modifed);

protected:
  virtual expr_t rewritePre(expr* node, RewriterContext& rCtx) = 0;

  virtual expr_t rewritePost(expr* node, RewriterContext& rCtx) = 0;
};


/*******************************************************************************

********************************************************************************/
#define RULE(name)                                                  \
class name : public PrePostRewriteRule                              \
{                                                                   \
 public:                                                            \
  name() : PrePostRewriteRule(#name) { }                            \
                                                                    \
  ~name() { }                                                       \
                                                                    \
 protected:                                                         \
  expr_t rewritePre(expr* node, RewriterContext& rCtx);             \
                                                                    \
  expr_t rewritePost(expr* node, RewriterContext& rCtx);            \
}


#define RULE_REWRITE_PRE(name) expr_t name::rewritePre(expr* node, RewriterContext& rCtx)

#define RULE_REWRITE_POST(name) expr_t name::rewritePost(expr* node, RewriterContext& rCtx)

}

#endif /* ZORBA_REWRITE_RULE_H */
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
