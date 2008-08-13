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
#include <iostream>
#include "compiler/rewriter/rules/ruleset.h"

namespace zorba {

RULE_REWRITE_PRE(EchoNodes)
{
  std::cout << "rewritePre: " << std::endl;
  node->put(std::cout);
  return NULL;
}

RULE_REWRITE_POST(EchoNodes)
{
  std::cout << "rewritePost: " << std::endl;
  node->put(std::cout);
  return NULL;
}

RULE_REWRITE_PRE(PlanPrinter)
{
  if (node == rCtx.getRoot()) {
    node->put(std::cout);
  }
  return NULL;
}

RULE_REWRITE_POST(PlanPrinter)
{
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
