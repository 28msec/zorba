#include <iostream>
#include "compiler/rewriter/rules/ruleset.h"

namespace xqp {

RULE_REWRITE_PRE(EchoNodeRule)
{
  std::cerr << "rewritePre: " << std::endl;
  node->put(std::cerr);
  return NULL;
}

RULE_REWRITE_POST(EchoNodeRule)
{
  std::cerr << "rewritePost: " << std::endl;
  node->put(std::cerr);
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
