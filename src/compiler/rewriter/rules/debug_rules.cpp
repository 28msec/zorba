#include <iostream>
#include "compiler/rewriter/rules/ruleset.h"

namespace zorba {

RULE_REWRITE_PRE(EchoNodes)
{
  std::cerr << "rewritePre: " << std::endl;
  node->put(std::cerr);
  return NULL;
}

RULE_REWRITE_POST(EchoNodes)
{
  std::cerr << "rewritePost: " << std::endl;
  node->put(std::cerr);
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
