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
#ifndef ZORBA_REWRITE_RULE_H
#define ZORBA_REWRITE_RULE_H

#include <string>
#include "common/shared_types.h"

namespace zorba {

class CompilerCB;
class RewriterContext;

class RewriteRule {
  public:
    virtual ~RewriteRule() { }

    virtual const std::string& getRuleName() const = 0;

    virtual expr_t rewritePre(expr *node, RewriterContext& rCtx) = 0;
    virtual expr_t rewritePost(expr *node, RewriterContext& rCtx) = 0;
};

}

#endif /* ZORBA_REWRITE_RULE_H */
/* vim:set ts=2 sw=2: */
